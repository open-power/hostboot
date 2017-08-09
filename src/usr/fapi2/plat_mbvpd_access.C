/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_mbvpd_access.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
 *  @file  plat_mbvpd_access.C
 *
 *  @brief Implements the fapi2_mbvpd_access.H functions
 */

#include    <stdint.h>
#include    <errl/errlentry.H>

// fapi2 support changes
#include <fapi2_mbvpd_access.H>
#include <fapi2_mbvpd_access_defs.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <devicefw/userif.H>
#include <vpd/cvpdenums.H>

// Invalid chip unit
const uint8_t MBVPD_INVALID_CHIP_UNIT = 0xFF;

namespace fapi2
{

//******************************************************************************
// CvpdRecordXlate
// Translates a FAPI MBVPD Record enumerator into a Hostboot CVPD Record
// enumerator
//******************************************************************************
fapi2::ReturnCode CvpdRecordXlate(const fapi2::MBvpdRecord i_fapiRecord,
                                  CVPD::cvpdRecord & o_hbRecord,
                                  uint8_t & o_recordIndex)
{
    // Create a lookup table for converting a FAPI CVPD record enumerator to a
    // Hostboot CVPD record enumerator. This is a simple array and relies on
    // the FAPI record enumerators starting at zero and incrementing.
    struct cvpdRecordToChip
    {
        CVPD::cvpdRecord rec;
        // This is the fapi2 Index to the CVPD record
        uint8_t recIndex;
    };
    static const cvpdRecordToChip cvpdFapiRecordToHbRecord[] =
    {
        /** CVPD record mapping to FAPI2 CVPD **/
        {CVPD::VEIR,MBVPD_RECORD_VEIR},
        {CVPD::VER0,MBVPD_RECORD_VER0},
        {CVPD::MER0,MBVPD_RECORD_MER0},
        {CVPD::VSPD,MBVPD_RECORD_VSPD},
        {CVPD::VINI,MBVPD_RECORD_VINI},
        {CVPD::OPFR,MBVPD_RECORD_OPFR},
        {CVPD::VNDR,MBVPD_RECORD_VNDR},
        {CVPD::SPDX,MBVPD_RECORD_SPDX},
    };
    const uint8_t NUM_CVPD_RECORDS =
           sizeof(cvpdFapiRecordToHbRecord)/sizeof(cvpdFapiRecordToHbRecord[0]);

    fapi2::ReturnCode l_rc;

    uint8_t l_index = static_cast<uint8_t>(i_fapiRecord);

    if (l_index >= NUM_CVPD_RECORDS)
    {
        FAPI_ERR("MBvpdRecordXlate: Index went out of bounds looking for record: 0x%x", i_fapiRecord);
        /*@
         * @errortype
         * @moduleid         MOD_FAPI2_CVPD_ACCESS
         * @reasoncode       RC_RECORD_OUT_OF_BOUNDS
         * @userdata1        Record enumerator
         * @userdata2[0:31]  Index
         * @userdata2[32:63] Max Index
         * @devdesc          Attempt to read an CVPD field using
         *                   an invalid record
         * @custdesc         Firmware error during IPL
         */

        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi2::MOD_FAPI2_CVPD_ACCESS,
            fapi2::RC_RECORD_OUT_OF_BOUNDS,
            i_fapiRecord,
            TWO_UINT32_TO_UINT64(l_index,
            NUM_CVPD_RECORDS),
            true);

        //Set the record index to INVALID
        //Don't set the data because we dont know anything about it
        o_recordIndex  = MBVPD_INVALID_CHIP_UNIT;

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }


    if(!l_rc)
    {
        o_hbRecord    = cvpdFapiRecordToHbRecord[l_index].rec;
        o_recordIndex = cvpdFapiRecordToHbRecord[l_index].recIndex;
    }

    return l_rc;
}

