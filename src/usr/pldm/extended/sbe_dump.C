/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/sbe_dump.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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
#include <pldm/pldm_trace.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_util.H>
#include <openbmc/pldm/libpldm/include/libpldm/platform.h>
#include <openbmc/pldm/libpldm/include/libpldm/oem/ibm/libpldm/state_set_oem_ibm.h>

#include <initservice/istepdispatcherif.H>

// Miscellaneous
#include <sys/msg.h>
#include <sys/time.h>

using namespace PLDM;
using namespace ERRORLOG;
using namespace TARGETING;

// PLDM local definition which should be coming from state_set_oem_ibm.h
// when PLDM subtree updates occur
const uint16_t PLDM_OEM_IBM_SBE_SEMANTIC_ID = 32775;

/* @brief Get the BMC's SBE Dump effecter ID for the given target. Returns 0 if not found.
 *
 * @param[in] i_target    The target to search for.
 * @return effecter_id_t  The BMC's SBE dump effecter ID, or 0 if not found.
 * Note: HBRT cannot access the PDR repository, so this is a restricted function
 */
effecter_id_t getSbeDumpEffecterId(const Target* const i_target)
{
#ifndef __HOSTBOOT_RUNTIME
    pldm_entity entity_info = targeting_to_pldm_entity_id(i_target->getAttr<ATTR_PLDM_ENTITY_ID_INFO>());

    return thePdrManager()
        .findNumericEffecterId(entity_info,
                               [](pldm_numeric_effecter_value_pdr const * const numeric_effecter)
                               {
                                   return (le16toh(numeric_effecter->effecter_semantic_id) == PLDM_OEM_IBM_SBE_SEMANTIC_ID);
                               });
#else
    TARGETING::ATTR_SBE_DUMP_EFFECTER_ID_type sbe_dump_effecter = 0;
    if (i_target->tryGetAttr<TARGETING::ATTR_SBE_DUMP_EFFECTER_ID>(sbe_dump_effecter))
    {
        PLDM_INF("getSbeDumpEffecterId i_target=0x%X sbe_dump_effecter=0x%X (%d)", get_huid(i_target), sbe_dump_effecter, sbe_dump_effecter);
    }
    return sbe_dump_effecter;
#endif
}

/* @brief Get the attribute from IPL for SBE Dump Sensor State ID for the given target.
 * Returns 0 if not found.
 *
 * @param[in] i_target                   The target to search for.
 * @return ATTR_SBE_DUMP_SENSOR_ID_type  The Attribute for SBE dump Sensor State ID,
 *                                          or 0 if not found.
 */
TARGETING::ATTR_SBE_DUMP_SENSOR_ID_type getSbeDumpStateSensorId(const Target* const i_target)
{
    TARGETING::ATTR_SBE_DUMP_SENSOR_ID_type sbe_dump_sensor = 0;
    i_target->tryGetAttr<TARGETING::ATTR_SBE_DUMP_SENSOR_ID>(sbe_dump_sensor);

    return sbe_dump_sensor;
}

/** @brief Get the target related to the given target that contains
 *  the info for the SBE dump sensors/effecters for the given
 *  target. E.g. for OCMBs, get the child DIMM that the effecters are
 *  attached to.
 *
 * @param[in] i_target       The target to retrieve its appropriate effecter id for later
 * @return target or nullptr If not found a nullptr, otherwise the appropriate target
 */
