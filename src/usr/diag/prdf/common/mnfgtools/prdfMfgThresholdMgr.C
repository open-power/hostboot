/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThresholdMgr.C $    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2013              */
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

#include <prdfMfgThresholdMgr.H>
#include <prdfFlyWeight.C>

namespace PRDF
{

MfgThresholdMgr::MfgThresholdMgr()
{
    PRDF_MFG_THRESHOLD_FILE_INIT(iv_file);
}


MfgThresholdMgr::~MfgThresholdMgr()
{
    PRDF_MFG_THRESHOLD_FILE_DELETE(iv_file);
}

MfgThresholdMgr * MfgThresholdMgr::getInstance()
{
    static MfgThresholdMgr l_mgr;
    return &l_mgr;
}

uint16_t MfgThresholdMgr::getThreshold(uint32_t i_thrName)
{
    this->setupFile();

    int l_thr = -1;
    PRDF_MFG_THRESHOLD_FILE_GET(iv_file, i_thrName, l_thr);

    if (0 > l_thr)
        return getThresholdDefault(i_thrName);
    else if (0 == l_thr) // zero is the "infinite" threshold.
        return INFINITE_LIMIT_THR;
    else
        return (uint16_t) l_thr; //FIXME In case of error (-1), is it right behavior
}

const ThresholdResolution::ThresholdPolicy*
    MfgThresholdMgr::getThresholdP(uint32_t i_thrName)
{
    const static ThresholdResolution::ThresholdPolicy l_policy (getThreshold(i_thrName), 0xffffffff );

    return &(l_policy);
}

void MfgThresholdMgr::reset()
{
    PRDF_MFG_THRESHOLD_FILE_DELETE(iv_file);
}

uint16_t MfgThresholdMgr::getThresholdDefault(uint32_t i_thrName)
{
    uint32_t l_value = 0;

#define PRDF_MFGTHRESHOLD_TABLE_BEGIN if
#define PRDF_MFGTHRESHOLD_TABLE_END \
        (true) l_value = INFINITE_LIMIT_THR;
#define PRDF_MFGTHRESHOLD_ENTRY(a,b,c) \
        (i_thrName == b) { l_value = c; } else if
#include <prdfMfgThresholds.H>

    // zero is a special "infinite limit" value.
    if (0 == l_value)
        l_value = INFINITE_LIMIT_THR;

    return l_value;
}

void MfgThresholdMgr::setupFile()
{
    PRDF_MFG_THRESHOLD_FILE_SETUP(iv_file);
}

bool operator==(const ThresholdResolution::ThresholdPolicy & l,
                const ThresholdResolution::ThresholdPolicy & r)
{
    return (l.threshold == r.threshold) &&
           (l.interval == r.interval);
}

} // end namespace PRDF

