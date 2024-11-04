/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#ifndef LIBPLDM_DEMUX_H
#define LIBPLDM_DEMUX_H

#include <libpldm/base.h>
#include <libpldm/pldm.h>

#ifdef __cplusplus
extern "C" {
#endif

struct pldm_transport_mctp_demux;

/* Init the transport backend */
int pldm_transport_mctp_demux_init(struct pldm_transport_mctp_demux **ctx);

/* Destroy the transport backend */
void pldm_transport_mctp_demux_destroy(struct pldm_transport_mctp_demux *ctx);

/* Get the core pldm transport struct */
struct pldm_transport *
pldm_transport_mctp_demux_core(struct pldm_transport_mctp_demux *ctx);

#ifdef PLDM_HAS_POLL
struct pollfd;
/* Init pollfd for async calls */
int pldm_transport_mctp_demux_init_pollfd(struct pldm_transport *t,
					  struct pollfd *pollfd);
#endif

/* Inserts a TID-to-EID mapping into the transport's device map */
int pldm_transport_mctp_demux_map_tid(struct pldm_transport_mctp_demux *ctx,
				      pldm_tid_t tid, mctp_eid_t eid);

/* Removes a TID-to-EID mapping from the transport's device map */
int pldm_transport_mctp_demux_unmap_tid(struct pldm_transport_mctp_demux *ctx,
					pldm_tid_t tid, mctp_eid_t eid);

#ifdef __cplusplus
}
#endif

#endif /* LIBPLDM_DEMUX_H */
