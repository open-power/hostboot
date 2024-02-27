/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_fifo_buffer.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2024                        */
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
#ifndef __SBEIO_SBE_FIFO_BUFFER_H
#define __SBEIO_SBE_FIFO_BUFFER_H

#include <stdint.h>

#include "sbe_fifodd.H"
#include <memory>

#ifndef __HOSTBOOT_RUNTIME
#include <kernel/pagemgr.H>
#endif

namespace SBEIO
{

/*
 * @brief A buffer backed by discontiguous physical pages.
 */
class discontiguous_buffer
{
public:
    /** @brief Append a byte to the buffer. */
    void append(const uint8_t i_byte)
    {
        *get_ptr(iv_bytes_contained++) = i_byte;
    }

    /** @brief Append data to this buffer. */
    void append(const void* i_data, size_t i_amt)
    {
        const uint8_t* data_bytes = static_cast<const uint8_t*>(i_data);

        while (i_amt > 0)
        {
            append(*data_bytes);
            --i_amt;
            ++data_bytes;
        }
    }

    /** @brief Retrieve the 32-bit value at a given offset in the
     *  buffer.
     *
     *  Asserts on out-of-bounds accesses.
     */
    uint32_t word_at(const size_t i_word_offset) const
    {
        uint32_t word = 0;
        const size_t begin_copy = i_word_offset * sizeof(uint32_t);

        this->memcpy(&word, begin_copy, sizeof(uint32_t));
        return word;
    }

    /** @brief Retrieve the size of the buffer in bytes.
     */
    size_t size() const
    {
        return iv_bytes_contained;
    }

    /**
     * @brief Copy data out of the buffer at the given offset.
     *
     * @param[in] i_dest    The destination buffer.
     * @param[in] i_offset  The offset in the source buffer to copy from.
     * @param[in] i_count   The number of bytes to copy.
     *
     * @note Asserts on out-of-bounds access in the source buffer.
     */
    void memcpy(void* const i_dest, size_t i_offset, size_t i_count) const
    {
        if (i_offset + i_count < i_offset
            || i_offset > iv_bytes_contained
            || i_offset + i_count > iv_bytes_contained)
        {
            assert(false,
                   "discontiguous_buffer::memcpy index %ld + count %ld out of bounds %ld",
                   i_offset, i_count, iv_bytes_contained);
        }

        uint8_t* dest_bytes = static_cast<uint8_t*>(i_dest);

        while (i_offset < iv_bytes_contained && i_count > 0)
        {
            *dest_bytes = *get_ptr(i_offset);
            ++dest_bytes;
            ++i_offset;
            --i_count;
        }
    }

private:
    /** @brief Deleter class for a page. */
    struct free_page
    {
        void operator()(uint8_t* const i_page) const {
#ifdef __HOSTBOOT_RUNTIME
            free(i_page);
#else
            return PageManager::freePage(i_page);
#endif
        }
    };

    using page_ptr = std::unique_ptr<uint8_t, free_page>;
    std::vector<page_ptr> iv_pages;

    // The number of bytes actually used.
    size_t iv_bytes_contained = 0;

    /** @brief Allocate a single page of data. */
    static uint8_t* allocate_page()
    {
#ifdef __HOSTBOOT_RUNTIME
        return static_cast<uint8_t*>(malloc(PAGE_SIZE));
#else
        return static_cast<uint8_t*>(PageManager::allocatePage(1, /*userspace=*/true));
#endif
    }

    /**
     * @brief Retrieve a pointer to the byte at the given index in the
     * buffer.
     *
     * @note Automatically resizes when the index is out-of-bounds.
     */
    uint8_t* get_ptr(const size_t i_idx)
    {
        const size_t page = i_idx / PAGE_SIZE;
        const size_t offset = i_idx % PAGE_SIZE;

        while (iv_pages.size() <= page)
        {
            iv_pages.push_back(page_ptr(allocate_page(), free_page { }));
        }

        return iv_pages[page].get() + offset;
    }

