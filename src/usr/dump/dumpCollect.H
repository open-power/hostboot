/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/dump/dumpCollect.H $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
#ifndef __DUMPCOLLECT_H
#define __DUMPCOLLECT_H

#include <errl/errlentry.H>

/** @file  dumpCollect.H
 *  @brief Provides the interfaces to copy dump data from src to destination
 */

namespace DUMP
{

    //These structures are defined in the HDAT spec
    //The MDST and MDDT have this format.
    struct dumpEntry
    {
        uint64_t dataAddr;
        uint64_t dataSize;
    };

    
    //The MDRT has this format.
    struct resultsEntry
    {
        uint64_t srcAddr;
        uint64_t destAddr;
        uint64_t dataSize;
    };


    /**
     * @brief This function is a wrapper function that calls
     *   getHostDataPtrs to get the MDDT, MDST, MDRT pointers
     *   and then passes those values to the copySrcToDest
     *   routine that performs the copy
     *
     * @param[in]   void
     *
     * @return  errlHndl_t
     */                    
     errlHndl_t doDumpCollect(void);

     /**
      * @brief This function copies the data and sizes retrieved from the
      * MDST(source table) to the addresses indicated by the MDDT(destination
      * table).   Each write is then logged in the MDRT (results table) with
      * source addr, destination addr and size
      *
      * @param[in]   srcTableEntry     Ptr to the first MDST entry                           
      * @param[in]   srcTableSize      Size of the entire MDST
      *
      * @param[in]   destTableAddr     Ptr to the first MDDT entry                     
      * @param[in]   destTableSize     Size of the entire MDDT
      *
      * @param[in]   resultsTableAddr  Ptr to the first MDRT entry                           
      * @param[in]   resultsTableSize  Size of the entire MDRT
      *
      * @return  errlHndl_t
      */
     errlHndl_t copySrcToDest(dumpEntry *srcTableEntry, uint64_t srcTableSize,
                              dumpEntry *destTableEntry, uint64_t destTableSize,
                              resultsEntry *resultsTableEntry, uint64_t resultsTableSize);

     /**
      * @brief This routine retrieves first entry of the MDST, MDDT and
      *      MDRT and the size of each of those tables.
      *
      * @param[out]   srcTableEntry     Ptr to the first MDST entry                           
      * @param[out]   srcTableSize      Size of the entire MDST
      *
      * @param[out]   destTableAddr     Ptr to the first MDDT entry                     
      * @param[out]   destTableSize     Size of the entire MDDT
      *
      * @param[out]   resultsTableAddr  Ptr to the first MDRT entry                           
      * @param[out]   resultsTableSize  Size of the entire MDRT

      * @return  errlHndl_t
      */
     errlHndl_t getHostDataPtrs(dumpEntry *srcTableEntry, uint64_t &srcTableSize,
                                dumpEntry *destTableEntry, uint64_t &destTableSize,
                                resultsEntry *resultsTableEntry,uint64_t &resultsTableSize);


}


#endif
