/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_nest_common_mc_def.H $        */
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
/// ----------------------------------------------------------------------------
/// @file  p9_nest_common_mc_def.H
///
/// @brief Common definitions for MC related values in P9
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 2
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------
#ifndef _P9_NEST_COMMON_MC_DEF_H_
#define _P9_NEST_COMMON_MC_DEF_H_

//----------------------------------------------------------------------------
// Constant definitions
//----------------------------------------------------------------------------

// Nimbus PROC/MCS/MCA/DIMM definitions
const uint8_t MAX_MCS_PER_PROC = 4;
const uint8_t MAX_MCA_PER_PROC = 8;
const uint8_t MAX_MCA_PER_MCS  = 2;
const uint8_t MAX_DIMM_PER_MCA = 2;

#endif  // _P9_NEST_COMMON_MC_DEF_H_
