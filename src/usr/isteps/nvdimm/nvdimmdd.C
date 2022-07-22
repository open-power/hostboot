/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimmdd.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
 * @file nvdimmdd.C
 *
 * @brief Implementation of the NVDIMM device driver,
 *      which will access various NVDIMMs within the
 *      system via the I2C device driver
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
#include <errl/errludstring.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/util.H>
#include <devicefw/driverif.H>
#include <eeprom/eepromif.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/i2cif.H>
#include <isteps/nvdimm/nvdimmreasoncodes.H>
#include <isteps/nvdimm/nvdimmif.H>
#include "nvdimmdd.H"
#include "nvdimm.H"
#include "errlud_nvdimm.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------
mutex_t g_nvdimmMutex = MUTEX_INITIALIZER;

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_nvdimmr = nullptr;
TRAC_INIT( & g_trac_nvdimmr, "NVDIMMR", KILOBYTE );


// Easy macro replace for unit testing
#define TRACUCOMP(args...)  TRACFCOMP(args)
//#define TRACUCOMP(args...)

// ----------------------------------------------
// Defines
// ----------------------------------------------
#define MAX_BYTE_ADDR 2
#define NVDIMM_MAX_RETRIES 2
// ----------------------------------------------


namespace
{

// ------------------------------------------------------------------
// errorIsRetryable
// ------------------------------------------------------------------
static bool errorIsRetryable(uint16_t reasonCode)
{
    return reasonCode == I2C::I2C_NACK_ONLY_FOUND ||
        reasonCode == I2C::I2C_ARBITRATION_LOST_ONLY_FOUND;
}

}

namespace NVDIMM
{

// Register the perform Op with the routing code for DIMMs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::NVDIMM,
                       TARGETING::TYPE_DIMM,
                       nvdimmPerformOp );

