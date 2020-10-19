/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/control_word_ddr4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file control_word_ddr4.H
/// @brief Run and manage the DDR4 control words for the RCD and data buffers
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB


#ifndef _GENERIC_DDR4_CONTROL_WORD_H_
#define _GENERIC_DDR4_CONTROL_WORD_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <generic/memory/lib/ccs/ccs.H>

namespace mss
{

static constexpr uint64_t CW4_DATA_LEN = 4;
static constexpr uint64_t CW8_DATA_LEN = 8;

///
/// @brief Control word types
///
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
    /// @brief default dtor
    ///
    ~cw_data() = default;

    ///
    /// @brief default ctor
    ///
    cw_data() = default;

    ///
    /// @brief ctor for attribute driven data
    /// @param[in] i_func_space the function space number
    /// @param[in] i_number register control word number
    /// @param[in] i_func attribute accessor function pointer
    /// @param[in] i_delay delay in cycles after current RCW
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
    /// @param[in] i_func_space the function space number
    /// @param[in] i_number register control word number
    /// @param[in] i_data RCW data to write
    /// @param[in] i_delay delay in cycles after current RCW
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
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to cwTraits<T>
/// @tparam CCS traits type defaults to ccsTraits<MC>
/// @param[in] i_target a DIMM target
/// @param[in] i_data control word data to send
/// @param[in] i_sim true if in simulation mode
/// @param[in] i_turn_on_cke flag that states whether we want CKE on for this RCW
/// @param[out] o_instruction CCS instruction we created
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< control_word T, mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = cwTraits<T>, typename CCS = ccsTraits<MC> >
fapi2::ReturnCode control_word_engine(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const cw_data& i_data,
                                      const bool i_sim,
                                      const bool i_turn_on_cke,
                                      ccs::instruction_t& o_instruction)
{
    // You're probably asking "Why always turn off CKE's? What is this madness?"
    // Well, due to a vendor sensitivity, we need to have the CKE's off until we run RC09 at the very end
    // Unfortunately, we need to have the CKE's off on the DIMM we are running second
    // We also don't want to turn off the CKE's on the DIMM we are running first
    // Therefore, we want to setup all RCW commands to have CKE's off across both DIMM's
    // We then manually turn on the CKE's associated with a specific DIMM
    constexpr bool CKE_OFF = false;
    ccs::instruction_t l_inst = ccs::rcd_command(i_target, i_sim, CKE_OFF);

    // Turn on the CKE's for the ranks we're not touching, if it's needed
    // Note: we only have the whole CKE field, not the per DIMM one by default
    constexpr uint8_t CKE_PER_DIMM = 2;
    const uint64_t CKE_START = CCS::ARR0_DDR_CKE + (mss::index(i_target) * CKE_PER_DIMM);
    FAPI_TRY(l_inst.arr0.writeBit(i_sim || i_turn_on_cke, CKE_START, CKE_PER_DIMM));

    // Run everything else
    {

        // A12 is the RCW/ BCW selector
        l_inst.arr0.template writeBit<CCS::DDR_ADDRESS_12>(TT::CW_ACCESS);

        // For user defined data, iv_data is user defined and iv_attr_get is a NO-OP
        // For attribute defined data, iv_attr_get will define data and l_value initialization is overwritten
        // I need l_value integral because the attribute accessor template deduction doesn't let me use buffers
        // and since I'm passing in bcw data as const I can't pass in iv_data to the attribute accessor
        // which would break const correctness
        uint8_t l_value = i_data.iv_data;
        FAPI_TRY( i_data.iv_attr_get(i_target, l_value) );

        // Data to be written into the configuration registers
        // 4-bit control are contained in bits DA0 thorugh DA3
        // 8-bit control are contained in bits DA0 thorugh DA7
        mss::swizzle< CCS::ARR0_DDR_ADDRESS_0_13,
            TT::DATA_LEN, TT::SWIZZLE_START >(fapi2::buffer<uint8_t>(l_value), l_inst.arr0);

        // Selection of each word of control bits
        mss::swizzle < CCS::ARR0_DDR_ADDRESS_0_13 + TT::DATA_LEN,
            TT::WORD_LEN, TT::SWIZZLE_START > (i_data.iv_number, l_inst.arr0);

        // For changes to the control word setting [...] the controller needs to wait some time
        // the last control word access, before further access to the DRAM can take place.
        l_inst.arr1.template insertFromRight<CCS::ARR1_IDLES,
                             CCS::ARR1_IDLES_LEN>(i_data.iv_delay);

        FAPI_INF("F%d%s%02x%s value 0x%x (%d cycles) 0x%016llx:0x%016llx %s",
                 uint8_t(i_data.iv_func_space),
                 (TT::CW_ACCESS == 1 ? "BC" : "RC"),
                 uint8_t(i_data.iv_number),
                 (T == BCW_4BIT || T == RCW_4BIT ? "" : "X"),
                 l_value,
                 i_data.iv_delay,
                 uint64_t(l_inst.arr0), uint64_t(l_inst.arr1),
                 mss::c_str(i_target));
    }

    // All setup now, output it
    o_instruction = l_inst;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Control word engine that sets the CCS instruction
/// @tparam T the buffer control word type (4 bit or 8 bit)
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to cwTraits<T>
/// @tparam CCS traits type defaults to ccsTraits<MC>
/// @param[in] i_target a DIMM target
/// @param[in] i_data control word data to send
/// @param[in] i_sim true if in simulation mode
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @param[in] i_turn_on_cke flag that states whether we want CKE on for this RCW (defaulted to true)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< control_word T, mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = cwTraits<T>, typename CCS = ccsTraits<MC> >
fapi2::ReturnCode control_word_engine(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const cw_data& i_data,
                                      const bool i_sim,
                                      std::vector< ccs::instruction_t >& io_inst,
                                      const bool i_turn_on_cke = true)
{
    ccs::instruction_t l_inst;
    FAPI_TRY(control_word_engine<T>(i_target, i_data, i_sim, i_turn_on_cke, l_inst));
    io_inst.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Control word engine that sets the CCS instruction
/// @tparam T the buffer control word type (4 bit or 8 bit)
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to cwTraits<T>
/// @tparam CCS traits type defaults to ccsTraits<MC>
/// @param[in] i_target a DIMM target
/// @param[in] i_data_list a vector of control word data to send
/// @param[in] i_sim true if in simulation mode
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @param[in] i_turn_on_cke flag that states whether we want CKE on for all RCWs in the vector (defaulted to true)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< control_word T, mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = cwTraits<T>, typename CCS = ccsTraits<MC> >
fapi2::ReturnCode control_word_engine(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const std::vector<cw_data>& i_data_list,
                                      const bool i_sim,
                                      std::vector< ccs::instruction_t >& io_inst,
                                      const bool i_turn_on_cke = true)
{
    FAPI_ASSERT( !i_data_list.empty(),
                 fapi2::MSS_EMPTY_VECTOR().
                 set_FUNCTION(CW_DATA_ENGINE).
                 set_TARGET(i_target),
                 "%s. cw_data vector is empty!", mss::c_str(i_target) );

    for (const auto& data : i_data_list)
    {
        FAPI_TRY( control_word_engine<T>(i_target, data, i_sim, io_inst, i_turn_on_cke) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

/////////////////////////////////////////////////
// Now for the API related to CW information
/////////////////////////////////////////////////

///
/// @class cw_info
/// @brief class that represents (register/buffer) control word data as well as length and RCW vs BCW
/// @note used to store all CW data to move the knowledge of 4-bit vs 8-bit to runtime
///
struct cw_info
{
// Values of A12 which determines BCW vs RCW
// A12 is 1 for BCW and 0 for RCW
    static constexpr bool BCW = true;
    static constexpr bool RCW = false;

    // CW data
    cw_data iv_cw_data;

    // Data length 4 vs 8 bits
    uint64_t iv_data_len;

    // Boolean that controls BCW vs RCW - true if BCW
    bool iv_is_bcw;

    ///
    /// @brief default dtor
    ///
    ~cw_info() = default;

    ///
    /// @brief default ctor
    ///
    cw_info() = default;

    ///
    /// @brief ctor for attribute driven data
    /// @param[in] i_func_space the function space number
    /// @param[in] i_number register control word number
    /// @param[in] i_func attribute accessor function pointer
    /// @param[in] i_delay delay in cycles after current RCW
    /// @param[in] i_data_len data length
    /// @param[in] i_bcw buffer control word
    ///
    cw_info( const uint64_t i_func_space,
             const uint64_t i_number,
             fapi2::ReturnCode (*i_func)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, uint8_t&),
             const uint64_t i_delay,
             const uint64_t i_data_len,
             const bool i_bcw ):
        iv_cw_data(i_func_space, i_number, i_func, i_delay),
        iv_data_len(i_data_len),
        iv_is_bcw(i_bcw)
    {}

    ///
    /// @brief ctor for custom data
    /// @param[in] i_func_space the function space number
    /// @param[in] i_number register control word number
    /// @param[in] i_data RCW data to write
    /// @param[in] i_delay delay in cycles after current RCW
    /// @param[in] i_data_len data length
    /// @param[in] i_bcw buffer control word
    ///
    cw_info( const uint64_t i_func_space,
             const uint64_t i_number,
             const uint64_t i_data,
             const uint64_t i_delay,
             const uint64_t i_data_len,
             const bool i_bcw ):
        iv_cw_data(i_func_space, i_number, i_data, i_delay),
        iv_data_len(i_data_len),
        iv_is_bcw(i_bcw)
    {}

};

///
/// @brief Control word engine that sets the CCS instruction
/// @param[in] i_target a DIMM target
/// @param[in] i_info control word data and information about how to send it
/// @param[in] i_sim true if in simulation mode
/// @param[in] i_turn_on_cke flag that states whether we want CKE on for this RCW
/// @param[out] o_instruction CCS instruction we created
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode control_word_engine(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const cw_info& i_info,
        const bool i_sim,
        const bool i_turn_on_cke,
        ccs::instruction_t& o_instruction)
{
    // BCW 4-bit
    if(i_info.iv_is_bcw && i_info.iv_data_len == CW4_DATA_LEN)
    {
        FAPI_TRY(control_word_engine<BCW_4BIT>(i_target, i_info.iv_cw_data, i_sim, i_turn_on_cke, o_instruction));
    }
    // BCW 8-bit
    else if(i_info.iv_is_bcw && i_info.iv_data_len == CW8_DATA_LEN)
    {
        FAPI_TRY(control_word_engine<BCW_8BIT>(i_target, i_info.iv_cw_data, i_sim, i_turn_on_cke, o_instruction));
    }
    // RCW 4-bit
    else if(!i_info.iv_is_bcw && i_info.iv_data_len == CW4_DATA_LEN)
    {
        FAPI_TRY(control_word_engine<RCW_4BIT>(i_target, i_info.iv_cw_data, i_sim, i_turn_on_cke, o_instruction));
    }
    // RCW 8-bit
    else if(!i_info.iv_is_bcw && i_info.iv_data_len == CW8_DATA_LEN)
    {
        FAPI_TRY(control_word_engine<RCW_8BIT>(i_target, i_info.iv_cw_data, i_sim, i_turn_on_cke, o_instruction));
    }
    // Error case
    else
    {
        FAPI_ASSERT(false,
                    fapi2::MSS_INVALID_CW_ENCODING()
                    .set_CW_DATA_LEN(i_info.iv_data_len)
                    .set_BCW(i_info.iv_is_bcw)
                    .set_TARGET(i_target),
                    "%s data_len: %u and %s are an invalid combination",
                    mss::c_str(i_target), i_info.iv_data_len, i_info.iv_is_bcw ? "BCW" : "RCW");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Control word engine that sets the CCS instruction
/// @param[in] i_target a DIMM target
/// @param[in] i_info_list a vector of control word data to send
/// @param[in] i_sim true if in simulation mode
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @param[in] i_turn_on_cke flag that states whether we want CKE on for all RCWs in the vector (defaulted to true)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode control_word_engine(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::vector<cw_info>& i_info_list,
        const bool i_sim,
        std::vector< ccs::instruction_t >& io_inst,
        const bool i_turn_on_cke = true)
{
    FAPI_ASSERT( !i_info_list.empty(),
                 fapi2::MSS_EMPTY_VECTOR().
                 set_FUNCTION(CW_INFO_ENGINE).
                 set_TARGET(i_target),
                 "%s. cw_info vector is empty!", mss::c_str(i_target) );

    for (const auto& l_info : i_info_list)
    {
        ccs::instruction_t l_inst;
        FAPI_TRY( control_word_engine(i_target, l_info, i_sim, i_turn_on_cke, l_inst) );
        io_inst.push_back(l_inst);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Modifies the supplied CW to be in or out of address inversion mode
/// @param[in,out] io_rc00 the RCW that contains address inversion
/// @param[in] i_inversion_enable true if inversion is enabled
/// @note Passed values should be OFF_N or ON_N
///
inline void set_address_inversion(cw_data& io_rc00, const mss::states i_inversion_enable)
{
    // Bit 0 is the inversion enable
    // Note: the bits are actually in JEDEC order, so bit 0 is on the far right
    constexpr uint64_t INVERSION_BIT = 7;

    // Values should be OFF_N or ON_N
    io_rc00.iv_data.template writeBit<INVERSION_BIT>(i_inversion_enable);
}

///
/// @brief Decode the provided CW_INFO object and run control_word_engine
///
/// @param[in] i_target DIMM target
/// @param[in] i_sim Simulation true/false
/// @param[in] i_cw_info control word data
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
inline fapi2::ReturnCode decode_rcw_and_run_engine(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const bool i_sim,
    const cw_info& i_cw_info,
    std::vector< ccs::instruction_t >& io_inst)
{
    fapi2::buffer<uint8_t> l_f0rc2x_data;
    fapi2::buffer<uint8_t> l_f0rc4x_data;
    fapi2::buffer<uint8_t> l_f0rc6x_data;
    fapi2::buffer<uint8_t> l_f0rc06_data;

    std::vector<cw_info> l_info_list;

    static constexpr bool TURN_ON_CKE = true;

    // F0RC2X constants
    static constexpr uint8_t F0RC2X_F0RC4X_CW_SOURCE_BIT = 2;

    // F0RC4X constants
    static constexpr uint8_t F0RC4X_FUNC_SPACE_START = 0;
    static constexpr uint8_t F0RC4X_FUNC_SPACE_LEN = 3;
    static constexpr uint8_t F0RC4X_A12_BIT = 3;
    static constexpr uint8_t F0RC4X_NUMBER_START = 4;
    static constexpr uint8_t F0RC4X_NUMBER_LEN = 4;

    // F0RC06 constants
    static constexpr uint8_t F0RC06_CMD_WRITE = 0x05;

    // F0RC6X constants
    static constexpr uint8_t F0RC6X_A7A4_START = 0;
    static constexpr uint8_t F0RC6X_A7A4_LEN = 4;

    // Misc constants
    static constexpr uint8_t FUNCTION_SPACE_0 = 0;
    static constexpr uint8_t FUNCTION_SPACE_8 = 8;
    static constexpr uint8_t CW_2 = 2;
    static constexpr uint8_t CW_4 = 4;
    static constexpr uint8_t CW_6 = 6;
    static constexpr uint8_t DATA_LEN_4 = 4;
    static constexpr uint8_t DATA_LEN_8 = 8;

    // F0RC2X:
    // We don't have any attribute for this, so we aren't starting with any non-zero default
    l_f0rc2x_data.writeBit<F0RC2X_F0RC4X_CW_SOURCE_BIT>(
        i_cw_info.iv_cw_data.iv_func_space >= FUNCTION_SPACE_8);

    // Construct F0RC2X
    l_info_list.push_back(cw_info(FUNCTION_SPACE_0,
                                  CW_2,
                                  l_f0rc2x_data,
                                  i_cw_info.iv_cw_data.iv_delay,
                                  CW8_DATA_LEN,
                                  i_cw_info.iv_is_bcw));

    // F0RC4X:
    // [7:5] Func Space
    l_f0rc4x_data.insertFromRight<F0RC4X_FUNC_SPACE_START, F0RC4X_FUNC_SPACE_LEN>
    (i_cw_info.iv_cw_data.iv_func_space % FUNCTION_SPACE_8);

    // [4] A12
    l_f0rc4x_data.writeBit<F0RC4X_A12_BIT>(i_cw_info.iv_is_bcw);

    // [3:0] iv_number
    l_f0rc4x_data.insertFromRight<F0RC4X_NUMBER_START, F0RC4X_NUMBER_LEN>
    ((i_cw_info.iv_data_len == DATA_LEN_8) ? i_cw_info.iv_cw_data.iv_number : 0);

    // Construct F0RC4X
    l_info_list.push_back(cw_info(FUNCTION_SPACE_0,
                                  CW_4,
                                  l_f0rc4x_data,
                                  i_cw_info.iv_cw_data.iv_delay,
                                  CW8_DATA_LEN,
                                  i_cw_info.iv_is_bcw));

    // F0RC6X:
    // Set up using RCW's data
    fapi2::buffer<uint8_t> l_f0rc6x_data(i_cw_info.iv_cw_data.iv_data);

    // Overwrite A7-A4 with iv_number for DATA_LEN_4 CWs
    if (i_cw_info.iv_data_len == DATA_LEN_4)
    {
        l_f0rc6x_data.insert<F0RC6X_A7A4_START, F0RC6X_A7A4_LEN>(i_cw_info.iv_cw_data.iv_number);
    }

    l_info_list.push_back(cw_info(FUNCTION_SPACE_0,
                                  CW_6,
                                  l_f0rc6x_data,
                                  i_cw_info.iv_cw_data.iv_delay,
                                  CW8_DATA_LEN,
                                  i_cw_info.iv_is_bcw));

    // F0RC06 - RCD_WRITE:
    fapi2::buffer<uint8_t> l_f0rc06_data(F0RC06_CMD_WRITE);
    l_info_list.push_back(cw_info(FUNCTION_SPACE_0,
                                  CW_6,
                                  l_f0rc06_data,
                                  i_cw_info.iv_cw_data.iv_delay,
                                  CW4_DATA_LEN,
                                  i_cw_info.iv_is_bcw));

    // Issue command
    return control_word_engine(i_target, l_info_list, i_sim, io_inst, TURN_ON_CKE);
}

}// mss

#endif
