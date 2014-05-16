/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/gpio/gpiodd.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
/* [+] Google Inc.                                                        */
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
#ifndef __GPIODD_H
#define __GPIODD_H

#include <errl/errlentry.H>
#include <gpio/gpioif.H>


namespace GPIO
{
    struct gpioAddr_t
    {
        TARGETING::EntityPath i2cMasterPath;
        uint8_t deviceType; //!< device type
        uint8_t portAddr;
        uint8_t i2cPort;
        uint8_t engine;
        uint8_t i2cDeviceAddr;
    };

    /**
     * @brief Perform a GPIO operation
     *
     * @param[in] i_optype - Operation Type - @see devicefw/userif.H
     * @param[in] i_target - Target device
     * @param[in/out] io_buffer - Ptr to data buffer to be written/read into
     * @param[in/out] io_buflen - Length of the data buffer
     * @param[in] i_accessType @see devicefw/userif.H
     * @param[in] i_args Device arguement list. Gpio Device type,
     *            Gpio port address
     *
     * @return errlHndl_t  NULL on success or error handle on error.
     */
    errlHndl_t gpioPerformOp(DeviceFW::OperationType i_opType,
                             TARGETING::Target * i_target,
                             void * io_buffer,
                             size_t & io_buflen,
                             int64_t i_accessType,
                             va_list i_args);

    /**
     * @brief Read from a gpio device and port
     *
     * @param[in] i_target - Target of the i2c master for this gpio device
     * @param[out] o_buffer - Buffer to contain the value of the gpio port
     * @param[in/out] io_buflen - in: Size of the buffer, out: bytes actually
     *                read
     * @param[in] gpioInfo - gpio addressing information @see gpioAddr_t
     *
     * @return errlHndl_t - Null on Success or error handle on error
     */
    errlHndl_t gpioRead( TARGETING::Target * i_target,
                         void * o_buffer,
                         size_t & io_buflen,
                         gpioAddr_t & i_gpioInfo);

    /**
     * @brief Write to a gpio device and port
     *
     * @param[in] i_target - Target of the i2c master for this gpio device
     * @param[in] i_buffer - Buffer containing the value to write
     * @param[in] i_buflen - Number of bytes to write
     * @param[in] gpioInfo - gpio addressing information @see gpioAddr_t
     *
     * @return errlHndl_t - NULL on Success or error handle on error
     */
    errlHndl_t gpioWrite( TARGETING::Target * i_target,
                          void * i_buffer,
                          size_t i_buflen,
                          gpioAddr_t & i_gpioInfo);


    /**
     * @brief Read the GPIO attributes
     *
     * @param[in] i_target - Target that contains the attritutes for the device
     * @param[in/out] gpioAddr_t GPIO address information. @see gpioAddr_t
     *
     * @return errlHndl_t - NULL on Sucess or error handle on error
     */
    errlHndl_t gpioReadAttributes ( TARGETING::Target * i_target,
                                    gpioAddr_t & io_gpioInfo);
};

#endif
