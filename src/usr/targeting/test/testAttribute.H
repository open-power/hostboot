/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/testAttribute.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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

#ifndef __TEST_ATTRIBUTE_H
#define __TEST_ATTRIBUTE_H

/**
 *  @file targeting/test/testAttribute.H
 *
 *  @brief Unit test for TARGETING::AttributeTank::Attribute
 */

//******************************************************************************
// Includes
//******************************************************************************

// CXX TEST
#include <cxxtest/TestSuite.H>

#include <targeting/common/attributeTank.H>

#include <attributeenums.H>
#include <attributetraits.H>

#include <targeting/common/commontargeting.H>
#include <targeting/common/trace.H>
#include <targeting/targplatutil.H>


using namespace TARGETING;

class AttributeTest: public CxxTest::TestSuite
{
public:
    /**
     *  @test Tests the setters and getter methods
     */
    void testSimpleSettersAndGetters(void);

    /**
     *  @test Test setting the Attribute Value
     */
    void testSettingAndGettingValue(void);

    /**
     *  @test Test Serialize and Deserialize methods
     */
    void testSerializeAndDeserializeMethod(void);

    /**
     *  @test Test the Operator Equal method
     */
    void testOperatorEqual(void);

    /**
     *  @test Test the Copy Constructor Method
     */
    void testCopyConstructor(void);

    void testGeneratedInvalidsForAttr(void);

    private:

    /**
     *  @test Compare the Attribute Header for the two given attributes
     *
     *  @param[in] l_attribute1 Attribute to compare with
     *  @param[in] l_attribute2 Attribute to compare with
     *
     *  @return true if Attribute Header's match, false otherwise
     */
    bool compareAttributeHeader(
                     const AttributeTank::Attribute* const l_attribute1,
                     const AttributeTank::Attribute* const l_attribute2);

    /**
     *  @test Compare the Attribute Values for the two given attributes
     *
     *  @param[in] l_attribute1 Attribute to compare with
     *  @param[in] l_attribute2 Attribute to compare with
     *
     *  @return true if Attribute Values` match, false otherwise
     */
    bool compareAttributeValues(
                     const AttributeTank::Attribute* const l_attribute1,
                     const AttributeTank::Attribute* const l_attribute2);

    /**
     *  @test check that an Attribute Invalid value is assigned
     *  to the maximum value for its size
     *
     *  @param[in] invalidEnumVal Attribute Invalid value to check
     *
     *  @return true if the Invalid Value is set to the max value, false otherwise
     */
    template<typename T>
    bool isEnumMaxVal(const T invalidEnumVal);


};  //  end class AttributeTest


// testSimpleSettersAndGetters
void AttributeTest::testSimpleSettersAndGetters(void)
{
    TRACFCOMP( g_trac_test, ENTER_MRK "testSimpleSettersAndGetters" );

    // Test stats
    uint8_t l_numTests(0);
    uint8_t l_numFails(0);

    // Create an Attribute to test against
    TARGETING::AttributeTank::Attribute l_attribute;

    // Get a reference to the Attribute Header to test that
    // what is returned is truly a reference and not a copy
    const TARGETING::AttributeTank::AttributeHeader &l_attributeHeader =
                                        l_attribute.getHeader();

    // Test setting/getting the Attribute ID
    ++l_numTests;
    l_attribute.setId(0x1001);
    if (0x1001 != l_attribute.getHeader().iv_attrId)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 1 - "
                "set/get Attribute ID failed; "
                "expected 0x1001 but got back 0x%X",
                l_attribute.getHeader().iv_attrId);
        ++l_numFails;
    }

    ++l_numTests;
    if (0x1001 != l_attributeHeader.iv_attrId)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 2 - get Attribute ID "
                "via Attribute Header reference failed; "
                "expected 0x1001 but got back 0x%X",
                l_attributeHeader.iv_attrId);
        ++l_numFails;
    }

    // Test setting/getting the Attribute Target Type
    ++l_numTests;
    l_attribute.setTargetType(0x2002);
    if (0x2002 != l_attribute.getHeader().iv_targetType)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 3 - "
                "set/get Attribute Target Type failed; "
                "expected 0x2002 but got back 0x%X",
                l_attribute.getHeader().iv_targetType);
        ++l_numFails;
    }

    ++l_numTests;
    if (0x2002 != l_attributeHeader.iv_targetType)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 4 - get Attribute "
                "Target Type via Attribute Header reference failed; "
                "expected 0x2002 but got back 0x%X",
                l_attributeHeader.iv_targetType);
        ++l_numFails;
    }

    // Test setting/getting the Attribute Position
    ++l_numTests;
    l_attribute.setPosition(0x3003);
    if (0x3003 != l_attribute.getHeader().iv_pos)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 5 - "
                "set/get Attribute Position failed; "
                "expected 0x3003 but got back 0x%X",
                l_attribute.getHeader().iv_pos);
        ++l_numFails;
    }

    ++l_numTests;
    if (0x3003 != l_attributeHeader.iv_pos)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 6 - get Attribute Position "
                "via Attribute Header reference failed; "
                "expected 0x3003 but got back 0x%X",
                l_attributeHeader.iv_pos);
        ++l_numFails;
    }

    // Test setting/getting the Attribute Unit Position
    ++l_numTests;
    l_attribute.setUnitPosition(0x4);
    if (0x4 != l_attribute.getHeader().iv_unitPos)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 7 - "
                "set/get Attribute Unit Position failed; "
                "expected 0x4 but got back 0x%X",
                l_attribute.getHeader().iv_unitPos);
        ++l_numFails;
    }

    ++l_numTests;
    if (0x4 != l_attributeHeader.iv_unitPos)
    {
       TS_FAIL("testSimpleSettersAndGetters: Test 8 - "
               "get Attribute Unit Position via Attribute Header reference "
               "failed; expected 0x4 but got back 0x%X",
               l_attributeHeader.iv_unitPos);
        ++l_numFails;
    }

    // Test setting/getting the Attribute Node
    ++l_numTests;
    l_attribute.setNode(0x5);
    if (0x5 != l_attribute.getHeader().iv_node)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 9 - "
                "set/get Attribute Node failed; "
                "expected 0x5 but got back 0x%X",
                l_attribute.getHeader().iv_node);
        ++l_numFails;
    }

    ++l_numTests;
    if (0x5 != l_attributeHeader.iv_node)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 10 - get Attribute Node "
                "via Attribute Header reference failed; "
                "expected 0x5 but got back 0x%X",
                l_attributeHeader.iv_node);
        ++l_numFails;
    }

    // Test setting/getting the Attribute Flags
    ++l_numTests;
    l_attribute.setFlags(0x6);
    if (0x6 != l_attribute.getHeader().iv_flags)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 11 - "
                "set/get Attribute Flags failed; "
                "expected 0x6 but got back 0x%X",
                l_attribute.getHeader().iv_flags);
        ++l_numFails;
    }

    ++l_numTests;
    if (0x6 != l_attributeHeader.iv_flags)
    {
        TS_FAIL("testSimpleSettersAndGetters: Test 12 - get Attribute Flags "
                "via Attribute Header reference failed; "
                "expected 0x6 but got back 0x%X",
                l_attributeHeader.iv_flags);
        ++l_numFails;
    }

    TRACFCOMP( g_trac_test, EXIT_MRK "testSimpleSettersAndGetters "
               "num tests = %d  / num fails = %d", l_numTests, l_numFails);
}  // end testSimpleSettersAndGetters


