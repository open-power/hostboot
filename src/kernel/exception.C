/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/exception.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2016                        */
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
#include <assert.h>
#include <kernel/types.h>
#include <kernel/console.H>
#include <kernel/task.H>
#include <kernel/taskmgr.H>
#include <arch/ppc.H>
#include <kernel/vmmmgr.H>
#include <kernel/cpuid.H>
#include <kernel/intmsghandler.H>
#include <errno.h>
#include <kernel/vmmmgr.H>
#include <kernel/machchk.H>
#include <kernel/terminate.H>
#include <kernel/hbterminatetypes.H>
#include <kernel/kernel_reasoncodes.H>


namespace ExceptionHandles
{
    bool PrivInstr(task_t*);
}

const uint64_t EXCEPTION_SRR1_MASK      = 0x00000000783F0000;
const uint64_t EXCEPTION_SRR1_PRIVINS   = 0x0000000000040000;

extern "C"
void kernel_execute_prog_ex()
{
    task_t* t = TaskManager::getCurrentTask();
    uint64_t exception = getSRR1() & EXCEPTION_SRR1_MASK;

    bool handled = false;
    switch(exception)
    {
        case EXCEPTION_SRR1_PRIVINS:
            handled = ExceptionHandles::PrivInstr(t);
            break;
    }
    if (!handled)
    {
        printk("Program exception, killing task %d\n", t->tid);
        TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
    }
}

const uint64_t EXCEPTION_DSISR_MASK     = 0x0000000048000000;
const uint64_t EXCEPTION_DSISR_PTEMISS  = 0x0000000040000000;
const uint64_t EXCEPTION_DSISR_PERMERR  = 0x0000000008000000;
const uint64_t EXCEPTION_DSISR_STORE    = 0x0000000002000000;

extern "C"
void kernel_execute_data_storage()
{
    task_t* t = TaskManager::getCurrentTask();
    uint64_t exception = getDSISR() & EXCEPTION_DSISR_MASK;

    bool handled = false;
    switch(exception)
    {
        case EXCEPTION_DSISR_PTEMISS:
        {
            uint64_t is_store = getDSISR() & EXCEPTION_DSISR_STORE;
            handled = VmmManager::pteMiss(t, getDAR(), 0 != is_store);
            break;
        }

        case EXCEPTION_DSISR_PERMERR:
        {
            uint64_t is_store = getDSISR() & EXCEPTION_DSISR_STORE;
            if (is_store)
            {
                handled = VmmManager::pteMiss(t, getDAR(), true);
            }
            break;
        }
    }
    if (!handled)
    {
        printk("Data Storage exception on %d: %lx, %lx @ %p\n",
               t->tid, getDAR(), getDSISR(), t->context.nip);
        TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
    }
}

extern "C"
void kernel_execute_data_segment()
{
    task_t* t = TaskManager::getCurrentTask();
    printk("Data Segment exception on %d: %lx @ %p\n",
           t->tid, getDAR(), t->context.nip);
    TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
}

const uint64_t EXCEPTION_SRR1_INSTR_MASK    = 0x0000000040000000;
const uint64_t EXCEPTION_SRR1_INSTR_PTEMISS = 0x0000000040000000;

extern "C"
void kernel_execute_inst_storage()
{
    task_t* t = TaskManager::getCurrentTask();
    uint64_t exception = getSRR1() & EXCEPTION_SRR1_INSTR_MASK;

    bool handled = false;
    switch (exception)
    {
        case EXCEPTION_SRR1_INSTR_PTEMISS:
            handled = VmmManager::pteMiss(t, getSRR0(), false);
            break;
    }
    if (!handled)
    {
        printk("Inst Storage exception on %d: %lx, %lx\n",
               t->tid, getSRR0(), getSRR1());
        TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
    }
}

extern "C"
void kernel_execute_inst_segment()
{
    task_t* t = TaskManager::getCurrentTask();
    printk("Inst Segment exception on %d: %p\n", t->tid, t->context.nip);
    TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
}

extern "C"
void kernel_execute_alignment()
{
    task_t* t = TaskManager::getCurrentTask();
    printk("Alignment exception, killing task %d\n", t->tid);
    TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
}

