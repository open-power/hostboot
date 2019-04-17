/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/runtime/rt_rsvdtracebuffer.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2019                        */
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

#include "rt_rsvdtracebuffer.H"
#include <string.h>               // memset

namespace TRACE
{
/**
 *  ctor
 */
RsvdTraceBuffer::RsvdTraceBuffer()
{
    // The buffer is not valid - there is no actual/real buffer to point to.
    // With no actual/real buffer to point to, all internal data is NULL/0.
    setBufferValidity(false);
    clearPtrToHead();
    setBeginningBoundary(nullptr);
    setEndingBoundary(nullptr);
}

/**
 *  init
 */
void RsvdTraceBuffer::init(uint32_t   i_bufferSize,
                           uintptr_t  i_addressToBuffer,
                           uintptr_t* i_addressToHead)
{
    // If buffer is not already initialized and incoming data is legit
    if ( (false == isBufferValid())   &&
         (i_bufferSize > 0 )          &&
         (i_addressToBuffer > 0)      &&
         (nullptr != i_addressToHead) )
    {
        setBeginningBoundary(convertToCharPointer(i_addressToBuffer));
        setEndingBoundary(convertToCharPointer(i_addressToBuffer +
                                                             i_bufferSize - 1));
        setListHeadPtr(i_addressToHead);

        // Now that there is an actual/real buffer to point to, the buffer is
        // valid, although it may/may not have any entries associated with it.
        setBufferValidity(true);
    }
}

/**
 *  insertEntry
 */
Entry* RsvdTraceBuffer::insertEntry(uint32_t i_dataSize)
{
    // Create a handle to an Entry
    Entry* l_entry(nullptr);

    // Before continuing, make sure the buffer is valid
    if (isBufferValid())
    {
        char* l_availableAddress(nullptr);

        // Bump up the needed size to include the entry itself and
        // necessary alignment.
        // (Alignment is needed so that Entry's members can be atomically
        //  updated).
        uint32_t l_entrySize = getAlignedSizeOfEntry(i_dataSize);
        if (makeSpaceForEntry(l_entrySize, l_availableAddress) &&
            l_availableAddress)
        {
            // Set entry if space was created and an available address
            // is returned
            l_entry = reinterpret_cast<Entry*>(l_availableAddress);

            setListTail(l_entry);
        }
    }

    return l_entry;
}

/**
 *  makeSpaceForEntry
 */
uint32_t RsvdTraceBuffer::makeSpaceForEntry(uint32_t i_spaceNeeded,
                                            char* &o_availableAddress)
{
    o_availableAddress = nullptr;
    uint32_t l_spaceAvailable = 0;

    // Only look for space if requested space is less than
    // or equal to buffer size
    if (i_spaceNeeded <= getBufferSize())
    {
        l_spaceAvailable = getAvailableSpace(i_spaceNeeded, o_availableAddress);

        // Keep requesting for space until we get the space that is asked for
        while (l_spaceAvailable < i_spaceNeeded)
        {
            // If we can't remove any entries, then we exhausted all efforts.
            // Should not happen, because the space requested should be less
            // than or equal to buffer size
            if (!removeOldestEntry())
            {
                l_spaceAvailable = 0;
                break;
            }

            l_spaceAvailable = getAvailableSpace(i_spaceNeeded,
                                                 o_availableAddress);
        }
    }

    return l_spaceAvailable;
}

/**
 *  getAvailableSpace
 */
uint32_t RsvdTraceBuffer::getAvailableSpace(uint32_t i_spaceNeeded,
                                            char* &o_availableAddress)
{
    o_availableAddress = nullptr;
    uint32_t l_availableSpace(0);

    // If the list is empty, then the full buffer is available
    if (isListEmpty())
    {
        l_availableSpace = getBufferSize();
        o_availableAddress = iv_bufferBeginningBoundary;
    }
    // The list is not empty; must find available space
    else
    {
        // Cache some useful data for easy calculations later on
        uintptr_t l_bufferBeginningBoundary = getAddressOfPtr(iv_bufferBeginningBoundary);
        uintptr_t l_bufferEndingBoundary = getAddressOfPtr(iv_bufferEndingBoundary);
        Entry* l_head = getListHead();
        uintptr_t l_headAddr = getAddressOfPtr(l_head);
        uintptr_t l_tailAddrEnd = getEndingAddressOfEntry(l_head->prev);

        // If address of the tail is greater or equal to the head then the tail
        // will be at the end of the buffer or, in other words, ahead of the head.
        if (l_tailAddrEnd >= l_headAddr)
        {
            // Get available space between the tail and buffer ending boundary
            size_t l_spaceAtEnd = l_bufferEndingBoundary - l_tailAddrEnd;
            // Get available space between the buffer beginning boundary and head
            size_t l_spaceAtBeginning = l_headAddr - l_bufferBeginningBoundary;

            // If the space available at end of buffer is enough to satisfy the
            // space needed, then return that value else return the space
            // available at the beginning of the buffer.  If the space at the
            // end does not have enough of the needed space, then space will
            // ultimately be made at the beginning of the
            //
            // Right now, you are probably thinking, what if I only need 5 free
            // spaces and if the end has 10 available and the beginning has 7
            // available, why not return the space at the beginning, the
            // minimum needed to satisfy our needs.  I believe we still would
            // want to "fill out" the end, before starting with beginning.
            //
            // Side note:  We want to return contiguous memory only.  Although
            // l_spaceAtEnd + l_spaceAtBeginning may satisfy the space needed,
            // it is not contiguous.
            if (l_spaceAtEnd >= i_spaceNeeded)
            {
                // There is more available space at the end of the buffer
                l_availableSpace = l_spaceAtEnd;
                o_availableAddress = convertToCharPointer(l_tailAddrEnd + 1);
            }
            // Just return the space available at beginning and hopefully
            // that will satisfy our needs
            else
            {
                // There is more available space at the beginning of the buffer
                l_availableSpace = l_spaceAtBeginning;
                o_availableAddress = iv_bufferBeginningBoundary;
            }
        }
        // The tail is behind the head in the buffer
        else
        {
            // Get available space between the head and tail
            l_availableSpace = l_headAddr - l_tailAddrEnd + 1;
            o_availableAddress = convertToCharPointer(l_tailAddrEnd  + 1);
        }
   }
   return l_availableSpace;
}

/**
 *  removeOldestEntry
 */
bool RsvdTraceBuffer::removeOldestEntry()
{
    bool l_oldestEntryRemoved(false);

    // If the list is not empty, then remove oldest entry - the head
    if (!isListEmpty())
    {
        // Get a handle to the head
        Entry* l_head(getListHead());

        // Is there only one entry?
        if (l_head->next == l_head)
        {
            // Yes, just set the head to nullptr and we are done
            l_head = nullptr;
        }
        // There is more than one entry, so remove head (the oldest entry)
        else
        {
            // Point head's next entry to head's previous entry
            l_head->next->prev = l_head->prev;
            // Point head's previous entry to head's next entry
            l_head->prev->next = l_head->next;
            // Now set head to the next entry
            l_head = l_head->next;
        }

        // Update the head of the list
        setListHead(l_head);
        l_oldestEntryRemoved = true;
    }

    return l_oldestEntryRemoved;
}

/**
 *  getTrace
 */
uint32_t RsvdTraceBuffer::getTrace(void* o_data, uint32_t i_dataSize) const
{
    uint32_t l_sizeOfBufferExtracted(0);

    // Before continuing, make sure the buffer is valid
    if (isBufferValid())
    {
        // If caller passed in a nullptr for the data or zero for the data size,
        // then that signals the user only wants to ascertain the size
        // requirement to hold all the data associated with the entries.
        if ((nullptr == o_data) || (0 == i_dataSize))
        {
            // Caller wants to ascertain size requirements for data
            l_sizeOfBufferExtracted = getAggregateSizeOfEntries();
        }
        else
        {
            // Caller wants to collect data - enough data to fill data size
            l_sizeOfBufferExtracted = getTraceEntries(o_data, i_dataSize);
        }
    }

    return l_sizeOfBufferExtracted;
}

/**
 *  aggregateSizeOfEntries
 */
uint32_t RsvdTraceBuffer::getAggregateSizeOfEntries() const
{
    uint32_t l_aggregatedSize(0);

    // Get a handle to the head
    Entry* l_head(getListHead());

    // Make sure the list is not null
    if (l_head)
    {
        Entry* l_entry = l_head;
        do
        {
            // Need to add to the size, the size of an uint32_t.  The uint32_t
            // will hold the size of the data that is to be returned along
            // with the returned data.
            l_aggregatedSize += ALIGN_8(l_entry->size) + sizeof(uint32_t);
            l_entry = l_entry->next;
        } while (l_entry != l_head);
    }

    // Add size of trace_buf_head_t to get the true size requirements
    return (l_aggregatedSize + sizeof(trace_buf_head_t));
}

/**
 *  getTraceEntries
 */
uint32_t RsvdTraceBuffer::getTraceEntries(void* o_data, uint32_t i_dataSize) const
{
    uint32_t l_sizeOfEntries(0);

    // Before proceeding, make sure the incoming data is valid
    if ((nullptr != o_data) &&
        (i_dataSize >= sizeof(trace_buf_head_t)) )
    {
        // Clear the outgoing data before populating it
        memset(o_data, 0, i_dataSize);

        // Get a useful "trace buffer head" handle to the data buffer passed in
        trace_buf_head_t* l_header =reinterpret_cast<trace_buf_head_t*>(o_data);

        // Now populate the trace buffer header with some useful info
        l_header->ver = TRACE_BUF_VERSION;
        l_header->hdr_len = l_header->size = sizeof(trace_buf_head_t);
        l_header->time_flg = TRACE_TIME_REAL;
        strncpy(l_header->comp, "RSVD_MEM_TRACE", TRAC_COMP_SIZE);
        l_header->endian_flg = 'B'; // Big Endian.

        // Get a handle to the head
        Entry* l_head(getListHead());

        // Extract the trace info from this class' internal buffer
        // If the list is not empty and have data then extract the trace info
        if (l_head)
        {
            // Keep a tally of the size of the data that can be copied over.
            // Also account for the trace_buf_head_t that is at the beginning
            // of buffer o_data.
            uint32_t l_totalSize(sizeof(trace_buf_head_t));
            // Keep a tally of the number of entries that can be extracted
            uint32_t l_entriesToExtract(0);
            // The entry size as data type uint32_t; for code up keep
            uint32_t l_entrySize(0);
            // Get a handle on the last entry on the list
            Entry* l_entry(l_head->prev);

            // Calculate the number of entries that can be stuffed into the data
            // buffer - starting with newest entry (tail) to oldest entry (head)
            do
            {
                // Calculate the size: add the size of the data (that will be
                // copied over) plus the size of the type of the entry size
                // (that will hold the size of the data being copied over).
                if ((l_totalSize + ALIGN_8(l_entry->size) + sizeof(l_entrySize))
                                                                  <= i_dataSize)
                {
                    l_totalSize += ALIGN_8(l_entry->size) + sizeof(l_entrySize);
                    ++l_entriesToExtract;
                }
                else // Can't retrieve this entry; it breaks the size limitation
                {
                    // Although we are done here, we still need to point to
                    // the previous item.  The continuation of this algorithm
                    // depends on it (expects to be one behind the needed data)
                    l_entry = l_entry->prev;
                    break;
                }

                l_entry = l_entry->prev;
            } while (l_entry != l_head->prev);

            // Get a useful "char *" handle to the data buffer passed in,
            // for easy data injection
            char* l_data = reinterpret_cast<char*>(o_data);

            // Retrieve the data, going forwards in the list: Want to retrieve
            // the entries in chronological order
            // Currently pointing one entry behind the starting entry (starting
            // entry, meaning the first entry to start gathering data from)
            while (l_entriesToExtract)
            {
                // Get next entry
                l_entry = l_entry->next;

                // Copy entry data.
                memcpy(&l_data[l_header->size], l_entry->data, l_entry->size);
                l_header->size += ALIGN_8(l_entry->size);

                // Copy entry size.
                l_entrySize = l_entry->size + sizeof(l_entrySize);
                memcpy(&l_data[l_header->size], &l_entrySize, sizeof(l_entrySize));
                l_header->size += sizeof(l_entrySize);

                // increment/decrements our counters
                ++l_header->te_count;
                --l_entriesToExtract;
            }  // end while (l_entriesToExtract)
        }  // end if (l_head)

        // Update the size of the entries retrieved and the
        // next free memory location in header trace buffer
        l_sizeOfEntries = l_header->next_free = l_header->size;
    }

    return l_sizeOfEntries;
}

/**
 *  getNumberOfEntries
 */
uint32_t RsvdTraceBuffer::RsvdTraceBuffer::getNumberOfEntries() const
{
    uint32_t l_numberOfEntries(0);

    // If the list is not empty, count the entries
    if (!isListEmpty())
    {
        // Get a handle to the head
        Entry* l_head = getListHead();
        do
        {
            ++l_numberOfEntries;
            l_head = l_head->next;
        } while (l_head != getListHead());
    }

    return l_numberOfEntries;
}

}  // end namespace TRACE
