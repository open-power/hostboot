/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_get_poundv_bucket_attr.H $   */
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
/// @file p9_pm_get_poundv_bucket.H
/// @brief Provide structure for voltageBucketData so that info from #V keyword
/// can be stored inside of this struct.
/// Also define prototype for p9_pm_get_poundv_bucket
///

#ifndef _P9_PM_GET_POUND_V_BUCKET_ATTR_H_
#define _P9_PM_GET_POUND_V_BUCKET_ATTR_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_get_poundv_bucket_attr_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>&,
    uint8_t* o_data);

extern "C" {

///
/// @brief Read #V bucket data from LRP record based upon
///        bucket ID read off of parent proc chip. This function
///        will pass out array of bytes as they are read from the VPD
///        NOTE: This might be incorrect endianness
/// @param[in] i_target EQ chiplet target
/// @param[in] o_data bytes read from #V keyword of an LRP record
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_pm_get_poundv_bucket_attr(
        const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
        uint8_t* o_data);

} // extern "C"

#endif // _P9_PM_GET_POUND_V_BUCKET_ATTR_H_
