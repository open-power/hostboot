#ifndef __KERNEL_SPINLOCK_H
#define __KERNEL_SPINLOCK_H

#include <util/locked/lock.H>
#include <stdint.h>

class Spinlock : public Util::Locked::Lock
{
    public:
	Spinlock() : iv_reserve(0), iv_ready(0) {};

	void lock();
	void unlock();

    private:
	volatile uint64_t iv_reserve;
	volatile uint64_t iv_ready;
};

#endif
