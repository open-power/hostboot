/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#include "compiler.h"
#include "container-of.h"
#include "mctp-defines.h"
#include "socket.h"
#include "transport.h"

#include <libpldm/base.h>
#include <libpldm/pldm.h>
#include <libpldm/transport.h>
#include <libpldm/transport/mctp-demux.h>

#include <errno.h>
#include <limits.h>
#include <poll.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define MCTP_DEMUX_NAME "libmctp-demux-daemon"
const uint8_t mctp_msg_type = MCTP_MSG_TYPE_PLDM;

struct pldm_transport_mctp_demux {
	struct pldm_transport transport;
	int socket;
	/* In the future this probably needs to move to a tid-eid-uuid/network
	 * id mapping for multi mctp networks */
	pldm_tid_t tid_eid_map[MCTP_MAX_NUM_EID];
	struct pldm_socket_sndbuf socket_send_buf;
};

#define transport_to_demux(ptr)                                                \
	container_of(ptr, struct pldm_transport_mctp_demux, transport)

LIBPLDM_ABI_STABLE
struct pldm_transport *
pldm_transport_mctp_demux_core(struct pldm_transport_mctp_demux *ctx)
{
	return &ctx->transport;
}

static pldm_requester_rc_t pldm_transport_mctp_demux_open(void)
{
	int fd = -1;
	ssize_t rc = -1;

	fd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
	if (fd == -1) {
		return fd;
	}

	const char path[] = "\0mctp-mux";
	struct sockaddr_un addr;
	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path, path, sizeof(path) - 1);
	rc = connect(fd, (struct sockaddr *)&addr,
		     sizeof(path) + sizeof(addr.sun_family) - 1);
	if (rc == -1) {
		return PLDM_REQUESTER_OPEN_FAIL;
	}
	rc = write(fd, &mctp_msg_type, sizeof(mctp_msg_type));
	if (rc == -1) {
		return PLDM_REQUESTER_OPEN_FAIL;
	}

	return fd;
}

LIBPLDM_ABI_STABLE
int pldm_transport_mctp_demux_init_pollfd(struct pldm_transport *t,
					  struct pollfd *pollfd)
{
	struct pldm_transport_mctp_demux *ctx = transport_to_demux(t);
	pollfd->fd = ctx->socket;
	pollfd->events = POLLIN;
	return 0;
}

