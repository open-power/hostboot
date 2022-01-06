/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodControls.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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

//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
//Standard library
#include <list>

#include <targeting/common/attributes.H>

//Targeting support
#include <targeting/common/targetservice.H>
#include <targeting/common/util.H>
#include "TodProc.H"
#include "TodDrawer.H"
#include "TodSvcUtil.H"
#include "TodControls.H"
#include "TodTrace.H"
#include "TodUtils.H"
#include <devicefw/userif.H>
#include <hwas/common/deconfigGard.H>
//HWPF
#include <plat_hwp_invoker.H>
#include <p10_scom_perv_d.H>
#include <p10_tod_utils.H>
#include <errl/errlentry.H>
#include <errl/errludtarget.H>
#include <isteps/tod_init_reasoncodes.H>

using namespace TARGETING;
using namespace scomt;
using namespace perv;

namespace TOD
{

//------------------------------------------------------------------------------
//Static globals
//------------------------------------------------------------------------------

TodControls & TodControls::getTheInstance()
{
    return Singleton<TodControls>::instance();
}

//******************************************************************************
//TodControls::TodControls
//******************************************************************************
TodControls::TodControls()
{
    TOD_ENTER("TodControls constructor");
    TOD_EXIT("TodControls constructor");
}

//******************************************************************************
//TodControls::~TodControls
//******************************************************************************
TodControls::~TodControls()
{
    TOD_ENTER("TodControls destructor");

    destroy(TOD_PRIMARY);
    destroy(TOD_SECONDARY);

    TOD_EXIT("TodControls destructor");
}

//******************************************************************************
//TodControls::pickMdmt
//******************************************************************************
errlHndl_t TodControls::pickMdmt(const p10_tod_setup_tod_sel i_config)
{

   TOD_ENTER("TodControls::pickMdmt: Input config is 0x%.2X", i_config);

   errlHndl_t l_errHdl = nullptr;

   //MDMT is the master processor that drives TOD signals to all the remaining
   //processors on the system, as such wherever possible algorithm will try to
   //ensure that primary and secondary topology provides redundancy of MDMT.

    do{

        TodDrawerContainer l_todDrawerList =
            iv_todConfig[i_config].iv_todDrawerList;
        TodProcContainer l_procList;

        TodProc* l_newMdmt = nullptr;
        TodDrawer* l_pTodDrw = nullptr;
        TodProcContainer l_procCompleteList; 
        TARGETING::Target* l_bootProc = nullptr;

        l_errHdl = targetService().queryMasterProcChipTargetHandle(
                                                 l_bootProc,
                                                 nullptr,
                                                 true );
        if(l_errHdl)
        {
            TOD_ERR( "ERROR : pickMdmt "
                       "queryMasterProcChipTargetHandle() " );
            errlCommit(l_errHdl, TOD_COMP_ID);
            break;
        }

        //No MDMT configured yet. We need to select boot proc as MDMT.

        //In P10, all TOD errors are configured as checkstop.
        //For eBMC based systems, LPC clock is used as TOD refrence clock. During
        //IPL, for non boot Procs, LPC clock paths are not verified. If such a Proc is 
        //chosen as MDMT, a single instance of TOD error can bring down the platform.
        //Since, recovery from TOD error in P10 is not possible, it is safer to choose
        //only boot proc as MDMT.

        for (const auto & l_drwItr: l_todDrawerList)
        {
            l_procList.clear();
            bool l_mdmtFound = false;            

            //Get the list of procs on this TOD drawer that have oscillator
            //input.

            l_drwItr->
                getPotentialMdmts(l_procList);

            for( const auto & l_proc: l_procList )
            {
                if( l_proc->getTarget() == l_bootProc )
                {
                    l_pTodDrw = l_drwItr;
                    l_newMdmt = l_proc;
                    l_mdmtFound  = true;
                    break;
                }
            }

            if(l_mdmtFound)
            {
                break;
            }
        }

        if(l_newMdmt)
        {
            // If new MDMT, we set the todConfig
            l_errHdl = setMdmt(i_config,
                               l_newMdmt,
                               l_pTodDrw );
            if(l_errHdl)
            {
                TOD_ERR("Error setting proc 0x%.8X on "
                        "TOD drawer 0x%.2X as MDMT "
                        "for config 0x%.2X",
                        l_newMdmt->getTarget()->
                        getAttr<TARGETING::ATTR_HUID>(),
                        l_pTodDrw->getId(),
                        i_config);
                errlCommit(l_errHdl, TOD_COMP_ID);
            }
        }
    }while(0);


    TOD_EXIT("TodControls::pickMdmt");

    return l_errHdl;
}

//******************************************************************************
//TodControls::buildTodDrawers
//******************************************************************************
errlHndl_t  TodControls::buildTodDrawers(
        const p10_tod_setup_tod_sel i_config)
{
    TOD_ENTER("buildTodDrawers");
    errlHndl_t l_errHdl = nullptr;

    do{

        TARGETING::TargetHandleList l_funcNodes;

        //Get the system pointer
        TARGETING::Target* l_pSysTarget = nullptr;
        (void)TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

        if (nullptr == l_pSysTarget)
        {
            //We should not be reaching here without a valid system target
            TOD_ERR_ASSERT(false, "buildTodDrawers: nullptr system target ");
            break;
        }

        //Build the list of functional nodes
        l_errHdl =  TOD::TodSvcUtil::getFuncNodeTargetsOnSystem( l_pSysTarget,
                l_funcNodes);
        if ( l_errHdl )
        {
            TOD_ERR("For System target 0x%08X getFuncNodeTargetsOnSystem "
                    "returned  error ",l_pSysTarget->
                    getAttr<TARGETING::ATTR_HUID>());
            break;
        }

        //If there was no functional  node found then we must return
        if ( l_funcNodes.empty() )
        {
            TOD_ERR("For System target 0x%08X no functional node found ",
                    l_pSysTarget->getAttr<TARGETING::ATTR_HUID>());
             /*@
              * @errortype
              * @moduleid     TOD_BUILD_TOD_DRAWERS
              * @reasoncode   TOD_NO_FUNC_NODE_AVAILABLE
              * @userdata1    system target's HUID
              * @devdesc      MDMT could not find a functional node
              * @custdesc     Error encountered during IPL of the system
              */
            const bool hbSwError = true;
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                               TOD_BUILD_TOD_DRAWERS,
                               TOD_NO_FUNC_NODE_AVAILABLE,
                               l_pSysTarget->getAttr<ATTR_HUID>(),
                               hbSwError);
            break;
        }

        TodDrawerContainer& l_todDrawerList =
            iv_todConfig[i_config].iv_todDrawerList;
        if (!l_todDrawerList.empty())
        {
            TOD_ERR_ASSERT(false, "TOD drawer list must be empty");
            break;
        }

        //For each node target find the prcessor chip on it
        TARGETING::TargetHandleList l_funcProcs;

        TARGETING::PredicateCTM
            l_procCTM(TARGETING::CLASS_CHIP,TARGETING::TYPE_PROC);

        TARGETING::PredicateHwas l_funcPred;
        l_funcPred.functional(true);
        TARGETING::PredicatePostfixExpr l_funcProcPostfixExpr;
        l_funcProcPostfixExpr.push(&l_procCTM).push(&l_funcPred).And();

        for (auto l_node : l_funcNodes)
        {
            //Create a new TOD drawer and add it to the TOD drawer list
            //Create a TOD drawer with the drawer id same as
            //node's id , and the pointer to the node target
            TodDrawer *l_pTodDrawer = new
                TodDrawer(l_node->getAttr<TARGETING::ATTR_ORDINAL_ID>(),
                              l_node);
            l_todDrawerList.push_back(l_pTodDrawer);

            l_funcProcs.clear();
            TARGETING::targetService().getAssociated(l_funcProcs,
                    l_node,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::IMMEDIATE,
                    &l_funcProcPostfixExpr);

            for (auto l_proc : l_funcProcs)
            {
                //Create a TodProc passing the target pointer and the
                //pointer of TodDrawer to which this processor belongs
                TodProc *l_pTodProc = new TodProc(l_proc, l_pTodDrawer);
                l_pTodDrawer->addProc(l_pTodProc);
                l_pTodProc = nullptr;
            }
            l_pTodDrawer = nullptr;
        }

        //Validate that we had at least one TOD drawer at the end of this
        // process else generate an error
        if (iv_todConfig[i_config].iv_todDrawerList.empty())
        {
            TOD_ERR("No TOD drawer could be built for the configuration "
                    " %s ", (i_config == TOD_PRIMARY) ? "Primary": "Secondary");
            /*@
             * @errortype
             * @moduleid     TOD_BUILD_TOD_DRAWERS
             * @reasoncode   TOD_NO_DRAWERS
             * @userdata1    TOD configuration
             * @devdesc      No TOD drawer could be configured for this topology
             *               type
             * @custdesc     Host failed to boot because there was a problem
             *               configuring Time Of Day on the Host processors
             */
             l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                               TOD_BUILD_TOD_DRAWERS,
                               TOD_NO_DRAWERS,
                               i_config);

             l_errHdl->addProcedureCallout(
             HWAS::EPUB_PRC_FIND_DECONFIGURED_PART,
             HWAS::SRCI_PRIORITY_LOW);

        }

    }while(0);
    TOD_EXIT("buildTodDrawers");
    return l_errHdl;
}

