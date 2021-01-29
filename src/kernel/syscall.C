/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/syscall.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2021                        */
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
#include <errno.h>
#include <kernel/cpu.H>
#include <kernel/cpumgr.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/task.H>
#include <kernel/syscalls.H>
#include <kernel/console.H>
#include <kernel/pagemgr.H>
#include <kernel/msg.H>
#include <kernel/timemgr.H>
#include <kernel/futexmgr.H>
#include <kernel/cpuid.H>
#include <kernel/misc.H>
#include <kernel/msghandler.H>
#include <kernel/vmmmgr.H>
#include <kernel/stacksegment.H>
#include <kernel/heapmgr.H>
#include <kernel/intmsghandler.H>
#include <kernel/doorbell.H>
#include <sys/sync.h>
#include <errno.h>
#include <kernel/machchk.H>
#include <kernel/ipc.H>


extern "C"
void kernel_execute_hyp_doorbell()
{
    printkd("hyp_doorbell on %lx\n", getPIR());

    // Per POWER ISA Section 5.9.2, to avoid any weak consistency
    //  issues we must use a msgsync instruction before consuming
    //  any data set by a different thread following a doorbell
    //  wakeup.
    msgsync();

    task_t* t = TaskManager::getCurrentTask();
    task_t* l_task_post = nullptr;
    doorbell_clear();

    //Execute all work items on doorbell_actions stack
    cpu_t* l_cpu = CpuManager::getCurrentCPU();
    KernelWorkItem *l_work = l_cpu->doorbell_actions.pop();
    while(l_work != nullptr)
    {
        //Execute Work Item and then delete it
        (*l_work)();
        delete l_work;
        l_work = l_cpu->doorbell_actions.pop();
    }

    //IPC messages come in only on the master, so
    //If this is a doorbell to the master -- check
    cpu_t* master = CpuManager::getMasterCPU();
    if(l_cpu == master)
    {
        size_t pir = getPIR();
        printk("IPC msg pir %lx incoming\n", pir);
        //Send message to the intrrp in userspace indicating it has
        // potential a pending IPC message.
        InterruptMsgHdlr::sendIpcMsg(pir);
    }

    DeferredQueue::execute();

    // Mustn't switch tasks if external interrupt due to
    // the fact external interrupts come in as HYP exceptions
    // and all other come in as regular excpetions.  If HYP
    // comes on top of regular... need to leave existing task
    // as is. The custom implementation of sendMessage of InterruptMsgHdlr
    // will take care of task switching safely.

    //check to see if work switched the task
    l_task_post = TaskManager::getCurrentTask();
    kassert(t == l_task_post);
}

extern "C"
void kernel_execute_decrementer()
{
    cpu_t* c = CpuManager::getCurrentCPU();
    Scheduler* s = c->scheduler;
    TimeManager::checkReleaseTasks(s);

    task_t* current_task = TaskManager::getCurrentTask();

    CpuManager::executePeriodics(c);

    if (current_task == TaskManager::getCurrentTask())
    {
        s->returnRunnable();
        s->setNextRunnable();
    }
}

namespace Systemcalls
{
    typedef void(*syscall)(task_t*);
    void TaskYield(task_t*);
    void TaskStart(task_t*);
    void TaskEnd(task_t*);
    void TaskMigrateToMaster(task_t*);
    void TaskWait(task_t*);
    void MsgQCreate(task_t*);
    void MsgQDestroy(task_t*);
    void MsgQRegisterRoot(task_t*);
    void MsgQResolveRoot(task_t*);
    void MsgSend(task_t*);
    void MsgSendRecv(task_t*);
    void MsgRespond(task_t*);
    void MsgWait(task_t*);
    void DevMap(task_t*);
    void DevUnmap(task_t*);
    void TimeNanosleep(task_t*);
    void Futex(task_t *t);
    void Shutdown(task_t *t);
    void CpuCoreType(task_t *t);
    void CpuDDLevel(task_t *t);
    void CpuStartCore(task_t *t);
    void CpuSprValue(task_t *t);
    void CpuSprSet(task_t *t);
    void CpuNap(task_t *t);
    void CpuWinkle(task_t *t);
    void CpuWakeupCore(task_t *t);
    void MmAllocBlock(task_t *t);
    void MmRemovePages(task_t *t);
    void MmSetPermission(task_t *t);
    void MmAllocPages(task_t *t);
    void MmVirtToPhys(task_t *t);
    void MmExtend(task_t *t);
    void MmLinearMap(task_t *t);
    void CritAssert(task_t *t);
    void SetMchkData(task_t *t);
    void UpdateRemoteIpcAddr(task_t *t);
    void QryLocalIpcInfo(task_t *t);
    void SetTopologyMode(task_t *t);


