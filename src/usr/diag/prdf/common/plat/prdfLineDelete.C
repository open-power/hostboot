/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfLineDelete.C $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2012              */
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

/** @file prdfLineDelete.C
 * Contains the definitions needed for the line delete algorithms and the CE
 * table.
 */


#include <prdfLineDelete.H>
#include <iipServiceDataCollector.h>
#include <prdfBitString.H>

// See prdfLineDelete.H for full function documentation.
namespace PrdfLineDelete
{

    /* PrdfCacheCETable::addAddress
     * Insert address into CE table.
     */
    bool PrdfCacheCETable::addAddress( PrdfCacheAddress i_addr,
                                       STEP_CODE_DATA_STRUCT & i_sdc )
    {
        // Get the time of the current error.
        PrdTimer timeOfError = i_sdc.service_data->GetTOE();

        // Check if time interval has elapsed. If so, flush the table.
        if ( (timeOfError > cv_flushTimer) || !cv_flushTimerInited )
        {
            this->flushTable();
            cv_flushTimer = timeOfError + iv_thPolicy.interval;
            cv_flushTimerInited = true;
        }

        // Increment address hit count and total table count.
        uint32_t count = ++cv_ceTable[i_addr];
        cv_total++;

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
        cv_total = 0;
    }

    /* PrdfCacheCETable::getTotalCount()
     * Clear all CE hits from the table and reset timer to 0.
     */
    uint32_t PrdfCacheCETable::getTotalCount() // zs01
    {
        return cv_total;
    }

    /* PrdfCacheCETable::addToCaptureData()
     * Will add CE table to the capture data.
     */
    void PrdfCacheCETable::addToCaptureData(TARGETING::TargetHandle_t i_pchipHandle, int32_t i_scomId,
                                            CaptureData & io_cd)  // zs02
    {
        const uint32_t l_maxEntries
                        = CaptureData::MAX_ENTRY_SIZE / (2 * sizeof(uint32_t));

        uint32_t l_entryTable[l_maxEntries * 2];
        uint32_t l_entryIndex = 0;

        // Loop on all entries in CE table.
        for (PrdfCacheAddressTable::iterator i = cv_ceTable.begin();
            i != cv_ceTable.end(); ++i)
        {
            // Add entry to table.
            l_entryTable[2 * l_entryIndex] = i.first();
            l_entryTable[2 * l_entryIndex + 1] = i.second();

            // Check if entry chunk is filled, or reached the end of entries.
            if ( ( l_maxEntries == (l_entryIndex + 1) ) ||
                 ( (i + 1) == cv_ceTable.end() ) )
            {
                // Add chunk to capture data.
                BIT_STRING_ADDRESS_CLASS l_entryChunk( 0,
                        ( ( (l_entryIndex + 1) * (2 * sizeof(uint32_t)) ) * 8 ),
                                  (CPU_WORD*) l_entryTable );
                io_cd.Add(i_pchipHandle, i_scomId, l_entryChunk);
            }

            // Increment entry ID.
            l_entryIndex = (l_entryIndex + 1) % l_maxEntries;
        }
    }

    /* PrdfCacheCETable::getLargestEntry
     * Will search the PrdfCacheCETable for the address with the largest count
     */
    PrdfCacheAddress PrdfCacheCETable::getLargestEntry( uint32_t * o_count )
    {
        PrdfCacheAddress largestEntry = 0;
        uint32_t highestCount = 0;

        // Loop on all entries in CE table.
        for (PrdfCacheAddressTable::iterator i = cv_ceTable.begin();
             i != cv_ceTable.end(); ++i)
        {
            if ( i.second() > highestCount )
            {
                largestEntry = i.first();
                highestCount = i.second();

                if (o_count != NULL)
                    (*o_count) = highestCount;
            }
        }

        return largestEntry;
    }

    /* PrdfCacheCETable::getTableSize
     */
    uint32_t PrdfCacheCETable::getTableSize() //zs04
    {
        return cv_ceTable.size();
    }

 //mp26 a
    /* PrdfCacheCETable::getCRCAnalysisEntries
     * Will search the PrdfCacheCETable for the address with the largest count
     * Also returns highest, second highest, and lowest count values
     */

    //NOTE: need to make sure table size is not zero before calling this function.
    PrdfCacheAddress PrdfCacheCETable::getCRCAnalysisEntries(
                                                             uint32_t & o_countHigh,
                                                             uint32_t & o_count2ndHigh,
                                                             uint32_t & o_countLow)
    {
        PrdfCacheAddress largestEntry = 0;

        do
        {

            PrdfCacheAddressTable::iterator i = cv_ceTable.begin();

            // Initialize the counts to the value of the first entry.
            largestEntry = i.first();
            o_countHigh = i.second();
            o_count2ndHigh = 0;
            o_countLow = 0;

            if ( 1 == getTableSize() ) break; // only one entry

              ++i; // There are at least two entries, start at the second.

              // Initialize 2nd highest count and low count.
              if ( i.second() > o_countHigh )
              {
                  o_count2ndHigh = o_countHigh;
                  o_countLow = o_countHigh;

                  largestEntry = i.first();
                  o_countHigh = i.second();
              }
              else
              {
                  o_count2ndHigh = i.second();
                  o_countLow = i.second();
              }

              // Loop on all entries in CE table.
                ++i; // Start at third entry.
                  // Note: loop will exit immediately if the table count is 2.
                      for ( ; i != cv_ceTable.end(); ++i )
                      {
                          // Get highest count.
                            if ( i.second() > o_countHigh )
                            {
                                o_count2ndHigh = o_countHigh;

                                largestEntry = i.first();
                                o_countHigh = i.second();
                            }
                          // Get second highest count.
                            else if ( (i.second() > o_count2ndHigh) &&
                                      (i.second() <= o_countHigh) )
                            {
                                o_count2ndHigh = i.second();
                            }
                          // Get lowest count.
                            else if ( i.second() < o_countLow )
                            {
                                o_countLow = i.second();
                            }
                      }

        } while (0);

        return largestEntry;
    }
};



// Change Log ******************************************************************
//
// Flag Reason  Vers Date     Coder    Description
// ---- ------- ---- -------- -------- -----------------------------------------
//      F522128 f300 09/22/05 iawillia Initial File Creation
// zs01 F565934 f310 09/06/06 zshelle  Adding getTotalCount()
// zs02 d573288 f310 10/05/06 zshelle  Adding addToCaptureData()
// zs03 588751  f310 03/12/07 zshelle  Adding getLargestEntry()
// zs04 633659  f340 04/11/08 zshelle  Add getEntryCount() and getTableSize()
// mp26 F750906 f720          plute    Add getCRCAnalysisEntries
//
// End Change Log **************************************************************
