/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#include "responder.h"

#include <libpldm/base.h>
#include <libpldm/pldm.h>

#include <stdbool.h>

static bool pldm_responder_cookie_eq(const struct pldm_responder_cookie *left,
				     const struct pldm_responder_cookie *right)
{
	return left->tid == right->tid &&
	       left->instance_id == right->instance_id &&
	       left->type == right->type && left->command == right->command;
}

int pldm_responder_cookie_track(struct pldm_responder_cookie *jar,
				struct pldm_responder_cookie *cookie)
{
	struct pldm_responder_cookie *current;
	struct pldm_responder_cookie *next;

	if (!jar || !cookie) {
		return PLDM_REQUESTER_INVALID_SETUP;
	}

	current = jar;
	next = current->next;
	while (next) {
		/* Cookie must not already be known */
		if (pldm_responder_cookie_eq(next, cookie)) {
			return PLDM_REQUESTER_INVALID_SETUP;
		}
		current = next;
		next = next->next;
	}

	cookie->next = NULL;
	current->next = cookie;

	return PLDM_REQUESTER_SUCCESS;
}

struct pldm_responder_cookie *
pldm_responder_cookie_untrack(struct pldm_responder_cookie *jar, pldm_tid_t tid,
			      pldm_instance_id_t instance_id, uint8_t type,
			      uint8_t command)
{
	const struct pldm_responder_cookie cookie = { tid, instance_id, type,
						      command, NULL };
	struct pldm_responder_cookie *current;
	struct pldm_responder_cookie *next;

	if (!jar) {
		return NULL;
	}

	current = jar;
	next = current->next;
	while (next && !pldm_responder_cookie_eq(next, &cookie)) {
		current = next;
		next = next->next;
	}

	if (next) {
		current->next = next->next;
	}

	return next;
}
