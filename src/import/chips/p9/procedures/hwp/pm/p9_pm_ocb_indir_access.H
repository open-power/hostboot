/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_ocb_indir_access.H $         */
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
/// @file  p9_pm_ocb_indir_access.H
/// @brief Access procedure to the OCC OCB indirect channels
///

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP HWP Backup Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : FSP:HS

#ifndef _P9_PM_OCB_INDIR_ACCESS_H_
#define _P9_PM_OCB_INDIR_ACCESS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_pm.H>
#include <p9_pm_ocb_init.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
namespace p9ocb
{
enum PM_OCB_ACCESS_OP
{
    OCB_GET = 0x1,
    OCB_PUT = 0x2
};
}

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_ocb_indir_access_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const p9ocb::PM_OCB_CHAN_NUM,
 const p9ocb::PM_OCB_ACCESS_OP,
 const uint32_t,
 const bool,
 const uint32_t,
 uint32_t&,
 uint64_t*);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

extern "C"
{

/// @brief Provides for the abstract access to an OCB indirect channel that has
/// been configured previously via p9_pm_ocb_indir_setup_[linear/circular]
/// procedures
///
/// @param[in]     &i_target           Chip target
/// @param[in]     i_ocb_chan          OCB channel number (0, 1, 2, 3)
/// @param[in]     i_ocb_op            Operation (Get, Put)
/// @param[in]     i_ocb_req_length    Requested length in the number of 8B
///                                    elements to be accessed (unit origin)
///                                    Number of bytes = (i_ocb_req_length) *
///                                    8B
/// @param[in]     i_oci_address_valid Indicator that oci_address is to be used
/// @param[in]     i_oci_address       OCI Address to be used for the operation
/// @param[out]    &o_ocb_act_length   Address containing the actual length
///                                    in the number of 8B elements to be
///                                    accessed (zero origin)
///                                    Number of bytes = (o_ocb_act_length+1) *
///                                    8B
/// @param[in/out] io_ocb_buffer       Pointer to a container of type uint64_t
///                                    to store the data to be written into or
///                                    obtained from OCC SRAM
///
/// @return FAPI2_RC_SUCCESS on success, else error.

    fapi2::ReturnCode p9_pm_ocb_indir_access(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9ocb::PM_OCB_CHAN_NUM  i_ocb_chan,
        const p9ocb::PM_OCB_ACCESS_OP i_ocb_op,
        const uint32_t                i_ocb_req_length,
        const bool                    i_oci_address_valid,
        const uint32_t                i_oci_address,
        uint32_t&                     o_ocb_act_length,
        uint64_t*                     io_ocb_buffer);

} // extern "C"

#endif // _P9_PM_OCB_INDIR_ACCESS_H_
