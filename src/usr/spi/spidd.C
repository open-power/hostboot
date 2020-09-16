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
#include "errlud_spi.H"
#include <trace/interface.H>

#include <spi/spireasoncodes.H>

#include <errl/errlentry.H>
#include <errl/hberrltypes.H>
#include <errl/errludlogregister.H>
#include <errl/errludtarget.H>

#include <hwas/common/hwasCallout.H>
#include <targeting/common/utilFilter.H>
#include <fapi2/plat_hwp_invoker.H>

#include <hbotcompid.H>
#include <initservice/taskargs.H>
#include <p10_scom_perv.H>
#include <p10_spi_init_pib.H>

constexpr uint64_t HOSTBOOT_PIB_MASTER_ID = 9;

// -----------------------------------------------------------------------------
//      Trace definitions
// -----------------------------------------------------------------------------
trace_desc_t* g_trac_spi = nullptr;
TRAC_INIT(&g_trac_spi, SPI_COMP_NAME, KILOBYTE);

//#define TRACUCOMP(args...)    TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace SPI
{

// Always include the ECC byte so that layers above SPI driver can handle ECC
const bool ALWAYS_INCLUDE_ECC = true;

// Give this constant a more managable name.
const uint64_t ROOT_CTRL_8_PIB =
    static_cast<uint64_t>(scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_RW);

const uint64_t ROOT_CTRL_8_FSI =
    static_cast<uint64_t>(scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_FSI_BYTE);


/**
 * _start() task entry procedure using the macro found in taskargs.H
 */
TASK_ENTRY_MACRO( spiInit );

// Initializes the SPI Device Driver by ensuring the SPI Master's mux is set to
// use PIB.
void spiInit(errlHndl_t & io_rtaskRetErrl)
{
    TARGETING::Target * masterTarget = nullptr;
    TARGETING::targetService()
        .masterProcChipTargetHandle(masterTarget);

    TARGETING::SpiSwitches switches;

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> masterProc(masterTarget);

    do {

        // Set the contents of root control register 8 which controls
        // whether we're accessing over PIB or FSI.
        FAPI_INVOKE_HWP(io_rtaskRetErrl,
                        p10_spi_init_pib,
                        masterProc);

        if (io_rtaskRetErrl != nullptr)
        {
            TRACFCOMP(g_trac_spi, ERR_MRK"spiInit(): "
                     "An error occurred during initialization of libspi.so! "
                     "SPI Device Driver will not function.");
            io_rtaskRetErrl->collectTrace(SPI_COMP_NAME, KILOBYTE);
            break;
        }

        // Update SPI access attribute for master processor
        switches.usePibSPI  = 1;
        switches.useFsiSPI  = 0;
        masterTarget->setAttr<TARGETING::ATTR_SPI_SWITCHES>(switches);
        TRACFCOMP( g_trac_spi, "spiInit: tgt=0x%X SPI_SWITCHES updated: "
                   "pib=%d, fsi=%d",
                   TARGETING::get_huid(masterTarget),
                   switches.usePibSPI, switches.useFsiSPI );

    } while(0);

    return;
}

// Register the EEPROM SPI perform Op with routing code for Procs.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SPI_EEPROM,
                      TARGETING::TYPE_PROC,
                      spiEepromPerformOp);

// Register the TPM SPI perform Op with routing code for Procs.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SPI_TPM,
                      TARGETING::TYPE_PROC,
                      spiTpmPerformOp);


