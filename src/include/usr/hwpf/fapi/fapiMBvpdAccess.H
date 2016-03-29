/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiMBvpdAccess.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
// $Id: fapiMBvpdAccess.H,v 1.13 2015/10/06 19:19:44 kahnevan Exp $
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
        MBVPD_RECORD_OPFR = 0x05,
        MBVPD_RECORD_VNDR = 0x06,
        MBVPD_RECORD_SPDX = 0x07,
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
        MBVPD_KEYWORD_DW  = 0x0d,
        MBVPD_KEYWORD_PN  = 0x0e,
        MBVPD_KEYWORD_SN  = 0x0f,
        MBVPD_KEYWORD_DR  = 0x10,
        MBVPD_KEYWORD_CE  = 0x11,
        MBVPD_KEYWORD_FN  = 0x12,
        MBVPD_KEYWORD_CC  = 0x13,
        MBVPD_KEYWORD_HE  = 0x14,
        MBVPD_KEYWORD_CT  = 0x15,
        MBVPD_KEYWORD_HW  = 0x16,
        MBVPD_KEYWORD_VD  = 0x17,
        MBVPD_KEYWORD_VN  = 0x18,
        MBVPD_KEYWORD_VP  = 0x19,
        MBVPD_KEYWORD_SV  = 0x1a,
        MBVPD_KEYWORD_M0  = 0x1b,
        MBVPD_KEYWORD_M1  = 0x1c,
        MBVPD_KEYWORD_M2  = 0x1d,
        MBVPD_KEYWORD_M3  = 0x1e,
        MBVPD_KEYWORD_M4  = 0x1f,
        MBVPD_KEYWORD_M5  = 0x20,
        MBVPD_KEYWORD_M6  = 0x21,
        MBVPD_KEYWORD_M7  = 0x22,
        MBVPD_KEYWORD_M8  = 0x23,
        MBVPD_KEYWORD_T1  = 0x24,
        MBVPD_KEYWORD_T2  = 0x25,
        MBVPD_KEYWORD_T4  = 0x26,
        MBVPD_KEYWORD_T5  = 0x27,
        MBVPD_KEYWORD_T6  = 0x28,
        MBVPD_KEYWORD_T8  = 0x29,
        MBVPD_KEYWORD_Q0  = 0x2a,
        MBVPD_KEYWORD_Q1  = 0x2b,
        MBVPD_KEYWORD_Q2  = 0x2c,
        MBVPD_KEYWORD_Q3  = 0x2d,
        MBVPD_KEYWORD_Q4  = 0x2e,
        MBVPD_KEYWORD_Q5  = 0x2f,
        MBVPD_KEYWORD_Q6  = 0x30,
        MBVPD_KEYWORD_Q7  = 0x31,
        MBVPD_KEYWORD_Q8  = 0x32,
        MBVPD_KEYWORD_K0  = 0x33,
        MBVPD_KEYWORD_K1  = 0x34,
        MBVPD_KEYWORD_K2  = 0x35,
        MBVPD_KEYWORD_K3  = 0x36,
        MBVPD_KEYWORD_K4  = 0x37,
        MBVPD_KEYWORD_K5  = 0x38,
        MBVPD_KEYWORD_K6  = 0x39,
        MBVPD_KEYWORD_K7  = 0x3a,
        MBVPD_KEYWORD_K8  = 0x3b,
        MBVPD_KEYWORD_MM  = 0x3c,
        MBVPD_KEYWORD_SS  = 0x3d,
        MBVPD_KEYWORD_ET  = 0x3e,
        MBVPD_KEYWORD_VM  = 0x3f,
        MBVPD_KEYWORD_PD1 = 0x40, //#1
        MBVPD_KEYWORD_PDZ = 0x41, //#Z
        MBVPD_KEYWORD_PD4 = 0x42, //#4
        MBVPD_KEYWORD_PD5 = 0x43, //#5
        MBVPD_KEYWORD_PD6 = 0x44, //#6
        MBVPD_KEYWORD_PD8 = 0x45, //#8
        MBVPD_KEYWORD_PDY = 0x46, //#Y       
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
 *  @param[in]     i_record       Record enumerator
 *  @param[in]     i_keyword      Keyword enumerator
 *  @param[in]     i_memBufTarget Reference to memory buffer chip target for
 *                            the record
 *  @param[in]     i_pBuffer      Pointer to buffer where record will be stored. If
 *                                NULL then the size of record will be stored in
 *                                io_fieldSize
 *  @param[in,out] io_fieldSize   Size of i_pBuffer in bytes
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
 *  @param[in]     i_record       Record enumerator
 *  @param[in]     i_keyword      Keyword enumerator
 *  @param[in]     i_memBufTarget Reference to memory buffer chip target for
 *                                the record
 *  @param[in]     i_pBuffer      Pointer to buffer where data to set is stored
 *  @param[in,out] i_fieldSize    Size of i_pBuffer in bytes
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
