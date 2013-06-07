/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/intr/intrrp.C $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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

#define INTR_TRACE_NAME INTR_COMP_NAME

using namespace INTR;
using namespace TARGETING;

const uint32_t IntrRp::cv_PE_IRSN_COMP_SCOM_LIST[] =
{
    PE0_IRSN_COMP_SCOM_ADDR,
    PE1_IRSN_COMP_SCOM_ADDR,
    PE2_IRSN_COMP_SCOM_ADDR
};

const uint32_t IntrRp::cv_PE_IRSN_MASK_SCOM_LIST[] =
{
    PE0_IRSN_MASK_SCOM_ADDR,
    PE1_IRSN_MASK_SCOM_ADDR,
    PE2_IRSN_MASK_SCOM_ADDR
};

const uint32_t IntrRp::cv_PE_BAR_SCOM_LIST[] =
{
    PE0_BAREN_SCOM_ADDR,
    PE1_BAREN_SCOM_ADDR,
    PE2_BAREN_SCOM_ADDR
};

trace_desc_t * g_trac_intr = NULL;
TRAC_INIT(&g_trac_intr, INTR_TRACE_NAME, KILOBYTE, TRACE::BUFFER_SLOW);

/**
 * setup _start and handle barrier
 */
TASK_ENTRY_MACRO( IntrRp::init );


/**
 * @brief Utility function to get the list of enabled threads
 * @return Bitstring of enabled threads
 */
uint64_t get_enabled_threads( void )
{
    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    assert( sys != NULL );
    uint64_t en_threads = sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();
    if( en_threads == 0 )
    {
        // Read the scratch reg that the SBE setup
        //  Enabled threads are listed as a bitstring in bits 16:23
        //  A value of zero means the SBE hasn't set them up yet
        while( en_threads == 0 )
        {
            en_threads = mmio_scratch_read(MMIO_SCRATCH_AVP_THREADS);

            //@todo RTC:63991 - Remove this after we get the new SBE image
            if( en_threads == 0 )
            {
                // Default to all threads enabled
                uint64_t max_threads = cpu_thread_count();
                en_threads =
                  ((1ull << max_threads) - 1ull) << (48ull - max_threads);
            }
        }
        en_threads = en_threads << 16; //left-justify the threads
        TRACFCOMP( g_trac_intr,
                   "Enabled Threads = %.16X",
                   en_threads );

        sys->setAttr<TARGETING::ATTR_ENABLED_THREADS>(en_threads);
    }
    TRACDCOMP( g_trac_intr, "en_threads=%.16X", en_threads );
    return en_threads;
}

void IntrRp::init( errlHndl_t   &io_errlHndl_t )
{
    errlHndl_t err = NULL;

    err = Singleton<IntrRp>::instance()._init();

    //  pass task error back to parent
    io_errlHndl_t = err ;
}


