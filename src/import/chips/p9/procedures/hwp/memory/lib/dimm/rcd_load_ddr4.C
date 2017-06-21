/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/rcd_load_ddr4.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file rcd_load_ddr4.C
/// @brief Run and manage the DDR4 rcd loading
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/dimm/rcd_load_ddr4.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>
#include <lib/workarounds/draminit_workarounds.H>

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
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode rcd_load_ddr4( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                 std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    FAPI_INF("rcd_load_ddr4 %s", mss::c_str(i_target));

    // Per DDR4RCD02, tSTAB is us. We want this in cycles for the CCS.
    const uint64_t tSTAB = mss::us_to_cycles(i_target, mss::tstab());
    constexpr uint8_t FS0 = 0; // Function space 0

    // RCD 4-bit data - integral represents rc#
    static const std::vector< cw_data > l_rcd_4bit_data =
    {
        { FS0, 0,  eff_dimm_ddr4_rc00,    mss::tmrd()    },
        { FS0, 1,  eff_dimm_ddr4_rc01,    mss::tmrd()    },
        { FS0, 2,  eff_dimm_ddr4_rc02,    tSTAB          },
        { FS0, 3,  eff_dimm_ddr4_rc03,    mss::tmrd_l()  },
        { FS0, 4,  eff_dimm_ddr4_rc04,    mss::tmrd_l()  },
        { FS0, 5,  eff_dimm_ddr4_rc05,    mss::tmrd_l()  },
        // Note: the tMRC1 timing as it is larger for saftey's sake
        // The concern is that if geardown mode is ever required in the future, we would need the longer timing
        { FS0, 6,  eff_dimm_ddr4_rc06_07, mss::tmrc1()   },
        { FS0, 8,  eff_dimm_ddr4_rc08,    mss::tmrd()    },
        { FS0, 9,  eff_dimm_ddr4_rc09,    mss::tmrd()    },
        { FS0, 10, eff_dimm_ddr4_rc0a,    tSTAB          },
        { FS0, 11, eff_dimm_ddr4_rc0b,    mss::tmrd_l()  },
        { FS0, 12, eff_dimm_ddr4_rc0c,    mss::tmrd()    },
        { FS0, 13, eff_dimm_ddr4_rc0d,    mss::tmrd_l2() },
        { FS0, 14, eff_dimm_ddr4_rc0e,    mss::tmrd()    },
        { FS0, 15, eff_dimm_ddr4_rc0f,    mss::tmrd_l2() },
    };

    // RCD 8-bit data - integral represents rc#
    static const std::vector< cw_data > l_rcd_8bit_data =
    {
        { FS0, 1,  eff_dimm_ddr4_rc_1x, mss::tmrd()   },
        { FS0, 2,  eff_dimm_ddr4_rc_2x, mss::tmrd()   },
        { FS0, 3,  eff_dimm_ddr4_rc_3x, tSTAB         },
        { FS0, 4,  eff_dimm_ddr4_rc_4x, mss::tmrd()   },
        { FS0, 5,  eff_dimm_ddr4_rc_5x, mss::tmrd()   },
        { FS0, 6,  eff_dimm_ddr4_rc_6x, mss::tmrd()   },
        { FS0, 7,  eff_dimm_ddr4_rc_7x, mss::tmrd_l() },
        { FS0, 8,  eff_dimm_ddr4_rc_8x, mss::tmrd()   },
        { FS0, 9,  eff_dimm_ddr4_rc_9x, mss::tmrd()   },
        { FS0, 10, eff_dimm_ddr4_rc_ax, mss::tmrd()   },
        { FS0, 11, eff_dimm_ddr4_rc_bx, mss::tmrd_l() },
    };

    // Load 4-bit data
    FAPI_TRY( control_word_engine<RCW_4BIT>(i_target, l_rcd_4bit_data, io_inst), "%s failed to load 4-bit control words",
              mss::c_str(i_target));

    // Load 8-bit data
    FAPI_TRY( control_word_engine<RCW_8BIT>(i_target, l_rcd_8bit_data, io_inst), "%s failed to load 8-bit control words",
              mss::c_str(i_target));

    // DD2 hardware has an issue with properly resetting the DRAM
    // The below workaround toggles RC06 again to ensure the DRAM is reset properly
    FAPI_TRY( mss::workarounds::rcw_reset_dram(i_target, io_inst), "%s failed to add reset workaround functionality",
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace
