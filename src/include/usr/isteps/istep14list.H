/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep14list.H $                        */
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
#ifndef __ISTEPS_ISTEP14LIST_H
#define __ISTEPS_ISTEP14LIST_H

/**
 * @file    istep14list.H
 *
 *  IStep 14    Dram Initialization
 *  IPL FLow Doc        v1.41 (11/08/13)
 *
 *    14.1    host_startprd_dram
 *          : Load prd for DRAM domain
 *    14.2    mss_extent_setup
 *          : MSS Extent Setup
 *    14.3    mss_memdiag
 *          : Mainstore Pattern Testing
 *    14.4    mss_thermal_init
 *          : Initialize the thermal sensor
 *    14.5    proc_pcie_config
 *          : Configure the PHBs
 *    14.6    mss_power_cleanup
 *          : Clean up any MCS/Centaurs
 *    14.7    proc_setup_bars
 *          : Setup Memory BARs
 *    14.8    proc_exit_cache_contained
 *          : Allow execution from memory
 *    14.9    host_mpipl_service
 *          : Perform MPIPL tasks
 *
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>
#include <config.h>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/dram_initialization/dram_initialization.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep14[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },

// Reduce ext img for VPO
#ifndef CONFIG_VPO_COMPILE
        {
                ISTEPNAME(14,01,"host_startprd_dram"),
                DRAM_INITIALIZATION::call_host_startprd_dram,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,02,"mss_extent_setup"),
                DRAM_INITIALIZATION::call_mss_extent_setup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,03,"mss_memdiag"),
                DRAM_INITIALIZATION::call_mss_memdiag,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,04,"mss_thermal_init"),
                DRAM_INITIALIZATION::call_mss_thermal_init,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,05,"proc_pcie_config"),
                DRAM_INITIALIZATION::call_proc_pcie_config,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,06,"mss_power_cleanup"),
                DRAM_INITIALIZATION::call_mss_power_cleanup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,07,"proc_setup_bars"),
                DRAM_INITIALIZATION::call_proc_setup_bars,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,08,"proc_exit_cache_contained"),
                DRAM_INITIALIZATION::call_proc_exit_cache_contained,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, true }
        },
        {
                ISTEPNAME(14,09,"host_mpipl_service"),
                DRAM_INITIALIZATION::call_host_mpipl_service,
                { START_FN, EXT_IMAGE, MPIPL_OP, true }
        },
#endif
    };

const DepModInfo g_istep14Dependancies = {
    {
#ifndef CONFIG_VPO_COMPILE
        DEP_LIB(libdram_initialization.so),
        DEP_LIB(libdram_training.so),
        DEP_LIB(libdump.so),
        DEP_LIB(libnest_chiplets.so),
#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
        DEP_LIB(libocc.so),
#endif
#endif
        NULL
    }
};

const ExtTaskInfo g_istep14TaskList = {
    &(g_istep14[0]),
    ( sizeof(g_istep14)/sizeof(TaskInfo) ),
    &g_istep14Dependancies
};

};  // end namespace

#endif
