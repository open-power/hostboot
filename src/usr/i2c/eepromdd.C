/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/eepromdd.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
 * @file eepromdd.C
 *
 * @brief Implementation of the EEPROM device driver,
 *      which will access various EEPROMs within the
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
#include <devicefw/driverif.H>
#include <i2c/eepromddreasoncodes.H>
#include <i2c/eepromif.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/i2cif.H>
#include "eepromdd.H"
#include "errlud_i2c.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------
mutex_t g_eepromMutex = MUTEX_INITIALIZER;

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_eeprom = NULL;
TRAC_INIT( & g_trac_eeprom, EEPROM_COMP_NAME, KILOBYTE );

trace_desc_t* g_trac_eepromr = NULL;
TRAC_INIT( & g_trac_eepromr, "EEPROMR", KILOBYTE );

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// ----------------------------------------------
// Defines
// ----------------------------------------------
#define MAX_BYTE_ADDR 2
#define EEPROM_MAX_NACK_RETRIES 2
// ----------------------------------------------


namespace EEPROM
{

// Register the perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_PROC,
                       eepromPerformOp );

// Register the perform Op with the routing code for DIMMs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_DIMM,
                       eepromPerformOp );

// Register the perform Op with the routing code for Memory Buffers.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_MEMBUF,
                       eepromPerformOp );

// Register the perform Op with the routing code for Nodes.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_NODE,
                       eepromPerformOp );

// ------------------------------------------------------------------
// eepromPerformOp
// ------------------------------------------------------------------
errlHndl_t eepromPerformOp( DeviceFW::OperationType i_opType,
                            TARGETING::Target * i_target,
                            void * io_buffer,
                            size_t & io_buflen,
                            int64_t i_accessType,
                            va_list i_args )
{
    errlHndl_t err = NULL;
    TARGETING::Target * i2cMasterTarget = NULL;
    eeprom_addr_t i2cInfo;

    i2cInfo.chip = va_arg( i_args, uint64_t );
    i2cInfo.offset = va_arg( i_args, uint64_t );

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromPerformOp()" );

    TRACUCOMP (g_trac_eeprom, ENTER_MRK"eepromPerformOp(): "
               "i_opType=%d, chip=%d, offset=%x, len=%d",
               (uint64_t) i_opType, i2cInfo.chip, i2cInfo.offset, io_buflen);

#ifdef __HOSTBOOT_RUNTIME
    // At runtime the OCC sensor cache will need to be diabled to avoid I2C
    // collisions. This bool indicates the sensor cache was enabled but is
    // now disabled and needs to be re-enabled when the eeprom op completes.
    bool scacDisabled = false;
#endif //__HOSTBOOT_RUNTIME

    do
    {
        // Read Attributes needed to complete the operation
        err = eepromReadAttributes( i_target,
                                    i2cInfo );

        if( err )
        {
            break;
        }

        // Check to see if we need to find a new target for
        // the I2C Master
        err = eepromGetI2CMasterTarget( i_target,
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
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromPerformOp(): Device Overflow! "
                       "C-p/e/dA=%d-%d/%d/0x%X, offset=0x%X, len=0x%X "
                       "devSizeKB=0x%X", i2cInfo.chip, i2cInfo.port,
                       i2cInfo.engine, i2cInfo.devAddr, i2cInfo.offset,
                       io_buflen, i2cInfo.devSize_KB);


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
                                               i2cInfo.offset,
                                               io_buflen       ),
                                           i2cInfo.devSize_KB,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( EEPROM_COMP_NAME );

            break;
        }

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
        if( i_opType == DeviceFW::READ )
        {
            err = eepromRead( i2cMasterTarget,
                              io_buffer,
                              io_buflen,
                              i2cInfo );

            if ( err )
            {
                break;
            }

        }
        else if( i_opType == DeviceFW::WRITE )
        {
            err = eepromWrite( i2cMasterTarget,
                               io_buffer,
                               io_buflen,
                               i2cInfo );

            if ( err )
            {
                break;
            }

        }
        else
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromPerformOp(): Invalid EEPROM Operation!");

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
                                           i2cInfo.chip,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( EEPROM_COMP_NAME );

            break;
        }
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
                               i2cInfo )
                             .addToLog(err);
    }

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromPerformOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end eepromPerformOp

