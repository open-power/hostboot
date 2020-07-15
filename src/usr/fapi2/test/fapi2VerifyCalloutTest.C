/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2VerifyCalloutTest.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
#include <fapi2.H>
#include <error_info.H>
#include <plat_hwp_invoker.H>
#include <errl/errlreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <rcSupport.H>

uint32_t rcTestCalloutDeconfigGard()
{
    uint32_t l_result = 0;

    // FIXME RTC:257497
    // See body of p10_gardAndDeconfig
#if 0
    errlHndl_t l_errl = NULL;
    bool l_hw_callout_found = false;

    FAPI_INF("rcTestCalloutDeconfigGard running");

    TARGETING::TargetHandleList l_chipList;
    TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);
    TARGETING::Target * l_Proc = NULL;

    //Grab the first chip if there are multiple
    if (l_chipList.size() > 0)
    {
        l_Proc = l_chipList[0];
    }
    else
    {
        TS_FAIL("No proc chips found");
    }

    //Convert to fapi2 target for the HWP below
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(l_Proc);

    FAPI_INVOKE_HWP(l_errl, p10_gardAndDeconfig, fapi2_procTarget);

    if(l_errl != NULL)
    {
        FAPI_INF("rcTestCalloutDeconfigGard: p10_gardAndDeconfig "
                                                    "returned errl (expected)");

        //Get the User Data fields of the errl. They are returned as
        //vector<void*>, so iterate over them.
        for( auto l_callout_raw : l_errl->
                getUDSections( ERRL_COMP_ID, ERRORLOG::ERRL_UDT_CALLOUT ) )
        {
            HWAS::callout_ud_t* l_callout_entry =
                    reinterpret_cast<HWAS::callout_ud_t*>(l_callout_raw);

            if(l_callout_entry->type == HWAS::HW_CALLOUT)
            {
                l_hw_callout_found = true;
                FAPI_INF("rcTestCalloutDeconfigGard: found hw callout");

                if(l_callout_entry->gardErrorType  == HWAS::GARD_Unrecoverable)
                {
                    FAPI_INF("rcTestCalloutDeconfigGard: "
                                                     "Gard Error Type matches");
                }
                else
                {
                    TS_FAIL("rcTestCalloutDeconfigGard: "
                    "Gard Error Type does NOT match. Expected: %x Actual: %x",
                    HWAS::GARD_Unrecoverable, l_callout_entry->gardErrorType);
                    l_result = 1;
                    break;
                }

                if(l_callout_entry->deconfigState == HWAS::DELAYED_DECONFIG)
                {
                    FAPI_INF("rcTestCalloutDeconfigGard: Target deconfigured");
                }
                else
                {
                    TS_FAIL("rcTestCalloutDeconfigGard: "
                                                  "Target is NOT deconfigured");
                    l_result = 2;
                    break;
                }
            }
        }
        if(!l_hw_callout_found)
        {
            TS_FAIL("rcTestCalloutDeconfigGard: hw callout not found");
            l_result = 3;
        }
    }
    else
    {
        TS_FAIL("rcTestCalloutDeconfigGard: No error was returned "
                                                  "from p10_gardAndDeconfig !!");
        l_result = 4;
    }

    delete l_errl;
    l_errl = NULL;

    FAPI_INF("rcTestCalloutDeconfigGard finished");
#endif
    return l_result;
}

uint32_t rcTestCalloutProcedure()
{
    uint32_t l_result = 0;
    // FIXME RTC:257497
    // See body of p10_procedureCallout
#if 0
    errlHndl_t l_errl = NULL;
    bool l_procedure_found = false;

    FAPI_INF("rcTestCalloutProcedure running");

    FAPI_INVOKE_HWP(l_errl, p10_procedureCallout);

    if(l_errl != NULL)
    {
        FAPI_INF("rcTestCalloutProcedure: "
                                "p10_procedureCallout returned errl (expected)");

        //Get the User Data fields of the errl. They are returned as
        //vector<void*>, so iterate over them.
        for( auto l_callout_raw : l_errl->
                getUDSections( ERRL_COMP_ID, ERRORLOG::ERRL_UDT_CALLOUT ) )
        {
            HWAS::callout_ud_t* l_callout_entry =
                    reinterpret_cast<HWAS::callout_ud_t*>(l_callout_raw);
            if(l_callout_entry->type == HWAS::PROCEDURE_CALLOUT)
            {
                l_procedure_found = true;
                FAPI_INF("rcTestCalloutProcedure: procedure callout found");
                if(l_callout_entry->priority == HWAS::SRCI_PRIORITY_HIGH)
                {
                    FAPI_INF("rcTestCalloutProcedure: "
                                       "high priority procedure callout found");
                }
                else
                {
                    TS_FAIL("rcTestCalloutProcedure: "
                    "incorrect procedure callout priority. Expected: %x"
                    " Actual: %x",
                    HWAS::SRCI_PRIORITY_HIGH,
                    l_callout_entry->priority);
                    l_result = 1;
                    break;
                }
            }
        }
        if(!l_procedure_found)
        {
            TS_FAIL("rcTestCalloutProcedure: procedure callout NOT found");
            l_result = 2;
        }
    }
    else
    {
        TS_FAIL("rcTestCalloutProcedure: No error was returned "
                                                 "from p10_procedureCallout !!");
        l_result = 3;
    }

    delete l_errl;
    l_errl = NULL;

    FAPI_INF("rcTestCalloutProcedure finished");
#endif
    return l_result;
}

