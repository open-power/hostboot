/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/test/seepromSecurityTest.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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



#include <secureboot/secure_reasoncodes.H>
#include <secureboot/service.H>
#include <secureboot/service_ext.H>
#include <secureboot/settings.H>

#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/common/utilFilter.H>

#include <errl/errlentry.H>
#include <errl/errlmanager.H>

#include <devicefw/userif.H>

#include <arch/pvrformat.H>
#include <sys/mmio.h>


// Structure for holding the various information about a particular test of the measurement seeprom security
// verification code.
struct mfgSecurityTest
{
    // Production mode or MFG mode determines the error log severity should an error occur.
    bool isMfgMode;

    // An enumeration to hold all failure types.
    enum class failureType_t : uint8_t
    {
        ALL_GOOD    = 0x0, // Has min version and fuse blown
        BAD_VERSION = 0x1, // Min secure version not installed
        BAD_FUSE    = 0x2  // Fuse not yet blown, but should be.
    };

    // What kind of failure is this?
    failureType_t failType;

    // An enumeration to hold procs effected by issue.
    enum class numProcsEffected_t : uint8_t
    {
        NA  = 0x0, // Should only be used with ALL_GOOD tests.
        ONE = 0x1,
        ALL = 0x2
    };

    // How many procs are effected by the problem?
    numProcsEffected_t procsEffected;
};

// This register provides a way to change the state of EXPORT_CTRL_OTP_SPIM_MEAS_SEEPROM_LOCK_DC fuse which
// is the mechanism which allows the SBE measurement seeproms to be updated or not. See scom def for more details.
constexpr uint32_t EXPORT_REGULATION_CTRL_REG = 0x1000E;

// Structure that holds the original register contents that will be modified during the tests that way
// the test can clean up after itself.
struct procRegContents
{

    // The target where the data comes from.
    TARGETING::Target* proc;
    // Hold content from the version data register;
    uint64_t measurementRegData;
    // Holds the data contained within EXPORT_REGULATION_CTRL_REG.
    uint64_t exportRegCtrlData;
};

typedef std::vector<procRegContents> procRegContentsList;

// ======================================
// Utility Functions
// =====================================

// Saves off the register contents that will be changed during testing. See definition at bottom of file.
errlHndl_t saveProcRegValues(const TARGETING::TargetHandleList &procList,
                             procRegContentsList    &o_regs);

// Restores the register contents that was changed during testing. See definition at bottom of file.
errlHndl_t restoreProcRegValues(const procRegContentsList &i_regs);


// Handles setting up procs in the system for the given test case. See definition at bottom of file.
errlHndl_t setupProcsForMeasurementSecurityChecks(const mfgSecurityTest& test,
                                                  const TARGETING::TargetHandleList& procList);

class SeepromSecurityTest : public CxxTest::TestSuite
{
public:

