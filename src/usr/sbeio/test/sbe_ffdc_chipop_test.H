/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_ffdc_chipop_test.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2024                        */
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
#ifndef __SBE_FFDC_CHIPOP_TEST_H
#define __SBE_FFDC_CHIPOP_TEST_H

/**
 *  @file sbe_ffdc_chipop_test.H
 *
 *  @brief Test cases for sbe/hb ffdc package exchange
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sbeio/sbe_utils.H>
#include <sbeio/sbeioif.H>
#include <targeting/odyutil.H>
#include <return_code_defs.H>

#include <hwp_return_codes.H>

#include "sbe_fifodd.H"

using namespace fapi2;
using namespace TARGETING;
using namespace ERRORLOG;
using namespace SBEIO;

namespace SBEIO {
    errlHndl_t sendTestFfdcRequest(TARGETING::Target * i_target,
                                   const SbeFifo::fifoTestFfdcResponseFormat i_format,
                                   const uint16_t i_numRecords,
                                   uint64_t * i_recordsPtr);
};

TargetHandle_t getOdyChip()
{
    TargetHandle_t odysseyChip = nullptr;

    for (auto ocmb : composable(getAllChips)(TYPE_OCMB_CHIP, true))
    {
        if (UTIL::isOdysseyChip(ocmb))
        {
            odysseyChip = ocmb;
            break;
        }
    }

    return odysseyChip;
}

struct sbeFfdcTest
{
    uint32_t rc;
    TargetHandle_t target;
    uint8_t expectations;
};

typedef std::vector<SbeFifo::fifoTestFfdcErrorRecord> errorRecords_t;

class SbeFfdcChipOpTest : public CxxTest::TestSuite
{
private:

    std::array<char, 64> exp_to_str(uint8_t i_expectation)
    {
        std::array<char, 64> str = { };

        do {
            if (i_expectation == ErrlEntry::NO_MATCH)
            {
                strcpy(&str[0], "NO_MATCH");
                break;
            }

            fapi2::each_1bit_mask(i_expectation, [&](const uint64_t bit)
            {
                const auto expectation = static_cast<ErrlEntry::callout_search_criteria>(bit);
                switch (expectation)
                {
                    case ErrlEntry::TARGET_MATCH:
                        strcat(&str[0], "TARGET_MATCH|");
                        break;
                    case ErrlEntry::DECONFIG_FOUND:
                        strcat(&str[0], "DECONFIG_FOUND|");
                        break;
                    case ErrlEntry::GARD_FOUND:
                        strcat(&str[0], "GARD_FOUND|");
                        break;
                    case ErrlEntry::NO_MATCH:
                        break;
                }
                return true; // continue to end
            });
            if (strlen(&str[0]))
            {
                str[strlen(&str[0]) - 1] = '\0'; // chop off the last |
            }
        } while (0);
        return str;
    }

    std::array<char, 64> rc_to_str(uint32_t i_rc)
    {
        std::array<char, 64> str = { };
        switch(i_rc)
        {
            case RC_TEST_DIMM_TARGET0:
                strcpy(&str[0], "RC_TEST_DIMM_TARGET0");
                break;
            case RC_TEST_DIMM_TARGET2:
                strcpy(&str[0], "RC_TEST_DIMM_TARGET2");
                break;
            case RC_TEST_CALLOUT_DIMM_TARGET0:
                strcpy(&str[0], "RC_TEST_CALLOUT_DIMM_TARGET0");
                break;
            case RC_TEST_CALLOUT_DIMM_TARGET2:
                strcpy(&str[0], "RC_TEST_CALLOUT_DIMM_TARGET2");
                break;
            case RC_TEST_CALLOUT_DIMM_DECONFIG_TARGET0:
                strcpy(&str[0], "RC_TEST_CALLOUT_DIMM_DECONFIG_TARGET0");
                break;
            case RC_TEST_CALLOUT_DIMM_DECONFIG_TARGET2:
                strcpy(&str[0], "RC_TEST_CALLOUT_DIMM_DECONFIG_TARGET2");
                break;
            case RC_TEST_CALLOUT_DIMM_GARD_TARGET0:
                strcpy(&str[0], "RC_TEST_CALLOUT_DIMM_GARD_TARGET0");
                break;
            case RC_TEST_CALLOUT_DIMM_GARD_TARGET2:
                strcpy(&str[0], "RC_TEST_CALLOUT_DIMM_GARD_TARGET2");
                break;
            case RC_TEST_CALLOUT_DIMM_DECONFIG_GARD_TARGET0:
                strcpy(&str[0], "RC_TEST_CALLOUT_DIMM_DECONFIG_GARD_TARGET0");
                break;
            case RC_TEST_CALLOUT_DIMM_DECONFIG_GARD_TARGET2:
                strcpy(&str[0], "RC_TEST_CALLOUT_DIMM_DECONFIG_GARD_TARGET2");
                break;
            case RC_TEST_MEMPORT_TARGET0:
                strcpy(&str[0], "RC_TEST_MEMPORT_TARGET0");
                break;
            case RC_TEST_MEMPORT_TARGET1:
                strcpy(&str[0], "RC_TEST_MEMPORT_TARGET1");
                break;
            case RC_TEST_CALLOUT_MEMPORT_TARGET0:
                strcpy(&str[0], "RC_TEST_CALLOUT_MEMPORT_TARGET0");
                break;
            case RC_TEST_CALLOUT_MEMPORT_TARGET1:
                strcpy(&str[0], "RC_TEST_CALLOUT_MEMPORT_TARGET1");
                break;
            case RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_TARGET0:
                strcpy(&str[0], "RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_TARGET0");
                break;
            case RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_TARGET1:
                strcpy(&str[0], "RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_TARGET1");
                break;
            case RC_TEST_CALLOUT_MEMPORT_GARD_TARGET0:
                strcpy(&str[0], "RC_TEST_CALLOUT_MEMPORT_GARD_TARGET0");
                break;
            case RC_TEST_CALLOUT_MEMPORT_GARD_TARGET1:
                strcpy(&str[0], "RC_TEST_CALLOUT_MEMPORT_GARD_TARGET1");
                break;
            case RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_GARD_TARGET0:
                strcpy(&str[0], "RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_GARD_TARGET0");
                break;
            case RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_GARD_TARGET1:
                strcpy(&str[0], "RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_GARD_TARGET1");
                break;
            case RC_TEST_PERV_TARGET1:
                strcpy(&str[0], "RC_TEST_PERV_TARGET1");
                break;
            case RC_TEST_PERV_TARGET8:
                strcpy(&str[0], "RC_TEST_PERV_TARGET8");
                break;
            case RC_TEST_CALLOUT_PERV_TARGET1:
                strcpy(&str[0], "RC_TEST_CALLOUT_PERV_TARGET1");
                break;
            case RC_TEST_CALLOUT_PERV_TARGET8:
                strcpy(&str[0], "RC_TEST_CALLOUT_PERV_TARGET8");
                break;
            case RC_TEST_CALLOUT_PERV_DECONFIGURE_TARGET1:
                strcpy(&str[0], "RC_TEST_CALLOUT_PERV_DECONFIGURE_TARGET1");
                break;
            case RC_TEST_CALLOUT_PERV_DECONFIGURE_TARGET8:
                strcpy(&str[0], "RC_TEST_CALLOUT_PERV_DECONFIGURE_TARGET8");
                break;
            case RC_TEST_CALLOUT_PERV_GARD_TARGET1:
                strcpy(&str[0], "RC_TEST_CALLOUT_PERV_GARD_TARGET1");
                break;
            case RC_TEST_CALLOUT_PERV_GARD_TARGET8:
                strcpy(&str[0], "RC_TEST_CALLOUT_PERV_GARD_TARGET8");
                break;
            case RC_TEST_CALLOUT_PERV_DECONFIGURE_GARD_TARGET1:
                strcpy(&str[0], "RC_TEST_CALLOUT_PERV_DECONFIGURE_GARD_TARGET1");
                break;
            case RC_TEST_CALLOUT_PERV_DECONFIGURE_GARD_TARGET8:
                strcpy(&str[0], "RC_TEST_CALLOUT_PERV_DECONFIGURE_GARD_TARGET8");
                break;
            case RC_TEST_TEMPSENSOR_TARGET0:
                strcpy(&str[0], "RC_TEST_TEMPSENSOR_TARGET0");
                break;
            case RC_TEST_TEMPSENSOR_TARGET1:
                strcpy(&str[0], "RC_TEST_TEMPSENSOR_TARGET1");
                break;
            case RC_TEST_CALLOUT_TEMPSENSOR_TARGET0:
                strcpy(&str[0], "RC_TEST_CALLOUT_TEMPSENSOR_TARGET0");
                break;
            case RC_TEST_CALLOUT_TEMPSENSOR_TARGET1:
                strcpy(&str[0], "RC_TEST_CALLOUT_TEMPSENSOR_TARGET1");
                break;
            case RC_TEST_CALLOUT_OCMB_DECONFIGURE_GARD_TARGET0:
                strcpy(&str[0], "RC_TEST_CALLOUT_OCMB_DECONFIGURE_GARD_TARGET0");
                break;
            default:
                assert(false, "Unsupported RC=0x%08X", i_rc);
                break;
        }
        return str;
    }

    static std::vector<errlHndl_t> flattenAggregate(const errlHndl_t errl)
    {
        if (errl)
        {
            auto agg = errl->aggregated();
            return { begin(agg), end(agg) };
        }
        else
        {
            return { /* empty vector */ };
        }
    }

    size_t countErrorLogs(const errlHndl_t i_errl)
    {
        return flattenAggregate(i_errl).size();
    }

    size_t countErrorLogs(const std::vector<errlHndl_t> i_errls)
    {
        size_t count = 0;

        for (const auto & errl : i_errls)
        {
            count += countErrorLogs(errl);
        }

        return count;
    }

    bool hasErrorType(const char * i_testName,
                        errorRecords_t i_records,
                        errlHndl_t i_error)
    {
        bool retVal = true;
        for (const auto & record : i_records)
        {
            if ( !i_error->hasErrorType(record.returnCode) )
            {
                TS_FAIL("%s> Expected error PLID=0x%X to have error type %s",
                        i_testName,
                        i_error->plid(),
                        rc_to_str(record.returnCode).data());
                retVal = false;
            }
        }
        return retVal;
    }

    void send_and_check_callouts(const sbeFfdcTest & i_test, TargetHandle_t i_chip)
    {
#define TEST_FUNC "send_and_check_callouts: "
        TS_INFO(TEST_FUNC"OCMB[0x%X], test target[0x%X] w/ %s and expectations=%s executing test...",
                get_huid(i_chip),
                get_huid(i_test.target),
                rc_to_str(i_test.rc).data(),
                exp_to_str(i_test.expectations).data());
        // Make error record for RC
        SbeFifo::fifoTestFfdcErrorRecord errRecord(i_test.rc, FAPI2_ERRL_SEV_UNRECOVERABLE, 1/* count */);

        // Send the chipop using FIFO_TEST_SYNC_NON_FATAL_FFDC so the only log returned is the log generated by the RC.
        errlHndl_t err = SBEIO::sendTestFfdcRequest(i_chip,
                                                    SbeFifo::FIFO_TEST_SYNC_NON_FATAL_FFDC,
                                                    1,
                                                    reinterpret_cast<uint64_t *>(&errRecord));
        if (err)
        {
            uint8_t query_results = err->queryCallouts(i_test.target);
            if (query_results == i_test.expectations)
            {
                if (!hasErrorType(TEST_FUNC, { errRecord }, err))
                {
                    goto TEST_FAIL_EXIT;
                }
            }
            else
            {
                TS_FAIL_FN("Callouts for target[0x%X]: %s  didn't match expectations %s",
                        get_huid(i_test.target),
                        exp_to_str(query_results).data(),
                        exp_to_str(i_test.expectations).data());
                goto TEST_FAIL_EXIT;
            }
            delete err;
            err = nullptr;
            TS_INFO(TEST_FUNC"OCMB[0x%X], test target[0x%X] w/ %s and expectations=%s PASSED",
                    get_huid(i_chip),
                    get_huid(i_test.target),
                    rc_to_str(i_test.rc).data(),
                    exp_to_str(i_test.expectations).data());
        }
        else
        {
            TS_FAIL_FN("Did not get an error log back from sendTestFfdcRequest for "
                        "chip[0x%X], test target[0x%X], %s!",
                        get_huid(i_chip),
                        get_huid(i_test.target),
                        rc_to_str(i_test.rc).data());
            goto TEST_FAIL_EXIT;
        }

TEST_FAIL_EXIT:
        if (err)
        {
            errlCommit(err, CXXTEST_COMP_ID);
        }
#undef TEST_FUNC
    }

    void send_and_check_error_record(const char * i_testName,
                                          TargetHandle_t i_chip,
                                          SbeFifo::fifoTestFfdcResponseFormat i_format,
                                          errorRecords_t i_errorRecords,
                                          size_t i_expected_num_chipop_logs,
                                          size_t i_expected_num_getFfdc_logs = 0)
    {
#define TEST_FUNC "send_and_check_error_record:"
        TS_INFO("Executing %s ...",i_testName);

        // At the end of the test, if anything didn't go as expected these error handles will be committed.
        errlHndl_t async_errls = nullptr,
                   chipopErr = SBEIO::sendTestFfdcRequest(i_chip,
                                                          i_format,
                                                          i_errorRecords.size(),
                                                          reinterpret_cast<uint64_t *>(i_errorRecords.data()));

        // Count how many error logs were returned by the request and check if that number was expected by the test.
        size_t errl_count = countErrorLogs(chipopErr);
        if ((errl_count != i_expected_num_chipop_logs))
        {
            TS_FAIL_FN("%s> Expected %d logs returned from chip-op, got %d",
                       i_testName,
                       i_expected_num_chipop_logs,
                       errl_count);
            goto TEST_FAIL_EXIT;
        }

        if (errl_count > 0)
        {
            // This test expected some number of chip-op error logs. Ensure the error type(s) match expectations.
            if (!hasErrorType(i_testName, i_errorRecords, chipopErr))
            {
                goto TEST_FAIL_EXIT;
            }
        }

        // Clean up the chip-op log from this test.
        delete chipopErr;
        chipopErr = nullptr;

        // If this is an async test, call the getFfdc chip-op to check for the expected errors.
        if ((i_format == SbeFifo::FIFO_TEST_ASYNC_NON_FATAL_FFDC) || (i_format == SbeFifo::FIFO_TEST_ASYNC_FATAL_FFDC))
        {
            errlOwner request_errl = genFifoSBEFFDCErrls(i_chip, async_errls);
            if (request_errl)
            {
                TS_FAIL_FN("%s> Unexpected failure when attempting to get async ffdc, committing log ...",
                           i_testName);
                errlCommit(request_errl, CXXTEST_COMP_ID);
                goto TEST_FAIL_EXIT;
            }

            errl_count = countErrorLogs(async_errls);
            if (errl_count != i_expected_num_getFfdc_logs)
            {
                TS_FAIL_FN("%s> Expected %d logs returned from getFfdc chip-op, got %d",
                           i_testName,
                           i_expected_num_getFfdc_logs,
                           errl_count);
                goto TEST_FAIL_EXIT;
            }

            if (errl_count > 0)
            {
                // This test expected some number of chip-op error logs. Ensure the error type(s) match expectations.
                if( !hasErrorType(i_testName, i_errorRecords, async_errls))
                {
                    goto TEST_FAIL_EXIT;
                }
            }
            // Clean up the async log for this test.
            delete async_errls;
            async_errls = nullptr;
        }

TEST_FAIL_EXIT:
        if (!async_errls && !chipopErr)
        {
            TS_INFO("%s> Passed", i_testName);
        }
        if (chipopErr)
        {
            // Commit the log for inspection
            errlCommit(chipopErr, CXXTEST_COMP_ID);
            // If this was an async test that failed then call getFFDC to clear out any leftovers from this test so
            // there aren't side effects in other tests.
            if ((i_format == SbeFifo::FIFO_TEST_ASYNC_NON_FATAL_FFDC) ||
                (i_format == SbeFifo::FIFO_TEST_ASYNC_FATAL_FFDC))
            {
                errlOwner request_errl = genFifoSBEFFDCErrls(i_chip, async_errls);
                if (request_errl)
                {
                    TS_INFO("Unexpected failure when attempting to get async ffdc, committing log ...");
                    errlCommit(request_errl, CXXTEST_COMP_ID);
                }
            }
        }
        if (async_errls)
        {
           errlCommit(async_errls, CXXTEST_COMP_ID);
        }
#undef TEST_FUNC
    }

