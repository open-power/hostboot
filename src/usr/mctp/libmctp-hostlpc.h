/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/libmctp-hostlpc.h $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#define HOST_VER_CUR 2
// EID is the MCTP endpoint ID, which aids in routing MCTP packets
// theorectically we could assign these dynamically but for now
// we are saying that BMC is EID 8 and hostboot IPL time is HOST_EID 9
#define BMC_EID 8
#define HOST_EID 9

#define HOST_DESIRED_MTU 32768


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
