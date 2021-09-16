/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/sbe_dump.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

/* @brief Implementation of PLDM SBE dump functions.
 */

// Targeting
#include <targeting/common/target.H>
#include <targeting/common/utilFilter.H>
#include <targeting/targplatutil.H>

// PLDM
#include <pldm/extended/sbe_dump.H>
#include <pldm/pldm_errl.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <pldm/extended/pdr_manager.H>
#include "../common/pldmtrace.H"
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_util.H>
#include <openbmc/pldm/libpldm/platform.h>

// Miscellaneous
#include <sys/msg.h>

using namespace PLDM;
using namespace ERRORLOG;
using namespace TARGETING;

// @TODO RTC 247294: Delete these constants and use the ones from libpldm
const int PLDM_OEM_IBM_SBE_MAINTENANCE_STATE = 32772;
const int PLDM_OEM_IBM_SBE_HRESET_STATE = 32773;

#ifndef __HOSTBOOT_RUNTIME

/* @brief Get the BMC's SBE Dump effecter ID for the given proc. Returns 0 if not found.
 *
 * @param[in] i_proc      The processor to search for.
 * @return effecter_id_t  The BMC's SBE dump effecter ID, or 0 if not found.
 */
effecter_id_t getSbeDumpEffecterId(const Target* const i_proc)
{
    const auto targ_entity_id = i_proc->getAttr<ATTR_PLDM_ENTITY_ID_INFO>();

    effecter_id_t effecter_id = 0;

    thePdrManager().foreachPdrOfType(PLDM_NUMERIC_EFFECTER_PDR,
                                     [&effecter_id, targ_entity_id]
                                     (const uint8_t* const pdr_data, const uint32_t pdr_data_size)
                                     {
                                         const auto numeric_effecter_pdr
                                             = reinterpret_cast<const pldm_numeric_effecter_value_pdr*>(pdr_data);

                                         if (le16toh(numeric_effecter_pdr->entity_type) == targ_entity_id.entityType
                                             && le16toh(numeric_effecter_pdr->entity_instance) == targ_entity_id.entityInstanceNumber
                                             && le16toh(numeric_effecter_pdr->container_id) == targ_entity_id.containerId)
                                         {
                                             if (le16toh(numeric_effecter_pdr->effecter_semantic_id) == PLDM_OEM_IBM_SBE_MAINTENANCE_STATE)
                                             {
                                                 effecter_id = le16toh(numeric_effecter_pdr->effecter_id);
                                                 return true; // halt the iteration
                                             }
                                         }
                                         return false; // continue the iteration
                                     });

    return effecter_id;
}

