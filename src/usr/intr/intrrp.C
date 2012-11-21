/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/intr/intrrp.C $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
#include <sys/misc.h>
#include <kernel/console.H>
#include <sys/task.h>
#include <targeting/common/targetservice.H>
#include <vmmconst.h>
#include <targeting/common/attributes.H>
#include <devicefw/userif.H>
#include <sys/time.h>
#include <sys/vfs.h>

#define INTR_TRACE_NAME INTR_COMP_NAME

using namespace INTR;

trace_desc_t * g_trac_intr = NULL;
TRAC_INIT(&g_trac_intr, INTR_TRACE_NAME, 2 * 1024);

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


//  ICPBAR = INTP.ICP_BAR[0:25] in P8 = 0x3FFFF800 + (8*node) + procPos
//  P7 Scom address 0x02011C09 P8 = 0x020109c9
//  BaseAddress P7:
//  BA[18:43] = ICPBAR  (P8 says [14:43] (30 bits))
//  BA[47:49] = COREid (0-7)
//  BA[50:51] = cpu thread (0-3)
//
//  BaseAddress P8:
//  BA[14:43] = ICPBAR (30 bits)
//  BA[45:48] = coreID (1-6,9-14) (12 cores)
//  BA[49:51] = thread (0-7)
//
//  BA+0  = XIRR (poll - Read/Write has no side effects))
//  BA+4  = XIRR (Read locks HW, Write -> EOI to HW))
//  BA+12 = MFRR  (1 byte)
//  BA+16 = LINKA (4 bytes)
//  BA+20 = LINKB (4 bytes)
//  BA+24 = LINKC (4 bytes)
errlHndl_t IntrRp::_init()
{
    errlHndl_t err = NULL;

    // get the PIR
    // Which ever cpu core this is running on is the MASTER cpu
    // Make master thread 0
    uint32_t cpuid = task_getcpuid();
    iv_masterCpu = cpuid;
    iv_masterCpu.threadId = 0;

    TRACFCOMP(g_trac_intr,"Master cpu node[%d], chip[%d], core[%d], thread[%d]",
              iv_masterCpu.nodeId, iv_masterCpu.chipId, iv_masterCpu.coreId,
              iv_masterCpu.threadId);

    // The base realAddr is the base address for the whole system.
    // Therefore the realAddr must be based on the processor
    // that would have the lowest BAR value in the system,
    // whether it exists or not. In this case n0p0

    TARGETING::Target* procTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle( procTarget );

    uint64_t barValue = 0;
    procTarget->tryGetAttr<TARGETING::ATTR_INTP_BASE_ADDR>(barValue);

    // Mask off node & chip id to get base address
    uint64_t realAddr = barValue & ICPBAR_BASE_ADDRESS_MASK;

    TRACFCOMP(g_trac_intr,"INTR: realAddr = %lx",realAddr);

    // VADDR_SIZE is 1MB per chip - max 32 -> 32MB
    iv_baseAddr = reinterpret_cast<uint64_t>
        (mmio_dev_map(reinterpret_cast<void*>(realAddr),THIRTYTWO_MB));

    TRACFCOMP(g_trac_intr,"INTR: vAddr = %lx",iv_baseAddr);

    // Set the BAR scom reg
    err = setBAR(procTarget,iv_masterCpu);

    if(!err)
    {
        err = checkAddress(iv_baseAddr);
    }

    if(!err)
    {

        // Set up the interrupt provider registers
        // NOTE: It's only possible to set up the master core at this point.
        //
        // Set up link registers to forward all intrpts to master cpu.
        //
        // There is one register set per cpu thread.
        size_t threads = cpu_thread_count();

        PIR_t pir = iv_masterCpu;
        for(size_t thread = 0; thread < threads; ++thread)
        {
            pir.threadId = thread;
            initInterruptPresenter(pir);
        }

        // Get the kernel msg queue for ext intr
        // Create a task to handle the messages
        iv_msgQ = msg_q_create();
        msg_intr_q_register(iv_msgQ, realAddr);

        task_create(IntrRp::msg_handler, NULL);

        // Register event to be called on shutdown
        INITSERVICE::registerShutdownEvent(iv_msgQ,
                                           MSG_INTR_SHUTDOWN,
                                           INITSERVICE::INTR_PRIORITY);
    }

    return err;
}

