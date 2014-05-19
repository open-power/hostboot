/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/mnfgtools/prdfMfgThresholdFile.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2014              */
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

#ifndef __PRDF_PRDFMFGTHRESHOLDFILE_H
#define __PRDF_PRDFMFGTHRESHOLDFILE_H

#include <prdfMfgThresholdFile_common.H>

namespace PRDF
{

class MfgThresholdFile : public MfgThresholdFileCommon
{
    public:

        /**
         *  @brief configure MfgThresholdFile
        */
        virtual void setup();

        /**
         * @brief serialize threshold data into data buffer
         * @param[in/out] o_buffer - data buffer
         * @param[in] i_sizeOfBuf - size of buffer
         */
        virtual void packThresholdDataIntoBuffer(
                                    uint8_t* & o_buffer,
                                    uint32_t i_sizeOfBuf);

    private:

        /**
         *  @brief sync MFG thresholds from FSP
        */
        void syncFromFsp();

};

} // end namespace PRDF

#endif
