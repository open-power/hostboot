//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/trace/tracebuffer.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
