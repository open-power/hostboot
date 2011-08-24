//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/istepdispatcher/isteplist.H $
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

#ifndef __ISTEPS_H
#define __ISTEPS_H

/**
 * @file    isteplist.H
 *
 *  TaskInfo structs for each task that will run in the extended image.
 */

#include    <initservice/initsvcreasoncodes.H>
#include    "istepdispatcher.H"
#include    "../../isteps/isteps.H"

namespace   INITSERVICE
{

const   uint64_t MAX_ISTEPS   =   25;

const TaskInfo    g_isteps[]   =   {

        //  -----   ISteps Image  ------------------------------------------

        /**
         * @brief   targeting task, initializes extended module area
         */
        {
                "istep1" ,                              // istep name
                ISTEPS::IStep1,                         // pointer to fn
                {
                        NONE,                           // task type
                        EXT_IMAGE,                      // Extended Module
                        ISTEP_1_ERRL_ID,                // module id
                }
        },

        //  ---------------------------------------------------------------
        //  -----   END OF LIST!!!  ---------------------------------------
        //  ---------------------------------------------------------------

        /**
         * @brief   last task in the list
         */
        {
                "end" ,                                 // dummy string
                NULL,                                   // pointer to fn
                {
                        END_TASK_LIST,                       // end of list
                        UNDEFINED_MT,                   // dummy module type
                        UNDEFINED_MODULE_ERRL_ID,            // dummy errorlog
                }
        },

};


};  // namespace

#endif
