/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/TodProc.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
 *  @file TodProc.C
 *
 *  @brief The file implements methods of TodProc class
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <tod_init/tod_init_reasoncodes.H>
#include "TodDrawer.H"
#include "TodProc.H"
#include "TodTypes.H"
#include "TodAssert.H"
#include "TodTrace.H"

namespace TOD
{

//******************************************************************************
// TodProc::TodProc
//******************************************************************************
TodProc::TodProc(
           const TARGETING::Target* i_procTarget,
           const TodDrawer* i_parentDrawer):
           iv_procTarget(i_procTarget),
           iv_parentDrawer(i_parentDrawer),
           iv_tod_node_data(NULL),
           iv_masterType(NOT_MASTER)
{
    TOD_ASSERT(iv_procTarget, "Target input i_procTarget is NULL ");
    TOD_ASSERT(iv_parentDrawer, "TOD drawer input iv_parentDrawer is NULL ");

    TOD_ENTER("Created proc 0x%.8X on drawer 0x%.2X",
               iv_procTarget->getAttr<TARGETING::ATTR_HUID>(),
               iv_parentDrawer->getId());
    init();

    TOD_EXIT("TodProc constructor");
}

//******************************************************************************
// TodProc::~TodProc
//******************************************************************************
TodProc::~TodProc()
{
    TOD_ENTER("TodProc destructor");

    if(iv_tod_node_data)
    {
        delete iv_tod_node_data->i_target;
        iv_tod_node_data->i_target = NULL;
        delete iv_tod_node_data;
        iv_tod_node_data = NULL;
    }
    iv_xbusTargetList.clear();
    iv_abusTargetList.clear();

    TOD_EXIT("TodProc destructor");
}


//******************************************************************************
// TodProc::getMasterType
//******************************************************************************
TodProc::ProcMasterType TodProc::getMasterType() const
{
    return iv_masterType;
}

//******************************************************************************
// TodProc::setMasterType
//******************************************************************************
void TodProc::setMasterType(const ProcMasterType i_masterType)
{
    TOD_ENTER("setMasterType");

    iv_masterType = i_masterType;
    iv_tod_node_data->i_drawer_master = true;
    if(TOD_MASTER == i_masterType)
    {
        iv_tod_node_data->i_tod_master = true;
    }

    TOD_EXIT("setMasterType");
}

//******************************************************************************
// TodProc::init
//******************************************************************************
void TodProc::init()
{
    TOD_ENTER("init");

    if(iv_tod_node_data)
    {
        if(iv_tod_node_data->i_target)
        {
            delete iv_tod_node_data->i_target;
        }
        delete iv_tod_node_data;
    }
    iv_tod_node_data = new tod_topology_node();
    //Initialize the iv_tod_node_data structure
    iv_tod_node_data->i_target = new fapi::Target;
    iv_tod_node_data->i_target->setType(fapi::TARGET_TYPE_PROC_CHIP);
    iv_tod_node_data->i_target->set
       (reinterpret_cast<void*>(const_cast<TARGETING::Target*>(iv_procTarget)));
    iv_tod_node_data->i_tod_master = false;
    iv_tod_node_data->i_drawer_master = false;
    iv_tod_node_data->i_bus_rx = NONE;
    iv_tod_node_data->i_bus_tx = NONE;

    TodTopologyNodeContainer::iterator l_childItr;

    for(l_childItr = iv_tod_node_data->i_children.begin();
        l_childItr != iv_tod_node_data->i_children.end();
        ++l_childItr)
    {
        delete (*l_childItr);
    }
    iv_tod_node_data->i_children.clear();

    iv_xbusTargetList.clear();
    iv_abusTargetList.clear();

    //Make a list of outgoing bus targets for this processor
    TARGETING::PredicateCTM
        l_xbusCTM(TARGETING::CLASS_UNIT,TARGETING::TYPE_XBUS);
    TARGETING::PredicateCTM
        l_abusCTM(TARGETING::CLASS_UNIT,TARGETING::TYPE_ABUS);

    TARGETING::TargetHandleList l_xbusTargetList;
    TARGETING::TargetHandleList l_abusTargetList;

    TARGETING::PredicateIsFunctional l_func;
    TARGETING::PredicatePostfixExpr l_funcAndXbusFilter;
    TARGETING::PredicatePostfixExpr l_funcAndAbusFilter;
    l_funcAndXbusFilter.push(&l_xbusCTM).push(&l_func).And();
    l_funcAndAbusFilter.push(&l_abusCTM).push(&l_func).And();

    TARGETING::targetService().getAssociated(l_xbusTargetList,
            iv_procTarget,
            TARGETING::TargetService::CHILD,
            TARGETING::TargetService::ALL,
            &l_funcAndXbusFilter);

    //Push the X bus targets found to the iv_xbusTargetList
    for(uint32_t l_index =0 ; l_index < l_xbusTargetList.size();
        ++l_index)
    {
        iv_xbusTargetList.push_back(l_xbusTargetList[l_index]);
    }

    TARGETING::targetService().getAssociated(l_abusTargetList,
            iv_procTarget,
            TARGETING::TargetService::CHILD,
            TARGETING::TargetService::ALL,
            &l_funcAndAbusFilter);
    //Push the A bus targets found to the iv_abusTargetList
    for(uint32_t l_index =0 ; l_index < l_abusTargetList.size();
        ++l_index)
    {
        iv_abusTargetList.push_back(l_abusTargetList[l_index]);
    }

    TOD_EXIT("init");

    return;
}

//******************************************************************************
// TodProc::connect
//******************************************************************************
errlHndl_t TodProc::connect(
        TodProc* i_destination,
        const TARGETING::TYPE i_busChipUnitType,
        bool& o_isConnected)
{
    TOD_ENTER("Source proc HUID = 0x%08X "
        "Destination proc HUID = 0x%08X "
        "Bus type for connection = 0x%08X ",
        iv_procTarget->getAttr<TARGETING::ATTR_HUID>(),
        i_destination->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
        static_cast<uint32_t>(i_busChipUnitType));

    errlHndl_t l_errHndl = NULL;
    o_isConnected = false;

    do
    {
        if(iv_procTarget->getAttr<TARGETING::ATTR_HUID>() ==
                i_destination->getTarget()->getAttr<TARGETING::ATTR_HUID>())
        {
            TOD_INF("This and the destination are the same procs");
            o_isConnected = true;
            break;
        }

        TARGETING::TargetHandleList* l_pBusList = NULL;

        //Check whether we've to connect over X or A bus
        if(TARGETING::TYPE_XBUS == i_busChipUnitType)
        {
            l_pBusList = &iv_xbusTargetList;
        }
        else if(TARGETING::TYPE_ABUS == i_busChipUnitType)
        {
            l_pBusList = &iv_abusTargetList;
        }
        else
        {
            TOD_ERR("Bus type 0x%.8X passed to the method is not "
                "supported", i_busChipUnitType);
            logUnsupportedBusType(i_busChipUnitType,l_errHndl);
            break;
        }

        //From this proc (iv_procTarget), find if destination(i_destination)
        //has a connection via the bus type i_busChipUnitType :

        //Step 1: Sequentially pick buses from either iv_xbusTargetList or
        //iv_abusTargetList depending on the bus type specified as input
        //Step 2: Get the parent of peer target of the bus target found in the
        //previous step. If it matches with the destination, we got a connection
        //Step 3: If a match is found then fill the i_bus_tx and i_bus_rx
        //attributes for the destination proc and return

        const TARGETING::Target * l_proc = NULL;
        TARGETING::TargetHandleList l_busList;

        TARGETING::TargetHandleList::iterator l_busIter = (*l_pBusList).begin();
        for(;l_busIter != (*l_pBusList).end() ; ++l_busIter)
        {
            l_busList.clear();

            //Get the peer target for this bus connection
            //I need to know the peer's (bus endpoint) attributes such as
            //HUID, chip unit. Applying a result filter will get me the proc
            //on the other end, but will abstract away the bus, which is not
            //what I want.
            getPeerTargets(
                 l_busList,
                *l_busIter,
                 NULL,
                 NULL);

            //There should be only 1 peer
            if(1 == l_busList.size())
            {
                l_proc = getParentChip(l_busList[0]);

                if((l_proc) &&
                   l_proc->getAttr<TARGETING::ATTR_HWAS_STATE>().functional &&
                   (l_proc->getAttr<TARGETING::ATTR_HUID>() ==
                       i_destination->iv_procTarget->
                           getAttr<TARGETING::ATTR_HUID>()))
                {
                    //We found a connection :
                    //iv_procTarget --- i_busChipUnitType --- i_destination
                    TOD_INF("Source processor 0x%.8X connects with the "
                        "destination processor 0x%.8X over "
                        "source bus 0x%.8X and destination bus 0x%.8X "
                        "via bus type 0x%.8X",
                        iv_procTarget->getAttr<TARGETING::ATTR_HUID>(),
                        i_destination->iv_procTarget->
                            getAttr<TARGETING::ATTR_HUID>(),
                        (*l_busIter)->getAttr<TARGETING::ATTR_HUID>(),
                        l_busList[0]->getAttr<TARGETING::ATTR_HUID>(),
                        i_busChipUnitType);

                    //Determine the bus type as per our format, for eg XBUS0
                    //ATTR_CHIP_UNIT gives the instance number of
                    //the bus and it has direct correspondance to
                    //the port no.
                    //For instance a processor has two A buses
                    //then the one with ATTR_CHIP_UNIT 0 will be A0
                    //and the one with ATTR_CHIP_UNIT 1 will be A1
                    proc_tod_setup_bus l_busOut = NONE;
                    proc_tod_setup_bus l_busIn = NONE;
                    l_errHndl = getBusPort(i_busChipUnitType,
                                    (*l_busIter)->
                                        getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                                    l_busOut);
                    if(NULL == l_errHndl)
                    {
                        l_errHndl = getBusPort(i_busChipUnitType,
                            l_busList[0]->
                                getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                            l_busIn);
                    }
                    if(l_errHndl)
                    {
                        //Should not be hitting this path if HW procedure is
                        //correctly defining all the bus types and ports
                        TOD_ERR("proc_tod_setup_bus type not found for "
                            "port 0x%.2X of bus type 0x%.8X. Source processor "
                            "0x%.8X, destination processor 0x%.8X",
                            (*l_busIter)->
                                getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                            i_busChipUnitType,
                            iv_procTarget->
                                getAttr<TARGETING::ATTR_HUID>(),
                            i_destination->iv_procTarget->
                                getAttr<TARGETING::ATTR_HUID>());
                        break;
                    }

                    //Set the bus connections for i_destination :
                    //Bus out from this proc = l_busOut;
                    //Bus in to destination = l_busIn;
                    i_destination->setConnections(l_busOut, l_busIn);
                    o_isConnected = true;
                    break;
                }
            }
        }
        if(l_errHndl)
        {
            break;
        }
    }while(0);

    TOD_EXIT("connect. errHdl = %p", l_errHndl);

    return l_errHndl;
}

//******************************************************************************
//TodProc::getBusPort
//******************************************************************************
errlHndl_t TodProc::getBusPort(
        const TARGETING::TYPE  i_busChipUnitType,
        const uint32_t  i_busPort,
        proc_tod_setup_bus& o_busPort) const
{
    TOD_ENTER("getBusPort");

    errlHndl_t l_errHndl = NULL;

    if(TARGETING::TYPE_XBUS == i_busChipUnitType)
    {
        switch(i_busPort)
        {
            case 0:
                o_busPort = XBUS0;
                break;
            case 1:
                o_busPort = XBUS1;
                break;
            case 2:
                o_busPort = XBUS2;
                break;
            case 3:
                o_busPort = XBUS3;
                break;
            default:
                TOD_ERR("Port 0x%.8X not supported for X bus",
                    i_busPort);
                logUnsupportedBusPort(i_busPort,
                    i_busChipUnitType,
                    l_errHndl);
                break;
        }
    }
    else if(TARGETING::TYPE_ABUS == i_busChipUnitType)
    {
        switch(i_busPort)
        {
            case 0:
                o_busPort = ABUS0;
                break;
            case 1:
                o_busPort = ABUS1;
                break;
            case 2:
                o_busPort = ABUS2;
                break;
            default:
                TOD_ERR("Port 0x%.8X not supported for A bus",
                    i_busPort);
                logUnsupportedBusPort(i_busPort,
                    i_busChipUnitType,
                    l_errHndl);
                break;
        }
    }
    else
    {
        TOD_ERR("Bus type 0X%.8X not supported",i_busChipUnitType);
        logUnsupportedBusType(i_busChipUnitType, l_errHndl);
    }

    TOD_EXIT("getBusPort. errHdl = %p", l_errHndl);

    return l_errHndl;
}


//******************************************************************************
//TodProc::logUnsupportedBusType
//******************************************************************************
void TodProc::logUnsupportedBusType(const int32_t i_busChipUnitType,
        errlHndl_t& io_errHdl) const
{
    /*@
     * @errortype
     * @moduleid     TOD_LOG_UNSUPPORTED_BUSTYPE
     * @reasoncode   TOD_UNSUPPORTED_BUSTYPE
     * @userdata1    Bus type that is not currently supported
     * @devdesc      Error: Unsupported bus type was detected
     *               Possible Causes: Invalid bus configuration in targeting, or
     *               getBusPort method has not been updated to support all the
     *               bus type on a given system.
     *               Resolution:Development team should be contacted.
     */
     io_errHdl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        TOD_LOG_UNSUPPORTED_BUSTYPE,
                        TOD_UNSUPPORTED_BUSTYPE,
                        i_busChipUnitType, 0);
}

