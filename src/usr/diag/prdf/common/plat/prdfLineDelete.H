/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfLineDelete.H $              */
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

/** @namespace PrdfLineDelete
 *  Namespace to encapsulate all of the LineDelete specific classes and enums.
 */
namespace PrdfLineDelete
{

    /** @enum PrdfCacheType
     *  Used to express where a cache error occured.
     */
    enum PrdfCacheType
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

    /** @enum PrdfCacheErrorType
     *  Used to express the types of cache errors that can occur.
     */
    enum PrdfCacheErrorType
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
     *  per address before signalling "at threshold".  (the 2nd occurance would
     *  be the at threshold).
     *
     *  @note This is now being used for eRepair as well as cache CEs.
     */
    class PrdfCacheCETable
    {
      public:

        /**
         * @brief Constructor from ThresholdPolicy struct.
         * @param i_thPolicy A pointer to a ThresholdPolicy struct.
         */
        explicit PrdfCacheCETable(
                    const ThresholdResolution::ThresholdPolicy & i_thPolicy ) :
            iv_thPolicy(i_thPolicy), cv_flushTimerInited(false), cv_total(0)
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

            /** @fn getTotalCount
             *  Returns the total amount of CE hits in a table
             *
             *  @return uint32_t - the total CE hits in a table
             */
            uint32_t getTotalCount();        //zs01

            /** @fn addToCaptureData
             *  Adds CE table to the capture data.
             *
             *        @param The chip Handle.
             *        @param The scom id.
                *  @param The Service Data Collector.
             */
            void addToCaptureData(TARGETING::TargetHandle_t i_pchipHandle, int32_t, CaptureData &); // zs02

            /** @fn getLargestEntry
             *  @brief Will search the PrdfCacheCETable for the address with the
             *         largest count.
             *  @param The count of the highest entry (default = NULL).
             *  @return Address with the largest count.
             */
            PrdfCacheAddress getLargestEntry( uint32_t * o_count = NULL );

            /** @fn PrdfCacheCETable::getTableSize
             *  @return uint32_t - The total number of entries in the table
             */
            uint32_t getTableSize(); //zs04

             //mp26 a
            /** @fn getCRCAnalysisEntries
             *  @brief Will search the PrdfCacheCETable for the different count
             *         values..
             *  @param Output the highest count..
             *  @param Output the second highest count..
             *  @param Output the lowest count..
             *  @return Address with the largest count.
             */
            PrdfCacheAddress getCRCAnalysisEntries(
                                             uint32_t & o_countHigh,
                                             uint32_t & o_count2ndHigh,
                                             uint32_t & o_countLow);

      private:

        const ThresholdResolution::ThresholdPolicy  iv_thPolicy;
        PrdfCacheAddressTable cv_ceTable;
        PrdTimer cv_flushTimer;
        bool cv_flushTimerInited;
        uint32_t cv_total;        //zs01

    };

};
#endif

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- -------------------------------
//       F522128  f300 09/22/05 iawillia Initial File Creation
//  zs01 F565934  f310 09/06/06 zshelle         Adding getTotalCount()
//  zs02 d573288  f310 10/05/06 zshelle         Adding addToCaptureData()
//  zs03 588751   f310 03/12/07 zshelle  Adding getLargestEntry()
//  zs04 633659   f340 04/11/08 zshelle  Add getEntryCount() and getTableSize()
//  mp26 F750906  f720          plute    Add getCRCAnalysisEntries
//
// End Change Log *****************************************************
