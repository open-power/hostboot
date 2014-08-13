/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/console/uartconfig.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#include "uart.H"

const uint64_t CONSOLE::g_uartBase = 0x3f8;
const uint64_t CONSOLE::g_uartBaud = 115200;
const uint64_t CONSOLE::g_uartClock = 1843200;

/* Someone could decide to make these attributes that are accessed like:
 *      TARGETING::Target *sys;
 *      TARGETING::targetService().getTopLevelTarget(sys);
 *
 *      g_uartBase = sys->getAttr<TARGETING::ATTR_CONSOLE_UART_BASE>();
 *      g_uartBaud = sys->getAttr<TARGETING::ATTR_CONSOLE_UART_BAUD_RATE>();
 *
 * ( though the variables would need to be initialized via a function call
 *   indirection )
 *
 * In order to do this, we'd have to remove this file from the object
 * list and insert a new file via a config option.
 */
