/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/vpd_access_defs.H $             */
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
///
/// @file vpd_access_defs.H
///
/// @brief VPD access definitions
///

#ifndef __VPDACCESSDEFS_H_
#define __VPDACCESSDEFS_H_

#include <stdint.h>

namespace fapi2
{

// @brief VPD accesss enums
enum MemVpdData
{
    MR, //! Memory phase rotator
    MT, //! Memory Termination
    MP, //! Memory Power related info
};

typedef MemVpdData MemVpdData_t;

/// @brief  Class representing required VPDInfo to be used in vpd collection.
/// @tparam T, the type of target this class is used with.
///
///  NOTE: to be defined by implementor
//
template<fapi2::TargetType T>
class VPDInfo;

}
#endif
