/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/errlud_nvdimm.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
 *  @file errlud_nvdimm.C
 *
 *  @brief Implementation of classes to log nvdimm FFDC
 */
#include <isteps/nvdimm/nvdimmreasoncodes.H>
#include "nvdimmdd.H"
#include "errlud_nvdimm.H"

namespace NVDIMM
{

//------------------------------------------------------------------------------
//  NVDIMM User Details
//------------------------------------------------------------------------------
UdNvdimmParms::UdNvdimmParms( uint8_t i_opType,
                              TARGETING::Target * i_target,
                              uint64_t i_buflen,
                              nvdimm_addr_t &i_i2cInfo )
{
    // Set up Ud instance variables
    iv_CompId = NVDIMM_COMP_ID;
    iv_Version = 3;
    iv_SubSection = NVDIMM_UDT_PARAMETERS;

    //***** Memory Layout *****
    // 1 byte   : Op Type Description
    // 1 byte   : Op Type (DeviceFW::OperationType)
    // 4 bytes  : Target HUID
    // 8 bytes  : Length of In/Out Buffer
    // 8 bytes  : Offset
    // 8 bytes  : Port
    // 8 bytes  : Engine
    // 8 bytes  : Device Address
    // 1 byte   : Address Size
    // 8 bytes  : Write Page Size
    // 8 bytes  : Device Size (in KB)
    // 8 bytes  : Chip Count
    // 8 bytes  : Write Cycle Time
    // 1 byte   : I2C MUX Bus Selector
    // N bytes  : I2C MUX path in string form

    // Cache the MUX path in string form for reference and easy access
    char *l_muxPath = i_i2cInfo.i2cMuxPath.toString();

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint8_t)*2
                                        +sizeof(uint32_t)
                                        +sizeof(uint64_t)*5
                                        +sizeof(uint8_t)
                                        +sizeof(uint64_t)*4
                                        +sizeof(uint8_t)
                                        +(strlen(l_muxPath) +1) ) );

    uint64_t tmp64 = 0;
    uint32_t tmp32 = 0;
    uint8_t tmp8 = 0;

    if( i_opType == DeviceFW::READ )
    {
        tmp8 = 0;
    }
    else if( i_opType == DeviceFW::WRITE )
    {
        tmp8 = 1;
    }
    else
    {
        tmp8 = 2;
    }
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = i_opType;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp32 = TARGETING::get_huid(i_target);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp64 = i_buflen;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.offset;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.port;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.engine;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.devAddr;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp8 = static_cast<uint8_t>(i_i2cInfo.addrSize);
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp64 = i_i2cInfo.writePageSize;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.devSize_KB;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.chipCount;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.writeCycleTime;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    // Begin Version 3 Data
    tmp8 = i_i2cInfo.i2cMuxBusSelector;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    memcpy(l_pBuf, l_muxPath, strlen(l_muxPath));
    l_pBuf += strlen(l_muxPath);
    l_pBuf = '\0';   // add a terminator for ease of parsing
    ++l_pBuf;

    free(l_muxPath);
    l_muxPath = nullptr;
}

//------------------------------------------------------------------------------
UdNvdimmParms::~UdNvdimmParms()
{

}

} // end NVDIMM namespace
