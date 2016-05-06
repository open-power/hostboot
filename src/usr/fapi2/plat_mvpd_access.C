/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_mvpd_access.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
 *  @file  plat_mvpd_access.C
 *
 *  @brief Implements the mvpd_access.H functions
 */

#include    <stdint.h>
#include    <errl/errlentry.H>

// fapi2 support changes
#include <mvpd_access.H>
#include <mvpd_access_defs.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>

// Invalid chip unit
const uint8_t MVPD_INVALID_CHIP_UNIT = 0xFF;

namespace fapi2
{

//******************************************************************************
// MvpdRecordXlate
// Translates a FAPI MVPD Record enumerator into a Hostboot MVPD Record
// enumerator
//******************************************************************************
fapi2::ReturnCode MvpdRecordXlate(const fapi2::MvpdRecord i_fapiRecord,
                                 MVPD::mvpdRecord & o_hbRecord,
                                 uint8_t & o_recordIndex)
{
    // Create a lookup table for converting a FAPI MVPD record enumerator to a
    // Hostboot MVPD record enumerator. This is a simple array and relies on
    // the FAPI record enumerators starting at zero and incrementing.

    //Structure to map fapi2::MVPD_RECORD to chiplet chip num position
    struct mvpdRecordToChip
    {
        MVPD::mvpdRecord rec;
        // This is the fapi2 Index to the MVPD record
        uint8_t recIndex;
    };
    static const mvpdRecordToChip mvpdFapiRecordToHbRecord[] =
    {
        /** MVPD record mapping to FAPI2 MVPD **/
        {MVPD::CRP0,MVPD_RECORD_CRP0},
        {MVPD::CP00,MVPD_RECORD_CP00},
        {MVPD::VINI,MVPD_RECORD_VINI},
        {MVPD::LRP0,MVPD_RECORD_LRP0},
        {MVPD::LRP1,MVPD_RECORD_LRP1},
        {MVPD::LRP2,MVPD_RECORD_LRP2},
        {MVPD::LRP3,MVPD_RECORD_LRP3},
        {MVPD::LRP4,MVPD_RECORD_LRP4},
        {MVPD::LRP5,MVPD_RECORD_LRP5},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LRP6},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LRP7},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LRP8},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LRP9},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LRPA},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LRPB},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LRPC},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LRPD},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LRPE},
        {MVPD::LWP0,MVPD_RECORD_LWP0},
        {MVPD::LWP1,MVPD_RECORD_LWP1},
        {MVPD::LWP2,MVPD_RECORD_LWP2},
        {MVPD::LWP3,MVPD_RECORD_LWP3},
        {MVPD::LWP4,MVPD_RECORD_LWP4},
        {MVPD::LWP5,MVPD_RECORD_LWP5},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LWP6},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LWP7},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LWP8},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LWP9},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LWPA},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LWPB},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LWPC},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LWPD},
        {MVPD::MVPD_INVALID_RECORD,MVPD_RECORD_LWPE},
        /* Record available in HB but not in FAPI*/
        //{MVPD::VRML,MVPD_RECORD_VRML},
        {MVPD::VWML,MVPD_RECORD_VWML},
        {MVPD::MER0,MVPD_RECORD_MER0},
        //{MVPD::VMSC,MVPD_RECORD_VMSC},
    };
    const uint8_t NUM_MVPD_RECORDS =
           sizeof(mvpdFapiRecordToHbRecord)/sizeof(mvpdFapiRecordToHbRecord[0]);

    fapi2::ReturnCode l_rc;

    uint8_t l_index = static_cast<uint8_t>(i_fapiRecord);

    if (l_index >= NUM_MVPD_RECORDS)
    {
        FAPI_ERR("MvpdRecordXlate: Index went out of bounds looking for record: 0x%x", i_fapiRecord);
        /*@
         * @errortype
         * @moduleid         MOD_FAPI2_MVPD_ACCESS
         * @reasoncode       RC_RECORD_OUT_OF_BOUNDS
         * @userdata1        Record enumerator
         * @userdata2[0:31]  Index
         * @userdata2[32:63] Max Index
         * @devdesc          Attempt to read an MVPD field using
         *                   an invalid record
         * @custdesc         Firmware error during IPL
         */

        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi2::MOD_FAPI2_MVPD_ACCESS,
            fapi2::RC_RECORD_OUT_OF_BOUNDS,
            i_fapiRecord,
            TWO_UINT32_TO_UINT64(l_index,
            NUM_MVPD_RECORDS),
            true);

        //Set the record index to INVALID
        //Don't set the data because we dont know anything about it
        o_recordIndex  = MVPD_INVALID_CHIP_UNIT;

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }
    else if(mvpdFapiRecordToHbRecord[l_index].rec == MVPD::MVPD_INVALID_RECORD)
    {
        FAPI_ERR("MvpdRecordXlate: Invalid MVPD Record: 0x%x", i_fapiRecord);
        /*@
         * @errortype
         * @moduleid     MOD_FAPI2_MVPD_ACCESS
         * @reasoncode   RC_INVALID_RECORD
         * @userdata1    Record enumerator
         * @devdesc      Attempt to read an MVPD field using an invalid record
         * @custdesc     Firmware error during IPL
         */

        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi2::MOD_FAPI2_MVPD_ACCESS,
            fapi2::RC_INVALID_RECORD,
            i_fapiRecord, 0, true);

        //Set information that we found
        o_hbRecord     = MVPD::MVPD_INVALID_RECORD;
        o_recordIndex = mvpdFapiRecordToHbRecord[l_index].recIndex;

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }


    if(!l_rc)
    {
        o_hbRecord    = mvpdFapiRecordToHbRecord[l_index].rec;
        o_recordIndex = mvpdFapiRecordToHbRecord[l_index].recIndex;
    }

    return l_rc;
}

