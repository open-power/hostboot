/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/console/uartif.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
 * @file uartif.H
 *
 * @brief Defines an interface for retrieving information about the
 *        LPC connected UART devices.
 *
 */

#ifndef __CONSOLE_UARTIF_H
#define __CONSOLE_UARTIF_H

#include <stdint.h>
#include <stdarg.h>

namespace CONSOLE
{

    // NOTE: These interrupt numbers come from the legacy values used for
    //       COM1/COM2 ports on the old IBM compatible PC's.
    const uint8_t VUART1_IRQ        = 4;
    const uint8_t VUART2_IRQ        = 3;

    // Host SerlIRQ interrupt type for UART1 and UART2
    // These values are defined in the "Initialization of Hypervisor Memory
    // Space for P10" document.
    const uint8_t RESERVED_TRIG     = 0x00;
    const uint8_t LOW_LEVEL_TRIG    = 0x01;
    const uint8_t RISING_EDGE_TRIG  = 0x02;
    const uint8_t HIGH_LEVEL_TRIG   = 0x03;

/**
 * @brief UART ID's representing the supported UARTS
 */
enum uartId_t: uint8_t
{
    VUART1 = 0,
    VUART2 = 1,
    NUM_VUARTS,
    DEFAULT = VUART1,
    DEBUG = VUART2
};

/**
 * Structure to return UART information in
 */
struct UartInfo_t
{
    uint64_t lpcBaseAddr; //< Base address of the UART device the LPC bus
    uint32_t lpcSize; //< Size of the UART device address space on LPC bus
    uint32_t clockFreqHz; //< Clock Frequency of the UART baud clock in Hz
    uint32_t freqHz; //< Current baud rate of the UART device
    uint8_t interruptNum; //< UART Interrupt Number
    uint8_t interruptTrigger; //< UART trigger type
    bool consoleEnabled; //< Hostboot console support enabled
        //< 0x01: low level, 0x02: rising edge, 0x03: high level
};

/**
 * Retrieve some information about a UART and the connection
 * we have to it.
 *
 * param[in] i_uartId The id of the UART for which to retrieve information
 *
 * @return Structure of UART data
 */
UartInfo_t getUartInfo(uartId_t i_uartId);


};

#endif
