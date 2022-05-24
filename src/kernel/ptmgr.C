/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/ptmgr.C $                                          */
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
#include <kernel/ptmgr.H>
#include <kernel/vmmmgr.H>
#include <util/singleton.H>
#include <kernel/console.H>
#include <kernel/segmentmgr.H>
#include <kernel/taskmgr.H>
#include <arch/ppc.H>
#include <assert.h>
#include <util/align.H>
#include <sys/misc.h>

//#define Dprintk(...) printkd(args...)
#define Dprintk(args...)
#define Tprintk(args...)
#define Eprintk(args...) printk(args)


// Utilities to do some bit manipulation

/**
 * @brief Extract a set of bits and right-justify the result
 * @param[in] i_var64  64-bit word to extract data from
 * @param[in] i_startbit  Bit to start extraction from
 * @param[in] i_lastbit  Bit to stop extraction on, inclusive
 * @return uint64_t  Right-justified data
 */
ALWAYS_INLINE static inline
uint64_t EXTRACT_RJ( uint64_t i_var64,
                     uint64_t i_startbit,
                     uint64_t i_lastbit )
{
    uint64_t mask = ((0xFFFFFFFFFFFFFFFF >> i_startbit) &
                     (0xFFFFFFFFFFFFFFFF << (63 - i_lastbit)));
    uint64_t result = (i_var64 & mask) >> (63 - i_lastbit);
    return result;
}

/**
 * @brief Extract a set of bits and left-justify the result
 * @param[in] i_var64  64-bit word to extract data from
 * @param[in] i_startbit  Bit to start extraction from
 * @param[in] i_lastbit  Bit to stop extraction on, inclusive
 * @return uint64_t  Left-justified data
 */
/*
ALWAYS_INLINE static inline
uint64_t EXTRACT_LJ( uint64_t var64,
                     uint64_t i_startbit,
                     uint64_t i_lastbit )
{
    uint64_t mask = ((0xFFFFFFFFFFFFFFFF >> i_startbit) &
                     (0xFFFFFFFFFFFFFFFF << (63 - i_lastbit)));
    uint64_t result = (var64 & mask) << i_startbit;
    return result;
}
*/

/**
 * @brief Extract a set of bits from the last word of data and right-justify
 *        the result
 *
 *  Example:  Extract bits 25:54 from a 79 bit buffer :
 *    bb = EXTRACT_RJ_LEN(aa,79,25,54)
 *
 * @param[in] i_lastword  Right-most 64-bit word of larger data buffer,
 *                        data[len-64:len]
 * @param[in] i_bitlen    Total number of bits in original buffer
 * @param[in] i_startbit  Bit to start extraction from, relative to original
 *                        bit length
 * @param[in] i_lastbit   Bit to stop extraction on, inclusive, relative to
 *                        original bit length
 * @return uint64_t  Left-justified data
 */
ALWAYS_INLINE static inline
uint64_t EXTRACT_RJ_LEN( uint64_t i_lastword,
                         uint64_t i_bitlen,
                         uint64_t i_startbit,
                         uint64_t i_lastbit )
{
    Dprintk( "i_lastword=%.16lX, i_bitlen=%ld, i_startbit=%ld, i_lastbit=%ld\n",
             i_lastword, i_bitlen, i_startbit, i_lastbit );
    if( (i_lastbit - i_startbit) > 64 )
    {
        Eprintk("error %d : i_lastword=%.16lX, i_bitlen=%ld, i_startbit=%ld,"
                " i_lastbit=%ld\n", __LINE__,
                i_lastword, i_bitlen, i_startbit, i_lastbit);
        kassert(false);
    }
    else if( i_lastbit >= i_bitlen  )
    {
        Eprintk("error %d : i_lastword=%.16lX, i_bitlen=%ld, i_startbit=%ld,"
                " i_lastbit=%ld\n", __LINE__,
                i_lastword, i_bitlen, i_startbit, i_lastbit);
        kassert(false);
    }
    else if( i_bitlen <= 64 )
    {
        uint64_t diff = 64 - i_bitlen;
        return EXTRACT_RJ( i_lastword, i_startbit + diff, i_lastbit + diff );
    }
    else if( i_lastbit < (i_bitlen - 64) )
    {
        // desired bits are inside the first word
        return 0;
    }

    // goal is to left-justify the i_startbit to be bit0 in the resulting word
    uint64_t diff = i_bitlen - 64;  //=bits to the left of i_lastword

    if( i_startbit < diff )
    {
        //move the buffer to the right, zeros will fill in the extra bits
        i_lastword = i_lastword >> (diff - i_startbit);
    }
    else
    {
        //move the buffer to the left to justify it
        i_lastword = i_lastword << (i_startbit - diff);
    }

    i_lastbit -= i_startbit;
    i_startbit = 0;


    return EXTRACT_RJ( i_lastword, i_startbit, i_lastbit );
}

/**
 * @brief Extract a set of bits from the last word of data and left-justify
 *        the result
 *
 * @param[in] i_lastword  Right-most 64-bit word of larger data buffer,
 *                        data[len-64:len]
 * @param[in] i_bitlen    Total number of bits in original buffer
 * @param[in] i_startbit  Bit to start extraction from, relative to original
 *                        bit length
 * @param[in] i_lastbit   Bit to stop extraction on, inclusive, relative to
 *                        original bit length
 * @return uint64_t  Left-justified data
 */
