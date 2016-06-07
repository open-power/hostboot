/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/scom.H $             */
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
/// @file scom.H
/// @brief Tools related to scom operations
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SCOM_H_
#define _MSS_SCOM_H_

#include <fapi2.H>
#include <lib/utils/c_str.H>

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

///
/// @brief Blast one peice of data across a vector of addresses
/// @param[in] i_target the target for the scom
/// @param[in] i_addrs const std::vector<uint64_t>& addresses
/// @param[in] i_data const fapi2::buffer<uint64_t>& the data to blast
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Author is originally from Boston (Pahk mah cah in Havahd Yahd)

/// @note std::transform might have been tidier, but because of the ReturnCode
/// and the FAPI_TRY mechanism, this is the simplest.
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_blastah( const fapi2::Target<T>& i_target, const std::vector<uint64_t>& i_addrs,
                                const fapi2::buffer<uint64_t>& i_data )
{
    size_t count(0);

    for (auto a : i_addrs)
    {
        FAPI_TRY( mss::putScom(i_target, a, i_data) );
        ++count;
    }

    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR( "scom_blastah failed: %d of %d executed against %s", count, i_addrs.size(), mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief Blast one peice of data across a vector of targets
/// @param[in]i_targets  the vector of targets for the scom
/// @param[in] i_addr the address
/// @param[in] i_data const fapi2::buffer<uint64_t>& the data to blast
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_blastah( const std::vector<fapi2::Target<T> >& i_targets, const uint64_t i_addr,
                                const fapi2::buffer<uint64_t>& i_data )
{
    size_t count(0);

    for (auto t : i_targets)
    {
        FAPI_TRY( mss::putScom(t, i_addr, i_data) );
        ++count;
    }

    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR( "scom_blastah failed: %d of %d written to 0x%llx", count, i_targets.size(), i_addr);
    return fapi2::current_err;
}

///
/// @brief Blast one peice of data across a vector of targets
/// @param[in]i_targets  the vector of targets for the scom
/// @param[in] i_addrs the vector of addresses
/// @param[in] i_data const fapi2::buffer<uint64_t>& the data to blast
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_blastah( const std::vector<fapi2::Target<T> >& i_targets,
                                const std::vector<uint64_t>& i_addrs,
                                const fapi2::buffer<uint64_t>& i_data )
{
    size_t count(0);

    for (auto t : i_targets)
    {
        FAPI_TRY( mss::scom_blastah(t, i_addrs, i_data) );
        ++count;
    }

    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR( "scom_blastah failed: %d of %dx%d", count, i_targets.size(), i_addrs.size() );
    return fapi2::current_err;
}


}
#endif
