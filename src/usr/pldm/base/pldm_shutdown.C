/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_shutdown.C $                           */
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

/**
 * @file pldm_shutdown.H
 *
 * @brief Contains definitions for PLDM shutdown processing. This object file
 * must be a part of the Hostboot Base image (HBB) because the shutdown path
 * mustn't require making PNOR requests.
 */

// Standard library
#include <memory>

// PLDM
#include <pldm/base/pldm_shutdown.H>
#include <pldm/pldm_reasoncodes.H>
#include "../common/pldmtrace.H"
#include <pldm/pldm_const.H>
#include <pldm/pldm_util.H>
#include <pldm/extended/pdr_manager.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <openbmc/pldm/libpldm/platform.h>
#include <openbmc/pldm/libpldm/base.h>
#include <openbmc/pldm/libpldm/state_set.h>

// System/kernel
#include <sys/misc.h>
#include <sys/msg.h>
#include <kernel/console.H>

// Targeting/initservice
#include <targeting/targplatutil.H>
#include <targeting/common/utilFilter.H>

// Misc
#include <sys/vfs.h>
#include <initservice/initserviceif.H>
#include <arch/ppc.H>

using namespace PLDM;
using namespace TARGETING;

// This structure is passed as the argument to the thread that we create to wait
// for the graceful shutdown.
struct shutdown_args
{
    // The message queue that Initservice will send us a message on, indicating
    // that the memory page flushing is complete.
    std::unique_ptr<void, decltype(&msg_q_destroy)> msgq;

    // The PLDM message queue that we will use to send the BMC the
    // shutdown-complete notification.
    msg_q_t pldm_msg_q = nullptr;

    // Hostboot's terminus ID. Obtained from the PDR Manager, which code lives
    // in the extended image, and so we have to fetch it and store here before
    // shutting down because we can't/shouldn't access the extended image in the
    // shutdown path to avoid making page requests.
    terminus_id_t hb_terminus_id = 0;

    // The shutdown sensor ID to use in the completion notification. We have to
    // read this before shutting down, because we cannot read any attributes in
    // the shutdown path, since it might entail making page requests to the BMC
    // which we can't/shouldn't do while shutting down.
    sensor_id_t shutdown_sensor_id;
};

/* @brief Wait for a message from Initservice on the message queue (provided in
 * the argument) that tells us that all dirty pages have been flushed from
 * memory, after which we send a notification to the BMC letting it know that we
 * are finished gracefully shutting down.
 *
 * @param[in] i_args  Pointer to shutdown_args structure
 */
static void* wait_for_graceful_shutdown(void* const i_args)
{
    task_detach();

    const std::unique_ptr<shutdown_args> args { static_cast<shutdown_args*>(i_args) };

    msg_t* msg = msg_wait(args->msgq.get());

    printk("\nSending PLDM graceful shutdown notification\n");

    errlHndl_t errl = sendSensorStateChangedEvent(args->shutdown_sensor_id,
                                                  0, // subsensor offset 0
                                                  PLDM_SW_TERM_GRACEFUL_SHUTDOWN,
                                                  args->hb_terminus_id);

    if (errl)
    {
        // We can't commit the error this late in the shutdown path because
        // we've already flushed PNOR pages, shut down the error service etc. so
        // we just send some traces to the printk buffer and upgrade the
        // shutdown status to "error".

        printk("requestSoftPowerOff: Error occurred in sendSensorStateChangedEvent:\n");
        printk(TRACE_ERR_FMT "\n", TRACE_ERR_ARGS(errl));

        // This call to doShutdown will just update the "worst shutdown status"
        // so that we don't completely lose the error.
        INITSERVICE::doShutdown(SHUTDOWN_STATUS_PLDM_NOTI_FAILED, true /* background shutdown */);
    }

    msg_respond(args->msgq.get(), msg);

    return nullptr;
}

void PLDM::requestSoftPowerOff()
{
    PLDM_INF(ENTER_MRK"requestSoftPowerOff");

    const sensor_id_t shutdown_sensor_id
        = UTIL::assertGetToplevelTarget()->getAttr<ATTR_PLDM_SENSOR_INFO>().sensor_id;

    // If we can find the shutdown sensor ID, then we start a task that will
    // send a completion notification to the BMC using that sensor ID.
    // If we cannot find the shutdown sensor ID, then we can't notify the BMC,
    // so create an error and shutdown with an error code.
    if (shutdown_sensor_id != 0)
    {
        const msg_q_t msgQ = MSG_Q_RESOLVE("PLDM::requestSoftPowerOff", VFS_ROOT_MSG_PLDM_REQ_OUT);

        const auto args = new shutdown_args
        {
            .msgq { msg_q_create(), msg_q_destroy },
            .pldm_msg_q = msgQ,
            .hb_terminus_id = thePdrManager().hostbootTerminusId(),
            .shutdown_sensor_id = shutdown_sensor_id
        };

        // Create a thread waiting for the "memory flush complete" message from
        // Initservice.
        task_create(wait_for_graceful_shutdown, args);

        // Tell the istep dispacher to stop executing isteps.
        INITSERVICE::stopIpl();

        // Register for the post memory flush callback. Initservice will send us
        // a message on this message queue, which the thread we created above is
        // listening on.
        INITSERVICE::registerShutdownEvent(PLDM_COMP_ID,
                                           args->msgq.get(),
                                           0, // Message ID, don't care what this value is
                                           INITSERVICE::POST_MEM_FLUSH_NOTIFY_LAST);

        // Memory barrier, ensure all stores complete before we start flushing out pages.
        lwsync();

        PLDM_INF("requestSoftPowerOff: Shutting down gracefully");

        // Initiate the shutdown processing in the background
        INITSERVICE::doShutdown(SHUTDOWN_STATUS_GOOD, true /* background shutdown */);
    }
    else
    {
        /*@
         * @errortype
         * @severity   ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_PLDM_SHUTDOWN
         * @reasoncode RC_NOT_READY
         * @devdesc    Requested a graceful shutdown before creating the shutdown sensor.
         * @custdesc   Internal firmware error
         */
        errlHndl_t errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                  MOD_PLDM_SHUTDOWN,
                                                  RC_NOT_READY,
                                                  0,
                                                  0,
                                                  ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        PLDM_ERR("requestSoftPowerOff: Cannot find PLDM sensor ID, shutting down with error 0x%08x",
                 errl->plid());

        auto plid = errl->plid();

        errlCommit(errl, PLDM_COMP_ID);

        // Tell the istep dispacher to stop executing isteps
        INITSERVICE::stopIpl();

        // Memory barrier, ensure all stores complete before we start flushing out pages.
        lwsync();

        // Initiate the shutdown processing in the background
        INITSERVICE::doShutdown(plid, true /* background shutdown */);
    }

    PLDM_INF(EXIT_MRK"requestSoftPowerOff");
}