    // Tests that measurement seeproms on all procs are running minimum secure version and have had their
    // fuses blown.
    // NOTE: This is a DD2 hardware assertion therefor DD1 simics will skip this testcase.
    void test_MfgMeasurementSeepromSecurityChecks(void)
    {
        errlHndl_t err = nullptr;
        // Used to save reg contents that will be modified during this test to be restored after.
        procRegContentsList originalRegContents;

        do {
        // Only run these tests if this is DD2 simics
        PVR_t pvr(mmio_pvr_read() & 0xFFFFFFFF);
        if (pvr.isP10DD10())
        {
            TS_INFO("Detected P10 DD1 simics, skipping testcases for DD2...");
            break;
        }

        // The list of tests to execute to verify measurement seeprom security checks for both MFG mode and
        // non-MFG mode.
        // Tests the following scenarios:
        //         * MFG Mode and Non-MFG mode for each:
        //             * No issues
        //             * 1 proc -> bad minimum secure version
        //             * 1 proc -> fuse yet to be blown but min secure version installed.
        //             * all procs -> bad minimum secure version
        //             * all procs -> fuse yet to be blown but min secure version installed.
        // NOTE: For the purposes of these tests only the fuse will be unblown OR min secure version is not installed
        //       not both at the same time because if both are a problem simultaneously then which error returned is
        //       dependent on how the code is structured.
        std::vector<mfgSecurityTest> tests{
            { // MFG Mode enabled with correct min version installed and fuses blown.
              // Expected Result: No error logs.
                true,
                mfgSecurityTest::failureType_t::ALL_GOOD,
                mfgSecurityTest::numProcsEffected_t::NA,
            },
            { // MFG Mode enabled with one proc having bad min version installed and all fuses blown.
              // NOTE: From the perspective of the test, the fuse state is a "don't care" since the failing RC
              //       will be for the version.
              // Expected Result: An unrecoverable log for the effected proc
                true,
                mfgSecurityTest::failureType_t::BAD_VERSION,
                mfgSecurityTest::numProcsEffected_t::ONE,
            },
            { // MFG Mode enabled with one proc having bad min version installed and all fuses blown.
              // NOTE: From the perspective of the test, the fuse state is a "don't care" since the failing RC
              //       will be for the version.
              // Expected Result: An unrecoverable log for each effected proc
                true,
                mfgSecurityTest::failureType_t::BAD_VERSION,
                mfgSecurityTest::numProcsEffected_t::ALL,
            },
            { // MFG Mode enabled with one proc having not had its fuse blown.
              // Expected Result: An unrecoverable log for the effected proc
                true,
                mfgSecurityTest::failureType_t::BAD_FUSE,
                mfgSecurityTest::numProcsEffected_t::ONE,
            },
            { // MFG Mode enabled with one proc having bad min version installed and all fuses blown.
              // Expected Result: An unrecoverable log for each effected proc
                true,
                mfgSecurityTest::failureType_t::BAD_FUSE,
                mfgSecurityTest::numProcsEffected_t::ALL,
            },
            { // MFG Mode disabled with correct min version installed and fuses blown.
              // Expected Result: No error logs.
                false, // Normal IPL
                mfgSecurityTest::failureType_t::ALL_GOOD,
                mfgSecurityTest::numProcsEffected_t::NA,
            },
            { // MFG Mode disabled with one proc having bad min version installed and all fuses blown.
              // NOTE: From the perspective of the test, the fuse state is a "don't care" since the failing RC
              //       will be for the version.
              // Expected Result: An informational log for the effected proc
                false, // Normal IPL
                mfgSecurityTest::failureType_t::BAD_VERSION,
                mfgSecurityTest::numProcsEffected_t::ONE,
            },
            { // MFG Mode disabled with one proc having bad min version installed and all fuses blown.
              // NOTE: From the perspective of the test, the fuse state is a "don't care" since the failing RC
              //       will be for the version.
              // Expected Result: An informational log for each effected proc
                false, // Normal IPL
                mfgSecurityTest::failureType_t::BAD_VERSION,
                mfgSecurityTest::numProcsEffected_t::ALL,
            },
            { // MFG Mode disabled with one proc having not had its fuse blown.
              // Expected Result: An informational log for the effected proc
                false, // Normal IPL
                mfgSecurityTest::failureType_t::BAD_FUSE,
                mfgSecurityTest::numProcsEffected_t::ONE,
            },
            { // MFG Mode disabled with one proc having bad min version installed and all fuses blown.
              // Expected Result: An informational log for each effected proc
                false, // Normal IPL
                mfgSecurityTest::failureType_t::BAD_FUSE,
                mfgSecurityTest::numProcsEffected_t::ALL,
            },
        };

        // =================================================================
        // Begin testcases
        // =================================================================

        // Get all the procs
        TARGETING::TargetHandleList procList;
        getAllChips(procList, TARGETING::TYPE_PROC);

        // Before the tests begin, save the original data off.
        err = saveProcRegValues(procList, originalRegContents);
        if (err)
        {
            // Unexpected error
            TS_FAIL("test_MfgMeasurementSeepromSecurityChecks: "
                    "Unexpected error while trying to save original proc data,"
                    " can't continue...");
            break;
        }

        int testId = 0;
        for (const auto& test : tests)
        {
            // If there is a problem during one of the tests then this id is used to determine which test failed.
            testId++;

            TS_INFO("test_MfgMeasurementSeepromSecurityChecks: "
                    "Running test %d of %d with conditions: MFG MODE = %s, failType = 0x%x, numProcsEffected = 0x%x;"
                    " See test for decode of enums.",
                    testId,
                    tests.size(),
                    test.isMfgMode ? "TRUE" : "FALSE",
                    test.failType,
                    test.procsEffected);

            // Set the MFG flag appropriately for the test
            if (test.isMfgMode)
            {
                TARGETING::setMfgFlag(TARGETING::MFG_FLAGS_MNFG_SEEPROM_SECURITY_CHECKS);
            }
            else
            {
                TARGETING::clearMfgFlag(TARGETING::MFG_FLAGS_MNFG_SEEPROM_SECURITY_CHECKS);
            }

            // Setup the procs for the test
            err = setupProcsForMeasurementSecurityChecks(test, procList);
            if (err)
            {
                // Unexpected error, abort the test.
                TS_FAIL("test_MfgMeasurementSeepromSecurityChecks: Unexpected error in test %d of %d,"
                        " can't continue...",
                        testId,
                        tests.size());
                break;
            }

            // Depending on how many procs are supposed to fail a given test these will determine if enough errors
            // occurred.
            int numErrors = 0, numExpectedErrors = 0;

            // Establish the number of expected errors for this test.
            if (test.procsEffected == mfgSecurityTest::numProcsEffected_t::ONE)
            {
                numExpectedErrors = 1;
            } else if (test.procsEffected == mfgSecurityTest::numProcsEffected_t::ALL)
            {
                // One error per failing proc.
                numExpectedErrors = procList.size();
            }

            // For each proc in the system:
            //  * Call verifyMeasurementSeepromSecurity()
            //  * Verify the results are in line with the current test
            for (const auto& proc : procList)
            {

                // An error could come back depending on the test.
                err = SECUREBOOT::verifyMeasurementSeepromSecurity(proc);

                if (err)
                {
                    // An error was returned, now determine if it should have happened
                    // and if it was the correct one.
                    if (err->moduleId() != SECUREBOOT::MOD_VERIFY_MEASUREMENT_SEEPROM_SECURITY)
                    {
                        // An unexpected error occurred during the test.
                        TS_FAIL("test_MfgMeasurementSeepromSecurityChecks: Unexpected error in test %d of %d,"
                                " can't continue...",
                                testId,
                                tests.size());
                        break;
                    }

                    numErrors++;

                    // Did the error match the one the test expected?
                    if ( ((err->reasonCode() == SECUREBOOT::RC_UNSECURE_MEASUREMENT_VERSION)
                          && (test.failType == mfgSecurityTest::failureType_t::BAD_VERSION))
                       || ((err->reasonCode() == SECUREBOOT::RC_UNBLOWN_MEASUREMENT_FUSE)
                          && (test.failType == mfgSecurityTest::failureType_t::BAD_FUSE)))
                    {
                        // Have the number of errors which occurred exceeded expectations?
                        if (numErrors > numExpectedErrors)
                        {
                            // Too many errors for this test
                            TS_FAIL("test_MfgMeasurementSeepromSecurityChecks: "
                                    "Too many errors occurred for test %d of %d. Actual %d, Expected %d",
                                    testId,
                                    tests.size(),
                                    numErrors,
                                    numExpectedErrors);

                            // Toss out the error
                            delete err;
                            err = nullptr;

                            // Continue on to the next test.
                            break;
                        }

                        // Was the severity of the error in line with expectations?
                        // MFG mode   -> UNRECOVERABLE
                        // Normal IPL -> INFORMATIONAL
                        if ( ((err->sev() == ERRORLOG::ERRL_SEV_UNRECOVERABLE)
                             && !TARGETING::isSeepromSecurityChecksSet())
                            || ((err->sev() == ERRORLOG::ERRL_SEV_INFORMATIONAL)
                               && TARGETING::isSeepromSecurityChecksSet()))
                        {
                            // The error severity didn't match expectations.
                            TS_FAIL("test_MfgMeasurementSeepromSecurityChecks: "
                                    "Actual error severity didn't match expected severity. Actual 0x%x, Expected %s",
                                    err->sev(),
                                    TARGETING::isSeepromSecurityChecksSet() ? "UNRECOVERABLE" : "INFORMATIONAL");

                            // Toss out the error
                            delete err;
                            err = nullptr;

                            // Continue on to the next test.
                            break;
                        }

                        // Everything checks out so far for this test. Toss out the error log.
                        delete err;
                        err = nullptr;

                    }
                    else
                    {
                        // An unexpected error occurred.
                        TS_FAIL("test_MfgMeasurementSeepromSecurityChecks: Unexpected error in test %d of %d,"
                                " can't continue...",
                                testId,
                                tests.size());
                        break;
                    }
                }
            } // End loop over all procs
            if (err)
            {
                // An unexpected error occurred during the test.
                break;
            }

            // Make sure the number of errors matched the test expectations
            // NOTE: numErrors > numExpectedErrors handled during proc iteration
            if (numErrors != numExpectedErrors)
            {
                TS_FAIL("test_MfgMeasurementSeepromSecurityChecks: "
                        "Not enough errors occurred for test %d of %d. Actual %d, Expected %d",
                        testId,
                        tests.size(),
                        numErrors,
                        numExpectedErrors);
            }

        } // End loop over all tests
        if (err)
        {
            // An unexpected error occurred during the test.
            break;
        }


        } while(0);

        if (err)
        {
            TS_FAIL("test_MfgMeasurementSeepromSecurityChecks: An unexpected error occurred. Check the log for info.");
            // An unexpected error occurred somewhere during the tests. Commit it for debug.
            ERRORLOG::errlCommit(err, CXXTEST_COMP_ID);
        }

        err = restoreProcRegValues(originalRegContents);
        if (err)
        {
            // Unexpected error
            TS_INFO("test_MfgMeasurementSeepromSecurityChecks: Failed to restore original register states for procs. "
                    "Could have downstream effects for other tests...");
            ERRORLOG::errlCommit(err, CXXTEST_COMP_ID);
        }

    };
};

