/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/i2c.H $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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

// Handy macros to check i2c ranges
//  Pass in an instance of a TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type
#define I2C_BUS_MAX_ENGINE(var) (sizeof(var)/sizeof(var[0]))
#define I2C_BUS_MAX_PORT(var)   (sizeof(var[0])/sizeof(var[0][0]))

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
 * @brief Structure used to pass important variables between functions
 */
struct misc_args_t
{
    uint8_t  port;
    uint8_t  engine;
    uint64_t devAddr;
    bool     skip_mode_setup;
    bool     with_stop;
    bool     read_not_write;
    uint64_t bus_speed;          // in kbits/sec (ie 400KHz)
    uint16_t bit_rate_divisor;   // uint16_t to match size in mode register
    uint64_t polling_interval_ns;  // in nanoseconds
    uint64_t timeout_count;
    uint64_t offset_length;
    uint8_t* offset_buffer;

    TARGETING::I2cSwitches switches;

    misc_args_t():port(0xFF),
                  engine(0xFF),
                  devAddr(0xFFFFFFFF),
                  skip_mode_setup(false),
                  with_stop(true),
                  read_not_write(true),
                  bus_speed(0),
                  bit_rate_divisor(0),
                  polling_interval_ns(0),
                  timeout_count(0),
                  offset_length(0),
                  offset_buffer(NULL){};

};

}; // end I2C namespace

#endif  // __I2C_COMMON_H
