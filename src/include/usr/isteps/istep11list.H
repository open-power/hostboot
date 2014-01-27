/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep11list.H $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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

namespace   INITSERVICE
{

const   TaskInfo    g_istep11[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(11,01,"mss_getecid"),
                DMI_TRAINING::call_mss_getecid,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,02,"dmi_attr_update"),
                DMI_TRAINING::call_dmi_attr_update,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,03,"proc_dmi_scominit"),
                DMI_TRAINING::call_proc_dmi_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,04,"dmi_scominit"),
                DMI_TRAINING::call_dmi_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,05,"dmi_erepair"),
                DMI_TRAINING::call_dmi_erepair,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,06,"dmi_io_dccal"),
                DMI_TRAINING::call_dmi_io_dccal,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,07,"dmi_pre_trainadv"),
                DMI_TRAINING::call_dmi_pre_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,08,"dmi_io_run_training"),
                DMI_TRAINING::call_dmi_io_run_training,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,09,"dmi_post_trainadv"),
                DMI_TRAINING::call_dmi_post_trainadv,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,10,"proc_cen_framelock"),
                DMI_TRAINING::call_proc_cen_framelock,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,11,"host_startprd_dmi"),
                DMI_TRAINING::call_host_startprd_dmi,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,12,"host_attnlisten_cen"),
                DMI_TRAINING::call_host_attnlisten_cen,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
        {
                ISTEPNAME(11,13,"cen_set_inband_addr"),
                DMI_TRAINING::call_cen_set_inband_addr,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, true }
        },
};

const DepModInfo g_istep11Dependancies = {
    {
        DEP_LIB(libdmi_training.so),
        DEP_LIB(libedi_ei_initialization.so),
        DEP_LIB(libnest_chiplets.so),
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
