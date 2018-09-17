/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmimsg.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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
/**
 * @file ipmimsg.C
 * @brief code for the IPMI message class
 */

#include <errl/errlmanager.H>

#include "ipmimsg.H"

#include <kernel/console.H>
#include <config.h>

// Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"msg: " printf_string,##args)

namespace IPMI
{

    ///
    /// @brief msg ctor
    /// @param[in] i_cmd, the network function & command
    /// @param[in] i_len, the length of the data
    /// @param[in] i_data, the data (new'd space)
    ///
    Message::Message(const command_t& i_cmd,
                     const uint8_t i_len,
                     uint8_t* i_data):
        iv_msg(msg_allocate()),
        iv_key(0),
        iv_len(i_len),
        iv_netfun(i_cmd.first),
        iv_seq(iv_key),
        iv_cmd(i_cmd.second),
        iv_cc(0),
        iv_state(0),
        iv_errl(NULL),
        iv_data(i_data)
    {
        iv_timeout.tv_sec = 0;
        iv_timeout.tv_nsec = 0;
    }

};
