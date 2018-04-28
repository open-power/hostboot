/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_dd.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#define NODE_COMM_POLL_DELAY_NS 1   // Sleep for 1ns per poll
#define NODE_COMM_POLL_DELAY_TOTAL_NS 10 // Total time to poll


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
    node_comm_args_t node_comm_args;

    uint64_t mode = va_arg( i_args, uint64_t );
    node_comm_args.mode = static_cast<node_comm_modes_t>(mode);

    uint64_t linkId = va_arg( i_args, uint64_t );
    node_comm_args.linkId = static_cast<uint8_t>(linkId);

    uint64_t mboxId = va_arg( i_args, uint64_t );
    node_comm_args.mboxId = static_cast<uint8_t>(mboxId);

    node_comm_args.data_ptr = reinterpret_cast<uint64_t*>(io_buffer);
    node_comm_args.tgt = i_target;
    node_comm_args.tgt_huid = TARGETING::get_huid(i_target);

    do
    {

    // Check other input parameters
    const auto max_linkId = (mode==NCDD_MODE_ABUS)
                              ? NCDD_MAX_ABUS_LINK_ID
                              : NCDD_MAX_XBUS_LINK_ID;

    if (    (node_comm_args.mode >= NCDD_MODE_INVALID)
         || (node_comm_args.linkId > max_linkId)
         || (node_comm_args.mboxId > NCDD_MAX_MBOX_ID)
         || (node_comm_args.data_ptr == nullptr)
       )
    {
        TRACFCOMP( g_trac_nc,ERR_MRK"nodeCommPerformOp: Invalid Input Args!"
                   " mode=%d, linkId=0x%X (max=0x%X), mboxId=0x%X, "
                   " data_ptr=%p",
                   node_comm_args.mode, node_comm_args.linkId,
                   max_linkId, node_comm_args.mboxId,
                   node_comm_args.data_ptr);

        /*@
         * @errortype
         * @reasoncode       RC_NCDD_INVALID_ARGS
         * @moduleid         MOD_NCDD_PERFORM_OP
         * @userdata1[0:15]  BUS Mode Enum Value
         * @userdata1[16:31] LinkId Value
         * @userdata1[32:47] MAX possile LinkId Value based on Mode
         * @userdata1[48:63] MailboxId Value
         * @userdata2        Input Data Pointer
         * @devdesc          Invalid Input Args for Node Comm DD call
         * @custdesc         Secure Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_NCDD_PERFORM_OP,
                                       RC_NCDD_INVALID_ARGS,
                                       FOUR_UINT16_TO_UINT64(
                                         node_comm_args.mode,
                                         node_comm_args.linkId,
                                         max_linkId,
                                         node_comm_args.mboxId),
                                       reinterpret_cast<uint64_t>(
                                         node_comm_args.data_ptr),
                                       true /*Add HB SW Callout*/ );
        break;
    }

    TRACUCOMP(g_trac_nc,ENTER_MRK"nodeCommPerformOp: %s: %s: "
              "tgt=0x%X, LinkId=%d, MboxId=%d, data=0x%.16llX",
              (node_comm_args.mode == NCDD_MODE_ABUS)
              ? NCDD_ABUS_STRING : NCDD_XBUS_STRING,
              ( i_opType == DeviceFW::READ ) ? "read" : "write",
              node_comm_args.tgt_huid, node_comm_args.linkId,
              node_comm_args.mboxId, (*node_comm_args.data_ptr));

    // Mutex Lock
    // @TODO RTC:191008 Support mutex

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
        err = ncddWrite( node_comm_args);
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

    // Mutex Unlock
    // @TODO RTC:191008 Support mutex

    // If err, add trace and FFDC to log
    if (err)
    {
        err->collectTrace(SECURE_COMP_NAME);
        err->collectTrace(NODECOMM_TRACE_NAME);

        // @TODO RTC:191008 Add FFDC - call to new UserDetails Section
    }

    TRACFCOMP (g_trac_nc, EXIT_MRK"nodeCommPerformOp: %s: %s: "
               "tgt=0x%X, LinkId=%d, MboxId=%d, data=0x%.16llX. "
               TRACE_ERR_FMT,
               (node_comm_args.mode == NCDD_MODE_ABUS)
                 ? NCDD_ABUS_STRING : NCDD_XBUS_STRING,
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

    } while( 0 );

    TRACUCOMP( g_trac_nc,EXIT_MRK"ncddRead: "
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
    err = ncddWaitForCmdComp(i_args);
    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"ncddWrite: Wait For Cmd Complete "
            "failed for Target HUID 0x%08X. "
            TRACE_ERR_FMT,
            i_args.tgt_huid,
            TRACE_ERR_ARGS(err));
        break;
    }

    // @TODO RTC 191008 - have ncddWaitForCmdComp return status to
    // check for 'write' bit being set

    } while( 0 );

    TRACUCOMP( g_trac_nc,EXIT_MRK"ncddWrite: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));

    return err;

} // end ncddWrite


