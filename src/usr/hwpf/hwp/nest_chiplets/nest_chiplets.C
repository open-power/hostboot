/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/nest_chiplets.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
   @file nest_chiplets.C                                                
 *
 *  Support file for IStep: nest_chiplets                                                    
 *   Nest Chiplets
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
#include    <initservice/initserviceif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>


//  --  prototype   includes    --
//  Add any customized routines that you don't want overwritten into
//      "start_clocks_on_nest_chiplets_custom.C" and include 
//      the prototypes here.
//  #include    "nest_chiplets_custom.H"
#include    "nest_chiplets.H"
#include    "proc_start_clocks_chiplets/proc_start_clocks_chiplets.H"
#include    "proc_chiplet_scominit/proc_chiplet_scominit.H"
#include    "proc_chiplet_scominit/proc_xbus_scominit.H"
#include    "proc_chiplet_scominit/proc_abus_scominit.H"
#include    "proc_scomoverride_chiplets/proc_scomoverride_chiplets.H"
#include    "proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_setup.H"
#include    "proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_initf.H"
#include    "proc_pcie_scominit/proc_pcie_scominit.H"
#include    "../bus_training/pbusLinkSvc.H"
#include    <fapiHwpExecInitFile.H>
#include    "proc_pcie_slot_power.H"

const char * const PROC_CHIPLET_ABUS_IF = "p8.abus.scom.if";
const char * const PROC_CHIPLET_XBUS_IF = "p8.xbus.scom.if";

namespace   NEST_CHIPLETS
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;

//*****************************************************************************
// wrapper function to call proc_attr_update
//*****************************************************************************
void * call_proc_attr_update( void * io_pArgs )
{
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_proc_attr_update entry" );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_proc_attr_update exit" );

    return l_StepError.getErrorHandle();

}
//*****************************************************************************
// wrapper function to call proc_a_x_pci_dmi_pll_initf
//*****************************************************************************
void*    call_proc_a_x_pci_dmi_pll_initf( void    *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_proc_a_x_pci_dmi_pll_initf entry" );

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for ( TargetHandleList::const_iterator
          l_iter = l_procTargetList.begin();
          l_iter != l_procTargetList.end();
          ++l_iter )
    {
        const TARGETING::Target*  l_proc_target = *l_iter;
        const fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                            ( const_cast<TARGETING::Target*>(l_proc_target) ) );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_a_x_pci_dmi_pll_initf HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_proc_target));

        bool l_startXbusPll = false;
        bool l_startAbusPll = false;
        bool l_startPCIEPll = false;
        bool l_startDMIPll = false;
        
        TARGETING::TargetHandleList l_xbus;
        getChildChiplets( l_xbus, l_proc_target, TYPE_XBUS );
        if (l_xbus.size() > 0)
        {
            l_startXbusPll = true;
        }

        TARGETING::TargetHandleList l_abus;
        getChildChiplets( l_abus, l_proc_target, TYPE_ABUS );
        if (l_abus.size() > 0)
        {
            l_startAbusPll = true;
        }

        TARGETING::TargetHandleList l_pci;
        getChildChiplets( l_pci, l_proc_target, TYPE_PCI );
        if (l_pci.size() > 0)
        {
            l_startPCIEPll = true;
        }

        TARGETING::TargetHandleList l_mcs;
        getChildChiplets( l_mcs, l_proc_target, TYPE_MCS );
        if (l_mcs.size() > 0)
        {
            l_startDMIPll = true;
        }

        //  call proc_a_x_pci_dmi_pll_initf
        FAPI_INVOKE_HWP(l_err, proc_a_x_pci_dmi_pll_initf,
                        l_fapi_proc_target,
                        l_startXbusPll,   // xbus
                        l_startAbusPll,   // abus
                        l_startPCIEPll,   // pcie
                        l_startDMIPll);   // dmi

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: proc_a_x_pci_dmi_pll_initf"
                      " HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
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
// wrapper function to call proc_a_x_pci_dmi_pll_setup
//*****************************************************************************
void*    call_proc_a_x_pci_dmi_pll_setup( void    *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_proc_a_x_pci_dmi_pll_setup entry" );

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for (TARGETING::TargetHandleList::const_iterator
         l_cpuIter = l_procTargetList.begin();
         l_cpuIter != l_procTargetList.end();
         ++l_cpuIter)
    {
        const TARGETING::Target* l_proc_target = *l_cpuIter;
        const fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                ( const_cast<TARGETING::Target*>(l_proc_target) ) );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_a_x_pci_dmi_pll_setup HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_proc_target));

        bool l_startXbusPll = false;
        bool l_startAbusPll = false;
        bool l_startPCIEPll = false;
        bool l_startDMIPll = false;
        
        TARGETING::TargetHandleList l_xbus;
        getChildChiplets( l_xbus, l_proc_target, TYPE_XBUS );
        if (l_xbus.size() > 0)
        {
            l_startXbusPll = true;
        }

        TARGETING::TargetHandleList l_abus;
        getChildChiplets( l_abus, l_proc_target, TYPE_ABUS );
        if (l_abus.size() > 0)
        {
            l_startAbusPll = true;
        }

        TARGETING::TargetHandleList l_pci;
        getChildChiplets( l_pci, l_proc_target, TYPE_PCI );
        if (l_pci.size() > 0)
        {
            l_startPCIEPll = true;
        }

        TARGETING::TargetHandleList l_mcs;
        getChildChiplets( l_mcs, l_proc_target, TYPE_MCS );
        if (l_mcs.size() > 0)
        {
            l_startDMIPll = true;
        }

        //  call proc_a_x_pci_dmi_pll_setup
        FAPI_INVOKE_HWP(l_err, proc_a_x_pci_dmi_pll_setup,
                        l_fapi_proc_target,
                        l_startXbusPll,   // xbus
                        l_startAbusPll,   // abus
                        l_startPCIEPll,   // pcie
                        l_startDMIPll);   // dmi

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: proc_a_x_pci_dmi_pll_setup"
                      " HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: proc_a_x_pci_dmi_pll_setup HWP( )" );
        }
    }


