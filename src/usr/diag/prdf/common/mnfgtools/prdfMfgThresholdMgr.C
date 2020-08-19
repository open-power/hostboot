/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThresholdMgr.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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

#include <prdfMfgThresholdMgr.H>
#include <prdfFlyWeight.C>

namespace PRDF
{

MfgThresholdMgr::MfgThresholdMgr() :
  iv_mfgThres(nullptr)
{

}

MfgThresholdMgr::~MfgThresholdMgr()
{
    reset();
}

MfgThresholdMgr * MfgThresholdMgr::getInstance()
{
    static MfgThresholdMgr l_mgr;
    return &l_mgr;
}

uint8_t MfgThresholdMgr::getThreshold(uint32_t i_thrName)
{
    this->setupThresholds();

    uint8_t l_thr = iv_mfgThres->getThreshold(i_thrName);

    if (0 == l_thr) // zero is the "infinite" threshold.
        return (MfgThreshold::INFINITE_LIMIT_THR);
    else
        return l_thr;
}

ThresholdResolution::ThresholdPolicy*
    MfgThresholdMgr::getThresholdP(uint32_t i_thrName)
{
    uint8_t threshold = getThreshold(i_thrName);
    uint32_t interval = ThresholdResolution::NONE;

    if( (MfgThreshold::INFINITE_LIMIT_THR) <= threshold )
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

    if(nullptr != iv_mfgThres)
    {
        delete iv_mfgThres;
        iv_mfgThres = nullptr;
    }
}

MfgThreshold * MfgThresholdMgr::getMfgThreshold()
{
    setupThresholds();
    return iv_mfgThres;
}

void MfgThresholdMgr::setupThresholds()
{
    if(nullptr == iv_mfgThres)
    {
        iv_mfgThres = new MfgThreshold();
        iv_mfgThres->setup();
    }
}

bool operator==(ThresholdResolution::ThresholdPolicy & l,
                ThresholdResolution::ThresholdPolicy & r)
{
    return (l.threshold == r.threshold) &&
           (l.interval == r.interval);
}

} // end namespace PRDF

