/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mctp/mctpif.H $                               */
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
#ifndef MCTPIF_H
#define MCTPIF_H

/**
 * @file mctpif.H
 *
 * @brief MCTP's interface for hostboot userspace modules to include
 *
 */

#include <sys/msg.h>
namespace MCTP
{
    /**
    * @brief Register the LPC bus with the hostlpc binding. This will
    *        trigger the handshake between the host and the bmc over
    *        the KCS interface after which MCTP traffic will start
    *        flowing.
    * @note This function is just a wrapper that calls a function of the same
    *       name on the mctpRp singleton that does the real work.
    */
    void register_mctp_bus(void);
}

#endif
