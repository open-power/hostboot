/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/eff_config/memory_size.C $ */
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
/// @file memory_size.C
/// @brief Return the effective memory size behind a target
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <mss_attribute_accessors.H>

#include <lib/shared/mss_const.H>
#include <lib/eff_config/memory_size.H>

namespace mss
{
///
/// @brief Return the total memory size behind an MCA
/// @param[in] i_target the MCA target
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode eff_memory_size( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, uint64_t& o_size )
{
    uint32_t l_sizes[PORTS_PER_MCS];
    o_size = 0;

    FAPI_TRY( mss::eff_dimm_size(i_target, &(l_sizes[0])) );

    for (size_t i = 0; i < PORTS_PER_MCS; ++i)
    {
        o_size += l_sizes[i];
    }

fapi_try_exit:
    return fapi2::current_err;
}

}

