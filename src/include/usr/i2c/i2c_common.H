/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/i2c_common.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
#ifndef __I2C_COMMON_H
#define __I2C_COMMON_H

#include <devicefw/driverif.H>
/**
 * @file i2c_common.H
 *
 * @brief Provides the interfaces for the i2c device driver common with runtime
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------

namespace I2C
{

/**
 * @brief enums for ONE_BYTE_ADDR_PAGESELECT EEPROMs
 */
enum eepromPage_t : uint8_t
{
    PAGE_ZERO = 0x0,
    PAGE_ONE = 0x1,
    PAGE_UNKNOWN = 0x2,
};

enum eepromPageAddr_t
{
    PAGE_ZERO_ADDR = 0x6C,
    PAGE_ONE_ADDR  = 0x6E,
};

struct Smbus_t
{
    uint8_t commandCode; // Command for read/write block operations
    bool    usePec;      // Whether to use PEC byte or not
};

/**
 * @brief Structure used to pass important variables between functions
 */
struct misc_args_t
{
    DeviceFW::I2C_SUBOP subop; ///< Sub-operation to perform
    uint8_t  port;
    uint8_t  engine;
    uint64_t devAddr;
    bool     skip_mode_setup;
    bool     with_stop;
    bool     read_not_write;
    bool     with_address;      ///< Send address
    bool     with_start;        ///< Send start bit
    bool     read_continue;     ///< Allow one logical read across multiple I2C
                                ///< ops.  Set when next read will be tied to
                                ///< current read
    uint64_t bus_speed;          ///< in kbits/sec (ie 400KHz)
    uint16_t bit_rate_divisor;   ///< uint16_t to match size in mode register
    uint64_t polling_interval_ns;  ///< in nanoseconds
    uint64_t timeout_count;
    uint64_t offset_length;
    uint8_t* offset_buffer;
    uint8_t  i2cMuxBusSelector;
    const    TARGETING::EntityPath* i2cMuxPath;

    TARGETING::I2cSwitches switches;

    Smbus_t  smbus;

    misc_args_t():subop(DeviceFW::I2C_STANDARD),
                  port(0xFF),
                  engine(0xFF),
                  devAddr(0xFFFFFFFF),
                  skip_mode_setup(false),
                  with_stop(true),
                  read_not_write(true),
                  with_address(true),
                  with_start(true),
                  read_continue(false),
                  bus_speed(0),
                  bit_rate_divisor(0),
                  polling_interval_ns(0),
                  timeout_count(0),
                  offset_length(0),
                  offset_buffer(nullptr),
                  i2cMuxBusSelector(I2C_MUX::NOT_APPLICABLE),
                  i2cMuxPath(nullptr),
                  smbus( {0,true} )
                  {
                      memset(&switches, 0x0, sizeof(switches));
                  };

};

}; // end I2C namespace

#endif  // __I2C_COMMON_H