/*
ALWAYS_INLINE static inline
uint64_t EXTRACT_LJ_LEN( uint64_t i_lastword,
                         uint64_t i_bitlen,
                         uint64_t i_startbit,
                         uint64_t i_lastbit )
{
    uint64_t diff = i_bitlen - 64;
    i_lastword = i_lastword >> diff;
    if( i_lastbit < 64 ) {
        i_lastbit = i_lastbit - diff;
    } else {
        Eprintk("error %d : i_lastword=%lX, i_bitlen=%ld, i_startbit=%ld,"
                " i_lastbit=%ld\n", __LINE__,
                i_lastword, i_bitlen, i_startbit, i_lastbit);
        kassert(false);
    }
    if( i_startbit < 64 ) {
        i_startbit = i_startbit - diff;
    } else {
        Eprintk("error %d : i_lastword=%lX, i_bitlen=%ld, i_startbit=%ld,"
                " i_lastbit=%ld\n", __LINE__,
                i_lastword, i_bitlen, i_startbit, i_lastbit);
        kassert(false);
    }
    return EXTRACT_LJ( i_lastword, i_startbit, i_lastbit );
}
*/

/********************
 Public Methods
 ********************/

/**
 * STATIC
 * @brief Static Initializer
 */
void PageTableManager::init()
{
    Singleton<PageTableManager>::instance();
}

/**
 * STATIC
 * @brief Add an entry to the hardware page table
 */
void PageTableManager::addEntry( uint64_t i_vAddr,
                                 uint64_t i_page,
                                 uint64_t i_accessType )
{
    // adjust physical address for the HRMOR unless this is a mmio
    if ((SegmentManager::CI_ACCESS != i_accessType) &&
        ((BYPASS_HRMOR & i_accessType) == 0))
    {
        i_page |= (getHRMOR() / PAGESIZE);
    }

    return Singleton<PageTableManager>::instance()._addEntry( i_vAddr,
                                                              i_page,
                                                              i_accessType );
}

/**
 * STATIC
 * @brief Remove an entry from the hardware page table
 */
void PageTableManager::delEntry( uint64_t i_vAddr )
{
    return Singleton<PageTableManager>::instance()._delEntry(i_vAddr);
}

/**
 * STATIC
 * @brief Remove a range of entries from the hardware page table
 */
void PageTableManager::delRangeVA( uint64_t i_vAddrStart,
                                   uint64_t i_vAddrFinish )
{
    return Singleton<PageTableManager>::instance()._delRangeVA(i_vAddrStart,i_vAddrFinish);
}

/**
 * STATIC
 * @brief Remove a range of entries from the hardware page table
 */
void PageTableManager::delRangePN( uint64_t i_pnStart,
                                   uint64_t i_pnFinish,
                                   bool i_applyHRMOR )
{
    // adjust physical address for the HRMOR unless this is a mmio
    if( i_applyHRMOR )
    {
        i_pnStart |= (getHRMOR() / PAGESIZE);
        i_pnFinish |= (getHRMOR() / PAGESIZE);
    }

    return Singleton<PageTableManager>::instance()._delRangePN(i_pnStart,i_pnFinish);
}


/**
 * STATIC
 * @brief Return status information about an entry in the hardware page table
 */
uint64_t PageTableManager::getStatus( uint64_t i_vAddr,
                                      uint64_t& o_pn )
{
    return Singleton<PageTableManager>::instance()._getStatus(i_vAddr,o_pn);
}

/**
 * STATIC
 * @brief  Print out the contents of a PTE
 */
void PageTableManager::printPTE( const char* i_label,
                                 uint64_t i_pteAddr,
                                 bool i_verbose )
{
#ifdef HOSTBOOT_DEBUG
    Singleton<PageTableManager>::instance().printPTE( i_label, (PageTableEntry*)i_pteAddr, i_verbose );
#endif
}

/**
 * STATIC
 * @brief  Print out the contents of a PTE
 */
void PageTableManager::printPTE( uint64_t i_va,
                                 bool i_verbose )
{
#ifdef HOSTBOOT_DEBUG
    PageTableEntry* pte = Singleton<PageTableManager>::instance().findPTE(i_va);
    Singleton<PageTableManager>::instance().printPTE( NULL, pte, i_verbose );
#endif
}

/**
 * STATIC
 * @brief  Print out the entire Page Table
 */
void PageTableManager::printPT( void )
{
#ifdef HOSTBOOT_DEBUG
    Singleton<PageTableManager>::instance()._printPT();
#endif
}

void PageTableManager::flush( void )
{
    Singleton<PageTableManager>::instance()._flush();
}

/********************
 Private/Protected Methods
 ********************/
/**
 * @brief  Constructor
 */
