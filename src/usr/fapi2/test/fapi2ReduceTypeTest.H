/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2ReduceTypeTest.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#include <fapi2/target.H>
#include <error_scope.H>

using namespace fapi2;


// NOOP function to call reduceType
template<fapi2::TargetType T>
ReturnCodes test_composite_type( const fapi2::Target<TARGET_TYPE_ALL >& i_target )
{
    fapi2::Target<T> l_temp_target;
    return i_target.reduceType<T>(l_temp_target);
};

class Fapi2ReduceTypeTest : public CxxTest::TestSuite
{
  public:
    //******************************************************************************
    // test_fapi2GetTarget
    //******************************************************************************
    void test_fapi2_reduceType()
    {
        //errlHndl_t l_err = nullptr;
        int numTests = 0;
        int numFails = 0;
        ReturnCodes l_rc = FAPI2_RC_SUCCESS;
        FAPI_INF("test_fapi2_reduceType> Start");

        do
        {
        // generate lots of targets
        GENERATE_TEST_TARGETS(test_fapi2_reduceType);

        numTests++;
        l_rc = test_composite_type<TARGET_TYPE_EQ>(fapi2_eqTarget);
        if( FAPI2_RC_SUCCESS != l_rc )
        {
            TS_FAIL( "test_fapi2_reduceType fail on TARGET_TYPE_EQ" );
            numFails++;
        }

        numTests++;
        l_rc = test_composite_type<TARGET_TYPE_PERV>(fapi2_pervTarget);
        if( FAPI2_RC_SUCCESS != l_rc )
        {
            TS_FAIL( "test_fapi2_reduceType fail on TARGET_TYPE_PERV" );
            numFails++;
        }

        numTests++;
        l_rc = test_composite_type<TARGET_TYPE_PROC_CHIP>(fapi2_procTarget);
        if( FAPI2_RC_SUCCESS != l_rc )
        {
            TS_FAIL( "test_fapi2_reduceType fail on TARGET_TYPE_PROC_CHIP" );
            numFails++;
        }

        numTests++;
        l_rc = test_composite_type<TARGET_TYPE_OMI>(fapi2_procTarget);
        if( FAPI2_RC_SUCCESS == l_rc )
        {
            TS_FAIL( "test_fapi2_reduceType did not fail on TARGET_TYPE_OMI from fapi2_procTarget" );
            numFails++;
        }

        } while(0);

        FAPI_INF("test_fapi2_reduceType> End %d/%d fails", numFails, numTests);
       
    }
};
