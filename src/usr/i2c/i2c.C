/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/i2c.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
/**
 * @file i2c.C
 *
 * @brief Implementation of the i2c device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>  // ERRORLOG::ErrlUserDetailsString
#include <targeting/common/entitypath.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/predicates/predicates.H>
#include <devicefw/driverif.H>
#include <fsi/fsiif.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/i2cif.H>
#include <attributetraits.H>
#include <i2c/i2c.H>
#include "errlud_i2c.H"
#include <secureboot/trustedbootif.H>
#include <secureboot/service.H>
#include <eeprom/eepromif.H>
#include <hwas/common/hwas.H>  // HwasState
#include <algorithm>

// ----------------------------------------------
// Globals
// ----------------------------------------------

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_i2c = nullptr;
TRAC_INIT( & g_trac_i2c, I2C_COMP_NAME, KILOBYTE );

trace_desc_t* g_trac_i2cr = nullptr;
TRAC_INIT( & g_trac_i2cr, "I2CR", KILOBYTE );


// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// ----------------------------------------------
// Defines
// ----------------------------------------------
#define I2C_RESET_DELAY_NS (5 * NS_PER_MSEC)  // Sleep for 5 ms after reset
#define I2C_RESET_POLL_DELAY_NS (500 * 1000)  // Sleep for 500usec per poll
#define I2C_RESET_POLL_DELAY_TOTAL_NS (500 * NS_PER_MSEC) // Total time to poll

#define MAX_NACK_RETRIES 3
#define PAGE_OPERATION 0xffffffff  // Special value use to determine type of op
#define P10_ENGINE_SCOM_OFFSET 0x1000
constexpr uint64_t FSI_BUS_SPEED_MHZ = 133; //FSI runs at 133MHz

// Derived from ATTR_I2C_BUS_SPEED_ARRAY[engine][port] attribute
#define I2C_BUS_ATTR_MAX_ENGINE                                     \
    I2C_BUS_MAX_ENGINE(TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type{})
#define I2C_BUS_ATTR_MAX_PORT                                       \
    I2C_BUS_MAX_PORT(TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type{})
#define FSI_MODE_MAX_PORT 18 // Engine A has 18 ports

// ----------------------------------------------

namespace I2C
{

namespace SMBUS
{

uint8_t calculatePec(
    const uint8_t* const i_pData,
    const size_t         i_size)
{
    uint8_t pec = 0;

    for (size_t index=0; index<i_size; ++index)
    {
       pec ^= i_pData[index];
       pec = pec ^ (pec<<1) ^ (pec<<2) ^ ((pec&128)?9:0) ^ ((pec&64)?7:0);
    }

    return pec;
}

BlockWrite::BlockWrite(
           const uint8_t       i_address,
           const uint8_t       i_commandCode,
           const uint8_t       i_byteCount,
           const void*   const i_pDataBytes,
           const bool          i_usePec)

  : writeAddr(i_address),
    commandCode(i_commandCode),
    byteCount(i_byteCount)
{
    memcpy(dataBytes,i_pDataBytes,i_byteCount);
    memset(dataBytes+i_byteCount,0x00,sizeof(dataBytes)-i_byteCount);
    messageSize =   offsetof(I2C::SMBUS::BlockWrite,dataBytes)
                  + byteCount - sizeof(writeAddr);
    if(i_usePec)
    {
        ++messageSize;
        const auto pec = I2C::SMBUS::calculatePec(
            reinterpret_cast<uint8_t*>(&writeAddr),
            messageSize);
        *(reinterpret_cast<uint8_t*>(&writeAddr)+messageSize)=pec;
    }
}

WriteByteOrWord::WriteByteOrWord(
        const uint8_t       i_address,
        const uint8_t       i_commandCode,
        const uint8_t       i_byteCount,
        const void*   const i_pDataBytes,
        const bool          i_usePec)
    : writeAddr(i_address),
      commandCode(i_commandCode),
      byteCount(i_byteCount)
{
    assert(((byteCount==1) || (byteCount==2)),
        "Invalid byte count %d for write byte or write word",
        byteCount);
    memcpy(dataBytes,i_pDataBytes,byteCount);
    memset(dataBytes+byteCount,0x00,sizeof(dataBytes)-byteCount);
    messageSize =   offsetof(I2C::SMBUS::WriteByteOrWord,dataBytes)
                  - offsetof(I2C::SMBUS::WriteByteOrWord,commandCode)
                  + byteCount;
    if(i_usePec)
    {
        // Currently message size does not reflect the address.  If we
        // are adding a PEC byte, that will up the amount of data we need
        // to transmit.  Leverage the preincrement to calculate the PEC over
        // the right number of bytes.
        const auto pec = I2C::SMBUS::calculatePec(
            reinterpret_cast<uint8_t*>(&writeAddr),
            ++messageSize);
        *(dataBytes+byteCount)=pec;
    }
}

SendByte::SendByte(const uint8_t       i_address,
                   const void*   const i_pDataByte,
                   const bool          i_usePec)
    : writeAddr(i_address),
      dataByte(*reinterpret_cast<const uint8_t*>(i_pDataByte))
{
    messageSize =   offsetof(I2C::SMBUS::SendByte,pec)
                  - offsetof(I2C::SMBUS::SendByte,dataByte);
    if(i_usePec)
    {
        // Currently message size does not reflect the address.  If we
        // are adding a PEC byte, that will up the amount of data we need
        // to transmit.  Leverage the preincrement to calculate the PEC over
        // the right number of bytes.
        pec = I2C::SMBUS::calculatePec(
            reinterpret_cast<uint8_t*>(&writeAddr),
            ++messageSize);
    }
}

} // End SMBUS namespace

// Register the generic I2C perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::I2C,
                       TARGETING::TYPE_PROC,
                       i2cPerformOp );

/*
 * @brief     A helper function for i2cCommonOp that commonizes error handling
 *            for a bad PEC byte for a power sequencer.
 *
 * @param[in]      i_expectedPec  The value of the expected PEC byte.
 *
 * @param[in]      i_actualPec    The value of the actual PEC byte.
 *
 * @param[in]      i_i2cMaster    The i2c master for the power sequencer.
 *
 * @param[in]      i_args         The i2c info for the power sequencer.
 *
 * @return         errlHndl_t     A pointer to an error log.
 */
errlHndl_t badPecByteError(const uint8_t                      i_expectedPec,
                           const uint8_t                      i_actualPec,
                           const TARGETING::TargetHandle_t&   i_i2cMaster,
                           const misc_args_t                  i_args)
{
    /*@
    * @errortype
    * @severity             ERRL_SEV_PREDICTIVE
    * @moduleid             I2C_BAD_PEC_BYTE_ERROR
    * @reasoncode           I2C_BAD_PEC_BYTE
    * @devdesc              A bad PEC byte was found during the
    *                       device operation.
    * @custdesc             Unexpected firmware error
    * @userdata1[00:31]     Expected PEC byte
    * @userdata1[32:63]     Actual PEC byte
    */
    errlHndl_t err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             I2C_BAD_PEC_BYTE_ERROR,
                                             I2C_BAD_PEC_BYTE,
                                             TWO_UINT32_TO_UINT64(
                                                 i_expectedPec,
                                                 i_actualPec));

    // Add a callout for the I2C master.
    err->addI2cDeviceCallout(i_i2cMaster,
                             i_args.engine,
                             i_args.port,
                             i_args.devAddr,
                             HWAS::SRCI_PRIORITY_HIGH);

    // Add a callout for hostboot code.
    err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_LOW);

    err->collectTrace(I2C_COMP_NAME);

    return err;

}


/**
 *
 * @brief A useful utility to dump (trace out) the TARGETING::FapiI2cControlInfo
 *        data. Use as needed.
 *
 * @param [in] i_args - The TARGETING::FapiI2cControlInfo data to dump for
 *                       consumption
 *
 */
void dumpFapiI2cControlInfo(const TARGETING::FapiI2cControlInfo & i_args)
{
    char* l_masterTargetPath = i_args.i2cMasterPath.toString();
    char* l_muxPath = i_args.i2cMuxPath.toString();

    TRACFCOMP( g_trac_i2c,"dumpFapiI2cControlInfo: "
               "port(%d), engine(%d), devAddr(0x%X), i2cMasterPath(%s), "
               "i2cMuxBusSelector(%d), i2cMuxPath(%s)",
               i_args.port, i_args.engine, i_args.devAddr, l_masterTargetPath,
               i_args.i2cMuxBusSelector, l_muxPath);

    free(l_masterTargetPath);
    free(l_muxPath);
    l_masterTargetPath = l_muxPath = nullptr;
}


/**
 *
 * @brief A useful utility to dump (trace out) the I2C::misc_args_t data.
 *        Use as needed.
 *
 * @param [in] i_args - The I2C::misc_args_t data to dump for consumption
 *
 */
void dumpMiscArgsData(const I2C::misc_args_t & i_args)
{
    char* l_muxPath{nullptr};
    if (i_args.i2cMuxPath)
    {
        l_muxPath = i_args.i2cMuxPath->toString();
    }

    TRACFCOMP( g_trac_i2c,"dumpMiscArgsData: subop(0x%016llX), "
               "engine(%d), port(%d), devAddr(0x%X), skip_mode_step(%d), "
               "with_stop(%d), read_not_write(%d), with_address(%d), "
               "with_start(%d)",
               i_args.subop,i_args.engine, i_args.port, i_args.devAddr,
               i_args.skip_mode_setup, i_args.with_stop,
               i_args.read_not_write, i_args.with_address,
               i_args.with_start);

    TRACFCOMP( g_trac_i2c,"dumpMiscArgsData cont.: read_continue(%d), "
               "bus_speed(%d), bit_rate_divisor(%d), polling_interval_ns(%d), "
               "timeout_count(%d), offset_length(%d), offset_buffer(%p/0x%X)",
               i_args.read_continue,i_args.bus_speed,i_args.bit_rate_divisor,
               i_args.polling_interval_ns,
               i_args.timeout_count, i_args.offset_length,
               i_args.offset_buffer,
               (0x0 == i_args.offset_buffer ? 0 : *(i_args.offset_buffer) ) );

    TRACFCOMP( g_trac_i2c,"dumpMiscArgsData cont.: "
               "i2cMuxBusSelector(%d), i2cMuxPath(%s)",
               i_args.i2cMuxBusSelector,
               ( (nullptr == l_muxPath) ? "NULL" : l_muxPath ) );

    free(l_muxPath);
    l_muxPath = nullptr;
}

#if 0 // Useful to enable for debug
void read_status( TARGETING::Target * i_target,
                  misc_args_t & i_args )
{
    errlHndl_t err = nullptr;

    // Read the status Reg
    status_reg_t stat;
    stat.value=0;
    err = i2cRegisterOp( DeviceFW::READ,
                         i_target,
                         &stat.value,
                         I2C_REG_STATUS,
                         i_args );
    if( err )
    {
        delete err;
    }
    TRACFCOMP(g_trac_i2c,"Reading I2C_REG_STATUS(7)=%.8X",
              stat.value);

    // Read the extended status Reg
    int I2C_REG_EXTENDED_STATUS = 0x8;
    extended_status_reg_t extstat;
    extstat.value=0;
    err = i2cRegisterOp( DeviceFW::READ,
                         i_target,
                         &extstat.value,
                         I2C_REG_EXTENDED_STATUS,
                         i_args );
    if( err )
    {
        delete err;
    }
    TRACFCOMP(g_trac_i2c,"Reading I2C_REG_EXTENDED_STATUS(8)=%.8X",
              extstat.value);
}
#endif // debug only

