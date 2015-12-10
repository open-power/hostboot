/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p9_sample_procedure.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <cxxtest/TestSuite.H>
#include <p9_sample_procedure.H>
#include <fapi2.H>
#include <plat_attribute_service.H>


//------------------------------------------------------------------------------
/// @file  p9_sample_procedure.C
///
/// @brief These procedures test FAPI_ATTR_GET, FAPI_ATTR_SET,
///        and FAPI_TRY and FAPI_ERR. This is primarily here to
///        to make sure these compile okay.
//------------------------------------------------------------------------------


fapi2::ReturnCode p9_sample_procedure_proc(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
               uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on PROC Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1,
                   i_target,
                    expectedValue));

    FAPI_ERR("Get Scratch Attr on PROC Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1,
                           i_target,
                           l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d",
             l_attr_scratch,
             expectedValue);


 fapi_try_exit:

    FAPI_ERR("Exiting ...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_sample_procedure_ex(
               fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
                                         uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on EX Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                    expectedValue));

    FAPI_ERR("Get Scratch Attr on EX Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));

    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_eq(
               fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
                                         uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on EQ Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on EQ Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_core(
               fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                                           uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on CORE Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on CORE Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}



fapi2::ReturnCode p9_sample_procedure_mcs(
               fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                          uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on MCS Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                    expectedValue));

    FAPI_ERR("Get Scratch Attr on MCS Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_mca(
               fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                          uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on MCA Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on MCA Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_mcbist(
               fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                             uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on MCBIST Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on MCBIST Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_xbus(
               fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
                                           uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on XBUS Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on XBUS Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_capp(
               fapi2::Target<fapi2::TARGET_TYPE_CAPP>& i_target,
                                           uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on CAPP Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on CAPP Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_obus(
               fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_target,
                                           uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on OBUS Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on OBUS Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_nv(
               fapi2::Target<fapi2::TARGET_TYPE_NV>& i_target,
                                         uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on NV Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on NV Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_sbe(
               fapi2::Target<fapi2::TARGET_TYPE_SBE>& i_target,
                                          uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on SBE Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on SBE Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_ppe(
               fapi2::Target<fapi2::TARGET_TYPE_PPE>& i_target,
                                          uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on PPE Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                    expectedValue));

    FAPI_ERR("Get Scratch Attr on PPE Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_perv(
               fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target,
                                           uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on PERV Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                    expectedValue));

    FAPI_ERR("Get Scratch Attr on PERV Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_phb(
               fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
                                          uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on PHB Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on PHB Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_sample_procedure_pec(
               fapi2::Target<fapi2::TARGET_TYPE_PEC>& i_target,
                                          uint8_t expectedValue)
{
    uint8_t l_attr_scratch = 0;
    FAPI_ERR("Entering ...");
    FAPI_ERR("Set Scratch Attr on PEC Target");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        expectedValue));

    FAPI_ERR("Get Scratch Attr on PEC Target");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1, i_target,
                        l_attr_scratch));
    FAPI_ERR("Read scratch value : %d , expected it to be %d", l_attr_scratch, expectedValue);

fapi_try_exit:
    FAPI_ERR("Exiting ...");
    return fapi2::current_err;

}

