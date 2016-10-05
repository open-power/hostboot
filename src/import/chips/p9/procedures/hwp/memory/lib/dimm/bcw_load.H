/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/bcw_load.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file bcw_load.H
/// @brief Code to support bcw_loads
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_BCW_LOAD_H_
#define _MSS_BCW_LOAD_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>

#include <lib/utils/c_str.H>
#include <lib/shared/mss_kind.H>

namespace mss
{

enum data_buffer
{
    BCW_4BIT,
    BCW_8BIT,
};

struct bcw_data
{
    // function space #
    fapi2::buffer<uint8_t> iv_func_space;

    // Which buffer control word (bcw) # this is
    fapi2::buffer<uint8_t> iv_number;

    // The attribute getter
    fapi2::ReturnCode (*iv_attr_get)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, uint8_t&);

    // The bcw value
    fapi2::buffer<uint8_t> iv_data;

    // The delay needed after this BCW word is written
    uint64_t iv_delay;

    ///
    /// @brief NO-OP function to avoid a function nullptr
    /// @param[in] i_target a DIMM target
    /// @param[out] o_output output remains unchanged
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode no_op_func(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t& o_output)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    ///
    /// @brief ctor for attribute driven data
    ///
    bcw_data( uint64_t i_func_space,
              uint64_t i_number,
              fapi2::ReturnCode (*i_func)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, uint8_t&),
              uint64_t i_delay ):
        iv_func_space(i_func_space),
        iv_number(i_number),
        iv_attr_get(i_func),
        iv_data(0),
        iv_delay(i_delay)
    {}

    ///
    /// @brief ctor for custom data
    ///
    bcw_data( uint64_t i_func_space,
              uint64_t i_number,
              uint64_t i_data,
              uint64_t i_delay):
        iv_func_space(i_func_space),
        iv_number(i_number),
        iv_data(i_data),
        iv_delay(i_delay)
    {
        // Setting the attribute accessor function pointer to NO-OP
        // when we call the ctor that doesn't use it to avoid cases
        // when iv_attr_get can be nullptr and potentially cause a seg fault
        iv_attr_get = &no_op_func;
    }

};

template< data_buffer T >
class bcwTraits;

template< >
class bcwTraits< BCW_8BIT >
{
    public:
        static constexpr uint64_t DATA_LEN = 8;
        static constexpr uint64_t WORD_LEN = 4;
        static constexpr uint64_t SWIZZLE_START = 7;
};

template< >
class bcwTraits< BCW_4BIT >
{
    public:
        static constexpr uint64_t DATA_LEN = 4;
        static constexpr uint64_t WORD_LEN = 4;
        static constexpr uint64_t SWIZZLE_START = 7;
};

