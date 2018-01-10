/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/accessors/p9_get_mem_vpd_keyword.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

///
/// @file p9_get_mem_vpd_keyword.C
/// @brief Return mem vpd keyword based on VDPInfo
///
// *HWP HWP Owner: Dan Crowell <dcrowell@us.ibm.com>
// *HWP HWP Backup: Matt Light <mklight@us.ibm.com>
// *HWP FW Owner: Dan Crowell <dcrowell@us.ibm.com>
// *HWP Team:
// *HWP Level: 3
// *HWP Consumed by: Cronus, FSP, HB

#include <stdint.h>
#include <fapi2.H>
#include <p9_get_mem_vpd_keyword.H>

using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

//remove the following comments for unit testing
//#undef FAPI_DBG
//#define FAPI_DBG(args...) FAPI_INF(args)

/// Local declartions

/// Structure for the layout of the MR and MT mapping keyword
enum mappingKeywordEnum
{
    MAPPING_LAYOUT_VERSION  = 1,
    MAPPING_LAYOUT_INVALID  = 0xff,
    MAPPING_LAYOUT_LAST     = 0x00,
    MAPPING_LAYOUT_MAXROWS  = 36,  //0..9,A..Z

    MAPPING_LAYOUT_MCS_0        = 0x8000, //mcs position 0
    MAPPING_LAYOUT_MCS_15       = 0x0001, //mcs position 15

    MAPPING_LAYOUT_RANKPAIR_00  = 0x8000, //Rank pair 0x00
    MAPPING_LAYOUT_RANKPAIR_01  = 0x4000, //Rank pair 0x01
    MAPPING_LAYOUT_RANKPAIR_02  = 0x2000, //Rank pair 0x02
    MAPPING_LAYOUT_RANKPAIR_04  = 0x1000, //Rank pair 0x04
    MAPPING_LAYOUT_RANKPAIR_10  = 0x0800, //Rank pair 0x10
    MAPPING_LAYOUT_RANKPAIR_11  = 0x0400, //Rank pair 0x11
    MAPPING_LAYOUT_RANKPAIR_12  = 0x0200, //Rank pair 0x12
    MAPPING_LAYOUT_RANKPAIR_14  = 0x0100, //Rank pair 0x14
    MAPPING_LAYOUT_RANKPAIR_20  = 0x0080, //Rank pair 0x20
    MAPPING_LAYOUT_RANKPAIR_21  = 0x0040, //Rank pair 0x21
    MAPPING_LAYOUT_RANKPAIR_22  = 0x0020, //Rank pair 0x22
    MAPPING_LAYOUT_RANKPAIR_24  = 0x0010, //Rank pair 0x24
    MAPPING_LAYOUT_RANKPAIR_40  = 0x0008, //Rank pair 0x40
    MAPPING_LAYOUT_RANKPAIR_41  = 0x0004, //Rank pair 0x41
    MAPPING_LAYOUT_RANKPAIR_42  = 0x0002, //Rank pair 0x42
    MAPPING_LAYOUT_RANKPAIR_44  = 0x0001, //Rank pair 0x44

    MAPPING_LAYOUT_FREQ_0       = 0x80,   //Frequency index 0 - 1866
    MAPPING_LAYOUT_FREQ_1       = 0x40,   //Frequency index 1 - 2133
    MAPPING_LAYOUT_FREQ_2       = 0x20,   //Frequency index 2 - 2400
    MAPPING_LAYOUT_FREQ_3       = 0x10,   //Frequency index 3 - 2666
};

struct mappingHeader_t //header is first in mapping keyword
{
    uint8_t layoutVersion;  // decode version
    uint8_t numEntries;     // number of criteria mapping entries
    uint8_t reserved;       // reserved
} __attribute__((packed));

// header for Q0 and CK keywords
struct mappingHeader2_t //header is first in mapping keyword
{
    uint8_t layoutVersion;  // decode version
    uint8_t numEntries;     // number of criteria mapping entries (DQ = # of map entries)
    uint8_t blobSize;       // # bytes in each data entry
    uint8_t reserved;
} __attribute__((packed));

struct mappingKeywordRow_t //criteria mapping entries follow header
{
    uint8_t mcsMaskMSB;  // mcs mask high order byte
    uint8_t mcsMaskLSB;  // mcs mask low order byte
    uint8_t rankMaskMSB; // rank mask high order byte
    uint8_t rankMaskLSB; // rank mask low order byte
    uint8_t freqMask;    // low nibble reserved
    char    keywordChar; // 0..9,A..Z
} __attribute__((packed));

