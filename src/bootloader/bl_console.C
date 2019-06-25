/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bl_console.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
 *  @file bl_console.C
 *
 *  @brief Bootloader console functions to write data to lpc console
 */

#include <bootloader/bl_console.H>
#include <sys/task.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <lpc/lpc_const.H>
#include <uart.H>
#include <uartconfig.C>
#include <p10_sbe_hb_structures.H>

using namespace CONSOLE;
using namespace UARTREGS;

bool bl_console::console_fail = false;
const auto blConfigData = reinterpret_cast<BootloaderConfigData_t *>(SBE_HB_COMM_ADDR);

// TODO: addon commit to handle nanosleep functions
static bool simple_delay(const uint64_t i_sec, const uint64_t i_nsec)
{
    //bool result = false;

    //uint64_t delay = convert_sec_to_ticks(i_sec, i_nsec);

    return true;
}

void nanosleep(const uint64_t i_sec, const uint64_t i_nsec)
{
    uint64_t l_sec = i_sec + i_nsec / NS_PER_SEC;
    uint64_t l_nsec = i_nsec % NS_PER_SEC;

    simple_delay(l_sec, l_nsec);
}

// TODO: addon commit to handle error path
static bool readUartReg(const uint8_t i_addr, uint8_t &o_data)
{
    uint64_t src_addr = g_blData->blToHbData.lpcBAR + LPC::LPCHC_IO_SPACE + g_uartBase + i_addr;
    Bootloader::handleMMIO(src_addr,
                           reinterpret_cast<uintptr_t>(&o_data) + getHRMOR(),
                           sizeof(o_data), Bootloader::BYTESIZE,
                           Bootloader::READ);

    return false;
}

static bool writeUartReg(const uint8_t i_addr, const uint8_t i_data)
{
    uint64_t dest_addr = g_blData->blToHbData.lpcBAR + LPC::LPCHC_IO_SPACE + g_uartBase + i_addr;
    Bootloader::handleMMIO(reinterpret_cast<uintptr_t>(&i_data) + getHRMOR(),
                           dest_addr,
                           sizeof(i_data), Bootloader::BYTESIZE,
                           Bootloader::WRITE);

    return false;
}

void bl_console::putString(const char* i_s)
{
    while (*i_s)
    {
        putChar(*i_s);
        i_s++;
    }
}

// TODO: revisit when SBE works
void bl_console::init()
{
    uint64_t divisor = (g_uartClock / 16) / g_uartBaud;

    writeUartReg(LCR, 0x00);

    writeUartReg(SCR, 'w');

    uint8_t output = 0;
    readUartReg(SCR, output);

    writeUartReg(IER, 0);

    writeUartReg(LCR, LCR_DLAB);

    writeUartReg(DLL, divisor & 0xff);

    writeUartReg(DLM, divisor >> 8);

    writeUartReg(LCR, LCR_DWL8 | LCR_NOP | LCR_STP1);

    writeUartReg(MCR, MCR_RTS | MCR_DTR);

    writeUartReg(FCR, FCR_ENF | FCR_CLFR | FCR_CLFT);
}

void displayNibble(const unsigned char i_nibble)
{
    char hex_nibble = (i_nibble < 0xA) ? '0' + i_nibble : '7' + i_nibble;
    bl_console::putChar(hex_nibble);
}

void bl_console::displayHex(const unsigned char* i_start_addr, const size_t i_size)
{
    size_t count_size = 0;
    while (count_size < i_size)
    {
        if (count_size != 0)
        {
            if (count_size % 16 == 0)
            {
                putString("\r\n");
            }
            else if (count_size % 4 == 0)
            {
                putChar('\t');
            }
        }

        displayNibble((*i_start_addr & 0xF0) >> 4);
        displayNibble(*i_start_addr & 0x0F);
        count_size += sizeof(char);
        i_start_addr += sizeof(char);
    }
}

// Writes a character to console
void bl_console::putChar(const char i_c)
{
    // Wait for transmit FIFO to have space
    bool console_enable = blConfigData->lpcConsoleEnable == 1;
    bool error = false;
    do
    {
        if (bl_console::console_fail || !console_enable)
        {
            break;
        }

        const uint64_t DELAY_NS = 100;
        const size_t DELAY_LOOPS = 100000000;

        uint8_t data = 0;
        size_t loops = 0;

        do
        {
            error = readUartReg(LSR, data);
            if (error)
            {
                break;
            }

            // Wait for idle or error status
            if (data == LSR_BAD || (data & LSR_THRE))
            {
                break;
            }
            nanosleep(0, DELAY_NS);

            loops++;
        } while (loops < DELAY_LOOPS);

        if (error)
        {
            bl_console::console_fail = true;
            break;
        }
        else if (data == LSR_BAD)
        {
            bl_console::console_fail = true;
            break;
        }
        else if (loops >= DELAY_LOOPS)
        {
            bl_console::console_fail = true;
            break;
        }

        // Write character to FIFO
        error = writeUartReg(THR, i_c);
    } while (0);

    if (error)
    {
        bl_console::console_fail = true;
    }
}