// ------------------------------------------------------------------
// i2cPerformOp
// ------------------------------------------------------------------
errlHndl_t i2cPerformOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         va_list i_args )
{
    TRACUCOMP( g_trac_i2c, ENTER_MRK"i2cPerformOp() opType(%s), "
              "i_target(0x%X), io_buffer(%p), io_buflen(%d),  "
              "i_accessType(%d)",
              i_opType == DeviceFW::READ ? "READ" : "WRITE",
              TARGETING::get_huid(i_target),
              io_buffer,
              io_buflen,
              i_accessType);

    errlHndl_t err = nullptr;

    // Get the input args our of the va_list
    //  Address, Port, Engine, Device Addr.
    // Other args set below
    misc_args_t args;

    // Read in the sub-operation
    const auto subop =
        static_cast<DeviceFW::I2C_SUBOP>(va_arg(i_args,uint64_t));

    args.port = va_arg( i_args, uint64_t );
    args.engine = va_arg( i_args, uint64_t );
    args.devAddr = va_arg( i_args, uint64_t );

    // These are additional parms in the case an offset is passed in
    // via va_list, as well

    // Set both Host and FSI switches to 0 so that they get set later by
    // attribute in i2cCommonOp()
    args.switches.useHostI2C = 0;
    args.switches.useFsiI2C  = 0;

    // Decide if page select was requested (denoted with special device address)
    if( args.devAddr == PAGE_OPERATION )
    {

        // since this was a page operation, next arg will be whether we want to
        // lock the page, or unlock
        bool l_lockOp = static_cast<bool>(va_arg(i_args, int));
        if(l_lockOp)
        {
            //If page select requested, desired page would be passed in va_list
            uint8_t l_desiredPage = static_cast<uint8_t>(va_arg(i_args, int ));

            bool l_lockMutex = static_cast<bool>(va_arg(i_args, int));
            err = i2cPageSwitchOp( i_opType,
                                    i_target,
                                    i_accessType,
                                    l_desiredPage,
                                    l_lockMutex,
                                    args );

            if( err )
            {
                TRACFCOMP(g_trac_i2c, "Locking the page FAILED");
                bool l_pageUnlockSuccess = false;
                l_pageUnlockSuccess = i2cPageUnlockOp( i_target,
                                                    args );
                if( !l_pageUnlockSuccess )
                {
                    TRACFCOMP(g_trac_i2c,
                        "An Error occurred when unlocking page after"
                        " failure to lock the page!");
                }
            }
        }
        else
        {
            bool l_pageUnlockSuccess;
            l_pageUnlockSuccess = i2cPageUnlockOp( i_target,
                                                   args );
            if( !l_pageUnlockSuccess )
            {
                TRACFCOMP(g_trac_i2c,"i2cPerformOp::i2cPageUnlockOp - Failure unlocking the page");
                /*@
                 * @errortype
                 * @reasoncode      I2C_FAILURE_UNLOCKING_EEPROM_PAGE
                 * @severity        ERRORLOG_SEV_UNRECOVERABLE
                 * @moduleid        I2C_PERFORM_OP
                 * @userdata1       Target Huid
                 * @userdata2       <UNUSED>
                 * @devdesc         I2C master encountered an error while
                 *                  trying to unlock the eepromPage
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               I2C_PERFORM_OP,
                                               I2C_FAILURE_UNLOCKING_EEPROM_PAGE,
                                               TARGETING::get_huid(i_target),
                                               0x0,
                                               ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
                // TODO RTC 148705: Callout downstream DIMMs
                err->collectTrace(I2C_COMP_NAME, 256 );
            }
        }

    }
    // Else this is not a page operation, call the normal common function
    else
    {
        if(   (subop==DeviceFW::I2C_SMBUS_BLOCK)
           || (subop==DeviceFW::I2C_SMBUS_BYTE)
           || (subop==DeviceFW::I2C_SMBUS_WORD))
        {
            args.smbus.commandCode =
                static_cast<decltype(args.smbus.commandCode)>(
                    va_arg(i_args,uint64_t));
            args.smbus.usePec = true; // All implementations use PEC
            args.i2cMuxBusSelector = va_arg(i_args,uint64_t);
            args.i2cMuxPath = reinterpret_cast<const TARGETING::EntityPath*>(
                va_arg(i_args, uint64_t));
        }
        else if(subop==DeviceFW::I2C_SMBUS_SEND_OR_RECV)
        {
            args.smbus.usePec = true; // All implementations use PEC
            args.i2cMuxBusSelector = va_arg(i_args,uint64_t);
            args.i2cMuxPath = reinterpret_cast<const TARGETING::EntityPath*>(
                va_arg(i_args, uint64_t));
        }
        else // Standard ops
        {
            args.offset_length = va_arg( i_args, uint64_t);
            uint8_t* temp = reinterpret_cast<uint8_t*>(
                va_arg(i_args, uint64_t));
            args.i2cMuxBusSelector = va_arg( i_args, uint64_t);
            args.i2cMuxPath = reinterpret_cast<const TARGETING::EntityPath*>(
                va_arg(i_args, uint64_t));
            if ( args.offset_length != 0 )
            {
                args.offset_buffer = temp;

            }
        }

        args.subop=subop;

        err = i2cCommonOp( i_opType,
                           i_target,
                           io_buffer,
                           io_buflen,
                           i_accessType,
                           args );
    }

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cPerformOp() - %s",
               ((nullptr == err) ? "No Error" : "With Error") );

    return err;
} // end i2cPerformOp

// ------------------------------------------------------------------
// common_i2cPerformOp
// ------------------------------------------------------------------
static errlHndl_t common_i2cPerformOp( DeviceFW::OperationType i_opType,
                                       TARGETING::Target * i_target,
                                       void * io_buffer,
                                       size_t & io_buflen,
                                       int64_t i_accessType,
                                       va_list i_args,
                                       const bool i_isFsi )
{
    TRACUCOMP( g_trac_i2c, ENTER_MRK"%s_i2cPerformOp()",
               i_isFsi ? "fsi" : "host");

    errlHndl_t err = nullptr;

    // Get the input args our of the va_list
    //  Address, Port, Engine, Device Addr.
    // Other args set below
    misc_args_t args;
    args.port = va_arg( i_args, uint64_t );
    args.engine = va_arg( i_args, uint64_t );
    args.devAddr = va_arg( i_args, uint64_t );

    // These are additional parms in the case an offset is passed in
    // via va_list, as well

    args.offset_length = va_arg( i_args, uint64_t);
    uint8_t* temp = reinterpret_cast<uint8_t*>(va_arg(i_args, uint64_t));
    args.i2cMuxBusSelector = va_arg( i_args, uint64_t);
    args.i2cMuxPath = reinterpret_cast<const TARGETING::EntityPath*>(va_arg(i_args, uint64_t));

    if ( args.offset_length != 0 )
    {
        args.offset_buffer = temp;
    }

    // Set Host switch to and FSI switch appropriately
    args.switches.useHostI2C = !i_isFsi;
    args.switches.useFsiI2C  = i_isFsi;


    // Call common function
    err = i2cCommonOp( i_opType,
                       i_target,
                       io_buffer,
                       io_buflen,
                       i_accessType,
                       args );


    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"%s_i2cPerformOp() - %s",
               i_isFsi ? "fsi" : "host",
               ((nullptr == err) ? "No Error" : "With Error") );

    return err;
} // end common_i2cPerformOp

// Register the Host-based I2C perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::HOSTI2C,
                       TARGETING::TYPE_PROC,
                       host_i2cPerformOp );

// ------------------------------------------------------------------
// host_i2cPerformOp
// ------------------------------------------------------------------
errlHndl_t host_i2cPerformOp( DeviceFW::OperationType i_opType,
                              TARGETING::Target * i_target,
                              void * io_buffer,
                              size_t & io_buflen,
                              int64_t i_accessType,
                              va_list i_args )
{
    return common_i2cPerformOp( i_opType,
                                i_target,
                                io_buffer,
                                io_buflen,
                                i_accessType,
                                i_args,
                                false ); // host operation
} // end host_i2cPerformOp


// Register the FSI-based I2C perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::FSI_I2C,
                       TARGETING::TYPE_PROC,
                       fsi_i2cPerformOp );

// ------------------------------------------------------------------
// fsi_i2cPerformOp
// ------------------------------------------------------------------
errlHndl_t fsi_i2cPerformOp( DeviceFW::OperationType i_opType,
                             TARGETING::Target * i_target,
                             void * io_buffer,
                             size_t & io_buflen,
                             int64_t i_accessType,
                             va_list i_args )
{
    return common_i2cPerformOp( i_opType,
                                i_target,
                                io_buffer,
                                io_buflen,
                                i_accessType,
                                i_args,
                                true ); // fsi operation
} // end fsi_i2cPerformOp


// ------------------------------------------------------------------
// i2cHandleError
// ------------------------------------------------------------------
void i2cHandleError( TARGETING::Target * i_target,
                     errlHndl_t & i_err,
                     misc_args_t & i_args )
{
    errlHndl_t err_reset = nullptr;
    TRACUCOMP(g_trac_i2c, ENTER_MRK"i2cHandlError()");
    if( i_err )
    {
        // if it was a bus arbitration lost error set the
        // the reset level so a force unlock reset can be performed
        i2c_reset_level l_reset_level = BASIC_RESET;

        if ( i_err->reasonCode() == I2C_ARBITRATION_LOST_ONLY_FOUND )
        {

            l_reset_level = FORCE_UNLOCK_RESET;
        }

        // Reset the I2C Master
        err_reset = i2cReset( i_target,
                              i_args,
                              l_reset_level);

        if( err_reset )
        {
            // 2 error logs, so commit the reset log here
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cCommonOp() - "
                    "Previous error (rc=0x%X, eid=0x%X) before "
                    "i2cReset() failed.  Committing reset error "
                    "(rc=0x%X, eid=0x%X) and returning original error",
                    i_err->reasonCode(), i_err->eid(),
                    err_reset->reasonCode(), err_reset->eid() );

            errlCommit( err_reset, I2C_COMP_ID );

       }

        // Sleep to allow devices to recover from reset
        nanosleep( 0, I2C_RESET_DELAY_NS );

    }
    TRACUCOMP(g_trac_i2c, EXIT_MRK"i2cHandlError()");
}


errlHndl_t i2cChooseEepromPage(TARGETING::Target * i_target,
                               uint8_t & i_currentPage,
                               uint8_t & i_newPage,
                               uint8_t i_desiredPage,
                               misc_args_t & i_args,
                               bool & i_pageSwitchNeeded )
{
    errlHndl_t l_err = nullptr;
    // Get EEPROM page attribute
    TRACUCOMP(g_trac_i2c,
            "i2cChooseEepromPage: current EEPROM page is %d for target(0x%x)",
            i_currentPage,
            TARGETING::get_huid(i_target) );
    if( i_currentPage != i_desiredPage )
    {
        if( i_desiredPage == PAGE_ONE )
        {
            TRACUCOMP(g_trac_i2c, "i2cChooseEepromPage: Switching to page ONE");
            i_args.devAddr = PAGE_ONE_ADDR;
            i_newPage = PAGE_ONE;
            i_pageSwitchNeeded = true;
        }
        else if( i_desiredPage == PAGE_ZERO )
        {
            TRACUCOMP(g_trac_i2c, "i2cChooseEepromPage: Switching to page ZERO");
            i_args.devAddr = PAGE_ZERO_ADDR;
            i_newPage = PAGE_ZERO;
            i_pageSwitchNeeded = true;
        }
        else
        {
            TRACFCOMP(g_trac_i2c, ERR_MRK"i2cChooseEepromPage: Invalid page requested");
            /*@
             * @errortype
             * @reasoncode      I2C_INVALID_EEPROM_PAGE_REQUEST
             * @severity        ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid        I2C_CHOOSE_EEPROM_PAGE
             * @userdata1       Target Huid
             * @userdata2       Requested Page
             * @devdesc         There was a request for an invalid
             *                  EEPROM page
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             I2C_CHOOSE_EEPROM_PAGE,
                                             I2C_INVALID_EEPROM_PAGE_REQUEST,
                                             TARGETING::get_huid(i_target),
                                             i_desiredPage,
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            l_err->collectTrace( I2C_COMP_NAME, 256 );
        }
    }

    return l_err;
}

// ------------------------------------------------------------------
// i2cPageSwitchOp
// ------------------------------------------------------------------
errlHndl_t i2cPageSwitchOp( DeviceFW::OperationType i_opType,
                             TARGETING::Target * i_target,
                             int64_t i_accessType,
                             uint8_t i_desiredPage,
                             bool i_lockMutex,
                             misc_args_t & i_args )
{
    TRACUCOMP(g_trac_i2c, ENTER_MRK"i2cPageSwitchOp");

    errlHndl_t l_err = nullptr;
    errlHndl_t l_err_NACK = nullptr;
    bool l_mutexSuccess = false;
    bool l_pageSwitchNeeded = false;
    bool l_mutex_needs_unlock = false;

    bool l_error = false;
    mutex_t * l_pageLock = nullptr;

    uint8_t l_currentPage;
    uint8_t l_newPage;
    TARGETING::ATTR_EEPROM_PAGE_ARRAY_type page_array;

    do
    {

        // Check for Master Sentinel chip
        if( TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cPageSwitchOp() - Cannot target Master Sentinel "
                       "Chip for an I2C Operation!" );

            /*@
             * @errortype
             * @reasoncode     I2C_MASTER_SENTINEL_TARGET
             * @severity       ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid       I2C_PAGE_SWITCH_OP
             * @userdata1      Operation Type requested
             * @userdata2      <UNUSED>
             * @devdesc        Master Sentinel chip was used as a target for an
             *                 I2C operation.  This is not permitted.
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_PAGE_SWITCH_OP,
                                           I2C_MASTER_SENTINEL_TARGET,
                                           i_opType,
                                           0x0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            l_err->collectTrace( I2C_COMP_NAME, 256);

            break;
        }

        //Set Host vs Fsi switches if not done already
        i2cSetSwitches(i_target, i_args);



        if(i_lockMutex)
        {
            //get page mutex
            l_mutexSuccess = i2cGetPageMutex(i_target,
                                           i_args,
                                           l_pageLock );
            if(!l_mutexSuccess)
            {
                TRACUCOMP(g_trac_i2c,
                          ERR_MRK"Error in i2cPageSwitchOp::i2cGetPageMutex()");
                /*@
                 * @errortype
                 * @reasoncode     I2C_INVALID_EEPROM_PAGE_MUTEX
                 * @severity       ERRORLOG_SEV_UNRECOVERABLE
                 * @moduleid       I2C_PAGE_SWITCH_OP
                 * @userdata1      Target Huid
                 * @userdata2      <UNUSED>
                 * @devdesc        There was an error retrieving the EEPROM page
                 *                 mutex for this i2c master engine
                 */
                l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                 I2C_PAGE_SWITCH_OP,
                                                 I2C_INVALID_EEPROM_PAGE_MUTEX,
                                                 TARGETING::get_huid(i_target),
                                                 0x0,
                                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

                l_err->collectTrace( I2C_COMP_NAME, 256 );
                break;
            }

            (void)mutex_lock( l_pageLock );
        }
        // Calculate variables related to I2C Bus speed in 'args' struct
        l_err = i2cSetBusVariables( i_target, I2C_BUS_SPEED_FROM_MRW, i_args);

        if( l_err )
        {
            TRACFCOMP(g_trac_i2c,
                      ERR_MRK"Error in i2cPageSwitchOp::i2cSetBusVariables()");

            // Error means we need to unlock the page mutex prematurely
            l_mutex_needs_unlock = true;
            // Skip performing actual I2C Operation
            break;
        }


        //Get the i2c master page array attribute
        if( !(i_target->tryGetAttr<TARGETING::ATTR_EEPROM_PAGE_ARRAY>
                                            (page_array ) ) )
        {
            TRACFCOMP(g_trac_i2c,
                      "i2cPageSwitchOp() - Cannot find ATTR_EEPROM_PAGE_ARRAY");
            /*@
             * @errortype
             * @reasoncode      I2C_ATTRIBUTE_NOT_FOUND
             * @severity        ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid        I2C_PAGE_SWITCH_OP
             * @userdata1       Target HUID for the attribute
             * @userdata2       <UNUSED>
             * @devdesc         ATTR_EEPROM_PAGE_ARRAY not found
             * @custdesc        I2C configuration data missing
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             I2C_PAGE_SWITCH_OP,
                                             I2C_ATTRIBUTE_NOT_FOUND,
                                             TARGETING::get_huid(i_target),
                                             0x0,
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            l_err->collectTrace( I2C_COMP_NAME, 256 );
            l_mutex_needs_unlock = true;
            break;
        }

        // Get the current page for this i2c bus
        l_currentPage = page_array[i_args.engine][i_args.port];

        // Choose the correct EEPROM page
        l_err = i2cChooseEepromPage( i_target,
                                     l_currentPage,
                                     l_newPage,
                                     i_desiredPage,
                                     i_args,
                                     l_pageSwitchNeeded );

        if( l_err )
        {
            TRACFCOMP(g_trac_i2c,
                 ERR_MRK"Error in i2cPageSwitchOp::i2cChooseEepromPage()");
            l_mutex_needs_unlock = true;
            break;
        }

        // If we found that a page switch was needed, perform the
        // necessary write operation to switch to the desired page
        if( l_pageSwitchNeeded )
        {
            // Perform the actual write operation to switch pages.
            i_args.read_not_write  = false;
            i_args.with_stop       = true;
            i_args.skip_mode_setup = false;


            //going to write 2 bytes of zeros to special device address
            size_t l_zeroBuflen = 2;
            uint8_t * l_zeroBuffer = static_cast<uint8_t*>(malloc(l_zeroBuflen));
            memset(l_zeroBuffer, 0, l_zeroBuflen);

            TRACUCOMP(g_trac_i2c,"i2cPageSwitchOp args! \n"
                    "misc_args_t: port:%d / engine: %d: devAddr: %x: skip_mode_step(%d):\n"
                    "with_stop(%d): read_not_write(%d): bus_speed: %d: bit_rate_divisor: %d:\n"
                    "polling_interval_ns: %d: timeout_count: %d: offset_length: %d, ",
                    i_args.port, i_args.engine, i_args.devAddr, i_args.skip_mode_setup,
                    i_args.with_stop, i_args.read_not_write, i_args.bus_speed,
                    i_args.bit_rate_divisor, i_args.polling_interval_ns, i_args.timeout_count,
                    i_args.offset_length);

            // Printing mux info separately, if combined, nothing is displayed
            if (i_args.i2cMuxPath)
            {
                char* l_muxPath = i_args.i2cMuxPath->toString();
                TRACUCOMP(g_trac_i2c, "i2cPageSwitchOp(): muxSelector=0x%X, muxPath=%s",
                          i_args.i2cMuxBusSelector, l_muxPath);
                free(l_muxPath);
                l_muxPath = nullptr;
            }
            else
            {
                TRACUCOMP(g_trac_i2c, "i2cPageSwitchOp(): muxSelector=0x%X, muxPath=NULL",
                          i_args.i2cMuxBusSelector);
            }

            // Retry MAX_NACK_RETRIES so we can bypass nacks caused by a busy bus.
            // Other Nack errors are expected and caused by the empty write
            // associated with the page switch operation.
            for(uint8_t retry = 0;
                retry <= MAX_NACK_RETRIES;
                retry++)
            {
                l_err = i2cWrite(i_target,
                                 l_zeroBuffer,
                                 l_zeroBuflen,
                                 i_args);

                if(l_err == nullptr)
                {
                    // Operation completed successfully
                    // set attribute and break from retry loop
                    TRACUCOMP(g_trac_i2c,"Set EEPROM_PAGE to %d", i_desiredPage);
                    page_array[i_args.engine][i_args.port] = l_newPage;
                    i_target->setAttr<TARGETING::ATTR_EEPROM_PAGE_ARRAY>(page_array);
                    break;
                }
                else if( l_err->reasonCode() != I2C_NACK_ONLY_FOUND)
                {
                    // Only retry on NACK failures. Break from retry loop
                    TRACFCOMP(g_trac_i2c,
                            ERR_MRK"i2cPageSwitchOp(): I2C Write "
                            "Non-NACK fail %x", i_args.devAddr );
                    l_err->collectTrace(I2C_COMP_NAME);
                    l_mutex_needs_unlock = true;
                    l_error = true;
                    break;
                }
                else // Handle NACK error
                {
                    TRACFCOMP(g_trac_i2c,
                       "i2cPageSwitchOp::Expected Nack error. Retrying in case "
                       "this nack was caused by bus being busy "
                       "loop = %d", retry);

                    nanosleep( 0, i_args.polling_interval_ns );

                    // Retry on NACKs just in case the cause was a busy i2c bus.
                    if( retry < MAX_NACK_RETRIES )
                    {
                        if(l_err_NACK == nullptr)
                        {
                            l_err_NACK = l_err;
                            TRACUCOMP(g_trac_i2c,
                                    "Saving first Nack error and retry");
                            nanosleep(0, i_args.polling_interval_ns);
                            l_err_NACK->collectTrace(I2C_COMP_NAME);

                        }
                        else
                        {
                            // Delete this new NACK error
                            delete l_err;
                            nanosleep(0 ,i_args.polling_interval_ns);
                            l_err = nullptr;
                        }
                        // continue to retry
                        continue;
                    }
                    else // no more retries: trace and break;
                    {
                        TRACFCOMP(g_trac_i2c,
                                "Exiting Nack retry loop");
                        break;
                    }
                }

            } // end of retry loop

            if(l_err_NACK)
            {
                if( l_err )
                {
                    i2cHandleError( i_target,
                                    l_err,
                                    i_args );
                    delete l_err;
                    l_err = nullptr;

                }
                delete l_err_NACK;
                l_err_NACK = nullptr;
            }
            //free zero buffer
            free(l_zeroBuffer);
        }
        else
        {
            TRACUCOMP(g_trac_i2c,
                    "On correct page(%d). No page switch needed",
                    l_currentPage);
        }

        if( l_error )
        {
           //call i2cHandleError
           i2cHandleError( i_target,
                           l_err,
                           i_args );
           break;
        }
    }while( 0 );
    if( l_mutex_needs_unlock )
    {
        TRACFCOMP(g_trac_i2c,
                "Prematurely unlocking page mutex");
        (void)mutex_unlock(l_pageLock);
    }

    TRACUCOMP(g_trac_i2c, EXIT_MRK"i2cPageSwitchOp()");

    return l_err;
}



// ------------------------------------------------------------------
// i2cPageUnlockOp
// ------------------------------------------------------------------
bool i2cPageUnlockOp( TARGETING::Target * i_target,
                            misc_args_t & i_args )
{
    TRACUCOMP(g_trac_i2c, ENTER_MRK"i2cPageUnlockOp()");
    bool l_mutexSuccess = false;
    mutex_t * l_pageLock = nullptr;
    errlHndl_t l_err = nullptr;

    do
    {
        // Get the mutex for this target
        l_mutexSuccess = i2cGetPageMutex( i_target,
                                          i_args,
                                          l_pageLock );

        if( !l_mutexSuccess )
        {
            TRACUCOMP( g_trac_i2c,
                   ERR_MRK"Error in i2cPageUnlockOp::i2cGetPageMutex()");
            /*@
             * @errortype
             * @reasoncode     I2C_INVALID_EEPROM_PAGE_MUTEX
             * @severity       ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid       I2C_PAGE_UNLOCK_OP
             * @userdata1      Target Huid
             * @userdata2      <UNUSED>
             * @devdesc        There was an error retrieving the EEPROM page
             *                 mutex for this i2c master engine
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             I2C_PERFORM_OP,
                                             I2C_INVALID_EEPROM_PAGE_MUTEX,
                                             TARGETING::get_huid(i_target),
                                             0x0,
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            l_err->collectTrace( I2C_COMP_NAME, 256 );
            errlCommit(l_err, I2C_COMP_ID);
            break;
        }
        //Unlock the page mutex
        (void)mutex_unlock(l_pageLock);
    }while( 0 );

    TRACUCOMP(g_trac_i2c, EXIT_MRK"i2cPageUnlockOp()");
    return l_mutexSuccess;
}


// ------------------------------------------------------------------
// i2cSetSwitches
// ------------------------------------------------------------------
void i2cSetSwitches( TARGETING::Target * i_target,
                     misc_args_t & io_args )
{
    // Set Host vs FSI switches if both values are zero;
    // Otherwise, caller should have already set them
    if ( ( io_args.switches.useHostI2C == 0 ) &&
         ( io_args.switches.useFsiI2C == 0 ) )
    {
        if ( !( i_target->tryGetAttr<TARGETING::ATTR_I2C_SWITCHES>
                                    (io_args.switches) ) )
        {
            // Default to Host
            io_args.switches.useHostI2C = 1;
            io_args.switches.useFsiI2C  = 0;
        }
    }
    return;
}


// ------------------------------------------------------------------
// i2cGetI2cMuxTarget
// ------------------------------------------------------------------
errlHndl_t i2cGetI2cMuxTarget ( const TARGETING::EntityPath & i_i2cMuxPath,
                                TARGETING::Target * &o_target,
                                bool i_noError )
{
    errlHndl_t l_err(nullptr);

    // Initially set outgoing target to NULL
    o_target = nullptr;

    //Get the string to MUX path and hold for future use, if needed, free at end
    char* l_muxPath = i_i2cMuxPath.toString();
    TRACUCOMP( g_trac_i2c, ENTER_MRK"i2cGetI2cMuxTarget() muxPath(%s)",
               l_muxPath);

    do
    {
        TARGETING::TargetService& l_targetService = TARGETING::targetService();

        // Retrieve the I2C MUX target from path
        o_target = l_targetService.toTarget(i_i2cMuxPath);

        if ( nullptr == o_target )
        {
            if (!i_noError)
            {
                TRACFCOMP( g_trac_i2c,
                    ERR_MRK "i2cGetI2cMuxTarget() - I2C MUX Entity Path (%s)"
                            " could not be converted to a target.",
                            l_muxPath );


                /*@
                 * @errortype
                 * @reasoncode  I2C_MUX_TARGET_NOT_FOUND
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    I2C_ACCESS_MUX
                 * @devdesc     I2C mux path target is null
                 * @custdesc    Unexpected boot firmware error
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    I2C_ACCESS_MUX,
                                    I2C_MUX_TARGET_NOT_FOUND,
                                    0,
                                    0,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

                // Collect the MUX entity path info
                ERRORLOG::ErrlUserDetailsString(l_muxPath).addToLog(l_err);

                l_err->collectTrace( I2C_COMP_NAME, 256);

                break;
            }
        }

        // Is the target functional
        TARGETING::HwasState l_hwasState =
                                o_target->getAttr<TARGETING::ATTR_HWAS_STATE>();
        if ( !l_hwasState.poweredOn  ||
             !l_hwasState.present    ||
             !l_hwasState.functional )
        {
            if (!i_noError)
            {
                TRACFCOMP( g_trac_i2c,
                        ERR_MRK "i2cGetI2cMuxTarget() - I2C MUX target (0x%X) "
                                "is non functional.",
                                TARGETING::get_huid(o_target) );
                /*@
                 * @errortype
                 * @reasoncode     I2C_MUX_TARGET_NON_FUNCTIONAL
                 * @severity       ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid       I2C_ACCESS_MUX
                 * @userdata1      I2C MUX Target Huid
                 * @devdesc        I2C mux path target is not functional
                 * @custdesc       Unexpected boot firmware error
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    I2C_ACCESS_MUX,
                                    I2C_MUX_TARGET_NON_FUNCTIONAL,
                                    TARGETING::get_huid(o_target),
                                    0,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

                // Collect the MUX entity path info
                ERRORLOG::ErrlUserDetailsString(l_muxPath).addToLog(l_err);

                l_err->collectTrace( I2C_COMP_NAME, 256);
            }

            // Don't return a non functional target
            o_target = nullptr;

            break;
        }
    } while( 0 );


    TRACUCOMP( g_trac_i2c, EXIT_MRK"i2cGetI2cMuxTarget() - %s%X",
               ((nullptr == l_err) ? "No Error, target=0x" :
                                     "With Error, target=0x"),
               ((nullptr == o_target) ? 0x0 : TARGETING::get_huid(o_target) ) );

    // Free the string to MUX path
    free(l_muxPath);
    l_muxPath = nullptr;

    return l_err;
} // end i2cGetI2cMuxTarget


// ------------------------------------------------------------------
// i2cAccessMux
// ------------------------------------------------------------------
errlHndl_t i2cAccessMux( TARGETING::Target*           i_masterTarget,
                         uint8_t                      i_i2cMuxBusSelector,
                         const TARGETING::EntityPath &i_i2cMuxPath)
{
    char* l_muxPath = i_i2cMuxPath.toString();
    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cAccessMux(): masterTarget=0x%X, "
               "muxSelector=0x%X, muxPath=%s",
               TARGETING::get_huid(i_masterTarget),
               i_i2cMuxBusSelector,
               l_muxPath );

    free(l_muxPath);
    l_muxPath = nullptr;

    errlHndl_t l_err{nullptr};

    do
    {
        TARGETING::TargetHandle_t l_i2cMuxTarget(nullptr);

        l_err = i2cGetI2cMuxTarget( i_i2cMuxPath,
                                    l_i2cMuxTarget, false);

        // If an issue getting the MUX target, then return error
        if (l_err)
        {
            break;
        }

        TARGETING::FapiI2cControlInfo l_muxData;

        if (! (l_i2cMuxTarget->tryGetAttr<TARGETING::ATTR_FAPI_I2C_CONTROL_INFO>(l_muxData)) )
        {
            TRACFCOMP(g_trac_i2c,
            "i2cAccessMux(): getting ATTR_FAPI_I2C_CONTROL_INFO failed");
            break;
        }

        TARGETING::ATTR_MODEL_type l_muxModel;
        if (! (l_i2cMuxTarget->tryGetAttr<TARGETING::ATTR_MODEL>(l_muxModel)) )
        {
            TRACFCOMP(g_trac_i2c,
            "i2cAccessMux(): getting ATTR_MODEL failed");
            break;
        }

        assert(l_muxModel == TARGETING::MODEL_PCA9847, "Invalid model of mux detected");
        const uint8_t PCA9847_ENABLE_BIT = 8;

        uint8_t l_muxSelector = i_i2cMuxBusSelector | PCA9847_ENABLE_BIT;
        uint8_t *l_ptrMuxSelector = &l_muxSelector;
        size_t l_muxSelectorSize = sizeof(l_muxSelector);

        l_err = DeviceFW::deviceOp(
                     DeviceFW::WRITE,
                     i_masterTarget,
                     l_ptrMuxSelector,
                     l_muxSelectorSize,
                     DEVICE_I2C_ADDRESS(l_muxData.port,
                                        l_muxData.engine,
                                        l_muxData.devAddr,
                                        I2C_MUX::NOT_APPLICABLE,
                                        (&i_i2cMuxPath) ) );
    } while (0);

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cAccessMux() - %s",
               ((nullptr == l_err) ? "No Error" : "With Error") );

    return l_err;
}  // end i2cAccessMux

// ------------------------------------------------------------------
// i2cCommonOp
// ------------------------------------------------------------------
errlHndl_t i2cCommonOp( DeviceFW::OperationType i_opType,
                        TARGETING::Target * i_target,
                        void * io_buffer,
                        size_t & io_buflen,
                        int64_t i_accessType,
                        misc_args_t & i_args )
{
    errlHndl_t err = nullptr;
    bool mutex_success = false;

    mutex_t * engineLock = nullptr;
    bool mutex_needs_unlock = false;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cCommonOp(): i_opType=%d, aType=%d, "
               "e/p/devAddr= %d/%d/0x%x, len=%d, offset=0x%x/%p",
               static_cast<uint64_t>(i_opType), i_accessType, i_args.engine, i_args.port,
               i_args.devAddr, io_buflen, i_args.offset_length,
               i_args.offset_buffer);

    // Printing mux info separately, if combined, nothing is displayed
    if (i_args.i2cMuxPath)
    {
        char* l_muxPath = i_args.i2cMuxPath->toString();
        TRACUCOMP(g_trac_i2c, "i2cCommonOp(): muxSelector=0x%X, muxPath=%s",
                  i_args.i2cMuxBusSelector, l_muxPath);
        free(l_muxPath);
        l_muxPath = nullptr;
    }
    else
    {
        TRACUCOMP(g_trac_i2c, "i2cCommonOp(): muxSelector=0x%X, muxPath=NULL",
                  i_args.i2cMuxBusSelector);
    }

    do
    {
        // Check for Master Sentinel chip
        if( TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cCommonOp() - Cannot target Master Sentinel "
                       "Chip for an I2C Operation!" );

            /*@
             * @errortype
             * @reasoncode     I2C_MASTER_SENTINEL_TARGET
             * @severity       ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid       I2C_PERFORM_OP
             * @userdata1      Operation Type requested
             * @userdata2      <UNUSED>
             * @devdesc        Master Sentinel chip was used as a target for an
             *                 I2C operation.  This is not permitted.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_PERFORM_OP,
                                           I2C_MASTER_SENTINEL_TARGET,
                                           i_opType,
                                           0x0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( I2C_COMP_NAME, 256);

            break;
        }

        //Set Host vs Fsi switches if not done already
        i2cSetSwitches(i_target, i_args);

        // Get the mutex for the requested engine
        mutex_success = i2cGetEngineMutex( i_target,
                                           i_args,
                                           engineLock );

        if( !mutex_success )
        {
            TRACUCOMP( g_trac_i2c,
                       ERR_MRK"Error in i2cCommonOp::i2cGetEngineMutex()");
            break;
        }

        // Lock on this engine
        recursive_mutex_lock( engineLock );
        mutex_needs_unlock = true;

        if ( (I2C_MUX::NOT_APPLICABLE != i_args.i2cMuxBusSelector) &&
             (nullptr != i_args.i2cMuxPath) )
        {
            err = i2cAccessMux( i_target,
                                i_args.i2cMuxBusSelector,
                                *(i_args.i2cMuxPath));
        }

        if ( err )
        {

            TRACFCOMP(g_trac_i2c,
                      ERR_MRK"i2cCommonOp() - There is an issue accessing "
                       "the I2C MUX");

            // Skip performing the actual I2C Operation
            break;
        }

        // Calculate variables related to I2C Bus Speed in 'args' struct
        err =  i2cSetBusVariables( i_target, I2C_BUS_SPEED_FROM_MRW, i_args);

        if( err )
        {
            // Skip performing the actual I2C Operation
            break;
        }

        /*******************************************************/
        /*  Perform the I2C Operation                          */
        /*******************************************************/

        /***********************************************/
        /* I2C SMBUS Send Byte                         */
        /***********************************************/
        if(   (i_opType  == DeviceFW::WRITE )
           && (i_args.subop == DeviceFW::I2C_SMBUS_SEND_OR_RECV))
        {
            TRACUCOMP(g_trac_i2c, INFO_MRK
                      "I2C SMBUS Send Byte, "
                      "Use PEC = %d.",
                      i_args.smbus.usePec);

            // If requested length is anything other than 1 byte, throw an
            // error.
            if(io_buflen != sizeof(uint8_t))
            {
                /*@
                 * @errortype
                 * @reasoncode I2C_INVALID_SEND_BYTE_LENGTH
                 * @severity   ERRL_SEV_UNRECOVERABLE
                 * @moduleid   I2C_PERFORM_OP
                 * @userdata1  Size of request
                 * @devdesc    Invalid input buffer length for send byte request
                 * @custdesc   Unexpected firmware error
                 */
                err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    I2C_PERFORM_OP,
                    I2C_INVALID_SEND_BYTE_LENGTH,
                    io_buflen,
                    0,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                err->collectTrace(I2C_COMP_NAME);

                io_buflen = 0;

                break;
            }

            // Write SMBUS Send Byte command to device.
            i_args.read_not_write  = false;
            i_args.with_stop       = true;
            i_args.skip_mode_setup = false;
            i_args.with_address    = true;
            i_args.with_start      = true;

            I2C::SMBUS::SendByte sendByte(i_args.devAddr,
                                          io_buffer,
                                          i_args.smbus.usePec);
            do {

            size_t writeSize = sendByte.messageSize;
            const auto writeSizeExp = writeSize;
            err = i2cWrite(i_target,
                           &sendByte.dataByte,
                           writeSize,
                           i_args);
            if(err)
            {
                break;
            }

            assert(writeSize == writeSizeExp,
                   "Write size mismatch; expected %d but got %d",
                   writeSizeExp,writeSize);

            io_buflen = sizeof(sendByte.dataByte);

            } while(0);

            if(err)
            {
                io_buflen = 0;
            }
        }
        /***********************************************/
        /* I2C SMBUS Write Byte / Write Word           */
        /***********************************************/
        else if(   (i_opType  == DeviceFW::WRITE )
                && (   (i_args.subop == DeviceFW::I2C_SMBUS_BYTE)
                    || (i_args.subop == DeviceFW::I2C_SMBUS_WORD)))
        {
            // Note: The SMBUS spec calls a 2 byte value a "word"
            TRACUCOMP(g_trac_i2c, INFO_MRK
                      "I2C SMBUS Write %s: Command code = 0x%02X, "
                      "Use PEC = %d.",
                      i_args.subop == DeviceFW::I2C_SMBUS_BYTE ?
                          "Byte" : "Word",
                      i_args.smbus.commandCode,
                      i_args.smbus.usePec);

            // If requested length is != 1 byte for a write byte transaction,
            // or != 2 bytes for a write word transaction, throw an error.
            if(   (   (i_args.subop == DeviceFW::I2C_SMBUS_BYTE)
                   && (io_buflen != sizeof(uint8_t)))
               || (   (i_args.subop == DeviceFW::I2C_SMBUS_WORD)
                   && (io_buflen != sizeof(uint16_t))))
            {
                /*@
                 * @errortype
                 * @reasoncode I2C_INVALID_WRITE_BYTE_OR_WORD_LENGTH
                 * @severity   ERRL_SEV_UNRECOVERABLE
                 * @moduleid   I2C_PERFORM_OP
                 * @userdata1  Size of request
                 * @userdata2  Sub-op
                 * @devdesc    Invalid input buffer length for write byte or
                 *     write word request
                 * @custdesc   Unexpected firmware error
                 */
                err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    I2C_PERFORM_OP,
                    I2C_INVALID_WRITE_BYTE_OR_WORD_LENGTH,
                    io_buflen,
                    i_args.subop,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                err->collectTrace(I2C_COMP_NAME);

                io_buflen = 0;

                break;
            }

            // Write SMBUS Write Byte or Write Word command to device.
            i_args.read_not_write  = false;
            i_args.with_stop       = true;
            i_args.skip_mode_setup = false;
            i_args.with_address    = true;
            i_args.with_start      = true;

            uint8_t bytes = (i_args.subop == DeviceFW::I2C_SMBUS_BYTE) ?
                sizeof(uint8_t) : sizeof(uint16_t);
            I2C::SMBUS::WriteByteOrWord writeByteOrWord(i_args.devAddr,
                                              i_args.smbus.commandCode,
                                              bytes,
                                              io_buffer,
                                              i_args.smbus.usePec);
            do {

            size_t writeSize = writeByteOrWord.messageSize;
            const auto writeSizeExp = writeSize;
            err = i2cWrite(i_target,
                           &writeByteOrWord.commandCode,
                           writeSize,
                           i_args);
            if(err)
            {
                break;
            }

            assert(writeSize == writeSizeExp,
                   "Write size mismatch; expected %d but got %d",
                   writeSizeExp,writeSize);

            io_buflen = writeByteOrWord.byteCount;

            } while(0);

            if(err)
            {
                io_buflen = 0;
            }
        }
        /***********************************************/
        /* I2C SMBUS Block Write                       */
        /***********************************************/
        else if(   (i_opType  == DeviceFW::WRITE )
                && (i_args.subop == DeviceFW::I2C_SMBUS_BLOCK))
        {
            TRACUCOMP(g_trac_i2c, INFO_MRK
                      "I2C SMBUS Block Write: Command code = 0x%02X, "
                      "Use PEC = %d. io_buflen = %lu",
                      i_args.smbus.commandCode,
                      i_args.smbus.usePec, io_buflen);

            // If requested length is for < 1 byte or > 255 bytes for a block
            // write transaction, throw an error.
            if(   (!io_buflen)
               || (io_buflen > UINT8_MAX) )
            {
                /*@
                 * @errortype
                 * @reasoncode I2C_INVALID_BLOCK_WRITE_LENGTH
                 * @severity   ERRL_SEV_UNRECOVERABLE
                 * @moduleid   I2C_PERFORM_OP
                 * @userdata1  Size of request
                 * @devdesc    Invalid input buffer length for block write
                 *     request
                 * @custdesc   Unexpected firmware error
                 */
                err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    I2C_PERFORM_OP,
                    I2C_INVALID_BLOCK_WRITE_LENGTH,
                    io_buflen,
                    0,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

                err->collectTrace(I2C_COMP_NAME);

                io_buflen = 0;

                break;
            }

            // Write SMBUS block write command to device.
            i_args.read_not_write  = false;
            i_args.with_stop       = true;
            i_args.skip_mode_setup = false;
            i_args.with_address    = true;
            i_args.with_start      = true;

            I2C::SMBUS::BlockWrite blockWrite(i_args.devAddr,
                                              i_args.smbus.commandCode,
                                              io_buflen,
                                              io_buffer,
                                              i_args.smbus.usePec);
            do {

            size_t writeSize = blockWrite.messageSize;
            const auto writeSizeExp = writeSize;
            err = i2cWrite(i_target,
                           &blockWrite.commandCode,
                           writeSize,
                           i_args);
            if(err)
            {
                break;
            }

            assert(writeSize == writeSizeExp,
                   "Write size mismatch; expected %d but got %d",
                   writeSizeExp,writeSize);

            io_buflen = blockWrite.byteCount;

            } while(0);

            if(err)
            {
                io_buflen = 0;
            }
        }
        /***********************************************/
        /* I2C SMBUS Read Word or Byte                 */
        /***********************************************/
        else if(   (i_opType  == DeviceFW::READ )
                && (   (i_args.subop == DeviceFW::I2C_SMBUS_BYTE)
                    || (i_args.subop == DeviceFW::I2C_SMBUS_WORD)))
        {
            // Note: The SMBUS spec calls a 2 byte value a "word"
            TRACUCOMP(g_trac_i2c, INFO_MRK
                      "I2C SMBUS Read %s: Command code = 0x%02X, "
                      "Use PEC = %d",
                      i_args.subop == DeviceFW::I2C_SMBUS_BYTE ?
                          "Byte" : "Word",
                      i_args.smbus.commandCode,
                      i_args.smbus.usePec);

            // If requested length is != 1 byte for a read byte transaction,
            // or != 2 bytes for a read word transaction, throw an error.
            if(   (   (i_args.subop == DeviceFW::I2C_SMBUS_BYTE)
                   && (io_buflen != sizeof(uint8_t)))
               || (   (i_args.subop == DeviceFW::I2C_SMBUS_WORD)
                   && (io_buflen != sizeof(uint16_t))))
            {
                /*@
                 * @errortype
                 * @reasoncode I2C_INVALID_READ_BYTE_OR_WORD_LENGTH
                 * @severity   ERRL_SEV_UNRECOVERABLE
                 * @moduleid   I2C_PERFORM_OP
                 * @userdata1  Size of request
                 * @userdata2  Sub-op
                 * @devdesc    Invalid input buffer length for read byte or
                 *     read word request
                 * @custdesc   Unexpected firmware error
                 */
                err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    I2C_PERFORM_OP,
                    I2C_INVALID_READ_BYTE_OR_WORD_LENGTH,
                    io_buflen,
                    i_args.subop,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                err->collectTrace(I2C_COMP_NAME);

                io_buflen = 0;

                break;
            }

            // Write SMBUS Read Byte|Word command to device.  Inhibit stop
            // because the protocol requires a chained read operation without
            // a stop in between.
            i_args.read_not_write  = false;
            i_args.with_stop       = false;
            i_args.skip_mode_setup = false;
            i_args.with_address    = true;
            i_args.with_start      = true;

            uint8_t bytes = (   i_args.subop
                             == DeviceFW::I2C_SMBUS_BYTE) ?
                sizeof(uint8_t) : sizeof(uint16_t);

            I2C::SMBUS::ReadByteOrWord readByteOrWord(i_args.devAddr,
                                                      i_args.smbus.commandCode,
                                                      bytes);
            do {

            size_t commandCodeSize = sizeof(readByteOrWord.commandCode);
            const auto commandCodeSizeExp = commandCodeSize;
            err = i2cWrite(i_target,
                           &readByteOrWord.commandCode,
                           commandCodeSize,
                           i_args);
            if(err)
            {
                break;
            }

            assert(commandCodeSize == commandCodeSizeExp,
                   "Command code write size mismatch; expected %d but got %d",
                   commandCodeSizeExp,commandCodeSize);

            // Now read the required number of data bytes (1 or 2).
            // If there is no PEC byte, complete the transaction with a stop
            // and inform the engine there is no subsequent read.  If the PEC
            // byte is supported, withhold the stop and inform the engine there
            // is an additional read transaction coming.  Since this is a
            // continuation of the original operation but as a read, repeat the
            // start bit and address.
            i_args.read_not_write  = true;
            i_args.skip_mode_setup = true;
            i_args.with_stop      = i_args.smbus.usePec ? false : true;
            i_args.read_continue  = i_args.smbus.usePec ? true : false;

            size_t dataBytesSize = readByteOrWord.byteCount;
            const auto dataBytesSizeExp = dataBytesSize;
            err = i2cRead(i_target,
                          readByteOrWord.dataBytes,
                          dataBytesSize,
                          i_args);
            if(err)
            {
                break;
            }

            assert(dataBytesSize == dataBytesSizeExp,
                   "Data bytes read size mismatch; expected %d but got %d",
                   dataBytesSizeExp,dataBytesSize);

            if(i_args.smbus.usePec)
            {
                // Read the PEC byte with stop at the end and inform engine
                // the chained reads are complete
                i_args.with_stop = true;
                i_args.read_continue = false;
                i_args.with_address  = false;
                i_args.with_start    = false;

                size_t pecSize=sizeof(readByteOrWord.pec);
                const auto pecSizeExp=pecSize;
                err = i2cRead(i_target,
                              &readByteOrWord.pec,
                              pecSize,
                              i_args);
                if(err)
                {
                    break;
                }

                assert(pecSize == pecSizeExp,
                       "PEC byte read size mismatch; expected %d but got %d",
                       pecSizeExp,pecSize);

                const size_t pecBytes =
                      offsetof(I2C::SMBUS::ReadByteOrWord,dataBytes)
                    + readByteOrWord.byteCount;
                const auto expectedPec = I2C::SMBUS::calculatePec(
                    reinterpret_cast<uint8_t*>(&readByteOrWord),pecBytes);
                if(readByteOrWord.pec != expectedPec)
                {
                    TRACFCOMP(g_trac_i2c, ERR_MRK
                              "Bad PEC byte detected; expected 0x%02X "
                              "but received 0x%02X.  # PEC bytes = %d",
                              expectedPec,readByteOrWord.pec,pecBytes);

                    err = badPecByteError(expectedPec,
                                          readByteOrWord.pec,
                                          i_target,
                                          i_args);

                    break;
                }
            }

            // Copy the amount of data returned by the remote device, or
            // the user requested amount, whichever is smaller
            io_buflen = readByteOrWord.byteCount;
            memcpy(io_buffer,readByteOrWord.dataBytes,io_buflen);

            } while(0);

            if(err)
            {
                io_buflen = 0;
            }
        }
        /***********************************************/
        /* I2C SMBUS Block Read                        */
        /***********************************************/
        else if(   (i_opType  == DeviceFW::READ )
                && (i_args.subop == DeviceFW::I2C_SMBUS_BLOCK))
        {
            TRACUCOMP(g_trac_i2c, INFO_MRK
                      "I2C SMBUS Block Read: Command code = 0x%02X, "
                      "Use PEC = %d.",
                      i_args.smbus.commandCode,
                      i_args.smbus.usePec);

            // If requested length is < 1 byte or > 255 bytes for a block
            // read transaction, throw an error.
            if(   (!io_buflen)
               || (io_buflen > UINT8_MAX) )
            {
                /*@
                 * @errortype
                 * @reasoncode I2C_INVALID_BLOCK_READ_LENGTH
                 * @severity   ERRL_SEV_UNRECOVERABLE
                 * @moduleid   I2C_PERFORM_OP
                 * @userdata1  Size of request
                 * @devdesc    Invalid input buffer length for block read
                 *     request
                 * @custdesc   Unexpected firmware error
                 */
                err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    I2C_PERFORM_OP,
                    I2C_INVALID_BLOCK_READ_LENGTH,
                    io_buflen,
                    0,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

                err->collectTrace(I2C_COMP_NAME);

                io_buflen = 0;

                break;
            }

            // Write SMBUS block read command to device.  Inhibit stop
            // because the protocol requires a chained read operation without
            // a stop in between.
            i_args.read_not_write  = false;
            i_args.with_stop       = false;
            i_args.skip_mode_setup = false;
            i_args.with_address    = true;
            i_args.with_start      = true;

            I2C::SMBUS::BlockRead blockRead(i_args.devAddr,
                                            i_args.smbus.commandCode);

            do {

            size_t commandCodeSize = sizeof(i_args.smbus.commandCode);
            const auto commandCodeSizeExp = commandCodeSize;
            err = i2cWrite(i_target,
                           &i_args.smbus.commandCode,
                           commandCodeSize,
                           i_args);
            if(err)
            {
                break;
            }

            assert(commandCodeSize == commandCodeSizeExp,
                   "Command code write size mismatch; expected %d but got %d",
                   commandCodeSizeExp,commandCodeSize);

            // Read the block count byte, which indicates how many
            // bytes (up to 255) the remote device will return as part of the
            // logical response.  Does -not- include PEC byte.
            // Since it's a continuation of an existing command, send a repeated
            // start and address, but again do not send the stop because
            // the read must continue later.  Also set read-continue in the
            // engine so that we can break the full set of reads into multiple
            // transactions and don't setup the engine again.
            i_args.read_not_write  = true;
            i_args.read_continue = true;
            i_args.skip_mode_setup = true;

            size_t blockCountSize = sizeof(blockRead.blockCount);
            const auto blockCountSizeExp = blockCountSize;
            err = i2cRead(i_target,
                          &blockRead.blockCount,
                          blockCountSize,
                          i_args);
            if(err)
            {
                break;
            }

            assert(blockCountSize == blockCountSizeExp,
                   "Block count read size mismatch; expected %d but got %d",
                   blockCountSizeExp,blockCountSize);

            // From this point onwards, we don't want a start bit or address to
            // be sent
            i_args.with_start     = false;
            i_args.with_address   = false;

            // Now read the specified number of data bytes.
            // If there is no PEC byte, complete the transaction with a stop
            // and inform the engine there is no subsequent read.  If the PEC
            // byte is supported, withhold the stop to inform the engine there
            // is an additional read transaction coming.  Since this is a
            // continuation of the read, withhold the start bit and the address.
            // If the data count was zero, we -have- to
            // skip the read unless there is no PEC byte (and thus a stop),
            // because a transaction without a stop/start/address of 0 length
            // will otherwise trigger a command invalid condition from the I2C
            // engine.
            if(blockRead.blockCount || !i_args.smbus.usePec)
            {
                i_args.with_stop      = i_args.smbus.usePec ? false : true;
                i_args.read_continue  = i_args.smbus.usePec ? true : false;

                size_t dataBytesSize = blockRead.blockCount;
                const auto dataBytesSizeExp = dataBytesSize;
                err = i2cRead(i_target,
                              blockRead.dataBytes,
                              dataBytesSize,
                              i_args);
                if(err)
                {
                    break;
                }

                assert(dataBytesSize == dataBytesSizeExp,
                       "Data bytes read size mismatch; expected %d but got %d",
                       dataBytesSizeExp,dataBytesSize);
            }

            if(i_args.smbus.usePec)
            {
                // Read the PEC byte with stop at the end and inform engine
                // the chained reads are complete
                i_args.with_stop = true;
                i_args.read_continue = false;

                size_t pecSize=sizeof(blockRead.pec);
                const auto pecSizeExp=pecSize;
                err = i2cRead(i_target,
                              &blockRead.pec,
                              pecSize,
                              i_args);
                if(err)
                {
                    break;
                }

                assert(pecSize == pecSizeExp,
                       "PEC byte read size mismatch; expected %d but got %d",
                       pecSizeExp,pecSize);

                const size_t pecBytes =
                      offsetof(I2C::SMBUS::BlockRead,dataBytes)
                    + blockRead.blockCount;
                const auto expectedPec = I2C::SMBUS::calculatePec(
                    reinterpret_cast<uint8_t*>(&blockRead),pecBytes);

                if(blockRead.pec != expectedPec)
                {
                    TRACFCOMP(g_trac_i2c, ERR_MRK
                              "Bad PEC byte detected; expected 0x%02X "
                              "but received 0x%02X.  # PEC bytes = %d",
                              expectedPec,blockRead.pec,pecBytes);

                    err = badPecByteError(expectedPec,
                                          blockRead.pec,
                                          i_target,
                                          i_args);

                    break;
                }
            }

            // Copy the amount of data returned by the remote device, or
            // the user requested amount, whichever is smaller
            io_buflen = std::min(io_buflen,
                                 static_cast<size_t>(blockRead.blockCount));
            memcpy(io_buffer,blockRead.dataBytes,io_buflen);

            } while(0);

            if(err)
            {
                io_buflen = 0;
            }
        }
        /***********************************************/
        /* I2C Read with Offset                        */
        /***********************************************/
        else if( i_opType        == DeviceFW::READ &&
            i_args.offset_length != 0 )
        {
            // First WRITE offset to device without a stop
            i_args.read_not_write  = false;
            i_args.with_stop       = false;
            i_args.skip_mode_setup = false;

            err = i2cWrite( i_target,
                            i_args.offset_buffer,
                            i_args.offset_length,
                            i_args );

            if( err == nullptr )
            {
                // Now do the READ with a stop
                i_args.read_not_write = true;
                i_args.with_stop      = true;

                // Skip mode setup on this cmd -
                // already set with previous cmd
                i_args.skip_mode_setup = true;

                err = i2cRead( i_target,
                               io_buffer,
                               io_buflen,
                               i_args );
            }
        }

        /***********************************************/
        /* I2C Write with Offset                       */
        /***********************************************/
        else if( i_opType        == DeviceFW::WRITE &&
                 i_args.offset_length != 0 )
        {
            // Add the Offset Information to the start of the data and
            // then send as a single write operation

            size_t newBufLen = i_args.offset_length + io_buflen;
            uint8_t * newBuffer = static_cast<uint8_t*>(malloc(newBufLen));

            // Add the Offset to the buffer
            memcpy( newBuffer, i_args.offset_buffer, i_args.offset_length);

            // Now add the data the user wanted to write
            memcpy( &newBuffer[i_args.offset_length], io_buffer, io_buflen);

            // Write parms:
            i_args.read_not_write  = false;
            i_args.with_stop       = true;
            i_args.skip_mode_setup = false;

            err = i2cWrite( i_target,
                            newBuffer,
                            newBufLen,
                            i_args );

            free( newBuffer );
        }

        /***********************************************/
        /* I2C Read (no offset)                        */
        /***********************************************/
        else if ( i_opType        == DeviceFW::READ &&
                  i_args.offset_length == 0 )
        {
            // Do a direct READ
            i_args.read_not_write  = true;
            i_args.with_stop       = true;
            i_args.skip_mode_setup = false;

            err = i2cRead( i_target,
                           io_buffer,
                           io_buflen,
                           i_args);
        }


        /***********************************************/
        /* I2C Write (no offset)                       */
        /***********************************************/
        else if( i_opType        == DeviceFW::WRITE &&
                 i_args.offset_length == 0 )
        {
            // Do a direct WRITE with a stop
            i_args.read_not_write  = false;
            i_args.with_stop       = true;
            i_args.skip_mode_setup = false;

            err = i2cWrite( i_target,
                            io_buffer,
                            io_buflen,
                            i_args);
        }

        /********************************************************/
        /* Error - Unsupported I2C Op/Offset Type Combination   */
        /********************************************************/
        else
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cCommonOp() - "
                       "Unsupported Op/Offset-Type Combination=%d/%d",
                       i_opType, i_args.offset_length );
            uint64_t userdata2 = i_args.offset_length;
            userdata2 = (userdata2 << 16) | i_args.port;
            userdata2 = (userdata2 << 16) | i_args.engine;
            userdata2 = (userdata2 << 16) | i_args.devAddr;

            /*@
             * @errortype
             * @reasoncode       I2C_INVALID_OP_TYPE
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         I2C_PERFORM_OP
             * @userdata1        i_opType
             * @userdata2[0:15]  Offset Length
             * @userdata2[16:31] Master Port
             * @userdata2[32:47] Master Engine
             * @userdata2[48:63] Slave Device Address
             * @devdesc          Invalid operation type.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_PERFORM_OP,
                                           I2C_INVALID_OP_TYPE,
                                           i_opType,
                                           userdata2,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( I2C_COMP_NAME, 256);

            // No Operation performed, so can break and skip the section
            // that handles operation errors
            break;
        }

        // Handle Error from I2C Operation
        if( err )
        {
            i2cHandleError( i_target,
                            err,
                            i_args );
            break;
        }
    } while( 0 );

    // Check if we need to unlock the mutex
    if ( mutex_needs_unlock == true )
    {
        // Unlock
        recursive_mutex_unlock( engineLock );
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Unlocked engine: %d",
                   i_args.engine );
    }

    // If there is an error, add FFDC
    if ( err != nullptr )
    {
        // Add parameter info to log
        // @todo RTC 114298- update this for new parms/switches
        I2C::UdI2CParms( i_opType,
                         i_target,
                         io_buflen,
                         i_accessType,
                         i_args  )
                       .addToLog(err);

        // Add secureboot info to log
        SECUREBOOT::addSecureUserDetailsToErrlog(err);

    }

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cCommonOp() - %s",
               ((nullptr == err) ? "No Error" : "With Error") );

    return err;
} // end i2cCommonOp


// ------------------------------------------------------------------
// i2cPresence
// ------------------------------------------------------------------
bool i2cPresence( TARGETING::Target * i_target,
                  uint64_t            i_port,
                  uint64_t            i_engine,
                  uint64_t            i_devAddr,
                  uint8_t             i_i2cMuxBusSelector,
                  const TARGETING::EntityPath& i_i2cMuxPath )
{
    TRACUCOMP(g_trac_i2c, ENTER_MRK"i2cPresence(): tgt=0x%X: e%d/p%d/"
              "devAddr=0x%X", TARGETING::get_huid(i_target), i_engine,
              i_port, i_devAddr );

    errlHndl_t err = nullptr;
    bool l_mutex_success = false;
    bool l_present = false;
    size_t buflen = 1;
    uint64_t reset_error = 0;
    misc_args_t args;

    args.port = i_port;
    args.engine = i_engine;
    args.devAddr = i_devAddr;
    args.read_not_write = true;
    args.with_stop = true;
    args.skip_mode_setup = false;

    //Registers
    status_reg_t status;
    fifo_reg_t fifo;

    // Synchronization
    mutex_t * engineLock = nullptr;
    bool mutex_needs_unlock = false;

    // Use Local Variables (timeoutCount gets decremented);
    uint64_t l_interval_ns;
    uint64_t l_timeoutCount;

    do
    {
        // Get the mutex for the requested engine
        l_mutex_success = i2cGetEngineMutex( i_target,
                                             args,
                                             engineLock );

        if( !l_mutex_success )
        {
            TRACUCOMP( g_trac_i2c,
                       ERR_MRK"Error in i2cPresence::i2cGetEngineMutex()");
            break;
        }

        // Lock on this engine
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Obtaining lock for engine: %d",
                   args.engine );

        recursive_mutex_lock( engineLock );
        mutex_needs_unlock = true;

        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Locked on engine: %d",
                   args.engine );

        // Set the MUX selector (if there is one) for the MUX before continuing
        if (I2C_MUX::NOT_APPLICABLE != i_i2cMuxBusSelector)
        {
            // Check that Mux exists first
            TARGETING::TargetHandle_t l_i2cMuxTarget(nullptr);

            bool noError = true;  // just return nullptr target if mux doesn't exist
            err = i2cGetI2cMuxTarget( i_i2cMuxPath,
                                      l_i2cMuxTarget,
                                      noError );
            if (err || (l_i2cMuxTarget == nullptr))
            {
                // exit early if mux does not exist
                TRACFCOMP(g_trac_i2c,
                    ERR_MRK"i2cPresence() - XML appears to be wrong since "
                    "i2cMuxSelector 0x%02X != NOT_APPLICABLE for non-existent "
                    "I2C MUX target", i_i2cMuxBusSelector);
                break;
            }
            err = i2cAccessMux(i_target, i_i2cMuxBusSelector, i_i2cMuxPath );

            if ( err )
            {
                TRACFCOMP(g_trac_i2c,
                          ERR_MRK"i2cPresence() - There is an issue accessing "
                          "the I2C MUX");

                // Skip performing the presence detect operation
                break;
            }
        }

        // Set I2C Mode (Host vs FSI) for the target
        args.switches.useHostI2C = 0;
        args.switches.useFsiI2C  = 0;
        i2cSetSwitches( i_target, args );

        err = i2cSetBusVariables(i_target,
                                 I2C_BUS_SPEED_400KHZ,
                                 args);

        if( err )
        {
            TRACUCOMP(g_trac_i2c,
                      ERR_MRK"error in i2cPresence::i2cSetBusVariables()");
            break;
        }

        err = i2cSetup( i_target,
                        buflen,
                        args );

        if( err )
        {
            TRACUCOMP(g_trac_i2c,
                      ERR_MRK"error in i2cPresence::i2cSetup()");
            break;
        }

        l_interval_ns = args.polling_interval_ns;
        l_timeoutCount = args.timeout_count;

        //Check the Command Complete bit
        do
        {
            nanosleep( 0, l_interval_ns );

            status.value = 0x0ull;
            err = i2cRegisterOp( DeviceFW::READ,
                                 i_target,
                                 &status.value,
                                 I2C_REG_STATUS,
                                 args );

            if( err )
            {
                TRACUCOMP(g_trac_i2c,
                          ERR_MRK"i2cPresence::error in i2cRegisterOp()");
                break;
            }

            if( 0 == l_timeoutCount-- )
            {
                TRACUCOMP(g_trac_i2c,
                          ERR_MRK"i2cPresence() - Timed out waiting for "
                                 "Command Complete!");
                break;
            }

        }while( 0 == status.command_complete &&
                0 == status.fifo_entry_count &&
                0 == status.nack_received &&
                0 == status.data_request ); /* Command has completed
                                                   or fifo has data    */

        if( err )
        {
            TRACUCOMP(g_trac_i2c,
                      ERR_MRK"Error when waiting for Command Complete");
            break;
        }

        if( status.nack_received == 0 )
        {
            //The chip was present.
            TRACUCOMP(g_trac_i2c,
                      ERR_MRK"chip found! i2cPresence returning true!");

            // No nack received so we check the FIFO register
            if( status.fifo_entry_count != 0 || status.data_request != 0 )
            {

                //Read data from FIFO register to complete operation.
                fifo.value = 0x0ull;
                err = i2cRegisterOp( DeviceFW::READ,
                                     i_target,
                                     &fifo.value,
                                     I2C_REG_FIFO,
                                     args );

                TRACUCOMP(g_trac_i2c,
                          "i2cPresence() - FIFO = 0x%016llx",
                          fifo.value);

                if( err )
                {
                    TRACUCOMP(g_trac_i2c,
                    ERR_MRK"Error in i2cPresence::i2cRegisterOp()"
                    " - FIFO register");
                    break;
                }

                // -check for command complete
                err = i2cWaitForCmdComp(i_target,
                                        args );
                if( err )
                {
                    TRACUCOMP(g_trac_i2c,
                           ERR_MRK"Error in i2cPresence::i2cWaitForCmdComp()");
                    break;
                }

            }

            l_present = true;
            break;
        }
        else
        {
            //The chip was not present.
            TRACUCOMP(g_trac_i2c,
                      ERR_MRK"The chip was not present!");

            // reset error register
            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &reset_error,
                                 I2C_REG_RESET_ERRORS,
                                 args );

            if( err )
            {
                TRACUCOMP(g_trac_i2c,
                          ERR_MRK"Error in i2cPresence::i2cRegisterOp()"
                          " - Error register");
            }
            break;
        }

    } while ( 0 );

    if( err )
    {
        TRACFCOMP( g_trac_i2c,
                   ERR_MRK"i2cPresence() Error! "
                   "tgt=0x%X: e%d/p%d/devAddr=0x%X",
                   TARGETING::get_huid(i_target), i_engine, i_port, i_devAddr);
        errlCommit(err,
                   I2C_COMP_ID);

    }

    // Check if we need to unlock the mutex
    if ( mutex_needs_unlock == true )
    {
        // Unlock
        recursive_mutex_unlock( engineLock );
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Unlocked engine: %d",
                   args.engine );
    }

    TRACUCOMP(g_trac_i2c, EXIT_MRK"i2cPresence(): tgt=0x%X: e%d/p%d/"
              "devAddr=0x%X: l_present=%d",
              TARGETING::get_huid(i_target), i_engine, i_port, i_devAddr,
              l_present );

    return l_present;

}


