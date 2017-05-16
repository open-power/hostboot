/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/dll_workarounds.C $ */
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

#include <map>
#include <fapi2.H>
#include <lib/workarounds/dll_workarounds.H>
#include <lib/fir/check.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/phy/dp16.H>
#include <lib/fir/fir.H>
#include <lib/shared/mss_const.H>
#include <lib/utils/conversions.H>

namespace mss
{

static const std::vector< mss::dll_map > DLL_REGS =
{
    // ADR DLL 0
    {
        MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0,
        MCA_DDRPHY_ADR_DLL_VREG_COARSE_P0_ADR32S0,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_2,
        MCA_DDRPHY_ADR_DLL_DAC_LOWER_P0_ADR32S0,
        MCA_DDRPHY_ADR_DLL_DAC_UPPER_P0_ADR32S0
    },

    // DP0 DLL0
    {
        MCA_DDRPHY_DP16_DLL_CNTL0_P0_0,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_0,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_0,
        MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_0,
        MCA_DDRPHY_DP16_DLL_DAC_UPPER0_P0_0,
    },

    // DP1 DLL0
    {
        MCA_DDRPHY_DP16_DLL_CNTL0_P0_1,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_1,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_1,
        MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_1,
        MCA_DDRPHY_DP16_DLL_DAC_UPPER0_P0_1,
    },

    // DP2 DLL0
    {
        MCA_DDRPHY_DP16_DLL_CNTL0_P0_2,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_2,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_2,
        MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_2,
        MCA_DDRPHY_DP16_DLL_DAC_UPPER0_P0_2,
    },

    // DP3 DLL0
    {
        MCA_DDRPHY_DP16_DLL_CNTL0_P0_3,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_3,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_3,
        MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_3,
        MCA_DDRPHY_DP16_DLL_DAC_UPPER0_P0_3,
    },

    // DP4 DLL0
    {
        MCA_DDRPHY_DP16_DLL_CNTL0_P0_4,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_4,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_3,
        MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_4,
        MCA_DDRPHY_DP16_DLL_DAC_UPPER0_P0_4,
    },

    // DP0 DLL1
    {
        MCA_DDRPHY_DP16_DLL_CNTL1_P0_0,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_0,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_0,
        MCA_DDRPHY_DP16_DLL_DAC_LOWER1_P0_0,
        MCA_DDRPHY_DP16_DLL_DAC_UPPER1_P0_0,
    },

    // DP1 DLL1
    {
        MCA_DDRPHY_DP16_DLL_CNTL1_P0_1,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_1,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_1,
        MCA_DDRPHY_DP16_DLL_DAC_LOWER1_P0_1,
        MCA_DDRPHY_DP16_DLL_DAC_UPPER1_P0_1,
    },

    // DP2 DLL1
    {
        MCA_DDRPHY_DP16_DLL_CNTL1_P0_2,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_2,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_2,
        MCA_DDRPHY_DP16_DLL_DAC_LOWER1_P0_2,
        MCA_DDRPHY_DP16_DLL_DAC_UPPER1_P0_2,
    },

    // DP3 DLL1
    {
        MCA_DDRPHY_DP16_DLL_CNTL1_P0_3,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_3,
        MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_3,
        MCA_DDRPHY_DP16_DLL_DAC_LOWER1_P0_3,
        MCA_DDRPHY_DP16_DLL_DAC_UPPER1_P0_3,
    },
};

namespace workarounds
{
namespace dll
{

///
/// @brief Clears the DLL firs
/// @param[in] i_target the MCA target
/// @return FAPI2_RC_SUCCESS if the scoms don't fail
/// @note Need to clear the DLL firs when we notice a DLL fail for workarounds
///
fapi2::ReturnCode clear_dll_fir( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target  )
{
    fapi2::buffer<uint64_t> l_phyfir_data;

    fir::reg<MCA_IOM_PHY0_DDRPHY_FIR_REG> l_mca_fir_reg(i_target, fapi2::current_err);
    FAPI_TRY(fapi2::current_err, "%s unable to create fir::reg for 0x%016llx", mss::c_str(i_target),
             MCA_IOM_PHY0_DDRPHY_FIR_REG);

    FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_2>()); // bit 56
    FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_4>()); // bit 58

    FAPI_TRY( mss::getScom(i_target, MCA_IOM_PHY0_DDRPHY_FIR_REG, l_phyfir_data),
              "Failed getScom() operation on %s reg 0x%016llx",
              mss::c_str(i_target), MCA_IOM_PHY0_DDRPHY_FIR_REG);

