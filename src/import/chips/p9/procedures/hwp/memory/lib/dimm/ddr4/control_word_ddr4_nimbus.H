/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/control_word_ddr4_nimbus.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file control_word_ddr4_nimbus.C
/// @brief Run and manage the DDR4 control words for the RCD and data buffers
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB


#ifndef _MSS_CONTROL_WORD_NIMBUS_H_
#define _MSS_CONTROL_WORD_NIMBUS_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/dimm/ddr4/control_word_ddr4.H>


///
/// @class cwTraits
/// @brief a collection of traits associated with the 8-bit buffer control words
///
template< >
class cwTraits< mss::BCW_8BIT >
{
    public:
        // From DDR4 DBO2 spec
        // Section 4.1 BCW Decoding
        // Table 25 - 8-bit BCW Decoding

        // Address bits denoted by A

        // Data settings are set by A[7:0]
        static constexpr uint64_t DATA_LEN = mss::CW8_DATA_LEN;

        // Control words are set by A[11:4]
        static constexpr uint64_t WORD_LEN = 4;

        // Magic swizzle start bit to make data left aligned for CCS inst.
        static constexpr uint64_t SWIZZLE_START = 7;

        // Address bit 12 must be 1 for accesses to Data Buffer (DB) Control Words.
        static constexpr uint64_t CW_ACCESS = 1;
};

///
/// @class cwTraits
/// @brief a collection of traits associated with the 4-bit buffer control words
///
template< >
class cwTraits< mss::BCW_4BIT >
{
    public:
        // From DDR4 DBO2 spec
        // Section 4.1 BCW Decoding
        // Table 24 - 4-bit BCW Decoding

        // Address bits denoted by A

        // Data settings are set by A[3:0]
        static constexpr uint64_t DATA_LEN = mss::CW4_DATA_LEN;

        // Control words are set by A[11:4]
        // Word length is technically 8
        // But we only need 4 to decode word.
        static constexpr uint64_t WORD_LEN = 4;

        // Magic swizzle start bit to make data left aligned for CCS inst.
        static constexpr uint64_t SWIZZLE_START = 7;

        // Address bit 12 must be 1 for accesses to Data Buffer (DB) Control Words.
        static constexpr uint64_t CW_ACCESS = 1;
};

///
/// @class cwTraits
/// @brief a collection of traits associated with the 8-bit register control words
///
template< >
class cwTraits< mss::RCW_8BIT >
{
    public:
        // From DDR4 RCDO2 spec:
        // Section 2.23.2 Control Word Decoding table
        // Table 27 -  Function Space 0 Control Word Decoding

        // Address bits denoted by A

        // Data settings are set by A[7:0]
        static constexpr uint64_t DATA_LEN = mss::CW8_DATA_LEN;

        // Control words are set by A[12:8]
        // Word length is technically 5
        // But we only need 4 to decode word.
        static constexpr uint64_t WORD_LEN = 4;

        // Magic swizzle start bit to make data left aligned for CCS inst.
        static constexpr uint64_t SWIZZLE_START = 7;

        // Address bit 12 must be 0 for accesses to Register Control Words.
        static constexpr uint64_t CW_ACCESS = 0;
};

///
/// @class cwTraits
/// @brief a collection of traits associated with the 4-bit register control words
///
template< >
class cwTraits< mss::RCW_4BIT >
{
    public:
        // From DDR4 RCDO2 spec:
        // Section 2.23.2 Control Word Decoding table
        // Table 27 -  Function Space 0 Control Word Decoding

        // Address bits denoted by A

        // Data settings are set by A[3:0]
        static constexpr uint64_t DATA_LEN = mss::CW4_DATA_LEN;

        // Control words are set by A[12:4]
        // Word length is technically 9
        // But we only need 4 to decode word.
        static constexpr uint64_t WORD_LEN = 4;

        // Magic swizzle start bit to make data left aligned for CCS inst.
        static constexpr uint64_t SWIZZLE_START = 7;

        // Address bit 12 must be 0 for accesses to Register Control Words.
        static constexpr uint64_t CW_ACCESS = 0;
};

#endif
