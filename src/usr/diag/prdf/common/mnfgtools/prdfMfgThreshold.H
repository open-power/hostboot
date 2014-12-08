/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: usr/diag/prdf/common/mnfgtools/prdfMfgThreshold.H $           */
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

#ifndef __PRDFMFGTHRESHOLD_H
#define __PRDFMFGTHRESHOLD_H

#include <stdint.h>
#include <map>

namespace PRDF
{

class MfgThreshold
{
    public:

        /**
         *  @brief threshold map
        */
        typedef std::map<uint32_t, uint8_t> Threshold_t;

        /**
         * @brief Infinite threshold enum
        */
        enum { INFINITE_LIMIT_THR = 0xff };

        /**
         *  @brief constructor
        */
        MfgThreshold() {};

        /**
         *  @brief destructor
        */
        ~MfgThreshold() {};

        /**
         *  @brief setup the thresholds
        */
        void setup();

        /**
         * @brief get threshold value from name
         * @param[in] i_thrName - threshold name
         *
         * @return corresponding threshold value
         */
        uint8_t getThreshold(uint32_t i_thrName);

        /**
         * @brief set threshold name/value
         * @param[in] i_thrName - threshold name
         * @param[in] i_value - threshold value
         */
        void setThreshold(uint32_t i_thrName, uint8_t i_value);

        /**
         * @brief clear all thresholds
         *
         */
        void clearThresholds();

    protected:

        Threshold_t iv_thresholds;

};

} // end namespace PRDF

#endif
