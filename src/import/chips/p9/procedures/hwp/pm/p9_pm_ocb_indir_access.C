/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_ocb_indir_access.C $        */
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
/// @file p9_pm_ocb_indir_access.C
/// @brief Performs the data transfer to/from an OCB indirect channel

// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP Backup HWP Owner:
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS

///
/// High-level procedure flow:
/// @verbatim
///
///     Per HW220256, for Murano DD1, a push (Put) must first check for non-full
///     condition to avoid a data corruption scenario.  This is fixed in
///     Venice DD1.
/// @endverbatim
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm.H>
#include <p9_pm_ocb_indir_access.H>


// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

enum
{
    OCB_FULL_POLL_MAX = 4,
    OCB_FULL_POLL_DELAY_HDW = 0,
    OCB_FULL_POLL_DELAY_SIM = 0
};

fapi2::ReturnCode p9_pm_ocb_indir_access(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    p9ocb::PM_OCB_CHAN_NUM     i_ocb_chan,
    p9ocb::P9_OCB_ACCESS_OP    i_ocb_op,
    const uint32_t             i_ocb_req_length,
    fapi2::buffer<uint64_t>&    io_ocb_buffer,
    uint32_t&                   o_ocb_act_length,
    const bool                 i_oci_address_valid,
    const uint32_t             i_oci_address)
{
    FAPI_IMP("Entering...");

    FAPI_IMP("Exit...");
    return fapi2::FAPI2_RC_SUCCESS;
}
