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

/* @file  rt_fwnotify.C
 *
 * @brief Contains definition of firmware_notify which can be called from
 *        by the hypervisor to control HBRT
 */

#include <sbeio/sbe_retry_handler.H>       // SbeRetryHandler
#include <sbeio/sbeioif.H>                 // getPmicHlthCheckData
#include <sbeio/sbe_psudd.H>               // SbePsu
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper
#include <runtime/interface.h>             // g_hostInterfaces
#include <runtime/runtime_reasoncodes.H>   // MOD_RT_FIRMWARE_NOTIFY, etc
#include <errl/errlentry.H>                // ErrlEntry
#include <errl/errlmanager.H>              // errlCommit
#include <errl/hberrltypes.H>              // TWO_UINT32_TO_UINT64
#include <targeting/translateTarget.H>     // RT_TARG::getHbTarget
#include <targeting/common/target.H>       // TargetHandle_t, getTargetFromHuid
#include <attributeenums.H>                // ATTRIBUTE_ID
#include <mctp/mctpif_rt.H>                // MCTP::get_next_packet
#include <mctp/mctp_errl.H>                // MCTP::addBmcAndHypErrorCallouts
#include <pldm/pldmif.H>                   // PLDM::get_next_request
#include <sys/time.h>                      // nanosleep
#include <util/util_reasoncodes.H>
#include <runtime/hbrt_utilities.H>        // HBRT_TRACE_NAME

using namespace TARGETING;
using namespace RUNTIME;
using namespace ERRORLOG;
using namespace MBOX;
using namespace SBEIO;

// Trace definition
extern trace_desc_t* g_trac_runtime;
extern trace_desc_t* g_trac_hbrt;

const uint32_t HOST_CALLBACK_TIMER_DISABLED = 0xFFFFFFFF;
const uint32_t HOST_CALLBACK_TIMER_ONE_SECOND = MS_PER_SEC;

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
 *  @brief Send a spi lock request to the Hypervisor
 *  @param[in] TargetHandl_t i_proc  Proc chip that owns the SPI engine
 *  @param[in] uint8_t i_lockState  1:block HYP, 0:allow HYP
 **/
