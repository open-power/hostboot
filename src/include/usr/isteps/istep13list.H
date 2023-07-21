/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep13list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
 *  P10 IPL FLow Doc        v0.90.01
 *
 *  13.1  mss_scominit
 *      : Perform scom inits to MC and PHY
 *  13.2 mss_draminit
 *      : Dram initialize
 *  13.3 mss_draminit_mc
 *      : Hand off control to MC
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file

namespace   ISTEP_13
{
/**
 *  @brief   mss_scominit
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mss_scominit( void    *io_pArgs );

/**
 *  @brief   mss_draminit
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mss_draminit( void    *io_pArgs );


/**
 *  @brief   mss_draminit_mc
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mss_draminit_mc( void    *io_pArgs );


};


namespace   INITSERVICE
{
const   TaskInfo    g_istep13[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(13,01,"mss_scominit"),
                ISTEP_13::call_mss_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,02,"mss_draminit"),
                ISTEP_13::call_mss_draminit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
                // true covers part b) checking for attentions as memory attentions rollup to processors
        },
        {
                ISTEPNAME(13,03,"mss_draminit_mc"),
                ISTEP_13::call_mss_draminit_mc,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
};

const DepModInfo g_istep13Dependancies = {
    {
        DEP_LIB(libocmbupd.so),
        DEP_LIB(libisteps_mss.so),
        DEP_LIB(libistep13.so),
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
