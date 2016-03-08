/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/fapi2_spd_access.H $                       */
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
/// @file spd_access.H
///
/// @brief Defines the SPD functions that platform must implement
///

#ifndef _FAPI2_SPDACCESS_H_
#define _FAPI2_SPDACCESS_H_

#include <stdint.h>
#include <return_code.H>
#include <target.H>
#include <plat_spd_access.H>

namespace fapi2
{
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
fapi2::ReturnCode getSPD( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          uint8_t* o_blob,
                          size_t& s );

}
#endif
