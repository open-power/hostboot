/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/bootconfig/bootconfig_ast2400.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
/******************************************************************************/
// Includes
/******************************************************************************/
#include "bootconfig_ast2400.H"
#include <lpc/lpcif.H>
#include <devicefw/userif.H>
#include <errl/errlentry.H>
#include <trace/interface.H>
#include <hwas/common/deconfigGard.H>
#include <console/consoleif.H>
#include <config.h>

namespace INITSERVICE
{
namespace BOOTCONFIG
{

// declare storage for config trace
extern trace_desc_t * g_bc_trace;

AST2400BootConfig::AST2400BootConfig()
{
    CURRENT_CONFIG_VERSION = BOOT_FLAGS_VERSION_1;
};


AST2400BootConfig::~AST2400BootConfig()
{};

// ----------------------------------------------------------------------------
// configureBootMode()
// ----------------------------------------------------------------------------
void AST2400BootConfig::configureBootMode(uint8_t i_bootMode )
{
    // assume boot mode is exclusive..
    switch( i_bootMode )
    {
        case NORMAL:
            {
                TRACFCOMP(g_bc_trace,
                        "configureBootMode() - Boot Mode = NORMAL");
                break;
            }
        // RTC:123376 - Need to investigate if any additional flags need to be
        // set or if terminate on error is sufficient
        case TERMINATE_ON_ERROR:
            {

                TARGETING::Target* l_pTopLevel = NULL;
                TARGETING::targetService().getTopLevelTarget(l_pTopLevel);

                TRACFCOMP(g_bc_trace,
                        "configureBootMode() - Boot Mode = TERMINATE_ON_ERROR");

                l_pTopLevel->setAttr<TARGETING::ATTR_MNFG_FLAGS>
                                        (TARGETING::MNFG_FLAG_SRC_TERM );
                break;
            }

        case ISTEP_MODE:
            {
                TRACFCOMP(g_bc_trace,
                        "configureBootMode() - Boot Mode = ISTEP MODE");

                TARGETING::Target* l_pTopLevel = NULL;
                TARGETING::targetService().getTopLevelTarget(l_pTopLevel);

                l_pTopLevel->setAttr<TARGETING::ATTR_ISTEP_MODE>(1);

                break;
            }

         default:
                  TRACFCOMP(g_bc_trace,
                            "WRN>>configureBootMode() - Boot mode = "
                             "INVALID[0x%x] default to normal", i_bootMode );
                break;

          break;
    }
}

// ----------------------------------------------------------------------------
// configureHbLogLevel()
// ----------------------------------------------------------------------------
void AST2400BootConfig::configureHbLogLevel(uint8_t i_logOptions )
{

    switch( i_logOptions )
    {
        case LOG_ENABLE_SCAN_TRACE:
            {
                TRACFCOMP(g_bc_trace,
                  "configureHbLogLevel() - Log level = enable scan trace");

                // enable the scan trace for now.
                TARGETING::Target* l_pTopLevel = NULL;
                TARGETING::targetService().getTopLevelTarget(l_pTopLevel);

                TARGETING::HbSettings hbSettings =
                    l_pTopLevel->getAttr<TARGETING::ATTR_HB_SETTINGS>();

                // if its not already set, then set it.
                if( !hbSettings.traceScanDebug )
                {
                    hbSettings.traceScanDebug = 1;

                    l_pTopLevel->setAttr<
                                    TARGETING::ATTR_HB_SETTINGS>(hbSettings);
                }

                break;
            }

        default:
            {
                // do nothing
                TRACFCOMP(g_bc_trace,
                        "configureLogLevel() - Log level = NORMAL");

                break;
            }
    }

}

// ----------------------------------------------------------------------------
// configureBootOptions()
// ----------------------------------------------------------------------------
void AST2400BootConfig::configureBootOptions(uint8_t i_bootOptions )
{
    // clear gard records?
    if( i_bootOptions & CLEAR_GARD_RECORDS )
    {
        TRACFCOMP(g_bc_trace,
                "configureBootOptions()"
                " clearing gard records");

        errlHndl_t errl = HWAS::theDeconfigGard().clearGardRecords(NULL);

        if(errl)
        {
            errl->collectTrace( "BOOT_CFG", 512 );
            errlCommit(errl,INITSVC_COMP_ID);
        }
    }
}

// ----------------------------------------------------------------------------
// readAndProcessBootConfig()
// ----------------------------------------------------------------------------
errlHndl_t AST2400BootConfig::readAndProcessBootConfig()
{

    TRACDCOMP(g_bc_trace, ENTER_MRK"readAndProcessBootConfig()");

    errlHndl_t l_err = NULL;

    uint8_t register_data = 0;

    do{

        l_err = unlockSIORegisters();

        if(l_err)
        {
            TRACFCOMP(g_bc_trace, "readAndProcessBootConfig()"
                    " call to unlock SIO registers failed");
            break;
        }

        // read the register holding the agreed upon magic
        // number to indicate registers have been configured
        l_err = readSIORegister( BOOT_FLAGS_VERSION_REG, register_data );

        if( l_err )
        {
            TRACFCOMP(g_bc_trace,"Failed reading the boot flags version, skip processing");
            break;
        }

        if( register_data != BOOT_FLAGS_VERSION_1 )
        {

            TRACFCOMP(g_bc_trace,"WRN>>readAndProcessBootConfig() - "
                    "boot flags not correct version"
                    " 0x%x!=0x%x", register_data, BOOT_FLAGS_VERSION_1 );

#ifdef CONFIG_CONSOLE
            CONSOLE::displayf(NULL, "Ignoring boot flags, incorrect version 0x%x", register_data);
            CONSOLE::flush();
#endif

            break;
        }

        // read the SIO register holding the boot flags
        l_err = readSIORegister( BOOT_FLAGS_REG, register_data );

        if( l_err )
        {
            TRACFCOMP(g_bc_trace,"Failed reading the boot flags, leave"
                    " settings at default values");

            break;
        }

        processBootFlagsV1( register_data );

    }while(0);

   // leave SIO registers unlocked, pnor code is dependant on
   // having access to them

    TRACDCOMP(g_bc_trace, EXIT_MRK"readAndProcessBootConfig()");

    return l_err;
}

// ----------------------------------------------------------------------------
// processBootFlagsV1()
// ----------------------------------------------------------------------------
void AST2400BootConfig::processBootFlagsV1( uint8_t i_flags )
{
    configureBootMode( i_flags & BOOT_MODE_FLAGS );

    configureBootOptions( i_flags & BOOT_OPTIONS_FLAGS );

    configureHbLogLevel( i_flags & LOG_LEVEL_FLAGS );
}

// ----------------------------------------------------------------------------
// readIstepControl()
// ----------------------------------------------------------------------------
errlHndl_t AST2400BootConfig::readIstepControl( istepControl_t &o_stepInfo )
{
    errlHndl_t l_err = NULL;

    do
    {
        // read istep control from 0x2a
        l_err = readSIORegister( ISTEP_CONTROL_REG, o_stepInfo.istepControl );

        if(l_err) break;

        // read major number from 0x2b
        l_err = readSIORegister( ISTEP_MAJOR_REG, o_stepInfo.istepMajorNumber );
        if(l_err) break;

        // read minor number from 0x2c
        l_err = readSIORegister( ISTEP_MINOR_REG, o_stepInfo.istepMinorNumber );
    }
    while(0);

    return l_err;
}


// $TODO RTC:115576 remove these functions
errlHndl_t  AST2400BootConfig::readSIORegister( uint8_t i_addr,
        uint8_t &o_data  )
{

    errlHndl_t l_err = NULL;

    o_data = 0;

    size_t length = sizeof(o_data);

    // write the value of the read register
    l_err = deviceWrite( TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
            &i_addr,
            length,
            DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO_ADDR_REG));