PageTableManager::PageTableManager( bool i_userSpace )
: ivTABLE(NULL)
,ivIdleTaskFunction(0)
,ivIdleTaskPN(0)
{
    uint64_t l_hrmor = 0;
    if( i_userSpace )
    {
        ivTABLE = new char[getSize()];
        printk( "** PageTableManager running in USER_SPACE : ivTABLE = %p**\n", ivTABLE );
        l_hrmor = cpu_spr_value(CPU_SPR_HRMOR);
    }
    else
    {
        printkd( "Page Table is at 0x%.16lX : 0x%.16lX\n",
                 getAddress(), getAddress() + getSize() );
        l_hrmor = getHRMOR();
    }

    // Find the relative address of the branch into idleTaskLoop
    uint64_t* idle_jump = reinterpret_cast<uint64_t*>(TaskManager::idleTaskLoop);
    // The actual address of the function itself is the data at that
    ///address.
    //000000000001c260 <TaskManager::idleTaskLoop(void*)>:
    //  39077    1c260    0001c260:   00 00 00 00     .long 0x0
    //  39078    1c264    0001c264:   00 01 2b 60     .long 0x12b60  <<< here
    ivIdleTaskFunction = *idle_jump;

    // Compute the physical page number of the idleTaskLoop
    ivIdleTaskPN = (ALIGN_PAGE_DOWN(ivIdleTaskFunction)/PAGESIZE); //relative page
    ivIdleTaskPN |= (l_hrmor/PAGESIZE); //offset by HRMOR to get real page
    printk("IdleTask @0x%lX, PN=%lX\n",
           ivIdleTaskFunction, ivIdleTaskPN);

    //initialize the table to be invalid
    invalidatePT();
}

/**
 * @brief Invalidate all PTEs in the table
 */
void PageTableManager::invalidatePT( void )
{
    PageTableEntry* pte = (PageTableEntry*)getAddress();
    uint64_t num_ptes = getSize() / sizeof(PageTableEntry);
    for( uint64_t x = 0; x < num_ptes; x++ )
    {
        pte->AVA = (uint64_t)PTE_AVA_MASK;
        pte->V = 0;
        pte++;
    }
}

PageTableManager::~PageTableManager()
{
    if( ivTABLE ) {
        delete[] ivTABLE;
    }
}


/**
 * @brief Add an entry to the hardware page table
 */
void PageTableManager::_addEntry( uint64_t i_vAddr,
                                  uint64_t i_page,
                                  uint64_t i_accessType )
{
    Tprintk( ">> PageTableManager::_addEntry( i_vAddr=0x%.16lX, i_page=%ld,"
             " i_accessType=%d )\n", i_vAddr, i_page, i_accessType );

    //Note: no need to lock here because that is handled by higher function

    // page-align this address
    uint64_t l_vaddr = ALIGN_PAGE_DOWN(i_vAddr);

    PageTableEntry pte_data;
    setupDefaultPTE( &pte_data );

    // find the matching PTEG first so we only do it once
    uint64_t pteg_addr = findPTEG( l_vaddr );

    //look for a matching entry in the table already
    PageTableEntry* pte_slot = findPTE( l_vaddr, pteg_addr );
    if( pte_slot == NULL )
    {
        // look for an empty/invalid entry that we can use
        pte_slot = findEmptyPTE( pteg_addr );
        if( pte_slot == NULL )
        {
            // look for a valid entry we can steal
            pte_slot = findOldPTE( pteg_addr );

            // delete the entry that we're going to steal first
            delEntry( pte_slot );
        }

        // since the entry isn't in the table right now we should
        //  start fresh with the usage bits
        pte_data.R = 0b0;    //Clear Referenced bit
        pte_data.LRU = 0b00; //Clear LRU bits
    }
    else
    {
        if( pte_slot->V == 1 )
        {
            if( i_page != pte_slot->PN )
            {
                Eprintk( "**ERROR** PageTableManager::_addEntry>"
                         " Duplicate PTE with different page number\n" );
                kassert(false);
            }
        }
        else
        {
            // We reused a PTE previously used, but it wasn't marked valid
            // so clear the R/LRU bits to reset it to a clean state.
            pte_data.R = 0b0;    //Clear Referenced bit
            pte_data.LRU = 0b00; //Clear LRU bits
        }
    }

    // we can't handle any other cases...
    if( pte_slot == NULL )
    {
        Eprintk( "**ERROR** PageTableManager::_addEntry>"
                 " Nowhere to put the new PTE\n" );
        kassert(false);
    }

    // update the access bits in our local copy
    setAccessBits( &pte_data, i_accessType );

    // update the Abbreviated Virtual Address
    pte_data.AVA = (i_vAddr >> 23);

    // update the Abbreviated Real Page Number
    pte_data.PN = i_page;

    //Note: We are ignoring the LP field

    // write the new entry into mainstore
    writePTE( &pte_data, pte_slot, true );


    Dprintk( "<< PageTableManager::_addEntry()\n" );
}

/**.
 * @brief Remove an entry from the hardware page table
 */
void PageTableManager::_delEntry( uint64_t i_vAddr )
{
    // find the corresponding PTE
    PageTableEntry* pte = findPTE( i_vAddr );
    if( pte )
    {
        delEntry( pte );
    }
}

/**
 * @brief Remove an entry from the hardware page table
 */
void PageTableManager::delEntry( PageTableEntry* i_pte )
{
    if (i_pte->V)
    {
        // clear the entry from the table
        writePTE( i_pte, i_pte, false );

        // need to notify VMM when we remove a PTE
        pushUsageStats( i_pte );
    }
}

/**
 * @brief Remove a range of entries from the hardware page table
 */
void PageTableManager::_delRangeVA( uint64_t i_vAddrStart,
                                    uint64_t i_vAddrFinish )
{
    // Note : this could potentially be very slow for large ranges

    // loop around 4K pages within the range
    for( uint64_t va = i_vAddrStart; va < i_vAddrFinish; va += PAGESIZE )
    {
        _delEntry( va );
    }
}

