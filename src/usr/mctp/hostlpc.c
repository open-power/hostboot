/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/hostlpc.c $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */

// System Headers
#include <endian.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <hbotcompid.H>
// Headers from local directory
#include "libmctp-hostlpc.h"
#include "extern/libmctp-alloc.h"
#include "extern/libmctp-log.h"

// List external IO function we get from hostboot_mctp
extern int __mctp_hostlpc_hostboot_kcs_read(void *arg,
                                            enum mctp_binding_lpc_kcs_reg reg,
                                            uint8_t *val);

extern int __mctp_hostlpc_hostboot_kcs_write(void *arg,
                                             enum mctp_binding_lpc_kcs_reg reg,
                                             uint8_t val);

extern int __mctp_hostlpc_hostboot_lpc_read(void *arg, void * buf,
                                            uint64_t offset, size_t len);

extern int __mctp_hostlpc_hostboot_lpc_write(void *arg, void * buf,
                                             uint64_t offset, size_t len);

extern void __mctp_hostlpc_hostboot_nanosleep(uint64_t i_sec,
                                              uint64_t i_nsec);

extern void __mctp_hostlpc_hostboot_do_shutdown(uint64_t i_status);

extern void __mctp_hostlpc_hostboot_console_print(const char* i_message);

// Perform write on KCS Data register
static int mctp_hostlpc_kcs_send(struct mctp_binding_hostlpc *hostlpc,
                                 uint8_t data)
{
    uint8_t status = 0;
    int rc = 0;

    for (;;) {
        // Poll on the KCS status register until IBF bit is clear
        // prior to sending a write across the KCS interface
        rc = hostlpc->ops.kcs_read(hostlpc->ops_data,
                                   MCTP_LPC_KCS_REG_STATUS,
                                   &status);
        if (rc != 0) {
            mctp_prwarn("KCE status read failed");
            return -1;
        }
        // Make sure that IBF is clear before trying to send another message
        if (!(status & KCS_STATUS_IBF)) {
            break;
        }
        // 25 nanosecond sleep between status polls
        hostlpc->ops.nanosleep(0, 25);
        /* TODO RTC: 249701 timeout */
    }

    rc = hostlpc->ops.kcs_write(hostlpc->ops_data,
                                MCTP_LPC_KCS_REG_DATA,
                                data);
    if (rc != 0) {
        mctp_prwarn("KCS data write failed");
        return -1;
    }

    return 0;
}

// Basic CRC formula
static uint32_t crc32(const void *buf, size_t len)
{
    const uint8_t *buf8 = buf;
    uint32_t rem = 0xffffffff;

    for (; len; len--) {
        int i;

        rem = rem ^ *buf8;
        for (i = 0; i < CHAR_BIT; i++)
            rem = (rem >> 1) ^ ((rem & 1) * 0xEDB88320);

        buf8++;
    }

    return rem ^ 0xffffffff;
}

// Add four-byte CRC at the end of the package
static bool mctp_hostlpc_add_crc(struct mctp_pktbuf* pkt)
{
    uint32_t crc_code = htobe32(crc32(mctp_pktbuf_hdr(pkt),
                                      mctp_pktbuf_size(pkt)));

    return mctp_pktbuf_push(pkt, &crc_code, sizeof(crc_code));
}

// Validate the packet CRC and discard it for ease of processing
static bool mctp_hostlpc_validate_crc(struct mctp_pktbuf* pkt)
{
    uint32_t crc_code = 0;
    void* crc_ptr = NULL;

    crc_code = htobe32(crc32(mctp_pktbuf_hdr(pkt),
                             // skip the actual CRC code
                             mctp_pktbuf_size(pkt) - MCTP_CRC_SIZE));
    // Grab the CRC out of the MCTP packet
    crc_ptr = pkt->data + (pkt->end - MCTP_CRC_SIZE);

    bool valid = crc_ptr && (!memcmp(&crc_code, crc_ptr, MCTP_CRC_SIZE));

    // Pop the crc off of the packet to simplify further processing
    pkt->end -= sizeof(crc_code);

    if(!valid)
    {
        mctp_prwarn("CRC check failed. Expected: 0x%08x; actual: 0x%08x",
                    crc_code,
                    *((uint32_t*)crc_ptr));
    }

    return valid;
}