// testSettingAndGettingValue
void AttributeTest::testSettingAndGettingValue(void)
{
    TRACFCOMP( g_trac_test, ENTER_MRK "testSettingAndGettingValue" );

    // Test stats
    uint8_t l_numTests(0);
    uint8_t l_numFails(0);

    // Create an Attribute to test with
    TARGETING::AttributeTank::Attribute l_attribute;

    /// Test getting Size of the Attribute when no Value exists/has been set
    ++l_numTests;
    if (l_attribute.getSize() !=
                            sizeof(TARGETING::AttributeTank::AttributeHeader))
    {
        TS_FAIL("testSettingAndGettingValue: Test 1 - "
                 "get Attribute Size failed, when no value set; "
                 "expected size %d but got back size %d",
                 sizeof(TARGETING::AttributeTank::AttributeHeader),
                 l_attribute.getSize());
        ++l_numFails;
    }

    /// Test cloning the value when no Value exists/has been set
    // First create a buffer
    uint32_t l_bufferSize = 3;
    uint8_t l_buffer[l_bufferSize] = { 0 };
    uint8_t l_compareBuffer[l_bufferSize] = { 0 };

    uint32_t l_returnedSize = l_attribute.cloneValue(l_buffer, l_bufferSize);
    // Make sure 0 is returned
    ++l_numTests;
    if (0 != l_returnedSize)
    {
        TS_FAIL("testSettingAndGettingValue: Test 2 - "
                "Attribute clone value failed, with buffer size 0; "
                "expected size 0 but got back size %d",
                l_returnedSize);
        ++l_numFails;
    }

    // Make sure cloned data is correct
    ++l_numTests;
    if (0 != memcmp(l_buffer, l_compareBuffer, l_bufferSize))
    {
        TS_FAIL("testSettingAndGettingValue: Test 3 - "
                "Attribute clone value failed, with buffer size 0; "
                "incorrect data returned");
        ++l_numFails;
    }

    /// Test clearing the Value
    l_returnedSize = l_attribute.setValue(nullptr, 0);
    // Make sure 0 is returned
    ++l_numTests;
    if (0 != l_returnedSize)
    {
        TS_FAIL("testSettingAndGettingValue: Test 4 - "
                "returned Attribute Size failed, sent a value of size 0; "
                "expected size 0 but got back size %d",
                l_returnedSize);
        ++l_numFails;
    }

    // Make sure size is only the Attribute Header size
    ++l_numTests;
    if (l_attribute.getSize() !=
                            sizeof(TARGETING::AttributeTank::AttributeHeader))
    {
        TS_FAIL("testSettingAndGettingValue: Test 5 - "
                     "get Attribute Size failed, sent a value of size 0; "
                     "expected size %d but got back size %d",
                     sizeof(TARGETING::AttributeTank::AttributeHeader),
                     l_attribute.getSize());
        ++l_numFails;
    }

    // Make sure value is NULL
    ++l_numTests;
    if (nullptr != l_attribute.getValue())
    {
        TS_FAIL("testSettingAndGettingValue: Test 6 - "
                "get Attribute Value failed, sent a value of size 0; "
                "expected nullptr but got back %p",
                l_attribute.getValue());
        ++l_numFails;
    }

    /// Send in buffer with smaller size than actual size of buffer
    // Add data o the buffer
    l_buffer[0] = 0xAA;
    l_buffer[1] = 0xBB;
    l_buffer[2] = 0xCC;

    // Set the Attribute Value to the buffer's first element
    l_returnedSize = l_attribute.setValue(l_buffer, 1);
    // Make sure only 1 is returned
    ++l_numTests;
    if (1 != l_returnedSize)
    {
        TS_FAIL("testSettingAndGettingValue: Test 7 - "
                "returned Attribute Size failed, sent a value of size 1; "
                "expected size 1 but got back size %d",
                l_returnedSize);
        ++l_numFails;
    }

    // Make sure Attribute Value size is size of Attribute Header plus one
    ++l_numTests;
    if (l_attribute.getSize() !=
             (sizeof(TARGETING::AttributeTank::AttributeHeader) + 1))
    {
        TS_FAIL("testSettingAndGettingValue: Test 8 - "
                "get Attribute Size failed, sent a Value of size 1 "
                "expected size %d but got back size %d",
                sizeof(TARGETING::AttributeTank::AttributeHeader) + 1,
                l_attribute.getSize());
        ++l_numFails;
    }

    // Get a handle to the Value to do some testing on it
    const uint8_t* const l_value =
                reinterpret_cast<const uint8_t* const>(l_attribute.getValue());

    // Make sure Value is not NULL
    ++l_numTests;
    if (nullptr == l_value)
    {
        TS_FAIL("testSettingAndGettingValue: Test 9 - "
                     "get Attribute Value failed; "
                     "expected a non-null pointer but got back a null pointer");
        ++l_numFails;
    }

    // Make sure the first value is what we expect
    ++l_numTests;
    if (l_value[0] != 0xAA)
    {
        TS_FAIL("testSettingAndGettingValue: Test 10 - "
                "Accessing first value in Attribute Value failed; "
                "expected 0xAA but got back 0x%X",
                l_value[0]);
        ++l_numFails;
    }

    // Test cloning with Attribute
    uint8_t l_clonedBuffer[l_bufferSize] = { 0 };
    memset(l_compareBuffer, 0, l_bufferSize);
    l_compareBuffer[0] = 0xAA;
    l_returnedSize = l_attribute.cloneValue(l_clonedBuffer, l_bufferSize);
    // Make sure 1 is returned
    ++l_numTests;
    if (1 != l_returnedSize)
    {
        TS_FAIL("testSettingAndGettingValue: Test 11 - "
                "Attribute clone value failed, with buffer size 1; "
                "expected size 1 but got back size %d",
                l_returnedSize);
        ++l_numFails;
    }

    // Make sure the cloned data is correct
    ++l_numTests;
    if (0 != memcmp(l_clonedBuffer, l_compareBuffer, l_bufferSize))
    {
        TS_FAIL("testSettingAndGettingValue: Test 12 - "
                "Attribute clone value failed, with buffer size 1; "
                "incorrect data returned");
        ++l_numFails;
    }

    /// Send in buffer with actual size of said buffer
    // First set the buffer's values
    l_buffer[0] = 0xDD;
    l_buffer[1] = 0xEE;
    l_buffer[2] = 0xFF;
    l_returnedSize = l_attribute.setValue(l_buffer, l_bufferSize);

    // Make sure buffer size is returned correctly
    ++l_numTests;
    if (l_bufferSize != l_returnedSize)
    {
        TS_FAIL("testSettingAndGettingValue: Test 13 - "
                "returned Attribute Size failed, sent a buffer of size %d; "
                "expected size %d but got back size %d",
                l_bufferSize,
                l_bufferSize,
                l_returnedSize);
        ++l_numFails;
    }

    // Make sure Attribute Value size is size of Attribute Header
    // plus buffer size
    ++l_numTests;
    if (l_attribute.getSize() !=
            (sizeof(TARGETING::AttributeTank::AttributeHeader) + l_bufferSize))
    {
        TS_FAIL("testSettingAndGettingValue: Test 14 - "
              "get Attribute Size failed, sent a buffer of size %d; "
              "expected size %d but got back size %d",
              l_bufferSize,
              sizeof(TARGETING::AttributeTank::AttributeHeader) + l_bufferSize,
              l_attribute.getSize());
        ++l_numFails;
    }

    // Get a handle to the Value to do some testing on it
    const uint8_t* const l_value2 =
                reinterpret_cast<const uint8_t* const>(l_attribute.getValue());

    // Make sure Value is not NULL
    ++l_numTests;
    if (nullptr == l_value2)
    {
        TS_FAIL("testSettingAndGettingValue: Test 15 - "
                "get Attribute Value failed, sent a buffer of size %d "
                "expected a non-null pointer but got back a null pointer",
                l_bufferSize);
        ++l_numFails;
    }

    // Make sure the first value is what we expect
    ++l_numTests;
    if (l_value2[0] != 0xDD)
    {
        TS_FAIL("testSettingAndGettingValue: Test 16 - "
                "Accessing first value in Attribute Value failed, "
                "for a Value of size %d; "
                "expected 0xDD but got back 0x%X",
                l_bufferSize,
                l_value2[0]);
        ++l_numFails;
    }

    // Make sure the second value is what we expect
    ++l_numTests;
    if (l_value2[1] != 0xEE)
    {
        TS_FAIL("testSettingAndGettingValue: Test 17 - "
                "Accessing second value in Attribute Value failed, "
                "for a Value of size %d; "
                "expected 0xEE but got back 0x%X",
                l_bufferSize,
                l_value2[1]);
        ++l_numFails;
    }

    // Make sure the third value is what we expect
    ++l_numTests;
    if (l_value2[2] != 0xFF)
    {
        TS_FAIL("testSettingAndGettingValue: Test 18 - "
                "Accessing third value in Attribute Value failed, "
                "for a Value of size %d; "
                "expected 0xFF but got back 0x%X",
                l_bufferSize,
                l_value2[2]);
        ++l_numFails;
    }

    /// Make sure previously cloned data is an actually cloned and not
    /// a copy
    ++l_numTests;
    if (0 != memcmp(l_clonedBuffer, l_compareBuffer, l_bufferSize))
    {
        TS_FAIL("testSettingAndGettingValue: Test 19 - "
                "Attribute clone value failed, with buffer size 1; "
                "data not cloned but is a reference a pointer");
        ++l_numFails;
    }

    l_returnedSize = l_attribute.cloneValue(l_clonedBuffer, l_bufferSize);
    // Make sure 3 is returned
    ++l_numTests;
    if (3 != l_returnedSize)
    {
        TS_FAIL("testSettingAndGettingValue: Test 20 - "
                "returned Attribute clone value failed, with buffer size 3; "
                "expected size 3 but got back size %d",
                l_returnedSize);
        ++l_numFails;
    }

    /// Make sure previously cloned data is correct
    ++l_numTests;
    if (0 != memcmp(l_clonedBuffer, l_buffer, l_bufferSize))
    {
        TS_FAIL("testSettingAndGettingValue: Test 21 - "
                "Attribute clone value failed, with buffer size 3 ; "
                "incorrect data returned");
        ++l_numFails;
    }

    TRACFCOMP( g_trac_test, EXIT_MRK "testSettingAndGettingValue "
               "num tests = %d  / num fails = %d", l_numTests, l_numFails);
}  // end AttributeTest::testSettingAndGettingValue


