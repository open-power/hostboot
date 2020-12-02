/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuReadSeeprom.C $                          */
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
* @file sbe_psuReadSeeprom.C
* @brief Send command to request Seeprom read on SBE
*/

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"psuReadSeeprom: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"psuReadSeeprom: " printf_string,##args)

#define READ_SEEPROM_SIZE_ALIGNMENT_BYTES 128
#define READ_SEEPROM_DEST_ADDR_ALIGNMENT_BYTES 8


namespace SBEIO
{

    /**
    * @brief Sends a PSU chipOp to request Seeprom read from SBE
    *
    * @note - details in sbeioif.H
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuReadSeeprom(TARGETING::Target * i_target,
                                  uint32_t i_seepromOffset,
                                  uint32_t i_readSize,
                                  uint64_t i_destAddr)
    {
        errlHndl_t errl = nullptr;

        SBE_TRACD(ENTER_MRK "sending psu seeprom read request command from HB -> SBE");

        // Verify input parameters meet restrictions
        assert(i_target!=nullptr,"sendPsuReadSeeprom: i_target was nullptr");
        assert((i_readSize % CHIPOP_READ_SEEPROM_SIZE_ALIGNMENT_BYTES) == 0,"sendPsuReadSeeprom: i_readSize 0x%X is not 128B aligned", i_readSize);
        assert((i_destAddr % CHIPOP_READ_SEEPROM_DEST_ADDR_ALIGNMENT_BYTES) == 0,"sendPsuReadSeeprom: i_destAddr 0x%.16llX is not 8B aligned", i_destAddr);

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

        SBE_TRACD(EXIT_MRK "sendPsuReadSeeprom");

        return errl;
    };

} //end namespace SBEIO

