/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#include "compiler.h"
#include "container-of.h"
#include "mctp-defines.h"
#include "responder.h"
#include "socket.h"
#include "transport.h"

#include <libpldm/base.h>
#include <libpldm/pldm.h>
#include <libpldm/transport.h>
#include <libpldm/transport/af-mctp.h>

#include <errno.h>
#include <limits.h>
#include <linux/mctp.h>
#include <poll.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

struct pldm_responder_cookie_af_mctp {
	struct pldm_responder_cookie req;
	struct sockaddr_mctp smctp;
};

#define cookie_to_af_mctp(c)                                                   \
	container_of((c), struct pldm_responder_cookie_af_mctp, req)

#define AF_MCTP_NAME "AF_MCTP"
struct pldm_transport_af_mctp {
	struct pldm_transport transport;
	int socket;
	pldm_tid_t tid_eid_map[MCTP_MAX_NUM_EID];
	struct pldm_socket_sndbuf socket_send_buf;
	bool bound;
	struct pldm_responder_cookie cookie_jar;
};

#define transport_to_af_mctp(ptr)                                              \
	container_of(ptr, struct pldm_transport_af_mctp, transport)

LIBPLDM_ABI_STABLE
struct pldm_transport *
pldm_transport_af_mctp_core(struct pldm_transport_af_mctp *ctx)
{
	return &ctx->transport;
}

LIBPLDM_ABI_STABLE
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

static int pldm_transport_af_mctp_get_tid(struct pldm_transport_af_mctp *ctx,
					  mctp_eid_t eid, pldm_tid_t *tid)
{
	if (ctx->tid_eid_map[eid] != 0) {
		*tid = ctx->tid_eid_map[eid];
		return 0;
	}
	return -1;
}

LIBPLDM_ABI_STABLE
int pldm_transport_af_mctp_map_tid(struct pldm_transport_af_mctp *ctx,
				   pldm_tid_t tid, mctp_eid_t eid)
{
	ctx->tid_eid_map[eid] = tid;

	return 0;
}

LIBPLDM_ABI_STABLE
int pldm_transport_af_mctp_unmap_tid(struct pldm_transport_af_mctp *ctx,
				     LIBPLDM_CC_UNUSED pldm_tid_t tid,
				     mctp_eid_t eid)
{
	ctx->tid_eid_map[eid] = 0;

	return 0;
}

static pldm_requester_rc_t pldm_transport_af_mctp_recv(struct pldm_transport *t,
						       pldm_tid_t *tid,
						       void **pldm_msg,
						       size_t *msg_len)
{
	struct pldm_transport_af_mctp *af_mctp = transport_to_af_mctp(t);
	struct sockaddr_mctp addr = { 0 };
	socklen_t addrlen = sizeof(addr);
	struct pldm_msg_hdr *hdr;
	pldm_requester_rc_t res;
	mctp_eid_t eid = 0;
	ssize_t length;
	void *msg;
	int rc;

	length = recv(af_mctp->socket, NULL, 0, MSG_PEEK | MSG_TRUNC);
	if (length <= 0) {
		return PLDM_REQUESTER_RECV_FAIL;
	}

	msg = malloc(length);
	if (!msg) {
		return PLDM_REQUESTER_RECV_FAIL;
	}

	length = recvfrom(af_mctp->socket, msg, length, MSG_TRUNC,
			  (struct sockaddr *)&addr, &addrlen);
	if (length < (ssize_t)sizeof(struct pldm_msg_hdr)) {
		res = PLDM_REQUESTER_INVALID_RECV_LEN;
		goto cleanup_msg;
	}

	eid = addr.smctp_addr.s_addr;
	rc = pldm_transport_af_mctp_get_tid(af_mctp, eid, tid);
	if (rc) {
		res = PLDM_REQUESTER_RECV_FAIL;
		goto cleanup_msg;
	}

	hdr = msg;

	if (af_mctp->bound && hdr->request) {
		struct pldm_responder_cookie_af_mctp *cookie;

		cookie = malloc(sizeof(*cookie));
		if (!cookie) {
			res = PLDM_REQUESTER_RECV_FAIL;
			goto cleanup_msg;
		}

		cookie->req.tid = *tid,
		cookie->req.instance_id = hdr->instance_id,
		cookie->req.type = hdr->type,
		cookie->req.command = hdr->command;
		cookie->smctp = addr;

		rc = pldm_responder_cookie_track(&af_mctp->cookie_jar,
						 &cookie->req);
		if (rc) {
			res = PLDM_REQUESTER_RECV_FAIL;
			goto cleanup_msg;
		}
	}

	*pldm_msg = msg;
	*msg_len = length;

	return PLDM_REQUESTER_SUCCESS;

cleanup_msg:
	free(msg);

	return res;
}

