/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vfs/vfs_reasoncodes.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef VFS_REASONCODES_H
#define VFS_REASONCODES_H

#include <hbotcompid.H>

namespace VFS
{
    enum VfsModuleID
    {
        UNDEFINED_MODULE_ERRL_ID    = 0x00,
        VFS_MODULE_ID               = 0x01,
        VFS_RT_MODULE_ID            = 0x02,
        VFS_WATCHER                 = 0x03,
        VFS_MODULE_LOAD_MONITOR     = 0x04,
        VFS_MODULE_EXEC_MONITOR     = 0x05,
    };

    enum VfsReasonCode
    {
        VFS_LOAD_FAILED     =       VFS_COMP_ID | 0x01,
        VFS_UNLOAD_FAILED   =       VFS_COMP_ID | 0x02,
        VFS_ALLOC_VMEM_FAILED =     VFS_COMP_ID | 0x03,
        VFS_PERMS_VMEM_FAILED =     VFS_COMP_ID | 0x04,
        VFS_MODULE_DOES_NOT_EXIST = VFS_COMP_ID | 0x05,
        VFS_INVALID_DATA_MODULE   = VFS_COMP_ID | 0x06,
        VFS_TASK_CRASHED          = VFS_COMP_ID | 0x07,
    };
};

#endif
