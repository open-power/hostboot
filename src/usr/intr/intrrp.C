/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/intr/intrrp.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
 * @file intrrp.C
 * @brief Interrupt Resource Provider
 */

#include "intrrp.H"
#include <trace/interface.H>
#include <errno.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include <util/singleton.H>
#include <intr/intr_reasoncodes.H>
#include <sys/mmio.h>
#include <sys/mm.h>
#include <sys/misc.h>
#include <kernel/console.H>
#include <kernel/ipc.H>
#include <sys/task.h>
#include <vmmconst.h>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <targeting/common/utilFilter.H>
#include <devicefw/userif.H>
#include <sys/time.h>
#include <sys/vfs.h>
#include <hwas/common/hwasCallout.H>
#include <fsi/fsiif.H>
#include <arch/ppc.H>
#include <arch/pirformat.H>
#include <config.h>

#define INTR_TRACE_NAME INTR_COMP_NAME

using namespace INTR;
using namespace TARGETING;


trace_desc_t * g_trac_intr = NULL;
TRAC_INIT(&g_trac_intr, INTR_TRACE_NAME, 16*KILOBYTE, TRACE::BUFFER_SLOW);

/**
 * setup _start and handle barrier
 */
TASK_ENTRY_MACRO( IntrRp::init );


void IntrRp::init( errlHndl_t   &io_errlHndl_t )
{
    errlHndl_t err = NULL;

    err = Singleton<IntrRp>::instance()._init();

    //  pass task error back to parent
    io_errlHndl_t = err ;
}

errlHndl_t IntrRp::_init()
{
    errlHndl_t l_err = NULL;

    // get the PIR
    // Which ever cpu core this is running on is the MASTER cpu
    // Make master thread 0
    uint32_t cpuid = task_getcpuid();
    iv_masterCpu = cpuid;
    iv_masterCpu.threadId = 0;

    TRACFCOMP(g_trac_intr,"IntrRp::_init() Master cpu group[%d], "
                          "chip[%d], core[%d], thread[%d]",
              iv_masterCpu.groupId, iv_masterCpu.chipId, iv_masterCpu.coreId,
              iv_masterCpu.threadId);

    // Do the initialization steps on the master proc chip
    // The other proc chips will be setup at a later point
    TARGETING::Target* procTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle( procTarget );

    // Set up the IPC message Data area
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != NULL);
    uint64_t hrmor_base =
        sys->getAttr<TARGETING::ATTR_HB_HRMOR_NODAL_BASE>();

    KernelIpc::ipc_data_area.pir = iv_masterCpu.word;
    KernelIpc::ipc_data_area.hrmor_base = hrmor_base;
    KernelIpc::ipc_data_area.msg_queue_id = IPC_DATA_AREA_CLEAR;

    do
    {
        //TODO RTC 150562 - updates for multi-chip. My understanding is
        // the setting of the BARs + Enables can be done at the point in the IPL
        // where Xscoms are enabled.
        // Set the Interrupt BAR Scom Registers
        l_err = setInterruptBARs(procTarget);

        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "IntrRp::_init() Error setting Interrupt BARs.");
            break;
        }

      //TODO RTC 134431
      #ifdef CONFIG_MPIPL_ENABLED
        uint8_t is_mpipl = 0;
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        if(sys &&
           sys->tryGetAttr<TARGETING::ATTR_IS_MPIPL_HB>(is_mpipl) &&
           is_mpipl)
        {
            TRACFCOMP(g_trac_intr,"Disable interupts for MPIPL");
            l_err = hw_disableIntrMpIpl();

            if(l_err)
            {
                errlCommit(l_err,INTR_COMP_ID);
                l_err = NULL;
            }
        }
      #endif

        TRACFCOMP(g_trac_intr, "IntrRp::_init() Masking Interrupts");
        //Mask off all interrupt sources - these will be enabled as SW entities
        // register for specific interrupts via the appropriate message queue
        l_err = maskAllInterruptSources();
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "IntrRp::_init() Error masking all interrupt sources.");
            break;
        }

        TRACFCOMP(g_trac_intr, "IntrRp::_init() Enabling PSIHB Interrupts");
        //Enable PSIHB Interrupts
        l_err = enableInterrupts();
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "IntrRp::_init() Error enabling Interrupts");
            break;
        }

        // Create the kernel msg queue for external interrupts
        iv_msgQ = msg_q_create();
        msg_intr_q_register(iv_msgQ,
             procTarget->getAttr<TARGETING::ATTR_XIVE_THREAD_MGMT1_BAR_ADDR>());

        // Create a task to handle the messages
        task_create(IntrRp::msg_handler, NULL);

        // Register event to be called on shutdown
        INITSERVICE::registerShutdownEvent(iv_msgQ,
                                           MSG_INTR_SHUTDOWN,
                                           INITSERVICE::INTR_PRIORITY);

        //The INTRP itself will monitor/handle PSU Interrupts
        //  so unmask those interrupts
        l_err = unmaskInterruptSource(LSI_PSU);

        //Set value for enabled threads
        uint64_t l_en_threads = get_enabled_threads();
        TRACFCOMP(g_trac_intr, "IntrRp::_init() Threads enabled:"
                                " %lx", l_en_threads);
    } while(0);

    return l_err;
}

void IntrRp::acknowledgeInterrupt()
{
    //A uint16 store from the Acknowledge Hypervisor Interrupt
    // offset in the Thread Management BAR space signals
    // the interrupt is acknowledged
    uint16_t * l_ack_int_ptr = (uint16_t *)iv_xiveTmBar1Address;
    l_ack_int_ptr += ACK_HYPERVISOR_INT_REG_OFFSET;

    uint16_t l_ackRead = *l_ack_int_ptr;
    TRACFCOMP(g_trac_intr, "IntrRp::acknowledgeInterrupt(), read result: %16x", l_ackRead);
}

errlHndl_t IntrRp::resetIntUnit()
{
    errlHndl_t l_err = NULL;
    uint64_t l_barValue = XIVE_RESET_POWERBUS_QUIESCE_ENABLE;
    uint64_t size = sizeof(l_barValue);
    uint32_t l_addr = XIVE_RESET_INT_CQ_RST_CTL_SCOM_ADDR;

    TARGETING::Target* procTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle( procTarget );

    do {
        //First quiesce the power bus
        TRACDCOMP(g_trac_intr, "IntrRp::resetIntUnit() - "
                           "Quiesce the PowerBus Interface");
        l_err = deviceWrite(procTarget,
                            &l_barValue,
                            size,
                            DEVICE_SCOM_ADDRESS(l_addr));

        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "IntrRp::resetIntUnit() - "
                                    "Error Quiescing the PowerBus");
            break;
        }

        //A short amount of time is needed to let the powerbus quiesce before
        // the next step in the reset can occur, so do a short polling loop
        // for the indicator the power bus has been quiesced
        uint64_t l_quiesceTimeout = XIVE_RESET_POWERBUS_QUIESCE_TIMEOUT;
        uint64_t l_timeWaited = 0;
        uint64_t reg = 0x0;

        do
        {
            if (l_timeWaited >= l_quiesceTimeout)
            {
                TRACFCOMP(g_trac_intr, "IntrRp::resetIntUnit() - Timeout "
                          "waiting for PowerBus to quiesce");
                /*@ errorlog tag
                 * @errortype       ERRL_SEV_UNRECOVERABLE
                 * @moduleid        INTR::MOD_INTRRP_RESETINTUNIT
        `        * @reasoncode      INTR::RC_XIVE_PBUS_QUIESCE_TIMEOUT
                 * @userdata1       XIVE Powerbus Scom Register Address
                 * @userdata2       XIVE Powerbus Scom Register Data
                 *
                 * @devdesc         Timeout waiting for Powerbus to Quiesce
                 */
                l_err = new ERRORLOG::ErrlEntry
                        (
                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,    // severity
                         INTR::MOD_INTRRP_RESETINTUNIT,       // moduleid
                         INTR::RC_XIVE_PBUS_QUIESCE_TIMEOUT,  // reason code
                         l_addr,
                         reg
                        );

                break;
            }

            uint64_t scom_len = sizeof(reg);

            //Read the powerbus state
            l_err = deviceRead( procTarget,
                                &reg,
                                scom_len,
                                DEVICE_SCOM_ADDRESS(l_addr));


            if (l_err)
            {
                //Logging below this loop
                break;
            }


            if (reg & POWERBUS_STATE_QUIESCE)
            {
                //Powerbus Quiesced
                break;
            }
            else
            {
                nanosleep(0,XIVE_RESET_POWERBUS_QUIESCE_TIMEOUT / 10);
                l_timeWaited += XIVE_RESET_POWERBUS_QUIESCE_TIMEOUT / 10;
            }
        } while(1);

        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error getting Powerbus state");
            break;
        }

        TRACDCOMP(g_trac_intr, "Reset XIVE INT unit");
        l_barValue = XIVE_RESET_UNIT_ENABLE;
        l_err = deviceWrite(procTarget,
                            &l_barValue,
                            size,
                            DEVICE_SCOM_ADDRESS(l_addr));

        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error resetting XIVE INT unit");
            break;
        }

    } while (0);

    if (l_err)
    {
        TRACFCOMP(g_trac_intr, "Error: Interrupt Engine not reset successfully");
    }

    return l_err;
}

errlHndl_t IntrRp::enableInterrupts()
{
    errlHndl_t err = NULL;
    PSIHB_SW_INTERFACES_t * l_psihb_ptr = iv_psiHbBaseAddr;

   do
    {
        //Set bit to route interrupts to CEC instead of FSP
        l_psihb_ptr->psihbcr =
                    (l_psihb_ptr->psihbcr | PSI_BRIDGE_ENABLE_CEC_INTERRUPT);

        //Set bit to enable PSIHB Interrupts
        l_psihb_ptr->icr =
                      (l_psihb_ptr->icr | PSI_BRIDGE_INTP_STATUS_CTL_ENABLE);

        //Set Physical Thread Enable register in the PC space
        uint64_t * l_ic_ptr = iv_xiveIcBarAddress;
        l_ic_ptr += XIVE_IC_BAR_INT_PC_MMIO_REG_OFFSET;

        XIVE_IC_THREAD_CONTEXT_t * l_xive_ic_ptr =
                reinterpret_cast<XIVE_IC_THREAD_CONTEXT_t *>(l_ic_ptr);
        l_xive_ic_ptr->phys_thread_enable0_set = XIVE_IC_THREAD0_ENABLE;

        //Set bit to configure LSI mode for HB cec interrupts
        XIVE_IVPE_THREAD_CONTEXT_t * this_ivpe_ptr =
          reinterpret_cast<XIVE_IVPE_THREAD_CONTEXT_t *> (iv_xiveTmBar1Address);
        this_ivpe_ptr->cams = XIVE_IVPE_QW3_LSI_ENABLE;

   } while (0);

    //TODO RTC 150260 - Determine if any error checking can be done above, if so
    //  create/return errorlogs. If not, change the funciton return type.
    return err;
}

errlHndl_t IntrRp::disableInterrupts()
{
    errlHndl_t err = NULL;

    // Disable the interrupt on master processor core, thread 0
    uint64_t baseAddr = iv_baseAddr + cpuOffsetAddr(iv_masterCpu);

    err = checkAddress(baseAddr);
    if(!err)
    {
        uint8_t * cppr = reinterpret_cast<uint8_t*>(baseAddr+CPPR_OFFSET);
        *cppr = 0;
    }

    return err;
}

