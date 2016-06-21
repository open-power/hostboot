/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/ecc/mbs_error_vector_trap.H $ */
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
/// @file mbs_error_vector_trap.H
/// @brief Subroutines for the MC MBS error vector trap registers (MBSEVR*Q)
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MBS_ERROR_VECTOR_TRAP_H_
#define _MSS_MBS_ERROR_VECTOR_TRAP_H_

#include <fapi2.H>
#include <lib/utils/scom.H>
#include <lib/utils/find.H>
#include <lib/ecc/ecc_traits.H>

namespace mss
{

namespace ecc
{

namespace mbs_error_vector_trap
{

///
/// @brief Read MBS Error Vector Trap (MBSEVR*Q) register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    const auto& l_mcbist_target = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    FAPI_TRY( mss::getScom(l_mcbist_target, (TT::ERROR_VECTOR_REGS[l_port]), o_data) );
    FAPI_INF("read: 0x%016lx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write MBS Error Vector Trap (MBSEVR*Q) register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    const auto& l_mcbist_target = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    FAPI_TRY( mss::putScom(l_mcbist_target, (TT::ERROR_VECTOR_REGS[l_port]), i_data) );
    FAPI_INF("write: 0x%016lx", i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_nce_galois
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline void set_nce_galois( const fapi2::Target<T>& i_target,
                            fapi2::buffer<uint64_t>& io_data,
                            const uint64_t i_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // divide by 2 because each register holds info for a pair of ports
    if ((l_port % 2) == 0)
    {
        io_data.insertFromRight<TT::P0_NCE_GALOIS, TT::P0_NCE_GALOIS_LEN>(i_value);
    }
    else
    {
        io_data.insertFromRight<TT::P1_NCE_GALOIS, TT::P1_NCE_GALOIS_LEN>(i_value);
    }

    FAPI_INF("set_nce_galois: 0x%016lx", i_value);
}

///
/// @brief get_nce_galois
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline void get_nce_galois( const fapi2::Target<T>& i_target,
                            const fapi2::buffer<uint64_t>& i_data,
                            uint64_t& o_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // divide by 2 because each register holds info for a pair of ports
    if ((l_port % 2) == 0)
    {
        i_data.extractToRight<TT::P0_NCE_GALOIS, TT::P0_NCE_GALOIS_LEN>(o_value);
    }
    else
    {
        i_data.extractToRight<TT::P1_NCE_GALOIS, TT::P1_NCE_GALOIS_LEN>(o_value);
    }

    FAPI_INF("get_nce_galois: 0x%016lx", o_value);
}

///
/// @brief set_nce_magnitude
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline void set_nce_magnitude( const fapi2::Target<T>& i_target,
                               fapi2::buffer<uint64_t>& io_data,
                               const uint64_t i_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // divide by 2 because each register holds info for a pair of ports
    if ((l_port % 2) == 0)
    {
        io_data.insertFromRight<TT::P0_NCE_MAGNITUDE, TT::P0_NCE_MAGNITUDE_LEN>(i_value);
    }
    else
    {
        io_data.insertFromRight<TT::P1_NCE_MAGNITUDE, TT::P1_NCE_MAGNITUDE_LEN>(i_value);
    }

    FAPI_INF("set_nce_magnitude: 0x%016lx", i_value);
}

///
/// @brief get_nce_magnitude
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline void get_nce_magnitude( const fapi2::Target<T>& i_target,
                               const fapi2::buffer<uint64_t>& i_data,
                               uint64_t& o_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // divide by 2 because each register holds info for a pair of ports
    if ((l_port % 2) == 0)
    {
        i_data.extractToRight<TT::P0_NCE_MAGNITUDE, TT::P0_NCE_MAGNITUDE_LEN>(o_value);
    }
    else
    {
        i_data.extractToRight<TT::P1_NCE_MAGNITUDE, TT::P1_NCE_MAGNITUDE_LEN>(o_value);
    }

    FAPI_INF("get_nce_magnitude: 0x%016lx", o_value);
}

///
/// @brief set_tce_galois
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline void set_tce_galois( const fapi2::Target<T>& i_target,
                            fapi2::buffer<uint64_t>& io_data,
                            const uint64_t i_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // divide by 2 because each register holds info for a pair of ports
    if ((l_port % 2) == 0)
    {
        io_data.insertFromRight<TT::P0_TCE_GALOIS, TT::P0_TCE_GALOIS_LEN>(i_value);
    }
    else
    {
        io_data.insertFromRight<TT::P1_TCE_GALOIS, TT::P1_TCE_GALOIS_LEN>(i_value);
    }

    FAPI_INF("set_tce_galois: 0x%016lx", i_value);
}

///
/// @brief get_tce_galois
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline void get_tce_galois( const fapi2::Target<T>& i_target,
                            const fapi2::buffer<uint64_t>& i_data,
                            uint64_t& o_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // divide by 2 because each register holds info for a pair of ports
    if ((l_port % 2) == 0)
    {
        i_data.extractToRight<TT::P0_TCE_GALOIS, TT::P0_TCE_GALOIS_LEN>(o_value);
    }
    else
    {
        i_data.extractToRight<TT::P1_TCE_GALOIS, TT::P1_TCE_GALOIS_LEN>(o_value);
    }

    FAPI_INF("get_tce_galois: 0x%016lx", o_value);
}

///
/// @brief set_tce_magnitude
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline void set_tce_magnitude( const fapi2::Target<T>& i_target,
                               fapi2::buffer<uint64_t>& io_data,
                               const uint64_t i_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // divide by 2 because each register holds info for a pair of ports
    if ((l_port % 2) == 0)
    {
        io_data.insertFromRight<TT::P0_TCE_MAGNITUDE, TT::P0_TCE_MAGNITUDE_LEN>(i_value);
    }
    else
    {
        io_data.insertFromRight<TT::P1_TCE_MAGNITUDE, TT::P1_TCE_MAGNITUDE_LEN>(i_value);
    }

    FAPI_INF("set_tce_magnitude: 0x%016lx", i_value);
}

///
/// @brief get_tce_magnitude
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline void get_tce_magnitude( const fapi2::Target<T>& i_target,
                               const fapi2::buffer<uint64_t>& i_data,
                               uint64_t& o_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // divide by 2 because each register holds info for a pair of ports
    if ((l_port % 2) == 0)
    {
        i_data.extractToRight<TT::P0_TCE_MAGNITUDE, TT::P0_TCE_MAGNITUDE_LEN>(o_value);
    }
    else
    {
        i_data.extractToRight<TT::P1_TCE_MAGNITUDE, TT::P1_TCE_MAGNITUDE_LEN>(o_value);
    }

    FAPI_INF("get_tce_magnitude: 0x%016lx", o_value);
}

} // close namespace mbs_error_vector_trap

} // close namespace ecc

} // close namespace mss

#endif
