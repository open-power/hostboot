//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/isteps/istep4list.H $
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
#ifndef __ISTEPS_ISTEP4LIST_H
#define __ISTEPS_ISTEP4LIST_H

/**
 * @file    istep4list.H
 *
 *  list of functions called by HWAS (ISTEP 4) - "named isteps"
 *
 */


#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

#include    <hwas/hwas.H>

namespace   INITSERVICE
{

/**
 * @note    IStep definition for for Hardware Availability Service (HWAS)
 *
 *  1.  Initialize Target States
 *      1.POWERED_ON=true
 *      2.PRESENT=false
 *      3.FUNCTIONAL=false
 *      4.CHANGED_SINCE_LAST_IPL
 *      5.GARD Level (4 bits)
 *      6.Others?
 *  2.  Call FSI module to "walk the bus" and collect presence information.
 *  3.  Call FSI module interface to collect presence information
 *  4.  Apply presence data: DD framework (Call loaded device drivers)
 *  5.  Apply PR keyword data
 *  6.  Apply Partial Bad data (call Partial Bad module)
 *  7.  Apply GARD data (call GARD module)
 *
 */
const   TaskInfo    g_istep4[]  =   {

        {
                "init_target_states" ,          // substep name
                HWAS::init_target_states,               // pointer to fn
                {
                        START_FN,                       // task type
                        EXT_IMAGE,                      // Extended Module
                        HWAS_1_ERRL_ID,                 // module id
                }
        },
        {
                "init_fsi" ,                    // substep name
                HWAS::init_fsi,                         // pointer to fn
                {
                        START_FN,                       // task type
                        EXT_IMAGE,                      // Extended Module
                        HWAS_2_ERRL_ID,                 // module id
                }
        },
        {
                "apply_fsi_info" ,                   // substep name
                HWAS::apply_fsi_info,                   // pointer to fn
                {
                        START_FN,                       // task type
                        EXT_IMAGE,                      // Extended Module
                        HWAS_3_ERRL_ID,                 // module id
                }
        },
        {
                "apply_dd_presence" ,           // substep name
                HWAS::apply_dd_presence,                // pointer to fn
                {
                        START_FN,                       // task type
                        EXT_IMAGE,                      // Extended Module
                        HWAS_5_ERRL_ID,                 // module id
                }
        },
        {
                "apply_pr_keyword_data" ,       // substep name
                HWAS::apply_pr_keyword_data,            // pointer to fn
                {
                        START_FN,                       // task type
                        EXT_IMAGE,                      // Extended Module
                        HWAS_6_ERRL_ID,                 // module id
                }
        },
        {
                "apply_partial_bad" ,           // substep name
                HWAS::apply_partial_bad,                // pointer to fn
                {
                        START_FN,                       // task type
                        EXT_IMAGE,                      // Extended Module
                        HWAS_7_ERRL_ID,                 // module id
                }
        },
        {
                "apply_gard" ,                  // substep name
                HWAS::apply_gard,                       // pointer to fn
                {
                        START_FN,                       // task type
                        EXT_IMAGE,                      // Extended Module
                        HWAS_8_ERRL_ID,                 // module id
                }
        }

        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep4TaskList    =   {
        g_istep4,
        ( sizeof(g_istep4)/sizeof(TaskInfo) )
};

};  // end namespace

#endif
