/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/eepromdd_hardware.C $                             */
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
#include "eepromdd_hardware.H"
#include <sys/time.h>
#include "errlud_i2c.H"
#include <i2c/eepromif.H>
#include <i2c/i2cif.H>
#include <errl/errlmanager.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/eepromddreasoncodes.H>
#include <errl/errludstring.H>
#include <errl/errludtarget.H>

extern trace_desc_t* g_trac_eeprom;

// ----------------------------------------------
// Globals
// ----------------------------------------------
mutex_t g_eepromMutex = MUTEX_INITIALIZER;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

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

namespace EEPROM
{

errlHndl_t eepromPerformOpHW(DeviceFW::OperationType i_opType,
                             TARGETING::Target * i_target,
                             void * io_buffer,
                             size_t & io_buflen,
                             eeprom_addr_t & io_i2cInfo)
{
#ifdef __HOSTBOOT_RUNTIME
    // At runtime the OCC sensor cache will need to be disabled to avoid I2C
    // collisions. This bool indicates the sensor cache was enabled but is
    // now disabled and needs to be re-enabled when the eeprom op completes.
    bool scacDisabled = false;
#endif //__HOSTBOOT_RUNTIME
    TARGETING::Target * i2cMasterTarget = nullptr;
    void * l_pBuffer        = io_buffer;
    size_t l_currentOpLen   = io_buflen;
    size_t l_remainingOpLen = io_buflen;
    errlHndl_t err = nullptr;

    do
    {
        // Read Attributes needed to complete the operation
        err = eepromReadAttributes( i_target,
                                    io_i2cInfo );

        if( err )
        {
            break;
        }

        size_t l_snglChipSize = (io_i2cInfo.devSize_KB * KILOBYTE)
                                / io_i2cInfo.chipCount;

        // Check to see if we need to find a new target for
        // the I2C Master
        err = eepromGetI2CMasterTarget( i_target,
                                        io_i2cInfo,
                                        i2cMasterTarget );

        if( err )
        {
            break;
        }

        // Check that the offset + data length is less than device max size
        if ( ( io_i2cInfo.offset + io_buflen ) >
             ( io_i2cInfo.devSize_KB * KILOBYTE  ) )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromPerformOp(): Device Overflow! "
                       "C-e/p/dA=%d-%d/%d/0x%X, offset=0x%X, len=0x%X "
                       "devSizeKB=0x%X", io_i2cInfo.eepromRole, io_i2cInfo.engine,
                       io_i2cInfo.port, io_i2cInfo.devAddr, io_i2cInfo.offset,
                       io_buflen, io_i2cInfo.devSize_KB);


            /*@
             * @errortype
             * @reasoncode       EEPROM_OVERFLOW_ERROR
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         EEPROM_PERFORM_OP
             * @userdata1[0:31]  Offset
             * @userdata1[32:63] Buffer Length
             * @userdata2        Device Max Size (in KB)
             * @devdesc          I2C Buffer Length + Offset > Max Size
             * @custdesc         A problem occurred during the IPL of the
             *                   system: I2C buffer offset is too large.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           EEPROM_PERFORM_OP,
                                           EEPROM_OVERFLOW_ERROR,
                                           TWO_UINT32_TO_UINT64(
                                               io_i2cInfo.offset,
                                               io_buflen       ),
                                           io_i2cInfo.devSize_KB,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( EEPROM_COMP_NAME );

            break;
        }

        // Adjust offset and devAddr to the correct starting chip
        while( io_i2cInfo.offset >= l_snglChipSize )
        {
            io_i2cInfo.offset -= l_snglChipSize;
            io_i2cInfo.devAddr += EEPROM_DEVADDR_INC;
        }

        // Keep first op length within a chip
        if( ( io_i2cInfo.offset + io_buflen ) > l_snglChipSize )
        {
            l_currentOpLen = l_snglChipSize - io_i2cInfo.offset;
        }

        TRACFCOMP( g_trac_eeprom,
                   "eepromPerformOp():  i_opType=%d "
                   "C-e/p/dA=%d-%d/%d/0x%X, offset=0x%X, len=0x%X, ",
                   i_opType, io_i2cInfo.eepromRole, io_i2cInfo.engine,
                   io_i2cInfo.port, io_i2cInfo.devAddr, io_i2cInfo.offset, io_buflen)

        TRACFCOMP (g_trac_eeprom,
                   "eepromPerformOp(): snglChipKB=0x%X, chipCount=0x%X, devSizeKB=0x%X",
                   l_snglChipSize, io_i2cInfo.chipCount, io_i2cInfo.devSize_KB);

        // Printing mux info separately, if combined, nothing is displayed
        char* l_muxPath = io_i2cInfo.i2cMuxPath.toString();
        TRACFCOMP(g_trac_eeprom, "eepromPerformOp(): "
                  "muxSelector=0x%X, muxPath=%s",
                  io_i2cInfo.i2cMuxBusSelector,
                  l_muxPath);
        free(l_muxPath);
        l_muxPath = nullptr;

#ifdef __HOSTBOOT_RUNTIME
        // Disable Sensor Cache if the I2C master target is MEMBUF
        if( i2cMasterTarget->getAttr<TARGETING::ATTR_TYPE>() ==
                                                    TARGETING::TYPE_MEMBUF )
        {
            err = I2C::i2cDisableSensorCache(i2cMasterTarget,scacDisabled);
            if ( err )
            {
                break;
            }
        }
#endif //__HOSTBOOT_RUNTIME

        // Do the read or write
        while(l_remainingOpLen > 0)
        {
            if( i_opType == DeviceFW::READ )
            {
                err = eepromRead( i2cMasterTarget,
                                  l_pBuffer,
                                  l_currentOpLen,
                                  io_i2cInfo );
            }
            else if( i_opType == DeviceFW::WRITE )
            {
                err = eepromWrite( i2cMasterTarget,
                                   l_pBuffer,
                                   l_currentOpLen,
                                   io_i2cInfo );
            }
            else
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromPerformOp(): "
                           "Invalid EEPROM Operation!");

                /*@
                 * @errortype
                 * @reasoncode     EEPROM_INVALID_OPERATION
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       EEPROM_PERFORM_OP
                 * @userdata1      Operation Type
                 * @userdata2      Chip to Access
                 * @devdesc        Invalid operation type.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               EEPROM_PERFORM_OP,
                                               EEPROM_INVALID_OPERATION,
                                               i_opType,
                                               io_i2cInfo.eepromRole,
                                               true /*Add HB SW Callout*/ );

