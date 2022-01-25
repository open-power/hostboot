/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/dimmPres.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#include <initservice/initserviceif.H>
#include <fsi/fsiif.H>
#include "../eeprom/eepromCache.H"

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

    TRACSSCOMP( g_trac_spd, ENTER_MRK"dimmPresenceDetect() "
                "DIMM HUID 0x%X", TARGETING::get_huid(i_target));
    do
    {
        // Check to be sure that the buffer is big enough.
        if( !(io_buflen >= sizeof(bool)) )
        {
            TRACFCOMP( g_trac_spd, ERR_MRK"dimmPresenceDetect() "
                       "Invalid Data Length: %d",
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

        // Is the target present?
#ifdef CONFIG_SUPPORT_EEPROM_HWACCESS
        // Check if the i2c master is present.
        // If it is not then no reason to check the DIMM which would
        // otherwise generate tons of FSI errors.
        // We can't just check if parent MCA or MBA
        // is functional because DIMM presence detect is called before
        // the parent MCS/MCA or MBA/MEMBUF is set as present/functional.
        bool l_i2cMasterPresent = false;

        do
        {
            // get eeprom vpd primary info
            TARGETING::EepromVpdPrimaryInfo eepromData;
            if( !(i_target->
                     tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>
                         ( eepromData ) ) )
            {
                TRACFCOMP( g_trac_spd, ERR_MRK"dimmPresenceDetect() "
                           "Error: no eeprom vpd primary info" );
                break;
            }

            // find i2c master target
            TARGETING::TargetService& tS = TARGETING::targetService();
            bool exists = false;
            tS.exists( eepromData.i2cMasterPath, exists );
            if( !exists )
            {
                TRACFCOMP( g_trac_spd, ERR_MRK"dimmPresenceDetect() "
                           "i2cMasterPath attribute path doesn't exist");
                break;
            }

            // Since it exists, convert to a target
            TARGETING::Target * l_i2cMasterTarget =
                                   tS.toTarget( eepromData.i2cMasterPath );

            if( NULL == l_i2cMasterTarget )
            {
                TRACFCOMP( g_trac_spd, ERR_MRK"dimmPresenceDetect() "
                           "i2cMasterPath target is NULL");
                break;
            }
            TRACSSCOMP( g_trac_spd, "dimmPresenceDetect() "
                "i2c master HUID 0x%X", TARGETING::get_huid(l_i2cMasterTarget));

            // Check if present
            TARGETING::Target* masterProcTarget = NULL;
            TARGETING::targetService().masterProcChipTargetHandle(
                                                        masterProcTarget );
            // Master proc is taken as always present. Validate other targets.
            if (l_i2cMasterTarget != masterProcTarget)
            {
                l_i2cMasterPresent = FSI::isSlavePresent(l_i2cMasterTarget);
                if( !l_i2cMasterPresent )
                {
                    TRACFCOMP( g_trac_spd, ERR_MRK"dimmPresenceDetect() "
                               "isSlavePresent failed");
                    break;
                }
            }
            l_i2cMasterPresent = true;
        }
        while (0);
#endif //CONFIG_SUPPORT_EEPROM_HWACCESS

        // Check if the SPD is there if we are talking to real hardware
#ifdef CONFIG_SUPPORT_EEPROM_HWACCESS
        present = spdPresent( i_target );

        // Otherwise just check the eeprom cache
#elif defined(CONFIG_SUPPORT_EEPROM_CACHING)
        err = EEPROM::eecachePresenceDetect(i_target, present);
        if(err)
        {
            TRACFCOMP(g_trac_spd, ERR_MRK "dimmPresenceDetect() "
                "detect target HUID 0x%.08x against the existing EECACHE "
                "failed. rc=0x%X, plid=0x%X",
                TARGETING::get_huid(i_target), ERRL_GETRC_SAFE(err),
                ERRL_GETPLID_SAFE(err));
            present = false;
            break;
        }
#endif

        if( present == false )
        {
            TRACUCOMP( g_trac_spd, INFO_MRK"dimmPresenceDetect() "
                       "Dimm was found to be NOT present." );
        }
        else
        {
            TRACUCOMP( g_trac_spd, INFO_MRK"dimmPresenceDetect() "
                       "Dimm was found to be present." );
        }


        // copy present value into output buffer so caller can read it
        memcpy( io_buffer, &present, presentSz );
        io_buflen = presentSz;

    } while( 0 );

    TRACSSCOMP( g_trac_spd, EXIT_MRK"dimmPresenceDetect() = %d", present );

    return err;
} // end dimmPresenceDetect


}; // end namespace SPD
