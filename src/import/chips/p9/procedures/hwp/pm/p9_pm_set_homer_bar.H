/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_set_homer_bar.H $          */
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

/// @file  p9_pm_set_homer_bar.H
/// @brief Set/reset the BLOCK_REG_WKUP_SOURCES bit in the PPM
///         associated with an EX chiplet
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS
///
///-----------------------------------------------------------------------------

#ifndef _P9_SET_HOMER_BAR_H_
#define _P9_SET_HOMER_BAR_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_set_homer_bar_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const uint64_t,
    const uint64_t);


extern "C"
{
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \param[in] i_target     Procesor Chip target
/// \param[in] i_mem_bar    Base address of the region where image is located
/// \param[in] i_mem_size   Size (in MB) of the region where image is located
///                         if not a power of two value, the value will be
///                         rounded up to the next power of 2 for setting the
///                         hardware mask

    fapi2::ReturnCode p9_pm_set_homer_bar(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_mem_bar,
        const uint64_t i_mem_size);

}//extern
#endif // _P9_SET_HOMER_BAR_H_
