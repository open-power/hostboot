/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/fapi_i2c_dd.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __FAPII2CDD_H
#define __FAPII2CDD_H

#include <errl/errlentry.H>
#include <i2c/i2cif.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>

namespace FAPI_I2C_DD
{
    /**
     * @brief Perform a FAPI i2c operation
     *
     * @param[in] i_optype - Operation Type - @see devicefw/userif.H
     * @param[in] i_target - Target device (contains attr with fapiI2c info)
     * @param[in/out] io_buffer - Ptr to data buffer to be written/read into
     * @param[in/out] io_buflen - Length of the data buffer
     * @param[in] i_accessType @see devicefw/userif.H
     * @param[in] i_args Device argument list.
     *                   ConfigDataSize as size_t
     *                   ConfigData as uint8_t*
     *
     *
     * @return errlHndl_t  NULL on success or error handle on error.
     */
    errlHndl_t fapiI2cPerformOp(DeviceFW::OperationType i_opType,
                                TARGETING::Target * i_target,
                                void * io_buffer,
                                size_t & io_buflen,
                                int64_t i_accessType,
                                va_list i_args);

    /**
     * @brief Read from a i2c device and port
     *
     * @param[in] i_target - Target of the i2c master for this i2c device
     * @param[in] i_data   - Configuration data to write before the read
     * @param[out] o_buffer - Buffer to contain what was read
     * @param[in] i_i2cInfo - i2c addressing information
     *
     * @return errlHndl_t - Null on Success or error handle on error
     */
    errlHndl_t i2cRead( TARGETING::Target * i_target,
                        void * o_buffer,
                        size_t & io_buffer_size,
                        TARGETING::ATTR_FAPI_I2C_CONTROL_INFO_type * i_i2cInfo,
                        uint8_t * i_offset_data,
                        const size_t i_offset_data_size );

    /**
     * @brief Write to an i2c target
     *
     * @param[in] i_target - Target of the i2c master for this i2c device
     * @param[in] i_buffer - Buffer containing the value to write
     * @param[in] io_buffer_size - Number of bytes to write
     *                             Returns number of bytes written
     * @param[in] i_i2cInfo - i2c addressing information
     *
     * @return errlHndl_t - NULL on Success or error handle on error
     */
    errlHndl_t i2cWrite( TARGETING::Target * i_target,
                       void * i_buffer,
                       size_t & io_buffer_size,
                       TARGETING::ATTR_FAPI_I2C_CONTROL_INFO_type * i_i2cInfo );


    /**
     * @brief Read the FAPI I2C attributes associated with target
     *
     * @param[in] i_target - Target that contains the attritutes for the device
     * @param[in/out] io_i2cInfo I2C address information.
     *
     * @return errlHndl_t - NULL on Success or error handle on error
     */
    errlHndl_t readI2cAttributes ( TARGETING::Target * i_target,
                      TARGETING::ATTR_FAPI_I2C_CONTROL_INFO_type &io_i2cInfo );
};

#endif
