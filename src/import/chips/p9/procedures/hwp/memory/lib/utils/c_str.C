/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/c_str.C $            */
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
/// @file c_str.C
/// @brief Storage for the C-string name of a thing
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Craig Hamilton <cchamilt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include <mss_attribute_accessors.H>
#include <fapi2.H>
#include "c_str.H"

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

// Thread local storage for the string we're going to create.
thread_local char c_str_storage[fapi2::MAX_ECMD_STRING_LEN];

template< fapi2::TargetType T >
char const* make_c_str_helper( char const* s, const fapi2::Target<T>& i_target);

template<>
char const* c_str<DEFAULT_KIND, TARGET_TYPE_DIMM>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target )
{
    return make_c_str_helper(" unknown dimm", i_target);
}

template<>
char const* c_str<KIND_RDIMM_DDR4, TARGET_TYPE_DIMM>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target )
{
    return make_c_str_helper(" rdimm (ddr4)", i_target);
}

template<>
char const* c_str<KIND_RDIMM_EMPTY, TARGET_TYPE_DIMM>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target )
{
    return make_c_str_helper(" rdimm (empty)", i_target);
}

template<>
char const* c_str<KIND_LRDIMM_DDR4, TARGET_TYPE_DIMM>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target )
{
    return make_c_str_helper(" lrdimm (ddr4)", i_target);
}

template<>
char const* c_str<KIND_LRDIMM_EMPTY, TARGET_TYPE_DIMM>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target )
{
    return make_c_str_helper(" lrdimm (empty)", i_target);
}

template<>
char const* c_str<FORCE_DISPATCH, TARGET_TYPE_DIMM>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target )
{
    uint8_t l_type = 0;
    uint8_t l_gen = 0;

    uint8_t l_value[2][2];
    auto l_mca = i_target.getParent<TARGET_TYPE_MCA>();
    auto l_mcs = l_mca.getParent<TARGET_TYPE_MCS>();

    // Had to unroll FAPI_TRY so that fapi2::current_err doesn't get overwritten, causes errors
    // when calling c_str inside of a function that returns fapi2::ReturnCode
    if (FAPI_ATTR_GET(fapi2::ATTR_EFF_DIMM_TYPE, l_mcs, l_value) != FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    l_type = l_value[mss::index(l_mca)][mss::index(i_target)];

    // Had to unroll FAPI_TRY so that fapi2::current_err doesn't get overwritten, causes errors
    // when calling c_str inside of a function that returns fapi2::ReturnCode
    if (FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_GEN, l_mcs, l_value) != FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    l_gen = l_value[mss::index(l_mca)][mss::index(i_target)];

    return c_str_dispatch<FORCE_DISPATCH, TARGET_TYPE_DIMM>(dimm_kind( l_type, l_gen ), i_target);

fapi_try_exit:
    // Probably the best we're going to do ...
    return "couldn't get dimm type, dram gen";
}

template< fapi2::TargetType T >
char const* make_c_str_helper( char const* s, const fapi2::Target<T>& i_target)
{
    fapi2::toString( i_target, c_str_storage, fapi2::MAX_ECMD_STRING_LEN );
    return strncat( c_str_storage, s, fapi2::MAX_ECMD_STRING_LEN - strlen(c_str_storage) );
}

}
