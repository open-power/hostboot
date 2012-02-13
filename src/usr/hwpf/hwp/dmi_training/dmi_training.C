//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/HWPs/dmi_training/dmi_training.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

/**
 *  @file dmi_training.C
 *
 *  Support file for hardware procedure:
 *      DMI Training
 *
 */

/**
 * @note    "" comments denote lines that should be built from the HWP
 *          tag block.  See the preliminary design in dmi_training.H
 *          Please save.
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>

//  targeting support.
#include    <targeting/attributes.H>
#include    <targeting/entitypath.H>
#include    <targeting/target.H>
#include    <targeting/targetservice.H>
#include    <targeting/iterators/rangefilter.H>
#include    <targeting/predicates/predicatectm.H>
#include    <targeting/predicates/predicatepostfixexpr.H>
#include    <targeting/predicates/predicateisfunctional.H>


//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

//  --  prototype   includes    --
#include    "dmi_training.H"
#include    "proc_cen_framelock.H"
#include    "io_run_training.H"

namespace   DMI_TRAINING
{


using   namespace   TARGETING;
using   namespace   fapi;

//
//  Wrapper function to call 11.1   dmi_scominit
//
void    call_dmi_scominit( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_scominit entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "dmi_scominit exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 11.2 :  dmi_erepair
//
void    call_dmi_erepair( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_erepair entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "dmi_erepair exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

//
//  Wrapper function to call 11.3 : dmi_io_dccal
//
void    call_dmi_io_dccal( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_io_dccal entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "dmi_io_dccal exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 11.4 : dmi_io_run_training
//
void    call_dmi_io_run_training( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;
    TARGETING::TargetService&   l_targetService = targetService();
    uint8_t                     l_cpuNum        =   0;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "dmi_io_run_training entry" );

    //  Use PredicateIsFunctional to filter only functional chips
    TARGETING::PredicateIsFunctional             l_isFunctional;

    //  filter for functional Proc Chips
    TARGETING::PredicateCTM         l_procChipFilter( CLASS_CHIP, TYPE_PROC );
    TARGETING::PredicatePostfixExpr l_functionalAndProcChipFilter;
    l_functionalAndProcChipFilter.push(&l_procChipFilter).push(&l_isFunctional).And();
    TARGETING::TargetRangeFilter    l_cpuFilter(
            l_targetService.begin(),
            l_targetService.end(),
            &l_functionalAndProcChipFilter );

    for ( l_cpuNum=0;   l_cpuFilter;    ++l_cpuFilter, l_cpuNum++ )
    {
        //  make a local copy of the CPU target
        const TARGETING::Target*  l_cpu_target = *l_cpuFilter;

        //  get the mcs chiplets associated with this cpu
        TARGETING::PredicateCTM l_mcsChipFilter(CLASS_UNIT, TYPE_MCS);
        TARGETING::PredicatePostfixExpr l_functionalAndMcsChipFilter;
        l_functionalAndMcsChipFilter.push(&l_mcsChipFilter).push(&l_isFunctional).And();
        TARGETING::TargetHandleList l_mcsTargetList;
        l_targetService.getAssociated(
                l_mcsTargetList,
                l_cpu_target,
                TARGETING::TargetService::CHILD,
                TARGETING::TargetService::IMMEDIATE,
                &l_functionalAndMcsChipFilter );

        for ( uint8_t j=0; j < l_mcsTargetList.size(); j++ )
        {
            //  make a local copy of the MCS target
            const TARGETING::Target*  l_mcs_target = l_mcsTargetList[j];
            uint8_t l_mcsNum    =   l_mcs_target->getAttr<ATTR_CHIP_UNIT>();

            //  find all the Centaurs that are associated with this MCS
            TARGETING::PredicateCTM l_membufChipFilter(CLASS_CHIP, TYPE_MEMBUF);
            TARGETING::PredicatePostfixExpr l_functionalAndMembufChipFilter;
            l_functionalAndMembufChipFilter.push(&l_membufChipFilter).push(&l_isFunctional).And();
            TARGETING::TargetHandleList l_memTargetList;
            l_targetService.getAssociated(
                            l_memTargetList,
                            l_mcs_target,
                            TARGETING::TargetService::CHILD_BY_AFFINITY,
                            TARGETING::TargetService::ALL,
                            &l_functionalAndMembufChipFilter);

            for ( uint8_t k=0, l_memNum=0; k < l_memTargetList.size(); k++, l_memNum++ )
            {
                //  make a local copy of the MEMBUF target
                const TARGETING::Target*  l_mem_target = l_memTargetList[k];

                //  struct containing custom parameters that is fed to HWP
                struct DmiIORunTrainingParms    {
                    io_interface_t master_interface;
                    uint32_t master_group;
                    io_interface_t slave_interface;
                    uint32_t slave_group;
                }   l_CustomParms[] =
                {       { /*MCS0*/ CP_IOMC0_P0, 3, CEN_DMI, 0 },
                        { /*MCS1*/ CP_IOMC0_P1, 2, CEN_DMI, 0 },
                        { /*MCS2*/ CP_IOMC0_P2, 1, CEN_DMI, 0 },
                        { /*MCS3*/ CP_IOMC0_P3, 0, CEN_DMI, 0 },
                        { /*MCS4*/ CP_IOMC1_P0, 3, CEN_DMI, 0 },
                        { /*MCS5*/ CP_IOMC1_P1, 2, CEN_DMI, 0 },
                        { /*MCS6*/ CP_IOMC1_P2, 1, CEN_DMI, 0 },
                        { /*MCS7*/ CP_IOMC1_P3, 0, CEN_DMI, 0 },
                };
                //  call the HWP with each target   ( if parallel, spin off a task )
                const fapi::Target l_fapi_master_target(
                        TARGET_TYPE_PROC_CHIP,
                        reinterpret_cast<void *>
                ( const_cast<TARGETING::Target*>(l_cpu_target) )
                );
                const fapi::Target l_fapi_slave_target(
                        TARGET_TYPE_MEMBUF_CHIP,
                        reinterpret_cast<void *>
                (const_cast<TARGETING::Target*>(l_mem_target))
                );

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "===== Call dmi_io_run_training HWP( cpu 0x%x, mcs 0x%x, mem 0x%x ) : ",
                        l_cpuNum,
                        l_mcsNum,
                        l_memNum );

                EntityPath l_path;
                l_path = l_cpu_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
                l_path  =   l_mcs_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
                l_path  =   l_mem_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "===== " );

                l_fapirc  =   io_run_training(
                        l_fapi_master_target,
                        l_CustomParms[l_mcsNum].master_interface,
                        l_CustomParms[l_mcsNum].master_group,
                        l_fapi_slave_target,
                        l_CustomParms[l_mcsNum].slave_interface,
                        l_CustomParms[l_mcsNum].slave_group    );

                //  process return code.
                if ( l_fapirc == fapi::FAPI_RC_SUCCESS )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "SUCCESS :  io_run_training HWP( cpu 0x%x, mcs 0x%x, mem 0x%x ) ",
                            l_cpuNum,
                            l_mcsNum,
                            l_memNum );
                }
                else
                {
                    /**
                     * @todo fapi error - just print out for now...
                     */
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "ERROR %d :  io_run_training HWP( cpu 0x%x, mcs 0x%x, mem 0x%x ) ",
                            static_cast<uint32_t>(l_fapirc),
                            l_cpuNum,
                            l_mcsNum,
                            l_memNum );
                }
            }  //end for l_mem_target

        }   // end for l_mcs_target

    }   // end for l_cpu_target


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_io_run_training exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 11.5 : host_startPRD_dmi
//
void    call_host_startPRD_dmi( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_startPRD_dmi entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_startPRD_dmi exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 11.6 : host_attnlisten_cen
//
void    call_host_attnlisten_cen( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_attnlisten_cen entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "<host_attnlisten_cen exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

//
//  Wrapper function to call 11.7 : proc_cen_framelock
//
void    call_proc_cen_framelock( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode            l_fapirc;
    proc_cen_framelock_args     l_args;
    TARGETING::TargetService&   l_targetService = targetService();
    uint8_t                     l_cpuNum        =   0;

    //  Use PredicateIsFunctional to filter only functional chips
    TARGETING::PredicateIsFunctional    l_isFunctional;


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_cen_framework entry" );

    TARGETING::PredicateCTM         l_procChipFilter( CLASS_CHIP, TYPE_PROC );
    TARGETING::PredicatePostfixExpr l_functionalAndProcChipFilter;
    l_functionalAndProcChipFilter.push(&l_procChipFilter).push(&l_isFunctional).And();
    TARGETING::TargetRangeFilter    l_cpuFilter(
            l_targetService.begin(),
            l_targetService.end(),
            &l_functionalAndProcChipFilter );

    for ( l_cpuNum=0;   l_cpuFilter;    ++l_cpuFilter, l_cpuNum++ )
    {
        //  make a local copy of the CPU target
        const TARGETING::Target*  l_cpu_target = *l_cpuFilter;

        //  get the mcs chiplets associated with this cpu
        TARGETING::PredicateCTM l_mcsChipFilter(CLASS_UNIT, TYPE_MCS);
        TARGETING::PredicatePostfixExpr l_functionalAndMcsChipFilter;
        l_functionalAndMcsChipFilter.push(&l_mcsChipFilter).push(&l_isFunctional).And();
        TARGETING::TargetHandleList l_mcsTargetList;
        l_targetService.getAssociated(
                                    l_mcsTargetList,
                                    l_cpu_target,
                                    TARGETING::TargetService::CHILD,
                                    TARGETING::TargetService::IMMEDIATE,
                                    &l_functionalAndMcsChipFilter );

        for ( uint8_t j=0; j < l_mcsTargetList.size(); j++ )
        {
            //  make a local copy of the MCS target
            const TARGETING::Target*  l_mcs_target = l_mcsTargetList[j];

            uint8_t l_mcsNum    =   l_mcs_target->getAttr<ATTR_CHIP_UNIT>();

            //  find all the Centaurs that are associated with this MCS
            TARGETING::PredicateCTM l_membufChipFilter(CLASS_CHIP, TYPE_MEMBUF);
            TARGETING::PredicatePostfixExpr l_functionalAndMembufChipFilter;
            l_functionalAndMembufChipFilter.push(&l_membufChipFilter).push(&l_isFunctional).And();
            TARGETING::TargetHandleList l_memTargetList;
            l_targetService.getAssociated(l_memTargetList,
                                          l_mcs_target,
                                          TARGETING::TargetService::CHILD_BY_AFFINITY,
                                          TARGETING::TargetService::ALL,
                                          &l_functionalAndMembufChipFilter);

            for ( uint8_t k=0, l_memNum=0; k < l_memTargetList.size(); k++, l_memNum++ )
            {
                //  make a local copy of the MEMBUF target
                const TARGETING::Target*  l_mem_target = l_memTargetList[k];


                // fill out the args struct.
                 l_args.mcs_pu               =   l_mcsNum;
                 l_args.in_error_state       =   false;
                 l_args.channel_init_timeout =   CHANNEL_INIT_TIMEOUT_NO_TIMEOUT;
                 l_args.frtl_auto_not_manual =   true;
                 l_args.frtl_manual_pu       =   0;
                 l_args.frtl_manual_mem      =   0;

                // Create compatable FAPI Targets from the vanilla targets,
                //  and invoke the HWP.
                fapi::Target l_fapiCpuTarget(
                        TARGET_TYPE_PROC_CHIP,
                        reinterpret_cast<void *>
                            ( const_cast<TARGETING::Target*>(l_cpu_target) )
                        );
                fapi::Target l_fapiMemTarget(
                        TARGET_TYPE_MEMBUF_CHIP,
                        reinterpret_cast<void *>
                            (const_cast<TARGETING::Target*>(l_mem_target))
                        );

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "===== Call proc_cen_framelock HWP( cpu 0x%x, mcs 0x%x, mem 0x%x ) : ",
                        l_cpuNum,
                        l_mcsNum,
                        l_memNum );
                EntityPath l_path;
                l_path = l_cpu_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
                l_path  =   l_mcs_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
                l_path  =   l_mem_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "===== " );

                // finally!
                l_fapirc =  proc_cen_framelock(
                                    l_fapiCpuTarget,
                                    l_fapiMemTarget,
                                    l_args );

                if ( l_fapirc == fapi::FAPI_RC_SUCCESS )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "SUCCESS :  proc_cen_framelock HWP( cpu 0x%x, mcs 0x%x, mem 0x%x ) ",
                            l_cpuNum,
                            l_mcsNum,
                            l_memNum );
                }
                else
                {
                    /**
                     * @todo fapi error - just print out for now...
                     */
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR %d : proc_cen_framelock HWP( cpu 0x%x, mcs 0x%x, mem 0x%x )",
                    static_cast<uint32_t>(l_fapirc),
                    l_cpuNum,
                    l_mcsNum,
                    l_memNum );
                }
            }   // end mem
        }   // end mcs
    }   //  end cpu

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_cen_framework exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 11.8 : cen_set_inband_addr
//
void    call_cen_set_inband_addr( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_set_inband_addr entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "cen_set_inband_addr exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


};   // end namespace