//******************************************************************************
//TodControls::isTodRunning
//******************************************************************************
errlHndl_t TodControls ::isTodRunning(bool& o_isTodRunning)const
{
    TOD_ENTER("isTodRunning");
    errlHndl_t l_errHdl = nullptr;
    TARGETING::Target* l_primaryMdmt = nullptr;
    TARGETING::Target* l_secondaryMdmt = nullptr;
    o_isTodRunning = false;

    do{
        //Read the TOD HW to get the configured MDMT
        l_errHdl = getConfiguredMdmt(l_primaryMdmt,l_secondaryMdmt);
        if(l_errHdl)
        {
            TOD_ERR("Failed getting configured MDMTs" );
            break;
        }

        //PHYP starts TOD logic. TOD logic can be started using either primary
        //or secondary TOD configuration, if both configuration exist primary
        //topology is considered for starting TOD logic. After the TOD logic is
        //started successfully, TOD FSM ( finite state machine ) register will
        //report the TOD status as running.

        //If there is atleast one MDMT
        //configured , check the chipTOD HW status by reading the TOD
        //register scomt::perv::TOD_FSM_REG

        fapi2::variable_buffer l_primaryMdmtBuf(64);
        l_primaryMdmtBuf.flush<0>();
        fapi2::variable_buffer l_secondaryMdmtBuf(64);
        l_secondaryMdmtBuf.flush<0>();

        if(l_primaryMdmt)
        {
            l_errHdl = todGetScom(l_primaryMdmt,
                                  TOD_FSM_REG,
                                  l_primaryMdmtBuf);
            if(l_errHdl)
            {
                TOD_ERR("Scom failed for TOD FSM register "
                        "scomt::perv::TOD_FSM_REG on primary MDMT");
                break;
            }

        }

        if(l_secondaryMdmt)
        {
            l_errHdl = todGetScom(l_secondaryMdmt,
                                  TOD_FSM_REG,
                                  l_secondaryMdmtBuf);
            if(l_errHdl)
            {
                TOD_ERR("Scom failed for TOD FSM register "
                       "scomt::perv::TOD_FSM_REG on secondary MDMT");
                break;
            }
        }

        //If the bit 4 of the scomt::perv::TOD_FSM_REG related to primary or
        //secondary topology is set then the chip TOD logic is considered to
        //be in the running state.
        if(l_primaryMdmtBuf.isBitSet(TOD_FSM_REG_TOD_IS_RUNNING))
        {
            o_isTodRunning = true;
            TOD_INF("TOD logic is in the running state considering primary"
                     "topology as active topology");
        }
        else if(l_secondaryMdmtBuf.isBitSet(TOD_FSM_REG_TOD_IS_RUNNING))
        {
             o_isTodRunning = true;
             TOD_INF("TOD logic is in the running state considering"
                      "secondary topology as active topology");
        }
    }while(0);

    TOD_EXIT("isTodRunning: TOD HW State = %d",o_isTodRunning);
    return l_errHdl;
}

