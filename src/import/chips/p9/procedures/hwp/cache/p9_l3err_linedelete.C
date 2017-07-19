/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/cache/p9_l3err_linedelete.C $ */
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

///----------------------------------------------------------------------------
///
/// @file p9_l3err_linedelete.H
///
/// @brief Delete the L3 error cache line according to the error extraction
///        information.
///        See header file for detailed description.
///
/// *HWP HWP Owner   : Alex Taft <amtaft@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Quad
/// *HWP Consumed by : PRDF
/// *HWP Level       : 3
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_l3err_linedelete.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>
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
fapi2::ReturnCode l3PurgeCompleteCheck(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const uint64_t i_busyCount,
    fapi2::buffer<uint64_t>& o_prdPurgeReg)
{
    FAPI_DBG("Entering l3PurgeCompleteCheck");

    // Wait EX_PRD_PURGE_CMD_REG_BUSY bit for a max input counter time
    uint64_t l_loopCount = 0;

    do
    {
        FAPI_TRY(fapi2::getScom(i_target, EX_PRD_PURGE_REG, o_prdPurgeReg),
                 "Error from getScom EX_PRD_PURGE_REG");

        // Check the EX_PRD_PURGE_CMD_REG_BUSY bit from scom register
        if ( !o_prdPurgeReg.getBit(EX_PRD_PURGE_REG_L3_REQ) )
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
                fapi2::P9_L3ERR_LINE_DELETE_REG_BUSY()
                .set_TARGET(i_target)
                .set_COUNT_THRESHOLD(i_busyCount)
                .set_PRD_PURGE_REG(o_prdPurgeReg),
                "Error: PRD_PURGE_CMD_REG_BUSY exceeds limit count of %d.",
                i_busyCount);

fapi_try_exit:
    FAPI_DBG("Exiting l3PurgeCompleteCheck - Counter: %d; prdPurgeReg: 0x%.16llX",
             l_loopCount, o_prdPurgeReg);
    return fapi2::current_err;
}

//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
// See doxygen in header file
// TODO: RTC 178071
// See if with some small refactoring we could just call/share the p9_l3_flush
// HWP code/errors to implement this routine?
fapi2::ReturnCode p9_l3err_linedelete(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const p9_l3err_extract_err_data& i_err_data,
    const uint64_t i_busyCount)
{

    // mark function entry
    FAPI_DBG("Entering p9_l3err_linedelete: i_busyCount: %ld", i_busyCount);

    fapi2::buffer<uint64_t> l_l3_l3cerrs_prd_purge_reg;

    //   +---------------------------+
    //   |    L3 Line Delete Scom    |
    //   +---------------------------+
    //   |Bit(s)|  Data              |
    //   +------+--------------------+
    //   |    0 | Trigger            |
    //   +------+--------------------+
    //   |  1:4 | Purge type (ld=0x2)|
    //   +------+--------------------+
    //   |  5:8 | Don't care         |
    //   +------+--------------------+
    //   |    9 | Busy Error         |
    //   +------+--------------------+
    //   |12:16 | Member (1 of 20)   |
    //   +------+--------------------+
    //   |17:28 | CGC (addr 45:56)   |
    //   +------+--------------------+
    //   |29:63 | Don't care         |
    //   +------+--------------------+

    // EXP.L3.L3_MISC.L3CERRS.PRD_PURGE_REG
    // Write member, cgc address into PRD Purge Engine Command Register
    // SCOM Addr: 0x000000001001180E
    // bit 0 is the trigger, the act of writing this bit to 1 sets off the line delete
    // bits 1:4 is ttype 0b0010 = line delete
    // bits 12:16 is the member
    // bits 17:28 is the cgc address

    // Make sure there's no current purge is in progress
    FAPI_TRY(l3PurgeCompleteCheck(i_target, i_busyCount,
                                  l_l3_l3cerrs_prd_purge_reg),
             "Error returned from l3PurgeCompleteCheck()");
    FAPI_DBG("l_l3_l3cerrs_prd_purge_reg: 0x%.16llX",
             l_l3_l3cerrs_prd_purge_reg);


    l_l3_l3cerrs_prd_purge_reg.insertFromRight
    <EX_PRD_PURGE_REG_L3_MEMBER, EX_PRD_PURGE_REG_L3_MEMBER_LEN>
    (i_err_data.member);
    l_l3_l3cerrs_prd_purge_reg.insertFromRight
    <EX_PRD_PURGE_REG_L3_DIR_ADDR, EX_PRD_PURGE_REG_L3_DIR_ADDR_LEN>
    (i_err_data.hashed_real_address_45_56);
    l_l3_l3cerrs_prd_purge_reg.insertFromRight<EX_PRD_PURGE_REG_L3_REQ, 1>(1);
    l_l3_l3cerrs_prd_purge_reg.insertFromRight
    <EX_PRD_PURGE_REG_L3_TTYPE, EX_PRD_PURGE_REG_L3_TTYPE_LEN>(0x2);

    FAPI_DBG("l_l3_l3cerrs_prd_purge_reg_data: %#lx", l_l3_l3cerrs_prd_purge_reg);
    FAPI_TRY(fapi2::putScom(i_target, EX_PRD_PURGE_REG, l_l3_l3cerrs_prd_purge_reg),
             "Error from putScom (l_l3_l3cerrs_prd_purge_reg)");

    // Verify purge operation is complete
    FAPI_TRY(l3PurgeCompleteCheck(i_target, i_busyCount,
                                  l_l3_l3cerrs_prd_purge_reg),
             "Error returned from l3PurgeCompleteCheck()");
    FAPI_DBG("l_l3_l3cerrs_prd_purge_reg: 0x%.16llX",
             l_l3_l3cerrs_prd_purge_reg);

    // mark HWP exit
fapi_try_exit:
    FAPI_INF("Exiting p9_l3err_linedelete...");
    return fapi2::current_err;
} // p9_l3err_extract