//******************************************************************************
// MvpdKeywordXlate
// Translates a FAPI MVPD Keyword enumerator into a Hostboot MVPD Keyword
// enumerator
//******************************************************************************
fapi2::ReturnCode MvpdKeywordXlate(const fapi2::MvpdKeyword i_fapiKeyword,
                                  MVPD::mvpdKeyword & o_hbKeyword,
                                  uint8_t & o_keywordIndex)
{
    // Create a lookup table for converting a FAPI MVPD keyword enumerator to a
    // Hostboot MVPD keyword enumerator. This is a simple array and relies on
    // the FAPI keyword enumerators starting at zero and incrementing.
    //Structure to map fapi2::MVPD_KEYWORD to chiplet chip num position
    struct mvpdKeywordToHb
    {
        MVPD::mvpdKeyword keyword;
        // This is the fapi2 Index to the MVPD Keyword
        uint8_t keywordIndex;
    };
    static const mvpdKeywordToHb mvpdFapiKeywordToHbKeyword[] =
    {
        {MVPD::VD,  MVPD_KEYWORD_VD},
        {MVPD::ED,  MVPD_KEYWORD_ED},
        {MVPD::TE,  MVPD_KEYWORD_TE},
        {MVPD::DD,  MVPD_KEYWORD_DD},
        {MVPD::INVALID_MVPD_KEYWORD,  MVPD_KEYWORD_PDP},
        {MVPD::INVALID_MVPD_KEYWORD,  MVPD_KEYWORD_ST},
        {MVPD::DN,  MVPD_KEYWORD_DN},
        {MVPD::PG,  MVPD_KEYWORD_PG},
        {MVPD::PK,  MVPD_KEYWORD_PK},
        {MVPD::pdR, MVPD_KEYWORD_PDR},
        {MVPD::pdV, MVPD_KEYWORD_PDV},
        {MVPD::pdH, MVPD_KEYWORD_PDH},
        {MVPD::SB,  MVPD_KEYWORD_SB},
        {MVPD::DR,  MVPD_KEYWORD_DR},
        {MVPD::VZ,  MVPD_KEYWORD_VZ},
        {MVPD::CC,  MVPD_KEYWORD_CC},
        {MVPD::CE,  MVPD_KEYWORD_CE},
        {MVPD::FN,  MVPD_KEYWORD_FN},
        {MVPD::PN,  MVPD_KEYWORD_PN},
        {MVPD::SN,  MVPD_KEYWORD_SN},
        {MVPD::PR,  MVPD_KEYWORD_PR},
        {MVPD::HE,  MVPD_KEYWORD_HE},
        {MVPD::CT,  MVPD_KEYWORD_CT},
        {MVPD::HW,  MVPD_KEYWORD_HW},
        {MVPD::pdM, MVPD_KEYWORD_PDM},
        {MVPD::IN,  MVPD_KEYWORD_IN},
        {MVPD::INVALID_MVPD_KEYWORD,  MVPD_KEYWORD_PD2},
        {MVPD::INVALID_MVPD_KEYWORD,  MVPD_KEYWORD_PD3},
        {MVPD::INVALID_MVPD_KEYWORD,  MVPD_KEYWORD_OC},
        {MVPD::INVALID_MVPD_KEYWORD,  MVPD_KEYWORD_FO},
        {MVPD::pdI, MVPD_KEYWORD_PDI},
        {MVPD::pdG, MVPD_KEYWORD_PDG},
        {MVPD::INVALID_MVPD_KEYWORD,  MVPD_KEYWORD_MK},
        {MVPD::PB,  MVPD_KEYWORD_PB},
        {MVPD::CH,  MVPD_KEYWORD_CH},
        {MVPD::IQ,  MVPD_KEYWORD_IQ},

        /*Keywords available in HB but not in FAPI enum*/
        //{MVPD::PM,  MVPD_KEYWORD_PM},
        //{MVPD::PZ,  MVPD_KEYWORD_PZ},
        //{MVPD::n20, MVPD_KEYWORD_N20},
        //{MVPD::n21, MVPD_KEYWORD_N21},
        //{MVPD::n30, MVPD_KEYWORD_N30},
        //{MVPD::n31, MVPD_KEYWORD_N31},
    };
    const uint8_t NUM_MVPD_KEYWORDS =
       sizeof(mvpdFapiKeywordToHbKeyword)/sizeof(mvpdFapiKeywordToHbKeyword[0]);

    fapi2::ReturnCode l_rc;

    uint8_t l_index = static_cast<uint8_t>(i_fapiKeyword);



    if (l_index >= NUM_MVPD_KEYWORDS)
    {
        FAPI_ERR("MvpdKeywordXlate: Index went out of bounds looking for keyword: 0x%x", i_fapiKeyword);
        /*@
         * @errortype
         * @moduleid         MOD_FAPI2_MVPD_ACCESS
         * @reasoncode       RC_KEYWORD_OUT_OF_BOUNDS
         * @userdata1        Keyword enumerator
         * @userdata2[0:31]  Index
         * @userdata2[32:63] Max Index
         * @devdesc          Attempt to read an MVPD field using
         *                   an invalid keyword
         * @custdesc         Firmware error during IPL
         */

        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi2::MOD_FAPI2_MVPD_ACCESS,
            fapi2::RC_KEYWORD_OUT_OF_BOUNDS,
            i_fapiKeyword,
            TWO_UINT32_TO_UINT64(l_index,
            NUM_MVPD_KEYWORDS),
            true);

        //Set the keyword index to INVALID
        //Don't set the data because we dont know anything about it
        o_keywordIndex  = MVPD_INVALID_CHIP_UNIT;

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }
    else if(mvpdFapiKeywordToHbKeyword[l_index].keyword == MVPD::INVALID_MVPD_KEYWORD)
    {
        FAPI_ERR("MvpdKeywordXlate: Invalid MVPD Keyword: 0x%x", i_fapiKeyword);
        /*@
        * @errortype
        * @moduleid     MOD_FAPI2_MVPD_ACCESS
        * @reasoncode   RC_INVALID_KEYWORD
        * @userdata1    Keyword enumerator
        * @devdesc      Attempt to read an MVPD field using an invalid keyword
        * @custdesc     Firmware error during IPL
        */

        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi2::MOD_FAPI2_MVPD_ACCESS,
            fapi2::RC_INVALID_KEYWORD,
            i_fapiKeyword, 0, true);

        //Set information that we found
        o_hbKeyword     = MVPD::INVALID_MVPD_KEYWORD;
        o_keywordIndex = mvpdFapiKeywordToHbKeyword[l_index].keywordIndex;

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }

    if(!l_rc)
    {
        o_hbKeyword    = mvpdFapiKeywordToHbKeyword[l_index].keyword;
        o_keywordIndex = mvpdFapiKeywordToHbKeyword[l_index].keywordIndex;
    }

    return l_rc;
}

