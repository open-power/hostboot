/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatMBvpdAccess.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
/**
 *  @file fapiPlatMBvpdAccess.C
 *
 *  @brief Implements the fapiMBvpdAccess.H functions
 */

#include    <stdint.h>
#include    <errl/errlentry.H>

//  fapi support
#include <hwpf/hwpf_reasoncodes.H>
#include <fapiMBvpdAccess.H>

//  MBVPD
#include <devicefw/userif.H>
#include <vpd/cvpdenums.H>


namespace fapi
{

//******************************************************************************
// MBvpdRecordXlate
// Translates a FAPI MBVPD Record enumerator into a Hostboot MBVPD Record
// enumerator
//******************************************************************************
fapi::ReturnCode MBvpdRecordXlate(const fapi::MBvpdRecord i_fapiRecord,
                                 CVPD::cvpdRecord & o_hbRecord)
{
    // Create a lookup table for converting a FAPI MBVPD record enumerator to a
    // Hostboot CVPD record enumerator. This is a simple array and relies on
    // the FAPI record enumerators starting at zero and incrementing.
    static const CVPD::cvpdRecord
                  mbvpdFapiRecordToHbRecord[] =
    {
        CVPD::VEIR,
        CVPD::VER0,
        CVPD::MER0,
        CVPD::VSPD,
        CVPD::VINI,
        CVPD::OPFR,
        CVPD::VNDR,
        CVPD::SPDX,
    };
    const uint8_t NUM_MBVPD_RECORDS =
        sizeof(mbvpdFapiRecordToHbRecord)/sizeof(mbvpdFapiRecordToHbRecord[0]);

    fapi::ReturnCode l_rc;

    uint8_t l_index = static_cast<uint8_t>(i_fapiRecord);

    if (l_index >= NUM_MBVPD_RECORDS)
    {
        FAPI_ERR("MBvpdRecordXlate: Invalid MBVPD Record: 0x%x", i_fapiRecord);
        /*@
         * @errortype
         * @moduleid     MOD_MBVPD_ACCESS
         * @reasoncode   RC_INVALID_RECORD
         * @userdata1    Record enumerator
         * @devdesc      Attempt to read an MVPD field using an invalid record
         */
        const bool hbSwError = true;
        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            MOD_MBVPD_ACCESS,
            RC_INVALID_RECORD,
            i_fapiRecord, 0, hbSwError);

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        o_hbRecord = mbvpdFapiRecordToHbRecord[l_index];
    }

    return l_rc;
}

//******************************************************************************
// MBvpdKeywordXlate
// Translates a FAPI MBVPD Keyword enumerator into a Hostboot CVPD Keyword
// enumerator
//******************************************************************************
fapi::ReturnCode MBvpdKeywordXlate(const fapi::MBvpdKeyword i_fapiKeyword,
                                  CVPD::cvpdKeyword & o_hbKeyword)
{
    // Create a lookup table for converting a FAPI MBVPD keyword enumerator to a
    // Hostboot CVPD keyword enumerator. This is a simple array and relies on
    // the FAPI record enumerators starting at zero and incrementing.
    static const CVPD::cvpdKeyword
        mbvpdFapiKeywordToHbKeyword[] =
    {
        CVPD::pdI,
        CVPD::PF,
        CVPD::MT,
        CVPD::MR,
        CVPD::pdA,
        CVPD::EL,
        CVPD::LM,
        CVPD::MW,
        CVPD::MV,
        CVPD::AM,
        CVPD::VZ,
        CVPD::pdD,
        CVPD::MX,
        CVPD::DW,
        CVPD::PN,
        CVPD::SN,
        CVPD::DR,
        CVPD::CE,
        CVPD::FN,
        CVPD::CC,
        CVPD::HE,
        CVPD::CT,
        CVPD::HW,
        CVPD::VD,
        CVPD::VN,
        CVPD::VP,
        CVPD::SV,
        CVPD::M0,
        CVPD::M1,
        CVPD::M2,
        CVPD::M3,
        CVPD::M4,
        CVPD::M5,
        CVPD::M6,
        CVPD::M7,
        CVPD::M8,
        CVPD::T1,
        CVPD::T2,
        CVPD::T4,
        CVPD::T5,
        CVPD::T6,
        CVPD::T8,
        CVPD::Q0,
        CVPD::Q1,
        CVPD::Q2,
        CVPD::Q3,
        CVPD::Q4,
        CVPD::Q5,
        CVPD::Q6,
        CVPD::Q7,
        CVPD::Q8,
        CVPD::K0,
        CVPD::K1,
        CVPD::K2,
        CVPD::K3,
        CVPD::K4,
        CVPD::K5,
        CVPD::K6,
        CVPD::K7,
        CVPD::K8,
    };
    const uint8_t NUM_MBVPD_KEYWORDS =
     sizeof(mbvpdFapiKeywordToHbKeyword)/sizeof(mbvpdFapiKeywordToHbKeyword[0]);

    fapi::ReturnCode l_rc;

    uint8_t l_index = static_cast<uint8_t>(i_fapiKeyword);

    if (l_index >= NUM_MBVPD_KEYWORDS)
    {
        FAPI_ERR("MbvpdKeywordXlate: Invalid MVPD Keyword: 0x%x",
                i_fapiKeyword);
        /*@
         * @errortype
         * @moduleid     MOD_MBVPD_ACCESS
         * @reasoncode   RC_INVALID_KEYWORD
         * @userdata1    Keyword enumerator
         * @devdesc      Attempt to read an MVPD field using an invalid keyword
         */
        const bool hbSwError = true;
        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            MOD_MBVPD_ACCESS,
            RC_INVALID_KEYWORD,
            i_fapiKeyword, 0, hbSwError);

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        o_hbKeyword = mbvpdFapiKeywordToHbKeyword[l_index];
    }

    return l_rc;
}

}

