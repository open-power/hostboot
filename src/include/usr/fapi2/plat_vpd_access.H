/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_vpd_access.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file plat_vpd_access.H
///
/// @brief Platform vpd-access definitions
///

#ifndef _FAPI2_PLAT_VPDACCESS_H_
#define _FAPI2_PLAT_VPDACCESS_H_

#include <fapi2_vpd_access.H>
#include <vpd/memd_vpdenums.H>

namespace fapi2
{

/// @brief Return a blob of memory VPD data associated with the input target
///
/// Platform specific getVPD implmentation for MCS target type
///
/// @param[in] i_target, a valid fapi2 MCS target
/// @param[in] io_vpd_info, fapi2::VPDInfo class that specifies which piece
///            of data to return. Types MR and MT supported.
/// @param[out] o_blob, the blob of raw data from the vpd
/// @return FAPI2_RC_SUCCESS if there's no problem
/// @note passing nullptr for o_blob will return the size of the keyword

fapi2::ReturnCode platGetVPD(
                        const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                        VPDInfo<fapi2::TARGET_TYPE_MCS>& io_vpd_info,
                        uint8_t* o_blob);

/**
 * @brief Search through the PNOR::MEMD section to find the copy with
 *        a matching VM keyword compared to the EEPROM's VM.
 *
 * @param[in] i_eepromVM - The EEPROM's copy of the VM keyword
 * @param[in] i_header   - The header from PNOR::MEMD
 * @param[in] i_target   - A valid fapi2 MCS target
 * @param[in] i_vm_size  - Size of the VM keyword
 *
 * @return boolean - true if a matching MEMD was found, false if not
 */
bool find_memd_in_pnor(uint8_t* i_eepromVM, MemdHeader_t i_header,
                       TARGETING::Target * i_target, size_t i_vm_size);

};
#endif // _FAPI2_PLAT_VPDACCESS_H_