extern "C"
void kernel_execute_hype_emu_assist()
{
    task_t* t = TaskManager::getCurrentTask();
    printk("HypeEmu: Illegal instruction in task %d\n"
           "\tHSSR0 = %lx, HEIR = %lx\n", t->tid, getHSRR0(), getHEIR());
    TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
}

const uint32_t EXCEPTION_BRANCH_INSTR_MASK     = 0xFC000000;
const uint32_t EXCEPTION_BRANCH_INSTR          = 0x48000000;
const uint32_t EXCEPTION_MFSPR_CFAR_INSTR_MASK = 0xFC1FFFFE;
const uint32_t EXCEPTION_MFSPR_CFAR_INSTR      = 0x7C1C02A6;
const uint32_t EXCEPTION_MFSPR_GFR_NAME_MASK   = 0x03E00000;

namespace ExceptionHandles
{
    bool PrivInstr(task_t* t)
    {
        uint64_t phys_addr = VmmManager::findKernelAddress(
                reinterpret_cast<uint64_t>(t->context.nip));

        if (-EFAULT != static_cast<int64_t>(phys_addr))
        {
            uint32_t* instruction = reinterpret_cast<uint32_t*>(phys_addr);

            // Check for 'nap' and skip over.  This avoids a task-crash
            // if for some reason we entered back into the task without
            // privilege raised.
            if (*instruction == 0x4c000364)
            {
                printk("Error: Nap executed with lowered permissions on %d\n",
                       t->tid);
                t->context.nip = reinterpret_cast<void *> (
                       (reinterpret_cast<uint64_t>(t->context.nip)) + 4);
                return true;
            }


            // Check for 'mfspr r*, CFAR' instructions (from MFSPR RT,SPR)
            // and handle the setting of the specific r* register
            if (( *instruction & EXCEPTION_MFSPR_CFAR_INSTR_MASK)
                  == EXCEPTION_MFSPR_CFAR_INSTR )
            {

                // check to make sure previous instruction was a branch
                //  if not, then we don't want to handle this exception
                uint32_t* previous_instr =
                          (reinterpret_cast<uint32_t*>(phys_addr)) - 1;
                if ( (*previous_instr & EXCEPTION_BRANCH_INSTR_MASK)
                      == EXCEPTION_BRANCH_INSTR )
                {
                    uint32_t gpr_name = 0;

                    // GPR register in bits 6:10 of mfspr instruction
                    gpr_name = (*instruction & EXCEPTION_MFSPR_GFR_NAME_MASK)
                                >> 21;

                    // Move contents of previous instruction address to r*
                    t->context.gprs[gpr_name] =
                       (reinterpret_cast<uint64_t>(t->context.nip)) - 4;

                    // move instruction stream to next instruction
                    t->context.nip = reinterpret_cast<void *> (
                       (reinterpret_cast<uint64_t>(t->context.nip)) + 4);

                    printkd("mfsr r%d to CFAR handled, nip=%p\n",
                            gpr_name, t->context.nip  );

                    return true;
                }
                else
                {
                    printk("Error: mfspr r* to CFAR found, but previous "
                           "inst not a branch\n");
                    return false;
                }
            }
        }

        return false;
    }

}

extern "C"
void kernel_execute_fp_unavail()
{
    task_t* t = TaskManager::getCurrentTask();

    if (t->fp_context)
    {
        printk("Error: FP unavailable while task has FP-context.\n");
        kassert(t->fp_context == NULL);
    }
    else
    {
        // Enable FP by creating a FP context.
        // Context switch code will handle the rest.
        t->fp_context = new context_fp_t();
    }
}

const uint64_t EXCEPTION_HSRR1_SOFTPATCH_MASK   = 0x0000000000100000;
const uint64_t EXCEPTION_HSRR1_SOFTPATCH_DENORM = 0x0000000000100000;

extern "C" void p8_softpatch_denorm_assist(context_fp_t*);

extern "C"
void kernel_execute_softpatch()
{
    task_t* t = TaskManager::getCurrentTask();

    if ((getHSRR1() & EXCEPTION_HSRR1_SOFTPATCH_MASK) ==
        EXCEPTION_HSRR1_SOFTPATCH_DENORM)
    {
        if (t->fp_context == NULL)
        {
            printk("Error: Task took Denorm-assist without FP active.\n");
            kassert(t->fp_context != NULL);
        }

        switch (CpuID::getCpuType())
        {
            case CORE_POWER8_MURANO:
            case CORE_POWER8_VENICE:
            case CORE_POWER8_NAPLES:
            case CORE_POWER9_NIMBUS:
            case CORE_POWER9_CUMULUS:
            case CORE_UNKNOWN:
                p8_softpatch_denorm_assist(t->fp_context);
                break;
        }
    }
}

