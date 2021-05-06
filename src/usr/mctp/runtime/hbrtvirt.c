/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/runtime/hbrtvirt.c $                             */
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

/**
 * @file  hbrtvirt.c
 * @brief Source code for HBRT's MCTP binding to the PHYP's virtual MCTP bridge
 */

// system headers
#include <endian.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// local headers
#include "libmctp-hbrtvirt.h"
// libmctp headers
#include <libmctp-alloc.h>
#include <libmctp-log.h>
#include <libmctp_rc.h>

extern int __mctp_hbrtvirt_hostboot_mctp_send(uint32_t len,
                                              void *val);

extern int __mctp_hbrtvirt_hostboot_mctp_receive(uint64_t *len,
                                                 void *val);
/**
 *  @brief Perform a MCTP_SEND fw_request to send the MCTP packet across
 *         the hypervisor's virtual bridge
 *
 *  @param[in] b   ptr to our hbrt mctp binding
 *  @param[in] pkt ptr to mctp_pktbuf we want to transmit
 *
 *  @return rc from the platform call attempting to perform this operation
 */
static int mctp_binding_hbrtvirt_tx(struct mctp_binding *b,
                                    struct mctp_pktbuf *pkt)
{
    int rc = 0;
    do
    {
        struct mctp_binding_hbrtvirt *hbrtvirt = binding_to_hbrtvirt(b);
        uint32_t len = mctp_pktbuf_size(pkt);
        if (len > tx_size) {
            rc = RC_MCTP_INVALID_LENGTH;
            break;
        }

        rc = hbrtvirt->ops.mctp_send(len, (uint8_t *)mctp_pktbuf_hdr(pkt));
    }while(0);

    return rc;
}

/* See libmctp-hbrtvirt.h for doxygen */
int mctp_hbrtvirt_rx_start(struct mctp_binding_hbrtvirt * const i_hbrtvirt)
{
    int rc = 0;
    uint64_t len = rx_size;
    uint8_t *virtual_rx = (uint8_t*)calloc(1, len);

    do {
    rc = i_hbrtvirt->ops.mctp_receive(&len, virtual_rx);
    if(rc)
    {
        // got a return code from the hypervisor request
        break;
    }

    // have mctp core logic allocate us a packet buffer
    struct mctp_pktbuf *pkt = mctp_pktbuf_alloc(&i_hbrtvirt->binding, len);
    if (!pkt)
    {
        rc = RC_MCTP_ALLOCATION_FAIL;
        break;
    }

    // copy what we have read over the virtual bus into the packet buffer
    // provided by the core logic
    memcpy(mctp_pktbuf_hdr(pkt), virtual_rx, len);

    // pass the packet we received into the mctp core logic for it to handle
    mctp_bus_rx(&i_hbrtvirt->binding, pkt);

    // mctp_bus_rx will free pkt
    pkt = NULL;

    } while(0);

    free(virtual_rx);
    virtual_rx = NULL;

    return rc;
}

/* allocate and basic initialisation */
static struct mctp_binding_hbrtvirt *__mctp_hbrtvirt_init(void)
{
    struct mctp_binding_hbrtvirt *hbrtvirt = __mctp_alloc(sizeof(*hbrtvirt));
    memset(hbrtvirt, 0, sizeof(*hbrtvirt));
    hbrtvirt->binding.name = "hbrtvirt";
    hbrtvirt->binding.version = HBRT_VER_CUR;
    hbrtvirt->binding.tx = mctp_binding_hbrtvirt_tx;
    hbrtvirt->binding.start = NULL;
    hbrtvirt->binding.pkt_size = RT_MCTP_BMTU;
    hbrtvirt->binding.pkt_pad = 0;
    return hbrtvirt;
}

void mctp_hbrtvirt_destroy(struct mctp_binding_hbrtvirt *hbrtvirt)
{
    __mctp_free(hbrtvirt);
}

struct mctp_binding_hbrtvirt *mctp_hbrtvirt_init_hbrt()
{
    struct mctp_binding_hbrtvirt *hbrtvirt = __mctp_hbrtvirt_init();
    if (!hbrtvirt)
    {
      return NULL;
    }

    /* Set internal operations mctp send/receive */
    hbrtvirt->ops.mctp_send    = __mctp_hbrtvirt_hostboot_mctp_send;
    hbrtvirt->ops.mctp_receive = __mctp_hbrtvirt_hostboot_mctp_receive;
    hbrtvirt->ops_data = hbrtvirt;

    return hbrtvirt;
}
