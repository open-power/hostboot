/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_cen_ref_clk_enable.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
 *  @file call_proc_cen_ref_clk_enable.C
 *
 *  Support file for IStep: slave_sbe
 *   Slave SBE
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <sys/time.h>
#include <devicefw/userif.H>
#include <i2c/i2cif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>
#include <targeting/attrsync.H>

#include <isteps/hwpisteperror.H>

#include <errl/errludtarget.H>



const uint64_t MS_TO_WAIT_FIRST = 2500; //(2.5 s)
const uint64_t MS_TO_WAIT_OTHERS= 100; //(100 ms)

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_08
{

uint8_t getMembufsAttachedBitMask( TARGETING::Target * i_procChipHandle  );
void fenceAttachedMembufs( TARGETING::Target * i_procChipHandle  );

//******************************************************************************
// call_proc_cen_ref_clock_enable
//******************************************************************************
void* call_proc_cen_ref_clk_enable(void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_cen_ref_clock_enable enter" );

    TARGETING::TargetHandleList functionalProcChipList;

    getAllChips(functionalProcChipList, TYPE_PROC, true);

    // loop thru the list of processors
    for (TargetHandleList::const_iterator
            l_proc_iter = functionalProcChipList.begin();
            l_proc_iter != functionalProcChipList.end();
            ++l_proc_iter)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X",
                TARGETING::get_huid( *l_proc_iter ));

        uint8_t l_membufsAttached = 0;
        // get a bit mask of present/functional dimms assocated with
        // this processor
        l_membufsAttached = getMembufsAttachedBitMask( *l_proc_iter );

        //Perform a workaround for GA1 to raise fences on centaurs
        //to prevent FSP from analyzing if HB TIs for recoverable
        //errors
        //RTC 106276
        fenceAttachedMembufs( *l_proc_iter );

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "passing target HUID %.8X and 0x%x mask",
                TARGETING::get_huid( *l_proc_iter ), l_membufsAttached );

        if( l_membufsAttached )
        {

            /* @TODO RTC:134078 use fapi2 targets
            fapi::Target l_fapiProcTarget( fapi::TARGET_TYPE_PROC_CHIP,
                                       *l_proc_iter );
            */

            // Invoke the HWP passing in the proc target and
            // a bit mask indicating connected centaurs
            // Cumulus only
            //@TODO RTC:134078
            //FAPI_INVOKE_HWP(l_errl,
            //        p9_proc_cen_ref_clk_enable,
            //        l_fapiProcTarget, l_membufsAttached );

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR : proc_cen_ref_clk_enable",
                        "failed, returning errorlog" );

                // capture the target data in the elog
                ErrlUserDetailsTarget( *l_proc_iter ).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit error log
                errlCommit( l_errl, HWPF_COMP_ID );
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS : proc_cen_ref_clk_enable",
                        "completed ok");
            }
        }
    }   // endfor

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_cen_ref_clock_enable exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//******************************************************************************
// getMembufsAttachedBitMask - helper function for hwp proc_cen_ref_clk_enable
//******************************************************************************
uint8_t getMembufsAttachedBitMask( TARGETING::Target * i_procTarget  )
{
    const uint8_t MCS_WITH_ATTACHED_CENTAUR_MASK = 0x80;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Finding functional membuf chips downstream from "
            "proc chip with HUID of 0x%08X",
            i_procTarget->getAttr<TARGETING::ATTR_HUID>());

    uint8_t l_attachedMembufs = 0;

    // Get list of functional membuf chips downstream from the given
    // proc chip
    TARGETING::TargetHandleList functionalMembufChipList;

    getChildAffinityTargets( functionalMembufChipList,
                      const_cast<TARGETING::Target*>(i_procTarget ),
                      TARGETING::CLASS_CHIP,
                      TARGETING::TYPE_MEMBUF,
                      true);

    // loop through the functional membufs
    for(TARGETING::TargetHandleList::const_iterator pTargetItr
                            = functionalMembufChipList.begin();
                            pTargetItr != functionalMembufChipList.end();
                            pTargetItr++)
    {
        // Find each functional membuf chip's upstream functional MCS
        // unit, if any, and accumulate it into the attached membuf
        // chips mask
        TARGETING::TargetHandleList functionalMcsUnitList;

        getParentAffinityTargets( functionalMcsUnitList, *pTargetItr,
                                  TARGETING::CLASS_UNIT, TARGETING::TYPE_MCS,
                                  true );

        if(functionalMcsUnitList.empty())
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Functional membuf chip with HUID of 0x%08X "
                    "is not attached to an upstream functional MCS",
                    (*pTargetItr)->getAttr<
                    TARGETING::ATTR_HUID>());
            continue;
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Found functional MCS unit with HUID of 0x%08X "
                "upstream from functional membuf chip with HUID of 0x%08X",
                ((*functionalMcsUnitList.begin())->getAttr<
                 TARGETING::ATTR_CHIP_UNIT>()),
                (*pTargetItr)->getAttr<
                TARGETING::ATTR_HUID>());
        l_attachedMembufs |=
            ((MCS_WITH_ATTACHED_CENTAUR_MASK) >>
             ((*functionalMcsUnitList.begin())->getAttr<
              TARGETING::ATTR_CHIP_UNIT>()));
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Proc chip with HUID of 0x%08X has attached membuf "
            "mask (l_attachedMembufs) of 0x%02X",
            i_procTarget->getAttr<TARGETING::ATTR_HUID>(),
            l_attachedMembufs);

    // return the bitmask
    return l_attachedMembufs;

}

