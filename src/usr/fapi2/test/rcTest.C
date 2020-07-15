/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/rcTest.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
// $Id: rcTest.C,v 1.16 2015/03/18 19:41:51 pragupta Exp $
/**
 *  @file rcTest.C
 *
 *  @brief Implements Target class unit test functions.
 */


#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <error_info.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <rcSupport.H>

fapi2::ReturnCode get_fapi2_error(void)
{
    FAPI_INF("Enter get_fapi2_error...");
    // You can assign directly to the buffer:
    const uint32_t buf[] = {0x01, 0x02, 0x03, 0xDEADBEEF};
    fapi2::variable_buffer other_bits(buf, 4, 128);
    uint32_t val;

    FAPI_TRY( other_bits.extract(val, 0, 130) );

fapi_try_exit:
    FAPI_INF("Exiting get_fapi2_error...");

    // should return FAPI2_RC_INVALID_PARAMETER
    return fapi2::current_err;
}

fapi2::ReturnCode get_plat_error(void)
{
    FAPI_INF("Entering get_plat_error...");

    fapi2::buffer<uint64_t> l_scomdata = 0;

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_chipList;

    // Get a list of all of the proc chips
    TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

    TARGETING::Target * l_Proc = nullptr;

    if (l_chipList.size() > 0)
    {
        l_Proc = l_chipList[0];
    }

    if (l_Proc != nullptr)
    {
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(l_Proc);

        FAPI_INF("Do an invalid address getscom on proc target");
        FAPI_TRY(fapi2::getScom(fapi2_procTarget,
                                0x11223344,
                                l_scomdata));
    }
 fapi_try_exit:

    FAPI_INF("Exiting get_plat_error...");
    return fapi2::current_err;
}


namespace fapi2
{

//******************************************************************************
// rcTestDefaultConstructor. Ensures that the ReturnCode default
// constructor works
//******************************************************************************
uint32_t rcTestDefaultConstructor()
{
    uint32_t l_result = 0;

    // Create ReturnCode using default constructor
    ReturnCode l_rc;

    // Ensure that the embedded return code is success
    if (l_rc != FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("rcTestDefaultConstructor. Code is 0x%x, expected success",
                 static_cast<uint64_t>(l_rc));
        l_result = 1;
    }
    else
    {
        // Ensure that testing l_rc works
        if (l_rc)
        {
            FAPI_ERR("rcTestDefaultConstructor. testing rc returned true");
            l_result = 2;
        }
        else
        {
            FAPI_INF("rcTestDefaultConstructor. Success!");
        }
    }
    return l_result;
}


//******************************************************************************
// rcTestReturnCodeCreator. Ensures that the ReturnCode creator reflects
// the return code
//******************************************************************************

// FIXME RTC:257497
// RC_TEST_ERROR_A required, in p9 comes from src/import/chips/p9/procedures/
// xml/error_info/proc_example_errors.xml
// There's no equivalent file in ekb-p10 yet.
#if 0
uint32_t rcTestReturnCodeCreator()
{
    uint32_t l_result = 0;

    // Create ReturnCode using default constructor
    ReturnCode l_rc;

    // Set the return code to a FAPI code
    l_rc = get_fapi2_error();

    // Ensure that the creator is FAPI
    ReturnCode::returnCodeCreator l_creator = l_rc.getCreator();

    if (l_creator != ReturnCode::CREATOR_FAPI)
    {
        FAPI_ERR("rcTestReturnCodeCreator. Creator is 0x%x, expected FAPI",
                 l_creator);
        l_result = 1;
    }
    else
    {
        // Set the return code to a PLAT code
        l_rc = get_plat_error(); //.setPlatError(nullptr);

        // Ensure that the creator is PLAT
        l_creator = l_rc.getCreator();

        if (l_creator != ReturnCode::CREATOR_PLAT)
        {
            FAPI_ERR("rcTestReturnCodeCreator. Creator is 0x%x, expected PLAT",
                     l_creator);
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
                FAPI_ERR("rcTestReturnCodeCreator. Creator is 0x%x,expected HWP"
                        , l_creator);
                l_result = 3;
            }
            else
            {
                FAPI_INF("rcTestReturnCodeCreator. Success!");
            }
        }
    }

    return l_result;
}
#endif


//******************************************************************************
// rcTestReturnCodeConstructor. Ensures that the ReturnCode constructor works
// when specifying a return code
//******************************************************************************
uint32_t rcTestReturnCodeConstructor()
{
    uint32_t l_result = 0;

    // Create ReturnCode specifying a return code
    ReturnCode l_rc(FAPI2_RC_INVALID_ATTR_GET);

    // Ensure that the embedded return code is as expected
    uint64_t l_codeCheck = l_rc;

    if (l_codeCheck != FAPI2_RC_INVALID_ATTR_GET)
    {
        FAPI_ERR("rcTestReturnCodeConstructor. Code is 0x%x,"
                " expected FAPI2_RC_INVALID_ATTR_GET",l_codeCheck);
        l_result = 1;
    }
    else
    {
        // Ensure that testing l_rc works
        if (!l_rc)
        {
            FAPI_ERR("rcTestReturnCodeConstructor. testing rc returned false");
            l_result = 2;
        }
        else
        {
            FAPI_INF("rcTestReturnCodeConstructor. Success!");
        }
    }

    return l_result;
}

