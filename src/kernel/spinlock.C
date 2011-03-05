#include <kernel/spinlock.H>
#include <arch/ppc.H>

void Spinlock::lock()
{
    uint64_t reservation = __sync_fetch_and_add(&iv_reserve, 1);
    if (iv_ready != reservation)
    {
	do
	{
	    setThreadPriorityLow();
	}
	while(iv_ready != reservation);
	setThreadPriorityHigh();
    }
}

void Spinlock::unlock()
{
    __sync_add_and_fetch(&iv_ready, 1);
}