// ------------------------------------------------------------------
// nvdimmPerformOp
// ------------------------------------------------------------------
errlHndl_t nvdimmPerformOp( DeviceFW::OperationType i_opType,
                            TARGETING::Target * i_target,
                            void * io_buffer,
                            size_t & io_buflen,
                            int64_t i_accessType,
                            va_list i_args )
{
    errlHndl_t err = nullptr;
    TARGETING::Target * i2cMasterTarget = nullptr;
    nvdimm_addr_t i2cInfo;

    i2cInfo.offset = va_arg( i_args, uint64_t );

    TRACDCOMP( g_trac_nvdimm,
               ENTER_MRK"nvdimmPerformOp()" );

    TRACUCOMP (g_trac_nvdimm, ENTER_MRK"nvdimmPerformOp(): "
               "i_opType=%d, offset=%x, len=%d",
               (uint64_t) i_opType, i2cInfo.offset, io_buflen);

    void * l_pBuffer        = io_buffer;
    size_t l_currentOpLen   = io_buflen;
    size_t l_remainingOpLen = io_buflen;

    do
    {
        // Read Attributes needed to complete the operation
        err = nvdimmReadAttributes( i_target,
                                    i2cInfo );

        if( err )
        {
            break;
        }

        size_t l_snglChipSize = (i2cInfo.devSize_KB * KILOBYTE)
                                / i2cInfo.chipCount;

        // Check to see if we need to find a new target for
        // the I2C Master
        err = nvdimmGetI2CMasterTarget( i_target,
                                        i2cInfo,
                                        i2cMasterTarget );

        if( err )
        {
            break;
        }

        // Check that the offset + data length is less than device max size
        if ( ( i2cInfo.offset + io_buflen ) >
             ( i2cInfo.devSize_KB * KILOBYTE  ) )
        {
            TRACFCOMP( g_trac_nvdimm,
                       ERR_MRK"nvdimmPerformOp(): Device Overflow! "
                       "e/p/dA=%d/%d/0x%X, offset=0x%X, len=0x%X "
                       "devSizeKB=0x%X",
                       i2cInfo.engine, i2cInfo.port,
                       i2cInfo.devAddr, i2cInfo.offset, io_buflen,
                       i2cInfo.devSize_KB );

            // Printing mux info separately, if combined, nothing is displayed
            char* l_muxPath = i2cInfo.i2cMuxPath.toString();
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmPerformOp(): "
                      "muxSelector=0x%X, muxPath=%s",
                      i2cInfo.i2cMuxBusSelector,
                      l_muxPath);
            free(l_muxPath);
            l_muxPath = nullptr;

            /*@
             * @errortype
             * @reasoncode       NVDIMM_OVERFLOW_ERROR
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         NVDIMM_PERFORM_OP
             * @userdata1[0:31]  Offset
             * @userdata1[32:63] Buffer Length
             * @userdata2        Device Max Size (in KB)
             * @devdesc          I2C Buffer Length + Offset > Max Size
             * @custdesc         A problem occurred during the IPL of the
             *                   system: I2C buffer offset is too large.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           NVDIMM_PERFORM_OP,
                                           NVDIMM_OVERFLOW_ERROR,
                                           TWO_UINT32_TO_UINT64(
                                               i2cInfo.offset,
                                               io_buflen       ),
                                           i2cInfo.devSize_KB,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( NVDIMM_COMP_NAME );

            break;
        }

        // Keep first op length within a chip
        if( ( i2cInfo.offset + io_buflen ) > l_snglChipSize )
        {
            l_currentOpLen = l_snglChipSize - i2cInfo.offset;
        }

        TRACFCOMP( g_trac_nvdimm,
                   "nvdimmPerformOp():  i_opType=%d "
                   "e/p/dA=%d/%d/0x%X, offset=0x%X, len=0x%X, "
                   "snglChipKB=0x%X, chipCount=0x%X, devSizeKB=0x%X", i_opType,
                   i2cInfo.engine, i2cInfo.port, i2cInfo.devAddr,
                   i2cInfo.offset, io_buflen, l_snglChipSize,
                   i2cInfo.chipCount, i2cInfo.devSize_KB );

        // Printing mux info separately, if combined, nothing is displayed
        char* l_muxPath = i2cInfo.i2cMuxPath.toString();
        TRACFCOMP(g_trac_nvdimm, "nvdimmPerformOp(): "
                  "muxSelector=0x%X, muxPath=%s",
                  i2cInfo.i2cMuxBusSelector,
                  l_muxPath);
        free(l_muxPath);
        l_muxPath = nullptr;

        // Do the read or write
        while(l_remainingOpLen > 0)
        {
            if( i_opType == DeviceFW::READ )
            {
                err = nvdimmRead( i2cMasterTarget,
                                  l_pBuffer,
                                  l_currentOpLen,
                                  i2cInfo );
            }
            else if( i_opType == DeviceFW::WRITE )
            {
                err = nvdimmWrite( i2cMasterTarget,
                                   l_pBuffer,
                                   l_currentOpLen,
                                   i2cInfo );
            }
            else
            {
                TRACFCOMP( g_trac_nvdimm,
                           ERR_MRK"nvdimmPerformOp(): "
                           "Invalid NVDIMM Operation!");

                /*@
                 * @errortype
                 * @reasoncode     NVDIMM_INVALID_OPERATION
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       NVDIMM_PERFORM_OP
                 * @userdata1      Operation Type
                 * @userdata2      Chip to Access
                 * @devdesc        Invalid operation type.
                 * @custdesc       An internal firmware error occurred
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               NVDIMM_PERFORM_OP,
                                               NVDIMM_INVALID_OPERATION,
                                               i_opType,
                                               0,
                                               ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

                err->collectTrace( NVDIMM_COMP_NAME );
            }

            if ( err )
            {
                break;
            }

            // Adjust the buffer pointer and remaining op length
            l_pBuffer = (void *)(reinterpret_cast<uint64_t>(l_pBuffer)
                                 + l_currentOpLen);
            l_remainingOpLen -= l_currentOpLen;

            if( l_remainingOpLen > l_snglChipSize )
            {
                // Keep next op length within a chip
                l_currentOpLen = l_snglChipSize;
            }
            else if( l_remainingOpLen > 0 )
            {
                // Set next op length to what is left to do
                l_currentOpLen = l_remainingOpLen;
            }
            else
            {
                // Break if there is nothing left to do
                break;
            }

            // Prepare the address at the start of next NVDIMM
            i2cInfo.offset = 0;
            i2cInfo.devAddr += NVDIMM_DEVADDR_INC;
        } // Do the read or write
    } while( 0 );

    // If there is an error, add parameter info to log
    if ( err != nullptr )
    {
        NVDIMM::UdNvdimmParms( i_opType,
                               i_target,
                               io_buflen,
                               i2cInfo )
                             .addToLog(err);
    }

    TRACDCOMP( g_trac_nvdimm,
               EXIT_MRK"nvdimmPerformOp() - %s",
               ((nullptr == err) ? "No Error" : "With Error") );

    return err;
} // end nvdimmPerformOp

// ------------------------------------------------------------------
// crossesNvdimmPageBoundary
// ------------------------------------------------------------------
errlHndl_t crossesNvdimmPageBoundary( uint64_t i_offset,
                                      size_t i_buflen )
{

    TRACUCOMP(g_trac_nvdimm,
            ENTER_MRK"crossesNvdimmPageBoundary()");

    errlHndl_t err = nullptr;

    if(i_offset >= NVDIMM_PAGE_SIZE || (i_offset+i_buflen) >= NVDIMM_PAGE_SIZE)
    {
        TRACFCOMP( g_trac_nvdimm,
                   ERR_MRK"crossesNvdimmPageBoundary() - offset 0x%X, buflen 0x%X"
                   "crossed the page size boundary 0x%X",
                    i_offset, i_buflen, NVDIMM_PAGE_SIZE );

            /*@
             * @errortype
             * @reasoncode       NVDIMM_INVALID_OFFSET
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         NVDIMM_CROSSESNVDIMMPAGEBOUNDARY
             * @userdata1        Offset attempting to access
             * @userdata2        Requested buffer length
             * @devdesc          NVDIMM register offset out of bound
             * @custdesc         An internal firmware error occurred
             */
            err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                NVDIMM_CROSSESNVDIMMPAGEBOUNDARY,
                                NVDIMM_INVALID_OFFSET,
                                static_cast<uint64_t>(i_offset),
                                static_cast<uint64_t>(i_buflen));

            // Could be FSP or HB code's fault
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_MED);

            err->collectTrace( NVDIMM_COMP_NAME );

            return err;

    }

    TRACUCOMP(g_trac_nvdimm,
            EXIT_MRK"crossesNvdimmPageBoundary()");

    return err;
}

// ------------------------------------------------------------------
// nvdimmRead
// ------------------------------------------------------------------
errlHndl_t nvdimmRead ( TARGETING::Target * i_target,
                        void * o_buffer,
                        size_t i_buflen,
                        nvdimm_addr_t i_i2cInfo )
{
    errlHndl_t err = nullptr;
    uint8_t byteAddr[MAX_BYTE_ADDR];
    size_t byteAddrSize = 0;
    bool unlock = false;

    TRACUCOMP( g_trac_nvdimm,
               ENTER_MRK"nvdimmRead()" );

    do
    {
        TRACUCOMP( g_trac_nvdimmr,
                   "NVDIMM READ  START : Offset %.2X : Len %d",
                    i_i2cInfo.offset, i_buflen );


        // Check to see if the Read operation straddles the NVDIMM page
        // boundary
        err = crossesNvdimmPageBoundary( i_i2cInfo.offset, i_buflen );
        if( err )
        {
            TRACFCOMP(g_trac_nvdimm,
                    ERR_MRK"nvdimmRead()::crossesNvdimmPageBoundary()");
            break;
        }

        // Set addressing parameters
        err = nvdimmPrepareAddress( i_target,
                                    &byteAddr,
                                    byteAddrSize,
                                    i_i2cInfo);

        if( err )
        {
            TRACFCOMP(g_trac_nvdimm,
                    ERR_MRK"nvdimmRead()::nvdimmPrepareAddress()");
            break;
        }

        // Lock to sequence operations
        mutex_lock( &g_nvdimmMutex );
        unlock = true;

        // Read data from NV controller
        err = nvdimmReadData( i_target,
                              o_buffer,
                              i_buflen,
                              &byteAddr,
                              byteAddrSize,
                              i_i2cInfo );
        if( err )
        {
            TRACFCOMP(g_trac_nvdimm,
                    "Failed reading data: original read");
            break;
        }

        TRACUCOMP( g_trac_nvdimmr,
                   "NVDIMM READ  END   : Offset %.2X : Len %d : %016llx",
                   i_i2cInfo.offset, i_buflen, *((uint64_t*)o_buffer) );

    } while( 0 );

    if (unlock)
        mutex_unlock( & g_nvdimmMutex );

    TRACUCOMP( g_trac_nvdimm,
               EXIT_MRK"nvdimmRead()" );

    return err;
} // end nvdimmRead


