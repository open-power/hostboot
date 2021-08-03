/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_l2_flush.C $     */
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
///
/// @file p10_l2_flush.C
/// @brief Flush the P10 L2 cache (FAPI)
///
/// *HWP HW Maintainer: Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
/// *HWP Consumed by  : FSP, SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_l2_flush.H>

#include <p10_scom_c.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// polling constants
enum
{
    P10_L2_FLUSH_HW_NS_DELAY     = 1000000, // unit is nano seconds
    P10_L2_FLUSH_SIM_CYCLE_DELAY = 12000,   // unit is cycles
    P10_L2_FLUSH_MAX_POLLS       = 200      // unit is polls
};

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode purgeCompleteCheck(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const uint64_t i_busyCount,
    fapi2::buffer<uint64_t>& o_prdPurgeCmdReg)
{
    using namespace scomt;
    using namespace scomt::c;

    uint64_t l_loopCount = 0;

    do
    {

        FAPI_TRY(GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG(i_target, o_prdPurgeCmdReg));

        FAPI_ASSERT(!GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(o_prdPurgeCmdReg),
                    fapi2::P10_PURGE_CMD_REG_ERR()
                    .set_TARGET(i_target)
                    .set_CMD_REG(o_prdPurgeCmdReg),
                    "Purge failed. L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR set");

        if (!GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(o_prdPurgeCmdReg))
        {
            break;
        }
        else
        {
            l_loopCount++;

            if (l_loopCount > i_busyCount)
            {
                FAPI_ERR("Purge engine busy (reg_busy = %d, busy_on_this = %d, sm_busy = %d)",
                         GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(o_prdPurgeCmdReg),
                         GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(o_prdPurgeCmdReg),
                         GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(o_prdPurgeCmdReg));

                FAPI_ASSERT(false,
                            fapi2::P10_PURGE_COMPLETE_TIMEOUT()
                            .set_TARGET(i_target)
                            .set_COUNT_THRESHOLD(i_busyCount)
                            .set_CMD_REG(o_prdPurgeCmdReg),
                            "Previous purge request has not completed for target");
            }

            // Delay 10ns for each loop
            FAPI_TRY(fapi2::delay(P10_L2_FLUSH_HW_NS_DELAY,
                                  P10_L2_FLUSH_SIM_CYCLE_DELAY),
                     "Fapi Delay call failed.");
        }
    }
    while (1);

fapi_try_exit:


    FAPI_DBG("Exiting purgeCompleteCheck - Counter: %d; prdPurgeCmdReg: 0x%.16llX",
             l_loopCount, o_prdPurgeCmdReg);
    return fapi2::current_err;
}

/// See doxygen in header file
fapi2::ReturnCode setupAndTriggerPrdPurge(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const p10core::purgeData_t& i_purgeData,
    fapi2::buffer<uint64_t>& i_prdPurgeCmdReg)
{
    using namespace scomt;
    using namespace scomt::c;
    // Start with current CMD reg value
    fapi2::buffer<uint64_t> l_cmdReg = i_prdPurgeCmdReg;
    fapi2::buffer<uint64_t> l_cmdType = i_purgeData.iv_cmdType;
    fapi2::buffer<uint64_t> l_cmdMem = i_purgeData.iv_cmdMem;
    fapi2::buffer<uint64_t> l_cmdBank = i_purgeData.iv_cmdBank;
    fapi2::buffer<uint64_t> l_cmdCGC = i_purgeData.iv_cmdCGC;

    // Write PURGE_CMD_TRIGGER bit in Purge Engine Command Register
    // ensure PURGE_CMD_TYPE/MEM/CGC/BANK are clear to specify flush
    // of entire cache
    FAPI_DBG("Write L2 Purge Engine Command Register to initiate cache flush");

    SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE(l_cmdType, l_cmdReg);
    SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM(l_cmdMem, l_cmdReg);
    SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(l_cmdBank, l_cmdReg);
    SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC(l_cmdCGC, l_cmdReg);
    SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(l_cmdReg);

    FAPI_TRY(PUT_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG(i_target, l_cmdReg));

fapi_try_exit:
    return fapi2::current_err;
}

//------------------------------------------------------------------------------
// Hardware Procedure
// See doxygen in header file.
//------------------------------------------------------------------------------
fapi2::ReturnCode p10_l2_flush(
    const fapi2::Target <fapi2::TARGET_TYPE_CORE>& i_target,
    const p10core::purgeData_t& i_purgeData)
{
    fapi2::buffer<uint64_t> l_cmdReg;
    fapi2::ATTR_ECO_MODE_Type l_eco_mode = fapi2::ENUM_ATTR_ECO_MODE_DISABLED;

    FAPI_DBG("Entering p10_l2_flush: i_purgeData [iv_cmdType: 0x%x] "
             "[iv_cmdMem : 0x%x] [iv_cmdBank: 0x%x] [iv_cmdCGC : 0x%x]",
             i_purgeData.iv_cmdType, i_purgeData.iv_cmdMem,
             i_purgeData.iv_cmdBank, i_purgeData.iv_cmdCGC);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE, i_target, l_eco_mode),
             "Error from FAPI_ATTR_GET (ATTR_ECO_MODE)");

    if (l_eco_mode == fapi2::ENUM_ATTR_ECO_MODE_ENABLED)
    {
        FAPI_INF("Skipping purge on ECO target");
        goto fapi_try_exit;
    }

    FAPI_TRY(purgeCompleteCheck(i_target, 0, l_cmdReg), // 0 = no wait
             "Error returned from purgeCompleteCheck call");

    FAPI_TRY(setupAndTriggerPrdPurge(i_target, i_purgeData, l_cmdReg),
             "Error returned from setupAndTriggerPrdPurge");

    FAPI_TRY(purgeCompleteCheck(i_target, P10_L2_FLUSH_MAX_POLLS, l_cmdReg),
             "Error returned from purgeCompleteCheck call");

fapi_try_exit:
    FAPI_DBG("p10_l2_flush: Exit");
    return fapi2::current_err;
}
