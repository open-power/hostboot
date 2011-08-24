//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/ptmgr.C $
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
#include <kernel/ptmgr.H>
#include <kernel/vmmmgr.H>
#include <util/singleton.H>
#include <kernel/console.H>
#include <arch/ppc.H>
#include <assert.h>

//#define Dprintk(...) printk(args...)
#define Dprintk(args...)
#define Tprintk(args...)
#define Eprintk(args...) printk(args)

// Utilities to do some bit manipulation

/**
 * @brief Extract a set of bits and right-justify the result
 * @param i_var64[in]  64-bit word to extract data from
 * @param i_startbit[in]  Bit to start extraction from
 * @param i_lastbit[in]  Bit to stop extraction on, inclusive
 * @return uint64_t  Right-justified data
 */
ALWAYS_INLINE uint64_t EXTRACT_RJ( uint64_t i_var64,
                                   uint64_t i_startbit,
                                   uint64_t i_lastbit )
{
    uint64_t mask = ((0xFFFFFFFFFFFFFFFF >> i_startbit) & (0xFFFFFFFFFFFFFFFF << (63 - i_lastbit)));
    uint64_t result = (i_var64 & mask) >> (63 - i_lastbit);
    return result;
}

/**
 * @brief Extract a set of bits and left-justify the result
 * @param i_var64[in]  64-bit word to extract data from
 * @param i_startbit[in]  Bit to start extraction from
 * @param i_lastbit[in]  Bit to stop extraction on, inclusive
 * @return uint64_t  Left-justified data
 */
ALWAYS_INLINE uint64_t EXTRACT_LJ( uint64_t var64,
                                   uint64_t i_startbit,
                                   uint64_t i_lastbit )
{
    uint64_t mask = ((0xFFFFFFFFFFFFFFFF >> i_startbit) & (0xFFFFFFFFFFFFFFFF << (63 - i_lastbit)));
    uint64_t result = (var64 & mask) << i_startbit;
    return result;
}

/**
 * @brief Extract a set of bits from the last word of data and right-justify the result
 *
 *  Example:  Extract bits 25:54 from a 79 bit buffer :
 *    bb = EXTRACT_RJ_LEN(aa,79,25,54)
 *
 * @param i_lastword[in]  Right-most 64-bit word of larger data buffer, data[len-64:len]
 * @param i_bitlen[in]  Total number of bits in original buffer
 * @param i_startbit[in]  Bit to start extraction from, relative to original bit length
 * @param i_lastbit[in]  Bit to stop extraction on, inclusive, relative to original bit length
 * @return uint64_t  Left-justified data
 */
