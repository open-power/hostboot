/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sio/siodd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#ifndef __SIO_SIODD_H
#define __SIO_SIODD_H

#include <limits.h>
#include <sys/sync.h>
#include <stdint.h>
#include <errl/errlentry.H>
#include <lpc/lpcif.H>
#include <targeting/common/targetservice.H>

/**
 * class describing accesses to AST2400 BMC chip
 */
class SioDD
{
    public:
        /** @brief  Constructor
         * @param[in] i_target: SIO target
         */
        SioDD(TARGETING::Target* i_target =
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

        /* @brief Destructor */
        ~SioDD();

        /**
         * @brief Read a single byte from a SIO register
         * @param[in] i_target: SIO target
         * @param[in] i_dev: Device to read from
         * @param[in] i_reg: Register to read
         * @param[in] o_byte: Data that was read
         *
         * @return Error from operation
         */
        errlHndl_t readSIO(TARGETING::Target* i_target,
                uint8_t i_dev, uint8_t i_reg, uint8_t* o_byte);

        /**
         * @brief Write a single byte into a SIO register
         * @param[in] i_target: SIO target
         * @param[in] i_dev: Device to write to
         * @param[in] i_reg: Register to write
         * @param[in] i_data: Data to write
         *
         * @return Error from operation
         */
        errlHndl_t writeSIO(TARGETING::Target* i_target,
                uint8_t i_dev, uint8_t i_reg, uint8_t* i_data);

        /**
         * @brief AHB SIO read operation
         * @param[in] i_target: SIO target
         * @param[in] i_reg: Register to read
         * @param[in] o_data: Data that was read
         *
         * @return Error from operation
         */
        errlHndl_t ahbSioRead(TARGETING::Target* i_target,
                uint32_t i_reg, uint32_t* o_data);

        /**
         * @brief AHB SIO write operation
         * @param[in] i_target: SIO target
         * @param[in] i_reg: Register to write
         * @param[in] i_val: Data to write
         *
         * @return Error from operation
         */
        errlHndl_t ahbSioWrite(TARGETING::Target* i_target,
                uint32_t i_reg, uint32_t* i_val);

        friend class SioDDTest;

    private:
        /**
         * @brief Change device pointed to by SIO
         * @param[in] i_target: SIO target
         * @param[in] i_dev: Device to point to
         *
         * @return Error from operation
         */
        errlHndl_t changeDevice(TARGETING::Target* i_target,
                uint8_t i_dev);

        /**
         * @brief Internal write function
         * assumes mutex is locked
         * @param[in] i_target: SIO target
         * @param[in] i_reg: Register to write
         * @param[in] i_data: Data to write
         *
         * @return Error from operation
         */
        errlHndl_t _writeSIO(TARGETING::Target* i_target,
                uint8_t i_reg, uint8_t* i_data);

        /**
         * @brief Internal read function
         * assumes mutex is locked
         * @param[in] i_target: SIO target
         * @param[in] i_reg: Register to read
         * @param[in] o_byte: Data that was read
         *
         * @return Error from operation
         */
        errlHndl_t _readSIO(TARGETING::Target* i_target,
                uint8_t i_reg, uint8_t* o_byte);

        /**
         * @brief LPC to AHB address translation
         * @param[in] i_target: SIO target
         * @param[in] i_addr: Address for subsequent AHB SIO read/write
         *
         * @return Error from operation
         */
        errlHndl_t _ahbSioAddrPrep(TARGETING::Target* i_target,
                uint32_t i_addr);

        /**
         * @brief Internal write function
         * assumes mutex is locked
         * @param[in] i_target: SIO target
         * @param[in] i_reg: Register to write to
         * @param[in] i_val: Data that is to be written
         *
         * @return Error from operation
         */
        errlHndl_t _ahbSioWrite(TARGETING::Target* i_target,
                uint32_t i_reg, uint32_t* i_val);

        /**
         * @brief Internal read function
         * assumes mutex is locked
         * @param[in] i_target: SIO target
         * @param[in] i_reg: Register to read from
         * @param[in] i_val: Data that was read
         *
         * @return Error from operation
         */
        errlHndl_t _ahbSioRead(TARGETING::Target* i_target,
                uint32_t i_reg, uint32_t* o_data);

        /**
         * @brief Unlock SIO password register
         * @param[in] i_target: SIO target
         *
         * @return Error from operation
         */
        errlHndl_t unlock_SIO(TARGETING::Target* i_target);

        /**
         * @brief Previous device accessed by SIO
         */
        uint8_t iv_prev_dev;

        /**
         * @brief Mutex to prevent concurrent accesses to SIO
         */
        mutex_t iv_sio_mutex;
    };
#endif
