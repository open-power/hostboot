/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/pba.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file pba.H
/// @brief Code to support per-buffer addressability (PBA)
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#ifndef _MSS_PBA_H_
#define _MSS_PBA_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/c_str.H>
#include <lib/utils/nimbus_find.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/dimm/ddr4/data_buffer_ddr4_nimbus.H>

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
        const mss::states i_state );

} // ns pc

namespace ddr4
{

namespace pba
{

///
/// @brief Configures PBA timings
/// @param[in] i_target a fapi2::Target of type MCA
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode configure_timings( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Enters into and configures PBA mode
/// @param[in] i_target a fapi2::Target of type DIMM
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode enter( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target );

///
/// @brief Exits out of and disables PBA mode
/// @param[in] i_target a fapi2::Target of type DIMM
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target );

///
/// @brief PBA commands container that also has some light compression
///
class commands
{
    public:
        static constexpr uint8_t BCW_DELAY = 255;
        using DIMM_TARGET = fapi2::Target<fapi2::TARGET_TYPE_DIMM>;
        using BCW_MAP = std::map<uint64_t, std::vector<cw_info>>;

        ///
        /// @brief Base constructor
        ///
        commands() = default;

        ///
        /// @brief Base destructor
        ///
        ~commands() = default;

        ///
        /// @brief Adds in a PBA command if need be
        /// @param[in] i_target the DIMM target
        /// @param[in] i_buffer the LRDIMM buffer on which to operate
        /// @param[in] i_cw_info
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode add_command( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const uint64_t i_buffer,
                                       const cw_info& i_cw_info )
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

            // Check for a valid rank
            FAPI_ASSERT(i_buffer < MAX_LRDIMM_BUFFERS,
                        fapi2::MSS_PBA_INVALID_BUFFER().
                        set_TARGET(i_target).
                        set_BUFFER(i_buffer).
                        set_MAX(MAX_LRDIMM_BUFFERS),
                        "%s buffer is out of range buffer:%lu max:%lu", mss::c_str(i_target), i_buffer, MAX_LRDIMM_BUFFERS);

            // Does the compression
            iv_commands[i_target][i_buffer].push_back(i_cw_info);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks whether the map is empty
        /// @return bool true if empty
        ///
        inline bool empty() const
        {
            return iv_commands.empty();
        }

        ///
        /// @brief Clears the commands
        ///
        inline void clear()
        {
            iv_commands.clear();
        }

        ///
        /// @brief Returns the command information
        /// @return iv_commands
        ///
        inline const typename std::map<DIMM_TARGET, BCW_MAP>& get()
        const
        {
            return iv_commands;
        }

    private:
        // The following is a map of targets to a map of buffer's as the key to a vector of cw_info
        // An explanation as to the data structure is included below

        // PBA compression is a little complex, but is organized to allow us to minimize the number of commands run
        // Each individual map is designed to further minimize the number of commands run
        // The compressed commands consist of a map of DIMM targets as a key going to a map buffer ID's as a key and a value of control word information structures
        // The outside map, maps the DIMM to the PBA BCWs and buffers that need to be run
        // Basically, it's a list of a specific buffer/DIMM target with all the commands that need to be run
        // The target loop allows us to just issue the enter/exit for each DIMM once
        // We then just issue all of the BCW's one buffer at a time
        // CCS does not allow the user to toggle the DQ during a PBA command
        // The DQ information is stored in separate registers in the PHY
        // What this means for issuing the commands is that we have to issue an invocation of CCS for each different PBA command we issue
        // We can issue a single MRS command for multiple DRAM's however
        // Each invocation of CCS creates a noticable increase in time, as the registers need to be configured, CCS needs to be started, and we need to poll for done
        // By only entering into PBA on a DIMM-rank once and by issuing the PBA commands to each buffer in one invocation, we can save a lot of runtime
        typename std::map<DIMM_TARGET, BCW_MAP> iv_commands;
};

///
/// @brief Performs all PBA commands
/// @param[in] i_target DIMM on which to operate
/// @param[in] i_buffer the LRDIMM buffer on which to operate
/// @param[in] i_bcws the control words to issue to the buffer
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode execute_commands( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint64_t i_buffer,
                                    const std::vector<cw_info>& i_bcws );

///
/// @brief Performs all PBA commands
/// @param[in] i_commands the PDA commands to issue and DRAM
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode execute_commands( const commands& i_commands );

} // ns pba

} // ns ddr4

} // ns mss

#endif
