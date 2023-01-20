/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/fir/gen_mss_fir.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
/// @file gen_mss_fir.H
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GEN_MSS_FIR_H_
#define _GEN_MSS_FIR_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

// Each FIR bit is contained in a register (set or unset) and is mapped to action and mask registers (defines
// their behavior). Likewise, each unit (MCBIST, MCS, MCA) has control bits defining whether the attentions
// from this unit represent special or host attentions.


///
/// @brief FIR Register Traits
/// @tparam R FIR Register
///
template <uint64_t R>
struct firTraits;

///
/// @brief FIR Register Traits, with newer register setup (discrete registers for each action type)
/// @tparam R FIR Register
/// TODO MST-1389 Create fir::reg class for this struct
///
template <uint64_t R>
struct firTraits2;

namespace fir
{

///
/// @brief Small class to hold Explorer, P10 and previous generations FIR register
/// @tparam R the FIR register
/// @tparam RT the type traits for this register (derived)
///
template<uint64_t R, typename RT = mss::firTraits<R>>
class reg
{
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

            if (RT::HAS_ACT2)
            {
                FAPI_TRY( mss::getScom(iv_target, RT::ACT2, iv_action2) );
            }

        fapi_try_exit:
            o_rc = fapi2::current_err;
        }

        ///
        /// @brief Clear FIR bits
        /// @tparam B the ordinal number of the bit in question
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

        // Magic patterns in these functions are (Action0, Action1, Action2, Mask)

        ///
        /// @brief Setup Checkstop (0,0,0,0)
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& checkstop()
        {
            return action_helper<B, C>(0, 0, 0, 0);
        }

        ///
        /// @brief Setup Checkstop_nomask (0,0,0,x) without unmasking given FIR bits
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& checkstop_nomask()
        {
            return action_helper_no_mask<B, C>(0, 0, 0);
        }

        ///
        /// @brief Setup Recoverable Error (0,1,0,0)
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& recoverable_error()
        {
            return action_helper<B, C>(0, 1, 0, 0);
        }

        ///
        /// @brief Setup Attention (1,0,0,0)
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& attention()
        {
            return action_helper<B, C>(1, 0, 0, 0);
        }

        ///
        /// @brief Setup Local checkstop (1,1,0,0)
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& local_checkstop()
        {
            return action_helper<B, C>(1, 1, 0, 0);
        }

        ///
        /// @brief Setup Host Attention (0,0,1,0)
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& host_attention()
        {
            return action_helper<B, C>(0, 0, 1, 0);
        }

        ///
        /// @brief Setup Masked (x,x,x,1)
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& masked()
        {
            return action_helper<B, C>(1, 1, 1, 1);
        }

        ///
        /// @brief Setup Masked without touching action bits (x,x,x,1)
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& remask()
        {
            iv_mask.setBit<B, C>();
            return *this;
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

            if (RT::HAS_ACT2)
            {
                FAPI_TRY( mss::putScom(iv_target, RT::ACT2, iv_action2) );
            }

            FAPI_TRY( mss::putScom(iv_target, RT::MASK_AND, iv_mask) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Return FIR reg address
        /// @return FIR reg address
        ///
        inline uint64_t get_address() const
        {
            return RT::REG;
        }

        ///
        /// @brief Return mask value
        /// @return FIR mask register value
        ///
        fapi2::buffer<uint64_t> get_mask() const
        {
            return iv_mask;
        }

        ///
        /// @brief Return act0 value
        /// @return FIR action0 register value
        ///
        fapi2::buffer<uint64_t> get_act0() const
        {
            return iv_action0;
        }

        ///
        /// @brief Return act1 value
        /// @return FIR action1 register value
        ///
        fapi2::buffer<uint64_t> get_act1() const
        {
            return iv_action1;
        }

        ///
        /// @brief Return act2 value
        /// @return FIR action2 register value
        ///
        fapi2::buffer<uint64_t> get_act2() const
        {
            return iv_action2;
        }

    private:
        fapi2::Target<RT::T> iv_target;
        fapi2::buffer<uint64_t> iv_mask;
        fapi2::buffer<uint64_t> iv_action0;
        fapi2::buffer<uint64_t> iv_action1;
        fapi2::buffer<uint64_t> iv_action2;

        ///
        /// @brief Register helper takes a setting of bits for action0, action1, action2, and optionally mask and sets our internal state
        /// @tparam B the fir bit ordinal number
        /// @tparam C the bit count, defaults to 1
        /// @param[in] i_act0 the setting for action0
        /// @param[in] i_act1 the setting for action1
        /// @param[in] i_act2 the setting for action2
        /// @param[in] i_mask the setting for mask
        /// @return reference to fir::reg, to be used for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& action_helper(const uint64_t i_act0,
                                          const uint64_t i_act1,
                                          const uint64_t i_act2,
                                          const uint64_t i_mask)
        {
            iv_mask.writeBit<B, C>(i_mask);

            return this->action_helper_no_mask<B, C>(i_act0, i_act1, i_act2);
        }

        ///
        /// @brief Register helper takes a setting of bits for action0, action1, action2, and sets our internal state
        /// @tparam B the fir bit ordinal number
        /// @tparam C the bit count, defaults to 1
        /// @param[in] i_act0 the setting for action0
        /// @param[in] i_act1 the setting for action1
        /// @param[in] i_act2 the setting for action2
        /// @return reference to fir::reg, to be used for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg<R>& action_helper_no_mask(const uint64_t i_act0,
                const uint64_t i_act1,
                const uint64_t i_act2)
        {
            iv_action0.writeBit<B, C>(i_act0);
            iv_action1.writeBit<B, C>(i_act1);
            iv_action2.writeBit<B, C>(i_act2);

            return *this;
        }


};

