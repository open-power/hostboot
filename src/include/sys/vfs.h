#ifndef __SYS_VFS_H
#define __SYS_VFS_H

#include <stdint.h>
// NOTE!. This file is included by linker.C and can't include non standard header files
#ifndef LINKER_C
// other includes not visable to the linker
#include <sys/task.h>
#endif

// make TODO VFS_MODULE_MAX equal to the actual number of modules in the base image (+ 2?)
#define VFS_MODULE_MAX 64
// Extended use 4 4k pages
//  Extended Module Virtual address at 1GB
#define VFS_EXTENDED_MODULE_VADDR (1 * 1024 * 1024 * 1024)
#define VFS_EXTENDED_MODULE_TABLE_ADDRESS (VFS_EXTENDED_MODULE_VADDR)
#define VFS_EXTENDED_MODULE_TABLE_OFFSET 0
#define VFS_EXTENDED_MODULE_MAX 128
#define VFS_MODULE_NAME_MAX 64
#define VFS_SYMBOL_INIT _init
#define VFS_SYMBOL_START _start
#define VFS_SYMBOL_FINI _fini
#define VFS_SYMBOL_TEXT .text
#define VFS_SYMBOL_DATA .data
#define VFS_STRINGIFY(X) #X
#define VFS_TOSTRING(X) VFS_STRINGIFY(X)

#define VFS_MODULE_DEFINE_START(f) \
    extern "C" void VFS_SYMBOL_START(void* args) \
    { \
	f(args); \
    }

#ifdef __cplusplus
extern "C"
{
#endif

extern const char* VFS_ROOT;
extern const char* VFS_ROOT_BIN;
extern const char* VFS_ROOT_DATA;
extern const char* VFS_ROOT_MSG;
extern const char* VFS_MSG;

enum VfsMessages
{
    VFS_MSG_REGISTER_MSGQ, //!< Message to VFS_ROOT to register a message queue
    VFS_MSG_RESOLVE_MSGQ,  //!< Message to VFS_ROOT to find a message queue
    VFS_MSG_EXEC,          //!< Message to VFS_ROOT execute a module
    VFS_MSG_LOAD,          //!< Message to VFS_MSG to load a module
    VFS_MSG_UNLOAD,        //!< Message to VFS_MSG to unload a module
};

struct VfsSystemModule
{
    const char module[VFS_MODULE_NAME_MAX];     //!< Module name
    void  (*init)(void*);                       //!< ptr to init()
    void  (*start)(void*);                      //!< ptr to start()
    void  (*fini)(void*);                       //!< ptr to fini()
    uint64_t * text;                            //!< ptr to text (code) section
    uint64_t * data;                            //!< ptr to data section
    uint64_t page_size;                         //!< no. of memory pages used
};

extern VfsSystemModule VFS_MODULES[VFS_MODULE_MAX];

extern uint64_t VFS_LAST_ADDRESS;

#ifdef __cplusplus
}
#endif

#ifndef LINKER_C
/**
 * Find the VfsSystemModule data for the given module name
 * @param[in] i_table VFS module table
 * @param[in] i_name name of module to find
 * @return VfsSystemModule ptr to data | NULL if not found
 */
VfsSystemModule * vfs_find_module(VfsSystemModule * i_table, const char * i_name);

/**
 * Call the module start routine
 * @param[in] i_module VfsSystemModule data for the module
 * @param[in] i_param parameter to pass to task_create() for this module
 * @return tid_t of started task | -1 if i_module is NULL | -2 if there is no start()
 */
tid_t vfs_exec(VfsSystemModule * i_module, void* i_param);
#endif

#endif
