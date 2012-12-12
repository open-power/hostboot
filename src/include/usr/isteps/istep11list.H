/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep11list.H $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
 *  IPL Flow Doc        v1.28 (12/03/12)
 *
 * 11.1  mss_getecid
 *       :  Read out ECID orff all Centaurs
 * 11.2  proc_dmi_scominit
 *       :  DMI Scom setup on P8 MCS
 * 11.3  dmi_scominit
 *       :  Scom setup on centaur
 * 11.4  dmi_erepair
 *          : Restore EDI Bus eRepair data
 * 11.5  dmi_io_dccal
 *       : Calibrate DMI interfaces
 * 11.6  dmi_pre_trainadv
 *       : Advanced pre DMI training
 * 11.7  dmi_io_run_training
 *       : Run training on MC buses
 * 11.8  dmi_post_trainadv
 *       : Advanced post DMI training
 * 11.9  proc_cen_framelock
 *       : Initialize EDI Frame
 * 11.10 host_startprd_dmi
 *       : Load prd for DMI domain
 * 11.11 host_attnlisten_cen
 *       : Start listening for attentions
 * 11.12 cen_set_inband_addr
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
                {
                        NONE,
                        EXT_IMAGE,
                        IPL_NOOP,
                        false,                              // true = check for attentions
                }
        },
        {
                ISTEPNAME(11,01,"mss_getecid"),             // substep name
                DMI_TRAINING::call_mss_getecid,             // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(11,02,"proc_dmi_scominit"),       // substep name
                DMI_TRAINING::call_proc_dmi_scominit,       // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },

        {
                ISTEPNAME(11,03,"dmi_scominit"),             // substep name
                DMI_TRAINING::call_dmi_scominit,             // pointer to fn
                {
                        START_FN,                            // task type
                        EXT_IMAGE,                           // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },

        {
                ISTEPNAME(11,04,"dmi_erepair"),              // substep name
                DMI_TRAINING::call_dmi_erepair,              // pointer to fn
                {
                        START_FN,                            // task type
                        EXT_IMAGE,                           // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(11,05,"dmi_io_dccal"),             // substep name
                DMI_TRAINING::call_dmi_io_dccal,            // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(11,06,"dmi_pre_trainadv"),        // substep name
                DMI_TRAINING::call_dmi_pre_trainadv,        // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(11,07,"dmi_io_run_training"),      // substep name
                DMI_TRAINING::call_dmi_io_run_training,     // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(11,08,"dmi_post_trainadv"),       // substep name
                DMI_TRAINING::call_dmi_post_trainadv,       // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(11,09,"proc_cen_framelock"),       // substep name
                DMI_TRAINING::call_proc_cen_framelock,      // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(11,10,"host_startprd_dmi"),        // substep name
                DMI_TRAINING::call_host_startprd_dmi,       // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(11,11,"host_attnlisten_cen"),      // substep name
                DMI_TRAINING::call_host_attnlisten_cen,     // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },
        {
                ISTEPNAME(11,12,"cen_set_inband_addr"),      // substep name
                DMI_TRAINING::call_cen_set_inband_addr,      // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                        NORMAL_IPL_OP,
                        true,
                }
        },

        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep11TaskList    =   {
        &(g_istep11[0]),
        ( sizeof(g_istep11)/sizeof(TaskInfo) ),
        NULL
};

};  // end namespace

#endif
