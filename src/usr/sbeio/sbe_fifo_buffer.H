/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_fifo_buffer.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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

namespace SBEIO
{

/**
 * @brief A class for managing duel input buffers for sbeio fifo response
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
     * @brief Accessor to FFDC data.
     *
     * @returns pointer to FFDC data if the message is complete and contains
     *          FFDC data. A nullptr is returned otherwise.
     *
     */
    const void * getFFDCPtr();

    /**
     * @brief FFDC data size.
     *
     * @return FFDC data size in bytes or 0 if the message is incomplete
     *         or does not have FFDC data.
     */
    size_t getFFDCByteSize();

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
     * @brief Returns a pointer to the StatusHeader struct.
     *
     * @return A pointer to the StatusHeader struct if the
     *         buffer state is MSG_COMPLETE, or a NULL pointer
     *         otherwise.
     */
    const SbeFifo::statusHeader * getStatusHeader();

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
     * @brief Obtain a pointer to return data
     *
     * @return A pointer to return data if the message is complete and
     *         contains return data. A nullptr is returned otherwise.
     */
    const void * getReturnData();

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
     * @brief Obtain the local buffer for debugging.
     *
     * @return A pointer to the local buffer.
     */
    const uint32_t * localBuffer() const {return iv_localMsgBuffer;}

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
    size_t offset() const {return iv_localMsgBuffer[iv_offsetIndex];}

    //=========================
    // Class Constants
    //=========================

    static const size_t MSG_BUFFER_SIZE_WORDS = 3072;
    static const size_t INVALID_INDEX = size_t(-1);

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

   uint32_t iv_localMsgBuffer[MSG_BUFFER_SIZE_WORDS]; /**< local buffer large enough
                                                           to hold FFDC data */

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
   size_t iv_offsetIndex{INVALID_INDEX}; /**< position of offset to the
                                              status header */
   size_t iv_statusIndex{INVALID_INDEX}; /**< position of the status header */
   size_t iv_ffdcIndex{INVALID_INDEX}; /**< position of FFDC data if any */
   size_t iv_ffdcSize{0}; /**< size of ffdc data if any is present */

   State iv_state{MSG_INCOMPLETE}; /**< Messaging State */

   static const char* cv_stateStrings[]; /**< Messaging State Strings */
};

} //End Namespace SBEIO

#endif
