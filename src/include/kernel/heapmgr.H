/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/heapmgr.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2024                        */
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
#ifndef __KERNEL_HEAPMGR_H
#define __KERNEL_HEAPMGR_H

#include <stdint.h>
#include <builtins.h>
#include <kernel/types.h>

#ifndef __HOSTBOOT_RUNTIME
#include <util/lockfree/stack.H>
#endif

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
            CHUNK_HEADER_PLUS_RESERVED = 9, //!< 8 Bytes header + 1 byte valid
        };

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

            // last bucket size, 8 byte chunk header + 1 byte for consistency
            // checking
            MAX_SMALL_ALLOC_SIZE      = BUCKET_SIZE11 - CHUNK_HEADER_PLUS_RESERVED,
            MAX_BIG_ALLOC_SIZE        = 20*PAGESIZE,

            // Constants for Huge Chunk support
            HC_SLOT_SIZE   = 3*MEGABYTE,  //!< Max size of a single allocation
            HC_NUM_SLOTS   = 20,  //!< Number of available allocations
            HC_TOTAL_SIZE  = (HC_SLOT_SIZE*HC_NUM_SLOTS),  //! Total size
        };

// we only want the constants in HBRT
#ifndef __HOSTBOOT_RUNTIME
        friend class CpuManager;
        friend void kernel_execute_decrementer();

        /**
         * Initalize the HeapManager
         */
        static void init();

        /**
         * Request an allocation of heap memory
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

        /**
         * Add pointers to the global debug area
         */
        static void addDebugPointers();

        /**
         * Coalesce unallocated memory chucks
         * @pre This function can only be called from kernel space and
         * requires that all other processes are quiesced
         */
        static void coalesce( void );

        /**
         * @brief Copy statistics data from memory to o_stats
         * @param[out] o_stats  The memory block to copy statistics data into
         */
        static void get_stats(struct kmem_trc_data &o_stats);

    protected:

        /**
         * ctor
         */
        HeapManager() {};

        /**
         * dtor
         */
        ~HeapManager() {};


    private:

        struct chunk_t
        {
            struct
            {
                uint8_t     free;       //!< F=free, A=allocated
                uint8_t     coalesce;   //!< C=chunk being coalesced
                uint16_t    size;       //!< size of the data area
                tid_t       allocator;  //!< task_id of allocating thread
                uint16_t    bucket;     //!< Which bucket this chunk belongs to
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

        /**
         * huge chunk directory entry
         */
        struct huge_chunk_t
        {
            void * addr;        //!< Allocated address
            size_t page_count;  //!< Number of pages used
            huge_chunk_t * next; //!< Next allocation

            huge_chunk_t(void * i_ptr, size_t i_pages)
                : addr(i_ptr), page_count(i_pages), next(nullptr) {}
        };

        /**
         * @brief used in coalesce for temp list of chunks
         */
        struct chunk_list_t
        {
            chunk_t head;
            int     size;

            chunk_list_t() {clear();}
            void clear()
            {
                head.next = nullptr;
                size      = 0;
            }
            chunk_t* get_head()
            {
                return head.next;
            }
            void push(chunk_t *c)
            {
                size++;
                c->next   = head.next;
                head.next = c;
            }
            chunk_t* pop()
            {
                if (head.next == nullptr)
                {
                    return nullptr;
                }
                chunk_t *save{nullptr};
                size--;
                save       = head.next;
                head.next  = head.next->next;
                save->next = nullptr;
                return save;
            }
        };

        void* _allocate(size_t);        //!< see allocate
        void* _allocateBig(size_t);     //!< see allocate
        void* _allocateHuge(size_t);    //!< see allocate
        void* _realloc(void*,size_t);   //!< see realloc
        void* _reallocBig(void*,size_t);//!< see realloc
        void* _reallocHuge(void*,size_t);//!< see realloc
        void _free(void*);              //!< see free
        bool _freeBig(void*);           //!< see free
        bool _freeHuge(void*);          //!< see free
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
                return iv_chunk_size[i_bucketIndex];
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

        /**
         * Add pointers to the global debug area
         */
        void _addDebugPointers();

        uint64_t iv_hugeblock_allocated{0};          //!< Huge Block allocated
        uint64_t cv_hugeblock_page_count{0};         //!< # of pages being used
        uint64_t cv_hugeblock_page_max{0};           //!< Max # of pages used
        uint64_t cv_largeheap_page_count{0};         //!< # of pages being used
        uint64_t cv_largeheap_page_max{0};           //!< Max # of pages used
        uint64_t cv_smallheap_page_count{0};         //!< # of pages being used
        uint64_t cv_smallheap_alloc_hw{0};           //!< allocated high water
        uint64_t cv_smallheap_allocated{0};          //!< sum of chunk bytes allocated
        uint64_t cv_smallheap_user_allocated{0};     //!< sum of user bytes allocated
        uint64_t cv_smallheap_coalesce_state{0};     //!< 1 if a coalesce is running, else 0
        uint64_t cv_smallheap_coalesce_attempts{0};  //!< coalesced attempts
        uint64_t cv_smallheap_coalesce_count{0};     //!< coalesced chunk count
        uint64_t cv_smallheap_coalesce_page{0};      //!< coalesced page count
        uint64_t cv_free_bucket_counts [BUCKETS]={}; //!< free chunks
        uint64_t cv_inuse_bucket_counts[BUCKETS]={}; //!< alloc chunks in use
        uint64_t cv_alloc_sizes        [BUCKETS]={}; //!< total alloc chunks
        uint64_t iv_chunk_size         [BUCKETS]={HeapManager::BUCKET_SIZE0,
                                                  HeapManager::BUCKET_SIZE1,
                                                  HeapManager::BUCKET_SIZE2,
                                                  HeapManager::BUCKET_SIZE3,
                                                  HeapManager::BUCKET_SIZE4,
                                                  HeapManager::BUCKET_SIZE5,
                                                  HeapManager::BUCKET_SIZE6,
                                                  HeapManager::BUCKET_SIZE7,
                                                  HeapManager::BUCKET_SIZE8,
                                                  HeapManager::BUCKET_SIZE9,
                                                  HeapManager::BUCKET_SIZE10,
                                                  HeapManager::BUCKET_SIZE11};

        Util::Lockfree::Stack<chunk_t> first_chunk[BUCKETS]; //!< free pool
        Util::Lockfree::Stack<big_chunk_t> big_chunk_stack;  //!< big chunk dir
        Util::Lockfree::Stack<huge_chunk_t> huge_chunk_stack; //!< huge chunks

#endif //__HOSTBOOT_RUNTIME

};
#endif
