/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/dimm/rcd_load_ddr4.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file rcd_load_ddr4.C
/// @brief Run and manage the DDR4 rcd loading
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include "../mss.H"
#include "rcd_load_ddr4.H"

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

///
/// @brief Perform the rcd_load_ddr4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode rcd_load_ddr4( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                 std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& i_inst)
{
    FAPI_INF("rcd_load_ddr4 %s", mss::c_str(i_target));

    // Per DDR4RCD02 table 104 - timing requirements
    static const uint64_t tMRD = 8;
    static const uint64_t tMRD_L = 16;

    // Per DDR4RCD02, tSTAB is 5us. We want this in cycles for the CCS.
    const uint64_t tSTAB = mss::us_to_cycles(i_target, 5);

    static std::vector< rcd_data > l_rcd_4bit_data =
    {
        {  0, eff_dimm_ddr4_rc00, tMRD  }, {  1, eff_dimm_ddr4_rc01, tMRD  }, {  2, eff_dimm_ddr4_rc02, tSTAB },
        {  3, eff_dimm_ddr4_rc03, tMRD_L}, {  4, eff_dimm_ddr4_rc04, tMRD_L}, {  5, eff_dimm_ddr4_rc05, tMRD_L},
        {  6, eff_dimm_ddr4_rc67, tMRD  }, {  8, eff_dimm_ddr4_rc08, tMRD  }, {  9, eff_dimm_ddr4_rc09, tMRD  },
        { 10, eff_dimm_ddr4_rc10, tSTAB }, { 11, eff_dimm_ddr4_rc11, tMRD  }, { 12, eff_dimm_ddr4_rc12, tMRD  },
        { 13, eff_dimm_ddr4_rc13, tMRD  }, { 14, eff_dimm_ddr4_rc14, tMRD  }, { 15, eff_dimm_ddr4_rc15, tMRD  },
    };

    static std::vector< rcd_data > l_rcd_8bit_data =
    {
        {  1, eff_dimm_ddr4_rc1x, tMRD  }, {  2, eff_dimm_ddr4_rc2x, tMRD  }, {  3, eff_dimm_ddr4_rc3x, tSTAB },
        {  4, eff_dimm_ddr4_rc4x, tMRD  }, {  5, eff_dimm_ddr4_rc5x, tMRD  }, {  6, eff_dimm_ddr4_rc6x, tMRD  },
        {  7, eff_dimm_ddr4_rc7x, tMRD  }, {  8, eff_dimm_ddr4_rc8x, tMRD  }, {  9, eff_dimm_ddr4_rc9x, tMRD  },
        { 10, eff_dimm_ddr4_rcax, tMRD  }, { 11, eff_dimm_ddr4_rcbx, tMRD_L}
    };

    fapi2::buffer<uint8_t> l_value;

    // A little 4bit RCD love ...
    for (auto d : l_rcd_4bit_data)
    {
        // Note: this isn't general - assumes Nimbus via MCBIST instruction here BRS
        ccs::instruction_t<TARGET_TYPE_MCBIST> l_inst = ccs::rcd_command<TARGET_TYPE_MCBIST>(i_target);
        FAPI_TRY( d.iv_func(i_target, l_value) );

        // If this control word would be set to 0, skip it - we can rely on the DIMM default
        if (l_value != 0)
        {
            // Data to be written into the 4-bit configuration registers need to be presented on DA0 .. DA3
            mss::swizzle<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_0_13, 4, 7>(l_value, l_inst.arr0);

            // Selection of each word of 4-bit control bits is presented on inputs DA4 through DA12
            mss::swizzle < MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_0_13 + 4, 4, 7 > (d.iv_rcd, l_inst.arr0);

            // For changes to the control word setting [...] the controller needs to wait tMRD[tSTAB] after
            // the last control word access, before further access to the DRAM can take place.
            l_inst.arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES, MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(d.iv_delay);

            FAPI_INF("RCD%02d value 0x%x (%d) 0x%016llx:0x%016llx %s", uint8_t(d.iv_rcd), l_value, d.iv_delay,
                     l_inst.arr0, l_inst.arr1, mss::c_str(i_target));
            i_inst.push_back(l_inst);
        }
    }

    // 8bit's turn
    for (auto d : l_rcd_8bit_data)
    {
        // Note: this isn't general - assumes Nimbus via MCBIST instruction here BRS
        ccs::instruction_t<TARGET_TYPE_MCBIST> l_inst = ccs::rcd_command<TARGET_TYPE_MCBIST>(i_target);
        FAPI_TRY( d.iv_func(i_target, l_value) );

        // If this control word would be set to 0, skip it - we can rely on the DIMM default
        if (l_value != 0)
        {
            // Data to be written into the 8-bit configuration registers need to be presented on DA0 .. DA7
            mss::swizzle<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_0_13, 8, 7>(l_value, l_inst.arr0);

            // Selection of each word of 8-bit control bits is presented on inputs DA8 through DA12.
            mss::swizzle < MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_0_13 + 8, 5, 7 > (d.iv_rcd, l_inst.arr0);

            // For changes to the control word setting [...] the controller needs to wait tMRD[tSTAB] after
            // the last control word access, before further access to the DRAM can take place.
            l_inst.arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES, MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(d.iv_delay);

            FAPI_INF("RCD%XX value 0x%x (%d) 0x%016llx:0x%016llx %s", uint8_t(d.iv_rcd), l_value, d.iv_delay,
                     l_inst.arr0, l_inst.arr1, mss::c_str(i_target));
            i_inst.push_back(l_inst);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace
