/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodProc.H $                                */
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
#ifndef  TODPROC_H
#define  TODPROC_H

/**
 *  @file TodProc.H
 *
 *  @brief Contains TodProc class declaration
 *   TodProc class encapsulates a proc chip target with other attributes
 *   that are necessary to define the proc chip in a TOD topology
 */

//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
//HWPF - For TOD constants
#include <p10_tod_utils.H>
#include "TodSvcUtil.H"
#include "TodAssert.H"

namespace TOD
{

//--------------------------------------------------------------------------
//Forward declarations
//--------------------------------------------------------------------------
struct TodChipData;
class TodDrawer;
class TodProc;

//--------------------------------------------------------------------------
//Typedefs
//--------------------------------------------------------------------------
typedef std::list<TodProc*> TodProcContainer;
typedef std::list<tod_topology_node*> TodTopologyNodeContainer;
/**
 * @class TodProc
 *
 * @brief  TodProc class encapsulates a proc chip target with other
 *  attributes that helps to identify the position of proc chip in a
 *  TOD netwok and also define its connection with other proc chips
 */
class TodProc
{
    public:

        //Specify proc master type :
        //TOD master/drawer master
        enum ProcMasterType
        {
            NOT_MASTER    = 0x00,
            TOD_MASTER    = 0x01,
            DRAWER_MASTER = 0x02
        };

        /**
         * @brief Constructor
         *
         * @param[in] i_procTarget
         *     Pointer to proc target
         *
         * @param[in] i_parentDrawer
         *     Pointer to TOD drawer in which this proc is contained
         */
        TodProc(const TARGETING::Target* i_procTarget,
                const TodDrawer* i_parentDrawer);

        /**
         * @brief Destructor
         */
        ~TodProc();

        /**
         * @brief The method will try to connect TodProc object, for which
         *  the method has been called to the TodProc object specified
         *  in destination argument.
         *
         * @par Detailed Description:
         *  While creating the TOD topology TodTopologyManager will connect
         *  TodProc objects to the topology if they
         *  physically connect over A/X bus, to a TodProc object
         *  that is already part of the topology and also valid  candidate for
         *  connecting the TodProc object under consideration.
         *
         *  The process of connecting processors starts with MDMT and will
         *  continue till all the processors are connected.
         *  At each step TodTopologyManager will make call to connect
         *  method. This method will check if processor chip owned by
         *  TodProc object (for which the method is called ) is physically
         *  connected to the destination (passed as argument), over the bus type
         *  specified in argument to the method.
         *
         *  If they connect then the i_bus_rx and  i_bus_tx members of
         *  iv_tod_node_data will be filled up for the destination object
         *  such that
         *  i_bus_rx == The bus on destination object that connects to the
         *  this proc
         *  i_bus_tx == The bus on this proc that connects to the
         *  destination
         *
         * @param[in] i_destination, Pointer to destination TodProc object
         *  that has to be connected.
         *
         * @param[in] i_busChipUnitType, Type of the bus (A/X) for which
         *   connection has to be determined
         *
         * @param[out] o_isConnected, this parameter will be set to true if
         *  source and destination connect over the specified bus type. Before
         *  looking for o_isConnected the caller should check for returned error
         *  log handle and only if it is NULL o_isConnected should be
         *  considered.
         *
         * @return Error log handle, indicates status of request
         * @retval NULL indicates that connect method's algorithm  executed
         *  successfully, however in order to know if two processor objects
         *  connect over the specified bus or not o_isConnected has to be
         *  examined.
         * @retval !NULL indicates that method connect could not be completed
         *  successfully. In this case o_isConnected should be ignored.
         *
         *  Error log handle points to a valid error log object whose primary
         *  SRC reason code (pError->getSRC()->reasonCode()) indicates the type
         *  of error.
         *
         * @note It is up to the caller to change the severity of the
         *  returned error based on what it decides to do with it. By default
         *  any returned error created by this function will be a non-reported
         *  tracing event error log.
         */
        errlHndl_t connect(
                TodProc* i_destination,
                const TARGETING::TYPE i_busChipUnitType,
                bool& o_isConnected);

