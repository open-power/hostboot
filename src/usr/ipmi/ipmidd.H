/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmidd.H $                                       */
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
#ifndef __IPMI_IPMIDD_H
#define __IPMI_IMPIDD_H

#include <sys/msg.h>
#include <ipmi/ipmiif.H>
#include "ipmibt.H"

/** @file ipmidd.H
 *  @brief Provides the interfaces to the IPMI Device Driver
 */

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
     * @brief True if we told the RP to try a write again
     */
    bool iv_eagains;

    // Disallow copying this class.
    IpmiDD& operator=(const IpmiDD&);
    IpmiDD(const IpmiDD&);
};


#endif
