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
