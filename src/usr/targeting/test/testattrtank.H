/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/testattrtank.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
#ifndef TESTATTRTANK_H
#define TESTATTRTANK_H

/**
 *  @file testattrtank.H
 *
 *  @brief Test case for AttributeTank
*/

#include <cxxtest/TestSuite.H>

#include <targeting/common/attributeTank.H>
#include <targeting/attrPlatOverride.H>
#include <pnor/pnorif.H>

using namespace TARGETING;

class AttrTankTest: public CxxTest::TestSuite
{
public:

    //**************************************************************************
    // tankTest1. Test AttributeTank functions with empty tank
    //**************************************************************************
    void tankTest1(void)
    {
        do
        {
            // Create a local AttributeTank
            AttributeTank l_tank;

            // Check that tank is empty
            if (l_tank.attributesExist())
            {
                TS_FAIL("tankTest1: Error. AttributeTank is not empty (1)");
                break;
            }

            if (l_tank.attributeExists(5))
            {
                TS_FAIL("tankTest1: Error. AttributeTank is not empty (2)");
                break;
            }

            // Clear all attributes from empty tank
            l_tank.clearAllAttributes();

            // Clear a non-const attribute from empty tank
            l_tank.clearNonConstAttribute(ATTR_SCRATCH_UINT64_1,
                                          TYPE_SYS,
                                          AttributeTank::ATTR_POS_NA,
                                          AttributeTank::ATTR_UNIT_POS_NA,
                                          AttributeTank::ATTR_NODE_NA);

            // Try to get an attribute from empty tank
            uint64_t l_val = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                    TYPE_SYS,
                                    AttributeTank::ATTR_POS_NA,
                                    AttributeTank::ATTR_UNIT_POS_NA,
                                    AttributeTank::ATTR_NODE_NA,
                                    &l_val))
            {
                TS_FAIL("tankTest1: Error. Got attr from empty tank (3)");
                break;
            }

            // Try to serialize all attributes from empty tank
            std::vector<AttributeTank::AttributeSerializedChunk> l_attributes;
            l_tank.serializeAttributes(AttributeTank::ALLOC_TYPE_MALLOC,
                                       4096, l_attributes);