    syscall syscalls[] =
    {
        &TaskYield,  // TASK_YIELD
        &TaskStart,  // TASK_START
        &TaskEnd,  // TASK_END
        &TaskMigrateToMaster, // TASK_MIGRATE_TO_MASTER
        &TaskWait, // TASK_WAIT

        &MsgQCreate,  // MSGQ_CREATE
        &MsgQDestroy,  // MSGQ_DESTROY
        &MsgQRegisterRoot,  // MSGQ_REGISTER_ROOT
        &MsgQResolveRoot,  // MSGQ_RESOLVE_ROOT

        &MsgSend,  // MSG_SEND
        &MsgSendRecv,  // MSG_SENDRECV
        &MsgRespond,  // MSG_RESPOND
        &MsgWait,  // MSG_WAIT
        &DevMap,  // DEV_MAP
        &DevUnmap,  // DEV_UNMAP

        &TimeNanosleep,  // TIME_NANOSLEEP

        &Futex,      // SYS_FUTEX operations

        &Shutdown,    // MISC_SHUTDOWN
        &CpuCoreType, // MISC_CPUCORETYPE
        &CpuDDLevel,  // MISC_CPUDDLEVEL
        &CpuStartCore, // MISC_CPUSTARTCORE
        &CpuSprValue, // MISC_CPUSPRVALUE
        &CpuSprSet,   // MISC_CPUSPRSET
        &CpuNap, // MISC_CPUNAP
        &CpuWinkle,   // MISC_CPUWINKLE
        &CpuWakeupCore,   // MISC_CPUWAKEUPCORE

        &MmAllocBlock, // MM_ALLOC_BLOCK
        &MmRemovePages, // MM_REMOVE_PAGES
        &MmSetPermission, // MM_SET_PERMISSION
        &MmAllocPages,    // MM_ALLOC_PAGES
        &MmVirtToPhys,    // MM_VIRT_TO_PHYS
        &MmExtend,        // MM_EXTEND
        &MmLinearMap,     // MM_LINEAR_MAP
        &CritAssert,  // MISC_CRITASSERT
        &SetMchkData,  // MISC_SETMCHKDATA
        &UpdateRemoteIpcAddr, // UPDATE_REMOTE_IPC_ADDR
        &QryLocalIpcInfo,  // QRY_LOCAL_IPC_INFO
        &SetTopologyMode   // MISC_SET_TOPOLOGY_MODE

    };
};

extern "C"
void kernel_execute_system_call()
{
    using namespace Systemcalls;
    task_t* t = TaskManager::getCurrentTask();

    uint64_t syscall = t->context.gprs[3];
    if (syscall >= SYSCALL_MAX)
    {
        printk("Invalid syscall : %ld\n", syscall);
        TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
    }
    else
    {
        syscalls[syscall](t);
    }
}

namespace Systemcalls
{
    void TaskYield(task_t* t)
    {
        Scheduler* s = t->cpu->scheduler;
        s->returnRunnable();
        s->setNextRunnable();

        // This call prevents a live-lock situation.
        CpuManager::executePeriodics(CpuManager::getCurrentCPU());
    }

    void TaskStart(task_t* t)
    {
        task_t* newTask =
            TaskManager::createTask((TaskManager::task_fn_t)TASK_GETARG0(t),
                                    (void*)TASK_GETARG1(t));
        newTask->cpu = t->cpu;
        t->cpu->scheduler->addTask(newTask);

        TASK_SETRTN(t, newTask->tid);

        doorbell_broadcast();
    }

    void TaskEnd(task_t* t)
    {
        TaskManager::endTask(t, (void*)TASK_GETARG0(t),
                             TASK_STATUS_EXITED_CLEAN);
    }

