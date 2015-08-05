/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/mvpd_access.H $                            */
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
/// @file mvpd_access.H
///
/// @brief Defines the Module VPD functions that platform must implement
///

#ifndef _FAPI2_MVPDACCESS_H_
#define _FAPI2_MVPDACCESS_H_

#include <stdint.h>
#include <return_code.H>
#include <target.H>
#include <mvpd_access_defs.H>

namespace fapi2
{
///
/// @brief Get Module VPD field.
///
/// A Module VPD field is specified using a record and keyword enumerator
///
/// Suggested way to call this routine is to call it once with a NULL buffer
/// pointer to to retrieve the size of the record, then allocate the proper
/// size of the buffer and call again.
///
/// @param[in] i_record     Record enumerator
/// @param[in] i_keyword    Keyword enumerator
/// @param[in] i_target     Reference to processor chip target for the record
/// @param[in] i_pBuffer    Pointer to buffer where record will be stored. If
///                         NULL then the size of record will be stored in
///                         io_fieldSize
/// @param[in,out] io_fieldSize Size of i_pBuffer in bytes
///
/// @return fapi2::ReturnCode. FAPI_RC_SUCCESS, or failure value.
///
ReturnCode getMvpdField(const MvpdRecord i_record,
                        const MvpdKeyword i_keyword,
                        const Target<TARGET_TYPE_PROC_CHIP>& i_target,
                        uint8_t* const i_pBuffer,
                        uint32_t& io_fieldSize);

///
/// @brief Set Module VPD field.
///
/// A Module VPD field is specified using a record and keyword enumerator
///
/// @param[in] i_record     Record enumerator
/// @param[in] i_keyword    Keyword enumerator
/// @param[in] i_target     Reference to processor chip target for the record
/// @param[in] i_pBuffer    Pointer to buffer where data to set is stored
/// @param[in] i_fieldSize  Size of i_pBuffer in bytes
///
/// @return fapi2::ReturnCode. FAPI_RC_SUCCESS, or failure value.
///
ReturnCode setMvpdField(const MvpdRecord i_record,
                        const MvpdKeyword i_keyword,
                        const Target<TARGET_TYPE_PROC_CHIP>& i_target,
                        const uint8_t* const i_pBuffer,
                        const uint32_t i_fieldSize);
}

#endif
