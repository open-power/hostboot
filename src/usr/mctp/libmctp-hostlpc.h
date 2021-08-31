/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/libmctp-hostlpc.h $                              */
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
#ifndef _LIBMCTP_HOSTLPCL_H
#define _LIBMCTP_HOSTLPCL_H

#ifdef __cplusplus
extern "C" {
#endif

// Headers from local directory
#include "libmctp-lpc.h"

#define binding_to_hostlpc(b) \
  container_of(b, struct mctp_binding_hostlpc, binding)

#define HOST_VER_MIN 1
#define HOST_VER_CUR 3
// EID is the MCTP endpoint ID, which aids in routing MCTP packets
// theorectically we could assign these dynamically but for now
// we are saying that BMC is EID 8 and hostboot IPL time is HOST_EID 9
#define BMC_EID 8
#define HOST_EID 9

#define HOST_DESIRED_MTU 32768

// The maximum amount of memory we will allocate for a message
// context we are building for an incoming MCTP message made
// of multiple MCTP packets. We will se this to be 128KB as the
// largest message we expect is the response to 127KB +1 PLDM
// file read requests HB makes during lid verification in istep 21
// We cannot use 127KB+1 directly because this value must be a
// 8KB, 16KB, 32KB, 64KB, 128KB, 256KB etc. due the the way we currently
// grow the memory buffer allotted for a given message context.
// See extern/core.c mctp_msg_ctx_add_pkt for more info.
#define HOST_MAX_INCOMING_MESSAGE_ALLOCATION 131072

// Defined here because mctp_reasoncodes.H uses C++ syntax.
#define RC_CRC_MISMATCH 0x05
#define RC_FAILED_ALLOCATING_PACKET 0x06

struct mctp_binding_hostlpc {
  struct mctp_binding  binding;

  union {
    void      *lpc_map;
    struct mctp_lpcmap_hdr  *lpc_hdr;
  };

  /* direct ops data */
  struct mctp_binding_lpc_ops  ops;
  void                         *ops_data;
};

struct mctp_binding_hostlpc *mctp_hostlpc_init_hostboot(uint64_t i_mctpVaddr);

void mctp_hostlpc_tx_complete(struct mctp_binding_hostlpc *hostlpc);

void mctp_hostlpc_rx_start(struct mctp_binding_hostlpc *hostlpc);

#ifdef __cplusplus
}
#endif

#endif /* _LIBMCTP_HOSTLPCL_H */
