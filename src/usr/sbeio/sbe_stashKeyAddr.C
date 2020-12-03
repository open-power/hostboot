/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_stashKeyAddr.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
* @file sbe_stashKeyAddr.C
* @brief Send command to stash key-value pair in the SBE
*/

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"psuStashKeyAddr: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"psuStashKeyAddr: " printf_string,##args)

namespace SBEIO
{

    /**
    * @brief Sends a PSU chipOp to stash a key-address pair in the SBE
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuStashKeyAddrRequest(const uint8_t i_key,
                                          const uint64_t i_value,
                                          TARGETING::Target * i_procChip)
    {
        errlHndl_t errl = NULL;

        SBE_TRACD(ENTER_MRK "sending psu stashKeyAddr request from HB to SBE on proc %d",
                    i_procChip->getAttr<TARGETING::ATTR_POSITION>());

        // set up PSU command message
        SbePsu::psuCommand   l_psuCommand(
                                  SbePsu::SBE_REQUIRE_RESPONSE |
                                  SbePsu::SBE_REQUIRE_ACK, //control flags
                                  SbePsu::SBE_PSU_GENERIC_MESSAGE, //command class
                                  SbePsu::SBE_PSU_MSG_STASH_KEY_ADDR); //command
        SbePsu::psuResponse  l_psuResponse;

        l_psuCommand.cd7_stashKeyAddr_Key = i_key;
        l_psuCommand.cd7_stashKeyAddr_Value = i_value;

        bool command_unsupported = false;

        errl =  SBEIO::SbePsu::getTheInstance().performPsuChipOp(
            i_procChip,
            &l_psuCommand,
            &l_psuResponse,
            SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
            SbePsu::SBE_STASH_KEY_ADDR_REQ_USED_REGS,
            SbePsu::SBE_STASH_KEY_ADDR_RSP_USED_REGS,
            SbePsu::unsupported_command_error_severity { ERRORLOG::ERRL_SEV_INFORMATIONAL },
            &command_unsupported);

        if (command_unsupported)
        { // Traces are already logged
            errlCommit(errl, SBEIO_COMP_ID);
        }
        else if (errl)
        {
            if (l_psuResponse.secondaryStatus == SBE_SEC_INPUT_BUFFER_OVERFLOW)
            {
                SBE_TRACF(ERR_MRK"sendPsuStashKeyAddrRequest: Input buffer overflow, we are "
                          "attempting to stash too many pairs");
            }

            SBE_TRACF(ERR_MRK "sendPsuStashKeyAddrRequest: PSU Cmd Failed: "
                      "err rc=0x%.4X plid=0x%.8X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

            errl->collectTrace(SBEIO_COMP_NAME);
        }

        SBE_TRACD(EXIT_MRK "stashKeyAddr");

        return errl;
    };

} //end namespace SBEIO