public:

    void testSyncFfdc()
    {
#define TEST_FUNC "testSyncFfdc:"
        // Tests if Hostboot and the SBE can handle sync FFDC fails. When an sync fail occurs ffdc packages are
        // returned with the response from the chip-op.
        //
        // There are two kinds:
        //   1. Fatal.
        //   2. Non-Fatal.
        // The main difference between the two is how a Hardware Procedure deals with a failure. For fatal, the HWP
        // returns an error back to the SBE. For non-fatal, the HWP would call something like logError() internally and
        // return success back to the SBE. As far as Hostboot is concerned, fatal errors would have the SBE return bad
        // primary/secondary status codes back and non-fatal wouldn't.
        //
        // As a result, this test will check for that difference and opt not to interrogate the specifics of the data
        // returned.

        TARGETING::Target * odyOcmb = getOdyChip();
        if (odyOcmb == nullptr)
        {
            // No Odyssey OCMBs found, abort test.
            TS_INFO(TEST_FUNC"Did NOT find any Odyssey OCMBs to work with, skipping test");
            return;
        }

        // For these tests, the data within the error record is not important. For the count field, just provide 1.
        // We aren't testing for multiple SLIDs, so one is enough.
        errorRecords_t errRecord = { { RC_TEST_DIMM_TARGET0, FAPI2_ERRL_SEV_UNRECOVERABLE, 1/* count */} };

        const size_t expected_nonfatal_errors = 1, // Sync nonfatal fails do not produce a chip-op log
                     expected_fatal_errors = 3;    // Sync fatal fails should produce:
                                                   //  * a chip-op failure log
                                                   //  * a HWP log for the RC
                                                   //  * a PLATFORM_ERROR log with SBE Trace data

        send_and_check_error_record(TEST_FUNC" FIFO_TEST_SYNC_NON_FATAL_FFDC",
                                         odyOcmb,
                                         SbeFifo::FIFO_TEST_SYNC_NON_FATAL_FFDC,
                                         errRecord,
                                         expected_nonfatal_errors);

        send_and_check_error_record(TEST_FUNC" FIFO_TEST_SYNC_FATAL_FFDC",
                                         odyOcmb,
                                         SbeFifo::FIFO_TEST_SYNC_FATAL_FFDC,
                                         errRecord,
                                         expected_fatal_errors);

#undef TEST_FUNC
    }

    void testAsyncFfdc()
    {
#define TEST_FUNC "testAsyncFfdc:"
        // Tests if Hostboot and the SBE can handle async FFDC fails. When an async fail occurs there is no ffdc
        // packages returned with the response from the chip-op. Instead a getFFDC chip-op must be called to retrieve
        // the data.

        TARGETING::Target * odyOcmb = getOdyChip();
        if (odyOcmb == nullptr)
        {
            // No Odyssey OCMBs found, abort test.
            TS_INFO(TEST_FUNC"Did NOT find any Odyssey OCMBs to work with, skipping test");
            return;
        }

        // For these tests, the data within the error record is not important. For the count field, just provide 1.
        // We aren't testing for multiple SLIDs, so one is enough.
        errorRecords_t errRecord = { { RC_TEST_DIMM_TARGET0, FAPI2_ERRL_SEV_UNRECOVERABLE, 1/* count */ } };

        const size_t expected_chipop_errors = 0, // async failures should not produce chip-op fails.
                     expected_async_errors = errRecord.size() + 1; /* Whenever there's a getFFDC request sent to the SBE
                                                                      it will return an extra PLAT RC ffdc package with
                                                                      a different SLID than error record data we'd sent.
                                                                      So, add an extra log to the expected number. */

        send_and_check_error_record(TEST_FUNC" FIFO_TEST_ASYNC_NON_FATAL_FFDC",
                                         odyOcmb,
                                         SbeFifo::FIFO_TEST_ASYNC_NON_FATAL_FFDC,
                                         errRecord,
                                         expected_chipop_errors,
                                         expected_async_errors);

        send_and_check_error_record(TEST_FUNC" FIFO_TEST_ASYNC_FATAL_FFDC",
                                         odyOcmb,
                                         SbeFifo::FIFO_TEST_ASYNC_FATAL_FFDC,
                                         errRecord,
                                         expected_chipop_errors,
                                         expected_async_errors);

#undef TEST_FUNC
    }

    void testMultipleSlids()
    {
#define TEST_FUNC "testMultipleSlids"
        // This test will check two things; First, that hostboot code can handle multiple SLIDs returned from the
        // SBE. Second, that the test chip-op code's parameters work as expected. There are two ways the SBE will return
        // multiple SLIDs, by giving a value greater than one in the error record itself or by sending multiple
        // different error records.

        TARGETING::Target * OdyOcmb = getOdyChip();
        if (OdyOcmb == nullptr)
        {
            // No Odyssey OCMBs found, abort test.
            TS_INFO(TEST_FUNC"Did NOT find any Odyssey OCMBs to work with, skipping test");
            return;
        }
        // Setting the error record count above one will have the SBE send back that number of unique SLIDs
        // with that RC.
        const uint8_t error_record_count = 10;
        errorRecords_t errRecord = { { RC_TEST_DIMM_TARGET0, FAPI2_ERRL_SEV_UNRECOVERABLE, error_record_count } };
        const size_t expected_chipop_errors = 0, // async failures should not produce chip-op fails.
                     expected_async_errors = error_record_count + 1;/* Whenever there's a getFFDC request sent to the
                                                                       SBE it will return an extra PLAT RC ffdc package
                                                                       with a different SLID than error record data we'd
                                                                       sent. So, add an extra log to the expected
                                                                       number. */

        // Test async non fatal
        send_and_check_error_record(TEST_FUNC" FIFO_TEST_ASYNC_NON_FATAL_FFDC",
                                         OdyOcmb,
                                         SbeFifo::FIFO_TEST_ASYNC_NON_FATAL_FFDC,
                                         errRecord,
                                         expected_chipop_errors,
                                         expected_async_errors);

        // Test async fatal
        send_and_check_error_record(TEST_FUNC" FIFO_TEST_ASYNC_FATAL_FFDC",
                                         OdyOcmb,
                                         SbeFifo::FIFO_TEST_ASYNC_FATAL_FFDC,
                                         errRecord,
                                         expected_chipop_errors,
                                         expected_async_errors);

        // Test sync
        send_and_check_error_record(TEST_FUNC" FIFO_TEST_SYNC_NON_FATAL_FFDC",
                                         OdyOcmb,
                                         SbeFifo::FIFO_TEST_SYNC_NON_FATAL_FFDC,
                                         errRecord,
                                         error_record_count);

        errorRecords_t records =
        {
            { RC_TEST_DIMM_TARGET0, FAPI2_ERRL_SEV_UNRECOVERABLE, 1},
            { RC_TEST_DIMM_TARGET2, FAPI2_ERRL_SEV_UNRECOVERABLE, 1},
        };

        // Test sync with two distinct error records. This will test that the FFDC parser is able to handle multiple
        // unique RCs at the same time.
        send_and_check_error_record(TEST_FUNC" FIFO_TEST_SYNC_NON_FATAL_FFDC",
                                         OdyOcmb,
                                         SbeFifo::FIFO_TEST_SYNC_NON_FATAL_FFDC,
                                         records,
                                         records.size());

#undef TEST_FUNC
    }