    /**
     * @brief Retrieve a pointer to the byte at the given index in the
     * buffer.
     *
     * @note Asserts when the index is out-of-bounds.
     */
    const uint8_t* get_ptr(const size_t i_idx) const
    {
        const size_t page = i_idx / PAGE_SIZE;
        const size_t offset = i_idx % PAGE_SIZE;

        if (page >= iv_pages.size())
        {
            assert(false, "discontiguous_buffer::get_ptr() const: Index %ld out of bounds (pages = %ld)",
                   i_idx, iv_pages.size());
        }

        return iv_pages[page].get() + offset;
    }
};

/**
 * @brief A class for managing dual input buffers for sbeio fifo response
 *        messaging.
 *
 * Sbeio messaging uses a pair of buffers for parsing fifo response
 * messages. The first buffer is a caller supplied buffer that must be large
 * enough to hold required data for a given message response. For example,
 * a read command will have a response that will contain the data read and a
 * status header. A write command will have a response that will contain
 * only a status header detailing the result of the command. In addition,
 * response data can include FFDC data upon an error. The user supplied
 * buffer does not need to be big enough to hold the extra data since this
 * information is processed by the messaging code before returning to the
 * caller. As a result, a second buffer which should be large enough to
 * to contain any FFDC information is processed in parallel with the caller
 * supplied buffer in order to capture a full response.
 */
class SbeFifoRespBuffer
{
    // The SbeFifo should have access to protected members for error logging purposes.
    friend class SbeFifo;
public:

    /**
     * @brief Constructor.
     *
     * @param[in] i_fifoBuffer -   The caller supplied buffer.
     * @param[in] bufferWordSize - The size of the caller supplied buffer in
     *                             uint32_t units.
     * @param[in] i_getSbeFfdcFmt - A bool indicating if this is for a get SBE
     *                              FFDC request with a special buffer format.
     */
    explicit SbeFifoRespBuffer(uint32_t * i_fifoBuffer, size_t bufferWordSize,
                               bool i_getSbeFfdcFmt = false);

    //This is a helper class intended for local use only.
    SbeFifoRespBuffer(const SbeFifoRespBuffer&) = delete;
    SbeFifoRespBuffer(SbeFifoRespBuffer&&) = delete;

    SbeFifoRespBuffer& operator=(const SbeFifoRespBuffer&) = delete;
    SbeFifoRespBuffer& operator=(SbeFifoRespBuffer&&) = delete;

    //=======================
    // Message construction
    //========================

    /**
     * @brief append a uint32 to the next buffer insert position.
     *
     * @param[in] i_value - The value to add to the buffers.
     *
     * @return True if the value was able to be stored in at least the local
     *         buffer, false otherwise.
     */
    bool append(uint32_t i_value);

    /**
     * @brief When the DN FIFO Dequeued EOT flag is detected
     *        externally, this method is called to validate
     *        the buffer data and set indexes to the status
     *        and ffdc areas.
     */
    void completeMessage();

    //============================
    // Messaging State
    //============================

    /**
     * @brief operator that returns true if the messaging
     *        state is MSG_INCOMPLETE. This indicates that
     *        data is able to be appended to the buffer(s)
     */
    operator bool() const {return MSG_INCOMPLETE == iv_state;}

    /**
     * @brief Current state of the messaging buffer
     *
     */
    enum State{
                INVALID_CALLER_BUFFER = 0, /**< enum Caller buffer too short */
                OVERRUN = 1,               /**< enum message larger than local
                                              buffer */
                MSG_SHORT_READ = 2,        /**< enum Message is shorter that
                                                header */
                MSG_INVALID_OFFSET = 3,   /**< enum The message contains an
                                               invalid status header offset */
                MSG_COMPLETE = 4,         /**< enum The message was read in
                                                    successfully */
                MSG_INCOMPLETE = 5        /**< enum The message is being
                                                    constructed */
              };

    /**
     * @brief Accessor for messaging state.
     *
     * @return The state of the messaging buffers.
     */
    State getState() const {return iv_state;}

    /**
     * @brief A simplified state accessor.
     *
     * @return True if the state is MSG_COMPLETE or MSG_INCOMPLETE
     *         False otherwise.
     */
    bool getStatus() const {return (MSG_COMPLETE == iv_state ||
                                                MSG_INCOMPLETE == iv_state);}

    /**
     * @brief Accessor for if the message has been successfully completed.
     *
     * @return True if the message has been successfully completed.
     */
    bool isMsgComplete() const {return MSG_COMPLETE == iv_state;}

    //=================
    //FFDC
    //=================

    /**
     * @brief Does the message contain FFDC data.
     *
     * @return True if the message is complete and contains FFDC data
     *         False otherwise.
     */
    bool msgContainsFFDC();

    /**
     * @brief FFDC data size.
     *
     * @return FFDC data size in bytes or 0 if the message is incomplete
     *         or does not have FFDC data.
     */
    size_t getFFDCByteSize();

    /**
     * @brief Return a copy of the FFDC data in the message, if any.
     *
     * @note Return vector will be empty if there is no FFDC data in the message.
     */
    std::vector<uint8_t> getFFDCData();

