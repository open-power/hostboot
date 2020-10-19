/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/tpmdd.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
 *      system via the SPI device driver
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
#include <errl/errluserdetails.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/util.H>
#include <devicefw/driverif.H>
#include <util/misc.H> // simics check
#include <spi/tpmddif.H>
#include <spi/tpmddreasoncodes.H>
#include <secureboot/service.H>
#include <secureboot/trustedbootif.H>
#include "tpmdd.H"
#include <spi/spi.H> // spiInitEngine


// ----------------------------------------------
// Globals
// ----------------------------------------------
mutex_t g_tpmMutex = MUTEX_INITIALIZER;

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_tpmdd = nullptr;
TRAC_INIT( & g_trac_tpmdd, TPMDD_COMP_NAME, KILOBYTE );

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

//#define TRACUBIN(args...)  TRACFBIN(args)
#define TRACUBIN(args...)

// ----------------------------------------------
// Defines
// ----------------------------------------------
// ----------------------------------------------


namespace TPMDD
{

static const size_t TPM_MAX_RETRIES = 5;
static const size_t TPM_MAX_RETRY_DELAY_NS = (250 * NS_PER_MSEC);
static const size_t TPM_MAX_SPI_TRANSMIT_SIZE = 64;


// Register the perform Op with the routing code for TPM
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PRESENT,
                      TARGETING::TYPE_TPM,
                      tpmPresenceDetect);
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::TPM,
                       TARGETING::TYPE_TPM,
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
    errlHndl_t err = nullptr;
    tpm_info_t tpmInfo;
    uint64_t commandSize = 0;
    bool unlock = false;
    tpm_locality_t locality = TPM_LOCALITY_0;

    tpmInfo.operation = static_cast<TPMDD::tpm_op_types_t>
        (va_arg( i_args, uint64_t ));
    commandSize = va_arg( i_args, uint64_t );
    locality = static_cast<TPMDD::tpm_locality_t>(va_arg( i_args, uint64_t ));

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmPerformOp()" );

    TRACUCOMP( g_trac_tpmdd, ENTER_MRK"tpmPerformOp(): "
               "i_opType=%d, operation=%d, buflen=%d, cmdlen=%d, locality=%d",
               (uint64_t) i_opType, tpmInfo.operation,
               io_buflen, commandSize, locality );

    do
    {
        // Read Attributes needed to complete the operation
        err = tpmReadAttributes( i_target,
                                 tpmInfo,
                                 locality );

        if( err )
        {
            break;
        }

        // Ensure the TPM is enabled
        if (!tpmInfo.tpmEnabled)
        {
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmPerformOp(): TPM requested not enabled!"
                       "0x%08X TPM (SPI access 0x%08X, engine %d), OP=%d",
                       get_huid(i_target),
                       get_huid(tpmInfo.spiTarget),
                       tpmInfo.spiEngine,
                       tpmInfo.operation );

            /*@
             * @errortype
             * @reasoncode     TPM_DISABLED_VIA_MRW
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       TPMDD_PERFORM_OP
             * @userdata1      TPM
             * @userdata2      Operation Type
             * @devdesc        Invalid operation type.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           TPMDD_PERFORM_OP,
                                           TPM_DISABLED_VIA_MRW,
                                           TARGETING::get_huid(i_target),
                                           i_opType,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

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
                           "TPM_OP_READVENDORID OP=%d is a 4 byte op, "
                           "io_buflen = %d",
                           tpmInfo.operation, io_buflen );

                /*@
                 * @errortype
                 * @reasoncode       TPM_OVERFLOW_ERROR
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         TPMDD_PERFORM_OP
                 * @userdata1        TPM
                 * @userdata2[0-31]  Operation
                 * @userdata2[32-63] Buffer Length (in Bytes)
                 * @devdesc          TPM buffer length > 4 for read vendor op
                 * @custdesc         A problem occurred during the IPL of the
                 *                   system: TPM buffer is too large.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               TPMDD_PERFORM_OP,
                                               TPM_OVERFLOW_ERROR,
                                               TARGETING::get_huid(i_target),
                                               TWO_UINT32_TO_UINT64(
                                                     tpmInfo.operation,
                                                     io_buflen       ),
                                               ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

                err->collectTrace( TPMDD_COMP_NAME );
                break;
            }



            // Set the offset for the vendor reg
            tpmInfo.offset = tpmInfo.vendorIdOffset;

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
                       "OP=%d, Type=%d",
                       tpmInfo.operation, i_opType);

            /*@
             * @errortype
             * @reasoncode     TPM_INVALID_OPERATION
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       TPMDD_PERFORM_OP
             * @userdata1      TPM
             * @userdata2      Operation Type
             * @devdesc        Invalid operation type.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           TPMDD_PERFORM_OP,
                                           TPM_INVALID_OPERATION,
                                           TARGETING::get_huid(i_target),
                                           i_opType,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( TPMDD_COMP_NAME );

            break;
        }


    } while( 0 );

    if ( err != nullptr )
    {
        // Add Security Registers to the error log
        SECUREBOOT::addSecurityRegistersToErrlog(err);
    }

    if( unlock )
    {
        mutex_unlock( & g_tpmMutex );
    }

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmPerformOp() - %s",
               ((nullptr == err) ? "No Error" : "With Error") );

    return err;
} // end tpmPerformOp

//-------------------------------------------------------------------
//tpmPresence
//-------------------------------------------------------------------

bool tpmPresence (TARGETING::Target* i_pTpm)
{
    TRACFCOMP(g_trac_tpmdd, ENTER_MRK
        "tpmPresence: Attempting to detect TPM with HUID=0x%08X.",
        TARGETING::get_huid(i_pTpm));

    assert(i_pTpm != nullptr,
           "BUG! Caller passed in nullptr for TPM target");

    // Input target must have a SPI_TPM_INFO attribute (only applicable to TPM
    // targets), enforced by call to tpmReadAttributes
    errlHndl_t pError = nullptr;
    bool present = false;

    const auto forceTrace = false; // For debug
    const auto tpmRequired = TRUSTEDBOOT::isTpmRequired();
    const auto verbose = tpmRequired || forceTrace;

    tpm_info_t tpmInfo;

    do
    {
        pError = tpmReadAttributes(i_pTpm,
                                   tpmInfo,
                                   TPM_LOCALITY_0);
        if(pError)
        {
            TRACFCOMP(g_trac_tpmdd,ERR_MRK
                "tpmPresence: Bug! Failed in call to tpmReadAttributes() for "
                "TPM with HUID=0x%08X. "
                TRACE_ERR_FMT,
                get_huid(i_pTpm),
                TRACE_ERR_ARGS(pError));
            break;
        }

        // Ensure the TPM is enabled
        if (!tpmInfo.tpmEnabled)
        {
            // It is not an error condition for a TPM to be disabled in the
            // object model; in that case don't complain if the TPM is not
            // present.
            TRACFCOMP(g_trac_tpmdd,INFO_MRK
                "tpmPresence: TPM with HUID=0x%08X is defined "
                "in the object model blueprint but is flagged as "
                "disabled/ignored.",
                get_huid(i_pTpm));
            break;
        }

        // Treat TPM as not present if it is being driven by a processor that is
        // not yet available via XSCOM.

        // If the scom switch is set to XSCOM though, that means the power bus
        // is up and we have a communication path over to other chip and to the
        // PIB attached SPI controlling processor
        // we can -also- get to same place via 2nd SBE FIFO .. but .. only
        // after the SBE for that chip is running and servicing
        // SBE FIFO requests

        // So defer discovery to either after the chip's SBE has booted,
        // at which point the 2nd SBE FIFO can be used, or after the SMP is
        // established, at which point power bus access is enabled.
        if(   tpmInfo.spiTarget->getAttr<TARGETING::ATTR_TYPE>()
           == TARGETING::TYPE_PROC)
        {
            const auto scomSwitches = tpmInfo.spiTarget->getAttr<
                TARGETING::ATTR_SCOM_SWITCHES>();
            if(!scomSwitches.useXscom)
            {
                TRACFCOMP(g_trac_tpmdd,INFO_MRK
                    "tpmPresence: TPM with HUID=0x%08X is not "
                    "accessible, as the proc that drives it (HUID 0x%08X) "
                    "is not XSCOM accessible",
                    get_huid(i_pTpm),
                    get_huid(tpmInfo.spiTarget));
                break;
            }
        }

        // Verify the TPM is supported by this driver by reading and
        // comparing the vendor ID
        uint32_t vendorId = 0;
        const size_t vendorIdSize = sizeof(vendorId);

        // Set the offset for the vendor reg
        tpmInfo.offset = tpmInfo.vendorIdOffset;

        // Set up CLOCK_CONFIG register for SPI engine 4 being used to communicate with TPM
        pError = SPI::spiInitEngine(tpmInfo.spiTarget, tpmInfo.spiEngine);

        if (pError)
        {
            if(verbose)
            {
                TRACFCOMP(g_trac_tpmdd,ERR_MRK
                    "tpmPresence: SPI::spiInitEngine(...) Failed to configure SPIM4 CLOCK_CONFIG "
                    "register. TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d"
                    TRACE_ERR_FMT,
                    TARGETING::get_huid(i_pTpm),
                    TARGETING::get_huid(tpmInfo.spiTarget),
                    tpmInfo.spiEngine,
                    TRACE_ERR_ARGS(pError));
            }
            break;
        }

        pError = tpmRead(&vendorId,
                         vendorIdSize,
                         tpmInfo,
                         true /* silent */ );
        if (pError)
        {
            if(verbose)
            {
                TRACFCOMP(g_trac_tpmdd,ERR_MRK
                    "tpmPresence: tpmRead: Failed to read TPM vendor ID! "
                    "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, "
                    "TPM address=0x%08X. "
                    TRACE_ERR_FMT,
                    TARGETING::get_huid(i_pTpm),
                    TARGETING::get_huid(tpmInfo.spiTarget),
                    tpmInfo.spiEngine,
                    tpmInfo.offset,
                    TRACE_ERR_ARGS(pError));
            }
            break;

        }
        else if ((TPMDD::TPM_VENDORID_MASK & vendorId)
                       != tpmInfo.vendorId)
        {
            if(verbose)
            {
                TRACFCOMP(g_trac_tpmdd,ERR_MRK
                    "tpmPresence: Sampled TPM vendor ID did not match expected "
                    "vendor ID! "
                    "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, "
                    "Actual vendor ID=0x%08X, expected vendor ID=0x%08X.",
                    TARGETING::get_huid(i_pTpm),
                    TARGETING::get_huid(tpmInfo.spiTarget),
                    tpmInfo.spiEngine,
                    vendorId,
                    tpmInfo.vendorId);
            }

            /*@
             * @errortype
             * @moduleid         TPMDD_TPMPRESENCE
             * @reasoncode       TPM_RC_UNEXPECTED_VENDOR_ID
             * @userdata1[0:31]  Expected vendor ID
             * @userdata1[32:63] Actual vendor ID
             * @userdata2        TPM HUID
             * @devdesc          Unexpected vendor ID read from TPM
             * @custdesc         Trusted boot problem detected
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                TPMDD_TPMPRESENCE,
                TPM_RC_UNEXPECTED_VENDOR_ID,
                TWO_UINT32_TO_UINT64(tpmInfo.vendorId,vendorId),
                get_huid(i_pTpm),
                ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
            break;
        }

        // TPM Nuvoton Model 75x requires some additional setup for locality
        // NOTE: SBE should have set access to locality 0, but we can
        // set it again for good measure (just in case)
        if (tpmInfo.model == TPM_MODEL_75x)
        {
            TRACFCOMP( g_trac_tpmdd,INFO_MRK
                "tpmPresence: TPM Detected! "
                "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, "
                "vendor ID=0x%08X (no family ID for model 75x)",
                TARGETING::get_huid(i_pTpm),
                TARGETING::get_huid(tpmInfo.spiTarget),
                tpmInfo.spiEngine,
                vendorId );

            // Command to enable locality 0
            uint8_t val = TPM_ACCESS_REQUEST_LOCALITY_USE;
            size_t  valSize = sizeof(val);
            // Set the offset for the loc_sel reg
            tpmInfo.offset = TPM_REG_75x_TPM_ACCESS;
            pError = tpmWrite( &val,
                               valSize,
                               tpmInfo);
            if (pError)
            {
                TRACFCOMP(g_trac_tpmdd,ERR_MRK
                    "tpmPresence: Error on cmd to set up Locality 0 for 75x "
                    "TPM HUID=0x%08X. Treat TPM as not present",
                    TARGETING::get_huid(i_pTpm));
                break;
            }

            present = true;
        }
        // no else as tpmReadAttributes limits the model to just TPM_MODEL_75x

    } while( 0 );

    if(pError)
    {
        // If a TPM is required to boot the system, then escalate TPM
        // presence failure as an unrecoverable error log, and link its PLID to
        // a new log explicitly indicating the TPM was not detected properly.
        if(tpmRequired)
        {
            pError->collectTrace(TPMDD_COMP_NAME);
            pError->collectTrace(SECURE_COMP_NAME);
            pError->collectTrace(TRBOOT_COMP_NAME);
            pError->collectTrace(SPI_COMP_NAME);

            ERRORLOG::ErrlUserDetailsTarget(i_pTpm).addToLog(pError);

            const auto original_eid  = pError->eid();
            const auto original_plid = pError->plid();
            pError->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            errlCommit(pError,TPMDD_COMP_ID);

            /*@
             * @errortype
             * @moduleid   TPMDD_TPMPRESENCE
             * @reasoncode TPM_RC_TPM_NOT_DETECTED
             * @userdata1  TPM HUID
             * @devdesc    The system's "TPM Required" policy is set to
             *     "TPM Required" and a TPM that was expected to be present was
             *     not detected properly.  The TPM in question will eventually
             *     be flagged as TPM_UNUSABLE for redundancy calculations,
             *     Possible causes: (1) absent or improperly seated TPM,
             *     (2) TPM hardware failure, (3) firmware bug, (4) incorrect TPM
             *     part, (5) SPI failure, (6) processor failure,
             *     See earlier error logs with same PLID for additional details.
             * @custdesc   A trusted platform module (TPM) that was expected
             *     to be present was not detected properly
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                TPMDD_TPMPRESENCE,
                TPM_RC_TPM_NOT_DETECTED,
                get_huid(i_pTpm),
                0,
                ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
            pError->plid(original_plid);
            ERRORLOG::ErrlUserDetailsTarget(i_pTpm).addToLog(pError);

            TRACFCOMP(g_trac_tpmdd, ERR_MRK
                "tpmPresence: Due to Error eid=0x%.8X plid=0x%.8X involving "
                "TPM with HUID=0x%08X, committing Unrecoverable Error "
                "eid=0x%.8X with same plid=0x%.8X",
                original_eid, original_plid, TARGETING::get_huid(i_pTpm),
                pError->eid(), pError->plid());

            // Hardware/Procedure callouts/trace should have been added to the
            // original log but the main HW/SW callouts/traces are replicated here
            // just in case.
            pError->addHwCallout(i_pTpm,
                                 HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL);

            pError->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW);

            pError->collectTrace(TPMDD_COMP_NAME);
            pError->collectTrace(SECURE_COMP_NAME);
            pError->collectTrace(TRBOOT_COMP_NAME);
            pError->collectTrace(SPI_COMP_NAME);

            errlCommit(pError,TPMDD_COMP_ID);
        }
        else
        {
            delete pError;
            pError = nullptr;
        }
    }

    TRACFCOMP(g_trac_tpmdd, EXIT_MRK
        "tpmPresence: TPM with HUID=0x%08X, presence=%d",
        TARGETING::get_huid(i_pTpm), present);

    return present;
}

// ------------------------------------------------------------------
// tpmPresenceDetect
// ------------------------------------------------------------------
errlHndl_t tpmPresenceDetect(DeviceFW::OperationType i_opType,
                             TARGETING::Target* i_target,
                             void* io_buffer,
                             size_t& io_buflen,
                             int64_t i_accessType,
                             va_list i_args)
{
    errlHndl_t err = nullptr;
    if (unlikely(io_buflen < sizeof(bool)))
    {
        TRACFCOMP(g_trac_tpmdd,
                  ERR_MRK "tpmPresenceDetect> Invalid data length: %d",
                  io_buflen);
        /*@
         * @errortype
         * @moduleid     TPMDD_TPMPRESENCEDETECT
         * @reasoncode   TPM_INVALID_OPERATION
         * @userdata1    Data Length
         * @devdesc      presenceDetect> Invalid data length (!= 1 bytes)
         * @custdesc     Problem occurred during TPM presence detection
         */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        TPMDD_TPMPRESENCEDETECT,
                                        TPM_INVALID_OPERATION,
                                        TO_UINT64(io_buflen),
                                        true /*SW error*/);
        io_buflen = 0;
    } else {
        bool present = tpmPresence (i_target);
        memcpy(io_buffer, &present, sizeof(present));
        io_buflen = sizeof(present);
    }
    return err;

}

