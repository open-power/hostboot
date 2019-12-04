/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_cen_set_inband_addr.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <util/utilmbox_scratch.H>
#include <util/misc.H>

#ifdef CONFIG_AXONE
// Axone HWPs
#include    <exp_omi_init.H>
#include    <p9a_omi_init.H>
#include    <p9a_disable_ocmb_i2c.H>
#include    <expupd/expupd.H>
#else
// Cumulus HWP
#include    <p9c_set_inband_addr.H>
#endif

//Inband SCOM
#include    <ibscom/ibscomif.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_12
{
void cumulus_call_cen_set_inband_addr(IStepError & io_istepError);
void axone_call_cen_set_inband_addr(IStepError & io_istepError);
void enableInbandScomsOCMB( TARGETING::TargetHandleList i_ocmbTargetList );
void disableI2cAccessToOcmbs(IStepError & io_istepError);

void* call_cen_set_inband_addr (void *io_pArgs)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_set_inband_addr entry" );
    IStepError l_StepError;
    auto l_procModel = TARGETING::targetService().getProcessorModel();

    switch (l_procModel)
    {
        case TARGETING::MODEL_CUMULUS:
            cumulus_call_cen_set_inband_addr(l_StepError);
            // @todo RTC 187913 inband centaur scom in P9
            // Re-enable when support available in simics
            if ( Util::isSimicsRunning() == false )
            {
                //Now enable Inband SCOM for all memory mapped chips.
                IBSCOM::enableInbandScoms();
            }
            break;
        case TARGETING::MODEL_AXONE:
            axone_call_cen_set_inband_addr(l_StepError);

            // No need to disable i2c access if and error was encountered setting up the inband addr
            if(l_StepError.isNull())
            {
                disableI2cAccessToOcmbs(l_StepError);
            }
            break;
        case TARGETING::MODEL_NIMBUS:
            break;  // do nothing step
        default:
            assert(0, "call_cen_set_inband_addr: Unsupported model type 0x%04X",
                l_procModel);
            break;
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_set_inband_addr exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

#ifndef CONFIG_AXONE
void cumulus_call_cen_set_inband_addr(IStepError & io_istepError)
{
    errlHndl_t l_err = nullptr;
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_set_inband_addr: %d proc chips found",
            l_procTargetList.size());

    for (const auto & l_proc_target : l_procTargetList)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p9c_set_inband_addr HWP target HUID %.8x",
            TARGETING::get_huid(l_proc_target));

        //  call the HWP with each target
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target
                (l_proc_target);

        FAPI_INVOKE_HWP(l_err, p9c_set_inband_addr, l_fapi_proc_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  p9c_set_inband_addr HWP on target HUID %.8x",
                l_err->reasonCode(), TARGETING::get_huid(l_proc_target) );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );

        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  p9c_set_inband_addr HWP");
        }
    } // proc target loop
}

void axone_call_cen_set_inband_addr(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'exp_omi_init/p9a_omi_init' but Axone code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}

void enableInbandScomsOCMB( TARGETING::TargetHandleList l_ocmbTargetList )
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'enableInbandScomsOCMB' but Axone code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}
  
void disableI2cAccessToOcmbs(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'disableI2cAccessToOcmbs' but Axone code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}


#else

void cumulus_call_cen_set_inband_addr(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'p9c_set_inband_addr' but Cumulus code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}

