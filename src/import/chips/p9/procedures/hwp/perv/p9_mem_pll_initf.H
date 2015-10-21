/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_mem_pll_initf.H $             */
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
//------------------------------------------------------------------------------
/// @file  p9_mem_pll_initf.H
///
/// @brief PLL initfile for MBAs
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 1
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------


#ifndef _P9_MEM_PLL_INITF_H_
#define _P9_MEM_PLL_INITF_H_


#include <fapi2.H>


typedef fapi2::ReturnCode (*p9_mem_pll_initf_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

/// @brief  > This step is a no-op if memory is running in synchronous mode since MCAs are using thr nest PLL
///  > MBA PLL setup
///       Hostboot does not support twiddling bits, looks up which bucket to use from attributes set during mss_freq
///       Request SBE to scan said ring and data stored as a ring image.
///
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p9_mem_pll_initf(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chiplet);
}

#endif
