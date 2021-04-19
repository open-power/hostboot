/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/extended/pldm_watchdog.H $               */
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
#ifndef PLDM_WATCHDOG_H
#define PLDM_WATCHDOG_H

#include <stdint.h>

/*
 * @file pldm_watchdog.H
 *
 * @brief This file contains APIs and definitions for PLDM watchdog functions.
 */

namespace PLDM
{

// Whether the watchdog timer is armed and HB should be sending regular
// heartbeats.
extern bool g_pldmWatchdogArmed;
// The value of the default timeout agreed upon between BMC and HB
extern const uint16_t DEFAULT_WATCHDOG_TIMEOUT_SEC;

} // namespace PLDM
#endif