//******************************************************************************
//TodProc::logUnsupportedBusPort
//******************************************************************************
void TodProc::logUnsupportedBusPort(
        const int32_t i_busPort,
        const int32_t i_busChipUnitType,
        errlHndl_t& io_errHdl) const
{
    /*@
     * @errortype
     * @reasoncode   TOD_UNSUPPORTED_BUSPORT
     * @moduleid     TOD_LOG_UNSUPPORTED_BUSPORT
     * @userdata1    Bus port that is not currently supported
     * @userdata2    Bus Type for which the unsupported port has been reported
     * @devdesc      Error: Unsupported bus port was detected for the specified
     *               bus type.
     *               Possible Causes: Invalid bus configuration in targeting, or
     *               getBusPort method has not been updated to support all the
     *               possible port for a bus on a given system type.
     *               Resolution:Development team should be contacted.
     */
     io_errHdl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        TOD_LOG_UNSUPPORTED_BUSPORT,
                        TOD_UNSUPPORTED_BUSPORT,
                        i_busPort, i_busChipUnitType);
}

//******************************************************************************
// TodProc::addChild
//******************************************************************************
void TodProc::addChild(TodProc* i_child)
{
    TOD_ENTER("addChild");

    if(iv_procTarget->getAttr<TARGETING::ATTR_HUID>() !=
            i_child->getTarget()->getAttr<TARGETING::ATTR_HUID>())
    {
        iv_childrenList.push_back(i_child);
        (iv_tod_node_data->i_children).push_back(i_child->getTopologyNode());
    }

    TOD_EXIT("addChild");
}