/*
 * @brief a helper function to write to a 64 bit register
 *
 * @param[in]  i_reg    Contains all the necessary info to write to the register.
 *
 * @return     errlHndl_t    nullptr on success, otherwise an error.
 */
errlHndl_t writeRegister64(SecureRegisterValues i_reg)
{
    errlHndl_t err = nullptr;

    do {
        size_t size = sizeof(uint64_t), actual = sizeof(uint64_t);

        err = deviceWrite(i_reg.procTgt,
                          &(i_reg.data),
                          actual,
                          DEVICE_SCOM_ADDRESS(i_reg.addr));
        if (err)
        {
            break;
        }

        if (actual != size)
        {
            TS_FAIL("writeRegister64: Didn't write the expected amount of data to reg 0x%x",
                    i_reg.addr);
            // Make a bogus error to send back.
            err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    0xFF,
                    0xFFFF);
        }
    } while (0);

    return err;
}

/*
 * @brief a helper function to read to a 64 bit register
 *
 * @param[in]  i_reg    Contains all the necessary info to read to the register.
 *
 * @return     errlHndl_t    nullptr on success, otherwise an error.
 */
errlHndl_t readRegister64(SecureRegisterValues i_reg)
{
    errlHndl_t err = nullptr;

    do {
        size_t size = sizeof(uint64_t), actual = sizeof(uint64_t);

        err = deviceRead(i_reg.procTgt,
                         &(i_reg.data),
                         actual,
                         DEVICE_SCOM_ADDRESS(i_reg.addr));
        if (err)
        {
            break;
        }

        if (actual != size)
        {
            TS_FAIL("readRegister64: Didn't read the expected amount of data to reg 0x%x",
                    i_reg.addr);
            // Make a bogus error to send back.
            err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    0xFF,
                    0xFFFF);
        }
    } while (0);

    return err;
}

