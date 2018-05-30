/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/runtime/test/testrsvdtracebuf.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <cxxtest/TestSuite.H>

#include <trace/runtime/rt_rsvdtracebuffer.H>     // TRACE::RsvdTraceBuffer
#include <trace/runtime/rt_rsvdtracebufservice.H> // TRACE::RsvdTraceBufService
#include <trace/entry.H>             // TRACE::Entry
#include <trace/compdesc.H>          // TRACE::ComponentDesc
#include <util/runtime/util_rt.H>    // hb_get_rt_rsvd_mem

#include <stdint.h>                  // uint32_t
#include <stdlib.h>                  // malloc
#include <string.h>                  // memset


class RsvdTraceBuffTestSuite : public CxxTest::TestSuite
{
public:

// Let's start with some simple tests - the constructor
void testRsvdTraceBuffConstructor()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    TRACE::RsvdTraceBuffer l_rsvd;

    if (nullptr != l_rsvd.iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: beginning buffer boundary is not null",
                __FILE__, __func__);
    }

    if (nullptr != l_rsvd.iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: ending buffer boundary is not null",__FILE__, __func__);
    }

    if (nullptr != l_rsvd.iv_ptrToHead)
    {
        TS_FAIL("%s:%s: list head is not null", __FILE__, __func__);
    }

    if (nullptr != l_rsvd.getListHead())
    {
        TS_FAIL("%s:%s: list head is not null", __FILE__, __func__);
    }

    if (false != l_rsvd.iv_isBufferValid)
    {
        TS_FAIL("%s:%s: buffer validity is not false", __FILE__, __func__);
    }

    if (false != l_rsvd.isBufferValid())
    {
        TS_FAIL("%s:%s: buffer validity is not false", __FILE__, __func__);
    }

    if (true != l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is NOT empty", __FILE__, __func__);
    }

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
} // void testRsvdTraceBuffConstructor()

// Some more simple tests - the initializer
void testRsvdTraceBuffInit()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    // Create a buffer
    uint32_t l_bufferSize = 40;
    char *l_buffer = reinterpret_cast<char*>(malloc(l_bufferSize));
    memset(l_buffer, 0 , l_bufferSize);

    // Get the address of buffer; just like we would get in "real life"
    uintptr_t l_bufferAddr = reinterpret_cast<uintptr_t>(l_buffer);

    // Get a pointer to where the HEAD needs to reside in the buffer
    uintptr_t *l_addressToHead = reinterpret_cast<uintptr_t *>(l_bufferAddr);

    // Initialize the buffer
    TRACE::RsvdTraceBuffer l_rsvd;
    l_rsvd.init(l_bufferSize - sizeof(uintptr_t),
                l_bufferAddr + sizeof(uintptr_t),
                l_addressToHead);

    char* l_bufferBegin = reinterpret_cast<char*>(l_bufferAddr +
                                                        sizeof(uintptr_t));
    char* l_bufferEnd = reinterpret_cast<char*>(l_bufferAddr +
                                                        l_bufferSize - 1);

    if (l_bufferBegin != l_rsvd.iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: beginning buffer boundary is not null",
                __FILE__, __func__);
    }

    if (l_bufferEnd != l_rsvd.iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: ending buffer boundary not set properly",
                __FILE__, __func__);
    }

    if (true != l_rsvd.iv_isBufferValid)
    {
        TS_FAIL("%s:%s: buffer validity is not true", __FILE__, __func__);
    }

    if (true != l_rsvd.isBufferValid())
    {
        TS_FAIL("%s:%s: buffer validity is not true", __FILE__, __func__);
    }

    if (nullptr == l_rsvd.iv_ptrToHead)
    {
        TS_FAIL("%s:%s: list head is Null", __FILE__, __func__);
    }

    if (nullptr != l_rsvd.getListHead())
    {
        TS_FAIL("%s:%s: list head is NOT NULL", __FILE__, __func__);
    }

    if (l_bufferAddr != reinterpret_cast<uintptr_t>(l_rsvd.iv_ptrToHead))
    {
        TS_FAIL("%s:%s: Pointer to list is not correct", __FILE__, __func__);
    }

    if (true != l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is not empty", __FILE__, __func__);
    }

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
}  // end void testRsvdTraceBuffInit()