//******************************************************************************
// CvpdKeywordXlate
// Translates a FAPI MBVPD Keyword enumerator into a Hostboot CVPD Keyword
// enumerator
//******************************************************************************
fapi2::ReturnCode CvpdKeywordXlate(const fapi2::MBvpdKeyword i_fapiKeyword,
                                   CVPD::cvpdKeyword & o_hbKeyword,
                                   uint8_t & o_keywordIndex)
{
    // Create a lookup table for converting a FAPI CVPD keyword enumerator to a
    // Hostboot CVPD keyword enumerator. This is a simple array and relies on
    // the FAPI keyword enumerators starting at zero and incrementing.
    struct cvpdKeywordToHb
    {
        CVPD::cvpdKeyword keyword;
        // This is the fapi2 Index to the CVPD Keyword
        uint8_t keywordIndex;
    };
    static const cvpdKeywordToHb cvpdFapiKeywordToHbKeyword[] =
    {
        {CVPD::pdI, MBVPD_KEYWORD_PDI},
        {CVPD::PF,  MBVPD_KEYWORD_PF},
        {CVPD::MT,  MBVPD_KEYWORD_MT},
        {CVPD::MR,  MBVPD_KEYWORD_MR},
        {CVPD::pdA, MBVPD_KEYWORD_PDA},
        {CVPD::EL,  MBVPD_KEYWORD_EL},
        {CVPD::LM,  MBVPD_KEYWORD_LM},
        {CVPD::MW,  MBVPD_KEYWORD_MW},
        {CVPD::MV,  MBVPD_KEYWORD_MV},
        {CVPD::AM,  MBVPD_KEYWORD_AM},
        {CVPD::VZ,  MBVPD_KEYWORD_VZ},
        {CVPD::pdD, MBVPD_KEYWORD_PDD},
        {CVPD::MX,  MBVPD_KEYWORD_MX},
        {CVPD::DW,  MBVPD_KEYWORD_DW},
        {CVPD::PN,  MBVPD_KEYWORD_PN},
        {CVPD::SN,  MBVPD_KEYWORD_SN},
        {CVPD::DR,  MBVPD_KEYWORD_DR},
        {CVPD::CE,  MBVPD_KEYWORD_CE},
        {CVPD::FN,  MBVPD_KEYWORD_FN},
        {CVPD::CC,  MBVPD_KEYWORD_CC},
        {CVPD::HE,  MBVPD_KEYWORD_HE},
        {CVPD::CT,  MBVPD_KEYWORD_CT},
        {CVPD::HW,  MBVPD_KEYWORD_HW},
        {CVPD::VD,  MBVPD_KEYWORD_VD},
        {CVPD::VN,  MBVPD_KEYWORD_VN},
        {CVPD::VP,  MBVPD_KEYWORD_VP},
        {CVPD::VS,  MBVPD_KEYWORD_SV},
        {CVPD::M0,  MBVPD_KEYWORD_M0},
        {CVPD::M1,  MBVPD_KEYWORD_M1},
        {CVPD::M2,  MBVPD_KEYWORD_M2},
        {CVPD::M3,  MBVPD_KEYWORD_M3},
        {CVPD::M4,  MBVPD_KEYWORD_M4},
        {CVPD::M5,  MBVPD_KEYWORD_M5},
        {CVPD::M6,  MBVPD_KEYWORD_M6},
        {CVPD::M7,  MBVPD_KEYWORD_M7},
        {CVPD::M8,  MBVPD_KEYWORD_M8},
        {CVPD::T1,  MBVPD_KEYWORD_T1},
        {CVPD::T2,  MBVPD_KEYWORD_T2},
        {CVPD::T4,  MBVPD_KEYWORD_T4},
        {CVPD::T5,  MBVPD_KEYWORD_T5},
        {CVPD::T6,  MBVPD_KEYWORD_T6},
        {CVPD::T8,  MBVPD_KEYWORD_T8},
        {CVPD::Q0,  MBVPD_KEYWORD_Q0},
        {CVPD::Q1,  MBVPD_KEYWORD_Q1},
        {CVPD::Q2,  MBVPD_KEYWORD_Q2},
        {CVPD::Q3,  MBVPD_KEYWORD_Q3},
        {CVPD::Q4,  MBVPD_KEYWORD_Q4},
        {CVPD::Q5,  MBVPD_KEYWORD_Q5},
        {CVPD::Q6,  MBVPD_KEYWORD_Q6},
        {CVPD::Q7,  MBVPD_KEYWORD_Q7},
        {CVPD::Q8,  MBVPD_KEYWORD_Q8},
        {CVPD::K0,  MBVPD_KEYWORD_K0},
        {CVPD::K1,  MBVPD_KEYWORD_K1},
        {CVPD::K2,  MBVPD_KEYWORD_K2},
        {CVPD::K3,  MBVPD_KEYWORD_K3},
        {CVPD::K4,  MBVPD_KEYWORD_K4},
        {CVPD::K5,  MBVPD_KEYWORD_K5},
        {CVPD::K6,  MBVPD_KEYWORD_K6},
        {CVPD::K7,  MBVPD_KEYWORD_K7},
        {CVPD::K8,  MBVPD_KEYWORD_K8},
        {CVPD::MM,  MBVPD_KEYWORD_MM},
        {CVPD::SS,  MBVPD_KEYWORD_SS},
        {CVPD::ET,  MBVPD_KEYWORD_ET},
        {CVPD::VM,  MBVPD_KEYWORD_VM},
        {CVPD::pd1, MBVPD_KEYWORD_PD1},
        {CVPD::pdZ, MBVPD_KEYWORD_PDZ},
        {CVPD::pd4, MBVPD_KEYWORD_PD4},
        {CVPD::pd5, MBVPD_KEYWORD_PD5},
        {CVPD::pd6, MBVPD_KEYWORD_PD6},
        {CVPD::pd8, MBVPD_KEYWORD_PD8},
        {CVPD::pdY, MBVPD_KEYWORD_PDY},
    };
    const uint8_t NUM_CVPD_KEYWORDS =
       sizeof(cvpdFapiKeywordToHbKeyword)/sizeof(cvpdFapiKeywordToHbKeyword[0]);

    fapi2::ReturnCode l_rc;

    uint8_t l_index = static_cast<uint8_t>(i_fapiKeyword);



    if (l_index >= NUM_CVPD_KEYWORDS)
    {
        FAPI_ERR("CvpdKeywordXlate: Index went out of bounds looking for keyword: 0x%x", i_fapiKeyword);
        /*@
         * @errortype
         * @moduleid         MOD_FAPI2_CVPD_ACCESS
         * @reasoncode       RC_KEYWORD_OUT_OF_BOUNDS
         * @userdata1        Keyword enumerator
         * @userdata2[0:31]  Index
         * @userdata2[32:63] Max Index
         * @devdesc          Attempt to read an CVPD field using
         *                   an invalid keyword
         * @custdesc         Firmware error during IPL
         */

        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi2::MOD_FAPI2_CVPD_ACCESS,
            fapi2::RC_KEYWORD_OUT_OF_BOUNDS,
            i_fapiKeyword,
            TWO_UINT32_TO_UINT64(l_index,
            NUM_CVPD_KEYWORDS),
            true);

        //Set the keyword index to INVALID
        //Don't set the data because we dont know anything about it
        o_keywordIndex  = MBVPD_INVALID_CHIP_UNIT;

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }

    if(!l_rc)
    {
        o_hbKeyword    = cvpdFapiKeywordToHbKeyword[l_index].keyword;
        o_keywordIndex = cvpdFapiKeywordToHbKeyword[l_index].keywordIndex;
    }

    return l_rc;
}