errlHndl_t spiPerformOp(DeviceFW::OperationType i_opType,
                        void*                   io_buffer,
                        size_t&                 io_buflen,
                        SpiOp *                 i_spiOp )
{
    errlHndl_t errl = nullptr;
    bool mutex_should_unlock = false;

    assert((i_spiOp != nullptr), "spiPerformOp called with nullptr SpiOp");

    TARGETING::Target* spiTarget = i_spiOp->getControllerTarget();
    uint8_t spiEngine = i_spiOp->getEngine();

    do {

        if (io_buflen == 0)
        {
            TRACFCOMP(g_trac_spi,
                      ERR_MRK"spiPerformOp(): io_buflen %d. "
                      "Size must be greater than zero", io_buflen);
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         SPI::SPI_PERFORM_OP
            * @reasoncode       SPI::SPI_INVALID_BUFFER_SIZE
            * @userdata1        Target HUID of the SPI Master
            * @devdesc          The length of the buffer to write/read must be
            *                   greater than zero.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPI_PERFORM_OP,
                                           SPI_INVALID_BUFFER_SIZE,
                                           TARGETING::get_huid(spiTarget),
                                           0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        errl = spiEngineLockOp(spiTarget,
                               spiEngine,
                               mutex_should_unlock);
        if (errl != nullptr)
        {
            break;
        }

        // Take possession of the Atomic Lock
        TRACDCOMP(g_trac_spi, "Grabbing atomic lock");
        SpiControlHandle handle = i_spiOp->getSpiHandle();
        FAPI_INVOKE_HWP( errl,
                         spi_master_unlock,
                         handle,
                         HOSTBOOT_PIB_MASTER_ID );
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_spi, "Failure trying to release atomic lock");
            ERRORLOG::ErrlUserDetailsTarget(spiTarget, "Proc Target")
              .addToLog(errl);
            io_buflen = 0;
            break;
        }
        FAPI_INVOKE_HWP( errl,
                         spi_master_lock,
                         handle,
                         HOSTBOOT_PIB_MASTER_ID );
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_spi, "Failure trying to grab atomic lock");
            ERRORLOG::ErrlUserDetailsTarget(spiTarget, "Proc Target")
              .addToLog(errl);
            io_buflen = 0;
            break;
        }

        // =====================================================================
        // SPI Read Operation
        // =====================================================================
        if (i_opType == DeviceFW::READ)
        {
            // calls the derived class function
            errl = i_spiOp->read(io_buffer, io_buflen);

            if (errl != nullptr)
            {
                TRACUCOMP(g_trac_spi,
                          ERR_MRK"spiPerformOp(): Spi read operation failed!");
                break;
            }
        }
        // =====================================================================
        // SPI Write Operation
        // =====================================================================
        else if (i_opType == DeviceFW::WRITE)
        {
            // calls the derived class function
            errl = i_spiOp->write(io_buffer, io_buflen);
            if (errl != nullptr)
            {
                TRACUCOMP(g_trac_spi,
                          ERR_MRK"spiPerformOp(): Spi write operation failed!");
                break;
            }
        }
        else
        {
            // Unknown/Unsupported Operation Type
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         SPI::SPI_PERFORM_OP
            * @reasoncode       SPI::SPI_UNKNOWN_OP_TYPE
            * @userdata1        Target HUID of the SPI Master
            * @userdata2        op type
            * @devdesc          The requested op type is not supported.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPI_PERFORM_OP,
                                           SPI_UNKNOWN_OP_TYPE,
                                           TARGETING::get_huid(spiTarget),
                                           i_opType,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

    } while(0);

    if (mutex_should_unlock)
    {
        errlHndl_t unlockErrl = spiEngineLockOp(spiTarget,
                                                spiEngine,
                                                mutex_should_unlock);
        if (unlockErrl != nullptr)
        {
            if (errl == nullptr)
            {
                errl = unlockErrl;
            }
            else
            {
                TRACFCOMP(g_trac_spi, "spiPerformOp(): Committing second error "
                          "eid=0x%X with plid of returned error: 0x%X",
                          unlockErrl->eid(),
                          errl->plid());
                unlockErrl->plid(errl->plid());
                errlCommit(unlockErrl, SPI_COMP_ID);
            }
        }
    }

    return errl;
}


