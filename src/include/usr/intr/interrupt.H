/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/intr/interrupt.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <sys/msg.h>
#include <errl/errlentry.H>

namespace INTR
{


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
    enum ext_intr_t
    {
        NO_INTERRUPT = 0,       //!< no interrupt present
        INTERPROC = 2,          //!< Inter processor interrupt (should be changed?)
        FSP_MAILBOX = 0x1A,     //!< TODO final value??
        ATTENTION = 0x26,       //!< TODO find this value
        MAX_XISR  = 0x00FFFFFF, //!< Max value of the XISR
        SHUT_DOWN = 0x01000000, //!< INTR presenter sends this when shutting down
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
        MSG_INTR_SHUTDOWN,         //!< Call to shutdown interrupt presenter
    };


    /**
     * Register a message queue for an interrupt type
     * @param[in] i_msgQ The message queue
     * @param[in] i_msg_type, The message type of the message to send
     *                        to i_msgQ when an interrupt of
     *                        i_intr_type occurrs.
     * @param[in] i_intr_type, The interrupt type to register.
     *
     * @note the interrupt type is currently the XISR value in the XIRR
     *       register and consists of the chipid, buid, and level
     *       @see  i_intr_type for enumerations.
     *
     * @note when an interrupt of type i_msg_type occurrs, the
     * interrupt presenter sends a sync message with type i_msg_type to
     * i_msgQ with i_intr_type in message data word 0 and then waits
     * for a response.
     *
     * @note When HB is shutting down the interrupt presenter will send
     * a message to all registered queues with a sync message type of
     * i_msg_type, and data[0] = INTR::SHUT_DOWN.  A response is expected.
     */
    errlHndl_t registerMsgQ(msg_q_t i_msgQ,
                            uint32_t i_msg_type,
                            ext_intr_t i_intr_type);

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

    /**
     * Get the cpu id of the interrupt destination
     * @param[in] i_xisr, The XISR value for the interrupt
     * @return cpuId (PIR value)
     * @pre The interrupt service provider is initialized
     * @note the XISR = IRSN | IRSN_source
     */
    uint32_t intrDestCpuId(uint32_t i_xisr);

};

#endif
