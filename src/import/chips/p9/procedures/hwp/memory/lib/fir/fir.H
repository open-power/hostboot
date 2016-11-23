/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/fir.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file fir.H
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_FIR_H_
#define _MSS_FIR_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/utils/scom.H>

namespace mss
{

//
// Each FIR bit is contained in a register (set or unset) and is mapped to action and mask registers (defines
// their behavior). Likewise, each unit (MCBIST, MCS, MCA) has control bits defining whether the attentions
// from this unit represent special or host attentions.

///
/// @brief FIR Register Traits
/// @tparam R the FIR register
///
template <uint64_t R >
struct firTraits;

///
/// @brief FIR Register Traits for MCBISTFIR
///
template <>
struct firTraits<MCBIST_MCBISTFIRQ>
{
    static constexpr uint64_t REG = MCBIST_MCBISTFIRQ;
    static constexpr uint64_t ACT0 = MCBIST_MCBISTFIRACT0;
    static constexpr uint64_t ACT1 = MCBIST_MCBISTFIRACT1;
    static constexpr uint64_t MASK = MCBIST_MCBISTFIRMASK;
    static constexpr uint64_t MASK_AND = MCBIST_MCBISTFIRMASK_AND;
    static constexpr uint64_t MASK_OR = MCBIST_MCBISTFIRMASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCBIST;
};

///
/// @brief FIR Register Traits for PHYFIR
///
template <>
struct firTraits<MCA_IOM_PHY0_DDRPHY_FIR_REG>
{
    static constexpr uint64_t REG = MCA_IOM_PHY0_DDRPHY_FIR_REG;
    static constexpr uint64_t ACT0 = MCA_IOM_PHY0_DDRPHY_FIR_ACTION0_REG;
    static constexpr uint64_t ACT1 = MCA_IOM_PHY0_DDRPHY_FIR_ACTION1_REG;
    static constexpr uint64_t MASK = MCA_IOM_PHY0_DDRPHY_FIR_MASK_REG;
    static constexpr uint64_t MASK_AND = MCA_IOM_PHY0_DDRPHY_FIR_MASK_REG_AND;
    static constexpr uint64_t MASK_OR = MCA_IOM_PHY0_DDRPHY_FIR_MASK_REG_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCA;
};

///
/// @brief FIR Register Traits for MCFIR
///
template <>
struct firTraits<MCS_MCFIR>
{
    static constexpr uint64_t REG = MCS_MCFIR;
    static constexpr uint64_t ACT0 = MCS_MCFIRACT0;
    static constexpr uint64_t ACT1 = MCS_MCFIRACT1;
    static constexpr uint64_t MASK = MCS_MCFIRMASK;
    static constexpr uint64_t MASK_AND = MCS_MCFIRMASK_AND;
    static constexpr uint64_t MASK_OR = MCS_MCFIRMASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCS;
};

///
/// @brief FIR Register Traits for MCA_FIR (ECC64.SCOM.FIR)
///
template <>
struct firTraits<MCA_FIR>
{
    static constexpr uint64_t REG = MCA_FIR;
    static constexpr uint64_t ACT0 = MCA_ACTION0;
    static constexpr uint64_t ACT1 = MCA_ACTION1;
    static constexpr uint64_t MASK = MCA_MASK;
    static constexpr uint64_t MASK_AND = MCA_MASK_AND;
    static constexpr uint64_t MASK_OR = MCA_MASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCA;
};

///
/// @brief FIR Register Traits for MBACALFIR
///
template <>
struct firTraits<MCA_MBACALFIRQ>
{
    static constexpr uint64_t REG = MCA_MBACALFIRQ;
    static constexpr uint64_t ACT0 = MCA_MBACALFIR_ACTION0;
    static constexpr uint64_t ACT1 = MCA_MBACALFIR_ACTION1;
    static constexpr uint64_t MASK = MCA_MBACALFIR_MASK;
    static constexpr uint64_t MASK_AND = MCA_MBACALFIR_MASK_AND;
    static constexpr uint64_t MASK_OR = MCA_MBACALFIR_MASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCA;
};

namespace fir
{


///
/// @brief Small class to hold a FIR register
/// @tparam R the FIR register
/// @tparam RT the type traits for this register (derived)
///
template< uint64_t R, typename RT = firTraits<R> >
class reg
{