const uint64_t EXCEPTION_MSR_PR_BIT_MASK       = 0x0000000000004000;
const uint64_t EXCEPTION_SRR1_LOADSTORE_ERR    = 0x0000000000200000;
const uint64_t EXCEPTION_DSISR_LD_UE_INTERRUPT = 0x0000000000008000;
const uint64_t EXCEPTION_DSISR_SLB_ERRORS      = 0x00000000000000C0;

extern "C"
void kernel_execute_machine_check()
{
    task_t* t = TaskManager::getCurrentTask();

    //PR (bit 49) = 0 indicates hypervisor mode
    //  Which indicates kernel mode in Hostboot env.
    if(!(getSRR1() & EXCEPTION_MSR_PR_BIT_MASK))
    {
        //Not much we can do to recover in Kernel, just assert
        printk("Kernel Space Machine check in %d on %ld:\n"
               "\tSRR0 = %lx, SRR1 = %lx\n"
               "\tDSISR = %lx, DAR = %lx\n",
               t->tid, getPIR(),
               getSRR0(), getSRR1(), getDSISR(), getDAR());
        kassert(false);
    }

    bool handled = false;

    // Error in load/store.
    if (getSRR1() & EXCEPTION_SRR1_LOADSTORE_ERR)
    {
        // SUE on load instruction.
        if (getDSISR() & EXCEPTION_DSISR_LD_UE_INTERRUPT)
        {
            handled = Kernel::MachineCheck::handleLoadUE(t);
        }
        // SLB parity or multi-hit.
        else if (getDSISR() & EXCEPTION_DSISR_SLB_ERRORS)
        {
            handled = Kernel::MachineCheck::handleSLB(t);
        }
    }
    // Error in instruction fetch.
    else
    {
        enum
        {
            SRR1_ERR_RESERVED = 0,              //< Reserved
            SRR1_ERR_IFU_UE = 1,                //< UE on Instruction
            SRR1_ERR_IFU_SLB_P = 2,             //< SLB Parity
            SRR1_ERR_IFU_SLB_MH = 3,            //< SLB Multihit
            SRR1_ERR_IFU_SLB_MHP = 4,           //< SLB Multihit & Parity
            SRR1_ERR_IFU_TLB_MH = 5,            //< TLB Multihit
            SRR1_ERR_IFU_TLB_MH_RELOAD = 6,     //< TLB Multihit on Reload
            SRR1_ERR_IFU_UNKNOWN = 7            //< Unknown error.
        };

        // Extract bits 43:45.
        uint64_t error = (getSRR1() >> 18) & 0x7;

        switch (error)
        {
            case SRR1_ERR_IFU_SLB_P:
            case SRR1_ERR_IFU_SLB_MH:
            case SRR1_ERR_IFU_SLB_MHP:
                handled = Kernel::MachineCheck::handleSLB(t);
                break;
        }
    }

    if (!handled)
    {
        //User Space MC
        printk("User Space Machine check in %d on %ld:\n"
                "\tSRR0 = %lx, SRR1 = %lx\n"
                "\tDSISR = %lx, DAR = %lx\n",
                t->tid, getPIR(),
                getSRR0(), getSRR1(), getDSISR(), getDAR());
        TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
    }
}

extern "C"
void kernel_execute_external()
{
    // SRR0 set to the effective addr the thread
    // would have attempted to execute next
    // SRR1 [33:36,42:47] set to zero
    //      all others copied from MSR
    InterruptMsgHdlr::handleInterrupt();
}

extern "C"
void kernel_execute_unhandled_exception()
{
    task_t* t = TaskManager::getCurrentTask();
    uint64_t exception = getSPRG2();

    printk("Unhandled exception %lx by task %d @ %p\n",
           exception, t->tid, t->context.nip);

    termWriteSRC(TI_UNHANDLED_EX, RC_UNHANDLED_EX, exception);
    terminateExecuteTI();
}
