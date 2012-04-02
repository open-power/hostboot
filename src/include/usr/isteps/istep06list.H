//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/isteps/istep6list.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __ISTEPS_ISTEP6LIST_H
#define __ISTEPS_ISTEP6LIST_H

/**
 * @file    istep6list.H
 *
 *  list of functions called by HWAS (ISTEP 6) - "named isteps"
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

#include    <hwas/hwas.H>
#include    <hwas/plat/hostbootIstep.H>


namespace   INITSERVICE
{

/**
 * @note    IStep definition for Hostboot - Slave SBE
 *
 *  1.  host_setup : Setup host environment
 *  2.  host_istep_enable : Hostboot istep ready
 *  3.  host_init_fsi : Setup the FSI links to slave chips
 *  4.  host_set_ipl_parms : Build ipl parameters
 *  5.  host_discover_targets : Builds targeting
 *  6.  host_gard : Do Gard
 *  7.  host_cancontinue_clear : Clear deconfigured states
 *  8.  proc_check_slave_sbe_seeprom_complete : Check Slave SBE Complete
 *
 */
const   TaskInfo    g_istep06[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(06,01,"host_setup"),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(06,02,"host_istep_enable"),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },

        {
                ISTEPNAME(06,03,"host_init_fsi"),           // substep name
                HWAS::host_init_fsi,                        // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                }
        },
        {
                ISTEPNAME(06,04,"set_ipl_parms"),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(06,05,"host_discover_targets"),   // substep name
                HWAS::host_discover_targets,                // pointer to fn
                {
                        START_FN,                           // task type
                        EXT_IMAGE,                          // Extended Module
                }
        },
        {
                ISTEPNAME(06,06, "host_gard"),           // substep name
                HWAS::host_gard,                        // pointer to fn
                {
                        START_FN,                       // task type
                        EXT_IMAGE,                      // Extended Module
                }
        },
        {
                ISTEPNAME(06,07,"host_cancontinue_clear"),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(06,08,"proc_check_slave_sbe_seeprom_complete"),
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },

        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep06TaskList    =   {
        &(g_istep06[0]),
        ( sizeof(g_istep06)/sizeof(TaskInfo) ),
        NULL
};

};  // end namespace

#endif
