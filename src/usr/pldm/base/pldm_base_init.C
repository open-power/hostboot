/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_base_init.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
 * @file pldm_base_init.C
 *
 * @brief Source code for the function that will be called when the pldm_base
 *        module is loaded by the init service.
 *
 */

#include <mctp/mctpif.H>
#include "pldm_requester.H"
#include "pldm_msg_queues.H"
#include <initservice/taskargs.H>
#include <pldm/requests/pldm_tid_requests.H>
#include <pldm/pldm_reasoncodes.H>
#include <assert.h>
#include <pldm/requests/pldm_datetime_requests.H>
#include <sys/sync.h>
#include <sys/task.h>
#include <vector>
#include <errl/errlmanager.H>
#include <pldm/pldmif.H>
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/pldm_trace.H>
#include <initservice/initserviceif.H>

using namespace PLDM;

/* @brief Structure for recording a callback that will be invoked when the
 * system is shutting down.
 */
struct shutdown_event
{
    shutdown_callback_t callback = nullptr;
    void* context = nullptr; // Argument to the callback
};

namespace
{

// This lock protects access to g_shutdown_events.
mutex_t g_shutdown_events_mutex = MUTEX_INITIALIZER;
// A list of callbacks to be invoked when firmware begins shutting down.
std::vector<shutdown_event> g_shutdown_events;

#ifdef CONFIG_PLDM
void* shutdown_listener(msg_q_t const i_msgQ)
{
    task_detach();

    // Wait for Initservice to tell us that the host is shutting down
    auto msg = msg_wait(i_msgQ);

    // Lock access to g_shutdown_events while we iterate it
    const auto lock = scoped_mutex_lock(g_shutdown_events_mutex);

    PLDM_INF(ENTER_MRK"Invoking PLDM shutdown events");

    for (const auto event : g_shutdown_events)
    {
        event.callback(event.context);
    }

    g_shutdown_events.clear();

    PLDM_INF(EXIT_MRK"Finished invoking PLDM shutdown events");

    // Respond to Initservice to let the shutdown continue
    msg_respond(i_msgQ, msg);

    return nullptr;
}
#endif

/**
* @brief This is the function that gets called when pldm_base is loaded by
*        initservice. It handles registering the pldm msg queues, initializing
*        the pldm requester task, and telling the mctp layer we are ready to
*        register the lpc bus to start MCTP traffic.
*/
void base_init(errlHndl_t& o_errl)
{
    do{
    // register g_outboundPldmReqMsgQ, g_inboundPldmRspMsgQ,
    // and g_inboundPldmReqMsgQ so external modules can resolve
    // them easily
    registerPldmMsgQs();

    // This will call the pldmRequester constructor which
    // will launch the task waiting for inbound PLDM requests
    // from the BMC
    Singleton<pldmRequester>::instance().init();

    // Notify MCTP layer that they can register the bus
    // and start MCTP traffic
    MCTP::register_mctp_bus();

    // libpldm is loaded by standalone simics, but CONFIG_PLDM isn't set in a
    // standalone environment, so we use this to avoid trying to send PLDM
    // notifications when there's no BMC.
#ifdef CONFIG_PLDM
    // Get BMC TID (terminus ID)
    o_errl = getTID();
    if(o_errl)
    {
        break;
    }

    // Fetch the current date/time from the BMC and seed it into
    // ErrlManager for error log timestamps.
    date_time_t l_currentTime{};
    o_errl = getDateTime(l_currentTime);
    if(o_errl)
    {
        break;
    }
    ERRORLOG::ErrlManager::setBaseDateTime(l_currentTime);

    // We don't want to keep these vectors around any longer than we have
    // to so put them in their own scope along with the call that needs them
    {
        std::vector<uint8_t> bios_string_table;
        std::vector<uint8_t> bios_attr_table;
        // Copy all the pending "hb_*" attributes into the "hb_*_current" attributes
        o_errl = PLDM::latchBiosAttrs(bios_string_table, bios_attr_table);
        if(o_errl)
        {
            break;
        }
    }

    // Create a message queue for our shutdown listener. Initservice will send a
    // message to this queue when shutdown begins.
    const auto msgQ = msg_q_create();

    task_create(shutdown_listener, msgQ);

    INITSERVICE::registerShutdownEvent(PLDM_COMP_ID,
                                       msgQ,
                                       0, // Message ID, don't care what this value is
                                       // We want an early notification so we
                                       // don't have to worry about other
                                       // resources being shut down.
                                       INITSERVICE::HIGHEST_PRIORITY);

    // call ErrlManager function - tell him that BMC interface is ready!
    ERRORLOG::ErrlManager::errlResourceReady(ERRORLOG::BMC);

#endif
    }while(0);

    if(o_errl)
    {
        ERRORLOG::errlCommit(o_errl, PLDM_COMP_ID);
        /* Give ErrlManager a chance to handle committed log */
        task_yield();
        INITSERVICE::doShutdown(RC_BASE_INIT_FAIL);
        assert(false, "pldm_base_init: should never return from doShutdown");
    }
}

} // anonymous namespace

namespace PLDM
{

void registerShutdownCallback(shutdown_callback_t i_handler, void* i_context)
{
    const auto lock = scoped_mutex_lock(g_shutdown_events_mutex);
    g_shutdown_events.push_back({ i_handler, i_context });
}

} // namespace PLDM

TASK_ENTRY_MACRO( base_init );