/**
 * @brief Remove a range of entries from the hardware page table
 */
void PageTableManager::_delRangePN( uint64_t i_pnStart,
                                    uint64_t i_pnFinish )
{
    // Since the range is likely going to be quite large, we are going to
    //  loop around every PTE rather than looping through all of the pages
    //  within the given range
    uint64_t pt_addr = getAddress();
    PageTableEntry* pte = (PageTableEntry*) pt_addr;
    uint64_t num_ptes = getSize() / sizeof(PageTableEntry);
    for( uint64_t x = 0; x < num_ptes; x++ )
    {
        if( (pte->V == 1) && (pte->PN >= i_pnStart) && (pte->PN <= i_pnFinish) )
        {
            delEntry( pte );
        }

        pte++;
    }
}

/**
 * @brief Return status information about an entry in the hardware page table
 */
uint64_t PageTableManager::_getStatus( uint64_t i_vAddr,
                                       uint64_t& o_pn )
{
    PageTableEntry* pte = findPTE( i_vAddr );
    o_pn = INVALID_PN;
    if( pte ) {
        o_pn = pte->PN;
    }
    return getStatus( pte );
}

/**
 * @brief Translate a PTE into the status bits
 */
uint64_t PageTableManager::getStatus( PageTableEntry* i_pte )
{
    if( i_pte == NULL )
    {
        return PTE_UNKNOWN;
    }

    // translate different bits in the struct
    uint64_t status = PTE_UNKNOWN;
    status |= PTE_PRESENT;
    if( i_pte->V == 1 ) {
        status |= PTE_VALID;
    }

    uint64_t access = getAccessType(i_pte);

    switch (access)
    {
      case SegmentManager::CI_ACCESS:
	status |= PTE_CACHE_INHIBITED;
	break;

      case READ_ONLY:
	status |= PTE_READ;
	break;

      case WRITABLE:
	status |= PTE_WRITABLE;
	status |= PTE_READ;
        break;

      case  EXECUTABLE:
	status |= PTE_EXECUTE;
	status |= PTE_READ;
        break;

      default:
	break;
    }

    if( i_pte->R == 1 ) {
        status |= PTE_ACCESSED;
    }

    return status;
}


/**
 * @brief  Return the 39-bit hash value of the VA
 */
uint64_t PageTableManager::computeHash( uint64_t i_vAddr )
{
    //Note: VA is really 78-bits, we are assuming top 14 bits are always zero

    uint64_t l_hash_val = 0;

    if( SLBE_s == 40 )
    {
        // the hash value is computed by
        // Exclusive ORing the following three quantities:
        // (VA[24:37]||<25>0), (0||VA[0:37]), and (<b-1>0||VA[38:77-b])

        //mask off unrelated bits, right-justify bit 37, append 25 zeros
        uint64_t va__24_37 = EXTRACT_RJ_LEN( i_vAddr, 78, 24, 37 ) << 25;
        //mask off unrelated bits, right-justify bit 37
        uint64_t va__0_37 = EXTRACT_RJ_LEN( i_vAddr, 78, 0, 37 );
        //mask off unrelated bits, right-justify bit 65 (77-12)
        uint64_t va__38_77b = EXTRACT_RJ_LEN( i_vAddr, 78, 38, 77-SLBE_b );

        l_hash_val = va__24_37 ^ va__0_37 ^ va__38_77b;

        Dprintk( "computeHash(i_vAddr=0x%.16lX)\n", i_vAddr );
        Dprintk( "va__24_37  = 0x%.16lX\n", va__24_37 );
        Dprintk( "va__0_37   = 0x%.16lX\n", va__0_37 );
        Dprintk( "va__38_77b = 0x%.16lX\n", va__38_77b );

    }
    else if( SLBE_s == 28 )
    {
        // the hash value is computed by
        // Exclusive ORing VA[11:49] with (<11+b>0||VA[50:77-b])

        //mask off unrelated bits, right-justify bit 49
        uint64_t va__11_49 = EXTRACT_RJ_LEN( i_vAddr, 78, 11, 49 );
        //mask off unrelated bits, right-justify bit 65 (77-12)
        uint64_t va__50_77b = EXTRACT_RJ_LEN( i_vAddr, 78, 50, 77-SLBE_b );

        l_hash_val = va__11_49 ^ va__50_77b;
    }

    //Note: not using Secondary Hash (LPCR[TC]==1)


    Dprintk( "l_hash_val = 0x%.16lX\n", l_hash_val );
    return l_hash_val;
}

/**
 * @brief  Find the 60-bit real address of the PTEG that matches the given
 *         virtual address
 */
uint64_t PageTableManager::findPTEG( uint64_t i_vAddr )
{
    // hash is an index into a virtual array of PTEGs
    uint64_t hash = computeHash(i_vAddr); //right-justified

    // mask off the hash to fit into the table
    hash = hash % PTEG_COUNT;

    // use the hash as the index into the array of PTEGs
    uint64_t pteg_addr = getAddress() + hash * PTEG_SIZE_BYTES;

    Dprintk( "PageTableManager::findPTEG(i_vAddr=0x%.16lX) = 0x%.16lX\n",
             i_vAddr, pteg_addr );
    return pteg_addr;
}

