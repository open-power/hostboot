/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodControls.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
 *  @file TodControls.C
 *
 *  @brief This file implements the methods declared in TodControls class
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

#include <fapiPlatHwpInvoker.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <p8_scom_addresses.H>
#include <tod_init/tod_init_reasoncodes.H>
#include "TodAssert.H"
#include "TodTrace.H"
#include "TodDrawer.H"
#include "TodProc.H"
#include "TodTypes.H"
#include "TodControls.H"
#include "TodSvcUtil.H"
#include "proc_tod_setup/proc_tod_setup.H"
#include <list>
#include <map>

using namespace TARGETING;

namespace TOD
{

//------------------------------------------------------------------------------
//Static globals
//------------------------------------------------------------------------------
//const static char DIR_PATH_SERERATOR = '/';
//const static mode_t DIR_CREATION_MODE = 0777;
//const static char * FILE_WRITE_MODE = "w+";
//const static char * FILE_READ_MODE = "r";

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
//TodControls::pickMDMT
//******************************************************************************
errlHndl_t TodControls::pickMdmt(const proc_tod_setup_tod_sel i_config)
{
   TOD_ENTER("pickMdmt");
   errlHndl_t l_errHdl=NULL;

   //MDMT is the master processor that drives TOD signals to all the remaining
   //processors on the system, as such wherever possible algoritm will try to
   //ensure that primary and secondary topology provides redundancy of MDMT.

   //Whenever there is an existing MDMT for the opposite configuration following
   //considerations will go in deciding the MDMT for configuration passed
   //through i_config
   //1. MDMT will be chosen from a node other that the node on which other MDMDT
   //   belongs in multinode system
   //2. In single node system MDMT will be chosen from a different fabric node
   //   (tod drawer )
   //3. Last a processor different from MDMT on the same fabric node will be
   //   chosen, if other options are not feasible

    do
    {
        proc_tod_setup_tod_sel l_oppConfig = (i_config == TOD_PRIMARY ) ?
                                              TOD_SECONDARY : TOD_PRIMARY;

        TodProc * l_pTodProc = NULL;
        TodProc * l_oppMdmt = iv_todConfig[l_oppConfig].iv_mdmt;
        TodDrawerContainer l_todDrawerList;
        l_todDrawerList = iv_todConfig[i_config].iv_todDrawerList;

        TodProc * l_lastProcWithMaxCores = NULL;
        TodDrawer * l_lastMasterTodDrawer = NULL;
        uint32_t l_lastMaxCoreCount = 0;
        uint32_t l_coreCount=0;
        uint32_t l_maxPossibleCoresPerProc = getMaxPossibleCoresPerProc();

        if ( l_oppMdmt  )
        {
            //1.Try to find MDMT on a TOD drawer that is not on the same
            //  physical node as opposite MDMT

            //Iterate the list of TOD drawers
            for (TodDrawerContainer::iterator l_todDrawerIter =
                    l_todDrawerList.begin();
                    l_todDrawerIter != l_todDrawerList.end() ;
                    ++l_todDrawerIter)
            {
                //TodProc --> TodDrawer --> Node
                if ( l_oppMdmt->getParentDrawer()->getParentNodeTarget()->
                        getAttr<ATTR_HUID>()
                        !=
                     (*l_todDrawerIter)->getParentNodeTarget()->
                        getAttr<ATTR_HUID>())
                {
                    l_pTodProc = NULL;
                    l_coreCount = 0;
                    (*l_todDrawerIter)->
                    getProcWithMaxCores(NULL,l_pTodProc,l_coreCount);
                    if ( l_pTodProc )
                    {
                        TOD_INF("returned core count = %d ",l_coreCount);
                        if ( l_coreCount > l_lastMaxCoreCount)
                        {
                            l_lastProcWithMaxCores = l_pTodProc;
                            l_lastMaxCoreCount = l_coreCount;
                            l_lastMasterTodDrawer = (*l_todDrawerIter);
                            if (l_lastMaxCoreCount == l_maxPossibleCoresPerProc)
                            {
                                break;
                            }
                        }
                    }

                }
            }

            if ( l_lastProcWithMaxCores )
            {
                l_lastMasterTodDrawer->setMasterDrawer(true);
                iv_todConfig[i_config].iv_mdmt = l_lastProcWithMaxCores;
                l_lastProcWithMaxCores->setMasterType(TodProc::TOD_MASTER);
                break;
            }

            //2.Try to find MDMT on a TOD drawer that is on the same physical
            //  node as the possible opposite MDMT but on different TOD drawer
            for (TodDrawerContainer::iterator l_todDrawerIter =
                    l_todDrawerList.begin();
                    l_todDrawerIter != l_todDrawerList.end() ;
                    ++l_todDrawerIter)
            {
                if ( (l_oppMdmt->getParentDrawer()->getParentNodeTarget()->
                            getAttr<ATTR_HUID>()
                            ==
                     (*l_todDrawerIter)->getParentNodeTarget()->
                            getAttr<ATTR_HUID>())
                        //Same node as opposite MDMT
                        &&
                     (l_oppMdmt->getParentDrawer()->getId()
                            !=
                     (*l_todDrawerIter)->getId()))//Different Drawer
                {
                    l_pTodProc = NULL;
                    l_coreCount = 0;
                    (*l_todDrawerIter)->
                        getProcWithMaxCores(NULL,l_pTodProc,l_coreCount);
                    if ( l_pTodProc )
                    {
                        if ( l_coreCount > l_lastMaxCoreCount)
                        {
                            l_lastProcWithMaxCores =  l_pTodProc;
                            l_lastMaxCoreCount = l_coreCount;
                            l_lastMasterTodDrawer = (*l_todDrawerIter);
                            if (l_lastMaxCoreCount == l_maxPossibleCoresPerProc)
                            {
                                break;
                            }
                        }

                    }

                }
            }

            if ( l_lastProcWithMaxCores )
            {
                l_lastMasterTodDrawer->setMasterDrawer(true);
                iv_todConfig[i_config].iv_mdmt = l_lastProcWithMaxCores;
                l_lastProcWithMaxCores->setMasterType(TodProc::TOD_MASTER);
                break;
            }

            //3.Try to find MDMT on the same TOD drawer as the TOD Drawer of
            //  opposite MDMT
            for (TodDrawerContainer::iterator l_todDrawerIter =
                    l_todDrawerList.begin();
                    l_todDrawerIter != l_todDrawerList.end() ;
                    ++l_todDrawerIter)
            {
                l_coreCount = 0;
                if ( l_oppMdmt->getParentDrawer()->getId() ==
                        (*l_todDrawerIter)->getId() )
                {
                    //This is the TOD drawer on which opposite MDMT exists,
                    //try to avoid processor chip of opposite MDMT while
                    //getting the proc with max cores
                    (*l_todDrawerIter)->getProcWithMaxCores(
                            iv_todConfig[l_oppConfig].iv_mdmt,l_pTodProc
                            ,l_coreCount);
                    if ( l_pTodProc )
                    {
                        iv_todConfig[i_config].iv_mdmt = l_pTodProc;
                        (*l_todDrawerIter)->setMasterDrawer(true);
                        l_pTodProc->setMasterType(TodProc::TOD_MASTER);
                        break;
                    }
                }
            }

            if ( iv_todConfig[i_config].iv_mdmt )
            {
                break;
            }

            //If we reach here only option left is MDMT on the other config so
            //select it. So we look for a proc in this config's set of TOD
            //drawers, find the one which is same as the MDMT on the other
            //config (based on the HUID).
            bool l_mdmtFound = false;
            for(TodDrawerContainer::iterator l_drwItr =
                iv_todConfig[i_config].iv_todDrawerList.begin();
                l_drwItr != iv_todConfig[i_config].iv_todDrawerList.end();
                ++l_drwItr)
            {
                const TodProcContainer& l_procs = (*l_drwItr)->getProcs();
                for(TodProcContainer::const_iterator
                    l_procItr = l_procs.begin();
                    l_procItr != l_procs.end();
                    ++l_procItr)
                {
                    if( (*l_procItr)->getTarget()->getAttr<ATTR_HUID>()
                          ==
                        (iv_todConfig[l_oppConfig].iv_mdmt)->
                        getTarget()->getAttr<ATTR_HUID>() )
                    {
                        iv_todConfig[i_config].iv_mdmt = (*l_procItr);
                        (*l_procItr)->setMasterType(TodProc::TOD_MASTER);
                        (*l_drwItr)->setMasterDrawer(true);
                        l_mdmtFound = true;
                        break;
                    }
                }

                if(l_mdmtFound)
                {
                    break;
                }
            }

            if(l_mdmtFound)
            {
                break;
            }
        }
        else
        { //There is no MDMT configured for the other topology hence select
          //the MDMT from any TOD drawer
            for (TodDrawerContainer::iterator l_todDrawerIter =
                    l_todDrawerList.begin();
                    l_todDrawerIter != l_todDrawerList.end() ;
                    ++l_todDrawerIter)
            {
                l_pTodProc = NULL;
                l_coreCount = 0;
                (*l_todDrawerIter)->getProcWithMaxCores(
                        NULL,l_pTodProc,l_coreCount);
                if ( l_pTodProc )
                {
                    if ( l_coreCount > l_lastMaxCoreCount)
                    {
                        l_lastProcWithMaxCores =  l_pTodProc;
                        l_lastMaxCoreCount = l_coreCount;
                        l_lastMasterTodDrawer = (*l_todDrawerIter);
                        if (l_lastMaxCoreCount == l_maxPossibleCoresPerProc)
                        {
                            break;
                        }
                    }
                }
            }

            if ( l_lastProcWithMaxCores )
            {
                l_lastMasterTodDrawer->setMasterDrawer(true);
                iv_todConfig[i_config].iv_mdmt = l_lastProcWithMaxCores;
                l_lastProcWithMaxCores->setMasterType(TodProc::TOD_MASTER);
                break;
            }
        }

        if ( !iv_todConfig[i_config].iv_mdmt )
        {
            TOD_ERR("MDMT NOT FOUND for configuration 0x%02X",i_config);

            /*@
             * @errortype
             * @reasoncode   TOD_NO_MASTER_PROC
             * @moduleid     TOD_PICK_MDMT
             * @userdata1    TOD configuration type
             * @devdesc      MDMT could not be found for the supplied topology
             *               type
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_PICK_MDMT,
                               TOD_NO_MASTER_PROC,
                               i_config);
        }

    }while(0);

    if ( iv_todConfig[i_config].iv_mdmt )
    {
        TOD_INF("MDMT for configuration %d , is proc "
                "0%08X", i_config, iv_todConfig[i_config].iv_mdmt->
                getTarget()->getAttr<ATTR_HUID>());
    }
    TOD_EXIT("pickMdmt. errHdl = %p", l_errHdl);
    return l_errHdl;

}

//******************************************************************************
//TodControls::buildTodDrawers
//******************************************************************************
errlHndl_t  TodControls::buildTodDrawers(
        const proc_tod_setup_tod_sel i_config)
{
    TOD_ENTER("buildTodDrawers");
    errlHndl_t l_errHdl = NULL;

    do{

        TARGETING::TargetHandleList l_funcNodeTargetList;

        //Get the system pointer
        TARGETING::Target* l_pSysTarget = NULL;
        (void)TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

        //We should not be reaching here without a valid system target
        TOD_ASSERT(l_pSysTarget,"NULL system target ");

        //Build the list of functional nodes
        l_errHdl = getFuncNodeTargetsOnSystem( l_pSysTarget,
                                               l_funcNodeTargetList);
        if ( l_errHdl )
        {
            TOD_ERR("For System target 0x%08X getFuncNodeTargetsOnSystem "
                    "returned  error ",l_pSysTarget->getAttr<ATTR_HUID>());
            break;
        }

        //If there was no functional node found then we must return
        if ( l_funcNodeTargetList.empty() )
        {
            TOD_ERR("For System target 0x%08X no functional node found ",
                    l_pSysTarget->getAttr<TARGETING::ATTR_HUID>());
            /*@
             * @errortype
             * @reasoncode   TOD_NO_FUNC_NODE_AVAILABLE
             * @moduleid     TOD_BUILD_TOD_DRAWERS
             * @userdata1    system target's HUID
             * @devdesc      MDMT could not find a functional node
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_BUILD_TOD_DRAWERS,
                               TOD_NO_FUNC_NODE_AVAILABLE,
                               l_pSysTarget->getAttr<ATTR_HUID>());
            break;
        }

        //For each node target find the prcessor chip on it
        TARGETING::TargetHandleList l_funcProcTargetList;

        TARGETING::PredicateCTM
            l_procCTM(TARGETING::CLASS_CHIP,TARGETING::TYPE_PROC);

        TARGETING::PredicateHwas l_funcPred;
        l_funcPred.functional(true);
        TARGETING::PredicatePostfixExpr l_funcProcPostfixExpr;
        l_funcProcPostfixExpr.push(&l_procCTM).push(&l_funcPred).And();

        TodDrawerContainer& l_todDrawerList =
            iv_todConfig[i_config].iv_todDrawerList;
        TodDrawerContainer::iterator l_todDrawerIter;
        bool b_foundDrawer = false;

        for( uint32_t l_nodeIndex = 0;
                l_nodeIndex < l_funcNodeTargetList.size();
                ++l_nodeIndex )
        {
            l_funcProcTargetList.clear();

            //Find the funcational Proc targets on the system
            TARGETING::targetService().getAssociated(l_funcProcTargetList,
                    l_funcNodeTargetList[l_nodeIndex],
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &l_funcProcPostfixExpr);

            //Go over the list of procs and insert them in respective fabric
            //node list ( TOD drawer )
            for ( uint32_t l_procIndex =0 ;
                    l_procIndex < l_funcProcTargetList.size();
                    ++l_procIndex )
            {
                b_foundDrawer = false;
                //Traverse over the fabric node list (TOD drawer) and find if
                //there is an existing fabric node for this proc

                for ( l_todDrawerIter = l_todDrawerList.begin() ;
                        l_todDrawerIter != l_todDrawerList.end() ;
                        ++l_todDrawerIter)
                {
                    if ( (*l_todDrawerIter)->getId() ==
                            l_funcProcTargetList[l_procIndex]->
                            getAttr<ATTR_FABRIC_NODE_ID>())
                    {
                        //Add the proc to this fabric node, such that
                        //TodProc has the target pointer and the pointer to
                        //the TOD drawer to which it belongs
                        TodProc *l_procPtr =
                            new TodProc
                            (l_funcProcTargetList[l_procIndex],
                             (*l_todDrawerIter));
                        (*l_todDrawerIter)->addProc(l_procPtr);
                        l_procPtr = NULL; //Nullifying the pointer after
                        //transferring ownership

                        b_foundDrawer = true;
                        break;
                    }

                } // end drawer list loop

                if (!b_foundDrawer )
                {
                    //Create a new TOD drawer and add it to the TOD drawer list
                    //Create a TOD drawer with the fabric node id and the
                    //pointer to the node to which this fabric node belongs
                    TodDrawer *l_pTodDrawer = new
                        TodDrawer(l_funcProcTargetList[l_procIndex]->
                                getAttr<ATTR_FABRIC_NODE_ID>(),
                                l_funcNodeTargetList[l_nodeIndex]);

                    //Create a TodProc passing the target pointer and the
                    //pointer of TodDrawer to which this processor belongs
                    TodProc *l_pTodProc = new
                        TodProc(l_funcProcTargetList[l_procIndex],
                                l_pTodDrawer);

                    //push the processor ( TodProc ) , into the TOD drawer
                    l_pTodDrawer->addProc(l_pTodProc);

                    //push the Tod drawer ( TodDrawer ) , into the
                    //TodControls
                    l_todDrawerList.push_back(l_pTodDrawer);
                    //Nullify the pointers after transfering the ownership
                    l_pTodDrawer = NULL;
                    l_pTodProc = NULL;

                }

            }// end proc list loop

        } // end node list loop

        //Validate that we had atlease one TOD drawer at the end of this process
        //else generate an error
        if (iv_todConfig[i_config].iv_todDrawerList.empty())
        {
            TOD_ERR("No TOD drawer could be built for the configuration "
                    " %s ", (i_config == TOD_PRIMARY ? "Primary " :
                        "Secondary") );
            /*@
             * @errortype
             * @reasoncode   TOD_NO_DRAWERS
             * @moduleid     TOD_BUILD_TOD_DRAWERS
             * @userdata1    TOD configuration
             * @devdesc      No TOD drawer could be configured for this topology
             *               type
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                               TOD_BUILD_TOD_DRAWERS,
                               TOD_NO_DRAWERS,
                               i_config);
        }

    }while(0);
    TOD_EXIT("buildTodDrawers. errHdl = %p", l_errHdl);
    return l_errHdl;
}

//******************************************************************************
//TodControls::getTodConfigState
//******************************************************************************
errlHndl_t TodControls::getTodConfigState(
        TOD_CONFIG_STATE& o_configState,
        proc_tod_setup_tod_sel& o_activeConfig,
        bool& o_isTodRunning)const
{
    TOD_ENTER("getTodConfigState");
    errlHndl_t l_errHdl = NULL;
    o_configState = TOD_UNCHANGED;
    o_activeConfig = TOD_PRIMARY;
    o_isTodRunning = false;

    do
    {
        //Get the currently active TOD configuration
        l_errHdl = queryActiveConfig (o_activeConfig,o_isTodRunning);
        if ( l_errHdl )
        {
            TOD_ERR("Call to queryActiveConfig failed ");
            break;
        }
        //Need to read the TodSystemFile to decide if HW configuration has
        //changed since the last time TOD was configured
        std::vector<TodChipData> l_todChipDataVector;
        l_errHdl = TodControls::readTodProcDataFromFile(l_todChipDataVector);
        if ( l_errHdl ) //Indicates hard failure not limited to failure of tod
            //logic only, we cannot continue with flow
        {
            TOD_ERR("Failed loading TodChipData from TodSystemFile");
            break;
        }

        //Determine if the TOD HW has changed since the last time topology was
        //created
        //1) File data is valid but HW has changed => Report TOD_MODIFIED
        //2) File data is valid and HW has not changed => Report TOD_UNCHANGED
        //3) Authenticity of file data is in question => Report
        //TOD_UNKNOWN

        //Check if TodSystemFile has topology data for atleast one node
        if ( hasNoValidData ( l_todChipDataVector ))
        {
            TOD_INF("No valid data found in the file TodSystemFile");
            o_configState = TOD_UNKNOWN;
            break;
        }

        //For each functional processor present in the system, if we
        //have, old  configuration data in the TodSystemConfig file then
        //validate it.

        //Get the processors present in the system
        TARGETING::PredicateCTM
            l_procFilter(TARGETING::CLASS_CHIP,TARGETING::TYPE_PROC,
                    TARGETING::MODEL_NA);

        TARGETING::PredicateHwas l_presencePredicate;
        l_presencePredicate.present(true);

        TARGETING::PredicatePostfixExpr l_presenceAndProcChipFilter;
        l_presenceAndProcChipFilter.push(&l_procFilter).
            push(&l_presencePredicate).And();

        TARGETING::TargetRangeFilter l_filter(
                TARGETING::targetService().begin(),
                TARGETING::targetService().end(),
                &l_presenceAndProcChipFilter);

        bool l_state = false;  //Variable for keeping functional state of
        //the processor
        uint32_t l_ordinalId = TOD_INVALID_UNITID;
        //Initializing to some value not expected to be ordinal id

        ecmdDataBufferBase l_chipCtrlRegBuf(64);

        //Initialize l_chipCtrlRegBuf it will be used later

        FAPI_INVOKE_HWP(l_errHdl, init_chip_ctrl_reg, l_chipCtrlRegBuf);
        if ( l_errHdl )
        {
            TOD_ERR("init_chip_ctrl_reg returned error ");
            break;
        }

        for ( ; l_filter ; ++l_filter )
        {
            l_state = false;
            if ((*l_filter)->getAttr<ATTR_HWAS_STATE>().functional)
            {
                l_state = true;
            }

            // use position attribute on one drawer only machine
            l_ordinalId=(*l_filter)->getAttr<ATTR_POSITION>();

            if ( l_state ) //Functional processor
            {
                //Check if TodSystemData file also indicates the processor as
                //functional

                //Indexing into l_todChipDataVector is safe as size of vector is
                //always determined by the maximum possible processors for this
                //system type
                if(((l_todChipDataVector[l_ordinalId].header.flags) &
                            TOD_FUNC) != 0 )
                {

                    //File data says that the chip is functional do some more
                    //validation on the data

                    //Check if the chip control register (0x40010) data is valid
                    //This data does not depend on topology, so it should tally
                    if ( (l_todChipDataVector[l_ordinalId].regs.ccr) !=
                            l_chipCtrlRegBuf.getWord(0)  )
                    {
                        TOD_INF("Chip control register read from TodSystemData"
                                "is not valid for the processor 0x%08X",
                                (*l_filter)->getAttr<TARGETING::ATTR_HUID>());
                        //We do not have a valid data no need to continue
                        //further
                        o_configState = TOD_UNKNOWN;
                        break;
                    }
                }
                else
                {
                    //New hardware has been added
                    TOD_INF("New processor detected 0x%08X",
                            (*l_filter)->getAttr<ATTR_HUID>());
                    o_configState = TOD_MODIFIED;
                }

            }
            else
            {
                //Check if this chip was functional earlier
                if ( ((l_todChipDataVector[l_ordinalId].header.flags) &
                            TOD_FUNC) != 0 )
                {
                    //HW has been removed
                    o_configState = TOD_MODIFIED;
                    TOD_INF("Processor 0x%08X is no more available ",
                            (*l_filter)->getAttr<ATTR_HUID>());
                }
            }
        }

    }while(0);

    TOD_EXIT(" config state = %d, active config = %d, TOD HW State = "
            "%d errHdl = %p",
            o_configState, o_activeConfig , o_isTodRunning, l_errHdl);

    return l_errHdl;
}

//******************************************************************************
//TodControls::isTodRunning
//******************************************************************************
errlHndl_t TodControls::isTodRunning(bool& o_isTodRunning)const
{
    TOD_ENTER("isTodRunning");
    errlHndl_t l_errHdl = NULL;
    TARGETING::Target* l_primaryMdmt=NULL;
    TARGETING::Target* l_secondaryMdmt=NULL;
    o_isTodRunning = false;

    do
    {
        //Read the TOD HW to get the configured MDMT
        l_errHdl = getConfiguredMdmt(l_primaryMdmt,l_secondaryMdmt);
        if ( l_errHdl )
        {
            TOD_ERR("Failed getting configured MDMTs" );
            break;
        }

        if ( l_primaryMdmt || l_secondaryMdmt ) //If there is atleast one MDMT
            //configured , check the chipTOD HW status by reading the TOD
            //status register TOD_PSS_MSS_STATUS_REG_00040008
        {
            ecmdDataBufferBase l_primaryMdmtBuf(64);
            ecmdDataBufferBase l_secondaryMdmtBuf(64);

            if ( l_primaryMdmt )
            {
                l_errHdl = todGetScom(l_primaryMdmt,
                        TOD_PSS_MSS_STATUS_REG_00040008,
                        l_primaryMdmtBuf);
                if ( l_errHdl )
                {
                    TOD_ERR("Scom failed for status register "
                            "TOD_PSS_MSS_STATUS_REG_00040008 on primary MDMT");
                    break;
                }
            }

            if ( l_secondaryMdmt )
            {
                l_errHdl = todGetScom(l_secondaryMdmt,
                        TOD_PSS_MSS_STATUS_REG_00040008,
                        l_secondaryMdmtBuf);
                if ( l_errHdl )
                {
                    TOD_ERR("Scom failed for status register "
                           "TOD_PSS_MSS_STATUS_REG_00040008 on secondary MDMT");
                    break;
                }
            }

            //If all the bits of TOD_PSS_MSS_STATUS_REG_00040008 are off then
            //ChipTOD HW is not running
            if ((l_primaryMdmtBuf.getWord(0) == 0 ) &&
                    (l_secondaryMdmtBuf.getWord(0)== 0))
            {
                break;
            }

            o_isTodRunning = true;
        }

    }while(0);

    TOD_EXIT("TOD HW State = %d errHdl = %p",o_isTodRunning, l_errHdl);
    return l_errHdl;
}

//******************************************************************************
//TodControls::queryActiveConfig
//******************************************************************************
errlHndl_t TodControls::queryActiveConfig(
        proc_tod_setup_tod_sel& o_activeConfig,
        bool& o_isTodRunning)const
{
    TOD_ENTER("queryActiveConfig");
    errlHndl_t l_errHdl = NULL;
    TARGETING::Target* l_primaryMdmt=NULL;
    TARGETING::Target* l_secondaryMdmt=NULL;

    o_isTodRunning = false;
    o_activeConfig = TOD_PRIMARY;

    do
    {
        //Read the configured Mdmt from TOD HW
        l_errHdl = getConfiguredMdmt(l_primaryMdmt,l_secondaryMdmt);
        if ( l_errHdl )
        {
            TOD_ERR("Failed to get configured MDMTs" );
            break;
        }

        if ( l_primaryMdmt || l_secondaryMdmt ) //If there is atleast one MDMT
            //configured,` check the ChipTOD HW status by reading the TOD
            //status register TOD_PSS_MSS_STATUS_REG_00040008
        {
            ecmdDataBufferBase l_primaryMdmtBuf(64);
            ecmdDataBufferBase l_secondaryMdmtBuf(64);

            if ( l_primaryMdmt )
            {
                l_errHdl = todGetScom(l_primaryMdmt,
                        TOD_PSS_MSS_STATUS_REG_00040008,
                        l_primaryMdmtBuf);
                if ( l_errHdl )
                {
                    TOD_ERR("Scom failed for status register "
                            "TOD_PSS_MSS_STATUS_REG_00040008 on primary MDMT");
                    break;
                }
            }

            if ( l_secondaryMdmt )
            {
                l_errHdl = todGetScom(l_secondaryMdmt,
                        TOD_PSS_MSS_STATUS_REG_00040008,
                        l_secondaryMdmtBuf);
                if ( l_errHdl )
                {
                    TOD_ERR("Scom failed for status register "
                            "TOD_PSS_MSS_STATUS_REG_00040008 secondary MDMT ");
                    break;
                }
            }

            //If all the bits of TOD_PSS_MSS_STATUS_REG_00040008 are off then
            //ChipTOD HW is not running
            if ((l_primaryMdmtBuf.getWord(0) == 0 ) &&
                    (l_secondaryMdmtBuf.getWord(0)== 0))
            {
                break;
            }

            o_isTodRunning = true;

            //First 3 bits of TOD_PSS_MSS_STATUS_REG_00040008  indicates
            //active TOD topology
            // [0:2] == '111' secondary, '000' is primary - just check bit 0

            //Putting the below check because of  past TOD HW error.
            //Both primary and secondary MDMT would claim that it is the active
            //one,this happened during CHARM operation after failover from
            //primary to econdary
            //May be that error does not exists in P8 HW but in case it still
            //exists we will be able to catch it
            if (  l_primaryMdmt &&  l_secondaryMdmt )
            {
                if (
                        l_primaryMdmtBuf.isBitSet
                        (TOD_PSS_MSS_STATUS_REG_00040008_ACTIVE_BIT)
                        !=
                        l_secondaryMdmtBuf.isBitSet
                        (TOD_PSS_MSS_STATUS_REG_00040008_ACTIVE_BIT)
                   )
                {
                    TOD_ERR("TOD HW error, primary and secondary MDMT do not"
                            "agree on bits 0 of TOD status register 0x40008");
                    /*@
                     * @errortype
                     * @reasoncode   TOD_HW_ERROR
                     * @moduleid     TOD_QUERY_ACTIVE_CONFIG
                     * @userdata1    Status register bits of primary MDMT
                     * @userdata2    Status register bits of secondary MDMT
                     * @devdesc      Error: primary and secondary MDMT do not
                     *               agree on bits 0 of TOD status register
                     *               0x40008
                     */
                    l_errHdl = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      TOD_QUERY_ACTIVE_CONFIG,
                                      TOD_HW_ERROR,
                                      l_primaryMdmtBuf.getWord(0),
                                      l_secondaryMdmtBuf.getWord(0) );
                    break;
                }
            }

