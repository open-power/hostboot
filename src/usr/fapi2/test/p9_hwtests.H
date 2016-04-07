/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p9_hwtests.H $                             */
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
//------------------------------------------------------------------------------
/// @file  p9_hwtests.C
///
/// @brief These procedures test the fapi2 hw_access interfaces.
//------------------------------------------------------------------------------
#ifndef _P9_HWTESTS_H_
#define _P9_HWTESTS_H_

#include <fapi2.H>

fapi2::ReturnCode p9_scomtest_getscom_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode p9_scomtest_putscom_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode p9_cfamtest_getcfam_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode p9_cfamtest_putcfam_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode p9_ringtest_getring_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode p9_ringtest_modring_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);



fapi2::ReturnCode p9_scomtest_getscom_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode p9_scomtest_putscom_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode p9_cfamtest_getcfam_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode p9_cfamtest_putcfam_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


/////////////
//
// TODO-RTC:151428 - need simics support for these ring functions to pass
//
fapi2::ReturnCode p9_ringtest_getring_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode p9_ringtest_modring_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
/////////////

#endif
