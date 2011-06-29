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

const TaskInfo iv_exttaskinfolist[]   =   {

        //  -----   Extended Image  ------------------------------------------

        /**
         * @brief   targeting task, initializes extended module area
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


};  // namespace    EXTINITSVC

#endif  // __EXT_INIT_SVC_TASKS_H
