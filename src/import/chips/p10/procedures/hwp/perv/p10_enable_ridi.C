/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_enable_ridi.C $  */
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

//------------------------------------------------------------------------------
// @file  p10_enable_ridi.C
//
// @brief Modules for scan 0 and array init
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : SBE/HB
//------------------------------------------------------------------------------

#include <p10_enable_ridi.H>
#include <p10_scom_perv_3.H>

/// @brief Enable Drivers/Recievers for a pervasive target
///
/// @param[in]     i_target   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_enable_ridi(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target)
{
    using namespace scomt::perv;
    fapi2::buffer<uint64_t> l_data64;
    FAPI_DBG("p10_enable_ridi: Entering ...");

    FAPI_INF("Check for chiplet enable");
    FAPI_TRY(GET_NET_CTRL0_RW(i_target, l_data64));

    if ( GET_NET_CTRL0_CHIPLET_ENABLE(l_data64) )
    {
        FAPI_INF("Enable Recievers, Drivers DI1 & DI2");
        l_data64.flush<0>();
        SET_NET_CTRL0_CPLT_RCTRL(1, l_data64);
        SET_NET_CTRL0_CPLT_DCTRL(1, l_data64);
        SET_NET_CTRL0_CPLT_RCTRL2(1, l_data64);
        FAPI_TRY(PUT_NET_CTRL0_RW_WOR(i_target, l_data64));
    }

    FAPI_DBG("p10_enable_ridi: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}
