/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/hwpThreadHelper.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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

#include <utility>

#include <hwas/common/hwas.H>

#include <hwpThread.H>
#include <initservice/isteps_trace.H>

#include "ocmbupd_helpers.H"

/**
 * @brief SUB-HWP Invoker macro
 *
 * This macro is called by HostBoot code to invoke an Odyssey HW Procedure (HWP), does
 * the trace before the HWP call, and does the check errl/trace after the HWP.
 * The caller must ensure a goto label called ERROR_EXIT exists.
 *
 * CALLER     - function name of the caller
 * ISTEP_ERROR- The istep error being used
 * ERRL       - local errlHndl_t
 * TARGET     - Target to execute HWP against
 * FUNC       - HWP function name
 * _args_...  - Any additional arguments that the HWP requires
 */
#define RUN_ODY_HWP(CALLER, ISTEP_ERROR, ERRL, TARGET, FUNC, _args_...) \
    do                                                                  \
    {                                                                   \
        errlHndl_t& RUN_ODY_HWP_errl = ERRL;                            \
        TRACISTEP(#CALLER ": run " #FUNC " on target HUID 0x%.8X (host)", get_huid(TARGET)); \
        FAPI_INVOKE_HWP(RUN_ODY_HWP_errl, FUNC, ##_args_);              \
        if (RUN_ODY_HWP_errl)                                           \
        {                                                               \
            goto ERROR_EXIT;                                            \
        }                                                               \
        else                                                            \
        {                                                               \
            TRACISTEP(#CALLER ": SUCCESS running " #FUNC " hwp on target HUID 0x%.8X", \
                      get_huid(TARGET));                                \
        }                                                               \
    } while (false)

/**
 * @brief SUB-ChipOp Invoker macro
 *
 * This macro is called by HostBoot code to invoke an Odyssey ChipOp, does
 * the trace before the ChipOp call, and does the check errl/trace after the ChipOp.
 * The caller must ensure a goto label called ERROR_EXIT exists.
 *
 * CALLER     - function name of the caller
 * ISTEP_ERROR- The istep error being used
 * ERRL       - local errlHndl_t
 * TARGET     - Target to execute HWP against
 * OP         - ChipOp to execute
 */
#define RUN_ODY_CHIPOP(CALLER, ISTEP_ERROR, ERRL, TARGET, OP)           \
    do                                                                  \
    {                                                                   \
        errlHndl_t& RUN_ODY_CHIPOP_errl = ERRL;                         \
                                                                        \
        TRACISTEP(#CALLER ": run " #OP " on target HUID 0x%.8X (chipop)", get_huid(TARGET)); \
        RUN_ODY_CHIPOP_errl = sendExecHWPRequest(TARGET, OP);           \
        /* A chipop response may include logs orthogonal to the         \
           chipop's success, those should not cause a failure. */       \
        if (RUN_ODY_CHIPOP_errl                                         \
            && !(RUN_ODY_CHIPOP_errl->hasErrorTypeOtherThan(SBEIO_ERROR_TYPE_FFDC_PACKAGE))) \
        {                                                               \
            TRACISTEP(#CALLER ": PARTIAL SUCCESS running " #OP " chipop on target HUID 0x%.8X", \
                      get_huid(TARGET));                                \
            /* If there are visible logs, send through FSM for possible update*/        \
            if(RUN_ODY_CHIPOP_errl->isSevVisible())                                     \
            {                                                                           \
                ocmbupd::ody_upd_event_t M_update_event = ocmbupd::OCMB_HWP_FAIL_OTHER; \
                TARGETING::Target* const M_ocmb = TARGET;                               \
                errlOwner M_errl(RUN_ODY_CHIPOP_errl);                                  \
                if (auto M_upd_errl = ocmbupd::ody_upd_process_event(M_ocmb,            \
                                            M_update_event,                             \
                                            std::move(M_errl)))                         \
                {                                                                       \
                    TRACISTEP(ERR_MRK #OP ": ody_upd_process_event(0x%08x) "            \
                        "failed following a partially successful chipop "               \
                        TRACE_ERR_FMT,                                  \
                        get_huid(M_ocmb),                               \
                        TRACE_ERR_ARGS(M_upd_errl));                    \
                    collectOdyScratchData(TARGET,RUN_ODY_CHIPOP_errl);  \
                    errlCommit(RUN_ODY_CHIPOP_errl, ISTEP_COMP_ID);     \
                }                                                       \
            }                                                           \
            else                                                        \
            {                                                           \
                collectOdyScratchData(TARGET,RUN_ODY_CHIPOP_errl);          \
                errlCommit(RUN_ODY_CHIPOP_errl, ISTEP_COMP_ID);             \
            }                                                           \
        }                                                               \
        /* A chipop execution failure. */                               \
        else if (RUN_ODY_CHIPOP_errl)                                   \
        {                                                               \
            TRACISTEP(#CALLER ": FAILURE running " #OP " chipop on target HUID 0x%.8X", \
                      get_huid(TARGET));                                \
            goto ERROR_EXIT;                                            \
        }                                                               \
        else                                                            \
        {                                                               \
            TRACISTEP(#CALLER ": SUCCESS running " #OP " chipop on target HUID 0x%.8X", \
                      get_huid(TARGET));                                \
        }                                                               \
    } while (false)

namespace ISTEP
{

/*******************************************************************************
 * @brief Base work item class for running a HWP-based istep in parallel, where
 *        captureErrorOcmbUpdateCheck is called if there is a hwp failure.
 */
class HwpWorkItem_OCMBUpdateCheck : public HwpWorkItem
{
public:

    using error_list = std::vector<std::pair<TARGETING::Target*, errlHndl_t>>;

private:

    static error_list cv_errors; // access to this is controlled by cv_stepErrorMutex

    /** @brief Push an error onto the static error list in a thread-safe manner.
     */
    static void push_error(TARGETING::Target* const i_target, errlHndl_t& io_errl)
    {
        const auto lock = scoped_mutex_lock(cv_stepErrorMutex);

        cv_errors.push_back(std::make_pair(i_target, io_errl));
        io_errl = nullptr;
    }

public:

    /**
     * @brief ctor
     *
     * @param[in] i_stepError  Error accumulator for this istep
     * @param[in] i_target  Target to execute HWP against
     * @param[in] i_hwpName  Name of HWP being executed
     */
    HwpWorkItem_OCMBUpdateCheck(ISTEP_ERROR::IStepError& i_stepError,
                                TARGETING::Target& i_target,
                                const char* const i_hwpName)
        : HwpWorkItem(i_stepError, i_target, i_hwpName)
    { }

    /**
     * @brief Executes if the HWP returns an error
     *
     * @param[in/out] io_err  Error returned from FAPI_INVOKE_HWP. Set
     *                        to NULL on return from this function.
     */
    virtual void run_after_failure(errlHndl_t& io_err) override
    {
        if (TARGETING::UTIL::isOdysseyChip(iv_pTarget))
        { // If this is an Odyssey target, let the Odyssey code update
          // FSM take action.
            HANDLE_ODY_HWP_ERROR(memory_init, memory_init, *iv_pStepError, iv_pTarget, io_err);
        }
        else
        { // If this is not an Odyssey target, it's either an Explorer
          // system or some non-OCMB Odyssey-related target. In the
          // Explorer case we let Explorer logic handle the error, and
          // if it's an Odyssey-related non-OCMB we are going to
          // broadcast this event to all Odysseys in the node. We
          // can't do multiple broadcasts in parallel, so we save off
          // this error and handle them all sequentially in
          // handle_errors. (And do the same for Explorer systems
          // since it doesn't hurt.)
            TRACISTEP(INFO_MRK"HwpWorkItem_OCMBUpdateCheck::run_after_failure: Saving "
                      "error 0x%08X (target 0x%08X) to handle later (HWP %s)",
                      ERRL_GETEID_SAFE(io_err),
                      get_huid(iv_pTarget),
                      iv_hwpName);
            push_error(iv_pTarget, io_err);
        }

        const auto lock = scoped_mutex_lock(cv_stepErrorMutex);
        cv_encounteredHwpError = true;
    }

    /**
     * @brief Retrieve the static list of errors that need to be processed
     * sequentially, and clear it.
     *
     * @note This should be called from a single thread.
     */
    static error_list get_and_clear_errors()
    {
        auto vec = move(cv_errors);
        cv_errors.clear();
        return vec;
    }

    /**
     * @brief Handle the static list of errors that need to be processed
     * sequentially, and clear it.
     *
     * @note This should be called from a single thread.
     */
    static void handle_and_clear_errors(ISTEP_ERROR::IStepError& io_stepError,
                                        const compId_t i_comp_id = HWPF_COMP_ID)
    {
        for (auto [ target, errl ] : get_and_clear_errors())
        {
            TRACISTEP(INFO_MRK"HwpWorkItem_OCMBUpdateCheck::handle_errors: "
                      "Handling error 0x%08X on target 0x%08X",
                      ERRL_GETEID_SAFE(errl),
                      get_huid(target));

            ocmbupd::captureErrorOcmbUpdateCheck(errl, io_stepError, i_comp_id, target);
        }
    }
};

/**
 * @brief A HwpWorkItem that can call a given function.
 *
 * @tparam Base     The class to inherit from. Use this to customize error
 *                  handling if needed.
 * @tparam Functor  The type of the functor to call (this should be inferred
 *                  by a wrapper function).
 */
template<typename Base, typename Functor>
class HwpWorkItem_Generic : public Base
{
public:
    template<typename F>
    HwpWorkItem_Generic(F&& i_functor,
                        ISTEP_ERROR::IStepError& i_stepError,
                        TARGETING::Target&     i_target,
                        const char*     i_hwpName )
        : Base(i_stepError, i_target, i_hwpName),
          functor(std::forward<F>(i_functor))
    {
    }

    virtual errlHndl_t run_hwp() override
    {
        return functor(Base::iv_pTarget);
    }

    Functor functor;
};

/**
 * @brief Utility to create a HwpWorkItem_Generic for use with ThreadPool.
 *
 * @tparam        Base          Base class for the work item.
 * @tparam        F             Functor type (inferred).
 *
 * @param[in/out] io_stepError  The IStepError to record error logs with.
 * @param[in]     i_target      The target to invoke the functor on.
 * @param[in]     i_hwpName     The name of the HWP being called (for traces/logs).
 * @param[in]     i_functor     The functor to call.
 *
 * @return                      A HwpWorkItem_Generic instance that will invoke
 *                              the given functor.
 */
template<typename Base = HwpWorkItem, typename F>
inline auto parallel_work(ISTEP_ERROR::IStepError& io_stepError,
                          TARGETING::Target& i_target,
                          const char* const i_hwpName,
                          F&& i_functor)
{
    return new HwpWorkItem_Generic<Base, typename std::remove_reference<F>::type>(
        std::forward<F>(i_functor),
        io_stepError,
        i_target,
        i_hwpName
    );
}

/** @brief Provides a function invoke() that will call handle_and_clear_errors on the
 *  given class, if it exists.
 */
struct HwpWorkItem_invoke_handle_and_clear_errors
{
    template<typename T>
    static void invoke(ISTEP_ERROR::IStepError& io_stepError, decltype(&T::handle_and_clear_errors))
    {
        T::handle_and_clear_errors(io_stepError);
    }

    template<typename T>
    static void invoke(ISTEP_ERROR::IStepError& io_stepError, ...)
    {
        // The given class doens't have a handle_and_clear_errors function, so don't
        // do anything.
    }
};

/**
 * @brief Use ThreadPool to run a series of tasks in parallel, one task per item in
 * the given container.
 *
 * run_after_failure-style error handling can be customized by explicitly providing a
 * class for the tasks to inherit from as the first template argument to this function.
 *
 * After the threads finish, if the provided class has a function named
 * "handle_and_clear_errors", it will be called with a reference to an IStepError.
 *
 * @tparam       Base          Base class for the task class. Use this to customize
 *                             error handling if needed.
 * @tparam       Cont          Container type (inferred).
 * @tparam       F             Function type (inferred).
 *
 * @param[in]    i_container   The container with elements to apply the function to.
 * @param[in]    io_stepError  The IStepError to log errors with.
 * @param[in]    i_hwpname     The name of the hardware procedure (for traces/logs).
 * @param[in]    i_functor     The functor to apply to the elements of the given
 *                             container in parallel.
 */
template<typename Base = HwpWorkItem, typename Cont, typename F>
inline void parallel_for_each(Cont&& i_container,
                              ISTEP_ERROR::IStepError& io_stepError,
                              const char* const i_hwpname,
                              F&& i_functor)
{
    Util::ThreadPool<HwpWorkItem> threadpool;

    for (const auto elem : i_container)
    {
        threadpool.insert(parallel_work<Base>(io_stepError, *elem, i_hwpname, i_functor));
    }

    HwpWorkItem::start_threads(threadpool, io_stepError, i_container.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        HwpWorkItem_invoke_handle_and_clear_errors::invoke<Base>(io_stepError, nullptr);
    }
}

} //namespace ISTEP

#endif //__ISTEPS_HWPTHREADHELPER_H