#ifndef __HOSTBOOT_RUNTIME
//-------------------------------------------------------------------
//eepromPresence
//-------------------------------------------------------------------
bool eepromPresence ( TARGETING::Target * i_target )
{
    TRACUCOMP(g_trac_eeprom, ENTER_MRK"eepromPresence()");

    errlHndl_t err = NULL;
    bool l_present = false;
    TARGETING::Target * i2cMasterTarget = NULL;

    eeprom_addr_t i2cInfo;

    i2cInfo.chip = EEPROM::VPD_PRIMARY;
    i2cInfo.offset = 0;
    do
    {

        // Read Attributes needed to complete the operation
        err = eepromReadAttributes( i_target,
                                    i2cInfo );

        if( err )
        {
            TRACFCOMP(g_trac_eeprom,
                     ERR_MRK"Error in eepromPresence::eepromReadAttributes()");
            break;
        }

        // Check to see if we need to find a new target for
        // the I2C Master
        err = eepromGetI2CMasterTarget( i_target,
                                        i2cInfo,
                                        i2cMasterTarget );

        if( err )
        {
            TRACFCOMP(g_trac_eeprom,
                     ERR_MRK"Error in eepromPresence::eepromGetI2Cmaster()");
            break;
        }

        //Check for the target at the I2C level
        l_present = I2C::i2cPresence(i2cMasterTarget,
                          i2cInfo.port,
                          i2cInfo.engine,
                          i2cInfo.devAddr );

        if( !l_present )
        {
            TRACDCOMP(g_trac_eeprom,
                     ERR_MRK"i2cPresence returned false! chip NOT present!");
            break;
        }

    } while( 0 );

    // If there was an error commit the error log
    if( err )
    {
        errlCommit( err, I2C_COMP_ID );
    }

    TRACDCOMP(g_trac_eeprom, EXIT_MRK"eepromPresence()");
    return l_present;
}
#endif



