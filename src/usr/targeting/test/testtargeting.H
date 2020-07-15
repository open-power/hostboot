/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/testtargeting.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#ifndef __TARGETING_TESTTARGETING_H
#define __TARGETING_TESTTARGETING_H

/**
 *  @file targeting/test/testtargeting.H
 *
 *  @brief All unit tests which test targeting in a platform specific way
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <sys/time.h>
#include <limits.h>

// CXXTEST
#include <cxxtest/TestSuite.H>

// System
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <sys/sync.h>
#include <sys/task.h>
#include <sys/time.h>
#include <arch/memorymap.H>
#include <kernel/console.H>

// This component
#include <targeting/common/attributes.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/target.H>
#include <targeting/common/hbrt_target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/common/trace.H>

// Generated
#include <attribute_ids.H>

/**
 *  @brief Struct to hold pointers to a mutex / protected value
 */
struct MutexTestData_t
{
    mutex_t* pMutex;         // Pointer to mutex
    barrier_t* pBarrier;     // Pointer to barrier
    volatile uint32_t* pVar; // Pointer to value protected by mutex
};

/**
 *  @brief Function which attempts to write a protected variable
 *
 *  @param[in] i_pData Pointer to mutex pointer/value pointer structure
 *
 *  @return NULL
 */
void* funcTestMutex(void* i_pData)
{
    MutexTestData_t* l_pData = static_cast<MutexTestData_t*>(i_pData);
    barrier_wait(l_pData->pBarrier);
    mutex_lock(l_pData->pMutex);
    *(l_pData->pVar) = 1;
    mutex_unlock(l_pData->pMutex);
    barrier_wait(l_pData->pBarrier);
    return NULL;
}

/**
 *  @brief Function which attempts to recursively access a critical section with
 *         a recursive mutex.
 *
 *  @param[in] i_pData Pointer to mutex pointer/value pointer structure
 *
 *  @return nullptr
 */
void* funcTestRecursiveMutex(void* i_pData)
{
    MutexTestData_t* l_pData = static_cast<MutexTestData_t*>(i_pData);

    // The parent thread holds the lock initially. So the child thread will be
    // blocked when it attempts to access the critical section.
    TS_INFO("Child Thread: Attempting to access the Critical Section");
    recursive_mutex_lock(l_pData->pMutex);

    TS_INFO("Child Thread: Entering the Critical Section");
    if (*(l_pData->pVar) > 0)
    {
        *(l_pData->pVar) = 0;
        funcTestRecursiveMutex(l_pData);
    }

    TS_INFO("Child Thread: Leaving the Critical Section");
    recursive_mutex_unlock(l_pData->pMutex);
    return nullptr;
}

/**
 *  @brief Function that serves as an entry point to the recursive function
 *         it calls. This is so that the barrier_wait calls work without the
 *         recursion causing a deadlock.
 *
 *  @param[in] i_pData Pointer to mutex pointer/value pointer structure
 *
 *  @return nullptr
 */
void* funcTestRecursiveMutexEntry(void* i_pData)
{
    MutexTestData_t* l_pData = static_cast<MutexTestData_t*>(i_pData);

    // Signal to the parent thread that the child thread is about to access the
    // lock which is held by it. That way the main thread can verify that
    // this thread hasn't started recursion yet.
    barrier_wait(l_pData->pBarrier);

    funcTestRecursiveMutex(l_pData);

    // Wake the parent thread so that it can verify that this thread accessed
    // the protected value which proves that the child thread got
    // the lock recursively without a deadlock occuring.
    barrier_wait(l_pData->pBarrier);

    return nullptr;
}

/**
 *  @brief Function to test get and set of std::array values for attributes that
 *  support it. Any N-th dimensional array can be tested.
 *
 *  @param[in] i_target Pointer to target object
 *  @param[in] i_setVal TA_typeStdArr type value to set
 */
template <const TARGETING::ATTRIBUTE_ID TA, typename TA_typeStdArr,
    typename TA_type>