// Notify the bmc that we (the host) have started a tx across the bus
static int mctp_binding_hostlpc_tx(struct mctp_binding *b,
                                   struct mctp_pktbuf *pkt)
{
    struct mctp_binding_hostlpc *hostlpc = binding_to_hostlpc(b);
    uint32_t len;

    len = mctp_pktbuf_size(pkt);
    if (len > hostlpc->lpc_hdr->tx_size - sizeof(len)) {
        mctp_prwarn("invalid TX len 0x%x", len);
        return -1;
    }

    // tx section starts with uint32_t variable followed by a uint8_t array

    // first write the length and ensure its big-endian
    uint32_t tmp = htobe32(len);
    hostlpc->ops.lpc_write(hostlpc->ops_data, &tmp,
                           hostlpc->lpc_hdr->tx_offset, sizeof(tmp));

    // Insert the CRC at the end of the buffer; re-compute the length
    if(mctp_hostlpc_add_crc(pkt))
    {
        mctp_prwarn("Could not add CRC to MCTP packet!");
    }
    len = mctp_pktbuf_size(pkt);

    // then write the buffer to the tx space for len bytes
    hostlpc->ops.lpc_write(hostlpc->ops_data, mctp_pktbuf_hdr(pkt),
                           hostlpc->lpc_hdr->tx_offset + sizeof(len), len);

    mctp_binding_set_tx_enabled(b, false);

    mctp_hostlpc_kcs_send(hostlpc, KCS_TX_BEGIN);
    return 0;
}

// This will go away in future commits
void mctp_hostlpc_rx_start(struct mctp_binding_hostlpc *hostlpc) __attribute__((unused));

// Read what was written to the LPC window by the BMC
void mctp_hostlpc_rx_start(struct mctp_binding_hostlpc *hostlpc)
{
    struct mctp_pktbuf *pkt;
    uint32_t len;

    // rx section starts with uint32_t variable followed by a uint8_t array

    // first read the length in big endian
    hostlpc->ops.lpc_read(hostlpc->ops_data, &len,
                          hostlpc->lpc_hdr->rx_offset, sizeof(len));
    len = be32toh(len);

    // We cannot read lengths that exceed out pkt size
    if (len > hostlpc->lpc_hdr->rx_size - sizeof(len)) {
        mctp_prwarn("invalid RX len 0x%x", len);
        return;
    }

    // We cannot read lengths that exceed out pkt size
    if (len > hostlpc->binding.pkt_size) {
        mctp_prwarn("invalid RX len 0x%x, binding.pkt_size 0x%x",
                    len, hostlpc->binding.pkt_size );
        return;
    }

    // Make space for the CRC at the end of the buffer
    len += MCTP_CRC_SIZE;

    // now that we know the length allocate a pkt buffer
    // which will get filled in on the next read
    pkt = mctp_pktbuf_alloc(&hostlpc->binding, len);

    if (!pkt)
    {
        mctp_prwarn("Could not allocate a packet.");
        hostlpc->ops.console_print("Could not allocate a packet, Hostboot should have asserted prior to reaching this! Shutting down.");
        hostlpc->ops.do_shutdown(MCTP_COMP_ID | RC_FAILED_ALLOCATING_PACKET);
    }

    // after we get size and allocate the buffer then read the remainig
    // contents of the rx window
    hostlpc->ops.lpc_read(hostlpc->ops_data, mctp_pktbuf_hdr(pkt),
                          hostlpc->lpc_hdr->rx_offset + sizeof(len), len);

    // Tell the BMC we have read the message off the bus before moving on
    mctp_hostlpc_kcs_send(hostlpc, KCS_RX_COMPLETE);

    // If the CRC is valid then send the MCTP packet along to the core mctp
    // logic. The core mctp logic will determine if its a complete message
    // or needs to be added to an existing message context. If this packet
    // marks an end of message then the complete message will be routed out
    // to the PLDM layer.
    if(mctp_hostlpc_validate_crc(pkt))
    {
        mctp_bus_rx(&hostlpc->binding, pkt);
    }
    else
    {
        mctp_pktbuf_free(pkt);
        pkt = NULL;
        mctp_prwarn("Dropping corrupted packet");
        hostlpc->ops.console_print("Received invalid MCTP packet from BMC. Shutting down.");
        hostlpc->ops.do_shutdown(MCTP_COMP_ID | RC_CRC_MISMATCH);
    }

    return;
}

