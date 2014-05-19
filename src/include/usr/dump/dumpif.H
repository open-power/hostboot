/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/dump/dumpif.H $                               */
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
#ifndef __DUMPIF_H
#define __DUMPIF_H

/** @file  dumpif.H
 *  @brief Provides the external interfaces for dump.
 *            - copy dump data from src to destination
 *            - Send Mbox Msg for dump status
 */

namespace DUMP
{


    /**
     * @brief DUMP Message Types 
     */

    enum DUMP_MSG_TYPE
    {
        DUMP_MSG_START_MSG_TYPE = 0x000000B1,
        DUMP_MSG_END_MSG_TYPE = 0x000000B2,
        DUMP_MSG_ERROR_MSG_TYPE = 0x000000B3,

    };

    // The following are #defines  needed for Dump Testing.. These are the
    // default memory locations for MDST, MDDT, MDRT when running withoutPHYPab
    // The data range is defined in vmmconst.h so this test space is saved.

    /* Chunk of physical memory used for Dump Source Table */
    #define DUMP_TEST_SRC_MEM_ADDR  DUMP_TEST_MEMORY_ADDR
    #define DUMP_TEST_SRC_MEM_SIZE  MEGABYTE

    /* Chunk of physical memory used for Dump Destination Table */
    #define DUMP_TEST_DST_MEM_ADDR (DUMP_TEST_SRC_MEM_ADDR +  \
    DUMP_TEST_SRC_MEM_SIZE)


    #define DUMP_TEST_DST_MEM_SIZE  MEGABYTE

    /* Chunk of physical memory used for Dump Results Table */
    #define DUMP_TEST_RESULTS_MEM_ADDR (DUMP_TEST_DST_MEM_ADDR + \
    DUMP_TEST_DST_MEM_SIZE)


    #define DUMP_TEST_RESULTS_MEM_SIZE   MEGABYTE

    // Data location where the src, destination tables point to. (The actual
    // data)
    #define DUMP_TEST_SRC_DATA_AREA (DUMP_TEST_RESULTS_MEM_ADDR +   \
    DUMP_TEST_RESULTS_MEM_SIZE)


    #define DUMP_TEST_DST_DATA_AREA (DUMP_TEST_SRC_DATA_AREA + \
    DUMP_TEST_DATA_SIZE)

    #define DUMP_TEST_DATA_SIZE           MEGABYTE

    // default enums to point out the start and end of the DUMP Tables in memory
    #define DUMP_TEST_TABLE_START DUMP_TEST_SRC_MEM_ADDR
    #define DUMP_TEST_TABLE_SIZE (DUMP_TEST_SRC_MEM_SIZE +   \
    DUMP_TEST_DST_MEM_SIZE + DUMP_TEST_RESULTS_MEM_SIZE)

       
    #define DUMP_TEST_TABLE_END (DUMP_TEST_TABLE_START + DUMP_TEST_TABLE_SIZE)

    // In addition to the dump table locations we have scratch data area that is
    // used to put the SRC data that the MDST will point to.

    // This is the size of all the Data used for Dump testing
    #define DUMP_TEST_ALL_SIZE  (DUMP_TEST_TABLE_SIZE + (2*MEGABYTE))

    // This is the ending address of test Data area
    #define DUMP_TEST_ALL_END  (DUMP_TEST_TABLE_START + DUMP_TEST_ALL_SIZE)


    //These structures are defined in the HDAT spec
    //The MDST and MDDT have this format.
    struct dumpEntry
    {
        uint64_t dataAddr;
        uint32_t reserved;
        uint32_t dataSize;
    } PACKED;

    //The MDRT has this format.
    struct resultsEntry
    {
        uint64_t srcAddr;
        uint64_t destAddr;
        uint64_t dataSize;
        uint64_t reserved;
    } PACKED;


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
                              resultsEntry *resultsTableEntry,
                              uint64_t resultsTableSize);

    /**
     * @brief This function handles sending the mailbox message to the Fsp to
     *      notify of Dump Status.  Start, error or complete.  If Error or
     *      complete types are requested, the dump results table is passed
     *      to the FSP.
     *
     * @param[in] i_type - The type of DUMP msg being written.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
     *      log.
     */
    errlHndl_t sendMboxMsg (DUMP_MSG_TYPE i_type);



} // end of namespace


#endif
