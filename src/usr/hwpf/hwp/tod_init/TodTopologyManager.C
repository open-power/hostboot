/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodTopologyManager.C $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
 *  @file TodTopologyManager.C
 *
 *  @brief TOD Topology Manager class implementation. Responsible for
 *      creating/modifying the primary and secondary topologies.
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <tod_init/tod_init_reasoncodes.H>
#include "TodTopologyManager.H"
#include "TodControls.H"
#include "TodDrawer.H"
#include "TodProc.H"
#include "TodTrace.H"

using namespace TARGETING;

namespace TOD
{

//------------------------------------------------------------------------------
//Global defines
//------------------------------------------------------------------------------
//Strings used in topology/register dump to fsp-trace
static const char* TOD_PRIMARY_TOPOLOGY = "PRIMARY";
static const char* TOD_SECONDARY_TOPOLOGY = "SECONDARY";
static const char* NO_BUS  = "NONE";
static const char* X_BUS_0 = "XBUS0";
static const char* X_BUS_1 = "XBUS1";
static const char* X_BUS_2 = "XBUS2";
static const char* X_BUS_3 = "XBUS3";
static const char* A_BUS_0 = "ABUS0";
static const char* A_BUS_1 = "ABUS1";
static const char* A_BUS_2 = "ABUS2";

//******************************************************************************
//TodTopologyManager::TodTopologyManager
//******************************************************************************
TodTopologyManager::TodTopologyManager(
                        const proc_tod_setup_tod_sel i_topologyType) :
    iv_topologyType(i_topologyType)
{
    TOD_ENTER("Topology type 0X%.8X", i_topologyType);

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
    TOD_ENTER("create");

    errlHndl_t l_errHdl = NULL;

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
        l_errHdl = TodControls::getTheInstance().pickMdmt(iv_topologyType);
        if(l_errHdl)
        {
            TOD_ERR("Couldn't pick MDMT.");
            break;
        }

        //Get the TOD drawers
        TodDrawerContainer l_todDrwList;
        TodControls::getTheInstance().getDrawers(iv_topologyType,
                                                     l_todDrwList);
        //Find the TOD system master drawer (the one in which the MDMT lies)
        TodDrawer* l_pMasterDrawer = NULL;
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
        if(NULL == l_pMasterDrawer)
        {
            TOD_ERR("TOD master drawer not found");
            /*@
             * @errortype
             * @reasoncode   TOD_CREATION_ERR
             * @moduleid     TOD_TOPOLOGY_CREATE
             * @userdata1    Topology type : primary/secondary
             * @devdesc      TOD master drawer not found
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_TOPOLOGY_CREATE,
                               TOD_CREATION_ERR,
                               iv_topologyType );
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

    TOD_EXIT("create. errHdl = %p", l_errHdl);

    return l_errHdl;
}

//******************************************************************************
//TodTopologyManager::wireProcs
//******************************************************************************
errlHndl_t TodTopologyManager::wireProcs(const TodDrawer* i_pTodDrawer)
{
    TOD_ENTER("wireProcs");

    errlHndl_t l_errHdl = NULL;

    do
    {
        if(NULL == i_pTodDrawer)
        {
            TOD_ERR("TOD drawer not specified");
            /*@
             * @errortype
             * @reasoncode   TOD_CREATION_ERR_NO_DRAWER
             * @moduleid     TOD_WIRE_PROCS
             * @userdata1    Topology type : primary/secondary
             * @devdesc      TOD drawer not specified
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_WIRE_PROCS,
                               TOD_CREATION_ERR_NO_DRAWER,
                               iv_topologyType );
            break;
        }

        TOD_INF("TOD drawer id %d", i_pTodDrawer->getId());

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
        TodProc* l_pDrawerMaster = NULL;
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
        while((NULL == l_errHdl) && (l_sourcesList.end() != l_sourceItr))
        {
            for(l_targetItr = l_targetsList.begin();
                l_targetItr != l_targetsList.end();)
            {
                l_errHdl = (*l_sourceItr)->connect(*l_targetItr,
                                                   TARGETING::TYPE_XBUS,
                                                   l_connected);
                if(l_errHdl)
                {
                    TOD_ERR("Error tying to connect target 0x%.8X "
                    "to source 0x%.8X.",
                    (*l_targetItr)->getTarget()->getAttr<ATTR_HUID>(),
                    (*l_sourceItr)->getTarget()->getAttr<ATTR_HUID>());
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
            (*(l_targetsList.begin()))->getTarget()->getAttr<ATTR_HUID>());
            /*@
             * @errortype
             * @reasoncode   TOD_CREATION_ERR
             * @moduleid     TOD_WIRE_PROCS
             * @userdata1    DrawerId = bit[0:31], Topology type = bit[32:63]
             * @userdata2    HUID of first disconnected proc
             * @devdesc      TOD drawer has one or more disconnected procs
             */
            uint64_t l_data = i_pTodDrawer->getId();
            l_data <<= 32;
            l_data |= iv_topologyType;
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_WIRE_PROCS,
                               TOD_CREATION_ERR,
                               l_data,
                               (*(l_targetsList.begin()))->getTarget()->
                                 getAttr<ATTR_HUID>());
            break;
        }
    }while(0);

    TOD_EXIT("wireProcs. errHdl = %p", l_errHdl);

    return l_errHdl;
}

