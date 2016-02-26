/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/test/trustedbootTest.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#ifndef __TRUSTEDBOOTTEST_H
#define __TRUSTEDBOOTTEST_H

/**
 *  @file trustedbootTest.H
 *
 *  @brief Test cases for trustedboot
 */

#include <sys/time.h>
#include <cxxtest/TestSuite.H>
#include <targeting/common/commontargeting.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <i2c/tpmddif.H>
#include <secureboot/trustedbootif.H>
#include "../trustedTypes.H"
#include "../trustedboot.H"
#include "../trustedbootCmds.H"

extern trace_desc_t* g_trac_trustedboot;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACUBIN(args...)  TRACFBIN(args)
#define TRACUBIN(args...)


using namespace TRUSTEDBOOT;


class TrustedBootTest: public CxxTest::TestSuite
{
    public:


    /**
     * @brief Helper to run failing marshal tests
     */
    void runTpmMarshalFailTest(TRUSTEDBOOT::TPM2_BaseIn* i_cmd,
                               uint8_t* o_outbuf,
                               size_t i_bufsize,
                               size_t & o_cmdSize,
                               const char* i_testName,
                               int64_t & io_num_ops,
                               int64_t & io_fails)
    {
        errlHndl_t err = NULL;

        err = tpmMarshalCommandData(i_cmd,
                                    o_outbuf,
                                    i_bufsize,
                                    &o_cmdSize);
        io_num_ops++;
        if (NULL == err)
        {
            io_fails++;
            TS_FAIL( "runTpmMarshalFailTest(%s) - Error not detected",
                     i_testName);
        }
        else
        {
            delete err;
            err = NULL;
        }

    }
    /**
     * @brief Helper to run marshal tests
     */
    void runTpmMarshalTest(TRUSTEDBOOT::TPM2_BaseIn* i_cmd,
                           uint8_t* o_outbuf,
                           size_t i_bufsize,
                           size_t & o_cmdSize,
                           const char* i_testName,
                           int64_t & io_num_ops,
                           int64_t & io_fails,
                           size_t i_expSize)
    {
        errlHndl_t err = NULL;
        TRUSTEDBOOT::TPM2_BaseIn* baseCmd =
            reinterpret_cast<TRUSTEDBOOT::TPM2_BaseIn*>(o_outbuf);

        do
        {


            err = tpmMarshalCommandData(i_cmd,
                                        o_outbuf,
                                        i_bufsize,
                                        &o_cmdSize);
            io_num_ops++;
            if (NULL != err)
            {
                io_fails++;
                TS_FAIL( "runTpmMarshalTest(%s) - Error detected", i_testName);
                errlCommit( err,
                            TPMDD_COMP_ID );
                delete err;
                err = NULL;
                break;
            }
            io_num_ops++;
            if (o_cmdSize == 0 ||
                o_cmdSize != baseCmd->commandSize ||
                o_cmdSize != i_expSize)
            {
                io_fails++;
                TS_FAIL( "runTpmMarshalTest(%s) - Size Mismatch "
                         "oC %d aC %d Exp %d",
                         i_testName, o_cmdSize,
                         baseCmd->commandSize, i_expSize);
                break;
            }

            // Try some that should fail
            err = tpmMarshalCommandData(i_cmd,
                                        o_outbuf,
                                        i_expSize-1,
                                        &o_cmdSize);
            io_num_ops++;
            if (NULL == err)
            {
                io_fails++;
                TS_FAIL( "runTpmMarshalTest(%s) - Size-1 error not detected",
                         i_testName);
                break;
            }
            else
            {
                delete err;
                err = NULL;
            }

            err = tpmMarshalCommandData(i_cmd,
                                        o_outbuf,
                                        i_expSize/2,
                                        &o_cmdSize);
            io_num_ops++;
            if (NULL == err)
            {
                io_fails++;
                TS_FAIL( "runTpmMarshalTest(%s) - Size/2 error not detected",
                         i_testName);
                break;
            }
            else
            {
                delete err;
                err = NULL;
            }

            err = tpmMarshalCommandData(i_cmd,
                                        o_outbuf,
                                        i_expSize/3,
                                        &o_cmdSize);
            io_num_ops++;
            if (NULL == err)
            {
                io_fails++;
                TS_FAIL( "runTpmMarshalTest(%s) - Size/3 error not detected",
                         i_testName);
                break;
            }
            else
            {
                delete err;
                err = NULL;
            }

        } while( 0 );
    }


