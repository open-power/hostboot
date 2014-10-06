/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmidd.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
/**
 *  @file ipmidd.C
 *
 *  @brief Implementation of the IPMI Device Driver
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <errl/errludstring.H>
#include "ipmidd.H"
#include "ipmirp.H"
#include <ipmi/ipmiif.H>
#include <initservice/initserviceif.H>
#include <util/align.H>
#include <lpc/lpcif.H>
#include <config.h>

#include <sys/msg.h>
#include <errno.h>

#include <sys/time.h>
#include <sys/task.h>

/*****************************************************************************/
// D e f i n e s
/*****************************************************************************/

trace_desc_t* g_trac_ipmi;
TRAC_INIT(&g_trac_ipmi, IPMI_COMP_NAME, 6*KILOBYTE, TRACE::BUFFER_SLOW);

#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"dd: "printf_string,##args)

// Registers. These are fixed for LPC/BT so we can hard-wire them
#define REG_CONTROL     0xE4
#define REG_HOSTBMC     0xE5
#define REG_INTMASK     0xE6

// Control register bits. The control register is interesting in that writing
// 0's never does anything; all registers are either set to 1 when written
// with a 1 or toggled (1/0) when written with a one. So, we don't ever need
// to read-modify-write, we can just write an or'd mask of bits.
#define CTRL_B_BUSY       (1 << 7)
#define CTRL_H_BUSY       (1 << 6)
#define CTRL_OEM0         (1 << 5)
#define CTRL_SMS_ATN      (1 << 4)
#define CTRL_B2H_ATN      (1 << 3)
#define CTRL_H2B_ATN      (1 << 2)
#define CTRL_CLR_RD_PTR   (1 << 1)
#define CTRL_CLR_WR_PTR   (1 << 0)

#define IDLE_STATE (CTRL_B_BUSY | CTRL_B2H_ATN | CTRL_SMS_ATN | CTRL_H2B_ATN)

// Bit in the INMASK register which signals to the BMC
// to reset it's end of things.
#define INT_BMC_HWRST     (1 << 7)

// How long to sychronously wait for the device to change state (in ns)
#define WAIT_TIME 100000000

/**
 * @brief Performs an IPMI Message Read Operation
 * This function performs a IPMI Message Read operation. It follows a
 * pre-defined prototype functions in order to be registered with the
 * device-driver framework.
 *
 * @param[in]   i_opType        Operation type READ
 * @param[in]   i_target        IPMI target, ignored use the master sentinel
 * @param[out]  o_buffer        Pointer to a BT message we're going to fill in.
 * @param[out]  o_buflen        Always sizeof(uint8_t)
 * @param[in]   i_accessType    DeviceFW::IPMIBT
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, it is unused
 * @return  errlHndl_t
 */
errlHndl_t ddRead(DeviceFW::OperationType i_opType,
                  TARGETING::Target* i_target,
                  void* o_buffer,
                  size_t& o_buflen,
                  int64_t i_accessType,
                  va_list i_args)
{
    // If someone passed in the wrong target, we have a coding error
    assert(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target,
           "ipmi read expects master processor target");

    // We are the BT driver, so it's safe to assume they sent us a BTMessage.
    return Singleton<IpmiDD>::instance().receive(
        static_cast<IPMI::BTMessage*>(o_buffer));
}

/**
 * @brief Performs an IPMI Message Write Operation
 * This function performs a IPMI Message Write operation. It follows a
 * pre-defined prototype functions in order to be registered with the
 * device-driver framework.
 *
 * @param[in]   i_opType        Operation type WRITE
 * @param[in]   i_target        IPMI target, ignored use the master sentinel
 * @param[in]   i_buffer        Pointer to a BT message we're going to transmit
 * @param[in]   i_buflen        Always sizeof(uint8_t)
 * @param[in]   i_accessType    DeviceFW::IPMIBT
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, it is unused
 * @return  errlHndl_t
 */