/**
 * Helper function to start the messge handler
 */
void* IntrRp::msg_handler(void * unused)
{
    Singleton<IntrRp>::instance().msgHandler();
    return NULL;
}


void IntrRp::msgHandler()
{
    TRACDCOMP(g_trac_intr, ENTER_MRK"IntrRp::msgHandler()");

    while(1)
    {
        msg_t* msg = msg_wait(iv_msgQ); // wait for interrupt msg

        switch(msg->type)
        {
            //Both cases require the same functinality, EXTERN comes from
            //  the kernel. COALESCE comes from userspace as the final step of
            //  the EOI path involves a read, if that returns 1 it signifies a
            //  new interrupt is already pending. So the EOI path will send a
            //  new COALESCE message to trigger the handling.
            case MSG_INTR_COALESCE:
            case MSG_INTR_EXTERN:
                {
                    ext_intr_t type = NO_INTERRUPT;
                    uint32_t ackResponse =
                                        static_cast<uint32_t>(msg->data[0]>>32);
                    //Check if LSI-Based Interrupt
                    if ((ackResponse & LSI_INTERRUPT) == LSI_INTERRUPT)
                    {
                        TRACFCOMP(g_trac_intr, "IntrRp::msgHandler() "
                                                 "- LSI Interrupt Detected");
                        //Read LSI Interrupt Status register
                        PSIHB_SW_INTERFACES_t * l_psihb_ptr = iv_psiHbBaseAddr;
                        uint64_t lsiIntStatus = l_psihb_ptr->lsiintstatus;
                        TRACFCOMP(g_trac_intr, "IntrRp::msgHandler() "
                                         "lsiIntStatus 0x%016lx", lsiIntStatus);
                        LSIvalue_t l_intrType = static_cast<LSIvalue_t>
                             (__builtin_clzl(lsiIntStatus));
                        type = static_cast<ext_intr_t>(l_intrType);
                    }

                    // xirr was read by interrupt message handler.
                    // Passed in as upper word of data[0]
                    uint32_t xirr = static_cast<uint32_t>(msg->data[0]>>32);
                    // data[0] (lower word) has the PIR
                    uint64_t l_xirr_pir = msg->data[0];
                    uint64_t l_data0 = (l_xirr_pir & 0xFFFFFFFF);
                    PIR_t pir = static_cast<PIR_t>(l_data0);

                    TRACFCOMP(g_trac_intr,
                              "External Interrupt received. XIRR=%x, PIR=%x",
                              xirr,pir.word);
                    //An external interrupt comes from two paths
                    //  1) kernel space - synchronous - response needed
                    //  2) User space (coalesce interrupt) - asynchronous
                    //     - no response needed, just free message
                    if (msg_is_async(msg))
                    {
                        msg_free(msg);
                    }
                    else
                    {
                        // Acknowlege msg
                        msg->data[1] = 0;
                        msg_respond(iv_msgQ, msg);
                    }

                    //Search if anyone is subscribed to the given
                    // interrupt source
                    Registry_t::iterator r = iv_registry.find(type);

                    if(r != iv_registry.end() && type != INTERPROC_XISR)
                    {
                        msg_q_t msgQ = r->second.msgQ;

                        msg_t * rmsg = msg_allocate();
                        rmsg->type = r->second.msgType;
                        rmsg->data[0] = type;  // interrupt type
                        rmsg->data[1] = l_xirr_pir;
                        rmsg->extra_data = NULL;

                        int rc = msg_sendrecv_noblk(msgQ,rmsg, iv_msgQ);
                        if(rc)
                        {
                            TRACFCOMP(g_trac_intr,ERR_MRK
                                      "External Interrupt received type = %d, "
                                      "but could not send message to registered"
                                      " handler. Ignoring it. rc = %d",
                                      (uint32_t) type, rc);
                        }
                    }
                    else if (type == LSI_PSU)
                    {
                        TRACFCOMP(g_trac_intr, "PSU Interrupt Detected");
                        handlePsuInterrupt(type);
                    }
                    else  // no queue registered for this interrupt type
                    {
                        // Throw it away for now.
                        TRACFCOMP(g_trac_intr,ERR_MRK
                                  "External Interrupt received type = %d, but "
                                  "nothing registered to handle it. "
                                  "Ignoring it.",
                                  (uint32_t)type);
                    }
                }
                break;

            case MSG_INTR_CPU_WAKEUP:
                {
                    uint64_t l_xirr_pir = msg->data[0];
                    uint64_t l_data0 = (l_xirr_pir & 0xFFFFFFFF);
                    PIR_t l_pir = static_cast<PIR_t>(l_data0);
                    PIR_t l_core_pir = l_pir;
                    l_core_pir.threadId = 0;

                    if (iv_ipisPending.count(l_core_pir))
                    {
                        TRACFCOMP(g_trac_intr,INFO_MRK
                                  "IntrRp::msgHandler Doorbell wakeup received"
                                  " for %d", l_pir.word);

                        IPI_Info_t& ipiInfo = iv_ipisPending[l_core_pir];
                        ipiInfo.first &=
                           ~(0x8000000000000000 >> l_pir.threadId);

                        if (0 == ipiInfo.first)
                        {
                            msg_t* ipiMsg = ipiInfo.second;
                            iv_ipisPending.erase(l_core_pir);

                            ipiMsg->data[1] = 0;
                            msg_respond(iv_msgQ, ipiMsg);
                        }
                        else
                        {
                            TRACFCOMP(g_trac_intr,INFO_MRK
                                      "IPI still pending for %x",
                                      ipiInfo.first);
                        }

                    }
                }
                break;
/*TODO RTC 150861 -- I think a new IPC message type needs to be defined.
 *                   And the code below should be executed when this new message
 *                   type is received. The Kernel will send this message to
 *                   here (this intrrp code) during doorbell wakeup.

                    // Now handle any IPC messages
                    // If something is registered for IPIs
                    // and msg is ready, then handle
                    if(r != iv_registry.end() &&
                       (KernelIpc::ipc_data_area.msg_queue_id !=
                       IPC_DATA_AREA_CLEAR) &&
                        (KernelIpc::ipc_data_area.msg_queue_id !=
                         IPC_DATA_AREA_LOCKED))
                    {
                        msg_q_t msgQ = r->second.msgQ;

                        msg_t * rmsg = msg_allocate();
                        rmsg->type = r->second.msgType;
                        rmsg->data[0] = type;  // interrupt type
                        rmsg->data[1] = l_xirr_pir;
                        rmsg->extra_data = NULL;

                        int rc = msg_sendrecv_noblk(msgQ, rmsg, iv_msgQ);
                        if(rc)
                        {
                            TRACFCOMP(g_trac_intr,ERR_MRK
                                      "IPI Interrupt received, but could "
                                      "not send message to the registered "
                                      "handler. Ignoring it. rc = %d",
                                      rc);
                        }
                    }
**/
            case MSG_INTR_EOI:
                {
                    // Use standrard EOI (End of Interrupt) sequence
                    if(msg->data[0] != INTERPROC_XISR)
                    {
                        uint64_t intSource = msg->data[0];
                        sendEOI(intSource);
                    }
                    msg_free(msg);
                }
                break;

            case MSG_INTR_REGISTER_MSGQ:
                {

                    msg_q_t l_msgQ = reinterpret_cast<msg_q_t>(msg->data[0]);
                    uint64_t l_type = msg->data[1];
                    LSIvalue_t l_intr_type = static_cast<LSIvalue_t>
                      (l_type & LSI_SOURCE_MASK);

                    errlHndl_t err = registerInterruptXISR(l_msgQ, l_type >> 32,
                                                                   l_intr_type);
                    if (err)
                    {
                        TRACFCOMP(g_trac_intr,
                            "IntrRp::msgHandler MSG_INTR_REGISTER_MSGQ error "
                            "registering handler for interrupt type: %lx",
                            l_intr_type);
                    }
                    else
                    {
                        //Enable (aka unmask) Interrupts for the source being
                        // registered for
                        err = unmaskInterruptSource(l_intr_type);
                        if (err)
                        {
                            TRACFCOMP(g_trac_intr,
                              "IntrRp::msgHandler MSG_INTR_REGISTER_MSGQ error"
                                " unmasking interrupt type: %lx",
                                l_intr_type);
                        }
                    }

                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    msg_respond(iv_msgQ,msg);
                }
                break;
            case MSG_INTR_UNREGISTER_MSGQ:
                {
                    TRACFCOMP(g_trac_intr,
                           "INTR remove registration of interrupt type = 0x%lx",
                            msg->data[0]);
                    LSIvalue_t l_type = static_cast<LSIvalue_t>(msg->data[0]);
                    LSIvalue_t l_intr_type = static_cast<LSIvalue_t>
                      (l_type & LSI_SOURCE_MASK);

                    // Mask the interrupt source prior to unregistering
                    errlHndl_t err = maskInterruptSource(l_intr_type);
                    if(err)
                    {
                        TRACFCOMP(g_trac_intr,
                             "IntrRp::msgHandler MSG_INTR_UNREGISTER_MSGQ error"
                             " masking interrupt type: %lx",
                             l_intr_type);
                        errlCommit(err,INTR_COMP_ID);
                    }

                    // Unregister for this source and return rc in response
                    msg_q_t msgQ = unregisterInterruptXISR(l_type);
                    msg->data[1] = reinterpret_cast<uint64_t>(msgQ);
                    msg_respond(iv_msgQ, msg);
                }
                break;
            case MSG_INTR_ENABLE:
                {
                    errlHndl_t err = enableInterrupts();
                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    msg_respond(iv_msgQ,msg);
                }
                break;

            case MSG_INTR_DISABLE:
                {
                    errlHndl_t err = disableInterrupts();
                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    msg_respond(iv_msgQ,msg);
                }
                break;

            //  Called when a new cpu becomes active other than the master
            //  Expect a call for each new core
            case MSG_INTR_ADD_CPU:
                {
                    //Get the base PIR sent from the kernel
                    PIR_t pir = msg->data[1];
                    //No need to care about thread ID as that will be gathered
                    //  below
                    pir.threadId = 0;
                    //Push back base core PIR for later use
                    iv_cpuList.push_back(pir);

                    TRACFCOMP(g_trac_intr,"Add CPU group[%d], chip[%d],"
                              "core[%d], thread[%d]",
                              pir.groupId, pir.chipId, pir.coreId,
                              pir.threadId);

                    //Get threads to be enabled so they will be monitored
                    uint64_t en_threads = get_enabled_threads();
                    iv_ipisPending[pir] = IPI_Info_t(en_threads, msg);

                    //Create handleCpuTimeout task - this task will monitor
                    // for wakeup messages from each individual expected
                    // thread to be sent.
                    task_create(handleCpuTimeout,
                                reinterpret_cast<void*>(pir.word));
                    TRACFCOMP(g_trac_intr, "handleCpuTimeout task started"
                              " responding to kernel message");
                }
                break;
            case MSG_INTR_ADD_CPU_TIMEOUT:
                {
                    PIR_t pir = msg->data[0];
                    TRACDCOMP("IntrRp::msgHandler() CPU Timeout Message "
                              "received for: %x", pir.word);
                    size_t count = msg->data[1];

                    if(iv_ipisPending.count(pir))
                    {
                        if (count < CPU_WAKEUP_INTERVAL_COUNT)
                        {
                            TRACFCOMP(g_trac_intr,
                                      INFO_MRK "Cpu wakeup pending on %x",
                                      pir.word);

                            // Tell child thread to retry.
                            msg->data[1] = EAGAIN;
                        }
                        else // Timed out.
                        {
                            TRACFCOMP(g_trac_intr,
                                      ERR_MRK "Cpu wakeup timeout on %x",
                                      pir.word);

                            // Tell child thread to exit.
                            msg->data[1] = 0;

                            // Get saved thread info.
                            IPI_Info_t& ipiInfo = iv_ipisPending[pir];
                            msg_t* ipiMsg = ipiInfo.second;
                            iv_ipisPending.erase(pir);

                            // Respond to waiting thread with ETIME.
                            ipiMsg->data[1] = -ETIME;
                            msg_respond(iv_msgQ, ipiMsg);
                        }
                    }
                    else // Ended successfully.
                    {
                        TRACFCOMP(g_trac_intr,
                                  INFO_MRK "Cpu wakeup completed on %x",
                                  pir.word);
                        // Tell child thread to exit.
                        msg->data[1] = 0;
                    }

                    msg_respond(iv_msgQ, msg);
                }
                break;
            case MSG_INTR_SHUTDOWN:
                {
                    TRACFCOMP(g_trac_intr,"Shutdown event received");
                    shutDown(msg->data[0]);

                    msg_respond(iv_msgQ, msg);

                }
                break;
#ifdef CONFIG_MPIPL_ENABLED //TODO RTC 134431
            case MSG_INTR_ADD_HBNODE:  // node info for mpipl
                {
                    errlHndl_t err = addHbNodeToMpiplSyncArea(msg->data[0]);
                    if(err)
                    {
                        errlCommit(err,INTR_COMP_ID);
                    }
                    msg_free(msg); // async message
                }
                break;
#endif
            case MSG_INTR_DRAIN_QUEUE:
                {
                    //The purpose of this message is allow the
                    //intrp to drain its message queue of pending EOIs
                    //just respond
                    msg_respond(iv_msgQ,msg);
                }
                break;

            default:
                msg->data[1] = -EINVAL;
                msg_respond(iv_msgQ, msg);
        }
    }
}

