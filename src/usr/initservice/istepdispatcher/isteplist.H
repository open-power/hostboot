#ifndef __ISTEPS_H
#define __ISTEPS_H
/**
 * @file    extinitsvctasks.H
 *
 *  TaskInfo structs for each task that will run in the extended image.
 */

#include    <initservice/initsvcreasoncodes.H>
#include    "istepdispatcher.H"
#include    "../../isteps/isteps.H"

namespace   INITSERVICE
{

const   uint64_t MAX_ISTEPS   =   25;

const TaskInfo    isteps[]   =   {

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

#endif  // __EXT_INIT_SVC_TASKS_H
