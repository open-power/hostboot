/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/nest_chiplets.C $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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


//*****************************************************************************
// wrapper function to call proc_pcie_scominit
//******************************************************************************
void*    call_proc_pcie_scominit( void    *io_pArgs )
{
    errlHndl_t          l_errl      =   NULL;
    IStepError          l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        "call_proc_pcie_scominit entry" );

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
