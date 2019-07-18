/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/pba.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file pba.C
/// @brief Code to support per-buffer addressability (PBA)
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#include <lib/shared/nimbus_defaults.H>
#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/utils/nimbus_find.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/dimm/ddr4/data_buffer_ddr4.H>
#include <lib/phy/phy_cntrl.H>
#include <lib/dimm/ddr4/pba.H>
// Including PDA as some of the helper functions are the same for PBA
#include <lib/dimm/ddr4/pda.H>
#include <lib/workarounds/ccs_workarounds.H>

#include <map>

namespace mss
{

namespace pc
{

///
/// @brief Enables or disables PBA in the PHY
/// @param[in] i_target a fapi2::Target of type MCA
/// @param[in] i_state ON or OFF for configuring PBA mode
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode configure_phy_pba_mode( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const mss::states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(mss::pc::read_config0(i_target, l_data));
    mss::pc::set_pba_enable(l_data, i_state);
    FAPI_TRY(mss::pc::write_config0(i_target, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns pc


namespace ddr4
{

namespace pba
{

///
/// @brief Configures PBA timings
/// @param[in] i_target a fapi2::Target of type MCA
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode configure_timings( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // Fun fact, we're hitting all of the bits in this reg, no need for RMW
    fapi2::buffer<uint64_t> l_data;

    // So we want to:
    // 1) Turn off the PDA on MRS bit
    // 2) Have a 0 delay between the MRS being sent and starting the 0/1 latching
    // 3) Hold the delay for as long as possible (safer and easier than figuring out how long to hold the values)
    mss::wc::set_pda_mode(l_data, mss::states::OFF);
    mss::ddr4::pda::configure_timings(l_data);

    // Set that reg
    FAPI_TRY(mss::wc::write_config3(i_target, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enters into and configures PBA mode
/// @param[in] i_target a fapi2::Target of type DIMM
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode enter( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target )
{
    ccs::program l_program;

    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // Turns on PBA mode in the buffers
    FAPI_TRY( mss::ddr4::set_pba_mode( i_target, mss::states::ON, l_program.iv_instructions ));

    // Now, hold the CKE's high, so we don't power down the RCD and re-power it back up
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    FAPI_TRY( ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target),
                           l_program,
                           l_mca),
              "unable to execute CCS for PBA enter %s",
              mss::c_str(i_target) );

    // Now sets up all of the PDA regs now that we are in PDA mode
    FAPI_TRY(mss::ddr4::pba::configure_timings(l_mca));
    FAPI_TRY(mss::pc::configure_phy_pba_mode(l_mca, mss::states::ON));
    FAPI_TRY(mss::ddr4::pda::blast_dram_config(l_mca, mss::states::OFF_N));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Exits out of and disables PDA mode
/// @param[in] i_target a fapi2::Target of type DIMM
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target )
{
    ccs::program l_program;

    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // We need everyone to exit PDA mode, so all of them are all ON
    FAPI_TRY( mss::ddr4::pda::blast_dram_config(l_mca, mss::states::ON_N) );

    // Turns off PBA mode in the buffers
    FAPI_TRY( mss::ddr4::set_pba_mode( i_target, mss::states::OFF, l_program.iv_instructions ));

    // Now, hold the CKE's high, so we don't power down the RCD and re power it back up
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    FAPI_TRY( ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target),
                           l_program,
                           l_mca),
              "unable to execute CCS for PBA exit %s",
              mss::c_str(i_target) );

    // Disables PBA mode
    FAPI_TRY(mss::pc::configure_phy_pba_mode(l_mca, mss::states::OFF));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Performs all PBA commands
/// @param[in] i_target DIMM on which to operate
/// @param[in] i_buffer the LRDIMM buffer on which to operate
/// @param[in] i_bcws the control words to issue to the buffer
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode execute_commands( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint64_t i_buffer,
                                    const std::vector<cw_info>& i_bcws )
{
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    uint8_t l_sim = 0;
    FAPI_TRY(mss::is_simulation(l_sim));

    // If the commands passed in are empty, simply exit
    FAPI_ASSERT((!i_bcws.empty()),
                fapi2::MSS_EMPTY_PDA_VECTOR().
                set_PROCEDURE(mss::ffdc_function_codes::PBA_EXECUTE_VECTOR),
                "%s PBA commands vector is empty, exiting", mss::c_str(i_target));

    // Buffers are 8 bits wide, so use the DRAM helper and pass in 8 bits
    // Enable the buffer
    FAPI_TRY(mss::ddr4::pda::change_dram_bit_helper<fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8>( l_mca, i_buffer,
             mss::states::ON_N));

    // Issue PBA commands
    {
        ccs::program l_program;

        // Inserts the DES command to ensure we keep our CKE high
        l_program.iv_instructions.push_back(mss::ccs::des_command());

        // Makes a copy of the vector, so we can do the function space swaps correctly
        auto l_bcws = i_bcws;
        FAPI_TRY(insert_function_space_select(l_bcws));

        FAPI_TRY(control_word_engine(i_target,
                                     l_bcws,
                                     l_sim,
                                     l_program.iv_instructions));

        // Now, hold the CKE's high, so we don't power down the RCD and re power it back up
        mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

        FAPI_TRY( ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target),
                               l_program,
                               l_mca),
                  "unable to execute CCS for BCW buffer %lu %s",
                  i_buffer, mss::c_str(i_target) );
    }

    // Buffers are 8 bits wide, so use the DRAM helper and pass in 8 bits
    // Disable the buffer
    FAPI_TRY(mss::ddr4::pda::change_dram_bit_helper<fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8>( l_mca, i_buffer,
             mss::states::OFF_N));


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Performs all PBA commands
/// @param[in] i_commands the PDA commands to issue and DRAM
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode execute_commands( const commands& i_commands )
{
    // If the commands passed in are empty, simply exit
    FAPI_ASSERT((!i_commands.empty()),
                fapi2::MSS_EMPTY_PDA_VECTOR().
                set_PROCEDURE(mss::ffdc_function_codes::PBA_EXECUTE_CONTAINER),
                "PBA commands map is empty, exiting");

    // Loop until all commands have been issued
    for(const auto& l_commands : i_commands.get())
    {
        const auto& l_dimm = l_commands.first;
        const auto& l_pba_commands = l_commands.second;

        // First, enter into PBA mode
        FAPI_TRY(enter(l_dimm));

        // Now loops through all of the MRS and DRAM
        for(const auto& l_command : l_pba_commands)
        {
            const auto& l_buffer = l_command.first;
            const auto& l_bcws = l_command.second;
            FAPI_TRY(execute_commands( l_dimm,
                                       l_buffer,
                                       l_bcws ));
        }

        // Finally, exit out of PBA
        FAPI_TRY(exit(l_dimm));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns pba

} // ns ddr4

} // ns mss
