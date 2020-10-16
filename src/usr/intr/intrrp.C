/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/intr/intrrp.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#include <string.h>
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
#include <arch/pvrformat.H>
#include <util/utilmbox_scratch.H>
#include <util/align.H>
#include <errl/errludprintk.H>
#include <util/misc.H>

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

errlHndl_t IntrRp::resetIntpForMpipl()
{
    errlHndl_t err = NULL;
    do{
        TARGETING::TargetHandleList l_funcProcs;

        TARGETING::Target* masterProc = NULL;
        TARGETING::targetService().masterProcChipTargetHandle( masterProc );

        getAllChips(l_funcProcs, TYPE_PROC);

        //Need to make sure we have all of the functional procs in iv_chipList
        for(const auto & l_procChip : l_funcProcs)
        {
            //make sure it is not the master, as master has already been added
            if (l_procChip != masterProc)
            {
                intr_hdlr_t* l_procIntrHdlr = new intr_hdlr_t(l_procChip);
                TRACFCOMP(g_trac_intr, "IntrRp::resetIntpForMpipl() Adding slave proc %lx to list of chips.", get_huid(l_procChip));
                iv_chipList.push_back(l_procIntrHdlr);
                // Set the common Interrupt BAR Scom Registers for the proc
                err = setCommonInterruptBARs(l_procIntrHdlr);
                if (err)
                {
                    TRACFCOMP(g_trac_intr, "IntrRp::resetIntpForMpipl() Setting common interrupt Bars on proc %lx.", get_huid(l_procChip));
                    break;
                }
            }
        }

        //Break if there was an error in the previous for-loop
        if(err)
        {
            break;
        }

        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);
        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_existing_image = 0;
        hb_existing_image = sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

        if (hb_existing_image == 0)
        {
            //single node system so do nothing
            TRACDCOMP( g_trac_intr,
              "IntrRp::resetIntpForMpipl() called on a single node system, skip INTRP sync steps");
        }
        else
        {
            TRACFCOMP(g_trac_intr,
               "IntrRp::resetIntpForMpipl() Synchronize multi-node interrupt enablement");

            // MPIPL Step 1 -- Set the ESB State to Off (0x1) for the LSI SB
            //    EOI Page This is the 4th page in the IC_BAR. View the P9
            //    Interrupt Workbook section 5.1 to find info on this page
            disableLsiInterrupts();

            // Step 2 -- Set bit 0 of Interrupt Control Register
            //     to 1 to enable LSI mode
            for(ChipList_t::iterator targ_itr = iv_chipList.begin();
                                targ_itr != iv_chipList.end(); ++targ_itr)
            {
                PSIHB_SW_INTERFACES_t * l_psihb_ptr =
                                        (*targ_itr)->psiHbBaseAddr;
                l_psihb_ptr->icr =
                         (l_psihb_ptr->icr | PSI_BRIDGE_INTP_STATUS_CTL_ENABLE);
            }

            // Step 3 -- Confirm all other nodes have
            //   completed steps 1+2 above before the rest
            //   of the initialization sequence is completed
            err = syncNodes(INTR_MPIPL_INIT_COMPLETE);
        }

        if (err)
        { break; }

        TRACFCOMP(g_trac_intr, "IntrRp::resetIntpForMpipl() Masking all interrupt sources.");
        //Mask any future interrupts to avoid receiving anymore while in the process
        // of resetting the rest of the Interrupt Logic
        err = maskAllInterruptSources();
        if (err)
        {
            TRACFCOMP(g_trac_intr, "IntrRp::resetIntpForMpipl() Error while masking all interrupt sources.");
            break;
        }

        // Clear out the PC registers that did not get properly cleared during
        // the SBE steps of MPIPL
        // TODO RTC:215215 re-enable when we get this working in simics
        if(!Util::isSimicsRunning())
        {
            clearIntPcRegs();
        }

        //Reset PSIHB Interrupt Space
        TRACFCOMP(g_trac_intr, "Reset PSIHB Interrupt Space");

        //First reset INTRP logic for slave procs
        for(ChipList_t::iterator targ_itr = iv_chipList.begin();
        targ_itr != iv_chipList.end(); ++targ_itr)
        {
            if (*targ_itr != iv_masterHdlr)
            {
                PSIHB_SW_INTERFACES_t * this_psihb_ptr = (*targ_itr)->psiHbBaseAddr;
                this_psihb_ptr->icr = PSI_BRIDGE_INTP_STATUS_CTL_RESET;
            }
        }

        //Then reset master proc INTRP logic
        PSIHB_SW_INTERFACES_t * this_psihb_ptr = iv_masterHdlr->psiHbBaseAddr;
        this_psihb_ptr->icr = PSI_BRIDGE_INTP_STATUS_CTL_RESET;
        TRACFCOMP(g_trac_intr, "Reset PSIHB INTR Complete");

        //Hostboot routes all interrupts to the master proc. This gets set up during istep 8
        //of a normal IPL but later the Hypervisor will reset the routing. During an mpipl,
        //istep 8 wont get ran so we need to set the routing up now.
        for(ChipList_t::iterator targ_itr = iv_chipList.begin();
        targ_itr != iv_chipList.end(); ++targ_itr)
        {
            if (*targ_itr != iv_masterHdlr)
            {
                TRACDCOMP(g_trac_intr, "IntrRp::resetIntpForMpipl() Setting up LSI Interrupt Routing for proc %lx", get_huid((*targ_itr)->proc));
                routeLSIInterrupts(*targ_itr);
            }
        }

       // Clear out any interrupt related FIRs that might have popped during the MPIPL seqeuence
       err =  clearAllIntFirs();

    }while(0);

    return err;
}


errlHndl_t IntrRp::clearAllIntFirs()
{
    // Per scom definition all of these register will be cleared on any read
    // TODO RTC 215215 -- Validate list with PRD Team
    const uint64_t l_fir_reg_addrs_to_read_to_clear[] =
    {
        INT_PC_ERR0_WOF,     INT_PC_ERR0_FATAL,
        INT_PC_ERR0_RECOV,   INT_PC_ERR0_INFO,
        INT_PC_ERR1_WOF,     INT_PC_ERR1_FATAL,
        INT_PC_ERR1_RECOV,   INT_PC_ERR1_INFO,
        INT_VC_WOF_ERR_G0,   INT_VC_WOF_ERR_G1,
        INT_VC_FATAL_ERR_G0, INT_VC_FATAL_ERR_G1,
        INT_VC_RECOV_ERR_G0, INT_VC_RECOV_ERR_G1,
        INT_VC_INFO_ERR_G0,  INT_VC_INFO_ERR_G1,
    };

    // tmp var used to perform reads/writes
    uint64_t l_tmp64;
    errlHndl_t l_err = nullptr;
    size_t l_opSize = sizeof(l_tmp64);

    // Need a list of all of the functional processors for this node
    TARGETING::TargetHandleList l_funcProcs;
    getAllChips(l_funcProcs, TYPE_PROC);

    do{
        // Clear out all of the INT related firs on all functional processor
        for(const auto & l_procChip : l_funcProcs)
        {
            // Loop through and read all of the "read to clear" regs to clear them all
            for (uint8_t i = 0; i < (sizeof(l_fir_reg_addrs_to_read_to_clear) / sizeof(uint64_t)); i++)
            {
                l_err = deviceRead(l_procChip,
                                  &l_tmp64,
                                  l_opSize,
                                  DEVICE_SCOM_ADDRESS(l_fir_reg_addrs_to_read_to_clear[i]) );

                // If get a scom error it is likely no other scoms will work so bail out
                if(l_err)
                {
                    break;
                }
            }

            // If get a scom error it is likely no other scoms will work so bail out
            if(l_err)
            {
                break;
            }

            // In addition to the "read to clear" register we must also clear INT_CQ_WOF
            // and INT_CQ_FIR which need to be written to with 0x0 to clear.
            l_tmp64 = 0x0;
            l_err = deviceWrite(l_procChip,
                                  &l_tmp64,
                                  l_opSize,
                                  DEVICE_SCOM_ADDRESS(INT_CQ_WOF) );

            // If get a scom error it is likely no other scoms will work so bail out
            if(l_err)
            {
                break;
            }

            l_err = deviceWrite(l_procChip,
                                  &l_tmp64,
                                  l_opSize,
                                  DEVICE_SCOM_ADDRESS(INT_CQ_FIR) );

            // If get a scom error it is likely no other scoms will work so bail out
            if(l_err)
            {
                break;
            }
        }
    } while(0);

    return l_err;
}

errlHndl_t  IntrRp::setHbModeOnTctxtCfgReg(intr_hdlr_t * i_procIntrHdlr)
{
    assert(i_procIntrHdlr != nullptr,"BUG! Input interrupt handler pointer "
            "was nullptr");
    auto * const l_procChip = i_procIntrHdlr->proc;
    assert(l_procChip != nullptr,"BUG! proc target was nullptr");

    errlHndl_t l_err = nullptr;
    do{
        uint64_t scom_data = 0;
        size_t   DATA_SIZE = sizeof(scom_data);
        l_err = deviceRead( l_procChip,
                            &scom_data,
                            DATA_SIZE,
                            DEVICE_SCOM_ADDRESS(INT_TCTXT_CFG_SCOM_ADDR) );
        if( l_err)
        {
            break;
        }

        scom_data |= INT_TCTXT_CFG_HB_MODE;

        l_err = deviceWrite(l_procChip,
                            &scom_data,
                            DATA_SIZE,
                            DEVICE_SCOM_ADDRESS(INT_TCTXT_CFG_SCOM_ADDR));
        if( l_err)
        {
            break;
        }

    }while(0);

    return l_err;
}