//******************************************************************************
//TodTopologyManager::wireTodDrawer
//******************************************************************************
errlHndl_t TodTopologyManager::wireTodDrawer(TodDrawer* i_pTodDrawer)
{
    TOD_ENTER("wireTodDrawer");

    errlHndl_t l_errHdl = NULL;

    do
    {
        if(NULL == i_pTodDrawer)
        {
            TOD_ERR("TOD drawer not specified");
            /*@
             * @errortype
             * @reasoncode   TOD_CREATION_ERR
             * @moduleid     TOD_WIRE_DRAWERS
             * @userdata1    Topology type : primary/secondary
             * @devdesc      TOD drawer not specified
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_WIRE_DRAWERS,
                               TOD_CREATION_ERR,
                               iv_topologyType);
            break;
        }

        TOD_INF("TOD drawer id %d", i_pTodDrawer->getId());

        //The algorithm to wire the slave TOD drawers to the mater TOD
        //drawer (to the MDMT to be specific) goes as follows :
        /*
        For each slave TOD drawer "d"
            For each proc "p" in d
                If MDMT connects p via A bus
                    we are done, exit
        */

        //Get the MDMT
        TodProc* l_pMDMT =
                    TodControls::getTheInstance().getMDMT(iv_topologyType);
        if(NULL == l_pMDMT)
        {
            TOD_ERR("MDMT not found for topology type 0X%.8X",
                     iv_topologyType);
            /*@
             * @errortype
             * @reasoncode   TOD_NO_MASTER_PROC
             * @moduleid     TOD_WIRE_DRAWERS
             * @userdata1    Topology type : primary/secondary
             * @devdesc      MDMT could not be found
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_WIRE_DRAWERS,
                               TOD_NO_MASTER_PROC,
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
                                        TARGETING::TYPE_ABUS,
                                        l_connected);
            if(l_errHdl)
            {
                TOD_ERR("Error tying to connect target 0x%.4X "
                         "to MDMT 0x%.8X.",
                         (*l_itr)->getTarget()->getAttr<ATTR_HUID>(),
                         l_pMDMT->getTarget()->getAttr<ATTR_HUID>());
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
             * @reasoncode   TOD_CANNOT_WIRE_DRAWER
             * @moduleid     TOD_WIRE_DRAWERS
             * @userdata1    Topology type : primary/secondary
             * @userdata2    TOD drawer id
             * @devdesc      TOD drawer couldn't be wired
             */
            l_errHdl = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_INFORMATIONAL,
                               TOD_WIRE_DRAWERS,
                               TOD_CANNOT_WIRE_DRAWER,
                               iv_topologyType,
                               i_pTodDrawer->getId());
            break;
        }
    }while(0);

    TOD_EXIT("wireTodDrawer. errHdl = %p", l_errHdl);

    return l_errHdl;
}

