/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThresholdMgr.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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

#ifndef __PRDF_PRDFMFGTHRESHOLDMGR_H
#define __PRDF_PRDFMFGTHRESHOLDMGR_H

#include <stdint.h>
#include <prdfMfgThreshold.H>
#include <prdfThresholdResolutions.H>
#include <prdfFlyWeight.H>

namespace PRDF
{

class MfgThresholdMgr
{
    public:

        /**
         *  @brief constructor
        */
        MfgThresholdMgr();

        /**
         *  @brief destructor
        */
        ~MfgThresholdMgr();

        /**
         * @brief get MfgThresholdMgr singleton
         *
         * @return MfgThresholdMgr singleton
         */
        static MfgThresholdMgr * getInstance();

        /**
         * @brief get threshold value from name
         * @param[in] i_thrName - threshold name
         *
         * @return corresponding threshold value
         */
        uint8_t getThreshold(uint32_t i_thrName);

        /**
         * @brief get threshold policy from name
         * @param[in] i_thrName - threshold name
         *
         * @return threshold policy
         */
        ThresholdResolution::ThresholdPolicy* getThresholdP(uint32_t i_thrName);

        /**
         *  @brief reset/clean up MfgThresholdMgr
        */
        void reset();

        /**
         * @brief get MfgThreshold
         *
         * @return MfgThreshold pointer
         */
        MfgThreshold* getMfgThreshold();

    private:

        /**
         *  @brief set up MfgThreshold
        */
        virtual void setupThresholds();

        FlyWeight<ThresholdResolution::ThresholdPolicy, 10> iv_thrs;

        MfgThreshold* iv_mfgThres;
};

} // end namespace PRDF

#endif