            if (l_attributes.size())
            {
                TS_FAIL("tankTest1: Error. Got attrs from empty tank (4)");
                break;
            }

        } while (0);

        TS_TRACE("tankTest1 complete" );
    }

    //**************************************************************************
    // tankTest2. Test AttributeTank functions with single attribute in tank
    //**************************************************************************
    void test2(void)
    {
        do
        {
            // Create a local AttributeTank
            AttributeTank l_tank;

            // Add ATTR_SCRATCH_UINT64_1 to the tank
            uint64_t l_val = 4;
            l_tank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                TYPE_SYS,
                                AttributeTank::ATTR_POS_NA,
                                AttributeTank::ATTR_UNIT_POS_NA,
                                AttributeTank::ATTR_NODE_NA,
                                0, sizeof(l_val), &l_val);

            // Check that attributes exist in the tank
            if (!l_tank.attributesExist())
            {
                TS_FAIL("tankTest2: Error. AttributeTank is empty (1)");
                break;
            }

            if (!l_tank.attributeExists(ATTR_SCRATCH_UINT64_1))
            {
                TS_FAIL("tankTest2: Error. Attribute not in tank (2)");
                break;
            }

            if (l_tank.attributeExists(1))
            {
                TS_FAIL("tankTest2: Error. Wrong attribute in tank (3)");
                break;
            }

            // Try to get the wrong attribute from the tank (wrong att ID)
            l_val = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT64_2,
                                    TYPE_SYS,
                                    AttributeTank::ATTR_POS_NA,
                                    AttributeTank::ATTR_UNIT_POS_NA,
                                    AttributeTank::ATTR_NODE_NA,
                                    &l_val))
            {
                TS_FAIL("tankTest2: Error. Got wrong attr from tank (4)");
                break;
            }

            // Try to get the wrong attribute from the tank (wrong target type)
            l_val = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                    TYPE_PROC,
                                    AttributeTank::ATTR_POS_NA,
                                    AttributeTank::ATTR_UNIT_POS_NA,
                                    AttributeTank::ATTR_NODE_NA,
                                    &l_val))
            {
                TS_FAIL("tankTest2: Error. Got wrong attr from tank (5)");
                break;
            }

            // Get the attribute from the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_SYS,
                                      AttributeTank::ATTR_POS_NA,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest2: Error. Did not get attr from tank (6)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest2: Error. Got bad value (0x%llx) from tank (7)",
                        l_val);
                break;
            }

            // Get the attribute from the tank using a real position
            // This should succeed because attribute in tank matches all positions
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_SYS,
                                      1,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest2: Error. Did not get attr from tank (8)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest2: Error. Got bad value (0x%llx) from tank (9)",
                        l_val);
                break;
            }

            // Get the attribute from the tank using a real unit-position
            // This should succeed because attribute in tank matches all unit
            // positions
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_SYS,
                                      AttributeTank::ATTR_POS_NA,
                                      2,
                                      AttributeTank::ATTR_NODE_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest2: Error. Did not get attr from tank (10)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest2: Error. Got bad value (0x%llx) from tank (11)",
                        l_val);
                break;
            }

            // Get the attribute from the tank using a real node-number
            // This should succeed because attribute in tank matches all node
            // numbers
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_SYS,
                                      AttributeTank::ATTR_POS_NA,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      1,
                                      &l_val)))
            {
                TS_FAIL("tankTest2: Error. Did not get attr from tank (12)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest2: Error. Got bad value (0x%llx) from tank (13)",
                        l_val);
                break;
            }

            // Serialize all attributes from the tank
            std::vector<AttributeTank::AttributeSerializedChunk> l_attributes;
            l_tank.serializeAttributes(AttributeTank::ALLOC_TYPE_NEW,
                                       4096, l_attributes);

            if (l_attributes.size() != 1)
            {
                TS_FAIL("tankTest2: Error. Got wrong number of chunks (%d) from tank (14)",
                        l_attributes.size());
                break;
            }

            if (l_attributes[0].iv_size !=
                (sizeof(AttributeTank::AttributeHeader) + sizeof(l_val)))
            {
                TS_FAIL("tankTest2: Error. Got wrong size (%d) of attrs from tank (15)",
                        l_attributes[0].iv_size);
                break;
            }

            uint64_t * l_pVal = reinterpret_cast<uint64_t *>
                (l_attributes[0].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal != 4)
            {
                TS_FAIL("tankTest2: Error. Got bad value (0x%016llx) from tank (16)",
                        *l_pVal);
                break;
            }

            // Clear the tank and check it was cleared
            l_tank.clearAllAttributes();

            l_val = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                    TYPE_SYS,
                                    AttributeTank::ATTR_POS_NA,
                                    AttributeTank::ATTR_UNIT_POS_NA,
                                    AttributeTank::ATTR_NODE_NA,
                                    &l_val))
            {
                TS_FAIL("tankTest2: Error. Got value from empty tank (17)");
                break;
            }

            // Deserialize the attribute back into the tank
            l_tank.deserializeAttributes(l_attributes[0]);

            // Check the attribute made it back into the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_SYS,
                                      AttributeTank::ATTR_POS_NA,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest2: Error. Did not get attr from tank (18)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest2: Error. Got bad value (0x%llx) from tank (19)",
                        l_val);
                break;
            }

            // Free the memory in the attribute chunk
            delete [] l_attributes[0].iv_pAttributes;
            l_attributes[0].iv_pAttributes = NULL;

        } while (0);

        TS_TRACE("tankTest2 complete" );
    }

    //**************************************************************************
    // tankTest3. Test AttributeTank functions with multiple attributes in tank
    //**************************************************************************
    void test3(void)
    {
        do
        {
            // Create a local AttributeTank
            AttributeTank l_tank;

            // Add ATTR_SCRATCH_UINT64_1 as a proc chip attribute to the tank
            uint64_t l_val = 4;
            l_tank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                TYPE_PROC,
                                1,
                                AttributeTank::ATTR_UNIT_POS_NA,
                                AttributeTank::ATTR_NODE_NA,
                                0, sizeof(l_val), &l_val);

            // Add ATTR_SCRATCH_UINT32_1 as an MBA attribute to the tank
            uint32_t l_val2 = 5;
            l_tank.setAttribute(ATTR_SCRATCH_UINT32_1,
                                TYPE_MBA,
                                1,
                                2,
                                3,
                                0, sizeof(l_val2), &l_val2);

            // Get the first attribute from the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_PROC,
                                      1,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (1)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest3: Error. Got bad value (0x%016llx) from tank (2)",
                        l_val);
                break;
            }

            // Try to get the first attribute from the tank with the wrong pos
            l_val = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                    TYPE_PROC,
                                    2,
                                    AttributeTank::ATTR_UNIT_POS_NA,
                                    AttributeTank::ATTR_NODE_NA,
                                    &l_val))
            {
                TS_FAIL("tankTest3: Error. Got wrong attr from tank (3)");
                break;
            }

            // Get the second attribute from the tank
            l_val2 = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                      TYPE_MBA,
                                      1,
                                      2,
                                      3,
                                      &l_val2)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (4)");
                break;
            }

            if (l_val2 != 5)
            {
                TS_FAIL("tankTest3: Error. Got bad value (0x%llx) from tank (5)",
                        l_val);
                break;
            }

            // Try to get the second attribute from the tank with the wrong
            // unit position
            l_val2 = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                    TYPE_MBA,
                                    1,
                                    3,
                                    3,
                                    &l_val2))
            {
                TS_FAIL("tankTest3: Error. Got wrong attr from tank (6)");
                break;
            }

            // Try to get the second attribute from the tank with the wrong
            // node number
            l_val2 = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                    TYPE_MBA,
                                    1,
                                    2,
                                    4,
                                    &l_val2))
            {
                TS_FAIL("tankTest3: Error. Got wrong attr from tank (7)");
                break;
            }

            // Serialize all attributes from the tank into a single chunk
            std::vector<AttributeTank::AttributeSerializedChunk> l_attributes;
            l_tank.serializeAttributes(AttributeTank::ALLOC_TYPE_MALLOC,
                                       4096, l_attributes);

            if (l_attributes.size() != 1)
            {
                TS_FAIL("tankTest3: Error. Got wrong number of chunks (%d) from tank (8)",
                        l_attributes.size());
                break;
            }

            if (l_attributes[0].iv_size !=
                (sizeof(AttributeTank::AttributeHeader) + sizeof(l_val) +
                 sizeof(AttributeTank::AttributeHeader) + sizeof(l_val2)) )
            {
                TS_FAIL("tankTest3: Error. Got wrong size (%d) of attrs from tank (9)",
                        l_attributes[0].iv_size);
                break;
            }

            uint64_t * l_pVal = reinterpret_cast<uint64_t *>
                (l_attributes[0].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal != 4)
            {
                TS_FAIL("tankTest3: Error. Got bad value (0x%016llx) from tank (10)",
                        *l_pVal);
                break;
            }

            uint32_t * l_pVal2 = reinterpret_cast<uint32_t *>
                (l_attributes[0].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader) +
                 sizeof(l_val) + sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal2 != 5)
            {
                TS_FAIL("tankTest3: Error. Got bad value (0x%08x) from tank (11)",
                        *l_pVal2);
                break;
            }

            // Clear the tank
            l_tank.clearAllAttributes();

            // Deserialize the attribute back into the tank
            l_tank.deserializeAttributes(l_attributes[0]);

            // Check the first attribute made it back into the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_PROC,
                                      1,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (12)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest3: Error. Got bad value (0x%016llx) from tank (13)",
                        l_val);
                break;
            }

            // Check the second attribute made it back into the tank
            l_val2 = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                      TYPE_MBA,
                                      1,
                                      2,
                                      3,
                                      &l_val2)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (14)");
                break;
            }

            if (l_val2 != 5)
            {
                TS_FAIL("tankTest3: Error. Got bad value (0x%llx) from tank (15)",
                        l_val);
                break;
            }

            // Free the memory in the attribute chunk
            free (l_attributes[0].iv_pAttributes);
            l_attributes[0].iv_pAttributes = NULL;
            l_attributes.clear();

            // Serialize all attributes from the tank into a two chunks
            // Use a chunk size small enough to only fit a single attribute
            l_tank.serializeAttributes(AttributeTank::ALLOC_TYPE_MALLOC,
                sizeof(AttributeTank::AttributeHeader) + sizeof(l_val) + 8,
                l_attributes);

            if (l_attributes.size() != 2)
            {
                TS_FAIL("tankTest3: Error. Got wrong number of chunks (%d) from tank (16)",
                        l_attributes.size());
                break;
            }

            if (l_attributes[0].iv_size !=
                (sizeof(AttributeTank::AttributeHeader) + sizeof(l_val)))
            {
                TS_FAIL("tankTest3: Error. Got wrong size (%d) of attrs from tank (17)",
                        l_attributes[0].iv_size);
                break;
            }

            l_pVal = reinterpret_cast<uint64_t *>
                (l_attributes[0].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal != 4)
            {
                TS_FAIL("tankTest3: Error. Got bad value (0x%016llx) from tank (18)",
                        *l_pVal);
                break;
            }

            if (l_attributes[1].iv_size !=
                (sizeof(AttributeTank::AttributeHeader) + sizeof(l_val2)))
            {
                TS_FAIL("tankTest3: Error. Got wrong size (%d) of attrs from tank (19)",
                        l_attributes[1].iv_size);
                break;
            }

            l_pVal2 = reinterpret_cast<uint32_t *>
                (l_attributes[1].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal2 != 5)
            {
                TS_FAIL("tankTest3: Error. Got bad value (0x%016llx) from tank (20)",
                        *l_pVal);
                break;
            }

            // Clear the tank
            l_tank.clearAllAttributes();

            // Deserialize the attributes back into the tank
            l_tank.deserializeAttributes(l_attributes[0]);
            l_tank.deserializeAttributes(l_attributes[1]);

            // Check the first attribute made it back into the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_PROC,
                                      1,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (21)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest3: Error. Got bad value (0x%016llx) from tank (22)",
                        l_val);
                break;
            }

            // Check the second attribute made it back into the tank
            l_val2 = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                      TYPE_MBA,
                                      1,
                                      2,
                                      3,
                                      &l_val2)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (23)");
                break;
            }

            if (l_val2 != 5)
            {
                TS_FAIL("tankTest3: Error. Got bad value (0x%llx) from tank (24)",
                        l_val);
                break;
            }

            // Free the memory in the attribute chunks
            free (l_attributes[0].iv_pAttributes);
            l_attributes[0].iv_pAttributes = NULL;
            free (l_attributes[1].iv_pAttributes);
            l_attributes[1].iv_pAttributes = NULL;

        } while (0);

        TS_TRACE("tankTest3 complete" );
    }

    //**************************************************************************
    // tankTest4. Test AttributeTank functions with a constant attribute
    //**************************************************************************
    void test4(void)
    {
        do
        {
            // Create a local AttributeTank (this is not the singleton)
            AttributeTank l_tank;

            // Set const attribute
            uint8_t l_val = 4;
            l_tank.setAttribute(ATTR_SCRATCH_UINT8_1,
                                TYPE_SYS,
                                AttributeTank::ATTR_POS_NA,
                                AttributeTank::ATTR_UNIT_POS_NA,
                                AttributeTank::ATTR_NODE_NA,
                                AttributeTank::ATTR_FLAG_CONST,
                                sizeof(l_val), &l_val);

            // Try to clear the attribute, it should not be cleared
            l_tank.clearNonConstAttribute(ATTR_SCRATCH_UINT8_1,
                                          TYPE_SYS,
                                          AttributeTank::ATTR_POS_NA,
                                          AttributeTank::ATTR_UNIT_POS_NA,
                                          AttributeTank::ATTR_NODE_NA);

            // Check that tank is not-empty
            if (!l_tank.attributesExist())
            {
                TS_FAIL("tankTest4: Error. AttributeTank is empty (1)");
                break;
            }

            // Clear all attribute
            l_tank.clearAllAttributes();

            // Check that tank is empty
            if (l_tank.attributesExist())
            {
                TS_FAIL("tankTest4: Error. AttributeTank is not empty (2)");
                break;
            }

        } while (0);

        TS_TRACE("tankTest4 complete" );
    }

    //**************************************************************************
    // tankTest5. Test adding the same attribute twice to a tank
    //**************************************************************************
    void test5(void)
    {
        do
        {
            // Create a local AttributeTank (this is not the singleton)
            AttributeTank l_tank;

            // Add ATTR_SCRATCH_UINT64_1 to the tank twice (the second one
            // should replace the first
            uint64_t l_val = 4;
            l_tank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                TYPE_SYS,
                                AttributeTank::ATTR_POS_NA,
                                AttributeTank::ATTR_UNIT_POS_NA,
                                1,
                                0, sizeof(l_val), &l_val);

            l_val = 5;
            l_tank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                TYPE_SYS,
                                AttributeTank::ATTR_POS_NA,
                                AttributeTank::ATTR_UNIT_POS_NA,
                                1,
                                0, sizeof(l_val), &l_val);

            // Get the attribute from the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_SYS,
                                      AttributeTank::ATTR_POS_NA,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      1,
                                      &l_val)))
            {
                TS_FAIL("tankTest5: Error. Did not get attr from tank (1)");
                break;
            }

            if (l_val != 5)
            {
                TS_FAIL("tankTest5: Error. Got bad value (0x%llx) from tank (2)",
                        l_val);
                break;
            }

            // Serialize all attributes from the tank
            std::vector<AttributeTank::AttributeSerializedChunk> l_attributes;
            l_tank.serializeAttributes(AttributeTank::ALLOC_TYPE_NEW,
                                       4096, l_attributes);

            if (l_attributes.size() != 1)
            {
                TS_FAIL("tankTest5: Error. Got wrong number of chunks (%d) from tank (3)",
                        l_attributes.size());
                break;
            }

            if (l_attributes[0].iv_size !=
                (sizeof(AttributeTank::AttributeHeader) + sizeof(l_val)))
            {
                TS_FAIL("tankTest5: Error. Got wrong size (%d) of attrs from tank (4)",
                        l_attributes[0].iv_size);
                break;
            }

            uint64_t * l_pVal = reinterpret_cast<uint64_t *>
                (l_attributes[0].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal != 5)
            {
                TS_FAIL("tankTest5: Error. Got bad value (0x%016llx) from tank (5)",
                        *l_pVal);
                break;
            }
            delete [] l_attributes[0].iv_pAttributes;
            l_attributes[0].iv_pAttributes = NULL;

        } while (0);

        TS_TRACE("tankTest5 complete" );
    }

    //**************************************************************************
    // tankTest6. Test AttributeTank clearAllAttributes with node filter
    //**************************************************************************
    void test6(void)
    {
        do
        {
            // Create a local AttributeTank
            AttributeTank l_tank;

            // Add an attribute for NODE_NA to the tank
            uint64_t l_val = 4;
            l_tank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                TYPE_PROC,
                                1,
                                AttributeTank::ATTR_UNIT_POS_NA,
                                AttributeTank::ATTR_NODE_NA,
                                0, sizeof(l_val), &l_val);

            // Add an attribute for node 3 to the tank
            uint32_t l_val2 = 5;
            l_tank.setAttribute(ATTR_SCRATCH_UINT32_1,
                                TYPE_MBA,
                                1,
                                2,
                                3,
                                0, sizeof(l_val2), &l_val2);

            // Clear NOT_ALL_NODES attributes
            l_tank.clearAllAttributes(AttributeTank::NODE_FILTER_NOT_ALL_NODES);

            // Get the NODE_NA attribute from the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_PROC,
                                      1,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest6: Error. Did not get attr from tank (1)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest6: Error. Got bad value (0x%llx) from tank (2)",
                        l_val);
                break;
            }

            // Try to get the node 3 attribute from the tank (should be cleared)
            l_val2 = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                    TYPE_MBA,
                                    1,
                                    2,
                                    3,
                                    &l_val2))
            {
                TS_FAIL("tankTest6: Error. Got cleared attr from tank (3)");
                break;
            }

            // Add the node 3 attribute back to the tank
            l_val2 = 5;
            l_tank.setAttribute(ATTR_SCRATCH_UINT32_1,
                                TYPE_MBA,
                                1,
                                2,
                                3,
                                0, sizeof(l_val2), &l_val2);

            // Clear SPECIFIC_NODE_AND_ALL attributes for node 6
            l_tank.clearAllAttributes(
                AttributeTank::NODE_FILTER_SPECIFIC_NODE_AND_ALL, 6);

            // Try to get the NODE_NA attribute from the tank (should be
            // cleared)
            l_val = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                    TYPE_PROC,
                                    1,
                                    AttributeTank::ATTR_UNIT_POS_NA,
                                    AttributeTank::ATTR_NODE_NA,
                                    &l_val))
            {
                TS_FAIL("tankTest6: Error. Got cleared attr from tank (4)");
                break;
            }

            // Get the node 3 attribute from the tank
            l_val2 = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                      TYPE_MBA,
                                      1,
                                      2,
                                      3,
                                      &l_val2)))
            {
                TS_FAIL("tankTest6: Error. Did not get attr from tank (5)");
                break;
            }

            if (l_val2 != 5)
            {
                TS_FAIL("tankTest6: Error. Got bad value (0x%llx) from tank (6)",
                        l_val2);
                break;
            }

            // Add the NODE_NA attribute back to the tank
            l_val = 4;
            l_tank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                TYPE_PROC,
                                1,
                                AttributeTank::ATTR_UNIT_POS_NA,
                                AttributeTank::ATTR_NODE_NA,
                                0, sizeof(l_val), &l_val);

            // Clear SPECIFIC_NODE_AND_ALL attributes for node 3
            l_tank.clearAllAttributes(
                AttributeTank::NODE_FILTER_SPECIFIC_NODE_AND_ALL, 3);

            // Try to get the NODE_NA attribute from the tank (should be
            // cleared)
            l_val = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                    TYPE_PROC,
                                    1,
                                    AttributeTank::ATTR_UNIT_POS_NA,
                                    AttributeTank::ATTR_NODE_NA,
                                    &l_val))
            {
                TS_FAIL("tankTest6: Error. Got cleared attr from tank (7)");
                break;
            }

            // Try to get the node 3 attribute from the tank (should be cleared)
            l_val2 = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                    TYPE_MBA,
                                    1,
                                    2,
                                    3,
                                    &l_val2))
            {
                TS_FAIL("tankTest6: Error. Got cleared attr from tank (8)");
                break;
            }

            // Add the NODE_NA attribute back to the tank
            l_val = 4;
            l_tank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                TYPE_PROC,
                                1,
                                AttributeTank::ATTR_UNIT_POS_NA,
                                AttributeTank::ATTR_NODE_NA,
                                0, sizeof(l_val), &l_val);

            // Add the node 3 attribute back to the tank
            l_val2 = 5;
            l_tank.setAttribute(ATTR_SCRATCH_UINT32_1,
                                TYPE_MBA,
                                1,
                                2,
                                3,
                                0, sizeof(l_val2), &l_val2);

            // Clear SPECIFIC_NODE attributes for node 6
            l_tank.clearAllAttributes(
                AttributeTank::NODE_FILTER_SPECIFIC_NODE, 6);

            // Get the NODE_NA attribute from the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_PROC,
                                      1,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest6: Error. Did not get attr from tank (9)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest6: Error. Got bad value (0x%llx) from tank (10)",
                        l_val);
                break;
            }

            // Get the node 3 attribute from the tank
            l_val2 = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                      TYPE_MBA,
                                      1,
                                      2,
                                      3,
                                      &l_val2)))
            {
                TS_FAIL("tankTest6: Error. Did not get attr from tank (11)");
                break;
            }

            if (l_val2 != 5)
            {
                TS_FAIL("tankTest6: Error. Got bad value (0x%llx) from tank (12)",
                        l_val2);
                break;
            }

            // Clear SPECIFIC_NODE attributes for node 3
            l_tank.clearAllAttributes(
                AttributeTank::NODE_FILTER_SPECIFIC_NODE, 3);

            // Get the NODE_NA attribute from the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_PROC,
                                      1,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest6: Error. Did not get attr from tank (13)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL("tankTest6: Error. Got bad value (0x%llx) from tank (14)",
                        l_val);
                break;
            }

            // Try to get the node 3 attribute from the tank (should be cleared)
            l_val2 = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                    TYPE_MBA,
                                    1,
                                    2,
                                    3,
                                    &l_val2))
            {
                TS_FAIL("tankTest6: Error. Got cleared attr from tank (15)");
                break;
            }

        } while (0);

        TS_TRACE("tankTest6 complete" );
    }

    //**************************************************************************
    // tankTest7. Test AttributeTank clearNonConstAttribute
    //**************************************************************************
    void test7(void)
    {
        do
        {
            // Create a local AttributeTank
            AttributeTank l_tank;

            // Add a const attribute for node 3 to the tank
            uint32_t l_val2 = 5;
            l_tank.setAttribute(ATTR_SCRATCH_UINT32_1,
                                TYPE_MBA,
                                1,
                                2,
                                3,
                                AttributeTank::ATTR_FLAG_CONST,
                                sizeof(l_val2), &l_val2);

            // Try to clear the attribute, it should not be cleared
            l_tank.clearNonConstAttribute(ATTR_SCRATCH_UINT32_1,
                                          TYPE_MBA,
                                          1,
                                          2,
                                          3);

            // Get the node 3 attribute from the tank
            l_val2 = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                      TYPE_MBA,
                                      1,
                                      2,
                                      3,
                                      &l_val2)))
            {
                TS_FAIL("tankTest7: Error. Did not get attr from tank (1)");
                break;
            }

            if (l_val2 != 5)
            {
                TS_FAIL("tankTest7: Error. Got bad value (0x%llx) from tank (2)",
                        l_val2);
                break;
            }

            // Clear all attributes from the tank
            l_tank.clearAllAttributes();

            // Add a non-const attribute for node 3 to the tank
            l_val2 = 5;
            l_tank.setAttribute(ATTR_SCRATCH_UINT32_1,
                                TYPE_MBA,
                                1,
                                2,
                                3,
                                0,
                                sizeof(l_val2), &l_val2);

            // Try to clear the attribute with node 1, it should not be cleared
            l_tank.clearNonConstAttribute(ATTR_SCRATCH_UINT32_1,
                                          TYPE_MBA,
                                          1,
                                          2,
                                          1);

            // Get the node 3 attribute from the tank
            l_val2 = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                      TYPE_MBA,
                                      1,
                                      2,
                                      3,
                                      &l_val2)))
            {
                TS_FAIL("tankTest7: Error. Did not get attr from tank (3)");
                break;
            }

            if (l_val2 != 5)
            {
                TS_FAIL("tankTest7: Error. Got bad value (0x%llx) from tank (4)",
                        l_val2);
                break;
            }

            // Clear the attribute
            l_tank.clearNonConstAttribute(ATTR_SCRATCH_UINT32_1,
                                          TYPE_MBA,
                                          1,
                                          2,
                                          3);

            // Try to get the node 3 attribute from the tank (should be cleared)
            l_val2 = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                    TYPE_MBA,
                                    1,
                                    2,
                                    3,
                                    &l_val2))
            {
                TS_FAIL("tankTest7: Error. Got cleared attr from tank (5)");
                break;
            }

        } while (0);

        TS_TRACE("tankTest7 complete" );
    }

    /**
     * @brief Test BMC Attr Override function
     *        Set attributes into 3 different tanks. Then place overrides in
     *        both correct/incorrect simulated pnor sections. Finally call
     *        getAttrOverrides to deserialize each sections data and verify
     *        that it did not apply incorrect overrides and applied correct ones
     *
     */
    void testBMCAttrOverride(void)
    {
        errlHndl_t l_errhdl = NULL;
        const uint64_t l_chunkSize = 4096;

        // Simulate Pnor ATTR_TMP and ATTR_PERM sections in memory
        PNOR::SectionInfo_t l_attrTmpSec;
        l_attrTmpSec.id = PNOR::ATTR_TMP;
        l_attrTmpSec.name = "Test Attr Tmp";
        l_attrTmpSec.vaddr = reinterpret_cast<uint64_t>(malloc(3*l_chunkSize));

        PNOR::SectionInfo_t l_attrPermSec;
        l_attrPermSec.id = PNOR::ATTR_PERM;
        l_attrPermSec.name = "Test Attr Perm";
        l_attrPermSec.vaddr = reinterpret_cast<uint64_t>(malloc(3*l_chunkSize));

        do
        {
            // Create local AttributeTanks
            AttributeTank l_FapiTank;
            AttributeTank l_TargetTank;
            AttributeTank l_PermTank;

            // Create local array of those tanks
            AttributeTank* l_tanks[AttributeTank::TANK_LAYER_LAST];

            // Create Attr Overrides
            // Add ATTR_SCRATCH_UINT64_1 to the Fapi tank
            uint64_t l_val = 4;
            l_FapiTank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                    TYPE_PROC,
                                    AttributeTank::ATTR_POS_NA,
                                    AttributeTank::ATTR_UNIT_POS_NA,
                                    AttributeTank::ATTR_NODE_NA,
                                    0, sizeof(l_val), &l_val);

            // Add ATTR_SCRATCH_UINT64_1 to the Target tank
            l_TargetTank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_PROC,
                                      1,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      AttributeTank::ATTR_NODE_NA,
                                      0, sizeof(l_val), &l_val);
            // Add ATTR_SCRATCH_UINT64_1 to the Perm tank
            l_PermTank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                    TYPE_PROC,
                                    1,
                                    AttributeTank::ATTR_UNIT_POS_NA,
                                    AttributeTank::ATTR_NODE_NA,
                                    0, sizeof(l_val), &l_val);


            ////////////////////////////////////////////////////////////////////
            // Fill in simulated pnor sections
            // Add a fapi, targ, and perm overrides to both sections to test
            // catching incorrect ones and applying the correct ones

            uint32_t l_permIndex = 0;
            uint32_t l_tmpIndex = 0;
            AttrOverrideSection * l_pAttrOverSec = NULL;
            AttributeTank::AttributeSerializedChunk l_chunk;

            // Fapi - Serialize all attributes from each tank
            AttributeTank::AttributeSerializedChunks_t l_attributes;
            l_FapiTank.serializeAttributes(AttributeTank::ALLOC_TYPE_NEW,
                    l_chunkSize, l_attributes);

            // Copy Fapi Overrides to test tmp and perm sections
            for (AttributeTank::AttributeSerializedChunks_t::iterator
                    chunkIter = l_attributes.begin();
                    chunkIter != l_attributes.end();
                    ++chunkIter)
            {
                l_chunk = *chunkIter;

                // handle tmp section
                l_pAttrOverSec = reinterpret_cast<AttrOverrideSection *>
                                        (l_attrTmpSec.vaddr + l_tmpIndex);
                l_pAttrOverSec->iv_layer = AttributeTank::TANK_LAYER_FAPI;
                l_pAttrOverSec->iv_size = l_chunk.iv_size;
                memcpy(&l_pAttrOverSec->iv_chunk, l_chunk.iv_pAttributes,
                        l_chunk.iv_size);
                l_tmpIndex += sizeof(AttrOverrideSection)+
                                        l_pAttrOverSec->iv_size;

                // handle perm section
                l_pAttrOverSec = reinterpret_cast<AttrOverrideSection *>
                                        (l_attrPermSec.vaddr + l_permIndex);
                l_pAttrOverSec->iv_layer = AttributeTank::TANK_LAYER_FAPI;
                l_pAttrOverSec->iv_size = l_chunk.iv_size;
                memcpy(&l_pAttrOverSec->iv_chunk, l_chunk.iv_pAttributes,
                        l_chunk.iv_size);
                l_permIndex += sizeof(AttrOverrideSection)+
                                        l_pAttrOverSec->iv_size;
            }

            // Targeting - Serialize all attributes from tank
            l_attributes.clear();
            l_TargetTank.serializeAttributes(AttributeTank::ALLOC_TYPE_NEW,
                    l_chunkSize, l_attributes);

            // Copy Target Override chunk to test tmp and perm sections
            for (AttributeTank::AttributeSerializedChunks_t::iterator
                    chunkIter = l_attributes.begin();
                    chunkIter != l_attributes.end();
                    ++chunkIter)
            {
                l_chunk = *chunkIter;

                // handle tmp section
                l_pAttrOverSec = reinterpret_cast<AttrOverrideSection *>
                                        (l_attrTmpSec.vaddr + l_tmpIndex);
                l_pAttrOverSec->iv_layer = AttributeTank::TANK_LAYER_TARG;
                l_pAttrOverSec->iv_size = l_chunk.iv_size;
                memcpy(&l_pAttrOverSec->iv_chunk, l_chunk.iv_pAttributes,
                        l_chunk.iv_size);
                l_tmpIndex += sizeof(AttrOverrideSection)+
                                        l_pAttrOverSec->iv_size;

                // handle perm section
                l_pAttrOverSec = reinterpret_cast<AttrOverrideSection *>
                                        (l_attrPermSec.vaddr + l_permIndex);
                l_pAttrOverSec->iv_layer = AttributeTank::TANK_LAYER_TARG;
                l_pAttrOverSec->iv_size = l_chunk.iv_size;
                memcpy(&l_pAttrOverSec->iv_chunk, l_chunk.iv_pAttributes,
                        l_chunk.iv_size);
                l_permIndex += sizeof(AttrOverrideSection)+
                                        l_pAttrOverSec->iv_size;
            }

            // Permanent - Serialize all attributes from tank
            l_attributes.clear();
            l_PermTank.serializeAttributes(AttributeTank::ALLOC_TYPE_NEW,
                    l_chunkSize, l_attributes);

            // Copy Perm Override chunk to test tmp and perm sections
            for (AttributeTank::AttributeSerializedChunks_t::iterator
                    chunkIter = l_attributes.begin();
                    chunkIter != l_attributes.end();
                    ++chunkIter)
            {
                l_chunk = *chunkIter;

                // handle tmp section
                l_pAttrOverSec = reinterpret_cast<AttrOverrideSection *>
                                        (l_attrTmpSec.vaddr + l_tmpIndex);
                l_pAttrOverSec->iv_layer = AttributeTank::TANK_LAYER_PERM;
                l_pAttrOverSec->iv_size = l_chunk.iv_size;
                memcpy(&l_pAttrOverSec->iv_chunk, l_chunk.iv_pAttributes,
                        l_chunk.iv_size);
                l_tmpIndex += sizeof(AttrOverrideSection)+
                                        l_pAttrOverSec->iv_size;

                // handle perm section
                l_pAttrOverSec = reinterpret_cast<AttrOverrideSection *>
                                        (l_attrPermSec.vaddr + l_permIndex);
                l_pAttrOverSec->iv_layer = AttributeTank::TANK_LAYER_PERM;
                l_pAttrOverSec->iv_size = l_chunk.iv_size;
                memcpy(&l_pAttrOverSec->iv_chunk, l_chunk.iv_pAttributes,
                        l_chunk.iv_size);
                l_permIndex += sizeof(AttrOverrideSection)+
                                        l_pAttrOverSec->iv_size;
            }

            // Add termination section

            // handle tmp section
            l_pAttrOverSec = reinterpret_cast<AttrOverrideSection *>
                                    (l_attrTmpSec.vaddr + l_tmpIndex);
            l_pAttrOverSec->iv_layer = AttributeTank::TANK_LAYER_TERM;
            l_pAttrOverSec->iv_size = 0;
            l_tmpIndex += sizeof(AttrOverrideSection);

            // handle perm section
            l_pAttrOverSec = reinterpret_cast<AttrOverrideSection *>
                                    (l_attrPermSec.vaddr + l_permIndex);
            l_pAttrOverSec->iv_layer = AttributeTank::TANK_LAYER_TERM;
            l_pAttrOverSec->iv_size = 0;
            l_permIndex += sizeof(AttrOverrideSection);

            // Update final size of created section
            l_attrTmpSec.size = l_tmpIndex;
            l_attrPermSec.size = l_permIndex;

            ////////////////////////////////////////////////////////////////////
            // Test simulated pnor sections attr overrides

            // Test Attr Tmp - should only include Fapi and Targ overrides
            l_FapiTank.clearAllAttributes();
            l_TargetTank.clearAllAttributes();
            l_PermTank.clearAllAttributes();

            l_tanks[AttributeTank::TANK_LAYER_FAPI-1] = &l_FapiTank;
            l_tanks[AttributeTank::TANK_LAYER_TARG-1] = &l_TargetTank;
            l_tanks[AttributeTank::TANK_LAYER_PERM-1] = &l_PermTank;

            // Call function that actually reads in attribute overrides
            l_errhdl = getAttrOverrides(l_attrTmpSec, l_tanks);

            if (l_errhdl)
            {
                errlCommit(l_errhdl, TARG_COMP_ID);
                TS_FAIL("testattrtank::testBMCAttrOverride getAttrOverrides() failed");
                break;
            }

            ////////////////////////////////////////////////////////////////////
            // Check the first attribute made it back into the Fapi tank
            l_val = 0;
            if (!(l_FapiTank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                          TYPE_PROC,
                                          AttributeTank::ATTR_POS_NA,
                                          AttributeTank::ATTR_UNIT_POS_NA,
                                          AttributeTank::ATTR_NODE_NA,
                                          &l_val)))
            {
                TS_FAIL("testattrtank::testBMCAttrOverride: Error. Did not get attr from Fapi Tank");
                break;
            }
            if (l_val != 4)
            {
                TS_FAIL("testattrtank::testBMCAttrOverride: Error. Got bad value (0x%X) from Fapi Tank",
                        l_val);
                break;
            }

            // Check the first attribute made it back into the Target tank
            l_val = 0;
            if (!(l_TargetTank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                            TYPE_PROC,
                                            1,
                                            AttributeTank::ATTR_UNIT_POS_NA,
                                            AttributeTank::ATTR_NODE_NA,
                                            &l_val)))
            {
                TS_FAIL("testattrtank::testBMCAttrOverride: Error. Did not get attr from Target Tank");
                break;
            }
            if (l_val != 4)
            {
                TS_FAIL("testattrtank::testBMCAttrOverride: Error. Got bad value (0x%X) from Target Tank",
                        l_val);
                break;
            }

            // Check to make sure no Permanent overrides were applied
            if (l_PermTank.size() > 0)
            {
                TS_FAIL("testattrtank::testBMCAttrOverride: Error. A permanent override was found and applied in the PNOR::TMP section");
                break;
            }

            // Test Attr Perm - should only include Perm overrides
            l_tanks[AttributeTank::TANK_LAYER_FAPI-1]->clearAllAttributes();
            l_tanks[AttributeTank::TANK_LAYER_TARG-1]->clearAllAttributes();
            l_tanks[AttributeTank::TANK_LAYER_PERM-1]->clearAllAttributes();

            // Call function that actually reads in attribute overrides
            l_errhdl = getAttrOverrides(l_attrPermSec, l_tanks);

            // Check the first attribute made it back into the Perm tank
            l_val = 0;
            if (!(l_PermTank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                          TYPE_PROC,
                                          1,
                                          AttributeTank::ATTR_UNIT_POS_NA,
                                          AttributeTank::ATTR_NODE_NA,
                                          &l_val)))
            {
                TS_FAIL("testattrtank::testBMCAttrOverride: Error. Did not get attr from Perm Tank");
                break;
            }
            if (l_val != 4)
            {
                TS_FAIL("testattrtank::testBMCAttrOverride: Error. Got bad value (0x%X) from Perm Tank",
                        l_val);
                break;
            }
            // Check to make sure no Fapi overrides were applied
            if (l_FapiTank.size() > 0)
            {
                TS_FAIL("testattrtank::testBMCAttrOverride: Error. A fapi override was found and applied in the PNOR::PERM section");
                break;
            }
            // Check to make sure no Targ overrides were applied
            if (l_TargetTank.size() > 0)
            {
                TS_FAIL("testattrtank::testBMCAttrOverride: Error. A targ override was found and applied in the PNOR::PERM section");
                break;
            }

        } while(0);

        // Free memory
        free (reinterpret_cast<char *>(l_attrTmpSec.vaddr));
        free (reinterpret_cast<char *>(l_attrPermSec.vaddr));
    }

    /**
     * @brief Test to check if the const array tankLayerToPnor is sorted
     *        which also indicates in enum order
     */
    void testLidToPnorSorted(void)
    {
        for (size_t i = 0; i < (AttributeTank::TANK_LAYER_LAST - 1); ++i)
        {
            if (tankLayerToPnor[i].first > tankLayerToPnor[i+1].first)
            {
                TS_FAIL("testattrtank::testTankLayerToPnorSorted: attrPlatOverride.H tankLayerToPnor[] is not sorted");
            }
        }
    }
};

#endif
