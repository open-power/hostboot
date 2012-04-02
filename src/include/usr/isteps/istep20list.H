//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/isteps/istep20list.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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

#ifndef __ISTEPS_ISTEP20LIST_H
#define __ISTEPS_ISTEP20LIST_H

/**
 * @file    istep20list.H
 *
 *  IStep 20    Load Payload
 *  IPL FLow Doc        v1.01 (03/26/12)
 *
 *    20.1    host_load_payload
 *          : Load payload
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1612
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/load_payload/load_payload.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep20[]  =   {

        {

                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },

        {
                ISTEPNAME(20,01,"host_load_payload"),
                LOAD_PAYLOAD::call_host_load_payload,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep20TaskList    =   {
        &(g_istep20[0]),
        ( sizeof(g_istep20)/sizeof(TaskInfo) ),
        NULL    //  later, depModules struct
};

};  // end namespace

#endif