errlHndl_t IntrRp::sendEOI(uint64_t& i_intSource)
{
    //Send an EOI to the Power bus using the PSIHB ESB Space
    //This is done with a read to the page specific to the interrupt source.
    //Each interrupt source gets one page
    uint64_t * l_psiHbPowerBusEoiAddr =
               iv_psiHbEsbBaseAddr + ((i_intSource)*PAGE_SIZE)/sizeof(uint64_t);
    errlHndl_t l_err = NULL;

    do {

        uint64_t eoiRead = *l_psiHbPowerBusEoiAddr;
        if (eoiRead != 0)
        {
            TRACFCOMP(g_trac_intr, ERR_MRK"IntrRp::sendEOI error sending EOI"
                               " to PSIHB ESB. EOI load returned: %x", eoiRead);
            /*@ errorlog tag
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        INTR::MOD_INTRRP_SENDEOI
             * @reasoncode      INTR::RC_PSIHB_ESB_EOI_FAIL
             * @userdata1       Value read from EOI load
             * @userdata2       Interrupt Source to issue EOI to
             * @devdesc         Unexpected RC from issuing PSIHB EOI store
             */
            l_err = new ERRORLOG::ErrlEntry
              (
               ERRORLOG::ERRL_SEV_UNRECOVERABLE,    // severity
               INTR::MOD_INTRRP_SENDEOI,            // moduleid
               INTR::RC_PSIHB_ESB_EOI_FAIL,         // reason code
               eoiRead,                             // read value
               i_intSource                          // interrupt source number
               );
            break;
        }

        TRACDCOMP(g_trac_intr, "IntrRp::sendEOI read response: %lx", eoiRead);

        //EOI Part 2 - LSI ESB Internal to the IVPE
        uint64_t * l_lsiEoi = iv_xiveIcBarAddress;
        l_lsiEoi += XIVE_IC_LSI_EOI_OFFSET;
        uint64_t l_intPending = *l_lsiEoi;

        //If an interrupt is pending, HB userspace will send a message to
        // trigger the handling of a 'new' interrupt. In this situation the
        // interrupt will not be triggered via the kernel.
        if (l_intPending == 1)
        {
            //First acknowledge the interrupt so it won't be re-presented
            acknowledgeInterrupt();

            uint64_t l_data0 = LSI_INTERRUPT << 32;
            if (iv_msgQ)
            {
                msg_t * int_msg = msg_allocate();
                int_msg->type = MSG_INTR_COALESCE;
                int_msg->data[0] = reinterpret_cast<uint64_t>(l_data0);
                int send_rc = msg_send(iv_msgQ, int_msg);
                if (send_rc != 0)
                {
                    TRACFCOMP(g_trac_intr, ERR_MRK"IntrRp::sendEOI error "
                            "sending coalesce message");
                    /*@ errorlog tag
                     * @errortype       ERRL_SEV_UNRECOVERABLE
                     * @moduleid        INTR::MOD_INTRRP_SENDEOI
                     * @reasoncode      INTR::RC_MESSAGE_SEND_ERROR
                     * @userdata1       RC from msg_send command
                     * @devdesc         Error encountered sending coalesce
                     *                  message to INTRP
                     */
                    l_err = new ERRORLOG::ErrlEntry
                        (
                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,  // severity
                         INTR::MOD_INTRRP_SENDEOI,          // moduleid
                         INTR::RC_MESSAGE_SEND_ERROR,       // reason code
                         send_rc,
                         0
                        );
                    break;
                }
            }
        }
    } while(0);

    return l_err;
}

errlHndl_t IntrRp::maskAllInterruptSources(void)
{
    errlHndl_t l_err = NULL;
    for (uint8_t i = 0; i < LSI_LAST_SOURCE; i++)
    {
        TRACDCOMP(g_trac_intr, "MaskInterruptSource: %d", i);
        l_err = maskInterruptSource(i);
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error Masking Interrupt source: %x", i);
            break;
        }
    }

    TRACDCOMP(g_trac_intr, EXIT_MRK"MaskAllInterruptSources");
    return l_err;
}

errlHndl_t IntrRp::maskInterruptSource(uint8_t l_intr_source)
{
    errlHndl_t l_err = NULL;
    uint64_t * l_psiHbEsbptr = iv_psiHbEsbBaseAddr;
    l_psiHbEsbptr +=
       (((l_intr_source*PAGE_SIZE)+PSI_BRIDGE_ESB_OFF_OFFSET)/sizeof(uint64_t));

    uint64_t l_maskRead = *l_psiHbEsbptr;
    TRACDCOMP(g_trac_intr, "Mask read result: %lx", l_maskRead);

/*
    TODO RTC 150260

    //Perform 2nd read to verify in OFF state
    l_maskRead = *l_psiHbEsbptr;
    TRACDCOMP(g_trac_intr, "Mask read result: %lx", l_maskRead);

    if (l_maskRead != ESB_STATE_OFF)
    {
        TRACFCOMP(g_trac_intr, "Error masking interrupt source: %x."
                              " ESB state is: %lx.",
                              l_intr_source, l_maskRead);

        l_err = new ERRORLOG::ErrlEntry
              (
               ERRORLOG::ERRL_SEV_INFORMATIONAL,  // severity
               INTR::MOD_INTRRP_MASKINTERRUPT,    // moduleid
               INTR::RC_XIVE_ESB_WRONG_STATE,     // reason code
               l_intr_source,
               l_maskRead
               );

    }
**/

    return l_err;
}

errlHndl_t IntrRp::unmaskInterruptSource(uint8_t l_intr_source)
{
    errlHndl_t l_err = NULL;
    uint64_t * l_psiHbEsbptr = iv_psiHbEsbBaseAddr;
    l_psiHbEsbptr +=
     (((l_intr_source*PAGE_SIZE)+PSI_BRIDGE_ESB_RESET_OFFSET)/sizeof(uint64_t));

    uint64_t l_unmaskRead = *l_psiHbEsbptr;
    TRACDCOMP(g_trac_intr, "Unmask read result: %lx", l_unmaskRead);

/* TODO RTC 150260

    //Read 2nd time to verify proper ESB state
    l_unmaskRead = *l_psiHbEsbptr;

    if (l_unmaskRead != ESB_STATE_RESET)
    {
        TRACFCOMP(g_trac_intr, "Error unmasking interrupt source: %x."
                              " ESB state is: %lx.",
                              l_intr_source, l_unmaskRead);

        l_err = new ERRORLOG::ErrlEntry
              (
               ERRORLOG::ERRL_SEV_INFORMATIONAL,  // severity
               INTR::MOD_INTRRP_UNMASKINTERRUPT,  // moduleid
               INTR::RC_XIVE_ESB_WRONG_STATE,     // reason code
               l_intr_source,
               l_unmaskRead
               );

    }
**/
    return l_err;
}

errlHndl_t IntrRp::setInterruptBARs(TARGETING::Target * i_target)
{
    errlHndl_t l_err = NULL;

    do {

        l_err = setPsiHbBAR(i_target);
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error setting PSIHB BAR");
            break;
        }

        l_err = setPsiHbEsbBAR(i_target, true);
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error setting PSIHB ESB BAR");
            break;
        }

        l_err = setXiveIcBAR(i_target);
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error setting XIVE IC BAR");
            break;
        }

        l_err = setXiveIvpeTmBAR1(i_target);
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error setting XIVE TM BAR1");
            break;
        }

    } while (0);

    return l_err;
}