    /**
     * @brief Helper to run failing unmarshal tests
     */
    void runTpmUnmarshalFailTest(uint32_t i_commandCode,
                                 uint8_t* i_respBuf,
                                 size_t i_respBufSize,
                                 TRUSTEDBOOT::TPM2_BaseOut* o_outBuf,
                                 size_t i_outBufSize,
                                 const char* i_testName,
                                 int64_t & io_num_ops,
                                 int64_t & io_fails)
    {
        errlHndl_t err = NULL;

        err = tpmUnmarshalResponseData(i_commandCode,
                                       i_respBuf,
                                       i_respBufSize,
                                       o_outBuf,
                                       i_outBufSize);
        io_num_ops++;
        if (NULL == err)
        {
            io_fails++;
            TS_FAIL( "runTpmUnmarshalFailTest(%s) - Error not detected",
                     i_testName);
        }
        else
        {
            delete err;
            err = NULL;
        }

    }
    /**
     * @brief Helper to run unmarshal tests
     */
    void runTpmUnmarshalTest(uint32_t i_commandCode,
                             uint8_t* i_respBuf,
                             size_t i_respBufSize,
                             TRUSTEDBOOT::TPM2_BaseOut* o_outBuf,
                             size_t i_outBufSize,
                             const char* i_testName,
                             int64_t & io_num_ops,
                             int64_t & io_fails)
    {
        errlHndl_t err = NULL;

        do
        {


            err = tpmUnmarshalResponseData(i_commandCode,
                                           i_respBuf,
                                           i_respBufSize,
                                           o_outBuf,
                                           i_outBufSize);
            io_num_ops++;
            if (NULL != err)
            {
                io_fails++;
                TS_FAIL( "runTpmUnmarshalTest(%s) - Error detected",
                         i_testName);
                errlCommit( err,
                            TPMDD_COMP_ID );
                delete err;
                err = NULL;
                break;
            }

            // Try some that should fail
            err = tpmUnmarshalResponseData(i_commandCode,
                                           i_respBuf,
                                           4,
                                           o_outBuf,
                                           i_outBufSize);
            io_num_ops++;
            if (NULL == err)
            {
                io_fails++;
                TS_FAIL( "runTpmUnmarshalTest(%s) - "
                         "RespBuf Size=4 error not detected",
                         i_testName);
                break;
            }
            else
            {
                delete err;
                err = NULL;
            }

            // If the response output buffer is more then just the base we
            //  can do another failing size verif
            if (i_outBufSize > sizeof(TPM2_BaseOut))
            {
                err = tpmUnmarshalResponseData(i_commandCode,
                                               i_respBuf,
                                               sizeof(TPM2_BaseOut),
                                               o_outBuf,
                                               i_outBufSize);
                io_num_ops++;
                if (NULL == err)
                {
                    io_fails++;
                    TS_FAIL( "runTpmUnmarshalTest(%s) - "
                             "RespBuf Size=10 error not detected",
                             i_testName);
                    break;
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            }

            err = tpmUnmarshalResponseData(i_commandCode,
                                           i_respBuf,
                                           i_respBufSize,
                                           o_outBuf,
                                           4);
            io_num_ops++;
            if (NULL == err)
            {
                io_fails++;
                TS_FAIL( "runTpmUnmarshalTest(%s) - "
                         "OutBuf Size=4 error not detected",
                         i_testName);
                break;
            }
            else
            {
                delete err;
                err = NULL;
            }

            if (i_outBufSize > sizeof(TPM2_BaseOut))
            {
                err = tpmUnmarshalResponseData(i_commandCode,
                                               i_respBuf,
                                               i_respBufSize,
                                               o_outBuf,
                                               sizeof(TPM2_BaseOut));
                io_num_ops++;
                if (NULL == err)
                {
                    io_fails++;
                    TS_FAIL( "runTpmUnmarshalTest(%s) - "
                             "OutBuf Size=10 error not detected",
                             i_testName);
                    break;
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            }

        } while( 0 );
    }


    /**
     * @brief Test command marshaling
     */
    void testCommandMarshal ( void )
    {
        int64_t fails = 0, num_ops = 0;
        uint8_t dataBufIn[BUFSIZE];
        uint8_t dataBufOut[BUFSIZE];
        size_t  cmdSize = 0;
        TRUSTEDBOOT::TPM2_BaseIn* baseCmd =
            reinterpret_cast<TRUSTEDBOOT::TPM2_BaseIn*>(dataBufIn);

        TRACFCOMP( g_trac_trustedboot,
                   "testCommandMarshal - Start" );
        do
        {

            // Unsupported command
            {
                memset(dataBufIn, 0, sizeof(dataBufIn));
                memset(dataBufOut, 0, sizeof(dataBufOut));
                baseCmd->commandCode = 0x12345;

                runTpmMarshalFailTest(baseCmd,
                                      dataBufOut,
                                      sizeof(dataBufOut),
                                      cmdSize,
                                      "Unsupported command",
                                      num_ops,
                                      fails);
            }

            // Test 2ByteIn with Startup command
            {
                memset(dataBufIn, 0, sizeof(dataBufIn));
                memset(dataBufOut, 0, sizeof(dataBufOut));
                TRUSTEDBOOT::TPM2_2ByteIn* cmdPtr =
                    reinterpret_cast<TRUSTEDBOOT::TPM2_2ByteIn*>(dataBufIn);
                cmdPtr->base.commandCode = TRUSTEDBOOT::TPM_CC_Startup;

                runTpmMarshalTest(baseCmd,
                                  dataBufOut,
                                  sizeof(dataBufOut),
                                  cmdSize,
                                  "2ByteIn",
                                  num_ops,
                                  fails,
                                  sizeof(TPM2_2ByteIn));
            }

            // Test GetCapabilityIn
            {
                memset(dataBufIn, 0, sizeof(dataBufIn));
                memset(dataBufOut, 0, sizeof(dataBufOut));
                TRUSTEDBOOT::TPM2_GetCapabilityIn* cmdPtr =
                    reinterpret_cast<TRUSTEDBOOT::TPM2_GetCapabilityIn*>
                    (dataBufIn);
                cmdPtr->base.commandCode = TRUSTEDBOOT::TPM_CC_GetCapability;

                runTpmMarshalTest(baseCmd,
                                  dataBufOut,
                                  sizeof(dataBufOut),
                                  cmdSize,
                                  "GetCapabilityIn",
                                  num_ops,
                                  fails,
                                  sizeof(TPM2_GetCapabilityIn));
            }



        } while( 0 );
        TRACFCOMP( g_trac_trustedboot,
                   "testCommandMarshal - End: %d/%d fails",
                   fails, num_ops );

    }

    /**
     * @brief Test command unmarshaling
     */
    void testCommandUnmarshal ( void )
    {
        int64_t fails = 0, num_ops = 0;
        uint8_t dataBufIn[BUFSIZE];
        uint8_t dataBufOut[BUFSIZE];
        TRUSTEDBOOT::TPM2_BaseOut* baseCmd =
            reinterpret_cast<TRUSTEDBOOT::TPM2_BaseOut*>(dataBufOut);

        TRACFCOMP( g_trac_trustedboot,
                   "testCommandUnmarshal - Start" );
        do
        {

            // Unsupported command
            {
                memset(dataBufIn, 0, sizeof(dataBufIn));
                memset(dataBufOut, 0, sizeof(dataBufOut));

                runTpmUnmarshalFailTest(0x12345,
                                        dataBufIn,
                                        sizeof(dataBufIn),
                                        baseCmd,
                                        sizeof(dataBufOut),
                                        "Unsupported command",
                                        num_ops,
                                        fails);
            }

            // Test BaseOut with Startup command
            {
                memset(dataBufIn, 0, sizeof(dataBufIn));
                memset(dataBufOut, 0, sizeof(dataBufOut));

                runTpmUnmarshalTest(TRUSTEDBOOT::TPM_CC_Startup,
                                    dataBufIn,
                                    sizeof(dataBufIn),
                                    baseCmd,
                                    sizeof(TPM2_BaseOut),
                                    "BaseOut",
                                    num_ops,
                                    fails);
            }

            // Test GetCapabilityOut
            {
                memset(dataBufIn, 0, sizeof(dataBufIn));
                memset(dataBufOut, 0, sizeof(dataBufOut));

                // Test will fail because we haven't set the capability
                runTpmUnmarshalFailTest(TRUSTEDBOOT::TPM_CC_GetCapability,
                                        dataBufIn,
                                        sizeof(dataBufIn),
                                        baseCmd,
                                        sizeof(TPM2_GetCapabilityOut),
                                        "GetCapabilityOut - invalid cap",
                                        num_ops,
                                        fails);

                // Set the capability coming from the TPM
                TRUSTEDBOOT::TPM2_GetCapabilityOut* respPtr =
                    reinterpret_cast<TRUSTEDBOOT::TPM2_GetCapabilityOut*>
                    (dataBufIn);
                respPtr->capData.capability =
                    TRUSTEDBOOT::TPM_CAP_TPM_PROPERTIES;

                runTpmUnmarshalTest(TRUSTEDBOOT::TPM_CC_GetCapability,
                                    dataBufIn,
                                    sizeof(dataBufIn),
                                    baseCmd,
                                    sizeof(TPM2_GetCapabilityOut),
                                    "GetCapabilityOut",
                                    num_ops,
                                    fails);
            }



        } while( 0 );
        TRACFCOMP( g_trac_trustedboot,
                   "testCommandUnmarshal - End: %d/%d fails",
                   fails, num_ops );

    }


};

#endif