errlHndl_t tpmRead ( void * o_buffer,
                     size_t i_buflen,
                     const tpm_info_t & i_tpmInfo,
                     bool i_silent)
{
    errlHndl_t err = nullptr;
    errlHndl_t err_RETRY = nullptr;

    // Trusted Computing Group (TCG) standard requires
    // 3-byte addressing for SPI TPM operations
    // 0xD4 [locality]0 00
    // 0xD4 and locality byte are added during deviceOp
    uint32_t tpmAddress = i_tpmInfo.offset;

    TRACUCOMP( g_trac_tpmdd,
               "tpmRead() - address: 0x%08X, locality %d, length %d",
               tpmAddress, i_tpmInfo.locality, i_buflen );


    /***********************************************************/
    /* Attempt read multiple times on fails                    */
    /***********************************************************/
    for (size_t retry = 0;
         retry <= TPM_MAX_RETRIES;
         retry++)
    {
        size_t readLength = i_buflen;

        // Do the actual read via SPI
        err = deviceOp( DeviceFW::READ,
                        i_tpmInfo.spiTarget,
                        o_buffer,
                        readLength,
                        DEVICE_SPI_TPM_ADDRESS(
                                      i_tpmInfo.spiEngine,
                                      tpmAddress,
                                      i_tpmInfo.locality,
                                      i_tpmInfo.tpmTarget ) );
        if ( err == nullptr )
        {
            // Operation completed successfully
            // break from retry loop
            break;
        }
        else // Handle error
        {
            TRACFCOMP( g_trac_tpmdd,
                     ERR_MRK"tpmRead(): Error! "
                     "TPM 0x%08X, SPI controller 0x%08X, Engine %d, "
                     "address 0x%08X, readLength 0x%08X,"
                     "rc=0x%X, eid=0x%X",
                     get_huid(i_tpmInfo.tpmTarget),
                     get_huid(i_tpmInfo.spiTarget),
                     i_tpmInfo.spiEngine,
                     tpmAddress, readLength,
                     err->reasonCode(), err->eid() );

            // If op will be attempted again: save log and continue
            if ( retry < TPM_MAX_RETRIES )
            {
                // Only save original RETRY error
                if ( err_RETRY == nullptr )
                {
                    // Save original RETRY error
                    err_RETRY = err;

                    TRACFCOMP( g_trac_tpmdd,
                               ERR_MRK"tpmRead(): Save as Retry "
                               "SPI controller 0x%08X, Engine %d, "
                               "Address 0x%08X, "
                               "rc=0x%X, eid=0x%X, "
                               "retry/MAX=%d/%d. Save error and retry",
                               get_huid(i_tpmInfo.spiTarget),
                               i_tpmInfo.spiEngine, tpmAddress,
                               err->reasonCode(), err->eid(),
                               retry, TPM_MAX_RETRIES );
                    err_RETRY->collectTrace(TPMDD_COMP_NAME);
                    err = nullptr;
                }
                else
                {
                    // Add data to original error
                    TRACFCOMP( g_trac_tpmdd,
                               ERR_MRK"tpmRead(): Another Error! "
                               "SPI controller 0x%08X, Engine %d, "
                               "Address 0x%08X, "
                               "rc=0x%X, eid=0x%X, "
                               "retry/MAX=%d/%d. Delete error and retry",
                               get_huid(i_tpmInfo.spiTarget),
                               i_tpmInfo.spiEngine, tpmAddress,
                               err->reasonCode(), err->eid(),
                               retry, TPM_MAX_RETRIES );

                    ERRORLOG::ErrlUserDetailsString(
                              "Another ERROR found")
                              .addToLog(err_RETRY);

                    // Delete this new error
                    delete err;
                    err = nullptr;
                }

                // Add 250ms delay before retry:
                TRACFCOMP( g_trac_tpmdd,
                           "tpmRead(): sleep for 250ms before retry");
                nanosleep(0, TPM_MAX_RETRY_DELAY_NS);

                // continue to retry
                continue;
            }
            else // no more retries: trace and break
            {
                TRACFCOMP( g_trac_tpmdd,
                           ERR_MRK"tpmRead(): No More Retries! "
                           "SPI controller 0x%08X, Engine %d, "
                           "Address 0x%08X, "
                           "rc=0x%X, eid=0x%X, "
                           "retry/MAX=%d/%d. Returning Error",
                           get_huid(i_tpmInfo.spiTarget),
                           i_tpmInfo.spiEngine, tpmAddress,
                           err->reasonCode(), err->eid(),
                           retry, TPM_MAX_RETRIES );

                err->collectTrace(TPMDD_COMP_NAME);

                // break from retry loop
                break;
            }
        }
    } // end of retry loop

    // Handle saved error, if any
    if (err_RETRY)
    {
        if (err)
        {
            if (!i_silent)
            {
                // commit original RETRY error with new err PLID
                err_RETRY->plid(err->plid());
                TRACFCOMP(g_trac_tpmdd, "tpmRead(): Committing saved RETRY "
                          "err eid=0x%X with plid of returned err: 0x%X",
                          err_RETRY->eid(), err_RETRY->plid());

                ERRORLOG::ErrlUserDetailsTarget(i_tpmInfo.spiTarget)
                    .addToLog(err_RETRY);

                errlCommit(err_RETRY, TPMDD_COMP_ID);
            }
            else
            {
                TRACFCOMP( g_trac_tpmdd,
                    "tpmRead(): silently deleting original RETRY err "
                    "rc=0x%X, eid=0x%X with plid of 0x%X",
                    err_RETRY->reasonCode(), err_RETRY->eid(),
                    err_RETRY->plid() );
                delete err_RETRY;
                err_RETRY = nullptr;
            }
        }
        else
        {
            // Since we eventually succeeded, delete original RETRY error
            TRACFCOMP(g_trac_tpmdd, "tpmRead(): Op successful, "
                      "deleting saved RETRY err eid=0x%X, plid=0x%X",
                      err_RETRY->eid(), err_RETRY->plid());

            delete err_RETRY;
            err_RETRY = nullptr;
        }
    }

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmRead()" );
    return err;
}