errlHndl_t IntrRp::handlePsuInterrupt(ext_intr_t i_type)
{
    //TODO FIXME RTC 149698
    // Long term will leverage mask register to avoid
    // polling loop below
    errlHndl_t l_err = NULL;
    uint32_t l_addr = PSI_BRIDGE_PSU_DOORBELL_REG;
    size_t scom_len = sizeof(uint64_t);
    uint64_t reg = 0x0;
    uint64_t l_elapsed_time_ns = 0;
    TARGETING::Target* procTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle( procTarget );

    do
    {
        l_err = deviceRead(procTarget,
                           &reg,
                           scom_len,
                           DEVICE_SCOM_ADDRESS(l_addr));

        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error Reading PSU SCOM address: %lx",
                                   l_addr);
            break;
        }

        //If the PSU Host Doorbell bit is on, wait for the
        // PSU DD to handle
        if (reg & PSI_BRIDGE_PSU_HOST_DOORBELL)
        {
            TRACDCOMP(g_trac_intr, "Host/SBE Mailbox "
                                   "response. Wait for Polling to handle"
                                   " response");
            nanosleep(0,10000);
            l_elapsed_time_ns += 10000;
        }
        else
        {
            //Polling Complete
            break;
        }
        if (l_elapsed_time_ns > MAX_PSU_LONG_TIMEOUT_NS)
        {
            TRACFCOMP(g_trac_intr, "PSU Timeout hit");
            /*@ errorlog tag
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        INTR::MOD_INTRRP_HNDLPSUINTERRUPT
             * @reasoncode      INTR::RC_PSU_DOORBELL_TIMEOUT
             * @userdata1       Scom Address with interrupt condition
             * @userdata2       Register Value
             * @devdesc         PSU Doorbell Timeout hit waiting for doorbell
             *                  interrupt condition to be cleared
             */
            l_err = new ERRORLOG::ErrlEntry
              (
               ERRORLOG::ERRL_SEV_UNRECOVERABLE,    // severity
               INTR::MOD_INTRRP_HNDLPSUINTERRUPT,   // moduleid
               INTR::RC_PSU_DOORBELL_TIMEOUT,       // reason code
               l_addr,
               reg
               );
            break;
        }

    } while(1);

    do {

        if (l_err)
        {
            break;
        }

        //Clear the PSU Scom Reg Interrupt Status register
        uint64_t l_barValue = 0;
        uint64_t size = sizeof(l_barValue);
        l_err = deviceWrite(procTarget,
                            &l_barValue,
                            size,
                            DEVICE_SCOM_ADDRESS(l_addr));

        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error clearing scom - %x", l_addr);
            break;
        }

        //Issue standard EOI for the PSU Interupt
        uint64_t intSource = i_type;
        TRACFCOMP(g_trac_intr, "Sending PSU EOI");
        sendEOI(intSource);

    } while(0);

    return l_err;
}

errlHndl_t IntrRp::getNxIRSN(TARGETING::Target * i_target,
                             uint32_t& o_irsn, uint32_t& o_num)
{
    errlHndl_t err = NULL;

    size_t scom_len = sizeof(uint64_t);
    uint64_t reg = 0x0;

    do{
        err = deviceRead
          ( i_target,
            &reg,
            scom_len,
            DEVICE_SCOM_ADDRESS(NX_BUID_SCOM_ADDR));

        if(err)
        {
            break;
        }

        //only calc IRSN if downstream interrupts are enabled
        o_irsn = 0;
        if(reg &(1ull << (63-NX_BUID_ENABLE)))  //reg has NX_BUID_ENABLE set
        {
            uint32_t l_mask = ((static_cast<uint32_t>(reg >> NX_IRSN_MASK_SHIFT)
                                & NX_IRSN_MASK_MASK) | NX_IRSN_UPPER_MASK);

            o_irsn = ((static_cast<uint32_t>(reg >> NX_IRSN_COMP_SHIFT)
                       & IRSN_COMP_MASK) & l_mask);

            //To get the number of interrupts, we need to "count" the 0 bits
            //cheat by extending mask to FFF8 + mask, then invert and add 1
            o_num = (~((~IRSN_COMP_MASK) | l_mask)) +1;
        }
    }while(0);


    TRACFCOMP(g_trac_intr,"NX_ISRN: 0x%x, num: 0x%x",o_irsn, o_num);

    return err;
}

//----------------------------------------------------------------------------
errlHndl_t IntrRp::registerInterruptXISR(msg_q_t i_msgQ,
                                     uint32_t i_msg_type,
                                     ext_intr_t i_xisr)
{
    errlHndl_t err = NULL;
    Registry_t::iterator r = iv_registry.find(i_xisr);

    if(r == iv_registry.end())
    {
        TRACFCOMP(g_trac_intr,"INTR::register intr type 0x%x", i_xisr);
        iv_registry[i_xisr] = intr_response_t(i_msgQ,i_msg_type);
    }
    else
    {
        if(r->second.msgQ != i_msgQ)
        {
            /*@ errorlog tag
             * @errortype       ERRL_SEV_INFORMATIONAL
             * @moduleid        INTR::MOD_INTRRP_REGISTERINTERRUPT
             * @reasoncode      INTR::RC_ALREADY_REGISTERED
             * @userdata1       XISR
             * @userdata2       0
             *
             * @devdesc         Interrupt type already registered
             *
             */
            err = new ERRORLOG::ErrlEntry
              (
               ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
               INTR::MOD_INTRRP_REGISTERINTERRUPT,  // moduleid
               INTR::RC_ALREADY_REGISTERED,         // reason code
               i_xisr,
               0
               );
        }
    }
    return err;
}

msg_q_t IntrRp::unregisterInterruptXISR(ext_intr_t i_xisr)
{
    msg_q_t msgQ = NULL;

    Registry_t::iterator r = iv_registry.find(i_xisr);
    if(r != iv_registry.end())
    {
        TRACFCOMP(g_trac_intr,INFO_MRK "Removing interrupt listener: %lx",
                     i_xisr);
        msgQ = r->second.msgQ;
        iv_registry.erase(r);
    }

    return msgQ;
}

void IntrRp::sendIPI(const PIR_t i_pir) const
{
    uint64_t baseAddr = iv_baseAddr + cpuOffsetAddr(i_pir);
    volatile uint8_t * mfrr =
        reinterpret_cast<uint8_t*>(baseAddr + MFRR_OFFSET);

    eieio(); sync();
    MAGIC_INSTRUCTION(MAGIC_SIMICS_CORESTATESAVE);
    (*mfrr) = IPI_USR_PRIO;
}


errlHndl_t IntrRp::checkAddress(uint64_t i_addr)
{
    errlHndl_t err = NULL;

    if(i_addr < VMM_VADDR_DEVICE_SEGMENT_FIRST)
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        INTR::MOD_INTRRP_CHECKADDRESS
         * @reasoncode      INTR::RC_BAD_VIRTUAL_IO_ADDRESS
         * @userdata1       The bad virtual address
         * @userdata2       0
         *
         * @devdesc         The virtual address is not a valid IO address
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,
             INTR::MOD_INTRRP_CHECKADDRESS,
             INTR::RC_BAD_VIRTUAL_IO_ADDRESS,
             i_addr,
             0
            );
    }

    return err;
}

void IntrRp::shutDown(uint64_t i_status)
{
    msg_t * rmsg = msg_allocate();

    // Call everyone and say shutting down!
    for(Registry_t::iterator r = iv_registry.begin();
        r != iv_registry.end();
        ++r)
    {
        msg_q_t msgQ = r->second.msgQ;

        rmsg->type = r->second.msgType;
        rmsg->data[0] = SHUT_DOWN;
        rmsg->data[1] = i_status;
        rmsg->extra_data = NULL;

        int rc = msg_sendrecv(msgQ,rmsg);
        if(rc)
        {
            TRACFCOMP(g_trac_intr,ERR_MRK
                      "Could not send message to registered handler to Shut"
                      " down. Ignoring it.  rc = %d",
                      rc);
        }
    }

    msg_free(rmsg);

    //Reset PSIHB Interrupt Space
    TRACDCOMP(g_trac_intr, "Reset PSIHB Interrupt Space");
    PSIHB_SW_INTERFACES_t * this_psihb_ptr = iv_psiHbBaseAddr;
    this_psihb_ptr->icr = PSI_BRIDGE_INTP_STATUS_CTL_RESET;
    TRACDCOMP(g_trac_intr, "Reset PSIHB INTR Complete");

    //Reset XIVE Interrupt unit
    resetIntUnit();

    // Reset the IP hardware registers
    iv_cpuList.push_back(iv_masterCpu);

#ifdef CONFIG_ENABLE_P9_IPI
    size_t threads = cpu_thread_count();
    uint64_t en_threads = get_enabled_threads();

    for(CpuList_t::iterator pir_itr = iv_cpuList.begin();
        pir_itr != iv_cpuList.end();
        ++pir_itr)
    {
        PIR_t pir = *pir_itr;
        for(size_t thread = 0; thread < threads; ++thread)
        {
            // Skip threads that were never started
            if( !(en_threads & (0x8000000000000000>>thread)) )
            {
                TRACDCOMP(g_trac_intr,"IntrRp::shutDown: Skipping thread %d",thread);
                continue;
            }
            pir.threadId = thread;
            //wh_p9 disableInterruptPresenter(pir);
        }
    }
#endif
    TRACFCOMP(g_trac_intr,INFO_MRK"INTR is shutdown");
}

//----------------------------------------------------------------------------

#ifdef CONFIG_MPIPL_ENABLED

errlHndl_t IntrRp::hw_disableRouting(TARGETING::Target * i_proc,
                                     INTR_ROUTING_t i_rx_tx)
{
    errlHndl_t err = NULL;
    do
    {
        size_t scom_len = sizeof(uint64_t);

        // PSI
        PSIHB_ISRN_REG_t reg;

        err = deviceRead
          (
           i_proc,
           &reg,
           scom_len,
           DEVICE_SCOM_ADDRESS(PSIHB_ISRN_REG_t::PSIHB_STATUS_CTL_REG)

           );

        if(err)
        {
            break;
        }

        switch(i_rx_tx)
        {
        case INTR_UPSTREAM:
            reg.uie = 0;   //upstream interrupt enable = 0 (disable)
            break;

        case INTR_DOWNSTREAM:
            reg.die = 0;  //downstream interrupt enable = 0 (disable)
            break;
        }

        scom_len = sizeof(uint64_t);
        err = deviceWrite
          (
           i_proc,
           &reg,
           scom_len,
           DEVICE_SCOM_ADDRESS(PSIHB_ISRN_REG_t::PSIHB_STATUS_CTL_REG)
           );

        if(err)
        {
            break;
        }

        for(size_t i = 0;
            i < sizeof(cv_PE_BAR_SCOM_LIST)/sizeof(cv_PE_BAR_SCOM_LIST[0]);
            ++i)
        {
            uint64_t reg = 0;
            scom_len = sizeof(uint64_t);
            err = deviceRead
                (
                 i_proc,
                 &reg,
                 scom_len,
                 DEVICE_SCOM_ADDRESS(cv_PE_BAR_SCOM_LIST[i])
                );

            if(err)
            {
                break;
            }

            switch(i_rx_tx)
            {
                case INTR_UPSTREAM:
                    // reset bit PE_IRSN_UPSTREAM
                    reg &= ~((1ull << (63-PE_IRSN_UPSTREAM)));
                    break;

                case INTR_DOWNSTREAM:
                    // reset bit PE_IRSN_DOWNSTREAM
                    reg &= ~((1ull << (63-PE_IRSN_DOWNSTREAM)));
                    break;
            }

            scom_len = sizeof(uint64_t);
            err = deviceWrite
                (
                 i_proc,
                 &reg,
                 scom_len,
                 DEVICE_SCOM_ADDRESS(cv_PE_BAR_SCOM_LIST[i])
                );

            if(err)
            {
                break;
            }
        }
        if(err)
        {
            break;
        }

        //NX has no up/down stream enable bit - just one enable bit.
        //The NX should be cleared as part of an MPIPL so no
        //interrupts should be pending from this unit, however
        //we must allow EOIs to flow, so only disable when
        //downstream is requested
        if(i_rx_tx == INTR_DOWNSTREAM)
        {
            uint64_t reg = 0;
            scom_len = sizeof(uint64_t);
            err = deviceRead
                (
                 i_proc,
                 &reg,
                 scom_len,
                 DEVICE_SCOM_ADDRESS(NX_BUID_SCOM_ADDR)
                );
            if(err)
            {
                break;
            }

            // reset bit NX_BUID_ENABLE
            reg &= ~(1ull << (63-NX_BUID_ENABLE));

            scom_len = sizeof(uint64_t);
            err = deviceWrite
                (
                 i_proc,
                 &reg,
                 scom_len,
                 DEVICE_SCOM_ADDRESS(NX_BUID_SCOM_ADDR)
                );
            if(err)
            {
                break;
            }
        }

    } while(0);
    return err;
}
#endif

