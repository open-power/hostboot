/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/nest_chiplets/nest_chiplets.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
   @file nest_chiplets.C                                                
 *
 *  Support file for IStep: nest_chiplets                                                    
 *   Nest Chiplets
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-03:1952
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

//  --  prototype   includes    --
//  Add any customized routines that you don't want overwritten into
//      "start_clocks_on_nest_chiplets_custom.C" and include 
//      the prototypes here.
//  #include    "nest_chiplets_custom.H"
#include    "nest_chiplets.H"
#include    "proc_start_clocks_chiplets/proc_start_clocks_chiplets.H"
#include    "proc_chiplet_scominit/proc_chiplet_scominit.H"
#include    "proc_scomoverride_chiplets/proc_scomoverride_chiplets.H"
#include    "proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_setup.H"
#include    "proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_initf.H"
#include    "proc_pcie_scominit/proc_pcie_scominit.H"

namespace   NEST_CHIPLETS
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;

//*****************************************************************************
// wrapper function to call step 7.01 - proc_a_x_pci_dmi_pll_initf
//*****************************************************************************
void*    call_proc_a_x_pci_dmi_pll_initf( void    *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
            "call_proc_a_x_pci_dmi_pll_initf entry" );

    //TODO - Enable this procedure in SIMICs when RTC 46643 is done.
    //       For now, only run this procedure in VPO.
    if ( !(TARGETING::is_vpo()) )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "WARNING: proc_a_x_pci_dmi_pll_initf HWP"
                   " is disabled in SIMICS run!");
        // end task
        return  l_err ;
    }

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for ( TargetHandleList::iterator l_iter = l_procTargetList.begin();
          l_iter != l_procTargetList.end(); ++l_iter )
    {
        const TARGETING::Target*  l_proc_target = *l_iter;
        const fapi::Target l_fapi_proc_target(
                            TARGET_TYPE_PROC_CHIP,
                            reinterpret_cast<void *>
                            ( const_cast<TARGETING::Target*>(l_proc_target) ) );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Running proc_a_x_pci_dmi_pll_initf HWP");
        EntityPath l_path;
        l_path  =   l_proc_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        //  call proc_a_x_pci_dmi_pll_initf
        FAPI_INVOKE_HWP(l_err, proc_a_x_pci_dmi_pll_initf,
                        l_fapi_proc_target,
                        true,   // xbus
                        true,   // abus
                        true,   // pcie
                        true);  // dmi

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: proc_a_x_pci_dmi_pll_initf"
                      " HWP returns error",
                      l_err->reasonCode());

            ErrlUserDetailsTarget myDetails(l_proc_target);

            // capture the target data in the elog
            myDetails.addToLog(l_err );

            /*@
             * @errortype
             * @reasoncode  ISTEP_NEST_CHIPLETS_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_PROC_A_X_PCI_DMI_PLL_INITF
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to proc_a_x_pci_dmi_pll_initf has failed
             */
            l_StepError.addErrorDetails(ISTEP_NEST_CHIPLETS_FAILED,
                                        ISTEP_PROC_A_X_PCI_DMI_PLL_INITF,
                                        l_err);

            errlCommit( l_err, HWPF_COMP_ID );

           break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: proc_a_x_pci_dmi_pll_initf HWP( )" );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_a_x_pci_dmi_pll_initf exit" );
    return l_StepError.getErrorHandle();
}

//*****************************************************************************
// wrapper function to call step 7.02 - proc_a_x_pci_dmi_pll_setup
//*****************************************************************************
void*    call_proc_a_x_pci_dmi_pll_setup( void    *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
            "call_proc_a_x_pci_dmi_pll_setup entry" );

    //TODO - Enable this procedure in SIMICs when RTC 46643 is done.
    //       For now, only run this procedure in VPO.
    if ( !(TARGETING::is_vpo()) )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "WARNING: proc_a_x_pci_dmi_pll_setup HWP "
                   "is disabled in SIMICS run!");
        // end task
        return  l_err ;
    }

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for ( TargetHandleList::iterator l_iter = l_procTargetList.begin();
          l_iter != l_procTargetList.end(); ++l_iter )
    {
        const TARGETING::Target*  l_proc_target = *l_iter;
        const fapi::Target l_fapi_proc_target(
                TARGET_TYPE_PROC_CHIP,
                reinterpret_cast<void *>
                ( const_cast<TARGETING::Target*>(l_proc_target) ) );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running proc_a_x_pci_dmi_pll_setup HWP on...");
        EntityPath l_path;
        l_path  =   l_proc_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        //  call proc_a_x_pci_dmi_pll_setup
        FAPI_INVOKE_HWP(l_err, proc_a_x_pci_dmi_pll_setup,
                        l_fapi_proc_target,
                        true,   // xbus
                        true,   // abus
                        true,   // pcie
                        true);  // dmi

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: proc_a_x_pci_dmi_pll_setup \
                      HWP returns error",
                      l_err->reasonCode());

            ErrlUserDetailsTarget myDetails(l_proc_target);

            // capture the target data in the elog
            myDetails.addToLog(l_err );

            /*@
             * @errortype
             * @reasoncode  ISTEP_NEST_CHIPLETS_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_PROC_A_X_PCI_DMI_PLL_SETUP
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to proc_a_x_pci_dmi_pll_setup has failed
             */
            l_StepError.addErrorDetails(ISTEP_NEST_CHIPLETS_FAILED,
                                        ISTEP_PROC_A_X_PCI_DMI_PLL_SETUP,
                                        l_err);

            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: proc_a_x_pci_dmi_pll_setup HWP( )" );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_proc_a_x_pci_dmi_pll_setup exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

