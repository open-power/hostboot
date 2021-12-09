/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep18list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#ifndef __ISTEPS_ISTEP18LIST_H
#define __ISTEPS_ISTEP18LIST_H

/**
 * @file    istep18list.H
 *
 *  IStep 18    Establish System SMP
 *  IPL FLow Doc        v0.93 (04/04/16)
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>


namespace   ISTEP_18
{
    void * call_tod_setup(void *dummy);
    void * call_tod_init(void *dummy);
}

namespace   INITSERVICE
{
    const   TaskInfo    g_istep18[]  =   {
        {
                "",         // dummy, index 0
                nullptr,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(18,01,""),
                nullptr,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(18,02,""),
                nullptr,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(18,03,""),
                nullptr,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {

                ISTEPNAME(18,04,""),
                nullptr,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(18,05,""),
                nullptr,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(18,06,""),
                nullptr,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(18,07,""),
                nullptr,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(18,08,""),
                nullptr,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
// To reduce extended image size for VPO, don't run these isteps in VPO
#ifndef CONFIG_VPO_COMPILE
        {
                ISTEPNAME(18,09,"proc_tod_setup"),
                ISTEP_18::call_tod_setup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP|MPIPL_OP, false }
        },

        {
                ISTEPNAME(18,10,"proc_tod_init"),
                ISTEP_18::call_tod_init,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP|MPIPL_OP, false }
        },
#endif
};

const DepModInfo g_istep18Dependancies = {
        {
#ifndef CONFIG_VPO_COMPILE
            DEP_LIB(libtod.so),
            DEP_LIB(libistep18.so),
            DEP_LIB(libfab_iovalid.so),
#endif
            DEP_LIB(libisteps_mss.so),
            nullptr
        }
};

const ExtTaskInfo g_istep18TaskList = {
    &(g_istep18[0]),
    ( sizeof(g_istep18)/sizeof(TaskInfo) ),
    &g_istep18Dependancies
};

};  // end namespace

#endif
