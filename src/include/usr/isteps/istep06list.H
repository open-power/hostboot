/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep06list.H $                        */
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
#ifndef __ISTEPS_ISTEP6LIST_H
#define __ISTEPS_ISTEP6LIST_H

/**
 * @file    istep06list.H
 *
 * @note    IStep definition for Hostboot - Secondary SBE
 *
 *  IStep 06    Secondary SBE
 *  IPL FLow Doc        v0.98
 *
 *  06.1    host_bootloader
 *        : Host Bootloader (non-executable istep)
 *  06.2    host_setup
 *        : Setup host environment (non-executable istep)
 *  06.3    host_istep_enable
 *        : Hostboot istep ready (non-executable istep)
 *  06.4    host_init_fsi
 *        : Setup the FSI links to slave chips
 *  06.5    host_set_ipl_parms
 *        : Build ipl parameters
 *  06.6    host_discover_targets
 *        : Builds targeting
 *  06.7    host_update_primary_tpm
 *        : Update primary TPM
 *  06.8    host_gard
 *        : Do Gard
 *  06.9    host_voltage_config
 *        : Calculate correct chip voltage
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

namespace ISTEP_06
{

/**
 * @brief   host_init_fsi   Setup the FSI links to secondary chips (istep 6.5)
 *
 *  Call into the hwas platform-specific initHardware() function
 *  to init the FSI hardware.
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_init_fsi( void *io_pArgs );

/**
 * @brief   host_set_ipl_parms  Build ipl parameters (istep 6.6)
 *
 *  TBD
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_set_ipl_parms( void *io_pArgs );

/**
 * @brief   host_discover_targets   Builds targeting (istep 6.7)
 *
 *  This routine will walk through all the targets and initialize HWAS STATE
 *  to a known default value.
 *
 *  Currently everything is initialized to powered off, etc.
 *
 *  Call into the hwas platform-specific presenceDetect() function to
 *  read the hardware information, and apply it to the target states.
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_discover_targets( void *io_pArgs );

/**
 * @brief   call_host_update_primary_tpm (istep 6.8)
 *
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* call_host_update_primary_tpm( void *io_pArgs );

/**
 * @brief   host_gard   Do Gard (istep 6.9)
 *
 * Collect GARD information and apply it to the target states.
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_gard( void *io_pArgs );

/**
 * host_revert_sbe_mcs_setup (istep 6.10)
 *    Moved to istep14 call_proc_setup_bars.C
 */

/**
 * @brief   host_voltage_config (istep 6.11)
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* call_host_voltage_config (void * io_pArgs);

};


namespace   INITSERVICE
{

const   TaskInfo    g_istep06[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(06,01,""),        // not used. host bootloader
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(06,02,""),        // not used. host setup
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(06,03,""),        // not used. host istep enable
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(06,04,"host_init_fsi"),
                ISTEP_06::host_init_fsi,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false,
                        BASE_INITIALIZATION }
        },
        {
                ISTEPNAME(06,05,"host_set_ipl_parms"),
                ISTEP_06::host_set_ipl_parms,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
        {
                ISTEPNAME(06,06,"host_discover_targets"),
                ISTEP_06::host_discover_targets,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
        {
                ISTEPNAME(06,07,"host_update_primary_tpm"),
                ISTEP_06::call_host_update_primary_tpm,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
        {
                ISTEPNAME(06,08, "host_gard"),
                ISTEP_06::host_gard,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
        {
                ISTEPNAME(06,09,"host_voltage_config"),
                ISTEP_06::call_host_voltage_config,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },

};

const DepModInfo  g_istep06Dependancies = {
    {
      DEP_LIB(libistep06.so),
      DEP_LIB(libsbe.so),
      DEP_LIB(libpm.so),
#ifndef CONFIG_VPO_COMPILE
      DEP_LIB(libnestmemutils.so),
      DEP_LIB(libisteps_nest.so),
#endif
      DEP_LIB(libimageprocs.so),
      DEP_LIB(libp9_cpuWkup.so),
      DEP_LIB(libruntime.so),
#ifdef CONFIG_SECUREBOOT
      DEP_LIB(libsecureboot_ext.so),
#endif
      NULL
    }
};

const ExtTaskInfo g_istep06TaskList = {
    &(g_istep06[0]),
    ( sizeof(g_istep06)/sizeof(TaskInfo) ),
    &(g_istep06Dependancies),
};

};  // end namespace

#endif
