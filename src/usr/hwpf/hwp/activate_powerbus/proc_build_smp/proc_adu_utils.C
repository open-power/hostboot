/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_adu_utils.C $ */
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
// $Id: proc_adu_utils.C,v 1.10 2016/02/05 16:02:04 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/proc_adu_utils.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_adu_utils.C
// *! DESCRIPTION : ADU library functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *! BACKUP NAME : Kevin Reick   Email: reick@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_adu_utils.H>

extern "C"
{


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


fapi::ReturnCode proc_adu_utils_get_adu_lock_id(
    const fapi::Target& i_target,
    uint8_t& o_lock_id)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase data(64);
    uint8_t lock_id;

    FAPI_DBG("proc_adu_utils_get_adu_lock_id: Start");

    do
    {
        // read ADU Command register
        FAPI_DBG("proc_adu_utils_get_adu_lock_id: Reading ADU Command register to retreive lock ID");
        rc = fapiGetScom(i_target, ADU_COMMAND_0x02020001, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_adu_utils_get_adu_lock_id: fapiGetScom error (ADU_COMMAND_0x02020001)");
            break;
        }

        // extract lock ID field
        rc_ecmd |= data.extractToRight(&lock_id,
                                       ADU_COMMAND_LOCK_ID_START_BIT,
                                       (ADU_COMMAND_LOCK_ID_END_BIT-
                                        ADU_COMMAND_LOCK_ID_START_BIT)+1);
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            FAPI_ERR("proc_adu_utils_get_adu_lock_id: Error 0x%x extracting lock id from data buffer",
                     rc_ecmd);
            break;
        }
        o_lock_id = lock_id & ADU_COMMAND_LOCK_ID_MAX_VALUE;

    } while(0);

    FAPI_DBG("proc_adu_utils_get_adu_lock_id: End");
    return rc;
}


fapi::ReturnCode proc_adu_utils_clear_adu_auto_inc(
    const fapi::Target& i_target)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase data(64);

    FAPI_DBG("proc_adu_utils_clear_adu_auto_inc: Start");

    do
    {
        // retreive ADU Command register
        FAPI_DBG("proc_adu_utils_clear_adu_auto_inc: Reading ADU Command register");
        rc = fapiGetScom(i_target, ADU_COMMAND_0x02020001, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_adu_utils_clear_adu_auto_inc: fapiGetScom error (ADU_COMMAND_0x02020001)");
            break;
        }

        // clear auto-increment bit
        rc_ecmd |= data.clearBit(ADU_COMMAND_AUTO_INC_BIT);
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            FAPI_ERR("proc_adu_utils_clear_adu_auto_inc: Error 0x%x forming auto-increment clear data buffer",
                     rc_ecmd);
            break;
        }

        // write ADU Command register
        FAPI_DBG("proc_adu_utils_clear_adu_auto_inc: Writing ADU Command register");
        rc = fapiPutScom(i_target, ADU_COMMAND_0x02020001, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_adu_utils_clear_adu_auto_inc: fapiPutScom error (ADU_COMMAND_0x02020001)");
            break;
        }

    } while(0);

    FAPI_DBG("proc_adu_utils_clear_adu_auto_inc: End");
    return rc;
}


