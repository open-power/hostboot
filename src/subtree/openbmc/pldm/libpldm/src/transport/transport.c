#include "libpldm/transport.h"
#include "base.h"
#include "libpldm/requester/pldm.h"
#include "transport.h"

#ifdef PLDM_HAS_POLL
#include <poll.h>
#endif
#include <stdlib.h>
#include <unistd.h>

#ifndef PLDM_HAS_POLL
struct pollfd {
	int fd;	       /* file descriptor */
	short events;  /* requested events */
	short revents; /* returned events */
};

static inline int poll(struct pollfd *fds __attribute__((unused)),
		       int nfds __attribute__((unused)),
		       int timeout __attribute__((unused)))
{
	return 0;
}
#endif

pldm_requester_rc_t pldm_transport_poll(struct pldm_transport *transport,
					int timeout)
{
	struct pollfd pollfd;
	int rc = 0;
	if (!transport) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}
	if (!transport->init_pollfd) {
		return PLDM_REQUESTER_SUCCESS;
	}

	transport->init_pollfd(transport, &pollfd);
	rc = poll(&pollfd, 1, timeout);
	if (rc < 0) {
		return PLDM_REQUESTER_POLL_FAIL;
	}

	return PLDM_REQUESTER_SUCCESS;
}

pldm_requester_rc_t pldm_transport_send_msg(struct pldm_transport *transport,
					    pldm_tid_t tid,
					    const void *pldm_req_msg,
					    size_t req_msg_len)
{
	if (!transport || !pldm_req_msg) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	if (req_msg_len < sizeof(struct pldm_msg_hdr)) {
		return PLDM_REQUESTER_NOT_REQ_MSG;
	}

	const struct pldm_msg_hdr *hdr = pldm_req_msg;
	if (!hdr->request) {
		return PLDM_REQUESTER_NOT_REQ_MSG;
	}

	return transport->send(transport, tid, pldm_req_msg, req_msg_len);
}

pldm_requester_rc_t pldm_transport_recv_msg(struct pldm_transport *transport,
					    pldm_tid_t tid,
					    void **pldm_resp_msg,
					    size_t *resp_msg_len)
{
	if (!transport || !resp_msg_len) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	pldm_requester_rc_t rc =
	    transport->recv(transport, tid, pldm_resp_msg, resp_msg_len);
	if (rc != PLDM_REQUESTER_SUCCESS) {
		return rc;
	}

	struct pldm_msg_hdr *hdr = *pldm_resp_msg;
	if (hdr->request || hdr->datagram) {
		free(*pldm_resp_msg);
		*pldm_resp_msg = NULL;
		return PLDM_REQUESTER_NOT_RESP_MSG;
	}

	uint8_t pldm_rc = 0;
	if (*resp_msg_len < (sizeof(struct pldm_msg_hdr) + sizeof(pldm_rc))) {
		free(*pldm_resp_msg);
		*pldm_resp_msg = NULL;
		return PLDM_REQUESTER_RESP_MSG_TOO_SMALL;
	}

	return PLDM_REQUESTER_SUCCESS;
}

pldm_requester_rc_t
pldm_transport_send_recv_msg(struct pldm_transport *transport, pldm_tid_t tid,
			     const void *pldm_req_msg, size_t req_msg_len,
			     void **pldm_resp_msg, size_t *resp_msg_len)

{
	if (!resp_msg_len) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	pldm_requester_rc_t rc =
	    pldm_transport_send_msg(transport, tid, pldm_req_msg, req_msg_len);
	if (rc != PLDM_REQUESTER_SUCCESS) {
		return rc;
	}

	while (1) {
		rc = pldm_transport_poll(transport, -1);
		if (rc != PLDM_REQUESTER_SUCCESS) {
			break;
		}
		rc = pldm_transport_recv_msg(transport, tid, pldm_resp_msg,
					     resp_msg_len);
		if (rc == PLDM_REQUESTER_SUCCESS) {
			break;
		}
	}

	return rc;
}
