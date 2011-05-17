#include <stdint.h>
#include <stdlib.h>

#include <arch/ppc.H>

void* operator new(size_t s)
{
    return malloc(s);
};

void* operator new[](size_t s)
{
    return malloc(s);
};

void* operator new(size_t s, void *place)
{
    return place;
}

void* operator new[](size_t s, void *place)
{
    return place;
}

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
    // States:
    //     0 -> uninitialized
    //     1 -> locked
    //     2 -> unlocked and initialized
    
    uint32_t v = __sync_val_compare_and_swap((volatile uint32_t*)gv, 0, 1);
    if (v == 0)
	return 1;
    if (v == 2)
	return 0;
    
    // Wait for peer thread to perform initialization (state 2).
    while(2 != *(volatile uint32_t*)gv);
    
    // Instruction barrier to ensure value is set before later loads execute.
    isync(); 
    
    return 0;
}

extern "C" void __cxa_guard_release(volatile uint64_t* gv)
{
    // Memory barrier to ensure all preceeding writes have completed before
    // releasing guard.
    lwsync();

    (*(volatile uint32_t*)gv) = 2;
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