// ------------------------------------------------------------------
// nvdimmReadData
// ------------------------------------------------------------------
errlHndl_t nvdimmReadData( TARGETING::Target * i_target,
                           void * o_buffer,
                           size_t i_buflen,
                           void * i_byteAddress,
                           size_t i_byteAddressSize,
                           nvdimm_addr_t i_i2cInfo )
{
    errlHndl_t l_err = nullptr;
    errlHndl_t err_retryable = nullptr;

    TRACUCOMP(g_trac_nvdimm,
            ENTER_MRK"nvdimmReadData()");
    do
    {
        /************************************************************/
        /* Attempt read multiple times ONLY on retryable fails      */
        /************************************************************/
        for (uint8_t retry = 0;
             retry <= NVDIMM_MAX_RETRIES;
             retry++)
        {
            // Only write the byte address if we have data to write
            if( 0 != i_byteAddressSize )
            {
                // Use the I2C OFFSET Interface for the READ
                l_err = deviceOp(DeviceFW::READ,
                                 i_target,
                                 o_buffer,
                                 i_buflen,
                                 DEVICE_I2C_ADDRESS_OFFSET(
                                  i_i2cInfo.port,
                                  i_i2cInfo.engine,
                                  i_i2cInfo.devAddr,
                                  i_byteAddressSize,
                                  reinterpret_cast<uint8_t*>(i_byteAddress),
                                  i_i2cInfo.i2cMuxBusSelector,
                                  &(i_i2cInfo.i2cMuxPath)));

                if( l_err )
                {
                    TRACFCOMP(g_trac_nvdimm,
                              ERR_MRK"nvdimmReadData(): I2C Read-Offset failed on "
                              "%d/%d/0x%X, aS=%d",
                              i_i2cInfo.port, i_i2cInfo.engine,
                              i_i2cInfo.devAddr,
                              i_byteAddressSize);

                    // Printing mux info separately, if combined, nothing is displayed
                    char* l_muxPath = i_i2cInfo.i2cMuxPath.toString();
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmReadData(): "
                              "muxSelector=0x%X, muxPath=%s",
                              i_i2cInfo.i2cMuxBusSelector,
                              l_muxPath);
                    free(l_muxPath);
                    l_muxPath = nullptr;

                    TRACFBIN(g_trac_nvdimm, "i_byteAddress[]",
                             i_byteAddress, i_byteAddressSize);

                    // Don't break here -- error handled below
                }
            }
            else
            {
                // Do the actual read via I2C
                l_err = deviceOp( DeviceFW::READ,
                                  i_target,
                                  o_buffer,
                                  i_buflen,
                                  DEVICE_I2C_ADDRESS(
                                                i_i2cInfo.port,
                                                i_i2cInfo.engine,
                                                i_i2cInfo.devAddr,
                                                i_i2cInfo.i2cMuxBusSelector,
                                                &(i_i2cInfo.i2cMuxPath) ) );

                if( l_err )
                {
                    TRACFCOMP(g_trac_nvdimm,
                              ERR_MRK"nvdimmReadData(): I2C Read failed on "
                              "%d/%d/0x%0X",
                              i_i2cInfo.port, i_i2cInfo.engine,
                              i_i2cInfo.devAddr );

                    // Printing mux info separately, if combined, nothing is displayed
                    char* l_muxPath = i_i2cInfo.i2cMuxPath.toString();
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmReadData(): "
                              "muxSelector=0x%X, muxPath=%s",
                              i_i2cInfo.i2cMuxBusSelector,
                              l_muxPath);
                    free(l_muxPath);
                    l_muxPath = nullptr;

                    // Don't break here -- error handled below
                }
            }

            if ( l_err == nullptr )
            {
                // Operation completed successfully
                // break from retry loop
                break;
            }
            else if ( !errorIsRetryable( l_err->reasonCode() ) )
            {
                // Only retry on errorIsRetryable() failures: break from retry loop
                TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimmReadData(): Non-Nack "
                           "Error: rc=0x%X, tgt=0x%X, No Retry (retry=%d)",
                            l_err->reasonCode(),
                            TARGETING::get_huid(i_target), retry);

                l_err->collectTrace(NVDIMM_COMP_NAME);

                // break from retry loop
                break;
            }
            else // Handle retryable error
            {
                // If op will be attempted again: save log and continue
                if ( retry < NVDIMM_MAX_RETRIES )
                {
                    // Only save original retryable error
                    if ( err_retryable == nullptr )
                    {
                        // Save original retryable error
                        err_retryable = l_err;

                        TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimmReadData(): "
                                   "Retryable Error rc=0x%X, eid=0x%X, tgt=0x%X, "
                                   "retry/MAX=%d/%d. Save error and retry",
                                   err_retryable->reasonCode(),
                                   err_retryable->eid(),
                                   TARGETING::get_huid(i_target),
                                   retry, NVDIMM_MAX_RETRIES);

                        err_retryable->collectTrace(NVDIMM_COMP_NAME);
                    }
                    else
                    {
                        // Add data to original retryable error
                        TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimmReadData(): "
                                   "Another Retryable Error rc=0x%X, eid=0x%X "
                                   "plid=0x%X, tgt=0x%X, retry/MAX=%d/%d. "
                                   "Delete error and retry",
                                   l_err->reasonCode(), l_err->eid(), l_err->plid(),
                                   TARGETING::get_huid(i_target),
                                   retry, NVDIMM_MAX_RETRIES);

                        ERRORLOG::ErrlUserDetailsString(
                                  "Another Retryable ERROR found")
                                  .addToLog(err_retryable);

                        // Delete this new retryable error
                        delete l_err;
                        l_err = nullptr;
                    }

                    // continue to retry
                    continue;
                }
                else // no more retries: trace and break
                {
                    TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimmReadData(): "
                               "Error rc=0x%X, eid=%d, tgt=0x%X. No More "
                               "Retries (retry/MAX=%d/%d). Returning Error",
                               l_err->reasonCode(), l_err->eid(),
                               TARGETING::get_huid(i_target),
                               retry, NVDIMM_MAX_RETRIES);

                    l_err->collectTrace(NVDIMM_COMP_NAME);

                    // break from retry loop
                    break;
                }
            }

        } // end of retry loop

        // Handle saved retryable error, if any
        if (err_retryable)
        {
            if (l_err)
            {
                // commit original retryable error with new err PLID
                err_retryable->plid(l_err->plid());
                TRACFCOMP(g_trac_nvdimm, "nvdimmReadData(): Committing saved retryable "
                          "l_err eid=0x%X with plid of returned err: 0x%X",
                          err_retryable->eid(), err_retryable->plid());

                ERRORLOG::ErrlUserDetailsTarget(i_target)
                                               .addToLog(err_retryable);

                errlCommit(err_retryable, NVDIMM_COMP_ID);
            }
            else
            {
                // Since we eventually succeeded, delete original retryable error
                TRACFCOMP(g_trac_nvdimm, "nvdimmReadData(): Op successful, "
                          "deleting saved retryable err eid=0x%X, plid=0x%X",
                          err_retryable->eid(), err_retryable->plid());

                delete err_retryable;
                err_retryable = nullptr;
            }
        }

    }while( 0 );

    TRACUCOMP(g_trac_nvdimm,
            EXIT_MRK"nvdimmReadData");
    return l_err;
}



