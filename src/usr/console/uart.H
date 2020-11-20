/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/console/uart.H $                                      */
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

/**
 * @file uart.H
 *
 * @brief Defines interface for console support
 *
 */

#ifndef __CONSOLE_UART_H
#define __CONSOLE_UART_H

#include <errl/errlentry.H>
#include <console/uartif.H>

namespace CONSOLE
{
    /**
     *  Enums used for controlling behavior of the TX FIFO
     */
    enum FIFO_CONTROL
    {
        // Max number of characters that can fit into the transmit FIFO at
        // one time.
        TX_FIFO_SIZE = 16,

        // Start filling the FIFO without blocking when at least this many
        // characters in the FIFO are free.
        TX_FIFO_UNBLOCK_THRESHOLD = 1,

        // If FIFO was not empty in the last polling interval, amount of time
        // to wait before checking again, in nanoseconds.
        DELAY_NS = 100,

        // Number of times to poll for the FIFO to be empty before giving up.
        DELAY_LOOPS = 100000000,
    };

    namespace UARTREGS
    {
        /** UART Register Offsets */
        enum
        {
            RBR = 0,    ///< Recv Buffer
            THR = 0,    ///< Tran Holding
            DLL = 0,    ///< Divisor Latch LSB
            IER = 1,    ///< Interrupt Enable
            DLM = 1,    ///< Divisor Latch MSB
            FCR = 2,    ///< FIFO Control
            IIR = 2,    ///< Interrupt Identification
            LCR = 3,    ///< Line Control
            MCR = 4,    ///< Modem Control
            LSR = 5,    ///< Line Status
            MSR = 6,    ///< Modem Status
            SCR = 7,    ///< Scratch
        };

        /** Line Status Register (LSR) bit definitions */
        enum
        {
            LSR_DR = 0x01,    ///<  Data ready
            LSR_OE = 0x02,    ///<  Overrun
            LSR_PE = 0x04,    ///<  Parity error
            LSR_FE = 0x08,    ///<  Framing error
            LSR_BI = 0x10,    ///<  Break
            LSR_THRE = 0x20,  ///<  Xmit holding register empty
            LSR_TEMT = 0x40,  ///<  Xmitter empty
            LSR_ERR = 0x80,   ///<  Error
            LSR_BAD = 0xff,   ///<  Invalid value for LSR
        };

        /** Line Control Register (LCR) bit definitions */
        enum
        {
            LCR_DWL5 = 0x00,  ///<  Data word length: 5 bits
            LCR_DWL6 = 0x01,  ///<  Data word length: 6 bits
            LCR_DWL7 = 0x02,  ///<  Data word length: 7 bits
            LCR_DWL8 = 0x03,  ///<  Data word length: 8 bits

            LCR_STP1 = 0x00,  ///<  1 stop bits
            LCR_STP2 = 0x04,  ///<  1.5(5) or 2(6,7,8) stop bits

            LCR_NOP  = 0x00,  ///<  No Parity
            LCR_ODDP = 0x08,  ///<  Odd Parity
            LCR_EVEP = 0x18,  ///<  Even Parity
            LCR_HIP  = 0x28,  ///<  High Parity
            LCR_LOP  = 0x38,  ///<  Low Parity

            LCR_DLAB = 0x80,  ///<  DLL access
        };

        /** Modem Control Register (MCR) bit definitions */
        enum
        {
            MCR_DTR = 0x01,   ///<  Data terminal ready
            MCR_RTS = 0x02,   ///<  Request to send
        };

        /** FIFO Control Register (FCR) bit definitions */
        enum
        {
            FCR_ENF  = 0x01,   ///<  Enable FIFOs.
            FCR_CLFR = 0x02,   ///<  Clear Receive FIFO.
            FCR_CLFT = 0x04,   ///<  Clear Transmit FIFO
        };
    }

    /** @class Uart
     *  @brief Abstraction class for UART-based console operations.
     */
    class Uart
    {
        public:
            Uart() : iv_initialized(false), iv_failed(false) {};
            virtual ~Uart() {};

            /** Display character to console. */
            virtual void putc(char c);

            /** Get character from console. */
            //virtual void getc(char& c);

            /** Perform UART-specific initialization. */
            virtual void initialize(const uartId_t i_handle);

            /** Offsets to key registers for the UART device.
                See uartconfig.C. */
            uint64_t iv_base;
            uint64_t iv_baud;
            uint64_t iv_clock;


        protected:

            /** Perform write operation to UART engine. */
            virtual errlHndl_t writeReg(uint64_t i_addr, uint8_t i_byte);
            /** Perform read operation to UART engine. */
            virtual errlHndl_t readReg(uint64_t i_addr, uint8_t& o_byte);

            void setFailed() { iv_failed = true; }

        private:
            bool iv_initialized;
            bool iv_failed;

                // Prohibit copy constructors.
            Uart(const Uart&);
            Uart& operator=(const Uart&);
    };

    // Static configuration constants.  See uartconfig.C.
    extern const uint64_t g_vuart1Base;
    extern const uint64_t g_vuart1Baud;
    extern const uint64_t g_vuart1Clock;
    extern const uint64_t g_vuart2Base;
    extern const uint64_t g_vuart2Baud;
    extern const uint64_t g_vuart2Clock;
}

/** Helper macro to associate inherited UART device with the singleton. */
#define CONSOLE_UART_DEFINE_DEVICE(Type) \
    class ConsoleInit##Type \
    { \
        public: \
            ConsoleInit##Type() \
            { \
                Uart::g_device = new Type(); \
                Uart::g_device->initialize(); \
            } \
    }; \
    ConsoleInit##Type __console_init_##Type;

#endif