    void TaskMigrateToMaster(task_t* t)
    {
        // Move r6 to r3.
        //     This is needed so that this system call can be called from
        //     within a "fast" system call in start.S.  The fast system call
        //     will populate r6 with it's own syscall number.  When we return
        //     from this system call, on the master processor, we'll be back
        //     at the 'sc' instruction with r3 back to the fast syscall, and
        //     the fast syscall will be executed on the master processor.
        TASK_SETRTN(t, TASK_GETARG2(t));

        // Move task to master CPU and pick a new task.
        t->cpu->scheduler->addTaskMasterCPU(t);
        t->cpu->scheduler->setNextRunnable();
        doorbell_broadcast();
    }

    void TaskWait(task_t* t)
    {
        int64_t tid = static_cast<int64_t>(TASK_GETARG0(t));
        int* status = reinterpret_cast<int*>(TASK_GETARG1(t));
        void** retval = reinterpret_cast<void**>(TASK_GETARG2(t));

        // Validate status address and convert to kernel address.
        if (status != NULL)
        {
            uint64_t addr =
                VmmManager::findKernelAddress(
                    reinterpret_cast<uint64_t>(status));

            if (addr == (static_cast<uint64_t>(-EFAULT)))
            {
                TASK_SETRTN(t, -EFAULT);
                return;
            }
            status = reinterpret_cast<int*>(addr);
        }

        // Validate retval address and convert to kernel address.
        if (retval != NULL)
        {
            uint64_t addr =
                VmmManager::findKernelAddress(
                    reinterpret_cast<uint64_t>(retval));

            if (addr == (static_cast<uint64_t>(-EFAULT)))
            {
                TASK_SETRTN(t, -EFAULT);
                return;
            }
            retval = reinterpret_cast<void**>(addr);
        }

        // Perform wait.
        TaskManager::waitTask(t, tid, status, retval);
    }

    void MsgQCreate(task_t* t)
    {
        TASK_SETRTN(t, (uint64_t) new MessageQueue());
    }

    void MsgQDestroy(task_t* t)
    {
        MessageQueue* mq = (MessageQueue*) TASK_GETARG0(t);
        if (NULL != mq)
            delete mq;
        TASK_SETRTN(t, 0);
    }

    static MessageQueue* msgQRoot = NULL;
    static MessageQueue* msgQIntr = NULL;

    void MsgQRegisterRoot(task_t* t)
    {
        switch(TASK_GETARG0(t))
        {
            case MSGQ_ROOT_VFS:
                msgQRoot = (MessageQueue*) TASK_GETARG1(t);
                TASK_SETRTN(t,0);
                break;

            case MSGQ_ROOT_INTR:
                {
                    msgQIntr = (MessageQueue*) TASK_GETARG1(t);
                    uint64_t ipc_addr = (uint64_t) TASK_GETARG2(t);
                    InterruptMsgHdlr::create(msgQIntr,ipc_addr);
                    TASK_SETRTN(t,0);
                }
                break;

            default:
                printk("ERROR MsgRegisterRoot invalid type %ld\n",
                       TASK_GETARG0(t));
                TASK_SETRTN(t,-EINVAL);
        }
    }

    void MsgQResolveRoot(task_t* t)
    {
        switch(TASK_GETARG0(t))
        {
            case MSGQ_ROOT_VFS:
                TASK_SETRTN(t, (uint64_t) msgQRoot);
                break;

            case MSGQ_ROOT_INTR:
                TASK_SETRTN(t, (uint64_t) msgQIntr);
                break;

            default:
                printk("ERROR MsgQResolveRoot invalid type %ld\n",
                       TASK_GETARG0(t));
                TASK_SETRTN(t,0);
        }
    }

