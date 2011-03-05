#include <kernel/cpu.H>
#include <kernel/cpumgr.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/task.H>
#include <kernel/syscalls.H>
#include <kernel/console.H>
#include <kernel/pagemgr.H>
#include <kernel/usermutex.H>
#include <kernel/msg.H>
#include <kernel/timemgr.H>

extern "C"
void kernel_execute_decrementer()
{
    Scheduler* s = CpuManager::getCurrentCPU()->scheduler;
    TimeManager::checkReleaseTasks(s);        
    s->returnRunnable();
    s->setNextRunnable();
}

namespace Systemcalls
{
    typedef void(*syscall)(task_t*);
    void TaskYield(task_t*);
    void TaskStart(task_t*);
    void TaskEnd(task_t*);
    void TaskGettid(task_t*);
    void MutexCreate(task_t*);
    void MutexDestroy(task_t*);
    void MutexLockCont(task_t*);
    void MutexUnlockCont(task_t*);
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
    void TimeNanosleep(task_t*);

    syscall syscalls[] =
	{
	    &TaskYield,
	    &TaskStart,
	    &TaskEnd,
	    &TaskGettid,

	    &MutexCreate,
	    &MutexDestroy,
	    &MutexLockCont,
	    &MutexUnlockCont,

	    &MsgQCreate,
	    &MsgQDestroy,
	    &MsgQRegisterRoot,
	    &MsgQResolveRoot,

	    &MsgSend,
	    &MsgSendRecv,
	    &MsgRespond,
	    &MsgWait,

	    &MmioMap,
	    &MmioUnmap,

	    &TimeNanosleep,
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

    void TaskGettid(task_t* t)
    {
	TASK_SETRTN(t, t->tid);
    }

    void MutexCreate(task_t* t)
    {
	UserMutex * m = new UserMutex();
	TASK_SETRTN(t, (uint64_t)m);
    }

    void MutexDestroy(task_t* t)
    {
	// TODO: Extra verification of parameter and mutex state.

	delete (UserMutex*) TASK_GETARG0(t);
	TASK_SETRTN(t, 0);
    }

    void MutexLockCont(task_t* t)
    {
	// TODO: Extra verification of parameter and mutex state.
	
	UserMutex* m = (UserMutex*) TASK_GETARG0(t);
	m->lock.lock();
	if (m->unlock_pend) 
	{   
	    // We missed the unlock syscall, take lock and return to userspace.
	    m->unlock_pend = false;
	    m->lock.unlock();

	}
	else
	{
	    // Queue ourself to wait for unlock.
	    m->waiting.insert(TaskManager::getCurrentTask());
	    m->lock.unlock();
	    CpuManager::getCurrentCPU()->scheduler->setNextRunnable();
	}
	TASK_SETRTN(t, 0);	
    }

    void MutexUnlockCont(task_t* t)
    {
	// TODO: Extra verification of parameter and mutex state.

	UserMutex* m = (UserMutex*) TASK_GETARG0(t);
	m->lock.lock();
	task_t* wait_task = m->waiting.remove();
	if (NULL == wait_task)
	{
	    m->unlock_pend = true;
	}
	else
	{
	    wait_task->cpu->scheduler->addTask(wait_task);
	}
	m->lock.unlock();
	TASK_SETRTN(t, 0);
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
	}
	else // Context switch to waiter.
	{
	    TASK_SETRTN(waiter, (uint64_t) m);
	    mq->responses.insert(mp);
	    waiter->cpu = t->cpu;
	    TaskManager::setCurrentTask(waiter);
	}

	mq->lock.unlock();
	TASK_SETRTN(t,0);
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
	    t->cpu->scheduler->addTask(t);

	    TASK_SETRTN(t,0);
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

    void TimeNanosleep(task_t* t)
    {
	TimeManager::delayTask(t, TASK_GETARG0(t), TASK_GETARG1(t));
	TASK_SETRTN(t, 0);

	Scheduler* s = t->cpu->scheduler;
	s->setNextRunnable();
    }


};
