#include "utils/mctp-capture.h"

#include <stdio.h>
#include <sys/time.h>

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

	if (cap->linktype < CAPTURE_LINKTYPE_FIRST ||
			cap->linktype > CAPTURE_LINKTYPE_LAST) {
		fprintf(stderr,
			"Invalid private linktype value %d: see https://www.tcpdump.org/linktypes.html\n",
			cap->linktype);
		return -1;
	}

	if (!(cap->pcap = pcap_open_dead(cap->linktype, UINT16_MAX))) {
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

void capture_binding(struct mctp_pktbuf *pkt, void *user)
{
	pcap_dumper_t *dumper = user;
	struct pcap_pkthdr hdr;
	int rc;

	if ((rc = gettimeofday(&hdr.ts, NULL)) == -1)
		return;

	hdr.caplen = mctp_pktbuf_size(pkt);
	hdr.len = mctp_pktbuf_size(pkt);

	pcap_dump((u_char *)dumper, &hdr, (const u_char *)mctp_pktbuf_hdr(pkt));
}

void capture_socket(pcap_dumper_t *dumper, const void *buf, size_t len)
{
	struct pcap_pkthdr hdr;
	int rc;

	if ((rc = gettimeofday(&hdr.ts, NULL)) == -1)
		return;

	hdr.caplen = len;
	hdr.len = len;

	pcap_dump((u_char *)dumper, &hdr, buf);
}