// ------------------------------------------------------------------
// eepromPageOp
// ------------------------------------------------------------------
errlHndl_t eepromPageOp( TARGETING::Target * i_target,
                         bool i_switchPage,
                         bool i_lockMutex,
                         bool & io_pageLocked,
                         uint8_t i_desiredPage,
                         eeprom_addr_t i_i2cInfo )
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
                                eeprom_addr_t i_i2cInfo )
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
        TRACUCOMP( g_trac_eepromr,
                   "EEPROM READ  START : Chip: %02d : Offset %.2X : Len %d",
                   i_i2cInfo.chip, i_i2cInfo.offset, i_buflen );


        // Check to see if the Read operation straddles the EEPROM page
        //boundary
        l_boundaryCrossed = crossesEepromPageBoundary( i_i2cInfo.offset,
                                                       i_buflen,
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

        // Lock to sequence operations
        mutex_lock( &g_eepromMutex );

        // First Read. If Second read is necessary, this call will read
        // everything from the original offset up to the 256th byte
        err = eepromReadData( i_target,
                              o_buffer,
                              l_readBuflen,
                              &byteAddr,
                              byteAddrSize,
                              i_i2cInfo );
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




        TRACUCOMP( g_trac_eepromr,
                   "EEPROM READ  END   : Chip: %02d : Offset %.2X : Len %d : %016llx",
                   i_i2cInfo.chip, l_originalOffset, i_buflen,
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
    errlHndl_t err_NACK = NULL;

    TRACUCOMP(g_trac_eeprom,
            ENTER_MRK"eepromReadData()");
    do
    {
        /***********************************************************/
        /* Attempt read multiple times ONLY on NACK fails         */
        /***********************************************************/
        for (uint8_t retry = 0;
             retry <= EEPROM_MAX_NACK_RETRIES;
             retry++)
        {

            // Only write the byte address if we have data to write
            if( 0 != i_byteAddressSize )
            {
                // Use the I2C OFFSET Interface for the READ
                l_err = deviceOp( DeviceFW::READ,
                                i_target,
                                o_buffer,
                                i_buflen,
                                DEVICE_I2C_ADDRESS_OFFSET(
                                       i_i2cInfo.port,
                                       i_i2cInfo.engine,
                                       i_i2cInfo.devAddr,
                                       i_byteAddressSize,
                                       reinterpret_cast<uint8_t*>(i_byteAddress)));

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
                                DEVICE_I2C_ADDRESS( i_i2cInfo.port,
                                                    i_i2cInfo.engine,
                                                    i_i2cInfo.devAddr ) );

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
            else if ( l_err->reasonCode() != I2C::I2C_NACK_ONLY_FOUND )
            {
                // Only retry on NACK failures: break from retry loop
                TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromReadData(): Non-Nack "
                           "Error: rc=0x%X, tgt=0x%X, No Retry (retry=%d)",
                            l_err->reasonCode(),
                            TARGETING::get_huid(i_target), retry);

                l_err->collectTrace(EEPROM_COMP_NAME);

                // break from retry loop
                break;
            }
            else // Handle NACK error
            {
                // If op will be attempted again: save log and continue
                if ( retry < EEPROM_MAX_NACK_RETRIES )
                {
                    // Only save original NACK error
                    if ( err_NACK == NULL )
                    {
                        // Save original NACK error
                        err_NACK = l_err;

                        TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromReadData(): "
                                   "NACK Error rc=0x%X, eid=0x%X, tgt=0x%X, "
                                   "retry/MAX=%d/%d. Save error and retry",
                                   err_NACK->reasonCode(),
                                   err_NACK->eid(),
                                   TARGETING::get_huid(i_target),
                                   retry, EEPROM_MAX_NACK_RETRIES);

                        err_NACK->collectTrace(EEPROM_COMP_NAME);
                    }
                    else
                    {
                        // Add data to original NACK error
                        TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromReadData(): "
                                   "Another NACK Error rc=0x%X, eid=0x%X "
                                   "plid=0x%X, tgt=0x%X, retry/MAX=%d/%d. "
                                   "Delete error and retry",
                                   l_err->reasonCode(), l_err->eid(), l_err->plid(),
                                   TARGETING::get_huid(i_target),
                                   retry, EEPROM_MAX_NACK_RETRIES);

                        ERRORLOG::ErrlUserDetailsString(
                                  "Another NACK ERROR found")
                                  .addToLog(err_NACK);

                        // Delete this new NACK error
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
                               retry, EEPROM_MAX_NACK_RETRIES);

                    l_err->collectTrace(EEPROM_COMP_NAME);

                    // break from retry loop
                    break;
                }
            }

        } // end of retry loop

        // Handle saved NACK error, if any
        if (err_NACK)
        {
            if (l_err)
            {
                // commit original NACK error with new err PLID
                err_NACK->plid(l_err->plid());
                TRACFCOMP(g_trac_eeprom, "eepromReadData(): Committing saved NACK "
                          "l_err eid=0x%X with plid of returned err: 0x%X",
                          err_NACK->eid(), err_NACK->plid());

                ERRORLOG::ErrlUserDetailsTarget(i_target)
                                               .addToLog(err_NACK);

                errlCommit(err_NACK, EEPROM_COMP_ID);
            }
            else
            {
                // Since we eventually succeeded, delete original NACK error
                TRACFCOMP(g_trac_eeprom, "eepromReadData(): Op successful, "
                          "deleting saved NACK err eid=0x%X, plid=0x%X",
                          err_NACK->eid(), err_NACK->plid());

                delete err_NACK;
                err_NACK = NULL;
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
                   "EEPROM WRITE START : Chip: %02d : Offset %.2X : Len %d : %016llx",
                   i_i2cInfo.chip, i_i2cInfo.offset, io_buflen,
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
                                           i_i2cInfo.chip,
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
                "loop=%d, writeBuflen=%d, offset=0x%X, bAS=%d, diffs=%d/%d",
                i_i2cInfo.port, i_i2cInfo.engine, i_i2cInfo.devAddr,
                i, l_writeBuflen, i_i2cInfo.offset, byteAddrSize,
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

            TRACUCOMP(g_trac_eeprom,"eepromWrite() Loop %d End: "
                      "writeBuflen=%d, offset=0x%X, t_b_w=%d, io_buflen=%d",
                      i, l_writeBuflen, i_i2cInfo.offset,
                      total_bytes_written, io_buflen);

        } // end of write for-loop

        // Release mutex lock
        mutex_unlock( &g_eepromMutex );
        unlock = false;


        // Set how much data was actually written
        io_buflen = total_bytes_written;


        TRACSCOMP( g_trac_eepromr,
                   "EEPROM WRITE END   : Chip: %02d : Offset %.2X : Len %d",
                   i_i2cInfo.chip, i_i2cInfo.offset, io_buflen );
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
    errlHndl_t err_NACK = NULL;
    do
    {
         /***********************************************************/
         /* Attempt write multiple times ONLY on NACK fails         */
         /***********************************************************/
        for (uint8_t retry = 0;
              retry <= EEPROM_MAX_NACK_RETRIES;
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
                                            i_byteAddress)));


             if ( err == NULL )
             {
                 // Operation completed successfully
                 // break from retry loop
                 break;
             }
             else if ( err->reasonCode() != I2C::I2C_NACK_ONLY_FOUND )
             {
                 // Only retry on NACK failures: break from retry loop
                 TRACFCOMP(g_trac_eeprom, ERR_MRK"eepromWriteData(): I2C "
                           "Write Non-NACK fail %d/%d/0x%X, "
                           "ldl=%d, offset=0x%X, aS=%d, retry=%d",
                           i_i2cInfo.port, i_i2cInfo.engine,
                           i_i2cInfo.devAddr, i_dataLen,
                           i_i2cInfo.offset, i_i2cInfo.addrSize, retry);

                 err->collectTrace(EEPROM_COMP_NAME);

                 // break from retry loop
                 break;
             }
             else // Handle NACK error
             {
                 TRACFCOMP(g_trac_eeprom, ERR_MRK"eepromWriteData(): I2C "
                           "Write NACK fail %d/%d/0x%X, "
                           "ldl=%d, offset=0x%X, aS=%d, writePageSize = %x",
                           i_i2cInfo.port, i_i2cInfo.engine,
                           i_i2cInfo.devAddr, i_dataLen,
                           i_i2cInfo.offset, i_i2cInfo.addrSize,
                           i_i2cInfo.writePageSize);

                 // If op will be attempted again: save error and continue
                 if ( retry < EEPROM_MAX_NACK_RETRIES )
                 {
                     // Only save original NACK error
                     if ( err_NACK == NULL )
                     {
                         // Save original NACK error
                         err_NACK = err;

                         TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromWriteData(): "
                                    "Error rc=0x%X, eid=0x%X plid=0x%X, "
                                    "tgt=0x%X, retry/MAX=%d/%d. Save error "
                                    "and retry",
                                    err_NACK->reasonCode(),
                                    err_NACK->eid(),
                                    err_NACK->plid(),
                                    TARGETING::get_huid(i_target),
                                    retry, EEPROM_MAX_NACK_RETRIES);

                         err_NACK->collectTrace(EEPROM_COMP_NAME);
                     }
                     else
                     {
                         // Add data to original NACK error
                         TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromWriteData(): "
                                    "Another NACK Error rc=0x%X, eid=0x%X "
                                    "plid=0x%X, tgt=0x%X, retry/MAX=%d/%d. "
                                    "Delete error and retry",
                                    err->reasonCode(), err->eid(),
                                    err->plid(),
                                    TARGETING::get_huid(i_target),
                                    retry, EEPROM_MAX_NACK_RETRIES);

                         ERRORLOG::ErrlUserDetailsString(
                                   "Another NACK ERROR found")
                                   .addToLog(err_NACK);

                         // Delete this new NACK error
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
                                retry, EEPROM_MAX_NACK_RETRIES);

                     err->collectTrace(EEPROM_COMP_NAME);

                     // break from retry loop
                     break;
                 }
             }

         } // end of retry loop
         /***********************************************************/

         // Handle saved NACK errors, if any
         if (err_NACK)
         {
             if (err)
             {
                 // commit original NACK error with new err PLID
                 err_NACK->plid(err->plid());
                 TRACFCOMP(g_trac_eeprom, "eepromWriteData(): Committing saved "
                           "NACK err eid=0x%X with plid of returned err: "
                           "0x%X",
                           err_NACK->eid(), err_NACK->plid());

                 ERRORLOG::ErrlUserDetailsTarget(i_target)
                                                 .addToLog(err_NACK);

                 errlCommit(err_NACK, EEPROM_COMP_ID);
             }
             else
             {
                 // Since we eventually succeeded, delete original NACK error
                 TRACFCOMP(g_trac_eeprom, "eepromWriteData(): Op successful, "
                           "deleting saved NACK err eid=0x%X, plid=0x%X",
                           err_NACK->eid(), err_NACK->plid());

                 delete err_NACK;
                 err_NACK = NULL;
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
                                  eeprom_addr_t i_i2cInfo )
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
                                               i_i2cInfo.chip,
                                               true /*Add HB SW Callout*/ );

                err->collectTrace( EEPROM_COMP_NAME );

                break;
        }

    } while( 0 );

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromPrepareAddress()" );

    return err;
} // end eepromPrepareAddress


