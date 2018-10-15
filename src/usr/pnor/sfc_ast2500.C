/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_ast2500.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <sio/sio.H>
#include <sys/mmio.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <targeting/common/targetservice.H>
#include <pnor/pnor_reasoncodes.H>
#include <sys/time.h>
#include <errl/hberrltypes.H>
#include <lpc/lpcif.H>
#include "sfc_ast2500.H"
#include "norflash.H"
#include "sfc_ast2X00.H"
#include <util/align.H>
#include "pnor_common.H"

/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/


/*****************************************************************************/
// G l o b a l s
/*****************************************************************************/

// Initialized in pnorrp.C
extern trace_desc_t* g_trac_pnor;
/*****************************************************************************/
// M e t h o d s
/*****************************************************************************/
namespace PNOR {
/**
 * @brief Wrapper for device driver constructor
 */
errlHndl_t create_SfcDD( SfcDD*& o_sfc,
                         TARGETING::Target* i_proc )
{
    errlHndl_t l_err = NULL;
    TRACFCOMP( g_trac_pnor, "Creating SfcAST2500 object" );
    o_sfc = new SfcAST2500( l_err, i_proc );
    return l_err;
}

};

/**
 * @brief Constructor
 */
SfcAST2500::SfcAST2500( errlHndl_t& o_err,
                        TARGETING::Target* i_proc )
: SfcAST2X00(o_err,i_proc)
{
}

/**
 * @brief Initialize and configure the SFC hardware
 */
errlHndl_t SfcAST2500::hwInit( )
{
    TRACFCOMP( g_trac_pnor, ENTER_MRK"SfcAST2500::hwInit>" );
    errlHndl_t l_err = NULL;
    uint32_t l_lpc_addr;
    do
    {
        // The BMC may have disabled SIO access, but there's not much point in
        // testing whether it's available as there's no alternative action if
        // it is not. Instead, just try the SIO accesses and bail out with the
        // errl if they fail.

        /* Enable device 0x0D*/
        uint8_t l_data = SIO::ENABLE_DEVICE;
        size_t l_len = sizeof(l_data);
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          (&l_data),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::iLPC2AHB,0x30));
        if(l_err) { break; }

        /* ----- Setup the SPI Controller ----- */

        /* Enable write command mode to CE0 */
        SpiCE0ControlReg10_t l_ctlregCE0;
        l_lpc_addr = CE0_CTRLREG_10 | SPIC_BASE_ADDR_AHB;
        l_err = ahbSioReadWrapper(l_ctlregCE0.data32, l_lpc_addr);
        if( l_err ) { break; }

        l_ctlregCE0.cmdMode=0b10; //10:Normal Write (CMD + Address + Write data)
        l_err = ahbSioWriteWrapper(l_ctlregCE0.data32, l_lpc_addr);
        if( l_err ) { break; }