//******************************************************************************
//TodControls::queryActiveConfig
//******************************************************************************
errlHndl_t TodControls ::queryActiveConfig(
        p10_tod_setup_tod_sel& o_activeConfig,
        bool& o_isTodRunning,
        TARGETING::Target*& o_mdmtOnActiveTopology,
        bool i_determineTodRunningState)const
{
    TOD_ENTER("TodControls::queryActiveConfig");
    errlHndl_t l_errHdl = nullptr;
    TARGETING::Target* l_primaryMdmt = nullptr;
    TARGETING::Target* l_secondaryMdmt = nullptr;
    o_isTodRunning = false;

    do
    {

        if ( i_determineTodRunningState )
        {
            l_errHdl = isTodRunning(o_isTodRunning);
            if ( l_errHdl )
            {
                TOD_INF("Call to isTodRunning() failed,cannot query active "
                        "config state");
                break;
            }
        }

        //Read the TOD HW to get the configured MDMT
        l_errHdl = getConfiguredMdmt(l_primaryMdmt,l_secondaryMdmt);
        if ( l_errHdl )
        {
            TOD_ERR("Failed getting configured MDMTs" );
            break;
        }

        //Check for case where no MDMT could be found.. this can happen only
        //when the method is called before topology was configured
        if ( ! ( l_primaryMdmt || l_secondaryMdmt ))
        {
            TOD_ERR(" Neither primary not Secondary MDMT is configured ");
            //Return an error
            /*@
             * @errortype
             * @moduleid     TOD_QUERY_ACTIVE_CONFIG
             * @reasoncode   TOD_NO_VALID_MDMT_FOUND
             * @devdesc      No valid MDMT found on either topology
             * @custdesc     Host failed to boot because there was a problem
             *               configuring Time Of Day on the Host processors
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           TOD_QUERY_ACTIVE_CONFIG,
                           TOD_NO_VALID_MDMT_FOUND);
            break;

        }

        //Initialize the output variables, in case TOD is not running then
        //these values will be returned.
        o_activeConfig = TOD_PRIMARY;

        if ( l_primaryMdmt )
        {
            o_mdmtOnActiveTopology = l_primaryMdmt;
        }
        else
        {
            o_mdmtOnActiveTopology =  l_secondaryMdmt;
        }

        //If TOD is running then query the configured MDMT to get the active
        //configuration data else return Primary as default active
        //configuration.
        if (o_isTodRunning)
        {
            o_mdmtOnActiveTopology = nullptr;
            //Make it nullptr again, since TOD is running we cannot return
            //l_primaryMdmt as the MDMT on the active topology

            fapi2::variable_buffer l_primaryMdmtBuf(64);
            l_primaryMdmtBuf.flush<0>();
            fapi2::variable_buffer l_secondaryMdmtBuf(64);
            l_secondaryMdmtBuf.flush<0>();

            if ( l_primaryMdmt )
            {
                l_errHdl = todGetScom(l_primaryMdmt,
                                      TOD_PSS_MSS_STATUS_REG,
                                      l_primaryMdmtBuf);
                if ( l_errHdl )
                {
                    TOD_ERR("Scom failed for status register "
                            "TOD_PSS_MSS_STATUS_REG on primary "
                            " MDMT");
                    break;
                }

                //Check First 3 bits of TOD_PSS_MSS_STATUS_REG
                //indicates active TOD topology
                //[0:2] == '111' secondary, '000' is primary
                //just check bit 0
                if( l_primaryMdmtBuf.isBitSet
                        (TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT))
                {
                    TOD_INF("Primary MDMT  0x%08X is indicating active "
                            " configuration as TOD_PRIMARY ",
                            GETHUID(l_secondaryMdmt));
                    o_activeConfig = TOD_SECONDARY;
                    o_mdmtOnActiveTopology = l_secondaryMdmt;
                }
                else
                {
                    o_mdmtOnActiveTopology = l_primaryMdmt;
                }
                //else Primary Topology is considered active
            }
            //If Primary Mdmt is not present then querying the secondaryMdmt.
            else if ( l_secondaryMdmt )
            {
                l_errHdl = todGetScom(l_secondaryMdmt,
                                      TOD_PSS_MSS_STATUS_REG,
                                      l_secondaryMdmtBuf);
                if ( l_errHdl )
                {
                    TOD_ERR("Scom failed for status register "
                            "TOD_PSS_MSS_STATUS_REG on secondary "
                            "MDMT");
                    break;
                }

                //Check First 3 bits of TOD_PSS_MSS_STATUS_REG
                //indicates active TOD topology
                // [0:2] == '111' secondary, '000' is primary -
                //just check bit 0
                if ( l_secondaryMdmtBuf.isBitSet
                        (TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT))
                {
                    TOD_INF("Secondary MDMT  0x%08X is indicating active "
                            " configuration as TOD_SECONDARY ",
                            GETHUID(l_secondaryMdmt));
                    o_activeConfig = TOD_SECONDARY;
                    o_mdmtOnActiveTopology = l_secondaryMdmt;
                }
                else
                {
                    o_mdmtOnActiveTopology = l_primaryMdmt;
                }
            }

            //It is highly unlikely that PRIMARY topology says SECONDARY is
            //active however we don't have MDMT on the secondary topology.
            if ( !o_mdmtOnActiveTopology )
            {
                TOD_ERR("Active topology found but could not get the MDMT "
                        " on active TOPOLOGY ");

                /*@
                 * @errortype
                 * @moduleid     TOD_QUERY_ACTIVE_CONFIG
                 * @reasoncode   TOD_NO_MDMT_ON_ACTIVE_CONFIG
                 * @userdata1    Active configuration
                 * @devdesc      MDMT not found on active toplology
                 * @custdesc     Service Processor Firmware encountered an
                 *               internal error
                 */
                const bool hbSwError = true;
                l_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           TOD_QUERY_ACTIVE_CONFIG,
                           TOD_NO_MDMT_ON_ACTIVE_CONFIG,
                           o_activeConfig,
                           hbSwError);
                break;
            }
        }//isTodRunning check

    }while(0);

    //If TOD logic is running and no failure is hit in the code above.
    if( l_errHdl == nullptr )
    {
        if (o_isTodRunning)
        {
            if ( o_activeConfig == TOD_PRIMARY )
            {
                TOD_INF("Primary topology is considered as active ");
            }
            else if( o_activeConfig == TOD_SECONDARY)
            {
                TOD_INF("Secondary topology is considered as active");
            }
        }
        else
        {
            if ( i_determineTodRunningState )
            {
                TOD_INF("TOD logic is not in the running state!!");
            }
        }
    }
    else
    {
        TOD_ERR("Failed to get TOD running state and active configuration"
                "details!!");
    }

    TOD_EXIT("TodControls::queryActiveConfig");

    return l_errHdl;
}

