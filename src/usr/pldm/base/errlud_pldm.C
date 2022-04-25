/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/errlud_pldm.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/**
 *  @file errlud_pldm.C
 *
 *  @brief Implementation of classes to log pldm FFDC
 */
#include "errlud_pldm.H"
#include <pldm/pldm_reasoncodes.H>
#include "pldm_fr.H"
#include <pldm/pldm_trace.H> // PLDM_INF

namespace PLDM
{
/**
 * @brief Copies flight recorder data to output buffer
 *        Format: 2 byte size of fr data + x bytes fr data
 * @param[in/out] io_buffer Output buffer (pre-allocated)
 * @param[in]   i_frDataSize Full byte size of fr data
 * @param[in]   i_frData Pointer to start of fr data
 */
void copyDataToBuffer(char * io_buffer, const uint16_t i_frDataSize, void * i_frData)
{
    memcpy(io_buffer, &i_frDataSize, sizeof(i_frDataSize));
    if (i_frDataSize > 0)
    {
        memcpy(io_buffer+sizeof(i_frDataSize), i_frData, i_frDataSize);
    }
}

//------------------------------------------------------------------------------
//  PLDM User Details
//  Inbound BMC->HB request flight recorder log
//------------------------------------------------------------------------------
UdPldmFrInRequestParameters::UdPldmFrInRequestParameters()
{
    // Set up Ud instance variables
    iv_CompId = PLDM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = PLDM_UDT_FR_INBOUND_REQUESTS;

    std::vector<pldm_msg_hdr> frData;
    Singleton<pldmFR>::instance().dumpRequestFr(PLDM::INBOUND, frData);

    const uint16_t fullDataSize = frData.size()*sizeof(pldm_msg_hdr);
    PLDM_DBG("UdPldmFrInRequestParameters: full size = %d * %d = %d", frData.size(), sizeof(pldm_msg_hdr), fullDataSize);
    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(fullDataSize+sizeof(fullDataSize)));
    copyDataToBuffer(l_pBuf, fullDataSize, frData.data());
}

UdPldmFrInRequestParameters::~UdPldmFrInRequestParameters()
{
}

//------------------------------------------------------------------------------
//  PLDM User Details
//  Outbound HB->BMC request flight recorder log
//------------------------------------------------------------------------------
UdPldmFrOutRequestParameters::UdPldmFrOutRequestParameters()
{
    // Set up Ud instance variables
    iv_CompId = PLDM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = PLDM_UDT_FR_OUTBOUND_REQUESTS;

    std::vector<pldm_msg_hdr> frData;
    Singleton<pldmFR>::instance().dumpRequestFr(PLDM::OUTBOUND, frData);

    const uint16_t fullDataSize = (frData.size()*sizeof(pldm_msg_hdr));
    PLDM_DBG("UdPldmFrOutRequestParameters: full size = %d * %d = %d", frData.size(), sizeof(pldm_msg_hdr), fullDataSize);
    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(fullDataSize+sizeof(fullDataSize)));
    copyDataToBuffer(l_pBuf, fullDataSize, frData.data());
}

UdPldmFrOutRequestParameters::~UdPldmFrOutRequestParameters()
{
}
//------------------------------------------------------------------------------
//  PLDM User Details
//  Inbound BMC->HB response flight recorder log
//------------------------------------------------------------------------------
UdPldmFrInResponseParameters::UdPldmFrInResponseParameters()
{
    // Set up Ud instance variables
    iv_CompId = PLDM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = PLDM_UDT_FR_INBOUND_RESPONSES;

    std::vector<pldm_rsp_hdr> frData;
    Singleton<pldmFR>::instance().dumpResponseFr(PLDM::INBOUND, frData);

    const uint16_t fullDataSize = frData.size()*sizeof(pldm_rsp_hdr);
    PLDM_DBG("UdPldmFrInResponseParameters: full size = %d * %d = %d", frData.size(), sizeof(pldm_rsp_hdr), fullDataSize);
    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(fullDataSize+sizeof(fullDataSize)));
    copyDataToBuffer(l_pBuf, fullDataSize, frData.data());
}

UdPldmFrInResponseParameters::~UdPldmFrInResponseParameters()
{
}

//------------------------------------------------------------------------------
//  PLDM User Details
//  Outbound HB->BMC response flight recorder log
//------------------------------------------------------------------------------
UdPldmFrOutResponseParameters::UdPldmFrOutResponseParameters()
{
    // Set up Ud instance variables
    iv_CompId = PLDM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = PLDM_UDT_FR_OUTBOUND_RESPONSES;

    std::vector<pldm_rsp_hdr> frData;
    Singleton<pldmFR>::instance().dumpResponseFr(PLDM::OUTBOUND, frData);

    const uint16_t fullDataSize = frData.size()*sizeof(pldm_rsp_hdr);
    PLDM_DBG("UdPldmFrOutResponseParameters: full size = %d * %d = %d", frData.size(), sizeof(pldm_rsp_hdr), fullDataSize);
    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(fullDataSize+sizeof(fullDataSize)));
    copyDataToBuffer(l_pBuf, fullDataSize, frData.data());
}

UdPldmFrOutResponseParameters::~UdPldmFrOutResponseParameters()
{
}

} // end PLDM namespace
