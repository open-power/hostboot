/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_fifo_buffer_test.H $                   */
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
#ifndef __SBEIO_SBE_FIFO_BUFFER_TEST_H
#define __SBEIO_SBE_FIFO_BUFFER_TEST_H

#include <vector>

#include <cxxtest/TestSuite.H>
#include "sbe_test_support.H"

#include <sbe_fifo_buffer.H>
#include <trace/interface.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_BUFFER_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"sbeFifoBufferTest: " printf_string,##args)
#define SBE_BUFFER_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"sbeFifoBufferTest: " printf_string,##args)

using namespace SBEIO;

class SbeFifoRespBufferTestFixture : public SbeFifoRespBuffer
{
public:

    explicit SbeFifoRespBufferTestFixture(bool i_getSbeFfdcFmt = false):
                                SbeFifoRespBuffer(i_getSbeFfdcFmt)
    {
    }

    //expose data for testing
    using SbeFifoRespBuffer::index;
    using SbeFifoRespBuffer::offsetIndex;
    using SbeFifoRespBuffer::statusIndex;
    using SbeFifoRespBuffer::ffdcIndex;
    using SbeFifoRespBuffer::getStateString;
    using SbeFifoRespBuffer::setBufferState;
};


std::vector<uint32_t> bufferNoReturnNoFFDC = {
                                    0xC0DEA807, //Status Header 1
                                    0x00000000, //Status Header 2
                                    0x00000003, //word offset from the EOT to Status Header entry
                                    0x00000001  //EOT
                                  };

std::vector<uint32_t>  bufferReturnNoFFDC = {
                                    0x00010002, //Return Data 1
                                    0x00030004, //Return Data 2
                                    0xC0DEA807, //Status Header 1
                                    0x00000000, //Status Header 2
                                    0x00000003, //word offset from the EOT to Status Header entry
                                    0x00000001  //EOT
                                };

std::vector<uint32_t>  bufferNoReturnFFDC = {
                                    0xC0DEA807, //Status Header 1
                                    0x00FE0099, //Status Header 2
                                    0xFFDC0009, //FFDC 1 - Magic, Len (in words)
                                    0x0000A807, //FFDC 2 - Seq, Cmd class, cmd
                                    0x00983AB6, //FFDC 3 - RC_SBE_SCOM_FAILURE
                                    0x00000004, //FFDC 4 - scom addr size
                                    0x00000000, //FFDC 5 - scom addr
                                    0x12345678, //FFDC 6 - scom addr
                                    0x00000001, //FFDC 7 - PIB RC size
                                    0x00000000, //FFDC 8 - PIB_PARITY_ERROR
                                    0x00000006, //FFDC 9 - PIB_PARITY_ERROR
                                    0x0000000C, //word offset from the EOT to Status Header entry
                                    0x00000001, //EOT
                                };

std::vector<uint32_t>  bufferReturnFFDC = {
                                    0x00000001, //Return Data 1
                                    0x00000002, //Return Data 2
                                    0x00000003, //Return Data 3
                                    0xC0DEA807, //Status Header 1
                                    0x00FE0099, //Status Header 2
                                    0xFFDC0009, //FFDC 1 - Magic, Len
                                    0x0000A807, //FFDC 2 - Seq, Cmd class, cmd
                                    0x00983AB6, //FFDC 3 - RC_SBE_SCOM_FAILURE
                                    0x00000008, //FFDC 4 - scom addr size
                                    0x12345678, //FFDC 5 - scom addr msb
                                    0x9ABCDEF0, //FFDC 6 - scom addr lsb
                                    0x00000001, //FFDC 7 - PIB RC size
                                    0x00000000, //FFDC 8 - PIB_PARITY_ERROR msb
                                    0x00000006, //FFDC 9 - PIB_PARITY_ERROR lsb
                                    0x0000000C, //word offset from the EOT to Status Header entry
                                    0x00000001, //EOT
                                };

std::vector<uint32_t> bufferLongOffset = {
                                    0xC0DEA807, //Status Header 1
                                    0x00000000, //Status Header 2
                                    0x00000004, //word offset from the EOT to Status Header entry
                                    0x00000001  //EOT
                                };

std::vector<uint32_t> bufferShortOffset = {
                                    0xC0DEA807, //Status Header 1
                                    0x00000000, //Status Header 2
                                    0x00000002, //word offset from the EOT to Status Header entry
                                    0x00000001  //EOT
                                };

std::vector<uint32_t> bufferShortRead = {
                                    0xC0DEA807, //Status Header 1
                                    0x00000000, //Status Header 2
                                    0x00000001  //EOT
                                };

std::vector<uint32_t>  bufferGetSbeFFDC = {
                                    0xFFDC0009, //FFDC 1 - Magic, Len
                                    0x0000A801, //FFDC 2 - Seq, Cmd class, cmd
                                    0x00000000, //FFDC 3 - return code
                                    0x00000004, //FFDC 4 - scom addr size
                                    0x00000000, //FFDC 5 - scom addr msb
                                    0x12345678, //FFDC 6 - scom addr lsb
                                    0x00000001, //FFDC 7 - PIB RC size
                                    0x00000000, //FFDC 8 - PIB_PARITY_ERROR msb
                                    0x00000006, //FFDC 9 - PIB_PARITY_ERROR lsb
                                    0xC0DEA801, //Status Header 1
                                    0x00000000, //Status Header 2
                                    0x00000003, //word offset from the EOT to Status Header entry
                                    0x00000001, //EOT
                                };

