/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getDQSAttrISDIMM.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: getDQSAttrISDIMM.C,v 1.1 2015/04/09 13:36:16 janssens Exp $
/**
 * @file getDQSAttrISDIMM.C
 *
 * @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQS attribute
 */

#include <stdint.h>
#include <fapi.H>
#include <getISDIMMTOC4DAttrs.H>
#include <getDecompressedISDIMMAttrs.H>
#include <getDQSAttrISDIMM.H>

extern "C"
{

using namespace fapi;

fapi::ReturnCode getDQSAttrISDIMM(
                const fapi::Target &i_mbTarget,
                uint8_t (&o_val)[4][20])
{
    //Record:SPDX, Keyword K1, offset:0,32 bytes
    const uint32_t l_Q0_KEYWORD_SIZE = 32;
    const uint32_t l_K0_KEYWORD_SIZE = 32;
    const uint32_t l_DQS_KEYWORD_SIZE = 32;
    uint8_t l_k0_keyword[l_K0_KEYWORD_SIZE];
    uint8_t l_q0_keyword[l_Q0_KEYWORD_SIZE];
    uint8_t l_DQS_keyword[l_DQS_KEYWORD_SIZE];
    uint8_t l_DQ_keyword[DQ_KEYWORD_SIZE];
    uint32_t l_K0Bufsize = l_K0_KEYWORD_SIZE;
    uint32_t l_Q0Bufsize = l_Q0_KEYWORD_SIZE;
    uint32_t l_DQSBufsize = l_DQS_KEYWORD_SIZE;


    fapi::ReturnCode l_fapirc;
    do{
        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_SPDX,
                       fapi::MBVPD_KEYWORD_K0,
                       i_mbTarget,
                       (uint8_t *) (&l_k0_keyword),
                       l_K0Bufsize);
        if(l_fapirc)
        {
            FAPI_ERR("getDQSAttrISDIMM: Read of K0 Keyword failed");
            break;
        }
        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_SPDX,
                       fapi::MBVPD_KEYWORD_Q0,
                       i_mbTarget,
                       (uint8_t *) (&l_q0_keyword),
                       l_Q0Bufsize);
        if(l_fapirc)
        {
            FAPI_ERR("getDQSAttrISDIMM: Read of Q0 Keyword failed");
            break;
        }

        uint8_t l_dimmPos = 0;
        l_fapirc = FAPI_ATTR_GET(ATTR_ISDIMM_MBVPD_INDEX,&i_mbTarget,l_dimmPos);
        if(l_fapirc)
        {
            FAPI_ERR("getDQAttrISDIMM: read of ATTR_POS failed");
            break;
        }

        fapi::MBvpdKeyword l_DQS_Keyword = fapi::MBVPD_KEYWORD_K1;
        uint8_t l_actualK0Data = l_k0_keyword[l_dimmPos];
        switch(l_actualK0Data)
        {
            case 1:
                l_DQS_Keyword = fapi::MBVPD_KEYWORD_K1;
                break;
            case 2:
                l_DQS_Keyword = fapi::MBVPD_KEYWORD_K2;
                break;
            case 3:
                l_DQS_Keyword = fapi::MBVPD_KEYWORD_K3;
                break;
            case 4:
                l_DQS_Keyword = fapi::MBVPD_KEYWORD_K4;
                break;
            case 5:
                l_DQS_Keyword = fapi::MBVPD_KEYWORD_K5;
                break;
            case 6:
                l_DQS_Keyword = fapi::MBVPD_KEYWORD_K6;
                break;
            case 7:
                l_DQS_Keyword = fapi::MBVPD_KEYWORD_K7;
                break;
            case 8:
                l_DQS_Keyword = fapi::MBVPD_KEYWORD_K8;
                break;
            default:
                FAPI_ERR("getISDIMMTOC4DAttrs: Incorrect Data to read DQS keyword, tried to read copy 0x%02x",l_actualK0Data);
                const uint8_t & DQS_COPY = l_actualK0Data;
                FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INVALID_DQS_DATA);
                break;
        }
        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_SPDX,
                                     l_DQS_Keyword,
                                     i_mbTarget,
                                     (uint8_t *) (&l_DQS_keyword),
                                     l_DQSBufsize);
        if(l_fapirc)
        {
            FAPI_ERR("getISDIMMTOC4DAttrs: Read of DQS keyword failed");
            break;
        }

        l_fapirc = getDQAttribute(i_mbTarget,l_q0_keyword[l_dimmPos],
                                  l_DQ_keyword);
        if(l_fapirc)
        {
            FAPI_ERR("getISDIMMTOC4DAttrs: Read of DQ keyword failed");
            break;
        }

        uint32_t rc_num = 0;

        if(!l_fapirc)
        {
            ecmdDataBufferBase l_data_buffer_DQ1(136); //17 bytes
            ecmdDataBufferBase l_data_buffer_DQ2(136);
            ecmdDataBufferBase l_data_buffer_DQ3(136);
            ecmdDataBufferBase l_data_buffer_DQ4(136);
            ecmdDataBufferBase l_data_buffer_DQS1(16); //2 bytes
            ecmdDataBufferBase l_data_buffer_DQS2(16);
            ecmdDataBufferBase l_data_buffer_DQS3(16);
            ecmdDataBufferBase l_data_buffer_DQS4(16);

            uint8_t l_finalDQArray[80];
            uint8_t l_finalDQS1Array[20];
            uint8_t l_finalDQS2Array[20];
            uint8_t l_finalDQS3Array[20];
            uint8_t l_finalDQS4Array[20];

            for(int l_dqsDataIndex=0;l_dqsDataIndex<2;l_dqsDataIndex++)
            {
                rc_num |= l_data_buffer_DQS1.
                        insertFromRight(l_DQS_keyword[l_dqsDataIndex],
                                        l_dqsDataIndex*8,8);
                rc_num |= l_data_buffer_DQS2.
                        insertFromRight(l_DQS_keyword[l_dqsDataIndex+2],
                                        l_dqsDataIndex*8,8);
                rc_num |= l_data_buffer_DQS3.
                        insertFromRight(l_DQS_keyword[l_dqsDataIndex+4],
                                        l_dqsDataIndex*8,8);
                rc_num |= l_data_buffer_DQS4.
                        insertFromRight(l_DQS_keyword[l_dqsDataIndex+8],
                                        l_dqsDataIndex*8,8);
            }
            for(int l_dqDataIndex=0;l_dqDataIndex<17;l_dqDataIndex++)
            {
                rc_num |= l_data_buffer_DQ1.
                        insertFromRight(l_DQ_keyword[l_dqDataIndex],
                                        l_dqDataIndex*8,8);
                rc_num |= l_data_buffer_DQ2.
                        insertFromRight(l_DQ_keyword[l_dqDataIndex+17],
                                        l_dqDataIndex*8,8);
                rc_num |= l_data_buffer_DQ3.
                        insertFromRight(l_DQ_keyword[l_dqDataIndex+34],
                                        l_dqDataIndex*8,8);
                rc_num |= l_data_buffer_DQ4.
                        insertFromRight(l_DQ_keyword[l_dqDataIndex+51],
                                        l_dqDataIndex*8,8);
            }

            l_fapirc.setEcmdError(rc_num);
            if(l_fapirc)
            {
                FAPI_ERR("getISDIMMTOC4DAttrs.C: ecmdDataBufferBase inserted wrong");
                break;
            }

            decodeISDIMMAttrs(l_data_buffer_DQ1,l_data_buffer_DQS1,
                            l_finalDQArray,l_finalDQS1Array);
            decodeISDIMMAttrs(l_data_buffer_DQ2,l_data_buffer_DQS2,
                            l_finalDQArray,l_finalDQS2Array);
            decodeISDIMMAttrs(l_data_buffer_DQ3,l_data_buffer_DQS3,
                            l_finalDQArray,l_finalDQS3Array);
            decodeISDIMMAttrs(l_data_buffer_DQ4,l_data_buffer_DQS4,
                            l_finalDQArray,l_finalDQS4Array);

            for(int l_finalIndex=0;l_finalIndex<20;l_finalIndex++)
            {
                o_val[0][l_finalIndex] = l_finalDQS1Array[l_finalIndex];
                o_val[1][l_finalIndex] = l_finalDQS2Array[l_finalIndex];
                o_val[2][l_finalIndex] = l_finalDQS3Array[l_finalIndex];
                o_val[3][l_finalIndex] = l_finalDQS4Array[l_finalIndex];
            }
        }
    }while(0);
    return l_fapirc;
}

}
