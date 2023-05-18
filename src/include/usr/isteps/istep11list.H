/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep11list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
 *  Step 11 Hostboot OCMB Init
 *  IPL FLow Doc        v0.89.17
 *
 *    11.01    host_prd_hwreconfig
 *           : Hook to handle HW reconfig
 *    11.02    host_set_mem_volt
 *           : Enable voltages on the DDIMMS
 *    11.03    proc_ocmb_enable
 *           : Release reset, start clocks to OCMB
 *    11.04    ocmb_check_for_ready
 *           : Check that OCMB is ready
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
 *  @brief   host_set_mem_volt
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_host_set_mem_volt( void    *io_pArgs );

/**
 *  @brief   proc_ocmb_enable
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_proc_ocmb_enable( void    *io_pArgs );

/**
 *  @brief   ocmb_check_for_ready
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*  call_ocmb_check_for_ready( void    *io_pArgs );


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
                ISTEPNAME(11,02,"host_set_mem_volt"),
                ISTEP_11::call_host_set_mem_volt,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,03,"proc_ocmb_enable"),
                ISTEP_11::call_proc_ocmb_enable,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,04,"ocmb_check_for_ready"),
                ISTEP_11::call_ocmb_check_for_ready,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },

};

const DepModInfo g_istep11Dependancies = {
    {
        DEP_LIB(libistep11.so),
        DEP_LIB(libisteps_mss.so),
        DEP_LIB(libimageprocs.so),
        DEP_LIB(libocmbupd.so),
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
