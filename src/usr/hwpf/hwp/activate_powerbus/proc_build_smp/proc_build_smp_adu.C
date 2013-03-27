/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_adu.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: proc_build_smp_adu.C,v 1.4 2013/02/25 14:50:52 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_adu.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
#include "proc_build_smp_adu.H"
#include "proc_adu_utils.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


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
//          RC_PROC_ADU_UTILS_INVALID_ARGS if invalid number of lock attempts
//              is specified,
//          RC_PROC_ADU_UTILS_INTERNAL_ERR if an unexpected internal
//              logic error occurs,
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
//          RC_PROC_ADU_UTILS_INVALID_ARGS if invalid number of unlock attempts
//              is specified,
//          RC_PROC_ADU_UTILS_INTERNAL_ERR if an unexpected internal
//              logic error occurs,
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
// parameters: i_target         => P8 chip target
//             i_read_not_write => desired operation (read=true, write=false)
// returns: FAPI_RC_SUCCESS if status matches expected value,
//          RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH if status mismatches,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_adu_check_status(
    const fapi::Target& i_target)
{
    fapi::ReturnCode rc;
    proc_adu_utils_adu_status status_exp, status_act;
    bool match = false;
    uint8_t num_polls = 0;

    FAPI_DBG("proc_build_smp_adu_check_status: Start");
    do
    {
        // build expected status structure
        status_exp.busy             = ADU_STATUS_BIT_CLEAR;
        status_exp.wait_cmd_arbit   = ADU_STATUS_BIT_CLEAR;
        status_exp.addr_done        = ADU_STATUS_BIT_SET;
        status_exp.data_done        = ADU_STATUS_BIT_CLEAR;
        status_exp.wait_resp        = ADU_STATUS_BIT_CLEAR;
        status_exp.overrun_err      = ADU_STATUS_BIT_CLEAR;
        status_exp.autoinc_err      = ADU_STATUS_BIT_CLEAR;
        status_exp.command_err      = ADU_STATUS_BIT_CLEAR;
        status_exp.address_err      = ADU_STATUS_BIT_CLEAR;
        status_exp.command_hang_err = ADU_STATUS_BIT_CLEAR;
        status_exp.data_hang_err    = ADU_STATUS_BIT_CLEAR;
        status_exp.pbinit_missing   = ADU_STATUS_BIT_DONT_CARE;

        // retreive actual status value
        while (num_polls < PROC_BUILD_SMP_MAX_STATUS_POLLS)
        {
            FAPI_DBG("proc_build_smp_adu_check_status: Calling library to read ADU status (poll %d)",
                     num_polls+1);
            rc = proc_adu_utils_get_adu_status(i_target,
                                               status_act);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_adu_check_status: Error from proc_adu_utils_get_adu_status");
                break;
            }

            // status reported as busy, poll again
            if (status_act.busy)
            {
                num_polls++;
            }
            // not busy, check for expected status
            else
            {
                break;
            }
        }

        // check status bits versus expected pattern
        match =
            (((status_exp.busy == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.busy == status_act.busy)) &&
             ((status_exp.wait_cmd_arbit == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.wait_cmd_arbit == status_act.wait_cmd_arbit)) &&
             ((status_exp.addr_done == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.addr_done == status_act.addr_done)) &&
             ((status_exp.data_done == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.data_done == status_act.data_done)) &&
             ((status_exp.wait_resp == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.wait_resp == status_act.wait_resp)) &&
             ((status_exp.overrun_err == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.overrun_err == status_act.overrun_err)) &&
             ((status_exp.autoinc_err == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.autoinc_err == status_act.autoinc_err)) &&
             ((status_exp.command_err == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.command_err == status_act.command_err)) &&
             ((status_exp.address_err == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.address_err == status_act.address_err)) &&
             ((status_exp.command_hang_err == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.command_hang_err == status_act.command_hang_err)) &&
             ((status_exp.data_hang_err == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.data_hang_err == status_act.data_hang_err)) &&
             ((status_exp.pbinit_missing == ADU_STATUS_BIT_DONT_CARE) ||
              (status_exp.pbinit_missing == status_act.pbinit_missing)));
        if (!match)
        {
            FAPI_ERR("proc_adu_utils_check_adu_status: Status mismatch detected");
            FAPI_ERR("proc_adu_utils_check_adu_status: ADU Status bits:");
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_BUSY           = %d",
                     (status_act.busy == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_WAIT_CMD_ARBIT = %d",
                     (status_act.wait_cmd_arbit == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_ADDR_DONE      = %d",
                     (status_act.addr_done == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_DATA_DONE      = %d",
                     (status_act.data_done == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_WAIT_RESP      = %d",
                     (status_act.wait_resp == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status: ADU Error bits:");
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_OVERRUN_ERROR        = %d",
                     (status_act.overrun_err == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_AUTOINC_ERROR        = %d",
                     (status_act.autoinc_err == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_COMMAND_ERROR        = %d",
                     (status_act.command_err == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_ADDRESS_ERROR        = %d",
                     (status_act.address_err == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_COMMAND_HANG_ERROR   = %d",
                     (status_act.command_hang_err == ADU_STATUS_BIT_SET)?(1)
                                                                        :(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_DATA_HANG_ERROR      = %d",
                     (status_act.data_hang_err == ADU_STATUS_BIT_SET)?(1):(0));
            FAPI_ERR("proc_adu_utils_check_adu_status:   FBC_ALTD_PBINIT_MISSING_ERROR = %d",
                     (status_act.pbinit_missing == ADU_STATUS_BIT_SET)?(1):(0));
            const proc_adu_utils_adu_status & STATUS_DATA = status_act;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH);
            break;
        }
    } while(0);

    FAPI_DBG("proc_build_smp_adu_check_status: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_quiesce_pb(
    proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    // ADU status/control information
    proc_adu_utils_fbc_op adu_ctl;
    proc_adu_utils_fbc_op_hp_ctl adu_hp_ctl_unused;
    bool adu_is_dirty = false;

    // mark function entry
    FAPI_DBG("proc_build_smp_quiesce_pb: Start");

    do
    {
        // build ADU control structure
        adu_ctl.ttype = ADU_FBC_OP_TTYPE_PBOP;
        adu_ctl.tsize = ADU_FBC_OP_TSIZE_PBOP_DIS_ALL_FP_EN;
        adu_ctl.address = 0x0ULL;
        adu_ctl.scope = ADU_FBC_OP_SCOPE_SYSTEM;
        adu_ctl.drop_priority = ADU_FBC_OP_DROP_PRIORITY_HIGH;
        adu_ctl.cmd_type = ADU_FBC_OP_CMD_ADDR_ONLY;
        adu_ctl.init_policy = ADU_FBC_OP_FBC_INIT_NO_OVERRIDE;
        adu_ctl.use_autoinc = false;

        // acquire ADU lock
        // only required to obtain lock for this chip, as this function will
        // only be executed when fabric is configured as single chip island
        rc = proc_build_smp_adu_acquire_lock(
            i_smp_chip.chip->this_chip,
            PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS,
            PROC_BUILD_SMP_PHASE1_ADU_PICK_LOCK);
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
        rc = proc_build_smp_adu_reset(i_smp_chip.chip->this_chip);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_quiesce_pb: Error from proc_build_smp_adu_reset");
            break;
        }

        // launch command
        rc = proc_adu_utils_send_fbc_op(i_smp_chip.chip->this_chip,
                                        adu_ctl,
                                        false,
                                        adu_hp_ctl_unused);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_quiesce_pb: Error from proc_adu_utils_send_fbc_op");
            break;
        }

        // check status
        rc = proc_build_smp_adu_check_status(i_smp_chip.chip->this_chip);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_quiesce_pb: Error from proc_build_smp_adu_check_status");
            break;
        }

        // release ADU lock
        rc = proc_build_smp_adu_release_lock(
            i_smp_chip.chip->this_chip,
            PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_quiesce_pb: Error from proc_build_smp_adu_release_lock");
            break;
        }
    } while(0);

    // if error has occurred and ADU is dirty,
    // attempt to reset ADU and free lock (propogate rc of original fail)
    if (!rc.ok() && adu_is_dirty)
    {
        (void) proc_build_smp_adu_reset(i_smp_chip.chip->this_chip);
        (void) proc_build_smp_adu_release_lock(i_smp_chip.chip->this_chip, 1);
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_quiesce_pb: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_switch_cd(
    proc_build_smp_chip& i_smp_chip)
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

        // build ADU control structure
        adu_ctl.ttype = ADU_FBC_OP_TTYPE_PMISC;
        adu_ctl.tsize = ADU_FBC_OP_TSIZE_PMISC_SWITCH_AB;
        adu_ctl.address = 0x0ULL;
        adu_ctl.scope = ADU_FBC_OP_SCOPE_SYSTEM;
        adu_ctl.drop_priority = ADU_FBC_OP_DROP_PRIORITY_HIGH;
        adu_ctl.cmd_type = ADU_FBC_OP_CMD_ADDR_ONLY;
        adu_ctl.init_policy = ADU_FBC_OP_FBC_INIT_NO_OVERRIDE;
        adu_ctl.use_autoinc = false;

        adu_hp_ctl.do_tm_quiesce = false;
        adu_hp_ctl.do_pre_quiesce = true;
        adu_hp_ctl.do_post_init = true;
        adu_hp_ctl.post_quiesce_delay = PROC_BUILD_SMP_PHASE1_POST_QUIESCE_DELAY;
        adu_hp_ctl.pre_init_delay = PROC_BUILD_SMP_PHASE1_PRE_INIT_DELAY;
        adu_hp_ctl.do_switch_ab = false;
        adu_hp_ctl.do_switch_cd = true;

        // launch command
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
        rc = proc_build_smp_adu_check_status(i_smp_chip.chip->this_chip);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_cd: Error from proc_build_smp_adu_check_status");
            break;
        }

        // release ADU lock
        rc = proc_build_smp_adu_release_lock(
            i_smp_chip.chip->this_chip,
            PROC_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_cd: Error from proc_build_smp_adu_release_lock");
            break;
        }
    } while(0);

    // if error has occurred and ADU is dirty,
    // attempt to reset ADU and free lock (propogate rc of original fail)
    if (!rc.ok() && adu_is_dirty)
    {
        (void) proc_build_smp_adu_reset(i_smp_chip.chip->this_chip);
        (void) proc_build_smp_adu_release_lock(i_smp_chip.chip->this_chip, 1);
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_switch_cd: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_switch_ab(
    proc_build_smp_chip& i_master_smp_chip,
    proc_build_smp_system& i_smp)
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
                    PROC_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS,
                    PROC_BUILD_SMP_PHASE2_ADU_PICK_LOCK);
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
            }
        }
        if (!rc.ok())
        {
            break;
        }

        // build ADU control structure
        adu_ctl.ttype = ADU_FBC_OP_TTYPE_PMISC;
        adu_ctl.tsize = ADU_FBC_OP_TSIZE_PMISC_SWITCH_AB;
        adu_ctl.address = 0x0ULL;
        adu_ctl.scope = ADU_FBC_OP_SCOPE_SYSTEM;
        adu_ctl.drop_priority = ADU_FBC_OP_DROP_PRIORITY_HIGH;
        adu_ctl.cmd_type = ADU_FBC_OP_CMD_ADDR_ONLY;
        adu_ctl.init_policy = ADU_FBC_OP_FBC_INIT_NO_OVERRIDE;
        adu_ctl.use_autoinc = false;

        adu_hp_ctl.do_tm_quiesce = false;
        adu_hp_ctl.do_pre_quiesce = true;
        adu_hp_ctl.do_post_init = true;
        adu_hp_ctl.post_quiesce_delay = PROC_BUILD_SMP_PHASE2_POST_QUIESCE_DELAY;
        adu_hp_ctl.pre_init_delay = PROC_BUILD_SMP_PHASE2_PRE_INIT_DELAY;
        adu_hp_ctl.do_switch_ab = true;
        adu_hp_ctl.do_switch_cd = false;

        // launch command
        rc = proc_adu_utils_send_fbc_op(i_master_smp_chip.chip->this_chip,
                                        adu_ctl,
                                        true,
                                        adu_hp_ctl);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_ab: Error from proc_adu_utils_send_fbc_op");
            break;
        }

        // check status
        rc = proc_build_smp_adu_check_status(i_master_smp_chip.chip->this_chip);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_switch_ab: Error from proc_build_smp_adu_check_status");
            break;
        }

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
                    PROC_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_switch_ab: Error from proc_build_smp_adu_release_lock");
                    break;
                }
            }
        }
    } while(0);


    // if error has occurred and any ADU is dirty,
    // attempt to reset all ADUs and free locks (propogate rc of original fail)
    if (!rc.ok() && adu_is_dirty)
    {
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
    FAPI_DBG("proc_build_smp_switch_ab: End");
    return rc;
}


} // extern "C"