/**
 * @brief  Find the real address of the PTE that matches the given address
 */
PageTableManager::PageTableEntry* PageTableManager::findPTE( uint64_t i_vAddr )
{
    Dprintk( ">> PageTableManager::findPTE(i_vAddr=0x%.16lX)\n", i_vAddr );

    // first find the PTEG
    uint64_t pteg_addr = findPTEG( i_vAddr );

    // look for a PTE in that PTEG
    PageTableEntry* pte_found = findPTE( i_vAddr, pteg_addr );

    Dprintk( "PageTableManager::findPTE() = %.16lX <<\n", (uint64_t)pte_found );
    return pte_found;
}

/**
 * @brief  Find the real address of the PTE that matches the given address
 */
PageTableManager::PageTableEntry* PageTableManager::findPTE( uint64_t i_vAddr,
                                                             uint64_t i_ptegAddr
                                                           )
{
    Tprintk( "PageTableManager::findPTE(i_vAddr=0x%.16lX"
             ",i_ptegAddr=0x%.16lX)>>\n",
             i_vAddr, i_ptegAddr );

    PageTableEntry* pte_found = NULL;

    PageTableEntry* pte_cur = (PageTableEntry*)i_ptegAddr;

    // loop through all 8 PTEs
    for( uint64_t x = 0; x < 8; x++ )
    {
        // compare input to AVA
        //2:56  Abbreviated Virtual Address = VA w/o bottom 23 bits
        if( pte_cur->AVA == (i_vAddr >> 23) )
        {
            Tprintk( "Found match at PTE #%ld\n", x );
            //printPTE( pte_cur );
            pte_found = pte_cur;
            break;
        }

        pte_cur++;
    }

    Dprintk( "<<PageTableManager::findPTE() = %.16lX>>\n",
             (uint64_t)pte_found );
    return pte_found;
}

/**
 * @brief  Write a PTE to memory and update caches appropriately
 */
void PageTableManager::writePTE( PageTableEntry* i_pte,
                                 PageTableEntry* i_dest,
                                 bool i_valid )
{
    // Are we stealing a valid PTE?
    if( (i_dest->V == 1) && i_valid )
    {
        // If the AVAs match then we're just modifying permissions or something
        if( i_pte->AVA != i_dest->AVA )
        {
            // this should never happen because we should always go
            //   through the delEntry() path instead
            printPTE( "Stealing", i_dest );
            Eprintk( "**ERROR** PageTableManager::writePTE>"
                     " Trying to steal a PTE\n" );
            kassert(false);
        }
    }

    if(unlikely(ivTABLE != NULL))
    {
        Dprintk( ">> PageTableManager::writePTE( i_dest=%p, i_valid=%d )"
                 "  **FAKE**\n",
                 i_dest, i_valid );
        memcpy( (void*) i_dest, (void*) i_pte, sizeof(PageTableEntry) );
        if( i_valid ) {
            i_dest->V = 1;
            //printPTE( "Writing", i_dest );
        } else {
            i_dest->V = 0;
            //printk( ">> PageTableManager::writePTE( i_dest=%p, i_valid=%d )"
            //        "  **FAKE**\n",
            //        i_dest, i_valid );
            //printPTE( "Removing", i_dest );
        }
    }
    else
    {
        Dprintk( ">> PageTableManager::writePTE( i_dest=0x%.lX, i_valid=%d )\n",
                 i_dest, i_valid );

        // If we are invalidating or modifying permissions, need to invalidate
        // the PTE.
        if ((!i_valid) || (i_dest->V == 1) )
        {
            i_dest->V = 0; /* (other fields don't matter) */

            /* order update before tlbie and before next Page Table search */
            asm volatile("ptesync" ::: "memory");

            // tlbie, eieio, tlbsync, ptesync
            invalidateTLB(i_dest);
        }

        // Requested to mark page valid?
        if (i_valid)
        {
            //PTE:ARPN,LP,AC,R,C,WIMG,N,PP set to new values
            i_dest->dword1 = i_pte->dword1;

            asm volatile("eieio" ::: "memory"); /* order 2nd update before 3rd */

            //PTE:B,AVA,SW,L,H,V set to new values (V=1)
            i_dest->dword0 = i_pte->dword0;
            i_dest->LRU = 0;
            i_dest->V = 1;

            /* order 2nd and 3rd updates before next Page Table search
             and before next data access */
            asm volatile("ptesync" ::: "memory");
        }
    }

    // update the other entries' LRU statistics
    if (i_valid)
    {
        updateLRUGroup( i_dest );
    }

    Dprintk( "<< PageTableManager::writePTE()\n" );
}


/**
 * @brief  Print out the contents of a PTE
 */
