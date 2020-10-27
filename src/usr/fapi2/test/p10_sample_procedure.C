/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p10_sample_procedure.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

//------------------------------------------------------------------------------
/// @file  p10_sample_procedure.C
///
/// @brief This procedures tests FAPI_ATTR_GET, FAPI_TRY, and FAPI_ERR.
///        This is primarily here to make sure these compile okay.
//------------------------------------------------------------------------------


#define SAMPLE_PROCEDURE_MACRO( SAMPLE_HWP_NAME, FAPI2_TYPE)        \
    fapi2::ReturnCode SAMPLE_HWP_NAME(                              \
        fapi2::Target<FAPI2_TYPE>& i_target,                        \
        uint8_t expectedValue)                                      \
    {                                                               \
         fapi2::ATTR_FAPI_POS_Type l_fapi_pos = 0;                             \
        FAPI_ERR("Entering ...");                                   \
        FAPI_ERR("Get ATTR_FAPI_POS on FAPI2_TYPE Target");         \
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS,                \
                               i_target,                            \
                               l_fapi_pos));                    \
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
