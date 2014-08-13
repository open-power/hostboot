/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/console/console_reasoncodes.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
/* [+] International Business Machines Corp.                              */
/* [+] Google Inc.                                                        */
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
#ifndef __CONSOLE_CONSOLE_REASONCODES_H
#define __CONSOLE_CONSOLE_REASONCODES_H

#include <hbotcompid.H>

namespace CONSOLE
{
    enum ConsoleModuleId
    {
        MOD_CONSOLE_INVALID_MODULE      = 0x00,
        MOD_CONSOLE_UART_PUTC           = 0x01,
    };

    enum ConsoleReasonCode
    {
        RC_INVALID_DATA                 = CONSOLE_COMP_ID | 0x01,
        RC_TIMEOUT                      = CONSOLE_COMP_ID | 0x02,
    };
}

#endif
