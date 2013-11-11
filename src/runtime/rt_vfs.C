/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/runtime/rt_vfs.C $                                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <runtime/interface.h>
#include <kernel/console.H>
#include <util/align.H>
#include <sys/vfs.h>
#include <vector>
#include <errno.h>

VfsSystemModule VFS_MODULES[VFS_MODULE_MAX] =
{{{VFS_MODULE_MAX,0},NULL,NULL,NULL,NULL,NULL,0}};

void vfs_module_init()
{
    printk("Initializing modules.\n");

    VfsSystemModule* module = &VFS_MODULES[0];
    while ('\0' != module->module[0])
    {
        uint64_t textsize = (uint64_t)module->data - (uint64_t)module->text;
        if (textsize != 0)
        {
            for (uint64_t i = (uint64_t)module->text;
                 i < (uint64_t)module->data;
                 i += PAGESIZE)
            {
                g_hostInterfaces->set_page_execute(reinterpret_cast<void*>(i));
            }
        }

        ++module;
    }

    module = &VFS_MODULES[0];
    while ('\0' != module->module[0])
    {
        printk("\tIniting module %s...", module->module);
        if (NULL != module->init)
        {
            (module->init)(NULL);
        }
        printk("done.\n");

        ++module;
    }

    printk("Modules initialized.\n");

}

VfsSystemModule * vfs_find_module(VfsSystemModule * i_table,
                                  const char * i_name)
{
    VfsSystemModule* module = i_table;
    VfsSystemModule* ret = NULL;
    while ('\0' != module->module[0])
    {
        if (0 == strcmp(i_name,module->module))
        {
            ret = module;
            break;
        }
        module++;
    }
    return ret;
}

void* vfs_start_entrypoint(VfsSystemModule * i_module)
{
    void* ptr = reinterpret_cast<void*>(-ENOENT);
    if(i_module != NULL)
    {
        if (i_module->start == NULL)
        {
            // module has no start() routine
            ptr = reinterpret_cast<void*>(-ENOEXEC);
        }
        else
        {
            ptr = reinterpret_cast<void*>(i_module->start);
        }
    }
    return ptr;
}