            if(l_primaryMdmtBuf.isBitSet
                (TOD_PSS_MSS_STATUS_REG_00040008_ACTIVE_BIT))
            {
                TOD_INF("Primary MDMT says secondary is configured ");
                o_activeConfig = TOD_SECONDARY;
                //  If the primary says the secondary is active then what the
                //  secondary MDMT says is not important - no more checking
                //  required.
                break;
            }

            //The secondaryMDMT only needs to be checked if the primaryMDMT
            //said it is active ( i.e. bit 0 is clear )

            //If the secondary says the secondary is active then primary was
            //not found
            if ( l_secondaryMdmtBuf.isBitSet
                    (TOD_PSS_MSS_STATUS_REG_00040008_ACTIVE_BIT))
            {
                TOD_INF("Secondary MDMT says secondary is configured ");
                o_activeConfig = TOD_SECONDARY;
                break;
            }
        }
        //Else not yet initialized, just return primary

    }while(0);

    TOD_EXIT("queryActiveConfig. errHdl = %p", l_errHdl);
    return l_errHdl;
}

//******************************************************************************
//TodControls::getConfiguredMdmt
//******************************************************************************
errlHndl_t TodControls::getConfiguredMdmt(
        TARGETING::Target*& o_primaryMdmt,
        TARGETING::Target*& o_secondaryMdmt) const
{
    TOD_ENTER("getConfiguredMdmt");
    errlHndl_t l_errHdl = NULL;
    o_primaryMdmt = NULL;
    o_secondaryMdmt = NULL;

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

        ecmdDataBufferBase l_todCtrlReg(64);

        //TOD_PSS_MSS_CTRL_REG_00040007

        TARGETING::TargetRangeFilter l_filter(
                TARGETING::targetService().begin(),
                TARGETING::targetService().end(),
                &l_stateAndProcChipFilter);

        //Read the TOD control register TOD_PSS_MSS_CTRL_REG_00040007 for each
        //processor and check for bits 1 and 9
        for (   ; l_filter; ++l_filter  )
        {
            l_errHdl = todGetScom(*l_filter,
                    TOD_PSS_MSS_CTRL_REG_00040007,
                    l_todCtrlReg);

            if ( l_errHdl )
            {
                TOD_ERR("Scom failed for target 0x%08X on register"
                        "TOD_PSS_MSS_CTRL_REG_00040007 ",
                        (*l_filter)->getAttr<ATTR_HUID>());
                break;
            }

            if (
                l_todCtrlReg.isBitSet
                (TOD_PSS_MSS_CTRL_REG_00040007_PRIMARY_MDMT_BIT) )//primary MDMT
            {
                o_primaryMdmt = *l_filter;
                TOD_INF("found primary MDMT HUID = 0x%08X",
                        o_primaryMdmt->getAttr<ATTR_HUID>());
            }

            if (
                l_todCtrlReg.isBitSet
                (TOD_PSS_MSS_CTRL_REG_00040007_SECONDARY_MDMT_BIT) )
                //secondary MDMT
            {
                o_secondaryMdmt = *l_filter;
                TOD_INF("found secondary MDMT HUID = 0x%08X",
                        o_secondaryMdmt->getAttr<ATTR_HUID>());
            }

            if ( o_primaryMdmt && o_secondaryMdmt )
            {
                break;
            }
        }

    }while(0);

    TOD_EXIT("getConfiguredMdmt. errHdl = %p", l_errHdl);
    return l_errHdl;
}

