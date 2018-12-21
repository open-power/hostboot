/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/errlud_pgData.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef ERRLUD_PGDATA_H
#define ERRLUD_PGDATA_H

/**
 * @file errlud_pgData.H
 *
 * Defines the class that logs the HWAS Parital Good failures
 *
 */

#include <errl/errluserdetails.H>
#include <hwas/common/vpdConstants.H>

namespace HWAS
{

    /**
     * @class ErrlUdPartialGoodData
     *
     * @brief Adds the Parital Good vector to an error log.
     */

    class ErrlUdPartialGoodData : public ERRORLOG::ErrlUserDetails
    {
    public:

        /**
         * @brief Constructor
         *
         * @param[in] i_modelPgData    The model-specific partial good xbus and
         *                             obus data. This is used to construct an
         *                             "all good" vector to compare against the
         *                             i_pgData.
         * @param[in] i_pgData         The partial good data read from the VPD.
         */
        ErrlUdPartialGoodData(
                const uint16_t (&i_modelPgData)[MODEL_PG_DATA_ENTRIES],
                const uint16_t (&i_pgData)[VPD_CP00_PG_DATA_ENTRIES]);

        /**
         * @brief Destructor
         */
        virtual ~ErrlUdPartialGoodData()
        {}

        // Delete the Copy Constructor
        ErrlUdPartialGoodData(const ErrlUdPartialGoodData&) = delete;

        // Delete the Copy Assignment
        ErrlUdPartialGoodData& operator=(const ErrlUdPartialGoodData&) = delete;

        // Delete the Move Constructor
        ErrlUdPartialGoodData(ErrlUdPartialGoodData&&) = delete;

        // Delete the Move Assignment
        ErrlUdPartialGoodData& operator=(ErrlUdPartialGoodData&&) = delete;

    };
}

#endif
