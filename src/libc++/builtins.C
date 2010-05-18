#include <stdint.h>

extern "C" int __cxa_guard_acquire(volatile uint64_t* gv)
{
    // 0 .. uninitialized
    // 1 .. locked
    // 2 .. unlocked, initialized
    if (0 == *gv)
    {
	*gv = 1;
	return 1;
    }
    else if (1 == *gv)
    {
	while(1 == *gv);
    }
    
    return 0;
}

extern "C" void __cxa_guard_release(volatile uint64_t* gv)
{
    *gv = 2;
    return;
}


extern "C" int __cxa_atexit(void (*)(void*), void*, void*)
{
    return 0;
}

void*   __dso_handle = (void*) &__dso_handle;