void spiLockRequest(TargetHandle_t i_proc,
                    uint8_t i_lockState)
{
    errlHndl_t l_err = nullptr;

    do {
        if( g_hostInterfaces == nullptr ||
            (g_hostInterfaces->firmware_request == nullptr) )
        {
            TRACFCOMP(g_trac_runtime,
                      ERR_MRK"spiLockRequest: firmware_request interface not linked");
            /*@
             * @errortype
             * @severity         ERRL_SEV_INFORMATIONAL
             * @moduleid         Util::UTIL_SPI_LOCK_REQUEST
             * @reasoncode       Util::UTIL_RT_INTERFACE_ERR
             * @userdata1[0:31]  Target Processor HUID
             * @userdata1[32:63] Lock State
             * @userdata2        <unused>
             * @devdesc          firmware_request interface not linked.
             * @custdesc         Internal firmware error
             */
            l_err= new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                 Util::UTIL_SPI_LOCK_REQUEST,
                                 Util::UTIL_RT_INTERFACE_ERR,
                                 TWO_UINT32_TO_UINT64(
                                     TARGETING::get_huid(i_proc),
                                     i_lockState),
                                 0,
                                 ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Get the Proc Chip Id
        TARGETING::rtChipId_t l_chipId = 0;
        l_err = TARGETING::getRtTarget(i_proc, l_chipId);
        if(l_err)
        {
            TRACFCOMP( g_trac_runtime,
                       ERR_MRK"spiLockRequest: getRtTarget ERROR" );
            break;
        }

        // Create the firmware_request request struct to send data
        hostInterfaces::hbrt_fw_msg l_req_fw_msg;
        uint64_t l_req_fw_msg_size = sizeof(l_req_fw_msg);
        memset(&l_req_fw_msg, 0, l_req_fw_msg_size);

        // Populate the firmware_request request struct with given data
        l_req_fw_msg.io_type =
          hostInterfaces::HBRT_FW_MSG_TYPE_SPILOCK;
        l_req_fw_msg.spi_lock.procChipId = l_chipId;
        l_req_fw_msg.spi_lock.blockHyp = i_lockState;

        // Trace out firmware request info
        TRACFCOMP(g_trac_runtime,
                  INFO_MRK"spiLockRequest firmware request info: "
                  "io_type:%d, procChipId:0x%.16X, blockHyp:%d",
                  l_req_fw_msg.io_type,
                  l_req_fw_msg.spi_lock.procChipId,
                  l_req_fw_msg.spi_lock.blockHyp);

        // Create the firmware_request response struct to receive data
        hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
        uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
        memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Make the firmware_request call
        l_err = firmware_request_helper(l_req_fw_msg_size,
                                        &l_req_fw_msg,
                                        &l_resp_fw_msg_size,
                                        &l_resp_fw_msg);
        if (l_err)
        {
            // If error, break out of encompassing while loop
            break;
        }

    } while (0);

    // There is nothing the caller can do here so just commit the log
    //  internally and hope for the best
    if( l_err )
    {
        l_err->collectTrace(RUNTIME_COMP_NAME,1024);
        //Commit the error if it exists
        errlCommit(l_err, RUNTIME_COMP_ID);
    }

}


/**
 *  @brief Attempt an SBE recovery after an SBE error
 *  @param[in] uint64_t i_data Contains a HUID (in the first 4 bytes)
 *                             and a plid (in the last 4 bytes)
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

    TargetHandle_t l_target = nullptr;

    do
    {
        // Extract the target from the given HUID
        l_target = Target::getTargetFromHuid(l_sbeRetryData->huid);

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
                                   ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Before restarting the SBE, need to block out PHYP access
        //  to the SPI engine
        spiLockRequest(l_target,1);

        // Get the SBE Retry Handler, propagating the supplied PLID
        SbeRetryHandler l_SBEobj =
              SbeRetryHandler(l_target,
                              SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                              SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                              l_sbeRetryData->plid,
                              NOT_INITIAL_POWERON);

        //Attempt to recover the SBE
        l_SBEobj.main_sbe_handler();

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
        }
        else
        {
            TRACFCOMP(g_trac_runtime, "sbeAttemptRecovery: RECOVERY_FAILED");
            l_req_fw_msg.generic_msg.msgType =
                              GenericFspMboxMessage_t::MSG_SBE_RECOVERY_FAILED;

            // Make an info log to capture some state information
            /*@
             * @errortype
             * @moduleid     MOD_RT_FIRMWARE_NOTIFY
             * @reasoncode   RC_SBE_RT_RECOVERY_ERR
             * @userdata1[00:31]  Target HUID
             * @userdata1[32:63]  HWSV error log id (plid)
             * @userdata2[00:31]  SBE Message Register
             * @userdata2[32:63]  Unused
             * @devdesc      SBE did not recover after hreset attempt
             * @custdec      Informational log for internal usage
             */
            l_err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                  MOD_RT_FIRMWARE_NOTIFY,
                                  RC_SBE_RT_RECOVERY_ERR,
                                  TWO_UINT32_TO_UINT64(
                                      l_sbeRetryData->huid,
                                      l_sbeRetryData->plid),
                                  TWO_UINT32_TO_UINT64(
                                      l_SBEobj.getSbeRegister().reg,
                                      0),
                                  ErrlEntry::NO_SW_CALLOUT);
            l_err->addHwCallout( l_target, HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::NO_DECONFIG, HWAS::GARD_NULL );
            l_err->collectTrace(RUNTIME_COMP_NAME, 256);
            l_err->collectTrace(FAPI2_COMP_NAME, 256);
            l_err->collectTrace(SBEIO_COMP_NAME, 256);
            errlCommit( l_err, RUNTIME_COMP_ID );
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
             * @custdec      Internal firmware error
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   MOD_RT_FIRMWARE_NOTIFY,
                                   RC_FW_REQUEST_RT_NULL_PTR,
                                   l_sbeRetryData->huid,
                                   l_sbeRetryData->plid,
                                   ErrlEntry::ADD_SW_CALLOUT);

           break;
        }

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

    // No matter what happened, always release the lock at the end
    if( l_target )
    {
        spiLockRequest(l_target,0);
    }

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

    TRACFCOMP(g_trac_runtime, EXIT_MRK"occActiveNotification");
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
                                        ErrlEntry::ADD_SW_CALLOUT);

       l_err->collectTrace(RUNTIME_COMP_NAME, 256);

       //Commit the error
       errlCommit(l_err, RUNTIME_COMP_ID);
    }

    TRACFCOMP(g_trac_runtime, EXIT_MRK"attrSyncRequest");
}


