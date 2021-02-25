/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/test/tpmLogMgrTest.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#ifndef __TPMLOGMGRTEST_H
#define __TPMLOGMGRTEST_H

/**
 *  @file tpmLogMgrTest.H
 *
 *  @brief Test cases for the tpm log manager
 */

#include <sys/time.h>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include "../trustedTypes.H"
#include "../tpmLogMgr.H"


using namespace TRUSTEDBOOT;


class TPMLogMgrTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief Retrieve a Tpm log manager to test with
         */
        void getTestLogMgr(TpmLogMgr* logMgr)
        {

            errlHndl_t err = TpmLogMgr_initialize(logMgr);
            if( NULL != err )
            {
                TS_FAIL( "getTestLogMgr - Error detected" );
                errlCommit( err, TRBOOT_COMP_ID );
                delete err;
                err = NULL;
            }
            else if (TpmLogMgr_getLogSize(logMgr) != 73)
                // 73 is size of header entry
            {
                TS_FAIL( "getTestLogMgr - Failed to find "
                         "proper header log Len=%d",
                         TpmLogMgr_getLogSize(logMgr));
            }
            else
            {
                TRACUCOMP(g_trac_trustedboot, "getTestLogMgr - "
                          "Allocate returned as expected. Len=%d",
                          TpmLogMgr_getLogSize(logMgr));
            }
        }

        /**
         * @brief TPM Log Allocate Test
         */
        void testTPMLogMgrAllocate ( void )
        {
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            TCG_PCR_EVENT2 log;
            uint32_t totalLogSize = 0;

            TRACFCOMP( g_trac_trustedboot,
                       "testTPMLogMgrAllocate - Start" );

            do
            {
                // Initialize logMgr
                TpmLogMgr logMgr;
                getTestLogMgr(&logMgr);

                // Bump full size by the header
                totalLogSize = TpmLogMgr_getLogSize(&logMgr);

                for (size_t idx = 0; idx < 10; idx ++)
                {

                    // Build up and add an event to the log
                    memset(&log, 0, sizeof(log));
                    log.pcrIndex = 0xF1F2F300 + idx;
                    log.eventType = 0xE1E2E3E4;

                    log.digests.count=1;

                    uint32_t digestSize = TPM_ALG_SHA256_SIZE;
                    log.digests.digests[0].algorithmId = TPM_ALG_SHA256;

                    num_ops++;
                    if (TPMT_HA_marshalSize(&(log.digests.digests[0])) !=
                        (digestSize + sizeof(uint16_t)))
                    {
                        fails++;
                        TS_FAIL( "testTPMLogMgrAllocate(%d) - Invalid digest "
                                 "size Act=%d Exp=%d",
                                 TPMT_HA_marshalSize(&(log.digests.digests[0])),
                                 idx,
                                 (digestSize + sizeof(uint16_t)));
                        break;
                    }

                    memset(&(log.digests.digests[0].digest),
                           0x51+idx, digestSize);

                    log.event.eventSize = 21+idx;
                    memset(log.event.event, 0x31+idx, log.event.eventSize);

                    // Full log size dependent on algorithm used
                    uint32_t logSize = (sizeof(uint32_t) * 2) +
                        sizeof(uint32_t) +
                        sizeof(uint16_t) + TPM_ALG_SHA256_SIZE +
                        sizeof(uint32_t) + 21 + idx;
                    totalLogSize += logSize;

                    num_ops++;
                    if (TCG_PCR_EVENT2_marshalSize(&log) != logSize)
                    {
                        fails++;
                        TS_FAIL( "testTPMLogMgrAllocate(%d) - "
                                 "Invalid final log size "
                                 "Act=%d Exp=%d",
                                 idx, TCG_PCR_EVENT2_marshalSize(&log),
                                 logSize);
                        break;
                    }

                    // Ok, finally add this to the TPM log
                    err = TpmLogMgr_addEvent(&logMgr,&log);
                    num_ops ++;
                    if( NULL != err )
                    {
                        fails++;
                        TS_FAIL( "testTPMLogMgrAllocate(%d) - "
                                 "Error detected adding event", idx);
                        errlCommit( err,
                                    TRBOOT_COMP_ID );
                        delete err;
                        err = NULL;
                        break;
                    }
                    else if (TpmLogMgr_getLogSize(&logMgr) != totalLogSize)
                    {
                        fails++;
                        TS_FAIL( "testTPMLogMgrAllocate(%d) - Failed to find "
                                 "log ActLen=%d ExpLen=%d",
                                 idx,
                                 TpmLogMgr_getLogSize(&logMgr),
                                 totalLogSize);
                        break;

                    }
                    else
                    {
                        TRACUCOMP(g_trac_trustedboot,
                                  "testTPMLogMgrAllocate(%d) "
                                  "- Addevent returned as expected. "
                                  "Len=%d",
                                  idx,
                                  TpmLogMgr_getLogSize(&logMgr));
                    }

                } // End for

                // Lastly dump the log to a trace so we can review it
                TpmLogMgr_dumpLog(&logMgr);

            } while( 0 );
            TRACFCOMP( g_trac_trustedboot,
                       "testTPMLogMgrAllocate - End: %d/%d fails",
                       fails, num_ops );
        }

        /**
         * @brief Add generic test event to log and return the event added
         */
        TCG_PCR_EVENT2 addTestLogEvent(TpmLogMgr& i_logMgr,
                                       const uint8_t* i_logMsg,
                                       size_t i_logMsgSize)
        {
            // Set components of TCG_PCR_EVENT2
            TPM_Pcr pcr = PCR_0;
            TPM_Alg_Id algId = TPM_ALG_SHA256;
            size_t digestSize = TPM_ALG_SHA256_SIZE;
            uint8_t digest[digestSize];
            for (size_t idx = 0; idx < digestSize; idx++)
            {
                digest[idx] = idx+1;
            }

            // Get a TCG_PCR_EVENT2
            TCG_PCR_EVENT2 eventLog = TpmLogMgr_genLogEventPcrExtend(
                                        pcr, EV_NO_ACTION, algId,
                                        digest, digestSize,
                                        TPM_ALG_INVALID_ID, nullptr,
                                        0, i_logMsg,
                                        i_logMsgSize);

            // Add event to log
            errlHndl_t err = TpmLogMgr_addEvent(&i_logMgr, &eventLog);
            if (err)
            {
                TS_FAIL("addTestLogEvent - Failed to addEvent with the following message");
                TRACFBIN(g_trac_trustedboot,
                         "TPM log message",
                         i_logMsg,
                         i_logMsgSize);
                errlCommit( err, TRBOOT_COMP_ID );
                delete err;
                err = NULL;
            }

            return eventLog;
        }

        /**
         * @brief TPM Log read single entry test
         */
        void testTpmLogReadSingleEntry ( void )
        {
            TRACFCOMP( g_trac_trustedboot, "testTpmLogReadSingleEntry - Start" );

            do {
                // Initialize logMgr
                TpmLogMgr logMgr;
                getTestLogMgr(&logMgr);

                // Add event to log
                uint8_t logMsg[] = "testTpmLogReadSingleEntry";
                TCG_PCR_EVENT2 eventLog = addTestLogEvent(logMgr,
                                                          logMsg,
                                                          sizeof(logMsg));

                // Retrive event from log
                TCG_PCR_EVENT2 resultEventLog;
                const uint8_t* eventHndl = TpmLogMgr_getFirstEvent(&logMgr);
                if (eventHndl == NULL)
                {
                    TS_FAIL( "testTpmLogReadSingleEntry - Log only contains header event" );
                    break;
                }
                bool unMarshalError = false;
                eventHndl = TpmLogMgr_getNextEvent(&logMgr, eventHndl,
                                                   &resultEventLog,
                                                   &unMarshalError);
                if (unMarshalError)
                {
                    TS_FAIL( "testTpmLogReadSingleEntry - LogUnmarshall failed");
                    break;
                }
                // Ensure getNextEvent returned NULL as there is only one entry
                if (eventHndl != NULL)
                {
                    TS_FAIL( "testTpmLogReadSingleEntry - Unexpected entries in eventLog");
                    break;
                }

                // Ensure == operator is correct
                if (memcmp(&eventLog, &resultEventLog, sizeof(TCG_PCR_EVENT2))
                    != 0)
                {
                    TS_FAIL( "testTpmLogReadSingleEntry - ==operator failed to compare events");
                    break;
                }

                // Ensure what we read out matches what we put in
                if ( eventLog == resultEventLog )
                {
                    TRACFCOMP( g_trac_trustedboot, "testTpmLogReadSingleEntry - Success read Event");
                }
                else
                {
                    TS_FAIL( "testTpmLogReadSingleEntry - Failed to read Event");
                    break;
                }

            } while(0);

            TRACFCOMP( g_trac_trustedboot, "testTpmLogReadSingleEntry - End" );
        }

        /**
         * @brief TPM Log read empty log
         */
        void testTpmLogReadEmptyLog ( void )
        {
            TRACFCOMP( g_trac_trustedboot, "testTpmLogReadEmptyLog - Start" );

            do {
                // Initialize logMgr
                TpmLogMgr logMgr;
                getTestLogMgr(&logMgr);

                // Ensure there is only a header event in the log
                if (TpmLogMgr_getFirstEvent(&logMgr) != NULL)
                {
                    TS_FAIL( "testTpmLogReadEmptyLog - Read past actual eventLog");
                    break;
                }
            }
            while (0);
        }

        /**
         * @brief TPM Log read past valid log test
         */
        void testTpmLogReadPastValidLog ( void )
        {
            TRACFCOMP( g_trac_trustedboot, "testTpmLogReadPastValidLog - Start" );

            do {
                // Initialize logMgr
                TpmLogMgr logMgr;
                getTestLogMgr(&logMgr);

                // Add event to log
                uint8_t logMsg[] = "testTpmLogReadPastValidLog";
                addTestLogEvent(logMgr, logMsg, sizeof(logMsg));

                // Retrive event from log
                TCG_PCR_EVENT2 resultEventLog;
                const uint8_t* eventHndl = TpmLogMgr_getFirstEvent(&logMgr);
                if (eventHndl == NULL)
                {
                    TS_FAIL( "testTpmLogReadPastValidLog - Log only contains header event" );
                    break;
                }

                // Try reading past a valid log
                bool unMarshalError = false;
                for (int i = 0; i < 2; ++i)
                {
                    eventHndl = TpmLogMgr_getNextEvent(&logMgr, eventHndl,
                                                       &resultEventLog,
                                                       &unMarshalError);
                    if (i == 0 && unMarshalError)
                    {
                        TS_FAIL( "testTpmLogReadPastValidLog - LogUnmarshall failed");
                        break;
                    }
                    if (i == 1 && (eventHndl != NULL || !unMarshalError ) )
                    {
                        TS_FAIL( "testTpmLogReadPastValidLog - Read past actual eventLog without posting error and returning NULL");
                    }
                }
            }
            while (0);
        }


        /**
         * @brief TPM Log calcLogSize tests
         */
        void testTpmLogCalcLogSize ( void )
        {
            TRACFCOMP( g_trac_trustedboot, "testTpmLogCalcLogSize - Start" );

            do {
                // Initialize logMgr
                TpmLogMgr logMgr;
                getTestLogMgr(&logMgr);

                size_t firstEventSize = TpmLogMgr_getLogSize(&logMgr);

                // No events beyond initial one
                if ((TpmLogMgr_calcLogSize(&logMgr) !=
                     TpmLogMgr_getLogSize(&logMgr)))
                {
                    TS_FAIL( "testTpmLogCalcLogSize - "
                             "Invalid first event calc LS(%d) CS(%d)",
                             TpmLogMgr_getLogSize(&logMgr),
                             TpmLogMgr_calcLogSize(&logMgr));
                    break;
                }

                uint8_t logMsg[] = "CalcLog11";
                // Add an event to log
                TCG_PCR_EVENT2 eventLog = addTestLogEvent(logMgr,
                                                          logMsg,
                                                          sizeof(logMsg));
                if (TpmLogMgr_calcLogSize(&logMgr) !=
                    TpmLogMgr_getLogSize(&logMgr) ||
                    ((firstEventSize +
                      TCG_PCR_EVENT2_marshalSize(&eventLog))
                     != TpmLogMgr_getLogSize(&logMgr)) )
                {
                    TS_FAIL( "testTpmLogCalcLogSize - "
                             "Invalid second event calc LS(%d) CS(%d)",
                             TpmLogMgr_getLogSize(&logMgr),
                             TpmLogMgr_calcLogSize(&logMgr));
                    break;
                }

                uint8_t logMsg1[] = "CalcLog3434";
                // Add more events to log
                for (int idx = 0; idx < 10; idx ++)
                {
                    eventLog = addTestLogEvent(logMgr,
                                               logMsg1,
                                               sizeof(logMsg1));
                    if (TpmLogMgr_calcLogSize(&logMgr) !=
                        TpmLogMgr_getLogSize(&logMgr))
                    {
                        TS_FAIL( "testTpmLogCalcLogSize - IDX (%d) "
                                 "Invalid additional event calc LS(%d) CS(%d)",
                                 idx,
                                 TpmLogMgr_getLogSize(&logMgr),
                                 TpmLogMgr_calcLogSize(&logMgr));
                        break;
                    }
                }
            }
            while (0);
        }

        /**
         * @brief TPM Log initializeUsingExistingLog tests
         */
        void testTpmLogInitExisting ( void )
        {
            TRACFCOMP( g_trac_trustedboot, "testTpmLogInitExisting - Start" );
            errlHndl_t err = NULL;
            TCG_PCR_EVENT2 eventLog;

            do {
                // Initialize logMgr
                TpmLogMgr logMgr;
                getTestLogMgr(&logMgr);
                // Create a logMgr clone
                TpmLogMgr cloneMgr;

                err = TpmLogMgr_initializeUsingExistingLog(&cloneMgr,
                                           TpmLogMgr_getLogStartPtr(&logMgr),
                                           logMgr.logMaxSize);

                // No events beyond initial one
                if (NULL != err ||
                    TpmLogMgr_getLogSize(&logMgr) !=
                    TpmLogMgr_getLogSize(&cloneMgr))
                {
                    TS_FAIL( "testTpmLogInitExisting - "
                             "test fail on initial init "
                             "err(%d) LMS(%d) CLS(%d)",
                             (NULL == err) ? 0 : 1,
                             TpmLogMgr_getLogSize(&logMgr),
                             TpmLogMgr_getLogSize(&cloneMgr));
                    break;
                }


                uint8_t logMsg[] = "CalcLog3434";
                // Add more events to log
                for (int idx = 0; idx < 10; idx ++)
                {
                    eventLog = addTestLogEvent(logMgr,
                                               logMsg,
                                               sizeof(logMsg));
                }

                err = TpmLogMgr_initializeUsingExistingLog(&cloneMgr,
                                           TpmLogMgr_getLogStartPtr(&logMgr),
                                           logMgr.logMaxSize);

                if (NULL != err ||
                    TpmLogMgr_getLogSize(&logMgr) !=
                    TpmLogMgr_getLogSize(&cloneMgr))
                {
                    TS_FAIL( "testTpmLogInitExisting - "
                             "test fail on multiple log init "
                             "err(%d) LMS(%d) CLS(%d)",
                             (NULL == err) ? 0 : 1,
                             TpmLogMgr_getLogSize(&logMgr),
                             TpmLogMgr_getLogSize(&cloneMgr));
                    break;
                }

                uint8_t logMsg1[] = "Clone123 23434";
                // Now try adding an event to the clone logMgr
                eventLog = addTestLogEvent(cloneMgr, logMsg1, sizeof(logMsg1));
                if (TpmLogMgr_getLogSize(&logMgr) ==
                    TpmLogMgr_getLogSize(&cloneMgr))
                {
                    TS_FAIL( "testTpmLogInitExisting - "
                             "test fail on addlog to clone"
                             "LMS(%d) CLS(%d)",
                             TpmLogMgr_getLogSize(&logMgr),
                             TpmLogMgr_getLogSize(&cloneMgr));
                    break;
                }
            }
            while (0);
            TRACFCOMP( g_trac_trustedboot, "testTpmLogInitExisting - End" );
        }

        /**
         * @brief TPM Log initializeUsingExistingLog failing tests
         */
        void testTpmLogInitExistingFails ( void )
        {
            TRACFCOMP( g_trac_trustedboot,
                       "testTpmLogInitExistingFails - Start" );
            errlHndl_t err = NULL;

            do {
                // Initialize logMgr
                TpmLogMgr logMgr;
                getTestLogMgr(&logMgr);
                // Create a logMgr clone
                TpmLogMgr cloneMgr;
                uint8_t logBuffer[256];

                // Zero'd buffer without initial header entry
                memset(logBuffer,0, sizeof(logBuffer));
                err = TpmLogMgr_initializeUsingExistingLog(&cloneMgr,
                                                           logBuffer,
                                                           sizeof(logBuffer));

                if (NULL == err)
                {
                    TS_FAIL( "testTpmLogInitExistingFails - "
                             "test fail on initial init "
                             "err(%d) LMS(%d) CLS(%d)",
                             (NULL == err) ? 0 : 1,
                             TpmLogMgr_getLogSize(&logMgr),
                             TpmLogMgr_getLogSize(&cloneMgr));
                    break;
                }
                else
                {
                    delete err;
                    err = NULL;
                }


                // Buffer too small
                err = TpmLogMgr_initializeUsingExistingLog(&cloneMgr,
                                           TpmLogMgr_getLogStartPtr(&logMgr),
                                           10);
                if (NULL == err)
                {
                    TS_FAIL( "testTpmLogInitExistingFails - "
                             "test fail on initial init buff too small"
                             "err(%d) LMS(%d) CLS(%d)",
                             (NULL == err) ? 0 : 1,
                             TpmLogMgr_getLogSize(&logMgr),
                             TpmLogMgr_getLogSize(&cloneMgr));
                    break;
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            }
            while (0);
            TRACFCOMP( g_trac_trustedboot,
                       "testTpmLogInitExistingFails - End" );
        }

};

#endif
