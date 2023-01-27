#include "utils/mctp-capture.h"

#include <stdio.h>
#include <sys/time.h>
#include <string.h>

#if HAVE_PCAP
#include <pcap/sll.h>
#include <linux/if_ether.h>
#include "libmctp-alloc.h"

#ifndef ETH_P_MCTP
#define ETH_P_MCTP 0xfa
#endif

#endif

int capture_init(void)
{
	char errbuf[PCAP_ERRBUF_SIZE];
	int rc;

	if ((rc = pcap_init(PCAP_CHAR_ENC_UTF_8, errbuf)) == -1) {
		fprintf(stderr, "pcap_init: %s\n", errbuf);
		return -1;
	}

	return 0;
}

int capture_prepare(struct capture *cap)
{
	int rc;

	if (!(cap->pcap = pcap_open_dead(CAPTURE_LINKTYPE_LINUX_SLL2,
					 UINT16_MAX))) {
		fprintf(stderr, "pcap_open_dead: failed\n");
		return -1;
	}
	if (!(cap->dumper = pcap_dump_open(cap->pcap, cap->path))) {
		fprintf(stderr, "pcap_dump_open: failed\n");
		return -1;
	}

	return 0;
}

void capture_close(struct capture *cap)
{
	pcap_dump_close(cap->dumper);

	pcap_close(cap->pcap);
}

void capture_binding(struct mctp_pktbuf *pkt, bool outgoing, void *user)
{
	pcap_dumper_t *dumper = user;
	struct pcap_pkthdr hdr;
	int rc;
	uint8_t *pktbuf = NULL;
	size_t size;

	if ((rc = gettimeofday(&hdr.ts, NULL)) == -1)
		return;

	/* Write sll2 header */
	size = sizeof(struct sll2_header) + mctp_pktbuf_size(pkt);
	pktbuf = __mctp_alloc(size);
	if (!pktbuf)
		return;

	struct sll2_header *sll2 = (struct sll2_header *)pktbuf;
	sll2->sll2_protocol = htons(ETH_P_MCTP);
	if (outgoing)
		sll2->sll2_pkttype = LINUX_SLL_OUTGOING;
	else
		sll2->sll2_pkttype = LINUX_SLL_HOST;
	sll2->sll2_reserved_mbz = 0x0;
	sll2->sll2_if_index = 0x0;
	sll2->sll2_hatype = 0x0;
	sll2->sll2_halen = 0x0;
	memset(sll2->sll2_addr, 0, SLL_ADDRLEN);

	memcpy(pktbuf + sizeof(struct sll2_header), mctp_pktbuf_hdr(pkt),
	       mctp_pktbuf_size(pkt));

	hdr.caplen = size;
	hdr.len = size;

	pcap_dump((u_char *)dumper, &hdr, (const u_char *)pktbuf);
	__mctp_free(pktbuf);
}

void capture_socket(pcap_dumper_t *dumper, const void *buf, size_t len,
		    bool outgoing, int eid)
{
	struct pcap_pkthdr hdr;
	int rc;
	uint8_t *pktbuf = NULL;
	size_t size;

	if ((rc = gettimeofday(&hdr.ts, NULL)) == -1)
		return;

	/* Write sll2 header */
	size = sizeof(struct sll2_header) + sizeof(struct mctp_hdr) + len;
	pktbuf = __mctp_alloc(size);
	if (!pktbuf)
		return;

	struct sll2_header *sll2 = (struct sll2_header *)pktbuf;
	sll2->sll2_protocol = htons(ETH_P_MCTP);
	if (outgoing)
		sll2->sll2_pkttype = LINUX_SLL_OUTGOING;
	else
		sll2->sll2_pkttype = LINUX_SLL_HOST;
	sll2->sll2_reserved_mbz = 0x0;
	sll2->sll2_if_index = 0x0;
	sll2->sll2_hatype = 0x0;
	sll2->sll2_halen = 0x0;
	memset(sll2->sll2_addr, 0, SLL_ADDRLEN);

	/* Write fake mctp header */
	struct mctp_hdr *mctp =
		(struct mctp_hdr *)(pktbuf + sizeof(struct sll2_header));
	mctp->ver = 1;
	mctp->flags_seq_tag = 0xc0; //set SOM and EOM
	if (outgoing) {
		mctp->dest = eid;
		mctp->src = 0;
	} else {
		mctp->dest = 0;
		mctp->src = eid;
	}

	/* Ignore the eid at start of buf */
	memcpy(pktbuf + sizeof(struct sll2_header) + sizeof(struct mctp_hdr),
	       buf + 1, len - 1);

	hdr.caplen = size;
	hdr.len = size;

	pcap_dump((u_char *)dumper, &hdr, (const u_char *)pktbuf);
	__mctp_free(pktbuf);
}
