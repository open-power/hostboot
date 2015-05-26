/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep08list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#ifndef __ISTEPS_ISTEP08LIST_H
#define __ISTEPS_ISTEP08LIST_H

/**
 * @file    istep08list.H
 *
 *  IStep 08        Nest Chiplets
 *  IPL FLow Doc    v0.60 (06/02/15)
 *
 *    08.01    host_slave_sbe_config
 *           : Configure host slave sbe
 *    08.02    host_setup_sbe
 *           : Setup host sbe
 *    08.03    host_cbs_start
 *           : Start cbs
 *    08.04    proc_check_slave_sbe_seeprom_complete
 *           : Check Slave SBE Complete
 *    08.05    proc_cen_ref_clk_enable
 *           : Setup centaur ref clocks
 *    08.06    proc_attr_update
 *           : Proc ATTR Update
 *    08.07    proc_enable_osclite
 *           : Enable Osclite
 *    08.08    proc_chiplet_scominit
 *           : Scom inits to all chiplets (sans Quad)
 *    08.09    proc_xbus_scominit
 *           : Apply scom inits to Xbus
 *    08.10    proc_abus_scominit
 *           : Apply scom inits to Abus
 *    08.11    proc_obus_scominit
 *           : Apply scom inits to Obus
 *    08.12    proc_npu_scominit
 *           : Apply scom inits to Npu
 *    08.13    proc_pcie_scominit
 *           : Apply scom inits to PCIechiplets
 *    08.14    proc_scomoverride_chiplets
 *           : Apply sequenced scom inits
 *    08.15    proc_chiplet_enable_ridi
 *           : Enable RI/DI chip wide
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/nest_chiplets/nest_chiplets.H"
#include    "../../../usr/hwpf/hwp/slave_sbe/slave_sbe.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep08[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(08,01,"host_slave_sbe_config"),
                SLAVE_SBE::call_host_slave_sbe_config,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,02,"host_setup_sbe"),
                SLAVE_SBE::call_host_setup_sbe,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,03,"host_cbs_start"),
                SLAVE_SBE::call_host_cbs_start,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,04,"proc_check_slave_sbe_seeprom_complete"),
                SLAVE_SBE::call_proc_check_slave_sbe_seeprom_complete,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
        {
                ISTEPNAME(08,05,"proc_cen_ref_clk_enable"),
                SLAVE_SBE::call_proc_cen_ref_clk_enable,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,06,"proc_attr_update"),
                NEST_CHIPLETS::call_proc_attr_update,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,07,"proc_enable_osclite"),
                NEST_CHIPLETS::call_proc_enable_osclite,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,08,"proc_chiplet_scominit"),
                NEST_CHIPLETS::call_proc_chiplet_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,09,"proc_xbus_scominit"),
                NEST_CHIPLETS::call_proc_xbus_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,10,"proc_abus_scominit"),
                NEST_CHIPLETS::call_proc_abus_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,11,"proc_obus_scominit"),
                NEST_CHIPLETS::call_proc_obus_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,12,"proc_npu_scominit"),
                NEST_CHIPLETS::call_proc_npu_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,13,"proc_pcie_scominit"),
                NEST_CHIPLETS::call_proc_pcie_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,14,"proc_scomoverride_chiplets"),
                NEST_CHIPLETS::call_proc_scomoverride_chiplets,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,15,"proc_chiplet_enable_ridi"),
                NEST_CHIPLETS::call_proc_chiplet_enable_ridi,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },

};

const DepModInfo g_istep08Dependancies = {
    {
        DEP_LIB(libnest_chiplets.so),
        DEP_LIB(libslave_sbe.so),
        DEP_LIB(libsbe.so),
        DEP_LIB(libpstates.so),
        NULL
    }
};

const ExtTaskInfo g_istep08TaskList = {
    &(g_istep08[0]),
    ( sizeof(g_istep08)/sizeof(TaskInfo) ),
    &g_istep08Dependancies
};

};  // end namespace

#endif
