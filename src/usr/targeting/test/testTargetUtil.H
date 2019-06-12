/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/testTargetUtil.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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

#ifndef __TEST_TARGETING_UTIL_H
#define __TEST_TARGETING_UTIL_H

/**
 *  @file targeting/test/testTargetUtil.H
 *
 *  @brief Unit test for the templates makeAttribute
 *         and makeAttributeStdArr
 */

//******************************************************************************
// Includes
//******************************************************************************

// CXX TEST
#include <cxxtest/TestSuite.H>

#include <targeting/common/targetUtil.H>

using namespace TARGETING;

//******************************************************************************
// class MakeAttributeTest
//******************************************************************************
class MakeAttributeTest: public CxxTest::TestSuite
{
public:

    /**
     *  @test Test the Make Attribute template
     */
    void testMakeAttribute(void);

    /**
     *  @test Test the Make Attribute for Standard Array template
     */
    void  testMakeAttributeStdArr(void);

};  //  end class MakeAttributeTest

// testMakeAttribute
void MakeAttributeTest::testMakeAttribute(void)
{
    TRACFCOMP( g_trac_test, ENTER_MRK "testMakeAttribute" );

    // Test stats
    uint8_t l_numTests(0);
    uint8_t l_numFails(0);

    if (!TARGETING::targetService().isInitialized())
    {
        TS_FAIL("testMakeAttribute: Target Service is not initialized, "
                "cannot perform test, exiting");

        TRACFCOMP( g_trac_test, EXIT_MRK "testMakeAttribute "
               "num tests = 1  / num fails = 1");
        return;
    }

    // Get the top level target
    TARGETING::Target * l_sys(nullptr);
    TARGETING::targetService().getTopLevelTarget( l_sys );

    if(!l_sys)
    {
        TS_FAIL("testMakeAttribute: Get Top Level Target failed, "
                "unable to get top level target, cannot perform "
                "test, exiting");

        TRACFCOMP( g_trac_test, EXIT_MRK "testMakeAttribute "
               "num tests = 1  / num fails = 1");
        return;
    }

    // Save initial value to restore later
    uint8_t l_simpleTypeRestoreValue =
                       l_sys->getAttr<TARGETING::ATTR_IS_SIMULATION>();

    // Test 1, test a simple attribute with known data
    ++l_numTests;
    do
    {
        // Set the attribute 'Is Simulation' to a known value to
        // facilitate testing
        uint8_t l_isSimulationSet = 1;
        l_sys->setAttr<TARGETING::ATTR_IS_SIMULATION>(l_isSimulationSet);
        uint8_t l_isSimulationReturn =
                       l_sys->getAttr<TARGETING::ATTR_IS_SIMULATION>();

        // Verify setting the attribute worked
        if (l_isSimulationSet != l_isSimulationReturn)
        {
            TS_FAIL("testMakeAttribute: Test 1 - Setting attribute failed "
                    "to initialize attribute to %d but retained "
                    "value at %d, cannot perform test, exiting",
                    l_isSimulationSet,
                    l_isSimulationReturn);
            ++l_numFails;
            break;
        }

        // Retrieve that set attribute back via the 'make attribute' call
        TARGETING::AttributeTank::Attribute l_attribute;
        bool l_return =
                TARGETING::makeAttribute<TARGETING::ATTR_IS_SIMULATION>
                                                  (l_sys, l_attribute);

        // Verify the called worked
        if (true != l_return)
        {
            TS_INFO("testMakeAttribute: Test 1 - Make attribute call failed");
            ++l_numFails;
            break;
        }

        // Get a pointer to the attribute created in make attribute call,
        // to get to the data.
        const uint8_t* l_attributeValue =
                        static_cast<const uint8_t*>(l_attribute.getValue());

        // If the pointer to the data is NULL, then the make attribute did fail
        if (l_attributeValue == nullptr)
        {
            TS_INFO("testMakeAttribute: Test 1 - Getting attribute value "
                    "failed, NULL pointer returned when getting value.");
            ++l_numFails;
            break;
        }

        // Verify the returned attribute matches it's set value
        if (*l_attributeValue != l_isSimulationSet)
        {
           TS_INFO("testMakeAttribute: Test 1 - Retrieved attribute value "
                    "failed, retrieved attribute value(%d) does not "
                    "match set attribute value(%d)",
                    l_isSimulationSet,
                    *l_attributeValue);
            ++l_numFails;
            break;
        }
    }
    while (0);

    // Test 2, test the same simple attribute but with different data
    ++l_numTests;
    do
    {
        // Set the attribute 'Is Simulation' to a known value to
        // facilitate testing
        uint8_t l_isSimulationSet = 5;
        l_sys->setAttr<TARGETING::ATTR_IS_SIMULATION>(l_isSimulationSet);
        uint8_t l_isSimulationReturn =
                       l_sys->getAttr<TARGETING::ATTR_IS_SIMULATION>();

        // Verify setting the attribute worked
        if (l_isSimulationSet != l_isSimulationReturn)
        {
            TS_FAIL("testMakeAttribute: Test 2 - Setting attribute failed "
                    "to initialize attribute to %d but retained "
                    "value at %d, cannot perform test, exiting",
                    l_isSimulationSet,
                    l_isSimulationReturn);
            ++l_numFails;
            break;
        }

        // Retrieve that set attribute back via the 'make attribute' call
        TARGETING::AttributeTank::Attribute l_attribute;
        bool l_return =
                TARGETING::makeAttribute<TARGETING::ATTR_IS_SIMULATION>
                                                  (l_sys, l_attribute);

        // Verify the called worked
        if (true != l_return)
        {
            TS_INFO("testMakeAttribute: Test 2 - Make attribute call failed");
            ++l_numFails;
            break;
        }

        // Get a pointer to the attribute created in make attribute call,
        // to get to the data.
        const uint8_t* l_attributeValue =
                        static_cast<const uint8_t*>(l_attribute.getValue());

        // If the pointer to the data is NULL, then the make attribute did fail
        if (l_attributeValue == nullptr)
        {
            TS_INFO("testMakeAttribute: Test 1 - Getting attribute value "
                    "failed, NULL pointer returned when getting value.");
            ++l_numFails;
            break;
        }

        // Verify the returned attribute matches it's set value
        if (*l_attributeValue != l_isSimulationSet)
        {
           TS_INFO("testMakeAttribute: Test 2 - Retrieved attribute value "
                    "failed, retrieved attribute value(%d) does not "
                    "match set attribute value(%d)",
                    l_isSimulationSet,
                    *l_attributeValue);
            ++l_numFails;
            break;
        }
    }
    while (0);

    // Restore value
    l_sys->setAttr<TARGETING::ATTR_IS_SIMULATION>(l_simpleTypeRestoreValue);

    TRACFCOMP( g_trac_test, EXIT_MRK "testMakeAttribute "
               "num tests = %d  / num fails = %d", l_numTests, l_numFails);
}  // end testMakeAttribute