                err->collectTrace( EEPROM_COMP_NAME );
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

            // Prepare the address at the start of next EEPROM
            io_i2cInfo.offset = 0;
            io_i2cInfo.devAddr += EEPROM_DEVADDR_INC;
        } // Do the read or write
    } while( 0 );

#ifdef __HOSTBOOT_RUNTIME
    // Re-enable sensor cache if it was disabled before the eeprom op and
    // the I2C master target is MEMBUF
    if( scacDisabled &&
       (i2cMasterTarget->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_MEMBUF) )
    {
        errlHndl_t tmp_err = NULL;

        tmp_err = I2C::i2cEnableSensorCache(i2cMasterTarget);

        if( err && tmp_err)
        {
            delete tmp_err;
            TRACFCOMP(g_trac_eeprom,
                ERR_MRK" Enable Sensor Cache failed for HUID=0x%.8X",
                TARGETING::get_huid(i2cMasterTarget));
        }
        else if(tmp_err)
        {
            err = tmp_err;
        }
    }
#endif //__HOSTBOOT_RUNTIME

    // If there is an error, add parameter info to log
    if ( err != NULL )
    {
        EEPROM::UdEepromParms( i_opType,
                               i_target,
                               io_buflen,
                               io_i2cInfo )
                             .addToLog(err);
    }

    return err;
}

// ------------------------------------------------------------------
// eepromPageOp
// ------------------------------------------------------------------
errlHndl_t eepromPageOp( TARGETING::Target * i_target,
                         bool i_switchPage,
                         bool i_lockMutex,
                         bool & io_pageLocked,
                         uint8_t i_desiredPage,
                         const eeprom_addr_t & i_i2cInfo )
{
    TRACUCOMP(g_trac_eeprom,
            ENTER_MRK"eepromPageOp()");

    errlHndl_t l_err = NULL;
    size_t l_placeHolderZero = 0;

    do
    {
        // DDR4 requires EEPROM page to be selected before read/write operation.
        // The following operation locks the EEPROM_PAGE attribute behind a
        // mutex and switches all DIMMs on the I2C bus to the appropriate
        // page.
        if( i_i2cInfo.addrSize == ONE_BYTE_ADDR_PAGESELECT )
        {

            bool l_lockPage;
            if( i_switchPage )
            {
                // we want to switch to the desired page
                l_lockPage = true;
                l_err = deviceOp( DeviceFW::WRITE,
                                i_target,
                                NULL,
                                l_placeHolderZero,
                                DEVICE_I2C_CONTROL_PAGE_OP(
                                    i_i2cInfo.port,
                                    i_i2cInfo.engine,
                                    l_lockPage,
                                    i_desiredPage,
                                    i_lockMutex ));

                if( l_err )
                {
                    TRACFCOMP(g_trac_eeprom,
                            "eepromPageOp::Failed locking EEPROM page");
                    break;
                }
                // if we make it this far, we successfully locked the page mutex
                io_pageLocked = true;
            }
            else
            {
                // we only want to unlock the page
                l_lockPage = false;
                l_err = deviceOp( DeviceFW::WRITE,
                                i_target,
                                NULL,
                                l_placeHolderZero,
                                DEVICE_I2C_CONTROL_PAGE_OP(
                                    i_i2cInfo.port,
                                    i_i2cInfo.engine,
                                    l_lockPage,
                                    l_placeHolderZero,
                                    i_lockMutex ));

                if( l_err )
                {
                    TRACFCOMP( g_trac_eeprom,
                            "eepromPageOp()::failed unlocking EEPROM page");
                    break;
                }
                // if we make it this far, we successfully unlocked the page
                io_pageLocked = false;
            }
        }
    }while(0);
    TRACUCOMP(g_trac_eeprom,
            EXIT_MRK"eepromPageOp()");
    return l_err;
}


