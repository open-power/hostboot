#include <trace_adal.h>
#include <util/singleton.H>
#include <stdarg.h>
#include <arch/ppc.H>

#include "TraceBuffer.H"

int32_t trace_adal_init_buffer(trace_desc_t * td, const char* comp, 
                               const size_t size )
{
    // For now, just store the component name.
    *td = (trace_desc_t) comp;
    return 0;
}

int32_t trace_adal_write_all(const trace_desc_t td, 
                             const enum trace_hash_val hash,
                             const char * fmt,
                             const uint32_t line,
                             const int32_t type, ...)
{
    // This code is incorrect for determining formatting but will work for now.
    size_t size = 0;
    const char* _fmt = fmt;
    while ('\0' != *_fmt)
    {
        if ('%' == *_fmt)
            size++;
        _fmt++;
    }

    traceEntry* entry = 
        Singleton<TraceBuffer>::instance().claimEntry(sizeof(traceEntry) + 
                                                      sizeof(uint64_t) * size);

    entry->component = (uint64_t) td;
    entry->tid = task_gettid();
    entry->length = sizeof(uint64_t) * size;
    entry->hash = hash;
    entry->timestamp = getTB();
    entry->line = line;

    uint64_t* data = &entry->values[0];

    va_list args;
    va_start(args, type);
    for (size_t i = 0; i < size; i++)
    {
        *data = va_arg(args, uint64_t);
        data++;
    }
    va_end(args);
    return 0;
}
