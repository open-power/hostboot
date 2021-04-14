/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/spnorrp.H $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#ifndef __PNOR_SPNORRP_H
#define __PNOR_SPNORRP_H
#include <pnor/pnorif.H>
#include <sys/msg.h>
#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <vmmconst.h>
#include <map>
#include "pnor_common.H"
#include "ffs.h"
#include <securerom/ROM.H>

namespace SECUREBOOT
{
    class ContainerHeader;
}

/**
 * Secure PNOR Resource Provider
 */

class SPnorRP
{
  public:
   /**
     * @brief Static Initializer
     * @param[in]  ref to errlHndl_t
     */
    static void init( errlHndl_t &io_rtaskRetErrl );

   /**
     * @brief  Returns true if the initial startup failed for some reason
     * @param[out]  Return code
     * @return  true if startup failed
     */
    bool didStartupFail( uint64_t& o_rc ) const
    {
        if( iv_startupRC )
        {
            o_rc = iv_startupRC;
            return true;
        }
        return false;
    };

    /**
     * @brief Perform mm_alloc_block operations in order to allocate
     *        virtual memory blocks that SPnorRP will use. This function
     *        is only required when using pnor_pldmdd as our pnor device
     *        driver.
     * @param[in]  i_TOC Pointer to an array of SectionData_t. PnorRP
     *                   should be passing its populated iv_TOC instance
     *                   variable to this function
     * @return Returns a pointer to this SPnorRP instance
     *
     * @note Any errors that occur will be committed within this function
     */
    SPnorRP* setupVmm(const PNOR::SectionData_t * const i_TOC);


  protected:
    /**
     * @brief  Constructor, default TOC offsets to side A
     */
    SPnorRP();

    /**
     * @brief  Destructor
     */
    ~SPnorRP();

  private:

    enum
    {
        SBASE_VADDR = VMM_VADDR_SPNOR_RP, /**< 8GB = 0x200000000*/
        TEMP_VADDR = VMM_VADDR_SPNOR_TEMP, /**< 5GB = 0x140000000 */
        LAST_VADDR = SBASE_VADDR + PNOR::PNOR_SIZE,  /**< End of our VA range */
    };

    /* bitwise enumeration to keep track of verified sections */
    enum
    {
        HBI_SECTION = 0x1,
    };

    /**
     * Pointer to the message queue where we receive messages for
     * secure space.
     */
    msg_q_t iv_msgQ;

    /**
     * Remember that we failed during initial startup
     *   This is set by startup methods to indicate to constructor that
     *   something went wrong
     */
    uint64_t iv_startupRC;

    /**
     * Keep track of secured payload size and secure section addresses
     */
    struct LoadRecord{
        uint8_t* secAddr; // virtual address of the start of the record
        uint64_t hashTableVaddr; // virtual address of the hash table (if it exists)
        size_t textSize; // size of the protected payload, not including header
        size_t infoSize; // size of the entire partition
        size_t refCount;
        bool hasHashTable; // indicates if the record has a hash table

        SHA512_t payloadTextHash;
        LoadRecord()
        :secAddr(nullptr), hashTableVaddr(0), textSize(0), infoSize(0), refCount(0), hasHashTable(false)
        {
            memset(&payloadTextHash[0], 0, SHA512_DIGEST_LENGTH);
        }
    };
    std::map<PNOR::SectionId, LoadRecord*> iv_loadedSections;


    /**
     * @brief Initialize the daemon, called by constructor
     */
    void initDaemon();