// testSerializeAndDeserializeMethod
void AttributeTest::testSerializeAndDeserializeMethod(void)
{
    TRACFCOMP( g_trac_test, ENTER_MRK "testSerializeAndDeserializeMethod" );

    // Test stats
    uint8_t l_numTests(0);
    uint8_t l_numFails(0);

    // Create an Attribute to test with
    AttributeTank::Attribute l_attribute;
    // Get a copy of the Attribute Size for later purposes
    uint32_t l_attributeSize(l_attribute.getSize());

    /// Test serializing when attribute has no data at all
    {
        // Create a buffer to hold serialized data
        uint8_t* l_serializedData = new uint8_t[l_attributeSize];
        // Get the serialized data
        uint32_t l_returnedSize = l_attribute.serialize(l_serializedData,
                                                        l_attributeSize);

        // Make sure serialized data is the size expected
        ++l_numTests;
        if (l_returnedSize != l_attributeSize)
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 1 - "
                    "Attribute Serialize failed, with a 0 size Data Value; "
                    "expected size %d but got back size %d",
                     l_attributeSize,
                     l_returnedSize);
            ++l_numFails;
        }

        // Make sure the serialized Attribute Header
        // matches original Attribute Header
        // Get a handle to Attribute Header
        AttributeTank::Attribute* l_attribute2 =
                 reinterpret_cast<AttributeTank::Attribute*>(l_serializedData);
        const AttributeTank::AttributeHeader & l_attributeHeader2 =
                                                     l_attribute2->getHeader();

        // Compare the two different Attribute Header for a match
        ++l_numTests;
        if (!compareAttributeHeader(l_attribute2, &l_attribute))
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 2 - "
                    "Attribute Serialize failed, with a 0 size Data Value; "
                    "incorrect Attribute Header data returned");
            ++l_numFails;
        }

        // Make sure that the size of the Attribute Values is zero
        ++l_numTests;
        if (0 != l_attributeHeader2.iv_valSize)
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 3 - "
                    "Attribute Serialize failed, with a 0 size Data Value; "
                    "Expected 0 size Data Value but %d was returned",
                    l_attributeHeader2.iv_valSize);
            ++l_numFails;
        }

        // Test deserialize
        {
            AttributeTank::Attribute l_attribute3;
            uint32_t l_returnedSize2 =
                    l_attribute3.deserialize(l_serializedData, l_returnedSize);

            // Make sure data size copied is correct
            ++l_numTests;
            if (l_returnedSize2 != l_returnedSize)
            {
                TS_FAIL("testSerializeAndDeserializeMethod: Test 4 - "
                     "Attribute Deserialize failed, with a 0 size Data Value; "
                     "expected size %d but got back size %d",
                     l_returnedSize,
                     l_returnedSize2);
                ++l_numFails;
            }

            // Make sure the Attribute Header matches original data
            ++l_numTests;
            if (!compareAttributeHeader(&l_attribute3, &l_attribute))
            {
                TS_FAIL("testSerializeAndDeserializeMethod: Test 5 - "
                     "Attribute deserialize failed, with a 0 size Data Value; "
                     "incorrect Attribute Header data returned");
                ++l_numFails;
            }

            // Test when buffer is too small
            ++l_numTests;
            AttributeTank::Attribute l_attribute4;
            l_returnedSize2 = l_attribute4.deserialize(l_serializedData,
                                                       l_returnedSize - 1);
            if (0 != l_returnedSize2)
            {
                TS_FAIL("testSerializeAndDeserializeMethod: Test 6 - "
                     "Attribute Deserialize failed, with too small of buffer;"
                     "expected size 0 but got back size %d",
                     l_returnedSize2);
                ++l_numFails;
            }
        }
        // Cleanup memory used for this test
        delete []l_serializedData;
        l_serializedData = nullptr;
    }

    /// Test serializing when Attribute has Attribute Header data
    /// and no Attribute Values
    // Set some values for the Attribute Header
    l_attribute.setId(0x1001);
    l_attribute.setTargetType(0x2002);
    l_attribute.setPosition(0x3003);
    l_attribute.setUnitPosition(0x4);
    l_attribute.setNode(0x5);
    l_attribute.setFlags(0x6);
    {
        // Create a buffer to hold serialized data
        uint8_t* l_serializedData = new uint8_t[l_attributeSize];
        // Get the serialized data
        uint32_t l_returnedSize = l_attribute.serialize(l_serializedData,
                                                        l_attributeSize);

        // Make sure serialized data is the size expected
        ++l_numTests;
        if (l_returnedSize != l_attributeSize)
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 7 - "
                    "Attribute Serialize failed, with valid Attribute "
                    "Header data and no Data Value;"
                    "expected size %d but got back size %d",
                    l_attributeSize,
                    l_returnedSize);
            ++l_numFails;
        }

        // Make sure the serialized Attribute Header
        // matches original Attribute Header
        // Get a handle to Attribute Header
        AttributeTank::Attribute* l_attribute2 =
                 reinterpret_cast<AttributeTank::Attribute*>(l_serializedData);
        const AttributeTank::AttributeHeader & l_attributeHeader2 =
                                                     l_attribute2->getHeader();
        // Compare the two different Attribute Header for a match
        ++l_numTests;
        if (!compareAttributeHeader(l_attribute2, &l_attribute))
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 8 - "
                        "Attribute Serialize failed, with valid Attribute "
                        "Header data and no Data Value;"
                        "incorrect Attribute Header data returned");
            ++l_numFails;
        }

        // Make sure that the size of the Attribute Values is zero
        ++l_numTests;
        if (0 != l_attributeHeader2.iv_valSize)
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 9 - "
                    "Attribute Serialize failed, with valid Attribute "
                    "Header data and no Data Value;"
                    "Expected 0 size Data Value but %d was returned",
                    l_attributeHeader2.iv_valSize);
            ++l_numFails;
        }

        // Test deserialize
        {
            AttributeTank::Attribute l_attribute3;
            uint32_t l_returnedSize2 =
                    l_attribute3.deserialize(l_serializedData, l_returnedSize);

            // Make sure data size copied is correct
            ++l_numTests;
            if (l_returnedSize2 != l_returnedSize)
            {
                TS_FAIL("testSerializeAndDeserializeMethod: Test 10 - "
                        "Attribute Deserialize failed, with valid Attribute "
                        "Header data and no Data Value;"
                        "expected size %d but got back size %d",
                        l_returnedSize,
                        l_returnedSize2);
                ++l_numFails;
            }

            // Make sure the Attribute Header matches original data
            ++l_numTests;
            if (!compareAttributeHeader(&l_attribute3, &l_attribute))
            {
                TS_FAIL("testSerializeAndDeserializeMethod: Test 11 - "
                        "Attribute Deserialize failed, with valid Attribute "
                        "Header data and no Data Value;"
                        "incorrect Attribute Header data returned");
                ++l_numFails;
            }
        }

        // Cleanup memory used for this test
        delete []l_serializedData;
        l_serializedData = nullptr;
    }

    /// Test serializing when Attribute has Attribute Header data
    /// and a single Attribute Value
    // Give the Attribute a single Attribute Value
    uint8_t l_dataBuffer[1] = { 0 };
    l_dataBuffer[0] = 0x44;
    l_attribute.setValue(l_dataBuffer, 1);
    l_attributeSize = l_attribute.getSize();
    {
        // Create a buffer to hold serialized data
        uint8_t* l_serializedData = new uint8_t[l_attributeSize];
        // Get the serialized data
        uint32_t l_returnedSize = l_attribute.serialize(l_serializedData,
                                                        l_attributeSize);

        // Make sure serialized data is the size expected
        ++l_numTests;
        if (l_returnedSize != l_attributeSize)
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 12 - "
                    "Attribute Serialize failed, with a size 1 Data Value; "
                    "expected size %d but got back size %d",
                    l_attributeSize,
                    l_returnedSize);
            ++l_numFails;
        }

        // Make sure the serialized Attribute Header
        // matches original Attribute Header
        // Get a handle to Attribute Header
        AttributeTank::Attribute* l_attribute2 =
                 reinterpret_cast<AttributeTank::Attribute*>(l_serializedData);
        const AttributeTank::AttributeHeader & l_attributeHeader2 =
                                                     l_attribute2->getHeader();
        // Compare the two different Attribute Header for a match
        ++l_numTests;
        if (!compareAttributeHeader(l_attribute2, &l_attribute))
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 13 - "
                    "Attribute Serialize failed, with a size 1 Data Value; "
                    "incorrect Attribute Header data returned");
            ++l_numFails;
        }

        // Make sure that the size of the Attribute Values is 1
        ++l_numTests;
        if (1 != l_attributeHeader2.iv_valSize)
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 14 - "
                    "Attribute Serialize failed, with a size 1 Data Value; "
                    "Expected 1 size Data Value but %d was returned",
                    l_attributeHeader2.iv_valSize);
            ++l_numFails;
        }

        // Point to the Attribute Values
        l_serializedData += sizeof(AttributeTank::AttributeHeader);

        // Compare the two different Attribute Value
        ++l_numTests;
        if (0 != memcmp(l_serializedData, &l_dataBuffer, 1))
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 15 - "
                    "Attribute Serialize failed, with a size 1 Data Value; "
                    "incorrect Attribute Data Value returned");
            ++l_numFails;
        }

        // Reset the Serialized Data for next test
        l_serializedData -= sizeof(AttributeTank::AttributeHeader);

        // Test deserialize
        {
            AttributeTank::Attribute l_attribute3;
            uint32_t l_returnedSize2 =
                    l_attribute3.deserialize(l_serializedData, l_returnedSize);
            // Make sure data size copied is correct
            ++l_numTests;
            if (l_returnedSize2 != l_returnedSize)
            {

                TS_FAIL("testSerializeAndDeserializeMethod: Test 16 - "
                     "Attribute Deserialize failed, with a size 1 Data Value; "
                     "expected size %d but got back size %d",
                     l_returnedSize,
                     l_returnedSize2);
                ++l_numFails;
            }

            // Make sure the Attribute Header matches original data
            ++l_numTests;
            if (!compareAttributeHeader(&l_attribute3, &l_attribute))
            {
                TS_FAIL("testSerializeAndDeserializeMethod: Test 17 - "
                     "Attribute deserialize failed, with a size 1 Data Value; "
                     "incorrect Attribute Header data returned");
                ++l_numFails;
            }

            // Test when buffer is too small
            AttributeTank::Attribute l_attribute4;
            l_returnedSize2 = l_attribute4.deserialize(l_serializedData,
                                                       l_returnedSize - 1);

            // Make sure returned size is 0
            ++l_numTests;
            if (0 != l_returnedSize2)
            {
                TS_FAIL("testSerializeAndDeserializeMethod: Test 18 - "
                     "Attribute Deserialize failed, with too small of buffer "
                     "for 1 data value; expected size 0 but got back size %d",
                     l_returnedSize2);
                ++l_numFails;
            }
        }

        // Cleanup memory used for this test
        delete []l_serializedData;
        l_serializedData = nullptr;
    }

    /// Test serializing when Attribute has Attribute Header data
    /// and a several Attribute Values
    // Give the Attribute several Attribute Values
    uint32_t l_bufferSize(3);
    uint8_t l_dataBuffer2[l_bufferSize] = { 0 };
    l_dataBuffer2[0] = 0x55;
    l_dataBuffer2[1] = 0x66;
    l_dataBuffer2[2] = 0x77;
    l_attribute.setValue(l_dataBuffer2, l_bufferSize);
    l_attributeSize = l_attribute.getSize();
    {
        // Create a buffer to hold serialized data
        uint8_t* l_serializedData = new uint8_t[l_attributeSize];
        // Get the serialized data
        uint32_t l_returnedSize = l_attribute.serialize(l_serializedData,
                                                        l_attributeSize);

        // Make sure serialized data is the size expected
        ++l_numTests;
        if (l_returnedSize != l_attributeSize)
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 19 - "
                    "Attribute Serialize failed, with a size 3 Data Value; "
                    "expected size %d but got back size %d",
                    l_attributeSize,
                    l_returnedSize);
            ++l_numFails;
        }

        // Make sure the serialized Attribute Header
        // matches original Attribute Header
        // Get a handle to Attribute Header
        AttributeTank::Attribute* l_attribute2 =
                 reinterpret_cast<AttributeTank::Attribute*>(l_serializedData);

        // Compare the two different Attribute Header for a match
        ++l_numTests;
        if (!compareAttributeHeader(l_attribute2, &l_attribute))
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 20 - "
                    "Attribute Serialize failed, with a size 3 Data Value; "
                    "incorrect Attribute Header data returned");
            ++l_numFails;
        }

        // Make sure that the size of the Attribute Values is 3
        ++l_numTests;
        if (l_bufferSize != l_attribute2->getHeader().iv_valSize)
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 21 - "
                    "Attribute Serialize failed, with a size 3 Data Value; "
                    "Expected %d size Data Value but %d was returned",
                    l_bufferSize,
                    l_attribute2->getHeader().iv_valSize);

            ++l_numFails;
        }

        // Point to the Attribute Values
        l_serializedData += sizeof(AttributeTank::AttributeHeader);


        // Compare the two different Attribute Value
        ++l_numTests;
        if (0 != memcmp(l_serializedData, &l_dataBuffer2, l_bufferSize))
        {
            TS_FAIL("testSerializeAndDeserializeMethod: Test 22 - "
                    "Attribute Serialize failed, with a size 3 Data Value; "
                    "incorrect Attribute Data Values returned");
            ++l_numFails;
        }

        // Reset the Serialized Data for next test
        l_serializedData -= sizeof(AttributeTank::AttributeHeader);

        // Test deserialize
        {
            AttributeTank::Attribute l_attribute3;
            uint32_t l_returnedSize2 =
                    l_attribute3.deserialize(l_serializedData, l_returnedSize);

            // Make sure data size copied is correct
            ++l_numTests;
            if (l_returnedSize2 != l_returnedSize)
            {
                TS_FAIL("testSerializeAndDeserializeMethod: Test 23 - "
                     "Attribute Deserialize failed, with a size 3 Data Value; "
                     "expected size %d but got back size %d",
                     l_returnedSize,
                     l_returnedSize2);
                ++l_numFails;
            }

            // Make sure the Attribute Header matches original data
            ++l_numTests;
            if (!compareAttributeHeader(&l_attribute3, &l_attribute))
            {
                TS_FAIL("testSerializeAndDeserializeMethod: Test 24 - "
                     "Attribute Deserialize failed, with a size 3 Data Value; "
                     "incorrect Attribute Header data returned");
                ++l_numFails;
            }

            // Test when buffer is too small
            AttributeTank::Attribute l_attribute4;
            l_returnedSize2 = l_attribute4.deserialize(l_serializedData,
                                                       l_returnedSize - 1);

            // Make sure returned size is 0
            ++l_numTests;
            if (0 != l_returnedSize2)
            {
                TS_FAIL("testSerializeAndDeserializeMethod: Test 25 - "
                     "Attribute Deserialize failed, with too small of buffer "
                     "for 3 data values; expected size 0 but got back size %d",
                     l_returnedSize2);
                ++l_numFails;
            }
        }

        // Cleanup memory used for this test
        delete []l_serializedData;
        l_serializedData = nullptr;
    }

    TRACFCOMP( g_trac_test, EXIT_MRK "testSerializeAndDeserializeMethod "
               "num tests = %d  / num fails = %d", l_numTests, l_numFails);
}   // end AttributeTest::testSerializeAndDeserializeMethod

