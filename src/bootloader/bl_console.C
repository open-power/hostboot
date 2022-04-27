/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bl_console.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
#include <util/align.H>
#include <arch/ppc.H>
#include <kernel/timemgr.H>

using namespace CONSOLE;
using namespace UARTREGS;

bool bl_console::console_fail = false;

void computeOpbmErrSev(OpbmErrReg_t i_opbmErrData,
                       ResetLevels &o_resetLevel)
{
    o_resetLevel = RESET_CLEAR;

    // First check the soft errors
    if (i_opbmErrData.rxits || i_opbmErrData.rxicmd || i_opbmErrData.rxiaa ||
        i_opbmErrData.rxopbe || i_opbmErrData.rxicmdb || i_opbmErrData.rxidatab)
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
    }

    // Now look for hard errors that will override soft errors reset level
    if (i_opbmErrData.rxopbt || i_opbmErrData.rxiaddr || i_opbmErrData.rxctgtel)
    {
        o_resetLevel = RESET_OPB_LPCHC_HARD;
    }
}

void computeLpchcErrSev(LpchcErrReg_t i_lpchcErrData,
                        ResetLevels &o_resetLevel)
{
    o_resetLevel = RESET_CLEAR;

    // First check the soft errors
    // All of these errors are set from bad LPC end points. Setting all to soft.
    // On Rainier HW, lreset bit pops up when we get to HBBL, but the console
    // works OK despite that bit. The check for that bit was removed from HBBL
    // for now until we check with HW people and figure out why the bit is set.
    if (i_lpchcErrData.syncab ||
        i_lpchcErrData.syncnr || i_lpchcErrData.syncne ||
        i_lpchcErrData.syncto || i_lpchcErrData.tctar || i_lpchcErrData.mctar)
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
    }
}

bool checkForLpcErrors()
{
    uint32_t opbm_buffer = 0;
    uint32_t lpchc_buffer = 0;
    OpbmErrReg_t opbm_err_union;
    opbm_err_union.data32 = 0x0;
    LpchcErrReg_t lpchc_err_union;
    lpchc_err_union.data32 = 0x0;
    ResetLevels l_opbmResetLevel = RESET_CLEAR;
    ResetLevels l_lpchcResetLevel = RESET_CLEAR;

    uint64_t l_pnorEnd = g_blData->blToHbData.lpcBAR + LPC::LPCHC_FW_SPACE +
        PNOR::LPC_TOP_OF_FLASH_OFFSET;

    uint64_t l_mmioAddr = l_pnorEnd - PNOR::TOC_OFFSET_FROM_TOP_OF_FLASH;
    l_mmioAddr = ALIGN_PAGE_DOWN(l_mmioAddr);

    // First do a dummy LPC access (if an LPC error condition exists,
    // an access can be necessary to get the error indicated in the
    // status register. This read will force the error condition to
    // properly be shown in the LPC error status reg
    Bootloader::handleMMIO(l_mmioAddr,
                           reinterpret_cast<uintptr_t>(&opbm_buffer) +
                           getHRMOR(),
                           Bootloader::WORDSIZE,
                           Bootloader::WORDSIZE,
                           Bootloader::READ);

    uint32_t l_opb_status_addr = OPBM_ACCUM_STATUS_REG;
    uint64_t src_addr = g_blData->blToHbData.lpcBAR + LPC::LPCHC_ERR_SPACE +
        l_opb_status_addr;
    Bootloader::handleMMIO(src_addr,
                           reinterpret_cast<uintptr_t>(&opbm_buffer) +
                           getHRMOR(),
                           Bootloader::WORDSIZE, Bootloader::WORDSIZE,
                           Bootloader::READ);

    uint32_t l_lpchc_addr = LPCHC_REG;
    src_addr = g_blData->blToHbData.lpcBAR + LPC::LPCHC_ERR_SPACE + l_lpchc_addr;
    Bootloader::handleMMIO(src_addr,
                           reinterpret_cast<uintptr_t>(&lpchc_buffer) +
                           getHRMOR(),
                           Bootloader::WORDSIZE, Bootloader::WORDSIZE,
                           Bootloader::READ);

    // Mask error bits
    opbm_err_union.data32 = (opbm_buffer & LPC::OPB_ERROR_MASK);
    lpchc_err_union.data32 = (lpchc_buffer & LPCHC_ERROR_MASK);

    if (opbm_err_union.data32 != 0)
    {
        // New priority is to force a specific checkstop so that PRD can
        // handle the callout
        Bootloader::bl_forceCheckstopOnLpcErrors();

        // Shouldn't return back from forcing a checkstop, but if so, just
        // follow the previous error path here

        computeOpbmErrSev(opbm_err_union, l_opbmResetLevel);

        if (l_opbmResetLevel != RESET_CLEAR)
        {
            bl_console::console_fail = true;
        }
    }

    if (lpchc_err_union.data32 != 0)
    {
        computeLpchcErrSev(lpchc_err_union, l_lpchcResetLevel);

        if (l_lpchcResetLevel != RESET_CLEAR)
        {
            bl_console::console_fail = true;
        }
    }

    return bl_console::console_fail;
}

