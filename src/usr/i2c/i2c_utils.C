/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/i2c_utils.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
 * @file i2c_utils.C
 *
 * @brief Common I2C functions for IPL and Runtime code
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
#include <errl/errludstring.H>  // ERRORLOG::ErrlUserDetailsString
#include <devicefw/userif.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/i2cif.H>
#include <i2c/i2c.H>
#include "errlud_i2c.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_i2c;
extern trace_desc_t* g_trac_i2cr;


// ----------------------------------------------

namespace I2C
{
/**
 * @brief This function forcefully releases the I2C Atomic Lock
 *        from its current owner.
 */
errlHndl_t forceClearAtomicLock( TARGETING::Target * i_target,
                                 i2cEngineSelect i_engine )
{
    /* Directions from I2C Logic team:
     Read the Lock_register(03FF) and write the same content back to the
     register. The Atomic_ID in the writeData will be compared to current
     holding owner ID & updates the lock_ID field with the master ID of
     the new master.
     */
    errlHndl_t l_errhdl = nullptr;

    do {
        for( uint8_t l_engine = 0;
             l_engine < I2C_BUS_ATTR_MAX_ENGINE;
             l_engine++ )
        {
            // Only operate on selected engines
            if ( ! ( i2cEngineToEngineSelect(l_engine) & i_engine ) )
            {
                continue;
            }

            TRACFCOMP( g_trac_i2c,INFO_MRK
                       "forceClearAtomicLock> Forcing engine %d on %.8X",
                       l_engine, TARGETING::get_huid(i_target) );
            uint64_t l_lockaddr = 0x000A03FF
                                 + (l_engine * P10_ENGINE_SCOM_OFFSET);

            size_t l_opsize=8;
            uint64_t l_lockdata = 0;
            l_errhdl = DeviceFW::deviceRead( i_target,
                                             &l_lockdata,
                                             l_opsize,
                                             DEVICE_SCOM_ADDRESS(l_lockaddr) );
            if( l_errhdl )
            {
                TRACFCOMP( g_trac_i2c,INFO_MRK
                           "forceClearAtomicLock> Error reading scom %.8X on %.8X",
                           l_lockaddr, TARGETING::get_huid(i_target) );
                break;
            }
            l_errhdl = DeviceFW::deviceWrite( i_target,
                                              &l_lockdata,
                                              l_opsize,
                                              DEVICE_SCOM_ADDRESS(l_lockaddr) );
            if( l_errhdl )
            {
                TRACFCOMP( g_trac_i2c,INFO_MRK
                           "forceClearAtomicLock> Error writing scom %.8X on %.8X",
                           l_lockaddr, TARGETING::get_huid(i_target) );
            }

            // Leave the lock cleared out before we leave
            l_lockdata = 0;
            l_errhdl = DeviceFW::deviceWrite( i_target,
                                              &l_lockdata,
                                              l_opsize,
                                              DEVICE_SCOM_ADDRESS(l_lockaddr) );
            if( l_errhdl )
            {
                TRACFCOMP( g_trac_i2c,INFO_MRK
                           "forceClearAtomicLock> Error clearing lock scom %.8X on %.8X",
                           l_lockaddr, TARGETING::get_huid(i_target) );
                break;
            }
        }
    } while(0);

    return l_errhdl;
}

} // end namespace I2C