errlHndl_t spiEepromPerformOp(DeviceFW::OperationType i_opType,
                              TARGETING::Target*      i_controller_target,
                              void*                   io_buffer,
                              size_t&                 io_buflen,
                              int64_t                 i_accessType,
                              va_list                 i_args)
{
    errlHndl_t errl = nullptr;

    TRACUCOMP(g_trac_spi, ENTER_MRK"spiEepromPerformOp() opType(%s), "
              "i_controller_target(0x%X), io_buffer(%p), io_buflen(%d), "
              "i_accessType(%ld)",
              (i_opType == DeviceFW::READ) ? "READ" : "WRITE",
              TARGETING::get_huid(i_controller_target),
              io_buffer,
              io_buflen,
              i_accessType);

    // SPI master engine to use for this operation
    uint8_t engine = static_cast<uint8_t>(va_arg(i_args, uint64_t));

    // The offset to start the read or write from
    uint64_t offset = va_arg(i_args, uint64_t);

    SpiEepromOp spiOp = SpiEepromOp(i_controller_target,
                                    engine,
                                    offset,
                                    io_buflen,
                                    io_buffer);

    errl = spiPerformOp(i_opType, io_buffer, io_buflen, &spiOp);
    if (errl != nullptr)
    {
        UdSpiEepromParameters(i_opType,
                              i_accessType,
                              spiOp).addToLog(errl);

        errl->collectTrace(SPI_COMP_NAME, KILOBYTE);
    }

    return errl;
}

errlHndl_t spiTpmPerformOp(DeviceFW::OperationType i_opType,
                           TARGETING::Target*      i_controller_target,
                           void*                   io_buffer,
                           size_t&                 io_buflen,
                           int64_t                 i_accessType,
                           va_list                 i_args)
{
    errlHndl_t errl = nullptr;

    TRACUCOMP(g_trac_spi, ENTER_MRK"spiTpmPerformOp() opType(%s), "
              "i_controller_target(0x%X), io_buffer(%p), io_buflen(%d), "
              "i_accessType(%ld)",
              (i_opType == DeviceFW::READ) ? "READ" : "WRITE",
              TARGETING::get_huid(i_controller_target),
              io_buffer,
              io_buflen,
              i_accessType);

    // SPI master engine to use for this operation
    uint8_t engine = static_cast<uint8_t>(va_arg(i_args, uint64_t));

    // The offset to start the read or write from
    uint64_t offset = va_arg(i_args, uint64_t);

    uint32_t locality = va_arg(i_args, uint32_t);

    TARGETING::Target * tpmTarget = va_arg(i_args, TARGETING::Target *);

    SpiTpmOp spiOp = SpiTpmOp(i_controller_target,
                              engine,
                              offset,
                              locality,
                              tpmTarget);

    errl = spiPerformOp(i_opType, io_buffer, io_buflen, &spiOp);
    if (errl != nullptr)
    {
        UdSpiTpmParameters(i_opType,
                           i_accessType,
                           spiOp).addToLog(errl);

        errl->collectTrace(SPI_COMP_NAME, KILOBYTE);
    }

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
                          "Invalid engine for getting mutex. i_engine=%d",
                          i_engine);
                success = false;
                break;
        };
    } while(0);

    return success;
}

errlHndl_t spiEngineLockOp(TARGETING::Target* i_target,
                           const uint8_t      i_engine,
                                 bool&        io_unlock)
{
    errlHndl_t errl = nullptr;

    do {
        mutex_t * engine_lock = nullptr;
        bool mutexSuccess = spiGetEngineMutex(i_target,
                                              i_engine,
                                              engine_lock);

        if (!mutexSuccess)
        {
            TRACFCOMP(g_trac_spi, ERR_MRK"spiEngineLockOp(): "
                      "Failed to retrieve requested engine mutex! Engine %d",
                      i_engine);
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         SPI::SPI_ENGINE_LOCK_OP
            * @reasoncode       SPI::SPI_FAILED_TO_RETRIEVE_ENGINE_MUTEX
            * @userdata1        Target HUID of the SPI Master
            * @userdata2        Requested SPI Engine
            * @devdesc          The SPI engine mutex requested couldn't be
            *                   retrieved.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPI_ENGINE_LOCK_OP,
                                           SPI_FAILED_TO_RETRIEVE_ENGINE_MUTEX,
                                           TARGETING::get_huid(i_target),
                                           i_engine,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            io_unlock = false;
            break;
        }

        if (io_unlock)
        {
            mutex_unlock(engine_lock);
            io_unlock = false;
        }
        else
        {
            mutex_lock(engine_lock);
            io_unlock = true;
        }

    } while(0);

    return errl;
}

////////////////////////////////////////////////////////////////////////////////
// SpiOp
////////////////////////////////////////////////////////////////////////////////
SpiOp::SpiOp(TARGETING::Target* i_controller_target,
             const uint8_t      i_engine,
             const uint64_t     i_offset)
    : iv_target(i_controller_target),
      iv_offset(i_offset),
      iv_engine(i_engine)
{
}