size_t overrun_element_count{SbeFifoRespBuffer::MSG_BUFFER_SIZE_WORDS_POZ + 1};
uint32_t overrun_element_value{34};
std::vector<uint32_t> bufferOverrun(overrun_element_count,
                                    overrun_element_value);

//===================================================
class SbeFifoBufferTest : public CxxTest::TestSuite
{
public:

    struct expected_data
    {
        const char* test_name;
        size_t index;
        size_t offset_index;
        size_t offset;

        size_t statusIndex;
        const void* expected_status;

        bool expectFFDC;
        size_t ffdcIndex;
        size_t ffdcByteSize;
        const void* expected_ffdc_data;

        bool expectReturnData;
        size_t dataByteSize;
        const void* expected_data;

        char strMessage[512];
    };

    void testDiscontiguousBuffer()
    {
        TS_INFO("SbeFifoBufferTest: TC_testDiscontiguousBuffer");

        BUFFER::discontiguous_t buf;

        for (int i = 0; i < 1024; ++i)
        {
            buf.append(0xab);
        }

        char data[4096];
        memset(data, 0xdc, 4096);
        buf.append(data, 4096);

        if (buf.size() != 1024 + 4096)
        {
            TS_FAIL("testDiscontiguousBuffer: size is %d, expected %d",
                    1024 + 4096,
                    buf.size());
            return;
        }

        unsigned int i = 0;
        for (; i < 1024 / 4; ++i)
        {
            if (buf.word32_at(i) != 0xabababab)
            {
                TS_FAIL("testDiscontiguousBuffer: Word at index %d "
                        "is 0x%08X, expected 0xabababab",
                        i,
                        buf.word32_at(i));
                return;
            }
        }

        while (i < buf.size() / 4)
        {
            if (buf.word32_at(i) != 0xdcdcdcdc)
            {
                TS_FAIL("testDiscontiguousBuffer: Word at index %d "
                        "is 0x%08X, expected 0xdcdcdcdc",
                        i,
                        buf.word32_at(i));
                return;
            }
            ++i;
        }

        char buf2[4];
        buf.memcpy(buf2, 1024 - 2, 4);

        if (buf2[0] != 0xab || buf2[1] != 0xab
            || buf2[2] != 0xdc || buf2[3] != 0xdc)
        {
            TS_FAIL("testDiscontiguousBuffer: memcpy failed, expected "
                    "0xababdcdc, got 0x%02x%02x%02x%02x",
                    buf2[0], buf2[1], buf2[2], buf2[3]);
            return;
        }

        SBE_BUFFER_TRACD(EXIT_MRK"testDiscontiguousBuffer");
    }

    //------------------------------------------------
    void testState()
    {
        TS_INFO("sbeFifoBufferTest: TC_testState");

        bool result{true};

        //Set buffer to various states and test responses

        /* The operator bool is implemented so that the fifobuffer object can
         * be used as a control variable for a while loop. The operator bool
         * only returns true if data is allowed to be added to the buffer
         * (i.e. the state is MSG_INCOMPLETE). A SbeFifoRespBuffer object which
         * is in an error state or contains a complete message is no longer
         * able to accept new data to add to the internal buffers and as such
         * will return false for the conversion operator.
        */

        /* The getStatus method on the other hand returns true if the
         * SbeFifoRespBuffer object is not in an error state. The MSG_COMPLETE
         * and MSG_INCOMPLETE are the non-error states, any other state will
         * cause getStatus to return false.
        */

        do
        {
            SbeFifoRespBufferTestFixture fifoBuffer;

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "The FIFO buffer is not in a good state after "
                        "CTOR call. Buffer state: %s",
                         fifoBuffer.getStateString()
                       );

                result = false;
            }

            fifoBuffer.setBufferState(SbeFifoRespBuffer::OVERRUN);

            if(fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "The operator bool unexpectedly returned true "
                        "after setting the state to OVERRUN"
                       );