    if( l_err == NULL )
    {

        // get the register contents.
        l_err = deviceRead(
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                (void *)&o_data,
                length,
                DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO_DATA_REG));
    }

    return l_err;

}

// $TODO RTC:115576 remove these function
errlHndl_t  AST2400BootConfig::writeSIORegister( uint8_t i_addr,
        uint8_t i_data  )
{

    size_t length = sizeof(i_data);

    errlHndl_t l_err = NULL;

    l_err = deviceWrite(
            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
            &i_addr,
            length,
            DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO_ADDR_REG ));

    if( l_err == NULL )
    {
        l_err = deviceWrite(
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                &i_data,
                length,
                DEVICE_LPC_ADDRESS(LPC::TRANS_IO, SIO_DATA_REG ));
    }

    return l_err;
}

// $TODO RTC:115576 remove these function
errlHndl_t AST2400BootConfig::unlockSIORegisters()
{
    errlHndl_t l_err = NULL;
    uint8_t key = SIO_REG_UNLOCK_KEY;
    size_t length = sizeof(key);

    do {

        // Write out the register address
        l_err = deviceWrite(
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                &key,
                length,
                DEVICE_LPC_ADDRESS(LPC::TRANS_IO,SIO_ADDR_REG) );

        if(l_err) break;

        // Write out the register address
        l_err = deviceWrite(
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                &key,
                length,
                DEVICE_LPC_ADDRESS(LPC::TRANS_IO,SIO_ADDR_REG) );

    }while(0);

    return l_err;
}

// $TODO RTC:115576 remove these function
void AST2400BootConfig::lockSIORegisters()
{
    // write the data to lock it back up..
    uint8_t key = SIO_REG_LOCK_KEY;
    size_t length = sizeof(uint8_t);

    // Write out the register address
    errlHndl_t l_err = deviceWrite(
            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
            &key,
            length,
            DEVICE_LPC_ADDRESS(LPC::TRANS_IO,SIO_ADDR_REG) );

    if(l_err)
    {
        TRACFCOMP(g_bc_trace, "FAILED locking SIO registers");
        errlCommit(l_err, ISTEP_COMP_ID);
    }
}

};
};