//******************************************************************************
//TodControls::getConfiguredMdmt
//******************************************************************************
errlHndl_t TodControls ::getConfiguredMdmt(
        TARGETING::Target*& o_primaryMdmt,
        TARGETING::Target*& o_secondaryMdmt) const
{
    TOD_ENTER("getConfiguredMdmt");
    errlHndl_t l_errHdl = nullptr;
    o_primaryMdmt = nullptr;
    o_secondaryMdmt = nullptr;

    do
    {
        //Find MDMT for primary and secondary topology from HW

        //Get the functional procs on the system
        TARGETING::PredicateCTM
            l_procFilter(TARGETING::CLASS_CHIP,TARGETING::TYPE_PROC,
                    TARGETING::MODEL_NA);

        TARGETING::PredicateHwas l_funcPred;
        l_funcPred.functional(true);

        TARGETING::PredicatePostfixExpr l_stateAndProcChipFilter;
        l_stateAndProcChipFilter.push(&l_procFilter).
            push(&l_funcPred).And();

        TARGETING::TargetHandleList l_procTargetList;
        //fapi2 data buffer for TOD register
        fapi2::variable_buffer l_todStatusReg(64);

        /* TOD_PSS_MSS_STATUS_REG (defined in p10_scom_perv_d.H) has the
         * following interpretation:
         * Primary configuration
         * TOD_STATUS[13]   TOD_STATUS[14]  Inference
         *      1               1          Master TOD Master Drawer
         *      0               1          Slave TOD Master Drawer
         *      0               0          Slave TOD Slave Drawer
         *      1               0          Master TOD Slave Drawer
         *
         * Secondary configuration
         * TOD_STATUS[17]    TOD_STATUS[18] Inference
         *                                  Same as for primary
         */

        TARGETING::TargetRangeFilter l_filter(
                TARGETING::targetService().begin(),
                TARGETING::targetService().end(),
                &l_stateAndProcChipFilter);

        //Read the TOD status register TOD_PSS_MSS_STATUS_REG for each
        //processor and check the TOD and Drawer bits
        for (   ; l_filter; ++l_filter  )
        {
            l_errHdl = todGetScom(*l_filter,
                                  TOD_PSS_MSS_STATUS_REG,
                                  l_todStatusReg);

            if ( l_errHdl )
            {
                TOD_ERR("Scom failed for target 0x%08X on register"
                        " TOD_PSS_MSS_STATUS_REG",
                        (*l_filter)->getAttr<TARGETING::ATTR_HUID>());
                break;
            }

            if (l_todStatusReg.isBitSet(
                    TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS)
                &&
                l_todStatusReg.isBitSet(
                        TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS))
            {
                o_primaryMdmt = *l_filter;
                TOD_INF("found primary MDMT HUID = 0x%08X",
                        o_primaryMdmt->getAttr<TARGETING::ATTR_HUID>());
            }

            if (l_todStatusReg.isBitSet(
                    TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS)
                &&
                l_todStatusReg.isBitSet(
                    TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS))
            {
                o_secondaryMdmt = *l_filter;
                TOD_INF("found secondary MDMT HUID = 0x%08X",
                        o_secondaryMdmt->getAttr<TARGETING::ATTR_HUID>());

            }

            if ( o_primaryMdmt && o_secondaryMdmt )
            {
                break;
            }
        }

    }while(0);

    TOD_EXIT("getConfiguredMdmt");
    return l_errHdl;
}

//******************************************************************************
//TodControls::destroy
//******************************************************************************
void TodControls::destroy(const p10_tod_setup_tod_sel i_config)
{
    TOD_ENTER("TodControls::destroy");

    for(TodDrawerContainer::iterator l_itr =
            iv_todConfig[i_config].iv_todDrawerList.begin();
            l_itr != iv_todConfig[i_config].iv_todDrawerList.end();
            ++l_itr)
    {
        if(*l_itr)
        {
            delete (*l_itr);
        }
    }
    iv_todConfig[i_config].iv_todDrawerList.clear();
    iv_todConfig[i_config].iv_mdmt = nullptr;
    iv_todConfig[i_config].iv_isConfigured = false;
    iv_todChipDataVector.clear();
    iv_BlackListedProcs.clear();
    iv_gardedTargets.clear();
    TOD_EXIT("TodControls::destroy");
}

//******************************************************************************
//TodControls::writeTodProcData
//******************************************************************************
errlHndl_t TodControls :: writeTodProcData(
        const p10_tod_setup_tod_sel i_config)
{
    TOD_ENTER("TodControls::writeTodProcData");
    errlHndl_t l_errHdl = nullptr;

    do{

        //As per the requirement specified by PHYP/HDAT, TOD needs to fill
        //data for every chip that can be installed on the system.
        //It is also required that chip ID match the index of the entry in the
        //array so we can possibly have valid chip data at different indexes in
        //the array and the intermittent locations filled with the chip entries
        //that does not exist on the system. All such entires will have default
        //non-significant values

        TodChipData blank;
        uint32_t l_maxProcCount = TOD::TodSvcUtil::getMaxProcsOnSystem();
        Target* l_target = nullptr;

        TOD_INF("Max possible processor chips for this system when configured "
                "completely is %d",l_maxProcCount);

        iv_todChipDataVector.assign(l_maxProcCount,blank);

        TARGETING::ATTR_ORDINAL_ID_type l_ordId = 0x0;
        //Ordinal Id of the processors that form the topology

        //Fill the TodChipData structures with the actual value in the
        //ordinal order
        for(TodDrawerContainer::iterator l_itr =
                iv_todConfig[i_config].iv_todDrawerList.begin();
                l_itr != iv_todConfig[i_config].iv_todDrawerList.end();
                ++l_itr)
        {
            const TodProcContainer&  l_procs =
                (*l_itr)->getProcs();

            for(TodProcContainer::const_iterator
                    l_procItr = l_procs.begin();
                    l_procItr != l_procs.end();
                    ++l_procItr)
            {
                l_ordId =
                    (*l_procItr)->getTarget()->
                    getAttr<TARGETING::ATTR_ORDINAL_ID>();

                //Clear the default flag for this chip, defaults to
                //NON_FUNCTIONAL however this is a functional chip
                iv_todChipDataVector[l_ordId].header.flags = TOD_NONE;

                //Fill the todChipData structure at position l_ordId
                //inside iv_todChipDataVector with TOD register data
                //values
                (*l_procItr )->setTodChipData(
                        iv_todChipDataVector[l_ordId]);

                //Set flags to indicate if the proc chip is an MDMT
                //See if the current proc chip is MDMT of the primary
                //topology
                if ( getConfigStatus(TOD_PRIMARY)
                        &&
                        getMDMT(TOD_PRIMARY))
                {
                    if (
                            (getMDMT(TOD_PRIMARY)->getTarget()->
                             getAttr<TARGETING::ATTR_HUID>())
                            ==
                            ((*l_procItr)->getTarget()->
                             getAttr<TARGETING::ATTR_HUID>())
                       )
                    {

                        iv_todChipDataVector[l_ordId].header.flags |=
                            TOD_PRI_MDMT;
                    }
                }


                //See if the current proc chip is MDMT of the secondary
                //network
                //Note: The chip can be theoretically both primary and
                //secondary MDMDT
                if ( getConfigStatus(TOD_SECONDARY)
                        &&
                        getMDMT(TOD_SECONDARY))
                {
                    if (
                            (getMDMT(TOD_SECONDARY)->getTarget()->
                             getAttr<TARGETING::ATTR_HUID>())
                            ==
                            ((*l_procItr)->getTarget()->
                             getAttr<TARGETING::ATTR_HUID>())
                       )
                    {

                        iv_todChipDataVector[l_ordId].header.flags |=
                            TOD_SEC_MDMT;
                    }

                }

                ATTR_TOD_CPU_DATA_type l_tod_array;
                memcpy(l_tod_array,
                       &iv_todChipDataVector[l_ordId],sizeof(TodChipData));

                l_target = const_cast<Target *>((*l_procItr)->getTarget());
                l_target->setAttr<ATTR_TOD_CPU_DATA>(l_tod_array);
            }
        }

    }while(0);

    TOD_EXIT("writeTodProcData. errHdl = %p", l_errHdl);
    return l_errHdl;

}//end of writeTodProcData

