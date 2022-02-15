/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep09list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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

#ifndef __ISTEPS_ISTEP09LIST_H
#define __ISTEPS_ISTEP09LIST_H

/**
 * @file    istep09list.H
 *
 *  IStep 09    EDI+ and Electrical O-Bus Initialization
 *  IPL FLow Doc        v0.89.17_urmor
 *
 *    09.1    proc_io_dccal_done
 *          : Ensure the IO PPE has finished iodccal
 *    09.2    fabric_dl_pre_trainadv
 *          : Advanced pre training
 *    09.3    fabric_dl_setup_training
 *          : Setup training on internal node buses
 *    09.4    proc_fabric_link_layer
 *          : Start SMP link layer
 *    09.5    fabric_dl_post_trainadv
 *          : Advanced post training
 *    09.6    proc_fabric_iovalid
 *          : Lower functional fences on local SMP
 *    09.7    proc_fbc_eff_config_aggregate
 *          : Pick link(s) for coherency
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file

namespace   ISTEP_09
{

/**
 *  @brief   proc_io_dccal_done
 *
 *           Ensure the IO PPE has finished iodccal
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*    call_proc_io_dccal_done( void    *io_pArgs );



/**
 *  @brief   fabric_dl_pre_trainadv
 *
 *           Advanced pre training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_fabric_dl_pre_trainadv( void    *io_pArgs );



/**
 *  @brief   fabric_dl_setup_training
 *
 *           Setup training on internal node buses
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_fabric_dl_setup_training( void    *io_pArgs );



/**
 *  @brief   proc_fabric_link_layer
 *
 *           Start SMP link layer
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_proc_fabric_link_layer( void    *io_pArgs );



/**
 *  @brief   fabric_dl_post_trainadv
 *
 *           Advanced post EI/EDI training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_fabric_dl_post_trainadv( void    *io_pArgs );



/**
 *  @brief   proc_fabric_iovalid
 *
 *           Lower functional fences on local SMP
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_proc_fabric_iovalid( void    *io_pArgs );



/**
 *  @brief   proc_fbc_eff_config_aggregate
 *
 *           Pick link(s) for coherency
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_proc_fbc_eff_config_aggregate( void    *io_pArgs );

} // end namespace



namespace   INITSERVICE
{
    const   TaskInfo    g_istep09[]  =   {
        {
                "",         // dummy, index 0
                nullptr,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(09,01,"proc_io_dccal_done"),
                ISTEP_09::call_proc_io_dccal_done,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(09,02,"fabric_dl_pre_trainadv"),
                ISTEP_09::call_fabric_dl_pre_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,03,"fabric_dl_setup_training"),
                ISTEP_09::call_fabric_dl_setup_training,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,04,"proc_fabric_link_layer"),
                ISTEP_09::call_proc_fabric_link_layer,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,05,"fabric_dl_post_trainadv"),
                ISTEP_09::call_fabric_dl_post_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,06,"proc_fabric_iovalid"),
                ISTEP_09::call_proc_fabric_iovalid,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(09,07,"proc_fbc_eff_config_aggregate"),
                ISTEP_09::call_proc_fbc_eff_config_aggregate,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
    };

const DepModInfo  g_istep09Dependancies = {
    {
        DEP_LIB(libistep09.so),
        DEP_LIB(libpm.so),
        DEP_LIB(libnestmemutils.so),
        DEP_LIB(libimageprocs.so),
        nullptr
    }
};

const ExtTaskInfo g_istep09TaskList = {
    &(g_istep09[0]),
    ( sizeof(g_istep09)/sizeof(TaskInfo) ),
    &g_istep09Dependancies
};

} // end namespace

#endif
