/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/exception.C $                                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2013              */
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
            // priviledge raised.
            if (*instruction == 0x4c000364)
            {
                printk("Error: Nap executed with lowered permissions on %d\n",
                       t->tid);
                t->context.nip = static_cast<void*>(instruction + 1);
                return true;
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
            case CORE_UNKNOWN:
                p8_softpatch_denorm_assist(t->fp_context);
                break;
        }
    }
}

const uint64_t EXCEPTION_MSR_PR_BIT_MASK       = 0x0000000000004000;
const uint64_t EXCEPTION_SRR1_LOADSTORE_ERR    = 0x0000000000200000;
const uint64_t EXCEPTION_DSISR_LDX_UE_INTERRUPT = 0x0000000000008000;
const uint32_t EXCEPTION_LDX_INSTR_MASK        = 0xFC0007FE;
const uint32_t EXCEPTION_LDX_INSTR             = 0x7C00002A;
const uint32_t EXCEPTION_RA_MASK               = 0x001F0000;
const uint32_t EXCEPTION_RB_MASK               = 0x0000F800;
const uint32_t EXCEPTION_RT_MASK               = 0x03E00000;

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

    //User Space MC
    printk("User Space Machine check in %d on %ld:\n"
           "\tSRR0 = %lx, SRR1 = %lx\n"
           "\tDSISR = %lx, DAR = %lx\n",
           t->tid, getPIR(),
           getSRR0(), getSRR1(), getDSISR(), getDAR());


    //Determine if this Machine Check was triggered by a SUE on
    //CI (Cache Inhibited) Load.
    if(!((getSRR1() & EXCEPTION_SRR1_LOADSTORE_ERR) &&
         (getDSISR() & EXCEPTION_DSISR_LDX_UE_INTERRUPT)))
    {
        //SUE not caused by CI Load, unhandled exception.
        TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
    }

    //Get instruction that caused the SUE
    uint64_t phys_addr = VmmManager::findKernelAddress(
               reinterpret_cast<uint64_t>(t->context.nip));

    sync();
    uint32_t* instruction = reinterpret_cast<uint32_t*>(phys_addr);

    if(!((*instruction & EXCEPTION_LDX_INSTR_MASK) ==
         EXCEPTION_LDX_INSTR))
    {
        //Not an LDX instruction, unhandled exception
        printk("kernel_execute_machine_check: Instruction 0x%.8x not an LDX instruction.  Ending task\n", *instruction);
        TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);

    }

    //Compute the accessed address
    uint32_t rA = (*instruction & EXCEPTION_RA_MASK) >> 16;
    uint32_t rB = (*instruction & EXCEPTION_RB_MASK) >> 11;

    uint64_t vaddr = 0;
    if(rA != 0)
    {
        vaddr = t->context.gprs[rA] +
          t->context.gprs[rB];
    }
    else
    {
        vaddr = t->context.gprs[rB];
    }

    uint64_t phys = VmmManager::findPhysicalAddress(vaddr);

    //Check if address is in IBSCOM MMIO Range.
    if( (phys >= MMIO_IBSCOM_START) &&
        (phys <= MMIO_IBSCOM_END) )
    {
        //Read occured during IBSCOM read.  Indicate error to caller
        //by setting known pattern (ascii SCOMFAIL) in rT
        uint32_t rT = (*instruction & EXCEPTION_RT_MASK) >> 21;

        //set rT = MMIO_IBSCOM_UE_DETECTED
        t->context.gprs[rT] = MMIO_IBSCOM_UE_DETECTED;
        //Advance to next instruction
        uint32_t* nextInst = reinterpret_cast<uint32_t*>(t->context.nip);
        nextInst++;
        t->context.nip = reinterpret_cast<void*>(nextInst);
    }
    else
    {
        printk("kernel_execute_machine_check: Unrecognized memory address(%lx) - ending Task\n",
               phys);
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