//******************************************************************************
// rcTestComparisonOperator . Ensures that the comparison operators work
// (comparing with another ReturnCode)
//******************************************************************************
uint32_t rcTestComparisonOperator()
{
    uint32_t l_result = 0;

    // Create similar ReturnCodes
    ReturnCode l_rc(FAPI2_RC_INVALID_ATTR_GET);
    ReturnCode l_rc2(FAPI2_RC_INVALID_ATTR_GET);

    // Ensure that the equality comparison returns true
    if (!(l_rc == l_rc2))
    {
        FAPI_ERR("rcTestComparisonOperator. 1. Equality comparison false");
        l_result = 1;
    }
    else
    {
        // Ensure that the inequality comparison returns false
        if (l_rc != l_rc2)
        {
            FAPI_ERR("rcTestComparisonOperator. 2. Inequality comparison true");
            l_result = 2;
        }
        else
        {
            // Change the code of l_rc2
            l_rc2 = get_fapi2_error();

            // Ensure that the equality comparison returns false
            if (l_rc == l_rc2)
            {
                FAPI_ERR("rcTestComparisonOperator.3.Equality comparison true");
                l_result = 3;
            }
            else
            {
                // Ensure that the inequality comparison returns true
                if (!(l_rc != l_rc2))
                {
                    FAPI_ERR("rcTestComparisonOperator. 4. Inequality "
                             " comparison false");
                    l_result = 4;
                }
                else
                {
                    FAPI_INF("rcTestComparisonOperator() Success!");
                }
            }
        }
    }

    return l_result;
}


//******************************************************************************
// rcTestComparisonOperatorWithRCValue. Ensures that the comparison operators
// work (comparing with a return code value)
//******************************************************************************
uint32_t rcTestComparisonOperatorWithRCValue()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc(FAPI2_RC_INVALID_ATTR_GET);

    // Ensure that the equality comparison returns true when comparing to the
    // same return code value
    if (!(l_rc == FAPI2_RC_INVALID_ATTR_GET))
    {
        FAPI_ERR("rcTestComparisonOperatorWithRCValue. 1. Equality comparison"
                " false");
        l_result = 1;
    }
    else
    {
        // Ensure that the inequality comparison returns false when comparing to
        // the same return code value
        if (l_rc != FAPI2_RC_INVALID_ATTR_GET)
        {
            FAPI_ERR("rcTestComparisonOperatorWithRCValue. 2. Inequality "
                    "comparison true");
            l_result = 2;
        }
        else
        {
            // Ensure that the equality comparison returns false when comparing
            // to a different return code value
            if (l_rc == FAPI2_RC_PLAT_ERR_SEE_DATA)
            {
                FAPI_ERR("rcTestComparisonOperatorWithRCValue. 3. Equality"
                         " comparison true");
                l_result = 3;
            }
            else
            {
                // Ensure that the inequality comparison returns true when
                // comparing to a different return code value
                if (!(l_rc != FAPI2_RC_PLAT_ERR_SEE_DATA))
                {
                    FAPI_ERR("rcTestComparisonOperatorWithRCValue. 4. "
                            " Inequality comparison false");
                    l_result = 4;
                }
                else
                {
                    FAPI_INF("rcTestComparisonOperatorWithRCValue. Success!");
                }
            }
        }
    }

    return l_result;
}


//******************************************************************************
// rcTestCopyConstructor. Ensures that the copy constructor works when there is
// attached PlatData and that the getPlatData function works
//******************************************************************************
uint32_t rcTestCopyConstructor()
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
    (void) l_rc.setPlatDataPtr(l_pMyData);

    // Create a ReturnCode using the copy constructor
    ReturnCode l_rc2(l_rc);

    // Ensure that the two ReturnCodes are the same
    if (l_rc != l_rc2)
    {
        FAPI_ERR("rcTestCopyConstructor. ReturnCodes differ");
        l_result = 1;
    }
    else
    {
        // Ensure that getPlatData retrieves the PlatData from l_rc
        void * l_pMyDataCheck = l_rc.getPlatDataPtr();

        if (l_pMyDataCheck != l_pMyData)
        {
            FAPI_ERR("rcTestCopyConstructor. 1. getPlatData returned "
                    " unexpected data ptr");
            l_result = 2;
        }
        else
        {
            // Ensure that getPlatData retrieves the PlatData from l_rc2
            l_pMyDataCheck = nullptr;
            l_pMyDataCheck = l_rc2.getPlatDataPtr();

            if (l_pMyDataCheck != l_pMyData)
            {
                FAPI_ERR("rcTestCopyConstructor. 2. getPlatData returned "
                          "unexpected data ptr");
                l_result = 3;
            }
            else
            {
                FAPI_INF("rcTestCopyConstructor. Success!");
            }
        }
    }

    return l_result;
}

//******************************************************************************
// rcTestAssignmentOperator. Ensures that the assignment operator works when
// there is attached PlatData and that the releasePlatData function works
//******************************************************************************
uint32_t rcTestAssignmentOperator()
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
    (void) l_rc.setPlatDataPtr(l_pMyData);

    // Create a ReturnCode using the assignment operator
    ReturnCode l_rc2;
    l_rc2 = l_rc;

    // Ensure that the two ReturnCodes are the same
    if (l_rc != l_rc2)
    {
        FAPI_ERR("rcTestAssignmentOperator. ReturnCodes differ");
        l_result = 1;
    }
    else
    {
        // Ensure that releasePlatData retrieves the PlatData from l_rc
        void * l_pMyDataCheck = l_rc.getPlatDataPtr();

        if (l_pMyDataCheck != l_pMyData)
        {
            FAPI_ERR("rcTestAssignmentOperator. getPlatDataPtr returned "
                      "unexpected data ptr");
            l_result = 2;
        }
        else
        {
            FAPI_INF("rcTestAssignmentOperator. Success!");
        }
    }

    return l_result;
}

//******************************************************************************
// rcTestGetErrorInfo . Ensures that the getErrorInfo function works when there
// is no ErrorInfo
//******************************************************************************
uint32_t rcTestGetErrorInfo()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;

    // Ensure that the getErrorInfo function returns nullptr
    const ErrorInfo * l_pErrInfo =
        reinterpret_cast<const ErrorInfo *> (0x12345678);

    l_pErrInfo = l_rc.getErrorInfo();

    if (l_pErrInfo != nullptr)
    {
        FAPI_ERR("rcTestGetErrorInfo. getErrorInfo did not return nullptr");
        l_result = 1;
    }
    else
    {
        FAPI_INF("rcTestGetErrorInfo. Success!");
    }

    return l_result;
}

