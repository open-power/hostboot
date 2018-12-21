/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/errlud_pgData.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
 * @file errlud_pgData.C
 *
 * @brief Implementation of class to log HWAS Partial Good vector.
 *
 */

#include <hwas/common/hwasError.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <util/utilmem.H>
#include "errlud_pgData.H"

HWAS::ErrlUdPartialGoodData::ErrlUdPartialGoodData(
        const uint16_t (&i_modelPgData)[MODEL_PG_DATA_ENTRIES],
        const uint16_t (&i_pgData)[VPD_CP00_PG_DATA_ENTRIES])
{
    // Setup the User Details instance variables.
    iv_CompId       = HWAS_COMP_ID;
    iv_Version      = HWAS_UDT_VERSION_1;
    iv_SubSection   = HWAS_UDT_PARTIAL_GOOD_DATA;

    UtilMem l_memBuf;

    // ******** HWAS_UDT_VERSION_1 Memory Layout ******** //
    // 2 Bytes: Model dependent XBUS All Good Value
    // 2 Bytes: Model dependent OBUS All Good Value
    // Last 128 bytes
    // Each 2 Bytes: An entry in the Partial Good Vector.

    static_assert(2 == MODEL_PG_DATA_ENTRIES,
                  "Expected MODEL_PG_DATA_ENTRIES == 2 entries");
    static_assert(64 == VPD_CP00_PG_DATA_ENTRIES,
                  "Expected VPD_CP00_PG_DATA_ENTRIES == 64 entries");

    // Store the All Good values in the buffer
    for (size_t i = 0; i < MODEL_PG_DATA_ENTRIES; ++i)
    {
        l_memBuf << i_modelPgData[i];
    }

    // Store the contents of the partial good vector in the buffer
    for (size_t i = 0; i < VPD_CP00_PG_DATA_ENTRIES; ++i)
    {
        l_memBuf << i_pgData[i];
    }

    auto l_pError = l_memBuf.getLastError();
    if (l_pError)
    {
        errlCommit(l_pError, HWAS_COMP_ID);
    }
    else
    {
        uint8_t* const l_pBuffer = reallocUsrBuf(l_memBuf.size());
        memcpy(l_pBuffer, l_memBuf.base(), l_memBuf.size());
    }
}