void PageTableManager::printPTE( const char* i_label,
                                 const PageTableEntry* i_pte,
                                 bool i_verbose )
{
#ifdef HOSTBOOT_DEBUG
    if( i_pte == NULL )
    {
        if( i_label ) { printkd( "%s :: ", i_label ); }
        printkd( "NULL PTE\n" );
        return;
    }

    uint64_t pte_num = (((uint64_t)i_pte) - getAddress()) / sizeof(PageTableEntry);
    pte_num++; pte_num--;

    if( i_label ) { printkd( "%s :: ", i_label ); }
    if( i_verbose )
    {
        printkd( "[%4ld:%4ld]> @%p\n", pte_num/PTEG_SIZE, pte_num%PTEG_SIZE, i_pte );
        printkd( "Dword  : %.16lX %.16lX\n", ((uint64_t*)i_pte)[0], ((uint64_t*)i_pte)[1] );
        printkd( "-AVA   : 0x%.14lX\n", i_pte->AVA );
        printkd( "-SW    : %ld\n", i_pte->SW );
        printkd( "-LRU   : %ld\n", i_pte->LRU );
        printkd( "-V     : %ld\n", i_pte->V );
        printkd( "-RC    : %ld%ld\n", i_pte->R, i_pte->C );
        printkd( "-WIMG  : 0x%.1lX\n", i_pte->WIMG );
        printkd( "-pp0   : %ld\n", i_pte->pp0 );
        printkd( "-pp1_2 : %ld\n", i_pte->pp1_2 );
        printkd( "-PN    : %ld\n", i_pte->PN );
    }
    else
    {
        printkd( "[%4ld:%4ld]> @%p : %.16lX %.16lX : VA=%16lX, PN=%ld\n", pte_num/PTEG_SIZE, pte_num%PTEG_SIZE, i_pte, i_pte->dword0, i_pte->dword1, getVirtAddrFromPTE(i_pte), i_pte->PN );
    }
#endif
}


/**
 * @brief  Print out the entire Page Table
 */
void PageTableManager::_printPT( void )
{
#ifdef HOSTBOOT_DEBUG
    printkd( "- -Page Table --\n" );
    uint64_t pt_addr = getAddress();
    PageTableEntry* pte = (PageTableEntry*) pt_addr;
    printkd( "@%p..0x%.16lX\n", pte, pt_addr +  getSize() );

    uint64_t num_ptes = getSize() / sizeof(PageTableEntry);
    for( uint64_t x = 0; x < num_ptes; x++ )
    {
        if( pte->V == 1 )
        {
            printPTE( NULL, pte );
        }

        pte++;
    }

    printkd( "-- End Page Table --\n" );
#endif
}

/**
 * @brief  Return the real address of the page table in memory
 */
uint64_t PageTableManager::getAddress( void )
{
    if(unlikely(ivTABLE != NULL)) {
        return (uint64_t)ivTABLE;
    } else {
        return VmmManager::HTABORG();
    }
}

/**
 * @brief  Return the size of the page table in memory in bytes
 */
inline uint64_t PageTableManager::getSize( void )
{
    return (256*1024); //256KB
}

/**
 * @brief  Set bits in PTE for the given ACCESS_TYPES
 */
void PageTableManager::setAccessBits( PageTableEntry* o_pte,
                                           uint64_t i_accessType )
{
    o_pte->dword1 &= ~PTE_ACCESS_BITS;

    /*  Description of the WIMG bits.
        W1,3 0 - not Write Through Required
        1 - Write Through Required
        I3   0 - not Caching Inhibited
        1 - Caching Inhibited
        M2   0 - not Memory Coherence Required
        1 - Memory Coherence Required
        G   0 - not Guarded
        1 - Guarded
        */
    if( SegmentManager::CI_ACCESS == i_accessType )
    {
        o_pte->WIMG = 0b0101; // Cache Inhibited, Guarded
        o_pte->pp1_2 = 0b10;  // PP=010
        o_pte->N = 0b1;       // No Execute
    }
    else
    {
        // Only setting that changes WIMG is CI_ACCESSS
        // All others are set to 0b0010
        o_pte->WIMG = 0b0010; // Memory Coherency Required

        // Turn on the guarded access permission if requested
        if(i_accessType & GUARDED)
        {
            o_pte->WIMG |= 0b0001;
        }

        if (i_accessType & READ_ONLY)
        {
            o_pte->pp1_2 = 0b01;  // PP=001
            o_pte->N = 0b1;       // No Execute
        }
        // if writable (implied readable)
        else if (i_accessType & WRITABLE)
        {
            o_pte->pp1_2 = 0b10;  // PP=010
            o_pte->N = 0b1;       // No Execute
        }
        // if executable (implied readable)
        else if (i_accessType & EXECUTABLE)
        {
            o_pte->pp1_2 = 0b01;  // PP=001
            o_pte->N = 0b0;       // Execute
        }
        else
        {
            Eprintk( "** unrecognized access=%ld\n", i_accessType );
        }
    }
}

/**
 * @brief  Convert the bits from a PTE into a ACCESS_TYPES
 */
uint64_t PageTableManager::getAccessType( const PageTableEntry* i_pte )
{

  if( i_pte->pp0 == 0b0 )
  {
    // If set to Cache Inhibited.
    if( (i_pte->WIMG == 0b0101) && (i_pte->pp1_2 == 0b10) )
    {
      return SegmentManager::CI_ACCESS;
    }
    else if ( (i_pte->WIMG & 0b1110) == 0b0010)
      {
	if (i_pte->pp1_2 == 0b00)
	{
	  return NO_ACCESS;
	}
	// If read and no execute
	else if ((i_pte->pp1_2 == 0b01) && (i_pte->N == 0b1))
	{
	  return READ_ONLY;
	}
	// if writeable and no executable
	else if ((i_pte->pp1_2 == 0b10) && (i_pte->N == 0b1))
	{
	  return WRITABLE;
	}
	// if readably and executable..
	else if  ((i_pte->pp1_2 == 0b01) && (i_pte->N == 0b0))
	{
	  return EXECUTABLE;
	}
      }
  }
  Eprintk( "I don't recognize this PTE : WIMG=%ld, pp1_2=%ld\n",
           i_pte->WIMG, i_pte->pp1_2 );
  printPTE( "getAccessType", i_pte);
  kassert(false);
  return NO_ACCESS;

}
/**
 * @brief  Fill in default values for the PTE
 */
