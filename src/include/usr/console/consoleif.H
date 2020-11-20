/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/console/consoleif.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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
#ifndef __CONSOLE_CONSOLEIF_H
#define __CONSOLE_CONSOLEIF_H

#include <stdarg.h>
#include <stddef.h>
#include <console/uartif.H>

namespace CONSOLE
{

    /** @brief Display a string to the console.
     *
     *  @param[in] - String to display.
     */
#if (defined(CONFIG_CONSOLE) && !defined(__HOSTBOOT_RUNTIME))
    extern void display(const uartId_t, const char*);
#else
    inline void display(const uartId_t, const char*) {};
#endif

    /** @brief Display formatted string to the console.
     *
     *  @param[in] - Header (or NULL).
     *  @param[in] - Format string.
     */
#if (defined(CONFIG_CONSOLE) && !defined(__HOSTBOOT_RUNTIME))
    extern void displayf(const uartId_t, const char*, const char*, ...);
#else
    inline void displayf(const uartId_t, const char*, const char*, ...) {};
#endif

    /** @brief Display formatted string to the console.
     *
     *  @param[in] - Header (or NULL).
     *  @param[in] - Format string.
     *  @param[in] - va_list of arguments.
     */
#if (defined(CONFIG_CONSOLE) && !defined(__HOSTBOOT_RUNTIME))
    extern void vdisplayf(const uartId_t, const char*, const char*, va_list);
#else
    inline void vdisplayf(const uartId_t, const char*, const char*, va_list) {};
#endif


    /** @brief Wait for console buffers to be flushed to device.
    */
#if (defined(CONFIG_CONSOLE) && !defined(__HOSTBOOT_RUNTIME))
    extern void flush();
#else
    inline void flush() {};
#endif

};


#endif
