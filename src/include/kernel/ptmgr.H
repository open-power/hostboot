/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/ptmgr.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
#ifndef __KERNEL_PTMGR_H
#define __KERNEL_PTMGR_H

#include <stdint.h>
#include <util/lockfree/stack.H>
#include <kernel/vmmmgr.H>

/**
 * @class PageTableManager
 * @brief Manages the Page Table in the hardware
 */
class PageTableManager
{
  public:
    // Public Constants

    /**
     * Status Values
     */
    enum
    {
        PTE_UNKNOWN         = 0x0000000000000000, /**< Entry wasn't found */
        PTE_PRESENT         = 0x0000000000000001, /**< Entry is present in table */
        PTE_VALID           = 0x0000000000000002, /**< Entry is valid */
        PTE_READ            = 0x0000000000000004, /**< Read permission */
        PTE_WRITABLE        = 0x0000000000000008, /**< Write permission */
        PTE_EXECUTE         = 0x0000000000000010, /**< Execute permission */
        PTE_CACHE_INHIBITED = 0x0000000000000020, /**< Cache-Inhibited Access */
        PTE_MODIFIED        = 0x0000000000000040, /**< Page has been modified */
        PTE_ACCESSED        = 0x0000000000000080, /**< Page has been accessed */
    };

    /**
     * Page Table Constants
     */
    enum
    {
        PT_SIZE = (1 << 18), /**< Size of Page Table in bytes */
        PTE_SIZE = /**< Size of 1 Page Table Entry in bytes */
            2*sizeof(uint64_t),
        PTEG_SIZE = 8, /**< Number of PTEs in a single PTE Group */
        PTEG_COUNT =  /**< Number of PTEGs in the Page Table */
            (PT_SIZE / PTE_SIZE) / PTEG_SIZE,
        INVALID_PN = /**< Error value for a Page Number return */
            0xFFFFFFFFFFFFFFFF,
    };

    /**
     * LRU Statistics
     */
    struct UsageStats_t {
	union {
	    struct {
		uint64_t C:1;    /**< Page has been modified  */
		uint64_t R:1;    /**< Page has been referenced  */
		uint64_t LRU:2;  /**< Current value of LRU  */
		uint64_t rsv:60; /**< Reserved space  */
	    };
	    uint64_t fullword;  /**< Full Dword0 */
	};
	UsageStats_t():fullword(0){};
    };

    /**
     * @brief Static Initializer
     */
    static void init();

    /**
     * @brief Add an entry to the hardware page table
     *
     * @param[in] i_vAddr  Virtual Address within the page to be mapped  (full address)
     * @param[in] i_page  Real physical page number to map to  (page number)
     * @param[in] i_accessType  Type of access page will be given
     */
    static void addEntry( uint64_t i_vAddr,
                          uint64_t i_page,
                          uint64_t i_accessType );

    /**
     * @brief Remove an entry from the hardware page table
     *
     * @param[in] i_vAddr  Virtual Address within the page to be removed  (full address)
     */
    static void delEntry( uint64_t i_vAddr );

    /**
     * @brief Remove a range of entries from the hardware page table
     *
     * @param[in] i_vAddrStart  Beginning of VA range to remove  (full address)
     * @param[in] i_vAddrFinish  End of VA range to remove  (full address)
     */
    static void delRangeVA( uint64_t i_vAddrStart,
                            uint64_t i_vAddrFinish );


    /**
     * @brief Remove a range of entries from the hardware page table
     *
     * @param[in] i_pnStart  First Physical Page to remove  (page number)
     * @param[in] i_pnFinish  Last Physical Page to remove  (page number)
     * @param[in] i_applyHRMOR  If true then the HRMOR is applied to the
     *                          page numbers, MMIOs should set to false
     */
    static void delRangePN( uint64_t i_pnStart,
                            uint64_t i_pnFinish,
                            bool i_applyHRMOR = true );