//******************************************************************************
//TodTopologyManager::dumpTopology
//******************************************************************************
void TodTopologyManager::dumpTopology() const
{
    TOD_ENTER("dumpTopology");

    static const char* busnames[8] = {0};
    busnames[NONE] = NO_BUS;
    busnames[XBUS0] = X_BUS_0;
    busnames[XBUS1] = X_BUS_1;
    busnames[XBUS2] = X_BUS_2;
    busnames[XBUS3] = X_BUS_3;
    busnames[ABUS0] = A_BUS_0;
    busnames[ABUS1] = A_BUS_1;
    busnames[ABUS2] = A_BUS_2;

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
        TodControls::getTheInstance().getDrawers(iv_topologyType, l_todDrwList);
        TodDrawerContainer::const_iterator l_drwItr = l_todDrwList.begin();
        while(l_todDrwList.end() != l_drwItr)
        {
            TOD_INF("TOPOLOGY DUMP> TOD Drawer(0x%.2X)",(*l_drwItr)->getId());
            //Get the procs on this drawer
            TodProcContainer l_procList = (*l_drwItr)->getProcs();

            TOD_INF("TOPOLOGY DUMP> "
                    "parent_huid---bus out---bus in---child_huid");
            TodProcContainer::const_iterator l_procItr = l_procList.begin();
            while(l_procList.end() != l_procItr)
            {
                //Get the children for this TOD proc
                TodProcContainer l_childList;
                (*l_procItr)->getChildren(l_childList);
                TodProcContainer::const_iterator l_childItr =
                                                            l_childList.begin();
                while(l_childList.end() != l_childItr)
                {
                    TOD_INF("TOPOLOGY DUMP> 0x%08X---%s---%s---0x%08X",
                             (*l_procItr)->getTarget()->getAttr<ATTR_HUID>(),
                             busnames[(*l_childItr)->getBusIn()],
                             busnames[(*l_childItr)->getBusOut()],
                             (*l_childItr)->getTarget()->getAttr<ATTR_HUID>());
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
    TOD_ENTER("dumpTodRegs");

    static const char* topologynames[2] = {0};
    topologynames[TOD_PRIMARY] = TOD_PRIMARY_TOPOLOGY;
    topologynames[TOD_SECONDARY] = TOD_SECONDARY_TOPOLOGY;

    do
    {
        TOD_INF("TOD REGDUMP> Start, topology type %s",
                 topologynames[iv_topologyType]);
        //Get the TOD drawers
        TodDrawerContainer l_todDrwList;
        TodControls::getTheInstance().getDrawers(iv_topologyType, l_todDrwList);
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
                    (*l_procItr)->getTarget()->getAttr<ATTR_HUID>());
                if(TodProc::TOD_MASTER == (*l_procItr)->getMasterType())
                {
                   TOD_INF("TOD REGDUMP> This proc is the MDMT");
                }
                else if(TodProc::DRAWER_MASTER == (*l_procItr)->getMasterType())
                {
                    TOD_INF("TOD REGDUMP> This proc is the SDMT "
                             " for this drawer");
                }
                proc_tod_setup_conf_regs l_todRegs;
                (*l_procItr)->getTodRegs(l_todRegs);
                TOD_INF("TOD REGDUMP> MASTER PATH CONTROL REG 0x%.16llX",
                         l_todRegs.tod_m_path_ctrl_reg.getDoubleWord(0));
                TOD_INF("TOD REGDUMP> PORT 0 PRIMARY CONFIG REG 0x%.16llX",
                         l_todRegs.tod_pri_port_0_ctrl_reg.getDoubleWord(0));
                TOD_INF("TOD REGDUMP> PORT 1 PRIMARY CONFIG REG 0x%.16llX",
                         l_todRegs.tod_pri_port_1_ctrl_reg.getDoubleWord(0));
                TOD_INF("TOD REGDUMP> PORT 0 SECONDARY CONFIG REG 0x%.16llX",
                         l_todRegs.tod_sec_port_0_ctrl_reg.getDoubleWord(0));
                TOD_INF("TOD REGDUMP> PORT 1 SECONDARY CONFIG REG 0x%.16llX",
                         l_todRegs.tod_sec_port_1_ctrl_reg.getDoubleWord(0));
                TOD_INF("TOD REGDUMP> SLAVE PATH CONTROL REG 0x%.16llX",
                         l_todRegs.tod_s_path_ctrl_reg.getDoubleWord(0));
                TOD_INF("TOD REGDUMP> INTERNAL PATH CONTROL REG 0x%.16llX",
                         l_todRegs.tod_i_path_ctrl_reg.getDoubleWord(0));
                TOD_INF("TOD REGDUMP> PRIMARY/SECONDARY MASTER/SLAVE CONTROL"
                         " REG 0x%.16llX",
                         l_todRegs.tod_pss_mss_ctrl_reg.getDoubleWord(0));
                TOD_INF("TOD REGDUMP> CHIP CONTROL REG 0x%.16llX",
                         l_todRegs.tod_chip_ctrl_reg.getDoubleWord(0));
                ++l_procItr;
            }
            ++l_drwItr;
        }
        TOD_INF("TOD REGDUMP> End");
    }while(0);

    TOD_EXIT("dumpTodRegs");
}

} //namespace TOD
