/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/accessors/p9_get_mem_vpd_keyword.C $ */
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
    MAPPING_LAYOUT_RANKPAIR_44  = 0x0001, //Rank pair 0x44
    MAPPING_LAYOUT_FREQ_0       = 0x80,   //Frequency index 0
    MAPPING_LAYOUT_FREQ_3       = 0x10,   //Frequency index 3
};

struct mappingHeader_t //header is first in mapping keyword
{
    uint8_t layoutVersion;  // decode version
    uint8_t numEntries;     // number of criteria mapping entries
    uint8_t reserved;       // reserved
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

extern "C"
{

/// @brief Return VPD keyword based on MCS, VPDInfo, and MR/MT mapping
/// The MR and MT keyword contains a header followed by a table. Each
/// row in the table has criteria to select a vpd keyword.
///
/// @param[in]  i_target, the MCS
/// @param[in]  i_vpd_info, vpd criteria
/// @param[in]  i_pMapping, MR or MT keyword data
/// @param[in]  i_mappingSize, size of i_pMapping buffer
/// @param[out] o_keywordName, keyword with vpd
/// @return FAPI2_RC_SUCCESS iff ok
    fapi2::ReturnCode p9_get_mem_vpd_keyword(
        const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS>& i_vpd_info,
        const uint8_t*         i_pMapping,
        const size_t           i_mappingSize,
        fapi2::keywordName_t& o_keywordName)
    {
        char l_first  = 0;  //first character of return keyword name
        char l_second = 0;  //second character of return keyword name
        fapi2::ATTR_MEMVPD_POS_Type l_mcsPos = 0;
        uint16_t l_mcsMask   = 0;
        uint16_t l_rankMask  = 0;
        uint8_t  l_rankShift = 0;
        uint8_t  l_freqMask  = 0;
        uint32_t l_freqTableIndex = 0;
        fapi2::ATTR_MEMVPD_FREQS_MHZ_Type l_freqTable = {0};
        uint32_t l_freqTableCnt = sizeof(l_freqTable) / sizeof(l_freqTable[0]);
        uint32_t l_index = 0; //start with first criteria row
        uint32_t l_indexMax = MAPPING_LAYOUT_MAXROWS;
        const mappingHeader_t* l_mappingHeader = //pointer to header
            reinterpret_cast<const mappingHeader_t*>(i_pMapping);
        const mappingKeywordRow_t* l_mapping =   //pointer to first criteria row
            reinterpret_cast<const mappingKeywordRow_t*>(i_pMapping +
                    sizeof(mappingHeader_t));

        FAPI_DBG("p9_get_mem_vpd_keyword: enter");

        // Validate size of mapping to be at least large enough for biggest
        // mapping table expected.
        const size_t MAPPING_LAYOUT_MAXSIZE =
            size_t(sizeof(mappingKeywordRow_t) * MAPPING_LAYOUT_MAXROWS) +
            sizeof(mappingHeader_t);
        FAPI_ASSERT(MAPPING_LAYOUT_MAXSIZE <= i_mappingSize,
                    fapi2::GET_MEM_VPD_MAPPING_TOO_SMALL().
                    set_SIZE(size_t(i_mappingSize)).
                    set_EXPECTED(size_t(MAPPING_LAYOUT_MAXSIZE)).
                    set_TARGET(i_target).
                    set_VPDTYPE(i_vpd_info.iv_vpd_type),
                    "Mapping keyword size %d less than min %d expected",
                    i_mappingSize,
                    MAPPING_LAYOUT_MAXSIZE);

        // Validate mapping keyword version supported
        FAPI_ASSERT(MAPPING_LAYOUT_VERSION == l_mappingHeader->layoutVersion,
                    fapi2::GET_MEM_VPD_UNSUPPORTED_VERSION().
                    set_VERSION(uint8_t(l_mappingHeader->layoutVersion)).
                    set_EXPECTED(uint8_t(MAPPING_LAYOUT_VERSION)).
                    set_TARGET(i_target).
                    set_VPDTYPE(i_vpd_info.iv_vpd_type),
                    "Header version %d not supported % expected",
                    l_mappingHeader->layoutVersion,
                    MAPPING_LAYOUT_VERSION);

        // Validate vpd type and set first keyword name character based on type
        switch (i_vpd_info.iv_vpd_type)
        {
            case fapi2::MT:
                l_first = 'X';  //MT vpd keyword name X0..X9,XA..XZ
                break;

            case fapi2::MR:
                l_first = 'J';  //MR vpd keyword name J0..J9,JA..JZ
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::GET_MEM_VPD_UNSUPPORTED_TYPE().
                            set_TARGET(i_target).
                            set_VPDTYPE(i_vpd_info.iv_vpd_type),
                            "Invalid vpd type = %d",
                            i_vpd_info.iv_vpd_type);
        }

        // Get the MCS position and calculate mask
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEMVPD_POS,
                               i_target,
                               l_mcsPos),
                 "p9_get_mem_vpd_keyword: get ATTR_MEMVPD_POS failed");
        l_mcsMask = (MAPPING_LAYOUT_MCS_0 >> l_mcsPos); //zero based
        FAPI_DBG ("p9_get_mem_vpd_keyword: mca position = %d mask=0x%04x",
                  l_mcsPos, l_mcsMask);

        // Get the frequency index and calculate mask
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEMVPD_FREQS_MHZ,
                               fapi2::Target<TARGET_TYPE_SYSTEM>(),
                               l_freqTable),
                 "p9_get_mem_vpd_keyword: get ATTR_MEMVPD_FREQS_MHZ failed");

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
                    set_TARGET(i_target).
                    set_VPDTYPE(i_vpd_info.iv_vpd_type),
                    "Frequency %d not in ATTR_MEMVPD_FREQS_MHZ",
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
                            set_TARGET(i_target).
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
                            set_TARGET(i_target).
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

        for (l_index = 0; l_index < l_indexMax; l_index++)
        {
            if (MAPPING_LAYOUT_LAST == l_mapping[l_index].keywordChar)
            {
                break; //Hit end of table (not expected, but being careful.
                //The keyword is zero padded by genMemVpd.pl
            }

            if ( (l_mcsMask  &
                  (((l_mapping[l_index].mcsMaskMSB) << 8) | //endian sensitive
                   l_mapping[l_index].mcsMaskLSB))  &&
                 (l_rankMask &
                  (((l_mapping[l_index].rankMaskMSB) << 8) | //endian sensitve
                   l_mapping[l_index].rankMaskLSB)) &&
                 (l_freqMask & l_mapping[l_index].freqMask) )
            {
                // This row covers mca, ranks, and freq
                l_second = l_mapping[l_index].keywordChar;
                break;
            }
        }

        //Was a matching row found?
        FAPI_ASSERT(0 != l_second,
                    fapi2::GET_MEM_VPD_NO_MATCH_FOUND().
                    set_MCS(fapi2::ATTR_MEMVPD_POS_Type(l_mcsPos)).
                    set_FREQ(uint32_t(i_vpd_info.iv_freq_mhz)).
                    set_DIMM0RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_0)).
                    set_DIMM1RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_1)).
                    set_HEADER(mappingHeader_t(*l_mappingHeader)).
                    set_TARGET(i_target).
                    set_VPDTYPE(i_vpd_info.iv_vpd_type),
                    "No match in mapping table");
        //Was a valid keyword name found?
        FAPI_ASSERT(MAPPING_LAYOUT_INVALID != l_second,
                    fapi2::GET_MEM_VPD_UNSUPPORTED_CONFIGURATION().
                    set_MCS(fapi2::ATTR_MEMVPD_POS_Type(l_mcsPos)).
                    set_FREQ(uint32_t(i_vpd_info.iv_freq_mhz)).
                    set_DIMM0RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_0)).
                    set_DIMM1RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_1)).
                    set_VPDMCSMASK(uint16_t(((l_mapping[l_index].mcsMaskMSB) << 8) |
                                            l_mapping[l_index].mcsMaskLSB)).
                    set_VPDFREQMASK(uint8_t(l_mapping[l_index].freqMask)).
                    set_VPDRANKMASK(uint8_t(((l_mapping[l_index].rankMaskMSB) << 8) |
                                            l_mapping[l_index].rankMaskLSB)).
                    set_TARGET(i_target).
                    set_VPDTYPE(i_vpd_info.iv_vpd_type),
                    "Unsupported configuration");

        // build the keyword name
        o_keywordName[0] = l_first;
        o_keywordName[1] = l_second;
        o_keywordName[2] = 0;
        FAPI_DBG("p9_get_mem_vpd_keyword: keyword name = %s",
                 o_keywordName);
    fapi_try_exit:

        FAPI_DBG("p9_get_mem_vpd_keyword: exit");
        return fapi2::current_err;
    }

} //extern C
