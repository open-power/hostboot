#ifndef __FAPITARGETTEST_H
#define __FAPITARGETTEST_H

/**
 *  @file fapitargettest.H
 *
 *  @brief Test case for FAPI targets
*/

#include <cxxtest/TestSuite.H>
#include <fapi.H>

using namespace fapi;

class FapiTargetTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief Test target #1
     */
    void testTarget1()
    {
        // Create Target using default constructor
        Target l_target;

        // Ensure that the handle pointer is NULL
        void * l_pHandle = l_target.get();

        if (l_pHandle != NULL)
        {
            TS_FAIL("testTarget1. Handle is not NULL");
        }
        else
        {
            // Ensure that the type is TARGET_TYPE_NONE
            TargetType l_type = l_target.getType();
            if (l_type != TARGET_TYPE_NONE)
            {
                TS_FAIL("testTarget1. Type is not TARGET_TYPE_NONE");
            }
        }

        return;
    }

    /**
     * @brief Test target #2
     */
    void testTarget2()
    {
        uint8_t l_handle = 7;
        void * l_pHandle = reinterpret_cast<void *>(&l_handle);

        // Create Target
        Target l_target(TARGET_TYPE_DIMM, l_pHandle);

        // Ensure that the handle pointer is as expected
        void * l_pHandleCheck = l_target.get();

        if (l_pHandleCheck != l_pHandle)
        {
            TS_FAIL("testTarget2. Handle is not as expected");
        }
        else
        {
            // Ensure that the type is TARGET_TYPE_DIMM
            TargetType l_type = l_target.getType();

            if (l_type != TARGET_TYPE_DIMM)
            {
                TS_FAIL("testTarget2. Type is not TARGET_TYPE_DIMM");
            }
        }

        // Set the handle pointer to NULL to prevent any problem on destruction
        l_target.set(NULL);

        return;
    }

    /**
     * @brief Test target #3
     */
    void testTarget3()
    {
        // Create Target using default constructor
        Target l_target;

        // Set the handle
        uint8_t l_handle = 7;
        void * l_pHandle = reinterpret_cast<void *>(&l_handle);
        l_target.set(l_pHandle);

        // Ensure that the handle pointer is as expected
        void * l_pHandleCheck = l_target.get();

        if (l_pHandleCheck != l_pHandle)
        {
            TS_FAIL("testTarget3. Handle is not as expected");
        }
        else
        {
            // Set the type
            l_target.setType(TARGET_TYPE_DIMM);

            // Ensure that the type is TARGET_TYPE_DIMM
            TargetType l_type = l_target.getType();

            if (l_type != TARGET_TYPE_DIMM)
            {
                TS_FAIL("testTarget3. Type is not TARGET_TYPE_DIMM");
            }
        }

        return;
    }

    /**
     * @brief Test target #4
     */
    void testTarget4()
    {
        // Create Target
        uint8_t l_handle = 7;
        void * l_pHandle = reinterpret_cast<void *>(&l_handle);
        Target l_target(TARGET_TYPE_DIMM, l_pHandle);

        // Create Target using copy constructor
        Target l_target2(l_target);

        // Ensure that the target types are the same
        TargetType l_type = l_target.getType();
        TargetType l_type2 = l_target2.getType();

        if (l_type != l_type2)
        {
            TS_FAIL("testTarget4. Types are not the same ");
        }
        else
        {
            // Ensure that the handles are the same
            void * l_han1 = l_target.get();
            void * l_han2 = l_target2.get();

            if (l_han1 != l_han2)
            {
                TS_FAIL("testTarget4. Handles are not the same");
            }
        }

        return;
    }

    /**
     * @brief Test target #5
     */
    void testTarget5()
    {
        // Create Target
        uint8_t l_handle = 7;
        void * l_pHandle = reinterpret_cast<void *>(&l_handle);
        Target l_target(TARGET_TYPE_DIMM, l_pHandle);

        // Create Target using assignment operator
        Target l_target2;
        l_target2 = l_target;

        // Ensure that the target types are the same
        TargetType l_type = l_target.getType();
        TargetType l_type2 = l_target2.getType();

        if (l_type != l_type2)
        {
            TS_FAIL("testTarget5. Types are not the same");
        }
        else
        {
            // Ensure that the handles are the same
            void * l_han1 = l_target.get();
            void * l_han2 = l_target2.get();

            if (l_han1 != l_han2)
            {
                TS_FAIL("testTarget5. Handles are not the same");
            }
        }

        return;
    }

    /**
     * @brief Test target #6
     */
    void testTarget6()
    {
        // Create similar Targets
        uint8_t l_handle = 7;
        void * l_pHandle = reinterpret_cast<void *>(&l_handle);
        Target l_target(TARGET_TYPE_DIMM, l_pHandle);
        Target l_target2(TARGET_TYPE_DIMM, l_pHandle);

        // Ensure that the equality comparison returns true
        if (!(l_target == l_target2))
        {
            TS_FAIL("testTarget6. 1. Equality comparison false");
        }
        else
        {
            // Ensure that the inequality comparison returns false
            if (l_target != l_target2)
            {
                TS_FAIL("testTarget6. 2. Inequality comparison true");
            }
            else
            {
                // Change the target type of l_target2
                (void)l_target2.setType(TARGET_TYPE_PROC_CHIP);

                // Ensure that the equality comparison returns false
                if (l_target == l_target2)
                {
                    TS_FAIL("testTarget6. 3. Equality comparison true");
                }
                else
                {
                    // Ensure that the inequality comparison returns true
                    if (!(l_target != l_target2))
                    {
                        TS_FAIL("testTarget6. 4. Inequality comparison false");
                    }
                    else
                    {
                        // Reset the target type of l_target2
                        (void)l_target2.setType(TARGET_TYPE_DIMM);

                        // Change the handle of l_target
                        uint8_t l_handle2 = 7;
                        void * l_pHandle2 = reinterpret_cast<void *>(&l_handle2);
                        (void)l_target.set(l_pHandle2);

                        // Ensure that the equality comparison returns false
                        if (l_target == l_target2)
                        {
                            TS_FAIL("testTarget6. 5. Equality comparison true");
                        }
                        else
                        {
                            // Ensure that the inequality comparison returns true
                            if (!(l_target != l_target2))
                            {
                                TS_FAIL("testTarget6. 6. Inequality comparison "
                                        "false");
                            }
                        }
                    }
                }
            }
        }

        return;
    }

};

#endif
