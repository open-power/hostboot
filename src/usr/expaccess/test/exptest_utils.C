/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/test/exptest_utils.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
    errlHndl_t loadModule(const char * i_modName)
    {
        errlHndl_t err = NULL;

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
                FAPI_INF("loadModule: %s loaded", i_modName);
            }
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

    void enableInbandScomsOcmb(const TARGETING::TargetHandle_t i_ocmbTarget)
    {
        mutex_t* l_mutex = nullptr;

        assert((i_ocmbTarget != nullptr),
                "enableInbandScomsOcmb: target is NULL!");

        // Verify that the target is of type OCMB_CHIP
        TARGETING::ATTR_TYPE_type l_targetType =
                    i_ocmbTarget->getAttr<TARGETING::ATTR_TYPE>();
        assert((l_targetType == TARGETING::TYPE_OCMB_CHIP),
                "enableInbandScomsOcmb: target is not an OCMB chip!");

        TS_INFO("enableInbandScomsOcmb: switching to use MMIO on OCMB 0x%08x",
                   TARGETING::get_huid(i_ocmbTarget));

        //don't mess with attributes without the mutex (just to be safe)
        l_mutex = i_ocmbTarget->getHbMutexAttr<TARGETING::ATTR_SCOM_ACCESS_MUTEX>();
        recursive_mutex_lock(l_mutex);

        TARGETING::ScomSwitches l_switches =
            i_ocmbTarget->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
        l_switches.useInbandScom = 1;
        l_switches.useI2cScom = 0;

        // Modify attribute
        i_ocmbTarget->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
        recursive_mutex_unlock(l_mutex);
    };

    void disableInbandScomsOcmb(const TARGETING::TargetHandle_t i_ocmbTarget)
    {
        mutex_t* l_mutex = nullptr;

        assert((i_ocmbTarget != nullptr),
                "disableInbandScomsOcmb: target is NULL!");

        // Verify that the target is of type OCMB_CHIP
        TARGETING::ATTR_TYPE_type l_targetType =
                    i_ocmbTarget->getAttr<TARGETING::ATTR_TYPE>();
        assert((l_targetType == TARGETING::TYPE_OCMB_CHIP),
                "disableInbandScomsOcmb: target is not an OCMB chip!");

        TS_INFO("disableInbandScomsOcmb: switching to use i2c on OCMB 0x%08x",
                   TARGETING::get_huid(i_ocmbTarget));

        //don't mess with attributes without the mutex (just to be safe)
        l_mutex = i_ocmbTarget->getHbMutexAttr<TARGETING::ATTR_SCOM_ACCESS_MUTEX>();
        recursive_mutex_lock(l_mutex);

        TARGETING::ScomSwitches l_switches =
            i_ocmbTarget->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
        l_switches.useInbandScom = 0;
        l_switches.useI2cScom = 1;

        // Modify attribute
        i_ocmbTarget->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
        recursive_mutex_unlock(l_mutex);
    };

}
