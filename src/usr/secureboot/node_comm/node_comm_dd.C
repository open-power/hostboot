/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_dd.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/**
 * @file node_comm_dd.C
 *
 * @brief Implementation of the Secure Node Communications device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <secureboot/secure_reasoncodes.H>

#include "node_comm_dd.H"
#include "node_comm.H"
#include "../common/errlud_secure.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_nc = nullptr;
TRAC_INIT( & g_trac_nc, NODECOMM_TRACE_NAME, KILOBYTE );


// ----------------------------------------------
// Defines
// ----------------------------------------------
// If the link(s) are up the operation should complete right away
// so there will only be a short polling window
#define NODE_COMM_DD_POLL_DELAY_NS 1   // Sleep for 1ns per poll
#define NODE_COMM_DD_POLL_DELAY_TOTAL_NS 10 // Total time to poll


using namespace TARGETING;

namespace SECUREBOOT
{

namespace NODECOMM
{

// Register the generic I2C perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::NODECOMM,
                       TARGETING::TYPE_PROC,
                       nodeCommPerformOp );

errlHndl_t nodeCommPerformOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         va_list i_args )
{
    errlHndl_t err = nullptr;
    bool unlock_mutex = false;
    node_comm_args_t node_comm_args;

    uint64_t linkId = va_arg( i_args, uint64_t );
    node_comm_args.linkId = static_cast<uint8_t>(linkId);

    uint64_t mboxId = va_arg( i_args, uint64_t );
    node_comm_args.mboxId = static_cast<uint8_t>(mboxId);

    node_comm_args.data_ptr = reinterpret_cast<uint64_t*>(io_buffer);
    node_comm_args.tgt = i_target;
    node_comm_args.tgt_huid = TARGETING::get_huid(i_target);

    do
    {

    // Verify OP type
    if ( (i_opType != DeviceFW::READ) &&
         (i_opType != DeviceFW::WRITE) )
    {
        TRACFCOMP( g_trac_nc,ERR_MRK"nodeCommPerformOp: Invalid opType: 0x%X",
                   i_opType);
        /*@
         * @errortype
         * @moduleid     MOD_NCDD_PERFORM_OP
         * @reasoncode   RC_NCDD_INVALID_OP_TYPE
         * @userdata1    Operation type
         * @userdata2    Input Target HUID
         * @devdesc      NodeComm DD invalid operation type
         * @custdesc     Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            MOD_NCDD_PERFORM_OP,
                            RC_NCDD_INVALID_OP_TYPE,
                            i_opType,
                            node_comm_args.tgt_huid,
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        break;
    }

    // Check other input parameters
    if (    (node_comm_args.linkId > NCDD_MAX_LINK_ID)
         || (node_comm_args.mboxId > NCDD_MAX_MBOX_ID)
         || (node_comm_args.data_ptr == nullptr)
       )
    {
        TRACFCOMP( g_trac_nc,ERR_MRK"nodeCommPerformOp: Invalid Input Args!"
                   " linkId=0x%X (max=0x%X), mboxId=0x%X, "
                   " data_ptr=%p",
                   node_comm_args.linkId,
                   NCDD_MAX_LINK_ID, node_comm_args.mboxId,
                   node_comm_args.data_ptr);

        /*@
         * @errortype
         * @reasoncode       RC_NCDD_INVALID_ARGS
         * @moduleid         MOD_NCDD_PERFORM_OP
         * @userdata1[0:15]  LinkId Value
         * @userdata1[16:31] MAX possile LinkId Value
         * @userdata1[32:47] MailboxId Value
         * @userdata1[48:63] MAX possible MailboxId Value
         * @userdata2        Input Data Pointer
         * @devdesc          Invalid Input Args for Node Comm DD call
         * @custdesc         Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_NCDD_PERFORM_OP,
                                       RC_NCDD_INVALID_ARGS,
                                       FOUR_UINT16_TO_UINT64(
                                         node_comm_args.linkId,
                                         NCDD_MAX_LINK_ID,
                                         node_comm_args.mboxId,
                                         NCDD_MAX_MBOX_ID),
                                       reinterpret_cast<uint64_t>(
                                         node_comm_args.data_ptr),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
        break;
    }

    TRACUTCOMP(g_trac_nc,ENTER_MRK"nodeCommPerformOp: %s: "
              "tgt=0x%X, LinkId=%d, MboxId=%d, data=0x%.16llX",
              ( i_opType == DeviceFW::READ ) ? "read" : "write",
              node_comm_args.tgt_huid, node_comm_args.linkId,
              node_comm_args.mboxId, (*node_comm_args.data_ptr));

    // Mutex Lock
    mutex_lock(node_comm_args.tgt->
            getHbMutexAttr<TARGETING::ATTR_HB_NODE_COMM_MUTEX>());
    unlock_mutex = true;

    /***********************************************/
    /* Node Comm Read                              */
    /***********************************************/
    if ( i_opType == DeviceFW::READ )
    {
        err = ncddRead( node_comm_args );
    }

    /***********************************************/
    /* Node Comm Write                             */
    /***********************************************/
    else if( i_opType == DeviceFW::WRITE )
    {
        err = ncddWrite( node_comm_args );
    }

    // Handle Error from Operation (like a reset, if necessary)
    if( err )
    {

        ncddHandleError( err,
                         node_comm_args );
        break;
    }

    }
    while (0);

    // If err, add trace and FFDC to log
    if (err)
    {
        err->collectTrace(SECURE_COMP_NAME);
        err->collectTrace(NODECOMM_TRACE_NAME);

        UdNodeCommInfo(i_opType,
                       io_buflen,
                       i_accessType,
                       node_comm_args)
                      .addToLog(err);

        if (err->reasonCode() != RC_NCDD_INVALID_ARGS)
        {
            // Collect FFDC - Target and Registers
            getNodeCommFFDC(node_comm_args.tgt,
                            err);
        }
    }

    // Mutex unlock
    if (unlock_mutex == true)
    {
        mutex_unlock(node_comm_args.tgt->
              getHbMutexAttr<TARGETING::ATTR_HB_NODE_COMM_MUTEX>());
    }

    TRACUTCOMP (g_trac_nc, EXIT_MRK"nodeCommPerformOp: %s: "
               "tgt=0x%X, LinkId=%d, MboxId=%d, data=0x%.16llX. "
               TRACE_ERR_FMT,
               ( i_opType == DeviceFW::READ ) ? "read" : "write",
               node_comm_args.tgt_huid,
               node_comm_args.linkId, node_comm_args.mboxId,
               (node_comm_args.data_ptr != nullptr)
                ? (*node_comm_args.data_ptr) : 0,
               TRACE_ERR_ARGS(err));

    return err;
} // end nodeCommPerformOp

