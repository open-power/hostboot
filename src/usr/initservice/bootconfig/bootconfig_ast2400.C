/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/bootconfig/bootconfig_ast2400.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#include <sio/sio.H>
#include <devicefw/driverif.H>
#include <targeting/common/mfgFlagAccessors.H>

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
                TRACFCOMP(g_bc_trace,
                        "configureBootMode() - Boot Mode = TERMINATE_ON_ERROR");

                // Set the SRC TERM flag
                TARGETING::setMfgFlag(TARGETING::MFG_FLAGS_MNFG_SRC_TERM);

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
};

// configurePnorDriver()
// ----------------------------------------------------------------------------
void AST2400BootConfig::configurePnorDriver( uint8_t i_driver )
{
    switch (i_driver) {
    case MBOX:
        TRACFCOMP(g_bc_trace,
                "configurePnorDriver() bmc supports mbox protocol");

#ifndef CONFIG_PNORDD_IS_BMCMBOX
        TRACFCOMP(g_bc_trace,
                  "configurePnorDriver() hb does not support mbox protocol");
#else
        TRACFCOMP(g_bc_trace,
                  "configurePnorDriver() using mbox driver");
        break;
#endif

    case SFC:
        TRACFCOMP(g_bc_trace,
                "configurePnorDriver() using sfc driver");
	break;
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
    size_t l_len = sizeof(uint8_t);
    do
    {
        // The BMC may have disabled SIO, in which case we use a default set of
        // boot flags
        bool haveSio;
        l_err = SIO::isAvailable(haveSio);
        if (l_err)
        {
            break;
        }

        if (!haveSio)
        {
            processBootFlagsV1(0);
            break;
        }

        // read the register holding the agreed upon magic
        // number to indicate registers have been configured

        // Registers below 0x30 do not belong to any particular SIO device.
        // Device field advised to be set to SUART1 or iLPC2AHB as these are the
        // only two devices currently in use and will thereby save additional
        // SIO before and after this call.
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(register_data),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::DONT_CARE, BOOT_FLAGS_VERSION_REG));
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
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "Ignoring boot flags, incorrect version 0x%x", register_data);
            CONSOLE::flush();
#endif

            break;
        }

        // read the SIO register holding the boot flags
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(register_data),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::DONT_CARE, BOOT_FLAGS_REG));
        if( l_err )
        {
            TRACFCOMP(g_bc_trace,"Failed reading the boot flags, leave"
                    " settings at default values");

            break;
        }

        processBootFlagsV1( register_data );

    }while(0);

    TRACDCOMP(g_bc_trace, EXIT_MRK"readAndProcessBootConfig()");

    return l_err;
}

// ----------------------------------------------------------------------------
// processBootFlagsV1()
// ----------------------------------------------------------------------------
void AST2400BootConfig::processBootFlagsV1( uint8_t i_flags )
{
    configureBootMode( i_flags & BOOT_MODE_FLAGS );

    configurePnorDriver( i_flags & PNOR_DRIVER_FLAGS );

    configureBootOptions( i_flags & BOOT_OPTIONS_FLAGS );

    configureHbLogLevel( i_flags & LOG_LEVEL_FLAGS );
}

// ----------------------------------------------------------------------------
// readIstepControl()
// ----------------------------------------------------------------------------
errlHndl_t AST2400BootConfig::readIstepControl( istepControl_t &o_stepInfo )
{
    errlHndl_t l_err = NULL;
    size_t l_len = sizeof(uint8_t);
    do
    {
        // read istep control from 0x2a
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(o_stepInfo.istepControl),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::DONT_CARE, ISTEP_CONTROL_REG));
        if(l_err) { break; }

        // read major number from 0x2b
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(o_stepInfo.istepMajorNumber),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::DONT_CARE, ISTEP_MAJOR_REG));
        if(l_err) { break; }

        // read minor number from 0x2c
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(o_stepInfo.istepMinorNumber),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::DONT_CARE, ISTEP_MINOR_REG));
    }
    while(0);

    return l_err;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::writeIstepControl()
// ----------------------------------------------------------------------------
errlHndl_t AST2400BootConfig::writeIstepControl( istepControl_t i_istepCtl )
{
    errlHndl_t l_err = NULL;
    size_t l_len = sizeof(uint8_t);

    // read istep control from 0x2a
    TRACFCOMP( g_bc_trace, "AST2400BootConfig:: Write istep control %x",  i_istepCtl.istepControl);

    do
    {
        //write status
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(i_istepCtl.istepStatus),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::DONT_CARE, ISTEP_STATUS_REG));
        if(l_err) { break; }

        //write command/control
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(i_istepCtl.istepControl),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::DONT_CARE,
                                             ISTEP_HOST_CTL_REG));
        if(l_err) { break; }
    }
    while(0);

    return l_err;
}


};
};
