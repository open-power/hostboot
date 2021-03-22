/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodSvc.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
 *  @file TodSvc.C
 *
 *  @brief Implements the TodSvc class that provides the Time Of Day service
 */


//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
//Service Processor components outside
//#include <mboxclientlib.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <arch/magic.H>
#include "TodSvc.H"
#include "TodControls.H"
#include "TodProc.H"
#include "TodTopologyManager.H"
#include "TodTrace.H"

#include "TodHwpIntf.H"
#include "TodSvcUtil.H"

#include <p10_tod_utils.H>
#include <p10_scom_perv_a.H>
#include <isteps/tod_init_reasoncodes.H>
#include "TodUtils.H"

namespace TOD
{

TodSvc & TodSvc::getTheInstance()
{
    return Singleton<TodSvc>::instance();
}

//******************************************************************************
//TodSvc::todSetup
//******************************************************************************
errlHndl_t TodSvc::todSetup()
{
    TOD_ENTER("TodSvc::todSetup");

    errlHndl_t l_errHdl = nullptr;
    bool l_isTodRunning = false;
    TodTopologyManager l_primary(TOD_PRIMARY);

    do
    {
        bool l_inMPIPLPath = false;
        l_errHdl = isMPIPL(l_inMPIPLPath);
        if (l_errHdl)
        {
            TOD_ERR("Failed to check if in MPIPL path or not");
            break;
        }
        if (false == l_inMPIPLPath)
        {
            l_errHdl = TOD::isTodRunning(l_isTodRunning);
            if (l_errHdl)
            {
                TOD_INF("Call to isTodRunning failed, cannot create topology");
                break;
            }

            if (l_isTodRunning)
            {
                TOD_ERR("Cannot create TOD topology while the Chip TOD logic"
                        "is running ");
                /*@
                 * @errortype
                 * @moduleid     TOD_SETUP
                 * @reasoncode   TOD_INVALID_ACTION
                 * @userdata1    ChipTOD logic HW state, 1=running,
                 *               zero otherwise
                 * @devdesc      Error: Creation of TOD topology required when
                 *               TOD HW is running
                 * @custdesc     Host failed to boot because there was a problem
                 *               configuring Time Of Day on the Host processors
                 */
                l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_SETUP,
                               TOD_INVALID_ACTION,
                               l_isTodRunning);

                break;

            }
        }

        TOD::destroy(TOD_PRIMARY);
        TOD::destroy(TOD_SECONDARY);

        //Build the list of garded TOD targets
        l_errHdl = TOD::buildGardedTargetsList();
        if (l_errHdl)
        {
            TOD_ERR("Call to buildGardedTargetsList failed");
            break;
        }

        //Build a set of datastructures to setup creation of the TOD topology

        //We're going to setup TOD for this IPL
        //1) Build a set of datastructures to setup creation of the TOD
        //topologies.
        l_errHdl = TOD::buildTodDrawers(TOD_PRIMARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: failed to build TOD drawers "
                    "for primary topology.");
            break;
        }

        //2) Ask the topology manager to setup the primary topology
        l_errHdl = l_primary.create();
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: failed to create primary topology.");
            break;
        }
        l_primary.dumpTopology();

        //3) Call hardware procedures to configure the TOD hardware logic for
        //the primary topology and to fill up the TOD regs.

        l_errHdl = todSetupHwp(TOD_PRIMARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: primary topology setup HWP.");
            break;
        }

        l_errHdl = todSaveRegsHwp(TOD_PRIMARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: primary topology register save HWP.");
            break;
        }

        //Primary successfully configured
        TOD::setConfigStatus(TOD_PRIMARY,true);

#ifdef CONFIG_ENABLE_TOD_REDUNDANCY
        //Build datastructures for secondary topology
        l_errHdl = TOD::buildTodDrawers(TOD_SECONDARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: failed to build TOD drawers "
                     "for secondary topology.");
            //Report the error as informational - loss of redundancy,
            //but no loss of TOD function.
            errlCommit(l_errHdl, TOD_COMP_ID);
            break;
        }

        //4) Ask the topology manager to setup the secondary topology
        TodTopologyManager l_secondary(TOD_SECONDARY);
        l_errHdl = l_secondary.create();
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: failed to create secondary topology.");
            //Report the error as informational - loss of redundancy,
            //but no loss of TOD function.
            errlCommit(l_errHdl, TOD_COMP_ID);
            break;
        }
        l_secondary.dumpTopology();

        //5) Call hardware procedures to configure the TOD hardware logic for
        //the secondary topology and to fill up the TOD regs.

        l_errHdl = todSetupHwp(TOD_SECONDARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: secondary topology setup HWP.");
            //Report the error as informational - loss of redundancy,
            //but no loss of TOD function.
            errlCommit(l_errHdl, TOD_COMP_ID);
            break;
        }

        //Secondary successfully configured
        TOD::setConfigStatus(TOD_SECONDARY,true);
