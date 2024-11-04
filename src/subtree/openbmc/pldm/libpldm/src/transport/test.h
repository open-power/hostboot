/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#ifndef LIBPLDM_TRANSPORT_TEST_H
#define LIBPLDM_TRANSPORT_TEST_H

#include <libpldm/base.h>

#include <stddef.h>
#include <stdint.h>
#include <sys/timerfd.h>

#ifdef __cplusplus
extern "C" {
#endif

enum pldm_transport_test_element {
	PLDM_TRANSPORT_TEST_ELEMENT_MSG_SEND,
	PLDM_TRANSPORT_TEST_ELEMENT_MSG_RECV,
	PLDM_TRANSPORT_TEST_ELEMENT_LATENCY,
};

struct pldm_transport_test_msg_send {
	pldm_tid_t dst;
	const void *msg;
	size_t len;
};

struct pldm_transport_test_msg_recv {
	pldm_tid_t src;
	const void *msg;
	size_t len;
};

struct pldm_transport_test_descriptor {
	enum pldm_transport_test_element type;
	union {
		struct pldm_transport_test_msg_send send_msg;
		struct pldm_transport_test_msg_recv recv_msg;
		struct itimerspec latency;
	};
};

struct pldm_transport_test;

int pldm_transport_test_init(struct pldm_transport_test **ctx,
			     const struct pldm_transport_test_descriptor *seq,
			     size_t count);
void pldm_transport_test_destroy(struct pldm_transport_test *ctx);
struct pldm_transport *
pldm_transport_test_core(struct pldm_transport_test *ctx);

#if PLDM_HAS_POLL
struct pollfd;
int pldm_transport_test_init_pollfd(struct pldm_transport *ctx,
				    struct pollfd *pollfd);
#endif

#ifdef __cplusplus
}
#endif

#endif