// Test where buffer is too small to accommodate any Entry size
void testRsvdTraceBuffBufferToSmall()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    uint32_t l_bufferSize = ALIGN_8(sizeof(TRACE::Entry)) -1;
    TRACE::RsvdTraceBuffer l_rsvd;
    char *l_buffer = initializeRsvdBuffer(l_bufferSize, l_rsvd);

    if (l_rsvd.getBufferSize() != l_bufferSize)
    {
        TS_FAIL("%s:%s: buffer size is not correct", __FILE__, __func__);
    }

    TRACE::Entry* l_entry = l_rsvd.insertEntry(0);
    if (nullptr != l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is NOT null", __FILE__, __func__);
    }

    if (true != l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is not empty", __FILE__, __func__);
    }

    if (reinterpret_cast<uintptr_t>(l_buffer) !=
        reinterpret_cast<uintptr_t>(l_rsvd.iv_ptrToHead))
    {
        TS_FAIL("%s:%s: Pointer to list is not correct", __FILE__, __func__);
    }

    l_entry = l_rsvd.insertEntry(1);
    if (nullptr != l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is NOT null", __FILE__, __func__);
    }

    if (true != l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is not empty", __FILE__, __func__);
    }

    if (reinterpret_cast<uintptr_t>(l_buffer) !=
        reinterpret_cast<uintptr_t>(l_rsvd.iv_ptrToHead))
    {
        TS_FAIL("%s:%s: Pointer to list is not correct", __FILE__, __func__);
    }

    l_entry = l_rsvd.insertEntry(sizeof(TRACE::Entry));
    if (nullptr != l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is NOT null", __FILE__, __func__);
    }

    if (true != l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is not empty", __FILE__, __func__);
    }

    if (reinterpret_cast<uintptr_t>(l_buffer) !=
        reinterpret_cast<uintptr_t>(l_rsvd.iv_ptrToHead))
    {
        TS_FAIL("%s:%s: Pointer to list is not correct", __FILE__, __func__);
    }

    free(l_buffer);

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
} // end void testRsvdTraceBuffBufferToSmall()