//******************************************************************************
// getMvpdField
//******************************************************************************
fapi2::ReturnCode getMvpdField
                (const fapi2::MvpdRecord i_record,
                const fapi2::MvpdKeyword i_keyword,
                const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> &i_procTarget,
                uint8_t * const i_pBuffer,
                uint32_t &io_fieldSize)
{
    uint8_t l_recIndex = MVPD_INVALID_CHIP_UNIT;
    uint8_t l_keyIndex = MVPD_INVALID_CHIP_UNIT;
    errlHndl_t l_errl = NULL;
    fapi2::ReturnCode l_rc;
    FAPI_DBG("getMvpdField entry");

    do
    {
        // Translate the FAPI record to a Hostboot record
        MVPD::mvpdRecord l_hbRecord = MVPD::MVPD_INVALID_RECORD;

        l_rc = fapi2::MvpdRecordXlate(i_record, l_hbRecord, l_recIndex);

        if (l_rc)
        {
            break;
        }

        // Translate the FAPI keyword to a Hostboot keyword
        MVPD::mvpdKeyword l_hbKeyword = MVPD::INVALID_MVPD_KEYWORD;

        l_rc = fapi2::MvpdKeywordXlate(i_keyword, l_hbKeyword, l_keyIndex);

        if (l_rc)
        {
            break;
        }

        // deviceRead will return the size of the field if the
        // pointer is NULL
        size_t l_fieldLen = io_fieldSize;

        l_errl = deviceRead(
                reinterpret_cast< TARGETING::Target*>(i_procTarget.get()),
                i_pBuffer,
                l_fieldLen,
                DEVICE_MVPD_ADDRESS(l_hbRecord, l_hbKeyword));

        if (l_errl)
        {
            FAPI_ERR("getMvpdField: ERROR: deviceRead : errorlog PLID=0x%x",
                    l_errl->plid());

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));

            break;
        }

        // Success, update callers io_fieldSize for the case where the
        // pointer is NULL and deviceRead returned the actual size
        io_fieldSize = l_fieldLen;

        FAPI_DBG("getMvpdField: returning field len=0x%x", io_fieldSize);

    } while(0);

    if( l_rc)
    {
        io_fieldSize = 0;
    }

    FAPI_DBG( "getMvpdField: exit" );

    return  l_rc;
}

