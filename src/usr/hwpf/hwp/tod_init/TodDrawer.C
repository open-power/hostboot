/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodDrawer.C $                       */
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
 *  @file TodDrawer.C
 *
 *  @brief The file implements methods of TodDrawer class
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
#include "TodSvcUtil.H"
#include "TodDrawer.H"
#include "TodAssert.H"
#include "TodTrace.H"
#include <tod_init/tod_init_reasoncodes.H>


namespace TOD
{

//******************************************************************************
// TodDrawer::TodDrawer
//******************************************************************************
TodDrawer::TodDrawer(const uint8_t i_drawerId,
                     const TARGETING::Target* i_parentNode):
    iv_todDrawerId(i_drawerId),
    iv_isTodMaster(false),
    iv_parentNodeTarget(i_parentNode)
{
    TOD_ASSERT(iv_parentNodeTarget,
           "Error creating TOD drawer with id 0x%.2X, parent node"
           "pointer passed as NULL", i_drawerId);

    TOD_ENTER("Created TOD drawer with id 0x%.2X, parent node 0x%.8X",
               i_drawerId,
               i_parentNode->getAttr<TARGETING::ATTR_HUID>());
    TOD_EXIT("TodDrawer constructor");
}

//******************************************************************************
// TodDrawer::~TodDrawer
//******************************************************************************
TodDrawer::~TodDrawer()
{
    TOD_ENTER("TodDrawer destructor");

    for(TodProcContainer::iterator l_itr = iv_todProcList.begin();
        l_itr != iv_todProcList.end();
        ++l_itr)
    {
        delete (*l_itr);
    }
    iv_todProcList.clear();
    TOD_EXIT("TodDrawer destructor");
}

//******************************************************************************
// TodDrawer::getProcWithMaxCores
//******************************************************************************
void TodDrawer::getProcWithMaxCores(
                const TodProc* i_procToIgnore,
                TodProc*& o_pTodProc,
                uint32_t& o_coreCount) const
{
    TOD_ENTER("getProcWithMaxCores");
    o_pTodProc =  NULL;
    o_coreCount = 0;

    do{
        //List of functional cores
        TARGETING::TargetHandleList l_funcCoreTargetList;
        TARGETING::PredicateCTM
            l_coreCTM(TARGETING::CLASS_UNIT,TARGETING::TYPE_CORE);

        TARGETING::PredicateHwas l_funcPred;
        l_funcPred.functional(true);
        TARGETING::PredicatePostfixExpr l_funcCorePostfixExpr;
        l_funcCorePostfixExpr.push(&l_coreCTM).push(&l_funcPred).And();

        TodProc* l_pSelectedTarget = NULL;
        uint32_t l_maxCores = 0;

        for(TodProcContainer::const_iterator l_procIter =
            iv_todProcList.begin();
            l_procIter != iv_todProcList.end();
            ++l_procIter)
        {
            if((NULL != i_procToIgnore) &&
               (i_procToIgnore->getTarget()->getAttr<TARGETING::ATTR_HUID>() ==
               (*l_procIter)->getTarget()->getAttr<TARGETING::ATTR_HUID>()))
            {
                continue;
            }
            l_funcCoreTargetList.clear();
            //Find the funcational core targets on this proc
            TARGETING::targetService().getAssociated(l_funcCoreTargetList,
                    (*l_procIter)->getTarget(),
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &l_funcCorePostfixExpr);

            if ( l_funcCoreTargetList.size() > l_maxCores )
            {
                l_pSelectedTarget = *l_procIter;
                l_maxCores = l_funcCoreTargetList.size();
            }
        }
        if ( l_maxCores > 0 )
        {
            o_pTodProc = l_pSelectedTarget;
            o_coreCount = l_maxCores;
            TOD_INF("getProcWithMaxCores,On drawer %d, processor 0x%08X "
            "has maximum cores count = %d ",
            iv_todDrawerId,
            l_pSelectedTarget->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
            l_maxCores);
        }

    }while(0);

    TOD_EXIT("getProcWithMaxCores");
}


//******************************************************************************
// TodDrawer::findMasterProc
//******************************************************************************
errlHndl_t TodDrawer::findMasterProc(TodProc*& o_drawerMaster) const
{
    TOD_ENTER("findMasterProc");

    errlHndl_t l_errHdl = NULL;

    TodProc* l_pMasterProc = NULL;

    do{
        TodProcContainer::const_iterator l_procIter = iv_todProcList.begin();
        for (; l_procIter != iv_todProcList.end(); ++l_procIter)
        {
            if(((*l_procIter)->getMasterType() == TodProc::TOD_MASTER)
               ||
               ((*l_procIter)->getMasterType() == TodProc::DRAWER_MASTER))
               {
                   l_pMasterProc = (*l_procIter);
                   break;
               }
        }
        if(iv_todProcList.end() == l_procIter)
        {
            TOD_ERR("No master proc for drawer 0x%.2X",iv_todDrawerId);
            /*@
             * @errortype
             * @reasoncode   TOD_NO_MASTER_PROC
             * @moduleid     TOD_FIND_MASTER_PROC
             * @userdata1    TOD drawer id
             * @devdesc      No master proc set for this drawer
             */
             l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_LOG_INVALID_CONFIG,
                               TOD_INVALID_CONFIG,
                               iv_todDrawerId, 0);
        }
    }while(0);

    o_drawerMaster = l_pMasterProc;

    TOD_EXIT("findMasterProc, errHdl = %p", l_errHdl);

    return l_errHdl;
}

}//end of namespace