#ifdef CONFIG_PCIE_HOTPLUG_CONTROLLER
    //  Loop through all the procs in the system
    //  and run proc_pcie_slot_power to
    //  power off hot plug controller to avoid downstream MEX issues


    for (TargetHandleList::const_iterator
            l_proc_iter = l_procTargetList.begin();
            l_proc_iter != l_procTargetList.end();
            ++l_proc_iter)
    {
        //  make a local copy of the Processor target
        TARGETING::Target* l_pProcTarget = *l_proc_iter;

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "target HUID %.8X",
                    TARGETING::get_huid(l_pProcTarget));

        fapi::Target l_fapiProcTarget( fapi::TARGET_TYPE_PROC_CHIP,
                                       l_pProcTarget    );

        // Invoke the HWP
        FAPI_INVOKE_HWP(l_err,
                        proc_pcie_slot_power,
                        l_fapiProcTarget,
                        false  );  // turn off
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : proc_pcie_hotplug_control",
                  " failed, returning errorlog" );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_err );

            // informational. Don't add to istep error or return error
            l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);

            // Commit error log
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "SUCCESS : proc_pcie_hotplug_control",
              " completed ok");
        }
    }   // endfor
#endif


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_a_x_pci_dmi_pll_setup exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

//******************************************************************************
// customizeChipRegions
//******************************************************************************
errlHndl_t customizeChipRegions(TARGETING::Target* i_procTarget)
{

    errlHndl_t l_err = NULL;
    uint8_t *l_pgData = NULL;

    do{

        size_t l_pgSize = 0;

        // First get the size
        l_err = deviceRead(i_procTarget,
                           NULL,
                           l_pgSize,
                           DEVICE_MVPD_ADDRESS(MVPD::CP00, MVPD::PG));
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR: deviceRead of MVPD for PG failed (size): "
                      "errorlog PLID=0x%x",
                      l_err->plid());
            break;
        }

        // Now allocate a buffer and read it
        l_pgData = static_cast<uint8_t *>(malloc(l_pgSize));
        l_err = deviceRead(i_procTarget,
                           l_pgData,
                           l_pgSize,
                           DEVICE_MVPD_ADDRESS(MVPD::CP00, MVPD::PG));
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR: deviceRead of MVPD for PG failed (data): "
                      "errorlog PLID=0x%x",
                      l_err->plid());
            break;
        }

        TRACDBIN(ISTEPS_TRACE::g_trac_isteps_trace,
                 "Binary dump of PG:",l_pgData,l_pgSize);

        static const size_t VPD_CP00_PG_HDR_LENGTH =  01;
        // TODO RTC 47050 : Debate on a max config interface
        static const uint32_t MAX_CHIPLETS_PER_PROC = 32;
        //Starting position of the PG VPD data in ATTR_CHIP_REGIONS_TO_ENABLE
        static const size_t PG_START_POS = ( 64-16-4);

        //prepare the vector to be populated to ATTR_CHIP_REGIONS_TO_ENABLE
        TARGETING::ATTR_CHIP_REGIONS_TO_ENABLE_type l_chipRegionData;
        memset(&l_chipRegionData,0,sizeof(ATTR_CHIP_REGIONS_TO_ENABLE_type));

        //Skip the header
        uint16_t *l_partialGoodUint16=reinterpret_cast<uint16_t*>(
                    &l_pgData[VPD_CP00_PG_HDR_LENGTH]);

        //For customizing the image data, the 16 bit partial good value
        //retrieved for the chiplets ( 32 no. ) , should be set from bit 4..19
        //of the attribute ATTR_CHIP_REGIONS_TO_ENABLE for the processor

        for ( uint32_t l_chipRegionIndex = 0  ;
                l_chipRegionIndex <  MAX_CHIPLETS_PER_PROC ;
                ++l_chipRegionIndex)
        {
            l_chipRegionData[l_chipRegionIndex] =
                l_partialGoodUint16[l_chipRegionIndex];
            l_chipRegionData[l_chipRegionIndex] =
                l_chipRegionData[l_chipRegionIndex]<<PG_START_POS;
        }

        TRACDBIN(ISTEPS_TRACE::g_trac_isteps_trace,
                 "Binary dump of ATTR_CHIP_REGIONS_TO_ENABLE:",
                 l_chipRegionData,sizeof(ATTR_CHIP_REGIONS_TO_ENABLE_type));

        i_procTarget->setAttr<TARGETING::ATTR_CHIP_REGIONS_TO_ENABLE>
            (l_chipRegionData);

    }while(0);

    free(l_pgData);

    return l_err;

}

//*****************************************************************************
// wrapper function to call proc_startclock_chiplets
//*****************************************************************************
void*    call_proc_startclock_chiplets( void    *io_pArgs )
{
    errlHndl_t l_err =   NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_startclock_chiplets entry" );

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);


    for ( TargetHandleList::const_iterator
          l_iter = l_procTargetList.begin();
          l_iter != l_procTargetList.end();
          ++l_iter )
    {
        const TARGETING::Target*  l_proc_target = *l_iter;
        const fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                ( const_cast<TARGETING::Target*>(l_proc_target) ));

        l_err = customizeChipRegions(*l_iter);
        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X : customizeChipRegions "
                      "returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_startclock_chiplets HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_proc_target));

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

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

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
// wrapper function to call proc_chiplet_scominit
//******************************************************************************
void*    call_proc_chiplet_scominit( void    *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                             "call_proc_chiplet_scominit entry" );

    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    do
    {
        // If running Sapphire, set sleep enable attribute here so
        // initfile can be run correctly
        if(is_sapphire_load())
        {
            TARGETING::Target* l_sys = NULL;
            TARGETING::targetService().getTopLevelTarget(l_sys);
            assert( l_sys != NULL );
            uint8_t l_sleepEnable = 1;
            l_sys->setAttr<TARGETING::ATTR_PM_SLEEP_ENABLE>(l_sleepEnable);
        }

        // ----------------------------------------------
        // Execute PROC_CHIPLET_SCOMINIT_FBC_IF initfile
        // ----------------------------------------------

        for (TARGETING::TargetHandleList::const_iterator
             l_cpuIter = l_cpuTargetList.begin();
             l_cpuIter != l_cpuTargetList.end();
             ++l_cpuIter)
        {
            const TARGETING::Target* l_cpu_target = *l_cpuIter;
            const fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                    ( const_cast<TARGETING::Target*>(l_cpu_target) ) );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_chiplet_scominit HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_cpu_target));

            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP(l_err, proc_chiplet_scominit, l_fapi_proc_target);
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : "
                 "proc_chiplet_scominit HWP returns error.  target HUID %.8X",
                        l_err->reasonCode(), TARGETING::get_huid(l_cpu_target));

                ErrlUserDetailsTarget(l_cpu_target).addToLog( l_err );

                // Create IStep error log and cross ref to error that occurred
                l_StepError.addErrorDetails( l_err );
                // We want to continue to the next target instead of exiting,
                // Commit the error log and move on
                // Note: Error log should already be deleted and set to NULL
                // after committing
                errlCommit(l_err, HWPF_COMP_ID);
            }
        }

    } while (0);

    return l_StepError.getErrorHandle();
}

