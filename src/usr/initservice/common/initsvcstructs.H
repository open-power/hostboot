/****************************************************************************
 * $IBMCopyrightBlock:
 * 
 *  IBM Confidential
 * 
 *  Licensed Internal Code Source Materials
 * 
 *  IBM Flexible Support Processor Licensed Internal Code
 * 
 *  (C) Copyright IBM Corp. 2011
 * 
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 * $
****************************************************************************/

#ifndef __COMMON_INITSVCSTRUCTS_H
#define __COMMON_INITSVCSTRUCTS_H
/**
 *  @file initsvcstructs.H
 *
 *  common structs for initservice, extinitsvc, istepdispatcher
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>

namespace   INITSERVICE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/


/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/

/**
 * @enum    TaskType
 *  - NONE          ==  placeholder, no task
 *  - START_TASK   ==   task with _start() function entry point
 *  - START_FN      ==  task with function pointer entry point
 *  - BARRIER       ==  set barrier for next N tasks.
 *  - STOP_TASK     ==  Execute the destructor on the task in extended image.
 *                      ( not implemented yet)
 *  - END_TASK_LIST ==  last entry in the task list.
 */
enum    TaskType
{
    UNDEFINED_TT    =   0,
    NONE,
    START_TASK,
    START_FN,
    BARRIER,
    STOP_TASK,
    END_TASK_LIST,
};


/**
 * @enum    ModuleType
 *  -   BASE_IMAGE == module in the base image
 *  -   EXT_IMAGE == module in the extended image
 */
enum    ModuleType
{
    UNDEFINED_MT    =   0,
    BASE_IMAGE,
    EXT_IMAGE,
};


/**
 * @struct  TaskFlags
 *
 *  - run _start() function on start
 *  - module type, BASE_MODULE or EXT_MODULE
 *  - module_id for errorlog if task fails
 *
 */
struct  TaskFlags
{
    TaskType            task_type;          // this is a task, run _start() function
    ModuleType          module_type;        // BASE_IMAGE or EXT_IMAGE
    InitServiceModuleID module_id;          // module id for errorlog
};


/**
 * @struct  TaskInfo
 *
 * Holds information on each task in the system.
 *      - taskname
 *      - execution flags, see TaskFlags above
 *
 */
struct  TaskInfo
{
    const   char        taskname[VFS_MODULE_NAME_MAX];
    void                (*taskfn)(void *ptr);
    const   TaskFlags   taskflags;

};

} // namespace

#endif
