/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getDQAttrISDIMM.C $ */
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
/// @file getDQAttrISDIMM.C
/// @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQ attribute
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
#include <getDQAttrISDIMM.H>
#include <fapi2_mbvpd_access.H>
#include  <generic/memory/lib/utils/c_str.H>

extern "C"
{

    ///
    /// @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQ attribute
    /// @note Access the compressed DQ data in the MBvpd record SPDX, keyword Q1-Q9
    /// @param[in] i_mbTarget    - Reference to mb Target
    /// @param[out] o_val[4][80] - Decoded Q data
    /// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
    ///
    fapi2::ReturnCode getDQAttrISDIMM(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
        uint8_t (&o_val)[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQ_ENTRIES])
    {

        constexpr uint32_t l_Q0_KEYWORD_SIZE = 32;
        constexpr uint8_t DQ_BYTES = 17;
        constexpr uint8_t DQS_BYTES = 2;

        //Record:SPDX, Keyword Q1, offset:0, 96 bytes.
        uint8_t l_q0_keyword[l_Q0_KEYWORD_SIZE] = {};
        size_t l_Q0Bufsize = l_Q0_KEYWORD_SIZE;
        uint8_t l_DQ_keyword[DQ_KEYWORD_SIZE] = {};
        uint8_t l_dimmPos = 0;
        //end actual data
        fapi2::variable_buffer l_data_buffer_DQ1(DQ_BYTES * BITS_PER_BYTE); //17 bytes
        fapi2::variable_buffer l_data_buffer_DQ2(DQ_BYTES * BITS_PER_BYTE);
        fapi2::variable_buffer l_data_buffer_DQ3(DQ_BYTES * BITS_PER_BYTE);
        fapi2::variable_buffer l_data_buffer_DQ4(DQ_BYTES * BITS_PER_BYTE);
        fapi2::variable_buffer l_data_buffer_DQS(DQS_BYTES * BITS_PER_BYTE); //2 bytes
        uint8_t l_finalDQ1Array[DIMM_TO_C4_DQ_ENTRIES] = {};
        uint8_t l_finalDQ2Array[DIMM_TO_C4_DQ_ENTRIES] = {};
        uint8_t l_finalDQ3Array[DIMM_TO_C4_DQ_ENTRIES] = {};
        uint8_t l_finalDQ4Array[DIMM_TO_C4_DQ_ENTRIES] = {};
        uint8_t l_finalDQSArray[DIMM_TO_C4_DQS_ENTRIES] = {};

        FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_SPDX,
                               fapi2::MBVPD_KEYWORD_Q0,
                               i_mbTarget,
                               (uint8_t*) (&l_q0_keyword),
                               l_Q0Bufsize), "getDQAttrISDIMM: Read of Q0 Keyword failed on %s", mss::c_str(i_mbTarget));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_ISDIMM_MBVPD_INDEX, i_mbTarget, l_dimmPos),
                 "getDQAttrISDIMM: read of ATTR_POS failed on %s", mss::c_str(i_mbTarget));
        FAPI_TRY(getDQAttribute(i_mbTarget, l_q0_keyword[l_dimmPos],
                                l_DQ_keyword), "getDQAttrISDIMM: read of DQ Keyword failed on %s", mss::c_str(i_mbTarget));


        for(uint8_t l_dataIndex = 0; l_dataIndex < DQ_BYTES; l_dataIndex++)
        {
            l_data_buffer_DQ1.insertFromRight(l_DQ_keyword[l_dataIndex],
                                              l_dataIndex * 8, 8);
            l_data_buffer_DQ2.insertFromRight(l_DQ_keyword[l_dataIndex + 17],
                                              l_dataIndex * 8, 8);
            l_data_buffer_DQ3.insertFromRight(l_DQ_keyword[l_dataIndex + 34],
                                              l_dataIndex * 8, 8);
            l_data_buffer_DQ4.insertFromRight(l_DQ_keyword[l_dataIndex + 51],
                                              l_dataIndex * 8, 8);
        }

        decodeISDIMMAttrs(l_data_buffer_DQ1, l_data_buffer_DQS,
                          l_finalDQ1Array, l_finalDQSArray);
        decodeISDIMMAttrs(l_data_buffer_DQ2, l_data_buffer_DQS,
                          l_finalDQ2Array, l_finalDQSArray);
        decodeISDIMMAttrs(l_data_buffer_DQ3, l_data_buffer_DQS,
                          l_finalDQ3Array, l_finalDQSArray);
        decodeISDIMMAttrs(l_data_buffer_DQ4, l_data_buffer_DQS,
                          l_finalDQ4Array, l_finalDQSArray);

        for(uint8_t l_finalIndex = 0; l_finalIndex < DIMM_TO_C4_DQ_ENTRIES; l_finalIndex++)
        {
            o_val[0][l_finalIndex] = l_finalDQ1Array[l_finalIndex];
            o_val[1][l_finalIndex] = l_finalDQ2Array[l_finalIndex];
            o_val[2][l_finalIndex] = l_finalDQ3Array[l_finalIndex];
            o_val[3][l_finalIndex] = l_finalDQ4Array[l_finalIndex];
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

}
