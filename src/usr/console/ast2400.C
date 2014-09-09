/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/console/ast2400.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#include <errl/errlmanager.H>

namespace CONSOLE
{

/** Overload the base class with Ast2400 specifices.
 *
 *  In initialization we need to program the SIO device on the AST2400 to
 *  enable the Uart device.
 */
class Ast2400Uart : public Uart
{
    private:

        // Perform raw LPC writes to SIO region.
        errlHndl_t _writeReg(uint64_t i_addr, uint8_t i_byte)
        {
            size_t len = sizeof(i_byte);
            return deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                               &i_byte,
                               len,
                               DEVICE_LPC_ADDRESS(LPC::TRANS_IO, i_addr));
        }

    public:

        virtual void initialize()
        {
            errlHndl_t l_errl = NULL;

            do
            {

                // Unlock the SIO registers
                //  (write 0xA5 password to offset 0x2E two times)
                l_errl = _writeReg( 0x2e, 0xA5 );
                if (l_errl) { break; }
                l_errl = _writeReg( 0x2e, 0xA5 );
                if (l_errl) { break; }

                // Select logical device 2 (SUART1) in SIO
                l_errl = _writeReg( 0x2e, 0x07 ); // select logical dev number
                if (l_errl) { break; }
                l_errl = _writeReg( 0x2f, 0x02 ); // write device 2
                if (l_errl) { break; }

                // Disable SUART1 to change settings
                l_errl = _writeReg( 0x2e, 0x30 ); // select SIO base enable
                if (l_errl) { break; }
                l_errl = _writeReg( 0x2f, 0x00 ); // clear enable
                if (l_errl) { break; }

                // Set SUART1 addr to g_uartBase
                l_errl = _writeReg( 0x2e, 0x60 ); // select SIO addr[7:3]
                if (l_errl) { break; }
                l_errl = _writeReg( 0x2f, (g_uartBase >> 8) & 0xFF );
                if (l_errl) { break; }
                l_errl = _writeReg( 0x2e, 0x61 ); // select SIO addr[15:8]
                if (l_errl) { break; }
                l_errl = _writeReg( 0x2f, (g_uartBase & 0xFF) );
                if (l_errl) { break; }

                // Set the SerIRQ
                l_errl = _writeReg( 0x2e, 0x70 );
                if (l_errl) { break; }
                l_errl = _writeReg( 0x2f, 0x04 );
                if (l_errl) { break; }
                l_errl = _writeReg( 0x2e, 0x71 );
                if (l_errl) { break; }
                l_errl = _writeReg( 0x2f, 0x01 );

                // Enable SUART1
                l_errl = _writeReg( 0x2e, 0x30 ); // select SIO base enable
                if (l_errl) { break; }
                l_errl = _writeReg( 0x2f, 0x01 ); // write enable
                if (l_errl) { break; }

                // Lock the SIO registers
                l_errl = _writeReg( 0x2e, 0xAA );
                if (l_errl) { break; }

            } while(0);

            if (l_errl)
            {
                setFailed();
                errlCommit(l_errl, CONSOLE_COMP_ID);
            }

            Uart::initialize();
        }

};

CONSOLE_UART_DEFINE_DEVICE(Ast2400Uart);

}