Target* getDumpTarget(Target* const i_target)
{
    switch (i_target->getAttr<ATTR_TYPE>())
    {
    case TYPE_PROC:
        // HBRT does NOT support dumping the PROC SBE at this time
#ifdef __HOSTBOOT_RUNTIME
        return nullptr;
#else
        return i_target;
#endif
    case TYPE_OCMB_CHIP: {
        const auto dimms = composable(getChildAffinityTargets)(i_target, CLASS_NA, TYPE_DIMM, true);

        TARGETING::ATTR_SBE_DUMP_EFFECTER_ID_type sbe_dump_effecter = 0;
        for (const auto dimm : dimms)
        {
            // HBRT cannot access the PDR repository, so the SBE_DUMP_EFFECTER_ID is
            // stored on an attribute per DIMM
            // For HBRT we need to validate that the OCMB dimm does have a non-zero SBE_DUMP_EFFECTER_ID
            // The effecter id on each dimm under an OCMB will provide the proper (same) effecter id
            // The same effecter id is used during IPL and Runtime (stored on its proper target)
            // The usage of the SBE_DUMP_EFFECTER_ID cannot be leveraged until such time in the IPL
            // where the proper Odyssey handlers would be available to drive any dump and recovery
            // operations.
            if (dimm->tryGetAttr<TARGETING::ATTR_SBE_DUMP_EFFECTER_ID>(sbe_dump_effecter))
            {
                if (sbe_dump_effecter != 0)
                {
                    PLDM_INF("getDumpTarget OCMB HUID=0x%X DIMM HUID=0x%X sbe_dump_effecter=0x%X (%d)",
                             get_huid(i_target), get_huid(dimm), sbe_dump_effecter, sbe_dump_effecter);
                    return dimm;
                }
            }
        }
        break;
    }
    default:
        // the nullptr return will cause the dump to log an informational log and skip dumping
        PLDM_INF("getDumpTarget DEFAULT HUID=0x%X returning nullptr", get_huid(i_target));
        break;
    }
    return nullptr;
}