errlHndl_t IntrRp::enableInterrupts()
{
    errlHndl_t err = NULL;

    // Enable the interrupt on master processor core, thread 0
    uint64_t baseAddr = iv_baseAddr + cpuOffsetAddr(iv_masterCpu);

    err = checkAddress(baseAddr);
    if(!err)
    {
        uint8_t * cppr = reinterpret_cast<uint8_t*>(baseAddr+CPPR_OFFSET);
        *cppr = 0xff;
    }

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
    while(1)
    {
        msg_t* msg = msg_wait(iv_msgQ); // wait for interrupt msg

        switch(msg->type)
        {
            case MSG_INTR_EXTERN:
                {
                    ext_intr_t type = NO_INTERRUPT;

                    // xirr was read by interrupt message handler.
                    // Passed in as data[1]
                    uint32_t xirr = static_cast<uint32_t>(msg->data[1]);
                    // data[0] has the PIR
                    PIR_t pir = static_cast<PIR_t>(msg->data[0]);

                    uint64_t baseAddr = iv_baseAddr + cpuOffsetAddr(pir);
                    uint32_t * xirrAddress =
                        reinterpret_cast<uint32_t*>(baseAddr + XIRR_OFFSET);

                    // type = XISR = XIRR[8:31]
                    // priority = XIRR[0:7]
                    // Use the XISR as the type (for now)
                    type = static_cast<ext_intr_t>(xirr & XISR_MASK);

                    TRACFCOMP(g_trac_intr,"External Interrupt recieved, Type=%x",type);

                    // Acknowlege msg
                    msg->data[1] = 0;
                    msg_respond(iv_msgQ, msg);

                    Registry_t::iterator r = iv_registry.find(type);
                    if(r != iv_registry.end())
                    {
                        msg_q_t msgQ = r->second.msgQ;

                        msg_t * rmsg = msg_allocate();
                        rmsg->type = r->second.msgType;
                        rmsg->data[0] = type;  // interrupt type
                        rmsg->data[1] = 0;
                        rmsg->extra_data = NULL;

                        int rc = msg_sendrecv(msgQ,rmsg);
                        if(rc)
                        {
                            TRACFCOMP(g_trac_intr,ERR_MRK
                                      "External Interrupt recieved type = %d, "
                                      "but could not send message to registered"
                                      " handler. Ignoring it. rc = %d",
                                      (uint32_t) type, rc);
                        }
                        msg_free(rmsg);
                    }
                    else if (type == INTERPROC)
                    {
                        // Ignore "spurious" IPIs (handled below).

                        // Note that we could get an INTERPROC interrupt
                        // and handle it through the above registration list
                        // as well.  This is to catch the case where no one
                        // has registered for an IPI.
                    }
                    else  // no queue registered for this interrupt type
                    {
                        // Throw it away for now.
                        TRACFCOMP(g_trac_intr,ERR_MRK
                                  "External Interrupt recieved type = %d, but "
                                  "nothing registered to handle it. "
                                  "Ignoreing it.",
                                  (uint32_t)type);
                    }

                    // Handle IPIs special since they're used for waking up
                    // cores and have special clearing requirements.
                    if (type == INTERPROC)
                    {
                        // Clear IPI request.
                        volatile uint8_t * mfrr =
                            reinterpret_cast<uint8_t*>(baseAddr + MFRR_OFFSET);
                        (*mfrr) = 0xff;
                        eieio();  // Force mfrr clear before xirr EIO.

                        // Deal with pending IPIs.
                        PIR_t core_pir = pir; core_pir.threadId = 0;
                        if (iv_ipisPending.count(core_pir))
                        {
                            TRACFCOMP(g_trac_intr,INFO_MRK
                                      "IPI wakeup received for %d", pir.word);

                            IPI_Info_t& ipiInfo = iv_ipisPending[core_pir];

                            ipiInfo.first &= ~(1 << pir.threadId);

                            if (0 == ipiInfo.first)
                            {
                                msg_t* ipiMsg = ipiInfo.second;
                                iv_ipisPending.erase(core_pir);

                                ipiMsg->data[1] = 0;
                                msg_respond(iv_msgQ, ipiMsg);
                            }
                            else
                            {
                                TRACDCOMP(g_trac_intr,INFO_MRK
                                          "IPI still pending for %x",
                                          ipiInfo.first);
                            }

                        }
                    }

                    // Writing the XIRR with the same value read earlier
                    // tells the interrupt presenter hardware to signal an EOI.
                    *xirrAddress = xirr;
                }
                break;

            case MSG_INTR_REGISTER_MSGQ:
                {
                    msg_q_t l_msgQ = reinterpret_cast<msg_q_t>(msg->data[0]);
                    uint64_t l_type = msg->data[1];
                    ext_intr_t l_intr_type = static_cast<ext_intr_t>(l_type & 0xFFFF);
                    errlHndl_t err = registerInterrupt(l_msgQ,l_type >> 32,l_intr_type);

                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    msg_respond(iv_msgQ,msg);
                }
                break;

            case MSG_INTR_UNREGISTER_MSGQ:
                {
                    TRACFCOMP(g_trac_intr,
                              "INTR remove registration of interrupt type = 0x%lx",
                              msg->data[0]);

                    msg_q_t msgQ = NULL;
                    ext_intr_t type = static_cast<ext_intr_t>(msg->data[0]);
                    Registry_t::iterator r = iv_registry.find(type);
                    if(r != iv_registry.end())
                    {
                        msgQ = r->second.msgQ;
                        iv_registry.erase(r);
                    }

                    msg->data[1] = reinterpret_cast<uint64_t>(msgQ);

                    TRACDCOMP(g_trac_intr,
                              "UNREG: msgQ = 0x%lx",
                              msg->data[1]);

                    msg_respond(iv_msgQ,msg);
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
                    errlHndl_t err =disableInterrupts();
                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    msg_respond(iv_msgQ,msg);
                }
                break;

            //  Called when a new cpu becomes active other than the master
            //  Expect a call for each new core
            case MSG_INTR_ADD_CPU:
                {
                    PIR_t pir = msg->data[1];
                    pir.threadId = 0;
                    iv_cpuList.push_back(pir);

                    TRACFCOMP(g_trac_intr,"Add CPU node[%d], chip[%d],"
                              "core[%d], thread[%d]",
                              pir.nodeId, pir.chipId, pir.coreId,
                              pir.threadId);

                    size_t threads = cpu_thread_count();
                    iv_ipisPending[pir] = IPI_Info_t((1 << threads)-1, msg);

                    for(size_t thread = 0; thread < threads; ++thread)
                    {
                        pir.threadId = thread;
                        initInterruptPresenter(pir);
                        sendIPI(pir);
                    }
                }
                break;

            case MSG_INTR_SHUTDOWN:
                {
                    TRACFCOMP(g_trac_intr,"Shutdown event received");
                    shutDown();

                    msg_respond(iv_msgQ, msg);

                }
                break;

            default:
                msg->data[1] = -EINVAL;
                msg_respond(iv_msgQ, msg);
        }
    }
}



