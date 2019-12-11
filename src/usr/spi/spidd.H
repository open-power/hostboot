/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/spidd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#ifndef __SPIDD_H
#define __SPIDD_H

/**
 *
 * @file spidd.H
 *
 * @brief Provides the interfaces for the Serial Peripheral Interface (SPI)
 *        device driver
 *
 */
// -----------------------------------------------------------------------------
//      Includes
// -----------------------------------------------------------------------------
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <targeting/common/targetservice.H>

namespace SPI
{

struct spi_misc_args_t
{
    // SPI Master Engine to use
    uint8_t engine;

    // The read or write offset.
    uint64_t offset;

    spi_misc_args_t()
        : engine(0),
          offset(0)
        {}
};

/**
 * @brief Initialize SPI Device Driver. Initializes engine mutexes and forces
 *        SPI Master to use PIB.
 */
void spiInit(errlHndl_t &io_rtaskRetErrl);

/**
  *
  * @brief Perform a SPI access operation. It follows a pre-defined prototype
  *        function in order to be registered with the device driver framework.
  *
  * @param[in] i_opType       Operation Type. See DeviceFW::OperationType in
  *                           driverif.H
  *
  * @param[in] i_target       SPI Master Target.
  *
  * @param [in/out] io_buffer INPUT: Pointer to the data that will be written to
  *                                  the target device.
  *                           OUTPUT: Pointer to the data that was read from the
  *                                   target device.
  *
  * @param [in/out] io_buflen INPUT: Length of the buffer to be written to
  *                                  target device.
  *                           OUTPUT: Length of buffer that was written, or
  *                                   length of buffer to be read from target
  *                                   device.
  *
  * @param [in] i_accessType  Access Type. See DeviceFW::AccessType in userif.H
  *
  * @param [in] i_args        This is an argument list for the device driver
  *                           framework.  This list of arguments is documented
  *                           in driverif.H.
  *
  * @return     errlHndl_t    nullptr if successful, otherwise a pointer to the
  *                           error log.
  *
  */
errlHndl_t spiPerformOp(DeviceFW::OperationType i_opType,
                        TARGETING::Target*      i_target,
                        void*                   io_buffer,
                        size_t&                 io_buflen,
                        int64_t                 i_accessType,
                        va_list                 i_args);

}; // end namespace SPI
#endif
