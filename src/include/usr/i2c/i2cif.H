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
 *      engines.
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
*        @todo RTC 115832 - additional enums will be added
*
*/
enum i2cResetType
{
    I2C_RESET_INVALID                   = 0x00,
    I2C_RESET_PROC_HOST                 = 0x01, // Only Host (not FSI)
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

};  // end namespace I2C

#endif  // end __I2CIF_H
