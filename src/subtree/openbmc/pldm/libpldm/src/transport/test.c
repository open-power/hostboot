/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
/* NOLINTNEXTLINE(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp) */
#include "array.h"
#include "container-of.h"
#include "transport.h"
#include "test.h"

#include <errno.h>
#include <poll.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct pldm_transport_test {
	struct pldm_transport transport;
	const struct pldm_transport_test_descriptor *seq;
	size_t count;
	size_t cursor;
	int timerfd;
};

#define transport_to_test(ptr)                                                 \
	container_of(ptr, struct pldm_transport_test, transport)

LIBPLDM_ABI_TESTING
struct pldm_transport *pldm_transport_test_core(struct pldm_transport_test *ctx)
{
	return &ctx->transport;
}

#ifdef PLDM_HAS_POLL
#include <poll.h>
LIBPLDM_ABI_TESTING
int pldm_transport_test_init_pollfd(struct pldm_transport *ctx,
				    struct pollfd *pollfd)
{
	static const struct itimerspec disable = {
		.it_value = { 0, 0 },
		.it_interval = { 0, 0 },
	};
	struct pldm_transport_test *test = transport_to_test(ctx);
	const struct pldm_transport_test_descriptor *desc;
	int rc;

	rc = timerfd_settime(test->timerfd, 0, &disable, NULL);
	if (rc < 0) {
		return PLDM_REQUESTER_POLL_FAIL;
	}

	if (test->cursor >= test->count) {
		return PLDM_REQUESTER_POLL_FAIL;
	}

	desc = &test->seq[test->cursor];

	if (desc->type == PLDM_TRANSPORT_TEST_ELEMENT_LATENCY) {
		rc = timerfd_settime(test->timerfd, 0, &desc->latency, NULL);
		if (rc < 0) {
			return PLDM_REQUESTER_POLL_FAIL;
		}

		/* This was an explicit latency element, so now move beyond it for recv */
		test->cursor++;
	} else if (desc->type == PLDM_TRANSPORT_TEST_ELEMENT_MSG_RECV) {
		/* Expire the timer immediately so it appears ready */
		static const struct timespec ensure_ready = {
			.tv_sec = 0,
			.tv_nsec = 2,
		};
		static const struct itimerspec ready = {
			.it_value = { 0, 1 },
			.it_interval = { 0, 0 },
		};
		struct pollfd pfds[] = {
			{ .fd = test->timerfd, .events = POLLIN },
		};

		rc = timerfd_settime(test->timerfd, 0, &ready, NULL);
		if (rc < 0) {
			return PLDM_REQUESTER_POLL_FAIL;
		}

		rc = ppoll(pfds, ARRAY_SIZE(pfds), &ensure_ready, NULL);
		if (rc < 1) {
			return PLDM_REQUESTER_POLL_FAIL;
		}

		/* Don't increment test->cursor as recv needs to consume the current test element */
	} else {
		return PLDM_REQUESTER_POLL_FAIL;
	}

	pollfd->fd = test->timerfd;
	pollfd->events = POLLIN;

	return 0;
}
#endif

static pldm_requester_rc_t pldm_transport_test_recv(struct pldm_transport *ctx,
						    pldm_tid_t *tid,
						    void **pldm_resp_msg,
						    size_t *resp_msg_len)
{
	struct pldm_transport_test *test = transport_to_test(ctx);
	const struct pldm_transport_test_descriptor *desc;
	void *msg;

	if (test->cursor >= test->count) {
		return PLDM_REQUESTER_RECV_FAIL;
	}

	desc = &test->seq[test->cursor];

	if (desc->type != PLDM_TRANSPORT_TEST_ELEMENT_MSG_RECV) {
		return PLDM_REQUESTER_RECV_FAIL;
	}

	msg = malloc(desc->recv_msg.len);
	if (!msg) {
		return PLDM_REQUESTER_RECV_FAIL;
	}

	memcpy(msg, desc->recv_msg.msg, desc->recv_msg.len);
	*pldm_resp_msg = msg;
	*resp_msg_len = desc->recv_msg.len;
	*tid = desc->recv_msg.src;

	test->cursor++;

	return PLDM_REQUESTER_SUCCESS;
}

static pldm_requester_rc_t pldm_transport_test_send(struct pldm_transport *ctx,
						    pldm_tid_t tid,
						    const void *pldm_req_msg,
						    size_t req_msg_len)
{
	struct pldm_transport_test *test = transport_to_test(ctx);
	const struct pldm_transport_test_descriptor *desc;

	if (test->cursor > test->count) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	desc = &test->seq[test->cursor];

	if (desc->type != PLDM_TRANSPORT_TEST_ELEMENT_MSG_SEND) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	if (desc->send_msg.dst != tid) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	if (desc->send_msg.len != req_msg_len) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	if (memcmp(desc->send_msg.msg, pldm_req_msg, req_msg_len) != 0) {
		return PLDM_REQUESTER_SEND_FAIL;
	}

	test->cursor++;

	return PLDM_REQUESTER_SUCCESS;
}

LIBPLDM_ABI_TESTING
int pldm_transport_test_init(struct pldm_transport_test **ctx,
			     const struct pldm_transport_test_descriptor *seq,
			     size_t count)
{
	int rc;

	if (!ctx || *ctx) {
		return -EINVAL;
	}

	struct pldm_transport_test *test = malloc(sizeof(*test));
	if (!test) {
		return -ENOMEM;
	}

	test->transport.name = "TEST";
	test->transport.version = 1;
	test->transport.recv = pldm_transport_test_recv;
	test->transport.send = pldm_transport_test_send;
	test->transport.init_pollfd = pldm_transport_test_init_pollfd;
	test->seq = seq;
	test->count = count;
	test->cursor = 0;
	test->timerfd = timerfd_create(CLOCK_MONOTONIC, 0);
	if (test->timerfd < 0) {
		rc = -errno;
		goto cleanup_test;
	}

	*ctx = test;

	return 0;

cleanup_test:
	free(test);
	return rc;
}

LIBPLDM_ABI_TESTING
void pldm_transport_test_destroy(struct pldm_transport_test *ctx)
{
	close(ctx->timerfd);
	free(ctx);
}
