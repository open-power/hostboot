/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/test/tpmLogMgrTest.H $             */
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
#include "../base/tpmLogMgr.H"


using namespace TRUSTEDBOOT;


class TPMLogMgrTest: public CxxTest::TestSuite
{
    public:

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

                TpmLogMgr logMgr;

                num_ops++;
                err = TpmLogMgr_initialize(&logMgr);

                if( NULL != err )
                {
                    fails++;
                    TS_FAIL( "testTPMLogMgrAllocate - Error detected" );
                    errlCommit( err,
                                SECURE_COMP_ID );
                    delete err;
                    err = NULL;
                    break;
                }
                else if (TpmLogMgr_getLogSize(&logMgr) != 69)
                    // 69 is size of header entry
                {
                    fails++;
                    TS_FAIL( "testTPMLogMgrAllocate - Failed to find "
                             "proper header log Len=%d",
                             TpmLogMgr_getLogSize(&logMgr));
                    break;

                }
                else
                {
                    TRACUCOMP(g_trac_trustedboot, "testTPMLogMgrAllocate - "
                              "Allocate returned as expected. Len=%d",
                              TpmLogMgr_getLogSize(&logMgr));
                }
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

                    memset(log.digests.digests[0].digest.bytes,
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
                                    SECURE_COMP_ID );
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


};

#endif
