//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/sys/vfs/vfs_init.C $
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
 * @file vfs_init.C
 * @brief function definitions for funtions used to initialize modules
 */
#include <sys/vfs.h>
#include <kernel/console.H>
#include <limits.h>
#include <sys/mm.h>

VfsSystemModule VFS_MODULES[VFS_MODULE_MAX];
uint64_t VFS_LAST_ADDRESS;


int vfs_module_perms(VfsSystemModule* module)
{
    int rc = 0;
    uint64_t memsize = (module->page_count*PAGESIZE);
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


