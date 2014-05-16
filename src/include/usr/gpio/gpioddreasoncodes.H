/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/gpio/gpioddreasoncodes.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __GPIODDREASONCODES_H
#define __GPIODDREASONCODES_H

#include <hbotcompid.H>
namespace GPIO
{
    /**
     * @enum gpioModuleid
     *
     * @brief Module Ids used in creating errorlogs.
     */
    enum gpioModuleId
    {
        GPIO_PERFORM_OP     = 0x00,
        GPIO_READ           = 0x01,
        GPIO_WRITE          = 0x02,
        GPIO_READATTRIBUTES = 0x03,
    };

    /**
     * @enum grioReasonCode
     */
    enum gpioReasonCode
    {
        GPIO_INVALID_DEVICE_TYPE        = GPIO_COMP_ID | 0x00,
        GPIO_ATTR_INFO_NOT_FOUND        = GPIO_COMP_ID | 0x01,
        GPIO_I2C_TARGET_NOT_FOUND       = GPIO_COMP_ID | 0x02,
        GPIO_INVALID_OP                 = GPIO_COMP_ID | 0x03,
    };

};
#endif
