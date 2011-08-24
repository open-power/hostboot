//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/vfs/vfsrp.H $
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
#ifndef VFSRP_H
#define VFSRP_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errltypes.H>

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
            static void init(void * i_taskArgs);

        protected:
            /**
             * Ctor
             */
            VfsRp() : iv_msgQ(NULL), iv_pnor_vaddr(0) {}

            /**
             * Dtor
             */
            ~VfsRp();

            /**
             * Start message handler
             */
            static void msg_handler(void * unused);

            /**
             * Load or Unload a module
             * @param[in] i_msg the message
             * @note Does not return. calls task_end()
             */
            static void load_unload(void * i_msg);

            /**
             * Call _start on module
             * @param[in] i_msg the message
             * @note Does not return. calls task_end()
             */
            static void exec(void * i_msg);

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
             * Load or Unload a module
             * @param[in] i_msg the message
             */
            void _load_unload(msg_t * i_msg);

            /**
             * Call _start on module
             * @param[in] i_msg the message
             */
            void _exec(msg_t * i_msg);

        private: // data

            msg_q_t iv_msgQ;         //!< message queue
            uint64_t iv_pnor_vaddr;  //!< virtual address of ext image in PFNOR
    };

}; // VFS namepsace

#endif
