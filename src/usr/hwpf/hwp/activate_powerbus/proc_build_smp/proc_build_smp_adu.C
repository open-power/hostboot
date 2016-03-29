/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_adu.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
// $Id: proc_build_smp_adu.C,v 1.12 2016/02/05 16:05:39 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_adu.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_build_smp_adu.C
// *! DESCRIPTION : Interface for ADU operations required to support fabric
// *!               configuration actions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_build_smp_adu.H>
#include <proc_adu_utils.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

const uint32_t PROC_BUILD_SMP_MAX_STATUS_POLLS = 5;

const uint32_t PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS = 1;
const bool PROC_BUILD_SMP_PHASE1_ADU_PICK_LOCK = false;
const uint32_t PROC_BUILD_SMP_PHASE1_POST_QUIESCE_DELAY = 128;
const uint32_t PROC_BUILD_SMP_PHASE1_PRE_INIT_DELAY = 128;

const uint32_t PROC_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS = 5;
const bool PROC_BUILD_SMP_PHASE2_ADU_PICK_LOCK = true;
const uint32_t PROC_BUILD_SMP_PHASE2_POST_QUIESCE_DELAY = 4096;
const uint32_t PROC_BUILD_SMP_PHASE2_PRE_INIT_DELAY = 512;

// ADU pMISC Mode register field/bit definitions
const uint32_t ADU_PMISC_MODE_ENABLE_PB_SWITCH_AB_BIT = 30;
const uint32_t ADU_PMISC_MODE_ENABLE_PB_SWITCH_CD_BIT = 31;

// FFDC logging on ADU switch fails
const uint8_t PROC_BUILD_SMP_FFDC_NUM_REGS = 11;
const uint32_t PROC_BUILD_SMP_FFDC_REGS[PROC_BUILD_SMP_FFDC_NUM_REGS] =
{
    PB_MODE_CENT_0x02010C4A,
    PB_HP_MODE_NEXT_CENT_0x02010C4B,
    PB_HP_MODE_CURR_CENT_0x02010C4C,
    PB_HPX_MODE_NEXT_CENT_0x02010C4D,
    PB_HPX_MODE_CURR_CENT_0x02010C4E,
    X_GP0_0x04000000,
    PB_X_MODE_0x04010C0A,
    A_GP0_0x08000000,
    ADU_IOS_LINK_EN_0x02020019,
    PB_A_MODE_0x0801080A,
    ADU_PMISC_MODE_0x0202000B
};
enum proc_build_smp_ffdc_reg_index
{
    PB_MODE_CENT_DATA_INDEX = 0,
    PB_HP_MODE_NEXT_CENT_DATA_INDEX = 1,
    PB_HP_MODE_CURR_CENT_DATA_INDEX = 2,
    PB_HPX_MODE_NEXT_CENT_DATA_INDEX = 3,
    PB_HPX_MODE_CURR_CENT_DATA_INDEX = 4,
    X_GP0_DATA_INDEX = 5,
    PB_X_MODE_DATA_INDEX = 6,
    A_GP0_DATA_INDEX = 7,
    ADU_IOS_LINK_EN_DATA_INDEX = 8,
    PB_A_MODE_DATA_INDEX = 9,
    ADU_PMISC_MODE_DATA_INDEX = 10
};


extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: set action which will occur on fabric pmisc switch command
// parameters: i_target    => P8 chip target
//             i_switch_ab => perform switch AB operation?
//             i_switch_cd => perform switch CD operation?
// returns: FAPI_RC_SUCCESS if action is configured successfully,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_adu_set_switch_action(
    const fapi::Target& i_target,
    const bool i_switch_ab,
    const bool i_switch_cd)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase pmisc_data(64), pmisc_mask(64);

    FAPI_DBG("proc_build_smp_adu_set_switch_action: Start");
    do
    {
        // build ADU pMisc Mode register content
        FAPI_DBG("proc_build_smp_adu_set_switch_action: Writing ADU pMisc Mode register");
        // switch AB bit
        rc_ecmd |= pmisc_data.writeBit(
            ADU_PMISC_MODE_ENABLE_PB_SWITCH_AB_BIT,
            i_switch_ab);
        rc_ecmd |= pmisc_mask.setBit(
            ADU_PMISC_MODE_ENABLE_PB_SWITCH_AB_BIT);
        // switch CD bit
        rc_ecmd |= pmisc_data.writeBit(
            ADU_PMISC_MODE_ENABLE_PB_SWITCH_CD_BIT,
            i_switch_cd);
        rc_ecmd |= pmisc_mask.setBit(
            ADU_PMISC_MODE_ENABLE_PB_SWITCH_CD_BIT);

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_adu_set_switch_action: Error 0x%x setting up ADU pMisc Mode register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        // write ADU pMisc Mode register content
        rc = fapiPutScomUnderMask(i_target,
                                  ADU_PMISC_MODE_0x0202000B,
                                  pmisc_data,
                                  pmisc_mask);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_adu_set_switch_action: fapiPutScomUnderMask error (ADU_PMISC_MODE_0x0202000B)");
            break;
        }
    } while(0);

    FAPI_DBG("proc_build_smp_adu_set_switch_action: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: acquire ADU atomic lock to guarantee exclusive use of its
//           resources
// parameters: i_target         => P8 chip target
//             i_adu_lock_tries => number of lock acquisistions to attempt
//             i_adu_pick_lock  => attempt lock pick if lock acquisition
//                                 is unsuccessful after i_adu_lock_tries?
// returns: FAPI_RC_SUCCESS if lock is successfully acquired,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_OPERATION if an unsupported operation
//              is specified,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_ATTEMPTS if invalid number of attempts
//              is specified,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_adu_acquire_lock(
    const fapi::Target& i_target,
    const uint32_t& i_adu_lock_tries,
    const bool& i_adu_pick_lock)
{
    fapi::ReturnCode rc;
    proc_adu_utils_adu_lock_operation lock_op = ADU_LOCK_ACQUIRE;

    FAPI_DBG("proc_build_smp_adu_acquire_lock: Start");

    do
    {
        // attempt ADU lock acquisition
        FAPI_DBG("proc_build_smp_adu_acquire_lock: Calling library to acquire ADU lock");
        rc = proc_adu_utils_manage_adu_lock(i_target,
                                            lock_op,
                                            i_adu_lock_tries);

        // return code specifically indicates lock acquisition was not
        // successful because ADU lock is held by another entity
        if (rc == fapi::FAPI_RC_PLAT_ERR_ADU_LOCKED)
        {
            FAPI_INF("proc_build_smp_adu_acquire_lock: Unable to acquire ADU lock after %d tries",
                     i_adu_lock_tries);

            // give up if lock pick is not specified
            if (!i_adu_pick_lock)
            {
                FAPI_ERR("proc_build_smp_adu_acquire_lock: ADU lock acquisition unsuccessful, giving up without attempting to pick lock");
                break;
            }
            // otherwise make single lock pick attempt
            else
            {
                FAPI_DBG("proc_build_smp_adu_acquire_lock: Calling library to pick ADU lock");
                lock_op = ADU_LOCK_FORCE_ACQUIRE;
                rc = proc_adu_utils_manage_adu_lock(i_target,
                                                    lock_op,
                                                    1);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_adu_acquire_lock: Error from proc_adu_utils_manage_adu_lock");
                    break;
                }
            }
        }
        // flag error on any other return code that is not OK
        else if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_adu_acquire_lock: Error from proc_adu_utils_manage_adu_lock");
            break;
        }
    } while(0);

    FAPI_DBG("proc_build_smp_adu_acquire_lock: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: reset ADU state machines and status register
//           NOTE: intended to be run while holding ADU lock
// parameters: i_target => P8 chip target
// returns: FAPI_RC_SUCCESS if fabric is not stopped,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_adu_reset(
    const fapi::Target& i_target)
{
    fapi::ReturnCode rc;

    FAPI_DBG("proc_build_smp_adu_reset: Start");
    do
    {
        // call ADU library function
        FAPI_DBG("proc_build_smp_adu_reset: Calling library to reset ADU");
        rc = proc_adu_utils_reset_adu(i_target);
        if (!rc.ok()) {
            FAPI_ERR("proc_build_smp_adu_reset: Error from proc_adu_utils_reset_adu");
        }
    } while(0);

    FAPI_DBG("proc_build_smp_adu_reset: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: release ADU atomic lock
//           NOTE: intended to be run while holding ADU lock
// parameters: i_target           => P8 chip target
//             i_adu_unlock_tries => number of lock releases to attempt
// returns: FAPI_RC_SUCCESS if lock is successfully released,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_OPERATION if an unsupported operation
//              is specified,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_ATTEMPTS if invalid number of attempts
//              is specified,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_adu_release_lock(
    const fapi::Target& i_target,
    const uint32_t& i_adu_unlock_tries)
{
    fapi::ReturnCode rc;

    FAPI_DBG("proc_build_smp_adu_release_lock: Start");

    do
    {
        // attempt ADU lock acquisition
        FAPI_DBG("proc_build_smp_adu_release_lock: Calling library to release ADU lock");
        rc = proc_adu_utils_manage_adu_lock(i_target,
                                            ADU_LOCK_RELEASE,
                                            i_adu_unlock_tries);

        // return code specifically indicates lock release was not
        // successful because ADU lock is held by another entity
        if (rc == fapi::FAPI_RC_PLAT_ERR_ADU_LOCKED)
        {
            FAPI_INF("proc_build_smp_adu_release_lock: Unable to release ADU lock after %d tries",
                     i_adu_unlock_tries);
            FAPI_ERR("proc_build_smp_adu_release_lock: ADU lock release unsuccessful");
            break;
        }
        // flag error on any other return code that is not OK
        else if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_adu_release_lock: Error from proc_adu_utils_manage_adu_lock");
            break;
        }
    } while(0);

    FAPI_DBG("proc_build_smp_adu_release_lock: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: check ADU status matches expected state/value
//           NOTE: intended to be run while holding ADU lock
// parameters: i_target           => P8 chip target
//             i_smp              => structure encapsulating SMP topology
//             i_dump_all_targets => dump FFDC for all targets in SMP?
//                                   true=yes, false=no, only for i_target
// returns: FAPI_RC_SUCCESS if status matches expected value,
//          RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH if status mismatches,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_adu_check_status(
    const fapi::Target& i_target,
    proc_build_smp_system& i_smp,
    const bool i_dump_all_targets)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    proc_adu_utils_adu_status status;
    bool match = false;
    uint8_t num_polls = 0;

    FAPI_DBG("proc_build_smp_adu_check_status: Start");
    do
    {
        // retreive actual status value
        while (num_polls < PROC_BUILD_SMP_MAX_STATUS_POLLS)
        {
            FAPI_DBG("proc_build_smp_adu_check_status: Calling library to read ADU status (poll %d)",
                     num_polls+1);
            rc = proc_adu_utils_get_adu_status(i_target,
                                               false,
                                               status);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_adu_check_status: Error from proc_adu_utils_get_adu_status");
                break;
            }

            // status reported as busy, poll again
            if (status.busy)
            {
                num_polls++;
            }
            // not busy, check for expected status
            else
            {
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }

        // check status bits versus expected pattern
        match =
            ((status.busy == ADU_STATUS_BIT_CLEAR) &&
             (status.wait_cmd_arbit == ADU_STATUS_BIT_CLEAR) &&
             (status.addr_done == ADU_STATUS_BIT_SET) &&
             (status.data_done == ADU_STATUS_BIT_CLEAR) &&
             (status.wait_resp == ADU_STATUS_BIT_CLEAR) &&
             (status.overrun_err == ADU_STATUS_BIT_CLEAR) &&
             (status.autoinc_err == ADU_STATUS_BIT_CLEAR) &&
             (status.command_err == ADU_STATUS_BIT_CLEAR) &&
             (status.address_err == ADU_STATUS_BIT_CLEAR) &&
             (status.command_hang_err == ADU_STATUS_BIT_CLEAR) &&
             (status.data_hang_err == ADU_STATUS_BIT_CLEAR));
        if (!match)
        {
            FAPI_ERR("proc_adu_utils_check_adu_status: Status mismatch detected");
            FAPI_ERR("proc_adu_utils_check_adu_status: ADU Status bits:");
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_BUSY           = %d",
                     (status.busy == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_WAIT_CMD_ARBIT = %d",
                     (status.wait_cmd_arbit == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_ADDR_DONE      = %d",
                     (status.addr_done == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_DATA_DONE      = %d",
                     (status.data_done == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_WAIT_RESP      = %d",
                     (status.wait_resp == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status: ADU Error bits:");
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_OVERRUN_ERROR        = %d",
                     (status.overrun_err == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_AUTOINC_ERROR        = %d",
                     (status.autoinc_err == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_COMMAND_ERROR        = %d",
                     (status.command_err == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_ADDRESS_ERROR        = %d",
                     (status.address_err == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_COMMAND_HANG_ERROR   = %d",
                     (status.command_hang_err == ADU_STATUS_BIT_SET)?(1)
                                                                        :(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_DATA_HANG_ERROR      = %d",
                     (status.data_hang_err == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_PBINIT_MISSING_ERROR = %d",
                     (status.pbinit_missing == ADU_STATUS_BIT_SET)?(1):(0));

            // dump FFDC
            // there is no clean way to represent the collection in XML (given an arbitrary number of chips),
            // so collect manually and store into data buffers which can be post-processed from the error log
            std::map<proc_fab_smp_node_id, proc_build_smp_node>::iterator n_iter;
            std::map<proc_fab_smp_chip_id, proc_build_smp_chip>::iterator p_iter;
            std::vector<fapi::Target*> targets_to_collect;
            std::vector<bool> nv_present;
            ecmdDataBufferBase scom_data(64);
            ecmdDataBufferBase chip_ids;
            ecmdDataBufferBase ffdc_reg_data[PROC_BUILD_SMP_FFDC_NUM_REGS];
            bool ffdc_scom_error = false;

            // determine set of chips to collect
            for (n_iter = i_smp.nodes.begin();
                 n_iter != i_smp.nodes.end();
                 n_iter++)
            {
                for (p_iter = n_iter->second.chips.begin();
                     p_iter != n_iter->second.chips.end();
                     p_iter++)
                {
                    if (i_dump_all_targets ||
                        (p_iter->second.chip->this_chip == i_target))
                    {
                        nv_present.push_back(p_iter->second.nv_present);
                        targets_to_collect.push_back(&(p_iter->second.chip->this_chip));
                    }
                }
            }

            // size FFDC buffers
            rc_ecmd |= chip_ids.setByteLength(targets_to_collect.size());
            for (uint8_t i = 0; i < PROC_BUILD_SMP_FFDC_NUM_REGS; i++)
            {
                rc_ecmd |= ffdc_reg_data[i].setDoubleWordLength(targets_to_collect.size());
            }

            // extract FFDC data
            std::vector<bool>::iterator n = nv_present.begin();
            for (std::vector<fapi::Target*>::iterator t = targets_to_collect.begin();
                 t != targets_to_collect.end();
                 t++, n++)
            {
                // log node/chip ID
                for (n_iter = i_smp.nodes.begin();
                     n_iter != i_smp.nodes.end();
                     n_iter++)
                {
                    for (p_iter = n_iter->second.chips.begin();
                         p_iter != n_iter->second.chips.end();
                         p_iter++)
                    {
                        if ((&(p_iter->second.chip->this_chip)) == *t)
                        {
                            uint8_t id = ((n_iter->first & 0x3) << 4) |
                                (p_iter->first & 0x3);

                            rc_ecmd |= chip_ids.setByte(t - targets_to_collect.begin(), id);
                        }
                    }
                }

                // collect SCOM data
                for (uint8_t i = 0; i < PROC_BUILD_SMP_FFDC_NUM_REGS; i++)
                {
                    // skip A / F link registers if NV link logic is present
                    if ((*n) &&
                        ((i == static_cast<uint8_t>(A_GP0_DATA_INDEX)) ||
                         (i == static_cast<uint8_t>(ADU_IOS_LINK_EN_DATA_INDEX)) ||
                         (i == static_cast<uint8_t>(PB_A_MODE_DATA_INDEX))))
                    {
                        rc_ecmd |= scom_data.flushTo1();
                    }
                    else
                    {
                        rc = fapiGetScom(*(*t), PROC_BUILD_SMP_FFDC_REGS[i], scom_data);
                        if (!rc.ok())
                        {
                            ffdc_scom_error = true;
                        }
                    }

                    rc_ecmd |= scom_data.extractPreserve(
                        ffdc_reg_data[i],
                        0, 64,
                        64*(t - targets_to_collect.begin()));
                }
            }

            const fapi::Target& TARGET = i_target;
            const proc_adu_utils_adu_status& ADU_STATUS_DATA = status;
            const uint8_t& ADU_NUM_POLLS = num_polls;
            const uint8_t& NUM_CHIPS = targets_to_collect.size();
            const uint8_t& FFDC_VALID = !rc_ecmd && !ffdc_scom_error;
            const ecmdDataBufferBase& CHIP_IDS = chip_ids;
            const ecmdDataBufferBase& PB_MODE_CENT_DATA = ffdc_reg_data[0];
            const ecmdDataBufferBase& PB_HP_MODE_NEXT_CENT_DATA = ffdc_reg_data[1];
            const ecmdDataBufferBase& PB_HP_MODE_CURR_CENT_DATA = ffdc_reg_data[2];
            const ecmdDataBufferBase& PB_HPX_MODE_NEXT_CENT_DATA = ffdc_reg_data[3];
            const ecmdDataBufferBase& PB_HPX_MODE_CURR_CENT_DATA = ffdc_reg_data[4];
            const ecmdDataBufferBase& X_GP0_DATA = ffdc_reg_data[5];
            const ecmdDataBufferBase& PB_X_MODE_DATA = ffdc_reg_data[6];
            const ecmdDataBufferBase& A_GP0_DATA = ffdc_reg_data[7];
            const ecmdDataBufferBase& ADU_IOS_LINK_EN_DATA = ffdc_reg_data[8];
            const ecmdDataBufferBase& PB_A_MODE_DATA = ffdc_reg_data[9];
            const ecmdDataBufferBase& ADU_PMISC_MODE_DATA = ffdc_reg_data[10];
            FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH);
            break;
        }
    } while(0);

    FAPI_DBG("proc_build_smp_adu_check_status: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_switch_cd(
    proc_build_smp_chip& i_smp_chip,
    proc_build_smp_system& i_smp)
{
    fapi::ReturnCode rc;
    // ADU status/control information
    proc_adu_utils_fbc_op adu_ctl;
    proc_adu_utils_fbc_op_hp_ctl adu_hp_ctl;
    bool adu_is_dirty = false;

    // mark function entry
    FAPI_DBG("proc_build_smp_switch_cd: Start");

    do
    {
        FAPI_DBG("proc_build_smp_switch_cd: Acquiring lock for ADU");
        // acquire ADU lock
        // only required to obtain lock for this chip, as this function will
        // only be executed when fabric is configured as single chip island
        rc = proc_build_smp_adu_acquire_lock(
            i_smp_chip.chip->this_chip,
            PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS,
            PROC_BUILD_SMP_PHASE1_ADU_PICK_LOCK);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_cd: Error from proc_build_smp_adu_acquire_lock");
            break;
        }
        // NOTE: lock is now held, if an operation fails from this point
        //       to the end of the procedure:
        //       o attempt to cleanup/release lock (so that procedure does not
        //         leave the ADU in a locked state)
        //       o return rc of original fail
        adu_is_dirty = true;

        // reset ADU
        rc = proc_build_smp_adu_reset(i_smp_chip.chip->this_chip);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_cd: Error from proc_build_smp_adu_reset");
            break;
        }
        FAPI_DBG("proc_build_smp_switch_cd: ADU lock held");

        // condition for switch CD operation
        rc = proc_build_smp_adu_set_switch_action(
            i_smp_chip.chip->this_chip,
            false,
            true);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_cd: Error from proc_build_smp_adu_set_switch_action (set)");
            break;
        }

        // build ADU control structure
        adu_ctl.ttype = ADU_FBC_OP_TTYPE_PMISC;
        adu_ctl.tsize = ADU_FBC_OP_TSIZE_PMISC_SWITCH_AB;
        adu_ctl.address = 0x0ULL;
        adu_ctl.scope = ADU_FBC_OP_SCOPE_SYSTEM;
        adu_ctl.drop_priority = ADU_FBC_OP_DROP_PRIORITY_HIGH;
        adu_ctl.cmd_type = ADU_FBC_OP_CMD_ADDR_ONLY;
        adu_ctl.init_policy = ADU_FBC_OP_FBC_INIT_OVERRIDE;
        adu_ctl.use_autoinc = false;

        adu_hp_ctl.do_tm_quiesce = true;
        adu_hp_ctl.do_pre_quiesce = true;
        adu_hp_ctl.do_post_init = true;
        adu_hp_ctl.post_quiesce_delay = PROC_BUILD_SMP_PHASE1_POST_QUIESCE_DELAY;
        adu_hp_ctl.pre_init_delay = PROC_BUILD_SMP_PHASE1_PRE_INIT_DELAY;

        // launch command
        FAPI_DBG("proc_build_smp_switch_cd: Issuing switch CD from %s",
                 i_smp_chip.chip->this_chip.toEcmdString());
        rc = proc_adu_utils_send_fbc_op(i_smp_chip.chip->this_chip,
                                        adu_ctl,
                                        true,
                                        adu_hp_ctl);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_cd: Error from proc_adu_utils_send_fbc_op");
            break;
        }

        // check status
        rc = proc_build_smp_adu_check_status(i_smp_chip.chip->this_chip, i_smp, false);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_cd: Error from proc_build_smp_adu_check_status");
            break;
        }

        // reset switch controls
        rc = proc_build_smp_adu_set_switch_action(
            i_smp_chip.chip->this_chip,
            false,
            false);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_cd: Error from proc_build_smp_adu_set_switch_action (reset)");
            break;
        }

        // release ADU lock
        FAPI_DBG("proc_build_smp_switch_cd: Releasing lock for ADU");
        rc = proc_build_smp_adu_release_lock(
            i_smp_chip.chip->this_chip,
            PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_cd: Error from proc_build_smp_adu_release_lock");
            break;
        }
        FAPI_DBG("proc_build_smp_switch_cd: ADU lock released");
    } while(0);

    // if error has occurred and ADU is dirty,
    // attempt to reset ADU and free lock (propogate rc of original fail)
    if (!rc.ok() && adu_is_dirty)
    {
        FAPI_INF("proc_build_smp_switch_cd: Attempting to reset/free lock on ADU");
        (void) proc_build_smp_adu_set_switch_action(i_smp_chip.chip->this_chip, false, false);
        (void) proc_build_smp_adu_reset(i_smp_chip.chip->this_chip);
        (void) proc_build_smp_adu_release_lock(i_smp_chip.chip->this_chip, 1);
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_switch_cd: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_quiesce_pb(
    proc_build_smp_system& i_smp,
    const proc_build_smp_operation i_op)
{
    fapi::ReturnCode rc;
    std::map<proc_fab_smp_node_id, proc_build_smp_node>::iterator n_iter;
    std::map<proc_fab_smp_chip_id, proc_build_smp_chip>::iterator p_iter;
    std::vector<proc_build_smp_chip*>::iterator quiesce_iter;
    // ADU status/control information
    proc_adu_utils_fbc_op adu_ctl;
    proc_adu_utils_fbc_op_hp_ctl adu_hp_ctl;
    bool adu_is_dirty = false;

    // mark function entry
    FAPI_DBG("proc_build_smp_quiesce_pb: Start");

    do
    {
        FAPI_DBG("proc_build_smp_quiesce_pb: Acquiring lock for all ADU units in fabric");
        // loop through all chips, lock & reset ADU
        for (n_iter = i_smp.nodes.begin();
             (n_iter != i_smp.nodes.end()) && (rc.ok());
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 (p_iter != n_iter->second.chips.end()) && (rc.ok());
                 p_iter++)
            {
                // acquire ADU lock
                rc = proc_build_smp_adu_acquire_lock(
                    p_iter->second.chip->this_chip,
                    ((i_op == SMP_ACTIVATE_PHASE1)?
                     (PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS):
                     (PROC_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS)),
                    ((i_op == SMP_ACTIVATE_PHASE1)?
                     (PROC_BUILD_SMP_PHASE1_ADU_PICK_LOCK):
                     (PROC_BUILD_SMP_PHASE2_ADU_PICK_LOCK)));
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_quiesce_pb: Error from proc_build_smp_adu_acquire_lock");
                    break;
                }
                // NOTE: lock is now held, if an operation fails from this point
                //       to the end of the procedure:
                //       o attempt to cleanup/release lock (so that procedure does not
                //         leave the ADU in a locked state)
                //       o return rc of original fail
                adu_is_dirty = true;

                // reset ADU
                rc = proc_build_smp_adu_reset(p_iter->second.chip->this_chip);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_quiesce_pb: Error from proc_build_smp_adu_reset");
                    break;
                }
            }
        }
        if (!rc.ok())
        {
            break;
        }
        FAPI_DBG("proc_build_smp_quiesce_pb: All ADU locks held");

        // build ADU control structure
        adu_ctl.ttype = ADU_FBC_OP_TTYPE_PBOP;
        adu_ctl.tsize = ADU_FBC_OP_TSIZE_PBOP_DIS_ALL_FP_EN;
        adu_ctl.address = 0x0ULL;
        adu_ctl.scope = ADU_FBC_OP_SCOPE_SYSTEM;
        adu_ctl.drop_priority = ADU_FBC_OP_DROP_PRIORITY_HIGH;
        adu_ctl.cmd_type = ADU_FBC_OP_CMD_ADDR_ONLY;
        adu_ctl.init_policy = ADU_FBC_OP_FBC_INIT_OVERRIDE;
        adu_ctl.use_autoinc = false;

        adu_hp_ctl.do_tm_quiesce = true;
        adu_hp_ctl.do_pre_quiesce = false;
        adu_hp_ctl.do_post_init = false;
        adu_hp_ctl.post_quiesce_delay = 0x0;
        adu_hp_ctl.pre_init_delay = 0x0;

        // issue quiesce on all specified chips
        for (n_iter = i_smp.nodes.begin();
             (n_iter != i_smp.nodes.end()) && (rc.ok());
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 (p_iter != n_iter->second.chips.end()) && (rc.ok());
                 p_iter++)
            {
                if (p_iter->second.issue_quiesce_next)
                {
                    FAPI_DBG("proc_build_smp_quiesce_pb: Issuing quiesce from %s",
                             p_iter->second.chip->this_chip.toEcmdString());
                    // launch command
                    rc = proc_adu_utils_send_fbc_op(p_iter->second.chip->this_chip,
                                                    adu_ctl,
                                                    true,
                                                    adu_hp_ctl);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_build_smp_quiesce_pb: Error from proc_adu_utils_send_fbc_op");
                        break;
                    }

                    // check status
                    rc = proc_build_smp_adu_check_status(
                        p_iter->second.chip->this_chip,
                        i_smp,
                        (i_op == SMP_ACTIVATE_PHASE2));
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_build_smp_quiesce_pb: Error from proc_build_smp_adu_check_status");
                        break;
                    }
                }
            }
        }
        if (!rc.ok())
        {
            break;
        }

        FAPI_DBG("proc_build_smp_quiesce_pb: Releasing lock for all ADU units in drawer");
        // loop through all chips, unlock ADUs
        for (n_iter = i_smp.nodes.begin();
             (n_iter != i_smp.nodes.end()) && (rc.ok());
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 (p_iter != n_iter->second.chips.end()) && (rc.ok());
                 p_iter++)
            {
                // release ADU lock
                rc = proc_build_smp_adu_release_lock(
                    p_iter->second.chip->this_chip,
                    ((i_op == SMP_ACTIVATE_PHASE1)?
                     (PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS):
                     (PROC_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS)));
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_quiesce_pb: Error from proc_build_smp_adu_release_lock");
                    break;
                }
            }
        }
        if (!rc.ok())
        {
            break;
        }
        FAPI_DBG("proc_build_smp_quiesce_pb: All ADU locks released");
    } while(0);


    // if error has occurred and any ADU is dirty,
    // attempt to reset all ADUs and free locks (propogate rc of original fail)
    if (!rc.ok() && adu_is_dirty)
    {
        FAPI_INF("proc_build_smp_quiesce_pb: Attempting to reset/free lock on all ADUs");
        // loop through all chips, unlock ADUs
        for (n_iter = i_smp.nodes.begin();
             n_iter != i_smp.nodes.end();
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 p_iter++)
            {
                (void) proc_build_smp_adu_reset(p_iter->second.chip->this_chip);
                (void) proc_build_smp_adu_release_lock(
                    p_iter->second.chip->this_chip,
                    1);
            }
        }
    }

    // mark function entry
    FAPI_DBG("proc_build_smp_quiesce_pb: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_switch_ab(
    proc_build_smp_system& i_smp,
    const proc_build_smp_operation i_op)
{
    fapi::ReturnCode rc;
    std::map<proc_fab_smp_node_id, proc_build_smp_node>::iterator n_iter;
    std::map<proc_fab_smp_chip_id, proc_build_smp_chip>::iterator p_iter;
    // ADU status/control information
    proc_adu_utils_fbc_op adu_ctl;
    proc_adu_utils_fbc_op_hp_ctl adu_hp_ctl;
    bool adu_is_dirty = false;

    // mark function entry
    FAPI_DBG("proc_build_smp_switch_ab: Start");

    do
    {
        FAPI_DBG("proc_build_smp_switch_ab: Acquiring lock for all ADU units in fabric");
        // loop through all chips, lock & reset ADU
        for (n_iter = i_smp.nodes.begin();
             (n_iter != i_smp.nodes.end()) && (rc.ok());
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 (p_iter != n_iter->second.chips.end()) && (rc.ok());
                 p_iter++)
            {
                // acquire ADU lock
                rc = proc_build_smp_adu_acquire_lock(
                    p_iter->second.chip->this_chip,
                    ((i_op == SMP_ACTIVATE_PHASE1)?
                     (PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS):
                     (PROC_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS)),
                    ((i_op == SMP_ACTIVATE_PHASE1)?
                     (PROC_BUILD_SMP_PHASE1_ADU_PICK_LOCK):
                     (PROC_BUILD_SMP_PHASE2_ADU_PICK_LOCK)));
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_switch_ab: Error from proc_build_smp_adu_acquire_lock");
                    break;
                }
                // NOTE: lock is now held, if an operation fails from this point
                //       to the end of the procedure:
                //       o attempt to cleanup/release lock (so that procedure does not
                //         leave the ADU in a locked state)
                //       o return rc of original fail
                adu_is_dirty = true;

                // reset ADU
                rc = proc_build_smp_adu_reset(p_iter->second.chip->this_chip);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_switch_ab: Error from proc_build_smp_adu_reset");
                    break;
                }

                // condition for switch AB operation
                // all chips which were not quiesced prior to switch AB will
                // need to observe the switch
                rc = proc_build_smp_adu_set_switch_action(
                    p_iter->second.chip->this_chip,
                    !p_iter->second.quiesced_next,
                    false);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_switch_ab: Error from proc_build_smp_adu_set_switch_action (set)");
                    break;
                }
            }
        }
        if (!rc.ok())
        {
            break;
        }
        FAPI_DBG("proc_build_smp_switch_ab: All ADU locks held");

        // build ADU control structure
        adu_ctl.ttype = ADU_FBC_OP_TTYPE_PMISC;
        adu_ctl.tsize = ADU_FBC_OP_TSIZE_PMISC_SWITCH_AB;
        adu_ctl.address = 0x0ULL;
        adu_ctl.scope = ADU_FBC_OP_SCOPE_SYSTEM;
        adu_ctl.drop_priority = ADU_FBC_OP_DROP_PRIORITY_HIGH;
        adu_ctl.cmd_type = ADU_FBC_OP_CMD_ADDR_ONLY;
        adu_ctl.init_policy = ADU_FBC_OP_FBC_INIT_OVERRIDE;
        adu_ctl.use_autoinc = false;

        adu_hp_ctl.do_tm_quiesce = true;
        adu_hp_ctl.do_pre_quiesce = true;
        adu_hp_ctl.do_post_init = true;
        adu_hp_ctl.post_quiesce_delay = ((i_op == SMP_ACTIVATE_PHASE1)?
                                         (PROC_BUILD_SMP_PHASE1_POST_QUIESCE_DELAY):
                                         (PROC_BUILD_SMP_PHASE2_POST_QUIESCE_DELAY));
        adu_hp_ctl.pre_init_delay = ((i_op == SMP_ACTIVATE_PHASE1)?
                                     (PROC_BUILD_SMP_PHASE1_PRE_INIT_DELAY):
                                     (PROC_BUILD_SMP_PHASE2_PRE_INIT_DELAY));

        // launch command
        FAPI_DBG("proc_build_smp_switch_ab: Issuing switch AB from %s",
                 i_smp.nodes[i_smp.master_chip_curr_node_id].chips[i_smp.master_chip_curr_chip_id].chip->this_chip.toEcmdString());
        rc = proc_adu_utils_send_fbc_op(i_smp.nodes[i_smp.master_chip_curr_node_id].chips[i_smp.master_chip_curr_chip_id].chip->this_chip,
                                        adu_ctl,
                                        true,
                                        adu_hp_ctl);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_ab: Error from proc_adu_utils_send_fbc_op");
            break;
        }

        // check status
        rc = proc_build_smp_adu_check_status(
            i_smp.nodes[i_smp.master_chip_curr_node_id].chips[i_smp.master_chip_curr_chip_id].chip->this_chip,
            i_smp,
            true);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_ab: Error from proc_build_smp_adu_check_status");
            break;
        }

        // loop through all chips, unlock ADUs
        FAPI_DBG("proc_build_smp_switch_ab: Releasing lock for all ADU units in drawer");
        for (n_iter = i_smp.nodes.begin();
             (n_iter != i_smp.nodes.end()) && (rc.ok());
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 (p_iter != n_iter->second.chips.end()) && (rc.ok());
                 p_iter++)
            {
                // reset switch action
                rc = proc_build_smp_adu_set_switch_action(
                    p_iter->second.chip->this_chip,
                    false,
                    false);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_switch_ab: Error from proc_build_smp_adu_set_switch_action (clear)");
                    break;
                }

                // release ADU lock
                rc = proc_build_smp_adu_release_lock(
                    p_iter->second.chip->this_chip,
                    ((i_op == SMP_ACTIVATE_PHASE1)?
                     (PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS):
                     (PROC_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS)));
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_switch_ab: Error from proc_build_smp_adu_release_lock");
                    break;
                }
            }
        }
        if (!rc.ok())
        {
            break;
        }
        FAPI_DBG("proc_build_smp_switch_ab: All ADU locks released");
    } while(0);

    // if error has occurred and any ADU is dirty,
    // attempt to reset all ADUs and free locks (propogate rc of original fail)
    if (!rc.ok() && adu_is_dirty)
    {
        FAPI_INF("proc_build_smp_switch_ab: Attempting to reset/free lock on all ADUs");
        // loop through all chips, unlock ADUs
        for (n_iter = i_smp.nodes.begin();
             n_iter != i_smp.nodes.end();
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 p_iter++)
            {
                (void) proc_build_smp_adu_set_switch_action(p_iter->second.chip->this_chip, false, false);
                (void) proc_build_smp_adu_reset(p_iter->second.chip->this_chip);
                (void) proc_build_smp_adu_release_lock(
                    p_iter->second.chip->this_chip,
                    1);
            }
        }
    }

    // mark function entry
    FAPI_DBG("proc_build_smp_switch_ab: End");
    return rc;
}


} // extern "C"