//******************************************************************************
// getMvpdField
//******************************************************************************
fapi2::ReturnCode getMBvpdField
                (const fapi2::MBvpdRecord  i_record,
                 const fapi2::MBvpdKeyword i_keyword,
                 const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> &i_target,
                 uint8_t * const i_pBuffer,
                 size_t& io_fieldSize)
{
    uint8_t l_recIndex = MBVPD_INVALID_CHIP_UNIT;
    uint8_t l_keyIndex = MBVPD_INVALID_CHIP_UNIT;
    errlHndl_t l_errl = NULL;
    fapi2::ReturnCode l_rc;
    FAPI_DBG("getMBvpdField entry");

    do
    {
        // Translate the FAPI record to a Hostboot record
        CVPD::cvpdRecord l_hbRecord = CVPD::CVPD_INVALID_RECORD;

        l_rc = fapi2::CvpdRecordXlate(i_record, l_hbRecord, l_recIndex);

        if (l_rc)
        {
            break;
        }

        // Translate the FAPI keyword to a Hostboot keyword
        CVPD::cvpdKeyword l_hbKeyword = CVPD::CVPD_INVALID_KEYWORD;

        l_rc = fapi2::CvpdKeywordXlate(i_keyword, l_hbKeyword, l_keyIndex);

        if (l_rc)
        {
            break;
        }

        // deviceRead will return the size of the field if the
        // pointer is NULL
        size_t l_fieldLen = io_fieldSize;

        l_errl = deviceRead(
                reinterpret_cast< TARGETING::Target*>(i_target.get()),
                i_pBuffer,
                l_fieldLen,
                DEVICE_CVPD_ADDRESS(l_hbRecord, l_hbKeyword));

        if (l_errl)
        {
            FAPI_ERR("getMBvpdField: ERROR: deviceRead : errorlog PLID=0x%x",
                    l_errl->plid());

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));

            break;
        }

        // Success, update callers io_fieldSize for the case where the
        // pointer is NULL and deviceRead returned the actual size
        io_fieldSize = l_fieldLen;

        FAPI_DBG("getMBvpdField: returning field len=0x%x", io_fieldSize);

    } while(0);

    if( l_rc)
    {
        io_fieldSize = 0;
    }

    FAPI_DBG( "getMBvpdField: exit" );

    return  l_rc;
}

