/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/runtime/rt_vfs.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#include <string.h>
#include <sys/vfs.h>
#include <vfs/vfs_reasoncodes.H>
#include <errl/errlentry.H>
#include <errl/errludstring.H>

using namespace ERRORLOG;

namespace VFS
{
    void find_test_modules(std::vector<const char*> & o_list)
    {
        o_list.clear();

        for(VfsSystemModule* vfsItr = &VFS_MODULES[0];
            '\0' != vfsItr->module[0];
            vfsItr++)
        {
            if (0 == memcmp(vfsItr->module, "libtest", 7))
            {
                if (NULL != vfsItr->start)
                {
                    o_list.push_back(vfsItr->module);
                }
            }
        }
    }

    errlHndl_t module_address(const char * i_name,
                              const char *& o_address, size_t & o_size)
    {
        errlHndl_t l_errl = NULL;
        VfsSystemModule* entry = vfs_find_module(&VFS_MODULES[0], i_name);

        if ((NULL == entry) || (entry->text != entry->data))
        {
            /*@ errorlog tag
             * @errortype       ERRL_SEV_INFORMATIONAL
             * @moduleid        VFS_RT_MODULE_ID
             * @reasoncode      VFS_INVALID_DATA_MODULE
             * @userdata1       0
             * @userdata2       0
             *
             * @devdesc         Module is not a data module
             *
             */
            l_errl = new ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,       //  severity
                VFS::VFS_RT_MODULE_ID,                  //  moduleid
                VFS::VFS_INVALID_DATA_MODULE,           //  reason Code
                0, 0);
            ErrlUserDetailsString(i_name).addToLog(l_errl);
        }
        else
        {
            o_address = (const char *)entry->data;
            o_size = entry->byte_count;
        }

        return l_errl;
    }
}
