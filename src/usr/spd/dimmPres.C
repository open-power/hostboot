//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/spd/dimmPres.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 * @file dimmPres.C
 *
 * @brief Implementation of the DIMM Presence detect.
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/targetservice.H>
#include <devicefw/driverif.H>
#include <spd/spdreasoncodes.H>
#include <spd/spdenums.H>

#include "spd.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t * g_trac_spd;

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

// ----------------------------------------------
// Defines
// ----------------------------------------------


namespace SPD
{

// Register the Presence detect code with the framework.
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::PRESENT,
                       TARGETING::TYPE_DIMM,
                       dimmPresenceDetect );

// ------------------------------------------------------------------
// dimmPresenceDetect
// ------------------------------------------------------------------
errlHndl_t dimmPresenceDetect( DeviceFW::OperationType i_opType,
                               TARGETING::Target * i_target,
                               void * io_buffer,
                               size_t & io_buflen,
                               int64_t i_accessType,
                               va_list i_args )
{
    errlHndl_t err = NULL;
    bool present = false;
    size_t presentSz = sizeof(present);

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdPresenceDetect()" );

    do
    {
        // Check to be sure that the buffer is big enough.
        if( !(io_buflen >= sizeof(bool)) )
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"spdPresenceDetect() - Invalid Data Length: %d",
                       io_buflen );

            /*@
             * @errortype
             * @reasoncode       SPD_INSUFFICIENT_BUFFER_SIZE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_PRESENCE_DETECT
             * @userdata1        Buffer Length
             * @userdata2        <UNUSED>
             * @devdesc          Buffer for checking Presence Detect was not the correct size.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_PRESENCE_DETECT,
                                           SPD_INSUFFICIENT_BUFFER_SIZE,
                                           TO_UINT64(io_buflen),
                                           0x0 );

            break;
        }

        // Read Byte 2 (BASIC_MEMORY_TYPE) for the target passed in.
        uint16_t data = 0x0;
        size_t dataSz = sizeof(data);
        err = spdGetKeywordValue( BASIC_MEMORY_TYPE,
                                  &data,
                                  dataSz,
                                  i_target );

        if( err )
        {
            // If an error is returned, the DIMM is not present.
            present = false;
            TRACUCOMP( g_trac_spd,
                       INFO_MRK"Dimm was found to be NOT present." );

            // Delete the error
            delete err;
            err = NULL;
        }
        else
        {
            // DIMM is present...
            present = true;
            TRACUCOMP( g_trac_spd,
                       INFO_MRK"Dimm was found to be present." );
        }

        // copy present value into output buffer so caller can read it
        memcpy( io_buffer, &present, presentSz );
        io_buflen = presentSz;

    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdPresenceDetect()" );

    return err;
} // end dimmPresenceDetect


}; // end namespace SPD
