/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/spidd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

class SpiOp
{
protected:

    // Master SPI target
    TARGETING::Target* iv_target;

    // The requested read or write offset.
    uint64_t iv_offset;

    // The engine to use for this Op
    uint8_t iv_engine;


    /**
     *  @brief Adds the various registers of the target spi device to an error
     *         log.
     *
     *  @param[in/out]  io_errl     The error log to add the register contents
     *                              to.
     */
    void addStatusRegs(errlHndl_t& io_errl);

    /**
     *  @brief Adds callouts for the SPI device to the error log.
     *         Does a medium callout on the SPI master proc
     *         Does a low callout of HB code
     *
     *  @param[in/out]  io_errl     The error log to add the callouts to.
     */
    virtual void addCallouts(errlHndl_t& io_errl);

public:

    /**
     *  @brief Constructor that creates a SpiOp object. This constructor will
     *         initialize all member variables.
     *
     *  @param[in]  i_controller_target    Initializes iv_target.
     *  @param[in]  i_engine               Initializes iv_engine.
     *  @param[in]  i_offset               Initializes iv_offset.
     *
     */
    SpiOp(TARGETING::Target* i_controller_target,
          uint8_t   i_engine,
          uint64_t  i_offset);

    /**
     * @brief      Constructs a SpiControlHandle object that calculates engine
     *             offset and other necessary parameters to perform the SpiOp.
     *
     * @return     SpiControlHandle
     */
    SpiControlHandle getSpiHandle();

    /**
     * @brief          Pure virtual function that will perform the SPI read
     *                 operation.
     *
     * @param[out]     o_buffer  The buffer to place the retrieved data.
     *
     * @param[in]      io_buflen  The size of the data to read and place in the
     *                            buffer.
     *
     * @return         errlHndl_t nullptr if successful, otherwise a pointer to
     *                            the error log.
     */
    virtual errlHndl_t read(void* o_buffer, size_t& io_buflen) = 0;

    /**
     * @brief          Pure virtual function that will perform the SPI write
     *                 operation.
     *
     * @param[in]      i_buffer  The buffer containing the data to be written
     *                           to the target device.
     *
     * @param[in/out]  io_buflen INPUT: The size of the data to write to the
     *                                  target device.
     *                           OUTPUT: The size of the data buffer written.
     *
     * @return         errlHndl_t nullptr if successful, otherwise a pointer to
     *                            the error log.
     */
    virtual errlHndl_t write(void* i_buffer, size_t& io_buflen) = 0;

    /**
     * @brief Returns the value of iv_offset member.
     */
    uint64_t getOffset() const;

    /**
     * @brief Returns the value of iv_engine member.
     */
    uint8_t  getEngine() const;

    /**
     * @brief Returns the value of iv_target member.
     */
    TARGETING::Target* getControllerTarget() const;

}; // End of SpiOp class definition.

class SpiEepromOp : public SpiOp
{
    // The number of bytes a SPI transaction must be aligned to.
    static constexpr size_t TRANSACTION_ALIGNMENT = 8;

    // The adjusted offset to read or write to.
    // This must always be a multiple of TRANSACTION_ALIGNMENT
    uint64_t iv_adjusted_offset;

    // The adjusted length of the buffer to be sent in a SPI read/write
    // transaction. This must always be a multiple of TRANSACTION_ALIGNMENT.
    uint64_t iv_adjusted_length;

    // The index into the adjusted buffer where the requested data starts.
    uint8_t iv_start_index;

    // Determines if an adjusted buffer is in use. If the operation wasn't
    // aligned then an adjusted buffer would be necessary.
    bool iv_usingAdjustedBuffer;

    // Will point to the output buffer given in spiPerformOp or if
    // iv_usingAdjustedBuffer is set to true then it will point to an adjusted
    // buffer.
    uint8_t * iv_buffer;

    // The length of the request.
    size_t iv_length;

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