errlHndl_t ddWrite(DeviceFW::OperationType i_opType,
                   TARGETING::Target* i_target,
                   void* i_buffer,
                   size_t& i_buflen,
                   int64_t i_accessType,
                   va_list i_args)
{
    // If someone passed in the wrong target, we have a coding error
    assert(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target,
           "ipmi write expects master processor target");

    // We are the BT driver, so it's safe to assume they sent us a BTMessage
    return Singleton<IpmiDD>::instance().send(
        static_cast<IPMI::BTMessage*>(i_buffer));
}

// Register IPMIDD access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::IPMIBT,
                      TARGETING::TYPE_PROC,
                      ddRead);

DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::IPMIBT,
                      TARGETING::TYPE_PROC,
                      ddWrite);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Read an address from LPC space
 */
errlHndl_t IpmiDD::readLPC(const uint32_t i_addr, uint8_t& o_data)
{
    static size_t size = sizeof(uint8_t);
    errlHndl_t err = deviceOp( DeviceFW::READ,
                             TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                             static_cast<void*>(&o_data),
                             size,
                             DEVICE_LPC_ADDRESS(LPC::TRANS_IO, i_addr) );
    return err;
}

/**
 * @brief Write an address from LPC space
 */
errlHndl_t IpmiDD::writeLPC(const uint32_t i_addr,
                            uint8_t i_data)
{
    static size_t size = sizeof(uint8_t);
    errlHndl_t err = deviceOp(DeviceFW::WRITE,
                              TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                              static_cast<void*>(&i_data),
                              size,
                              DEVICE_LPC_ADDRESS(LPC::TRANS_IO, i_addr) );
    return err;
}

/**
 * @brief  Static function wrapper to pass into task_create
 */
static void* poll_control_register( void* /* unused */ )
{
    IPMI_TRAC(ENTER_MRK "poll_control_register" );
    Singleton<IpmiDD>::instance().pollCtrl();
    return NULL;
}

/**
 * @brief Poll the control register
 */
void IpmiDD::pollCtrl(void)
{
    // Mark as an independent daemon so if it crashes we terminate.
    task_detach();

    // We send a message to this message queue when the ipmi state changes.
    // Don't free these messages - these messages are sent async so the
    // consumer will free the message.
    static msg_q_t mq = Singleton<IpmiRP>::instance().msgQueue();
    msg_t* msg = NULL;

    uint8_t ctrl = 0;

    while(1)
    {
        mutex_lock(&iv_mutex);
        errlHndl_t err = readLPC(REG_CONTROL, ctrl);

        // Not sure there's much we can do here but commit the log
        // and let this thread fail.
        if (err)
        {
            IPMI_TRAC(ERR_MRK "polling loop encountered an error, exiting");
            errlCommit(err, IPMI_COMP_ID);
            break;
        }
        else
        {
            // If we're idle, tell the resoure provider to check for any
            // pending messages which were delayed due to contention. But don't
            // send a message everytime we see idle, only if there we suspect
            // we sent EAGAINs.
            if (((ctrl & IDLE_STATE) == 0) && iv_eagains)
            {
                msg = msg_allocate();
                msg->type = IPMI::MSG_STATE_IDLE;
                msg_send(mq, msg);
                iv_eagains = false;
            }

            // If we see the B2H_ATN, there's a response waiting
            else if (ctrl & CTRL_B2H_ATN)
            {
                msg = msg_allocate();
                msg->type = IPMI::MSG_STATE_RESP;
                msg_send(mq, msg);
            }

            // If we see the SMS_ATN, there's an event waiting
            else if (ctrl & CTRL_SMS_ATN)
            {
                IPMI_TRAC(ERR_MRK "sending state sms/event, unexpected");
                msg = msg_allocate();
                msg->type = IPMI::MSG_STATE_EVNT;
                msg_send(mq, msg);
            }
        }
        mutex_unlock(&iv_mutex);
        nanosleep(0, WAIT_TIME);
    }
}

