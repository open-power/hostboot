#ifndef __SYS_VFS_H
#define __SYS_VFS_H

#include <stdint.h>

#define VFS_MODULE_MAX 128
#define VFS_MODULE_NAME_MAX 64
#define VFS_SYMBOL_INIT _init
#define VFS_SYMBOL_START _start
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
    const char module[VFS_MODULE_NAME_MAX];
    void  (*init)(void*);
    void  (*start)(void*);
};

extern VfsSystemModule VFS_MODULES[VFS_MODULE_MAX];
extern uint64_t VFS_LAST_ADDRESS;

#ifdef __cplusplus
}
#endif

#endif
