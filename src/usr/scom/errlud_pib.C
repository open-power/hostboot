/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/errlud_pib.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
 *  @file errlud_pib.C
 *
 *  @brief Implementation of classes to log SCOM FFDC
 */
#include <scom/errlud_pib.H>
#include <string.h>
#include <scom/scomreasoncodes.H>
#include <errl/errlentry.H>

namespace SCOM
{

//------------------------------------------------------------------------------
//  PibInfo
//------------------------------------------------------------------------------
UdPibInfo::UdPibInfo( uint8_t i_pibErr )
{
    // Set up Ud instance variables
    iv_CompId = SCOM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = SCOM_UDT_PIB;


    //***** Memory Layout *****
    // 1 byte  :  PIB
    auto l_pBuf = reallocUsrBuf(sizeof(uint8_t));
    memcpy(l_pBuf, &i_pibErr, sizeof(i_pibErr));

}

//------------------------------------------------------------------------------
UdPibInfo::~UdPibInfo()
{

}


}