//  ICPBAR = INTP.ICP_BAR[0:25] in P8 = 0x3FFFF800 + (8*node) + procPos
//  P8 Scom address = 0x020109c9
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
    barValue = procTarget->getAttr<TARGETING::ATTR_INTP_BASE_ADDR>();

    // Mask off node & chip id to get base address
    uint64_t realAddr = barValue & ICPBAR_BASE_ADDRESS_MASK;

    TRACFCOMP(g_trac_intr,"INTR: realAddr = %lx",realAddr);

    // VADDR_SIZE is 1MB per chip - max 32 -> 32MB
    iv_baseAddr = reinterpret_cast<uint64_t>
        (mmio_dev_map(reinterpret_cast<void*>(realAddr),THIRTYTWO_MB));

    TRACFCOMP(g_trac_intr,"INTR: vAddr = %lx",iv_baseAddr);

    // Set up the IPC message Data area
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != NULL);
    uint64_t hrmor_base =
        sys->getAttr<TARGETING::ATTR_HB_HRMOR_NODAL_BASE>();
 
    KernelIpc::ipc_data_area.pir = iv_masterCpu.word;
    KernelIpc::ipc_data_area.hrmor_base = hrmor_base;
    KernelIpc::ipc_data_area.msg_queue_id = 0;

    // Set the BAR scom reg
    err = setBAR(procTarget,iv_masterCpu);

    if(!err)
    {
        err = checkAddress(iv_baseAddr);
    }

    if(!err)
    {
        uint8_t is_mpipl = 0;
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        if(sys &&
           sys->tryGetAttr<TARGETING::ATTR_IS_MPIPL_HB>(is_mpipl) &&
           is_mpipl)
        {
            TRACFCOMP(g_trac_intr,"Disable interupts for MPIPL");
            err = hw_disableIntrMpIpl();

            if(err)
            {
                errlCommit(err,INTR_COMP_ID);
                err = NULL;
            }
        }
        else
        {
            // The XIRR should be clean at this point, if not there is a
            // serious problem. The routine will assert if an interrupt is
            // found.
            cleanCheck();
        }
        

        // Set up the interrupt provider registers
        // NOTE: It's only possible to set up the master core at this point.
        //
        // Set up link registers to forward all intrpts to master cpu.
        //
        // There is one register set per cpu thread.
        uint64_t max_threads = cpu_thread_count();
        uint64_t en_threads = get_enabled_threads();

        PIR_t pir = iv_masterCpu;
        for(size_t thread = 0; thread < max_threads; ++thread)
        {
            // Skip threads that we shouldn't be starting
            if( !(en_threads & (0x8000000000000000>>thread)) )
            {
                TRACDCOMP(g_trac_intr,
                          "IntrRp::_init: Skipping thread %d : en_threads=%X",
                          thread,en_threads);
                continue;
            } 
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

    if(!err)
    {
        // Enable PSI to present interrupts
        err = initIRSCReg(procTarget);
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

                    TRACFCOMP(g_trac_intr,
                              "External Interrupt recieved, Type=%x",
                              type);

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
                    else if (type == INTERPROC_XISR)
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
                                  "Ignoring it.",
                                  (uint32_t)type);
                    }

                    // Handle IPIs special since they're used for waking up
                    // cores and have special clearing requirements.
                    if (type == INTERPROC_XISR)
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
                    ISNvalue_t l_intr_type = static_cast<ISNvalue_t>
                      (l_type & 0xFFFF);

                    errlHndl_t err = registerInterruptISN(l_msgQ,l_type >> 32,
                                                       l_intr_type);
                    if(!err)
                    {
                        err = initXIVR(l_intr_type, true);
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
                    ISNvalue_t l_type = static_cast<ISNvalue_t>(msg->data[0]);
                    msg_q_t msgQ = unregisterInterruptISN(l_type);

                    if(msgQ)
                    {
                        //shouldn't get an error since we found a queue
                        //Just commit it
                        errlHndl_t err = initXIVR(l_type, false);
                        if(err)
                        {
                            errlCommit(err,INTR_COMP_ID);
                        }
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
                    uint64_t en_threads = get_enabled_threads();

                    iv_ipisPending[pir] = IPI_Info_t((1 << threads)-1, msg);

                    for(size_t thread = 0; thread < threads; ++thread)
                    {
                        // Skip threads that we shouldn't be starting
                        if( !(en_threads & (0x8000000000000000>>thread)) )
                        {
                            TRACDCOMP(g_trac_intr,"MSG_INTR_ADD_CPU: Skipping thread %d",thread);
                            continue;
                        } 
                        pir.threadId = thread;
                        initInterruptPresenter(pir);
                        sendIPI(pir);
                    }
                }
                break;

            case MSG_INTR_ENABLE_PSI_INTR:
                {
                    TARGETING::Target * target =
                        reinterpret_cast<TARGETING::Target *>(msg->data[0]);
                    errlHndl_t err = initIRSCReg(target);
                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    msg_respond(iv_msgQ,msg);
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
    barValue = i_target->getAttr<TARGETING::ATTR_INTP_BASE_ADDR>();

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


errlHndl_t IntrRp::initIRSCReg(TARGETING::Target * i_target)
{
    errlHndl_t err = NULL;

    // Only do once for each proc chip
    if(std::find(iv_chipList.begin(),iv_chipList.end(),i_target) ==
       iv_chipList.end())
    {
        uint8_t chip = 0;
        uint8_t node = 0;

        node = i_target->getAttr<ATTR_FABRIC_NODE_ID>();
        chip = i_target->getAttr<ATTR_FABRIC_CHIP_ID>();

        size_t scom_len = sizeof(uint64_t);

        // Mask off interrupts from isn's on this target
        // This also sets the source isn and PIR destination
        // such that if an interrupt is pending when when the ISRN
        // is written, simics get the right destination for the
        // interrupt.
        err = maskXIVR(i_target);

        // Setup PHBISR
        // EN.TPC.PSIHB.PSIHB_ISRN_REG set to 0x00030003FFFF0000
        PSIHB_ISRN_REG_t reg;

        PIR_t pir(0);
        pir.nodeId = node;
        pir.chipId = chip;
        // IRSN must be unique for each processor chip
        reg.irsn = makeXISR(pir,0);
        reg.die  = PSIHB_ISRN_REG_t::ENABLE;
        reg.uie  = PSIHB_ISRN_REG_t::ENABLE;
        reg.mask = PSIHB_ISRN_REG_t::IRSN_MASK;

        TRACFCOMP(g_trac_intr,"PSIHB_ISRN_REG: 0x%016lx",reg.d64);

        err = deviceWrite
            ( i_target,
              &reg,
              scom_len,
              DEVICE_SCOM_ADDRESS(PSIHB_ISRN_REG_t::PSIHB_ISRN_REG));

        if(err)
        {
            // add callout
            err->addHwCallout(i_target,
                              HWAS::SRCI_PRIORITY_HIGH,
                              HWAS::DECONFIG,
                              HWAS::GARD_NULL);
        }
        else
        {
            iv_chipList.push_back(i_target);
        }
    }

    return err;
}

errlHndl_t IntrRp::initXIVR(enum ISNvalue_t i_isn, bool i_enable)
{
    errlHndl_t err = NULL;
    size_t scom_len = sizeof(uint64_t);
    uint64_t scom_addr = 0;

    //Don't do any of this for ISN_INTERPROC
    if(ISN_INTERPROC != i_isn)
    {
        //Setup the XIVR register
        PsiHbXivr xivr;
        PIR_t pir = intrDestCpuId();
        xivr.pir = pir.word;
        xivr.source = i_isn;

        switch(i_isn)
        {
        case ISN_OCC:
            xivr.priority   = PsiHbXivr::OCC_PRIO;
            scom_addr       = PsiHbXivr::OCC_XIVR_ADRR;
            break;

        case ISN_FSI: //FSP_MAILBOX
            xivr.priority   = PsiHbXivr::FSI_PRIO;
            scom_addr       = PsiHbXivr::FSI_XIVR_ADRR;
            break;

        case ISN_LPC:
            xivr.priority   = PsiHbXivr::LPC_PRIO;
            scom_addr       = PsiHbXivr::LPC_XIVR_ADRR;
            break;

        case ISN_LCL_ERR:
            xivr.priority   = PsiHbXivr::LCL_ERR_PRIO;
            scom_addr       = PsiHbXivr::LCL_ERR_XIVR_ADDR;
            break;

        case ISN_HOST:
            xivr.priority   = PsiHbXivr::HOST_PRIO;
            scom_addr       = PsiHbXivr::HOST_XIVR_ADRR;
            break;

        default: //Unsupported ISN
            TRACFCOMP(g_trac_intr,"Unsupported ISN: 0x%02x",i_isn);
            /*@ errorlog tag
             * @errortype  ERRL_SEV_INFORMATIONAL
             * @moduleid   INTR::MOD_INTR_INIT_XIVR
             * @reasoncode INTR::RC_BAD_ISN
             * @userdata1  Interrupt type to register
             * @userdata2  0
             *
             * @devdesc    Unsupported ISN Requested
             *
             */
            err = new ERRORLOG::ErrlEntry
              (
               ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
               INTR::MOD_INTR_INIT_XIVR,            // moduleid
               INTR::RC_BAD_ISN,                    // reason code
               static_cast<uint64_t>(i_isn),
               0
               );
        }

        // Init the XIVR on all chips we have setup
        // Note that this doesn't handle chips getting added midstream,
        // But the current use case only has FSIMbox (1 chip) and
        // ATTN (all chips) at stable points in the IPL
        if(!err)
        {
            if(i_enable)
            {
                iv_isnList.push_back(i_isn);
            }
            else
            {
                xivr.priority = PsiHbXivr::PRIO_DISABLED;

                //Remove from isn list
                ISNList_t::iterator itr = std::find(iv_isnList.begin(),
                                                    iv_isnList.end(),
                                                    i_isn);
                if(itr != iv_isnList.end())
                {
                    iv_isnList.erase(itr);
                }
            }

            for(ChipList_t::iterator target_itr = iv_chipList.begin();
                target_itr != iv_chipList.end(); ++target_itr)
            {
                err = deviceWrite
                  (*target_itr,
                   &xivr,
                   scom_len,
                   DEVICE_SCOM_ADDRESS(scom_addr));

                if(err)
                {
                    break;
                }
            }
        }
    }

    return err;
}

//----------------------------------------------------------------------------

// Set priority highest (disabled) ,but with valid PIR
errlHndl_t IntrRp::maskXIVR(TARGETING::Target *i_target)
{
    struct XIVR_INFO
    {
        ISNvalue_t  isn:8;
        uint32_t addr;
    };

    static  const XIVR_INFO xivr_info[] =
    {
        {ISN_OCC,       PsiHbXivr::OCC_XIVR_ADRR},
        {ISN_FSI,       PsiHbXivr::FSI_XIVR_ADRR},
        {ISN_LPC,       PsiHbXivr::LPC_XIVR_ADRR},
        {ISN_LCL_ERR,   PsiHbXivr::LCL_ERR_XIVR_ADDR},
        {ISN_HOST,      PsiHbXivr::HOST_XIVR_ADRR}
    };

    errlHndl_t err = NULL;
    size_t scom_len = sizeof(uint64_t);
    PIR_t pir = intrDestCpuId();
    PsiHbXivr xivr;

    xivr.pir = pir.word;
    xivr.priority = PsiHbXivr::PRIO_DISABLED;

    for(size_t i = 0; i < sizeof(xivr_info)/sizeof(xivr_info[0]); ++i)
    {
        xivr.source = xivr_info[i].isn;

        err = deviceWrite
            (i_target,
             &xivr,
             scom_len,
             DEVICE_SCOM_ADDRESS(xivr_info[i].addr));

        if(err)
        {
            break;
        }
    }
    return err;
}

//----------------------------------------------------------------------------

errlHndl_t IntrRp::registerInterruptISN(msg_q_t i_msgQ,
                                     uint32_t i_msg_type,
                                     ext_intr_t i_intr_type)
{
    errlHndl_t err = NULL;

    //INTERPROC is special -- same for all procs
    if(i_intr_type == ISN_INTERPROC)
    {
        err = registerInterruptXISR(i_msgQ, i_msg_type,
                                    INTERPROC_XISR);
    }
    else
    {
        //Register interrupt type on all present procs
        for(ChipList_t::iterator target_itr = iv_chipList.begin();
            target_itr != iv_chipList.end(); ++target_itr)
        {
            uint8_t chip = 0;
            uint8_t node = 0;
            node = (*target_itr)->getAttr<ATTR_FABRIC_NODE_ID>();
            chip = (*target_itr)->getAttr<ATTR_FABRIC_CHIP_ID>();

            PIR_t pir(0);
            pir.nodeId = node;
            pir.chipId = chip;
            uint32_t l_irsn = makeXISR(pir, i_intr_type);

            err = registerInterruptXISR(i_msgQ, i_msg_type, l_irsn);
            if(err)
            {
                break;
            }
        }
    }
    return err;
}

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

msg_q_t IntrRp::unregisterInterruptISN(ISNvalue_t i_intr_type)
{
    msg_q_t msgQ = NULL;

    //INTERPROC is special -- same for all procs
    if(i_intr_type == ISN_INTERPROC)
    {
        msgQ = unregisterInterruptXISR(INTERPROC_XISR);
    }
    else
    {
        //Unregister interrupt type on all present procs
        for(ChipList_t::iterator target_itr = iv_chipList.begin();
            target_itr != iv_chipList.end(); ++target_itr)
        {
            uint8_t chip = 0;
            uint8_t node = 0;
            node = (*target_itr)->getAttr<ATTR_FABRIC_NODE_ID>();
            chip = (*target_itr)->getAttr<ATTR_FABRIC_CHIP_ID>();

            PIR_t pir(0);
            pir.nodeId = node;
            pir.chipId = chip;
            uint32_t l_irsn = makeXISR(pir, i_intr_type);

            msgQ = unregisterInterruptXISR(l_irsn);
        }
    }

    return msgQ;
}

msg_q_t IntrRp::unregisterInterruptXISR(ext_intr_t i_xisr)
{
    msg_q_t msgQ = NULL;

    Registry_t::iterator r = iv_registry.find(i_xisr);
    if(r != iv_registry.end())
    {
        msgQ = r->second.msgQ;
        iv_registry.erase(r);
    }

    return msgQ;
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



void IntrRp::disableInterruptPresenter(const PIR_t i_pir) const
{
    uint64_t baseAddr = iv_baseAddr + cpuOffsetAddr(i_pir);
    uint8_t * cppr =
        reinterpret_cast<uint8_t*>(baseAddr + CPPR_OFFSET);
    uint32_t * plinkReg =
        reinterpret_cast<uint32_t *>(baseAddr + LINKA_OFFSET);

    // non- side effect xirr register
    uint32_t * xirrAddr =
        reinterpret_cast<uint32_t *>(baseAddr + XIRR_RO_OFFSET);

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
         * @devdesc         The virutal address is not a valid IO address
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
    errlHndl_t err = NULL;
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

    // Reset the PSI regs
    // NOTE: there is nothing in the  IRSN Proposal.odt document that
    // specifies a procedure or order for disabling interrupts.
    // @see RTC story 47105 discussion for Firmware & Hardware requirements
    //

    //Going to clear the XIVRs first
    ISNList_t l_isnList = iv_isnList;
    for(ISNList_t::iterator isnItr = l_isnList.begin();
        isnItr != l_isnList.end();++isnItr)
    {
        //shouldn't get an error since we found a queue
        //so just commit it
        err = initXIVR((*isnItr), false);
        if(err)
        {
            errlCommit(err,INTR_COMP_ID);
            err = NULL;
        }
    }

    // TODO secure boot - how do we know a processor chip has been added?
    PSIHB_ISRN_REG_t reg;               //zeros self
    size_t scom_len = sizeof(reg);

    for(ChipList_t::iterator target_itr = iv_chipList.begin();
        target_itr != iv_chipList.end(); ++target_itr)
    {
        err = deviceWrite
            (*target_itr,
             &reg,
             scom_len,
             DEVICE_SCOM_ADDRESS(PSIHB_ISRN_REG_t::PSIHB_ISRN_REG));

        if(err)
        {
            errlCommit(err,INTR_COMP_ID);
            err = NULL;
        }
    }


    // Reset the IP hardware regiseters

    iv_cpuList.push_back(iv_masterCpu);

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
            disableInterruptPresenter(pir);
        }
    }
    TRACFCOMP(g_trac_intr,INFO_MRK,"INTR is shutdown");
}

//----------------------------------------------------------------------------

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
             DEVICE_SCOM_ADDRESS(PSIHB_ISRN_REG_t::PSIHB_ISRN_REG)
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
             DEVICE_SCOM_ADDRESS(PSIHB_ISRN_REG_t::PSIHB_ISRN_REG)
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
                    // reset bit PE_IRSN_RX
                    reg &= ~((1ull << (63-PE_IRSN_RX)));
                    break;

                case INTR_DOWNSTREAM:
                    // reset bit PE_IRSN_TX
                    reg &= ~((1ull << (63-PE_IRSN_TX)));
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
        //interrupts should be pending from this unit.
        if(i_rx_tx == INTR_UPSTREAM)
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

//----------------------------------------------------------------------------

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


//----------------------------------------------------------------------------

errlHndl_t IntrRp::hw_disableIntrMpIpl()
{
    errlHndl_t err = NULL;
    do
    {
        TARGETING::TargetHandleList procChips;
        getAllChips(procChips, TYPE_PROC);

        TARGETING::TargetHandleList procCores;
        getAllChiplets(procCores, TYPE_CORE);

        // Disable upstream intr routing on all processor chips
        for(TARGETING::TargetHandleList::iterator proc = procChips.begin();
            proc != procChips.end();
            ++proc)
        {
            // disable upstream intr routing
            err = hw_disableRouting(*proc,INTR_UPSTREAM);
            if(err)
            {
                break;
            }
        }
        if(err)
        {
            break;
        }

        // Set interrupt presenter to allow all interrupts
        for(TARGETING::TargetHandleList::iterator 
            core = procCores.begin();
            core != procCores.end();
            ++core)
        {
            const TARGETING::Target * proc = getParentChip(*core);

            FABRIC_CHIP_ID_ATTR chip = proc->getAttr<ATTR_FABRIC_CHIP_ID>();
            FABRIC_NODE_ID_ATTR node = proc->getAttr<ATTR_FABRIC_NODE_ID>();
            CHIP_UNIT_ATTR coreId = 
                (*core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            PIR_t pir(0);
            pir.nodeId = node;
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

        // Now look for interrupts
        bool interrupt_found = false;
        size_t retryCount = 10;

        do
        {
            interrupt_found = false;
            nanosleep(0,1000000);   // 1 ms

            for(TARGETING::TargetHandleList::iterator 
                core = procCores.begin();
                core != procCores.end();
                ++core)
            {
                const TARGETING::Target * proc = getParentChip(*core);

                FABRIC_CHIP_ID_ATTR chip = 
                    proc->getAttr<ATTR_FABRIC_CHIP_ID>();
                FABRIC_NODE_ID_ATTR node = 
                    proc->getAttr<ATTR_FABRIC_NODE_ID>();
                CHIP_UNIT_ATTR coreId = 
                    (*core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                PIR_t pir(0);
                pir.nodeId = node;
                pir.chipId = chip;
                pir.coreId = coreId;

                size_t threads = cpu_thread_count();
                for(size_t thread = 0; thread < threads; ++thread)
                {
                    pir.threadId = thread;
                    uint64_t xirrAddr = iv_baseAddr +
                        cpuOffsetAddr(pir) + XIRR_RO_OFFSET;
                    uint32_t * xirrPtr = 
                        reinterpret_cast<uint32_t*>(xirrAddr);
                    uint32_t xirr = *xirrPtr & 0x00FFFFFF;
                    if(xirr) // pending interrupt
                    {
                        // Found pending interrupt!
                        interrupt_found = true;

                        TRACFCOMP(g_trac_intr,
                                  ERR_MRK
                                  "Pending interrupt found on MPIPL."
                                  " CpuId:0x%x XIRR:0x%x",
                                  pir.word,
                                  xirr);
                        // Signal EOI - read then write xirr value
                        ++xirrPtr;        // move to RW XIRR reg
                        volatile uint32_t xirr_rw = *xirrPtr;
                        *xirrPtr = xirr_rw;
                        --xirrPtr;      // back to RO XIRR reg
                    }
                }
            }
        } while(interrupt_found == true && --retryCount != 0);

        if(interrupt_found && (retryCount == 0))
        {
            // traces above should identify stuck interrupt
            INITSERVICE::doShutdown(INTR::RC_PERSISTANT_INTERRUPTS);
        }

        // Disable all interrupt presenters
        for(TARGETING::TargetHandleList::iterator 
            core = procCores.begin();
            core != procCores.end();
            ++core)
        {
            const TARGETING::Target * proc = getParentChip(*core);

            FABRIC_CHIP_ID_ATTR  chip = proc->getAttr<ATTR_FABRIC_CHIP_ID>();
            FABRIC_NODE_ID_ATTR node = proc->getAttr<ATTR_FABRIC_NODE_ID>();
            CHIP_UNIT_ATTR coreId =
                (*core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            PIR_t pir(0);
            pir.nodeId = node;
            pir.chipId = chip;
            pir.coreId = coreId;

            size_t threads = cpu_thread_count();
            for(size_t thread = 0; thread < threads; ++thread)
            {
                pir.threadId = thread;
                disableInterruptPresenter(pir);
            }
        }

        // disable downstream routing and clean up IRSN regs
        for(TARGETING::TargetHandleList::iterator proc = procChips.begin();
            proc != procChips.end();
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
        }
        if(err)
        {
            break;
        }
    } while(0);
    return err;
}

void IntrRp::cleanCheck()
{
    TARGETING::TargetHandleList procCores;
    getAllChiplets(procCores, TYPE_CORE);

    for(TARGETING::TargetHandleList::iterator 
        core = procCores.begin();
        core != procCores.end();
        ++core)
    {
        const TARGETING::Target * proc = getParentChip(*core);

        FABRIC_CHIP_ID_ATTR chip = proc->getAttr<ATTR_FABRIC_CHIP_ID>();
        FABRIC_NODE_ID_ATTR node = proc->getAttr<ATTR_FABRIC_NODE_ID>();
        CHIP_UNIT_ATTR coreId = 
            (*core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();

        PIR_t pir(0);
        pir.nodeId = node;
        pir.chipId = chip;
        pir.coreId = coreId;

        size_t threads = cpu_thread_count();
        for(size_t thread = 0; thread < threads; ++thread)
        {
            pir.threadId = thread;
            uint64_t xirrAddr =
                cpuOffsetAddr(pir) + iv_baseAddr + XIRR_RO_OFFSET;
            uint32_t * xirrPtr = reinterpret_cast<uint32_t*>(xirrAddr);
            uint32_t xirr = (*xirrPtr) & 0x00FFFFFF; // mask off CPPR

            if(xirr != 0)
            {
                // mbox is not available at this point.
                // errl is not functional at this point.
                // This is probably a bug in SIMICS or FSP or HARDWARE
                TRACFCOMP(g_trac_intr, ERR_MRK
                          "Unexpected early interrupt on non-mpipl path."
                          " xirr = %x",
                          xirr);
                assert(xirr == 0);
            }
        }
    }
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

errlHndl_t INTR::enablePsiIntr(TARGETING::Target * i_target)
{
    errlHndl_t err = NULL;
    msg_q_t intr_msgQ = msg_q_resolve(VFS_ROOT_MSG_INTR);
    if(intr_msgQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_INTR_ENABLE_PSI_INTR;
        msg->data[0] = reinterpret_cast<uint64_t>(i_target);

        msg_sendrecv(intr_msgQ, msg);

        err = reinterpret_cast<errlHndl_t>(msg->data[1]);
        msg_free(msg);
    }
    else
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        INTR::MOD_INTR_ENABLE_PSI_INTR
         * @reasoncode      INTR::RC_RP_NOT_INITIALIZED
         * @userdata1       MSG_INTR_ENABLE_PSI_INTR
         * @userdata2       0
         *
         * @devdesc         Interrupt resource provider not initialized yet.
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,      // severity
             INTR::MOD_INTR_ENABLE_PSI_INTR,        // moduleid
             INTR::RC_RP_NOT_INITIALIZED,           // reason code
             static_cast<uint64_t>(MSG_INTR_ENABLE_PSI_INTR),
             0
            );
    }
    return err;
}

