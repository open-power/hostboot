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

/**
 * Structure to return UART information in
 */
struct UartInfo_t
{
    //@TODO-RTC:161647-Add more details/comments
    uint64_t lpcBaseAddr;
    uint32_t lpcSize;
    uint32_t clockFreqHz;
    uint32_t freqHz;
    uint8_t interruptNum;
    uint8_t interruptTrigger;
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
