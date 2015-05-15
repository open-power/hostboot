/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/vpd.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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

#include "vpd.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_vpd = NULL;
TRAC_INIT( & g_trac_vpd, "VPD", KILOBYTE );

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)


namespace VPD
{

// ------------------------------------------------------------------
// getVpdLocation
// ------------------------------------------------------------------
errlHndl_t getVpdLocation ( int64_t & o_vpdLocation,
                            TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"getVpdLocation()" );

    o_vpdLocation = i_target->getAttr<TARGETING::ATTR_VPD_REC_NUM>();
    TRACUCOMP( g_trac_vpd,
               INFO_MRK"Using VPD location: %d",
               o_vpdLocation );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"getVpdLocation()" );

    return err;
}


// ------------------------------------------------------------------
// resolveVpdSource
// ------------------------------------------------------------------
bool resolveVpdSource( TARGETING::Target * i_target,
                       bool i_rwPnorEnabled,
                       bool i_rwHwEnabled,
                       vpdCmdTarget i_vpdCmdTarget,
                       vpdCmdTarget& o_vpdSource )
{
    bool badConfig = false;
    o_vpdSource = VPD::INVALID_LOCATION;

    if( i_vpdCmdTarget == VPD::PNOR )
    {
        if( i_rwPnorEnabled )
        {
            o_vpdSource = VPD::PNOR;
        }
        else
        {
            badConfig = true;
            TRACFCOMP(g_trac_vpd,"resolveVpdSource: VpdCmdTarget=PNOR but READ/WRITE PNOR CONFIG is disabled");
        }
    }
    else if( i_vpdCmdTarget == VPD::SEEPROM )
    {
        if( i_rwHwEnabled )
        {
            o_vpdSource = VPD::SEEPROM;
        }
        else
        {
            badConfig = true;
            TRACFCOMP(g_trac_vpd,"resolveVpdSource: VpdCmdTarget=SEEPROM but READ/WRITE HW CONFIG is disabled");
        }
    }
    else  // i_vpdCmdTarget == VPD::AUTOSELECT
    {
        if( i_rwPnorEnabled &&
            i_rwHwEnabled )
        {
            // PNOR needs to be loaded before we can use it
            TARGETING::ATTR_VPD_SWITCHES_type vpdSwitches =
                    i_target->getAttr<TARGETING::ATTR_VPD_SWITCHES>();
            if( vpdSwitches.pnorCacheValid )
            {
                o_vpdSource = VPD::PNOR;
            }
            else
            {
                o_vpdSource = VPD::SEEPROM;
            }
        }
        else if( i_rwPnorEnabled )
        {
            o_vpdSource = VPD::PNOR;
        }
        else if( i_rwHwEnabled )
        {
            o_vpdSource = VPD::SEEPROM;
        }
        else
        {
            badConfig = true;
            TRACFCOMP(g_trac_vpd,"resolveVpdSource: READ/WRITE PNOR CONFIG and READ/WRITE HW CONFIG disabled");
        }
    }

    return badConfig;
}

}; //end VPD namespace
