/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep15list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
#ifndef __ISTEPS_ISTEP15LIST_H
#define __ISTEPS_ISTEP15LIST_H

/**
 * @file    istep15list.H
 *
 *  IStep 15    Build Winkle Images
 *  IPL FLow Doc        v1.28 (12/03/12)
 *
 *    15.1    host_build_winkle
 *          : Build runtime winkle images
 *    15.2    proc_set_pore_bar
 *          : Tell SLW Eng where winkle image is
 *    15.3    proc_poreslw_init
 *          : Initialize the PORE-SLW engine
 *
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/build_winkle_images/build_winkle_images.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep15[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(15,01,"host_build_winkle"),
                BUILD_WINKLE_IMAGES::call_host_build_winkle,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, true }
        },
        {
                ISTEPNAME(15,02,"proc_set_pore_bar"),
                BUILD_WINKLE_IMAGES::call_proc_set_pore_bar,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, true }
        },
        {
                ISTEPNAME(15,03,"p8_poreslw_init"),
                BUILD_WINKLE_IMAGES::call_p8_poreslw_init,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, true }
        },
};


const DepModInfo g_istep15Dependancies = {
    {
        DEP_LIB(libocc.so),
        DEP_LIB(libbuild_winkle_images.so),
        NULL
    }
};

const ExtTaskInfo g_istep15TaskList = {
    &(g_istep15[0]),
    ( sizeof(g_istep15)/sizeof(TaskInfo) ),
    &g_istep15Dependancies
};

};  // end namespace

#endif