// ------------------------------------------------------------------
// crossesEepromPageBoundary
// ------------------------------------------------------------------
bool crossesEepromPageBoundary( uint64_t i_originalOffset,
                                size_t i_originalLen,
                                size_t & io_newLen,
                                size_t & o_pageTwoBuflen,
                                const eeprom_addr_t& i_i2cInfo )
{
    bool l_boundaryCrossed = false;
    size_t l_higherBound = i_originalOffset + i_originalLen;

    if( ( i_i2cInfo.addrSize == ONE_BYTE_ADDR_PAGESELECT ) &&
      ( ( i_originalOffset < EEPROM_PAGE_SIZE ) &&
        ( l_higherBound > EEPROM_PAGE_SIZE) ) )
    {
        // The read/write request crosses the boundary
        l_boundaryCrossed = true;

        // Calculate the new length of the page 0 buffer and the
        // length of the page 1 buffer
        o_pageTwoBuflen = l_higherBound - EEPROM_PAGE_SIZE;
        io_newLen = i_originalLen - o_pageTwoBuflen;
    }
    else
    {
        // The read/write request does not cross the boundary.
        // Update new length to be used by subsequent operations
        io_newLen = i_originalLen;
        o_pageTwoBuflen = 0;
    }

    return l_boundaryCrossed;
}



