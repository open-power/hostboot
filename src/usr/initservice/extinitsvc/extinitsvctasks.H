//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/extinitsvc/extinitsvctasks.H $
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

#ifndef __EXT_INIT_SVC_TASKS_H
#define __EXT_INIT_SVC_TASKS_H

/**
 * @file    extinitsvctasks.H
 *
 *  TaskInfo structs for each task that will run in the extended image.
 */

#include    <initservice/initsvcreasoncodes.H>
#include    "extinitsvc.H"

namespace   INITSERVICE
{

const   uint64_t MAX_EXT_TASKS   =   25;

const TaskInfo g_exttaskinfolist[]   =   {

        //  -----   Extended Image  ------------------------------------------

        /**
         * @brief   ecmddatabuffer task, 
         */
        {
                "libecmddatabuffer.so" ,                    // taskname
                NULL,                                       // no pointer to fn
                {
                        INIT_TASK,                          // task type
                        EXT_IMAGE,                          // Extended Module
                        START_ECMDDATABUFFER_ERRL_ID,       // module id
                }
        },

        /**
         * @brief   hwpf task, 
         */
        {
                "libhwpf.so" ,                              // taskname
                NULL,                                       // no pointer to fn
                {
                        INIT_TASK,                          // task type
                        EXT_IMAGE,                          // Extended Module
                        START_HWPF_ERRL_ID,                 // module id
                }
        },

        /**
         * @brief   fabi task, 
         */
        {
                "libfapi.so" ,                              // taskname
                NULL,                                       // no pointer to fn
                {
                        INIT_TASK,                          // task type
                        EXT_IMAGE,                          // Extended Module
                        START_FAPI_ERRL_ID,                 // module id
                }
        },
        
        /**
         * @brief   hwp task, 
         */
        {
                "libhwp.so" ,                               // taskname
                NULL,                                       // no pointer to fn
                {
                        INIT_TASK,                          // task type
                        EXT_IMAGE,                          // Extended Module
                        START_HWP_ERRL_ID,                  // module id
                }
        },
        
        /**
         * @brief   plat task, 
         */
        {
                "libplat.so" ,                              // taskname
                NULL,                                       // no pointer to fn
                {
                        INIT_TASK,                          // task type
                        EXT_IMAGE,                          // Extended Module
                        START_PLAT_ERRL_ID,                 // module id
                }
        },
        
        /**
         * @brief   targeting task,
         */
        {
            "libtargeting.so" ,                         // taskname
            NULL,                                       // no pointer to fn
            {
                START_TASK,                         // task type
                EXT_IMAGE,                          // Extended Module
                START_TARGETING_ERRL_ID,            // module id
            }
        },

        /**
         * @brief   IStep Dispatcher task, runs ISteps
         */
        {
            "libistepdisp.so" ,                         // taskname
            NULL,                                       // no pointer to fn
            {
                START_TASK,                         // task type
                EXT_IMAGE,                          // Extended Module
                EXECUTE_ISTEPS_ERRL_ID,             // module id
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


//  -----   UNIT    TESTS   -------------------------------------------------
const   TaskInfo    CXXTEST_TASK    =   {
                "libcxxtest.so" ,                           // taskname
                NULL,                                       // no pointer to fn
                {
                        START_TASK,                         // task type
                        EXT_IMAGE,                          // Extended Module
                        START_CXXTEST_ERRL_ID,              // module id
                }
        };


};  // namespace

#endif  // __EXT_INIT_SVC_TASKS_H