errlHndl_t PLDM::dumpSbe(Target* const i_proc, const errlHndl_t i_errorlog)
{
    PLDM_ENTER("dumpSbe(0x%08x, 0x%08x)", get_huid(i_proc), ERRL_GETPLID_SAFE(i_errorlog));

    errlHndl_t errl = nullptr;

    do
    {

    /* Search for the effecter IDs (one from the BMC, to ask it to dump the SBE,
     * and one from Hostboot, which the BMC will use to signal HB that it's done. */

    const effecter_id_t sbe_dump_effecter = getSbeDumpEffecterId(i_proc);

    const uint16_t dump_complete_effecter
        = thePdrManager().getHostStateQueryIdForStateSet(PdrManager::STATE_QUERY_EFFECTER,
                                                         PLDM_OEM_IBM_SBE_MAINTENANCE_STATE,
                                                         i_proc);

    if (sbe_dump_effecter == 0 || dump_complete_effecter == 0)
    {
        PLDM_ERR("dumpSbe: Can't find either SBE dump effecter or dump complete effecter on processor 0x%08x (%d, %d)",
                 get_huid(i_proc),
                 sbe_dump_effecter,
                 dump_complete_effecter);

        /*@
         * @errorlog
         * @severity         ERRL_SEV_INFORMATIONAL
         * @moduleid         MOD_SBE_DUMP
         * @reasoncode       RC_EFFECTER_NOT_FOUND
         * @userdata1        Processor HUID
         * @userdata2[0:31]  BMC's SBE start-dump effecter ID
         * @userdata2[32:63] Host's SBE dump-complete effecter ID
         * @devdesc          Missing SBE dump effecter ID
         * @custdesc         Error occurred during system boot.
         */
        errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                             MOD_SBE_DUMP,
                             RC_EFFECTER_NOT_FOUND,
                             get_huid(i_proc),
                             TWO_UINT32_TO_UINT64(sbe_dump_effecter,
                                                  dump_complete_effecter),
                             ErrlEntry::ADD_SW_CALLOUT);

        addBmcErrorCallouts(errl);
        break;
    }

    /* Set the effecter on the BMC, which will cause it to dump the SBE under
     * the proc that the effecter is attached to. */

    std::unique_ptr<void, decltype(&msg_q_destroy)> msgQ { msg_q_create(), msg_q_destroy };

    // Register our message queue before we send the numeric effecter set-request
    const uint32_t MSG = 0xd05be;
    thePdrManager().registerStateEffecterCallbackMsgQ(dump_complete_effecter, 0, msgQ.get(), MSG);

    const uint32_t plid = ERRL_GETPLID_SAFE(i_errorlog);

    errl = sendSetNumericEffecterValueRequest(sbe_dump_effecter, plid, sizeof(plid));

    if (errl)
    {
        PLDM_ERR("dumpSbe: Failed to send numeric effecter value set request for processor 0x%08x (err = 0x%08x)",
                 get_huid(i_proc), ERRL_GETPLID_SAFE(errl));
        break;
    }

    /* Wait on the BMC to set our effecter. */

    const int SBE_DUMP_TIMEOUT_SECONDS = 30;
    const auto dump_done_msgs = msg_wait_timeout(msgQ.get(), SBE_DUMP_TIMEOUT_SECONDS);

    // After waiting, we remove our queue from the PDR manager's callback list,
    // and we wait again for one second. This is to avoid a race condition where
    // a message might arrive on the queue after the timeout expires but before
    // we remove ourselves from the PDR manager's callback list. If we don't
    // handle that, then either (1) the PDR manager will block forever waiting
    // on a response to the message, or (2) something bad will happen when we
    // delete the queue that the PDR manager is waiting for a response on, or
    // (3) at the very least we will leak the message.
    thePdrManager().unregisterStateEffecterCallbackMsgQ(dump_complete_effecter, 0, msgQ.get());

    const auto respond_to_msg =
        [&msgQ, i_errorlog, i_proc, dump_complete_effecter](const bool prev_completed, msg_t* const msg)
    {
        bool this_completed = false;

        // @TODO RTC 247294: Remove this and use libpldm constants
        enum ibm_oem_pldm_state_set_sbe_dump_state_values {
            SBE_DUMP_COMPLETED = 0x1,
            SBE_RETRY_REQUIRED = 0x2,
        };

        // The static handler for this effecter will take care of the
        // SBE_RETRY_REQUIRED case
        if (msg->data[1] == SBE_DUMP_COMPLETED)
        {
            this_completed = true;
        }

        msg->data[0] = PLDM_SUCCESS;
        const int rc = msg_respond(msgQ.get(), msg);

        if (rc != 0)
        {
            /*@
             * @errortype
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         MOD_SBE_DUMP
             * @reasoncode       RC_SEND_FAIL
             * @userdata1[0:31]  Return code from msg_respond
             * @userdata1[32:63] PLID of error log that triggered SBE dump
             * @userdata2[0:31]  HUID of processor with faulty SBE
             * @userdata2[32:63] PLDM effecter ID of dump-complete effecter
             * @devdesc          msg_respond() failed
             * @custdesc         Firmware error during system boot
             */
            errlHndl_t err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                           MOD_SBE_DUMP,
                                           RC_SEND_FAIL,
                                           TWO_UINT32_TO_UINT64(rc, ERRL_GETPLID_SAFE(i_errorlog)),
                                           TWO_UINT32_TO_UINT64(get_huid(i_proc),
                                                                dump_complete_effecter),
                                           ErrlEntry::ADD_SW_CALLOUT);
            errlCommit(err, PLDM_COMP_ID);
        }

        return this_completed || prev_completed;
    };

    bool dump_completed = false;

    dump_completed = std::accumulate(begin(dump_done_msgs), end(dump_done_msgs),
                                     dump_completed, respond_to_msg);

    const auto stragglers = msg_wait_timeout(msgQ.get(), 1);

    dump_completed = std::accumulate(begin(stragglers), end(stragglers),
                                     dump_completed, respond_to_msg);

    /* If we got a message instead of a timeout, then we succeeded. If not,
     * create an error log. */

    if (!dump_completed)
    {
        PLDM_ERR("dumpSbe: Request for SBE dump on processor 0x%08x (effecter IDs %d, %d) timed out",
                 get_huid(i_proc),
                 sbe_dump_effecter,
                 dump_complete_effecter);

        /*@
         * @errorlog
         * @errortype        ERRL_SEV_INFORMATIONAL
         * @moduleid         MOD_SBE_DUMP
         * @reasoncode       RC_SBE_DUMP_TIMED_OUT
         * @userdata1        Processor HUID
         * @userdata2[0:31]  BMC's SBE start-dump effecter ID
         * @userdata2[32:63] Host's SBE dump-complete effecter ID
         * @devdesc          Missing SBE dump effecter ID
         * @custdesc         Error occurred during system boot.
         */
        errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                             MOD_SBE_DUMP,
                             RC_SBE_DUMP_TIMED_OUT,
                             get_huid(i_proc),
                             TWO_UINT32_TO_UINT64(sbe_dump_effecter,
                                                  dump_complete_effecter),
                             ErrlEntry::ADD_SW_CALLOUT);

        addBmcErrorCallouts(errl);
        break;
    }

    } while (false);

    PLDM_EXIT("dumpSbe(0x%08x, 0x%08x) = 0x%08x",
              get_huid(i_proc), ERRL_GETPLID_SAFE(i_errorlog), ERRL_GETPLID_SAFE(errl));

    return errl;
}