//******************************************************************************
// setMBvpdField
//******************************************************************************
fapi2::ReturnCode setMBvpdField
                (const fapi2::MBvpdRecord i_record,
                 const fapi2::MBvpdKeyword i_keyword,
                 const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> &i_target,
                 const uint8_t * const i_pBuffer,
                 const uint32_t i_fieldSize)
{
    fapi2::ReturnCode l_rc;
    uint8_t l_recIndex = MBVPD_INVALID_CHIP_UNIT;
    uint8_t l_keyIndex = MBVPD_INVALID_CHIP_UNIT;
    errlHndl_t l_errl = NULL;
    FAPI_DBG("setMBvpdField entry");

    do
    {
        // Translate the FAPI record to a Hostboot record
        CVPD::cvpdRecord l_hbRecord = CVPD::CVPD_INVALID_RECORD;

        l_rc = fapi2::CvpdRecordXlate(i_record, l_hbRecord, l_recIndex);

        if (l_rc)
        {
            break;
        }

        // Translate the FAPI keyword to a Hostboot keyword
        CVPD::cvpdKeyword l_hbKeyword = CVPD::CVPD_INVALID_KEYWORD;

        l_rc = fapi2::CvpdKeywordXlate(i_keyword, l_hbKeyword, l_keyIndex);

        if (l_rc)
        {
            break;
        }

        size_t l_fieldLen = i_fieldSize;

        l_errl = deviceWrite(
                reinterpret_cast< TARGETING::Target*>(i_target.get()),
                const_cast<uint8_t *>(i_pBuffer),
                l_fieldLen,
                DEVICE_CVPD_ADDRESS(l_hbRecord, l_hbKeyword));

    } while(0);

    if (l_errl)
    {
        FAPI_ERR("setMBvpdField: ERROR: deviceWrite : errorlog PLID=0x%x",
                l_errl->plid());

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));

    }

    FAPI_DBG( "setMBvpdField: exit" );

    return  l_rc;
}

} // fapi2