//******************************************************************************
//TodControls::hasNoValidData()
//******************************************************************************
bool TodControls ::hasNoValidData(const std::vector<TodChipData>&
        i_todChipDataVector)const
{
    TOD_ENTER("TodControls::hasNoValidData");
    bool result = true;
    for(std::vector<TodChipData>::const_iterator l_iter =
            i_todChipDataVector.begin();
            l_iter != i_todChipDataVector.end(); ++l_iter)
    {
        if(((*l_iter).header.flags & TOD_FUNC) != 0)
        {
            result = false;
            break;
        }
    }
    TOD_EXIT("hasNoValidData");
    return result;
}

//******************************************************************************
//TodControls::pickMdmt
//******************************************************************************
TodProc* TodControls ::pickMdmt(
                                  const TodProc* i_otherConfigMdmt,
                                  const p10_tod_setup_tod_sel& i_config,
                                  const bool i_setMdmt)
{
    TOD_ENTER("TodControls::pickMdmt: Other MDMT : 0x%.8X, "
               "Input config : 0x%.2X",
               GETHUID(i_otherConfigMdmt->getTarget()),
               i_config);

    TodProc* l_newMdmt = nullptr;
    TodProc *l_pTodProc = nullptr;
    TodDrawer* l_pMasterDrw = nullptr;
    TodDrawerContainer l_todDrawerList =
        iv_todConfig[i_config].iv_todDrawerList;
    TodProcContainer l_procList;
    uint32_t l_coreCount = 0;
    uint32_t l_maxCoreCount = 0;
    errlHndl_t l_errHdl = nullptr;

    do
    {
        //1.MDMT will be chosen from a node other than the node on which
        //this MDMT exists, in case of multinode systems
        //Iterate the list of TOD drawers
        l_maxCoreCount = 0;
        for (TodDrawerContainer::iterator l_todDrawerIter =
                 l_todDrawerList.begin();
             l_todDrawerIter != l_todDrawerList.end();
             ++l_todDrawerIter)
        {

            //TodProc --> TodDrawer --> Node
            if(i_otherConfigMdmt->getParentDrawer()->getParentNodeTarget()->
                   getAttr<TARGETING::ATTR_HUID>()
               !=
               (*l_todDrawerIter)->getParentNodeTarget()->
                   getAttr<TARGETING::ATTR_HUID>())
            {
                l_pTodProc = nullptr;
                l_coreCount = 0;
                l_procList.clear();
                //Get the list of procs on this TOD drawer that have oscillator
                //input. Each of them is a potential MDMT, choose the one with
                //max no. of cores
                (*l_todDrawerIter)->
                    getPotentialMdmts(l_procList);
                (*l_todDrawerIter)->
                    getProcWithMaxCores(nullptr,
                                        l_pTodProc,
                                        l_coreCount,
                                        &l_procList);
                if(l_coreCount > l_maxCoreCount)
                {
                    l_newMdmt = l_pTodProc;
                    l_maxCoreCount = l_coreCount;
                    l_pMasterDrw = *l_todDrawerIter;
                }
            }
        }
        if(l_newMdmt && i_setMdmt )
        {
            l_errHdl = setMdmt(i_config,
                               l_newMdmt,
                               l_pMasterDrw);
            if(l_errHdl)
            {
                TOD_ERR("Error setting proc 0x%.8X on "
                         "TOD drawer 0x%.2X as MDMT "
                         "for config 0x%.2X",
                         l_newMdmt->getTarget()->
                            getAttr<TARGETING::ATTR_HUID>(),
                         l_pMasterDrw->getId(),
                         i_config);
                errlCommit(l_errHdl, TOD_COMP_ID);
                l_newMdmt = nullptr;
            }
            else
            {
                TOD_INF("Found MDMT 0x%.8X on different node 0x%.8X",
                    l_newMdmt->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
                    l_pMasterDrw->getParentNodeTarget()->
                        getAttr<TARGETING::ATTR_HUID>());
                l_pMasterDrw = nullptr;
                break;
            }
        }

        //2.Try to find MDMT on a TOD drawer that is on the same physical
        //node as the possible opposite MDMT but on different TOD drawer
        l_maxCoreCount = 0;
        for(const auto & l_todDrawerIter : l_todDrawerList)
        {
            if((i_otherConfigMdmt->getParentDrawer()->getParentNodeTarget()->
                    getAttr<TARGETING::ATTR_HUID>() ==
               l_todDrawerIter->getParentNodeTarget()->
                    getAttr<TARGETING::ATTR_HUID>())//Same node
               &&
               (i_otherConfigMdmt->getParentDrawer()->getId() !=
                    l_todDrawerIter->getId()))//Different TOD Drawer
            {
                l_pTodProc = nullptr;
                l_coreCount = 0;
                l_procList.clear();
                //Get the list of procs on this TOD drawer that have oscillator
                //input. Each of them is a potential MDMT, choose the one with
                //max no. of cores
                l_todDrawerIter->
                    getPotentialMdmts(l_procList);
                l_todDrawerIter->
                    getProcWithMaxCores(nullptr,
                                        l_pTodProc,
                                        l_coreCount,
                                        &l_procList);
                if(l_coreCount > l_maxCoreCount)
                {
                    l_newMdmt = l_pTodProc;
                    l_maxCoreCount = l_coreCount;
                    l_pMasterDrw = l_todDrawerIter;
                }
            }
        }
        if(l_newMdmt && i_setMdmt)
        {
            l_errHdl = setMdmt(i_config,
                               l_newMdmt,
                               l_pMasterDrw);
            if(l_errHdl)
            {
                TOD_ERR("Error setting proc 0x%.8X on "
                         "TOD drawer 0x%.2X as MDMT "
                         "for config 0x%.2X",
                         l_newMdmt->getTarget()->
                            getAttr<TARGETING::ATTR_HUID>(),
                         l_pMasterDrw->getId(),
                         i_config);
                errlCommit(l_errHdl, TOD_COMP_ID);
                l_newMdmt = nullptr;
            }
            else
            {
                TOD_INF("Found MDMT 0x%.8X on different TOD drawer 0x%.2X",
                    l_newMdmt->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
                    l_pMasterDrw->getId());
                l_pMasterDrw = nullptr;
                break;
            }
        }

        //3.Try to find MDMT on the same TOD drawer as the TOD Drawer of
        //opposite MDMT
        l_maxCoreCount = 0;
        for (const auto l_todDrawerIter : l_todDrawerList)
        {
            l_pTodProc = nullptr;
            l_coreCount = 0;
            l_procList.clear();
            if(i_otherConfigMdmt->getParentDrawer()->getId() ==
                  l_todDrawerIter->getId())
            {
                //This  is the TOD drawer on which opposite MDMT exists,
                //try to avoid processor chip of opposite MDMT while
                //getting the proc with max cores
                //Get the list of procs on this TOD drawer that have oscillator
                //input. Each of them is a potential MDMT, choose the one with
                //max no. of cores
                l_todDrawerIter->
                    getPotentialMdmts(l_procList);
                l_todDrawerIter->getProcWithMaxCores(
                        i_otherConfigMdmt,
                        l_pTodProc,
                        l_coreCount,
                        &l_procList);
                l_newMdmt = l_pTodProc;
                l_pMasterDrw = l_todDrawerIter;
                break;
            }
        }
        if(l_newMdmt && i_setMdmt)
        {
            l_errHdl = setMdmt(i_config,
                               l_newMdmt,
                               l_pMasterDrw);
            if(l_errHdl)
            {
                TOD_ERR("Error setting proc 0x%.8X on "
                         "TOD drawer 0x%.2X as MDMT "
                         "for config 0x%.2X",
                         l_newMdmt->getTarget()->
                            getAttr<TARGETING::ATTR_HUID>(),
                         l_pMasterDrw->getId(),
                         i_config);
                errlCommit(l_errHdl, TOD_COMP_ID);
                l_newMdmt = nullptr;
            }
            else
            {
                TOD_INF(
                    "Found another MDMT 0x%.8X on the same TOD drawer 0x%.2X "
                    "on which i_otherConfigMdmt(0x%.8X) resides",
                    GETHUID(l_newMdmt->getTarget()),
                    l_pMasterDrw->getId(),
                    GETHUID(i_otherConfigMdmt->getTarget()));
                l_pMasterDrw = nullptr;
                break;
            }
        }
    }while(0);

    TOD_EXIT("TodControls::pickMdmt");

    return l_newMdmt;
}

