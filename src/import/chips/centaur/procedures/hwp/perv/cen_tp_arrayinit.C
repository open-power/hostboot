/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_tp_arrayinit.C $ */
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
/// @file cen_tp_arrayinit.C
/// @brief Centaur PRV Array Init (FAPI2)
///
/// General Description : PRV Array Init Procedure
///                       - Array Init for PRV Cplt
///                       - Scan0 of PRV Chiplet (except PIB/PCB)
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
#include <cen_tp_arrayinit.H>
#include <cen_common_funcs.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_tp_arrayinit(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");

    // Step 1: Array Init for PRV Cplt
    FAPI_DBG("Call ARRAY INIT Subroutine for Pervasive Chiplet");
    FAPI_TRY(cen_arrayinit_module(i_target, SCAN_CHIPLET_TP, SCAN_TP_ARRAY_INIT_REGIONS));

    // Step 2: Scan0 for PRV Cplt
    FAPI_DBG("Call SCAN0 Subroutine for Pervasive Chiplet");
    FAPI_TRY(cen_scan0_module(i_target, SCAN_CHIPLET_TP, SCAN_TP_REGIONS_EXCEPT_PIB_PCB, SCAN_TP_SCAN_SELECTS));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