    /**
     * @brief Return status information about an entry in the hardware page table
     *
     * @param[in] i_vAddr  Virtual Address within the page to be queried  (full address)
     * @param[out] o_pn  Real physical page number va is mapped to,
     *                   INVALID_PN if PTE is invalid
     *
     * @return uint64_t  ORed combination of status flags
     */
    static uint64_t getStatus( uint64_t i_vAddr,
                               uint64_t& o_pn );

    /**
     * @brief  Print out the contents of a PTE to the printk buffer
     *
     * @param[in] i_label  string to display along with the PTE data
     * @param[in] i_pteAddr  address/pointer to the PTE to display
     * @param[in] i_verbose  true=break out all attributes, false=abbreviated output
     */
    static void printPTE( const char* i_label,
                          uint64_t i_pteAddr,
                          bool i_verbose = false );

    /**
     * @brief  Print out the contents of a PTE based on a VA
     *
     * @param[in] i_va  Virtual address that is part of the page the PTE points to
     * @param[in] i_verbose  true=break out all attributes, false=abbreviated output
     */
    static void printPTE( uint64_t i_va,
                          bool i_verbose = false );

    /**
     * @brief  Print out the entire Page Table
     */
    static void printPT( void );

    /**
     * @brief Flush reference status & unload unused pages
     */
    static void flush( void );


  protected:
    /**
     * @brief  Constructor
     *
     * @param[in] i_userSpace  true=declare a local page table for user-space testing
     */
    PageTableManager( bool i_userSpace = false );

    /**
     * @brief  Destructor
     */
    ~PageTableManager();

  private:
    /**
     * Local copy of Page Table for user-space testing
     *  (set to NULL for kernel instance)
     */
    char* ivTABLE;

    /**
     * Represents a single entry in the page table
     */
    struct PageTableEntry
    {
        /**
         * Dword0
         */
        union {
            struct {  /**< Dword0 Attributes */
                uint64_t rsv0:12; /**< 0:11  Reserved */
                uint64_t AVA:45;  /**< 12:56  Abbrev VA, VA w/o bottom bits */
                uint64_t SW:1;    /**< 57 =SW[0] - Reserved  */
                uint64_t R2:1;    /**< 58 =SW[1] - Shadow R bit  */
                uint64_t LRU:2;   /**< 59:60 =SW[2:3] Used for LRU algorithm */
                uint64_t L:1;     /**< 61    Virtual page size  */
                uint64_t H:1;     /**< 62    Hash function identifier  */
                uint64_t V:1;     /**< 63    Entry valid  */
            };
            uint64_t dword0;  /**< Full Dword0 */
        };

        /**
         * Dword1
         */
        union {
            struct {  /**< Dword1 Attributes */
                uint64_t pp0:1;    /**< 0     Page Protection bit 0  */
                uint64_t TS:1;     /**< 1     Tag Set bit  */
                uint64_t key0_1:2; /**< 2:3   KEY bits 0:1  <unused>  */
                uint64_t B:2;      /**< 4:5   Segment Size  */
                uint64_t rsv1:1;   /**< 6     Reserved */
                uint64_t PN:45;    /**< 7:51  Abbrev RPN + Large Page Size  */
                uint64_t key2_4:3; /**< 52:54 KEY bits 2:4  <unused>  */
                uint64_t R:1;      /**< 55    Reference bit  */
                uint64_t C:1;      /**< 56    Change bit  */
                uint64_t WIMG:4;   /**< 57:60 Storage control bits  */
                uint64_t N:1;      /**< 61    No-execute page (N==1)  */
                uint64_t pp1_2:2;  /**< 62:63 Page Protection bits 1:2  */
            };
            uint64_t dword1;  /**< Full Dword1 */
        };
    } PACKED;
    enum { PTE_AVA_MASK = 0x1FFFFFFFFFFF };

    /**
     * Internal Constants
     */
    enum {
        PTE_ACCESS_BITS = 0x800000000000007B,  /**< pp0 + WIMG + pp1_2  */
        PTEG_SIZE_BYTES = (sizeof(PageTableEntry)*8),  /**< Size of PTE Group in bytes */

    };

