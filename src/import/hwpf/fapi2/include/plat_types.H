/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/plat_types.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
 * @file plat_types.H
 * @brief definitions for fapi2 platform types
 */

#ifndef __FAPI2_PLAT_TYPES__
#define __FAPI2_PLAT_TYPES__

namespace fapi2
{
///
/// @enum fapi::PlatformType
/// @brief Platform types a FAPI procedure might be compiled for
/// @note can be used for conditionally compiled code depending on platform
///       instead of using #ifdefs
///

enum PlatformType
{
    PLAT_EXAMPLE,    ///< FAPI2 example platform
    PLAT_CRONUS,     ///< Cronus
    PLAT_SBE,        ///< Self Boot Engine
    PLAT_HOSTBOOT,   ///< HostBoot
    PLAT_HWSV,       ///< FSP Hardware Server
    PLAT_QME,        ///< Quad Management Engine
};

}

#endif