// Test where buffer is just the right size to fit a single Entry
void testRsvdTraceBuffOnlyAccommodateOneItem()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    TRACE::RsvdTraceBuffer l_rsvd;
    uint32_t l_bufferSize = ALIGN_8(sizeof(TRACE::Entry));
    uint32_t l_entrySize = l_bufferSize - sizeof(TRACE::Entry);
    char *l_buffer = initializeRsvdBuffer(l_bufferSize,
                                          l_rsvd);

    if (l_rsvd.getBufferSize() != l_bufferSize)
    {
        TS_FAIL("%s:%s: buffer size is not correct", __FILE__, __func__);
    }

    TRACE::Entry* l_entry = l_rsvd.insertEntry(l_entrySize);
    char* l_entryCharPtr = reinterpret_cast<char*>(l_entry);
    uint32_t l_endingPos = ALIGN_8(sizeof(TRACE::Entry) + l_entrySize) - 1;
    char* l_entryEndCharPtr = l_entryCharPtr + l_endingPos;
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
    }

    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (l_entryCharPtr != l_rsvd.iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != l_rsvd.iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != l_rsvd.convertToCharPointer
                                (l_rsvd.
                                      getEndingAddressOfEntry(l_entry)))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (reinterpret_cast<uintptr_t>(l_buffer) !=
        reinterpret_cast<uintptr_t>(l_rsvd.iv_ptrToHead))
    {
        TS_FAIL("%s:%s: Pointer to list is not correct", __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    // Add another item with same size
    l_entry = l_rsvd.insertEntry(l_entrySize);
    l_entryCharPtr = reinterpret_cast<char*>(l_entry);
    l_entryEndCharPtr = l_entryCharPtr + l_endingPos;
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr IS null", __FILE__, __func__);
    }

    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (l_entryCharPtr != l_rsvd.iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != l_rsvd.convertToCharPointer
                                (l_rsvd.
                                      getEndingAddressOfEntry(l_entry)))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != l_rsvd.iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (reinterpret_cast<uintptr_t>(l_buffer) !=
        reinterpret_cast<uintptr_t>(l_rsvd.iv_ptrToHead))
    {
        TS_FAIL("%s:%s: Pointer to list is not correct", __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    // Add another item with size+
    l_entry = l_rsvd.insertEntry(10);
    l_entryCharPtr = reinterpret_cast<char*>(l_entry);
    if (nullptr != l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is not NULL", __FILE__, __func__);
    }

    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (reinterpret_cast<uintptr_t>(l_buffer) !=
        reinterpret_cast<uintptr_t>(l_rsvd.iv_ptrToHead))
    {
        TS_FAIL("%s:%s: Pointer to list is not correct", __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    free(l_buffer);

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
} // end void testRsvdTraceBuffOnlyAccommodateOneItem()

// Test where buffer is just the right size to fit a single Entry plus size
void testRsvdTraceBuffOnlyAccommodateOneItemPlusSize()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    TRACE::RsvdTraceBuffer l_rsvd;
    uint32_t l_bufferSize = ALIGN_8(sizeof(TRACE::Entry) + 20);
    uint32_t l_entrySize = l_bufferSize - sizeof(TRACE::Entry);

    char *l_fullBuffer = initializeRsvdBuffer(l_bufferSize,
                                              l_rsvd);

    // Adjust buffer to the area we are interested in
    char* l_buffer = l_fullBuffer + sizeof(uintptr_t);

    if (l_rsvd.getBufferSize() != l_bufferSize)
    {
        TS_FAIL("%s:%s: buffer size is not correct", __FILE__, __func__);
    }

    // Add first entry - will be at beginning of buffer
    TRACE::Entry* l_entry = l_rsvd.insertEntry(l_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = l_entrySize;
    char* l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    char* l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
        return; // Need to quit or die
    }

    if (reinterpret_cast<TRACE::Entry*>(*l_rsvd.iv_ptrToHead) != l_entry)
    {
        TS_FAIL("%s:%s: head pointer is not pointing first Entry",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_buffer)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_rsvd.iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + l_bufferSize - 1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != l_rsvd.iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }


    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    // Add another entry - will be at beginning of buffer
    l_entry = l_rsvd.insertEntry(l_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = l_entrySize;
    l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
        return; // Need to quit or die
    }

    if (reinterpret_cast<TRACE::Entry*>(*l_rsvd.iv_ptrToHead) != l_entry)
    {
        TS_FAIL("%s:%s: head pointer is not pointing first Entry",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_buffer)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_rsvd.iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + l_bufferSize - 1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != l_rsvd.iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    // Add a third item - with 0 size
    l_entry = l_rsvd.insertEntry(0);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = 0;
    l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
        return; // Need to quit or die
    }

    if (reinterpret_cast<TRACE::Entry*>(*l_rsvd.iv_ptrToHead) != l_entry)
    {
        TS_FAIL("%s:%s: head pointer is not pointing first Entry",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_buffer)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_rsvd.iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + ALIGN_8(sizeof(TRACE::Entry)) - 1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    l_rsvd.clearBuffer();
    if (true != l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is NOT empty", __FILE__, __func__);
    }

    if (l_rsvd.iv_ptrToHead == nullptr)
    {
        TS_FAIL("%s:%s: pointer to head is NULL", __FILE__, __func__);
    }

    if (*l_rsvd.iv_ptrToHead != NULL)
    {
        TS_FAIL("%s:%s: pointer to head is pointing an item",__FILE__,__func__);
    }

    if (false == l_rsvd.isBufferValid())
    {
        TS_FAIL("%s:%s: buffer is not valid", __FILE__, __func__);
    }

    // Add a "first" item - with 0 size
    l_entry = l_rsvd.insertEntry(0);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = 0;
    l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
        return; // Need to quit or die
    }

    if (reinterpret_cast<TRACE::Entry*>(*l_rsvd.iv_ptrToHead) != l_entry)
    {
        TS_FAIL("%s:%s: head pointer is not pointing first Entry",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_buffer)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_rsvd.iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + ALIGN_8(sizeof(TRACE::Entry)) - 1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    l_rsvd.clearBuffer();
    if (true != l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is NOT empty", __FILE__, __func__);
    }

    if (l_rsvd.iv_ptrToHead == nullptr)
    {
        TS_FAIL("%s:%s: pointer to head is NULL", __FILE__, __func__);
    }

    if (*l_rsvd.iv_ptrToHead != NULL)
    {
        TS_FAIL("%s:%s: pointer to head is pointing an item",__FILE__,__func__);
    }

    if (false == l_rsvd.isBufferValid())
    {
        TS_FAIL("%s:%s: buffer is not valid", __FILE__, __func__);
    }

    // Add another entry - will be at beginning of buffer
    l_entry = l_rsvd.insertEntry(l_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = l_entrySize;
    l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
        return; // Need to quit or die
    }

    if (reinterpret_cast<TRACE::Entry*>(*l_rsvd.iv_ptrToHead) != l_entry)
    {
        TS_FAIL("%s:%s: head pointer is not pointing first Entry",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_buffer)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_rsvd.iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + l_bufferSize - 1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != l_rsvd.iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    free(l_fullBuffer);

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
} // end void testRsvdTraceBuffOnlyAccommodateOneItemPlusSize()

// Test where buffer is just the right size to fit two Entries
void testRsvdTraceBuffOnlyAccommodateTwoItems()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    TRACE::RsvdTraceBuffer l_rsvd;
    uint32_t l_bufferSize = 2 * ALIGN_8(sizeof(TRACE::Entry));
    uint32_t l_entrySize = (l_bufferSize/2) - sizeof(TRACE::Entry);

    char *l_fullBuffer = initializeRsvdBuffer(l_bufferSize,
                                              l_rsvd);

    // Adjust buffer to the area we are interested in
    char* l_buffer = l_fullBuffer + sizeof(uintptr_t);

    if (l_rsvd.getBufferSize() != l_bufferSize)
    {
        TS_FAIL("%s:%s: buffer size is not correct",
                __FILE__, __func__);
    }

    // Add first entry - will be at beginning of buffer
    TRACE::Entry* l_entry = l_rsvd.insertEntry(l_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = l_entrySize;
    char* l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    char* l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (reinterpret_cast<TRACE::Entry*>(*l_rsvd.iv_ptrToHead) != l_entry)
    {
        TS_FAIL("%s:%s: head pointer is not pointing first Entry",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_buffer)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + (l_bufferSize/2) - 1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    // Add second item, should take up the rest of the space
    l_entry = l_rsvd.insertEntry(l_entrySize);
    TRACE::Entry *l_soonToBeHead = l_entry;
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = l_entrySize;
    l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (l_entryCharPtr != (l_buffer + (l_bufferSize/2)))
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != (l_rsvd.iv_bufferBeginningBoundary + l_bufferSize/2))
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + l_bufferSize -1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != l_rsvd.iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    // Add third item, should go to the front of the buffer
    l_entry = l_rsvd.insertEntry(l_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = l_entrySize;
    l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (reinterpret_cast<TRACE::Entry*>(*l_rsvd.iv_ptrToHead) != l_soonToBeHead)
    {
        TS_FAIL("%s:%s: head pointer is not pointing first Entry",
                __FILE__, __func__);
    }
    l_soonToBeHead = l_entry;

    if (l_entryCharPtr != l_buffer)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + (l_bufferSize/2) - 1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    // Add fourth item, should take up the rest of the space
    l_entry = l_rsvd.insertEntry(l_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = l_entrySize;
    l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (reinterpret_cast<TRACE::Entry*>(*l_rsvd.iv_ptrToHead) != l_soonToBeHead)
    {
        TS_FAIL("%s:%s: head pointer is not pointing first Entry",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != (l_buffer + (l_bufferSize/2)))
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != (l_rsvd.iv_bufferBeginningBoundary + l_bufferSize/2))
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + l_bufferSize -1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != l_rsvd.iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    free(l_fullBuffer);

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
}  // end void testRsvdTraceBuffOnlyAccommodateTwoItems

// Test when adding items at the ends of the buffer
void testRsvdTraceBuffTestTheEnds()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    TRACE::RsvdTraceBuffer l_rsvd;
    uint32_t l_bufferSize = ALIGN_8(sizeof(TRACE::Entry) + 20);
    uint32_t l_entrySize = l_bufferSize - sizeof(TRACE::Entry);
    l_bufferSize *= 3;

    char *l_fullBuffer = initializeRsvdBuffer(l_bufferSize,
                                              l_rsvd);

    // Adjust buffer to the area we are interested in
    char* l_buffer = l_fullBuffer + sizeof(uintptr_t);

    if (l_rsvd.getBufferSize() != l_bufferSize)
    {
        TS_FAIL("%s:%s: buffer size is not correct",
                __FILE__, __func__);
    }

    // A few needed vars
    TRACE::Entry* l_entry(nullptr);
    char* l_entryCharPtr(nullptr);
    char* l_entryEndCharPtr(nullptr);
    bool l_itemRemoved(false);


    // Add first entry - will be at beginning of buffer
    l_entry = l_rsvd.insertEntry(l_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }
    l_entry->size = l_entrySize;

    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    // Add second entry - will be at beginning of buffer
    l_entry = l_rsvd.insertEntry(l_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }
    l_entry->size = l_entrySize;

    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    l_itemRemoved = l_rsvd.removeOldestEntry();
    if (true != l_itemRemoved)
    {
        TS_FAIL("%s:%s: unable to remove oldest item", __FILE__, __func__);
    }

    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }


    l_entry = l_rsvd.getListHead();
    l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (reinterpret_cast<TRACE::Entry*>(*l_rsvd.iv_ptrToHead) != l_entry)
    {
        TS_FAIL("%s:%s: head pointer is not pointing first Entry",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != (l_buffer + l_entrySize + sizeof(TRACE::Entry)))
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + (2 *
                                     (l_entrySize + sizeof(TRACE::Entry))) - 1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    // Add third item, should go to the end of buffer
    l_entry = l_rsvd.insertEntry(l_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = l_entrySize;
    l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (l_entryCharPtr != (l_buffer + (2 *
                                         (l_entrySize + sizeof(TRACE::Entry)))))
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != l_rsvd.iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    // Add fourth item, should go to the beginning of buffer
    l_entry = l_rsvd.insertEntry(l_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    l_entry->size = l_entrySize;
    l_entryCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
           l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (l_entryCharPtr != l_rsvd.iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + l_entrySize + sizeof(TRACE::Entry) -1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    free(l_fullBuffer);

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
}  // end void testRsvdTraceBuffTestTheEnds

// Test reentrant of buffer
// Create a buffer and an item
void testRsvdTraceBuffTestReentrant ()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    TRACE::RsvdTraceBuffer l_rsvd;
    iv_bufferSize = ALIGN_8(sizeof(TRACE::Entry) + 20);
    iv_entrySize = iv_bufferSize - sizeof(TRACE::Entry);
    iv_bufferSize *= 3;

    iv_buffer = initializeRsvdBuffer(iv_bufferSize,
                                     l_rsvd);

    iv_bufferBeginningBoundary = l_rsvd.iv_bufferBeginningBoundary;
    iv_bufferEndingBoundary = l_rsvd.iv_bufferEndingBoundary;

    // Adjust buffer to the area we are interested in
    char* l_buffer = iv_buffer + sizeof(uintptr_t);

    if (l_rsvd.getBufferSize() != iv_bufferSize)
    {
        TS_FAIL("%s:%s: buffer size is not correct",
                __FILE__, __func__);
    }

    if (true != l_rsvd.isBufferValid())
    {
        TS_FAIL("%s:%s: buffer is not valid", __FILE__, __func__);
    }

    // A few needed vars
    TRACE::Entry* l_entry(nullptr);
    char* l_entryCharPtr(nullptr);
    char* l_entryEndCharPtr(nullptr);

    // Add first entry - will be at beginning of buffer
    l_entry = l_rsvd.insertEntry(iv_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }
    l_entry->size = iv_entrySize;
    l_entryCharPtr =
         l_rsvd.convertToCharPointer(l_rsvd.getAddressOfPtr(l_entry));
    l_entryEndCharPtr =
         l_rsvd.convertToCharPointer(l_rsvd.getEndingAddressOfEntry(l_entry));
    memset(l_entry->data, 'A', l_entry->size);

    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (reinterpret_cast<TRACE::Entry*>(*l_rsvd.iv_ptrToHead) != l_entry)
    {
        TS_FAIL("%s:%s: head pointer is not pointing to first Entry",
                __FILE__, __func__);
    }

    if (l_entryCharPtr != l_buffer)
    {
        TS_FAIL("%s:%s: entry starting position is not correct",
                __FILE__, __func__);
    }

    if (l_entryEndCharPtr != (l_buffer + iv_entrySize +
                                                     sizeof(TRACE::Entry) - 1))
    {
        TS_FAIL("%s:%s: entry ending position is not correct",
                __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
}  // end void testRsvdTraceBuffTestReentrant

// Test reentrant of buffer
// See if we can get a a hold of the buffer and check item previously added
// add another item
void testRsvdTraceBuffTestReentrant2()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    TRACE::RsvdTraceBuffer l_rsvd;
    initializeRsvdBufferForReentrant(l_rsvd);

    if (l_rsvd.getBufferSize() != iv_bufferSize)
    {
        TS_FAIL("%s:%s: buffer size is not correct",
                __FILE__, __func__);
    }

    if (l_rsvd.iv_bufferEndingBoundary != iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: buffer not properly initialized",
                __FILE__, __func__);
    }

    if (l_rsvd.iv_bufferBeginningBoundary != iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: buffer not properly initialized",
                __FILE__, __func__);
    }

    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (true != l_rsvd.isBufferValid())
    {
        TS_FAIL("%s:%s: buffer is not valid", __FILE__, __func__);
    }

    if (true != runSelfDiagnostics(l_rsvd))
    {
        TS_FAIL("%s:%s: self diagnostics discovered an error",
                __FILE__, __func__);
    }

    // A few needed vars
    TRACE::Entry* l_entry(nullptr);

    // Get first entry - will be at beginning of buffer
    l_entry = l_rsvd.getListHead();
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    if ('A' != l_entry->data[0])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    if ('A' != l_entry->data[l_entry->size - 1])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    // Add second entry - will be at beginning of buffer
    l_entry = l_rsvd.insertEntry(iv_entrySize);
    l_entry->size = iv_entrySize;
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }
    memset(l_entry->data, 'B', l_entry->size);
    if ('B' != l_entry->data[0])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    if ('B' != l_entry->data[iv_entrySize - 1])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
}  // end void testRsvdTraceBuffTestReentrant2

// Test reentrant of buffer
// See if we can get a a hold of the buffer and verify items added;
// remove all items
void testRsvdTraceBuffTestReentrant3()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    TRACE::RsvdTraceBuffer l_rsvd;
    initializeRsvdBufferForReentrant(l_rsvd);

    if (l_rsvd.getBufferSize() != iv_bufferSize)
    {
        TS_FAIL("%s:%s: buffer size is not correct",
                __FILE__, __func__);
    }

    if (l_rsvd.iv_bufferEndingBoundary != iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: buffer not properly initialized",
                __FILE__, __func__);
    }

    if (l_rsvd.iv_bufferBeginningBoundary != iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: buffer not properly initialized",
                __FILE__, __func__);
    }

    if (true != l_rsvd.isBufferValid())
    {
        TS_FAIL("%s:%s: buffer is not valid", __FILE__, __func__);
    }

    // A few needed vars
    TRACE::Entry* l_entry(nullptr);

    // Get first entry
    l_entry = l_rsvd.getListHead();
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    if ('A' != l_entry->data[0])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    if ('A' != l_entry->data[l_entry->size - 1])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    // Remove first
    l_rsvd.removeOldestEntry();

    // Get first entry
    l_entry = l_rsvd.getListHead();
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    if ('B' != l_entry->data[0])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    if ('B' != l_entry->data[l_entry->size - 1])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    l_rsvd.clearBuffer();
    l_entry = l_rsvd.getListHead();
    if (nullptr != l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is NOT null", __FILE__, __func__);
        return; // Need to quit or die
    }

    if (true != l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is NOT empty", __FILE__, __func__);
    }

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
}  // end void testRsvdTraceBuffTestReentrant3

// Test reentrant of buffer
// See if we can get a a hold of the buffer and add an item
void testRsvdTraceBuffTestReentrant4()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    TRACE::RsvdTraceBuffer l_rsvd;
    initializeRsvdBufferForReentrant(l_rsvd);

    if (l_rsvd.getBufferSize() != iv_bufferSize)
    {
        TS_FAIL("%s:%s: buffer size is not correct",
                __FILE__, __func__);
    }

    if (l_rsvd.iv_bufferEndingBoundary != iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: buffer not properly initialized",
                __FILE__, __func__);
    }

    if (l_rsvd.iv_bufferBeginningBoundary != iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: buffer not properly initialized",
                __FILE__, __func__);
    }

    if (true != l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is NOT empty", __FILE__, __func__);
    }

    if (true != l_rsvd.isBufferValid())
    {
        TS_FAIL("%s:%s: buffer is not valid", __FILE__, __func__);
    }

    TRACE::Entry* l_entry(nullptr);
    l_entry = l_rsvd.getListHead();
    if (nullptr != l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is NOT null", __FILE__, __func__);
        return; // Need to quit or die
    }

    // Add an entry
    l_entry = l_rsvd.insertEntry(iv_entrySize);
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }
    l_entry->size = iv_entrySize;
    memset(l_entry->data, 'C', l_entry->size);
    if ('C' != l_entry->data[0])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    if ('C' != l_entry->data[l_entry->size - 1])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
}  // end void testRsvdTraceBuffTestReentrant4


