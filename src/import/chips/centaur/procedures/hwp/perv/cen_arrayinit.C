/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_arrayinit.C $ */
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
/// @file cen_arrayinit.C
/// @brief: PRV Array Init Procedure
///         - Array Init for all good chiplets except PRV
///         - Scan0 cleanup for all good chiplets except PRV

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
#include <cen_arrayinit.H>
#include <cen_common_funcs.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_arrayinit(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");
    FAPI_DBG("*** Array Init and Scan0 Cleanup for good Chiplets *** ");

    // Step 1: Calling array init subroutine
    FAPI_DBG("MC Group 3: Calling Array Init Subroutine ..." );
    FAPI_TRY(cen_arrayinit_module(i_target, SCAN_CHIPLET_GROUP3, SCAN_ALLREGIONEXVITAL));

    // Step 2: Scan0 for other Cplts
    FAPI_DBG("Call SCAN0 Subroutine for MC Group 3 ..." );
    FAPI_TRY(cen_scan0_module(i_target, SCAN_CHIPLET_GROUP3, SCAN_ALLREGIONEXVITAL, SCAN_ALLSCANEXPRV));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

