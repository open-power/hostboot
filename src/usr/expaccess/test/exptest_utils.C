/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/test/exptest_utils.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include <fapi2.H>
#include <cxxtest/TestSuite.H>
#include "exptest_utils.H"

namespace exptest
{
    errlHndl_t loadModule(bool & o_module_loaded, const char * i_modName)
    {
        errlHndl_t err = NULL;
        o_module_loaded = false;

    // VFS functions only compilable in non-runtime environment
    #ifndef __HOSTBOOT_RUNTIME
        if(!VFS::module_is_loaded(i_modName))
        {
            err = VFS::module_load(i_modName);
            if(err)
            {
                TS_FAIL("loadModule() - %s load failed", i_modName );
            }
            else
            {
                o_module_loaded = true;
                FAPI_INF("loadModule: %s loaded", i_modName);
            }
        }
    #endif
        return err;
    }

    errlHndl_t unloadModule(const char * i_modName)
    {
        errlHndl_t err = NULL;

    // VFS function only compilable in non-runtime environment
    #ifndef __HOSTBOOT_RUNTIME
        err = VFS::module_unload(i_modName);
        if(err)
        {
            TS_FAIL("unloadModule() - %s unload failed", i_modName );
        }
        else
        {
            FAPI_INF("unloadModule: %s unloaded", i_modName);
        }
    #endif
        return err;
    }

    TARGETING::HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR getTestMutex(void)
    {
        TARGETING::HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR pMutex = nullptr;

        // Get a reference to the target service
        TARGETING::TargetService& l_targetService = TARGETING::targetService();

        // Get the system target containing the test mutex
        TARGETING::Target* l_pTarget = NULL;
        (void) l_targetService.getTopLevelTarget(l_pTarget);
        if (l_pTarget == nullptr)
        {
            TS_INFO("getTestMutex: Top level target handle is NULL");
        }
        else
        {
            // use the chip-specific mutex attribute
            pMutex = l_pTarget->getHbMutexAttr
                               <TARGETING::ATTR_HB_MUTEX_SERIALIZE_TEST_LOCK>();
        }
        return pMutex;
    }
}
