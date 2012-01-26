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
 *                          mjjones     09/23/2011  Updated test for ErrorInfo
 *                          mjjones     01/13/2012  Use new ReturnCode interfaces
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
            else
            {
                FAPI_INF("rcTest1. Success!");
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
    l_rc.setFapiError(FAPI_RC_INVALID_ATTR_GET);

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
        l_rc.setPlatError(NULL);

        // Ensure that the creator is PLAT
        l_creator = l_rc.getCreator();

        if (l_creator != ReturnCode::CREATOR_PLAT)
        {
            FAPI_ERR("rcTest2. Creator is 0x%x, expected PLAT", l_creator);
            l_result = 2;
        }
        else
        {
            // Set the return code to a HWP code (intentionally use function
            // that does not add error information).
            l_rc._setHwpError(RC_TEST_ERROR_A);

            // Ensure that the creator is HWP
            l_creator = l_rc.getCreator();

            if (l_creator != ReturnCode::CREATOR_HWP)
            {
                FAPI_ERR("rcTest2. Creator is 0x%x, expected HWP", l_creator);
                l_result = 3;
            }
            else
            {
                FAPI_INF("rcTest2. Success!");
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
    ReturnCode l_rc(FAPI_RC_INVALID_ATTR_GET);

    // Ensure that the embedded return code is as expected
    uint32_t l_codeCheck = l_rc;

    if (l_codeCheck != FAPI_RC_INVALID_ATTR_GET)
    {
        FAPI_ERR("rcTest3. Code is 0x%x, expected FAPI_RC_INVALID_ATTR_GET",
                 l_codeCheck);
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
            else
            {
                FAPI_INF("rcTest3. Success!");
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
    ReturnCode l_rc(FAPI_RC_INVALID_ATTR_GET);
    ReturnCode l_rc2(FAPI_RC_INVALID_ATTR_GET);

    // Ensure that the equality comparison returns true
    if (!(l_rc == l_rc2))
    {
        FAPI_ERR("rcTest4. 1. Equality comparison false");
        l_result = 1;
    }
    else
    {
        // Ensure that the inequality comparison returns false
        if (l_rc != l_rc2)
        {
            FAPI_ERR("rcTest4. 2. Inequality comparison true");
            l_result = 2;
        }
        else
        {
            // Change the code of l_rc2
            l_rc2.setFapiError(FAPI_RC_PLAT_ERR_SEE_DATA);

            // Ensure that the equality comparison returns false
            if (l_rc == l_rc2)
            {
                FAPI_ERR("rcTest4. 3. Equality comparison true");
                l_result = 3;
            }
            else
            {
                // Ensure that the inequality comparison returns true
                if (!(l_rc != l_rc2))
                {
                    FAPI_ERR("rcTest4. 4. Inequality comparison false");
                    l_result = 4;
                }
                else
                {
                    FAPI_INF("rcTest4. Success!");
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
    ReturnCode l_rc(FAPI_RC_INVALID_ATTR_GET);

    // Ensure that the equality comparison returns true when comparing to the
    // same return code value
    if (!(l_rc == FAPI_RC_INVALID_ATTR_GET))
    {
        FAPI_ERR("rcTest5. 1. Equality comparison false");
        l_result = 1;
    }
    else
    {
        // Ensure that the inequality comparison returns false when comparing to
        // the same return code value
        if (l_rc != FAPI_RC_INVALID_ATTR_GET)
        {
            FAPI_ERR("rcTest5. 2. Inequality comparison true");
            l_result = 2;
        }
        else
        {
            // Ensure that the equality comparison returns false when comparing
            // to a different return code value
            if (l_rc == FAPI_RC_PLAT_ERR_SEE_DATA)
            {
                FAPI_ERR("rcTest5. 3. Equality comparison true");
                l_result = 3;
            }
            else
            {
                // Ensure that the inequality comparison returns true when
                // comparing to a different return code value
                if (!(l_rc != FAPI_RC_PLAT_ERR_SEE_DATA))
                {
                    FAPI_ERR("rcTest5. 4. Inequality comparison false");
                    l_result = 4;
                }
                else
                {
                    FAPI_INF("rcTest5. Success!");
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
    ReturnCode l_rc(FAPI_RC_INVALID_ATTR_GET);

    // Ensure that the getPlatData function returns NULL
    void * l_pData = reinterpret_cast<void *> (0x12345678);

    l_pData = l_rc.getPlatData();

    if (l_pData != NULL)
    {
        FAPI_ERR("rcTest6. getPlatData did not return NULL");
        l_result = 1;
    }
    else
    {
        // Ensure that the releasePlatData function returns NULL
        l_pData = reinterpret_cast<void *> (0x12345678);

        l_pData = l_rc.releasePlatData();

        if (l_pData != NULL)
        {
            FAPI_ERR("rcTest6. releasePlatData did not return NULL");
            l_result = 2;
        }
        else
        {
            FAPI_INF("rcTest6. Success!");
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
    ReturnCode l_rc;

    // Assign PlatData. Note that this should really be an errlHndl_t, because
    // the FSP deleteData function will attempt to delete an error log, but this
    // is just for test, the data will be released before the ReturnCode is
    // destructed.
    uint32_t l_myData = 6;
    void * l_pMyData = reinterpret_cast<void *> (&l_myData);
    (void) l_rc.setPlatError(l_pMyData);

    // Ensure that getPlatData retrieves the PlatData
    void * l_pMyDataCheck = l_rc.getPlatData();

    if (l_pMyDataCheck != l_pMyData)
    {
        FAPI_ERR("rcTest7. 1. getPlatData returned unexpected data ptr");
        l_result = 1;
    }
    else
    {
        // Ensure that getPlatData retrieves the PlatData again
        l_pMyDataCheck = NULL;
        l_pMyDataCheck = l_rc.getPlatData();

        if (l_pMyDataCheck != l_pMyData)
        {
            FAPI_ERR("rcTest7. 2. getPlatData returned unexpected data ptr");
            l_result = 2;
        }
        else
        {
            FAPI_INF("rcTest7. Success!");
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
    ReturnCode l_rc;

    // Assign PlatData. Note that this should really be an errlHndl_t, because
    // the FSP deleteData function will attempt to delete an error log, but this
    // is just for test, the data will be released before the ReturnCode is
    // destructed.
    uint32_t l_myData = 6;
    void * l_pMyData = reinterpret_cast<void *> (&l_myData);
    (void) l_rc.setPlatError(l_pMyData);

    // Ensure that releasePlatData retrieves the PlatData
    void * l_pMyDataCheck = l_rc.releasePlatData();

    if (l_pMyDataCheck != l_pMyData)
    {
        FAPI_ERR("rcTest8. getPlatData returned unexpected data ptr");
        l_result = 1;
    }
    else
    {
        // Ensure that releasePlatData now returns NULL
        l_pMyDataCheck = NULL;
        l_pMyDataCheck = l_rc.releasePlatData();

        if (l_pMyDataCheck != NULL)
        {
            FAPI_ERR("rcTest8. 2. getPlatData returned non NULL ptr");
            l_result = 2;
        }
        else
        {
            FAPI_INF("rcTest8. Success!");
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
    ReturnCode l_rc;

    // Assign PlatData. Note that this should really be an errlHndl_t, because
    // the FSP deleteData function will attempt to delete an error log, but this
    // is just for test, the data will be released before the ReturnCode is
    // destructed.
    uint32_t l_myData = 6;
    void * l_pMyData = reinterpret_cast<void *> (&l_myData);
    (void) l_rc.setPlatError(l_pMyData);

    // Create a ReturnCode using the copy constructor
    ReturnCode l_rc2(l_rc);

    // Ensure that the two ReturnCodes are the same
    if (l_rc != l_rc2)
    {
        FAPI_ERR("rcTest9. ReturnCodes differ");
        l_result = 1;
    }
    else
    {
        // Ensure that getPlatData retrieves the PlatData from l_rc
        void * l_pMyDataCheck = l_rc.getPlatData();

        if (l_pMyDataCheck != l_pMyData)
        {
            FAPI_ERR("rcTest9. 1. getPlatData returned unexpected data ptr");
            l_result = 2;
        }
        else
        {
            // Ensure that getPlatData retrieves the PlatData from l_rc2
            l_pMyDataCheck = NULL;
            l_pMyDataCheck = l_rc2.getPlatData();

            if (l_pMyDataCheck != l_pMyData)
            {
                FAPI_ERR("rcTest9. 2. getPlatData returned unexpected data ptr");
                l_result = 3;
            }
            else
            {
                FAPI_INF("rcTest9. Success!");
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
    ReturnCode l_rc;

    // Assign PlatData. Note that this should really be an errlHndl_t, because
    // the PLAT deleteData function will attempt to delete an error log, but
    // this is just for test, the data will be released before the ReturnCode is
    // destructed.
    uint32_t l_myData = 6;
    void * l_pMyData = reinterpret_cast<void *> (&l_myData);
    (void) l_rc.setPlatError(l_pMyData);

    // Create a ReturnCode using the assignment operator
    ReturnCode l_rc2;
    l_rc2 = l_rc;

    // Ensure that the two ReturnCodes are the same
    if (l_rc != l_rc2)
    {
        FAPI_ERR("rcTest10. ReturnCodes differ");
        l_result = 1;
    }
    else
    {
        // Ensure that releasePlatData retrieves the PlatData from l_rc
        void * l_pMyDataCheck = l_rc.releasePlatData();

        if (l_pMyDataCheck != l_pMyData)
        {
            FAPI_ERR("rcTest10. releasePlatData returned unexpected data ptr");
            l_result = 2;
        }
        else
        {
            // Ensure that releasePlatData retrieves NULL from l_rc2
            l_pMyDataCheck = NULL;
            l_pMyDataCheck = l_rc2.releasePlatData();

            if (l_pMyDataCheck != NULL)
            {
                FAPI_ERR("rcTest10. releasePlatData returned non NULL ptr");
                l_result = 3;
            }
            else
            {
                FAPI_INF("rcTest10. Success!");
            }
        }
    }

    return l_result;
}

//******************************************************************************
// rcTest11. Ensures that the getErrorInfo function works when there is no
//           ErrorInfo
//******************************************************************************
uint32_t rcTest11()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;

    // Ensure that the getErrorInfo function returns NULL
    const ErrorInfo * l_pErrInfo =
        reinterpret_cast<const ErrorInfo *> (0x12345678);

    l_pErrInfo = l_rc.getErrorInfo();

    if (l_pErrInfo != NULL)
    {
        FAPI_ERR("rcTest11. getErrorInfo did not return NULL");
        l_result = 1;
    }
    else
    {
        FAPI_INF("rcTest11. Success!");
    }

    return l_result;
}

//******************************************************************************
// rcTest12. Ensures that the getErrorInfo function works when there is
//           ErrorInfo
//******************************************************************************
uint32_t rcTest12()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;
    l_rc.setFapiError(FAPI_RC_INVALID_ATTR_GET);

    // Create a DIMM target
    uint32_t l_targetHandle = 3;
    Target l_target(TARGET_TYPE_DIMM, &l_targetHandle);
    
    // Create some FFDC
    uint8_t l_ffdc = 0x12;

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_ffdc, &l_target};
    fapi::ReturnCode::ErrorInfoEntry l_entries[] =
        {{fapi::ReturnCode::EI_TYPE_FFDC, 0,
          fapi::ReturnCodeFfdc::getErrorInfoFfdcSize(l_ffdc)},
         {fapi::ReturnCode::EI_TYPE_CALLOUT, 1, fapi::PRI_MEDIUM},
         {fapi::ReturnCode::EI_TYPE_DECONF, 1},
         {fapi::ReturnCode::EI_TYPE_GARD, 1}};
    l_rc.addErrorInfo(l_objects, l_entries, 4);

    do
    {
        // Check that the Error Info can be retrieved
        const ErrorInfo * l_pErrInfo = NULL;
        l_pErrInfo = l_rc.getErrorInfo();

        if (l_pErrInfo == NULL)
        {
            FAPI_ERR("rcTest12. getErrorInfo returned NULL");
            l_result = 1;
            break;
        }

        // Check the FFDC error information
        if (l_pErrInfo->iv_ffdcs.size() != 1)
        {
            FAPI_ERR("rcTest12. %d FFDCs", l_pErrInfo->iv_ffdcs.size());
            l_result = 2;
            break;
        }

        uint32_t l_size = 0;
        const void * l_pFfdc = NULL;

        l_pFfdc = l_pErrInfo->iv_ffdcs[0]->getData(l_size);

        if (l_size != sizeof(l_ffdc))
        {
            FAPI_ERR("rcTest12. FFDC size is %d", l_size);
            l_result = 3;
            break;
        }

        const uint8_t * l_pFfdcCheck = static_cast<const uint8_t *>(l_pFfdc);
        if (*l_pFfdcCheck != 0x12)
        {
            FAPI_ERR("rcTest12. FFDC is 0x%x", *l_pFfdcCheck);
            l_result = 4;
            break;
        }

        // Check the callout error information
        if (l_pErrInfo->iv_callouts.size() != 1)
        {
            FAPI_ERR("rcTest12. %d callouts", l_pErrInfo->iv_ffdcs.size());
            l_result = 5;
            break;
        }

        if (l_pErrInfo->iv_callouts[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest12. callout target mismatch");
            l_result = 6;
            break;
        }

        if (l_pErrInfo->iv_callouts[0]->iv_priority != PRI_MEDIUM)
        {
            FAPI_ERR("rcTest12. callout priority mismatch");
            l_result = 7;
            break;
        }

        // Check the deconfig error information
        if (l_pErrInfo->iv_deconfigs.size() != 1)
        {
            FAPI_ERR("rcTest12. %d deconfigs", l_pErrInfo->iv_deconfigs.size());
            l_result = 8;
            break;
        }

        if (l_pErrInfo->iv_deconfigs[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest12. deconfig target mismatch");
            l_result = 9;
            break;
        }

        // Check the GARD error information
        if (l_pErrInfo->iv_gards.size() != 1)
        {
            FAPI_ERR("rcTest12. %d gards", l_pErrInfo->iv_gards.size());
            l_result = 10;
            break;
        }

        if (l_pErrInfo->iv_gards[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest12. gard target mismatch");
            l_result = 11;
            break;
        }

        FAPI_INF("rcTest12. Success!");
    }
    while(0);

    return l_result;
}

//******************************************************************************
// rcTest13. Ensures that the copy constructor works when there is ErrorInfo
//******************************************************************************
uint32_t rcTest13()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;
    l_rc.setFapiError(FAPI_RC_INVALID_ATTR_GET);

    // Create a DIMM target
    uint32_t l_targetHandle = 3;
    Target l_target(TARGET_TYPE_DIMM, &l_targetHandle);

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_target};
    fapi::ReturnCode::ErrorInfoEntry l_entries[] =
        {{fapi::ReturnCode::EI_TYPE_GARD, 0}};
    l_rc.addErrorInfo(l_objects, l_entries, 1);

    // Create a ReturnCode using the copy constructor
    ReturnCode l_rc2(l_rc);

    do
    {
        // Ensure that the two ReturnCodes are the same
        if (l_rc != l_rc2)
        {
            FAPI_ERR("rcTest13. ReturnCodes differ");
            l_result = 1;
            break;
        }

        // Ensure that getErrorInfo returns correct information from l_rc
        const ErrorInfo * l_pErrInfo = NULL;

        l_pErrInfo = l_rc.getErrorInfo();

        if (l_pErrInfo == NULL)
        {
            FAPI_ERR("rcTest13. getErrorInfo returned NULL");
            l_result = 2;
            break;
        }
       
        if (l_pErrInfo->iv_gards.size() != 1)
        {
            FAPI_ERR("rcTest13. %d gards", l_pErrInfo->iv_gards.size());
            l_result = 3;
            break;
        }

        if (l_pErrInfo->iv_gards[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest13. gard target mismatch");
            l_result = 4;
            break;
        }

        // Ensure that getErrorInfo from l_rc2 returns the same pointer
        const ErrorInfo * l_pErrInfo2 = l_rc2.getErrorInfo();

        if (l_pErrInfo != l_pErrInfo2)
        {
            FAPI_ERR("rcTest13. error info mismatch");
            l_result = 5;
            break;
        }

        FAPI_INF("rcTest13. Success!");
    }
    while(0);

    return l_result;
}

//******************************************************************************
// rcTest14. Ensures that the assignment operator works when there ErrorInfo
//******************************************************************************
uint32_t rcTest14()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;
    l_rc.setFapiError(FAPI_RC_INVALID_ATTR_GET);

    // Create a DIMM target
    uint32_t l_targetHandle = 3;
    Target l_target(TARGET_TYPE_DIMM, &l_targetHandle);

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_target};
    fapi::ReturnCode::ErrorInfoEntry l_entries[] =
        {{fapi::ReturnCode::EI_TYPE_GARD, 0}};
    l_rc.addErrorInfo(l_objects, l_entries, 1);

    // Create a ReturnCode using the assignment operator
    ReturnCode l_rc2;
    l_rc2 = l_rc;

    do
    {
        // Ensure that the two ReturnCodes are the same
        if (l_rc != l_rc2)
        {
            FAPI_ERR("rcTest14. ReturnCodes differ");
            l_result = 1;
            break;
        }

        // Ensure that getErrorInfo returns correct information from l_rc
        const ErrorInfo * l_pErrInfo = NULL;

        l_pErrInfo = l_rc.getErrorInfo();

        if (l_pErrInfo == NULL)
        {
            FAPI_ERR("rcTest14. getErrorInfo returned NULL");
            l_result = 2;
            break;
        }

        if (l_pErrInfo->iv_gards.size() != 1)
        {
            FAPI_ERR("rcTest14. %d gards", l_pErrInfo->iv_gards.size());
            l_result = 3;
            break;
        }

        if (l_pErrInfo->iv_gards[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest14. gard target mismatch");
            l_result = 4;
            break;
        }

        // Ensure that getErrorInfo from l_rc2 returns the same pointer
        const ErrorInfo * l_pErrInfo2 = l_rc2.getErrorInfo();

        if (l_pErrInfo != l_pErrInfo2)
        {
            FAPI_ERR("rcTest14. error info mismatch");
            l_result = 5;
            break;
        }

        FAPI_INF("rcTest14. Success!");
    }
    while(0);

    return l_result;
}

//******************************************************************************
// rcTest15. Ensures that setting the ReturnCode to success clears ErrorInfo
//******************************************************************************
uint32_t rcTest15()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;
    l_rc.setFapiError(FAPI_RC_INVALID_ATTR_GET);

    // Create a DIMM target
    uint32_t l_targetHandle = 3;
    Target l_target(TARGET_TYPE_DIMM, &l_targetHandle);

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_target};
    fapi::ReturnCode::ErrorInfoEntry l_entries[] =
        {{fapi::ReturnCode::EI_TYPE_GARD, 0}};
    l_rc.addErrorInfo(l_objects, l_entries, 1);

    // Set the ReturnCode to success
    l_rc = FAPI_RC_SUCCESS;

    // Check that there is no ErrorInfo
    const ErrorInfo * l_pErrInfo = NULL;

    l_pErrInfo = l_rc.getErrorInfo();

    if (l_pErrInfo != NULL)
    {
        FAPI_ERR("rcTest15. getErrorInfo returned NULL");
        l_result = 1;
    }
    else
    {
        FAPI_INF("rcTest15. Success!");
    }

    return l_result;
}

//******************************************************************************
// rcTest16. Ensures that multiple Error Info of each type can be added
//******************************************************************************
uint32_t rcTest16()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;
    l_rc.setFapiError(FAPI_RC_INVALID_ATTR_GET);

    // Create 2 targets
    uint32_t l_targetHandle = 3;
    Target l_target(TARGET_TYPE_DIMM, &l_targetHandle);

    uint32_t l_targetHandle2 = 4;
    Target l_target2(TARGET_TYPE_MCS_CHIPLET, &l_targetHandle2);

    // Create 2 FFDCs
    uint8_t l_ffdc = 0x12;
    uint32_t l_ffdc2 = 0x12345678;

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_ffdc, &l_ffdc2, &l_target, &l_target2};
    fapi::ReturnCode::ErrorInfoEntry l_entries[] =
        {{fapi::ReturnCode::EI_TYPE_FFDC, 0,
          fapi::ReturnCodeFfdc::getErrorInfoFfdcSize(l_ffdc)},
         {fapi::ReturnCode::EI_TYPE_FFDC, 1,
          fapi::ReturnCodeFfdc::getErrorInfoFfdcSize(l_ffdc2)},
         {fapi::ReturnCode::EI_TYPE_CALLOUT, 2, fapi::PRI_HIGH},
         {fapi::ReturnCode::EI_TYPE_CALLOUT, 3, fapi::PRI_LOW},
         {fapi::ReturnCode::EI_TYPE_DECONF, 2},
         {fapi::ReturnCode::EI_TYPE_DECONF, 3},
         {fapi::ReturnCode::EI_TYPE_GARD, 2},
         {fapi::ReturnCode::EI_TYPE_GARD, 3}};
    l_rc.addErrorInfo(l_objects, l_entries, 8);

    do
    {
        // Check that the Error Info can be retrieved
        const ErrorInfo * l_pErrInfo = NULL;
        l_pErrInfo = l_rc.getErrorInfo();

        if (l_pErrInfo == NULL)
        {
            FAPI_ERR("rcTest16. getErrorInfo returned NULL");
            l_result = 1;
            break;
        }

        // Check the FFDC error information
        if (l_pErrInfo->iv_ffdcs.size() != 2)
        {
            FAPI_ERR("rcTest16. %d FFDCs", l_pErrInfo->iv_ffdcs.size());
            l_result = 2;
            break;
        }

        uint32_t l_size = 0;
        const void * l_pFfdc = NULL;

        l_pFfdc = l_pErrInfo->iv_ffdcs[0]->getData(l_size);

        if (l_size != sizeof(l_ffdc))
        {
            FAPI_ERR("rcTest16. FFDC[0] size is %d", l_size);
            l_result = 3;
            break;
        }

        const uint8_t * l_pFfdcCheck = static_cast<const uint8_t *>(l_pFfdc);
        if (*l_pFfdcCheck != 0x12)
        {
            FAPI_ERR("rcTest16. FFDC[0] is 0x%x", *l_pFfdcCheck);
            l_result = 4;
            break;
        }

        l_pFfdc = l_pErrInfo->iv_ffdcs[1]->getData(l_size);

        if (l_size != sizeof(l_ffdc2))
        {
            FAPI_ERR("rcTest16. FFDC[1] size is %d", l_size);
            l_result = 5;
            break;
        }

        const uint32_t * l_pFfdc2Check = static_cast<const uint32_t *>(l_pFfdc);
        if (*l_pFfdc2Check != 0x12345678)
        {
            FAPI_ERR("rcTest16. FFDC[1] is 0x%x", *l_pFfdc2Check);
            l_result = 6;
            break;
        }

        // Check the callout error information
        if (l_pErrInfo->iv_callouts.size() != 2)
        {
            FAPI_ERR("rcTest16. %d callouts", l_pErrInfo->iv_ffdcs.size());
            l_result = 7;
            break;
        }

        if (l_pErrInfo->iv_callouts[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest16. callout[0] target mismatch");
            l_result = 8;
            break;
        }

        if (l_pErrInfo->iv_callouts[0]->iv_priority != PRI_HIGH)
        {
            FAPI_ERR("rcTest16. callout[0] priority mismatch");
            l_result = 9;
            break;
        }

        if (l_pErrInfo->iv_callouts[1]->iv_target != l_target2)
        {
            FAPI_ERR("rcTest16. callout[1] target mismatch");
            l_result = 10;
            break;
        }

        if (l_pErrInfo->iv_callouts[1]->iv_priority != PRI_LOW)
        {
            FAPI_ERR("rcTest16. callout[1] priority mismatch");
            l_result = 11;
            break;
        }

        // Check the deconfig error information
        if (l_pErrInfo->iv_deconfigs.size() != 2)
        {
            FAPI_ERR("rcTest16. %d deconfigs", l_pErrInfo->iv_deconfigs.size());
            l_result = 12;
            break;
        }

        if (l_pErrInfo->iv_deconfigs[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest16. deconfig[0] target mismatch");
            l_result = 13;
            break;
        }

        if (l_pErrInfo->iv_deconfigs[1]->iv_target != l_target2)
        {
            FAPI_ERR("rcTest16. deconfig[1] target mismatch");
            l_result = 13;
            break;
        }

        // Check the GARD error information
        if (l_pErrInfo->iv_gards.size() != 2)
        {
            FAPI_ERR("rcTest16. %d gards", l_pErrInfo->iv_gards.size());
            l_result = 14;
            break;
        }

        if (l_pErrInfo->iv_gards[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest16. gard[0] target mismatch");
            l_result = 15;
            break;
        }

        if (l_pErrInfo->iv_gards[1]->iv_target != l_target2)
        {
            FAPI_ERR("rcTest16. gard[1] target mismatch");
            l_result = 16;
            break;
        }

        FAPI_INF("rcTest16. Success!");
    }
    while(0);

    return l_result;
}

//******************************************************************************
// rcTest17. Ensures that static_cast can be applied to a ReturnCode
//******************************************************************************
uint32_t rcTest17()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc(FAPI_RC_INVALID_ATTR_GET);

    uint32_t l_check = static_cast<uint32_t>(l_rc);

    if (l_check != FAPI_RC_INVALID_ATTR_GET)
    {
        FAPI_ERR("rcTest17. RC is not FAPI_RC_INVALID_ATTR_GET, it is 0x%x",
        l_check);
        l_result = 1;
    }
    else
    {
        FAPI_INF("rcTest17. Success!");
    }

    return l_result;
}

}
