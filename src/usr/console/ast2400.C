/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/console/ast2400.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#include <kernel/console.H>
#include <devicefw/driverif.H>
#include <initservice/bootconfigif.H>

namespace CONSOLE
{
    const uint32_t VUART1_BASE    = 0x1E787000;
    const uint32_t VUART1_GCTRLA  = VUART1_BASE + 0x20;
    const uint32_t VUART1_GCTRLB  = VUART1_BASE + 0x24;
    const uint32_t VUART1_ADDRL   = VUART1_BASE + 0x28;
    const uint32_t VUART1_ADDRH   = VUART1_BASE + 0x2c;

    const uint8_t SERIAL_IRQ      = 4;

    const uint8_t SIO_ADDR_REG_2E = 0x2E;
    const uint8_t SIO_DATA_REG_2F = 0x2F;

    // used to test config flags related to console outup selection
    const uint8_t CONFIG_MASK = 0xC0;

    /** Overload the base class with Ast2400 specifics.
     *
     *  In initialization we need to program the SIO device on the AST2400 to
     *  enable the Uart device.
     */
    class Ast2400Uart : public Uart
    {

     public:
        enum consoleConfig_t
        {
            NONE            = 0x00,  // No output selected
            SELECT_SUART    = 0x40,  // SIO Uart
            SELECT_VUART    = 0x80,  // SOL virtual uart
            RESERVED        = 0xc0,  // Reserved
        };

     private:
        // $TODO RTC:115576 remove these sio write functions when SIO dd code
        // is completed
        // Perform raw LPC writes to SIO region.
        errlHndl_t _writeReg(uint8_t i_addr, uint8_t i_byte)
        {
            size_t len = sizeof(i_byte);
            return deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                &i_byte,
                                len,
                                DEVICE_LPC_ADDRESS(LPC::TRANS_IO, i_addr));
        }

        // write i_data to register i_reg
        errlHndl_t writeSIOReg( uint8_t i_reg, uint8_t i_data )
        {
            errlHndl_t l_err = NULL;

            do{

                l_err = _writeReg( SIO_ADDR_REG_2E, i_reg );

                if(l_err) { break; }

                l_err = _writeReg( SIO_DATA_REG_2F, i_data );

            }while(0);

            return l_err;
        }

