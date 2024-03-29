/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utiltcemgr.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#ifndef __UTILTCEMGR_H
#define __UTILTCEMGR_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <intr/interrupt.H>
#include <sys/misc.h>
#include <map>

// Forward declarations
class TCETest;

namespace TCE
{

struct TceEntry_t
{
    // Derived from "15.9.6 TCE - Translation Control Entry" of the
    // P9 Pervasive Workbook
    union
    {
        uint64_t WholeTceEntry;
        struct {
            uint64_t reserved_0        :8;    // first 8 bits reserved
            uint64_t realPageNumber    :44;   // real page number
            uint64_t reserved_1        :10;   // reserved bits
            uint64_t writeAccess       :1;    // Write access allowed
            uint64_t readAccess        :1;    // Read access allowed
        };

    };

    // Constructor to default to zero
    TceEntry_t() :
        WholeTceEntry(0x0) {};

};

struct TarTceAddrRegister_t
{
    // Derived from "15.9.6 TCE - Translation Control Entry" of the
    // P9 Pervasive Workbook
    union
    {
        uint64_t WholeTAR;
        struct {
            uint64_t reserved_0        :8;    // first 8 bits reserved
            uint64_t tceTableStartAddr :34;   // real page number
            uint64_t reserved_1        :6;    // reserved since 512k entries
            uint64_t reserved_2        :13;   // reserved
            uint64_t tceEntries        :3;    // TCE Entries
        };
    };

    // Constructor to default to zero
    TarTceAddrRegister_t() :
        WholeTAR(0x0) {};

};

struct TceEntryInfo_t
{
    uint64_t start_addr;
    size_t size;

    // Constructor to default to zero
    TceEntryInfo_t() :
        start_addr(0x0), size(0) {};
};


/** @class UtilTceMgr
 *  @brief   Responsible for managing the TCE entries
 *
 */
class UtilTceMgr
{

  private:
    /** Indicator of TCEs being intialized */
    bool iv_isTceHwInitDone;

    /** Indicator of TCE Table being allocated and initialized in memory */
    bool iv_isTceTableInitDone;

    /** Virtual Address of the Mapped TCE Table */
    uint64_t iv_tceTableVaAddr;

    /** Physical Address of the TCE Table */
    uint64_t iv_tceTablePhysAddr;

    /** Number of TCE entries - via size */
    size_t iv_tceEntryCount;

    /** size of the Tce Table */
    size_t iv_tceTableSize;

    /** Tokens for PAYLOAD and HDAT entries in the TCE Table */
    uint32_t iv_payloadToken;
    uint32_t iv_hdatToken;

    /* Cache of starting addresses of allocated TCEs and their
     *  tokens ((starting entry in the TCE Table) * PAGESIZE) and size
     * Indexed by token - the position of the first entry of the TCE Table
     * Returns the starting address and size of the memory allocated by the
     *  entries in the TCE Table
     */
    std::map<uint32_t, TceEntryInfo_t> iv_allocatedAddrs;

    /* For Debug purposes */
    void printIvMap() const;


    /** Max TCE Entries and Size for the TCE Table. */
    /** And Max amount of Memory The TCEs can cover. */
    enum
    {
        MAX_NUM_TCE_TABLE_ENTRIES   = 0x080000, // 512k entries - HW Max
        MAX_TCE_TABLE_SIZE          = 0x400000, // 512k * 8 bytes/entry
        MAX_TCE_MEMORY_SPACE        = MAX_NUM_TCE_TABLE_ENTRIES * PAGESIZE,
    };

    /** Values related to PSIHB_SW_INTERFACES_t registers */
    enum
    {
        TAR_TCE_ENTRIES_512K = 0b100,  // TAR bits 61:63=0b100 for 512K entries
        PHBSECURE_TCE_ENABLE = 0x2000000000000000,
    };

    /** Values related to tokens */
    enum tokenValues : uint32_t
    {
        INVALID_TOKEN_VALUE = 0xFFFFFFFF,
    };

    /**
     * @brief Responsible for initalizing the TCE Table and mapping the
     *         TCE Table into memory
     *
     * @return errlHndl_t - Return error log if unsuccessful
     *
     */
    errlHndl_t createTceTable();

    /**
     * @brief Responsible for setting up the Processors to point to the TCE
     *         Table
     *
     * @return errlHndl_t - Return error log if unsuccessful
     *
     */
    errlHndl_t initTceInHdw();