//******************************************************************************
// TodProc::getTodRegs
//******************************************************************************
void TodProc::getTodRegs(proc_tod_setup_conf_regs& o_todRegs) const
{
    o_todRegs.tod_m_path_ctrl_reg =
        iv_tod_node_data->o_todRegs.tod_m_path_ctrl_reg;
    o_todRegs.tod_pri_port_0_ctrl_reg =
        iv_tod_node_data->o_todRegs.tod_pri_port_0_ctrl_reg;
    o_todRegs.tod_pri_port_1_ctrl_reg =
        iv_tod_node_data->o_todRegs.tod_pri_port_1_ctrl_reg;
    o_todRegs.tod_sec_port_0_ctrl_reg =
        iv_tod_node_data->o_todRegs.tod_sec_port_0_ctrl_reg;
    o_todRegs.tod_sec_port_1_ctrl_reg =
        iv_tod_node_data->o_todRegs.tod_sec_port_1_ctrl_reg;
    o_todRegs.tod_s_path_ctrl_reg =
        iv_tod_node_data->o_todRegs.tod_s_path_ctrl_reg;
    o_todRegs.tod_i_path_ctrl_reg =
        iv_tod_node_data->o_todRegs.tod_i_path_ctrl_reg;
    o_todRegs.tod_pss_mss_ctrl_reg =
        iv_tod_node_data->o_todRegs.tod_pss_mss_ctrl_reg;
    o_todRegs.tod_chip_ctrl_reg =
        iv_tod_node_data->o_todRegs.tod_chip_ctrl_reg;
}

