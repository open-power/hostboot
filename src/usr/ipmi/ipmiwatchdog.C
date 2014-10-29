/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmiwatchdog.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __IPMIWATCHDOG_IPMIWATCHDOG_C
#define __IPMIWATCHDOG_IPMIWATCHDOG_C
/**
 *  @file ipmiwatchdog.C
 *
 *  Ipmi watchdog timer
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <errl/errlentry.H>
#include <ipmi/ipmiwatchdog.H>
#include <ipmi/ipmiif.H>
#include <sys/time.h>

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
// Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"wd: "printf_string,##args)

namespace IPMIWATCHDOG
{

/******************************************************************************/
// Functions
/******************************************************************************/


errlHndl_t setWatchDogTimer(  const uint16_t i_countdown_secs,
                        const uint8_t i_timer_use,
                        const TIMER_ACTIONS i_timer_action,
                        const TIMER_USE_CLR_FLAGS i_timer_clr_flag)
{
    errlHndl_t err_ipmi = NULL;

    // Convert secs into lsb and msb values
    // the ipmi spec uses the count which is 100ms/count
    static const uint16_t ms_per_count               = 100;
    static const uint8_t bits_to_shift_for_nxt_byte  = 8;
    static const uint8_t byte_mask                   = 0xFF;

    uint16_t countdown = (i_countdown_secs * MS_PER_SEC)
                            / ms_per_count;

    uint8_t init_countdown_lsb = static_cast<uint8_t>
                                 (countdown & byte_mask);

    uint8_t init_countdown_msb = static_cast<uint8_t>(
                                 (countdown >> bits_to_shift_for_nxt_byte)
                                 & byte_mask);


    size_t len = 6; // IPMI spec has request data at 6 bytes

    //create request data buffer
    uint8_t* data = new uint8_t[len];

    IPMI::completion_code cc = IPMI::CC_UNKBAD;

    data[0] = i_timer_use;          // byte 1 timer use
    data[1] = i_timer_action;      // byte 2 timer actions
    data[2] = 0x00;                 // byte 3 pre-interval timeout in secs
    data[3] = i_timer_clr_flag;    // byte 4 timer use flags to clear
    data[4] = init_countdown_lsb; // byte 5 initial countdown timer LSByte
    data[5] = init_countdown_msb; // byte 6 initial countdown timer MSByte

    err_ipmi = IPMI::sendrecv(IPMI::set_watchdog(), cc, len, data);

    //cleanup buffer
    delete[] data; data = NULL;

    if(cc != IPMI::CC_OK)
    {
        IPMI_TRAC("Watchdog: BMC returned not ok CC[%x]",cc);
        // should we log error and then retry?
        // what happens if the communication is broken
        // reset will try and set it again.
    }

    return err_ipmi;
}


errlHndl_t resetWatchDogTimer()
{
    errlHndl_t err_ipmi = NULL;


    // reset command does not take any request data
    size_t len = 0;
    uint8_t* data = NULL;


    do
    {

        // Don't worry about the return just send the msg over
        // If there is an error during the reset
        // we don't care about it since the watchdog will trip
        //send ipmi command
        err_ipmi = IPMI::send(IPMI::reset_watchdog(), len, data);

        if(err_ipmi)
        {
            //got an error sending IPMI msg
            //progate error upstream.
            break;
        }

    }
    while(0);

    return err_ipmi;
}


} // namespace

#endif
