//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/devicefw/test/associatortest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#ifndef __TEST_ASSOCIATORTEST_H
#define __TEST_ASSOCIATORTEST_H

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <devicefw/devfwreasoncodes.H>
#include "../associator.H"

using namespace DeviceFW;
using namespace TARGETING;

class AssociatorTest;
typedef void (AssociatorTest::*test_fn)();

static test_fn g_associatorTest_value;
static test_fn g_associatorTest_result;
static OperationType g_associatorTest_opType;
static int64_t g_associatorTest_accessType;

class AssociatorTest: public CxxTest::TestSuite
{
public:
    
    /**
     * @test Ensure AssociationContainer can be constructed.
     */
    void testConstruct()
    {
        Associator* as = new Associator();
        if (NULL == as)
        {
            TS_FAIL("Unable to construct Associator.");
        }
        delete as;
    }

    // Used for registration testing.
    static
    errlHndl_t performOperation(OperationType i_opType,
                                Target* i_target,
                                void* io_buffer, size_t& io_buflen,
                                int64_t i_accessType, va_list i_addr)
    {
        g_associatorTest_result = g_associatorTest_value;
        g_associatorTest_opType = i_opType;
        g_associatorTest_accessType = i_accessType;

        return NULL;
    }
    
    /**
     * @test Verify simple registration.
     */
    void testSimpleRegistration()
    {
        void* buf = NULL;
        size_t bufsize = 0;

        g_associatorTest_value = &AssociatorTest::testSimpleRegistration;

        Associator as;
        as.registerRoute(READ,
                         SCOM,
                         TYPE_PROC,
                         &performOperation);
        
        errlHndl_t l_errl = as.performOp(READ, 
                                         MASTER_PROCESSOR_CHIP_TARGET_SENTINEL, 
                                         buf, bufsize,
                                         SCOM, va_list());

        if (l_errl)
        {
            TS_FAIL("Error received from performOp.");
        }

        if (g_associatorTest_result != g_associatorTest_value)
        {
            TS_FAIL("PerformOperation does not appear to have been called.");
        }

        if (g_associatorTest_opType != READ)
        {
            TS_FAIL("Invalid operation type.");
        }

        if (g_associatorTest_accessType != SCOM)
        {
            TS_FAIL("Invalid access type.");
        }
    }

    /**
     * @test Verify we catch double registration.
     */
    void testDoubleRegistration()
    {
        errlHndl_t l_errl = NULL;

        // Register non-sensical SCOM-READ to Nodes
        Associator as;
        l_errl = as.registerRoute(READ,
                                  SCOM,
                                  TYPE_NODE,
                                  &performOperation);
        if (l_errl)
        {
            TS_FAIL("testDoubleRegistration> Error received from registerRoute (1).");
        }

        // Register the exact same thing again
        l_errl = as.registerRoute(READ,
                                  SCOM,
                                  TYPE_NODE,
                                  &performOperation);

        if (l_errl)
        {
            // error log is expected case, delete it
            delete l_errl;
        }
        else
        {
            TS_FAIL("testDoubleRegistration> No error from duplicate registration.");
        }

        // Register a wildcard that overlaps
        l_errl = as.registerRoute(WILDCARD,
                                  SCOM,
                                  TYPE_NODE,
                                  &performOperation);

        if (l_errl)
        {
            // error log is expected case, delete it
            delete l_errl;
        }
        else
        {
            TS_FAIL("testDoubleRegistration> No error from wildcard registration.");
        }

        // Reverse the wildcard test
        l_errl = as.registerRoute(WILDCARD,
                                  PNOR,
                                  TYPE_NODE,
                                  &performOperation);
        if (l_errl)
        {
            TS_FAIL("testDoubleRegistration> Error received from registerRoute (2).");
        }
        l_errl = as.registerRoute(WRITE,
                                  PNOR,
                                  TYPE_NODE,
                                  &performOperation);
        if (l_errl)
        {
            // error log is expected case, delete it
            delete l_errl;
        }
        else
        {
            TS_FAIL("testDoubleRegistration> No error from registration after wildcard.");
        }


    }

    /**
     * @test Verify registration with an operator as a WILDCARD.
     */
    void testOpWildcard()
    {
        void* buf = NULL;
        size_t bufsize = 0;

        g_associatorTest_value = &AssociatorTest::testOpWildcard;

        Associator as;
        as.registerRoute(WILDCARD,
                         SCOM,
                         TYPE_PROC,
                         &performOperation);
        
        errlHndl_t l_errl = as.performOp(WRITE,
                                         MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                         buf, bufsize,
                                         SCOM, va_list());

        if (l_errl)
        {
            TS_FAIL("Error received from performOp.");
        }

        if (g_associatorTest_result != g_associatorTest_value)
        {
            TS_FAIL("PerformOperation does not appear to have been called.");
        }

        if (g_associatorTest_opType != WRITE)
        {
            TS_FAIL("Invalid operation type.");
        }

        if (g_associatorTest_accessType != SCOM)
        {
            TS_FAIL("Invalid access type.");
        }
    }
    
    /**
     * @test Verify registration with a target type as a WILDCARD.
     */
    void testTargTypeWildcard()
    {
        void* buf = NULL;
        size_t bufsize = 0;

        g_associatorTest_value = &AssociatorTest::testTargTypeWildcard;

        Associator as;
        as.registerRoute(READ,
                         SCOM,
                         WILDCARD,
                         &performOperation);
        
        errlHndl_t l_errl = as.performOp(READ, 
                                         MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                         buf, bufsize,
                                         SCOM, va_list());

        if (l_errl)
        {
            TS_FAIL("Error received from performOp.");
        }

        if (g_associatorTest_result != g_associatorTest_value)
        {
            TS_FAIL("PerformOperation does not appear to have been called.");
        }

        if (g_associatorTest_opType != READ)
        {
            TS_FAIL("Invalid operation type.");
        }

        if (g_associatorTest_accessType != SCOM)
        {
            TS_FAIL("Invalid access type.");
        }
    }

        
    /**
     * @test Verify missing registration returns an error log.
     */
    void testMissingRegistration()
    {
        void* buf = NULL;
        size_t bufsize = 0;

        g_associatorTest_value = &AssociatorTest::testMissingRegistration;

        Associator as;
        as.registerRoute(READ,
                         SCOM,
                         WILDCARD,
                         &performOperation);
        
        errlHndl_t l_errl = as.performOp(READ,
                                         MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                         buf, bufsize,
                                         MAILBOX, va_list());

        if (NULL == l_errl)
        {
            TS_FAIL("Error not received from performOp.");
        }
        else if (DEVFW_RC_NO_ROUTE_FOUND != l_errl->reasonCode())
        {
            TS_FAIL("Reason code different from DEVFW_RC_NO_ROUTE_FOUND.");
        }
    }


};

#endif