/* @TODO RTC:162680
        // Enable write command mode to CE1
        SpiCE1ControlReg14_t l_ctlregCE1;
        l_lpc_addr = CE1_CTRLREG_14 | SPIC_BASE_ADDR_AHB;
        l_err = ahbSioReadWrapper(l_ctlregCE1.data32, l_lpc_addr);
        if( l_err ) { break; }

        l_ctlregCE1.cmdMode=0b10; //10:Normal Write (CMD + Address + Write data)
        l_err = ahbSioWriteWrapper(l_ctlregCE1.data32, l_lpc_addr);
        if( l_err ) { break; }
**/

        /* Enable writing to CE0 and CE1 */
        SpiConfigReg00_t confreg;
        l_lpc_addr = CONFREG_00 | SPIC_BASE_ADDR_AHB;
        l_err = ahbSioReadWrapper(confreg.data32, l_lpc_addr);
        if( l_err ) { break; }

        confreg.enableCE0Write = 1; //Enable flash memory write for CE0
        //@TODO RTC:162680 - confreg.enableCE1Write = 1;
        l_err = ahbSioWriteWrapper(confreg.data32, l_lpc_addr);
        if( l_err ) { break; }

        /*
         * Setup base CE Control reg for our use, four byte mode for address
         * selection and setting 2x clock cycles
         */
        SpiCEControlReg04_t l_ceCtrlReg;
        l_lpc_addr = CE_CTLREG_04 | SPIC_BASE_ADDR_AHB;
        l_err = ahbSioReadWrapper(confreg.data32, l_lpc_addr);
        if( l_err ) { break; }

        l_ceCtrlReg.enableCE0Div2 = 1; //Enable 2x clock cycles for CE0
        l_ceCtrlReg.fourByteModeCE0 = 1;
        /* @TODO RTC:162680
         * l_ceCtrlReg.enableCE1Div2 = 1; //Enable 2x clock cycles for CE1
         * l_ceCtrlReg.fourByteModeCE1 = 1;
         */
        l_err = ahbSioWriteWrapper(l_ceCtrlReg.data32, l_lpc_addr);
        if( l_err ) { break; }

        /*
         * Setup control regs for CE0 + CE1 for our use, switching
         * to 1-bit mode (ioMode == 0b00), clearing user mode if
         * set (cmdMode == 0b00)
         * etc...
         *
         * Also configure SPI clock to something safe
         * like HCLK/8 (24Mhz)
         */
        l_ctlregCE0.ioMode = 0b00; //single bit or controlled by bit[3]
        l_ctlregCE0.pulseWidth = 0x0; //0000: 16T (1T = 1 HCLK clock)
        l_ctlregCE0.cmdData = 0x00;
        l_ctlregCE0.spiClkFreq = 0x4; //HCLK/8
        l_ctlregCE0.dummyCycleRead1 = 0; //no dummy cycles
        l_ctlregCE0.dummyCycleRead2 = 0b00; //no dummy cycles
        l_ctlregCE0.cmdMode = 0b00; //00:Normal Read (03h + Address + Read data)

        /* @TODO RTC:162680
        l_ctlregCE1.ioMode = 0b00; //single bit or controlled by bit[3]
        l_ctlregCE1.pulseWidth = 0x0; //0000: 16T (1T = 1 HCLK clock)
        l_ctlregCE1.cmdData = 0x00;
        l_ctlregCE1.spiClkFreq = 0x4; //HCLK/8
        l_ctlregCE1.dummyCycleRead1 = 0; //no dummy cycles
        l_ctlregCE1.dummyCycleRead2 = 0b00; //no dummy cycles
        l_ctlregCE1.cmdMode = 0b00; //00:Normal Read (03h + Address + Read data)
        **/

        iv_ctlRegCE0Default = l_ctlregCE0; // Default setup is regular read mode
        // @TODO RTC:162680 iv_ctlRegCE1Default = l_ctlregCE1;

        // Configure CE0 for read
        l_lpc_addr = CE0_CTRLREG_10 | SPIC_BASE_ADDR_AHB;
        l_err = ahbSioWriteWrapper(l_ctlregCE0.data32, l_lpc_addr);
        if( l_err ) { break; }

        /*  @TODO RTC:162680
        // Configure CE1 for read
        l_lpc_addr = CE1_CTRLREG_14 | SPIC_BASE_ADDR_AHB;
        l_err = ahbSioWriteWrapper(l_ctlregCE1.data32, l_lpc_addr);
        if( l_err ) { break; }
        **/

        // Figure out what flash chip we have
        uint32_t chipid = 0;
        l_err = getNORChipId( chipid );
        if( l_err ) { break; }

        // Setup flash-specific settings here, if there are any

    } while(0);

    TRACFCOMP( g_trac_pnor, EXIT_MRK"SfcAST2500::hwInit> err=%.8X", ERRL_GETEID_SAFE(l_err) );
    return l_err;
}

/**
 * @brief Enter/exit command mode
 */
errlHndl_t SfcAST2500::commandMode( bool i_enter )
{
    errlHndl_t l_err = NULL;
    uint32_t l_lpc_addr;
    TRACDCOMP( g_trac_pnor, ENTER_MRK"SfcAST2500::commandMode(%d)", i_enter );

    /*
     * There is only a limited addressable window within LPC space.  The AST
     * has its control register space at too far of a distance from the read
     * space for them both to fit in a single window.  Rather than moving the
     * window around we will use the iLPC2AHB backdoor inside the SuperIO
     * controller to do both register accesses and to write into the flash.
     *
     * High level flow to write into control space:
     *    Stop active control (SPI04 Control Reg)
     *    Enable command mode (SPI04 Control Reg)
     *    Write actual command into flash base addr (0x0E000000)
     */

    do {
        //@TODO RTC:162680 - Does this path also need to enable
        //  the CE1 control reg (0x14)
        SpiCE0ControlReg10_t ctlreg = iv_ctlRegCE0Default;

        // Switch to user mode, CE# dropped
        ctlreg.stopActiveCtl = 1;
        ctlreg.cmdMode = 0b11; //User Mode (Read/Write Data)
        l_lpc_addr = CE0_CTRLREG_10 | SPIC_BASE_ADDR_AHB;
        l_err = ahbSioWriteWrapper(ctlreg.data32, l_lpc_addr);
        if( l_err ) { break; }

        if( i_enter ) //ast_sf_start_cmd
        {
            // user mode, CE# active
            ctlreg.stopActiveCtl = 0;
            l_err = ahbSioWriteWrapper(ctlreg.data32, l_lpc_addr);
            if( l_err ) { break; }
        }
        else //ast_sf_end_cmd
        {
            // Switch back to read mode
            l_err = ahbSioWriteWrapper(iv_ctlRegCE0Default.data32, l_lpc_addr);
            if( l_err ) { break; }
        }

    } while(0);

    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcAST2500::commandMode> err=%.8X", ERRL_GETEID_SAFE(l_err) );
    return l_err;
}
