/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vfs/vfsrp.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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

struct msg_t;

namespace VFS
{
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
            VfsRp() : iv_msgQ(NULL), iv_msg(NULL), iv_pnor_vaddr(0)
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

        private: // data

            msg_q_t iv_msgQ;         //!< message queue
            msg_t*  iv_msg;          //!< Current message being handled
            uint64_t iv_pnor_vaddr;  //!< virtual address of ext image in PFNOR

            typedef std::vector<VfsSystemModule *> ModuleList_t;

            mutex_t iv_mutex;       //!< lock for iv_loaded
            ModuleList_t iv_loaded; //!< Loaded modules
    };

}; // VFS namepsace

#endif
