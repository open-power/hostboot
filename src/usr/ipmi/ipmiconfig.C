/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmiconfig.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

#include <stdint.h>
#include "ipmiconfig.H"

    //
    // Information contained in the Get Interface Capabilities command
    //
    // Request to response time default, in seconds
const uint8_t IPMI::g_bmc_timeout = 1;

    // Number of allowed outstanding requests default
const uint8_t IPMI::g_outstanding_req = 0xff;

    // The size of the BMC input buffer default (our write)
const uint8_t IPMI::g_xmit_buffer_size = 0x40;

    // The size of the BMC transmit buffer default (our read)
const uint8_t IPMI::g_recv_buffer_size = 0x40;

    // How many times we should retry a message if the BMC timesout default
const uint8_t IPMI::g_retries = 0x00;