    void MsgSend(task_t* t)
    {
        uint64_t q_handle = TASK_GETARG0(t);
        msg_t* m = (msg_t*) TASK_GETARG1(t);
        int rc = 0;

        if(((q_handle >> 32) & MSGQ_TYPE_IPC) != 0)
        {
            rc = KernelIpc::send(q_handle, m);
        }
        else
        {

            MessageQueue* mq = reinterpret_cast<MessageQueue*>(q_handle);

            if ((NULL == mq) || (NULL == m))
            {
                printkd("NULL pointer for message queue (%p) or message (%p).\n",
                        mq, m);
                TASK_SETRTN(t, -EINVAL);
                return;
            }

            m->__reserved__async = 0; // set to async msg.

            if (m->type >= MSG_FIRST_SYS_TYPE)
            {
                printkd("Invalid type for msg_send, type=%d.\n", m->type);
                TASK_SETRTN(t, -EINVAL);
                return;
            }

            mq->lock.lock();

            // Get waiting (server) task.
            task_t* waiter = mq->waiting.remove();
            if (NULL == waiter) // None found, add to 'messages' queue.
            {
                MessagePending* mp = new MessagePending();
                mp->key = m;
                mp->task = t;
                mq->messages.insert(mp);
            }
            else // Add waiter back to its scheduler.
            {
                TASK_SETRTN(waiter, (uint64_t) m);
                waiter->cpu->scheduler->addTask(waiter);
                doorbell_broadcast();
            }

            mq->lock.unlock();
        }
        TASK_SETRTN(t, rc);
    }

    void MsgSendRecv(task_t* t)
    {
        MessageQueue* mq = (MessageQueue*) TASK_GETARG0(t);
        msg_t* m = (msg_t*) TASK_GETARG1(t);
        MessageQueue* mq2 = (MessageQueue*) TASK_GETARG2(t);

        m->__reserved__async = 1; // set to sync msg.
        if (NULL != mq2) // set as pseudo-sync if secondary queue given.
        {
            m->__reserved__pseudosync = 1;
        }

        if (m->type >= MSG_FIRST_SYS_TYPE)
        {
            printk("Invalid message type for msg_sendrecv, type=%d.\n",
                    m->type);
            TASK_SETRTN(t, -EINVAL);
            return;
        }

        // Create pending response object.
        MessagePending* mp = new MessagePending();
        mp->key = m;
        if (!m->__reserved__pseudosync) // Normal sync, add task to pending obj.
        {
            mp->task = t;
            t->state = TASK_STATE_BLOCK_MSG;
            t->state_info = mq;
        }
        else // Pseudo-sync, add the secondary queue instead.
        {
            mp->task = reinterpret_cast<task_t*>(mq2);
            TASK_SETRTN(t, 0);  // Need to give good RC for the caller, since
                                // we are returning immediately.
        }

        mq->lock.lock();

        // Get waiting (server) task.
        task_t* waiter = mq->waiting.remove();
        if (NULL == waiter) // None found, add to 'messages' queue.
        {
            mq->messages.insert(mp);
            if (!m->__reserved__pseudosync)
            {
                // Choose next task to execute, this one is delayed.
                t->cpu->scheduler->setNextRunnable();
            } // For pseudo-sync, just keep running the current task.
        }
        else // Context switch to waiter.
        {
            TASK_SETRTN(waiter, (uint64_t) m);
            mq->responses.insert(mp);
            waiter->cpu = t->cpu;
            if (m->__reserved__pseudosync) // For pseudo-sync, add this task
                                           // back to scheduler.
            {
                t->cpu->scheduler->addTask(t);
                doorbell_broadcast();
            }
            TaskManager::setCurrentTask(waiter);
        }

        mq->lock.unlock();
    }

    void MsgRespond(task_t* t)
    {
        MessageQueue* mq = (MessageQueue*) TASK_GETARG0(t);
        msg_t* m = (msg_t*) TASK_GETARG1(t);

        mq->lock.lock();
        MessagePending* mp = mq->responses.find(m);
        if (NULL != mp)
        {
            task_t* waiter = mp->task;

            mq->responses.erase(mp);
            mq->lock.unlock();
            delete mp;

            // Kernel message types are handled by MessageHandler objects.
            if (m->type >= MSG_FIRST_SYS_TYPE)
            {
                TASK_SETRTN(t,
                            ((MessageHandler*)waiter)->recvMessage(m));

                if (TaskManager::getCurrentTask() != t)
                {
                    t->cpu->scheduler->addTask(t);
                    doorbell_broadcast();
                }
            }
            // Pseudo-sync messages are handled by pushing the response onto
            // a message queue.
            else if (m->__reserved__pseudosync)
            {
                MessageQueue* mq2 = (MessageQueue*) waiter;
                mq2->lock.lock();

                // See if there is a waiting task (the original client).
                task_t* client = mq2->waiting.remove();
                if (NULL == client) // None found, add to queue.
                {
                    MessagePending* mp2 = new MessagePending();
                    mp2->key = m;
                    mp2->task = t;
                    mq2->messages.insert(mp2);
                }
                else // Add waiting task onto its scheduler.
                {
                    TASK_SETRTN(client, (uint64_t) m);
                    client->cpu->scheduler->addTask(client);
                    doorbell_broadcast();
                }

                mq2->lock.unlock();
                TASK_SETRTN(t, 0);

            }
            // Normal-sync messages are handled by releasing the deferred task.
            else
            {
                waiter->cpu = t->cpu;
                TaskManager::setCurrentTask(waiter);
                TASK_SETRTN(waiter,0);

                TASK_SETRTN(t,0);
                t->cpu->scheduler->addTask(t);
                doorbell_broadcast();
            }
        }
        else
        {
            TASK_SETRTN(t, -EBADF);
            mq->lock.unlock();
        }
    }

