/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep15list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2019                        */
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
 *  IStep 15    Build STOP Images
 *  P10 IPL FLow Doc        v0.89.12
 *
 *    15.1    host_build_stop_image
 *          : Build runtime STOP images
 *    15.2    proc_set_homer_bar
 *          : Set HOMER location in OCC and QME
 *    15.3    host_establish_ec_chiplet
 *          : Update multicast on ECs for runtime state
 *    15.4    host_start_stop_engine
 *          : Initialize QME engine
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include <initservice/initsvcstructs.H>
#include <initservice/initsvcreasoncodes.H>
namespace   ISTEP_15
{


/**
 *  @brief   proc_set_homer_bar
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    proc_set_homer_bar( void    *io_pArgs );


/**
 *  @brief   host_build_stop_image
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  host_build_stop_image( void    *io_pArgs );



/**
 *  @brief   host_start_stop_engine
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    host_start_stop_engine( void    *io_pArgs );



/**
 *  @brief   host_establish_ec_chiplet
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    host_establish_ec_chiplet( void    *io_pArgs );

};


namespace   INITSERVICE
{
    const   TaskInfo    g_istep15[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(15,01,"host_build_stop_image"),
                ISTEP_15::host_build_stop_image,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, true }
        },
        {
                ISTEPNAME(15,02,"proc_set_homer_bar"),
                ISTEP_15::proc_set_homer_bar,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, true }
        },
        {
                ISTEPNAME(15,03,"host_establish_ec_chiplet"),
                ISTEP_15::host_establish_ec_chiplet,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
        {
                ISTEPNAME(15,04,"host_start_stop_engine"),
                ISTEP_15::host_start_stop_engine,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
};


const DepModInfo g_istep15Dependancies = {
    {
        DEP_LIB(libistep15.so),
        DEP_LIB(libpm.so),
        DEP_LIB(libimageprocs.so),
        nullptr
    }
};

const ExtTaskInfo g_istep15TaskList = {
    &(g_istep15[0]),
    ( sizeof(g_istep15)/sizeof(TaskInfo) ),
    &g_istep15Dependancies
};

};  // end namespace

#endif
