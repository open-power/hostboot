#ifndef __BASEINITSVC_INITSERVICE_H
#define __BASEINITSVC_INITSERVICE_H
/**
 *  @file initservice.H
 *
 *      - Manage high-level host boot IPL flow
 *      - Perform can-continue processing
 *      - Perform automatic and manual Istep execution
 *      - Handle flow errors as appropriate.
 *
 */

/**
 * High-level todo list
 *
 * @todo    SP3:    move startTask() and reportError() to private
 * @todo    SP3:    add (NULL) detection to printk
 * @@todo           Add more macros to trace, discuss with Andrew and Nick
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <util/singleton.H>
#include <sys/vfs.h>            // VFS_MODULE_NAME_MAX

#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/initsvcreasoncodes.H>


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
 * @todo revisit these flags in sprint3
 */
struct  TaskFlags
{
    TaskType            task_type;          // this is a task, run _start() function
    ModuleType          module_type;        // BASE_IMAGE or EXT_IMAGE
    InitServiceModuleID module_id;          // module id for errorlog
};

/**
 * @struct  _TaskInfo
 *
 * Holds information on each task in the system.
 *      - taskname
 *      - execution flags, see TaskFlags above
 *
 */
struct  TaskInfo
{
    const   char        taskname[VFS_MODULE_NAME_MAX];
    void        (*taskfn)(void *ptr);
    const   TaskFlags   taskflags;

};


/******************************************************************************/
// InitService Class
/******************************************************************************/

// Singleton definition
class InitService;
typedef Singleton<InitService> theInitService;

/**
 *  @class  InitService Singleton Class
 *
 *  This class is launched by _start() (see initservicetaskentry.C),
 *  which is launched by the kernel (init_main.C).
 *
 *  Once started, it handles the rest of HostBoot Initialization.
 *
 *  @returns    none
 */
class InitService
{

public:

    friend  class InitServiceTest;

    /**
     * @brief Get singleton instance of this class.
     *
     *  @return the (one and only) instance of InitService
     */
    static InitService& getTheInstance();

    /**
     *  @brief  Provide an entry function into the class, called from _start()
     *
     *  @param[in]  i_args    pointer to any arguments passed in from
     *                      _start() and by extension the kernel,
     *                      currently this is NULL .
     */
    void            init( void *i_args);

    /**
     * @todo    InitServiceTest should be able to find protected functions.
     */
    // $$protected:

    /**
     * @brief   start a task
     *
     *  @param[in]      i_ptask     pointer to a TaskInfo struct
     *  @param[in]      io_pargs    pointer to a TaskArgs struct, or NULL
     *  @param[inout]   io_rerrl    reference to an errorlog handle.
     *                              errorlog will be filled out if error,
     *                              otherwise untouched.
     *
     *  @return NULL if success, errorlog handle for failure
     *
     */
    errlHndl_t     startTask(   const TaskInfo      *i_ptask,
                                TaskArgs::TaskArgs  *i_pargs,
                                errlHndl_t          &io_rerrl ) const;


    /**
     * @brief   report Error to the system.
     *
     * @param[in]  io_rerrl - errlHndl_t pointer to a filled-out error entry
     *                                 errorlog will be committed, errorlog
     *                                 will be deleted, and pointer will be
     *                                 set to NULL on exit
     *
     * @return  nothing
     */
    void           reportError( errlHndl_t  &io_rerrl) const;


    /**
     * @brief   set progress code for task.
     *
     * @param[in]  i_progresscode - 64-bit progress code.
     *
     * @return  nothing
     *
     */
    void           setProgressCode( uint64_t  &i_progresscode ) const;



protected:

    /**
     * @brief Constructor for the InitService object.
     */
    InitService();

    /**
     * @brief Destructor for the InitService object.
     */
    ~InitService();


private:


};  //  class InitService

} // namespace INITSERVICE

#endif