//----------------------------------------------------------------------------

#ifdef CONFIG_MPIPL_ENABLED
errlHndl_t IntrRp::hw_resetIRSNregs(TARGETING::Target * i_proc)
{
    errlHndl_t err = NULL;
    size_t scom_len = sizeof(uint64_t);
    do
    {
        // PSI
        PSIHB_ISRN_REG_t reg1; // zeros self
        reg1.irsn -= 1;  // default all '1's according to scom spec
        // all other fields = 0

        err = deviceWrite
          (
           i_proc,
           &reg1,
           scom_len,
           DEVICE_SCOM_ADDRESS(PSIHB_ISRN_REG_t::PSIHB_ISRN_REG)
           );
        if(err)
        {
            break;
        }

        // PE
        for(size_t i = 0;
            i < sizeof(cv_PE_BAR_SCOM_LIST)/sizeof(cv_PE_BAR_SCOM_LIST[0]);
            ++i)
        {
            uint64_t reg = 0;
            scom_len = sizeof(uint64_t);
            // Note: no default value specified in scom spec - assume 0
            err = deviceWrite
                (
                 i_proc,
                 &reg,
                 scom_len,
                 DEVICE_SCOM_ADDRESS(cv_PE_IRSN_COMP_SCOM_LIST[i])
                );
            if(err)
            {
                break;
            }

            scom_len = sizeof(uint64_t);
            // Note: no default value specified in scom spec - assume 0
            err = deviceWrite
                (
                 i_proc,
                 &reg,
                 scom_len,
                 DEVICE_SCOM_ADDRESS(cv_PE_IRSN_MASK_SCOM_LIST[i])
                );
            if(err)
            {
                break;
            }
        }
        if(err)
        {
            break;
        }

        // NX [1:19] is BUID [20:32] mask
        // No default value specified in scom spec. assume 0
        uint64_t reg = 0;
        scom_len = sizeof(uint64_t);
        err = deviceWrite
            (
             i_proc,
             &reg,
             scom_len,
             DEVICE_SCOM_ADDRESS(NX_BUID_SCOM_ADDR)
            );
        if(err)
        {
            break;
        }
    } while(0);
    return err;
}
#endif