// ------------------------------------------------------------------
// eepromRead
// ------------------------------------------------------------------
errlHndl_t eepromRead ( TARGETING::Target * i_target,
                        void * o_buffer,
                        size_t i_buflen,
                        eeprom_addr_t i_i2cInfo )
{
    errlHndl_t err = NULL;
    uint8_t byteAddr[MAX_BYTE_ADDR];
    size_t byteAddrSize = 0;
    bool l_pageLocked = false;
    uint8_t l_desiredPage = 0;
    bool l_boundaryCrossed = false;
    size_t l_readBuflen = 0;
    size_t l_pageTwoBuflen = 0;

    TRACUCOMP( g_trac_eeprom,
               ENTER_MRK"eepromRead()" );

    do
    {
        TRACUCOMP( g_trac_eeprom,
                   "EEPROM READ  START : Chip: %02d : Offset %.2X : Len %d",
                   i_i2cInfo.chip, i_i2cInfo.offset, i_buflen );

        // At maximum we want to do 1 KB reads at a time. The largest that
        // the scom byte range will support is 64 KB - 1 but we will do 1
        // KB at a time to catch fails faster. This is useful when we do big
        // reads when caching the eeprom to pnor.
        size_t l_readLenRemaining = i_buflen;
        size_t l_currentReadLen;

        // Lock to sequence operations
        mutex_lock( &g_eepromMutex );

        while( l_readLenRemaining > 0 )
        {
            l_currentReadLen = l_readLenRemaining < KILOBYTE ? l_readLenRemaining : KILOBYTE;

            // Check to see if the Read operation straddles the EEPROM page
            // boundary.Note this is only required for systems w/ DDR4 industry
            // standard dimms. DDR4 ISDIMMS have a max of 512 bytes so we will
            // never loop through this multiple times on those systems
            l_boundaryCrossed = crossesEepromPageBoundary( i_i2cInfo.offset,
                                                          l_currentReadLen,
                                                          l_readBuflen,
                                                          l_pageTwoBuflen,
                                                          i_i2cInfo );

            // Set addressing parameters
            err = eepromPrepareAddress( i_target,
                                        &byteAddr,
                                        byteAddrSize,
                                        l_desiredPage,
                                        i_i2cInfo);

            if( err )
            {
                TRACFCOMP(g_trac_eeprom,
                        ERR_MRK"eepromRead()::eepromPrepareAddress()");
                break;
            }


            // Attempt to lock page mutex
            // (only important in DDR4 IS-DIMM systems)
            bool l_switchPage = true;
            bool l_lockMutex = true;
            err = eepromPageOp( i_target,
                                l_switchPage,
                                l_lockMutex,
                                l_pageLocked,
                                l_desiredPage,
                                i_i2cInfo );

            if( err )
            {
                TRACFCOMP(g_trac_eeprom,
                        "eepromRead()::eepromPageOp()::failed locking page");
                break;
            }

            // First Read. If Second read is necessary, this call will read
            // everything from the original offset up to the 256th byte
            err = eepromReadData( i_target,
                                  &(reinterpret_cast<uint8_t*>(o_buffer)[i_buflen - l_readLenRemaining]),
                                  l_readBuflen,
                                  &byteAddr,
                                  byteAddrSize,
                                  i_i2cInfo );

            i_i2cInfo.offset += l_currentReadLen;
            l_readLenRemaining -= l_currentReadLen;

            if( err )
            {
                TRACFCOMP(g_trac_eeprom,
                        "Failed reading data: original read");
                break;
            }


            // Perform the second Read if necessary. Read starts at
            // begining of EEPROM page 1 (offset=0x100) and reads the
            // rest of the required data.
            if( l_boundaryCrossed )
            {
                //Prepare the address to read at the start of EEPROM page one
                i_i2cInfo.offset = EEPROM_PAGE_SIZE; // 0x100
                err = eepromPrepareAddress( i_target,
                                            &byteAddr,
                                            byteAddrSize,
                                            l_desiredPage,
                                            i_i2cInfo );
                if( err )
                {
                    TRACFCOMP(g_trac_eeprom,
                            "Error preparing address: second eeprom read");
                    break;
                }

                // Switch to the second EEPROM page
                l_switchPage = true;
                l_lockMutex = false;
                err = eepromPageOp( i_target,
                                    l_switchPage,
                                    l_lockMutex,
                                    l_pageLocked,
                                    l_desiredPage,
                                    i_i2cInfo );

                if( err )
                {
                    TRACFCOMP( g_trac_eeprom,
                            "Failed switching to EEPROM page 1 for second read op");
                    break;
                }

                // Perform the second read operation
                err = eepromReadData(
                              i_target,
                              &(reinterpret_cast<uint8_t*>(o_buffer)[l_readBuflen]),
                              l_pageTwoBuflen,
                              &byteAddr,
                              byteAddrSize,
                              i_i2cInfo );

                if( err )
                {
                    TRACFCOMP( g_trac_eeprom,
                            "Failed reading data: second read");
                    break;
                }
            }
        }


        TRACUCOMP( g_trac_eeprom,
                   "EEPROM READ  END   : Eeprom Role: %02d : Offset %.2X : Len %d : %016llx",
                   i_i2cInfo.eepromRole, i_i2cInfo.offset, i_buflen,
                   *((uint64_t*)o_buffer) );

    } while( 0 );

    // Unlock eeprom mutex no matter what
    mutex_unlock( & g_eepromMutex );

    // Whether we failed in the main routine or not, unlock page iff the page is locked
    if( l_pageLocked )
    {
        errlHndl_t l_pageOpErrl = NULL;
        bool l_switchPage = false;
        bool l_lockMutex = false;
        l_pageOpErrl = eepromPageOp( i_target,
                                     l_switchPage,
                                     l_lockMutex,
                                     l_pageLocked,
                                     l_desiredPage,
                                     i_i2cInfo );
        if( l_pageOpErrl )
        {
            TRACFCOMP(g_trac_eeprom,
                    "eepromRead()::Failed unlocking page");
            errlCommit(l_pageOpErrl, I2C_COMP_ID);
        }

    }

    TRACUCOMP( g_trac_eeprom,
               EXIT_MRK"eepromRead()" );

    return err;
} // end eepromRead


