/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_l2_flush.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_l2_flush.H
/// @brief Flush the P9 L2 cache (FAPI)
///
/// *HWP HWP Owner   : Benjamin Gass <bgass@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Quad
/// *HWP Consumed by : FSP and SBE
/// *HWP Level       : 3
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_l2_flush.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// polling constants
enum
{
    P9_L2_FLUSH_HW_NS_DELAY     = 10000, // unit is nano seconds
    P9_L2_FLUSH_SIM_CYCLE_DELAY = 12000, // unit is cycles
    P9_L2_FLUSH_MAX_POLLS       = 200    // unit is cycles
};

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///-----------------------------------------------------------------------------
/// @brief Utility subroutine to initiate L2 cache flush via purge engine.
///
/// @param[in]  i_target    EX target
/// @param[in]  i_regAddr   The scom address to use
/// @param[in]  i_purgeData Structure having values for MEM, CGC, BANK
///                         passed by the user
///
/// @return  FAPI2_RC_SUCCESS if purge operation was started,
///          RC_P9_L2_FLUSH_PURGE_REQ_OUTSTANDING if a prior purge
///          operation has not yet completed
///          else FAPI getscom/putscom return code for failing operation
///-----------------------------------------------------------------------------
fapi2::ReturnCode l2_flush_start(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const uint32_t i_regAddr,
    const p9core::purgeData_t& i_purgeData)
{
    fapi2::buffer<uint64_t> l_cmdReg;
    fapi2::buffer<uint64_t> l_purgeCmd;

    FAPI_DBG("l2_flush_start: Enter");

    // ensure that purge engine is idle before starting flush
    // poll Purge Engine status
    FAPI_DBG("Reading L2 Purge Engine Command Register to check status");
    FAPI_TRY(fapi2::getScom(i_target, i_regAddr, l_cmdReg));

    // check to see if this reg is idle and ready to accept a new command
    FAPI_ASSERT(!l_cmdReg.getBit<EX_PRD_PURGE_CMD_REG_BUSY>(),
                fapi2::P9_L2_FLUSH_PURGE_REQ_OUTSTANDING()
                .set_TARGET(i_target)
                .set_CMD_REG(l_cmdReg)
                .set_CMD_REG_ADDR(i_regAddr),
                "Previous purge request has not completed for target");

    // write PURGE_CMD_TRIGGER bit in Purge Engine Command Register
    // ensure PURGE_CMD_TYPE/MEM/CGC/BANK are clear to specify flush
    // of entire cache
    FAPI_DBG("Write L2 Purge Engine Command Register to initiate cache flush");
    l_purgeCmd.insert<EX_PRD_PURGE_CMD_REG_TYPE,
                      EX_PRD_PURGE_CMD_REG_TYPE_LEN>(i_purgeData.iv_cmdType);

    l_purgeCmd.insert<EX_PRD_PURGE_CMD_REG_MEM,
                      EX_PRD_PURGE_CMD_REG_MEM_LEN>(i_purgeData.iv_cmdMem);

    l_purgeCmd.insert<EX_PRD_PURGE_CMD_REG_BANK, 1>(i_purgeData.iv_cmdBank);

    l_purgeCmd.insert<EX_PRD_PURGE_CMD_REG_CGC,
                      EQ_PRD_PURGE_CMD_REG_CGC_LEN>(i_purgeData.iv_cmdCGC);

    l_purgeCmd.setBit<EX_PRD_PURGE_CMD_REG_TRIGGER>();

    FAPI_TRY(fapi2::putScom(i_target, i_regAddr, l_purgeCmd));

fapi_try_exit:
    FAPI_DBG("l2_flush_start: Exit");
    return fapi2::current_err;
}

