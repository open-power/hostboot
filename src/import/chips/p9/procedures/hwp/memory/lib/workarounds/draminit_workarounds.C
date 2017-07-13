/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/draminit_workarounds.C $ */
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
/// @file workarounds/draminit_workarounds.C
/// @brief Workarounds for the draminit code
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/dimm/rcd_load_ddr4.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>
#include <lib/workarounds/draminit_workarounds.H>

namespace mss
{

namespace workarounds
{

///
/// @brief Runs the DRAM reset workaround to fix training bugs
/// @param[in] i_target - the target on which to operate
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode rcw_reset_dram( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    // Note: we're always going to run this guy
    FAPI_INF("%s running the DRAM RCW DRAM reset workaround", mss::c_str(i_target));

    // Declares constexpr's
    constexpr uint64_t RESET_CW = 6;
    constexpr uint64_t RESET_DRAM = 0x02;
    constexpr uint64_t CLEAR_RESET = 0x03;
    // Using a delay of 2000 cycles to ensure we're holding everything for a long enough time
    // Note: this value is set using "engineering judgement" and was considered arbitrarily high enough
    constexpr uint64_t DELAY = 2000;
    // Function space 0
    constexpr uint8_t FS0 = 0;

    // Reset, then clear the data
    static const std::vector< cw_data > l_rcd_reset_data =
    {
        { FS0, RESET_CW, RESET_DRAM,  DELAY },
        { FS0, RESET_CW, CLEAR_RESET, DELAY },
    };

    // Load the data into the CCS array
    return control_word_engine<RCW_4BIT>(i_target, l_rcd_reset_data, io_inst);
}

} // namespace workarounds

} // namespace mss