#endif

void updateSbeHresetStatus(Target* const i_proc, const ATTR_CURRENT_SBE_HRESET_STATUS_type i_state)
{
    i_proc->setAttr<ATTR_CURRENT_SBE_HRESET_STATUS>(i_state);

    const sensor_id_t hreset_noti_sensor
        = thePdrManager().getHostStateQueryIdForStateSet(PdrManager::STATE_QUERY_SENSOR,
                                                         PLDM_OEM_IBM_SBE_HRESET_STATE,
                                                         i_proc);

    assert(hreset_noti_sensor != 0, "Cannot find HRESET notification sensor on proc 0x%08x",
           get_huid(i_proc));

    sendSensorStateChangedEvent(i_proc, PLDM_OEM_IBM_SBE_HRESET_STATE, hreset_noti_sensor, 0, i_state);
}

sbe_hreset_states PLDM::notifyBeginSbeHreset(Target* const i_proc)
{
    sbe_hreset_states state;

    TargetHandleList procs;
    getAllChips(procs, TYPE_PROC);

    for (const auto proc : procs)
    {
        state.states.push_back({ get_huid(proc), proc->getAttr<ATTR_CURRENT_SBE_HRESET_STATUS>() });

        updateSbeHresetStatus(proc, SBE_HRESET_STATUS_NOT_READY);
    }

    return state;
}

void PLDM::notifyEndSbeHreset(Target* const i_proc, const ATTR_CURRENT_SBE_HRESET_STATUS_type i_state, const sbe_hreset_states& states)
{
    const auto proc_huid = get_huid(i_proc);

    for (const auto state : states.states)
    {
        if (state.huid != proc_huid)
        {
            Target* const targ = Target::getTargetFromHuid(state.huid);
            assert(targ, "endHreset: Cannot find target with HUID 0x%08x", state.huid);

            updateSbeHresetStatus(targ, state.state);
        }
    }

    updateSbeHresetStatus(i_proc, i_state);
}

void PLDM::notifySbeHresetsReady(const bool i_ready)
{
    const ATTR_CURRENT_SBE_HRESET_STATUS_type state = (i_ready
                                                       ? SBE_HRESET_STATUS_READY
                                                       : SBE_HRESET_STATUS_NOT_READY);

    // We can only HRESET functional SBEs, so if the caller says we're ready, we
    // will notify the BMC that the FUNCTIONAL procs are ready; otherwise we
    // will notify the BMC that the PRESENT procs are NOT ready.
    TargetHandleList procs;
    TARGETING::getChildAffinityTargetsByState(procs, UTIL::assertGetToplevelTarget(), CLASS_NA, TYPE_PROC,
                                              i_ready ? UTIL_FILTER_FUNCTIONAL : UTIL_FILTER_PRESENT);

    for (const auto proc : procs)
    {
        updateSbeHresetStatus(proc, state);
    }
}