ALWAYS_INLINE inline
void PageTableManager::setupDefaultPTE( PageTableEntry* o_pte )
{
    o_pte->B = 0b01;   //Segment Size  (01=1TB)
    o_pte->L = 0b0;    //Virtual page size  (1=>4KB)
    o_pte->H = 0b0;    //Hash function identifier  (0=primary hash)
    o_pte->C = 0b1;    // Mark change bit so HW doesn't have to; we don't use
                       // the change bits anyhow.
}

/**
 * @brief  Find the real address of a PTE that that is empty or invalid
 */
PageTableManager::PageTableEntry*
    PageTableManager::findEmptyPTE( uint64_t i_ptegAddr )
{
    Tprintk( "PageTableManager::findEmptyPTE(i_ptegAddr=0x%.16lX)>>\n",
              i_ptegAddr );

    PageTableEntry* pte_slot = NULL;
    PageTableEntry* pte_cur = (PageTableEntry*)i_ptegAddr;

    // loop through all 8 PTEs
    for( uint64_t x = 0; x < 8; x++ )
    {
        // look for an invalid entry
        if( pte_cur->V == 0 )
        {
            Tprintk( "Found invalid slot at #%ld\n", x );
            //printPTE( pte_cur );
            pte_slot = pte_cur;
            break;
        }

        pte_cur++;
    }

    Dprintk( "<<PageTableManager::findEmptyPTE() = %p>>\n", pte_slot );
    return pte_slot;
}

/**
 * @brief  Find the real address of a PTE that can be invalidated
 *   and replaced
 */
PageTableManager::PageTableEntry*
    PageTableManager::findOldPTE( uint64_t i_ptegAddr )
{
    // Order of preference for PTE slots to steal:
    // 0) Never take the PTE for the idle task
    // 1) PTE with highest use count (LRU==SW[2:3])
    // 2) Lowest PTE with the highest use count
    PageTableEntry* pte = (PageTableEntry*)i_ptegAddr;
    PageTableEntry* old_pte = pte;
    for( uint64_t x = 0; x < 8; x++ )
    {
        // Note: Checking 2 pages to cover the (very unlikely) scenario where
        //  the idle function happens to cross 2 pages.  There is no
        //  real harm to pinning a second page even if not needed since
        //  it is also part of the base image so there is no good reason
        //  to page it out.

        // Choose any other page over the idle task
        if( (old_pte->PN == ivIdleTaskPN)
            || (old_pte->PN == (ivIdleTaskPN+1)) )
        {
            old_pte = pte;
        }
        // Choose the least recently used page to replace, but
        // never choose the idle task
        else if( (pte->LRU > old_pte->LRU)
                 && !((pte->PN == ivIdleTaskPN)
                      || (pte->PN == (ivIdleTaskPN+1))) )
        {
            old_pte = pte;
        }

        pte++;
    }
    //PageTableManager::printPTE( "Dropping PTE", old_pte );

    return old_pte;
}

/**
 * @brief Update the LRU statistics for other PTEs in the same PTEG as
 *        the target
 */
void PageTableManager::updateLRUGroup( const PageTableEntry* i_newPTE )
{
    Tprintk( ">> PageTableManager::updateLRUGroup( i_newPTE=%p )\n", i_newPTE );

    // find the beginning of the PTEG, by rounding down by PTEG_SIZE_BYTES.
    uint64_t pteg_addr = (((uint64_t)i_newPTE) / PTEG_SIZE_BYTES) *
                         PTEG_SIZE_BYTES;

    // loop through all 8 PTEs in the PTEG
    PageTableEntry* pte_cur = (PageTableEntry*)pteg_addr;
    for( uint64_t x = 0; x < 8; x++ )
    {
        // skip the entry we just added
        if( pte_cur != i_newPTE )
        {
            updateLRUEntry(pte_cur);
        }

        pte_cur++;
    }

    Tprintk( "<< PageTableManager::updateLRUGroup(\n" );
}

/**
 * @brief Update the LRU statistics for a specific PTE.
 */
void PageTableManager::updateLRUEntry( PageTableEntry* i_PTE )
{
    Tprintk( ">> PageTableManager::updateLRUEntry( i_PTE=%p )\n", i_PTE);

    PageTableEntry pte = *i_PTE;

    // Check if referenced.
    if ((pte.V == 1) && (pte.R == 1))
    {
        // Save software bit updates for later.
        pte.LRU = 0;
        pte.R2 = 1;

        // Update R bit in PTE.
        //     See Resetting the Reference Bit in ISA.
        i_PTE->R = 0;  // should only be updating 1 byte.
        invalidateTLB(i_PTE);
    }
    else if (pte.LRU < 0b11)
    {
        pte.LRU++;
    }

    // Update the software bits of the PTE.
    //     The ISA suggests we need to do a ldarx/stdcx combination
    //     here, but this isn't required because we have a spinlock
    //     around the page table as a whole.  No other thread will
    //     be even reading this word here.
    i_PTE->dword0 = pte.dword0;

    Tprintk( "<< PageTableManager::updateLRUEntry(\n" );
}