//******************************************************************************
// rcTestErrorInfo. Ensures that the getErrorInfo function works when there is
//           ErrorInfo
//******************************************************************************
uint32_t rcTestErrorInfo()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;

    //TODO RTC 143127:fapi2 ReturnCode support in hostboot
    //l_rc.setPlatError(nullptr, FAPI2_RC_PLAT_ERR_SEE_DATA);
    l_rc._setHwpError(RC_FAPI2_SAMPLE);

    TARGETING::Target * l_pTarget = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_pTarget);

    fapi2::Target <fapi2::TARGET_TYPE_SYSTEM> l_target(l_pTarget);

    TARGETING::Target* l_masterProc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );

    fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_target2(l_masterProc);

    // Create some FFDC
    uint8_t l_ffdc = 0x12;

    // Add error information to the ReturnCode, the data is the same as that
    // produced by the fapiParseErrorInfo.pl script in fapiHwpErrorInfo.H
    const void * l_objects[] = {&l_ffdc, &l_target, &l_target2};
    fapi2::ErrorInfoEntry l_entries[6];
    l_entries[0].iv_type = fapi2::EI_TYPE_FFDC;
    l_entries[0].ffdc.iv_ffdcObjIndex = 0;
    l_entries[0].ffdc.iv_ffdcId = 0x22334455;
    l_entries[0].ffdc.iv_ffdcSize =
        fapi2::getErrorInfoFfdcSize(l_ffdc);
    l_entries[1].iv_type = fapi2::EI_TYPE_PROCEDURE_CALLOUT;
    l_entries[1].proc_callout.iv_procedure = fapi2::ProcedureCallouts::CODE;
    l_entries[1].proc_callout.iv_calloutPriority =
        fapi2::CalloutPriorities::MEDIUM;
    l_entries[2].iv_type = fapi2::EI_TYPE_BUS_CALLOUT;
    l_entries[2].bus_callout.iv_endpoint1ObjIndex = 1;
    l_entries[2].bus_callout.iv_endpoint2ObjIndex = 2;
    l_entries[2].bus_callout.iv_calloutPriority =
        fapi2::CalloutPriorities::MEDIUM;
    l_entries[3].iv_type = fapi2::EI_TYPE_CDG;
    l_entries[3].target_cdg.iv_targetObjIndex = 1;
    l_entries[3].target_cdg.iv_callout = 1;
    l_entries[3].target_cdg.iv_deconfigure = 1;
    l_entries[3].target_cdg.iv_gard = 0;
    l_entries[3].target_cdg.iv_calloutPriority = fapi2::CalloutPriorities::HIGH;
    l_entries[4].iv_type = fapi2::EI_TYPE_HW_CALLOUT;
    l_entries[4].hw_callout.iv_hw = fapi2::HwCallouts::MEM_REF_CLOCK;
    l_entries[4].hw_callout.iv_calloutPriority = fapi2::CalloutPriorities::LOW;
    l_entries[4].hw_callout.iv_refObjIndex = 0xff;
    l_entries[5].iv_type = fapi2::EI_TYPE_HW_CALLOUT;
    l_entries[5].hw_callout.iv_hw = fapi2::HwCallouts::FLASH_CONTROLLER_PART;
    l_entries[5].hw_callout.iv_calloutPriority = fapi2::CalloutPriorities::LOW;
    l_entries[5].hw_callout.iv_refObjIndex = 0xff;

    l_rc.addErrorInfo(l_objects, l_entries, 6);

    do
    {
        // Check that the Error Info can be retrieved
        const ErrorInfo * l_pErrInfo = nullptr;
        l_pErrInfo = l_rc.getErrorInfo();

        if (l_pErrInfo == nullptr)
        {
            FAPI_ERR("rcTestErrorInfo. getErrorInfo returned nullptr");
            l_result = 1;
            break;
        }

        // Check the FFDC error information
        if (l_pErrInfo->iv_ffdcs.size() != 1)
        {
            FAPI_ERR("rcTestErrorInfo. %d FFDCs", l_pErrInfo->iv_ffdcs.size());
            l_result = 2;
            break;
        }

        uint32_t l_size = 0;
        const void * l_pFfdc = nullptr;

        l_pFfdc = l_pErrInfo->iv_ffdcs[0]->getData(l_size);

        if (l_size != sizeof(l_ffdc))
        {
            FAPI_ERR("rcTestErrorInfo. FFDC size is %d", l_size);
            l_result = 3;
            break;
        }

        const uint8_t * l_pFfdcCheck = static_cast<const uint8_t *>(l_pFfdc);
        if (*l_pFfdcCheck != 0x12)
        {
            FAPI_ERR("rcTestErrorInfo. FFDC is 0x%x", *l_pFfdcCheck);
            l_result = 4;
            break;
        }
        // Check the callout/deconfigure/gard error information
        if (l_pErrInfo->iv_CDGs.size() != 1)
        {
            FAPI_ERR("rcTestErrorInfo. %d CDGs", l_pErrInfo->iv_CDGs.size());
            l_result = 5;
            break;
        }
        if (l_pErrInfo->iv_CDGs[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTestErrorInfo. CDG target mismatch");
            l_result = 6;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_callout != true)
        {
            FAPI_ERR("rcTestErrorInfo. callout not set");
            l_result = 7;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_calloutPriority !=
            CalloutPriorities::HIGH)
        {
            FAPI_ERR("rcTestErrorInfo. CDG callout priority mismatch (%d)",
                     l_pErrInfo->iv_CDGs[0]->iv_calloutPriority);
            l_result = 8;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_deconfigure != true)
        {
            FAPI_ERR("rcTestErrorInfo. deconfigure not set");
            l_result = 9;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_gard != false)
        {
            FAPI_ERR("rcTestErrorInfo. GARD set");
            l_result = 10;
            break;
        }

        // Additional procedure called out due to Bus Callout
        if (l_pErrInfo->iv_procedureCallouts.size() != 2)
        {
            FAPI_ERR("rcTestErrorInfo. %d proc-callouts",
                     l_pErrInfo->iv_procedureCallouts.size());
            l_result = 11;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[0]->iv_procedure !=
            ProcedureCallouts::CODE)
        {
            FAPI_ERR("rcTestErrorInfo. procedure callout[0] mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[0]->iv_procedure);
            l_result = 12;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[0]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTestErrorInfo. procedure callout[0] priority "
            " mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[0]->iv_calloutPriority);
            l_result = 13;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[1]->iv_procedure !=
            ProcedureCallouts::BUS_CALLOUT)
        {
            FAPI_ERR("rcTestErrorInfo. procedure callout[1] mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[1]->iv_procedure);
            l_result = 14;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[1]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTestErrorInfo. procedure callout[1] priority "
            "mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[1]->iv_calloutPriority);
            l_result = 15;
            break;
        }

        if (l_pErrInfo->iv_busCallouts.size() != 1)
        {
            FAPI_ERR("rcTestErrorInfo. %d bus-callouts",
                     l_pErrInfo->iv_busCallouts.size());
            l_result = 16;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_target1 != l_target)
        {
            FAPI_ERR("rcTestErrorInfo. bus target mismatch 1");
            l_result = 17;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_target2 != l_target2)
        {
            FAPI_ERR("rcTestErrorInfo. bus target mismatch 2");
            l_result = 18;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_calloutPriority !=
            CalloutPriorities::LOW)
        {
            FAPI_ERR("rcTestErrorInfo. bus callout priority mismatch (%d)",
                     l_pErrInfo->iv_busCallouts[0]->iv_calloutPriority);
            l_result = 19;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs.size() != 0)
        {
            FAPI_ERR("rcTestErrorInfo. %d children-cdgs",
                     l_pErrInfo->iv_childrenCDGs.size());
            l_result = 20;
            break;
        }

        if (l_pErrInfo->iv_hwCallouts.size() != 2)
        {
            FAPI_ERR("rcTestErrorInfo. %d hw-callouts",
                     l_pErrInfo->iv_hwCallouts.size());
            l_result = 27;
            break;
        }

        if (l_pErrInfo->iv_hwCallouts[0]->iv_hw !=
            HwCallouts::MEM_REF_CLOCK)
        {
            FAPI_ERR("rcTestErrorInfo. hw callout mismatch (%d)",
                     l_pErrInfo->iv_hwCallouts[0]->iv_hw);
            l_result = 28;
            break;
        }

        if (l_pErrInfo->iv_hwCallouts[0]->iv_calloutPriority !=
            CalloutPriorities::LOW)
        {
            FAPI_ERR("rcTestErrorInfo. hw callout priority mismatch (%d)",
                     l_pErrInfo->iv_hwCallouts[0]->iv_calloutPriority);
            l_result = 29;
            break;
        }

        FAPI_INF("rcTestErrorInfo. Success!");
    }
    while(0);

    return l_result;
}

//******************************************************************************
// rcTestCopyConstructorwithErrorInfo. Ensures that the copy constructor works
// when there is ErrorInfo
//******************************************************************************
uint32_t rcTestCopyConstructorwithErrorInfo()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;
    //TODO RTC 143127:fapi2 ReturnCode support in hostboot
    //l_rc.setPlatError(nullptr, FAPI2_RC_PLAT_ERR_SEE_DATA);
    l_rc._setHwpError(RC_FAPI2_SAMPLE);

    TARGETING::Target * l_pTarget = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_pTarget);

    fapi2::Target <fapi2::TARGET_TYPE_SYSTEM> l_target(l_pTarget);

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_target};
    fapi2::ErrorInfoEntry l_entries[1];
    l_entries[0].iv_type = fapi2::EI_TYPE_CDG;
    l_entries[0].target_cdg.iv_targetObjIndex = 0;
    l_entries[0].target_cdg.iv_callout = 0;
    l_entries[0].target_cdg.iv_deconfigure = 0;
    l_entries[0].target_cdg.iv_gard = 1;
    l_entries[0].target_cdg.iv_calloutPriority = fapi2::CalloutPriorities::LOW;

    l_rc.addErrorInfo(l_objects, l_entries, 1);

    // Create a ReturnCode using the copy constructor
    ReturnCode l_rc2(l_rc);

    do
    {
        // Ensure that the two ReturnCodes are the same
        if (l_rc != l_rc2)
        {
            FAPI_ERR("rcTestCopyConstructorwithErrorInfo. ReturnCodes differ");
            l_result = 1;
            break;
        }

        // Ensure that getErrorInfo returns correct information from l_rc
        const ErrorInfo * l_pErrInfo = nullptr;

        l_pErrInfo = l_rc.getErrorInfo();

        if (l_pErrInfo == nullptr)
        {
            FAPI_ERR("rcTestCopyConstructorwithErrorInfo. getErrorInfo "
                    "returned nullptr");
            l_result = 2;
            break;
        }

        if (l_pErrInfo->iv_CDGs.size() != 1)
        {
            FAPI_ERR("rcTestCopyConstructorwithErrorInfo. %d CDGs",
                    l_pErrInfo->iv_CDGs.size());
            l_result = 3;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTestCopyConstructorwithErrorInfo. CDG target mismatch");
            l_result = 4;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_gard != true)
        {
            FAPI_ERR("rcTestCopyConstructorwithErrorInfo. GARD not set");
            l_result = 5;
            break;
        }

        // Ensure that getErrorInfo from l_rc2 returns the same pointer
        const ErrorInfo * l_pErrInfo2 = l_rc2.getErrorInfo();

        if (l_pErrInfo != l_pErrInfo2)
        {
            FAPI_ERR("rcTestCopyConstructorwithErrorInfo. error info mismatch");
            l_result = 5;
            break;
        }

        FAPI_INF("rcTestCopyConstructorwithErrorInfo. Success!");
    }
    while(0);

    return l_result;
}