// ------------------------------------------------------------------
// tpmWrite
// ------------------------------------------------------------------
errlHndl_t tpmWrite ( void * i_buffer,
                      size_t i_buflen,
                      const tpm_info_t & i_tpmInfo)
{
    errlHndl_t err       = nullptr;
    errlHndl_t err_RETRY = nullptr;

    // Trusted Computing Group (TCG) standard requires
    // 3-byte addressing for SPI TPM operations
    // 0xD4 [locality]0 00
    // 0xD4 and locality byte are added during deviceOp
    uint32_t tpmAddress = i_tpmInfo.offset;

    TRACDCOMP( g_trac_tpmdd, "tpmWrite() - address: 0x%08X, locality %d, "
               "buflen=%d", tpmAddress, i_tpmInfo.locality, i_buflen );

    TRACUCOMP( g_trac_tpmdd,
               "TPM WRITE START : Offset %.2X : Len %d : %016llx",
               i_tpmInfo.offset,
               i_buflen,
               *(reinterpret_cast<uint64_t*>(i_buffer)) );

    /***********************************************************/
    /* Attempt write multiple times ONLY on fails              */
    /***********************************************************/
    for (size_t retry = 0;
         retry <= TPM_MAX_RETRIES;
         retry++)
    {
        // Do the actual write via SPI
        err = deviceOp( DeviceFW::WRITE,
                        i_tpmInfo.spiTarget,
                        i_buffer,
                        i_buflen,
                        DEVICE_SPI_TPM_ADDRESS(
                                     i_tpmInfo.spiEngine,
                                     tpmAddress,
                                     i_tpmInfo.locality,
                                     i_tpmInfo.tpmTarget) );
        if ( err == nullptr )
        {
            // Operation completed successfully
            // break from retry loop
            break;
        }
        else // Handle error
        {
            TRACFCOMP( g_trac_tpmdd,
                     ERR_MRK"tpmWrite(): Error! "
                     "TPM 0x%08X, SPI controller 0x%08X Engine %d, "
                     "rc=0x%X, eid=0x%X, retry/MAX=%d/%d.",
                     get_huid(i_tpmInfo.tpmTarget),
                     get_huid(i_tpmInfo.spiTarget),
                     i_tpmInfo.spiEngine,
                     err->reasonCode(), err->eid(),
                     retry, TPM_MAX_RETRIES);

            // If op will be attempted again: save log and continue
            if ( retry < TPM_MAX_RETRIES )
            {
                // Only save original RETRY error
                if ( err_RETRY == nullptr )
                {
                    // Save original RETRY error
                    err_RETRY = err;

                    TRACFCOMP( g_trac_tpmdd,
                               ERR_MRK"tpmWrite(): RETRY Error! "
                               "0x%08X engine %d, OP=%d, "
                               "rc=0x%X, eid=0x%X, "
                               "retry/MAX=%d/%d. Save error and retry",
                               get_huid(i_tpmInfo.spiTarget),
                               i_tpmInfo.spiEngine,
                               i_tpmInfo.operation,
                               err_RETRY->reasonCode(),
                               err_RETRY->eid(),
                               retry, TPM_MAX_RETRIES);
                    err_RETRY->collectTrace(TPMDD_COMP_NAME);
                    err = nullptr;
                }
                else
                {
                    // Add data to original RETRY error
                    TRACFCOMP( g_trac_tpmdd,
                               ERR_MRK"tpmWrite(): Another RETRY Error! "
                               "SPI controller 0x%08X engine %d, OP=%d, "
                               "rc=0x%X, eid=0x%X "
                               "plid=0x%X, retry/MAX=%d/%d. "
                               "Delete error and retry",
                               get_huid(i_tpmInfo.spiTarget),
                               i_tpmInfo.spiEngine,
                               i_tpmInfo.operation,
                               err->reasonCode(), err->eid(), err->plid(),
                               retry, TPM_MAX_RETRIES);

                    ERRORLOG::ErrlUserDetailsString(
                              "Another ERROR found")
                              .addToLog(err_RETRY);

                    // Delete this new error
                    delete err;
                    err = nullptr;
                }

                // Add 250ms delay before retry
                TRACFCOMP( g_trac_tpmdd,
                           "tpmWrite(): sleep for 250ms before retry %d",
                           retry+1 );
                nanosleep(0, TPM_MAX_RETRY_DELAY_NS);

                // continue to retry
                continue;
            }
            else // no more retries: trace and break
            {
                TRACFCOMP( g_trac_tpmdd,
                           ERR_MRK"tpmWrite(): No More Retries! "
                           "0x%08X engine %d, OP=%d, "
                           "Error rc=0x%X, eid=%d, "
                           "retry/MAX=%d/%d. Returning Error",
                           get_huid(i_tpmInfo.spiTarget),
                           i_tpmInfo.spiEngine,
                           i_tpmInfo.operation,
                           err->reasonCode(), err->eid(),
                           retry, TPM_MAX_RETRIES);

                err->collectTrace(TPMDD_COMP_NAME);

                // break from retry loop
                break;
            }
        }
    } // retry for loop

    // Handle saved RETRY error, if any
    if (err_RETRY)
    {
        if (err)
        {
            // commit original RETRY error with new err PLID
            err_RETRY->plid(err->plid());
            TRACFCOMP(g_trac_tpmdd, "tpmWrite(): Committing saved RETRY "
                      "err eid=0x%X with plid of returned err: 0x%X",
                      err_RETRY->eid(), err_RETRY->plid());

            ERRORLOG::ErrlUserDetailsTarget(i_tpmInfo.spiTarget)
                                           .addToLog(err_RETRY);

            errlCommit(err_RETRY, TPMDD_COMP_ID);
            err_RETRY = nullptr;
        }
        else
        {
            // Since we eventually succeeded, delete original RETRY error
            TRACFCOMP(g_trac_tpmdd, "tpmWrite(): Op successful, "
                      "deleting saved RETRY err eid=0x%X, plid=0x%X",
                      err_RETRY->eid(), err_RETRY->plid());

            delete err_RETRY;
            err_RETRY = nullptr;
        }
    }

    TRACSCOMP( g_trac_tpmdd,
               "TPM WRITE END   : Offset %.2X : Len %d",
               i_tpmInfo.offset, i_buflen);
    return err;
} // tpmWrite