// ------------------------------------------------------------------
// nvdimmWrite
// ------------------------------------------------------------------
errlHndl_t nvdimmWrite ( TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         nvdimm_addr_t i_i2cInfo )
{
    errlHndl_t err = nullptr;
    uint8_t byteAddr[MAX_BYTE_ADDR];
    size_t byteAddrSize = 0;
    uint8_t * newBuffer = nullptr;
    bool needFree = false;
    uint32_t data_left = 0;
    uint32_t diff_wps = 0;

    TRACDCOMP( g_trac_nvdimm,
               ENTER_MRK"nvdimmWrite()" );

    do
    {
        TRACUCOMP( g_trac_nvdimm,
                   "NVDIMM WRITE START : Offset %.2X : Len %d : %016llx",
                   i_i2cInfo.offset, io_buflen, *((uint64_t*)io_buffer) );


        // Prepare address parameters
        err = nvdimmPrepareAddress( i_target,
                                    &byteAddr,
                                    byteAddrSize,
                                    i_i2cInfo);

        if( err )
        {
            TRACFCOMP(g_trac_nvdimm,
                    ERR_MRK"nvdimmWrite()::nvdimmPrepareAddress()");
            break;
        }

        // Check for writePageSize of zero
        if ( i_i2cInfo.writePageSize == 0 )
        {
            TRACFCOMP( g_trac_nvdimm,
                       ERR_MRK"nvdimmWrite(): writePageSize is 0!");

            /*@
             * @errortype
             * @reasoncode     NVDIMM_I2C_WRITE_PAGE_SIZE_ZERO
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       NVDIMM_WRITE
             * @userdata1      HUID of target
             * @devdesc        I2C write page size is zero.
             * @custdesc       An internal firmware error occurred
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           NVDIMM_WRITE,
                                           NVDIMM_I2C_WRITE_PAGE_SIZE_ZERO,
                                           TARGETING::get_huid(i_target),
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( NVDIMM_COMP_NAME );

            break;
        }

        // Make sure offset and buffer length are within NVDIMM page boundary
        err = crossesNvdimmPageBoundary( i_i2cInfo.offset,
                                   io_buflen );
        if( err )
        {
            TRACFCOMP(g_trac_nvdimm,
                    ERR_MRK"nvdimmWrite()::crossesNvdimmPageBoundary()");
            break;
        }

        // NVDIMM devices have write page boundaries, so when necessary
        // need to split up command into multiple write operations

        // Setup a max-size buffer of writePageSize
        size_t newBufLen = i_i2cInfo.writePageSize;
        newBuffer = static_cast<uint8_t*>(malloc( newBufLen ));
        needFree = true;

        // Point a uint8_t ptr at io_buffer for array addressing below
        uint8_t * l_data_ptr = reinterpret_cast<uint8_t*>(io_buffer);

        // Lock for operation sequencing
        mutex_lock( &g_nvdimmMutex );

        // variables to store different amount of data length
        size_t total_bytes_written = 0;

        while( total_bytes_written < io_buflen )
        {
            // Determine how much data can be written in this loop
            // Can't go over a writePageSize boundary

            // Total data left to write
            data_left = io_buflen - total_bytes_written;

            // Difference to next writePageSize boundary
            diff_wps = i_i2cInfo.writePageSize -
                                (i_i2cInfo.offset % i_i2cInfo.writePageSize);

            // Add the data the user wanted to write
            memcpy( newBuffer,
                    &l_data_ptr[total_bytes_written],
                    newBufLen );

            // Setup offset/address parms
            err = nvdimmPrepareAddress( i_target,
                                        &byteAddr,
                                        byteAddrSize,
                                        i_i2cInfo );

            if( err )
            {
                TRACFCOMP(g_trac_nvdimm,
                         ERR_MRK"nvdimmWrite::nvdimmPrepareAddress()::loop version");
                break;
            }

            TRACUCOMP(g_trac_nvdimm,"nvdimmWrite() Loop: %d/%d/0x%X "
                "writeBuflen=%d, offset=0x%X, "
                "bAS=%d, diffs=%d/%d",
                i_i2cInfo.port, i_i2cInfo.engine, i_i2cInfo.devAddr,
                newBufLen, i_i2cInfo.offset, byteAddrSize,
                data_left, diff_wps);

            // Printing mux info separately, if combined, nothing is displayed
            char* l_muxPath = i_i2cInfo.i2cMuxPath.toString();
            TRACFCOMP(g_trac_nvdimm, "nvdimmWrite(): "
                      "muxSelector=0x%X, muxPath=%s",
                      i_i2cInfo.i2cMuxBusSelector,
                      l_muxPath);
            free(l_muxPath);
            l_muxPath = nullptr;

            // Perform the requested write operation
            err = nvdimmWriteData( i_target,
                                   newBuffer,
                                   newBufLen,
                                   &byteAddr,
                                   byteAddrSize,
                                   i_i2cInfo );

            if ( err )
            {
                // Can't assume that anything was written if
                // there was an error, so no update to total_bytes_written
                // for this loop
                TRACFCOMP(g_trac_nvdimm,
                         "Failed writing data: original nvdimm write");
                break;
            }

            // Wait for NVDIMM to write data to its internal memory
            // i_i2cInfo.writeCycleTime value in milliseconds
            //nanosleep( 0, i_i2cInfo.writeCycleTime * NS_PER_MSEC );
            nanosleep( 0, 10000 );  // 10 microseconds (needed for nvdimm update)

            // Update how much data was written
            total_bytes_written += newBufLen;

            // Update offset
            i_i2cInfo.offset += newBufLen;

            TRACUCOMP(g_trac_nvdimm,"nvdimmWrite() Loop End: "
                      "writeBuflen=%d, offset=0x%X, t_b_w=%d, io_buflen=%d",
                       newBufLen, i_i2cInfo.offset,
                      total_bytes_written, io_buflen);
        } // end of write for-loop

        // Release mutex lock
        mutex_unlock( &g_nvdimmMutex );

        // Set how much data was actually written
        io_buflen = total_bytes_written;


        TRACSCOMP( g_trac_nvdimmr,
                   "NVDIMM WRITE END   : Offset %.2X : Len %d",
                   i_i2cInfo.offset, io_buflen );
    } while( 0 );

    // Free memory
    if( needFree )
    {
        free( newBuffer );
    }

    TRACDCOMP( g_trac_nvdimm,
               EXIT_MRK"nvdimmWrite()" );

    return err;

} // end nvdimmWrite

// ------------------------------------------------------------------
// nvdimmWriteData
// ------------------------------------------------------------------
errlHndl_t nvdimmWriteData( TARGETING::Target * i_target,
                            void * i_dataToWrite,
                            size_t i_dataLen,
                            void * i_byteAddress,
                            size_t i_byteAddressSize,
                            nvdimm_addr_t i_i2cInfo )
{
    TRACDCOMP( g_trac_nvdimm,
               ENTER_MRK"nvdimmWriteData()");
    errlHndl_t err = nullptr;
    errlHndl_t err_retryable = nullptr;
    do
    {
         /***********************************************************/
         /* Attempt write multiple times ONLY on retryable fails    */
         /***********************************************************/
        for (uint8_t retry = 0;
              retry <= NVDIMM_MAX_RETRIES;
              retry++)
         {
            // Do the actual data write
            err = deviceOp( DeviceFW::WRITE,
                            i_target,
                            i_dataToWrite,
                            i_dataLen,
                            DEVICE_I2C_ADDRESS_OFFSET(
                                        i_i2cInfo.port,
                                        i_i2cInfo.engine,
                                        i_i2cInfo.devAddr,
                                        i_byteAddressSize,
                                        reinterpret_cast<uint8_t*>(
                                        i_byteAddress),
                                        i_i2cInfo.i2cMuxBusSelector,
                                        &(i_i2cInfo.i2cMuxPath) ));

             if ( err == nullptr )
             {
                 // Operation completed successfully
                 // break from retry loop
                 break;
             }
             else if ( !errorIsRetryable( err->reasonCode() ) )
             {
                 // Only retry on errorIsRetryable() failures: break from retry loop
                 TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmWriteData(): I2C "
                           "Write Non-Retryable fail %d/%d/0x%X, "
                           "ldl=%d, offset=0x%X, aS=%d, retry=%d",
                           i_i2cInfo.port, i_i2cInfo.engine,
                           i_i2cInfo.devAddr, i_dataLen,
                           i_i2cInfo.offset, i_i2cInfo.addrSize, retry);

                 // Printing mux info separately, if combined, nothing is displayed
                 char* l_muxPath = i_i2cInfo.i2cMuxPath.toString();
                 TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmWriteData(): "
                           "muxSelector=0x%X, muxPath=%s",
                           i_i2cInfo.i2cMuxBusSelector,
                           l_muxPath);
                 free(l_muxPath);
                 l_muxPath = nullptr;

                 err->collectTrace(NVDIMM_COMP_NAME);

                 // break from retry loop
                 break;
             }
             else // Handle retryable error
             {
                 TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmWriteData(): I2C "
                           "Write retryable fail %d/%d/0x%X, "
                           "ldl=%d, offset=0x%X, aS=%d, writePageSize = %x",
                           i_i2cInfo.port, i_i2cInfo.engine,
                           i_i2cInfo.devAddr, i_dataLen,
                           i_i2cInfo.offset, i_i2cInfo.addrSize,
                           i_i2cInfo.writePageSize);

                 // Printing mux info separately, if combined, nothing is displayed
                 char* l_muxPath = i_i2cInfo.i2cMuxPath.toString();
                 TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmWriteData(): "
                           "muxSelector=0x%X, muxPath=%s",
                           i_i2cInfo.i2cMuxBusSelector,
                           l_muxPath);
                 free(l_muxPath);
                 l_muxPath = nullptr;

                 // If op will be attempted again: save error and continue
                 if ( retry < NVDIMM_MAX_RETRIES )
                 {
                     // Only save original retryable error
                     if ( err_retryable == nullptr )
                     {
                         // Save original retryable error
                         err_retryable = err;

                         TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimmWriteData(): "
                                    "Error rc=0x%X, eid=0x%X plid=0x%X, "
                                    "tgt=0x%X, retry/MAX=%d/%d. Save error "
                                    "and retry",
                                    err_retryable->reasonCode(),
                                    err_retryable->eid(),
                                    err_retryable->plid(),
                                    TARGETING::get_huid(i_target),
                                    retry, NVDIMM_MAX_RETRIES);

                         err_retryable->collectTrace(NVDIMM_COMP_NAME);
                     }
                     else
                     {
                         // Add data to original retryable error
                         TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimmWriteData(): "
                                    "Another Retryable Error rc=0x%X, eid=0x%X "
                                    "plid=0x%X, tgt=0x%X, retry/MAX=%d/%d. "
                                    "Delete error and retry",
                                    err->reasonCode(), err->eid(),
                                    err->plid(),
                                    TARGETING::get_huid(i_target),
                                    retry, NVDIMM_MAX_RETRIES);

                         ERRORLOG::ErrlUserDetailsString(
                                   "Another retryable ERROR found")
                                   .addToLog(err_retryable);

                         // Delete this new retryable error
                         delete err;
                         err = nullptr;
                     }

                     // continue to retry
                     continue;
                 }
                 else // no more retries: trace and break
                 {
                     TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimmWriteData(): "
                                "Error rc=0x%X, tgt=0x%X. No More Retries "
                                "(retry/MAX=%d/%d). Returning Error",
                                err->reasonCode(),
                                TARGETING::get_huid(i_target),
                                retry, NVDIMM_MAX_RETRIES);

                     err->collectTrace(NVDIMM_COMP_NAME);

                     // break from retry loop
                     break;
                 }
             }

         } // end of retry loop
         /***********************************************************/

         // Handle saved retryable errors, if any
         if (err_retryable)
         {
             if (err)
             {
                 // commit original retryable error with new err PLID
                 err_retryable->plid(err->plid());
                 TRACFCOMP(g_trac_nvdimm, "nvdimmWriteData(): Committing saved "
                           "retryable err eid=0x%X with plid of returned err: "
                           "0x%X",
                           err_retryable->eid(), err_retryable->plid());

                 ERRORLOG::ErrlUserDetailsTarget(i_target)
                                                 .addToLog(err_retryable);

                 errlCommit(err_retryable, NVDIMM_COMP_ID);
             }
             else
             {
                 // Since we eventually succeeded, delete original retryable error
                 TRACFCOMP(g_trac_nvdimm, "nvdimmWriteData(): Op successful, "
                           "deleting saved retryable err eid=0x%X, plid=0x%X",
                           err_retryable->eid(), err_retryable->plid());

                 delete err_retryable;
                 err_retryable = nullptr;
             }
         }
    }while( 0 );
    TRACDCOMP( g_trac_nvdimm,
            EXIT_MRK"nvdimmWriteData()");
    return err;
}