uint32_t rcTestCalloutHw()
{
    uint32_t l_result = 0;
// FIXME RTC:257497
// See body of p10_hwCallout
#if 0
    errlHndl_t l_errl = NULL;
    bool l_hw_callout_found = false;

    FAPI_INF("rcTestCalloutHw running");

    TARGETING::TargetHandleList l_coreList;
    TARGETING::getAllChiplets(l_coreList, TARGETING::TYPE_CORE, false);
    TARGETING::Target * l_Core = NULL;

    //Get the first core
    if(l_coreList.size() > 0)
    {
        l_Core = l_coreList[0];
    }
    else
    {
        TS_FAIL("No cores found");
    }

    //Convert to fapi2 target for HWP
    fapi2::Target<fapi2::TARGET_TYPE_CORE> fapi2_coreTarget(l_Core);

    FAPI_INVOKE_HWP(l_errl, p10_hwCallout, fapi2_coreTarget);

    if(l_errl != NULL)
    {
        FAPI_INF("rcTestCalloutHw: p10_hwCallout returned errl (expected)");

        //Get the User Data fields of the errl. They are returned as
        //vector<void*>, so iterate over them.
        for( auto l_callout_raw : l_errl->
                getUDSections( ERRL_COMP_ID, ERRORLOG::ERRL_UDT_CALLOUT ) )
        {
            HWAS::callout_ud_t* l_callout_entry =
                    reinterpret_cast<HWAS::callout_ud_t*>(l_callout_raw);
            if(l_callout_entry->type == HWAS::HW_CALLOUT)
            {
                l_hw_callout_found = true;
                FAPI_INF("rcTestCalloutHw: hw callout found");
                if(l_callout_entry->priority == HWAS::SRCI_PRIORITY_LOW)
                {
                    FAPI_INF("rcTestCalloutHw: low priority hw callout found");
                }
                else
                {
                    TS_FAIL("rcTestCalloutHw: incorrect hw callout priority."
                    " Expected: %x Actual: %x",
                    HWAS::SRCI_PRIORITY_LOW, l_callout_entry->priority);
                    l_result = 1;
                    break;
                }
            }
        }
        if(!l_hw_callout_found)
        {
            TS_FAIL("rcTestCalloutHw: hw callout NOT found");
            l_result = 2;
        }
    }
    else
    {
        TS_FAIL("rcTestCalloutHw: No error was returned from p10_hwCallout !!");
        l_result = 3;
    }

    delete l_errl;
    l_errl = NULL;

    FAPI_INF("rcTestCalloutHw finished");
#endif
    return l_result;
}