    /**
     * @brief Load secure sections into temporary address space and verify them
     * @note The Load record is not only used for output of the section info
     *       from the verifySections, but is also used as input via the
     *       payloadTextHash field, which is used (if i_loadedPreviously is
     *       true) to help determine if the PCR extend should be recalculated.
     *
     * @param[in]     i_secId - PNOR section id to verify
     * @param[in]     i_loadedPreviously - indicates section has been securely
     *                loaded previously
     * @param[in/out] io_rec - Load record to store section information in
     *                io_rec->payloadTextHash is used for comparision if
     *                i_loadedPreviusly is true.
     * @param[out]    o_plid - On function failure (return code is non-zero),
     *                PLID of the related error that was committed internally,
     *                otherwise 0.
     * @return  uint64_t - Return code to pass back to message handler.  If a
     *                     non-0 return code is returned, that implies the
     *                     function also committed an error and returned a non-0
     *                     PLID in o_plid
     */
    uint64_t verifySections(PNOR::SectionId i_id,
                            bool i_loadedPreviously,
                            LoadRecord* io_rec,
                            uint32_t& o_plid);

    /**
     * @brief  Message receiver for secure space
     */
    void waitForMessage();

    // disable copy ctor
    SPnorRP(const SPnorRP&);

    // disable assignment operator
    SPnorRP& operator=(const SPnorRP&);

    // allow local helper function to call private methods
    friend void* secure_wait_for_message( void* unused );

    /**
     * @brief  A wrapper for mm_alloc_block that encapsulates error log
     *         creation.
     */
    errlHndl_t allocBlock(msg_q_t mq, void* va, uint64_t size) const;

    /**
     * @brief  A wrapper for mm_set_permission that encapsulates error log
     *         creation.
     */
    errlHndl_t setPermission(void* va, uint64_t size,
                                       uint64_t accessType) const;

    /**
     * @brief  A wrapper for mm_remove_pages that encapsulates an error log
     * @note   This is a special case of mm_remove_pages that makes use of
     *         PAGE_REMOVAL_OPS "RELEASE" setting
     *
     * @param[in] i_va - virtual start address of pages to be removed
     * @param[in] i_size - size of block to remove
     */
    errlHndl_t removePages(void* i_va, uint64_t i_size) const;

    /**
     * @brief  Handles any additional section specific verification checks.
     * @param[in]  i_vaddr - vaddr of PNOR section to verify. Includes header
     *                       NULL will assert
     * @param[in]  i_secId - PNOR section id to verify
     * @return  errlHndl_t - NULL if success, errlHndl_t otherwise.
     */
    errlHndl_t miscSectionVerification(const uint8_t *i_vaddr,
                                       PNOR::SectionId i_secId) const;

    /**
     * @brief  Check if HBB and HBI were part of the same build
     *         Calculate HBB sw signatures hash and compare that to the build
     *         time hash of HBB sw signatures. The build time HBB hash is stored
     *         in the first entry (SALT) of HBI's hash page table.
     * @param[in]  i_vaddr - vaddr points to start of hash page table of HBI
     *                       NOTE: Since this expects the vaddr to point to the
     *                       start of the hash page table, the secureboot header
     *                       must be skipped prior by the caller.
     *                       NULL will assert
     * @return  errlHndl_t - NULL if success, errlHndl_t otherwise.
     */
    errlHndl_t baseExtVersCheck(const uint8_t *i_vaddr) const;

    /**
     * @brief  Check if SBKT is properly formatted to then provide the new HW
     *         key hash to transition the system to.
     * @param[in]  i_vaddr - vaddr points to start of the SBKT container
     *                       NULL will assert
     * @return  errlHndl_t - NULL if success, errlHndl_t otherwise.
     */
    errlHndl_t keyTransitionCheck(const uint8_t *i_vaddr) const;

    /**
     *  @brief Apply firmware key indicator policies for the given section
     *
     *  @par Detailed Description:
     *      Reads the HW/SW policy flags from the given section's container
     *      header and applies any applicable policies.
     *
     *  @param[in] i_header Reference to requested section's container header
     *  @param[in] i_sectionId Section's ID
     *
     *  @return errlHndl_t Error log handle; nullptr if success, pointer to
     *      valid error log otherwise.
     */
    errlHndl_t processFwKeyIndicators(
        const SECUREBOOT::ContainerHeader& i_header,
        const PNOR::SectionId              i_sectionId) const;

};
#endif