///
/// @brief Helper function to load BCWs
/// @tparam T the buffer control word type (4 bit or 8 bit)
/// @tparam TT traits type defaults to bcwTraits<T>
/// @param[in] i_target a DIMM target
/// @param[in] i_data bcw data to send
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< data_buffer T, typename TT = bcwTraits<T> >
static fapi2::ReturnCode bcw_engine_boilerplate(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const bcw_data& i_data,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    constexpr uint64_t DDR_ADDRESS_12 = 12;

    // Note: this isn't general - assumes Nimbus via MCBIST instruction here BRS
    ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> l_inst = ccs::rcd_command<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // Address bit 12 must be 1 for accesses to Data Buffer (DB) Control Words.
    // Consider adding more commonality between RCD/BCW commands - AAM
    l_inst.arr0.setBit<DDR_ADDRESS_12>();

    // For user defined data, iv_data is user defined and iv_attr_get is a NO-OP
    // For attribute defined data, iv_attr_get will define data and l_value initialization is overwritten
    // I need l_value integral because the attribute accessor template deduction doesn't let me use buffers
    // and since I'm passing in bcw data as const I can't pass in iv_data to the attribute accessor
    // which would break const correctness
    uint8_t l_value = i_data.iv_data;
    FAPI_TRY( i_data.iv_attr_get(i_target, l_value) );

    // Data to be written into the configuration registers
    // 4-bit control are containned in bits DA0 thorugh DA3
    // 8-bit control are contained in bits DA0 thorugh DA7
    mss::swizzle< MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_0_13,
        TT::DATA_LEN, TT::SWIZZLE_START >(fapi2::buffer<uint8_t>(l_value), l_inst.arr0);

    // Selection of each word of control bits
    // 4-bit control words are selected by bits on DA4 through DA11
    // 8-bit control words are selected by bits on DA8 through DA11
    mss::swizzle < MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_0_13 + TT::DATA_LEN,
        TT::WORD_LEN, TT::SWIZZLE_START > (i_data.iv_number, l_inst.arr0);

    // For changes to the control word setting [...] the controller needs to wait tMRC[tDLLK] after
    // the last control word access, before further access to the DRAM can take place.
    l_inst.arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES,
                                MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(i_data.iv_delay);

    FAPI_INF("F%dBC%02d%s value 0x%x (%d cycles) 0x%016llx:0x%016llx %s",
             uint8_t(i_data.iv_func_space), uint8_t(i_data.iv_number),  (T == BCW_4BIT ? "" : "X"), l_value,
             i_data.iv_delay, uint64_t(l_inst.arr0), uint64_t(l_inst.arr1), mss::c_str(i_target));

    io_inst.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets buffer control words (BCW)
/// @tparam T the buffer control word type (4 bit or 8 bit)
/// @tparam TT traits type defaults to bcwTraits<T>
/// @param[in] i_target a DIMM target
/// @param[in] i_data a vector bcw data to send
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< data_buffer T, typename TT = bcwTraits<T> >
inline fapi2::ReturnCode bcw_engine( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const bcw_data& i_data,
                                     std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    FAPI_TRY( bcw_engine_boilerplate<T>(i_target, i_data, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets buffer control words (BCW)
/// @tparam T the buffer control word type (4 bit or 8 bit)
/// @tparam TT traits type defaults to bcwTraits<T>
/// @param[in] i_target a DIMM target
/// @param[in] i_data_list a vector bcw data to send
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<data_buffer T, typename TT = bcwTraits<T> >
inline fapi2::ReturnCode bcw_engine( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::vector<bcw_data>& i_data_list,
                                     std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    for (const auto& data : i_data_list)
    {
        FAPI_TRY( bcw_engine_boilerplate<T>(i_target, data, io_inst) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the function space for the BCW
/// @tparam T the functon space number we want
/// @param[in] i_target a DIMM target
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< uint64_t T >
inline fapi2::ReturnCode function_space_select(const fapi2::Target< fapi2::TARGET_TYPE_DIMM >& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    // function space bits for the function space selector are
    // don't cares.  We choose 0 for simplicity.
    constexpr uint8_t FSPACE = 0;
    constexpr uint8_t WORD = 7;

    FAPI_TRY( bcw_engine<BCW_8BIT>(i_target,
                                   bcw_data( FSPACE, WORD, T, mss::tmrd() ),
                                   io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the bcw_load operations
/// @tparam T the fapi2::TargetType of i_target
/// @param[in] i_target a fapi2::Target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode bcw_load( const fapi2::Target<T>& i_target );


//
// Implement the polymorphism for bcw_load
//

/// Register the API.
/// Define the template parameters for the overloaded function
/// @note the first argument is the api name, and the rest are the api's template parameters.
/// @note this creates __api_name##_overload
template< mss::kind_t K >
struct perform_bcw_load_overload
{
    static constexpr bool available = false;
};

/// Register the specific overloads. The first parameter is the name
/// of the api, the second is the kind of the element which is being
/// overloaded - an RDIMM, an LRDIMM, etc. The remaining parameters
/// indicate the specialization of the api itself.
/// @note You need to define the "DEFAULT_KIND" here as an overload. This
/// allows the mechanism to find the "base" implementation for things which
/// have no specific overload.
template<>
struct perform_bcw_load_overload< DEFAULT_KIND >
{
    static constexpr bool available = true;
};


template<>
struct perform_bcw_load_overload< KIND_RDIMM_DDR4 >
{
    // Buffer control words should not be sent for RDIMMs (NO-OP)
    static constexpr bool available = true;
};

template<>
struct perform_bcw_load_overload< KIND_LRDIMM_DDR4 >
{
    static constexpr bool available = true;
};

///
///  Define the default case for overloaded calls. enable_if states that
/// if there is a DEFAULT_KIND overload for this TargetType, then this
/// entry point will be defined. Note the general case below is enabled if
/// there is no overload defined for this TargetType
///

///
/// @brief Perform the bcw_load operations
/// @tparam K, the kind of DIMM we're operating on (derived)
/// @param[in] i_target, a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::kind_t K = FORCE_DISPATCH >
typename std::enable_if< perform_bcw_load_overload<DEFAULT_KIND>::available, fapi2::ReturnCode>::type
perform_bcw_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                  std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

//
// We know we registered overloads for perform_bcw_load, so we need the entry point to
// the dispatcher. Add a set of these for all TargetTypes which get overloads
// for this API
//

///
/// @brief Perform the bcw_load operations (FORCE_DISPATCH specialization)
/// @param[in] i_target the DIMM target
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_bcw_load<FORCE_DISPATCH>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

///
/// @brief Perform the bcw_load operations (DEFAULT_KIND specialization)
/// @param[in] i_target the DIMM target
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_bcw_load<DEFAULT_KIND>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

//
// Boilerplate dispatcher
//

///
/// @brief Perform the bcw_load operations
/// @tparam K the kind of DIMM we're operating on (derived)
/// @tparam B boolean that enables API from K dimm kind
/// @param[in] i_target, a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< kind_t K, bool B = perform_bcw_load_overload<K>::available >
inline fapi2::ReturnCode perform_bcw_load_dispatch( const kind_t& i_kind,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    // We dispatch to another kind if:
    // We don't have an overload defined (B == false)
    // Or, if we do have an overload (B == true) and this is not our kind.
    if ((B == false) || ((B == true) && (K != i_kind)))
    {
        return perform_bcw_load_dispatch < (kind_t)(K - 1) > (i_kind, i_target, io_inst);
    }

    // Otherwise, we call the overload.
    return perform_bcw_load<K>(i_target, io_inst);
}

// DEFAULT_KIND is 0 so this is the end of the recursion
template<>
inline fapi2::ReturnCode perform_bcw_load_dispatch<DEFAULT_KIND>(const kind_t&,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    return perform_bcw_load<DEFAULT_KIND>(i_target, io_inst);
}

}
#endif
