/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/dimm/mrs_load_ddr4.H $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file mrs_load_ddr4.H
/// @brief Code to support mrs_load_ddr4
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Bill Hoffa <wghoffa@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MRS_LOAD_DDR4_H_
#define _MSS_MRS_LOAD_DDR4_H_

#include <fapi2.H>
#include <mss.H>

namespace mss
{

// Map bits in the ARR0 register(s) to MRS address bits. Should be traits related to ARR0. BRS
enum address_bits
{
    A0 = 0,
    A1 = 1,
    A2 = 2,
    A3 = 3,
    A4 = 4,
    A5 = 5,
    A6 = 6,
    A7 = 7,
    A8 = 8,
    A9 = 9,
    A10 = 10,
    A11 = 11,
    A12 = 12,
    A13 = 13,
    A14 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_14,
    A15 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_15,
    A16 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_16,
    A17 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_17,

    // Only kind of address bits ... <shrug>
    BA0 = 17,
    BA1 = 18,
    BG0 = 19,
    BG1 = 15,
};

///
/// @brief Perform the mrs_load_ddr4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] i_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrs_load_ddr4( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst);

///
/// @brief Mirror (front to back) the ADR bits of a CCS instruction - implementation
/// @tparam T typename of the ccs::instruction_t
/// @param[in, out] io_inst reference to a CCS instruction to be mirrored
/// @return FAPI2_RC_SUCESS iff ok
/// @note written this way so this is easier to test
///
template<fapi2::TargetType T>
void address_mirror_impl(ccs::instruction_t<T>& io_inst)
{
    // Nothing fancy here, just mirror the bits we're told to mirror in Table 14 — Address Mirroring and Inversion
    mss::template swap<A3, A4>(io_inst.arr0);
    mss::template swap<A5, A6>(io_inst.arr0);
    mss::template swap<A7, A8>(io_inst.arr0);
    mss::template swap<A11, A13>(io_inst.arr0);
    mss::template swap<BA0, BA1>(io_inst.arr0);
    mss::template swap<BG0, BG1>(io_inst.arr0);
}

///
/// @brief Mirror (front to back) the ADR bits of a CCS instruction
/// @tparam T typename of the ccs::instruction_t
/// @param[in] i_target target to use to get mirroring attribute
/// @param[in] i_rank the rank in question
/// @param[in, out] io_inst reference to a CCS instruction to be mirrored
/// @return FAPI2_RC_SUCESS iff ok
/// @note assumes the input is from an even number rank
///
template<fapi2::TargetType T>
fapi2::ReturnCode address_mirror(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_rank, ccs::instruction_t<T>& io_inst)
{
    // We only mirror if the mirroring attribute is set.
    uint8_t l_mirror = 0;
    FAPI_TRY( eff_dimm_rcd_mirror_mode(i_target, l_mirror) );

    // We only mirror odd ranks.
    if ((l_mirror == fapi2::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_ON) && (i_rank & 0x1))
    {
        address_mirror_impl(io_inst);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Invert (side to side) the ADR bits of a CCS instruction
/// @param[in] i_inst const reference to a CCS instruction.
/// @return[out] ccs instruction with the ADR bits inverted (side-to-side)
///
template<fapi2::TargetType T>
ccs::instruction_t<T> address_invert(const ccs::instruction_t<T>& i_inst)
{
    // Copy the input as the output doesn't all change.
    ccs::instruction_t<T> i_out(i_inst);

    // Nothing fancy here, just negate the bits we're told to negate in Table 14 — Address Mirroring and Inversion
    mss::template negate<A3>(i_out.arr0);
    mss::template negate<A4>(i_out.arr0);
    mss::template negate<A5>(i_out.arr0);
    mss::template negate<A6>(i_out.arr0);
    mss::template negate<A7>(i_out.arr0);
    mss::template negate<A8>(i_out.arr0);
    mss::template negate<A9>(i_out.arr0);

    mss::template negate<A11>(i_out.arr0);
    mss::template negate<A13>(i_out.arr0);
    mss::template negate<A17>(i_out.arr0);

    mss::template negate<BA0>(i_out.arr0);
    mss::template negate<BA1>(i_out.arr0);
    mss::template negate<BG0>(i_out.arr0);
    mss::template negate<BG1>(i_out.arr0);

    return i_out;
}

} // namespace
#endif
