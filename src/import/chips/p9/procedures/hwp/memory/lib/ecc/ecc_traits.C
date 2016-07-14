/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/ecc/ecc_traits.C $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file ecc_traits.C
/// @brief Traits class for the MC ECC syndrome registers
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/ecc/ecc_traits.H>

namespace mss
{

// we need these declarations here in order for the linker to see the definitions
// in the eccTraits class
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::MAINLINE_NCE_REGS[];
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::MAINLINE_RCE_REGS[];
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::MAINLINE_MPE_REGS[];
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::MAINLINE_UE_REGS[];
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::MAINLINE_AUE_REGS[];
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::ERROR_VECTOR_REGS[];

constexpr const uint8_t eccTraits<fapi2::TARGET_TYPE_MCA>::symbol2galois[];
constexpr const uint8_t eccTraits<fapi2::TARGET_TYPE_MCA>::symbol2dq[];

} // close namespace mss
