/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThresholdFile_common.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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

int MfgThresholdFileCommon::getThreshold(uint32_t i_thrName)
{
    if (iv_thresholds.end() == iv_thresholds.find(i_thrName))
        return -1;
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