/*
 * @brief A helper function to save off the contents of the registers modified by this test suite per proc in
 *        the system.
 * @param[in]  procList     The list of procs to save contents for.
 *
 * @param[out] o_regs       The saved contents of the regs per proc. Enough data is in this list to identify where it
 *                          came from to make restoration later simpler.
 *
 * @return     errlHndl_t  nullptr on success, otherwise an error.
 */
errlHndl_t saveProcRegValues(const TARGETING::TargetHandleList &procList,
                             procRegContentsList    &o_regs)
{
    errlHndl_t err = nullptr;

    o_regs.clear();

    do {
        for (const auto& proc : procList)
        {
            SecureRegisterValues reg;
            procRegContents contents;

            contents.proc = reg.procTgt = proc;

            // Read data from the measurement version register.
            reg.addr = sbe_measurement_regs[2];
            reg.data = 0x0;

            err = SECUREBOOT::getSbeMeasurementRegister(reg);
            if (err)
            {
                break;
            }

            // Save the data off
            contents.measurementRegData = reg.data;

            // Read the export ctrl reg next.
            reg.addr = EXPORT_REGULATION_CTRL_REG;
            reg.data = 0x0;

            err = readRegister64(reg);
            if (err)
            {
                break;
            }

            // Save of the data
            contents.exportRegCtrlData = reg.data;

            // Add the content to the vector
            o_regs.push_back(contents);

        }

    } while (0);

    return err;
}

/*
 * @brief A helper function to restore the contents of the registers modified by this test suite per proc in
 *        the system.
 *
 * @param[in] i_regs       The saved contents of the regs per proc. Enough data is in this list to identify where it
 *                         came from to make restoration simpler.
 *
 * @return     errlHndl_t  nullptr on success, otherwise an error.
 */
