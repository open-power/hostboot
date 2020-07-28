/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep10list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
 *  Step 10 Hostboot Activate Power Bus
 *
 *    10.01    proc_build_smp
 *           : Integrate P10 Islands into SMP
 *    10.02    host_sbe_update
 *           : Update SBE
 *    10.03    host_secureboot_lockdown
 *           :
 *    10.04    proc_chiplet_scominit
 *           : Scom inits to all chiplets (sans quad/fabric)
 *    10.05    proc_pau_scominit
 *           : Scom inits for the PAU unit
 *    10.06    proc_pcie_scominit
 *           : Apply scom inits to PCIe Chiplets
 *    10.07    proc_scomoverride_chiplets
 *           : Apply sequenced scom inits
 *    10.08    proc_chiplet_enable_ridi
 *           : Enable RI/DI chip wide
 *    10.09    call_host_rng_bist
 *           : Trigger Built In Self Test for RNG
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file

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
 *  @brief   host_sbe_update
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_host_sbe_update( void    *io_pArgs );

/**
 *  @brief   call_host_secureboot_lockdown
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_host_secureboot_lockdown( void    *io_pArgs );

/**
 *  @brief proc_pau_scominit
 *
 *    Apply scom inits to PAU
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_proc_pau_scominit(void *io_pArgs);

/**
 *  @brief  proc_chiplet_scominit
 *
 *     Apply scom inits to chiplets
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_chiplet_scominit( void    *io_pArgs );

/**
 *  @brief   proc_pcie_scominit
 *
 *           Apply scom inits to PCIe chiplets
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_pcie_scominit( void    *io_pArgs );

/**
 *  @brief   proc_scomoverride_chiplets
 *
 *           Apply sequenced scom inits
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_scomoverride_chiplets( void    *io_pArgs );

/**
 *  @brief   proc_chiplet_enable_ridi
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_chiplet_enable_ridi( void    *io_pArgs );

/**
 *  @brief   call_host_rng_bist
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_host_rng_bist( void    *io_pArgs );

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
                ISTEPNAME(10,02,"host_sbe_update"),
                ISTEP_10::call_host_sbe_update,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(10,03,"host_secureboot_lockdown"),
                ISTEP_10::call_host_secureboot_lockdown,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, true }
        },
        {
                ISTEPNAME(10,04,"proc_chiplet_scominit"),
                ISTEP_10::call_proc_chiplet_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(10,05,"proc_pau_scominit"),
                ISTEP_10::call_proc_pau_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(10,06,"proc_pcie_scominit"),
                ISTEP_10::call_proc_pcie_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(10,07,"proc_scomoverride_chiplets"),
                ISTEP_10::call_proc_scomoverride_chiplets,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(10,08,"proc_chiplet_enable_ridi"),
                ISTEP_10::call_proc_chiplet_enable_ridi,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(10,09,"host_rng_bist"),
                ISTEP_10::call_host_rng_bist,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
};

const DepModInfo g_istep10Dependancies = {
    {
        DEP_LIB(libistep10.so),
        DEP_LIB(libisteps_nest.so),
        DEP_LIB(libisteps_mss.so),
        DEP_LIB(libsbe.so),
        DEP_LIB(libnestmemutils.so),
        DEP_LIB(libimageprocs.so),
#ifdef CONFIG_SECUREBOOT
        DEP_LIB(libsecureboot_ext.so),
#endif
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
