/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/expupd/test/expupdatetest.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __EXPUPDATETEST_H
#define __EXPUPDATETEST_H

/**
 *  @file expupdatetest.H
 *
 *  @brief Test cases for explorer chip firmware update
 */

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <lib/inband/exp_inband.H>
#include <exp_data_structs.H>
#include <exp_fw_update.H>
#include <generic/memory/lib/utils/endian_utils.H>
#ifndef __HOSTBOOT_RUNTIME
#include <vfs/vfs.H> // module_is_loaded & module_load
#endif
#include <test/exptest_utils.H>

const char MSS_LIBRARY_NAME[] = "libisteps_mss.so";
const char EXPUPD_LIBRARY_NAME[] = "libexpupd.so";

/**
 * @brief Generic function to load a module
 * @param i_modName - module name to load
 * @return error handle if module_load call fails
 */
errlHndl_t loadModule(const char * i_modName)
{
    errlHndl_t err = nullptr;

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
            TS_TRACE("loadModule: %s loaded", i_modName);
        }
    }
#endif
    return err;
}


class ExpUpdateTest: public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Test the explorer firmware update procedure
     */
    void  testExpFwUpdate( void )
    {
        errlHndl_t l_errl = nullptr;

        uint8_t l_dataBuffer[4096] = {0};

        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipList;

        // Get a list of all of the functioning ocmb chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_OCMB_CHIP, true);

        TARGETING::HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR l_mutex = exptest::getTestMutex();
        if (l_mutex == nullptr)
        {
            TS_FAIL("testExpFwUpdate: unable to get test mutex");
        }
        else
        {
            for (const auto & l_ocmb: l_chipList)
            {
                fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>l_fapi2_target(l_ocmb);

                // Inband operations can't be run at the same time
                // atomic section >>
                mutex_lock(l_mutex);

                // Invoke procedure
                FAPI_INVOKE_HWP(l_errl, exp_fw_update, l_fapi2_target,
                                l_dataBuffer, sizeof(l_dataBuffer));

                // << atomic section
                mutex_unlock(l_mutex);
                if (l_errl)
                {
#if 0  // skipping exp_fw_update error until simics is changed - @fixme:RTC-209865
                    TS_FAIL("Error from exp_fw_update for 0x%.8X target",
                        TARGETING::get_huid(l_ocmb));
#endif
                    break;
                }
            }

            if (l_errl)
            {
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }

        TS_INFO("testExpFwUpdate: exiting");
    };

    /**
     * @brief Constructor
     */
    ExpUpdateTest() : CxxTest::TestSuite()
    {
        // All modules are loaded by runtime,
        // so testcase loading of modules is not required
#ifndef __HOSTBOOT_RUNTIME
        errlHndl_t err = nullptr;

        err = loadModule(MSS_LIBRARY_NAME);
        if(err)
        {
            TS_FAIL("ExpUpdateTest() - Constuctor: failed to load MSS module");
            errlCommit( err, CXXTEST_COMP_ID );
        }
        err = loadModule(EXPUPD_LIBRARY_NAME);
        if(err)
        {
            TS_FAIL("ExpUpdateTest() - Constuctor: failed to load EXPUPD module");
            errlCommit( err, CXXTEST_COMP_ID );
        }
#endif
    };


    /**
     * @brief Destructor
     */
    ~ExpUpdateTest()
    {
    };

    private:
};

#endif
