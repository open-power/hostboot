#include <assert.h>
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

extern "C"
void kernel_execute_decrementer()
{
    cpu_t* c = CpuManager::getCurrentCPU();
    Scheduler* s = c->scheduler;
    TimeManager::checkReleaseTasks(s);
    s->returnRunnable();

    if (CpuManager::isShutdownRequested())
    {
        KernelMisc::shutdown();
    }

    s->setNextRunnable();
}

namespace Systemcalls
{
    typedef void(*syscall)(task_t*);
    void TaskYield(task_t*);
    void TaskStart(task_t*);
    void TaskEnd(task_t*);
    void TaskGettid(task_t*);
    void MsgQCreate(task_t*);
    void MsgQDestroy(task_t*);
    void MsgQRegisterRoot(task_t*);
    void MsgQResolveRoot(task_t*);
    void MsgSend(task_t*);
    void MsgSendRecv(task_t*);
    void MsgRespond(task_t*);
    void MsgWait(task_t*);
    void MmioMap(task_t*);
    void MmioUnmap(task_t*);
    void DevMap(task_t*);
    void DevUnmap(task_t*);
    void TimeNanosleep(task_t*);
    void FutexWait(task_t *t);
    void FutexWake(task_t *t);
    void Shutdown(task_t *t);
    void CpuCoreType(task_t *t);
    void CpuDDLevel(task_t *t);
    void MmAllocBlock(task_t *t);

    syscall syscalls[] =
	{
	    &TaskYield,  // TASK_YIELD
	    &TaskStart,  // TASK_START
	    &TaskEnd,  // TASK_END

	    &MsgQCreate,  // MSGQ_CREATE
	    &MsgQDestroy,  // MSGQ_DESTROY
	    &MsgQRegisterRoot,  // MSGQ_REGISTER_ROOT
	    &MsgQResolveRoot,  // MSGQ_RESOLVE_ROOT

	    &MsgSend,  // MSG_SEND
	    &MsgSendRecv,  // MSG_SENDRECV
	    &MsgRespond,  // MSG_RESPOND
	    &MsgWait,  // MSG_WAIT

	    &MmioMap,  // MMIO_MAP
	    &MmioUnmap,  // MMIO_UNMAP
            &DevMap,  // DEV_MAP
            &DevUnmap,  // DEV_UNMAP

	    &TimeNanosleep,  // TIME_NANOSLEEP

        &FutexWait,  // FUTEX_WAIT
        &FutexWake,  // FUTEX_WAKE

        &Shutdown,  // MISC_SHUTDOWN

        &CpuCoreType,  // MISC_CPUCORETYPE
        &CpuDDLevel,  // MISC_CPUDDLEVEL

        &MmAllocBlock, // MM_ALLOC_BLOCK
	};
};

extern "C"
void kernel_execute_system_call()
{
    using namespace Systemcalls;
    task_t* t = TaskManager::getCurrentTask();

    uint64_t syscall = t->context.gprs[3];
    if (syscall > SYSCALL_MAX)
    {
	// TODO : kill task.
	printk("Invalid syscall : %ld\n", syscall);
	while(1);
    }
    else
    {
	syscalls[syscall](t);
    }
}

#define TASK_GETARGN(t, n) (t->context.gprs[n+4])
#define TASK_GETARG0(t) (TASK_GETARGN(t,0))
#define TASK_GETARG1(t) (TASK_GETARGN(t,1))
#define TASK_GETARG2(t) (TASK_GETARGN(t,2))
#define TASK_GETARG3(t) (TASK_GETARGN(t,3))
#define TASK_GETARG4(t) (TASK_GETARGN(t,4))
#define TASK_GETARG5(t) (TASK_GETARGN(t,5))
#define TASK_GETARG6(t) (TASK_GETARGN(t,6))
#define TASK_GETARG7(t) (TASK_GETARGN(t,7))

#define TASK_SETRTN(t, n) (t->context.gprs[3] = (n))

namespace Systemcalls
{
    void TaskYield(task_t* t)
    {
	Scheduler* s = t->cpu->scheduler;
	s->returnRunnable();
	s->setNextRunnable();
    }

    void TaskStart(task_t* t)
    {
	task_t* newTask =
	    TaskManager::createTask((TaskManager::task_fn_t)TASK_GETARG0(t),
				    (void*)TASK_GETARG1(t));
	newTask->cpu = t->cpu;
	t->cpu->scheduler->addTask(newTask);

	TASK_SETRTN(t, newTask->tid);
    }

    void TaskEnd(task_t* t)
    {
	// Make sure task pointers are updated before we delete this task.
	t->cpu->scheduler->setNextRunnable();

	// TODO: Deal with join.

	// Clean up task memory.
	PageManager::freePage(t->context.stack_ptr, TASK_DEFAULT_STACK_SIZE);
	delete t;
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

    void MsgQRegisterRoot(task_t* t)
    {
	msgQRoot = (MessageQueue*) TASK_GETARG0(t);
	TASK_SETRTN(t, 0);
    }

    void MsgQResolveRoot(task_t* t)
    {
	TASK_SETRTN(t, (uint64_t) msgQRoot);
    }

    void MsgSend(task_t* t)
    {
	MessageQueue* mq = (MessageQueue*) TASK_GETARG0(t);
	msg_t* m = (msg_t*) TASK_GETARG1(t);
	m->__reserved__async = 0; // set to async msg.

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
	}

	mq->lock.unlock();
	TASK_SETRTN(t, 0);
    }

