/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfLineDelete.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2005,2021                        */
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

/** @file prdfLineDelete.H
 * Contains the definitions needed for the line delete algorithms and the CE
 * table.
 */

#ifndef __PRDFLINEDELETE_H
#define __PRDFLINEDELETE_H

#include <UtilSMap.H>
#include <prdfThresholdResolutions.H>
#include <iipstep.h>
#include <iipCaptureData.h>

namespace PRDF
{

/** @namespace LineDelete
 *  Namespace to encapsulate all of the LineDelete specific classes and enums.
 */
namespace LineDelete
{

    /** @enum CacheType
     *  Used to express where a cache error occurred.
     */
    enum CacheType
    {
        L3 = 0,
        L3_DIR = 1,
        L2 = 2,
        L2_DIR = 4,
        CACHE_MASK = L3 | L3_DIR | L2 | L2_DIR,

        SLICE_A = 8,
        SLICE_B = 16,
        SLICE_MASK = SLICE_A | SLICE_B
    };

    /** @enum CacheErrorType
     *  Used to express the types of cache errors that can occur.
     */
    enum CacheErrorType
    {
        UE, CE
    };

    /** @typedef PrdfCacheAddress
     *        Used to index cache error hits in the CE table.
     */
    typedef uint32_t PrdfCacheAddress;

    /** @typedef PrdfCacheAddressTable
     *  Maps Cache Addresses to hit counts.
     */
    typedef UtilSMap<PrdfCacheAddress, uint32_t> PrdfCacheAddressTable;

    /** @class PrdfCacheCETable
     *  Used to store and threshold cache CE errors.
     *
     *  Takes a threshold policy (such as "2 per day") and allows that many hits
     *  per address before signalling "at threshold".  (the 2nd occurrence would
     *  be the at threshold).
     *
     *  @note This is now being used for eRepair as well as cache CEs.
     */
    class PrdfCacheCETable
    {
      public:

        /** Default constructor */
        PrdfCacheCETable() {}

        /**
         * @brief Constructor from ThresholdPolicy struct.
         * @param i_thPolicy A pointer to a ThresholdPolicy struct.
         */
        explicit PrdfCacheCETable(
                    const ThresholdResolution::ThresholdPolicy i_thPolicy ) :
            iv_thPolicy(i_thPolicy), cv_flushTimerInited(false)
        {}

        // NOTE: iv_thPolicy should never be deleted in this class so the
        // default destructor will be sufficient.

            /** @fn addAddress
             *  Insert an address into the CE table.
             *
             *  @param The CE address.
             *  @param The Service Data Collector to get the current time.
             *
             *  @return true - if the threshold policy has been reached.
             *  @return false - if the threshold policy has not been reached.
             */
            bool addAddress(PrdfCacheAddress, STEP_CODE_DATA_STRUCT &);

            /** @fn PrdfCacheCETable::isIntervalElapsed()
             *  @param STEP_CODE_DATA_STRUCT & i_sdc
             *  @return TRUE if the interval time has elapsed.
             */
            bool isIntervalElapsed( STEP_CODE_DATA_STRUCT & i_sdc );

            /** @fn flushTable
             *  Clear all CE hits from the table and reset timer to 0.
             */
            void flushTable();

      private:

        ThresholdResolution::ThresholdPolicy iv_thPolicy;
        PrdfCacheAddressTable cv_ceTable;
        Timer cv_flushTimer;
        bool cv_flushTimerInited;

    };

};

} // end namespace PRDF

#endif

