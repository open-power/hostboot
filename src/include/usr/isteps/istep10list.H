/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep10list.H $                        */
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
#ifndef __ISTEPS_ISTEP10LIST_H
#define __ISTEPS_ISTEP10LIST_H


/**
 * @file    istep10list.H
 *
 *  Step 10 Hostboot SBE Centaur Init
 *  IPL FLow Doc        v0.67 (11/12/15)
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include <config.h>

namespace   ISTEP_10
{

/**
 *  @brief   proc_build_smp
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*    call_proc_build_smp( void    *io_pArgs );



/**
 *  @brief   host_slave_sbe_update
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_host_slave_sbe_update( void    *io_pArgs );



/**
 *  @brief   host update redundant tpm
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_host_update_redundant_tpm( void    *io_pArgs );

};


namespace   INITSERVICE
{

const   TaskInfo    g_istep10[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(10,01,"proc_build_smp"),
                ISTEP_10::call_proc_build_smp,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(10,02,"host_slave_sbe_update"),
                ISTEP_10::call_host_slave_sbe_update,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(10,03,"host_update_redundant_tpm"),
                ISTEP_10::call_host_update_redundant_tpm,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
};

const DepModInfo g_istep10Dependancies = {
    {
        DEP_LIB(libistep10.so),
        NULL
    }
};

const ExtTaskInfo g_istep10TaskList = {
    &(g_istep10[0]),
    ( sizeof(g_istep10)/sizeof(TaskInfo) ),
    &g_istep10Dependancies
};

};  // end namespace

#endif