        /**
         * @brief This is a helper method for connect, that will pick a value
         *  from p10_tod_setup_bus enum corresponding to the bus type and
         *  the  port specified as argument
         *
         * @param[in] i_busChipUnitType , This will indicate   A/X bus type
         *
         * @param[in] i_busPort , The port of the bus
         *
         * @param[out] o_busId , p10_tod_setup_bus enum member corresponding to
         *  the bus type and bus port specified as parameter. Before looking for
         *  o_busId caller should look for returned error handle and only if it
         *  is NULL, o_busId should be considered.
         *
         * @return Error log handle, indicates status of request
         * @retval NULL, indicates o_busId was successfully found
         * @retval !NULL, indicates that o_busId could not be found possibly
         *  because specified bus type and port combination is not supported
         *
         *  Error log handle points to a valid error log object whose primary
         *  SRC reason code (pError->getSRC()->reasonCode()) indicates the type
         *  of error.
         *
         * @note It is up to the caller to change the severity of the
         *  returned error based on what it decides to do with it. By default
         *  any returned error created by this function will be a non-reported
         *  tracing event error log.
         */
        errlHndl_t getBusPort(
                const   TARGETING::TYPE  i_busChipUnitType,
                const uint32_t  i_busPort,
                p10_tod_setup_bus& o_busId) const;

        /**
         * @brief Method to create an errlHndl_t object for
         *  UNSUPPORTED_BUSTYPE
         *
         * @par Detailed Description:
         *  This error will be logged by a method if it finds that a particular
         *  bus type is not supported on TOD topology.
         *
         * @param[in] i_busChipUnitType, Type of bus that is not supported
         *
         * @param[out] io_errHdl
         *  On input this parameter will be either NULL or pointing to
         *  an existing error handle.
         *  On output this parameter will either have a newly created handle
         *  assigned to it ( If input parameter was NULL ) or a new SRC will be
         *  appened to existing error handle ( If the input was not NULL )
         *
         * @return N/A
         */
        void logUnsupportedBusType(const int32_t i_busChipUnitType,
                errlHndl_t& io_errHdl) const;

        /**
         * @brief Method to create an errlHndl_t object for
         *  UNSUPPORTED_BUSPORT
         *
         * @par Detailed Description:
         *  This error will be logged by getBusPort if it finds that the input
         *  bus port is not supported for a specified bus type, from
         *  TOD topology point of view.
         *
         * @param[in] i_busPort , Type of bus that is not currently supported.
         *
         * @param[out] io_errHdl
         *  On input this parameter will be either NULL or pointing to
         *  an existing error handle.
         *  On output this parameter will either have a newly created handle
         *  assigned to it ( If input parameter was NULL ) or a new SRC will be
         *  appened to existing error handle ( If the input was not NULL )
         *
         * @return N/A
         */
        void logUnsupportedBusPort(
                const int32_t i_busPort,
                const int32_t i_busChipUnitType,
                errlHndl_t& io_errHdl) const;

        /**
         * @brief Add a child TodProc to this (adds to iv_childrenList).
         *  Added child will receive TOD signal from the processor
         *  represented by this TodProc object.
         *
         * @param[in] i_child
         *     Pointer to child TodProc
         *
         * @return N/A
         */
        void addChild(TodProc* i_child);

        /**
         * @brief Setter method for iv_masterType
         *
         * @param[in] i_masterType
         *      Parameter to indicate the master type
         *
         * @return N/A
         */
        void setMasterType(const ProcMasterType i_masterType);

        /**
         * @brief Getter method for iv_masterType
         *
         * @return ProcMasterType, value of iv_masterType
         */
        ProcMasterType getMasterType() const ;