/**
 *  @brief Log the gard event from PHYP
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
        // Make sure the error type is valid, if not, log it.
        switch(i_gardEvent.i_error_type)
        {
        case hostInterfaces::HBRT_GARD_ERROR_SLB:
        case hostInterfaces::HBRT_GARD_ERROR_NX:
            {
                // These types are supported
                break;
            }
        case hostInterfaces::HBRT_GARD_ERROR_UNKNOWN:
        case hostInterfaces::HBRT_GARD_ERROR_COMPUTATION_TEST_FAILURE:
        case hostInterfaces::HBRT_GARD_ERROR_CHIP_TOD_FAILURE:
        case hostInterfaces::HBRT_GARD_ERROR_TIMEFAC_FAILURE:
        case hostInterfaces::HBRT_GARD_ERROR_PROC_RECOVERY_THRESHOLD:
        case hostInterfaces::HBRT_GARD_ERROR_SLW:
        case hostInterfaces::HBRT_GARD_ERROR_CAPP_UNIT:
        case hostInterfaces::HBRT_GARD_ERROR_LAST:
            {
                TRACFCOMP(g_trac_runtime, "logGardEvent: ERROR: unknown/invalid "
                                          "error type 0x%.8X",
                                          i_gardEvent.i_error_type);

                /* @
                 * @errortype
                 * @severity         ERRL_SEV_PREDICTIVE
                 * @moduleid         MOD_LOG_GARD_EVENT
                 * @reasoncode       RC_LOG_GARD_EVENT_UNKNOWN_ERROR_TYPE
                 * @userdata1[0:31]  GARD error type
                 * @userdata1[32:63] Processor ID
                 * @userdata2[0:31]  Sub unit mask
                 * @userdata2[32:63] Recovery level
                 * @devdesc          Unknown/invalid error type
                 * @custdesc         Internal firmware error
                 */
                l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                       MOD_LOG_GARD_EVENT,
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
        }
        if (l_err)
        {
            break;
        }

        // Get the Target associated with processor ID
        TARGETING::TargetHandle_t l_procTarget{nullptr}, l_gardTarget{nullptr};
        l_err = RT_TARG::getHbTarget(i_gardEvent.i_procId, l_procTarget);
        if (l_err)
        {
            TRACFCOMP(g_trac_runtime, "logGardEvent: Error getting "
                                      "HB Target from processor ID 0x%0X, "
                                      "exiting ...",
                                      i_gardEvent.i_procId);
            break;
        }
        // Set the target to guard to be the target that was just retrieved and let it be overriden if necessary
        // depending on the error type requested.
        l_gardTarget = l_procTarget;

        // PHYP will send a PROC chip id if it wants to guard an NX unit. Need to grab the NX unit associated
        // with the given PROC to guard that part out.
        if (i_gardEvent.i_error_type == hostInterfaces::HBRT_GARD_ERROR_NX)
        {
            TARGETING::TargetHandleList l_NXChiplet;
            getChildChiplets(l_NXChiplet, l_procTarget, TYPE_NX, false);
            // There is only 1 NX chiplet per proc, if we didn't get it then throw an error
            if (l_NXChiplet.size() != 1)
            {
                /* @
                 * @errortype
                 * @severity         ERRL_SEV_PREDICTIVE
                 * @moduleid         MOD_LOG_GARD_EVENT
                 * @reasoncode       RC_LOG_NX_GARD_INVALID_NX_QUANTITY
                 * @userdata1[0:31]  Number of NX units found, expected 1
                 * @userdata1[32:63] Processor ID
                 * @devdesc          Expected to get only one NX unit for the given PROC but didn't. See userdata for
                 *                   amount found.
                 * @custdesc         Internal firmware error
                 */
                l_err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                      MOD_LOG_GARD_EVENT,
                                      RC_LOG_NX_GARD_INVALID_NX_QUANTITY,
                                      TWO_UINT32_TO_UINT64(
                                           l_NXChiplet.size(),
                                           i_gardEvent.i_procId),
                                      0 /* Unused */,
                                      ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
            l_gardTarget = l_NXChiplet[0];
        }

        // Log the GARD event
        /* @
         * @errortype
         * @severity         ERRL_SEV_PREDICTIVE
         * @moduleid         MOD_LOG_GARD_EVENT
         * @reasoncode       RC_LOG_GARD_EVENT
         * @userdata1[0:31]  GARD error type
         * @userdata1[32:63] Processor ID
         * @userdata2[0:31]  Sub unit mask
         * @userdata2[32:63] Recovery level
         * @devdesc          Gard event from Opal/Phyp
         * @custdesc         Hardware error detected at runtime
         */
        l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                               MOD_LOG_GARD_EVENT,
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

        // Do the actual gard. Set as predictive to allow for resource recovery
        l_err->addHwCallout( l_gardTarget, HWAS::SRCI_PRIORITY_MED,
                             HWAS::NO_DECONFIG, HWAS::GARD_Predictive);
    } while(0);

    // Commit any error log that occurred.
    errlCommit(l_err, RUNTIME_COMP_ID);

    TRACFCOMP(g_trac_runtime, EXIT_MRK"logGardEvent")
}
#if (defined(CONFIG_MCTP) || defined(CONFIG_MCTP_TESTCASES))
/**
 *  @brief Handle the next PLDM request if we have one cached, otherwise
 *         attempt to read MCTP packets in an attempt to get a PLDM request.
 *
 *  @return void
 **/
