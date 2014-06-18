/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep12list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
#ifndef __ISTEPS_ISTEP12LIST_H
#define __ISTEPS_ISTEP12LIST_H

/**
 * @file    istep12list.H
 *
 *  IStep 12    Step 12 MC Config
 *  IPL FLow Doc        v1.35 (04/11/13)
 *
 *  12.1      host_collect_dimm_spd
 *  	: Collect Master dimm SPD
  *  12.2     mss_volt
 *  	: Calc dimm voltage
 *  12.3      mss_freq
 *  	: Calc dimm frequency
 *  12.4      mss_eff_config
 *  	: Determine effective config
 *  12.5      mss_attr_update
 *      : MSS ATTR update
*
*  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-03-01:1032
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/mc_config/mc_config.H"

#include <config.h>

namespace   INITSERVICE
{

const   TaskInfo    g_istep12[]  =   {
        {
                "",                   // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(12,01,"host_collect_dimm_spd"),
                MC_CONFIG::call_host_collect_dimm_spd,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,02,"mss_volt"),
                MC_CONFIG::call_mss_volt,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,03,"mss_freq"),
                MC_CONFIG::call_mss_freq,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,04,"mss_eff_config"),
                MC_CONFIG::call_mss_eff_config,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(12,05,"mss_attr_update"),
                MC_CONFIG::call_mss_attr_update,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
};

const DepModInfo g_istep12Dependancies = {
    {
        DEP_LIB(libmc_config.so),
#ifdef CONFIG_DJVPD_READ_FROM_HW
        DEP_LIB(libdram_training.so),
#endif // CONFIG_DJVPD_READ_FROM_HW
        NULL
    }
};

const ExtTaskInfo g_istep12TaskList = {
    &(g_istep12[0]),
    ( sizeof(g_istep12)/sizeof(TaskInfo) ),
    &g_istep12Dependancies
};

};  // end namespace

#endif