//******************************************************************************
//TodControls::destroy
//******************************************************************************
void TodControls::destroy(const proc_tod_setup_tod_sel i_config)
{
    TOD_ENTER("destroy");

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
    iv_todConfig[i_config].iv_mdmt = NULL;
    iv_todConfig[i_config].iv_isConfigured = false;

    TOD_EXIT("destroy");
}

//******************************************************************************
//TodControls::writeTodProcData
//******************************************************************************
errlHndl_t TodControls::writeTodProcData(
        const proc_tod_setup_tod_sel i_config)
{
    TOD_ENTER("writeTodProcData");
    errlHndl_t l_errHdl = NULL;

    do
    {
        //As per the requirement specified by PHYP/HDAT, HB needs to fill
        //data for every chip that can be installed on the system.
        //It is also required that chip ID match the index of the entry in the
        //array so we can possibly have valid chip data at different indexes in
        //the array and the intermittent locations filled with the chip entries
        //that does not exist on the system. All such entires will have default
        //non-significant values

        TodChipData blank;
        uint32_t l_maxProcCount = getMaxProcsOnSystem();

        TOD_INF("Max possible processor chips for this system when configured "
                "completely is %d",l_maxProcCount);

        iv_todChipDataVector.assign(l_maxProcCount,blank);

        TARGETING::ATTR_POSITION_type l_ordId = 0x0;
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
                    (*l_procItr)->getTarget()->getAttr<ATTR_POSITION>();

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
                             getAttr<ATTR_HUID>())
                            ==
                            ((*l_procItr)->getTarget()->
                             getAttr<ATTR_HUID>())
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
                             getAttr<ATTR_HUID>())
                            ==
                            ((*l_procItr)->getTarget()->
                             getAttr<ATTR_HUID>())
                       )
                    {

                        iv_todChipDataVector[l_ordId].header.flags |=
                            TOD_SEC_MDMT;
                    }

                }

            }
        }

        //Done with setting the data write it to the file
        l_errHdl = writeTodProcDataToFile();
        if ( l_errHdl )
        {
            TOD_ERR( "Failed writing TOD chip data to the file ");
            break;
        }

    }while(0);

    TOD_EXIT("writeTodProcData. errHdl = %p", l_errHdl);
    return l_errHdl;

}//end of writeTodProcData