    FAPI_INF("%s PHY FIR register is now 0x%016llx", mss::c_str(i_target), l_phyfir_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if CAL_ERROR and CAL_ERROR_FINE bits are set
/// @param[in] i_dll_cntrl_data DLL CNTRL data
/// @return true if DLL cal failed, false otherwiae
///
bool did_cal_fail( const fapi2::buffer<uint64_t>& i_dll_cntrl_data )
{
    FAPI_DBG("DLL_CNTL data 0x%016llx, CAL_ERROR %d, CAL_ERROR_FINE %d",
             i_dll_cntrl_data,
             i_dll_cntrl_data.getBit<mss::dll_map::DLL_CNTL_CAL_ERROR>(),
             i_dll_cntrl_data.getBit<mss::dll_map::DLL_CNTL_CAL_ERROR_FINE>());

    return i_dll_cntrl_data.getBit<mss::dll_map::DLL_CNTL_CAL_ERROR>() ||
           i_dll_cntrl_data.getBit<mss::dll_map::DLL_CNTL_CAL_ERROR_FINE>();
}

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
                            std::map< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> >& io_failed_dll_dac)
{
    fapi2::buffer<uint64_t> l_dll_cntrl_data;
    FAPI_TRY( mss::getScom(i_target, i_map.iv_cntrl, l_dll_cntrl_data),
              "Failed getScom() operation on %s reg 0x%016llx",
              mss::c_str(i_target), i_map.iv_cntrl);

    FAPI_DBG("%s Read DLL_CNTRL reg 0x%016llx, with data 0x%016llx",
             mss::c_str(i_target), i_map.iv_cntrl, l_dll_cntrl_data);

    if( did_cal_fail(l_dll_cntrl_data) )
    {
        fapi2::buffer<uint64_t> l_dll_dac_data;
        uint64_t l_neighbor_dac_coarse = 0;

        // Read DAC coarse from neighboring DLL
        FAPI_TRY( mss::getScom(i_target, i_map.iv_vreg_coarse_neighbor_dll, l_dll_dac_data),
                  "Failed getScom() operation on %s reg 0x%016llx",
                  mss::c_str(i_target), i_map.iv_vreg_coarse_neighbor_dll );

        FAPI_DBG( "%s Read neighboring DLL VREG COARSE reg 0x%016llx with data 0x%016llx",
                  mss::c_str(i_target), i_map.iv_vreg_coarse_neighbor_dll, l_dll_dac_data );

        // Pair VREG coarse from failing DLL w/data from the DAC coarse from the neighboring DLL
        l_dll_dac_data.extractToRight< dll_map::REGS_RXDLL_DAC_COARSE, dll_map::REGS_RXDLL_DAC_COARSE_LEN >
        (l_neighbor_dac_coarse);

        FAPI_DBG( "%s Saving failing DLL VREG COARSE reg 0x%016llx, value extracted 0x%llx",
                  mss::c_str(i_target), i_map.iv_vreg_coarse_same_dll, l_neighbor_dac_coarse);

        io_failed_dll_vreg_coarse.emplace( std::make_pair(i_map.iv_vreg_coarse_same_dll, l_neighbor_dac_coarse) );

        // Create a list DAC Lower and Upper pairs for failing DLLs
        FAPI_DBG( "%s Saving off pair of failling DLL regs for DAC LOWER 0x%016llx, DAC UPPER 0x%016llx",
                  mss::c_str(i_target), i_map.iv_dll_dac_lower, i_map.iv_dll_dac_upper );

        io_failed_dll_dac.emplace( std::make_pair(i_map.iv_dll_dac_lower, i_map.iv_dll_dac_upper) );

        // Store a list of all failing DLL CNTRL registers
        FAPI_INF( "%s Saving off failed DLL_CNTRL 0x%016llx",
                  mss::c_str(i_target), i_map.iv_cntrl );

        io_failed_dll_cntrl.push_back(i_map.iv_cntrl);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks for DLL error status
/// @param[in] i_target the fapi2 target
/// @param[in] i_failed_dll_cntrl vector of failed DLLs
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode check_status(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const std::vector< uint64_t >& i_failed_dll_cntrl)
{
    for( const auto& reg : i_failed_dll_cntrl )
    {
        fapi2::buffer<uint64_t> l_dll_cntrl_data;

        FAPI_TRY( mss::getScom(i_target, reg, l_dll_cntrl_data),
                  "Failed getScom() operation on %s reg 0x%016llx",
                  mss::c_str(i_target), reg );

        FAPI_DBG("Checking status on %s, DLL CNTRL reg 0x%016llx", mss::c_str(i_target), reg);

        FAPI_ASSERT( did_cal_fail(l_dll_cntrl_data) == false,
                     fapi2::MSS_DLL_FAILED_TO_CALIBRATE()
                     .set_MCA_IN_ERROR(i_target),
                     "%s DLL failed to calibrate",
                     mss::c_str(i_target) )
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Change VREG_COARSE for failed DLLs
/// @param[in] i_target the fapi2 target
/// @param[in] i_failed_dll_map failed DLL VREG COARSE map
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_vreg_coarse(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                     const std::map< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> >& i_failed_dll_map)
{
    for( const auto& map : i_failed_dll_map)
    {
        // Little renaming to help clarify map fields
        const auto FAILING_COARSE_REG = map.first;
        const auto NEIGHBOR_DATA = map.second;

        fapi2::buffer<uint64_t> l_data;

        // Read DAC coarse from failed DLL
        FAPI_TRY( mss::getScom(i_target, FAILING_COARSE_REG, l_data),
                  "Failed getScom() operation on %s reg 0x%016llx",
                  mss::c_str(i_target), FAILING_COARSE_REG );


        FAPI_DBG("%s Read DLL_VREG_COARSE reg 0x%016llx, data 0x%016llx",
                 mss::c_str(i_target), FAILING_COARSE_REG, l_data);

        l_data.insertFromRight< dll_map::REGS_RXDLL_DAC_COARSE,
                                dll_map::REGS_RXDLL_DAC_COARSE_LEN>(NEIGHBOR_DATA);

        FAPI_INF("%s Writing to DLL_VREG_COARSE reg 0x%016llx, data 0x%016llx, value 0x%llx",
                 mss::c_str(i_target), FAILING_COARSE_REG, l_data, NEIGHBOR_DATA);

        // Write DAC coarse from failed DLL with DAC coarse from neighboring DLL
        FAPI_TRY( mss::putScom(i_target, FAILING_COARSE_REG, l_data),
                  "Failed putScom() operation on %s reg 0x%016llx",
                  mss::c_str(i_target), FAILING_COARSE_REG );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to set DAC_COARSE reg
/// @param[in] i_target the fapi2 target
/// @param[in] i_failed_dll_dac failed DLL VREG COARSE
/// @param[in] i_value the value to set
/// @return FAPI2_RC_SUCCESS iff ok
///
static fapi2::ReturnCode dll_dac_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                        const fapi2::buffer<uint64_t>& i_failed_dll_dac,
                                        const uint64_t i_value)
{
    constexpr uint64_t SOURCE_START = dll_map::REGS_RXDLL_VREG;

    // Read DAC coarse from failed DLL
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(i_target, i_failed_dll_dac, l_data),
              "Failed getScom() operation on %s reg 0x%016llx",
              mss::c_str(i_target), i_failed_dll_dac );


    l_data.insert<dll_map::REGS_RXDLL_VREG,
                  dll_map::REGS_RXDLL_VREG_LEN,
                  SOURCE_START>(i_value);

    FAPI_INF("%s Writing to DAC_REG 0x%016llx, data 0x%016llx, value 0x%llx",
             mss::c_str(i_target), i_failed_dll_dac, l_data, i_value);

    // Write DAC coarse from failed DLL with DAC coarse from neighboring DLL
    FAPI_TRY( mss::putScom(i_target, i_failed_dll_dac, l_data),
              "Failed putScom() operation on %s reg 0x%016llx",
              mss::c_str(i_target), i_failed_dll_dac );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Change DLL DAC for failled DLLs map
/// @param[in] i_target the fapi2 target
/// @param[in] i_failed_dll_dac_map failed DLL DAC map
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_dac(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                             const std::map< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> >& i_failed_dll_dac_map)
{
    // Hard coded default values per Steve Wyatt for this workaround
    constexpr uint64_t DAC_LOWER_DEFAULT = 0x8000;
    constexpr uint64_t DAC_UPPER_DEFAULT = 0xFFE0;

    for( const auto& map : i_failed_dll_dac_map)
    {
        const auto DAC_LOWER_REG = map.first;
        const auto DAC_UPPER_REG = map.second;

        FAPI_TRY( dll_dac_helper(i_target, DAC_UPPER_REG, DAC_UPPER_DEFAULT) );
        FAPI_TRY( dll_dac_helper(i_target, DAC_LOWER_REG, DAC_LOWER_DEFAULT) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief DLL Workaround algorithm to fax bad voltage settings
/// @param[in] i_target the fapi2 target
/// @return FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode fix_bad_voltage_settings(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target)
{

    constexpr uint64_t SKIP_VREG = 0b10;

    for( const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target) )
    {
        std::vector<uint64_t> l_failing_dll_cntrl;
        std::map< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> > l_failing_dll_vreg_coarse;
        std::map< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> > l_failing_dll_dac;

        // Find failing DLL
        for( const auto& map : DLL_REGS )
        {
            FAPI_TRY( log_fails(p, map, l_failing_dll_cntrl, l_failing_dll_vreg_coarse, l_failing_dll_dac),
                      "%s Failed log_fails()", mss::c_str(p));
        }

        // Set DLL reset bit and skip VREG bit on failed DLLs
        {
            fapi2::buffer<uint64_t> l_read;

            for( const auto& d : l_failing_dll_cntrl )
            {
                // Need to clear out the error bits even though we set the reset bit
                FAPI_TRY(mss::getScom(p, d, l_read),
                         "Failed getScom() operation on %s reg 0x%016llx",
                         mss::c_str(i_target), d );
                FAPI_DBG("%s DLL CNTRL register is 0x%016llx", mss::c_str(p), l_read);
                mss::dp16::set_dll_cal_reset(l_read, mss::HIGH);
                mss::dp16::set_dll_cal_skip(l_read, SKIP_VREG);
                l_read.clearBit<mss::dll_map::DLL_CNTL_CAL_ERROR>();
                l_read.clearBit<mss::dll_map::DLL_CNTL_CAL_ERROR_FINE>();

                FAPI_DBG("%s new setting for DLL CNTRL register is 0x%016llx", mss::c_str(p), l_read);

                FAPI_TRY(mss::putScom(p, d, l_read),
                         "Failed putScom() operation on %s reg 0x%016llx",
                         mss::c_str(i_target), d );

            }

        }

        FAPI_TRY( clear_dll_fir(p) );

        // Write the VREG DAC value found in log_fails to the failing DLL VREG DAC
        FAPI_TRY( change_vreg_coarse(p, l_failing_dll_vreg_coarse),
                  "%s Failed change_vreg_coarse()", mss::c_str(p) );

        // Reset the upper and lower fine calibration bits back to defaults
        // since the earlier initial full calibration will have disturbed these.
        FAPI_TRY( change_dac(p, l_failing_dll_dac),
                  "Failed change_dac on %s", mss::c_str(p) );

        // Run DLL Calibration again on failed DLLs
        {
            fapi2::buffer<uint64_t> l_read;

            for( const auto& d : l_failing_dll_cntrl )
            {
                FAPI_TRY(mss::getScom(p, d, l_read),
                         "Failed getScom() operation on %s reg 0x%016llx",
                         mss::c_str(i_target), d );

                mss::dp16::set_dll_cal_reset(l_read, mss::LOW);

                FAPI_INF("%s DLL_CNTRL_REG 0x%016llx, data 0x%016llx",
                         mss::c_str(p), d, l_read);

                FAPI_TRY(mss::putScom(p, d, l_read),
                         "Failed putScom() operation on %s reg 0x%016llx",
                         mss::c_str(i_target), d );
            }
        }

        // The [delay value] gives software a reasonable amount of time to wait for an individual
        // DLL to calibrate starting from when it is taken out of reset. As some internal state machine transitions
        // between steps may not have been counted, software should add some margin.
        // 32,772 dphy_nclk cycles from Reset=0 to VREG Calibration to exhaust all values
        // 37,382 dphy_nclk cycles for full calibration to start and fail (“worst case”)
        // More or less a fake value for sim delay as this isn't executed in sim.
        fapi2::delay(mss::cycles_to_ns(i_target, mss::FULL_DLL_CAL_DELAY), DELAY_1US);

        FAPI_TRY( check_status(p, l_failing_dll_cntrl),
                  "%s check_status() failed", mss::c_str(p));

    }// mca

fapi_try_exit:
    return fapi2::current_err;
}


} // close namespace dll
} // close namespace workarounds
} // close namespace mss
