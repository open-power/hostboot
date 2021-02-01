/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_dd.H $                 */
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
#ifndef __NODE_COMM_DD_H
#define __NODE_COMM_DD_H

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <devicefw/userif.H>
#include <secureboot/nodecommif.H>

namespace SECUREBOOT
{

namespace NODECOMM
{

/**
 * @brief Struct used to pass basic Node Communication operations
 *        information between functions
 */
struct node_comm_args_t
{
    TARGETING::Target* tgt;
    uint32_t tgt_huid;
    uint8_t linkId;
    uint8_t mboxId;
    uint64_t* data_ptr;

    node_comm_args_t():tgt(nullptr),
                       tgt_huid(0x0),
                       linkId(NCDD_INVALID_LINK_MBOX),
                       mboxId(NCDD_INVALID_LINK_MBOX),
                       data_ptr(nullptr){};
};


/**
 * @brief Node Comm Contol (and Status) Register Definition
 *
 * @note  Certain bits are used to start an operation, provide status of the
 *        operation, and flag errors in the operation.
 */
union ctrl_reg_t
{
    uint64_t value;
    struct
    {
        uint64_t start_stop : 1;  // set to start op; HW sets to 0 when op done
        uint64_t write_not_read : 1;
        uint64_t bad_addr : 1;
        uint64_t link_down : 1;
        uint64_t corrupt : 1;
        uint64_t sent : 1;
        uint64_t bad_write : 1;
        uint64_t reset : 1;
        uint64_t mbox_id : 1;
        uint64_t link_id : 3;
        uint64_t reserved : 52;

    } PACKED;
};


/**
*
* @brief Perform a Node Comm operation.  It follows a pre-defined
*       prototype function in order to be registered with the device
*       driver framework.
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driverif.H
*
* @param[in] i_target - Processor Target
*                       Code will fail if nullptr or not TYPE_PROC
*
* @param [in/out] io_buffer
*       INPUT: Pointer to the data that will be  written to the target device
*       OUTPUT: Pointer to the data that was read from the target device
*
* @param [in/out] io_buflen
*       INPUT: Length of the buffer to be written to target device
*       OUTPUT: Length of buffer that was written, or length of buffer
*           to be read from target device
*       NOTE:  For Both INPUT and OUTPUT this should be 8-bytes (64-bits)
*
* @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
*       userif.H
*
* @param [in] i_args - This is an argument list for the device driver
*       framework.  This list of arguments is documented in userif.H.
*
* @return errlHndl_t - NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t nodeCommPerformOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         va_list i_args );

/**
 * @brief Reads data From ABUS/XBUS Link Mailbox Register
 *
 * @param[in/out] io_args - Structure containing arguments needed for a command
 *                          transaction and it holds the resulting data
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
 *                      the error log.
 */
errlHndl_t ncddRead (node_comm_args_t & io_args);

/**
 * @brief Writes data to ABUS/XBUS Link Mailbox Data Movement Register and then
 *        sends data via Link Bus Mailbox capability
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *                     transaction.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to
 *                      the error log.
 */
errlHndl_t ncddWrite (node_comm_args_t & i_args);

/**
 * @brief Checks the status in the ABUS/XBUS Link Mailbox Control Register
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *                     transaction.
 *
 * @param[in] i_statusVal - Control/Status Register value to be checked
 *
 * @return errlHndl_t - nullptr if successful and the command is complete;
 *                      otherwise a pointer to the error log.
 */
errlHndl_t ncddCheckStatus (node_comm_args_t & i_args,
                            const ctrl_reg_t & i_statusVal );

/**
 * @brief Waits for the operation to complete or timeout while
 *        periodically checking the status for errors
 *
 * @param[in] i_args - Structure containing arguments needed for a command
 *                     transaction.
 *
 * @param[in] o_statusVal - Last Control/Status Register value that was checked
 *
 * @return errlHndl_t - nullptr if successful and the command is complete;
 *                      otherwise a pointer to the error log.
 */
errlHndl_t ncddWaitForCmdComp (node_comm_args_t & i_args,
                               ctrl_reg_t & o_statusVal);

/**
 * @brief Analyzes an error handle object and performs any
 *        reset activity, if necessary
 *
 * @param[in/out] io_err - The error to analyze
 * @param[in]     i_args - miscellaneous arguments
 *
 * @return void
 */
void ncddHandleError( errlHndl_t & io_err,
                      node_comm_args_t & i_args );


/**
 * @brief This function handles all Node Communications-related SCOM operations
 *
 * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
 *       driververif.H
 *
 * @param [in/out] io_buffer_64
 *       INPUT: Pointer to 64 bits of data to be  written to the target
 *       OUTPUT: Pointer to the 64 bits of data that was read from the target
 *
 * @param[in] i_reg - The SCOM register of the operation
 *
 * @param[in/out] i_args - Structure containing arguments needed for a command
 *                         transaction and holds resulting data, if applicable
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to
 *                     the error log.
 */
errlHndl_t ncddRegisterOp ( DeviceFW::OperationType i_opType,
                            uint64_t * io_data_64,
                            uint64_t i_reg,
                            node_comm_args_t & i_args );

} // end NODECOMM namespace

} // end SECUREBOOT namespace

#endif // End __NODE_COMM_DD_H

