/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/initserviceif.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __INITSERVICE_INITSERVICEIF_H
#define __INITSERVICE_INITSERVICEIF_H

#include <vmmconst.h>
#include <sys/msg.h>
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/namedtarget.H>
#include    <targeting/attrsync.H>

namespace INITSERVICE
{

    /**
     * Priority scheme, if needed
     */
    enum EventPriority_t
    {
        LOWEST_PRIORITY = 0,    //!<< Notifiy last, LIFO order
        INTR_PRIORITY   = LOWEST_PRIORITY, //!<< Shutdown INTR
        MBOX_PRIORITY   = 1,    //!<< Shutdown MBOX
        NO_PRIORITY = 16,       //!<< No dependency / dont' care, LIFO order
        HIGHEST_PRIORITY = 127, //!<< Nofity first, LIFO order
    };

/**
 * @brief Register a block/range of vitual memory to be handled during a
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
 * @param[in] i_priority, See EventPriority
 * @return true - i_msgQ registered
 *         false - i_msgQ already registered. Not registered again.
 */
bool registerShutdownEvent(msg_q_t i_msgQ,
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
                  uint64_t i_payload_data = 0);

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
}


#endif