// testOperatorEqual
void AttributeTest::testOperatorEqual(void)
{
    TRACFCOMP( g_trac_test, ENTER_MRK "testOperatorEqual" );

    // Test stats
    uint8_t l_numTests(0);
    uint8_t l_numFails(0);

    // Create an Attribute to test against
    AttributeTank::Attribute l_attribute1;

    // Test with an empty attribute
    AttributeTank::Attribute l_attribute2;
    // Invoke Operator Equal
    l_attribute2 = l_attribute1;

    // Make sure the Attribute Header match
    ++l_numTests;
    if (!compareAttributeHeader(&l_attribute1, &l_attribute2))
    {
        TS_FAIL("testOperatorEqual: Test 1 - "
                "Attribute Operator = failed, with default values; "
                "incorrect Attribute Header data returned");
        ++l_numFails;
    }

    // Modify the data
    l_attribute1.setId(0x1001);
    l_attribute1.setTargetType(0x2002);
    l_attribute1.setPosition(0x3003);
    l_attribute1.setUnitPosition(0x4);
    l_attribute1.setNode(0x5);
    l_attribute1.setFlags(0x6);

    // Test with modified data
    AttributeTank::Attribute l_attribute3;
    // Invoke Operator Equal
    l_attribute3 = l_attribute1;

    // Make sure the Attribute Header match
    ++l_numTests;
    if (!compareAttributeHeader(&l_attribute1, &l_attribute3))
    {
        TS_FAIL("testOperatorEqual: Test 2 - "
                "Attribute Operator = failed, with modifed values; "
                "incorrect Attribute Header data returned");
        ++l_numFails;
    }

    // Add attribute values
    uint32_t l_bufferSize(3);
    uint8_t l_buffer[l_bufferSize];
    l_buffer[0] = 0x66;
    l_buffer[0] = 0x77;
    l_buffer[0] = 0x88;
    l_attribute1.setValue(l_buffer, l_bufferSize);

    // Test with modified data
    AttributeTank::Attribute l_attribute4;
    // Invoke Operator Equal
    l_attribute4 = l_attribute1;

    // Make sure the Attribute Header match
    ++l_numTests;
    if (!compareAttributeHeader(&l_attribute1, &l_attribute4))
    {
        TS_FAIL("testOperatorEqual: Test 3 - "
                     "Attribute Operator = failed, with data values; "
                     "incorrect Attribute Header data returned");
        ++l_numFails;
    }

    // Make sure the Attribute Values match
    ++l_numTests;
    if (!compareAttributeValues(&l_attribute1, &l_attribute4))
    {
        TS_FAIL("testOperatorEqual: Test 4 - "
                "Attribute Operator = failed, with data values; "
                "incorrect Attribute Values data returned");
        ++l_numFails;
    }

    // Update the Attribute Values and test again
    l_buffer[0] = 0x22;
    l_buffer[0] = 0x33;
    l_buffer[0] = 0x55;
    l_attribute1.setValue(l_buffer, l_bufferSize);

    // Make sure the Attribute Header match original data
    ++l_numTests;
    if (!compareAttributeHeader(&l_attribute1, &l_attribute4))
    {
        TS_FAIL("testOperatorEqual: Test 5 - "
                "Attribute Operator = failed, with data values updated; "
                "incorrect Attribute Header data returned");
        ++l_numFails;
    }

    // Make sure the Attribute Values DO NOT match
    ++l_numTests;
    if (compareAttributeValues(&l_attribute1, &l_attribute4))
    {
        TS_FAIL("testOperatorEqual: Test 6 - "
                "Attribute Operator = failed, with data values updated; "
                "incorrect Attribute Values data returned");
        ++l_numFails;
    }

    TRACFCOMP( g_trac_test, EXIT_MRK "testOperatorEqual "
               "num tests = %d  / num fails = %d", l_numTests, l_numFails);
} // end testOperatorEqual