// testMakeAttributeStdArr
void MakeAttributeTest::testMakeAttributeStdArr(void)
{
    TRACFCOMP( g_trac_test, ENTER_MRK "testMakeAttributeStdArr" );

    // Test stats
    uint8_t l_numTests(0);
    uint8_t l_numFails(0);


    if (!TARGETING::targetService().isInitialized())
    {
        TS_FAIL("testMakeAttributeStdArr: Target Service is not initialized, "
                "cannot perform test, exiting");

        TRACFCOMP( g_trac_test, EXIT_MRK "testMakeAttributeStdArr: "
               "num tests = 1  / num fails = 1");
        return;
    }

    // Get the top level target
    TARGETING::Target * l_sys(nullptr);
    TARGETING::targetService().getTopLevelTarget( l_sys );

    if(!l_sys)
    {
        TS_FAIL("testMakeAttributeStdArr: Get Top Level Target failed, "
                "unable to get top level target, cannot perform "
                "test, exiting");

        TRACFCOMP( g_trac_test, EXIT_MRK "testMakeAttributeStdArr: "
               "num tests = 1  / num fails = 1");
        return;
    }

    // Save initial value to restore later
    TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS_typeStdArr
            l_complexTypeRestoreValue;

    // Test 1, test a complex attribute with known data
    ++l_numTests;
    do
    {
        // Set the attribute 'IPC Node Buffer Global Address' to a
        // known value to facilitate testing
        TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS_typeStdArr
            l_complexTypeSet = {9, 6, 3, 1, 5, 1, 7, 3};

        if ( !l_sys->trySetAttr<TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>(
                         l_complexTypeSet) )
        {
            TS_FAIL("testMakeAttributeStdArr: Test 1 - can't set "
                    "TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS ");
            ++l_numFails;
            break;
        }

        // Do a sanity check and make sure we can set/get attribute via
        // trySetAttr/tryGetAttr
        TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS_typeStdArr
            l_complexTypeGet;

        if ( !l_sys->tryGetAttr<TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>(
                         l_complexTypeGet) )
        {
            TS_FAIL("testMakeAttributeStdArr: Test 1 - can't get "
                    "TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS ");
            ++l_numFails;
            break;
        }

        // Verify setting the attribute worked
        if (0 != memcmp(&l_complexTypeGet, &l_complexTypeSet,
                         sizeof(l_complexTypeSet)) )
        {
            TS_FAIL("testMakeAttributeStdArr: Test 1 - Setting "
                    "attribute failed, cannot perform test, exiting");
            ++l_numFails;
            break;
        }

        // Retrieved that set attribute back via the 'make attribute' call
        TARGETING::AttributeTank::Attribute l_attribute;
        bool l_return =
                TARGETING::makeAttributeStdArr
                               <TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>
                               (l_sys, l_attribute);

        // Verify the called worked
        if (l_return == false)
        {
            TS_FAIL("testMakeAttributeStdArr: Test 1 - Make "
                    "attribute call failed");
            ++l_numFails;
            break;
        }

        // Get a pointer to the attribute created in make attribute call,
        // to get to the data.
        const uint8_t* l_attributeValue =
                        static_cast<const uint8_t*>(l_attribute.getValue());

        // If the pointer to the data is NULL, then the make attribute did fail
        if (l_attributeValue == nullptr)
        {
            TS_INFO("testMakeAttributeStdArr: Test 1 - Getting attribute value "
                    "failed, NULL pointer returned when getting value.");
            ++l_numFails;
        }

        // Verify the returned attribute matches it's set value
        if (0 != memcmp(l_attributeValue, &l_complexTypeSet,
                         sizeof(l_complexTypeSet)) )
        {
           TS_INFO("testMakeAttributeStdArr: Test 1 - Retrieved attribute "
                   "value failed, expected value and retrieved value do "
                   "not match");
            ++l_numFails;
            break;
        }
    }
    while (0);


    // Test 2, test the same complex attribute but with different data
    ++l_numTests;
    do
    {
        // Set the attribute 'IPC Node Buffer Global Address' to a
        // known value to facilitate testing
        TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS_typeStdArr
            l_complexTypeSet = {1, 2, 6, 8, 3, 2, 9, 3};

        if ( !l_sys->trySetAttr<TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>(
                         l_complexTypeSet) )
        {
            TS_FAIL("testMakeAttributeStdArr: Test 2 - can't set "
                    "TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS ");
            ++l_numFails;
            break;
        }

        // Do a sanity check and make sure we can set/get attribute via
        // trySetAttr/tryGetAttr
        TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS_typeStdArr
            l_complexTypeGet;

        if ( !l_sys->tryGetAttr<TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>(
                         l_complexTypeGet) )
        {
            TS_FAIL("testMakeAttributeStdArr: Test 2 - can't get "
                    "TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS ");
            ++l_numFails;
            break;
        }

        // Verify setting the attribute worked
        if (0 != memcmp(&l_complexTypeGet, &l_complexTypeSet,
                         sizeof(l_complexTypeSet)) )
        {
            TS_FAIL("testMakeAttributeStdArr: Test 2 - Setting "
                    "attribute failed, cannot perform test, exiting");
            ++l_numFails;
            break;
        }

        // Retrieved that set attribute back via the 'make attribute' call
        TARGETING::AttributeTank::Attribute l_attribute;
        bool l_return =
                TARGETING::makeAttributeStdArr
                               <TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>
                               (l_sys, l_attribute);

        // Verify the called worked
        if (l_return == false)
        {
            TS_FAIL("testMakeAttributeStdArr: Test 2 - Make "
                    "attribute call failed");
            ++l_numFails;
            break;
        }

        // Get a pointer to the attribute created in make attribute call,
        // to get to the data.
        const uint8_t* l_attributeValue =
                        static_cast<const uint8_t*>(l_attribute.getValue());

        // If the pointer to the data is NULL, then the make attribute did fail
        if (l_attributeValue == nullptr)
        {
            TS_INFO("testMakeAttributeStdArr: Test 2 - Getting attribute value "
                    "failed, NULL pointer returned when getting value.");
            ++l_numFails;
        }

        // Verify the returned attribute matches it's set value
        if (0 != memcmp(l_attributeValue, &l_complexTypeSet,
                         sizeof(l_complexTypeSet)) )
        {
           TS_INFO("testMakeAttributeStdArr: Test 2 - Retrieved attribute "
                   "value failed, expected value and retrieved value do "
                   "not match");
            ++l_numFails;
            break;
        }
    }
    while (0);

    // Restore value
    l_sys->trySetAttr<TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>(
                         l_complexTypeRestoreValue);

    TRACFCOMP( g_trac_test, EXIT_MRK "testMakeAttributeStdArr "
               "num tests = %d  / num fails = %d", l_numTests, l_numFails);

}  // end testMakeAttributeStdArr

#endif  // end __TEST_ATTRIBUTE_H
