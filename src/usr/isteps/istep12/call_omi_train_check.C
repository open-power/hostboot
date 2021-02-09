/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_train_check.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 * @file    call_omi_train_check.C
 *
 *  Contains the HWP wrapper for Istep 12.8
 *      exp_omi_train_check
 *      p10_omi_train_check
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>    // captureError
#include    <hwpThread.H>

#include    <util/misc.H>           // isSimicsRunning()

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <p10_omi_train_check.H>
#include    <exp_omi_train_check.H>
#include    <chipids.H>             // for EXPLORER ID

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{

class WorkItem_exp_omi_train_check: public ISTEP::HwpWorkItem
{
  public:
    WorkItem_exp_omi_train_check( IStepError& i_stepError,
                                  const Target& i_ocmb )
    : HwpWorkItem( i_stepError, i_ocmb, "exp_omi_train_check" ) {}

    virtual errlHndl_t run_hwp( void )
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, exp_omi_train_check, l_fapi_target);
        return l_err;
    }

    /**
     * @brief Executes if the HWP returns an error
     *   Extended in order to check for missing OCMB FW updates
     *
     * @param[in] i_err  Error returned from FAPI_INVOKE_HWP
     */
    virtual void run_after_failure( errlHndl_t& i_err )
    {
        // Capture error if there is no update needed, otherwise mark
        //  the part for an update
        captureErrorOcmbUpdateCheck(i_err, *iv_pStepError,
                                    HWPF_COMP_ID, iv_pTarget);
        cv_encounteredHwpError = true;
    };

    // Remember that we hit a HWP failure.  We can't rely on IStepError because
    //  logs might have been committed informational in the case where the OCMB
    //  is downlevel.
    static bool cv_encounteredHwpError;
};
bool WorkItem_exp_omi_train_check::cv_encounteredHwpError = false;


class WorkItem_p10_omi_train_check: public ISTEP::HwpWorkItem
{
  public:
    WorkItem_p10_omi_train_check( IStepError& i_stepError,
                                  const Target& i_omi )
    : HwpWorkItem( i_stepError, i_omi, "p10_omi_train_check" ) {}

    virtual errlHndl_t run_hwp( void )
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OMI> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, p10_omi_train_check, l_fapi_target);
        return l_err;
    }

    /**
     * @brief Executes if the HWP returns an error
     *   Extended in order to check for missing omi FW updates
     *
     * @param[in] i_err  Error returned from FAPI_INVOKE_HWP
     */
    virtual void run_after_failure( errlHndl_t& i_err )
    {
        // Capture error if there is no update needed, otherwise mark
        //  the part for an update
        captureErrorOcmbUpdateCheck(i_err, *iv_pStepError,
                                    HWPF_COMP_ID, iv_pTarget);
        cv_encounteredHwpError = true;
    };

    // Remember that we hit a HWP failure.  We can't rely on IStepError because
    //  logs might have been committed informational in the case where the omi
    //  is downlevel.
    static bool cv_encounteredHwpError;
};
bool WorkItem_p10_omi_train_check::cv_encounteredHwpError = false;


void* call_omi_train_check (void *io_pArgs)
{
    IStepError l_StepError;
    Util::ThreadPool<ISTEP::HwpWorkItem> threadpool;

    TRACFCOMP( g_trac_isteps_trace, "call_omi_train_check entry");

    do
    {
        // 12.8.a exp_omi_train_check.C
        //        - Check for training errors

        // Find functional ocmb targets
        TargetHandleList l_OcmbChipList;
        getAllChips(l_OcmbChipList, TYPE_OCMB_CHIP, true);
        size_t l_numWorkitems = 0;

        for (auto & l_ocmb: l_OcmbChipList)
        {
            // Only run exp_omi_train_check on EXPLORER OCMB targets.
            uint32_t chipId = l_ocmb->getAttr<ATTR_CHIP_ID>();
            if (chipId == POWER_CHIPID::EXPLORER_16)
            {
                //  Create a new workitem from this ocmb and feed it to the
                //  thread pool for processing.  Thread pool handles workitem
                //  cleanup.
                threadpool.insert(new WorkItem_exp_omi_train_check(l_StepError,
                                                                   *l_ocmb));
                l_numWorkitems++;
            }
            else
            {
                // Not an Explorer, just skip exp_omi_train_check call
                TRACFCOMP( g_trac_isteps_trace,
                    "Skipping exp_omi_train_check HWP because target "
                    "HUID 0x%.8X, chipId 0x%.4X is not an Explorer OCMB",
                    get_huid(l_ocmb), chipId );
            }
        } // OCMB loop

        // Start the threads and wait for completion
        if( ISTEP::HwpWorkItem::start_threads( threadpool,
                                               l_StepError,
                                               l_numWorkitems ) )
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"call_omi_train_check: start_threads returned an error for exp_omi_train_check" );
            break;
        }

        // Do not continue if an error was encountered
        if(WorkItem_p10_omi_train_check::cv_encounteredHwpError)
        {
            TRACFCOMP( g_trac_isteps_trace,
                INFO_MRK "call_omi_train_check exited early because p10_omi_train_check "
                "had failures");
            break;
        }


        // 12.8.b p10_omi_train_check.C
        //        - Check for training errors

        // Find omi targets
        TargetHandleList l_omiTargetList;
        getAllChiplets(l_omiTargetList, TYPE_OMI);

        for (const auto & l_omi_target : l_omiTargetList)
        {
            //  Create a new workitem from this ocmb and feed it to the
            //  thread pool for processing.  Thread pool handles workitem
            //  cleanup.
            threadpool.insert(new WorkItem_p10_omi_train_check(l_StepError,
                                                               *l_omi_target));
        } // OMI loop

        // Start the threads and wait for completion
        if( ISTEP::HwpWorkItem::start_threads( threadpool,
                                               l_StepError,
                                               l_omiTargetList.size() ) )
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"call_omi_train_check: start_threads returned an error for p10_omi_train_check" );
            break;
        }
    } while (0);

    // Beyond this point, scoms to the OCMBs should be working, so clear the
    // ATTR_ATTN_POLL_PLID attribute since attention won't need to check the
    // PRD_HWP_PLID attribute before scomming the OCMBs anymore.
    TargetHandle_t sys = nullptr;
    targetService().getTopLevelTarget(sys);
    assert(sys != nullptr);
    sys->setAttr<ATTR_ATTN_POLL_PLID>(0);

    TRACFCOMP( g_trac_isteps_trace, "call_omi_train_check exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