errlHndl_t IntrRp::_init()
{
    errlHndl_t l_err = nullptr;

    // get the PIR
    // Which ever cpu core this is running on is the MASTER cpu
    // Make master thread 0
    uint32_t cpuid = task_getcpuid();
    iv_masterCpu = cpuid;
    iv_masterCpu.threadId = 0;

    TRACFCOMP(g_trac_intr,"IntrRp::_init() Master cpu topology[%d], "
                          " core[%d], thread[%d]",
              iv_masterCpu.topologyId, iv_masterCpu.coreId,
              iv_masterCpu.threadId);

    iv_IntrRpShutdownRequested = false; // Not shutting down

    // Do the initialization steps on the master proc chip
    // The other proc chips will be setup at a later point
    TARGETING::Target* procTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle( procTarget );

    intr_hdlr_t* l_procIntrHdlr = new intr_hdlr_t(procTarget);
    iv_masterHdlr = l_procIntrHdlr;
    iv_chipList.push_back(l_procIntrHdlr);

    // Set up the IPC message Data area
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != NULL);
    uint64_t hrmor_base = cpu_spr_value(CPU_SPR_HRMOR);

    KernelIpc::ipc_data_area.pir = iv_masterCpu.word;
    KernelIpc::ipc_data_area.hrmor_base = hrmor_base;
    KernelIpc::ipc_data_area.msg_queue_id = IPC_DATA_AREA_CLEAR;

    do
    {
        // Set the Interrupt BAR Scom Registers specific to the master
        l_err = setMasterInterruptBARs(procTarget);

        if (l_err)
        {
            TRACFCOMP(g_trac_intr,
              "IntrRp::_init() Error setting Master Proc Interrupt BARs.");
            break;
        }

        // Set the common Interrupt BAR Scom Registers for the master
        l_err = setCommonInterruptBARs(iv_masterHdlr);

        if (l_err)
        {
            TRACFCOMP(g_trac_intr,
              "IntrRp::_init() Error setting Common Proc Interrupt BARs.");
            break;
        }

        l_err = setHbModeOnTctxtCfgReg(iv_masterHdlr);

        if (l_err)
        {
            TRACFCOMP(g_trac_intr,
                      "IntrRp::_init() Error setting Hostboot Mode bit on in TCTXT_CFG register");
            break;
        }

        // extract the mpipl indicator
        // will still be 0 if attribute does not exist
        uint8_t is_mpipl = 0;
        sys->tryGetAttr<TARGETING::ATTR_IS_MPIPL_HB>(is_mpipl);

        // Extract the last values for IPC data Addresses.
        // will be 00's except for MPIPL, then previous values
        uint64_t l_ipcDataAddrs[MAX_NODES_PER_SYS];
        assert((sys->tryGetAttr<TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>
        (l_ipcDataAddrs)) == true );

        // determine node and
        // ipc data address as seen by a remote node
        uint64_t l_thisNode = 0xa5a5;   // seed with invalid value(s) to
        uint64_t l_remoteAddr = 0x5a5a; // catch missing return values

        set_topology_mode(sys->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_MODE>());
        qryLocalIpcInfo( l_thisNode, l_remoteAddr );

        // validate no change to local if this is an MPIPL
        if (is_mpipl)
        {
            assert( l_ipcDataAddrs[l_thisNode] == l_remoteAddr );
        }

        // update attribute entry for this node
        l_ipcDataAddrs[l_thisNode] = l_remoteAddr;
        sys->setAttr<TARGETING::ATTR_IPC_NODE_BUFFER_GLOBAL_ADDRESS>
        (l_ipcDataAddrs);

        // shadow the IPC addrs where the IPC msg send can reach them
        for ( uint64_t i = 0;
                i < MAX_NODES_PER_SYS;
                i++ )
        {
            uint64_t remoteAddr = l_ipcDataAddrs[i];
            updateRemoteIpcAddr( i, remoteAddr );
        }

        if(is_mpipl)
        {
            TRACFCOMP(g_trac_intr,"Reset interrupt service for MPIPL");
            l_err = resetIntpForMpipl();

            if(l_err)
            {
                TRACFCOMP(g_trac_intr,
                        "Failed to reset interrupt service for MPIPL");
                break;
            }
        }

        //Disable Incoming PSI Interrupts
        TRACDCOMP(g_trac_intr, "IntrRp::_init() Disabling PSI Interrupts");
        uint64_t l_disablePsiIntr = PSI_BRIDGE_INTP_STATUS_CTL_DISABLE_PSI;
        uint64_t size = sizeof(l_disablePsiIntr);
        l_err = deviceWrite(procTarget,
                     &l_disablePsiIntr,
                     size,
                 DEVICE_SCOM_ADDRESS(PSI_BRIDGE_INTP_STATUS_CTL_CLR_SCOM_ADDR));

        if (l_err)
        {
            TRACFCOMP(g_trac_intr,
                             "IntrRp::_init() Error disabling PSI Interrupts.");
            break;
        }

        // Check if we need to run the MPIPL path
        if(is_mpipl)
        {
            // In MPIPL we enable Interrupt before masking sources -- while the
            // system is in this state interupts can get stuck, need to let any
            // interrupts have time to present themselves before we mask things
            TRACFCOMP(g_trac_intr, "IntrRp::_init() Enabling PSIHB Interrupts");
            //Enable PSIHB Interrupts
            l_err = enableInterrupts(l_procIntrHdlr);

            if (l_err)
            {
                TRACFCOMP(g_trac_intr, "IntrRp::_init() Error enabling Interrupts");
                break;
            }


            TRACFCOMP(g_trac_intr, "IntrRp::_init() Masking Interrupts");
            //Mask off all interrupt sources - these will be enabled as SW entities
            // register for specific interrupts via the appropriate message queue
            l_err = maskAllInterruptSources();
            if (l_err)
            {
                TRACFCOMP(g_trac_intr, "IntrRp::_init() Error masking all interrupt sources.");
                break;
            }

            //Route LSI interrupt events over PSIHB instead of local wire
            // This is a HW Bug Workaround for slaves using the PSIHB and
            // the master using the local wire
            routeLSIInterrupts(l_procIntrHdlr);

            enableLsiInterrupts();
        }
        else
        {
            TRACFCOMP(g_trac_intr, "IntrRp::_init() Masking Interrupts");
            //Mask off all interrupt sources - these will be enabled as SW entities
            // register for specific interrupts via the appropriate message queue
            l_err = maskAllInterruptSources();
            if (l_err)
            {
                TRACFCOMP(g_trac_intr, "IntrRp::_init() Error masking all interrupt sources.");
                break;
            }

            //Route LSI interrupt events over PSIHB instead of local wire
            // This is a HW Bug Workaround for slaves using the PSIHB and
            // the master using the local wire
            routeLSIInterrupts(l_procIntrHdlr);

            enableLsiInterrupts();

            TRACFCOMP(g_trac_intr, "IntrRp::_init() Enabling PSIHB Interrupts");
            //Enable PSIHB Interrupts
            l_err = enableInterrupts(l_procIntrHdlr);
            if (l_err)
            {
                TRACFCOMP(g_trac_intr, "IntrRp::_init() Error enabling Interrupts");
                break;
            }
        }

        // Build up list of unregistered LSI sources, at this point no sourced
        // have registered message qs (NOTE: it's more useful to know what is NOT
        // registered rather than what is)
        for(uint8_t i = LSI_FIRST_SOURCE; i < LSI_LAST_SOURCE; i++)
        {
            iv_unregisterdLsiSources.push_back(i);
        }

        // Create the kernel msg queue for external interrupts
        iv_msgQ = msg_q_create();
        msg_intr_q_register(iv_msgQ,
             procTarget->getAttr<TARGETING::ATTR_INT_CQ_TM_BAR_ADDR>());

        // Create a task to handle the messages
        task_create(IntrRp::msg_handler, NULL);

        // Register event to be called on shutdown
        INITSERVICE::registerShutdownEvent(INTR_COMP_ID, iv_msgQ,
                                           MSG_INTR_SHUTDOWN,
                                           INITSERVICE::INTR_PRIORITY);

        //Set value for enabled threads
        uint64_t l_en_threads = get_enabled_threads();
        TRACFCOMP(g_trac_intr, "IntrRp::_init() Threads enabled:"
                                " %lx", l_en_threads);

    } while(0);

    return l_err;
}

void IntrRp::enableLsiInterrupts()
{
    TRACDCOMP(g_trac_intr, "IntrRp:: enableLsiInterrupts() enter");
    //The XIVE HW is expecting these MMIO accesses to come from the
    // core/thread they were setup (master core, thread 0)
    // These functions will ensure this code executes there
    task_affinity_pin();
    task_affinity_migrate_to_master();
    uint64_t * l_lsiEoi = iv_masterHdlr->xiveIcBarAddr;
    l_lsiEoi += XIVE_IC_LSI_EOI_OFFSET;
    l_lsiEoi += (ESB_RESET_OFFSET / sizeof(uint64_t));

    volatile uint64_t l_eoiRead = *l_lsiEoi;
    TRACFCOMP(g_trac_intr, "IntrRp:: enableLsiInterrupts() read 0x%lx from pointer %p", l_eoiRead, l_lsiEoi);
    //MMIO Complete, rest of code can run on any thread
    task_affinity_unpin();
    TRACDCOMP(g_trac_intr, "IntrRp:: enableLsiInterrupts() exit");
}

void IntrRp::disableLsiInterrupts()
{
    TRACDCOMP(g_trac_intr, "IntrRp:: disableLsiInterrupts() enter");
    //The XIVE HW is expecting these MMIO accesses to come from the
    // core/thread they were setup (master core, thread 0)
    // These functions will ensure this code executes there
    task_affinity_pin();
    task_affinity_migrate_to_master();
    uint64_t * l_lsiEoi = iv_masterHdlr->xiveIcBarAddr;
    l_lsiEoi += XIVE_IC_LSI_EOI_OFFSET;
    l_lsiEoi += (ESB_OFF_OFFSET / sizeof(uint64_t));
    volatile uint64_t l_eoiRead = *l_lsiEoi;
    TRACFCOMP(g_trac_intr, "IntrRp:: disableLsiInterrupts() read 0x%lx from pointer %p", l_eoiRead, l_lsiEoi);
    //MMIO Complete, rest of code can run on any thread
    task_affinity_unpin();
    TRACDCOMP(g_trac_intr, "IntrRp:: disableLsiInterrupts() exit");
}

/**
 * Clear INT_PC registers that didn't get cleared by the HW reset
 * during the SBE steps of the MPIPL
 */
void IntrRp::clearIntPcRegs()
{
    TRACDCOMP(g_trac_intr, "IntrRp:: clearIntPcRegs() enter");
    //The XIVE HW is expecting these MMIO accesses to come from the
    // core/thread they were setup (master core, thread 0)
    // These functions will ensure this code executes there
    task_affinity_pin();
    task_affinity_migrate_to_master();

    uint64_t * l_vsdTableAddr =
        iv_masterHdlr->xiveIcBarAddr + XIVE_IC_PC_VSD_TABLE_ADDR_OFFSET;
    *l_vsdTableAddr = 0x0000000000000000;

    uint64_t * l_vsdTableData =
        iv_masterHdlr->xiveIcBarAddr + XIVE_IC_PC_VSD_TABLE_DATA_OFFSET;
    *l_vsdTableData = 0x0000000000000000;

    uint64_t * l_blockModeAddr =
        iv_masterHdlr->xiveIcBarAddr + XIVE_IC_PC_VPD_BLOCK_MODE_OFFSET;
    *l_blockModeAddr = 0x0000000000000000;

    //MMIO Complete, rest of code can run on any thread
    task_affinity_unpin();
    TRACDCOMP(g_trac_intr, "IntrRp:: clearIntPcRegs() exit");
}


void IntrRp::acknowledgeInterrupt()
{

    //The XIVE HW is expecting these MMIO accesses to come from the
    // core/thread they were setup (master core, thread 0)
    // These functions will ensure this code executes there
    task_affinity_pin();
    task_affinity_migrate_to_master();

    //A uint16 store from the Acknowledge Hypervisor Interrupt
    //  offset in the Thread Management BAR space signals
    //  the interrupt is acknowledged
    volatile uint16_t * l_ack_int_ptr = (uint16_t *)iv_intCqTmBarAddress;
    l_ack_int_ptr += ACK_HYPERVISOR_INT_REG_OFFSET;
    eieio();
    uint16_t l_ackRead = *l_ack_int_ptr;

    //MMIO Complete, rest of code can run on any thread
    task_affinity_unpin();

    TRACFCOMP(g_trac_intr, "IntrRp::acknowledgeInterrupt(), read result: %16x", l_ackRead);
}