    /**
     * @brief Copy data out of the SbeFifoRespBuffer and into the
     * given destination buffer.
     *
     * @param[in] i_dest    The destination buffer.
     * @param[in] i_offset  The offset in the source buffer to copy from.
     * @param[in] i_count   The byte count to copy.
     */
    void memcpy(void* const i_dest, size_t i_offset, size_t i_count) const
    {
        iv_buffer.memcpy(i_dest, i_offset, i_count);
    }

    /**
     * @brief FFDC data size.
     *
     * @return FFDC data size in words or 0 if the message is incomplete
     *         or does not have FFDC data.
     */
    size_t getFFDCWordSize();

    //=================================
    // Status Header
    //=================================

    /**
     * @brief Returns the StatusHeader struct from the message.
     *
     * @return The StatusHeader struct, valid only if the
     *         buffer state is MSG_COMPLETE.
     */
    SbeFifo::statusHeader getStatusHeader();

    //================================
    // Return Data
    //================================

    /**
     * @brief Determine if the message contains return data.
     *
     * @return True if the message is complete and has return data
     *         False otherwise.
     *
     */
    bool msgContainsReturnData();

    /**
     * @brief Obtain a copy of return data
     *
     * @return A copy of the return data if the message is complete and
     *         contains return data. Empty vector is returned otherwise.
     */
    std::vector<uint8_t> getReturnData();

    /**
     * @brief Obtain the return data size in bytes.
     *
     * @return The return data size in bytes if the message is complete and
     *         contains return data, 0 is returned otherwise.
     */
    size_t getReturnDataByteSize();

    /**
     * @brief Obtain the return data size in uint32_t words.
     *
     * @return The return data size in bytes if the message is complete and
     *         contains return data, 0 is returned otherwise.
     */
    size_t getReturnDataWordSize();

    /*
     * @brief Obtain the current index for debugging
     *
     * @return - The current Index
     */
    size_t index() const {return iv_index;}

    /*
     * @brief Obtain the offset Index for debugging
     *
     * @return - The offset Index
     *
     */
    size_t offsetIndex() const {return iv_offsetIndex;}

    /*
     * @brief Obtain the offset to the Status Header
     *        for debugging and error reporting.
     *
     * @return - The offset to the status header.
     *
     */
    size_t offset() const { return iv_buffer.word_at(iv_offsetIndex);}

    //=========================
    // Class Constants
    //=========================

    // Different size FIFO buffers are used for P10 and POZ (which includes Odyssey)
    static constexpr size_t MSG_BUFFER_SIZE_WORDS_P10 = (PAGE_SIZE * SBE_FFDC_MAX_PAGES_P10) / sizeof(uint32_t);
    static constexpr size_t MSG_BUFFER_SIZE_WORDS_POZ = (PAGE_SIZE * SBE_FFDC_MAX_PAGES_POZ) / sizeof(uint32_t);
    static constexpr size_t INVALID_INDEX = size_t(-1);

protected:

   //=====================
   // Unit Test Access
   //=====================
   const uint32_t * callerBuffer() const {return iv_callerBufferPtr;}
   size_t callerWordSize() const {return iv_callerWordSize;}

   size_t statusIndex() const {return iv_statusIndex;}
   size_t ffdcIndex() const {return iv_ffdcIndex;}

   const char* getStateString() const {return cv_stateStrings[iv_state];}

   void setBufferState(State newValue){iv_state = newValue;}

private:

   //====================
   // Buffers
   //====================

   discontiguous_buffer iv_buffer;

   uint32_t * const iv_callerBufferPtr{}; /**< caller supplied buffer should
                                             be large enough to hold at least
                                             return data and status */

   const size_t iv_callerWordSize; /**< caller buffer size in uint32_t units */

   bool iv_getSbeFfdcFmt; /**< indicates if buffer is for a get SBE FFDC request
                             and has a special format where the return data is
                             the FFDC and there is no FFDC after the status
                             header */

   //====================
   // Index and State
   //====================

   size_t iv_index{}; /**< denotes the next insert position */
   size_t iv_offsetIndex{INVALID_INDEX}; /**< position of offset to the status header */
   size_t iv_statusIndex{INVALID_INDEX}; /**< position of the status header */
   size_t iv_ffdcIndex{INVALID_INDEX}; /**< position of FFDC data if any */
   size_t iv_ffdcSize{0}; /**< size of ffdc data if any is present */

   State iv_state{MSG_INCOMPLETE}; /**< Messaging State */

   static const char* cv_stateStrings[]; /**< Messaging State Strings */
};

} //End Namespace SBEIO

#endif