    void MsgSendRecv(task_t* t)
    {
	MessageQueue* mq = (MessageQueue*) TASK_GETARG0(t);
	msg_t* m = (msg_t*) TASK_GETARG1(t);
	m->__reserved__async = 1; // set to sync msg.

	mq->lock.lock();
	MessagePending* mp = new MessagePending();
	mp->key = m;
	mp->task = t;

	// Get waiting (server) task.
	task_t* waiter = mq->waiting.remove();
	if (NULL == waiter) // None found, add to 'messages' queue.
	{
	    mq->messages.insert(mp);
	    // Choose next thread to execute, this one is delayed.
	    t->cpu->scheduler->setNextRunnable();
	}
	else // Context switch to waiter.
	{
	    TASK_SETRTN(waiter, (uint64_t) m);
	    mq->responses.insert(mp);
	    waiter->cpu = t->cpu;
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
	    delete mp;

	    waiter->cpu = t->cpu;
	    TaskManager::setCurrentTask(waiter);
            TASK_SETRTN(waiter,0);

	    TASK_SETRTN(t,0);
	    t->cpu->scheduler->addTask(t);
	}
	else
	{
	    TASK_SETRTN(t, -1);
	}
	mq->lock.unlock();
    }

    void MsgWait(task_t* t)
    {
    	MessageQueue* mq = (MessageQueue*) TASK_GETARG0(t);

	mq->lock.lock();
	MessagePending* mp = mq->messages.remove();

	if (NULL == mp)
	{
	    mq->waiting.insert(t);
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

    void MmioMap(task_t* t)
    {
	void* ra = (void*)TASK_GETARG0(t);
	size_t pages = TASK_GETARG1(t);

	TASK_SETRTN(t, (uint64_t) VmmManager::mmioMap(ra,pages));
    }

    void MmioUnmap(task_t* t)
    {
	void* ea = (void*)TASK_GETARG0(t);
	size_t pages = TASK_GETARG1(t);

	TASK_SETRTN(t, VmmManager::mmioUnmap(ea,pages));
    }

    /**
     * Map a device into virtual memory
     * @param[in] t:  The task used to map a device
     */
    void DevMap(task_t *t)
    {
        void *ra = (void*)TASK_GETARG0(t);
        SEG_DATA_SIZES devDataSize = (SEG_DATA_SIZES)TASK_GETARG1(t);

        kassert(TASK_SETRTN(t, (uint64_t)VmmManager::devMap(ra,devDataSize)) !=
                NULL);
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

	Scheduler* s = t->cpu->scheduler;
	s->setNextRunnable();
    }

    /**
     * Put task on wait queue based on futex
     * @param[in] t:  The task to block
     */
    void FutexWait(task_t * t)
    {
        uint64_t * uaddr = (uint64_t *) TASK_GETARG0(t);
        uint64_t val   = (uint64_t) TASK_GETARG1(t);

        // Set RC to success initially.
        TASK_SETRTN(t,0);

        //TODO translate uaddr from user space to kernel space
        //     Right now they are the same.

        uint64_t rc = FutexManager::wait(t,uaddr,val);
        if (rc != 0) // Can only set rc if we still have control of the task,
                     // which is only (for certain) on error rc's.
        {
            TASK_SETRTN(t,rc);
        }
    }

    /**
     * Wake tasks on futex wait queue
     * @param[in] t:  The current task
     */
    void FutexWake(task_t * t)
    {
        uint64_t * uaddr = (uint64_t *) TASK_GETARG0(t);
        uint64_t count = (uint64_t) TASK_GETARG1(t);

        // TODO translate uaddr from user space to kernel space
        //      Right now they are the same

        uint64_t started = FutexManager::wake(uaddr,count);

        TASK_SETRTN(t,started);
    }

    /**
     * Shutdown all CPUs
     * @param[in] t:  The current task
     */
    void Shutdown(task_t * t)
    {
        uint64_t status = static_cast<uint64_t>(TASK_GETARG0(t));
        CpuManager::requestShutdown(status);
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

    /**
     * Allocate a block of virtual memory within the base segment
     * @param[in] t: The task used to allocate a block in the base segment
     */
    void MmAllocBlock(task_t* t)
    {
        MessageQueue* mq = (MessageQueue*)TASK_GETARG0(t);
        void* va = (void*)TASK_GETARG1(t);
        uint64_t size = (uint64_t)TASK_GETARG2(t);

        TASK_SETRTN(t, VmmManager::mmAllocBlock(mq,va,size));
    }

};
