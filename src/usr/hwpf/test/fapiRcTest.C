//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/test/fapiRcTest.C $
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
/**
 *  @file fapiTargetTest.C
 *
 *  @brief Implements Target class unit test functions.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created.
 *                          mjjones     07/26/2011  Added more tests
 *
 */

#include <fapi.H>

namespace fapi
{

//******************************************************************************
// rcTest1. Ensures that the ReturnCode default constructor works
//******************************************************************************
uint32_t rcTest1()
{
    uint32_t l_result = 0;

    // Create ReturnCode using default constructor
    ReturnCode l_rc;

    // Ensure that the embedded return code is success
    if (l_rc != FAPI_RC_SUCCESS)
    {
        FAPI_ERR("rcTest1. Code is 0x%x, expected success",
                 static_cast<uint32_t>(l_rc));
        l_result = 1;
    }
    else
    {
        // Ensure that ok function works
        if (l_rc.ok() == false)
        {
            FAPI_ERR("rcTest1. ok returned false");
            l_result = 2;
        }
        else
        {
            // Ensure that testing l_rc works
            if (l_rc)
            {
                FAPI_ERR("rcTest1. testing rc returned true");
                l_result = 3;
            }
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest2. Ensures that the ReturnCode creator reflects the return code
//******************************************************************************
uint32_t rcTest2()
{
    uint32_t l_result = 0;

    // Create ReturnCode using default constructor
    ReturnCode l_rc;

    // Set the return code to a FAPI code
    l_rc = FAPI_RC_FAPI_MASK | 0x05;

    // Ensure that the creator is FAPI
    ReturnCode::returnCodeCreator l_creator = l_rc.getCreator();

    if (l_creator != ReturnCode::CREATOR_FAPI)
    {
        FAPI_ERR("rcTest2. Creator is 0x%x, expected FAPI", l_creator);
        l_result = 1;
    }
    else
    {
        // Set the return code to a PLAT code
        l_rc = FAPI_RC_PLAT_ERR_SEE_DATA;

        // Ensure that the creator is PLAT
        l_creator = l_rc.getCreator();

        if (l_creator != ReturnCode::CREATOR_PLAT)
        {
            FAPI_ERR("rcTest2. Creator is 0x%x, expected PLAT", l_creator);
            l_result = 2;
        }
        else
        {
            // Set the return code to a HWP code
            l_rc = 5;

            // Ensure that the creator is HWP
            l_creator = l_rc.getCreator();

            if (l_creator != ReturnCode::CREATOR_HWP)
            {
                FAPI_ERR("rcTest2. Creator is 0x%x, expected HWP", l_creator);
                l_result = 3;
            }
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest3. Ensures that the ReturnCode constructor works when specifying a
//          return code
//******************************************************************************
uint32_t rcTest3()
{
    uint32_t l_result = 0;

    // Create ReturnCode specifying a return code
    uint32_t l_code = 4;
    ReturnCode l_rc(l_code);

    // Ensure that the embedded return code is as expected
    uint32_t l_codeCheck = l_rc;

    if (l_codeCheck != l_code)
    {
        FAPI_ERR("rcTest3. Code is 0x%x, expected 0x%x", l_codeCheck,
                l_code);
        l_result = 1;
    }
    else
    {
        // Ensure that ok function returns false
        if (l_rc.ok())
        {
            FAPI_ERR("rcTest3. ok returned true");
            l_result = 2;
        }
        else
        {
            // Ensure that testing l_rc works
            if (!l_rc)
            {
                FAPI_ERR("rcTest3. testing rc returned false");
                l_result = 3;
            }
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest4. Ensures that the comparison operators work (comparing with another
//          ReturnCode)
//******************************************************************************
uint32_t rcTest4()
{
    uint32_t l_result = 0;

    // Create similar ReturnCodes
    uint32_t l_code = 6;
    uint32_t l_code2 = 7;
    ReturnCode l_rc(l_code);
    ReturnCode l_rc2(l_code);

    // Ensure that the equality comparison returns true
    if (!(l_rc == l_rc2))
    {
        FAPI_ERR("rcTest5. 1. Equality comparison false");
        l_result = 1;
    }
    else
    {
        // Ensure that the inequality comparison returns false
        if (l_rc != l_rc2)
        {
            FAPI_ERR("rcTest5. 2. Inequality comparison true");
            l_result = 2;
        }
        else
        {
            // Change the code of l_rc2
            l_rc2 = l_code2;

            // Ensure that the equality comparison returns false
            if (l_rc == l_rc2)
            {
                FAPI_ERR("rcTest5. 3. Equality comparison true");
                l_result = 3;
            }
            else
            {
                // Ensure that the inequality comparison returns true
                if (!(l_rc != l_rc2))
                {
                    FAPI_ERR("rcTest5. 4. Inequality comparison false");
                    l_result = 4;
                }
            }
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest5. Ensures that the comparison operators work (comparing with a return
//          code value)
//******************************************************************************
uint32_t rcTest5()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    uint32_t l_code = 6;
    uint32_t l_code2 = 7;
    ReturnCode l_rc(l_code);

    // Ensure that the equality comparison returns true when comparing to the
    // same return code value
    if (!(l_rc == l_code))
    {
        FAPI_ERR("rcTest6. 1. Equality comparison false");
        l_result = 1;
    }
    else
    {
        // Ensure that the inequality comparison returns false when comparing to
        // the same return code value
        if (l_rc != l_code)
        {
            FAPI_ERR("rcTest6. 2. Inequality comparison true");
            l_result = 2;
        }
        else
        {
            // Ensure that the equality comparison returns false when comparing
            // to a different return code value
            if (l_rc == l_code2)
            {
                FAPI_ERR("rcTest6. 3. Equality comparison true");
                l_result = 3;
            }
            else
            {
                // Ensure that the inequality comparison returns true when
                // comparing to a different return code value
                if (!(l_rc != l_code2))
                {
                    FAPI_ERR("rcTest6. 4. Inequality comparison false");
                    l_result = 4;
                }
            }
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest6. Ensures that the getPlatData and releasePlatData functions work when
//          there is no attached data
//******************************************************************************
uint32_t rcTest6()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    uint32_t l_code = 6;
    ReturnCode l_rc(l_code);

    // Ensure that the getPlatData function returns NULL
    void * l_pData = reinterpret_cast<void *> (0x12345678);

    l_pData = l_rc.getPlatData();

    if (l_pData != NULL)
    {
        FAPI_ERR("rcTest7. getPlatData did not return NULL");
        l_result = 1;
    }
    else
    {
        // Ensure that the releasePlatData function returns NULL
        l_pData = reinterpret_cast<void *> (0x12345678);

        l_pData = l_rc.releasePlatData();

        if (l_pData != NULL)
        {
            FAPI_ERR("rcTest7. releasePlatData did not return NULL");
            l_result = 2;
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest7. Ensures that the getPlatData function works when there is attached
//          data
//******************************************************************************
uint32_t rcTest7()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    uint32_t l_code = 10;
    ReturnCode l_rc(l_code);

    // Assign PlatData. Note that this should really be an errlHndl_t, because
    // the FSP deleteData function will attempt to delete an error log, but this
    // is just for test, the data will be released before the ReturnCode is
    // destructed.
    uint32_t l_myData = 6;
    void * l_pMyData = reinterpret_cast<void *> (&l_myData);
    (void) l_rc.setPlatData(l_pMyData);

    // Ensure that getPlatData retrieves the PlatData
    void * l_pMyDataCheck = l_rc.getPlatData();

    if (l_pMyDataCheck != l_pMyData)
    {
        FAPI_ERR("rcTest8. 1. getPlatData returned unexpected data ptr");
        l_result = 1;
    }
    else
    {
        // Ensure that getPlatData retrieves the PlatData again
        l_pMyDataCheck = NULL;
        l_pMyDataCheck = l_rc.getPlatData();

        if (l_pMyDataCheck != l_pMyData)
        {
            FAPI_ERR("rcTest8. 2. getPlatData returned unexpected data ptr");
            l_result = 2;
        }
    }

    // Release the data to avoid ReturnCode from deleting in on destruction
    l_pMyDataCheck = l_rc.releasePlatData();

    return l_result;
}

//******************************************************************************
// rcTest8. Ensures that the releasePlatData function works when there is
//          attached data
//******************************************************************************
uint32_t rcTest8()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    uint32_t l_code = 10;
    ReturnCode l_rc(l_code);

    // Assign PlatData. Note that this should really be an errlHndl_t, because
    // the FSP deleteData function will attempt to delete an error log, but this
    // is just for test, the data will be released before the ReturnCode is
    // destructed.
    uint32_t l_myData = 6;
    void * l_pMyData = reinterpret_cast<void *> (&l_myData);
    (void) l_rc.setPlatData(l_pMyData);

    // Ensure that releasePlatData retrieves the PlatData
    void * l_pMyDataCheck = l_rc.releasePlatData();

    if (l_pMyDataCheck != l_pMyData)
    {
        FAPI_ERR("rcTest9. getPlatData returned unexpected data ptr");
        l_result = 1;
    }
    else
    {
        // Ensure that releasePlatData now returns NULL
        l_pMyDataCheck = NULL;
        l_pMyDataCheck = l_rc.releasePlatData();

        if (l_pMyDataCheck != NULL)
        {
            FAPI_ERR("rcTest9. 2. getPlatData returned non NULL ptr");
            l_result = 2;
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest9. Ensures that the copy constructor works when there is attached
//          PlatData and that the getPlatData function works
//******************************************************************************
uint32_t rcTest9()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    uint32_t l_code = 10;
    ReturnCode l_rc(l_code);

    // Assign PlatData. Note that this should really be an errlHndl_t, because
    // the FSP deleteData function will attempt to delete an error log, but this
    // is just for test, the data will be released before the ReturnCode is
    // destructed.
    uint32_t l_myData = 6;
    void * l_pMyData = reinterpret_cast<void *> (&l_myData);
    (void) l_rc.setPlatData(l_pMyData);

    // Create a ReturnCode using the copy constructor
    ReturnCode l_rc2(l_rc);

    // Ensure that the two ReturnCodes are the same
    if (l_rc != l_rc2)
    {
        FAPI_ERR("rcTest10. ReturnCodes differ");
        l_result = 1;
    }
    else
    {
        // Ensure that getPlatData retrieves the PlatData from l_rc
        void * l_pMyDataCheck = l_rc.getPlatData();

        if (l_pMyDataCheck != l_pMyData)
        {
            FAPI_ERR("rcTest10. 1. getPlatData returned unexpected data ptr");
            l_result = 2;
        }
        else
        {
            // Ensure that getPlatData retrieves the PlatData from l_rc2
            l_pMyDataCheck = NULL;
            l_pMyDataCheck = l_rc2.getPlatData();

            if (l_pMyDataCheck != l_pMyData)
            {
                FAPI_ERR("rcTest10. 2. getPlatData returned unexpected data ptr");
                l_result = 3;
            }
        }
    }

    // Release the data to avoid ReturnCode from deleting in on destruction.
    // This will release the data from both copies of the ReturnCode.
    (void) l_rc.releasePlatData();

    return l_result;
}

//******************************************************************************
// rcTest10. Ensures that the assignment operator works when there is attached
//           PlatData and that the releasePlatData function works
//******************************************************************************
uint32_t rcTest10()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    uint32_t l_code = 10;
    ReturnCode l_rc(l_code);

    // Assign PlatData. Note that this should really be an errlHndl_t, because
    // the PLAT deleteData function will attempt to delete an error log, but
    // this is just for test, the data will be released before the ReturnCode is
    // destructed.
    uint32_t l_myData = 6;
    void * l_pMyData = reinterpret_cast<void *> (&l_myData);
    (void) l_rc.setPlatData(l_pMyData);

    // Create a ReturnCode using the assignment operator
    ReturnCode l_rc2;
    l_rc2 = l_rc;

    // Ensure that the two ReturnCodes are the same
    if (l_rc != l_rc2)
    {
        FAPI_ERR("rcTest11. ReturnCodes differ");
        l_result = 1;
    }
    else
    {
        // Ensure that releasePlatData retrieves the PlatData from l_rc
        void * l_pMyDataCheck = l_rc.releasePlatData();

        if (l_pMyDataCheck != l_pMyData)
        {
            FAPI_ERR("rcTest11. releasePlatData returned unexpected data ptr");
            l_result = 2;
        }
        else
        {
            // Ensure that releasePlatData retrieves NULL from l_rc2
            l_pMyDataCheck = NULL;
            l_pMyDataCheck = l_rc2.releasePlatData();

            if (l_pMyDataCheck != NULL)
            {
                FAPI_ERR("rcTest11. releasePlatData returned non NULL ptr");
                l_result = 3;
            }
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest11. Ensures that the getHwpFfdc functions works when there is no FFDC
//******************************************************************************
uint32_t rcTest11()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    uint32_t l_code = 6;
    ReturnCode l_rc(l_code);

    // Ensure that the getHwpFfdc function returns NULL
    const void * l_pFfdc = reinterpret_cast<const void *> (0x12345678);

    // Get FFDC pointer
    uint32_t l_size = 0;
    l_pFfdc = l_rc.getHwpFfdc(l_size);

    if (l_pFfdc != NULL)
    {
        FAPI_ERR("rcTest11. getHwpFfdc did not return NULL");
        l_result = 1;
    }

    return l_result;
}

//******************************************************************************
// rcTest12. Ensures that the getHwpFfdc function works when there is FFDC
//******************************************************************************
uint32_t rcTest12()
{
    uint32_t l_result = 0;
    uint32_t l_code = 10;

    // Create a ReturnCode
    ReturnCode l_rc(l_code);

    // Add HwpFfdc.
    uint32_t l_myData[2] = {4, 5};
    void * l_pMyData = reinterpret_cast<void *> (l_myData);
    (void) l_rc.setHwpFfdc(l_pMyData, sizeof(l_myData));

    // Ensure that getHwpFfdc returns a pointer to the same data
    uint32_t l_size = 0;
    const uint32_t * l_pMyDataCheck = reinterpret_cast<const uint32_t *>
        (l_rc.getHwpFfdc(l_size));

    if (l_size != sizeof(l_myData))
    {
        FAPI_ERR("rcTest12. getHwpFfdc returned bad size %d", l_size);
        l_result = 1;
    }
    else if ((l_pMyDataCheck[0] != 4) || (l_pMyDataCheck[1] != 5))
    {
        FAPI_ERR("rcTest12. getHwpFfdc returned bad data");
        l_result = 2;
    }

    return l_result;
}

//******************************************************************************
// rcTest13. Ensures that the copy constructor works when there is FFDC and that
//           the getHwpFfdc function works
//******************************************************************************
uint32_t rcTest13()
{
    uint32_t l_result = 0;
    uint32_t l_code = 10;

    // Create a ReturnCode
    ReturnCode l_rc(l_code);

    // Add HwpFfdc.
    uint32_t l_myData[2] = {4, 5};
    void * l_pMyData = reinterpret_cast<void *> (l_myData);
    (void) l_rc.setHwpFfdc(l_pMyData, sizeof(l_myData));

    // Create a ReturnCode using the copy constructor
    ReturnCode l_rc2(l_rc);

    // Ensure that the two ReturnCodes are the same
    if (l_rc != l_rc2)
    {
        FAPI_ERR("rcTest13. ReturnCodes differ");
        l_result = 1;
    }
    else
    {
        // Ensure that getHwpFfdc returns a pointer to the same data from l_rc
        uint32_t l_size = 0;
        const uint32_t * l_pMyDataCheck = reinterpret_cast<const uint32_t *>
            (l_rc.getHwpFfdc(l_size));

        if (l_size != sizeof(l_myData))
        {
            FAPI_ERR("rcTest13. getHwpFfdc returned bad size %d", l_size);
            l_result = 2;
        }
        else if ((l_pMyDataCheck[0] != 4) || (l_pMyDataCheck[1] != 5))
        {
            FAPI_ERR("rcTest13. getHwpFfdc returned bad data");
            l_result = 3;
        }
        else
        {
            // Ensure that getHwpFfdc returns a pointer to the same data from
            // l_rc2
            uint32_t l_size2 = 0;
            const uint32_t * l_pMyDataCheck2 = reinterpret_cast<const uint32_t *>
                (l_rc2.getHwpFfdc(l_size2));

            if (l_size2 != sizeof(l_myData))
            {
                FAPI_ERR("rcTest13. getHwpFfdc(2) returned bad size %d",
                         l_size2);
                l_result = 4;
            }
            else if ((l_pMyDataCheck2[0] != 4) || (l_pMyDataCheck2[1] != 5))
            {
                FAPI_ERR("rcTest13. getHwpFfdc(2) returned bad data");
                l_result = 5;
            }
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest14. Ensures that the assignment operator works when there is FFDC and
//           that the getHwpFfdc function works
//******************************************************************************
uint32_t rcTest14()
{
    uint32_t l_result = 0;
    uint32_t l_code = 10;

    // Create a ReturnCode
    ReturnCode l_rc(l_code);

    // Add HwpFfdc.
    uint32_t l_myData[2] = {4, 5};
    void * l_pMyData = reinterpret_cast<void *> (l_myData);
    (void) l_rc.setHwpFfdc(l_pMyData, sizeof(l_myData));

    // Create a ReturnCode using the assignment operator
    ReturnCode l_rc2;
    l_rc2 = l_rc;

    // Ensure that the two ReturnCodes are the same
    if (l_rc != l_rc2)
    {
        FAPI_ERR("rcTest14. ReturnCodes differ");
        l_result = 1;
    }
    else
    {
        // Ensure that getHwpFfdc returns a pointer to the same data from l_rc
        uint32_t l_size = 0;
        const uint32_t * l_pMyDataCheck = reinterpret_cast<const uint32_t *>
            (l_rc.getHwpFfdc(l_size));

        if (l_size != sizeof(l_myData))
        {
            FAPI_ERR("rcTest14. getHwpFfdc returned bad size %d", l_size);
            l_result = 2;
        }
        else if ((l_pMyDataCheck[0] != 4) || (l_pMyDataCheck[1] != 5))
        {
            FAPI_ERR("rcTest14. getHwpFfdc returned bad data");
            l_result = 3;
        }
        else
        {
            // Ensure that getHwpFfdc returns a pointer to the same data from
            // l_rc2
            uint32_t l_size2 = 0;
            const uint32_t * l_pMyDataCheck2 = reinterpret_cast<const uint32_t *>
                (l_rc2.getHwpFfdc(l_size2));

            if (l_size2 != sizeof(l_myData))
            {
                FAPI_ERR("rcTest14. getHwpFfdc(2) returned bad size %d",
                         l_size2);
                l_result = 4;
            }
            else if ((l_pMyDataCheck2[0] != 4) || (l_pMyDataCheck2[1] != 5))
            {
                FAPI_ERR("rcTest14. getHwpFfdc(2) returned bad data");
                l_result = 5;
            }
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest15. Ensures that the setErrTarget function works when there is no error
//******************************************************************************
uint32_t rcTest15()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;

    // Create a Target
    uint8_t l_handle = 7;
    void * l_pHandle = reinterpret_cast<void *>(&l_handle);
    Target l_target(TARGET_TYPE_DIMM, l_pHandle);

    // Set the error target
    l_rc.setErrTarget(l_target);

    // Retreive the Error target (should be null because no error)
    Target * l_pTarget = l_rc.getErrTarget();

    if (l_pTarget != NULL)
    {
        FAPI_ERR("rcTest15. getErrTarget returned non-null pointer");
        l_result = 1;
    }

    // Set the handle pointer to NULL to prevent any problem on destruction
    l_target.set(NULL);

    return l_result;
}

//******************************************************************************
// rcTest16. Ensures that the setErrTarget function works when there is an error
//******************************************************************************
uint32_t rcTest16()
{
    uint32_t l_result = 0;

    // Create a ReturnCode with an error
    ReturnCode l_rc(8);

    // Create a Target
    uint8_t l_handle = 7;
    void * l_pHandle = reinterpret_cast<void *>(&l_handle);
    Target l_target(TARGET_TYPE_DIMM, l_pHandle);

    // Set the error target
    l_rc.setErrTarget(l_target);

    // Retreive the Error target
    Target * l_pTarget = l_rc.getErrTarget();

    if (*l_pTarget != l_target)
    {
        FAPI_ERR("rcTest16. getErrTarget returned bad target");
        l_result = 1;
    }

    // Set the handle pointer to NULL to prevent any problem on destruction
    l_target.set(NULL);

    return l_result;
}

//******************************************************************************
// rcTest17. Ensures that the setErrTarget function works when there is an error
//           and an existing Target
//******************************************************************************
uint32_t rcTest17()
{
    uint32_t l_result = 0;

    // Create a ReturnCode with an error
    ReturnCode l_rc(8);

    // Create a Target
    uint8_t l_handle = 7;
    void * l_pHandle = reinterpret_cast<void *>(&l_handle);
    Target l_target(TARGET_TYPE_DIMM, l_pHandle);

    // Create another Target
    uint8_t l_handle2 = 8;
    void * l_pHandle2 = reinterpret_cast<void *>(&l_handle2);
    Target l_target2(TARGET_TYPE_DIMM, l_pHandle2);

    // Set the error target
    l_rc.setErrTarget(l_target);

    // Attempt to set the error target again (should not be set because there is
    // already an error target)
    l_rc.setErrTarget(l_target2);

    // Retreive the Error target
    Target * l_pTarget = l_rc.getErrTarget();

    if (*l_pTarget != l_target)
    {
        FAPI_ERR("rcTest17. getErrTarget returned bad target");
        l_result = 1;
    }

    // Set the handle pointer to NULL to prevent any problem on destruction
    l_target.set(NULL);

    return l_result;
}

}