// ------------------------------------------------------------------
// tpmTransmit
// ------------------------------------------------------------------
errlHndl_t tpmTransmit ( void * io_buffer,
                         size_t & io_buflen,
                         size_t i_commandlen,
                         const tpm_info_t & i_tpmInfo )
{
    errlHndl_t err = nullptr;
    bool isReady = false;

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmTransmit()" );

    do
    {

        TRACUCOMP( g_trac_tpmdd,
                   "TPM TRANSMIT START : BufLen %d : CmdLen %d : %016llx",
                   io_buflen, i_commandlen,
                   *(reinterpret_cast<uint64_t*>(io_buffer))  );

        // Verify the TPM is ready to receive our command
        err = tpmIsCommandReady(i_tpmInfo, isReady);
        if( err )
        {
            break;
        }

        if (!isReady)
        {
            // set TPM into command ready state
            err = tpmWriteCommandReady(i_tpmInfo);
            if( err )
            {
                break;
            }

            // Verify the TPM is now ready to receive our command
            err = tpmPollForCommandReady(i_tpmInfo);
            if( err )
            {
                break;
            }
        }

        // Write the command into the TPM FIFO
        err = tpmWriteFifo(i_tpmInfo,
                           io_buffer, i_commandlen);
        if( err )
        {
            break;
        }

        TRACUCOMP( g_trac_tpmdd,
                   "TPM TRANSMIT tpmWriteTpmGo" );
        err = tpmWriteTpmGo(i_tpmInfo);
        if( err )
        {
            break;
        }

        // Read the response from the TPM FIFO
        TRACUCOMP( g_trac_tpmdd,
                   "TPM TRANSMIT tpmReadFifo(length: %d)", io_buflen );
        err = tpmReadFifo(i_tpmInfo,
                          io_buffer, io_buflen);
        if( err )
        {
            break;
        }

        TRACUCOMP( g_trac_tpmdd,
                   "TPM TRANSMIT tpmWriteCommandReady" );
        err = tpmWriteCommandReady(i_tpmInfo);
        if( err )
        {
            break;
        }

    } while( 0 );

    TRACUCOMP( g_trac_tpmdd,
               "TPM TRANSMIT END   : BufLen %d : CmdLen %d : %016llx",
               io_buflen, i_commandlen,
               *(reinterpret_cast<uint64_t*>(io_buffer))  );

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmTransmit()" );

    return err;

} // end tpmTransmit


