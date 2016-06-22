/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/adr32s.C $             */
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
/// @file adr32s.C
/// @brief Subroutines for the PHY ADR32S registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/phy/adr32s.H>

namespace mss
{

// Definition of the ADR32S DLL Config registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::DLL_CNFG_REG =
{
    MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0,
    MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S1
};

}

