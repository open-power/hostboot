/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/tpmdd.C $                                         */
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
 * @file tpmdd.C
 *
 * @brief Implementation of the TPM device driver,
 *      which will access the TPM within the
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
#include <i2c/tpmddif.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/tpmddreasoncodes.H>
#include <i2c/i2cif.H>
#include "tpmdd.H"
#include "errlud_i2c.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------
mutex_t g_tpmMutex = MUTEX_INITIALIZER;

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_tpmdd = NULL;
TRAC_INIT( & g_trac_tpmdd, TPMDD_COMP_NAME, KILOBYTE );

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// ----------------------------------------------
// Defines
// ----------------------------------------------
// ----------------------------------------------


namespace TPMDD
{

static const size_t MAX_BYTE_ADDR = 2;
static const size_t TPM_MAX_NACK_RETRIES = 2;

// Register the perform Op with the routing code for Nodes.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::TPM,
                       DeviceFW::WILDCARD,
                       tpmPerformOp );


// ------------------------------------------------------------------
// tpmPerformOp
// ------------------------------------------------------------------
errlHndl_t tpmPerformOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         va_list i_args )
{
    errlHndl_t err = NULL;
    tpm_info_t tpmInfo;
    uint64_t commandSize = 0;
    bool unlock = false;

    tpmInfo.chip = va_arg( i_args, uint64_t );
    tpmInfo.operation = ((TPMDD::tpm_op_types_t)va_arg( i_args, uint64_t ));
    commandSize = va_arg( i_args, uint64_t );

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmPerformOp()" );

    TRACUCOMP (g_trac_tpmdd, ENTER_MRK"tpmPerformOp(): "
               "i_opType=%d, chip=%d, operation=%d, buflen=%d, cmdlen=%d",
               (uint64_t) i_opType, tpmInfo.chip, tpmInfo.operation, io_buflen,
               commandSize);

    do
    {
        // Read Attributes needed to complete the operation
        err = tpmReadAttributes( i_target,
                                 tpmInfo );

        if( err )
        {
            break;
        }

        // Ensure the TPM is enabled
        if (!tpmInfo.tpmEnabled)
        {
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmPerformOp(): TPM requested not enabled!"
                       "C-p/e/dA=%d-%d/%d/0x%X, OP=%d",
                       tpmInfo.chip, tpmInfo.port,
                       tpmInfo.engine, tpmInfo.devAddr, tpmInfo.operation);

            /*@
             * @errortype
             * @reasoncode     TPM_DEVICE_NOT_AVAILABLE
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       TPMDD_PERFORM_OP
             * @userdata1      Operation Type
             * @userdata2      Chip to Access
             * @devdesc        Invalid operation type.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           TPMDD_PERFORM_OP,
                                           TPM_DEVICE_NOT_AVAILABLE,
                                           i_opType,
                                           tpmInfo.chip,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( TPMDD_COMP_NAME );

            break;
        }



        // Lock to sequence operations
        mutex_lock( &g_tpmMutex );
        unlock = true;


        // TPM_OP_READVENDORID operation
        // Only supported with a DeviceFW::READ operation
        if( TPMDD::TPM_OP_READVENDORID == tpmInfo.operation &&
            DeviceFW::READ == i_opType)
        {

            if (io_buflen > 4)
            {
                TRACFCOMP( g_trac_tpmdd,
                           ERR_MRK"tpmPerformOp(): Operation Overflow! "
                           "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                           "blen=%d",
                           tpmInfo.chip, tpmInfo.port,
                           tpmInfo.engine, tpmInfo.devAddr,
                           tpmInfo.operation, io_buflen);


                /*@
                 * @errortype
                 * @reasoncode       TPM_OVERFLOW_ERROR
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         TPMDD_PERFORM_OP
                 * @userdata1        Operation
                 * @userdata2        Buffer Length      (in Bytes)
                 * @devdesc          TPM buffer length > 4 for read vendor op
                 * @custdesc         A problem occurred during the IPL of the
                 *                   system: TPM buffer is too large.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               TPMDD_PERFORM_OP,
                                               TPM_OVERFLOW_ERROR,
                                               tpmInfo.operation,
                                               io_buflen,
                                               true /*Add HB SW Callout*/ );

                err->collectTrace( TPMDD_COMP_NAME );
                break;
            }



            // Set the offset for the vendor reg
            tpmInfo.offset = TPMDD::I2C_REG_VENDOR;


            err = tpmRead( io_buffer,
                           io_buflen,
                           tpmInfo );

            if ( err )
            {
                break;
            }

        }

        // TPM_OP_TRANSMIT
        // Ignoring read/write type since transmit really does both anyway
        else if( TPMDD::TPM_OP_TRANSMIT == tpmInfo.operation )
        {


            err = tpmTransmit( io_buffer,
                               io_buflen,
                               commandSize,
                               tpmInfo );

            if ( err )
            {
                break;
            }

        }
        else
        {
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmPerformOp(): Invalid TPM Operation!"
                       "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, Type=%d",
                       tpmInfo.chip, tpmInfo.port,
                       tpmInfo.engine, tpmInfo.devAddr,
                       tpmInfo.operation, i_opType);

            /*@
             * @errortype
             * @reasoncode     TPM_INVALID_OPERATION
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       TPMDD_PERFORM_OP
             * @userdata1      Operation Type
             * @userdata2      Chip to Access
             * @devdesc        Invalid operation type.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           TPMDD_PERFORM_OP,
                                           TPM_INVALID_OPERATION,
                                           i_opType,
                                           tpmInfo.chip,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( TPMDD_COMP_NAME );

            break;
        }


    } while( 0 );

    if( unlock )
    {
        mutex_unlock( & g_tpmMutex );
    }


    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmPerformOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end tpmPerformOp

//-------------------------------------------------------------------
//tpmPresence
//-------------------------------------------------------------------
bool tpmPresence ( TARGETING::Target * i_target,
                   tpm_chip_types_t i_chip)
{

    TRACDCOMP(g_trac_tpmdd, ENTER_MRK"tpmPresence()");
    TRACUCOMP(g_trac_tpmdd, ENTER_MRK"tpmPresence() : "
              "node tgt=0x%X chip=%d",
              TARGETING::get_huid(i_target),
              i_chip);

    errlHndl_t err = NULL;
    bool l_present = true;

    tpm_info_t tpmInfo;

    tpmInfo.chip = i_chip;
    tpmInfo.offset = 0;
    do
    {

        // Read Attributes needed to complete the operation
        err = tpmReadAttributes( i_target,
                                 tpmInfo );

        if( err )
        {
            TRACFCOMP(g_trac_tpmdd,
                     ERR_MRK"Error in tpmPresence::tpmReadAttributes() "
                      "RC 0x%X", err->reasonCode());
            l_present = false;
            delete err;
            err = NULL;
            break;
        }

        // Ensure the TPM is enabled
        if (!tpmInfo.tpmEnabled)
        {
            TRACUCOMP(g_trac_tpmdd,
                      INFO_MRK"tpmPresence : Device not enabled");
            l_present = false;
            break;
        }




        // Verify the TPM is supported by this driver by reading and
        //  comparing the vendorid
        uint32_t vendorId = 0;
        size_t   vendorIdSize = 4;


        // Set the offset for the vendor reg
        tpmInfo.offset = TPMDD::I2C_REG_VENDOR;


        err = tpmRead( &vendorId,
                       vendorIdSize,
                       tpmInfo );

        if ( NULL != err )
        {
            TRACUCOMP(g_trac_tpmdd,
                     ERR_MRK"tpmPresence : ReadVendorID failed!"
                      "node tgt=0x%X C-p/e/dA=%d-%d/%d/0x%X RC=0x%X",
                      TARGETING::get_huid(i_target),
                      tpmInfo.chip,
                      tpmInfo.port,
                      tpmInfo.engine,
                      static_cast<uint64_t>(tpmInfo.devAddr),
                      err->reasonCode()
                      );
            l_present = false;
            delete err;
            err = NULL;
            break;

        }
        else if ((TPMDD::TPM_VENDORID_MASK & vendorId)
                   != TPMDD::TPM_VENDORID)
        {
            TRACUCOMP(g_trac_tpmdd,
                     ERR_MRK"tpmPresence : ReadVendorID mismatch!"
                      "node tgt=0x%X C-p/e/dA=%d-%d/%d/0x%X"
                      " found ID=0x%X exp ID=0x%X",
                      TARGETING::get_huid(i_target),
                      tpmInfo.chip,
                      tpmInfo.port,
                      tpmInfo.engine,
                      static_cast<uint64_t>(tpmInfo.devAddr),
                      vendorId, TPMDD::TPM_VENDORID
                      );
            l_present = false;
            break;
        }


        // Verify the TPM is supported by this driver by reading and
        //  comparing the familyid
        uint8_t familyId = 0;
        size_t  familyIdSize = 1;


        // Set the offset for the vendor reg
        tpmInfo.offset = TPMDD::I2C_REG_FAMILYID;


        err = tpmRead( &familyId,
                       familyIdSize,
                       tpmInfo );

        if ( NULL != err )
        {
            TRACUCOMP(g_trac_tpmdd,
                     ERR_MRK"tpmPresence : ReadFamilyID failed!"
                      "node tgt=0x%X C-p/e/dA=%d-%d/%d/0x%X RC=0x%X",
                      TARGETING::get_huid(i_target),
                      tpmInfo.chip,
                      tpmInfo.port,
                      tpmInfo.engine,
                      static_cast<uint64_t>(tpmInfo.devAddr),
                      err->reasonCode()
                      );
            l_present = false;
            delete err;
            err = NULL;
            break;

        }
        else if ((TPMDD::TPM_FAMILYID_MASK & familyId)
                 != TPMDD::TPM_FAMILYID)
        {
            TRACUCOMP(g_trac_tpmdd,
                     ERR_MRK"tpmPresence : FamilyID mismatch!"
                      "node tgt=0x%X C-p/e/dA=%d-%d/%d/0x%X"
                      " found ID=0x%X exp ID=0x%X",
                      TARGETING::get_huid(i_target),
                      tpmInfo.chip,
                      tpmInfo.port,
                      tpmInfo.engine,
                      static_cast<uint64_t>(tpmInfo.devAddr),
                      familyId, TPMDD::TPM_FAMILYID
                      );
            l_present = false;
            break;
        }
        else
        {
            TRACFCOMP(g_trac_tpmdd,
                      INFO_MRK"tpmPresence : TPM Detected!"
                      " node tgt=0x%X C-p/e/dA=%d-%d/%d/0x%X"
                      " Vendor ID=0x%X, Family ID=0x%X",
                      TARGETING::get_huid(i_target),
                      tpmInfo.chip,
                      tpmInfo.port,
                      tpmInfo.engine,
                      static_cast<uint64_t>(tpmInfo.devAddr),
                      vendorId, familyId
                      );
            l_present = true;
        }




    } while( 0 );

    TRACDCOMP(g_trac_tpmdd, EXIT_MRK"tpmPresence() : presence : %d",
              l_present);
    TRACUCOMP(g_trac_tpmdd, EXIT_MRK"tpmPresence() : "
              "node tgt=0x%X chip=%d presence=%d",
              TARGETING::get_huid(i_target),
              i_chip, l_present);
    return l_present;
}

// ------------------------------------------------------------------
// tpmRead
// ------------------------------------------------------------------
errlHndl_t tpmRead ( void * o_buffer,
                     size_t i_buflen,
                     tpm_info_t i_tpmInfo )
{
    errlHndl_t err = NULL;
    errlHndl_t err_NACK = NULL;
    uint8_t byteAddr[MAX_BYTE_ADDR];
    size_t byteAddrSize = 0;

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmRead()" );

    do
    {
        TRACUCOMP( g_trac_tpmdd,
                   "TPM READ  START : Chip: %02d : Offset %.2X : Len %d",
                   i_tpmInfo.chip, i_tpmInfo.offset, i_buflen );

        err = tpmPrepareAddress( &byteAddr,
                                 byteAddrSize,
                                 i_tpmInfo );

        if( err )
        {
            break;
        }

        /***********************************************************/
        /* Attempt read multiple times ONLY on NACK fails         */
        /***********************************************************/
        for (size_t retry = 0;
             retry <= TPM_MAX_NACK_RETRIES;
             retry++)
        {

            // Only write the byte address if we have data to write
            if( 0 != byteAddrSize )
            {
                // Use the I2C OFFSET Interface for the READ
                err = deviceOp( DeviceFW::READ,
                                i_tpmInfo.i2cTarget,
                                o_buffer,
                                i_buflen,
                                DEVICE_I2C_ADDRESS_OFFSET(
                                       i_tpmInfo.port,
                                       i_tpmInfo.engine,
                                       i_tpmInfo.devAddr,
                                       byteAddrSize,
                                       reinterpret_cast<uint8_t*>(&byteAddr)));

                if( err )
                {
                    TRACFCOMP(g_trac_tpmdd,
                              ERR_MRK"tpmRead(): I2C Read-Offset failed! "
                              "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                              "offset=0x%X, aS=%d, len=%d",
                              i_tpmInfo.chip, i_tpmInfo.port,
                              i_tpmInfo.engine, i_tpmInfo.devAddr,
                              i_tpmInfo.operation,
                              i_tpmInfo.offset, byteAddrSize, i_buflen);
                    TRACFBIN(g_trac_tpmdd, "byteAddr[]",
                             &byteAddr, byteAddrSize);

                    // Don't break here -- error handled below
                }
            }
            else
            {
                // Do the actual read via I2C
                err = deviceOp( DeviceFW::READ,
                                i_tpmInfo.i2cTarget,
                                o_buffer,
                                i_buflen,
                                DEVICE_I2C_ADDRESS( i_tpmInfo.port,
                                                    i_tpmInfo.engine,
                                                    i_tpmInfo.devAddr ) );

                if( err )
                {
                    TRACFCOMP(g_trac_tpmdd,
                              ERR_MRK"tpmRead(): I2C Read failed! "
                              "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                              "len=%d",
                              i_tpmInfo.chip, i_tpmInfo.port,
                              i_tpmInfo.engine, i_tpmInfo.devAddr,
                              i_tpmInfo.operation,
                              i_buflen);

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
                TRACFCOMP( g_trac_tpmdd, ERR_MRK"tpmRead(): Non-Nack! "
                           "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                           "Error: rc=0x%X, No Retry (retry=%d)",
                           i_tpmInfo.chip, i_tpmInfo.port,
                           i_tpmInfo.engine, i_tpmInfo.devAddr,
                           i_tpmInfo.operation,
                           err->reasonCode(), retry);

                err->collectTrace(TPMDD_COMP_NAME);

                // break from retry loop
                break;
            }
            else // Handle NACK error
            {
                // If op will be attempted again: save log and continue
                if ( retry < TPM_MAX_NACK_RETRIES )
                {
                    // Only save original NACK error
                    if ( err_NACK == NULL )
                    {
                        // Save original NACK error
                        err_NACK = err;

                        TRACFCOMP( g_trac_tpmdd,
                                   ERR_MRK"tpmRead(): NACK Error! "
                                   "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                                   "rc=0x%X, eid=0x%X, "
                                   "retry/MAX=%d/%d. Save error and retry",
                                   i_tpmInfo.chip, i_tpmInfo.port,
                                   i_tpmInfo.engine, i_tpmInfo.devAddr,
                                   i_tpmInfo.operation,
                                   err_NACK->reasonCode(),
                                   err_NACK->eid(),
                                   retry, TPM_MAX_NACK_RETRIES);

                        err_NACK->collectTrace(TPMDD_COMP_NAME);
                    }
                    else
                    {
                        // Add data to original NACK error
                        TRACFCOMP( g_trac_tpmdd,
                                   ERR_MRK"tpmRead(): Another NACK Error! "
                                   "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                                   "rc=0x%X, eid=0x%X, "
                                   "plid=0x%X, retry/MAX=%d/%d. "
                                   "Delete error and retry",
                                   i_tpmInfo.chip, i_tpmInfo.port,
                                   i_tpmInfo.engine, i_tpmInfo.devAddr,
                                   i_tpmInfo.operation,
                                   err->reasonCode(), err->eid(), err->plid(),
                                   retry, TPM_MAX_NACK_RETRIES);

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
                    TRACFCOMP( g_trac_tpmdd,
                               ERR_MRK"tpmRead(): No More Retries! "
                               "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                               "Error rc=0x%X, eid=%d, "
                               "retry/MAX=%d/%d. Returning Error",
                               i_tpmInfo.chip, i_tpmInfo.port,
                               i_tpmInfo.engine, i_tpmInfo.devAddr,
                               i_tpmInfo.operation,
                               err->reasonCode(), err->eid(),
                               retry, TPM_MAX_NACK_RETRIES);

                    err->collectTrace(TPMDD_COMP_NAME);

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
                TRACFCOMP(g_trac_tpmdd, "tpmRead(): Committing saved NACK "
                          "err eid=0x%X with plid of returned err: 0x%X",
                          err_NACK->eid(), err_NACK->plid());

                ERRORLOG::ErrlUserDetailsTarget(i_tpmInfo.i2cTarget)
                                               .addToLog(err_NACK);

                errlCommit(err_NACK, TPMDD_COMP_ID);
            }
            else
            {
                // Since we eventually succeeded, delete original NACK error
                TRACFCOMP(g_trac_tpmdd, "tpmRead(): Op successful, "
                          "deleting saved NACK err eid=0x%X, plid=0x%X",
                          err_NACK->eid(), err_NACK->plid());

                delete err_NACK;
                err_NACK = NULL;
            }
        }


        TRACUCOMP( g_trac_tpmdd,
                   "TPM READ  END   : Chip: %02d : "
                   "Offset %.2X : Len %d : %016llx",
                   i_tpmInfo.chip, i_tpmInfo.offset, i_buflen,
                   *(reinterpret_cast<uint64_t*>(o_buffer)) );

    } while( 0 );

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmRead()" );

    return err;
} // end tpmRead

// ------------------------------------------------------------------
// tpmWrite
// ------------------------------------------------------------------
errlHndl_t tpmWrite ( void * i_buffer,
                      size_t i_buflen,
                      tpm_info_t i_tpmInfo )
{
    errlHndl_t err = NULL;
    errlHndl_t err_NACK = NULL;
    uint8_t byteAddr[MAX_BYTE_ADDR];
    size_t byteAddrSize = 0;

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmWrite()" );

    do
    {
        TRACUCOMP( g_trac_tpmdd,
                   "TPM WRITE START : Chip: %02d : "
                   "Offset %.2X : Len %d : %016llx",
                   i_tpmInfo.chip, i_tpmInfo.offset,
                   i_buflen,
                   *(reinterpret_cast<uint64_t*>(i_buffer))  );

        err = tpmPrepareAddress( &byteAddr,
                                 byteAddrSize,
                                 i_tpmInfo );

        if( err )
        {
            break;
        }

        /***********************************************************/
        /* Attempt write multiple times ONLY on NACK fails         */
        /***********************************************************/
        for (size_t retry = 0;
             retry <= TPM_MAX_NACK_RETRIES;
             retry++)
        {

            // Only write the byte address if we have data to write
            if( 0 != byteAddrSize )
            {
                // Use the I2C OFFSET Interface for the WRITE
                err = deviceOp( DeviceFW::WRITE,
                                i_tpmInfo.i2cTarget,
                                i_buffer,
                                i_buflen,
                                DEVICE_I2C_ADDRESS_OFFSET(
                                       i_tpmInfo.port,
                                       i_tpmInfo.engine,
                                       i_tpmInfo.devAddr,
                                       byteAddrSize,
                                       reinterpret_cast<uint8_t*>(&byteAddr)));

                if( err )
                {
                    TRACFCOMP(g_trac_tpmdd,
                              ERR_MRK"tpmWrite(): I2C Write-Offset! "
                              "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, ",
                              "offset=0x%X, aS=%d, len=%d",
                              i_tpmInfo.chip, i_tpmInfo.port,
                              i_tpmInfo.engine, i_tpmInfo.devAddr,
                              i_tpmInfo.operation,
                              i_tpmInfo.offset, byteAddrSize, i_buflen);
                    TRACFBIN(g_trac_tpmdd, "byteAddr[]",
                             &byteAddr, byteAddrSize);

                    // Don't break here -- error handled below
                }
            }
            else
            {
                // Do the actual write via I2C
                err = deviceOp( DeviceFW::WRITE,
                                i_tpmInfo.i2cTarget,
                                i_buffer,
                                i_buflen,
                                DEVICE_I2C_ADDRESS( i_tpmInfo.port,
                                                    i_tpmInfo.engine,
                                                    i_tpmInfo.devAddr ) );

                if( err )
                {
                    TRACFCOMP(g_trac_tpmdd,
                              ERR_MRK"tpmWrite(): I2C Write failed! "
                              "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                              "len=%d",
                              i_tpmInfo.chip, i_tpmInfo.port,
                              i_tpmInfo.engine, i_tpmInfo.devAddr,
                              i_tpmInfo.operation,
                              i_buflen);

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
                TRACFCOMP( g_trac_tpmdd, ERR_MRK"tpmWrite(): Non-Nack "
                           "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                           "Error: rc=0x%X, No Retry (retry=%d)",
                           i_tpmInfo.chip, i_tpmInfo.port,
                           i_tpmInfo.engine, i_tpmInfo.devAddr,
                           i_tpmInfo.operation,
                           err->reasonCode(), retry);

                err->collectTrace(TPMDD_COMP_NAME);

                // break from retry loop
                break;
            }
            else // Handle NACK error
            {
                // If op will be attempted again: save log and continue
                if ( retry < TPM_MAX_NACK_RETRIES )
                {
                    // Only save original NACK error
                    if ( err_NACK == NULL )
                    {
                        // Save original NACK error
                        err_NACK = err;

                        TRACFCOMP( g_trac_tpmdd,
                                   ERR_MRK"tpmWrite(): NACK Error! "
                                   "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                                   "rc=0x%X, eid=0x%X, "
                                   "retry/MAX=%d/%d. Save error and retry",
                                   i_tpmInfo.chip, i_tpmInfo.port,
                                   i_tpmInfo.engine, i_tpmInfo.devAddr,
                                   i_tpmInfo.operation,
                                   err_NACK->reasonCode(),
                                   err_NACK->eid(),
                                   retry, TPM_MAX_NACK_RETRIES);

                        err_NACK->collectTrace(TPMDD_COMP_NAME);
                    }
                    else
                    {
                        // Add data to original NACK error
                        TRACFCOMP( g_trac_tpmdd,
                                   ERR_MRK"tpmWrite(): Another NACK Error! "
                                   "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                                   "rc=0x%X, eid=0x%X "
                                   "plid=0x%X, retry/MAX=%d/%d. "
                                   "Delete error and retry",
                                   i_tpmInfo.chip, i_tpmInfo.port,
                                   i_tpmInfo.engine, i_tpmInfo.devAddr,
                                   i_tpmInfo.operation,
                                   err->reasonCode(), err->eid(), err->plid(),
                                   retry, TPM_MAX_NACK_RETRIES);

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
                    TRACFCOMP( g_trac_tpmdd,
                               ERR_MRK"tpmWrite(): No More Retries! "
                               "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                               "Error rc=0x%X, eid=%d, "
                               "retry/MAX=%d/%d. Returning Error",
                               i_tpmInfo.chip, i_tpmInfo.port,
                               i_tpmInfo.engine, i_tpmInfo.devAddr,
                               i_tpmInfo.operation,
                               err->reasonCode(), err->eid(),
                               retry, TPM_MAX_NACK_RETRIES);

                    err->collectTrace(TPMDD_COMP_NAME);

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
                TRACFCOMP(g_trac_tpmdd, "tpmWrite(): Committing saved NACK "
                          "err eid=0x%X with plid of returned err: 0x%X",
                          err_NACK->eid(), err_NACK->plid());

                ERRORLOG::ErrlUserDetailsTarget(i_tpmInfo.i2cTarget)
                                               .addToLog(err_NACK);

                errlCommit(err_NACK, TPMDD_COMP_ID);
            }
            else
            {
                // Since we eventually succeeded, delete original NACK error
                TRACFCOMP(g_trac_tpmdd, "tpmWrite(): Op successful, "
                          "deleting saved NACK err eid=0x%X, plid=0x%X",
                          err_NACK->eid(), err_NACK->plid());

                delete err_NACK;
                err_NACK = NULL;
            }
        }


        TRACSCOMP( g_trac_tpmdd,
                   "TPM WRITE END   : Chip: %02d : "
                   "Offset %.2X : Len %d",
                   i_tpmInfo.chip, i_tpmInfo.offset, i_buflen);

    } while( 0 );

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmWrite()" );

    return err;
} // end tpmWrite

// ------------------------------------------------------------------
// tpmTransmit
// ------------------------------------------------------------------
errlHndl_t tpmTransmit ( void * io_buffer,
                         size_t & io_buflen,
                         size_t i_commandlen,
                         tpm_info_t i_tpmInfo )
{
    errlHndl_t err = NULL;
    bool isReady = false;

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmTransmit()" );

    do
    {

        TRACUCOMP( g_trac_tpmdd,
                   "TPM TRANSMIT START : Chip: %02d : "
                   "BufLen %d : CmdLen %d : %016llx",
                   i_tpmInfo.chip,
                   io_buflen, i_commandlen,
                   *(reinterpret_cast<uint64_t*>(io_buffer))  );

        err = tpmIsCommandReady(i_tpmInfo, isReady);
        if( err )
        {
            break;
        }

        if (!isReady)
        {
            err = tpmWriteCommandReady(i_tpmInfo);
            if( err )
            {
                break;
            }
        }

        // Verify the TPM is ready to receive our command
        err = tpmPollForCommandReady(i_tpmInfo);
        if( err )
        {
            break;
        }

        // Write the command into the TPM FIFO
        err = tpmWriteFifo(i_tpmInfo,
                           io_buffer, i_commandlen);
        if( err )
        {
            break;
        }

        err = tpmWriteTpmGo(i_tpmInfo);
        if( err )
        {
            break;
        }

        // Read the response from the TPM FIFO
        err = tpmReadFifo(i_tpmInfo,
                          io_buffer, io_buflen);
        if( err )
        {
            break;
        }

        err = tpmWriteCommandReady(i_tpmInfo);
        if( err )
        {
            break;
        }

    } while( 0 );

    TRACUCOMP( g_trac_tpmdd,
               "TPM TRANSMIT END   : Chip: %02d : "
               "BufLen %d : CmdLen %d : %016llx",
               i_tpmInfo.chip,
               io_buflen, i_commandlen,
               *(reinterpret_cast<uint64_t*>(io_buffer))  );

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmTransmit()" );

    return err;

} // end tpmTransmit


// ------------------------------------------------------------------
// tpmPrepareAddress
// ------------------------------------------------------------------
errlHndl_t tpmPrepareAddress ( void * io_buffer,
                               size_t & o_bufSize,
                               tpm_info_t i_tpmInfo )
{
    errlHndl_t err = NULL;

    o_bufSize = 0;

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmPrepareAddress()" );
    do
    {

        // --------------------------------------------------------------------
        // Currently only supporting I2C devices and that use 0, 1, or 2 bytes
        // to set the offset (ie, internal address) into the device.
        // --------------------------------------------------------------------
        switch( i_tpmInfo.addrSize )
        {
            case TWO_BYTE_ADDR:
                o_bufSize = 2;
                *((uint8_t*)io_buffer) = (i_tpmInfo.offset & 0xFF00ull) >> 8;
                *((uint8_t*)io_buffer+1) = (i_tpmInfo.offset & 0x00FFull);
                break;

            case ONE_BYTE_ADDR:
                o_bufSize = 1;
                *((uint8_t*)io_buffer) = (i_tpmInfo.offset & 0xFFull);
                break;

            default:
                TRACFCOMP( g_trac_tpmdd,
                           ERR_MRK"tpmPrepareAddress() - Invalid Device "
                           "Address Size: 0x%08x", i_tpmInfo.addrSize);

                /*@
                 * @errortype
                 * @reasoncode       TPM_INVALID_DEVICE_TYPE
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         TPMDD_PREPAREADDRESS
                 * @userdata1        Address Size (aka Device Type)
                 * @userdata2        TPM chip
                 * @devdesc          The Device type not supported (addrSize)
                 * @custdesc         A problem was detected during the IPL of
                 *                   the system: Device type not supported.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               TPMDD_PREPAREADDRESS,
                                               TPM_INVALID_DEVICE_TYPE,
                                               i_tpmInfo.addrSize,
                                               i_tpmInfo.chip,
                                               true /*Add HB SW Callout*/ );

                err->collectTrace( TPMDD_COMP_NAME );

                break;
        }

    } while( 0 );

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmPrepareAddress()" );

    return err;
} // end tpmPrepareAddress


// ------------------------------------------------------------------
// tpmReadAttributes
// ------------------------------------------------------------------
errlHndl_t tpmReadAttributes ( TARGETING::Target * i_target,
                               tpm_info_t & io_tpmInfo )
{
    errlHndl_t err = NULL;
    bool fail_reading_attribute = false;

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmReadAttributes()" );

    // These variables will be used to hold the TPM attribute data
    TARGETING::TpmPrimaryInfo tpmData;

    do
    {

        switch (io_tpmInfo.chip )
        {
            case TPM_PRIMARY:
                if( !( i_target->
                         tryGetAttr<TARGETING::ATTR_TPM_PRIMARY_INFO>
                             ( tpmData ) ) )

                {
                    fail_reading_attribute = true;
                }
                break;

            case TPM_BACKUP:

                if( !(i_target->
                        tryGetAttr<TARGETING::ATTR_TPM_BACKUP_INFO>
                        ( reinterpret_cast<
                            TARGETING::ATTR_TPM_BACKUP_INFO_type&>
                                ( tpmData) ) ) )
                {
                    fail_reading_attribute = true;
                }
                break;

            default:
                TRACFCOMP( g_trac_tpmdd,ERR_MRK"tpmReadAttributes() - "
                           "Invalid chip %d tgt=0x%X to read attributes from!",
                           io_tpmInfo.chip,
                           TARGETING::get_huid(i_target));

                /*@
                 * @errortype
                 * @reasoncode       TPM_INVALID_CHIP
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         TPMDD_READATTRIBUTES
                 * @userdata1        TPM Chip
                 * @userdata2        HUID of target
                 * @devdesc          Invalid TPM chip to access
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              TPMDD_READATTRIBUTES,
                                              TPM_INVALID_CHIP,
                                              io_tpmInfo.chip,
                                              TARGETING::get_huid(i_target),
                                              true /*Add HB SW Callout*/ );

                err->collectTrace( TPMDD_COMP_NAME );

                break;
        }

        if (NULL != err)
        {
            break;
        }

        // Check if Attribute Data was found
        if( fail_reading_attribute == true )
        {
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmReadAttributes() - ERROR reading "
                       "attributes for chip %d, tgt=0x%X!",
                       io_tpmInfo.chip,
                       TARGETING::get_huid(i_target));

                /*@
                 * @errortype
                 * @reasoncode       TPM_ATTR_INFO_NOT_FOUND
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         TPMDD_READATTRIBUTES
                 * @userdata1        HUID of target
                 * @userdata2        TPM chip
                 * @devdesc          TPM attribute was not found
                 */
                err = new ERRORLOG::ErrlEntry(
                                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              TPMDD_READATTRIBUTES,
                                              TPM_ATTR_INFO_NOT_FOUND,
                                              TARGETING::get_huid(i_target),
                                              io_tpmInfo.chip);

                // Could be FSP or HB code's fault
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_MED);
                err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                         HWAS::SRCI_PRIORITY_MED);

                err->collectTrace( TPMDD_COMP_NAME );

                break;

        }

        // Successful reading of Attribute, so extract the data
        io_tpmInfo.port          = tpmData.port;
        io_tpmInfo.devAddr       = tpmData.devAddrLocality0;
        /// @TODO RTC: 134415 Need to handle locality4
        io_tpmInfo.engine        = tpmData.engine;
        io_tpmInfo.i2cMasterPath = tpmData.i2cMasterPath;
        io_tpmInfo.tpmEnabled    = tpmData.tpmEnabled;

        // Convert attribute info to tpm_addr_size_t enum
        if ( tpmData.byteAddrOffset == 0x2 )
        {
            io_tpmInfo.addrSize = TWO_BYTE_ADDR;
        }
        else if ( tpmData.byteAddrOffset == 0x1 )
        {
            io_tpmInfo.addrSize = ONE_BYTE_ADDR;
        }
        else
        {
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmReadAttributes() - INVALID ADDRESS "
                       "OFFSET SIZE %d!",
                       tpmData.byteAddrOffset );

                /*@
                 * @errortype
                 * @reasoncode       TPM_INVALID_ADDR_OFFSET_SIZE
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         TPMDD_READATTRIBUTES
                 * @userdata1        HUID of target
                 * @userdata2        Address Offset Size
                 * @devdesc          Invalid address offset size
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    TPMDD_READATTRIBUTES,
                                    TPM_INVALID_ADDR_OFFSET_SIZE,
                                    TARGETING::get_huid(i_target),
                                    tpmData.byteAddrOffset,
                                    true /*Add HB SW Callout*/ );

                err->collectTrace( TPMDD_COMP_NAME );

                break;

        }

        // Get i2c master target
        err = tpmGetI2CMasterTarget( i_target,
                                     io_tpmInfo );

        if( err )
        {
            TRACFCOMP(g_trac_tpmdd,
                      ERR_MRK"Error in tpmReadAttributes::tpmGetI2Cmaster() "
                      "RC 0x%X", err->reasonCode());
            break;
        }


        // Lookup bus speed
        TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speeds;
        if( io_tpmInfo.i2cTarget->
            tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>(speeds) &&
            (io_tpmInfo.engine < I2C_BUS_MAX_ENGINE(speeds)) &&
            (io_tpmInfo.port < I2C_BUS_MAX_PORT(speeds)) )
        {
            io_tpmInfo.busFreq = speeds[io_tpmInfo.engine][io_tpmInfo.port];
            io_tpmInfo.busFreq *= 1000; //convert KHz->Hz
        }
        else
        {
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmReadAttributes() - BUS SPEED LOOKUP FAIL");

                /*@
                 * @errortype
                 * @reasoncode       TPM_BUS_SPEED_LOOKUP_FAIL
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         TPMDD_READATTRIBUTES
                 * @userdata1        HUID of target
                 * @userdata2        Address Offset Size
                 * @devdesc          Invalid address offset size
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    TPMDD_READATTRIBUTES,
                                    TPM_BUS_SPEED_LOOKUP_FAIL,
                                    TARGETING::get_huid(i_target),
                                    tpmData.byteAddrOffset,
                                    true /*Add HB SW Callout*/ );

                err->collectTrace( TPMDD_COMP_NAME );

                break;

        }


    } while( 0 );

    TRACUCOMP(g_trac_tpmdd,"tpmReadAttributes() tgt=0x%X, %d/%d/0x%X "
              "En=%d, aS=%d, aO=%d",
              TARGETING::get_huid(i_target),
              io_tpmInfo.port, io_tpmInfo.engine, io_tpmInfo.devAddr,
              io_tpmInfo.tpmEnabled,
              io_tpmInfo.addrSize, tpmData.byteAddrOffset);

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmReadAttributes()" );

    return err;
} // end tpmReadAttributes


