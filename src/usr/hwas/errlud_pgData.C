/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/errlud_pgData.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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

using PARTIAL_GOOD::pg_entry_t;

HWAS::ErrlUdPartialGoodData::ErrlUdPartialGoodData(
    const model_ag_entries& i_modelAgData,
    const partialGoodVector& i_pgData)
{
    // Setup the User Details instance variables.
    iv_CompId       = HWAS_COMP_ID;
    iv_Version      = HWAS_UDT_VERSION_1;
    iv_SubSection   = HWAS_UDT_PARTIAL_GOOD_DATA_V2;

    UtilMem l_memBuf;

    // ******** HWAS_UDT_VERSION_1 Memory Layout ******** //
    // NUM_MODEL_AG_ENTRIES : uint32_t
    // MODEL_AG_ENTRIES     : model_ag_entry[NUM_MODEL_AG_ENTRIES]
    // NUM_PG_ENTRIES       : uint32_t
    // PG_ENTRIES           : pg_entry_t[NUM_PG_ENTRIES]

    // @TODO RTC 249996 i_modelAgData.size() instead of MODEL_AG_DATA_ENTRIES
    l_memBuf << static_cast<uint32_t>(MODEL_AG_DATA_ENTRIES);

    // Store the model-specific All Good values in the buffer
    for (const auto entry : i_modelAgData)
    {
        l_memBuf << entry.index;
        l_memBuf << entry.value;
    }

    l_memBuf << static_cast<uint32_t>(i_pgData.size());

    // Store the contents of the partial good vector in the buffer
    for (const auto entry : i_pgData)
    {
        l_memBuf << entry;
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
