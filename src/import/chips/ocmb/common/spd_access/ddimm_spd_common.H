/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/spd_access/ddimm_spd_common.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file ddimm_spd_common.H
/// @brief Contains constants related to DDIMM SPD access
///        that are used by other accessor functions.
///
// *HWP Team: Memory
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot
#ifndef __DDIMM_SPD_COMMON__
#define __DDIMM_SPD_COMMON__

namespace DDIMM_SPD
{

// DDR level
constexpr uint16_t DDR_BYTE       = 2;
constexpr uint8_t MEM_DDR4  = 0x0C;
constexpr uint8_t MEM_DDR5  = 0x12;

// Module/Package Type
constexpr uint16_t DIMM_TYPE_BYTE = 3;
constexpr uint8_t MEM_DDIMM = 0x0A;

// Module/Package Size/Height
constexpr uint16_t DDR4_DIMM_SIZE_BYTE = 193;
constexpr uint16_t DDR5_DIMM_SIZE_BYTE = 230;
constexpr uint8_t MEM_4U    = 0x80;
constexpr uint8_t MEM_2U    = 0x20;

// Default value that means no device is present
constexpr uint8_t NO_DEVICE = 0x00;
};

#endif //__DDIMM_SPD_COMMON__