// ------------------------------------------------------------------
// tpmGetI2CMasterTarget
// ------------------------------------------------------------------
errlHndl_t tpmGetI2CMasterTarget ( TARGETING::Target * i_target,
                                   tpm_info_t & io_tpmInfo )
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmGetI2CMasterTarget()" );

    do
    {
        TARGETING::TargetService& tS = TARGETING::targetService();

        // The path from i_target to its I2C Master was read from the
        // attribute via tpmReadAttributes() and passed to this function
        // in io_tpmInfo.i2cMasterPath

        // check that the path exists
        bool exists = false;
        tS.exists( io_tpmInfo.i2cMasterPath,
                   exists );

        if( !exists )
        {
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmGetI2CMasterTarget() - "
                       "i2cMasterPath attribute path doesn't exist!" );

            // Compress the i2cMasterPath entity path into a uint64_t value
            // Format is up to 4 path elements defined like type:8 instance:8
            uint64_t l_epCompressed = 0;
            for( uint32_t i = 0; i < io_tpmInfo.i2cMasterPath.size(); i++ )
            {
                // Path element: type:8 instance:8
                l_epCompressed |=
                    io_tpmInfo.i2cMasterPath[i].type << ((16*(3-i))+8);
                l_epCompressed |=
                    io_tpmInfo.i2cMasterPath[i].instance << (16*(3-i));

                // Can only fit 4 path elements into 64 bits
                if ( i == 3 )
                {
                    break;
                }
            }

            /*@
             * @errortype
             * @reasoncode       TPM_I2C_MASTER_PATH_ERROR
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         TPMDD_GETI2CMASTERTARGET
             * @userdata1[00:31] Attribute Chip Type Enum
             * @userdata1[32:63] HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          I2C master entity path doesn't exist.
             */
            err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                TPMDD_GETI2CMASTERTARGET,
                                TPM_I2C_MASTER_PATH_ERROR,
                                TWO_UINT32_TO_UINT64(
                                    io_tpmInfo.chip,
                                    TARGETING::get_huid(i_target) ),
                                l_epCompressed,
                                true /*Add HB SW Callout*/ );

            err->collectTrace( TPMDD_COMP_NAME );

            ERRORLOG::ErrlUserDetailsString(
                io_tpmInfo.i2cMasterPath.toString()).addToLog(err);

            break;
        }

        // Since it exists, convert to a target
        io_tpmInfo.i2cTarget = tS.toTarget( io_tpmInfo.i2cMasterPath );

        if( NULL == io_tpmInfo.i2cTarget )
        {
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmGetI2CMasterTarget() - I2C Master "
                              "Path target was NULL!" );

            // Compress the entity path
            uint64_t l_epCompressed = 0;
            for( uint32_t i = 0; i < io_tpmInfo.i2cMasterPath.size(); i++ )
            {
                // Path element: type:8 instance:8
                l_epCompressed |=
                    io_tpmInfo.i2cMasterPath[i].type << ((16*(3-i))+8);
                l_epCompressed |=
                    io_tpmInfo.i2cMasterPath[i].instance << (16*(3-i));

                // Can only fit 4 path elements into 64 bits
                if ( i == 3 )
                {
                    break;
                }
            }

            /*@
             * @errortype
             * @reasoncode       TPM_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         TPMDD_GETI2CMASTERTARGET
             * @userdata1[00:31] Attribute Chip Type Enum
             * @userdata1[32:63] HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          I2C master path target is null.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           TPMDD::TPMDD_GETI2CMASTERTARGET,
                                           TPMDD::TPM_TARGET_NULL,
                                           TWO_UINT32_TO_UINT64(
                                               io_tpmInfo.chip,
                                               TARGETING::get_huid(i_target) ),
                                           l_epCompressed,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( TPMDD_COMP_NAME );

            ERRORLOG::ErrlUserDetailsString(
                io_tpmInfo.i2cMasterPath.toString()).addToLog(err);

            break;
        }


    } while( 0 );

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmGetI2CMasterTarget()" );

    return err;
} // end tpmGetI2CMasterTarget


errlHndl_t tpmWriteReg ( tpm_info_t i_tpmInfo,
                         size_t i_offset,
                         size_t i_buflen,
                         void * i_buffer)
{
    i_tpmInfo.offset = i_offset;
    return tpmWrite(i_buffer,
                    i_buflen,
                    i_tpmInfo);

} // end tpmWriteReg

errlHndl_t tpmReadReg ( tpm_info_t i_tpmInfo,
                        size_t i_offset,
                        size_t i_buflen,
                        void * o_buffer)
{
    i_tpmInfo.offset = i_offset;
    return tpmRead(o_buffer,
                   i_buflen,
                   i_tpmInfo);

} // end tpmReadReg

errlHndl_t tpmReadSTSReg ( tpm_info_t i_tpmInfo,
                           tpm_sts_reg_t & o_stsReg)
{
    i_tpmInfo.offset = TPMDD::I2C_REG_STS;
    return tpmRead(reinterpret_cast<void*>(&o_stsReg),
                   1,
                   i_tpmInfo);
} // end tpmReadSTSReg

errlHndl_t tpmReadSTSRegValid ( tpm_info_t i_tpmInfo,
                                tpm_sts_reg_t & o_stsReg)
{
    errlHndl_t err = NULL;

    i_tpmInfo.offset = TPMDD::I2C_REG_STS;
    size_t polls = 0;
    do
    {
        err = tpmRead(reinterpret_cast<void*>(&o_stsReg),
                      1,
                      i_tpmInfo);
        if (err)
        {
            break;
        }

        if (polls > TPMDD::MAX_STSVALID_POLLS)
        {
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmReadSTSRegValid(): Timeout! "
                       "C-p/e/dA=%d-%d/%d/0x%X, %02X",
                       i_tpmInfo.chip, i_tpmInfo.port,
                       i_tpmInfo.engine, i_tpmInfo.devAddr,
                       o_stsReg.value);

            /*@
             * @errortype
             * @reasoncode       TPM_TIMEOUT
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         TPMDD_READSTSREGVALID
             * @userdata1        Operation
             * @userdata2        STS Reg
             * @devdesc          TPM timeout waiting for stsValid
             * @custdesc         A problem occurred during the IPL of the
             *                   system: TPM timeout
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           TPMDD_READSTSREGVALID,
                                           TPM_TIMEOUT,
                                           i_tpmInfo.operation,
                                           o_stsReg.value,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( TPMDD_COMP_NAME );
            break;
        }
        else if (!o_stsReg.stsValid)
        {
            // Sleep 10ms before attempting another read
            nanosleep(0, 10 * NS_PER_MSEC);
            polls++;
        }
    } while (!o_stsReg.stsValid);

    return err;
} // end tpmReadSTSRegValid


errlHndl_t tpmIsCommandReady( tpm_info_t i_tpmInfo,
                              bool & o_isReady)
{
    tpm_sts_reg_t stsReg;
    errlHndl_t err = tpmReadSTSReg(i_tpmInfo,
                                   stsReg);
    o_isReady = false;

    if (NULL == err && stsReg.isCommandReady)
    {
        o_isReady = true;
    }
    return err;

} // end tpmIsCommandReady

errlHndl_t tpmPollForCommandReady( tpm_info_t i_tpmInfo)
{
    tpm_sts_reg_t stsReg;
    errlHndl_t err = NULL;

    // Operation TIMEOUT_B defined by TCG spec for command ready
    for (size_t delay = 0; delay < TPMDD::TPM_TIMEOUT_B; delay += 10)
    {
        err = tpmReadSTSReg(i_tpmInfo,
                            stsReg);
        if ((NULL == err && stsReg.isCommandReady) ||
            (NULL != err))
        {
            break;
        }
        // Sleep 10ms before attempting another read
        nanosleep(0, 10 * NS_PER_MSEC);

    }

    if (NULL == err && !stsReg.isCommandReady)
    {
        // The first write to command ready may have just aborted
        //   an outstanding command, we will write it again and poll once
        //   more
        err = tpmWriteCommandReady(i_tpmInfo);

        if (NULL == err)
        {
            // Ok, poll again
            // Operation TIMEOUT_B defined by TCG spec for command ready
            for (size_t delay = 0; delay < TPMDD::TPM_TIMEOUT_B; delay += 10)
            {
                err = tpmReadSTSReg(i_tpmInfo,
                                    stsReg);
                if ((NULL == err && stsReg.isCommandReady) ||
                    (NULL != err))
                {
                    break;
                }
                // Sleep 10ms before attempting another read
                nanosleep(0, 10 * NS_PER_MSEC);
            }
        }
    }


    if (NULL == err && !stsReg.isCommandReady)
    {
        // Timed out waiting for TPM to be ready
        TRACFCOMP( g_trac_tpmdd,
                   ERR_MRK"tpmPollForCommandReady() - "
                   "Timeout polling for command ready! "
                   "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                   "STS=0x%X",
                   i_tpmInfo.chip, i_tpmInfo.port,
                   i_tpmInfo.engine, i_tpmInfo.devAddr, i_tpmInfo.operation,
                   stsReg.value );

        /*@
         * @errortype
         * @reasoncode       TPM_TIMEOUT
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         TPMDD_POLLFORCOMMMANDREADY
         * @userdata1        Attribute Chip Type Enum
         * @userdata2        STS Reg
         * @devdesc        Timeout waiting for TPM to enter command ready state.
         */
        err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      TPMDD_POLLFORCOMMMANDREADY,
                                      TPM_TIMEOUT,
                                      i_tpmInfo.chip,
                                      stsReg.value,
                                      true /*Add HB SW Callout*/ );

        err->collectTrace( TPMDD_COMP_NAME );

        ERRORLOG::ErrlUserDetailsString(
                  i_tpmInfo.i2cMasterPath.toString()).addToLog(err);

    }
    return err;

} // end tpmPollForCommandReady

