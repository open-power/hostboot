/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/rcSupport.H $                              */
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
/// @file  rcSupport.H
///
/// @brief These procedures provide fapi2 return codes with desired data to
///        support testing from rcTest

//------------------------------------------------------------------------------
#ifndef _RC_SUPPORT_H_
#define _RC_SUPPORT_H_

#include <fapi2.H>

//******************************************************************************
// p9_ffdc_fail. Returns a fapi2::ReturnCode with an ffdc entry
//******************************************************************************
fapi2::ReturnCode p9_ffdc_fail(void);


//******************************************************************************
// p9_registerFfdc_fail.
// Returns a fapi2::ReturnCode with registery reads of a target
//******************************************************************************
fapi2::ReturnCode p9_registerFfdc_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target);


//******************************************************************************
// p9_procedureFfdc_fail.
// Cause a failure which calls a procedure that fills in some ffdc into the
// fapi2::ReturnCode
//******************************************************************************
fapi2::ReturnCode p9_procedureFfdc_fail(void);


#endif