// ------------------------------------------------------------------
// eepromReadAttributes
// ------------------------------------------------------------------
errlHndl_t eepromReadAttributes ( TARGETING::Target * i_target,
                                  eeprom_addr_t & o_i2cInfo )
{
    errlHndl_t err = NULL;
    bool fail_reading_attribute = false;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromReadAttributes()" );

    // These variables will be used to hold the EEPROM attribute data
    // Note:  each 'EepromVpd' struct is kept the same via the attributes
    //        so will be copying each to eepromData to save code space
    TARGETING::EepromVpdPrimaryInfo eepromData;

    do
    {

        switch (o_i2cInfo.chip )
        {
            case VPD_PRIMARY:
                if( !( i_target->
                         tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>
                             ( eepromData ) ) )

                {
                    fail_reading_attribute = true;
                }
                break;

            case VPD_BACKUP:

                if( !(i_target->
                        tryGetAttr<TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO>
                        ( reinterpret_cast<
                            TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO_type&>
                                ( eepromData) ) ) )
                {
                    fail_reading_attribute = true;
                }
                break;

            case SBE_PRIMARY:
                if( !(i_target->
                        tryGetAttr<TARGETING::ATTR_EEPROM_SBE_PRIMARY_INFO>
                        ( reinterpret_cast<
                            TARGETING::ATTR_EEPROM_SBE_PRIMARY_INFO_type&>
                                ( eepromData) ) ) )
                {
                    fail_reading_attribute = true;
                }
                break;

            case SBE_BACKUP:
                if( (!i_target->
                        tryGetAttr<TARGETING::ATTR_EEPROM_SBE_BACKUP_INFO>
                        ( reinterpret_cast<
                            TARGETING::ATTR_EEPROM_SBE_BACKUP_INFO_type&>
                                ( eepromData) ) ) )
                {
                    fail_reading_attribute = true;
                }
                break;

            default:
                TRACFCOMP( g_trac_eeprom,ERR_MRK"eepromReadAttributes() - "
                           "Invalid chip (%d) to read attributes from!",
                            o_i2cInfo.chip );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_INVALID_CHIP
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        EEPROM Chip
                 * @userdata2        HUID of target
                 * @devdesc          Invalid EEPROM chip to access
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           EEPROM_READATTRIBUTES,
                                           EEPROM_INVALID_CHIP,
                                           o_i2cInfo.chip,
                                           TARGETING::get_huid(i_target),
                                           true /*Add HB SW Callout*/ );

                err->collectTrace( EEPROM_COMP_NAME );

                break;
        }

        // Check if Attribute Data was found
        if( fail_reading_attribute == true )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromReadAttributes() - ERROR reading "
                       "attributes for chip %d!",
                       o_i2cInfo.chip );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_ATTR_INFO_NOT_FOUND
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        HUID of target
                 * @userdata2        EEPROM chip
                 * @devdesc          EEPROM attribute was not found
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_READATTRIBUTES,
                                    EEPROM_ATTR_INFO_NOT_FOUND,
                                    TARGETING::get_huid(i_target),
                                    o_i2cInfo.chip);

                // Could be FSP or HB code's fault
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_MED);
                err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                         HWAS::SRCI_PRIORITY_MED);

                err->collectTrace( EEPROM_COMP_NAME );

                break;

        }

        // Successful reading of Attribute, so extract the data
        o_i2cInfo.port           = eepromData.port;
        o_i2cInfo.devAddr        = eepromData.devAddr;
        o_i2cInfo.engine         = eepromData.engine;
        o_i2cInfo.i2cMasterPath  = eepromData.i2cMasterPath;
        o_i2cInfo.writePageSize  = eepromData.writePageSize;
        o_i2cInfo.devSize_KB     = eepromData.maxMemorySizeKB;
        o_i2cInfo.writeCycleTime = eepromData.writeCycleTime;

        // Convert attribute info to eeprom_addr_size_t enum
        if ( eepromData.byteAddrOffset == 0x3 )
        {
            o_i2cInfo.addrSize = ONE_BYTE_ADDR;
        }
        else if ( eepromData.byteAddrOffset == 0x2 )
        {
            o_i2cInfo.addrSize = TWO_BYTE_ADDR;
        }
        else if ( eepromData.byteAddrOffset == 0x1 )
        {
            o_i2cInfo.addrSize = ONE_BYTE_ADDR_PAGESELECT;
        }
        else if ( eepromData.byteAddrOffset == 0x0 )
        {
            o_i2cInfo.addrSize = ZERO_BYTE_ADDR;
        }
        else
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromReadAttributes() - INVALID ADDRESS "
                       "OFFSET SIZE %d!",
                       o_i2cInfo.addrSize );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_INVALID_ADDR_OFFSET_SIZE
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        HUID of target
                 * @userdata2        Address Offset Size
                 * @devdesc          Invalid address offset size
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_READATTRIBUTES,
                                    EEPROM_INVALID_ADDR_OFFSET_SIZE,
                                    TARGETING::get_huid(i_target),
                                    o_i2cInfo.addrSize,
                                    true /*Add HB SW Callout*/ );

                err->collectTrace( EEPROM_COMP_NAME );

                break;

        }

    } while( 0 );

    TRACUCOMP(g_trac_eeprom,"eepromReadAttributes() tgt=0x%X, %d/%d/0x%X "
              "wpw=0x%X, dsKb=0x%X, aS=%d (%d), wct=%d",
              TARGETING::get_huid(i_target),
              o_i2cInfo.port, o_i2cInfo.engine, o_i2cInfo.devAddr,
              o_i2cInfo.writePageSize, o_i2cInfo.devSize_KB,
              o_i2cInfo.addrSize, eepromData.byteAddrOffset,
              o_i2cInfo.writeCycleTime);


    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromReadAttributes()" );

    return err;
} // end eepromReadAttributes


