/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep13list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
 *  IStep 13    Step 13
 *  IPL FLow Doc        v0.95
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include <config.h>

namespace   ISTEP_13
{

/**
 *  @brief   host_disable_memvolt
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_host_disable_memvolt( void    *io_pArgs );



/**
 *  @brief   mem_pll_reset
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mem_pll_reset( void    *io_pArgs );



/**
 *  @brief   mem_pll_initf
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mem_pll_initf( void    *io_pArgs );



/**
 *  @brief   mem_pll_setup
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mem_pll_setup( void    *io_pArgs );


/**
 *  @brief   mem_startclocks
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mem_startclocks( void    *io_pArgs );

/**
 *  @brief   host_enable_memvolt
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_host_enable_memvolt( void    *io_pArgs );

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
 *  @brief   mss_ddr_phy_reset
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mss_ddr_phy_reset( void    *io_pArgs );

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
 *  @brief   mss_draminit_training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mss_draminit_training( void    *io_pArgs );

/**
 *  @brief   mss_draminit_trainadv
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mss_draminit_trainadv( void    *io_pArgs );

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
                ISTEPNAME(13,01,"host_disable_memvolt"),
                ISTEP_13::call_host_disable_memvolt,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,02,"mem_pll_reset"),
                ISTEP_13::call_mem_pll_reset,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,03,"mem_pll_initf"),
                ISTEP_13::call_mem_pll_initf,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,04,"mem_pll_setup"),
                ISTEP_13::call_mem_pll_setup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,05,"proc_mcs_skewadjust"),
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(13,06,"mem_startclocks"),
                ISTEP_13::call_mem_startclocks,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,07,"host_enable_memvolt"),
                ISTEP_13::call_host_enable_memvolt,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,08,"mss_scominit"),
                ISTEP_13::call_mss_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,09,"mss_ddr_phy_reset"),
                ISTEP_13::call_mss_ddr_phy_reset,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,10,"mss_draminit"),
                ISTEP_13::call_mss_draminit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,11,"mss_draminit_training"),
                ISTEP_13::call_mss_draminit_training,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,12,"mss_draminit_trainadv"),
                ISTEP_13::call_mss_draminit_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(13,13,"mss_draminit_mc"),
                ISTEP_13::call_mss_draminit_mc,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
};

const DepModInfo g_istep13Dependancies = {
    {
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