// ------------------------------------------------------------------
// nvdimmPrepareAddress
// ------------------------------------------------------------------
errlHndl_t nvdimmPrepareAddress ( TARGETING::Target * i_target,
                                  void * io_buffer,
                                  size_t & o_bufSize,
                                  nvdimm_addr_t i_i2cInfo )
{
    errlHndl_t err = nullptr;
    o_bufSize = 0;

    TRACDCOMP( g_trac_nvdimm,
               ENTER_MRK"nvdimmPrepareAddress()" );

    // NV Controller only supports ONE_BYTE_ADDR
    // Throw an error if it's something else
    if ( i_i2cInfo.addrSize == ONE_BYTE_ADDR)
    {
        o_bufSize = 1;
        memset( io_buffer, 0x0, o_bufSize );
        *((uint8_t*)io_buffer) = (i_i2cInfo.offset & 0xFFull);
    }
    else
    {

        TRACFCOMP( g_trac_nvdimm,
                   ERR_MRK"nvdimmPrepareAddress() - Invalid Device "
                   "Address Size: 0x%08x", i_i2cInfo.addrSize);

        /*@
         * @errortype
         * @reasoncode       NVDIMM_INVALID_DEVICE_TYPE
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         NVDIMM_PREPAREADDRESS
         * @userdata1        Address Size (aka Device Type)
         * @devdesc          The Device type not supported (addrSize)
         * @custdesc         A problem was detected during the IPL of
         *                   the system: Device type not supported.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       NVDIMM_PREPAREADDRESS,
                                       NVDIMM_INVALID_DEVICE_TYPE,
                                       i_i2cInfo.addrSize,
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        err->collectTrace( NVDIMM_COMP_NAME );
    }

    TRACDCOMP( g_trac_nvdimm,
               EXIT_MRK"nvdimmPrepareAddress()" );

    return err;
} // end nvdimmPrepareAddress


// ------------------------------------------------------------------
// nvdimmReadAttributes
// ------------------------------------------------------------------
errlHndl_t nvdimmReadAttributes ( TARGETING::Target * i_target,
                                  nvdimm_addr_t & o_i2cInfo )
{
    errlHndl_t err = nullptr;

    TRACDCOMP( g_trac_nvdimm,
               ENTER_MRK"nvdimmReadAttributes()" );

    // These variables will be used to hold the NVDIMM attribute data
    // 'EepromNvInfo' struct is kept the same as nvdimm_addr_t via the
    // attributes.
    TARGETING::EepromNvInfo nvdimmData;

    if(!(i_target->tryGetAttr<TARGETING::ATTR_EEPROM_NV_INFO>
                ( reinterpret_cast<TARGETING::ATTR_EEPROM_NV_INFO_type&>( nvdimmData) )))
    {
        TRACFCOMP( g_trac_nvdimm,
                   ERR_MRK"nvdimmReadAttributes() - ERROR reading "
                   "attributes for tgt=0x%X",
                   TARGETING::get_huid(i_target) );

            /*@
             * @errortype
             * @reasoncode       NVDIMM_ATTR_INFO_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         NVDIMM_READATTRIBUTES
             * @userdata1        HUID of target
             * @devdesc          NVDIMM attribute was not found
             * @custdesc         An internal firmware error occurred
             */
            err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                NVDIMM_READATTRIBUTES,
                                NVDIMM_ATTR_INFO_NOT_FOUND,
                                TARGETING::get_huid(i_target));

            // Could be FSP or HB code's fault
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_MED);
            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_MED);

            err->collectTrace( NVDIMM_COMP_NAME );

            return err;

    }

    // Successful reading of Attribute, so extract the data
    o_i2cInfo.port           = nvdimmData.port;
    o_i2cInfo.devAddr        = nvdimmData.devAddr;
    o_i2cInfo.engine         = nvdimmData.engine;
    o_i2cInfo.i2cMasterPath  = nvdimmData.i2cMasterPath;
    o_i2cInfo.writePageSize  = nvdimmData.writePageSize;
    o_i2cInfo.devSize_KB     = nvdimmData.maxMemorySizeKB;
    o_i2cInfo.chipCount      = nvdimmData.chipCount;
    o_i2cInfo.writeCycleTime = nvdimmData.writeCycleTime;
    o_i2cInfo.i2cMuxBusSelector = nvdimmData.i2cMuxBusSelector;
    o_i2cInfo.i2cMuxPath     = nvdimmData.i2cMuxPath;

    // Convert attribute info to nvdimm_addr_size_t enum
    if ( nvdimmData.byteAddrOffset == 0x3 )
    {
        o_i2cInfo.addrSize = ONE_BYTE_ADDR;
    }
    else if ( nvdimmData.byteAddrOffset == 0x2 )
    {
        o_i2cInfo.addrSize = TWO_BYTE_ADDR;
    }
    else if ( nvdimmData.byteAddrOffset == 0x1 )
    {
        o_i2cInfo.addrSize = ONE_BYTE_ADDR_PAGESELECT;
    }
    else if ( nvdimmData.byteAddrOffset == 0x0 )
    {
        o_i2cInfo.addrSize = ZERO_BYTE_ADDR;
    }
    else
    {
        TRACFCOMP( g_trac_nvdimm,
                   ERR_MRK"nvdimmReadAttributes() - INVALID ADDRESS "
                   "OFFSET SIZE %d!",
                   o_i2cInfo.addrSize );

            /*@
             * @errortype
             * @reasoncode       NVDIMM_INVALID_ADDR_OFFSET_SIZE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         NVDIMM_READATTRIBUTES
             * @userdata1        HUID of target
             * @userdata2        Address Offset Size
             * @devdesc          Invalid address offset size
             * @custdesc         An internal firmware error occurred
             */
            err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                NVDIMM_READATTRIBUTES,
                                NVDIMM_INVALID_ADDR_OFFSET_SIZE,
                                TARGETING::get_huid(i_target),
                                o_i2cInfo.addrSize,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( NVDIMM_COMP_NAME );

            return err;

    }

    TRACUCOMP(g_trac_nvdimm,"nvdimmReadAttributes() tgt=0x%X, %d/%d/0x%X "
              "wpw=0x%X, dsKb=0x%X, chpCnt=%d, aS=%d (%d), wct=%d",
              TARGETING::get_huid(i_target),
              o_i2cInfo.port, o_i2cInfo.engine, o_i2cInfo.devAddr,
              o_i2cInfo.writePageSize, o_i2cInfo.devSize_KB,
              o_i2cInfo.chipCount, o_i2cInfo.addrSize,
              nvdimmData.byteAddrOffset, o_i2cInfo.writeCycleTime);

    // Printing mux info separately, if combined, nothing is displayed
    char* l_muxPath = o_i2cInfo.i2cMuxPath.toString();
    TRACFCOMP(g_trac_nvdimm, "nvdimmReadAttributes(): "
              "muxSelector=0x%X, muxPath=%s",
              o_i2cInfo.i2cMuxBusSelector,
              l_muxPath);
    free(l_muxPath);
    l_muxPath = nullptr;

    TRACDCOMP( g_trac_nvdimm,
               EXIT_MRK"nvdimmReadAttributes()" );

    return err;
} // end nvdimmReadAttributes


