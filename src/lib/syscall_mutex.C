#include <sys/mutex.h>
#include <sys/syscall.h>
#include <kernel/usermutex.H>

using namespace Systemcalls;

mutex_t mutex_create()
{
    return (mutex_t) _syscall0(MUTEX_CREATE);
}

int mutex_destroy(mutex_t m)
{
    return (int64_t)_syscall1(MUTEX_DESTROY, m);
}

int mutex_lock(mutex_t m)
{
    uint64_t oldvalue = __sync_fetch_and_add(&((UserMutex*)m)->value, 1);
    if (0 == oldvalue)
	return 0;
    else 
	return (int64_t)_syscall1(MUTEX_LOCK_CONTESTED, m);
}

int mutex_unlock(mutex_t m)
{
    uint64_t oldvalue = __sync_fetch_and_sub(&((UserMutex*)m)->value, 1);
    if (1 == oldvalue)
	return 0;
    else
	return (int64_t)_syscall1(MUTEX_UNLOCK_CONTESTED, m);
}
