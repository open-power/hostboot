/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vfs/vfsrp.C $                                         */
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
/**
 * @file vfsrp.C
 * @brief Virtual File system Extended image support
 */

#include <limits.h>
#include <string.h>
#include <errno.h>
#include <sys/vfs.h>
#include <vfs/vfs.H>
#include <vfs/vfs_reasoncodes.H>
#include <sys/task.h>
#include <sys/mm.h>
#include <initservice/taskargs.H>
#include <trace/interface.H>
#include "vfsrp.H"
#include <pnor/pnorif.H>
#include <util/align.H>
#include <errl/errludstring.H>
#include <errl/errlmanager.H>
#include <secureboot/service.H>
#include <secureboot/containerheader.H>
#include <kernel/console.H>
#include <errl/errludprintk.H>

using namespace VFS;

// Trace definitions
trace_desc_t * g_trac_vfs = NULL;
TRAC_INIT(&g_trac_vfs, VFS_COMP_NAME, KILOBYTE, TRACE::BUFFER_SLOW);

/**
 * setup _start and handle barrier
 */
TASK_ENTRY_MACRO( VfsRp::init );

// ----------------------------------------------------------------------------

VfsRp::~VfsRp()
{
    // Unloading of this module currently not supported.
    // unregister msg queue?  Currently can't do that
    // msg_q_destroy(iv_msgQ);
}

// ----------------------------------------------------------------------------

/**
 * STATIC initializer of vfs resource provider entry point
 */
void VfsRp::init( errlHndl_t &io_taskRetErrl )
{
    errlHndl_t err = NULL;

    err = Singleton<VfsRp>::instance()._init();


    io_taskRetErrl= err ;
}
// ----------------------------------------------------------------------------

/**
 * Helper function to start vfs messge handler
 */
void* VfsRp::msg_handler(void * unused)
{
    Singleton<VfsRp>::instance().msgHandler();
    return NULL;
}

// ----------------------------------------------------------------------------

void * VfsRp::vfsWatcher(void * unused)
{
    Singleton<VfsRp>::instance()._vfsWatcher();
    return NULL;
}

// ----------------------------------------------------------------------------

void* VfsRp::loadUnloadMonitored(void * i_msg)
{
    task_detach();
    Singleton<VfsRp>::instance()._loadUnloadMonitored((msg_t*)i_msg);
    return NULL;
}

// ----------------------------------------------------------------------------

void* VfsRp::loadUnload(void * i_msg)
{
    Singleton<VfsRp>::instance()._loadUnload((msg_t*)i_msg);
    return NULL;
}

// ----------------------------------------------------------------------------

void* VfsRp::execMonitored(void * i_msg)
{
    task_detach();
    Singleton<VfsRp>::instance()._execMonitored((msg_t*)i_msg);
    return NULL;
}

// ----------------------------------------------------------------------------

void* VfsRp::exec(void * i_msg)
{
    Singleton<VfsRp>::instance()._exec((msg_t*)i_msg);
    return NULL;
}
/**
 * Initialze the vfs resource provider
 */
