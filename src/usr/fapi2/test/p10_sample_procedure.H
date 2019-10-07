/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p10_sample_procedure.H $                   */
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
//------------------------------------------------------------------------------
/// @file  p10_sample_procedure.H
///
/// @brief This procedure is a sample p10 procedure for compilation testing
//------------------------------------------------------------------------------

#ifndef _P10_SAMPLE_PROCEDURE_H_
#define _P10_SAMPLE_PROCEDURE_H_


#include <fapi2.H>
#include <error_scope.H>

typedef fapi2::ReturnCode (*p10_sample_procedure_FP_t)(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

/// @brief This sample function has some CFAM/SCOM access for compilation
///        testing
///
/// @param[in]     i_target   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{

fapi2::ReturnCode p10_sample_procedure_proc(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_fc(
               fapi2::Target<fapi2::TARGET_TYPE_FC>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_eq(
               fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_core(
               fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_perv(
               fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_phb(
               fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_pec(
               fapi2::Target<fapi2::TARGET_TYPE_PEC>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_mc(
               fapi2::Target<fapi2::TARGET_TYPE_MC>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_mi(
               fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_omi(
               fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_omic(
               fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_mcc(
               fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_ocmb(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                uint8_t expectedValue);

fapi2::ReturnCode p10_sample_procedure_mem_port(
               fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                uint8_t expectedValue);

}

#endif // _P10_SAMPLE_PROCEDURE_H_