// Test reentrant of buffer
// Finally see if we can get item
void testRsvdTraceBuffTestReentrant5()
{
    TRACFCOMP(g_trac_test, ENTER_MRK"RsvdTraceBuffTestSuite:%s", __func__);

    TRACE::RsvdTraceBuffer l_rsvd;
    initializeRsvdBufferForReentrant(l_rsvd);

    if (l_rsvd.getBufferSize() != iv_bufferSize)
    {
        TS_FAIL("%s:%s: buffer size is not correct",
                __FILE__, __func__);
    }

    if (l_rsvd.iv_bufferEndingBoundary != iv_bufferEndingBoundary)
    {
        TS_FAIL("%s:%s: buffer not properly initialized",
                __FILE__, __func__);
    }

    if (l_rsvd.iv_bufferBeginningBoundary != iv_bufferBeginningBoundary)
    {
        TS_FAIL("%s:%s: buffer not properly initialized",
                __FILE__, __func__);
    }

    if (true == l_rsvd.isListEmpty())
    {
        TS_FAIL("%s:%s: list is empty", __FILE__, __func__);
    }

    if (true != l_rsvd.isBufferValid())
    {
        TS_FAIL("%s:%s: buffer is not valid", __FILE__, __func__);
    }

    TRACE::Entry* l_entry(nullptr);
    l_entry = l_rsvd.getListHead();
    if (nullptr == l_entry)
    {
        TS_FAIL("%s:%s: Entry ptr is null", __FILE__, __func__);
        return; // Need to quit or die
    }

    if ('C' != l_entry->data[0])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    if ('C' != l_entry->data[l_entry->size - 1])
    {
        TS_FAIL("%s:%s: Entry data is corrupt",
                __FILE__, __func__);
    }

    TRACFCOMP(g_trac_test, EXIT_MRK"RsvdTraceBuffTestSuite:%s", __func__);
}  // end void testRsvdTraceBuffTestReentrant5

