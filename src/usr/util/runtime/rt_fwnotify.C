/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/rt_fwnotify.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2022                        */
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

#include <sbeio/sbe_retry_handler.H>       // SbeRetryHandler
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper
#include <runtime/interface.h>             // g_hostInterfaces
#include <runtime/runtime_reasoncodes.H>   // MOD_RT_FIRMWARE_NOTIFY, etc
#include <errl/errlentry.H>                // ErrlEntry
#include <errl/errlmanager.H>              // errlCommit
#include <errl/hberrltypes.H>              // TWO_UINT32_TO_UINT64
#include <targeting/common/target.H>       // TargetHandle_t, getTargetFromHuid
#include <targeting/runtime/rt_targeting.H>          // RT_TARG::getHbTarget
#include <attributeenums.H>                // ATTRIBUTE_ID

#ifdef CONFIG_NVDIMM
#include <isteps/nvdimm/nvdimm.H>          // NVDIMM related activities
#include <targeting/common/targetUtil.H>   // makeAttribute
#include <runtime/hbrt_utilities.H>
using namespace NVDIMM;
#endif

using namespace TARGETING;
using namespace RUNTIME;
using namespace ERRORLOG;
using namespace MBOX;
using namespace SBEIO;


// Trace definition
extern trace_desc_t* g_trac_runtime;
extern trace_desc_t* g_trac_hbrt;

/**
 * @brief The lower and upper bounds for the sequence ID.
 **/
const uint16_t SEQ_ID_MIN = 0x0000;
const uint16_t SEQ_ID_MAX = 0x7FFF;

/**
 * @brief Set the sequence ID to the minimum value
 **/
uint16_t SeqId_t::SEQ_ID = SEQ_ID_MIN;

/**
 * @brief Gets the next sequence ID.
 * @return The next sequence ID value within its lower and upper bound
 * @note This code is thread safe, no need for a mutex around this because
 *       HBRT never runs in multi-thread.
 *
 **/
uint16_t SeqId_t::getNextSeqId()
{
    if (SeqId_t::SEQ_ID < SEQ_ID_MAX)
    {
        ++SeqId_t::SEQ_ID;
    }
    else
    {
        SeqId_t::SEQ_ID = SEQ_ID_MIN;
    }

    return SeqId_t::SEQ_ID;
}

/**
 *  @brief Gets the current value of the sequence ID.
 *  @return The current value of the sequence ID.
 **/
uint16_t SeqId_t::getCurrentSeqId()
{
    return SeqId_t::SEQ_ID;
}

/**
 *  @brief Attempt to notify PHYP of SBE active status change
 *  @param[in] i_data - contains a byte indicating SBE active status
 *  @param[in] i_target - target we wish to send the notification for
 *  @platform FSP
 **/
void sbeActiveNotification( void * i_data,
                            TARGETING::Target *i_target)
{
    // data is one byte - 1 = SBE active, 0 = SBE not active
    uint8_t * l_active = reinterpret_cast<uint8_t*>(i_data);
    TRACFCOMP(g_trac_runtime, ENTER_MRK"sbeActiveNotification: 0x%02X", *l_active);
#ifdef CONFIG_NVDIMM
    // Just a safety check
    assert(l_active != nullptr, "sbeActiveNotification: invalid NULL data ptr");
    assert(i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC,
           "sbeActiveNotification passed target that is not TYPE_PROC");
    errlHndl_t l_err = nullptr;

    if (*l_active)
    {
        l_err = NVDIMM::notifyNvdimmProtectionChange(i_target,
                                                     NVDIMM::SBE_ACTIVE);
    }
    else
    {
        l_err = NVDIMM::notifyNvdimmProtectionChange(i_target,
                                                     NVDIMM::SBE_INACTIVE);
    }

    // commit error if it exists
    if (l_err)
    {
        TRACFCOMP(g_trac_runtime,
                  ERR_MRK"sbeActiveNotification: 0x%02X - 0x%.8X processor",
                  *l_active, TARGETING::get_huid(i_target));

        errlCommit(l_err, RUNTIME_COMP_ID);
        l_err = nullptr;
    }
#endif
}

/**
 *  @brief Attempt an SBE recovery after an SBE error
 *  @param[in] uint64_t i_data Contains a HUID (in the first 4 bytes)
 *                             and a plid (in the last 4 bytes)
 *  @platform FSP, OpenPOWER
 **/