errlHndl_t tpmIsExpecting( tpm_info_t i_tpmInfo,
                           bool & o_isExpecting)
{
    tpm_sts_reg_t stsReg;
    errlHndl_t err = tpmReadSTSRegValid(i_tpmInfo,
                                        stsReg);
    o_isExpecting = false;

    if (NULL == err && stsReg.expect)
    {
        o_isExpecting = true;
    }
    return err;

} // end tpmIsExpecting

errlHndl_t tpmIsDataAvail( tpm_info_t i_tpmInfo,
                           bool & o_isDataAvail)
{
    tpm_sts_reg_t stsReg;
    errlHndl_t err = tpmReadSTSRegValid(i_tpmInfo,
                                        stsReg);
    o_isDataAvail = false;

    if (NULL == err && stsReg.dataAvail)
    {
        o_isDataAvail = true;
    }
    return err;

} // end tpmIsDataAvail

errlHndl_t tpmPollForDataAvail( tpm_info_t i_tpmInfo)
{
    tpm_sts_reg_t stsReg;
    errlHndl_t err = NULL;

    // Operation TIMEOUT_A defined by TCG spec for data available
    for (size_t delay = 0; delay < TPMDD::TPM_TIMEOUT_A; delay += 10)
    {
        err = tpmReadSTSRegValid(i_tpmInfo,
                                 stsReg);
        if ((NULL == err && stsReg.dataAvail) ||
            (NULL != err))
        {
            break;
        }
        // Sleep 10ms before attempting another read
        nanosleep(0, 10 * NS_PER_MSEC);

    }

    if (NULL == err && !stsReg.dataAvail)
    {
        // Timed out waiting for TPM to have more data available
        TRACFCOMP( g_trac_tpmdd,
                   ERR_MRK"tpmPollForDataAvail() - "
                   "Timeout polling for dataAvail! "
                   "C-p/e/dA=%d-%d/%d/0x%X, OP=%d, "
                   "STS=0x%X",
                   i_tpmInfo.chip, i_tpmInfo.port,
                   i_tpmInfo.engine, i_tpmInfo.devAddr, i_tpmInfo.operation,
                   stsReg.value );

        /*@
         * @errortype
         * @reasoncode       TPM_TIMEOUT
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         TPMDD_POLLFORDATAAVAIL
         * @userdata1        Attribute Chip Type Enum
         * @userdata2        STS Reg
         * @devdesc          Timeout waiting for TPM data available.
         */
        err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      TPMDD_POLLFORDATAAVAIL,
                                      TPM_TIMEOUT,
                                      i_tpmInfo.chip,
                                      stsReg.value,
                                      true /*Add HB SW Callout*/ );

        err->collectTrace( TPMDD_COMP_NAME );

        ERRORLOG::ErrlUserDetailsString(
                  i_tpmInfo.i2cMasterPath.toString()).addToLog(err);

    }
    return err;

} // end tpmPollForDataAvail