    private:
        fapi2::Target<RT::T> iv_target;

    public:

        ///
        /// @brief fir::reg constructor
        /// @param[in] i_target representing the fapi2::Target used to scom register R
        /// @param[out] a fapi2::ReturnCode indicating if the internal constructor opererations were a success
        ///
        reg( const fapi2::Target<RT::T>& i_target, fapi2::ReturnCode& o_rc ):
            iv_target(i_target),

            // Fill our buffer with F's as we're going to clear the bits we want to
            // unmask and then drop the result in to the _AND register.
            iv_mask(~0)
        {
            // Priming Read
            FAPI_TRY( mss::getScom(iv_target, RT::ACT0, iv_action0) );
            FAPI_TRY( mss::getScom(iv_target, RT::ACT1, iv_action1) );

        fapi_try_exit:
            o_rc = fapi2::current_err;
        }

        ///
        /// @brief Clear FIR bits
        /// @tparam B the ordinial number of the bit in question
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        template< uint64_t B >
        inline fapi2::ReturnCode clear() const
        {
            fapi2::buffer<uint64_t> l_read;
            FAPI_TRY( mss::getScom(iv_target, RT::REG, l_read) );
            l_read.clearBit<B>();
            FAPI_TRY( mss::putScom(iv_target, RT::REG, l_read) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Clear the entire register of FIR bits
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        inline fapi2::ReturnCode clear() const
        {
            return mss::putScom(iv_target, RT::REG, 0);
        }

        // Magic patterns in these functions are (Action0, Action1, Mask)

        ///
        /// @brief Setup Checkstop (0,0,0)
        /// @tparam B the ordinial number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& checkstop()
        {
            return action_helper<B, C>(0, 0, 0);
        }

        ///
        /// @brief Setup Recoverable Error (0,1,0)
        /// @tparam B the ordinial number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference sutable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& recoverable_error()
        {
            return action_helper<B, C>(0, 1, 0);
        }

        ///
        /// @brief Setup Attention (1,0,0)
        /// @tparam B the ordinial number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference sutable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& attention()
        {
            return action_helper<B, C>(1, 0, 0);
            // TK do we need to setup special attention or host attention here?
        }

        ///
        /// @brief Setup Local checkstop (1,1,0)
        /// @tparam B the ordinial number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference sutable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& local_checkstop()
        {
            return action_helper<B, C>(1, 1, 0);
        }

        ///
        /// @brief Setup Masked (x,x,1)
        /// @tparam B the ordinial number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference sutable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& masked()
        {
            return action_helper<B, C>(1, 1, 1);
        }

        ///
        /// @brief Write action0, action1 and mask for this register
        /// @return fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        inline fapi2::ReturnCode write() const
        {
            // Set action registers before unmasking to prevent unintended actions when you unmask.
            FAPI_TRY( mss::putScom(iv_target, RT::ACT0,     iv_action0) );
            FAPI_TRY( mss::putScom(iv_target, RT::ACT1,     iv_action1) );
            FAPI_TRY( mss::putScom(iv_target, RT::MASK_AND, iv_mask) );

        fapi_try_exit:
            return fapi2::current_err;
        }

    private:

        fapi2::buffer<uint64_t> iv_mask;
        fapi2::buffer<uint64_t> iv_action0;
        fapi2::buffer<uint64_t> iv_action1;

        ///
        /// @brief Register helper takes a setting of bits for action0, action1 and mask and sets our internal state
        /// @tparam B the fir bit ordinal number
        /// @tparam C the bit count, defaults to 1
        /// @param[in] i_act0 the setting for action0
        /// @param[in] i_act1 the setting for action1
        /// @param[in] i_mask the setting for mask
        /// @return reference to fir::reg, to be used for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& action_helper(const uint64_t i_act0, const uint64_t i_act1, const uint64_t i_mask)
        {
            iv_mask.writeBit<B, C>(i_mask);
            iv_action0.writeBit<B, C>(i_act0);
            iv_action1.writeBit<B, C>(i_act1);

            return *this;
        }
};

}
}
#endif
