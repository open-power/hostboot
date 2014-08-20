/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/hwpDQCompressionTest.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef _HWPDQCOMPRESSIONTEST_H
#define _HWPDQCOMPRESSIONTEST_H

/**
 *  @file hwpDQCompressionTest.H
 *
 *  @brief Tests for DQ and DQS compression and decompression
 *
 */

#include <cxxtest/TestSuite.H>
#include <hwpf/hwp/mvpd_accessors/DQCompressionLib.H>
#include "../hwp/mvpd_accessors/compressionTool/DQCompressionReasonCodes.H"
#include "../hwp/mvpd_accessors/compressionTool/DQCompressionConsts.H"
#include <hwpf/hwp/mvpd_accessors/getDecompressedISDIMMAttrs.H>

#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>

using namespace TARGETING;
using namespace DQCompression;

class HwpDQCompressionTest: public CxxTest::TestSuite
{
public:
    void testDQCompression1()
    {
        int l_errl = NO_ERR;
        do
        {
                TRACFCOMP(g_trac_targeting, "Starting DQ Test 1");
                //Input DQ array
                uint8_t l_isdimmToC4DQ_P0 [DQarray_size]={8,9,10,11,12,13,14,15,
                                                      0,1,2,3,4,5,6,7,
                                                      16,17,18,19,20,21,22,23,
                                                      64,65,66,67,68,69,70,71,
                                                      32,33,34,35,36,37,38,39,
                                                      40,41,42,43,44,45,46,47,
                                                      48,49,50,51,52,53,54,55,
                                                      56,57,58,59,60,61,62,63,
                                                      24,25,26,27,28,29,30,31,
                                                      255,255,255,255,255,255,
                                                      255,255};

                //convert array to a vector
                std::vector<uint8_t> l_isdimmToC4DQ_0 (l_isdimmToC4DQ_P0,
                            l_isdimmToC4DQ_P0+(sizeof(l_isdimmToC4DQ_P0)/
                            sizeof(uint8_t)));

                //Pass the vector to the encode function
                ecmdDataBufferBase l_encodedDQData;
                l_errl = encodeDQ(l_isdimmToC4DQ_0, DQ, l_encodedDQData);

                if (l_errl)
                {
                    TS_FAIL("Error Encoding DQ Data set1 %s",
                                    ReasonCodes[l_errl]);
                    break;
                }

                //Input DQS Array
                uint8_t l_isdimmToC4DQS_P0 [DQSarray_size]= {2,3,0,1,
                                                        4,5,16,17,
                                                        8,9,10,11,
                                                        12,13,14,15,
                                                        6,7,255,255};
                //Convert DQS array to a vector
                std::vector<uint8_t> l_isdimmToC4DQS_0 (l_isdimmToC4DQS_P0,
                            l_isdimmToC4DQS_P0+(sizeof(l_isdimmToC4DQS_P0)/
                            sizeof(uint8_t)));

                //encode
                ecmdDataBufferBase l_encodedDQSData;
                l_errl = encodeDQ(l_isdimmToC4DQS_0, DQS, l_encodedDQSData);
                if (l_errl)
                {
                    TS_FAIL("Error Encoding DQS Data1 %s",
                                    ReasonCodes[l_errl]);
                    break;
                }

                //Pass the output to decode
                uint8_t l_decDQArray [DQarray_size];
                uint8_t l_decDQSArray[DQSarray_size];
                decodeISDIMMAttrs(l_encodedDQData, l_encodedDQSData,
                                l_decDQArray, l_decDQSArray);

                //Check if the initial vector is obtained.
                //If not, throw an error
                //First, check DQ
                for (uint8_t i = 0; i < DQarray_size; i++)
                {
                    if(l_decDQArray[i] != l_isdimmToC4DQ_P0[i])
                    {
                        TS_FAIL("Decoded Output differs from initial array DQ test1");
                        break;
                    }
                }

                //Check DQS
                for (uint8_t i = 0; i < DQSarray_size; i++)
                {
                    if(l_decDQSArray[i] != l_isdimmToC4DQS_P0[i])
                    {
                        TS_FAIL("Decoded Output differs from initial array DQS test1");
                        break;
                    }
                }

                TRACFCOMP(g_trac_targeting, "DQ Test 1 ended successfully");
        } while (0);

    }

    void testDQCompression2 ()
    {
        int l_errl = NO_ERR;
        do
        {
              TRACFCOMP(g_trac_targeting, "Starting DQ Test 2");
              uint8_t l_isdimmToC4DQ_P1[DQarray_size]={24,25,26,27,28,29,30,31,
                                                  4,5,6,7,0,1,2,3,
                                                  20,21,22,23,16,17,18,19,
                                                  68,69,70,71,64,65,66,67,
                                                  36,37,38,39,32,33,34,35,
                                                  43,41,42,40,44,45,46,47,
                                                  48,49,50,51,52,53,54,55,
                                                  56,57,58,59,60,61,62,63,
                                                  15,13,14,12,10,9,11,8,
                                                  255,255,255,255,255,255,
                                                  255,255};

                //Convert to a vector
                std::vector<uint8_t> l_isdimmToC4DQ_1 (l_isdimmToC4DQ_P1,
                            l_isdimmToC4DQ_P1+(sizeof(l_isdimmToC4DQ_P1)/
                            sizeof(uint8_t)));

                //Pass the vector to encode function
                ecmdDataBufferBase l_encodedDQData;
                l_errl = encodeDQ(l_isdimmToC4DQ_1, DQ, l_encodedDQData);

                if (l_errl)
                {
                    TS_FAIL("Error Encoding DQ Data2 %s",
                                    ReasonCodes[l_errl]);
                    break;
                }
                uint8_t l_isdimmToC4DQS_P1 [DQSarray_size]= {7,6,1,0,
                                                           4,5,17,16,
                                                           9,8,10,11,
                                                           13,12,14,15,
                                                           2,3,255,255};
                std::vector<uint8_t> l_isdimmToC4DQS_1 (l_isdimmToC4DQS_P1,
                          l_isdimmToC4DQS_P1+(sizeof(l_isdimmToC4DQS_P1)/sizeof
                            (uint8_t)));

                //encode
                ecmdDataBufferBase l_encodedDQSData;
                l_errl = encodeDQ(l_isdimmToC4DQS_1, DQS, l_encodedDQSData);
                if (l_errl)
                {
                    TS_FAIL("Error Encoding DQS Data2 %s",
                                    ReasonCodes[l_errl]);
                    break;
                }

                //Pass the output to decode
                uint8_t l_decDQArray [DQarray_size];
                uint8_t l_decDQSArray[DQSarray_size];
                decodeISDIMMAttrs (l_encodedDQData, l_encodedDQSData,
                                   l_decDQArray, l_decDQSArray);

                //Check if the initial vector is obtained.
                //If not, throw an error
                //First, check DQ
                for (uint8_t i = 0; i < DQarray_size; i++)
                {
                    if(l_decDQArray[i] != l_isdimmToC4DQ_P1[i])
                    {
                        TS_FAIL("Decoded Output differs initial array DQ test2");
                        break;
                    }
                }

                //Check DQS
                for (uint8_t i = 0; i < DQSarray_size; i++)
                {
                    if(l_decDQSArray[i] != l_isdimmToC4DQS_P1[i])
                    {
                        TS_FAIL("Decoded Output differs initial array DQS test2");
                        break;
                    }
                }

                TRACFCOMP(g_trac_targeting, "DQ Test 2 ended successfully");
        } while (0);
    }
};
#endif