        /**
         * @brief Getter for TOD registers for this proc
         *  Check proc_tod_utils.H : p10_tod_setup_conf_regs for the list of
         *  registers. The registers are updated by the TOD HWP.
         *
         * @param[out] o_todRegs
         *  container of TOD registers
         *
         * @return N/A
         */
        void getTodRegs(p10_tod_setup_conf_regs& o_todRegs) const;

        /**
         * @brief This method will populate the TodChipData object passed as
         *  input with the TOD register values of the this proc.
         *
         * @param[out] o_todChipData
         *  The TodChipData object in which data has to be output
         *
         * @return NA
         *
         */
        void setTodChipData(TodChipData& o_todChipData) const;


        /**
         * @brief Getter method for iv_tod_node_data
         *
         * @return tod_topology_node*, pointer to this proc's topology
         *  node structure
         */
        tod_topology_node* getTopologyNode()
        {
            return iv_tod_node_data;
        }

        /**
         * @brief Getter method for iv_parentDrawer
         *
         * @return TodDrawer*, pointer to this proc's containing TOD drawer
         */
        const TodDrawer* getParentDrawer() const
        {
            return iv_parentDrawer;
        }

        /**
         * @brief Getter method for tod_topology_node::i_bus_rx data member ,
         *  i_bus_rx is the fabric bus over which current processor receives
         *  signals from its parent
         *
         * @return p10_tod_setup_bus bus type and port
         */
        p10_tod_setup_bus getBusIn() const
        {
            return iv_tod_node_data->i_bus_rx;
        }

        /**
         * @brief Getter method for tod_topology_node::i_bus_tx data member ,
         *  i_bus_tx is the bus over which signal is transmitted by the
         *  parent of this processor
         *
         * @return p10_tod_setup_bus bus type and port
         */
        p10_tod_setup_bus getBusOut() const
        {
            return iv_tod_node_data->i_bus_tx;
        }

        /**
         * @brief Getter method for iv_procTarget
         *
         * @return Target pointer for this proc
         */
        const TARGETING::Target* getTarget() const
        {
            return iv_procTarget;
        }

        /**
         * @brief Getter method for iv_childrenList.
         *  see also addChild
         *
         * @param[out] o_childrenList
         *  List of pointers to children TodProc
         *
         * @return N/A
         */
        void getChildren(TodProcContainer& o_childrenList) const
        {
            o_childrenList = iv_childrenList;
        }

        /**
         * @brief Sets bus in and bus out
         *
         * @return N/A
         */
        void setConnections(const p10_tod_setup_bus i_parentBusOut,
                const p10_tod_setup_bus i_thisBusIn)
        {
            iv_tod_node_data->i_bus_tx = i_parentBusOut;
            iv_tod_node_data->i_bus_rx = i_thisBusIn;
        }

    private:
        /*
         * @brief Helper method to initialize the bus parameter
         *  iv_smpgroupTargetList and iv_tod_node_data,
         *  for this object.
         *   It will be called from the constructor.
         *
         * @return N/A
         */
        void init();

        //Target pointer to the processor chip, that is been encapsulated in
        //the TodProc object
        const TARGETING::Target* iv_procTarget;

        //Pointer to the parent TodDrawer object to which this processor
        //belong
        const TodDrawer * iv_parentDrawer;

        //List of SMPGROUP bus targets for this processor
        TARGETING::TargetHandleList iv_smpgroupTargetList;

        //List of children that will receive TOD signal from this processor
        //belongs
        TodProcContainer iv_childrenList;

        //Pointer to the tod_topology_node object that defines  TOD specific
        //attributes for this processor chip, the reason this has been kept
        //seperate is this data structure is shared across HW procedure
        tod_topology_node* iv_tod_node_data;

        //Data member to indicate if this processor is either a TOD_MASTER or
        //DRAWER_MASTER
        ProcMasterType iv_masterType;

};

}//end of namespace

#endif //TODPROC_H
