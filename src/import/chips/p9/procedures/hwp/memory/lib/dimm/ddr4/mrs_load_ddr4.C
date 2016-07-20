/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs_load_ddr4.C $ */
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
/// @file mrs_load_ddr4.C
/// @brief Run and manage the DDR4 mrs loading
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

namespace ddr4
{

///
/// @brief Perform the mrs_load DDR4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrs_load( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                            std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    FAPI_INF("ddr4::mrs_load %s", mss::c_str(i_target));

    // Per DDR4MRS02 table 104 - timing requirements
    static const uint64_t tMRD = 8;

    static std::vector< mrs_data<TARGET_TYPE_MCBIST> > l_mrs_data =
    {
        // JEDEC ordering of MRS per DDR4 power on sequence
        {  3, mrs03, mrs03_decode, tMRD  },
        {  6, mrs06, mrs06_decode, tMRD  },
        {  5, mrs05, mrs05_decode, tMRD  },
        {  4, mrs04, mrs04_decode, tMRD  },
        {  2, mrs02, mrs02_decode, tMRD  },
        {  1, mrs01, mrs01_decode, tMRD  },
        {  0, mrs00, mrs00_decode, tMRD  },
    };

    std::vector< uint64_t > l_ranks;
    FAPI_TRY( mss::ranks(i_target, l_ranks) );

    for (const auto& d : l_mrs_data)
    {
        for (const auto& r : l_ranks)
        {
            // Note: this isn't general - assumes Nimbus via MCBIST instruction here BRS
            ccs::instruction_t<TARGET_TYPE_MCBIST> l_inst_a_side =
                ccs::mrs_command<TARGET_TYPE_MCBIST>(i_target, r, d.iv_mrs);
            ccs::instruction_t<TARGET_TYPE_MCBIST> l_inst_b_side;

            // Thou shalt send 2 MRS, one for the a-side and the other inverted for the b-side.
            // If we're on an odd-rank then we need to mirror
            // So configure the A-side, mirror if necessary and invert for the B-side
            FAPI_TRY( d.iv_func(i_target, l_inst_a_side, r) );

            FAPI_TRY( mss::address_mirror(i_target, r, l_inst_a_side) );
            l_inst_b_side = mss::address_invert(l_inst_a_side);

            // Not sure if we can get tricky here and only delay after the b-side MR. The question is whether the delay
            // is needed/assumed by the register or is purely a DRAM mandated delay. We know we can't go wrong having
            // both delays but if we can ever confirm that we only need one we can fix this. BRS
            l_inst_a_side.arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES,
                                               MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(d.iv_delay);
            l_inst_b_side.arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES,
                                               MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(d.iv_delay);

            // Dump out the 'decoded' MRS and trace the CCS instructions.
            FAPI_TRY( d.iv_dumper(l_inst_a_side, r) );

            FAPI_INF("MRS%02d (%d) 0x%016llx:0x%016llx %s:rank %d a-side", uint8_t(d.iv_mrs), d.iv_delay,
                     l_inst_a_side.arr0, l_inst_a_side.arr1, mss::c_str(i_target), r);
            FAPI_INF("MRS%02d (%d) 0x%016llx:0x%016llx %s:rank %d b-side", uint8_t(d.iv_mrs), d.iv_delay,
                     l_inst_b_side.arr0, l_inst_b_side.arr1, mss::c_str(i_target), r);

            // Add both to the CCS program
            io_inst.push_back(l_inst_a_side);
            io_inst.push_back(l_inst_b_side);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns ddr4
} // ns mss
