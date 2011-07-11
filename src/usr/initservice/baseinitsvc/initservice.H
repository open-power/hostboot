/****************************************************************************
 * $IBMCopyrightBlock:
 * 
 *  IBM Confidential
 * 
 *  Licensed Internal Code Source Materials
 * 
 *  IBM HostBoot Licensed Internal Code
 * 
 *  (C) Copyright IBM Corp. 2011
 * 
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 * $
****************************************************************************/

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
#include <errl/errlentry.H>
#include <initservice/initsvcreasoncodes.H>
#include <initservice/taskargs.H>

#include "../common/initsvcstructs.H"

namespace   INITSERVICE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/

/******************************************************************************/
// InitService Class
/******************************************************************************/

/**
 *  @class  InitService Singleton Class
 *
 *  This class is launched by _start() (see initservicetaskentry.C),
 *  which is launched by the kernel (init_main.C).
 *
 *  Once started, it handles the rest of HostBoot Initialization.
 *
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
     * @brief   start a task using the taskname string in the TaskInfo struct.
     *          taskname string will be something like "libtargeting.so", which
     *          is the name of the compiled and linked targetting module.
     *          The module is expected to have implemented a extern "C"
     *          function called "void _start(void *args)" which is considered
     *          to be the "task entry point".  When _start is called, its
     *          parameter will be set to point to a TaskArgs struct which
     *          can be used to pass information back and forth.  See the
     *          comments in TaskArgs.H for more info.
     *          See initsvctasks.H and the unit tests for some examples of
     *          how this is used.
     *
     *
     *  @param[in]      i_ptask     pointer to a TaskInfo struct
     *  @param[in]      io_pargs    pointer to a TaskArgs struct, or NULL
     *
     *  @return NULL if success, errorlog handle for failure
     *
     *  @note   startTask() can also be used to launch an asynchronous task
     *          by calling it with i_pargs set to NULL.   This will disable
     *          the barrier check.
     *
     */
    errlHndl_t     startTask(   const TaskInfo      *i_ptask,
                                TaskArgs::TaskArgs  *i_pargs    ) const;

    /**
     * @brief   executeFn
     *  Execute an function
     *
     *  @param[in]      i_ptask -   pointer to an TaskInfo struct
     *  @param[in,out]  i_pargs -   pointer to a TaskArgs struct
     *
     *  @return errlHndl_t  handle, NULL if success, filled out errorlog
     *                      if failure
     */
    errlHndl_t executeFn(   const TaskInfo  *i_ptask,
                            TaskArgs        *i_pargs    ) const;



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
    void           setProgressCode( uint64_t  i_progresscode ) const;



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
    /**
     * @note   Disable copy constructor and assignment operator
     */
    InitService(const InitService& i_right);
    InitService& operator=(const InitService& i_right);

};  //  class InitService

} // namespace INITSERVICE

#endif
