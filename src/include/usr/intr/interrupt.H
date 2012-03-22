//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/intr/interrupt.H $
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
#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <sys/msg.h>
#include <errl/errlentry.H>
#include <sys/interrupt.h>

namespace INTR
{


    /**
     * External Interrupt Types (XISR)
     */
    enum ext_intr_t
    {
        NO_INTERRUPT = 0,       //!< no interrupt present
        INTERPROC = 2,          //!< Inter processor interrupt
        FSP_MAILBOX = 0x1A,     //!< TODO final value??
        ATTENTION = 0x26,       //!< TODO find this value
    };

    /**
     * Msg types for intrRp from usr space
     */
    enum msg_intr_types_t
    {
        MSG_INTR_ADD_CPU_USR = 1,  //!< Add cpu core, data[0] = cpuid (PIR)
        MSG_INTR_REGISTER_MSGQ,    //!< Register a msgQ
        MSG_INTR_UNREGISTER_MSGQ,  //!< Un register a msgQ
        MSG_INTR_ENABLE,           //!< Enable external Interrupts
        MSG_INTR_DISABLE,          //!< Disable external interrupts
    };


    /**
     * Register a message queue to recieve external interrupts
     * @param[in] i_msgQ  The message queue
     * @param[in] i_type  The type of interrupt (XISR value)
     * @return errlHndl_t on error.
     */
    errlHndl_t registerMsgQ(msg_q_t i_msgQ, ext_intr_t i_type);

    /**
     * Un register a message queue from the interrupt handler
     * @param[in] i_type the type of interrupt (XISR value)
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

};

#endif
