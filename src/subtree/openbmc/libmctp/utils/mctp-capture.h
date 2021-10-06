/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */

#ifndef _UTILS_MCTP_CAPTURE_H
#define _UTILS_MCTP_CAPTURE_H

#include "config.h"

#include "libmctp.h"

#include <sys/types.h>

#if HAVE_PCAP
#include <pcap/pcap.h>
#else
typedef void pcap_t;
typedef void pcap_dumper_t;
#endif

#define CAPTURE_LINKTYPE_FIRST	147
#define CAPTURE_LINKTYPE_LAST	162

#define __unused __attribute__((unused))

struct capture {
	const char	*path;
	int		linktype;
	pcap_t		*pcap;
	pcap_dumper_t	*dumper;
};

#if HAVE_PCAP
int capture_init(void);
int capture_prepare(struct capture *cap);
void capture_close(struct capture *cap);
void capture_binding(struct mctp_pktbuf *pkt, void *user);
void capture_socket(pcap_dumper_t *dumper, const void *buf, size_t len);
#else
#include <stdio.h>
static inline int
capture_init(void)
{
	fprintf(stderr, "libpcap support is disabled, cannot initialise libpcap\n");
	return 0;
}

static inline int
capture_prepare(struct capture *cap)
{
	fprintf(stderr, "libpcap support is disabled, cannot capture to %s\n",
		cap->path);
	return 0;
}

static inline void capture_close(struct capture *cap __unused)
{
}

static inline void
capture_binding(struct mctp_pktbuf *pkt __unused, void *user __unused)
{
}

static inline void capture_socket(pcap_dumper_t *dumper __unused,
				  const void *buf __unused,
				  size_t len __unused)
{
}
#endif
#endif
