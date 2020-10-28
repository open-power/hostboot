/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devicefw/driverif_common.H $                  */
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
#ifndef __DRIVERIF_COMMON_H
#define __DRIVERIF_COMMON_H

/** @file driverif_common.H
  * @brief Provides data structures and interfaces common between HBBL and HB
  */

namespace DeviceFW
{
    /** @enum OperationType
     *  @brief Set of operations which can be registered for.
     */
    enum OperationType
    {
        READ = 0,
        WRITE,

        LAST_OP_TYPE,
        FIRST_OP_TYPE = READ

    };
}; // namespace DeviceFW
#endif
