/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/errlud_vpd.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2024                        */
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
 *  @file errlud_vpd.C
 *
 *  @brief Implementation of classes to log VPD FFDC
 */
#include "errlud_vpd.H"
#include "ipvpd.H"
#include <vpd/vpdreasoncodes.H>
#include <string.h>

namespace VPD
{

//------------------------------------------------------------------------------
//  UdVpdParms
//------------------------------------------------------------------------------
UdVpdParms::UdVpdParms( TARGETING::Target * i_target,
                        uint64_t i_buflen,
                        uint64_t i_record,
                        uint64_t i_keyword,
                        EEPROM::EEPROM_SOURCE i_source,
                        bool i_readNotWrite )
:ERRORLOG::ErrlUserDetails()
{
    // Set up Ud instance variables
    iv_CompId =VPD_COMP_ID;
    iv_Version = 2;
    iv_SubSection = VPD_UDT_PARAMETERS;

    //***** Memory Layout *****
    // 1 byte   : Read / Not-Write
    // 4 bytes  : Target HUID
    // 8 bytes  : Length of In/Out Buffer
    // 8 bytes  : Record
    // 8 bytes  : Keyword
    // 4 bytes  : EEPROM Source

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint8_t)
                                        +sizeof(uint32_t)*2
                                        +sizeof(uint64_t)*3));
    uint64_t tmp64 = 0;
    uint32_t tmp32 = 0;
    uint8_t tmp8 = 0;

    tmp8 = i_readNotWrite;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp32 = TARGETING::get_huid(i_target);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp64 = i_buflen;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_record;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_keyword;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp32 = i_source;
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

}

//------------------------------------------------------------------------------
UdVpdParms::~UdVpdParms()
{

}

//------------------------------------------------------------------------------
void UdVpdParms::addToLog(errlHndl_t i_errl,
                          ERRORLOG::propagation_t i_behavior)
{
    // Check for a previous version of this type before adding myself.
    // There are a few code paths that could end up with duplicate calls.
    // The assumption is that the first entry added will be the most
    // accurate so that is the one we want to keep.
    auto l_prevUD = i_errl->getUDSections(VPD_COMP_ID, VPD_UDT_PARAMETERS);
    if( l_prevUD.empty() )
    {
        ERRORLOG::ErrlUserDetails::addToLog(i_errl, i_behavior);
    }
}

}