void handleMctpAvailable(void)
{
    errlHndl_t errl = nullptr;

    do{
    auto& next_pldm_request = PLDM::get_next_request();
    // if we have a complete pldm request waiting for us then
    // handle it
    if(!next_pldm_request.empty())
    {
        errl = PLDM::handle_next_pldm_request();
        if(errl)
        {
            errlCommit(errl, RUNTIME_COMP_ID);
        }
        break;
    }

    int return_code = MCTP::get_next_packet();
    TRACDCOMP(g_trac_hbrt, "handleMctpAvailable: initial get packet returned rc : %d ", return_code );
    // if nothing is waiting for us right away then do
    // not make an error, just break out.
    // We expect to get more MCTP_AVAILABLE notifications
    // than we need to process all of the packets
    if(return_code)
    {
        if(return_code == HBRT_RC_NO_MCTP_PACKET)
        {
            // this will happen a lot so do not trace
            break;
        }
        else
        {
            TRACFCOMP(g_trac_hbrt,
                      "handleMctpAvailable: rc %d occurred while attempting to retrieve the first MCTP packet",
                      return_code);
        }
    }
    else
    {
        uint8_t sleep_time_sec = 0;
        while(next_pldm_request.empty())
        {
            return_code = MCTP::get_next_packet();
            if(return_code)
            {
                if(return_code == HBRT_RC_NO_MCTP_PACKET)
                {
                    constexpr uint8_t sleep_timeout_sec = 90;
                    constexpr uint8_t one_sec = 1;
                    constexpr uint8_t zero_nsec = 0;
                    nanosleep(one_sec,zero_nsec);
                    if(sleep_time_sec++ < sleep_timeout_sec)
                    {
                        continue;
                    }
                }
                TRACFCOMP(g_trac_hbrt,
                          "handleMctpAvailable: rc %d occurred while attempting to retrieve the next MCTP packet ",
                          return_code);
                break;
             }
        }
    }

    if(return_code)
    {
        /* @
         * @errortype
         * @severity         ERRL_SEV_PREDICTIVE
         * @moduleid         MOD_RT_FIRMWARE_NOTIFY
         * @reasoncode       RC_MCTP_AVAILABLE_ERR
         * @userdata1        return code from MCTP::get_next_packet
         * @userdata2        unused
         * @devdesc          Error during MCTP message handling during hbrt
         * @custdesc         Hardware error detected at runtime
         */
        errl = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                              MOD_RT_FIRMWARE_NOTIFY,
                              RC_MCTP_AVAILABLE_ERR,
                              return_code,
                              0,
                              ErrlEntry::NO_SW_CALLOUT);
        errl->collectTrace(PLDM_COMP_NAME);
        MCTP::addBmcAndHypErrorCallouts(errl);
    }
    else
    {
        errl = PLDM::handle_next_pldm_request();
        if(errl)
        {
            // handle_next_pldm_request will trace the proper reason
            // No need to flag an error since it may just be informational
            // errl will be committed soon
        }
    }
    }while(0);

    if(errl)
    {
        errlCommit(errl, RUNTIME_COMP_ID);
    }
}
#endif