//----------------------------------------------------------------------------
#ifdef CONFIG_MPIPL_ENABLED
errlHndl_t IntrRp::blindIssueEOIs(TARGETING::Target * i_proc)
{
    errlHndl_t err = NULL;

    TARGETING::TargetHandleList procCores;
    getChildChiplets(procCores, i_proc, TYPE_CORE, false); //state can change

    do
    {
        //Issue eio to IPIs first
        for(TARGETING::TargetHandleList::iterator
            core = procCores.begin();
            core != procCores.end();
            ++core)
        {
            FABRIC_CHIP_ID_ATTR chip = i_proc->getAttr<ATTR_FABRIC_CHIP_ID>();
            FABRIC_NODE_ID_ATTR node = i_proc->getAttr<ATTR_FABRIC_NODE_ID>();
            CHIP_UNIT_ATTR coreId =
                                (*core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            PIR_t pir(0);
            pir.groupId = node;
            pir.chipId = chip;
            pir.coreId = coreId;

            size_t threads = cpu_thread_count();
            for(size_t thread = 0; thread < threads; ++thread)
            {
                pir.threadId = thread;
                uint64_t xirrAddr = iv_baseAddr +
                  cpuOffsetAddr(pir);
                 uint32_t * xirrPtr =
                  reinterpret_cast<uint32_t*>(xirrAddr + XIRR_OFFSET);
                uint8_t * mfrrPtr = reinterpret_cast<uint8_t*>(
                                                 xirrAddr + MFRR_OFFSET);

                //need to set mfrr to 0xFF first
                TRACDCOMP(g_trac_intr,"Clearing IPI to xirrPtr[%p]", xirrPtr);
                *mfrrPtr = 0xFF;
                *xirrPtr = 0xFF000002;
            }
        }

        PIR_t pir(iv_masterCpu);
        pir.threadId = 0;
        //Can just write all EOIs to master core thread 0 XIRR
        uint64_t xirrAddr = iv_baseAddr + cpuOffsetAddr(pir);
        volatile uint32_t * xirrPtr =
                   reinterpret_cast<uint32_t*>(xirrAddr +XIRR_OFFSET);


        //Issue eio to PSI logic
        uint32_t l_psiBaseIsn;
        uint32_t l_maxInt = 0;
        err = getPsiIRSN(i_proc, l_psiBaseIsn, l_maxInt);
        if(err)
        {
            break;
        }

        //Only issue if ISN is non zero (ie set)
        if(l_psiBaseIsn)
        {
            l_psiBaseIsn |= 0xFF000000;
            uint32_t l_psiMaxIsn = l_psiBaseIsn + l_maxInt;

            TRACFCOMP(g_trac_intr,"Issuing EOI to PSIHB range %x - %x",
                      l_psiBaseIsn, l_psiMaxIsn);

            for(uint32_t l_isn = l_psiBaseIsn; l_isn < l_psiMaxIsn; ++l_isn)
            {
                TRACDCOMP(g_trac_intr,"   xirrPtr[%p] xirr[%x]\n", xirrPtr, l_isn);
                *xirrPtr = l_isn;
            }
        }

        //Don't need to issue EOIs to PHBs
        //since PHB ETU reset cleans them up

        //Issue eio to NX logic
        uint32_t l_nxBaseIsn;
        err = getNxIRSN(i_proc, l_nxBaseIsn, l_maxInt);
        if(err)
        {
            break;
        }

        //Only issue if ISN is non zero (ie set)
        if(l_nxBaseIsn)
        {
            l_nxBaseIsn |= 0xFF000000;
            uint32_t l_nxMaxIsn = l_nxBaseIsn + l_maxInt;
            TRACFCOMP(g_trac_intr,"Issuing EOI to NX range %x - %x",
                      l_nxBaseIsn, l_nxMaxIsn);

            for(uint32_t l_isn = l_nxBaseIsn; l_isn < l_nxMaxIsn; ++l_isn)
            {
                *xirrPtr = l_isn;
            }
        }
    } while(0);
    return err;
}
#endif

//----------------------------------------------------------------------------

errlHndl_t IntrRp::findProcs_Cores(TARGETING::TargetHandleList & o_procs,
                                   TARGETING::TargetHandleList& o_cores)
{
    errlHndl_t err = NULL;

    do
    {
        //Build a list of "functional" processors.  This needs to be
        //done without targeting support (just blueprint) since
        //on MPIPL the targeting information is obtained in
        //discover_targets -- much later in the IPL.

        //Since this is MPIPL we will rely on two things:
        // 1) FSI will be active to present chips
        // 2) The MPIPL HW bit in CFAM 2839 will be set

        //force FSI to init so we can rely on slave data
        err = FSI::initializeHardware();
        if(err)
        {
            break;
        }

        TARGETING::TargetHandleList procChips;
        TARGETING::PredicateCTM predProc( TARGETING::CLASS_CHIP,
                                          TARGETING::TYPE_PROC );

        TARGETING::TargetService& tS = TARGETING::targetService();
        TARGETING::Target * sysTarget = NULL;
        tS.getTopLevelTarget( sysTarget );
        assert( sysTarget != NULL );

        TARGETING::Target* masterProcTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(
                                                        masterProcTarget );

        tS.getAssociated( procChips,
                          sysTarget,
                          TARGETING::TargetService::CHILD,
                          TARGETING::TargetService::ALL,
                          &predProc );

        for(TARGETING::TargetHandleList::iterator proc = procChips.begin();
            proc != procChips.end();
            ++proc)
        {
            //if master proc -- just add it as we are running on it
            if (*proc == masterProcTarget)
            {
                o_procs.push_back(*proc);
                continue;
            }

            //First see if present
            if(FSI::isSlavePresent(*proc))
            {
                TRACFCOMP(g_trac_intr,"Proc %x detected via FSI", TARGETING::get_huid(*proc));

                //Second check to see if MPIPL bit is on cfam "2839" which
                //Note 2839 is ecmd addressing, real address is 0x28E4 (byte)
                uint64_t l_addr = 0x28E4;
                uint32_t l_data = 0;
                size_t l_size = sizeof(uint32_t);
                err = deviceRead(*proc,
                                   &l_data,
                                   l_size,
                                   DEVICE_FSI_ADDRESS(l_addr));
                if (err)
                {
                    TRACFCOMP(g_trac_intr,"Failed to read CFAM 2839 on %x",
                              TARGETING::get_huid(*proc));
                    break;
                }

                TRACFCOMP(g_trac_intr,"Proc %x 2839 val [%x]", TARGETING::get_huid(*proc),
                          l_data);

                if(l_data & 0x80000000)
                {
                    //Chip is present and functional -- add it to our list
                    o_procs.push_back(*proc);

                    //Also need to force it to use Xscom
                    //Note that it has to support (ie it is part of the SMP)
                    ScomSwitches l_switches =
                                     (*proc)->getAttr<ATTR_SCOM_SWITCHES>();

                    l_switches.useSbeScom = 0;
                    l_switches.useFsiScom = 0;
                    l_switches.useXscom = 1;

                    (*proc)->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
                }
            }
        }
        if (err)
        {
            break;
        }


        //Build up a list of all possible cores (don't care if func/present,
        //just that they exist in the blueprint
        TARGETING::TargetHandleList l_cores;
        for(TARGETING::TargetHandleList::iterator proc = o_procs.begin();
            proc != o_procs.end();
            ++proc)
        {
            l_cores.clear();
            getChildChiplets(l_cores, *proc, TYPE_CORE, false);
            for(TARGETING::TargetHandleList::iterator core = l_cores.begin();
                core != l_cores.end();
                ++core)
            {
                o_cores.push_back(*core);
            }
        }
    }while(0);

    return err;
}

void IntrRp::allowAllInterrupts(TARGETING::Target* i_core)
{
    const TARGETING::Target * proc = getParentChip(i_core);

    FABRIC_CHIP_ID_ATTR chip = proc->getAttr<ATTR_FABRIC_CHIP_ID>();
    FABRIC_NODE_ID_ATTR node = proc->getAttr<ATTR_FABRIC_NODE_ID>();
    CHIP_UNIT_ATTR coreId = i_core->getAttr<TARGETING::ATTR_CHIP_UNIT>();

    PIR_t pir(0);
    pir.groupId = node;
    pir.chipId = chip;
    pir.coreId = coreId;

    size_t threads = cpu_thread_count();
    for(size_t thread = 0; thread < threads; ++thread)
    {
        pir.threadId = thread;
        uint64_t cpprAddr=cpuOffsetAddr(pir)+iv_baseAddr+CPPR_OFFSET;
        uint8_t *cppr = reinterpret_cast<uint8_t*>(cpprAddr);
        *cppr = 0xff; // allow all interrupts
    }

}

void IntrRp::disableAllInterrupts(TARGETING::Target* i_core)
{
    const TARGETING::Target * proc = getParentChip(i_core);

    FABRIC_CHIP_ID_ATTR  chip = proc->getAttr<ATTR_FABRIC_CHIP_ID>();
    FABRIC_NODE_ID_ATTR node = proc->getAttr<ATTR_FABRIC_NODE_ID>();
    CHIP_UNIT_ATTR coreId = i_core->getAttr<TARGETING::ATTR_CHIP_UNIT>();

    PIR_t pir(0);
    pir.groupId = node;
    pir.chipId = chip;
    pir.coreId = coreId;

    size_t threads = cpu_thread_count();
    for(size_t thread = 0; thread < threads; ++thread)
    {
        pir.threadId = thread;
        //wh_p9 disableInterruptPresenter(pir);
    }
}

void IntrRp::drainMpIplInterrupts(TARGETING::TargetHandleList & i_cores)
{
    TRACFCOMP(g_trac_intr,"Drain pending interrupts");
    bool interrupt_found = false;
    size_t retryCount = 10;

    do
    {
        interrupt_found = false;
        nanosleep(0,1000000);   // 1 ms

        for(TARGETING::TargetHandleList::iterator
            core = i_cores.begin();
            core != i_cores.end();
            ++core)
        {
            const TARGETING::Target * proc = getParentChip(*core);

            FABRIC_CHIP_ID_ATTR chip = proc->getAttr<ATTR_FABRIC_CHIP_ID>();
            FABRIC_NODE_ID_ATTR node = proc->getAttr<ATTR_FABRIC_NODE_ID>();
            CHIP_UNIT_ATTR coreId =
                              (*core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            PIR_t pir(0);
            pir.groupId = node;
            pir.chipId = chip;
            pir.coreId = coreId;

            TRACFCOMP(g_trac_intr,"  n%d p%d c%d", node, chip, coreId);
            size_t threads = cpu_thread_count();
            for(size_t thread = 0; thread < threads; ++thread)
            {
                pir.threadId = thread;
                uint64_t xirrAddr = iv_baseAddr +
                  cpuOffsetAddr(pir) + XIRR_RO_OFFSET;
                volatile uint32_t * xirrPtr =
                  reinterpret_cast<uint32_t*>(xirrAddr);
                uint32_t xirr = *xirrPtr & 0x00FFFFFF;
                TRACDCOMP(g_trac_intr,"   xirrPtr[%p] xirr[%x]\n", xirrPtr, xirr);
                if(xirr)
                {
                    // Found pending interrupt!
                    interrupt_found = true;

                    TRACFCOMP(g_trac_intr,
                              ERR_MRK
                              "Pending interrupt found on MPIPL."
                              " CpuId:0x%x XIRR:0x%x",
                              pir.word,
                              xirr);
                    uint8_t * mfrrPtr =
                      reinterpret_cast<uint8_t*>(xirrAddr + MFRR_OFFSET);
                    // Signal EOI - read then write xirr value
                    ++xirrPtr;        // move to RW XIRR reg
                    volatile uint32_t xirr_rw = *xirrPtr;

                    //If IPI need to set mfrr to 0xFF
                    if(INTERPROC_XISR == xirr)
                    {
                        *mfrrPtr = 0xFF;
                    }

                    *xirrPtr = xirr_rw;
                    --xirrPtr;      // back to RO XIRR reg
                }
            }
        }
    } while(interrupt_found == true && --retryCount != 0);

    if(interrupt_found && (retryCount == 0))
    {
        // traces above should identify stuck interrupt
        INITSERVICE::doShutdown(INTR::RC_PERSISTENT_INTERRUPTS);
    }
}


#ifdef CONFIG_MPIPL_ENABLED
errlHndl_t IntrRp::hw_disableIntrMpIpl()
{
    errlHndl_t err = NULL;
    TARGETING::TargetHandleList funcProc, procCores;

    //Need to clear out all pending interrupts.  This includes
    //ones that PHYP already accepted and ones "hot" in the XIRR
    //register.   Must be done for all processors prior to opening
    //up traffic for mailbox (since we switch the IRSN).  PHYP
    //can route PSI interrupts to any chip in the system so all
    //must be cleaned up prior to switching

    do
    {
        //extract the node layout for later
        err = extractHbNodeInfo();
        if(err)
        {
            break;
        }

        //Get the procs/cores
        err = findProcs_Cores(funcProc, procCores);
        if(err)
        {
            break;
        }

        //since HB will need to use PSI interrupt block, we need to
        //perform the extra step of disabling FSP PSI interrupts at
        //source(theoretically upstream disable should have handled,
        //but it seesms to slip through somehow and doesn't get fully
        //cleaned up cause we clear the XIVR
        for(TARGETING::TargetHandleList::iterator proc = funcProc.begin();
            (proc != funcProc.end()) && !err;
            ++proc)
        {
            uint64_t reg = PSI_FSP_INT_ENABLE;
            size_t scom_len = sizeof(uint64_t);
            err = deviceWrite
              (
               (*proc),
               &reg,
               scom_len,
               DEVICE_SCOM_ADDRESS(PSI_HBCR_AND_SCOM_ADDR)
               );
        }
        if(err)
        {
            break;
        }

        // Disable upstream intr routing on all processor chips
        TRACFCOMP(g_trac_intr,"Disable upstream interrupt");
        for(TARGETING::TargetHandleList::iterator proc = funcProc.begin();
            (proc != funcProc.end()) && !err;
            ++proc)
        {
            // disable upstream intr routing
            err = hw_disableRouting(*proc,INTR_UPSTREAM);
        }
        if(err)
        {
            break;
        }

        err = syncNodes(INTR_MPIPL_UPSTREAM_DISABLED);
        if ( err )
        {
            break;
        }

        // Set interrupt presenter to allow all interrupts
        TRACFCOMP(g_trac_intr,"Allow interrupts");
        for(TARGETING::TargetHandleList::iterator
            core = procCores.begin();
            core != procCores.end();
            ++core)
        {
            allowAllInterrupts(*core);
        }

        // Now look for interrupts
        drainMpIplInterrupts(procCores);

        // Issue blind EOIs to all threads IPIs and  to clean up stale XIRR
        TRACFCOMP(g_trac_intr,"Issue blind EOIs to all ISRN and IPIs");
        for(TARGETING::TargetHandleList::iterator proc = funcProc.begin();
            (proc != funcProc.end()) && !err;
            ++proc)
        {
            err = blindIssueEOIs(*proc);
        }
        if(err)
        {
            break;
        }

        err = syncNodes(INTR_MPIPL_DRAINED);
        if( err )
        {
            break;
        }

        // Disable all interrupt presenters
        for(TARGETING::TargetHandleList::iterator core = procCores.begin();
            core != procCores.end();
            ++core)
        {
            disableAllInterrupts(*core);
        }

        // disable downstream routing and clean up IRSN regs
        for(TARGETING::TargetHandleList::iterator proc = funcProc.begin();
            proc != funcProc.end();
            ++proc)
        {
            // disable downstream routing
            err = hw_disableRouting(*proc,INTR_DOWNSTREAM);
            if(err)
            {
                break;
            }

            // reset IRSN values
            err = hw_resetIRSNregs(*proc);
            if(err)
            {
                break;
            }

            //Now mask off all XIVRs under the PSI unit
            //This prevents hot PSI mbox interrupts from flowing up to HB
            //and allows PHYP to deal with them
            err = maskXIVR(*proc);
            if(err)
            {
                break;
            }
        }
        if(err)
        {
            break;
        }
    } while(0);
    return err;
}
#endif

errlHndl_t syncNodesError(void * i_p, uint64_t i_len)
{
    TRACFCOMP(g_trac_intr,"Failure calling mm_block_map: phys_addr=%p",
              i_p);
    /*@
     * @errortype    ERRL_SEV_UNRECOVERABLE
     * @moduleid     INTR::MOD_INTR_SYNC_NODES
     * @reasoncode   INTR::RC_CANNOT_MAP_MEMORY
     * @userdata1    physical address
     * @userdata2    Block size requested
     * @devdesc      Error mapping in memory
     */
    return new ERRORLOG::ErrlEntry
        (
         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
         INTR::MOD_INTR_SYNC_NODES,
         INTR::RC_CANNOT_MAP_MEMORY,
         reinterpret_cast<uint64_t>(i_p),
         i_len,
         true /*Add HB Software Callout*/);
}

errlHndl_t IntrRp::syncNodes(intr_mpipl_sync_t i_sync_type)
{
    errlHndl_t err = NULL;
    bool reported[MAX_NODES_PER_SYS] = { false,};

    uint64_t hrmorBase = KernelIpc::ipc_data_area.hrmor_base;

    void * node_info_ptr =
        reinterpret_cast<void *>((iv_masterCpu.groupId * hrmorBase) +
                                 VMM_INTERNODE_PRESERVED_MEMORY_ADDR);

    internode_info_t * this_node_info =
        reinterpret_cast<internode_info_t *>
        (mm_block_map(node_info_ptr,INTERNODE_INFO_SIZE));

    do
    {

        if(this_node_info == NULL)
        {
            err = syncNodesError(this_node_info, INTERNODE_INFO_SIZE);
            break;
        }


        if(this_node_info->eye_catcher != NODE_INFO_EYE_CATCHER)
        {
            TRACFCOMP(g_trac_intr, INFO_MRK
                      "MPIPL, but INTR node data sync area unintialized."
                      " Assuming single HB Intance system");

            break;
        }

        // Map the internode data areas to a virtual address
        internode_info_t * vaddr[MAX_NODES_PER_SYS];

        for(uint64_t node = 0; node < MAX_NODES_PER_SYS; ++node)
        {
            if (node == iv_masterCpu.groupId)
            {
                vaddr[node] = this_node_info;
            }
            else if(this_node_info->exist[node])
            {
                node_info_ptr =
                    reinterpret_cast<void *>
                    ((node*hrmorBase)+VMM_INTERNODE_PRESERVED_MEMORY_ADDR);

                internode_info_t * node_info =
                    reinterpret_cast<internode_info_t *>
                    (mm_block_map(node_info_ptr,
                                  INTERNODE_INFO_SIZE));

                if(node_info == NULL)
                {
                    err = syncNodesError(node_info_ptr,
                                         INTERNODE_INFO_SIZE);
                    break;
                }
                vaddr[node] = node_info;
                reported[node] = false;
            }
        }
        if (err)
        {
            break;
        }


        // This node has hit the sync point
        this_node_info->mpipl_intr_sync = i_sync_type;
        lwsync();

        bool synched = false;
        // Loop until all nodes have reached the sync point
        while(synched == false)
        {
            synched = true;

            for(uint64_t node = 0; node < MAX_NODES_PER_SYS; ++node)
            {
                if(this_node_info->exist[node])
                {
                    intr_mpipl_sync_t sync_type =
                        vaddr[node]->mpipl_intr_sync;
                    if(sync_type < i_sync_type)
                    {
                        synched = false;
                        // Insure simics does a context switch
                        setThreadPriorityLow();
                        setThreadPriorityHigh();
                    }
                    else if(reported[node] == false)
                    {
                        reported[node] = true;
                        TRACFCOMP( g_trac_intr, INFO_MRK
                                   "MPIPL node %ld reached syncpoint %d",
                                   node, (uint32_t)i_sync_type);
                    }
                }
            }
        }
        isync();

        for(uint64_t node = 0; node < MAX_NODES_PER_SYS; ++node)
        {
            if(this_node_info->exist[node])
            {
                // We are still using this_node_info area
                // so unmap it later.
                if(node != iv_masterCpu.groupId)
                {
                    mm_block_unmap(vaddr[node]);
                }
            }
        }

        mm_block_unmap(this_node_info);

    } while(0);

    return err;
}

#ifdef CONFIG_MPIPL_ENABLED
errlHndl_t  IntrRp::initializeMpiplSyncArea()
{
    errlHndl_t err = NULL;
    uint64_t hrmorBase = KernelIpc::ipc_data_area.hrmor_base;
    void * node_info_ptr =
        reinterpret_cast<void *>((iv_masterCpu.groupId * hrmorBase) +
                                 VMM_INTERNODE_PRESERVED_MEMORY_ADDR);

    internode_info_t * this_node_info =
        reinterpret_cast<internode_info_t *>
        (mm_block_map(node_info_ptr,INTERNODE_INFO_SIZE));

    if(this_node_info)
    {
        TRACFCOMP( g_trac_intr,
                   "MPIPL SYNC at phys %p virt %p value %lx\n",
                   node_info_ptr, this_node_info, NODE_INFO_EYE_CATCHER );


        this_node_info->eye_catcher = NODE_INFO_EYE_CATCHER;
        this_node_info->version = NODE_INFO_VERSION;
        this_node_info->mpipl_intr_sync = INTR_MPIPL_SYNC_CLEAR;
        for(uint64_t node = 0; node < MAX_NODES_PER_SYS; ++node)
        {
            if(iv_masterCpu.groupId == node)
            {
                this_node_info->exist[node] = true;
            }
            else
            {
                this_node_info->exist[node] = false;
            }
        }

        mm_block_unmap(this_node_info);
    }
    else
    {
        TRACFCOMP( g_trac_intr, "Failure calling mm_block_map : phys_addr=%p",
                   node_info_ptr);
        /*@
         * @errortype    ERRL_SEV_UNRECOVERABLE
         * @moduleid     INTR::MOD_INTR_INIT_MPIPLAREA
         * @reasoncode   INTR::RC_CANNOT_MAP_MEMORY
         * @userdata1    physical address
         * @userdata2    Size
         * @devdesc      Error mapping in memory
         */
        err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      INTR::MOD_INTR_INIT_MPIPLAREA,
                                      INTR::RC_CANNOT_MAP_MEMORY,
                                      reinterpret_cast<uint64_t>(node_info_ptr),
                                      INTERNODE_INFO_SIZE,
                                      true /*Add HB Software Callout*/);

    }
    return err;
}
#endif

#ifdef CONFIG_MPIPL_ENABLED
errlHndl_t  IntrRp::addHbNodeToMpiplSyncArea(uint64_t i_hbNode)
{
    errlHndl_t err = NULL;
    uint64_t hrmorBase = KernelIpc::ipc_data_area.hrmor_base;
    void * node_info_ptr =
        reinterpret_cast<void *>((iv_masterCpu.groupId * hrmorBase) +
                                 VMM_INTERNODE_PRESERVED_MEMORY_ADDR);

    internode_info_t * this_node_info =
        reinterpret_cast<internode_info_t *>
        (mm_block_map(node_info_ptr,INTERNODE_INFO_SIZE));

    if(this_node_info)
    {
        if(this_node_info->eye_catcher != NODE_INFO_EYE_CATCHER)
        {
            // Initialize the mutli-node area for this node.
            err = initializeMpiplSyncArea();
        }

        this_node_info->exist[i_hbNode] = true;
        this_node_info->mpipl_intr_sync = INTR_MPIPL_SYNC_CLEAR;

        mm_block_unmap(this_node_info);
    }
    else
    {
        TRACFCOMP( g_trac_intr, "Failure calling mm_block_map : phys_addr=%p",
                   node_info_ptr);
        /*@
         * @errortype    ERRL_SEV_UNRECOVERABLE
         * @moduleid     INTR::MOD_INTR_SYNC_ADDNODE
         * @reasoncode   INTR::RC_CANNOT_MAP_MEMORY
         * @userdata1    physical address
         * @userdata2    Size
         * @devdesc      Error mapping in memory
         */
        err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      INTR::MOD_INTR_SYNC_ADDNODE,
                                      INTR::RC_CANNOT_MAP_MEMORY,
                                      reinterpret_cast<uint64_t>(node_info_ptr),
                                      INTERNODE_INFO_SIZE,
                                      true /*Add HB Software Callout*/);

    }
    return err;
}
#endif