// testCopyConstructor
void AttributeTest::testCopyConstructor(void)
{
    TRACFCOMP( g_trac_test, ENTER_MRK "testCopyConstructor" );

    // Test stats
    uint8_t l_numTests(0);
    uint8_t l_numFails(0);

    // Create an Attribute to test against
    AttributeTank::Attribute l_attribute1;

    l_attribute1.setId(0x1001);
    l_attribute1.setFlags(0x5);

    // Test with an empty attribute, invoke copy constructor
    AttributeTank::Attribute l_attribute2 = l_attribute1;

    // Make sure the Attribute Header match
    ++l_numTests;
    if (!compareAttributeHeader(&l_attribute1, &l_attribute2))
    {
        TS_FAIL("testCopyConstructor: Test 1 - "
                "Attribute Copy Ctor failed, with default values; "
                "incorrect Attribute Header data returned");
        ++l_numFails;
    }

    // Modify the data
    l_attribute1.setId(0x1001);
    l_attribute1.setTargetType(0x2002);
    l_attribute1.setPosition(0x3003);
    l_attribute1.setUnitPosition(0x4);
    l_attribute1.setNode(0x5);
    l_attribute1.setFlags(0x6);

    // Test with modified data, invoke copy constructor
    AttributeTank::Attribute l_attribute3 = l_attribute1;

    // Make sure the Attribute Header match
    ++l_numTests;
    if (!compareAttributeHeader(&l_attribute1, &l_attribute3))
    {
        TS_FAIL("testCopyConstructor: Test 2 - "
                "Attribute Copy Ctor failed, with modifed values; "
                "incorrect Attribute Header data returned");
        ++l_numFails;
    }

    // Add attribute values
    uint32_t l_bufferSize(3);
    uint8_t l_buffer[l_bufferSize];
    l_buffer[0] = 0x66;
    l_buffer[0] = 0x77;
    l_buffer[0] = 0x88;
    l_attribute1.setValue(l_buffer, l_bufferSize);

    // Test with modified data, invoke copy constructor
    AttributeTank::Attribute l_attribute4 = l_attribute1;

    // Make sure the Attribute Header match
    ++l_numTests;
    if (!compareAttributeHeader(&l_attribute1, &l_attribute4))
    {
        TS_FAIL("testCopyConstructor: Test 3 - "
                "Attribute Copy Ctor failed, with data values; "
                "incorrect Attribute Header data returned");
        ++l_numFails;
    }

    // Make sure the Attribute Values match
    ++l_numTests;
    if (!compareAttributeValues(&l_attribute1, &l_attribute4))
    {
        TS_FAIL("testCopyConstructor: Test 4 - "
                "Attribute Copy Ctor failed, with data values; "
                "incorrect Attribute Values data returned");
        ++l_numFails;
    }

    // Update the Attribute Values and test again
    l_buffer[0] = 0x22;
    l_buffer[0] = 0x33;
    l_buffer[0] = 0x55;
    l_attribute1.setValue(l_buffer, l_bufferSize);

    // Make sure the Attribute Header match original data
    ++l_numTests;
    if (!compareAttributeHeader(&l_attribute1, &l_attribute4))
    {
        TS_FAIL("testCopyConstructor: Test 5 - "
                "Attribute Copy Ctor failed, with data values updated; "
                "incorrect Attribute Header data returned");
        ++l_numFails;
    }

    // Make sure the Attribute Values DO NOT match
    ++l_numTests;
    if (compareAttributeValues(&l_attribute1, &l_attribute4))
    {
        TS_FAIL("testCopyConstructor: Test 6 - "
                "Attribute Copy Ctor failed, with data values updated; "
                "incorrect Attribute Values data returned");
        ++l_numFails;
    }

    TRACFCOMP( g_trac_test, EXIT_MRK "testCopyConstructor "
               "num tests = %d  / num fails = %d", l_numTests, l_numFails);
} // end testCopyConstructor

