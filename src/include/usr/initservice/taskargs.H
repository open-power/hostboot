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

#ifndef __TASKARGS_TASKARGS_H
#define __TASKARGS_TASKARGS_H

/**
 * @file    taskargs.H
 *
 * common file to hold arguments passed onto tasks.
 *
 * will also hold macros, etc to manage arguments

 */

#include    <assert.h>
#include    <sys/sync.h>
#include    <trace/interface.H>

#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>

/**
 * @note macro to set up a _start() task entry routine.
 */
#define TASK_ENTRY_MACRO( MyInitFn )                                        \
extern "C"                                                                  \
void _start( void *io_pArgs )                                               \
{                                                                           \
    INITSERVICE::TaskArgs::TaskArgs *pTaskArgs  =                           \
            reinterpret_cast<INITSERVICE::TaskArgs::TaskArgs *>(io_pArgs);  \
                                                                            \
    MyInitFn( pTaskArgs );                                                  \
                                                                            \
    if  ( pTaskArgs )                                                       \
    {                                                                       \
        pTaskArgs->waitChildSync();                                         \
    }                                                                       \
                                                                            \
    task_end();                                                             \
}


namespace   INITSERVICE
{

/**
 * @const   TASKARGS_UNDEFINED64
 *  iv_taskreturncode and iv_taskcommand are initialized to this value -
 *  if parent or child change them, it can be easily recognized
 *
 *
 */
const   uint64_t    TASKARGS_UNDEFINED64  =   0xbadc0ffee0ddf00d;

/**
 *  @class TaskArgs
 *
 *  passed into a task as a void* pointer
 *  contains:
 *      - barrier to wait on
 *      - data from parent (if used)
 *      - return code from child (if used)
 *      - pointer to errorlog handle
 *
 */
class  TaskArgs
{

public:


    /**
     * @brief   TaskArgs    constructor
     *
     */
    TaskArgs();


    /**
     * @brief   TaskArgs    destructor
     */
    ~TaskArgs();


    /**
     * @brief   waitParentSync()
     *
     * Wait for internal barrier associated with this args struct
     * This should be called by the task that launches a child task.
     * Currently there is no difference between parent and child
     * but this may change.
     *
     */
    void    waitParentSync();


    /**
     * @brief   waitChildSync()
     *
     * Wait for internal barrier associated with this args struct
     * This should be called by the child task.
     * Currently there is no difference between parent and child
     * but this may change.
     *
     */
    void    waitChildSync();


    /**
     * @brief   postReturnCode
     *
     * Child task can use this to post a return code to InitServices
     *
     * @param[in]   i_returncode;
     *
     */
    void    postReturnCode( const uint64_t i_returncode );


    /**
     * @brief   getReturnCode
     *
     * Parent task can use this to get a return code from the child
     *
     * @return value of iv_taskreturncode;
     *
     */
    uint64_t getReturnCode( )   const;


    /**
     * @brief   setCommand
     *
     * Parent can pass commands and info to the child using this function
     *
     * @param[in]   i_command;
     */
    void    setCommand( const uint64_t  i_command );


    /**
     * @brief   getCommand
     *
     * Child can get commands from the parent using this function
     *
     *@return   value of iv_taskcommand;
     *
     * @todo    might overload this later if we need to pass structs,
     *          buffers, etc.
     */
    uint64_t    getCommand( )   const;


    /**
     * @brief   postErrorLog
     *
     * Child task can use this to post an errorlog to InitServices
     * Caller is responsible for creating a new errorlog, etc.
     * No checking is done.
     *
     * @param[in]   i_errl;
     *
     */
    void    postErrorLog( errlHndl_t i_errl );


    /**
     * @brief   getErrorLog
     *
     * Parent task can use this to get an errorlog from the child
     *
     * @return iv_errl
     *
     */
    errlHndl_t getErrorLog( );


    /**
     * @brief   clear taskargs struct between uses
     *          - barrier is left alone,
     *          - if iv_errl is non zero, we commit it here just to avoid
     *              a memory leak.
     */
    void    clear();


private:

    /**
     * @note   Disable copy constructor and assignment operator
     */
    TaskArgs(const TaskArgs& i_right);
    TaskArgs& operator=(const TaskArgs& i_right);


    errlHndl_t  iv_errl;
    uint64_t    iv_taskreturncode;
    uint64_t    iv_taskcommand;

    barrier_t   iv_sync_barrier;

};

};  // namespace


#endif
