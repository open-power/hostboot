/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep13list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
/* [+] Google Inc.                                                        */
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
#ifndef __ISTEPS_ISTEP13LIST_H
#define __ISTEPS_ISTEP13LIST_H


/**
 * @file    istep13list.H
 *
 *  IStep 13    Step 13 DRAM Training
 *  IPL FLow Doc        v1.37 (08/13/13)
 *
 *  13.1      host_disable_vddr
 *      : Disable VDDR on CanContinue loops
 *  13.2      mem_pll_initf
 *      : PLL Initfile for MBAs
 *  13.3      mem_pll_setup
 *      : Setup PLL for MBAs
 *  13.4      mem_startclocks
 *      : Start clocks on MBAs
 *  13.5      host_enable_vddr
 *      : Enable the VDDR3 Voltage Rail
 *  13.6      mss_scominit
 *      : Perform scom inits to MC and PHY
 *  13.7      mss_ddr_phy_reset
 *      : Soft reset of DDR PHY macros
 *  13.8      mss_draminit
 *      : Dram initialize
 *  13.9      mss_draminit_training
 *      : Dram training
 *  13.10     mss_draminit_trainadv
 *      : Advanced dram training
 *  13.11     mss_draminit_mc
 *      : Hand off control to MC
 *  13.12 mss_dimm_power_test
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-02-27:2142
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/dram_training/dram_training.H"
#include <config.h>

namespace   INITSERVICE
{
const   TaskInfo    g_istep13[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },

// Reduce extended image size for VPO
#ifndef CONFIG_VPO_COMPILE
        {
                ISTEPNAME(13,01,"host_disable_vddr"),
                DRAM_TRAINING::call_host_disable_vddr,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,02,"mem_pll_initf"),
                DRAM_TRAINING::call_mem_pll_initf,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,03,"mem_pll_setup"),
                DRAM_TRAINING::call_mem_pll_setup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,04,"mem_startclocks"),
                DRAM_TRAINING::call_mem_startclocks,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,05,"host_enable_vddr"),
                DRAM_TRAINING::call_host_enable_vddr,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,06,"mss_scominit"),
                DRAM_TRAINING::call_mss_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,07,"mss_ddr_phy_reset"),
                DRAM_TRAINING::call_mss_ddr_phy_reset,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,08,"mss_draminit"),
                DRAM_TRAINING::call_mss_draminit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,09,"mss_draminit_training"),
                DRAM_TRAINING::call_mss_draminit_training,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,10,"mss_draminit_trainadv"),
                DRAM_TRAINING::call_mss_draminit_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,11,"mss_draminit_mc"),
                DRAM_TRAINING::call_mss_draminit_mc,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,12,"mss_dimm_power_test"),
                DRAM_TRAINING::call_mss_dimm_power_test,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
#endif
};

const DepModInfo g_istep13Dependancies = {
    {
#ifndef CONFIG_VPO_COMPILE
        DEP_LIB(libdram_training.so),
        DEP_LIB(libdram_initialization.so),
        DEP_LIB(libmc_config.so),
#endif
        NULL
    }
};

const ExtTaskInfo g_istep13TaskList = {
    &(g_istep13[0]),
    ( sizeof(g_istep13)/sizeof(TaskInfo) ),
    &g_istep13Dependancies
};

};  // end namespace

#endif