// isEnumMaxVal
template <typename T>
bool AttributeTest::isEnumMaxVal(T invalidEnumVal)
{
    bool isMaxVal = false;
    switch (sizeof(invalidEnumVal))
    {
        case 1:
            isMaxVal = invalidEnumVal == 0xFF;
            break;
        case 2:
            isMaxVal = invalidEnumVal == 0xFFFF;
            break;
        case 4:
            isMaxVal = invalidEnumVal == 0xFFFFFFFF;
            break;
        case 8:
            isMaxVal = invalidEnumVal == 0xFFFFFFFFFFFFFFFF;
            break;
        default:
            isMaxVal = false;

    }

    return isMaxVal;
} // end isEnumMaxVal

// testGeneratedInvalidsForAttr
void AttributeTest::testGeneratedInvalidsForAttr(void)
{
    TRACFCOMP( g_trac_test, ENTER_MRK " testGeneratedInvalidsForAttr" );

    // Test stats
    uint8_t l_numTests(0);
    uint8_t l_numFails(0);

    Target* sys = UTIL::assertGetToplevelTarget();
    Target* nodeTgt = UTIL::getCurrentNodeTarget();

    //tests for enums
    TS_TRACE(INFO_MRK "Testing Attribute Enums");

    auto test = KEY_CLEAR_REQUEST_INVALID;
    TS_TRACE(INFO_MRK "Test1: KEY_CLEAR_REQUEST_INVALID = 0x%X", test);

    auto defaultGet = sys->getAttr<ATTR_KEY_CLEAR_REQUEST>();
    TS_TRACE(INFO_MRK "get default value for KEY_CLEAR_REQUEST = 0x%X", defaultGet);

    //test setting the attribute with the INVALID value
    test = KEY_CLEAR_REQUEST_INVALID;
    sys->setAttr<ATTR_KEY_CLEAR_REQUEST>(test);
    test = sys->getAttr<ATTR_KEY_CLEAR_REQUEST>();
    TS_TRACE(INFO_MRK "set KEY_CLEAR_REQUEST to its INVALID value = 0x%X", test);

    // test that the enum was properly set to its INVALID value
    ++l_numTests;
    if (test != KEY_CLEAR_REQUEST_INVALID)
    {
        TS_FAIL("test1 testGeneratedInvalidsForAttr: "
                "set ATTR_KEY_CLEAR_REQUEST to KEY_CLEAR_REQUEST_INVALID failed "
                "incorrect Attribute Values data returned. "
                "ATTR_KEY_CLEAR_REQUEST = 0x%X", test);
        ++l_numFails;
    }

    // test that the invalid value is the max value for its size
    TS_TRACE(INFO_MRK "size of KEY_CLEAR_REQUEST_INVALID is: %d",
                       sizeof(KEY_CLEAR_REQUEST_INVALID));

    ++l_numTests;
    if (!isEnumMaxVal(KEY_CLEAR_REQUEST_INVALID))
    {
        TS_FAIL("test1 testGeneratedInvalidsForAttr: "
                "KEY_CLEAR_REQUEST_INVALID not set to max value "
                "KEY_CLEAR_REQUEST_INVALID = 0x%X, "
                "expected %d byte(s) of 0xFF", KEY_CLEAR_REQUEST_INVALID,
                 sizeof(KEY_CLEAR_REQUEST_INVALID));
        ++l_numFails;
    }

    // set it back to the default
    sys->setAttr<ATTR_KEY_CLEAR_REQUEST>(defaultGet);

    //// END OF FIRST TEST CASE ////

    auto test2 = PAYLOAD_KIND_INVALID;
    TS_TRACE(INFO_MRK "Test2: PAYLOAD_KIND_INVALID = 0x%X", test2);

    auto defaultGet2 = sys->getAttr<ATTR_PAYLOAD_KIND>();
    TS_TRACE(INFO_MRK "get default value for PAYLOAD_KIND = 0x%X", defaultGet2);

    test2 = PAYLOAD_KIND_INVALID;
    sys->setAttr<ATTR_PAYLOAD_KIND>(test2);
    test2 = sys->getAttr<ATTR_PAYLOAD_KIND>();
    TS_TRACE(INFO_MRK "set PAYLOAD_KIND to its INVALID value = 0x%X", test2);

    ++l_numTests;
    if (test2 != PAYLOAD_KIND_INVALID)
    {
        TS_FAIL("test2 testGeneratedInvalidsForAttr: "
                "set ATTR_PAYLOAD_KIND to PAYLOAD_KIND_INVALID failed "
                "incorrect Attribute Values data returned. "
                "ATTR_PAYLOAD_KIND = 0x%X", test2);
        ++l_numFails;
    }

    TS_TRACE(INFO_MRK "size of PAYLOAD_KIND_INVALID is %d",
                       sizeof(PAYLOAD_KIND_INVALID));

    ++l_numTests;
    if (!isEnumMaxVal(PAYLOAD_KIND_INVALID))
    {
        TS_FAIL("test1 testGeneratedInvalidsForAttr: "
                "PAYLOAD_KIND_INVALID not set to max value "
                "PAYLOAD_KIND_INVALID = 0x%X, "
                "expected %d byte(s) of 0xFF", PAYLOAD_KIND_INVALID,
                 sizeof(PAYLOAD_KIND_INVALID));
        ++l_numFails;
    }

    sys->setAttr<ATTR_PAYLOAD_KIND>(defaultGet2);

    //// END SECOND CASE ////

    //test for traits
    auto test3 = AttributeTraits<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>()
                 .PHYS_PRES_REQUEST_OPEN_WINDOW_INVALID;
    auto pprowInvalid = test3;
    TS_TRACE(INFO_MRK "Testing Attribute Traits");
    TS_TRACE(INFO_MRK "Test3: PHYS_PRES_REQUEST_OPEN_WINDOW_INVALID = 0x%X", test3);

    auto defaultGet3 = nodeTgt->getAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>();

    TS_TRACE(INFO_MRK "get default value for PHYS_PRES_REQUEST_OPEN_WINDOW = 0x%X", defaultGet3);

    nodeTgt->setAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>(test3);
    test3 = nodeTgt->getAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>();
    TS_TRACE(INFO_MRK "set PHYS_PRES_REQUEST_OPEN_WINDOW to its INVALID value = 0x%X", test3 );

    ++l_numTests;
    if (test3 != pprowInvalid)
    {
        TS_FAIL("test3 testGeneratedInvalidsForAttr: "
                "set ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW to "
                "PHYS_PRES_REQUEST_OPEN_WINDOW_INVALID failed "
                "incorrect Attribute Values data returned. "
                "ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW = 0x%X", test3);
        ++l_numFails;
    }

    TS_TRACE(INFO_MRK "size of PHYS_PRES_REQUEST_OPEN_WINDOW_INVALID is: %d",
                       sizeof(pprowInvalid));

    ++l_numTests;
    if (!isEnumMaxVal(pprowInvalid))
    {
        TS_FAIL("test1 testGeneratedInvalidsForAttr: "
                "PHYS_PRES_REQUEST_OPEN_WINDOW_INVALID not set to max value "
                "PHYS_PRES_REQUEST_OPEN_WINDOW_INVALID = 0x%X, "
                "expected %d byte(s) of 0xFF", pprowInvalid,
                 sizeof(pprowInvalid));
        ++l_numFails;
    }

    nodeTgt->setAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>(defaultGet3);

    //// END THIRD TEST CASE ////
    //test for strings

    TS_TRACE(INFO_MRK "Testing Attribute Strings");

    auto test4 = PAYLOAD_KIND_INVALID;
    auto defaultGet4 = sys->getAttr<ATTR_PAYLOAD_KIND>();
    sys->setAttr<ATTR_PAYLOAD_KIND>(test4);

    // must have 'hasStringConversion' specified in attributetraits.H
    // and have an attrToString function in attributestrings.C
    auto attrString = sys->getAttrAsString<ATTR_PAYLOAD_KIND>();

    TS_TRACE(INFO_MRK "ATTR_PAYLOAD_KIND_INVALID = %s", attrString);

    ++l_numTests;
    if(strcmp(attrString, "INVALID") != 0)
    {
        TS_FAIL("test4 testGeneratedInvalidsForAttr: "
                "PAYLOAD_KIND_INVALID to string failed "
                "incorrect Attribute String returned. "
                "ATTR_PAYLOAD_KIND = %s", attrString);
        ++l_numFails;
    }


    sys->setAttr<ATTR_PAYLOAD_KIND>(defaultGet4);
    //// END FOURTH CASE ////

    TRACFCOMP( g_trac_test, EXIT_MRK "testGeneratedInvalidsForAttr "
                "num tests = %d  / num fails = %d", l_numTests, l_numFails);

} //end testGeneratedInvalidsForAttr

// compareAttributeHeader
bool AttributeTest::compareAttributeHeader(
                     const AttributeTank::Attribute* const l_attribute1,
                     const AttributeTank::Attribute* const l_attribute2)
{
    bool retVal(true);

    // Make sure the Attribute Header matches original data
    if (0 != memcmp(&(l_attribute1->getHeader()),
                    &(l_attribute2->getHeader()),
                    sizeof(AttributeTank::AttributeHeader)))
    {
        retVal = false;
    }

    return retVal;

} // end compareAttributeHeader

// compareAttributeValues
bool AttributeTest::compareAttributeValues(
                     const AttributeTank::Attribute* const l_attribute1,
                     const AttributeTank::Attribute* const l_attribute2)
{
    bool retVal(true);

    // Compare the Attribute Values for a match
    if (0 != memcmp(l_attribute1->getValue(),
                    l_attribute2->getValue(),
                    l_attribute2->getHeader().iv_valSize))
    {
        retVal = false;
    }

    return retVal;

} // end compareAttributeValues

#endif // end __TEST_ATTRIBUTE_H
