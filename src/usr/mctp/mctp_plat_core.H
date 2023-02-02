/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/mctp_plat_core.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2023                        */
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

#ifndef MCTP_PLAT_CORE_H
#define MCTP_PLAT_CORE_H

#include <stdint.h>

namespace MCTP {

/**
 *  @brief Get the MCTP tag to populate in the tag field of the next MCTP
 *      message
 *  @warning This API is not threadsafe, however all existing code locations
 *      already serialize message creation.  Hostboot IPL code only calls
 *      this from a serialized message processing loop, and Hostboot runtime
 *      code is inherently single-threaded.
 *  @return uint8_t The 7 bit tag value to use in the next MCTP message
 */
uint8_t get_mctp_tag();

} // End MCTP namespace

#endif // MCTP_PLAT_CORE_H