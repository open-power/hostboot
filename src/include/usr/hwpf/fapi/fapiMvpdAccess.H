/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiMvpdAccess.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: fapiMvpdAccess.H,v 1.10 2015/04/23 19:42:38 whs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiMvpdAccess.H,v $

/**
 *  @file fapiMvpdAccess.H
 *
 *  @brief Defines the Module VPD functions that platform must implement
 *
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     10/09/2012  Added fapiGetMvpdField
 */

#ifndef _FAPI_FAPIMVPDACCESS_H_
#define _FAPI_FAPIMVPDACCESS_H_

#include <stdint.h>
#include <stddef.h>
#include <fapiReturnCode.H>
#include <fapiTarget.H>

namespace fapi
{
    enum MvpdRecord
    {
        MVPD_RECORD_CRP0 = 0x00,
        MVPD_RECORD_CP00 = 0x01,
        MVPD_RECORD_VINI = 0x02,
        MVPD_RECORD_LRP0 = 0x03,
        MVPD_RECORD_LRP1 = 0x04,
        MVPD_RECORD_LRP2 = 0x05,
        MVPD_RECORD_LRP3 = 0x06,
        MVPD_RECORD_LRP4 = 0x07,
        MVPD_RECORD_LRP5 = 0x08,
        MVPD_RECORD_LWP0 = 0x09,
        MVPD_RECORD_LWP1 = 0x0a,
        MVPD_RECORD_LWP2 = 0x0b,
        MVPD_RECORD_LWP3 = 0x0c,
        MVPD_RECORD_LWP4 = 0x0d,
        MVPD_RECORD_LWP5 = 0x0e,
        MVPD_RECORD_VRML = 0x0f,
        MVPD_RECORD_VWML = 0x10,
        MVPD_RECORD_VER0 = 0x11,
        MVPD_RECORD_MER0 = 0x12,
        MVPD_RECORD_VMSC = 0x13,
    };

    enum MvpdKeyword
    {
        MVPD_KEYWORD_VD  = 0x00,
        MVPD_KEYWORD_ED  = 0x01,
        MVPD_KEYWORD_TE  = 0x02,
        MVPD_KEYWORD_DD  = 0x03,
        MVPD_KEYWORD_DN  = 0x04,
        MVPD_KEYWORD_PG  = 0x05,
        MVPD_KEYWORD_PK  = 0x06,
        MVPD_KEYWORD_PDR = 0x07,
        MVPD_KEYWORD_PDV = 0x08,
        MVPD_KEYWORD_PDH = 0x09,
        MVPD_KEYWORD_SB  = 0x0a,
        MVPD_KEYWORD_DR  = 0x0b,
        MVPD_KEYWORD_VZ  = 0x0c,
        MVPD_KEYWORD_CC  = 0x0d,
        MVPD_KEYWORD_CE  = 0x0e,
        MVPD_KEYWORD_FN  = 0x0f,
        MVPD_KEYWORD_PN  = 0x10,
        MVPD_KEYWORD_SN  = 0x11,
        MVPD_KEYWORD_PR  = 0x12,
        MVPD_KEYWORD_HE  = 0x13,
        MVPD_KEYWORD_CT  = 0x14,
        MVPD_KEYWORD_HW  = 0x15,
        MVPD_KEYWORD_PDM = 0x16,
        MVPD_KEYWORD_IN  = 0x17,
        MVPD_KEYWORD_PDI = 0x18,
        MVPD_KEYWORD_PDG = 0x19,
        MVPD_KEYWORD_PB  = 0x1a,
        MVPD_KEYWORD_CH  = 0x1b,
        MVPD_KEYWORD_IQ  = 0x1c,
        MVPD_KEYWORD_PM  = 0x1d,
        MVPD_KEYWORD_PZ  = 0x1e,
        MVPD_KEYWORD_N20 = 0x1f,
        MVPD_KEYWORD_N21 = 0x20,
        MVPD_KEYWORD_N30 = 0x21,
        MVPD_KEYWORD_N31 = 0x22,
    };

