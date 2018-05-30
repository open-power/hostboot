/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/runtime/rt_rsvdtracebuffer.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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
#ifndef __RSVD_TRACE_BUFFER_H
#define __RSVD_TRACE_BUFFER_H

/** @file rt_rsvdtracebuffer.H
 *  Declarations for the RsvdTraceBuffer (Reserved Trace Buffer) class.
 */

#include <stdint.h>        // uint32_t
#include <trace/entry.H>   // Entry
#include <util/align.H>    // ALIGN_8

// Forward declaration of the test suite
class RsvdTraceBuffTestSuite;

namespace TRACE
{

    /** @class RsvdTraceBuffer
     *
     *  @brief Class to manage the Reserved Trace Buffer
     *
     *  This is a utility class to manage the buffer - looking for space
     *  for an entry, adding entries and removing entries.
     *
     */
    class RsvdTraceBuffer
    {
        public:

            /** Constructor.
             */
            RsvdTraceBuffer();

            /** Initializes the buffer, if previously not done.
             *
             *  @param[in] i_bufferSize - Size of the buffer.
             *
             *  @param[in] i_addressToBuffer - Where the buffer begins
             *
             *  @param[in] i_addressToHead - A pointer to a ponter to the first
             *                               Entry, cannot be a nullptr
             */
            void init(uint32_t   i_bufferSize,
                      uintptr_t  i_addressToBuffer,
                      uintptr_t* i_addressToHead);

            /** @brief This function will insert an Entry to the buffer
             *
             *  @param[in]  i_dataSize - The size of the contiguous piece
             *                           of memory caller desires
             *
             *  @return A valid Entry pointer if space found for an Entry;
             *          nullptr otherwise
             */
            Entry* insertEntry(uint32_t i_dataSize);

            /** @brief Extract the trace info or return aggregated size of the
             *         traces
             *
             *  @algorithm If o_data is null or i_dataSize is 0, then this
             *             method will return all the trace sizes, this class
             *             contains, aggregated together.
             *             If o_data is valid and the i_size is less than
             *             the size of trace_buf_head_t, then 0 is returned.
             *             If o_data is valid and the i_size is greater than
             *             the size of trace_buf_head_t, then as many trace
             *             entries will be returned in the o_data buffer that
             *             i_size will allow.
             *
             *  @param[in]  o_data - if not null, the buffer area to copy
             *                       trace data into
             *
             *  @param[out] i_dataSize - if not 0, the size of the buffer area,
             *                           which dictates how many trace entries'
             *                           payload (or data the entry contains)
             *                           that can be copied
             *
             *  @return the size of the trace data being returned, or the
             *          aggregated size of the traces, or 0
             */
            uint32_t getTrace(void* o_data, uint32_t i_dataSize) const;


            /** @brief Return the state of buffer
             *
             *  @return true if buffer has been initialized properly,
             *          false otherwise
             *
             */
            bool isBufferValid() const
                {   return iv_isBufferValid; }

            /** @brief Clears the buffer of all entries
             */
            void clearBuffer()
                {   setListHead(reinterpret_cast<TRACE::Entry*>(NULL)); }

            /** @brief Retrieve the number of entries in buffer
             */
            uint32_t getNumberOfEntries() const;

        private:
            /** @brief This function will find a contiguous piece of memory that
             *         is large enough in size to accommodate the space needed.
             *         If not enough free contiguous memory exists to accommodate
             *         the space needed, then space will be created that will be
             *         large enough for the space needed with one caveat - if
             *         the space requested is greater than the size of the
             *         buffer, then no attempt will be made to accommodate the
             *         space needed but instead 0 will be returned and
             *         o_availableAddress will be set to nullptr.
             *
             *  @algorithm Call the method getAvailableSpace (below) to get
             *             the largest contiguous piece of memory, whether it
             *             satisfies our needs or not.  If it does satisfy our
             *             needs, then return the size of the space found and a
             *             pointer to the beginning of that space.  If it does
             *             not satisfy our spatial needs, then remove the head
             *             entry from the list and check again.  We remove the
             *             head because the head entry will be the oldest entry
             *             (time wise). Repeat until we get the space needed
             *             or until all entries are removed.  Unless the space
             *             requested is not larger in size to the buffer size,
             *             then an available space will eventually be returned.
             *
             *  @param[in]  i_spaceNeeded - @see insertEntry::i_dataSize above
             *
             *  @param[out] o_availableAddress - A pointer to the contiguous
             *                 piece of memory found that satisfies the caller's
             *                 request.  If not found, then nullptr
             *
             *  @return the size of the space found/created; 0 if none
             *          found/created
             */
            uint32_t makeSpaceForEntry(uint32_t i_spaceNeeded,
                                       char* &o_availableAddress);

