/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiMBvpdAccess.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: fapiMBvpdAccess.H,v 1.9 2014/01/20 20:03:18 mjjones Exp $
/**
 *  @file fapiMBvpdAccess.H
 *
 *  @brief Defines the Memory Bus (Centaur) VPD functions that platform
 *   must implement
 *
 */

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
        MBVPD_RECORD_VINI = 0x04,
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
        MBVPD_KEYWORD_VZ  = 0x0a,
        MBVPD_KEYWORD_PDD = 0x0b,
        MBVPD_KEYWORD_MX  = 0x0c,
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
