/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep16list.H $                        */
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

#ifndef __ISTEPS_ISTEP16LIST_H
#define __ISTEPS_ISTEP16LIST_H

/**
 * @file    istep16list.H
 *
 *  IStep 16    Core Activate
 *  IPL FLow Doc        v0.60 (06/02/15)
 *
 *    16.1    host_activate_master
 *          : Activate master core
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include <initservice/initsvcstructs.H>
#include <initservice/initsvcreasoncodes.H>
#include <iterator>

namespace ISTEP_16
{

/**
 *  @brief   host_activate_boot_core
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void* call_host_activate_boot_core(void *io_pArgs);

/**
 *  @brief   host_activate_secondary_cores
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void* call_host_activate_secondary_cores(void *io_pArgs);

/**
 *  @brief   mss_scrub
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void* call_mss_scrub(void *io_pArgs);

/**
 *  @brief    host_ipl_complete
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void* call_host_ipl_complete(void *io_pArgs);

/**
 *  @brief    host_load_io_ppe
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void* call_host_load_io_ppe(void *io_pArgs);

};

namespace INITSERVICE
{
    const TaskInfo g_istep16[] =
    {
        {
            "",         // dummy, index 0
            nullptr,
            { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
            ISTEPNAME(16,01,"host_activate_boot_core"),
            ISTEP_16::call_host_activate_boot_core,
            { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
        {
            ISTEPNAME(16,02,"host_activate_secondary_cores"),
            ISTEP_16::call_host_activate_secondary_cores,
            { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, true }
        },
        {
            ISTEPNAME(16,03,"host_secure_rng_noop"),
            nullptr,
            { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
            // Hostboot PRD should no longer be called after this step.
            ISTEPNAME(16,04,"mss_scrub"),
            ISTEP_16::call_mss_scrub,
#ifdef CONFIG_NVDIMM
            { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
#else
            { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
#endif
        },
        {
            ISTEPNAME(16,05,"host_ipl_complete"),
            ISTEP_16::call_host_ipl_complete,
            { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
};

const DepModInfo g_istep16Dependancies =
{
    {
        DEP_LIB(libistep16.so),
        DEP_LIB(libnestmemutils.so),
        DEP_LIB(libp9_cpuWkup.so),
        DEP_LIB(libisteps_mss.so),
        DEP_LIB(libpm.so),
        DEP_LIB(libimageprocs.so),
        DEP_LIB(libisteps_nest.so),
        nullptr
    }
};

const ExtTaskInfo g_istep16TaskList =
{
    &(g_istep16[0]),
    std::size(g_istep16),
    &g_istep16Dependancies
};

};  // end namespace

#endif
