#ifndef __USR_VFS_H
#define __USR_VFS_H

#include <errl/errlentry.H>
#include <sys/vfs.h>

namespace VFS
{
    /** 
     * Load or unload a module from the extended image.
     * @param[in] i_module Module name
     * @param[in] i_msgtype [VFS_MSG_LOAD | VFS_MSG_UNLOAD]
     * @return errlHandl_t on error
     */
    errlHndl_t module_load_unload(const char * i_module, VfsMessages i_msgtype);

    /**
     * Loads a module from the extended image and initializes it
     * @param[in] i_module Module name
     * @return errlHndl_t on error
     */
    ALWAYS_INLINE
    inline errlHndl_t module_load(const char * i_module) 
    {
        return VFS::module_load_unload(i_module,VFS_MSG_LOAD);
    }

    /**
     * Destroys and unloads module.
     * @param[in] i_module Module name
     * @return errlHndl_t on error
     */
    ALWAYS_INLINE
    inline errlHndl_t module_unload(const char * i_module)
    {
        return VFS::module_load_unload(i_module, VFS_MSG_UNLOAD);
    }

};

#endif
