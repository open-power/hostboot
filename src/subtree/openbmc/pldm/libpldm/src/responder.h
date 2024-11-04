/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#ifndef LIBPLDM_SRC_RESPONDER_H
#define LIBPLDM_SRC_RESPONDER_H

#include <libpldm/base.h>
#include <libpldm/instance-id.h>

#include <stdint.h>

struct pldm_responder_cookie {
	pldm_tid_t tid;
	pldm_instance_id_t instance_id;
	uint8_t type;
	uint8_t command;
	struct pldm_responder_cookie *next;
};

int pldm_responder_cookie_track(struct pldm_responder_cookie *jar,
				struct pldm_responder_cookie *cookie);

struct pldm_responder_cookie *
pldm_responder_cookie_untrack(struct pldm_responder_cookie *jar, pldm_tid_t tid,
			      pldm_instance_id_t instance_id, uint8_t type,
			      uint8_t command);

#endif