// ------------------------------------------------------------------
// eepromGetI2CMasterTarget
// ------------------------------------------------------------------
errlHndl_t eepromGetI2CMasterTarget ( TARGETING::Target * i_target,
                                      eeprom_addr_t i_i2cInfo,
                                      TARGETING::Target * &o_target )
{
    errlHndl_t err = NULL;
    o_target = NULL;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromGetI2CMasterTarget()" );

    do
    {
        TARGETING::TargetService& tS = TARGETING::targetService();

        // The path from i_target to its I2C Master was read from the
        // attribute via eepromReadAttributes() and passed to this function
        // in i_i2cInfo.i2cMasterPath

        // check that the path exists
        bool exists = false;
        tS.exists( i_i2cInfo.i2cMasterPath,
                   exists );

        if( !exists )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromGetI2CMasterTarget() - "
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
             * @reasoncode       EEPROM_I2C_MASTER_PATH_ERROR
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         EEPROM_GETI2CMASTERTARGET
             * @userdata1[00:31] Attribute Chip Type Enum
             * @userdata1[32:63] HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          I2C master entity path doesn't exist.
             */
            err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_GETI2CMASTERTARGET,
                                EEPROM_I2C_MASTER_PATH_ERROR,
                                TWO_UINT32_TO_UINT64(
                                    i_i2cInfo.chip,
                                    TARGETING::get_huid(i_target) ),
                                l_epCompressed,
                                true /*Add HB SW Callout*/ );

            err->collectTrace( EEPROM_COMP_NAME );

            ERRORLOG::ErrlUserDetailsString(
                i_i2cInfo.i2cMasterPath.toString()).addToLog(err);

            break;
        }

        // Since it exists, convert to a target
        o_target = tS.toTarget( i_i2cInfo.i2cMasterPath );

        if( NULL == o_target )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromGetI2CMasterTarget() - I2C Master "
                              "Path target was NULL!" );

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
             * @reasoncode       EEPROM_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         EEPROM_GETI2CMASTERTARGET
             * @userdata1[00:31] Attribute Chip Type Enum
             * @userdata1[32:63] HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          I2C master path target is null.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           EEPROM_GETI2CMASTERTARGET,
                                           EEPROM_TARGET_NULL,
                                           TWO_UINT32_TO_UINT64(
                                               i_i2cInfo.chip,
                                               TARGETING::get_huid(i_target) ),
                                           l_epCompressed,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( EEPROM_COMP_NAME );

            ERRORLOG::ErrlUserDetailsString(
                i_i2cInfo.i2cMasterPath.toString()).addToLog(err);

            break;
        }

    } while( 0 );

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromGetI2CMasterTarget()" );

    return err;
} // end eepromGetI2CMasterTarget


