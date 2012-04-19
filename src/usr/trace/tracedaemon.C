//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/trace/tracedaemon.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#include "tracedaemon.H"
#include <sys/task.h>
#include <targeting/common/commontargeting.H>
#include <vfs/vfs.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

namespace TRACE
{

TraceDaemon::TraceDaemon() :
    iv_pMaster(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
{
    iv_msgQ = msg_q_create();
    task_create(TraceDaemon::start, this);
}

TraceDaemon::~TraceDaemon()
{
        // Send message to shutdown daemon thread.
    msg_t* l_msg = msg_allocate();
    l_msg->type = DAEMON_SHUTDOWN;
    msg_sendrecv(iv_msgQ, l_msg);
    msg_free(l_msg);

        // Release message queue.
    msg_q_destroy(iv_msgQ);
}

void TraceDaemon::start(void* i_self)
{
    reinterpret_cast<TraceDaemon *>(i_self)->run();
};

void TraceDaemon::run()
{
    msg_t* l_msg = NULL;

    // Main daemon loop.
    while(1)
    {
        // Get message from client.
        l_msg = msg_wait(iv_msgQ);

        // Switch based on message type.
        switch(l_msg->type)
        {
            case UPDATE_SCRATCH_REG:
                updateScratchReg(l_msg->data[0]);
                break;

            case SEND_TRACE_BUFFER: // TODO.
                    // Delete buffer for now.
                free(l_msg->extra_data);
                break;

            case DAEMON_SHUTDOWN:
                    // Respond to message and exit.
                msg_respond(iv_msgQ, l_msg);
                task_end();
                break;
        };

        if (msg_is_async(l_msg))
        {
            // Delete async messages.
            msg_free(l_msg);
        }
        else
        {
            // Respond to sync messages.
            msg_respond(iv_msgQ, l_msg);
        }
    }

}

void TraceDaemon::updateScratchReg(uint64_t i_value)
{
    // Find master processor target.
    if (iv_pMaster == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        if (VFS::module_is_loaded("libtargeting.so") &&
            TARGETING::targetService().isInitialized())
        {
            TARGETING::targetService().masterProcChipTargetHandle(iv_pMaster);
        }
    }

    // Write scratch register to requested value.
    size_t l_size = sizeof(uint64_t);
    errlHndl_t l_errl = deviceWrite(iv_pMaster, &i_value, l_size,
                                    DEVICE_SCOM_ADDRESS(MB_SCRATCH_REGISTER_0));

    if (l_errl)
    {
        errlCommit(l_errl, HBTRACE_COMP_ID);
    }
}

};
