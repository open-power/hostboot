/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/control_word_ddr4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file control_word_ddr4.C
/// @brief Run and manage the DDR4 control words for the RCD and data buffers
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB


#ifndef _MSS_CONTROL_WORD_H_
#define _MSS_CONTROL_WORD_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>

#include <generic/memory/lib/utils/c_str.H>
#include <lib/ccs/ccs.H>

namespace mss
{
enum control_word
{
    // buffer control words
    BCW_4BIT,
    BCW_8BIT,

    // register control words
    RCW_4BIT,
    RCW_8BIT,
};
}

///
/// @class cwTraits
/// @brief a collection of traits associated with the control word engine
///
template< mss::control_word T >
class cwTraits;

///
/// @class cwTraits
/// @brief a collection of traits associated with the 8-bit buffer control words
///
template< >
class cwTraits< mss::BCW_8BIT >
{
    public:
        // From DDR4 DBO2 spec
        // Section 4.1 BCW Decoding
        // Table 25 - 8-bit BCW Decoding

        // Address bits denoted by A

        // Data settings are set by A[7:0]
        static constexpr uint64_t DATA_LEN = 8;

        // Control words are set by A[11:4]
        static constexpr uint64_t WORD_LEN = 4;

        // Magic swizzle start bit to make data left aligned for CCS inst.
        static constexpr uint64_t SWIZZLE_START = 7;

        // Address bit 12 must be 1 for accesses to Data Buffer (DB) Control Words.
        static constexpr uint64_t CW_ACCESS = 1;
};

///
/// @class cwTraits
/// @brief a collection of traits associated with the 4-bit buffer control words
///
template< >
class cwTraits< mss::BCW_4BIT >
{
    public:
        // From DDR4 DBO2 spec
        // Section 4.1 BCW Decoding
        // Table 24 - 4-bit BCW Decoding

        // Address bits denoted by A

        // Data settings are set by A[3:0]
        static constexpr uint64_t DATA_LEN = 4;

        // Control words are set by A[11:4]
        // Word length is technically 8
        // But we only need 4 to decode word.
        static constexpr uint64_t WORD_LEN = 4;

        // Magic swizzle start bit to make data left aligned for CCS inst.
        static constexpr uint64_t SWIZZLE_START = 7;

        // Address bit 12 must be 1 for accesses to Data Buffer (DB) Control Words.
        static constexpr uint64_t CW_ACCESS = 1;
};

///
/// @class cwTraits
/// @brief a collection of traits associated with the 8-bit register control words
///
template< >
class cwTraits< mss::RCW_8BIT >
{
    public:
        // From DDR4 RCDO2 spec:
        // Section 2.23.2 Control Word Decoding table
        // Table 27 -  Function Space 0 Control Word Decoding

        // Address bits denoted by A

        // Data settings are set by A[7:0]
        static constexpr uint64_t DATA_LEN = 8;

        // Control words are set by A[12:8]
        // Word length is technically 5
        // But we only need 4 to decode word.
        static constexpr uint64_t WORD_LEN = 4;

        // Magic swizzle start bit to make data left aligned for CCS inst.
        static constexpr uint64_t SWIZZLE_START = 7;

        // Address bit 12 must be 0 for accesses to Register Control Words.
        static constexpr uint64_t CW_ACCESS = 0;
};

///
/// @class cwTraits
/// @brief a collection of traits associated with the 4-bit register control words
///
template< >
class cwTraits< mss::RCW_4BIT >
{
    public:
        // From DDR4 RCDO2 spec:
        // Section 2.23.2 Control Word Decoding table
        // Table 27 -  Function Space 0 Control Word Decoding

        // Address bits denoted by A

        // Data settings are set by A[3:0]
        static constexpr uint64_t DATA_LEN = 4;

        // Control words are set by A[12:4]
        // Word length is technically 9
        // But we only need 4 to decode word.
        static constexpr uint64_t WORD_LEN = 4;

        // Magic swizzle start bit to make data left aligned for CCS inst.
        static constexpr uint64_t SWIZZLE_START = 7;