private:
// Helpful methods to help in testing
char* initializeRsvdBuffer(uint32_t i_bufferSize,
                           TRACE::RsvdTraceBuffer& i_rsvd)
{
    // Create a buffer
    uint32_t l_realBufferSize = i_bufferSize + sizeof(uintptr_t);
    char *l_buffer = reinterpret_cast<char*>(malloc(l_realBufferSize));
    memset(l_buffer, 0, l_realBufferSize);

    // Get the address of buffer; just like we would get in "real life"
    uintptr_t l_bufferAddr = reinterpret_cast<uintptr_t>(l_buffer);

    // Get a pointer to where the HEAD needs to reside in the buffer
    uintptr_t *l_addressToHead = reinterpret_cast<uintptr_t *>(l_bufferAddr);

    // Initialize the buffer
    i_rsvd.init(i_bufferSize,
                l_bufferAddr + sizeof(uintptr_t),
                l_addressToHead);

    return l_buffer;
}

void initializeRsvdBufferForReentrant(TRACE::RsvdTraceBuffer& i_rsvd)
{
    // Get the address of buffer; just like we would get in "real life"
    uintptr_t l_bufferAddr = reinterpret_cast<uintptr_t>(iv_buffer);

    // Get a pointer to where the HEAD is
    uintptr_t *l_addressToHead = reinterpret_cast<uintptr_t *>(iv_buffer);

    // Initialize the buffer
    i_rsvd.init(iv_bufferSize,
                l_bufferAddr + sizeof(uintptr_t),
                l_addressToHead);
}