void sbeAttemptRecovery(uint64_t i_data)
{
    // Create a useful struct to get to the data
    // The data is expected to be a HUID (in the first 4 bytes)
    // followed by a PLID (in the last 4 bytes).
    SbeRetryReqData_t *l_sbeRetryData = reinterpret_cast<SbeRetryReqData_t*>(&i_data);

    TRACFCOMP(g_trac_runtime, ENTER_MRK"sbeAttemptRecovery: plid:0x%X, "
             "HUID:0x%X", l_sbeRetryData->plid, l_sbeRetryData->huid);

    errlHndl_t l_err = nullptr;
    uint8_t l_sbe_recovered = 0;

    do
    {
        // Extract the target from the given HUID
        TargetHandle_t l_target =
                        Target::getTargetFromHuid(l_sbeRetryData->huid);

        // If HUID invalid, log error and quit
        if (nullptr == l_target)
        {
            TRACFCOMP(g_trac_runtime, ERR_MRK"sbeAttemptRecovery: "
                       "No target associated with HUID:0x%.8X",
                       l_sbeRetryData->huid);

            /*@
             * @errortype
             * @severity     ERRL_SEV_PREDICTIVE
             * @moduleid     MOD_RT_FIRMWARE_NOTIFY
             * @reasoncode   RC_SBE_RT_INVALID_HUID
             * @userdata1    HUID of target
             * @userdata2    HWSV error log id (plid)
             * @devdesc      SBE error recovery attempt failed
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   MOD_RT_FIRMWARE_NOTIFY,
                                   RC_SBE_RT_INVALID_HUID,
                                   l_sbeRetryData->huid,
                                   l_sbeRetryData->plid,
                                   true);
            break;
        }

        // Notify PHYP that the SBE is inactive and their NVDIMMs are not protected
        sbeActiveNotification( &l_sbe_recovered, l_target );

        // Get the SBE Retry Handler, propagating the supplied PLID
        SbeRetryHandler l_SBEobj = SbeRetryHandler(SbeRetryHandler::
                                    SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                                    l_sbeRetryData->plid);

        //Attempt to recover the SBE
        l_SBEobj.main_sbe_handler(l_target);


        if (nullptr == g_hostInterfaces ||
            nullptr == g_hostInterfaces->firmware_request)
        {
            TRACFCOMP(g_trac_runtime, ERR_MRK"sbeAttemptRecovery: "
                       "Hypervisor firmware_request interface not linked");

            /*@
             * @errortype
             * @severity     ERRL_SEV_PREDICTIVE
             * @moduleid     MOD_RT_FIRMWARE_NOTIFY
             * @reasoncode   RC_FW_REQUEST_RT_NULL_PTR
             * @userdata1    HUID of target
             * @userdata2    HWSV error log id (plid)
             * @devdesc      SBE error recovery attempt failed
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   MOD_RT_FIRMWARE_NOTIFY,
                                   RC_FW_REQUEST_RT_NULL_PTR,
                                   l_sbeRetryData->huid,
                                   l_sbeRetryData->plid,
                                   true);

           break;
        }

        // Create the firmware_request request struct to send data
        hostInterfaces::hbrt_fw_msg l_req_fw_msg;
        uint64_t l_req_fw_msg_size = sizeof(l_req_fw_msg);

        // Initialize the firmware_request request struct
        l_req_fw_msg.generic_msg.initialize();

        // Populate the firmware_request request struct with given data
        l_req_fw_msg.io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
        l_req_fw_msg.generic_msg.msgq = GenericFspMboxMessage_t::FSP_HBRT_MESSAGEQ;
        l_req_fw_msg.generic_msg.__req = GenericFspMboxMessage_t::REQUEST;
        l_req_fw_msg.generic_msg.data = i_data;

        // Set msgType based on recovery success or failure (If sbe made it back to runtime)
        if (l_SBEobj.isSbeAtRuntime())
        {
            TRACFCOMP(g_trac_runtime, "sbeAttemptRecovery: RECOVERY_SUCCESS");
            l_req_fw_msg.generic_msg.msgType =
                             GenericFspMboxMessage_t::MSG_SBE_RECOVERY_SUCCESS;
            // Notify PHYP that the SBE is active
            l_sbe_recovered = 1;
            sbeActiveNotification( &l_sbe_recovered, l_target);
        }
        else
        {
            TRACFCOMP(g_trac_runtime, "sbeAttemptRecovery: RECOVERY_FAILED");
            l_req_fw_msg.generic_msg.msgType =
                              GenericFspMboxMessage_t::MSG_SBE_RECOVERY_FAILED;
        }

        // Create the firmware_request response struct to receive data
        // NOTE: For messages to the FSP the response size must match
        // the request size
        // No need to check for expected response size > request
        // size because they use the same base structure
        hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
        uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
        memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Trace out the request structure
        TRACFBIN( g_trac_runtime, INFO_MRK"Sending firmware_request",
                  &l_req_fw_msg,
                  l_req_fw_msg_size);

        // Make the firmware_request call
        l_err = firmware_request_helper(l_req_fw_msg_size,
                                        &l_req_fw_msg,
                                        &l_resp_fw_msg_size,
                                        &l_resp_fw_msg);

        if (l_err)
        {
            break;
        }
    } while(0);

    if (l_err)
    {
       //Commit the error if it exists
       errlCommit(l_err, RUNTIME_COMP_ID);
    }

    TRACFCOMP(g_trac_runtime, EXIT_MRK"sbeAttemptRecovery");
}

/**
 *  @brief Attempt to notify PHYP of OCC active status change
 *  @param[in] i_data - contains a byte indicating OCC active status
 *  @platform FSP
 **/
void occActiveNotification( void * i_data )
{
    // data is one byte - 1 = OCC active, 0 = OCC not active
    uint8_t * l_active = reinterpret_cast<uint8_t*>(i_data);

    // Just a safety check
    assert(l_active != nullptr, "occActiveNotification: invalid NULL data ptr");

    TRACFCOMP(g_trac_runtime, ENTER_MRK"occActiveNotification: 0x%02X", *l_active);

#ifdef CONFIG_NVDIMM
    errlHndl_t l_err = nullptr;

    TargetHandleList l_procList;
    getAllChips(l_procList, TYPE_PROC);

    // Now send msg to PHYP notifying them if OCC is protecting the NVDIMMs
    for (auto & l_proc : l_procList)
    {
        if (*l_active)
        {
            l_err = NVDIMM::notifyNvdimmProtectionChange(l_proc,
                                                         NVDIMM::OCC_ACTIVE);
        }
        else
        {
            l_err = NVDIMM::notifyNvdimmProtectionChange(l_proc,
                                                         NVDIMM::OCC_INACTIVE);
        }

        // commit error if it exists
        // continue notification to all functional processors
        if (l_err)
        {
            TRACFCOMP(g_trac_runtime,
                      ERR_MRK"occActiveNotification: 0x%02X - 0x%.8X processor",
                      *l_active, TARGETING::get_huid(l_proc));

            errlCommit(l_err, RUNTIME_COMP_ID);
            l_err = nullptr;
        }
    }
#endif
}

/**
 *  @brief Attempt to sync attribute setting with the FSP
 *  @param[in] void * i_data - contains a target huid, attribute id,
 *                             attribute data length, and attribute data
 *  @platform FSP
 **/
void attrSyncRequest( void * i_data)
{
    HbrtAttrSyncData_t * l_hbrtAttrData =
                                reinterpret_cast<HbrtAttrSyncData_t*>(i_data);
    TRACFCOMP(g_trac_runtime, ENTER_MRK"attrSyncRequest: Target HUID 0x%0X "
             "for AttrID: 0x%0X with AttrSize: %lld", l_hbrtAttrData->huid,
             l_hbrtAttrData->attrID, l_hbrtAttrData->sizeOfAttrData);

    TRACFBIN(g_trac_runtime, "Attribute data: ",
             &(l_hbrtAttrData->attrDataStart),
             l_hbrtAttrData->sizeOfAttrData);

    // extract the target from the given HUID
    TargetHandle_t l_target = Target::getTargetFromHuid(l_hbrtAttrData->huid);

    // Assumes the attribute is writeable
    bool attr_updated = l_target->unsafeTrySetAttr(
                                               l_hbrtAttrData->attrID,
                                               l_hbrtAttrData->sizeOfAttrData,
               reinterpret_cast<const void*>(&(l_hbrtAttrData->attrDataStart)));

    if (!attr_updated)
    {
        TRACFCOMP(g_trac_runtime,ERR_MRK"attrSyncRequest: "
                    "Unable to update attribute");

        // Copy the first couple bytes of new attribute data (up to 4 bytes)
        uint32_t l_attrData = 0;
        uint32_t l_attrSize = l_hbrtAttrData->sizeOfAttrData;
        if (l_attrSize > sizeof(l_attrData))
        {
            l_attrSize = sizeof(l_attrData);
        }
        memcpy(&l_attrData, &(l_hbrtAttrData->attrDataStart), l_attrSize);

        /*@
         * @errortype
         * @severity     ERRL_SEV_PREDICTIVE
         * @moduleid     MOD_RT_ATTR_SYNC_REQUEST
         * @reasoncode   RC_ATTR_UPDATE_FAILED
         * @userdata1[0:31]  Target HUID
         * @userdata1[32:63] Attribute ID
         * @userdata2[0:31]  Data Size
         * @userdata2[32:63] Up to 4 bytes of attribute data
         * @devdesc      Attribute failed to update on HBRT side
         */
        errlHndl_t l_err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                         MOD_RT_ATTR_SYNC_REQUEST,
                                         RC_ATTR_UPDATE_FAILED,
                                         TWO_UINT32_TO_UINT64(
                                            l_hbrtAttrData->huid,
                                            l_hbrtAttrData->attrID),
                                         TWO_UINT32_TO_UINT64(
                                            l_hbrtAttrData->sizeOfAttrData,
                                            l_attrData),
                                         true);

        l_err->collectTrace(RUNTIME_COMP_NAME, 256);

        //Commit the error
        errlCommit(l_err, RUNTIME_COMP_ID);
    }

    TRACFCOMP(g_trac_runtime, EXIT_MRK"attrSyncRequest");
}

#ifdef CONFIG_NVDIMM
/**
 * @brief Utility function to set ATTR_NVDIMM_ENCRYPTION_ENABLE
 *        and send the value to the FSP
 */
void set_ATTR_NVDIMM_ENCRYPTION_ENABLE(
            ATTR_NVDIMM_ENCRYPTION_ENABLE_type i_val )
{
    errlHndl_t l_err = nullptr;

    Target* l_sys = nullptr;
    targetService().getTopLevelTarget( l_sys );
    assert(l_sys, "set_ATTR_NVDIMM_ENCRYPTION_ENABLE: no TopLevelTarget");
    l_sys->setAttr<ATTR_NVDIMM_ENCRYPTION_ENABLE>(i_val);

    // Send it down to the FSP
    AttributeTank::Attribute l_attr = {};
    if( !makeAttribute<ATTR_NVDIMM_ENCRYPTION_ENABLE>
        (l_sys, l_attr) )
    {
        TRACFCOMP(g_trac_runtime, ERR_MRK"set_ATTR_NVDIMM_ENCRYPTION_ENABLE() Could not create Attribute");
        /*@
         *@errortype
         *@reasoncode       RC_CANNOT_MAKE_ATTRIBUTE
         *@severity         ERRORLOG_SEV_PREDICTIVE
         *@moduleid         SET_ATTR_NVDIMM_ENCRYPTION_ENABLE
         *@devdesc          Couldn't create an Attribute to send the data
         *                  to the FSP
         *@custdesc         NVDIMM encryption error
         */
        l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                                        SET_ATTR_NVDIMM_ENCRYPTION_ENABLE,
                                        RC_CANNOT_MAKE_ATTRIBUTE,
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
        l_err->collectTrace(NVDIMM_COMP_NAME);
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    else
    {
        std::vector<TARGETING::AttributeTank::Attribute> l_attrList;
        l_attrList.push_back(l_attr);
        l_err = sendAttributes( l_attrList );
        if (l_err)
        {
            TRACFCOMP(g_trac_runtime, ERR_MRK"set_ATTR_NVDIMM_ENCRYPTION_ENABLE() Error sending ATTR_NVDIMM_ENCRYPTION_ENABLE down to FSP");
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
        }
    }
}
#endif //CONFIG_NVDIMM

/**
 *  @brief Perform an NVDIMM operation
 *  @param[in] i_nvDimmOp - A struct that contains the operation(s) to perform
 *                          and a flag indicating whether to perform operation
 *                          on all processors or a given single processor.
 *
 *  @Note The arming/disarming operations below are in the order of which they
 *        should be performed.  If a new sequence is added to the
 *        arming/disarming sequence, make sure it is inserted in the
 *        correct order.
 *        The current order is: disarm -> disable encryption -> remove keys ->
 *                              enable encryption -> arm
 **/
int doNvDimmOperation(const hostInterfaces::nvdimm_operation_t& i_nvDimmOp)
{
    int rc = 0;
#ifndef CONFIG_NVDIMM
    TRACFCOMP(g_trac_runtime, ENTER_MRK"doNvDimmOperation: not an "
              "NVDIMM configuration, this call becomes a noop.");

#else
    TRACFCOMP(g_trac_runtime, ENTER_MRK"doNvDimmOperation: Operation(s) "
              "0x%0X, processor ID  0x%0X",
              i_nvDimmOp.opType,
              i_nvDimmOp.procId);

    // Error log handle for capturing any errors
    errlHndl_t       l_err{nullptr};
    // List of NVDIMM Targets to execute NVDIMM operation on
    TargetHandleList l_nvDimmTargetList;

    // Perform the operations requested
    do
    {
        /// Populate the NVDIMM target list
        // If requesting to perform operation on all NVDIMMs, then
        // retrieve all NVDIMMs from system
        if (HBRT_NVDIMM_OPERATION_APPLY_TO_ALL_NVDIMMS == i_nvDimmOp.procId)
        {
            nvdimm_getNvdimmList(l_nvDimmTargetList);
        }
        // Else retrieve only the NVDIMMs from given processor ID
        else
        {
            /// Get the NVDIMMs associated with procId
            // Convert the procId to a real boy, uh, I mean target
            TARGETING::TargetHandle_t l_procTarget;
            l_err = RT_TARG::getHbTarget(i_nvDimmOp.procId, l_procTarget);
            if (l_err)
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: Error getting "
                                          "HB Target from processor ID 0x%0X, "
                                          "exiting ...",
                                          i_nvDimmOp.procId);
                rc = -1;
                break;
            }

            // Get the list of NVDIMMs associated with processor target
            l_nvDimmTargetList = TARGETING::getProcNVDIMMs(l_procTarget);
        }

        // No point in continuing if the list of NVDIMM Targets is empty
        if (!l_nvDimmTargetList.size())
        {
            TRACFCOMP(g_trac_runtime, "doNvDimmOperation: No NVDIMMs found, "
                                      "exiting ...");
            rc = -1;
            break;
        }

        // Perform the arming/disarming operations.  If anyone fails in the
        // sequence, no point in calling the next, if there is a next operation.
        do
        {
            // Disarm the NV logic
            if (i_nvDimmOp.opType & hostInterfaces::HBRT_FW_NVDIMM_DISARM)
            {
                // Make call to disarm
                if (!nvdimmDisarm(l_nvDimmTargetList))
                {
                    TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                              "Call to disarm failed. Will not perform any "
                              "more arming/disarming calls, if they exist");
                    rc = -1;
                    break;
                }
                else
                {
                    TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                                              "Call to disarm succeeded");
                }
            }

            // Disable encryption on the NVDIMM and clear saved values from FW
            if (i_nvDimmOp.opType &
                              hostInterfaces::HBRT_FW_NVDIMM_DISABLE_ENCRYPTION)
            {
                // Make call to disable encryption
                if (!nvdimm_crypto_erase(l_nvDimmTargetList))
                {
                    TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                              "Call to disable encryption failed.  Will not "
                              "perform any more arming/disarming calls, if "
                              "they exist");

                    // Clear the encryption enable attribute
                    set_ATTR_NVDIMM_ENCRYPTION_ENABLE(0);

                    rc = -1;
                    break;
                }
                else
                {
                    TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                                       "Call to disable encryption succeeded.");
                }

                // Clear the encryption enable attribute
                set_ATTR_NVDIMM_ENCRYPTION_ENABLE(0);
            }

            // Remove keys
            if (i_nvDimmOp.opType & hostInterfaces::HBRT_FW_NVDIMM_REMOVE_KEYS)
            {
                // Make call to remove keys
                if (!nvdimm_remove_keys())
                {
                    TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                              "Call to remove keys failed.  Will not perform "
                              "any more arming/disarming calls, if they exist");
                    rc = -1;
                    break;
                }
                else
                {
                    TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                                              "Call to remove keys succeeded.");
                }
            }

            // Enable encryption on the NVDIMM
            if (i_nvDimmOp.opType &
                               hostInterfaces::HBRT_FW_NVDIMM_ENABLE_ENCRYPTION)
            {
                // Set the encryption enable attribute
                set_ATTR_NVDIMM_ENCRYPTION_ENABLE(1);

                // Make call to generate keys before enabling encryption
                if(!nvdimm_gen_keys())
                {
                    TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                              "Call to generate keys failed, unable to enable "
                              "encryption. Will not perform any more "
                              "arming/disarming calls, if they exist");
                    rc = -1;
                    break;
                }
                else
                {
                    // Make call to enable encryption
                    if (!nvdimm_encrypt_enable(l_nvDimmTargetList))
                    {
                        TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                                  "Call to enable encryption failed. "
                                  "Will not perform any more arming/disarming "
                                  "calls, if they exist");
                        rc = -1;
                        break;
                    }
                    else
                    {
                        TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                                        "Call to enable encryption succeeded.");
                    }
                } // end if(!nvdimm_gen_keys()) ... else ...
            }

            // Arm the NV logic
            if (i_nvDimmOp.opType & hostInterfaces::HBRT_FW_NVDIMM_ARM)
            {
                // Make call to arm
                if (!nvdimmArm(l_nvDimmTargetList))
                {
                    TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                                              "Call to arm failed.");
                    rc = -1;
                    break;
                }
                else
                {
                    TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                                              "Call to arm succeeded.");
                }
            }  // end if (nvDimmOp.opType & hostInterfaces::HBRT_FW_NVDIMM_ARM)
        }  while (0); // end Perform the arming/disarming operations.

        // Perform the ES (energy source) health check operation
        if (i_nvDimmOp.opType & hostInterfaces::HBRT_FW_MNFG_ES_HEALTH_CHECK)
        {
            if (!nvDimmEsCheckHealthStatus(l_nvDimmTargetList))
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                       "Call to do an ES (energy source) health check failed.");
                rc = -1;
                break;
            }
            else
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                    "Call to do an ES (energy source) health check succeeded.");
            }
        }

        // Perform the NVM (non-volatile memory) health check operation
        if (i_nvDimmOp.opType & hostInterfaces::HBRT_FW_MNFG_NVM_HEALTH_CHECK)
        {
            if (!nvDimmNvmCheckHealthStatus(l_nvDimmTargetList))
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                 "Call to do a NVM (non-volatile memory) health check failed.");
                rc = -1;
                break;
            }
            else
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
              "Call to do a NVM (non-volatile memory) health check succeeded.");
            }
        }

        // Perform the factory default operation
        if (i_nvDimmOp.opType & hostInterfaces::HBRT_FW_NVDIMM_FACTORY_DEFAULT)
        {
            if (!nvdimmFactoryDefault(l_nvDimmTargetList))
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                 "Call to do NVDIMM Factory Default operation failed.");
                rc = -1;
                break;
            }
            else
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                "Call to do NVDIMM Factory Default operation succeeded.");
            }
        }

        // Perform the secure erase verify start operation
        if (i_nvDimmOp.opType & hostInterfaces::HBRT_FW_NVDIMM_SECURE_EV_START)
        {
            if (!nvdimmSecureEraseVerifyStart(l_nvDimmTargetList))
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                 "Call to do NVDIMM Secure Erase Verify Start failed.");
                rc = -1;
                break;
            }
            else
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                "Call to do NVDIMM Secure Erase Verify Start succeeded.");
            }
        }

        // Perform the secure erase verify status operation
        if (i_nvDimmOp.opType & hostInterfaces::HBRT_FW_NVDIMM_SECURE_EV_STATUS)
        {
            if (!nvdimmSecureEraseVerifyStatus(l_nvDimmTargetList))
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                 "Call to do NVDIMM Secure Erase Verify Status failed.");
                rc = -1;
                break;
            }
            else
            {
                TRACFCOMP(g_trac_runtime, "doNvDimmOperation: "
                "Call to do NVDIMM Secure Erase Verify Status succeeded.");
            }
        }

    } while(0); // end Perform the operations requested

    if (l_err)
    {
       //Commit the error if it exists
       errlCommit(l_err, RUNTIME_COMP_ID);
    }

