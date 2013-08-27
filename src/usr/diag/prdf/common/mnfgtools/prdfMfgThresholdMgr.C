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

MfgThresholdMgr::MfgThresholdMgr() :
  iv_file(NULL)
{

}


MfgThresholdMgr::~MfgThresholdMgr()
{
    if(NULL != iv_file)
    {
        delete iv_file;
        iv_file = NULL;
    }
}

MfgThresholdMgr * MfgThresholdMgr::getInstance()
{
    static MfgThresholdMgr l_mgr;
    return &l_mgr;
}

uint8_t MfgThresholdMgr::getThreshold(uint32_t i_thrName)
{
    this->setupFile();

    uint8_t l_thr = iv_file->getThreshold(i_thrName);

    if ((MfgThresholdFileCommon::INFINITE_LIMIT_THR) <= l_thr)
        return getThresholdDefault(i_thrName);
    else if (0 == l_thr) // zero is the "infinite" threshold.
        return (MfgThresholdFileCommon::INFINITE_LIMIT_THR);
    else
        return l_thr;
}

ThresholdResolution::ThresholdPolicy*
    MfgThresholdMgr::getThresholdP(uint32_t i_thrName)
{
    uint8_t threshold = getThreshold(i_thrName);
    uint32_t interval = ThresholdResolution::NONE;

    if( (MfgThresholdFileCommon::INFINITE_LIMIT_THR) <= threshold )
    {
        PRDF_TRAC("MfgThresholdMgr::getThresholdP: "
                  "infinite threshold: 0x%x", i_thrName);
        interval = ThresholdResolution::ONE_SEC;
    }

    ThresholdResolution::ThresholdPolicy l_policy( threshold, interval );

    return &(iv_thrs.get(l_policy));
}

void MfgThresholdMgr::reset()
{
    iv_thrs.clear();

    if(NULL != iv_file)
    {
        delete iv_file;
        iv_file = NULL;
    }
}

uint8_t MfgThresholdMgr::getThresholdDefault(uint32_t i_thrName)
{
    uint8_t l_value = 0;

#define PRDF_MFGTHRESHOLD_TABLE_BEGIN if
#define PRDF_MFGTHRESHOLD_TABLE_END \
        (true) l_value = (MfgThresholdFileCommon::INFINITE_LIMIT_THR);
#define PRDF_MFGTHRESHOLD_ENTRY(a,b,c) \
        (i_thrName == b) { l_value = c; } else if
#include <prdfMfgThresholds.H>

    // zero is a special "infinite limit" value.
    if (0 == l_value)
        l_value = (MfgThresholdFileCommon::INFINITE_LIMIT_THR);

    return l_value;
}

void MfgThresholdMgr::setupFile()
{
    if(NULL == iv_file)
    {
        iv_file = new MfgThresholdFile();
        iv_file->setup();
    }
}

bool operator==(ThresholdResolution::ThresholdPolicy & l,
                ThresholdResolution::ThresholdPolicy & r)
{
    return (l.threshold == r.threshold) &&
           (l.interval == r.interval);
}

} // end namespace PRDF