// ------------------------------------------------------------------
// nvdimmGetI2CMasterTarget
// ------------------------------------------------------------------
errlHndl_t nvdimmGetI2CMasterTarget ( TARGETING::Target * i_target,
                                      nvdimm_addr_t i_i2cInfo,
                                      TARGETING::Target * &o_target )
{
    errlHndl_t err = nullptr;
    o_target = nullptr;

    TRACDCOMP( g_trac_nvdimm,
               ENTER_MRK"nvdimmGetI2CMasterTarget()" );

    do
    {
        TARGETING::TargetService& tS = TARGETING::targetService();

        // The path from i_target to its I2C Master was read from the
        // attribute via nvdimmReadAttributes() and passed to this function
        // in i_i2cInfo.i2cMasterPath

        // check that the path exists
        bool exists = false;
        tS.exists( i_i2cInfo.i2cMasterPath,
                   exists );

        if( !exists )
        {
            TRACFCOMP( g_trac_nvdimm,
                       ERR_MRK"nvdimmGetI2CMasterTarget() - "
                       "i2cMasterPath attribute path doesn't exist!" );

            // Compress the entity path
            uint64_t l_epCompressed = 0;
            for( uint32_t i = 0; i < i_i2cInfo.i2cMasterPath.size(); i++ )
            {
                // Path element: type:8 instance:8
                l_epCompressed |=
                    i_i2cInfo.i2cMasterPath[i].type << (16*(3-i));
                l_epCompressed |=
                    i_i2cInfo.i2cMasterPath[i].instance << ((16*(3-i))-8);

                // Can only fit 4 path elements into 64 bits
                if ( i == 3 )
                {
                    break;
                }
            }

            /*@
             * @errortype
             * @reasoncode       NVDIMM_I2C_MASTER_PATH_ERROR
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         NVDIMM_GETI2CMASTERTARGET
             * @userdata1        HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          I2C master entity path doesn't exist.
             * @custdesc         An internal firmware error occurred
             */
            err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                NVDIMM_GETI2CMASTERTARGET,
                                NVDIMM_I2C_MASTER_PATH_ERROR,
                                TARGETING::get_huid(i_target),
                                l_epCompressed,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( NVDIMM_COMP_NAME );

            char* l_masterPath = i_i2cInfo.i2cMasterPath.toString();
            ERRORLOG::ErrlUserDetailsString(l_masterPath).addToLog(err);
            free(l_masterPath);
            l_masterPath = nullptr;

            break;
        }

        // Since it exists, convert to a target
        o_target = tS.toTarget( i_i2cInfo.i2cMasterPath );

        if( nullptr == o_target )
        {
            TRACFCOMP( g_trac_nvdimm,
                       ERR_MRK"nvdimmGetI2CMasterTarget() - I2C Master "
                              "Path target was nullptr!" );

            // Compress the entity path
            uint64_t l_epCompressed = 0;
            for( uint32_t i = 0; i < i_i2cInfo.i2cMasterPath.size(); i++ )
            {
                // Path element: type:8 instance:8
                l_epCompressed |=
                    i_i2cInfo.i2cMasterPath[i].type << (16*(3-i));
                l_epCompressed |=
                    i_i2cInfo.i2cMasterPath[i].instance << ((16*(3-i))-8);

                // Can only fit 4 path elements into 64 bits
                if ( i == 3 )
                {
                    break;
                }
            }

            /*@
             * @errortype
             * @reasoncode       NVDIMM_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         NVDIMM_GETI2CMASTERTARGET
             * @userdata1        HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          I2C master path target is null.
             * @custdesc         An internal firmware error occurred
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           NVDIMM_GETI2CMASTERTARGET,
                                           NVDIMM_TARGET_NULL,
                                           TARGETING::get_huid(i_target),
                                           l_epCompressed,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( NVDIMM_COMP_NAME );

            char* l_masterPath = i_i2cInfo.i2cMasterPath.toString();
            ERRORLOG::ErrlUserDetailsString(l_masterPath).addToLog(err);
            free(l_masterPath);
            l_masterPath = nullptr;

            break;
        }

    } while( 0 );

    TRACDCOMP( g_trac_nvdimm,
               EXIT_MRK"nvdimmGetI2CMasterTarget()" );

    return err;
} // end nvdimmGetI2CMasterTarget

/**
 * @brief Add any new NVDIMMs associated with this target
 *   to the list
 * @param[in] i_list : list of previously discovered NVDIMMs
 * @param[out] i_targ : owner of NVDIMMs to add
 */
void add_to_list( std::list<EEPROM::EepromInfo_t>& i_list,
                  TARGETING::Target* i_targ )
{
    TRACFCOMP(g_trac_nvdimm,"Targ %.8X",TARGETING::get_huid(i_targ));

    TARGETING::EepromNvInfo nvdimmData;

    if( i_targ->tryGetAttr<TARGETING::ATTR_EEPROM_NV_INFO>
                ( reinterpret_cast<TARGETING::ATTR_EEPROM_NV_INFO_type&>( nvdimmData) ) )
    {
        // check that the path exists
        bool exists = false;
        TARGETING::targetService().exists( nvdimmData.i2cMasterPath,
                                           exists );
        if( !exists )
        {
            TRACDCOMP(g_trac_nvdimm,"no master path");
            return;
        }

        // Since it exists, convert to a target
        TARGETING::Target* i2cm = TARGETING::targetService()
          .toTarget( nvdimmData.i2cMasterPath );
        if( nullptr == i2cm )
        {
            //not sure how this could happen, but just skip it
            TRACDCOMP(g_trac_nvdimm,"no target");
            return;
        }

        // ignore anything with junk data
        TARGETING::Target * sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( sys );
        if( i2cm == sys )
        {
            TRACDCOMP(g_trac_nvdimm,"sys target");
            return;
        }

        // copy all the data out
        EEPROM::EepromInfo_t nv_info;
        nv_info.i2cMaster = i2cm;
        nv_info.engine = nvdimmData.engine;
        nv_info.port = nvdimmData.port;
        nv_info.devAddr = nvdimmData.devAddr;
        nv_info.assocTarg = i_targ;
        nv_info.chipCount = nvdimmData.chipCount;
        nv_info.addrBytes = nvdimmData.byteAddrOffset;
        //one more lookup for the speed
        TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speeds;
        if( i2cm->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
            (speeds) )
        {
            if( (nv_info.engine > I2C_BUS_MAX_ENGINE(speeds))
                || (nv_info.port > I2C_BUS_MAX_PORT(speeds)) )
            {
                TRACDCOMP(g_trac_nvdimm,"bad engine/port");
                return;
            }
            nv_info.busFreq = speeds[nv_info.engine][nv_info.port];
            nv_info.busFreq *= 1000; //convert KHz->Hz
        }
        else
        {
            TRACDCOMP(g_trac_nvdimm,"bus speed not found");
            return;
        }

        i_list.push_back(nv_info);
        TRACFCOMP(g_trac_nvdimm,"--Adding i2cm=%.8X, eng=%d, port=%d, "
                                "addr=%.2X for %.8X",
                                TARGETING::get_huid(i2cm),
                                nvdimmData.engine,
                                nvdimmData.port,
                                nv_info.devAddr,
                                TARGETING::get_huid(nv_info.assocTarg));
    }
}

/**
 * @brief Return a set of information related to every unique
 *        NVDIMM in the system
 */
void getNVDIMMs( std::list<EEPROM::EepromInfo_t>& o_info )
{
    TRACUCOMP(g_trac_nvdimm,ENTER_MRK "getNVDIMMs()");

    TARGETING::TargetHandleList l_dimmList;

    TARGETING::getAllLogicalCards(
        l_dimmList,
        TARGETING::TYPE_DIMM);

    for (auto const l_dimm : l_dimmList)
    {
        if (TARGETING::isNVDIMM(l_dimm))
            add_to_list( o_info, l_dimm );
    }

    TRACUCOMP(g_trac_nvdimm,EXIT_MRK "getNVDIMMs(): Found %d NVDIMMs",
        o_info.size());
}

} // end namespace NVDIMM
