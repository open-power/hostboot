/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mc/gen_mss_port.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/// @file gen_mss_port.H
/// @brief Code to support ports
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP


#ifndef _GEN_MSS_PORT_H_
#define _GEN_MSS_PORT_H_

#include <fapi2.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mc/gen_mss_port_traits.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_traits.H>
#include <generic/memory/lib/ecc/galois.H>
#include <generic/memory/lib/utils/mcbist/gen_maint_cmds.H>
#include <generic/memory/lib/utils/conversions.H>


namespace mss
{
///
/// @brief Configure clock stabilization time field
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the OCMB target to operate on
/// @param[in] i_has_rcd flag to signify existence of RCD on DIMM
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode configure_tstab(const fapi2::Target<T>& i_target, const bool i_has_rcd)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_reg_data = 0;

    // Clock stabilization time with an RCD on the DIMM is 5us which is converted to ns
    constexpr uint64_t TSTAB_VAL_IN_NS = 5 * CONVERT_NS_IN_A_US;
    uint64_t l_tstab_cfg_val = 0;

    // Convert the ns to cycles.
    l_tstab_cfg_val = mss::ns_to_cycles(i_target, TSTAB_VAL_IN_NS, l_rc);
    FAPI_TRY(l_rc, "%s ns_to_cycles failed", mss::c_str(i_target));

    // Reading from the register into l_reg_data
    FAPI_TRY(mss::getScom(i_target, TT::SRQ_MBAREFAQ, l_reg_data));


    // tSTAB should be 5us if RCD exists, otherwise default of 0
    l_reg_data.insertFromRight<TT::SRQ_MBAREFAQ_CFG_TSTAB,
                               TT::SRQ_MBAREFAQ_CFG_TSTAB_LEN>
                               (i_has_rcd ? l_tstab_cfg_val : 0);