void SpiOp::addStatusRegs(errlHndl_t& io_errl)
{
    do {
        if (io_errl == nullptr)
        {
            // io_errl cannot be nullptr.
            TRACFCOMP(g_trac_spi, ERR_MRK"SpiOp::addStatusRegs(): "
                      "io_errl was nullptr. Skip adding additional FFDC");
            break;
        }

        ERRORLOG::ErrlUserDetailsLogRegister registerUDSection(iv_target);

        // Calculates the base address for the SPI device we want to pull
        // register contents from.
        SpiControlHandle handle = getSpiHandle();

        // List of registers to collect data from.
        uint32_t registerList[] = {
            (SPIM_COUNTERREG     | handle.base_addr),
            (SPIM_CONFIGREG1     | handle.base_addr),
            (SPIM_CLOCKCONFIGREG | handle.base_addr),
            (SPIM_MMSPISMREG     | handle.base_addr),
            (SPIM_TDR            | handle.base_addr),
            (SPIM_RDR            | handle.base_addr),
            (SPIM_SEQREG         | handle.base_addr),
            (SPIM_STATUSREG      | handle.base_addr),
        };

        for (auto reg : registerList)
        {
            registerUDSection.addData(DEVICE_SCOM_ADDRESS(reg));
        }

        // Figure out if in FSI or PIB mode
        auto spiSwitch = iv_target->getAttr<TARGETING::ATTR_SPI_SWITCHES>();

        // Add Root Control Register as well in case the PIB bit was set
        // improperly
        if (spiSwitch.usePibSPI)
        {
            registerUDSection.addData(DEVICE_SCOM_ADDRESS(ROOT_CTRL_8_PIB));
        }
        else
        {
            registerUDSection.addData(DEVICE_FSI_ADDRESS(ROOT_CTRL_8_FSI));
        }

        registerUDSection.addToLog(io_errl);

    } while(0);
}

void SpiOp::addCallouts(errlHndl_t& io_errl)
{
    do {
        if (io_errl == nullptr)
        {
            // io_errl cannot be nullptr.
            TRACFCOMP(g_trac_spi, ERR_MRK"SpiOp::addCallouts(): "
                      "io_errl was nullptr. Skip adding additional FFDC");
            break;
        }

        // Do a medium callout on the SPI master proc
        io_errl->addHwCallout(iv_target,
                              HWAS::SRCI_PRIORITY_MED,
                              HWAS::NO_DECONFIG,
                              HWAS::GARD_NULL);

        // Do a low callout on HB code.
        io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);
    } while(0);
}

SpiControlHandle SpiOp::getSpiHandle()
{
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> chip_target(iv_target);

    auto spiSwitch = iv_target->getAttr<TARGETING::ATTR_SPI_SWITCHES>();

    // setup SPI handle based on spiSwitch attribute
    return SpiControlHandle(chip_target, iv_engine, 1, spiSwitch.usePibSPI);
}

TARGETING::Target* SpiOp::getControllerTarget() const
{
    return iv_target;
}

uint64_t SpiOp::getOffset() const
{
    return iv_offset;
}

uint8_t  SpiOp::getEngine() const
{
    return iv_engine;
}

////////////////////////////////////////////////////////////////////////////////
// SpiEepromOp
////////////////////////////////////////////////////////////////////////////////
SpiEepromOp::SpiEepromOp(TARGETING::Target* i_target,
                         const uint8_t      i_engine,
                         const uint64_t     i_offset,
                         const size_t       i_buflen,
                         void *             i_buffer)
    : SpiOp(i_target, i_engine, i_offset), iv_length(i_buflen)
{
    iv_start_index = (iv_offset % TRANSACTION_ALIGNMENT);
    setAdjustedOpArgs(i_buffer);
}

