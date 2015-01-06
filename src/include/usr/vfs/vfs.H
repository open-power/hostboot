/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vfs/vfs.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
     * Test for existence of module
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