errlHndl_t VfsRp::_init()
{
    errlHndl_t err = NULL;
    size_t rc = 0;

    do {

    iv_msgQ = msg_q_create();
    rc = msg_q_register(iv_msgQ, VFS_ROOT_MSG_VFS);
    assert(rc == 0,"Msg Queue Registration failed in VFS");

#ifdef CONFIG_SECUREBOOT
    err = loadSecureSection(PNOR::HB_EXT_CODE);
    if(err)
    {
        break;
    }
#endif

    // Discover PNOR virtual address of extended image
    PNOR::SectionInfo_t l_pnor_info;
    err = PNOR::getSectionInfo(PNOR::HB_EXT_CODE, l_pnor_info);
    if(err)
    {
        break;
    }

    iv_pnor_vaddr = l_pnor_info.vaddr;
    iv_hbExtSecure = l_pnor_info.secure;
#ifdef CONFIG_SECUREBOOT
    // Assume if HBI is signed it also has a hash page table.
    if (iv_hbExtSecure)
    {
        // store the hash page table offset for reference
        iv_hashPageTableOffset = iv_pnor_vaddr;

        // Extract total protected payload size from header
        iv_protectedPayloadSize = l_pnor_info.secureProtectedPayloadSize;

        // calculate the hash page table size
        iv_hashPageTableSize = iv_protectedPayloadSize - VFS_MODULE_TABLE_SIZE;
        TRACFCOMP(g_trac_vfs, "VfsRp::_init HB_EXT total payload_text_size = 0x%X, hash page table size = 0x%X",
                  l_pnor_info.secureProtectedPayloadSize,
                  iv_hashPageTableSize);
        // skip the hash page table
        iv_pnor_vaddr += iv_hashPageTableSize;

        // Compute offset to the unprotected payload virtual address range.
        // This offset should be subtracted from the secure address
        iv_unprotectedOffset = VMM_VADDR_SPNOR_DELTA+VMM_VADDR_SPNOR_DELTA;
    }
#endif

    rc = mm_alloc_block
        (iv_msgQ,
         (void *)VFS_EXTENDED_MODULE_VADDR,
         ALIGN_PAGE(l_pnor_info.size)
        );
    if(rc == 0)
    {
        // Note: permissions are set elsewhere

        // Start msg_handler task watcher
        //  NOTE: This would be a weak consistancy issues if
        //  task_create were not a system call.
        task_create(VfsRp::vfsWatcher, NULL);
    }
    else
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        VFS_MODULE_ID
         * @reasoncode      VFS_ALLOC_VMEM_FAILED
         * @userdata1       returncode from mm_alloc_block()
         * @userdata2       Size of memory to allocate
         *
         * @devdesc         Could not allocate virtual memory.
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
             VFS::VFS_MODULE_ID,                     //  moduleid
             VFS::VFS_ALLOC_VMEM_FAILED,             //  reason Code
             rc,                                     //  user1 = rc
             l_pnor_info.size,                       //  user2 = size
             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT,
             ERRORLOG::ErrlEntry::FORCE_DUMP
            );
        break;
    }
    } while (0);

    return err;
}


// ----------------------------------------------------------------------------

void VfsRp::_vfsWatcher()
{

    while(1)
    {
        tid_t tid = task_create(VfsRp::msg_handler, NULL);
        assert( tid > 0 );

        int childsts = 0;
        void * childRc = NULL;

        // The msg_handler will only return if there is a problem
        tid_t tidRc = task_wait_tid( tid,
                                     &childsts,
                                     &childRc);

        TRACFCOMP(g_trac_vfs, ERR_MRK
                  "VFS msg_handler crashed. tid:%d status:%d childRc:%p. "
                  "Restarting VFS...",
                  tid, childsts, childRc);

        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        VFS_WATCHER
         * @reasoncode      VFS_TASK_CRASHED
         * @userdata1       tidRc
         * @userdata2       task Rc
         *
         * @devdesc         VFS RP Task crashed.
         * @custdesc  A problem was detected during the IPL of they system:
         *            Task crashed.
         *
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM, // severity
             VFS::VFS_WATCHER,                     // moduleid
             VFS::VFS_TASK_CRASHED,                // reason
             (uint64_t)tidRc,                      // tid rc
             (uint64_t)childRc,                    // child rc
             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT,
             ERRORLOG::ErrlEntry::FORCE_DUMP
            );

        // Add Printk Buffer for FFDC.
        ERRORLOG::ErrlUserDetailsPrintk().addToLog(err);

        // Message is only saved in iv_msg for messages from the kernel
        if(iv_msg != NULL)
        {
            if(childRc == NULL) // Critical error not yet reported
            {
                ERRORLOG::errlCommit(err, VFS_COMP_ID);
            }
            else // Crit error already generated
            {
                delete err;
                err = nullptr;
            }

            iv_msg->data[1] = -EIO;  /* I/O error */
            iv_msg->extra_data = childRc;  /* Critical code from PNOR */
            msg_respond(iv_msgQ, iv_msg);
            iv_msg = NULL;
        }
        else //nothing to respond to - just commit error and restar task
        {
            ERRORLOG::errlCommit(err, VFS_COMP_ID);
        }

        // Loop and restart the vfs msg_handler task
    }
}

