/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_setFFDCAddr.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
* @file sbe_setFFDCAddr.C
* @brief Set FFDC Address inform the SBE of other
         procs in the system.
*/

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>
#include <targeting/common/targetservice.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"sendSetFFDCAddr: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"sendSetFFDCAddr: " printf_string,##args)

namespace SBEIO
{

    /**
    * @brief Set the FFDC address for the SBE so it is aware of the FFDC buffer
    *        and its size and it is aware of the SBE Communication buffer and
    *        its size
    *
    * @param[in] i_sbeffdcSize uint32 Size of SBE FFDC buffer
    * @param[in] i_sbeCommSize uint32 Size of SBE Communication buffer
    * @param[in] i_sbeffdcAddr uint64 Physical mainstore address of FFDC buffer
    * @param[in] i_sbeCommAddr uint64 Physical mainstore address of Comm buffer
    * @param[in] i_procChip The proc to which you would like to send the info
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendSetFFDCAddr(const uint32_t i_sbeffdcSize,
                               const uint32_t i_sbeCommSize,
                               const uint64_t i_sbeffdcAddr,
                               const uint64_t i_sbeCommAddr,
                               TARGETING::Target * i_procChip)
    {
        errlHndl_t errl = NULL;

        SBE_TRACF(ENTER_MRK "sending set FFDC address from HB -> SBE for Proc "
                  "0x%x, FFDC at 0x%016x for %d, Comm at 0x%016x for %d",
                  i_procChip->getAttr<TARGETING::ATTR_POSITION>(),
                  i_sbeffdcAddr,
                  i_sbeffdcSize,
                  i_sbeCommAddr,
                  i_sbeCommSize);

        // Create command and response structures
        SbePsu::psuCommand l_psuCommand(
                           SbePsu::SBE_REQUIRE_RESPONSE,  //control flags
                           SbePsu::SBE_PSU_GENERIC_MESSAGE, //command class
                           SbePsu::SBE_PSU_SET_FFDC_ADDRESS); //command
        SbePsu::psuResponse l_psuResponse;

        // Fill in PSU Command with Set FFDC Address information
        l_psuCommand.cd7_setFFDCAddr_FFDCSize = i_sbeffdcSize;
        l_psuCommand.cd7_setFFDCAddr_CommSize = i_sbeCommSize;
        l_psuCommand.cd7_setFFDCAddr_FFDCAddr = i_sbeffdcAddr;
        l_psuCommand.cd7_setFFDCAddr_CommAddr = i_sbeCommAddr;

        // Call performPsuChipOp, tell SBE where to write FFDC and messages
        errl =  SBEIO::SbePsu::getTheInstance().performPsuChipOp(i_procChip,
                                &l_psuCommand,
                                &l_psuResponse,
                                SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                                SbePsu::SBE_SET_FFDC_ADDR_REQ_USED_REGS,
                                SbePsu::SBE_SET_FFDC_ADDR_RSP_USED_REGS);

        SBE_TRACD(EXIT_MRK "sendSetFFDCAddr");

        return errl;
    };

} //end namespace SBEIO
