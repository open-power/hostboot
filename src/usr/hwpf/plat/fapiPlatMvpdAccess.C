/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatMvpdAccess.C $                      */
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
/**
 *  @file fapiPlatMvpdAccess.C
 *
 *  @brief Implements the fapiMvpdAccess.H functions
 */

#include    <stdint.h>
#include    <errl/errlentry.H>
#include    <freqVoltageSvc.H>

//  fapi support
#include <fapiAttributeService.H>
#include <fapiMvpdAccess.H>
#include <fapiSystemConfig.H>
#include <hwpf/hwpf_reasoncodes.H>

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>

const uint8_t NON_ECO_VOLTAGE_BUCKET_OFFFSET = 0x04;
const uint8_t ALTERNATE_BUCKET_OFFSET = 0x05;
const uint8_t BUCKET_ID_MASK = 0x0F;
const uint8_t DEFAULT_BUCKET = 1;
const uint8_t VERSION_01_BUCKET_SZ = 0x33; // 51 decimal
const uint8_t POUND_V_VERSION_01 = 0x01;

// Decimal 50 - 2 bytes for each 25 attributes.
const uint8_t MAX_MVPD_VOLTAGE_BUCKET_ATTR_SZ = 0x32;
// Two byte shift
const uint8_t MVPD_TWO_BYTE_ATTR_VAL_SHIFT = 0x10;
// Invalid chip unit
const uint8_t MVPD_INVALID_CHIP_UNIT = 0xFF;

namespace fapi
{

//******************************************************************************
// MvpdRecordXlate
// Translates a FAPI MVPD Record enumerator into a Hostboot MVPD Record
// enumerator
//******************************************************************************
fapi::ReturnCode MvpdRecordXlate(const fapi::MvpdRecord i_fapiRecord,
                                 MVPD::mvpdRecord & o_hbRecord,
                                 uint8_t & o_chipUnitNum)
{
    // Create a lookup table for converting a FAPI MVPD record enumerator to a
    // Hostboot MVPD record enumerator. This is a simple array and relies on
    // the FAPI record enumerators starting at zero and incrementing.

    //Structure to map fapi::MVPD_RECORD to chiplet chip num position
    struct mvpdRecordToChip
    {
        MVPD::mvpdRecord rec;
        // This is the chip unit position. 0xFF means record associated to all
        // chiplets, any other number means record associated to the ex chiplet
        // corresponding to that number.
        uint8_t exChipNum;
    };
    static const mvpdRecordToChip mvpdFapiRecordToHbRecord[] =
    {
        {MVPD::CRP0,0xFF},
        {MVPD::CP00,0xFF},
        {MVPD::VINI,0xFF},
        {MVPD::LRP0,0x00},
        {MVPD::LRP1,0x01},
        {MVPD::LRP2,0x02},
        {MVPD::LRP3,0x03},
        {MVPD::LRP4,0x04},
        {MVPD::LRP5,0x05},
        {MVPD::LRP6,0x06},
        {MVPD::LRP7,0x07},
        {MVPD::LRP8,0x08},
        {MVPD::LRP9,0x09},
        {MVPD::LRPA,0x0A},
        {MVPD::LRPB,0x0B},
        {MVPD::LRPC,0x0C},
        {MVPD::LRPD,0x0D},
        {MVPD::LRPE,0x0E},
        {MVPD::LWP0,0x00},
        {MVPD::LWP1,0x01},
        {MVPD::LWP2,0x02},
        {MVPD::LWP3,0x03},
        {MVPD::LWP4,0x04},
        {MVPD::LWP5,0x05},
        {MVPD::LWP6,0x06},
        {MVPD::LWP7,0x07},
        {MVPD::LWP8,0x08},
        {MVPD::LWP9,0x09},
        {MVPD::LWPA,0x0A},
        {MVPD::LWPB,0x0B},
        {MVPD::LWPC,0x0C},
        {MVPD::LWPD,0x0D},
        {MVPD::LWPE,0x0E},
        {MVPD::VWML,0xFF},
        {MVPD::MER0,0xFF},
    };
    const uint8_t NUM_MVPD_RECORDS =
           sizeof(mvpdFapiRecordToHbRecord)/sizeof(mvpdFapiRecordToHbRecord[0]);

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
        const bool hbSwError = true;
        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi::MOD_MVPD_ACCESS,
            fapi::RC_INVALID_RECORD,
            i_fapiRecord, 0, hbSwError);

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        o_hbRecord = mvpdFapiRecordToHbRecord[l_index].rec;
        o_chipUnitNum = mvpdFapiRecordToHbRecord[l_index].exChipNum;
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
    static const MVPD::mvpdKeyword
        mvpdFapiKeywordToHbKeyword[] =
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
        MVPD::CH,
        MVPD::IQ,
    };
    const uint8_t NUM_MVPD_KEYWORDS =
       sizeof(mvpdFapiKeywordToHbKeyword)/sizeof(mvpdFapiKeywordToHbKeyword[0]);

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
        const bool hbSwError = true;
        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi::MOD_MVPD_ACCESS,
            fapi::RC_INVALID_KEYWORD,
            i_fapiKeyword, 0, hbSwError);

        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        o_hbKeyword = mvpdFapiKeywordToHbKeyword[l_index];
    }

    return l_rc;
}

