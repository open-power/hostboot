/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/rcSupport.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// @file  rcSupport.H
///
/// @brief These procedures provide fapi2 return codes with desired data to
///        support testing from rcTest

//------------------------------------------------------------------------------
#ifndef _RC_SUPPORT_H_
#define _RC_SUPPORT_H_

#include <fapi2.H>

extern const uint32_t VARIABLE_BUFFER_ELEMENTS;
extern const uint64_t FAPI2_TEST_BUFFER_VALUE;
extern const uint32_t FAPI2_TEST_VARIABLE_BUFFER_VALUE[];

//*****************************************************************************
// p10_ffdc_fail. Returns a fapi2::ReturnCode with an ffdc entry
//*****************************************************************************
fapi2::ReturnCode p10_ffdc_fail(void);


//*****************************************************************************
// p10_registerFfdc_fail.
// Returns a fapi2::ReturnCode with registery reads of a target
//*****************************************************************************
fapi2::ReturnCode p10_registerFfdc_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target);


//*****************************************************************************
// p10_procedureFfdc_fail.
// Cause a failure which calls a procedure that fills in some ffdc into the
// fapi2::ReturnCode
//*****************************************************************************
fapi2::ReturnCode p10_procedureFfdc_fail(void);

//*****************************************************************************
// p10_gardAndDeconfig
// Force a test return code that deconfigures the target and gards it
//****************************************************************************
fapi2::ReturnCode p10_gardAndDeconfig(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target);

//*****************************************************************************
// p10_deconfigCallout
// Force a test return code that deconfigures the target
//*****************************************************************************
fapi2::ReturnCode p10_deconfigCallout(
               fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm_target);

//******************************************************************************
// p10_deconfigCalloutNone
// Force a test return code that deconfigures the target
//******************************************************************************
fapi2::ReturnCode p10_deconfigCalloutNone(
              fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm_target);

//*****************************************************************************
// p10_procedureCallout
// Force a test return code that creates a procedure callout
//*****************************************************************************
fapi2::ReturnCode p10_procedureCallout();

//*****************************************************************************
// p10_hwCallout
// Force a test return code that creates a hw callout
//*****************************************************************************
fapi2::ReturnCode p10_hwCallout(
               fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target);


//****************************************************************************
// p10ErrorWithBuffer
// Force an error that will use a caller populated fapi2::buffer<>
//****************************************************************************
fapi2::ReturnCode p10ErrorWithBuffer(
                    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

//*****************************************************************************
// p10ErrorWithVariableBuffer
// Force an error that will use a caller populated fapi2::variable_buffer
//*****************************************************************************
fapi2::ReturnCode p10ErrorWithVariableBuffer(
                    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

#endif
