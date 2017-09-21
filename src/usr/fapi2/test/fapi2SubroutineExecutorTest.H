/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2SubroutineExecutorTest.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include <fapi2_subroutine_executor.H>

//--------------------------------------------------------------------------
/// @file  fapi2SubroutineExecutorTest.C
///
/// @brief This does tests of the FAPI try and FAPI assert MACROs without
///        needing full ReturnCode support.
//--------------------------------------------------------------------------

namespace fapi2
{

    class Fapi2SubroutineExecutorTest : public CxxTest::TestSuite
{
    private:

        // a pretend HWP that we will use for simple testing
        //note that function name does not match anything defined as acceptable hwp names in sbe_secureHwp.C
        fapi2::ReturnCode procedure_to_call(TARGETING::Target * i_target, uint32_t i_data, uint32_t& o_data )
        {
            fapi2::ReturnCode l_rc = FAPI2_RC_SUCCESS;

            if(i_data == 0 )
            {
                o_data = 1;
            }
            else if( i_data == 1 )
            {
                l_rc = FAPI2_RC_FALSE;
            }
            return l_rc;
        }

        // a pretend HWP that we will use for simple testing
        //note that function name matches what is defined as acceptable hwp name in sbe_secureHwp.C
        fapi2::ReturnCode test_hwp(TARGETING::Target * i_target, uint32_t i_data, uint32_t& o_data )
        {
            fapi2::ReturnCode l_rc = FAPI2_RC_SUCCESS;

            if(i_data == 0 )
            {
                o_data = 1;
            }
            else if( i_data == 1 )
            {
                l_rc = FAPI2_RC_FALSE;
            }
            return l_rc;
        }

    // Request to run a hwp that is on Hostboot's supported list
    // We expect that hostboot will send a secureHwp chip op
    // but it will fail because SBE doesn't support and instead
    // we will just run hwp on host
    // Test that the function runs okay
    fapi2::ReturnCode  p9_fapi_subroutineExecutor_ValidHwp(  )
    {
        FAPI_INF("p9_fapi_subroutineExecutor_ValidHwp starting ... ");
        fapi2::ReturnCode l_rc = FAPI2_RC_SUCCESS;
        // Get a list of all of the proc chips and use the first we find as our target
        // then cast it to a fapi2 target
        TARGETING::TargetHandleList l_chipList;
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, true);
        assert(l_chipList.size() > 0, "Could not find a functional proc chip, something is wrong");
        TARGETING::Target * l_proc = l_chipList[0];

        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(l_proc);

        uint32_t  l_var1 = 0;
        uint32_t  l_var2 = 0;


        FAPI_PLAT_CALL_SUBROUTINE(l_rc, test_hwp, fapi2_procTarget, l_var1, l_var2);

        if(l_var2 != 1)
        {
            l_rc = 0xDEAD;
        }
        FAPI_INF("p9_fapi_subroutineExecutor_ValidHwp complete ... ");
        return l_rc;
    }

    // Request to run a hwp that isn't on Hostboot's supported list
    // We expect that hostboot will still send secureHwp chip op
    // but it will fail and instead we will just run hwp on host
    // Test that the function runs okay
    fapi2::ReturnCode  p9_fapi_subroutineExecutor_InvalidHwp(  )
    {
        FAPI_INF("p9_fapi_subroutineExecutor_InvalidHwp starting ... ");
        fapi2::ReturnCode l_rc = FAPI2_RC_SUCCESS;
        // Get a list of all of the proc chips and use the first we find as our target
        // then cast it to a fapi2 target
        TARGETING::TargetHandleList l_chipList;
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, true);
        assert(l_chipList.size() > 0, "Could not find a functional proc chip, something is wrong");
        TARGETING::Target * l_proc = l_chipList[0];
        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(l_proc);

        uint32_t  l_var1 = 0;
        uint32_t  l_var2 = 0;
        FAPI_PLAT_CALL_SUBROUTINE(l_rc, procedure_to_call, fapi2_procTarget, l_var1, l_var2);