errlHndl_t ncddRead(node_comm_args_t & i_args)
{
    errlHndl_t err = nullptr;

    do
    {
    // Determine correct Link Mailbox Register based on inputs
    const uint64_t link_mbox_reg = getLinkMboxReg(i_args.linkId, i_args.mboxId);

    // Read data from the correct LinkId/Mailbox Register
    err = ncddRegisterOp( DeviceFW::READ,
                          i_args.data_ptr,
                          link_mbox_reg,
                          i_args );

    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"ncddRead: SCOM deviceRead call "
            "failed for Target HUID 0x%08X and address 0x%016llX. "
            TRACE_ERR_FMT,
            i_args.tgt_huid,
            link_mbox_reg,
            TRACE_ERR_ARGS(err));
        break;
    }

    // Since Read above was successful, clear the data register
    uint64_t clear_data = 0x0;
    err = ncddRegisterOp( DeviceFW::WRITE,
                          &clear_data,
                          link_mbox_reg,
                          i_args );

    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"ncddRead: SCOM deviceWrite call "
            "failed for Target HUID 0x%08X and address 0x%016llX. "
            TRACE_ERR_FMT,
            i_args.tgt_huid,
            link_mbox_reg,
            TRACE_ERR_ARGS(err));
        break;
    }


    // Since Read above was successful, clear the FIR bit
    uint64_t fir_attn_bit = getLinkMboxFirAttnBit(i_args.linkId, i_args.mboxId);

    // Invert the fir bit and WOX_AND it into the register
    uint64_t clear_fir_bit = ~fir_attn_bit;

    uint64_t reg_addr = NCDD_REG_FIR_WOX_AND;

    TRACUTCOMP(g_trac_nc,"ncddRead: Clearing FIR bit 0x%.16llX based on "
              "linkId=%d, mboxId=%d, by writing 0x%.16llX to FIR Reg "
              "Addr 0x%.16llX on Target 0x%X",
              fir_attn_bit, i_args.linkId, i_args.mboxId,
              clear_fir_bit, reg_addr, i_args.tgt_huid);

    err = ncddRegisterOp( DeviceFW::WRITE,
                          &clear_fir_bit,
                          NCDD_REG_FIR_WOX_AND,
                          i_args );

    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"ncddRead: SCOM deviceWrite call "
            "failed for Target HUID 0x%08X and address 0x%016llX. "
            TRACE_ERR_FMT,
            i_args.tgt_huid,
            link_mbox_reg,
            TRACE_ERR_ARGS(err));
        break;
    }


    } while( 0 );

    TRACUTCOMP( g_trac_nc,EXIT_MRK"ncddRead: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));

    return err;

} // end ncddRead