///-----------------------------------------------------------------------------
/// @brief Utility subroutine to poll L2 purge engine status, looking for
///        clean idle state.
///
/// @param[in] i_target EX chiplet target
/// @param[in] i_regAddr Purge engine register SCOM address
///
/// @return FAPI2_RC_SUCCESS if engine status returns as idle (with no errors)
///         before maximum number of polls has been reached
///         RC_P9_L2_FLUSH_CMD_ERROR
///              if purge command error reported,
///         RC_P9_L2_FLUSH_CMD_TIMEOUT
///              if purge operation did not complete prior to polling limit,
///         else FAPI getscom/putscom return code for failing operation
///-----------------------------------------------------------------------------
fapi2::ReturnCode l2_flush_check_status(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const uint32_t i_regAddr)
{
    fapi2::buffer<uint64_t> l_cmdReg;
    uint32_t l_polls = 1;

    FAPI_DBG("l2_flush_check_status: Enter");

    while(1)
    {
        // poll Purge Engine status
        FAPI_DBG("Reading L2 Purge Engine Command Register to check status");
        FAPI_TRY(fapi2::getScom(i_target, i_regAddr, l_cmdReg));

        // check state of PURGE_CMD_ERR
        FAPI_ASSERT(!l_cmdReg.getBit<EX_PRD_PURGE_CMD_REG_ERR>(),
                    fapi2::P9_L2_FLUSH_CMD_ERROR()
                    .set_TARGET(i_target)
                    .set_CMD_REG(l_cmdReg)
                    .set_CMD_REG_ADDR(i_regAddr),
                    "Purge failed. EX_PRD_PURGE_CMD_REG_ERR set");

        // check to see if this reg is idle and ready to accept a new command
        if (!l_cmdReg.getBit<EX_PRD_PURGE_CMD_REG_BUSY>())
        {
            FAPI_DBG("Purge engine idle");
            break;
        }

        // engine busy, dump status
        FAPI_DBG("Purge engine busy (reg_busy = %d, busy_on_this = %d,"
                 " sm_busy = %d)",
                 l_cmdReg.getBit<EX_PRD_PURGE_CMD_REG_BUSY>(),
                 l_cmdReg.getBit<EX_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>(),
                 l_cmdReg.getBit<EX_PRD_PURGE_CMD_REG_PRGSM_BUSY>());

        // check if loop count has expired
        FAPI_ASSERT((l_polls < P9_L2_FLUSH_MAX_POLLS),
                    fapi2::P9_L2_FLUSH_CMD_TIMEOUT()
                    .set_TARGET(i_target)
                    .set_CMD_REG(l_cmdReg)
                    .set_CMD_REG_ADDR(i_regAddr)
                    .set_NUMBER_OF_ATTEMPTS(l_polls),
                    "Purge engine still busy after %d loops", l_polls);

        // l_polls left, delay prior to next poll
        FAPI_DBG("%d loops done, delaying before next poll", l_polls);

        FAPI_TRY(fapi2::delay(P9_L2_FLUSH_HW_NS_DELAY,
                              P9_L2_FLUSH_SIM_CYCLE_DELAY));

        l_polls++;
    }

fapi_try_exit:
    FAPI_DBG("l2_flush_check_status: Exit");
    return fapi2::current_err;
}

//------------------------------------------------------------------------------
// Hardware Procedure
// See doxygen in header file.
//------------------------------------------------------------------------------
fapi2::ReturnCode p9_l2_flush(
    const fapi2::Target <fapi2::TARGET_TYPE_EX>& i_target,
    const p9core::purgeData_t& i_purgeData)
{
    FAPI_DBG("Entering p9_l2_flush: i_purgeData [iv_cmdType: 0x%x] "
             "[iv_cmdMem : 0x%x] [iv_cmdBank: 0x%x] [iv_cmdCGC : 0x%x]",
             i_purgeData.iv_cmdType, i_purgeData.iv_cmdMem,
             i_purgeData.iv_cmdBank, i_purgeData.iv_cmdCGC);

    uint32_t l_regAddr = EX_PRD_PURGE_CMD_REG;

    // initiate flush
    FAPI_TRY(l2_flush_start(i_target, l_regAddr, i_purgeData));

    // check that flush completes and the purge engine is idle
    // before exiting
    FAPI_TRY(l2_flush_check_status(i_target, l_regAddr));

fapi_try_exit:
    FAPI_DBG("p9_l2_flush: Exit");
    return fapi2::current_err;
}