// ----------------------------------------------------------------------------

void VfsRp::msgHandler()
{
    while(1)
    {
        iv_msg = NULL;
        msg_t* msg = msg_wait(iv_msgQ);

        switch(msg->type)
        {
            case VFS_MSG_LOAD:
                {
                    TRACDCOMP(g_trac_vfs, "Load request: %s",
                              (const char *) msg->data[0]);

                    // run in own task so page faults can be handled
                    task_create(loadUnloadMonitored, msg);
                }
                break;

            case VFS_MSG_UNLOAD:
                {
                    TRACDCOMP(g_trac_vfs, "Unload request: %s",
                              (const char *) msg->data[0]);

                    // run in own task so page faults can be handled
                    task_create(loadUnloadMonitored, msg);

                }
                break;

            case VFS_MSG_EXEC:
                {
                    TRACDCOMP(g_trac_vfs, "EXEC request: %s",
                           (const char*)((msg_t*)msg->data[0])->data[0]);

                    // run in own task so page faults can be handled
                    task_create(execMonitored, msg);

                }
                break;

            case MSG_MM_RP_READ:
                {
                    iv_msg = msg; // save message in case task crashes
                    uint64_t vaddr = msg->data[0]; //page aligned
                    uint64_t paddr = msg->data[1]; //page aligned
                    // Get relative virtual address within VFS space
                    vaddr-=VFS_EXTENDED_MODULE_VADDR;
                    do
                    {
#ifdef CONFIG_SECUREBOOT
                        if (SECUREBOOT::enabled() && iv_hbExtSecure)
                        {
                            errlHndl_t l_errl = verify_page(vaddr);
                            // Failed to pass secureboot verification
                            if(l_errl)
                            {
                                msg->data[1] = -EACCES;
                                SECUREBOOT::handleSecurebootFailure(
                                    l_errl, false, true);
                                break;
                            }
                        }
#endif
                        memcpy((void *)paddr, (void *)(iv_pnor_vaddr
                               -iv_unprotectedOffset+vaddr),
                               PAGE_SIZE);
                        mm_icache_invalidate((void*)paddr,PAGE_SIZE/8);
                        msg->data[1] = 0;
                    } while(0);
                }
                msg_respond(iv_msgQ, msg);
                break;

            case MSG_MM_RP_WRITE:
                assert(0);              // not supported now
                //msg->data[1] = 0;
                //msg_respond(iv_msgQ, msg);
                break;

            case MSG_MM_RP_PERM:
                msg->data[1] = -EINVAL;
                msg_respond(iv_msgQ, msg);
                break;

            default:
                msg_free(msg);
                break;
        }
    } // while(1)
}

// ----------------------------------------------------------------------------

void VfsRp::_loadUnloadMonitored(msg_t * i_msg)
{
    tid_t tid = task_create(VfsRp::loadUnload, i_msg);
    assert( tid > 0 );

    int childsts = 0;
    void * childRc = NULL;

    tid_t tidRc = task_wait_tid( tid,
                                 &childsts,
                                 &childRc);


    if(childsts == TASK_STATUS_CRASHED)
    {
        TRACFCOMP(g_trac_vfs, ERR_MRK
                  "VFS load/unload crashed. tid:%d status:%d childRc:%p",
                  tid, childsts, childRc);

        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        VFS_MODULE_LOAD_MONITOR
         * @reasoncode      VFS_TASK_CRASHED
         * @userdata1       tidRc
         * @userdata2       Task Status
         *
         * @devdesc         VFS Task crashed.
         * @custdesc  A problem was detected during the IPL of they system:
         *            Task crashed.
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,     // severity
             VFS::VFS_MODULE_LOAD_MONITOR,             // moduleid
             VFS::VFS_TASK_CRASHED,                    // reason Code
             (uint64_t)tidRc,                          // tid rc
             (uint64_t)childsts,                       // task status
             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT,
             ERRORLOG::ErrlEntry::FORCE_DUMP
            );

        // Add Printk Buffer for FFDC.
        ERRORLOG::ErrlUserDetailsPrintk().addToLog(err);

        if(childRc != NULL) // crit elog aleady generated
        {
            err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        // tell caller that load/unload failed
        i_msg->data[0] = reinterpret_cast<uint64_t>(err);
        msg_respond(iv_msgQ, i_msg);
    }
}