    void MsgWait(task_t* t)
    {
        MessageQueue* mq = (MessageQueue*) TASK_GETARG0(t);

        mq->lock.lock();
        MessagePending* mp = mq->messages.remove();

        if (NULL == mp)
        {
            mq->waiting.insert(t);
            t->state = TASK_STATE_BLOCK_MSG;
            t->state_info = mq;
            t->cpu->scheduler->setNextRunnable();
        }
        else
        {
            msg_t* m = mp->key;
            if (m->__reserved__async)
                mq->responses.insert(mp);
            else
                delete mp;
            TASK_SETRTN(t, (uint64_t) m);
        }
        mq->lock.unlock();
    }

    /**
     * Map a device into virtual memory
     * @param[in] t:  The task used to map a device
     */
    void DevMap(task_t *t)
    {
        void *ra = (void*)TASK_GETARG0(t);
        uint64_t devDataSize = ALIGN_PAGE(TASK_GETARG1(t));
        bool cacheable = (0 != TASK_GETARG2(t));
        bool guarded = (0 != TASK_GETARG3(t));

        if (TASK_GETARG0(t) & (PAGESIZE - 1)) // ensure address page alignment.
        {
            TASK_SETRTN(t, NULL);
        }
        else if (devDataSize > THIRTYTWO_GB)
        {
            TASK_SETRTN(t, NULL);
        }
        else
        {
            TASK_SETRTN(t,
                        (uint64_t)VmmManager::devMap(
                            ra,devDataSize,cacheable,guarded));
        }
    }

    /**
     * Unmap a device from virtual memory
     * @param[in] t:  The task used to unmap a device
     */
    void DevUnmap(task_t *t)
    {
        void *ea = (void*)TASK_GETARG0(t);

        TASK_SETRTN(t, VmmManager::devUnmap(ea));
    }

    void TimeNanosleep(task_t* t)
    {
        TimeManager::delayTask(t, TASK_GETARG0(t), TASK_GETARG1(t));
        TASK_SETRTN(t, 0);

        t->cpu->scheduler->setNextRunnable();
    }


    void Futex(task_t * t)
    {
        uint64_t op = static_cast<uint64_t>(TASK_GETARG0(t));
        uint64_t futex = static_cast<uint64_t>(TASK_GETARG1(t));
        uint64_t val = static_cast<uint64_t>(TASK_GETARG2(t));
        uint64_t val2 = static_cast<uint64_t>(TASK_GETARG3(t));
        uint64_t futex2 = static_cast<uint64_t>(TASK_GETARG4(t));
        uint64_t rc = 0;

        // Set RC to success initially.
        TASK_SETRTN(t,0);

        futex = VmmManager::findKernelAddress(futex);
        if(futex == (static_cast<uint64_t>(-EFAULT)))
        {
            printk("Task %d terminated. No physical address found for address 0x%p",
                   t->tid,
                   reinterpret_cast<void *>(futex));

            TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
            return;
        }

        uint64_t * futex_p = reinterpret_cast<uint64_t *>(futex);

        switch(op)
        {
            case FUTEX_WAIT: // Put task on wait queue based on futex

                rc = FutexManager::wait(t, futex_p, val);

                // Can only be set rc if control of the task is still had,
                // which is only, for certain, on error rc's
                if(rc != 0)
                {
                    TASK_SETRTN(t,rc);
                }
                break;

            case FUTEX_WAKE: // Wake task(s) on the futex wait queue

                rc = FutexManager::wake(futex_p, val);
                TASK_SETRTN(t,rc);
                break;

            case FUTEX_REQUEUE:
                // Wake (val) task(s) on futex && requeue remaining tasks on futex2

                futex2 = VmmManager::findKernelAddress(futex2);
                if(futex2 == (static_cast<uint64_t>(-EFAULT)))
                {
                    printk("Task %d terminated. No physical address found for address 0x%p",
                           t->tid,
                           reinterpret_cast<void *>(futex2));

                    TaskManager::endTask(t, NULL, TASK_STATUS_CRASHED);
                    return;
                }

                rc = FutexManager::wake(futex_p, val,
                                        reinterpret_cast<uint64_t *>(futex2),
                                        val2);
                break;

            default:
                printk("ERROR Futex invalid op %ld\n",op);
                TASK_SETRTN(t,static_cast<uint64_t>(-EINVAL));
        };
    }