fapi::ReturnCode proc_adu_utils_manage_adu_lock(
    const fapi::Target& i_target,
    const proc_adu_utils_adu_lock_operation i_lock_operation,
    const uint32_t i_num_attempts)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase lock_control(64);
    uint32_t attempt_count = 1;

    FAPI_DBG("proc_adu_utils_manage_adu_lock: Start");

    do
    {
        // validate input parameters
        if (i_num_attempts == 0)
        {
            FAPI_ERR("proc_adu_utils_manage_adu_lock: Invalid value %d for number of lock manipulation attempts",
                     i_num_attempts);
            const fapi::Target & TARGET = i_target;
            const uint32_t & ATTEMPTS = i_num_attempts;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_ADU_UTILS_INVALID_LOCK_ATTEMPTS);
            break;
        }

        // set up data buffer to perform desired lock manipulation operation
        if (i_lock_operation == ADU_LOCK_ACQUIRE)
        {
            FAPI_DBG("proc_adu_utils_manage_adu_lock: Configuring lock manipulation control data buffer to perform lock acquisition");
            rc_ecmd |= lock_control.setBit(ADU_COMMAND_LOCKED_BIT);
        }
        else if (i_lock_operation == ADU_LOCK_FORCE_ACQUIRE)
        {
            FAPI_DBG("proc_adu_utils_manage_adu_lock: Configuring lock manipulation control data buffer to perform lock acquisition/pick");
            rc_ecmd |= lock_control.setBit(ADU_COMMAND_LOCKED_BIT);
            rc_ecmd |= lock_control.setBit(ADU_COMMAND_LOCK_PICK_BIT);
        }
        else if (i_lock_operation == ADU_LOCK_RELEASE)
        {
            FAPI_DBG("proc_adu_utils_manage_adu_lock: Configuring lock manipulation control data buffer to perform lock release");
        }
        else
        {
            FAPI_ERR("proc_adu_utils_manage_adu_lock: Internal error (unsupported lock operation enum value %d)",
                     i_lock_operation);
            const fapi::Target & TARGET = i_target;
            const uint32_t & OPERATION = i_lock_operation;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_ADU_UTILS_INVALID_LOCK_OPERATION);
            break;
        }
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            FAPI_ERR("proc_adu_utils_manage_adu_lock: Error 0x%x setting up lock manipulation control data buffer",
                     rc_ecmd);
            break;
        }

        // perform lock management operation
        while (1)
        {
            // write ADU command register to attempt lock manipulation
            FAPI_DBG("proc_adu_utils_manage_adu_lock: Writing ADU Command register to attempt lock manipulation");
            rc = fapiPutScom(i_target, ADU_COMMAND_0x02020001, lock_control);
            // pass back return code to caller unless it specifically indicates
            // that the ADU lock manipulation was unsuccessful and we're going
            // to try again
            if ((rc != fapi::FAPI_RC_PLAT_ERR_ADU_LOCKED) ||
                (attempt_count == i_num_attempts))
            {
                // rc does not indicate success
                if (!rc.ok())
                {
                    // rc does not indicate lock held, exit
                    if (rc != fapi::FAPI_RC_PLAT_ERR_ADU_LOCKED)
                    {
                        FAPI_ERR("proc_adu_utils_manage_adu_lock: fapiPutScom error (ADU_COMMAND_0x02020001)");
                        break;
                    }
                    // rc indicates lock held, out of attempts
                    if (attempt_count == i_num_attempts)
                    {
                        FAPI_ERR("proc_adu_utils_manage_adu_lock: Desired ADU lock manipulation was not successful after %d attempts",
                                 i_num_attempts);
                        break;
                    }
                }
                // rc clean, lock management operation successful
                FAPI_DBG("proc_adu_utils_manage_adu_lock: Lock manipulation successful");
                break;
            }

            // delay to provide time for ADU lock to be released
            rc = fapiDelay(PROC_ADU_UTILS_ADU_HW_NS_DELAY,
                           PROC_ADU_UTILS_ADU_SIM_CYCLE_DELAY);
            if (!rc.ok())
            {
                FAPI_ERR("proc_adu_utils_manage_adu_lock: fapiDelay error");
                break;
            }

            // increment attempt count, loop again
            attempt_count++;
            FAPI_DBG("proc_adu_utils_manage_adu_lock: Attempt %d of %d",
                     attempt_count, i_num_attempts);
        }

    } while(0);

    FAPI_DBG("proc_adu_utils_manage_adu_lock: End");
    return rc;
}


fapi::ReturnCode proc_adu_utils_reset_adu(
    const fapi::Target& i_target)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase data(64);

    FAPI_DBG("proc_adu_utils_reset_adu: Start");

    do
    {
        // assert status clear & state machine bits
        // leave lock bit asserted
        FAPI_DBG("proc_adu_utils_reset_adu: Writing ADU Command register to reset ADU");
        rc_ecmd |= data.setBit(ADU_COMMAND_CLEAR_STATUS_BIT);
        rc_ecmd |= data.setBit(ADU_COMMAND_RESET_BIT);
        rc_ecmd |= data.setBit(ADU_COMMAND_LOCKED_BIT);
        if (rc_ecmd)
        {
   	    rc.setEcmdError(rc_ecmd);
            FAPI_ERR("proc_adu_utils_reset_adu: Error 0x%x setting up reset control data buffer",
                     rc_ecmd);
            break;
        }

        // write ADU Command register
        rc = fapiPutScom(i_target, ADU_COMMAND_0x02020001, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_adu_utils_reset_adu: fapiPutScom error (ADU_COMMAND_0x02020001)");
            break;
        }

    } while(0);

    FAPI_DBG("proc_adu_utils_reset_adu: End");
    return rc;
}