//******************************************************************************
// rcTestAssignmentOperatorwithErrorInfo. Ensures that the assignment operator
// works when there ErrorInfo
//******************************************************************************
uint32_t rcTestAssignmentOperatorwithErrorInfo()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;
    //TODO RTC 143127:fapi2 ReturnCode support in hostboot
    //l_rc.setPlatError(nullptr, FAPI2_RC_PLAT_ERR_SEE_DATA);
    l_rc._setHwpError(RC_FAPI2_SAMPLE);

    TARGETING::Target * l_pTarget = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_pTarget);

    fapi2::Target <fapi2::TARGET_TYPE_SYSTEM> l_target(l_pTarget);

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_target};
    fapi2::ErrorInfoEntry l_entries[1];
    l_entries[0].iv_type = fapi2::EI_TYPE_CDG;
    l_entries[0].target_cdg.iv_targetObjIndex = 0;
    l_entries[0].target_cdg.iv_callout = 0;
    l_entries[0].target_cdg.iv_deconfigure = 0;
    l_entries[0].target_cdg.iv_gard = 1;
    l_entries[0].target_cdg.iv_calloutPriority = fapi2::CalloutPriorities::LOW;

    l_rc.addErrorInfo(l_objects, l_entries, 1);

    // Create a ReturnCode using the assignment operator
    ReturnCode l_rc2;
    l_rc2 = l_rc;

    do
    {
        // Ensure that the two ReturnCodes are the same
        if (l_rc != l_rc2)
        {
            FAPI_ERR("rcTestAssignmentOperatorwithErrorInfo. ReturnCodes "
                     "differ");
            l_result = 1;
            break;
        }

        // Ensure that getErrorInfo returns correct information from l_rc
        const ErrorInfo * l_pErrInfo = nullptr;

        l_pErrInfo = l_rc.getErrorInfo();

        if (l_pErrInfo == nullptr)
        {
            FAPI_ERR("rcTestAssignmentOperatorwithErrorInfo. getErrorInfo "
                       "returned nullptr");
            l_result = 2;
            break;
        }

        if (l_pErrInfo->iv_CDGs.size() != 1)
        {
            FAPI_ERR("rcTestAssignmentOperatorwithErrorInfo. %d CDGs",
                    l_pErrInfo->iv_CDGs.size());
            l_result = 3;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTestAssignmentOperatorwithErrorInfo. CDG target "
                        "mismatch");
            l_result = 4;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_gard != true)
        {
            FAPI_ERR("rcTestAssignmentOperatorwithErrorInfo. GARD not set");
            l_result = 5;
            break;
        }

        // Ensure that getErrorInfo from l_rc2 returns the same pointer
        const ErrorInfo * l_pErrInfo2 = l_rc2.getErrorInfo();

        if (l_pErrInfo != l_pErrInfo2)
        {
            FAPI_ERR("rcTestAssignmentOperatorwithErrorInfo. error "
                     "info mismatch");
            l_result = 5;
            break;
        }

        FAPI_INF("rcTestAssignmentOperatorwithErrorInfo. Success!");
    }
    while(0);

    return l_result;
}