errlHndl_t tpmReadBurstCount( tpm_info_t i_tpmInfo,
                              uint16_t & o_burstCount)
{
    errlHndl_t err = NULL;
    o_burstCount = 0;

    // Read the burst count
    uint16_t burstCount = 0;
    if (NULL == err)
    {
        err = tpmReadReg(i_tpmInfo,
                         TPMDD::I2C_REG_BURSTCOUNT,
                         2,
                         reinterpret_cast<void*>(&burstCount));
    }

    if (NULL == err)
    {
        o_burstCount = (burstCount & 0x00FF) << 8;
        o_burstCount |= (burstCount & 0xFF00) >> 8;
    }
    TRACUCOMP( g_trac_tpmdd,
               "tpmReadBurstCount() - BurstCount %d",
               o_burstCount);


    return err;

} // end tpmReadBurstCount



errlHndl_t tpmWriteCommandReady( tpm_info_t i_tpmInfo)
{
    tpm_sts_reg_t stsReg;
    stsReg.value = 0;
    stsReg.isCommandReady = 1;

    return tpmWriteReg(i_tpmInfo,
                       TPMDD::I2C_REG_STS,
                       1,
                       reinterpret_cast<void*>(&stsReg));

} // end tpmWriteCommandReady

errlHndl_t tpmWriteTpmGo( tpm_info_t i_tpmInfo)
{
    tpm_sts_reg_t stsReg;
    stsReg.value = 0;
    stsReg.tpmGo = 1;

    return tpmWriteReg(i_tpmInfo,
                       TPMDD::I2C_REG_STS,
                       1,
                       reinterpret_cast<void*>(&stsReg));

} // end tpmWriteTpmGo

