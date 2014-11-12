/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/dimmPres.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
#include <targeting/common/utilFilter.H>
#include <devicefw/driverif.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/spdenums.H>
#include <config.h>

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
             * @devdesc          Buffer for checking Presence Detect
             *                   was not the correct size.
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

        // Is the target present
#ifdef CONFIG_DJVPD_READ_FROM_HW
        // Check if the parent MBA/MEMBUF is present.  If it is not then
        // no reason to check the DIMM which would otherwise generate
        // tons of FSI errors.  We can't just check if parent MBA
        // is functional because DIMM presence detect is called before
        // the parent MBA/MEMBUF is set as present/functional.
        TARGETING::TargetHandleList membufList;
        TARGETING::PredicateCTM membufPred( TARGETING::CLASS_CHIP,
                                            TARGETING::TYPE_MEMBUF );
        TARGETING::targetService().getAssociated(
            membufList,
            i_target,
            TARGETING::TargetService::PARENT_BY_AFFINITY,
            TARGETING::TargetService::ALL,
            &membufPred);

        bool parentPresent = false;
        const TARGETING::TargetHandle_t membufTarget = *(membufList.begin());

        err = deviceRead(membufTarget, &parentPresent, presentSz,
                                DEVICE_PRESENT_ADDRESS());
        if (err)
        {
            TRACFCOMP(
                g_trac_spd,
                "Error reading parent MEMBUF present: huid 0x%X DIMM huid 0x%X",
                TARGETING::get_huid(membufTarget),
                TARGETING::get_huid(i_target) );
            break;
        }
        if (!parentPresent)
        {
            present = false;
            // Invalidate the SPD in PNOR
            err = VPD::invalidatePnorCache(i_target);
            if (err)
            {
                TRACFCOMP( g_trac_spd, "Error invalidating SPD in PNOR" );
            }
            break;
        }
#endif

        present = spdPresent( i_target );

        if( present == false )
        {
            TRACUCOMP( g_trac_spd,
                       INFO_MRK"Dimm was found to be NOT present." );
        }
        else
        {
            TRACUCOMP( g_trac_spd,
                       INFO_MRK"Dimm was found to be present." );
        }

#if defined(CONFIG_DJVPD_READ_FROM_HW) && defined(CONFIG_DJVPD_READ_FROM_PNOR)
        if( present )
        {
            // Check if the VPD data in the PNOR matches the SEEPROM
            err = VPD::ensureCacheIsInSync( i_target );
            if( err )
            {
                present = false;

                TRACFCOMP(g_trac_spd,ERR_MRK "dimmPresenceDetectt> Error during ensureCacheIsInSync (SPD)" );
                break;
            }
        }
        else
        {
            // SPD is not present, invalidate the SPD in PNOR
            err = VPD::invalidatePnorCache(i_target);
            if (err)
            {
                TRACFCOMP( g_trac_spd, "Error invalidating SPD in PNOR" );
            }
        }
#endif
        // copy present value into output buffer so caller can read it
        memcpy( io_buffer, &present, presentSz );
        io_buflen = presentSz;

    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"dimmPresenceDetect()" );

    return err;
} // end dimmPresenceDetect


}; // end namespace SPD
