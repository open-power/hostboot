//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/heapmgr.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
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
#ifndef __KERNEL_HEAPMGR_H
#define __KERNEL_HEAPMGR_H

#include <stdint.h>
#include <util/lockfree/stack.H>
#include <builtins.h>

extern "C"
void kernel_execute_decrementer();

/**
 * A class to manage the dynamic memory allocation heap.
 * <p>There is a small allocation heap and a large heap.
 * The Small allocation heap is a Fibonacci buddy system divided into the
 * following bucket sizes: 16,32,48,80,128,208,336,544,880,1424,2304,3728.
 * Eight bytes is used for overhead in each allocation making the effective
 * bucket sizes  8,24,40,72,120,200,328,536,872,1416,2296, and 3720.
 * The small heap increases one page at a time as allocations are needed.
 * A 4k pages is initially divided into buckes of size 3728,336, and 32.
 * Pages can't be recovered once assinged to the small heap.</p>
 * 
 * <p>Anthing larger than 3720 goes into the large allocation heap.
 * Memory in the large allocation heap are assigned as integral pages.
 * When memory is released from the large allocation heap, it is returned
 * to the system page manager.</p>
 */
class HeapManager
{
    public:
        enum
        {
            BUCKETS             = 12,   //!< number of buckets
            MIN_BUCKET_SIZE     = 16,   //!< Smallest bucket size
            FIB_START_INCR      = 16,   //!< Seed for the Fibonacci series
            BUCKET_SIZE0        = MIN_BUCKET_SIZE,
            BUCKET_SIZE1        = BUCKET_SIZE0 + FIB_START_INCR,
            BUCKET_SIZE2        = BUCKET_SIZE1 + BUCKET_SIZE0,
            BUCKET_SIZE3        = BUCKET_SIZE2 + BUCKET_SIZE1,
            BUCKET_SIZE4        = BUCKET_SIZE3 + BUCKET_SIZE2,
            BUCKET_SIZE5        = BUCKET_SIZE4 + BUCKET_SIZE3,
            BUCKET_SIZE6        = BUCKET_SIZE5 + BUCKET_SIZE4,
            BUCKET_SIZE7        = BUCKET_SIZE6 + BUCKET_SIZE5,
            BUCKET_SIZE8        = BUCKET_SIZE7 + BUCKET_SIZE6,
            BUCKET_SIZE9        = BUCKET_SIZE8 + BUCKET_SIZE7,
            BUCKET_SIZE10       = BUCKET_SIZE9 + BUCKET_SIZE8,
            BUCKET_SIZE11       = BUCKET_SIZE10 + BUCKET_SIZE9,

            MAX_SMALL_ALLOC_SIZE      = BUCKET_SIZE11 - 8,// last bucket size-8
        };

        friend class CpuManager;
        friend void kernel_execute_decrementer();

        /**
         * Initalize the HeapManager
         */
        static void init();

        /**
         * Reqest an allocation of heap memory
         * @param[in] i_sz  requested memory size in bytes
         * @return a pointer to allocated memory
         */
        static void* allocate(size_t i_sz);

        /**
         * Request a change in allocation size
         * @param[in] i_ptr The memory allocation
         * @param[in] i_sz  The new size
         * @return a pointer to allocated memory
         * @post Memory may have been moved
         */
        static void* realloc(void * i_ptr, size_t i_sz);

        /**
         * Return an allocation to the heap.
         * @param[in] The allocation
         */
        static void  free(void * i_ptr);


    protected:

        /**
         * ctor
         */
        HeapManager() {};

        /**
         * dtor
         */
        ~HeapManager() {};

        /**
         * Coalesce unallocated memory chucks
         * @pre This function can only be called from kernel space and
         * requires that all other processes are quiesced
         */
        static void coalesce( void );

        /**
         * Print some stats to printkd
         * @pre system quiesced, This function can only be called from
         *      kernel space.
         * @post coalesce() called
         */
        static void stats( void );

    private:

        struct chunk_t
        {
            struct
            {
                bool    free:1;         //!< Is chunck free
                uint64_t bucket:63;     //!< Which bucket this chunk belongs to
            } PACKED;
            
            chunk_t* next;      //!< Next chunk (for unallocated chunks only)
        };

        /**
         * big chunk directory entry
         */
        struct big_chunk_t
        {
            void * addr;        //!< Allocated address
            size_t page_count;  //!< Number of pages used
            big_chunk_t * next; //!< Next allocation

            big_chunk_t(void * i_ptr, size_t i_pages) 
                : addr(i_ptr), page_count(i_pages), next(NULL) {}
        };

        void* _allocate(size_t);        //!< see allocate
        void* _allocateBig(size_t);     //!< see allocate
        void* _realloc(void*,size_t);   //!< see realloc
        void* _reallocBig(void*,size_t);//!< see realloc
        void _free(void*);              //!< see free
        bool _freeBig(void*);           //!< see free
        void _coalesce(void);           //!< see coalesce

        /**
         * Get a chunk of free memory from the given bucket
         * @param[in] The bucket index
         * @return  a chunk
         */
        chunk_t* pop_bucket(size_t);

        /**
         * Push a free chunk onto the free bucket stack
         * @param[in] the chunk
         * @param[in] the bucket index
         */
        void push_bucket(chunk_t*, size_t);

        /**
         * Get a new page from the page manager, set it up, and addit it to the
         * free pool
         */
        void newPage();

        /**
         * Get the bytesize of the given bucket
         * @param[in] The bucket index
         * @return the bytesize of the bucket
         */
        ALWAYS_INLINE
            size_t bucketByteSize(size_t i_bucketIndex)
            {
                return cv_chunk_size[i_bucketIndex];
            }

        /**
         * Get the bucket index for a given size
         * @param[in] The bytesize
         * @return the smallest bucket index that the given size will fit into
         */
        size_t bucketIndex(size_t i_sz);

        /**
         * Walk through all the allocated pages and verify coherency
         */
        void test_pages();

    private: // data

        Util::Lockfree::Stack<chunk_t> first_chunk[BUCKETS]; //!< free pool
        Util::Lockfree::Stack<big_chunk_t> big_chunk_stack;  //!< big chunk dir

        static const size_t cv_chunk_size[BUCKETS];//!< The bucket sizes
        static uint32_t cv_coalesce_count;       //!< coalesced chunk count
        static uint32_t cv_free_bytes;           //!< Only valid after coalesce()
        static uint32_t cv_free_chunks;          //!< Only valid after coalesce()
        static uint32_t cv_smallheap_page_count; //!< # of pages being used
        static uint32_t cv_largeheap_page_count; //!< # of pages being used
        static uint32_t cv_largeheap_page_max;   //!< Max # of pages used
};
#endif
