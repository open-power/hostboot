/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getISDIMMTOC4DAttrs.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
// $Id: getISDIMMTOC4DAttrs.C,v 1.4 2015/04/09 13:36:21 janssens Exp $
/**
 * @file getISDIMMTOC4DAttrs.C
 *
 * @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQ and DQS attributes
 */

#include <stdint.h>
#include <fapi.H>
#include <getISDIMMTOC4DAttrs.H>
#include <getDecompressedISDIMMAttrs.H>

extern "C"
{

using namespace fapi;

fapi::ReturnCode getDQAttribute(const fapi::Target &i_mbTarget,
                uint32_t i_whichCopy, uint8_t (&o_DQKeyword)[DQ_KEYWORD_SIZE])
{
    uint32_t l_DQBufsize = DQ_KEYWORD_SIZE;

    fapi::ReturnCode l_fapirc;
    fapi::MBvpdKeyword l_DQKey = fapi::MBVPD_KEYWORD_Q1;
    do{
        switch(i_whichCopy)
        {
            case 1:
                l_DQKey = fapi::MBVPD_KEYWORD_Q1;
                break;
            case 2:
                l_DQKey = fapi::MBVPD_KEYWORD_Q2;
                break;
            case 3:
                l_DQKey = fapi::MBVPD_KEYWORD_Q3;
                break;
            case 4:
                l_DQKey = fapi::MBVPD_KEYWORD_Q4;
                break;
            case 5:
                l_DQKey = fapi::MBVPD_KEYWORD_Q5;
                break;
            case 6:
                l_DQKey = fapi::MBVPD_KEYWORD_Q6;
                break;
            case 7:
                l_DQKey = fapi::MBVPD_KEYWORD_Q7;
                break;
            case 8:
                l_DQKey = fapi::MBVPD_KEYWORD_Q8;
                break;
            default:
                FAPI_ERR("getISDIMMTOC4DAttrs: Incorrect Data to read DQ keyword, tried to read copy 0x%02x",i_whichCopy);
                const uint8_t & DQ_COPY = i_whichCopy;
                FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_INVALID_DQ_DATA);
                break;
        }

        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_SPDX,
                                     l_DQKey,
                                     i_mbTarget,
                                     (uint8_t *) (&o_DQKeyword),
                                     l_DQBufsize);
        if(l_fapirc)
        {
            FAPI_ERR("getISDIMMTOC4DAttrs: Read of DQ keyword failed");
            break;
        }
    }while(0);
    return l_fapirc;

}

}
