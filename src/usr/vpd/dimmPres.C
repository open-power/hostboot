/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/dimmPres.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/spdenums.H>

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
                ENTER_MRK"dimmPresenceDetect()" );

    do
    {
        // Check to be sure that the buffer is big enough.
        if( !(io_buflen >= sizeof(bool)) )
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"dimmPresenceDetect() - Invalid Data Length: %d",
                       io_buflen );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_INSUFFICIENT_BUFFER_SIZE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_PRESENCE_DETECT
             * @userdata1        Buffer Length
             * @userdata2        <UNUSED>
             * @devdesc          Buffer for checking Presence Detect was not the correct size.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_PRESENCE_DETECT,
                                           VPD::VPD_INSUFFICIENT_BUFFER_SIZE,
                                           TO_UINT64(io_buflen),
                                           0x0,
                                           true /*Add HB Software Callout*/);

            err->collectTrace( "SPD", 256);

            break;
        }

        // Read Byte 2 (BASIC_MEMORY_TYPE) for the target passed in.
        uint16_t data = 0x0;
        size_t dataSz = sizeof(data);
        err = deviceRead( i_target,
                          &data,
                          dataSz,
                          DEVICE_SPD_ADDRESS( SPD::BASIC_MEMORY_TYPE ) );

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
                EXIT_MRK"dimmPresenceDetect()" );

    return err;
} // end dimmPresenceDetect


}; // end namespace SPD
