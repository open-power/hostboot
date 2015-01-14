/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/console/consoleif.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#include <config.h>
#include <stdarg.h>

namespace CONSOLE
{

    /** @brief Display a string to the console.
     *
     *  @param[in] - String to display.
     */
#ifdef CONFIG_CONSOLE
    extern void display(const char*);
#else
    inline void display(const char*) {};
#endif

    /** @brief Display formatted string to the console.
     *
     *  @param[in] - Header (or NULL).
     *  @param[in] - Format string.
     */
#ifdef CONFIG_CONSOLE
    extern void displayf(const char*, const char*, ...);
#else
    inline void displayf(const char*, const char*, ...) {};
#endif

    /** @brief Display formatted string to the console.
     *
     *  @param[in] - Header (or NULL).
     *  @param[in] - Format string.
     *  @param[in] - va_list of arguments.
     */
#ifdef CONFIG_CONSOLE
    extern void vdisplayf(const char*, const char*, va_list);
#else
    inline void vdisplayf(const char*, const char*, va_list) {};
#endif


    /** @brief Wait for console buffers to be flushed to device.
    */
#ifdef CONFIG_CONSOLE
    extern void flush();
#else
    inline void flush() {};
#endif

};

#endif
