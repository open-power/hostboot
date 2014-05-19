/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/sys/vfs/vfs_init.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
 * @file vfs_init.C
 * @brief function definitions for funtions used to initialize modules
 */
#include <sys/vfs.h>
#include <kernel/console.H>
#include <limits.h>
#include <sys/mm.h>
#include <util/align.H>

VfsSystemModule VFS_MODULES[VFS_MODULE_MAX] =
{{{VFS_MODULE_MAX,0},NULL,NULL,NULL,NULL,NULL,0}};

uint64_t VFS_LAST_ADDRESS;


int vfs_module_perms(VfsSystemModule* module)
{
    int rc = 0;
    uint64_t memsize = ALIGN_PAGE(module->byte_count);
    uint64_t textsize= (uint64_t)module->data - (uint64_t)module->text;

    uint64_t datasize = memsize - textsize;

    printkd("%s text=%p:%lx data=%p:%lx\n",
            module->module,
            module->text,
            textsize,
            module->data,
            datasize);

    if(textsize != 0)
    {
        // Mark text pages(s) as executable
        rc |= mm_set_permission(module->text,
                                textsize,
                                EXECUTABLE);

        // Mark data pages(s) as normal
        rc |= mm_set_permission(module->data,
                                datasize,
                                WRITABLE);
    }
    else // ro data module
    {
        // Mark data pages(s) as normal
        rc |= mm_set_permission(module->data,
                                datasize,
                                READ_ONLY);
    }
    return rc;
}

// ----------------------------------------------------------------------------

void vfs_module_init()
{
    printk("Initializing modules.\n");

    VfsSystemModule* module = &VFS_MODULES[0];
    while ('\0' != module->module[0])
    {
        int rc = vfs_module_perms(module);
        if(rc) printk("Perms set failed on %s, rc = %d\n",
                      module->module,rc);
        ++module;
    }

    module = &VFS_MODULES[0];
    while ('\0' != module->module[0])
    {
	printk("\tIniting module %s...", module->module);
	if (NULL != module->init)
	    (module->init)(NULL);
	printk("done.\n");

	++module;
    }

    printk("Modules initialized.\n");
}

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

VfsSystemModule * vfs_find_address(VfsSystemModule * i_table,
                                   const void * i_vaddr)
{
    VfsSystemModule * module = i_table;
    VfsSystemModule * ret = NULL;

    const uint8_t * vaddr = reinterpret_cast<const uint8_t *>(i_vaddr);

    while('\0' != module->module[0])
    {
        const uint8_t * first = reinterpret_cast<const uint8_t *>(module->text);
        const uint8_t * last = first + module->byte_count;

        if(vaddr >= first && vaddr < last)
        {
            ret = module;
            break;
        }
        ++module;
    }
    return ret;
}

