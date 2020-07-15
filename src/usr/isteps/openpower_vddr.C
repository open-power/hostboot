/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/openpower_vddr.C $                             */
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
// Rhesus board-specific VDDR support.
// VDDR is enabled/disabled via a GPIO on the hammock card.
// A separate GPIO selects between 1.35V and 1.25V output from the VR.


#include "platform_vddr.H"

#include <string.h>

#include <isteps/hwpf_reasoncodes.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>

#include <kernel/timemgr.H>

#include <usr/devicefw/driverif.H>
#include <usr/gpio/gpioif.H>

using namespace TARGETING;
using namespace DeviceFW;

trace_desc_t* g_trac_vddr = NULL;
TRAC_INIT(&g_trac_vddr, "HB_VDDR",  KILOBYTE);

// PCA95X internal register addresses
enum
{
#ifdef CONFIG_PCA95X_8BIT
    PCA95X_GPIO_REG_INPUT    = 0x0,
    PCA95X_GPIO_REG_OUTPUT   = 0x1,
    PCA95X_GPIO_REG_POLARITY = 0x2,
    PCA95X_GPIO_REG_CONFIG   = 0x3,
#endif
#ifdef CONFIG_PCA95X_16BIT
    PCA95X_GPIO_REG_INPUT    = 0x0,
    PCA95X_GPIO_REG_OUTPUT   = 0x2,
    PCA95X_GPIO_REG_POLARITY = 0x4,
    PCA95X_GPIO_REG_CONFIG   = 0x6,
#endif
    PCA95X_GPIO_POLARITY_NORMAL = 0,
    PCA95X_GPIO_POLARITY_INVERTED = 1,

};

#define    PCA95X_GPIO_CONFIG_OUTPUT false
#define    PCA95X_GPIO_CONFIG_INPUT  true

// GPIO bit numbers (0-7) => port addr 0 pin(0-7)
// GPIO bit numbers  (8-15) => port addr 1 pin(0-7)
#define GPIO_TO_PORT(gpio) (gpio / 8)
#define GPIO_TO_BIT(gpio) (gpio % 8)

// Helper function to call provided function pointer on each functional
// centaur Target.

//******************************************************************************
// compareTargetsGpioInfos
//******************************************************************************

bool compareTargetsGpioInfos(
   TARGETING::TargetHandle_t i_pLhs,
   TARGETING::TargetHandle_t i_pRhs)
{

    TARGETING::ATTR_GPIO_INFO_type lhsGpioInfo =
        i_pLhs->getAttr<TARGETING::ATTR_GPIO_INFO>();
    TARGETING::ATTR_GPIO_INFO_type rhsGpioInfo =
        i_pRhs->getAttr<TARGETING::ATTR_GPIO_INFO>();

    // Code logically compares left hand side (lhs) target to right hand side
    // (rhs) target with respect to GPIO info and returns true if the left hand
    // side is logically before the right hand side.  To make the computation,
    // compare first GPIO info field for each object.  If values are not
    // logically equal, return whether the left hand side value was less than
    // the right hand side value.  Otherwise break the tie by comparing the
    // next GPIO field in similar fashion.  Continue breaking ties until the
    // last field, in which case a tie returns false.
    bool lhsLogicallyBeforeRhs =
        lhsGpioInfo.i2cMasterPath < rhsGpioInfo.i2cMasterPath;
    if(lhsGpioInfo.i2cMasterPath == rhsGpioInfo.i2cMasterPath)
    {
        lhsLogicallyBeforeRhs = lhsGpioInfo.port < rhsGpioInfo.port;
        if(lhsGpioInfo.port == rhsGpioInfo.port)
        {
            lhsLogicallyBeforeRhs = lhsGpioInfo.engine < rhsGpioInfo.engine;
            if(lhsGpioInfo.engine == rhsGpioInfo.engine)
            {
                lhsLogicallyBeforeRhs
                    = lhsGpioInfo.devAddr < rhsGpioInfo.devAddr;
                if(lhsGpioInfo.devAddr == rhsGpioInfo.devAddr)
                {
                    lhsLogicallyBeforeRhs =
                        lhsGpioInfo.vddrPin < rhsGpioInfo.vddrPin;
                }
            }
        }
    }

    return lhsLogicallyBeforeRhs;
}

//******************************************************************************
// areTargetsGpioInfoEqual
//******************************************************************************

bool areTargetsGpioInfoEqual(
   TARGETING::TargetHandle_t i_pLhs,
   TARGETING::TargetHandle_t i_pRhs)
{

    TARGETING::ATTR_GPIO_INFO_type lhsGpioInfo =
        i_pLhs->getAttr<TARGETING::ATTR_GPIO_INFO>();
    TARGETING::ATTR_GPIO_INFO_type rhsGpioInfo =
        i_pRhs->getAttr<TARGETING::ATTR_GPIO_INFO>();

    return(   (   lhsGpioInfo.i2cMasterPath
               == rhsGpioInfo.i2cMasterPath)
           && (   lhsGpioInfo.port
               == rhsGpioInfo.port)
           && (   lhsGpioInfo.engine
               == rhsGpioInfo.engine)
           && (   lhsGpioInfo.devAddr
               == rhsGpioInfo.devAddr)
           && (   lhsGpioInfo.vddrPin
               == rhsGpioInfo.vddrPin) );
}

