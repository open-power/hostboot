/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/quad_encode_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file quad_encode_workaround.H
/// @brief Contains workarounds having to do with quad-encode CS
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#ifndef _QUAD_ENCODE_WORKAROUND_H_
#define _QUAD_ENCODE_WORKAROUND_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>

#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/ccs/ccs.H>
#include <lib/dimm/rank.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <p9_mc_scom_addresses_fld.H>

namespace mss
{

namespace workarounds
{

static constexpr uint64_t MAX_MR = 6;

///
/// @brief Fixes shadow register corruption over all ranks if needed
/// @param[in] i_target - the DIMM target on which to operate
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///
fapi2::ReturnCode fix_shadow_register_corruption( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Fixes shadow register corruption if needed
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///
fapi2::ReturnCode fix_shadow_register_corruption( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank);

///
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @param[out] o_fix_needed - true iff the shadow register's could be corrupted (aka are we a 4R DIMM?)
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///

fapi2::ReturnCode check_shadow_register_corruption( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        bool& o_fix_needed);

///
/// @brief Returns true if an MRS command was run
/// @param[in] i_inst instruction to check for an MRS command
/// @return true iff the command contains an MRS command
///
bool is_command_mrs(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst);

///
/// @brief Returns true if a vector of commands contains an MRS command
/// @param[in] i_inst instruction to check for an MRS command
/// @return true iff the command contains an MRS command
///
bool contains_command_mrs(const std::vector<ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>>& i_inst);

///
/// @brief Converts the CCS instructions to the shadow register configuration
/// @param[in] i_inst CCS instruction to convert
/// @return the register value for the shadow register
///
inline fapi2::buffer<uint64_t> convert_to_shadow_reg(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst)
{
    fapi2::buffer<uint64_t> l_arr0(i_inst.arr0);
    mss::reverse(l_arr0);
    constexpr uint64_t SHADOW_REG_START = 50;
    l_arr0.clearBit<0, SHADOW_REG_START>();
    return l_arr0;
}

///
/// @class shadow_regs_traits
/// @brief a collection of traits associated with each shadow register
/// @tparam MR the MR number for which to fix the shadow regs
///
template< uint64_t MR >
class shadow_regs_traits;

///
/// @class shadow_regs_traits
/// @brief a collection of traits associated with each shadow register - specialization for MR0
///
template<>
class shadow_regs_traits<0>
{
    public:

        static const std::vector<uint64_t> REGS;

        ///
        /// @brief Configure the ARR0 of the CCS isntruction for mrs00
        /// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        /// @param[in,out] io_inst the instruction to fixup
        /// @param[in] i_rank ths rank in question
        /// @return FAPI2_RC_SUCCESS iff OK
        ///
        static inline fapi2::ReturnCode mrs_gen(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                                                const uint64_t i_rank)
        {
            constexpr uint8_t LR_2666_MARGIN_ADJUST = 2;

            // So, why is MRS0 being reset differently compared to the other mode register sets?
            // For LRDIMM, at 2666, we're running at the edge of the PHY's capabilities to account for the read delay
            // This means, we've started taking some fails related to not being able to wait long enough for the data to come back
            // A handy workaround for this is to increase our CAS latency within the PHY itself by changing the value of the mode register
            // This tricks the PHY's snooping capabilities to think that the data is coming back a bit later
            // This allows the gate delay and RLO to account for the increased delay correctly
            // Note: we need the DRAM to send the data back at the same time, but fake the PHY into thinking that it's coming later

            uint8_t l_dimm_type = 0;
            uint64_t l_freq = 0;

            // Check to make sure our ctor worked ok
            mss::ddr4::mrs00_data l_data( i_target, fapi2::current_err );
            FAPI_TRY( fapi2::current_err, "%s Unable to construct MRS00 data from attributes", mss::c_str(i_target) );
            FAPI_TRY( mss::eff_dimm_type(i_target, l_dimm_type));
            FAPI_TRY( mss::freq(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq));

            // Apply the CAS latency offset if we have an LRDIMM at 2666
            l_data.iv_cas_latency += ((l_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) &&
                                      (l_freq == fapi2::ENUM_ATTR_MSS_FREQ_MT2666)) ?
                                     LR_2666_MARGIN_ADJUST : 0;
            FAPI_TRY( mss::ddr4::mrs00(i_target, l_data, io_inst, i_rank) );
        fapi_try_exit:
            return fapi2::current_err;
        };
};

///
/// @class shadow_regs_traits
/// @brief a collection of traits associated with each shadow register - specialization for MR1
///
template<>
class shadow_regs_traits<1>
{
    public:

        static const std::vector<uint64_t> REGS;

        ///
        /// @brief Configure the ARR0 of the CCS isntruction for mrs00
        /// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        /// @param[in,out] io_inst the instruction to fixup
        /// @param[in] i_rank ths rank in question
        /// @return FAPI2_RC_SUCCESS iff OK
        ///
        static inline fapi2::ReturnCode mrs_gen(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                                                const uint64_t i_rank)
        {
            return mss::ddr4::mrs01(i_target, io_inst, i_rank);
        };
};

///
/// @class shadow_regs_traits
/// @brief a collection of traits associated with each shadow register - specialization for MR2
///
template<>
class shadow_regs_traits<2>
{
    public:

        static const std::vector<uint64_t> REGS;

        ///
        /// @brief Configure the ARR0 of the CCS isntruction for mrs00
        /// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        /// @param[in,out] io_inst the instruction to fixup
        /// @param[in] i_rank ths rank in question
        /// @return FAPI2_RC_SUCCESS iff OK
        ///
        static inline fapi2::ReturnCode mrs_gen(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                                                const uint64_t i_rank)
        {
            return mss::ddr4::mrs02(i_target, io_inst, i_rank);
        };
};

///
/// @class shadow_regs_traits
/// @brief a collection of traits associated with each shadow register - specialization for MR3
///
template<>
class shadow_regs_traits<3>
{
    public:

        static const std::vector<uint64_t> REGS;

        ///
        /// @brief Configure the ARR0 of the CCS isntruction for mrs00
        /// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        /// @param[in,out] io_inst the instruction to fixup
        /// @param[in] i_rank ths rank in question
        /// @return FAPI2_RC_SUCCESS iff OK
        ///
        static inline fapi2::ReturnCode mrs_gen(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                                                const uint64_t i_rank)
        {
            return mss::ddr4::mrs03(i_target, io_inst, i_rank);
        };
};

///
/// @class shadow_regs_traits
/// @brief a collection of traits associated with each shadow register - specialization for MR4
///
template<>
class shadow_regs_traits<4>
{
    public:

        static const std::vector<uint64_t> REGS;

        ///
        /// @brief Configure the ARR0 of the CCS isntruction for mrs00
        /// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        /// @param[in,out] io_inst the instruction to fixup
        /// @param[in] i_rank ths rank in question
        /// @return FAPI2_RC_SUCCESS iff OK
        ///
        static inline fapi2::ReturnCode mrs_gen(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                                                const uint64_t i_rank)
        {
            return mss::ddr4::mrs04(i_target, io_inst, i_rank);
        };
};

///
/// @class shadow_regs_traits
/// @brief a collection of traits associated with each shadow register - specialization for MR5
///
template<>
class shadow_regs_traits<5>
{
    public:

        static const std::vector<uint64_t> REGS;

        ///
        /// @brief Configure the ARR0 of the CCS isntruction for mrs00
        /// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        /// @param[in,out] io_inst the instruction to fixup
        /// @param[in] i_rank ths rank in question
        /// @return FAPI2_RC_SUCCESS iff OK
        ///
        static inline fapi2::ReturnCode mrs_gen(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                                                const uint64_t i_rank)
        {
            return mss::ddr4::mrs05(i_target, io_inst, i_rank);
        };
};

///
/// @class shadow_regs_traits
/// @brief a collection of traits associated with each shadow register - specialization for MR6
///
template<>
class shadow_regs_traits<6>
{
    public:

        static const std::vector<uint64_t> REGS;

        ///
        /// @brief Configure the ARR0 of the CCS isntruction for mrs00
        /// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        /// @param[in,out] io_inst the instruction to fixup
        /// @param[in] i_rank ths rank in question
        /// @return FAPI2_RC_SUCCESS iff OK
        ///
        static inline fapi2::ReturnCode mrs_gen(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                                                const uint64_t i_rank)
        {
            return mss::ddr4::mrs06(i_target, io_inst, i_rank);
        };
};


///
/// @brief Fixes shadow register corruption on the associated MR
/// @tparam MR the MR number for which to fix the shadow regs
/// @tparam traits associated with this shadow register
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in] i_rp - the rank pair on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///
template< uint64_t MR, typename TT = shadow_regs_traits<MR> >
fapi2::ReturnCode fix_shadow_register_corruption_mr( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rp,
        const uint64_t i_rank)
{
    static_assert( MR <= MAX_MR, "MR instance out of range");

    ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> l_inst;
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // Converts this to DIMM rank. just. in. case.
    const auto l_dimm_rank = mss::index(i_rank);

    FAPI_ASSERT( i_rp < MAX_RANK_PAIRS,
                 fapi2::MSS_INVALID_RANK_PAIR()
                 .set_RANK_PAIR(i_rp)
                 .set_FUNCTION(mss::ffdc_function_codes::FIX_SHADOW_REGISTER)
                 .set_MCA_TARGET(l_mca),
                 "%s invalid RP %u. Max is %u",
                 mss::c_str(l_mca), i_rp, MAX_RANK_PAIRS);

    FAPI_TRY(TT::mrs_gen(i_target, l_inst, l_dimm_rank), "%s failed to get MRS%u nominal values", mss::c_str(i_target), MR);

    // Issues the scom to the shadow regiser
    FAPI_TRY(mss::putScom(l_mca, TT::REGS[i_rp], convert_to_shadow_reg(l_inst)),
             "%s rank%u failed to set the shadow register", mss::c_str(i_target), l_dimm_rank);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // ns workarounds
} // ns mss

#endif
