/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p10_mmiotests.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2024                        */
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
/// @file  p10_mmiotests.C
///
/// @brief These procedures test the fapi2 mmio_access interfaces.
//------------------------------------------------------------------------------
#ifndef _P10_MMIOTESTS_H_
#define _P10_MMIOTESTS_H_

#include <fapi2.H>

// Write/Read from the inband response address (shouldn't hurt anything)
//Constants from #include <exp_inband.H>
static const uint64_t EXPLR_IB_MMIO_OFFSET   = 0x0000000100000000ull; // 4GB
static const uint64_t EXPLR_IB_SRAM_BASE     = 0x01000000; // MSCCRNGE 01000000 020FFFFF
static const uint64_t EXPLR_IB_RSP_SRAM_ADDR  = EXPLR_IB_SRAM_BASE | 0x03FF00;
static const uint64_t EXPLR_IB_RSP_ADDR =  EXPLR_IB_MMIO_OFFSET | EXPLR_IB_RSP_SRAM_ADDR;

//-----------------------------------------------------------------------
// FAILURE TESTCASES
//-----------------------------------------------------------------------
// Unsupported target
fapi2::ReturnCode p10_mmiotest_getmmio_invalid_target(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode p10_mmiotest_putmmio_invalid_target(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// Expected size cannot be broken evenly into section sizes
fapi2::ReturnCode p10_mmiotest_indivisible_by_section_size(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

// Try unsupported section size
fapi2::ReturnCode p10_mmiotest_invalid_section_size(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

//-----------------------------------------------------------------------
// GOOD-CASE TESTCASES
//-----------------------------------------------------------------------
// Simple getMMIO, try with two get sizes
fapi2::ReturnCode p10_mmiotest_getmmio_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
               uint64_t i_addr,
               size_t i_mmioSize);

// Simple putMMIO, try with two put sizes
fapi2::ReturnCode p10_mmiotest_putmmio_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
               uint64_t i_addr,
               size_t i_mmioSize);

// Verify same read of the same thing twice matches
fapi2::ReturnCode p10_mmiotest_double_read_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
               uint64_t i_addr,
               size_t i_mmioSize);

// Verify we read exactly what we wrote
fapi2::ReturnCode p10_mmiotest_write_read_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
               uint64_t i_addr,
               size_t i_mmioSize);
#endif