//******************************************************************************
//TodControls::setMdmtOfActiveConfig
//******************************************************************************
void  TodControls ::setMdmtOfActiveConfig(
            const p10_tod_setup_tod_sel i_config,
            TodProc* i_mdmt,
            TodDrawer* i_masterDrawer)
{
    TOD_ENTER("setMdmtOfActiveConfig");

    do
    {
      if ( !i_mdmt )
      {
          TOD_ERR_ASSERT(false, "Software error input MDMT must not be nullptr");
          break;
      }

      if ( !i_masterDrawer )
      {
          TOD_ERR_ASSERT(false, "Software error input master drawer must not be "
          " nullptr");
          break;
      }

      iv_todConfig[i_config].iv_mdmt = i_mdmt;
      i_mdmt->setMasterType(TodProc::TOD_MASTER);
      i_masterDrawer->setMasterDrawer(true);

      TOD_INF("MDMT for configuration 0x%.2X is proc 0x%.8X",
              i_config,
              GETHUID(iv_todConfig[i_config].iv_mdmt->getTarget()));
    } while (0);
    TOD_EXIT("setMdmtOfActiveConfig");
}

//******************************************************************************
//TodControls::setMdmt
//******************************************************************************
errlHndl_t TodControls::setMdmt(const p10_tod_setup_tod_sel i_config,
                                 TodProc* i_mdmt,
                                 TodDrawer* i_masterDrawer)
{
    TOD_ENTER("setMdmt");

    errlHndl_t l_errHdl = nullptr;

    do
    {
      if (!i_mdmt)
      {
          TOD_ERR_ASSERT(false, "Software error input MDMT must not be nullptr");
          break;
      }

      if (!i_masterDrawer)
      {
          TOD_ERR_ASSERT(false, "Software error input master drawer must not be "
          " nullptr");
          break;
      }

      iv_todConfig[i_config].iv_mdmt = i_mdmt;
      i_mdmt->setMasterType(TodProc::TOD_MASTER);
      i_masterDrawer->setMasterDrawer(true);

      TOD_INF("MDMT for configuration 0x%.2X is proc 0x%.8X, ",
               i_config,
               iv_todConfig[i_config].iv_mdmt->
                   getTarget()->getAttr<TARGETING::ATTR_HUID>());

    } while (0);
    TOD_EXIT("setMdmt");

    return l_errHdl;
}

//******************************************************************************
//isProcBlackListed
//******************************************************************************
bool  TodControls::isProcBlackListed (
        TARGETING::ConstTargetHandle_t i_procTarget
        )const
{
    TOD_ENTER("TodControls::isProcBlackListed");

    bool l_blackListed = false;

    do
    {
      if(!i_procTarget)
      {
          TOD_ERR_ASSERT(false, "Input target cannot be nullptr for "
                  "isProcBlackListed");
          break;
      }

      if (
              ( GETCLASS(i_procTarget) != TARGETING::CLASS_CHIP )
              ||
              ( GETTYPE(i_procTarget) != TARGETING::TYPE_PROC))
      {
          TOD_ERR_ASSERT(false, "Only processor target allowed as input for "
                  " isProcBlackListed ");
          break;
      }

      // If the maximum number of processors on a system is more than 4, it
      // means that we are using a half-link SMP topology to connect DCMs. In
      // that case, due to hardware requirements, only processor 0 on any given
      // DCM can be used as a TOD master.
      if (TOD::TodSvcUtil::getMaxProcsOnSystem() > 4
          && i_procTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>() % 2 != 0)
      {
          TARGETING::TargetHandleList procs;
          TARGETING::getAllChips(procs, TARGETING::TYPE_PROC);

          // The processors within a DCM are connected via a full IOHS link, so
          // we don't have to blacklist the odd processor in the DCM when
          // there's only one functional DCM (which must be DCM 0; system
          // processor 0 must always be functional, since it is the only
          // processor with an FSI link to the BMC).
          if (procs.size() > 2 || i_procTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>() != 1)
          {
              TOD_INF("Proc 0x%.8X is blacklisted because it's the secondary processor in a DCM!",
                      GETHUID(i_procTarget));
              l_blackListed = true;
              break;
          }
      }

      if(iv_BlackListedProcs.end() != std::find(
          iv_BlackListedProcs.begin(),
          iv_BlackListedProcs.end(),
          i_procTarget))
      {
          TOD_INF("Proc 0x%.8X is blacklisted!", GETHUID(i_procTarget));
          l_blackListed = true;
      }
    } while (0);
    TOD_EXIT("TodControls::isProcBlackListed");

    return l_blackListed;
}

//******************************************************************************
//buildGardedTargetsList
//******************************************************************************
errlHndl_t TodControls::buildGardedTargetsList()
{
    TOD_ENTER("buildGardedTargetsList");
    errlHndl_t l_errHdl = nullptr;
    iv_gardListInitialized = false;
    clearGardedTargetsList();

    do
    {
        TARGETING::Target* l_pSystemTarget = nullptr;
        TARGETING::targetService().getTopLevelTarget(l_pSystemTarget);
        if (!l_pSystemTarget)
        {
            TOD_ERR_ASSERT(false, "System target could not be found");
            break;
        }

        GardedUnitList_t l_gardedUnitList;
        l_errHdl = gardGetGardedUnits(l_pSystemTarget,l_gardedUnitList);
        if ( l_errHdl )
        {
            TOD_ERR("Error getting garded units.");
            break;
        }
        else
        {
            for(const auto & l_iter : l_gardedUnitList)
            {
                //Push the HUID to the set of garded targets
                iv_gardedTargets.push_back(l_iter.iv_huid);
                TOD_INF("Adding 0x%08X to the garded list of targets",
                        l_iter.iv_huid);
            }


        }

    }while(0);

    if ( !l_errHdl )
    {
        iv_gardListInitialized = true;
    }
    TOD_EXIT("buildGardedTargetsList");

    return l_errHdl;

}