// ------------------------------------------------------------------
// eepromReadData
// ------------------------------------------------------------------
errlHndl_t eepromReadData( TARGETING::Target * i_target,
                           void * o_buffer,
                           size_t i_buflen,
                           void * i_byteAddress,
                           size_t i_byteAddressSize,
                           eeprom_addr_t i_i2cInfo )
{
    errlHndl_t l_err = NULL;
    errlHndl_t err_retryable = NULL;

    TRACUCOMP(g_trac_eeprom,
            ENTER_MRK"eepromReadData()");
    do
    {
        /************************************************************/
        /* Attempt read multiple times ONLY on retryable fails      */
        /************************************************************/
        for (uint8_t retry = 0;
             retry <= EEPROM_MAX_RETRIES;
             retry++)
        {

            // Only write the byte address if we have data to write
            if( 0 != i_byteAddressSize )
            {
                // Use the I2C MUX OFFSET Interface for the READ
                l_err = deviceOp( DeviceFW::READ,
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
                    TRACFCOMP(g_trac_eeprom,
                              ERR_MRK"eepromReadData(): I2C Read-Offset failed on "
                              "%d/%d/0x%X aS=%d",
                              i_i2cInfo.port, i_i2cInfo.engine,
                              i_i2cInfo.devAddr, i_byteAddressSize);
                    TRACFBIN(g_trac_eeprom, "i_byteAddress[]",
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
                    TRACFCOMP(g_trac_eeprom,
                              ERR_MRK"eepromReadData(): I2C Read failed on "
                              "%d/%d/0x%0X", i_i2cInfo.port, i_i2cInfo.engine,
                              i_i2cInfo.devAddr);

                    // Don't break here -- error handled below
                }
            }

            if ( l_err == NULL )
            {
                // Operation completed successfully
                // break from retry loop
                break;
            }
            else if ( !errorIsRetryable( l_err->reasonCode() ) )
            {
                // Only retry on errorIsRetryable() failures: break from retry loop
                TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromReadData(): Non-Nack "
                           "Error: rc=0x%X, tgt=0x%X, No Retry (retry=%d)",
                            l_err->reasonCode(),
                            TARGETING::get_huid(i_target), retry);

                l_err->collectTrace(EEPROM_COMP_NAME);

                // break from retry loop
                break;
            }
            else // Handle retryable error
            {
                // If op will be attempted again: save log and continue
                if ( retry < EEPROM_MAX_RETRIES )
                {
                    // Only save original retryable error
                    if ( err_retryable == NULL )
                    {
                        // Save original retryable error
                        err_retryable = l_err;

                        TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromReadData(): "
                                   "Retryable Error rc=0x%X, eid=0x%X, tgt=0x%X, "
                                   "retry/MAX=%d/%d. Save error and retry",
                                   err_retryable->reasonCode(),
                                   err_retryable->eid(),
                                   TARGETING::get_huid(i_target),
                                   retry, EEPROM_MAX_RETRIES);

                        err_retryable->collectTrace(EEPROM_COMP_NAME);
                    }
                    else
                    {
                        // Add data to original retryable error
                        TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromReadData(): "
                                   "Another Retryable Error rc=0x%X, eid=0x%X "
                                   "plid=0x%X, tgt=0x%X, retry/MAX=%d/%d. "
                                   "Delete error and retry",
                                   l_err->reasonCode(), l_err->eid(), l_err->plid(),
                                   TARGETING::get_huid(i_target),
                                   retry, EEPROM_MAX_RETRIES);

                        ERRORLOG::ErrlUserDetailsString(
                                  "Another Retryable ERROR found")
                                  .addToLog(err_retryable);

                        // Delete this new retryable error
                        delete l_err;
                        l_err = NULL;
                    }

                    // continue to retry
                    continue;
                }
                else // no more retries: trace and break
                {
                    TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromReadData(): "
                               "Error rc=0x%X, eid=%d, tgt=0x%X. No More "
                               "Retries (retry/MAX=%d/%d). Returning Error",
                               l_err->reasonCode(), l_err->eid(),
                               TARGETING::get_huid(i_target),
                               retry, EEPROM_MAX_RETRIES);

                    l_err->collectTrace(EEPROM_COMP_NAME);

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
                TRACFCOMP(g_trac_eeprom, "eepromReadData(): Committing saved retryable "
                          "l_err eid=0x%X with plid of returned err: 0x%X",
                          err_retryable->eid(), err_retryable->plid());

                ERRORLOG::ErrlUserDetailsTarget(i_target)
                                               .addToLog(err_retryable);

                errlCommit(err_retryable, EEPROM_COMP_ID);
            }
            else
            {
                // Since we eventually succeeded, delete original retryable error
                TRACFCOMP(g_trac_eeprom, "eepromReadData(): Op successful, "
                          "deleting saved retryable err eid=0x%X, plid=0x%X",
                          err_retryable->eid(), err_retryable->plid());

                delete err_retryable;
                err_retryable = NULL;
            }
        }

    }while( 0 );

    TRACUCOMP(g_trac_eeprom,
            EXIT_MRK"eepromReadData");
    return l_err;
}