// ------------------------------------------------------------------
// i2cRead
// ------------------------------------------------------------------
errlHndl_t i2cRead ( TARGETING::Target * i_target,
                     void * o_buffer,
                     size_t & i_buflen,
                     misc_args_t & i_args)
{
    errlHndl_t err = nullptr;
    uint64_t bytesRead = 0x0;

    // Use Local Variables (timeoutCount gets derecmented)
    uint64_t interval_ns  = i_args.polling_interval_ns;
    uint64_t timeoutCount = i_args.timeout_count;

    // Define the regs we'll be using
    status_reg_t status;
    fifo_reg_t fifo;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cRead()" );

    TRACSCOMP( g_trac_i2cr,
               "I2C READ  START : engine %.2X : port %.2X : devAddr %.2X : "
               "len %d",
               i_args.engine, i_args.port, i_args.devAddr, i_buflen);

    // Printing mux info separately, if combined, nothing is displayed
    if (i_args.i2cMuxPath)
    {
        char* l_muxPath = i_args.i2cMuxPath->toString();
        TRACSCOMP(g_trac_i2c, "i2cRead(): muxSelector=0x%X, muxPath=%s",
                  i_args.i2cMuxBusSelector, l_muxPath);
        free(l_muxPath);
        l_muxPath = nullptr;
    }
    else
    {
        TRACSCOMP(g_trac_i2c, "i2cRead(): muxSelector=0x%X, muxPath=NULL",
                  i_args.i2cMuxBusSelector);
    }

    do
    {
        // Do Command/Mode reg setups.
        i_args.read_not_write = true;

        err = i2cSetup( i_target,
                        i_buflen,
                        i_args );

        if( err )
        {
            break;
        }

        for( bytesRead = 0; bytesRead < i_buflen; bytesRead++ )
        {
            TRACUCOMP( g_trac_i2c,
                       INFO_MRK"Reading byte (%d) out of (%d)",
                       (bytesRead+1), i_buflen );

            // Read the status reg to see if there is data in the FIFO
            status.value = 0x0ull;
            err = i2cReadStatusReg( i_target,
                                    i_args,
                                    status );

            if( err )
            {
                break;
            }

            // Wait for 1 of 2 indictators to read from FIFO:
            // 1) fifo_entry_count !=0
            // 2) Data Request bit is on
            while( (0 == status.fifo_entry_count) &&
                   (0 == status.data_request)        )
            {
                nanosleep( 0, interval_ns );

                status.value = 0x0ull;
                err = i2cReadStatusReg( i_target,
                                        i_args,
                                        status );

                if( err )
                {
                    break;
                }


                TRACUCOMP( g_trac_i2c, "i2cRead() Wait Loop: status=0x%016llx "
                           ".fifo_entry_count=%d, .data_request=%d",
                           status.value, status.fifo_entry_count,
                           status.data_request);


                if( 0 == timeoutCount-- )
                {
                    TRACFCOMP( g_trac_i2c,
                               ERR_MRK"i2cRead() - "
                               "Timed out waiting for data in FIFO! "
                               "status=0x%016llx "
                               ".fifo_entry_count=%d, .data_request=%d",
                               status.value, status.fifo_entry_count,
                               status.data_request );

                    /*@
                     * @errortype
                     * @reasoncode       I2C_FIFO_TIMEOUT
                     * @severity         ERRL_SEV_UNRECOVERABLE
                     * @moduleid         I2C_READ
                     * @userdata1[0:31]  Status Register Value
                     * @userdata1[32:63] Master Target
                     * @userdata2[0:7]   Master Engine
                     * @userdata2[8:15]  Master Port
                     * @userdata2[16:31] Slave Device Address
                     * @userdata2[32:47] Bus Speed
                     * @userdata2[48:63] Bit Rate Devisor
                     * @devdesc          Timed out waiting for data in FIFO to read
                     */
                    err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                   I2C_READ,
                                                   I2C_FIFO_TIMEOUT,
                                                   I2C_SET_USER_DATA_1(
                                                       status,
                                                       i_target),
                                                   I2C_SET_USER_DATA_2(i_args));

                    addHwCalloutsI2c(err, i_target, i_args);

                    // Or HB code failed to do the procedure correctly
                    err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                             HWAS::SRCI_PRIORITY_LOW);

                    err->collectTrace( I2C_COMP_NAME, 256);

                    break;
                }
            }

            if( err )
            {
                break;
            }

            // Read the data from the fifo
            fifo.value = 0x0ull;

            err = i2cRegisterOp( DeviceFW::READ,
                                 i_target,
                                 &fifo.value,
                                 I2C_REG_FIFO,
                                 i_args );

            TRACUCOMP( g_trac_i2c,
                       INFO_MRK"i2cRead() - FIFO = 0x%016llx",
                       fifo.value);

            if( err )
            {
                break;
            }

            *((uint8_t*)o_buffer + bytesRead) = fifo.byte_0;

            // Every time FIFO is read, reset timeout count
            timeoutCount = I2C_TIMEOUT_COUNT( interval_ns );

            TRACUCOMP( g_trac_i2cr,
                       "I2C READ  DATA  : engine %.2X : port %.2x : "
                       "devAddr %.2X : byte %d : %.2X (0x%lx)",
                       i_args.engine, i_args.port, i_args.devAddr,
                       bytesRead, fifo.byte_0, fifo.value );

            // Printing mux info separately, if combined, nothing is displayed
            if (i_args.i2cMuxPath)
            {
                char* l_muxPath = i_args.i2cMuxPath->toString();
                TRACUCOMP(g_trac_i2c, "i2cRead(): muxSelector=0x%X, "
                          "muxPath=%s", i_args.i2cMuxBusSelector, l_muxPath);
                free(l_muxPath);
                l_muxPath = nullptr;
            }
            else
            {
                TRACUCOMP(g_trac_i2c, "i2cRead(): muxSelector=0x%X, "
                          "muxPath=NULL", i_args.i2cMuxBusSelector);
            }
        }

        if( err )
        {
            break;
        }

        // Poll for Command Complete
        err = i2cWaitForCmdComp( i_target,
                                 i_args );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACSCOMP( g_trac_i2cr,
               "I2C READ  END   : engine %.2X : port %.2x : devAddr %.2X : "
               "len %d",
               i_args.engine, i_args.port, i_args.devAddr, i_buflen );

    // Printing mux info separately, if combined, nothing is displayed
    if (i_args.i2cMuxPath)
    {
        char* l_muxPath = i_args.i2cMuxPath->toString();
        TRACSCOMP(g_trac_i2c, "i2cRead(): muxSelector=0x%X, muxPath=%s",
                  i_args.i2cMuxBusSelector, l_muxPath);
        free(l_muxPath);
        l_muxPath = nullptr;
    }
    else
    {
        TRACSCOMP(g_trac_i2c, "i2cRead(): muxSelector=0x%X, muxPath=NULL",
                  i_args.i2cMuxBusSelector);
    }

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cRead()" );

    return err;
} // end i2cRead