errlHndl_t ncddCheckStatus (node_comm_args_t & i_args,
                            const ctrl_reg_t i_statusVal )
{
    errlHndl_t err = nullptr;
    bool errorFound = false;

    TRACUCOMP( g_trac_nc,
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
             * @custdesc         Secure Boot failure
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_NCDD_CHECK_FOR_ERRORS,
                                           RC_NCDD_HW_ERROR_FOUND,
                                           i_statusVal.value,
                                           i_args.tgt_huid);

            // Likely an issue with Processor or its bus
            err->addHwCallout( i_args.tgt,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::DELAYED_DECONFIG,
                               HWAS::GARD_NULL );

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_MED);

            // @TODO RTC 184518 - Look into bus callouts

           break;
        }


    } while( 0 );

    TRACUCOMP( g_trac_nc,EXIT_MRK"ncddCheckStatus: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));

    return err;

} // end ncddCheckStatus


errlHndl_t ncddWaitForCmdComp (node_comm_args_t & i_args)
{
    errlHndl_t err = nullptr;
    uint64_t interval_ns  = NODE_COMM_POLL_DELAY_NS;
    int timeout_ns = NODE_COMM_POLL_DELAY_TOTAL_NS;
    ctrl_reg_t ctrl_reg_status;


    TRACUCOMP(g_trac_nc, "ncddWaitForCmdComp(): timeout_ns=%d, "
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
                 * @custdesc         Secure Boot failure
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              MOD_NCDD_WAIT_FOR_CMD_COMP,
                                              RC_NCDD_CMD_COMP_TIMEOUT,
                                              ctrl_reg_status.value,
                                              TWO_UINT32_TO_UINT64(
                                                NCDD_REG_CTRL,
                                                i_args.tgt_huid));

                // Likely an issue with Processor or its bus
                err->addHwCallout(i_args.tgt,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::DELAYED_DECONFIG,
                                  HWAS::GARD_NULL);

                // Or HB code failed to do the procedure correctly
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_MED);

                // @TODO RTC 184518 - Look into bus callouts

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

    TRACUCOMP( g_trac_nc,EXIT_MRK"ncddWaitForCmdComp: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));

    return err;

} // end ncddWaitForCmdComp

errlHndl_t ncddRegisterOp ( DeviceFW::OperationType i_opType,
                            uint64_t * io_data_64,
                            uint64_t i_reg,
                            node_comm_args_t & i_args )
{
    errlHndl_t err = nullptr;
    const size_t expSize = sizeof(i_reg);
    uint64_t l_reg = getLinkMboxRegAddr(i_reg, i_args.mode);

    TRACUCOMP(g_trac_nc,ENTER_MRK"ncddRegisterOp: %s: %s: "
              "tgt=0x%X, reg_addr=0x%.16llX, data=0x%.16llX",
              (i_args.mode == NCDD_MODE_ABUS)
                ? NCDD_ABUS_STRING : NCDD_XBUS_STRING,
              ( i_opType == DeviceFW::READ ) ? "read" : "write",
              i_args.tgt_huid,
              l_reg, (*io_data_64)) ;

    do
    {
    uint64_t reqSize = expSize;
    err = DeviceFW::deviceOp( i_opType,
                              i_args.tgt,
                              io_data_64,
                              reqSize,
                              DEVICE_SCOM_ADDRESS(l_reg));

    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"ncddRegisterOp %s %s Fail! "
                  TRACE_ERR_FMT
                  " tgt=0x%X, reg_addr=0x%.8X, data=0x%.16X",
                  (i_args.mode == NCDD_MODE_ABUS)
                    ? NCDD_ABUS_STRING : NCDD_XBUS_STRING,
                  ( i_opType == DeviceFW::READ ) ? "read" : "write",
                  TRACE_ERR_ARGS(err),
                  i_args.tgt_huid,
                  l_reg, (*io_data_64) );
            break;
        }
    assert(reqSize==expSize,"ncddRegisterOp: SCOM deviceRead didn't return expected data size of %d (it was %d)",
           expSize,reqSize);

    } while (0);

    TRACUCOMP(g_trac_nc,EXIT_MRK"ncddRegisterOp: %s: %s: "
              "tgt=0x%X, reg_addr=0x%.16llX, data=0x%.16llX. "
              TRACE_ERR_FMT,
              (i_args.mode == NCDD_MODE_ABUS)
                ? NCDD_ABUS_STRING : NCDD_XBUS_STRING,
              ( i_opType == DeviceFW::READ ) ? "read" : "write",
              i_args.tgt_huid,
              l_reg, (*io_data_64),
              TRACE_ERR_ARGS(err));

    return err;

} // end ncddRegisterOp


} // end NODECOMM namespace

} // end SECUREBOOT namespace