/**
 * @brief Performs a reset of the BT hardware
 */
inline errlHndl_t IpmiDD::reset(void)
{
    // Reset the BT interface, and flush messages. We eat messages off of
    // the interface until it goes idle. We assume, since we're resetting,
    // that there is nothing on the interface we're interested in.
    mutex_lock(&iv_mutex);
    IPMI_TRAC(ENTER_MRK "resetting the IPMI BT interface");

    uint8_t ctrl = 0;
    IPMI::BTMessage msg;

    errlHndl_t err = readLPC(REG_CONTROL, ctrl);
    IPMI_TRAC("reset: control register %x", ctrl);
    while ((ctrl & (CTRL_B2H_ATN | CTRL_SMS_ATN)) && (err == NULL))
    {
        // There should only be one, if any - but we'll log each one we find.
        IPMI_TRAC(INFO_MRK "found a waiting message during reset");
        err = receive(&msg);
        IPMI_TRAC("reset: received %x:%x", msg.iv_netfun, msg.iv_cmd);
        delete[] msg.iv_data;

        if (err) {break;}

        err = readLPC(REG_CONTROL, ctrl);
        IPMI_TRAC("reset: control register %x", ctrl);
    }

    // Commit this log. We're about to reset the PHY anyway, so maybe
    // that'll clear this error. If not, we'll report that error.
    if (err)
    {
        errlCommit(err, IPMI_COMP_ID);
    }

    mutex_unlock(&iv_mutex);

    IPMI_TRAC(EXIT_MRK "resetting the IPMI BT interface");
    return writeLPC(REG_INTMASK, INT_BMC_HWRST);
}

/**
 * @brief Performs an IPMI Message Write Operation
 */
errlHndl_t IpmiDD::send(IPMI::BTMessage* i_msg)
{
    errlHndl_t err = NULL;
    uint8_t    ctrl = 0;

    mutex_lock(&iv_mutex);
    do
    {
        err = readLPC(REG_CONTROL, ctrl);
        if (err) { break; }

        // If the interface isn't idle, tell the caller to come back
        if ((ctrl & IDLE_STATE) != 0)
        {
            i_msg->iv_state = EAGAIN;
            iv_eagains = true;
            continue;
        }

        // Tell the interface we're writing. Per p. 135 of the
        // spec we *do not* set H_BUSY.
        err = writeLPC(REG_CONTROL, CTRL_CLR_WR_PTR);
        if (err) { break; }

        // Add the header size on as req_len is only the length of the data
        err = writeLPC(REG_HOSTBMC, i_msg->iv_len + IPMI_BT_HEADER_SIZE);
        if (err) { break; }

        err = writeLPC(REG_HOSTBMC, i_msg->iv_netfun);
        if (err) { break; }

        err = writeLPC(REG_HOSTBMC, i_msg->iv_seq);
        if (err) { break; }

        err = writeLPC(REG_HOSTBMC, i_msg->iv_cmd);
        if (err) { break; }

        for( size_t i = 0; (i < i_msg->iv_len) && (err == NULL); ++i)
        {
            err = writeLPC(REG_HOSTBMC, i_msg->iv_data[i]);
        }
        if (err) { break; }

        // If all is well, alert the host we sent bits.
        err = writeLPC(REG_CONTROL, CTRL_H2B_ATN);
        if (err) {break;}

    } while(false);

    mutex_unlock(&iv_mutex);

    // If we have an error, try to reset the interface.
    if (err)
    {
        reset();
    }

    // Don't bother reporting a write if we returned EAGAIN, the
    // upper layers will report the re-queue or whatever.
    if (i_msg->iv_state != EAGAIN)
    {
        IPMI_TRAC(INFO_MRK "write %s %x:%x seq %x len %x",
                  err ? "err" : "ok",
                  i_msg->iv_netfun, i_msg->iv_cmd, i_msg->iv_seq,
                  i_msg->iv_len);
    }

    return err;
}