//******************************************************************************
// rcTestClearErrorInfo. Ensures that setting the ReturnCode to success clears
// ErrorInfo
//******************************************************************************
uint32_t rcTestClearErrorInfo()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;
    //TODO RTC 143127:fapi2 ReturnCode support in hostboot
    //l_rc.setPlatError(nullptr, FAPI2_RC_PLAT_ERR_SEE_DATA);
    l_rc._setHwpError(RC_FAPI2_SAMPLE);

    TARGETING::Target * l_pTarget = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_pTarget);

    fapi2::Target <fapi2::TARGET_TYPE_SYSTEM> l_target(l_pTarget);

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_target};
    fapi2::ErrorInfoEntry l_entries[1];
    l_entries[0].iv_type = fapi2::EI_TYPE_CDG;
    l_entries[0].target_cdg.iv_targetObjIndex = 0;
    l_entries[0].target_cdg.iv_callout = 0;
    l_entries[0].target_cdg.iv_deconfigure = 0;
    l_entries[0].target_cdg.iv_gard = 1;
    l_entries[0].target_cdg.iv_calloutPriority = fapi2::CalloutPriorities::LOW;

    l_rc.addErrorInfo(l_objects, l_entries, 1);

    // Set the ReturnCode to success
    l_rc = FAPI2_RC_SUCCESS;

    // Check that there is no ErrorInfo
    const ErrorInfo * l_pErrInfo = nullptr;

    l_pErrInfo = l_rc.getErrorInfo();

    if (l_pErrInfo != nullptr)
    {
        FAPI_ERR("rcTestClearErrorInfo. getErrorInfo returned nullptr");
        l_result = 1;
    }
    else
    {
        FAPI_INF("rcTestClearErrorInfo. Success!");
    }

    return l_result;
}

