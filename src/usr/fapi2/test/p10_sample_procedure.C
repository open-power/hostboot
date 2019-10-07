/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p10_sample_procedure.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#include <p10_sample_procedure.H>
#include <fapi2.H>
#include <plat_attribute_service.H>
#include <arch/ppc.H>

//------------------------------------------------------------------------------
/// @file  p10_sample_procedure.C
///
/// @brief These procedures test FAPI_ATTR_GET, FAPI_ATTR_SET,
///        and FAPI_TRY and FAPI_ERR. This is primarily here to
///        to make sure these compile okay.
//------------------------------------------------------------------------------


#define SAMPLE_PROCEDURE_MACRO( SAMPLE_HWP_NAME, FAPI2_TYPE)        \
    fapi2::ReturnCode SAMPLE_HWP_NAME(                              \
        fapi2::Target<FAPI2_TYPE>& i_target,                        \
        uint8_t expectedValue)                                      \
    {                                                               \
        uint8_t l_attr_scratch = 0;                                 \
        FAPI_ERR("Entering ...");                                   \
        FAPI_ERR("Set Scratch Attr on PROC Target %p = %s",         \
                 (TARGETING::Target*)i_target.get());               \
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SCRATCH_UINT8_1,         \
                               i_target,                            \
                               expectedValue));                     \
        FAPI_ERR("Get Scratch Attr on FAPI2_TYPE Target");          \
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SCRATCH_UINT8_1,         \
                               i_target,                            \
                               l_attr_scratch));                    \
        FAPI_ERR("Read scratch value : %d , expected it to be %d",  \
                 l_attr_scratch,                                    \
                 expectedValue);                                    \
    fapi_try_exit:                                                  \
        FAPI_ERR("Exiting ...");                                    \
        return fapi2::current_err;                                  \
}

SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_proc, fapi2::TARGET_TYPE_PROC_CHIP)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_eq, fapi2::TARGET_TYPE_EQ)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_core, fapi2::TARGET_TYPE_CORE)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_perv, fapi2::TARGET_TYPE_PERV)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_phb, fapi2::TARGET_TYPE_PHB)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_pec, fapi2::TARGET_TYPE_PEC)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_mc, fapi2::TARGET_TYPE_MC)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_mi, fapi2::TARGET_TYPE_MI)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_omi, fapi2::TARGET_TYPE_OMI)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_omic, fapi2::TARGET_TYPE_OMIC)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_mcc, fapi2::TARGET_TYPE_MCC)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_ocmb, fapi2::TARGET_TYPE_OCMB_CHIP)
SAMPLE_PROCEDURE_MACRO(p10_sample_procedure_mem_port, fapi2::TARGET_TYPE_MEM_PORT)
