/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/dump/dumpCollect.H $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#include <dump/dumpif.H>
/** @file  dumpCollect.H
 *  @brief Provides the interfaces to get the host data pointers for the
 *        dump tables.
 */

namespace DUMP
{
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
     errlHndl_t getHostDataPtrs(dumpEntry *&srcTableEntry,
                                uint64_t &srcTableSize,
                                dumpEntry *&destTableEntry,
                                uint64_t &destTableSize,
                                resultsEntry *&resultsTableEntry,
                                uint64_t &resultsTableSize);


}; // end of namespace


#endif
