/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/initserviceif.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
/* [+] Google Inc.                                                        */
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
#ifndef __INITSERVICE_INITSERVICEIF_H
#define __INITSERVICE_INITSERVICEIF_H

#include <vmmconst.h>
#include <sys/msg.h>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>
#include <targeting/attrsync.H>

#define THIS_NODE_NO_PAYLOAD 0xffffffffffffffffull

namespace INITSERVICE
{

    /**
     * Priority scheme:
     *  The message queue will be sorted in ascending priority order, meaing a
     *  process registering with a priority of zero will be notified first.
     *
     * There are two ranges of callback priorities supported.
     *
     *      1. Pre Memory flush callback priorities are in the range 0-127 and
     *      will occur before the memory has been flushed to pnor.
     *
     *      2. Post memory flush callback priorities are in the range 127-255,
     *      and are signaled after the memory has been flushed to pnor.
     *
     *      NOTE: The final call back for systems which support PLDM should be
     *      POST_MEM_FLUSH_NOTIFY_LAST since it will trigger a power off
     *      request to the BMC.
     *
     */
    enum EventPriority_t
    {
        NOTIFY_FIRST                    = 0,
        HIGHEST_PRIORITY                = NOTIFY_FIRST,
        NO_PRIORITY                     = 16,
        MBOX_PRIORITY                   = 18,
        INTR_PRIORITY                   = 19,
        PRESHUTDOWN_INIT_PRIORITY       = 20,
        LOWEST_PRIORITY                 = 127,
        CONSOLE_PRIORITY                = LOWEST_PRIORITY,
        LAST_PRE_MEM_FLUSH_PRIORITY     = LOWEST_PRIORITY,
        HIGHEST_POST_MEM_FLUSH_PRIORITY = 128,  // 1st post mem flush callback
        PNOR_RP_PRIORITY                = HIGHEST_POST_MEM_FLUSH_PRIORITY,
        POST_MEM_FLUSH_NOTIFY_LAST      = 255
    };

/**
 * @brief Register a block/range of virtual memory to be handled during a
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
 * @param[in] i_priority, See EventPriority
 *
 * @return true - i_msgQ registered
 *         false - i_msgQ already registered. Not registered again.
 */
bool registerShutdownEvent(compId_t i_compID,
                           msg_q_t i_msgQ,
                           uint32_t i_msgType,
                           EventPriority_t i_priority = NO_PRIORITY);

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
 * @brief Perform necessary steps, such as FLUSHing, to registered blocks.
 *
 * @param[in] i_status - Shutdown status to be passed along on shutdown
 * @param[in] i_inBackground - Shutdown should be handled by a background task.
 * @param[in] i_payload_base - The base address (target HRMOR) of the
 *                             payload.
 * @param[in] i_payload_entry - The offset from base address of the
 *                              payload entry-point.
 * @param[in] i_payload_data - Pointer to payload data (if needed)
 *
 * @param[in] i_masterHBinstance - master Host boot instance number (node)
 *                                 Needed when starting payload
 *                                 on multi-node system.
 *
 * @param[in]  i_error_info - Add'tl error data to be included in TI data area
 *
 * @return Nothing
 *
 * @note If inBackground = true, the shutdown call will spawn a child task
 *       which will do the shutdown processing.  If inBackground = false, the
 *       shutdown processing will be handled in the context of the caller and
 *       will never return.
 */
void doShutdown ( uint64_t i_status,
                  bool i_inBackground = false,
                  uint64_t i_payload_base = 0,
                  uint64_t i_payload_entry = 0,
                  uint64_t i_payload_data = 0,
                  uint64_t i_masterHBInstance = THIS_NODE_NO_PAYLOAD,
                  uint32_t i_error_info =0);

/**
 * @brief Wrapper function to perform shutdown including error data
 *     provided in the TI area. This function calls doShutdown() with
 *     the appropriate default parms.
 *
 * @param[in] i_status - Shutdown status to be passed along on shutdown
 * @param[in]  i_error_info - Add'tl error data to be included in TI data area
 *
 * @return Nothing
 */
void doShutdownWithError ( uint64_t i_status, uint32_t i_error_info);

/**
 * @brief Returns if Service Processor Base Services are available
 *
 * If true then the Hostboot<->SP mailbox is enabled and HWSV is
 * providing base services
 *
 * @return bool - true if SP Base Services are available
 */
inline bool spBaseServicesEnabled()
{
    bool spBaseServicesEnabled = false;
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    TARGETING::SpFunctions spfuncs;
    if( sys &&
        sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfuncs) &&
        spfuncs.baseServices )
    {
        spBaseServicesEnabled = true;
    }

    return spBaseServicesEnabled;
}

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
 * @brief This function is to be used by external code to tell
 *      istepdispatcher to stop executing isteps
 *
 *  Note:
 *  Located here so external code can call before
 *  istepdispatcher code is loaded
 *
 * @return Nothing
 */
void stopIpl( void );

/**
 * @brief Return if istepdispatcher needs to stop executing isteps
 * @return true if IPL stopped
 */
bool isIplStopped();

/**
 * @brief Start the istep timings in the global data structure
 * @param[in] istep
 * @return none
 */
void start_istep_timer( uint16_t istep);

/**
 * @brief Stop the istep timings in the global data structure
 * @param[in] istep
 * @return none
 */
void stop_istep_timer( uint16_t istep);

/**
 * @brief Start the substep timings in the global data structure
 * @param[in] istep
 * @param[in] substep
 * @return none
 */
void start_substep_timer( uint16_t istep, uint16_t substep);

/**
 * @brief Stop the substep timings in the global data structure
 * @param[in] istep
 * @param[in] substep
 * @return none
 */
void stop_substep_timer( uint16_t istep, uint16_t substep);

/**
 * @brief Start the substep in progress marker in the global data structure
 * The usage of the start substep in progress marker is used to put a mark
 * on the wall that the substep has been initiated.  The importance of this
 * marker is that during the execution of the substep (for instance host_start_payload)
 * the substep does -NOT- return to the doIstep logic loop, therefore we use
 * the in progress marker in another code location to see if this substep is the one that
 * is being handled as a special case that ends the IPL.
 *
 * Only the substeps are tracked in this manner (that is why there is not an equivalent
 * start_istep_inprogress or stop_istep_inprogress).
 *
 * @param[in] istep
 * @param[in] substep
 * @return none
 */
void start_substep_inprogress( uint16_t istep, uint16_t substep);

/**
 * @brief Stop the substep in progress marker in the global data structure
 * See start_substep_inprogress for more detail on the usage of this marker.
 *
 * @param[in] istep
 * @param[in] substep
 * @return none
 */
void stop_substep_inprogress( uint16_t istep, uint16_t substep);

/**
 * @brief Set substep as a valid substep based on isteplist taskinfo
 * @param[in] istep
 * @param[in] substep
 * @param[in] taskname - taskname to record
 * @return none
 */
void set_substep_valid( uint16_t istep, uint16_t substep, const char* taskname);

/**
 * @brief Log the IPL stats for this Node
 * @return none
 */
void logStats();

}


#endif