// ------------------------------------------------------------------
// eepromWrite
// ------------------------------------------------------------------
errlHndl_t eepromWrite ( TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         eeprom_addr_t i_i2cInfo )
{
    errlHndl_t err = NULL;
    uint8_t l_desiredPage = 0;
    uint8_t l_originalPage = 0;
    uint8_t byteAddr[MAX_BYTE_ADDR];
    size_t byteAddrSize = 0;
    uint8_t * newBuffer = NULL;
    bool needFree = false;
    bool unlock = false;
    bool l_pageLocked = false;
    uint32_t data_left = 0;
    uint32_t diff_wps = 0;
    size_t l_writeBuflen = 0;
    size_t l_bytesIntoSecondPage = 0;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromWrite()" );

    do
    {
        TRACUCOMP( g_trac_eeprom,
                   "EEPROM WRITE START : Eeprom Role : %02d : Offset %.2X : Len %d : %016llx",
                   i_i2cInfo.eepromRole, i_i2cInfo.offset, io_buflen,
                   *((uint64_t*)io_buffer) );


        // Prepare address parameters
        err = eepromPrepareAddress( i_target,
                                    &byteAddr,
                                    byteAddrSize,
                                    l_desiredPage,
                                    i_i2cInfo);

        if( err )
        {
            TRACFCOMP(g_trac_eeprom,
                    ERR_MRK"eepromWrite()::eepromPrepareAddress()");
            break;
        }

        // Save original Page
        l_originalPage = l_desiredPage;
        // Attempt to lock page mutex
        bool l_switchPage = true; // true: Lock and switch page
                                  // false: Just unlock page
        bool l_lockMutex = true;  // true: Lock mutex
                                  // false: Skip locking mutex step
        err = eepromPageOp( i_target,
                            l_switchPage,
                            l_lockMutex,
                            l_pageLocked,
                            l_desiredPage,
                            i_i2cInfo );

        if( err )
        {
            TRACFCOMP(g_trac_eeprom,
                    "eepromWrite()::Failed locking EEPROM page");
            break;
        }

        // Check for writePageSize of zero
        if ( i_i2cInfo.writePageSize == 0 )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromWrite(): writePageSize is 0!");

            /*@
             * @errortype
             * @reasoncode     EEPROM_I2C_WRITE_PAGE_SIZE_ZERO
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       EEPROM_WRITE
             * @userdata1      HUID of target
             * @userdata2      Chip to Access
             * @devdesc        I2C write page size is zero.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           EEPROM_WRITE,
                                           EEPROM_I2C_WRITE_PAGE_SIZE_ZERO,
                                           TARGETING::get_huid(i_target),
                                           i_i2cInfo.eepromRole,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( EEPROM_COMP_NAME );

            break;
        }

        // EEPROM devices have write page boundaries, so when necessary
        // need to split up command into multiple write operations

        // Setup a max-size buffer of writePageSize
        size_t newBufLen = i_i2cInfo.writePageSize;
        newBuffer = static_cast<uint8_t*>(malloc( newBufLen ));
        needFree = true;

        // Point a uint8_t ptr at io_buffer for array addressing below
        uint8_t * l_data_ptr = reinterpret_cast<uint8_t*>(io_buffer);

        // Lock for operation sequencing
        mutex_lock( &g_eepromMutex );
        unlock = true;

        // variables to store different amount of data length
        size_t loop_data_length = 0;
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

            // Take the lesser of the 2 options
            loop_data_length = (data_left < diff_wps ) ? data_left : diff_wps;

            // Add the data the user wanted to write
            memcpy( newBuffer,
                    &l_data_ptr[total_bytes_written],
                    loop_data_length );



            // Check if loop_data_length crosses the EEPROM page boundary
            crossesEepromPageBoundary( i_i2cInfo.offset,
                                       loop_data_length,
                                       l_writeBuflen,
                                       l_bytesIntoSecondPage,
                                       i_i2cInfo );

            // Setup offset/address parms
            err = eepromPrepareAddress( i_target,
                                        &byteAddr,
                                        byteAddrSize,
                                        l_desiredPage,
                                        i_i2cInfo );


            if( err )
            {
                TRACFCOMP(g_trac_eeprom,
                         ERR_MRK"eepromWrite::eepromPrepareAddress()::loop version");
                break;
            }



            // if desired page has changed mid-request, switch to correct page
            if( l_desiredPage != l_originalPage )
            {
                l_switchPage = true;
                l_lockMutex = false;
                err = eepromPageOp( i_target,
                                    l_switchPage,
                                    l_lockMutex,
                                    l_pageLocked,
                                    l_desiredPage,
                                    i_i2cInfo );
                if( err )
                {
                    TRACFCOMP( g_trac_eeprom,
                            "Failed switching to new EEPROM page!");
                    break;
                }
                l_originalPage = l_desiredPage;
            }

            TRACUCOMP(g_trac_eeprom,"eepromWrite() Loop: %d/%d/0x%X "
                "writeBuflen=%d, offset=0x%X, bAS=%d, diffs=%d/%d",
                i_i2cInfo.port, i_i2cInfo.engine, i_i2cInfo.devAddr,
                l_writeBuflen, i_i2cInfo.offset, byteAddrSize,
                data_left, diff_wps);

            // Perform the requested write operation
            err = eepromWriteData( i_target,
                                   newBuffer,
                                   l_writeBuflen,
                                   &byteAddr,
                                   byteAddrSize,
                                   i_i2cInfo );

            if ( err )
            {
                // Can't assume that anything was written if
                // there was an error, so no update to total_bytes_written
                // for this loop
                TRACFCOMP(g_trac_eeprom,
                         "Failed writing data: original eeprom write");
                break;
            }

            // Wait for EEPROM to write data to its internal memory
            // i_i2cInfo.writeCycleTime value in milliseconds
            nanosleep( 0, i_i2cInfo.writeCycleTime * NS_PER_MSEC );

            // Update how much data was written
            total_bytes_written += l_writeBuflen;

            // Update offset
            i_i2cInfo.offset += l_writeBuflen;

            TRACUCOMP(g_trac_eeprom,"eepromWrite() Loop End: "
                      "writeBuflen=%d, offset=0x%X, t_b_w=%d, io_buflen=%d",
                      l_writeBuflen, i_i2cInfo.offset,
                      total_bytes_written, io_buflen);
        } // end of write for-loop

        // Release mutex lock
        mutex_unlock( &g_eepromMutex );
        unlock = false;


        // Set how much data was actually written
        io_buflen = total_bytes_written;


        TRACSCOMP( g_trac_eeprom,
                   "EEPROM WRITE END   : Eeprom Role : %02d : Offset %.2X : Len %d",
                   i_i2cInfo.eepromRole, i_i2cInfo.offset, io_buflen );
    } while( 0 );

    // Free memory
    if( needFree )
    {
        free( newBuffer );
    }

    // Catch it if we break out early.
    if( unlock )
    {
        mutex_unlock( & g_eepromMutex );
    }


    // Whether we failed in the main routine or not, unlock the page iff it is already
    // locked
    if( l_pageLocked )
    {
        errlHndl_t l_pageOpErrl = NULL;

        bool l_switchPage = false;
        bool l_lockMutex = false;
        l_pageOpErrl = eepromPageOp( i_target,
                                     l_switchPage,
                                     l_lockMutex,
                                     l_pageLocked,
                                     l_desiredPage,
                                     i_i2cInfo );
        if( l_pageOpErrl )
        {
            TRACFCOMP(g_trac_eeprom,
                    "eepromWrite()::Failed unlocking page");
            errlCommit(l_pageOpErrl, I2C_COMP_ID);
        }

    }

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromWrite()" );

    return err;

} // end eepromWrite



// ------------------------------------------------------------------
// eepromWriteData
// ------------------------------------------------------------------
errlHndl_t eepromWriteData( TARGETING::Target * i_target,
                            void * i_dataToWrite,
                            size_t i_dataLen,
                            void * i_byteAddress,
                            size_t i_byteAddressSize,
                            eeprom_addr_t i_i2cInfo )
{
    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromWriteData()");
    errlHndl_t err = NULL;
    errlHndl_t err_retryable = NULL;
    do
    {
         /***********************************************************/
         /* Attempt write multiple times ONLY on retryable fails    */
         /***********************************************************/
        for (uint8_t retry = 0;
              retry <= EEPROM_MAX_RETRIES;
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
                                            &(i_i2cInfo.i2cMuxPath) ) );

             if ( err == NULL )
             {
                 // Operation completed successfully
                 // break from retry loop
                 break;
             }
             else if ( !errorIsRetryable( err->reasonCode() ) )
             {
                 // Only retry on errorIsRetryable() failures: break from retry loop
                 TRACFCOMP(g_trac_eeprom, ERR_MRK"eepromWriteData(): I2C "
                           "Write Non-Retryable fail %d/%d/0x%X, "
                           "ldl=%d, offset=0x%X, aS=%d, retry=%d",
                           i_i2cInfo.port, i_i2cInfo.engine,
                           i_i2cInfo.devAddr, i_dataLen,
                           i_i2cInfo.offset, i_i2cInfo.addrSize, retry);

                 err->collectTrace(EEPROM_COMP_NAME);

                 // break from retry loop
                 break;
             }
             else // Handle retryable error
             {
                 TRACFCOMP(g_trac_eeprom, ERR_MRK"eepromWriteData(): I2C "
                           "Write retryable fail %d/%d/0x%X, "
                           "ldl=%d, offset=0x%X, aS=%d, writePageSize = %x",
                           i_i2cInfo.port, i_i2cInfo.engine,
                           i_i2cInfo.devAddr, i_dataLen,
                           i_i2cInfo.offset, i_i2cInfo.addrSize,
                           i_i2cInfo.writePageSize);

                 // Printing mux info separately, if combined, nothing is displayed
                 char* l_muxPath = i_i2cInfo.i2cMuxPath.toString();
                 TRACFCOMP(g_trac_eeprom, ERR_MRK"eepromWriteData():"
                           "muxSelector=0x%X, muxPath=%s",
                           i_i2cInfo.i2cMuxBusSelector,
                           l_muxPath);
                 free(l_muxPath);
                 l_muxPath = nullptr;

                 // If op will be attempted again: save error and continue
                 if ( retry < EEPROM_MAX_RETRIES )
                 {
                     // Only save original retryable error
                     if ( err_retryable == NULL )
                     {
                         // Save original retryable error
                         err_retryable = err;

                         TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromWriteData(): "
                                    "Error rc=0x%X, eid=0x%X plid=0x%X, "
                                    "tgt=0x%X, retry/MAX=%d/%d. Save error "
                                    "and retry",
                                    err_retryable->reasonCode(),
                                    err_retryable->eid(),
                                    err_retryable->plid(),
                                    TARGETING::get_huid(i_target),
                                    retry, EEPROM_MAX_RETRIES);

                         err_retryable->collectTrace(EEPROM_COMP_NAME);
                     }
                     else
                     {
                         // Add data to original retryable error
                         TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromWriteData(): "
                                    "Another Retryable Error rc=0x%X, eid=0x%X "
                                    "plid=0x%X, tgt=0x%X, retry/MAX=%d/%d. "
                                    "Delete error and retry",
                                    err->reasonCode(), err->eid(),
                                    err->plid(),
                                    TARGETING::get_huid(i_target),
                                    retry, EEPROM_MAX_RETRIES);

                         ERRORLOG::ErrlUserDetailsString(
                                   "Another retryable ERROR found")
                                   .addToLog(err_retryable);

                         // Delete this new retryable error
                         delete err;
                         err = NULL;
                     }

                     // continue to retry
                     continue;
                 }
                 else // no more retries: trace and break
                 {
                     TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromWriteData(): "
                                "Error rc=0x%X, tgt=0x%X. No More Retries "
                                "(retry/MAX=%d/%d). Returning Error",
                                err->reasonCode(),
                                TARGETING::get_huid(i_target),
                                retry, EEPROM_MAX_RETRIES);

                     err->collectTrace(EEPROM_COMP_NAME);

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
                 TRACFCOMP(g_trac_eeprom, "eepromWriteData(): Committing saved "
                           "retryable err eid=0x%X with plid of returned err: "
                           "0x%X",
                           err_retryable->eid(), err_retryable->plid());

                 ERRORLOG::ErrlUserDetailsTarget(i_target)
                                                 .addToLog(err_retryable);

                 errlCommit(err_retryable, EEPROM_COMP_ID);
             }
             else
             {
                 // Since we eventually succeeded, delete original retryable error
                 TRACFCOMP(g_trac_eeprom, "eepromWriteData(): Op successful, "
                           "deleting saved retryable err eid=0x%X, plid=0x%X",
                           err_retryable->eid(), err_retryable->plid());

                 delete err_retryable;
                 err_retryable = NULL;
             }
         }
    }while( 0 );
    TRACDCOMP( g_trac_eeprom,
            EXIT_MRK"eepromWriteData()");
    return err;
}