    /**
     * Relative address of idle task loop function
     */
    uint64_t ivIdleTaskFunction;

    /**
     * Physical page that contains the idle task loop function
     * - Because idleTaskLoop is part of the base image we know that
     *   the physical memory for it will remain resident at all times
     *   and never move.
     */
    uint64_t ivIdleTaskPN;

    /**
     * @brief  Return the hash value of the VA
     *
     * @param[in] i_vAddr  Virtual Address to hash
     *
     * @return uint64_t  hash value used by Page Table hardware
     */
    uint64_t computeHash( uint64_t i_vAddr );

    /**
     * @brief  Find the real address of the PTEG that matches the given VA
     *
     * @param[in] i_vAddr  Virtual Address to look up
     *
     * @return uint64_t  PTEG address
     */
    uint64_t findPTEG( uint64_t i_vAddr );

    /**
     * @brief  Find the PTE that matches the given VA
     *
     * @param[in] i_vAddr  Virtual Address to search for
     *
     * @return PageTableEntry*  Pointer to PTE, this is a real address
     */
    PageTableEntry* findPTE( uint64_t i_vAddr );

    /**
     * @brief  Find the real address of the PTE that matches the given address
     *
     * @param[in] i_vAddr  Virtual Address to search for
     * @param[in] i_ptegAddr  Real Address of PTEG that would own this PTE
     *
     * @return PageTableEntry*  Pointer to PTE, this is a real address
     */
    PageTableEntry* findPTE( uint64_t i_vAddr,
                             uint64_t i_ptegAddr );

    /**
     * @brief  Find the real address of a PTE that that is empty or invalid
     *
     * @param[in] i_ptegAddr  Real Address of PTEG that would own this PTE
     *
     * @return PageTableEntry*  Pointer to PTE slot, this is a real address
     */
    PageTableEntry* findEmptyPTE( uint64_t i_ptegAddr );

    /**
     * @brief  Find the real address of a PTE that can be invalidated
     *   and replaced
     *
     * @param[in] i_ptegAddr  Real Address of PTEG that would own this PTE
     *
     * @return PageTableEntry*  Pointer to PTE, this is a real address
     */
    PageTableEntry* findOldPTE( uint64_t i_ptegAddr );

    /**
     * @brief  Write a PTE to memory and update caches appropriately
     *
     * @note This function should only be used to change a PTE from valid to
     *       invalid or from invalid to valid, unless modifying the permissions
     *       on an existing PTE (without changing addresses).  Use in two
     *       stages otherwise.
     *
     * @param[in] i_pte  Local pointer to PTE data
     * @param[in] i_dest  Real Address inside page table to write i_pte data into
     * @param[in] i_valid  true=set Valid bit, false=clear Valid bit
     */
    void writePTE( PageTableEntry* i_pte,
                   PageTableEntry* i_dest,
                   bool i_valid );

    /**
     * @brief Add an entry to the hardware page table
     *
     * @param[in] i_vAddr  Virtual Address within the page to be mapped
     * @param[in] i_page  Real physical page number to map to
     * @param[in] i_accessType  Type of access page will be given
     */
    void _addEntry( uint64_t i_vAddr,
                    uint64_t i_page,
                    uint64_t i_accessType );

    /**
     * @brief Remove an entry from the hardware page table
     *
     * @param[in] i_vAddr  Virtual Address within the page to be removed
     */
    void _delEntry( uint64_t i_vAddr );

    /**
     * @brief Remove an entry from the hardware page table
     *
     * @param[in] i_pte  Pointer to real PTE in the page table
     */
    void delEntry( PageTableEntry* i_pte );

    /**
     * @brief Remove a range of entries from the hardware page table
     *
     * @param[in] i_vAddrStart  Beginning of VA range to remove
     * @param[in] i_vAddrFinish  End of VA range to remove
     */
    void _delRangeVA( uint64_t i_vAddrStart,
                      uint64_t i_vAddrFinish );

