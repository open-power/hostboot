//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/isteps/isteplist.H $
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

#include    <vector>

#include    <initservice/initsvcreasoncodes.H>
#include    <initservice/initsvcstructs.H>

#include    "isteps.H"


namespace   INITSERVICE
{

const   uint64_t    MAX_SUBSTEPS =  25;

/**
 * @struct  ExtTaskInfo
 *
 * struct to store the TaskInfo for this IStep, plus the number of items in
 * the istep (calculated at compiletime).
 */
struct  ExtTaskInfo
{
    const TaskInfo  *const pti;
    const uint64_t  numitems;
};

const   TaskInfo    istep0[]  =   {

        {
                "istep0_substep0" ,                              // istep name
                ISTEPS::IStep0sub0,                         // pointer to fn
                {
                        NONE,                           // task type
                        EXT_IMAGE,                      // Extended Module
                        ISTEP_1_ERRL_ID,                // module id
                }
        },

        {
                "istep0_substep1" ,                              // istep name
                ISTEPS::IStep0sub1,                         // pointer to fn
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
                "end_istep0" ,                                 // dummy string
                NULL,                                   // pointer to fn
                {
                        END_TASK_LIST,                       // end of list
                        UNDEFINED_MT,                   // dummy module type
                        UNDEFINED_MODULE_ERRL_ID,            // dummy errorlog
                }
        },
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep0    =   {
    &(istep0[0]),
    ( sizeof(istep0)/sizeof(TaskInfo) )                 //  numitems
};


const   TaskInfo    istep1[]  =   {

        /**
         * @brief   targeting task, initializes extended module area
         */
        {
                "istep1_sub0" ,                              // istep name
                ISTEPS::IStep1sub0,                         // pointer to fn
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

// make a struct from the above with the number of items included
ExtTaskInfo g_istep1    =   {
        istep1,
        ( sizeof(istep1)/sizeof(TaskInfo) )
};


// initialize an array of ExtTaskInfo
const  ExtTaskInfo  g_isteps[]    =   {
        g_istep0,
        g_istep1,
};

// publish the size of the g_isteps array
const   uint64_t    MAX_ISTEPS   =  sizeof(g_isteps)/sizeof(TaskInfo *) ;


};  // namespace

#endif
