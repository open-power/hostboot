/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep20list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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

#ifndef __ISTEPS_ISTEP20LIST_H
#define __ISTEPS_ISTEP20LIST_H

/**
 * @file    istep20list.H
 *
 *  IStep 20    Loading Payload
 *
 *    20.1    host_load_payload
 *          :  Load Payload
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>
#include    <config.h>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/load_payload/load_payload.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep20[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },

// To reduce extended image size for VPO, don't run these isteps in VPO
#ifndef CONFIG_VPO_COMPILE
        {
                ISTEPNAME(20,01,"host_load_payload"),
                LOAD_PAYLOAD::call_host_load_payload,
                { START_FN, EXT_IMAGE, MPIPL_OP | NORMAL_IPL_OP, false }
        },
#endif

};

const DepModInfo  g_istep20Dependancies = {
    {
        DEP_LIB(libload_payload.so),
        DEP_LIB(libxz.so),
        NULL
    }
};

const ExtTaskInfo g_istep20TaskList = {
    &(g_istep20[0]),
    ( sizeof(g_istep20)/sizeof(TaskInfo) ),
    &g_istep20Dependancies
};

};  // end namespace

#endif