                result = false;
            }

            if(fifoBuffer.getStatus())
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "getStatus unexpectedly returned true "
                        "after setting the state to OVERRUN"
                       );

                result = false;
            }

            fifoBuffer.setBufferState(SbeFifoRespBuffer::MSG_SHORT_READ);

            if(fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "The operator bool unexpectedly returned true "
                        "after setting the state to MSG_SHORT_READ"
                       );

                result = false;
            }

            if(fifoBuffer.getStatus())
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "getStatus unexpectedly returned true "
                        "after setting the state to MSG_SHORT_READ"
                       );

                result = false;
            }

            fifoBuffer.setBufferState(SbeFifoRespBuffer::MSG_INVALID_OFFSET);

            if(fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "The operator bool unexpectedly returned true "
                        "after setting the state to MSG_INVALID_OFFSET"
                       );

                result = false;
            }

            if(fifoBuffer.getStatus())
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "getStatus unexpectedly returned true "
                        "after setting the state to MSG_INVALID_OFFSET"
                       );

                result = false;
            }

            fifoBuffer.setBufferState(SbeFifoRespBuffer::MSG_COMPLETE);

            if(fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "The operator bool unexpectedly returned true "
                        "after setting the state to MSG_COMPLETE"
                       );

                result = false;
            }

            if(not fifoBuffer.getStatus())
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "getStatus unexpectedly returned false "
                        "after setting the state to MSG_COMPLETE"
                       );

                result = false;
            }

            fifoBuffer.setBufferState(SbeFifoRespBuffer::MSG_INCOMPLETE);

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "The operator bool unexpectedly returned false "
                        "after setting the state to MSG_INCOMPLETE"
                       );

                result = false;
            }

            if(not fifoBuffer.getStatus())
            {
                TS_FAIL("sbeFifoBufferTest testState: "
                        "getStatus unexpectedly returned false "
                        "after setting the state to MSG_INCOMPLETE"
                       );

                result = false;
            }
        }
        while(0);

        if(result)
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testState test passed!");
        }
        else
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testState test failed!");
        }
    }

    //------------------------------------------------
    void testNoReturnNoFFDC()
    {
        TS_INFO("sbeFifoBufferTest: TC_testNoReturnNoFFDC");

        //Test with buffer data that has No Return data and No FFDC
        //A successful write message will have this format.

        bool result{true};

        do
        {
            SbeFifoRespBufferTestFixture fifoBuffer;

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testNoReturnNoFFDC: "
                        "The FIFO buffer is not in a good state after "
                        "CTOR call. Buffer state: %s",
                         fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            setTestData(&bufferNoReturnNoFFDC);

            while(fifoBuffer)
            {
                uint32_t value{};
                bool rc = readTestData(value);
                if(rc)
                {
                    rc = fifoBuffer.append(value);
                    if(not rc)
                    {
                        TS_FAIL("sbeFifoBufferTest testNoReturnNoFFDC: "
                                "append operation unexpectedly failed. "
                                "Fifo Buffer state = %s",
                                 fifoBuffer.getStateString()
                               );

                        result = false;
                        break;
                    }
                }
                else
                {
                    fifoBuffer.completeMessage();
                }
            }

            if(not result)
            {
                break;
            }

            if(SbeFifoRespBuffer::MSG_COMPLETE != fifoBuffer.getState())
            {
                TS_FAIL("sbeFifoBufferTest testNoReturnNoFFDC: "
                        "Buffer unexpectedly not in the complete state after "
                        "populating buffer. State = %s.",
                        fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            if(not fifoBuffer.isMsgComplete())
            {
                TS_FAIL("sbeFifoBufferTest testNoReturnNoFFDC: "
                        "unexpectedly returned false for isMsgComplete"
                       );

                result = false;
                break;
            }

            if(not fifoBuffer.getStatus())
            {
                TS_FAIL("sbeFifoBufferTest testNoReturnNoFFDC: "
                        "unexpectedly returned false for getStatus"
                       );

                result = false;
                break;
            }

            expected_data expData;
            memset(&expData, 0, sizeof(expData));

            expData.test_name = "sbeFifoBufferTest testNoReturnNoFFDC";
            expData.index = 4;
            expData.offset_index = 2;
            expData.offset = 3;

            expData.statusIndex = 0;
            expData.expected_status = &bufferNoReturnNoFFDC[0];

            expData.expectFFDC = false;
            expData.expectReturnData = false;

            bool check_result = runChecks(expData, fifoBuffer);

            if(not check_result)
            {
                TS_FAIL("%s", expData.strMessage);

                result = false;
                break;
            }
        }
        while(0);

        if(result)
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testNoReturnNoFFDC "
                                                              "test passed!");
        }
        else
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testNoReturnNoFFDC "
                                                              "test failed!");
        }
    }

    //-----------------------------------------------------
    void testReturnNoFFDC()
    {
        TS_INFO("sbeFifoBufferTest: TC_testReturnNoFFDC");

        //Test with buffer data that has Return data and No FFDC
        //A successful read message will have this format.

        bool result{true};

        do
        {
            SbeFifoRespBufferTestFixture fifoBuffer;

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testReturnNoFFDC: "
                        "The FIFO buffer is not in a good state after "
                        "CTOR call. Buffer state: %s",
                         fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            setTestData(&bufferReturnNoFFDC);

            while(fifoBuffer)
            {
                uint32_t value{};
                bool rc = readTestData(value);
                if(rc)
                {
                    rc = fifoBuffer.append(value);
                    if(not rc)
                    {
                        TS_FAIL("sbeFifoBufferTest testReturnNoFFDC: "
                                "append operation unexpectedly failed. "
                                "Fifo Buffer state = %s",
                                 fifoBuffer.getStateString()
                               );

                        result = false;
                        break;
                    }
                }
                else
                {
                    fifoBuffer.completeMessage();
                }
            }

            if(not result)
            {
                break;
            }

            if(SbeFifoRespBuffer::MSG_COMPLETE != fifoBuffer.getState())
            {
                TS_FAIL("sbeFifoBufferTest testReturnNoFFDC: "
                        "Buffer unexpectedly not in the complete state after "
                        "populating buffer. State = %s.",
                        fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            if(not fifoBuffer.isMsgComplete())
            {
                TS_FAIL("sbeFifoBufferTest testReturnNoFFDC: "
                        "unexpectedly returned false for isMsgComplete"
                       );

                result = false;
                break;
            }

            if(not fifoBuffer.getStatus())
            {
                TS_FAIL("sbeFifoBufferTest testReturnNoFFDC: "
                        "unexpectedly returned false for getStatus"
                       );

                result = false;
                break;
            }

            expected_data expData;
            memset(&expData, 0, sizeof(expData));

            expData.test_name = "sbeFifoBufferTest testReturnNoFFDC";
            expData.index = 6;
            expData.offset_index = 4;
            expData.offset = 3;

            expData.statusIndex = 2;
            expData.expected_status = &bufferReturnNoFFDC[2];

            expData.expectFFDC = false;

            expData.expectReturnData = true;
            expData.dataByteSize = sizeof(uint32_t) * 2;
            expData.expected_data = &bufferReturnNoFFDC[0];

            bool check_result = runChecks(expData, fifoBuffer);

            if(not check_result)
            {
                TS_FAIL("%s", expData.strMessage);

                result = false;
                break;
            }
        }
        while(0);

        if(result)
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testReturnNoFFDC "
                                                            "test passed!");
        }
        else
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testReturnNoFFDC "
                                                            "test failed!");
        }
    }

    //--------------------------------------------------------------------
    void testNoReturnFFDC()
    {
        TS_INFO("sbeFifoBufferTest: TC_testNoReturnFFDC");

        //Test with buffer data that has No Return data and FFDC data
        //An unsuccessful write message will have this format.

        bool result{true};

        do
        {
            SbeFifoRespBufferTestFixture fifoBuffer;

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testNoReturnFFDC: "
                        "The FIFO buffer is not in a good state after "
                        "CTOR call. Buffer state: %s",
                         fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            setTestData(&bufferNoReturnFFDC);

            while(fifoBuffer)
            {
                uint32_t value{};
                bool rc = readTestData(value);
                if(rc)
                {
                    rc = fifoBuffer.append(value);
                    if(not rc)
                    {
                        TS_FAIL("sbeFifoBufferTest testNoReturnFFDC: "
                                "append operation unexpectedly failed. "
                                "Fifo Buffer state = %s",
                                 fifoBuffer.getStateString()
                               );

                        result = false;
                        break;
                    }
                }
                else
                {
                    fifoBuffer.completeMessage();
                }
            }

            if(not result)
            {
                break;
            }

            if(SbeFifoRespBuffer::MSG_COMPLETE != fifoBuffer.getState())
            {
                TS_FAIL("sbeFifoBufferTest testNoReturnFFDC: "
                        "Buffer unexpectedly not in the complete state after "
                        "populating buffer. State = %s.",
                        fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            if(not fifoBuffer.isMsgComplete())
            {
                TS_FAIL("sbeFifoBufferTest testNoReturnFFDC: "
                        "unexpectedly returned false for isMsgComplete"
                       );

                result = false;
                break;
            }

            if(not fifoBuffer.getStatus())
            {
                TS_FAIL("sbeFifoBufferTest testNoReturnFFDC: "
                        "unexpectedly returned false for getStatus"
                       );

                result = false;
                break;
            }

            expected_data expData;
            memset(&expData, 0, sizeof(expData));

            expData.test_name = "sbeFifoBufferTest testNoReturnFFDC";
            expData.index = 13;
            expData.offset_index = 11;
            expData.offset = 12;

            expData.statusIndex = 0;
            expData.expected_status = &bufferNoReturnFFDC[0];

            expData.expectFFDC = true;
            expData.ffdcIndex = 2;
            expData.ffdcByteSize = sizeof(uint32_t)*9;
            expData.expected_ffdc_data = &bufferNoReturnFFDC[2];

            expData.expectReturnData = false;

            bool check_result = runChecks(expData, fifoBuffer);

            if(not check_result)
            {
                TS_FAIL("%s", expData.strMessage);
                result = false;
                break;
            }
        }
        while(0);

        if(result)
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testNoReturnFFDC "
                                                              "test passed!");
        }
        else
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testNoReturnFFDC "
                                                              "test failed!");
        }
    }

    //-----------------------------------------------------------------------
    void testReturnFFDC()
    {
        TS_INFO("sbeFifoBufferTest: TC_testReturnFFDC");

        //Test with buffer data that has both Return data and FFDC data

        bool result{true};

        do
        {
            SbeFifoRespBufferTestFixture fifoBuffer;

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testReturnFFDC: "
                        "The FIFO buffer is not in a good state after "
                        "CTOR call. Buffer state: %s",
                         fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            setTestData(&bufferReturnFFDC);

            while(fifoBuffer)
            {
                uint32_t value{};
                bool rc = readTestData(value);
                if(rc)
                {
                    rc = fifoBuffer.append(value);
                    if(not rc)
                    {
                        TS_FAIL("sbeFifoBufferTest testReturnFFDC: "
                                "append operation unexpectedly failed. "
                                "Fifo Buffer state = %s",
                                 fifoBuffer.getStateString()
                               );

                        result = false;
                        break;
                    }
                }
                else
                {
                    fifoBuffer.completeMessage();
                }
            }

            if(not result)
            {
                break;
            }

            if(SbeFifoRespBuffer::MSG_COMPLETE != fifoBuffer.getState())
            {
                TS_FAIL("sbeFifoBufferTest testReturnFFDC: "
                        "Buffer unexpectedly not in the complete state after "
                        "populating buffer. State = %s.",
                        fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            if(not fifoBuffer.isMsgComplete())
            {
                TS_FAIL("sbeFifoBufferTest testReturnFFDC: "
                        "unexpectedly returned false for isMsgComplete"
                       );

                result = false;
                break;
            }

            if(not fifoBuffer.getStatus())
            {
                TS_FAIL("sbeFifoBufferTest testReturnFFDC: "
                        "unexpectedly returned false for getStatus"
                       );

                result = false;
                break;
            }

            expected_data expData;
            memset(&expData, 0, sizeof(expData));

            expData.test_name = "ReturnFFDC";
            expData.index = 16;
            expData.offset_index = 14;
            expData.offset = 12;

            expData.statusIndex = 3;
            expData.expected_status = &bufferReturnFFDC[3];

            expData.expectFFDC = true;
            expData.ffdcIndex = 5;
            expData.ffdcByteSize = sizeof(uint32_t)*9;
            expData.expected_ffdc_data = &bufferReturnFFDC[5];

            expData.expectReturnData = true;
            expData.dataByteSize = sizeof(uint32_t) * 3;
            expData.expected_data = &bufferReturnFFDC[0];

            bool check_result = runChecks(expData, fifoBuffer);

            if(not check_result)
            {
                TS_FAIL("%s", expData.strMessage);

                result = false;
                break;
            }
        }
        while(0);

        if(result)
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testReturnFFDC test passed!");
        }
        else
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testReturnFFDC test failed!");
        }
    }

    //------------------------------------------------------------------------
    void testBadOffsetLong()
    {
        TS_INFO("sbeFifoBufferTest: TC_testBadOffsetLong");

        //Test with an offset that points to beyond that start of the buffer

        bool result{true};

        do
        {
            SbeFifoRespBufferTestFixture fifoBuffer;

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testBadOffsetLong: "
                        "The FIFO buffer is not in a good state after "
                        "CTOR call. Buffer state: %s",
                         fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            setTestData(&bufferLongOffset);

            while(fifoBuffer)
            {
                uint32_t value{};
                bool rc = readTestData(value);
                if(rc)
                {
                    rc = fifoBuffer.append(value);
                    if(not rc)
                    {
                        TS_FAIL("sbeFifoBufferTest testBadOffsetLong: "
                                "append operation unexpectedly failed. "
                                "Fifo Buffer state = %s",
                                 fifoBuffer.getStateString()
                               );

                        result = false;
                        break;
                    }
                }
                else
                {
                    fifoBuffer.completeMessage();
                }
            }

            if(not result)
            {
                break;
            }

            if(SbeFifoRespBuffer::MSG_INVALID_OFFSET != fifoBuffer.getState())
            {
                TS_FAIL("sbeFifoBufferTest testBadOffsetLong: "
                        "Buffer unexpectedly not in the INVALID_OFFSET state "
                        "after populating buffer. State = %s.",
                        fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            if(fifoBuffer.isMsgComplete())
            {
                TS_FAIL("sbeFifoBufferTest testBadOffsetLong: "
                        "unexpectedly returned true for isMsgComplete"
                       );

                result = false;
                break;
            }
        }
        while(0);

        if(result)
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testBadOffsetLong "
                                                            "test passed!");
        }
        else
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testBadOffsetLong "
                                                            "test failed!");
        }
    }

    //----------------------------------------------------------------------
    void testBadOffsetShort()
    {
        TS_INFO("sbeFifoBufferTest: TC_testBadOffsetShort");

        //Test with an offset that is too short to reach the Status Header

        bool result{true};

        do
        {
            SbeFifoRespBufferTestFixture fifoBuffer;

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testBadOffsetShort: "
                        "The FIFO buffer is not in a good state after "
                        "CTOR call. Buffer state: %s",
                         fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            setTestData(&bufferShortOffset);

            while(fifoBuffer)
            {
                uint32_t value{};
                bool rc = readTestData(value);
                if(rc)
                {
                    rc = fifoBuffer.append(value);
                    if(not rc)
                    {
                        TS_FAIL("sbeFifoBufferTest testBadOffsetShort: "
                                "append operation unexpectedly failed. "
                                "Fifo Buffer state = %s",
                                 fifoBuffer.getStateString()
                               );

                        result = false;
                        break;
                    }
                }
                else
                {
                    fifoBuffer.completeMessage();
                }
            }

            if(not result)
            {
                break;
            }

            if(SbeFifoRespBuffer::MSG_INVALID_OFFSET != fifoBuffer.getState())
            {
                TS_FAIL("sbeFifoBufferTest testBadOffsetShort: "
                        "Buffer unexpectedly not in the INVALID_OFFSET state "
                        "after populating buffer. State = %s.",
                        fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            if(fifoBuffer.isMsgComplete())
            {
                TS_FAIL("sbeFifoBufferTest testBadOffsetShort: "
                        "unexpectedly returned true for isMsgComplete."
                       );

                result = false;
                break;
            }
        }
        while(0);

        if(result)
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testBadOffsetShort "
                                                             "test passed!");
        }
        else
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testBadOffsetShort "
                                                            "test failed!");
        }
    }

    //------------------------------------------------------------------------
    void testShortRead()
    {
        TS_INFO("sbeFifoBufferTest: TC_testShortRead");
        //Test case where message is completed prematurely

        bool result{true};

        do
        {
            SbeFifoRespBufferTestFixture fifoBuffer;

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testShortRead: "
                        "The FIFO buffer is not in a good state after "
                        "CTOR call. Buffer state: %s",
                         fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            setTestData(&bufferShortRead);

            while(fifoBuffer)
            {
                uint32_t value{};
                bool rc = readTestData(value);
                if(rc)
                {
                    rc = fifoBuffer.append(value);
                    if(not rc)
                    {
                        TS_FAIL("sbeFifoBufferTest testShortRead: "
                                "append operation unexpectedly failed. "
                                "Fifo Buffer state = %s",
                                 fifoBuffer.getStateString()
                               );

                        result = false;
                        break;
                    }
                }
                else
                {
                    fifoBuffer.completeMessage();
                }
            }

            if(not result)
            {
                break;
            }

            if(SbeFifoRespBuffer::MSG_SHORT_READ != fifoBuffer.getState())
            {
                TS_FAIL("sbeFifoBufferTest testShortRead: "
                        "Buffer unexpectedly not in the MSG_SHORT_READ state "
                        "after populating buffer. State = %s.",
                        fifoBuffer.getStateString()
                       );

               result = false;
               break;
            }

            if(fifoBuffer.isMsgComplete())
            {
                TS_FAIL("sbeFifoBufferTest testShortRead: "
                        "unexpectedly returned true for isMsgComplete"
                       );

               result = false;
               break;
            }
        }
        while(0);

        if(result)
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testShortRead test passed!");
        }
        else
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testShortRead test failed!");
        }
    }

    //-----------------------------------------------------------
    void testOverrun()
    {
        TS_INFO("sbeFifoBufferTest: TC_testOverrun");

        //Test the case where the message is not completed and
        //overruns the local buffer.

        bool result{true};
        do
        {
            SbeFifoRespBufferTestFixture fifoBuffer;

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testOverrun: "
                        "The FIFO buffer is not in a good state after "
                        " CTOR call. Buffer state: %s",
                         fifoBuffer.getStateString()
                       );

               result = false;
               break;
            }

            setTestData(&bufferOverrun);

            while(fifoBuffer)
            {
                uint32_t value{};
                bool rc = readTestData(value);
                if(rc)
                {
                    rc = fifoBuffer.append(value);
                    if(not rc && SbeFifoRespBuffer::OVERRUN !=
                                                        fifoBuffer.getState())
                    {
                        TS_FAIL("sbeFifoBufferTest testOverrun: "
                                "append operation unexpectedly failed. "
                                "Fifo Buffer state = %s",
                                 fifoBuffer.getStateString()
                               );

                        result = false;
                        break;
                    }
                }
                else
                {
                    fifoBuffer.completeMessage();
                }
            }

            if(not result)
            {
                break;
            }

            if(SbeFifoRespBuffer::OVERRUN != fifoBuffer.getState())
            {
                TS_FAIL("sbeFifoBufferTest testOverrun: "
                        "Buffer unexpectedly not in the OVERRUN state "
                        "after populating buffer. State = %s.",
                        fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            if(fifoBuffer.isMsgComplete())
            {
                TS_FAIL("sbeFifoBufferTest testOverrun: "
                        "unexpectedly returned true for isMsgComplete"
                       );

               result = false;
               break;
            }
        }
        while(0);

        if(result)
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testOverrun test passed!");
        }
        else
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testOverrun test failed!");
        }
    }

    //-----------------------------------------------------------------------
    void testGetSbeFFDC()
    {
        TS_INFO("sbeFifoBufferTest: TC_testGetSbeFFDC");

        //Test with buffer data that has FFDC data in get SBE FFDC format

        bool result{true};

        do
        {
            SbeFifoRespBufferTestFixture fifoBuffer(true);

            if(not fifoBuffer)
            {
                TS_FAIL("sbeFifoBufferTest testGetSbeFFDC: "
                        "The FIFO buffer is not in a good state after "
                        "CTOR call. Buffer state: %s",
                         fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            setTestData(&bufferGetSbeFFDC);

            while(fifoBuffer)
            {
                uint32_t value{};
                bool rc = readTestData(value);
                if(rc)
                {
                    rc = fifoBuffer.append(value);
                    if(not rc)
                    {
                        TS_FAIL("sbeFifoBufferTest testGetSbeFFDC: "
                                "append operation unexpectedly failed. "
                                "Fifo Buffer state = %s",
                                 fifoBuffer.getStateString()
                               );

                        result = false;
                        break;
                    }
                }
                else
                {
                    fifoBuffer.completeMessage();
                }
            }

            if(not result)
            {
                break;
            }

            if(SbeFifoRespBuffer::MSG_COMPLETE != fifoBuffer.getState())
            {
                TS_FAIL("sbeFifoBufferTest testGetSbeFFDC: "
                        "Buffer unexpectedly not in the complete state after "
                        "populating buffer. State = %s.",
                        fifoBuffer.getStateString()
                       );

                result = false;
                break;
            }

            if(not fifoBuffer.isMsgComplete())
            {
                TS_FAIL("sbeFifoBufferTest testGetSbeFFDC: "
                        "unexpectedly returned false for isMsgComplete"
                       );

                result = false;
                break;
            }

            if(not fifoBuffer.getStatus())
            {
                TS_FAIL("sbeFifoBufferTest testGetSbeFFDC: "
                        "unexpectedly returned false for getStatus"
                       );

                result = false;
                break;
            }

            expected_data expData;
            memset(&expData, 0, sizeof(expData));

            expData.test_name = "GetSbeFFDC";
            expData.index = 13;
            expData.offset_index = 11;
            expData.offset = 3;

            expData.statusIndex = 9;
            expData.expected_status = &bufferGetSbeFFDC[9];

            // NOTE: FFDC is in the return data for get SBE FFDC response.
            expData.expectFFDC = true;
            expData.ffdcIndex = 0;
            expData.ffdcByteSize = sizeof(uint32_t)*9;
            expData.expected_ffdc_data = &bufferGetSbeFFDC[0];

            expData.expectReturnData = true;
            expData.dataByteSize = sizeof(uint32_t) * 9;
            expData.expected_data = &bufferGetSbeFFDC[0];

            bool check_result = runChecks(expData, fifoBuffer);

            if(not check_result)
            {
                TS_FAIL("%s", expData.strMessage);

                result = false;
                break;
            }
        }
        while(0);

        if(result)
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testGetSbeFFDC test passed!");
        }
        else
        {
            SBE_BUFFER_TRACD("sbeFifoBufferTest testGetSbeFFDC test failed!");
        }
    }

private:

    std::vector<uint32_t>* iv_testData{};
    std::vector<uint32_t>::const_iterator iv_itr;

    //--------------------------------------------------------
    void setTestData(std::vector<uint32_t>* i_testData)
    {
        iv_testData = i_testData;
        resetTestData();
    }

    //---------------------------------------------------------
    void resetTestData()
    {
        if(iv_testData)
        {
            iv_itr = iv_testData->begin();
        }
    }

    //---------------------------------------------------------
    bool readTestData(uint32_t& value)
    {
        bool retval{false};
        if(iv_testData)
        {
            if(iv_itr != iv_testData->end())
            {
                value = *iv_itr;
                ++iv_itr;
                retval = true;
            }
        }

        return retval;
    }

    //------------------------------------------------------------------
    bool runChecks(expected_data& expData,
                                    SbeFifoRespBufferTestFixture& fifoBuffer)
    {

        bool result{true};

        do
        {
            if(expData.index != fifoBuffer.index())
            {
                snprintf(expData.strMessage,
                         sizeof(expData.strMessage),
                        "%s next insertion index not at %d as expected. Index = %d",
                         expData.test_name,
                         expData.index,
                         fifoBuffer.index()
                       );

                result = false;
                break;
            }

            if(expData.offset_index != fifoBuffer.offsetIndex())
            {
                snprintf(expData.strMessage,
                         sizeof(expData.strMessage),
                        "%s: offset index not at %d as expected. "
                        "Offset index = %d",
                        expData.test_name,
                        expData.offset_index,
                        fifoBuffer.offsetIndex()
                       );

                result = false;
                break;
            }

            if(expData.offset != fifoBuffer.offset())
            {
                snprintf(expData.strMessage,
                         sizeof(expData.strMessage),
                         "%s: "
                         "The offset to the status header is not %d as expected. Buffer Offset: %d",
                         expData.test_name,
                         expData.offset,
                         fifoBuffer.offset());

                result = false;
                break;
            }

            if(expData.statusIndex != fifoBuffer.statusIndex())
            {
                snprintf(expData.strMessage,
                         sizeof(expData.strMessage),
                         "%s: status index not at %d as expected. "
                        "Status index = %d",
                         expData.test_name,
                         expData.statusIndex,
                         fifoBuffer.statusIndex()
                       );

                result = false;
                break;
            }

            auto status_hdr = fifoBuffer.getStatusHeader();
            if(memcmp(expData.expected_status, &status_hdr,
                                    sizeof(SbeFifo::statusHeader)) != 0)
            {
                char expected_xxd[128];
                char actual_xxd[128];

                xxdPrint(&status_hdr,
                         sizeof(SbeFifo::statusHeader),
                         actual_xxd);

                xxdPrint(expData.expected_status,
                         sizeof(SbeFifo::statusHeader),
                         expected_xxd);

                snprintf(expData.strMessage,
                         sizeof(expData.strMessage),
                         "%s: "
                         "Buffer StatusHeader not as expected.\n"
                         "Status data: \n%s\n"
                         "Expected data: \n%s",
                         expData.test_name,
                         actual_xxd,
                         expected_xxd
                        );

                result = false;
                break;
            }

            if(expData.expectFFDC)
            {
                 if(expData.ffdcIndex != fifoBuffer.ffdcIndex())
                 {
                     snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "ffdc index not at %d as expected. ffdc index %d",
                            expData.test_name,
                            expData.ffdcIndex,
                            fifoBuffer.ffdcIndex()
                            );

                     result = false;
                     break;
                 }

                if(not fifoBuffer.msgContainsFFDC())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "msgContainsFFDC incorrectly returned false",
                            expData.test_name
                            );

                    result = false;
                    break;
                }

                std::vector<uint8_t> ffdc;
                fifoBuffer.getFFDCData(ffdc);

                if(ffdc.empty())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "getFFDCPtr unexpectedly returned nothing.",
                             expData.test_name
                            );

                    result = false;
                    break;
                }

                if(expData.ffdcByteSize != fifoBuffer.getFFDCByteSize())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "Buffer FFDC byte size %d not as expected %d",
                             expData.test_name,
                             fifoBuffer.getFFDCByteSize(),
                             expData.ffdcByteSize
                            );

                    result = false;
                    break;
                }

                if(expData.ffdcByteSize/sizeof(uint32_t) !=
                                                fifoBuffer.getFFDCWordSize())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "Buffer FFDC word size %d not as expected %d",
                             expData.test_name,
                             fifoBuffer.getFFDCWordSize(),
                             expData.ffdcByteSize/sizeof(uint32_t)
                            );

                    result = false;
                    break;
                }

                if(memcmp(ffdc.data(),
                       expData.expected_ffdc_data, expData.ffdcByteSize) != 0)
                {
                    char expected_xxd[128];
                    char ffdc_xxd[128];

                    xxdPrint(ffdc.data(),
                             expData.ffdcByteSize,
                             ffdc_xxd);

                    xxdPrint(expData.expected_ffdc_data,
                             expData.ffdcByteSize,
                             expected_xxd);

                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                             "%s: "
                             "Buffer FFDC data not as expected.\n"
                             "FFDC data: \n%s\n"
                             "Expected data: \n%s",
                             expData.test_name,
                             ffdc_xxd,
                             expected_xxd
                            );

                    result = false;
                    break;
                }
            }
            else
            {
                if(SbeFifoRespBuffer::INVALID_INDEX != fifoBuffer.ffdcIndex())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "ffdc index not INVALID_INDEX as expected. "
                            "ffdc index = 0x%08X",
                             expData.test_name,
                             fifoBuffer.ffdcIndex()
                           );

                    result = false;
                    break;
                }

                if(fifoBuffer.msgContainsFFDC())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "msgContainsFFDC incorrectly returned true",
                            expData.test_name
                            );

                    result = false;
                    break;
                }

                std::vector<uint8_t> ffdc;
                fifoBuffer.getFFDCData(ffdc);

                if(!ffdc.empty())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "getFFDCPtr unexpectedly returned data.",
                             expData.test_name
                            );

                    result = false;
                    break;
                }

                if(fifoBuffer.getFFDCByteSize() > 0)
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "getFFDCByteSize unexpectedly returned a "
                            "non zero value: 0x%08X",
                            expData.test_name,
                            fifoBuffer.getFFDCByteSize()
                            );

                    result = false;
                    break;
                }

                if(fifoBuffer.getFFDCWordSize() > 0)
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "getFFDCWordSize unexpectedly returned a "
                            "non zero value: 0x%08X",
                            expData.test_name,
                            fifoBuffer.getFFDCWordSize()
                            );

                    result = false;
                    break;
                }
            }

            if(expData.expectReturnData)
            {
                if(not fifoBuffer.msgContainsReturnData())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "msgContainsReturnData incorrectly returned false",
                            expData.test_name
                            );

                    result = false;
                    break;
                }

                std::vector<uint8_t> return_data;
                fifoBuffer.getReturnData(return_data);

                if(not return_data.data())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "getReturnData unexpectedly returned a nullptr.",
                             expData.test_name
                            );

                    result = false;
                    break;
                }

                if(expData.dataByteSize != fifoBuffer.getReturnDataByteSize())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: "
                            "Buffer return data size %d not as expected %d",
                             expData.test_name,
                             fifoBuffer.getReturnDataByteSize(),
                             expData.dataByteSize
                            );

                    result = false;
                    break;
                }

                if(expData.dataByteSize/sizeof(uint32_t) !=
                                           fifoBuffer.getReturnDataWordSize())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                            "%s: Buffer Return data word size "
                            "%d not as expected %d",
                             expData.test_name,
                             fifoBuffer.getReturnDataWordSize(),
                             expData.dataByteSize/sizeof(uint32_t)
                            );

                    result = false;
                    break;
                }

                if(memcmp(return_data.data(),
                          expData.expected_data, expData.dataByteSize) != 0)
                {
                    char expected_xxd[128];
                    char data_xxd[128];

                    xxdPrint(return_data.data(),
                             expData.dataByteSize,
                             data_xxd);

                    xxdPrint(expData.expected_data,
                             expData.dataByteSize,
                             expected_xxd);

                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                             "%s: "
                             "Buffer Return data not as expected.\n"
                             "Return data: \n%s\n"
                             "Expected data: \n%s",
                             expData.test_name,
                             data_xxd,
                             expected_xxd
                            );

                    result = false;
                    break;
                }
            }
            else
            {
                if(fifoBuffer.msgContainsReturnData())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                             "%s: "
                             "msgContainsReturnData incorrectly returned true",
                             expData.test_name
                             );

                    result = false;
                    break;
                }

                std::vector<uint8_t> return_data;
                fifoBuffer.getReturnData(return_data);

                if(return_data.data())
                {
                    snprintf(expData.strMessage,
                             sizeof(expData.strMessage),
                             "%s: getReturnData unexpectedly "
                             "returned a non-nullptr.",
                             expData.test_name
                            );

                    result = false;
                    break;
                }

                if(fifoBuffer.getReturnDataByteSize() > 0)
                {
                    snprintf(expData.strMessage,
                            sizeof(expData.strMessage),
                            "%s: "
                            "getReturnDataByteSize unexpectedly returned a "
                            "non zero value: 0x%08X",
                            expData.test_name,
                            fifoBuffer.getReturnDataByteSize()
                            );

                    result = false;
                    break;
                }

                if(fifoBuffer.getReturnDataWordSize() > 0)
                {
                    snprintf(expData.strMessage,
                            sizeof(expData.strMessage),
                            "%s: "
                            "getReturnDataWordSize unexpectedly returned a "
                            "non zero value: 0x%08X",
                            expData.test_name,
                            fifoBuffer.getReturnDataWordSize()
                            );

                    result = false;
                    break;
                }
            }
        }
        while(0);

       return result;
    }

};

#endif