//******************************************************************************
// setMvpdField
//******************************************************************************
fapi2::ReturnCode setMvpdField
                (const fapi2::MvpdRecord i_record,
                const fapi2::MvpdKeyword i_keyword,
                const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> &i_procTarget,
                const uint8_t * const i_pBuffer,
                const uint32_t i_fieldSize)
{
    fapi2::ReturnCode l_rc;
    uint8_t l_recIndex = MVPD_INVALID_CHIP_UNIT;
    uint8_t l_keyIndex = MVPD_INVALID_CHIP_UNIT;
    errlHndl_t l_errl = NULL;
    FAPI_DBG("setMvpdField entry");

    do
    {
        // Translate the FAPI record to a Hostboot record
        MVPD::mvpdRecord l_hbRecord = MVPD::MVPD_INVALID_RECORD;

        l_rc = fapi2::MvpdRecordXlate(i_record, l_hbRecord, l_recIndex);

        if (l_rc)
        {
            break;
        }

        // Translate the FAPI keyword to a Hostboot keyword
        MVPD::mvpdKeyword l_hbKeyword = MVPD::INVALID_MVPD_KEYWORD;

        l_rc = fapi2::MvpdKeywordXlate(i_keyword, l_hbKeyword, l_keyIndex);

        if (l_rc)
        {
            break;
        }

        size_t l_fieldLen = i_fieldSize;

        l_errl = deviceWrite(
                reinterpret_cast< TARGETING::Target*>(i_procTarget.get()),
                const_cast<uint8_t *>(i_pBuffer),
                l_fieldLen,
                DEVICE_MVPD_ADDRESS(l_hbRecord, l_hbKeyword));

    } while(0);

    if (l_errl)
    {
        FAPI_ERR("setMvpdField: ERROR: deviceWrite : errorlog PLID=0x%x",
                l_errl->plid());

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));

    }

    FAPI_DBG( "setMvpdField: exit" );

    return  l_rc;
}

} // fapi2

