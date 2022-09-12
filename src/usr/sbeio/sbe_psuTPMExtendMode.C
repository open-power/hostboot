/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuTPMExtendMode.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
* @file sbe_psuTPMExtendMode.C
* @brief Enter and exit the TPM extend mode via the SBE.
*/

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>
#include <targeting/common/targetservice.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio, printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio, printf_string,##args)

namespace SBEIO
{

    /**
    * @brief Send the TPM Extend Mode command to the SBE with Enter ctrl flag
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t psuTPMExtendModeEnter()
    {
        errlHndl_t errl = nullptr;

        do {

        TARGETING::TargetService& tS = TARGETING::targetService();
        TARGETING::Target * l_tgt = nullptr;

        errl = tS.queryMasterProcChipTargetHandle(l_tgt);
        if (errl)
        {
            SBE_TRACF(ERR_MRK
                "psuTPMExtendModeEnter: Failed to get boot Proc: err rc=0x%.4X plid=0x%.8X",
                ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

            break;
        }

        const uint32_t l_ctrlFlags = SbePsu::SBE_TPM_EXTEND_MODE_ENTER |
                               SbePsu::SBE_TPM_EXTEND_MODE_RESPONSE_REQUIRED;
        const uint32_t l_waitTimerMS = 10500;
        // Due to SBE protocol limitation, the wait timer cannot exceed 10500
        // or it will wrap around in the SBE
        static_assert(l_waitTimerMS <= 10500,
                      "psuTPMExtendModeEnter waitTimerMS > 10500");

        SBE_TRACF(ENTER_MRK
            "psuTPMExtendModeEnter: sending TPM Extend Mode from HB -> SBE ctrlFlags=0x%x waitTimerMS=%d on Proc 0x%x",
            l_ctrlFlags, l_waitTimerMS,
            l_tgt->getAttr<TARGETING::ATTR_POSITION>());

        SbePsu::psuCommand   l_psuCommand(
                        l_ctrlFlags,
                        SbePsu::SBE_PSU_CLASS_SECURITY_CONTROL, //command class
                        SbePsu::SBE_PSU_TPM_EXTEND_MODE_CMD); //command
        SbePsu::psuResponse  l_psuResponse;

        // set up PSU command message
        l_psuCommand.cd6_TPMExtendMode_WaitTimerMS = l_waitTimerMS;

        errl =  SBEIO::SbePsu::getTheInstance().performPsuChipOp(
            l_tgt,
            &l_psuCommand,
            &l_psuResponse,
            SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
            SbePsu::SBE_TPM_EXTEND_MODE_REQ_USED_REGS,
            SbePsu::SBE_TPM_EXTEND_MODE_RSP_USED_REGS);
        if (errl)
        {
            SBE_TRACF(ERR_MRK
                "psuTPMExtendModeEnter: PSU Cmd Failed: err rc=0x%.4X plid=0x%.8X",
                ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
            errl->collectTrace(SBEIO_COMP_NAME, SBEIO_COMP_ID);

            break;
        }

        } while(0);

        SBE_TRACF(EXIT_MRK "psuTPMExtendModeEnter (PLID=0x%08x)",
                  ERRL_GETPLID_SAFE(errl));

        return errl;
    };

    /**
    * @brief Send the TPM Extend Mode command to the SBE with Exit ctrl flag
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t psuTPMExtendModeExit()
    {
        errlHndl_t errl = nullptr;

        do {

        TARGETING::TargetService& tS = TARGETING::targetService();
        TARGETING::Target * l_tgt = nullptr;

        errl = tS.queryMasterProcChipTargetHandle(l_tgt);
        if (errl)
        {
            SBE_TRACF(ERR_MRK
                "psuTPMExtendModeExit: Failed to get boot Proc: err rc=0x%.4X plid=0x%.8X",
                ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

            break;
        }

        const uint32_t l_ctrlFlags = SbePsu::SBE_TPM_EXTEND_MODE_EXIT |
                               SbePsu::SBE_TPM_EXTEND_MODE_RESPONSE_REQUIRED;
        const uint32_t l_waitTimerMS = 0;

        SBE_TRACF(ENTER_MRK
            "psuTPMExtendModeExit: sending TPM Extend Mode from HB -> SBE ctrlFlags=0x%x waitTimerMS(unused)=%d on Proc 0x%x",
            l_ctrlFlags, l_waitTimerMS,
            l_tgt->getAttr<TARGETING::ATTR_POSITION>());

        SbePsu::psuCommand   l_psuCommand(
                        l_ctrlFlags,
                        SbePsu::SBE_PSU_CLASS_SECURITY_CONTROL, //command class
                        SbePsu::SBE_PSU_TPM_EXTEND_MODE_CMD); //command
        SbePsu::psuResponse  l_psuResponse;

        // set up PSU command message
        l_psuCommand.cd6_TPMExtendMode_WaitTimerMS = l_waitTimerMS;

        errl =  SBEIO::SbePsu::getTheInstance().performPsuChipOp(
            l_tgt,
            &l_psuCommand,
            &l_psuResponse,
            SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
            SbePsu::SBE_TPM_EXTEND_MODE_REQ_USED_REGS,
            SbePsu::SBE_TPM_EXTEND_MODE_RSP_USED_REGS);
        if (errl)
        {
            SBE_TRACF(ERR_MRK
                "psuTPMExtendModeExit: PSU Cmd Failed: err rc=0x%.4X plid=0x%.8X",
                ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
            errl->collectTrace(SBEIO_COMP_NAME, SBEIO_COMP_ID);

            break;
        }

        } while(0);

        SBE_TRACF(EXIT_MRK "psuTPMExtendModeExit (PLID=0x%08x)",
                  ERRL_GETPLID_SAFE(errl));

        return errl;
    };

} //end namespace SBEIO
