/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/ast_mboxdd.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2017                        */
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
#ifndef __AST_MBOXDD_H
#define __AST_MBOXDD_H

#include <limits.h>
#include <config.h>

/** @file ast_mboxdd.H
 *  @brief Provides the interfaces Aspeed MBOX hardware
 */

/**
 *  @brief  AST Mbox Device Driver Class
 *          Provides the interface to exchange Mbox
 *          messages with the BMC.
 */
class astMbox
{
    public:

        enum
        {
            BMC_MBOX_DATA_REGS              = 14,
            BMC_MBOX_ARGS_REGS              = 11,

            /* Commands */
            MBOX_C_RESET_STATE              = 0x01,
            MBOX_C_GET_MBOX_INFO            = 0x02,
            MBOX_C_GET_FLASH_INFO           = 0x03,
            MBOX_C_CREATE_READ_WINDOW       = 0x04,
            MBOX_C_CLOSE_WINDOW             = 0x05,
            MBOX_C_CREATE_WRITE_WINDOW      = 0x06,
            MBOX_C_MARK_WRITE_DIRTY         = 0x07,
            MBOX_C_WRITE_FLUSH              = 0x08,
            MBOX_C_BMC_EVENT_ACK            = 0x09,
            MBOX_C_MARK_WRITE_ERASED        = 0x0a,

            /* Responses */
            MBOX_R_SUCCESS                  = 0x01,
            MBOX_R_PARAM_ERROR              = 0x02,
            MBOX_R_WRITE_ERROR              = 0x03,
            MBOX_R_SYSTEM_ERROR             = 0x04,
            MBOX_R_TIMEOUT                  = 0x05,
            MBOX_R_BUSY                     = 0x06,
            MBOX_R_WINDOW_ERROR             = 0x07,
        };

        /**
         *  @brief AST Mbox message class.
         *         Encapsulates a mailbox message and provides
         *         accessors to read/write 8, 16 and 32-bit
         *         quantities in the right endianness at
         *         specified offsets of the "args" section.
         */
        class mboxMessage
        {
            public:

                mboxMessage( uint8_t i_cmd )
                {
                    iv_cmd = i_cmd;
                }

                uint8_t iv_cmd;
                uint8_t iv_seq;
                uint8_t iv_args[BMC_MBOX_ARGS_REGS];
                uint8_t iv_resp;

                inline uint8_t get8( uint8_t i_index )
                {
                    assert( i_index < BMC_MBOX_ARGS_REGS);
                    return iv_args[i_index];
                }

                inline void put8( uint8_t i_index, uint8_t i_value )
                {
                    assert( i_index < BMC_MBOX_ARGS_REGS);
                    iv_args[i_index] = i_value;
                }

                inline uint16_t get16( uint8_t i_index )
                {
                    assert( i_index < (BMC_MBOX_ARGS_REGS - 1));
                    return iv_args[i_index] | (iv_args[i_index + 1] << 8);
                }

                inline void put16( uint8_t i_index, uint16_t i_value )
                {
                    assert( i_index < (BMC_MBOX_ARGS_REGS - 1));
                    iv_args[i_index] = i_value & 0xff;
                    iv_args[i_index + 1] = i_value >> 8;
                }

                inline uint32_t get32( uint8_t i_index )
                {
                    assert( i_index < (BMC_MBOX_ARGS_REGS - 3));
                    return iv_args[i_index] |
                           (iv_args[i_index + 1] << 8) |
                           (iv_args[i_index + 2] << 16) |
                           (iv_args[i_index + 3] << 24);
                }

                inline void put32( uint8_t i_index, uint32_t i_value )
                {
                    assert( i_index < (BMC_MBOX_ARGS_REGS - 3));
                    iv_args[i_index] = i_value & 0xff;
                    iv_args[i_index + 1] = (i_value >> 8) & 0xff;
                    iv_args[i_index + 2] = (i_value >> 16) & 0xff;
                    iv_args[i_index + 3 ] = i_value >> 24;
                }
        };

        /**
         *  @brief Send a message and receive the response
         *
         *  @parm[in/out] io_msg  Message to send, contains the response on exit
         */
        errlHndl_t doMessage( mboxMessage& io_msg );

        /**
         * @brief Constructor
         *
         * @parm i_target     Processor Target
         *       NOTE: i_target can only be used after targeting is loaded
         */
        astMbox( TARGETING::Target* i_target = NULL );

        /**
         * @brief Destructor
         */
        ~astMbox();

    private:

        enum
        {
            MBOX_FLAG_REG               = 0x0f,
            MBOX_STATUS_0               = 0x10,
            MBOX_STATUS_1               = 0x11,
            MBOX_STATUS1_ATTN           = 0x80,
            MBOX_STATUS1_RESP           = 0x20,
            MBOX_BMC_CTRL               = 0x12,
            MBOX_CTRL_INT_STATUS        = 0x80,
            MBOX_CTRL_INT_MASK          = 0x02,
            MBOX_CTRL_INT_SEND          = 0x01,
            MBOX_HOST_CTRL              = 0x13,
            MBOX_BMC_INT_EN_0           = 0x14,
            MBOX_BMC_INT_EN_1           = 0x15,
            MBOX_HOST_INT_EN_0          = 0x16,
            MBOX_HOST_INT_EN_1          = 0x17,

            MBOX_IO_BASE                = 0x1000,
            MBOX_LPC_IRQ                = 0x9,

            MBOX_MAX_RESP_WAIT_US       = 10000000, /* 10s timeout */
        };

        /**
         * @brief Initialize/Enable the MBox in the SIO
         */
        errlHndl_t initializeMbox( void );

        /**
         * @brief Write a byte to the mBox
             *
             * @parm[in] i_addr: Register offset in the mbox
             * @parm[in] i_byte: Byte to write
         */
        errlHndl_t mboxOut( uint64_t i_addr, uint8_t i_byte );

        /**
         * @brief Read a byte from the mBox
             *
             * @parm[in] i_addr: Register offset in the mbox
             * @parm[out] o_byte: Byte read
         */
        errlHndl_t mboxIn( uint64_t i_addr, uint8_t& o_byte );

        /**
         * @brief Processor Target used to access LPC device
         *
         */
        TARGETING::Target* iv_target;

        /**
         * @brief Sequence number for mailbox messages
         */
        uint8_t iv_mboxMsgSeq;
};

#endif /* __AST_MBOXDD_H */
