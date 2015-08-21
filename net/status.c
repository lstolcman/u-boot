/*
 * Lukasz Stolcman <lukasz.stolcman@tieto.com> 2015
 *
 */

#include <common.h>
#include <command.h>
#include <net.h>

#include "status.h"

#define STATUS_TIMEOUT 10000UL

static int status_our_port;

static void status_send(void)
{
	struct status_pkt_t pkt;
	int pktlen = sizeof(struct status_pkt_t);

	memset(&pkt, 0, sizeof(pkt));

	pkt.header = STATUS_HEADER_STATUS;
	pkt.id = 0xaf;
	pkt.status = STATUS_STATUS_U_BOOT;

	memcpy((char *)net_tx_packet + net_eth_hdr_size() + IP_UDP_HDR_SIZE,
			(char *)&pkt, pktlen);

	status_our_port = random_port();

	net_send_udp_packet(net_server_ethaddr, net_status_master_board_ip, STATUS_SERVICE_PORT,
			status_our_port, pktlen);
}

static void status_timeout_handler(void)
{
	net_set_state(NETLOOP_FAIL);
	return;
}

static void status_handler(uchar *pkt, unsigned dest, struct in_addr sip,
		unsigned src, unsigned len)
{
	struct status_response_t *rpkt = (struct status_response_t *)pkt;

	printf("dest=%i\nin_addr=%d\nsrc=%d\nlen=%d\n", dest, sip, src, len);
	if (dest != status_our_port)
		return;

	printf("pkt.header=%i\npkt.id=%i\n", rpkt->header, rpkt->id);

	net_set_state(NETLOOP_SUCCESS);
}

void status_start(void)
{
	debug("%s\n", __func__);

	net_set_timeout_handler(STATUS_TIMEOUT, status_timeout_handler);
	net_set_udp_handler(status_handler);
	memset(net_server_ethaddr, 0, sizeof(net_server_ethaddr));

	status_send();
}