/**
 * @brief Compare predicate for EepromInfo_t
 */
class isSameEeprom
{
  public:
    isSameEeprom( EepromInfo_t& i_first )
    : iv_first(i_first)
    {}

    bool operator()( EepromInfo_t& i_second )
    {
        return( (iv_first.i2cMaster == i_second.i2cMaster)
                && (iv_first.engine == i_second.engine)
                && (iv_first.port == i_second.port)
                && (iv_first.devAddr == i_second.devAddr) );
    }
  private:
    EepromInfo_t& iv_first;
};

/**
 * @brief Add any new EEPROMs associated with this target
 *   to the list
 * @param[in] i_list : list of previously discovered EEPROMs
 * @param[out] i_targ : owner of EEPROMs to add
 */
void add_to_list( std::list<EepromInfo_t>& i_list,
                  TARGETING::Target* i_targ )
{
    TRACDCOMP(g_trac_eeprom,"Targ %.8X",TARGETING::get_huid(i_targ));

    // try all defined types of EEPROMs
    for( eeprom_chip_types_t eep_type = FIRST_CHIP_TYPE;
         eep_type < LAST_CHIP_TYPE;
         eep_type = static_cast<eeprom_chip_types_t>(eep_type+1) )
    {
        bool found_eep = false;
        TARGETING::EepromVpdPrimaryInfo eepromData;

        switch( eep_type )
        {
            case VPD_PRIMARY:
                if( i_targ->
                    tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>
                    ( eepromData ) )

                {
                    found_eep = true;
                }
                break;

            case VPD_BACKUP:
                if( i_targ->
                    tryGetAttr<TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO>
                    ( reinterpret_cast<
                      TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO_type&>
                      ( eepromData) ) )
                {
                    found_eep = true;
                }
                break;

            case SBE_PRIMARY:
                if( i_targ->
                    tryGetAttr<TARGETING::ATTR_EEPROM_SBE_PRIMARY_INFO>
                    ( reinterpret_cast<
                      TARGETING::ATTR_EEPROM_SBE_PRIMARY_INFO_type&>
                      ( eepromData) ) )
                {
                    found_eep = true;
                }
                break;

            case SBE_BACKUP:
                if( i_targ->
                    tryGetAttr<TARGETING::ATTR_EEPROM_SBE_BACKUP_INFO>
                    ( reinterpret_cast<
                      TARGETING::ATTR_EEPROM_SBE_BACKUP_INFO_type&>
                      ( eepromData) ) )
                {
                    found_eep = true;
                }
                break;

            case LAST_CHIP_TYPE:
                //only included to catch additional types later on
                found_eep = false;
                break;
        }

        if( !found_eep )
        {
            //nothing to do
            continue;
        }

        // check that the path exists
        bool exists = false;
        TARGETING::targetService().exists( eepromData.i2cMasterPath,
                                           exists );
        if( !exists )
        {
            continue;
        }

        // Since it exists, convert to a target
        TARGETING::Target* i2cm = TARGETING::targetService()
          .toTarget( eepromData.i2cMasterPath );
        if( NULL == i2cm )
        {
            //not sure how this could happen, but just skip it
            continue;
        }

        // ignore anything with junk data
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        if( i2cm == sys )
        {
            continue;
        }

        // copy all the data out
        EepromInfo_t eep_info;
        eep_info.i2cMaster = i2cm;
        eep_info.engine = eepromData.engine;
        eep_info.port = eepromData.port;
        eep_info.devAddr = eepromData.devAddr;
        eep_info.device = eep_type;
        eep_info.assocTarg = i_targ;
        eep_info.sizeKB = eepromData.maxMemorySizeKB;
        eep_info.addrBytes = eepromData.byteAddrOffset;
        //one more lookup for the speed
        TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speeds;
        if( i2cm->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
            (speeds) )
        {
            if( (eep_info.engine > I2C_BUS_MAX_ENGINE(speeds))
                || (eep_info.port > I2C_BUS_MAX_PORT(speeds)) )
            {
                continue;
            }
            eep_info.busFreq = speeds[eep_info.engine][eep_info.port];
            eep_info.busFreq *= 1000; //convert KHz->Hz
        }
        else
        {
            continue;
        }

        // check if the eeprom is already in our list
        std::list<EepromInfo_t>::iterator oldeep =
          find_if( i_list.begin(), i_list.end(),
                   isSameEeprom(eep_info) );
        if( oldeep == i_list.end() )
        {
            // didn't find it in our list so stick it into the output list
            i_list.push_back(eep_info);
            TRACDCOMP(g_trac_eeprom,"--Adding i2cm=%.8X, type=%d, eng=%d, port=%d, addr=%.2X for %.8X", TARGETING::get_huid(i2cm),eep_type,eepromData.engine,eepromData.port, eep_info.devAddr,  TARGETING::get_huid(eep_info.assocTarg));
        }
        else
        {
            TRACDCOMP(g_trac_eeprom,"--Skipping duplicate i2cm=%.8X, type=%d, eng=%d, port=%d, addr=%.2X for %.8X", TARGETING::get_huid(i2cm),eep_type,eepromData.engine,eepromData.port, eep_info.devAddr,  TARGETING::get_huid(eep_info.assocTarg));
        }
    }
}