//******************************************************************************
// rcTestAddErrorInfo.Ensures that multiple Error Info of each type can be added
//******************************************************************************
uint32_t rcTestAddErrorInfo()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc;
    l_rc._setHwpError(RC_FAPI2_SAMPLE);

    TARGETING::Target * l_pTarget = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_pTarget);

    fapi2::Target <fapi2::TARGET_TYPE_SYSTEM> l_target(l_pTarget);

    TARGETING::Target* l_masterProc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );

    fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_target2(l_masterProc);

    // Create 2 FFDCs
    uint8_t l_ffdc = 0x12;
    uint32_t l_ffdc2 = 0x12345678;

    // Add error information to the ReturnCode
    const void * l_objects[] = {&l_ffdc, &l_ffdc2, &l_target,
                                 &l_target2};
    fapi2::ErrorInfoEntry l_entries[8];
    l_entries[0].iv_type = fapi2::EI_TYPE_FFDC;
    l_entries[0].ffdc.iv_ffdcObjIndex = 0;
    l_entries[0].ffdc.iv_ffdcId = 0x22334455;
    l_entries[0].ffdc.iv_ffdcSize =
        fapi2::getErrorInfoFfdcSize(l_ffdc);
    l_entries[1].iv_type = fapi2::EI_TYPE_FFDC;
    l_entries[1].ffdc.iv_ffdcObjIndex = 1;
    l_entries[1].ffdc.iv_ffdcId = 0x33445566;
    l_entries[1].ffdc.iv_ffdcSize =
        fapi2::getErrorInfoFfdcSize(l_ffdc2);
    l_entries[2].iv_type = fapi2::EI_TYPE_CDG;
    l_entries[2].target_cdg.iv_targetObjIndex = 2;
    l_entries[2].target_cdg.iv_callout = 0;
    l_entries[2].target_cdg.iv_deconfigure = 1;
    l_entries[2].target_cdg.iv_gard = 0;
    l_entries[2].target_cdg.iv_calloutPriority = fapi2::CalloutPriorities::HIGH;
    l_entries[3].iv_type = fapi2::EI_TYPE_CDG;
    l_entries[3].target_cdg.iv_targetObjIndex = 3;
    l_entries[3].target_cdg.iv_callout = 0;
    l_entries[3].target_cdg.iv_deconfigure = 0;
    l_entries[3].target_cdg.iv_gard = 1;
    l_entries[3].target_cdg.iv_calloutPriority =
                            fapi2::CalloutPriorities::MEDIUM;
    l_entries[4].iv_type = fapi2::EI_TYPE_PROCEDURE_CALLOUT;
    l_entries[4].proc_callout.iv_procedure = fapi2::ProcedureCallouts::CODE;
    l_entries[4].proc_callout.iv_calloutPriority =
                fapi2::CalloutPriorities::MEDIUM;
    l_entries[5].iv_type = fapi2::EI_TYPE_PROCEDURE_CALLOUT;
    l_entries[5].proc_callout.iv_procedure =
                fapi2::ProcedureCallouts::LVL_SUPPORT;
    l_entries[5].proc_callout.iv_calloutPriority =
                fapi2::CalloutPriorities::LOW;
    l_entries[6].iv_type = fapi2::EI_TYPE_BUS_CALLOUT;
    l_entries[6].bus_callout.iv_endpoint1ObjIndex = 2;
    l_entries[6].bus_callout.iv_endpoint2ObjIndex = 3;
    l_entries[6].bus_callout.iv_calloutPriority = fapi2::CalloutPriorities::LOW;
    l_entries[7].iv_type = fapi2::EI_TYPE_BUS_CALLOUT;
    l_entries[7].bus_callout.iv_endpoint1ObjIndex = 2;
    l_entries[7].bus_callout.iv_endpoint2ObjIndex = 3;
    l_entries[7].bus_callout.iv_calloutPriority =
                    fapi2::CalloutPriorities::HIGH;

    l_rc.addErrorInfo(l_objects, l_entries, 8);

    do
    {
        // Check that the Error Info can be retrieved
        const ErrorInfo * l_pErrInfo = nullptr;
        l_pErrInfo = l_rc.getErrorInfo();

        if (l_pErrInfo == nullptr)
        {
            FAPI_ERR("rcTestAddErrorInfo. getErrorInfo returned nullptr");
            l_result = 1;
            break;
        }

        // Check the FFDC error information
        if (l_pErrInfo->iv_ffdcs.size() != 2)
        {
            FAPI_ERR("rcTestAddErrorInfo.%d FFDCs",l_pErrInfo->iv_ffdcs.size());
            l_result = 2;
            break;
        }

        uint32_t l_size = 0;
        const void * l_pFfdc = nullptr;

        l_pFfdc = l_pErrInfo->iv_ffdcs[0]->getData(l_size);

        if (l_size != sizeof(l_ffdc))
        {
            FAPI_ERR("rcTestAddErrorInfo. FFDC[0] size is %d", l_size);
            l_result = 3;
            break;
        }

        const uint8_t * l_pFfdcCheck = static_cast<const uint8_t *>(l_pFfdc);
        if (*l_pFfdcCheck != 0x12)
        {
            FAPI_ERR("rcTestAddErrorInfo. FFDC[0] is 0x%x", *l_pFfdcCheck);
            l_result = 4;
            break;
        }

        l_pFfdc = l_pErrInfo->iv_ffdcs[1]->getData(l_size);

        if (l_size != sizeof(l_ffdc2))
        {
            FAPI_ERR("rcTestAddErrorInfo. FFDC[1] size is %d", l_size);
            l_result = 5;
            break;
        }

        const uint32_t * l_pFfdc2Check = static_cast<const uint32_t *>(l_pFfdc);
        if (*l_pFfdc2Check != 0x12345678)
        {
            FAPI_ERR("rcTestAddErrorInfo. FFDC[1] is 0x%x", *l_pFfdc2Check);
            l_result = 6;
            break;
        }

        // Check the callout/deconfigure/GARD error information
        if (l_pErrInfo->iv_CDGs.size() != 2)
        {
            FAPI_ERR("rcTestAddErrorInfo. %d CDGs", l_pErrInfo->iv_CDGs.size());
            l_result = 7;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_target != l_target)
        {
            FAPI_ERR("rcTestAddErrorInfo. CDG[0] target mismatch");
            l_result = 8;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_callout != false)
        {
            FAPI_ERR("rcTestAddErrorInfo. CDG[0] callout set");
            l_result = 9;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_calloutPriority !=
                CalloutPriorities::HIGH)
        {
            FAPI_ERR("rcTestAddErrorInfo. CDG[0] callout priority mismatch");
            l_result = 10;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_deconfigure != true)
        {
            FAPI_ERR("rcTestAddErrorInfo. CDG[0] deconfigure not set");
            l_result = 11;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_gard != false)
        {
            FAPI_ERR("rcTestAddErrorInfo. CDG[0] gard set");
            l_result = 12;
            break;
        }

        if (l_pErrInfo->iv_CDGs[1]->iv_target != l_target2)
        {
            FAPI_ERR("rcTestAddErrorInfo. CDG[1] target mismatch");
            l_result = 13;
            break;
        }

        if (l_pErrInfo->iv_CDGs[1]->iv_callout != false)
        {
            FAPI_ERR("rcTestAddErrorInfo. CDG[0] callout set");
            l_result = 14;
            break;
        }

        if (l_pErrInfo->iv_CDGs[1]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTestAddErrorInfo. CDG[1] callout priority mismatch");
            l_result = 15;
            break;
        }

        if (l_pErrInfo->iv_CDGs[1]->iv_deconfigure != false)
        {
            FAPI_ERR("rcTestAddErrorInfo. CDG[1] deconfigure set");
            l_result = 16;
            break;
        }

        if (l_pErrInfo->iv_CDGs[1]->iv_gard != true)
        {
            FAPI_ERR("rcTestAddErrorInfo. CDG[1] gard not set");
            l_result = 17;
            break;
        }

        // Additional procedures called out due to Bus Callout
        if (l_pErrInfo->iv_procedureCallouts.size() != 4)
        {
            FAPI_ERR("rcTestAddErrorInfo. %d proc-callouts",
                     l_pErrInfo->iv_procedureCallouts.size());
            l_result = 18;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[0]->iv_procedure !=
            ProcedureCallouts::CODE)
        {
            FAPI_ERR("rcTestAddErrorInfo. procedure[0] callout mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[0]->iv_procedure);
            l_result = 19;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[0]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTestAddErrorInfo. procedure[0] callout priority "
            "mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[0]->iv_calloutPriority);
            l_result = 20;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[1]->iv_procedure !=
            ProcedureCallouts::LVL_SUPPORT)
        {
            FAPI_ERR("rcTestAddErrorInfo. procedure[1] callout mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[1]->iv_procedure);
            l_result = 21;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[1]->iv_calloutPriority !=
            CalloutPriorities::LOW)
        {
            FAPI_ERR("rcTestAddErrorInfo. procedure[1] callout priority "
            "mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[1]->iv_calloutPriority);
            l_result = 22;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[2]->iv_procedure !=
            ProcedureCallouts::BUS_CALLOUT)
        {
            FAPI_ERR("rcTestAddErrorInfo. procedure[2] callout mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[2]->iv_procedure);
            l_result = 23;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[2]->iv_calloutPriority !=
            CalloutPriorities::LOW)
        {
            FAPI_ERR("rcTestAddErrorInfo. procedure[2] callout priority "
            "mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[2]->iv_calloutPriority);
            l_result = 24;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[3]->iv_procedure !=
            ProcedureCallouts::BUS_CALLOUT)
        {
            FAPI_ERR("rcTestAddErrorInfo. procedure[3] callout mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[3]->iv_procedure);
            l_result = 25;
            break;
        }

        if (l_pErrInfo->iv_procedureCallouts[3]->iv_calloutPriority !=
            CalloutPriorities::HIGH)
        {
            FAPI_ERR("rcTestAddErrorInfo. procedure[3] callout priority "
            "mismatch (%d)",
                     l_pErrInfo->iv_procedureCallouts[3]->iv_calloutPriority);
            l_result = 26;
            break;
        }

        if (l_pErrInfo->iv_busCallouts.size() != 2)
        {
            FAPI_ERR("rcTestAddErrorInfo. %d bus-callouts",
                     l_pErrInfo->iv_busCallouts.size());
            l_result = 27;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_target1 != l_target)
        {
            FAPI_ERR("rcTestAddErrorInfo. bus target mismatch 1");
            l_result = 28;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_target2 != l_target2)
        {
            FAPI_ERR("rcTestAddErrorInfo. bus target mismatch 2");
            l_result = 29;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[0]->iv_calloutPriority !=
            CalloutPriorities::LOW)
        {
            FAPI_ERR("rcTestAddErrorInfo. bus callout priority mismatch 1 (%d)",
                     l_pErrInfo->iv_busCallouts[0]->iv_calloutPriority);
            l_result = 30;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[1]->iv_target1 != l_target)
        {
            FAPI_ERR("rcTestAddErrorInfo. bus target mismatch 3");
            l_result = 31;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[1]->iv_target2 != l_target2)
        {
            FAPI_ERR("rcTestAddErrorInfo. bus target mismatch 4");
            l_result = 32;
            break;
        }

        if (l_pErrInfo->iv_busCallouts[1]->iv_calloutPriority !=
            CalloutPriorities::MEDIUM)
        {
            FAPI_ERR("rcTestAddErrorInfo. bus callout priority mismatch 2 (%d)",
                     l_pErrInfo->iv_busCallouts[1]->iv_calloutPriority);
            l_result = 33;
            break;
        }

        if (l_pErrInfo->iv_childrenCDGs.size() != 0)
        {
            FAPI_ERR("rcTestAddErrorInfo. %d children-cdgs",
                     l_pErrInfo->iv_childrenCDGs.size());
            l_result = 34;
            break;
        }

        FAPI_INF("rcTestAddErrorInfo. Success!");
    }
    while(0);

    return l_result;
}

//******************************************************************************
// rcTestStaticCast. Ensures that static_cast can be applied to a ReturnCode
//******************************************************************************
uint32_t rcTestStaticCast()
{
    uint32_t l_result = 0;

    // Create a ReturnCode
    ReturnCode l_rc(FAPI2_RC_INVALID_ATTR_GET);

    uint64_t l_check = static_cast<uint64_t>(l_rc);

    if (l_check != FAPI2_RC_INVALID_ATTR_GET)
    {
        FAPI_ERR("rcTestStaticCast. RC is not FAPI2_RC_INVALID_ATTR_GET, "
                " it is 0x%x",
        l_check);
        l_result = 1;
    }
    else
    {
        FAPI_INF("rcTestStaticCast. Success!");
    }

    return l_result;
}

#ifdef fips
uint32_t rcTestRcToErrl()
{
    uint32_t l_result = 0;

    // Create a FAPI  ReturnCode
    ReturnCode l_rc(FAPI2_RC_INVALID_ATTR_GET);

    // Create Target of functional processor chip
    TARGETING::Target *l_proc = nullptr;

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
            FAPI_ERR("rcTestRcToErrl:No functional processors found");
            break;
        }

        l_proc = *l_pFuncProcFilter;
        TARGETING::Target* l_pConstTarget =
            const_cast<TARGETING::Target*>(l_proc);

        fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP>l_procTarget(
                     reinterpret_cast<void*>(l_pConstTarget));

        const void * l_objects[] = { &l_fapiTarget};

        l_rc._setHwpError(RC_FAPI2_SAMPLE);
        fapi2::ErrorInfoEntry l_entries[1];
        l_entries[0].iv_type = fapi2::EI_TYPE_CDG;
        l_entries[0].target_cdg.iv_targetObjIndex = 0;
        l_entries[0].target_cdg.iv_callout = 0;
        l_entries[0].target_cdg.iv_deconfigure = 0;
        l_entries[0].target_cdg.iv_gard = 1;
        l_entries[0].target_cdg.iv_calloutPriority =
            fapi2::CalloutPriorities::LOW;


        // Add the error info
        l_rc.addErrorInfo(l_objects, l_entries, 1);

        // Check that the Error Info can be retrieved
        const ErrorInfo * l_pErrInfo = nullptr;
        l_pErrInfo = l_rc.getErrorInfo();

        if (l_pErrInfo == nullptr)
        {
            FAPI_ERR("rcTestRcToErrl:getErrorInfo returned nullptr");
            l_result = 2;
            break;
        }

        // Check the callout/deconfigure/GARD error information
        if (l_pErrInfo->iv_CDGs[0]->iv_target != l_fapiTarget)
        {
            FAPI_ERR("rcTestRcToErrl:CDG[0] target mismatch");
            l_result = 3;
            break;
        }

        if (l_pErrInfo->iv_CDGs[0]->iv_gard == false)
        {
            FAPI_ERR("rcTestRcToErrl:CDG[0] gard not set");
            l_result = 4;
            break;
        }

        // fapiRcToErrl is implicitly calling processEICDGs
        errlHndl_t pError = fapi2::rcToErrl(l_rc);
        if(pError == nullptr)
        {
            FAPI_ERR("rcTestRcToErrl:fapiRcToErrl returnd No Errorlog handle");
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

        FAPI_INF("rcTestRcToErrl:Deconfig/Gard HWP callout TC success");
        if(pError != nullptr)
        {
            delete pError;
            pError = nullptr;
        }

    }while(0);
    return l_result;
}
#endif //fips

// FIXME RTC:257497
// RC_TEST_ERROR_A required, in p9 comes from src/import/chips/p9/procedures/
// xml/error_info/proc_example_errors.xml
// There's no equivalent file in ekb-p10 yet.
#if 0
uint32_t rcTestReturnCodeAttrErrls()
{
    uint32_t numTests = 0;
    uint32_t numFails = 0;
    errlHndl_t l_errl = nullptr;
    FAPI_INF("rcTestReturnCodeAttrErrls() running");
    do
    {
        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipList;

        // Get a list of all of the proc chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        TARGETING::Target * l_Proc = nullptr;

        //Take the first proc and use it
        if (l_chipList.size() > 0)
        {
            l_Proc = l_chipList[0];
        }

        numTests++;
        if(l_Proc == nullptr)
        {
            // Send an errorlog because we cannot find any procs.
            TS_FAIL("getAllChips: could not find proc, skipping tests");
            numFails++;
            break;
        }


        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_ffdc_fail);
        if(l_errl != nullptr)
        {
            FAPI_INF("p10_ffdc_fail returned errl");
            errlCommit(l_errl,CXXTEST_COMP_ID);
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p10_ffdc_fail !!");
            numFails++;
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_procedureFfdc_fail);
        if(l_errl != nullptr)
        {
            FAPI_INF("p10_procedureFfdc_fail returned errl");
            errlCommit(l_errl,CXXTEST_COMP_ID);
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p10_procedureFfdc_fail !!");
            numFails++;
        }

        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(
                l_Proc);

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_registerFfdc_fail, fapi2_procTarget);
        if(l_errl != nullptr)
        {
            FAPI_INF("p10_registerFfdc_fail returned errl");
            errlCommit(l_errl,CXXTEST_COMP_ID);
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p10_registerFfdc_fail !!");
            numFails++;
        }

        numTests++;
        fapi2::ReturnCode l_rc;
        FAPI_INVOKE_HWP_RC(l_errl, l_rc, p10_registerFfdc_fail, fapi2_procTarget);
        if( (l_errl != nullptr) && (l_rc == (fapi2::ReturnCode)fapi2::RC_TEST_ERROR_A) )
        {
            FAPI_INF("p10_registerFfdc_fail returned correct RC");
            delete l_errl;
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("Wrong RC from p10_registerFfdc_fail !!");
            numFails++;
        }
    } while (0);

    FAPI_INF("rcTestReturnCodeAttrErrls Test Complete. %d/%d fails",
        numFails , numTests);

    return numFails;
}
#endif

}