        // Perform reads from the SIO register region.
        errlHndl_t readSIOReg(uint8_t i_reg, uint8_t &o_byte)
        {
            errlHndl_t l_err = NULL;

            size_t len = sizeof(o_byte);

            do{
                l_err =  deviceWrite(
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        &i_reg,
                        len,
                        DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO_ADDR_REG_2E));

                if(l_err) { break; }

                l_err =  deviceRead(
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        &o_byte,
                        len,
                        DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO_DATA_REG_2F));
            }while(0);

            return l_err;
        }

        // setup the AHB access
        errlHndl_t ahbSioAddressPrep(uint32_t reg)
        {
            errlHndl_t l_err = NULL;

            do{
                // Select logical device D (LPC2AHB)
                l_err = writeSIOReg( 0x07, 0x0D );
                if( l_err ) { break; }

                /* Enable iLPC->AHB */
                l_err = writeSIOReg( 0x30, 0x01 );
                if( l_err ) { break; }

                /* Address */
                l_err = writeSIOReg(0xF0, (reg >> 24) & 0xff);
                if( l_err ) {break; }

                l_err = writeSIOReg(0xF1, (reg >> 16) & 0xff);
                if( l_err ) {break; }

                l_err = writeSIOReg(0xF2, (reg >>  8) & 0xff);
                if( l_err ) {break; }

                l_err = writeSIOReg(0xF3, (reg      ) & 0xff);
                if( l_err ) {break; }

                /* bytes per cycle type */
                l_err = writeSIOReg(0xF8, 0x02);
                if( l_err ) {break; }

            }while(0);

            return l_err;
        }

        errlHndl_t ahbSioWrite(uint32_t reg, uint32_t val )
        {
            errlHndl_t l_err = NULL;

            do{

                l_err = ahbSioAddressPrep( reg);
                if( l_err ) { break; }

                /* Write data */
                l_err = writeSIOReg(0xF4, val >> 24);
                if( l_err ) { break; }
                l_err = writeSIOReg(0xF5, val >> 16);
                if( l_err ) { break; }
                l_err = writeSIOReg(0xF6, val >>  8);
                if( l_err ) { break; }
                l_err = writeSIOReg(0xF7, val);
                if( l_err ) { break; }

                /* Trigger the write with the magic number */
                l_err = writeSIOReg(0xFe, 0xcf);

            }while(0);

            return l_err;
        }

        errlHndl_t ahbSioRead( uint32_t reg, uint32_t &o_data )
        {
            errlHndl_t l_err = NULL;
            uint8_t tmp_data = 0;
            o_data = 0;

            do{

                l_err = ahbSioAddressPrep(reg);
                if(l_err){break;}

                /* Trigger the read - ignore the output data */
                l_err = readSIOReg(0xFE, tmp_data);
                if(l_err){break;}

                tmp_data = 0;

                /* Read results */
                l_err = readSIOReg(0xF4, tmp_data );
                if(l_err){;break;}
                o_data =  tmp_data;

                l_err = readSIOReg(0xF5, tmp_data );
                if(l_err){break;}
                o_data = (o_data << 8) | tmp_data;

                l_err = readSIOReg(0xF6, tmp_data );
                if(l_err){break;}
                o_data = (o_data << 8) | tmp_data;

                l_err = readSIOReg(0xF7, tmp_data );
                if(l_err){break;}
                o_data = (o_data << 8) | tmp_data;

            }while(0);

            return l_err;
        }

        private:

        void initializeSUART()
        {
            errlHndl_t l_errl = NULL;

            do
            {
                // Select logical device 2 (SUART1) in SI)
                l_errl = writeSIOReg( 0x07, 0x02);
                if (l_errl) { break; }

                // Disable SUART1 to change settings
                l_errl = writeSIOReg( 0x30, 0x00 );
                if (l_errl) { break; }

                // Set SUART1 addr to g_uartBase
                l_errl = writeSIOReg( 0x60, (g_uartBase >> 8) & 0xFF );
                if (l_errl) { break; }

                l_errl = writeSIOReg( 0x61, (g_uartBase & 0xFF) );
                if (l_errl) { break; }

                // Set the SerIRQ
                l_errl = writeSIOReg( 0x70, SERIAL_IRQ );
                if (l_errl) { break; }

                l_errl = writeSIOReg( 0x71, 0x01 );
                if (l_errl) { break; }


                // Enable SUART1
                l_errl = writeSIOReg( 0x30, 0x01 ); // select SIO base enable
                if (l_errl) { break; }

                //@fixme-RTC:115576 - Leaving SIO unlocked for now to allow
                //   PNOR write/erase to work
                // Lock the SIO registers
                //l_errl = _writeReg( 0x2e, 0xAA );
                //if (l_errl) { break; }

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

            do{
                uint32_t v;

                /* configure IRQ level as low */
                l_err = ahbSioRead(VUART1_GCTRLA, v);
                if(l_err){break;}
                v = v & ~2u;
                l_err = ahbSioWrite(VUART1_GCTRLA, v);
                if(l_err){break;}

                /* configure the IRQ number */
                l_err = ahbSioRead(VUART1_GCTRLB, v);
                if(l_err){break;}

                v = (v & ~0xf0u) | ((SERIAL_IRQ << 4));
                l_err = ahbSioWrite(VUART1_GCTRLB,v);
                if(l_err){break;}

                /* configure the address */
                l_err = ahbSioWrite(VUART1_ADDRL, g_uartBase & 0xff);
                if(l_err){break;}

                l_err = ahbSioWrite(VUART1_ADDRH, g_uartBase >> 8);

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

            do{
               // read the control reg, mask off the enabled bit
               // and write it back
                uint32_t reg_value = 0;

                l_err = ahbSioRead(VUART1_GCTRLA, reg_value );
                if(l_err){break;}

                // mask off the low order bit to mark the vuart as disabled
                reg_value &= 0xFE;
                l_err = ahbSioWrite(VUART1_GCTRLA, reg_value );
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

            do{

                // select device 2 - UART1
                l_err = writeSIOReg(0x07, 0x02);
                if(l_err){break;}

                // clear the uart enable from base ctl reg
                l_err = writeSIOReg(0x30, 0);

            }while(0);

            if (l_err)
            {
                errlCommit(l_err, CONSOLE_COMP_ID);
            }
        };

        virtual void unlockSIO()
        {
            errlHndl_t l_err = NULL;
            do{
                // Unlock the SIO registers
                //  (write 0xA5 password to offset 0x2E two times)
                l_err = _writeReg( SIO_ADDR_REG_2E, 0xA5 );
                if (l_err) { break; }

                l_err = _writeReg( SIO_ADDR_REG_2E, 0xA5 );

            }while(0);

            if (l_err)
            {
                errlCommit(l_err, CONSOLE_COMP_ID);
            }

        }

        public:

        virtual void initialize()
        {
            // read the SIO register set by the BMC to determine uart config
            const uint8_t expected_version =
                INITSERVICE::BOOTCONFIG::BOOT_FLAGS_VERSION_1;

            uint8_t this_version = 0x00;

            errlHndl_t l_err = NULL;

            uint8_t uart_config = 0x00;

            do{
                // allow access to the registers
                unlockSIO();

                //  verify the boot flags version from register 0x28
                l_err = readSIOReg( 0x28, this_version );

                if (l_err) { break; }

                // is it the version we expected?
                if( expected_version == this_version )
                {
                    l_err = readSIOReg(0x2d, uart_config);

                    if (l_err) { break; }

                    // determine which config has been selected
                    consoleConfig_t config =
                        static_cast<consoleConfig_t>(uart_config & CONFIG_MASK);

                    switch ( config )
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
