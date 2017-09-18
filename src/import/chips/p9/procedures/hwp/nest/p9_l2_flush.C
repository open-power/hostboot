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
/// @file p9_l2_flush.C
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

/// See doxygen in header file
fapi2::ReturnCode purgeCompleteCheck(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const uint64_t i_busyCount,
    fapi2::buffer<uint64_t>& o_prdPurgeCmdReg)
{
    FAPI_DBG("Entering purgeCompleteCheck");
    uint64_t l_loopCount = 0;

    do
    {
        FAPI_TRY(fapi2::getScom(i_target, EX_PRD_PURGE_CMD_REG, o_prdPurgeCmdReg),
                 "Error from getScom EX_PRD_PURGE_CMD_REG");

        // Check state of PURGE_CMD_ERR
        FAPI_ASSERT(!o_prdPurgeCmdReg.getBit<EX_PRD_PURGE_CMD_REG_ERR>(),
                    fapi2::P9_PURGE_CMD_REG_ERR()
                    .set_TARGET(i_target)
                    .set_CMD_REG(o_prdPurgeCmdReg),
                    "Purge failed. EX_PRD_PURGE_CMD_REG_ERR set");

        // Check the EX_PRD_PURGE_CMD_REG_BUSY bit from scom register
        if ( !o_prdPurgeCmdReg.getBit(EX_PRD_PURGE_CMD_REG_BUSY) )
        {
            // PURGE is done, get out
            break;
        }
        else
        {
            l_loopCount++;

            if (l_loopCount > i_busyCount)
            {
                // Time out, exit loop
                break;
            }

            // Delay 10ns for each loop
            FAPI_TRY(fapi2::delay(P9_L2_FLUSH_HW_NS_DELAY,
                                  P9_L2_FLUSH_SIM_CYCLE_DELAY),
                     "Fapi Delay call failed.");
        }
    }
    while (1);

    // Error out if still busy
    if (l_loopCount > i_busyCount)
    {
        // engine busy, dump status
        FAPI_DBG("Purge engine busy (reg_busy = %d, busy_on_this = %d,"
                 " sm_busy = %d)",
                 o_prdPurgeCmdReg.getBit<EX_PRD_PURGE_CMD_REG_BUSY>(),
                 o_prdPurgeCmdReg.getBit<EX_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>(),
                 o_prdPurgeCmdReg.getBit<EX_PRD_PURGE_CMD_REG_PRGSM_BUSY>());

        FAPI_ASSERT(false, fapi2::P9_PURGE_COMPLETE_TIMEOUT()
                    .set_TARGET(i_target)
                    .set_COUNT_THRESHOLD(i_busyCount)
                    .set_CMD_REG(o_prdPurgeCmdReg),
                    "Previous purge request has not completed for target");
    }

fapi_try_exit:
    FAPI_DBG("Exiting purgeCompleteCheck - Counter: %d; prdPurgeCmdReg: 0x%.16llX",
             l_loopCount, o_prdPurgeCmdReg);
    return fapi2::current_err;
}

/// See doxygen in header file
fapi2::ReturnCode setupAndTriggerPrdPurge(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const p9core::purgeData_t& i_purgeData,
    fapi2::buffer<uint64_t>& i_prdPurgeCmdReg)
{
    FAPI_DBG("setupAndTriggerPrdPurge: Enter");

    // Start with current CMD reg value
    fapi2::buffer<uint64_t> l_cmdReg = i_prdPurgeCmdReg;

    // Write PURGE_CMD_TRIGGER bit in Purge Engine Command Register
    // ensure PURGE_CMD_TYPE/MEM/CGC/BANK are clear to specify flush
    // of entire cache
    FAPI_DBG("Write L2 Purge Engine Command Register to initiate cache flush");
    l_cmdReg.insert<EX_PRD_PURGE_CMD_REG_TYPE,
                    EX_PRD_PURGE_CMD_REG_TYPE_LEN>(i_purgeData.iv_cmdType);
    l_cmdReg.insert<EX_PRD_PURGE_CMD_REG_MEM,
                    EX_PRD_PURGE_CMD_REG_MEM_LEN>(i_purgeData.iv_cmdMem);
    l_cmdReg.insert<EX_PRD_PURGE_CMD_REG_BANK, 1>(i_purgeData.iv_cmdBank);
    l_cmdReg.insert<EX_PRD_PURGE_CMD_REG_CGC,
                    EQ_PRD_PURGE_CMD_REG_CGC_LEN>(i_purgeData.iv_cmdCGC);
    l_cmdReg.setBit<EX_PRD_PURGE_CMD_REG_TRIGGER>();

    FAPI_TRY(fapi2::putScom(i_target, EX_PRD_PURGE_CMD_REG, l_cmdReg),
             "Error from putScom EX_PRD_PURGE_CMD_REG");

fapi_try_exit:
    FAPI_DBG("setupAndTriggerPrdPurge: Exit");
    return fapi2::current_err;
}

///-----------------------------------------------------------------------------
/// @brief Utility subroutine to initiate L2 cache flush via purge engine.
///
/// @param[in]  i_target    EX target
/// @param[in]  i_purgeData Structure having values for MEM, CGC, BANK
///                         passed by the user
///
/// @return  FAPI2_RC_SUCCESS if purge operation was started,
///          else error code.
///-----------------------------------------------------------------------------
fapi2::ReturnCode l2_flush_start(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const p9core::purgeData_t& i_purgeData)
{
    FAPI_DBG("l2_flush_start: Enter");
    fapi2::buffer<uint64_t> l_cmdReg;

    // Ensure that purge engine is idle before starting flush
    // poll Purge Engine status
    FAPI_TRY(purgeCompleteCheck(i_target, 0, l_cmdReg), // 0 = no wait
             "Error returned from purgeCompleteCheck call");

    FAPI_TRY(setupAndTriggerPrdPurge(i_target, i_purgeData, l_cmdReg),
             "Error returned from setupAndTriggerPrdPurge");

fapi_try_exit:
    FAPI_DBG("l2_flush_start: Exit");
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
    fapi2::buffer<uint64_t> l_cmdReg;

    FAPI_DBG("Entering p9_l2_flush: i_purgeData [iv_cmdType: 0x%x] "
             "[iv_cmdMem : 0x%x] [iv_cmdBank: 0x%x] [iv_cmdCGC : 0x%x]",
             i_purgeData.iv_cmdType, i_purgeData.iv_cmdMem,
             i_purgeData.iv_cmdBank, i_purgeData.iv_cmdCGC);

    // Initiate flush
    FAPI_TRY(l2_flush_start(i_target, i_purgeData),
             "Error returned from l2_flush_start()");

    // Check for purge complete
    FAPI_TRY(purgeCompleteCheck(i_target, P9_L2_FLUSH_MAX_POLLS, l_cmdReg),
             "Error returned from purgeCompleteCheck call");

fapi_try_exit:
    FAPI_DBG("p9_l2_flush: Exit");
    return fapi2::current_err;
}
