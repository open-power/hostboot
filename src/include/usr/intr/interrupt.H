/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/intr/interrupt.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
    typedef uint32_t ext_intr_t;

    // Interrupt Source Number (ISN) Definition
    // NOTE: It is assumed that LSI sources interrupts in
    //       this list have values that match the LSI source
    //       values listed in the LSIvalue_t enum
    enum ISNvalue_t
    {
        ISN_PSI         = 0,
        ISN_OCC         = 1,
        ISN_FSI         = 2,
        FSP_MAILBOX     = 2,
        ISN_LPC         = 3,
        ISN_LCL_ERR     = 4,
        ISN_HOST        = 5,
        ISN_PSU         = 13,
        ISN_INTERPROC   = 0xF0, // Interproc (IPC) Message Type
        SHUT_DOWN = 0x01000000, //!< INTR presenter sends this when shutting down
    };

    //These values are HW defined values from the LSI Interrupts status register
    // on the PSIHB. These should only be changed if the spec changes.
    enum LSIvalue_t
    {
        LSI_FIRST_SOURCE = 0,
        LSI_PSI          = LSI_FIRST_SOURCE,
        LSI_OCC          = 1,
        LSI_FSIMBOX      = 2,
        LSI_LPC          = 3,
        LSI_LCL_FIR      = 4,
        LSI_GLOBAL       = 5,
        LSI_TPM          = 6,
        LSI_LPC_SERIAL0  = 7,
        LSI_LPC_SERIAL1  = 8,
        LSI_LPC_SERIAL2  = 9,
        LSI_LPC_SERIAL3  = 10,
        LSI_SBE_OR_I2C   = 11,
        LSI_DIO          = 12,
        LSI_PSU          = 13,
        LSI_LAST_SOURCE,
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
        MSG_INTR_MPIPL_CLEANUP,     //!< Clean up interrupts on MPIPL
        MSG_INTR_ADD_CPU_TIMEOUT,   //!< Check for a timeout waiting for a core.
        MSG_INTR_ADD_HBNODE,        //!< Add node info for MPIPL
        MSG_INTR_EOI,               //!< Issue EOI when received
        MSG_INTR_DRAIN_QUEUE,       //!< Allow intrp to drain Q of EOI
        MSG_INTR_COALESCE,          //!< Pending interrupt to be handled
        MSG_INTR_ENABLE_PSI_INTR,   //!< Enable PSIHB Interrupts
        MSG_INTR_DUMP,              //!< Print out interrupt info to slow buffer
    };


    //Derived from 15.8 PSIHB Software Interfaces of the p9_cn_psi_hb_regs.pdf
    //  (splintered off from the P9 Pervasive Workbook)
    // -- shared with other code (like utiltce)
    struct PSIHB_SW_INTERFACES_t
    {
        uint64_t psihbbar; //Host Bridge Base Address Register    - 0x0
        uint64_t fspbar;   //FSP Base Address Register            - 0x8
        uint64_t fspmmr;   //FSP Memory Mask Register             - 0x10
        uint64_t tceaddr;  //TAR - TCE Address Register           - 0x18
        uint64_t psihbcr;  //PSI Host Bridge Ctrl/Status Register - 0x20
        uint64_t psisemr;  //PSIHB Status / Error Mask Register   - 0x28
        uint64_t reserved2; //Unused / Reserved
        uint64_t phbdsr;   //PSIHB Debug Setting register         - 0x38
        uint64_t phbscr;   //PSI Host Bridge Ctrl/Status Register - 0x40
        uint64_t phbccr;   //PSI Host Bridge clear ctl/status reg - 0x48
        uint64_t dmaupaddr; //DMA Upper Address Register          - 0x50
        uint64_t icr;      //Interrupt Control Register           - 0x58
        uint64_t esbciaddr; //ESB CI Base Address                 - 0x60
        uint64_t esbnotifyaddr; //ESB Notification Address        - 0x68
        uint64_t ivtofforig; //IVT Offset Origin Register         - 0x70
        uint64_t lsiintlevel; //LSI Intr Level Register (lab use  - 0x78
        uint64_t lsiintstatus; //LSI Interrupt Status register    - 0x80
        uint64_t reserved3; //Unused / Reserved                   - 0x88
        uint64_t phbsecure; //PSI Host Bridge Secure Control reg  - 0x90
    };

    enum esbStates
    {
        ESB_STATE_RESET   = 0,
        ESB_STATE_OFF     = 1,
        ESB_STATE_PENDING = 2,
        ESB_STATE_QUEUED  = 3,
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
    * Sends a message to the intrrp Q to tell it to print out current state
    * of interrupts from hostboot perspective to the slow trace buffer
    *
    * This will call the private intrrp functions:
    *  printEsbStates
    *  printPSIHBInfo
    *  printLSIInfo
    * @return errlHndl_t on error.
    */
    errlHndl_t printInterruptInfo();

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

    //TODO RTC 150260
    /**
     * Initialize the IRSCReg to enable PSI to present interrupts
     * @param[in] i_target  The target processor
     * @return error log handle on error
     */
    errlHndl_t enablePsiIntr(TARGETING::Target * i_target);

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

    /**
    * Convert the esb state to a human readable string
    * @param[in] i_esbState  ESB state as hex
    * @return human readable string, "INVALID" if cannot translate
    */
    void esbStateToString(uint64_t i_esbState, const char** o_esbStateString);

};

#endif
