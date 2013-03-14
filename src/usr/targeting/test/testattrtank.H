/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/testattrtank.H $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
                                          AttributeTank::ATTR_UNIT_POS_NA);

            // Try to get an attribute from empty tank
            uint64_t l_val = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                    TYPE_SYS,
                                    AttributeTank::ATTR_POS_NA,
                                    AttributeTank::ATTR_UNIT_POS_NA,
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
                                      &l_val)))
            {
                TS_FAIL("tankTest2: Error. Did not get attr from tank (6)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL(
                    "tankTest2: Error. Got bad value (0x%llx) from tank (7)",
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

            // Serialize all attributes from the tank
            std::vector<AttributeTank::AttributeSerializedChunk> l_attributes;
            l_tank.serializeAttributes(AttributeTank::ALLOC_TYPE_NEW,
                                       4096, l_attributes);

            if (l_attributes.size() != 1)
            {
                TS_FAIL(
                    "tankTest2: Error. Got wrong number of chunks (%d) from tank (12)",
                    l_attributes.size());
                break;
            }

            if (l_attributes[0].iv_size !=
                (sizeof(AttributeTank::AttributeHeader) + sizeof(l_val)))
            {
                TS_FAIL(
                    "tankTest2: Error. Got wrong size (%d) of attrs from tank (13)",
                    l_attributes[0].iv_size);
                break;
            }

            uint64_t * l_pVal = reinterpret_cast<uint64_t *>
                (l_attributes[0].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal != 4)
            {
                TS_FAIL(
                    "tankTest2: Error. Got bad value (0x%016llx) from tank (14)",
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
                                    &l_val))
            {
                TS_FAIL("tankTest2: Error. Got value from empty tank (15)");
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
                                      &l_val)))
            {
                TS_FAIL("tankTest2: Error. Did not get attr from tank (16)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL(
                    "tankTest2: Error. Got bad value (0x%llx) from tank (17)",
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
                                0, sizeof(l_val), &l_val);

            // Add ATTR_SCRATCH_UINT32_1 as an MBA attribute to the tank
            uint32_t l_val2 = 5;
            l_tank.setAttribute(ATTR_SCRATCH_UINT32_1,
                                TYPE_MBA,
                                1,
                                2,
                                0, sizeof(l_val2), &l_val2);

            // Get the first attribute from the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_PROC,
                                      1,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (1)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL(
                    "tankTest3: Error. Got bad value (0x%016llx) from tank (2)",
                    l_val);
                break;
            }

            // Try to get the first attribute from the tank with the wrong pos
            l_val = 0;
            if (l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                    TYPE_PROC,
                                    2,
                                    AttributeTank::ATTR_UNIT_POS_NA,
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
                                      &l_val2)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (4)");
                break;
            }

            if (l_val2 != 5)
            {
                TS_FAIL(
                    "tankTest3: Error. Got bad value (0x%llx) from tank (5)",
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
                                    &l_val2))
            {
                TS_FAIL("tankTest3: Error. Got wrong attr from tank (6)");
                break;
            }

            // Serialize all attributes from the tank into a single chunk
            std::vector<AttributeTank::AttributeSerializedChunk> l_attributes;
            l_tank.serializeAttributes(AttributeTank::ALLOC_TYPE_MALLOC,
                                       4096, l_attributes);

            if (l_attributes.size() != 1)
            {
                TS_FAIL(
                    "tankTest3: Error. Got wrong number of chunks (%d) from tank (7)",
                    l_attributes.size());
                break;
            }

            if (l_attributes[0].iv_size !=
                (sizeof(AttributeTank::AttributeHeader) + sizeof(l_val) +
                 sizeof(AttributeTank::AttributeHeader) + sizeof(l_val2)) )
            {
                TS_FAIL(
                    "tankTest3: Error. Got wrong size (%d) of attrs from tank (8)",
                    l_attributes[0].iv_size);
                break;
            }

            uint64_t * l_pVal = reinterpret_cast<uint64_t *>
                (l_attributes[0].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal != 4)
            {
                TS_FAIL(
                    "tankTest3: Error. Got bad value (0x%016llx) from tank (9)",
                    *l_pVal);
                break;
            }

            uint32_t * l_pVal2 = reinterpret_cast<uint32_t *>
                (l_attributes[0].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader) +
                 sizeof(l_val) + sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal2 != 5)
            {
                TS_FAIL(
                    "tankTest3: Error. Got bad value (0x%08x) from tank (10)",
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
                                      &l_val)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (11)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL(
                    "tankTest3: Error. Got bad value (0x%016llx) from tank (12)",
                    l_val);
                break;
            }

            // Check the second attribute made it back into the tank
            l_val2 = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                      TYPE_MBA,
                                      1,
                                      2,
                                      &l_val2)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (13)");
                break;
            }

            if (l_val2 != 5)
            {
                TS_FAIL(
                    "tankTest3: Error. Got bad value (0x%llx) from tank (14)",
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
                TS_FAIL(
                    "tankTest3: Error. Got wrong number of chunks (%d) from tank (15)",
                    l_attributes.size());
                break;
            }

            if (l_attributes[0].iv_size !=
                (sizeof(AttributeTank::AttributeHeader) + sizeof(l_val)))
            {
                TS_FAIL(
                    "tankTest3: Error. Got wrong size (%d) of attrs from tank (16)",
                    l_attributes[0].iv_size);
                break;
            }

            l_pVal = reinterpret_cast<uint64_t *>
                (l_attributes[0].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal != 4)
            {
                TS_FAIL(
                    "tankTest3: Error. Got bad value (0x%016llx) from tank (17)",
                    *l_pVal);
                break;
            }

            if (l_attributes[1].iv_size !=
                (sizeof(AttributeTank::AttributeHeader) + sizeof(l_val2)))
            {
                TS_FAIL(
                    "tankTest3: Error. Got wrong size (%d) of attrs from tank (18)",
                    l_attributes[1].iv_size);
                break;
            }

            l_pVal2 = reinterpret_cast<uint32_t *>
                (l_attributes[1].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal2 != 5)
            {
                TS_FAIL(
                    "tankTest3: Error. Got bad value (0x%016llx) from tank (19)",
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
                                      &l_val)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (20)");
                break;
            }

            if (l_val != 4)
            {
                TS_FAIL(
                    "tankTest3: Error. Got bad value (0x%016llx) from tank (21)",
                    l_val);
                break;
            }

            // Check the second attribute made it back into the tank
            l_val2 = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT32_1,
                                      TYPE_MBA,
                                      1,
                                      2,
                                      &l_val2)))
            {
                TS_FAIL("tankTest3: Error. Did not get attr from tank (22)");
                break;
            }

            if (l_val2 != 5)
            {
                TS_FAIL(
                    "tankTest3: Error. Got bad value (0x%llx) from tank (23)",
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
                                AttributeTank::ATTR_FLAG_CONST,
                                sizeof(l_val), &l_val);

            // Try to clear the attribute, it should not be cleared
            l_tank.clearNonConstAttribute(ATTR_SCRATCH_UINT8_1,
                                          TYPE_SYS,
                                          AttributeTank::ATTR_POS_NA,
                                          AttributeTank::ATTR_UNIT_POS_NA);

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
                                0, sizeof(l_val), &l_val);

            l_val = 5;
            l_tank.setAttribute(ATTR_SCRATCH_UINT64_1,
                                TYPE_SYS,
                                AttributeTank::ATTR_POS_NA,
                                AttributeTank::ATTR_UNIT_POS_NA,
                                0, sizeof(l_val), &l_val);

            // Get the attribute from the tank
            l_val = 0;
            if (!(l_tank.getAttribute(ATTR_SCRATCH_UINT64_1,
                                      TYPE_SYS,
                                      AttributeTank::ATTR_POS_NA,
                                      AttributeTank::ATTR_UNIT_POS_NA,
                                      &l_val)))
            {
                TS_FAIL("tankTest5: Error. Did not get attr from tank (1)");
                break;
            }

            if (l_val != 5)
            {
                TS_FAIL(
                    "tankTest5: Error. Got bad value (0x%llx) from tank (2)",
                    l_val);
                break;
            }

            // Serialize all attributes from the tank
            std::vector<AttributeTank::AttributeSerializedChunk> l_attributes;
            l_tank.serializeAttributes(AttributeTank::ALLOC_TYPE_NEW,
                                       4096, l_attributes);

            if (l_attributes.size() != 1)
            {
                TS_FAIL(
                    "tankTest5: Error. Got wrong number of chunks (%d) from tank (3)",
                    l_attributes.size());
                break;
            }

            if (l_attributes[0].iv_size !=
                (sizeof(AttributeTank::AttributeHeader) + sizeof(l_val)))
            {
                TS_FAIL(
                    "tankTest5: Error. Got wrong size (%d) of attrs from tank (4)",
                    l_attributes[0].iv_size);
                break;
            }

            uint64_t * l_pVal = reinterpret_cast<uint64_t *>
                (l_attributes[0].iv_pAttributes +
                 sizeof(AttributeTank::AttributeHeader));

            if (*l_pVal != 5)
            {
                TS_FAIL(
                    "tankTest5: Error. Got bad value (0x%016llx) from tank (5)",
                    *l_pVal);
                break;
            }
            delete [] l_attributes[0].iv_pAttributes;
            l_attributes[0].iv_pAttributes = NULL;

        } while (0);

        TS_TRACE("tankTest5 complete" );
    }

};

#endif
