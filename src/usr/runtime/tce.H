/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/tce.H $                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef __TCE_H
#define __TCE_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <devicefw/userif.H>




struct TceEntry
{
    // TCE Table
    union
    {
        uint64_t WholeTceEntry;
        struct {
            uint64_t realPageNumber    :52;   // real page number
            uint64_t valid             :1;    // The tces is valid for IO
            uint64_t reserved          :9;    // reserved bits
            uint64_t writeAccess       :1;    // Write access allowed
            uint64_t readAccess        :1;    // Read access allowed
        };

    };
};


/** @class TceMgr
 *  @brief   Responsible for managing the TCE entries
 *
 */
    class TceMgr
    {

      private:
        /** Indicator of TCEs being intialized */
        int tceEntryInit;

        /** Pointer to the Mapped TCE Table */
        TceEntry *tceTableVaPtr;
        /** physical address of the TCE Table */
        uint64_t tceTablePhysAddr;

        //** Max number of TCE entries - via size*/
        uint64_t maxTceEntries;

        /** size of the Tce Table */
        uint64_t tceTableSize;


        /**
         * @brief Responsible for mapping the TCE Table
         *
         * @return errlHndl_t - Return error log if unsuccessful
         *
         */
        errlHndl_t mapTceTable(void);

      public:
        /**
         * @brief Constructor.  Initializes instance variables.
         * @param[in/default] i_tableAddr - Starting address of the TCE
         *         table.. Default address is TCE_TABLE_ADDR. This was added
         *         for testing TCE entries and not using the "real" table
         * @param[in/default] i_tableSize - Size of the TCE table. Default value
         *         is TCE_TABLE_SIZE
         */
        TceMgr(uint64_t i_tableAddr = TCE_TABLE_ADDR,
                uint64_t i_tableSize = TCE_TABLE_SIZE);

        /**
         * Destructor.
         * No action necessary.
         */
        ~TceMgr();

        /** Max TCE Entries for the TCE Table */
        enum
        {
            NUM_TCE_TABLE_ENTRIES   = 0x80000,       // 512k entries
        };

        enum
        {
            INVALID_TOKEN_ENTRY   = 0xFFFFFFFFFFFFFFFF,
        };



        /**
         * @brief Responsible for initalizing the TCE Table and mapping the
         *         TCEtable
         *
         * @return errlHndl_t - Return error log if unsuccessful
         *
         */
        errlHndl_t createTceTable();


        /**
         * @brief Responsible for setting up the Processors to point to the TCE
         *         table
         *
         * @return errlHndl_t - Return error log if unsuccessful
         *
         */
        errlHndl_t initTceInHdw();


        /**
         * @brief Responsible for allocating TCE Entries
         *
         * @param[in] i_startingAddress - Starting address to TCE
         * @param[in] i_size - Size of the address space
         * @param[out] startingToken - Starting Entry into the table.
         *          (this is an offset into the array based on the
         *           TCE index * PAGESIZE.  Each TCE entry maps to a
         *           pagesize of memory)
         *
         * @return errl - Return Error Handle if failed.
         *
         */
        errlHndl_t allocateTces(uint64_t i_startingAddress,
                                  uint64_t i_size,
                                  uint64_t& o_startingToken);

        /**
         * @brief Responsible for deallocating TCE Entries
         *
         * @param[in] i_startingToken - Token indicating the starting entry to
         *                              remove
         * @param[in] i_size - Size of memory space to remove TCE entries
         *                     associated
         *
         * @return errl - Return Error Handle if fatal failure occurred.
         *
         */
        errlHndl_t deallocateTces(uint64_t i_startingToken,
                                    uint64_t i_size);


    };

#endif

