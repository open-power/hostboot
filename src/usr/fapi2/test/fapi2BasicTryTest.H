/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2BasicTryTest.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
// #include <plat_attribute_service.H>

//--------------------------------------------------------------------------
/// @file  p9_basicTry.C
///
/// @brief This does tests of the FAPI try and FAPI assert MACROs without
///        needing full ReturnCode support.
//--------------------------------------------------------------------------

namespace fapi2
{

class Fapi2BasicTryTest : public CxxTest::TestSuite
{
    private:

    // This is the basic function that allows us to set a return code
    // that we can use for  FAPI_TRY macro testing.
    uint32_t  p9_forceTestUsingRc( uint32_t  i_rc )
    {
        FAPI_INF("p9_forceTestUsingRc  with RC = %d", i_rc );

        return(i_rc);
    }


    // Force a bad RC and see if FAPI_TRY will do the goto exit
    fapi2::ReturnCode  p9_fapi_tryFailure(  )
    {

        FAPI_INF("Go for BAD TEST ");
        FAPI_TRY( p9_forceTestUsingRc(0xFF) );

        // Should never get here since we failed routine above
        // Hence, I want to fail testcase if we do
        FAPI_ERR("Completed BAD TEST --Should never get here");
        fapi2::current_err = 0xDEAD;
        return fapi2::current_err;

    fapi_try_exit:
        // We failed as expected
        FAPI_INF( "Had RC %d but will exit cleanly",
                  (uint64_t)(fapi2::current_err) );
        fapi2::current_err = 0;

        return fapi2::current_err;
    }


    // Force the FAPI_ASSERT to fail and verify it will goto exit
    fapi2::ReturnCode  p9_fapi_assertFailure(  )
    {


        uint32_t  l_var1 = 5, l_var2 = 25;
        FAPI_INF("Running ASSERT test that will fail");
        FAPI_ASSERT( l_var1 == l_var2,
                    fapi2::FAPI2_SAMPLE(),
                    "Verify ASSERT that WILL ASSERT" );

        // Shouldn't get here so fail if we do
        FAPI_ERR("Completed BAD TEST with ASSERT -- Should never get here");
        fapi2::current_err = 0xABAD;
        return fapi2::current_err;

    fapi_try_exit:
        // We detected the fail which is expected
        FAPI_INF( "FAILURE as expected though: %d",
                  (uint64_t)(fapi2::current_err) );
        fapi2::current_err = 0;

        return fapi2::current_err;
    }

    // FAPI_TRY with good RC so we should run thru all code.
    // If it doesn't work, we should have non-zero RC which
    // forces testcase failure.
    fapi2::ReturnCode  p9_fapi_trySuccess(  )
    {
        fapi2::current_err = 0xFFFF;

        FAPI_INF("Go for GOOD TEST ");
        FAPI_TRY( p9_forceTestUsingRc(0) );
        FAPI_INF("Completed GOOD TEST with CURRENT_ERROR: %d",
                (uint64_t)(fapi2::current_err) );
        fapi2::current_err = 0;

    fapi_try_exit:
        FAPI_INF("Exiting with %d",   (uint64_t)(fapi2::current_err) );

        return fapi2::current_err;
    }


    // FAPI_ASSERT should succeed and run thru all code.
    // If it doesn't work, we should have non-zero RC which
    // forces testcase failure.
    fapi2::ReturnCode  p9_fapi_assertSuccess(  )
    {
        fapi2::current_err = 0xFFFF;

        uint32_t  l_var1 = 5, l_var2 = 5;
        FAPI_ASSERT( l_var1 == l_var2,
                    fapi2::FAPI2_SAMPLE(),
                    "Verify ASSERT that doesn't assert" );
        FAPI_INF("Completed GOOD TEST with ASSERT");
        fapi2::current_err = 0;


    fapi_try_exit:
        FAPI_INF("SUCCESS Exiting with %d",   (uint64_t)(fapi2::current_err) );

        return fapi2::current_err;
    }

  public:
    //******************************************************************************
    // test_fapi2basicTry
    //******************************************************************************

    void  test_fapi2basicTry()
    {
        int numTests = 0;
        int numFails = 0;
        fapi2::ReturnCode l_rc;


        FAPI_INF("fapi2basicTry starting ... ");

        numTests++;
        l_rc = p9_fapi_tryFailure();
        if ( true == (bool)l_rc )
        {
            numFails++;
            TS_FAIL(" p9_fapi_tryFailure returned error");
        }

        numTests++;
        l_rc = p9_fapi_assertFailure();
        if ( true == (bool)l_rc )
        {
            numFails++;
            TS_FAIL(" p9_fapi_assertFailure returned error");
        }

        numTests++;
        l_rc = p9_fapi_trySuccess();
        if ( true == (bool)l_rc )
        {
            numFails++;
            TS_FAIL(" p9_fapi_trySuccess returned error");
        }

        numTests++;
        l_rc = p9_fapi_assertSuccess();
        if ( true == (bool)l_rc )
        {
            numFails++;
            TS_FAIL(" p9_fapi_assertSuccess returned error");
        }

        FAPI_INF("fapi2basicTry:: Test Complete. %d/%d fails", numFails, numTests);

    } // end main testcase driver

}; // end class

} // end namespace fapi2
