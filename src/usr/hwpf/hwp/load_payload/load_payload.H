/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/load_payload/load_payload.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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

#ifndef __LOAD_PAYLOAD_LOAD_PAYLOAD_H
#define __LOAD_PAYLOAD_LOAD_PAYLOAD_H


#include <stdint.h>

namespace LOAD_PAYLOAD
{

/**
 *  @brief host_load_payload
 *         Host Load Payload
 *
 *  @param[in,out] - pointer to any arguments, usually NULL
 *
 *  return - any error logs to istep
 *
 */
void*  call_host_load_payload(void *io_pArgs);

}; // end namespace

#endif
