/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/testtargeting.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2019                        */
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

// CXXTEST
#include <cxxtest/TestSuite.H>

#include <errl/errlmanager.H>
#include <sys/sync.h>
#include <sys/task.h>
#include <sys/time.h>

// This component
#include <targeting/common/attributes.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/common/targreasoncodes.H>
#include <errl/errludtarget.H>
#include <targeting/common/trace.H>
#include <kernel/console.H>

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

class TargetingTestSuite : public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Test Hostboot specific mutex attribute support
     */
    void testHbRecursiveMutexAttr()
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
    void testHbMutexAttr()
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

    void testNvTarget()
    {
        TS_TRACE(ENTER_MRK "testNvTarget" );

        using namespace ERRORLOG;
        using namespace TARGETING;

        TargetHandleList l_targs;

        getAllChiplets( l_targs, TYPE_OBUS_BRICK);
        if(l_targs.size() == 0)
        {
            TS_FAIL("TYPE_OBUS_BRICK target incorrectly returned zero size");
        }
        else
        {
            TS_TRACE("Correctly returned non-zero number of NV units: %d",
                     l_targs.size());
        }

        for (auto l_targ : l_targs)
        {
            // Do a basic validation of NV target by reading HUID
            uint32_t l_huid = get_huid(l_targ);
            if(l_huid == 0)
            {
                TS_FAIL("Failed to read HUID for a NV target");
            }
            else
            {
                TS_TRACE("NV HUID:0x%.8X",l_huid);
            }
        }

        TS_TRACE(EXIT_MRK "testNvTarget");
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

};

#endif // End __TARGETING_TESTTARGETING_H
