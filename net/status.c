/*
 * Lukasz Stolcman <lukasz.stolcman@tieto.com> 2015
 *
 */

#include <common.h>
#include <command.h>
#include <net.h>

#include "status.h"


static int status_our_port;

bool send_packets = true;
bool master_alive = false;
uint8_t packet_id = 0;
uint8_t retry_count = TOUT_RETRY;
uint8_t packet_id = 0;


static void status_send(void)
{
	while (true)
	{
		if (send_packets && !master_alive && get_timer(t) > TOUT_RESPONSE)
		{
			struct status_pkt_t pkt;
			int pktlen = sizeof(struct status_pkt_t);

			memset(&pkt, 0, sizeof(pkt));

			pkt.header = STATUS_HEADER_STATUS;
			pkt.id = packet_id++;
			pkt.status = STATUS_STATUS_U_BOOT;

			memcpy((char *)net_tx_packet + net_eth_hdr_size() + IP_UDP_HDR_SIZE,
					(char *)&pkt, pktlen);

			status_our_port = random_port();

			net_send_udp_packet(net_server_ethaddr, net_status_master_board_ip, STATUS_SERVICE_PORT,
					status_our_port, pktlen);

			send_packets = false;

			//status_send(); // or while (true) instead
		}
	}
}

static void status_timeout_handler(void)
{
	if (retry_count > TOUT_RETRY)
	{
		retry_count = 0;
		master_alive = false;
	}
	else
	{
		++retry_count;
	}

	send_packets = true;

	//net_set_state(NETLOOP_FAIL);
}

static void status_handler(uchar *pkt, unsigned dest, struct in_addr sip,
		unsigned src, unsigned len)
{
	struct status_response_t *rpkt;
	if (dest != status_our_port)
		return;

	rpkt = (struct status_response_t *)pkt;

	printf("dest=%i\nin_addr=%d\nsrc=%d\nlen=%d\n", dest, sip, src, len);

	printf("pkt.header=%i\npkt.id=%i\n", rpkt->header, rpkt->id);


	if (rpkt->header == STATUS_HEADER_RESPONSE)
	{
		if (rpkt->id == packet_id)
		{
			master_alive = true;
		}
	}

	if (rpkt->header == STATUS_HEADER_CHGSTATE)
	{
		net_set_udp_handler(NULL);

		//send response
		struct status_response_t pkt;
		int pktlen = sizeof(struct status_response_t);

		memset(&pkt, 0, sizeof(pkt));

		pkt.header = STATUS_HEADER_STATUS;
		pkt.id = packet_id++;
		pkt.status = STATUS_STATUS_U_BOOT;

		memcpy((char *)net_tx_packet + net_eth_hdr_size() + IP_UDP_HDR_SIZE,
				(char *)&pkt, pktlen);

		status_our_port = random_port();

		net_send_udp_packet(net_server_ethaddr, net_status_master_board_ip, STATUS_SERVICE_PORT,
				status_our_port, pktlen);


		net_set_state(NETLOOP_SUCCESS);
	}
}

void status_start(void)
{
	debug("%s\n", __func__);

	net_set_timeout_handler(TOUT_RESPONSE, status_timeout_handler);
	net_set_udp_handler(status_handler);
	memset(net_server_ethaddr, 0, sizeof(net_server_ethaddr));

	status_send();
}
