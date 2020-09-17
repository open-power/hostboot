/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/test/expErrlTest.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/**
 *  @file expErrlTest.C
 *  @brief Tests the various ways to grab/add explorer error log data
 */
#include <rcExpLog.H>  // RC error log side
#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>    // FAPI_INVOKE_HWP
#include <errl/errlmanager.H>
#include <expscom/expscom_errlog.H>



fapi2::ReturnCode get_scom(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const uint64_t i_address,
                               fapi2::buffer<uint64_t>& o_data)
{
  return fapi2::getScom(i_target,i_address,o_data);
}

uint32_t expErrorLogHb()
{
    uint32_t numTests = 0;
    uint32_t numFails = 0;
    errlHndl_t l_err = nullptr;

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_chipList;

    // Get a list of all of the functioning ocmb chips
    TARGETING::getAllChips(l_chipList, TARGETING::TYPE_OCMB_CHIP, true);

    //Verify at least one ocmb found, some systems do not have ocmb chips
    if(l_chipList.size() == 0 )
    {
        FAPI_INF("expErrorLogHb: No OCMB targets found, skipping test");
    }

    // create an error for each OCMB and grab the trace data
    for ( auto & l_ocmb : l_chipList )
    {
        //  Get a scom error with bad address
        FAPI_INF("expErrorLogHb - Get a scom error with bad address for ocmb 0x%.8X",
                  TARGETING::get_huid(l_ocmb));
        numTests++;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapi2_ocmbTarget(l_ocmb);
        fapi2::buffer<uint64_t> l_scom_buffer;
        FAPI_INVOKE_HWP( l_err, get_scom, fapi2_ocmbTarget,
                         0xFFFFFFFF, l_scom_buffer );
        if (l_err)
        {
            FAPI_INF("expErrorLogHb - created error log 0x%04X, now adding explorer errors", l_err->plid());

            // Add explorer error logs to this and commit
            bool logAdded = false;
            numTests++;
            logAdded = EXPSCOM::expAddLog(EXPSCOM::ACTIVE_LOG, l_ocmb, l_err);
            if (!logAdded)
            {
                TS_FAIL("expErrorLogHb: No ACTIVE explorer logs added to 0x%04X", l_err->plid());
                numFails++;
            }

            numTests++;
            logAdded = EXPSCOM::expAddLog(EXPSCOM::SAVED_LOG_A, l_ocmb, l_err);
            if (!logAdded)
            {
                TS_FAIL("expErrorLogHb: No SAVED image A explorer logs added to 0x%04X", l_err->plid());
                numFails++;
            }
            numTests++;
            logAdded = EXPSCOM::expAddLog(EXPSCOM::SAVED_LOG_B, l_ocmb, l_err);
            if (!logAdded)
            {
                TS_FAIL("expErrorLogHb: No SAVED image B explorer logs added to 0x%04X", l_err->plid());
                numFails++;
            }
            errlCommit(l_err, CXXTEST_COMP_ID);
        }
        else
        {
            TS_FAIL("expErrorLogHb: getScom(0xFFFFFFFF) worked on 0x%.8X",
                    TARGETING::get_huid(l_ocmb));
            numFails++;
        }
    }

    FAPI_INF("expErrorLogHb Test Complete. %d/%d fails", numFails, numTests);

    return numFails;
}

uint32_t expErrorLogRc()
{
    uint32_t numTests = 0;
    uint32_t numFails = 0;
    errlHndl_t l_errl = nullptr;
    FAPI_INF("expErrorLogRc() running");
    do
    {
        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipList;

        // Get a list of all of the functioning ocmb chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_OCMB_CHIP, true);
        TARGETING::Target * l_ocmb = nullptr;

        //Take the first ocmb and use it
        if (l_chipList.size() > 0)
        {
            l_ocmb = l_chipList[0];
        }
        else
        {
            FAPI_INF("expErrorLogRc: No OCMB targets found, skipping test");
            break;
        }

        numTests++;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapi2_ocmbTarget(l_ocmb);
        // This procedure creates an RC error and then adds Explorer log data
        // to that error
        // (0x500 bytes of ACTIVE log data, 0x450 bytes of SAVED log data (images A & B))
        FAPI_INVOKE_HWP(l_errl, exp_error_rc, fapi2_ocmbTarget, 0x500, 0x450, 0x450);
        if(l_errl != nullptr)
        {
            // Commit this error log so it can be examined for Explorer log data
            FAPI_INF("exp_errorFfdc_fail returned expected errl");
            errlCommit(l_errl,CXXTEST_COMP_ID);
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("expErrorLogRc: No error from exp_errorFfdc_fail !!");
            numFails++;
        }
    } while (0);

    FAPI_INF("expErrorLogRc Test Complete. %d/%d fails",
        numFails , numTests);

    return numFails;
}
