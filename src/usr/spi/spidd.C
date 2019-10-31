/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/spidd.C $                                         */
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
/**
 * @file spidd.C
 *
 * @brief Implementation of the Serial Peripheral Interface (SPI) device driver
 *
 */

// -----------------------------------------------------------------------------
//      Includes
// -----------------------------------------------------------------------------
#include "spidd.H"
#include <trace/interface.H>

#include <targeting/common/utilFilter.H>
#include <fapi2/plat_hwp_invoker.H>

#include <hbotcompid.H>
#include <initservice/taskargs.H>
#include <p10_scom_perv.H>

// -----------------------------------------------------------------------------
//      Trace definitions
// -----------------------------------------------------------------------------
trace_desc_t* g_trac_spi = nullptr;
TRAC_INIT(&g_trac_spi, SPI_COMP_NAME, KILOBYTE);

#define TRACUCOMP(args...)    TRACFCOMP(args)
//#define TRACUCOMP

namespace SPI
{

// Always include the ECC byte so that layers above SPI driver can handle ECC
const bool ALWAYS_INCLUDE_ECC = true;

/**
 * _start() task entry procedure using the macro found in taskargs.H
 */
TASK_ENTRY_MACRO( spiInit );

// Initializes the SPI Device Driver by ensuring the SPI Master's mux is set to
// use PIB.
void spiInit(errlHndl_t & io_rtaskRetErrl)
{
    // @TODO RTC 208787 Pull this code out and put in a HWP. Then call it here.
    const uint64_t ROOT_CTRL_8 =
        static_cast<uint64_t>(scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_RW);
    const uint64_t SPIM_PORT_MUX_SELECT =
        scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC;

    TARGETING::Target * masterTarget = nullptr;
    TARGETING::targetService()
        .masterProcChipTargetHandle(masterTarget);

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> masterProc(masterTarget);
    fapi2::buffer<uint64_t> root_ctrl_buffer;

    // Get the contents of root control register 8 which controls whether we're
    // accessing over PIB or FSI.
    FAPI_TRY(fapi2::getScom(masterProc,
                            ROOT_CTRL_8,
                            root_ctrl_buffer));

    // Force root control reg 8 to use PIB for SPI Master
    // clearing the bit to 0 forces the SPI Master to use the PIB path.
    root_ctrl_buffer.clearBit<SPIM_PORT_MUX_SELECT>();

    // Write the buffer back to the register.
    FAPI_TRY(fapi2::putScom(masterProc,
                            ROOT_CTRL_8,
                            root_ctrl_buffer));
fapi_try_exit:
    return;
}

// Register the generic SPI perform Op with routing code for Procs.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SPI,
                      TARGETING::TYPE_PROC,
                      spiPerformOp);

errlHndl_t spiPerformOp(DeviceFW::OperationType i_opType,
                        TARGETING::Target*      i_target,
                        void*                   io_buffer,
                        size_t&                 io_buflen,
                        int64_t                 i_accessType,
                        va_list                 i_args)
{
    TRACUCOMP(g_trac_spi, ENTER_MRK"spiPerformOp() opType(%s), "
              "i_target(0x%X), io_buffer(%p), io_buflen(%d),  "
              "i_accessType(%d)",
              i_opType == DeviceFW::READ ? "READ" : "WRITE",
              TARGETING::get_huid(i_target),
              io_buffer,
              io_buflen,
              i_accessType);

    errlHndl_t errl = nullptr;
    bool mutex_should_unlock = false;

    // SPI master engine to use for this operation
    uint8_t engine = static_cast<uint8_t>(va_arg(i_args, uint64_t));
    // The offset to start the read or write from
    uint64_t offset = va_arg(i_args, uint64_t);

    do {

        if (io_buflen == 0)
        {
            // @TODO RTC 243918 Error
            TRACFCOMP(g_trac_spi,
                      ERR_MRK"spiPerformOp(): io_buflen %d. Size invalid",
                      io_buflen);
            break;
        }

        SpiOp spiOp = SpiOp(i_target,
                            engine,
                            offset,
                            io_buflen,
                            io_buffer);

        errl = spiEngineLockOp(i_target,
                               engine,
                               mutex_should_unlock);
        if (errl != nullptr)
        {
            // @TODO RTC 243918 Handle it.
            break;
        }
        mutex_should_unlock = true;

        // =====================================================================
        // SPI Read Operation
        // =====================================================================
        if (i_opType == DeviceFW::READ)
        {
            errl = spiOp.read(io_buffer,
                              io_buflen);

            if (errl != nullptr)
            {
                break;
            }
        }
        // =====================================================================
        // SPI Write Operation
        // =====================================================================
        else if (i_opType == DeviceFW::WRITE)
        {
            errl = spiOp.write(io_buffer,
                               io_buflen);

            if (errl != nullptr)
            {
                break;
            }
        }
        else
        {
            // Unknown/Unsupported Operation Type
            // @TODO RTC 243918 Create an error for this case.
        }

    } while(0);

    if (mutex_should_unlock)
    {
        errl = spiEngineLockOp(i_target,
                               engine,
                               mutex_should_unlock);
        if (errl != nullptr)
        {
            // @TODO RTC 243918 Handle it.
        }
    }

    return errl;
}