    // Writing the updated value to the regitster
    FAPI_TRY(mss::putScom(i_target, TT::SRQ_MBAREFAQ, l_reg_data));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Reads the farb0q register
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[out] o_data data read from the register
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Disable Port Fail after recurring RCD errors.
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode read_farb0q( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    // This register sits on different chiplets depending upon the MC type in question
    // In some MC's, it sits on the port level
    // In other MC's, it sits on the chip level
    // As such, a helper function is used to grab the appropriate target type to run this scom
    FAPI_TRY( mss::getScom(TT::get_farb_target(i_target), TT::FARB0Q_REG, o_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes the farb0q register
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[in] i_data data read from the register
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Disable Port Fail after recurring RCD errors.
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode write_farb0q( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    // This register sits on different chiplets depending upon the MC type in question
    // In some MC's, it sits on the port level
    // In other MC's, it sits on the chip level
    // As such, a helper function is used to grab the appropriate target type to run this scom
    FAPI_TRY( mss::putScom(TT::get_farb_target(i_target), TT::FARB0Q_REG, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads the farb6q register
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[out] o_data data read from the register
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Disable Port Fail after recurring RCD errors.
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode read_farb6q( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    // This register sits on different chiplets depending upon the MC type in question
    // In some MC's, it sits on the port level
    // In other MC's, it sits on the chip level
    // As such, a helper function is used to grab the appropriate target type to run this scom
    FAPI_TRY( mss::getScom(TT::get_farb_target(i_target), TT::FARB6Q_REG, o_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes the farb6q register
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[in] i_data data read from the register
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Disable Port Fail after recurring RCD errors.
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode write_farb6q( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    // This register sits on different chiplets depending upon the MC type in question
    // In some MC's, it sits on the port level
    // In other MC's, it sits on the chip level
    // As such, a helper function is used to grab the appropriate target type to run this scom
    FAPI_TRY( mss::putScom(TT::get_farb_target(i_target), TT::FARB6Q_REG, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the bandwidth window data
/// @tparam MC the memory controller type
/// @tparam TT the class traits for the port
/// @param[in] i_data data read from the register
/// @param[out] o_bw_window
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Disable Port Fail after recurring RCD errors.
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
void get_bw_window( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_bw_window )
{
    o_bw_window = 0;
    i_data.extractToRight<TT::BW_WINDOW_SIZE, TT::BW_WINDOW_SIZE_LEN>(o_bw_window);
}

///
/// @brief Gets the bandwidth snapshot
/// @tparam MC the memory controller type
/// @tparam TT the class traits for the port
/// @param[in] i_data data read from the register
/// @param[out] o_bw_snapshot
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Disable Port Fail after recurring RCD errors.
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
void get_bw_snapshot( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_bw_snapshot )
{
    o_bw_snapshot = 0;
    i_data.extractToRight<TT::BW_SNAPSHOT, TT::BW_SNAPSHOT_LEN>(o_bw_snapshot);
}


///
/// @brief ATTR_MSS_MVPD_FWMS getter declare
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the fapi2::Target<fapi2::TargetType>
/// @param[out] uint32_t* memory to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Mark store records from MPVD Lx keyword
///
template< mss::mc_type MC, fapi2::TargetType T>
fapi2::ReturnCode mvpd_fwms(const fapi2::Target< T>& i_target, uint32_t (&o_array)[MARK_STORE_COUNT]);

///
/// @brief Enable power management
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode enable_power_management( const fapi2::Target<T>& i_target )
{
    //Enable Power management based off of mrw_power_control_requested
    FAPI_INF("%s Enable Power min max domains", mss::c_str(i_target));

    bool is_pwr_cntrl = true;
    fapi2::buffer<uint64_t> l_data;
    uint8_t  l_pwr_cntrl = 0;

    // Get the value from attribute and write it to scom register
    FAPI_TRY(fapi2::getScom(i_target, TT::MBARPC0Q_REG, l_data));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_pwr_cntrl));

    is_pwr_cntrl = ((l_pwr_cntrl == fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_POWER_DOWN)
                    || (l_pwr_cntrl == fapi2::ENUM_ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED_PD_AND_STR)
                    || (l_pwr_cntrl == fapi2::ENUM_ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP));

    l_data.writeBit< TT::CFG_MIN_MAX_DOMAINS_ENABLE>(is_pwr_cntrl);
    FAPI_TRY( fapi2::putScom(i_target, TT::MBARPC0Q_REG, l_data) );


fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Set the IML init complete bit
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[in] i_state the state
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode change_iml_complete( const fapi2::Target<T>& i_target, states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Change the IML init complete bit to high for %s %s", (i_state == HIGH ? "high" : "low"),
             mss::c_str(i_target));
    FAPI_TRY( mss::getScom(i_target, TT::PMU8Q_REG, l_data) );
    l_data.writeBit<TT::CFG_INIT_COMPLETE>(i_state);
    FAPI_TRY( mss::putScom(i_target, TT::PMU8Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read the read ECC Control register
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[out] o_buffer the buffer to write the register data into
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode read_recr_register( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_buffer )
{
    FAPI_TRY( mss::getScom(i_target, TT::ECC_REG, o_buffer) );

    FAPI_INF( "Read ECC Control register is 0x%016lx for %s", uint64_t(o_buffer), mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write to RECR register
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[in] i_buffer the buffer that holds the register data to write
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode write_recr_register( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_buffer )
{
    FAPI_INF( "Change Read ECC Control register to 0x%016lx for %s",  i_buffer, mss::c_str(i_target) );

    FAPI_TRY( mss::putScom(i_target, TT::ECC_REG, i_buffer) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the tce correction enable value from RECR
/// @tparam MC the memory controller type
/// @tparam TT the class traits for the port
/// @param[in] i_data the data buffer containing the RECR register
/// @param[out] o_value TCE_CORRECTION_ENABLE value (on or off)
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
void get_tce_correction( const fapi2::buffer<uint64_t>& i_data, mss::states& o_value )
{
    o_value = i_data.template getBit<TT::RECR_TCE_CORRECTION>() ? mss::states::ON : mss::states::OFF;

    FAPI_INF( "TCE_CORRECTION_ENABLE: %lu", o_value );
}

///
/// @brief Sets tce correction enable in buffer
/// @tparam MC the memory controller type
/// @tparam TT the class traits for the port
/// @param[in,out] io_data the target data buffer
/// @param[in] i_value TCE_CORRECTION_ENABLE value (on or off) to set
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
void set_tce_correction( fapi2::buffer<uint64_t>& io_data, const mss::states i_value )
{
    FAPI_INF( "Set TCE_CORRECTION_ENABLE to %lu", i_value);

    io_data.template writeBit<TT::RECR_TCE_CORRECTION>(i_value);
}

///
/// @brief Setup TCE correction
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode setup_tce_correction (const fapi2::Target<T>& i_target)
{
    fapi2::buffer<uint64_t> l_data;
    bool l_erepairs_disabled = false;
    mss::states l_state = mss::OFF;

    // Check for manufacturing disable dram repair flag to disable TCE correction
    FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_DISABLE_MEMORY_eREPAIR, l_erepairs_disabled));

    FAPI_TRY(mss::read_recr_register<MC>(i_target, l_data ), "%s: Failed read_recr_register",
             mss::c_str(i_target));
    l_state = l_erepairs_disabled ? mss::OFF : mss::ON;
    mss::set_tce_correction<MC>(l_data, l_state);

    FAPI_TRY( mss::write_recr_register<MC>(i_target, l_data), "%s: Failed write_recr_register",
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Change the state of the port_fail_disable bit
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[in] i_state the state
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Disable Port Fail after recurring RCD errors.
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode change_port_fail_disable( const fapi2::Target<T>& i_target, states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Change port fail disable to %s %s", (i_state == HIGH ? "high" : "low"), mss::c_str(i_target));
    FAPI_TRY( mss::getScom(i_target, TT::FARB0Q_REG, l_data) );
    l_data.writeBit<TT::PORT_FAIL_DISABLE>(i_state);
    FAPI_TRY( mss::putScom(i_target, TT::FARB0Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Change the state of the dfi init start bit
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[in] i_state the state
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode change_dfi_init_start( const fapi2::Target<T>& i_target, states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Change rcd recovery disable to %s %s", (i_state == HIGH ? "high" : "low"), mss::c_str(i_target));
    FAPI_TRY( mss::getScom(i_target, TT::FARB0Q_REG, l_data) );
    l_data.writeBit<TT::DFI_INIT_START>(i_state);
    FAPI_TRY( mss::putScom(i_target, TT::FARB0Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Change the state of the addr_mux_sel bit
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[in] i_state the state
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode change_addr_mux_sel( const fapi2::Target<T>& i_target, states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Change addr_mux_sel to %s %s", (i_state == HIGH ? "high" : "low"), mss::c_str(i_target));
    FAPI_TRY( mss::getScom(i_target, TT::FARB5Q_REG, l_data) );
    l_data.writeBit<TT::CFG_CCS_ADDR_MUX_SEL>(i_state);
    FAPI_TRY( mss::putScom(i_target, TT::FARB5Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable the MC Periodic calibration functionality
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode enable_periodic_cal( const fapi2::Target<T>& i_target )
{

    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(i_target, TT::FARB9Q_REG, l_data) );

    // Set up noise window triggered calibration
    l_data.setBit<TT::CFG_CTRLUPD_AFTER_ERR>();

    // Set up periodic calibration
    l_data.setBit<TT::CFG_MC_PER_CAL_ENABLE>();
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_INTERVAL_TB,
                           TT::CFG_MC_PER_CAL_INTERVAL_TB_LEN>(TT::CAL_INTERVAL_TB_16384_CYCLES);
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_INTERVAL,
                           TT::CFG_MC_PER_CAL_INTERVAL_LEN>(TT::CAL_INTERVAL_VALUE);
    l_data.clearBit<TT::CFG_MC_PER_CAL_FIXED_RUN_LENGTH_EN>();
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_RUN_LENGTH,
                           TT::CFG_MC_PER_CAL_RUN_LENGTH_LEN>(0);
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_CTRLUPD_MIN,
                           TT::CFG_MC_PER_CAL_CTRLUPD_MIN_LEN>(TT::CAL_CTRLUPD_MIN_VALUE);

    FAPI_TRY( mss::putScom(i_target, TT::FARB9Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Change the state of the force_str bit
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[in] i_state the state
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode change_force_str( const fapi2::Target<T>& i_target, const states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Change force_str to %s %s", (i_state == HIGH ? "high" : "low"), mss::c_str(i_target));
    FAPI_TRY( mss::getScom(i_target, TT::STR0Q_REG, l_data) );
    l_data.writeBit<TT::CFG_FORCE_STR>(i_state);
    FAPI_TRY( mss::putScom(i_target, TT::STR0Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Change the state of the MC Refresh enable bit
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[in] i_state the state
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode change_refresh_enable( const fapi2::Target<T>& i_target, states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Change refresh enable to %s %s", (i_state == HIGH ? "high" : "low"), mss::c_str(i_target));
    FAPI_TRY( mss::getScom(i_target, TT::REFRESH_REG, l_data) );
    l_data.writeBit<TT::REFRESH_ENABLE>(i_state);
    FAPI_TRY( mss::putScom(i_target, TT::REFRESH_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Enable periodic zq cal
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode enable_zq_cal( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Enable periodic zq cal for %s", mss::c_str(i_target));
    FAPI_TRY( mss::getScom(i_target, TT::FARB9Q_REG, l_data) );
    l_data.writeBit<TT::CFG_ZQ_PER_CAL_ENABLE>(mss::HIGH);
    FAPI_TRY( mss::putScom(i_target, TT::FARB9Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set up memory controller specific settings for ECC registers (at the end of draminit_mc)
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @param[in,out] io_data contents of RECR register
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode ecc_reg_settings_draminit_mc( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint64_t>& io_data )
{
    fapi2::buffer<uint64_t> l_ctcr_data;

    // mc_type specific settings for RECR
    io_data.setBit<TT::RECR_ENABLE_MPE_NOISE_WINDOW>();
    io_data.setBit<TT::RECR_RETRY_UNMARKED_ERRORS>();
    io_data.clearBit<TT::RECR_CFG_MAINT_USE_TIMERS>();

    // Set up CTCR timers to 20x4^3 (1280 clock cycles; typical read latency is 120ish, so this is about 10x)
    // This is a preliminary guess from the design team. Also enable UE lockout window
    // CTCR -> 51A8E00000000000
    FAPI_TRY( mss::getScom(i_target, TT::CTCR_REG, l_ctcr_data) );

    l_ctcr_data.insertFromRight<TT::CTCR_MPE_TIMER, TT::CTCR_MPE_TIMER_LEN>(TT::MPE_TIMER_SETTING);
    l_ctcr_data.insertFromRight<TT::CTCR_MPE_TIMEBASE, TT::CTCR_MPE_TIMEBASE_LEN>(TT::MPE_TIMEBASE_SETTING);
    l_ctcr_data.insertFromRight<TT::CTCR_UE_TIMER, TT::CTCR_UE_TIMER_LEN>(TT::UE_TIMER_SETTING);
    l_ctcr_data.insertFromRight<TT::CTCR_UE_TIMEBASE, TT::CTCR_UE_TIMEBASE_LEN>(TT::UE_TIMEBASE_SETTING);
    l_ctcr_data.setBit<TT::CTCR_UE_LOCKOUT_ENABLE>();

    FAPI_TRY( mss::putScom(i_target, TT::CTCR_REG, l_ctcr_data) );

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Enable Read ECC checking
/// @tparam MC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the port
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode enable_read_ecc( const fapi2::Target<T>& i_target )
{
    constexpr uint8_t RECR_MBSECCQ_DATA_INVERSION_NO_INVERSION = 0b00;
    constexpr uint8_t RECR_MBSECCQ_DATA_INVERSION_INVERT_DATA_TOGGLE_CHECKS = 0b11;
    fapi2::buffer<uint64_t> l_data;

    uint8_t l_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_sim) );

    FAPI_DBG("Enable Read ECC %s", mss::c_str(i_target));

    FAPI_TRY( mss::getScom(i_target, TT::ECC_REG, l_data) );
    l_data.clearBit<TT::ECC_CHECK_DISABLE>();
    l_data.clearBit<TT::ECC_CORRECT_DISABLE>();

    // VBU tests assume good ECC and we don't have good ECC (since we're not writing everything)
    // so we can't run with address checking. Disable address checking in sim.
    l_data.writeBit<TT::ECC_USE_ADDR_HASH>(l_sim ? mss::states::LOW : mss::states::HIGH);

    // The preferred operating mode is 11 (INVERT_DATA_TOGGLE_CHECKS) which stores data complemented
    // (because most bits are '0', and the dram bus pulls up, so transmitting 1s is least power) but
    // still flips the inversion of check bits to aid RAS. Per Brad Michael 12/15
    // Leave un-inverted for sim. This allows the DIMM loader to write 0's and effect good ECC
    l_data.insertFromRight<TT::RECR_MBSECCQ_DATA_INVERSION, TT::RECR_MBSECCQ_DATA_INVERSION_LEN>(l_sim ?
            RECR_MBSECCQ_DATA_INVERSION_NO_INVERSION :
            RECR_MBSECCQ_DATA_INVERSION_INVERT_DATA_TOGGLE_CHECKS);

    FAPI_TRY( ecc_reg_settings_draminit_mc<MC>(i_target, l_data) );

    // bits: 60 MBSTRQ_CFG_MAINT_RCE_WITH_CE
    // cfg_maint_rce_with_ce - not implemented. Need to investigate if needed for nimbus.

    FAPI_TRY( mss::putScom(i_target, TT::ECC_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the write reorder queue bit
/// @tparam MC the memory controller type
/// @tparam T, the mc
/// @tparam TT, the class traits for the port
/// @param[in] i_target the target to effect
/// @param[in] i_state to set the bit too
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
inline fapi2::ReturnCode configure_wrq(const fapi2::Target<T>& i_target,
                                       const mss::states i_state)
{
    // Loops through all port targets, hitting all the registers
    for( const auto& l_port : mss::find_targets<TT::PORT_TYPE>(i_target) )
    {
        fapi2::buffer<uint64_t> l_data;

        // Gets the reg
        FAPI_TRY(mss::getScom(l_port, TT::WRQ_REG, l_data), "%s failed to getScom from WRQ0Q", mss::c_str(l_port));

        // Sets the bit
        l_data.writeBit<TT::WRQ_FIFO_MODE>(i_state == mss::states::ON);

        // Sets the regs
        FAPI_TRY(mss::putScom(l_port, TT::WRQ_REG, l_data), "%s failed to putScom to WRQ0Q", mss::c_str(l_port));
    }

    // In case we don't have any port's
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the read reorder queue bit
/// @tparam MC the memory controller type
/// @tparam T, the mc
/// @tparam TT, the class traits for the port
/// @param[in] i_target the target to effect
/// @param[in] i_state to set the bit too
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
inline fapi2::ReturnCode configure_rrq(const fapi2::Target<T>& i_target, const mss::states i_state)
{
    // Loops through all port targets, hitting all the registers
    for( const auto& l_port : mss::find_targets<TT::PORT_TYPE>(i_target) )
    {
        fapi2::buffer<uint64_t> l_data;

        // Gets the reg
        // This register sits on different chiplets depending upon the MC type in question
        // In some MC's, it sits on the port level
        // In other MC's, it sits on the chip level
        // As such, a helper function is used to grab the appropriate target type to run this scom
        FAPI_TRY(mss::getScom(TT::get_rrq_target(l_port), TT::RRQ_REG, l_data), "%s failed to getScom from RRQ0Q",
                 mss::c_str(l_port));

        // Sets the bit
        l_data.writeBit<TT::RRQ_FIFO_MODE>(i_state == mss::states::ON);

        // Sets the regs
        FAPI_TRY(mss::putScom(TT::get_rrq_target(l_port), TT::RRQ_REG, l_data), "%s failed to putScom to RRQ0Q",
                 mss::c_str(l_port));
    }

    // In case we don't have any port's
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Resets the write/read reorder queue values - needs to be called after MCBIST execution
/// @tparam MC the memory controller type
/// @tparam T, the mc
/// @tparam TT, the class traits for the port
/// @param[in] i_target the target to effect
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
inline fapi2::ReturnCode reset_reorder_queue_settings(const fapi2::Target<T>& i_target)
{
    uint8_t l_reorder_queue = 0;
    FAPI_TRY(mss::attr::get_reorder_queue_setting(i_target, l_reorder_queue));

    // Changes the reorder queue settings
    {
        // Two settings are FIFO and REORDER.  FIFO is a 1 in the registers, while reorder is a 0 state
        const mss::states l_state = ((l_reorder_queue == fapi2::ENUM_ATTR_MEM_REORDER_QUEUE_SETTING_FIFO) ?
                                     mss::states::ON : mss::states::OFF);
        FAPI_TRY(mss::template configure_rrq<MC>(i_target, l_state), "%s failed to reset read reorder queue settings",
                 mss::c_str(i_target));
        FAPI_TRY(mss::template configure_wrq<MC>(i_target, l_state), "%s failed to reset write reorder queue settings",
                 mss::c_str(i_target));
    }


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Convert a bitmap from the BAD_DQ_BITMAP attribute to a vector of bad DQ indexes
/// @param[in] i_bad_bits an 8-bit bitmap of bad bits
/// @param[in] i_nibble which nibble of the bitmap to convert
/// @return std::vector of DQ bits marked as bad in the bitmap
///
inline std::vector<uint64_t> bad_bit_helper(const uint8_t i_bad_bits, const size_t i_nibble)
{
    std::vector<uint64_t> l_output;
    fapi2::buffer<uint8_t> l_bit_buffer(i_bad_bits);

    const size_t l_start = (i_nibble == 0) ? 0 : mss::conversions::BITS_PER_NIBBLE;

    for (size_t l_offset = 0; l_offset < mss::conversions::BITS_PER_NIBBLE; ++l_offset)
    {
        const size_t l_position_tmp = l_start + l_offset;

        if (l_bit_buffer.getBit(l_position_tmp))
        {
            l_output.push_back(l_position_tmp);
        }
    }

    return l_output;
}

}// ns mss

#endif
