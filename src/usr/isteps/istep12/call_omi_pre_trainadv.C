/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_pre_trainadv.C $              */
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
 * @file    call_omi_pre_trainadv.C
 *
 *  Support file for Istep 12.5 Debug routine for IO Characterization
 *
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>          // captureError
#include    <hwpThread.H>
#include    <hwpThreadHelper.H>

#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <chipids.H>
#include    <p10_io_omi_pre_trainadv.H>
#include    <ody_omi_hss_tx_zcal.H>
#include    <ody_omi_pretrain_adv.H>

#include    <sbeio/sbeioif.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;
using   namespace   SBEIO;

namespace ISTEP_12
{

class Host_ody_omi_hss_tx_zcal: public HwpWorkItem
{
  public:
    Host_ody_omi_hss_tx_zcal( IStepError& i_stepError,
                                  Target& i_ocmb )
    : HwpWorkItem( i_stepError, i_ocmb, "ody_omi_hss_tx_zcal" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, ody_omi_hss_tx_zcal, l_fapi_target);
        return l_err;
    }
};

class ChipOp_ody_omi_hss_tx_zcal: public HwpWorkItem
{
  public:
    ChipOp_ody_omi_hss_tx_zcal( IStepError& i_stepError,
                                    Target& i_ocmb )
    : HwpWorkItem( i_stepError, i_ocmb, "ody_omi_hss_tx_zcal" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        RUN_SUB_CHIPOP(CONTEXT, l_err, iv_pTarget, IO_ODY_OMI_HSS_TX_ZCAL);
        ERROR_EXIT:
        return l_err;
    }
};

class Host_ody_omi_pretrain_adv: public HwpWorkItem
{
  public:
    Host_ody_omi_pretrain_adv( IStepError& i_stepError,
                                   Target& i_ocmb )
    : HwpWorkItem( i_stepError, i_ocmb, "ody_omi_pretrain_adv" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, ody_omi_pretrain_adv, l_fapi_target);
        return l_err;
    }
};

class ChipOp_ody_omi_pretrain_adv: public HwpWorkItem
{
  public:
    ChipOp_ody_omi_pretrain_adv( IStepError& i_stepError,
                                     Target& i_ocmb )
    : HwpWorkItem( i_stepError, i_ocmb, "ody_omi_pretrain_adv" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        l_err = sendExecHWPRequest(iv_pTarget, IO_ODY_OMI_PRETRAIN_ADV);
        return l_err;
    }
};

void* call_omi_pre_trainadv (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
    Util::ThreadPool<HwpWorkItem> threadpool;
    TargetHandleList l_procTargetList;

    // get RUN_ODY_HWP_FROM_HOST
    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    // 12.5.a ody_omi_hss_tx_zcal
    for (const auto l_ocmb_target : l_ocmbTargetList)
    {
        //  call the HWP with each target
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
            (l_ocmb_target);

        uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();

        //  Create a new workitem from this ocmb and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        if (chipId == POWER_CHIPID::ODYSSEY_16)
        {
            if (l_runOdyHwpFromHost)
            {
                threadpool.insert(new Host_ody_omi_hss_tx_zcal(l_StepError,
                                                              *l_ocmb_target));
            }
            else
            {
                threadpool.insert(new ChipOp_ody_omi_hss_tx_zcal(l_StepError,
                                                                *l_ocmb_target));
            }
        }
    }

    HwpWorkItem::start_threads(threadpool, l_StepError, l_ocmbTargetList.size());

    // Do not continue if an error was encountered
    if(HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP( g_trac_isteps_trace,
            INFO_MRK "call_omi_pre_trainadv exited early because ody_omi_hss_tx_zcal "
            "had failures");
        goto ERROR_EXIT;
    }

    getAllChips(l_procTargetList, TYPE_PROC);
    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_omi_pre_trainadv. "
        "%d PROCs found", l_procTargetList.size());

    // 12.5.b p10_io_omi_pre_trainadv.C
    //        - Debug routine for IO characterization
    for (const auto & l_proc_target : l_procTargetList)
    {
        TRACFCOMP(g_trac_isteps_trace,
            INFO_MRK"p10_io_omi_pre_trainadv HWP target HUID 0x%.8x ",
            get_huid(l_proc_target));

        //  call the HWP with each target
        fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target
                (l_proc_target);

        FAPI_INVOKE_HWP(l_err, p10_io_omi_pre_trainadv, l_fapi_proc_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP(g_trac_isteps_trace,
                ERR_MRK"call p10_io_omi_pre_trainadv HWP(): failed on "
                "target 0x%08X. " TRACE_ERR_FMT,
                get_huid(l_proc_target),
                TRACE_ERR_ARGS(l_err));

            captureError(l_err, l_StepError, HWPF_COMP_ID, l_proc_target);
            goto ERROR_EXIT;
        }

        TRACFCOMP(g_trac_isteps_trace,
                INFO_MRK"SUCCESS : p10_io_omi_pre_trainadv HWP ");
    }

    // 12.5.c ody_omi_pretrain_adv
    for (const auto l_ocmb_target : l_ocmbTargetList)
    {
        //  call the HWP with each target
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
            (l_ocmb_target);

        uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();

        //  Create a new workitem from this ocmb and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        if (chipId == POWER_CHIPID::ODYSSEY_16)
        {
            if (l_runOdyHwpFromHost)
            {
                threadpool.insert(new Host_ody_omi_pretrain_adv(l_StepError,
                                                               *l_ocmb_target));
            }
            else
            {
                threadpool.insert(new ChipOp_ody_omi_pretrain_adv(l_StepError,
                                                                 *l_ocmb_target));
            }
        }
    }

    HwpWorkItem::start_threads(threadpool, l_StepError, l_ocmbTargetList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_omi_pre_trainadv: ody_omi_pretrain_adv: error");
        goto ERROR_EXIT;
    }

    ERROR_EXIT:

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_omi_pre_trainadv ");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
