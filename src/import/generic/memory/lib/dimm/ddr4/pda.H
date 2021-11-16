/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/pda.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file pda.H
/// @brief Code to support per-DRAM addressability (PDA)
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#ifndef _GENERIC_DDR4_PDA_H_
#define _GENERIC_DDR4_PDA_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/dimm/mrs_load.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <generic/memory/lib/dimm/mrs_traits.H>

#include <map>

namespace mss
{

namespace ddr4
{

namespace pda
{

///
/// @brief PDA traits class
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class pda_traits
{};

///
/// @brief PDA commands container that also has compression
/// @tparam D the MRS command type
/// @tparam MC the memory controller type
/// @tparam TT the pda_traits for the controller
///
template< typename D, mss::mc_type MC, typename TT = pda_traits<MC> >
class commands
{
    public:

        // Typdefs to make the code more readable
        typedef std::map<D, std::vector<uint64_t> > mrs_drams;

        ///
        /// @brief Base constructor
        ///
        commands() = default;

        ///
        /// @brief Base destructor
        ///
        ~commands() = default;

        ///
        /// @brief Adds in a PDA command if need be
        /// @tparam fapi2::TargetType T the target type on which to operate
        /// @param[in] i_target the target
        /// @param[in] i_rank the rank
        /// @param[in] i_mrs_container the MRS container to add
        /// @param[in] i_dram the DRAM to issue the PDA command to
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        template<fapi2::TargetType T>
        fapi2::ReturnCode add_command( const fapi2::Target<T>& i_target,
                                       const uint64_t i_rank,
                                       const D& i_mrs,
                                       const uint64_t i_dram )
        {
            typename TT::RANK_TARGET l_rank_target;
            FAPI_TRY( TT::get_rank_target(i_target,
                                          i_rank,
                                          l_rank_target));

            // Does the compression
            iv_commands[l_rank_target][i_mrs].push_back(i_dram);

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
        inline const typename std::map<typename TT::RANK_TARGET, mrs_drams>& get() const
        {
            return iv_commands;
        }

    private:
        // The following is a map of target/DIMM pairs as the key to a map of
        // the MRS command as the key to the DRAM's to toggle. An explanation as to the data structure is included below

        // PDA compression is a little complex, but is organized to allow us to minimize the number of commands run
        // Each individual map is designed to further minimize the number of commands run
        // The compressed commands consist of a map of pairs within a map
        // The outside map, maps the DIMM/rank to the MRS command and DRAM's that need to be run
        // Basically, it's a list of a specific rank target with all the commands that need to be run
        // The rank-specific target information allows us to just issue the enter/exit commands for PDA for each rank once
        // The MRS commands to the DRAM are then looped over in the inside loop
        // The inside map has a key of the MRS and a value of a map of DRAM's to issue the MRS to
        // CCS does not allow the user to toggle the DQ during an MRS command
        // The DQ information is stored in separate registers in the PHY
        // What this means for issuing the commands is that we have to issue an invocation of CCS for each different MRS command we issue
        // We can issue a single MRS command for multiple DRAM's however
        // Each invocation of CCS creates a noticable increase in time, as the registers need to be configured, CCS needs to be started, and we need to poll for done
        // By only entering into PDA on a DIMM-rank once and by issuing the PDA MRS's to multiple DRAM's at a time, we can save a lot of runtime
        // Note: in shmoo, adding the compression reduced runtime from about 13 minutes down to 3 minutes
        typename std::map<typename TT::RANK_TARGET, mrs_drams> iv_commands;
};

///
/// @brief Performs a PDA WR VREF latch
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_commands the PDA commands to issue and DRAM
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note A PDA latch of WR VREF settings is the most common PDA operations
/// This function adds a bit of fanciness (compression) to speed up the overall runtime
///
template< mss::mc_type MC >
fapi2::ReturnCode execute_wr_vref_latch( const commands<mss::ddr4::mrs06_data<MC>, MC>& i_commands );

} // ns pda

} // ns ddr4

} // ns mss

#endif
