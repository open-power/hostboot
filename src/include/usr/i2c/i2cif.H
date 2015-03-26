/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/i2cif.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

// @todo RTC 125540 - Ensure no possible Centaur i2c collisions during HB IPL
//                    Need to re-evaluate the ifdef/ifndef in this file
#ifndef __HOSTBOOT_RUNTIME
/**
 * @enum i2cProcessType
 *
 * @brief I2C Process Type specifies which targets and which I2C master
 *        engines are reset or setup
 *
 * Specifically:
 *
 * _PROC_   --> loops through the processors in the system
 * _MEMBUF_ --> loops through membufs in the system
 *
 * _HOST_   --> only does the reset if target's active engine is in Host mode
 * _FSI_    --> only does the reset if target's active engine is in FSI mode
 * [NOTE: active engine is determined by target's I2C_SWITCHES attribute]
 *
 * _ALL     --> combines one or more of the PROC/MEMBUF and HOST/FSI pairs
 *
 */
enum i2cProcessType
{
    // used to create function-specific enums below
    I2C_RANGE_HOST    = 0x01,
    I2C_RANGE_FSI     = 0x02,
    I2C_RANGE_PROC    = 0x04,
    I2C_RANGE_MEMBUF  = 0x08,

    // external interface for i2cResetActiveMasters and i2cSetupActiveMasters
    I2C_PROC_HOST = I2C_RANGE_PROC | I2C_RANGE_HOST,
    I2C_PROC_FSI  = I2C_RANGE_PROC | I2C_RANGE_FSI,
    I2C_PROC_ALL  = I2C_PROC_HOST | I2C_PROC_FSI,

    I2C_MEMBUF_HOST = I2C_RANGE_MEMBUF | I2C_RANGE_HOST,
    I2C_MEMBUF_FSI  = I2C_RANGE_MEMBUF | I2C_RANGE_FSI,
    I2C_MEMBUF_ALL  = I2C_MEMBUF_HOST  | I2C_MEMBUF_FSI,

    I2C_ALL = I2C_PROC_ALL | I2C_MEMBUF_ALL,
};

/**
 * @brief This function will handle everything required to reset a target's
 *        "active" I2C master engine.
 * [NOTE: "active" engine is determined by target's I2C_SWITCHES attribute]
 *
 *
 * @param[in] i_resetType - Specfies which targets and which I2C master engines
 *                          to reset
 *                          (see i2cProcessType description above)
 *
 * @param[in] i_functional - Specfies if reset is performed on functional or
 *                           any existing targets that match the i_resetType
 *                           if true - functional targets
 *                           if false - existing targets
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cResetActiveMasters ( i2cProcessType i_resetType,
                                   bool i_functional = true );

/**
 * @brief This function will handle everything required to setup a target's
 *        "active" I2C master engine.
 * [NOTE: "active" engine is determined by target's I2C_SWITCHES attribute]
 *
 *
 * @param[in] i_setupType - Specfies which targets and which I2C master engines
 *                          to setup
 *                          (see i2cProcessType description above)
 *
 * @param[in] i_functional - Specfies if setup is performed on functional or
 *                           any existing targets that match the i_resetType
 *                           if true - functional targets
 *                           if false - existing targets
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cSetupActiveMasters ( i2cProcessType i_setupType,
                                   bool i_functional = true );


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



/**
 * @brief Define a set of information about the I2C masters
 *   (primarily used to populate the devtree)
 */
struct MasterInfo_t
{
    uint64_t scomAddr; //< Base scom address for control regs
    uint8_t engine;    //< Engine number
    uint32_t freq;     //< Local Bus frequency of master in Hz
};

/**
 * @brief Return a set of information related to each I2C master on
 *   the given target chip
 *
 * @param[in] i_chip - I2C Master chip (proc or membuf)
 * @param[out] o_info - list of I2C Information
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
void getMasterInfo( const TARGETING::Target* i_chip,
                    std::list<MasterInfo_t>& o_info );
#endif // !__HOSTBOOT_RUNTIME

#ifdef __HOSTBOOT_RUNTIME
/**
 * @brief This function disables the OCC sensor cache for the specified target
 *
 * @param[in] i_target - I2C Master Target device
 * @param[out] o_disabled - Indicates the sensor cache was enabled
 *                          and is now disabled
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cDisableSensorCache( TARGETING::Target * i_target,
                                  bool & o_disabled );

/**
 * @brief This function enables the OCC sensor cache for the specified target
 *
 * @param[in] i_target - I2C Master Target device
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t i2cEnableSensorCache( TARGETING::Target * i_target );
#endif //__HOSTBOOT_RUNTIME

};  // end namespace I2C

#endif  // end __I2CIF_H
