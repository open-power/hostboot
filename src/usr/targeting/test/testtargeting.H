//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/test/testtargeting.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

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
#include <hwpf/plat/fapiPlatAttributeService.H>
#include <fapiReturnCode.H>
#include <fapiAttributeIds.H>
#include <fapiAttributeService.H>
#include <errl/errlmanager.H>
#include <sys/sync.h>
#include <sys/task.h>
#include <sys/time.h>

// This component
#include <targeting/common/attributes.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
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
 *  @return N/A
 */
void funcTestMutex(void* i_pData)
{
    MutexTestData_t* l_pData = static_cast<MutexTestData_t*>(i_pData);
    barrier_wait(l_pData->pBarrier);
    mutex_lock(l_pData->pMutex);
    *(l_pData->pVar) = 1;
    mutex_unlock(l_pData->pMutex);
    barrier_wait(l_pData->pBarrier);
    task_end();
}

class TargetingTestSuite : public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Test Hostboot specific mutex attribute support
     */
    void testHbMutexAttr()
    {
        TS_TRACE(ENTER_MRK "testHbMutexAttr" );

        using namespace TARGETING;
        using namespace fapi;

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

        // Create a structue holding pointers to the mutex and a protected value
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
        using namespace fapi;

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

        errlCommit(l_err, TARG_COMP_ID);

        TS_TRACE(EXIT_MRK "testErrlTargetFFDC");
    }
};

#endif // End __TARGETING_TESTTARGETING_H
