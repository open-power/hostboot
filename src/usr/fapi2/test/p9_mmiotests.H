/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p9_mmiotests.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file  p9_mmiotests.C
///
/// @brief These procedures test the fapi2 mmio_access interfaces.
//------------------------------------------------------------------------------
#ifndef _P9_MMIOTESTS_H_
#define _P9_MMIOTESTS_H_

#include <fapi2.H>

//-----------------------------------------------------------------------
// FAILURE TESTCASES
//-----------------------------------------------------------------------
// Unsupported target
fapi2::ReturnCode p9_mmiotest_getmmio_invalid_target(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode p9_mmiotest_putmmio_invalid_target(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// Expected size cannot be broken evenly into section sizes
fapi2::ReturnCode p9_mmiotest_indivisible_by_section_size(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

// Try unsupported section size
fapi2::ReturnCode p9_mmiotest_invalid_section_size(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

//-----------------------------------------------------------------------
// GOOD-CASE TESTCASES
//-----------------------------------------------------------------------
// Simple getMMIO, try with two get sizes
fapi2::ReturnCode p9_mmiotest_getmmio_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

// Simple putMMIO, try with two put sizes
fapi2::ReturnCode p9_mmiotest_putmmio_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

// Verify same read of the same thing twice matches
fapi2::ReturnCode p9_mmiotest_double_read_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

// Verify we read exactly what we wrote
fapi2::ReturnCode p9_mmiotest_write_read_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);
#endif
