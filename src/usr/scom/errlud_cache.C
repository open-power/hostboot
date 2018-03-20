/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/errlud_cache.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2018                        */
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
 *  @file errlud_cache.C
 *
 *  @brief Implementation of classes to log Centaur SCOM register cache
 *       mismatch FFDC
 */

#include <scom/scomreasoncodes.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <util/utilmem.H>
#include "errlud_cache.H"

SECUREBOOT::CENTAUR_SECURITY::UdCentaurCacheMismatch::UdCentaurCacheMismatch(
    const uint64_t i_registerAddr,
    const uint64_t i_unmaskedExpectedValue,
    const uint64_t i_unmaskedActualValue,
    const uint64_t i_mask)
{
    // Set up Ud instance variables
    iv_CompId     = SCOM_COMP_ID;
    iv_Version    = SCOM::SCOM_UDT_VERSION_1;
    iv_SubSection = SCOM::SCOM_UDT_CENTAUR_CACHE_MISMATCH;

    const auto maskedExpectedValue=i_unmaskedExpectedValue&i_mask;
    const auto maskedActualValue  =i_unmaskedActualValue&i_mask;

    //***** Version SCOM_UDT_VERSION_1 Memory Layout *****
    // 8 bytes : Centaur SCOM address with the cache miscompare
    // 8 bytes : Expected value from cache (unmasked)
    // 8 bytes : Actual value read from hardware (unmasked)
    // 8 bytes : Mask of bits to compare for the two values
    // 8 bytes : Expected value from cache (masked)
    // 8 bytes : Actual value read from hardware (masked)

    UtilMem memBuf;
    memBuf << i_registerAddr
           << i_unmaskedExpectedValue
           << i_unmaskedActualValue
           << i_mask
           << maskedExpectedValue
           << maskedActualValue;

    auto pError = memBuf.getLastError();
    if(pError)
    {
        errlCommit(pError,SCOM_COMP_ID);
    }
    else
    {
        uint8_t* const pBuf =
            reallocUsrBuf(memBuf.size());
        memcpy(pBuf, memBuf.base(), memBuf.size());
    }
}

