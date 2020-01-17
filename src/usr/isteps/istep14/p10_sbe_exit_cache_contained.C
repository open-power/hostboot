/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/p10_sbe_exit_cache_contained.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

//  targeting support
#include <fapi2/target.H>
#include <return_code.H>
#include <p10_exit_cache_contained.H>
#include <p10_sbe_exit_cache_contained.H>
#include <assert.h>

namespace ISTEP_14
{

extern "C"
{

fapi2::ReturnCode p10_sbe_exit_cache_contained(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const size_t i_xscomPairSize,
    const void* i_pxscomInit,
    const p10_sbe_exit_cache_contained_step_t i_steps)
{ assert(0); }

}
};
