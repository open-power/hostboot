/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_adu_utils.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_adu_utils.C
/// @brief Alter/Display library functions to support adu procedures
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_adu_utils.H>
#include <p10_fbc_utils.H>
#include <fapi2_mem_access.H>
#include <p10_scom_proc.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// Ttype constant variables
const uint32_t ALTD_CMD_TTYPE_CL_DMA_RD  = 0x06; //0b0000110
const uint32_t ALTD_CMD_TTYPE_DMA_PR_WR  = 0x26; //0b0100110
const uint32_t ALTD_CMD_TTYPE_CI_PR_RD   = 0x34; //0b0110100
const uint32_t ALTD_CMD_TTYPE_CI_PR_WR   = 0x37; //0b0110111
const uint32_t ALTD_CMD_TTYPE_PB_OPER    = 0x3F; //0b0111111
const uint32_t ALTD_CMD_TTYPE_PMISC_OPER = 0x31; //0b0110001

// Tsize constant variables
const uint32_t ALTD_CMD_CI_TSIZE_1   =  2; // Secondary encode for ci_pr_rd and ci_pr_wr is
const uint32_t ALTD_CMD_CI_TSIZE_2   =  4; // 0ttt sss0 (where sss represents the tsize)
const uint32_t ALTD_CMD_CI_TSIZE_4   =  6;
const uint32_t ALTD_CMD_CI_TSIZE_8   =  8;
const uint32_t ALTD_CMD_DMAW_TSIZE_1 =  2; // Secondary encode for dma_pr_w is ssss sss0
const uint32_t ALTD_CMD_DMAW_TSIZE_2 =  4; // (where ssss sss represents the tsize)
const uint32_t ALTD_CMD_DMAW_TSIZE_4 =  8;
const uint32_t ALTD_CMD_DMAW_TSIZE_8 = 16;
const uint32_t ALTD_CMD_DMAR_TSIZE   =  0; // Secondary encode is always 0 for cl_dma_rd

// Value for scope for any DMA write operations
const uint32_t ALTD_CMD_SCOPE_GROUP = 0b00000011;

// Values for PB operations
const uint32_t ALTD_CMD_PB_DIS_OPERATION_TSIZE = 0b00001000; // pbop.disable_all w/ fastpath
const uint32_t ALTD_CMD_PB_INIT_OPERATION_TSIZE = 0b00001011; // pbop.enable_all w/ fastpath
const uint32_t ALTD_CMD_SCOPE_SYSTEM = 0b00000101;
const uint32_t ALTD_STATUS_CRESP_VALUE_ACK_DONE = 0x04;

// Values for PMISC operations
const uint32_t ALTD_CMD_PMISC_TSIZE_1 = 0b00000010; // PMISC SWITCH
const uint32_t ALTD_CMD_PMISC_TSIZE_2 = 0b01000000; // PMISC HTM

// OPTION reg values for SWITCH operation
const uint32_t QUIESCE_SWITCH_WAIT_COUNT = 128;
const uint32_t INIT_SWITCH_WAIT_COUNT = 128;

//FORCE ECC Register field/bit definitions
const uint32_t ALTD_DATA_TX_ECC_END_BIT = 16;
const uint32_t ALTD_DATA_ECC_MASK = 0xFFFFull;

