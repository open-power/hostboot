/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getISDIMMTOC4DAttrs.C $ */
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
/// @file getISDIMMTOC4DAttrs.C
/// @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQ and DQS attributes
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
#include <fapi2_mbvpd_access.H>

extern "C"
{

///
/// @brief Utility function for the ATTR_VPD_ISDIMMTOC4DQ attribute
/// @note Given the D0 information, return the correct DQ copy.
/// @param[in] i_mbTarget  - Reference to mb Target
/// @param[in] i_whichCopy  - D0 information of which Q copy to get
/// @param[out] o_DQKeyword - Correct DQ information
/// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode getDQAttribute(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
                                     uint32_t i_whichCopy, uint8_t (&o_DQKeyword)[DQ_KEYWORD_SIZE])
    {
        size_t l_DQBufsize = DQ_KEYWORD_SIZE;

        fapi2::MBvpdKeyword l_DQKey = fapi2::MBVPD_KEYWORD_Q1;

        switch(i_whichCopy)
        {
            case 1:
                l_DQKey = fapi2::MBVPD_KEYWORD_Q1;
                break;

            case 2:
                l_DQKey = fapi2::MBVPD_KEYWORD_Q2;
                break;

            case 3:
                l_DQKey = fapi2::MBVPD_KEYWORD_Q3;
                break;

            case 4:
                l_DQKey = fapi2::MBVPD_KEYWORD_Q4;
                break;

            case 5:
                l_DQKey = fapi2::MBVPD_KEYWORD_Q5;
                break;

            case 6:
                l_DQKey = fapi2::MBVPD_KEYWORD_Q6;
                break;

            case 7:
                l_DQKey = fapi2::MBVPD_KEYWORD_Q7;
                break;

            case 8:
                l_DQKey = fapi2::MBVPD_KEYWORD_Q8;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MBVPD_INVALID_DQ_DATA().
                            set_DQ_COPY(i_whichCopy),
                            "getISDIMMTOC4DAttrs: Incorrect Data to read DQ keyword, tried to read copy 0x%02x", i_whichCopy);
                break;
        }

        FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_SPDX,
                               l_DQKey,
                               i_mbTarget,
                               (uint8_t*) (&o_DQKeyword),
                               l_DQBufsize), "getISDIMMTOC4DAttrs: Read of DQ keyword failed");
    fapi_try_exit:
        return fapi2::current_err;
    }

}
