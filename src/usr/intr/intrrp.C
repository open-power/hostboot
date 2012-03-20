//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/intr/intrrp.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
/**
 * @file intrrp.C
 * @brief Interrupt Resource Provider
 */

#include "intrrp.H"
#include <trace/interface.H>
#include <errno.h>
#include <initservice/taskargs.H>
#include <util/singleton.H>
#include <intr/intr_reasoncodes.H>
#include <sys/mmio.h>
#include <sys/misc.h>
#include <kernel/console.H>
#include <sys/task.h>
#include <targeting/targetservice.H>
#include <vmmconst.h>
#include <targeting/util.H>

using namespace INTR;

trace_desc_t * g_trac_intr = NULL;
TRAC_INIT(&g_trac_intr, INTR_COMP_NAME, 2 * 1024);


/**
 * setup _start and handle barrier
 */
TASK_ENTRY_MACRO( IntrRp::init );


void IntrRp::init( errlHndl_t   &io_errlHndl_t )
{
    errlHndl_t err = NULL;

    err = Singleton<IntrRp>::instance()._init();

    //  pass task error back to parent
    task_end2( err );
}


//  ICPBAR = INTP.ICP_BAR[0:25] in P7 = 0x3FBFF90 + (8*node) + procPos
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

    // TODO Temporaritly DISABLE in VBU until P8 support is confirmed
    if( TARGETING::is_vpo() )
    {
        iv_isVBU = true;
    }

    // get the PIR
    // Which ever cpu core this is running on is the MASTER cpu
    // Make master thread 0
    uint32_t cpuid = task_getcpuid();
    iv_masterCpu = cpuid;
    // If P7 or P7+ core -- need to tweak fields in PIR
    if(cpu_core_type() < CORE_POWER8_MURANO)
    {
        iv_masterCpu = P7PIR_t(cpuid);
    }
    iv_masterCpu.threadId = 0;

    TRACFCOMP(g_trac_intr,"node[%d], chip[%d], core[%d], thread[%d]",
              iv_masterCpu.nodeId, iv_masterCpu.chipId, iv_masterCpu.coreId,
              iv_masterCpu.threadId);


    uint64_t realAddr = 0;

    // TODO Does the BAR scom reg need to be read here or set here??
    //      Who sets the BAR?
    //uint64_t size = sizeof(realAddr);
    //TARGETING::TargetService& targetService = TARGETING::targetService();
    //TARGETING::Target* procTarget = NULL;
    //targetService.masterProcChipTargetHandle( procTarget );
    //
    // TODO What if this does not jive with with the PIR?

    // TODO Does this need to be read here?
    //err = deviceRead(procTarget,
    //                 &realAddr,
    //                 size,
    //                 DEVICE_SCOM_ADDRESS(ICPBAR_SCOM_ADDR));
    //if(err) return err;

    if(realAddr == 0)
    {
        realAddr = (static_cast<uint64_t>(ICPBAR_VAL)) << 34;
    }

    // TODO Does this need to be set here?
    // err = deviceWrite(procTarget,
    //                   &realAddr,
    //                   size,
    //                   DEVICE_SCOM_ADDRESS(ICPBAR_SCOM_ADDR));

    realAddr &= 0xFFFFFFFC00000000ul;   //[0:29] is ICP_BAR
    realAddr >>= 14;                    //[14:43] is BAR field in real address


    // The realAddr is the base address for the whole system.
    // Therefore the realAddr must be based on the processor with
    // lowest BAR value in the system. (usually n0p0)
    // TODO Adjust the realAddr if the BAR came from a processor other
    // than cpuid 0

    TRACFCOMP(g_trac_intr,"INTR: realAddr = %lx",realAddr);

    // VADDR_SIZE is 1MB per chip - max 32 -> 32MB
    iv_baseAddr = reinterpret_cast<uint64_t>
        (mmio_dev_map(reinterpret_cast<void*>(realAddr),THIRTYTWO_MB));

    TRACFCOMP(g_trac_intr,"INTR: vAddr = %lx",iv_baseAddr);

    err = checkAddress(iv_baseAddr);
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
        msg_q_register(iv_msgQ, INTR_MSGQ);

        task_create(IntrRp::msg_handler, NULL);
    }

    return err;
}