            /** @brief Returns a contiguous piece of memory that will satisfy
             *         the space that is needed if large enough space can be
             *         had, else returns the size of the largest contiguous
             *         piece of memory.
             *
             *  @algorithm There are three cases to consider:
             *         1) Tail is in front of the head (address wise, not
             *            logical wise) and the space between tail and end
             *            of buffer satisfies our spatial needs then return the
             *            space between tail and buffer end.
             *         Example 1:
             *         --- Beginning of Buffer                 End of Buffer ---
             *         |                                                       |
             *         V                                                       V
             *         ---------------------------------------------------------
             *         | < - 10 bytes -> | Head | .....| Tail | <- 20 bytes -> |
             *         ---------------------------------------------------------
             *            scenario 1: Contigous space desired: 15 bytes
             *                        Return the 20 bytes after the Tail
             *            scenario 2: Contiguous space desired: 10 bytes
             *                        Return the 20 bytes after the Tail
             *                            Here we can return the 10 bytes or
             *                            20 bytes - both satisfy the condition.
             *                            In this case, return the 20 bytes to
             *                            take full advantage of the buffer.
             *
             *         2) Tail is in front of the head and case 1 above cannot
             *            be satisfied then return the space between the
             *            beginning of buffer and head.
             *         Example 2.1:
             *         --- Beginning of Buffer                 End of Buffer ---
             *         |                                                       |
             *         V                                                       V
             *         ---------------------------------------------------------
             *         | < - 30 bytes -> | Head | .....| Tail | <- 15 bytes -> |
             *         ---------------------------------------------------------
             *            scenario 1: Contiguous space desired: 25 bytes
             *                        Return the 30 bytes before the Head
             *            scenario 2: Contiguous space desired: 40 bytes
             *                        Return the 30 bytes before the Head
             *
             *         Example 2.2:
             *         --- Beginning of Buffer                 End of Buffer ---
             *         |                                                       |
             *         V                                                       V
             *         ---------------------------------------------------------
             *         | < - 5 bytes -> | Head | .....| Tail | <- 15 bytes -> |
             *         ---------------------------------------------------------
             *            scenario 1: Contiguous space desired: 20 bytes
             *                        Return the 5 bytes before the Head
             *                            The reason for returning 5 bytes, even
             *                            though 15 bytes is greater is because,
             *                            ultimately space will be created at
             *                            the beginning of the buffer.
             *
             *         3) Tail is behind head, then simply return the
             *            available space between the two.
             *         Example 3:
             *         --- Beginning of Buffer                 End of Buffer ---
             *         |                                                       |
             *         V                                                       V
             *         ---------------------------------------------------------
             *         |  .... | Tail | < - 30 bytes -> | Head |  ....
             *         ---------------------------------------------------------
             *            Case 1: Contigous space desired: 25 bytes
             *                    Return the 30 bytes between Tail and Head.
             *            Case 2: Contigous space desired: 40 bytes
             *                    Return the 30 bytes between Tail and Head.
             *
             *  @param[in]  i_spaceNeeded - @see insertEntry::i_dataSize above
             *
             *  @param[out] o_availableAddress - @see makeSpaceForEntry above
             *
             *  @return The minimum size of the space found that meets the
             *          requested space needed; or the largest size that comes
             *          close to meeting the space needed
             *
             */
            uint32_t getAvailableSpace(uint32_t  i_spaceNeeded,
                                       char*    &o_availableAddress);

            /** @brief Remove the head of the list, because the head is the
             *         oldest entry
             *
             *  @return Returns true if oldest entry is removed; false otherwise
             */
            bool removeOldestEntry();

            /** @brief This will aggregate all the entries' data size and
             *         return it
             *
             *  @return Returns all the entries' data size plus the size of
             *          an uint32_t for each one.
             */
            uint32_t getAggregateSizeOfEntries() const;

            /** @brief This will return as many data entries that can be
             *         accommodated by size
             *
             *  @param[out] o_data - the buffer area to copy trace data into
             *
             *  @param[in]  i_dataSize - the size of the buffer area, which
             *                           dictates how many trace data can be
             *                           copied
             *
             *  @return Returns all the entries' data size plus the size of
             *          an uint32_t for each one, that can be accommodated
             */
            uint32_t getTraceEntries(void* o_data, uint32_t i_dataSize) const;


            /** @brief Return true if list empty
             *
             *  @return true if list empty; false otherwise
             */
            bool isListEmpty() const
                {   return (nullptr == getListHead()); }

            /** @brief Return the address of a pointer
             *
             *  @param[in] i_entry - a pointer to data type;
             *                      void pointer for our purposes
             *
             *  @return The address of the supplied pointer
             *
             *  @pre i_entry is NOT a nullptr
             */
            uintptr_t getAddressOfPtr(const void *i_entry) const
                {   return reinterpret_cast<uintptr_t>(i_entry); };

            /** @brief Get the address at the end of an Entry, which is the
             *         size of the Entry plus any padding for memory alignment
             *
             *  @param[in] i_entry - a pointer to an Entry data type
             *
             *  @return The address at the end of an Entry
             *
             *  @pre i_entry is NOT a nullptr
             */
            uintptr_t getEndingAddressOfEntry(const Entry *i_entry) const
                {   return (getAddressOfPtr(i_entry) +
                            getAlignedSizeOfEntry(i_entry->size) -1); };