    /**
     * @brief Copies the requested data from the adjusted buffer contents into
     *        the output buffer. This is done because the SPI devices have an
     *        alignment limitation that is hidden from layers above the SPI
     *        Device Driver. So, instead of directly reading data into the
     *        output buffer we create an aligned buffer to use for the read and
     *        then copy the data out.
     *        This function can also be used to generically copy one buffer's
     *        contents to another.
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

    /**
     *  @brief Adds callouts for the SPI Eeprom device to the error log.
     *
     *  @param[in/out]  io_errl     The error log to add the callouts to.
     */
    void addCallouts(errlHndl_t& io_errl);

public:
    /**
     *  @brief Constructor that creates a SpiEepromOp object. This constructor
     *         will initialize all member variables based on whether the requested
     *         operation is aligned by TRANSACTION_ALIGNMENT.
     *
     *  @param[in]  i_controller_target    Initializes iv_target.
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
    SpiEepromOp(TARGETING::Target* i_controller_target,
                uint8_t            i_engine,
                uint64_t           i_offset,
                size_t             i_buflen,
                void *             i_buffer);

    /**
     * @brief          Performs the SPI EEPROM read operation and handles
     *                 alignment adjusting if necessary.
     *
     * @param[out]     o_buffer  The buffer to place the retrieved data.
     *
     * @param[in]      io_buflen  The size of the data to read and place in the
     *                            buffer.
     *
     * @return         errlHndl_t nullptr if successful, otherwise a pointer to
     *                            the error log.
     */
    errlHndl_t read(void* o_buffer, size_t& io_buflen);

    /**
     * @brief          Performs the SPI EEPROM write operation.
     *
     * @param[in]      i_buffer  The buffer containing the data to be written
     *                           to the target device.
     *
     * @param[in/out]  io_buflen INPUT: The size of the data to write to the
     *                                  target device.
     *                           OUTPUT: The size of the data buffer written.
     *
     * @return         errlHndl_t nullptr if successful, otherwise a pointer to
     *                            the error log.
     */
    errlHndl_t write(void* i_buffer, size_t& io_buflen);

    /**
     * @brief Returns the value of iv_adjusted_offset member.
     */
    uint64_t getAdjustedOffset() const;

    /**
     * @brief Returns the value of iv_adjusted_length member.
     */
    uint64_t getAdjustedLength() const;

    /**
     * @brief Returns the value of iv_start_index member.
     */
    uint8_t getStartIndex() const;

    /**
     * @brief Returns the value of iv_usingAdjustedBuffer member.
     */
    bool getUsingAdjustedBuffer() const;

    /**
     * @brief Returns the value of iv_length member.
     */
    uint64_t getLength() const;
}; // End of SpiEepromOp class definition.


class SpiTpmOp : public SpiOp
{
    // TPM locality - (0-4)
    uint32_t iv_locality;

    // TPM target being accessed
    const TARGETING::Target * iv_tpmTarget;

    /**
     *  @brief Adds callouts for the SPI TPM device to the error log.
     *
     *  @param[in/out]  io_errl     The error log to add the callouts to.
     */
    void addCallouts(errlHndl_t& io_errl);

public:
    /**
     *  @brief Constructor that creates a SpiTpmOp object.
     *         This constructor will initialize all member variables
     *
     *  @param[in]  i_controller_target    Initializes iv_target.
     *  @param[in]  i_engine               Initializes iv_engine.
     *  @param[in]  i_offset               Initializes iv_offset
     *  @param[in]  i_locality             Initializes iv_locality (0-4)
     *  @param[in]  i_tpm_target           Initializes iv_tpmTarget
     *
     */
    SpiTpmOp(TARGETING::Target* i_controller_target,
             uint8_t            i_engine,
             uint64_t           i_offset,
             uint32_t           i_locality,
             TARGETING::Target* i_tpm_target);

    /**
     * @brief          Performs the SPI TPM read operation
     *
     * @param[out]     o_buffer  The buffer to place the retrieved data.
     *
     * @param[in]      io_buflen  The size of the data to read and place in the
     *                            buffer.
     *
     * @return         errlHndl_t nullptr if successful, otherwise a pointer to
     *                            the error log.
     */
    errlHndl_t read(void* o_buffer, size_t& io_buflen);

