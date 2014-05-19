/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThresholdFile_common.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#include <prdfMfgThresholdFile_common.H>

#ifdef NO_FSP
    // Can't use PRD implementation of
    // assert() in standalone tool code.
    #include <assert.h>
    #define PRDF_ASSERT(x) assert(x)
    #define PRDF_ENTER(args...) // no-op in tool compilation
    #define PRDF_EXIT(args...)  // no-op in tool compilation
    #define PRDF_TRAC(args...)  // no-op in tool compilation
#else
    #include <prdfAssert.h>
    #include <prdfTrace.H>
#endif


namespace PRDF
{

uint8_t MfgThresholdFileCommon::getThreshold(uint32_t i_thrName)
{
    if (iv_thresholds.end() == iv_thresholds.find(i_thrName))
        return INFINITE_LIMIT_THR;
    else
        return iv_thresholds[i_thrName];
}

void MfgThresholdFileCommon::setThreshold(uint32_t i_thrName, uint8_t i_value)
{
    iv_thresholds[i_thrName] = i_value;
}

void MfgThresholdFileCommon::clearThresholds()
{
    iv_thresholds.clear();
}

void MfgThresholdFileCommon::unpackThresholdDataFromBuffer(
                             uint8_t* & i_buffer,
                             uint32_t i_sizeOfBuf)
{
    #define FUNC "[MfgThresholdFileCommon::unpackThresholdDataFromBuffer]"
    PRDF_ENTER(FUNC" number of entries: %d",
               i_sizeOfBuf / sizeof(SyncThreshold_t));

    PRDF_ASSERT(NULL != i_buffer);

    uint32_t l_entryNum = i_sizeOfBuf / sizeof(SyncThreshold_t);

    SyncThreshold_t* l_ptr = reinterpret_cast<SyncThreshold_t*>(i_buffer);

    uint32_t hash = 0;
    uint8_t  value = 0;

    for(uint32_t i = 0; i < l_entryNum && l_ptr != NULL; ++i, l_ptr++)
    {
        hash  = ntohl(l_ptr->hash);
        value = l_ptr->value;
        PRDF_TRAC("threshold: %d, count: %d", hash, value);
        iv_thresholds[hash] = value;
    }

    PRDF_EXIT(FUNC);
    #undef FUNC
}


} // end namespace PRDF