//******************************************************************************
//TodControls::writeTodProcDataToFile()
//******************************************************************************
errlHndl_t TodControls::writeTodProcDataToFile()
{
    TOD_ENTER("writeTodProcDataToFile");
    errlHndl_t l_errHdl = NULL;
#ifndef __HOSTBOOT_MODULE
    do
    {
        std::string l_fileOpenMode(FILE_WRITE_MODE);
        char l_fileName[128];
        l_errHdl = getTodProcDataFilePath(l_fileName);
        if(l_errHdl)
        {
            TOD_ERR("Failed getting the file path for sharing TOD data with "
                    "   HDAT ");
            break;
        }

        //Create the parent directory in which file has to be written
        std::string l_dirPath = l_fileName.substr
            (0,l_fileName.find_last_of(DIR_PATH_SERERATOR));
        int rc = mkdir(l_dirPath.c_str(),DIR_CREATION_MODE);

        if ( rc != 0 )
        {
            //EEXIST just means it already exists, which is fine
            if (errno != EEXIST)
            {
                TOD_ERR("Error creating the directory %s "
                        "system returned error code %d",
                        l_dirPath.c_str(),errno);
                break;
            }
        }

        UtilFile file;
        l_errHdl = file.open(l_fileName.c_str(), l_fileOpenMode.c_str());
        if ( l_errHdl )
        {
            TOD_ERR("Failed opening the file %s, with mode %s" ,
                    l_fileName.c_str(),l_fileOpenMode.c_str());
            break;
        }

        TodChipDataContainer::iterator l_chipDataItr =
            iv_todChipDataVector.begin();
        file.write(reinterpret_cast<void *>((&(*l_chipDataItr))),
                (iv_todChipDataVector.size()* sizeof(TodChipData)));

        l_errHdl = file.getLastError();
        if ( l_errHdl )
        {
            TOD_ERR("Failed writing the tod chip data to file ");
            break;
        }

        l_errHdl = file.close();
        if ( l_errHdl )
        {
            TOD_ERR("Failed closing the file %s",  l_fileName.c_str());
            break;
        }

    }while(0);
#endif
    TOD_EXIT("writeTodProcDataToFile. errHdl = %p", l_errHdl);
    return l_errHdl;

}

