/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep07list.H $                        */
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
#ifndef __ISTEPS_ISTEP07LIST_H
#define __ISTEPS_ISTEP07LIST_H

/**
 * @file    istep07list.H
 *
 *  IStep 07    Nest Chiplets
 *  IPL FLow Doc        v0.95 (04/04/16)
 *
 *    07.1    host_mss_attr_cleanup
 *          : (placeholder)
 *    07.2    mss_volt
 *          : Calc dimm voltage
 *    07.3    mss_freq
 *          : Calc dimm frequency
 *    07.4    mss_eff_config
 *          : Determine effective config
 *    07.5    mss_attr_update
 *          : MSS ATTR update
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>


namespace   ISTEP_07
{

/**
 *  @brief   host_mss_attr_cleanup
 *
 *            Build the Attibute for the DIMMs to be consummed in later steps
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*   host_mss_attr_cleanup( void * io_pArgs );

/**
 *  @brief   mss_volt
 *
 *            Calc dimm voltage
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*   call_mss_volt( void * io_pArgs );



/**
 *  @brief   mss_freq
 *
 *           Calc dimm frequency
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_freq( void * io_pArgs );



/**
 *  @brief   mss_eff_config
 *
 *           Determine effective config
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_eff_config( void * io_pArgs );

/**
 *  @brief   mss_attr_update
 *
 *  Stub HWP to allow FW to override attributes programmatically
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_attr_update( void *io_pArgs );

};   // end namespace




namespace   INITSERVICE
{
    const   TaskInfo    g_istep07[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(07,01,"mss_attr_cleanup"),
                ISTEP_07::host_mss_attr_cleanup,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(07,02,"mss_volt"),
                ISTEP_07::call_mss_volt,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(07,03,"mss_freq"),
                ISTEP_07::call_mss_freq,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(07,04,"mss_eff_config"),
                ISTEP_07::call_mss_eff_config,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(07,05,"mss_attr_update"),
                ISTEP_07::call_mss_attr_update,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
};


const DepModInfo g_istep07Dependancies = {
    {
        DEP_LIB(libnestmemutils.so),
        DEP_LIB(libisteps_mss.so),
        DEP_LIB(libsbe.so),
        DEP_LIB(libimageprocs.so),
        DEP_LIB(libcen.so),
#ifndef CONFIG_FSP_BUILD
        DEP_LIB(libnvram.so),
#endif
        DEP_LIB(libistep07.so),
        NULL
    }
};

const ExtTaskInfo g_istep07TaskList = {
    &(g_istep07[0]),
    ( sizeof(g_istep07)/sizeof(TaskInfo) ),
    &g_istep07Dependancies
};

};  // end namespace

#endif
