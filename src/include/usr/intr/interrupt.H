/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/intr/interrupt.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <sys/msg.h>
#include <errl/errlentry.H>

namespace TARGETING
{
    class Target;
};

namespace INTR
{
    /**
     * cpu PIR register
     */
    struct PIR_t
    {
        union
        {
            uint32_t word;
            struct
            {
                //P8:
                uint32_t        reserved:19;    //!< zeros
                uint32_t        nodeId:3;       //!< node (0-3)
                uint32_t        chipId:3;       //!< chip pos on node (0-5)
                uint32_t        coreId:4;       //!< Core number (1-6,9-14)?
                uint32_t        threadId:3;     //!< Thread number (0-7)
            } PACKED;
        };
        PIR_t(uint32_t i_word = 0) : word(i_word) {}

        PIR_t(uint32_t i_nodeId, uint32_t i_chipId,
              uint32_t i_coreId, uint32_t i_thread = 0) :
            reserved(0),
            nodeId(i_nodeId), chipId(i_chipId),
            coreId(i_coreId), threadId(i_thread) {}

        PIR_t operator= (uint32_t i_word)
        {
            word = i_word;
            return word;
        }

        bool operator< (const PIR_t& r) const
        {
            return word < r.word;
        }
    };

    /**
     * External Interrupt Types (XISR)
     * This value is passed in message data[0] on interrupt or shutdown.
     * @note The XISR is 24 bits:
     * XISR[ 0: 4] NOT DEFINED
     * XISR[ 5: 7] Node id
     * XISR[ 8:10] chipId within Node
     * XISR[11:12] Unit selection [GX='00', PHB0='01', PHB1='10', PHB2='11']
     * XISR[13:19] BUID
     * XISR[20:23] level
     *
     * extr_intr_t values are XISR right shifted, lsb = bit 23
     */
    enum XISRvalue_t
    {
        NO_INTERRUPT = 0,       //!< no interrupt present
        INTERPROC_XISR = 2,     //!< XISR value for IPIs
        MAX_XISR  = 0x00FFFFFF, //!< Max value of the XISR
        SHUT_DOWN = 0x01000000, //!< INTR presenter sends this when shutting down
    };

    typedef uint32_t ext_intr_t;

    enum ISNvalue_t
    {
        ISN_PSI         = 0,
        ISN_OCC         = 1,
        ISN_FSI         = 2,
        FSP_MAILBOX     = 2,
        ISN_LPC         = 3,
        ISN_LCL_ERR     = 4,
        ISN_HOST        = 5,
        ISN_INTERPROC   = 0xF0, //"special" as it isn't part of PSIHB
                                //Converts to INTERPROC_XISR when registered
    };

    /**
     * The XISR value is the logical OR of the Interrup Requestor Source
     * Number (IRSN) and the Interrrupt Source Number (ISN).
     * See BookIV PSI chapter.  ISN is defined in the XIVR register and
     * IRSN is defined in the Interrupt Requester Source Compare Register
     */
    struct XISR_t
    {
        union
        {
            uint32_t       u32;
            struct
            {
                uint32_t        res:22; //!< Not used by Host boot
                uint32_t       node:3;  //!< PIR node id value
                uint32_t       chip:3;  //!< PIR chip id value
                uint32_t   intrproc:1;  //!< '0'-> interproc interrupt else '1'
                uint32_t        isn:3;  //!< Interrupt Source Number

            } PACKED;
        };

        XISR_t() : u32(0) {}
    };


    /**
     * Msg types for intrRp from usr space
     */
    enum msg_intr_types_t
    {
        MSG_INTR_REGISTER_MSGQ = 1, //!< Register a msgQ
        MSG_INTR_UNREGISTER_MSGQ,   //!< Un register a msgQ
        MSG_INTR_ENABLE,            //!< Enable external Interrupts
        MSG_INTR_DISABLE,           //!< Disable external interrupts
        MSG_INTR_SHUTDOWN,          //!< Call to shutdown interrupt presenter
        MSG_INTR_ENABLE_PSI_INTR,   //!< Enable PSI interrupts
        MSG_INTR_MPIPL_CLEANUP,     //!< Clean up interrupts on MPIPL
        MSG_INTR_ADD_CPU_TIMEOUT,   //!< Check for a timeout waiting for a core.
        MSG_INTR_ADD_HBNODE,        //!< Add node info for MPIPL
        MSG_INTR_EOI,               //!< Issue EOI when received
        MSG_INTR_DRAIN_QUEUE,       //!< Allow intrp to drain Q of EOI
    };