    /**
     * @brief Helper function to Memory Map PSI Host Bridge
     *
     * @param[in]  i_tgt       Pointer to Processor Target that is associated
     *                         with a specific PSI Host Bridge Memory Map.
     *                         Assert if NULL or not a Processor Target
     *
     * @param[out] o_psihb_ptr  If successful, pointer to memory mapped
     *                         location of PSI Host Bridge;
     *                         otherwise, NULL
     *
     * @return errlHndl_t - Return error log if unsuccessful
     *
     */
    errlHndl_t mapPsiHostBridge(const TARGETING::Target* i_tgt,
                                void *& o_psihb_ptr) const;


    /**
     * @brief Helper function to Unmap PSI Host Bridge from Memory
     *
     * @param[in] i_psihb_ptr  Pointer to memory mapped location of
     *                         PSI Host Bridge
     *
     * @return errlHndl_t - Return error log if unsuccessful
     *
     */
    errlHndl_t unmapPsiHostBridge(void *& i_psihb_ptr) const;


    /* let the testcase poke around */
    friend class ::TCETest;


  public:
    /**
     * @brief Constructor.  Initializes instance variables.
     * @param[in/default] i_tableAddr - Starting physical address of the TCE
     *          Table. Default address is TCE_TABLE_ADDR.
     *          Address must be aligned on a 4MB boundary or will fail.
     * @param[in/default] i_tableSize - Size of the TCE table. Default value
     *         is TCE_TABLE_SIZE
     *
     * @note  TCE_TABLE_ADDR and TCE_TABLE_SIZE are defined in vmmconst.h
     */
    UtilTceMgr(uint64_t i_tableAddr = cpu_spr_value(CPU_SPR_HRMOR) +
                                      TCE_TABLE_ADDR,
               size_t   i_tableSize = TCE_TABLE_SIZE);

    /**
     * Destructor.
     */
    ~UtilTceMgr();

    /**
     * Delete Copy Constructor
     */
    UtilTceMgr(const UtilTceMgr&) = delete;

    /**
     * Delete Copy Assignment
     */
    UtilTceMgr& operator= (const UtilTceMgr&) = delete;

    /**
     * Delete Move Constructor
     */
    UtilTceMgr (UtilTceMgr&&) = delete;

    /**
     * Delete Move Assignment
     */
    UtilTceMgr& operator = (UtilTceMgr&&) = delete;


    /**
     * @brief Responsible for allocating TCEs
     *
     * - see utiltce.H for details
     *
     */
    errlHndl_t allocateTces(uint64_t   i_startingAddress,
                            size_t     i_size,
                            uint32_t&  o_startingToken,
                            const bool i_rwNotRO);

    /**
     * @brief Responsible for deallocating TCEs
     *
     * - see utiltce.H for details
     *
     */
    errlHndl_t deallocateTces(uint32_t i_startingToken);

    /**
     * @brief Responsible for disabling TCEs on the system, including
     *        clearing the TCE table and disabling Processor settings
     *
     * - see utiltce.H for details
     *
     */
    errlHndl_t disableTces(void);

    /** Values related to tokens */
    enum tokenLabels
    {
        PAYLOAD_TOKEN = 0x0,
        HDAT_TOKEN    = 0x1,
    };

    /**
     * @brief Returns one of two internally stored tokens
     *
     * @param[in] i_tokenLabel - Specifies which token to return
     *                           Assert if neither PAYLOAD_TOKEN nor
     *                           HDAT_TOKEN
     *
     * @return uint32_t - Return specified token
     *
     */
    uint32_t getToken(tokenLabels i_tokenLabel);

    /**
     * @brief Sets one of two internally stored tokens
     *
     * @param[in] i_tokenLabel - Specifies which token to set
     *                           Assert if neither PAYLOAD_TOKEN nor
     *                           HDAT_TOKEN
     *
     * @param[in] i_tokenValue - Value to be set
     *
     * @return uint32_t - Set specified token
     *
     */
    void setToken(tokenLabels i_tokenLabel,
                  uint32_t i_tokenValue);


}; // class UtilTceMgr

    /**
     * @brief Returns a copy of the UtilTceMgr Singleton
     *
     * @return Returns a copy of Singleton<UtilTceMgr>::instance()
     */
    UtilTceMgr&  getTceManager(void);

}; // namespace

#endif