// ------------------------------------------------------------------
// i2cWrite
// ------------------------------------------------------------------
errlHndl_t i2cWrite ( TARGETING::Target * i_target,
                      void * i_buffer,
                      size_t & io_buflen,
                      misc_args_t & i_args)
{
    errlHndl_t err = nullptr;
    uint64_t bytesWritten = 0x0;

    // Define regs we'll be using
    fifo_reg_t fifo;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cWrite()" );

    TRACSCOMP( g_trac_i2c,
               "I2C WRITE START : engine %.2X : port %.2x : devAddr %.2X : "
               "len %d", i_args.engine, i_args.port, i_args.devAddr, io_buflen);

    // Printing mux info separately, if combined, nothing is displayed
    if (i_args.i2cMuxPath)
    {
        char* l_muxPath = i_args.i2cMuxPath->toString();
        TRACSCOMP(g_trac_i2c, "i2cWrite(): muxSelector=0x%X, muxPath=%s",
                  i_args.i2cMuxBusSelector, l_muxPath);
        free(l_muxPath);
    }
    else
    {
        TRACSCOMP(g_trac_i2c, "i2cWrite(): muxSelector=0x%X, muxPath=NULL",
                  i_args.i2cMuxBusSelector);
    }

    do
    {
        // Do Command/Mode reg setups
        i_args.read_not_write = false;

        err = i2cSetup( i_target,
                        io_buflen,
                        i_args);

        if( err )
        {
            break;
        }

        for( bytesWritten = 0x0; bytesWritten < io_buflen; ++bytesWritten )
        {
            // Wait for FIFO space to be available for the write
            err = i2cWaitForFifoSpace( i_target,
                                       i_args );

            if( err )
            {
                break;
            }

            // Write data to FIFO
            fifo.value = 0x0ull;
            fifo.byte_0 = *((uint8_t*)i_buffer + bytesWritten);

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &fifo.value,
                                 I2C_REG_FIFO,
                                 i_args );

            if( err )
            {
                break;
            }

            TRACSCOMP( g_trac_i2cr,
                       "I2C WRITE DATA  : engine %.2X : port %.2X : "
                       "devAddr %.2X : byte %d : %.2X (0x%lx)",
                       i_args.engine, i_args.port, i_args.devAddr,
                       bytesWritten, fifo.byte_0, fifo.value );
        }

        if( err )
        {
            break;
        }

        // Check for Command complete
        err = i2cWaitForCmdComp( i_target,
                                 i_args );

        if( err )
        {
            break;
        }

        // Make sure we send back how many bytes were written
        io_buflen = bytesWritten;
    } while( 0 );

    TRACSCOMP( g_trac_i2cr,
               "I2C WRITE END   : engine %.2X: port %.2X : devAddr %.2X : "
               "len %d", i_args.engine, i_args.port, i_args.devAddr, io_buflen);

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cWrite()" );

    return err;
} // end i2cWrite

