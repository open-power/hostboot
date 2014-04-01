/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vfs/vfs_reasoncodes.H $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