//*****************************************************************************
//TodControls::readTodProcDataFromFile
//******************************************************************************
errlHndl_t TodControls::readTodProcDataFromFile(
        std::vector<TodChipData>& o_todChipDataVector )const
{
    TOD_ENTER("readTodProcDataFromFile");
    errlHndl_t l_errHdl = NULL;
#ifndef __HOSTBOOT_MODULE
    do
    {
        std::string l_todProcDataFile;
        UtilFile l_file;

        l_errHdl = getTodProcDataFilePath(l_todProcDataFile);
        if(l_errHdl)
        {
            TOD_ERR("Failed getting the path of TodSystemFile ");
            break;
        }

        if ( !UtilFile::exists(l_todProcDataFile.c_str()))
        {
            TOD_INF("File %s , does not exist",l_todProcDataFile.c_str());
            break;
        }

        //Open the file for reading
        l_errHdl = l_file.open(l_todProcDataFile.c_str(),FILE_READ_MODE);
        if ( l_errHdl )
        {
            TOD_ERR("Failed opening the file %s, with mode %s" ,
                    l_todProcDataFile.c_str(),FILE_READ_MODE);
            break;
        }

        //The amount of data stored on TodSystemFile always depend on the
        //maximum processor possible for the given system type
        uint32_t l_maxProcCount = getMaxProcsOnSystem();

        uint32_t l_bytesToRead = l_file.size();

        if ( (l_bytesToRead == 0)  || (l_bytesToRead > (l_maxProcCount *
            sizeof(TodChipData))))  //Check for further safeguards
        {
            TOD_ERR("Error, File %s is corrupted"
                    ,l_todProcDataFile.c_str());

            //Commit this locally, because system can still proceed if TOD HW is
            //not running
            l_errHdl->commit(HWSV_COMP_ID, ERRL_ACTION_REPORT,
                    ERRL_SEV_INFORMATIONAL);
            delete l_errHdl;
            l_errHdl = 0;
            break;
        }

        TodChipData blank;
        o_todChipDataVector.assign(l_maxProcCount,blank); //Allocate memory with
        //default values

        //Read the data from file
        l_file.read(reinterpret_cast<void *>(&(*(o_todChipDataVector.begin()))),
                l_bytesToRead);


        l_errHdl = l_file.getLastError();
        if ( l_errHdl )
        {
            TOD_ERR("Failed reading tod chip data from file ");
            break;

        }

        l_errHdl = l_file.close();
        if ( l_errHdl )
        {
            TOD_ERR("Failed closing the file %s", l_todProcDataFile.c_str());
            break;
        }
        //Not going to close the file in error path , UtilFile will close it.

    }while(0);
#endif
     TOD_EXIT("readTodProcDataFromFile. errHdl = %p", l_errHdl);
     return l_errHdl;
}