#endif

        //Need to call this again if the secondary topology got set up,
        //that would have updated more regs.
        l_errHdl = todSaveRegsHwp(TOD_PRIMARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure: primary topology register save HWP.");
            break;
        }
        //Done with TOD setup
    }while(0);

    if((nullptr == l_errHdl) &&
       (false ==  l_isTodRunning ))
    {
        l_primary.dumpTodRegs();

        //If we are here then atleast Primary or both configurations were
        //successfully setup. If both were successfuly setup then we can use
        //writeTodProcData for either of them else we should call
        //writeTodProcData for only primary.
        //Ultimately it should be good enough to call the method for Primary
        l_errHdl = TOD::writeTodProcData(TOD_PRIMARY);
        if(l_errHdl)
        {
            TOD_ERR("TOD setup failure:Failed to write topology register data"
            " to the file.");
        }
    }

    TOD::clearGardedTargetsList();

    TOD_EXIT("TodSvc::todSetup");

    return l_errHdl;
}


//******************************************************************************
//TodSvc::readTod
//******************************************************************************
errlHndl_t TodSvc::readTod(uint64_t& o_todValue) const
{
    TOD_ENTER("readTod");

    errlHndl_t l_errHdl = nullptr;
    do
    {
        TARGETING::Target*  l_mdmtOnActiveTopology = nullptr;
        bool l_isTodRunning = false;
        bool l_getTodRunningStatus =  false;
        p10_tod_setup_tod_sel l_activeConfig = TOD_PRIMARY;

        //Get the currently active TOD configuration
        //Don't bother about the TOD runing state, caller should have asked for
        //readTOD in correct state.
        l_errHdl = TOD::queryActiveConfig(
                l_activeConfig,l_isTodRunning,
                l_mdmtOnActiveTopology,
                l_getTodRunningStatus);
        if ( l_errHdl )
        {
            TOD_ERR("Call to queryActiveConfig failed ");
            break;
        }

        TOD_INF(" Active topology %d, HUID of MDMT 0x%08X ",
                l_activeConfig,
                GETHUID(l_mdmtOnActiveTopology));


        //SCOM the TOD value reg
        fapi2::variable_buffer o_todValueBuf(64);
        l_errHdl = todGetScom(l_mdmtOnActiveTopology,
                              scomt::perv::TOD_VALUE_REG,
                              o_todValueBuf);

        if(l_errHdl)
        {
            TOD_ERR("TOD read error: failed to SCOM TOD value register "
                    "address 0x%.16llX on MDMT 0x%.8X.",
                    scomt::perv::TOD_VALUE_REG,
                    GETHUID(l_mdmtOnActiveTopology));
            break;
        }
        o_todValue = o_todValueBuf.get<int32_t>(0);
    }while(0);

    TOD_EXIT("readTod");

    return l_errHdl;
}

//******************************************************************************
//TodSvc::TodSvc
//******************************************************************************
TodSvc::TodSvc()
{
    TOD_ENTER("TodSvc constructor");

    TOD_EXIT("TodSvc constructor");
}

//******************************************************************************
//TodSvc::~TodSvc
//******************************************************************************
TodSvc::~TodSvc()
{
    TOD_ENTER("TodSvc destructor");

    //Free up held memory
    TOD::destroy(TOD_PRIMARY);
    TOD::destroy(TOD_SECONDARY);

    TOD_EXIT("TodSvc destructor");
}

