/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getDQAttrISDIMM.C $           */
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
// $Id: getDQAttrISDIMM.C,v 1.1 2015/04/09 13:36:12 janssens Exp $
/**
 * @file getDQAttrISDIMM.C
 *
 * @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQ attribute
 */

#include <stdint.h>
#include <fapi.H>
#include <getISDIMMTOC4DAttrs.H>
#include <getDecompressedISDIMMAttrs.H>
#include <getDQAttrISDIMM.H>

extern "C"
{

using namespace fapi;

fapi::ReturnCode getDQAttrISDIMM(
                const fapi::Target &i_mbTarget,
                uint8_t (&o_val)[4][80])
{

    const uint32_t l_Q0_KEYWORD_SIZE = 32;
    //Record:SPDX, Keyword Q1, offset:0, 96 bytes.
    uint8_t l_q0_keyword[l_Q0_KEYWORD_SIZE];
    uint32_t l_Q0Bufsize = l_Q0_KEYWORD_SIZE;
    uint8_t l_DQ_keyword[DQ_KEYWORD_SIZE];

    fapi::ReturnCode l_fapirc;
    do{

        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_SPDX,
                        fapi::MBVPD_KEYWORD_Q0,
                        i_mbTarget,
                        (uint8_t *) (&l_q0_keyword),
                        l_Q0Bufsize);
        if(l_fapirc)
        {
            FAPI_ERR("getDQAttrISDIMM: Read of Q0 Keyword failed");
            break;
        }

        uint8_t l_dimmPos = 0;
        l_fapirc = FAPI_ATTR_GET(ATTR_ISDIMM_MBVPD_INDEX,&i_mbTarget,l_dimmPos);
        if(l_fapirc)
        {
            FAPI_ERR("getDQAttrISDIMM: read of ATTR_POS failed");
            break;
        }

        l_fapirc = getDQAttribute(i_mbTarget,l_q0_keyword[l_dimmPos],
                                  l_DQ_keyword);
        if(l_fapirc)
        {
            FAPI_ERR("getDQAttrISDIMM: read of DQ Keyword failed");
            break;
        }
    }while(0);

    //end actual data

    ecmdDataBufferBase l_data_buffer_DQ1(136); //17 bytes
    ecmdDataBufferBase l_data_buffer_DQ2(136);
    ecmdDataBufferBase l_data_buffer_DQ3(136);
    ecmdDataBufferBase l_data_buffer_DQ4(136);
    ecmdDataBufferBase l_data_buffer_DQS(16); //2 bytes
    uint8_t l_finalDQ1Array[80];
    uint8_t l_finalDQ2Array[80];
    uint8_t l_finalDQ3Array[80];
    uint8_t l_finalDQ4Array[80];
    uint8_t l_finalDQSArray[20];

    for(int l_dataIndex=0;l_dataIndex<17;l_dataIndex++)
    {
        l_data_buffer_DQ1.insertFromRight(l_DQ_keyword[l_dataIndex],
                        l_dataIndex*8,8);
        l_data_buffer_DQ2.insertFromRight(l_DQ_keyword[l_dataIndex+17],
                        l_dataIndex*8,8);
        l_data_buffer_DQ3.insertFromRight(l_DQ_keyword[l_dataIndex+34],
                        l_dataIndex*8,8);
        l_data_buffer_DQ4.insertFromRight(l_DQ_keyword[l_dataIndex+51],
                        l_dataIndex*8,8);
    }
    decodeISDIMMAttrs(l_data_buffer_DQ1,l_data_buffer_DQS,
                    l_finalDQ1Array,l_finalDQSArray);
    decodeISDIMMAttrs(l_data_buffer_DQ2,l_data_buffer_DQS,
                    l_finalDQ2Array,l_finalDQSArray);
    decodeISDIMMAttrs(l_data_buffer_DQ3,l_data_buffer_DQS,
                    l_finalDQ3Array,l_finalDQSArray);
    decodeISDIMMAttrs(l_data_buffer_DQ4,l_data_buffer_DQS,
                    l_finalDQ4Array,l_finalDQSArray);

    for(int l_finalIndex=0;l_finalIndex<80;l_finalIndex++)
    {
        o_val[0][l_finalIndex] = l_finalDQ1Array[l_finalIndex];
        o_val[1][l_finalIndex] = l_finalDQ2Array[l_finalIndex];
        o_val[2][l_finalIndex] = l_finalDQ3Array[l_finalIndex];
        o_val[3][l_finalIndex] = l_finalDQ4Array[l_finalIndex];
    }
    return FAPI_RC_SUCCESS;
}

}