errlHndl_t tpmReadAttributes ( TARGETING::Target * i_target,
                               tpm_info_t & io_tpmInfo,
                               tpm_locality_t i_locality )
{
    errlHndl_t err = nullptr;

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmReadAttributes()" );

    // These variables will be used to hold the TPM attribute data
    TARGETING::SpiTpmInfo tpmData;
    uint8_t tpmModel = TPM_MODEL_UNDETERMINED;

    do
    {
        if( !( i_target->
               tryGetAttr<TARGETING::ATTR_SPI_TPM_INFO>
               ( tpmData ) ) )

        {
            const auto type = i_target->getAttr<TARGETING::ATTR_TYPE>();

            TRACFCOMP(g_trac_tpmdd,ERR_MRK
                "tpmReadAttributes: Failed to read SPI_TPM_INFO "
                "attribute from target HUID=0x%08X of type=0x%08X.",
                TARGETING::get_huid(i_target), type);

            /*@
             * @errortype
             * @reasoncode TPM_ATTR_INFO_NOT_FOUND
             * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid   TPMDD_READATTRIBUTES
             * @userdata1  HUID of target
             * @userdata2  Type of target
             * @devdesc    SPI_TPM_INFO attribute was not found for the
             *             requested target
             * @custdesc   Unexpected trusted boot related failure
             */
            err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          TPMDD_READATTRIBUTES,
                                          TPM_ATTR_INFO_NOT_FOUND,
                                          TARGETING::get_huid(i_target),
                                          type);

            // Could be FSP or HB code's fault
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_MED);
            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_MED);

            err->collectTrace( TPMDD_COMP_NAME );

            break;
        }

        if( !( i_target->
               tryGetAttr<TARGETING::ATTR_TPM_ENABLED>
               ( io_tpmInfo.tpmEnabled ) ) )

        {
            const auto type = i_target->getAttr<TARGETING::ATTR_TYPE>();

            TRACFCOMP(g_trac_tpmdd,ERR_MRK
                "tpmReadAttributes: Failed to read TPM_ENABLED "
                "attribute from target HUID=0x%08X of type=0x%08X.",
                TARGETING::get_huid(i_target),
                type);

            /*@
             * @errortype
             * @reasoncode TPM_ATTR_TPM_ENABLED_NOT_FOUND
             * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid   TPMDD_READATTRIBUTES
             * @userdata1  HUID of target
             * @userdata2  Type of target
             * @devdesc    TPM_ENABLED attribute was not found for the
             *             requested target
             * @custdesc   Unexpected trusted boot related failure
             */
            err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          TPMDD_READATTRIBUTES,
                                          TPM_ATTR_TPM_ENABLED_NOT_FOUND,
                                          TARGETING::get_huid(i_target),
                                          type);

            // Could be FSP or HB code's fault
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_MED);
            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( TPMDD_COMP_NAME );

            break;
        }

        if( !( i_target->
               tryGetAttr<TARGETING::ATTR_TPM_MODEL>
               ( tpmModel ) ) )

        {
            const auto type = i_target->getAttr<TARGETING::ATTR_TYPE>();

            TRACFCOMP(g_trac_tpmdd,ERR_MRK
                "tpmReadAttributes: Failed to read TPM_MODEL "
                "attribute from target HUID=0x%08X of type=0x%08X.",
                TARGETING::get_huid(i_target),
                type);

            /*@
             * @errortype
             * @reasoncode TPM_ATTR_MODEL_NOT_FOUND
             * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid   TPMDD_READATTRIBUTES
             * @userdata1  HUID of target
             * @userdata2  Type of target
             * @devdesc    TPM_MODEL attribute was not found for the
             *     requested target
             * @custdesc   Unexpected trusted boot related failure
             */
            err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          TPMDD_READATTRIBUTES,
                                          TPM_ATTR_MODEL_NOT_FOUND,
                                          TARGETING::get_huid(i_target),
                                          type);

            // Could be FSP or HB code's fault
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_MED);
            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( TPMDD_COMP_NAME );

            break;
        }


        if (tpmModel == TPM_MODEL_75x)
        {
            io_tpmInfo.model          = tpmModel;
            io_tpmInfo.sts            = TPM_REG_75x_STS;
            io_tpmInfo.burstCount     = TPM_REG_75x_BURSTCOUNT;
            io_tpmInfo.tpmHash        = TPM_REG_75x_TPM_HASH;
            io_tpmInfo.wrFifo         = TPM_REG_75x_WR_FIFO;
            io_tpmInfo.rdFifo         = TPM_REG_75x_RD_FIFO;
            io_tpmInfo.vendorIdOffset = TPM_REG_75x_VENDOR_ID_OFFSET;
            io_tpmInfo.vendorId       = TPM_VENDORID_75x;
        }
        else
        {
            // Fail since invalid/unsupported TPM model is found
            TRACFCOMP(g_trac_tpmdd,ERR_MRK
                      "tpmReadAttributes: Invalid TPM_MODEL %d from "
                      "attribute from target HUID=0x%08X",
                      tpmModel, TARGETING::get_huid(i_target));

            /*@
             * @errortype
             * @reasoncode TPM_ATTR_INVALID_MODEL
             * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid   TPMDD_READATTRIBUTES
             * @userdata1  TPM Model of target
             * @userdata2  HUID of target
             * @devdesc    TPM_MODEL attribute was set to a value that
             *             is not currently supported
             * @custdesc   Unexpected trusted boot related failure
             */
            err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          TPMDD_READATTRIBUTES,
                                          TPM_ATTR_INVALID_MODEL,
                                          tpmModel,
                                          TARGETING::get_huid(i_target));

            // Could be FSP or HB code's fault
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_MED);
            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( TPMDD_COMP_NAME );
            break;
        }

        io_tpmInfo.locality      = i_locality;
        io_tpmInfo.tpmTarget     = i_target;
        io_tpmInfo.spiEngine     = tpmData.engine;
        io_tpmInfo.spiControllerPath = tpmData.spiMasterPath;
        err = tpmGetSPIControllerTarget(i_target, io_tpmInfo );
        if (err)
        {
            TRACFCOMP(g_trac_tpmdd,
                ERR_MRK"Error in tpmReadAttributes::tpmGetSPIControllerTarget()"
                " RC 0x%X", err->reasonCode());
            break;
        }

        TRACUCOMP( g_trac_tpmdd, "tpmReadAttributes() TPM tgt=0x%.8X, "
                   "SPI controller 0x%.8X Engine %d Locality %d, Enable=%d",
                   TARGETING::get_huid(io_tpmInfo.tpmTarget),
                   TARGETING::get_huid(io_tpmInfo.spiTarget),
                   io_tpmInfo.spiEngine,
                   io_tpmInfo.locality,
                   io_tpmInfo.tpmEnabled );
    } while (0);

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmReadAttributes()" );
    return err;
}


// ------------------------------------------------------------------
// tpmGetSPIControllerTarget
// ------------------------------------------------------------------
errlHndl_t tpmGetSPIControllerTarget ( TARGETING::Target * i_target,
                                       tpm_info_t & io_tpmInfo )
{
    errlHndl_t err = nullptr;

    TRACDCOMP( g_trac_tpmdd,
               ENTER_MRK"tpmGetSPIControllerTarget()" );

    do
    {
        TARGETING::TargetService& tS = TARGETING::targetService();

        // The path from i_target to its SPI controller was read from the
        // attribute via tpmReadAttributes() and passed to this function
        // in io_tpmInfo.spiControllerPath

        // check that the path exists
        bool exists = false;
        tS.exists( io_tpmInfo.spiControllerPath, exists );

        if( !exists )
        {
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmGetSPIControllerTarget() - "
                       "spiControllerPath attribute path doesn't exist!" );

            // Compress the spiControllerPath entity path into a uint64_t value
            // Format is up to 4 path elements defined like type:8 instance:8
            uint64_t l_epCompressed = 0;
            for( uint32_t i = 0; i < io_tpmInfo.spiControllerPath.size(); i++ )
            {
                // Path element: type:8 instance:8
                l_epCompressed |=
                    io_tpmInfo.spiControllerPath[i].type << ((16*(3-i))+8);
                l_epCompressed |=
                    io_tpmInfo.spiControllerPath[i].instance << (16*(3-i));

                // Can only fit 4 path elements into 64 bits
                if ( i == 3 )
                {
                    break;
                }
            }

            /*@
             * @errortype
             * @reasoncode       TPM_SPI_CONTROLLER_PATH_ERROR
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         TPMDD_GETSPICONTROLLERTARGET
             * @userdata1        HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          SPI controller entity path doesn't exist.
             */
            err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                TPMDD_GETSPICONTROLLERTARGET,
                                TPM_SPI_CONTROLLER_PATH_ERROR,
                                TARGETING::get_huid(i_target),
                                l_epCompressed,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( TPMDD_COMP_NAME );

            char* l_controllerPath = io_tpmInfo.spiControllerPath.toString();
            ERRORLOG::ErrlUserDetailsString(l_controllerPath).addToLog(err);
            free(l_controllerPath);
            l_controllerPath = nullptr;

            break;
        }

        // Since it exists, convert to a target
        io_tpmInfo.spiTarget = tS.toTarget( io_tpmInfo.spiControllerPath );

        if( nullptr == io_tpmInfo.spiTarget )
        {
            TRACFCOMP( g_trac_tpmdd,
                ERR_MRK"tpmGetSPIControllerTarget() - SPI Controller "
                "Path target was NULL!" );

            // Compress the entity path
            uint64_t l_epCompressed = 0;
            for( uint32_t i = 0; i < io_tpmInfo.spiControllerPath.size(); i++ )
            {
                // Path element: type:8 instance:8
                l_epCompressed |=
                    io_tpmInfo.spiControllerPath[i].type << ((16*(3-i))+8);
                l_epCompressed |=
                    io_tpmInfo.spiControllerPath[i].instance << (16*(3-i));

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
             * @moduleid         TPMDD_GETSPICONTROLLERTARGET
             * @userdata1        HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          SPI controller path target is null.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           TPMDD::TPMDD_GETSPICONTROLLERTARGET,
                                           TPMDD::TPM_TARGET_NULL,
                                           TARGETING::get_huid(i_target),
                                           l_epCompressed,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( TPMDD_COMP_NAME );

            char* l_controllerPath = io_tpmInfo.spiControllerPath.toString();
            ERRORLOG::ErrlUserDetailsString(l_controllerPath).addToLog(err);
            free(l_controllerPath);
            l_controllerPath = nullptr;

            break;
        }


    } while( 0 );

    TRACDCOMP( g_trac_tpmdd,
               EXIT_MRK"tpmGetSPIControllerTarget()" );

    return err;
} // end tpmGetSPIControllerTarget


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
    errlHndl_t err = nullptr;

    i_tpmInfo.offset = i_offset;
    err =  tpmRead( o_buffer,
                    i_buflen,
                    i_tpmInfo );

    return err;

} // end tpmReadReg

