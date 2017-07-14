/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/fapi2_mbvpd_access.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file fapi2_mbvpd_access.H
///
/// @brief Defines the Memory Buffer VPD functions that platform must implement
///

#ifndef _FAPI2_MBVPDACCESS_H_
#define _FAPI2_MBVPDACCESS_H_

#include <stdint.h>
#include <return_code.H>
#include <target.H>
#include <fapi2_mbvpd_access_defs.H>
#include <plat_mbvpd_access.H>

namespace fapi2
{
///
/// @brief Get Memory Buffer VPD field.
///
/// A Memory Buffer VPD field is specified using a record and keyword enumerator
///
/// Suggested way to call this routine is to call it once with a NULL buffer
/// pointer to to retrieve the size of the record, then allocate the proper
/// size of the buffer and call again.
///
/// @param[in] i_record     Record enumerator
/// @param[in] i_keyword    Keyword enumerator
/// @param[in] i_target     Reference to processor chip target for the record
/// @param[in] i_pBuffer    Pointer to buffer where record will be stored. If
///                         NULL then the size of record will be stored in
///                         io_fieldSize
/// @param[in,out] io_fieldSize Size of i_pBuffer in bytes
///
/// @return fapi2::ReturnCode. FAPI_RC_SUCCESS, or failure value.
///
fapi2::ReturnCode getMBvpdField(const fapi2::MBvpdRecord i_record,
                                const fapi2::MBvpdKeyword i_keyword,
                                const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                                uint8_t* const i_pBuffer,
                                size_t& io_fieldSize);

///
/// @brief Set Memory Buffer VPD field.
///
/// A Memory Buffer VPD field is specified using a record and keyword enumerator
///
/// @param[in] i_record     Record enumerator
/// @param[in] i_keyword    Keyword enumerator
/// @param[in] i_target     Reference to processor chip target for the record
/// @param[in] i_pBuffer    Pointer to buffer where data to set is stored
/// @param[in] i_fieldSize  Size of i_pBuffer in bytes
///
/// @return fapi2::ReturnCode. FAPI_RC_SUCCESS, or failure value.
///
fapi2::ReturnCode setMBvpdField(const fapi2::MBvpdRecord i_record,
                                const fapi2::MBvpdKeyword i_keyword,
                                const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                                const uint8_t* const i_pBuffer,
                                const size_t i_fieldSize);
}

#endif