    /**
     * Shutdown all CPUs
     * @param[in] t:  The current task
     */
    void Shutdown(task_t * t)
    {
        uint64_t status = static_cast<uint64_t>(TASK_GETARG0(t));
        KernelMisc::g_payload_base = static_cast<uint64_t>(TASK_GETARG1(t));
        KernelMisc::g_payload_entry = static_cast<uint64_t>(TASK_GETARG2(t));
        KernelMisc::g_payload_data = static_cast<uint64_t>(TASK_GETARG3(t));
        KernelMisc::g_masterHBInstance= static_cast<uint64_t>(TASK_GETARG4(t));
        KernelMisc::g_error_data= static_cast<uint32_t>(TASK_GETARG5(t));
        CpuManager::requestShutdown(status, KernelMisc::g_error_data);
        TASK_SETRTN(t, 0);
    }

    /** Read CPU Core type using CpuID interfaces. */
    void CpuCoreType(task_t *t)
    {
        TASK_SETRTN(t, CpuID::getCpuType());
    }

    /** Read CPU DD level using CpuID interfaces. */
    void CpuDDLevel(task_t *t)
    {
        TASK_SETRTN(t, CpuID::getCpuDD());
    }

    /** Prep core for activation. */
    void CpuStartCore(task_t *t)
    {
        // This will cause another task to be scheduled in while the
        // core is started.
        CpuManager::startCore(static_cast<uint64_t>(TASK_GETARG0(t)),
                              static_cast<uint64_t>(TASK_GETARG1(t)));
    };

    /** Read SPR values. */
    void CpuSprValue(task_t *t)
    {
        uint64_t spr = TASK_GETARG0(t);
        uint64_t l_smf_bit = 0x0;

        switch (spr)
        {
            case CPU_SPR_MSR:
                //Set SMF bit based on current setting (HB never turns off)
                l_smf_bit = getMSR() & MSR_SMF_MASK;
                TASK_SETRTN(t, WAKEUP_MSR_VALUE | l_smf_bit);
                break;

            case CPU_SPR_LPCR:
                TASK_SETRTN(t, WAKEUP_LPCR_VALUE);
                break;

            case CPU_SPR_HRMOR:
                TASK_SETRTN(t, getHRMOR());
                break;

            case CPU_SPR_HID:
                TASK_SETRTN(t, getHID());
                break;

            default:
                TASK_SETRTN(t, -1);
                break;
        }
    };

    /** Set SPR values. */
    void CpuSprSet(task_t *t)
    {
        uint64_t spr = TASK_GETARG0(t);
        uint64_t newValue = TASK_GETARG1(t);

        switch (spr)
        {
            case CPU_SPR_HID:
                setHID( newValue );
                TASK_SETRTN(t, true);
                break;

            default:
                // unsupported SPR for write
                TASK_SETRTN(t, false);
                break;
        }
    };