extern "C"
{

//******************************************************************************
// fapiGetMBvpdField
//******************************************************************************
fapi::ReturnCode fapiGetMBvpdField(const fapi::MBvpdRecord i_record,
                                  const fapi::MBvpdKeyword i_keyword,
                                  const fapi::Target &i_memBufTarget,
                                  uint8_t * const i_pBuffer,
                                  uint32_t &io_fieldSize)
{
    fapi::ReturnCode l_rc;
    FAPI_DBG("fapiGetMBvpdField entry");

    do
    {
        // Translate the FAPI record to a Hostboot record
        CVPD::cvpdRecord l_hbRecord = CVPD::CVPD_INVALID_RECORD;

        l_rc = fapi::MBvpdRecordXlate(i_record, l_hbRecord);

        if (l_rc)
        {
            break;
        }

        // Translate the FAPI keyword to a Hostboot keyword
        CVPD::cvpdKeyword l_hbKeyword = CVPD::CVPD_INVALID_KEYWORD;

        l_rc = fapi::MBvpdKeywordXlate(i_keyword, l_hbKeyword);

        if (l_rc)
        {
            break;
        }

        // Similarly to this function, deviceRead will return the size of the
        // field if the pointer is NULL
        size_t l_fieldLen = io_fieldSize;

        errlHndl_t l_errl = deviceRead(
            reinterpret_cast< TARGETING::Target*>(i_memBufTarget.get()),
            i_pBuffer,
            l_fieldLen,
            DEVICE_CVPD_ADDRESS(l_hbRecord, l_hbKeyword));

        if (l_errl)
        {
            FAPI_ERR("fapGetMBvpdField: ERROR: deviceRead : errorlog PLID=0x%x",
                     l_errl->plid());

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_errl));

            break;
        }

        // Success, update callers io_fieldSize for the case where the pointer
        // is NULL and deviceRead returned the actual size
        io_fieldSize = l_fieldLen;
        FAPI_DBG("fapGetMBvpdField: returning field len=0x%x", io_fieldSize);

    } while(0);

    FAPI_DBG( "fapGetMBvpdField: exit" );

    return  l_rc;
}

//******************************************************************************
// fapSetMBvpdField
//******************************************************************************
fapi::ReturnCode fapiSetMBvpdField(const fapi::MBvpdRecord i_record,
                                  const fapi::MBvpdKeyword i_keyword,
                                  const fapi::Target &i_memBufTarget,
                                  const uint8_t * const i_pBuffer,
                                  const uint32_t i_fieldSize)
{
    fapi::ReturnCode l_rc;
    FAPI_DBG("fapiSetMBvpdField entry");

    do
    {
        // Translate the FAPI record to a Hostboot record
        CVPD::cvpdRecord l_hbRecord = CVPD::CVPD_INVALID_RECORD;

        l_rc = fapi::MBvpdRecordXlate(i_record, l_hbRecord);

        if (l_rc)
        {
            break;
        }

        // Translate the FAPI keyword to a Hostboot keyword
        CVPD::cvpdKeyword l_hbKeyword = CVPD::CVPD_INVALID_KEYWORD;

        l_rc = fapi::MBvpdKeywordXlate(i_keyword, l_hbKeyword);

        if (l_rc)
        {
            break;
        }

        size_t l_fieldLen = i_fieldSize;

        errlHndl_t l_errl = deviceWrite(
            reinterpret_cast< TARGETING::Target*>(i_memBufTarget.get()),
            const_cast<uint8_t *>(i_pBuffer),
            l_fieldLen,
            DEVICE_CVPD_ADDRESS(l_hbRecord, l_hbKeyword));

        if (l_errl)
        {
            FAPI_ERR("fapSetMBvpdField: ERROR:deviceWrite : errorlog PLID=0x%x",
                     l_errl->plid());

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_errl));

            break;
        }

    } while(0);

    FAPI_DBG( "fapSetMBvpdField: exit" );

    return  l_rc;
}

} // extern "C"
