/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_fifo_buffer.C $                             */
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
#include "sbe_fifo_buffer.H"
#include <trace/interface.H>

#include <algorithm>
#include <string.h>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio, printf_string,##args)

constexpr size_t STATUS_WORD_SIZE = sizeof(SBEIO::SbeFifo::statusHeader)/sizeof(uint32_t);

namespace SBEIO
{

// Use the larger of the MSG_BUFFER_SIZE_WORDS_* values to be safe
const size_t SbeFifoRespBuffer::MSG_BUFFER_SIZE_WORDS_POZ;

//------------------------------------------------------------------------
const char* SbeFifoRespBuffer::cv_stateStrings[] = {
                                            "INVALID_CALLER_BUFFER",
                                            "OVERRUN",
                                            "MSG_SHORT_READ",
                                            "MSG_INVALID_OFFSET",
                                            "MSG_COMPLETE",
                                            "MSG_INCOMPLETE"
                                          };

//-------------------------------------------------------------------------
SbeFifoRespBuffer::SbeFifoRespBuffer(uint32_t* i_fifoBuffer,
                                     size_t bufferWordSize,
                                     bool i_getSbeFfdcFmt)
                        : iv_callerBufferPtr(i_fifoBuffer),
                        // Use the larger of the MSG_BUFFER_SIZE_WORDS_* values to be safe
                        iv_callerWordSize( std::min(bufferWordSize, MSG_BUFFER_SIZE_WORDS_POZ) ),
                          iv_getSbeFfdcFmt(i_getSbeFfdcFmt)
{
    do {
        if(not i_fifoBuffer || iv_callerWordSize < STATUS_WORD_SIZE)
        {
            SBE_TRACF(ERR_MRK"SbeFifoRespBuffer CTOR: Caller buffer invalid.");
            iv_state = INVALID_CALLER_BUFFER;
            break;
        }

        memset(iv_callerBufferPtr, 0, iv_callerWordSize*sizeof(uint32_t));
    }
    while(0);
}

//---------------------------------------------------------------------
bool SbeFifoRespBuffer::append(uint32_t i_value)
{
    bool retval = false;

    if(iv_state == MSG_INCOMPLETE)
    {
        if(iv_index < iv_callerWordSize)
        {
            iv_callerBufferPtr[iv_index] = i_value;
        }

        // Use the larger of the MSG_BUFFER_SIZE_WORDS_* values to be safe
        if(iv_index < MSG_BUFFER_SIZE_WORDS_POZ)
        {
            iv_buffer.append(&i_value, sizeof(i_value));
            ++iv_index;
            retval = true;
        }
        else
        {
            SBE_TRACF(ERR_MRK"SbeFifoRespBuffer::append: Overran buffer.");
            iv_state = OVERRUN;
        }
    }
    else
    {
         SBE_TRACF(INFO_MRK"SbeFifoRespBuffer::append. "
                           "Invalid state for append, current state %s",
                            getStateString());
    }

    return retval;
}

//-------------------------------------------------------------------
void SbeFifoRespBuffer::completeMessage()
{
    do
    {
        if(MSG_INCOMPLETE == iv_state)
        {
            //Message Schema:
            // |Return Data (optional)| Status Header | FFDC (optional)
            // |Offset to Status Header (starting from EOT) | EOT |

            //Final index for a minimum complete message (No return data
            //and no FFDC):
            //Word Length of status header +
            //Length of Offset (1) + Length of EOT (1)
            if(iv_index < (STATUS_WORD_SIZE + 2))
            {
                SBE_TRACF(ERR_MRK"SbeFifoRespBuffer::completeMessage: "
                          "Complete call caused short read. (%d < %d)",
                          iv_index,
                          STATUS_WORD_SIZE + 2);
                iv_state = MSG_SHORT_READ;
                break;
            }

            // |offset to header| EOT marker | current insert pos | <- iv_index
            // The 'offset to header' is how many words to move back from the EOT position
            // to get the index of the Status Header.
            iv_offsetIndex = (iv_index - 2);

            const uint32_t ffdc_header_offset = iv_buffer.word_at(iv_offsetIndex);

            //Validate that the offset to the status header is in range
            if((ffdc_header_offset - 1) > iv_offsetIndex)
            {
                //offset is to large - would go before the buffer.
                SBE_TRACF(ERR_MRK"SbeFifoRespBuffer::completeMessage: "
                         "The offset to the StatusHeader is too large. "
                         "(%d > %d)",
                         ffdc_header_offset - 1,
                         iv_offsetIndex);
                iv_state = MSG_INVALID_OFFSET;
                break;
            }
            else if(ffdc_header_offset < (STATUS_WORD_SIZE + 1))
            {
                //Minimum offset (no ffdc) is StatusHeader size + 1
                SBE_TRACF(ERR_MRK"SbeFifoRespBuffer::completeMessage: "
                                 "The offset to the StatusHeader is too small. (%d < %d)",
                         ffdc_header_offset,
                         STATUS_WORD_SIZE + 1);
                iv_state = MSG_INVALID_OFFSET;
                break;
            }

            //Set The StatusHeader index
            iv_statusIndex = iv_offsetIndex - (ffdc_header_offset - 1);

            //Determine if there is FFDC data in the buffer. We check if the
            //buffer contains a get SBE FFDC response. If so, the FFDC is at the
            //start of the buffer in the return data. Otherwise, we do this by
            //checking that the index after the status header is less than the
            //offset index. If the offset index immediately follows the status
            //header then there is no FFDC in the header.
            if(iv_getSbeFfdcFmt)
            {
                iv_ffdcIndex = 0;
                iv_ffdcSize = iv_statusIndex;
                assert( ffdc_header_offset == (STATUS_WORD_SIZE + 1),
                        "Offset to status header is not 3");
            }
            else if((iv_statusIndex + STATUS_WORD_SIZE) < iv_offsetIndex)
            {
                iv_ffdcIndex = iv_statusIndex + STATUS_WORD_SIZE;
                iv_ffdcSize = (iv_offsetIndex - iv_ffdcIndex);
            }

            iv_state = MSG_COMPLETE;
        }
    }
    while(0);

    return;
}

//-------------------------------------------------------------------------
bool SbeFifoRespBuffer::msgContainsFFDC()
{
    bool retval{false};

    if(isMsgComplete())
    {
        if(INVALID_INDEX != iv_ffdcIndex)
        {
            retval = true;
        }
    }

    return retval;
}

//------------------------------------------------------------------------
std::vector<uint8_t> SbeFifoRespBuffer::getFFDCData()
{
    std::vector<uint8_t> data;

    if(msgContainsFFDC())
    {
        const size_t data_begin = iv_ffdcIndex * sizeof(uint32_t);
        const size_t data_len = iv_buffer.size() - data_begin;
        data.resize(data_len);
        iv_buffer.memcpy(data.data(), data_begin, data_len);
    }

    return data;
}

//--------------------------------------------------------------------------
size_t SbeFifoRespBuffer::getFFDCByteSize()
{
    size_t retval = 0;

    if(msgContainsFFDC())
    {
        retval = iv_ffdcSize * sizeof(uint32_t);
    }

    return retval;
}

//--------------------------------------------------------------------------
size_t SbeFifoRespBuffer::getFFDCWordSize()
{
    size_t retval = 0;

    if(msgContainsFFDC())
    {
        retval = iv_ffdcSize;
    }

    return retval;
}

//---------------------------------------------------------------------------
SbeFifo::statusHeader SbeFifoRespBuffer::getStatusHeader()
{
    SbeFifo::statusHeader retval{};

    if(isMsgComplete())
    {
        iv_buffer.memcpy(&retval, iv_statusIndex * sizeof(uint32_t), sizeof(retval));
    }

    return retval;
}

//---------------------------------------------------------------------------
bool SbeFifoRespBuffer::msgContainsReturnData()
{
    bool retval{false};

    if(isMsgComplete())
    {
        retval = (iv_statusIndex > 0);
    }

    return retval;
}

//---------------------------------------------------------------------------
std::vector<uint8_t> SbeFifoRespBuffer::getReturnData()
{
    std::vector<uint8_t> retval{};

    if(msgContainsReturnData())
    {
        retval.resize(iv_buffer.size());
        iv_buffer.memcpy(retval.data(), 0, iv_buffer.size());
    }

    return retval;
}

//----------------------------------------------------------------------------
size_t SbeFifoRespBuffer::getReturnDataByteSize()
{
    size_t retval = 0;

    if(msgContainsReturnData())
    {
        retval = iv_statusIndex * sizeof(uint32_t);
    }

    return retval;
}

//---------------------------------------------------------------------------
size_t SbeFifoRespBuffer::getReturnDataWordSize()
{
    size_t retval = 0;

    if(msgContainsReturnData())
    {
        retval = iv_statusIndex;
    }

    return retval;
}

} //End Namespace SBEIO