//*****************************************************************************
// wrapper function to call proc_xbus_scominit
//******************************************************************************
void* call_proc_xbus_scominit( void    *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        "call_proc_xbus_scominit entry" );

    do
    {
        EDI_EI_INITIALIZATION::TargetPairs_t l_XbusConnections;
        // Note:
        // i_noDuplicate parameter must be set to false because
        // two separate  calls would be needed:
        //    X0 <--> X1
        //    X1 <--> X0
        // only the first target is used to issue SCOMs
        l_err =
        EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().getPbusConnections(
                                          l_XbusConnections, TYPE_XBUS, false);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : getPbusConnections XBUS returns error",
                    l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );
            // Commit the error log
            // Log should be deleted and set to NULL in errlCommit.
            errlCommit(l_err, HWPF_COMP_ID);

            // Shouldn't continue on this fatal error (no XBUS), break out
            break;
        }

        for (EDI_EI_INITIALIZATION::TargetPairs_t::const_iterator
                        l_itr = l_XbusConnections.begin();
             l_itr != l_XbusConnections.end(); ++l_itr)
        {
            const TARGETING::Target* l_thisXbusTarget = l_itr->first;
            const TARGETING::Target* l_connectedXbusTarget = l_itr->second;

            // Call HW procedure
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_xbus_scominit HWP on "
                "This XBUS target %.8X - Connected XBUS target  %.8X",
                TARGETING::get_huid(l_thisXbusTarget),
                TARGETING::get_huid(l_connectedXbusTarget));

             const fapi::Target l_thisXbusFapiTarget(
                       TARGET_TYPE_XBUS_ENDPOINT,
                       (const_cast<TARGETING::Target*>(l_thisXbusTarget)));

             const fapi::Target l_connectedXbusFapiTarget(
                       TARGET_TYPE_XBUS_ENDPOINT,
                       (const_cast<TARGETING::Target*>(l_connectedXbusTarget)));

            FAPI_INVOKE_HWP(l_err, proc_xbus_scominit,
                            l_thisXbusFapiTarget, l_connectedXbusFapiTarget);
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : proc_xbus_scominit HWP returns error. "
                    "This XBUS target %.8X - Connected XBUS target  %.8X",
                    l_err->reasonCode(),
                    TARGETING::get_huid(l_thisXbusTarget),
                    TARGETING::get_huid(l_connectedXbusTarget));

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_thisXbusTarget).addToLog( l_err );
                ErrlUserDetailsTarget(l_connectedXbusTarget).addToLog( l_err );

                // Create IStep error log and cross ref to error that occurred
                l_StepError.addErrorDetails( l_err );
                // We want to continue to the next target instead of exiting,
                // Commit the error log and move on
                // Note: Error log should already be deleted and set to NULL
                // after committing
                errlCommit(l_err, HWPF_COMP_ID);
            }

        }

    } while (0);

    return l_StepError.getErrorHandle();
}

//*****************************************************************************
// wrapper function to call proc_abus_scominit
//******************************************************************************
void* call_proc_abus_scominit( void    *io_pArgs )
{

    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        "call_proc_abus_scominit entry" );

    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    do
    {

        EDI_EI_INITIALIZATION::TargetPairs_t l_AbusConnections;
        // Note:
        // i_noDuplicate parameter must be set to false because
        // two separate  calls would be needed:
        //    A0 <--> A1
        //    A1 <--> A0
        // only the first target is used to issue SCOMs
        l_err =
        EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().getPbusConnections(
                                          l_AbusConnections, TYPE_ABUS, false);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : getPbusConnections ABUS returns error",
                    l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit the error log
            // Log should be deleted and set to NULL in errlCommit.
            errlCommit(l_err, HWPF_COMP_ID);

            // Shouldn't continue on this fatal error (no ABUS), break out
            break;
        }

        // For each ABUS pair
        for (EDI_EI_INITIALIZATION::TargetPairs_t::iterator 
                l_abusPairIter = l_AbusConnections.begin();
                l_abusPairIter != l_AbusConnections.end();
                ++l_abusPairIter)
        {
            // Make local copies of ABUS targets for ease of use
            TARGETING::Target* l_thisAbusTarget =
                 const_cast<TARGETING::Target*>(l_abusPairIter->first);
            TARGETING::Target* l_connectedAbusTarget =
                 const_cast<TARGETING::Target*>(l_abusPairIter->second);

            // Get this abus fapi taget
            const fapi::Target l_fapi_this_abus_target(
                   TARGET_TYPE_ABUS_ENDPOINT,
                   const_cast<TARGETING::Target*>(l_thisAbusTarget));

            // Get connected abus fapi taget
            const fapi::Target l_fapi_connected_abus_target(
                   TARGET_TYPE_ABUS_ENDPOINT,
                   const_cast<TARGETING::Target*>(l_connectedAbusTarget));

            // Call HW procedure
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_abus_scominit HWP on "
                "Abus target HUID %.8X Connected Abus target HUID %.8X",
                TARGETING::get_huid(l_thisAbusTarget),
                TARGETING::get_huid(l_connectedAbusTarget));

            FAPI_INVOKE_HWP(l_err, proc_abus_scominit,
                            l_fapi_this_abus_target,
                            l_fapi_connected_abus_target);
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR %.8X : proc_abus_scominit HWP returns error. "
                    "Abus target HUID %.8X,  Connected Abus target HUID %.8X",
                    l_err->reasonCode(),
                    TARGETING::get_huid(l_thisAbusTarget),
                    TARGETING::get_huid(l_connectedAbusTarget));

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_thisAbusTarget).addToLog( l_err );
                ErrlUserDetailsTarget(l_connectedAbusTarget).addToLog( l_err );

                // Create IStep error log and cross ref to error that occurred
                l_StepError.addErrorDetails( l_err );
                // We want to continue to the next target instead of exiting,
                // Commit the error log and move on
                // Note: Error log should already be deleted and set to NULL
                // after committing
                errlCommit(l_err, HWPF_COMP_ID);
            }
        } // End abus list loop

    } while (0);

    return l_StepError.getErrorHandle();
}

