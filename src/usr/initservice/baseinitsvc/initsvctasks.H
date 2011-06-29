/**
 * @file    initsvctasks.H
 *
 *  TaskInfo structs for each task that will run.
 */

#ifndef __INIT_SVC_TASKS_H
#define __INIT_SVC_TASKS_H

#include    <initservice/initsvcreasoncodes.H>
#include    "initservice.H"

namespace   INITSERVICE
{

const   uint64_t MAX_TASKS   =   10;

const TaskInfo    iv_taskinfolist[]   =   {

        /**
         *  @brief  Errorlog    Task
         */
        {
                "liberrl.so" ,                  // taskname
                NULL,                           // no ptr to fn
                {
                        NONE,                        // don't start
                        BASE_IMAGE,             // Base Module
                        START_ERRL_ERRL_ID,     // module id for errorlog

                }
        },


        /**
         * @brief   PNOR    Driver  Task
         */
        {
                "libpnordd.so" ,                        // taskname
                NULL,                                   // no pointer to fn
                {
                        NONE,                                // don't start
                        BASE_IMAGE,                     // Base Module
                        START_PNORDD_ERRL_ID,                // module id for errorlog
                }
        },

        //  -----   Extended Image  -----------------------------------------------------

        /**
         * @brief   extinitsvc, initializes extended module area
         */
        {
                "libextinitsvc.so" ,                     // taskname
                NULL,                                   // no pointer to fn
                {
                        START_TASK,                          // don't start
                        EXT_IMAGE,                      // Ext Module
                        START_EXTINITSVC_ERRL_ID,             // module id for errorlog
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


};  // namespace    INITSERVICE
#endif  // __INIT_SVC_TASKS_H