#endif

    TRACFCOMP(g_trac_runtime, EXIT_MRK"doNvDimmOperation")
    return rc;
}

/**
 *  @brief Log the gard event from PHYP/OPAL
 *
 *  @param[in] i_gardEvent - The details of the gard event
 *                           @see hostInterfaces::gard_event_t for more info
 *
 **/
void logGardEvent(const hostInterfaces::gard_event_t& i_gardEvent)
{
    // Trace input components
    TRACFCOMP(g_trac_runtime,
              ENTER_MRK"logGardEvent: Gard Event Data: "
                       "error type(0x%.8X), processor ID(0x%.8X), "
                       "PLID(0x%.8X), sub unit mask(0x.%4X), "
                       "recovery level(0x.%4X)",
                       i_gardEvent.i_error_type,
                       i_gardEvent.i_procId,
                       i_gardEvent.i_plid,
                       i_gardEvent.i_sub_unit_mask,
                       i_gardEvent.i_recovery_level);

    errlHndl_t l_err{nullptr};

    do
    {
        // Make sure the error type is valid, if not, log it
        if ((i_gardEvent.i_error_type == hostInterfaces::HBRT_GARD_ERROR_UNKNOWN )   ||
            (i_gardEvent.i_error_type >= hostInterfaces::HBRT_GARD_ERROR_LAST) )
        {
            TRACFCOMP(g_trac_runtime, "logGardEvent: ERROR: unknown/invalid "
                                      "error type 0x%.8X",
                                      i_gardEvent.i_error_type);

            /* @
             * @errortype
             * @severity         ERRL_SEV_PREDICTIVE
             * @moduleid         MOD_RT_FIRMWARE_NOTIFY
             * @reasoncode       RC_LOG_GARD_EVENT_UNKNOWN_ERROR_TYPE
             * @userdata1[0:31]  GARD error type
             * @userdata1[32:63] Processor ID
             * @userdata2[0:31]  Sub unit mask
             * @userdata2[32:63] Recovery level
             * @devdesc          Unknown/invalid error type
             * @custdesc         Internal firmware error
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   MOD_RT_FIRMWARE_NOTIFY,
                                   RC_LOG_GARD_EVENT_UNKNOWN_ERROR_TYPE,
                                   TWO_UINT32_TO_UINT64(
                                        i_gardEvent.i_error_type,
                                        i_gardEvent.i_procId),
                                   TWO_UINT32_TO_UINT64(
                                        i_gardEvent.i_sub_unit_mask,
                                        i_gardEvent.i_recovery_level),
                                   ErrlEntry::ADD_SW_CALLOUT);
            break;
        }


        // Get the Target associated with processor ID
        TARGETING::TargetHandle_t l_procTarget{nullptr};
        l_err = RT_TARG::getHbTarget(i_gardEvent.i_procId, l_procTarget);
        if (l_err)
        {
            TRACFCOMP(g_trac_runtime, "logGardEvent: Error getting "
                                      "HB Target from processor ID 0x%0X, "
                                      "exiting ...",
                                      i_gardEvent.i_procId);
            break;
        }

        // Log the GARD event
        /* @
         * @errortype
         * @severity         ERRL_SEV_PREDICTIVE
         * @moduleid         MOD_RT_FIRMWARE_NOTIFY
         * @reasoncode       RC_LOG_GARD_EVENT
         * @userdata1[0:31]  GARD error type
         * @userdata1[32:63] Processor ID
         * @userdata2[0:31]  Sub unit mask
         * @userdata2[32:63] Recovery level
         * @devdesc          Gard event from Opal/Phyp
         * @custdesc         Hardware error detected at runtime
         */
        l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                               MOD_RT_FIRMWARE_NOTIFY,
                               RC_LOG_GARD_EVENT,
                               TWO_UINT32_TO_UINT64(
                                    i_gardEvent.i_error_type,
                                    i_gardEvent.i_procId),
                               TWO_UINT32_TO_UINT64(
                                    i_gardEvent.i_sub_unit_mask,
                                    i_gardEvent.i_recovery_level));

        // Set the PLID to the given gard event PLID if it exist
        if (i_gardEvent.i_plid)
        {
            l_err->plid(i_gardEvent.i_plid);
        }

        // Do the actual gard
        l_err->addHwCallout( l_procTarget, HWAS::SRCI_PRIORITY_MED,
                             HWAS::NO_DECONFIG, HWAS::GARD_PHYP);
    } while(0);

    // Commit any error log that occurred.
    errlCommit(l_err, RUNTIME_COMP_ID);

    TRACFCOMP(g_trac_runtime, EXIT_MRK"logGardEvent")
}

