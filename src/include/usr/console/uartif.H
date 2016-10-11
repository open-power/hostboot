/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/console/uartif.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef __CONSOLE_UARTIF_H
#define __CONSOLE_UARTIF_H

#include <config.h>
#include <stdarg.h>

namespace CONSOLE
{

    const uint8_t SERIAL_IRQ        = 4;

    // Host SerlIRQ interrupt type for SUART1
    const uint8_t RESERVED          = 0x00;
    const uint8_t LOW_LEVEL_TRIG    = 0x01;
    const uint8_t RISING_EDGE_TRIG  = 0x02;
    const uint8_t HIGH_LEVEL_TRIG   = 0x03;

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
        //< 0x01: low level, 0x02: rising edge, 0x03: high level
};

/**
 * Retrieve some information about the UART and the connection
 * we have to it.
 *
 * @return Structure of UART data
 */
UartInfo_t getUartInfo(void);


};

#endif
