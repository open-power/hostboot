/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_mmio_access.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/**
 * @file plat_mmio_access.C
 *
 * @brief Implements FAPI mmio functions at the platform layer.
 */

#include <stdint.h>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <return_code.H>
#include <target.H>
#include <target_types.H>
#include <plat_utils.H>
#include <attribute_service.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <fapi2/plat_mmio_access.H>

namespace fapi2
{
// Address bit that designates it as an Explorer MMIO address
static const uint64_t EXPLR_IB_MMIO_OFFSET       = 0x0000000100000000ull;

// Valid I2C access to 256MB SRAM space, starts at offset 0x01000000
static const uint64_t MIN_I2C_SRAM_SPACE_ADDRESS = 0x0000000001000000ull;
static const uint64_t MAX_I2C_SRAM_SPACE_ADDRESS = 0x0000000011000000ull;

// byte transaction sizes for i2c
static const size_t I2C_TRANSACTION_SIZE      = 4; // actual size sent
static const size_t SCOM_I2C_TRANSACTION_SIZE = 8;

// Convert MMIO to I2C address (need these bits set)
static const uint64_t EXPLR_MMIO_TO_I2C_ADDRESS_MASK = 0xA0000000;


/**
 * @brief Explorer Inband read via i2c
 * @param[in]     i_target - OCMB target
 * @param[in/out] io_data_read - buffer to be filled with read data
 * @param[in/out] io_get_size - size of buffer (returns read size)
 * @param[in]     i_i2c_addr - i2c scom address
 * @return  errlHndl_t indicating success or failure
 */
errlHndl_t explrIbI2cRead(TARGETING::Target * i_target,
                          uint8_t * io_data_read,
                          size_t io_get_size,
                          const uint64_t i_i2c_addr)
{
    errlHndl_t l_err = nullptr;

    if ( io_get_size % I2C_TRANSACTION_SIZE )
    {
        // invalid size expected (need to be a multiple of I2C_TRANSACTION_SIZE)
        FAPI_ERR("explrIbI2cRead: read size %d is not a multiple of %d",
            io_get_size, I2C_TRANSACTION_SIZE);
        /*@
         * @errortype
         * @moduleid     fapi2::MOD_FAPI2_EXPLR_IB_I2C_READ
         * @reasoncode   fapi2::RC_INVALID_BUFFER_SIZE
         * @userdata1[0:31]  Buffer size
         * @userdata1[32:63] Transaction size
         * @userdata2[0:31]  HUID of input target
         * @userdata2[32:63] i2c_address
         * @devdesc      Invalid read buffer size,
         *               needs to be divisible by transaction size
         * @custdesc     Internal firmware error
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   fapi2::MOD_FAPI2_EXPLR_IB_I2C_READ,
                                   fapi2::RC_INVALID_BUFFER_SIZE,
                                   TWO_UINT32_TO_UINT64(io_get_size,
                                      I2C_TRANSACTION_SIZE),
                                   TWO_UINT32_TO_UINT64(
                                      TARGETING::get_huid(i_target),
                                      i_i2c_addr),
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_err->collectTrace(FAPI_TRACE_NAME);
        io_get_size = 0;  // no data being read
    }
    else
    {
        FAPI_INF("explrIbI2cRead: deviceRead() starting at i2cscom address "
            "0x%08X for %d bytes", i_i2c_addr, io_get_size);

        // keep track of total bytes read
        size_t total_bytes_read = 0;

        // Increment this address after each read transaction
        uint64_t i2cAddr = i_i2c_addr;

        // scom transaction variables
        size_t scomTransSize = SCOM_I2C_TRANSACTION_SIZE;
        uint8_t scomReadData[SCOM_I2C_TRANSACTION_SIZE];

        // Only able to read 4 bytes at a time with i2c, so
        // need to break into multiple i2c read transactions
        while( total_bytes_read < io_get_size )
        {
            FAPI_DBG("explrIbI2cRead: deviceRead() at i2cscom address 0x%08X",
                    i2cAddr);
            l_err = deviceOp( DeviceFW::READ,
                              i_target,
                              scomReadData,
                              scomTransSize,
                              DEVICE_I2CSCOM_ADDRESS(i2cAddr) );
            if (l_err)
            {
                FAPI_ERR("explrIbI2cRead: target 0x%08X deviceRead() at "
                    "address 0x%08X failed",
                    TARGETING::get_huid(i_target), i2cAddr);
                l_err->collectTrace(FAPI_TRACE_NAME);
                break;
            }
            else
            {
                FAPI_DBG("explrIbI2cRead: read %02X%02X%02X%02X",
                    scomReadData[4], scomReadData[5], scomReadData[6],
                    scomReadData[7]);
            }

            // The MMIO hardware does this byteswap for us, since we are
            // running this over i2c we must reorder the bytes here
            io_data_read[total_bytes_read]   = scomReadData[7];
            io_data_read[total_bytes_read+1] = scomReadData[6];
            io_data_read[total_bytes_read+2] = scomReadData[5];
            io_data_read[total_bytes_read+3] = scomReadData[4];

            // Only able to read 4 bytes at a time
            total_bytes_read += I2C_TRANSACTION_SIZE;
            i2cAddr += I2C_TRANSACTION_SIZE;

            // make sure this value is correct for next op
            scomTransSize = SCOM_I2C_TRANSACTION_SIZE;
        }
    }
    return l_err;
}


/**
 * @brief Explorer Inband write via i2c
 * @param[in]     i_target - OCMB target
 * @param[in]     i_write_data - data to write out
 * @param[in/out] io_write_size - how much data to write
 *                (returns how much written)
 * @param[in]     i_i2c_addr - i2c scom address
 * @return  errlHndl_t indicating success or failure
 */
errlHndl_t explrIbI2cWrite(TARGETING::Target * i_target,
                          const uint8_t * i_write_data,
                          size_t io_write_size,
                          const uint64_t i_i2c_addr)
{
    errlHndl_t l_err = nullptr;

    // Verify write can be divide up evenly
    if ( io_write_size % I2C_TRANSACTION_SIZE )
    {
        // invalid size expected (need to be a multiple of I2C_TRANSACTION_SIZE)
        FAPI_ERR("explrIbI2cWrite: write size %d is not a multiple of %d",
            io_write_size, I2C_TRANSACTION_SIZE);
        /*@
         * @errortype
         * @moduleid     fapi2::MOD_FAPI2_EXPLR_IB_I2C_WRITE
         * @reasoncode   fapi2::RC_INVALID_BUFFER_SIZE
         * @userdata1[0:31]  Buffer size
         * @userdata1[32:63] Transaction size
         * @userdata2[0:31]  HUID of input target
         * @userdata2[32:63] i2c_address
         * @devdesc      Invalid write buffer size, needs to be divisible
         *               by transaction size
         * @custdesc     Internal firmware error
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   fapi2::MOD_FAPI2_EXPLR_IB_I2C_READ,
                                   fapi2::RC_INVALID_BUFFER_SIZE,
                                   TWO_UINT32_TO_UINT64(io_write_size,
                                      I2C_TRANSACTION_SIZE),
                                   TWO_UINT32_TO_UINT64(
                                      TARGETING::get_huid(i_target),
                                      i_i2c_addr),
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_err->collectTrace(FAPI_TRACE_NAME);
    }
    else
    {
        // counter for bytes written out to SRAM space
        size_t total_bytes_written = 0;

        // going to alter this address to cycle through write data
        uint64_t i2cAddr = i_i2c_addr;

        // scom transaction variables
        size_t scomTransSize = SCOM_I2C_TRANSACTION_SIZE;
        uint8_t scomWriteData[SCOM_I2C_TRANSACTION_SIZE];

        FAPI_INF("explrIbI2cWrite: deviceWrite() starting at i2cscom address "
            "0x%08X for %d bytes", i_i2c_addr, io_write_size);

        // Only able to write 4 bytes at a time with i2c,
        // so need to break into multiple i2c write transactions
        while( total_bytes_written < io_write_size )
        {
            memset(scomWriteData, 0x00, SCOM_I2C_TRANSACTION_SIZE);

            // Only last four bytes are actually written out
            // NOTE: MMIO hardware does this byteswap for us, but since we
            // are running this over i2c we must reorder the bytes here
            scomWriteData[7] = i_write_data[total_bytes_written];
            scomWriteData[6] = i_write_data[total_bytes_written+1];
            scomWriteData[5] = i_write_data[total_bytes_written+2];
            scomWriteData[4] = i_write_data[total_bytes_written+3];

            l_err = deviceOp( DeviceFW::WRITE,
                              i_target,
                              scomWriteData,
                              scomTransSize,
                              DEVICE_I2CSCOM_ADDRESS(i2cAddr) );
            if (l_err)
            {
                FAPI_ERR("explrIbI2cWrite: i2cscom write(0x%02X%02X%02X%02X) "
                    "at address 0x%08X failed",
                    scomWriteData[4], scomWriteData[5], scomWriteData[6],
                    scomWriteData[7], i2cAddr);
                l_err->collectTrace(FAPI_TRACE_NAME);
                break;
            }
            // Really only doing 4-byte transactions
            i2cAddr += I2C_TRANSACTION_SIZE;
            total_bytes_written += I2C_TRANSACTION_SIZE;

            // Update for next scom operation
            scomTransSize = SCOM_I2C_TRANSACTION_SIZE;
        }
    }
    return l_err;
}

/**
 * @brief Checks if all the conditions are met to allow i2c
 *        operation instead of MMIO.
 * @param[in] i_ocmb - OCMB target
 * @param[in] i_mmioAddress - address passed into get/putMMIO
 * @return true if i2c should be used instead of MMIO
 */
bool useI2cInsteadOfMmio( const TARGETING::Target * i_ocmb,
                          const uint64_t i_mmioAddress )
{
    bool useI2c = false;  // default to use MMIO

    uint8_t attrAllowedI2c = 0;

    // Check force i2c attribute first
    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    crit_assert(l_sys != nullptr);
    attrAllowedI2c = l_sys->getAttr<TARGETING::ATTR_FORCE_SRAM_MMIO_OVER_I2C>();

    // If not forced to use i2c, then check if that is the current scom setting
    if (!attrAllowedI2c)
    {
        // The SCOM_SWITCHES attribute will keep track of when it is safe
        // to access the ocmb via inband vs when we should do accesses over
        // i2c. Use this attribute to decide which we want to use.
        auto ocmb_info = i_ocmb->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
        if (!ocmb_info.useInbandScom)
        {
            attrAllowedI2c = 1;
        }
    }

    // Attribute settings must allow i2c operation before checking
    // for a valid address range
    if (attrAllowedI2c)
    {
        // Verify address is within valid SRAM range
        if ( ((i_mmioAddress & 0x0F00000000) == EXPLR_IB_MMIO_OFFSET) &&
             ((i_mmioAddress & 0x0FFFFFFFF) >= MIN_I2C_SRAM_SPACE_ADDRESS) &&
             ((i_mmioAddress & 0x0FFFFFFFF) <= MAX_I2C_SRAM_SPACE_ADDRESS) )
        {
            useI2c = true;
        }
        else
        {
           FAPI_INF("0x%08X OCMB address 0x%.8X is outside of SRAM range so using mmio",
              TARGETING::get_huid(i_ocmb), i_mmioAddress);
        }
    }

    return useI2c;
}

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------

/// @brief Platform-level implementation of getMMIO()
///        Reads data via MMIO from the target
ReturnCode platGetMMIO( const Target<TARGET_TYPE_ALL>& i_target,
                        const uint64_t i_mmioAddr,
                        const size_t i_transSize,
                        std::vector<uint8_t>& o_data )
{
    ReturnCode l_rc;
    errlHndl_t l_err = nullptr;

    FAPI_DBG(ENTER_MRK "platGetMMIO");

    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_mmio_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    size_t l_get_size = o_data.size();

    // create a temporary buffer for read data
    uint8_t * l_data_read = new uint8_t[ l_get_size ];

    do
    {
        // Extract the component pointer
        TARGETING::Target * l_target = nullptr;
        l_err = fapi2::platAttrSvc::getTargetingTarget(i_target, l_target);
        if ( l_err )
        {
            FAPI_ERR( "platGetMMIO: Error from getTargetingTarget on %s",
                      l_targName );
            break; //return with error
        }

        // Run mmio if inband i2c isn't enabled or address is outside of SRAM
        // range
        if ( !useI2cInsteadOfMmio(l_target, i_mmioAddr) )
        {
            // call MMIO driver
            l_err = DeviceFW::deviceRead(l_target,
                                 l_data_read,
                                 l_get_size,
                                 DEVICE_MMIO_ADDRESS(i_mmioAddr, i_transSize));
        }
        else
        {
            // Use i2c instead of MMMIO
            // Explorer i2c addresses are actually 32-bit and need 0xA at the
            // beginning
            uint64_t i2cAddr = (i_mmioAddr & 0x00000000FFFFFFFF) |
                                EXPLR_MMIO_TO_I2C_ADDRESS_MASK;
            l_err = explrIbI2cRead(l_target, l_data_read, l_get_size, i2cAddr);
        }
        if (l_traceit)
        {
            // Only trace the first 8 bytes of data read
            // (don't want to overflow trace buffer)
            uint64_t l_traceDataRead = 0;
            if (l_get_size >= sizeof(l_traceDataRead))
            {
              memcpy(&l_traceDataRead, l_data_read, sizeof(l_traceDataRead));
            }
            else if (l_get_size > 0)
            {
              memcpy(&l_traceDataRead, l_data_read, l_get_size);
            }
            FAPI_SCAN("TRACE : getMMIO  :  %s %d - %d %.16llX",
                      l_targName,
                      o_data.size(),
                      l_get_size,
                      l_traceDataRead);
        }

    } while(0);

    if (l_err)
    {
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_err);
    }
    else
    {
        // read was successful so copy data into o_data
        o_data.clear();
        o_data.insert( o_data.end(),
                       &l_data_read[0],
                       &l_data_read[l_get_size] );
    }
    delete [] l_data_read;

    FAPI_DBG(EXIT_MRK "platGetMMIO");
    return l_rc;
}


/// @brief Platform-level implementation of putMMIO()
///        Writes data via MMIO to the target
ReturnCode platPutMMIO( const Target<TARGET_TYPE_ALL>& i_target,
                        const uint64_t i_mmioAddr,
                        const size_t i_transSize,
                        const std::vector<uint8_t>& i_data )
{
    ReturnCode l_rc;
    errlHndl_t l_err = nullptr;
    uint8_t * l_writeDataPtr;

    FAPI_DBG(ENTER_MRK "platPutMMIO");

    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_mmio_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    do {
        // Extract the component pointer
        TARGETING::Target * l_target = nullptr;
        l_err = fapi2::platAttrSvc::getTargetingTarget(i_target, l_target);
        if (l_err)
        {
            FAPI_ERR( "platPutMMIO: Error from getTargetingTarget on %s",
                      l_targName );
            break; //return with error
        }

        //copy data from const vector to data ptr
        l_writeDataPtr = new uint8_t[ i_data.size() ];
        std::copy(i_data.begin(), i_data.end(), l_writeDataPtr);
        size_t l_dataSize = i_data.size();

        // Run mmio if inband i2c isn't enabled or address is outside of SRAM
        // range
        if ( !useI2cInsteadOfMmio(l_target, i_mmioAddr) )
        {
            // call MMIO driver
            l_err = DeviceFW::deviceWrite(l_target,
                                  l_writeDataPtr,
                                  l_dataSize,
                                  DEVICE_MMIO_ADDRESS(i_mmioAddr, i_transSize));
        }
        else
        {
            // Address is an Explorer SRAM address, so I2C will work
            // Explorer i2c addresses are actually 32-bit and need 0xA at the
            // beginning
            uint64_t i2cAddr = (i_mmioAddr & 0x00000000FFFFFFFF) |
                                EXPLR_MMIO_TO_I2C_ADDRESS_MASK;
            l_err = explrIbI2cWrite(l_target, l_writeDataPtr, l_dataSize,
                                    i2cAddr);
        }
        if (l_traceit)
        {
            // trace the first 8 bytes of written data
            // (avoid trace buffer overflow)
            uint64_t traceWriteData = 0;
            if (l_dataSize > sizeof(traceWriteData))
            {
                // copy what will fit into traceWriteData variable
                memcpy(&traceWriteData, l_writeDataPtr, sizeof(traceWriteData));
            }
            else
            {
                memcpy(&traceWriteData, l_writeDataPtr, l_dataSize);
            }
            FAPI_SCAN( "TRACE : putMMIO    :  %s : %d %.16llX",
                       l_targName,
                       l_dataSize,
                       traceWriteData );
        }

        delete [] l_writeDataPtr;

    } while (0);

    if (l_err)
    {
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_err);
    }

    FAPI_DBG(EXIT_MRK "platPutMMIO");
    return l_rc;
}

} // End namespace
