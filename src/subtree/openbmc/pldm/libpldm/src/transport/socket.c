/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#include "socket.h"

#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

int pldm_socket_sndbuf_init(struct pldm_socket_sndbuf *ctx, int socket)
{
	FILE *fp;
	long max_buf_size;
	char line[128];
	char *endptr;

	if (socket == -1) {
		return -1;
	}
	ctx->socket = socket;

	fp = fopen("/proc/sys/net/core/wmem_max", "r");
	if (fp == NULL) {
		return -1;
	}

	if (fgets(line, sizeof(line), fp) == NULL) {
		fclose(fp);
		return -1;
	}

	errno = 0;
	max_buf_size = strtol(line, &endptr, 10);
	if (errno != 0 || endptr == line) {
		fclose(fp);
		return -1;
	}

	fclose(fp);

	if (max_buf_size > INT_MAX) {
		max_buf_size = INT_MAX;
	}
	ctx->max_size = (int)max_buf_size;

	if (pldm_socket_sndbuf_get(ctx)) {
		return -1;
	}

	return 0;
}

int pldm_socket_sndbuf_accomodate(struct pldm_socket_sndbuf *ctx, int msg_len)
{
	if (msg_len < ctx->size) {
		return 0;
	}
	/* If message is bigger than the max size, don't return a failure. Set
	 * the buffer to the max size and see what happens. We don't know how
	 * much of the extra space the kernel actually uses so let it tell us if
	 * there wasn't enough space */
	if (msg_len > ctx->max_size) {
		msg_len = ctx->max_size;
	}
	if (ctx->size == ctx->max_size) {
		return 0;
	}
	int rc = setsockopt(ctx->socket, SOL_SOCKET, SO_SNDBUF, &(msg_len),
			    sizeof(msg_len));
	if (rc == -1) {
		return -1;
	}
	ctx->size = msg_len;
	return 0;
}

int pldm_socket_sndbuf_get(struct pldm_socket_sndbuf *ctx)
{
	/* size returned by getsockopt is the actual size of the buffer - twice
	 * the size of the value used by setsockopt. So for consistency, return
	 * half of the buffer size */
	int buf_size;
	socklen_t optlen = sizeof(buf_size);
	int rc = getsockopt(ctx->socket, SOL_SOCKET, SO_SNDBUF, &(buf_size),
			    &optlen);
	if (rc == -1) {
		return -1;
	}
	ctx->size = buf_size / 2;
	return 0;
}