#define GET_TEST_TARGETS(parent, children, min_required, child_type)                               \
        getChildAffinityTargetsByState(children,                                                   \
                                       parent,                                                     \
                                       CLASS_NA,                                                   \
                                       child_type,                                                 \
                                       UTIL_FILTER_ALL);                                           \
        if (children.size() < min_required)                                                        \
        {                                                                                          \
            TS_INFO(TEST_FUNC" Did NOT find enough targets TYPE:0x%X to continue, skipping test",  \
                             child_type);                                                          \
            return;                                                                                \
        }                                                                                          \

    void runAllReturnCodes(TargetHandle_t OdyOcmb)
    {
#define TEST_FUNC "runAllReturnCodes:"
        TargetHandleList dimms,
                         memports,
                         pervasives,
                         temp_sensors;

        // Gather all the child targets of this OCMB for testing. Need at least 2 of each type to continue.
        // All the return code tests use only the first and second instances of each type.
        GET_TEST_TARGETS(OdyOcmb, dimms, 2, TYPE_DIMM)
        GET_TEST_TARGETS(OdyOcmb, memports, 2, TYPE_MEM_PORT)
        GET_TEST_TARGETS(OdyOcmb, pervasives, 2, TYPE_PERV)
        GET_TEST_TARGETS(OdyOcmb, temp_sensors, 2, TYPE_TEMP_SENSOR)

        std::vector<sbeFfdcTest> tests =
        {
            { RC_TEST_DIMM_TARGET0,
                dimms[0], ErrlEntry::NO_MATCH },
            { RC_TEST_DIMM_TARGET2,
                dimms[1], ErrlEntry::NO_MATCH },
            { RC_TEST_CALLOUT_DIMM_TARGET0,
                dimms[0], ErrlEntry::TARGET_MATCH },
            { RC_TEST_CALLOUT_DIMM_TARGET2,
                dimms[1], ErrlEntry::TARGET_MATCH },
            { RC_TEST_CALLOUT_DIMM_DECONFIG_TARGET0,
                dimms[0], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND },
            { RC_TEST_CALLOUT_DIMM_DECONFIG_TARGET2,
                dimms[1], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND },
            { RC_TEST_CALLOUT_DIMM_GARD_TARGET0,
                dimms[0], ErrlEntry::TARGET_MATCH | ErrlEntry::GARD_FOUND },
            { RC_TEST_CALLOUT_DIMM_GARD_TARGET2,
                dimms[1], ErrlEntry::TARGET_MATCH | ErrlEntry::GARD_FOUND },
            { RC_TEST_CALLOUT_DIMM_DECONFIG_GARD_TARGET0,
                dimms[0], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND | ErrlEntry::GARD_FOUND },
            { RC_TEST_CALLOUT_DIMM_DECONFIG_GARD_TARGET2,
                dimms[1], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND | ErrlEntry::GARD_FOUND },

            { RC_TEST_MEMPORT_TARGET0,
                memports[0], ErrlEntry::NO_MATCH },
            { RC_TEST_MEMPORT_TARGET1,
                memports[1], ErrlEntry::NO_MATCH },
            { RC_TEST_CALLOUT_MEMPORT_TARGET0,
                memports[0], ErrlEntry::TARGET_MATCH },
            { RC_TEST_CALLOUT_MEMPORT_TARGET1,
                memports[1], ErrlEntry::TARGET_MATCH },
            { RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_TARGET0,
                memports[0], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND },
            { RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_TARGET1,
                memports[1], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND },
            { RC_TEST_CALLOUT_MEMPORT_GARD_TARGET0,
                memports[0], ErrlEntry::TARGET_MATCH | ErrlEntry::GARD_FOUND },
            { RC_TEST_CALLOUT_MEMPORT_GARD_TARGET1,
                memports[1], ErrlEntry::TARGET_MATCH | ErrlEntry::GARD_FOUND },
            { RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_GARD_TARGET0,
                memports[0], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND | ErrlEntry::GARD_FOUND },
            { RC_TEST_CALLOUT_MEMPORT_DECONFIGURE_GARD_TARGET1,
                memports[1], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND | ErrlEntry::GARD_FOUND },

            { RC_TEST_PERV_TARGET1,
                pervasives[0], ErrlEntry::NO_MATCH },
            { RC_TEST_PERV_TARGET8,
                pervasives[1], ErrlEntry::NO_MATCH },
            { RC_TEST_CALLOUT_PERV_TARGET1,
                pervasives[0], ErrlEntry::TARGET_MATCH },
            { RC_TEST_CALLOUT_PERV_TARGET8,
                pervasives[1], ErrlEntry::TARGET_MATCH },
            { RC_TEST_CALLOUT_PERV_DECONFIGURE_TARGET1,
                pervasives[0], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND },
            { RC_TEST_CALLOUT_PERV_DECONFIGURE_TARGET8,
                pervasives[1], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND },
            { RC_TEST_CALLOUT_PERV_GARD_TARGET1,
                pervasives[0], ErrlEntry::TARGET_MATCH | ErrlEntry::GARD_FOUND },
            { RC_TEST_CALLOUT_PERV_GARD_TARGET8,
                pervasives[1], ErrlEntry::TARGET_MATCH | ErrlEntry::GARD_FOUND },
            { RC_TEST_CALLOUT_PERV_DECONFIGURE_GARD_TARGET1,
                pervasives[0], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND | ErrlEntry::GARD_FOUND },
            { RC_TEST_CALLOUT_PERV_DECONFIGURE_GARD_TARGET8,
                pervasives[1], ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND | ErrlEntry::GARD_FOUND },

            { RC_TEST_TEMPSENSOR_TARGET0,
                temp_sensors[0], ErrlEntry::NO_MATCH },
            { RC_TEST_TEMPSENSOR_TARGET1,
                temp_sensors[1], ErrlEntry::NO_MATCH },
            { RC_TEST_CALLOUT_TEMPSENSOR_TARGET0,
                temp_sensors[0], ErrlEntry::TARGET_MATCH },
            { RC_TEST_CALLOUT_TEMPSENSOR_TARGET1,
                temp_sensors[1], ErrlEntry::TARGET_MATCH },

            { RC_TEST_CALLOUT_OCMB_DECONFIGURE_GARD_TARGET0,
                OdyOcmb, ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND | ErrlEntry::GARD_FOUND },

        };

        for (const auto test : tests)
        {
            send_and_check_callouts(test, OdyOcmb);
        }
#undef TEST_FUNC
    }

    void testAllReturnCodes()
    {
        // Systematically test all return codes provided to the testFFDC chip-op.
        // The targets are: OCMB, DIMM, MEM_PORT, PERV, TEMP_SENSOR
        for (auto ocmb : composable(getAllChips)(TYPE_OCMB_CHIP, true))
        {
            if (UTIL::isOdysseyChip(ocmb))
            {
                runAllReturnCodes(ocmb);
            }
        }
    }

};

#endif