uint32_t rcTestCalloutDeconfig()
{
    uint32_t l_result = 0;
// FIXME RTC:257497
// See body of p10_deconfigCallout
#if 0
    errlHndl_t l_errl = NULL;
    bool l_hw_callout_found = false;

    FAPI_INF("rcTestCalloutDeconfig running");

    TARGETING::TargetHandleList l_dimmList;
    TARGETING::getAllLogicalCards(l_dimmList, TARGETING::TYPE_DIMM, false);
    TARGETING::Target * l_Dimm = NULL;

    //Take the first dimm
    if (l_dimmList.size() > 0)
    {
        l_Dimm = l_dimmList[0];
    }
    else
    {
        TS_FAIL("No dimms found");
    }

    //Convert to fapi2 target for the HWP below
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> fapi2_dimmTarget(l_Dimm);

    FAPI_INVOKE_HWP(l_errl, p10_deconfigCallout, fapi2_dimmTarget);

    if(l_errl != NULL)
    {
        FAPI_INF("rcTestCalloutDeconfig: p10_deconfigCallout returned errl "
                                                                  "(expected)");

        //Get the User Data fields of the errl. They are returned as
        //vector<void*>, so iterate over them.
        for( auto l_callout_raw : l_errl->
                getUDSections( ERRL_COMP_ID, ERRORLOG::ERRL_UDT_CALLOUT ) )
        {
            HWAS::callout_ud_t* l_callout_entry =
                           reinterpret_cast<HWAS::callout_ud_t*>(l_callout_raw);

            if(l_callout_entry->type == HWAS::HW_CALLOUT)
            {
                l_hw_callout_found = true;
                FAPI_INF("rcTestCalloutDeconfig: hw callout found");
                if(l_callout_entry->deconfigState == HWAS::DELAYED_DECONFIG)
                {
                   FAPI_INF("rcTestCalloutDeconfig: Target is deconfigured");
                }
                else
                {
                    TS_FAIL("rcTestCalloutDeconfig: Target is NOT deconfigured");
                    l_result = 1;
                    break;
                }
            }
        }
        if(!l_hw_callout_found)
        {
            TS_FAIL("rcTestCalloutDeconfig: hw callout NOT found");
            l_result = 2;
        }
    }
    else
    {
        TS_FAIL("rcTestCalloutDeconfig: No error was returned from"
                                                      " p10_deconfigCallout !!");
        l_result = 3;
    }

    delete l_errl;
    l_errl = NULL;

    FAPI_INF("rcTestCalloutDeconfig finished");
#endif
    return l_result;
}

uint32_t rcTestCalloutNoneDeconfig()
{
    uint32_t l_result = 0;
// FIXME RTC:257497
// See body of p10_deconfigCalloutNone
#if 0
    errlHndl_t l_errl = NULL;
    bool l_hw_callout_found = false;

    FAPI_INF("rcTestCalloutNoneDeconfig running");

    TARGETING::TargetHandleList l_dimmList;
    TARGETING::getAllLogicalCards(l_dimmList, TARGETING::TYPE_DIMM, false);
    TARGETING::Target * l_Dimm = NULL;

    //Take the first dimm
    if (l_dimmList.size() > 0)
    {
        l_Dimm = l_dimmList[0];
    }
    else
    {
        TS_FAIL("No dimms found");
    }

    //Convert to fapi2 target for the HWP below
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> fapi2_dimmTarget(l_Dimm);

    FAPI_INVOKE_HWP(l_errl, p10_deconfigCalloutNone, fapi2_dimmTarget);

    if(l_errl != NULL)
    {
        FAPI_INF("rcTestCalloutNoneDeconfig: p10_deconfigCalloutNone "
                 "returned errl (expected)");

        //Get the User Data fields of the errl. They are returned as
        //vector<void*>, so iterate over them.
        for( auto l_callout_raw : l_errl->
                getUDSections( ERRL_COMP_ID, ERRORLOG::ERRL_UDT_CALLOUT ) )
        {
            HWAS::callout_ud_t* l_callout_entry =
                           reinterpret_cast<HWAS::callout_ud_t*>(l_callout_raw);

            if(l_callout_entry->type == HWAS::HW_CALLOUT)
            {
                l_hw_callout_found = true;
                FAPI_INF("rcTestCalloutNoneDeconfig: hw callout found");
                if(l_callout_entry->deconfigState == HWAS::DELAYED_DECONFIG)
                {
                   FAPI_INF("rcTestCalloutNoneDeconfig: Target is deconfigured");
                }
                else
                {
                    TS_FAIL("rcTestCalloutNoneDeconfig: Target is NOT deconfigured");
                    l_result = 1;
                    break;
                }
            }
        }
        if(!l_hw_callout_found)
        {
            TS_FAIL("rcTestCalloutNoneDeconfig: hw callout NOT found");
            l_result = 2;
        }
    }
    else
    {
        TS_FAIL("rcTestCalloutNoneDeconfig: No error was returned from"
                                                 " p10_deconfigCalloutNone !!");
        l_result = 3;
    }

    //l_errl->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
    //errlCommit(l_errl,CXXTEST_COMP_ID);
    delete l_errl;
    l_errl = NULL;

    // Now try it the way HWP people do it
    ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, p10_deconfigCalloutNone, fapi2_dimmTarget);
    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        // log the error but don't fail the unit test
        FAPI_INF("rcTestCalloutNoneDeconfig: logError called");
        fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED, true);
    }
    else
    {
        TS_FAIL("rcTestCalloutNoneDeconfig: No error was returned from "
                                     "FAPI_EXEC_HWP p10_deconfigCalloutNone !!");
        l_result = 4;
    }

    FAPI_INF("rcTestCalloutNoneDeconfig finished");
#endif
    return l_result;
}
