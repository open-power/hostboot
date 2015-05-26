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
 *  IStep 14
 *  IPL FLow Doc        v0.60 (06/02/15)
 *    14.7    proc_setup_bars
 *          : Setup Memory BARs
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
        {
                ISTEPNAME(14,07,"proc_setup_bars"),
                DRAM_INITIALIZATION::call_proc_setup_bars,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
    };

const DepModInfo g_istep14Dependancies = {
    {
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
