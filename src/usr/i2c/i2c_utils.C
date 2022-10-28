/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/i2c_utils.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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

// #define TRACUCOMP(args...) TRACFCOMP(args)
#define TRACUCOMP(args...)

// ----------------------------------------------

namespace I2C
{

errlHndl_t i2cChooseEepromPage(TARGETING::Target * i_target,
                               uint8_t i_currentPage,
                               uint8_t & o_newPage,
                               uint8_t i_desiredPage,
                               misc_args_t & o_args,
                               bool & o_pageSwitchNeeded )
{
    errlHndl_t l_err = nullptr;
    o_pageSwitchNeeded = false;

    TRACUCOMP(g_trac_i2c,
              "i2cChooseEepromPage: current EEPROM page is %d, desired page is %d for target(0x%08X)",
              i_currentPage,
              i_desiredPage,
              TARGETING::get_huid(i_target));

    if( i_currentPage != i_desiredPage )
    {
        switch (i_desiredPage)
        {
            case PAGE_ONE:

                TRACUCOMP(g_trac_i2c, "i2cChooseEepromPage: Switching to page ONE");
                o_args.devAddr = PAGE_ONE_ADDR;
                o_newPage = PAGE_ONE;
                o_pageSwitchNeeded = true;
                break;

            case PAGE_ZERO:

                TRACUCOMP(g_trac_i2c, "i2cChooseEepromPage: Switching to page ZERO");
                o_args.devAddr = PAGE_ZERO_ADDR;
                o_newPage = PAGE_ZERO;
                o_pageSwitchNeeded = true;
                break;

            case PAGE_UNKNOWN:
            default:

                o_newPage = PAGE_UNKNOWN;
                TRACFCOMP(g_trac_i2c, ERR_MRK"i2cChooseEepromPage: Invalid page requested %d",
                          i_desiredPage);
                /*@
                 * @errortype
                 * @reasoncode       I2C_INVALID_EEPROM_PAGE_REQUEST
                 * @severity         ERRORLOG_SEV_UNRECOVERABLE
                 * @moduleid         I2C_CHOOSE_EEPROM_PAGE
                 * @userdata1        Target Huid
                 * @userdata2[00:31] Requested Page
                 * @userdata2[32:63] Current Page
                 * @devdesc          There was a request for an invalid
                 *                   EEPROM page
                 * @custdesc         An internal firmware error occurred
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                I2C_CHOOSE_EEPROM_PAGE,
                                                I2C_INVALID_EEPROM_PAGE_REQUEST,
                                                TARGETING::get_huid(i_target),
                                                TWO_UINT32_TO_UINT64(i_desiredPage,
                                                                     i_currentPage),
                                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_err->collectTrace( I2C_COMP_NAME, 256 );
        }
    }

    return l_err;
}

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

        // Only do this if the I2C master target is in I2C Host (aka PIB) mode
        TARGETING::I2cSwitches i2c_switches;
        if ( ( i_target->tryGetAttr<TARGETING::ATTR_I2C_SWITCHES>(i2c_switches) )
             && ( i2c_switches.useHostI2C != 1 ) )
        {
            TRACFCOMP( g_trac_i2c,INFO_MRK
                       "forceClearAtomicLock> Skipping on %.8X because not in HOST/PIB mode",
                       TARGETING::get_huid(i_target) );
            break;
        }

        for( uint8_t l_engine = 0;
             l_engine < I2C_BUS_ATTR_MAX_ENGINE;
             l_engine++ )
        {
            // Only operate on selected engines
            if ( ! ( i2cEngineToEngineSelect(l_engine) & i_engine ) )
            {
                TRACDCOMP( g_trac_i2c,INFO_MRK
                           "forceClearAtomicLock> Skipping engine %d on %.8X "
                           "(i_engine=0x%X)",
                           l_engine, TARGETING::get_huid(i_target), i_engine );
                continue;
            }

            TRACFCOMP( g_trac_i2c,INFO_MRK
                       "forceClearAtomicLock> Forcing engine %d on %.8X",
                       l_engine, TARGETING::get_huid(i_target) );

            uint64_t l_lockaddr = I2C_HOST_MASTER_BASE_ADDR + I2C_REG_ATOMIC_LOCK + // 0xA03FF
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
                break;
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
