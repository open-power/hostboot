/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/fake_spd.H $         */
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

///
/// @file fake_spd.H
/// @brief A tool to return fake (fixed) DIMM SPD for testing, development
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_FAKE_SPD_H_
#define _MSS_FAKE_SPD_H_

#include <fapi2.H>

///
/// @brief Return a blob of SPD data from a DIMM
/// @param[in] i_target, a DIMM target representing the DIMM in question
/// @param[out] o_blob, the blob of data from the DIMM - raw
/// @param[out] o_size, o_size, the size of the blob
/// @return FAPI2_RC_SUCCESS if there's no problem
/// @note passing nullptr for o_blob will return the size of the blob
///   size_t s;
///   FAPI_TRY( getSPD(d->target(), nullptr, s) );
///   {
///       uint8_t blob[s];
///       FAPI_TRY( getSPD(d->target(), blob, s) );
///    }
///
fapi2::ReturnCode getSPD(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t* o_blob, size_t& s);

#endif