//******************************************************************************
// getVoltageBucketAttr
//******************************************************************************
fapi::ReturnCode getVoltageBucketAttr(const fapi::Target & i_exchplet,
                                      const fapi::voltageBucketData_t & i_data,
                                      uint8_t * io_pData,
                                      uint32_t & io_dataSz)
{
    fapi::ReturnCode l_rc;
    do
    {
        if( io_dataSz < MAX_MVPD_VOLTAGE_BUCKET_ATTR_SZ)
        {
            FAPI_ERR("getVltgBucketAttr: Invalid buffer size:0x%08X,"
                     "expected:0x%08X",io_dataSz,
                     MAX_MVPD_VOLTAGE_BUCKET_ATTR_SZ);
            errlHndl_t l_err = NULL;

            /*@
             * @errortype
             * @moduleid     fapi::MOD_PLAT_MVPD_GET_VLTG_BUCKET_ATTR
             * @reasoncode   fapi::RC_INVALID_SIZE
             * @userdata1    Invalid input length
             * @userdata2    Expected length
             * @devdesc      Input buffer size is smaller than expected length.
             */
            l_err =
                new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 fapi::MOD_PLAT_MVPD_GET_VLTG_BUCKET_ATTR,
                                 fapi::RC_INVALID_SIZE,
                                 io_dataSz,
                                 MAX_MVPD_VOLTAGE_BUCKET_ATTR_SZ);

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

        //NOTE: Below attributes are read and value written to the output
        // buffer as the VPD voltage bucket data layout. See MVPD documentation
        // for more details
        uint32_t l_data = 0;
        uint32_t l_idx = 0;
        // Write bucket id. This is written directly as this is not an
        // override attribute (cannot be changed).
        io_pData[l_idx] = i_data.bucketId;
        l_idx++;
        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_NOM_FREQ_MHZ,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_NOM_FREQ_MHZ");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_V_NEST_NOM_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                      "ATTR_OVERRIDE_MVPD_V_NEST_NOM_VOLTAGE");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_I_NEST_NOM_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_I_NEST_NOM_CURRENT");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_V_CS_NOM_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_V_CS_NOM_VOLTAGE");
            break;
        }

        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_I_CS_NOM_CURRENT,
                             &i_exchplet,
                             l_data);
        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_I_CS_NOM_CURRENT");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_PS_FREQ_MHZ,&i_exchplet,
                             l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_PS_FREQ_MHZ");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_V_NEST_PS_VOLTAGE,&i_exchplet,
                             l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_V_NEST_PS_VOLTAGE");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_I_NEST_PS_CURRENT,&i_exchplet,
                             l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_I_NEST_PS_CURRENT");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_V_CS_PS_VOLTAGE,&i_exchplet,
                             l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_V_CS_PS_VOLTAGE");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_I_CS_PS_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_I_CS_PS_CURRENT");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_TURBO_FREQ_MHZ,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_TURBO_FREQ_MHZ");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_V_NEST_TURBO_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_V_NEST_TURBO_VOLTAGE");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_I_NEST_TURBO_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_I_NEST_TURBO_CURRENT");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_V_CS_TURBO_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_V_CS_TURBO_VOLTAGE");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_I_CS_TURBO_CURRENT,
                             &i_exchplet, l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_I_CS_TURBO_CURRENT");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_FVMIN_FREQ_MHZ,
                             &i_exchplet,l_data);
        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_FVMIN_FREQ_MHZ");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_V_NEST_FVMIN_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_V_NEST_FVMIN_VOLTAGE");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_I_NEST_FVMIN_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_I_NEST_FVMIN_CURRENT");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_V_CS_FVMIN_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_V_CS_FVMIN_VOLTAGE");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_I_CS_FVMIN_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_I_CS_FVMIN_CURRENT");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_LAB_FREQ_MHZ,
                             &i_exchplet,l_data);
        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_LAB_FREQ_MHZ");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_V_NEST_LAB_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                      "ATTR_OVERRIDE_MVPD_V_NEST_LAB_VOLTAGE");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_I_NEST_LAB_CURRENT,
                             &i_exchplet, l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                     "ATTR_OVERRIDE_MVPD_I_NEST_LAB_CURRENT");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_V_CS_LAB_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                      "ATTR_OVERRIDE_MVPD_V_CS_LAB_VOLTAGE");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        l_rc = FAPI_ATTR_GET(ATTR_OVERRIDE_MVPD_I_CS_LAB_CURRENT,
                             &i_exchplet, l_data);

        if( l_rc )
        {
            FAPI_ERR("getVltgBucketAttr:Err in get "
                      "ATTR_OVERRIDE_MVPD_I_CS_LAB_CURRENT");
            break;
        }

        // Read value and put 2 bytes to the output buffer. FAPI ATTR cannot
        // be 2 bytes by design so had to make it 4 bytes and do shift to
        // return 2 bytes which is actual size of the data in the VPD.
        l_data = l_data << MVPD_TWO_BYTE_ATTR_VAL_SHIFT;
        memcpy(&io_pData[l_idx],&l_data,sizeof(uint16_t));
        l_idx += sizeof(uint16_t);

        //Return actual buffer size in output param
        io_dataSz = l_idx;

    }while(false);

    if(l_rc)
    {
        // On error return 0 size
        io_dataSz = 0;
    }

    return l_rc;
}

