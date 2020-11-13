/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/xscom/piberror_common.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef __PIBERROR_COMMON_H
#define __PIBERROR_COMMON_H

/** @file piberror_common.H
  * @brief Provides PIB data structures and interfaces common between HBBL and HB
  */

namespace PIB
{

    /**
     * @brief Enumerations for the each PIB error possbility
     */
    enum PibError
    {
        PIB_NO_ERROR          = 0,//0b000,
        PIB_RESOURCE_OCCUPIED = 1,//0b001,
        PIB_CHIPLET_OFFLINE   = 2,//0b010,
        PIB_PARTIAL_GOOD      = 3,//0b011,
        PIB_INVALID_ADDRESS   = 4,//0b100,
        PIB_CLOCK_ERROR       = 5,//0b101,
        PIB_PARITY_ERROR      = 6,//0b110,
        PIB_TIMEOUT           = 7,//0b111,
    };
} // namespace PIB

#endif