fapi::ReturnCode proc_adu_utils_send_fbc_op(
    const fapi::Target& i_target,
    const proc_adu_utils_fbc_op i_adu_ctl,
    const bool i_use_hp,
    const proc_adu_utils_fbc_op_hp_ctl i_adu_hp_ctl)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase ctl_data(64);
    ecmdDataBufferBase cmd_data(64);
    uint8_t struct_data_to_insert;

    FAPI_DBG("proc_adu_utils_send_fbc_op: Start");

    do
    {
        // validate input parameters
        if (i_adu_ctl.address > PROC_FBC_UTILS_FBC_MAX_ADDRESS)
        {
            FAPI_ERR("proc_adu_utils_send_fbc_op: Out-of-range value %016llX specified for fabric address argument",
                     i_adu_ctl.address);
            const fapi::Target & TARGET = i_target;
            const uint64_t & ADDRESS = i_adu_ctl.address;
            const proc_adu_utils_fbc_op & FBC_OP = i_adu_ctl;
            const proc_adu_utils_fbc_op_hp_ctl & FBC_OP_HP_CTL = i_adu_hp_ctl;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_ADU_UTILS_INVALID_FBC_OP);
            break;
        }
        if (i_use_hp &&
            (i_adu_hp_ctl.post_quiesce_delay >
             PROC_ADU_UTILS_ADU_MAX_POST_QUIESCE_DELAY))
        {
            FAPI_ERR("proc_adu_utils_send_fbc_op: Out-of-range value %d specified for hotplug post-quiesce delay argument",
                     i_adu_hp_ctl.post_quiesce_delay);
            const fapi::Target & TARGET = i_target;
            const uint64_t & ADDRESS = i_adu_ctl.address;
            const proc_adu_utils_fbc_op & FBC_OP = i_adu_ctl;
            const proc_adu_utils_fbc_op_hp_ctl & FBC_OP_HP_CTL = i_adu_hp_ctl;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_ADU_UTILS_INVALID_FBC_OP);
            break;
        }
        if (i_use_hp &&
            (i_adu_hp_ctl.pre_init_delay >
             PROC_ADU_UTILS_ADU_MAX_PRE_INIT_DELAY))
        {
            FAPI_ERR("proc_adu_utils_send_fbc_op: Out-of-range value %d specified for hotplug pre-init delay argument",
                     i_adu_hp_ctl.pre_init_delay);
	        const fapi::Target & TARGET = i_target;
            const uint64_t & ADDRESS = i_adu_ctl.address;
            const proc_adu_utils_fbc_op & FBC_OP = i_adu_ctl;
            const proc_adu_utils_fbc_op_hp_ctl & FBC_OP_HP_CTL = i_adu_hp_ctl;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_ADU_UTILS_INVALID_FBC_OP);
            break;
        }

        // build ADU Control register content
        FAPI_DBG("proc_adu_utils_send_fbc_op: Writing ADU Control register");
        // ttype field
        struct_data_to_insert = i_adu_ctl.ttype;
        rc_ecmd |= ctl_data.insertFromRight(
            &struct_data_to_insert,
            ADU_CONTROL_FBC_TTYPE_START_BIT,
            (ADU_CONTROL_FBC_TTYPE_END_BIT-
             ADU_CONTROL_FBC_TTYPE_START_BIT+1));
        // read/write bit
        if (i_adu_ctl.cmd_type == ADU_FBC_OP_CMD_RD_ADDR_DATA)
        {
            rc_ecmd |= ctl_data.setBit(ADU_CONTROL_FBC_RNW_BIT);
        }
        // tsize field
        struct_data_to_insert = i_adu_ctl.tsize;
        rc_ecmd |= ctl_data.insertFromRight(
            &struct_data_to_insert,
            ADU_CONTROL_FBC_TSIZE_START_BIT,
            (ADU_CONTROL_FBC_TSIZE_END_BIT-
             ADU_CONTROL_FBC_TSIZE_START_BIT+1));
        // address field
        rc_ecmd |= ctl_data.insertFromRight((uint32_t)
            (i_adu_ctl.address >>
             ADU_CONTROL_FBC_ADDRESS_SPLIT_BIT),
            ADU_CONTROL_FBC_ADDRESS_START_BIT,
            (ADU_CONTROL_FBC_ADDRESS_SPLIT_BIT-1-
             ADU_CONTROL_FBC_ADDRESS_START_BIT+1));
        rc_ecmd |= ctl_data.insertFromRight((uint32_t)
            (i_adu_ctl.address &
             ADU_CONTROL_FBC_ADDRESS_SPLIT_MASK),
            ADU_CONTROL_FBC_ADDRESS_SPLIT_BIT,
            (ADU_CONTROL_FBC_ADDRESS_END_BIT-
             ADU_CONTROL_FBC_ADDRESS_SPLIT_BIT+1));
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            FAPI_ERR("proc_adu_utils_send_fbc_op: Error 0x%x setting up ADU Control register data buffer",
                     rc_ecmd);
            break;
        }
        // write ADU Control register content
        rc = fapiPutScom(i_target, ADU_CONTROL_0x02020000, ctl_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_adu_utils_send_fbc_op: fapiPutScom error (ADU_CONTROL_0x02020000)");
            break;
        }

        // build ADU Command register content
        FAPI_DBG("proc_adu_utils_send_fbc_op: Writing ADU Command register");
        // start operation bit
        rc_ecmd |= cmd_data.setBit(ADU_COMMAND_START_OP_BIT);
        // address only bit
        if (i_adu_ctl.cmd_type == ADU_FBC_OP_CMD_ADDR_ONLY)
        {
            rc_ecmd |= cmd_data.setBit(ADU_COMMAND_ADDRESS_ONLY_BIT);
        }
        // lock bit
        rc_ecmd |= cmd_data.setBit(ADU_COMMAND_LOCKED_BIT);
        // scope field
        struct_data_to_insert = i_adu_ctl.scope;
        rc_ecmd |= cmd_data.insertFromRight(
            &struct_data_to_insert,
            ADU_COMMAND_FBC_SCOPE_START_BIT,
            (ADU_COMMAND_FBC_SCOPE_END_BIT-
             ADU_COMMAND_FBC_SCOPE_START_BIT+1));
        // auto-increment bit
        if (i_adu_ctl.use_autoinc)
        {
            rc_ecmd |= cmd_data.setBit(ADU_COMMAND_AUTO_INC_BIT);
        }
        // drop priority
        struct_data_to_insert = i_adu_ctl.drop_priority;
        rc_ecmd |= cmd_data.insertFromRight(
            &struct_data_to_insert,
            ADU_COMMAND_FBC_DROP_PRIORITY_START_BIT,
            (ADU_COMMAND_FBC_DROP_PRIORITY_END_BIT-
             ADU_COMMAND_FBC_DROP_PRIORITY_START_BIT+1));
        // fabric init policy controls
        if (i_adu_ctl.init_policy == ADU_FBC_OP_FBC_INIT_OVERRIDE)
        {
            rc_ecmd |= cmd_data.setBit(ADU_COMMAND_FBC_INIT_OVERRIDE_BIT);
        }
        else if (i_adu_ctl.init_policy == ADU_FBC_OP_FBC_INIT_WAIT_LOW)
        {
            rc_ecmd |= cmd_data.setBit(ADU_COMMAND_FBC_INIT_WAIT_LOW_BIT);
        }
        // perform token manager quiesce?
        if (i_use_hp && i_adu_hp_ctl.do_tm_quiesce)
        {
            rc_ecmd |= cmd_data.setBit(ADU_COMMAND_FBC_TM_QUIESCE_BIT);
        }
        // send fabric queisce command before programmed command?
        // set cycle delay to apply after quiesce before programmed command
        if (i_use_hp && i_adu_hp_ctl.do_pre_quiesce)
        {
            rc_ecmd |= cmd_data.setBit(ADU_COMMAND_FBC_PRE_QUIESCE_BIT);
            rc_ecmd |= cmd_data.insertFromRight(
                &i_adu_hp_ctl.post_quiesce_delay,
                ADU_COMMAND_FBC_POST_QUIESCE_COUNT_START_BIT,
                (ADU_COMMAND_FBC_POST_QUIESCE_COUNT_END_BIT-
                 ADU_COMMAND_FBC_POST_QUIESCE_COUNT_START_BIT+1));
        }
        // send fabric init command after programmed command?
        // set cycle delay to apply after programmed command before init
        if (i_use_hp && i_adu_hp_ctl.do_post_init)
        {
            rc_ecmd |= cmd_data.setBit(ADU_COMMAND_FBC_POST_INIT_BIT);
            rc_ecmd |= cmd_data.insertFromRight(
                &i_adu_hp_ctl.pre_init_delay,
                ADU_COMMAND_FBC_PRE_INIT_COUNT_START_BIT,
                (ADU_COMMAND_FBC_PRE_INIT_COUNT_END_BIT-
                 ADU_COMMAND_FBC_PRE_INIT_COUNT_START_BIT+1));
        }
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            FAPI_ERR("proc_adu_utils_send_fbc_op: Error 0x%x forming data buffer",
                     rc_ecmd);
            break;
        }

        // write ADU Command register content
        rc = fapiPutScom(i_target, ADU_COMMAND_0x02020001, cmd_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_adu_utils_send_fbc_op: fapiPutScom error (ADU_COMMAND_0x02020001)");
            break;
        }

    } while(0);

    FAPI_DBG("proc_adu_utils_send_fbc_op: End");
    return rc;
}