static errlHndl_t for_each_vddr_domain_with_functional_memory(
    errlHndl_t (*func)(Target *))
{
    // TODO RTC:246369 revisit this function and either implement it or
    // remove the references to it
    errlHndl_t l_err = nullptr;

    return l_err;
}

static errlHndl_t pca95xGpioSetBit(TARGETING::Target * i_target,
                                   uint8_t i_reg,
                                   uint8_t i_gpio,
                                   bool i_val)
{
    errlHndl_t err = NULL;
    do
    {

        uint64_t cmd = i_reg + GPIO_TO_PORT(i_gpio);
        uint8_t data = 0;
        size_t dataLen = sizeof(data);

        // Might want to make this an attribute;
        // However, This is already an OpenPOWER only object
        uint64_t deviceType = GPIO::PCA95X_GPIO;

        err = DeviceFW::deviceOp
            ( DeviceFW::READ,
              i_target,
              &data,
              dataLen,
              DEVICE_GPIO_ADDRESS(deviceType, cmd)
            );

        if( err )
        {
            break;
        }

        uint8_t new_reg_val = data;
        if( i_val )
        {
            new_reg_val |= 1 << GPIO_TO_BIT(i_gpio);
        }
        else
        {
            new_reg_val &= ~(1 << GPIO_TO_BIT(i_gpio));
        }

        // Do the write only if actually changing value.
        if( new_reg_val != data )
        {
            data = new_reg_val;
            cmd = i_reg + GPIO_TO_PORT(i_gpio);

            err = DeviceFW::deviceOp
                ( DeviceFW::WRITE,
                  i_target,
                  &data,
                  dataLen,
                  DEVICE_GPIO_ADDRESS(deviceType, cmd)
                );

            if( err )
            {
                break;
            }
        }

    } while(0);

    return err;
}


static errlHndl_t pca95xGpioWriteBit(TARGETING::Target * i_target,
                                     uint8_t i_gpio_pin,
                                     bool i_val)
{
    assert( i_gpio_pin >= 0 && i_gpio_pin < 16 );
    errlHndl_t err = NULL;

    err = pca95xGpioSetBit(i_target,
                           PCA95X_GPIO_REG_OUTPUT,
                           i_gpio_pin,
                           i_val);

    // Configure gpio bit as output (if necessary).
    if(!err)
    {
        err = pca95xGpioSetBit(i_target,
                               PCA95X_GPIO_REG_CONFIG,
                               i_gpio_pin,
                               PCA95X_GPIO_CONFIG_OUTPUT);
    }

    return err;
}

static errlHndl_t enableVddrViaGpioPinStrategy(Target *centaur)
{
    errlHndl_t l_err = NULL;

    do
    {
        // Enable the DIMM power.
        TARGETING::ATTR_GPIO_INFO_type gpioInfo =
            centaur->getAttr<TARGETING::ATTR_GPIO_INFO>();

        l_err = pca95xGpioWriteBit(centaur, gpioInfo.vddrPin, true);
        if(l_err)
        {
            TRACFCOMP(g_trac_vddr,ERR_MRK " "
                "Failed to assert pca95x GPIO for Centaur HUID = 0x%08x "
                "and pin %d.",
                TARGETING::get_huid(centaur),gpioInfo.vddrPin);
            break;
        }

        TRACFCOMP(g_trac_vddr,INFO_MRK " "
            "Enabled VDDR for Centaur HUID = 0x%08x (asserted pca95x GPIO "
            "pin %d).",
            TARGETING::get_huid(centaur),
            gpioInfo.vddrPin);

    } while(0);

    return l_err;
}

static errlHndl_t disableVddrViaGpioPinStrategy(Target *centaur)
{
    errlHndl_t l_err = NULL;

    do
    {
        // Disable the DIMM power.
        TARGETING::ATTR_GPIO_INFO_type gpioInfo =
            centaur->getAttr<TARGETING::ATTR_GPIO_INFO>();

        l_err = pca95xGpioWriteBit(centaur,gpioInfo.vddrPin, false);
        if(l_err)
        {
            TRACFCOMP(g_trac_vddr,ERR_MRK " "
                "Failed to deassert pca95x GPIO for Centaur HUID = 0x%08x "
                "and pin %d.",
                TARGETING::get_huid(centaur),gpioInfo.vddrPin);
            break;
        }

        TRACFCOMP(g_trac_vddr,INFO_MRK " "
            "Disabled VDDR for Centaur HUID = 0x%08x (deasserted pca95x GPIO "
            "pin %d).",
            TARGETING::get_huid(centaur),
            gpioInfo.vddrPin);

    } while(0);

    return l_err;
}

// External interfaces
errlHndl_t platform_enable_vddr()
{
    return for_each_vddr_domain_with_functional_memory(
        enableVddrViaGpioPinStrategy);
}

errlHndl_t platform_disable_vddr()
{
    return for_each_vddr_domain_with_functional_memory(
        disableVddrViaGpioPinStrategy);
}

errlHndl_t platform_adjust_vddr_post_dram_init()
{
    // Not supported on OpenPOWER
    return NULL;
}