errlHndl_t SpiEepromOp::read(void*   o_buffer,
                             size_t& io_buflen)
{
    errlHndl_t errl = nullptr;
    SpiControlHandle handle = getSpiHandle();

    if(iv_usingAdjustedBuffer)
    {
        iv_buffer = new uint8_t[iv_adjusted_length];
    }

    do {
        if (io_buflen != iv_length)
        {
            // Something changed the buffer length after object construction.
            TRACFCOMP(g_trac_spi, ERR_MRK"SpiOp::read(): "
                      "Buffer length didn't match previously given buffer "
                      "length. buffer length %d, expected length %d.",
                      io_buflen,
                      iv_length);

            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         SPI::SPI_OP_READ
            * @reasoncode       SPI::SPI_BUFFER_SIZE_MISMATCH
            * @userdata1        Target HUID of the SPI Master
            * @userdata2[00:31] Length of the request
            * @userdata2[32:63] Expected length
            * @devdesc          The length of the buffer to write/read changed
            *                   from the expected length.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPI_OP_READ,
                                           SPI_BUFFER_SIZE_MISMATCH,
                                           TARGETING::get_huid(iv_target),
                                           TWO_UINT32_TO_UINT64(io_buflen,
                                                                iv_length));
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_MED);
            io_buflen = 0;
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
            TRACFCOMP(g_trac_spi, "SpiOp::read(): "
                      "spi_read HWP error with params: offset = %d, "
                      "length = %d, useAdjustedBuffer = %s",
                      iv_adjusted_offset,
                      iv_adjusted_length,
                      iv_usingAdjustedBuffer ? "TRUE" : "FALSE");
            addStatusRegs(errl);
            addCallouts(errl);
            ERRORLOG::ErrlUserDetailsTarget(iv_target, "Proc Target")
                .addToLog(errl);
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

    // If the op had to be aligned then make sure to delete the
    // adjusted buffer that was created for the aligned operation.
    if (iv_usingAdjustedBuffer && (iv_buffer != nullptr))
    {
        delete[] iv_buffer;
        iv_buffer = nullptr;
    }
    return errl;
}

errlHndl_t SpiEepromOp::write(void*   i_buffer,
                              size_t& io_buflen)
{
    errlHndl_t errl = nullptr;

    SpiControlHandle handle = getSpiHandle();

    if(iv_usingAdjustedBuffer)
    {
        iv_buffer = new uint8_t[iv_adjusted_length];
    }

    do {

        if (io_buflen != iv_length)
        {
            // Something changed the buffer length after object construction
            TRACFCOMP(g_trac_spi, ERR_MRK"SpiOp::write(): "
                      "Buffer length didn't match previously given buffer "
                      "length. buffer length %d, expected length %d.",
                      io_buflen,
                      iv_length);
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         SPI::SPI_OP_WRITE
            * @reasoncode       SPI::SPI_BUFFER_SIZE_MISMATCH
            * @userdata1        Target HUID of the SPI Master
            * @userdata2[00:31] Length of the request
            * @userdata2[32:63] Expected length
            * @devdesc          The length of the buffer to write/read changed
            *                   from the expected length.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPI_OP_WRITE,
                                           SPI_BUFFER_SIZE_MISMATCH,
                                           TARGETING::get_huid(iv_target),
                                           TWO_UINT32_TO_UINT64(io_buflen,
                                                                iv_length));
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_MED);
            io_buflen = 0;
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
                TRACFCOMP(g_trac_spi, "SpiOp::write(): "
                          "spi_read HWP error with params: "
                          "adjusted offset = %d, adjusted length = %d",
                          iv_adjusted_offset,
                          iv_adjusted_length);
                addStatusRegs(errl);
                addCallouts(errl);
                ERRORLOG::ErrlUserDetailsTarget(iv_target, "Proc Target")
                    .addToLog(errl);
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
            TRACFCOMP(g_trac_spi, "SpiOp::write(): "
                      "spi_write HWP error with params: offset = %d, "
                      "length = %d", iv_adjusted_offset, iv_adjusted_length);
            addStatusRegs(errl);
            addCallouts(errl);
            ERRORLOG::ErrlUserDetailsTarget(iv_target, "Proc Target")
                .addToLog(errl);
            io_buflen = 0;
            break;
        }

    } while(0);

    // If the op had to be aligned then make sure to delete the
    // adjusted buffer that was created for the aligned operation.
    if (iv_usingAdjustedBuffer && (iv_buffer != nullptr))
    {
        delete[] iv_buffer;
        iv_buffer = nullptr;
    }
    return errl;
}

