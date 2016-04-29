/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/c_str.H $            */
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
/// @file c_str.H
/// @brief Function to return the C-string name of a thing
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_C_STR_H_
#define _MSS_C_STR_H_

#include <fapi2.H>

namespace mss
{

// Thread local storage for the string we're going to create.
extern thread_local char c_str_storage[fapi2::MAX_ECMD_STRING_LEN];

template< fapi2::TargetType T >
const char* c_str( const fapi2::template Target<T>& i_target )
{
    fapi2::toString( i_target, c_str_storage, fapi2::MAX_ECMD_STRING_LEN );
    return c_str_storage;
}

template<>
const char* c_str( const fapi2::template Target<fapi2::TARGET_TYPE_DIMM>& i_target );

}
#endif