errlHndl_t PLDM::dumpSbe(Target* const i_target, const uint32_t i_plid)
{
    PLDM_ENTER("dumpSbe i_target=0x%X i_plid=0x%08x", get_huid(i_target), i_plid);

    errlHndl_t errl = nullptr;

    do
    {

    Target* const dump_target = getDumpTarget(i_target);

    // IF FAILED TO GET TARGET
    if (!dump_target)
    {
        /*@
         *@moduleid         MOD_SBE_DUMP
         *@reasoncode       RC_DUMP_TARGET_NOT_FOUND
         *@userdata1        Input target HUID
         *@devdesc          Missing target to dump
         *@custdesc         Error occurred during system boot.
         */
        errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                             MOD_SBE_DUMP,
                             RC_DUMP_TARGET_NOT_FOUND,
                             get_huid(i_target),
                             0,
                             ErrlEntry::ADD_SW_CALLOUT);

        PLDM_ERR("dumpSbe: No dump target exists for i_target=0x%08X",
                 get_huid(i_target));
        errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    /* Search for the effecter IDs (one from the BMC, to ask it to dump the SBE,
     * and one from Hostboot, which the BMC will use to signal HB that it's done. */

    const effecter_id_t sbe_dump_effecter = getSbeDumpEffecterId(dump_target);
    PLDM_INF("dumpSbe: Using dump_target=0x%X i_target=0x%X effecter ID (%d)",
             get_huid(dump_target), get_huid(i_target), sbe_dump_effecter);

    const uint16_t dump_complete_effecter
        = thePdrManager().getHostStateQueryIdForStateSet(PdrManager::STATE_QUERY_EFFECTER,
                                                         PLDM_OEM_IBM_SBE_MAINTENANCE_STATE,
                                                         dump_target);

    PLDM_INF("dumpSbe dump_target=0x%X i_target=0x%X sbe_dump_effecter=0x%X (%d) dump_complete_effecter=0x%X (%d)",
                get_huid(dump_target), get_huid(i_target), sbe_dump_effecter, sbe_dump_effecter, dump_complete_effecter, dump_complete_effecter);

    //FAILED TO GET EFFECTER DATA,
    if (sbe_dump_effecter == 0 || dump_complete_effecter == 0)
    {
        PLDM_ERR("dumpSbe: Can't find either SBE dump effecter or dump complete effecter on dump_target=0x%X sbe_dump_effecter=%d dump_complete_effecter=%d",
                 get_huid(dump_target),
                 sbe_dump_effecter,
                 dump_complete_effecter);

        /*@
         * @errorlog
         * @severity         ERRL_SEV_INFORMATIONAL
         * @moduleid         MOD_SBE_DUMP
         * @reasoncode       RC_EFFECTER_NOT_FOUND
         * @userdata1        Dump target HUID
         * @userdata2[0:31]  BMC's SBE start-dump effecter ID
         * @userdata2[32:63] Host's SBE dump-complete effecter ID
         * @devdesc          Missing SBE dump effecter ID
         * @custdesc         Error occurred during system boot.
         */
        errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                             MOD_SBE_DUMP,
                             RC_EFFECTER_NOT_FOUND,
                             get_huid(dump_target),
                             TWO_UINT32_TO_UINT64(sbe_dump_effecter,
                                                  dump_complete_effecter),
                             ErrlEntry::ADD_SW_CALLOUT);

        addBmcErrorCallouts(errl);
        break;
    }

    /* Set the effecter on the BMC, which will cause it to dump the SBE under
     * the target that the effecter is attached to. */
#ifndef __HOSTBOOT_RUNTIME
    std::unique_ptr<void, decltype(&msg_q_destroy)> msgQ { msg_q_create(), msg_q_destroy };

    if (dump_target->getAttr<ATTR_TYPE>() == TYPE_PROC)
    {
        const uint32_t MSG = 0xd05be;
        // Register our message queue before we send the numeric effecter set-request
        thePdrManager().registerStateEffecterCallbackMsgQ(dump_complete_effecter,0,msgQ.get(),MSG);
    }
#endif // end #ifndef __HOSTBOOT_RUNTIME

    // This is set Effecter request to BMC to dump the ODY.
    errl = sendSetNumericEffecterValueRequest(sbe_dump_effecter, i_plid, sizeof(i_plid));

    if (errl)
    {
        PLDM_ERR("dumpSbe: Failed to send numeric effecter value set request for dump_target=0x%X ERRL=0x%X",
                 get_huid(dump_target), ERRL_GETPLID_SAFE(errl));
        break;
    }

    bool dump_completed = true; // HBRT will not use msgQ's so set to complete

    // The dump should complete in 2-3 minutes, so double the time (we need to block the
    // transaction to disallow any i2c bus contentions that may propagate by the BMC pulling
    // the dump).
    //
    // **NOTE** Currently due to BMC FSI driver issues the timeout window is 10 minutes
    // to address the worse case scenarios.
    //
    // The BMC hub master is running slower (at local bus frequency as opposed to Aspeed FSI frequency)
    // and then the remote slave is even slower due to another local bus clock div.  The BMC
    // just hardcodes the I2C clock div which slows down the I2C bus speed.
    constexpr uint64_t DUMP_TIMEOUT_INTERVAL_SECONDS = 60;     // seconds to wait per interval
    constexpr uint64_t DUMP_TIMEOUT_RETRIES = 10;              // 10 times

    // @TODO RTC 247294: Remove this and use libpldm constants
    enum ibm_oem_pldm_state_set_sbe_dump_state_values {
                    SBE_DUMP_STATUS_UNAVAILABLE = 0x0,
                    SBE_DUMP_COMPLETED = 0x1,
                    SBE_RETRY_REQUIRED = 0x2,
                };

    // *** P10 SBE DUMP ***
    if (dump_target->getAttr<ATTR_TYPE>() == TYPE_PROC)
    {
#ifndef __HOSTBOOT_RUNTIME
        /* Wait on the BMC to set our effecter. */

        uint64_t sbe_dump_timeout_milliseconds = DUMP_TIMEOUT_INTERVAL_SECONDS * MS_PER_SEC; //1 Min

        size_t retryCount = 0;
        std::vector<msg_t*> dump_done_msgs;
        while (retryCount++ < DUMP_TIMEOUT_RETRIES)
        {
            // Reset the watchdog timer
            INITSERVICE::sendProgressCode();

            dump_done_msgs = msg_wait_timeout(msgQ.get(), sbe_dump_timeout_milliseconds);
            if (!dump_done_msgs.empty())
            {
                PLDM_INF("dumpSbe: i_target=0x%X dump_target=0x%X total_seconds_waited=%d",
                        get_huid(i_target),
                        get_huid(dump_target),
                        (((retryCount-1)*DUMP_TIMEOUT_INTERVAL_SECONDS) +
                                (DUMP_TIMEOUT_INTERVAL_SECONDS -
                                (sbe_dump_timeout_milliseconds/MS_PER_SEC))) );
                break;
            }
            // Need to reset the milliseconds since the msg_wait_timeout sends back the remainder
            sbe_dump_timeout_milliseconds = DUMP_TIMEOUT_INTERVAL_SECONDS * MS_PER_SEC;

        } // end while DUMP_TIMEOUT_RETRIES

        // Reset the watchdog timer
        INITSERVICE::sendProgressCode();

        // After waiting, we remove our queue from the PDR manager's callback list,
        // and we wait again for one second. This is to avoid a race condition where
        // a message might arrive on the queue after the timeout expires but before
        // we remove ourselves from the PDR manager's callback list. If we don't
        // handle that, then either (1) the PDR manager will block forever waiting
        // on a response to the message, or (2) something bad will happen when we
        // delete the queue that the PDR manager is waiting for a response on, or
        // (3) at the very least we will leak the message.
        thePdrManager().unregisterStateEffecterCallbackMsgQ(dump_complete_effecter, 0, msgQ.get());

        sbe_dump_timeout_milliseconds = MS_PER_SEC; // 1 second for stragglers
        const auto stragglers = msg_wait_timeout(msgQ.get(), sbe_dump_timeout_milliseconds);

        dump_completed = !dump_done_msgs.empty() || !stragglers.empty();

        // Determine message response.
        const auto respond_to_msg =
            [&](const bool prev_completed, msg_t* const msg)
            {
                bool this_completed = false;

                // The static handler for this effecter will take care of the
                // SBE_RETRY_REQUIRED case
                if (msg->data[1] == SBE_DUMP_COMPLETED)
                {
                    this_completed = true;
                }

                msg->data[0] = PLDM_SUCCESS;
                const int rc = msg_respond(msgQ.get(), msg);

                assert(rc == 0,
                    "dumpSbe: msg_respond failed: rc = %d, plid = 0x%08x, dump_target huid "
                    "= 0x%08x, dump_complete_effecter = %d",
                    rc, i_plid, get_huid(dump_target), dump_complete_effecter);

                return this_completed || prev_completed;
            };

        bool dump_succeeded = false;

        if (dump_completed) // If dump_done_msgs is not empty we can see if dump succeeded.
        {
            dump_succeeded = std::accumulate(begin(dump_done_msgs), end(dump_done_msgs),
                                            dump_succeeded, respond_to_msg);

            dump_succeeded = std::accumulate(begin(stragglers), end(stragglers),
                                            dump_succeeded, respond_to_msg);
        }


        PLDM_INF("dumpSbe: dump_target HUID=0x%X dump_succeeded=%d", get_huid(dump_target),
                    dump_succeeded);

        if (!dump_succeeded )
        {
            PLDM_ERR("dumpSbe: Request for SBE dump on dump_target=0x%X sbe_dump_effecter=%d "
                    "dump_complete_effecter=%d timed out",
                    get_huid(dump_target),
                    sbe_dump_effecter,
                    dump_complete_effecter);

            /*@
            *@moduleid         MOD_SBE_DUMP
            *@reasoncode       RC_SBE_DUMP_TIMED_OUT
            *@userdata1        Dump target HUID
            *@userdata2[0:31]  BMC's SBE start-dump effecter ID
            *@userdata2[32:63] Host's SBE dump-complete effecter ID
            *@devdesc          BMC failed to respond to dump request.
            *@custdesc         Error occurred during failure-data capture.
            */
            errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                MOD_SBE_DUMP,
                                RC_SBE_DUMP_TIMED_OUT,
                                get_huid(dump_target),
                                TWO_UINT32_TO_UINT64(sbe_dump_effecter,
                                                    dump_complete_effecter),
                                ErrlEntry::ADD_SW_CALLOUT);

            addBmcErrorCallouts(errl);
            break;
        } // end if dump succeeded.
#else // HBRT

        // HBRT does NOT have access to all of the PLDM semantics, so just do a simple timeout.
        uint64_t sbe_dump_window = (DUMP_TIMEOUT_INTERVAL_SECONDS * DUMP_TIMEOUT_RETRIES) * NS_PER_SEC; // 10 minutes
        nanosleep(0, sbe_dump_window);
#endif 
    } // end if TYPE_PROC

    // *** Odyssey SBE DUMP ***
    else if (i_target->getAttr<ATTR_TYPE>() == TYPE_OCMB_CHIP)
    {
        // In both IPL and HBRT we will poll on a state sensor value

        constexpr uint64_t wait_time = DUMP_TIMEOUT_INTERVAL_SECONDS;
        size_t retryCounter = 0;
        uint32_t return_value = 0;
        TARGETING::ATTR_SBE_DUMP_SENSOR_ID_type OCMB_dump_SensorStateId = 0;
        errlHndl_t sensor_errl = nullptr;

        while (retryCounter++ < DUMP_TIMEOUT_RETRIES)
        {
            // BMC State Sensor ID
            OCMB_dump_SensorStateId = getSbeDumpStateSensorId(i_target);

            uint8_t  return_byte_data_size = 0;
            sensor_errl = sendGetStateSensorValueRequest(OCMB_dump_SensorStateId,
                                                  return_value,
                                                  return_byte_data_size);
            if (sensor_errl)
            {
                PLDM_ERR("dumpSbe failed sendGetStateSensorValueRequest i_target=0x%X "
                         "ERRL=0x%X", get_huid(i_target), ERRL_GETEID_SAFE(sensor_errl));
                sensor_errl->collectTrace(PLDM_COMP_NAME);

                // Just in case the dump did get kicked off, wait the maximum
                // remaining time before giving up
                nanosleep(wait_time*(DUMP_TIMEOUT_RETRIES-retryCounter), 0);

                break;
            }

            if(return_value == SBE_DUMP_COMPLETED)
            {
                dump_completed = true;
                break;
            }
            else if(return_value == SBE_DUMP_STATUS_UNAVAILABLE)
            {
                PLDM_ERR("Status_unavailable(0) Waiting Time(%d Sec.) "
                         "CountDown(%d of %d)",
                         wait_time, retryCounter, DUMP_TIMEOUT_RETRIES);
                nanosleep(wait_time, 0);
            }
            else if(return_value == SBE_RETRY_REQUIRED)
            {
                PLDM_ERR("Dump in Progress(2) Waiting Time(%d Sec.) CountDown(%D of %d)",
                         wait_time, retryCounter, DUMP_TIMEOUT_RETRIES);
                nanosleep(wait_time, 0);
            }
            else
            {
                PLDM_ERR("Unknown status (=%d) Waiting Time(%d Sec.) CountDown(%D of %d)",
                         return_value, wait_time, retryCounter, DUMP_TIMEOUT_RETRIES);
                nanosleep(wait_time, 0);
            }

        }  // end while DUMP_TIMEOUT_RETRIES

        PLDM_INF("dumpSbe: dump_target HUID=0x%X dump_completed=%d", get_huid(dump_target),
                    dump_completed);

        if (!dump_completed)
        {
            PLDM_ERR("dumpSbe: Request for SBE dump on dump_target=0x%X sbe_dump_effecter=%d "
                    "dump_complete_effecter=%d failed",
                    get_huid(dump_target),
                    sbe_dump_effecter,
                    dump_complete_effecter);

            /*@
            *@moduleid         MOD_SBE_DUMP
            *@reasoncode       RC_SBE_DUMP_FAILED
            *@userdata1        Dump target HUID
            *@userdata2[0:31]  OCMB SBE SensorStateId
            *@userdata2[32:63] Host's SBE dump-complete effecter ID
            *@devdesc          SBE dump request failed.
            *@custdesc         Error occurred during failure-data capture.
            */
            errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                 MOD_SBE_DUMP,
                                 RC_SBE_DUMP_FAILED,
                                 get_huid(dump_target),
                                 TWO_UINT32_TO_UINT64(OCMB_dump_SensorStateId,
                                                      return_value),
                                 ErrlEntry::ADD_SW_CALLOUT);
            errl->collectTrace(PLDM_COMP_NAME);
            errl->collectTrace(SBEIO_COMP_NAME);

            addBmcErrorCallouts(errl);

            //attach the previous sensor failure log to this if we had one
            if( sensor_errl )
            {
                errl->aggregate(sensor_errl);
            }

            break;
        } // end if dump not completed
    } // end if TYPE_OCMB_CHIP

    } while (false);

    // checks for PLDM error and adds flight recorder data to log
    addPldmFrData(errl);

    PLDM_EXIT("dumpSbe i_target=0x%X i_plid=0x%X ERRL=0x%X",
              get_huid(i_target), i_plid, ERRL_GETEID_SAFE(errl));

    return errl;
}

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
