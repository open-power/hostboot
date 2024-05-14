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

#include <discontiguous.H>

namespace SBEIO
{


/**
 * @brief A class for managing the sbeio fifo response messaging.
 *
 * Sbeio messaging uses a discontiguous buffer for parsing fifo response
 * messages. The buffer will hold the required data for a given message response.
 * For example, a read command will have a response that will contain the data
 * read and a status header. A write command will have a response that will contain
 * only a status header detailing the result of the command. In addition,
 * response data can include FFDC data upon an error. The extra data
 * information is processed by the messaging code before returning to the
 * caller.
 */
class SbeFifoRespBuffer
{
    // The SbeFifo should have access to protected members for error logging purposes.
    friend class SbeFifo;

public:

    /**
     * @brief Constructor.
     *
     * @param[in] i_getSbeFfdcFmt - A bool indicating if this is for a get SBE
     *                              FFDC request with a special buffer format.
     */
    explicit SbeFifoRespBuffer(bool i_getSbeFfdcFmt = false);

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
     * @brief Copy the FFDC data in the message to o_ffdc, if the message is
     *        complete and contains FFDC data. The vector is empty otherwise.
     *
     * @param[out] o_ffdc  The destination buffer
     */
    void getFFDCData(std::vector<uint8_t> &o_ffdc);

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
     * @brief Copy the return data in the message to o_data, if the message is
     *        complete and contains return data. No status bytes are included.
     *        The vector is empty otherwise.
     *
     * @param[out] o_data  The destination buffer
     */
    void getReturnData(std::vector<uint8_t> &o_data);

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

    /**
     * @brief Obtain the total buffer size in bytes
     *
     * @return The length of whatever data was read from the fifo
     */
    size_t getDataByteSize();

    /**
     * @brief set iv_getSbeFfdcFmt to true if cmd is GET_SBE_FFDC
     */
    void setFfdcFmt(void *i_hdr);

    /**
     * @brief Query if buffer is for a get SBE FFDC request
     *
     * @return iv_getSbeFfdcFmt
     */
    bool isFfdcFmt() {return iv_getSbeFfdcFmt;}

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
    size_t offset() const { return iv_buffer.word32_at(iv_offsetIndex);}

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

   size_t statusIndex() const {return iv_statusIndex;}
   size_t ffdcIndex() const {return iv_ffdcIndex;}

   const char* getStateString() const {return cv_stateStrings[iv_state];}

   void setBufferState(State newValue){iv_state = newValue;}

private:

   //====================
   // Buffers
   //====================

   BUFFER::discontiguous_t iv_buffer;

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