//******************************************************************************
// fenceAttachedMembufs - helper function for hwp proc_cen_ref_clk_enable
//******************************************************************************
void fenceAttachedMembufs( TARGETING::Target * i_procTarget  )
{
     errlHndl_t  l_errl = NULL;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Fencing attached (present) membuf chips downstream from "
            "proc chip with HUID of 0x%08X",
            i_procTarget->getAttr<TARGETING::ATTR_HUID>());


    // Get list of membuf chips downstream from the given proc chip
    TARGETING::TargetHandleList MembufChipList;

    getChildAffinityTargetsByState( MembufChipList,
                      const_cast<TARGETING::Target*>(i_procTarget ),
                      TARGETING::CLASS_CHIP,
                      TARGETING::TYPE_MEMBUF,
                      TARGETING::UTIL_FILTER_PRESENT);

    // loop through the membufs
    for(TARGETING::TargetHandleList::const_iterator pTargetItr
                            = MembufChipList.begin();
                            pTargetItr != MembufChipList.end();
                            pTargetItr++)
    {
        //Get CFAM "1012" -- FSI GP3 and set bits 23-27 (various fence bits)
        //Note 1012 is ecmd addressing, real address is 0x1048 (byte)
        uint64_t l_addr = 0x1048;
        const uint32_t l_fence_bits= 0x000001F0;
        uint32_t l_data = 0;
        size_t l_size = sizeof(uint32_t);
        l_errl = deviceRead(*pTargetItr,
                         &l_data,
                         l_size,
                         DEVICE_FSI_ADDRESS(l_addr));
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
             "Failed getcfam 1012 to HUID 0x%08X, ignoring, skipping",
             (*pTargetItr)->getAttr<TARGETING::ATTR_HUID>());
            delete l_errl;
            l_errl = NULL;
            continue;
        }

        l_data |= l_fence_bits;

        l_errl = deviceWrite(*pTargetItr,
                         &l_data,
                         l_size,
                         DEVICE_FSI_ADDRESS(l_addr));
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Failed putcfam 1012 to HUID 0x%08X, ignoring, skipping",
                      (*pTargetItr)->getAttr<TARGETING::ATTR_HUID>());
            delete l_errl;
            l_errl = NULL;
            continue;
        }
    }

}

}