// This will go away in future commits
void mctp_hostlpc_tx_complete(struct mctp_binding_hostlpc *hostlpc) __attribute__((unused));

// Hook into core code to state that we are ready for another tx
// (IE this tx is complete so we are ready for more )
void mctp_hostlpc_tx_complete(struct mctp_binding_hostlpc *hostlpc)
{
    mctp_binding_set_tx_enabled(&hostlpc->binding, true);
}

// Initial handshake hostboot need to perform when getting initialized.
// It is safe to assume at this point that the BMC should have initialized
// their end already.
static int mctp_hostlpc_init_hb(struct mctp_binding_hostlpc *hostlpc)
{
    int rc = 0;
    uint8_t l_data;

    rc = hostlpc->ops.kcs_read(hostlpc->ops_data,
                                MCTP_LPC_KCS_REG_STATUS,
                                &l_data);

    if( (l_data & KCS_STATUS_BMC_READY) && rc == 0)
    {
        struct mctp_lpcmap_hdr *hdr = hostlpc->lpc_hdr;

        // check if mtu negotiation is supported
        if(hdr->bmc_ver_cur >= 2)
        {
            hdr->rx_size = HOST_DESIRED_MTU;
        }
        hdr->host_ver_min = htobe16(HOST_VER_MIN);
        hdr->host_ver_cur = htobe16(HOST_VER_CUR);
        mctp_hostlpc_kcs_send(hostlpc, KCS_INIT);
    }
    else
    {
        mctp_prwarn("bmc is not setup");
    }

    // initialize the tx space to say the host is ready to use it
    mctp_binding_set_tx_enabled(&hostlpc->binding, true);

    return rc;
}

// Wrapper for mctp_hostlpc_init_hb, see comments for that func
static int mctp_binding_hostlpc_start_hb(struct mctp_binding *b)
{
    struct mctp_binding_hostlpc *hostlpc = container_of(b,
        struct mctp_binding_hostlpc, binding);

    return mctp_hostlpc_init_hb(hostlpc);
}

/* allocate and basic initialisation */
static struct mctp_binding_hostlpc *__mctp_hostlpc_init(void)
{
    struct mctp_binding_hostlpc *hostlpc;

    hostlpc = __mctp_alloc(sizeof(*hostlpc));
    memset(hostlpc, 0, sizeof(*hostlpc));
    hostlpc->binding.name = "hostlpc";
    hostlpc->binding.version = HOST_VER_CUR;
    hostlpc->binding.tx = mctp_binding_hostlpc_tx;
    hostlpc->binding.start = mctp_binding_hostlpc_start_hb;
    hostlpc->binding.pkt_size = MCTP_BMTU;
    hostlpc->binding.pkt_pad = 0;
    hostlpc->lpc_map = NULL;

    return hostlpc;
}

// function to get pointer to core binding
struct mctp_binding *mctp_binding_hostlpc_core(struct mctp_binding_hostlpc *b)
{
    return &b->binding;
}

// Public interface used to trigger the initialization of the hostlpc
// mctp binding
struct mctp_binding_hostlpc *mctp_hostlpc_init_hostboot(uint64_t i_mctpVaddr)
{
  struct mctp_binding_hostlpc *hostlpc;

  hostlpc = __mctp_hostlpc_init();
  if (!hostlpc)
    return NULL;

  /* Set internal operations for kcs and lpc */
  hostlpc->ops.kcs_read      = __mctp_hostlpc_hostboot_kcs_read;
  hostlpc->ops.kcs_write     = __mctp_hostlpc_hostboot_kcs_write;
  hostlpc->ops.lpc_read      = __mctp_hostlpc_hostboot_lpc_read;
  hostlpc->ops.lpc_write     = __mctp_hostlpc_hostboot_lpc_write;
  hostlpc->ops.nanosleep     = __mctp_hostlpc_hostboot_nanosleep;
  hostlpc->ops.do_shutdown   = __mctp_hostlpc_hostboot_do_shutdown;
  hostlpc->ops.console_print = __mctp_hostlpc_hostboot_console_print;
  hostlpc->ops_data = hostlpc;

  // Set LPC map pointer to Hostboot's Virtual Address of
  // the MCTP section in the LPC space
  hostlpc->lpc_map = (void *)(i_mctpVaddr);

  return hostlpc;
}

