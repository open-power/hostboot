/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/hwpThreadHelper.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2023                        */
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
#ifndef __ISTEPS_HWPTHREADHELPER_H
#define __ISTEPS_HWPTHREADHELPER_H

/**
 * @file    hwpThreadHelper.H
 *  Contains semi-generic definitions to run a HWP-based istep in parallel
 */

#include <hwpThread.H>

/**
 * @brief SUB-HWP Invoker macro
 *
 * This macro is called by HostBoot code to invoke a HW Procedure (HWP), does
 * the trace before the HWP call, and does the check errl/trace after the HWP.
 * The caller must ensure a goto label called ERROR_EXIT exists.
 *
 * CALLER     - function name of the caller
 * ERRL       - local errlHndl_t
 * TARGET     - Target to execute HWP against
 * FUNC       - HWP function name
 * _args_...  - Any additional arguments that the HWP requires
 */
#define RUN_SUB_HWP(CALLER, ERRL, TARGET, FUNC, _args_...) \
  TRACFCOMP(g_trac_isteps_trace, \
            #CALLER ": run " #FUNC " on target HUID 0x%.8X", get_huid(TARGET)); \
  FAPI_INVOKE_HWP(ERRL, FUNC, ##_args_); \
  if (ERRL) \
  { \
      TRACFCOMP(g_trac_isteps_trace, \
                ERR_MRK #CALLER ": " #FUNC " on target HUID 0x%.8X", get_huid(TARGET)); \
      goto ERROR_EXIT; \
  }

/**
 * @brief SUB-ChipOp Invoker macro
 *
 * This macro is called by HostBoot code to invoke a ChipOp, does
 * the trace before the ChipOp call, and does the check errl/trace after the ChipOp.
 * The caller must ensure a goto label called ERROR_EXIT exists.
 *
 * CALLER     - function name of the caller
 * ERRL       - local errlHndl_t
 * TARGET     - Target to execute HWP against
 * OP         - ChipOp to execute
 */
#define RUN_SUB_CHIPOP(CALLER, ERRL, TARGET, OP) \
  TRACFCOMP(g_trac_isteps_trace, \
            #CALLER ": run " #OP " on target HUID 0x%.8X", get_huid(TARGET)); \
  ERRL = sendExecHWPRequest(TARGET, OP); \
  if (ERRL) \
  { \
      TRACFCOMP(g_trac_isteps_trace, \
                ERR_MRK #CALLER ": " #OP " on target HUID 0x%.8X", get_huid(TARGET)); \
      goto ERROR_EXIT; \
  }

namespace ISTEP
{

/*******************************************************************************
 * @brief Base work item class for running a HWP-based istep in parallel, where
 *        captureErrorOcmbUpdateCheck is called if there is a hwp failure.
 */
class HwpWorkItem_OCMBUpdateCheck : public HwpWorkItem
{
  public:
    /**
     * @brief ctor
     *
     * @param[in] i_stepError  Error accumulator for this istep
     * @param[in] i_target  Target to execute HWP against
     * @param[in] i_hwpName  Name of HWP being executed
     */
    HwpWorkItem_OCMBUpdateCheck( ISTEP_ERROR::IStepError& i_stepError,
                                   TARGETING::Target&     i_target,
                                          const char*     i_hwpName ) :
        HwpWorkItem(i_stepError, i_target, i_hwpName) {};

    /**
     * @brief Executes if the HWP returns an error
     *
     * @param[in] i_err  Error returned from FAPI_INVOKE_HWP
     */
    virtual void run_after_failure( errlHndl_t& i_err ) override
    {
        const auto lock = scoped_mutex_lock(cv_stepErrorMutex);

        cv_encounteredHwpError = true;

        // Capture error if there is no update needed,
        //  otherwise mark the part for an update
        captureErrorOcmbUpdateCheck(i_err, *iv_pStepError, HWPF_COMP_ID, iv_pTarget);
    };
};

}; //namespace ISTEP

#endif //__ISTEPS_HWPTHREADHELPER_H