// ------------------------------------------------------------------
// i2cSetup
// ------------------------------------------------------------------
errlHndl_t i2cSetup ( TARGETING::Target * i_target,
                      size_t & i_buflen,
                      misc_args_t & i_args)
{
    errlHndl_t err = nullptr;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetup(): buf_len=%d, r_nw=%d, w_start=%d, "
               "w_address=%d, w_stop=%d, read_continue=%d, sms=%d",
               i_buflen, i_args.read_not_write, i_args.with_start,
               i_args.with_address, i_args.with_stop,
               i_args.read_continue,i_args.skip_mode_setup);

    // Define the registers that we'll use
    mode_reg_t mode;
    command_reg_t cmd;

    do
    {
        // Wait for Command complete before we start
        err = i2cWaitForCmdComp( i_target,
                                 i_args );

        if( err )
        {
            break;
        }


        // Skip mode setup on 2nd of 2 cmd strung together - like when sending
        //  device offset first before read or write

        if ( i_args.skip_mode_setup == false)
        {
            // Write Mode Register:
            //      - bit rate divisor (set in i2cSetClockVariables() )
            //      - port number

            mode.value = 0x0ull;
            mode.bit_rate_div = i_args.bit_rate_divisor;

            //On P10 in FSI mode,
            //  Engine 0/B (for OCC)
            //    PIB [0, 13] -> FSI [4, 17]
            //  Engine 1/C (Host)
            //    PIB [0, 13] -> FSI [4, 17]
            //  Engine 2/D (Host)
            //    No mapping to FSI
            //  Engine 3/E (Host)
            //    PIB [0, 3] -> FSI [0, 3]
            //    PIB [4, 15] -> FSI [6, 17]
            if ( i_args.switches.useFsiI2C )
            {
                if ( HOST_ENGINE_B == i_args.engine )
                {
                    mode.port_num = i_args.port + 4;
                }
                else if ( HOST_ENGINE_C == i_args.engine )
                {
                    mode.port_num = i_args.port + 4;
                }
                else if ( HOST_ENGINE_E == i_args.engine )
                {
                    if ( i_args.port <= 3 )
                    {
                        mode.port_num = i_args.port;
                    }
                    else
                    {
                        mode.port_num = i_args.port + 2;
                    }
                }
            }
            else
            {
                mode.port_num = i_args.port;
            }

            TRACUCOMP( g_trac_i2c,"i2cSetup(): set mode = 0x%lx", mode.value);

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &mode.value,
                                 I2C_REG_MODE,
                                 i_args );

            if( err )
            {
                break;
            }
        }


        // Write Command Register:
        //      - with start
        //      - with continue
        //      - with stop
        //      - with address
        //      - RnW
        //      - length
        cmd.value = 0x0ull;
        cmd.with_start = (i_args.with_start ? 1 : 0);
        cmd.read_continue = (i_args.read_continue ? 1 : 0);
        cmd.with_stop = (i_args.with_stop ? 1 : 0);
        cmd.with_addr = (i_args.with_address ? 1 : 0);

        // cmd.device_addr is 7 bits
        // devAddr though is a uint64_t
        //  -- value stored in LSB byte of uint64_t
        //  -- LS-bit is unused, creating the 7 bit cmd.device_addr
        //  So will be masking for LSB, and then shifting to push off LS-bit
        cmd.device_addr = (0x000000FF & i_args.devAddr) >> 1;

        cmd.read_not_write = (i_args.read_not_write ? 1 : 0);
        cmd.length_b = i_buflen;

        TRACUCOMP( g_trac_i2c,"i2cSetup(): set cmd = 0x%lx", cmd.value);

        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &cmd.value,
                             I2C_REG_COMMAND,
                             i_args );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetup()" );

    return err;
} // end i2cSetup


// ------------------------------------------------------------------
// i2cGetEngineMutex
// ------------------------------------------------------------------
bool i2cGetEngineMutex( const TARGETING::Target * const i_target,
                        const misc_args_t &  i_args,
                              mutex_t *&     i_engineLock )
{
    bool success = true;

    do
    {
        switch( i_args.engine )
        {
            case HOST_ENGINE_B:
                i_engineLock = i_target->
                           getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_0>();
                break;
            case HOST_ENGINE_C:
                i_engineLock = i_target->
                           getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_1>();
                break;
            case HOST_ENGINE_D:
                i_engineLock = i_target->
                           getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_2>();
                break;
            case HOST_ENGINE_E:
                i_engineLock = i_target->
                           getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_3>();
                break;
            default:
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"i2cGetEngineMutex: Invalid engine for getting Mutex! "
                           "i_args.engine=%d", i_args.engine );
                success = false;
                assert(false, "i2c.C: Invalid engine for getting Mutex!"
                       "i_args.engine=%d", i_args.engine );

                break;
        };

    }while( 0 );

    return success;
}

// ------------------------------------------------------------------
// i2cGetPageMutex
// ------------------------------------------------------------------
bool i2cGetPageMutex( TARGETING::Target * i_target,
                      misc_args_t & i_args,
                      mutex_t *& i_pageLock )
{
    bool success = true;
    do
    {
        switch( i_args.engine )
        {
            case HOST_ENGINE_B:
                i_pageLock = i_target->
                    getHbMutexAttr<TARGETING::ATTR_I2C_PAGE_MUTEX_0>();
                break;
            case HOST_ENGINE_C:
                i_pageLock = i_target->
                    getHbMutexAttr<TARGETING::ATTR_I2C_PAGE_MUTEX_1>();
                break;
            case HOST_ENGINE_D:
                i_pageLock = i_target->
                    getHbMutexAttr<TARGETING::ATTR_I2C_PAGE_MUTEX_2>();
                break;
            case HOST_ENGINE_E:
                i_pageLock = i_target->
                    getHbMutexAttr<TARGETING::ATTR_I2C_PAGE_MUTEX_3>();
                break;
            default:
                TRACFCOMP( g_trac_i2c,
                        ERR_MRK"i2cGetPageMutex: Invalid engine for getting mutex!");
                success = false;
                assert(false, "i2c.C: Invalid engine for getting Mutex!"
                        "i_args.engine=%d", i_args.engine );
                break;

        };

    }while( 0 );
    return success;
}


// ------------------------------------------------------------------
// i2cWaitForCmdComp
// ------------------------------------------------------------------
errlHndl_t i2cWaitForCmdComp ( TARGETING::Target * i_target,
                               misc_args_t & i_args)
{
    errlHndl_t err = nullptr;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cWaitForCmdComp()" );

    // Define the registers that we'll use
    status_reg_t status;

    // Use Local Variables (timeoutCount gets decremented)
    uint64_t interval_ns  = i_args.polling_interval_ns;
    uint64_t timeoutCount = i_args.timeout_count;

    TRACUCOMP(g_trac_i2c, "i2cWaitForCmdComp(): timeoutCount=%d, "
              "interval_ns=%d", timeoutCount, interval_ns);

    do
    {
        // Check the Command Complete bit
        do
        {
            nanosleep( 0, interval_ns );

            status.value = 0x0ull;
            err = i2cReadStatusReg( i_target,
                                    i_args,
                                    status );

            if( err )
            {
                TRACFCOMP(g_trac_i2c, "Errored at i2cWaitForCmdComplete::i2cReadStatusReg");
                break;
            }

            if( 0 == timeoutCount-- )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"i2cWaitForCmdComp() - "
                           "Timed out waiting for Command Complete! "
                           "status=%016llX", status.value );

                /*@
                 * @errortype
                 * @reasoncode       I2C_CMD_COMP_TIMEOUT
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         I2C_WAIT_FOR_CMD_COMP
                 * @userdata1[0:31]  Status Register Value
                 * @userdata1[32:63] Master Target
                 * @userdata2[0:7]   Master Engine
                 * @userdata2[8:15]  Master Port
                 * @userdata2[16:31] Slave Device Address
                 * @userdata2[32:47] Bus Speed
                 * @userdata2[48:63] Bit Rate Devisor
                 * @devdesc          Timed out waiting for command complete.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               I2C_WAIT_FOR_CMD_COMP,
                                               I2C_CMD_COMP_TIMEOUT,
                                               I2C_SET_USER_DATA_1(
                                                   status,
                                                   i_target),
                                               I2C_SET_USER_DATA_2(i_args));

                addHwCalloutsI2c(err, i_target, i_args);

                // Or HB code failed to do the procedure correctly
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);

                err->collectTrace( I2C_COMP_NAME, 256);

                break;
            }
        } while( 0 == status.command_complete ); /* Command Complete */

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cWaitForCmdComp()" );

    return err;
} // end i2cWaitForBus

// ------------------------------------------------------------------
// i2cReadStatusReg
// ------------------------------------------------------------------
errlHndl_t i2cReadStatusReg ( TARGETING::Target * i_target,
                              misc_args_t & i_args,
                              status_reg_t & o_statusReg )
{
    errlHndl_t err = nullptr;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cReadStatusReg()" );

    do
    {
        // Read the status Reg
        err = i2cRegisterOp( DeviceFW::READ,
                             i_target,
                             &o_statusReg.value,
                             I2C_REG_STATUS,
                             i_args );

        if( err )
        {
            break;
        }

        TRACUCOMP(g_trac_i2c,"i2cReadStatusReg(): "
                  INFO_MRK"status: 0x%016llx",
                  o_statusReg.value );


        // Check for Errors
        // Per the specification it is a requirement to check for errors each time
        // that the status register is read.
        err = i2cCheckForErrors( i_target,
                                 i_args,
                                 o_statusReg );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       "i2cReadStatusReg() saw i2cCheckForErrors error" );
            break;
        }
    } while( 0 );

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cReadStatusReg()" );

    return err;
} // end i2cReadStatusReg

