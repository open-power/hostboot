/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep09list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
 *  IPL FLow Doc        v0.60 (06/02/15)
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
 *    09.7    host_startprd_pbus
 *          : Load PRD for powerbus domain
 *    09.9    proc_fab_iovalid
 *          : Lower functional fences on local SMP
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include "../../../usr/hwpf/hwp/edi_ei_initialization/edi_ei_initialization.H"
#include <config.h>

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
                EDI_EI_INITIALIZATION::call_fabric_erepair,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,02,"fabric_io_dccal"),
                EDI_EI_INITIALIZATION::call_fabric_io_dccal,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,03,"fabric_pre_trainadv"),
                EDI_EI_INITIALIZATION::call_fabric_pre_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,04,"fabric_io_run_training"),
                EDI_EI_INITIALIZATION::call_fabric_io_run_training,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,05,"fabric_post_trainadv"),
                EDI_EI_INITIALIZATION::call_fabric_post_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,06,"proc_smp_link_layer"),
                EDI_EI_INITIALIZATION::call_proc_smp_link_layer,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,07,"host_startprd_pbus"),
                EDI_EI_INITIALIZATION::call_host_startprd_pbus,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,08,"host_attnlisten_proc"),
                EDI_EI_INITIALIZATION::call_host_attnlisten_proc,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(09,09,"proc_fab_iovalid"),
                EDI_EI_INITIALIZATION::call_proc_fab_iovalid,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
};

const DepModInfo  g_istep09Dependancies = {
    {
        DEP_LIB(libedi_ei_initialization.so),
        DEP_LIB(libsbe.so),
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