#ifdef CONFIG_MPIPL_ENABLED
errlHndl_t  IntrRp::extractHbNodeInfo(void)
{
    errlHndl_t err = NULL;
    uint64_t hrmorBase = KernelIpc::ipc_data_area.hrmor_base;
    TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_existing_image = 0;
    void * node_info_ptr =
        reinterpret_cast<void *>((iv_masterCpu.groupId * hrmorBase) +
                                 VMM_INTERNODE_PRESERVED_MEMORY_ADDR);

    internode_info_t * this_node_info =
        reinterpret_cast<internode_info_t *>
        (mm_block_map(node_info_ptr,INTERNODE_INFO_SIZE));

    if(this_node_info)
    {
        if(this_node_info->eye_catcher != NODE_INFO_EYE_CATCHER)
        {
            TRACFCOMP(g_trac_intr, INFO_MRK
                      "MPIPL, but INTR node data sync area unintialized."
                      " Assuming single HB Intance system");
        }
        else //multinode
        {
            TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
              (MAX_NODES_PER_SYS -1);

            for(uint64_t node = 0; node < MAX_NODES_PER_SYS; ++node)
            {
                //If comm area indicates node exists, add to map
                if(this_node_info->exist[node])
                {
                    hb_existing_image |= (mask >> node);
                }
            }
        }

        mm_block_unmap(this_node_info);
    }
    else
    {
        TRACFCOMP( g_trac_intr, "Failure calling mm_block_map : phys_addr=%p",
                   node_info_ptr);
        /*@
         * @errortype    ERRL_SEV_UNRECOVERABLE
         * @moduleid     INTR::MOD_INTR_EXTRACTNODEINFO
         * @reasoncode   INTR::RC_CANNOT_MAP_MEMORY
         * @userdata1    physical address
         * @userdata2    Size
         * @devdesc      Error mapping in memory
         */
        err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      INTR::MOD_INTR_EXTRACTNODEINFO,
                                      INTR::RC_CANNOT_MAP_MEMORY,
                                      reinterpret_cast<uint64_t>(node_info_ptr),
                                      INTERNODE_INFO_SIZE,
                                      true /*Add HB Software Callout*/);

    }

    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    sys->setAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>(hb_existing_image);
    TRACFCOMP( g_trac_intr, "extractHbNodeInfo found map: %x", hb_existing_image);

    return err;
}
#endif

//----------------------------------------------------------------------------
// External interfaces
//----------------------------------------------------------------------------

// Register a message queue with a particular intr type
errlHndl_t INTR::registerMsgQ(msg_q_t i_msgQ,
                              uint32_t i_msg_type,
                              ext_intr_t i_intr_type)
{
    errlHndl_t err = NULL;
    // Can't add while handling an interrupt, so
    // send msg instead of direct call
    msg_q_t intr_msgQ = msg_q_resolve(VFS_ROOT_MSG_INTR);

    if(intr_msgQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_INTR_REGISTER_MSGQ;
        msg->data[0] = reinterpret_cast<uint64_t>(i_msgQ);
        msg->data[1] = static_cast<uint64_t>(i_intr_type);
        msg->data[1] |= static_cast<uint64_t>(i_msg_type) << 32;

        int rc = msg_sendrecv(intr_msgQ, msg);
        if(!rc)
        {
            err = reinterpret_cast<errlHndl_t>(msg->data[1]);
        }
        else
        {
            TRACFCOMP(g_trac_intr,ERR_MRK
                      "INTR::registerMsgQ - msg_sendrecv failed. errno = %d",
                      rc);
        }

        msg_free(msg);
    }
    else
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        INTR::MOD_INTR_REGISTER
         * @reasoncode      INTR::RC_REGISTRY_NOT_READY
         * @userdata1       Interrupt type to register
         * @userdata2       0
         *
         * @devdesc         Interrupt resource provider not initialized yet.
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
             INTR::MOD_INTR_REGISTER,             // moduleid
             INTR::RC_REGISTRY_NOT_READY,         // reason code
             static_cast<uint64_t>(i_intr_type),
             0
            );
    }

    return err;
}

void INTR::sendEOI(msg_q_t i_q, msg_t* i_msg)
{
    //Fix up message to make it easier to handle
    //Users are required to NOT touch it
    i_msg->type = MSG_INTR_EOI;
    msg_respond(i_q,i_msg);
}

// Unregister message queue from interrupt handler
msg_q_t INTR::unRegisterMsgQ(ext_intr_t i_type)
{
    msg_q_t msgQ = NULL;
    msg_q_t intr_msgQ = msg_q_resolve(VFS_ROOT_MSG_INTR);
    if(intr_msgQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_INTR_UNREGISTER_MSGQ;
        msg->data[0] = static_cast<uint64_t>(i_type);

        int rc = msg_sendrecv(intr_msgQ,msg);

        if(!rc)
        {
            msgQ = reinterpret_cast<msg_q_t>(msg->data[1]);
        }
        else
        {
            TRACFCOMP(g_trac_intr,ERR_MRK
                      "INTR::unRegisterMsgQ - msg_sendrecv failed. errno = %d",
                      rc);
        }

        msg_free(msg);
    }
    return msgQ;
}


/*
 * Enable hardware to report external interrupts
 */
errlHndl_t INTR::enableExternalInterrupts()
{
    errlHndl_t err = NULL;
    msg_q_t intr_msgQ = msg_q_resolve(VFS_ROOT_MSG_INTR);
   if(intr_msgQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_INTR_ENABLE;

        msg_sendrecv(intr_msgQ, msg);

        err = reinterpret_cast<errlHndl_t>(msg->data[1]);
        msg_free(msg);
    }
    else
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        INTR::MOD_INTR_ENABLE
         * @reasoncode      INTR::RC_RP_NOT_INITIALIZED
         * @userdata1       MSG_INTR_ENABLE
         * @userdata2       0
         *
         * @devdesc         Interrupt resource provider not initialized yet.
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,      // severity
             INTR::MOD_INTR_ENABLE,                 // moduleid
             INTR::RC_RP_NOT_INITIALIZED,           // reason code
             static_cast<uint64_t>(MSG_INTR_ENABLE),
             0
            );
    }
    return err;
}

/*
 * Disable hardware from reporting external interrupts
 */