static pldm_requester_rc_t pldm_transport_af_mctp_send(struct pldm_transport *t,
						       pldm_tid_t tid,
						       const void *pldm_msg,
						       size_t msg_len)
{
	struct pldm_transport_af_mctp *af_mctp = transport_to_af_mctp(t);
	const struct pldm_msg_hdr *hdr;
	struct sockaddr_mctp addr = { 0 };

	if (msg_len < (ssize_t)sizeof(struct pldm_msg_hdr)) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	hdr = pldm_msg;
	if (af_mctp->bound && !hdr->request) {
		struct pldm_responder_cookie_af_mctp *cookie;
		struct pldm_responder_cookie *req;

		req = pldm_responder_cookie_untrack(&af_mctp->cookie_jar, tid,
						    hdr->instance_id, hdr->type,
						    hdr->command);
		if (!req) {
			return PLDM_REQUESTER_SEND_FAIL;
		}

		cookie = cookie_to_af_mctp(req);
		addr = cookie->smctp;
		/* Clear the TO to indicate a response */
		addr.smctp_tag &= ~MCTP_TAG_OWNER;
		free(cookie);
	} else {
		mctp_eid_t eid = 0;
		if (pldm_transport_af_mctp_get_eid(af_mctp, tid, &eid)) {
			return PLDM_REQUESTER_SEND_FAIL;
		}

		addr.smctp_family = AF_MCTP;
		addr.smctp_addr.s_addr = eid;
		addr.smctp_type = MCTP_MSG_TYPE_PLDM;
		addr.smctp_tag = MCTP_TAG_OWNER;
	}

	if (msg_len > INT_MAX ||
	    pldm_socket_sndbuf_accomodate(&(af_mctp->socket_send_buf),
					  (int)msg_len)) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	ssize_t rc = sendto(af_mctp->socket, pldm_msg, msg_len, 0,
			    (struct sockaddr *)&addr, sizeof(addr));
	if (rc == -1) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	return PLDM_REQUESTER_SUCCESS;
}

LIBPLDM_ABI_STABLE
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
	af_mctp->transport.init_pollfd = pldm_transport_af_mctp_init_pollfd;
	af_mctp->bound = false;
	af_mctp->cookie_jar.next = NULL;
	af_mctp->socket = socket(AF_MCTP, SOCK_DGRAM, 0);
	if (af_mctp->socket == -1) {
		free(af_mctp);
		return -1;
	}

	if (pldm_socket_sndbuf_init(&af_mctp->socket_send_buf,
				    af_mctp->socket)) {
		close(af_mctp->socket);
		free(af_mctp);
		return -1;
	}

	*ctx = af_mctp;
	return 0;
}

LIBPLDM_ABI_STABLE
void pldm_transport_af_mctp_destroy(struct pldm_transport_af_mctp *ctx)
{
	if (!ctx) {
		return;
	}
	close(ctx->socket);
	free(ctx);
}

LIBPLDM_ABI_STABLE
int pldm_transport_af_mctp_bind(struct pldm_transport_af_mctp *transport,
				const struct sockaddr_mctp *smctp, size_t len)
{
	struct sockaddr_mctp lsmctp = { 0 };
	int rc;

	if (!transport) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	if (!smctp && len) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	if (!smctp) {
		lsmctp.smctp_family = AF_MCTP;
		lsmctp.smctp_network = MCTP_NET_ANY;
		lsmctp.smctp_addr.s_addr = MCTP_ADDR_ANY;
		lsmctp.smctp_type = MCTP_MSG_TYPE_PLDM;
		lsmctp.smctp_tag = MCTP_TAG_OWNER;
		smctp = &lsmctp;
		len = sizeof(lsmctp);
	}

	if (smctp->smctp_family != AF_MCTP ||
	    smctp->smctp_type != MCTP_MSG_TYPE_PLDM ||
	    smctp->smctp_tag != MCTP_TAG_OWNER) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	if (len != sizeof(*smctp)) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	rc = bind(transport->socket, (const struct sockaddr *)smctp,
		  sizeof(*smctp));
	if (rc) {
		return PLDM_REQUESTER_SETUP_FAIL;
	}

	transport->bound = true;

	return PLDM_REQUESTER_SUCCESS;
}
