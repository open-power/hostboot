/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_securityListBinDump.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
* @file sbe_securityListBinDump.C
* @brief Send command to SBE to fetch the Security List Binary Dump
*        for the whitelist/blacklist algorithm.
*/

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"psuSecurityListBinDump: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"psuSecurityBinListDump: " printf_string,##args)

namespace SBEIO
{

    /**
    * @brief Sends a PSU chipOp to fetch security list binary dump in the SBE
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuSecurityListBinDumpRequest(const uint64_t i_addr,
                                                 TARGETING::Target * i_procChip)
    {
        errlHndl_t errl = nullptr;

        assert(i_procChip != nullptr,
               "SbePsu::SecurityBinlistDumpRequest: i_procChip is null");

        SBE_TRACD(ENTER_MRK "sending psu securityListBinaryDump request from HB"
            " to SBE on proc %d", i_procChip->getAttr<TARGETING::ATTR_POSITION>());

        // set up PSU command message
        SbePsu::psuCommand   l_psuCommand(
                                  SbePsu::SBE_REQUIRE_RESPONSE |
                                  SbePsu::SBE_REQUIRE_ACK, //control flags
                                  SbePsu::SBE_PSU_GENERIC_MESSAGE, //command class
                                  SbePsu::SBE_PSU_SECURITY_LIST_BIN_DUMP); //command
        SbePsu::psuResponse  l_psuResponse;

        l_psuCommand.cd7_securityListBinDump_addr = i_addr;

        errl =  SBEIO::SbePsu::getTheInstance().performPsuChipOp(
            i_procChip,
            &l_psuCommand,
            &l_psuResponse,
            SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
            SbePsu::SBE_SECURITY_LIST_BIN_DUMP_REQ_USED_REGS,
            SbePsu::SBE_SECURITY_LIST_BIN_DUMP_RSP_USED_REGS,
            SbePsu::COMMAND_SUPPORT_OPTIONAL);

        if (errl)
        {
            SBE_TRACF(ERR_MRK "sendPsuSecurityBinDumpRequest: PSU Cmd Failed: "
                      "err rc=0x%.4X plid=0x%.8X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
        }

        SBE_TRACD(EXIT_MRK "sendPsuSecurityListBinDumpRequest");

        return errl;
    };

} //end namespace SBEIO