void IntrRp::disablePsiInterrupts(intr_hdlr_t* i_proc)
{
    //Disable Incoming PSI Interrupts
    PSIHB_SW_INTERFACES_t * l_psihb_ptr = i_proc->psiHbBaseAddr;

    //Clear bit to disable PSI CEC interrupts
    l_psihb_ptr->psihbcr = (l_psihb_ptr->psihbcr & ~PSI_BRIDGE_INTP_STATUS_CTL_DISABLE_PSI);
}

errlHndl_t IntrRp::resetIntUnit(intr_hdlr_t* i_proc)
{
    errlHndl_t l_err = NULL;

    uint64_t l_barValue = XIVE_RESET_POWERBUS_QUIESCE_ENABLE;
    uint64_t size = sizeof(l_barValue);
    uint32_t l_addr = XIVE_RESET_INT_CQ_RST_CTL_SCOM_ADDR;

    TARGETING::Target* procTarget = i_proc->proc;

    do {
        //Disable the PSI CEC interrupts
        disablePsiInterrupts(i_proc);

        //Use HW-based XIVE Reset
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

        //A short amount of time is needed to let the powerbus quiesce
        // before the next step in the reset can occur, so do a short
        // polling loop for the indicator the power bus has been quiesced
        uint64_t l_quiesceTimeout = XIVE_RESET_POWERBUS_QUIESCE_TIMEOUT;
        uint64_t l_timeWaited = 0;
        uint64_t reg = 0x0;

        do
        {
            if (l_timeWaited >= l_quiesceTimeout)
            {
                TRACFCOMP(g_trac_intr, "IntrRp::resetIntUnit() - Timeout "
                              "waiting for PowerBus to quiesce");
                // @errorlog tag
                // @errortype       ERRL_SEV_UNRECOVERABLE
                // @moduleid        INTR::MOD_INTRRP_RESETINTUNIT
                // @reasoncode      INTR::RC_XIVE_PBUS_QUIESCE_TIMEOUT
                // @userdata1       XIVE Powerbus Scom Register Address
                // @userdata2       XIVE Powerbus Scom Register Data
                //
                // @devdesc         Timeout waiting for Powerbus to Quiesce
                //
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

        //Additional settings for fused mode
        //Needed because the HW XIVE reset clears too much HW state
        if (is_fused_mode())
        {
            //Do a Read-Modify-Write on INT Thread Context Register
            //setting the FUSED_CORE_EN bit as the 'modify' part
            uint64_t l_int_tctxt_reg = 0x0;
            l_err = deviceRead(procTarget,
                                &l_int_tctxt_reg,
                                size,
                                DEVICE_SCOM_ADDRESS(INT_TCTXT_CFG_SCOM_ADDR));

            if (l_err)
            {
                TRACFCOMP(g_trac_intr, "Error reading the INT_TCTXT_CFG(%lx) scom register",
                          INT_TCTXT_CFG_SCOM_ADDR);
                break;
            }

            l_int_tctxt_reg |= INT_TCTXT_CFG_FUSE_CORE_EN;

            l_err = deviceWrite(procTarget,
                                &l_int_tctxt_reg,
                                size,
                                DEVICE_SCOM_ADDRESS(INT_TCTXT_CFG_SCOM_ADDR));
            if (l_err)
            {
                TRACFCOMP(g_trac_intr, "Error writing %lx  the INT_TCTXT_CFG(%lx) scom register",
                          l_int_tctxt_reg, INT_TCTXT_CFG_SCOM_ADDR );
                break;
            }
        }

    } while (0);

    if (l_err)
    {
        TRACFCOMP(g_trac_intr, "Error: Interrupt Engine not reset successfully");
    }

    return l_err;
}

errlHndl_t IntrRp::disableInterrupts(intr_hdlr_t *i_proc)
{
    errlHndl_t l_err = NULL;

    do
    {
        //Disable PSI CEC interrupts
        disablePsiInterrupts(i_proc);

        //The XIVE HW is expecting these MMIO accesses to come from the
        // core/thread they were setup (master core, thread 0)
        // These functions will ensure this code executes there
        task_affinity_pin();
        task_affinity_migrate_to_master();

        //Pull thread context to register - View Section 4.4.4.15 of the
        // XIVE spec. Doing a 1b MMIO read will clear the cams VT bit.
        volatile uint8_t * l_pull_thread_ptr = (uint8_t *)iv_intCqTmBarAddress;
        l_pull_thread_ptr += PULL_THREAD_CONTEXT_OFFSET;
        eieio();

        uint8_t l_ackRead = *l_pull_thread_ptr;
        TRACFCOMP(g_trac_intr, "IntrRp::disableInterrupts(),"
                    " pull thread context read result: %8x", l_ackRead);
        eieio();
        sync();
        TRACFCOMP(g_trac_intr, INFO_MRK"LSI Mode inactive (cams_vt)");

        //MMIO Complete, rest of code can run on any thread
        task_affinity_unpin();

        // Unset Physical Thread Enable register in the PC space for the master
        //  core - Simply reset both regs.
        uint64_t * l_ic_ptr = i_proc->xiveIcBarAddr;
        l_ic_ptr += XIVE_IC_BAR_INT_PC_MMIO_REG_OFFSET;

        volatile XIVE_IC_THREAD_CONTEXT_t * l_xive_ic_ptr =
                reinterpret_cast<XIVE_IC_THREAD_CONTEXT_t *>(l_ic_ptr);

        TRACFCOMP(g_trac_intr, INFO_MRK"IntrRp::disableInterrupts() "
                    " Reset phys_thread_enable0_reg: 0x%016lx", 0x0);
        l_xive_ic_ptr->phys_thread_enable0_set = 0x0;

        TRACFCOMP(g_trac_intr, INFO_MRK"IntrRp::disableInterrupts() "
                    " Reset phys_thread_enable1_reg: 0x%016lx", 0x0);
        l_xive_ic_ptr->phys_thread_enable1_set = 0x0;

    } while (0);

    return l_err;
}

errlHndl_t IntrRp::enableInterrupts(intr_hdlr_t *i_proc)
{
    errlHndl_t err = NULL;
    PSIHB_SW_INTERFACES_t * l_psihb_ptr = i_proc->psiHbBaseAddr;

   do
    {
        //Set bit to route interrupts to CEC instead of FSP
        l_psihb_ptr->psihbcr =
                    (l_psihb_ptr->psihbcr | PSI_BRIDGE_ENABLE_CEC_INTERRUPT);

        //Set bit to enable PSIHB Interrupts
        l_psihb_ptr->icr =
                      (l_psihb_ptr->icr | PSI_BRIDGE_INTP_STATUS_CTL_ENABLE);

        // This XIVE register supports both Normal and Fused core, but Normal
        // Core mode can be safely assumed and the proper bits will be set.
        //
        //Set Physical Thread Enable register in the PC space for the master
        //  core
        PIR_t l_masterPir(task_getcpuid());
        uint64_t l_masterCoreID = l_masterPir.coreId;
        uint64_t l_masterThreadID = l_masterPir.threadId;

        uint64_t * l_ic_ptr = i_proc->xiveIcBarAddr;
        l_ic_ptr += XIVE_IC_BAR_INT_PC_MMIO_REG_OFFSET;

        volatile XIVE_IC_THREAD_CONTEXT_t * l_xive_ic_ptr =
                reinterpret_cast<XIVE_IC_THREAD_CONTEXT_t *>(l_ic_ptr);

        TRACFCOMP(g_trac_intr, INFO_MRK"IntrRp::enableInterrupts() "
                    "Set Physical Thread Enable for master core: %lx, "
                    "master thread: %lx ",
                    l_masterCoreID,
                    l_masterThreadID);

        //Normal Cores 0-15 are handled in thread enable0 reg
        if (l_masterCoreID < 16)
        {
            uint64_t l_enable =
              (XIVE_IC_THREAD0_ENABLE >> ((4*l_masterCoreID)+l_masterThreadID));
            TRACFCOMP(g_trac_intr, INFO_MRK"IntrRp::enableInterrupts() "
                    " Set phys_thread_enable0_reg: 0x%016lx", l_enable);
            l_xive_ic_ptr->phys_thread_enable0_set = l_enable;
        }
        else //Normal Cores 16-23 are handled in thread enable1 reg
        {
            //Shift offset as a second register is used for cores 16-23
            // so core 16 in reg 1 is equivalent to core 0 in reg0
            l_masterCoreID = l_masterCoreID - 16;
            uint64_t l_enable =
              (XIVE_IC_THREAD0_ENABLE >> ((4*l_masterCoreID)+l_masterThreadID));
            TRACFCOMP(g_trac_intr, INFO_MRK"IntrRp::enableInterrupts() "
                    " Set phys_thread_enable1_reg: 0x%016lx", l_enable);
            l_xive_ic_ptr->phys_thread_enable1_set = l_enable;
        }
        eieio();

        //Set bit to configure LSI mode for HB cec interrupts
        volatile XIVE_IVPE_THREAD_CONTEXT_t * this_ivpe_ptr =
          reinterpret_cast<XIVE_IVPE_THREAD_CONTEXT_t *> (iv_intCqTmBarAddress);
        this_ivpe_ptr->cams_vt = XIVE_IVPE_QW3_LSI_ENABLE;
        eieio();

        TRACFCOMP(g_trac_intr, INFO_MRK"LSI Mode active (cams_vt)");
   } while (0);

    //TODO RTC 150260 - Determine if any error checking can be done above, if so
    //  create/return errorlogs. If not, change the funciton return type.
    return err;
}

void IntrRp::routeLSIInterrupts(intr_hdlr_t *i_proc)
{
    PSIHB_SW_INTERFACES_t * l_psihb_ptr = i_proc->psiHbBaseAddr;

    //Route LSI Trigger Page to Master Proc Chip by setting the
    // ESB Notification Address register on the PSIHB
    uint64_t l_baseAddr =
       iv_masterHdlr->proc->getAttr<TARGETING::ATTR_XIVE_CONTROLLER_BAR_ADDR>();

    TRACFCOMP(g_trac_intr, INFO_MRK"Routing LSI Trigger page to Master Proc"
              " chip by setting esb notification address to:%lx",
              l_baseAddr + XIVE_IC_ESB_LSI_TRIGGER_PAGE_OFFSET);

    //Set notify to base address, then set valid bit
    uint64_t l_notifyValue = l_baseAddr + XIVE_IC_ESB_LSI_TRIGGER_PAGE_OFFSET;
    l_psihb_ptr->esbnotifyaddr = l_notifyValue;
    l_psihb_ptr->esbnotifyaddr = l_notifyValue + PSI_BRIDGE_ESB_NOTIFY_VALID;

    //Enable Interrupt routing to trigger page written above by setting
    // the Interrupt Control Register to all 0's
    l_psihb_ptr->icr = PSI_BRIDGE_ENABLE_LSI_INTR_REMOTE;
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
                    //ext_intr_t type = NO_INTERRUPT;
                    //Keep a list of all pending interrupts and which proc the
                    //  interrupt condition was seen on
                    std::vector< std::pair<intr_hdlr_t, ext_intr_t> >
                                                                l_pendingIntr;
                    uint32_t ackResponse =
                                        static_cast<uint32_t>(msg->data[0]>>32);
                    TRACDCOMP(g_trac_intr, "IntrRp::msgHandler(): ackResponse = 0x%x", ackResponse);

                    //Check if LSI-Based Interrupt
                    if ((ackResponse & LSI_INTERRUPT) == LSI_INTERRUPT)
                    {
                        TRACFCOMP(g_trac_intr, "IntrRp::msgHandler(): LSI Interrupt Detected");

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

                        //Read Interrupt Condition(s) and route to appropriate
                        //interrupt handlers
                        handleExternalInterrupt();
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
            case MSG_INTR_IPC:
                {
                    errlHndl_t l_err = NULL;
                    uint64_t l_xirr_pir = msg->data[0];

                    TRACFCOMP(g_trac_intr,INFO_MRK
                              "IntrRp::msgHandler Doorbell IPC msg received"
                                  " for %x", l_xirr_pir);

                    // Now handle any IPC messages
                    // If something is registered for the IPC msg
                    Registry_t::iterator r = iv_registry.find(ISN_INTERPROC);
                    if(r != iv_registry.end() &&
                       (KernelIpc::ipc_data_area.msg_queue_id !=
                       IPC_DATA_AREA_CLEAR) &&
                        (KernelIpc::ipc_data_area.msg_queue_id !=
                         IPC_DATA_AREA_LOCKED))
                    {
                        msg_q_t msgQ = r->second.msgQ;

                        msg_t * rmsg = msg_allocate();
                        rmsg->type = r->second.msgType;
                        rmsg->data[0] = ISN_INTERPROC;
                        rmsg->data[1] = l_xirr_pir;
                        rmsg->extra_data = NULL;

                        int rc = msg_sendrecv_noblk(msgQ, rmsg, iv_msgQ);
                        if(rc)
                        {
                            TRACFCOMP(g_trac_intr,ERR_MRK
                                      "IPC message received, but could "
                                      "not send message to the registered "
                                      "handler. Ignoring it. rc = %d",
                                      rc);
                        }
                    }
                    else if(KernelIpc::ipc_data_area.msg_queue_id ==
                              IPC_DATA_AREA_CLEAR ||
                            KernelIpc::ipc_data_area.msg_queue_id ==
                              IPC_DATA_AREA_LOCKED)
                    {
                        TRACFCOMP(g_trac_intr,ERR_MRK
                                   "IPC message received but data area is in"
                                   " an invalid state. msg_queue_id = 0x%lx",
                                   KernelIpc::ipc_data_area.msg_queue_id);
                        /*@ errorlog tag
                         * @errortype       ERRL_SEV_INFORMATIONAL
                         * @moduleid        INTR::MOD_INTRRP_IPC
                         * @reasoncode      INTR::RC_IPC_DATA_INVALID
                         * @userdata1       IPC Data Area MSG Queue ID
                         * @userdata2       PIR
                         * @devdesc         Error encountered routing IPC
                         *                  message
                         */
                        l_err = new ERRORLOG::ErrlEntry
                            (
                             ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
                             INTR::MOD_INTRRP_IPC,             // moduleid
                             INTR::RC_IPC_DATA_INVALID,        // reason code
                             KernelIpc::ipc_data_area.msg_queue_id,
                             l_xirr_pir
                            );
                        //Add the printk to give more data as to how we got
                        // in this situation
                        ERRORLOG::ErrlUserDetailsPrintk().addToLog(l_err);
                    }
                    else
                    {
                        TRACFCOMP(g_trac_intr,ERR_MRK
                           "IPC Message received type but nothing registered "
                           "to handle it. Ignoring it.");
                    }

                    // Always acknowlege msg to kernel
                    // kernel expects rc in data[1]
                    // rc of 0 means a successful return
                    msg->data[1] = 0;
                    msg_respond(iv_msgQ, msg);

                    if (l_err)
                    {
                        l_err->collectTrace(INTR_COMP_NAME, 256);
                        errlCommit(l_err, INTR_COMP_ID);
                    }
                }
                break;
            case MSG_INTR_EOI:
                {
                    // Use standrard EOI (End of Interrupt) sequence
                    if(msg->data[0] != ISN_INTERPROC)
                    {
                        uint64_t intSource = msg->data[0];
                        PIR_t l_pir = msg->data[1];
                        //The physical HW EOI is issued as the defect is
                        // discovered. At this point we just need to remove
                        // the pending interrupt obj and unmasking the
                        // interrupt source to properly handle new ints
                        completeInterruptProcessing(intSource, l_pir);
                    }
                    msg_free(msg);
                }
                break;

            case MSG_INTR_REGISTER_MSGQ:
                {

                    msg_q_t l_msgQ = reinterpret_cast<msg_q_t>(msg->data[0]);
                    uint64_t l_type = msg->data[1];
                    ext_intr_t l_intr_type = static_cast<ext_intr_t>(l_type & SOURCE_MASK);

                    errlHndl_t err = registerInterruptXISR(l_msgQ, l_type >> 32,
                                                                   l_intr_type);
                    if (err)
                    {
                        TRACFCOMP(g_trac_intr,
                            "IntrRp::msgHandler MSG_INTR_REGISTER_MSGQ error "
                            "registering handler for interrupt type: %lx",
                            l_intr_type);
                    }
                    // Only worry about masking if it is an LSI source
                    else if( l_intr_type >= LSI_FIRST_SOURCE &&
                             l_intr_type < LSI_LAST_SOURCE )
                    {
                        // Source is now registered so remove it from list
                        // NOTE: registerInterruptXISR check above will ensure
                        //  that it has not been registered before.
                        iv_unregisterdLsiSources.remove(l_intr_type);
                        //Enable (aka unmask) Interrupts for the source being
                        // registered for
                        for(ChipList_t::iterator targ_itr = iv_chipList.begin();
                             targ_itr != iv_chipList.end(); ++targ_itr)
                        {
                            err = unmaskInterruptSource(l_intr_type, *targ_itr);
                            if (err)
                            {
                                TRACFCOMP(g_trac_intr,
                                    "IntrRp::msgHandler MSG_INTR_REGISTER_MSGQ "
                                    "error unmasking interrupt type: %lx",
                                    l_intr_type);
                                errlCommit(err, INTR_COMP_ID);
                                break;
                            }
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
                    errlHndl_t err;
                    ext_intr_t l_type = static_cast<ext_intr_t>(msg->data[0]);
                    ext_intr_t l_intr_type = static_cast<ext_intr_t>(l_type & SOURCE_MASK);


                    if (l_type >= LSI_FIRST_SOURCE &&
                        l_type < LSI_LAST_SOURCE)
                    {
                        if(std::find(iv_unregisterdLsiSources.begin(),
                                    iv_unregisterdLsiSources.end(),
                                    l_intr_type) == iv_unregisterdLsiSources.end())
                        {
                            // Source is now unregistered so add it to list
                            iv_unregisterdLsiSources.push_back(l_intr_type);
                        }
                        else
                        {
                            TRACFCOMP(g_trac_intr,
                                      "IntrRp::msgHandler MSG_INTR_UNREGISTER_MSGQ"
                                      " Attempted to unregisted source %d but is was not registered",
                                      l_intr_type);
                            // Print unregistered sources
                            for (const auto& l_lsi_source : iv_unregisterdLsiSources)
                            {
                                TRACFCOMP(g_trac_intr,
                                          "IntrRp::msgHandler MSG_INTR_UNREGISTER_MSGQ"
                                          " This LSI source is not registered : %d",
                                          l_lsi_source);
                            }
                            /*@ errorlog tag
                            * @errortype       ERRL_SEV_INFORMATIONAL
                            * @moduleid        INTR::MOD_INTRRP_UNREGISTERINTERRUPT
                            * @reasoncode      INTR::RC_SOURCE_NOT_REGISTERED
                            * @userdata1       LSI Interrupt Source to Unregister
                            * @userdata2       Number of unregistered LSI sources
                            * @devdesc         Attempted to unregsister a source that
                            *                  is not registered
                            * @custdesc        Error hanlding processor interupts
                            */
                            err = new ERRORLOG::ErrlEntry
                                    (
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,        // severity
                                    INTR::MOD_INTRRP_UNREGISTERINTERRUPT, // moduleid
                                    INTR::RC_SOURCE_NOT_REGISTERED,       // reason code
                                    l_intr_type,
                                    iv_unregisterdLsiSources.size(),
                                    true); // sw callout
                            errlCommit(err,INTR_COMP_ID);
                        }

                        // Mask the interrupt source prior to unregistering
                        err = maskInterruptSource(l_intr_type);
                        if(err)
                        {
                            TRACFCOMP(g_trac_intr,
                                "IntrRp::msgHandler MSG_INTR_UNREGISTER_MSGQ"
                                " error masking interrupt type: %lx",
                                l_intr_type);
                            errlCommit(err,INTR_COMP_ID);
                        }
                    }

                    // Unregister for this source and return rc in response
                    msg_q_t msgQ = unregisterInterruptXISR(l_type);
                    msg->data[1] = reinterpret_cast<uint64_t>(msgQ);
                    msg_respond(iv_msgQ, msg);
                }
                break;
            case MSG_INTR_ENABLE:
                {
                    errlHndl_t err = NULL;
                    for(ChipList_t::iterator targ_itr = iv_chipList.begin();
                             targ_itr != iv_chipList.end(); ++targ_itr)
                    {
                        err = enableInterrupts(*targ_itr);
                        if (err)
                        {
                            break;
                        }
                    }
                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    msg_respond(iv_msgQ,msg);
                }
                break;

            case MSG_INTR_DISABLE:
                {
                    errlHndl_t err = disableInterrupts(iv_masterHdlr);
                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    msg_respond(iv_msgQ,msg);
                }
                break;
            case MSG_INTR_ENABLE_PSI_INTR:
                {
                    TRACFCOMP(g_trac_intr, "MSG_INTR_ENABLE_PSI_INTR received");
                    TARGETING::Target * target =
                        reinterpret_cast<TARGETING::Target *>(msg->data[0]);
                    errlHndl_t err = enableSlaveProcInterrupts(target);
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

                    TRACFCOMP(g_trac_intr,"Add CPU topology[%d],"
                              "core[%d], thread[%d]",
                              pir.topologyId, pir.coreId,
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
                    TRACDCOMP(g_trac_intr, "IntrRp::msgHandler() CPU Timeout Message received for: %x",
                              pir.word);

                    if(   !Util::requiresSecondaryCoreWorkaround()
                       && iv_ipisPending.count(pir))
                    {
                        size_t count = msg->data[1];
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
            case MSG_INTR_DRAIN_QUEUE:
                {
                    //The purpose of this message is allow the
                    //intrp to drain its message queue of pending EOIs
                    //just respond
                    msg_respond(iv_msgQ,msg);
                }
                break;
            case MSG_INTR_DUMP:
                {
                    // Run the functions that dump out
                    // interrupt info to slow buffer
                    printEsbStates();
                    printLSIInfo();
                    printPSIHBInfo();
                    msg_free(msg); // async message
                }
                break;

            default:
                msg->data[1] = -EINVAL;
                msg_respond(iv_msgQ, msg);
        }
    }
}

errlHndl_t IntrRp::sendPsiHbEOI(intr_hdlr_t* i_proc, uint64_t& i_intSource)
{
     errlHndl_t l_err = NULL;

    //The XIVE HW is expecting these MMIO accesses to come from the
    // core/thread they were setup (master core, thread 0)
    // These functions will ensure this code executes there
    task_affinity_pin();
    task_affinity_migrate_to_master();

    //Send an EOI to the Power bus using the PSIHB ESB Space
    //This is done with a read to the page specific to the interrupt source.
    //Each interrupt source gets one page
    uint64_t * l_psiHbPowerBusEoiAddr =
          i_proc->psiHbEsbBaseAddr + ((i_intSource)*PAGE_SIZE)/sizeof(uint64_t);

    uint64_t eoiRead = *l_psiHbPowerBusEoiAddr;

    //MMIO Complete, rest of code can run on any thread
    task_affinity_unpin();

    if (eoiRead != 0)
    {
        TRACFCOMP(g_trac_intr, ERR_MRK"IntrRp::sendPsiHbEOI error sending EOI"
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
    }

    TRACDCOMP(g_trac_intr, "IntrRp::sendPsiHbEOI read response: %lx", eoiRead);

    return l_err;
}


errlHndl_t IntrRp::sendXiveEOI(uint64_t& i_intSource, PIR_t& i_pir)
{
    errlHndl_t l_err = NULL;

    do {
        //The XIVE HW is expecting these MMIO accesses to come from the
        // core/thread they were setup (master core, thread 0)
        // These functions will ensure this code executes there
        task_affinity_pin();
        task_affinity_migrate_to_master();

        //LSI ESB Internal to the IVPE of the Master Proc
        volatile uint64_t * l_lsiEoi = iv_masterHdlr->xiveIcBarAddr;
        l_lsiEoi += XIVE_IC_LSI_EOI_OFFSET;
        uint64_t l_intPending = *l_lsiEoi;

        //MMIO Complete, rest of code can run on any thread
        task_affinity_unpin();

        //If an interrupt is pending, HB userspace will send a message to
        // trigger the handling of a 'new' interrupt. In this situation the
        // interrupt will not be triggered via the kernel.
        if (l_intPending == 1)
        {
            TRACFCOMP(g_trac_intr, "IntrRp::Need to acknowledge interrupt\n");
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
                     * @moduleid        INTR::MOD_INTRRP_XIVE_SENDEOI
                     * @reasoncode      INTR::RC_MESSAGE_SEND_ERROR
                     * @userdata1       RC from msg_send command
                     * @devdesc         Error encountered sending coalesce
                     *                  message to INTRP
                     */
                    l_err = new ERRORLOG::ErrlEntry
                        (
                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,  // severity
                         INTR::MOD_INTRRP_XIVE_SENDEOI,     // moduleid
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

errlHndl_t IntrRp::sendEOI(uint64_t& i_intSource, PIR_t& i_pir)
{
    intr_hdlr_t* l_proc = NULL;
    errlHndl_t l_err = NULL;

    //Find target handle for Proc to send EOI to
    for(ChipList_t::iterator targ_itr = iv_chipList.begin();
            targ_itr != iv_chipList.end(); ++targ_itr)
    {
        uint64_t l_topologyId = (*targ_itr)->proc->getAttr
                                        <TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();

        //Core + Thread IDs not important so use 0's
        PIR_t l_pir = PIR_t(l_topologyId, 0, 0);

        if (l_pir == i_pir)
        {
            l_proc = *targ_itr;
            break;
        }
    }

    do {
        l_err = sendPsiHbEOI(l_proc, i_intSource);
        if (l_err)
        { break ;}

        l_err = sendXiveEOI(i_intSource, i_pir);

    } while(0);

    return l_err;
}

void IntrRp::routeInterrupt(intr_hdlr_t* i_proc,
                            ext_intr_t i_type,
                            PIR_t& i_pir)
{
    //Search if anyone is subscribed to the given
    // interrupt source
    Registry_t::iterator r = iv_registry.find(i_type);

    if(r != iv_registry.end() && i_type != ISN_INTERPROC)
    {
        msg_q_t msgQ = r->second.msgQ;

        msg_t * rmsg = msg_allocate();
        rmsg->type = r->second.msgType;
        rmsg->data[0] = i_type;  // interrupt type
        rmsg->data[1] = i_pir.word;
        rmsg->extra_data = NULL;

        int rc = msg_sendrecv_noblk(msgQ,rmsg, iv_msgQ);
        if(rc)
        {
            TRACFCOMP(g_trac_intr,ERR_MRK
                "External Interrupt received type = %d, "
                "but could not send message to registered"
                " handler. Ignoring it. rc = %d",
                (uint32_t) i_type, rc);
        }
    }
    else  // no queue registered for this interrupt type
    {
        // Throw it away for now.
        TRACFCOMP(g_trac_intr,ERR_MRK
            "External Interrupt received type = %d, but "
            "nothing registered to handle it. Ignoring it.",
            (uint32_t)i_type);
    }
    return;
}

void IntrRp::handleExternalInterrupt()
{
    //Read LSI Interrupt Status register from each enabled
    // proc chip to see which caused the interrupt
    for(ChipList_t::iterator targ_itr = iv_chipList.begin();
            targ_itr != iv_chipList.end(); ++targ_itr)
    {
        uint64_t lsiIntStatus = (*targ_itr)->psiHbBaseAddr->lsiintstatus;
        TRACFCOMP(g_trac_intr, "IntrRp::msgHandler() lsiIntStatus 0x%016lx",
                       lsiIntStatus);

        //Loop through each bit, and add any pending
        // interrupts to list for later handling
        for (uint8_t i=0; i < LSI_LAST_SOURCE; i++)
        {
            uint64_t lsiIntMask = 0x8000000000000000 >> i;
            if (lsiIntMask & lsiIntStatus)
            {
                TRACDCOMP(g_trac_intr,"IntrRp::msgHandler()"
                                            " Interrupt Type: %d found", i);

                //Get PIR value for the proc with the
                // interrupt condition
                uint64_t l_topologyId =
                  (*targ_itr)->proc->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();
                //Core + Thread IDs not important so use 0's
                PIR_t l_pir = PIR_t(l_topologyId, 0, 0);

                //Make object to search pending interrupt
                //   list for
                std::pair<PIR_t, ext_intr_t> l_intr =
                             std::make_pair( l_pir, static_cast<ext_intr_t>(i));

                //See if an interrupt with from Proc with
                //  the same PIR + interrupt source are
                //  still being processed
                auto l_found = std::find_if( iv_pendingIntr.begin(),
                                             iv_pendingIntr.end(),
                                             [&l_intr](auto k)->bool
                    {
                        return ((k.first == l_intr.first) &&
                                       (k.second == l_intr.second));
                    });
                if (l_found != iv_pendingIntr.end())
                {
                    TRACFCOMP(g_trac_intr, "IntrRp::msgHandler() Pending"
                               " Interrupt already found for pir: 0x%lx,"
                               " interrupt type: %d, Ignoring",
                               l_pir, static_cast<ext_intr_t>(i));
                }
                else
                {
                    //New pending interrupt for source type
                    TRACFCOMP(g_trac_intr, "IntrRp::msgHandler() External "
                            "Interrupt found for pir: 0x%lx,interrupt type: %d",
                            l_pir, static_cast<ext_intr_t>(i));

                    //Add to list of interrupts in flight
                    iv_pendingIntr.push_back(l_intr);

                    uint64_t intSource = l_intr.second;

                    //Mask off current interrupt source
                    maskInterruptSource(intSource, *targ_itr);

                    //Send EOI so other interrupt sources other than the one
                    // masked previously can be presented
                    sendXiveEOI(intSource, l_pir);

                    //Call function to route the interrupt
                    //to the appropriate handler
                    routeInterrupt((*targ_itr), static_cast<ext_intr_t>(i),
                                      l_pir);
                }
            }
        }
    }
}

errlHndl_t IntrRp::maskAllInterruptSources()
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

errlHndl_t IntrRp::maskInterruptSource(uint8_t i_intr_source,
                                       intr_hdlr_t *i_chip)
{
    errlHndl_t l_err = NULL;
    // Perform read on ESB_OFF_OFFSET to transition the
    // ESB for this source to the OFF state which
    // masks the sources off
    uint64_t * l_psiHbEsbptr = i_chip->psiHbEsbBaseAddr;
    l_psiHbEsbptr +=
           (((i_intr_source*PAGE_SIZE)+ESB_OFF_OFFSET)
                  /sizeof(uint64_t));

    //MMIO Read to this address transitions the ESB to the off state
    volatile uint64_t l_maskRead = *l_psiHbEsbptr;
    eieio();

    //Perform 2nd read to verify in OFF state using query offset
    l_psiHbEsbptr = i_chip->psiHbEsbBaseAddr +
                  (((i_intr_source*PAGE_SIZE)+ESB_QUERY_OFFSET)
                  /sizeof(uint64_t));
    l_maskRead = *l_psiHbEsbptr;

    if (l_maskRead != ESB_STATE_OFF)
    {
        TRACFCOMP(g_trac_intr, "Error masking interrupt source: %x."
                              " ESB state is: %lx.",
                              i_intr_source, l_maskRead);

        l_err = new ERRORLOG::ErrlEntry
              (
               ERRORLOG::ERRL_SEV_INFORMATIONAL,  // severity
               INTR::MOD_INTRRP_MASKINTERRUPT,    // moduleid
               INTR::RC_XIVE_ESB_WRONG_STATE,     // reason code
               i_intr_source,
               l_maskRead
               );

    }

    return l_err;
}

errlHndl_t IntrRp::maskInterruptSource(uint8_t l_intr_source)
{
    errlHndl_t l_err = NULL;

    for(ChipList_t::iterator targ_itr = iv_chipList.begin();
            targ_itr != iv_chipList.end(); ++targ_itr)
    {
        l_err = maskInterruptSource(l_intr_source,
                                    *targ_itr);

        if (l_err)
        {
            break;
        }
    }

    return l_err;
}

errlHndl_t IntrRp::unmaskInterruptSource(uint8_t l_intr_source,
                                         intr_hdlr_t *i_proc,
                                         bool i_force_unmask)
{
    errlHndl_t l_err = NULL;
    uint64_t * l_psiHbEsbptr = nullptr;
    volatile uint64_t l_esbRead = 0;

    if(!i_force_unmask)
    {
        //Perform read to verify in OFF state using query offset
        l_psiHbEsbptr = i_proc->psiHbEsbBaseAddr +
                    (((l_intr_source*PAGE_SIZE)+ESB_QUERY_OFFSET)
                    /sizeof(uint64_t));

        l_esbRead = *l_psiHbEsbptr;
        eieio();
    }

    // If ESB source is indeed masked (OFF) on this processor
    // then go ahead w/ unmask
    if(i_force_unmask  || l_esbRead == ESB_STATE_OFF)
    {
        // Perform read to EOI offset which will put the ESB for this source
        // into the RESET state
        l_psiHbEsbptr = i_proc->psiHbEsbBaseAddr +
                (((l_intr_source*PAGE_SIZE)+ESB_RESET_OFFSET)
                            /sizeof(uint64_t));

        l_esbRead = *l_psiHbEsbptr;
        eieio();

        // Perform 2nd read on query offset to verify in we are
        // no longer in the OFF state
        l_psiHbEsbptr = i_proc->psiHbEsbBaseAddr +
                    (((l_intr_source*PAGE_SIZE)+ESB_QUERY_OFFSET)
                    /sizeof(uint64_t));

        l_esbRead = *l_psiHbEsbptr;
        eieio();

        // Make sure the ESB is no longer in OFF state for this source
        // NOTE: we dont check for RESET state because ESB could immediately
        //       go to pending if the LSI source was active
        if (l_esbRead == ESB_STATE_OFF)
        {
            TRACFCOMP(g_trac_intr, "Error unmasking interrupt source: %x."
                            " ESB state is: %lx.",
                            l_intr_source, l_esbRead);

            /*@ errorlog tag
                * @errortype         ERRL_SEV_INFORMATIONAL
                * @moduleid          INTR::MOD_INTRRP_UNMASKINTERRUPT
                * @reasoncode        INTR::RC_XIVE_ESB_WRONG_STATE
                * @userdata1[0:31]   Huid of processor
                * @userdata1[32:63]  Interrupt Source Number
                * @userdata2       MMIO Read Value for unmasking
                * @devdesc         Error unmasking interrupt source
                */
            l_err = new ERRORLOG::ErrlEntry
            (
                ERRORLOG::ERRL_SEV_INFORMATIONAL,  // severity
                INTR::MOD_INTRRP_UNMASKINTERRUPT,  // moduleid
                INTR::RC_XIVE_ESB_WRONG_STATE,     // reason code
                TWO_UINT32_TO_UINT64(
                    TO_UINT32( TARGETING::get_huid( i_proc->proc )),
                    TO_UINT32( l_intr_source )),
                l_esbRead
            );
        }
    }
    else
    {
        TRACFCOMP(g_trac_intr, "Requested Unmask of SRC 0x%x for target 0x%lx and source was not masked",
                  l_intr_source, l_esbRead);
    }

    return l_err;
}

errlHndl_t IntrRp::setMasterInterruptBARs(TARGETING::Target * i_target,
                                          bool i_enable)
{
    errlHndl_t l_err = NULL;

    do {

        l_err = setIntCqTmBAR(i_target, i_enable);
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error setting XIVE TM BAR1");
            break;
        }
    } while (0);

    return l_err;
}

errlHndl_t IntrRp::setCommonInterruptBARs(intr_hdlr_t * i_proc,
                                          bool i_enable)
{
    errlHndl_t l_err = NULL;

    do {

        l_err = setFspBAR(i_proc, i_enable);
        if(l_err)
        {
            TRACFCOMP(g_trac_intr, "Error setting FSP BAR");
            break;
        }

        l_err = setPsiHbBAR(i_proc, i_enable);
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error setting PSIHB BAR");
            break;
        }

        l_err = setPsiHbEsbBAR(i_proc, i_enable);
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error setting PSIHB ESB BAR");
            break;
        }

        l_err = setXiveIcBAR(i_proc, i_enable);
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, "Error setting XIVE IC BAR");
            break;
        }

    } while (0);

    return l_err;
}

void IntrRp::completeInterruptProcessing(uint64_t& i_intSource, PIR_t& i_pir)

{
    intr_hdlr_t* l_proc = NULL;
    errlHndl_t l_err = NULL;

    //Find target handle for Proc to remove pending interrupt for
    for (ChipList_t::iterator targ_itr = iv_chipList.begin();
            targ_itr != iv_chipList.end(); ++targ_itr)
    {
        uint64_t l_topologyId = (*targ_itr)->proc->getAttr
                                        <TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();

        //Core + Thread IDs not important so use 0's
        PIR_t l_pir = PIR_t(l_topologyId, 0, 0);

        if (l_pir == i_pir)
        {
            l_proc = *targ_itr;
            break;
        }
    }

    do {

        mutex_lock(&iv_intrRpMutex);
        // Do not complete interrupt processing if IntrRp has been shut down.
        // This prevents a race condition from happening where we try to access
        // a memory region that's been locked as part of the shutdown procedure.
        if(isIntrRpShutdown())
        {
            break;
        }

        //Check if we found a matching proc handler for the interrupt to remove
        //  This is needed so the iNTRRP will honor new interrupts from this
        //  source
        if (l_proc == NULL)
        {
            TRACFCOMP(g_trac_intr, ERR_MRK"IntrRp::completeInterruptProcessing:"
               " couldn't find proc handler that matches pir: 0x%lx", i_pir);
            break;
        }
        else
        {
            //Make object to search pending interrupt
            //   list for
            std::pair<PIR_t, ext_intr_t> l_intr = std::make_pair(
                                          i_pir,
                                          static_cast<ext_intr_t>(i_intSource));

            //See if an interrupt with from Proc with
            //  the same PIR + interrupt source are
            //  still being processed
            auto l_found = std::find_if( iv_pendingIntr.begin(),
                                     iv_pendingIntr.end(),
                                     [&l_intr](auto k)->bool
                  {
                        return (k.first == l_intr.first) &&
                        (k.second == l_intr.second);
                  });

            //Remove Interrupt source from pending interrupt list
            if (l_found == iv_pendingIntr.end())
            {
                TRACFCOMP(g_trac_intr,ERR_MRK"IntrRp::completeInterruptHandling()"
                                    " Pending Interrupt NOT found for pir:"
                                    " 0x%lx, interrupt type: %d. Ignoring.",
                                   i_pir, static_cast<ext_intr_t>(i_intSource));
            }
            else
            {
                TRACFCOMP(g_trac_intr, "IntrRp::completeInterruptProcessing()"
                                  " Removing pending interrupt for pir: 0x%lx,"
                                  "interrupt type: %d", i_pir,
                                  static_cast<ext_intr_t>(i_intSource));
                iv_pendingIntr.erase(l_found);
            }

            //Enable this interrupt source again
            l_err = unmaskInterruptSource(i_intSource, l_proc, true);

            if (l_err)
            {
                TRACFCOMP(g_trac_intr,
                    "IntrRp::completeInterruptProcessing "
                    "error unmasking interrupt type: %lx", i_intSource);
                errlCommit(l_err, INTR_COMP_ID);
            }

            //Send final EOI to enable interrupts for this source again
            sendEOI(i_intSource, i_pir);
        }

    } while(0);

    mutex_unlock(&iv_intrRpMutex);

    return;
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

void IntrRp::shutDown(uint64_t i_status)
{
    msg_t * rmsg = msg_allocate();
    errlHndl_t l_err = NULL;

    TRACFCOMP(g_trac_intr, "IntrRp::shutDown - Sending shutdown message"
              " to registered handlers");

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

    //Mask any future interrupts to avoid receiving anymore while in the process
    // of resetting the rest of the Interrupt Logic
    l_err = maskAllInterruptSources();
    if (l_err)
    {
        delete l_err; //errl comp already shutdown. Log error and continue
        l_err = nullptr;
        TRACFCOMP(g_trac_intr, "IntrRp::shutDown() Error masking all interrupt sources.");
    }

    mutex_lock(&iv_intrRpMutex);

    iv_IntrRpShutdownRequested = true;

    //Reset PSIHB Interrupt Space
    TRACFCOMP(g_trac_intr, "Reset PSIHB Interrupt Space");

    //First reset INTRP logic for slave procs
    for(ChipList_t::iterator targ_itr = iv_chipList.begin();
                        targ_itr != iv_chipList.end(); ++targ_itr)
    {
        if (*targ_itr != iv_masterHdlr)
        {
            PSIHB_SW_INTERFACES_t * this_psihb_ptr = (*targ_itr)->psiHbBaseAddr;
            this_psihb_ptr->icr = PSI_BRIDGE_INTP_STATUS_CTL_RESET;
            resetIntUnit(*targ_itr);
            //Disable common interrupt BARs
            l_err = setCommonInterruptBARs(*targ_itr, false);

            if (l_err)
            {
                delete l_err; //errl cmp already shutdown. Log error + continue
                l_err = nullptr;
                TRACFCOMP(g_trac_intr, "IntrRp::shutDown() Error disabling Common Interrupt BARs");
            }
        }
    }

    //Then reset master proc INTRP logic
    PSIHB_SW_INTERFACES_t * this_psihb_ptr = iv_masterHdlr->psiHbBaseAddr;
    this_psihb_ptr->icr = PSI_BRIDGE_INTP_STATUS_CTL_RESET;
    TRACFCOMP(g_trac_intr, "Reset PSIHB INTR Complete");

    //Reset XIVE Interrupt unit
    resetIntUnit(iv_masterHdlr);

    //Disable common interrupt BARs for master proc
    l_err = setCommonInterruptBARs(iv_masterHdlr, false);
    if (l_err)
    {
        delete l_err; //errl cmp already shutdown. Log error + continue
        l_err = nullptr;
        TRACFCOMP(g_trac_intr, "IntrRp::shutDown() Error disabling Common"
                               " Interrupt BARs for master proc");
    }

    //Disable master interrupt BARs
    l_err = setMasterInterruptBARs(iv_masterHdlr->proc, false);

    if (l_err)
    {
        delete l_err; //errl cmp already shutdown. Log error + continue
        l_err = nullptr;
        TRACFCOMP(g_trac_intr, "IntrRp::shutDown() Error disabling Master Interrupt BARs");
    }

    mutex_unlock(&iv_intrRpMutex);

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

    auto topology = proc->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
    CHIP_UNIT_ATTR coreId = i_core->getAttr<TARGETING::ATTR_CHIP_UNIT>();

    PIR_t pir(0);
    pir.topologyId = topology;
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

    auto topology = proc->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
    CHIP_UNIT_ATTR coreId = i_core->getAttr<TARGETING::ATTR_CHIP_UNIT>();

    PIR_t pir(0);
    pir.topologyId = topology;
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

            auto topology = proc->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
            CHIP_UNIT_ATTR coreId =
                              (*core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            PIR_t pir(0);
            pir.topologyId = topology;
            pir.coreId = coreId;

            TRACFCOMP(g_trac_intr,"  t%d c%d", topology, coreId);
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
                    if(ISN_INTERPROC == xirr)
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
        reinterpret_cast<void *>(hrmorBase +
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

        for(uint32_t node = 0; node < MAX_NODES_PER_SYS; ++node)
        {
            if (node == PIR_t::nodeOrdinalFromPir(iv_masterCpu.word))
            {
                vaddr[node] = this_node_info;
            }
            else if(this_node_info->exist[node])
            {
                // Read the remote ipc address for this node and store it as an integer
                uint64_t l_remote_ipc_addr =
                    reinterpret_cast<uint64_t>(KernelIpc::ipc_data_area.remote_ipc_data_addr[node]);

                // perform a block map to get a page aligned vaddr that contains the info we want
                void* l_pageAlignedPtr = mm_block_map(reinterpret_cast<void *>(ALIGN_PAGE_DOWN(l_remote_ipc_addr)),
                                                        ALIGN_PAGE(sizeof(KernelIpc::ipc_data_area_t) + PAGE_SIZE));

                KernelIpc::ipc_data_area_t * l_node_ipc_data_area =
                    reinterpret_cast<KernelIpc::ipc_data_area_t *>(
                        reinterpret_cast<uint64_t>(l_pageAlignedPtr) +
                        (l_remote_ipc_addr % PAGE_SIZE) );

                uint16_t sleep_time_cur = 0;
                const uint16_t SLEEP_TIME_WAIT_SEC = 5; // sleep for 5 seconds
                const uint16_t SLEEP_TIME_MAX = 300; // 300 second (5 minutes)

                while(l_node_ipc_data_area->hrmor_base == 0 && sleep_time_cur < SLEEP_TIME_MAX)
                {
                      TRACDCOMP(g_trac_intr, INFO_MRK
                                "0 hrmor found for node %d. Sleeping for %d sec and trying again",
                                node,
                                SLEEP_TIME_WAIT_SEC);
                      nanosleep(SLEEP_TIME_WAIT_SEC,0);
                      sleep_time_cur += SLEEP_TIME_WAIT_SEC;
                }

                if(sleep_time_cur >= SLEEP_TIME_MAX)
                {
                    TRACFCOMP(g_trac_intr, ERR_MRK
                                "Waited for %d seconds and 0 hrmor was found for node"
                                " %d so we are giving up",
                                sleep_time_cur,
                                node);
                    /*@
                    * @errortype    ERRL_SEV_UNRECOVERABLE
                    * @moduleid     INTR::MOD_INTR_SYNC_NODES
                    * @reasoncode   INTR::RC_NODE_SYNC_TIMEOUT
                    * @userdata1[0:31] This Node
                    * @userdata1[0:31] Remote Node we canot get HRMOR from
                    * @userdata2    Remote IPC Address
                    * @devdesc      Remote node is failing to fill out
                    *               its IPC section or this node is failing
                    *               to read it.
                    * @custdesc     Firmware error occured during system reboot
                    */
                    err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            INTR::MOD_INTR_SYNC_NODES,
                            INTR::RC_NODE_SYNC_TIMEOUT,
                            TWO_UINT32_TO_UINT64(
                              PIR_t::nodeOrdinalFromPir(iv_masterCpu.word),
                              node),
                            l_remote_ipc_addr,
                            true /*Add HB Software Callout*/);
                    break;
                }

                node_info_ptr =
                    reinterpret_cast<void *>
                     ((l_node_ipc_data_area->hrmor_base)+VMM_INTERNODE_PRESERVED_MEMORY_ADDR);

                mm_block_unmap(reinterpret_cast<void *>(ALIGN_PAGE_DOWN(l_remote_ipc_addr)));



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

            for(uint32_t node = 0; node < MAX_NODES_PER_SYS; ++node)
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

        for(uint32_t node = 0; node < MAX_NODES_PER_SYS; ++node)
        {
            if(this_node_info->exist[node])
            {
                // We are still using this_node_info area
                // so unmap it later.
                if(node != PIR_t::nodeOrdinalFromPir(iv_masterCpu.word))
                {
                    mm_block_unmap(vaddr[node]);
                }
            }
        }

        mm_block_unmap(this_node_info);

    } while(0);

    return err;
}

errlHndl_t  IntrRp::initializeMpiplSyncArea()
{
    errlHndl_t err = NULL;
    uint64_t hrmorBase = KernelIpc::ipc_data_area.hrmor_base;
    void * node_info_ptr =
        reinterpret_cast<void *>(hrmorBase +
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
            if(PIR_t::groupFromPir(iv_masterCpu.word) == node)
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

errlHndl_t  IntrRp::addHbNodeToMpiplSyncArea(uint64_t i_hbNode)
{
    errlHndl_t err = NULL;
    uint64_t hrmorBase = KernelIpc::ipc_data_area.hrmor_base;
    void * node_info_ptr =
        reinterpret_cast<void *>(hrmorBase +
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

errlHndl_t IntrRp::setFspBAR(
    const intr_hdlr_t* const i_pProcIntrHdlr,
    const bool               i_enable)
{
    errlHndl_t pError = nullptr;

    do
    {

        if (!i_enable)
        {
            // Noop on disable
            break;
        }

        assert(i_pProcIntrHdlr != nullptr,"BUG! Input interrupt handler pointer "
            "was nullptr");
        auto * const pProc = i_pProcIntrHdlr->proc;
        assert(pProc != nullptr,"BUG! proc target was nullptr");

        uint64_t fspBAR =
            pProc->getAttr<TARGETING::ATTR_FSP_BASE_ADDR>();

        const size_t expSize = sizeof(fspBAR);
        auto size = expSize;
        pError = deviceWrite(
                     pProc,
                     &fspBAR,
                     size,
                     DEVICE_SCOM_ADDRESS(PSI_BRIDGE_FSP_BAR_SCOM_ADDR));
        if(pError)
        {
            TRACFCOMP(g_trac_intr,ERR_MRK "Failed writing %d bytes of FSP BAR "
                "address value (0x%016llX) to FSP BAR register for proc 0x%08X",
                expSize,fspBAR,get_huid(pProc));
            break;
        }

        assert(size == expSize,"Actual SCOM write size (%d) does not match "
            "expected SCOM write size (%d)",size,expSize);

    } while(0);

    return pError;
}

errlHndl_t IntrRp::setPsiHbBAR(intr_hdlr_t *i_proc, bool i_enable)
{
    errlHndl_t l_err = NULL;
    TARGETING::Target *l_target = i_proc->proc;
    uint64_t l_baseBarValue =
                      l_target->getAttr<TARGETING::ATTR_PSI_BRIDGE_BASE_ADDR>();

    do {

        if (!i_enable) { break; } //Don't ever disable, PHYP needs this set

        //Get base BAR Value from attribute
        uint64_t l_barValue = l_baseBarValue;

        TRACFCOMP(g_trac_intr,"INTR: Setting PSI BRIDGE Bar Address value for -"
                              " Target %.8x. PSI BRIDGE BAR value: 0x%016lx",
                  TARGETING::get_huid(l_target),l_barValue);

        //Set base BAR Value
        uint64_t size = sizeof(l_barValue);
        l_err = deviceWrite(l_target,
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

        TRACFCOMP(g_trac_intr,"INTR: Setting PSI BRIDGE Bar enable value for Target - %.8x. PSI BRIDGE BAR value: 0x%016lx",
                  TARGETING::get_huid(l_target),l_barValue);

        l_err = deviceWrite(l_target,
                            &l_barValue,
                            size,
                            DEVICE_SCOM_ADDRESS(PSI_BRIDGE_BAR_SCOM_ADDR));

        if(l_err)
        {
            TRACFCOMP(g_trac_intr,ERR_MRK"Error enabling PSIHB BAR");
            break;
        }

        //Map Memory Internally for HB and store in member variable
        void *l_psiHbAddress = reinterpret_cast<void *>(l_baseBarValue);
        i_proc->psiHbBaseAddr = reinterpret_cast<PSIHB_SW_INTERFACES_t *>
                   (mmio_dev_map(l_psiHbAddress, PAGE_SIZE));

    } while(0);

    return l_err;
}

errlHndl_t IntrRp::setPsiHbEsbBAR(intr_hdlr_t *i_proc,
                                  bool i_enable)
{
    TARGETING::Target *l_target = i_proc->proc;
    errlHndl_t l_err = NULL;
    uint64_t l_baseBarValue
            = l_target->getAttr<TARGETING::ATTR_PSI_HB_ESB_ADDR>();

    do {

        uint64_t l_barValue = l_baseBarValue;
        TRACFCOMP(g_trac_intr,"INTR: Target %.8x. "
                              "PSI BRIDGE ESB BAR value: 0x%016lx",
                  TARGETING::get_huid(l_target),l_barValue);

        uint64_t size = sizeof(l_barValue);
        l_err = deviceWrite(l_target,
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
            TRACFCOMP(g_trac_intr,"INTR: Target %.8x. PSI BRIDGE ESB BAR value: 0x%016lx",
                  TARGETING::get_huid(l_target),l_barValue);

            size = sizeof(l_barValue);
            l_err = deviceWrite(l_target,
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
            i_proc->psiHbEsbBaseAddr =
               reinterpret_cast<uint64_t *>
               (mmio_dev_map(l_psiHbEoiAddress, (LSI_LAST_SOURCE)*PAGE_SIZE));
        }

    } while (0);

    return l_err;
}

errlHndl_t IntrRp::setIntCqTmBAR(TARGETING::Target * i_target,
                                     bool i_enable)
{
    errlHndl_t l_err = NULL;
    uint64_t l_baseBarValue =
                i_target->getAttr<TARGETING::ATTR_INT_CQ_TM_BAR_ADDR>();

    do
    {
        uint64_t l_barValue = l_baseBarValue;
        if (i_enable)
        {
            l_barValue += INT_CQ_TM_BAR_VALIDATE;
        }

        TRACDCOMP(g_trac_intr,"INTR: Target %.8x. INT CQ TM BAR value: 0x%016lx",
                  TARGETING::get_huid(i_target),l_barValue);

        uint64_t size = sizeof(l_barValue);
        l_err = deviceWrite(i_target,
                          &l_barValue,
                          size,
                          DEVICE_SCOM_ADDRESS(INT_CQ_TM_BAR_SCOM_ADDR));

        if(l_err)
        {
            TRACFCOMP(g_trac_intr,ERR_MRK"Unable to set INT CQ TM BAR");
            break;
        }

        //Map Memory Internally for HB and store in member variable
        void *l_intCqTmBarAddress =
                reinterpret_cast<void *>(l_baseBarValue);
        // SMF doesn't allow the user space to touch Ultravisor page (page 0),
        // so we have to use page 1. Map 2 page sizes to be able to access page1
        iv_intCqTmBarAddress =
               reinterpret_cast<uint64_t *>
               (mmio_dev_map(l_intCqTmBarAddress, PAGE_SIZE*2));

    } while(0);

    return l_err;
}


errlHndl_t IntrRp::setXiveIcBAR(intr_hdlr_t *i_proc, bool i_enable)
{
    TARGETING::Target *l_target = i_proc->proc;

    errlHndl_t l_err = NULL;
    uint64_t l_baseBarValue
            = l_target->getAttr<TARGETING::ATTR_XIVE_CONTROLLER_BAR_ADDR>();

    do {
        uint64_t l_barValue = l_baseBarValue;

        if (i_enable)
        {
            l_barValue += XIVE_IC_BAR_VALID;
        }

        TRACDCOMP(g_trac_intr,"INTR: Target %.8x. XIVE IC BAR value: 0x%016lx",
                  TARGETING::get_huid(l_target), l_barValue);

        uint64_t size = sizeof(l_barValue);
        l_err = deviceWrite(l_target,
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
        i_proc->xiveIcBarAddr =
               reinterpret_cast<uint64_t *>
               (mmio_dev_map(l_xiveIcBarAddress, 40*PAGE_SIZE));
    } while(0);

    return l_err;
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

    TRACFCOMP( g_trac_intr,"handleCpuTimeout for pir: 0x%lx", pir);

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
    using namespace INITSERVICE::SPLESS;

    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    assert( sys != NULL );
    uint64_t en_threads = sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();

    if( en_threads == 0 )
    {
        //Read mbox scratch regs for enabled threads value
        //and set attribute appropriately
        MboxScratch3_t l_scratch3;
        TARGETING::ATTR_MASTER_MBOX_SCRATCH_type l_scratchRegs;
        assert(sys->tryGetAttr<TARGETING::ATTR_MASTER_MBOX_SCRATCH>(l_scratchRegs),
               "INTR::get_enabled_threads() failed to get MASTER_MBOX_SCRATCH");
        l_scratch3.data32 = l_scratchRegs[MboxScratch3_t::REG_IDX];

        if(l_scratch3.fwModeCtlFlags.smtMode == MboxScratch3_t::SMT1)
        {
            en_threads = 0x8000000000000000; //SMT1 == thread 0
        }
        else if (l_scratch3.fwModeCtlFlags.smtMode == MboxScratch3_t::SMT2)
        {
            en_threads = 0xC000000000000000; //SMT2 == thread 0,1
        }
        else
        {
           en_threads = 0xF000000000000000; //SMT4 == thread 0..3
        }
        sys->setAttr<TARGETING::ATTR_ENABLED_THREADS>(en_threads);
    }
    return en_threads;
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

errlHndl_t INTR::IntrRp::enableSlaveProcInterrupts(TARGETING::Target * i_target)
{
    errlHndl_t l_err = NULL;
    do
    {
        TRACFCOMP(g_trac_intr, "Enabling Interrupts for slave proc with huid: %x",
                  TARGETING::get_huid(i_target));

        intr_hdlr_t* l_procIntrHdlr = new intr_hdlr_t(i_target);
        iv_chipList.push_back(l_procIntrHdlr);

        //Setup the base Interrupt BAR Registers for this non-master proc
        l_err = setCommonInterruptBARs(l_procIntrHdlr);
        if (l_err)
        {
            TRACFCOMP(g_trac_intr, ERR_MRK" could not set common interrupt BARs");
            break;
        }

        // Mask all unregistered LSI sources
        for (const auto& l_lsi_source : iv_unregisterdLsiSources)
        {
            l_err = maskInterruptSource(l_lsi_source,
                                        l_procIntrHdlr);
            if (l_err)
            {
                break;
            }
        }

        if (l_err)
        {
            break;
        }

        //Setup the PSIHB interrupt routing to route interrupts from non-master
        //  proc back to master proc
        routeLSIInterrupts(l_procIntrHdlr);

    } while(0);

    TRACFCOMP(g_trac_intr, INFO_MRK"Slave Proc Interrupt Routing setup complete");
    return l_err;
}

void INTR::esbStateToString(uint64_t i_esbState, const char** o_esbStateString)
{
    switch(i_esbState)
    {
        case ESB_STATE_RESET:
            *o_esbStateString = "RESET";
            break;
        case ESB_STATE_OFF:
            *o_esbStateString = "OFF";
            break;
        case ESB_STATE_PENDING:
            *o_esbStateString = "PENDING";
            break;
        case ESB_STATE_QUEUED:
            *o_esbStateString = "QUEUED";
            break;
        default:
            *o_esbStateString = "INVALID";
            break;
    }
}

errlHndl_t INTR::printInterruptInfo()
{
    errlHndl_t err = NULL;
    msg_q_t intr_msgQ = msg_q_resolve(VFS_ROOT_MSG_INTR);
    if(intr_msgQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_INTR_DUMP;
        int send_rc = msg_send(intr_msgQ, msg);
        if (send_rc != 0)
        {
            TRACFCOMP(g_trac_intr, ERR_MRK"IntrRp::printInterruptInfo error "
            "sending print intr info message");
            /*@ errorlog tag
            * @errortype       ERRL_SEV_UNRECOVERABLE
            * @moduleid        INTR::MOD_INTR_DUMP
            * @reasoncode      INTR::RC_MESSAGE_SEND_ERROR
            * @userdata1       RC from msg_send command
            * @devdesc         Error encountered sending print intr info
            *                  message to INTRP
            * @custdesc        Error encountered gathering diagnostic info
            */
            err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_UNRECOVERABLE,  // severity
             INTR::MOD_INTR_DUMP,               // moduleid
             INTR::RC_MESSAGE_SEND_ERROR,       // reason code
             send_rc,
             0
             );
        }
    }
    else
    {
        /*@ errorlog tag
        * @errortype       ERRL_SEV_INFORMATIONAL
        * @moduleid        INTR::MOD_INTR_DUMP
        * @reasoncode      INTR::RC_RP_NOT_INITIALIZED
        * @userdata1       MSG_INTR_DUMP
        * @userdata2       0
        * @devdesc         Interrupt resource provider not initialized yet.
        * @custdesc        Error encountered gathering diagnostic info
        */
        err = new ERRORLOG::ErrlEntry
        (
         ERRORLOG::ERRL_SEV_INFORMATIONAL,     // severity
         INTR::MOD_INTR_DUMP,                  // moduleid
         INTR::RC_RP_NOT_INITIALIZED,          // reason code
         static_cast<uint64_t>(MSG_INTR_DUMP),
         0
         );
    }
    return err;
}

void INTR::IntrRp::printLSIInfo() const
{
    TRACFCOMP(g_trac_intr, "---LSI Sources---");

    //Read LSI Interrupt Status register from each enabled
    // proc chip to see which caused the interrupt
    for(auto targ_itr = iv_chipList.begin();
    targ_itr != iv_chipList.end(); ++targ_itr)
    {
        uint64_t l_mmioRead = (*targ_itr)->psiHbBaseAddr->lsiintstatus;
        uint32_t l_huid = get_huid((*targ_itr)->proc);
        TRACFCOMP(g_trac_intr, "Processor 0x%lx", l_huid);
        TRACFCOMP(g_trac_intr, "                 lsiIntStatus :  vAddr=0x%016lx    Value=0x%016lx", &(*targ_itr)->psiHbBaseAddr->lsiintstatus , l_mmioRead);
        l_mmioRead = (*targ_itr)->psiHbBaseAddr->lsiintlevel;
        TRACFCOMP(g_trac_intr, "                 lsiIntLevel  :  vAddr=0x%016lx    Value=0x%016lx", &(*targ_itr)->psiHbBaseAddr->lsiintlevel, l_mmioRead);
    }
}

void INTR::IntrRp::printPSIHBInfo() const
{
    TRACFCOMP(g_trac_intr, "---PSIHB Info---");
    //Read LSI Interrupt Status register from each enabled
    // proc chip to see which caused the interrupt
    for(auto targ_itr = iv_chipList.begin();
    targ_itr != iv_chipList.end(); ++targ_itr)
    {
        uint32_t l_huid = get_huid((*targ_itr)->proc);
        uint64_t l_mmioRead = (*targ_itr)->psiHbBaseAddr->psihbcr;

        TRACFCOMP(g_trac_intr, "Processor 0x%lx", l_huid);

        TRACFCOMP(g_trac_intr, "                 PSIHB Ctrl/Status Reg       :  vAddr=0x%016lx    Value=0x%016lx",
                  &(*targ_itr)->psiHbBaseAddr->psihbcr, l_mmioRead);

        l_mmioRead = (*targ_itr)->psiHbBaseAddr->psisemr;
        TRACFCOMP(g_trac_intr, "                 PSIHB Error/Status Reg      :  vAddr=0x%016lx    Value=0x%016lx",
                  &(*targ_itr)->psiHbBaseAddr->psisemr,  l_mmioRead);

        l_mmioRead = (*targ_itr)->psiHbBaseAddr->phbdsr;
        TRACFCOMP(g_trac_intr, "                 PSIHB Dbg Setting Reg       :  vAddr=0x%016lx    Value=0x%016lx",
                  &(*targ_itr)->psiHbBaseAddr->phbdsr, l_mmioRead);

        l_mmioRead = (*targ_itr)->psiHbBaseAddr->icr;
        TRACFCOMP(g_trac_intr, "                 PSIHB Interrupt Control Reg :  vAddr=0x%016lx    Value=0x%016lx",
                  &(*targ_itr)->psiHbBaseAddr->icr, l_mmioRead);
    }
}

void INTR::IntrRp::printEsbStates() const
{
    TRACFCOMP(g_trac_intr, "---ESB States---");

    //LSI ESB Internal to the IVPE of the Master Proc
    volatile uint64_t * l_lsiEsbQuery = iv_masterHdlr->xiveIcBarAddr;
    l_lsiEsbQuery += XIVE_IC_LSI_EOI_OFFSET;
    l_lsiEsbQuery += (ESB_QUERY_OFFSET / sizeof(uint64_t));
    uint64_t l_intPending = *l_lsiEsbQuery;
    TRACFCOMP(g_trac_intr, "IC LSI ESB  = 0x%016lx", l_intPending);

    for(auto targ_itr = iv_chipList.begin();
    targ_itr != iv_chipList.end(); ++targ_itr)
    {
        TRACFCOMP(g_trac_intr, "Processor 0x%lx", get_huid((*targ_itr)->proc));
        for (uint8_t i = LSI_FIRST_SOURCE; i < LSI_LAST_SOURCE; i++)
        {
            // Ready from the ESB_QUERY_OFFSET to ensure the read doesn't
            // affect the state
            uint64_t * l_psiHbEsbptr = (*targ_itr)->psiHbEsbBaseAddr +
                            (((i*PAGE_SIZE)+ESB_QUERY_OFFSET) /sizeof(uint64_t));

            volatile uint64_t l_esbState = *l_psiHbEsbptr;
            const char* l_esbStateString = nullptr;

            // Use toString method to look up human readable string
            esbStateToString(l_esbState, &l_esbStateString);

            TRACFCOMP(g_trac_intr, "                 SRC: %02d         State: %s", i , l_esbStateString );
        }
    }
}

bool INTR::IntrRp::isIntrRpShutdown() const
{
    return iv_IntrRpShutdownRequested;
}
