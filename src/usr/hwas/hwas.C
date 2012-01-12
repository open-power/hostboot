//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwas/hwas.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
 *  @file hwas.C
 *
 *  HardWare Availability Service functions.
 *  See hwas.H for doxygen documentation tags.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <kernel/console.H>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <targeting/targetservice.H>
#include    <targeting/iterators/rangefilter.H>
#include    <targeting/predicates/predicatectm.H>
#include    <fsi/fsiif.H>

#include    <hwas/hwas.H>
#include    <hwas/deconfigGard.H>
#include    <targeting/util.H>

namespace   HWAS
{
trace_desc_t *g_trac_hwas = NULL;
TRAC_INIT(&g_trac_hwas, "HWAS", 2048 );

using   namespace   TARGETING;


void    init_target_states( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    TARGETING::HwasState l_hwasState;

    TRACDCOMP( g_trac_hwas, "init_target_states entry: set default HWAS state:" );

    //  loop through all the targets and set HWAS_STATE to a known default
    TARGETING::TargetIterator l_TargetItr = TARGETING::targetService().begin();
    for(    ;
            l_TargetItr != TARGETING::targetService().end();
            ++l_TargetItr
    )
    {
        l_hwasState =   l_TargetItr->getAttr<ATTR_HWAS_STATE>();
        l_hwasState.poweredOn             =   false;
        l_hwasState.present               =   false;
        l_hwasState.functional            =   false;
        l_hwasState.changedSinceLastIPL   =   false;
        l_hwasState.gardLevel             =   0;
        l_TargetItr->setAttr<ATTR_HWAS_STATE>( l_hwasState );
    }



    /**
     * @todo    Enable cpu 0 and centaur 0 for now.
     */
    //  $$$$$   TEMPORARY   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    //  get the master processor, this should be CPU 0
    TARGETING::Target* l_pMasterProcChipTargetHandle = NULL;
    (void)TARGETING::targetService().masterProcChipTargetHandle(
            l_pMasterProcChipTargetHandle);
    if (l_pMasterProcChipTargetHandle == NULL)
    {
        TRACFCOMP( g_trac_hwas, "FAILED to get master processor target");
    }
    else
    {
        //  set master chip to poweredOn, present, functional

        l_hwasState =   l_pMasterProcChipTargetHandle->getAttr<ATTR_HWAS_STATE>();
        l_hwasState.poweredOn             =   true;
        l_hwasState.present               =   true;
        l_hwasState.functional            =   true;
        l_hwasState.changedSinceLastIPL   =   false;
        l_hwasState.gardLevel             =   0;
        l_pMasterProcChipTargetHandle->setAttr<ATTR_HWAS_STATE>( l_hwasState );

        //  get the mcs "chiplets" associated with this cpu
        TARGETING::PredicateCTM l_mcsChipFilter(CLASS_UNIT, TYPE_MCS);
        TARGETING::TargetHandleList l_mcsTargetList;
        TARGETING::targetService().getAssociated(
                l_mcsTargetList,
                l_pMasterProcChipTargetHandle,
                TARGETING::TargetService::CHILD,
                TARGETING::TargetService::IMMEDIATE,
                &l_mcsChipFilter );
        //  debug...
        TRACDCOMP( g_trac_hwas,
                "%d MCSs for master processor",
                l_mcsTargetList.size() );

        for ( uint8_t i=0; i < l_mcsTargetList.size(); i++ )
        {
            //  set each MCS to poweredON, present, functional
            l_hwasState =   l_mcsTargetList[i]->getAttr<ATTR_HWAS_STATE>();
            l_hwasState.poweredOn             =   true;
            l_hwasState.present               =   true;
            l_hwasState.functional            =   true;
            l_hwasState.changedSinceLastIPL   =   false;
            l_hwasState.gardLevel             =   0;
            l_mcsTargetList[i]->setAttr<ATTR_HWAS_STATE>( l_hwasState );


            //  If ATTR_CHIP_UNIT==0 or 1, find the centaur underneath it
            //  and set it to good as well.
            if (    ( l_mcsTargetList[i]->getAttr<ATTR_CHIP_UNIT>() == 0 )
                 || ( l_mcsTargetList[i]->getAttr<ATTR_CHIP_UNIT>() == 1 )
                )
            {
                TARGETING::PredicateCTM l_membufChips(CLASS_CHIP, TYPE_MEMBUF);
                TARGETING::TargetHandleList l_memTargetList;
                TARGETING::targetService().getAssociated(l_memTargetList,
                        l_mcsTargetList[i],
                        TARGETING::TargetService::CHILD_BY_AFFINITY,
                        TARGETING::TargetService::ALL,
                        &l_membufChips);
                //  debug...
                TRACDCOMP( g_trac_hwas,
                        "%d MEMBUFSs associated with MCS %d",
                        l_memTargetList.size(),
                        l_mcsTargetList[i]->getAttr<ATTR_CHIP_UNIT>() );

                for ( uint8_t ii=0; ii < l_memTargetList.size(); ii++ )
                {
                    // set the Centaur(s) connected to MCS0 to poweredOn,
                    //      present, functional
                    l_hwasState =   l_memTargetList[ii]->getAttr<ATTR_HWAS_STATE>();
                    l_hwasState.poweredOn             =   true;
                    l_hwasState.present               =   true;
                    l_hwasState.functional            =   true;
                    l_hwasState.changedSinceLastIPL   =   false;
                    l_hwasState.gardLevel             =   0;
                    l_memTargetList[ii]->setAttr<ATTR_HWAS_STATE>( l_hwasState );
                }   // end for
            }   // end if
        }   // end for
    }   // end else
    //  $$$$$   TEMPORARY   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


void    init_fsi( void *io_pArgs )
{
    errlHndl_t  l_errl      =   NULL;
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "init_fsi entry" );

    l_errl  =   FSI::initializeHardware( );
    if ( l_errl )
    {
        TRACFCOMP( g_trac_hwas, "ERROR: failed to init FSI hardware" );
        pTaskArgs->postErrorLog( l_errl );
    }

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

void    apply_fsi_info( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "apply_fsi_info entry" );


    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

void    apply_dd_presence( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "apply_dd_presence entry" );


    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

void    apply_pr_keyword_data( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "apply_pr_keyword_data" );


    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

void    apply_partial_bad( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "apply_partial_bad entry" );


    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

void    apply_gard( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );

    TRACDCOMP( g_trac_hwas, "apply_gard entry" );

    errlHndl_t l_errl = theDeconfigGard().clearGardRecordsForReplacedTargets();

    if (l_errl)
    {
        TRACFCOMP(g_trac_hwas, "ERROR: apply_gard failed to clear GARD Records for replaced Targets");
        pTaskArgs->postErrorLog(l_errl);
    }
    else
    {
        l_errl = theDeconfigGard().deconfigureTargetsFromGardRecordsForIpl();

        if (l_errl)
        {
            TRACFCOMP(g_trac_hwas, "ERROR: apply_gard failed to deconfigure Targets from GARD Records for IPL");
            pTaskArgs->postErrorLog(l_errl);
        }
        else
        {
            TRACFCOMP(g_trac_hwas, "apply_gard completed successfully");
        }
    }

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


};   // end namespace

