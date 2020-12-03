/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuQuiesce.C $                              */
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
* @file sbe_psuQuiesce.C
* @brief Send command to quiesce the SBE
*/

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>
#include <sbeio/sbeioreasoncodes.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"psuQuiesce: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"psuQuiesce: " printf_string,##args)

namespace SBEIO
{
    errlHndl_t sendPsuQuiesceSbe(TARGETING::Target* i_pProc)
    {
        errlHndl_t pError = nullptr;

        SBE_TRACD(ENTER_MRK "sending psu quiesce command from HB -> SBE");

        do {

        if(   (i_pProc == nullptr)
           || (   i_pProc->getAttr<TARGETING::ATTR_TYPE>()
               != TARGETING::TYPE_PROC))
        {
            /*@
             * @errortype
             * @moduleid   SBEIO_SEND_PSU_QUIESCE_SBE
             * @reasoncode SBEIO_PSU_INVALID_TARGET
             * @userdata1  Target HUID (0, if invalid pointer)
             * @userdata2  Target type (TYPE_NA, if invalid pointer)
             * @devdesc    Caller requested PSU quiesce against an unassigned
             *     target or a target that is not a processor.
             * @custdesc   Firmware logic bug detected
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SBEIO_SEND_PSU_QUIESCE_SBE,
                SBEIO_PSU_INVALID_TARGET,
                TARGETING::get_huid(i_pProc),
                i_pProc ? i_pProc->getAttr<TARGETING::ATTR_TYPE>() : 0,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            pError->collectTrace(SBEIO_COMP_NAME);
            break;
        }

        // set up PSU command message
        SbePsu::psuCommand   l_psuCommand(
                                  SbePsu::SBE_REQUIRE_RESPONSE,  //control flags
                                  SbePsu::SBE_PSU_GENERIC_MESSAGE, //command class
                                  SbePsu::SBE_PSU_GENERIC_MSG_QUIESCE); //command
        SbePsu::psuResponse  l_psuResponse;


        pError =  SBEIO::SbePsu::getTheInstance().performPsuChipOp(
            i_pProc,
            &l_psuCommand,
            &l_psuResponse,
            SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
            SbePsu::SBE_QUIESCE_REQ_USED_REGS,
            SbePsu::SBE_QUIESCE_RSP_USED_REGS,
            SbePsu::unsupported_command_error_severity { ERRORLOG::ERRL_SEV_UNRECOVERABLE });

        // Regardless of whether the operation was successful, assume it
        // was, in order to suppress future SBE activity like shutdown
        // attribute synchronization.
        i_pProc->setAttr<TARGETING::ATTR_ASSUME_SBE_QUIESCED>(true);

        } while(0);

        SBE_TRACD(EXIT_MRK "sendPsuQuiesceSbe");

        return pError;
    };

} //end namespace SBEIO
