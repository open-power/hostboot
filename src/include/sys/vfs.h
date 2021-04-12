/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/vfs.h $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2021                        */
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
#ifndef __SYS_VFS_H
#define __SYS_VFS_H

#include <stdint.h>
// NOTE!. This file is included by linker.C and can't include non standard header files
#ifndef LINKER_C
// other includes not visible to the linker
#include <sys/task.h>
#endif

#ifndef __HOSTBOOT_RUNTIME
// make VFS_MODULE_MAX equal to the actual number of modules in the base image (+ 2?)
#define VFS_MODULE_MAX 16
#else
#define VFS_MODULE_MAX 128
#endif

// Extended use 4 4k pages
//  Extended Module Virtual address at 1GB
#define VFS_EXTENDED_MODULE_VADDR (1 * 1024 * 1024 * 1024)
#define VFS_EXTENDED_MODULE_TABLE_ADDRESS (VFS_EXTENDED_MODULE_VADDR)
#define VFS_EXTENDED_MODULE_TABLE_OFFSET 0
// Note: VFS_EXTENDED_MODULE_MAX used in src/build/buildpnor/genPnorImages.pl
#define VFS_EXTENDED_MODULE_MAX 192
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
extern const char* VFS_ROOT_MSG_VFS;
extern const char* VFS_ROOT_MSG_INTR;
extern const char* VFS_ROOT_MSG_PLDM_REQ_OUT;

enum VfsMessages
{
    VFS_MSG_REGISTER_MSGQ, //!< Message to VFS_ROOT to register a message queue
    VFS_MSG_REMOVE_MSGQ,   //!< Message to VFS_ROOT to remove a message queue
    VFS_MSG_RESOLVE_MSGQ,  //!< Message to VFS_ROOT to find a message queue
    VFS_MSG_EXEC,          //!< Message to VFS_ROOT execute a module
    VFS_MSG_LOAD,          //!< Message to vfsrp to load a module
    VFS_MSG_UNLOAD,        //!< Message to vfsrp to unload a module
};

// Note: size of VfsSystemModule (VFS_MODULE_TABLE_ENTRY_SIZE) used in
// src/build/buildpnor/buildpnor.pl
struct VfsSystemModule
{
    char module[VFS_MODULE_NAME_MAX];           //!< Module name
    void  (*init)(void*);                       //!< ptr to init()
    void  (*start)(void*);                      //!< ptr to start()
    void  (*fini)(void*);                       //!< ptr to fini()
    uint64_t * text;                            //!< ptr to text (code) section
    uint64_t * data;                            //!< ptr to data section
    uint64_t byte_count;                        //!< no. of bytes in module
};

extern VfsSystemModule VFS_MODULES[VFS_MODULE_MAX];

extern uint64_t VFS_LAST_ADDRESS;

#define VFS_MODULE_TABLE_SIZE (VFS_EXTENDED_MODULE_MAX * sizeof(VfsSystemModule))

// Offset for TLS "dtv-relative displacement".
// See http://www.uclibc.org/docs/tls-ppc64.txt
#define VFS_PPC64_DTPREL_OFFSET 0x8000

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
 * Find the VfsSystemModule for the given address
 * @param[in] i_table The VFS module table to look in
 * @param[in] i_vaddr The virtual address
 * @return VrsSytemModule ptr for the module | NULL if not found
 */
VfsSystemModule * vfs_find_address(VfsSystemModule * i_table,
                                   const void * i_vaddr);

/**
 * Get the module's start routine
 * @param[in] i_module VfsSystemModule data for the module
 * @return Function pointer of module's start or negative value on error.
 * @retval -ENOENT if i_module is NULL
 * @retval -ENOEXEC if there is no start()
 */
void* vfs_start_entrypoint(VfsSystemModule * i_module);

/**
 * Change permissions on the virtual pages associated with the module
 * @param[in] module  The vfsSystemModule
 * @return rc from mm_set_permission()
 */
int vfs_module_perms(VfsSystemModule* module);

#endif

#endif