//******************************************************************************
// _queryIopsToBifurcateAndPhbsToDisable
//******************************************************************************

#ifdef DYNAMIC_BIFURCATION
// Normally a x16 PCIE adapter is driven by one PHB in the processor.
// Some x16 adapters have two logically different devices integrated
// onto the same adapter, each acting as a x8 PCIE endpoint driven by
// its own PHB.  The ability to detect which type of PCIE adapter is
// present and dynamically reconfigure the PCIE langes / PHBs to support
// whatever is present is called 'dynamic bifurcation'.  This feature is
// not officially supported however hooks remain in place to add that
// support easily.  To enable it, define the DYNAMIC_BIFURCATION flag
// and implement the guts of the
// _queryIopsToBifurcateAndPhbsToDisable function.

errlHndl_t _queryIopsToBifurcateAndPhbsToDisable(
    TARGETING::ConstTargetHandle_t const       i_pProcChipTarget,
    BifurcatedIopsContainer&                   o_iopList,
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type& o_disabledPhbsMask)
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "_queryIopsToBifurcateAndPhbsToDisable: Proc chip target "
        "HUID = 0x%08X.",
        i_pProcChipTarget ?
            i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>() : 0);

    errlHndl_t pError = NULL;
    o_iopList.clear();
    o_disabledPhbsMask = 0;

    do {

    // Extension point to return bifurcated IOPs and PHBs to disable.
    // Assuming no extensions are added, the function returns no IOPs to
    // bifurcate and no PHBs to disable

    // If implemented, this function should only return error on software code
    // bug.  Any other condition should result in IOPs not being bifurcated and
    // host taking care of that condition.

    } while(0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        EXIT_MRK "_queryIopsToBifurcateAndPhbsToDisable: EID = 0x%08X, "
        "PLID = 0x%08X, RC = 0x%08X.",
        ERRL_GETEID_SAFE(pError),ERRL_GETPLID_SAFE(pError),
        ERRL_GETRC_SAFE(pError));

    return pError;
}

#endif

//******************************************************************************
// _deconfigPhbsBasedOnPciState
//******************************************************************************

