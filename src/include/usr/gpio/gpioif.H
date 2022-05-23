/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/gpio/gpioif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
#ifndef __GPIOIF_H
#define __GPIOIF_H

#include <errl/errlentry.H>

namespace GPIO
{
/**
 * @brief Devices to be accessed
 */
enum gpioDevice_t
{
                                // Corresponds to attribute ...
    PCA95X_GPIO            = 0, // GPIO_INFO
    PCA9551_GPIO_PHYS_PRES = 1, // GPIO_INFO_PHYS_PRES
    INVALID_GPIO,
};


/* The following enums and interfaces are specific to PCA9551 GPIO Devices.
 * Documentation here: https://www.nxp.com/docs/en/data-sheet/PCA9551.pdf
 */

/**
 * @brief Specific to PCA9551: LED Bit Mask to match how their status is read
 *        back from LED "INPUT" register on PCA9551 Devices
 */
enum PCA9551_LEDS_t : uint8_t
{
    PCA9551_LED0            = 0x01,
    PCA9551_LED1            = 0x02,
    PCA9551_LED2            = 0x04,
    PCA9551_LED3            = 0x08,
    PCA9551_LED4            = 0x10,
    PCA9551_LED5            = 0x20,
    PCA9551_LED6            = 0x40,
    PCA9551_LED7            = 0x80,
};

/**
 * @brief Specific to PCA9551: Values used by the LED select registers
 *        to determine the source of the LED data.
 */
enum PCA9551_LED_Output_Settings_t : uint8_t
{
    PCA9551_OUTPUT_LOW            = 0x00, // LED on
    PCA9551_OUTPUT_HIGH_IMPEDANCE = 0x01, // LED off; default
    PCA9551_OUTPUT_PWM0           = 0x02, // Output blinks at PWM0 rate
    PCA9551_OUTPUT_PWM1           = 0x03, // Output blinks at PWM1 rate
};

/**
 * @brief Specific to PCA9551: Control register definition:
          sepcificies which register the operation will target
 */
enum PCA9551_Registers_t : uint8_t
{
    PCA9551_REGISTER_INPUT = 0x00, // INPUT (read only) input register
    PCA9551_REGISTER_PCS0  = 0x01, // PSC0 (r/w) frequency prescaler 0
    PCA9551_REGISTER_PWM0  = 0x02, // PWM0 (r/w) PWM register 0
    PCA9551_REGISTER_PCS1  = 0x03, // PSC1 (r/w) frequency prescaler 1
    PCA9551_REGISTER_PWM1  = 0x04, // PWM1 (r/w) PWM register 1
    PCA9551_REGISTER_LS0   = 0x05, // LS0  (r/w) LED0 to LED3 selector
    PCA9551_REGISTER_LS1   = 0x06, // LS1  (r/w) LED4 to LED7 selector
};

/**
 * @brief Specific to PCA9551: Helper constants to work with the bits in the
 *        PCA9551 registers
 */
enum PCA9551_Constants_t : uint8_t
{
    // Mask shifted to apply 2-bit settings to a specific LED in the output
    // settings register
    PCA9551_LED_SETTINGS_MASK = 0x03,

    // Amount to shift the LED value per LED when walking through the LEDs
    // in the INPUT register (related to PCA9551_LEDS_t above)
    PCA9551_LED_SHIFT_AMOUNT = 0x01,

    // Amount to shift the LED Settings MASK per LED when walking through the
    // LEDs in the output settings register (ie, 2 bits at a time)
    PCA9551_LED_SETTINGS_MASK_SHIFT_AMOUNT = 0x02,

    // LED settings shift: While the INPUT register can contain all 8 LED values
    // (since each value is represented by one bit), the SETTINGS registers
    // (PCA9551_REGISTER_LS0 and PCA9551_REGISTER_LS1) can only cover 4 LEDs
    // each since each setting requires 2 bits.
    // This constant takes LEDs 4 to 7 and makes them look like LEDs 0 to 3 by
    // shifting the left-most nibble of the LED byte to the right-most
    // nibble.
    PCA9551_LED_SETTINGS_SHIFT_BITS = 4,
};

/**
 * @brief Returns the PCA9551 Device's INPUT register which reflects the state
 *        of the device's LEDs (aka pins)
 *
 * @param[in] i_target - Target that contains ATTR_GPIO_INFO_PHYS_PRES attribute
 *                       to run the commands against
 *
 * @param[out] o_led_data - The INPUT register data from the device
 *
 * @return errlHndl_t nullptr on success; non-nullptr on error.
 */
errlHndl_t gpioPca9551GetLeds(TARGETING::Target * i_target,
                              uint8_t & o_led_data);

/**
 * @brief Sets the given LED (aka pin) of a PCA9551 Device to a certain setting
 *        and returns the INPUT register which reflects the state of device's
 *        LEDs (aka pins) after the setting has been run
 *
 * @param[in] i_target - Target that contains ATTR_GPIO_INFO_PHYS_PRES attribute
 *                       to run the commands against
 *
 * @param[in] i_led - The specific LED Target that contains ATTR_GPIO_INFO_PHYS_PRES attribute
 *                       to run the commands against
 *
 * @param[in] i_setting - the output setting to set the LED to
 *
 * @param[out] o_led_data - The INPUT register data from the device after the
 *                          'set' procedure has been run allowing the caller to
 *                          evaluate if the set actually went through
 *
 * @return errlHndl_t nullptr on success; non-nullptr on error.
 */

errlHndl_t gpioPca9551SetLed(TARGETING::Target * i_target,
                             const PCA9551_LEDS_t i_led,
                             const PCA9551_LED_Output_Settings_t i_setting,
                             uint8_t & o_led_data);


}; // GPIO NAMESPACE
#endif