errlHndl_t IntrRp::setBAR(TARGETING::Target * i_target,
                          const PIR_t i_pir)
{
    errlHndl_t err = NULL;

    uint64_t barValue = 0;
    i_target->tryGetAttr<TARGETING::ATTR_INTP_BASE_ADDR>(barValue);

    barValue <<= 14;
    barValue |= 1ULL << (63 - ICPBAR_EN);

    TRACFCOMP(g_trac_intr,"INTR: Target %p. ICPBAR value: 0x%016lx",
              i_target,barValue);

    uint64_t size = sizeof(barValue);

    err = deviceWrite(i_target,
                      &barValue,
                      size,
                      DEVICE_SCOM_ADDRESS(ICPBAR_SCOM_ADDR));

    if(err)
    {
        TRACFCOMP(g_trac_intr,ERR_MRK"Unable to set IPCBAR");
    }

    return err;
}



errlHndl_t IntrRp::registerInterrupt(msg_q_t i_msgQ,
                                     uint32_t i_msg_type,
                                     ext_intr_t i_intr_type)
{
    errlHndl_t err = NULL;

    Registry_t::iterator r = iv_registry.find(i_intr_type);
    if(r == iv_registry.end())
    {
        TRACFCOMP(g_trac_intr,"INTR::register intr type 0x%x", i_intr_type);
        iv_registry[i_intr_type] = intr_response_t(i_msgQ,i_msg_type);
    }
    else
    {
        if(r->second.msgQ != i_msgQ)
        {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        INTR::MOD_INTRRP_REGISTERINTERRUPT
         * @reasoncode      INTR::RC_ALREADY_REGISTERED
         * @userdata1       Interrupt type
         * @userdata2       0
         *
         * @defdesc         Interrupt type already registered
         *
         */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
                 INTR::MOD_INTRRP_REGISTERINTERRUPT,  // moduleid
                 INTR::RC_ALREADY_REGISTERED,         // reason code
                 i_intr_type,
                 0
                );
        }

    }
    return err;
}

