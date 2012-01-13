//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/vfs/vfs.H $
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
#ifndef __USR_VFS_H
#define __USR_VFS_H

#include <errl/errlentry.H>
#include <sys/vfs.h>
#include <sys/sync.h>
#include <vector>

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

    /**
     * Find test modules
     * @param[out] list of module names
     */
    void find_test_modules(std::vector<const char *> & o_list);

    /**
     * Test for existance of module
     * @param[in] i_name module name
     * @return [true|false]
     */
    bool module_exists(const char * i_name);

    /**
     * Get the start memory address of a data module
     * @param[in] module name
     * @param[out] o_address  memory address
     * @param[out] o_size module size
     * @retun error log on error
     * @pre load_module() must have been called
     */
    errlHndl_t module_address(const char * i_name, const char *& o_address, size_t & o_size);

    /**
     * Get the module name associated with an address
     * @param[in] i_vaddr, The virtual address
     * @returns ptr to module name or NULL if not found
     */
    const char * module_find_name(const void * i_vaddr);

    /**
     * Query if module is loaded
     * @param[in] module name
     * @returns [true|false]
     */
    bool module_is_loaded(const char * i_name);

};

#endif
