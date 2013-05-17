/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiMBvpdAccess.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: fapiMBvpdAccess.H,v 1.2 2012/10/09 21:32:55 mjjones Exp $
/**
 *  @file fapiMBvpdAccess.H
 *
 *  @brief Defines the Memory Bus (Centaur) VPD functions that platform
 *   must implement
 *
 */
// $Id: fapiMBvpdAccess.H,v 1.2 2013/04/29 16:09:31 whs Exp $

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          whs         01/24/2013  Added fapiGetMBvpdField
 *                          whs         04/29/2013  Added VSPD record, keywords
 */

#ifndef _FAPI_FAPIMBVPDACCESS_H_
#define _FAPI_FAPIMBVPDACCESS_H_

#include <stdint.h>
#include <stddef.h>
#include <fapiReturnCode.H>
#include <fapiTarget.H>

namespace fapi
{
    enum MBvpdRecord
    {
        MBVPD_RECORD_VEIR = 0x00,
        MBVPD_RECORD_VER0 = 0x01,
        MBVPD_RECORD_MER0 = 0x02,
        MBVPD_RECORD_VSPD = 0x03,
    };

    enum MBvpdKeyword
    {
        MBVPD_KEYWORD_PDI = 0x00,
        MBVPD_KEYWORD_PF  = 0x01,
        MBVPD_KEYWORD_MT  = 0x02,
        MBVPD_KEYWORD_MR  = 0x03,
        MBVPD_KEYWORD_PDA = 0x04,
        MBVPD_KEYWORD_EL  = 0x05,
        MBVPD_KEYWORD_LM  = 0x06,
        MBVPD_KEYWORD_MW  = 0x07,
        MBVPD_KEYWORD_MV  = 0x08,
        MBVPD_KEYWORD_AM  = 0x09,
    };

}

extern "C"
{

/**
 *  @brief Get Memory Buffer (Centaur)  VPD field.
 *  
 *  A Memory Buffer VPD field is specified using a record and keyword enumerator
 *  
 *  Suggested way to call this routine is to call it once with a NULL buffer
 *  pointer to to retrieve the size of the record, then allocate the proper
 *  size of the buffer and call again.
 *
 *  @param[in] i_record       Record enumerator
 *  @param[in] i_keyword      Keyword enumerator
 *  @param[in] i_memBufTarget Reference to memory buffer chip target for
 *                            the record
 *  @param[in] i_pBuffer      Pointer to buffer where record will be stored. If
 *                            NULL then the size of record will be stored in
 *                            io_fieldSize
 *  @param[io] io_fieldSize   Size of i_pBuffer in bytes
 *
 *  @return fapi::ReturnCode. FAPI_RC_SUCCESS, or failure value.
 */
fapi::ReturnCode fapiGetMBvpdField(const fapi::MBvpdRecord i_record,
                                  const fapi::MBvpdKeyword i_keyword,
                                  const fapi::Target &i_memBufTarget,
                                  uint8_t * const i_pBuffer,
                                  uint32_t &io_fieldSize);

/**
 *  @brief Set Memory Buffer (Centaur) VPD field.
 *
 *  A Memory Buffer VPD field is specified using a record and keyword enumerator
 *
 *  @param[in] i_record       Record enumerator
 *  @param[in] i_keyword      Keyword enumerator
 *  @param[in] i_memBufTarget Reference to memory buffer chip target for
 *                            the record
 *  @param[in] i_pBuffer      Pointer to buffer where data to set is stored
 *  @param[io] i_fieldSize    Size of i_pBuffer in bytes
 *
 *  @return fapi::ReturnCode. FAPI_RC_SUCCESS, or failure value.
 */
fapi::ReturnCode fapiSetMBvpdField(const fapi::MBvpdRecord i_record,
                                  const fapi::MBvpdKeyword i_keyword,
                                  const fapi::Target &i_memBufTarget,
                                  const uint8_t * const i_pBuffer,
                                  const uint32_t i_fieldSize);
}

#endif
