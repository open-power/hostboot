/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/fapi2_vpd_access.H $                       */
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
/// @file fapi2_vpd_access.H
/// @brief Common file that defines the vpd access functions that
/// platform code must implement.
///
//

#ifndef _FAPI2_VPDACCESS_H_
#define _FAPI2_VPDACCESS_H_

#include <return_code.H>
#include <target_types.H>
#include <vpd_access_defs.H>
#include <plat_vpd_access.H>

namespace fapi2
{

/// @brief Return a blob of memory VPD data associated with the input target
/// @param[in] i_target, a valid fapi2 target
/// @param[in] io_vpd_info, fapi2::VPDInfo class that specifies which piece of data to return
/// @param[out] o_blob, the blob of raw data from the vpd
/// @return FAPI2_RC_SUCCESS if there's no problem
/// @note passing nullptr for o_blob will return the size of the keyword
///
/// Example:
/// fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> vpdInfo(MR_keyword);
/// vpdInfo.iv_speed_bin = 2400_SPEED_BIN;
///
/// uint8_t * blob = NULL;
///
/// FAPI_TRY(getVPD( mcs, vpdInfo, blob ));
/// blob = static_cast<uint8_t *>(malloc(vpdInfo.iv_size));
/// FAPI_TRY(getVPD( mcs, vpdInfo, blob ));
/// blob now contains the VPD data for the MCS.
///
template<TargetType T>
ReturnCode getVPD(const Target<T>& i_target,
                  VPDInfo<T>& io_vpd_info,
                  uint8_t* o_blob);

};
#endif