/**
 * @see  src/include/runtime/interface.h for definition of call
 *
 */
void firmware_notify( uint64_t i_len, void *i_data )
{
    TRACFCOMP(g_trac_hbrt, ENTER_MRK"firmware_notify: "
             "i_len:%d", i_len );

    TRACFBIN(g_trac_runtime, "firmware_notify: i_data", i_data, i_len);

    errlHndl_t l_err = nullptr;

    // Flag to detect an invalid/unknown/not used message
    bool l_badMessage = false;

    // Capture the unique message data associated with errant message
    uint64_t l_userData1(0), l_userData2(0);

    do
    {
        // make sure the length of the data is not less than the
        // data necessary to determine type of message
        if (i_len < hostInterfaces::HBRT_FW_MSG_BASE_SIZE)
        {
            l_badMessage = true;

            TRACFCOMP(g_trac_runtime, ERR_MRK"firmware_notify: Received "
                      "a non hostInterfaces::hbrt_fw_msg data stream" );

            break;
        }

        // Cast the data to an hbrt_fw_msg to extract the input type
        hostInterfaces::hbrt_fw_msg* l_hbrt_fw_msg =
                       static_cast<hostInterfaces::hbrt_fw_msg*>(i_data);
        switch (l_hbrt_fw_msg->io_type)
        {
            case hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ:
            {
                // Distinguish based on msgType and msgq
                if ( (l_hbrt_fw_msg->generic_msg.msgType ==
                         GenericFspMboxMessage_t::MSG_ATTR_SYNC_REQUEST) &&
                        (l_hbrt_fw_msg->generic_msg.msgq ==
                         MBOX::HB_ATTR_SYNC_MSGQ) )
                {
                    attrSyncRequest((void*)&(l_hbrt_fw_msg->generic_msg.data));
                }
                else if ((l_hbrt_fw_msg->generic_msg.msgType ==
                          GenericFspMboxMessage_t::MSG_OCC_ACTIVE) &&
                         (l_hbrt_fw_msg->generic_msg.msgq ==
                          MBOX::FSP_OCC_MSGQ_ID) )
                {
                    occActiveNotification((void*)&(l_hbrt_fw_msg->generic_msg.data));
                }
                // Placing this at end as it does not have a msgq specified
                // Want to match msgType & msgq combos first
                else if (l_hbrt_fw_msg->generic_msg.msgType ==
                         GenericFspMboxMessage_t::MSG_SBE_ERROR)
                {
                    sbeAttemptRecovery(l_hbrt_fw_msg->generic_msg.data);
                }
                else
                {
                    l_badMessage = true;

                    TRACFCOMP(g_trac_runtime, ERR_MRK"firmware_notify: "
                              "Unknown FSP message type:0x%.8X, "
                              "message queue id:0x%.8X, seqNum:%d ",
                              l_hbrt_fw_msg->generic_msg.msgType,
                              l_hbrt_fw_msg->generic_msg.msgq,
                              l_hbrt_fw_msg->generic_msg.seqnum);

                    // Pack user data 1 with message input type and
                    // firmware request message sequence number
                    l_userData1 = TWO_UINT32_TO_UINT64(
                                    l_hbrt_fw_msg->io_type,
                                    l_hbrt_fw_msg->generic_msg.seqnum);

                    // Pack user data 2 with message queue and message type
                    l_userData2 = TWO_UINT32_TO_UINT64(
                                    l_hbrt_fw_msg->generic_msg.msgq,
                                    l_hbrt_fw_msg->generic_msg.msgType);
                } // END if ( (l_hbrt_fw_msg->generic_msg.msgType ... else ...
            } // END case hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ:
            break;

            case hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_OPERATION:
            {
                uint64_t l_minMsgSize = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                sizeof(hostInterfaces::hbrt_fw_msg::nvdimm_operation);
                if (i_len < l_minMsgSize)
                {
                    l_badMessage = true;

                    TRACFCOMP(g_trac_runtime, ERR_MRK"firmware_notify: "
                     "Received message HBRT_FW_MSG_TYPE_NVDIMM_OPERATION, "
                     "but size of message data(%d) is not adequate for a "
                     "complete message of this type, with size requirement of "
                     "%d", i_len, l_minMsgSize );

                    // Pack user data 1 with the message input type, the only
                    // data that can be safely retrieved
                    l_userData1 = l_hbrt_fw_msg->io_type;

                    break;
                }

                doNvDimmOperation(l_hbrt_fw_msg->nvdimm_operation);
            } // END case hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_OPERATION:
            break;

            case hostInterfaces::HBRT_FW_MSG_TYPE_GARD_EVENT:
            {
                uint64_t l_minMsgSize = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                sizeof(hostInterfaces::hbrt_fw_msg::gard_event);
                if (i_len < l_minMsgSize)
                {
                    l_badMessage = true;

                    TRACFCOMP(g_trac_runtime, ERR_MRK"firmware_notify: "
                     "Received message HBRT_FW_MSG_TYPE_GARD_EVENT, "
                     "but size of message data(%d) is not adequate for a "
                     "complete message of this type, with size requirement of "
                     "%d", i_len, l_minMsgSize );

                    // Pack user data 1 with the message input type, the only
                    // data that can be safely retrieved
                    l_userData1 = l_hbrt_fw_msg->io_type;

                    break;
                }

                logGardEvent(l_hbrt_fw_msg->gard_event);
            } // END case hostInterfaces::HBRT_FW_MSG_TYPE_GARD_EVENT:
            break;

#ifdef CONFIG_NVDIMM
            case hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_STATS:
            {
                // Note - There is no data packet for the notify portion
                //  of this function.

                NVDIMM::nvdimm_stats();
            } // END case hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_STATS:
            break;
#endif

            default:
            {
                l_badMessage = true;

                TRACFCOMP(g_trac_runtime, ERR_MRK"firmware_notify: "
                          "Unknown firmware request input type:0x%.8X ",
                          l_hbrt_fw_msg->io_type);

                l_userData1 = l_hbrt_fw_msg->io_type;
            }  // END default
            break;

        };  // END switch (l_hbrt_fw_msg->io_type)

    } while(0);

    if (l_badMessage)
    {
        /*@
         * @errortype
         * @severity     ERRL_SEV_PREDICTIVE
         * @moduleid     MOD_RT_FIRMWARE_NOTIFY
         * @reasoncode   RC_FW_NOTIFY_RT_INVALID_MSG
         * @userdata1[0:31]  Firmware Request type
         * @userdata1[32:63] Sequence number (FSP msg)
         * @userdata2[0:31]  MBOX message type (FSP msg)
         * @userdata2[32:63] Message Type (FSP msg)
         * @devdesc      Error with Firmware Notify request
         */
        l_err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                              MOD_RT_FIRMWARE_NOTIFY,
                              RC_FW_NOTIFY_RT_INVALID_MSG,
                              l_userData1,
                              l_userData2,
                              true);

        if (i_len > 0)
        {
            l_err->addFFDC(RUNTIME_COMP_ID,
                           i_data,
                           i_len,
                           0, 0, false );
        }

        l_err->collectTrace(RUNTIME_COMP_NAME, 256);
    }

    if (l_err)
    {
        //Commit the error if it exists
        errlCommit(l_err, RUNTIME_COMP_ID);
    }

    TRACFCOMP(g_trac_hbrt, EXIT_MRK"firmware_notify");
};

struct registerFwNotify
{
    registerFwNotify()
    {
        getRuntimeInterfaces()->firmware_notify = &firmware_notify;
    }
};

registerFwNotify g_registerFwNotify;
