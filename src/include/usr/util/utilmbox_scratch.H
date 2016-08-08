/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utilmbox_scratch.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
#ifndef UTILMBOX_SCRATCH_H
#define UTILMBOX_SCRATCH_H

/**
 * @file utilmbox_scratch.H
 *
 * @brief Utilies to manipulate mbox scratch debug communication
 *
 * Used for creating and manipulating memory streams
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <initservice/mboxRegs.H>

// Utility Includes

/*****************************************************************************/
// Forwards
/*****************************************************************************/

//*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/
namespace Util
{
    enum
    {
        MSG_TYPE_MASK           =       0xE0000000,
        MSG_COUNT_MASK          =       0x1F000000,
        MSG_USAGE_MASK          =       MSG_TYPE_MASK | MSG_COUNT_MASK,
        MSG_USAGE_SHIFT         =       24,
        MSG_DATA_SIZE_MASK      =        ~MSG_USAGE_MASK,

        MSG_TYPE_TRACE          =       0x00,
        MSG_TYPE_ATTRDUMP       =       0x01,

    };

    /**
     * @brief This places the address and buffer size for the debug tool
     * into the mailbox scratch regs in a synchronous fashion.  It will also
     * wait for the tool to ack the reciept of data before returning
     *
     * @param[in] i_usage       1 byte of "usage" data.  Caller defined
     * @param[in] i_addr        Physical real address of buffer
     * @param[in] i_size        Size of data in bytes
     *
     * @return none
     */
    void writeDebugCommRegs(uint8_t i_usage, uint32_t i_addr, uint32_t i_size);

    /**
     * @brief This function writes data to mailbox scratch reg
     *  These scom addresses are always accessible and any errors are commited
     *  internally
     * @param[in] i_addr        Scom address of mailbox reg to write
     * @param[in] i_data        Data to write to mailbox
     *
     * @return none
     */
    void writeScratchReg(uint64_t i_addr, uint32_t i_data);

    /**
     * @brief This function reads data to mailbox scratch reg
     *  These scom addresses are always accessible and any errors are commited
     *  internally
     * @param[in] i_addr        Scom address of mailbox reg to read
     *
     * @return Data in mailbox scratch reg
     */
    uint32_t readScratchReg(uint64_t i_addr);
};

#endif //UTILMEM_H
