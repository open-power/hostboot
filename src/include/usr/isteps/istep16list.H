/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep16list.H $                        */
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

#ifndef __ISTEPS_ISTEP16LIST_H
#define __ISTEPS_ISTEP16LIST_H

/**
 * @file    istep16list.H
 *
 *  IStep 16    Core Activate
 *  IPL FLow Doc        v1.18 (10/18/12)
 *
 *    16.1    host_activate_master
 *          : Activate master core
 *    16.2    host_activate_slave_cores
 *          : Activate slave cores
 *    16.3    host_ipl_complete
 *          : Notify FSP drawer ipl complete
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1609
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/core_activate/core_activate.H"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep16[]  =   {

        {

                "",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },

        {
                ISTEPNAME(16,01,"host_activate_master"),
                CORE_ACTIVATE::call_host_activate_master,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        {
                ISTEPNAME(16,02,"host_activate_slave_cores"),
                CORE_ACTIVATE::call_host_activate_slave_cores,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        {
                ISTEPNAME(16,03,"host_ipl_complete"),
                CORE_ACTIVATE::call_host_ipl_complete,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },


        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep16TaskList    =   {
        &(g_istep16[0]),
        ( sizeof(g_istep16)/sizeof(TaskInfo) ),
        NULL    //  later, depModules struct
};

};  // end namespace

#endif
