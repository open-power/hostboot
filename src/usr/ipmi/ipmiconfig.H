/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmiconfig.H $                                   */
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

#ifndef __IPMI_IPMICONFIG_H
#define __IPMI_IMPICONFIG_H

/**
 * @file ipmiconfig.H
 * @brief IPMI service provider defaults and constants
 */

namespace IPMI
{
    //
    // Information contained in the Get Interface Capabilities command
    //
    // Request to response time default, in seconds
    extern const uint8_t g_bmc_timeout;

    // Number of allowed outstanding requests default
    extern const uint8_t g_outstanding_req;

    // The size of the BMC input buffer default (our write)
    extern const uint8_t g_xmit_buffer_size;

    // The size of the BMC transmit buffer default (our read)
    extern const uint8_t g_recv_buffer_size;

    // How many times we should retry a message if the BMC timesout default
    extern const uint8_t g_retries;
};

#endif
