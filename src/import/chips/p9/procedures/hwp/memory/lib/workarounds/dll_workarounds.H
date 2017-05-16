/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/dll_workarounds.H $ */
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

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_WORKAROUNDS_DLL_H_
#define _MSS_WORKAROUNDS_DLL_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <map>

namespace mss
{

///
/// @brief class to keep trace of DLL info for workaround
///
struct dll_map
{
    // Same values for DP16 and ADR enumerations
    // Used DP16 enumerations...just because
    static constexpr uint64_t REGS_RXDLL_DAC_COARSE = MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_1_01_REGS_RXDLL_DAC_COARSE;
    static constexpr uint64_t REGS_RXDLL_DAC_COARSE_LEN =
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_1_01_REGS_RXDLL_DAC_COARSE_LEN;
    static constexpr uint64_t DLL_CNTL_CAL_ERROR = MCA_DDRPHY_DP16_DLL_CNTL0_P0_1_01_CAL_ERROR;
    static constexpr uint64_t DLL_CNTL_CAL_ERROR_FINE = MCA_DDRPHY_DP16_DLL_CNTL0_P0_1_01_CAL_ERROR_FINE;
    static constexpr uint64_t DLL_CAL_GOOD = MCA_DDRPHY_DP16_DLL_CNTL0_P0_1_01_CAL_GOOD;

    // Value for UPPER and LOWER DAC are the same
    // Used LOWER DAC enumeration...just because
    static constexpr uint64_t REGS_RXDLL_VREG = MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_0_01_REGS_RXDLL_VREG_LOWER;
    static constexpr uint64_t REGS_RXDLL_VREG_LEN = MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_0_01_REGS_RXDLL_VREG_LOWER_LEN;

    ///
    /// @brief Checks for DLL error status
    /// @param[in] i_cntrl_reg
    /// @param[in] i_vreg_coarse_same_dll
    /// @param[in] i_vreg_coarse_neighbor_dll
    /// @param[in] i_dll_dac_upper
    /// @param[in] i_dll_dac_lower
    ///
    constexpr dll_map(const uint64_t i_cntrl_reg,
                      const uint64_t i_vreg_coarse_same_dll,
                      const uint64_t i_vreg_coarse_neighbor_dll,
                      const uint64_t i_dll_dac_lower,
                      const uint64_t i_dll_dac_upper)
        : iv_cntrl(i_cntrl_reg),
          iv_vreg_coarse_same_dll(i_vreg_coarse_same_dll),
          iv_vreg_coarse_neighbor_dll(i_vreg_coarse_neighbor_dll),
          iv_dll_dac_lower(i_dll_dac_lower),
          iv_dll_dac_upper(i_dll_dac_upper)
    {}

    const uint64_t iv_cntrl; // DP16 or ADR CNTRL register
    const uint64_t iv_vreg_coarse_same_dll; // VREG_COARSE register for same DLL as iv_cntrl_reg
    const uint64_t iv_vreg_coarse_neighbor_dll; // VREG_COARSE register for DLL neighbor for this workaround
    const uint64_t iv_dll_dac_lower; // DLL DAC Upper register
    const uint64_t iv_dll_dac_upper; // DLL DAC Lower register
};

namespace workarounds
{
namespace dll
{

///
/// @brief Clears the DLL firs
/// @param[in] i_target the MCA target
/// @return returns true unless if scom errors
///
fapi2::ReturnCode clear_dll_fir( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target  );

///
/// @brief Checks if CAL_ERROR and CAL_ERROR_FINE bits are set
/// @param[in] i_dll_cntrl_data DLL CNTRL data
/// @return bool
///
bool did_cal_fail( const fapi2::buffer<uint64_t>& i_dll_cntrl_data );

///
/// @brief Logs DLL error mappings from failed DLLs
/// @param[in] i_target the fapi2 target
/// @param[in] i_map dll map of DLLs to log errors from
/// @param[in,out] io_failed_dll_cntrl failed list of DLL CNTRL regs
/// @param[in,out] io_failed_dll_vreg_coarse map of VREG COARSE from failed DLLs
/// @param[in,out] io_failed_dll_dac map of DLL DAC from failed DLLs
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode log_fails(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                            const mss::dll_map& i_map,
                            std::vector< uint64_t >& io_failed_dll_cntrl,
                            std::map< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> >& io_failed_dll_vreg_coarse,
                            std::map< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> >& io_failed_dll_dac);

///
/// @brief Checks for DLL error status
/// @param[in] i_target the fapi2 target
/// @param[in] i_failed_dll_cntrl vector of failed DLLs
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode check_status(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const std::vector< uint64_t >& i_failed_dll_cntrl);

///
/// @brief Change VREG_COARSE for failed DLLs
/// @param[in] i_target the fapi2 target
/// @param[in] i_failed_dll_map failed DLL VREG COARSE map
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_vreg_coarse(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                     const std::map< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> >& i_failed_dll_map);

///
/// @brief Change DLL DAC for failled DLLs map
/// @param[in] i_target the fapi2 target
/// @param[in] i_failed_dll_dac_map failed DLL DAC map
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_dac(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                             const std::map< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> >& i_failed_dll_dac_map);

///
/// @brief DLL Workaround algorithm to fax bad voltage settings
/// @tparam T fapi2 Target Type - derived
/// @param[in] i_target the fapi2 target
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T  >
fapi2::ReturnCode fix_bad_voltage_settings(const fapi2::Target<T>& i_target);

} // close namespace dll
} // close namespace workarounds
} // close namespace mss

#endif