//******************************************************************************
//TodSvc::todInit
//******************************************************************************
errlHndl_t TodSvc::todInit()
{
    TOD_ENTER("TodSvc::todInit");
    errlHndl_t l_errHdl = nullptr;
    bool l_isTodRunning = false;
    do
    {
        //Check if the Chip TOD logic is already Running
        l_errHdl = TOD::isTodRunning(l_isTodRunning);
        if ( l_errHdl )
        {
            TOD_INF("Call to isTodRunning() failed , cannot initialize the"
            "Chip TOD logic ");
            break;
        }

        if ( l_isTodRunning )
        {
            TOD_ERR("Cannot initialize the TOD logic while the Chip TOD logic"
                    "is already running");
            /*@
             * @errortype
             * @moduleid     TOD_INIT_ALREADY_RUNNING
             * @reasoncode   TOD_INVALID_ACTION
             * @userdata1    EMOD_TOD_INIT
             * @userdata2    ChipTOD logic HW state, 1=running,
             *               zero otherwise
             * @devdesc      Error: Initialization of chip TOD logic cannot be
             *               done when its already in the running state
             * @custdesc     Host failed to boot because there was a problem
             *               configuring Time Of Day on the Host processors
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_INIT_ALREADY_RUNNING,
                               TOD_INVALID_ACTION,
                               EMOD_TOD_INIT,
                               l_isTodRunning);

            break;

        }

        //Call the hardware procedure to initialize the Chip TOD logic to the
        //running state using the PRIMARY TOD topology.
        l_errHdl = todInitHwp();
        if( l_errHdl )
        {
            TOD_ERR("TOD initialization failed for primary topology : HWP");
            l_errHdl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            //@FIXME-RTC:254475-Remove once this works everywhere
            if( MAGIC_INST_CHECK_FEATURE(MAGIC_FEATURE__IGNORETODFAIL) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "WORKAROUND> Ignoring error for now - TodSvc::todInit" );
                l_errHdl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            }
            errlCommit(l_errHdl, TOD_COMP_ID);
            break;
        }

    }while(0);
    TOD_EXIT("TodSvc::todInit");
    return l_errHdl;
}

//******************************************************************************
//TodSvc::setActiveMdmtForResetBackup
//******************************************************************************
errlHndl_t TodSvc::setActiveMdmtForResetBackup(
        const p10_tod_setup_tod_sel i_activeConfig)
{
    TOD_ENTER("setActiveMdmtForResetBackup");
    errlHndl_t  l_errHdl = nullptr;

    //While doing a resetBackup it was found that in memory copy of active
    //topology is not present, (system has done a RR )
    //In order to ensure redundancy of processor and oscillator source on the
    //backup topology we needed to have the copy of active topology in memory.

    //However we may not need to recreate the complete active topology from
    //the persistant topology information file.
    //It would be just sufficient if we have the todControls built and MDMT set

    do{

        l_errHdl = TOD::buildTodDrawers(i_activeConfig);
        if ( l_errHdl )
        {
            TOD_ERR("Failed to build TOD drawers for %s",
                    (TOD::TodSvcUtil::
                     topologyTypeToString(i_activeConfig)));
            break;
        }

        TARGETING::Target* l_primaryMdmt = nullptr;
        TARGETING::Target* l_secondaryMdmt = nullptr;

        //Read the HW to get the configured MDMT's
        l_errHdl = TOD::getConfiguredMdmt(l_primaryMdmt,
                                          l_secondaryMdmt);
        if ( l_errHdl )
        {
            TOD_ERR("Failed to get the configured MDMTs ");
            break;
        }

        TARGETING::Target* l_mdmtOnActiveTopology = nullptr;
        l_mdmtOnActiveTopology = ( i_activeConfig ==  TOD_PRIMARY )?
            l_primaryMdmt : l_secondaryMdmt;

        if ( !l_mdmtOnActiveTopology ) //Big problem--This should not happen

        {
            TOD_ERR("TOD HW logic is already running but we cannot locate"
                    "MDMT for the %s , that is active",
                    (TOD::TodSvcUtil::
                     topologyTypeToString(i_activeConfig)));
            /*@
             * @errortype
             * @moduleid     TOD_MDMT_TOPOLOGY
             * @reasoncode   TOD_NO_VALID_MDMT_FOUND
             * @userdata1    EMOD_TOD_SET_ACTIVE_MDMT
             * @userdata2    Topology type on which MDMT was searched
             * @devdesc      Error: Could not find MDMT on active topology
             *               even though TOD HW logic is running
             * @custdesc     Host failed to boot because there was a problem
             *               configuring Time Of Day on the Host processors
             */

            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_MDMT_TOPOLOGY,
                               TOD_NO_VALID_MDMT_FOUND,
                               EMOD_TOD_SET_ACTIVE_MDMT,
                               i_activeConfig);
            break;

        }

        //We have the valid MDMT target now, find the TodProc object
        //corresponding to it and also figure out the TodDrawer object to
        //which this processor belongs

        //To do so get the TodProc object whose HUID matches with the HUID
        //of the active topology's MDMT, and also get the TOD drawer to which
        //this TodProc object belongs
        TodDrawer* l_masterDrawer = nullptr;
        TodProc* l_masterProc = nullptr;
        std::list<TodDrawer*> l_drawerList;
        TOD::getDrawers(i_activeConfig, l_drawerList);

        bool l_drawerFound = false;

        for(std::list<TodDrawer*>::iterator l_drawerItr =
                l_drawerList.begin();
                ((l_drawerItr != l_drawerList.end()) && !l_drawerFound);
                ++l_drawerItr)
        {
            const std::list<TodProc*>& l_procsList =
                (*l_drawerItr)->getProcs();
            for(std::list<TodProc*>::const_iterator l_procItr =
                    l_procsList.begin();
                    ((l_procItr != l_procsList.end()) && !l_drawerFound);
                    ++l_procItr)
            {
                if (
                        (*l_procItr)->getTarget()
                        ==
                        l_mdmtOnActiveTopology)
                {
                    l_masterProc = *l_procItr;
                    l_masterDrawer = *l_drawerItr;
                    l_drawerFound = true;
                }

            }

        }

        if ( !l_masterProc || !l_masterDrawer )
        {

            //This should never happen unless we have goofed up big time

            TOD_ERR("Could not find TOD objects for the configured "
                    "MDMT 0x%08X on %s",
                    GETHUID(l_mdmtOnActiveTopology),
                    (TOD::TodSvcUtil::
                     topologyTypeToString(i_activeConfig)));

            bool l_masterProcNotFound = ( !l_masterProc )? true : false;
            bool l_masterDrawerNotFound = ( !l_masterDrawer )? true : false;

            /*@
             * @errortype
             * @moduleid     TOD_FIND_MASTER_PROC
             * @reasoncode   TOD_MASTER_TARGET_NOT_FOUND
             * @userdata1[32:64] 1 = Master proc was not found , zero otherwise
             * @userdata1[32:63] 1 = Master drawer was not found, zero otherwise
             * @userdata2[0:31]  EMOD_TOD_SET_ACTIVE_MDMT
             * @userdata2[32:64] Active topology
             * @devdesc      Either processor or drawer object was not found for
             *               the  MDMT found by reading the processor registers.
             * @custdesc     Service Processor Firmware encountered an internal
             *               error
             */

            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_FIND_MASTER_PROC,
                               TOD_MASTER_TARGET_NOT_FOUND,
                               TWO_UINT32_TO_UINT64(
                                   l_masterProcNotFound,
                                   l_masterDrawerNotFound),
                               TWO_UINT32_TO_UINT64(
                                   EMOD_TOD_SET_ACTIVE_MDMT,
                                   i_activeConfig));
            break;

        }

        //Now we have the all the objects required to set the MDMT
        (void) TOD::setMdmtOfActiveConfig(
                i_activeConfig,
                l_masterProc,
                l_masterDrawer);

    }while(0);

    TOD_EXIT("setActiveMdmtForResetBackup");
    return l_errHdl;
}

