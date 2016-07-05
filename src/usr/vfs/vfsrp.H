/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vfs/vfsrp.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#ifndef VFSRP_H
#define VFSRP_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <sys/msg.h>
#include <vector>
#include <sys/sync.h>

// Forward declarations
struct msg_t;
class SecureROMTest;

namespace VFS
{
    // Size of a single entry (in Bytes) in a PNOR hash page table.
    // Set in buildpnor.pl
    const size_t HASH_PAGE_TABLE_ENTRY_SIZE = 32;
    typedef uint8_t PAGE_TABLE_ENTRY_t[HASH_PAGE_TABLE_ENTRY_SIZE];

    void vfs_msg_handler(void * unused);

    /**
     * Virtual File System Service
     */
    class VfsRp
    {
        public:

            /**
             * static init
             * @param[in] task args
             */
            static void init( errlHndl_t &io_taskRetErrl );

            /**
             * Get the list of test modules
             * @param[out] list of test module names
             */
            void get_test_modules(std::vector<const char *> & o_list) const;

            /**
             * Test for existence of module
             * @param[in] i_name module name
             * @return [true|false]
             */
            bool module_exists(const char * i_name) const;

            /**
             * get VfsSystemModule information
             * @param[in] i_name module name
             * @return pointer to VfsSystemModule entree
             *         or NULL if not found
             */
            const VfsSystemModule * get_vfs_info(const char * i_name) const;

            /**
             * Get the module name that contains the given address
             * @param[in] i_vaddr The virtual address
             * @return ptr to the module name or NULL if it's not found
             */
            const char * get_name_from_address(const void * i_vaddr) const;

            /**
             * Query if a module is loaded
             * @param[in] i_name  The module name
             * @return [true|false]
             */
            bool is_module_loaded(const char * i_name);

        protected:
            /**
             * Ctor
             */
            VfsRp() : iv_msgQ(NULL), iv_msg(NULL), iv_pnor_vaddr(0),
                      iv_hashPageTableOffset(0),iv_hashPageTableSize(0)
            {
                mutex_init(&iv_mutex);
            }

            /**
             * Dtor
             */
            ~VfsRp();

            /**
             * Start message handler
             */
            static void* msg_handler(void * unused);

            /**
             * Load or Unload a module. Monitor for crash
             * @param[in] i_msg the message
             * @note Does not return.
             */
            static void* loadUnloadMonitored(void * i_msg);

            /**
             * Load or Unload a module
             * @param[in] i_msg the message
             */
            static void* loadUnload(void * i_msg);

            /**
             * Call _start on module. Montior for crash
             * @param[in] i_msg the message
             * @note Does not return.
             */
            static void* execMonitored(void * i_msg);

            /**
             * Call _start on module
             * @param[in] i_msg the message
             */
            static void* exec(void * i_msg);

            /**
             * Start the VFS resource provider message handler
             * and watch for crashes.
             */
            static void* vfsWatcher(void * unused);

        private: // functions

            /**
             * Initialize this object
             * @return return code on error
             */
            errlHndl_t _init();

            /**
             * Message handler
             */
            void msgHandler();

            /**
             * Load or Unload a module. Monitor for task crash
             * @parm[in] The message
             */
            void _loadUnloadMonitored(msg_t * i_msg);

            /**
             * Load or Unload a module
             * @param[in] i_msg the message
             */
            void _loadUnload(msg_t * i_msg);

            /**
             * Call _start on module
             * @param[in] i_msg the message
             */
            void _exec(msg_t * i_msg);

            /**
             * Call _start on Module. Montor for task crash
             * @param[in] The message
             */
            void _execMonitored(msg_t * i_msg);

            /**
             * Message Handler task watcher
             */
            void _vfsWatcher();

            /**
             * Verify page using secure hash page table
             *
             * @param[in] i_vaddr address to verify
             * @param[in] i_baseOffset base offset within a PNOR section
             *                         [Optional - Used by test cases]
             * @param[in] i_hashPageTableOffset hash page table offset based on
             *                          iv_pnor_vaddr
             *                         [Default to 0 when called within VfsRP,
             *                          Filled in by test cases]
             *
             * @return return code on error
             */
            uint64_t verify_page(uint64_t i_vaddr,
                                 uint64_t i_baseOffset = 0,
                                 uint64_t i_hashPageTableOffset = 0) const;

            /**
             * @brief  Determines the hash page table index associated with a
             *         vaddr. The hash page table has n-pages + 1 entries.
             *
             * @param[in] i_vaddr  Vaddr the caller is accessing,
             * @param[in] i_baseOffset base offset within a PNOR section
             *                         [Optional - Used by test cases]
             *
             * @return index of the hash page table
             */
            inline size_t getHashPageTableIndex (uint64_t i_vaddr,
                                                uint64_t i_baseOffset = 0) const
            {
                assert(i_baseOffset <= i_vaddr);
                return ( (i_vaddr - i_baseOffset) / PAGE_SIZE) + 1;
            }

            /**
             * @brief  Returns a hash page table entry
             *
             * @param[in] i_pageTableVaddr  Vaddr the caller is accessing
             * @param[in] i_baseOffset base offset within a PNOR section
             *                         [Optional - Used by test cases]
             * @param[in] i_hashPageTableOffset hash page table offset.
             *                         [Default to 0 when called within VfsRP]
             *                          Filled in by test cases]
             *
             * @return single entry of hash page table
             */
            inline PAGE_TABLE_ENTRY_t* getHashPageTableEntry(uint64_t i_vaddr,
                                    uint64_t i_baseOffset = 0,
                                    uint64_t i_hashPageTableOffset = 0) const
            {
                size_t l_index = getHashPageTableIndex(i_vaddr, i_baseOffset);
                size_t l_offset = l_index * HASH_PAGE_TABLE_ENTRY_SIZE;

                // Decide whether to use the internal or passed in value for
                // hash page table offset.
                size_t l_hashPageTableOffset = (i_hashPageTableOffset == 0) ?
                                iv_hashPageTableOffset :
                                iv_pnor_vaddr + i_hashPageTableOffset;
                return reinterpret_cast<PAGE_TABLE_ENTRY_t*>
                                            (l_hashPageTableOffset+l_offset);
            }

        private: // data

            msg_q_t iv_msgQ;         //!< message queue
            msg_t*  iv_msg;          //!< Current message being handled
            uint64_t iv_pnor_vaddr;  //!< virtual address of ext image in PNOR
            uint64_t iv_hashPageTableOffset; //!< virtual address of hashPageTable of ext image
            uint64_t iv_hashPageTableSize; //!< size of hashPageTable of ext image

            typedef std::vector<VfsSystemModule *> ModuleList_t;

            mutex_t iv_mutex;       //!< lock for iv_loaded
            ModuleList_t iv_loaded; //!< Loaded modules

            friend class ::SecureROMTest;
            /**
             * @brief Static instance function
             */
            static VfsRp& getInstance();

    };

}; // VFS namepsace

#endif
