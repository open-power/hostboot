/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#include "compiler.h"
#include "transport.h"

#include <libpldm/transport.h>
#include <libpldm/base.h>
#include <libpldm/pldm.h>

#include <errno.h>
#include <limits.h>
#ifdef PLDM_HAS_POLL
#include <poll.h>
#endif
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#ifndef PLDM_HAS_POLL
struct pollfd {
	int fd;	       /* file descriptor */
	short events;  /* requested events */
	short revents; /* returned events */
};

static inline int poll(struct pollfd *fds LIBPLDM_CC_UNUSED,
		       int nfds LIBPLDM_CC_UNUSED,
		       int timeout LIBPLDM_CC_UNUSED)
{
	return 0;
}
#endif

LIBPLDM_ABI_STABLE
int pldm_transport_poll(struct pldm_transport *transport, int timeout)
{
	struct pollfd pollfd;
	int rc = 0;
	if (!transport) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	/* If polling isn't supported then always indicate the transport is ready */
	if (!transport->init_pollfd) {
		return 1;
	}

	rc = transport->init_pollfd(transport, &pollfd);
	if (rc < 0) {
		return PLDM_REQUESTER_POLL_FAIL;
	}

	rc = poll(&pollfd, 1, timeout);
	if (rc < 0) {
		return PLDM_REQUESTER_POLL_FAIL;
	}

	/* rc is 0 if poll(2) times out, or 1 if pollfd becomes active. */
	return rc;
}

LIBPLDM_ABI_STABLE
pldm_requester_rc_t pldm_transport_send_msg(struct pldm_transport *transport,
					    pldm_tid_t tid,
					    const void *pldm_msg,
					    size_t msg_len)
{
	if (!transport || !pldm_msg) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	if (msg_len < sizeof(struct pldm_msg_hdr)) {
		return PLDM_REQUESTER_NOT_REQ_MSG;
	}

	return transport->send(transport, tid, pldm_msg, msg_len);
}

LIBPLDM_ABI_STABLE
pldm_requester_rc_t pldm_transport_recv_msg(struct pldm_transport *transport,
					    pldm_tid_t *tid, void **pldm_msg,
					    size_t *msg_len)
{
	if (!transport || !msg_len) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	pldm_requester_rc_t rc =
		transport->recv(transport, tid, pldm_msg, msg_len);
	if (rc != PLDM_REQUESTER_SUCCESS) {
		return rc;
	}

	if (*msg_len < sizeof(struct pldm_msg_hdr)) {
		free(*pldm_msg);
		*pldm_msg = NULL;
		return PLDM_REQUESTER_INVALID_RECV_LEN;
	}
	return PLDM_REQUESTER_SUCCESS;
}

static void timespec_to_timeval(const struct timespec *ts, struct timeval *tv)
{
	tv->tv_sec = ts->tv_sec;
	tv->tv_usec = ts->tv_nsec / 1000;
}

/* Overflow safety must be upheld before call */
static long timeval_to_msec(const struct timeval *tv)
{
	return tv->tv_sec * 1000 + tv->tv_usec / 1000;
}

/* If calculations on `tv` don't overflow then operations on derived
 * intervals can't either.
 */
static bool timeval_is_valid(const struct timeval *tv)
{
	if (tv->tv_sec < 0 || tv->tv_usec < 0 || tv->tv_usec >= 1000000) {
		return false;
	}

	if (tv->tv_sec > (LONG_MAX - tv->tv_usec / 1000) / 1000) {
		return false;
	}

	return true;
}

static int clock_gettimeval(clockid_t clockid, struct timeval *tv)
{
	struct timespec now;
	int rc;

	rc = clock_gettime(clockid, &now);
	if (rc < 0) {
		return rc;
	}

	timespec_to_timeval(&now, tv);

	return 0;
}

LIBPLDM_ABI_STABLE
pldm_requester_rc_t
pldm_transport_send_recv_msg(struct pldm_transport *transport, pldm_tid_t tid,
			     const void *pldm_req_msg, size_t req_msg_len,
			     void **pldm_resp_msg, size_t *resp_msg_len)

{
	/**
	 * Section "Requirements for requesters" in DSP0240, define the Time-out
	 * waiting for a response of the requester.
	 * PT2max = PT3min - 2*PT4max = 4800ms
	 */
	static const struct timeval max_response_interval = {
		.tv_sec = 4, .tv_usec = 800000
	};
	const struct pldm_msg_hdr *req_hdr;
	struct timeval remaining;
	pldm_requester_rc_t rc;
	struct timeval now;
	struct timeval end;
	int ret;
	int cnt;

	if (req_msg_len < sizeof(*req_hdr) || !resp_msg_len) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	req_hdr = pldm_req_msg;

	if (!req_hdr->request) {
		return PLDM_REQUESTER_NOT_REQ_MSG;
	}

	for (cnt = 0; cnt <= (PLDM_INSTANCE_MAX + 1) * PLDM_MAX_TIDS &&
		      pldm_transport_poll(transport, 0) == 1;
	     cnt++) {
		pldm_tid_t l_tid;
		rc = pldm_transport_recv_msg(transport, &l_tid, pldm_resp_msg,
					     resp_msg_len);
		if (rc == PLDM_REQUESTER_SUCCESS) {
			/* This isn't the message we wanted */
			free(*pldm_resp_msg);
		}
	}
	if (cnt == (PLDM_INSTANCE_MAX + 1) * PLDM_MAX_TIDS) {
		return PLDM_REQUESTER_TRANSPORT_BUSY;
	}

	rc = pldm_transport_send_msg(transport, tid, pldm_req_msg, req_msg_len);
	if (rc != PLDM_REQUESTER_SUCCESS) {
		return rc;
	}

	ret = clock_gettimeval(CLOCK_MONOTONIC, &now);
	if (ret < 0) {
		return PLDM_REQUESTER_POLL_FAIL;
	}

	timeradd(&now, &max_response_interval, &end);
	if (!timeval_is_valid(&end)) {
		return PLDM_REQUESTER_POLL_FAIL;
	}

	while (timercmp(&now, &end, <)) {
		pldm_tid_t src_tid;

		timersub(&end, &now, &remaining);

		/* 0 <= `timeval_to_msec()` <= 4800, and 4800 < INT_MAX */
		ret = pldm_transport_poll(transport,
					  (int)(timeval_to_msec(&remaining)));
		if (ret <= 0) {
			return PLDM_REQUESTER_RECV_FAIL;
		}

		ret = clock_gettimeval(CLOCK_MONOTONIC, &now);
		if (ret < 0) {
			return PLDM_REQUESTER_POLL_FAIL;
		}

		rc = pldm_transport_recv_msg(transport, &src_tid, pldm_resp_msg,
					     resp_msg_len);
		if (rc != PLDM_REQUESTER_SUCCESS) {
			continue;
		}

		if (src_tid != tid || !pldm_msg_hdr_correlate_response(
					      pldm_req_msg, *pldm_resp_msg)) {
			free(*pldm_resp_msg);
			continue;
		}

		return PLDM_REQUESTER_SUCCESS;
	}

	return PLDM_REQUESTER_RECV_FAIL;
}
