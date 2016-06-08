/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/fir/memdiags_fir.C $       */
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
/// @file memdiags_fir.C
/// @brief Subroutines for memdiags/prd FIR
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/utils/scom.H>
#include <lib/fir/memdiags_fir.H>

using fapi2::TARGET_TYPE_MCBIST;

namespace mss
{

///
/// @brief Unmask and setup actions for memdiags related FIR
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode unmask_memdiags_errors( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("unmask_memdiags_errors");

    // Fill our buffer with F's as we're going to clear the bits we want to
    // unmask and then drop the result in to the _AND register.
    fapi2::buffer<uint64_t> l_mcbistfir_mask(~0);
    fapi2::buffer<uint64_t> l_mcbistfir_action0;
    fapi2::buffer<uint64_t> l_mcbistfir_action1;

    FAPI_TRY( mss::getScom(i_target, MCBIST_MCBISTFIRACT0, l_mcbistfir_action0) );
    FAPI_TRY( mss::getScom(i_target, MCBIST_MCBISTFIRACT1, l_mcbistfir_action1) );

    // There's not much to do here right now as Marc needs to work out the new FIR
    // and whatnot for Nimbus. Lets make sure we setup everything as PRD needs it
    // for sim, and we'll circle back to add the other FIR as the design completes.

    // Don't unmask the main address skipped FIR. First, we rely on the skipping so
    // we probably don't want any one to see it and second it's broken per Shelton 5/16.

    // Unmask the program complete bit and setup the actions for an attention
    l_mcbistfir_action0.setBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>();
    l_mcbistfir_action1.clearBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>();
    l_mcbistfir_mask.clearBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>();

    // Hit the and register of the fir mask
    FAPI_TRY( mss::putScom(i_target, MCBIST_MCBISTFIRACT0, l_mcbistfir_action0) );
    FAPI_TRY( mss::putScom(i_target, MCBIST_MCBISTFIRACT1, l_mcbistfir_action1) );
    FAPI_TRY( mss::putScom(i_target, MCBIST_MCBISTFIRMASK_AND, l_mcbistfir_mask) );

fapi_try_exit:
    return fapi2::current_err;
}

}
