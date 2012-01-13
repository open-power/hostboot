//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/vfs/vfsrp.C $
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

using namespace VFS;

// Trace definitions
trace_desc_t * g_trac_vfs = NULL;
TRAC_INIT(&g_trac_vfs, VFS_COMP_NAME, 1024);

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
void VfsRp::init( void * i_taskArgs )
{
    errlHndl_t err = NULL;
    err = Singleton<VfsRp>::instance()._init();
    INITSERVICE::TaskArgs* args =
            static_cast<INITSERVICE::TaskArgs*>(i_taskArgs);
    if(err)
    {
        args->postErrorLog(err);
    }
}

// ----------------------------------------------------------------------------

/**
 * Helper function to start vfs messge handler
 */
void VfsRp::msg_handler(void * unused)
{
    Singleton<VfsRp>::instance().msgHandler();
}

// ----------------------------------------------------------------------------

void VfsRp::load_unload(void * i_msg)
{
    task_detach();
    Singleton<VfsRp>::instance()._load_unload((msg_t*)i_msg);
    task_end();
}

// ----------------------------------------------------------------------------

void VfsRp::exec(void * i_msg)
{
    task_detach();
    Singleton<VfsRp>::instance()._exec((msg_t*)i_msg);
    task_end();
}

// ----------------------------------------------------------------------------

/**
 * Initialze the vfs resource provider
 */
errlHndl_t VfsRp::_init()
{
    errlHndl_t err = NULL;
    size_t rc = 0;
    iv_msgQ = msg_q_create();
    rc = msg_q_register(iv_msgQ, VFS_ROOT_MSG_VFS);

    // Discover PNOR virtual address of extended image
    PNOR::SectionInfo_t l_pnor_info;

    // How will SIDE eventually be determined? TODO
    err = PNOR::getSectionInfo(PNOR::HB_EXT_CODE, PNOR::SIDE_A, l_pnor_info);
    if(!err)
    {
        iv_pnor_vaddr = l_pnor_info.vaddr;

        rc = mm_alloc_block
            (iv_msgQ,
             (void *)VFS_EXTENDED_MODULE_VADDR,
             ALIGN_PAGE(l_pnor_info.size)
            );
        if(rc == 0)
        {
            // TODO set permissions here or are defaults OK?

            // Start msg_handler
            //  NOTE: This would be a weak consistancy issues if
            //  task_create were not a system call.
            task_create(VfsRp::msg_handler, NULL);
        }
        else
        {
            /*@ errorlog tag
             * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid        VFS_MODULE_ID
             * @reasoncode      VFS_ALLOC_VMEM_FAILED
             * @userdata1       returncode from mm_alloc_block()
             * @userdata2       0
             *
             * @defdesc         Could not allocate virtual memory.
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                 VFS::VFS_MODULE_ID,                     //  moduleid
                 VFS::VFS_ALLOC_VMEM_FAILED,             //  reason Code
                 rc,                                     //  user1 = rc
                 0                                       //  user2
                );
        }
    }

    return err;
}


// ----------------------------------------------------------------------------

void VfsRp::msgHandler()
{
    while(1)
    {
        msg_t* msg = msg_wait(iv_msgQ);

        switch(msg->type)
        {
            case VFS_MSG_LOAD:
                {
                    TRACDCOMP(g_trac_vfs, "Load request: %s",
                              (const char *) msg->data[0]);

                    // run in own task so page faults can be handled
                    task_create(load_unload, msg);
                }
                break;

            case VFS_MSG_UNLOAD:
                {
                    TRACDCOMP(g_trac_vfs, "Unload request: %s",
                              (const char *) msg->data[0]);

                    // run in own task so page faults can be handled
                    task_create(load_unload, msg);

                }
                break;

            case VFS_MSG_EXEC:
                {
                    TRACDCOMP(g_trac_vfs, "EXEC request: %s",
                           (const char*)((msg_t*)msg->data[0])->data[0]);

                    // run in own task so page faults can be handled
                    task_create(exec, msg);

                }
                break;

            case MSG_MM_RP_READ:
                {
                    uint64_t vaddr = msg->data[0]; //page aligned
                    uint64_t paddr = msg->data[1]; //page aligned

                    vaddr -= VFS_EXTENDED_MODULE_VADDR;
                    memcpy((void *)paddr, (void *)(iv_pnor_vaddr+vaddr),
                           PAGE_SIZE);

                    mm_icache_invalidate((void*)paddr,PAGE_SIZE/8);

                }
                msg->data[1] = 0;
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

void VfsRp::_load_unload(msg_t * i_msg)
{
    errlHndl_t err = NULL;

    // Find VfsSystemModule
    //  The TOC for the extended image sits at the start of the image and is
    //  not location dependant, so just use the one pointed to by iv_pnor_vaddr
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
             * @userdata2       0
             *
             * @defdesc         Could not set permissions on virtual memory.
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                 VFS::VFS_MODULE_ID,                     //  moduleid
                 VFS_PERMS_VMEM_FAILED,                  //  reason Code
                 rc,                                     //  user1 = rc
                 0                                       //  user2 = 0
                );
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
             * @defdesc         Requested Module does not exist.
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                 VFS::VFS_MODULE_ID,                     //  moduleid
                 VFS_MODULE_DOES_NOT_EXIST,              //  reason Code
                 name[0],
                 name[1]
                );
        }
    }
    i_msg->data[0] = (uint64_t) err;
    msg_respond(iv_msgQ, i_msg);
}

// ----------------------------------------------------------------------------

void VfsRp::_exec(msg_t * i_msg)
{
    msg_t * msg1 = (msg_t *) i_msg->data[0];

    //  The TOC for the extended image sits at the start of the image and is
    //  not location dependant, so just use the one pointed to by iv_pnor_vaddr
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

    //TRACDCOMP(g_trac_vfs,"finding test modules...");

    while(vfsItr->module[0] != '\0')
    {
        if (0 == memcmp(vfsItr->module, "libtest", 7))
        {
            if (NULL != vfsItr->start)
            {
                //TRACDCOMP( g_trac_vfs, "%s",vfsItr->module);
                o_list.push_back(vfsItr->module);
            }
        }
        vfsItr++;
    }
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
         * @defdesc         Could not load/unload module.
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
             VFS::VFS_MODULE_ID,                     //  moduleid
             VFS::VFS_LOAD_FAILED,                   //  reason Code
             rc,                                     //  user1 = msg_sendrecv rc
             i_msgtype                               //  user2 = message type
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
        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        VFS_MODULE_ID
         * @reasoncode      VFS_INVALID_DATA_MODULE
         * @userdata1       0
         * @userdata2       0
         *
         * @defdesc         Module is not a data module
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,       //  severity
             VFS::VFS_MODULE_ID,                     //  moduleid
             VFS::VFS_INVALID_DATA_MODULE,           //  reason Code
             0,
             0
            );
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


