/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwpf/fapi/fapiMvpdAccess.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */

/**
 *  @file fapiMvpdAccess.H
 *
 *  @brief Prototype file for fapiMvpdAccess - read / write records from MVPD
 *
 */

#ifndef _FAPI_FAPIMVPDACCESS_H_
#define _FAPI_FAPIMVPDACCESS_H_

#include <stdint.h>
#include <stddef.h>
#include <fapi.H>

extern "C"
{

/**
 *  @brief fetch Module VPD #R record.
 *  Suggested way to call this routine is to call it once with a NULL buffer
 *  pointer to to retrieve the size of the record, then allocate the proper
 *  size of the buffer and call again.
 *
 *  @param[in]      -   i_fapiTarget    -   target that the #R record belongs to
 *  @param[in]      -   i_pPdrRecord    -   pointer to a buffer
 *                      Caller is responsible for allocating the buffer ahead
 *                      of time.
 *                      If NULL is passed in, the proper size of the #R record
 *                      will be returned in the o_rPdrSize parameter below.
 *  @param[in,out]  -   io_rPdrSize     -   size of the #R record in BYTES.
 *                      If the record was not found, an error will be returned
 *                      and this will be set to 0.
 *
 *  @return         -   FAPI_RC_SUCCESS, or failure value.
 */
fapi::ReturnCode    fapiGetMvpdPdr( const fapi::Target  &i_fapiTarget,
                                    uint8_t             *i_pPdrRecord,
                                    uint32_t            &io_rPdrSize );
}

#endif
