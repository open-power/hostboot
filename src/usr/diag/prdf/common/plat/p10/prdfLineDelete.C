/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfLineDelete.C $          */
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

/** @file prdfLineDelete.C
 * Contains the definitions needed for the line delete algorithms and the CE
 * table.
 */


#include <prdfLineDelete.H>
#include <iipServiceDataCollector.h>
#include <prdfBitString.H>

namespace PRDF
{

// See prdfLineDelete.H for full function documentation.
namespace LineDelete
{

    /* PrdfCacheCETable::addAddress
     * Insert address into CE table.
     */
    bool PrdfCacheCETable::addAddress( PrdfCacheAddress i_addr,
                                       STEP_CODE_DATA_STRUCT & i_sdc )
    {
        // Get the time of the current error.
        Timer timeOfError = i_sdc.service_data->GetTOE();

        // Check if time interval has elapsed. If so, flush the table.
        if ( (timeOfError > cv_flushTimer) || !cv_flushTimerInited )
        {
            this->flushTable();
            cv_flushTimer = timeOfError + iv_thPolicy.interval;
            cv_flushTimerInited = true;
        }

        // Increment address hit count.
        uint32_t count = ++cv_ceTable[i_addr];

        // Return whether the address threshold has been reached or not.
        return ( iv_thPolicy.threshold <= count );
    }

    /* PrdfCacheCETable::isIntervalElapsed()
     */
    bool PrdfCacheCETable::isIntervalElapsed( STEP_CODE_DATA_STRUCT & i_sdc )
    {
        bool o_rc = false;
        if ( cv_flushTimerInited )
            o_rc = ( i_sdc.service_data->GetTOE() > cv_flushTimer );
        return o_rc;
    }

    /* PrdfCacheCETable::flushTable()
     * Clear all entries from CE table.
     */
    void PrdfCacheCETable::flushTable()
    {
        // wipe interval timer and clear all hits.
        cv_flushTimerInited = false;
        cv_ceTable.clear();
    }

};

} // end namespace PRDF

