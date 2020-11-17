/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bl_console.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef __BL_CONSOLE_H
#define __BL_CONSOLE_H

#include <bootloader/bootloader.H>

/** @file bl_console.H
 *  @brief Provides interface to the console for bootloader
 */

class bl_console
{

public:

static bool console_fail;

/**
  * @brief Initialize registers to display data to LPC console
  */
static void init();

/**
  * @brief Output hex as string to LPC console
  *
  * @param[in] i_start_addr     starting address of hex
  * @param[in] i_size           number of bytes to output
  */
static void displayHex(const unsigned char* i_start_addr, size_t i_size);

/**
  * @brief Output char to LPC console
  *
  * @param[in] i_c      character to display to console
  */
static void putChar(const char i_c);

/**
  * @brief Output string to LPC console
  *
  * @param[in] i_s      string to display to console
  */
static void putString(const char* i_s);

};

/**
 * @brief The HBBL's version of sleep/wait/delay
 *
 * @param[in] i_sec the number of seconds to wait
 * @param[in] i_nsec the number of nanoseconds to wait
 */
void bl_nanosleep(uint64_t i_sec, uint64_t i_nsec);

#endif