// ------------------------------------------------------------------
// i2cCheckForErrors
// ------------------------------------------------------------------
errlHndl_t i2cCheckForErrors ( TARGETING::Target * i_target,
                               misc_args_t & i_args,
                               status_reg_t i_statusVal )
{
    errlHndl_t err = nullptr;
    bool errorFound = false;
    bool nackFound  = false;
    bool busArbiLostFound = false;
    uint64_t intRegVal = 0x0;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cCheckForErrors()" );

    do
    {
        if( 1 == i_statusVal.invalid_cmd )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Invalid Command! - status reg: %016llx"
                       TRACE_I2C_ADDR_FMT,
                       i_statusVal.value, TRACE_I2C_ADDR_ARGS(i_args) );
        }

        if( 1 == i_statusVal.lbus_parity_error )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Local Bus Parity Error! - status reg: %016llx"
                       TRACE_I2C_ADDR_FMT,
                       i_statusVal.value, TRACE_I2C_ADDR_ARGS(i_args) );
        }

        if( 1 == i_statusVal.backend_overrun_error )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C BackEnd OverRun Error! - status reg: %016llx"
                       TRACE_I2C_ADDR_FMT,
                       i_statusVal.value, TRACE_I2C_ADDR_ARGS(i_args) );
        }

        if( 1 == i_statusVal.backend_access_error )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C BackEnd Access Error! - status reg: %016llx"
                       TRACE_I2C_ADDR_FMT,
                       i_statusVal.value, TRACE_I2C_ADDR_ARGS(i_args) );
        }

        if( 1 == i_statusVal.arbitration_lost_error )
        {
            busArbiLostFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Arbitration Lost! - status reg: %016llx"
                       TRACE_I2C_ADDR_FMT,
                       i_statusVal.value, TRACE_I2C_ADDR_ARGS(i_args) );
        }

        if( 1 == i_statusVal.nack_received )
        {
            // Rather than using 'errorFound', use specific nackFound
            nackFound  = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C NACK Received! - status reg: %016llx"
                       TRACE_I2C_ADDR_FMT,
                       i_statusVal.value, TRACE_I2C_ADDR_ARGS(i_args) );
        }


        if( 1 == i_statusVal.stop_error )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C STOP Error! - status reg: %016llx"
                       TRACE_I2C_ADDR_FMT,
                       i_statusVal.value, TRACE_I2C_ADDR_ARGS(i_args) );
        }

        if( 1 == i_statusVal.any_i2c_interrupt )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Interrupt Detected! - status reg: %016llx"
                       TRACE_I2C_ADDR_FMT,
                       i_statusVal.value, TRACE_I2C_ADDR_ARGS(i_args) );

            // Get the Interrupt Register value to add to the log
            // - i2cGetInterrupts() adds intRegVal to trace, so it ill be added
            //   to error log below
            err = i2cGetInterrupts( i_target,
                                    i_args,
                                    intRegVal );

            if( err )
            {
                break;
            }

        }

        // read the extended status too
        if( errorFound || busArbiLostFound )
        {
            // Read the extended status Reg
            extended_status_reg_t extstat;
            extstat.value=0;
            err = i2cRegisterOp( DeviceFW::READ,
                                 i_target,
                                 &extstat.value,
                                 I2C_REG_EXTENDED_STATUS,
                                 i_args );

            if( err )
            {
                TRACFCOMP( g_trac_i2c, ERR_MRK"i2cCheckForErrors()> I2C_REG_EXTENDED_STATUS read failed - ignoring!!" );
                delete err;
            }
            TRACFCOMP(g_trac_i2c,"Reading I2C_REG_EXTENDED_STATUS(8)=%.8X",
                      extstat.value);
        }


        if( errorFound )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cCheckForErrors() - Error(s) found on %.8X"
                       TRACE_I2C_ADDR_FMT,
                       TARGETING::get_huid(i_target),
                       TRACE_I2C_ADDR_ARGS(i_args) );


            /*@
             * @errortype
             * @reasoncode       I2C_HW_ERROR_FOUND
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         I2C_CHECK_FOR_ERRORS
             * @userdata1[0:31]  Status Register Value
             * @userdata1[32:63] Master Target
             * @userdata2[0:7]   Master Engine
             * @userdata2[8:15]  Master Port
             * @userdata2[16:31] Slave Device Address
             * @userdata2[32:47] Bus Speed
             * @userdata2[48:63] Bit Rate Devisor
             * @devdesc          Error was found in I2C status register.
             *                   Check userdata to determine what the error was.
             * @custdesc       A problem occurred during the IPL of the system:
             *                 An error was found in the I2C status register.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_CHECK_FOR_ERRORS,
                                           I2C_HW_ERROR_FOUND,
                                           I2C_SET_USER_DATA_1(
                                               i_statusVal,
                                               i_target),
                                           I2C_SET_USER_DATA_2(i_args));

            addHwCalloutsI2c(err, i_target, i_args);

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( I2C_COMP_NAME );

            break;
        }

        else if ( nackFound )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cCheckForErrors() - NACK found (only error) on %.8X"
                       TRACE_I2C_ADDR_FMT,
                       TARGETING::get_huid(i_target),
                       TRACE_I2C_ADDR_ARGS(i_args) );

            /*@
             * @errortype
             * @reasoncode       I2C_NACK_ONLY_FOUND
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         I2C_CHECK_FOR_ERRORS
             * @userdata1[0:31]  Status Register Value
             * @userdata1[32:63] Master Target
             * @userdata2[0:7]   Master Engine
             * @userdata2[8:15]  Master Port
             * @userdata2[16:31] Slave Device Address
             * @userdata2[32:47] Bus Speed
             * @userdata2[48:63] Bit Rate Devisor
             * @devdesc        a NACK Error was found in the I2C status
             *                 register.
             * @custdesc       A problem occurred during the IPL of the system:
             *                 A NACK error was found in the I2C Status
             *                 register.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_CHECK_FOR_ERRORS,
                                           I2C_NACK_ONLY_FOUND,
                                           I2C_SET_USER_DATA_1(
                                               i_statusVal,
                                               i_target),
                                           I2C_SET_USER_DATA_2(i_args));

            addHwCalloutsI2c(err, i_target, i_args);

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( I2C_COMP_NAME );

            break;
        }
        else if( busArbiLostFound )
        {
            TRACFCOMP( g_trac_i2c,
            ERR_MRK"i2cCheckForErrors() - Bus Arbitration Lost (only error) on %.8X"
                    TRACE_I2C_ADDR_FMT,
                    TARGETING::get_huid(i_target),
                    TRACE_I2C_ADDR_ARGS(i_args) );


            /*@
             * @errortype
             * @reasoncode       I2C_ARBITRATION_LOST_ONLY_FOUND
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         I2C_CHECK_FOR_ERRORS
             * @userdata1[0:31]  Status Register Value
             * @userdata1[32:63] Master Target
             * @userdata2[0:7]   Master Engine
             * @userdata2[8:15]  Master Port
             * @userdata2[16:31] Slave Device Address
             * @userdata2[32:47] Bus Speed
             * @userdata2[48:63] Bit Rate Devisor
             * @devdesc        Bus Arbitration Lost Error was found in
             *                 the I2C status register.
             * @custdesc       A problem occurred during the IPL of the system:
             *                 A Bus Arbitration Lost error was found
             *                 in the I2C status register.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_CHECK_FOR_ERRORS,
                                           I2C_ARBITRATION_LOST_ONLY_FOUND,
                                           I2C_SET_USER_DATA_1(
                                               i_statusVal,
                                               i_target),
                                           I2C_SET_USER_DATA_2(i_args));

            addHwCalloutsI2c(err, i_target, i_args);

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( I2C_COMP_NAME );

            break;
        }

    } while( 0 );

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cCheckForErrors()" );

    return err;
} // end i2cCheckForErrors


// ------------------------------------------------------------------
// i2cWaitForFifoSpace
// ------------------------------------------------------------------
errlHndl_t i2cWaitForFifoSpace ( TARGETING::Target * i_target,
                                 misc_args_t & i_args )
{
    errlHndl_t err = nullptr;

    // Use Local Variables (timeoutCount gets derecmented)
    uint64_t interval_ns  = i_args.polling_interval_ns;
    uint64_t timeoutCount = i_args.timeout_count;

    // Define regs we'll be using
    status_reg_t status;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cWaitForFifoSpace()" );

    do
    {
        // Read Status reg to get available FIFO bytes
        status.value = 0x0ull;
        err = i2cReadStatusReg( i_target,
                                i_args,
                                status );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                    "Errored out at i2cReadStatusReg: statusreg = %016llx",
                    status.value);
            break;
        }

        TRACUCOMP( g_trac_i2c, "i2cWaitForFifoSpace(): status=0x%016llx "
                   "I2C_MAX_FIFO_CAPACITY=%d, status.fifo_entry_count=%d",
                   status.value, I2C_MAX_FIFO_CAPACITY,
                   status.fifo_entry_count);

        // 2 Conditions to wait on:
        // 1) FIFO is full
        // 2) Data Request bit is not set
        while( (I2C_MAX_FIFO_CAPACITY <= status.fifo_entry_count) &&
               (0 == status.data_request)                             )
        {
            // FIFO is full, wait before writing any data
            nanosleep( 0, interval_ns );

            status.value = 0x0ull;
            err = i2cReadStatusReg( i_target,
                                    i_args,
                                    status );

            if( err )
            {
                break;
            }

            if( 0 == timeoutCount-- )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"i2cWrite() - Timed out waiting for space in FIFO!" );

                /*@
                 * @errortype
                 * @reasoncode       I2C_FIFO_TIMEOUT
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         I2C_WRITE
                 * @userdata1[0:31]  Status Register Value
                 * @userdata1[32:63] Master Target
                 * @userdata2[0:7]   Master Engine
                 * @userdata2[8:15]  Master Port
                 * @userdata2[16:31] Slave Device Address
                 * @userdata2[32:47] Bus Speed
                 * @userdata2[48:63] Bit Rate Devisor
                 * @devdesc        Timed out waiting for space to write into FIFO.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               I2C_WRITE,
                                               I2C_FIFO_TIMEOUT,
                                               I2C_SET_USER_DATA_1(
                                                   status,
                                                   i_target),
                                               I2C_SET_USER_DATA_2(i_args));

                addHwCalloutsI2c(err, i_target, i_args);

                // Or HB code failed to do the procedure correctly
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);

                err->collectTrace( I2C_COMP_NAME, 256);

                break;
            }
        }

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cWaitForFifoSpace()" );

    return err;
} // end i2cWaitForFifoSpace

// ------------------------------------------------------------------
// i2cSendStopSignal
// ------------------------------------------------------------------
errlHndl_t i2cSendStopSignal(TARGETING::Target * i_target,
                                misc_args_t & i_args)
{

    errlHndl_t err = nullptr;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cSendStopSignal" );

    do
    {
        residual_length_reg_t clkdataline;
        clkdataline.value = 0x0;

        //manually send stop signal
        // set clock low: write 0 to immediate reset scl register

        TRACUCOMP(g_trac_i2c,"i2cSendStopSignal"
                  "clock line 0x%016llx",
                  clkdataline.value );

        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkdataline.value,
                             I2C_REG_RESET_SCL,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C reset SCL register Failed!!" );
            break;
        }

        //set data low: write 0 to immediate reset sda register
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkdataline.value,
                             I2C_REG_RESET_SDA,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C reset SDA register Failed!!" );
            break;
        }

        // set clock high: write 0 to immediate set scl register
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkdataline.value,
                             I2C_REG_SET_SCL,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C set SCL register Failed!!" );
            break;
        }

        //set data high: write 0 to immediate set sda register
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkdataline.value,
                             I2C_REG_SET_SDA,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C set SDA register Failed!!" );
            break;
        }
    }while(0);

    return err;
}//end i2cSendStopSignal


// ------------------------------------------------------------------
// i2cToggleClockLine
// ------------------------------------------------------------------
errlHndl_t i2cToggleClockLine(TARGETING::Target * i_target,
                                misc_args_t & i_args)
{

    errlHndl_t err = nullptr;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cToggleClockLine()" );

    do
    {
        residual_length_reg_t clkline;
        clkline.value = 0x0;

        //toggle clock line
        // set clock low: write 0 to immediate reset scl register

        TRACFCOMP(g_trac_i2c,"i2cToggleClockLine()"
                  "clock line 0x%016llx",
                  clkline.value );

        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkline.value,
                             I2C_REG_RESET_SCL,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C reset SCL register Failed!!" );
            break;
        }

        // set clock high: write 0 to immediate set scl register
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkline.value,
                             I2C_REG_SET_SCL,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C set SCL register Failed!!" );
            break;
        }

    }while(0);

    return err;
}//end i2cToggleClockLine


// ------------------------------------------------------------------
// i2cForceResetAndUnlock
// ------------------------------------------------------------------
errlHndl_t i2cForceResetAndUnlock( TARGETING::Target * i_target,
                                    misc_args_t & i_args)
{
    errlHndl_t err = nullptr;
    mode_reg_t mode;
    uint64_t l_speed = I2C_BUS_SPEED_FROM_MRW;

    // I2C Bus Speed Array
    TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speed_array;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cForceResetAndUnlock()" );

    do
    {

        // Get I2C Bus Speed Array attribute.  It will be used to determine
        // which engine/port combinations have devices on them
        if (  !( i_target->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
                                          (speed_array) ) )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cForceResetAndUnlock() - Cannot find "
                       "ATTR_I2C_BUS_SPEED_ARRAY needed for operation");
            /*@
             * @errortype
             * @reasoncode     I2C_ATTRIBUTE_NOT_FOUND
             * @severity       ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid       I2C_FORCE_RESET_AND_UNLOCK
             * @userdata1      Target for the attribute
             * @userdata2      <UNUSED>
             * @devdesc        ATTR_I2C_BUS_SPEED_ARRAY not found
             * @custdesc       I2C configuration data missing
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_FORCE_RESET_AND_UNLOCK,
                                           I2C_ATTRIBUTE_NOT_FOUND,
                                           TARGETING::get_huid(i_target),
                                           0x0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( I2C_COMP_NAME, 256);

            break;
        }

        uint32_t l_numPorts = I2C_BUS_ATTR_MAX_PORT;
        if (i_args.switches.useFsiI2C == 1)
        {
            TRACFCOMP( g_trac_i2c,INFO_MRK
                      "Using FSI I2C, use numports: %d", FSI_MODE_MAX_PORT);
            l_numPorts = FSI_MODE_MAX_PORT;
        }

        // Need to send slave stop to all ports with a device on the engine
        for( uint32_t port = 0; port < l_numPorts; port++ )
        {
            //Check if diag mode should be skipped
            TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

            if (l_type == TARGETING::TYPE_PROC)
            {
                // The FSI accessible I2C master on non-master P10 processors,
                // and I2C Engine E, do not allow diagnostic mode when Secure
                // Boot is enabled.  Note that because I2C is needed before
                // presence detect, we cannot check the security state of the
                // processor, so we use the master secure mode as a proxy.
                // However, we are unable to assume that the processors' secure
                // access bits (SABs) all match early in the IPL.  Therefore we
                // are disabling diagnostic mode for all FSI-based or Engine E
                // resets.
                if(i_args.switches.useFsiI2C || i_args.engine == HOST_ENGINE_E)
                {
                    TRACFCOMP(g_trac_i2c,
                              INFO_MRK "Not doing i2cForceResetAndUnlock() for "
                              "target=0x%08X: e/p= %d/%d due to P10 diag mode "
                              "limitations. Secure mode enabled = %d",
                              TARGETING::get_huid(i_target),
                              i_args.engine, port,
                              SECUREBOOT::enabled());

                    // Printing mux info separately, if combined, nothing is displayed
                    if (i_args.i2cMuxPath)
                    {
                        char* l_muxPath = i_args.i2cMuxPath->toString();
                        TRACFCOMP(g_trac_i2c, INFO_MRK"i2cForceResetAndUnlock(): "
                                  "muxSelector=0x%X, muxPath=%s",
                                  i_args.i2cMuxBusSelector, l_muxPath);
                        free(l_muxPath);
                        l_muxPath = nullptr;
                    }
                    else
                    {
                        TRACFCOMP(g_trac_i2c, INFO_MRK"i2cForceResetAndUnlock(): "
                                  "muxSelector=0x%X, muxPath=NULL",
                                  i_args.i2cMuxBusSelector);
                    }

                    continue;
                }
            }

            size_t logical_engine = i_args.engine;
            size_t logical_port = port;
            if (i_args.switches.useFsiI2C == 1)
            {
                setLogicalFsiEnginePort(logical_engine, logical_port);
            }

            l_speed = speed_array[logical_engine][logical_port];
            if ( l_speed == 0 )
            {
                continue;
            }

            TRACFCOMP( g_trac_i2c,
                       INFO_MRK"i2cForceResetAndUnlock() - Performing op on %8X "
                       "engine=%d, port=%d",
                       TARGETING::get_huid(i_target),
                       i_args.engine, port);

            // Clear mode register
            mode.value = 0x0ull;

            // set port in mode register
            mode.port_num = port;

            // enable diagnostic mode in mode register
            mode.diag_mode = 0x1;

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &mode.value,
                                 I2C_REG_MODE,
                                 i_args );

            if( err )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"I2C Enable Diagnostic mode Failed!!" );


                // We still need to reset the other ports on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }


            //toggle clock line
            err = i2cToggleClockLine( i_target,
                                      i_args );

            if( err )
            {
                // We still need to reset the other ports on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            //manually send stop signal
            err = i2cSendStopSignal( i_target,
                                     i_args );

            if( err )
            {
                // We still need to reset the other ports on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            // disable diagnostic mode in mode register
            mode.diag_mode = 0x0;

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &mode.value,
                                 I2C_REG_MODE,
                                 i_args );


            if( err )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"I2C disable Diagnostic mode Failed!!" );
                // We still need to reset the other ports on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }


        } // end of port for loop

    }while(0);

    return err;
}// end i2cForceResetAndUnlock

// ------------------------------------------------------------------
// i2cReset
// ------------------------------------------------------------------
errlHndl_t i2cReset ( TARGETING::Target * i_target,
                      misc_args_t & i_args,
                      i2c_reset_level i_reset_level)
{
    errlHndl_t err = nullptr;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cReset() on %.8X, level=%d" TRACE_I2C_ADDR_FMT,
               TARGETING::get_huid(i_target),
               i_reset_level,
               TRACE_I2C_ADDR_ARGS(i_args) );

    do
    {
        // Go through a complete reset sequence in case we have floating lines
        //  or other issues
        // - clear interrupt masks
        // - reset port busy
        // - send a stop
        // - reset the engine registers
        // - reset any sticky errors in the engine (and the fifo)
        // - reset port busy (again)

        uint64_t dataval = 0;

        // Zero out any interrupt setup
        dataval = 0;
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &dataval,
                             I2C_REG_INTMASK,
                             i_args );
        if( err )
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cReset()> I2C_REG_INTMASK write failed - continue with reset!!" );
            delete err;
            err = nullptr;
        }

        // From I2CM spec :
        // The entire register can be forced to reset by writing 0x8000000000000000
        //  (i.e bit 0:1 = 0b10 and other bits can be any value)
        dataval = 0x8000000000000000;
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &dataval,
                             I2CM_PORT_BUSY_REGISTER,
                             i_args );
        if( err )
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cReset()> I2CM_PORT_BUSY_REGISTER write failed - continue with reset!!" );
            delete err;
            err = nullptr;
        }

        // Sets the with_stop bit to force a generic STOP to everything
        dataval = 0x1000000000000000;
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &dataval,
                             I2C_REG_COMMAND,
                             i_args );
        if( err )
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cReset()> I2C_REG_COMMAND write failed - continue with reset!!" );
            delete err;
            err = nullptr;
        }

        // Any write to this address will reset the engine
        dataval = 0;
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &dataval,
                             I2C_REG_RESET,
                             i_args );
        if( err )
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cReset()> I2C_REG_RESET write failed - continue with reset!!" );
            delete err;
            err = nullptr;
        }

        nanosleep( 0, I2C_RESET_DELAY_NS );

        // Any write to this address will reset the engine along with
        //  several error conditions
        dataval = 0;
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &dataval,
                             I2C_REG_RESET_ERRORS,
                             i_args );
        if( err )
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cReset()> I2C_REG_RESET_ERRORS write failed - continue with reset!!" );
            delete err;
            err = nullptr;
        }

        nanosleep( 0, I2C_RESET_DELAY_NS );

        // Resetting the port busy again after we reset the logic
        dataval = 0x8000000000000000;
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &dataval,
                             I2CM_PORT_BUSY_REGISTER,
                             i_args );
        if( err )
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cReset()> I2CM_PORT_BUSY_REGISTER write failed - continue with reset!!" );
            delete err;
            err = nullptr;
        }

        nanosleep( 0, I2C_RESET_DELAY_NS );

        // Read the status reg at the end for possible FFDC
        status_reg_t stat;
        stat.value=0;
        err = i2cRegisterOp( DeviceFW::READ,
                             i_target,
                             &stat.value,
                             I2C_REG_STATUS,
                             i_args );
        if( err )
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cReset()> I2C_REG_STATUS read failed!!" );
            break;
        }
        TRACFCOMP(g_trac_i2c,"i2cReset()> I2C_REG_STATUS(7) after reset=%.8X",
                  stat.value);

        //--- Standard reset is complete


        //if the reset is a force unlock then we need to enable
        //diagnostic mode and toggle the clock and data lines
        //to manually reset the bus
        if( i_reset_level == FORCE_UNLOCK_RESET )
        {
            err = i2cForceResetAndUnlock( i_target,
                                          i_args );

            if( err )
            {
                TRACFCOMP( g_trac_i2c,
                           "i2cReset() committing log from i2cForceResetAndUnlock" );
                // We still want to send the slave stop command since the
                // initial reset completed above.
                // So just commit the log here and let the function continue.
                errlCommit( err, I2C_COMP_ID );
            }
        }

        // Part of doing the I2C Master reset is also sending a stop
        // command to all of the slave devices.
        err = i2cSendSlaveStop( i_target,
                                i_args );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cReset()" );

    return err;
} // end i2cReset


// ------------------------------------------------------------------
// i2cSendSlaveStop
// ------------------------------------------------------------------
errlHndl_t i2cSendSlaveStop ( TARGETING::Target * i_target,
                              misc_args_t & i_args)
{
    errlHndl_t err = nullptr;

    // Master Registers
    mode_reg_t mode;
    command_reg_t cmd;
    status_reg_t status_reg;
    uint64_t l_speed = I2C_BUS_SPEED_FROM_MRW;

    // I2C Bus Speed Array
    TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speed_array;
    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cSendSlaveStop()" );

    do
    {

        // Get I2C Bus Speed Array attribute.  It will be used to determine
        // which engine/port combinations have devices on them
        if (  !( i_target->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
                                          (speed_array) ) )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cSendSlaveStop() - Cannot find "
                       "ATTR_I2C_BUS_SPEED_ARRAY needed for operation");

            /*@
             * @errortype
             * @reasoncode     I2C_ATTRIBUTE_NOT_FOUND
             * @severity       ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid       I2C_SEND_SLAVE_STOP
             * @userdata1      Target for the attribute
             * @userdata2      <UNUSED>
             * @devdesc        ATTR_I2C_BUS_SPEED_ARRAY not found
             * @custdesc       I2C configuration data missing
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_SEND_SLAVE_STOP,
                                           I2C_ATTRIBUTE_NOT_FOUND,
                                           TARGETING::get_huid(i_target),
                                           0x0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( I2C_COMP_NAME, 256);

            break;
        }

        uint32_t l_numPorts = I2C_BUS_ATTR_MAX_PORT;
        if (i_args.switches.useFsiI2C == 1)
        {
            TRACFCOMP( g_trac_i2c,INFO_MRK
                      "Using FSI I2C, use numports: %d", FSI_MODE_MAX_PORT);
            l_numPorts = FSI_MODE_MAX_PORT;
        }

        // Need to send slave stop to all ports with a device on the engine
        for( uint32_t port = 0; port < l_numPorts; port++ )
        {
            // Only send stop to a port if there are devices on it
            l_speed = speed_array[i_args.engine][port];
            if ( l_speed == 0 )
            {
                continue;
            }

            // TODO RTC 178394: Investigate XSCOM errros and improve i2c
            //   presence detect here to remove this workaround
            if ( (i_args.engine == 1) && (port >= 4) )
            {
                TRACFCOMP( g_trac_i2c,
                  "Saw Errors resetting these devices, temporarily skipping engine: %d, port: %d",
                   i_args.engine, port);
                continue;
            }

            mode.value = 0x0ull;

            mode.port_num = port;
            mode.enhanced_mode = 1;

            // Need this to set bit_rate_divisor
            err = i2cSetBusVariables ( i_target,
                                       l_speed,
                                       i_args );
            if( err )
            {
                TRACFCOMP( g_trac_i2c,
                           "i2cSendSlaveStop() committing log from i2cSetBusVariables" );
                // We still need to send the slave stop to the other ports
                // on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            mode.bit_rate_div = i_args.bit_rate_divisor;
            TRACUCOMP(g_trac_i2c,"i2cSendSlaveStop(): "
                      "mode: 0x%016llx",
                      mode.value );

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &mode.value,
                                 I2C_REG_MODE,
                                 i_args );

            if( err )
            {
                TRACFCOMP( g_trac_i2c,
                           "i2cSendSlaveStop() committing log from i2cRegisterOp" );
                // We still need to send the slave stop to the other ports
                // on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            // Look for clock line (SCL) to be high
            // such that the 'stop' command will work
            status_reg.value = 0x0ull;
            size_t delay_ns = 0;
            for ( ;
                  delay_ns <= I2C_RESET_POLL_DELAY_TOTAL_NS;
                  delay_ns += I2C_RESET_POLL_DELAY_NS)
            {
                err = i2cRegisterOp( DeviceFW::READ,
                                     i_target,
                                     &status_reg.value,
                                     I2C_REG_STATUS,
                                     i_args );

                if( err )
                {
                    TRACFCOMP( g_trac_i2c,
                               ERR_MRK"Reading I2C Status Reg Failed!!" );
                    break;
                }

                if (status_reg.scl_input_level != 0)
                {
                    break;
                }

                // Sleep before polling again
                nanosleep( 0, I2C_RESET_POLL_DELAY_NS );

            }

            if ( err )
            {
                TRACFCOMP( g_trac_i2c,
                           "i2cSendSlaveStop() committing log from i2cRegisterOp 1" );
                // We still need to send the slave stop to the other ports
                // on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            if ( delay_ns > I2C_RESET_POLL_DELAY_TOTAL_NS )
            {
                // We don't see clock line high; in this case
                // it's not likely for a slave stop command to work.  One
                // possible nasty side-effect of attempting slave stop is the
                // I2C master can become indefinitely busy and prevent writes
                // to the mode register from completing. Just continue to the
                // next port.
                TRACFCOMP( g_trac_i2c, ERR_MRK"i2cSendSlaveStop(): "
                           "Not seeing SCL (%d) high "
                           "after %d ns of polling (max=%d). "
                           "Full status register = 0x%.16llX. "
                           "Inhibiting sending slave stop to e%/p%, "
                           "for HUID 0x%08X.",
                           status_reg.scl_input_level,
                           delay_ns,
                           I2C_RESET_POLL_DELAY_TOTAL_NS,
                           status_reg.value,
                           i_args.engine,
                           port,
                           TARGETING::get_huid(i_target));

                // Printing mux info separately, if combined, nothing is displayed
                if (i_args.i2cMuxPath)
                {
                    char* l_muxPath = i_args.i2cMuxPath->toString();
                    TRACFCOMP(g_trac_i2c, ERR_MRK"i2cSendSlaveStop(): "
                              "muxSelector=0x%X, muxPath=%s",
                              i_args.i2cMuxBusSelector, l_muxPath);
                    free(l_muxPath);
                    l_muxPath = nullptr;
                }
                else
                {
                    TRACFCOMP(g_trac_i2c, ERR_MRK"i2cSendSlaveStop(): "
                              "muxSelector=0x%X, muxPath=NULL",
                              i_args.i2cMuxBusSelector);
                }

                continue;
            }

            cmd.value = 0x0ull;
            cmd.with_stop = 1;

            TRACFCOMP(g_trac_i2c,"i2cSendSlaveStop(): "
                      "cmd: 0x%016llx",
                      cmd.value );

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &cmd.value,
                                 I2C_REG_COMMAND,
                                 i_args );

            if( err )
            {
                TRACFCOMP( g_trac_i2c,
                           "i2cSendSlaveStop() committing log from i2cRegisterOp 2" );
                // We still need to send the slave stop to the other ports
                // on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            // Now wait for cmd Complete
            err = i2cWaitForCmdComp( i_target,
                                     i_args );

            if( err )
            {
                TRACFCOMP( g_trac_i2c,
                           "i2cSendSlaveStop() committing log from i2cWaitForCmdComp on port %d",
                           port );
                // We still need to send the slave stop to the other ports
                // on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

        } // end of port for-loop

    } while( 0 );

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cSendSlaveStop()" );

    return err;
} // end i2cSendSlaveStop


// ------------------------------------------------------------------
// i2cGetInterrupts
// ------------------------------------------------------------------
errlHndl_t i2cGetInterrupts ( TARGETING::Target * i_target,
                              misc_args_t & i_args,
                              uint64_t & o_intRegValue )
{
    errlHndl_t err = nullptr;

    // Master Regs
    interrupt_reg_t intreg;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cGetInterrupts()" );

    do
    {
        intreg.value = 0x0;

        err = i2cRegisterOp( DeviceFW::READ,
                             i_target,
                             &intreg.value,
                             I2C_REG_INTERRUPT,
                             i_args );
        if( err )
        {
            break;
        }

        TRACUCOMP(g_trac_i2c,"i2cGetInterrupts(): "
                  "interrupt: 0x%016llx",
                  intreg.value );

        // Return the data read
        o_intRegValue = intreg.value;
    } while( 0 );

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cGetInterrupts( int reg val: %016llx)",
               o_intRegValue );

    return err;
} // end i2cGetInterrupts

#define I2C_CALCULATE_BRD( i_clockSpeed ) ( i_clockSpeed / 37 )
// #define BRD_1024 = ( ( nest_freq / ( 16 * 1024 * KILOBYTE ) ) - 1 ) / 4;

// ------------------------------------------------------------------
//  i2cSetBusVariables
// ------------------------------------------------------------------
errlHndl_t i2cSetBusVariables ( TARGETING::Target * i_target,
                                uint64_t i_speed,
                                misc_args_t & io_args)
{
    errlHndl_t err = nullptr;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetBusVariables(): i_speed=%d",
               i_speed );

    do
    {
        if ( i_speed == I2C_BUS_SPEED_FROM_MRW )
        {
            // Read data from attributes set by MRW
            TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speed_array;

            if (
                ( !( i_target->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
                                          (speed_array) ) )   ||
                ( io_args.engine >= I2C_BUS_ATTR_MAX_ENGINE ) ||
                ( io_args.port   >= I2C_BUS_ATTR_MAX_PORT )
               )
            {
                // Default to 400KHz
                TRACFCOMP( g_trac_i2c, ERR_MRK"i2cSetBusVariables: "
                           "unable to get TARGETING::ATTR_I2C_BUS_SPEED_ARRAY "
                           "or invalid engine(%d)/port(%d) combo. "
                           "Defaulting to 400KHz.",
                           io_args.engine, io_args.port);
                io_args.bus_speed = I2C_BUS_SPEED_400KHZ;
            }
            else
            {
                // All bus speed computations must be based off of the logical
                // engine/port mapping
                size_t logicalEngine = io_args.engine;
                size_t logicalPort = io_args.port;
                if (io_args.switches.useFsiI2C)
                {
                    setLogicalFsiEnginePort(logicalEngine,logicalPort);
                }

                io_args.bus_speed = speed_array[logicalEngine][logicalPort];

                assert(io_args.bus_speed,
                       "i2cSetBusVariables: bus speed for e%d/p%d (logical "
                       "e%d/p%d) driven by HUID 0x%08X is 0",
                       io_args.engine, io_args.port, logicalEngine, logicalPort,
                       TARGETING::get_huid(i_target));
            }
        }
        else
        {
            io_args.bus_speed = i_speed;
        }

        // Set other variables based off of io_args.bus_speed
        io_args.polling_interval_ns = i2cGetPollingInterval(io_args.bus_speed);
        io_args.timeout_count = I2C_TIMEOUT_COUNT(io_args.polling_interval_ns);

        // The Bit-Rate-Divisor set in the I2C Master mode register needs
        // to know the frequency of the "local bus" serving as a reflock
        // for the I2C Master
        uint64_t local_bus_MHZ = 0;

        if ( io_args.switches.useFsiI2C == 1 )
        {
            // For FSI I2C we should use the FSI clock
            local_bus_MHZ = FSI_BUS_SPEED_MHZ;
        }
        else
        {
            // For Host I2C use Nest Frequency as base

            TARGETING::Target* pSys = nullptr;
            TARGETING::targetService().getTopLevelTarget(pSys);
            assert(pSys != nullptr, "System target was nullptr");

            // PIB_CLK = ATTR_FREQ_PAU_MHZ / 4
            const uint64_t pib_clk =
              pSys->getAttr<TARGETING::ATTR_FREQ_PAU_MHZ>() / 4;

            // P10 has a by-2 internal divider to get from the PIB clock to the
            // local buz frequency
            local_bus_MHZ = pib_clk / 2;
        }

        io_args.bit_rate_divisor = i2cGetBitRateDivisor(io_args.bus_speed,
                                                        local_bus_MHZ);

    } while( 0 );

    TRACUCOMP(g_trac_i2c,"i2cSetBusVariables(): tgt=0x%X, e/p/dA=%d/%d/0x%X: "
              "speed=%d: b_sp=%d, b_r_d=0x%x, p_i=%d, to_c = %d",
              TARGETING::get_huid(i_target),
              io_args.engine, io_args.port, io_args.devAddr,
              i_speed, io_args.bus_speed, io_args.bit_rate_divisor,
              io_args.polling_interval_ns, io_args.timeout_count);

    // Printing mux info separately, if combined, nothing is displayed
    if (io_args.i2cMuxPath)
    {
        char* l_muxPath = io_args.i2cMuxPath->toString();
        TRACUCOMP(g_trac_i2c, "i2cSetBusVariables(): muxSelector=0x%X, "
                  "muxPath=%s", io_args.i2cMuxBusSelector, l_muxPath);
        free(l_muxPath);
        l_muxPath = nullptr;
    }
    else
    {
        TRACUCOMP(g_trac_i2c, "i2cSetBusVariables(): muxSelector=0x%X, "
                  "muxPath=NULL", io_args.i2cMuxBusSelector);
    }

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetBusVariables()" );

    return err;
}

/**
 * @brief This function will handle everything required to process
 *        each I2C master engine based on the input argements.
 *        List of operations in the i2cProcessOperation internal enum.
 */
