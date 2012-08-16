/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/isteps/istep10list.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __ISTEPS_ISTEP10LIST_H
#define __ISTEPS_ISTEP10LIST_H


/**
 * @file    istep10list.H
 *
 *  Step 10 Hostboot SBE Centaur Init
 *  IPL FLow Doc        v1.01 (03/26/12)
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */



#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/sbe_centaur_init/sbe_centaur_init.H"

namespace   INITSERVICE
{

const   TaskInfo    g_istep10[]  =   {

        {
                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(10,01,"cen_sbe_tp_chiplet_init1"),
                SBE_CENTAUR_INIT::call_sbe_centaur_init,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },

        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep10TaskList    =   {
        &(g_istep10[0]),
        ( sizeof(g_istep10)/sizeof(TaskInfo) ),
        NULL
};

};  // end namespace

#endif
