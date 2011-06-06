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


/**
 *  @brief  Trace   Task
 */
const	TaskInfo    TASK_TRACE  =  {
        "libtrace.so" ,                     // taskname
        {  false,                           // don't start
           BASE_MODULE,                     // Base Module
           START_TRACE_ID,                  // module id for errorlog
        },
};


/**
 *  @brief  Errorlog    Task
 */
const   TaskInfo    TASK_ERRORLOG  =  {
        "liberrl.so" , // taskname
        {  false,                                       // don't start
           BASE_MODULE,                                 // Base Module
           START_ERRL_ID,                                   // module id for errorlog

        },
};


/**
 *  @brief  XSCOM    Task
 */
const   TaskInfo    TASK_XSCOMDD  =  {
        "libscom.so" ,     // taskname
        {  false,                                       // don't start
           BASE_MODULE,                                 // Base Module
           START_XSCOMDD_ID,                               // module id for errorlog
        },
};


/**
 * @brief   PNOR    Driver  Task
 */
const   TaskInfo    TASK_PNORDD  =  {
        "libpnordd.so" , // taskname
        {  false,                                       // don't start
           BASE_MODULE,                                 // Base Module
           START_PNORDD_ID,                               // module id for errorlog
        },
};


/**
 * @brief   VFS 2   task, initializes extended module area
 */
const   TaskInfo    TASK_VFS_2   =  {
        "vfs2.so" ,      // taskname
        {  false,                                       // don't start
           BASE_MODULE,                            // Base Module
           START_VFS_2_ID                          // module id for errorlog
        },
};


};  // namespace    INITSERVICE
#endif	// __INIT_SVC_TASKS_H
