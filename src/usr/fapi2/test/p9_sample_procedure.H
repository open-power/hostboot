/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p9_sample_procedure.H $                    */
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
//------------------------------------------------------------------------------
/// @file  p9_sample_procedure.H
///
/// @brief This procedure is a sample p9 procedure for compilation testing
//------------------------------------------------------------------------------

#ifndef _P9_SAMPLE_PROCEDURE_H_
#define _P9_SAMPLE_PROCEDURE_H_


#include <fapi2.H>
#include <error_scope.H>

typedef fapi2::ReturnCode (*p9_sample_procedure_FP_t)(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

/// @brief This sample function has some CFAM/SCOM access for compilation
///        testing
///
/// @param[in]     i_target   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{

fapi2::ReturnCode p9_sample_procedure_proc(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                uint8_t expectedValue);


fapi2::ReturnCode p9_sample_procedure_ex(
               fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
                uint8_t expectedValue);


fapi2::ReturnCode p9_sample_procedure_eq(
               fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_core(
               fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                uint8_t expectedValue);


fapi2::ReturnCode p9_sample_procedure_mcs(
               fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_mca(
               fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_mcbist(
               fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_xbus(
               fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_capp(
               fapi2::Target<fapi2::TARGET_TYPE_CAPP>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_obus(
               fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_nv(
               fapi2::Target<fapi2::TARGET_TYPE_NV>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_sbe(
               fapi2::Target<fapi2::TARGET_TYPE_SBE>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_ppe(
               fapi2::Target<fapi2::TARGET_TYPE_PPE>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_perv(
               fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_phb(
               fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p9_sample_procedure_pec(
               fapi2::Target<fapi2::TARGET_TYPE_PEC>& i_target,
                uint8_t expectedValue);
}

#endif // _P9_SAMPLE_PROCEDURE_H_