void IntrRp::initInterruptPresenter(const PIR_t i_pir) const
{
    uint64_t baseAddr = iv_baseAddr + cpuOffsetAddr(i_pir);
    uint8_t * cppr =
        reinterpret_cast<uint8_t*>(baseAddr + CPPR_OFFSET);
    uint32_t * plinkReg =
        reinterpret_cast<uint32_t *>(baseAddr + LINKA_OFFSET);

    TRACDCOMP(g_trac_intr,"PIR 0x%x offset: 0x%lx",
              i_pir.word,
              cpuOffsetAddr(i_pir));
    if(i_pir.word == iv_masterCpu.word)
    {
        *cppr = 0xff;      // Allow all interrupts on master.
    }
    else
    {
        *cppr = 0x01;      // Allow only priority 0 interrupts on non-masters.
                           // We use priority 0 to deliver IPIs for waking up
                           // a core.
    }

    // Links are intended to be set up in rings.  If an interrupt ends up
    // where it started, it gets rejected by hardware.
    //
    // According to BOOK IV, The links regs are setup by firmware.
    //
    // Should be possible to link all interrupt forwarding directly to
    // the master core and either make them direct (lspec = 0) or by setting
    // the LOOPTRIP bit to stop the forwarding at the masterProc.
    //
    LinkReg_t linkReg;
    linkReg.word = 0;
    linkReg.loopTrip = 1;   // needed?
    linkReg.node = iv_masterCpu.nodeId;
    linkReg.pchip= iv_masterCpu.chipId;
    linkReg.pcore= iv_masterCpu.coreId;
    linkReg.tspec= iv_masterCpu.threadId;

    *(plinkReg) = linkReg.word;
    *(plinkReg + 1) = linkReg.word;
    linkReg.last = 1;
    *(plinkReg + 2) = linkReg.word;
}



void IntrRp::deconfigureInterruptPresenter(const PIR_t i_pir) const
{
    uint64_t baseAddr = iv_baseAddr + cpuOffsetAddr(i_pir);
    uint8_t * cppr =
        reinterpret_cast<uint8_t*>(baseAddr + CPPR_OFFSET);
    uint32_t * plinkReg =
        reinterpret_cast<uint32_t *>(baseAddr + LINKA_OFFSET);

    // non- side effect xirr register
    uint32_t * xirrAddr =
        reinterpret_cast<uint32_t *>(baseAddr) + XIRR_RO_OFFSET;

    uint32_t xirr = *xirrAddr & 0x00FFFFFF;

    TRACDCOMP(g_trac_intr,"PIR 0x%x offset: 0x%lx",
              i_pir.word,
              cpuOffsetAddr(i_pir));

    // Not sure if this will ever happen, but squawk alittle if it does
    if(xirr)
    {
        TRACFCOMP(g_trac_intr,
                  ERR_MRK
                  "Pending interrupt found on shutdown. CpuId:0x%x XIRR:0x%x",
                  i_pir.word,
                  xirr);
    }

    *cppr = 0;          // Set priority to most favored (off)

    *plinkReg = 0;      // Reset link registers - clear all forwarding
    *(plinkReg + 1) = 0;
    *(plinkReg + 2) = 0;
}


void IntrRp::sendIPI(const PIR_t i_pir) const
{
    uint64_t baseAddr = iv_baseAddr + cpuOffsetAddr(i_pir);
    volatile uint8_t * mfrr =
        reinterpret_cast<uint8_t*>(baseAddr + MFRR_OFFSET);

    eieio(); sync();
    MAGIC_INSTRUCTION(MAGIC_SIMICS_CORESTATESAVE);
    (*mfrr) = 0x00;
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
         * @defdesc         The virutal address is not a valid IO address
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

void IntrRp::shutDown()
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
        rmsg->data[1] = 0;
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

    // Reset the hardware regiseters

    iv_cpuList.push_back(iv_masterCpu);

    size_t threads = cpu_thread_count();
    for(CpuList_t::iterator pir_itr = iv_cpuList.begin();
        pir_itr != iv_cpuList.end();
        ++pir_itr)
    {
        PIR_t pir = *pir_itr;
        for(size_t thread = 0; thread < threads; ++thread)
        {
            pir.threadId = thread;
            deconfigureInterruptPresenter(pir);
        }
    }
    TRACFCOMP(g_trac_intr,INFO_MRK,"INTR is shutdown");
}

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
         * @defdesc         Interrupt resource provider not initialized yet.
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
         * @defdesc         Interrupt resource provider not initialized yet.
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
         * @defdesc         Interrupt resource provider not initialized yet.
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

uint32_t INTR::intrDestCpuId(uint32_t i_xisr)
{
    return Singleton<IntrRp>::instance().intrDestCpuId(i_xisr);
}