    /**
     *  Allow a task to request privilege escalation to execute the 'nap'
     *  instruction.
     *
     *  Verifies the instruction to execute is, in fact, nap and then sets
     *  an MSR mask in the task structure to allow escalation on next
     *  execution.
     *
     *  When 'nap' is executed the processor will eventually issue an
     *  SRESET exception with flags in srr1 to indication that the
     *  decrementer caused the wake-up.  The kernel will then need to
     *  advance the task to the instruction after the nap and remove
     *  privilege escalation.
     *
     */
    void CpuNap(task_t *t)
    {

        // This call prevents a live-lock situation, but is expensive
        // as more threads/memory come online.  Only use for small
        // (low core) environments (decrementer still calls)
        if(PageManager::isSmallMemEnv())
        {
            CpuManager::executePeriodics(CpuManager::getCurrentCPU());
        }

        uint32_t* instruction = static_cast<uint32_t*>(t->context.nip);
        if (STOP_INSTRUCTION == (*instruction)) // Verify 'nap' instruction,
                                                // otherwise just return.
        {
            // Disable HV, EE, PR, IR, DR so 'nap' can be executed.
            //     (which means to stay in HV state)
            t->context.msr_mask = 0x100000000000D030;
        }
    };

    /** Winkle all the threads. */
    void CpuWinkle(task_t *t)
    {
        cpu_t* cpu = CpuManager::getCurrentCPU();

        if ((WINKLE_SCOPE_MASTER == TASK_GETARG0(t) &&
                (CpuManager::getCpuCount() > CpuManager::getThreadCount())) ||
            (!cpu->master))
        {
            TASK_SETRTN(t, -EDEADLK);
        }
        else
        {
            TASK_SETRTN(t, 0);
            DeferredWork* deferred = NULL;
            if (WINKLE_SCOPE_MASTER == TASK_GETARG0(t))
            {
                bool  l_fusedCores = (bool)TASK_GETARG1(t);
                deferred = new KernelMisc::WinkleCore(t, l_fusedCores);
            }
            else
            {
                deferred = new KernelMisc::WinkleAll(t);
            }
            t->state = TASK_STATE_BLOCK_USRSPACE;
            t->state_info = deferred;
            DeferredQueue::insert(deferred);
            TaskManager::setCurrentTask(cpu->idle_task);
            DeferredQueue::execute();
        }
    }

    /** Force thread wakeup via doorbell. */
    void CpuWakeupCore(task_t *t)
    {
        CpuManager::wakeupCore(static_cast<uint64_t>(TASK_GETARG0(t)),
                               static_cast<uint64_t>(TASK_GETARG1(t)));
    };

    /**
     * Allocate a block of virtual memory within the base segment
     * @param[in] t: The task used to allocate a block in the base segment
     */
    void MmAllocBlock(task_t* t)
    {
        MessageQueue* mq = (MessageQueue*)TASK_GETARG0(t);
        void* va = (void*)TASK_GETARG1(t);
        uint64_t size = (uint64_t)TASK_GETARG2(t);

        if (TASK_GETARG1(t) & (PAGESIZE - 1)) // ensure address page alignment.
        {
            TASK_SETRTN(t, NULL);
        }
        else
        {
            TASK_SETRTN(t, VmmManager::mmAllocBlock(mq,va,size));
        }
    }

    /**
     * Remove pages from virtual memory
     * @param[in] t: The task used to remove pages
     */
    void MmRemovePages(task_t* t)
    {
        VmmManager::PAGE_REMOVAL_OPS oper =
                (VmmManager::PAGE_REMOVAL_OPS)TASK_GETARG0(t);
        void* vaddr = (void*)TASK_GETARG1(t);
        uint64_t size = (uint64_t)TASK_GETARG2(t);

        TASK_SETRTN(t, VmmManager::mmRemovePages(oper,vaddr,size,t));
    }

     /**
     * Set the Permissions on a block containing the virtual address passed in.
     * @param[in] t: The task used to set Page Permissions for a given block
     */
    void MmSetPermission(task_t* t)
    {
        void* va = (void*)TASK_GETARG0(t);
        uint64_t size = (uint64_t)TASK_GETARG1(t);
        PAGE_PERMISSIONS access_type = (PAGE_PERMISSIONS)TASK_GETARG2(t);

        TASK_SETRTN(t, VmmManager::mmSetPermission(va,size, access_type));
    }