errlHndl_t tpmWriteResponseRetry( tpm_info_t i_tpmInfo)
{
    tpm_sts_reg_t stsReg;
    stsReg.value = 0;
    stsReg.responseRetry = 1;

    return tpmWriteReg(i_tpmInfo,
                       TPMDD::I2C_REG_STS,
                       1,
                       reinterpret_cast<void*>(&stsReg));

} // end tpmWriteResponseRetry


errlHndl_t tpmWriteFifo( tpm_info_t i_tpmInfo,
                         void * i_buffer,
                         size_t i_buflen)
{
    size_t delay = 0;
    size_t curByte = 0;
    uint8_t* bytePtr = (uint8_t*)i_buffer;
    uint8_t* curBytePtr = NULL;
    uint16_t burstCount = 0;
    errlHndl_t err = NULL;
    bool expecting = false;
    // We will transfer the command except for the last byte
    //  that will be transfered separately to allow for
    //  overflow checking
    size_t length = i_buflen - 1;
    size_t tx_len = 0;

    do
    {
        err = tpmReadBurstCount(i_tpmInfo,
                                burstCount);
        if (err)
        {
            break;
        }
        else if (0 == burstCount)
        {
            // Need to delay to allow the TPM time
            nanosleep(0, 10 * NS_PER_MSEC); // 10ms
            delay += 10;
            continue;
        }

        // Send in some data
        delay = 0;
        curBytePtr = &(bytePtr[curByte]);
        tx_len = (curByte + burstCount > length ?
                  (length - curByte) :
                  burstCount);
        err = tpmWriteReg(i_tpmInfo,
                          TPMDD::I2C_REG_WR_FIFO,
                          tx_len,
                          curBytePtr);
        if (err)
        {
            break;
        }
        curByte += tx_len;

        // TPM should be expecting more data from the command
        err = tpmIsExpecting(i_tpmInfo,
                             expecting);

        if (NULL == err && !expecting)
        {
            // TPM is not expecting more data, we overflowed
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmWriteFifo(): Data Overflow! "
                       "C-p/e/dA=%d-%d/%d/0x%X, blen=%d, "
                       "clen=%d",
                       i_tpmInfo.chip, i_tpmInfo.port,
                       i_tpmInfo.engine, i_tpmInfo.devAddr,
                       i_buflen, curByte);

            /*@
             * @errortype
             * @reasoncode       TPM_OVERFLOW_ERROR
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         TPMDD_WRITEFIFO
             * @userdata1[0:31]  Current byte
             * @userdata1[32:63] Buffer Length      (in Bytes)
             * @userdata2        8 bytes of command buffer
             * @devdesc          TPM expected less data during FIFO write
             * @custdesc         A problem occurred during the IPL of the
             *                   system: TPM overflow
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           TPMDD_WRITEFIFO,
                                           TPM_OVERFLOW_ERROR,
                                           TWO_UINT32_TO_UINT64(
                                               curByte,
                                               i_buflen       ),
                                           *(reinterpret_cast<uint64_t*>
                                               (i_buffer)),
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( TPMDD_COMP_NAME );
        }
        if (err)
        {
            break;
        }

        // Everything but the last byte sent?
        if (curByte >= length)
        {
            break;
        }


    // Operation TIMEOUT_D defined by TCG spec for FIFO availability
    } while (delay < TPMDD::TPM_TIMEOUT_D);

    if (NULL == err &&
        delay < TPMDD::TPM_TIMEOUT_D)
    {
        delay = 0;

        // Send the final byte
        do
        {
            err = tpmReadBurstCount(i_tpmInfo,
                                    burstCount);
            if (err)
            {
                break;
            }
            else if (0 == burstCount)
            {
                // Need to delay to allow the TPM time
                nanosleep(0, 10 * NS_PER_MSEC); // 10ms
                delay += 10;
                continue;
            }

            // Send in some data
            delay = 0;
            curBytePtr = &(bytePtr[curByte]);
            err = tpmWriteReg(i_tpmInfo,
                              TPMDD::I2C_REG_WR_FIFO,
                              1,
                              curBytePtr);
            // done
            break;
            // Operation TIMEOUT_D defined by TCG spec for FIFO availability
        } while (delay < TPMDD::TPM_TIMEOUT_D);

    }


    if (NULL == err &&
        delay >= TPMDD::TPM_TIMEOUT_D)
    {
        TRACFCOMP( g_trac_tpmdd,
                   ERR_MRK"tpmWriteFifo(): Timeout! "
                   "C-p/e/dA=%d-%d/%d/0x%X, blen=%d, "
                   "clen=%d",
                   i_tpmInfo.chip, i_tpmInfo.port,
                   i_tpmInfo.engine, i_tpmInfo.devAddr,
                   i_buflen, curByte);

        /*@
         * @errortype
         * @reasoncode       TPM_TIMEOUT
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         TPMDD_WRITEFIFO
         * @userdata1[0:31]  Current Byte
         * @userdata1[32:63] Buffer Length      (in Bytes)
         * @userdata2        8 bytes of command buffer
         * @devdesc          TPM timeout writing to FIFO
         * @custdesc         A problem occurred during the IPL of the
         *                   system: TPM timeout
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       TPMDD_WRITEFIFO,
                                       TPM_TIMEOUT,
                                       TWO_UINT32_TO_UINT64(
                                               curByte,
                                               i_buflen       ),
                                       *(reinterpret_cast<uint64_t*>
                                         (i_buffer)),
                                       true /*Add HB SW Callout*/ );

        err->collectTrace( TPMDD_COMP_NAME );
    }



    if (NULL == err)
    {
        err = tpmIsExpecting(i_tpmInfo,
                             expecting);

        if (NULL == err && expecting)
        {
            // TPM is expecting more data even though we think we are done
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmWriteFifo(): Data Underflow! "
                       "C-p/e/dA=%d-%d/%d/0x%X, blen=%d, "
                       "clen=%d",
                       i_tpmInfo.chip, i_tpmInfo.port,
                       i_tpmInfo.engine, i_tpmInfo.devAddr,
                       i_buflen, curByte);

            /*@
             * @errortype
             * @reasoncode       TPM_UNDERFLOW_ERROR
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         TPMDD_WRITEFIFO
             * @userdata1[0:31]  Current Byte
             * @userdata1[32:63] Buffer Length      (in Bytes)
             * @userdata2        8 bytes of command buffer
             * @devdesc          TPM expected more data during FIFO write
             * @custdesc         A problem occurred during the IPL of the
             *                   system: TPM underflow
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           TPMDD_WRITEFIFO,
                                           TPM_UNDERFLOW_ERROR,
                                           TWO_UINT32_TO_UINT64(
                                               curByte,
                                               i_buflen       ),
                                           *(reinterpret_cast<uint64_t*>
                                             (i_buffer)),
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( TPMDD_COMP_NAME );
        }

    }



    return err;

} // end tpmWriteFifo

errlHndl_t tpmReadFifo( tpm_info_t i_tpmInfo,
                        void * o_buffer,
                        size_t & io_buflen)
{
    size_t delay = 0;
    size_t curByte = 0;
    uint8_t* bytePtr = (uint8_t*)o_buffer;
    uint8_t* curBytePtr = NULL;
    uint16_t burstCount = 0;
    errlHndl_t err = NULL;
    bool dataAvail = false;

    // Verify the TPM has data waiting for us
    err = tpmPollForDataAvail(i_tpmInfo);
    if( !err )
    {
        do
        {
            err = tpmReadBurstCount(i_tpmInfo,
                                    burstCount);
            if (err)
            {
                break;
            }
            else if (0 == burstCount)
            {
                // Need to delay to allow the TPM time
                nanosleep(0, 10 * NS_PER_MSEC);  // 10ms
                delay += 10;
                continue;
            }

            // Check for a buffer overflow
            if (curByte + burstCount >
                io_buflen)
            {
                // TPM is expecting more data even though we think we are done
                TRACFCOMP( g_trac_tpmdd,
                           ERR_MRK"tpmReadFifo(): Data Overflow! "
                           "C-p/e/dA=%d-%d/%d/0x%X, blen=%d, "
                           "clen=%d",
                           i_tpmInfo.chip, i_tpmInfo.port,
                           i_tpmInfo.engine, i_tpmInfo.devAddr,
                           io_buflen, curByte + burstCount);

                /*@
                 * @errortype
                 * @reasoncode       TPM_OVERFLOW_ERROR
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         TPMDD_READFIFO
                 * @userdata1[0:31]  Operation
                 * @userdata1[32:63] Buffer Length      (in Bytes)
                 * @userdata2        Current Byte
                 * @devdesc          TPM provided more data during FIFO read
                 *                   then buffer space provided
                 * @custdesc         A problem occurred during the IPL of the
                 *                   system: TPM overflow
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               TPMDD_READFIFO,
                                               TPM_OVERFLOW_ERROR,
                                               TWO_UINT32_TO_UINT64(
                                                      i_tpmInfo.operation,
                                                      io_buflen       ),
                                               curByte,
                                               true /*Add HB SW Callout*/ );

                err->collectTrace( TPMDD_COMP_NAME );
                break;
            }

            // Read some data
            delay = 0;
            curBytePtr = &(bytePtr[curByte]);
            err = tpmReadReg(i_tpmInfo,
                             TPMDD::I2C_REG_RD_FIFO,
                             burstCount,
                             curBytePtr);
            if (err)
            {
                break;
            }
            curByte += burstCount;

            err = tpmIsDataAvail(i_tpmInfo,
                                 dataAvail);
            if (err || !dataAvail)
            {
                break;
            }

            // Operation TIMEOUT_D defined by TCG spec for FIFO availability
        } while (delay < TPMDD::TPM_TIMEOUT_D);

    }

    if (!err && delay >= TPMDD::TPM_TIMEOUT_D)
    {
        TRACFCOMP( g_trac_tpmdd,
                   ERR_MRK"tpmReadFifo(): Timeout! "
                   "C-p/e/dA=%d-%d/%d/0x%X, blen=%d, "
                   "clen=%d",
                   i_tpmInfo.chip, i_tpmInfo.port,
                   i_tpmInfo.engine, i_tpmInfo.devAddr,
                   io_buflen, curByte);

        /*@
         * @errortype
         * @reasoncode       TPM_TIMEOUT
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         TPMDD_READFIFO
         * @userdata1[0:31]  Operation
         * @userdata1[32:63] Buffer Length      (in Bytes)
         * @userdata2        Current Byte
         * @devdesc          TPM timeout writing to FIFO
         * @custdesc         A problem occurred during the IPL of the
         *                   system: TPM timeout
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       TPMDD_READ,
                                       TPM_TIMEOUT,
                                       TWO_UINT32_TO_UINT64(
                                           i_tpmInfo.operation,
                                           io_buflen       ),
                                       curByte,
                                       true /*Add HB SW Callout*/ );

        err->collectTrace( TPMDD_COMP_NAME );
    }

    if (NULL == err)
    {
        // We read it properly tell the caller the result length
        io_buflen = curByte;
    }
    else
    {
        io_buflen = 0;
    }


    return err;

} // end tpmReadFifo




} // end namespace TPMDD

