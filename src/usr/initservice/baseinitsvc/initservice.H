/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/baseinitsvc/initservice.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2018                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

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
     * @brief Message queue structure.
     *
     */
    struct regMsgQ_t
    {
        msg_q_t msgQ;
        uint32_t msgType;
        uint32_t msgPriority;
        compId_t compID;

        /**
         * @brief Constructor
         */
        regMsgQ_t(msg_q_t i_msgQ,
                  uint32_t i_msgType,
                  EventPriority_t i_priority,
                  compId_t i_compId) :
            msgQ(i_msgQ), msgType(i_msgType),
                  msgPriority((uint32_t)i_priority),
                  compID(i_compId) {}

        // allow us to sort the queue based on priority
        bool operator < (const regMsgQ_t &msg ) const
        {
            return ( msgPriority < msg.msgPriority);
        }

    };


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
     *          is the name of the compiled and linked targeting module.
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
     * @param[in] i_compID, component registering event
     * @param[in] i_msgQ, A message queue to send a message to on shutdown
     * @param[in] i_msgType, The message type to send.
     * @param[in] i_priority, @See src/include/usr/initservice/initserviceif.H
     *
     * @return true  - i_msgQ registered
     *         false - i_msgQ already registered.- not registered again.
     */
    bool registerShutdownEvent(compId_t i_compID,
                               msg_q_t i_msgQ,
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
     * @brief Save Istep Step and Substep for use by error logging
     * @param[in] i_step, Istep Step
     * @param[in] i_subStep, Istep subStep
     * @return none
     */
    void ShadowIstepData( uint8_t i_step,
                          uint8_t i_subStep );

    /**
     * @brief Extract Istep Step and Substep
     * @param[out] o_step, Istep Step
     * @param[out] o_subStep, Istep subStep
     * @return none
     */
    void GetIstepData( uint8_t & o_step,
                       uint8_t & o_subStep );

    /**
     *  @brief Shut down Hostboot in a controlled way
     *
     *  @note: See the API documentation @
     *      src/include/usr/initservice/initserviceif.H
     */
    static void doShutdown (
                     uint64_t i_status,
                     bool     i_inBackground = false,
                     uint64_t i_payload_base = 0,
                     uint64_t i_payload_entry = 0,
                     uint64_t i_payload_data = 0,
                     uint64_t i_masterHBInstance = THIS_NODE_NO_PAYLOAD,
                     uint32_t i_error_info = 0);

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
     * @brief Atomically sets the shutdown status and TI data associated with
     *     a shutdown request
     *
     * @par Detailed Description
     *     Atomically sets the shutdown status and TI data associated with
     *     a shutdown request.  Any number of callers may initiate parallel
     *     shutdown requests, however this interface ensures that the first
     *     caller atomically updates the initial TI area and shutdown status.
     *     Subsequent callers will only be able to lock in a new status (TI
     *     area remains untouched) if it is a non-success reason code and the
     *     initial status was a PLID.
     *
     * @warning Should only be called by INITSERVICE::doShutdown
     *
     * @param[in] i_status     Shutdown status to be passed to primary shutdown
     *     handler
     * @param[in] i_error_info Additional error data to be included in TI data
     *
     * @return bool Boolean indicating whether this was the first shutdown
     *     to be requested
     */
    bool _setShutdownStatus(
        uint64_t i_status,
        uint32_t i_error_info);

    /**
     * @brief Perform necessary shut down steps.
     *
     * @param[in] i_status - Shutdown status to be passed along on shutdown
     * @param[in] i_payload_base - The base address (target HRMOR) of the
     *                             payload.
     * @param[in] i_payload_entry - The offset from base address of the
     *                              payload entry-point.
     * @param[in] i_payload_entry - HRMOR adjusted address of any payload data
     *                              placed in r3
     * @param[in] i_masterHBInstance - master hostboot instance number (node)
     *                                 Needed when starting payload on a
     *                                 multi-node system.
     * @param[in] i_error_info - Additional error data to be included in TI data
     *
     * @return Nothing
     * @note This calls registered services to notify them of shutdown and it
     * flushes the virtual memory.
     */
    void _doShutdown (uint64_t i_status,
                      uint64_t i_payload_base = 0,
                      uint64_t i_payload_entry = 0,
                      uint64_t i_payload_data = 0,
                      uint64_t i_masterHBInstance = 0xffffffffffffffffull,
                      uint32_t i_error_info = 0);

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


    typedef std::vector<regMsgQ_t> EventRegistry_t;

    // List of Services to notify on shutdown
    EventRegistry_t iv_regMsgQ;

    mutex_t iv_registryMutex;
    bool iv_shutdownInProgress;

    // Worst shutdown status accumulated during shutdown processing
    uint64_t iv_worst_status;

    uint8_t iv_iStep;     // shadow of current istep / substep
    uint8_t iv_iSubStep;  //  for error logs

};  //  class InitService

} // namespace INITSERVICE

#endif
