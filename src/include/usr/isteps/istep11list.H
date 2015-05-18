/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep11list.H $                        */
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
#ifndef __ISTEPS_ISTEP11LIST_H
#define __ISTEPS_ISTEP11LIST_H

/**
 * list of functions called for DMI Training - ISTEP 11 according to Dean's
 *  IPL Flow Doc        v1.35 (04/11/13)
 *
 * 11.1  mss_getecid
 *       :  Read out ECID orff all Centaurs
 * 11.2  dmi_attr_update
 *       :DMI ATTR update
 * 11.3  proc_dmi_scominit
 *       :  DMI Scom setup on P8 MCS
 * 11.4  dmi_scominit
 *       :  Scom setup on centaur
 * 11.5  dmi_erepair
 *          : Restore EDI Bus eRepair data
 * 11.6  dmi_io_dccal
 *       : Calibrate DMI interfaces
 * 11.7  dmi_pre_trainadv
 *       : Advanced pre DMI training
 * 11.8  dmi_io_run_training
 *       : Run training on MC buses
 * 11.9  dmi_post_trainadv
 *       : Advanced post DMI training
 * 11.10 proc_cen_framelock
 *       : Initialize EDI Frame
 * 11.11 host_startprd_dmi
 *       : Load prd for DMI domain
 * 11.12 host_attnlisten_cen
 *       : Start listening for attentions
 * 11.13 cen_set_inband_addr
 *       : Set the Inband base addresses
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
#include    "../../../usr/hwpf/hwp/dmi_training/dmi_training.H"
#include <config.h>

namespace   INITSERVICE
{

const   TaskInfo    g_istep11[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
};

const DepModInfo g_istep11Dependancies = {
    {
#ifndef CONFIG_VPO_COMPILE
        DEP_LIB(libdmi_training.so),
        DEP_LIB(libedi_ei_initialization.so),
        DEP_LIB(libnest_chiplets.so),
        DEP_LIB(libsecure_boot.so),
        DEP_LIB(libslave_sbe.so),
#endif
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