// ------------------------------------------------------------------
// eepromPrepareAddress
// ------------------------------------------------------------------
errlHndl_t eepromPrepareAddress ( TARGETING::Target * i_target,
                                  void * io_buffer,
                                  size_t & o_bufSize,
                                  uint8_t & o_desiredPage,
                                  const eeprom_addr_t & i_i2cInfo )
{
    errlHndl_t err = NULL;
    o_bufSize = 0;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromPrepareAddress()" );

    do
    {

        // --------------------------------------------------------------------
        // Currently only supporting I2C devices and that use 0, 1, or 2 bytes
        // to set the offset (ie, internal address) into the device.
        // --------------------------------------------------------------------
        switch( i_i2cInfo.addrSize )
        {
            case TWO_BYTE_ADDR:
                o_bufSize = 2;
                memset( io_buffer, 0x0, o_bufSize );
                *((uint8_t*)io_buffer) = (i_i2cInfo.offset & 0xFF00ull) >> 8;
                *((uint8_t*)io_buffer+1) = (i_i2cInfo.offset & 0x00FFull);
                break;

            case ONE_BYTE_ADDR_PAGESELECT:
                // If the offset is less than 256 bytes, report page zero, else page 1
                if( i_i2cInfo.offset >= EEPROM_PAGE_SIZE )
                {
                    o_desiredPage = 1;
                }
                else
                {
                    o_desiredPage = 0;
                }
                o_bufSize = 1;
                memset( io_buffer, 0x0, o_bufSize );
                *((uint8_t*)io_buffer) = (i_i2cInfo.offset & 0xFFull);
                break;

            case ONE_BYTE_ADDR:
                o_bufSize = 1;
                memset( io_buffer, 0x0, o_bufSize );
                *((uint8_t*)io_buffer) = (i_i2cInfo.offset & 0xFFull);
                break;

            case ZERO_BYTE_ADDR:
                o_bufSize = 0;
                // nothing to do with the buffer in this case
                break;

            default:
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromPrepareAddress() - Invalid Device "
                           "Address Size: 0x%08x", i_i2cInfo.addrSize);

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_INVALID_DEVICE_TYPE
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_PREPAREADDRESS
                 * @userdata1        Address Size (aka Device Type)
                 * @userdata2        EEPROM chip
                 * @devdesc          The Device type not supported (addrSize)
                 * @custdesc         A problem was detected during the IPL of
                 *                   the system: Device type not supported.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               EEPROM_PREPAREADDRESS,
                                               EEPROM_INVALID_DEVICE_TYPE,
                                               i_i2cInfo.addrSize,
                                               i_i2cInfo.eepromRole,
                                               true /*Add HB SW Callout*/ );

                err->collectTrace( EEPROM_COMP_NAME );

                break;
        }

    } while( 0 );

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromPrepareAddress()" );

    return err;
} // end eepromPrepareAddress

}