/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep08list.H $                        */
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
#ifndef __ISTEPS_ISTEP08LIST_H
#define __ISTEPS_ISTEP08LIST_H

/**
 * @file    istep08list.H
 *
 *  IStep 08    EDI, EI Initialization
 *  IPL FLow Doc        v1.28 (12/03/12)
 *
 *    08.1    fabric_erepair
 *          : Restore Fabric/EDI Bus eRepair data
 *    08.2    fabric_io_dccal
 *          : Calibrate Fabric/EDI interfaces
 *    08.3    fabric_pre_trainadv
 *          : Advanced pre EI/EDI training
 *    08.4    fabric_io_run_training
 *          : Run training on internal buses
 *    08.5    fabric_post_trainadv
 *          : Advanced post EI/EDI training
 *    08.6    host_startprd_pbus
 *          : Load prd for powerbus domain
 *    08.7    host_attnlisten_proc
 *          : Start listening for attentions
 *    08.8    proc_fab_iovalid
 *          : Lower functional fences on local SMP
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1606
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/edi_ei_initialization/edi_ei_initialization.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep08[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(08,01,"fabric_erepair"),
                EDI_EI_INITIALIZATION::call_fabric_erepair,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,02,"fabric_io_dccal"),
                EDI_EI_INITIALIZATION::call_fabric_io_dccal,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,03,"fabric_pre_trainadv"),
                EDI_EI_INITIALIZATION::call_fabric_pre_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,04,"fabric_io_run_training"),
                EDI_EI_INITIALIZATION::call_fabric_io_run_training,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,05,"fabric_post_trainadv"),
                EDI_EI_INITIALIZATION::call_fabric_post_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,06,"host_startprd_pbus"),
                EDI_EI_INITIALIZATION::call_host_startprd_pbus,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,07,"host_attnlisten_proc"),
                EDI_EI_INITIALIZATION::call_host_attnlisten_proc,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,08,"proc_fab_iovalid"),
                EDI_EI_INITIALIZATION::call_proc_fab_iovalid,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
};

const DepModInfo g_istep08Dependancies = {
    {
        DEP_LIB(libedi_ei_initialization.so),
        DEP_LIB(libdmi_training.so),
        DEP_LIB(libnest_chiplets.so),
        DEP_LIB(libsecure_boot.so),
        NULL
    }
};

const ExtTaskInfo g_istep08TaskList = {
    &(g_istep08[0]),
    ( sizeof(g_istep08)/sizeof(TaskInfo) ),
    &g_istep08Dependancies
};

};  // end namespace

#endif
