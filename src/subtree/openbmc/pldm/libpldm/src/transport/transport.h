#ifndef LIBPLDM_SRC_TRANSPORT_TRANSPORT_H
#define LIBPLDM_SRC_TRANSPORT_TRANSPORT_H

#include "libpldm/base.h"
#include "libpldm/requester/pldm.h"
struct pollfd;

/**
 * @brief Generic PLDM transport struct
 *
 * @var name - name of the transport
 * @var version - version of transport to use
 * @var recv - pointer to the transport specific function to receive a message
 * @var send - pointer to the transport specific function to send a message
 * @var init_pollfd - pointer to the transport specific init_pollfd function
 */
struct pldm_transport {
	const char *name;
	uint8_t version;
	pldm_requester_rc_t (*recv)(struct pldm_transport *transport,
				    pldm_tid_t tid, void **pldm_resp_msg,
				    size_t *resp_msg_len);
	pldm_requester_rc_t (*send)(struct pldm_transport *transport,
				    pldm_tid_t tid, const void *pldm_req_msg,
				    size_t req_msg_len);
	int (*init_pollfd)(struct pldm_transport *transport,
			   struct pollfd *pollfd);
};

#endif // LIBPLDM_SRC_TRANSPORT_TRANSPORT_H