//******************************************************************************
// setVoltageBucketAttr
//******************************************************************************
fapi::ReturnCode setVoltageBucketAttr(const fapi::Target & i_exchplet,
                                      const fapi::voltageBucketData_t & i_data)
{
    fapi::ReturnCode l_rc;
    do
    {
        // local variable is used as i_data fields are 2 bytes (matching VPD
        // data length) and FAPI attributes are 4 bytes long. FAPI attributes
        // cannot be 2 bytes by design.
        uint32_t l_data = i_data.nomFreq;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_NOM_FREQ_MHZ,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_NOM_FREQ_MHZ");
            break;
        }

        l_data = i_data.VnestNomVltg;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_V_NEST_NOM_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_V_NEST_NOM_VOLTAGE");
            break;
        }

        l_data = i_data.InestNomCurr;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_I_NEST_NOM_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_I_NEST_NOM_CURRENT");
            break;
        }

        l_data = i_data.VcsNomVltg;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_V_CS_NOM_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_V_CS_NOM_VOLTAGE");
            break;
        }

        l_data = i_data.IcsNomCurr;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_I_CS_NOM_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_I_CS_NOM_CURRENT");
            break;
        }

        l_data = i_data.PSFreq;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_PS_FREQ_MHZ,&i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_PS_FREQ_MHZ");
            break;
        }

        l_data = i_data.VnestPSVltg;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_V_NEST_PS_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_V_NEST_PS_VOLTAGE");
            break;
        }

        l_data = i_data.InestPSCurr;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_I_NEST_PS_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_I_NEST_PS_CURRENT");
            break;
        }

        l_data = i_data.VcsPSVltg;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_V_CS_PS_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_V_CS_PS_VOLTAGE");
            break;
        }

        l_data = i_data.IcsPSCurr;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_I_CS_PS_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_I_CS_PS_CURRENT");
            break;
        }

        l_data = i_data.turboFreq;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_TURBO_FREQ_MHZ,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_TURBO_FREQ_MHZ");
            break;
        }

        l_data = i_data.VnestTurboVltg;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_V_NEST_TURBO_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_V_NEST_TURBO_VOLTAGE");
            break;
        }

        l_data = i_data.InestTurboCurr;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_I_NEST_TURBO_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_I_NEST_TURBO_CURRENT");
            break;
        }

        l_data = i_data.VcsTurboVltg;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_V_CS_TURBO_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_V_CS_TURBO_VOLTAGE");
            break;
        }

        l_data = i_data.IcsTurboCurr;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_I_CS_TURBO_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_I_CS_TURBO_CURRENT");
            break;
        }
        l_data = i_data.fvminFreq;

        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_FVMIN_FREQ_MHZ,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_FVMIN_FREQ_MHZ");
            break;
        }

        l_data = i_data.VnestFvminVltg;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_V_NEST_FVMIN_VOLTAGE,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_V_NEST_FVMIN_VOLTAGE");
            break;
        }

        l_data = i_data.InestFvminCurr;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_I_NEST_FVMIN_CURRENT,
                             &i_exchplet,l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_I_NEST_FVMIN_CURRENT");
            break;
        }
        l_data = i_data.VcsFvminVltg;

        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_V_CS_FVMIN_VOLTAGE,&i_exchplet,
                             l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_V_CS_FVMIN_VOLTAGE");
            break;
        }

        l_data = i_data.IcsFvminCurr;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_I_CS_FVMIN_CURRENT,&i_exchplet,
                             l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_I_CS_FVMIN_CURRENT");
            break;
        }

        l_data = i_data.labFreq;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_LAB_FREQ_MHZ,&i_exchplet,
                             l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_LAB_FREQ_MHZ");
            break;
        }
        l_data = i_data.VnestLabVltg;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_V_NEST_LAB_VOLTAGE,&i_exchplet,
                             l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                      "ATTR_OVERRIDE_MVPD_V_NEST_LAB_VOLTAGE");
            break;
        }
        l_data = i_data.InestLabCurr;
        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_I_NEST_LAB_CURRENT,&i_exchplet,
                             l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_I_NEST_LAB_CURRENT");
            break;
        }
        l_data = i_data.VcsLabVltg;

        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_V_CS_LAB_VOLTAGE,&i_exchplet,
                             l_data);

        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_V_CS_LAB_VOLTAGE");
            break;
        }
        l_data = i_data.IcsLabCurr;

        l_rc = FAPI_ATTR_SET(ATTR_OVERRIDE_MVPD_I_CS_LAB_CURRENT,&i_exchplet,
                             l_data);
        if( l_rc )
        {
            FAPI_ERR("setVltgBucketAttr:Err in set "
                     "ATTR_OVERRIDE_MVPD_I_CS_LAB_CURRENT");
            break;
        }

    }while(false);

    return l_rc;
}