#ifndef CONFIG_FSP_BUILD
/**
 *  @brief Create the callback into HBRT for the PMIC health check
 *
 *  @param[in] i_firstCall - Creating the first callback
 *
 *  @return errlHndl_t - nullptr if no error
 **/
errlHndl_t createPmicHealthCheckCallback(bool i_firstCall)
{
    errlHndl_t l_err = nullptr;

    do {

        // Get the PMIC health check callback timer value from
        // the attribute (in milliseconds)
        auto l_host_callback_timer = UTIL::assertGetToplevelTarget()->
                                        getAttr<ATTR_PMIC_HEALTH_CHECK_TIMER>();

        // First check for callback disabled
        if (l_host_callback_timer == HOST_CALLBACK_TIMER_DISABLED)
        {
            TRACFCOMP(g_trac_hbrt,
                "createPmicHealthCheckCallback: ATTR_PMIC_HEALTH_CHECK_TIMER = %d Host callback disabled.",
                HOST_CALLBACK_TIMER_DISABLED);
            break;
        }

        // On the first call to this function set the callback timer to 1 second
        if (i_firstCall)
        {
            l_host_callback_timer = HOST_CALLBACK_TIMER_ONE_SECOND;
        }

        // Check the interface
        if( g_hostInterfaces == nullptr ||
          ( g_hostInterfaces->host_callback == nullptr ) )
        {
            TRACFCOMP(g_trac_runtime,
                ERR_MRK"createPmicHealthCheckCallback: host_callback interface not linked");
            /*@
             * @errortype
             * @severity         ERRL_SEV_INFORMATIONAL
             * @moduleid         MOD_CREATE_PMIC_HEALTH_CHECK_CALLBACK
             * @reasoncode       RC_HOST_CALLBACK_INTERFACE_ERR
             * @userdata1        First call to create callback function
             * @userdata2        <unused>
             * @devdesc          Host callback interface not linked
             * @custdesc         Internal firmware error
             */
            l_err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                  MOD_CREATE_PMIC_HEALTH_CHECK_CALLBACK,
                                  RC_HOST_CALLBACK_INTERFACE_ERR,
                                  i_firstCall,
                                  0,
                                  ErrlEntry::ADD_SW_CALLOUT);
            l_err->collectTrace(HBRT_TRACE_NAME,1024);
            break;
        }

        // Generate a new host callback (in milliseconds)
        TRACFCOMP(g_trac_hbrt,
            "createPmicHealthCheckCallback: Create host_callback for PMIC health check in %d milliseconds",
            l_host_callback_timer);

        size_t l_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE;
        uint8_t l_msg_buf[l_msg_size] = {0};

        hostInterfaces::hbrt_fw_msg* l_fw_msg =
            reinterpret_cast<hostInterfaces::hbrt_fw_msg *>(l_msg_buf);
        l_fw_msg->io_type = hostInterfaces::HBRT_FW_MSG_TYPE_PMIC_HEALTH_CHECK;

        int l_rc = g_hostInterfaces->host_callback(
                                        l_host_callback_timer,
                                        l_msg_size,
                                        reinterpret_cast<void*>(l_fw_msg) );

        if(l_rc)
        {
            TRACFCOMP( g_trac_hbrt, ERR_MRK
                "createPmicHealthCheckCallback: host_callback failed. "
                "rc 0x%X host callback timer 0x%X message size %d",
                l_rc, l_host_callback_timer, l_msg_size );

            // Convert rc to error log
            /*@
             * @errortype
             * @moduleid         MOD_CREATE_PMIC_HEALTH_CHECK_CALLBACK
             * @reasoncode       RC_HOST_CALLBACK_ERR
             * @userdata1        Hypervisor return code
             * @userdata2[0:31]  Callback timer value
             * @userdata2[32:63] Callback message size
             * @devdesc          Host Callback failed.
             * @custdesc         Internal firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        MOD_CREATE_PMIC_HEALTH_CHECK_CALLBACK,
                                        RC_HOST_CALLBACK_ERR,
                                        l_rc,
                                        TWO_UINT32_TO_UINT64(
                                                    l_host_callback_timer,
                                                    l_msg_size));

            l_err->collectTrace(HBRT_TRACE_NAME,1024);
            break;
        }
    } while (0);

    return l_err;
}

/**
 *  @brief Handle the PHYP callback to perform the PMIC health check.
 *
 *  @return void
 **/
void handlePmicHealthCheckCallback(void)
{
    errlHndl_t l_err = nullptr;

    do
    {
        // PMIC health check uses the SBE PSU interface,
        // make sure it is constructed
        SbePsu::getTheInstance();

        // Call function to create a PEL with PMIC telemetry data from the SBE.
        // This info PEL will be committed inside the health check function.
        // The error returned indicates a problem with the health check, commit it.
        l_err = SBEIO::getPmicHlthCheckData();
        if (l_err)
        {
            TRACFCOMP(g_trac_hbrt,
                "handlePmicHealthCheckCallback: Call to getPmicHlthCheckData failed");
            // Do not break out, commit the error then create a new
            // callback and try again, make sure the error is informational
            l_err->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(l_err, RUNTIME_COMP_ID);
        }

        // Call the function to create a new callback
        uint32_t l_firstCall = false;
        l_err = createPmicHealthCheckCallback( l_firstCall );
        if (l_err)
        {
            TRACFCOMP(g_trac_hbrt,
                "handlePmicHealthCheckCallback: Call to createPmicHealthCheckCallback failed");
            // Make sure the error is informational
            l_err->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(l_err, RUNTIME_COMP_ID);
            break;
        }

    } while (0);

}

/**
 *  @brief Setup the initial callback into HBRT for the PMIC health check
 **/
void setupPmicHealthCheck()
{
    errlHndl_t l_err = nullptr;

    // Call the function to create the first host callback
    uint32_t l_firstCall = true;
    l_err = createPmicHealthCheckCallback( l_firstCall );
    if (l_err)
    {
        TRACFCOMP(g_trac_hbrt,
            "setupPmicHealthCheck: Call to createPmicHealthCheckCallback failed");
        errlCommit(l_err, RUNTIME_COMP_ID);
    }
}
#endif

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

           TRACFCOMP(g_trac_runtime, ERR_MRK"firmware_notify: "
               "Received a non hostInterfaces::hbrt_fw_msg data stream" );

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
#if (defined(CONFIG_MCTP) || defined(CONFIG_MCTP_TESTCASES))
            case hostInterfaces::HBRT_FW_MSG_TYPE_MCTP_AVAILABLE:
            {
                TRACDCOMP(g_trac_runtime, "firmware_notify: "
                "handling MCTP Available command");

                handleMctpAvailable();
            }// END case hostInterfaces::HBRT_FW_MSG_TYPE_MCTP_AVAILABLE:
            break;
#endif
#ifndef CONFIG_FSP_BUILD
            case hostInterfaces::HBRT_FW_MSG_TYPE_PMIC_HEALTH_CHECK:
            {
                TRACFCOMP(g_trac_runtime,
                          "firmware_notify: PMIC health check callback");

                handlePmicHealthCheckCallback();
            }
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
                              ErrlEntry::ADD_SW_CALLOUT);

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

#ifndef CONFIG_FSP_BUILD
        postInitCalls_t* rt_postInits = getPostInitCalls();
        rt_postInits->callSetupPmicHealthCheck = &setupPmicHealthCheck;
#endif
    }
};

registerFwNotify g_registerFwNotify;