static int
pldm_transport_mctp_demux_get_eid(struct pldm_transport_mctp_demux *ctx,
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

static int
pldm_transport_mctp_demux_get_tid(struct pldm_transport_mctp_demux *ctx,
				  mctp_eid_t eid, pldm_tid_t *tid)
{
	/* mapping exists */
	if (ctx->tid_eid_map[eid] != 0) {
		*tid = ctx->tid_eid_map[eid];
		return 0;
	}
	return -1;
}

LIBPLDM_ABI_STABLE
int pldm_transport_mctp_demux_map_tid(struct pldm_transport_mctp_demux *ctx,
				      pldm_tid_t tid, mctp_eid_t eid)
{
	ctx->tid_eid_map[eid] = tid;

	return 0;
}

LIBPLDM_ABI_STABLE
int pldm_transport_mctp_demux_unmap_tid(struct pldm_transport_mctp_demux *ctx,
					LIBPLDM_CC_UNUSED pldm_tid_t tid,
					mctp_eid_t eid)
{
	ctx->tid_eid_map[eid] = 0;

	return 0;
}

static pldm_requester_rc_t
pldm_transport_mctp_demux_recv(struct pldm_transport *t, pldm_tid_t *tid,
			       void **pldm_msg, size_t *msg_len)
{
	struct pldm_transport_mctp_demux *demux = transport_to_demux(t);
	size_t mctp_prefix_len = 2;
	struct msghdr msg = { 0 };
	pldm_requester_rc_t res;
	uint8_t mctp_prefix[2];
	struct iovec iov[2];
	mctp_eid_t eid = 0;
	ssize_t min_len;
	size_t pldm_len;
	ssize_t length;
	ssize_t bytes;
	uint8_t *buf;
	int rc;

	min_len = sizeof(eid) + sizeof(mctp_msg_type) +
		  sizeof(struct pldm_msg_hdr);
	length = recv(demux->socket, NULL, 0, MSG_PEEK | MSG_TRUNC);
	if (length <= 0) {
		return PLDM_REQUESTER_RECV_FAIL;
	}

	buf = malloc(length);
	if (buf == NULL) {
		return PLDM_REQUESTER_RECV_FAIL;
	}

	if (length < min_len) {
		/* read and discard */
		recv(demux->socket, buf, length, 0);
		res = PLDM_REQUESTER_INVALID_RECV_LEN;
		goto cleanup_buf;
	}

	pldm_len = length - mctp_prefix_len;
	iov[0].iov_len = mctp_prefix_len;
	iov[0].iov_base = mctp_prefix;
	iov[1].iov_len = pldm_len;
	iov[1].iov_base = buf;

	msg.msg_iov = iov;
	msg.msg_iovlen = sizeof(iov) / sizeof(iov[0]);

	bytes = recvmsg(demux->socket, &msg, 0);
	if (length != bytes) {
		res = PLDM_REQUESTER_INVALID_RECV_LEN;
		goto cleanup_buf;
	}

	if (mctp_prefix[1] != mctp_msg_type) {
		res = PLDM_REQUESTER_NOT_PLDM_MSG;
		goto cleanup_buf;
	}

	eid = mctp_prefix[0];
	rc = pldm_transport_mctp_demux_get_tid(demux, eid, tid);
	if (rc) {
		res = PLDM_REQUESTER_RECV_FAIL;
		goto cleanup_buf;
	}

	*pldm_msg = buf;
	*msg_len = pldm_len;

	return PLDM_REQUESTER_SUCCESS;

cleanup_buf:
	free(buf);

	return res;
}

static pldm_requester_rc_t
pldm_transport_mctp_demux_send(struct pldm_transport *t, pldm_tid_t tid,
			       const void *pldm_msg, size_t msg_len)
{
	struct pldm_transport_mctp_demux *demux = transport_to_demux(t);
	mctp_eid_t eid = 0;
	if (pldm_transport_mctp_demux_get_eid(demux, tid, &eid)) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	uint8_t hdr[2] = { eid, mctp_msg_type };

	struct iovec iov[2];
	iov[0].iov_base = hdr;
	iov[0].iov_len = sizeof(hdr);
	iov[1].iov_base = (uint8_t *)pldm_msg;
	iov[1].iov_len = msg_len;

	struct msghdr msg = { 0 };
	msg.msg_iov = iov;
	msg.msg_iovlen = sizeof(iov) / sizeof(iov[0]);

	if (msg_len > INT_MAX ||
	    pldm_socket_sndbuf_accomodate(&(demux->socket_send_buf),
					  (int)msg_len)) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	ssize_t rc = sendmsg(demux->socket, &msg, 0);
	if (rc == -1) {
		return PLDM_REQUESTER_SEND_FAIL;
	}
	return PLDM_REQUESTER_SUCCESS;
}

LIBPLDM_ABI_STABLE
int pldm_transport_mctp_demux_init(struct pldm_transport_mctp_demux **ctx)
{
	if (!ctx || *ctx) {
		return -EINVAL;
	}

	struct pldm_transport_mctp_demux *demux =
		calloc(1, sizeof(struct pldm_transport_mctp_demux));
	if (!demux) {
		return -ENOMEM;
	}

	demux->transport.name = MCTP_DEMUX_NAME;
	demux->transport.version = 1;
	demux->transport.recv = pldm_transport_mctp_demux_recv;
	demux->transport.send = pldm_transport_mctp_demux_send;
	demux->transport.init_pollfd = pldm_transport_mctp_demux_init_pollfd;
	demux->socket = pldm_transport_mctp_demux_open();
	if (demux->socket == -1) {
		free(demux);
		return -1;
	}

	if (pldm_socket_sndbuf_init(&demux->socket_send_buf, demux->socket)) {
		close(demux->socket);
		free(demux);
		return -1;
	}

	*ctx = demux;
	return 0;
}

LIBPLDM_ABI_STABLE
void pldm_transport_mctp_demux_destroy(struct pldm_transport_mctp_demux *ctx)
{
	if (!ctx) {
		return;
	}
	close(ctx->socket);
	free(ctx);
}

/* Temporary for old API */
struct pldm_transport_mctp_demux *
pldm_transport_mctp_demux_init_with_fd(int mctp_fd)
{
	struct pldm_transport_mctp_demux *demux =
		calloc(1, sizeof(struct pldm_transport_mctp_demux));
	if (!demux) {
		return NULL;
	}

	demux->transport.name = MCTP_DEMUX_NAME;
	demux->transport.version = 1;
	demux->transport.recv = pldm_transport_mctp_demux_recv;
	demux->transport.send = pldm_transport_mctp_demux_send;
	demux->transport.init_pollfd = pldm_transport_mctp_demux_init_pollfd;
	/* dup is so we can call pldm_transport_mctp_demux_destroy which closes
	 * the socket, without closing the fd that is being used by the consumer
	 */
	demux->socket = dup(mctp_fd);
	if (demux->socket == -1) {
		free(demux);
		return NULL;
	}

	if (pldm_socket_sndbuf_init(&demux->socket_send_buf, demux->socket)) {
		close(demux->socket);
		free(demux);
		return NULL;
	}

	return demux;
}

int pldm_transport_mctp_demux_get_socket_fd(
	struct pldm_transport_mctp_demux *ctx)
{
	if (ctx) {
		return ctx->socket;
	}

	return -1;
}
