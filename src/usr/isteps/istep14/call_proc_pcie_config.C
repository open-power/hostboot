/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_proc_pcie_config.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//HWP Invoker
#include    <fapi2/plat_hwp_invoker.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <fapi2/target.H>

#include <p9_pcie_config.H>


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{

/******************************************************************
* compareChipUnits
*
* Check if chip unit of l_t1 > l_t2
*
*******************************************************************/
bool compareChipUnits(TARGETING::Target *l_t1,
                      TARGETING::Target *l_t2)
{
    bool l_result = false;
    assert((l_t1 != NULL) && (l_t2 != NULL));

    l_result = l_t1->getAttr<TARGETING::ATTR_CHIP_UNIT>() >
               l_t2->getAttr<TARGETING::ATTR_CHIP_UNIT>();

    return l_result;
}


/******************************************************************
* setup_pcie_iovalid_enable
*
* Setup ATTR_PROC_PCIE_IOVALID_ENABLE on i_procTarget's PEC children
*
*******************************************************************/
void setup_pcie_iovalid_enable(const TARGETING::Target * i_procTarget)
{
    // Get list of PEC chiplets downstream from the given proc chip
    TARGETING::TargetHandleList l_pecList;

    getChildAffinityTargetsByState( l_pecList,
                          i_procTarget,
                          TARGETING::CLASS_NA,
                          TARGETING::TYPE_PEC,
                          TARGETING::UTIL_FILTER_ALL);

    for (auto l_pecTarget : l_pecList)
    {
        // Get list of PHB chiplets downstream from the given PEC chiplet
        TARGETING::TargetHandleList l_phbList;

        getChildAffinityTargetsByState( l_phbList,
                          const_cast<TARGETING::Target*>(l_pecTarget),
                          TARGETING::CLASS_NA,
                          TARGETING::TYPE_PHB,
                          TARGETING::UTIL_FILTER_ALL);


        // default to all invalid
        ATTR_PROC_PCIE_IOVALID_ENABLE_type l_iovalid = 0;

        // arrange phb targets from largest to smallest based on unit
        // ex.  PHB5, PHB4, PHB3
        std::sort(l_phbList.begin(),l_phbList.end(),compareChipUnits);
        for(uint32_t k = 0; k<l_phbList.size(); ++k)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PHB>
                l_fapi_phb_target(l_phbList[k]);

            if(l_fapi_phb_target.isFunctional())
            {
                TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "PHB%d functional",
                    (l_phbList[k])->getAttr<TARGETING::ATTR_CHIP_UNIT>());

                // filled in bitwise,
                // largest PHB unit on the right to smallest leftword
                // ex. l_iovalid = 0b00000110 : PHB3, PHB4 functional, PHB5 not
                l_iovalid |= (1<<k);
            }
            else
            {
                TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "PHB%d not functional",
                    (l_phbList[k])->getAttr<TARGETING::ATTR_CHIP_UNIT>());
            }
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "PROC %.8X PEC%d -> ATTR_PROC_PCIE_IOVALID_ENABLE: 0x%02X",
                TARGETING::get_huid(i_procTarget),
                l_pecTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                l_iovalid);

        l_pecTarget->setAttr<TARGETING::ATTR_PROC_PCIE_IOVALID_ENABLE>(l_iovalid);
    }
}

void* call_proc_pcie_config (void *io_pArgs)
{
    errlHndl_t  l_errl  =   NULL;

    IStepError  l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_pcie_config entry" );

    TARGETING::TargetHandleList l_procChips;
    getAllChips(l_procChips, TYPE_PROC );

    for (const auto & l_procChip: l_procChips)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi_cpu_target(l_procChip);
        //  write HUID of target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_procChip));

        // setup ATTR_PROC_PCIE_IOINVALID_ENABLE for this processor
        setup_pcie_iovalid_enable(l_procChip);

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl, p9_pcie_config, l_fapi_cpu_target );

        if ( l_errl )
        {
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_procChip).addToLog( l_errl );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : proc_pcie_config" );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : proc_pcie_config" );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_pcie_config exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
