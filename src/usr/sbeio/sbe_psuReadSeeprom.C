/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuReadSeeprom.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
* @file sbe_psuReadSeeprom.C
* @brief Send command to request Seeprom read on SBE
*/

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"psuReadSeeprom: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"psuReadSeeprom: " printf_string,##args)

namespace SBEIO
{

    /**
    * @brief Sends a PSU chipOp to request Seeprom read from SBE
    *
    * @param[in]  i_target         Target with SBE to send read request to
    * @param[in]  i_seepromOffset  Offset in the seeprom image where we want
    *                              to start copying from (ignores ECC)
    * @param[in]  i_readSize       Amount of bytes we want to copy (ignores ECC)
    * @param[in]  i_destAddr       Address that hostboot has prepared which the
    *                              sbe will write too
    * @param[out] o_opSupported    Bool which tells us if the sbe supports the
    *                              chipOp or not
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuReadSeeprom(TARGETING::Target * i_target,
                                  uint32_t i_seepromOffset,
                                  uint32_t i_readSize,
                                  uint64_t i_destAddr,
                                  bool   & o_opSupported)
    {
        errlHndl_t errl = nullptr;

        SBE_TRACD(ENTER_MRK "sending psu seeprom read request command from HB -> SBE");

        // set up PSU command message
        SbePsu::psuCommand   l_psuCommand(
                                  SbePsu::SBE_REQUIRE_RESPONSE |
                                  SbePsu::SBE_REQUIRE_ACK,         //control flags
                                  SbePsu::SBE_PSU_GENERIC_MESSAGE, //command class
                                  SbePsu::SBE_PSU_READ_SEEPROM);   //command
        SbePsu::psuResponse  l_psuResponse;

        l_psuCommand.cd7_readSeeprom_SeepromOffset   = i_seepromOffset;
        l_psuCommand.cd7_readSeeprom_ReadSize        = i_readSize;
        l_psuCommand.cd7_readSeeprom_DestinationAddr = i_destAddr;


        errl =  SBEIO::SbePsu::getTheInstance().performPsuChipOp(i_target,
                                &l_psuCommand,
                                &l_psuResponse,
                                SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                                SbePsu::SBE_READ_SEEPROM_REQ_USED_REGS,
                                SbePsu::SBE_READ_SEEPROM_RSP_USED_REGS);

        if(l_psuResponse.primaryStatus == SBE_PRI_INVALID_COMMAND &&
            l_psuResponse.secondaryStatus == SBE_SEC_COMMAND_NOT_SUPPORTED)
        {
            SBE_TRACF(ENTER_MRK "SBE firmware level does not support PSU Seeprom Read Requests");
            //Make sure we aren't passing out any errors if the command isn't supported
            delete errl;
            errl = nullptr;
            o_opSupported = false;
        }

        SBE_TRACD(EXIT_MRK "sendPsuReadSeeprom");

        return errl;
    };

} //end namespace SBEIO