//******************************************************************************
//checkGardStatusOfTarget
//******************************************************************************
errlHndl_t TodControls::checkGardStatusOfTarget(
        TARGETING::ConstTargetHandle_t i_target,
        bool&  o_isTargetGarded )
{
    TOD_ENTER("checkGardStatusOfTarget");
    errlHndl_t l_errHdl = nullptr;
    o_isTargetGarded  = false;

    do{

        if ( !iv_gardListInitialized )
        {
            TOD_INF("Local cache of garded targets is not initialized "
            " the gard status will be retrieved from system model");
        }
        else
        {
            if (iv_gardedTargets.end() != std::find(
                iv_gardedTargets.begin(),
                iv_gardedTargets.end(),
                (GETHUID(i_target))))
            {
                o_isTargetGarded = true;
            }

        }

    }while(0);

    TOD_EXIT("checkGardStatusOfTarget: Target 0x%08X is %s",
            GETHUID(i_target),o_isTargetGarded?"garded":"not garded");
    return l_errHdl;
}

const char *TodControls::getPhysicalPathString(
        const TARGETING::ATTR_PHYS_PATH_type &i_path)
{
    const char *l_str  = i_path.toString();
    return l_str;
}

/******************************************************************************/
// gardGetGardedUnits
/******************************************************************************/
errlHndl_t TodControls::gardGetGardedUnits(
        const TARGETING::Target* const i_pTarget,
        GardedUnitList_t &o_gardedUnitList)
{
    TOD_ENTER("gardGetGardedUnits");
    errlHndl_t l_err = nullptr;

    o_gardedUnitList.clear();
    do
    {
        HWAS::DeconfigGard::GardRecords_t l_gardRecords;
        l_err = HWAS::theDeconfigGard().getGardRecords(i_pTarget,
                l_gardRecords);
        if(l_err != nullptr)
        {
            TOD_ERR("Error getting gard records for HUID :[0x%08X]",
                    GETHUID(i_pTarget));

            break;
        }

        for(const auto & l_iter : l_gardRecords)
        {
            TARGETING::Target * l_pTarget = nullptr;

            // getTargetFromPhysicalPath will either succeed or assert
            getTargetFromPhysicalPath(l_iter.iv_targetId, l_pTarget);

            GardedUnit_t l_gardedUnit;
            memset(&l_gardedUnit,0,sizeof(GardedUnit_t));
            l_gardedUnit.iv_huid =
                    l_pTarget->getAttr<TARGETING::ATTR_HUID>();
            TARGETING::Target *l_pNodeTarget = nullptr;
            if((l_pTarget->getAttr<TARGETING::ATTR_CLASS>() ==
                                    TARGETING::CLASS_ENC)&&
               (l_pTarget->getAttr<TARGETING::ATTR_TYPE>() ==
                                    TARGETING::TYPE_NODE))
            {
                l_pNodeTarget = l_pTarget;
            }
            else
            {
                l_err = getParent(l_pTarget,
                                  TARGETING::CLASS_ENC,
                                  l_pNodeTarget);
                if(l_err != nullptr)
                {
                    TOD_ERR("Error getting parent node, HUID:[0x%08X]",
                                l_pTarget->getAttr<TARGETING::ATTR_HUID>());

                    break;
                }
            }
            l_gardedUnit.iv_nodeHuid =
                    l_pNodeTarget->getAttr<TARGETING::ATTR_HUID>();
            l_gardedUnit.iv_errlogId =
                    l_iter.iv_errlogEid;
            l_gardedUnit.iv_errType =
                    static_cast<HWAS::GARD_ErrorType>(l_iter.iv_errorType);
            l_gardedUnit.iv_domain =
                    l_pTarget->getAttr<TARGETING::ATTR_CDM_DOMAIN>();
            l_gardedUnit.iv_type =
                    l_pTarget->getAttr<TARGETING::ATTR_TYPE>();

            l_gardedUnit.iv_class =
                    l_pTarget->getAttr<TARGETING::ATTR_CLASS>();

            o_gardedUnitList.push_back(l_gardedUnit);
        }
        if(l_err != nullptr)
        {
            break;
        }
    }
    while(0);
    if(l_err != nullptr)
    {
        o_gardedUnitList.clear();
    }
    TOD_EXIT("gardGetGardedUnits");

    return l_err;
}

//******************************************************************************
// getTargetFromPhysicalPath
//******************************************************************************

void TodControls::getTargetFromPhysicalPath(
    const TARGETING::ATTR_PHYS_PATH_type &i_path,
          TARGETING::Target*&  o_pTarget)

{
    TOD_ENTER("getTargetFromPhysicalPath");
    do
    {
        o_pTarget =
                TARGETING::targetService().toTarget(i_path);
        TOD_ERR_ASSERT(o_pTarget != nullptr,
                "Error in getting target from entity path[%s]",
                getPhysicalPathString(i_path));
    }
    while(0);
    TOD_EXIT("getTargetFromPhysicalPath");
}

//******************************************************************************
// getParent
//******************************************************************************