errlHndl_t tpmReadSTSReg ( tpm_info_t i_tpmInfo,
                           tpm_sts_reg_t & o_stsReg)
{
    i_tpmInfo.offset = i_tpmInfo.sts;

    return tpmRead(reinterpret_cast<void*>(&o_stsReg),
                   1,
                   i_tpmInfo);
} // end tpmReadSTSReg

errlHndl_t tpmReadSTSRegValid ( tpm_info_t i_tpmInfo,
                                tpm_sts_reg_t & o_stsReg)
{
    errlHndl_t err = nullptr;

    i_tpmInfo.offset = i_tpmInfo.sts;

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

        if (polls > TPMDD::MAX_STSVALID_POLLS && !(o_stsReg.stsValid))
        {
            TRACFCOMP( g_trac_tpmdd,
                ERR_MRK"tpmReadSTSRegValid(): Timeout! "
                "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, %02X status",
                TARGETING::get_huid(i_tpmInfo.tpmTarget),
                TARGETING::get_huid(i_tpmInfo.spiTarget),
                i_tpmInfo.spiEngine, o_stsReg.value );

            /*@
             * @errortype
             * @reasoncode       TPM_TIMEOUT
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         TPMDD_READSTSREGVALID
             * @userdata1        TPM
             * @userdata2[0:31]  Operation
             * @userdata2[32:63] STS Reg
             * @devdesc          TPM timeout waiting for stsValid
             * @custdesc         A problem occurred during the IPL of the
             *                   system: TPM timeout
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    TPMDD_READSTSREGVALID,
                                    TPM_TIMEOUT,
                                    TARGETING::get_huid(i_tpmInfo.tpmTarget),
                                    TWO_UINT32_TO_UINT64(
                                         i_tpmInfo.operation,
                                         o_stsReg.value),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

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


errlHndl_t tpmIsCommandReady( const tpm_info_t & i_tpmInfo,
                              bool & o_isReady)
{
    tpm_sts_reg_t stsReg;
    errlHndl_t err = tpmReadSTSReg(i_tpmInfo,
                                   stsReg);
    o_isReady = false;

    if (nullptr == err && stsReg.isCommandReady)
    {
        o_isReady = true;
    }
    return err;

} // end tpmIsCommandReady

errlHndl_t tpmPollForCommandReady( const tpm_info_t & i_tpmInfo)
{
    tpm_sts_reg_t stsReg;
    errlHndl_t err = nullptr;

    // Operation TIMEOUT_B defined by TCG spec for command ready
    for (size_t delay = 0; delay < TPMDD::TPM_TIMEOUT_B; delay += 10)
    {
        err = tpmReadSTSReg(i_tpmInfo,
                            stsReg);
        if ((nullptr == err && stsReg.isCommandReady) ||
            (nullptr != err))
        {
            break;
        }
        // Sleep 10ms before attempting another read
        nanosleep(0, 10 * NS_PER_MSEC);

    }

    if (nullptr == err && !stsReg.isCommandReady)
    {
        // The first write to command ready may have just aborted
        //   an outstanding command, we will write it again and poll once
        //   more
        err = tpmWriteCommandReady(i_tpmInfo);

        if (nullptr == err)
        {
            // Ok, poll again
            // Operation TIMEOUT_B defined by TCG spec for command ready
            for (size_t delay = 0; delay < TPMDD::TPM_TIMEOUT_B; delay += 10)
            {
                err = tpmReadSTSReg(i_tpmInfo,
                                    stsReg);
                if ((nullptr == err && stsReg.isCommandReady) ||
                    (nullptr != err))
                {
                    break;
                }
                // Sleep 10ms before attempting another read
                nanosleep(0, 10 * NS_PER_MSEC);
            }
        }
    }


    if (nullptr == err && !stsReg.isCommandReady)
    {
        // Timed out waiting for TPM to be ready
        TRACFCOMP( g_trac_tpmdd,
                   ERR_MRK"tpmPollForCommandReady() - "
                   "Timeout polling for command ready! "
                   "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, "
                   "OP=%d, STS=0x%X",
                   TARGETING::get_huid(i_tpmInfo.tpmTarget),
                   TARGETING::get_huid(i_tpmInfo.spiTarget),
                   i_tpmInfo.spiEngine,
                   i_tpmInfo.operation,
                   stsReg.value );

        /*@
         * @errortype
         * @reasoncode   TPM_TIMEOUT
         * @severity     ERRL_SEV_UNRECOVERABLE
         * @moduleid     TPMDD_POLLFORCOMMMANDREADY
         * @userdata1    TPM
         * @userdata2    STS Reg
         * @devdesc      Timeout waiting for TPM to enter command ready state.
         * @custdesc     TPM operation failure
         */
        err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    TPMDD_POLLFORCOMMMANDREADY,
                                    TPM_TIMEOUT,
                                    TARGETING::get_huid(i_tpmInfo.tpmTarget),
                                    stsReg.value,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        err->collectTrace( TPMDD_COMP_NAME );

        char* l_controllerPath = i_tpmInfo.spiControllerPath.toString();
        ERRORLOG::ErrlUserDetailsString(l_controllerPath).addToLog(err);
        free(l_controllerPath);
        l_controllerPath = nullptr;
    }
    return err;

} // end tpmPollForCommandReady

errlHndl_t tpmIsExpecting( const tpm_info_t & i_tpmInfo,
                           bool & o_isExpecting)
{
    tpm_sts_reg_t stsReg;
    errlHndl_t err = tpmReadSTSRegValid(i_tpmInfo,
                                        stsReg);
    o_isExpecting = false;

    if (nullptr == err && stsReg.expect)
    {
        o_isExpecting = true;
    }
    return err;

} // end tpmIsExpecting

errlHndl_t tpmIsDataAvail( const tpm_info_t & i_tpmInfo,
                           bool & o_isDataAvail)
{
    tpm_sts_reg_t stsReg;
    errlHndl_t err = tpmReadSTSRegValid(i_tpmInfo,
                                        stsReg);
    o_isDataAvail = false;

    if (nullptr == err && stsReg.dataAvail)
    {
        o_isDataAvail = true;
    }
    return err;

} // end tpmIsDataAvail