errlHndl_t TodSvc::isMPIPL( bool& o_mpIPL )
{
    TOD_ENTER("isMPIPL");

    errlHndl_t l_errHdl = nullptr;
    o_mpIPL = false;

    do{
        // Get the top level (system) target handle to check if MPIPL
        TARGETING::Target* l_pTopLevelTarget = nullptr;
        (void)TARGETING::targetService().getTopLevelTarget(l_pTopLevelTarget);
        if(nullptr == l_pTopLevelTarget)
        {
            /*@
             * @errortype
             * @moduleid     TOD_IS_MPIPL
             * @reasoncode   TOD_TOP_LEVEL_TARGET_NOT_FOUND
             * @devdesc      Top level Target not found
             * @custdesc     Service Processor Firmware encountered an internal
             *               error
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_IS_MPIPL,
                               TOD_TOP_LEVEL_TARGET_NOT_FOUND);

            TOD_ERR_ASSERT("Error getting top level target");
            break;
        }
        if(true == l_pTopLevelTarget->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
        {
            TOD_INF("In MPIPL path");
            o_mpIPL = true;
        }
    }while(0);

    TOD_EXIT( "isMPIPL: Output Params - o_mpIPL: %d", o_mpIPL );

    return l_errHdl;
}

// Wrapper function for TodSvc::todInit instance
errlHndl_t todInit()
{
    return  Singleton<TodSvc>::instance().todInit();
}

// Wrapper function for TodSvc::todInit instance
errlHndl_t todSetup()
{
    return  Singleton<TodSvc>::instance().todSetup();
}

} //namespace TOD
