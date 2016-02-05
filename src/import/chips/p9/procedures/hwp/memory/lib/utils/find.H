/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/find.H $             */
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
/// @file find.H
/// @brief Templates for finding things
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_FIND_H
#define _MSS_FIND_H

#include <fapi2.H>

namespace mss
{

///
/// @brief find a set of elements based on a fapi2 target
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @return a vector of M targets.
///
template< fapi2::TargetType M, fapi2::TargetType T >
inline std::vector< fapi2::Target<M> > find_targets( const fapi2::Target<T>& );

///
/// @brief find an element based on a fapi2 target
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] the fapi2 target T
/// @return an M target.
///
template< fapi2::TargetType M, fapi2::TargetType T >
inline fapi2::Target<M> find_target( const fapi2::Target<T>& );

///
/// @brief find the McBIST given a McBIST
/// @param[in] i_self the fapi2 target mcBIST
/// @return a McBIST target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCBIST> find_target( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_self)
{
    return i_self;
}

///
/// @brief find the McBIST given a DIMM
/// @param[in] i_target the fapi2 target DIMM
/// @return a McBIST target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCBIST> find_target( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCA>().getParent<fapi2::TARGET_TYPE_MCBIST>();
}

///
/// @brief find the McBIST given a MCA
/// @param[in] i_target the fapi2 target MCA
/// @return a McBIST target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCBIST> find_target( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCBIST>();
}


///
/// @brief find all the dimm connected to an MCS
/// @param[in] i_target a fapi2::Target MCS
/// @return a vector of fapi2::TARGET_TYPE_DIMM
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > find_targets( const fapi2::Target<fapi2::TARGET_TYPE_MCS>&
        i_target )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > l_dimms;

    // At this time, fapi2 (cronus?) doesn't seem to recognize a DIMM is the child of an MCS.
    for (auto p : i_target.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        auto l_these_dimms( p.getChildren<fapi2::TARGET_TYPE_DIMM>() );
        l_dimms.insert(l_dimms.end(), l_these_dimms.begin(), l_these_dimms.end());
    }

    return l_dimms;
}

///
/// @brief find all the dimm connected to an MCBIST
/// @param[in] i_target a fapi2::Target MCBIST
/// @return a vector of fapi2::TARGET_TYPE_DIMM
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > find_targets( const
        fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > l_dimms;

    for (auto p : i_target.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        auto l_these_dimms( p.getChildren<fapi2::TARGET_TYPE_DIMM>() );
        l_dimms.insert(l_dimms.end(), l_these_dimms.begin(), l_these_dimms.end());
    }

    return l_dimms;
}

///
/// @brief find all the MCS connected to an MCBIST
/// @param[in] i_target a fapi2::Target MCBIST
/// @return a vector of fapi2::TARGET_TYPE_MCS
/// @note Cronus should support MCS children of an MCBIST - so this might be temporary
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> > find_targets( const
        fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> > l_mcses;

    // At this time, fapi2 (cronus?) doesn't seem to recognize a MCS is the child of an MCBIST
    for (auto p : i_target.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        fapi2::Target<fapi2::TARGET_TYPE_MCS> l_mcs = p.getParent<fapi2::TARGET_TYPE_MCS>();

        if ( l_mcses.end() == std::find_if( l_mcses.begin(), l_mcses.end(),
                                            [l_mcs](const fapi2::Target<fapi2::TARGET_TYPE_MCS>& c)
    {
        return l_mcs == c;
    }) )
        {
            l_mcses.push_back(l_mcs);
        }
    }

    return l_mcses;
}

///
/// @brief find the MCS given a DIMM
/// @param[in] i_target the fapi2 target DIMM
/// @return a MCS target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCS> find_target( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCA>().getParent<fapi2::TARGET_TYPE_MCS>();
}

///
/// @brief find the MCA given a DIMM
/// @param[in] i_target the fapi2 target DIMM
/// @return a MCA target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCA> find_target( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCA>();
}

}// mss

#endif
