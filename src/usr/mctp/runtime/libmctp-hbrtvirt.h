/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/runtime/libmctp-hbrtvirt.h $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#ifndef _LIBMCTP_HBRTVIRT_H
#define _LIBMCTP_HBRTVIRT_H

/**
 *  @file  libmctp-hbrtvirt.h
 *  @brief libmctp binding for hbrt to a virtual bridge
 */

#include <libmctp.h>
#include <container_of.h>

#ifdef __cplusplus
extern "C" {
#endif

#define binding_to_hbrtvirt(b) \
  container_of(b, struct mctp_binding_hbrtvirt, binding)

#define HBRT_VER_MIN 1
#define HBRT_VER_CUR 1
// EID is the MCTP endpoint ID, which aids in routing MCTP packets
// theoretically we could assign these dynamically but for now
// we are saying that BMC is EID 8 and hostboot IPL time is HOST_EID 9
#define BMC_EID 8
#define HOST_EID 9
#define HBRT_EID 10

// HBRT will use a base max transmission unit of 4 KB - 4 (size) - 4 (crc32)
#define RT_MCTP_BMTU (4088)

// Phyp messages have a header size of 8 bytes to
// define the type of message.
#define PHYP_HDR_SIZE (8)

// layout of TX/RX areas
const uint32_t  rx_size   = RT_MCTP_BMTU + PHYP_HDR_SIZE;
const uint32_t  tx_size   = RT_MCTP_BMTU;

struct mctp_binding_hbrtvirt_ops {
  int (*mctp_send)(uint32_t len, void *val);
  int (*mctp_receive)(uint64_t *len, void *val);
};

struct mctp_binding_hbrtvirt {
  struct mctp_binding              binding;
  struct mctp_binding_hbrtvirt_ops ops;
  void                             *ops_data;
};

/**
 *  @brief Free dynamically allocated memory for hbrtvirt struct
 *
 *  @return void
 */
void mctp_hbrtvirt_destroy(struct mctp_binding_hbrtvirt *hbrtvirt);

/**
 *  @brief Function to initialize an MCTP binding for hbrt to the
 *         virtual bridge the hypervisor is providing
 *
 *  @return An initialized mctp_binding_hbrtvirt
 */
struct mctp_binding_hbrtvirt *mctp_hbrtvirt_init_hbrt();

/**
 *  @brief Function which will call into the MCTP core logic
 *         to read the next packet off the virtual bus
 *
 *  @param[in] i_hbrtvirt ptr to hbrt mctp binding for hypervisor's virtual bridge
 *
 *  @return rc from the platform call attempting to perform this operation
 */
int mctp_hbrtvirt_rx_start(struct mctp_binding_hbrtvirt * const i_hbrtvirt);

#ifdef __cplusplus
}
#endif

#endif /* _LIBMCTP_HBRTVIRT_H */
