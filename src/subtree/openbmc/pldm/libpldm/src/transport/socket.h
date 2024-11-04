/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#ifndef LIBPLDM_SRC_TRANSPORT_SOCKET_H
#define LIBPLDM_SRC_TRANSPORT_SOCKET_H

struct pldm_socket_sndbuf {
	int size;
	int socket;
	int max_size;
};

int pldm_socket_sndbuf_init(struct pldm_socket_sndbuf *ctx, int socket);
int pldm_socket_sndbuf_accomodate(struct pldm_socket_sndbuf *ctx, int msg_len);
int pldm_socket_sndbuf_get(struct pldm_socket_sndbuf *ctx);

#endif // LIBPLDM_SRC_TRANSPORT_SOCKET_H
