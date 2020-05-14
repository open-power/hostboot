/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/runtime/hbrt_mctp.H $                            */
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
#ifndef _HBRT_MCTP_H
#define _HBRT_MCTP_H

/**
 *  @file  hbrt_mctp.H
 *  @brief Declaration of functions we will bind to the hbrt virtual
 *         mctp binding.
 */
#include <stdint.h>

/**
 *  @brief Function which will bind to mctp_send and calls MCTP_SEND
 *         via the firmware_request interface.
 *
 *  @param[in] i_len  Length of the MCTP packet we want to send.
 *  @param[in] i_val  Pointer to a buffer containing MCTP packet we want to
 *                    send. This buffer is allocated and freed by the caller.
 *
 *  @return Return code, either from firmware_request or libmctp.
 */
extern "C"
int __mctp_hbrtvirt_hostboot_mctp_send(uint32_t i_len, const void *i_val);

/**
 *  @brief Function which will bind to mctp_receive and calls MCTP_RECEIVE
 *         via the firmware_request interface.
 *
 *  @param[in,out] len  in  : Length of the buffer provided.
 *                      out : Length copied into buffer.
 *  @param[out]    val  Pointer to buffer that MCTP packet will by copied
 *                      into. This buffer is allocated and freed by the caller.
 *
 *  @return Return code, either from firmware_request or libmctp.
 */
extern "C"
int __mctp_hbrtvirt_hostboot_mctp_receive(uint64_t *io_len, void *o_val);

#endif