//******************************************************************************
//TodProc::setTodChipData
//******************************************************************************
void TodProc::setTodChipData(TodChipData& o_todChipData) const
{
    proc_tod_setup_conf_regs& l_todRegs = iv_tod_node_data->o_todRegs;

    o_todChipData.header.chipID = iv_procTarget->
        getAttr<TARGETING::ATTR_POSITION>();

    o_todChipData.header.flags |= TOD_FUNC;

    o_todChipData.regs.mpcr = l_todRegs.tod_m_path_ctrl_reg.getWord(0);
    o_todChipData.regs.pcrp0 =  l_todRegs.tod_pri_port_0_ctrl_reg.getWord(0);
    o_todChipData.regs.pcrp1 = l_todRegs.tod_pri_port_1_ctrl_reg.getWord(0);
    o_todChipData.regs.scrp0 = l_todRegs.tod_sec_port_0_ctrl_reg.getWord(0);
    o_todChipData.regs.scrp1 = l_todRegs.tod_sec_port_1_ctrl_reg.getWord(0);
    o_todChipData.regs.spcr = l_todRegs.tod_s_path_ctrl_reg.getWord(0);
    o_todChipData.regs.ipcr = l_todRegs.tod_i_path_ctrl_reg.getWord(0);
    o_todChipData.regs.psmscr = l_todRegs.tod_pss_mss_ctrl_reg.getWord(0);
    o_todChipData.regs.ccr = l_todRegs.tod_chip_ctrl_reg.getWord(0);
}

} //end of namespace
