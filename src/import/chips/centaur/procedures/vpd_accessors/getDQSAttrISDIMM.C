/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getDQSAttrISDIMM.C $ */
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
/// @file getDQSAttrISDIMM.C
/// @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQS attribute
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include <stdint.h>
#include <fapi2.H>
#include <getISDIMMTOC4DAttrs.H>
#include <getDecompressedISDIMMAttrs.H>
#include <getDQSAttrISDIMM.H>
#include <fapi2_mbvpd_access.H>
#include  <generic/memory/lib/utils/c_str.H>

extern "C"
{
    ///
    /// @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQS attribute
    /// @note Access the compressed DQS data in the MBvpd record, SPDX, keyword K1-K9
    /// @param[in] i_mbTarget    - Reference to mb Target
    /// @param[out] o_val[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQS_ENTRIES] - Decoded K data
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
    ///
    fapi2::ReturnCode getDQSAttrISDIMM(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
        uint8_t (&o_val)[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQS_ENTRIES])
    {
        //Record:SPDX, Keyword K1, offset:0,32 bytes
        constexpr uint8_t DQ_BYTES = 17;
        constexpr uint8_t DQS_BYTES = 2;
        constexpr uint32_t l_Q0_KEYWORD_SIZE = 32;
        constexpr uint32_t l_K0_KEYWORD_SIZE = 32;
        constexpr uint32_t l_DQS_KEYWORD_SIZE = 32;
        uint8_t l_k0_keyword[l_K0_KEYWORD_SIZE] = {};
        uint8_t l_q0_keyword[l_Q0_KEYWORD_SIZE] = {};
        uint8_t l_DQS_keyword[l_DQS_KEYWORD_SIZE] = {};
        uint8_t l_DQ_keyword[DQ_KEYWORD_SIZE] = {};
        size_t l_K0Bufsize = l_K0_KEYWORD_SIZE;
        size_t l_Q0Bufsize = l_Q0_KEYWORD_SIZE;
        size_t l_DQSBufsize = l_DQS_KEYWORD_SIZE;
        uint8_t l_dimmPos = 0;
        uint8_t l_actualK0Data = 0;
        fapi2::variable_buffer l_data_buffer_DQ1(DQ_BYTES * BITS_PER_BYTE); //17 bytes
        fapi2::variable_buffer l_data_buffer_DQ2(DQ_BYTES * BITS_PER_BYTE);
        fapi2::variable_buffer l_data_buffer_DQ3(DQ_BYTES * BITS_PER_BYTE);
        fapi2::variable_buffer l_data_buffer_DQ4(DQ_BYTES * BITS_PER_BYTE);
        fapi2::variable_buffer l_data_buffer_DQS1(DQS_BYTES * BITS_PER_BYTE); //2 bytes
        fapi2::variable_buffer l_data_buffer_DQS2(DQS_BYTES * BITS_PER_BYTE);
        fapi2::variable_buffer l_data_buffer_DQS3(DQS_BYTES * BITS_PER_BYTE);
        fapi2::variable_buffer l_data_buffer_DQS4(DQS_BYTES * BITS_PER_BYTE);

        uint8_t l_finalDQArray[DIMM_TO_C4_DQ_ENTRIES] = {};
        uint8_t l_finalDQS1Array[DIMM_TO_C4_DQS_ENTRIES] = {};
        uint8_t l_finalDQS2Array[DIMM_TO_C4_DQS_ENTRIES] = {};
        uint8_t l_finalDQS3Array[DIMM_TO_C4_DQS_ENTRIES] = {};
        uint8_t l_finalDQS4Array[DIMM_TO_C4_DQS_ENTRIES] = {};

        fapi2::MBvpdKeyword l_DQS_Keyword = fapi2::MBVPD_KEYWORD_K1;
        FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_SPDX,
                               fapi2::MBVPD_KEYWORD_K0,
                               i_mbTarget,
                               (uint8_t*) (&l_k0_keyword),
                               l_K0Bufsize), "getDQSAttrISDIMM: Read of K0 Keyword failed on %s", mss::c_str(i_mbTarget));
        FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_SPDX,
                               fapi2::MBVPD_KEYWORD_Q0,
                               i_mbTarget,
                               (uint8_t*) (&l_q0_keyword),
                               l_Q0Bufsize), "getDQSAttrISDIMM: Read of Q0 Keyword failed on %s", mss::c_str(i_mbTarget));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_ISDIMM_MBVPD_INDEX, i_mbTarget, l_dimmPos),
                 "getDQAttrISDIMM: read of ATTR_POS failed on %s", mss::c_str(i_mbTarget));

        l_actualK0Data = l_k0_keyword[l_dimmPos];

        switch(l_actualK0Data)
        {
            case 1:
                l_DQS_Keyword = fapi2::MBVPD_KEYWORD_K1;
                break;

            case 2:
                l_DQS_Keyword = fapi2::MBVPD_KEYWORD_K2;
                break;

            case 3:
                l_DQS_Keyword = fapi2::MBVPD_KEYWORD_K3;
                break;

            case 4:
                l_DQS_Keyword = fapi2::MBVPD_KEYWORD_K4;
                break;

            case 5:
                l_DQS_Keyword = fapi2::MBVPD_KEYWORD_K5;
                break;

            case 6:
                l_DQS_Keyword = fapi2::MBVPD_KEYWORD_K6;
                break;

            case 7:
                l_DQS_Keyword = fapi2::MBVPD_KEYWORD_K7;
                break;

            case 8:
                l_DQS_Keyword = fapi2::MBVPD_KEYWORD_K8;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_INVALID_DQS_DATA().
                            set_DQS_COPY(l_actualK0Data),
                            "getISDIMMTOC4DAttrs: Incorrect Data to read DQS keyword, tried to read copy 0x%02x on %s", l_actualK0Data,
                            mss::c_str(i_mbTarget));
                break;
        }

        FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_SPDX,
                               l_DQS_Keyword,
                               i_mbTarget,
                               (uint8_t*) (&l_DQS_keyword),
                               l_DQSBufsize), "getISDIMMTOC4DAttrs: Read of DQS keyword failed on %s", mss::c_str(i_mbTarget));

        FAPI_TRY(getDQAttribute(i_mbTarget, l_q0_keyword[l_dimmPos],
                                l_DQ_keyword), "getISDIMMTOC4DAttrs: Read of DQ keyword failed on %s", mss::c_str(i_mbTarget));



        for(uint8_t l_dqsDataIndex = 0; l_dqsDataIndex < 2; l_dqsDataIndex++)
        {
            FAPI_TRY(l_data_buffer_DQS1.
                     insertFromRight(l_DQS_keyword[l_dqsDataIndex],
                                     l_dqsDataIndex * 8, 8), "getISDIMMTOC4DAttrs.C: fapi2::variable_buffer inserted wrong on %s", mss::c_str(i_mbTarget));
            FAPI_TRY(l_data_buffer_DQS2.
                     insertFromRight(l_DQS_keyword[l_dqsDataIndex + 2],
                                     l_dqsDataIndex * 8, 8), "getISDIMMTOC4DAttrs.C: fapi2::variable_buffer inserted wrong on %s", mss::c_str(i_mbTarget));
            FAPI_TRY(l_data_buffer_DQS3.
                     insertFromRight(l_DQS_keyword[l_dqsDataIndex + 4],
                                     l_dqsDataIndex * 8, 8), "getISDIMMTOC4DAttrs.C: fapi2::variable_buffer inserted wrong on %s", mss::c_str(i_mbTarget));
            FAPI_TRY(l_data_buffer_DQS4.
                     insertFromRight(l_DQS_keyword[l_dqsDataIndex + 8],
                                     l_dqsDataIndex * 8, 8), "getISDIMMTOC4DAttrs.C: fapi2::variable_buffer inserted wrong on %s", mss::c_str(i_mbTarget));
        }

        for(int l_dqDataIndex = 0; l_dqDataIndex < 17; l_dqDataIndex++)
        {
            FAPI_TRY(l_data_buffer_DQ1.
                     insertFromRight(l_DQ_keyword[l_dqDataIndex],
                                     l_dqDataIndex * 8, 8), "getISDIMMTOC4DAttrs.C: fapi2::variable_buffer inserted wrong on %s", mss::c_str(i_mbTarget));
            FAPI_TRY(l_data_buffer_DQ2.
                     insertFromRight(l_DQ_keyword[l_dqDataIndex + 17],
                                     l_dqDataIndex * 8, 8), "getISDIMMTOC4DAttrs.C: fapi2::variable_buffer inserted wrong on %s", mss::c_str(i_mbTarget));
            FAPI_TRY(l_data_buffer_DQ3.
                     insertFromRight(l_DQ_keyword[l_dqDataIndex + 34],
                                     l_dqDataIndex * 8, 8), "getISDIMMTOC4DAttrs.C: fapi2::variable_buffer inserted wrong on %s", mss::c_str(i_mbTarget));
            FAPI_TRY(l_data_buffer_DQ4.
                     insertFromRight(l_DQ_keyword[l_dqDataIndex + 51],
                                     l_dqDataIndex * 8, 8), "getISDIMMTOC4DAttrs.C: fapi2::variable_buffer inserted wrong on %s", mss::c_str(i_mbTarget));
        }

        decodeISDIMMAttrs(l_data_buffer_DQ1, l_data_buffer_DQS1,
                          l_finalDQArray, l_finalDQS1Array);
        decodeISDIMMAttrs(l_data_buffer_DQ2, l_data_buffer_DQS2,
                          l_finalDQArray, l_finalDQS2Array);
        decodeISDIMMAttrs(l_data_buffer_DQ3, l_data_buffer_DQS3,
                          l_finalDQArray, l_finalDQS3Array);
        decodeISDIMMAttrs(l_data_buffer_DQ4, l_data_buffer_DQS4,
                          l_finalDQArray, l_finalDQS4Array);

        for(uint8_t l_finalIndex = 0; l_finalIndex < DIMM_TO_C4_DQS_ENTRIES; l_finalIndex++)
        {
            o_val[0][l_finalIndex] = l_finalDQS1Array[l_finalIndex];
            o_val[1][l_finalIndex] = l_finalDQS2Array[l_finalIndex];
            o_val[2][l_finalIndex] = l_finalDQS3Array[l_finalIndex];
            o_val[3][l_finalIndex] = l_finalDQS4Array[l_finalIndex];
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

}