errlHndl_t INTR::disableExternalInterrupts()
{
    errlHndl_t err = NULL;
    // Can't disable while handling interrupt, so send msg to serialize
    msg_q_t intr_msgQ = msg_q_resolve(VFS_ROOT_MSG_INTR);
    if(intr_msgQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_INTR_DISABLE;

        msg_sendrecv(intr_msgQ, msg);

        err = reinterpret_cast<errlHndl_t>(msg->data[1]);
        msg_free(msg);
    }
    else
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        INTR::MOD_INTR_DISABLE
         * @reasoncode      INTR::RC_RP_NOT_INITIALIZED
         * @userdata1       MSG_INTR_DISABLE
         * @userdata2       0
         *
         * @devdesc         Interrupt resource provider not initialized yet.
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,      // severity
             INTR::MOD_INTR_DISABLE,                // moduleid
             INTR::RC_RP_NOT_INITIALIZED,           // reason code
             static_cast<uint64_t>(MSG_INTR_DISABLE),
             0
            );
    }
    return err;
}

errlHndl_t IntrRp::setPsiHbBAR(TARGETING::Target * i_target)
{
    errlHndl_t l_err = NULL;
    uint64_t l_baseBarValue =
                      i_target->getAttr<TARGETING::ATTR_PSI_BRIDGE_BASE_ADDR>();

    do {
        //Get base BAR Value from attribute
        uint64_t l_barValue = l_baseBarValue;

        TRACFCOMP(g_trac_intr,"INTR: Setting PSI BRIDGE Bar Address value for -"
                              " Target %p. PSI BRIDGE BAR value: 0x%016lx",
                  i_target,l_barValue);

        //Set base BAR Value
        uint64_t size = sizeof(l_barValue);
        l_err = deviceWrite(i_target,
                          &l_barValue,
                          size,
                          DEVICE_SCOM_ADDRESS(PSI_BRIDGE_BAR_SCOM_ADDR));

        if(l_err)
        {
            TRACFCOMP(g_trac_intr,ERR_MRK"Unable to set PSI BRIDGE BAR Address");
            break;
        }

        //Now set the enable bit
        l_barValue += PSI_BRIDGE_BAR_ENABLE;
        size = sizeof(l_barValue);

        TRACDCOMP(g_trac_intr,"INTR: Setting PSI BRIDGE Bar enable value for Target - %p. PSI BRIDGE BAR value: 0x%016lx",
                  i_target,l_barValue);

        l_err = deviceWrite(i_target,
                          &l_barValue,
                          size,
                          DEVICE_SCOM_ADDRESS(PSI_BRIDGE_BAR_SCOM_ADDR));

        if(l_err)
        {
            TRACFCOMP(g_trac_intr,ERR_MRK"Error enabling PSIHB BAR");
            break;
        }

        //Map Memory Internally for HB and store in member variable
        void *l_psiHbAddress =
               reinterpret_cast<void *>(l_baseBarValue);
        iv_psiHbBaseAddr =
               reinterpret_cast<PSIHB_SW_INTERFACES_t *>
               (mmio_dev_map(l_psiHbAddress, PAGE_SIZE));
    } while(0);

    return l_err;
}

errlHndl_t IntrRp::setPsiHbEsbBAR(TARGETING::Target * i_target,
                                    bool i_enable)
{
    errlHndl_t l_err = NULL;
    uint64_t l_baseBarValue
            = i_target->getAttr<TARGETING::ATTR_PSI_HB_ESB_ADDR>();

    do {

        uint64_t l_barValue = l_baseBarValue;
        TRACDCOMP(g_trac_intr,"INTR: Target %p. "
                              "PSI BRIDGE ESB BAR value: 0x%016lx",
                  i_target,l_barValue);

        uint64_t size = sizeof(l_barValue);
        l_err = deviceWrite(i_target,
                          &l_barValue,
                          size,
                          DEVICE_SCOM_ADDRESS(PSI_BRIDGE_ESB_BAR_SCOM_ADDR));

        if(l_err)
        {
            TRACFCOMP(g_trac_intr,ERR_MRK"Unable to set PSIHB ESB BAR ");
            break;
        }

        //If we are trying to enable this BAR register
        if (i_enable)
        {
            l_barValue += PSI_BRIDGE_ESB_BAR_VALID;
            TRACDCOMP(g_trac_intr,"INTR: Target %p. PSI BRIDGE ESB BAR value: 0x%016lx",
                  i_target,l_barValue);

            size = sizeof(l_barValue);
            l_err = deviceWrite(i_target,
                             &l_barValue,
                             size,
                             DEVICE_SCOM_ADDRESS(PSI_BRIDGE_ESB_BAR_SCOM_ADDR));

            if(l_err)
            {
                TRACFCOMP(g_trac_intr,ERR_MRK"Error setting PSIHB ESB BAR");
                break;
            }

            //Map Memory Internally for HB and store in member variable
            void *l_psiHbEoiAddress =
                    reinterpret_cast<void *>(l_baseBarValue);
            iv_psiHbEsbBaseAddr =
               reinterpret_cast<uint64_t *>
               (mmio_dev_map(l_psiHbEoiAddress, (LSI_LAST_SOURCE)*PAGE_SIZE));
        }

    } while (0);

    return l_err;
}

errlHndl_t IntrRp::setXiveIvpeTmBAR1(TARGETING::Target * i_target)
{
    errlHndl_t l_err = NULL;
    uint64_t l_baseBarValue =
                i_target->getAttr<TARGETING::ATTR_XIVE_THREAD_MGMT1_BAR_ADDR>();

    do
    {
        uint64_t l_barValue = l_baseBarValue + XIVE_IVPE_TM_BAR1_VALIDATE;

        TRACDCOMP(g_trac_intr,"INTR: Target %p. XIVE IVPE TM BAR1 value: 0x%016lx",
                  i_target,l_barValue);

        uint64_t size = sizeof(l_barValue);
        l_err = deviceWrite(i_target,
                          &l_barValue,
                          size,
                          DEVICE_SCOM_ADDRESS(XIVE_IVPE_TM_BAR1_SCOM_ADDR));

        if(l_err)
        {
            TRACFCOMP(g_trac_intr,ERR_MRK"Unable to set XIVE IVPE TM BAR1");
            break;
        }

        //Map Memory Internally for HB and store in member variable
        void *l_xiveTmBar1Address =
                reinterpret_cast<void *>(l_baseBarValue);
        iv_xiveTmBar1Address =
               reinterpret_cast<uint64_t *>
               (mmio_dev_map(l_xiveTmBar1Address, PAGE_SIZE));

    } while(0);

    return l_err;
}


errlHndl_t IntrRp::setXiveIcBAR(TARGETING::Target * i_target)
{
    errlHndl_t l_err = NULL;
    uint64_t l_baseBarValue
            = i_target->getAttr<TARGETING::ATTR_XIVE_CONTROLLER_BAR_ADDR>();

    do {
        uint64_t l_barValue = l_baseBarValue + XIVE_IC_BAR_VALID;

        TRACDCOMP(g_trac_intr,"INTR: Target %p. XIVE IC BAR value: 0x%016lx",
                  i_target,l_barValue);

        uint64_t size = sizeof(l_barValue);
        l_err = deviceWrite(i_target,
                          &l_barValue,
                          size,
                          DEVICE_SCOM_ADDRESS(XIVE_IC_BAR_SCOM_ADDR));

        if(l_err)
        {
            TRACFCOMP(g_trac_intr,ERR_MRK"Unable to set XIVE IC BAR");
            break;
        }

        //Map Memory Internally for HB and store in member variable
        void *l_xiveIcBarAddress =
                reinterpret_cast<void *>(l_baseBarValue);
        iv_xiveIcBarAddress =
               reinterpret_cast<uint64_t *>
               (mmio_dev_map(l_xiveIcBarAddress, 40*PAGE_SIZE));

    } while(0);

    return l_err;
}

uint64_t INTR::getIntpAddr(const TARGETING::Target * i_ec, uint8_t i_thread)
{
    const TARGETING::Target * l_proc = getParentChip(i_ec);
    uint64_t l_intB =l_proc->getAttr<TARGETING::ATTR_INTP_BASE_ADDR>();

    PIR_t pir(0);
    pir.groupId = l_proc->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>();
    pir.chipId = l_proc->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
    pir.coreId = i_ec->getAttr<TARGETING::ATTR_CHIP_UNIT>();
    pir.threadId = i_thread;

    return (l_intB+ InterruptMsgHdlr::mmio_offset(
              pir.word & (InterruptMsgHdlr::P9_PIR_THREADID_MSK |
                          InterruptMsgHdlr::P9_PIR_COREID_MSK)));
}

void* INTR::IntrRp::handleCpuTimeout(void* _pir)
{
    uint64_t pir = reinterpret_cast<uint64_t>(_pir);
    task_detach();

    int count = 0;
    int rc = 0;

    // Allocate a message to send to the RP thread.
    msg_t* msg = msg_allocate();
    msg->type = MSG_INTR_ADD_CPU_TIMEOUT;
    msg->data[0] = pir;
    msg_q_t intr_msgQ = msg_q_resolve(VFS_ROOT_MSG_INTR);

    TRACFCOMP( g_trac_intr,"handleCpuTimeout for pir: %lx", pir);

    do
    {
        // Sleep for the right amount.
        nanosleep(0, CPU_WAKEUP_INTERVAL_NS);

        // Check the status with the RP thread.
        msg->data[1] = count;
        msg_sendrecv(intr_msgQ, msg);

        // Get the status from the response message.
        rc = msg->data[1];
        count++;

    } while(rc == EAGAIN);

    msg_free(msg);

    return NULL;
}

errlHndl_t INTR::addHbNode(uint64_t i_hbNode)
{
    errlHndl_t err = NULL;
    msg_q_t intr_msgQ = msg_q_resolve(VFS_ROOT_MSG_INTR);
    TRACFCOMP( g_trac_intr,"Add node %d for MPIPL",i_hbNode);
    if(intr_msgQ)
    {
        msg_t * msg = msg_allocate();
        msg->data[0] = i_hbNode;
        msg->type = MSG_INTR_ADD_HBNODE;
        msg_send(intr_msgQ, msg);
    }
    else
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        INTR::MOD_INTR_ADDHBNODE
         * @reasoncode      INTR::RC_RP_NOT_INITIALIZED
         * @userdata1       MSG_INTR_ADD_HBNODE
         * @userdata2       hbNode to add
         *
         * @devdesc         Interrupt resource provider not initialized yet.
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,      // severity
             INTR::MOD_INTR_ADDHBNODE,              // moduleid
             INTR::RC_RP_NOT_INITIALIZED,           // reason code
             static_cast<uint64_t>(MSG_INTR_ADD_HBNODE),
             i_hbNode
            );
    }

    return err;
}

void INTR::drainQueue()
{
    // send a sync message if queue is found
    msg_q_t intr_msgQ = msg_q_resolve(VFS_ROOT_MSG_INTR);
    if(intr_msgQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_INTR_DRAIN_QUEUE;
        msg_sendrecv(intr_msgQ, msg);
        msg_free(msg);
    }
    //else no queue, no need to do anything
}

uint64_t INTR::get_enabled_threads( void )
{
    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    assert( sys != NULL );
    uint64_t en_threads = sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();
    if( en_threads == 0 )
    {
        //TODO RTC 151022
        //Read <SBE memory area> for enabled threads value
        //  and set attribute appropriately
        en_threads = 0xF000000000000000; //Enable all the threads
        sys->setAttr<TARGETING::ATTR_ENABLED_THREADS>(en_threads);
    }
    return en_threads;
}
