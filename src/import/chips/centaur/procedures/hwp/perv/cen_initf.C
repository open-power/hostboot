/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_initf.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
///
/// @file cen_initf.C
/// @brief Centaur initf (FAPI2)
///
/// @author Peng Fei GOU <shgoupf@cn.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_initf.H>
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fixes.H>
#include <centaur_misc_constants.H>
#include <cen_ring_id.h>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_initf(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");
    FAPI_TRY(fapi2::putRing(i_target, tcn_mbs_func),
             "Error from putRing (tcn_mbs_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_mbs_cmsk),
             "Error from putRing (tcn_mbs_cmsk)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_mbi_cmsk),
             "Error from putRing (tcn_mbi_cmsk)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_mbi_func),
             "Error from putRing (tcn_mbi_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_mbi_gptr),
             "Error from putRing (tcn_mbi_gptr)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_perv_func),
             "Error from putRing (tcn_perv_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_dmi_func),
             "Error from putRing (tcn_dmi_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_refr_func),
             "Error from putRing (tcn_refr_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_refr_abst),
             "Error from putRing (tcn_refr_abst)");
    FAPI_TRY(fapi2::putRing(i_target, tcm_memn_cmsk),
             "Error from putRing (tcm_memn_cmsk)");
    FAPI_TRY(fapi2::putRing(i_target, tcm_mems_cmsk),
             "Error from putRing (tcm_mems_cmsk)");
    FAPI_TRY(fapi2::putRing(i_target, tcm_memn_func),
             "Error from putRing (tcm_memn_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcm_mems_func),
             "Error from putRing (tcm_mems_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcm_perv_func),
             "Error from putRing (tcm_perv_func)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
