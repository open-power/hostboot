/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p9_i2ctests.H $                            */
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
/// @file  p9_i2ctests.C
///
/// @brief These procedures test the fapi2 i2c_access interfaces.
//------------------------------------------------------------------------------
#ifndef _P9_I2CTESTS_H_
#define _P9_I2CTESTS_H_

#include <fapi2.H>

fapi2::ReturnCode p9_i2ctest_geti2c_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode p9_i2ctest_puti2c_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode p9_i2ctest_geti2c_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

fapi2::ReturnCode p9_i2ctest_puti2c_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

fapi2::ReturnCode p9_i2ctest_double_read_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

fapi2::ReturnCode p9_i2ctest_write_read_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

#endif