enum i2cProcessOperation
{
    I2C_OP_RESET   = 1,
    I2C_OP_SETUP   = 2,
};
errlHndl_t i2cProcessActiveMasters ( i2cProcessType      i_processType,
                                     i2cProcessOperation i_processOperation,
                                     uint64_t            i_busSpeed,
                                     bool                i_functional,
                                     i2cEngineSelect     i_engineSelect )
{
    errlHndl_t err = nullptr;
    bool error_found = false;
    bool mutex_success = false;
    mutex_t * engineLock = nullptr;
    bool mutex_needs_unlock = false;

    misc_args_t io_args;

    // I2C Bus Speed Array
    TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speed_array;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cProcessActiveMasters(): Type=0x%X "
               "Operation=%d Bus Speed=%d Functional=%d engineSelect=0x%.2X",
               i_processType, i_processOperation, i_busSpeed, i_functional,
               i_engineSelect );
    do
    {

        // Get list of Procs
        TARGETING::TargetHandleList procList;

        if ( i_processType & I2C_RANGE_PROC )
        {

            // Pass input parameter for function (true) or existing (false)
            TARGETING::getAllChips(procList,
                                   TARGETING::TYPE_PROC,
                                   i_functional);

            if( 0 == procList.size() )
            {
                TRACFCOMP(g_trac_i2c,INFO_MRK
                       "i2cProcessActiveMasters: No Processor chips found!");

            }

            TRACFCOMP( g_trac_i2c,
                     INFO_MRK"i2cProcessActiveMasters: I2C Master Procs: %d",
                     procList.size() );
        }

        // Combine lists into chipList
        TARGETING::TargetHandleList chipList;
        chipList.insert(chipList.end(), procList.begin(), procList.end());

        // Get the Master Proc Chip Target for comparisons later
        TARGETING::TargetService& tS = TARGETING::targetService();
        TARGETING::Target* masterProcChipTargetHandle = nullptr;
        err = tS.queryMasterProcChipTargetHandle(masterProcChipTargetHandle);

        assert((err == nullptr), "tS.queryMasterProcChipTargetHandle returned "
               "err for masterProcChipTargetHandle");

        // Process each chip/target
        for( size_t chip = 0; chip < chipList.size(); chip++ )
        {
            TARGETING::Target* tgt = chipList[chip];

            TRACUCOMP( g_trac_i2c,
                       INFO_MRK"i2cProcessActiveMasters: Loop for tgt=0x%X",
                       TARGETING::get_huid(tgt) );

            // Look up I2C Mode for the target
            io_args.switches.useHostI2C = 0;
            io_args.switches.useFsiI2C  = 0;
            i2cSetSwitches( tgt, io_args );

            // Compare mode with input parameter
            if ( !( i_processType & I2C_RANGE_HOST )
                 && ( io_args.switches.useHostI2C == 1 ) )
            {
                TRACUCOMP( g_trac_i2c,
                        INFO_MRK"i2cProcessActiveMasters: skipping tgt=0x%X "
                        "due to i_processType=%d, useHostI2C=%d",
                        TARGETING::get_huid(tgt), i_processType,
                        io_args.switches.useHostI2C );
                continue;
            }

            if ( !( i_processType & I2C_RANGE_FSI )
                 && ( io_args.switches.useFsiI2C == 1 ) )
            {
                TRACUCOMP( g_trac_i2c,
                       INFO_MRK"i2cProcessActiveMasters: skipping tgt=0x%X "
                       "due to i_processType=%d, useFsiI2C=%d",
                       TARGETING::get_huid(tgt), i_processType,
                       io_args.switches.useFsiI2C );
                continue;
            }


            // Get I2C Bus Speed Array attribute.  It will be used to
            // determine which engines have devices on them
            if ( !(tgt->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
                                           (speed_array) ) )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"i2cProcessActiveMasters: - Cannot find "
                           "ATTR_I2C_BUS_SPEED_ARRAY needed for operation");

                /*@
                 * @errortype
                 * @reasoncode     I2C_ATTRIBUTE_NOT_FOUND
                 * @severity       ERRORLOG_SEV_UNRECOVERABLE
                 * @moduleid       I2C_PROCESS_ACTIVE_MASTERS
                 * @userdata1      Target for the attribute
                 * @userdata2[0:31]  Operation
                 * @userdata2[32:64] Type
                 * @devdesc        ATTR_I2C_BUS_SPEED_ARRAY not found
                 * @custdesc       I2C configuration data missing
                 */
                err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        I2C_PROCESS_ACTIVE_MASTERS,
                                        I2C_ATTRIBUTE_NOT_FOUND,
                                        TARGETING::get_huid(tgt),
                                        TWO_UINT32_TO_UINT64(
                                            i_processOperation,
                                            i_processType),
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

                err->collectTrace( I2C_COMP_NAME, 256);

                // We still need to reset the other I2C engines
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            // if i_functional == false then all possible returned in chipList,
            // so need to check if each target is present
            // -- master target defaulted to present
            if ( ( i_functional == false ) &&
                 ( tgt != masterProcChipTargetHandle ) )
            {
                bool check = FSI::isSlavePresent(tgt);

                if ( check == false )
                {
                    TRACUCOMP( g_trac_i2c,INFO_MRK
                               "i2cProcessActiveMasters: skipping tgt=0x%X "
                               "due to FSI::isSlavePresent returned=%s (%d)",
                               TARGETING::get_huid(tgt),
                               check ? "true" : "false", check );
                    continue;
                }
                else
                {
                    TRACUCOMP( g_trac_i2c,INFO_MRK
                             "i2cProcessActiveMasters: keeping tgt=0x%X due "
                             "to FSI::isSlavePresent returned=%s (%d)",
                             TARGETING::get_huid(tgt),
                             check ? "true" : "false", check );
                }
            }

            for( uint8_t engine = 0;
                 engine < I2C_BUS_ATTR_MAX_ENGINE;
                 engine++ )
            {
                io_args.engine = engine;

                // Only reset engine 0 for FSI
                if ( (i_processOperation & I2C_OP_RESET ) &&
                     ( engine != FSI_ENGINE_A ) &&
                     (io_args.switches.useFsiI2C == 1) )
                {
                    TRACUCOMP( g_trac_i2c,INFO_MRK
                        "Only reset engine 0 for FSI");
                    continue;
                }

                // Only operate on selected engines
                if ( ! ( i2cEngineToEngineSelect(engine) & i_engineSelect ) )
                {
                    TRACFCOMP( g_trac_i2c,INFO_MRK
                        "Skipping engine %d because i_engineSelect=0x%.2X",
                        engine, i_engineSelect );
                    continue;
                }


                // Look for any device on this engine based on speed_array
                bool skip = true;
                size_t l_numPorts = I2C_BUS_ATTR_MAX_PORT;
                if (io_args.switches.useFsiI2C == 1)
                {
                    TRACUCOMP( g_trac_i2c,INFO_MRK
                      "Using FSI I2c, use numports: %d", FSI_MODE_MAX_PORT);
                    l_numPorts = FSI_MODE_MAX_PORT;
                }
                for ( size_t j = 0; j < l_numPorts; j++ )
                {
                    size_t logical_engine = engine;
                    size_t logical_port = j;
                    if (io_args.switches.useFsiI2C == 1)
                    {
                        setLogicalFsiEnginePort(logical_engine, logical_port);
                    }

                    if ( speed_array[logical_engine][logical_port] != 0 )
                    {
                        skip = false;
                        io_args.port = j; // use this port
                        break;
                    }
                }

                // PHYP wants all of the engines set regardless if hostboot
                // believes there is a device on the bus.
                if ( i_processOperation == I2C_OP_SETUP )
                {
                    skip = false;
                    io_args.port = 0;
                }

                if ( skip == true )
                {
                    TRACUCOMP( g_trac_i2c,INFO_MRK
                              "i2cProcessActiveMasters: no devices found on "
                              "tgt=0x%X engine=%d",
                              TARGETING::get_huid(tgt), engine );
                    continue;
                }
                else
                {
                    TRACFCOMP( g_trac_i2c,INFO_MRK
                             "i2cProcessActiveMasters: Reset/Setup tgt=0x%X "
                             "engine=%d",
                             TARGETING::get_huid(tgt), engine );
                }

                error_found = false;
                mutex_needs_unlock = false;

                // Get the mutex for the requested engine
                mutex_success = i2cGetEngineMutex( tgt,
                                                   io_args,
                                                   engineLock );


                if( !mutex_success )
                {
                    TRACUCOMP( g_trac_i2c,
                               ERR_MRK"Error in i2cProcessActiveMasters: "
                               "i2cGetEngineMutex() failed to get mutex. "
                               "skipping reset on tgt=0x%X engine =%d",
                               TARGETING::get_huid(tgt), engine );
                    continue;
                }

                // Lock on this engine
                TRACUCOMP( g_trac_i2c,
                       INFO_MRK"i2cProcessActiveMasters: Obtaining lock for "
                       "engine: %d", engine );
                recursive_mutex_lock( engineLock );
                mutex_needs_unlock = true;
                TRACUCOMP( g_trac_i2c,INFO_MRK
                           "i2cProcessActiveMasters: Locked on engine: %d",
                           engine );

                TRACUCOMP( g_trac_i2c,INFO_MRK
                           "i2cProcessActiveMasters: Setup/Reset "
                           "0x%X engine = %d",
                           TARGETING::get_huid(tgt), engine );

                // Setup Bus Speed
                err = i2cSetBusVariables ( tgt,
                                           i_busSpeed,
                                           io_args );
                if( err )
                {
                    error_found = true;

                    TRACFCOMP( g_trac_i2c,ERR_MRK
                               "i2cProcessActiveMasters: Error Setting Bus "
                               "Variables: tgt=0x%X engine=%d",
                               TARGETING::get_huid(tgt), engine );

                    // If we get error skip resetting this target, but still
                    // need to reset other I2C engines
                    errlCommit( err,
                                I2C_COMP_ID );

                    // Don't continue or break - need mutex unlock
                }

                // Now reset or setup the engine/bus
                if ( error_found == false )
                {
                    switch (i_processOperation)
                    {
                        case I2C_OP_RESET:
                        {

                            const i2c_reset_level reset_level = FORCE_UNLOCK_RESET;

                            TRACFCOMP( g_trac_i2c,INFO_MRK
                                  "i2cProcessActiveMasters: reset engine: %d, "
                                  "reset_level=%d",
                                  engine, reset_level );

                            err = i2cReset ( tgt, io_args,
                                             reset_level );
                            if( err )
                            {
                                TRACFCOMP( g_trac_i2c,ERR_MRK
                                   "i2cProcessActiveMasters: Error reseting "
                                   "tgt=0x%X, engine=%d",
                                   TARGETING::get_huid(tgt), engine);

                                // If we get errors on the reset, we still need
                                // to reset the other I2C engines
                                errlCommit( err,
                                    I2C_COMP_ID );

                                // Don't continue or break - need mutex unlock
                            }
                            break;
                        }



                        case I2C_OP_SETUP:
                        {
                            // Check that engine is in a good state - this
                            // function looks for errors and that all previous
                            // commands are complete
                            err = i2cWaitForCmdComp(tgt,
                                                    io_args );

                            if( err )
                            {
                                TRACFCOMP(g_trac_i2c, ERR_MRK
                                    "i2cProcessActiveMasters: Error from "
                                    "i2cWaitForCmdComp tgt=0x%X, engine=%d. "
                                    "Will reset",
                                    TARGETING::get_huid(tgt), engine);

                                // Reset to recover the engine
                                errlHndl_t err_reset = nullptr;
                                err_reset = i2cReset ( tgt, io_args,
                                            FORCE_UNLOCK_RESET);

                                if( err_reset )
                                {
                                    TRACFCOMP( g_trac_i2c,ERR_MRK
                                       "i2cProcessActiveMasters: Error reseting"
                                       " tgt=0x%X, engine=%d",
                                       TARGETING::get_huid(tgt), engine);


                                    // commit reset error and previous error
                                    // with the same plid
                                    err_reset->plid(err->plid());
                                    TRACFCOMP(g_trac_i2c,
                                        "i2cProcessActiveMasters: comitting err"
                                        "(eid=0x%X) and err_reset(eid=0x%X) "
                                        "with plid 0x%X",
                                        err->eid(), err_reset->eid(),
                                        err->plid());

                                    errlCommit( err_reset,
                                        I2C_COMP_ID );

                                    errlCommit( err,
                                        I2C_COMP_ID );

                                    // Don't continue or break-need mutex unlock
                                }
                                else
                                {
                                    // The reset recovered the engine, so
                                    // just delete the original error log
                                   TRACFCOMP(g_trac_i2c,
                                        "i2cProcessActiveMasters: Reset worked "
                                        "so deleting previous err "
                                        "eid=0x%X and plid=0x%X",
                                        err->eid(), err->plid());
                                    delete err;
                                    err = nullptr;
                                }
                            }

                            // Set Mode Register
                            mode_reg_t mode;
                            mode.value = 0x0;

                            TRACFCOMP( g_trac_i2c,INFO_MRK
                              "i2cProcessActiveMasters: setup engine: %d",
                              engine );

                            mode.bit_rate_div = io_args.bit_rate_divisor;

                            err = i2cRegisterOp( DeviceFW::WRITE,
                                                 tgt,
                                                 &mode.value,
                                                 I2C_REG_MODE,
                                                 io_args );
                            if( err )
                            {
                                TRACFCOMP( g_trac_i2c,
                                   ERR_MRK"i2cProcessActiveMasters:"
                                          " Error setting mode for"
                                          " Processor, engine: %d",
                                          engine );

                                // If we get errors on these reads,
                                // we still need to continue
                                // to program the I2C Bus Divisor for the rest
                                errlCommit( err,
                                        I2C_COMP_ID );
                            }
                            break;
                        }
                        default:
                            assert (0,"i2cProcessActiveMasters: "
                                      "invalid operation");
                     }
                }

                // Check if we need to unlock the mutex
                if ( mutex_needs_unlock == true )
                {
                    // Unlock
                    recursive_mutex_unlock( engineLock );
                    TRACUCOMP( g_trac_i2c,INFO_MRK
                              "i2cProcessActiveMasters: Unlocked engine: %d",
                              engine );
                }

            } // end for-loop engine

        } // end for-loop chip

    } while( 0 );

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cProcessActiveMasters(): err rc=0x%X, plid=0x%X",
               ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

    return err;
}

/**
 * @brief This function is a wrapper to the common routine to reset
 *        I2C engines selected based on the input argements.
 *        Set bus speed from the MRW value.
 */
errlHndl_t i2cResetActiveMasters ( i2cProcessType i_resetType,
                                   bool i_functional,
                                   i2cEngineSelect i_engineSelect )
{
    errlHndl_t err = nullptr;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cResetActiveMasters(): i2cProcessType=0x%X, "
               "i_functional=%d, i_engineSelect=0x%.2X",
               i_resetType, i_functional, i_engineSelect );

    err = i2cProcessActiveMasters (i_resetType,  // select engines
                                   I2C_OP_RESET, // reset engines
                                   I2C_BUS_SPEED_FROM_MRW,
                                   i_functional,
                                   i_engineSelect);

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cResetActiveMasters(): err rc=0x%X, plid=0x%X",
               ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

    return err;
}

/**
 * @brief This function is a wrapper to the common routine to setup
 *        I2C engines selected based on the input argements.
 *        Set bus speed 400KHZ for Phyp (and other payloads).
 */
errlHndl_t i2cSetupActiveMasters ( i2cProcessType i_setupType,
                                   bool i_functional )
{
    errlHndl_t err = nullptr;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetupActiveMasters(): i2cProcessType=0x%X, "
               "i_functional=%d",
               i_setupType, i_functional );

    err = i2cProcessActiveMasters (i_setupType,   // select engines
                                   I2C_OP_SETUP,  // setup engines
                                   I2C_BUS_SPEED_400KHZ,
                                   i_functional,
                                   I2C_ENGINE_SELECT_ALL);

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetupActiveMasters(): err rc=0x%X, plid=0x%X",
               ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

    return err;
}

// ------------------------------------------------------------------
//  i2cSetAccessMode
//   NOTE: currently just supporting I2C_SET_MODE_PROC_HOST
// ------------------------------------------------------------------
void i2cSetAccessMode( i2cSetAccessModeType i_setModeType )
{
    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetAccessMode(): %d", i_setModeType );

    TARGETING::I2cSwitches switches;

    bool mutex_success = false;
    mutex_t * engineLocks[I2C_BUS_ATTR_MAX_ENGINE];
    misc_args_t args;


    do
    {
        // Get list of targets
        TARGETING::TargetHandleList tgtList;

        // Support for I2C_SET_MODE_PROC_HOST
        TARGETING::getAllChips(tgtList,
                               TARGETING::TYPE_PROC,
                               true); // true: return functional targets

        if( 0 == tgtList.size() )
        {
            TRACFCOMP(g_trac_i2c,
                      INFO_MRK"i2cSetAccessMode: No Targets found!");
            break;
        }

        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"i2cSetAccessMode: Targets: %d",
                   tgtList.size() );

        // Initalize mutex array
        for ( size_t index = 0; index < I2C_BUS_ATTR_MAX_ENGINE; index++ )
        {
            engineLocks[index] = nullptr;
        }

        // Check and set each target
        for( size_t i = 0; i < tgtList.size(); i++ )
        {
            TARGETING::Target* tgt = tgtList[i];

            // Get the mutex for all engines
            for ( size_t engine = 0;
                  engine < I2C_BUS_ATTR_MAX_ENGINE;
                  engine++ )
            {
                args.engine = engine;
                engineLocks[engine] = nullptr;

                mutex_success = i2cGetEngineMutex( tgt,
                                                   args,
                                                   engineLocks[engine] );

                if( !mutex_success )
                {
                    TRACFCOMP( g_trac_i2c,ERR_MRK"i2cSetAccessMode: Error from "
                               "i2cGetEngineMutex() getting engine %d lock for "
                               "tgt=0x%X", engine, TARGETING::get_huid(tgt));
                    break;
                }

                // Lock on this engine
                TRACUCOMP( g_trac_i2c,
                           INFO_MRK"Obtaining lock for engine: %d",
                           args.engine );

                recursive_mutex_lock( engineLocks[engine] );

                TRACUCOMP( g_trac_i2c,
                           INFO_MRK"Locked on engine: %d",
                           args.engine );
            }

            if ( mutex_success )
            {
                // The target is locked so complete the operation
                switches = tgt->getAttr<TARGETING::ATTR_I2C_SWITCHES>();

                TRACUCOMP( g_trac_i2c,"i2cSetAccessMode: tgt=0x%X switches: "
                           "host=%d, fsi=%d",
                           TARGETING::get_huid(tgt), switches.useHostI2C,
                           switches.useFsiI2C);

                // Support for I2C_SET_MODE_PROC_HOST
                if ((switches.useHostI2C != 1) ||
                    (switches.useFsiI2C  != 0)   )
                {
                    switches.useHostI2C = 1;
                    switches.useFsiI2C  = 0;

                    tgt->setAttr<TARGETING::ATTR_I2C_SWITCHES>(switches);

                    TRACUCOMP( g_trac_i2c,"i2cSetAccessMode: tgt=0x%X "
                               "I2C_SWITCHES updated: host=%d, fsi=%d",
                               TARGETING::get_huid(tgt), switches.useHostI2C,
                               switches.useFsiI2C);
                }
            }

            // Unlock the engines
            for ( size_t engine = 0;
                  engine < I2C_BUS_ATTR_MAX_ENGINE;
                  engine++ )
            {
                args.engine = engine;
                if ( engineLocks[engine] != nullptr )
                {
                    recursive_mutex_unlock( engineLocks[engine] );
                    TRACUCOMP( g_trac_i2c,
                               INFO_MRK"Unlocked engine: %d",
                               args.engine );
                }
            }
        } // end of target for loop

    } while( 0 );

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetAccessMode");

    return;
}


// ------------------------------------------------------------------
//  i2cRegisterOp
// ------------------------------------------------------------------
errlHndl_t i2cRegisterOp ( DeviceFW::OperationType i_opType,
                       TARGETING::Target * i_target,
                       uint64_t * io_data_64,
                       i2c_reg_offset_t i_reg,
                       misc_args_t & i_args )
{
    errlHndl_t err = nullptr;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cRegisterOp()");

    uint64_t op_addr = 0x0;
    uint64_t op_size = 0x0; // in bytes

    do
    {
        // Calculate Register Address and data size based on access type
        if ( i_args.switches.useHostI2C == 1 )
        {
            op_addr = I2C_HOST_MASTER_BASE_ADDR + i_reg +
                        (i_args.engine * P10_ENGINE_SCOM_OFFSET);
            op_size=8;

            TRACUCOMP( g_trac_i2c,
                       "i2cRegisterOp() op_addr: 0x%lx  io_data_64: 0x%lx",op_addr, *io_data_64 );

            err = DeviceFW::deviceOp( i_opType,
                                      i_target,
                                      io_data_64,
                                      op_size,
                                      DEVICE_SCOM_ADDRESS(op_addr) );

        }

        else // i_args.switches.useFsiI2C == 1
        {
            // FSI addresses are at 1-byte offsets, so need to multiply the
            // i_reg offset by 4 since each I2C register is 4 bytes long.
            op_addr = I2C_FSI_MASTER_BASE_ADDR + ( i_reg * 4 );

            if ( i_reg == I2C_REG_FIFO )
            {
                // Only read/write 1 byte at a time for FIFO register
                op_size = 1;
            }
            else
            {
                op_size = 4;
            }

            // Read or Write, this command should have the data left-justfied
            err = DeviceFW::deviceOp( i_opType,
                                      i_target,
                                      io_data_64,
                                      op_size,
                                      DEVICE_FSI_ADDRESS(op_addr));

        }

        if ( err )
        {
            TRACFCOMP(g_trac_i2c,"i2cRegisterOp %s FAIL!: plid=0X%X, rc=0x%X "
                      "tgt=0x%X, reg=%d, addr=0x%.8X, "
                      "data=0x%.16X",
                      ( i_opType == DeviceFW::READ ) ? "read" : "write",
                      err->plid(),  err->reasonCode(),
                      TARGETING::get_huid(i_target),
                      i_reg, op_addr, (*io_data_64) );
        }

    } while( 0 );

    TRACUCOMP(g_trac_i2c,"i2cRegisterOp(%s): tgt=0x%X, h/f=%d/%d(%d) "
              "i_reg=%d, addr=0x%.8X, data=0x%.16X",
              ( i_opType == DeviceFW::READ ) ? "r" : "w",
              TARGETING::get_huid(i_target),
              i_args.switches.useHostI2C,
              i_args.switches.useFsiI2C, op_size,
              i_reg, op_addr, (*io_data_64) );

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cRegisterOp()" );

    return err;
}

/**
 * @brief Return a set of information related to each I2C master on
 *   the given target chip
 */
