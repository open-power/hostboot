#ifndef __TRACE_TRACEBUFFER_H
#define __TRACE_TRACEBUFFER_H

#include <stdint.h>
#include <stdlib.h>
#include <new>
#include <limits.h>
#include <sys/task.h>

struct traceEntry
{
    uint64_t component;
    tid_t tid;
    uint16_t length;
    uint32_t hash;
    uint64_t timestamp;
    uint32_t line;
    uint64_t values[0];
};


class TracePage
{
    public:
        TracePage() : next(NULL), size(0) {};

        TracePage* setNext(TracePage*);
        TracePage* getNext() { return next; };
        traceEntry* claimEntry(size_t size);

    private:
        TracePage* volatile next;
        uint64_t size;
};

class TraceBuffer
{
    public:
        TraceBuffer()
            {
                first = last = new (malloc(PAGE_SIZE)) TracePage();
            }

        traceEntry* claimEntry(size_t size);

    private:
        TracePage* first;
        TracePage* volatile last;
};

#endif