errlHndl_t SpiOp::read(void*   o_buffer,
                       size_t& io_buflen)
{
    errlHndl_t errl = nullptr;
    SpiControlHandle handle = getSpiHandle();

    do {

        if (io_buflen != iv_length)
        {
            // Something changed the buffer length after object construction
            //@TODO RTC 243918 Error.
            break;
        }

        // Always use the adjusted offset and length for the read because
        // if iv_usingAdjustedBuffer is set to false then they are equal to
        // the requested offset and length and if iv_usingAdjustedBuffer is true
        // then we must use them anyway.
        FAPI_INVOKE_HWP(errl,
                        spi_read,
                        handle,
                        iv_adjusted_offset,
                        iv_adjusted_length,
                        RAW_BYTE_ACCESS,
                        iv_buffer);

        if (errl != nullptr)
        {
            io_buflen = 0;
            break;
        }

        if (iv_usingAdjustedBuffer)
        {
            // Write the requested data to the output buffer
            errl = copyToBuffer(o_buffer,
                                io_buflen,
                                iv_buffer,
                                iv_adjusted_length,
                                iv_start_index);
            if (errl != nullptr)
            {
                io_buflen = 0;
                break;
            }
        }
    } while(0);



    return errl;
}

errlHndl_t SpiOp::write(void*   i_buffer,
                        size_t& io_buflen)
{
    errlHndl_t errl = nullptr;

    SpiControlHandle handle = getSpiHandle();

    do {

        if (io_buflen != iv_length)
        {
            // Something changed the buffer length after object construction
            //@TODO RTC 243918 Error.
            break;
        }

        if (iv_usingAdjustedBuffer)
        {
            // Since the write transaction must be aligned by
            // TRANSACTION_ALIGNMENT bytes. Do a read using the adjusted buffer
            // size, modify the adjusted buffer with the data to be written,
            // then write that data back to the SPI device.
            FAPI_INVOKE_HWP(errl,
                            spi_read,
                            handle,
                            iv_adjusted_offset,
                            iv_adjusted_length,
                            RAW_BYTE_ACCESS,
                            iv_buffer);
            if (errl != nullptr)
            {
                io_buflen = 0;
                break;
            }

            // Write the contents of the original buffer to the adjusted buffer
            // at the correct start index.
            errl = copyToBuffer(&iv_buffer[iv_start_index],
                                io_buflen,
                                reinterpret_cast<uint8_t*>(i_buffer),
                                io_buflen);
            if (errl != nullptr)
            {
                io_buflen = 0;
                break;
            }
        }

        // Always use the adjusted offset and length for the write because
        // if iv_usingAdjustedBuffer is set to false then they are equal to
        // the requested offset and length and if iv_usingAdjustedBuffer is true
        // then we must use them anyway.
        FAPI_INVOKE_HWP(errl,
                        spi_write,
                        handle,
                        iv_adjusted_offset,
                        iv_adjusted_length,
                        iv_buffer);

        if (errl != nullptr)
        {
            io_buflen = 0;
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t copyToBuffer(void*           io_destination,
                        size_t&         io_amountToCopy,
                        uint8_t const * i_source,
                        const size_t    i_sourceLength,
                        const size_t    i_sourceOffset)
{
    errlHndl_t errl = nullptr;

    do {

        if (i_sourceOffset + io_amountToCopy > i_sourceLength)
        {
            //@TODO RTC 243918 Error
            TRACFCOMP(g_trac_spi, ERR_MRK"SPI::copyToBuffer() "
                     "size to copy greater than adjusted buffer size!");
            io_amountToCopy = 0;
            break;
        }

        memcpy(io_destination, &i_source[i_sourceOffset], io_amountToCopy);

    } while(0);

    return errl;
}

bool spiGetEngineMutex(TARGETING::Target* i_target,
                       uint8_t            i_engine,
                       mutex_t*&          io_engine_lock)
{
    bool success = true;
    namespace T = TARGETING;
    do
    {
        switch(i_engine)
        {
            case 0:
                io_engine_lock =
                    i_target->getHbMutexAttr<T::ATTR_SPI_ENGINE_MUTEX_0>();
                break;
            case 1:
                io_engine_lock =
                    i_target->getHbMutexAttr<T::ATTR_SPI_ENGINE_MUTEX_1>();
                break;
            case 2:
                io_engine_lock =
                    i_target->getHbMutexAttr<T::ATTR_SPI_ENGINE_MUTEX_2>();
                break;
            case 3:
                io_engine_lock =
                    i_target->getHbMutexAttr<T::ATTR_SPI_ENGINE_MUTEX_3>();
                break;
            case 4:
                io_engine_lock =
                    i_target->getHbMutexAttr<T::ATTR_SPI_ENGINE_MUTEX_4>();
                break;
            case 5:
                io_engine_lock =
                    i_target->getHbMutexAttr<T::ATTR_SPI_ENGINE_MUTEX_5>();
                break;
            default:
                TRACFCOMP(g_trac_spi, ERR_MRK"spiGetEngineMutex: "
                          "Invalid engine for getting mutex");
                success = false;
                assert(success, "spidd.C: Invalid engine for getting mutex "
                       "i_engine=%d", i_engine);
                break;
        };
    } while(0);

    return success;
}

errlHndl_t spiEngineLockOp(TARGETING::Target* i_target,
                           const uint8_t      i_engine,
                           const bool         i_unlock)
{
    errlHndl_t errl = nullptr;

    do {
        mutex_t * engine_lock = nullptr;
        bool mutexSuccess = spiGetEngineMutex(i_target,
                                              i_engine,
                                              engine_lock);

        if (!mutexSuccess)
        {
            //@TODO RTC 243918 Error
            break;
        }

        if (i_unlock)
        {
            mutex_unlock(engine_lock);
        }
        else
        {
            mutex_lock(engine_lock);
        }

    } while(0);

    return errl;
}

SpiOp::SpiOp(TARGETING::Target* i_target,
             const uint8_t      i_engine,
             const uint64_t     i_offset,
             const size_t       i_buflen,
             void *             i_buffer)
    : iv_target(i_target),
      iv_offset(i_offset),
      iv_length(i_buflen),
      iv_engine(i_engine)
{
    iv_start_index = (iv_offset % TRANSACTION_ALIGNMENT);

    // Calculate the adjusted parameters.
    setAdjustedOpArgs(i_buffer);

}

SpiOp::~SpiOp()
{
    // If the op had to be aligned then make sure to delete the
    // adjusted buffer that was created for the aligned operation.
    if (iv_usingAdjustedBuffer)
    {
        delete[] iv_buffer;
    }
}

void SpiOp::setAdjustedOpArgs(void * i_buffer)
{
    // Determine the adjusted start offset by checking how far off
    // the requested offset is from the nearest lower bound
    // TRANSACTION_ALIGNMENT multiple and subtract that amount off.
    size_t remainder = iv_offset % TRANSACTION_ALIGNMENT;
    iv_adjusted_offset = iv_offset - remainder;

    // Determine the adjusted length. This is done by first adding the requested
    // length and the remainder from adjusted offset calculation. That way any
    // additional bytes included in the transaction by shifting the requested
    // offset are accounted for. Then check to see how far off the new temporary
    // adjusted length is from being in alignment. If it's aligned then that is
    // the adjusted length, otherwise round the adjust length up to the next
    // alignment multiple so that bytes aren't clipped off the end of the buffer
    size_t temp_length = iv_length + remainder;
    size_t adjusted_length_remainder = temp_length % TRANSACTION_ALIGNMENT;

    if (adjusted_length_remainder == 0)
    {
        // temp_length is aligned by TRANSACTION_ALIGNMENT bytes.
        // Return this value.
        iv_adjusted_length = temp_length;
    }
    else
    {
        // Round the adjusted length up to the nearest TRANSACTION_ALIGNMENT
        // multiple so that all the data can be read into a single buffer.
        iv_adjusted_length = temp_length
                           + TRANSACTION_ALIGNMENT
                           - adjusted_length_remainder;
    }

    // Determine if the request is aligned or not. If it is then no need to
    // create a new buffer. Just use the buffer that was given.
    if ((iv_offset == iv_adjusted_offset) && (iv_length == iv_adjusted_length))
    {
        // Transaction is aligned. Don't need adjusted parameters.
        iv_usingAdjustedBuffer = false;
        iv_buffer = reinterpret_cast<uint8_t*>(i_buffer);
    }
    else
    {
        // Transaction is not aligned. Create a buffer large enough to fit
        // aligned data.
        iv_usingAdjustedBuffer = true;
        iv_buffer = new uint8_t[iv_adjusted_length];
    }

    TRACUCOMP(g_trac_spi, "SpiOp::setAdjustedOpArgs(): "
              "iv_length = %d, iv_adjusted_length = %d, "
              "iv_offset = %d, iv_adjusted_offset = %d",
              iv_length, iv_adjusted_length, iv_offset, iv_adjusted_offset);
}

SpiControlHandle SpiOp::getSpiHandle()
{
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> chip_target(iv_target);

    return SpiControlHandle(chip_target, iv_engine);
}

}; // end namespace SPI