void testStdArrayND(TARGETING::Target *i_target, TA_typeStdArr i_setVal)
{

    // Storing original value
    TA_type l_origVal;

    if(!i_target->tryGetAttr<TA>(l_origVal))
    {
        TS_FAIL("Failed to get original value of attribute.");
        return;
    }

    // Setting value using std::array as input
    i_target->setAttrFromStdArr<TA>(i_setVal);

    // Get c-style array
    TA_type l_cArrOutVal;
    if(!i_target->tryGetAttr<TA>(l_cArrOutVal))
    {
        TS_FAIL("Could not get c-style array value of attribute.");
        return;
    }

    // Copying l_cArrOutVal to a std::array var so that it can be
    // compared with l_outVal below
    TA_typeStdArr l_cArrOutValStdArr;
    memcpy(&l_cArrOutValStdArr, &l_cArrOutVal, sizeof(l_cArrOutVal));

    // std::array output
    auto l_outVal = i_target->getAttrAsStdArr<TA>();

    // Comparing set value with std::array value, and std::array value with
    // c-array value
    if (l_outVal == i_setVal)
    {
        TS_INFO("Success, get value equals set value.");
        if (l_cArrOutValStdArr == l_outVal)
        {
            TS_INFO("Success, get c-style array value equals get std::array"
                " value.");
        }
        else
        {
            TS_FAIL("Failure, get c-style array value does not equal get"
                " std::array value.");
        }
    }
    else
    {
        TS_FAIL("Failure, get value does not equal set value.");
    }

    // Restoring original value
    if(!i_target->trySetAttr<TA>(l_origVal))
    {
        TS_FAIL("Failed to restore original attribute value.");
    }

}