errlHndl_t SpiEepromOp::copyToBuffer(void*           io_destination,
                                     size_t&         io_amountToCopy,
                                     uint8_t const * i_source,
                                     const size_t    i_sourceLength,
                                     const size_t    i_sourceOffset)
{
    errlHndl_t errl = nullptr;

    do {

        if (i_sourceOffset + io_amountToCopy > i_sourceLength)
        {
            TRACFCOMP(g_trac_spi, ERR_MRK"SPI::copyToBuffer() "
                     "Size to copy %d from offset %d exceeds buffer size %d!",
                     io_amountToCopy, i_sourceOffset, i_sourceLength);
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         SPI::SPI_COPY_TO_BUFFER
            * @reasoncode       SPI::SPI_INVALID_PARAMETERS
            * @userdata1[00:15] The offset from which to begin copying data
            * @userdata1[16:31] The amount of data to copy to the destination
            * @userdata1[32:47] Unused
            * @userdata1[48:63] The length of the source buffer.
            * @devdesc          The combination of the offset and amount to copy
            *                   given would have caused a buffer overrun.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPI_COPY_TO_BUFFER,
                                           SPI_INVALID_PARAMETERS,
                                           FOUR_UINT16_TO_UINT64(
                                               i_sourceOffset,
                                               io_amountToCopy,
                                               0, // Unused Parameter
                                               i_sourceLength),
                                           0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            addStatusRegs(errl);
            io_amountToCopy = 0;
            break;
        }

        memcpy(io_destination, &i_source[i_sourceOffset], io_amountToCopy);

    } while(0);

    return errl;
}


void SpiEepromOp::setAdjustedOpArgs(void * i_buffer)
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
        // aligned data when an operation is performed.
        iv_usingAdjustedBuffer = true;
        iv_buffer = nullptr;
    }

    TRACUCOMP(g_trac_spi, "SpiOp::setAdjustedOpArgs(): "
              "iv_length = %d, iv_adjusted_length = %d, "
              "iv_offset = %d, iv_adjusted_offset = %d",
              iv_length, iv_adjusted_length, iv_offset, iv_adjusted_offset);
}


void SpiEepromOp::addCallouts(errlHndl_t& io_errl)
{
    do {
        if (io_errl == nullptr)
        {
            // io_errl cannot be nullptr.
            TRACFCOMP(g_trac_spi, ERR_MRK"SpiEepromOp::addCallouts(): "
                      "io_errl was nullptr. Skip adding additional FFDC");
            break;
        }

        // Do a high callout on the SPI Device
        // Handle the different engines of the SPI Master
        switch(iv_engine)
        {
            case 0:
            case 1:
                // BOOT SEEPROM Primary and Backup
                io_errl->addPartCallout(iv_target,
                                        HWAS::SBE_SEEPROM_PART_TYPE,
                                        HWAS::SRCI_PRIORITY_HIGH,
                                        HWAS::NO_DECONFIG,
                                        HWAS::GARD_NULL);
                break;
            case 2:
            case 3:
                // MVPD Primary and Backup
                io_errl->addPartCallout(iv_target,
                                        HWAS::VPD_PART_TYPE,
                                        HWAS::SRCI_PRIORITY_HIGH,
                                        HWAS::NO_DECONFIG,
                                        HWAS::GARD_NULL);
                break;
            case 4:  // TPM (handled by SpiTpmOp)
                break;
            case 5:
                // DUMP
                io_errl->addPartCallout(iv_target,
                                        HWAS::SPI_DUMP_PART_TYPE,
                                        HWAS::SRCI_PRIORITY_HIGH,
                                        HWAS::NO_DECONFIG,
                                        HWAS::GARD_NULL);
                break;
            default:
                break;
        };

        // Add the lower level SPI callouts
        SpiOp::addCallouts(io_errl);

    } while (0);
}

uint64_t SpiEepromOp::getLength() const
{
    return iv_length;
}

uint64_t SpiEepromOp::getAdjustedOffset() const
{
    return iv_adjusted_offset;
}

