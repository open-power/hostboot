/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/gpio/gpio_pca9551.C $                                 */
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
 * @file gpio_pca9551.C
 *
 * @brief Implements Interfaces Specific to the PCA9551 GPIO Devices
 *
 * @note  Reference: https://www.nxp.com/docs/en/data-sheet/PCA9551.pdf
 *
 */


#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/commontargeting.H>
#include <devicefw/driverif.H>
#include "gpiodd.H"
#include <gpio/gpioddreasoncodes.H>
#include <gpio/gpioif.H>
#include <config.h>

extern trace_desc_t* g_trac_gpio;

// Set to TRACFCOMP to enable unit trace
#define TRACUCOMP(args...)  TRACDCOMP(args)

using namespace DeviceFW;
using namespace TARGETING;

namespace GPIO
{


void gpioPca9551SetReigsterHelper(const PCA9551_LEDS_t i_led,
                                  const PCA9551_LED_Output_Settings_t i_setting,
                                  uint8_t & io_led_register_data)
{
   uint8_t l_led = i_led;
   uint8_t l_mask = PCA9551_LED_SETTINGS_MASK; // 2-bit mask shifted over to
                                               // match i_led's value
   uint8_t l_setting = i_setting; // will be shifted with 2-bit mask before it is applied

   // Adjust values for LEDs 4 to 7 to match calculations below for LEDs 0 to 3
   if (i_led > PCA9551_LED3)
   {
       l_led = l_led >> PCA9551_LED_SETTINGS_SHIFT_BITS;
   }
   TRACUCOMP(g_trac_gpio, "gpioPca9551SetReigsterHelper: "
             "i_led=0x%.2X, l_led=0x%.2X, l_mask=0x%.2X, "
             "l_setting=0x%.2X, data0=0x%.2X",
             i_led, l_led, l_mask, l_setting,io_led_register_data);

   // Move 2-bit mask and setting to cover the correct values
   // Setting register is uint8_t broken into 4 2-bit setting sections:
   // [LED3 Setting][LED2 Setting][LED1 Setting][LED0 Setting]
   // --OR--
   // [LED7 Setting][LED6 Setting][LED5 Setting][LED4 Setting]

   const uint8_t match = 0x01; // shift values until l_led == match

   // l_led must be >= match or following loop won't work
   assert(l_led >= match, "gpioPca9551SetReigsterHelper: l_led %d is < match %d", l_led, match);

   TRACUCOMP(g_trac_gpio,"gpioPca9551SetReigsterHelper: Pre-loop: "
             "l_led=0x%.2X, match=0x%.2X",
             l_led, match);
   while ( match != l_led )
   {
       l_led = l_led >> PCA9551_LED_SHIFT_AMOUNT;
       l_mask = l_mask << PCA9551_LED_SETTINGS_MASK_SHIFT_AMOUNT;
       l_setting = l_setting << PCA9551_LED_SETTINGS_MASK_SHIFT_AMOUNT;
       TRACUCOMP(g_trac_gpio,"gpioPca9551SetReigsterHelper: inside-loop: "
                 "l_led=0x%.2X, l_mask=0x%.2X, l_setting=0x%.2X",
                 l_led, l_mask, l_setting);
   }
   TRACUCOMP(g_trac_gpio, "gpioPca9551SetReigsterHelper: Post-loop: "
             "l_mask=0x%.2X, l_setting=0x%.2X",
             l_mask, l_setting);

   // Apply Mask to Register data and then OR-in setting bits
   io_led_register_data = (io_led_register_data & ~l_mask) | l_setting;
   TRACUCOMP(g_trac_gpio, "gpioPca9551SetReigsterHelper: "
             "io_led_register_data=0x%.2X",
             io_led_register_data);

   return;
}


errlHndl_t gpioPca9551GetLeds(TARGETING::Target * i_target,
                              uint8_t & o_led_data)
{
    errlHndl_t err = nullptr;

    TRACUCOMP(g_trac_gpio, ENTER_MRK"gpioPca9551GetLeds: "
              "i_target 0x%.08X",
              get_huid(i_target));

    do
    {

    // Read PCA9551 INPUT Register to get Pin (aka LED) Values
    uint8_t data = 0;
    size_t data_len = sizeof(data);
    const size_t exp_data_len = data_len;
    uint64_t device_type = PCA9551_GPIO_PHYS_PRES;
    uint64_t register_addr = PCA9551_REGISTER_INPUT;

    err = DeviceFW::deviceOp
            ( DeviceFW::READ,
              i_target,
              &data,
              data_len,
              DEVICE_GPIO_ADDRESS(device_type, register_addr)
             );
    if(err)
    {
        TRACFCOMP(g_trac_gpio, ERR_MRK"gpioPca9551GetLeds: "
                  "Reading INPUT register failed");
        break;
    }
    else
    {
        o_led_data = data;
        TRACUCOMP(g_trac_gpio, INFO_MRK"gpioPca9551GetLeds: "
                  "register_addr=0x%X, o_led_data=0x%.2X",
                  register_addr, o_led_data);
    }
    assert(data_len==exp_data_len, "gpioPca9551GetLeds: expected %d size of data but got %d", exp_data_len, data_len);

    } while (0);

    if (err)
    {
        err->collectTrace( GPIO_COMP_NAME );
    }

    return err;
}

errlHndl_t gpioPca9551SetLed(TARGETING::Target * i_target,
                             const PCA9551_LEDS_t i_led,
                             const PCA9551_LED_Output_Settings_t i_setting,
                             uint8_t & o_led_data)
{
    errlHndl_t err = nullptr;

    TRACUCOMP(g_trac_gpio, ENTER_MRK"gpioPca9551SetLed: "
              "i_target 0x%.8X, i_led=0x%.2X, i_setting=0x%.2X",
              get_huid(i_target), i_led, i_setting);

    do
    {
    uint64_t deviceType = PCA9551_GPIO_PHYS_PRES;

    // First Read Select Register - either LS0 (LEDs 0-3) or LS1 (LEDs 4-7)
    uint64_t register_addr = PCA9551_REGISTER_LS0;
    if (i_led > PCA9551_LED3)
    {
       register_addr = PCA9551_REGISTER_LS1;
    }
    uint8_t data = 0;
    size_t data_len = sizeof(data);
    const size_t exp_data_len = data_len;

    err = DeviceFW::deviceOp
            ( DeviceFW::READ,
              i_target,
              &data,
              data_len,
              DEVICE_GPIO_ADDRESS(deviceType, register_addr)
             );
    if(err)
    {
        TRACFCOMP(g_trac_gpio, ERR_MRK"gpioPca9551SetLed: "
                  "Reading LED Select register 0x%X failed",
                  register_addr);
        break;
    }
    else
    {
        TRACUCOMP(g_trac_gpio, INFO_MRK"gpioPca9551SetLed: "
                  "LED Select register_addr=0x%X, data=0x%.2X",
                  register_addr, data);
    }
    assert(data_len==exp_data_len, "gpioPca9551SetLed: expected %d size of data but got %d", exp_data_len, data_len);


    // Create Setting Register to Write Back:
    uint8_t write_data = data;
    gpioPca9551SetReigsterHelper(i_led, i_setting, write_data);

    // Write LED Select Register
    data = write_data;

    err = DeviceFW::deviceOp
            ( DeviceFW::WRITE,
              i_target,
              &data,
              data_len,
              DEVICE_GPIO_ADDRESS(deviceType, register_addr)
             );
    if(err)
    {
        TRACFCOMP(g_trac_gpio, ERR_MRK"gpioPca9551SetLed: "
                  "Writing LED Select register 0x%X failed",
                  register_addr);
        break;
    }
    else
    {
        TRACUCOMP(g_trac_gpio, INFO_MRK"gpioPca9551SetLed: "
                  "Writing LED Select register_addr=0x%X, data=0x%.2X",
                  register_addr, data);
    }
    assert(data_len==exp_data_len, "gpioPca9551SetLed: expected %d size of data but got %d", exp_data_len, data_len);


    // Read Back LED Select Register
    data = 0;
    err = DeviceFW::deviceOp
            ( DeviceFW::READ,
              i_target,
              &data,
              data_len,
              DEVICE_GPIO_ADDRESS(deviceType, register_addr)
             );
    if(err)
    {
        TRACFCOMP(g_trac_gpio, ERR_MRK"gpioPca9551SetLed: "
                  "Reading LED Select register 0x%X failed",
                  register_addr);
        break;
    }
    else
    {
        TRACUCOMP(g_trac_gpio, INFO_MRK"gpioPca9551SetLed: "
                  "LED Select register_addr=0x%X, data=0x%.2X",
                  register_addr, data);
    }
    assert(data_len==exp_data_len, "gpioPca9551SetLed: expected %d size of data but got %d", exp_data_len, data_len);

    // Compare data written and data read back
    if (data != write_data)
    {
        TRACFCOMP(g_trac_gpio, ERR_MRK"gpioPca9551SetLed: "
                  "Reading Back LED Select register 0x%X had unexpected data=",
                  "0x%.2X. Expected 0x%.2X",
                  register_addr, data, write_data);

        /*@
         * @errortype
         * @reasoncode       GPIO_PCA9551_DATA_MISMATCH
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         GPIO_PCA9551_SET_LED
         * @userdata1[0:31]  HUID of Master Processor Target
         * @userdata1[32:63] Input LED to Set
         * @userdata2[0:31]  Expected Data (aka data written)
         * @userdata2[32:63] Data Read Back
         * @devdesc          Setting of LED value did not appear to work
         * @custdesc         A problem occurred during the IPL
         *                   of the system.
         */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      GPIO_PCA9551_SET_LED,
                                      GPIO_PCA9551_DATA_MISMATCH,
                                      TWO_UINT32_TO_UINT64(
                                        get_huid(i_target),
                                        i_led),
                                      TWO_UINT32_TO_UINT64(
                                        write_data,
                                        data),
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        break;
    }

    // Read PCA9551 INPUT Register to get Pin (aka LED) Values
    data = 0;
    data_len = sizeof(data);
    register_addr = PCA9551_REGISTER_INPUT;

    err = DeviceFW::deviceOp
            ( DeviceFW::READ,
              i_target,
              &data,
              data_len,
              DEVICE_GPIO_ADDRESS(deviceType, register_addr)
             );
    if(err)
    {
        TRACFCOMP(g_trac_gpio, ERR_MRK"gpioPca9551SetLed: "
                  "Reading INPUT register failed");
        break;
    }
    else
    {
        o_led_data = data;
        TRACUCOMP(g_trac_gpio, INFO_MRK"gpioPca9551SetLed: "
                  "INPUT register_addr=0x%X, o_led_data=0x%.2X",
                  register_addr, o_led_data);
    }
    assert(data_len==exp_data_len, "gpioPca9551SetLed: expected %d size of data but got %d", exp_data_len, data_len);

    } while (0);

    if (err)
    {
        err->collectTrace( GPIO_COMP_NAME );
    }

    return err;

}

}; // end namespace GPIO