errlHndl_t tpmPollForDataAvail( const tpm_info_t & i_tpmInfo)
{
    tpm_sts_reg_t stsReg;
    errlHndl_t err = nullptr;

    // Use the longer timeout B here since some of the TPM commands may take
    // more than timeout A to complete
    for (size_t delay = 0; delay < TPMDD::TPM_TIMEOUT_B; delay += 10)
    {
        err = tpmReadSTSRegValid(i_tpmInfo,
                                 stsReg);
        if ((err != nullptr) && err->reasonCode() == TPM_TIMEOUT)
        {
            // Polling loop within tpmReadSTSRegValid timed out, delete error and try again.
            delete err;
            err = nullptr;
        }

        if ((nullptr == err && stsReg.dataAvail) ||
            (nullptr != err))
        {
            break;
        }
        // Sleep 10ms before attempting another read
        nanosleep(0, 10 * NS_PER_MSEC);

    }

    if (nullptr == err && !stsReg.dataAvail)
    {
        // Timed out waiting for TPM to have more data available
        TRACFCOMP( g_trac_tpmdd,
                   ERR_MRK"tpmPollForDataAvail() - "
                   "Timeout polling for dataAvail! "
                   "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, "
                   "OP=%d, STS=0x%X",
                   TARGETING::get_huid(i_tpmInfo.tpmTarget),
                   TARGETING::get_huid(i_tpmInfo.spiTarget),
                   i_tpmInfo.spiEngine,
                   i_tpmInfo.operation,
                   stsReg.value );

        /*@
         * @errortype
         * @reasoncode       TPM_TIMEOUT
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         TPMDD_POLLFORDATAAVAIL
         * @userdata1        TPM
         * @userdata2        STS Reg
         * @devdesc          Timeout waiting for TPM data available.
         * @custdesc         TPM operation failure
         */
        err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      TPMDD_POLLFORDATAAVAIL,
                                      TPM_TIMEOUT,
                                      TARGETING::get_huid(i_tpmInfo.tpmTarget),
                                      stsReg.value,
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        err->collectTrace( TPMDD_COMP_NAME );

        char* l_controllerPath = i_tpmInfo.spiControllerPath.toString();
        ERRORLOG::ErrlUserDetailsString(l_controllerPath).addToLog(err);
        free(l_controllerPath);
        l_controllerPath = nullptr;
    }
    return err;

} // end tpmPollForDataAvail

errlHndl_t tpmReadBurstCount( const tpm_info_t & i_tpmInfo,
                              uint16_t & o_burstCount)
{
    errlHndl_t err = nullptr;
    o_burstCount = 0;

    // Read the burst count
    uint16_t burstCount = 0;
    if (nullptr == err)
    {
        err = tpmReadReg(i_tpmInfo,
                         i_tpmInfo.burstCount,
                         2,
                         reinterpret_cast<void*>(&burstCount));
    }

    if (nullptr == err)
    {
        o_burstCount = (burstCount & 0x00FF) << 8;
        o_burstCount |= (burstCount & 0xFF00) >> 8;
    }
    TRACUCOMP( g_trac_tpmdd,
               "tpmReadBurstCount() - BurstCount %d",
               o_burstCount);


    return err;

} // end tpmReadBurstCount



errlHndl_t tpmWriteCommandReady( const tpm_info_t & i_tpmInfo)
{
    tpm_sts_reg_t stsReg;
    stsReg.value = 0;
    stsReg.isCommandReady = 1;

    return tpmWriteReg(i_tpmInfo,
                       i_tpmInfo.sts,
                       1,
                       reinterpret_cast<void*>(&stsReg));

} // end tpmWriteCommandReady

errlHndl_t tpmWriteTpmGo( const tpm_info_t & i_tpmInfo)
{
    tpm_sts_reg_t stsReg;
    stsReg.value = 0;
    stsReg.tpmGo = 1;

    return tpmWriteReg(i_tpmInfo,
                       i_tpmInfo.sts,
                       1,
                       reinterpret_cast<void*>(&stsReg));

} // end tpmWriteTpmGo

errlHndl_t tpmWriteResponseRetry( const tpm_info_t & i_tpmInfo)
{
    tpm_sts_reg_t stsReg;
    stsReg.value = 0;
    stsReg.responseRetry = 1;

    return tpmWriteReg(i_tpmInfo,
                       i_tpmInfo.sts,
                       1,
                       reinterpret_cast<void*>(&stsReg));

} // end tpmWriteResponseRetry


