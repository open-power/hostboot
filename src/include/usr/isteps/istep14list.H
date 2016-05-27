/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep14list.H $                        */
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
#ifndef __ISTEPS_ISTEP14LIST_H
#define __ISTEPS_ISTEP14LIST_H

/**
 * @file    istep14list.H
 *
 *  IStep 14
 *  IPL FLow Doc        v0.95
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include <initservice/initsvcstructs.H>
#include <initservice/initsvcreasoncodes.H>
#include <config.h>

namespace   ISTEP_14
{


/**
 *  @brief   mss_memdiag
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mss_memdiag( void    *io_pArgs );

/**
 *  @brief   mss_thermal_init
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mss_thermal_init( void    *io_pArgs );

/**
 *  @brief   proc_pcie_config
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_proc_pcie_config( void    *io_pArgs );

/**
 *  @brief   mss_power_cleanup
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_mss_power_cleanup( void    *io_pArgs );

/**
 *  @brief   proc_setup_bars
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_proc_setup_bars( void    *io_pArgs );

/**
 *  @brief   proc_htm_setup
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_proc_htm_setup( void    *io_pArgs );

/**
 *  @brief   proc_exit_cache_contained
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_proc_exit_cache_contained( void    *io_pArgs );

/**
 *  @brief   host_mpipl_service
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_host_mpipl_service( void    *io_pArgs );
};


namespace   INITSERVICE
{
    const   TaskInfo    g_istep14[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(14,01,"mss_memdiag"),
                ISTEP_14::call_mss_memdiag,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,02,"mss_thermal_init"),
                ISTEP_14::call_mss_thermal_init,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,03,"proc_pcie_config"),
                ISTEP_14::call_proc_pcie_config,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,04,"mss_power_cleanup"),
                ISTEP_14::call_mss_power_cleanup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,05,"proc_setup_bars"),
                ISTEP_14::call_proc_setup_bars,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,06,"proc_htm_setup"),
                ISTEP_14::call_proc_htm_setup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,07,"proc_exit_cache_contained"),
                ISTEP_14::call_proc_exit_cache_contained,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(14,08,"host_mpipl_service"),
                ISTEP_14::call_host_mpipl_service,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
    };

const DepModInfo g_istep14Dependancies = {
    {
        DEP_LIB(libistep14.so),
        DEP_LIB(libdump.so),
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
