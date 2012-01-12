//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/isteps/istep_template_list.H $
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
//
#ifndef __ISTEPS_ISTEP<@istepnum>LIST_H
#define __ISTEPS_ISTEP<@istepnum>LIST_H


/**
 * @file    istep18list.H
 *
 *  <@istepdesc>
 *  <@docversion>
 *
 *  <@istepnum>.<@substepnum>   <@substepname>  :
 *      <@substepdesc>
 *      ...
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */



#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/HWPs/<@istepname>/<@istepname>.H"

namespace   INITSERVICE
{

const   TaskInfo    g_istep<@istepnum>[]  =   {

        {
                ISTEPNAME(<@istepnum>,<@substepnum>,"<@substepname>"),
                <@istepname>::call_<@substepname>,
                {
                        START_FN,
                        EXT_IMAGE,
                        <@istepname>_ERRL_ID,
                }
        },

        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep<@istepnum>TaskList    =   {
        g_istep<@istepnum>,
        ( sizeof(g_istep<@istepnum>)/sizeof(TaskInfo) )
};

};  // end namespace

#endif
