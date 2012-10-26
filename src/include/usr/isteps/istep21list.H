/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep21list.H $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef __ISTEPS_ISTEP21LIST_H
#define __ISTEPS_ISTEP21LIST_H

/**
 * @file    istep21list.H
 *
 *  IStep 21    Start Payload
 *  IPL FLow Doc        v1.18 (10/18/12)
 *
 *    21.1    host_runtime_setup
 *          :  Start Payload
 *    21.2    host_verify_hdat
 *          :  Start Payload
 *    21.3    host_start_payload
 *          :  Start Payload
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1613
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/start_payload/start_payload.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep21[]  =   {

        {

                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },

        {
                ISTEPNAME(21,01,"host_runtime_setup"),
                START_PAYLOAD::call_host_runtime_setup,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(21,02,"host_verify_hdat"),
                START_PAYLOAD::call_host_verify_hdat,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
        {
                ISTEPNAME(21,03,"host_start_payload"),
                START_PAYLOAD::call_host_start_payload,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep21TaskList    =   {
        &(g_istep21[0]),
        ( sizeof(g_istep21)/sizeof(TaskInfo) ),
        NULL    //  later, depModules struct
};

};  // end namespace

#endif
