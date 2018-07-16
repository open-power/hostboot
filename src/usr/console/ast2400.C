/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/console/ast2400.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2018                        */
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
#include <sio/sio.H>
#include "uart.H"
#include <devicefw/userif.H>
#include <lpc/lpcif.H>
#include <errl/errlmanager.H>
#include <kernel/console.H>
#include <devicefw/driverif.H>
#include <initservice/bootconfigif.H>
#include <console/uartif.H>

namespace CONSOLE
{
    const uint32_t VUART1_BASE      = 0x1E787000;
    const uint32_t VUART1_GCTRLA    = VUART1_BASE + 0x20;
    const uint32_t VUART1_GCTRLB    = VUART1_BASE + 0x24;
    const uint32_t VUART1_ADDRL     = VUART1_BASE + 0x28;
    const uint32_t VUART1_ADDRH     = VUART1_BASE + 0x2c;

    /** Overload the base class with Ast2400 specifics.
     *
     *  In initialization we need to program the SIO device on the AST2400 to
     *  enable the Uart device.
     */
    class Ast2400Uart : public Uart
    {
     public:
        enum platFlagsMask_t
        {
            /**
             * @brief ISOLATE_SP flag
             *
             * If the ISOLATE_SP flag is set, then the service processor must
             * configure:
             *
             * 1. A UART device at 0x3f8, SIRQ 4, low polarity
             * 2. The BT device at 0xe4, SIRQ 10, low polarity
             */
            ISOLATE_SP      = 0x01,
            CONSOLE_FLAGS   = 0xc0,
        };

        enum consoleConfig_t
        {
            NONE            = 0x00,  // No output selected
            SELECT_SUART    = 0x40,  // SIO Uart
            SELECT_VUART    = 0x80,  // SOL virtual uart
            RESERVED        = 0xc0,  // Reserved
        };

     private:
        void initializeSUART()
        {
            errlHndl_t l_errl = NULL;
            uint8_t l_data;
            size_t l_len = sizeof(uint8_t);
            do
            {
                // Disable SUART1 to change settings
                l_data = SIO::DISABLE_DEVICE;
                l_errl = deviceOp( DeviceFW::WRITE,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &(l_data),
                                  l_len,
                                  DEVICE_SIO_ADDRESS(SIO::SUART1, 0x30));
                if (l_errl) { break; }

                // Set SUART1 addr to g_uartBase
                l_data =(g_uartBase >> 8) & 0xFF;
                l_errl = deviceOp( DeviceFW::WRITE,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &(l_data),
                                  l_len,
                                  DEVICE_SIO_ADDRESS(SIO::SUART1, 0x60));
                if (l_errl) { break; }

                l_data = g_uartBase & 0xFF;
                l_errl = deviceOp( DeviceFW::WRITE,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &(l_data),
                                  l_len,
                                  DEVICE_SIO_ADDRESS(SIO::SUART1, 0x61));
                if (l_errl) { break; }

                // Set the SerIRQ
                l_data = SERIAL_IRQ;
                l_errl = deviceOp( DeviceFW::WRITE,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &(l_data),
                                  l_len,
                                  DEVICE_SIO_ADDRESS(SIO::SUART1, 0x70));
                if (l_errl) { break; }

                l_data = LOW_LEVEL_TRIG;
                l_errl = deviceOp( DeviceFW::WRITE,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &(l_data),
                                  l_len,
                                  DEVICE_SIO_ADDRESS(SIO::SUART1, 0x71));
                if (l_errl) { break; }

                // Enable SUART1
                l_data = SIO::ENABLE_DEVICE;
                l_errl = deviceOp( DeviceFW::WRITE,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &(l_data),
                                  l_len,
                                  DEVICE_SIO_ADDRESS(SIO::SUART1, 0x30));
                if (l_errl) { break; }

            } while(0);

            if (l_errl)
            {
                setFailed();
                errlCommit(l_errl, CONSOLE_COMP_ID);
            }

            Uart::initialize();
        }

