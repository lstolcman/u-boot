/*
 * Lukasz Stolcman <lukasz.stolcman@tieto.com> 2015
 *
 */

#ifndef __STATUS_H__
#define __STATUS_H__

#define STATUS_SERVICE_PORT		9001

/* Status packet header */
#define STATUS_HEADER_STATUS	0x01
#define STATUS_HEADER_RESPONSE	0x02

/* System status indicator */
#define STATUS_STATUS_U_BOOT	0x01
#define STATUS_STATUS_LINUX		0x02

struct status_pkt_t {
	uint8_t header;
	uint8_t id;
	uint8_t status;
};

struct status_response_t {
	uint8_t header;
	uint8_t id;
};

void status_start(void);	/* Begin STATUS */

#endif /* __STATUS_H__ */
