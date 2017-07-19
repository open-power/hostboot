/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/cache/p9_l2err_linedelete.C $ */
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
/// @file p9_l2err_linedelete.C
///
/// @brief Delete the L2 error cache line according to the error extraction
///        information.
///        See more detailed description in header file.
///
/// *HWP HWP Owner   : Chen Qian <qianqc@cn.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Quad
/// *HWP Consumed by : PRDF
/// *HWP Level       : 3
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_l2err_linedelete.H>
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
/// @brief  Utility function to check for a purge operation to be completed.
///         This function polls the EX_PRD_PURGE_CMD_REG_BUSY bit of
///         EX_PRD_PURGE_CMD_REG.
///           - If this bit is clear before the input loop threshold is
///             reached, it returns FAPi2_RC_SUCCESS.
///           - Otherwise, it returns an error code.
///
/// @param[in]  i_target          => EX chiplet target
/// @param[in]  i_busyCount       => Max busy count waiting for PURGE to complete.
/// @param[out] o_prdPurgeCmdReg  => EX_PRD_PURGE_CMD_REG value.
///
fapi2::ReturnCode purgeCompleteCheck(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const uint64_t i_busyCount,
    fapi2::buffer<uint64_t>& o_prdPurgeCmdReg)
{
    FAPI_DBG("Entering purgeCompleteCheck");

    // Wait EX_PRD_PURGE_CMD_REG_BUSY bit for a max input counter time
    uint64_t l_loopCount = 0;

    do
    {
        FAPI_TRY(fapi2::getScom(i_target, EX_PRD_PURGE_CMD_REG, o_prdPurgeCmdReg),
                 "Error from getScom EX_PRD_PURGE_CMD_REG");

        // Check the EX_PRD_PURGE_CMD_REG_BUSY bit from scom register
        if ( !o_prdPurgeCmdReg.getBit(EX_PRD_PURGE_CMD_REG_BUSY) )
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
                fapi2::P9_L2ERR_LINE_DELETE_REG_BUSY()
                .set_TARGET(i_target)
                .set_COUNT_THRESHOLD(i_busyCount)
                .set_PRD_PURGE_CMD_REG(o_prdPurgeCmdReg),
                "Error: PRD_PURGE_CMD_REG_BUSY exceeds limit count of %d.",
                i_busyCount);

fapi_try_exit:
    FAPI_DBG("Exiting purgeCompleteCheck - Counter: %d; prdPurgeCmdReg: 0x%.16llX",
             l_loopCount, o_prdPurgeCmdReg);
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
// See doxygen in header file
// TODO: RTC 178071
// See if with some small refactoring we could just call/share the p9_l2_flush
// HWP code/errors to implement this routine?
fapi2::ReturnCode p9_l2err_linedelete(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const p9_l2err_extract_err_data& i_err_data,
    const uint64_t i_busyCount)
{
    fapi2::buffer<uint64_t> l_l2_l2cerrs_prd_purge_cmd_reg;

    // mark function entry
    FAPI_DBG("Entering p9_l2err_linedelete. BusyCount %d", i_busyCount);

    //   +---------------------------+
    //   |    L2 Line Delete Scom    |
    //   +---------------------------+
    //   |Bit(s)|  Data              |
    //   +------+--------------------+
    //   |    0 | Trigger            |
    //   +------+--------------------+
    //   |  1:4 | Purge type (LD=0x2)|
    //   +------+--------------------+
    //   | 5:16 | Don't care         |
    //   +------+--------------------+
    //   |17:19 | Member             |
    //   +------+--------------------+
    //   |20:27 | CGC  addr 48:55    |
    //   +------+--------------------+
    //   |   28 | Bank               |
    //   +------+--------------------+
    //   |29:30 | Don't care         |
    //   +------+--------------------+

    // Write member, address and bank into PRD Purge Engine Command Register
    // SCOM Addr: 0x000000001001080E
    // bit 0 is the trigger, the act of writing this bit to 1 sets off the line delete
    // bits 1:4 is ttype 0b0010 = line delete
    // bits 17:19 is the member
    // bits 20:27 is the cgc address
    // bit 28 is the bank

    // Make sure there's no current purge is in progress
    FAPI_TRY(purgeCompleteCheck(i_target, i_busyCount,
                                l_l2_l2cerrs_prd_purge_cmd_reg),
             "Error returned from purgeCompleteCheck()");
    FAPI_DBG("l_l2_l2cerrs_prd_purge_cmd_reg_data: 0x%.16llX",
             l_l2_l2cerrs_prd_purge_cmd_reg);

    // write trigger, type, cgc address and bank into PRD Purge Engine Command Register
    l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight
    <EX_PRD_PURGE_CMD_REG_MEM, EX_PRD_PURGE_CMD_REG_MEM_LEN>
    (i_err_data.member);
    l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight
    <EX_PRD_PURGE_CMD_REG_CGC, EX_PRD_PURGE_CMD_REG_CGC_LEN>
    (i_err_data.address);
    l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight
    <EX_PRD_PURGE_CMD_REG_BANK, 1>(i_err_data.bank);

    l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight
    <EX_PRD_PURGE_CMD_REG_TRIGGER, 1>(1);
    l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight
    <EX_PRD_PURGE_CMD_REG_TYPE, EX_PRD_PURGE_CMD_REG_TYPE_LEN>(0x2);

    FAPI_DBG("l_l2_l2cerrs_prd_purge_cmd_reg_data: %#lx",
             l_l2_l2cerrs_prd_purge_cmd_reg);
    FAPI_TRY(fapi2::putScom(i_target, EX_PRD_PURGE_CMD_REG,
                            l_l2_l2cerrs_prd_purge_cmd_reg),
             "Error from putScom EX_PRD_PURGE_CMD_REG");


    // Verify purge operation is complete
    FAPI_TRY(purgeCompleteCheck(i_target, i_busyCount,
                                l_l2_l2cerrs_prd_purge_cmd_reg),
             "Error returned from purgeCompleteCheck()");
    FAPI_DBG("l_l2_l2cerrs_prd_purge_cmd_reg_data: 0x%.16llX",
             l_l2_l2cerrs_prd_purge_cmd_reg);

fapi_try_exit:
    FAPI_INF("Exiting p9_l2err_linedelete...");
    return fapi2::current_err;
} // p9_l2err_extract
