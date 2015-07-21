/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_sbe_common.H $                */
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
/// @file  p9_sbe_common.H
///
/// @brief Common Modules for SBE
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


#ifndef _P9_SBE_COMMON_H_
#define _P9_SBE_COMMON_H_


#include <fapi2.H>


fapi2::ReturnCode p9_sbe_common_align_chiplets(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplets);

fapi2::ReturnCode p9_sbe_common_clock_start_allRegions(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_anychiplet);

fapi2::ReturnCode p9_sbe_common_clock_start_stop(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target,
        const fapi2::buffer<uint8_t> i_clock_cmd,
        const bool i_startslave,
        const bool i_startmaster,
        const fapi2::buffer<uint64_t> i_regions,
        const fapi2::buffer<uint8_t> i_clock_types);

fapi2::ReturnCode p9_sbe_common_set_scan_ratio(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplets);

#endif
