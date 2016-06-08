/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep09list.H $                        */
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

#ifndef __ISTEPS_ISTEP09LIST_H
#define __ISTEPS_ISTEP09LIST_H

/**
 * @file    istep09list.H
 *
 *  IStep 09    Activate PowerBus
 *  IPL FLow Doc        v0.95
 *
 *    09.1    fabric_erepair
 *          : Restore Fabric Bus eRepair data
 *    09.2    fabric_io_dccal
 *          : Calibrate Fabric interfaces
 *    09.3    fabric_pre_trainadv
 *          : Advanced pre training
 *    09.4    fabric_io_run_training
 *          : Run training on internal buses
 *    09.5    fabric_post_trainadv
 *          : Advanced post EI/EDI training
 *    09.6    proc_smp_link_layer
 *          : Start SMP link layer
 *    09.7    proc_fab_iovalid
 *          : Lower functional fences on local SMP
 *    09.8    host_fbc_eff_config_aggregate
 *          : Pick link(s) for coherency
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include <config.h>

namespace   ISTEP_09
{

/**
 *  @brief   fabric_erepair
 *
 *           Restore Fabric/EDI Bus eRepair data
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep
 *
 */
void*    call_fabric_erepair( void    *io_pArgs );



/**
 *  @brief   fabric_io_dccal
 *
 *           Calibrate Fabric/EDI interfaces
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_fabric_io_dccal( void    *io_pArgs );



/**
 *  @brief   fabric_pre_trainadv
 *
 *  08.3 : : Advanced pre EI/EDI training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_fabric_pre_trainadv( void    *io_pArgs );



/**
 *  @brief   fabric_io_run_training
 *
 *           Run training on internal buses
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_fabric_io_run_training( void    *io_pArgs );



/**
 *  @brief   fabric_post_trainadv
 *
 *           Advanced post EI/EDI training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_fabric_post_trainadv( void    *io_pArgs );



/**
 *  @brief   proc_smp_link_layer
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*   call_proc_smp_link_layer( void    *io_pArgs );



/**
 *  @brief   proc_fab_iovalid
 *
 *           Lower functional fences on local SMP
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_proc_fab_iovalid( void    *io_pArgs );



/**
 *  @brief   host_fbc_eff_config_aggregate
 *
 *           Aggregate the FBC configuration
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep
 *
 */
void*    call_host_fbc_eff_config_aggregate( void    *io_pArgs );

};   // end namespace



namespace   INITSERVICE
{
    const   TaskInfo    g_istep09[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(09,01,"fabric_erepair"),
                ISTEP_09::call_fabric_erepair,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,02,"fabric_io_dccal"),
                ISTEP_09::call_fabric_io_dccal,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,03,"fabric_pre_trainadv"),
                ISTEP_09::call_fabric_pre_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,04,"fabric_io_run_training"),
                ISTEP_09::call_fabric_io_run_training,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,05,"fabric_post_trainadv"),
                ISTEP_09::call_fabric_post_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,06,"proc_smp_link_layer"),
                ISTEP_09::call_proc_smp_link_layer,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,07,"proc_fab_iovalid"),
                ISTEP_09::call_proc_fab_iovalid,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(09,08,"host_fbc_eff_config_aggregate"),
                ISTEP_09::call_host_fbc_eff_config_aggregate,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
    };

const DepModInfo  g_istep09Dependancies = {
    {
        DEP_LIB(libistep09.so),
        NULL
    }
};

const ExtTaskInfo g_istep09TaskList = {
    &(g_istep09[0]),
    ( sizeof(g_istep09)/sizeof(TaskInfo) ),
    &g_istep09Dependancies
};

};  // end namespace

#endif