    /**
     * Call PageManager to allocate a number of pages.
     * @param[in] t: The task used.
     */
    void MmAllocPages(task_t* t)
    {
        ssize_t pages = TASK_GETARG0(t);

        // Attempt to allocate the page(s).
        void* page = PageManager::allocatePage(pages, true);
        TASK_SETRTN(t, reinterpret_cast<uint64_t>(page));

        // If we are low on memory, call into the VMM to free some up.
        uint64_t pcntAvail = PageManager::queryAvail();
        if (pcntAvail < PageManager::LOWMEM_NORM_LIMIT)
        {
            static uint64_t one_at_a_time = 0;
            if (!__sync_lock_test_and_set(&one_at_a_time, 1))
            {
                VmmManager::flushPageTable();
                VmmManager::castout_t sev =
                    (pcntAvail < PageManager::LOWMEM_CRIT_LIMIT) ?
                        VmmManager::CRITICAL : VmmManager::NORMAL;
                VmmManager::castOutPages(sev);
                __sync_lock_release(&one_at_a_time);
            }
        }
        else if ((page == NULL) && (pages > 1))
        {
            CpuManager::forceMemoryPeriodic();
        }

    }

     /**
      * Return the physical address backing a virtual address
      * @param[in] t: The task used
      */
    void MmVirtToPhys(task_t* t)
    {
        uint64_t i_vaddr = (uint64_t)TASK_GETARG0(t);
        uint64_t phys = VmmManager::findPhysicalAddress(i_vaddr);
        TASK_SETRTN(t, phys);
    }

    /**
     * Extends the initial footprint of the image further into memory.
     *
     * Depending on the syscall parameter, we will either switch from 4MB
     * to a cache-contained mode (either full 10MB or reduced 8MB) or will
     * expand into VMM_MEMORY_SIZE of space using real system memory.

     * @param[in] t: The task used to extend Memory
     */
    void MmExtend(task_t* t)
    {
        uint64_t size = TASK_GETARG0(t);

        switch (size)
        {
            case MM_EXTEND_REAL_MEMORY:
                TASK_SETRTN(t, VmmManager::mmExtend());
                break;

            default:
                TASK_SETRTN(t, -EINVAL);
                break;
        }
    }

    /**
     * Allocates a block of memory of the given size
     * to at a specified physical address
     */
    void MmLinearMap(task_t* t)
    {
        void* paddr = (void *)TASK_GETARG0(t);
        uint64_t size = (uint64_t)TASK_GETARG1(t);

        TASK_SETRTN(t, VmmManager::mmLinearMap(paddr,size));
    }

    /**
     * Call Crit assert to perform the terminate Immediate
     * @param[in] t: the task calling the critical assert
     */
    void CritAssert(task_t* t)
    {
        uint64_t i_failAddr = (uint64_t)(TASK_GETARG0(t));

        CpuManager::critAssert(i_failAddr);
    }

    /**
     *  @brief Tells the kernel how to force a checkstop for unrecoverable
     *         machine checks
     * @param[in] t: the task calling the critical assert
     */
    void SetMchkData(task_t* t)
    {
        uint64_t i_xstopAddr = (uint64_t)(TASK_GETARG0(t));
        uint64_t i_xstopData = (uint64_t)(TASK_GETARG1(t));

        Kernel::MachineCheck::setCheckstopData(i_xstopAddr,i_xstopData);
    }

    /**
     *  @brief Tells the kernel the address of the Remote IPC buffer
     *         for a given Node
     * @param[in] t: the task calling the update function
     */
    void UpdateRemoteIpcAddr(task_t* t)
    {
        uint64_t i_Node = TASK_GETARG0(t);
        uint64_t i_RemoteAddr = TASK_GETARG1(t);
        int rc = KernelIpc::updateRemoteIpcAddr(i_Node, i_RemoteAddr);
        TASK_SETRTN(t, rc);
    }

    /**
     *  @brief Query the local node and IPC buffer info
     * @param[in] t: the task calling the update function
     */
    void QryLocalIpcInfo(task_t* t)
    {
        uint64_t * i_pONode = (uint64_t *)TASK_GETARG0(t);
        uint64_t * i_pOAddr = (uint64_t *)TASK_GETARG1(t);
        int rc = KernelIpc::qryLocalIpcInfo(i_pONode, i_pOAddr);
        TASK_SETRTN(t, rc);
    }

    void SetTopologyMode(task_t* t)
    {
        uint8_t i_topologyMode = (uint8_t)TASK_GETARG0(t);

        KernelIpc::setTopologyMode(i_topologyMode);
    }

};