/**
 * @brief Read a response to an issued command, or an sms
 */
errlHndl_t IpmiDD::receive(IPMI::BTMessage* o_msg)
{
    errlHndl_t err = NULL;
    uint8_t    ctrl = 0;
    bool       marked_busy = false;

    mutex_lock(&iv_mutex);

    do
    {
        err = readLPC(REG_CONTROL, ctrl);
        if (err) { break; }

        // Tell the interface we're busy.
        err = writeLPC(REG_CONTROL, CTRL_H_BUSY);
        if (err) {break;}

        marked_busy = true;

        // Clear the pending state from the control register.
        // Note the spec distinctly says "after setting H_BUSY,
        // the host should clear this bit" - not at the same time.
        // This is the hand-shake; H_BUSY gates the BMC which allows
        // us to clear the ATN bits. Don't get fancy.
        err = writeLPC(REG_CONTROL,
                         (ctrl & CTRL_B2H_ATN) ? CTRL_B2H_ATN : CTRL_SMS_ATN);
        if (err) {break;}

        // Tell the interface we're reading
        err = writeLPC(REG_CONTROL, CTRL_CLR_RD_PTR);
        if (err) {break;}

        // The first byte is the length, grab it so we can allocate a buffer.
        err = readLPC(REG_HOSTBMC, o_msg->iv_len);
        if (err) { break; }

        // I don't think SMS messages have a completion code.
        o_msg->iv_len -= (ctrl & CTRL_B2H_ATN) ?
            IPMI_BT_HEADER_SIZE + 1 : IPMI_BT_HEADER_SIZE;

        err = readLPC(REG_HOSTBMC, o_msg->iv_netfun);
        if (err) { break; }

        err = readLPC(REG_HOSTBMC, o_msg->iv_seq);
        if (err) { break; }

        err = readLPC(REG_HOSTBMC, o_msg->iv_cmd);
        if (err) { break; }

        // I don't think SMS messages have a completion code.
        if (ctrl & CTRL_B2H_ATN)
        {
            err = readLPC(REG_HOSTBMC, o_msg->iv_cc);
            if (err) { continue; }
        }

        o_msg->iv_data = new uint8_t[o_msg->iv_len];

        for( size_t i = 0; (i < o_msg->iv_len) && (err == NULL); ++i)
        {
            err = readLPC(REG_HOSTBMC, o_msg->iv_data[i]);
        }
        if (err) { break; }

    } while(0);

    if (marked_busy)
    {
        // Clear the busy state (write 1 to toggle). Note if we get
        // an error from the writeLPC, we toss it and return the first
        // error as it likely has better information in it.
        delete writeLPC(REG_CONTROL, CTRL_H_BUSY);
    }

    mutex_unlock(&iv_mutex);

    IPMI_TRAC(INFO_MRK "read %s %s %x:%x seq %x len %x cc %x",
              (ctrl & CTRL_B2H_ATN) ? "b2h" : "sms",
              err ? "err" : "ok",
              o_msg->iv_netfun, o_msg->iv_cmd, o_msg->iv_seq,
              o_msg->iv_len, o_msg->iv_cc);

    return err;
}

/**
 * @brief  Constructor
 */
IpmiDD::IpmiDD(void):
    iv_eagains(false)
{
    mutex_init(&iv_mutex);

    // reset the BT interface - no idea what state the BMC thinks things are in
    errlHndl_t err = reset();
    if (err)
    {
        IPMI_TRAC(ERR_MRK "error resetting the BT interface");
        err->collectTrace(IPMI_COMP_NAME);
        errlCommit(err, IPMI_COMP_ID);
    }

    // Start task to poll the control register
    // This is a singleton so this will only be called once, right?
    task_create( poll_control_register, NULL );

    return;
}
