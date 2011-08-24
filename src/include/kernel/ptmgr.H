//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/ptmgr.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
        PTE_UNKNOWN          = 0x0000000000000000,  /**< Entry wasn't found */
        PTE_PRESENT          = 0x0000000000000001,  /**< Entry is present in table */
        PTE_VALID            = 0x0000000000000002,  /**< Entry is valid */
        PTE_READ_ONLY        = 0x0000000000000004,  /**< Read-Only */
        PTE_EXECUTE          = 0x0000000000000008,  /**< Execute permission */
        PTE_CACHE_INHIBITED  = 0x0000000000000010,  /**< Cache-Inhibited Access */
        PTE_MODIFIED         = 0x0000000000000020,  /**< Page has been modified */
        PTE_ACCESSED         = 0x0000000000000040,  /**< Page has been accessed */
    };

    /**
     * Page Table Constants
     */
    enum
    {
        PT_SIZE = (1 << 18),  /**< Size of Page Table in bytes */
        PTE_SIZE = 2*sizeof(uint64_t),   /**< Size of a single Page Table Entry in bytes */
        PTEG_SIZE = 8,  /**< Number of PTEs in a single PTE Group */
        PTEG_COUNT = (PT_SIZE / PTE_SIZE) / PTEG_SIZE,  /**< Number of PTEGs in the Page Table */
        INVALID_PN = 0xFFFFFFFFFFFFFFFF,  /**< Invalid value for a Page Number return */
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
                          VmmManager::ACCESS_TYPES i_accessType );

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
     */
    static void delRangePN( uint64_t i_pnStart,
                            uint64_t i_pnFinish );

    /**
     * @brief Return status information about an entry in the hardware page table
     *
     * @param[in] i_vAddr  Virtual Address within the page to be queried  (full address)
     * @param[out] o_pn  Real physical page number to map to, INVALID_PN if PTE is invalid
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
                uint64_t B:2;    /**< 0:1   Segment Size  */
                uint64_t AVA:55; /**< 2:56  Abbreviated Virtual Address = VA w/o bottom 23 bits  */
                uint64_t SW:2;   /**< 57:58 =SW[0:1] - Reserved  */
                uint64_t LRU:2;  /**< 59:60 =SW[2:3] - Used for LRU algorithm  */
                uint64_t L:1;    /**< 61    Virtual page size  */
                uint64_t H:1;    /**< 62    Hash function identifier  */
                uint64_t V:1;    /**< 63    Entry valid  */
            };
            uint64_t dword0;  /**< Full Dword0 */
        };

        /**
         * Dword1
         */
        union {
            struct {  /**< Dword0 Attributes */
                uint64_t pp0:1;    /**< 0     Page Protection bit 0  */
                uint64_t rsv:1;    /**< 1     Reserved  */
                uint64_t key0_1:2; /**< 2:3   KEY bits 0:1  <unused>  */
                uint64_t PN:48;    /**< 4:52  Abbreviated Real Page Number + Large page size selector  */
                uint64_t key2_4:3; /**< 53:54 KEY bits 2:4  <unused>  */
                uint64_t R:1;      /**< 55    Reference bit  */
                uint64_t C:1;      /**< 56    Change bit  */
                uint64_t WIMG:4;   /**< 57:60 Storage control bits  */
                uint64_t N:1;      /**< 61    No-execute page (N==1)  */
                uint64_t pp1_2:2;  /**< 62:63 Page Protection bits 1:2  */
            };
            uint64_t dword1;  /**< Full Dword1 */
        };
    } PACKED;

    /**
     * Internal Constants
     */
    enum {
        PTE_ACCESS_BITS = 0x800000000000007B,  /**< pp0 + WIMG + pp1_2  */
        PTEG_SIZE_BYTES = (sizeof(PageTableEntry)*8),  /**< Size of PTE Group in bytes */

        SLBE_b = 12,  /**< Page Size in bits per SLBE  */
        SLBE_s = 40,  /**< Segment Size in bits per SLBE  */

    };

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
                    VmmManager::ACCESS_TYPES i_accessType );

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
     * @brief Update the LRU statistics for other PTEs in the same PTEG as the target
     *
     * @param[in] i_newPTE  Real address of PTE that is being added to the Page Table
     */
    void updateLRU( const PageTableEntry* i_newPTE );

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
                        VmmManager::ACCESS_TYPES i_accessType );

    /**
     * @brief  Convert the bits from a PTE into a ACCESS_TYPES
     *
     * @param[in] i_pte  PTE to examine
     *
     * @return ACCESS_TYPES  Access parameters of given PTE
     */
    VmmManager::ACCESS_TYPES getAccessType( const PageTableEntry* i_pte );

    /**
     * @brief  Fill in default values for the PTE
     *
     * @param[out] o_pte  PTE to modify
     */
    static void setupDefaultPTE( PageTableEntry* o_pte );



    // Allow testcase to see inside
    friend class ptmgrtest;
};

#endif
