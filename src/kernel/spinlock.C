#include <kernel/spinlock.H>

void Spinlock::lock()
{
    uint64_t reservation = __sync_fetch_and_add(&iv_reserve, 1);
    while(iv_ready != reservation);
}

void Spinlock::unlock()
{
    __sync_add_and_fetch(&iv_ready, 1);
}