    /**
     * @brief Remove a range of entries from the hardware page table
     *
     * @param[in] i_pnStart  First Physical Page to remove
     * @param[in] i_pnFinish  Last Physical Page to remove
     */
    void _delRangePN( uint64_t i_pnStart,
                      uint64_t i_pnFinish );

    /**
     * @brief Return status information about an entry in the hardware page table
     *
     * @param[in] i_vAddr  Virtual Address within the page to be queried
     * @param[out] o_pn  Real physical page number to map to, INVALID_PN if PTE is invalid
     *
     * @return uint64_t  ORed combination of status flags
     */
    uint64_t _getStatus( uint64_t i_vAddr,
                         uint64_t& o_pn );

    /**
     * @brief Translate a PTE into the status bits
     *
     * @param[in] i_pte  Pointer to PTE, could be local memory or part of page table
     *
     * @return uint64_t  ORed combination of status flags
     */
    uint64_t getStatus( PageTableEntry* i_pte );

    /**
     * @brief Update the LRU statistics for other PTEs in the same PTEG as the
     *        target
     *
     * @param[in] i_newPTE  Real address of PTE that is being added to the
     *                      Page Table
     */
    void updateLRUGroup( const PageTableEntry* i_newPTE );

    /**
     * @brief Update the LRU statistics for a specific PTE.
     *
     * @param[in] i_newPTE  Real address of PTE to update.
     */
    void updateLRUEntry( PageTableEntry* i_newPTE );


    /**
     * @brief Invalidate TLB for a PTE
     *
     * @param[in] i_newPTE  Real address of PTE that is being modified
     */
    void invalidateTLB( PageTableEntry* i_pte );

    /**
     * @brief Invalidate all PTEs in the table
     */
    void invalidatePT( void );

    /**
     * @brief  Print out the contents of a PTE to the printk buffer
     *
     * @param[in] i_label  string to display along with the PTE data
     * @param[in] i_pteAddr  pointer to the PTE to display
     * @param[in] i_verbose  true=break out all attributes, false=abbreviated output
     */
    void printPTE( const char* i_label,
                   const PageTableEntry* i_pte,
                   bool i_verbose = false );

    /**
     * @brief  Print out the entire Page Table to the printk buffer
     */
    void _printPT( void );

    /**
     * @brief  Return the real address of the page table in memory
     * @return uint64_t  Page Table Address
     */
    uint64_t getAddress( void );

    /**
     * @brief  Return the size of the page table in memory in bytes
     * @return uint64_t  Size of Page Table in bytes
     */
    uint64_t getSize( void );

    /**
     * @brief  Set bits in PTE for the given ACCESS_TYPES
     *
     * @param[out] o_pte  PTE to modify
     * @param[in] i_accessType  Access parameter to apply to PTE
     */
    void setAccessBits( PageTableEntry* o_pte,
                          uint64_t i_accessType );

    /**
     * @brief  Convert the bits from a PTE into a ACCESS_TYPES
     *
     * @param[in] i_pte  PTE to examine
     *
     * @return uint64_t  Access parameters of given PTE
     */
    uint64_t getAccessType( const PageTableEntry* i_pte );

    /**
     * @brief  Calculate the original Virtual Address from a PTE
     *
     * @param[in] i_pte  PTE to examine, must be pointer to real entry in table
     *
     * @return uint64_t  page-aligned virtual address
     */
    uint64_t getVirtAddrFromPTE( const PageTableEntry* i_pte );

    /**
     * @brief  Fill in default values for the PTE
     *
     * @param[out] o_pte  PTE to modify
     */
    static void setupDefaultPTE( PageTableEntry* o_pte ) ALWAYS_INLINE;

    /**
     * @brief  Push C/R/LRU bits to the VMM
     *
     * @param[in] i_pte  PTE to examine, must be pointer to real entry in table
     */
    void pushUsageStats( PageTableEntry* i_pte );

    /**
     * @brief see flush
     */
    void _flush( void );

    // Allow testcase to see inside
    friend class ptmgrtest;
};

#endif