static uint64_t convertSecToTicks(const uint64_t i_sec, const uint64_t i_nsec)
{
    // result = ((sec * 10^9 + nsec) * timebaseFreq Hz) / 10^9
    uint64_t timebaseFreq = 512000000ULL;
    uint64_t result = ((i_sec * 1000000000ULL) + i_nsec);
    result *= (timebaseFreq / 1000000);
    result /= 1000;
    return result;
}

static void simpleDelay(const uint64_t i_sec, const uint64_t i_nsec)
{
    uint64_t delay = convertSecToTicks(i_sec, i_nsec);
    uint64_t expire = getTB() + delay;
    while (getTB() < expire)
    {
        // set low thread priority
        asm volatile("or 1,1,1");
    }

    // set high thread priority
    asm volatile("or 2,2,2");
}

void bl_nanosleep(const uint64_t i_sec, const uint64_t i_nsec)
{
    uint64_t l_sec = i_sec + i_nsec / NS_PER_SEC;
    uint64_t l_nsec = i_nsec % NS_PER_SEC;

    simpleDelay(l_sec, l_nsec);
}

// TODO: RTC 209583 addon commit to handle error path
static bool readUartReg(const uint8_t i_addr, uint8_t &o_data)
{
    uint64_t src_addr = g_blData->blToHbData.lpcBAR + LPC::LPCHC_IO_SPACE + g_vuart1Base + i_addr;
    Bootloader::handleMMIO(src_addr,
                           reinterpret_cast<uintptr_t>(&o_data) + getHRMOR(),
                           sizeof(o_data), Bootloader::BYTESIZE,
                           Bootloader::READ);

    return checkForLpcErrors();
}

static bool writeUartReg(const uint8_t i_addr, const uint8_t i_data)
{
    uint64_t dest_addr = g_blData->blToHbData.lpcBAR + LPC::LPCHC_IO_SPACE + g_vuart1Base + i_addr;
    Bootloader::handleMMIO(reinterpret_cast<uintptr_t>(&i_data) + getHRMOR(),
                           dest_addr,
                           sizeof(i_data), Bootloader::BYTESIZE,
                           Bootloader::WRITE);

    return checkForLpcErrors();
}

void bl_console::putString(const char* i_s)
{
    while (*i_s)
    {
        putChar(*i_s);
        i_s++;
    }
}

// Everything in this function is taken from uart.C, but ideally will all be
// removed when SBE works
void bl_console::init()
{
    uint64_t divisor = (g_vuart1Clock / 16) / g_vuart1Baud;
    uint8_t output = 0;

    const auto blConfigData = reinterpret_cast<BootloaderConfigData_t *>(
        SBE_HB_COMM_ADDR);
    bool consoleEnabled = (blConfigData->lpcConsoleEnable == 1);

    if (!consoleEnabled ||
        writeUartReg(LCR, 0x00) ||
        writeUartReg(SCR, 'w') ||
        readUartReg(SCR, output) ||
        writeUartReg(IER, 0) ||
        writeUartReg(LCR, LCR_DLAB) ||
        writeUartReg(DLL, divisor & 0xff) ||
        writeUartReg(DLM, divisor >> 8) ||
        writeUartReg(LCR, LCR_DWL8 | LCR_NOP | LCR_STP1) ||
        writeUartReg(MCR, MCR_RTS | MCR_DTR) ||
        writeUartReg(FCR, FCR_ENF | FCR_CLFR | FCR_CLFT))
    {
        // Error already handled
    }
}

void displayNibble(const unsigned char i_nibble)
{
    // Optimization to take advantage of how ascii tables are constructed
    // Between 0-9 and A-F ascii characters, there are 7 other characters
    // 0xA is 10 in decimal, so being less than 10 would put you in the range
    // of 0-9, being greater than or equal to 10 would put you in the range of
    // A-F
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
            // Code to format the console output to look more readable
            // Sample output:
            // XXXX XXXX XXXX XXXX
            // XXXX XXXX XXXX XXXX
            // 16 represents the end of line
            if (count_size % 16 == 0)
            {
                putString("\r\n");
            }
            // 4 represents the end of a block
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
    bool error = false;
    const auto blConfigData = reinterpret_cast<BootloaderConfigData_t *>(SBE_HB_COMM_ADDR);
    bool console_enable = (blConfigData->lpcConsoleEnable == 1);

    do
    {
        if (bl_console::console_fail || !console_enable)
        {
            break;
        }

        static unsigned char txRoom = CONSOLE::TX_FIFO_SIZE;
        if(txRoom < CONSOLE::TX_FIFO_UNBLOCK_THRESHOLD)
        {
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
                bl_nanosleep(0, CONSOLE::DELAY_NS);

                loops++;
            } while (loops < CONSOLE::DELAY_LOOPS);

            if (error)
            {
                break;
            }
            else if (data == LSR_BAD)
            {
                bl_console::console_fail = true;
                break;
            }
            else if (loops >= CONSOLE::DELAY_LOOPS)
            {
                bl_console::console_fail = true;
                break;
            }
            else
            {
                txRoom = CONSOLE::TX_FIFO_SIZE;
            }
        }

        // Write character to FIFO
        error = writeUartReg(THR, i_c);
        if(!error)
        {
            txRoom --;
        }

    } while (0);
}
