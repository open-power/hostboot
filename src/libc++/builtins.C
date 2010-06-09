#include <stdint.h>
#include <stdlib.h>

void* operator new(size_t s)
{
    return malloc(s);
};

void* operator new[](size_t s)
{
    return malloc(s);
};

void operator delete(void* p)
{
    return free(p);
};

void operator delete[](void* p)
{
    return free(p);
};

extern "C" int __cxa_guard_acquire(volatile uint64_t* gv)
{
    // 0 -> uninitialized
    // 1 -> locked
    // 2 -> unlocked and initialized
    
    uint32_t v = __sync_val_compare_and_swap((volatile uint32_t*)gv, 0, 1);
    if (v == 0)
	return 1;
    if (v == 2)
	return 0;
    while(2 != *(volatile uint32_t*)gv);
    return 0;
/*
    register volatile void* guard = gv;
    register uint32_t c = 0;

    asm volatile(
	"__cxa_guard_acquire_begin:"
	"lwarx %0,0,%1;"	// Load guard with reserve
	"cmpi 0,%0,0;"		// Compare with 0
	"bne+ __cxa_guard_acquire_finish;"	// != 0, goto "finished"
	"li %0, 1;"		// Set to 1.
	"stwcx. %0,0,%1;"	// Store against reserve
	"bne- __cxa_guard_acquire_begin;"	// goto begin if failed store.
	"li %0, 3;"		// Set to 3 -> success in lock
	"__cxa_guard_acquire_finish:" 
	    : "+r" (c) : "r" (guard): "memory","cc"
    );
    while (2 > c)
    {
	asm volatile("lwz %0, 0(%1);" : "=r" (c) : "r" (guard));
    }
    return (3 == c ? 1 : 0);  // 3 means success in lock, return 1 (obtained)
			      // 2 means initialized, return 0
*/
}

extern "C" void __cxa_guard_release(volatile uint64_t* gv)
{
    (*(volatile uint32_t*)gv) = 2;
    /*
    register volatile void* guard = gv;
    register uint32_t c = 2;
    asm volatile("stw %0, 0(%1)" :: "r"(c) , "r" (guard): "memory");
    */
    return;
}


extern "C" int __cxa_atexit(void (*)(void*), void*, void*)
{
    return 0;
}

extern "C" void __cxa_pure_virtual()
{
    // TODO: Add better code for invalid pure virtual call.
    while(1);
}

void*   __dso_handle = (void*) &__dso_handle;