        // Address bit 12 must be 0 for accesses to Register Control Words.
        static constexpr uint64_t CW_ACCESS = 0;
};

namespace mss
{

///
/// @class cw_data
/// @brief class that represents (register/buffer) control word data
///
struct cw_data
{
    // function space #
    fapi2::buffer<uint8_t> iv_func_space;

    // Which control word# this is (rcw or bcw)
    fapi2::buffer<uint8_t> iv_number;

    // The attribute getter
    fapi2::ReturnCode (*iv_attr_get)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, uint8_t&);

    // The cw value
    fapi2::buffer<uint8_t> iv_data;

    // The delay needed after this CW word is written
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
    /// @brief default ctor for attribute driven data
    ///
    cw_data() = default;

    ///
    /// @brief ctor for attribute driven data
    ///
    cw_data( const uint64_t i_func_space,
             const uint64_t i_number,
             fapi2::ReturnCode (*i_func)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, uint8_t&),
             const  uint64_t i_delay ):
        iv_func_space(i_func_space),
        iv_number(i_number),
        iv_attr_get(i_func),
        iv_data(0),
        iv_delay(i_delay)
    {}

    ///
    /// @brief ctor for custom data
    ///
    cw_data( const uint64_t i_func_space,
             const uint64_t i_number,
             const uint64_t i_data,
             const uint64_t i_delay):
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

///
/// @brief Control word engine that sets the CCS instruction
/// @tparam T the buffer control word type (4 bit or 8 bit)
/// @tparam TT traits type defaults to cwTraits<T>
/// @tparam OT the TargetType of the CCS instruction
/// @param[in] i_target a DIMM target
/// @param[in] i_data control word data to send
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< control_word T, typename TT = cwTraits<T>, fapi2::TargetType OT >
fapi2::ReturnCode control_word_engine(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const cw_data& i_data,
                                      std::vector< ccs::instruction_t<OT> >& io_inst)
{
    ccs::instruction_t<OT> l_inst =  ccs::rcd_command<OT>(i_target);

    // RCW or BCW access is selected by A12
    constexpr uint64_t DDR_ADDRESS_12 = 12;
    l_inst.arr0.template writeBit<DDR_ADDRESS_12>(TT::CW_ACCESS);

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
    mss::swizzle < MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_0_13 + TT::DATA_LEN,
        TT::WORD_LEN, TT::SWIZZLE_START > (i_data.iv_number, l_inst.arr0);

    // For changes to the control word setting [...] the controller needs to wait some time
    // the last control word access, before further access to the DRAM can take place.
    l_inst.arr1.template insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES,
                         MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(i_data.iv_delay);

    FAPI_INF("F%d%s%02x%s value 0x%x (%d cycles) 0x%016llx:0x%016llx %s",
             uint8_t(i_data.iv_func_space),
             (TT::CW_ACCESS == 1 ? "BC" : "RC"),
             uint8_t(i_data.iv_number),
             (T == BCW_4BIT || T == RCW_4BIT ? "" : "X"),
             l_value,
             i_data.iv_delay,
             uint64_t(l_inst.arr0), uint64_t(l_inst.arr1),
             mss::c_str(i_target));

    io_inst.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Control word engine that sets the CCS instruction
/// @tparam T the buffer control word type (4 bit or 8 bit)
/// @tparam TT traits type defaults to cwTraits<T>
/// @tparam OT the TargetType of the CCS instruction
/// @param[in] i_target a DIMM target
/// @param[in] i_data_list a vector of control word data to send
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< control_word T, typename TT = cwTraits<T>, fapi2::TargetType OT >
fapi2::ReturnCode control_word_engine(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const std::vector<cw_data>& i_data_list,
                                      std::vector< ccs::instruction_t<OT> >& io_inst)
{
    if( i_data_list.empty() )
    {
        FAPI_ERR("%s. cw_data vector is empty!", mss::c_str(i_target) );
        fapi2::Assert(false);
    }

    for (const auto& data : i_data_list)
    {
        FAPI_TRY( control_word_engine<T>(i_target, data, io_inst) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

}// mss

#endif
