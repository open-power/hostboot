/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/console/uart.C $                                      */
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
#include "uart.H"
#include <devicefw/userif.H>
#include <lpc/lpcif.H>
#include <kernel/console.H>
#include <sys/task.h>
#include <sys/time.h>
#include <errl/errlmanager.H>
#include <hwas/common/hwasCallout.H>
#include <console/console_reasoncodes.H>

namespace CONSOLE
{
    void Uart::initialize()
    {
        using namespace UARTREGS;

        errlHndl_t l_errl = NULL;

        do
        {
            // Check for failure from superclass initalize call.
            if (iv_failed) { break; }

            // Clear line control reg.
            l_errl = writeReg(LCR, 0x00);
            if (l_errl) { break; }

            // Check for existence of scratch register (and thus UART device).
            {
                const uint8_t value = 'h';
                uint8_t data = 0;
                l_errl = writeReg(SCR, value);
                if (l_errl) { break; }
                l_errl = readReg(SCR, data);
                if (l_errl) { break; }

                if (data != value)
                {
                    printk("UART: Device not found.\n");
                    break;
                }
            }

            // Reset interrupt register.
            l_errl = writeReg(IER, 0);
            if (l_errl) { break; }


            // Set baud rate.
            uint64_t divisor = (g_uartClock / 16) / g_uartBaud;
            l_errl = writeReg(LCR, LCR_DLAB);
            if (l_errl) { break; }
            l_errl = writeReg(DLL, divisor & 0xff);
            if (l_errl) { break; }
            l_errl = writeReg(DLM, divisor >> 8);
            if (l_errl) { break; }

            // Set 8N1 mode.
            l_errl = writeReg(LCR, LCR_DWL8 | LCR_NOP | LCR_STP1);
            if (l_errl) { break; }

            // Enable Request-to-send/Data-terminal-ready
            l_errl = writeReg(MCR, MCR_RTS | MCR_DTR);
            if (l_errl) { break; }

            // Clear and enable FIFOs.
            l_errl = writeReg(FCR, FCR_ENF | FCR_CLFR | FCR_CLFT);
            if (l_errl) { break; }

            // Found device.
            printk("UART: Device initialized.\n");
            iv_initialized = true;

        } while(0);

        if (l_errl)
        {
            iv_failed = true;
            errlCommit(l_errl, CONSOLE_COMP_ID);
        }
    }

    void Uart::putc(char c)
    {
        using namespace UARTREGS;

        errlHndl_t l_errl = NULL;
        do
        {
            if (iv_failed || !iv_initialized) { break; }

            // Wait for transmit FIFO to have space.
            {
                const uint64_t DELAY_NS = 100;
                const uint64_t DELAY_LOOPS = 100000000;

                uint8_t data = 0;
                uint64_t loops = 0;

                do
                {
                    l_errl = readReg(LSR, data);
                    if (l_errl) { break; }

                    // Wait for idle or error status.
                    if (data == LSR_BAD || (data & LSR_THRE))
                    {
                        break;
                    }
                    nanosleep(0, DELAY_NS);
                    task_yield();

                    loops++;
                } while( loops < DELAY_LOOPS);

                if (l_errl)
                {
                    printk("UART: Error state in xmit - LPC error.\n");
                    iv_failed = true;
                    break;
                }
                else if (data == LSR_BAD)
                {
                    printk("UART: Error state in xmit - bad data.\n");
                    iv_failed = true;
                    /*@
                     * @errortype
                     * @moduleid    CONSOLE::MOD_CONSOLE_UART_PUTC
                     * @reasoncode  CONSOLE::RC_INVALID_DATA
                     * @devdesc     Unexpected data from LPC-UART interface.
                     */
                    l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                                    CONSOLE::MOD_CONSOLE_UART_PUTC,
                                    CONSOLE::RC_INVALID_DATA);
                    //@TODO: RTC:116090 - Should be BMC hardware.
                    l_errl->addProcedureCallout(HWAS::EPUB_PRC_LVL_SUPP,
                                                HWAS::SRCI_PRIORITY_MED);
                    break;
                }
                else if (loops >= DELAY_LOOPS)
                {
                    printk("UART: FIFO timeout.\n");
                    iv_failed = true;
                    /*@
                     * @errortype
                     * @moduleid    CONSOLE::MOD_CONSOLE_UART_PUTC
                     * @reasoncode  CONSOLE::RC_TIMEOUT
                     * @devdesc     Timeout from LPC-UART interface.
                     */
                    l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                                    CONSOLE::MOD_CONSOLE_UART_PUTC,
                                    CONSOLE::RC_TIMEOUT);
                    //@TODO: RTC:116090 - Should be BMC hardware.
                    l_errl->addProcedureCallout(HWAS::EPUB_PRC_LVL_SUPP,
                                                HWAS::SRCI_PRIORITY_MED);
                    break;
                }
            }

            // Write character to FIFO.
            l_errl = writeReg(THR, c);

        } while(0);

        if (l_errl)
        {
            iv_failed = true;
            errlCommit(l_errl, CONSOLE_COMP_ID);
        }
        return;
    }

    errlHndl_t Uart::writeReg(uint64_t i_addr, uint8_t i_byte)
    {
        size_t len = sizeof(i_byte);
        return deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                           &i_byte,
                           len,
                           DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                              i_addr + g_uartBase));
    }

    errlHndl_t Uart::readReg(uint64_t i_addr, uint8_t& o_byte)
    {
        size_t len = sizeof(o_byte);
        return deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          static_cast<uint8_t*>(&o_byte),
                          len,
                          DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                             i_addr + g_uartBase));
    }

    Uart* Uart::g_device = NULL;

}
