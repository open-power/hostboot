/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmiwatchdog.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2018                        */
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
#include <time.h>

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
// Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"wd: " printf_string,##args)

namespace IPMIWATCHDOG
{

// Needed for watchdog resets in case the BMC side becomes uninitialized and we
// need to reinitialize it
static bool g_set_once = false;
static uint16_t g_countdown_secs;
static uint8_t g_timer_use;
static TIMER_ACTIONS g_timer_action;
static TIMER_USE_CLR_FLAGS g_timer_clr_flag;

/******************************************************************************/
// Functions
/******************************************************************************/


errlHndl_t setWatchDogTimer(  const uint16_t i_countdown_secs,
                        const uint8_t i_timer_use,
                        const TIMER_ACTIONS i_timer_action,
                        const TIMER_USE_CLR_FLAGS i_timer_clr_flag)
{
    // Save the latest values so that reset actions can setup the timer
    // if the BMC goes away.
    g_set_once = true;
    g_countdown_secs = i_countdown_secs;
    g_timer_use = i_timer_use;
    g_timer_action = i_timer_action;
    g_timer_clr_flag = i_timer_clr_flag;

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

    data[0] = i_timer_use;          // byte 1 timer use
    data[1] = i_timer_action;      // byte 2 timer actions
    data[2] = 0x00;                 // byte 3 pre-interval timeout in secs
    data[3] = i_timer_clr_flag;    // byte 4 timer use flags to clear
    data[4] = init_countdown_lsb; // byte 5 initial countdown timer LSByte
    data[5] = init_countdown_msb; // byte 6 initial countdown timer MSByte

    IPMI_TRAC( "setWatchDogTimer : sec=%d, use=%d, act=%d, clr=%d",
               i_countdown_secs,
               i_timer_use,
               i_timer_action,
               i_timer_clr_flag );
    return IPMI::send(IPMI::set_watchdog(), len, data);

}


errlHndl_t resetWatchDogTimer()
{
    errlHndl_t err_ipmi = NULL;

    // Limit the amount of sent watchdog resets to once per second to make
    // sure that we don't overload the BMC with resets during quickly
    // completing ISTEPs. For simplicity we only compare the tv_sec so
    // the grace period may be almost 2 seconds.
    static uint64_t last_reset_sec;
    timespec_t now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    if (last_reset_sec + 1 >= now.tv_sec)
    {
        return NULL;
    }
    last_reset_sec = now.tv_sec;

    // reset command does not take any request data
    size_t len = 0;
    uint8_t* data = NULL;


    do
    {
        IPMI_TRAC( "resetWatchDogTimer" );

        IPMI::completion_code cc;
        err_ipmi = IPMI::sendrecv(IPMI::reset_watchdog(), cc, len, data);
        delete[] data;

        if(err_ipmi)
        {
            //got an error sending IPMI msg
            //progate error upstream.
            break;
        }

        // Make sure we don't have an uninitialized watchdog
        // openbmc will always start the watchdog regardless of us
        // initializing it. If we don't initialize it, it can eventually
        // time out on us
        if (g_set_once && cc == IPMI::CC_CMDSPC1)
        {
            err_ipmi = setWatchDogTimer(g_countdown_secs,
                    g_timer_use | DO_NOT_STOP,
                    g_timer_action, g_timer_clr_flag);

            if (err_ipmi)
            {
                //got an error sending IPMI msg
                //progate error upstream.
                break;
            }

            // Make sure to issue a reset after initialization to start
            // the timer if it isn't already. We don't care about the return
            // value of this message since we can't recurse forever. If we
            // fail here, later resets should handle reconfiguring the
            // watchdog if it isn't critically broken.
            len = 0;
            data = NULL;
            err_ipmi = IPMI::send(IPMI::reset_watchdog(), len, data);

            if(err_ipmi)
            {
                //got an error sending IPMI msg
                //progate error upstream.
                break;
            }
        }

        // We don't care about any other types of errors as the watchdog
        // will just trip in these cases.
        break;
    }
    while(0);

    return err_ipmi;
}


} // namespace

#endif
