/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/accessors/p9_get_mem_vpd_keyword.C $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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
using fapi2::mappingKeywordRow;
using fapi2::MAPPING_LAYOUT_VERSION;
using fapi2::MAPPING_LAYOUT_INVALID;
using fapi2::MAPPING_LAYOUT_LAST;
using fapi2::MAPPING_LAYOUT_MAXROWS;
using fapi2::MAPPING_LAYOUT_MCA0;
using fapi2::MAPPING_LAYOUT_DIMM0_RANK0;
using fapi2::MAPPING_LAYOUT_DIMM0_RANK4;
using fapi2::MAPPING_LAYOUT_DIMM1_RANK0;
using fapi2::MAPPING_LAYOUT_DIMM1_RANK4;
using fapi2::MAPPING_LAYOUT_FREQ0;
using fapi2::MAPPING_LAYOUT_FREQ3;

extern "C"
{

/// @brief Return VPD keyword based on MCA, VPDInfo, and MR/MT mapping
/// The MR and MT keyword contains a header followed by a table. Each
/// row in the table has criteria to select a vpd keyword.
///
/// @param[in]  i_target, the MCA
/// @param[in]  i_vpd_info, vpd criteria
/// @param[in]  i_pMapping, MR or MT keyword data
/// @param[in]  i_mappingSize, size of i_pMapping buffer
/// @param[out] o_keywordName, keyword with vpd
/// @return FAPI2_RC_SUCCESS iff ok
    fapi2::ReturnCode p9_get_mem_vpd_keyword(
        const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const fapi2::VPDInfo<fapi2::TARGET_TYPE_MCA>& i_vpd_info,
        const uint8_t*         i_pMapping,
        const size_t           i_mappingSize,
        fapi2::keywordName_t& o_keywordName)
    {
        char l_first  = 0;
        char l_second = 0;
        fapi2::ATTR_MEMVPD_POS_Type l_mcaPos = 0;
        uint16_t l_mcaMask  = 0;
        uint8_t  l_rankMask = 0;
        uint8_t  l_freqMask = 0;
        uint32_t l_freqTableIndex = 0;
        fapi2::ATTR_MEMVPD_FREQS_MHZ_Type l_freqTable = {0};
        uint32_t l_freqTableCnt = sizeof(l_freqTable) / sizeof(l_freqTable[0]);
        uint32_t index = 0; //start with header
        const mappingKeywordRow* l_mapping =
            reinterpret_cast<const mappingKeywordRow*>(i_pMapping);

        FAPI_DBG("p9_get_mem_vpd_keyword: enter");

        // Validate size of mapping to be at least large enough for biggest
        // mapping table expected.
        const size_t MAPPING_LAYOUT_MAXSIZE =
            size_t(sizeof(mappingKeywordRow) * MAPPING_LAYOUT_MAXROWS);
        FAPI_ASSERT(MAPPING_LAYOUT_MAXSIZE <= i_mappingSize,
                    fapi2::GET_MEM_VPD_MAPPING_TOO_SMALL().
                    set_SIZE(size_t(i_mappingSize)).
                    set_EXPECTED(size_t(MAPPING_LAYOUT_MAXSIZE)),
                    "Mapping keyword size %d less than min %d expected",
                    i_mappingSize,
                    MAPPING_LAYOUT_MAXSIZE);

        // Validate mapping keyword version supported
        FAPI_ASSERT(MAPPING_LAYOUT_VERSION == l_mapping[index].layoutVersion,
                    fapi2::GET_MEM_VPD_UNSUPPORTED_VERSION().
                    set_VERSION(uint8_t(l_mapping[index].layoutVersion)).
                    set_EXPECTED(uint8_t(MAPPING_LAYOUT_VERSION)),
                    "Header version %d not supported % expected",
                    l_mapping[index].layoutVersion,
                    MAPPING_LAYOUT_VERSION);

        // Validate vpd type and set first keyword name character based on type
        switch (i_vpd_info.iv_vpd_type)
        {
            case fapi2::MT:
                l_first = 'X';  //vpd keyword name X0..X9,XA..XZ
                break;

            case fapi2::MR:
                l_first = 'J';  //vpd keyword name J0..J9,JA..JZ
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::GET_MEM_VPD_UNSUPPORTED_TYPE().
                            set_TYPE(fapi2::MemVpdData(i_vpd_info.iv_vpd_type)),
                            "Invalid vpd type = %d",
                            i_vpd_info.iv_vpd_type);
        }

        // Get the MCA position
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEMVPD_POS,
                               i_target,
                               l_mcaPos),
                 "p9_get_mem_vpd_keyword: get ATTR_MEMVPD_POS failed");
        l_mcaMask = (MAPPING_LAYOUT_MCA0 >> l_mcaPos); //zero based
        FAPI_DBG ("p9_get_mem_vpd_keyword: mca position = %d mask=%x",
                  l_mcaPos, l_mcaMask);

        // Get the frequency index
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
                    set_MEMVPDFREQ3(uint32_t(l_freqTable[3])),
                    "Frequency %d not in ATTR_MEMVPD_FREQS_MHZ",
                    i_vpd_info.iv_freq_mhz);
        l_freqMask = (MAPPING_LAYOUT_FREQ0 >> l_freqTableIndex); //zero based
        FAPI_DBG ("p9_get_mem_vpd_keyword: frequency index = %d mask=%x",
                  l_freqTableIndex, l_freqMask);

        // Get rank mask. Valid ranks are 0,1,2,4
        // Mask = rrrrssss  rrrr for rank0, ssss for rank1
        switch (i_vpd_info.iv_rank_count_dimm_0)
        {
            case 0: //can use shift, high order nibble
            case 1:
            case 2:
                l_rankMask =
                    (MAPPING_LAYOUT_DIMM0_RANK0 >> i_vpd_info.iv_rank_count_dimm_0);
                break;

            case 4:
                l_rankMask = MAPPING_LAYOUT_DIMM0_RANK4;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::GET_MEM_VPD_UNSUPPORTED_RANK().
                            set_RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_0)),
                            "Unsupported rank = %d should be 0,1,2, or 4",
                            i_vpd_info.iv_rank_count_dimm_0);
        }

        switch (i_vpd_info.iv_rank_count_dimm_1)
        {
            case 0: //can use shift, low order nibble
            case 1:
            case 2:
                l_rankMask |=
                    (MAPPING_LAYOUT_DIMM1_RANK0 >> i_vpd_info.iv_rank_count_dimm_1);
                break;

            case 4:
                l_rankMask |= MAPPING_LAYOUT_DIMM1_RANK4;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::GET_MEM_VPD_UNSUPPORTED_RANK().
                            set_RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_1)),
                            "Unsupported rank = %d should be 0,1,2, or 4",
                            i_vpd_info.iv_rank_count_dimm_1);
        }

        FAPI_DBG("p9_get_mem_vpd_keyword: rank0=%d rank1=%d mask=%x",
                 i_vpd_info.iv_rank_count_dimm_0,
                 i_vpd_info.iv_rank_count_dimm_1,
                 l_rankMask);

        // Use mapping data to find the second vpd keyword character
        // Skip first row which is the version header.
        for (index = 1; index < MAPPING_LAYOUT_MAXROWS - 1; index++)
        {
            if (MAPPING_LAYOUT_LAST == l_mapping[index].keywordChar)
            {
                break; //hit end of table
            }

            if ( (l_mcaMask  &
                  (((l_mapping[index].mcaMaskMSB) << 8) | //endian sensitive
                   l_mapping[index].mcaMaskLSB))  &&
                 (l_rankMask & l_mapping[index].rankMask) &&
                 (l_freqMask & l_mapping[index].freqMask) )
            {
                // This row covers mca, ranks, and freq
                l_second = l_mapping[index].keywordChar;
                break;
            }
        }

        //Was a matching row found?
        FAPI_ASSERT(0 != l_second,
                    fapi2::GET_MEM_VPD_NO_MATCH_FOUND().
                    set_TYPE(fapi2::MemVpdData(i_vpd_info.iv_vpd_type)).
                    set_MCA(fapi2::ATTR_MEMVPD_POS_Type(l_mcaPos)).
                    set_FREQ(uint32_t(i_vpd_info.iv_freq_mhz)).
                    set_DIMM0RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_0)).
                    set_DIMM1RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_1)).
                    set_HEADER(mappingKeywordRow(l_mapping[0])),
                    "No match in mapping table");
        //Was a valid keyword name found?
        FAPI_ASSERT(MAPPING_LAYOUT_INVALID != l_second,
                    fapi2::GET_MEM_VPD_UNSUPPORTED_CONFIGURATION().
                    set_TYPE(fapi2::MemVpdData(i_vpd_info.iv_vpd_type)).
                    set_MCA(fapi2::ATTR_MEMVPD_POS_Type(l_mcaPos)).
                    set_FREQ(uint32_t(i_vpd_info.iv_freq_mhz)).
                    set_DIMM0RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_0)).
                    set_DIMM1RANK(uint64_t(i_vpd_info.iv_rank_count_dimm_1)).
                    set_VPDMCAMASK(uint16_t(((l_mapping[index].mcaMaskMSB) << 8) |
                                            l_mapping[index].mcaMaskLSB)).
                    set_VPDFREQMASK(uint8_t(l_mapping[index].freqMask)).
                    set_VPDRANKMASK(uint8_t(l_mapping[index].rankMask)),
                    "Unsupported configuration");

        // build keyword
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