errlHndl_t ncddWrite (node_comm_args_t & i_args)
{
    errlHndl_t err = nullptr;

    do
    {
    // Write data to data movement register
    err = ncddRegisterOp( DeviceFW::WRITE,
                          i_args.data_ptr,
                          NCDD_REG_DATA,
                          i_args );

    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"ncddWrite: SCOM deviceWrite call "
            "failed for Target HUID 0x%08X and address 0x%016llX. "
            TRACE_ERR_FMT,
            i_args.tgt_huid,
            NCDD_REG_DATA,
            TRACE_ERR_ARGS(err));
        break;
    }


    // Write Control Reg to send the data
    ctrl_reg_t ctrl_reg_cmd;
    ctrl_reg_cmd.value = 0x0;

    ctrl_reg_cmd.start_stop = 1; // to start the command
    ctrl_reg_cmd.write_not_read = 1;  // write command
    ctrl_reg_cmd.mbox_id = i_args.mboxId;
    ctrl_reg_cmd.link_id = i_args.linkId;


    err = ncddRegisterOp( DeviceFW::WRITE,
                          &ctrl_reg_cmd.value,
                          NCDD_REG_CTRL,
                          i_args );

    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"ncddWrite: SCOM deviceWrite call "
            "failed for Target HUID 0x%08X and address 0x%016llX. "
            TRACE_ERR_FMT,
            i_args.tgt_huid,
            NCDD_REG_CTRL,
            TRACE_ERR_ARGS(err));
        break;
    }

    // Wait for command to be complete
    ctrl_reg_cmd.value = 0;
    err = ncddWaitForCmdComp(i_args, ctrl_reg_cmd);
    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"ncddWrite: Wait For Cmd Complete "
            "failed for Target HUID 0x%08X. "
            TRACE_ERR_FMT,
            i_args.tgt_huid,
            TRACE_ERR_ARGS(err));
        break;
    }

    // Check for 'sent' bit being set
    if (ctrl_reg_cmd.sent != 1)
    {
        TRACFCOMP( g_trac_nc,
                   ERR_MRK"ncddWrite: 'Sent' bit not set in status reg: "
                   "0x%.16llX (Target 0x%X)",
                   ctrl_reg_cmd.value, i_args.tgt_huid );

        /*@
         * @errortype
         * @reasoncode       RC_NCDD_DATA_NOT_SENT
         * @moduleid         MOD_NCDD_WRITE
         * @userdata1        Status Register Value
         * @userdata2        Target HUID
         * @devdesc          Sent bit not set in Node Comm status/ctrl register
         * @custdesc         Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_NCDD_WRITE,
                                       RC_NCDD_DATA_NOT_SENT,
                                       ctrl_reg_cmd.value,
                                       i_args.tgt_huid);

        // Likely an issue with Processor or its bus
        addNodeCommBusCallout(i_args.tgt,
                              i_args.linkId,
                              err);

        // Or HB code failed to do the procedure correctly
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_LOW);

        break;
    }

    } while( 0 );

    TRACUTCOMP( g_trac_nc,EXIT_MRK"ncddWrite: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));

    return err;

} // end ncddWrite


errlHndl_t ncddCheckStatus (node_comm_args_t & i_args,
                            const ctrl_reg_t & i_statusVal )
{
    errlHndl_t err = nullptr;
    bool errorFound = false;

    TRACUTCOMP( g_trac_nc,
               ENTER_MRK"ncddCheckStatus(): Tgt=0x%X: 0x%.16llX",
               i_args.tgt_huid,
               i_statusVal.value );

    do
    {
        if( 1 == i_statusVal.bad_addr )
        {
            errorFound = true;
            TRACFCOMP(g_trac_nc,ERR_MRK
                      "Node Comm DD: Bad Address! - status reg: 0x%016llx",
                      i_statusVal.value );
        }

        if( 1 == i_statusVal.link_down )
        {
            errorFound = true;
            TRACFCOMP(g_trac_nc,ERR_MRK
                      "Node Comm DD: Link Down! - status reg: 0x%016llx",
                      i_statusVal.value );
        }

        if( 1 == i_statusVal.corrupt )
        {
            errorFound = true;
            TRACFCOMP(g_trac_nc,ERR_MRK
                      "Node Comm DD: Corrupt! - status reg: 0x%016llx",
                      i_statusVal.value );
        }

        if( 1 == i_statusVal.bad_write )
        {
            errorFound = true;
            TRACFCOMP(g_trac_nc,ERR_MRK
                      "Node Comm DD: Bad Write! - status reg: 0x%016llx",
                      i_statusVal.value );
        }

        // Create Error Log
        if( errorFound )
        {
            TRACFCOMP( g_trac_nc,
                       ERR_MRK"ncddCheckStatus() - Error(s) found on "
                       "Target 0x%X",
                       i_args.tgt_huid );

            /*@
             * @errortype
             * @reasoncode       RC_NCDD_HW_ERROR_FOUND
             * @moduleid         MOD_NCDD_CHECK_FOR_ERRORS
             * @userdata1        Status Register Value
             * @userdata2        Target HUID
             * @devdesc          Error found in Node Comm status/ctrl register
             * @custdesc         Trusted Boot failure
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_NCDD_CHECK_FOR_ERRORS,
                                           RC_NCDD_HW_ERROR_FOUND,
                                           i_statusVal.value,
                                           i_args.tgt_huid);

            // Likely an issue with Processor or its bus
            addNodeCommBusCallout(i_args.tgt,
                                  i_args.linkId,
                                  err);

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            break;
        }


    } while( 0 );

    TRACUTCOMP( g_trac_nc,EXIT_MRK"ncddCheckStatus: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));

    return err;

} // end ncddCheckStatus


errlHndl_t ncddWaitForCmdComp (node_comm_args_t & i_args,
                               ctrl_reg_t & o_statusVal )
{
    errlHndl_t err = nullptr;
    uint64_t interval_ns  = NODE_COMM_DD_POLL_DELAY_NS;
    int timeout_ns = NODE_COMM_DD_POLL_DELAY_TOTAL_NS;
    ctrl_reg_t ctrl_reg_status;

    TRACUTCOMP(g_trac_nc, "ncddWaitForCmdComp(): timeout_ns=%d, "
              "interval_ns=%d", timeout_ns, interval_ns);

    do
    {
        do
        {
            // Read Control Reg to check for status
            ctrl_reg_status.value = 0x0;

            err = ncddRegisterOp( DeviceFW::READ,
                                  &ctrl_reg_status.value,
                                  NCDD_REG_CTRL,
                                  i_args );
            if(err)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"ncddWaitForCmdComp: ncddRegisterOp "
                          "failed for Target HUID 0x%08X and address 0x%016llX. "
                          TRACE_ERR_FMT,
                          i_args.tgt_huid,
                          NCDD_REG_CTRL,
                          TRACE_ERR_ARGS(err));
                break;
            }

            // Check For Errors
            err = ncddCheckStatus(i_args, ctrl_reg_status);
            if(err)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"ncddWaitForCmdComp: ncddCheckStatus"
                          " failed for Target HUID 0x%08X, address 0x%016llX. "
                          TRACE_ERR_FMT,
                          i_args.tgt_huid,
                          NCDD_REG_CTRL,
                          TRACE_ERR_ARGS(err));
                break;
            }

            // Check if we have more time to poll
            if (timeout_ns < 0)
            {
                TRACFCOMP(g_trac_nc,
                          ERR_MRK"ncddWaitForCmdComp() - "
                          "Timed out waiting for Command Complete! "
                          "status=0x%016llX from reg=0x%016llX",
                          ctrl_reg_status.value, NCDD_REG_CTRL);

                /*@
                 * @errortype
                 * @reasoncode       RC_NCDD_CMD_COMP_TIMEOUT
                 * @moduleid         MOD_NCDD_WAIT_FOR_CMD_COMP
                 * @userdata1        Status Register Value
                 * @userdata2[0:31]  Status/Control Register Address
                 * @userdata2[32:63] Target HUID
                 * @devdesc          Timed out waiting for command complete.
                 * @custdesc         Trusted Boot failure
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              MOD_NCDD_WAIT_FOR_CMD_COMP,
                                              RC_NCDD_CMD_COMP_TIMEOUT,
                                              ctrl_reg_status.value,
                                              TWO_UINT32_TO_UINT64(
                                                NCDD_REG_CTRL,
                                                i_args.tgt_huid));

                // Likely an issue with Processor or its bus
                addNodeCommBusCallout(i_args.tgt,
                                      i_args.linkId,
                                      err);

                // Or HB code failed to do the procedure correctly
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);

                break;
            }

            // Sleep before polling again
            nanosleep( 0, interval_ns );
            timeout_ns -= interval_ns;

         } while( 1 == ctrl_reg_status.start_stop ); /* Cmd Complete when ==0 */

         if (err)
         {
             break;
         }

    } while (0);

    o_statusVal = ctrl_reg_status;

    TRACUTCOMP( g_trac_nc,EXIT_MRK"ncddWaitForCmdComp: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));

    return err;

} // end ncddWaitForCmdComp


