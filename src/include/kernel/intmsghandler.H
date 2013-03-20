/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/intmsghandler.H $                          */
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
#ifndef __KERNEL_INTERRUPTMSGHDLR_H
#define __KERNEL_INTERRUPTMSGHDLR_H

#include <stdint.h>
#include <kernel/types.h>
#include <kernel/msghandler.H>
#include <kernel/msg.H>
#include <builtins.h>

/**
 * @class InterruptMsgHdlr
 * @brief Class to handle sending a message to user space for
 *        an External Interrupt.
 *
 * This class extends from the base MessageHandler so the base send/receive
 * message functions can be utilized. It overrides how to handle the message
 * responses
 */
class InterruptMsgHdlr : public MessageHandler
{
    public:

        /**
         * Field values for P8
         * @note This is used to calculate the mmio address offset
         * from the PIR for the interrupt presenter memory mapped registers.
         * The masks isolate the node,chip,core, and thread id fields in the
         * PIR.  The LSL values tell how far left a PIR field needs to be
         * shifted to create a proper mmio offset address.
         *
         */
        enum
        {
            P8_PIR_THREADID_MSK = 0x00000007,
            P8_PIR_COREID_MSK   = 0x00000078,
            P8_PIR_CHIPID_MSK   = 0x00000380,
            P8_PIR_NODEID_MSK   = 0x00001C00,

            // Logical Shift Left fields for mmio Base address from PIR.
            // (IP addr bit pos - PIR bit pos)
            P8_IP_THREADID_LSL = (12-0),
            P8_IP_COREID_LSL   = (15-3),    
            P8_IP_CHIPID_LSL   = (20-7),
            P8_IP_NODEID_LSL   = (22-10),
            XIRR_ADDR_OFFSET   = 4,
        };

        // Notes:
        //   All external interrupts are routed to one cpu core
        //   External Interrupts are only processed one at a time
        //   So we don't need a spinlock
        /**
         * Constructor
         */
        InterruptMsgHdlr(MessageQueue * i_msgQ)
            : MessageHandler(NULL,i_msgQ) {}

        /** 
         * Destructor.
         */
        virtual ~InterruptMsgHdlr() {};

        /**
         * Handle response to 'send message'
         *
         *  @param[in] i_type - The message type previously sent.
         *  @param[in] i_key - The key value for the received message.
         *  @param[in] i_task - The deferred task.
         *  @param[in] i_rc - The response rc from userspace.
         *
         *  @return HandleResult - The desired behavior on the 'recv message'
         *                         interface for this <key, task> pair.
         */
        virtual HandleResult handleResponse(msg_sys_types_t i_type,void* i_key,
                                            task_t* i_task,int i_rc);


        ALWAYS_INLINE
        static uint64_t mmio_offset(uint64_t i_pir)
        {
            uint64_t offset = 0;

            // The PIR chip id field has 1 extra bit (8 chips), so we need
            // to shift the node and chip separately
            offset  |= 
                (i_pir & P8_PIR_NODEID_MSK) << P8_IP_NODEID_LSL;

            offset  |= 
                (i_pir & P8_PIR_CHIPID_MSK) << P8_IP_CHIPID_LSL;

            // The core and thread id field are adjacent in both the PIR and
            // the mmio offset, so they can be done in one shift operation.
            offset  |=
                (i_pir & (P8_PIR_COREID_MSK | P8_PIR_THREADID_MSK))
                << P8_IP_THREADID_LSL;

            return offset;
        }
            
        /**
         * Create the InterruptMsgHdlr to handle external interrupts
         * @param[in] i_msgQ The message queue
         * @param[in] i_ipc_addr  The base address of the IPC registers
         */
        static void create(MessageQueue * i_msgQ, uint64_t i_ipc_addr);

        /**
         * Handle an external interrupt from HW
         */
        static void handleInterrupt();

        /**
         * Add cpu core - set up the external interrupt registers
         * @param[in] i_pir The cpu id of the core to to set-up
         * @note should be called when ever a new core becomes active
         */
        static void addCpuCore(uint64_t i_pir);

    private:

        static InterruptMsgHdlr * cv_instance;
        static uint64_t cv_ipc_base_address;
};


#endif

