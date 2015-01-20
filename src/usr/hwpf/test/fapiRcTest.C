/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/fapiRcTest.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
// $Id: fapiRcTest.C,v 1.16 2015/03/18 19:41:51 pragupta Exp $
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
 *                          mjjones     08/14/2012  Use new ErrorInfo structures
 *                          mjjones     03/28/2013  Added proc-callout tests
 *                          mjjones     03/28/2013  Added children-cdg tests
 *                          sangeet2    29/01/2015  Added testcase rcTest18
 */

#include <fapi.H>
#include <fapiPlatHwpInvoker.H>
#ifdef fips
#include <srcisrc.H>
#endif

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
    l_rc.setPlatError(NULL, FAPI_RC_PLAT_ERR_SEE_DATA);

    // Create fake targets
    uint32_t l_targetHandle = 3;
    Target l_target(TARGET_TYPE_DIMM, &l_targetHandle);
    uint32_t l_target2Handle = 4;
    Target l_target2(TARGET_TYPE_PROC_CHIP, &l_target2Handle);
    
    // Create some FFDC
    uint8_t l_ffdc = 0x12;

    // Add error information to the ReturnCode, the data is the same as that
    // produced by the fapiParseErrorInfo.pl script in fapiHwpErrorInfo.H
    const void * l_objects[] = {&l_ffdc, &l_target, &l_target2};
    fapi::ReturnCode::ErrorInfoEntry l_entries[7];
    l_entries[0].iv_type = fapi::ReturnCode::EI_TYPE_FFDC;
    l_entries[0].ffdc.iv_ffdcObjIndex = 0;
    l_entries[0].ffdc.iv_ffdcId = 0x22334455;
    l_entries[0].ffdc.iv_ffdcSize =
        fapi::ReturnCodeFfdc::getErrorInfoFfdcSize(l_ffdc);
    l_entries[1].iv_type = fapi::ReturnCode::EI_TYPE_PROCEDURE_CALLOUT;
    l_entries[1].proc_callout.iv_procedure = fapi::ProcedureCallouts::CODE;
    l_entries[1].proc_callout.iv_calloutPriority =
        fapi::CalloutPriorities::MEDIUM;
    l_entries[2].iv_type = fapi::ReturnCode::EI_TYPE_BUS_CALLOUT;
    l_entries[2].bus_callout.iv_endpoint1ObjIndex = 1;
    l_entries[2].bus_callout.iv_endpoint2ObjIndex = 2;
    l_entries[2].bus_callout.iv_calloutPriority =
        fapi::CalloutPriorities::MEDIUM;
    l_entries[3].iv_type = fapi::ReturnCode::EI_TYPE_CDG;
    l_entries[3].target_cdg.iv_targetObjIndex = 1;
    l_entries[3].target_cdg.iv_callout = 1;
    l_entries[3].target_cdg.iv_deconfigure = 1;
    l_entries[3].target_cdg.iv_gard = 0;
    l_entries[3].target_cdg.iv_calloutPriority = fapi::CalloutPriorities::HIGH;
    l_entries[4].iv_type = fapi::ReturnCode::EI_TYPE_CHILDREN_CDG;
    l_entries[4].children_cdg.iv_parentObjIndex = 1;
    l_entries[4].children_cdg.iv_callout = 0;
    l_entries[4].children_cdg.iv_deconfigure = 1;
    l_entries[4].children_cdg.iv_childType = fapi::TARGET_TYPE_ABUS_ENDPOINT;
    l_entries[4].children_cdg.iv_gard = 0;
    l_entries[4].children_cdg.iv_calloutPriority =
        fapi::CalloutPriorities::HIGH;
    l_entries[5].iv_type = fapi::ReturnCode::EI_TYPE_HW_CALLOUT;
    l_entries[5].hw_callout.iv_hw = fapi::HwCallouts::MEM_REF_CLOCK;
    l_entries[5].hw_callout.iv_calloutPriority = fapi::CalloutPriorities::LOW;
    l_entries[5].hw_callout.iv_refObjIndex = 0xff;
    l_entries[5].hw_callout.iv_objPosIndex = 0;
    l_entries[6].iv_type = fapi::ReturnCode::EI_TYPE_HW_CALLOUT;
    l_entries[6].hw_callout.iv_hw = fapi::HwCallouts::FLASH_CONTROLLER_PART;
    l_entries[6].hw_callout.iv_calloutPriority = fapi::CalloutPriorities::LOW;
    l_entries[6].hw_callout.iv_refObjIndex = 0xff;
    l_entries[6].hw_callout.iv_objPosIndex = 0;

    l_rc.addErrorInfo(l_objects, l_entries, 7);

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

        // Check the callout/deconfigure/gard error information
        if (l_pErrInfo->iv_CDGs.size() != 1)
        {
            FAPI_ERR("rcTest12. %d CDGs", l_pErrInfo->iv_CDGs.size());
            l_result = 5;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest12. CDG target mismatch");
            l_result = 6;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_callout != true)
        {
            FAPI_ERR("rcTest12. callout not set");
            l_result = 7;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_calloutPriority !=
            CalloutPriorities::HIGH)
        {
            FAPI_ERR("rcTest12. CDG callout priority mismatch (%d)",
                     l_pErrInfo->iv_CDGs[0]->iv_calloutPriority);
            l_result = 8;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_deconfigure != true)
        {
            FAPI_ERR("rcTest12. deconfigure not set");
            l_result = 9;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_gard != false)
        {
            FAPI_ERR("rcTest12. GARD set");
            l_result = 10;
            break;
        }

        // Additional procedure called out due to Bus Callout
        if (l_pErrInfo->iv_procedureCallouts.size() != 2)
        {
            FAPI_ERR("rcTest12. %d proc-callouts",
                     l_pErrInfo->iv_procedureCallouts.size());
            l_result = 11;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[0]->iv_procedure !=
            ProcedureCallouts::CODE)
        {
            FAPI_ERR("rcTest12. procedure callout[0] mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[0]->iv_procedure);
            l_result = 12;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[0]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTest12. procedure callout[0] priority mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[0]->iv_calloutPriority);
            l_result = 13;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[1]->iv_procedure !=
            ProcedureCallouts::BUS_CALLOUT)
        {
            FAPI_ERR("rcTest12. procedure callout[1] mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[1]->iv_procedure);
            l_result = 14;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[1]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTest12. procedure callout[1] priority mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[1]->iv_calloutPriority);
            l_result = 15;
            break;
        }

        if (l_pErrInfo->iv_busCallouts.size() != 1)
        {
            FAPI_ERR("rcTest12. %d bus-callouts",
                     l_pErrInfo->iv_busCallouts.size());
            l_result = 16;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_target1 != l_target)
        {
            FAPI_ERR("rcTest12. bus target mismatch 1");
            l_result = 17;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_target2 != l_target2)
        {
            FAPI_ERR("rcTest12. bus target mismatch 2");
            l_result = 18;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_calloutPriority !=
            CalloutPriorities::LOW)
        {
            FAPI_ERR("rcTest12. bus callout priority mismatch (%d)",
                     l_pErrInfo->iv_busCallouts[0]->iv_calloutPriority);
            l_result = 19;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs.size() != 1)
        {
            FAPI_ERR("rcTest12. %d children-cdgs",
                     l_pErrInfo->iv_childrenCDGs.size());
            l_result = 20;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_parent != l_target)
        {
            FAPI_ERR("rcTest12. parent chip mismatch");
            l_result = 21;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_childType !=
            fapi::TARGET_TYPE_ABUS_ENDPOINT)
        {
            FAPI_ERR("rcTest12. child type mismatch (0x%08x)",
                     l_pErrInfo->iv_childrenCDGs[0]->iv_childType);
            l_result = 22;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_calloutPriority !=
            CalloutPriorities::HIGH)
        {
            FAPI_ERR("rcTest12. child cdg priority mismatch (%d)",
                     l_pErrInfo->iv_childrenCDGs[0]->iv_calloutPriority);
            l_result = 23;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_callout != false)
        {
            FAPI_ERR("rcTest12. child cdg callout set");
            l_result = 24;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_deconfigure != true)
        {
            FAPI_ERR("rcTest12. child cdg deconfigure not set");
            l_result = 25;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_gard != false)
        {
            FAPI_ERR("rcTest12. child cdg GARD set");
            l_result = 26;
            break;
        }

        if (l_pErrInfo->iv_hwCallouts.size() != 2)
        {
            FAPI_ERR("rcTest12. %d hw-callouts",
                     l_pErrInfo->iv_hwCallouts.size());
            l_result = 27;
            break;
        }

        if (l_pErrInfo->iv_hwCallouts[0]->iv_hw !=
            HwCallouts::MEM_REF_CLOCK)
        {
            FAPI_ERR("rcTest12. hw callout mismatch (%d)",
                     l_pErrInfo->iv_hwCallouts[0]->iv_hw);
            l_result = 28;
            break;
        }

        if (l_pErrInfo->iv_hwCallouts[0]->iv_calloutPriority !=
            CalloutPriorities::LOW)
        {
            FAPI_ERR("rcTest12. hw callout priority mismatch (%d)",
                     l_pErrInfo->iv_hwCallouts[0]->iv_calloutPriority);
            l_result = 29;
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
    l_rc.setPlatError(NULL, FAPI_RC_PLAT_ERR_SEE_DATA);

    // Create a DIMM target
    uint32_t l_targetHandle = 3;
    Target l_target(TARGET_TYPE_DIMM, &l_targetHandle);

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_target};
    fapi::ReturnCode::ErrorInfoEntry l_entries[1];
    l_entries[0].iv_type = fapi::ReturnCode::EI_TYPE_CDG;
    l_entries[0].target_cdg.iv_targetObjIndex = 0;
    l_entries[0].target_cdg.iv_callout = 0;
    l_entries[0].target_cdg.iv_deconfigure = 0;
    l_entries[0].target_cdg.iv_gard = 1;
    l_entries[0].target_cdg.iv_calloutPriority = fapi::CalloutPriorities::LOW;

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
       
        if (l_pErrInfo->iv_CDGs.size() != 1)
        {
            FAPI_ERR("rcTest13. %d CDGs", l_pErrInfo->iv_CDGs.size());
            l_result = 3;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest13. CDG target mismatch");
            l_result = 4;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_gard != true)
        {
            FAPI_ERR("rcTest13. GARD not set");
            l_result = 5;
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
    l_rc.setPlatError(NULL, FAPI_RC_PLAT_ERR_SEE_DATA);

    // Create a DIMM target
    uint32_t l_targetHandle = 3;
    Target l_target(TARGET_TYPE_DIMM, &l_targetHandle);

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_target};
    fapi::ReturnCode::ErrorInfoEntry l_entries[1];
    l_entries[0].iv_type = fapi::ReturnCode::EI_TYPE_CDG;
    l_entries[0].target_cdg.iv_targetObjIndex = 0;
    l_entries[0].target_cdg.iv_callout = 0;
    l_entries[0].target_cdg.iv_deconfigure = 0;
    l_entries[0].target_cdg.iv_gard = 1;
    l_entries[0].target_cdg.iv_calloutPriority = fapi::CalloutPriorities::LOW;

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

        if (l_pErrInfo->iv_CDGs.size() != 1)
        {
            FAPI_ERR("rcTest14. %d CDGs", l_pErrInfo->iv_CDGs.size());
            l_result = 3;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest14. CDG target mismatch");
            l_result = 4;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_gard != true)
        {
            FAPI_ERR("rcTest14. GARD not set");
            l_result = 5;
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
    l_rc.setPlatError(NULL, FAPI_RC_PLAT_ERR_SEE_DATA);

    // Create a DIMM target
    uint32_t l_targetHandle = 3;
    Target l_target(TARGET_TYPE_DIMM, &l_targetHandle);

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_target};
    fapi::ReturnCode::ErrorInfoEntry l_entries[1];
    l_entries[0].iv_type = fapi::ReturnCode::EI_TYPE_CDG;
    l_entries[0].target_cdg.iv_targetObjIndex = 0;
    l_entries[0].target_cdg.iv_callout = 0;
    l_entries[0].target_cdg.iv_deconfigure = 0;
    l_entries[0].target_cdg.iv_gard = 1;
    l_entries[0].target_cdg.iv_calloutPriority = fapi::CalloutPriorities::LOW;

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
    l_rc.setPlatError(NULL, FAPI_RC_PLAT_ERR_SEE_DATA);

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
    fapi::ReturnCode::ErrorInfoEntry l_entries[10];
    l_entries[0].iv_type = fapi::ReturnCode::EI_TYPE_FFDC;
    l_entries[0].ffdc.iv_ffdcObjIndex = 0;
    l_entries[0].ffdc.iv_ffdcId = 0x22334455;
    l_entries[0].ffdc.iv_ffdcSize =
        fapi::ReturnCodeFfdc::getErrorInfoFfdcSize(l_ffdc);
    l_entries[1].iv_type = fapi::ReturnCode::EI_TYPE_FFDC;
    l_entries[1].ffdc.iv_ffdcObjIndex = 1;
    l_entries[1].ffdc.iv_ffdcId = 0x33445566;
    l_entries[1].ffdc.iv_ffdcSize =
        fapi::ReturnCodeFfdc::getErrorInfoFfdcSize(l_ffdc2);
    l_entries[2].iv_type = fapi::ReturnCode::EI_TYPE_CDG;
    l_entries[2].target_cdg.iv_targetObjIndex = 2;
    l_entries[2].target_cdg.iv_callout = 0;
    l_entries[2].target_cdg.iv_deconfigure = 1;
    l_entries[2].target_cdg.iv_gard = 0;
    l_entries[2].target_cdg.iv_calloutPriority = fapi::CalloutPriorities::HIGH;
    l_entries[3].iv_type = fapi::ReturnCode::EI_TYPE_CDG;
    l_entries[3].target_cdg.iv_targetObjIndex = 3;
    l_entries[3].target_cdg.iv_callout = 0;
    l_entries[3].target_cdg.iv_deconfigure = 0;
    l_entries[3].target_cdg.iv_gard = 1;
    l_entries[3].target_cdg.iv_calloutPriority = fapi::CalloutPriorities::MEDIUM;
    l_entries[4].iv_type = fapi::ReturnCode::EI_TYPE_PROCEDURE_CALLOUT;
    l_entries[4].proc_callout.iv_procedure = fapi::ProcedureCallouts::CODE; 
    l_entries[4].proc_callout.iv_calloutPriority = fapi::CalloutPriorities::MEDIUM;
    l_entries[5].iv_type = fapi::ReturnCode::EI_TYPE_PROCEDURE_CALLOUT;
    l_entries[5].proc_callout.iv_procedure = fapi::ProcedureCallouts::LVL_SUPPORT;
    l_entries[5].proc_callout.iv_calloutPriority = fapi::CalloutPriorities::LOW;
    l_entries[6].iv_type = fapi::ReturnCode::EI_TYPE_BUS_CALLOUT;
    l_entries[6].bus_callout.iv_endpoint1ObjIndex = 2;
    l_entries[6].bus_callout.iv_endpoint2ObjIndex = 3;
    l_entries[6].bus_callout.iv_calloutPriority = fapi::CalloutPriorities::LOW;
    l_entries[7].iv_type = fapi::ReturnCode::EI_TYPE_BUS_CALLOUT;
    l_entries[7].bus_callout.iv_endpoint1ObjIndex = 2;
    l_entries[7].bus_callout.iv_endpoint2ObjIndex = 3;
    l_entries[7].bus_callout.iv_calloutPriority = fapi::CalloutPriorities::HIGH;
    l_entries[8].iv_type = fapi::ReturnCode::EI_TYPE_CHILDREN_CDG;
    l_entries[8].children_cdg.iv_parentObjIndex = 2;
    l_entries[8].children_cdg.iv_callout = 1;
    l_entries[8].children_cdg.iv_deconfigure = 1;
    l_entries[8].children_cdg.iv_childType = fapi::TARGET_TYPE_ABUS_ENDPOINT;
    l_entries[8].children_cdg.iv_gard = 0;
    l_entries[8].children_cdg.iv_calloutPriority =
        fapi::CalloutPriorities::HIGH;
    l_entries[9].iv_type = fapi::ReturnCode::EI_TYPE_CHILDREN_CDG;
    l_entries[9].children_cdg.iv_parentObjIndex = 3;
    l_entries[9].children_cdg.iv_callout = 1;
    l_entries[9].children_cdg.iv_deconfigure = 0;
    l_entries[9].children_cdg.iv_childType = fapi::TARGET_TYPE_MBA_CHIPLET;
    l_entries[9].children_cdg.iv_gard = 1;
    l_entries[9].children_cdg.iv_calloutPriority =
        fapi::CalloutPriorities::MEDIUM;

    l_rc.addErrorInfo(l_objects, l_entries, 10);

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

        // Check the callout/deconfigure/GARD error information
        if (l_pErrInfo->iv_CDGs.size() != 2)
        {
            FAPI_ERR("rcTest16. %d CDGs", l_pErrInfo->iv_CDGs.size());
            l_result = 7;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTest16. CDG[0] target mismatch");
            l_result = 8;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_callout != false)
        {
            FAPI_ERR("rcTest16. CDG[0] callout set");
            l_result = 9;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_calloutPriority !=
                CalloutPriorities::HIGH)
        {
            FAPI_ERR("rcTest16. CDG[0] callout priority mismatch");
            l_result = 10;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_deconfigure != true)
        {
            FAPI_ERR("rcTest16. CDG[0] deconfigure not set");
            l_result = 11;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_gard != false)
        {
            FAPI_ERR("rcTest16. CDG[0] gard set");
            l_result = 12;
            break;
        }

        if (l_pErrInfo->iv_CDGs[1]->iv_target != l_target2)
        {
            FAPI_ERR("rcTest16. CDG[1] target mismatch");
            l_result = 13;
            break;
        }

        if (l_pErrInfo->iv_CDGs[1]->iv_callout != false)
        {
            FAPI_ERR("rcTest16. CDG[0] callout set");
            l_result = 14;
            break;
        }

        if (l_pErrInfo->iv_CDGs[1]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTest16. CDG[1] callout priority mismatch");
            l_result = 15;
            break;
        }

        if (l_pErrInfo->iv_CDGs[1]->iv_deconfigure != false)
        {
            FAPI_ERR("rcTest16. CDG[1] deconfigure set");
            l_result = 16;
            break;
        }

        if (l_pErrInfo->iv_CDGs[1]->iv_gard != true)
        {
            FAPI_ERR("rcTest16. CDG[1] gard not set");
            l_result = 17;
            break;
        }

        // Additional procedures called out due to Bus Callout
        if (l_pErrInfo->iv_procedureCallouts.size() != 4)
        {
            FAPI_ERR("rcTest16. %d proc-callouts",
                     l_pErrInfo->iv_procedureCallouts.size());
            l_result = 18;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[0]->iv_procedure !=
            ProcedureCallouts::CODE)
        {
            FAPI_ERR("rcTest16. procedure[0] callout mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[0]->iv_procedure);
            l_result = 19;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[0]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTest16. procedure[0] callout priority mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[0]->iv_calloutPriority);
            l_result = 20;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[1]->iv_procedure !=
            ProcedureCallouts::LVL_SUPPORT)
        {
            FAPI_ERR("rcTest16. procedure[1] callout mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[1]->iv_procedure);
            l_result = 21;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[1]->iv_calloutPriority !=
            CalloutPriorities::LOW)
        {
            FAPI_ERR("rcTest16. procedure[1] callout priority mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[1]->iv_calloutPriority);
            l_result = 22;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[2]->iv_procedure !=
            ProcedureCallouts::BUS_CALLOUT)
        {
            FAPI_ERR("rcTest16. procedure[2] callout mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[2]->iv_procedure);
            l_result = 23;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[2]->iv_calloutPriority !=
            CalloutPriorities::LOW)
        {
            FAPI_ERR("rcTest16. procedure[2] callout priority mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[2]->iv_calloutPriority);
            l_result = 24;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[3]->iv_procedure !=
            ProcedureCallouts::BUS_CALLOUT)
        {
            FAPI_ERR("rcTest16. procedure[3] callout mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[3]->iv_procedure);
            l_result = 25;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[3]->iv_calloutPriority !=
            CalloutPriorities::HIGH)
        {
            FAPI_ERR("rcTest16. procedure[3] callout priority mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[3]->iv_calloutPriority);
            l_result = 26;
            break;
        }

        if (l_pErrInfo->iv_busCallouts.size() != 2)
        {
            FAPI_ERR("rcTest16. %d bus-callouts",
                     l_pErrInfo->iv_busCallouts.size());
            l_result = 27;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_target1 != l_target)
        {
            FAPI_ERR("rcTest16. bus target mismatch 1");
            l_result = 28;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_target2 != l_target2)
        {
            FAPI_ERR("rcTest16. bus target mismatch 2");
            l_result = 29;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_calloutPriority !=
            CalloutPriorities::LOW)
        {
            FAPI_ERR("rcTest16. bus callout priority mismatch 1 (%d)",
                     l_pErrInfo->iv_busCallouts[0]->iv_calloutPriority);
            l_result = 30;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[1]->iv_target1 != l_target)
        {
            FAPI_ERR("rcTest16. bus target mismatch 3");
            l_result = 31;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[1]->iv_target2 != l_target2)
        {
            FAPI_ERR("rcTest16. bus target mismatch 4");
            l_result = 32;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[1]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTest16. bus callout priority mismatch 2 (%d)",
                     l_pErrInfo->iv_busCallouts[1]->iv_calloutPriority);
            l_result = 33;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs.size() != 2)
        {
            FAPI_ERR("rcTest16. %d children-cdgs",
                     l_pErrInfo->iv_childrenCDGs.size());
            l_result = 34;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_parent != l_target)
        {
            FAPI_ERR("rcTest16. parent chip mismatch 1");
            l_result = 35;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_childType !=
            fapi::TARGET_TYPE_ABUS_ENDPOINT)
        {
            FAPI_ERR("rcTest16. child type mismatch 1 (0x%08x)",
                     l_pErrInfo->iv_childrenCDGs[0]->iv_childType);
            l_result = 36;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_calloutPriority !=
            CalloutPriorities::HIGH)
        {
            FAPI_ERR("rcTest16. child cdg priority mismatch 1 (%d)",
                     l_pErrInfo->iv_childrenCDGs[0]->iv_calloutPriority);
            l_result = 37;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_callout != true)
        {
            FAPI_ERR("rcTest16. child cdg callout not set 1");
            l_result = 38;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_deconfigure != true)
        {
            FAPI_ERR("rcTest16. child cdg deconfigure not set 1");
            l_result = 39;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[0]->iv_gard != false)
        {
            FAPI_ERR("rcTest16. child cdg GARD set 1");
            l_result = 40;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[1]->iv_childType !=
            fapi::TARGET_TYPE_MBA_CHIPLET)
        {
            FAPI_ERR("rcTest16. child type mismatch 2 (0x%08x)",
                     l_pErrInfo->iv_childrenCDGs[1]->iv_childType);
            l_result = 41;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[1]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTest16. child cdg priority mismatch 2 (%d)",
                     l_pErrInfo->iv_childrenCDGs[1]->iv_calloutPriority);
            l_result = 42;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[1]->iv_callout != true)
        {
            FAPI_ERR("rcTest16. child cdg callout not set 2");
            l_result = 43;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[1]->iv_deconfigure != false)
        {
            FAPI_ERR("rcTest16. child cdg deconfigure set 2");
            l_result = 44;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs[1]->iv_gard != true)
        {
            FAPI_ERR("rcTest16. child cdg GARD not set 2");
            l_result = 45;
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

#ifdef fips
uint32_t rcTest18()
{
    uint32_t l_result = 0;

    // Create a FAPI  ReturnCode
    ReturnCode l_rc(FAPI_RC_INVALID_ATTR_GET);

    // Create Target of functional processor chip
    TARGETING::Target *l_proc = NULL;

    //  Use PredicateIsFunctional (formerly HwasPredicate) to filter
    //  only functional chips
    TARGETING::PredicateIsFunctional l_isFunctional;
    do
    {

        //  filter for functional Proc Chips
        TARGETING::PredicateCTM l_procChipFilter(TARGETING::CLASS_CHIP,
                TARGETING::TYPE_PROC );

        // declare a postfix expression
        TARGETING::PredicatePostfixExpr l_functionalAndProcChipFilter;

        // is-a-proc-chip is-functional AND
        l_functionalAndProcChipFilter.push(&l_procChipFilter).
            push(&l_isFunctional).And();

        // loop through all the targets, applying the filter,
        // and put the results in l_pFuncProc
        TARGETING::TargetRangeFilter  l_pFuncProcFilter(
                TARGETING::targetService().begin(),
                TARGETING::targetService().end(),
                &l_functionalAndProcChipFilter);

        // Get a pointer to that first function proc
        if(!l_pFuncProcFilter)
        {
            l_result = 1;
            FAPI_ERR("rcTest18:No functional processors found");
            break;
        }

        l_proc = *l_pFuncProcFilter;
        TARGETING::Target* l_pConstTarget =
            const_cast<TARGETING::Target*>(l_proc);

        fapi::Target l_fapiTarget(fapi::TARGET_TYPE_PROC_CHIP,
                     reinterpret_cast<void*>(l_pConstTarget));

        const void * l_objects[] = { &l_fapiTarget};
        fapi::ReturnCode::ErrorInfoEntry l_entries[1];
        l_entries[0].iv_type = fapi::ReturnCode::EI_TYPE_CDG;
        l_entries[0].target_cdg.iv_targetObjIndex = 0;
        l_entries[0].target_cdg.iv_callout = 0;
        l_entries[0].target_cdg.iv_deconfigure = 0;
        l_entries[0].target_cdg.iv_gard = 1;
        l_entries[0].target_cdg.iv_calloutPriority =
            fapi::CalloutPriorities::LOW;


        // Add the error info
        l_rc.addErrorInfo(l_objects, l_entries, 1);

        // Check that the Error Info can be retrieved
        const ErrorInfo * l_pErrInfo = NULL;
        l_pErrInfo = l_rc.getErrorInfo();

        if (l_pErrInfo == NULL)
        {
            FAPI_ERR("rcTest18:getErrorInfo returned NULL");
            l_result = 2;
            break;
        }

        // Check the callout/deconfigure/GARD error information
        if (l_pErrInfo->iv_CDGs[0]->iv_target != l_fapiTarget)
        {
            FAPI_ERR("rcTest18:CDG[0] target mismatch");
            l_result = 3;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_gard == false)
        {
            FAPI_ERR("rcTest18:CDG[0] gard not set");
            l_result = 4;
            break;
        }

        // fapiRcToErrl is implicitly calling processEICDGs
        errlHndl_t pError = fapiRcToErrl(l_rc);
        if(pError == NULL)
        {
            FAPI_ERR("rcTest18:fapiRcToErrl returnd No Errorlog handle");
            l_result = 5;
            break;
        }

        srciIdx_t l_calloutCnt = 0;
        const SrciSrc* pSRC = pError->getSRC();
        pSRC->Callouts(l_calloutCnt);
        if(l_calloutCnt < 1)
        {
            l_result = 6;
            FAPI_ERR("Error. No Callout from  fapiRcToErrl");
            break;
        }

        // TODO RTC 79353
        // Garded Target must be UnGard here.

        FAPI_INF("rcTest18:Deconfig/Gard HWP callout TC success");
        if(pError != NULL)
        {
            delete pError;
            pError = NULL;
        }

    }while(0);
    return l_result;
}
#endif //fips

}
