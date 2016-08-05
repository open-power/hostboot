/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/fake_spd.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file fake_spd.H
/// @brief A tool to return fake (fixed) DIMM SPD for testing, development
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP
#ifndef DOXYGEN
#ifndef _MSS_FAKE_SPD_H_
    #define _MSS_FAKE_SPD_H_

    #include <fapi2.H>

    ///
    /// @brief Return a blob of SPD data from a DIMM
    /// @param[in] i_target, a DIMM target representing the DIMM in question
    /// @param[out] o_blob, the blob of data from the DIMM - raw
    /// @param[out] o_size, o_size, the size of the blob
    /// @return FAPI2_RC_SUCCESS if there's no problem
    /// @note passing nullptr for o_blob will return the size of the blob
    ///   size_t s;
    ///   FAPI_TRY( getSPD(d->target(), nullptr, s) );
    ///   {
    ///       uint8_t blob[s];
    ///       FAPI_TRY( getSPD(d->target(), blob, s) );
    ///    }
    ///
    fapi2::ReturnCode getSPD(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t* o_blob, size_t& s);

#endif
#endif
