/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/scom.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file scom.H
/// @brief Tools related to scom operations
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Craig Hamilton <cchamilt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SCOM_H_
#define _MSS_SCOM_H_

#include <fapi2.H>

//
// Wrapping scom operations: We wrap fapi2::get/putScom for two reasons. The
// first is so that we can hook in to the base scom operations in the lab. This
// is expected to be used for test tracking and data gathering. The other
// reason is to facilitate sharing code with Z in the event they don't leverage
// fapi2. This gives us a place to define a common "hw access" API allowing
// P and Z to implement the underlying firmware API using different mechanisms.
//

namespace mss
{
/// @brief Reads a SCOM register from a chip.
/// @tparam K template parameter, passed in target.
/// @param[in]  i_target     HW target to operate on.
/// @param[in]  i_address    SCOM register address to read from.
/// @param[out] o_data       Buffer that holds data read from HW target.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
/// @note We wrap scom operations in the mss library so that we can hook
/// into them in the lab. For IPL firmware, this should compile out.
template< fapi2::TargetType K >
inline fapi2::ReturnCode getScom(const fapi2::Target<K>& i_target, const uint64_t i_address,
                                 fapi2::buffer<uint64_t>& o_data)
{
#ifdef PSYSTEMS_MSS_LAB_ONLY
    // Place holder for lab-hooks
    return fapi2::getScom(i_target, i_address, o_data);
#else
    return fapi2::getScom(i_target, i_address, o_data);
#endif
}

/// @brief Writes a SCOM register on a chip.
/// @tparam K template parameter, passed in target.
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
/// @note We wrap scom operations in the mss library so that we can hook
/// into them in the lab. For IPL firmware, this should compile out.
template< fapi2::TargetType K >
inline fapi2::ReturnCode putScom(const fapi2::Target<K>& i_target, const uint64_t i_address,
                                 const fapi2::buffer<uint64_t> i_data)
{
#ifdef PSYSTEMS_MSS_LAB_ONLY
    // Place holder for lab-hooks
    return fapi2::putScom(i_target, i_address, i_data);
#else
    return fapi2::putScom(i_target, i_address, i_data);
#endif
}

/// @brief Writes a SCOM register under mask on a chip
/// @tparam K template parameter, passed in target.
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @param[in] i_mask       Buffer that holds the mask value.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
/// @note We wrap scom operations in the mss library so that we can hook
/// into them in the lab. For IPL firmware, this should compile out.
template< fapi2::TargetType K >
inline fapi2::ReturnCode putScomUnderMask(const fapi2::Target<K>& i_target,
        const uint64_t i_address,
        const fapi2::buffer<uint64_t> i_data,
        const fapi2::buffer<uint64_t> i_mask)
{
#ifdef PSYSTEMS_MSS_LAB_ONLY
    // Place holder for lab-hooks
    return fapi2::putScomUnderMask(i_target, i_address, i_data, i_mask);
#else
    return fapi2::putScomUnderMask(i_target, i_address, i_data, i_mask);
#endif
}

}
#endif
