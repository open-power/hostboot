/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/eepromdd.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
    TARGETING::Target * theTarget = NULL;
    eeprom_addr_t i2cInfo;

    i2cInfo.chip = va_arg( i_args, uint64_t );
    i2cInfo.offset = va_arg( i_args, uint64_t );

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromPerformOp()" );

    TRACUCOMP (g_trac_eeprom, ENTER_MRK"eepromPerformOp(): "
               "i_opType=%d, chip=%d, offset=%d, len=%d",
               (uint64_t) i_opType, i2cInfo.chip, i2cInfo.offset, io_buflen);

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
                                        theTarget );

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


        // Do the read or write
        if( i_opType == DeviceFW::READ )
        {
            err = eepromRead( theTarget,
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
            err = eepromWrite( theTarget,
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


// ------------------------------------------------------------------
// eepromRead
// ------------------------------------------------------------------
errlHndl_t eepromRead ( TARGETING::Target * i_target,
                        void * o_buffer,
                        size_t i_buflen,
                        eeprom_addr_t i_i2cInfo )
{
    errlHndl_t err = NULL;
    errlHndl_t err_NACK = NULL;
    uint8_t byteAddr[MAX_BYTE_ADDR];
    size_t byteAddrSize = 0;
    bool unlock = false;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromRead()" );

    do
    {
        TRACSCOMP( g_trac_eepromr,
                   "EEPROM READ  START : Chip: %02d : Offset %.2X : Len %d",
                   i_i2cInfo.chip, i_i2cInfo.offset, i_buflen );

        err = eepromPrepareAddress( &byteAddr,
                                    byteAddrSize,
                                    i_i2cInfo );

        if( err )
        {
            break;
        }

        // Lock to sequence operations
        mutex_lock( &g_eepromMutex );
        unlock = true;

        /***********************************************************/
        /* Attempt read multiple times ONLY on NACK fails         */
        /***********************************************************/
        for (uint8_t retry = 0;
             retry <= EEPROM_MAX_NACK_RETRIES;
             retry++)
        {

            // Only write the byte address if we have data to write
            if( 0 != byteAddrSize )
            {
                // Use the I2C OFFSET Interface for the READ
                err = deviceOp( DeviceFW::READ,
                                i_target,
                                o_buffer,
                                i_buflen,
                                DEVICE_I2C_ADDRESS_OFFSET(
                                       i_i2cInfo.port,
                                       i_i2cInfo.engine,
                                       i_i2cInfo.devAddr,
                                       byteAddrSize,
                                       reinterpret_cast<uint8_t*>(&byteAddr)));

                if( err )
                {
                    TRACFCOMP(g_trac_eeprom,
                              ERR_MRK"eepromRead(): I2C Read-Offset failed on "
                              "%d/%d/0x%X aS=%d",
                              i_i2cInfo.port, i_i2cInfo.engine,
                              i_i2cInfo.devAddr, byteAddrSize);
                    TRACFBIN(g_trac_eeprom, "byteAddr[]",
                             &byteAddr, byteAddrSize);

                    // Don't break here -- error handled below
                }
            }
            else
            {
                // Do the actual read via I2C
                err = deviceOp( DeviceFW::READ,
                                i_target,
                                o_buffer,
                                i_buflen,
                                DEVICE_I2C_ADDRESS( i_i2cInfo.port,
                                                    i_i2cInfo.engine,
                                                    i_i2cInfo.devAddr ) );

                if( err )
                {
                    TRACFCOMP(g_trac_eeprom,
                              ERR_MRK"eepromRead(): I2C Read failed on "
                              "%d/%d/0x%0X", i_i2cInfo.port, i_i2cInfo.engine,
                              i_i2cInfo.devAddr);

                    // Don't break here -- error handled below
                }
            }

            if ( err == NULL )
            {
                // Operation completed successfully
                // break from retry loop
                break;
            }
            else if ( err->reasonCode() != I2C::I2C_NACK_ONLY_FOUND )
            {
                // Only retry on NACK failures: break from retry loop
                TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromRead(): Non-Nack "
                           "Error: rc=0x%X, tgt=0x%X, No Retry (retry=%d)",
                            err->reasonCode(),
                            TARGETING::get_huid(i_target), retry);

                err->collectTrace(EEPROM_COMP_NAME);

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
                        err_NACK = err;

                        TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromRead(): "
                                   "NACK Error rc=0x%X, eid=%d, tgt=0x%X, "
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
                        TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromRead(): "
                                   "Another NACK Error rc=0x%X, eid=0x%X "
                                   "plid=0x%X, tgt=0x%X, retry/MAX=%d/%d. "
                                   "Delete error and retry",
                                   err->reasonCode(), err->eid(), err->plid(),
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
                    TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromRead(): "
                               "Error rc=0x%X, eid=%d, tgt=0x%X. No More "
                               "Retries (retry/MAX=%d/%d). Returning Error",
                               err->reasonCode(), err->eid(),
                               TARGETING::get_huid(i_target),
                               retry, EEPROM_MAX_NACK_RETRIES);

                    err->collectTrace(EEPROM_COMP_NAME);

                    // break from retry loop
                    break;
                }
            }

        } // end of retry loop

        // Handle saved NACK error, if any
        if (err_NACK)
        {
            if (err)
            {
                // commit original NACK error with new err PLID
                err_NACK->plid(err->plid());
                TRACFCOMP(g_trac_eeprom, "eepromRead(): Committing saved NACK "
                          "err eid=0x%X with plid of returned err: 0x%X",
                          err_NACK->eid(), err_NACK->plid());

                ERRORLOG::ErrlUserDetailsTarget(i_target)
                                               .addToLog(err_NACK);

                errlCommit(err_NACK, EEPROM_COMP_ID);
            }
            else
            {
                // Since we eventually succeeded, delete original NACK error
                TRACFCOMP(g_trac_eeprom, "eepromRead(): Op successful, "
                          "deleting saved NACK err eid=0x%X, plid=0x%X",
                          err_NACK->eid(), err_NACK->plid());

                delete err_NACK;
                err_NACK = NULL;
            }
        }


        mutex_unlock( &g_eepromMutex );
        unlock = false;

        TRACSCOMP( g_trac_eepromr,
                   "EEPROM READ  END   : Chip: %02d : Offset %.2X : Len %d : %016llx",
                   i_i2cInfo.chip, i_i2cInfo.offset, i_buflen,
                   *((uint64_t*)o_buffer) );

    } while( 0 );

    // Catch it if we break out early.
    if( unlock )
    {
        mutex_unlock( & g_eepromMutex );
    }

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromRead()" );

    return err;
} // end eepromRead