//******************************************************************************
//TodControls::getTodProcDataFilePath()
//******************************************************************************
errlHndl_t TodControls::getTodProcDataFilePath(char * o_fileName)
    const
{
    TOD_ENTER("getTodProcDataFilePath");
    errlHndl_t l_errHdl = NULL;
#ifndef __HOSTBOOT_MODULE
    char *l_buf = NULL;
    do
    {
        uint32_t     l_fileSize = 0;
        const char* l_stringToAppend = NULL;
        const char* l_filePathKey[2] =
        {   P1_ROOT_PATH,
            CINI_SYSTODFILE_PATH
        };


        l_errHdl = UtilReg::path(l_filePathKey,(sizeof(l_filePathKey) /
        sizeof(l_filePathKey[0])),
        l_stringToAppend,l_buf,l_fileSize);

        if ( l_errHdl )
        {
            TOD_ERR("Failed getting file path from the registry using keys"
            "P1_ROOT_PATH and CINI_SYSTODFILE_PATH " );
            break;
        }

        o_fileName = std::string(l_buf);
        TOD_INF("Found file path %s",o_fileName.c_str());


    }while(0);

    if ( l_buf )
    {
        delete l_buf;
    }
#endif
    TOD_EXIT("getTodProcDataFilePath. errHdl = %p", l_errHdl);
    return l_errHdl;
}


//******************************************************************************
//HwsvTodControls::hasNoValidData()
//******************************************************************************
bool TodControls::hasNoValidData(const std::vector<TodChipData>&
        i_todChipDataVector)const
{
    TOD_ENTER("hasNoValidData");
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


}//end of namespace
