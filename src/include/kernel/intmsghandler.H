/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/intmsghandler.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#ifndef __KERNEL_INTERRUPTMSGHDLR_H
#define __KERNEL_INTERRUPTMSGHDLR_H

#include <stdint.h>
#include <kernel/types.h>
#include <kernel/msghandler.H>
#include <kernel/msg.H>
#include <builtins.h>
#include <arch/pirformat.H>

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
            P8_PIR_THREADID_MSK = PIR_t::THREAD_MASK,
            P8_PIR_COREID_MSK   = PIR_t::CORE_MASK,
            P8_PIR_CHIPID_MSK   = PIR_t::CHIP_MASK,
            P8_PIR_NODEID_MSK   = PIR_t::GROUP_MASK,

            // Logical Shift Left fields for mmio Base address from PIR.
            // (IP addr bit pos - PIR bit pos)
            P8_IP_THREADID_LSL = (12-PIR_t::BITS_AFTER_CORE),
            P8_IP_COREID_LSL   = (15-PIR_t::BITS_AFTER_CORE),
            P8_IP_CHIPID_LSL   = (20-PIR_t::BITS_AFTER_CHIP),
            P8_IP_NODEID_LSL   = (22-PIR_t::BITS_AFTER_GROUP),
            XIRR_ADDR_OFFSET   = 4,
            MFRR_ADDR_OFFSET   = 12,

            INTP_BAR_VALUE     = 0xFFFFE000,    // upper 32 bits of IPCBAR

            INTERPROC_XISR     = 2,     //IPI XISR is 2
        };

        /**
         * Constructor
         */
        InterruptMsgHdlr(MessageQueue * i_msgQ)
            : MessageHandler(&iv_lock,i_msgQ), iv_lock() {}

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

        /**
         * Issue an IPI to the core.
         *
         * @param[in] i_pir - The PIR of the CPU to send IPI at.
         * @param[in] i_favor - How favored the interrupt is; 0 = most favored
         *                      254 = least favored, 255 = no interrupt
         *                      Default 0x1 - IPI from kernel side (wakeup)
         */
        static void sendIPI(uint64_t i_pir, uint8_t i_favor = 0x1);

        /**
         * Issue the sbe/mailbox workaround (issue a mbox EOI to mailbox)
         *
         */
        static void issueSbeMboxWA();

    private:

        static InterruptMsgHdlr * cv_instance;
        static uint64_t cv_ipc_base_address;

        Spinlock iv_lock;
};


#endif