errlHndl_t IntrRp::enableInterrupts()
{
    errlHndl_t err = NULL;

    // TODO Temporarily DISABLE in VBU until P8 support is confirmed
    if(iv_isVBU) return err;

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
    // TODO Temporarily DISABLE in VBU until P8 support is confirmed
    if(iv_isVBU) return err;

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
void IntrRp::msg_handler(void * unused)
{
    Singleton<IntrRp>::instance().msgHandler();
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

                    // type = XISR = XIRR[8:31]
                    // priority = XIRR[0:7]
                    uint32_t * xirrAddress =
                        reinterpret_cast<uint32_t *>(iv_baseAddr+ XIRR_OFFSET+
                                                  cpuOffsetAddr(iv_masterCpu));

                    // xirr was read by interrupt message handler.
                    // Passed in as data[0]
                    uint32_t xirr = static_cast<uint32_t>(msg->data[0]);
                    type = static_cast<ext_intr_t>(xirr & 0x00FFFFFF);

                    TRACDCOMP(g_trac_intr,"External Interrupt recieved, Type=%x",type);

                    // Acknowlege msg
                    msg->data[1] = 0;
                    msg_respond(iv_msgQ, msg);

                    Registry_t::iterator r = iv_registry.find(type);
                    if(r != iv_registry.end())
                    {
                        msg_q_t msgQ = r->second;
                        msg_t * rmsg = msg_allocate();
                        rmsg->type = type;
                        int rc = msg_sendrecv(msgQ,rmsg);
                        if(rc)
                        {
                            TRACFCOMP(g_trac_intr,ERR_MRK
                                      "External Interrupt recieved type = %d, "
                                      "but could not send message to registered"
                                      " handler. Ignorming it. rc = %d",
                                      (uint32_t) type, rc);
                        }
                        msg_free(rmsg);
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

                    // Writing the XIRR with the same value read earlier
                    // tells the interrupt presenter hardware to signal an EOI.
                    *xirrAddress = xirr;
                }
                break;

            case MSG_INTR_REGISTER_MSGQ:
                {
                    msg_q_t l_msgQ = reinterpret_cast<msg_q_t>(msg->data[0]);
                    ext_intr_t l_t = static_cast<ext_intr_t>(msg->data[1]);
                    errlHndl_t err = registerInterrupt(l_msgQ,l_t);

                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    msg_respond(iv_msgQ,msg);
                }
                break;

            case MSG_INTR_UNREGISTER_MSGQ:
                {
                    TRACDCOMP(g_trac_intr,
                              "UNREG: msg type = 0x%lx",
                              msg->data[0]);

                    msg_q_t msgQ = NULL;
                    ext_intr_t type = static_cast<ext_intr_t>(msg->data[0]);
                    Registry_t::iterator r = iv_registry.find(type);
                    if(r != iv_registry.end())
                    {
                        msgQ = r->second;
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
            case MSG_INTR_ADD_CPU_USR:
            case MSG_INTR_ADD_CPU:
                {
                    PIR_t pir = msg->data[0];
                    // If P7 or P7+ core -- need to tweak fields in PIR
                    if(cpu_core_type() < CORE_POWER8_MURANO)
                    {
                        pir = P7PIR_t(msg->data[0]);
                    }

                    TRACFCOMP(g_trac_intr,"Add CPU node[%d], chip[%d],"
                              "core[%d], thread[%d]",
                              pir.nodeId, pir.chipId, pir.coreId,
                              pir.threadId);

                    size_t threads = cpu_thread_count();

                    for(size_t thread = 0; thread < threads; ++thread)
                    {
                        pir.threadId = thread;
                        initInterruptPresenter(pir);
                    }

                    msg->data[1] = 0;
                    msg_respond(iv_msgQ, msg);
                }
                break;

            default:
                msg->data[1] = -EINVAL;
                msg_respond(iv_msgQ, msg);
        }
    }
}


errlHndl_t IntrRp::registerInterrupt(msg_q_t i_msgQ, ext_intr_t i_type)
{
    errlHndl_t err = NULL;

    Registry_t::iterator r = iv_registry.find(i_type);
    if(r == iv_registry.end())
    {
        iv_registry[i_type] = i_msgQ;
    }
    else
    {
        if(r->second != i_msgQ)
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
                 i_type,
                 0
                );
        }

    }
    return err;
}

void IntrRp::initInterruptPresenter(const PIR_t i_pir) const
{
    // TODO Temporaritly DISABLE in VBU until P8 support is confirmed
    if(iv_isVBU) return;

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
        *cppr = 0xff;
    }
    else
    {
        *cppr = 0;      // no interrupts allowed except on master
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


// Register a message queue with a particular intr type
errlHndl_t INTR::registerMsgQ(msg_q_t i_msgQ, ext_intr_t i_type)
{
    errlHndl_t err = NULL;
    // Can't add while handling an interrupt, so
    // send msg instead of direct call
    msg_q_t intr_msgQ = msg_q_resolve(INTR_MSGQ);
    if(intr_msgQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_INTR_REGISTER_MSGQ;
        msg->data[0] = reinterpret_cast<uint64_t>(i_msgQ);
        msg->data[1] = static_cast<uint64_t>(i_type);

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
             static_cast<uint64_t>(i_type),
             0
            );
    }
    return err;
}

// Unregister message queue from interrupt handler
msg_q_t INTR::unRegisterMsgQ(ext_intr_t i_type)
{
    msg_q_t msgQ = NULL;
    msg_q_t intr_msgQ = msg_q_resolve(INTR_MSGQ);
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
    msg_q_t intr_msgQ = msg_q_resolve(INTR_MSGQ);
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
    msg_q_t intr_msgQ = msg_q_resolve(INTR_MSGQ);
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