errlHndl_t restoreProcRegValues(const procRegContentsList &i_regs)
{
    errlHndl_t err = nullptr;

    do {
        for (const auto& origContent : i_regs)
        {
            SecureRegisterValues reg;

            reg.procTgt = origContent.proc;

            // Write data to the measurement version register.
            reg.addr = sbe_measurement_regs[2];
            reg.data = origContent.measurementRegData;

            err = writeRegister64(reg);
            if (err)
            {
                break;
            }

            // Write the export ctrl reg next.
            reg.addr = EXPORT_REGULATION_CTRL_REG;
            reg.data = origContent.exportRegCtrlData;

            err = writeRegister64(reg);
            if (err)
            {
                break;
            }
        }

    } while (0);

    return err;
}


/*
 * @brief A helper function to setup all procs in a given list for a mfgSecurityTest. It does this by first
 *        setting them to the expected ALL_GOOD state and then using the test parameter to invalidate that state the way
 *        the test specifies.
 *
 * @param[in] test      A mfgSecurityTest that specifies which state all the procs need to be in for the test.
 *
 * @param[in] procList  A list of procs to work with for the given test.
 */
errlHndl_t setupProcsForMeasurementSecurityChecks(const mfgSecurityTest& test,
                                                  const TARGETING::TargetHandleList& procList)
{
    errlHndl_t err = nullptr;
    // The bit that sets/clears the fuse blown state for the proc.
    constexpr uint64_t EXPORT_CTRL_OTP_SPIM_MEAS_SEEPROM_LOCK_MASK = 0x0010000000000000ull;

    do {
    // First restore all procs to an ALL_GOOD state to clean up after any potential prior tests.
    for (const auto& proc : procList)
    {
        // Set the measurement version to be the minimum secure version.
        SecureRegisterValues reg;
        reg.procTgt = proc;
        reg.addr = sbe_measurement_regs[2];
        reg.data = 0x0;

        err = SECUREBOOT::getSbeMeasurementRegister(reg);
        if (err)
        {
            break;
        }

        // Sets the expected minimum secure version by setting the data in the reg in that region to zeroes first then
        // masking in the expected version.
        reg.data = (reg.data & ~SECUREBOOT::VERSION_BYTES_MASK)
                 | static_cast<uint64_t>(SECUREBOOT::MINIMUM_SECURE_MEASUREMENT_VERSION);

        err = writeRegister64(reg);
        if (err)
        {
            break;
        }

        // Replicate the behavior of a blown fuse.
        reg.addr = EXPORT_REGULATION_CTRL_REG;
        reg.data = 0x0;

        err = readRegister64(reg);
        if (err)
        {
            break;
        }

        reg.data |= EXPORT_CTRL_OTP_SPIM_MEAS_SEEPROM_LOCK_MASK;

        err = writeRegister64(reg);
        if (err)
        {
            break;
        }

    }
    if (err)
    {
        break;
    }

    // Iterate over all procs and modify seeprom regs according to the test demands.
    for (const auto& proc : procList)
    {
        SecureRegisterValues reg;
        reg.procTgt = proc;
        reg.data = 0x0;

        switch (test.failType)
        {
            case mfgSecurityTest::failureType_t::ALL_GOOD:
                // This has already been done above, just break.
                break;
            case mfgSecurityTest::failureType_t::BAD_VERSION:
                // Set version less than the minimum secure version.
                reg.addr = sbe_measurement_regs[2];

                err = SECUREBOOT::getSbeMeasurementRegister(reg);
                if (err)
                {
                    break;
                }

                reg.data = (reg.data & ~SECUREBOOT::VERSION_BYTES_MASK) | static_cast<uint64_t>(0x00010000);

                err = writeRegister64(reg);
                break;
            case mfgSecurityTest::failureType_t::BAD_FUSE:
                // Switch the fuse into the unblown state
                reg.addr = EXPORT_REGULATION_CTRL_REG;

                err = readRegister64(reg);
                if (err)
                {
                    break;
                }

                reg.data &= ~EXPORT_CTRL_OTP_SPIM_MEAS_SEEPROM_LOCK_MASK;

                err = writeRegister64(reg);
                break;
            default:
                // Unknown test
                assert(false, "setupProcsForMeasurementSecurityChecks: Unknown test found, don't know how to setup.");
                break;
        }
        if (err)
        {
            break;
        }

        if (test.procsEffected == mfgSecurityTest::numProcsEffected_t::ONE)
        {
            // Only one proc has an issue for this test. Since the failing proc doesn't matter, just break
            // here and leave the rest in the ALL_GOOD state.
            break;
        }

    }
    if (err)
    {
        break;
    }

    } while(0);

    return err;
}