//*****************************************************************************
// wrapper function to call step 7.03 - proc_startclock_chiplets
//*****************************************************************************
void*    call_proc_startclock_chiplets( void    *io_pArgs )
{
    errlHndl_t l_err =   NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_proc_startclock_chiplets entry" );

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for ( TargetHandleList::iterator l_iter = l_procTargetList.begin();
          l_iter != l_procTargetList.end(); ++l_iter )
    {
        const TARGETING::Target*  l_proc_target = *l_iter;
        const fapi::Target l_fapi_proc_target(
                TARGET_TYPE_PROC_CHIP,
                reinterpret_cast<void *>
                ( const_cast<TARGETING::Target*>(l_proc_target) )
        );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                   "Running proc_startclock_chiplets HWP on..." );
        //  dump physical path to targets
        EntityPath l_path;
        l_path  =   l_proc_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, proc_start_clocks_chiplets,
                        l_fapi_proc_target,
                        true,   // xbus
                        true,   // abus
                        true);  // pcie
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X : proc_startclock_chiplets HWP "
                      "returns error",
                       l_err->reasonCode());

            ErrlUserDetailsTarget myDetails(l_proc_target);

            // capture the target data in the elog
            myDetails.addToLog(l_err );

            /*@
             * @errortype
             * @reasoncode  ISTEP_NEST_CHIPLETS_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_PROC_STARTCLOCK_CHIPLETS
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to proc_start_clocks_chiplets has failed
             */
            l_StepError.addErrorDetails(ISTEP_NEST_CHIPLETS_FAILED,
                                        ISTEP_PROC_STARTCLOCK_CHIPLETS,
                                        l_err);

            errlCommit( l_err, HWPF_COMP_ID );

            break; // break out of cpuNum
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                       "SUCCESS :  proc_startclock_chiplets HWP( )" );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_proc_startclock_chiplets exit" );

    // end task, returning any errorlogs to IStepDisp 
    return l_StepError.getErrorHandle();
}

//******************************************************************************
// wrapper function ito call step 7.04 - proc_chiplet_scominit
//******************************************************************************
void*    call_proc_chiplet_scominit( void    *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_proc_chiplet_scominit entry" );

    // proc_chiplet_scominit will be called when there are initfiles to execute

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_proc_chiplet_scominit exit" );

    return l_err;
}

//*****************************************************************************
// wrapper function to call step 7.05 - proc_pcie_scominit
//******************************************************************************
void*    call_proc_pcie_scominit( void    *io_pArgs )
{
    errlHndl_t          l_errl      =   NULL;
    IStepError          l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "call_proc_pcie_scominit entry" );

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for ( TargetHandleList::iterator l_iter = l_procTargetList.begin();
          l_iter != l_procTargetList.end(); ++l_iter )
    {
        const TARGETING::Target*  l_proc_target = *l_iter;
        const fapi::Target l_fapi_proc_target(
                TARGET_TYPE_PROC_CHIP,
                reinterpret_cast<void *>
                ( const_cast<TARGETING::Target*>(l_proc_target) )
        );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Running proc_pcie_scominit HWP on..." );

        //  dump physical path to targets
        EntityPath l_path;
        l_path  =   l_proc_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_errl, proc_pcie_scominit, l_fapi_proc_target);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X : proc_pcie_scominit HWP returns error",
                      l_errl->reasonCode());

            /*@
             * @errortype
             * @reasoncode  ISTEP_NEST_CHIPLETS_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_PROC_PCIE_SCOMINIT
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to proc_pcie_scominit has failed
             */
            l_StepError.addErrorDetails(ISTEP_NEST_CHIPLETS_FAILED,
                                        ISTEP_PROC_PCIE_SCOMINIT,
                                        l_errl);

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog( l_errl );

            errlCommit( l_errl, HWPF_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS :  proc_pcie_scominit HWP" );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "call_proc_pcie_scominit exit" );

    // end task, returning any errorlogs to IStepDisp 
    return l_StepError.getErrorHandle();
}

//*****************************************************************************
// wrapper function to call step 7.06 - proc_scomoverride_chiplets
//*****************************************************************************
void*    call_proc_scomoverride_chiplets( void    *io_pArgs )
{
    errlHndl_t          l_errl      =   NULL;

    IStepError          l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_proc_scomoverride_chiplets entry" );

    FAPI_INVOKE_HWP(l_errl, proc_scomoverride_chiplets);

    if (l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, 
                  "ERROR 0x%.8X : proc_scomoverride_chiplets "
                  "HWP returns error",
                  l_errl->reasonCode());
            /*@
             * @errortype
             * @reasoncode  ISTEP_NEST_CHIPLETS_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_PROC_SCOMOVERRIDE_CHIPLETS
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to proc_scomoverride_chiplets has failed
             */
            l_StepError.addErrorDetails(ISTEP_NEST_CHIPLETS_FAILED,
                                        ISTEP_PROC_SCOMOVERRIDE_CHIPLETS,
                                        l_errl);

            errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, 
                  "SUCCESS :  proc_scomoverride_chiplets HWP");
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_proc_scomoverride_chiplets exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}


};   // end namespace
