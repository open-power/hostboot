/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_l3err_linedelete.C $ */
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
/// @file p10_l3err_linedelete.H
///
/// @brief Delete the L3 error cache line according to the error extraction
///        information.
///
/// *HWP HW Maintainer: Benjamin Gass <bgass@ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB, PRDF
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_l3err_linedelete.H>
#include <p10_scom_c.H>
//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint32_t BUSY_POLL_DELAY_IN_NS = 10000000; // 10ms
const uint32_t BUSY_POLL_DELAY_IN_CYCLES = 20000000; // 10ms, assumming 2GHz

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
///
/// @brief  Utility function to check for a L3 purge operation to be completed.
///         This function polls the EX_PRD_PURGE_REG_L3_REQ bit of
///         EX_PRD_PURGE_REG.
///           - If this bit is clear before the input loop threshold is
///             reached, it returns FAPi2_RC_SUCCESS.
///           - Otherwise, it returns an error code.
///
/// @param[in]  i_target          => EX chiplet target
/// @param[in]  i_busyCount       => Max busy count waiting for PURGE to complete.
/// @param[out] o_prdPurgeReg     => EX_PRD_PURGE_CMD_REG value.
///
fapi2::ReturnCode p10_l3err_chkpurge(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const uint64_t i_busyCount,
    fapi2::buffer<uint64_t>& o_prdPurgeReg)
{
    FAPI_DBG("Entering p10_l3err_chkpurge");

    using namespace scomt;
    using namespace scomt::c;

    // Wait EX_PRD_PURGE_CMD_REG_BUSY bit for a max input counter time
    uint64_t l_loopCount = 0;

    do
    {
        FAPI_TRY(GET_L3_MISC_L3CERRS_PRD_PURGE_REG(i_target, o_prdPurgeReg));

        // Check the EX_PRD_PURGE_CMD_REG_BUSY bit from scom register
        if ( !GET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(o_prdPurgeReg) )
        {
            // PURGE is done, get out
            break;
        }
        else
        {
            l_loopCount++;
            // Delay for 10ms
            FAPI_TRY(fapi2::delay(BUSY_POLL_DELAY_IN_NS,
                                  BUSY_POLL_DELAY_IN_CYCLES),
                     "Fapi Delay call failed.");
        }
    }
    while (l_loopCount < i_busyCount);

    // Error out if still busy
    FAPI_ASSERT(l_loopCount < i_busyCount,
                fapi2::P10_L3ERR_LINE_DELETE_REG_BUSY()
                .set_TARGET(i_target)
                .set_COUNT_THRESHOLD(i_busyCount)
                .set_PRD_PURGE_REG(o_prdPurgeReg),
                "Error: PRD_PURGE_CMD_REG_BUSY exceeds limit count of %d.",
                i_busyCount);

fapi_try_exit:
    FAPI_DBG("Exiting p10_l3err_chkpurge - Counter: %d; prdPurgeReg: 0x%.16llX",
             l_loopCount, o_prdPurgeReg);
    return fapi2::current_err;
}

//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
fapi2::ReturnCode p10_l3err_linedelete(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const p10_l3err_extract_err_data& i_err_data,
    const uint64_t i_busyCount)
{

    using namespace scomt;
    using namespace scomt::c;

    // mark function entry
    FAPI_DBG("Entering p10_l3err_linedelete: i_busyCount: %ld", i_busyCount);

    fapi2::buffer<uint64_t> l_l3_l3cerrs_prd_purge_reg;

    FAPI_TRY(p10_l3err_chkpurge(i_target, i_busyCount,
                                l_l3_l3cerrs_prd_purge_reg),
             "Error returned from p10_l3err_chkpurge()");
    FAPI_DBG("l_l3_l3cerrs_prd_purge_reg: 0x%.16llX",
             l_l3_l3cerrs_prd_purge_reg);

    FAPI_TRY(PREP_L3_MISC_L3CERRS_PRD_PURGE_REG(i_target));
    SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ(l_l3_l3cerrs_prd_purge_reg);
    SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE(0x2, l_l3_l3cerrs_prd_purge_reg);
    SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER(i_err_data.member, l_l3_l3cerrs_prd_purge_reg);
    SET_L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR(i_err_data.real_address_46_57 >> 1, l_l3_l3cerrs_prd_purge_reg);
    FAPI_TRY(PUT_L3_MISC_L3CERRS_PRD_PURGE_REG(i_target, l_l3_l3cerrs_prd_purge_reg));

    // Verify purge operation is complete
    FAPI_TRY(p10_l3err_chkpurge(i_target, i_busyCount,
                                l_l3_l3cerrs_prd_purge_reg),
             "Error returned from p10_l3err_chkpurge()");
    FAPI_DBG("l_l3_l3cerrs_prd_purge_reg: 0x%.16llX",
             l_l3_l3cerrs_prd_purge_reg);

    // mark HWP exit
fapi_try_exit:
    FAPI_INF("Exiting p10_l3err_linedelete...");
    return fapi2::current_err;
} // p10_l3err_extract