// ADU operation delay/polling constants for hw/sim
const uint32_t PROC_ADU_UTILS_ADU_OPER_HW_NS_DELAY       = 10000;
const uint32_t PROC_ADU_UTILS_ADU_OPER_SIM_CYCLE_DELAY   = 50000;
const uint32_t PROC_ADU_UTILS_ADU_STATUS_HW_NS_DELAY     = 100;
const uint32_t PROC_ADU_UTILS_ADU_STATUS_SIM_CYCLE_DELAY = 20000;
const uint32_t PROC_ADU_UTILS_ADU_STATUS_MAX_WAIT_POLLS  = 10;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////
// p10_adu_utils_check_args
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_check_args(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_address,
    const uint32_t i_flags,
    adu_operationFlag& o_flags)
{
    FAPI_DBG("Entering...");

    // process flags and fix unsupported/hazardous options
    o_flags.getFlag(i_flags);

    // Verify flag is valid
    FAPI_ASSERT(o_flags.isFlagValid(),
                fapi2::P10_ADU_UTILS_INVALID_FLAG()
                .set_FLAGS(i_flags),
                "p10_adu_setup: there was an invalid argument passed in when building flag.  Check error trace!");

    // validate transaction size/address and input flag requests
    //  for cache-inhibited/DMA partial operations types that rely on these fields
    if ((o_flags.getOperationType() == adu_operationFlag::CACHE_INHIBIT) ||
        (o_flags.getOperationType() == adu_operationFlag::DMA_PARTIAL))
    {
        adu_operationFlag::Transaction_size_t l_transSize;
        uint32_t l_actualTransSize;

        // Get the transaction size
        l_transSize = o_flags.getTransactionSize();

        // Translate the transaction size to the actual size (1, 2, 4, or 8 bytes)
        if (l_transSize == adu_operationFlag::TSIZE_1)
        {
            l_actualTransSize = 1;
        }
        else if (l_transSize == adu_operationFlag::TSIZE_2)
        {
            l_actualTransSize = 2;
        }
        else if (l_transSize == adu_operationFlag::TSIZE_4)
        {
            l_actualTransSize = 4;
        }
        else
        {
            l_actualTransSize = 8;
        }

        // Check the address alignment
        FAPI_ASSERT(!(i_address & (l_actualTransSize - 1)),
                    fapi2::P10_ADU_UTILS_INVALID_ARGS()
                    .set_TARGET(i_target)
                    .set_ADDRESS(i_address)
                    .set_MAXADDRESS(P10_FBC_UTILS_FBC_MAX_ADDRESS)
                    .set_TSIZE(l_actualTransSize)
                    .set_FLAGS(i_flags),
                    "Address is not cacheline aligned!");

        // Make sure the address is within the ADU bounds
        FAPI_ASSERT(i_address <= P10_FBC_UTILS_FBC_MAX_ADDRESS,
                    fapi2::P10_ADU_UTILS_INVALID_ARGS()
                    .set_TARGET(i_target)
                    .set_ADDRESS(i_address)
                    .set_MAXADDRESS(P10_FBC_UTILS_FBC_MAX_ADDRESS)
                    .set_TSIZE(l_actualTransSize)
                    .set_FLAGS(i_flags),
                    "Address exceeds supported fabric real address range!");

        // ignore fastmode requests for cache inhibited ops
        // this ensures per-transaction completion checks occur for these
        // operations, which may be long running to MMIO resources
        if (o_flags.getOperationType() == adu_operationFlag::CACHE_INHIBIT)
        {
            o_flags.setFastMode(false);
        }

        // ingore auto-increment requests for non-8B transactions
        // ADU auto-increment HW only supports 8B stride
        if (l_transSize != adu_operationFlag::TSIZE_8)
        {
            o_flags.setAutoIncrement(false);
        }

    }
    else
    {
        o_flags.setAutoIncrement(false);
        o_flags.setFastMode(false);
    }

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_check_fbc_state
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_check_fbc_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering...");

    bool fbc_initialized = false;
    bool fbc_running = false;

    // Get the state of the fabric
    FAPI_TRY(p10_fbc_utils_get_fbc_state(i_target, fbc_initialized, fbc_running),
             "Error reading pb_init/pb_stop via p10_fbc_utils_get_fbc_state");

    // Make sure the fabric is initialized and running, otherwise set an error
    FAPI_ASSERT(fbc_initialized && fbc_running,
                fapi2::P10_ADU_FBC_NOT_INITIALIZED()
                .set_TARGET(i_target),
                "Fabric is not initialized or running");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_get_num_granules
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_get_num_granules(
    const uint64_t i_address,
    uint32_t& o_numGranules)
{
    FAPI_DBG("Entering...");

    // From the address figure out when it is going to no longer be within the ADU bound by
    // doing the max fbc address minus the address and then divide by 8 to get number of bytes
    // and by 8 to get number of 8 byte granules that can be sent
    o_numGranules = ((P10_FBC_UTILS_FBC_MAX_ADDRESS - i_address) / 8) / 8;

    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_set_quiesce_init
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_set_quiesce_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::proc;

    FAPI_DBG("Entering...");

    fapi2::buffer<uint64_t> altd_option_reg_data(0);

    // Setup pre-command quiesce; sends a pb quiesce command before executing adu command
    FAPI_TRY(PREP_TP_TPBR_AD_ALTD_OPTION_REG(i_target));

    SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE(altd_option_reg_data);
    SET_TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT(QUIESCE_SWITCH_WAIT_COUNT, altd_option_reg_data);

    // Setup post-command init; sends a pb init command after executing adu command
    SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT(altd_option_reg_data);
    SET_TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT(INIT_SWITCH_WAIT_COUNT, altd_option_reg_data);
    SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH(altd_option_reg_data);

    // Write to ADU special option reg
    FAPI_TRY(PUT_TP_TPBR_AD_ALTD_OPTION_REG(i_target, altd_option_reg_data),
             "Error setting quiesce/init options via PU_ALTD_OPTION_REG register");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_set_switch_action
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_set_switch_action(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_switch_ab,
    const bool i_switch_cd)
{
    using namespace scomt::proc;

    FAPI_DBG("Entering...");

    fapi2::buffer<uint64_t> pmisc_data;

    // Build ADU pMisc Mode register content
    FAPI_DBG("Writing ADU pMisc Mode register: switch_ab=%s, switch_cd=%s",
             i_switch_ab ? "true" : "false", i_switch_cd ? "true" : "false");

    FAPI_TRY(GET_TP_TPBR_AD_SND_MODE_REG(i_target, pmisc_data));

    // Switch AB bit
    SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB(i_switch_ab, pmisc_data);

    // Switch CD bit
    SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD(i_switch_cd, pmisc_data);

    FAPI_TRY(PUT_TP_TPBR_AD_SND_MODE_REG(i_target, pmisc_data),
             "Error writing pb switch actions to PU_SND_MODE_REG register");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_setup_adu
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_setup_adu(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_address,
    const bool i_rnw,
    const adu_operationFlag& i_flags)
{
    using namespace scomt::proc;

    // Print the address and the flag along with start
    FAPI_DBG("Entering... Addr 0x%.16llX", i_address);

    fapi2::buffer<uint64_t> altd_cmd_reg_data(0);
    fapi2::buffer<uint64_t> altd_addr_reg_data(i_address);
    fapi2::buffer<uint64_t> altd_option_reg_data(0);
    adu_operationFlag::OperationType_t l_operType;
    adu_operationFlag::Transaction_size_t l_transSize;
    uint32_t l_altd_cmd_reg_fbc_ttype = 0;
    uint32_t l_altd_cmd_reg_fbc_tsize = 0;

    // Write the address into altd_addr_reg
    FAPI_TRY(PREP_TP_TPBR_AD_ALTD_ADDR_REG(i_target));
    FAPI_TRY(PUT_TP_TPBR_AD_ALTD_ADDR_REG(i_target, altd_addr_reg_data),
             "Error writing to ALTD_ADDR Register");

    // Process input flag
    l_operType = i_flags.getOperationType();
    l_transSize = i_flags.getTransactionSize();

    // Now work on getting the altd cmd register set up; go through all the bits and set/clear as needed
    // this routine assumes the lock is held by the caller, preserve this locked state
    FAPI_TRY(PREP_TP_TPBR_AD_ALTD_CMD_REG(i_target));
    SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED(altd_cmd_reg_data);

    // =========================================
    // === Setting for DMA and CI operations ===
    // =========================================
    if ( (l_operType == adu_operationFlag::CACHE_INHIBIT) ||
         (l_operType == adu_operationFlag::DMA_PARTIAL) )
    {
        // =========================================
        // ====== DMA and CI common settings =======
        // =========================================

        // Set fbc_altd_rnw if it's a read
        if (i_rnw)
        {
            SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW(altd_cmd_reg_data);
        }
        // Clear fbc_altd_rnw if it's a write
        else
        {
            CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW(altd_cmd_reg_data);
        }

        // If auto-inc set the auto-inc bit
        if (i_flags.getAutoIncrement() == true)
        {
            SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC(altd_cmd_reg_data);
        }

        // =========================================
        // ====== CI specific: ttype & tsize =======
        // =========================================
        if (l_operType == adu_operationFlag::CACHE_INHIBIT)
        {
            FAPI_DBG("ADU operation type: Cache Inhibited");

            // Set TTYPE
            if (i_rnw)
            {
                l_altd_cmd_reg_fbc_ttype = ALTD_CMD_TTYPE_CI_PR_RD;
            }
            else
            {
                l_altd_cmd_reg_fbc_ttype = ALTD_CMD_TTYPE_CI_PR_WR;
            }

            // Set TSIZE
            if ( l_transSize == adu_operationFlag::TSIZE_1 )
            {
                l_altd_cmd_reg_fbc_tsize = ALTD_CMD_CI_TSIZE_1;
            }
            else if ( l_transSize == adu_operationFlag::TSIZE_2 )
            {
                l_altd_cmd_reg_fbc_tsize = ALTD_CMD_CI_TSIZE_2;
            }
            else if ( l_transSize == adu_operationFlag::TSIZE_4 )
            {
                l_altd_cmd_reg_fbc_tsize = ALTD_CMD_CI_TSIZE_4;
            }
            else
            {
                l_altd_cmd_reg_fbc_tsize = ALTD_CMD_CI_TSIZE_8;
            }
        }

        // =========================================
        // ====== DMA specific: ttype & tsize ======
        // =========================================
        else
        {
            FAPI_DBG("ADU operation type: DMA");

            // If a read, set ALTD_CMD_TTYPE_CL_DMA_RD
            // Set the tsize to ALTD_CMD_DMAR_TSIZE
            if (i_rnw)
            {
                l_altd_cmd_reg_fbc_ttype = ALTD_CMD_TTYPE_CL_DMA_RD;
                l_altd_cmd_reg_fbc_tsize = ALTD_CMD_DMAR_TSIZE;
            }
            // If a write set ALTD_CMD_TTYPE_DMA_PR_WR
            // Set the tsize according to flag setting
            else
            {
                l_altd_cmd_reg_fbc_ttype = ALTD_CMD_TTYPE_DMA_PR_WR;

                //Set scope to system scope
                SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE(ALTD_CMD_SCOPE_SYSTEM, altd_cmd_reg_data);

                // Set TSIZE
                if ( l_transSize == adu_operationFlag::TSIZE_1 )
                {
                    l_altd_cmd_reg_fbc_tsize = ALTD_CMD_DMAW_TSIZE_1;
                }
                else if ( l_transSize == adu_operationFlag::TSIZE_2 )
                {
                    l_altd_cmd_reg_fbc_tsize = ALTD_CMD_DMAW_TSIZE_2;
                }
                else if ( l_transSize == adu_operationFlag::TSIZE_4 )
                {
                    l_altd_cmd_reg_fbc_tsize = ALTD_CMD_DMAW_TSIZE_4;
                }
                else
                {
                    l_altd_cmd_reg_fbc_tsize = ALTD_CMD_DMAW_TSIZE_8;
                }
            }
        }
    }

    // =========================================
    // == Setting for PB and PMISC operations ==
    // =========================================
    if ( (l_operType == adu_operationFlag::PB_DIS_OPER) ||
         (l_operType == adu_operationFlag::PB_INIT_OPER) ||
         (l_operType == adu_operationFlag::PMISC_OPER) )
    {
        // =========================================
        // ====== PB & PMISC common settings =======
        // =========================================
        // Set the start op bit
        SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP(altd_cmd_reg_data);
        // Set operation scope
        // PB_DIS/PB_INIT/PMISC must be set to system scope, performance is not critical.
        SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE(ALTD_CMD_SCOPE_SYSTEM, altd_cmd_reg_data);
        // Set DROP_PRIORITY = HIGH
        SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY(altd_cmd_reg_data);
        // Set AXTYPE = Address only
        SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE(altd_cmd_reg_data);

        // =========================================
        // ====== PB specific: ttype & tsize =======
        // =========================================
        if ((l_operType == adu_operationFlag::PB_DIS_OPER) ||
            (l_operType == adu_operationFlag::PB_INIT_OPER))
        {
            FAPI_DBG("ADU operation type: PB OPERATION");

            // Set TTYPE
            l_altd_cmd_reg_fbc_ttype = ALTD_CMD_TTYPE_PB_OPER;
            // Set TM_QUIESCE
            SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE(altd_cmd_reg_data);

            if (l_operType == adu_operationFlag::PB_DIS_OPER)
            {
                // TSIZE for PB operation is fixed value: 0b00001000
                l_altd_cmd_reg_fbc_tsize = ALTD_CMD_PB_DIS_OPERATION_TSIZE;
            }
            else
            {
                // Set OVERWRITE_PBINIT
                SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT(altd_cmd_reg_data);

                // TSIZE for PB operation is fixed value: 0b00001011
                l_altd_cmd_reg_fbc_tsize = ALTD_CMD_PB_INIT_OPERATION_TSIZE;
            }
        }

        // =========================================
        // ===== PMISC specific: ttype & tsize =====
        // =========================================
        else
        {
            FAPI_DBG("ADU operation type: PMISC");

            // Set TTYPE
            l_altd_cmd_reg_fbc_ttype = ALTD_CMD_TTYPE_PMISC_OPER;

            // Set TSIZE
            if ( l_transSize == adu_operationFlag::TSIZE_1 )
            {
                l_altd_cmd_reg_fbc_tsize = ALTD_CMD_PMISC_TSIZE_1;

                // Set TM_QUIESCE
                SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE(altd_cmd_reg_data);

                // Set quiesce and init around a switch operation in option reg
                FAPI_TRY(p10_adu_utils_set_quiesce_init(i_target),
                         "Error from p10_adu_utils_set_quiesce_init");

                // Touch altd_cmd_reg again, set_quiesce_init above touches
                // altd_option_reg so any following operations to altd_cmd_reg
                // after this point would fail scom checking
                FAPI_TRY(PREP_TP_TPBR_AD_ALTD_CMD_REG(i_target));
            }
            else if ( l_transSize == adu_operationFlag::TSIZE_2 )
            {
                l_altd_cmd_reg_fbc_tsize = ALTD_CMD_PMISC_TSIZE_2;
            }

        }
    }

    SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE(l_altd_cmd_reg_fbc_ttype, altd_cmd_reg_data);
    SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE(l_altd_cmd_reg_fbc_tsize, altd_cmd_reg_data);

    // Write altd cmd register with the settings that were set above
    FAPI_TRY(PUT_TP_TPBR_AD_ALTD_CMD_REG(i_target, altd_cmd_reg_data),
             "Error launching adu command via ALTD Cmd Register (PU_ALTD_CMD_REG)");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_start_op
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_start_op(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::proc;

    FAPI_DBG("Entering...");

    fapi2::buffer<uint64_t> altd_cmd_reg_data(0);

    // Read the altd_cmd_register
    FAPI_TRY(GET_TP_TPBR_AD_ALTD_CMD_REG(i_target, altd_cmd_reg_data),
             "Error reading from the ALTD_CMD_REG");

    // Set the start op bit
    SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP(altd_cmd_reg_data);

    // Write the altd_cmd_register
    FAPI_TRY(PUT_TP_TPBR_AD_ALTD_CMD_REG(i_target, altd_cmd_reg_data),
             "Error writing to the ALTD_CMD_REG");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_adu_write
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_adu_write(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_firstGranule,
    const bool i_lastGranule,
    const uint64_t i_address,
    const adu_operationFlag& i_flags,
    const uint8_t i_write_data[])
{
    using namespace scomt::proc;

    FAPI_DBG("Entering...");

    fapi2::buffer<uint64_t> altd_cmd_reg_data;
    fapi2::buffer<uint64_t> altd_status_reg_data;
    fapi2::buffer<uint64_t> force_ecc_reg_data;
    uint64_t write_data = 0x0ull;
    int eccIndex = 8;

    // Get ADU operation info from flag
    bool l_itagMode          = i_flags.getItagMode();
    bool l_eccMode           = i_flags.getEccMode();
    bool l_overrideEccMode   = i_flags.getEccItagOverrideMode();
    bool l_autoIncMode       = i_flags.getAutoIncrement();
    bool l_accessForceEccReg = (l_itagMode | l_eccMode | l_overrideEccMode);
    bool l_fastMode          = i_flags.getFastMode();

    // Dump ADU write settings
    FAPI_DBG("Modes: ITAG 0x%.8X, ECC 0x%.8X, OVERRIDE_ECC 0x%.8X, AUTOINC 0x%.8X",
             l_itagMode, l_eccMode, l_overrideEccMode, l_autoIncMode);

    // Get the write data that was passed in as a uint8 into a uint64
    for (int i = 0; i < 8; i++)
    {
        write_data |= ( static_cast<uint64_t>(i_write_data[i]) << (56 - (8 * i)) );
    }

    // Put the uint64 write data into the buffer
    fapi2::buffer<uint64_t> altd_data_reg_data(write_data);

    // If we are doing something with ecc/itag data
    if (l_accessForceEccReg == true)
    {
        // Read the FORCE_ECC register
        FAPI_TRY(GET_TP_TPBR_AD_FORCE_ECC_REG(i_target, force_ecc_reg_data),
                 "Error reading the FORCE_ECC Register");

        // If we want to write the itag bit set that bit
        if (l_itagMode == true)
        {
            eccIndex++;
            SET_TP_TPBR_AD_FORCE_ECC_REG_ITAG(force_ecc_reg_data);
        }

        // If we want to write the ecc data get the data
        if (l_eccMode == true)
        {
            SET_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC((uint64_t)i_write_data[eccIndex], force_ecc_reg_data);
        }

        // If we want to overwrite the ecc data set that bit
        if (l_overrideEccMode == true)
        {
            SET_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE(force_ecc_reg_data);
        }

        // Write to the FORCE_ECC register
        FAPI_TRY(PUT_TP_TPBR_AD_FORCE_ECC_REG(i_target, force_ecc_reg_data),
                 "Error writing to the FORCE_ECC Register");
    }

    // Write the data into the altd_data_reg
    FAPI_TRY(PREP_TP_TPBR_AD_ALTD_DATA_REG(i_target));
    FAPI_TRY(PUT_TP_TPBR_AD_ALTD_DATA_REG(i_target, altd_data_reg_data),
             "Error writing to ALTD_DATA Register");

    // Set the ALTD_CMD_START_OP bit to start the write (first granule for autoinc case or not autoinc)
    if ( i_firstGranule || (l_autoIncMode == false) )
    {
        FAPI_TRY(p10_adu_utils_start_op(i_target), "Error returned from p10_adu_utils_start_op");
    }

    // Delay to allow time for the write to progress
    FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_OPER_HW_NS_DELAY, PROC_ADU_UTILS_ADU_OPER_SIM_CYCLE_DELAY), "fapiDelay error");


    // check status
    if (!l_fastMode || i_lastGranule)
    {
        FAPI_TRY(p10_adu_utils_status_check(i_target, l_autoIncMode && !i_lastGranule, false));
    }

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_adu_read
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_adu_read(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_firstGranule,
    const bool i_lastGranule,
    const uint64_t i_address,
    const adu_operationFlag& i_flags,
    uint8_t o_read_data[])
{
    using namespace scomt::proc;

    FAPI_DBG("Entering...");

    fapi2::buffer<uint64_t> altd_cmd_reg_data;
    fapi2::buffer<uint64_t> altd_status_reg_data;
    fapi2::buffer<uint64_t> altd_data_reg_data;
    fapi2::buffer<uint64_t> force_ecc_reg_data;
    int eccIndex = 8;

    // Get ADU operation info from flag
    bool l_itagMode    = i_flags.getItagMode();
    bool l_eccMode     = i_flags.getEccMode();
    bool l_autoIncMode = i_flags.getAutoIncrement();
    bool l_fastMode    = i_flags.getFastMode();

    // Dump ADU read settings
    FAPI_DBG("Modes: ITAG 0x%.8X, ECC 0x%.8X, AUTOINC 0x%.8X",
             l_itagMode, l_eccMode, l_autoIncMode);

    // Set the ALTD_CMD_START_OP bit to start the read (first granule for autoinc case or not autoinc)
    if ( i_firstGranule || (l_autoIncMode == false) )
    {
        FAPI_TRY(p10_adu_utils_start_op(i_target), "Error returned from p10_adu_utils_start_op");
    }

    // Delay to allow time for the read to progress
    FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_OPER_HW_NS_DELAY, PROC_ADU_UTILS_ADU_OPER_SIM_CYCLE_DELAY), "fapiDelay error");

    // check before every read?
    if (!l_fastMode)
    {
        FAPI_TRY(p10_adu_utils_status_check(i_target, l_autoIncMode && !(i_firstGranule && i_lastGranule), false));
    }

    // If we want to include the itag and ecc data collect them before the read
    if ( l_itagMode || l_eccMode )
    {
        // Read the FORCE_ECC register
        FAPI_TRY(GET_TP_TPBR_AD_FORCE_ECC_REG(i_target, force_ecc_reg_data),
                 "Error reading from the FORCE_ECC Register");

        // If we are reading the itag get that data and put it in the read_data array
        if (l_itagMode)
        {
            eccIndex = 9;
            o_read_data[8] = GET_TP_TPBR_AD_FORCE_ECC_REG_ITAG(force_ecc_reg_data);
        }

        // If we are reading the ecc get that data and put it in the read_data array
        if (l_eccMode)
        {
            o_read_data[eccIndex] = (force_ecc_reg_data >> (63 - ALTD_DATA_TX_ECC_END_BIT)) & ALTD_DATA_ECC_MASK;
        }
    }

    // Read data from altd_data_reg
    FAPI_TRY(GET_TP_TPBR_AD_ALTD_DATA_REG(i_target, altd_data_reg_data),
             "Error reading from the ALTD_DATA Register");

    // Format the uint64 read data into an uint8 array
    for (int i = 0; i < 8; i++)
    {
        o_read_data[i] = (altd_data_reg_data >> (56 - (i * 8))) & 0xFFull;
    }

    // check after last read?
    if (i_lastGranule)
    {
        FAPI_TRY(p10_adu_utils_status_check(i_target, false, false));
    }

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_reset_adu
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_reset_adu(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::proc;

    FAPI_DBG("Entering...");

    fapi2::buffer<uint64_t> altd_cmd_reg_data(0);

    // Get the current value from altd_cmd register
    FAPI_TRY(GET_TP_TPBR_AD_ALTD_CMD_REG(i_target, altd_cmd_reg_data),
             "Error reading from ALTD_CMD Register");

    // Set the reset_fsm, clear_status, and locked bits to do an ADU reset
    SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM(altd_cmd_reg_data);
    SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS(altd_cmd_reg_data);
    SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED(altd_cmd_reg_data);

    // Write the altd_cmd register
    FAPI_TRY(PUT_TP_TPBR_AD_ALTD_CMD_REG(i_target, altd_cmd_reg_data),
             "Error clearing/resetting the adu using the ALTD_CMD Register");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_cleanup_adu
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_cleanup_adu(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::proc;

    FAPI_DBG("Entering...");

    fapi2::buffer<uint64_t> altd_cmd_reg_data(0);

    // Wwrite all zeroes to altd_cmd_reg to cleanup everything
    FAPI_TRY(PREP_TP_TPBR_AD_ALTD_CMD_REG(i_target));
    FAPI_TRY(PUT_TP_TPBR_AD_ALTD_CMD_REG(i_target, altd_cmd_reg_data),
             "Error clearing the ALTD_CMD Register");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_status_check
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_status_check(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_expBusyState,
    const bool i_addrOnlyOper)
{
    FAPI_DBG("Entering...");

    using namespace scomt::proc;

    FAPI_DBG("Entering...");

    fapi2::buffer<uint64_t> l_statusReg(0);
    bool l_statusError = false;

    // Check for a successful status max_wait_poll times
    for (uint32_t i = 0; i < PROC_ADU_UTILS_ADU_STATUS_MAX_WAIT_POLLS; i++)
    {
        l_statusError = false;

        // Read ALTD_STATUS_REG
        FAPI_TRY(GET_TP_TPBR_AD_ALTD_STATUS_REG(i_target, l_statusReg),
                 "Error reading from ALTD_STATUS Register");

        // Check for errors in status register
        l_statusError =
            ( l_statusError
              //Command arbiter did not complete
              || GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(l_statusReg)
              //Address portion of the operation is not complete
              || !GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(l_statusReg)
              //Waiting for a clean combined response (cresp)
              || GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(l_statusReg)
              //New data written before old was used/read w/o new data
              || GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(l_statusReg)
              //Internal address counter rolled over the 0.5M boundary
              || GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(l_statusReg)
              //New command was issued before previous one finished
              || GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(l_statusReg)
              //Invalid address; pb responded with addr_err cresp
              || GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(l_statusReg)
              //Attempt to start a command without pb_init active
              || GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(l_statusReg)
              //ECC Correctable error
              || GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(l_statusReg)
              //ECC Uncorrectable error
              || GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(l_statusReg)
              //ECC Special Uncorrectable error
              || GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(l_statusReg)
            );

        // If address only operation, do not check for PU_ALTD_STATUS_REG_FBC_DATA_DONE otherwise it should be set
        if (i_addrOnlyOper == false)
        {
            l_statusError |= !GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(l_statusReg);
        }

        if (i_expBusyState)
        {
            l_statusError |= !GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(l_statusReg);
        }
        else
        {
            l_statusError |= GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(l_statusReg);
        }

        // Break out of checking status max_wait_poll times if status register is clean
        if (!l_statusError)
        {
            FAPI_DBG("Hooray the adu status register is error free!");
            break;
        }

        // Delay to allow the write/read/other command to finish
        FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_STATUS_HW_NS_DELAY, PROC_ADU_UTILS_ADU_STATUS_SIM_CYCLE_DELAY),
                 "Error with fapiDelay while waiting for adu command completion");
    }

    // Polled the status register for a clean status max_wait_poll number of times;
    // throw errors if the status register is still not clean.

    // Throw an explicit error for address errors if detected
    FAPI_ASSERT(!GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(l_statusReg),
                fapi2::P10_ADU_STATUS_REG_ADDRESS_ERR()
                .set_TARGET(i_target)
                .set_STATUSREG(l_statusReg),
                "Address error detected by ADU Status Register");

    // Otherwise throw a generic error if not an address error
    FAPI_ASSERT(l_statusError == false,
                fapi2::P10_ADU_STATUS_REG_UNEXPECTED_ERR()
                .set_TARGET(i_target)
                .set_STATUSREG(l_statusReg)
                .set_EXP_BUSY_STATE(i_expBusyState)
                .set_ADDR_ONLY_OPER(i_addrOnlyOper),
                "Unexpected state in ADU Status Registers");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_clear_autoinc
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_clear_autoinc(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::proc;

    FAPI_DBG("Entering...");

    fapi2::buffer<uint64_t> altd_cmd_reg_data;

    // Get the value of altd_cmd register
    FAPI_TRY(GET_TP_TPBR_AD_ALTD_CMD_REG(i_target, altd_cmd_reg_data),
             "Error reading from ALTD_CMD Register");

    // Clear the autoinc bit
    CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC(altd_cmd_reg_data);

    // Write to the altd_cmd register with the autoinc bit cleared
    FAPI_TRY(PUT_TP_TPBR_AD_ALTD_CMD_REG(i_target, altd_cmd_reg_data),
             "Error clearing the auto_inc bit from the ALTD_CMD Register");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_manage_lock
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_adu_utils_manage_lock(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_lock_pick,
    const bool i_lock,
    const uint32_t i_num_attempts)
{
    using namespace scomt::proc;

    FAPI_DBG("Entering...");

    fapi2::ReturnCode rc;
    fapi2::buffer<uint64_t> lock_control(0);
    uint32_t attempt_count = 1;
    bool lock_pick_first_time = true;

    // Num_attempts cannot be 0, otherwise throw an error
    if (i_num_attempts == 0)
    {
        FAPI_ERR("Invalid value %d for number of lock manipulation attempts",
                 i_num_attempts);
    }

    FAPI_TRY(PREP_TP_TPBR_AD_ALTD_CMD_REG(i_target));

    // Set up data buffer to perform desired lock manipulation operation
    // If we are locking set the locked bit, reset_fsm bit, and clear_status bit
    if (i_lock)
    {
        FAPI_DBG("Configuring lock manipulation control data buffer to perform lock acquisition");
        SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED(lock_control);
        SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM(lock_control);
        SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS(lock_control);
    }
    else
    {
        FAPI_DBG("Configuring lock manipulation control data buffer to perform lock release");
    }

    // Try to lock/unlock the lock the number of times specified with i_num_attempts
    while (1)
    {
        FAPI_DBG("ADU Lock Attempt %d of %d", attempt_count, i_num_attempts);

        // Write ADU command register to attempt lock manipulation
        FAPI_DBG("Writing ADU Command register to attempt lock manipulation");
        rc = PUT_TP_TPBR_AD_ALTD_CMD_REG(i_target, lock_control);

        // Pass back return code to caller unless it specifically indicates
        // that the ADU lock manipulation was unsuccessful and we're going
        // to try again
        if ((rc != fapi2::FAPI2_RC_PLAT_ERR_ADU_LOCKED) || (attempt_count == i_num_attempts))
        {
            // rc does not indicate success
            if (rc)
            {
                // rc does not indicate lock held, exit
                if (rc != fapi2::FAPI2_RC_PLAT_ERR_ADU_LOCKED)
                {
                    FAPI_ERR("Failed to obtain adu lock due to fapiPutScom error (PU_ALTD_CMD_REG)");
                    break;
                }

                // rc indicates lock held, out of attempts
                if (attempt_count == i_num_attempts)
                {
                    // If out of attempts but lock pick is desired try to pick the lock once and see if it works
                    if (i_lock_pick && i_lock && lock_pick_first_time)
                    {
                        FAPI_DBG("Out of lock attempts, going to try a lock pick as desired");
                        SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK(lock_control);
                        attempt_count--;
                        lock_pick_first_time = false;
                    }
                    // If we are out of attempts and are not trying to pick the lock or if we already picked the lock, error out
                    else
                    {
                        FAPI_ASSERT(false, fapi2::P10_ADU_UTILS_LOCK_ERR()
                                    .set_TARGET(i_target)
                                    .set_LOCK_PICK(i_lock_pick)
                                    .set_LOCK(i_lock)
                                    .set_NUM_ATTEMPTS(i_num_attempts),
                                    "Ran out of lock attempts or failed to pick lock");
                        break;
                    }
                }
            }
            else
            {
                // rc clean, lock management operation successful
                FAPI_DBG("Lock manipulation successful!");
                break;
            }
        }

        // Delay to provide time for ADU lock to be released
        FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_STATUS_HW_NS_DELAY, PROC_ADU_UTILS_ADU_STATUS_SIM_CYCLE_DELAY),
                 "Error with fapiDelay while waiting for adu lock");

        // Increment attempt count, loop again
        attempt_count++;
    }

fapi_try_exit:

    // If there is an error from trying to lock/unlock
    if(rc)
    {
        fapi2::current_err = rc;
    }

    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_adu_utils_append_input_data
////////////////////////////////////////////////////////
void p10_adu_utils_append_input_data(
    const uint64_t i_address,
    const bool i_rnw,
    const uint32_t i_flags,
    fapi2::ReturnCode& o_rc)
{
#ifndef __PPE__
    uint64_t l_address = i_address;
    bool l_rnw = i_rnw;
    uint32_t l_flags = i_flags;
    fapi2::ffdc_t ADDRESS;
    fapi2::ffdc_t RNW;
    fapi2::ffdc_t FLAGS;
    ADDRESS.ptr() = static_cast<void*>(&l_address);
    ADDRESS.size() = sizeof(l_address);
    RNW.ptr() = static_cast<void*>(&l_rnw);
    RNW.size() = sizeof(l_rnw);
    FLAGS.ptr() = static_cast<void*>(&l_flags);
    FLAGS.size() = sizeof(l_flags);

    if ((o_rc == (fapi2::ReturnCode) fapi2::RC_P10_ADU_UTILS_INVALID_ARGS)
        || (o_rc == (fapi2::ReturnCode) fapi2::RC_P10_ADU_FBC_NOT_INITIALIZED)
        || (o_rc == (fapi2::ReturnCode) fapi2::RC_P10_ADU_STATUS_REG_ADDRESS_ERR)
        || (o_rc == (fapi2::ReturnCode) fapi2::RC_P10_ADU_STATUS_REG_UNEXPECTED_ERR)
        || (o_rc == (fapi2::ReturnCode) fapi2::RC_P10_ADU_UTILS_LOCK_ERR))
    {
        FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_P10_ADU_UTILS_EXTRA_INPUT_DATA);
    }

#endif
}