ALWAYS_INLINE uint64_t EXTRACT_RJ_LEN( uint64_t i_lastword,
                                       uint64_t i_bitlen,
                                       uint64_t i_startbit,
                                       uint64_t i_lastbit )
{
    Dprintk( "i_lastword=%.16lX, i_bitlen=%ld, i_startbit=%ld, i_lastbit=%ld\n", i_lastword, i_bitlen, i_startbit, i_lastbit );
    if( (i_lastbit - i_startbit) > 64 )
    {
        Eprintk("error %d : i_lastword=%.16lX, i_bitlen=%ld, i_startbit=%ld, i_lastbit=%ld\n", __LINE__, i_lastword, i_bitlen, i_startbit, i_lastbit);
        kassert(false);
    }
    else if( i_lastbit >= i_bitlen  )
    {
        Eprintk("error %d : i_lastword=%.16lX, i_bitlen=%ld, i_startbit=%ld, i_lastbit=%ld\n", __LINE__, i_lastword, i_bitlen, i_startbit, i_lastbit);
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
 * @brief Extract a set of bits from the last word of data and left-justify the result
 *
 * @param i_lastword[in]  Right-most 64-bit word of larger data buffer, data[len-64:len]
 * @param i_bitlen[in]  Total number of bits in original buffer
 * @param i_startbit[in]  Bit to start extraction from, relative to original bit length
 * @param i_lastbit[in]  Bit to stop extraction on, inclusive, relative to original bit length
 * @return uint64_t  Left-justified data
 */
ALWAYS_INLINE uint64_t EXTRACT_LJ_LEN( uint64_t i_lastword, uint64_t i_bitlen, uint64_t i_startbit, uint64_t i_lastbit )
{
    uint64_t diff = i_bitlen - 64;
    i_lastword = i_lastword >> diff;
    if( i_lastbit < 64 ) {
        i_lastbit = i_lastbit - diff;
    } else {
        Eprintk("error %d : i_lastword=%lX, i_bitlen=%ld, i_startbit=%ld, i_lastbit=%ld\n", __LINE__, i_lastword, i_bitlen, i_startbit, i_lastbit);
        kassert(false);
    }
    if( i_startbit < 64 ) {
        i_startbit = i_startbit - diff;
    } else {
        Eprintk("error %d : i_lastword=%lX, i_bitlen=%ld, i_startbit=%ld, i_lastbit=%ld\n", __LINE__, i_lastword, i_bitlen, i_startbit, i_lastbit);
        kassert(false);
    }
    return EXTRACT_LJ( i_lastword, i_startbit, i_lastbit );
}

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
                                 VmmManager::ACCESS_TYPES i_accessType )
{
    return Singleton<PageTableManager>::instance()._addEntry( i_vAddr, i_page, i_accessType );
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
                                   uint64_t i_pnFinish )
{
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
    Singleton<PageTableManager>::instance().printPTE( i_label, (PageTableEntry*)i_pteAddr, i_verbose );
}

/**
 * STATIC
 * @brief  Print out the contents of a PTE
 */
void PageTableManager::printPTE( uint64_t i_va,
                                 bool i_verbose )
{
    PageTableEntry* pte = Singleton<PageTableManager>::instance().findPTE(i_va);
    Singleton<PageTableManager>::instance().printPTE( NULL, pte, i_verbose );
}

/**
 * STATIC
 * @brief  Print out the entire Page Table
 */
void PageTableManager::printPT( void )
{
    Singleton<PageTableManager>::instance()._printPT();
}


/********************
 Private/Protected Methods
 ********************/

/**
 * @brief  Constructor
 */
PageTableManager::PageTableManager( bool i_userSpace )
: ivTABLE(NULL)
{
    if( i_userSpace )
    {
        ivTABLE = new char[getSize()];
        //printk( "** PageTableManager running in USER_SPACE : ivTABLE = %p**\n", ivTABLE );
    }
    else
    {
        printk( "Page Table is at 0x%.16lX : 0x%.16lX\n", getAddress(), getAddress() + getSize() );
    }

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
        pte->AVA = 0xFFFFFFFFFFFF;
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
                                  VmmManager::ACCESS_TYPES i_accessType )
{
    Tprintk( ">> PageTableManager::_addEntry( i_vAddr=0x%.16lX, i_page=%ld, i_accessType=%d )\n", i_vAddr, i_page, i_accessType );

    //Note: no need to lock here because that is handled by higher function

    PageTableEntry pte_data;
    setupDefaultPTE( &pte_data );

    // find the matching PTEG first so we only do it once
    uint64_t pteg_addr = findPTEG( i_vAddr );

    //look for a matching entry in the table already
    PageTableEntry* pte_slot = findPTE( i_vAddr, pteg_addr );
    if( pte_slot == NULL )
    {
        // look for an empty/invalid entry that we can use
        pte_slot = findEmptyPTE( pteg_addr );
        if( pte_slot == NULL )
        {
            // look for a valid entry we can steal
            pte_slot = findOldPTE( pteg_addr );
        }
    }
    else
    {
        if( (pte_slot->V == 1) && (i_page != pte_slot->PN) )
        {
            Eprintk( "**ERROR** PageTableManager::_addEntry> Duplicate PTE with different page number\n" );
            kassert(false);
        }
    }

    // we can't handle any other cases...
    if( pte_slot == NULL )
    {
        Eprintk( "**ERROR** PageTableManager::_addEntry> Nowhere to put the new PTE\n" );
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

/**
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
    writePTE( i_pte, i_pte, false );
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
            writePTE( pte, pte, false );
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

    VmmManager::ACCESS_TYPES access = getAccessType(i_pte);
    switch( access ) {
        case( VmmManager::CI_ACCESS ):
            status |= PTE_CACHE_INHIBITED;
            break;
        case( VmmManager::READ_O_ACCESS ):
            status |= PTE_READ_ONLY;
            break;
        case( VmmManager::NORMAL_ACCESS ):
            status |= PTE_EXECUTE; //@fixme?
            break;
        case( VmmManager::RO_EXE_ACCESS ):
            status |= PTE_READ_ONLY;
            status |= PTE_EXECUTE;
            break;
        default:
            break;
    };

    if( i_pte->C == 1 ) {
        status |= PTE_MODIFIED;
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
 * @brief  Find the 60-bit real address of the PTEG that matches the given virtual address
 */
uint64_t PageTableManager::findPTEG( uint64_t i_vAddr )
{
    // hash is an index into a virtual array of PTEGs
    uint64_t hash = computeHash(i_vAddr); //right-justified

    // mask off the hash to fit into the table
    hash = hash % PTEG_COUNT;

    // use the hash as the index into the array of PTEGs
    uint64_t pteg_addr = getAddress() + hash * PTEG_SIZE_BYTES;

    Dprintk( "PageTableManager::findPTEG(i_vAddr=0x%.16lX) = 0x%.16lX\n", i_vAddr, pteg_addr );
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
                                                             uint64_t i_ptegAddr )
{
    Tprintk( "PageTableManager::findPTE(i_vAddr=0x%.16lX,i_ptegAddr=0x%.16lX)>>\n", i_vAddr, i_ptegAddr );

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

    Dprintk( "<<PageTableManager::findPTE() = %.16lX>>\n", (uint64_t)pte_found );
    return pte_found;
}

/**
 * @brief  Write a PTE to memory and update caches appropriately
 */
void PageTableManager::writePTE( PageTableEntry* i_pte,
                                 PageTableEntry* i_dest,
                                 bool i_valid )
{
    // are we stealing a PTE
    bool pte_stolen = false;
    if( (i_dest->V == 1) && i_valid )
    {
        pte_stolen = true;
        printPTE( "Stealing", i_dest );
    }

    if(ivTABLE)
    {
        Dprintk( ">> PageTableManager::writePTE( i_dest=%p, i_valid=%d )  **FAKE**\n", i_dest, i_valid );
        memcpy( (void*) i_dest, (void*) i_pte, sizeof(PageTableEntry) );
        if( i_valid ) {
            i_dest->V = 1;
            //printPTE( "Writing", i_dest );
        } else {
            i_dest->V = 0;
            //printk( ">> PageTableManager::writePTE( i_dest=%p, i_valid=%d )  **FAKE**\n", i_dest, i_valid );
            //printPTE( "Removing", i_dest );
        }
    }
    else
    {
        Dprintk( ">> PageTableManager::writePTE( i_dest=0x%.lX, i_valid=%d )\n", i_dest, i_valid );

        //if( i_valid ) {
            //printPTE( "Writing", i_dest );
        //} else {
            //printPTE( "Removing", i_dest );
        //}

        i_dest->V = 0; /* (other fields don't matter) */

        /* order update before tlbie and before next Page Table search */
        asm volatile("ptesync" ::: "memory");

        // tlbie, eieio, tlbsync, ptesync
        invalidateTLB(i_pte);

        // if we're removing an entry we can ignore the other fields
        if( i_valid )
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
    updateLRU( i_dest );

    Dprintk( "<< PageTableManager::writePTE()\n" );
}


/**
 * @brief  Print out the contents of a PTE
 */
void PageTableManager::printPTE( const char* i_label,
                                 const PageTableEntry* i_pte,
                                 bool i_verbose )
{
    if( i_pte == NULL )
    {
        if( i_label ) { printk( "%s :: ", i_label ); }
        printk( "NULL PTE\n" );
        return;
    }

    uint64_t pte_num = (((uint64_t)i_pte) - getAddress()) / sizeof(PageTableEntry);

    if( i_label ) { printk( "%s :: ", i_label ); }
    if( i_verbose )
    {
        printk( "[%4ld:%4ld]> @%p\n", pte_num/PTEG_SIZE, pte_num%PTEG_SIZE, i_pte );
        printk( "Dword  : %.16lX %.16lX\n", ((uint64_t*)i_pte)[0], ((uint64_t*)i_pte)[1] );
        printk( "-AVA   : 0x%.14lX\n", i_pte->AVA );
        printk( "-SW    : %ld\n", i_pte->SW );
        printk( "-LRU   : %ld\n", i_pte->LRU );
        printk( "-V     : %ld\n", i_pte->V );
        printk( "-RC    : %ld%ld\n", i_pte->R, i_pte->C );
        printk( "-WIMG  : 0x%.1lX\n", i_pte->WIMG );
        printk( "-pp0   : %ld\n", i_pte->pp0 );
        printk( "-pp1_2 : %ld\n", i_pte->pp1_2 );
        printk( "-PN    : %ld\n", i_pte->PN );
    }
    else
    {
        printk( "[%4ld:%4ld]> @%p : %.16lX %.16lX : AVA=%16lX, PN=%ld\n", pte_num/PTEG_SIZE, pte_num%PTEG_SIZE, i_pte, i_pte->dword0, i_pte->dword1, i_pte->AVA, i_pte->PN );
    }

}


/**
 * @brief  Print out the entire Page Table
 */
void PageTableManager::_printPT( void )
{
    printk( "- -Page Table --\n" );
    uint64_t pt_addr = getAddress();
    PageTableEntry* pte = (PageTableEntry*) pt_addr;
    printk( "@%p..0x%.16lX\n", pte, pt_addr +  getSize() );

    uint64_t num_ptes = getSize() / sizeof(PageTableEntry);
    for( uint64_t x = 0; x < num_ptes; x++ )
    {
        if( pte->V == 1 )
        {
            printPTE( NULL, pte );
        }

        pte++;
    }

    printk( "-- End Page Table --\n" );
}

/**
 * @brief  Return the real address of the page table in memory
 */
uint64_t PageTableManager::getAddress( void )
{
    if(ivTABLE) {
        return (uint64_t)ivTABLE;
    } else {
        return VmmManager::HTABORG;
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
                                      VmmManager::ACCESS_TYPES i_accessType )
{
    o_pte->dword1 &= ~PTE_ACCESS_BITS;
    if( VmmManager::NO_USER_ACCESS == i_accessType ) {
        o_pte->WIMG = 0b0010; // Memory Coherency Required
        o_pte->N = 0b1;       // No Execute
    } else if( VmmManager::READ_O_ACCESS == i_accessType ) {
        o_pte->WIMG = 0b0010; // Memory Coherency Required
        o_pte->pp1_2 = 0b01;  // PP=001
        o_pte->N = 0b1;       // No Execute
    } else if( VmmManager::NORMAL_ACCESS == i_accessType ) {
        o_pte->WIMG = 0b0010; // Memory Coherency Required
        o_pte->pp1_2 = 0b10;  // PP=010
        o_pte->N = 0b0;       // @TODO Change to 'No Execute' when VFS supports.
    } else if( VmmManager::CI_ACCESS == i_accessType ) {
        o_pte->WIMG = 0b0101; // Cache Inhibited, Guarded
        o_pte->pp1_2 = 0b10;  // PP=010
        o_pte->N = 0b1;       // No Execute
    } else if( VmmManager::RO_EXE_ACCESS == i_accessType ) {
        o_pte->WIMG = 0b0010; // Memory Coherency Required
        o_pte->pp1_2 = 0b01;  // PP=001
        o_pte->N = 0b0;       // Execute
    } else {
        //@fixme - add RO_EXE_ACCESS
        Eprintk( "** unrecognized access=%d\n", i_accessType );
    }
}

/**
 * @brief  Convert the bits from a PTE into a ACCESS_TYPES
 */
VmmManager::ACCESS_TYPES PageTableManager::getAccessType( const PageTableEntry* i_pte )
{
    if( i_pte->pp0 == 0b0 )
    {
        if( (i_pte->WIMG == 0b0101) && (i_pte->pp1_2 == 0b10) )
        {
            return VmmManager::CI_ACCESS;
        }
        else if( (i_pte->WIMG == 0b0010) && (i_pte->pp1_2 == 0b00) )
        {
            return VmmManager::NO_USER_ACCESS;
        }
        else if( (i_pte->WIMG == 0b0010) && (i_pte->pp1_2 == 0b01) )
        {
            return VmmManager::READ_O_ACCESS;
        }
        else if( (i_pte->WIMG == 0b0010) && (i_pte->pp1_2 == 0b10) )
        {
            return VmmManager::NORMAL_ACCESS;
        }
        //@fixme - add RO_EXE_ACCESS
    }

    Eprintk( "I don't recognize this PTE : WIMG=%ld, pp1_2=%ld\n", i_pte->WIMG, i_pte->pp1_2 );
    printPTE( "getAccessType", i_pte);
    kassert(false);
    return VmmManager::NO_USER_ACCESS;
}

/**
 * @brief  Fill in default values for the PTE
 */
void PageTableManager::setupDefaultPTE( PageTableEntry* o_pte )
{
    o_pte->B = 0b01;  //Segment Size  (01=1TB)
    o_pte->L = 0b0;   //Virtual page size  (1=>4KB)
    o_pte->H = 0b0;   //Hash function identifier  (0=primary hash)
}

/**
 * @brief  Find the real address of a PTE that that is empty or invalid
 */
PageTableManager::PageTableEntry* PageTableManager::findEmptyPTE( uint64_t i_ptegAddr )
{
    Tprintk( "PageTableManager::findEmptyPTE(i_ptegAddr=0x%.16lX)>>\n", i_ptegAddr );

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
PageTableManager::PageTableEntry* PageTableManager::findOldPTE( uint64_t i_ptegAddr )
{
    // Order of preference for PTE slots to steal:
    // 1) PTE with highest use count (LRU==SW[2:3])
    // 2) Lowest PTE with the highest use count
    PageTableEntry* pte = (PageTableEntry*)i_ptegAddr;
    PageTableEntry* old_pte = pte;
    for( uint64_t x = 0; x < 8; x++ )
    {
        if( pte->LRU > old_pte->LRU )
        {
            old_pte = pte;
        }

        pte++;
    }
    PageTableManager::printPTE( "Dropping PTE", old_pte );

    return old_pte;
}

/**
 * @brief Update the LRU statistics for other PTEs in the same PTEG as the target
 */
void PageTableManager::updateLRU( const PageTableEntry* i_newPTE )
{
    Tprintk( ">> PageTableManager::updateLRU( i_newPTE=%p )\n", i_newPTE );

    // find the beginning of the PTEG
    uint64_t pteg_addr = (((uint64_t)i_newPTE) - getAddress()) / PTEG_SIZE_BYTES;
    pteg_addr = pteg_addr*PTEG_SIZE_BYTES + getAddress();

    // loop through all 8 PTEs in the PTEG
    PageTableEntry* pte_cur = (PageTableEntry*)pteg_addr;
    for( uint64_t x = 0; x < 8; x++ )
    {
        // skip the entry we just added
        if( pte_cur != i_newPTE )
        {
            PageTableEntry new_pte = *pte_cur;
            PageTableEntry old_pte = *pte_cur;

            // use this funny loop to avoid races where another thread
            //  is causing the C bit to be updated at the same time
            do {
                new_pte = *pte_cur;
                old_pte = *pte_cur;

                if( (new_pte.V == 1) && (new_pte.R == 1) )
                {
                    new_pte.LRU = 1;
                    new_pte.R = 0;
                }
                else
                {
                    if( new_pte.LRU < 0b11 )
                    {
                        new_pte.LRU++;
                    }
                }
            } while( !__sync_bool_compare_and_swap( &(pte_cur->dword0),
                                                    old_pte.dword0,
                                                    new_pte.dword0 ) );

            // tlbie, eieio, tlbsync, ptesync
            invalidateTLB(pte_cur);
        }

        pte_cur++;
    }

    Tprintk( "<< PageTableManager::updateLRU(\n" );
}

/**
 * @brief Invalidate TLB for a PTE
 */
void PageTableManager::invalidateTLB( PageTableEntry* i_pte )
{
    Tprintk( ">> PageTableManager::invalidateTLB( i_pte=%p )\n", i_pte );

    if( ivTABLE == NULL )
    {
        /*invalidate old translation*/
        //tlbie(old_B,old_VA[14:77-b],old_L,old_LP,old_AP,old_LPID);
        // TLBIE isn't correct in gcc, hand code asm.
        register uint64_t rS = 0, rB = 0;
        rB = (i_pte->AVA * 0x000FFFFFFFFFFFFF) << 12; // Put in rB[0:51]
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