/**
 * @brief Parse and get #V version one bucket data
 *
 * @par Detailed Description:
 *     This function handles parsing of version one #V data and returns
 *     bucket data buffer.
 *
 * @param[in] i_prBucketId  Bucket id to read data for
 * @param[in] i_dataSz      #V data buffer size
 * @param[in] i_vDataPtr    #V data buffer
 * @param[out] o_data       On success, structure with #V version one bucket
 *                          data from VPD
 *
 * @return fapi::ReturnCode. FAPI_RC_SUCCESS, or failure value.
 */
fapi::ReturnCode fapiGetVerOneVoltageBucketData(
                                 const TARGETING::Target * i_pChipTarget,
                                 const uint8_t i_prBucketId,
                                 const uint32_t i_dataSz,
                                 const uint8_t *i_vDataPtr,
                                 fapi::voltageBucketData_t & o_data)
{
    fapi::ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    do
    {
        memset (&o_data,0,sizeof (o_data));

        // For version 0x01, valid bucket id is 1 through 5.
        if( (i_prBucketId == 0 ) ||
            (i_prBucketId > 5) )
        {
            FAPI_ERR("Found invalid bucket ID:0x%02X", i_prBucketId);

            /*@
             * @errortype
             * @moduleid     fapi::MOD_GET_VER_ONE_VOLTAGE_BUCKET_DATA
             * @reasoncode   fapi::RC_INVALID_PARAM
             * @userdata1    Invalid bucket id
             * @devdesc      Invalid bucket id found for the voltage data.
             */
            l_err =
                new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 fapi::MOD_GET_VER_ONE_VOLTAGE_BUCKET_DATA,
                                 fapi::RC_INVALID_PARAM,
                                 i_prBucketId);

            // Callout HW as VPD data is incorrect
            l_err->addHwCallout(i_pChipTarget, HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::DECONFIG, HWAS::GARD_NULL);

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));

            break;
        }

        // Documented in Module VPD document: mvpd-p8-100212.pdf Version 1.0
        // skip (1 byte version +  3 byte PNP +
        //       ((bucketId-1(as bucketId starts at 1)) * bucket data size )
        uint32_t l_bucketOffset = 4 + ((i_prBucketId -1)* VERSION_01_BUCKET_SZ);

        if( i_dataSz < (l_bucketOffset + VERSION_01_BUCKET_SZ))
        {
            FAPI_ERR("Not enough data to get bucket data "
                     "Returned data length:[0x%08X],expected len:[0x%08X]",
                     i_dataSz, l_bucketOffset + VERSION_01_BUCKET_SZ);

            /*@
             * @errortype
             * @moduleid     fapi::MOD_GET_VER_ONE_VOLTAGE_BUCKET_DATA
             * @reasoncode   fapi::RC_INVALID_SIZE
             * @userdata1    Voltage data length
             * @userdata2    Expected length
             * @devdesc      Not enough voltage data to read bucket data.
             */
            l_err =
                new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 fapi::MOD_GET_VER_ONE_VOLTAGE_BUCKET_DATA,
                                 fapi::RC_INVALID_SIZE,
                                 i_dataSz,
                                 (l_bucketOffset + VERSION_01_BUCKET_SZ));

            // Callout HW as VPD data is incorrect
            l_err->addHwCallout(i_pChipTarget, HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::DECONFIG, HWAS::GARD_NULL);

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));

            break;
        }

        // Got bucket data, now make sure input bucket id matches with the
        // bucket id pointed to by the bucket data. Ignore default value
        // since it means VPD is not initialized.
        if( (i_prBucketId != i_vDataPtr[l_bucketOffset]) &&
            (i_prBucketId != DEFAULT_BUCKET) )
        {
            FAPI_ERR("BucketId:[0x%02x] from PR data "
                     "does not match bucketId:[0x%02X] from the voltage "
                     "data for HUID:[0x%08X]",
                     i_prBucketId, i_vDataPtr[l_bucketOffset],
                     i_pChipTarget->getAttr<TARGETING::ATTR_HUID>());

            /*@
             * @errortype
             * @moduleid         fapi::MOD_GET_VER_ONE_VOLTAGE_BUCKET_DATA
             * @reasoncode       fapi::RC_DATA_MISMATCH
             * @userdata1[0:31]  Voltage bucket id
             * @userdata1[32:63] PR bucket id
             * @userdata2        Voltage bucket id offset
             * @devdesc          Bucket id from PR keyword does not match
             *                   bucket id in the voltage data
             */
            l_err =
                new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 fapi::MOD_GET_VER_ONE_VOLTAGE_BUCKET_DATA,
                                 fapi::RC_DATA_MISMATCH,
            TWO_UINT32_TO_UINT64(i_vDataPtr[l_bucketOffset], i_prBucketId),
                                 l_bucketOffset);

            // Callout HW as VPD data is incorrect
            l_err->addHwCallout(i_pChipTarget, HWAS::SRCI_PRIORITY_HIGH,
                                HWAS::DECONFIG, HWAS::GARD_NULL);

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));

            break;
        }

        // Make sure bucket data is large enough to process output structure
        if (sizeof(o_data) < (VERSION_01_BUCKET_SZ))
        {
            FAPI_ERR("Not enough bucket data to fill o_data,"
                     "bucket length:[0x%08X],o_data size:[0x%08X]",
                     VERSION_01_BUCKET_SZ,sizeof(o_data));

            /*@
             * @errortype
             * @moduleid     fapi::MOD_GET_VER_ONE_VOLTAGE_BUCKET_DATA
             * @reasoncode   fapi::RC_INVALID_DATA
             * @userdata1    Bucket data length
             * @userdata2    Output Data size
             * @devdesc      Not enough bucket data to fill output data.
             */
            l_err =
                new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                fapi::MOD_GET_VER_ONE_VOLTAGE_BUCKET_DATA,
                                fapi::RC_INVALID_DATA,
                                VERSION_01_BUCKET_SZ,
                                (sizeof(o_data)));

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));

            break;
        }

        // TODO RTC 116552 Clean up logic to map data to a struct
        uint8_t l_idx = l_bucketOffset;
        //Bucket id
        o_data.bucketId = i_vDataPtr[l_idx];
        l_idx += sizeof(o_data.bucketId);
        //Nominal
        o_data.nomFreq = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.nomFreq);
        o_data.VnestNomVltg = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.VnestNomVltg);
        o_data.InestNomCurr = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.InestNomCurr);
        o_data.VcsNomVltg = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.VcsNomVltg);
        o_data.IcsNomCurr = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.IcsNomCurr);

        //PowerSave
        o_data.PSFreq = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.PSFreq);
        o_data.VnestPSVltg = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.VnestPSVltg);
        o_data.InestPSCurr = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.InestPSCurr);
        o_data.VcsPSVltg = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.VcsPSVltg);
        o_data.IcsPSCurr = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.IcsPSCurr);
        //Turbo
        o_data.turboFreq = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.turboFreq);
        o_data.VnestTurboVltg = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.VnestTurboVltg);
        o_data.InestTurboCurr = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.InestTurboCurr);
        o_data.VcsTurboVltg = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.VcsTurboVltg);
        o_data.IcsTurboCurr = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.IcsTurboCurr);

        // Fvmin
        o_data.fvminFreq = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.fvminFreq);
        o_data.VnestFvminVltg = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.VnestFvminVltg);
        o_data.InestFvminCurr = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.InestFvminCurr);
        o_data.VcsFvminVltg = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.VcsFvminVltg);
        o_data.IcsFvminCurr = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.IcsFvminCurr);

        //Lab
        o_data.labFreq = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.labFreq);
        o_data.VnestLabVltg = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.VnestLabVltg);
        o_data.InestLabCurr = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.InestLabCurr);
        o_data.VcsLabVltg = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.VcsLabVltg);
        o_data.IcsLabCurr = *(reinterpret_cast<uint16_t*>(
                                const_cast<uint8_t*>(&i_vDataPtr[l_idx])));
        l_idx += sizeof(o_data.IcsLabCurr);

    } while(0);

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
    uint8_t l_chipUnitNum = MVPD_INVALID_CHIP_UNIT;
    errlHndl_t l_errl = NULL;
    fapi::ReturnCode l_rc;
    FAPI_DBG("fapiGetMvpdField entry");

    do
    {
        // Translate the FAPI record to a Hostboot record
        MVPD::mvpdRecord l_hbRecord = MVPD::MVPD_INVALID_RECORD;

        l_rc = fapi::MvpdRecordXlate(i_record, l_hbRecord, l_chipUnitNum);

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

        // For #V keyword need to read the bucket id from the processor VPD
        // and then read #V data to get the voltage bucket data. Use exsiting
        // freq voltage service call to get the voltage bucket data
        if(i_keyword == fapi::MVPD_KEYWORD_PDV)
        {
            fapi::voltageBucketData_t l_pVData;

            // Get #V bucket data
            l_rc = fapiGetPoundVBucketData(i_procTarget,
                                  (uint32_t) l_hbRecord,
                                             l_pVData);
            if (l_rc)
            {
                TARGETING::Target * l_pChipTarget =
                   reinterpret_cast<TARGETING::Target*>(i_procTarget.get());

                FAPI_ERR("fapiGetMvpdField: Error getting #V bucket data "
                         "HUID: 0x%08X",
                         l_pChipTarget->getAttr<TARGETING::ATTR_HUID>());

                break;
            }

            // Get EX - CHPLET list and find the correct chiplet to read
            // write attributes
            std::vector<fapi::Target> l_exchiplets;
            fapi::TargetState l_state = fapi::TARGET_STATE_PRESENT;

            l_rc = fapiGetChildChiplets(
                                      i_procTarget,fapi::TARGET_TYPE_EX_CHIPLET,
                                      l_exchiplets,l_state);

            if( l_rc)
            {
                FAPI_ERR("fapiGetMvpdField:Error getting exchiplet list");
                break;
            }

            std::vector<fapi::Target>::iterator l_itr;
            // Traverse through ex-chiplet and compare chip unit pos to find
            // right ex chiplet
            for(l_itr = l_exchiplets.begin();l_itr!=l_exchiplets.end();l_itr++)
            {
                uint8_t l_chipUnit = MVPD_INVALID_CHIP_UNIT;
                // get chip unit
                l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS,&(*(l_itr)),l_chipUnit);

                if( l_rc)
                {
                    FAPI_ERR("fapiGetMvpdField:Err getting CHIP_UNIT_POS Attr");
                    break;
                }

                //Find correct chiplet
                // If ex-chiplet chip unit pos does not match the one input
                // record corresponds to then go to the next ex-chiplet
                if( l_chipUnit != l_chipUnitNum)
                {
                    continue;
                }
                // Matching ex-chiplet found. Write MVPD voltage bucket
                // attributes associated to it.
                l_rc = setVoltageBucketAttr(*l_itr,l_pVData);

                if( l_rc)
                {
                    FAPI_ERR("fapiGetMvpdField:Error setting voltage bucket "
                             "attribute");
                    break;
                }

                // Read it back to get override value (if any)
                l_rc = getVoltageBucketAttr(*l_itr,l_pVData,i_pBuffer,
                                            io_fieldSize);

                if( l_rc)
                {
                    FAPI_ERR("fapiGetMvpdField:Error reading voltage bucket "
                             "attribute");
                    break;
                }
                // found correct core so we are done
                break;
            } //end for loop

            if( l_rc)
            {
                break;
            }

        }
        else // non-#V Module VPD data
        {
            // Similarly to this function, deviceRead will return the size of
            // the field if the pointer is NULL
            size_t l_fieldLen = io_fieldSize;

            l_errl = deviceRead(
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

            // Success, update callers io_fieldSize for the case where the
            // pointer is NULL and deviceRead returned the actual size
            io_fieldSize = l_fieldLen;

        }

        FAPI_DBG("fapiGetMvpdField: returning field len=0x%x", io_fieldSize);

    } while(0);

    if( l_rc)
    {
        io_fieldSize = 0;
    }

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
    uint8_t l_chipUnitNum = MVPD_INVALID_CHIP_UNIT;
    FAPI_DBG("fapiSetMvpdField entry");

    do
    {
        // Translate the FAPI record to a Hostboot record
        MVPD::mvpdRecord l_hbRecord = MVPD::MVPD_INVALID_RECORD;

        l_rc = fapi::MvpdRecordXlate(i_record, l_hbRecord, l_chipUnitNum);

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

fapi::ReturnCode fapiGetPoundVBucketData(
                                      const fapi::Target &i_procTarget,
                                      const uint32_t i_record,
                                      fapi::voltageBucketData_t & o_data)
{
    fapi::ReturnCode l_rc;
    size_t     l_vpdSize = 0;
    uint8_t   *l_prDataPtr = NULL;
    uint8_t   *l_vDataPtr = NULL;
    errlHndl_t l_err = NULL;

    do
    {
        TARGETING::Target * l_pChipTarget =
                   reinterpret_cast<TARGETING::Target*>(i_procTarget.get());

        // Read PR keyword size
        l_err = deviceRead( l_pChipTarget,
                            NULL,
                            l_vpdSize,
                            DEVICE_MVPD_ADDRESS( MVPD::VINI,
                                                 MVPD::PR ) );
        if (l_err)
        {
            FAPI_ERR("Error getting PR keyword size for HUID: "
                     "0x%08X, errorlog PLID=0x%x",
                      l_pChipTarget->getAttr<TARGETING::ATTR_HUID>(),
                      l_err->plid());

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));

            break;
        }

        // Assert if deviceRead returned success but size is 0
        assert(l_vpdSize != 0);

        l_prDataPtr = new uint8_t [l_vpdSize];

        // Read PR keyword data
        l_err = deviceRead(l_pChipTarget,
                            l_prDataPtr,
                            l_vpdSize,
                            DEVICE_MVPD_ADDRESS( MVPD::VINI,
                                             MVPD::PR ) );
        if (l_err)
        {
            FAPI_ERR("Error getting PR keyword data for HUID: "
                     "0x%08X, errorlog PLID=0x%x",
                      l_pChipTarget->getAttr<TARGETING::ATTR_HUID>(),
                      l_err->plid());

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));

            break;
        }

        // Get non-ECO mode bucket id - bits 4-7
        uint8_t l_bucketId =
                 (l_prDataPtr[NON_ECO_VOLTAGE_BUCKET_OFFFSET] & BUCKET_ID_MASK);
        if( l_bucketId == 0)
        {
            FAPI_INF("bucketId is zero, using alternate offset");
            l_bucketId = l_prDataPtr[ALTERNATE_BUCKET_OFFSET];
        }
        if( l_bucketId == 0) // VPD is not initialized / programmed correctly
        {
            FAPI_INF("bucketId is zero, invalid VPD, using default value 0x%x",
                      DEFAULT_BUCKET);
            l_bucketId = DEFAULT_BUCKET;
        }

        l_vpdSize = 0;
        l_err = deviceRead( l_pChipTarget,
                            NULL,
                            l_vpdSize,
                            DEVICE_MVPD_ADDRESS( i_record,
                                                 MVPD::pdV ) );
        if (l_err)
        {
            FAPI_ERR("Error getting #V keyword size for HUID: "
                     "0x%08X, errorlog PLID=0x%x",
                      l_pChipTarget->getAttr<TARGETING::ATTR_HUID>(),
                      l_err->plid());

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));

            break;
        }

        // Assert if deviceRead returned success but size is 0
        assert(l_vpdSize != 0);

        l_vDataPtr = new uint8_t [l_vpdSize];

        l_err = deviceRead( l_pChipTarget,
                            l_vDataPtr,
                            l_vpdSize,
                            DEVICE_MVPD_ADDRESS( i_record,
                                             MVPD::pdV ) );
        if (l_err)
        {
            FAPI_ERR("Error getting #V keyword data for HUID: "
                     "0x%08X, errorlog PLID=0x%x",
                      l_pChipTarget->getAttr<TARGETING::ATTR_HUID>(),
                      l_err->plid());

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));

            break;
        }

        uint8_t l_version = 0x0;

        l_version = l_vDataPtr[0];

        if( l_version != POUND_V_VERSION_01)
        {
            FAPI_ERR("Found unsupported version:[0x%02X] of "
                     "the #V data", l_version);

            /*@
             * @errortype
             * @moduleid         fapi::MOD_GET_POUNDV_BUCKET_DATA
             * @reasoncode       fapi::RC_DATA_NOT_SUPPORTED
             * @userdata1[0:31]  Unsupported version
             * @userdata1[32:63] Expected version
             * @userdata2        #V KW data size
             * @devdesc          Unsupported #V keyword data version found.
             */
            l_err =
                new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 fapi::MOD_GET_POUNDV_BUCKET_DATA,
                                 fapi::RC_DATA_NOT_SUPPORTED,
            TWO_UINT32_TO_UINT64(l_version, POUND_V_VERSION_01),
                                 l_vpdSize);

            // Callout HW as VPD data is incorrect
            l_err->addHwCallout(l_pChipTarget, HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::DECONFIG, HWAS::GARD_NULL);

            // Code (SW) callout in case this is downlevel VPD version
            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_MED);

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));

            break;
        }

        // Parse #V Version one data to get bucket data
        l_rc = fapiGetVerOneVoltageBucketData(l_pChipTarget,
                                      l_bucketId,
                                      l_vpdSize,
                                      l_vDataPtr,
                                      o_data);
        if (l_rc)
        {
            FAPI_ERR("Error getting voltage bucket data for version 0x%x, "
                     "PR KW bucketId:[0x%02X], errorlog PLID=0x%x",
                     POUND_V_VERSION_01, l_bucketId, l_err->plid());

            break;
        }

    } while(0);

    if (l_prDataPtr != NULL)
    {
        delete [] l_prDataPtr;
    }
    if (l_vDataPtr != NULL)
    {
        delete [] l_vDataPtr;
    }

    return  l_rc;
}

} // extern "C"
