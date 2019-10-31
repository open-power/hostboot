/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/spidd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include <fapi2.H>

// @TODO RTC 208787 Update when SBE code is finalized.
#include <p10_sbe_spi_cmd.H>

namespace SPI
{

// The number of bytes a SPI transaction must be aligned to.
const size_t TRANSACTION_ALIGNMENT = 8;

class SpiOp
{
    TARGETING::Target* iv_target;

    // The requested read or write offset.
    uint64_t iv_offset;

    // The length of the request.
    size_t iv_length;

    // The engine to use for this Op
    uint8_t iv_engine;

    // The adjusted offset to read or write to.
    // This must always be a multiple of TRANSACTION_ALIGNMENT
    uint64_t iv_adjusted_offset;

    // The adjusted length of the buffer to be sent in a SPI read/write
    // transaction. This must always be a multiple of TRANSACTION_ALIGNMENT.
    uint64_t iv_adjusted_length;

    // The index into the adjusted buffer where the requested data starts.
    uint64_t iv_start_index;

    // Determines if an adjusted buffer is in use. If the operation wasn't
    // aligned then an adjusted buffer would be necessary.
    bool iv_usingAdjustedBuffer;

    // Will point to the output buffer given in spiPerformOp or if
    // iv_usingAdjustedBuffer is set to true then it will point to an adjusted
    // buffer.
    uint8_t * iv_buffer;

    /**
     * @brief Sets the adjusted buffer parameters. This determine if the
     *        requested operation was aligned and will calculate the appropriate
     *        adjusted parameters. This includes creating a new adjusted buffer
     *        to hold the information gathered by using the adjust parameters.
     *        Otherwise, if the op is aligned then the internal buffer pointer
     *        will point to the same buffer as the original request.
     *
     * @param[in]   i_buffer   Will be used to initialize iv_buffer if
     *                         necessary.
     */
    void setAdjustedOpArgs(void * i_buffer);

public:

    /**
     *  @brief Constructor that creates a SpiOp object. This constructor will
     *         initialize all member variables based on whether the requested
     *         operation is aligned by TRANSACTION_ALIGNMENT.
     *
     *  @param[in]  i_target    Initializes iv_target.
     *
     *  @param[in]  i_engine    Initializes iv_engine.
     *
     *  @param[in]  i_offset    Initializes i_offset and used to calculate
     *                          iv_adjusted_offset and iv_start_index.
     *
     *  @param[in]  i_buflen    Initializes iv_length and used to calculate
     *                          iv_adjusted_length.
     *
     *  @param[in]  i_buffer    Initializes iv_buffer IF the request is
     *                          aligned. Otherwise, not used.
     */
    SpiOp(TARGETING::Target* i_target,
          uint8_t            i_engine,
          uint64_t           i_offset,
          size_t             i_buflen,
          void *             i_buffer);

    /**
     *  @brief Destructor used to delete iv_buffer if iv_usingAdjustedBuffer was
     *         set to true.
     */
    ~SpiOp();

    /**
     * @brief      Constructs a SpiControlHandle object that calculates engine
     *             offset and other necessary parameters to perform the SpiOp.
     *
     * @return     SpiControlHandle
     */
    SpiControlHandle getSpiHandle();

    /**
     * @brief          Performs the SPI read operation and handles alignment
     *                 adjusting if necessary.
     *
     * @param[out]     o_buffer  The buffer to place the retrieved data.
     *
     * @param[in]      io_buflen  The size of the data to read and place in the
     *                            buffer.
     *
     * @return         errlHndl_t nullptr if successful, otherwise a pointer to
     *                            the error log.
     */
    errlHndl_t read(void*   o_buffer,
                    size_t& io_buflen);

    /**
     * @brief          Performs the SPI write operation.
     *
     * @param[in]      i_buffer  The buffer containing the data to be written to
     *                           the target device.
     *
     * @param[in/out]  io_buflen INPUT: The size of the data to write to the
     *                                  target device.
     *                           OUTPUT: The size of the data buffer written.
     *
     * @return         errlHndl_t nullptr if successful, otherwise a pointer to
     *                            the error log.
     */
    errlHndl_t write(void*   i_buffer,
                     size_t& io_buflen);

}; // End of SpiOp class definition.

/**
 * @brief Initialize SPI Device Driver by forcing SPI Master to use PIB.
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


/**
 * @brief Gets the appropriate engine mutex for the given SPI engine
 *
 * @param[in]     i_target       The target to get the mutex for.
 *
 * @param[in]     i_engine       Which engine mutex we are looking for.
 *
 * @param[in/out] io_engine_lock Pointer to the engine mutex.
 *                                INPUT: nullptr
 *                                OUTPUT: The engine mutex
 *
 * @return bool - True if valid mutex is found, False otherwise.
 */
bool spiGetEngineMutex(TARGETING::Target* i_target,
                       uint8_t            i_engine,
                       mutex_t*&          io_engine_lock);


/**
 * @brief Locks or unlocks the appropriate engine mutex for the given SPI engine
 *
 * @param[in]     i_target       The target used to get the mutex.
 *
 * @param[in]     i_engine       The engine mutex to lock or unlock.
 *
 * @param[in]     i_unlock       TRUE: unlock the mutex
 *                               FALSE: lock the mutex
 *
 * @return        errlHndl_t     nullptr on success, otherwise errl.
 */
errlHndl_t spiEngineLockOp(TARGETING::Target* i_target,
                           uint8_t            i_engine,
                           bool               i_unlock);

/**
 * @brief Copies the requested data from the adjusted buffer contents into the
 *        output buffer. This is done because the SPI devices have an alignment
 *        limitation that is hidden from layers above the SPI Device Driver. So,
 *        instead of directly reading data into the output buffer we create an
 *        aligned buffer to use for the read and then copy the data out.
 *
 * @param[in/out]  io_destination  The buffer to copy the requested data to.
 *
 * @param[in/out]  io_amountToCopy INPUT: The length of the requested data.
 *                                 OUTPUT: zero if an error occurs.
 *
 * @param[in]      i_source        The buffer to copy data from.
 *
 * @param[in]      i_sourceLength  Used to verify that we don't overrun the
 *                                 source buffer.
 *
 * @param[in]      i_sourceOffset  Offset to start at in the source buffer.
 *                                 Defaults to 0.
 *
 * @return         errlHndl_t     nullptr on success. Otherwise, error log.
 */
errlHndl_t copyToBuffer(void*           io_destination,
                        size_t&         io_amountToCopy,
                        uint8_t const * i_source,
                        const size_t    i_sourceLength,
                        const size_t    i_sourceOffset = 0);


}; // end namespace SPI
#endif
