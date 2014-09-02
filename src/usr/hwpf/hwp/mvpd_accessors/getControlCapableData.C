/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getControlCapableData.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $ID: getControlCapableData.C, v 1.1 2014/9/4 09:05:00 eliner Exp $
/**
 *  @file getControlCapable.C
 *
 *  @brief MBvpd accessor for the ATTR_MSS_POWER_CONTROL_CAPABLE attributes
 */

#include    <stdint.h>
#include    <fapi.H>
#include    <getControlCapableData.H>

extern "C"
{
using namespace fapi;
fapi::ReturnCode getControlCapableData(
                const fapi::Target &i_mbTarget,
                uint8_t & o_val)
{
    //Record:VSPD, Keyword:MR, offset: 253, 1 byte.
    const uint32_t MR_KEYWORD_SIZE = 255;

    struct mr_keyword
    {
        uint8_t filler[253];
        uint8_t position; //offset 253
        uint8_t extraFiller[MR_KEYWORD_SIZE-sizeof(filler)-sizeof(position)];
    };

    fapi::ReturnCode l_fapirc;
    mr_keyword * l_pMrBuffer = new mr_keyword;
    uint32_t l_MrBufsize = MR_KEYWORD_SIZE;
    do{

        l_fapirc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                    fapi::MBVPD_KEYWORD_MR,
                    i_mbTarget,
                    reinterpret_cast<uint8_t *>(l_pMrBuffer),
                    l_MrBufsize);
        if(l_fapirc)
        {
            FAPI_ERR("getControlCapableData: Read of MR Keyword failed");
            break;
        }
        o_val = l_pMrBuffer->position;

    }while(0);

    delete l_pMrBuffer;
    l_pMrBuffer = NULL;

    return l_fapirc;
}
}