        // initialize for SOL support
        void initializeVUART()
        {
            errlHndl_t l_err = NULL;

            do
            {
                uint32_t v;
                size_t l_len = sizeof(v);
                /* Enable device 0x0D*/
                uint8_t l_data = SIO::ENABLE_DEVICE;
                l_err = deviceOp( DeviceFW::WRITE,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  (&l_data),
                                  l_len,
                                  DEVICE_SIO_ADDRESS(SIO::iLPC2AHB,0x30));
                if(l_err) { break; }
                /* configure IRQ level as low */
                l_err = deviceOp( DeviceFW::READ,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &(v),
                                  l_len,
                                  DEVICE_AHB_SIO_ADDRESS(VUART1_GCTRLA));
                if(l_err){break;}
                v = v & ~2u;
                l_err = deviceOp(DeviceFW::WRITE,
                                 TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                 &(v),
                                 l_len,
                                 DEVICE_AHB_SIO_ADDRESS(VUART1_GCTRLA));

                if(l_err){break;}

                /* configure the IRQ number */
                l_err = deviceOp( DeviceFW::READ,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &(v),
                                  l_len,
                                  DEVICE_AHB_SIO_ADDRESS(VUART1_GCTRLB));
                if(l_err){break;}

                v = (v & ~0xf0u) | ((SERIAL_IRQ << 4));
                l_err = deviceOp(DeviceFW::WRITE,
                                 TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                 &(v),
                                 l_len,
                                 DEVICE_AHB_SIO_ADDRESS(VUART1_GCTRLB));
                if(l_err){break;}

                /* configure the address */
                v =  g_uartBase & 0xff;
                l_err = deviceOp(DeviceFW::WRITE,
                                 TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                 &(v),
                                 l_len,
                                 DEVICE_AHB_SIO_ADDRESS(VUART1_ADDRL));
                if(l_err){break;}

                v = g_uartBase >> 8;
                l_err = deviceOp(DeviceFW::WRITE,
                                 TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                 &(v),
                                 l_len,
                                 DEVICE_AHB_SIO_ADDRESS(VUART1_ADDRH));
                if(l_err){break;}

            }while(0);

            if (l_err)
            {
                printk("VUART: config failed at\n");
                setFailed();
                errlCommit(l_err, CONSOLE_COMP_ID);
            }
            else
            {
                printk("VUART: config SUCCESS\n" );
            }

            Uart::initialize();
        }

        void disableVUART()
        {
            errlHndl_t l_err = NULL;

            do
            {
               // read the control reg, mask off the enabled bit
               // and write it back
                uint32_t reg_value = 0;
                size_t l_len = sizeof(reg_value);
                l_err = deviceOp(DeviceFW::READ,
                                 TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                 &(reg_value),
                                 l_len,
                                 DEVICE_AHB_SIO_ADDRESS(VUART1_GCTRLA));

                if(l_err){break;}

                // mask off the low order bit to mark the vuart as disabled
                reg_value &= 0xFE;
                l_err = deviceOp(DeviceFW::WRITE,
                                 TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                 &(reg_value),
                                 l_len,
                                 DEVICE_AHB_SIO_ADDRESS(VUART1_GCTRLA));
                if(l_err){break;}

            }while(0);

            if (l_err)
            {
                errlCommit(l_err, CONSOLE_COMP_ID);
            }
        };

        void disableSUART()
        {
            errlHndl_t l_err = NULL;

            do
            {
                // clear the uart enable from base ctl reg
                uint8_t l_data = SIO::DISABLE_DEVICE;
                size_t l_len = sizeof(uint8_t);
                l_err = deviceOp( DeviceFW::WRITE,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &(l_data),
                                  l_len,
                                  DEVICE_SIO_ADDRESS(SIO::SUART1, 0x30));

            }while(0);

            if (l_err)
            {
                errlCommit(l_err, CONSOLE_COMP_ID);
            }
        };

    public:

        virtual void initialize()
        {
            // read the SIO register set by the BMC to determine uart config
            const uint8_t expected_version =
                INITSERVICE::BOOTCONFIG::BOOT_FLAGS_VERSION_1;
            uint8_t this_version = 0x00;

            errlHndl_t l_err = NULL;
            size_t l_len = sizeof(uint8_t);
            uint8_t plat_config = 0x00;

            do
            {
                //  verify the boot flags version from register 0x28
                l_err = deviceOp( DeviceFW::READ,
                                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &(this_version),
                                  l_len,
                                  DEVICE_SIO_ADDRESS(SIO::SUART1, 0x28));
                if (l_err) { break; }
                // is it the version we expected?
                if( expected_version == this_version )
                {
                    l_err = deviceOp( DeviceFW::READ,
                                      TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                      &(plat_config),
                                      l_len,
                                      DEVICE_SIO_ADDRESS(SIO::SUART1, 0x2d));
                    if (l_err) { break; }

                    if (plat_config & ISOLATE_SP)
                    {
                        printk("ast2400: UART configured by BMC\n");
                        Uart::initialize();
                        break;
                    }

                    // determine which config has been selected
                    consoleConfig_t uart_config =
                        static_cast<consoleConfig_t>(plat_config & CONSOLE_FLAGS);

                    switch ( uart_config )
                    {
                        case SELECT_SUART:
                            {
                                printk("ast2400: SUART config in process\n");
                                disableVUART();
                                initializeSUART();
                                break;
                            }
                        case SELECT_VUART:
                            {
                                printk("ast2400: VUART config in process\n");
                                disableSUART();
                                initializeVUART();
                                break;
                            }
                        case NONE:
                            {
                                // no config selected disable both
                                disableSUART();
                                disableVUART();
                                printk("ast2400: no config selected, "
                                                   "disable console output.\n");
                            }
                        default:
                            {
                                printk("ast2400: invalid config data"
                                       " default to SUART configuration\n");
                                initializeSUART();
                            }
                    }
                }
                else
                {
                    // invalid version read from SIO register 0x28
                    printk("ast2400: Invalid boot config version %d\n", this_version);
                    initializeSUART();
                }

            }while(0);

            if (l_err)
            {
                setFailed();
                errlCommit(l_err, CONSOLE_COMP_ID);
            }
       }
    };

CONSOLE_UART_DEFINE_DEVICE(Ast2400Uart);

};
