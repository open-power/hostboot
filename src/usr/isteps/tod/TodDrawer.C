/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodDrawer.C $                              */
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
/**
 *  @file TodDrawer.C
 *
 *  @brief The file implements methods of TodDrawer class
 */

//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
//Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <attributeenums.H>

#include "TodControls.H"
#include "TodProc.H"
#include "TodDrawer.H"
#include "TodUtils.H"
#include <hwas/common/deconfigGard.H>
//Standard library
#include <list>
#include "TodUtils.H"
#include <isteps/tod_init_reasoncodes.H>

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
    do
    {
      if (!iv_parentNodeTarget)
      {
          TOD_ERR_ASSERT(0, "Error creating TOD drawer with id 0x%.2X,"
          "parent node pointer passed as nullptr",
          i_drawerId);
          break;
      }
      TOD_ENTER("TodDrawer constructor: "
                "Created TOD drawer with id 0x%.2X, parent node 0x%.8X",
                 i_drawerId,
                 i_parentNode->getAttr<TARGETING::ATTR_HUID>());
    } while (0);
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
                uint32_t& o_coreCount,
                TodProcContainer* i_pProcList) const
{
    TOD_ENTER("getProcWithMaxCores");
    o_pTodProc =  nullptr;
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

        TodProc* l_pSelectedTarget = nullptr;
        uint32_t l_maxCores = 0;

        const TodProcContainer &l_procList =
            i_pProcList ? *i_pProcList : iv_todProcList;
        for(TodProcContainer::const_iterator l_procIter =
            l_procList.begin();
            l_procIter != l_procList.end();
            ++l_procIter)
        {
            if((nullptr != i_procToIgnore) &&
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
            TOD_INF("getProcWithMaxCores,On drawer 0x%2X, processor 0x%08X "
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
    TOD_ENTER("TodDrawer::findMasterProc");

    errlHndl_t l_errHdl = nullptr;

    TodProc* l_pMasterProc = nullptr;

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
             * @moduleid     TOD_FIND_MASTER_PROC
             * @reasoncode   TOD_NO_MASTER_PROC
             * @userdata1    TOD drawer id
             * @devdesc      No master proc set for this drawer
             * @custdesc     Service Processor Firmware couldn't detect any
             *               functional master processor required to boot the
             *               host
             */

            const bool hbSwError = true;
            l_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           TOD_FIND_MASTER_PROC,
                           TOD_NO_MASTER_PROC,
                           iv_todDrawerId,
                           hbSwError);
        }
    }while(0);

    o_drawerMaster = l_pMasterProc;

    TOD_EXIT("TodDrawer::findMasterProc");

    return l_errHdl;
}

//******************************************************************************
// TodDrawer::addProc
//******************************************************************************
void TodDrawer::addProc(TodProc* i_proc)
{
    if(i_proc)
    {
        iv_todProcList.push_back(i_proc);
    }
    else
    {
        TOD_ERR_ASSERT(false,"Code bug! Null Proc Target passed!");
    }
}

//******************************************************************************
// TodDrawer::getPotentialMdmts
//******************************************************************************
void TodDrawer::getPotentialMdmts(
        TodProcContainer& o_procList) const
{
    TOD_ENTER("TodDrawer::getPotentialMdmts");
    bool l_isGARDed = false;
    errlHndl_t l_errHdl = nullptr;

    const TARGETING::Target* l_procTarget = nullptr;
    // Procs that are GARDed, but configured.
    TodProcContainer l_usableGardedProcs;

    for(const auto & l_procItr : iv_todProcList)
    {

        l_procTarget = l_procItr->getTarget();

        //Check if the target is not black listed
        if ( !(TOD::isProcBlackListed(l_procTarget)) )
        {
            //Check if the target is not garded
            l_errHdl = TOD::checkGardStatusOfTarget(l_procTarget,
                        l_isGARDed);

            if(l_errHdl)
            {
                TOD_ERR("Failed in checkGardStatusOfTarget() to get the "
                        " GARD state for the target 0x%.8x",
                        GETHUID(l_procTarget));

                errlCommit(l_errHdl, TOD_COMP_ID);

                //Ignore this target as the gard status for this target
                //could not be obtained.
                continue;
            }

            TARGETING::ATTR_HWAS_STATE_type l_state =
                l_procTarget->getAttr<TARGETING::ATTR_HWAS_STATE>();

            if ( (!l_isGARDed) ||
                 (l_state.deconfiguredByEid ==
                  HWAS::DeconfigGard::CONFIGURED_BY_RESOURCE_RECOVERY) )
            {
                o_procList.push_back(l_procItr);
            }
            else
            {
                TOD_INF("PROC target 0x%.8x is not a preferred MDMT candidate"
                        " as it's garded",GETHUID(l_procTarget));
                l_usableGardedProcs.push_back(l_procItr);
            }
        }
        else
        {
            TOD_INF("PROC target 0x%.8x cannot be choosen as MDMT as it"
            "is backlisted",GETHUID(l_procTarget));
        }
        l_isGARDed = false;

    }//End of for loop

    if (o_procList.empty() && !l_usableGardedProcs.empty())
    {
        // No MDMT candidates found. Instead of failing the istep, if we
        // have GARDed (but functional) procs, consider them as candidates.
        // This is because these procs may still be usable for the current IPL,
        // and we don't want to fail the IPL here.
        o_procList = std::move(l_usableGardedProcs);
    }

    TOD_EXIT("TodDrawer::getPotentialMdmts");
}

}//end of namespace
