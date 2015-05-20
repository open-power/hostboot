/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep16list.H $                        */
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

#ifndef __ISTEPS_ISTEP16LIST_H
#define __ISTEPS_ISTEP16LIST_H

/**
 * @file    istep16list.H
 *
 *  IStep 16    Core Activate
 *  IPL FLow Doc        v1.41 (11/08/13)
 *
 *    16.1    host_activate_master
 *          : Activate master core
 *    16.2    host_activate_slave_cores
 *          : Activate slave cores
 *    16.3    mss_scrub
 *          : Start background scrub
 *    16.4    host_ipl_complete
 *          : Notify FSP drawer ipl complete
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1609
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/core_activate/core_activate.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep16[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(16,01,"host_activate_master"),
                CORE_ACTIVATE::call_host_activate_master,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, true }
        },
        {
                ISTEPNAME(16,02,"host_activate_slave_cores"),
                CORE_ACTIVATE::call_host_activate_slave_cores,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, true }
        },
        {
                ISTEPNAME(16,03,"mss_scrub"),
                CORE_ACTIVATE::call_mss_scrub,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(16,04,"host_ipl_complete"),
                CORE_ACTIVATE::call_host_ipl_complete,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
};

const DepModInfo g_istep16Dependancies = {
    {
        DEP_LIB(libcore_activate.so),
        DEP_LIB(libbuild_winkle_images.so),
        DEP_LIB(libnest_chiplets.so),
#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
        DEP_LIB(libocc.so),
#endif
        NULL
    }
};

const   ExtTaskInfo g_istep16TaskList    =   {
    &(g_istep16[0]),
    ( sizeof(g_istep16)/sizeof(TaskInfo) ),
    &g_istep16Dependancies
};

};  // end namespace

#endif