fapi::ReturnCode proc_adu_utils_get_adu_status(
    const fapi::Target& i_target,
    const bool i_poll_busy_low,
    proc_adu_utils_adu_status& o_status_act)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase status_data(64);
    bool poll = false;
    uint32_t poll_count = 0;

    FAPI_DBG("proc_adu_utils_get_adu_status: Start");

    do
    {
        // read ADU Status register
        FAPI_DBG("proc_adu_utils_get_adu_status: Reading ADU Status register (poll_busy_low: %d, count: %d)",
                 (i_poll_busy_low)?(1):(0), poll_count);
        rc = fapiGetScom(i_target, ADU_STATUS_0x02020002, status_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_adu_utils_get_adu_status: fapiGetScom error (ADU_STATUS_0x02020002)");
            break;
        }

        // fill actual structure
        o_status_act.busy =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_BUSY_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        poll = i_poll_busy_low &&
            (o_status_act.busy == ADU_STATUS_BIT_SET);
        poll_count++;

        o_status_act.wait_cmd_arbit =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_WAIT_CMD_ARBIT_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        o_status_act.addr_done =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_ADDR_DONE_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        o_status_act.data_done =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_DATA_DONE_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        o_status_act.wait_resp =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_WAIT_RESP_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        o_status_act.overrun_err =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_OVERRUN_ERR_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        o_status_act.autoinc_err =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_AUTOINC_ERR_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        o_status_act.command_err =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_COMMAND_ERR_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        o_status_act.address_err =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_ADDRESS_ERR_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        o_status_act.command_hang_err =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_COMMAND_HANG_ERR_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        o_status_act.data_hang_err =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_DATA_HANG_ERR_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
        o_status_act.pbinit_missing =
            status_data.isBitSet(ADU_STATUS_FBC_ALTD_INIT_MISSING_BIT) ?
            ADU_STATUS_BIT_SET :
            ADU_STATUS_BIT_CLEAR;
    } while(poll && (poll_count < PROC_ADU_UTILS_ADU_MAX_BUSY_POLLS));

    FAPI_DBG("proc_adu_utils_get_adu_status: End");
    return rc;
}