    /**
     * @brief          Performs the SPI TPM write operation.
     *
     * @param[in]      i_buffer  The buffer containing the data to be written
     *                           to the target device.
     *
     * @param[in/out]  io_buflen INPUT: The size of the data to write to the
     *                                  target device.
     *                           OUTPUT: The size of the data buffer written.
     *
     * @return         errlHndl_t nullptr if successful, otherwise a pointer to
     *                            the error log.
     */
    errlHndl_t write(void* i_buffer, size_t& io_buflen);

    /**
     * @brief Returns the value of iv_locality member.
     */
    uint32_t getLocality() const;

    /**
     * @brief Returns pointer to iv_tpmTarget member
     */
    const TARGETING::Target* getTpmTarget() const;

}; // End of SpiTpmOp class definition.

/**
 * @brief Initialize SPI Device Driver by forcing SPI Master to use PIB.
 *
 * @param[in/out]   io_rtaskRetErrl     nullptr on success. Otherwise, error.
 */
void spiInit(errlHndl_t &io_rtaskRetErrl);

/**
 *
 * @brief Perform a SPI access operation to an eeprom.
 *        It follows a pre-defined prototype function in order to be registered
 *        with the device driver framework.
 *
 * @param[in] i_opType       Operation Type. See DeviceFW::OperationType in
 *                           driverif.H
 *
 * @param[in] i_target       SPI Controller Target.
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
 *                           in driverif.H. *

 *
 * @return     errlHndl_t    nullptr if successful, otherwise a pointer to the
 *                           error log.
 *
 */
errlHndl_t spiEepromPerformOp(DeviceFW::OperationType i_opType,
                              TARGETING::Target*      i_controller_target,
                              void*                   io_buffer,
                              size_t&                 io_buflen,
                              int64_t                 i_accessType,
                              va_list                 i_args);

/**
 *
 * @brief Perform a SPI access operation to a TPM.
 *        It follows a pre-defined prototype function in order to be registered
 *        with the device driver framework.
 *
 * @param[in] i_opType       Operation Type. See DeviceFW::OperationType in
 *                           driverif.H
 *
 * @param[in] i_controller_target
 *                           SPI Controller Target
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
 *                           in driverif.H. *

 *
 * @return     errlHndl_t    nullptr if successful, otherwise a pointer to the
 *                           error log.
 *
 */
errlHndl_t spiTpmPerformOp(DeviceFW::OperationType i_opType,
                           TARGETING::Target*      i_controller_target,
                           void*                   io_buffer,
                           size_t&                 io_buflen,
                           int64_t                 i_accessType,
                           va_list                 i_args);

/**
 *
 * @brief Perform a SPI access operation. It follows a pre-defined prototype
 *        function in order to be registered with the device driver framework.
 *
 * @param[in] i_opType       Operation Type. See DeviceFW::OperationType in
 *                           driverif.H
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
 * @param[in] i_spiOp        Pointer to derived object which contains
 *                           information to perform the virtual SPI operations
 *
 * @return     errlHndl_t    nullptr if successful, otherwise a pointer to the
 *                           error log.
 *
 */
errlHndl_t spiPerformOp(DeviceFW::OperationType i_opType,
                        void*                   io_buffer,
                        size_t&                 io_buflen,
                        int64_t                 i_accessType,
                        SpiOp *                 i_spiOp );


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
 * @param[in]     io_unlock      INPUT: TRUE: unlock the mutex
 *                                      FALSE: lock the mutex
 *                               OUTPUT: TRUE: The mutex was locked and should
 *                                             be unlocked.
 *                                      FALSE: The mutex was unlocked and
 *                                             shouldn't be unlocked or an error
 *                                             occurred and mutex shouldn't be
 *                                             unlocked.
 *
 * @return        errlHndl_t     nullptr on success, otherwise errl.
 */
errlHndl_t spiEngineLockOp(TARGETING::Target* i_target,
                           uint8_t            i_engine,
                           bool&              io_unlock);

/**
 * @brief A helper function to add SPI status registers to the given error log
 *
 * @param[in] i_proc The proc on which the SPI registers live
 * @param[in] i_spiEngine The SPI engine to use
 * @param[in/out] io_errl The error log to attach the SPI register contents to
 */
void addSpiStatusRegsToErrl(TARGETING::Target* i_proc,
                            uint8_t i_spiEngine,
                            errlHndl_t& io_errl);


}; // end namespace SPI
#endif
