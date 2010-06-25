#ifndef __SYS_VFS_H
#define __SYS_VFS_H

#include <stdint.h>

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
};

#ifdef __cplusplus
}
#endif

#endif