fapi::ReturnCode proc_adu_utils_set_adu_data_registers(
    const fapi::Target& i_target,
    const uint64_t i_write_data,
    const bool i_override_itag,
    const bool i_write_itag,
    const bool i_override_ecc,
    const uint8_t i_write_ecc)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase ecc_data(64);

    FAPI_DBG("proc_adu_utils_set_adu_data_registers: Start");

    do
    {
        // write ADU Force ECC Register first if directed
        // this ordering is required to fully support auto-increment mode
        if (i_override_itag ||
            i_override_ecc)
        {
            FAPI_DBG("proc_adu_utils_set_adu_data_registers: Writing ADU Force ECC register");
            if (i_override_itag)
            {
                rc_ecmd |= ecc_data.setBit(ADU_FORCE_ECC_DATA_ITAG_BIT);
            }
            if (i_override_ecc)
            {
                // set ECC override bit, duplicate override ECC
                rc_ecmd |= ecc_data.setBit(ADU_FORCE_ECC_DATA_TX_ECC_OVERWRITE_BIT);
                rc_ecmd |= ecc_data.insertFromRight(
                    i_write_ecc,
                    ADU_FORCE_ECC_DATA_TX_ECC_HI_START_BIT,
                    ADU_FORCE_ECC_DATA_TX_ECC_HI_END_BIT-
                    ADU_FORCE_ECC_DATA_TX_ECC_HI_START_BIT+1);
                rc_ecmd |= ecc_data.insertFromRight(
                    i_write_ecc,
                    ADU_FORCE_ECC_DATA_TX_ECC_LO_START_BIT,
                    ADU_FORCE_ECC_DATA_TX_ECC_LO_END_BIT-
                    ADU_FORCE_ECC_DATA_TX_ECC_LO_START_BIT+1);
            }
            if (rc_ecmd)
            {
                rc.setEcmdError(rc_ecmd);
                FAPI_ERR("proc_adu_utils_set_adu_data_registers: Error 0x%x forming override ECC data buffer",
                         rc_ecmd);
                break;
            }

            // write ADU Force ECC register
            rc = fapiPutScom(i_target, ADU_FORCE_ECC_0x02020010, ecc_data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_adu_utils_set_adu_data_registers: fapiPutScom error (ADU_FORCE_ECC_0x02020010)");
                break;
            }
        }

        // write ADU Data register
        // this will generate new command in auto-increment mode
        FAPI_DBG("proc_adu_utils_set_adu_data_registers: Writing ADU Data register");
        rc_ecmd |= data.insertFromRight((uint32_t)
            (i_write_data >> ADU_DATA_SPLIT_BIT),
            ADU_DATA_START_BIT,
            (ADU_DATA_SPLIT_BIT-1-
             ADU_DATA_START_BIT+1));
        rc_ecmd |= data.insertFromRight((uint32_t)
            (i_write_data & ADU_DATA_SPLIT_MASK),
            ADU_DATA_SPLIT_BIT,
            (ADU_DATA_END_BIT-
             ADU_DATA_SPLIT_BIT+1));
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            FAPI_ERR("proc_adu_utils_set_adu_data_registers: Error 0x%x forming data buffer",
                     rc_ecmd);
            break;
        }

        // write ADU Data register
        rc = fapiPutScom(i_target, ADU_DATA_0x02020003, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_adu_utils_set_adu_data_registers: fapiPutScom error (ADU_DATA_0x02020003)");
            break;
        }

    } while(0);

    FAPI_DBG("proc_adu_utils_set_adu_data_registers: End");
    return rc;
}


