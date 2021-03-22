/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodTopologyManager.C $                     */
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
 *  @file TodTopologyManager.C
 *
 *  @brief TOD Topology Manager class implementation. Responsible for
 *      creating/modifying the primary and secondary topologies.
 */


//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
//#include <buffer.H>

//TARGETING
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include "TodUtils.H"
#include "TodTopologyManager.H"
#include "TodControls.H"
#include "TodDrawer.H"
#include "TodProc.H"
#include "TodTrace.H"
#include <p10_tod_utils.H>
#include <isteps/tod_init_reasoncodes.H>

extern "C" {

using namespace fapi2;

namespace TOD
{

//------------------------------------------------------------------------------
//Global defines
//------------------------------------------------------------------------------
//Strings used in topology/register dump to fsp-trace
static const char* TOD_PRIMARY_TOPOLOGY = "PRIMARY";
static const char* TOD_SECONDARY_TOPOLOGY = "SECONDARY";
static const char* NO_BUS  = "NONE";
static const char* IOHS_0 = "IOHS0";
static const char* IOHS_1 = "IOHS1";
static const char* IOHS_2 = "IOHS2";
static const char* IOHS_3 = "IOHS3";
static const char* IOHS_4 = "IOHS4";
static const char* IOHS_5 = "IOHS5";
static const char* IOHS_6 = "IOHS6";
static const char* IOHS_7 = "IOHS7";
//******************************************************************************
//TodTopologyManager::TodTopologyManager
//******************************************************************************
TodTopologyManager::TodTopologyManager(
                        const p10_tod_setup_tod_sel i_topologyType) :
    iv_topologyType(i_topologyType)
{
    TOD_ENTER("TodTopologyManager constructor: "
              "Topology type 0X%.8X", i_topologyType);

    TOD_EXIT("TodTopologyManager constructor");
}
//******************************************************************************
//TodTopologyManager::~TodTopologyManager
//******************************************************************************
TodTopologyManager::~TodTopologyManager()
{
    TOD_ENTER("TodTopologyManager destructor");

    TOD_EXIT("TodTopologyManager destructor");
}

//******************************************************************************
//TodTopologyManager::create
//******************************************************************************
errlHndl_t TodTopologyManager::create()
{
    TOD_ENTER("TodTopologyManager::create");

    errlHndl_t l_errHdl = nullptr;

    //The topology creation algorithm goes as follows :
    //1)Pick the MDMT.
    //2)In the master TOD drawer (the one in which MDMT lies),
    //wire the procs together.
    //3)Connect the MDMT to one processor in each of the slave TOD drawers
    //(the TOD drawers other than the master TOD drawer)
    //4)Wire the procs in the slave TOD drawers.
    do
    {
        //1) Pick the MDMT.
        l_errHdl = TOD::pickMdmt(iv_topologyType);
        if(l_errHdl)
        {
            TOD_ERR("Couldn't pick MDMT.");
            break;
        }

        //Get the TOD drawers
        TodDrawerContainer l_todDrwList;
        TOD::getDrawers(iv_topologyType, l_todDrwList);
        //Find the TOD system master drawer (the one in which the MDMT lies)
        TodDrawer* l_pMasterDrawer = nullptr;
        for(TodDrawerContainer::const_iterator l_itr = l_todDrwList.begin();
            l_itr != l_todDrwList.end();
            ++l_itr)
        {
            if((*l_itr)->isMaster())
            {
                l_pMasterDrawer = *l_itr;
                TOD_INF("TOD drawer(0x%.2X) is the master drawer",
                l_pMasterDrawer->getId());
                break;
            }
        }
        if(nullptr == l_pMasterDrawer)
        {
            TOD_ERR("TOD master drawer not found");
            /*@
             * @errortype
             * @moduleid     TOD_TOPOLOGY_CREATE
             * @reasoncode   TOD_CREATION_ERR
             * @userdata1    Topology type : primary/secondary
             * @devdesc      TOD master drawer not found
             * @custdesc     Host failed to boot because there was a problem
             *               configuring Time Of Day on the Host processors
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_INFORMATIONAL,
                         TOD_TOPOLOGY_CREATE,
                         TOD_CREATION_ERR,
                         iv_topologyType);
            break;
        }

        //2)In the master TOD drawer, wire the procs together.
        l_errHdl = wireProcs(l_pMasterDrawer);
        if(l_errHdl)
        {
            TOD_ERR("Couldn't wire one or more processors for "
                     "the master TOD drawer(0x%.2X)",
                     l_pMasterDrawer->getId());

            break;
        }

        //3)Connect the MDMT to one processor in each of the TOD drawers
        //other than the master TOD drawer.
        for(TodDrawerContainer::iterator l_itr = l_todDrwList.begin();
            l_itr != l_todDrwList.end();
            ++l_itr)
        {
            if((*l_itr)->isMaster())
            {
                //This is the master TOD drawer, we are connecting other
                //TOD drawers to this.
                continue;
            }
            l_errHdl = wireTodDrawer(*l_itr);
            if(l_errHdl)
            {
                TOD_ERR("Couldn't wire TOD drawer(0x%.2X) to MDMT.",
                         (*l_itr)->getId());
                break;
            }
        }
        if(l_errHdl)
        {
            break;
        }

        //4)Wire the procs in the other TOD drawers (i.e other than the master)
        for(TodDrawerContainer::const_iterator l_itr =
            l_todDrwList.begin();
            l_itr != l_todDrwList.end();
            ++l_itr)
        {
            if((*l_itr)->isMaster())
            {
                //We've done this already for the master TOD drawer
                continue;
            }
            l_errHdl = wireProcs(*l_itr);
            if(l_errHdl)
            {
                TOD_ERR("Couldn't wire one or more processors for "
                         "TOD drawer(0x%.2X).",
                         (*l_itr)->getId());
                break;
            }
        }
        if(l_errHdl)
        {
            break;
        }
    }while(0);

    TOD_EXIT("TodTopologyManager::create");

    return l_errHdl;
}

//******************************************************************************
//TodTopologyManager::wireProcs
//******************************************************************************
errlHndl_t TodTopologyManager::wireProcs(const TodDrawer* i_pTodDrawer)
{
    TOD_ENTER("TodTopologyManager::wireProcs");

    errlHndl_t l_errHdl = nullptr;

    do
    {
        if(nullptr == i_pTodDrawer)
        {
            TOD_ERR("TOD drawer not specified");
            /*@
             * @errortype
             * @moduleid     TOD_WIRE_PROCS
             * @reasoncode   TOD_INVALID_PARAM
             * @userdata1    Topology type : primary/secondary
             * @devdesc      TOD drawer not specified
             * @custdesc     Service Processor Firmware encountered an internal
             *               error
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_INFORMATIONAL,
                         TOD_WIRE_PROCS,
                         TOD_INVALID_PARAM,
                         iv_topologyType);
            break;
        }

        TOD_INF("TOD drawer id 0x%.2X", i_pTodDrawer->getId());

        //The algorithm to wire procs in a TOD drawer goes as follows :
        /*
        Have a "sources" list which initially has only the drawer master
        Have a "targets" list which has all the other procs.
        While the sources list isn't empty, for each source "s" in sources
            For each target "t" in targets
                If s connects t via X bus
                    Remove t from targets and add it to sources,
                    since it's now a potential source
        If targets isn't empty, we couldn't wire one or more procs
        */

        //Get the targets
        TodProcContainer l_targetsList = i_pTodDrawer->getProcs();

        //Check if we have procs to wire in the first place
        if(l_targetsList.empty())
        {
            TOD_INF("Nothing to wire on TOD drawer(0x%.2X)",
                     i_pTodDrawer->getId());
            break;
        }

        //Push the drawer master onto the sources list
        TodProc* l_pDrawerMaster = nullptr;
        l_errHdl = i_pTodDrawer->findMasterProc(l_pDrawerMaster);
        if(l_errHdl)
        {
            TOD_ERR("Master TOD proc not set for TOD drawer(0x%.2X)",
                     i_pTodDrawer->getId());
            break;
        }
        TodProcContainer l_sourcesList;
        l_sourcesList.push_back(l_pDrawerMaster);

        //Start connecting targets to sources
        TodProcContainer::iterator l_sourceItr = l_sourcesList.begin();
        TodProcContainer::iterator l_targetItr;
        bool l_connected = false;
        while((nullptr == l_errHdl) && (l_sourcesList.end() != l_sourceItr))
        {
            for(l_targetItr = l_targetsList.begin();
                l_targetItr != l_targetsList.end();)
            {
                l_errHdl = (*l_sourceItr)->connect(*l_targetItr,
                                                   TARGETING::TYPE_SMPGROUP,
                                                   l_connected);
                if(l_errHdl)
                {
                    TOD_ERR("Error tying to connect target 0x%.8X "
                    "to source 0x%.8X.",
                    (*l_targetItr)->getTarget()->
                    getAttr<TARGETING::ATTR_HUID>(),
                    (*l_sourceItr)->getTarget()->
                    getAttr<TARGETING::ATTR_HUID>());
                    break;
                }
                if(l_connected)
                {
                    //Prefer push_back to push_front since in case of multiple
                    //X bus path alternatives, the paths and hence the TOD
                    //delays will be shorter.
                    l_sourcesList.push_back(*l_targetItr);
                    (*l_sourceItr)->addChild(*l_targetItr);
                    l_targetItr = l_targetsList.erase(l_targetItr);
                }
                else
                {
                    ++l_targetItr;
                }
            }
            if(l_targetsList.empty())
            {
                break;
            }
            ++l_sourceItr;
        }
        if(l_errHdl)
        {
            break;
        }
        if(false == l_targetsList.empty())
        {

            //We couldn't connect one or more procs in this drawer
            TOD_ERR("TOD drawer(0x%.2X) has one or more procs not connected. "
            "0x%.8X is the first such proc.",
            i_pTodDrawer->getId(),
            (*(l_targetsList.begin()))->getTarget()->
            getAttr<TARGETING::ATTR_HUID>());

            /*@
             * @errortype
             * @moduleid     TOD_WIRE_PROCS
             * @reasoncode   TOD_CREATION_ERR
             * @userdata1[0:31]  Topology type : primary/secondary
             * @userdata1[32:63] TOD drawer id
             * @userdata2    HUID of first disconnected proc
             * @devdesc      TOD drawer has one or more disconnected procs
             * @custdesc     Host failed to boot because there was a problem
             *               configuring Time Of Day on the Host processors
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_INFORMATIONAL,
                         TOD_WIRE_PROCS,
                         TOD_CREATION_ERR,
                         TWO_UINT32_TO_UINT64(
                             iv_topologyType,
                             i_pTodDrawer->getId()),
                         (*(l_targetsList.begin()))->getTarget()->
                         getAttr<TARGETING::ATTR_HUID>());
            break;
        }
    }while(0);

    TOD_EXIT("TodTopologyManager::wireProcs");

    return l_errHdl;
}

//******************************************************************************
//TodTopologyManager::wireTodDrawer
//******************************************************************************
errlHndl_t TodTopologyManager::wireTodDrawer(TodDrawer* i_pTodDrawer)
{
    TOD_ENTER("wireTodDawer");

    errlHndl_t l_errHdl = nullptr;

    do
    {
        if(nullptr == i_pTodDrawer)
        {
            TOD_ERR("TOD drawer not specified");
            /*@
             * @errortype
             * @moduleid     TOD_WIRE_DRAWERS
             * @reasoncode   TOD_INVALID_PARAM
             * @userdata1    Topology type : primary/secondary
             * @devdesc      TOD drawer not specified
             * @custdesc     Service Processor Firmware encountered an internal
             *               error
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_INFORMATIONAL,
                         TOD_WIRE_DRAWERS,
                         TOD_INVALID_PARAM,
                         iv_topologyType);
            break;
        }

        TOD_INF("TOD drawer id 0x%.2X", i_pTodDrawer->getId());

        //The algorithm to wire the slave TOD drawers to the mater TOD
        //drawer (to the MDMT to be specific) goes as follows :
        /*
        For each slave TOD drawer "d"
            For each proc "p" in d
                If MDMT connects p via A bus
                    we are done, exit
        */

        //Get the MDMT
        TodProc* l_pMDMT = TOD::getMDMT(iv_topologyType);
        if(nullptr == l_pMDMT)
        {
            TOD_ERR("MDMT not found for topology type 0X%.8X",
                     iv_topologyType);
            /*@
             * @errortype
             * @moduleid     TOD_WIRE_DRAWERS
             * @reasoncode   TOD_MASTER_TARGET_NOT_FOUND
             * @userdata1    Topology type : primary/secondary
             * @devdesc      MDMT could not be found
             * @custdesc     Service Processor Firmware couldn't detect any
             *               functional master processor required to boot the
             *               host
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_INFORMATIONAL,
                         TOD_WIRE_DRAWERS,
                         TOD_MASTER_TARGET_NOT_FOUND,
                         iv_topologyType);
            break;
        }

        //Get the procs in this TOD drawer
        TodProcContainer l_procs = i_pTodDrawer->getProcs();

        //Check if we have procs
        if(l_procs.empty())
        {
            TOD_INF("Nothing to wire on TOD drawer(0x%.2X)",
                     i_pTodDrawer->getId());
            break;
        }

        //Find a proc which connects to the MDMT via A bus
        bool l_connected = false;
        TodProcContainer::iterator l_itr;
        for(l_itr = l_procs.begin();
            l_itr != l_procs.end();
            ++l_itr)
        {
            l_errHdl = l_pMDMT->connect(*l_itr,
                                        TARGETING::TYPE_SMPGROUP,
                                        l_connected);
            if(l_errHdl)
            {
                TOD_ERR("Error tying to connect target 0x%.4X "
                         "to MDMT 0x%.8X.",
                         (*l_itr)->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
                         l_pMDMT->getTarget()->getAttr<TARGETING::ATTR_HUID>());
                break;
            }
            if(l_connected)
            {
                //Found a proc, designate this as the SDMT for this TOD drawer.
                l_pMDMT->addChild(*l_itr);
                (*l_itr)->setMasterType(TodProc::DRAWER_MASTER);
                break;
            }
        }
        if(l_errHdl)
        {
            break;
        }
        if(l_procs.end() == l_itr)
        {
            TOD_ERR("TOD drawer(0x%.2X) couldn't be wired",
                     i_pTodDrawer->getId());
            /*@
             * @errortype
             * @moduleid     TOD_WIRE_DRAWERS
             * @reasoncode   TOD_CREATION_ERR
             * @userdata1    Topology type : primary/secondary
             * @userdata2    TOD drawer id
             * @devdesc      TOD drawer couldn't be wired
             * @custdesc     Host failed to boot because there was a problem
             *               configuring Time Of Day on the Host processors
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_INFORMATIONAL,
                         TOD_WIRE_DRAWERS,
                         TOD_CREATION_ERR,
                         iv_topologyType,
                         i_pTodDrawer->getId());
            break;
        }
    }while(0);

    TOD_EXIT("wireTodDawer");

    return l_errHdl;
}

//******************************************************************************
//TodTopologyManager::dumpTopology
//******************************************************************************
void TodTopologyManager::dumpTopology() const
{
    TOD_ENTER("dumpTopology");

    static const char* busnames[TOD_SETUP_BUS_BUS_MAX+1] = {0};
    busnames[TOD_SETUP_BUS_NONE] = NO_BUS;
    busnames[TOD_SETUP_BUS_IOHS0] = IOHS_0;
    busnames[TOD_SETUP_BUS_IOHS1] = IOHS_1;
    busnames[TOD_SETUP_BUS_IOHS2] = IOHS_2;
    busnames[TOD_SETUP_BUS_IOHS3] = IOHS_3;
    busnames[TOD_SETUP_BUS_IOHS4] = IOHS_4;
    busnames[TOD_SETUP_BUS_IOHS5] = IOHS_5;
    busnames[TOD_SETUP_BUS_IOHS6] = IOHS_6;
    busnames[TOD_SETUP_BUS_IOHS7] = IOHS_7;

    static const char* topologynames[2] = {0};
    topologynames[TOD_PRIMARY] = TOD_PRIMARY_TOPOLOGY;
    topologynames[TOD_SECONDARY] = TOD_SECONDARY_TOPOLOGY;

    do
    {
        //Dump the inter and intra TOD drawer connections
        TOD_INF("TOPOLOGY DUMP> Start, topology type %s",
                 topologynames[iv_topologyType]);
        //Get the TOD drawers
        TodDrawerContainer l_todDrwList;
        TOD::getDrawers(iv_topologyType, l_todDrwList);
        TodDrawerContainer::const_iterator l_drwItr = l_todDrwList.begin();
        while(l_todDrwList.end() != l_drwItr)
        {
            TOD_INF("TOPOLOGY DUMP> TOD Drawer(0x%.2X)",(*l_drwItr)->getId());
            //Get the procs on this drawer
            TodProcContainer l_procList = (*l_drwItr)->getProcs();

            TOD_INF("TOPOLOGY DUMP> parent---bus out---bus in---child");
            TodProcContainer::const_iterator l_procItr = l_procList.begin();

            while(l_procList.end() != l_procItr)
            {
                if(TodProc::TOD_MASTER == (*l_procItr)->getMasterType())
                {
                    TOD_INF("Proc 0x%.8X is the MDMT",
                    (*l_procItr)->getTarget()->getAttr<TARGETING::ATTR_HUID>());
                }

                //Get the children for this TOD proc
                TodProcContainer l_childList;
                (*l_procItr)->getChildren(l_childList);
                TodProcContainer::const_iterator l_childItr =
                    l_childList.begin();
                while(l_childList.end() != l_childItr)
                {
                    TOD_INF("TOPOLOGY DUMP> 0x%08X---%s---%s---0x%08X",
                   (*l_procItr)->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
                   busnames[(*l_childItr)->getBusIn()],
                   busnames[(*l_childItr)->getBusOut()],
                   (*l_childItr)->getTarget()->getAttr<TARGETING::ATTR_HUID>());
                   ++l_childItr;
                }
                ++l_procItr;
            }
            ++l_drwItr;
        }
        TOD_INF("TOPOLOGY DUMP> End");
    }while(0);

    TOD_EXIT("dumpTopology");
}

//******************************************************************************
//TodTopologyManager::dumpTodRegs
//******************************************************************************
void TodTopologyManager::dumpTodRegs() const
{
    TOD_ENTER("TodTopologyManager::dumpTodRegs");

    static const char* topologynames[2] = {0};
    topologynames[TOD_PRIMARY] = TOD_PRIMARY_TOPOLOGY;
    topologynames[TOD_SECONDARY] = TOD_SECONDARY_TOPOLOGY;

    do
    {
        TOD_INF("TOD REGDUMP> Start, topology type %s",
                 topologynames[iv_topologyType]);

        fapi2::variable_buffer l_regData(64);
        //Get the TOD drawers
        TodDrawerContainer l_todDrwList;
        TOD::getDrawers(iv_topologyType, l_todDrwList);
        TodDrawerContainer::const_iterator l_drwItr = l_todDrwList.begin();
        while(l_todDrwList.end() != l_drwItr)
        {
            TOD_INF("TOD REGDUMP> TOD Drawer(0x%.2X)",(*l_drwItr)->getId());
            //Get the procs on this drawer
            TodProcContainer l_procList = (*l_drwItr)->getProcs();
            TodProcContainer::const_iterator l_procItr = l_procList.begin();
            while(l_procList.end() != l_procItr)
            {
                TOD_INF("TOD REGDUMP> Proc HUID 0x%.8X",
                    (*l_procItr)->getTarget()->getAttr<TARGETING::ATTR_HUID>());
                if(TodProc::TOD_MASTER == (*l_procItr)->getMasterType())
                {
                    TOD_INF("TOD REGDUMP> This proc is the MDMT");
                }
                else if(TodProc::DRAWER_MASTER ==
                       (*l_procItr)->getMasterType())
                {
                    TOD_INF("TOD REGDUMP> This proc is the SDMT "
                             " for this drawer");
                }
                p10_tod_setup_conf_regs l_todRegs;
                (*l_procItr)->getTodRegs(l_todRegs);
                l_regData.set(l_todRegs.tod_m_path_ctrl_reg(), 0);
                TOD_INF("TOD REGDUMP> MASTER PATH CONTROL REG 0x%.16llX",
                        l_regData.get<uint32_t>(0));
                l_regData.set(l_todRegs.tod_pri_port_0_ctrl_reg(), 0);
                TOD_INF("TOD REGDUMP> PORT 0 PRIMARY CONFIG REG 0x%.16llX",
                        l_regData.get<uint32_t>(0));
                l_regData.set(l_todRegs.tod_pri_port_1_ctrl_reg(), 0);
                TOD_INF("TOD REGDUMP> PORT 1 PRIMARY CONFIG REG 0x%.16llX",
                        l_regData.get<uint32_t>(0));
                l_regData.set(l_todRegs.tod_sec_port_0_ctrl_reg(), 0);
                TOD_INF("TOD REGDUMP> PORT 0 SECONDARY CONFIG REG 0x%.16llX",
                        l_regData.get<uint32_t>(0));
                l_regData.set(l_todRegs.tod_sec_port_1_ctrl_reg(), 0);
                TOD_INF("TOD REGDUMP> PORT 1 SECONDARY CONFIG REG 0x%.16llX",
                        l_regData.get<uint32_t>(0));
                 l_regData.set(l_todRegs.tod_s_path_ctrl_reg(), 0);
                TOD_INF("TOD REGDUMP> SLAVE PATH CONTROL REG 0x%.16llX",
                        l_regData.get<uint32_t>(0));
                l_regData.set(l_todRegs.tod_i_path_ctrl_reg(), 0);
                TOD_INF("TOD REGDUMP> INTERNAL PATH CONTROL REG 0x%.16llX",
                        l_regData.get<uint32_t>(0));
                l_regData.set(l_todRegs.tod_pss_mss_ctrl_reg(), 0);
                TOD_INF("TOD REGDUMP> PRIMARY/SECONDARY MASTER/SLAVE CONTROL"
                         " REG 0x%.16llX",
                        l_regData.get<uint32_t>(0));
                l_regData.set(l_todRegs.tod_chip_ctrl_reg(), 0);
                TOD_INF("TOD REGDUMP> CHIP CONTROL REG 0x%.16llX",
                        l_regData.get<uint32_t>(0));
                ++l_procItr;
            }
            ++l_drwItr;
        }
        TOD_INF("TOD REGDUMP> End");
    }while(0);

    TOD_EXIT("TodTopologyManager::dumpTodRegs");
}

//******************************************************************************
//TodTopologyManager::wireProcsInSmpWrapMode
//******************************************************************************
errlHndl_t TodTopologyManager::wireProcsInSmpWrapMode(
                                       TodProcContainer& io_sourcesList,
                                       TodProcContainer& io_targetsList)
{
    TOD_ENTER("TodTopologyManager::wireProcsInSmpWrapMode");

    errlHndl_t l_errHdl = nullptr;

    do
    {
        TodProcContainer::iterator l_sourceItr = io_sourcesList.begin();
        TodProcContainer::iterator l_targetItr;
        bool l_connected = false;
        while((nullptr == l_errHdl) && (io_sourcesList.end() != l_sourceItr))
        {
            for(l_targetItr = io_targetsList.begin();
                l_targetItr != io_targetsList.end();)
            {
                l_errHdl = (*l_sourceItr)->connect(*l_targetItr,
                                                   TARGETING::TYPE_SMPGROUP,
                                                   l_connected);
                if(l_errHdl)
                {
                    TOD_ERR("Error tying to connect target 0x%.8X "
                    "to source 0x%.8X.",
                    (*l_targetItr)->getTarget()->
                    getAttr<TARGETING::ATTR_HUID>(),
                    (*l_sourceItr)->getTarget()->
                    getAttr<TARGETING::ATTR_HUID>());
                    break;
                }
                if(l_connected)
                {
                    io_sourcesList.push_back(*l_targetItr);
                    (*l_sourceItr)->addChild(*l_targetItr);
                    l_targetItr = io_targetsList.erase(l_targetItr);
                }
                else
                {
                    ++l_targetItr;
                }
            }
            ++l_sourceItr;
        }
    }while(0);

    TOD_EXIT("TodTopologyManager::wireProcsInSmpWrapMode");

    return l_errHdl;
}

} //namespace TOD

}