    /**
     * Register a message queue for an interrupt type
     * @param[in] i_msgQ The message queue
     * @param[in] i_msg_type, The message type of the message to send
     *                        to i_msgQ when an interrupt of
     *                        i_intr_type occurrs.
     * @param[in] i_intr_type, The interrupt type to register. Done
     *       for all chips presently capable of generating interrupts
     *
     * @note the interrupt type is currently the ISN value in the PSIHB
     *       XIVR register
     *       @see  ISNvalue_t for enumerations.
     *       The XISR value is calculated and registered for all chips
     *       presently capable of generaing interrupts.
     *
     * @note when an interrupt of type i_msg_type occurrs, the
     * interrupt presenter sends a sync message with type i_msg_type to
     * i_msgQ with FULL IRSN word 0 and then waits for a response.
     * Once the underlying hardware has been cleaned up (not driving
     * the interrupt) then sendEOI should be called.  Note the msg
     * must not be modified by the recipient.  The full IRSN has the
     * node/chip/ISN, not just the ISN
     *       @see makeXISR

     *
     * @note When HB is shutting down the interrupt presenter will send
     * a message to all registered queues with a sync message type of
     * i_msg_type, and data[0] = INTR::SHUT_DOWN.  A response is expected.
     */
    errlHndl_t registerMsgQ(msg_q_t i_msgQ,
                            uint32_t i_msg_type,
                            ext_intr_t i_intr_type);

    /**
     * Responds to the interrupt message and lets the interrupt
     * resource provide know that it can send the End Of Interrupt
     * to the hardware.  If the interrupt is being driven at this point
     * a new interrupt will be fired with an additional message placed
     * on the client's Queue
     * @param[in] i_q message queue
     * @param[in] i_msg The message that was sent to indicate an
                        interrupt.  This must remain unchanged
     *                  between receipt and sending the EOI
     */
    void sendEOI(msg_q_t i_q, msg_t* i_msg);

    /**
     * Un register a message queue from the interrupt handler
     * @param[in] i_type the type of interrupt (ISN value)
     * @return The message queue that was unregistered with i_type
     *         | NULL if no queue was not found for i_type
     */
    msg_q_t unRegisterMsgQ(ext_intr_t i_type);

    /**
     * Enable hardware to report external interrupts
     * @return errlHndl_t on error.
     */
    errlHndl_t enableExternalInterrupts();

    /**
     * Disable hardware from reporting external interrupts
     * @return errlHndl_t on error.
     */
    errlHndl_t disableExternalInterrupts();

    /**
     * Initialize the IRSCReg to enable PSI to present interrupts
     * @param[in] i_target  The target processor
     * @return error log handle on error
     */
    errlHndl_t enablePsiIntr(TARGETING::Target * i_target);

    /**
     * Return the interrupt presenter for requested target/thread
     * @param[in] i_ex  The target EX
     * @param[in] i_thread  Which thread on EX (0-7)
     * @return 64 bit address for the interrupt present addr
     */
    uint64_t getIntpAddr(const TARGETING::Target * i_ex,
                         uint8_t i_thread);

    /**
     * Indicate the existence of another HB node in the system
     * @param[in] The HB instance number (HB node)
     * @return error log handle on error
     */
    errlHndl_t addHbNode(uint64_t i_hbNode);

    /**
     * Method to send synchronous message to interrupt RP.  Intent
     * is to allow any pending EOIs (since they are async) to
     * drain     */
    void drainQueue(void);


};

#endif
