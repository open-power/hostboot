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
#include <sys/msg.h>

#include <trace/interface.H>
#include <errl/errlentry.H>     //  errlHndl_t
#include <errl/errlmanager.H>    //  errlCommit()
#include <initservice/initsvcreasoncodes.H>
#include <initservice/initsvcstructs.H>
#include <vmmconst.h>
#include <initservice/initserviceif.H>

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
     *          to be the "task entry point".       *
     *
     *  @param[in]      i_ptask     pointer to a TaskInfo struct
     *  @param[in,out]  io_pargs    pointer to any args.  This is usually NULL.
     *
     *  @return pointer to errorlog
     *  @retval NULL if success, filled in errorlog handle for failure
     */
    errlHndl_t     startTask(   const TaskInfo      *i_ptask,
                                void                *io_pargs    ) const;

    /**
     * @brief   Execute an function
     *
     *  @param[in]      i_ptask -   pointer to an TaskInfo struct
     *  @param[in,out]  i_pargs -   pointer to any args.  This is usually NULL.
     *
     *  @return pointer to errorlog
     *  @retval NULL if success, filled out errorlog if failure
     */
    errlHndl_t executeFn(   const TaskInfo  *i_ptask,
                            void            *i_pargs    ) const;


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
     * @param[in,out]   io_pargs -  pointer to any args.  This is usually NULL.
     *
     * @return  pointer to errlog
     * @retval  returns NULL, or a pointer to a filled out errorlog
     */
    errlHndl_t  dispatchTask( const TaskInfo    *i_ptask,
                              void              *io_pargs ) const;

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
     * @brief Register a service to be notified during shutdown
     *
     * @param[in] i_msgQ, A message queue to send a message to on shutdown
     * @param[in] i_msgType, The message type to send.
     * @param[in] i_priority, @See src/include/usr/initservice/initserviceif.H
     *
     * @return true  - i_msgQ registered
     *         false - i_msgQ already registered.- not registered again.
     */
    bool registerShutdownEvent(msg_q_t i_msgQ,
                               uint32_t i_msgType,
                               EventPriority_t i_priority);

    /**
     * @brief Un register a service for a Shutdown event
     * 
     * @param[in] i_msgQ, The message queue to be removed.
     *
     * @return true  - i_msgQ was removed from the event notification list. |
     *         false - i_msgQ was not registered in the event notification list.
     */
    bool unregisterShutdownEvent(msg_q_t i_msgQ);

    /**
     * @brief Perform necessary shut down steps.
     *
     * @param[in] i_status - Shutdown status to be passed along on shutdown
     * @param[in] i_payload_base - The base address (target HRMOR) of the
     *                             payload.
     * @param[in] i_payload_entry - The offset from base address of the
     *                              payload entry-point.
     *
     * @return Nothing
     * @note This calls registered services to notify them of shutdown and it
     * flushes the virtual memory.
     */
    void doShutdown ( uint64_t i_status,
                      uint64_t i_payload_base = 0,
                      uint64_t i_payload_entry = 0 );


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
     *  Disable copy constructor and assignment operator
     */
    InitService(const InitService& i_right);
    InitService& operator=(const InitService& i_right);


    /**
     * Check and load module associated with this task or function
     *  if necessary.
     *
     * @param[in]       i_ptask  -  pointer to a TaskInfo struct, which should
     *                              contain all the info to run the task.
     *  @return pointer to errorlog
     *  @retval NULL if success, filled out errorlog if failure
     */
    errlHndl_t  checkNLoadModule( const TaskInfo *i_ptask ) const;


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

    struct regMsgQ_t
    {
        msg_q_t msgQ;
        uint32_t msgType;
        uint32_t msgPriority;

        /**
         * @brief Constructor
         */
        regMsgQ_t(msg_q_t i_msgQ,
                  uint32_t i_msgType,
                  EventPriority_t i_priority) :
            msgQ(i_msgQ), msgType(i_msgType), msgPriority((uint32_t)i_priority) {}
    };

    typedef std::vector<regMsgQ_t> EventRegistry_t;

    // List of Services to notify on shutdown
    EventRegistry_t iv_regMsgQ;

};  //  class InitService

} // namespace INITSERVICE

#endif
