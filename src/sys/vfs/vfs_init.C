#include <sys/vfs.h>
#include <kernel/console.H> 

VfsSystemModule VFS_MODULES[VFS_MODULE_MAX];
uint64_t VFS_LAST_ADDRESS;

void vfs_module_init()
{
    printk("Initializing modules.\n");

    VfsSystemModule* module = &VFS_MODULES[0];
    while ('\0' != module->module[0])
    {
	printk("\tIniting module %s...", module->module);
	if (NULL != module->init)
	    (module->init)(NULL);
	printk("done.\n");

	module++;
    }

    printk("Modules initialized.");
}

void (*vfs_module_find_start(const char* modName))(void*)
{
    VfsSystemModule* module = &VFS_MODULES[0];
    while ('\0' != module->module[0])
    {
	if (0 == strcmp(modName, module->module))
	{
	    return module->start;
	}

	module++;
    }

    return NULL;
}