void axone_call_cen_set_inband_addr(IStepError & io_istepError)
{
    errlHndl_t l_err = nullptr;
    TARGETING::TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
        "axone_call_cen_set_inband_addr: %d ocmb chips found",
        l_ocmbTargetList.size());

    for (const auto & l_ocmb_target : l_ocmbTargetList)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "exp_omi_init HWP target HUID %.8x",
            TARGETING::get_huid(l_ocmb_target) );

        //  call the HWP with each target
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
                (l_ocmb_target);

        FAPI_INVOKE_HWP(l_err, exp_omi_init , l_fapi_ocmb_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                    "ERROR 0x%.8X:  exp_omi_init HWP on target HUID 0x%.8x",
                    l_err->reasonCode(), TARGETING::get_huid(l_ocmb_target) );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_ocmb_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  exp_omi_init HWP on target HUID 0x%.8x",
                TARGETING::get_huid(l_ocmb_target) );
        }
    } // ocmb loop

    TargetHandleList l_mccTargetList;
    getAllChiplets(l_mccTargetList, TYPE_MCC);

    for (const auto & l_mcc_target : l_mccTargetList)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p9a_omi_init HWP target HUID %.8x",
            TARGETING::get_huid(l_mcc_target) );

        //  call the HWP with each target
        fapi2::Target<fapi2::TARGET_TYPE_MCC> l_fapi_mcc_target
                (l_mcc_target);

        FAPI_INVOKE_HWP(l_err, p9a_omi_init, l_fapi_mcc_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                "ERROR 0x%.8X:  p9a_omi_init HWP on target HUID %.8x",
                l_err->reasonCode(), TARGETING::get_huid(l_mcc_target) );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mcc_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  p9a_omi_init HWP on target HUID 0x%.8x ,"
                "setting scom settings to use inband for all ocmb children",
                TARGETING::get_huid(l_mcc_target));

            TargetHandleList l_ocmbTargetList;
            getChildAffinityTargets(l_ocmbTargetList , l_mcc_target,
                                    CLASS_CHIP, TARGETING::TYPE_OCMB_CHIP);
            enableInbandScomsOCMB(l_ocmbTargetList);
        }
    } // MCC loop

    // Check if any explorer chips require a firmware update and update them
    // (skipped on MPIPL)
    // We should be checking for updates and perform the updates even if OMI
    // initialization failed.  It's possible that the OMI failure was due to
    // the OCMB having an old image. The update code will automatically
    // switch to using i2c if OMI is not enabled.
    Target* l_pTopLevel = nullptr;
    targetService().getTopLevelTarget( l_pTopLevel );
    assert(l_pTopLevel, "axone_call_cen_set_inband_addr: no TopLevelTarget");
    if (l_pTopLevel->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "skipping expupdUpdateAll due to MPIPL");
    }
    else
    {
        expupd::updateAll(io_istepError);
    }
}

/**
 * @brief Loop over all processors and disable i2c path to ocmb
 *        After this point no i2c commands will be possible until we
 *        power the chip off and on.
 * @param io_istepError - Istep error that tracks error logs for this step
 */
void disableI2cAccessToOcmbs(IStepError & io_istepError)
{
    errlHndl_t l_err = nullptr;
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TARGETING::TYPE_PROC);
    // We only want to disable i2c if we are in secure mode
    const bool FORCE_DISABLE = false;

    for ( const auto & l_proc : l_procTargetList )
    {
        //  call the HWP with each proc
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target
                (l_proc);

        FAPI_INVOKE_HWP(l_err, p9a_disable_ocmb_i2c, l_fapi_proc_target, FORCE_DISABLE);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                "ERROR 0x%.8X:  p9a_disable_ocmb_i2c HWP on target HUID %.8x",
                l_err->reasonCode(), TARGETING::get_huid(l_proc) );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  p9a_disable_ocmb_i2c HWP on target HUID 0x%.8x",
                TARGETING::get_huid(l_proc));
        }
    }
}

/**
 * @brief Enable Inband Scom for the OCMB targets
 * @param i_ocmbTargetList - OCMB targets
 */
void enableInbandScomsOCMB( TARGETING::TargetHandleList i_ocmbTargetList )
{
    mutex_t* l_mutex = NULL;

    for ( const auto & l_ocmb : i_ocmbTargetList )
    {
        //don't mess with attributes without the mutex (just to be safe)
        l_mutex = l_ocmb->getHbMutexAttr<TARGETING::ATTR_IBSCOM_MUTEX>();
        mutex_lock(l_mutex);

        ScomSwitches l_switches = l_ocmb->getAttr<ATTR_SCOM_SWITCHES>();
        l_switches.useI2cScom = 0;
        l_switches.useInbandScom = 1;

        // Modify attribute
        l_ocmb->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
        mutex_unlock(l_mutex);
    }
}

#endif // CONFIG_AXONE

};
