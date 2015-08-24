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
#define STATUS_HEADER_CHGSTATE	0x03
#define STATUS_HEADER_GETSTATUS	0x04

/* System status indicator */
#define STATUS_STATUS_U_BOOT	0x01
#define STATUS_STATUS_LINUX		0x02

/* Timeouts */
#define TOUT_RETRY 3
#define TOUT_RESPONSE (CONFIG_SYS_HZ * 0.5) /* 500ms = 0,5s */

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
