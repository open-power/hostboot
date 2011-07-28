void call_dtors(void * i_dso_handle);

// This identifies the module
void*   __dso_handle = (void*) &__dso_handle;

extern "C"
void _init(void*)
{
    // Call default constructors for any static objects.
    extern void (*ctor_start_address)();
    extern void (*ctor_end_address)();
    void(**ctors)() = &ctor_start_address;
    while(ctors != &ctor_end_address)
    {
	(*ctors)();
	ctors++;
    }
}

extern "C"
void _fini(void)
{
    call_dtors(__dso_handle);
}



