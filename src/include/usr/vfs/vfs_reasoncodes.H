#ifndef VFS_REASONCODES_H
#define VFS_REASONCODES_H

#include <hbotcompid.H>

namespace VFS
{
    enum VfsModuleID
    {
        UNDEFINED_MODULE_ERRL_ID    = 0,
        VFS_MODULE_ID,
    };

    enum VfsReasonCode
    {
        VFS_LOAD_FAILED     =       VFS_COMP_ID | 0x01,
        VFS_UNLOAD_FAILED   =       VFS_COMP_ID | 0x02,
        VFS_ALLOC_VMEM_FAILED =     VFS_COMP_ID | 0x03,
    };
};

#endif
