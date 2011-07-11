#ifndef __SYS_VFS_H
#define __SYS_VFS_H

#include <stdint.h>

// make TODO VFS_MODULE_MAX equal to the actual number of modules in the base image (+ 2?)
#define VFS_MODULE_MAX 32
// Extended use 4 4k pages
#define VFS_EXTENDED_MODULE_MAX 128
#define VFS_EXTENDED_MODULE_TABLE_ADDRESS 0x0000000040000000UL
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

enum VfsMessages
{
    VFS_MSG_REGISTER_MSGQ,
    VFS_MSG_RESOLVE_MSGQ,
    VFS_MSG_EXEC,
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

#endif
