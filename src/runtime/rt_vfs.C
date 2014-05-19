/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/runtime/rt_vfs.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
                if (g_hostInterfaces->set_page_execute)
                {
                    g_hostInterfaces->set_page_execute(
                            reinterpret_cast<void*>(i));
                }
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