class TargetingTestSuite : public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Test Hostboot specific mutex attribute support
     */
    // TODO RTC: 204720 when mutex issues are resolved reable this
    void _testHbRecursiveMutexAttr()
    {
        TS_TRACE(ENTER_MRK "testHbRecursiveMutexAttr" );

        using namespace TARGETING;

        do {

        // Get a reference to the target service
        TargetService& l_targetService = targetService();

        // Get the system target containing the test mutex
        TARGETING::Target* l_pTarget = nullptr;
        (void) l_targetService.getTopLevelTarget(l_pTarget);
        if (l_pTarget == nullptr)
        {
            TS_FAIL("Top level target handle is NULL");
            break;
        }

        // Get the mutex attribute (actually a mutex_t* which points to
        // a mutex)
        HB_RECURSIVE_MUTEX_TEST_LOCK_ATTR l_pLock =
            l_pTarget->getHbMutexAttr
                <TARGETING::ATTR_HB_RECURSIVE_MUTEX_TEST_LOCK>();

        // Verify the recursive mutex was initialized correctly
        mutex_t* l_recursiveMutex = reinterpret_cast<mutex_t*>(l_pLock);

        if ((l_recursiveMutex->iv_val != 0)
           || (l_recursiveMutex->iv_ownerLockCount != 0)
           || (l_recursiveMutex->iv_owner != 0)
           || (l_recursiveMutex->iv_recursive != true))
        {
            TS_FAIL("Mutex attribute must be initialized as recursive.");
            break;
        }

        // Try to get the attribute, and ensure it's the same
        HB_RECURSIVE_MUTEX_TEST_LOCK_ATTR l_pLockTry = nullptr;
        if(l_pTarget->tryGetHbMutexAttr
                <TARGETING::ATTR_HB_RECURSIVE_MUTEX_TEST_LOCK>(l_pLockTry))
        {
            if(l_pLockTry != l_pLock)
            {
                TS_FAIL("Mutex attributes should match, but dont.  "
                        "l_pLockTry = %p, l_pLock = %p",l_pLockTry,
                        l_pLock);
                break;
            }
        }
        else
        {
            TS_FAIL("Mutex attribute tryGet failed, even though it exists");
            break;
        }

        // Create a structure holding pointers to
        // the mutex and a protected value
        volatile uint32_t l_var = 1;
        TS_INFO("Parent Thread: Acquiring recursive lock");
        (void)recursive_mutex_lock(l_pLock);
        barrier_t l_barrier;
        (void)barrier_init(&l_barrier, 2);
        MutexTestData_t l_mutexTestData = { l_pLock, &l_barrier, &l_var };

        // Spawn off a function which tries to write the protected value to
        // something unexpected. If the mutex is working, the for loop will
        // always poll the expected value.
        TS_INFO("Parent Thread: Creating Child thread");
        task_create(funcTestRecursiveMutexEntry,
                    static_cast<void*>(&l_mutexTestData));

        // Guarantee the child process runs and blocks on the mutex prior to
        // modifying the protected value.  isync to ensure the processor doesn't
        // speculatively perform the comparison prior to the sleep completing
        TS_INFO("Parent Thread: Waiting for Child to attempt to grab the lock");
        barrier_wait(&l_barrier);
        nanosleep(0,TEN_CTX_SWITCHES_NS); isync();

        if(l_var != 1)
        {
            TS_FAIL("Protected value must be 1, was %d instead",l_var);
            break;
        }

        // Now unlock the mutex, allowing the other thread to overwrite the
        // protected value; which should happen within 100,000 reads of the
        // var.  This will confirm the other thread was actively trying to
        // write the controlled value
        TS_INFO(
            "Parent Thread: Releasing lock to Child to test recursive mutex.");
        (void)recursive_mutex_unlock(l_pLock);

        // Guarantee the child process acquires the mutex and modifies the
        // protected value.
        TS_INFO("Parent Thread: Waiting for Child to modify the value");
        barrier_wait(&l_barrier);

        if(l_var != 0)
        {
             TS_FAIL("Protected value must now be 0, was %d instead",l_var);
             break;
        }

        TS_INFO("Parent Thread: Child completed successfully.");
        barrier_destroy(&l_barrier);

        } while(0);

        TS_TRACE(EXIT_MRK "testHbRecursiveMutexAttr");
    }

    /**
     *  @brief Test Hostboot specific mutex attribute support
     */

    // TODO RTC: 204720 when mutex issues are resolved reable this
    void _testHbMutexAttr()
    {
        TS_TRACE(ENTER_MRK "testHbMutexAttr" );

        using namespace TARGETING;

        do {

        // Get a reference to the target service
        TargetService& l_targetService = targetService();

        // Get the system target containing the test mutex
        TARGETING::Target* l_pTarget = NULL;
        (void) l_targetService.getTopLevelTarget(l_pTarget);
        if (l_pTarget == NULL)
        {
            TS_FAIL("Top level target handle is NULL");
            break;
        }

        // Get the mutex attribute (actually a mutex_t* which points to
        // a mutex)
        HB_MUTEX_TEST_LOCK_ATTR l_pLock
            = l_pTarget->getHbMutexAttr<TARGETING::ATTR_HB_MUTEX_TEST_LOCK>();

        // Test: Verify the value pointed to by the mutex_t* is zero
        if ( (*reinterpret_cast<uint64_t*>(l_pLock)) != 0)
        {
            TS_FAIL("Mutex attribute must be initialized to zero, but got %ld",
                *reinterpret_cast<uint64_t*>(l_pLock));
            break;
        }

        // Try to get the attribute, and ensure it's the same
        HB_MUTEX_TEST_LOCK_ATTR l_pLockTry = NULL;
        if(l_pTarget->tryGetHbMutexAttr<TARGETING::ATTR_HB_MUTEX_TEST_LOCK>
                (l_pLockTry))
        {
            if(l_pLockTry != l_pLock)
            {
                TS_FAIL("Mutex attributes should match, but dont.  "
                        "l_pLockTry = %ld, l_pLock = %ld",l_pLockTry,
                        l_pLock);
                break;
            }
        }
        else
        {
            TS_FAIL("Mutex attribute tryGet failed, even though it exists");
            break;
        }

        // Create a structure holding pointers to
        // the mutex and a protected value
        volatile uint32_t l_var = 0;
        (void)mutex_lock(l_pLock);
        barrier_t l_barrier;
        (void)barrier_init(&l_barrier, 2);
        MutexTestData_t l_mutexTestData = { l_pLock, &l_barrier, &l_var };

        // Spawn off a function which tries to write the protected value to
        // something unexpected.  If the mutex is working, the for loop will
        // always poll the expected value.
        task_create(funcTestMutex, static_cast<void*>(&l_mutexTestData));

        // Guarantee the child process runs and blocks on the mutex prior to
        // modifying the protected value.  isync to ensure the processor doesn't
        // speculatively perform the comparison prior to the sleep completing
        barrier_wait(&l_barrier);
        nanosleep(0,TEN_CTX_SWITCHES_NS); isync();

        if(l_var != 0)
        {
            TS_FAIL("Protected value must be 0, was %d instead",l_var);
            break;
        }

        // Now unlock the mutex, allowing the other thread to overwrite the
        // protected value; which should happen within 100,000 reads of the
        // var.  This will confirm the other thread was actively trying to
        // write the controlled value
        (void)mutex_unlock(l_pLock);

        // Guarantee the child process acquires the mutex and modifies the
        // protected value.
        barrier_wait(&l_barrier);

        if(l_var != 1)
        {
             TS_FAIL("Protected value must now be 1, was %d instead",l_var);
             break;
        }

        barrier_destroy(&l_barrier);

        } while(0);

        TS_TRACE(EXIT_MRK "testHbMutexAttr");
    }

    /**
     *  @brief Test Hostboot specific error target FFDC support
     */
    void testErrlTargetFFDC()
    {
        TS_TRACE(ENTER_MRK "testErrlTargetFFDC" );

        using namespace ERRORLOG;
        using namespace TARGETING;

        // Get a reference to the target service
        TargetService& l_service = targetService();

        // Get the master proc target
        TARGETING::Target* l_pTarget1 = NULL;
        TARGETING::Target* l_pTarget2 = MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        l_service.masterProcChipTargetHandle( l_pTarget1);

        // Create an errorlog to test FFDC capture of targets
        /*@
         * @errortype
         * @severity ERRORLOG_SEV_INFORMATIONAL
         * @moduleid TARG_MOD_TEST
         * @reasoncode TARG_RC_TEST_TARGET_FFDC
         * @userdata1 Test data 1
         * @userdata2 Test data 2
         * @devdesc User Details unit test - create target user detail data
         */
        errlHndl_t l_err;
        l_err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                              TARG_MOD_TEST,
                              TARG_RC_TEST_TARGET_FFDC,
                              0x0011223344556677,
                              0x8899aabbccddeeff);

        ErrlUserDetailsTarget(l_pTarget1).addToLog(l_err);
        ErrlUserDetailsTarget(l_pTarget2).addToLog(l_err);

        errlCommit(l_err, CXXTEST_COMP_ID);

        TS_TRACE(EXIT_MRK "testErrlTargetFFDC");
    }

    /**
     *  @brief Test Hostboot specific L4 Target support
     */
    void testL4Target()
    {
        TS_TRACE(ENTER_MRK "testL4Target" );
#if 0
        // Disabling test until ecid reg setup in simics
        // is resolved
        using namespace ERRORLOG;
        using namespace TARGETING;

        TargetHandleList l_targs;

        getAllChiplets( l_targs, TYPE_L4);

        TARGETING::EntityPath phys_path_ptr;

        if( l_targs.size() )
        {

            phys_path_ptr =  l_targs[0]->getAttr<TARGETING::ATTR_PHYS_PATH>();

            TS_TRACE("%s",  phys_path_ptr.toString());

        }
        else
        {
            TS_FAIL("no L4 targets found in system");
        }

#endif
        TS_TRACE(EXIT_MRK "testL4Target" );
    }

    /**
     *  @brief Testing Hostboot support for negative attributes
     */
    void testSignedAttribute()
    {
        TS_TRACE(ENTER_MRK "testSignedAttribute");

        // TODO RTC 144142

        TARGETING::Target* l_sys = NULL;
        TARGETING::targetService().getTopLevelTarget(l_sys);
        int8_t signedAttr = -5;

        // Attempt to set the attribute to a negative number
        if(l_sys->trySetAttr<TARGETING::ATTR_TEST_NEGATIVE_FCN>(signedAttr))
        {
            TS_TRACE("testSignedAttribute: Attribute is %d",signedAttr);
        }
        else
        {
            TS_FAIL("testSignedAttribute: Attribute failed during set");
        }

        signedAttr = 0;

        l_sys->tryGetAttr<TARGETING::ATTR_TEST_NEGATIVE_FCN>(signedAttr);
        if(signedAttr < 0)
        {
            TS_TRACE("testSignedAttribute: Attribute is %d",signedAttr);
        }
        else
        {
            TS_FAIL("testSignedAttribute: Attribute is incorrectly positive");
        }

        TS_TRACE(EXIT_MRK "testSignedAttribute");
    }

    /**
     *  @brief Testing attribute's ability to get/set using std::array
     */
    void testStdArray()
    {

        // Testing 1D array

        TS_INFO(ENTER_MRK "testStdArray: Testing 1D array");

        constexpr auto TA = TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS;
            // TA: targeting attribute
        typedef TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS_typeStdArr
            TA_typeStdArr;
        typedef TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS_type TA_type;

        TARGETING::Target* l_pTarget = nullptr;
        TARGETING::targetService().getTopLevelTarget(l_pTarget);
        assert(l_pTarget != nullptr, "testStdArray, unable to establish top"
            " level target service");

        TA_typeStdArr l_setVal = {9, 6, 3, 1, 5, 1, 7, 3};

        testStdArrayND<TA, TA_typeStdArr, TA_type>(l_pTarget, l_setVal);

        // Testing 2D array
        TS_INFO(ENTER_MRK "testStdArray: Testing 2D array");

        constexpr auto TA2 = TARGETING::ATTR_EEPROM_PAGE_ARRAY;
        typedef TARGETING::ATTR_EEPROM_PAGE_ARRAY_typeStdArr TA2_typeStdArr;
        typedef TARGETING::ATTR_EEPROM_PAGE_ARRAY_type TA2_type;

        TARGETING::TargetHandleList l_procList;
        TARGETING::getAllChips(l_procList, TARGETING::TYPE_PROC);

        if (l_procList.size() == 0 )
        {
            TS_FAIL("Failed to get proc targets.");
        }
        else
        {
            // Setting value using std::array as input
            TA2_typeStdArr l_setVal2 {{ {9, 6, 3, 1}, {8, 4, 2, 44},
                                        {18, 14, 22, 2}, {77, 8, 6, 54} }};

            testStdArrayND<TA2, TA2_typeStdArr, TA2_type>(l_procList.front(),
                l_setVal2);
        }

        TS_INFO(EXIT_MRK "testStdArray");

    }

    void testPciPhbTarget()
    {
        TS_TRACE(ENTER_MRK "testPciPhbTarget" );

        using namespace ERRORLOG;
        using namespace TARGETING;

        TargetHandleList l_targs;

        getAllChiplets( l_targs, TYPE_PCI);

        // There is no PCI target in P9, ensure we got 0 back
        if(l_targs.size() != 0)
        {
            TS_FAIL("TYPE_PCIE target incorrectly returned non-zero size: %d",
                    l_targs.size());
        }

        // The PCI target is actually the PHB target in P9
        getAllChiplets( l_targs, TYPE_PHB);
        if(l_targs.size() == 0)
        {
            TS_FAIL("TYPE_PHB target incorrectly returned zero size");
        }
        else
        {
            TS_TRACE("Correctly returned non-zero number of PHB units: %d",
                     l_targs.size());
        }

        for (auto l_targ : l_targs)
        {
            // Do a basic validation of PHB target by reading HUID
            uint32_t l_huid = get_huid(l_targ);
            if(l_huid == 0)
            {
                TS_FAIL("Failed to read HUID for a PHB target");
            }
            else
            {
                TS_TRACE("PHB HUID:0x%.8X",l_huid);
            }
        }

        TS_TRACE(EXIT_MRK "testPciPhbTarget");
    }

    void testI2cMux()
    {
        TS_TRACE(ENTER_MRK "testI2cMux" );

        TARGETING::TargetRangeFilter l_targetList(
                    TARGETING::targetService().begin(),
                    TARGETING::targetService().end(),
                    nullptr);

        if (l_targetList)
        {
            for (;l_targetList;++l_targetList)
            {
                auto targetClass =
                                 l_targetList->getAttr<TARGETING::ATTR_CLASS>();
                auto targetType = l_targetList->getAttr<TARGETING::ATTR_TYPE>();
                auto targetModel =
                                 l_targetList->getAttr<TARGETING::ATTR_MODEL>();
                if ( (TARGETING::CLASS_CHIP == targetClass)     &&
                     (TARGETING::TYPE_I2C_MUX == targetType)    &&
                     (TARGETING::MODEL_PCA9847 == targetModel) )
                {
                    // Mask off upper 8 bits in case of multiple nodes
                    uint32_t l_huid = get_huid(*l_targetList) & 0x00FFFFFF;
                    // Extract the type, drop instance info
                    l_huid = l_huid >> 16;
                    if (TARGETING::TYPE_I2C_MUX != l_huid)
                    {
                        TS_FAIL("testI2cMux::huid returned(0x%X), "
                                "expected(0x%X)",
                                l_huid,
                                TARGETING::TYPE_I2C_MUX);
                    }

                    TARGETING::FapiI2cControlInfo l_i2cMuxInfo =
                          l_targetList->getAttr<TARGETING::ATTR_FAPI_I2C_CONTROL_INFO>();

                    if (TARGETING::EntityPath::PATH_PHYSICAL !=
                            l_i2cMuxInfo.i2cMasterPath.type())
                    {
                        TS_FAIL("testI2cMux::i2cMuxPath type "
                                "returned(%d), expected(PHYSICAL)",
                                l_i2cMuxInfo.i2cMasterPath.type());
                    }

                    char * l_pathAsString =
                                  l_i2cMuxInfo.i2cMasterPath.toString();
                    if (0 != strcmp(l_pathAsString,
                                    "Physical:/Sys0/Node0/Proc0"))
                    {
                        TS_FAIL("testI2cMux::i2cMuxPath path "
                                "returned(%s), "
                                "expected(Physical:/Sys0/Node0/Proc0)",
                                l_pathAsString);
                    } // end if (TARGETING

                    free (l_pathAsString);
                    l_pathAsString = nullptr;
                } // end if ( (TARGETING::CLASS_CHIP == targetClass) ...
                else if ( (TARGETING::CLASS_ENC == targetClass)   &&
                          (TARGETING::TYPE_NODE == targetType)    &&
                          (TARGETING::MODEL_POWER9 == targetModel) )

                {
                    TARGETING::EepromVpdPrimaryInfo l_eepromInfo =
                            l_targetList->
                             getAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>();

                    if (TARGETING::EntityPath::PATH_PHYSICAL !=
                        l_eepromInfo.i2cMuxPath.type())
                    {
                        TS_FAIL("testI2cMux::i2cMuxPath type returned(%d), "
                                "expected(PHYSICAL)",
                                l_eepromInfo.i2cMuxPath.type());
                    }

                    char * l_pathAsString =
                                         l_eepromInfo.i2cMuxPath.toString();

                    if (0 != strcmp(l_pathAsString,
                                    "Physical:/Sys0"))
                    {
                        TS_FAIL("testI2cMux::i2cMuxPath path returned(%s), "
                                "expected(Physical:/Sys0)",
                                l_pathAsString);
                    }
                    free (l_pathAsString);
                    l_pathAsString = nullptr;
                }  // end if ( (TARGETING::CLASS_ENC == targetClass) ...
            }  // end for (l_targetList;++l_targetList)
        }  // end if  (l_targetList)
        else
        {
            TS_FAIL("testI2cMux::No targets containing I2C Mux found");
        }

        TS_TRACE(EXIT_MRK "testI2cMux");
    }

    void testGetMemTargetMmioInfo(void)
    {
        uint32_t l_tests = 0;
        uint32_t l_fails = 0;
        TS_TRACE(ENTER_MRK "testGetMemTargetMmioInfo" );
        do
        {
            errlHndl_t l_errl = nullptr;

            // Get a reference to the target service
            TARGETING::TargetService& l_targetService = TARGETING::targetService();

            // Get the system target
            TARGETING::Target* l_pSys = nullptr;
            (void) l_targetService.getTopLevelTarget(l_pSys);
            if (l_pSys == nullptr)
            {
                TS_FAIL("Top level target handle is NULL");
                break;
            }

            // Ideally we'd make this test more flexible, but since
            //   we have a known config in standalone we can just
            //   hardcode an assumption
            // Assuming Topology Mode 0 (GGGC) and 1HOP_CHIP_IS_GROUP

            TARGETING::TargetHandleList l_ocmbTargetList;
            TARGETING::getAllChips(l_ocmbTargetList, TARGETING::TYPE_OCMB_CHIP);


            // Values from P10_MMIO_Map_v1.10.xlsx
            //                   0=g0c0         2=g1c0
            //MC01-OCMB 0 CONFIG 6030400000000  6430400000000
            //MC01-OCMB 1 CONFIG 6030480000000  6430480000000
            //MC01-OCMB 0 MMIO   6030500000000  6430500000000
            //MC01-OCMB 1 MMIO   6030580000000  6430580000000
            //MC23-OCMB 2 CONFIG 6030600000000  6430600000000
            //MC23-OCMB 2 CONFIG 6030600000000  6430600000000

            constexpr uint64_t OCMB0_CONFIG =   0x6030400000000;
            constexpr uint64_t OFFSET_TO_MMIO =     0x100000000;//4GB
            constexpr uint64_t OFFSET_TO_ODD_OCMB =  0x80000000;//2GB
            constexpr uint64_t PER_PROC_OFFSET = 0x400000000000;//64TB
            constexpr uint64_t PER_MC_OFFSET =      0x200000000;//8GB

            constexpr uint64_t CONFIG_SPACE_SIZE = OFFSET_TO_ODD_OCMB;
            constexpr uint64_t SM_MMIO_SPACE_SIZE = 128 * MEGABYTE;                      
            constexpr uint64_t SM_MMIO_SPACE_OFFSET = 0;
            constexpr uint64_t IBM_MMIO_SPACE_OFFSET = SM_MMIO_SPACE_OFFSET
                                                     + SM_MMIO_SPACE_SIZE; 
            // Actual MMIO SPACE for IBM scoms is only 16 MB but we reserve 
            // remainder of the entire 2 GB window
            const uint64_t IBM_MMIO_SPACE_RSV_SIZE = 2 * GIGABYTE
                                                     - SM_MMIO_SPACE_SIZE;
            const uint8_t SUPPORTS_8_BYTE = 8;
            const uint8_t SUPPORTS_4_BYTE = 4;

            const uint64_t OCMB0_RT_ID = 0x80000000;

            for (const auto & l_ocmb_target : l_ocmbTargetList)
            {
                // Generate expected values
                TARGETING::ATTR_POSITION_type l_pos = l_ocmb_target->getAttr<TARGETING::ATTR_POSITION>();

                uint64_t exp_runtimeid = OCMB0_RT_ID;
                exp_runtimeid += (l_pos%16);//16 OCMBs per PROC
                exp_runtimeid += (l_pos/16)<<5;//4 for HBRT ID +1 to handle GGGC topology id

                uint64_t exp_config = OCMB0_CONFIG;
                exp_config += OFFSET_TO_ODD_OCMB*(l_pos%2);
                exp_config += PER_MC_OFFSET*(l_pos/2);//2 OCMBs per MC
                exp_config += PER_PROC_OFFSET*(l_pos/16);//16 OCMBs per PROC

                uint64_t exp_mmio = exp_config + OFFSET_TO_MMIO;

                // Config Space
                TARGETING::ocmbMmioAddressRange_t exp_space_config(
                                       exp_runtimeid,
                                       exp_config,
                                       exp_config + CONFIG_SPACE_SIZE - 1,
                                       SUPPORTS_4_BYTE);
                // Microchip MMIO Space
                TARGETING::ocmbMmioAddressRange_t exp_space_mmio_mchp(
                                       exp_runtimeid,
                                       exp_mmio + SM_MMIO_SPACE_OFFSET,
                                       exp_mmio + SM_MMIO_SPACE_OFFSET
                                                + SM_MMIO_SPACE_SIZE - 1,
                                       SUPPORTS_4_BYTE);
                // IBM MMIO Space
                TARGETING::ocmbMmioAddressRange_t exp_space_mmio_ibm(
                                       exp_runtimeid,
                                       exp_mmio + IBM_MMIO_SPACE_OFFSET,
                                       exp_mmio + IBM_MMIO_SPACE_OFFSET
                                                + IBM_MMIO_SPACE_RSV_SIZE - 1,
                                       SUPPORTS_8_BYTE);

                // Compute the ranges
                l_tests++;
                std::vector<TARGETING::ocmbMmioAddressRange_t> l_ranges;
                l_errl = TARGETING::getMemTargetMmioInfo(l_ocmb_target, l_ranges);
                if(l_errl)
                {
                    TS_FAIL("testGetMemTargetMmioInfo an error occured while attempted to read mmio infor from target 0x%.08x",
                            TARGETING::get_huid(l_ocmb_target));
                    delete l_errl;
                    l_errl = nullptr;
                    l_fails++;
                    // Skip this target
                    continue;
                }

                l_tests++;
                if(l_ranges.size() != 3)
                {
                    TS_FAIL("testGetMemTargetMmioInfo OCMB with huid %.08X returned %d mmio ranges when 3 were expected",
                            TARGETING::get_huid(l_ocmb_target), l_ranges.size());
                    l_fails++;
                    // Skip this target
                    continue;
                }

                //Note-making an assumption on the order the ranges are
                // returned just to make the test easier to read

                l_tests++;
                if ( memcmp( &l_ranges[0], &exp_space_config, sizeof(TARGETING::ocmbMmioAddressRange_t )) != 0)
                {
                    TS_FAIL("testGetMemTargetMmioInfo::"
                            "OCMB %.8X CNFG space info did not match what was expected",
                            TARGETING::get_huid(l_ocmb_target));
                    l_fails++;
                    TS_INFO("EXPECTED: id:0x%lx  start addr:0x%lx  end addr:0x%lx  8byteAccess:%s ",
                            exp_space_config.hbrtId,
                            exp_space_config.mmioBaseAddr,
                            exp_space_config.mmioEndAddr,
                            exp_space_config.accessSize == 8 ? "true" : "false");
                    TS_INFO("ACTUAL  : id:0x%lx  start addr:0x%lx  end addr:0x%lx  8byteAccess:%s ",
                            l_ranges[0].hbrtId,
                            l_ranges[0].mmioBaseAddr,
                            l_ranges[0].mmioEndAddr,
                            l_ranges[0].accessSize == 8 ? "true" : "false");
                }

                l_tests++;
                if ( memcmp( &l_ranges[1], &exp_space_mmio_mchp, sizeof(TARGETING::ocmbMmioAddressRange_t )) != 0)
                {
                    TS_FAIL("testGetMemTargetMmioInfo::"
                            "OCMB %.8X Microchip MMIO space info did not match what was expected",
                            TARGETING::get_huid(l_ocmb_target));
                    l_fails++;
                    TS_INFO("EXPECTED: id:0x%lx  start addr:0x%lx  end addr:0x%lx  8byteAccess:%s ",
                            exp_space_mmio_mchp.hbrtId,
                            exp_space_mmio_mchp.mmioBaseAddr,
                            exp_space_mmio_mchp.mmioEndAddr,
                            exp_space_mmio_mchp.accessSize == 8 ? "true" : "false");
                    TS_INFO("ACTUAL  : id:0x%lx  start addr:0x%lx  end addr:0x%lx  8byteAccess:%s ",
                            l_ranges[1].hbrtId,
                            l_ranges[1].mmioBaseAddr,
                            l_ranges[1].mmioEndAddr,
                            l_ranges[1].accessSize == 8 ? "true" : "false");
                }

                l_tests++;
                if ( memcmp( &l_ranges[2], &exp_space_mmio_ibm, sizeof(TARGETING::ocmbMmioAddressRange_t )) != 0)
                {
                    TS_FAIL("testGetMemTargetMmioInfo::"
                            "OCMB %.8X IBM MMIO space info did not match what was expected",
                            TARGETING::get_huid(l_ocmb_target));
                    l_fails++;
                    TS_INFO("EXPECTED: id:0x%lx  start addr:0x%lx  end addr:0x%lx  8byteAccess:%s ",
                            exp_space_mmio_ibm.hbrtId,
                            exp_space_mmio_ibm.mmioBaseAddr,
                            exp_space_mmio_ibm.mmioEndAddr,
                            exp_space_mmio_ibm.accessSize == 8 ? "true" : "false");
                    TS_INFO("ACTUAL  : id:0x%lx  start addr:0x%lx  end addr:0x%lx  8byteAccess:%s ",
                            l_ranges[2].hbrtId,
                            l_ranges[2].mmioBaseAddr,
                            l_ranges[2].mmioEndAddr,
                            l_ranges[2].accessSize == 8 ? "true" : "false");
                }
            }
        }while(0);
        TS_TRACE(EXIT_MRK "testGetMemTargetMmioInfo tests: %d   fails: %d", l_tests, l_fails );
    }

};

#endif // End __TARGETING_TESTTARGETING_H
