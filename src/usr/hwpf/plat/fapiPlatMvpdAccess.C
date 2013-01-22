/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatMvpdAccess.C $                      */
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
/**
 *  @file fapiPlatMvpdAccess.C
 *
 *  @brief Implements the fapiMvpdAccess.H functions
 */

#include    <stdint.h>
#include    <errl/errlentry.H>

//  fapi support
#include <fapiMvpdAccess.H>
#include <hwpf/hwpf_reasoncodes.H>

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>


namespace fapi
{

//******************************************************************************
// MvpdRecordXlate
// Translates a FAPI MVPD Record enumerator into a Hostboot MVPD Record
// enumerator
//******************************************************************************
fapi::ReturnCode MvpdRecordXlate(const fapi::MvpdRecord i_fapiRecord,
                                 MVPD::mvpdRecord & o_hbRecord)
{
    // Create a lookup table for converting a FAPI MVPD record enumerator to a
    // Hostboot MVPD record enumerator. This is a simple array and relies on
    // the FAPI record enumerators starting at zero and incrementing.
    const uint8_t NUM_MVPD_RECORDS = 0x1c;
    static const MVPD::mvpdRecord mvpdFapiRecordToHbRecord[NUM_MVPD_RECORDS] =
    {
        MVPD::CRP0,
        MVPD::CP00,
        MVPD::VINI,
        MVPD::LRP0,
        MVPD::LRP1,
        MVPD::LRP2,
        MVPD::LRP3,
        MVPD::LRP4,
        MVPD::LRP5,
        MVPD::LRP6,
        MVPD::LRP7,
        MVPD::LRP8,
        MVPD::LRP9,
        MVPD::LRPA,
        MVPD::LRPB,
        MVPD::LWP0,
        MVPD::LWP1,
        MVPD::LWP2,
        MVPD::LWP3,
        MVPD::LWP4,
        MVPD::LWP5,
        MVPD::LWP6,
        MVPD::LWP7,
        MVPD::LWP8,
        MVPD::LWP9,
        MVPD::LWPA,
        MVPD::LWPB,
        MVPD::VWML,
    };
    
    fapi::ReturnCode l_rc;
    
    uint8_t l_index = static_cast<uint8_t>(i_fapiRecord);
    
    if (l_index >= NUM_MVPD_RECORDS)
    {
        FAPI_ERR("MvpdRecordXlate: Invalid MVPD Record: 0x%x", i_fapiRecord);
        /*@
         * @errortype
         * @moduleid     MOD_MVPD_ACCESS
         * @reasoncode   RC_INVALID_RECORD
         * @userdata1    Record enumerator
         * @devdesc      Attempt to read an MVPD field using an invalid record
         */
        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi::MOD_MVPD_ACCESS,
            fapi::RC_INVALID_RECORD,
            i_fapiRecord);
        
        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        o_hbRecord = mvpdFapiRecordToHbRecord[l_index];
    }
    
    return l_rc;
}

//******************************************************************************
// MvpdKeywordXlate
// Translates a FAPI MVPD Keyword enumerator into a Hostboot MVPD Keyword
// enumerator
//******************************************************************************
fapi::ReturnCode MvpdKeywordXlate(const fapi::MvpdKeyword i_fapiKeyword,
                                  MVPD::mvpdKeyword & o_hbKeyword)
{
    // Create a lookup table for converting a FAPI MVPD keyword enumerator to a
    // Hostboot MVPD keyword enumerator. This is a simple array and relies on
    // the FAPI record enumerators starting at zero and incrementing.
    const uint8_t NUM_MVPD_KEYWORDS = 0x22;
    static const MVPD::mvpdKeyword
        mvpdFapiKeywordToHbKeyword[NUM_MVPD_KEYWORDS] =
    {
        MVPD::VD,
        MVPD::ED,
        MVPD::TE,
        MVPD::DD,
        MVPD::pdP,
        MVPD::ST,
        MVPD::DN,
        MVPD::PG,
        MVPD::PK,
        MVPD::pdR,
        MVPD::pdV,
        MVPD::pdH,
        MVPD::SB,
        MVPD::DR,
        MVPD::VZ,
        MVPD::CC,
        MVPD::CE,
        MVPD::FN,
        MVPD::PN,
        MVPD::SN,
        MVPD::PR,
        MVPD::HE,
        MVPD::CT,
        MVPD::HW,
        MVPD::pdM,
        MVPD::IN,
        MVPD::pd2,
        MVPD::pd3,
        MVPD::OC,
        MVPD::FO,
        MVPD::pdI,
        MVPD::pdG,
        MVPD::MK,
        MVPD::PB,
    };
    
    fapi::ReturnCode l_rc;
    
    uint8_t l_index = static_cast<uint8_t>(i_fapiKeyword);
    
    if (l_index >= NUM_MVPD_KEYWORDS)
    {
        FAPI_ERR("MvpdKeywordXlate: Invalid MVPD Keyword: 0x%x", i_fapiKeyword);
        /*@
         * @errortype
         * @moduleid     MOD_MVPD_ACCESS
         * @reasoncode   RC_INVALID_KEYWORD
         * @userdata1    Keyword enumerator
         * @devdesc      Attempt to read an MVPD field using an invalid keyword
         */
        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi::MOD_MVPD_ACCESS,
            fapi::RC_INVALID_KEYWORD,
            i_fapiKeyword);
        
        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        o_hbKeyword = mvpdFapiKeywordToHbKeyword[l_index];
    }
    
    return l_rc;
}

}