struct mappingDqRow_t // DQ map entries following header
{
    fapi2::ATTR_MEMVPD_POS_Type qPosition;
    uint8_t qNum;
} __attribute__((packed));

const size_t DQ_MAP_SIZE    = 36;
const size_t DQ_BLOB_SIZE   = 160;

// VPD format only supports up to 16 unique MCS entries
constexpr fapi2::ATTR_MEMVPD_POS_Type MAX_MEMVPD_POS = 16;


extern "C"
{

/// @brief Return VPD keyword based on MCS, VPDInfo, and MR/MT mapping
/// The MR and MT keyword contains a header followed by a table.
/// Each row in the table has criteria to select a vpd keyword.
/// DQ keyword uses Q0 as a map to Q1-Q8 keywords.  Q0 and CK have a header.
///
/// @param[in]  i_target, the MCS
/// @param[in]  i_vpd_info, vpd criteria
/// @param[in]  i_pMapping, MR, MT, Q0, or CK keyword data
/// @param[in]  i_mappingSize, size of i_pMapping buffer
/// @param[out] o_keywordInfo, keyword with its vpd information
/// @return FAPI2_RC_SUCCESS iff ok
    fapi2::ReturnCode p9_get_mem_vpd_keyword(
        const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS>& i_vpd_info,
        const uint8_t*         i_pMapping,
        const size_t           i_mappingSize,
        fapi2::keywordInfo_t& o_keywordInfo)
    {
        char l_first  = 0;  //first character of return keyword name
        char l_second = MAPPING_LAYOUT_INVALID;  //second character of return keyword name
        fapi2::ATTR_MEMVPD_POS_Type l_mcsPos = 0;
        uint16_t l_mcsMask   = 0;
        uint16_t l_rankMask  = 0;
        uint8_t  l_rankShift = 0;
        uint8_t  l_freqMask  = 0;
        uint32_t l_freqTableIndex = 0;
        constexpr uint32_t l_freqTable[] = {1866, 2133, 2400, 2666};
        uint32_t l_freqTableCnt = sizeof(l_freqTable) / sizeof(l_freqTable[0]);
        uint32_t l_index = 0; //start with first criteria row
        uint32_t l_indexMax = MAPPING_LAYOUT_MAXROWS;
        o_keywordInfo.kwBlobIndex = 0; // default blob is entire keyword data
        o_keywordInfo.kwBlobSize = i_mappingSize;

        const mappingHeader_t* l_mappingHeader = //pointer to header
            reinterpret_cast<const mappingHeader_t*>(i_pMapping);
        const mappingHeader2_t* l_mappingHeader2 = //pointer to header2 (used for DQ and CK)
            reinterpret_cast<const mappingHeader2_t*>(i_pMapping);

        const mappingKeywordRow_t* l_mapping =   //pointer to first criteria row
            reinterpret_cast<const mappingKeywordRow_t*>(i_pMapping +
                    sizeof(mappingHeader_t));

        FAPI_DBG("p9_get_mem_vpd_keyword: enter");

        size_t l_mapping_layout_maxsize;
        uint8_t l_mapping_layout_version;

        // Fill in a data buffer for FFDC purposes
        uint64_t l_ffdc_MAPROW[MAPPING_LAYOUT_MAXROWS];
        memset( l_ffdc_MAPROW, 0, sizeof(l_ffdc_MAPROW) );

        // Validate vpd type and set first keyword name character based on type
        switch (i_vpd_info.iv_vpd_type)
        {
            case fapi2::MT:
                l_first = 'X';  //MT vpd keyword name X0..X9,XA..XZ
                l_mapping_layout_version = MAPPING_LAYOUT_VERSION;
                l_mapping_layout_maxsize = sizeof(mappingHeader_t) +
                                           size_t(sizeof(mappingKeywordRow_t) * MAPPING_LAYOUT_MAXROWS);
                break;

            case fapi2::MR:
                l_first = 'J';  //MR vpd keyword name J0..J9,JA..JZ
                l_mapping_layout_version = MAPPING_LAYOUT_VERSION;
                l_mapping_layout_maxsize = sizeof(mappingHeader_t) +
                                           size_t(sizeof(mappingKeywordRow_t) * MAPPING_LAYOUT_MAXROWS);
                break;

            case fapi2::DQ:
                l_first = 'Q';  //DQ vpd keyword name Q1...Q8
                l_mapping_layout_version = MAPPING_LAYOUT_VERSION;
                l_mapping_layout_maxsize = DQ_MAP_SIZE;
                break;

            case fapi2::CK:
                l_first = 'C';  //CKE vpd keyword name CK
                l_mapping_layout_version = MAPPING_LAYOUT_VERSION;
                l_mapping_layout_maxsize = sizeof(mappingHeader2_t) +
                                           (l_mappingHeader2->numEntries * l_mappingHeader2->blobSize);
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::GET_MEM_VPD_UNSUPPORTED_TYPE().
                            set_MCS_TARGET(i_target).
                            set_VPDTYPE(i_vpd_info.iv_vpd_type),
                            "Invalid vpd type = %d",
                            i_vpd_info.iv_vpd_type);
                break;
        }

        // Validate size of mapping to be at least large enough for biggest
        // mapping table expected.
        FAPI_ASSERT(l_mapping_layout_maxsize <= i_mappingSize,
                    fapi2::GET_MEM_VPD_MAPPING_TOO_SMALL().
                    set_SIZE(size_t(i_mappingSize)).
                    set_EXPECTED(l_mapping_layout_maxsize).
                    set_VPDTYPE(i_vpd_info.iv_vpd_type).
                    set_MCS_TARGET(i_target),
                    "Mapping keyword size %d less than min %d expected",
                    i_mappingSize,
                    l_mapping_layout_maxsize);

        // Validate mapping keyword version supported
        FAPI_ASSERT(l_mapping_layout_version == l_mappingHeader->layoutVersion,
                    fapi2::GET_MEM_VPD_UNSUPPORTED_VERSION().
                    set_VERSION(uint8_t(l_mappingHeader->layoutVersion)).
                    set_EXPECTED(uint8_t(l_mapping_layout_version)).
                    set_VPDTYPE(i_vpd_info.iv_vpd_type).
                    set_MCS_TARGET(i_target),
                    "Header version %d not supported % expected",
                    l_mappingHeader->layoutVersion,
                    l_mapping_layout_version);

        // Get the MCS position and calculate mask
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEMVPD_POS,
                               i_target,
                               l_mcsPos),
                 "p9_get_mem_vpd_keyword: get ATTR_MEMVPD_POS failed");
        // verify we have a valid MEMVPD_POS
        FAPI_ASSERT(l_mcsPos < MAX_MEMVPD_POS,
                    fapi2::GET_MEM_VPD_POS_OUT_OF_RANGE().
                    set_MCS_POS(l_mcsPos).
                    set_MAX_MEMVPD_POS(MAX_MEMVPD_POS).
                    set_MCS_TARGET(i_target).
                    set_VPDTYPE(i_vpd_info.iv_vpd_type),
                    "ATTR_MEMVPD_POS out of range (=%d)",
                    l_mcsPos);
        l_mcsMask = (MAPPING_LAYOUT_MCS_0 >> l_mcsPos); //zero based
        FAPI_DBG ("p9_get_mem_vpd_keyword: mca position = %d mask=0x%04x",
                  l_mcsPos, l_mcsMask);

        if (i_vpd_info.iv_vpd_type == fapi2::CK)
        {
            // verify data index will be valid
            FAPI_ASSERT(l_mcsPos < l_mappingHeader2->numEntries,
                        fapi2::GET_MEM_VPD_ENTRY_NOT_FOUND().
                        set_ENTRY(l_mcsPos).
                        set_MAX_ENTRIES(uint8_t(l_mappingHeader2->numEntries)).
                        set_VERSION(uint8_t(l_mappingHeader2->layoutVersion)).
                        set_VPDTYPE(i_vpd_info.iv_vpd_type).
                        set_MCS_TARGET(i_target),
                        "Unsupported entry (%d), max entries (%d)",
                        l_mcsPos,
                        uint8_t(l_mappingHeader2->numEntries));

            o_keywordInfo.kwBlobSize = l_mappingHeader2->blobSize;

            // Setup index to CK section data (ordered by memvpd pos)
            o_keywordInfo.kwBlobIndex = (l_mcsPos * o_keywordInfo.kwBlobSize) +
                                        sizeof(mappingHeader2_t);

            l_second = 'K';
        }
        else if (i_vpd_info.iv_vpd_type == fapi2::DQ)
        {
            // Find which Q# i_target is in
            const mappingDqRow_t* l_dqmapping =   //pointer to first criteria row
                reinterpret_cast<const mappingDqRow_t*>(i_pMapping +
                        sizeof(mappingHeader2_t));

            for (uint8_t i = 0; i < l_mappingHeader->numEntries; i++)
            {
                // Copy data into FFDC buffer
                memcpy( &(l_ffdc_MAPROW[i]),
                        &(l_dqmapping[i]),
                        sizeof(l_dqmapping[i]) );

                if (l_dqmapping[i].qPosition == l_mcsPos)
                {
                    l_second = l_dqmapping[i].qNum;
                    o_keywordInfo.kwBlobSize = DQ_BLOB_SIZE;
                    break;
                }
            }

            FAPI_DBG ("p9_get_mem_vpd_keyword: mcsPos %d -> Q%c keyword data",
                      l_mcsPos, l_second);
        }
        else
        {
            // Get the frequency index and calculate mask
            for (; l_freqTableIndex < l_freqTableCnt; l_freqTableIndex++)
            {
                if (i_vpd_info.iv_freq_mhz == l_freqTable[l_freqTableIndex])
                {
                    break; // found it
                }
            }

            FAPI_ASSERT(l_freqTableIndex < l_freqTableCnt,
                        fapi2::GET_MEM_VPD_UNSUPPORTED_FREQUENCY().
                        set_UNSUPPORTEDFREQ(uint32_t(i_vpd_info.iv_freq_mhz)).
                        set_MEMVPDFREQ0(uint32_t(l_freqTable[0])).
                        set_MEMVPDFREQ1(uint32_t(l_freqTable[1])).
                        set_MEMVPDFREQ2(uint32_t(l_freqTable[2])).
                        set_MEMVPDFREQ3(uint32_t(l_freqTable[3])).
                        set_MCS_TARGET(i_target).
                        set_VPDTYPE(i_vpd_info.iv_vpd_type),
                        "Frequency %d not supported by Nimbus",
                        i_vpd_info.iv_freq_mhz);
            l_freqMask = (MAPPING_LAYOUT_FREQ_0 >> l_freqTableIndex); //zero based
            FAPI_DBG ("p9_get_mem_vpd_keyword: frequency index = %d mask=0x%02x",
                      l_freqTableIndex, l_freqMask);

            // Calculate rank count mask. Valid rank counts are 0,1,2 or 4.
            // The mask has a bit for each of the 16 rank pairs of
            // dimm0 rank count by dimm1 count rank.
            // This notation is used by genMemVpd.pl to specify pairs.
            // Order= 0x00, 0x01, 0x02, 0x04, 0x11, 0x12, ... 0x42, 0x44
            switch (i_vpd_info.iv_rank_count_dimm_0)
            {
                case 0: //index into pair order by multiplying by 4
                case 1:
                case 2:
                    l_rankShift =  i_vpd_info.iv_rank_count_dimm_0 * 4;
                    break;

                case 4: // need to use value 3 for rank count 4
                    l_rankShift = 3 * 4;
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::GET_MEM_VPD_UNSUPPORTED_RANK().
                                set_RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_0)).
                                set_MCS_TARGET(i_target).
                                set_VPDTYPE(i_vpd_info.iv_vpd_type),
                                "Unsupported rank = %d should be 0,1,2, or 4",
                                i_vpd_info.iv_rank_count_dimm_0);
            }

            switch (i_vpd_info.iv_rank_count_dimm_1)
            {
                case 0: //add in dimm 1 rank count index
                case 1:
                case 2:
                    l_rankShift +=  i_vpd_info.iv_rank_count_dimm_1;
                    break;

                case 4: // need to use value 3 for rank count 4
                    l_rankShift += 3;
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::GET_MEM_VPD_UNSUPPORTED_RANK().
                                set_RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_1)).
                                set_MCS_TARGET(i_target).
                                set_VPDTYPE(i_vpd_info.iv_vpd_type),
                                "Unsupported rank = %d should be 0,1,2, or 4",
                                i_vpd_info.iv_rank_count_dimm_1);
            }

            l_rankMask = (MAPPING_LAYOUT_RANKPAIR_00 >> l_rankShift);
            FAPI_DBG("p9_get_mem_vpd_keyword: rank0=%d rank1=%d mask=0x%04x",
                     i_vpd_info.iv_rank_count_dimm_0,
                     i_vpd_info.iv_rank_count_dimm_1,
                     l_rankMask);

            // Use mapping data to find the second vpd keyword character.
            // Select the row where the MCS, Frequency, and rank count pair
            // bit are on in the criteria row in the mapping keyword.
            if (MAPPING_LAYOUT_MAXROWS > l_mappingHeader->numEntries)
            {
                l_indexMax = l_mappingHeader->numEntries;
            }

            // Loop through all of the rows until we find a match
            for (l_index = 0; l_index < l_indexMax; l_index++)
            {
                if (MAPPING_LAYOUT_LAST == l_mapping[l_index].keywordChar)
                {
                    break; //Hit end of table (not expected, but being careful.
                    //The keyword is zero padded by genMemVpd.pl
                }

                // Copy data into FFDC buffer
                memcpy( &(l_ffdc_MAPROW[l_index]),
                        &(l_mapping[l_index]),
                        sizeof(l_mapping[l_index]) );

                // Look for a match
                if ( (l_mcsMask  &
                      (((l_mapping[l_index].mcsMaskMSB) << 8) | //endian sensitive
                       l_mapping[l_index].mcsMaskLSB))  &&
                     (l_rankMask &
                      (((l_mapping[l_index].rankMaskMSB) << 8) | //endian sensitive
                       l_mapping[l_index].rankMaskLSB)) &&
                     (l_freqMask & l_mapping[l_index].freqMask) )
                {
                    // This row covers mca, ranks, and freq
                    l_second = l_mapping[l_index].keywordChar;
                    break;
                }
            }
        }

        // Was a matching row found?
        // Was a valid keyword name found?
        if( (0 == l_second) || ((static_cast<char>(MAPPING_LAYOUT_INVALID) == l_second)) )
        {
            // If we are in this conditional then we have encountered a fail and must decide
            // how to proceed further.  If iv_is_config_ffdc_enabled is true we will collect
            // FFDC and assert out here.
            FAPI_ASSERT( !i_vpd_info.iv_is_config_ffdc_enabled,
                         fapi2::GET_MEM_VPD_UNSUPPORTED_CONFIG().
                         set_MCS(fapi2::ATTR_MEMVPD_POS_Type(l_mcsPos)).
                         set_FREQ(uint32_t(i_vpd_info.iv_freq_mhz)).
                         set_DIMM0RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_0)).
                         set_DIMM1RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_1)).
                         set_HEADER(mappingHeader_t(*l_mappingHeader)).
                         set_MCS_TARGET(i_target).
                         set_VPDTYPE(i_vpd_info.iv_vpd_type).
                         set_MAPROW0(l_ffdc_MAPROW[0]).
                         set_MAPROW1(l_ffdc_MAPROW[1]).
                         set_MAPROW2(l_ffdc_MAPROW[2]).
                         set_MAPROW3(l_ffdc_MAPROW[3]).
                         set_MAPROW4(l_ffdc_MAPROW[4]).
                         set_MAPROW5(l_ffdc_MAPROW[5]).
                         set_MAPROW6(l_ffdc_MAPROW[6]).
                         set_MAPROW7(l_ffdc_MAPROW[7]).
                         set_MAPROW8(l_ffdc_MAPROW[8]).
                         set_MAPROW9(l_ffdc_MAPROW[9]),
                         "Unsupported configuration, no match in memory vpd mapping table");

            // If iv_is_config_ffdc_enabled is false we will arrive here and exit with a bad ReturnCode
            // but won't collect FFDC so we don't pollute users with false fails.
            FAPI_INF("Unsupported configuration, no match in memory vpd mapping table");
            return fapi2::FAPI2_RC_FALSE;
        }

        // build the keyword name
        o_keywordInfo.kwName[0] = l_first;
        o_keywordInfo.kwName[1] = l_second;
        o_keywordInfo.kwName[2] = 0;
        FAPI_DBG("p9_get_mem_vpd_keyword: keyword name = %s",
                 o_keywordInfo.kwName);
    fapi_try_exit:

        FAPI_DBG("p9_get_mem_vpd_keyword: exit");
        return fapi2::current_err;
    }

} //extern C