// ----------------------------------------------------------------------------

void VfsRp::_loadUnload(msg_t * i_msg)
{
    errlHndl_t err = NULL;

    // Find VfsSystemModule
    //  The TOC for the extended image sits at the start of the image and is
    //  not location dependent, so just use the one pointed to by iv_pnor_vaddr
    //  to avoid having to copy it to this block
    VfsSystemModule * module =
        vfs_find_module
        (
        (VfsSystemModule *)(iv_pnor_vaddr + VFS_EXTENDED_MODULE_TABLE_OFFSET),
         (const char *) i_msg->data[0]
        );

    if(module)
    {
        int rc = 0;

        // don't want the possibility of a function called in this module
        // until it's completely loaded and inited, so hold
        // off any query or other operation.
        mutex_lock(&iv_mutex);

        ModuleList_t::iterator mod_itr =
            std::find(iv_loaded.begin(),iv_loaded.end(),module);

        if(i_msg->type == VFS_MSG_LOAD)
        {
            if(mod_itr == iv_loaded.end()) // make sure it's not already loaded
            {
                // Set mem access parms
                rc = vfs_module_perms(module);
                if(!rc)
                {
                    iv_loaded.push_back(module);

                    if(module->init)
                    {
                        (module->init)(NULL);
                    }

                }
            }
        }
        else // unload
        {
            if(mod_itr != iv_loaded.end()) // Loaded
            {
                iv_loaded.erase(mod_itr);

                if(module->fini)
                {
                    (module->fini)(NULL);
                }

                rc = mm_set_permission(module->text,
                                       ALIGN_PAGE(module->byte_count),
                                       NO_ACCESS);

                rc = mm_remove_pages(RELEASE,
                                     module->text,
                                     ALIGN_PAGE(module->byte_count));
            }
            // else module was not loaded
        }

        mutex_unlock(&iv_mutex);

        if(rc)
        {
            /*@ errorlog tag
             * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid        VFS_MODULE_ID
             * @reasoncode      VFS_PERMS_VMEM_FAILED
             * @userdata1       returncode from mm_set_permission()
             * @userdata2       message type (LOAD or UNLOAD)
             *
             * @devdesc         Could not set permissions on virtual memory.
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                 VFS::VFS_MODULE_ID,                     //  moduleid
                 VFS_PERMS_VMEM_FAILED,                  //  reason Code
                 rc,                                     //  user1 = rc
                 i_msg->type,                            //  user2
                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT,
                 ERRORLOG::ErrlEntry::FORCE_DUMP );
        }
    }
    else
    {
        // Module does not exist in extended image.
        // If it exists then it is in the base image and it's already
        // initialized, however, we still should not be here, so put out a
        // trace msg;
        // If it does not exist anywhere then also create an error log
        TRACFCOMP(g_trac_vfs, ERR_MRK"load Module not found: %s",
                 (const char *) i_msg->data[0]);

        uint64_t * name = (uint64_t*)i_msg->data[0];

        if(!module_exists((const char *)i_msg->data[0]))
        {
            /*@ errorlog tag
             * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid        VFS_MODULE_ID
             * @reasoncode      VFS_MODULE_DOES_NOT_EXIST
             * @userdata1       first 8 bytes of module name
             * @userdata2       next 8 bytes of module name
             *
             * @devdesc         Requested module does not exist.
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                 VFS::VFS_MODULE_ID,                     //  moduleid
                 VFS_MODULE_DOES_NOT_EXIST,              //  reason Code
                 name[0],
                 name[1],
                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT,
                 ERRORLOG::ErrlEntry::FORCE_DUMP
                );
            err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH );
            err->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                      HWAS::SRCI_PRIORITY_LOW );
        }
    }
    i_msg->data[0] = (uint64_t) err;
    msg_respond(iv_msgQ, i_msg);
}

// ----------------------------------------------------------------------------

void VfsRp::_execMonitored(msg_t * i_msg)
{
    tid_t tid = task_create(VfsRp::exec, i_msg);
    assert( tid > 0 );

    int childsts = 0;
    void * childRc = NULL;

    tid_t tidRc = task_wait_tid( tid,
                                 &childsts,
                                 &childRc);

    if(childsts == TASK_STATUS_CRASHED)
    {
        TRACFCOMP(g_trac_vfs, ERR_MRK
                  "VFS exec crashed. tid:%d status:%d childRc:%p",
                  tid, childsts, childRc);

        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        VFS_MODULE_EXEC_MONITOR
         * @reasoncode      VFS_TASK_CRASHED
         * @userdata1       tidRc
         * @userdata2       task Rc
         *
         * @devdesc         VFS Task crashed.
         * @custdesc  A problem was detected during the IPL of they system:
         *            Task crashed.
         *
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,     // severity
             VFS::VFS_MODULE_EXEC_MONITOR,             // moduleid
             VFS::VFS_TASK_CRASHED,                    // reason Code
             (uint64_t)tidRc,                          // tid rc
             (uint64_t)childRc,                        // child rc
             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT,
             ERRORLOG::ErrlEntry::FORCE_DUMP
            );

        // Add Printk Buffer for FFDC.
        ERRORLOG::ErrlUserDetailsPrintk().addToLog(err);

        if(childRc != NULL) // crit elog aleady generated
        {
            err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        // tell caller that exec/startup failed
        i_msg->data[0] = reinterpret_cast<uint64_t>(err);
        msg_respond(iv_msgQ, i_msg);
    }
}

// ----------------------------------------------------------------------------

void VfsRp::_exec(msg_t * i_msg)
{
    msg_t * msg1 = (msg_t *) i_msg->data[0];

    //  The TOC for the extended image sits at the start of the image and is
    //  not location dependent, so just use the one pointed to by iv_pnor_vaddr
    //  to avoid having to copy it to this block
    VfsSystemModule * module =
        vfs_find_module((VfsSystemModule *)(iv_pnor_vaddr +
                                            VFS_EXTENDED_MODULE_TABLE_OFFSET),
                        (const char*) msg1->data[0]);

    msg_q_t vfsRmsgQ = (msg_q_t) i_msg->data[1];

    msg1->data[0] = (uint64_t) vfs_start_entrypoint(module);

    msg_respond(vfsRmsgQ,msg1);
    msg_free(i_msg);
}

// ----------------------------------------------------------------------------

bool VfsRp::module_exists(const char * i_name) const
{
    bool result = false;
    VfsSystemModule * module = vfs_find_module(VFS_MODULES,i_name);
    if(!module)
    {
        module = vfs_find_module((VfsSystemModule *)(iv_pnor_vaddr +
                                            VFS_EXTENDED_MODULE_TABLE_OFFSET),
                                 i_name);
    }
    if(module) result = true;
    return result;
}

// ----------------------------------------------------------------------------

const VfsSystemModule * VfsRp::get_vfs_info(const char * i_name) const
{
    return vfs_find_module((VfsSystemModule *)(iv_pnor_vaddr +
                                             VFS_EXTENDED_MODULE_TABLE_OFFSET),
                           i_name);
}

// ----------------------------------------------------------------------------

const char * VfsRp::get_name_from_address(const void * i_vaddr) const
{
    const char * result = NULL;

    VfsSystemModule * module = vfs_find_address
        ((VfsSystemModule *)(iv_pnor_vaddr + VFS_EXTENDED_MODULE_TABLE_OFFSET),
         i_vaddr);

    if(!module) // look in the base modules
    {
        module = vfs_find_address(VFS_MODULES,i_vaddr);
    }
    if(module)
    {
        result = module->module;
    }
    return result;
}

// ----------------------------------------------------------------------------

bool VfsRp::is_module_loaded(const char * i_name)
{
    bool result = false;
    const VfsSystemModule * module = get_vfs_info(i_name);
    if(module)
    {
        mutex_lock(&iv_mutex);
        ModuleList_t::const_iterator i =
            std::find(iv_loaded.begin(),iv_loaded.end(),module);
        if(i != iv_loaded.end())
        {
            result = true;
        }
        mutex_unlock(&iv_mutex);
    }
    if(!result)  // look in the base
    {
        module = vfs_find_module(VFS_MODULES,i_name);
        if(module)
        {
            // all base modules are always loaded
            result = true;
        }
    }

    return result;
}

// ----------------------------------------------------------------------------

void VfsRp::get_test_modules(std::vector<const char *> & o_list) const
{
    o_list.clear();
    o_list.reserve(32);

    VfsSystemModule * vfsItr =
        (VfsSystemModule *) (iv_pnor_vaddr + VFS_EXTENDED_MODULE_TABLE_OFFSET);

    TRACFCOMP(g_trac_vfs,"finding test modules...");

    while(vfsItr->module[0] != '\0')
    {
        if (0 == memcmp(vfsItr->module, "libtest", 7))
        {
            if (NULL != vfsItr->start)
            {
                TRACDCOMP( g_trac_vfs, "%s",vfsItr->module);
                o_list.push_back(vfsItr->module);
            }
        }
        vfsItr++;
    }
}


errlHndl_t VfsRp::verify_page(uint64_t i_vaddr, uint64_t i_baseOffset,
                              uint64_t i_hashPageTableOffset) const
{
    errlHndl_t l_errl = nullptr;
    uint64_t l_pnorVaddr = iv_pnor_vaddr-iv_unprotectedOffset+i_vaddr;

    // Get current hash page table entry
    TRACDCOMP(g_trac_vfs, "VfsRp::verify_page Current Page vaddr = 0x%llX, index = %d, bin file offset = 0x%llX",
             i_vaddr,
             getHashPageTableIndex(i_vaddr,i_baseOffset),
             i_vaddr+PAGE_SIZE+iv_protectedPayloadSize);
    PAGE_TABLE_ENTRY_t* l_pageTableEntry = getHashPageTableEntry(i_vaddr,
                                                        i_baseOffset,
                                                        i_hashPageTableOffset);

    // Get previous hash page table entry
    uint64_t l_prevPage = i_vaddr - PAGE_SIZE;
    TRACDCOMP(g_trac_vfs, "VfsRp::verify_page Prev Page vaddr = 0x%llX, index = %d, bin file offset = 0x%llX",
             l_prevPage,
             getHashPageTableIndex(l_prevPage,i_baseOffset),
             l_prevPage+PAGE_SIZE+iv_protectedPayloadSize);
    PAGE_TABLE_ENTRY_t* l_prevPageTableEntry = getHashPageTableEntry(
                                                        l_prevPage,
                                                        i_baseOffset,
                                                        i_hashPageTableOffset);

    // Concatenate previous page table entry with current page data
    std::vector< std::pair<void*,size_t> > l_blobs;
    l_blobs.push_back(std::make_pair<void*,size_t>(l_prevPageTableEntry,
                                                   HASH_PAGE_TABLE_ENTRY_SIZE));
    l_blobs.push_back(std::make_pair<void*,size_t>(
                                        reinterpret_cast<void*>(l_pnorVaddr),
                                        PAGE_SIZE));
    SHA512_t l_curPageHash = {0};
    SECUREBOOT::hashConcatBlobs(l_blobs, l_curPageHash);

    // Compare existing hash page table entry with the derived one.
    if (memcmp(l_pageTableEntry,l_curPageHash,HASH_PAGE_TABLE_ENTRY_SIZE) != 0)
    {
        TRACFCOMP(g_trac_vfs, "ERROR:>VfsRp::verify_page secureboot verify fail on vaddr 0x%llX, offset into HBI 0x%llX",
                              i_vaddr,
                              i_vaddr+PAGE_SIZE+iv_protectedPayloadSize);
        /*@
         * @severity        ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        VFS_VERIFY_PAGE
         * @reasoncode      VFS_PAGE_VERIFY_FAILED
         * @userdata1       Kernel RC
         * @userdata2       virtual address accessed
         *
         * @devdesc         Secureboot page verify failure.
         * @custdesc        Corrupted flash image or firmware error during system boot
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                         VFS_VERIFY_PAGE,
                                         VFS_PAGE_VERIFY_FAILED,
                                         TO_UINT64(EACCES),
                                         i_vaddr,
                                         true);
        l_errl->collectTrace(VFS_COMP_NAME);
        l_errl->collectTrace(PNOR_COMP_NAME);
    }

    return l_errl;
}

VfsRp& VfsRp::getInstance()
{
    return Singleton<VfsRp>::instance();
}

// -- External interface ------------------------------------------------------

errlHndl_t VFS::module_load_unload(const char * i_module, VfsMessages i_msgtype)
{
    errlHndl_t err = NULL;
    msg_q_t vfsQ = msg_q_resolve(VFS_ROOT_MSG_VFS);
    msg_t* msg = msg_allocate();
    msg->type = i_msgtype;
    msg->data[0] = (uint64_t) i_module;
    int rc = msg_sendrecv(vfsQ, msg);

    if (0 == rc)
    {
        err = (errlHndl_t) msg->data[0];
    }
    else
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        VFS_MODULE_ID
         * @reasoncode      VFS_LOAD_FAILED
         * @userdata1       returncode from msg_sendrecv()
         * @userdata2       VfsMessages type [LOAD | UNLOAD]
         *
         * @devdesc         Could not load/unload module.
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
             VFS::VFS_MODULE_ID,                     //  moduleid
             VFS::VFS_LOAD_FAILED,                   //  reason Code
             rc,                                     //  user1 = msg_sendrecv rc
             i_msgtype,                              //  user2 = message type
             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT,
             ERRORLOG::ErrlEntry::FORCE_DUMP
            );
    }

    msg_free(msg);
    return err;
}

// ----------------------------------------------------------------------------

void VFS::find_test_modules(std::vector<const char *> & o_list)
{
    Singleton<VfsRp>::instance().get_test_modules(o_list);
}

// ----------------------------------------------------------------------------

bool VFS::module_exists(const char * i_name)
{
    return Singleton<VfsRp>::instance().module_exists(i_name);
}

// -----------------------------------------------------------------------------

errlHndl_t VFS::module_address(const char * i_name, const char *& o_address, size_t & o_size)
{
    errlHndl_t err = NULL;
    o_address = NULL;
    o_size = 0;

    const VfsSystemModule * vfs = Singleton<VfsRp>::instance().get_vfs_info(i_name);
    if(!vfs || (vfs->text != vfs->data))
    {
        // module not found or is not a data module
        uint64_t name[2] = { 0, 0 };
        strncpy( reinterpret_cast<char*>(name), i_name, sizeof(uint64_t)*2 );
        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        VFS_MODULE_ID
         * @reasoncode      VFS_INVALID_DATA_MODULE
         * @userdata1       First 8 bytes of module name
         * @userdata2       Next 8 bytes of module name
         *
         * @devdesc         Module is not a data module
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,       //  severity
             VFS::VFS_MODULE_ID,                     //  moduleid
             VFS::VFS_INVALID_DATA_MODULE,           //  reason Code
             name[0],
             name[1],
             true /*Add HB Software Callout*/
            );
        ERRORLOG::ErrlUserDetailsString(i_name).addToLog(err);
    }
    else
    {
        o_address = (const char *)vfs->data;
        o_size = vfs->byte_count;
    }
    return err;
}

const char * VFS::module_find_name(const void * i_vaddr)
{
    return Singleton<VfsRp>::instance().get_name_from_address(i_vaddr);
}

bool VFS::module_is_loaded(const char * i_name)
{
    return Singleton<VfsRp>::instance().is_module_loaded(i_name);
}