// ------------------------------------------------------------------
// eepromWrite
// ------------------------------------------------------------------
errlHndl_t eepromWrite ( TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t io_buflen,
                         eeprom_addr_t i_i2cInfo )
{
    errlHndl_t err = NULL;
    errlHndl_t err_NACK = NULL;
    uint8_t byteAddr[MAX_BYTE_ADDR];
    size_t byteAddrSize = 0;
    uint8_t * newBuffer = NULL;
    bool needFree = false;
    bool unlock = false;
    uint32_t data_left = 0;
    uint32_t diff_wps = 0;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromWrite()" );

    do
    {
        TRACSCOMP( g_trac_eepromr,
                   "EEPROM WRITE START : Chip: %02d : Offset %.2X : Len %d : %016llx",
                   i_i2cInfo.chip, i_i2cInfo.offset, io_buflen,
                   *((uint64_t*)io_buffer) );

        err = eepromPrepareAddress( &byteAddr,
                                    byteAddrSize,
                                    i_i2cInfo );

        if( err )
        {
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


        for ( uint64_t i = 0 ;
              total_bytes_written < io_buflen ;
              i++ )
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


            // Setup offset/address parms
            err = eepromPrepareAddress(  &byteAddr,
                                         byteAddrSize,
                                         i_i2cInfo );

            if( err )
            {
                break;
            }

            TRACUCOMP(g_trac_eeprom,"eepromWrite() Loop: %d/%d/0x%X "
                "loop=%d, l_d_l=%d, offset=0x%X, bAS=%d, diffs=%d/%d",
                i_i2cInfo.port, i_i2cInfo.engine, i_i2cInfo.devAddr,
                i, loop_data_length, i_i2cInfo.offset, byteAddrSize,
                data_left, diff_wps);

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
                                newBuffer,
                                loop_data_length,
                                DEVICE_I2C_ADDRESS_OFFSET(
                                               i_i2cInfo.port,
                                               i_i2cInfo.engine,
                                               i_i2cInfo.devAddr,
                                               byteAddrSize,
                                               reinterpret_cast<uint8_t*>(
                                               &byteAddr)));


                if ( err == NULL )
                {
                    // Operation completed successfully
                    // break from retry loop
                    break;
                }
                else if ( err->reasonCode() != I2C::I2C_NACK_ONLY_FOUND )
                {
                    // Only retry on NACK failures: break from retry loop
                    TRACFCOMP(g_trac_eeprom, ERR_MRK"eepromWrite(): I2C "
                              "Write Non-NACK fail %d/%d/0x%X loop=%d, "
                              "ldl=%d, offset=0x%X, aS=%d, retry=%d",
                              i_i2cInfo.port, i_i2cInfo.engine,
                              i_i2cInfo.devAddr, i, loop_data_length,
                              i_i2cInfo.offset, i_i2cInfo.addrSize, retry);

                    err->collectTrace(EEPROM_COMP_NAME);

                    // break from retry loop
                    break;
                }
                else // Handle NACK error
                {
                    TRACFCOMP(g_trac_eeprom, ERR_MRK"eepromWrite(): I2C "
                              "Write NACK fail %d/%d/0x%X loop=%d, "
                              "ldl=%d, offset=0x%X, aS=%d",
                              i_i2cInfo.port, i_i2cInfo.engine,
                              i_i2cInfo.devAddr, i, loop_data_length,
                              i_i2cInfo.offset, i_i2cInfo.addrSize);

                    // If op will be attempted again: save error and continue
                    if ( retry < EEPROM_MAX_NACK_RETRIES )
                    {
                        // Only save original NACK error
                        if ( err_NACK == NULL )
                        {
                            // Save original NACK error
                            err_NACK = err;

                            TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromWrite(): "
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
                            TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromWrite(): "
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
                        TRACFCOMP( g_trac_eeprom, ERR_MRK"eepromWrite(): "
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
                    TRACFCOMP(g_trac_eeprom, "eepromWrite(): Committing saved "
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
                    TRACFCOMP(g_trac_eeprom, "eepromWrite(): Op successful, "
                              "deleting saved NACK err eid=0x%X, plid=0x%X",
                              err_NACK->eid(), err_NACK->plid());

                    delete err_NACK;
                    err_NACK = NULL;
                }
            }

            if ( err )
            {
                // Can't assume that anything was written if
                // there was an error, so no update to total_bytes_written
                // for this loop
                break;
            }

            // Wait for EEPROM to write data to its internal memory
            // i_i2cInfo.writeCycleTime value in milliseconds
            nanosleep(0, i_i2cInfo.writeCycleTime * NS_PER_MSEC);

            // Update how much data was written
            total_bytes_written += loop_data_length;

            // Update offset
            i_i2cInfo.offset += loop_data_length;

            TRACUCOMP(g_trac_eeprom,"eepromWrite() Loop %d End: "
                      "l_d_l=%d, offset=0x%X, t_b_w=%d, io_buflen=%d",
                      i, loop_data_length, i_i2cInfo.offset,
                      total_bytes_written, io_buflen);

        } // end of write for-loop

        // Release mutex lock
        mutex_unlock( &g_eepromMutex );
        unlock = false;

        // Set how much data was actually written
        io_buflen = total_bytes_written;

        if( err )
        {
            // Leave do-while loop
            break;
        }

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

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromWrite()" );

    return err;

} // end eepromWrite


// ------------------------------------------------------------------
// eepromPrepareAddress
// ------------------------------------------------------------------
errlHndl_t eepromPrepareAddress ( void * io_buffer,
                                  size_t & o_bufSize,
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
        o_i2cInfo.port          = eepromData.port;
        o_i2cInfo.devAddr       = eepromData.devAddr;
        o_i2cInfo.engine        = eepromData.engine;
        o_i2cInfo.i2cMasterPath = eepromData.i2cMasterPath;
        o_i2cInfo.writePageSize = eepromData.writePageSize;
        o_i2cInfo.devSize_KB    = eepromData.maxMemorySizeKB;
        o_i2cInfo.writeCycleTime = eepromData.writeCycleTime;

        // Convert attribute info to eeprom_addr_size_t enum
        if ( eepromData.byteAddrOffset == 0x2 )
        {
            o_i2cInfo.addrSize = TWO_BYTE_ADDR;
        }
        else if ( eepromData.byteAddrOffset == 0x1 )
        {
            o_i2cInfo.addrSize = ONE_BYTE_ADDR;
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

    TRACUCOMP(g_trac_eeprom,"eepromReadAttributes() %d/%d/0x%X "
              "wpw=0x%X, dsKb=0x%X, aS=%d (%d), wct=%d",
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
        if( TARGETING::TYPE_DIMM == i_target->getAttr<TARGETING::ATTR_TYPE>() )
        {
            TARGETING::TargetService& tS = TARGETING::targetService();

            // For DIMMs we need to get the parent that contains the
            // I2C Master that talks to the DIMM EEPROM

            // The path was read from the attribute via eepromReadAttributes()
            // and passed to this function in i_i2cInfo


            // check that the path exists
            bool exists = false;
            tS.exists( i_i2cInfo.i2cMasterPath,
                       exists );

            if( !exists )
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromGetI2CMasterTarget() - i2cMasterPath attribute path "
                           "doesn't exist!" );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_DIMM_I2C_MASTER_PATH_ERROR
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_GETI2CMASTERTARGET
                 * @userdata1        Attribute Chip Type Enum
                 * @userdata2        HUID of target
                 * @devdesc          DIMM I2C master entity path doesn't exist.
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_GETI2CMASTERTARGET,
                                    EEPROM_DIMM_I2C_MASTER_PATH_ERROR,
                                    i_i2cInfo.chip,
                                    TARGETING::get_huid(i_target),
                                    true /*Add HB SW Callout*/ );

                err->collectTrace( EEPROM_COMP_NAME );

                break;
            }

            // Since it exists, convert to a target
            o_target = tS.toTarget( i_i2cInfo.i2cMasterPath );

            if( NULL == o_target )
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromGetI2CMasterTarget() - I2C Master "
                                  "Path target was NULL!" );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_TARGET_NULL
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_GETI2CMASTERTARGET
                 * @userdata1        Attribute Chip Type Enum
                 * @userdata2        HUID of target
                 * @devdesc          I2C master path target is null.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               EEPROM_GETI2CMASTERTARGET,
                                               EEPROM_TARGET_NULL,
                                               i_i2cInfo.chip,
                                               TARGETING::get_huid(i_target),
                                               true /*Add HB SW Callout*/ );

                err->collectTrace( EEPROM_COMP_NAME );

                break;
            }
        }
        else
        {
            // Since current target is not a DIMM, use the target we have
            o_target = i_target;
        }
    } while( 0 );

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromGetI2CMasterTarget()" );

    return err;
} // end eepromGetI2CMasterTarget

} // end namespace EEPROM
