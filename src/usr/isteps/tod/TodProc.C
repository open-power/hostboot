/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodProc.C $                                */
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
//Standard library
#include <list>
//Targeting support
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <isteps/tod_init_reasoncodes.H>
#include "TodDrawer.H"
#include "TodProc.H"
#include <isteps/tod/TodTypes.H>
#include "TodControls.H"
#include <hwas/common/deconfigGard.H>
#include "TodAssert.H"
#include "TodTrace.H"
//HWPF
#include <fapi2/target.H>
#include <target_types.H>
#include "TodUtils.H"

extern "C" {

using namespace fapi2;

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
           iv_tod_node_data(nullptr),
           iv_masterType(NOT_MASTER)
{
    TOD_ENTER("TodProc constructor");

    do
    {
      if(!iv_procTarget)
      {
          TOD_ERR_ASSERT("Target input i_procTarget is nullptr ");
          break;
      }
      if(!iv_parentDrawer)
      {
          TOD_ERR_ASSERT("TOD drawer input iv_parentDrawer is nullptr ");
          break;
      }

    TOD_ENTER("Created proc 0x%.8X on drawer 0x%.2X",
                 iv_procTarget->getAttr<TARGETING::ATTR_HUID>(),
                 iv_parentDrawer->getId());
    init();
    } while (0);

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
        iv_tod_node_data->i_target = nullptr;
        delete iv_tod_node_data;
        iv_tod_node_data = nullptr;
    }

    iv_smpgroupTargetList.clear();

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
    TOD_IMP("Proc 0X%.8X is the drawer master for TOD drawer 0x%.2X",
             GETHUID(iv_procTarget), iv_parentDrawer->getId());
    if(TOD_MASTER == i_masterType)
    {
        TOD_IMP("Proc 0X%.8X is a TOD master",
                 GETHUID(iv_procTarget));
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
    iv_tod_node_data->i_target = new
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
        (const_cast<TARGETING::Target*>(iv_procTarget));
    iv_tod_node_data->i_tod_master = false;
    iv_tod_node_data->i_drawer_master = false;
    iv_tod_node_data->i_bus_rx = TOD_SETUP_BUS_NONE;
    iv_tod_node_data->i_bus_tx = TOD_SETUP_BUS_NONE;

    TodTopologyNodeContainer::iterator l_childItr;

    for(l_childItr = iv_tod_node_data->i_children.begin();
        l_childItr != iv_tod_node_data->i_children.end();
        ++l_childItr)
    {
        delete (*l_childItr);
    }
    iv_tod_node_data->i_children.clear();

    iv_smpgroupTargetList.clear();

    //Make a list of outgoing bus targets for this processor
    TARGETING::PredicateCTM
        l_smpgroupCTM(TARGETING::CLASS_UNIT,TARGETING::TYPE_SMPGROUP);

    TARGETING::TargetHandleList l_smpgroupTargetList;

    TARGETING::PredicateIsFunctional l_func;
    TARGETING::PredicatePostfixExpr l_funcAndSmpgroupFilter;
    l_funcAndSmpgroupFilter.push(&l_smpgroupCTM).push(&l_func).And();

    TARGETING::targetService().getAssociated(iv_smpgroupTargetList,
            iv_procTarget,
            TARGETING::TargetService::CHILD,
            TARGETING::TargetService::ALL,
            &l_funcAndSmpgroupFilter);

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
    TOD_ENTER("TodProc::connect: Source proc HUID = 0x%08X "
        "Destination proc HUID = 0x%08X "
        "Bus type for connection = 0x%08X ",
        iv_procTarget->getAttr<TARGETING::ATTR_HUID>(),
        i_destination->getTarget()->getAttr<TARGETING::ATTR_HUID>(),
        static_cast<uint32_t>(i_busChipUnitType));

    errlHndl_t l_errHndl = nullptr;
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

        TARGETING::TargetHandleList* l_pBusList = nullptr;

        if(TARGETING::TYPE_SMPGROUP == i_busChipUnitType)
        {
            l_pBusList = &iv_smpgroupTargetList;
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

        //Step 1: Sequentially pick buses from iv_smpgroupTargetList
        //Step 2: Get the peer target of the bus target found in the previous
        //step.
        //For the parent processor of PEER target and the parent processor
        //matches with the destination, we got a connection.
        //Step 3: If a match is found then fill the i_bus_tx and i_bus_rx
        //attributes for the destination proc and return

        //Predicates to look for a functional proc whose HUID is same as
        //that of i_destination. This predicate will be applied as a result
        //filter to getPeerTargets to determine the connected proc.
        TARGETING::PredicateCTM
            l_procFilter(TARGETING::CLASS_CHIP,TARGETING::TYPE_PROC);
        TARGETING::PredicateIsFunctional l_funcFilter;
        TARGETING::PredicateAttrVal<TARGETING::ATTR_HUID>
            l_huidFilter(
                i_destination->getTarget()->getAttr<TARGETING::ATTR_HUID>());
        TARGETING::PredicatePostfixExpr l_resFilter;
        l_resFilter.
            push(&l_procFilter).
            push(&l_funcFilter).
            And().
            push(&l_huidFilter).
            And();

        TARGETING::TargetHandleList l_procList;

        TARGETING::TargetHandleList::iterator l_busIter = (*l_pBusList).begin();
        for(;l_busIter != (*l_pBusList).end() ; ++l_busIter)
        {
            l_procList.clear();

            //The call below is to determine the connected proc
            TARGETING::getPeerTargets(
                 l_procList,
                 *l_busIter,
                 nullptr,
                 //result filter to get the connected proc
                 &l_resFilter);

            if(l_procList.size())
            {
                auto busPeer = (*l_busIter)->
                                   getAttr<TARGETING::ATTR_PEER_TARGET>();
                if(!busPeer)
                {
                    //This is unlikely, since the proc list is not empty,
                    //we should have also found a bus, but just a safety check.
                    TOD_ERR_ASSERT(0,
                        "Couldn't find a peer for bus 0x%.8X on proc 0x%.8X",
                        (*l_busIter)->getAttr<TARGETING::ATTR_HUID>(),
                        iv_procTarget->getAttr<TARGETING::ATTR_HUID>());
                }
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
                    busPeer->getAttr<TARGETING::ATTR_HUID>(),
                    i_busChipUnitType);

                //Determine the bus type as per our format, for eg SMPGROUP0
                //ATTR_CHIP_UNIT gives the instance number of
                //the bus and it has direct correspondance to
                //the port no.
                //For instance a processor has two A buses
                //then the one with ATTR_CHIP_UNIT 0 will be A0
                //and the one with ATTR_CHIP_UNIT 1 will be A1
                p10_tod_setup_bus l_busOut = TOD_SETUP_BUS_NONE;
                p10_tod_setup_bus l_busIn = TOD_SETUP_BUS_NONE;
                l_errHndl = getBusPort(i_busChipUnitType,
                                (*l_busIter)->
                                    getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                                l_busOut);
                if(nullptr == l_errHndl)
                {
                    l_errHndl = getBusPort(i_busChipUnitType,
                        busPeer->
                            getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                        l_busIn);
                }
                if(l_errHndl)
                {
                    //Should not be hitting this path if HW procedure is
                    //correctly defining all the bus types and ports
                    TOD_ERR("p10_tod_setup_bus type not found for "
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
        p10_tod_setup_bus& o_busPort) const
{
    TOD_ENTER("getBusPort");

    errlHndl_t l_errHndl = nullptr;

    if(TARGETING::TYPE_IOHS == i_busChipUnitType)
    {
        switch(i_busPort)
        {
            case 0:
                o_busPort = TOD_SETUP_BUS_IOHS0;
                break;
            case 1:
                o_busPort = TOD_SETUP_BUS_IOHS1;
                break;
            case 2:
                o_busPort = TOD_SETUP_BUS_IOHS2;
                break;
            case 3:
                o_busPort = TOD_SETUP_BUS_IOHS3;
                break;
            case 4:
                o_busPort = TOD_SETUP_BUS_IOHS4;
                break;
            case 5:
                o_busPort = TOD_SETUP_BUS_IOHS5;
                break;
            case 6:
                o_busPort = TOD_SETUP_BUS_IOHS6;
                break;
            case 7:
                o_busPort = TOD_SETUP_BUS_IOHS7;
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
    else if (i_busChipUnitType == TARGETING::TYPE_SMPGROUP)
    {
        l_errHndl = getBusPort(TARGETING::TYPE_IOHS,
                               i_busPort / 2, // IOHS chip number is
                                              // the SMPGROUP chip
                                              // number divided by 2
                               o_busPort);
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
     * @custdesc     Host Firmware encountered an internal error
     */
    io_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_INFORMATIONAL,
                           TOD_MOD_LOG_UNSUPPORTED_BUSTYPE,
                           TOD_UNSUPPORTED_BUSTYPE,
                           i_busChipUnitType);
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
     * @moduleid     TOD_LOG_UNSUPPORTED_BUSPORT
     * @reasoncode   TOD_UNSUPPORTED_BUSPORT
     * @userdata1    Bus port that is not currently supported
     * @userdata2    Bus Type for which the unsupported port has been reported
     * @devdesc      Error: Unsupported bus port was detected for the specified
     *               bus type.
     *               Possible Causes: Invalid bus configuration in targeting, or
     *               getBusPort method has not been updated to support all the
     *               possible port for a particular type of bus on the system.
     *               Resolution:Development team should be contacted.
     * @custdesc     Host Firmware encountered an internal error
     */
    io_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_INFORMATIONAL,
                           TOD_MOD_LOG_UNSUPPORTED_BUSTYPE,
                           TOD_UNSUPPORTED_BUSPORT,
                           i_busPort,
                           i_busChipUnitType);
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
void TodProc::getTodRegs(p10_tod_setup_conf_regs& o_todRegs) const
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
    p10_tod_setup_conf_regs& l_todRegs = iv_tod_node_data->o_todRegs;

    o_todChipData.header.chipID = iv_procTarget->
        getAttr<TARGETING::ATTR_ORDINAL_ID>();

    o_todChipData.header.flags |= TOD_FUNC;

    fapi2::variable_buffer l_regData((uint32_t)64);

    l_regData.set(l_todRegs.tod_m_path_ctrl_reg(), 0);
    o_todChipData.regs.mpcr = l_regData.get<uint32_t>(0);

    l_regData.set(l_todRegs.tod_pri_port_0_ctrl_reg(), 0);
    o_todChipData.regs.pcrp0 = l_regData.get<uint32_t>(0);

    l_regData.set(l_todRegs.tod_pri_port_1_ctrl_reg(), 0);
    o_todChipData.regs.pcrp1 = l_regData.get<uint32_t>(0);

    l_regData.set(l_todRegs.tod_sec_port_0_ctrl_reg(), 0);
    o_todChipData.regs.scrp0 = l_regData.get<uint32_t>(0);

    l_regData.set(l_todRegs.tod_sec_port_1_ctrl_reg(), 0);
    o_todChipData.regs.scrp1 = l_regData.get<uint32_t>(0);

    l_regData.set(l_todRegs.tod_s_path_ctrl_reg(), 0);
    o_todChipData.regs.spcr = l_regData.get<uint32_t>(0);

    l_regData.set(l_todRegs.tod_i_path_ctrl_reg(), 0);
    o_todChipData.regs.ipcr = l_regData.get<uint32_t>(0);

    l_regData.set(l_todRegs.tod_pss_mss_ctrl_reg(), 0);
    o_todChipData.regs.psmscr = l_regData.get<uint32_t>(0);

    l_regData.set(l_todRegs.tod_chip_ctrl_reg(), 0);
    o_todChipData.regs.ccr = l_regData.get<uint32_t>(0);
}

}//end of namespace

}