void _deconfigPhbsBasedOnPciState(
    TARGETING::ConstTargetHandle_t const       i_pProcChipTarget,
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type& io_phbActiveMask)
{
    errlHndl_t pError = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "_deconfigPhbsBasedOnPciState: Proc chip target HUID = "
        "0x%08X, PHB active mask = 0x%02X.",
        i_pProcChipTarget ?
            i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>() : 0,
        io_phbActiveMask);

    // Get proc chip's functional PCI units
    TARGETING::TargetHandleList funcPciList;
    (void)TARGETING::getChildChiplets(
        funcPciList,i_pProcChipTarget,TARGETING::TYPE_PCI);

    // Activate PHB mask bits based on functional PCI units
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type activePciMask = 0;
    for (TARGETING::TargetHandleList::const_iterator pciItr
            = funcPciList.begin();
         pciItr != funcPciList.end();
         ++pciItr)
    {
        // PCI chip unit to PHB mapping is as follows:
        //
        // PCI-0 => PHB0
        // PCI-1 => PHB1
        // PCI-2 => PHB2
        //
        // Further, io_phbActiveMask and activePciMask are bitmasks whose
        // leftmost bit corresponds to PHB0, followed by bits for PHB1 and PHB2.
        // The remaining bits are ignored.

        // Compensate for the fact that PHB mask bits start on left side of the
        // mask
        const size_t bitsToLeftShift
            = ((sizeof(activePciMask)*BITS_PER_BYTE) - 1);

        // Committing an error here because this would mean a read only
        // attribute was set to a value which should be impossible, the
        // side effect will be that whatever PHB this should really correspond
        // to will not be enabled
        if((*pciItr)->getAttr<TARGETING::ATTR_CHIP_UNIT>() > bitsToLeftShift)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK "_deconfigPhbsBasedOnPciState> "
                "Code Bug! CHIP_UNIT attribute (%d) for PCI unit with HUID of "
                "0x%08X was larger than max value of %d in "
                "_deconfigPhbsBasedOnPciState().",
                (*pciItr)->getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                (*pciItr)->getAttr<TARGETING::ATTR_HUID>(),
                bitsToLeftShift );
            /*@
             * @errortype
             * @moduleid         ISTEP_DECONFIG_PHBS_BASED_ON_PCI_STATE
             * @reasoncode       ISTEP_TARGET_NULL
             * @userdata1[0:31]  HUID of PCI target with bad ATTR_CHIP_UNIT
             * @userdata1[32:39] ATTR_CHIP_UNIT value
             * @userdata2[40:47] # bits to shift
             * @devdesc          Attribute model inconsistency detected; Cannot
             *                   represent PHB bitmask given the value of the
             *                   PCI target's chip unit attribute.  Continuing
             *                   without PHB enabled
             * @custdesc         A problem isolated to firmware occurred during
             *                   the IPL of the system.
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                ISTEP_DECONFIG_PHBS_BASED_ON_PCI_STATE,
                ISTEP_TARGET_NULL,
                TWO_UINT32_TO_UINT64(
                    (*pciItr)->getAttr<TARGETING::ATTR_HUID>(),
                    TWO_UINT16_TO_UINT32(
                        TWO_UINT8_TO_UINT16(
                            (*pciItr)->getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                            bitsToLeftShift),
                        0)),
                0,
                true);

            ERRORLOG::ErrlUserDetailsTarget(*pciItr).addToLog(pError);
            pError->collectTrace(ISTEP_COMP_NAME);
            errlCommit(pError, ISTEP_COMP_ID);

            continue;
        }

        activePciMask |=
            (1 << (  bitsToLeftShift
                   - (*pciItr)->getAttr<TARGETING::ATTR_CHIP_UNIT>()));
    }

    // Can never enable more PHBs than were supplied as input.  It's conceivable
    // that due to code bug in the chip unit attribute, the unit value
    // corresponds to a non supported PHB.  This masking will also prevent the
    // error from propagating.  There is no way to trap for valid PHBs that are
    // cross-wired vis a vis the chip unit attribute.
    io_phbActiveMask &= activePciMask;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        EXIT_MRK "_deconfigPhbsBasedOnPciState: io_phbActiveMask = 0x%02X",
        io_phbActiveMask);

    return;
}

//******************************************************************************
// Local logical equality operator for matching lane configuration rows
//******************************************************************************

inline bool operator==(
    const laneConfigRow& i_lhs,
    const laneConfigRow& i_rhs)
{
    return ( memcmp(i_lhs.laneSet,i_rhs.laneSet,sizeof(i_lhs.laneSet)) == 0);
}

//******************************************************************************
// _laneMaskToLaneWidth
//******************************************************************************

LaneWidth _laneMaskToLaneWidth(const uint16_t i_laneMask)
{
    LaneWidth laneWidth = LANE_WIDTH_NC;
    if(i_laneMask == LANE_MASK_X16)
    {
        laneWidth = LANE_WIDTH_16X;
    }
    else if(   (i_laneMask == LANE_MASK_X8_GRP0)
            || (i_laneMask == LANE_MASK_X8_GRP1))
    {
        laneWidth = LANE_WIDTH_8X;
    }

    return laneWidth;
}

//******************************************************************************
// computeProcPcieConfigAttrs
//******************************************************************************

errlHndl_t computeProcPcieConfigAttrs(
    TARGETING::TargetHandle_t const i_pProcChipTarget)
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "computeProcPcieConfigAttrs: Proc chip target HUID = "
        "0x%08X.",
        i_pProcChipTarget ?
            i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>() : 0);

    // Currently there are two IOP config tables, one for procs with 24 usable
    // PCIE lanes and one for proces with 32 usable PCIE lanes.  In general, the
    // code accumulates the current configuration of the IOPs from the MRW and
    // other dynamic information (such as bifurcation, etc.), then matches that
    // config to one of the rows in the table.  Once a match is discovered, the
    // IOP config value is pulled from the matching row and set in the
    // attributes.
    const laneConfigRow x24_laneConfigTable[] =
        {{{{{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x0,PHB0_MASK|PHB1_MASK},

         {{{{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}},
           {{LANE_WIDTH_NC,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x0,PHB0_MASK},

         {{{{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x1,PHB0_MASK|PHB1_MASK},

         {{{{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}},
           {{LANE_WIDTH_NC,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x1,PHB0_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x2,PHB0_MASK|PHB1_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x3,PHB0_MASK|PHB1_MASK|PHB2_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}},
           {{LANE_WIDTH_NC,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x3,PHB0_MASK|PHB2_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_ENABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x4,PHB0_MASK|PHB1_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_ENABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x5,PHB0_MASK|PHB1_MASK},

         {{{{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x6,PHB1_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x7,PHB1_MASK|PHB2_MASK},

         {{{{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_8X,DSMP_ENABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x8,PHB1_MASK},

         {{{{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_8X,DSMP_ENABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x9,PHB1_MASK},

         {{{{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0xA,PHB2_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_ENABLE}},
           {{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0xB,PHB1_MASK},

         {{{{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0xC,PHB1_MASK|PHB2_MASK},
        };

    const laneConfigRow* x24_end = x24_laneConfigTable +
        (  sizeof(x24_laneConfigTable)
         / sizeof(x24_laneConfigTable[0]));

    const laneConfigRow x32_laneConfigTable[] =
        {{{{{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}},
           {{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x0,PHB0_MASK|PHB1_MASK},

         {{{{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}}},
             0x1,PHB0_MASK|PHB1_MASK|PHB2_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}},
           {{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x2,PHB0_MASK|PHB1_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}}},
             0x3,PHB0_MASK|PHB1_MASK|PHB2_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_ENABLE}},
           {{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x4,PHB0_MASK|PHB1_MASK},

         {{{{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_ENABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}}},
             0x5,PHB0_MASK|PHB1_MASK|PHB2_MASK},

         {{{{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}},
           {{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x6,PHB0_MASK|PHB1_MASK},

         {{{{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}}},
             0x7,PHB0_MASK|PHB1_MASK|PHB2_MASK},

         {{{{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_8X,DSMP_ENABLE}},
           {{LANE_WIDTH_16X,DSMP_DISABLE},
            {LANE_WIDTH_NC,DSMP_DISABLE}}},
             0x8,PHB1_MASK},

         {{{{LANE_WIDTH_8X,DSMP_ENABLE},
            {LANE_WIDTH_8X,DSMP_ENABLE}},
           {{LANE_WIDTH_8X,DSMP_DISABLE},
            {LANE_WIDTH_8X,DSMP_DISABLE}}},
             0x9,PHB1_MASK|PHB2_MASK},
        };

    const laneConfigRow* x32_end = x32_laneConfigTable +
        (  sizeof(x32_laneConfigTable)
         / sizeof(x32_laneConfigTable[0]));

    errlHndl_t pError = NULL;
    const laneConfigRow* pLaneConfigTableBegin = NULL;
    const laneConfigRow* pLaneConfigTableEnd = NULL;

    do
    {
        if(i_pProcChipTarget == NULL)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK "computeProcPcieConfigAttrs> "
                "Code bug! Input processor target is NULL");

            /*@
             * @errortype
             * @moduleid    ISTEP_COMPUTE_PCIE_CONFIG_ATTRS
             * @reasoncode  ISTEP_TARGET_NULL
             * @devdesc     Caller passed a NULL processor target
             * @custdesc    A problem isolated to firmware occurred during the
             *              IPL of the system.
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                ISTEP_COMPUTE_PCIE_CONFIG_ATTRS,
                ISTEP_TARGET_NULL,
                0,
                0,
                true);
            pError->collectTrace(ISTEP_COMP_NAME);
            break;
        }

        const TARGETING::ATTR_CLASS_type targetClass
            = i_pProcChipTarget->getAttr<TARGETING::ATTR_CLASS>();
        const TARGETING::ATTR_TYPE_type targetType
            = i_pProcChipTarget->getAttr<TARGETING::ATTR_TYPE>();
        const bool targetPresent =
            i_pProcChipTarget->getAttr<TARGETING::ATTR_HWAS_STATE>()
                .present;

        if(   (targetClass != TARGETING::CLASS_CHIP)
           || (targetType != TARGETING::TYPE_PROC)
           || (!targetPresent))
        {
            const TARGETING::ATTR_HUID_type targetHuid
                = i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>();

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK "computeProcPcieConfigAttrs> Code bug!"
                "Input target is not a processor chip or is not present.  "
                "Class = 0x%08X, "
                "Type = 0x%08X, HUID = 0x%08X, Present? = %d",
                targetClass,targetType,
                targetHuid,
                targetPresent);

            /*@
             * @errortype
             * @moduleid         ISTEP_COMPUTE_PCIE_CONFIG_ATTRS
             * @reasoncode       ISTEP_INVALID_TARGET_TYPE
             * @userdata1[0:31]  Illegal target's class
             * @userdata1[32:63] Illegal target's type
             * @userdata2[0:31]  Illegal target's HUID
             * @userdata2[32:63] Illegal target's presence (0=no, 1=yes)
             * @devdesc          Caller passed a non-processor chip target or
             *                   passed a processor chip target that was not
             *                   present
             * @custdesc         A problem isolated to firmware occurred during
             *                   the IPL of the system.
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                ISTEP_COMPUTE_PCIE_CONFIG_ATTRS,
                ISTEP_INVALID_TARGET_TYPE,
                TWO_UINT32_TO_UINT64(
                    targetClass,targetType),
                TWO_UINT32_TO_UINT64(
                    targetHuid,targetPresent),
                true);
            ERRORLOG::ErrlUserDetailsTarget(i_pProcChipTarget).addToLog(pError);
            pError->collectTrace(ISTEP_COMP_NAME);
            break;
        }

        // Pick the appropriate IOP configuration table
        if(   i_pProcChipTarget->getAttr<TARGETING::ATTR_IOP_LANES_PER_PROC>()
           == IOP_LANES_PER_PROC_32X)
        {
            pLaneConfigTableBegin = x32_laneConfigTable;
            pLaneConfigTableEnd = x32_end;
        }
        else if(   i_pProcChipTarget->getAttr<
                       TARGETING::ATTR_IOP_LANES_PER_PROC>()
                == IOP_LANES_PER_PROC_24X)
        {
            pLaneConfigTableBegin = x24_laneConfigTable;
            pLaneConfigTableEnd = x24_end;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK "computeProcPcieConfigAttrs> "
                "Code bug! Unsupported ATTR_IOP_LANES_PER_PROC attribute for "
                "processor with HUID of 0x%08X.  Expected 24 or 32, but read "
                "value of %d.",
                i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>(),
                i_pProcChipTarget->getAttr<
                    TARGETING::ATTR_IOP_LANES_PER_PROC>());

            /*@
             * @errortype
             * @moduleid         ISTEP_COMPUTE_PCIE_CONFIG_ATTRS
             * @reasoncode       ISTEP_INVALID_ATTR_VALUE
             * @userdata1[0:31]  Target's HUID
             * @userdata2[32:63] ATTR_IOP_LANES_PER_PROC attribute value
             * @devdesc          Illegal ATTR_IOP_LANES_PER_PROC attribute read
             *                   from a processor chip target.
             * @custdesc         A problem isolated to firmware or firmware
             *                   customization occurred during the IPL of the
             *                   system.
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                ISTEP_COMPUTE_PCIE_CONFIG_ATTRS,
                ISTEP_INVALID_ATTR_VALUE,
                TWO_UINT32_TO_UINT64(
                    i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>(),
                    i_pProcChipTarget->getAttr<
                        TARGETING::ATTR_IOP_LANES_PER_PROC>()),
                0,
                true);
            ERRORLOG::ErrlUserDetailsTarget(i_pProcChipTarget).addToLog(pError);
            pError->collectTrace(ISTEP_COMP_NAME);
            break;
        }

        TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type disabledPhbs = 0;

#ifdef DYNAMIC_BIFURCATION

        // Figure out which IOPs need bifurcation, and as a result, which PHBs
        // to disable
        BifurcatedIopsContainer iopList;
        pError = _queryIopsToBifurcateAndPhbsToDisable(
            i_pProcChipTarget,
            iopList,
            disabledPhbs);
        if(pError!=NULL)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK "computeProcPcieConfigAttrs> "
                "Failed in call to _queryIopsToBifurcateAndPhbsToDisable; "
                "Proc HUID = 0x%08X.",
                i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>());
            break;
        }
#endif

        // Arrays require all try[Get|Set]Attr API calls in order to be able to
        // read them properly.  All attributes should exist, so assert if they
        // do not.
        TARGETING::ATTR_PROC_PCIE_LANE_MASK_NON_BIFURCATED_type
            laneMaskNonBifurcated = {{0}};
        assert(i_pProcChipTarget->tryGetAttr<
            TARGETING::ATTR_PROC_PCIE_LANE_MASK_NON_BIFURCATED>(
                laneMaskNonBifurcated));

        TARGETING::ATTR_PROC_PCIE_IOP_REVERSAL_NON_BIFURCATED_type
            laneReversalNonBifrucated = {{0}};
        assert(i_pProcChipTarget->tryGetAttr<
            TARGETING::ATTR_PROC_PCIE_IOP_REVERSAL_NON_BIFURCATED>(
                laneReversalNonBifrucated));

        TARGETING::ATTR_PROC_PCIE_IOP_SWAP_NON_BIFURCATED_type
            laneSwapNonBifurcated = {{0}};
        assert(i_pProcChipTarget->tryGetAttr<
            TARGETING::ATTR_PROC_PCIE_IOP_SWAP_NON_BIFURCATED>(
                laneSwapNonBifurcated));

        TARGETING::ATTR_PROC_PCIE_LANE_MASK_type
            effectiveLaneMask = {{0}};
        memcpy(effectiveLaneMask,laneMaskNonBifurcated,
            sizeof(effectiveLaneMask));

        TARGETING::ATTR_PROC_PCIE_IOP_REVERSAL_type
            effectiveLaneReversal = {{0}};
        memcpy(effectiveLaneReversal,laneReversalNonBifrucated,
            sizeof(effectiveLaneReversal));

        TARGETING::ATTR_PROC_PCIE_IOP_SWAP_type
            effectiveLaneSwap = {0};

        // Apply the non-bifurcated lane swap
        for(size_t iop = 0; iop<MAX_IOPS_PER_PROC; ++iop)
        {
            uint8_t laneSwap = 0;
            for(size_t laneGroup = 0;
                laneGroup <
                    (sizeof(laneSwapNonBifurcated)/sizeof(effectiveLaneSwap));
                ++laneGroup)
            {
                // If lanes are used and swap not yet set, then set it
                if(   (effectiveLaneMask[iop][laneGroup])
                   && (!laneSwap))
                {
                    laneSwap =
                        laneSwapNonBifurcated[iop][laneGroup];
                }
            }
            effectiveLaneSwap[iop] = laneSwap;
        }

#ifdef DYNAMIC_BIFURCATION

        TARGETING::ATTR_PROC_PCIE_LANE_MASK_BIFURCATED_type
            laneMaskBifurcated = {{0}};
        assert(i_pProcChipTarget->tryGetAttr<
            TARGETING::ATTR_PROC_PCIE_LANE_MASK_BIFURCATED>(
                laneMaskBifurcated));

        TARGETING::ATTR_PROC_PCIE_IOP_REVERSAL_BIFURCATED_type
            laneReversalBifurcated = {{0}};
        assert(i_pProcChipTarget->tryGetAttr<
            TARGETING::ATTR_PROC_PCIE_IOP_REVERSAL_BIFURCATED>(
                laneReversalBifurcated));

        TARGETING::ATTR_PROC_PCIE_IOP_SWAP_BIFURCATED_type
            bifurcatedSwap = {{0}};
        assert(i_pProcChipTarget->tryGetAttr<
            TARGETING::ATTR_PROC_PCIE_IOP_SWAP_BIFURCATED>(
                bifurcatedSwap));

        // Apply any IOP bifurcation settings
        for(BifurcatedIopsContainer::const_iterator iopItr = iopList.begin();
            iopItr != iopList.end();
            ++iopItr)
        {
            BifurcatedIopsContainer::const_reference iop = *iopItr;
            memcpy(
                &effectiveLaneReversal[iop][0],
                &laneReversalBifurcated[iop][0],
                sizeof(effectiveLaneReversal)/MAX_IOPS_PER_PROC);

            memcpy(
                &effectiveLaneMask[iop][0],
                &laneMaskBifurcated[iop][0],
                sizeof(effectiveLaneMask)/MAX_IOPS_PER_PROC);

            uint8_t laneSwap = 0;
            for(size_t laneGroup=0;
                laneGroup <
                    (sizeof(bifurcatedSwap)/sizeof(effectiveLaneSwap));
                ++laneGroup)
            {
                // If lanes are used and swap not yet set, then set it
                if(   (effectiveLaneMask[iop][laneGroup])
                   && (!laneSwap))
                {
                    laneSwap =
                        bifurcatedSwap[iop][laneGroup];
                }
            }
            effectiveLaneSwap[iop] = laneSwap;
        }
#endif

        i_pProcChipTarget->setAttr<
            TARGETING::ATTR_PROC_PCIE_LANE_MASK>(effectiveLaneMask);

        i_pProcChipTarget->setAttr<
            TARGETING::ATTR_PROC_PCIE_IOP_REVERSAL>(effectiveLaneReversal);

        i_pProcChipTarget->setAttr<
            TARGETING::ATTR_PROC_PCIE_IOP_SWAP>(effectiveLaneSwap);

        TARGETING::ATTR_PROC_PCIE_DSMP_CAPABLE_type
            dsmpCapable = {{0}};
        assert(i_pProcChipTarget->tryGetAttr<
            TARGETING::ATTR_PROC_PCIE_DSMP_CAPABLE>(dsmpCapable));

        TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type phbActiveMask = 0;
        TARGETING::ATTR_PROC_PCIE_IOP_CONFIG_type iopConfig = 0;

        laneConfigRow effectiveConfig =
            {{{{LANE_WIDTH_NC,DSMP_DISABLE},
                {LANE_WIDTH_NC,DSMP_DISABLE}},
               {{LANE_WIDTH_NC,DSMP_DISABLE},
                {LANE_WIDTH_NC,DSMP_DISABLE}}},
               0x0,PHB_MASK_NA};

        // Transform effective config to match lane config table format
        for(size_t iop = 0;
            iop < MAX_IOPS_PER_PROC;
            ++iop)
        {
            for(size_t laneGroup = 0;
                laneGroup < MAX_LANE_GROUPS_PER_IOP;
                ++laneGroup)
            {
                effectiveConfig.laneSet[iop][laneGroup].width
                    = _laneMaskToLaneWidth(effectiveLaneMask[iop][laneGroup]);
                effectiveConfig.laneSet[iop][laneGroup].dsmp
                    = dsmpCapable[iop][laneGroup];
            }
        }

        const laneConfigRow* laneConfigItr =
            std::find(
                pLaneConfigTableBegin,
                pLaneConfigTableEnd,
                effectiveConfig);

        if(laneConfigItr != pLaneConfigTableEnd)
        {
            iopConfig = laneConfigItr->laneConfig;
            phbActiveMask = laneConfigItr->phbActive;

            // Disable applicable PHBs
            phbActiveMask &= (~disabledPhbs);
            (void)_deconfigPhbsBasedOnPciState(
                i_pProcChipTarget,
                phbActiveMask);
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK "computeProcPcieConfigAttrs> "
                "Code bug! Proc PCIE IOP configuration not found.  Continuing "
                "with no PHBs active.  "
                "IOP0 Lane set 0: Lane mask = 0x%04X, DSMP enable = 0x%02X.  "
                "IOP0 Lane set 1: Lane mask = 0x%04X, DSMP enable = 0x%02X.  ",
                effectiveLaneMask[0][0],dsmpCapable[0][0],
                effectiveLaneMask[0][1],dsmpCapable[0][1]);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "IOP1 Lane set 0: Lane mask = 0x%04X, DSMP enable = 0x%02X.  "
                "IOP1 Lane set 1: Lane mask = 0x%04X, DSMP enable = 0x%02X.  ",
                effectiveLaneMask[1][0],dsmpCapable[1][0],
                effectiveLaneMask[1][1],dsmpCapable[1][1]);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Proc chip target HUID = 0x%08X.",
                i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>());
            /*@
             * @errortype
             * @moduleid         ISTEP_COMPUTE_PCIE_CONFIG_ATTRS
             * @reasoncode       ISTEP_INVALID_CONFIGURATION
             * @userdata1[0:31]  Target processor chip's HUID
             * @userdata1[32:39] IOP 0 lane set 0 DSMP enable
             * @userdata1[40:47] IOP 0 lane set 1 DSMP enable
             * @userdata1[48:55] IOP 1 lane set 0 DSMP enable
             * @userdata1[56:63] IOP 1 lane set 1 DSMP enable
             * @userdata2[0:15]  IOP 0 lane set 0 lane mask
             * @userdata2[16:31] IOP 0 lane set 1 lane mask
             * @userdata2[32:47] IOP 1 lane set 0 lane mask
             * @userdata2[48:63] IOP 1 lane set 1 lane mask
             * @devdesc          No valid PCIE IOP configuration found.  All
             *                   PHBs on the processor will be disabled.
             * @custdesc         A problem isolated to firmware or firmware
             *                   customization occurred during the IPL of the
             *                   system.
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                ISTEP_COMPUTE_PCIE_CONFIG_ATTRS,
                ISTEP_INVALID_CONFIGURATION,
                TWO_UINT32_TO_UINT64(
                    i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>(),
                    FOUR_UINT8_TO_UINT32(
                        dsmpCapable[0][0],
                        dsmpCapable[0][1],
                        dsmpCapable[1][0],
                        dsmpCapable[1][1])),
                FOUR_UINT16_TO_UINT64(
                    effectiveLaneMask[0][0],
                    effectiveLaneMask[0][1],
                    effectiveLaneMask[1][0],
                    effectiveLaneMask[1][1]),
                true);
            ERRORLOG::ErrlUserDetailsTarget(i_pProcChipTarget).addToLog(pError);
            pError->collectTrace(ISTEP_COMP_NAME);
            errlCommit(pError, ISTEP_COMP_ID);
        }

        i_pProcChipTarget->setAttr<
            TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE>(phbActiveMask);
        i_pProcChipTarget->setAttr<
            TARGETING::ATTR_PROC_PCIE_IOP_CONFIG>(iopConfig);

    } while(0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        EXIT_MRK "computeProcPcieConfigAttrs: EID = 0x%08X, PLID = 0x%08X, "
        "RC = 0x%08X.",
        ERRL_GETEID_SAFE(pError),ERRL_GETPLID_SAFE(pError),
        ERRL_GETRC_SAFE(pError));

    return pError;
}

//*****************************************************************************
// wrapper function to call proc_pcie_scominit
//******************************************************************************
void*    call_proc_pcie_scominit( void    *io_pArgs )
{
    errlHndl_t          l_errl      =   NULL;
    IStepError          l_StepError;

    bool spBaseServicesEnabled = INITSERVICE::spBaseServicesEnabled();

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for ( TargetHandleList::const_iterator
          l_iter = l_procTargetList.begin();
          l_iter != l_procTargetList.end();
          ++l_iter )
    {
        TARGETING::Target* const l_proc_target = *l_iter;

        // Compute the PCIE attribute config on all non-SP systems, since SP
        // won't be there to do it.
        if(!spBaseServicesEnabled)
        {
            // Unlike SP which operates on all present procs, the SP-less
            // algorithm only needs to operate on functional ones
            l_errl = computeProcPcieConfigAttrs(l_proc_target);
            if(l_errl != NULL)
            {
                // Any failure to configure PCIE that makes it to this handler
                // implies a firmware bug that should be fixed, everything else
                // is tolerated internally (usually as disabled PHBs)
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    ERR_MRK "call_proc_pcie_scominit> Failed in call to "
                    "computeProcPcieConfigAttrs for target with HUID = "
                    "0x%08X",
                    l_proc_target->getAttr<TARGETING::ATTR_HUID>());
                l_StepError.addErrorDetails(l_errl);
                errlCommit( l_errl, ISTEP_COMP_ID );
            }
        }

        const fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                ( const_cast<TARGETING::Target*>(l_proc_target) ));

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_pcie_scominit HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_proc_target));

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_errl, proc_pcie_scominit, l_fapi_proc_target);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X : proc_pcie_scominit HWP returns error",
                      l_errl->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog( l_errl );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );

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
// wrapper function to call proc_scomoverride_chiplets
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

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
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
