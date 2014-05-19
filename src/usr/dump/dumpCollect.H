/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/dump/dumpCollect.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
