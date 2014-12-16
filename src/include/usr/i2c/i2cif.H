/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/i2cif.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
#ifndef __I2CIF_H
#define __I2CIF_H

namespace I2C
{

/**
 * @brief This function will handle everything required to setup the master
 *      engines on the processor.
 *      Mainly, as of current code, this is being used to write the I2C Bus
 *      Divisor values to the master engines to be used by Phyp.
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cSetupMasters ( void );

/**
 * @enum i2cResetType
 *
 * @brief I2C Reset Type specifies what is reset when i2cResetMasters() is called
 */
enum i2cResetType
{
    I2C_RESET_INVALID,
    I2C_RESET_ALL,
    I2C_RESET_PROC_ALL,
    I2C_RESET_PROC_FSI,
    I2C_RESET_PROC_HOST,
    I2C_RESET_MEMBUF_ALL,
    I2C_RESET_MEMBUF_FSI,
    I2c_RESET_MEMBUF_HOST
};

/**
 * @brief This function will handle everything required to reset various
 *        I2C master engines.
 *
 * @param[in] i_resetType - Specfies which I2C master engines to reset
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cResetMasters ( i2cResetType i_resetType );


/**
 * @brief This function will determine if a given I2C device is present
 *
 * @param[in] i_target - The target device
 * @param[in] i_port - The device's port
 * @param[in] i_engine - The device's engine number
 * @param[in] i_devAddr - The device's address
 *
 * @return bool - True if chip is present, False otherwise.
 */
bool i2cPresence( TARGETING::Target * i_target,
                        uint64_t i_port,
                        uint64_t i_engine,
                        uint64_t i_devAddr );


/**
* @enum i2cSetAccessModeType
*
* @brief I2C Set Access Mode Type specifies what targets will be set to
*        a specific I2C Access Mode (Host or FSI)
*
*/
enum i2cSetAccessModeType
{
    I2C_SET_ACCESS_MODE_INVALID                   = 0x00,
    I2C_SET_ACCESS_MODE_PROC_HOST                 = 0x01
};


/**
 * @brief This function will set the I2C_SWITCH attribute for certain
 *        targets to a specific mode (Host or FSI) based on the input.
 *
 * @param i2cSetModeType  - Specifies which targets to be set and which
 *                          mode to set them to
 */
void i2cSetAccessMode( i2cSetAccessModeType i_setModeType );


};  // end namespace I2C

#endif  // end __I2CIF_H