/**
 * @brief Invalidate TLB for a PTE
 */
void PageTableManager::invalidateTLB( PageTableEntry* i_pte )
{
    Tprintk( ">> PageTableManager::invalidateTLB( i_pte=%p )\n", i_pte );

    if( likely(ivTABLE == NULL) )
    {
        // TLBIE's AVA is 14:65 of the original VA (!= pte->AVA)
        uint64_t tlbie_ava = EXTRACT_RJ_LEN(
                              getVirtAddrFromPTE(i_pte), 78, 14, 65 );

        /*invalidate old translation*/
        //tlbie(old_B,old_VA[14:77-b],old_L,old_LP,old_AP,old_LPID);
        // TLBIE isn't correct in gcc, hand code asm.
        register uint64_t rS = 0, rB = 0;
        rB = (tlbie_ava & 0x000FFFFFFFFFFFFF) << 12; // Put in rB[0:51]
        rB |= 0x0100; // B = 01 (1TB).
        asm volatile(".long 0x7c000264 | (%0 << 11) | (%1 << 21)" ::
                     "r"(rB), "r"(rS) : "memory");

        /* order tlbie before tlbsync */
        asm volatile("eieio" ::: "memory");

        /* order tlbie before ptesync */
        asm volatile("tlbsync" ::: "memory");

        /* order tlbie, tlbsync and 1st update before 2nd update */
        asm volatile("ptesync" ::: "memory");
    }

    Tprintk( "<< PageTableManager::invalidateTLB( )\n" );
}

/**
 * @brief  Calculate the original Virtual Address from a PTE
 */
uint64_t PageTableManager::getVirtAddrFromPTE( const PageTableEntry* i_pte )
{
    uint64_t pte_addr = (uint64_t)i_pte;

    /*
     0....5....1....5....2....5....3....5....4....5....50...5....6....5....7....5..    full VA (78 bits)
     000000000000000vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv000000000000    top 15 and bottom 12 bits are zero
     000000000000000---------aaaaaaaaaaaaaa----------------------------------------    X=VA[24:37]
     000000000000000bbbbbbbbbbbbBBBBBBBBBBB----------------------------------------    Y=VA[0:37]
     000000000000000-----------------------cccccccccccccccccCCCCCCCCCCC------------    Z=VA[38:65]
     000000000000000dddddddddddddddddddddddddddddddddddddddd-----------------------    AVA = VA[0:54]

     0000000000000000000000000000BBBBBBBBBBB = Y' = VA[27:37] = AVA[27:37]
     0000000000000000000000000000CCCCCCCCCCC = Z' = VA[55:65]

     X^Y^Z % 2048 = ptegnum
     0^Y^Z % 2048 = ptegnum		(all of X is above the % line)
     Y' ^ Z' = ptegnum
     Z' = Y' ^ ptegnum
     */

    // first get the PTEG number (=hash result) based on the PTE pointer
    uint64_t pteg_num = (pte_addr - getAddress())/PTEG_SIZE_BYTES;

    // next pull the Y' value out of the AVA
    uint64_t Yp = EXTRACT_RJ_LEN( i_pte->AVA, 55, 27, 37 );

    // next invert the XOR operation from the hash function
    uint64_t Zp = Yp ^ pteg_num;

    // finally put everything together to make a complete virtual address
    uint64_t va = (Zp << 12) | (i_pte->AVA << 23);

    return va;
}

/**
 * @brief  Push C/R/LRU bits to the VMM
 *
 * @param[in] i_pte  PTE to examine, must be pointer to real entry in table
 */
void PageTableManager::pushUsageStats( PageTableEntry* i_pte )
{
    // skip this in unit-test mode because addresses aren't really backed
    if( unlikely(ivTABLE != NULL) )
    {
        return;
    }

    UsageStats_t stats;

    // Read LRU.
    stats.LRU = i_pte->LRU;

    // Update R-bit.
    //    See Resetting the Reference Bit in ISA.
    if (i_pte->R)
    {
        stats.R = 1;
        i_pte->R = 0;
        invalidateTLB(i_pte);
    }

    // Update R2-bit (saved reference from updateLRUEntry).
    if (i_pte->R2)
    {
        stats.R = 1;

        // Update R2 (software field) bit in PTE.
        //     The ISA suggests we need to do a ldarx/stdcx combination
        //     here, but this isn't required because we have a spinlock
        //     around the page table as a whole.  No other thread will
        //     be even reading this word here.
        i_pte->R2 = 0;
    }

    // now we need to send what we learned to the rest of the VMM
    uint64_t va = getVirtAddrFromPTE(i_pte);
    SegmentManager::updateRefCount( va, stats );
}

void PageTableManager::_flush( void )
{
    if( unlikely(ivTABLE != NULL) )
    {
        return;
    }

    PageTableEntry* pte = (PageTableEntry*)getAddress();
    uint64_t num_ptes = getSize() / sizeof(PageTableEntry);
    for (uint64_t i = 0; i < num_ptes; ++i)
    {
        if (pte->V)
        {
            pushUsageStats ( pte );
        }
        ++pte;
    }
}