/**
 * @brief Return a set of information related to every unique
 *        EEPROM in the system
 */
void getEEPROMs( std::list<EepromInfo_t>& o_info )
{
    TRACDCOMP(g_trac_eeprom,">>getEEPROMs()");

    // We only want to have a single entry in our list per
    //  physical EEPROM.  Since multiple targets could be
    //  using the same EEPROM, we need to have a hierarchy
    //  of importance.
    //    node/planar > proc > membuf > dimm

    // predicate to only look for this that are actually there
    TARGETING::PredicateHwas isPresent;
    isPresent.reset().poweredOn(true).present(true);

    // #1 - Nodes
    TARGETING::PredicateCTM nodes( TARGETING::CLASS_ENC,
                                   TARGETING::TYPE_NODE,
                                   TARGETING::MODEL_NA );
    TARGETING::PredicatePostfixExpr l_nodeFilter;
    l_nodeFilter.push(&isPresent).push(&nodes).And();
    TARGETING::TargetRangeFilter node_itr( TARGETING::targetService().begin(),
                                           TARGETING::targetService().end(),
                                           &l_nodeFilter );
    for( ; node_itr; ++node_itr )
    {
        add_to_list( o_info, *node_itr );
    }

    // #2 - Procs
    TARGETING::PredicateCTM procs( TARGETING::CLASS_CHIP,
                                   TARGETING::TYPE_PROC,
                                   TARGETING::MODEL_NA );
    TARGETING::PredicatePostfixExpr l_procFilter;
    l_procFilter.push(&isPresent).push(&procs).And();
    TARGETING::TargetRangeFilter proc_itr( TARGETING::targetService().begin(),
                                           TARGETING::targetService().end(),
                                           &l_procFilter );
    for( ; proc_itr; ++proc_itr )
    {
        add_to_list( o_info, *proc_itr );
    }

    // #3 - Membufs
    TARGETING::PredicateCTM membs( TARGETING::CLASS_CHIP,
                                   TARGETING::TYPE_MEMBUF,
                                   TARGETING::MODEL_NA );
    TARGETING::PredicatePostfixExpr l_membFilter;
    l_membFilter.push(&isPresent).push(&membs).And();
    TARGETING::TargetRangeFilter memb_itr( TARGETING::targetService().begin(),
                                           TARGETING::targetService().end(),
                                           &l_membFilter );
    for( ; memb_itr; ++memb_itr )
    {
        add_to_list( o_info, *memb_itr );
    }

    // #4 - DIMMs
    TARGETING::PredicateCTM dimms( TARGETING::CLASS_LOGICAL_CARD,
                                   TARGETING::TYPE_DIMM,
                                   TARGETING::MODEL_NA );
    TARGETING::PredicatePostfixExpr l_dimmFilter;
    l_dimmFilter.push(&isPresent).push(&dimms).And();
    TARGETING::TargetRangeFilter dimm_itr( TARGETING::targetService().begin(),
                                           TARGETING::targetService().end(),
                                           &l_dimmFilter );
    for( ; dimm_itr; ++dimm_itr )
    {
        add_to_list( o_info, *dimm_itr );
    }

    TRACDCOMP(g_trac_eeprom,"<<getEEPROMs()");
}


} // end namespace EEPROM
