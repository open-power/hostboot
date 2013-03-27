/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/thread_activate/proc_thread_control/proc_thread_control.C $ */
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
// $Id: proc_thread_control.C,v 1.20 2013/03/15 15:03:58 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_thread_control
// *! DESCRIPTION : Core Thread start/stop/step/query/activate operations
// *!               Use to start (start or sreset) thread instruction execution,
// *!                 stop instruction execution, or single instruction step.
// *!                 Activate is used to put a POR state thread in the proper
// *!                 state to enable ram prior to starting.
// *!               Also used to query the state of a thread.
// *! OWNER NAME  : Lance Karm          Email: karm@us.ibm.com
// *! BACKUP NAME : Sebastien Lafontant Email: slafont@us.ibm.com
//------------------------------------------------------------------------------
#include <fapi.H>
#include "proc_thread_control.H"

extern "C"
{
    //--------------------------------------------------------------------------
    // Function definitions
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // function: proc_thread_control: utility subroutine to control thread state
    // parameters: i_target   => core target
    //             i_thread   => thread (0..7)
    //             i_command  =>
    //               PTC_CMD_SRESET => initiate sreset thread command
    //               PTC_CMD_START  => initiate start thread command
    //               PTC_CMD_STOP   => initiate stop thread command
    //               PTC_CMD_STEP   => initiate step thread command
    //               PTC_CMD_QUERY  => query and return thread state
    //                                 return data in o_ras_status
    //             i_warncheck => convert pre/post checks errors to warnings
    //             i_activate => initiate activate thread command
    //             o_ras_status  => output: complete RAS status register
    //             o_state       => output: thread state info
    //                               see proc_thread_control.H
    //                               for bit enumerations:
    //                               THREAD_STATE_*
    // returns: FAPI_RC_SUCCESS if operation was successful,
    //          function-specific fail codes (see function definitions),
    //          else error
    //--------------------------------------------------------------------------
    fapi::ReturnCode proc_thread_control(const fapi::Target& i_target,
            const uint8_t i_thread, const uint8_t i_command,
            const bool i_warncheck, ecmdDataBufferBase& o_ras_status,
            uint64_t& o_state)
    {
        fapi::ReturnCode rc;
        uint32_t rc_ecmd = 0;

        FAPI_INF("proc_thread_control : Start");

        do
        {
            rc_ecmd |= o_ras_status.setBitLength(64);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_thread_control: Error setting up data buffer");
                rc.setEcmdError(rc_ecmd);
                break;
            }

            if (i_command == PTC_CMD_SRESET)
            {
                rc = proc_thread_control_sreset(i_target, i_thread, i_warncheck,
                        o_ras_status, o_state);
                break;
            }
            if (i_command == PTC_CMD_START)
            {
                rc = proc_thread_control_start(i_target, i_thread, i_warncheck,
                        o_ras_status, o_state);
                break;
            }
            if (i_command == PTC_CMD_STOP)
            {
                rc = proc_thread_control_stop(i_target, i_thread, i_warncheck,
                        o_ras_status, o_state);
                break;
            }
            if (i_command == PTC_CMD_STEP)
            {
                rc = proc_thread_control_step(i_target, i_thread, i_warncheck,
                        o_ras_status, o_state);
                break;
            }
            if (i_command == PTC_CMD_ACTIVATE)
            {
                rc = proc_thread_control_activate(i_target, i_thread,
                        o_ras_status, o_state);
                break;
            }
            if (i_command == PTC_CMD_QUERY)
            {
                rc = proc_thread_control_query(i_target, i_thread, o_ras_status,
                        o_state);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_thread_control: ERROR calling proc_thread_control_query for thread %d", i_thread);
                    break;
                }
                break;
            }

            FAPI_ERR("proc_thread_control: ERROR - invalid command issued to proc_thread_control");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_THREAD_CONTROL_INV_COMMAND);

        }
        while(0);
        return rc;
    } // proc_thread_control

    //--------------------------------------------------------------------------
    // function: proc_thread_control_sreset: utility subroutine to sreset
    //           a thread
    // parameters: i_target   => core target
    //             i_thread   => thread (0..7)
    //             i_warncheck => convert check errors to warnings
    //             o_ras_status  => output: complete RAS status register
    //             o_state       => output: thread state info
    //                               see proc_thread_control.H
    //                               for bit enumerations:
    //                               THREAD_STATE_*
    // returns: FAPI_RC_SUCCESS if operation was successful,
    //          RC_PROC_THREAD_CONTROL_SRESET_FAIL if sreset command failed,
    //          else error
    //--------------------------------------------------------------------------
    fapi::ReturnCode proc_thread_control_sreset(const fapi::Target& i_target,
            const uint8_t i_thread, const bool i_warncheck,
            ecmdDataBufferBase& o_ras_status, uint64_t& o_state)
    {
        fapi::ReturnCode rc;
        uint32_t rc_ecmd = 0;

        ecmdDataBufferBase scomData(64);

        uint32_t directControlAddr = EX_PERV_TCTL0_DIRECT_0x10013000 +
            (i_thread << 4);

        do
        {
            FAPI_DBG("proc_thread_control_sreset : Initiating sreset command to core PC logic for thread %d", i_thread);

            // Setup & Initiate SReset Command
            rc_ecmd |= scomData.flushTo0();
            rc_ecmd |= scomData.setBit(PTC_DIR_CTL_SP_SRESET);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_thread_control_sreset: Error setting up data buffer");
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, directControlAddr, scomData);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_sreset: fapiPutScom error when issuing sp_sreset to thread %d", i_thread);
                break;
            }

            // Post-conditions check
            rc = proc_thread_control_query(i_target, i_thread, o_ras_status,
                    o_state);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_sreset: ERROR checking RAS_STATUS bits for thread %d", i_thread);
                break;
            }
            if (!(o_state & THREAD_STATE_INSTCOMP))
            {
                if (i_warncheck)
                {
                    FAPI_INF("proc_thread_control_sreset: WARNING: Thread SReset issued, but no instructions have completed.  SReset might have failed");
                    break;
                }
                else
                {
                    FAPI_ERR("proc_thread_control_sreset: ERROR: Thread SReset issued, but no instructions have completed.  SReset might have failed for thread %d", i_thread);
                    FAPI_SET_HWP_ERROR(rc,
                            RC_PROC_THREAD_CONTROL_SRESET_FAIL);
                    break;
                }
            }

            FAPI_INF("proc_thread_control_sreset : sreset command issued for thread %d", i_thread);
            break;
        }
        while (0);
        return rc;
    } // proc_thread_control_sreset

    //--------------------------------------------------------------------------
    // function: proc_thread_control_start: utility subroutine to start a thread
    // parameters: i_target   => core target
    //             i_thread   => thread (0..7)
    //             i_warncheck => convert check errors to warnings
    //             o_ras_status  => output: complete RAS status register
    //             o_state       => output: thread state info
    //                               see proc_thread_control.H
    //                               for bit enumerations:
    //                               THREAD_STATE_*
    // returns: FAPI_RC_SUCCESS if operation was successful,
    //          RC_PROC_THREAD_CONTROL_START_PRE_NOMAINT if maintenance bit
    //             was not set before start was issued
    //          RC_PROC_THREAD_CONTROL_START_FAIL if start command failed,
    //          else error
    //--------------------------------------------------------------------------
    fapi::ReturnCode proc_thread_control_start(const fapi::Target& i_target,
            const uint8_t i_thread, const bool i_warncheck,
            ecmdDataBufferBase& o_ras_status, uint64_t& o_state)
    {
        fapi::ReturnCode rc;
        uint32_t rc_ecmd = 0;

        ecmdDataBufferBase scomData(64);

        uint32_t directControlAddr = EX_PERV_TCTL0_DIRECT_0x10013000 +
            (i_thread << 4);

        do
        {
            FAPI_DBG("proc_thread_control_start : Initiating start command to core PC logic for thread %d", i_thread);

            // Check Preconditions: look for Core Maintenance Mode
            rc = proc_thread_control_query(i_target, i_thread, o_ras_status,
                    o_state);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_start: ERROR checking RAS_STATUS bits for thread %d", i_thread);
                break;
            }
            if (!(o_state & THREAD_STATE_MAINT))
            {
                if (i_warncheck)
                {
                    FAPI_INF("proc_thread_control_start: WARNING: Aborting Start Command for Thread %d - Maintenance bit is not on", i_thread);
                    break;
                }
                else
                {
                    FAPI_ERR("proc_thread_control_start: Start Precondition Check failed: RAS Status Maintenance bit is not on for thread %d", i_thread);
                    FAPI_SET_HWP_ERROR(rc,
                            RC_PROC_THREAD_CONTROL_START_PRE_NOMAINT);
                    break;
                }
            }

            // Issue Start Command
            rc_ecmd |= scomData.flushTo0();
            rc_ecmd |= scomData.setBit(PTC_DIR_CTL_SP_START);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_thread_control_start: Error setting up data buffer");
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, directControlAddr, scomData);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_start: fapiPutScom error when issuing sp_start to thread %d", i_thread);
                break;
            }

            // Check Postconditions (for warning/debug)
            rc = proc_thread_control_query(i_target, i_thread, o_ras_status,
                    o_state);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_start: ERROR checking RAS_STATUS bits for thread %d", i_thread);
                break;
            }
            if (!(o_state & THREAD_STATE_INSTCOMP))
            {
                if (i_warncheck)
                {
                    FAPI_INF("proc_thread_control_start: WARNING: Thread Start issued, but no instructions have completed.  Start might have failed");
                    break;
                }
                else
                {
                    FAPI_ERR("proc_thread_control_start: ERROR: Thread Start issued, but no instructions have completed.  Start might have failed for thread %d", i_thread);
                    FAPI_SET_HWP_ERROR(rc,
                            RC_PROC_THREAD_CONTROL_START_FAIL);
                    break;
                }
            }

            FAPI_INF("proc_thread_control_start : Start command issued for thread %d", i_thread);
            break;
        }
        while (0);
        return rc;
    } // proc_thread_control_start

    //--------------------------------------------------------------------------
    // function: proc_thread_control_stop: utility subroutine to stop a thread
    // parameters: i_target   => core target
    //             i_thread   => thread (0..7)
    //             i_warncheck => convert check errors to warnings
    //             o_ras_status  => output: complete RAS status register
    //             o_state       => output: thread state info
    //                               see proc_thread_control.H
    //                               for bit enumerations:
    //                               THREAD_STATE_*
    // returns: FAPI_RC_SUCCESS if operation was successful,
    //          RC_PROC_THREAD_CONTROL_STOP_FAIL if stop command failed,
    //          else error
    //--------------------------------------------------------------------------
    fapi::ReturnCode proc_thread_control_stop(const fapi::Target& i_target,
            const uint8_t i_thread, const bool i_warncheck,
            ecmdDataBufferBase& o_ras_status, uint64_t& o_state)
    {
        fapi::ReturnCode rc;
        uint32_t rc_ecmd = 0;

        ecmdDataBufferBase scomData(64);

        uint32_t directControlAddr = EX_PERV_TCTL0_DIRECT_0x10013000 +
            (i_thread << 4);

        do
        {
            FAPI_INF("proc_thread_control_stop : Initiating stop command to core PC logic for thread %d", i_thread);

            rc_ecmd |= scomData.flushTo0();
            rc_ecmd |= scomData.setBit(PTC_DIR_CTL_SP_STOP);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_thread_control_stop: Error setting up data buffer");
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // Issue Stop
            rc = fapiPutScom(i_target, directControlAddr, scomData);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_stop: fapiPutScom error when issuing sp_stop to thread %d", i_thread);
                break;
            }

            // Post-condition check
            rc = proc_thread_control_query(i_target, i_thread, o_ras_status,
                    o_state);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_stop: ERROR checking RAS_STATUS bits for thread %d", i_thread);
                break;
            }
            if (o_state & THREAD_STATE_CHKSTOP)
            {
                FAPI_INF("proc_thread_control_stop: WARNING: RAS Status register indicated checkstop after Thread Stop command was issued");
                break;
            }
            if (!(o_state & THREAD_STATE_MAINT))
            {
                if (i_warncheck)
                {
                    FAPI_INF("proc_thread_control_stop: WARNING: Thread Stop failed: RAS Status Maintenance bit is not on");
                    break;
                }
                else
                {
                    FAPI_ERR("proc_thread_control_stop: Thread Stop failed: RAS Status Maintenance bit is not on for thread %d", i_thread);
                    FAPI_SET_HWP_ERROR(rc,
                            RC_PROC_THREAD_CONTROL_STOP_FAIL);
                    break;
                }
            }

            FAPI_INF("proc_thread_control_stop : stop command successful for thread %d", i_thread);
            break;
        }
        while(0);
        return rc;
    } // proc_thread_control_stop

    //--------------------------------------------------------------------------
    // function: proc_thread_control_step: utility subroutine to single-
    //             instruction step a thread
    // parameters: i_target   => core target
    //             i_thread   => thread (0..7)
    //             i_warncheck => convert check errors to warnings
    //             o_ras_status  => output: complete RAS status register
    //             o_state       => output: thread state info
    //                               see proc_thread_control.H
    //                               for bit enumerations:
    //                               THREAD_STATE_*
    // returns: FAPI_RC_SUCCESS if operation was successful,
    //          RC_PROC_THREAD_CONTROL_STEP_PRE_NOMAINT if maintenance bit
    //             was not set before step was issued
    //          RC_PROC_THREAD_CONTROL_STEP_FAIL if step command failed,
    //          else error
    //--------------------------------------------------------------------------
    fapi::ReturnCode proc_thread_control_step(const fapi::Target& i_target,
            const uint8_t i_thread, const bool i_warncheck,
            ecmdDataBufferBase& o_ras_status, uint64_t& o_state)
    {
        fapi::ReturnCode rc;
        uint32_t rc_ecmd = 0;

        ecmdDataBufferBase scomData(64);

        uint32_t directControlAddr = EX_PERV_TCTL0_DIRECT_0x10013000 +
            (i_thread << 4);
        uint32_t rasModeAddr = EX_PERV_TCTL0_R_MODE_0x10013001 +
            (i_thread << 4);

        do
        {
            FAPI_DBG("proc_thread_control_step: Initiating step command to core PC logic for thread %d", i_thread);

            // Check Preconditions
            rc = proc_thread_control_query(i_target, i_thread, o_ras_status,
                    o_state);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_step: ERROR checking RAS_STATUS bits for thread %d", i_thread);
                break;
            }
            if (!(o_state & THREAD_STATE_MAINT))
            {
                FAPI_ERR("proc_thread_control_step: Step Precondition failed: RAS Status Maintenance bit is not on for thread %d", i_thread);
                FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_THREAD_CONTROL_STEP_PRE_NOMAINT);
                break;
            }

            // Set Single Mode
            ecmdDataBufferBase rasModeSave;
            rc = fapiGetScom(i_target, rasModeAddr, rasModeSave);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_step: fapiPutScom error when reading ras_mode register for thread %d", i_thread);
                break;
            }
            scomData = rasModeSave;
            rc_ecmd |= scomData.setBit(PTC_RAS_MODE_SINGLE);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_thread_control_step: Error setting up data buffer");
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, rasModeAddr, scomData);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_step: fapiPutScom error when single step mode in ras_mode register for thread %d", i_thread);
                break;
            }

            // Issue Step Command
            rc_ecmd |= scomData.flushTo0();
            rc_ecmd |= scomData.setBit(PTC_DIR_CTL_SP_STEP);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_thread_control_step: Error setting up data buffer");
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, directControlAddr, scomData);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_step: fapiPutScom error when issuing sp_step to thread %d", i_thread);
                break;
            }

            // Poll for step complete
            uint8_t stepCompletePollCount = 0;
            bool step_complete = false;
            do
            {
                rc = proc_thread_control_query(i_target, i_thread,
                        o_ras_status, o_state);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_thread_control_start: ERROR checking RAS_STATUS bits for thread %d", i_thread);
                    break;
                }
                if (o_state & THREAD_STATE_INSTCOMP)
                {
                    step_complete = true;
                    break;
                }
                stepCompletePollCount++;
                if (stepCompletePollCount > PTC_STEP_COMP_POLL_LIMIT) {
                    if (i_warncheck)
                    {
                        FAPI_INF("proc_thread_control_step: WARNING: Thread Step failed: RAS Status Group/Inst Complete bit is not on after %d poll attempts.  WARNING: RAS_MODE bit %d still in single instruction mode!  Thread %d", PTC_STEP_COMP_POLL_LIMIT, PTC_RAS_MODE_SINGLE, i_thread);
                        break;
                    }
                    else
                    {
                        FAPI_ERR("proc_thread_control_step: Thread Step failed: RAS Status Group/Inst Complete bit is not on after %d poll attempts.  WARNING: RAS_MODE bit %d still in single instruction mode!  Thread %d", PTC_STEP_COMP_POLL_LIMIT, PTC_RAS_MODE_SINGLE, i_thread);
                        FAPI_SET_HWP_ERROR(rc,
                                RC_PROC_THREAD_CONTROL_STEP_FAIL);
                        break;
                    }
                }
            }
            while(1);

            // break if error detected in polling
            if (!rc.ok())
            {
                break;
            }

            // Restore RasMode register (Exit Single Mode)
            if (step_complete)
            {
                FAPI_DBG("proc_thread_control_step : Instruction step complete.  Clearing single inst mode.");
                rc = fapiPutScom(i_target, rasModeAddr, rasModeSave);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_thread_control_step: fapiPutScom error when restoring ras_mode register for thread %d", i_thread);
                    break;
                }

                FAPI_INF("proc_thread_control_step : step command successful for thread %d", i_thread);
            }
            break;
        }
        while(0);
        return rc;
    } // proc_thread_control_step

    //--------------------------------------------------------------------------
    // function: proc_thread_control_activate: utility subroutine to activate
    //             a thread in POR state to enable ramming
    // parameters: i_target   => core target
    //             i_thread   => thread (0..7)
    //             o_ras_status  => output: complete RAS status register
    //             o_state       => output: thread state info
    //                               see proc_thread_control.H
    //                               for bit enumerations:
    //                               THREAD_STATE_*
    // returns: FAPI_RC_SUCCESS if operation was successful,
    //          RC_PROC_THREAD_CONTROL_ACTIVATE_FAIL if activate command failed,
    //          else error
    //--------------------------------------------------------------------------
    fapi::ReturnCode proc_thread_control_activate(const fapi::Target& i_target,
            const uint8_t i_thread, ecmdDataBufferBase& o_ras_status, uint64_t&
            o_state)
    {
        fapi::ReturnCode rc;
        uint32_t rc_ecmd = 0;

        ecmdDataBufferBase scomData(64);
        o_ras_status.setBitLength(64);

        do
        {
            FAPI_DBG("proc_thread_control_activate : Initiating activate thread command to core PC logic for thread %d", i_thread);
            uint8_t thd_activate_bit = PTC_RAM_THREAD_ACTIVE_T0 + i_thread;
            rc = fapiGetScom(i_target, EX_PERV_THREAD_ACTIVE_0x1001310E,
                    scomData);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_activate: fapiGetScom error when reading THREAD_ACTIVE register for thread %d", i_thread);
                break;
            }
            if (scomData.isBitSet(thd_activate_bit))
            {
                FAPI_INF("proc_thread_control_activate: Thread %d activate bit already set.  No action required.", i_thread);
                break;
            }
            rc_ecmd |= scomData.setBit(thd_activate_bit);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_thread_control_activate: Error setting up data buffer");
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, EX_PERV_THREAD_ACTIVE_0x1001310E,
                    scomData);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_activate: fapiPutScom error writing to THREAD_ACTIVE register when activating thread %d for RAM", i_thread);
                break;
            }
            rc = fapiGetScom(i_target, EX_PERV_THREAD_ACTIVE_0x1001310E,
                    scomData);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_activate: fapiGetScom error when reading THREAD_ACTIVE register for thread %d", i_thread);
                break;
            }
            if (scomData.isBitClear(thd_activate_bit))
            {
                FAPI_ERR("proc_thread_control_activate: Activate Thread failed: Thread Active bit is still off.");
                FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_THREAD_CONTROL_ACTIVATE_FAIL);
                break;
            }

            // Always return RAS_STATUS and state
            rc = proc_thread_control_query(i_target, i_thread, o_ras_status,
                    o_state);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_activate: error calling proc_thread_control_query for thread %d", i_thread);
                break;
            }

            FAPI_INF("proc_thread_control_activate : activate command successful for thread %d.", i_thread);
            break;
        }
        while(0);
        return rc;
    } // proc_thread_control_activate

    //--------------------------------------------------------------------------
    // function: proc_thread_control_query: utility subroutine to check
    //           various thread status bits
    // parameters: i_target   => core target
    //             i_thread   => thread (0..7)
    //             o_ras_status  => output: complete RAS status register
    //             o_state       => output: thread state info
    //                               see proc_thread_control.H
    //                               for bit enumerations:
    //                               THREAD_STATE_*
    // returns: FAPI_RC_SUCCESS if operation was successful,
    //          else SCOM read failure
    //--------------------------------------------------------------------------
    fapi::ReturnCode proc_thread_control_query(const fapi::Target&
            i_target, const uint8_t i_thread, ecmdDataBufferBase& o_ras_status,
            uint64_t& o_state)
    {
        fapi::ReturnCode rc;
        ecmdDataBufferBase scomData;

        uint32_t rasStatAddr = EX_PERV_TCTL0_R_STAT_0x10013002 +
            (i_thread << 4);
        o_ras_status.setBitLength(64);  // this also clears the buffer

        do
        {
            FAPI_INF("proc_thread_control_query: Start");

            o_state = 0;

            rc = fapiGetScom(i_target, rasStatAddr, scomData);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_query: fapiGetScom error when reading TCTL_R_STAT register for thread %d", i_thread);
                break;
            }
            o_ras_status = scomData;

            if (o_ras_status.isBitSet(PTC_RAS_STAT_CHKSTOP))
            {
                o_state |= THREAD_STATE_CHKSTOP;
            }
            if (o_ras_status.isBitSet(PTC_RAS_STAT_MAINT))
            {
                o_state |= THREAD_STATE_MAINT;
            }
            if (o_ras_status.isBitSet(PTC_RAS_STAT_INST_COMP))
            {
                o_state |= THREAD_STATE_INSTCOMP;
            }
            if (o_ras_status.isBitSet(PTC_RAS_STAT_THD_POR))
            {
                o_state |= THREAD_STATE_POR;
            }
            if (o_ras_status.isBitSet(PTC_RAS_STAT_ENABLED))
            {
                o_state |= THREAD_STATE_ENABLED;
            }
            // Threads that are not in maintenance and not checkstopped are also considered 'running'
            if (o_ras_status.isBitSet(PTC_RAS_STAT_RUN_BIT)  ||
               ((!o_ras_status.isBitSet(PTC_RAS_STAT_MAINT)) &&
                (!o_ras_status.isBitSet(PTC_RAS_STAT_CHKSTOP))))
            {
                o_state |= THREAD_STATE_RUNNING;
            }
            if (o_ras_status.isBitSet(PTC_RAS_STAT_THD_QUIESCED))
            {
                o_state |= THREAD_STATE_QUIESCED;
            }
            if (o_ras_status.isBitSet(PTC_RAS_STAT_THD_STARTING))
            {
                o_state |= THREAD_STATE_STARTING;
            }
            if (o_ras_status.isBitSet(PTC_RAS_STAT_THD_STOPPING))
            {
                o_state |= THREAD_STATE_STOPPING;
            }

            uint8_t thd_ram_active_bit = PTC_RAM_THREAD_ACTIVE_T0 + i_thread;
            rc = fapiGetScom(i_target, EX_PERV_THREAD_ACTIVE_0x1001310E,
                    scomData);
            if (!rc.ok())
            {
                FAPI_ERR("proc_thread_control_query: fapiGetScom error when reading THREAD_ACTIVE register for thread %d", i_thread);
                break;
            }
            if (scomData.isBitSet(thd_ram_active_bit))
            {
                o_state |= THREAD_STATE_RAM_ACTIVE;
            }

            FAPI_INF("proc_thread_control_query: thread state=%016llX (ras_status=%016llX)", o_state, o_ras_status.getDoubleWord(0));
        }
        while (0);
        return rc;
    } // proc_thread_control_query
}  // extern "C"