    typedef struct voltageBucketData
    {
        // bucket Id
        uint8_t bucketId;
        // Nominal
        uint16_t nomFreq;
        uint16_t VnestNomVltg;
        uint16_t InestNomCurr;
        uint16_t VcsNomVltg;
        uint16_t IcsNomCurr;
        // PowerSave
        uint16_t PSFreq;
        uint16_t VnestPSVltg;
        uint16_t InestPSCurr;
        uint16_t VcsPSVltg;
        uint16_t IcsPSCurr;
        // Turbo
        uint16_t turboFreq;
        uint16_t VnestTurboVltg;
        uint16_t InestTurboCurr;
        uint16_t VcsTurboVltg;
        uint16_t IcsTurboCurr;
        //Fvmin
        uint16_t fvminFreq;
        uint16_t VnestFvminVltg;
        uint16_t InestFvminCurr;
        uint16_t VcsFvminVltg;
        uint16_t IcsFvminCurr;
        //Lab
        uint16_t labFreq;
        uint16_t VnestLabVltg;
        uint16_t InestLabCurr;
        uint16_t VcsLabVltg;
        uint16_t IcsLabCurr;
    }voltageBucketData_t;

}

extern "C"
{

/**
 *  @brief Get Module VPD field.
 *
 *  A Module VPD field is specified using a record and keyword enumerator
 *
 *  Suggested way to call this routine is to call it once with a NULL buffer
 *  pointer to to retrieve the size of the record, then allocate the proper
 *  size of the buffer and call again.
 *
 *  @param[in] i_record     Record enumerator
 *  @param[in] i_keyword    Keyword enumerator
 *  @param[in] i_procTarget Reference to processor chip target for the record
 *  @param[in] i_pBuffer    Pointer to buffer where record will be stored. If
 *                          NULL then the size of record will be stored in
 *                          io_fieldSize
 *  @param[in,out] io_fieldSize Size of i_pBuffer in bytes
 *
 *  @return fapi::ReturnCode. FAPI_RC_SUCCESS, or failure value.
 */
fapi::ReturnCode fapiGetMvpdField(const fapi::MvpdRecord i_record,
                                  const fapi::MvpdKeyword i_keyword,
                                  const fapi::Target &i_procTarget,
                                  uint8_t * const i_pBuffer,
                                  uint32_t &io_fieldSize);

/**
 *  @brief Set Module VPD field.
 *
 *  A Module VPD field is specified using a record and keyword enumerator
 *
 *  @param[in] i_record     Record enumerator
 *  @param[in] i_keyword    Keyword enumerator
 *  @param[in] i_procTarget Reference to processor chip target for the record
 *  @param[in] i_pBuffer    Pointer to buffer where data to set is stored
 *  @param[in] i_fieldSize  Size of i_pBuffer in bytes
 *
 *  @return fapi::ReturnCode. FAPI_RC_SUCCESS, or failure value.
 */
fapi::ReturnCode fapiSetMvpdField(const fapi::MvpdRecord i_record,
                                  const fapi::MvpdKeyword i_keyword,
                                  const fapi::Target &i_procTarget,
                                  const uint8_t * const i_pBuffer,
                                  const uint32_t i_fieldSize);

/**
 * @brief Get #V bucket data from VPD
 *
 * @par Detailed Description:
 *     This function reads PR keyword from the VPD, parses PR keyword
 *     to get voltage bucket id, reads #V keyword (Voltage data) from VPD,
 *     parses #V keyword to get voltage data corresponding to the bucket id
 *     indicated by the PR keyword and returns data to the caller.
 *
 * @param[in] i_pTarget  Pointer to proc chip target.
 * @param[in] i_record   VPD record number to read #V bucket data
 * @param[out] o_data    On success, structure with #V bucket data from VPD
 *
 * @return fapi::ReturnCode. FAPI_RC_SUCCESS, or failure value.
 */
fapi::ReturnCode fapiGetPoundVBucketData(const fapi::Target &i_procTarget,
                                         const uint32_t i_record,
                                         fapi::voltageBucketData_t & o_data);

}

#endif
