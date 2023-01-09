/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_io_run_training.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
 * @file    call_omi_io_run_training.C
 *
 *  Contains the HWP wrapper for Istep 12.7
 *      exp_omi_train
 *      p10_omi_train
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>        // captureError
#include    <hwpThread.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <exp_omi_train.H>
#include    <p10_omi_train.H>
#include    <chipids.H>                 // for EXPLORER ID

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ERRORLOG;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{

class WorkItem_p10_omi_train: public ISTEP::HwpWorkItem
{
  public:
    WorkItem_p10_omi_train( IStepError& i_stepError,
                           const Target& i_omic )
    : HwpWorkItem( i_stepError, i_omic, "p10_omi_train" ) {}

    virtual errlHndl_t run_hwp( void )
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OMIC> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, p10_omi_train, l_fapi_target);
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
bool WorkItem_p10_omi_train::cv_encounteredHwpError = false;


class WorkItem_exp_omi_train: public ISTEP::HwpWorkItem
{
  public:
    WorkItem_exp_omi_train( IStepError& i_stepError,
                           const Target& i_ocmb )
    : HwpWorkItem( i_stepError, i_ocmb, "exp_omi_train" ) {}

    virtual errlHndl_t run_hwp( void )
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, exp_omi_train, l_fapi_target);
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
bool WorkItem_exp_omi_train::cv_encounteredHwpError = false;


void* call_omi_io_run_training (void *io_pArgs)
{
    IStepError l_StepError;
    TRACFCOMP( g_trac_isteps_trace, "call_omi_io_run_training entry" );
    Util::ThreadPool<ISTEP::HwpWorkItem> threadpool;

    do
    {
        // Starting beginning at this istep, we may be unable to scom the OCMBs
        // until the next istep is complete, except in certain cases where the
        // hardware procedure fails. Set ATTR_ATTN_POLL_PLID so ATTN knows to
        // poll the PRD_HWP_PLID before scomming the OCMBs.
        TargetHandle_t sys = nullptr;
        targetService().getTopLevelTarget(sys);
        assert(sys != nullptr);
        sys->setAttr<ATTR_ATTN_POLL_PLID>(1);


        // 12.7.a exp_omi_train.C
        TargetHandleList l_ocmbTargetList;
        getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

        for (const auto & l_ocmb_target : l_ocmbTargetList)
        {
            //  call the HWP with each target
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
                (l_ocmb_target);

            // Only run exp_omi_train on EXPLORER OCMB targets.
            uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();
            if (chipId == POWER_CHIPID::EXPLORER_16)
            {
                //  Create a new workitem from this omic and feed it to the
                //  thread pool for processing.  Thread pool handles workitem
                //  cleanup.
                threadpool.insert(new WorkItem_exp_omi_train(l_StepError,
                                                             *l_ocmb_target));
            }
            else
            {
                // Skip exp_omi_train call on non-Explorer chips
                TRACFCOMP( g_trac_isteps_trace,
                    "Skipping exp_omi_train HWP on target HUID 0x%.8X, "
                    "chipId 0x%.4X",
                    get_huid(l_ocmb_target), chipId );
            }
        }

        // Start the threads and wait for completion
        if( ISTEP::HwpWorkItem::start_threads( threadpool,
                                               l_StepError,
                                               l_ocmbTargetList.size() ) )
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"call_omi_io_run_training: start_threads returned an error for exp_omi_train" );
            break;
        }

        // Do not continue if an error was encountered
        if(WorkItem_exp_omi_train::cv_encounteredHwpError)
        {
            TRACFCOMP( g_trac_isteps_trace,
                INFO_MRK "call_omi_io_run_training exited early because exp_omi_train had failures");
            break;
        }


        // 12.7.b p10_omi_train.C
        TargetHandleList l_omicTargetList;
        getAllChiplets(l_omicTargetList, TYPE_OMIC);

        for (const auto & l_omic_target : l_omicTargetList)
        {
            //  Create a new workitem from this omic and feed it to the
            //  thread pool for processing.  Thread pool handles workitem
            //  cleanup.
            threadpool.insert(new WorkItem_p10_omi_train(l_StepError,
                                                         *l_omic_target));
        }

        // Start the threads and wait for completion
        if( ISTEP::HwpWorkItem::start_threads( threadpool,
                                               l_StepError,
                                               l_omicTargetList.size() ) )
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"call_omi_io_run_training: start_threads returned an error for p10_omi_train" );
            break;
        }

    } while (0);

    TRACFCOMP( g_trac_isteps_trace, "call_omi_io_run_training exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