errlHndl_t tpmWriteFifo( const tpm_info_t & i_tpmInfo,
                         void * i_buffer,
                         size_t i_buflen)
{
    size_t delay = 0;
    size_t curByte = 0;
    uint8_t* bytePtr = (uint8_t*)i_buffer;
    uint8_t* curBytePtr = nullptr;
    uint16_t burstCount = 0;
    errlHndl_t err = nullptr;
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

        // Single operations are limited to TPM SPI transmit size
        if (burstCount > TPM_MAX_SPI_TRANSMIT_SIZE)
        {
            burstCount = TPM_MAX_SPI_TRANSMIT_SIZE;
        }

        // Send in some data
        delay = 0;
        curBytePtr = &(bytePtr[curByte]);
        tx_len = (curByte + burstCount > length ?
                  (length - curByte) :
                  burstCount);
        TRACUCOMP( g_trac_tpmdd, "tpmWriteFifo: send some data %d tx_len", tx_len);
        err = tpmWriteReg(i_tpmInfo,
                          i_tpmInfo.wrFifo,
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

        if ((nullptr == err) && (!expecting))
        {
            // TPM is not expecting more data, we overflowed
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmWriteFifo(): Data Overflow! "
                       "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, "
                       "OP=%d, blen=%d, clen=%d",
                       TARGETING::get_huid(i_tpmInfo.tpmTarget),
                       TARGETING::get_huid(i_tpmInfo.spiTarget),
                       i_tpmInfo.spiEngine,
                       i_tpmInfo.operation,
                       i_buflen, curByte);

            /*@
             * @errortype
             * @reasoncode       TPM_OVERFLOW_ERROR
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         TPMDD_WRITEFIFO
             * @userdata1        TPM
             * @userdata2[0:31]  Current byte
             * @userdata2[32:63] Buffer Length      (in Bytes)
             * @devdesc          TPM expected less data during FIFO write
             * @custdesc         A problem occurred during the IPL of the
             *                   system: TPM overflow
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      TPMDD_WRITEFIFO,
                                      TPM_OVERFLOW_ERROR,
                                      TARGETING::get_huid(i_tpmInfo.tpmTarget),
                                      TWO_UINT32_TO_UINT64(
                                          curByte,
                                          i_buflen       ),
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

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

    if (nullptr == err &&
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
            TRACUCOMP( g_trac_tpmdd, "tpmWriteFifo: tpmWriteReg final byte, 0x%02X", *curBytePtr);
            err = tpmWriteReg(i_tpmInfo,
                              i_tpmInfo.wrFifo,
                              1,
                              curBytePtr);
            // done
            break;
            // Operation TIMEOUT_D defined by TCG spec for FIFO availability
        } while (delay < TPMDD::TPM_TIMEOUT_D);

    }


    if (nullptr == err &&
        delay >= TPMDD::TPM_TIMEOUT_D)
    {
        TRACFCOMP( g_trac_tpmdd,
                   ERR_MRK"tpmWriteFifo(): Timeout! "
                   "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, "
                   "OP=%d, blen=%d, clen=%d",
                   TARGETING::get_huid(i_tpmInfo.tpmTarget),
                   TARGETING::get_huid(i_tpmInfo.spiTarget),
                   i_tpmInfo.spiEngine,
                   i_tpmInfo.operation,
                   i_buflen, curByte);

        /*@
         * @errortype
         * @reasoncode       TPM_TIMEOUT
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         TPMDD_WRITEFIFO
         * @userdata1        TPM
         * @userdata2[0:31]  Current Byte
         * @userdata2[32:63] Buffer Length      (in Bytes)
         * @devdesc          TPM timeout writing to FIFO
         * @custdesc         A problem occurred during the IPL of the
         *                   system: TPM timeout
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       TPMDD_WRITEFIFO,
                                       TPM_TIMEOUT,
                                       TARGETING::get_huid(i_tpmInfo.tpmTarget),
                                       TWO_UINT32_TO_UINT64(
                                               curByte,
                                               i_buflen       ),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        err->collectTrace( TPMDD_COMP_NAME );
    }



    if (nullptr == err)
    {
        err = tpmIsExpecting(i_tpmInfo,
                             expecting);

        if ((nullptr == err) && expecting)
        {
            // TPM is expecting more data even though we think we are done
            TRACFCOMP( g_trac_tpmdd,
                       ERR_MRK"tpmWriteFifo(): Data Underflow! "
                       "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, "
                       "OP=%d, blen=%d, clen=%d",
                       TARGETING::get_huid(i_tpmInfo.tpmTarget),
                       TARGETING::get_huid(i_tpmInfo.spiTarget),
                       i_tpmInfo.spiEngine,
                       i_tpmInfo.operation,
                       i_buflen, curByte);


            /*@
             * @errortype
             * @reasoncode       TPM_UNDERFLOW_ERROR
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         TPMDD_WRITEFIFO
             * @userdata1        TPM
             * @userdata2[0:31]  Current Byte
             * @userdata2[32:63] Buffer Length      (in Bytes)
             * @devdesc          TPM expected more data during FIFO write
             * @custdesc         A problem occurred during the IPL of the
             *                   system: TPM underflow
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      TPMDD_WRITEFIFO,
                                      TPM_UNDERFLOW_ERROR,
                                      TARGETING::get_huid(i_tpmInfo.tpmTarget),
                                      TWO_UINT32_TO_UINT64(
                                          curByte,
                                          i_buflen       ),
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( TPMDD_COMP_NAME );
        }

    }



    return err;

} // end tpmWriteFifo

errlHndl_t tpmReadFifo( const tpm_info_t & i_tpmInfo,
                        void * o_buffer,
                        size_t & io_buflen)
{
    size_t delay = 0;
    size_t curByte = 0;
    uint8_t* bytePtr = (uint8_t*)o_buffer;
    uint8_t* curBytePtr = nullptr;
    uint16_t burstCount = 0;
    errlHndl_t err = nullptr;
    bool dataAvail = false;
    bool firstRead = true;
    uint16_t dataLen = 0;
    uint32_t responseSize = 0;
    uint32_t dataLeft = io_buflen;

    // all command responses are at least 10 bytes of data
    // 2 byte tag + 4 byte response size + 4 byte response code
    const uint32_t MIN_COMMAND_RESPONSE_SIZE = 10;

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

            // Read some data
            if (firstRead)
            {
                dataLen = MIN_COMMAND_RESPONSE_SIZE;
            }
            else if (burstCount < dataLeft)
            {
                dataLen = burstCount;
            }
            else
            {
                dataLen = dataLeft;
            }

            // Check for a buffer overflow
            if (curByte + dataLen > io_buflen)
            {
                // TPM is expecting more data even though we think we are done
                TRACFCOMP( g_trac_tpmdd,
                           ERR_MRK"tpmReadFifo(): Data Overflow! "
                           "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, "
                           "OP=%d, blen=%d, clen=%d",
                           TARGETING::get_huid(i_tpmInfo.tpmTarget),
                           TARGETING::get_huid(i_tpmInfo.spiTarget),
                           i_tpmInfo.spiEngine,
                           i_tpmInfo.operation,
                           io_buflen, curByte + dataLen);

                /*@
                 * @errortype
                 * @reasoncode       TPM_OVERFLOW_ERROR
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         TPMDD_READFIFO
                 * @userdata1        TPM
                 * @userdata2[0:15]  Operation
                 * @userdata2[16:31] Current Byte
                 * @userdata2[32:63] Buffer Length      (in Bytes)
                 * @devdesc          TPM provided more data during FIFO read
                 *                   then buffer space provided
                 * @custdesc         A problem occurred during the IPL of the
                 *                   system: TPM overflow
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     TPMDD_READFIFO,
                                     TPM_OVERFLOW_ERROR,
                                     TARGETING::get_huid(i_tpmInfo.tpmTarget),
                                     TWO_UINT32_TO_UINT64(
                                       TWO_UINT16_TO_UINT32(i_tpmInfo.operation,
                                                            curByte),
                                       io_buflen),
                                     ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                err->collectTrace( TPMDD_COMP_NAME );
                break;
            }

            delay = 0;
            curBytePtr = &(bytePtr[curByte]);
            TRACUCOMP( g_trac_tpmdd, "tpmReadFifo: tpmReadReg() %d length",
                       dataLen );
            err = tpmReadReg(i_tpmInfo,
                             i_tpmInfo.rdFifo,
                             dataLen,
                             curBytePtr);
            if (err)
            {
                break;
            }

            if (firstRead)
            {
                TRACUBIN( g_trac_tpmdd, "tpmReadFifo: firstRead", curBytePtr, dataLen );
                responseSize = *(reinterpret_cast<uint32_t*>((curBytePtr + 2)));
                TRACUCOMP( g_trac_tpmdd, "tpmReadFifo: total size = 0x%08X", responseSize );
                dataLeft = responseSize;
                firstRead = false;
            }
            curByte += dataLen;
            dataLeft -= dataLen;

            err = tpmIsDataAvail(i_tpmInfo,
                                 dataAvail);
            if (err || !dataAvail)
            {
                break;
            }
            if ((dataLeft == 0) && dataAvail)
            {
                // Either the available STS is wrong or
                // responseSize in firstRead response was wrong
                TRACFCOMP( g_trac_tpmdd,
                    ERR_MRK "tpmReadFifo: data should not be available anymore"
                    " (response size in response: 0x%04X)", responseSize );

                /*@
                 * @errortype
                 * @reasoncode       TPM_EXTRA_DATA_AVAILABLE
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         TPMDD_READFIFO
                 * @userdata1        TPM
                 * @userdata2[0:31]  responseSize returned in first data bytes
                 * @userdata2[32:63] Buffer Length (in Bytes)
                 * @devdesc          Either the available STS from TPM is wrong
                 *                   or responseSize was wrong
                 * @custdesc         A problem occurred during the IPL of the
                 *                   system: TPM read failure
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      TPMDD_READFIFO,
                                      TPM_EXTRA_DATA_AVAILABLE,
                                      TARGETING::get_huid(i_tpmInfo.tpmTarget),
                                      TWO_UINT32_TO_UINT64(
                                         responseSize,
                                         io_buflen),
                                      ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

                err->addHwCallout(i_tpmInfo.tpmTarget,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::NO_DECONFIG,
                                  HWAS::GARD_NULL);

                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);

                err->collectTrace(TPMDD_COMP_NAME);
                break;
            }

            // Operation TIMEOUT_D defined by TCG spec for FIFO availability
        } while (delay < TPMDD::TPM_TIMEOUT_D);

    }

    if (!err && delay >= TPMDD::TPM_TIMEOUT_D)
    {
        TRACFCOMP( g_trac_tpmdd,
                   ERR_MRK"tpmReadFifo(): Timeout! "
                   "TPM HUID=0x%08X, SPI HUID=0x%08X, Engine=%d, "
                   "OP=%d, blen=%d, clen=%d",
                   TARGETING::get_huid(i_tpmInfo.tpmTarget),
                   TARGETING::get_huid(i_tpmInfo.spiTarget),
                   i_tpmInfo.spiEngine,
                   i_tpmInfo.operation,
                   io_buflen, curByte);

        /*@
         * @errortype
         * @reasoncode       TPM_TIMEOUT
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         TPMDD_READFIFO
         * @userdata1        TPM
         * @userdata2[0:15]  Operation
         * @userdata2[16:31] Current Byte
         * @userdata2[32:63] Buffer Length      (in Bytes)
         * @devdesc          TPM timeout reading from FIFO
         * @custdesc         A problem occurred during the IPL of the
         *                   system: TPM timeout
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     TPMDD_READ,
                                     TPM_TIMEOUT,
                                     TARGETING::get_huid(i_tpmInfo.tpmTarget),
                                     TWO_UINT32_TO_UINT64(
                                       TWO_UINT16_TO_UINT32(i_tpmInfo.operation,
                                                            curByte),
                                       io_buflen),
                                     ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        err->collectTrace( TPMDD_COMP_NAME );
    }

    if (nullptr == err)
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