///
/// @brief Small class to hold a Odyssey and P11 style FIR register
/// @tparam R the FIR register
/// @tparam RT the type traits for this register (derived)
///
template<uint64_t R, typename RT = mss::firTraits2<R>>
class reg2
{
    public:

        ///
        /// @brief fir::reg constructor
        /// @param[in] i_target representing the fapi2::Target used to scom register R
        ///
        reg2( const fapi2::Target<RT::T>& i_target):
            iv_target(i_target)
        {
        }

        ///
        /// @brief Clear FIR bits
        /// @tparam B the ordinal number of the bit in question
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        template< uint64_t B >
        inline fapi2::ReturnCode clear() const
        {
            fapi2::buffer<uint64_t> l_clear;
            l_clear.setBit<B>();
            FAPI_TRY( mss::putScom(iv_target, RT::FIR_CLEAR, l_clear) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Clear the entire register of FIR bits
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        inline fapi2::ReturnCode clear() const
        {
            return mss::putScom(iv_target, RT::FIR_CLEAR, 0xFFFFFFFFFFFFFFFF);
        }

        // Magic patterns in these functions are (Action0, Action1, Action2, Mask)

        ///
        /// @brief Setup Checkstop register
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg2<R>& checkstop()
        {
            iv_xstop.setBit<B, C>();
            iv_mask_clear.setBit<B, C>();
            return *this;
        }

        ///
        /// @brief Setup Checkstop register without affecting mask
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg2<R>& checkstop_nomask()
        {
            iv_xstop.setBit<B, C>();
            return *this;
        }

        ///
        /// @brief Setup Recoverable Error register
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg2<R>& recoverable_error()
        {
            iv_recov.setBit<B, C>();
            iv_mask_clear.setBit<B, C>();
            return *this;
        }

        ///
        /// @brief Setup Attention register
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg2<R>& attention()
        {
            iv_attn.setBit<B, C>();
            iv_mask_clear.setBit<B, C>();
            return *this;
        }

        ///
        /// @brief Setup Local checkstop register
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return fir::reg reference suitable for chaining
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fir::reg2<R>& local_checkstop()
        {
            iv_lxstop.setBit<B, C>();
            iv_mask_clear.setBit<B, C>();
            return *this;
        }

        ///
        /// @brief Setup Masked
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fapi2::ReturnCode masked()
        {
            return this->remask<B, C>();
        }

        ///
        /// @brief Setup Masked by updating MASK_SET register
        /// @tparam B the ordinal number of the bit in question
        /// @tparam C the bit count, defaults to 1
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        template< uint64_t B, uint64_t C = 1 >
        inline fapi2::ReturnCode remask()
        {
            fapi2::buffer<uint64_t> l_set;
            l_set.setBit<B>();
            FAPI_TRY( mss::putScom(iv_target, RT::MASK_SET, l_set) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write action0, action1 and mask for this register
        /// @return fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        inline fapi2::ReturnCode write() const
        {
            FAPI_TRY( mss::putScom(iv_target, RT::MASK_CLEAR, iv_mask_clear) );
            FAPI_TRY( mss::putScom(iv_target, RT::ATTN,      iv_attn) );
            FAPI_TRY( mss::putScom(iv_target, RT::LXSTOP,    iv_lxstop) );
            FAPI_TRY( mss::putScom(iv_target, RT::RECOV,     iv_recov) );
            FAPI_TRY( mss::putScom(iv_target, RT::XSTOP,     iv_xstop) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Return FIR reg address
        /// @return FIR reg address
        ///
        inline uint64_t get_address() const
        {
            return RT::FIR_CLEAR;
        }

        ///
        /// @brief Return mask value
        /// @return FIR mask register value
        ///
        fapi2::buffer<uint64_t> get_mask() const
        {
            return iv_mask_clear;
        }

        ///
        /// @brief Return attn value
        /// @return FIR attention register value
        ///
        fapi2::buffer<uint64_t> get_attn() const
        {
            return iv_attn;
        }

        ///
        /// @brief Return lxstop value
        /// @return FIR local checkstop register value
        ///
        fapi2::buffer<uint64_t> get_lxstop() const
        {
            return iv_lxstop;
        }

        ///
        /// @brief Return recov value
        /// @return FIR recoverable register value
        ///
        fapi2::buffer<uint64_t> get_recov() const
        {
            return iv_recov;
        }

        ///
        /// @brief Return xstop value
        /// @return FIR checkstop register value
        ///
        fapi2::buffer<uint64_t> get_xstop() const
        {
            return iv_xstop;
        }

    private:

        fapi2::Target<RT::T> iv_target;
        fapi2::buffer<uint64_t> iv_mask_clear;
        fapi2::buffer<uint64_t> iv_attn;
        fapi2::buffer<uint64_t> iv_lxstop;
        fapi2::buffer<uint64_t> iv_recov;
        fapi2::buffer<uint64_t> iv_xstop;

};

} // end ns fir
} // end ns mss
#endif
