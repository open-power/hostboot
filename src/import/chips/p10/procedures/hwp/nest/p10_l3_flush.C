/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_l3_flush.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
///-----------------------------------------------------------------------------
///
/// @file p10_l3_flush.C
/// @brief Initiates an L3 purge request
///
/// *HWP HW Maintainer: Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
/// *HWP Consumed by: FSP, SBE
/// ----------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p10_l3_flush.H>

//--------------------------------------------------------------------------
// Constant definitions
//--------------------------------------------------------------------------

// L3 purge operation delay times for HW/sim
const uint32_t P10_L3_FLUSH_HW_NS_DELAY     = 1000000;
const uint32_t P10_L3_FLUSH_SIM_CYCLE_DELAY = 1000000;

// If the L3 purge is not completed in P10_L3_FLUSH_TIMEOUT delays, fail with error
const uint32_t P10_L3_FLUSH_TIMEOUT_COUNT = 100;

//--------------------------------------------------------------------------
//  HWP entry point
//--------------------------------------------------------------------------

fapi2::ReturnCode p10_l3_flush(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const uint32_t i_purge_type,
    const uint32_t i_purge_addr)
{
    using namespace scomt;
    using namespace scomt::c;
    // mark HWP entry
    FAPI_DBG("Entering ...\n");

    fapi2::buffer<uint64_t> l_purge_reg_data(0x0);
    uint32_t purge_pending_count = 0;

    //Make sure that the inputs are acceptable
    //Make sure the purge type is full, single, full blind, or dynamic
    //Make sure that the purge address fits within bits 16:26
    FAPI_ASSERT(((i_purge_type == L3_FULL_PURGE) ||
                 (i_purge_type == L3_SINGLE_PURGE) ||
                 (i_purge_type == L3_FULL_BLIND_PURGE) ||
                 (i_purge_type == L3_DYNAMIC_PURGE)) ||
                (i_purge_addr < 0x800),
                fapi2::P10_L3_FLUSH_INVALID_ARGS_ERR()
                .set_TARGET(i_target)
                .set_PURGETYPE(i_purge_type)
                .set_PURGEADDR(i_purge_addr),
                "i_purge_type is not a compatible type");

    //Make sure that another flush is not happening
    FAPI_DBG("Verifying that a previous flush is not active");
    FAPI_TRY(GET_L3_MISC_L3CERRS_PRD_PURGE_REG(i_target, l_purge_reg_data));

    FAPI_ASSERT(!(GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(l_purge_reg_data)),
                fapi2::P10_L3_FLUSH_PREVIOUS_PURGE_ACTIVE_ERR()
                .set_TARGET(i_target)
                .set_PURGEREG(l_purge_reg_data),
                "Previous purge request has not completed error");

    SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(0x1, l_purge_reg_data);
    SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE(i_purge_type, l_purge_reg_data);
    SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR(i_purge_addr, l_purge_reg_data);

    //Write the purge request
    FAPI_TRY(PUT_L3_MISC_L3CERRS_PRD_PURGE_REG(i_target, l_purge_reg_data));

    //Spin on PRD_PURGE_REQ until hardware clears it
    while(purge_pending_count++ < P10_L3_FLUSH_TIMEOUT_COUNT)
    {
        FAPI_DBG("Waiting for purge to complete...");

        FAPI_TRY(fapi2::delay(P10_L3_FLUSH_HW_NS_DELAY,
                              P10_L3_FLUSH_SIM_CYCLE_DELAY));

        FAPI_TRY(GET_L3_MISC_L3CERRS_PRD_PURGE_REG(i_target, l_purge_reg_data));

        if (!GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(l_purge_reg_data))
        {
            FAPI_DBG("Purge complete!");
            break;
        }
    }

    FAPI_ASSERT(purge_pending_count < P10_L3_FLUSH_TIMEOUT_COUNT,
                fapi2::P10_L3_FLUSH_PURGE_REQ_TIMEOUT_ERR()
                .set_TARGET(i_target)
                .set_PURGETYPE(i_purge_type)
                .set_PURGEADDR(i_purge_addr)
                .set_L3_PRD_PURGE_REG_DATA(l_purge_reg_data),
                "Purge did not complete in time.");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}