        if(l_rc == FAPI2_RC_FALSE)
        {
            FAPI_INF("p9_fapi_subroutineExecutor_InvalidHwp:: l_var1: %x l_var2: %x   l_rc: FALSE", l_var1, l_var2);
        }
        else
        {
            FAPI_INF("p9_fapi_subroutineExecutor_InvalidHwp:: l_var1: %x l_var2: %x   l_rc: SUCESS", l_var1, l_var2);
        }

        if(l_var2 != 1)
        {
            l_rc = 0xDEAD;
        }
        FAPI_INF("p9_fapi_subroutineExecutor_InvalidHwp complete ... ");
        return l_rc;
    }

    // Request to run a hwp that isn't on Hostboot's supported list
    // We expect that hostboot will still send secureHwp chip op
    // but it will fail and instead we will just run hwp on host
    // This test checks that if the hwp fails we get the RC correctly
    fapi2::ReturnCode  p9_fapi_subroutineExecutor_InvalidHwp_RcCheck(  )
    {
        FAPI_INF("p9_fapi_subroutineExecutor_InvalidHwp_RcCheck started ... ");
        fapi2::ReturnCode l_rc = FAPI2_RC_SUCCESS;
        // Get a list of all of the proc chips and use the first we find as our target
        // then cast it to a fapi2 target
        TARGETING::TargetHandleList l_chipList;
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, true);
        TARGETING::Target * l_proc = l_chipList[0];
        assert(l_chipList.size() > 0, "Could not find a functional proc chip, something is wrong");
        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(l_proc);

        uint32_t  l_var1 = 1;
        uint32_t  l_var2 = 1;
        FAPI_PLAT_CALL_SUBROUTINE(l_rc, procedure_to_call, fapi2_procTarget, l_var1, l_var2);
        if(l_rc == FAPI2_RC_FALSE)
        {
            FAPI_INF("p9_fapi_subroutineExecutor_InvalidHwp_RcCheck:: l_var1: %x l_var2: %x   l_rc: FALSE", l_var1, l_var2);
        }
        else
        {
            FAPI_INF("p9_fapi_subroutineExecutor_InvalidHwp_RcCheck:: l_var1: %x l_var2: %x   l_rc: SUCESS", l_var1, l_var2);
        }
        FAPI_INF("p9_fapi_subroutineExecutor_InvalidHwp_RcCheck complete ... ");
        return l_rc;
    }

  public:
    //******************************************************************************
    // test_fapi2SubroutineExecutor
    //******************************************************************************

    void  test_fapi2SubroutineExecutor()
    {
        int numTests = 0;
        int numFails = 0;
        fapi2::ReturnCode l_rc = FAPI2_RC_SUCCESS;

        FAPI_INF("test_fapi2SubroutineExecutor starting ... ");
        numTests++;
        l_rc = p9_fapi_subroutineExecutor_InvalidHwp();
        if (l_rc != FAPI2_RC_SUCCESS)
        {
            numFails++;
            TS_FAIL(" p9_fapi_subroutineExecutor_InvalidHwp returned bad RC!");
        }

        numTests++;
        l_rc = p9_fapi_subroutineExecutor_InvalidHwp_RcCheck();
        if (l_rc  != FAPI2_RC_FALSE)
        {
            numFails++;
            TS_FAIL(" p9_fapi_subroutineExecutor_InvalidHwp_RcCheck failed to return bad RC!");
        }

        //TODO RTC:180100 once the SBE support comes in we want SBE team to add support
        //for a test HWP so we can validate the chipOp request path works. This also
        //requires a 2 socket sytem model (might not be ready until cumulus)
        //p9_fapi_subroutineExecutor_ValidHwp

        FAPI_INF("test_fapi2SubroutineExecutor:: Test Complete. %d/%d fails", numFails, numTests);

    } // end main testcase driver

}; // end class

} // end namespace fapi2