errlHndl_t TodControls::getParent(const TARGETING::Target *i_pTarget,
                     const TARGETING::CLASS i_class,
                     TARGETING::Target *& o_parent_target)
{

    //--------------------------------------------------------------------------
    // Local Variables
    //--------------------------------------------------------------------------
    bool l_parent_found = false;
    errlHndl_t l_errl = nullptr;
    TARGETING::TargetHandleList l_list;
    // Initializing l_parentTarget here in-order to eliminate goto compilation
    // error below
    const TARGETING::Target * l_parentTarget = i_pTarget;
    TARGETING::ATTR_TYPE_type l_type = TARGETING::TYPE_NA;
    TARGETING::ATTR_CLASS_type l_class = TARGETING::CLASS_NA;

    //--------------------------------------------------------------------------
    // Code
    //--------------------------------------------------------------------------
    TOD_ENTER("getParent");

    do
    {
        TOD_ERR_ASSERT(i_pTarget != nullptr, "Input Target handle is null");

        // If we have a valid target, check if it is system
        l_type = i_pTarget->getAttr<TARGETING::ATTR_TYPE>();

        l_class = i_pTarget->getAttr<TARGETING::ATTR_CLASS>();

        if((TARGETING::CLASS_SYS == l_class) &&
            (TARGETING::TYPE_SYS == l_type))
        {
            TOD_ERR("Input target is SYSTEM which cannot have a parent target."
                 "Class [0x%08X], Type [0x%08X]",
                 static_cast<uint32_t>(l_class),
                 static_cast<uint32_t>(l_type));

            //Create error
            /*@
             * @errortype
             * @moduleid     TOD_UTIL_MOD_GET_PARENT
             * @reasoncode   TOD_INVALID_TARGET
             * @userdata1    HUID of the input target
             * @devdesc      Invalid target is supplied as input,
             *               SYSTEM target has no parent
             * @custdesc     Service Processor Firmware encountered an internal
             *               error
             */

            const bool hbSwError = true;
            l_errl = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                         TOD_UTIL_MOD_GET_PARENT,
                         TOD_INVALID_TARGET,
                         GETHUID(i_pTarget),
                         hbSwError);

            break;
        }


        // Clear existing elements of l_list, just to make sure, though
        // getAssociated() clears l_list below when it gets called
        l_list.clear();

        // Get the immediate parent
        TARGETING::targetService().getAssociated(l_list, l_parentTarget,
                TARGETING::TargetService::PARENT,
                TARGETING::TargetService::IMMEDIATE);

        if (l_list.size() != 1)
        {
            // Parent not found
            break;
        }
        else
        {
            // Copy parent from list
            l_parentTarget = l_list[0];

            // Check input CLASS with parent CLASS
            if ((i_class == TARGETING::CLASS_NA) ||
                (i_class == l_parentTarget->getAttr<TARGETING::ATTR_CLASS>()))
            {
                // Remove const-ness of l_parentTarget in-order to copy it to
                // o_parent_target, which is not a const
                o_parent_target =
                    const_cast<TARGETING::Target *>(l_parentTarget);
                l_parent_found = true;
                break;
            }
        }
    }while(0);

    // Create an error log if parent is not found
    if(!l_parent_found)
    {

        //Create error
        /*@
         * @errortype
         * @moduleid     TOD_UTIL_MOD_GET_PARENT
         * @reasoncode   TOD_PARENT_NOT_FOUND
         * @userdata1    HUID of supplied Target
         * @userdata2[0:31]  Size of the list
         * @userdata2[32:63] Input CLASS
         * @devdesc      Parent of input CLASS for supplied Target is not found
         * @custdesc     Service Processor Firmware encountered an internal
         *               error
         */
         l_errl = new ERRORLOG::ErrlEntry(
                          ERRORLOG::ERRL_SEV_INFORMATIONAL,
                          TOD_UTIL_MOD_GET_PARENT,
                          TOD_PARENT_NOT_FOUND,
                          GETHUID(i_pTarget),
                          TWO_UINT32_TO_UINT64(l_list.size(), i_class));

    }

    TOD_EXIT("getParent");
    return l_errl;

}

// Wrapper function for TodControls::getDrawers instance
void getDrawers(const p10_tod_setup_tod_sel i_config,
                TodDrawerContainer& o_drawerList)
{
    Singleton<TodControls>::instance().getDrawers(i_config, o_drawerList);
}

// Wrapper function for TodControls::isProcBlackListed instance
bool isProcBlackListed (TARGETING::ConstTargetHandle_t i_procTarget)
{
    return Singleton<TodControls>::instance().isProcBlackListed(
        i_procTarget);
}

// Wrapper function for TodControls::getMDMT instance
TodProc* getMDMT(const p10_tod_setup_tod_sel i_config)
{
    return Singleton<TodControls>::instance().getMDMT(i_config);
}

// Wrapper function for TodControls::pickMdmt instance
errlHndl_t pickMdmt(const p10_tod_setup_tod_sel i_config)
{
    return Singleton<TodControls>::instance().pickMdmt(i_config);
}

// Wrapper function for TodControls::isTodRunning instance
errlHndl_t isTodRunning ( bool& o_isTodRunning)
{
    return Singleton<TodControls>::instance().isTodRunning(o_isTodRunning);
}

// Wrapper function for TodControls::checkGardStatusOfTarget instance
errlHndl_t checkGardStatusOfTarget(TARGETING::ConstTargetHandle_t i_target,
                                   bool&  o_isTargetGarded)
{
    return Singleton<TodControls>::instance().checkGardStatusOfTarget(
        i_target, o_isTargetGarded);
}


// Wrapper function for TodControls::destroy instance
void destroy(const p10_tod_setup_tod_sel i_config)
{
    Singleton<TodControls>::instance().destroy(i_config);
}

// Wrapper function for TodControls::buildTodDrawers instance
errlHndl_t buildTodDrawers(const p10_tod_setup_tod_sel i_config)
{
    return Singleton<TodControls>::instance().buildTodDrawers(i_config);
}

// Wrapper function for TodControls::buildGardedTargetsList instance
errlHndl_t buildGardedTargetsList()
{
    return Singleton<TodControls>::instance().buildGardedTargetsList();
}

// Wrapper function for TodControls::setConfigStatus instance
void setConfigStatus(const p10_tod_setup_tod_sel i_config,
                     const bool i_isConfigured )
{
    Singleton<TodControls>::instance().setConfigStatus(i_config,
                                                       i_isConfigured);
}

// Wrapper function for TodControls::getConfiguredMdmt instance
errlHndl_t getConfiguredMdmt(TARGETING::Target*& o_primaryMdmt,
                             TARGETING::Target*& o_secondaryMdmt)
{
    return Singleton<TodControls>::instance().getConfiguredMdmt(o_primaryMdmt,
        o_secondaryMdmt);
}

// Wrapper function for TodControls::writeTodProcData instance
errlHndl_t writeTodProcData(const p10_tod_setup_tod_sel i_config)
{
    return Singleton<TodControls>::instance().writeTodProcData(i_config);
}

void  clearGardedTargetsList()
{
    Singleton<TodControls>::instance().clearGardedTargetsList();
}

// Wrapper function for TodControls::queryActiveConfig instance
errlHndl_t queryActiveConfig(p10_tod_setup_tod_sel& o_activeConfig,
                             bool& o_isTodRunning,
                             TARGETING::Target*& o_mdmtOnActiveTopology,
                             bool i_determineTodRunningState)
{
    return Singleton<TodControls>::instance().queryActiveConfig(o_activeConfig,
        o_isTodRunning, o_mdmtOnActiveTopology, i_determineTodRunningState);
}

// Wrapper function for TodControls::setMdmtOfActiveConfig instance
void setMdmtOfActiveConfig(const p10_tod_setup_tod_sel i_config,
                           TodProc* i_proc,
                           TodDrawer* i_drawer)
{
    return Singleton<TodControls>::instance().setMdmtOfActiveConfig(i_config,
    i_proc, i_drawer);
}

// Wrapper function for TodControls::getConfigStatus instance
bool getConfigStatus(const p10_tod_setup_tod_sel i_config)
{
    return Singleton<TodControls>::instance().getConfigStatus(i_config);
}

}//end of namespace
