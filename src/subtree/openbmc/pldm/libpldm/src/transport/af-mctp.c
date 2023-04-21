#include "../mctp-defines.h"
#include "base.h"
#include "container-of.h"
#include "libpldm/pldm.h"
#include "libpldm/transport.h"
#include "transport.h"

#include <errno.h>
#include <linux/mctp.h>
#include <poll.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define AF_MCTP_NAME "AF_MCTP"
struct pldm_transport_af_mctp {
	struct pldm_transport transport;
	int socket;
	pldm_tid_t tid_eid_map[MCTP_MAX_NUM_EID];
};

#define transport_to_af_mctp(ptr)                                              \
	container_of(ptr, struct pldm_transport_af_mctp, transport)

struct pldm_transport *
pldm_transport_af_mctp_core(struct pldm_transport_af_mctp *ctx)
{
	return &ctx->transport;
}

int pldm_transport_af_mctp_init_pollfd(struct pldm_transport *t,
				       struct pollfd *pollfd)
{
	struct pldm_transport_af_mctp *ctx = transport_to_af_mctp(t);
	pollfd->fd = ctx->socket;
	pollfd->events = POLLIN;
	return 0;
}

static int pldm_transport_af_mctp_get_eid(struct pldm_transport_af_mctp *ctx,
					  pldm_tid_t tid, mctp_eid_t *eid)
{
	int i;
	for (i = 0; i < MCTP_MAX_NUM_EID; i++) {
		if (ctx->tid_eid_map[i] == tid) {
			*eid = i;
			return 0;
		}
	}
	*eid = -1;
	return -1;
}

int pldm_transport_af_mctp_map_tid(struct pldm_transport_af_mctp *ctx,
				   pldm_tid_t tid, mctp_eid_t eid)
{
	ctx->tid_eid_map[eid] = tid;

	return 0;
}

int pldm_transport_af_mctp_unmap_tid(struct pldm_transport_af_mctp *ctx,
				     __attribute__((unused)) pldm_tid_t tid,
				     mctp_eid_t eid)
{
	ctx->tid_eid_map[eid] = 0;

	return 0;
}

static pldm_requester_rc_t pldm_transport_af_mctp_recv(struct pldm_transport *t,
						       pldm_tid_t tid,
						       void **pldm_resp_msg,
						       size_t *resp_msg_len)
{
	struct pldm_transport_af_mctp *af_mctp = transport_to_af_mctp(t);
	mctp_eid_t eid = 0;
	int rc = pldm_transport_af_mctp_get_eid(af_mctp, tid, &eid);
	if (rc) {
		return PLDM_REQUESTER_RECV_FAIL;
	}

	ssize_t length = recv(af_mctp->socket, NULL, 0, MSG_PEEK | MSG_TRUNC);
	if (length <= 0) {
		return PLDM_REQUESTER_RECV_FAIL;
	}
	*pldm_resp_msg = malloc(length);
	length = recv(af_mctp->socket, *pldm_resp_msg, length, MSG_TRUNC);
	if (length < (ssize_t)sizeof(struct pldm_msg_hdr)) {
		free(*pldm_resp_msg);
		return PLDM_REQUESTER_INVALID_RECV_LEN;
	}
	*resp_msg_len = length;
	return PLDM_REQUESTER_SUCCESS;
}

static pldm_requester_rc_t pldm_transport_af_mctp_send(struct pldm_transport *t,
						       pldm_tid_t tid,
						       const void *pldm_req_msg,
						       size_t req_msg_len)
{
	struct pldm_transport_af_mctp *af_mctp = transport_to_af_mctp(t);
	mctp_eid_t eid = 0;
	if (pldm_transport_af_mctp_get_eid(af_mctp, tid, &eid)) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	struct sockaddr_mctp addr = {0};
	addr.smctp_family = AF_MCTP;
	addr.smctp_addr.s_addr = eid;
	addr.smctp_type = MCTP_MSG_TYPE_PLDM;
	addr.smctp_tag = MCTP_TAG_OWNER;

	ssize_t rc = sendto(af_mctp->socket, pldm_req_msg, req_msg_len, 0,
			    (struct sockaddr *)&addr, sizeof(addr));
	if (rc == -1) {
		return PLDM_REQUESTER_SEND_FAIL;
	}
	return PLDM_REQUESTER_SUCCESS;
}

int pldm_transport_af_mctp_init(struct pldm_transport_af_mctp **ctx)
{
	if (!ctx || *ctx) {
		return -EINVAL;
	}

	struct pldm_transport_af_mctp *af_mctp =
	    calloc(1, sizeof(struct pldm_transport_af_mctp));
	if (!af_mctp) {
		return -ENOMEM;
	}

	af_mctp->transport.name = AF_MCTP_NAME;
	af_mctp->transport.version = 1;
	af_mctp->transport.recv = pldm_transport_af_mctp_recv;
	af_mctp->transport.send = pldm_transport_af_mctp_send;
	af_mctp->socket = socket(AF_MCTP, SOCK_DGRAM, 0);
	if (af_mctp->socket == -1) {
		free(af_mctp);
		return -1;
	}
	*ctx = af_mctp;
	return 0;
}

void pldm_transport_af_mctp_destroy(struct pldm_transport_af_mctp *ctx)
{
	if (!ctx) {
		return;
	}
	close(ctx->socket);
	free(ctx);
}