uint64_t SpiEepromOp::getAdjustedLength() const
{
    return iv_adjusted_length;
}

uint8_t SpiEepromOp::getStartIndex() const
{
    return iv_start_index;
}

bool SpiEepromOp::getUsingAdjustedBuffer() const
{
    return iv_usingAdjustedBuffer;
}

///////////////////////////////////////////////////////////////////////////////
// SpiTpmOp
///////////////////////////////////////////////////////////////////////////////
SpiTpmOp::SpiTpmOp(TARGETING::Target* i_controller_target,
                   const uint8_t            i_engine,
                   const uint64_t           i_offset,
                   const uint32_t           i_locality,
                   TARGETING::Target* i_tpm_target)
                   : SpiOp(i_controller_target, i_engine, i_offset),
                    iv_locality(i_locality), iv_tpmTarget(i_tpm_target)
{
}

errlHndl_t SpiTpmOp::read(void* o_buffer, size_t& io_buflen)
{
    errlHndl_t errl = nullptr;

    TRACUCOMP(g_trac_spi, "SpiTpmOp::read() - calling "
            "spi_tpm_read_secure HWP with params: "
            "locality = %d, offset = 0x%llx, length = %d",
            iv_locality, iv_offset, io_buflen);

    SpiControlHandle handle = getSpiHandle();
    FAPI_INVOKE_HWP(errl,
                    spi_tpm_read_secure,
                    handle,
                    iv_locality,
                    iv_offset,
                    io_buflen,
                    reinterpret_cast<uint8_t*>(o_buffer));
    if (errl != nullptr)
    {
        TRACFCOMP(g_trac_spi, ERR_MRK "SpiTpmOp::read(): "
                  "spi_tpm_read_secure HWP error with params: "
                  "locality = %d, offset = 0x%llx, length = %d",
                  iv_locality, iv_offset, io_buflen);
        addStatusRegs(errl);
        addCallouts(errl);
        ERRORLOG::ErrlUserDetailsTarget(iv_target, "Proc Target")
            .addToLog(errl);
        io_buflen = 0;
    }

    return errl;
}

errlHndl_t SpiTpmOp::write(void* i_buffer, size_t& io_buflen)
{
    errlHndl_t errl = nullptr;

    TRACUCOMP(g_trac_spi, "SpiTpmOp::write() - calling "
            "spi_tpm_write_with_wait HWP with params: "
            "locality = %d, offset = 0x%llx, length = %d",
            iv_locality, iv_offset, io_buflen);

    SpiControlHandle handle = getSpiHandle();
    FAPI_INVOKE_HWP(errl,
                    spi_tpm_write_with_wait,
                    handle,
                    iv_locality,
                    iv_offset,
                    io_buflen,
                    reinterpret_cast<uint8_t*>(i_buffer));
    if (errl != nullptr)
    {
        TRACFCOMP(g_trac_spi, ERR_MRK "SpiTpmOp::write(): "
                  "spi_tpm_write_with_wait HWP error with params: "
                  "locality = %d, offset = 0x%llx, length = %d",
                  iv_locality, iv_offset, io_buflen);
        addStatusRegs(errl);
        addCallouts(errl);
        ERRORLOG::ErrlUserDetailsTarget(iv_target, "Proc Target")
            .addToLog(errl);
    }
    return errl;
}

uint32_t SpiTpmOp::getLocality() const
{
    return iv_locality;
}

const TARGETING::Target* SpiTpmOp::getTpmTarget() const
{
    return iv_tpmTarget;
}

void SpiTpmOp::addCallouts(errlHndl_t& io_errl)
{
    do {
        if (io_errl == nullptr)
        {
            // io_errl cannot be nullptr.
            TRACFCOMP(g_trac_spi, ERR_MRK"SpiTpmOp::addCallouts(): "
                      "io_errl was nullptr. Skip adding additional FFDC");
            break;
        }

        // Callout TPM HW
        io_errl->addHwCallout(iv_tpmTarget,
                              HWAS::SRCI_PRIORITY_HIGH,
                              HWAS::NO_DECONFIG,
                              HWAS::GARD_NULL);

        // Add the lower level SPI callouts
        SpiOp::addCallouts(io_errl);

    } while (0);
}

}; // end namespace SPI
