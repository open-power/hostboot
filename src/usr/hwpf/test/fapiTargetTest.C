/**
 *  @file fapitargetTest.C
 *
 *  @brief Implements Target class unit test functions.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created.
 *
 */

#include <fapi.H>

namespace fapi
{

//******************************************************************************
// targetTest1
//******************************************************************************
uint32_t targetTest1()
{
    uint32_t l_result = 0;

    // Create Target using default constructor
    Target l_target;

    // Ensure that the handle pointer is NULL
    void * l_pHandle = l_target.get();

    if (l_pHandle != NULL)
    {
        FAPI_ERR("targetTest1. Handle is not NULL");
        l_result = 1;
    }
    else
    {
        // Ensure that the type is TARGET_TYPE_NONE
        TargetType l_type = l_target.getType();

        if (l_type != TARGET_TYPE_NONE)
        {
            FAPI_ERR("targetTest1. Type is 0x%x, expected NONE", l_type);
            l_result = 2;
        }
    }

    return l_result;
}

//******************************************************************************
// targetTest2
//******************************************************************************
uint32_t targetTest2()
{
    uint32_t l_result = 0;
    uint8_t l_handle = 7;
    void * l_pHandle = reinterpret_cast<void *>(&l_handle);

    // Create Target
    Target l_target(TARGET_TYPE_DIMM, l_pHandle);

    // Ensure that the handle pointer is as expected
    void * l_pHandleCheck = l_target.get();

    if (l_pHandleCheck != l_pHandle)
    {
        FAPI_ERR("targetTest2. Handle is not as expected");
        l_result = 1;
    }
    else
    {
        // Ensure that the type is TARGET_TYPE_DIMM
        TargetType l_type = l_target.getType();

        if (l_type != TARGET_TYPE_DIMM)
        {
            FAPI_ERR("targetTest2. Type is 0x%x, expected DIMM", l_type);
            l_result = 2;
        }
    }

    // Set the handle pointer to NULL to prevent any problem on destruction
    l_target.set(NULL);

    return l_result;
}

//******************************************************************************
// targetTest3
//******************************************************************************
uint32_t targetTest3()
{
    uint32_t l_result = 0;

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
        FAPI_ERR("targetTest3. Handle is not as expected");
        l_result = 1;
    }
    else
    {
        // Set the type
        l_target.setType(TARGET_TYPE_DIMM);

        // Ensure that the type is TARGET_TYPE_DIMM
        TargetType l_type = l_target.getType();

        if (l_type != TARGET_TYPE_DIMM)
        {
            FAPI_ERR("targetTest3. Type is 0x%x, expected DIMM", l_type);
            l_result = 2;
        }
    }

    return l_result;
}

//******************************************************************************
// targetTest4
//******************************************************************************
uint32_t targetTest4()
{
    uint32_t l_result = 0;

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
        FAPI_ERR("targetTest4. Types are not the same (0x%x, 0x%x)", l_type,
                 l_type2);
        l_result = 1;
    }
    else
    {
        // Ensure that the handles are the same
        void * l_han1 = l_target.get();
        void * l_han2 = l_target2.get();

        if (l_han1 != l_han2)
        {
            FAPI_ERR("targetTest4. Handles are not the same");
            l_result = 2;
        }
    }

    return l_result;
}

//******************************************************************************
// targetTest5
//******************************************************************************
uint32_t targetTest5()
{
    uint32_t l_result = 0;

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
        FAPI_ERR("targetTest5. Types are not the same (0x%x, 0x%x)", l_type,
                 l_type2);
        l_result = 1;
    }
    else
    {
        // Ensure that the handles are the same
        void * l_han1 = l_target.get();
        void * l_han2 = l_target2.get();

        if (l_han1 != l_han2)
        {
            FAPI_ERR("targetTest5. Handles are not the same");
            l_result = 2;
        }
    }

    return l_result;
}

//******************************************************************************
// targetTest6
//******************************************************************************
uint32_t targetTest6()
{
    uint32_t l_result = 0;

    // Create similar Targets
    uint8_t l_handle = 7;
    void * l_pHandle = reinterpret_cast<void *>(&l_handle);
    Target l_target(TARGET_TYPE_DIMM, l_pHandle);
    Target l_target2(TARGET_TYPE_DIMM, l_pHandle);

    // Ensure that the equality comparison returns true
    if (!(l_target == l_target2))
    {
        FAPI_ERR("targetTest6. 1. Equality comparison false");
        l_result = 1;
    }
    else
    {
        // Ensure that the inequality comparison returns false
        if (l_target != l_target2)
        {
            FAPI_ERR("targetTest6. 2. Inequality comparison true");
            l_result = 2;
        }
        else
        {
            // Change the target type of l_target2
            (void)l_target2.setType(TARGET_TYPE_PROC_CHIP);

            // Ensure that the equality comparison returns false
            if (l_target == l_target2)
            {
                FAPI_ERR("targetTest6. 3. Equality comparison true");
                l_result = 3;
            }
            else
            {
                // Ensure that the inequality comparison returns true
                if (!(l_target != l_target2))
                {
                    FAPI_ERR("targetTest6. 4. Inequality comparison false");
                    l_result = 4;
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
                        FAPI_ERR("targetTest6. 5. Equality comparison true");
                        l_result = 5;
                    }
                    else
                    {
                        // Ensure that the inequality comparison returns true
                        if (!(l_target != l_target2))
                        {
                            FAPI_ERR("targetTest6. 6. Inequality comparison "
                                    "false");
                            l_result = 6;
                        }
                    }
                }
            }
        }
    }

    return l_result;
}

}