void getMasterInfo( const TARGETING::Target* i_chip,
                    std::list<MasterInfo_t>& o_info )
{
    TRACFCOMP(g_trac_i2c,"getMasterInfo(%.8X)",TARGETING::get_huid(i_chip));
    for( uint32_t engine = 0;
         engine < I2C_BUS_ATTR_MAX_ENGINE;
         engine++ )
    {
        MasterInfo_t info;

        //For P10, the base scom address for each i2c engine
        //can be computed by adding an offset of P10_ENGINE_SCOM_OFFSET each time
        info.scomAddr = 0x000A0000 + engine*P10_ENGINE_SCOM_OFFSET;
        info.engine = engine;
        info.freq = i2cGetNestFreq()*FREQ_CONVERSION::HZ_PER_MHZ;
        // PIB_CLK = NEST_FREQ /4
        // Local Bus = PIB_CLK / 2  [P10]
        info.freq = info.freq/8; //convert nest to local bus

        TRACFCOMP(g_trac_i2c,"getMasterInfo(%.8X): pushing back engine=%d, scomAddr=0x%X",TARGETING::get_huid(i_chip), engine, info.scomAddr);

        o_info.push_back(info);
    }
}


//******************************************************************************
// areI2cDevicesLogicallyEqual (std::unique equality comparison)
//******************************************************************************

bool areI2cDevicesLogicallyEqual(
     const DeviceInfo_t& i_lhs,
     const DeviceInfo_t& i_rhs)
{
    return    (i_lhs.masterChip == i_rhs.masterChip)
           && (i_lhs.engine == i_rhs.engine)
           && (i_lhs.masterPort == i_rhs.masterPort)
           && (i_lhs.addr == i_rhs.addr)
           && (i_lhs.slavePort == i_rhs.slavePort);
}

//******************************************************************************
// byI2cDeviceOrder (std::sort comparison function)
//******************************************************************************

bool byI2cDeviceOrder(
     const DeviceInfo_t& i_lhs,
     const DeviceInfo_t& i_rhs)
{
    bool lhsLogicallyBeforeRhs = (i_lhs.masterChip < i_rhs.masterChip);
    if(i_lhs.masterChip == i_rhs.masterChip)
    {
        lhsLogicallyBeforeRhs = (i_lhs.engine < i_rhs.engine);
        if(i_lhs.engine == i_rhs.engine)
        {
            lhsLogicallyBeforeRhs = (i_lhs.masterPort < i_rhs.masterPort);
            if(i_lhs.masterPort == i_rhs.masterPort)
            {
                lhsLogicallyBeforeRhs = (i_lhs.addr < i_rhs.addr);
                if(i_lhs.addr == i_rhs.addr)
                {
                    lhsLogicallyBeforeRhs = (i_lhs.slavePort < i_rhs.slavePort);
                }
            }
        }
    }
    return lhsLogicallyBeforeRhs;
}

//******************************************************************************
// removeI2CDeviceDuplicates
//******************************************************************************
void removeI2cDeviceDuplicates(std::vector<DeviceInfo_t>& io_deviceInfo)
{
    std::vector<DeviceInfo_t> l_unique_deviceInfo;

    // Begin by sorting the list
    // Order I2C devices by chip, engine, port, address, slave port
    std::sort(io_deviceInfo.begin(), io_deviceInfo.end(),
        byI2cDeviceOrder);

    // Build up new unique list (thus removing duplicates)
    if (io_deviceInfo.size() > 1)
    {
        auto currentItr = io_deviceInfo.begin();
        auto nextItr = currentItr + 1;

        do {
            if (nextItr != io_deviceInfo.end() && (currentItr != nullptr))
            {
                if (areI2cDevicesLogicallyEqual(*currentItr, *nextItr))
                {
                    // skip if first letter is ?, these are guessed defaults
                    if (currentItr->deviceLabel[0] == '?')
                    {
                        // don't save currentItr as it is a guessed default
                        currentItr = nextItr;
                    }
                }
                else
                {
                    // Save currentItr as nextItr isn't the same logical device
                    if (currentItr != nullptr)
                    {
                        l_unique_deviceInfo.push_back(*currentItr);
                    }
                    currentItr = nextItr;
                }
            }
            else
            {
                // Save currentItr if pointing at something valid
                if (currentItr != nullptr)
                {
                    l_unique_deviceInfo.push_back(*currentItr);
                    currentItr = nextItr;
                }
            }

            if (nextItr != io_deviceInfo.end())
            {
                ++nextItr;
            }

        } while (currentItr != io_deviceInfo.end());

        io_deviceInfo = l_unique_deviceInfo;
    }
}

/**
 * Retrieve some information about I2C devices that the Host
 * needs to know about
 */
void getDeviceInfo( TARGETING::Target* i_i2cMaster,
                    std::vector<DeviceInfo_t>& o_deviceInfo )
{
    TRACFCOMP(g_trac_i2c,"getDeviceInfo>>");

    TARGETING::TargetHandleList chipTargets;
    if(i_i2cMaster == nullptr)
    {
        // If no target specified, use every proc chip
        TARGETING::Target* pSys = nullptr;
        TARGETING::targetService().getTopLevelTarget(pSys);
        assert(pSys != nullptr,"System target was nullptr");

        TARGETING::PredicateCTM procChip(
            TARGETING::CLASS_CHIP,TARGETING::TYPE_PROC);

        TARGETING::targetService().getAssociated(
            chipTargets,
            pSys,
            TARGETING::TargetService::CHILD,
            TARGETING::TargetService::ALL,
            &procChip);
    }
    else
    {
        // Otherwise, use the input target
        chipTargets.push_back(i_i2cMaster);
    }

    for(auto pChipTarget : chipTargets)
    {
        // If target is a processor, find its upstream node
        TARGETING::Target* pProc = nullptr;
        if(pChipTarget->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC)
        {
            pProc = pChipTarget;
        }
        else
        {
            TARGETING::TargetHandleList affinityParentTargets;
            TARGETING::getParentAffinityTargets (
                affinityParentTargets,
                pChipTarget,
                TARGETING::CLASS_CHIP,
                TARGETING::TYPE_PROC,
                false);
            // Some Chips might not have an upstream processor
            if(affinityParentTargets.empty())
            {
                continue;
            }
            assert(affinityParentTargets.size() == 1,
                "Exactly one affinity parent expected, not %d",
                affinityParentTargets.size());
            pProc = affinityParentTargets[0];
        }
        auto assocProc = pProc->getAttr<TARGETING::ATTR_POSITION>();
        assert(assocProc <= UINT8_MAX,"Proc position exceeded max for uint8_t");

        TARGETING::TargetHandleList affinityParentTargets;
        TARGETING::getParentAffinityTargets (
            affinityParentTargets,
            pProc,
            TARGETING::CLASS_ENC,
            TARGETING::TYPE_NODE,
            false);
        assert(affinityParentTargets.size() == 1,
            "Exactly one affinity parent expected, not %d",
            affinityParentTargets.size());
        TARGETING::Target* pNode = affinityParentTargets[0];
        auto assocNode = pNode->getAttr<TARGETING::ATTR_ORDINAL_ID>();
        assert(assocNode <= UINT8_MAX,"Node position exceeded max for uint8_t");

        //Get list of all I2C Masters
        std::list<I2C::MasterInfo_t> l_i2cInfo;
        I2C::getMasterInfo( pChipTarget, l_i2cInfo );

        // Get all the EEPROMs
        std::list<EEPROM::EepromInfo_t> l_eepromInfo;
        EEPROM::getEEPROMs( l_eepromInfo );

        // Loop through i2c masters and push into o_deviceInfo all
        // the EEPROMs connected via i2c
        for(auto const& i2cm : l_i2cInfo)
        {
            TRACUCOMP(g_trac_i2c,"i2c loop - eng=%.8X", TARGETING::get_huid(pChipTarget));
            /* I2C Busses */
            std::list<EEPROM::EepromInfo_t>::iterator l_eep =
                l_eepromInfo.begin();
            while( l_eep != l_eepromInfo.end() )
            {
                // Skip non-i2c eeproms
                if ( l_eep->accessMethod !=
                     EEPROM::EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
                {
                    l_eep = l_eepromInfo.erase(l_eep);
                    continue;
                }

                TRACUCOMP(g_trac_i2c,"eeprom loop - eng=%.8X, port=%.8X", TARGETING::get_huid(l_eep->eepromAccess.i2cInfo.i2cMaster), l_eep->eepromAccess.i2cInfo.engine );
                DeviceInfo_t l_currentDI;

                //ignore the devices that aren't on the current target
                if( l_eep->eepromAccess.i2cInfo.i2cMaster != pChipTarget )
                {
                    TRACUCOMP(g_trac_i2c,"skipping unmatched i2c master");
                    l_eep = l_eepromInfo.erase(l_eep);
                    continue;
                }

                //skip the devices that are on a different engine
                else if( l_eep->eepromAccess.i2cInfo.engine != i2cm.engine)
                {
                    TRACUCOMP(g_trac_i2c,"skipping unmatched engine");
                    ++l_eep;
                    continue;
                }

                l_currentDI.assocNode = assocNode;
                l_currentDI.assocProc = assocProc;
                l_currentDI.masterChip = l_eep->eepromAccess.i2cInfo.i2cMaster;
                l_currentDI.engine = l_eep->eepromAccess.i2cInfo.engine;
                l_currentDI.masterPort = l_eep->eepromAccess.i2cInfo.port;
                l_currentDI.addr = l_eep->eepromAccess.i2cInfo.devAddr;
                l_currentDI.slavePort = 0xFF;
                l_currentDI.busFreqKhz = (l_eep->eepromAccess.i2cInfo.busFreq)
                    / FREQ_CONVERSION::HZ_PER_KHZ;
                l_currentDI.deviceType =
                    TARGETING::HDAT_I2C_DEVICE_TYPE_SEEPROM;

                // See i2c.C removeI2cDeviceDuplicates(...) If a
                // duplicate of this i2c device is found, the duplicate
                // without the "?" in the device label will be
                // kept in o_deviceInfo.
                strcpy(l_currentDI.deviceLabel, "?");

                TRACUCOMP(g_trac_i2c,"Adding addr=0x%X", l_eep->eepromAccess.i2cInfo.devAddr);
                o_deviceInfo.push_back(l_currentDI);
                l_eep = l_eepromInfo.erase(l_eep);
            } //end of eeprom iter

        } //end of i2cm

#if CONFIG_INCLUDE_XML_OPENPOWER

        TARGETING::ATTR_HDAT_I2C_ELEMENTS_type l_arrayLength = 0;
        auto present = pChipTarget->tryGetAttr<
            TARGETING::ATTR_HDAT_I2C_ELEMENTS>(l_arrayLength);
        if(!present || l_arrayLength == 0)
        {
            // The arrays are non-existent or empty
            continue;
        }

        // These checks ensure we don't try to read too many elements from any
        // of the arrays. We use assert() here because the values are
        // essentially constants, and any MRW change that violates these
        // constraints would crash on every IPL, so the changes couldn't pass
        // testing.

        assert(l_arrayLength < std::size(TARGETING::ATTR_HDAT_I2C_ADDR_type{}),
               "HDAT_I2C_ELEMENTS specifies more elements than HDAT_I2C_ADDR contains");
        assert(l_arrayLength < std::size(TARGETING::ATTR_HDAT_I2C_BUS_FREQ_type{}),
               "HDAT_I2C_ELEMENTS specifies more elements than HDAT_I2C_BUS_FREQ contains");
        assert(l_arrayLength < std::size(TARGETING::ATTR_HDAT_I2C_DEVICE_LABEL_type{}),
               "HDAT_I2C_ELEMENTS specifies more elements than HDAT_I2C_DEVICE_LABEL contains");
        assert(l_arrayLength < std::size(TARGETING::ATTR_HDAT_I2C_DEVICE_PURPOSE_type{}),
               "HDAT_I2C_ELEMENTS specifies more elements than HDAT_I2C_DEVICE_PURPOSE contains");
        assert(l_arrayLength < std::size(TARGETING::ATTR_HDAT_I2C_DEVICE_TYPE_type{}),
               "HDAT_I2C_ELEMENTS specifies more elements than HDAT_I2C_DEVICE_TYPE contains");
        assert(l_arrayLength < std::size(TARGETING::ATTR_HDAT_I2C_ENGINE_type{}),
               "HDAT_I2C_ELEMENTS specifies more elements than HDAT_I2C_ENGINE contains");
        assert(l_arrayLength < std::size(TARGETING::ATTR_HDAT_I2C_MASTER_PORT_type{}),
               "HDAT_I2C_ELEMENTS specifies more elements than HDAT_I2C_MASTER_PORT contains");
        assert(l_arrayLength < std::size(TARGETING::ATTR_HDAT_I2C_SLAVE_PORT_type{}),
               "HDAT_I2C_ELEMENTS specifies more elements than HDAT_I2C_SLAVE_PORT contains");

        // Assume all required attributes are present from this point
        TARGETING::ATTR_HDAT_I2C_ENGINE_type l_i2cEngine = {0};
        present = pChipTarget->tryGetAttr<TARGETING::ATTR_HDAT_I2C_ENGINE>(
            l_i2cEngine);
        assert(present,"Target 0x%08X does not have ATTR_HDAT_I2C_ENGINE "
            "attribute",TARGETING::get_huid(pChipTarget));

        TARGETING::ATTR_HDAT_I2C_MASTER_PORT_type l_i2cMasterPort = {0};
        present = pChipTarget->tryGetAttr<
            TARGETING::ATTR_HDAT_I2C_MASTER_PORT>(l_i2cMasterPort);
        assert(present,"Target 0x%08X does not have ATTR_HDAT_I2C_MASTER_PORT "
            "attribute",TARGETING::get_huid(pChipTarget));

        TARGETING::ATTR_HDAT_I2C_DEVICE_TYPE_type l_i2cDevType;
        memset(&l_i2cDevType,TARGETING::HDAT_I2C_DEVICE_TYPE_UNKNOWN,
               sizeof(l_i2cDevType));
        present = pChipTarget->tryGetAttr<
            TARGETING::ATTR_HDAT_I2C_DEVICE_TYPE>(l_i2cDevType);
        assert(present,"Target 0x%08X does not have ATTR_HDAT_I2C_DEVICE_TYPE "
            "attribute",TARGETING::get_huid(pChipTarget));

        TARGETING::ATTR_HDAT_I2C_ADDR_type l_i2cAddr = {0};
        present = pChipTarget->tryGetAttr<TARGETING::ATTR_HDAT_I2C_ADDR>(
            l_i2cAddr);
        assert(present,"Target 0x%08X does not have ATTR_HDAT_I2C_ADDR "
            "attribute",TARGETING::get_huid(pChipTarget));

        TARGETING::ATTR_HDAT_I2C_SLAVE_PORT_type l_i2cSlavePort = {0};
        present = pChipTarget->tryGetAttr<
            TARGETING::ATTR_HDAT_I2C_SLAVE_PORT>(l_i2cSlavePort);
        assert(present,"Target 0x%08X does not have ATTR_HDAT_I2C_SLAVE_PORT "
            "attribute",TARGETING::get_huid(pChipTarget));

        TARGETING::ATTR_HDAT_I2C_BUS_FREQ_type l_i2cBusFreq = {0};
        present = pChipTarget->tryGetAttr<TARGETING::ATTR_HDAT_I2C_BUS_FREQ>(
            l_i2cBusFreq);
        assert(present,"Target 0x%08X does not have ATTR_HDAT_I2C_BUS_FREQ "
            "attribute",TARGETING::get_huid(pChipTarget));

        TARGETING::ATTR_HDAT_I2C_DEVICE_PURPOSE_type l_i2cDevPurpose;
        memset(&l_i2cDevPurpose,TARGETING::HDAT_I2C_DEVICE_PURPOSE_UNKNOWN,
               sizeof(l_i2cDevPurpose));
        present = pChipTarget->tryGetAttr<
            TARGETING::ATTR_HDAT_I2C_DEVICE_PURPOSE>(l_i2cDevPurpose);
        assert(present,"Target 0x%08X does not have "
            "ATTR_HDAT_I2C_DEVICE_PURPOSE attribute",
            TARGETING::get_huid(pChipTarget));

        TARGETING::ATTR_HDAT_I2C_DEVICE_LABEL_type l_i2cDevLabel;
        present = pChipTarget->tryGetAttr<
            TARGETING::ATTR_HDAT_I2C_DEVICE_LABEL>(l_i2cDevLabel);
        assert(present,"Target 0x%08X does not have ATTR_HDAT_I2C_DEVICE_LABEL "
            "attribute",TARGETING::get_huid(pChipTarget));

        for(TARGETING::ATTR_HDAT_I2C_ELEMENTS_type l_idx=0;
            l_idx < l_arrayLength;
            ++l_idx)
        {

            if(l_i2cAddr[l_idx] == UINT8_MAX)
            {
                continue;
            }

            DeviceInfo_t l_currentDevice = {nullptr};
            l_currentDevice.assocNode = assocNode;
            l_currentDevice.assocProc = assocProc;
            l_currentDevice.masterChip = pChipTarget;
            l_currentDevice.engine = l_i2cEngine[l_idx];
            l_currentDevice.masterPort = l_i2cMasterPort[l_idx];
            l_currentDevice.addr = l_i2cAddr[l_idx];
            l_currentDevice.slavePort = l_i2cSlavePort[l_idx];
            l_currentDevice.busFreqKhz = l_i2cBusFreq[l_idx]
                / FREQ_CONVERSION::HZ_PER_KHZ;
            l_currentDevice.deviceType =
                                static_cast<TARGETING::HDAT_I2C_DEVICE_TYPE>(
                                                        l_i2cDevType[l_idx]);
            l_currentDevice.devicePurpose =
                                static_cast<TARGETING::HDAT_I2C_DEVICE_PURPOSE>(
                                                        l_i2cDevPurpose[l_idx]);

            memcpy(l_currentDevice.deviceLabel, l_i2cDevLabel[l_idx],
                sizeof(l_currentDevice.deviceLabel));
            l_currentDevice.deviceLabel[sizeof(l_currentDevice.deviceLabel) - 1]
                = '\0';

            o_deviceInfo.push_back(l_currentDevice);
        }
#endif

    } //end of per chip loop

    // remove duplicates (also use deviceLabel from MRW, when possible)
    removeI2cDeviceDuplicates(o_deviceInfo);

    TRACFCOMP(g_trac_i2c,"<<getDeviceInfo");
    return;
}


/**
 * @brief Utility Function to capture error log user data consisting of
 *        the I2C Master Status Register and the I2C Master Target HUID
 */
uint64_t I2C_SET_USER_DATA_1 ( status_reg_t status_reg,
                               TARGETING::Target * tgt)
{
    return TWO_UINT32_TO_UINT64( TO_UINT32( status_reg.value >> 32),
                                 TARGETING::get_huid(tgt) );
}

/**
 * @brief Utility Function to capture error log user data consisting of
 *        the I2C variables relating to the I2C Master
 */
uint64_t I2C_SET_USER_DATA_2 ( misc_args_t args)
{

    return FOUR_UINT16_TO_UINT64(
                      TWO_UINT8_TO_UINT16 (args.engine, args.port),
                      args.devAddr & 0x000000000000FFFF,
                      args.bus_speed & 0x000000000000FFFF,
                      args.bit_rate_divisor );
}


void setLogicalFsiEnginePort(size_t &io_logical_engine, size_t &io_logical_port)
{
    // This is a NOOP for any engine except A
    if( io_logical_engine != 0 )
    {
        return;
    }

    /* Inclusive ranges:

       A0..A3 -> E0..E3
       A4..A5 -> C0..C1
       A6..A17 -> E4..E15
    */

    if (io_logical_port <= 3)
    {
        io_logical_engine = HOST_ENGINE_E;
    }
    else if (io_logical_port >= 6)
    {
        io_logical_engine = HOST_ENGINE_E;
        io_logical_port -= 2;
    }
    else
    {
        io_logical_engine = HOST_ENGINE_C;
        io_logical_port -= 4;
    }
}

void addHwCalloutsI2c(errlHndl_t i_err,
                      TARGETING::Target * i_target,
                      const misc_args_t & i_args)
{
    assert(i_err != nullptr, "Error log must not be nullptr");
    assert(i_target != nullptr, "i2cMaster target must not be nullptr.");

    if (!INITSERVICE::spBaseServicesEnabled())
    {
        i_err->addI2cDeviceCallout(i_target,
                                   i_args.engine,
                                   i_args.port,
                                   i_args.devAddr,
                                   HWAS::SRCI_PRIORITY_HIGH);
    }
    else
    {
        // For FSP systems which don't yet have special handling for i2c device
        // callouts we still need to handle the UCD search to avoid regression
        // back to the "non UCD aware" behavior.
        bool l_devFound = false;
        const auto l_physPath = i_target->getAttr<TARGETING::ATTR_PHYS_PATH>();

        // Loop thru the UCDs in the system and match physical path,
        // engine, and port to the i2c master.

        TARGETING::TargetHandleList allUcds;
        TARGETING::getAllChips(allUcds,
                               TARGETING::TYPE_POWER_SEQUENCER,
                               false);

        for(const auto &ucd: allUcds)
        {
            const auto l_ucdInfo = ucd->
                getAttr<TARGETING::ATTR_I2C_CONTROL_INFO>();

            if ((l_ucdInfo.i2cMasterPath == l_physPath) &&
                (l_ucdInfo.engine == i_args.engine) &&
                (l_ucdInfo.port == i_args.port) &&
                (l_ucdInfo.devAddr == i_args.devAddr))
            {
                TRACFCOMP(g_trac_i2c,
                          "Unresponsive UCD found: "
                          "Engine=%d, masterPort=%d, address=0x%X "
                          "huid for its i2c master is 0x%.8X",
                          l_ucdInfo.engine,
                          l_ucdInfo.port,
                          l_ucdInfo.devAddr,
                          TARGETING::get_huid(i_target));

                i_err->addHwCallout(ucd,
                                    HWAS::SRCI_PRIORITY_HIGH,
                                    HWAS::NO_DECONFIG,
                                    HWAS::GARD_NULL);

                l_devFound = true;
                break;
            }
        }

        // Could also be an issue with Processor or its bus
        // -- both on the same FRU
        i_err->addHwCallout(i_target,
                            l_devFound ?
                            HWAS::SRCI_PRIORITY_MED :
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::NO_DECONFIG,
                            HWAS::GARD_NULL);
    }
}

} // end namespace I2C