void ncddHandleError( errlHndl_t & io_err,
                      node_comm_args_t & i_args )
{
    TRACFCOMP( g_trac_nc,ENTER_MRK"ncddHandleError: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(io_err));

    errlHndl_t l_err = nullptr;

    do
    {
    // On a fail issue a cmd to the control reg with just the 'reset' bit set
    ctrl_reg_t ctrl_reg_cmd;
    ctrl_reg_cmd.value = 0x0;
    ctrl_reg_cmd.reset = 1;


    l_err = ncddRegisterOp( DeviceFW::WRITE,
                            &ctrl_reg_cmd.value,
                            NCDD_REG_CTRL,
                            i_args );

    if(l_err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"ncddHandleError: SCOM deviceWrite call "
            "failed for Target HUID 0x%08X and address 0x%016llX: "
            TRACE_ERR_FMT
            " . Committing after chaining to existing error: "
            TRACE_ERR_FMT,
            i_args.tgt_huid,
            NCDD_REG_CTRL,
            TRACE_ERR_ARGS(l_err),
            TRACE_ERR_ARGS(io_err));

        l_err->plid(io_err->plid());
        errlCommit( l_err, SECURE_COMP_ID );
        break;
    }

    } while (0);

    TRACFCOMP( g_trac_nc,EXIT_MRK"ncddHandleError: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(io_err));

    return;

} // end ncddHandleError



errlHndl_t ncddRegisterOp ( DeviceFW::OperationType i_opType,
                            uint64_t * io_data_64,
                            uint64_t i_reg,
                            node_comm_args_t & i_args )
{
    errlHndl_t err = nullptr;
    const size_t expSize = sizeof(i_reg);

    TRACUTCOMP(g_trac_nc,ENTER_MRK"ncddRegisterOp: %s: "
              "tgt=0x%X, reg_addr=0x%.16llX, data=0x%.16llX",
              ( i_opType == DeviceFW::READ ) ? "read" : "write",
              i_args.tgt_huid,
              i_reg, (*io_data_64)) ;

    do
    {
    uint64_t reqSize = expSize;
    err = DeviceFW::deviceOp( i_opType,
                              i_args.tgt,
                              io_data_64,
                              reqSize,
                              DEVICE_SCOM_ADDRESS(i_reg));

    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"ncddRegisterOp %s Fail! "
                  TRACE_ERR_FMT
                  " tgt=0x%X, reg_addr=0x%.8X, data=0x%.16X",
                  ( i_opType == DeviceFW::READ ) ? "read" : "write",
                  TRACE_ERR_ARGS(err),
                  i_args.tgt_huid,
                  i_reg, (*io_data_64) );
            break;
        }
    assert(reqSize==expSize,"ncddRegisterOp: SCOM deviceRead didn't return expected data size of %d (it was %d)",
           expSize,reqSize);

    } while (0);

    TRACUTCOMP(g_trac_nc,EXIT_MRK"ncddRegisterOp: %s: "
              "tgt=0x%X, reg_addr=0x%.16llX, data=0x%.16llX. "
              TRACE_ERR_FMT,
              ( i_opType == DeviceFW::READ ) ? "read" : "write",
              i_args.tgt_huid,
              i_reg, (*io_data_64),
              TRACE_ERR_ARGS(err));

    return err;

} // end ncddRegisterOp


} // end NODECOMM namespace

} // end SECUREBOOT namespace