bool runSelfDiagnostics(TRACE::RsvdTraceBuffer& l_rsvd)
{
    bool l_everythingChecksOut = true;
    uintptr_t l_bufferBeginningBoundary = l_rsvd.getAddressOfPtr
                         (l_rsvd.iv_bufferBeginningBoundary);
    uintptr_t l_bufferEndingBoundary = l_rsvd.getAddressOfPtr
                         (l_rsvd.iv_bufferEndingBoundary);

    if (!l_rsvd.isListEmpty())
    {
        uint32_t l_itemCount(0);

        TRACE::Entry* l_entry  = l_rsvd.getListHead();
        TRACE::Entry* l_head = l_entry;
        do
        {
            ++l_itemCount;
            uintptr_t l_entryAddr = l_rsvd.getAddressOfPtr(l_entry);
            uintptr_t l_entryAddrEnd =
                            l_rsvd.getEndingAddressOfEntry(l_entry);

            if (l_entryAddr < l_bufferBeginningBoundary)
            {
                TS_FAIL("Item [%d] at address (0x%X) precedes the "
                        "allocated memory location at address "
                        "(0x%X) by %d byte(s)",
                        l_itemCount, l_entryAddr, l_bufferBeginningBoundary,
                        (l_bufferBeginningBoundary - l_entryAddr));
                l_everythingChecksOut = false;
            }
            else if (l_entryAddr > l_bufferEndingBoundary)
            {
                TS_FAIL("Item [%d] at address (0x%X) is beyond the "
                        "ending allocated memory location at address "
                        "(0x%X) by %d byte(s)",
                        l_itemCount, l_entryAddr, l_bufferEndingBoundary,
                        (l_entryAddr - l_bufferEndingBoundary));
                l_everythingChecksOut = false;
            }
            else if (l_entryAddrEnd > l_bufferEndingBoundary)
            {
                TS_FAIL("Item [%d] at address (0x%X) overruns the "
                        "ending allocated memory location at address "
                        "(0x%X) by %d byte(s)",
                        l_itemCount, l_entryAddr, l_bufferEndingBoundary,
                        (l_entryAddrEnd - l_bufferEndingBoundary));
                l_everythingChecksOut = false;
            }
            else
            {
                uintptr_t l_entryNextAddr = l_rsvd.
                                         getAddressOfPtr(l_entry->next);
                if ((l_entryNextAddr > l_entryAddr) &&
                    (l_entryAddrEnd >= l_entryNextAddr) )
                {
                    TS_FAIL("Item [%d] at address (0x%X) overruns the "
                            "next item at address (0x%X) by %d byte(s)",
                            l_itemCount, l_entryAddr, l_entryNextAddr,
                            (l_entryAddrEnd - l_entryNextAddr + 1));
                    l_everythingChecksOut = false;
                }
            } // end if ... else

            l_entry = l_entry->next;
        }
        while(l_entry != l_head);
    } // end if (!l_rsvd.isListEmpty())

    return l_everythingChecksOut;
}

    char* iv_buffer;
    uint32_t iv_bufferSize;
    uint32_t iv_entrySize;
    char *iv_bufferBeginningBoundary; //< Pointer to beginning of buffer
    char *iv_bufferEndingBoundary;    //< Pointer to end of buffer
    TRACE::ComponentDesc *iv_compDesc;
};