extern "C"
{

//******************************************************************************
// fapiGetMvpdField
//******************************************************************************
fapi::ReturnCode fapiGetMvpdField(const fapi::MvpdRecord i_record,
                                  const fapi::MvpdKeyword i_keyword,
                                  const fapi::Target &i_procTarget,
                                  uint8_t * const i_pBuffer,
                                  uint32_t &io_fieldSize)
{
    fapi::ReturnCode l_rc;
    FAPI_DBG("fapiGetMvpdField entry");

    do
    {
        // Translate the FAPI record to a Hostboot record
        MVPD::mvpdRecord l_hbRecord = MVPD::MVPD_INVALID_RECORD;
        
        l_rc = fapi::MvpdRecordXlate(i_record, l_hbRecord);
        
        if (l_rc)
        {
            break;
        }
        
        // Translate the FAPI keyword to a Hostboot keyword
        MVPD::mvpdKeyword l_hbKeyword = MVPD::INVALID_MVPD_KEYWORD;
        
        l_rc = fapi::MvpdKeywordXlate(i_keyword, l_hbKeyword);
        
        if (l_rc)
        {
            break;
        }
                
        // Similarly to this function, deviceRead will return the size of the
        // field if the pointer is NULL
        size_t l_fieldLen = io_fieldSize;

        errlHndl_t l_errl = deviceRead(
            reinterpret_cast< TARGETING::Target*>(i_procTarget.get()),
            i_pBuffer,
            l_fieldLen,
            DEVICE_MVPD_ADDRESS(l_hbRecord, l_hbKeyword));
        
        if (l_errl)
        {
            FAPI_ERR("fapiGetMvpdField: ERROR: deviceRead : errorlog PLID=0x%x",
                     l_errl->plid());

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_errl));

            break;
        }

        // Success, update callers io_fieldSize for the case where the pointer
        // is NULL and deviceRead returned the actual size
        io_fieldSize = l_fieldLen;
        FAPI_DBG("fapiGetMvpdField: returning field len=0x%x", io_fieldSize);

    } while(0);

    FAPI_DBG( "fapiGetMvpdField: exit" );

    return  l_rc;
}

//******************************************************************************
// fapiSetMvpdField
//******************************************************************************
fapi::ReturnCode fapiSetMvpdField(const fapi::MvpdRecord i_record,
                                  const fapi::MvpdKeyword i_keyword,
                                  const fapi::Target &i_procTarget,
                                  const uint8_t * const i_pBuffer,
                                  const uint32_t i_fieldSize)
{
    fapi::ReturnCode l_rc;
    FAPI_DBG("fapiSetMvpdField entry");

    do
    {
        // Translate the FAPI record to a Hostboot record
        MVPD::mvpdRecord l_hbRecord = MVPD::MVPD_INVALID_RECORD;
        
        l_rc = fapi::MvpdRecordXlate(i_record, l_hbRecord);
        
        if (l_rc)
        {
            break;
        }
        
        // Translate the FAPI keyword to a Hostboot keyword
        MVPD::mvpdKeyword l_hbKeyword = MVPD::INVALID_MVPD_KEYWORD;
        
        l_rc = fapi::MvpdKeywordXlate(i_keyword, l_hbKeyword);
        
        if (l_rc)
        {
            break;
        }
                
        size_t l_fieldLen = i_fieldSize;

        errlHndl_t l_errl = deviceWrite(
            reinterpret_cast< TARGETING::Target*>(i_procTarget.get()),
            const_cast<uint8_t *>(i_pBuffer),
            l_fieldLen,
            DEVICE_MVPD_ADDRESS(l_hbRecord, l_hbKeyword));
        
        if (l_errl)
        {
            FAPI_ERR("fapiSetMvpdField: ERROR: deviceWrite : errorlog PLID=0x%x",
                     l_errl->plid());

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_errl));

            break;
        }

    } while(0);

    FAPI_DBG( "fapiSetMvpdField: exit" );

    return  l_rc;
}

} // extern "C"
