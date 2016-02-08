/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/TodTopologyManager.H $                 */
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
#ifndef TODTOPOLOGYMANAGER_H
#define TODTOPOLOGYMANAGER_H

/**
 *  @file TodTopologyManager.H
 *
 *  @brief TOD Topology Manager class definition. Responsible for
 *      creating/modifying the primary and secondary topologies
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

#include <errl/errlentry.H>
#include "proc_tod_utils/proc_tod_utils.H"

namespace TOD
{

//------------------------------------------------------------------------------
//Forward declarations
//------------------------------------------------------------------------------
class TodDrawer;

class TodTopologyManager
{
public:
    /**
     * @brief Constructor.
     *
     * @par Detailed Description:
     *     Create a topology manager by specifying the type :
     *     TOD_PRIMARY/TOD_SECONDARY. Having separate managers
     *     for the primary/secondary topology allows exclusive
     *     operations on the topology and a greater degree of
     *     error management.
     *
     * @param[in] i_type
     *     Primary(TOD_PRIMARY) or Secondary(TOD_SECONDARY)
     */
    TodTopologyManager(const proc_tod_setup_tod_sel i_type);

    /**
     * @brief Destructor.
     */
    ~TodTopologyManager();

    /**
     * @brief Create a TOD topology
     *
     * @par Detailed Description:
     *     The topology creation algorithm goes as follows:
     *     1)Pick the MDMT.
     *     2)In the master TOD drawer (the one in which MDMT lies),
     *       wire the procs together.
     *     3)Connect the MDMT to one processor in each of the slave TOD drawers
     *       (the TOD drawers other than the master TOD drawer).
     *     4)Wire the procs in the slave TOD drawers.
     *
     * @return Error log handle indicating the status of the request.
     * @retval NULL if successful
     * @retval !NULL if failed to create topology
     *
     *     Error log handle points to a valid error log object whose primary
     *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
     *     of error.
     *
     * @note It is up to the caller to change the severity of the
     *     returned error based on what it decides to do with it. By default
     *     any returned error created by this function will be a non-reported
     *     tracing event error log.
     */
    errlHndl_t create();

    /**
     * @brief Dumps the topology connections in this format to fsp-trace:
     *     parent---bus out---bus in---child. An example would be
     *     pu:k0:n0:s0:p00---XBUS1---XBUS1---pu:k0:n0:s0:p01
     *
     * @return N/A
     */
    void dumpTopology() const;

    /**
     * @brief Dumps the TOD register values that the hardware procedure
     *     supplied us with to fsp-trace. Check proc_tod_utils.H :
     *     proc_tod_setup_conf_regs for the list of registers.
     *
     * @return N/A
     */
    void dumpTodRegs() const;

private:
    /**
     * @brief Wires, or sets the X bus connection paths between
     *     processors in the input TOD drawer
     *
     * @param[in] i_pTodDrawer
     *     Pointer to a HwsvTodDrawer
     *
     * @return Error log handle indicating the status of the request.
     * @retval NULL if successful
     * @retval !NULL if failed to wire one or more procs in the TOD drawer
     *
     *     Error log handle points to a valid error log object whose primary
     *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
     *     of error.
     *
     * @note It is up to the caller to change the severity of the
     *     returned error based on what it decides to do with it. By default
     *     any returned error created by this function will be a non-reported
     *     tracing event error log.
     */
    errlHndl_t wireProcs(const TodDrawer* i_pTodDrawer);

    /**
     * @brief Wires, or sets the A bus connection paths between
     *     the MDMT and one of the processors in the input TOD
     *     drawer (thus designating that processor as the SDMT).
     *
     * @param[in] i_pTodDrawer
     *     Pointer to a TodDrawer
     *
     * @return Error log handle indicating the status of the request.
     * @retval NULL if successful
     * @retval !NULL if failed to connect the MDMT to any processor in the
     *     input TOD drawer.
     *
     *     Error log handle points to a valid error log object whose primary
     *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
     *     of error.
     *
     * @note It is up to the caller to change the severity of the
     *     returned error based on what it decides to do with it. By default
     *     any returned error created by this function will be a non-reported
     *     tracing event error log.
     */
    errlHndl_t wireTodDrawer(TodDrawer* i_pTodDrawer);

    //Holds the type of the topology this manager is working on :
    //primary/secondary
    proc_tod_setup_tod_sel iv_topologyType;
};

} //namespace TOD

#endif //#define TODTOPOLOGYMANAGER_H