fapi::ReturnCode proc_adu_utils_get_adu_data_registers(
    const fapi::Target& i_target,
    const bool i_get_itag,
    uint64_t& o_read_data,
    bool& o_read_itag)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase ecc_data(64);

    FAPI_DBG("proc_adu_utils_get_adu_data_registers: Start");

    do
    {
        // read ADU Force ECC Register first if directed
        // this ordering is required to fully support auto-increment mode
        if (i_get_itag)
        {
            // read ADU Force ECC register
            FAPI_DBG("proc_adu_utils_get_adu_data_registers: Reading ADU Force ECC register");
            rc = fapiGetScom(i_target, ADU_FORCE_ECC_0x02020010, ecc_data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_adu_utils_get_adu_data_registers: fapiGetScom error (ADU_FORCE_ECC_0x02020010)");
                break;
            }
            o_read_itag = ecc_data.isBitSet(ADU_FORCE_ECC_DATA_ITAG_BIT);
        }

        // read ADU Data register
        // this will generate new command in auto-increment mode
        FAPI_DBG("proc_adu_utils_get_adu_data_registers: Reading ADU Data register");
        rc = fapiGetScom(i_target, ADU_DATA_0x02020003, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_adu_utils_get_adu_data_registers: fapiGetScom error (ADU_DATA_0x02020003)");
            break;
        }
        o_read_data = data.getDoubleWord(0);

    } while(0);

    FAPI_DBG("proc_adu_utils_get_adu_data_registers: End");
    return rc;
}


} // extern "C"
