/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThreshold.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#include <prdfMfgThreshold.H>
#include <prdfAssert.h>
#include <prdfTrace.H>
#include <prdfTargetServices.H>

namespace PRDF
{

using namespace TARGETING;

uint8_t MfgThreshold::getThreshold(uint32_t i_thrName)
{
    if (iv_thresholds.end() == iv_thresholds.find(i_thrName))
        return INFINITE_LIMIT_THR;
    else
        return iv_thresholds[i_thrName];
}

void MfgThreshold::setThreshold(uint32_t i_thrName, uint8_t i_value)
{
    iv_thresholds[i_thrName] = i_value;
}

void MfgThreshold::clearThresholds()
{
    iv_thresholds.clear();
}

void MfgThreshold::setup()
{
    #define PRDF_FUNC "[MfgThreshold::setup] "
    do
    {
        // Get top level target
        TargetHandle_t l_sysTarget = NULL;
        l_sysTarget = PlatServices::getSystemTarget();
        if(NULL == l_sysTarget)
        {
            PRDF_ERR(PRDF_FUNC"No System target!");
            break;
        }

        // Set the thresholds
        #ifdef __PRDF_PRDFMFGTHRESHOLDS_H
        #undef __PRDF_PRDFMFGTHRESHOLDS_H
        #endif

        #ifdef PRDF_MFGTHRESHOLD_ENTRY
        #undef PRDF_MFGTHRESHOLD_TABLE_BEGIN
        #undef PRDF_MFGTHRESHOLD_TABLE_END
        #undef PRDF_MFGTHRESHOLD_ENTRY
        #endif

        #define PRDF_MFGTHRESHOLD_TABLE_BEGIN
        #define PRDF_MFGTHRESHOLD_TABLE_END
        #define PRDF_MFGTHRESHOLD_ENTRY(a,b)                 \
        {                                                    \
            uint8_t l_threshold = l_sysTarget->getAttr<a>(); \
            this->setThreshold(a, l_threshold);              \
        }
        #include <prdfMfgThresholdAttrs.H>

    }while(0);

    #undef PRDF_FUNC
}

} // end namespace PRDF
