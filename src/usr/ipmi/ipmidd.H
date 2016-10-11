/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmidd.H $                                       */
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
#ifndef __IPMI_IPMIDD_H
#define __IPMI_IMPIDD_H

#include <sys/msg.h>
#include <ipmi/ipmiif.H>
#include "ipmibt.H"

/** @file ipmidd.H
 *  @brief Provides the interfaces to the IPMI Device Driver
 */

enum {
    // Registers. These are fixed for LPC/BT so we can hard-wire them
    REG_CONTROL = 0xE4,
    REG_HOSTBMC = 0xE5,
    REG_INTMASK = 0xE6,

    // Control register bits. The control register is interesting in that
    // writing 0's never does anything; all registers are either set to 1
    // when written with a 1 or toggled (1/0) when written with a one. So,
    // we don't ever need to read-modify-write, we can just write an or'd
    // mask of bits.
    CTRL_B_BUSY        = (1 << 7),
    CTRL_H_BUSY        = (1 << 6),
    CTRL_OEM0          = (1 << 5),
    CTRL_SMS_ATN       = (1 << 4),
    CTRL_B2H_ATN       = (1 << 3),
    CTRL_H2B_ATN       = (1 << 2),
    CTRL_CLR_RD_PTR    = (1 << 1),
    CTRL_CLR_WR_PTR    = (1 << 0),

    IDLE_STATE = (CTRL_B_BUSY | CTRL_B2H_ATN |
                  CTRL_SMS_ATN | CTRL_H2B_ATN),

    // Bit in the INMASK register which signals to the BMC
    // to reset it's end of things.
    INT_BMC_HWRST      = (1 << 7),

    // How long to sychronously wait for the device to change state (in ns)
    WAIT_TIME = 100000000,
};

/**
 *  @brief IPMI Device Driver Class
 *     Provides read/write message capabilities.
 */
class IpmiDD
{
  public:
    /**
     * @brief Poll the control register
     *
     * @parm void
     */
    void pollCtrl(void);

    /**
     * @brief Performs an IPMI message read operation
     *
     * @param[out] o_msg - Destination buffer for data
     *
     * @return errlHndl_t  NULL on success
     */

    errlHndl_t receive(IPMI::BTMessage* o_msg);

    /**
     * @brief Performs an IPMI message write operation
     *
     * @param[in] i_msg - Location of data to be written
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t send(IPMI::BTMessage* i_msg);

    /**
     * @brief Performs a reset of the BT hardware
     *
     * @param void
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t reset(void);

    /**
     * @brief shutdown the device driver
     */
    void handleShutdown(void);

    /**
     * @brief Constructor
     *
     * @parm void
     */
    IpmiDD(void);

  private:
    /**
     * @brief Read an address from LPC space
     *
     * @parm i_addr  Absolute LPC Address
     * @parm o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    errlHndl_t readLPC(const uint32_t i_addr, uint8_t& o_data);

    /**
     * @brief Write an address from LPC space
     *
     * @parm i_addr  Absolute LPC Address
     * @parm i_data  Data to write
     *
     * @return Error from operation
     */
    errlHndl_t writeLPC(const uint32_t i_addr, uint8_t i_data);

  private: // Variables

    /**
     * @brief Mutex used to protect internal state
     */
    mutex_t iv_mutex;

    /**
     * @brief Shut down resources
     */
    bool iv_shutdown_now;

    /**
     * @brief True if we told the RP to try a write again
     */
    bool iv_eagains;

    // Disallow copying this class.
    IpmiDD& operator=(const IpmiDD&);
    IpmiDD(const IpmiDD&);
};


#endif
