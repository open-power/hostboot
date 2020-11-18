/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/scom.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file scom.H
/// @brief Tools related to scom operations
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SCOM_H_
#define _MSS_SCOM_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>

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
inline fapi2::ReturnCode getScom(const fapi2::Target<K>& i_target,
                                 const uint64_t i_address,
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
inline fapi2::ReturnCode putScom(const fapi2::Target<K>& i_target,
                                 const uint64_t i_address,
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
fapi2::ReturnCode scom_blastah( const fapi2::Target<T>& i_target,
                                const std::vector<uint64_t>& i_addrs,
                                const fapi2::buffer<uint64_t>& i_data )
{
    size_t count(0);

    for (const auto& a : i_addrs)
    {
        FAPI_TRY( mss::putScom(i_target, a, i_data) );
        ++count;
    }

    // Don't return current_err, if there are no registers in the vector we don't set it.
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR( "scom_blastah failed: %d of %d executed against %s", count, i_addrs.size(), mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief Blast one peice of data across a vector of targets
/// @param[in] i_targets  the vector of targets for the scom
/// @param[in] i_addr the address
/// @param[in] i_data const fapi2::buffer<uint64_t>& the data to blast
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_blastah( const std::vector<fapi2::Target<T> >& i_targets,
                                const uint64_t i_addr,
                                const fapi2::buffer<uint64_t>& i_data )
{
    size_t count(0);

    for (const auto& t : i_targets)
    {
        FAPI_TRY( mss::putScom(t, i_addr, i_data) );
        ++count;
    }

    // Don't return current_err, if there are no targets in the vector we don't set it.
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR( "scom_blastah failed: %d of %d written to 0x%llx", count, i_targets.size(), i_addr);
    return fapi2::current_err;
}

///
/// @brief Blast one peice of data across a vector of targets
/// @param[in] i_targets  the vector of targets for the scom
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

    for (const auto& t : i_targets)
    {
        FAPI_TRY( mss::scom_blastah(t, i_addrs, i_data) );
        ++count;
    }

    // Don't return current_err, if there are no targets in the vector we don't set it.
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR( "scom_blastah failed: %d of %dx%d", count, i_targets.size(), i_addrs.size() );
    return fapi2::current_err;
}

///
/// @brief Blast parallel vectors of data and addresses to a single target
/// @param[in] i_target the target for the scom
/// @param[in] i_addrs const std::vector<uint64_t>& addresses
/// @param[in] i_data std:vector<fapi2::buffer<uint64_t>>& the data to blast
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_blastah( const fapi2::Target<T>& i_targets,
                                const std::vector<uint64_t>& i_addrs,
                                const std::vector<fapi2::buffer<uint64_t>>& i_data )
{
    size_t count(0);

    // Little sanity check
    if (i_data.size() != i_addrs.size())
    {
        FAPI_ERR("Passed bad vectors in to scom_blastah: %d and %d in size", i_data.size(), i_addrs.size() );
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    auto l_address = i_addrs.begin();
    auto l_data = i_data.begin();

    for ( ; l_address != i_addrs.end(); ++l_address, ++l_data )
    {
        FAPI_TRY( mss::putScom(i_targets, *l_address, *l_data) );
        ++count;
    }

    // Don't return current_err, if there are no registers in the vector we don't set it.
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR( "parallel scom_blastah failed: %d of %d", count, i_addrs.size() );
    return fapi2::current_err;
}

///
/// @brief Blast parallel vectors of data and address pairs to a single target
/// @param[in] i_target the target for the scom
/// @param[in] i_addrs const std::vector<uint64_t>& of address pairs
/// @param[in] i_data std::vector< std::pair<uint64_t, uint64_t>> the data to blast
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_blastah( const fapi2::Target<T>& i_targets,
                                const std::vector< std::pair< uint64_t, uint64_t> >& i_addrs,
                                const std::vector< std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> > >& i_data )
{
    size_t count(0);

    // Little sanity check
    if (i_data.size() != i_addrs.size())
    {
        FAPI_ERR("Passed bad vectors of pairs in to scom_blastah: %d and %d in size", i_data.size(), i_addrs.size() );
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    auto l_address = i_addrs.begin();
    auto l_data = i_data.begin();

    for ( ; l_address != i_addrs.end(); ++l_address, ++l_data )
    {
        FAPI_TRY( mss::putScom(i_targets, l_address->first,  l_data->first) );
        FAPI_TRY( mss::putScom(i_targets, l_address->second, l_data->second) );
        ++count;
    }

    // Don't return current_err, if there are no registers in the vector we don't set it.
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR( "parallel pairs scom_blastah failed: %d of %d", count, i_addrs.size() );
    return fapi2::current_err;
}

///
/// @brief Blast single data data to a vector of address pairs to a single target
/// @param[in] i_target the target for the scom
/// @param[in] i_addrs const std::vector< std::pair<uint64_t, uint64_t> >& of address pairs
/// @param[in] i_data uint64_t the data to blast
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_blastah( const fapi2::Target<T>& i_targets,
                                const std::vector< std::pair< uint64_t, uint64_t> >& i_addr,
                                const fapi2::buffer<uint64_t>& i_data )
{
    size_t count(0);

    for (auto a = i_addr.begin(); a != i_addr.end(); ++a)
    {
        FAPI_TRY( mss::putScom(i_targets, a->first, i_data) );
        FAPI_TRY( mss::putScom(i_targets, a->second, i_data) );
        ++count;
    }

    // Don't return current_err, if there are no registers in the vector we don't set it.
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR( "pairs scom_blastah failed: %d of %d", count, i_addr.size() );
    return fapi2::current_err;
}

///
/// @brief Suck one peice of data from a vector of addresses
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target for the scom
/// @param[in] i_addr the vector of addresses
/// @param[in] o_data std::vector<uint64_t> the resulting data
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Author is originally from Boston (Pahk mah cah in Havahd Yahd)
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_suckah( const fapi2::Target<T>& i_target,
                               const std::vector<uint64_t>& i_addr,
                               std::vector< fapi2::buffer<uint64_t> >& o_data )
{
    size_t count(0);
    fapi2::buffer<uint64_t> l_read;

    o_data.clear();

    for (const auto& a : i_addr)
    {
        FAPI_TRY( mss::getScom(i_target, a, l_read) );
        o_data.push_back(l_read);
        ++count;
    }

    // Don't return current_err, if there are no registers in the vector we don't set it.
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR( "scom_suckah failed: %d of %d executed against %s", count, i_addr.size(), mss::c_str(i_target));
    return fapi2::current_err;
}


///
/// @brief Suck one peice of data from a vector of address pairs
/// @tparam T the fapi2::TargetType of the target
/// @tparam B a begin iterator
/// @tparam E an end iterator
/// @param[in] i_target the target for the scom
/// @param[in] i_addr a vector of address pairs
/// @param[in] o_data std::vector< std::pair<uint64_t, uint64_t>> the resulting data
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Author is originally from Boston (Pahk mah cah in Havahd Yahd)
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_suckah( const fapi2::Target<T>& i_target,
                               const std::vector< std::pair< uint64_t, uint64_t> >& i_addr,
                               std::vector< std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> > >& o_data )
{
    size_t count(0);
    std::pair< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> > l_read;

    o_data.clear();

    for (const auto& a : i_addr)
    {
        FAPI_TRY( mss::getScom(i_target, a.first, l_read.first) );
        FAPI_TRY( mss::getScom(i_target, a.second, l_read.second) );
        o_data.push_back( l_read );
        ++count;
    }

    // Don't return current_err, if there are no registers in the vector we don't set it.
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR( "scom_suckah failed: %d of %d executed against %s", count, i_addr.size(), mss::c_str(i_target));
    return fapi2::current_err;
}


}
#endif
