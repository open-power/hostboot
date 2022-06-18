/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuSendCoreConfig.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
* @file sbe_psuSendCoreConfig.C
* @brief Send Core configuration information, for a PROC, to the SBE
*/

#include <errl/errlmanager.H>                  // errlHndl_t
#include <sbeio/sbe_psudd.H>                   // SbePsu::psuCommand
#include <targeting/common/commontargeting.H>  // get_huid
#include <targeting/common/utilFilter.H>       // getAllChips
#include <sbeio/sbeioreasoncodes.H>            // SBEIO_PSU, SBEIO_PSU_SEND
#include <sbeio/sbeioif.H>
#include <sys/mm.h>                            // mm_virt_to_phys
#include <errno.h>
#include <sbeio/sbe_utils.H>                   // SBE_PMIC_HLTH_CHECK_BUFFER_LEN_BYTES
#include <errl/errlreasoncodes.H>              // ERRL_UDT_NOFORMAT
#include <targeting/common/mfgFlagAccessors.H> // areAllSrcsTerminating

extern trace_desc_t* g_trac_sbeio;

namespace SBEIO
{
using namespace TARGETING;

 /** @brief Populate the PSU Command with Core target configuration info
 *          and send to the SBE
 *
 *  @param[in] i_pProc - The PROC target to extract the core config targets from
 *  @return nullptr if no error else an error log
 */
errlHndl_t psuSendSbeCoreConfig(const TargetHandle_t i_pProc)
{
    errlHndl_t l_err(nullptr);

    // Validate and verify that the target passed in is indeed a PROC
    assert( TYPE_PROC == i_pProc->getAttr<ATTR_TYPE>(),
            "psuSendSbeCoreConfig: Expected a target of type PROC but received a target of type 0x%.4X",
            i_pProc->getAttr<ATTR_TYPE>() );

    TRACFCOMP(g_trac_sbeio, ENTER_MRK"psuSendSbeCoreConfig: PROC target HUID 0x%X",
                            get_huid(i_pProc) );

    do
    {
        TargetHandleList l_func_cores;
        PredicatePostfixExpr l_checkExprFunctionalcore;
        PredicateCTM l_isCore(CLASS_UNIT, TYPE_CORE);
        PredicateHwas l_functional;
        l_functional.functional(true);
        l_checkExprFunctionalcore.push(&l_functional);
        l_checkExprFunctionalcore.push(&l_isCore).And();
        targetService().getAssociated(l_func_cores, i_pProc,
            TargetService::CHILD, TargetService::ALL,
            &l_checkExprFunctionalcore);
        uint64_t bitStringFuncCores = UTIL::targetListToBitString<ATTR_CHIP_UNIT>(l_func_cores, &l_checkExprFunctionalcore);
        bool command_unsupported =false;
        // Create a PSU command message and initialize it with Core Config specific flags
        SbePsu::psuCommand l_psuCommand(
                    SbePsu::SBE_REQUIRE_RESPONSE |
                    SbePsu::SBE_REQUIRE_ACK,           // control flags
                    SbePsu::SBE_PSU_CLASS_CORE_STATE,  // command class (0xD1)
                    SbePsu::SBE_CMD_CORE_CONFIG);      // command (0x03)

        // SBE wants b0=functional b1=non-functional (deconfigured/garded) to keep like definition
        // of scratch REG 1 so the code can be re-used when updating the core functional states
        // take complement BEFORE shifting bits
        l_psuCommand.cd7_sendCoreConfig_CoreMask = (~bitStringFuncCores) << 32;
        TRACFCOMP(g_trac_sbeio, "psuSendSbeCoreConfig CoreMask=0x%X", l_psuCommand.cd7_sendCoreConfig_CoreMask);

        // Create a PSU response message
        SbePsu::psuResponse l_psuResponse;

        // Make the call to perform the PSU Chip Operation
        l_err = SbePsu::getTheInstance().performPsuChipOp(
                        i_pProc,
                        &l_psuCommand,
                        &l_psuResponse,
                        SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                        SbePsu::SBE_CORE_CONFIG_REQ_USED_REGS,
                        SbePsu::SBE_CORE_CONFIG_RSP_USED_REGS,
                        SbePsu::unsupported_command_error_severity { ERRORLOG::ERRL_SEV_INFORMATIONAL },
                        &command_unsupported);
        if (command_unsupported)
        {
            TRACFCOMP(g_trac_sbeio, ERR_MRK"psuSendSbeCoreConfig: "
                       "Call to performPsuChipOp command unsupported, log and continue");
            errlCommit(l_err, SBEIO_COMP_ID);
        }
        else if (l_err)
        {
            // Traces have already been logged
            TRACFCOMP( g_trac_sbeio, ERR_MRK"psuSendSbeCoreConfig: ERROR: "
                       "Call to performPsuChipOp failed, error returned" );
        }
    } while (0);

    TRACFCOMP(g_trac_sbeio, EXIT_MRK "psuSendSbeCoreConfig");

    return l_err;
}; // psuSendSbeCoreConfig

} // namespace SBEIO
