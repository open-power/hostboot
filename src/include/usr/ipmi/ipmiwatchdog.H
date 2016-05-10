/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ipmi/ipmiwatchdog.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#ifndef __IPMIWATCHDOG_IPMIWATCHDOG_H
#define __IPMIWATCHDOG_IPMIWATCHDOG_H
/**
 *  @file ipmiwatchdog.H
 *
 *  IPMI watchdog interface launched from the IStep Dispatcher
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <errl/errlentry.H>
#include <config.h>

namespace IPMIWATCHDOG
{
/******************************************************************************/
// Globals/Constants
/******************************************************************************/
/**
 * @brief the default watchdog countdown setting it to 120 seconds.
 *
 * @TODO RTC:124499 revisit after performace improvments
 *
 */
// The config option CONFIG_BMC_IPMI_LONG_WATCHDOG allows a tester to use a
// watchdog timer that is several times more than what a customer would desire
// to aid in testing only. This option was initially envisioned for use with
// tracelite enabled, which greatly lengthens IPL time causing the watchdog
// timer to timeout. However this option could have other uses, so its name
// is left generic so as not imply the limited use with tracelite alone.
#ifdef CONFIG_BMC_IPMI_LONG_WATCHDOG
const uint16_t  DEFAULT_WATCHDOG_COUNTDOWN = 2400;
#else
const uint16_t  DEFAULT_WATCHDOG_COUNTDOWN = 120;
#endif

/**
 * @brief the default watchdog countdown for transition between hostboot
 * and OPAL (value is in seconds)
 */
const uint16_t  DEFAULT_HB_OPAL_TRANSITION_COUNTDOWN = 30;

/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/
/**
 * @brief Used in Byte 1 field of the set watchdog command
 */
enum TIMER_USE
{
    DO_NOT_LOG  =   0x80, // bit 7
    DO_NOT_STOP =   0x40, // bit 6
    BIOS_FRB2   =   0x01, // bit 0
    BIOS_POST   =   0x02, // bit 1
    OS_LOAD     =   0x03, // bits 0 & 1
    SMS_OS      =   0x04, // bit 2
    OEM         =   0x05, // bits 2 & 0

};

/**
 * @brief Used in Byte 2 field of the set watchdog command
 */
enum TIMER_ACTIONS
{
    NO_ACTIONS              =   0x00, // all bits
    PRE_TIMEOUT_INT_SMI     =   0x10, // bit 4
    PRE_TIMEOUT_INT_NMI     =   0x20, // bit 5
    PRE_TIMEOUT_INT_MSG     =   0x30, // bits 4 & 5
    TIMEOUT_HARD_RESET      =   0x01, // bit 0
    TIMEOUT_PWR_DOWN        =   0x02, // bit 1
    TIMEOUT_PWR_CYCLE       =   0x03, // bits 0 & 1

};

/**
 * @brief Used in Byte 4 field of the set watchdog command
 *      set to 1 to clear the flag set to 0 to leave alone
 */
enum TIMER_USE_CLR_FLAGS
{
    OEM_FLAG     =   0x20, // bit 5
    SMS_OS_FLAG  =   0x10, // bit 4
    OS_LOAD_FLAG  =   0x08, // bit 3
    BIOS_POST_FLAG  =   0x04, // bit 2
    BIOS_FRB2_FLAG  =   0x02, // bit 1

};


/******************************************************************************/
// Functions
/******************************************************************************/

/**
 * @brief Sets the ipmi watchdog timer on the BMC
 *
 * Called by hostboot to set a watchdog timer on the BMC
 * @param[in] i_countdown_secs, initial countdown in seconds
 * @param[in] i_timer_use, Sets watchdog timer use bits.
 * @param[in] i_timer_action, Sets watchdog timer experation action.
 * @param[in] i_timer_clr_flag, Sets the Watchdog interrupt flag to clear.
 * @return none
 */

errlHndl_t setWatchDogTimer(  const uint16_t i_countdown_secs,
                        const uint8_t i_timer_use
                                = static_cast<uint8_t>(DO_NOT_STOP | BIOS_FRB2),
                        const TIMER_ACTIONS i_timer_action
                                = TIMEOUT_HARD_RESET,
                        const TIMER_USE_CLR_FLAGS i_timer_clr_flag
                                = BIOS_FRB2_FLAG);

/**
 * @brief Resets the ipmi watchdog timer on the BMC
 *
 * Called by hostboot to reset a watchdog timer countdown on the BMC.
 * If the BMC returns an error code indicating the watchdog timer
 * has not been started, this function will start the watchdog timer.
 *
 * @return error
 */
errlHndl_t resetWatchDogTimer();


} // namespace

#endif
