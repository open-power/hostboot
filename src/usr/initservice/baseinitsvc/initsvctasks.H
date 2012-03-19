//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/baseinitsvc/initsvctasks.H $
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

#ifndef __INIT_SVC_TASKS_H
#define __INIT_SVC_TASKS_H

/**
 * @file    initsvctasks.H
 *
 *  TaskInfo structs for each task that will run.
 */

#include    <initservice/initsvcreasoncodes.H>
#include    "initservice.H"

namespace   INITSERVICE
{

const   uint64_t MAX_TASKS   =   10;

const TaskInfo    g_taskinfolist[]   =   {

        /**
         *  @brief  Errorlog    Task
         */
        {
                "liberrl.so" ,                      // taskname
                NULL,                               // no ptr to fn
                {
                        NONE,                       // don't start
                        BASE_IMAGE,                 // Base Module
                }
        },


        /**
         * @brief   PNOR    Driver  Task
         */
        {
                "libpnor.so" ,                      // taskname
                NULL,                               // no pointer to fn
                {
                        START_TASK,                 // start
                        BASE_IMAGE,                 // Base Module
                }
        },

        /**
         * @brief  Extended VFS module
         */
        {
                "libvfs.so",                        // taskname
                NULL,
                {
                        START_TASK,                 // start task
                        BASE_IMAGE,                 // Base Module
                }
        },

        //  -----   Extended Image  -----------------------------------------------------

        /**
         * @brief   extinitsvc, initializes extended module area
         */
        {
                "libextinitsvc.so" ,                // taskname
                NULL,                               // no pointer to fn
                {
                        START_TASK,                 // call start()
                        EXT_IMAGE,                  // EXT_IMAGE
                }
        },


        //  ---------------------------------------------------------------
        //  -----   END OF LIST!!!  ---------------------------------------
        //  ---------------------------------------------------------------

        /**
         * @brief   last task in the list
         */
        {
                "end" ,                             // dummy string
                NULL,                               // pointer to fn
                {
                        END_TASK_LIST,              // end of list
                        UNDEFINED_MT,               // dummy module type
                }
        },

};


};  // namespace
#endif  //
