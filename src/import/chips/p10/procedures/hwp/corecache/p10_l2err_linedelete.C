/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_l2err_linedelete.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
///----------------------------------------------------------------------------
///
/// @file p10_l2err_linedelete.C
///
/// @brief Delete the L2 error cache line according to the error extraction
///        information.
///
/// *HWP HW Maintainer: Benjamin Gass <bgass@ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB, PRDF
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_l2err_linedelete.H>
#include <p10_scom_c.H>
#include <p10_l2_flush.H>

//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
fapi2::ReturnCode p10_l2err_linedelete(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const p10_l2err_extract_err_data& i_err_data,
    const uint64_t i_busyCount)
{

    using namespace scomt;
    using namespace scomt::c;

    // mark function entry
    FAPI_DBG("Entering p10_l2err_linedelete: i_busyCount: %ld", i_busyCount);

    fapi2::buffer<uint64_t> l_l2_l2cerrs_prd_purge_reg;

    FAPI_TRY(purgeCompleteCheck(i_target, i_busyCount,
                                l_l2_l2cerrs_prd_purge_reg),
             "Error returned from purgeCompleteCheck()");
    FAPI_DBG("l_l2_l2cerrs_prd_purge_reg: 0x%.16llX",
             l_l2_l2cerrs_prd_purge_reg);

    FAPI_TRY(PREP_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG(i_target));
    SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(l_l2_l2cerrs_prd_purge_reg);
    SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE(0x2, l_l2_l2cerrs_prd_purge_reg);
    SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM(i_err_data.member, l_l2_l2cerrs_prd_purge_reg);
    //Note: the bank is actually 2 bits now, but the figtree was not updated.
    //cgc and bank combined are addr bits 47 to 56
    SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC(i_err_data.real_address_47_56 >> 1, l_l2_l2cerrs_prd_purge_reg);
    SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(i_err_data.real_address_47_56 & 0x1, l_l2_l2cerrs_prd_purge_reg);
    FAPI_TRY(PUT_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG(i_target, l_l2_l2cerrs_prd_purge_reg));

    // Verify purge operation is complete
    FAPI_TRY(purgeCompleteCheck(i_target, i_busyCount,
                                l_l2_l2cerrs_prd_purge_reg),
             "Error returned from purgeCompleteCheck()");
    FAPI_DBG("l_l2_l2cerrs_prd_purge_reg: 0x%.16llX",
             l_l2_l2cerrs_prd_purge_reg);

    // mark HWP exit
fapi_try_exit:
    FAPI_INF("Exiting p10_l2err_linedelete...");
    return fapi2::current_err;
} // p10_l2err_extract