            /** @brief Converts an address to a character pointer
             *
             *  @param[in] i_addressOfPtr - a legitimate address
             *
             *  @return A character pointer to the address supplied
             *
             *  @pre i_addressOfPtr is a a legitimate address of a memory
             *                      location
             */
            char* convertToCharPointer(uintptr_t i_addressOfPtr) const
                {   return reinterpret_cast<char*>(i_addressOfPtr); };

            /** @brief Save away the beginning boundary of the buffer
             *
             *  @param[in] i_bufferBeginningBoundary - a pointer to the
             *                                   beginning of the buffer
             *
             */
            void setBeginningBoundary(char* i_bufferBeginningBoundary)
                {   iv_bufferBeginningBoundary = i_bufferBeginningBoundary; };

            /** @brief Save away the ending boundary of the buffer
             *
             *  @param[in] i_bufferEndingBoundary - a pointer to the
             *                                      end of the buffer
             *
             */
            void setEndingBoundary(char * i_bufferEndingBoundary)
                {   iv_bufferEndingBoundary = i_bufferEndingBoundary; }

            /** @brief Set the head of the list
             *
             *  @param[in] i_addressToHead - pointer to an area outside
             *                the controlled buffer that stays updated with
             *                the head of the list; OK to be a nullptr
             *
             */
            void setListHeadPtr(uintptr_t* i_addressToHead)
                {   iv_ptrToHead = i_addressToHead; };

            /** @brief Set the head of the list
             *
             *  @param[in] i_head - a pointer to an Entry data type;
             *                      OK to be a nullptr
             *
             */
            void setListHead(Entry* i_entry)
                {
                    if (nullptr != i_entry)
                    {
                        i_entry->next = i_entry->prev = i_entry;
                    }
                    // Sanity check, make sure the pointer to head is valid
                    if (nullptr != iv_ptrToHead)
                    {
                        *iv_ptrToHead = getAddressOfPtr(i_entry);
                    }
                };

            /** @brief Get the head of the list
             *
             *  @return return the head of the list as an Entry pointer
             */
            Entry* getListHead() const
                {
                    Entry* l_entry = nullptr;
                    // Make sure the pointer is valid before de-referencing it
                    if (nullptr != iv_ptrToHead)
                    {
                        l_entry = reinterpret_cast<Entry*>(*iv_ptrToHead);
                    };
                    return l_entry;
                }

            /** @brief Append an entry to the end of the list
             *
             *  @param[in] i_tail - a pointer to an Entry data type;
             *                      OK to be a nullptr
             *
             */
            void setListTail(Entry* i_newEntry)
                {
                    Entry* l_head = getListHead();

                    // If there is a head and user passed in a legitimate tail
                    // then add the tail at the end of the list
                    if (l_head && i_newEntry)
                    {
                        // Get a handle to old tail
                        Entry* l_tail = l_head->prev;
                        // Point new entry's (new tail) next entry to head
                        i_newEntry->next = l_head;
                        // Point new entry's (new tail) previous entry to tail (old tail)
                        i_newEntry->prev = l_tail;
                        // Point head's previous to the new entry (new tail)
                        l_head->prev = i_newEntry;
                        // Point tail (old tail) to the new entry (new tail)
                        l_tail->next = i_newEntry;
                    }
                    // Else, head is a nullptr and user passed in a
                    // legitimate new Entry, then set head to new Entry
                    else if (i_newEntry)
                    {
                        setListHead(i_newEntry);
                    }
                    // else tail is not legit, so let's get out of here,
                    // nothing to do
                }


            /** @brief Get the size of the buffer; the buffer that is available
             *        for Entries.
             *
             *  @return Size of buffer
             */
            uint32_t getBufferSize() const
                {   return (iv_bufferEndingBoundary -
                                             iv_bufferBeginningBoundary + 1); };

            /** @brief Get the size of an Entry plus the bytes needed to memory
             *         align the Entry.
             *
             *  @param[in] i_dataSize - the size of the data that extends beyond
             *                          the Entry data type
             *
             *  @return The total size of Entry; includes size of the Entry
             *          itself, size of the data that is associated with Entry
             *          and extras size so as to be properly aligned
             *
             */
            uint32_t getAlignedSizeOfEntry(uint32_t i_dataSize) const
                {   return ALIGN_8(sizeof(Entry) + i_dataSize); }

            /** @brief Set the buffer state
             *
             *  @param[in] i_state - the new state of the buffer; false or true
             *
             */
            void setBufferValidity(bool i_state)
                {   iv_isBufferValid = i_state; }

            /** @brief Clears the the pointer that points to the head
             */
            void clearPtrToHead()
                {   iv_ptrToHead = nullptr; }

            char *iv_bufferBeginningBoundary; //< Pointer to beginning of buffer
            char *iv_bufferEndingBoundary;    //< Pointer to end of buffer
            uintptr_t* iv_ptrToHead; //< Pointer to oldest Entry (time wise)
            bool iv_isBufferValid; //< Indicates an initialized buffer

            // For testing purposes only
            friend class ::RsvdTraceBuffTestSuite;
};
}

#endif
