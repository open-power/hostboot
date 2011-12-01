//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/baseinitsvc/initservice.H $
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

#ifndef __BASEINITSVC_INITSERVICE_H
#define __BASEINITSVC_INITSERVICE_H
/**
 *  @file initservice.H
 *
 *  Base image Initialization Service
 *      - Manage high-level host boot IPL flow
 *      - Perform can-continue processing
 *      - Perform automatic and manual Istep execution
 *      - Handle flow errors as appropriate.
 *
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
#include <initservice/initsvcstructs.H>
#include <vmmconst.h>

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
 *  @class  InitService
 *
 *  Singleton Class
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
     *                        _start() and by extension the kernel,
     *                        currently this is always NULL .
     *
     *  @return nothing
     *
     */
    void            init( void *i_args);


     /**
     * @brief   Start a task using the taskname string in the TaskInfo struct.
     *
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
     *  @param[in,out]  io_pargs    pointer to a TaskArgs struct, or NULL
     *                              On input, TaskArgs struct will have
     *                              command, returncode, and errlog fields
     *                              cleared.  task can fill in these values
     *                              on return.
     *
     *  @return pointer to errorlog
     *  @retval NULL if success, filled in errorlog handle for failure
     *
     *  @note   startTask() can also be used to launch an asynchronous task
     *          by calling it with i_pargs set to NULL.   This will disable
     *          the barrier check.
     *
     */
    errlHndl_t     startTask(   const TaskInfo      *i_ptask,
                                TaskArgs::TaskArgs  *io_pargs    ) const;

    /**
     * @brief   Execute an function
     *
     *  @param[in]      i_ptask -   pointer to an TaskInfo struct
     *  @param[in,out]  i_pargs -   pointer to a TaskArgs struct
     *                              On input, TaskArgs struct will have
     *                              command, returncode, and errlog fields
     *                              cleared.  Task can fill in these values
     *                              on return.
     *
     *  @return pointer to errorlog
     *  @retval NULL if success, filled out errorlog if failure
     */
    errlHndl_t executeFn(   const TaskInfo  *i_ptask,
                            TaskArgs        *i_pargs    ) const;


    /**
     * @brief   set progress code for task.
     *          This is supposed to make a system call to post the error to
     *          SP and will also write a SCOM reg
     *
     * @TODO need progress code categories defined.
     *
     * @param[in]  i_progresscode - 64-bit progress code.
     *
     * @return  nothing
     *
     */
    void           setProgressCode( uint64_t  i_progresscode ) const;


    /**
     * @brief   dispatch Task depending on what type of task it is,
     *          etc.
     *
     * @param[in]       i_ptask  -  pointer to a TaskInfo struct, which should
     *                              contain all the info to run the task.
     * @param[in,out]   io_pargs -  pointer to a TaskArgs struct.  It is
     *                              possible that this will not be used at all.
     *
     * @return  pointer to errlog
     * @retval  returns NULL, or a pointer to a filled out errorlog
     */
    errlHndl_t  dispatchTask( const TaskInfo    *i_ptask,
                              TaskArgs          *io_pargs ) const;

    /**
     * @brief Registry a block/range of vitual memory to be handled during a
     *        shutdown.
     *
     * @param[in] i_vaddr - Base virtual address
     * @param[in] i_size - Size of virtual memory from base address
     * @param[in] i_priority - Order to handle given block(0-Lowest Priority)
     *
     * @return Nothing
     */
    void registerBlock(void* i_vaddr, uint64_t i_size, BlockPriority i_priority);

    /**
     * @brief Perform necessary steps, such as FLUSHing, to registered blocks.
     *
     * @param[in] i_status - Shutdown status to be passed along on shutdown
     *
     * @return Nothing
     */
    void doShutdown(uint64_t i_status);


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

    /**
     * @struct regBlock_t
     * @brief Attributes stored for virtual memory ranges that must be handled
     *        during a shutdown.
     */
    struct regBlock_t
    {
        //Base virtual address
        void* vaddr;
        //Size of virtual memory from base address
        uint64_t size;
        //Priority order in which to handle the given block
        uint64_t priority;

        /**
         * @brief Constructor to initialize a registered block object
         */
        regBlock_t(void* i_vaddr, uint64_t i_size, uint64_t i_priority) :
            vaddr(i_vaddr), size(i_size), priority(i_priority) {}
    };

    //Store a list of registered blocks
    std::vector<regBlock_t*> iv_regBlock;

};  //  class InitService

} // namespace INITSERVICE

#endif
