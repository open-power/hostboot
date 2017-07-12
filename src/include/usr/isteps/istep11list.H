/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep11list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
#ifndef __ISTEPS_ISTEP11LIST_H
#define __ISTEPS_ISTEP11LIST_H

/**
 *  Step 11 Hostboot Centaur Init  
 *  IPL FLow Doc        v1.07
 *
 *    11.01    host_prd_hwreconfig
 *           : Hook to handle HW reconfig 
 *    11.02    cen_tp_chiplet_init1
 *           : Centaur TP chiplet init, stage #1
 *    11.03    cen_pll_initf
 *           : Program Nest PLL
 *    11.04    cen_pll_setup
 *           : Setup Nest PLL
 *    11.05    cen_tp_chiplet_init2	
 *           : Centaur TP chiplet init, stage #2
 *    11.06    cen_tp_arrayinit
 *           : Centaur TP chiplet array init
 *    11.07    cen_tp_chiplet_init3
 *           : Centaur TP chiplet init, stage #3
 *    11.08    cen_chiplet_init
 *           : Centaur chiplet init
 *    11.09    cen_arrayinit
 *           : Centaur chiplet array init
 *    11.10    cen_initf
 *           : Centaur Scan overrides
 *    11.11    cen_do_manual_inits
 *           : Manual Centaur Scans
 *    11.12    cen_startclocks
 *           : Start Centaur Nest/MEM clocks
 *    11.13    cen_scominits
 *           : Perform Centaur SCOM inits
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

/**
 * @file    istep11list.H
 *
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include <config.h>

namespace   ISTEP_11
{

/**
 *  @brief   host_prd_hwreconfig
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_host_prd_hwreconfig( void    *io_pArgs );

/**
 *  @brief   cen_tp_chiplet_init1
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_tp_chiplet_init1( void    *io_pArgs );

/**
 *  @brief   cen_pll_initf
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_pll_initf( void    *io_pArgs );

/**
 *  @brief   cen_pll_setup
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_pll_setup( void    *io_pArgs );

/**
 *  @brief   cen_tp_chiplet_init2
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_tp_chiplet_init2( void    *io_pArgs );

/**
 *  @brief   cen_tp_arrayinit
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_tp_arrayinit( void    *io_pArgs );

/**
 *  @brief   cen_tp_chiplet_init3
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_tp_chiplet_init3( void    *io_pArgs );

/**
 *  @brief   cen_chiplet_init
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_chiplet_init( void    *io_pArgs );

/**
 *  @brief   cen_arrayinit
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_arrayinit( void    *io_pArgs );

/**
 *  @brief   cen_initf
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_initf( void    *io_pArgs );

/**
 *  @brief   cen_do_manual_inits
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_do_manual_inits( void    *io_pArgs );

/**
 *  @brief   cen_startclocks
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_startclocks( void    *io_pArgs );

/**
 *  @brief   cen_scominits
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*  call_cen_scominits( void    *io_pArgs );


};


namespace   INITSERVICE
{

const   TaskInfo    g_istep11[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(11,01,"host_prd_hwreconfig"),
                ISTEP_11::call_host_prd_hwreconfig,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,02,"cen_tp_chiplet_init1"),
                ISTEP_11::call_cen_tp_chiplet_init1,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,03,"cen_pll_initf"),
                ISTEP_11::call_cen_pll_initf,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,04,"cen_pll_setup"),
                ISTEP_11::call_cen_pll_setup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,05,"cen_tp_chiplet_init2"),
                ISTEP_11::call_cen_tp_chiplet_init2,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,06,"cen_tp_arrayinit"),
                ISTEP_11::call_cen_tp_arrayinit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,07,"cen_tp_chiplet_init3"),
                ISTEP_11::call_cen_tp_chiplet_init3,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,08,"cen_chiplet_init"),
                ISTEP_11::call_cen_chiplet_init,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,09,"cen_arrayinit"),
                ISTEP_11::call_cen_arrayinit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,10,"cen_initf"),
                ISTEP_11::call_cen_initf,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,11,"cen_do_manual_inits"),
                ISTEP_11::call_cen_do_manual_inits,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,12,"cen_startclocks"),
                ISTEP_11::call_cen_startclocks,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,13,"cen_scominits"),
                ISTEP_11::call_cen_scominits,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },

};

const DepModInfo g_istep11Dependancies = {
    {
        DEP_LIB(libistep11.so),
        NULL
    }
};

const ExtTaskInfo g_istep11TaskList = {
    &(g_istep11[0]),
    ( sizeof(g_istep11)/sizeof(TaskInfo) ),
    &g_istep11Dependancies
};

};  // end namespace

#endif
