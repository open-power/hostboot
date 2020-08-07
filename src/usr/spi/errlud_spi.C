/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/errlud_spi.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
 *  @file errlud_spi.C
 *
 *  @brief Implementation of classes to log spi FFDC
 */
#include "errlud_spi.H"
#include <spi/spireasoncodes.H>
#include <devicefw/driverif.H>

namespace SPI
{

//------------------------------------------------------------------------------
//  SPI User Details
//------------------------------------------------------------------------------
UdSpiEepromParameters::UdSpiEepromParameters(uint8_t i_opType,
                                             int64_t i_accessType,
                                             SpiEepromOp i_spiOp)
{
    // Set up Ud instance variables
    iv_CompId = SPI_COMP_ID;
    iv_Version = 1;
    iv_SubSection = SPI_EEPROM_UDT_PARAMETERS;

    //***** Memory Layout *****
    // 1 byte   : Op Type (DeviceFW::OperationType)
    // 4 bytes  : SPI controller Target HUID
    // 8 bytes  : Access Type (DeviceFW::AccessType)
    // 1 byte   : Engine
    // 8 bytes  : Offset
    // 8 bytes  : Length of In/Out Buffer
    // 8 bytes  : Adjusted Offset (to align request)
    // 8 bytes  : Adjusted Length of internal Buffer (to align request)
    // 1 byte   : Start index in adjusted buffer where requested data starts
    // 1 byte   : 1 : Adjusted Buffer used, 0: Adjusted Buffer unused


    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint8_t)*2
                                        +sizeof(uint32_t)
                                        +sizeof(uint64_t)
                                        +sizeof(uint8_t)
                                        +sizeof(uint64_t)*4
                                        +sizeof(uint8_t)*2));
    uint64_t tmp64 = 0;
    uint32_t tmp32 = 0;
    uint8_t tmp8 = 0;

    tmp8 = i_opType;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp32 = TARGETING::get_huid(i_spiOp.getControllerTarget());
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp64 = i_accessType;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp8 = i_spiOp.getEngine();
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp64 = i_spiOp.getOffset();
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_spiOp.getLength();
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_spiOp.getAdjustedOffset();
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_spiOp.getAdjustedLength();
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp8 = i_spiOp.getStartIndex();
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = i_spiOp.getUsingAdjustedBuffer();
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);
}

//------------------------------------------------------------------------------
UdSpiEepromParameters::~UdSpiEepromParameters()
{
}

UdSpiTpmParameters::UdSpiTpmParameters(uint8_t i_opType,
                                       int64_t i_accessType,
                                       SpiTpmOp i_spiOp)
{
    // Set up Ud instance variables
    iv_CompId = SPI_COMP_ID;
    iv_Version = 1;
    iv_SubSection = SPI_TPM_UDT_PARAMETERS;

    //***** Memory Layout *****
    // 1 byte   : Op Type (DeviceFW::OperationType)
    // 4 bytes  : Controller Target HUID
    // 8 bytes  : Access Type (DeviceFW::AccessType)
    // 1 byte   : Engine
    // 8 bytes  : Offset
    // 4 bytes  : Locality
    // 4 bytes  : TPM HUID
    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint8_t)*2
                                        +sizeof(uint32_t)
                                        +sizeof(uint64_t)
                                        +sizeof(uint8_t)
                                        +sizeof(uint64_t)
                                        +sizeof(uint32_t)
                                        +sizeof(uint32_t)));
    uint64_t tmp64 = 0;
    uint32_t tmp32 = 0;
    uint8_t tmp8 = 0;

    tmp8 = i_opType;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp32 = TARGETING::get_huid(i_spiOp.getControllerTarget());
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp64 = i_accessType;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp8 = i_spiOp.getEngine();
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp64 = i_spiOp.getOffset();
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp32 = i_spiOp.getLocality();
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp32 = TARGETING::get_huid(i_spiOp.getTpmTarget());
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);
}

UdSpiTpmParameters::~UdSpiTpmParameters()
{
}

} // end SPI namespace
