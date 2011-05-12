#ifndef __ERRLTEST_H
#define __ERRLTEST_H

/**
 *  @file errltest.H
 *
 *  @brief Test case for Error Logging
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>

#define TEST_REASON_CODE    0x0F0F
#define TEST_SEVERITY       ERRORLOG::ERRL_SEV_INFORMATIONAL
#define TEST_MOD_ID         0x0022
#define TEST_USR_DATA_1     0x8000000000000001
#define TEST_USR_DATA_2     0x9000000000000003
#define TEST_RETURN_CODE    0xF0F0

class ErrlTest: public CxxTest::TestSuite
{
public:


    /**
     * @brief Test error log creation
     *  - Create an error log
     *  - Verify data of created log
     *  - Commit an error log
     *  - Delete an error log
     */
    void testErrl1(void)
    {
        // Create an error log
        errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                                TEST_SEVERITY,
                                TEST_MOD_ID,
                                TEST_REASON_CODE,
                                TEST_USR_DATA_1,
                                TEST_USR_DATA_2);

        // Make sure log is created
        if (l_err == NULL)
        {
            TS_FAIL("testErrl1: createErrlLog() outputs NULL pointer!");
        }

        // Verify log data
        else if (l_err->sev() != ERRORLOG::ERRL_SEV_INFORMATIONAL)
        {
            TS_FAIL("testErrl1: createErrlLog() returns incorrect severity!");
        }
        else if (l_err->reasonCode() != TEST_REASON_CODE)
        {
             TS_FAIL("testErrl1: createErrlLog() returns incorrect reason code!");
        }
        else if (l_err->eventType() != ERRORLOG::ERRL_ETYPE_NOT_APPLICABLE)
        {
             TS_FAIL("testErrl1: createErrlLog() returns incorrect event type!");
        }
        else if (l_err->subSys() != ERRORLOG::EPUB_RESERVED_0)
        {
             TS_FAIL("testErrl1: createErrlLog() returns incorrect sub system!");
        }
        else if (l_err->srcType() != ERRORLOG::SRC_ERR_INFO)
        {
             TS_FAIL("testErrl1: createErrlLog() returns incorrect SRC type!");
        }
        else if (l_err->termState() != ERRORLOG::TERM_STATE_UNKNOWN)
        {
             TS_FAIL("testErrl1: termState() returns incorrect term state!");
        }
        else
        {
            // Commit error log
            ERRORLOG::theErrlManager::instance().commitErrLog(l_err);
            // Make sure error log has been deleted by manager
            if (l_err != NULL)
            {
                TS_FAIL("testErrl1: commitErrLog() did not delete error!");
            }
        }
    }

    /**
     * @brief Test error log parameter settings
     */
    void testErrl2(void)
    {
        // Create an error log
        errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                                TEST_SEVERITY,
                                TEST_MOD_ID,
                                TEST_REASON_CODE,
                                TEST_USR_DATA_1,
                                TEST_USR_DATA_2);

        // Make sure log is created
        if (l_err == NULL)
        {
            TS_FAIL("testErrl2: createErrlLog() returns NULL pointer!");
        }
        else
        {
            // Set and verify log data
            l_err->setSev(ERRORLOG::ERRL_SEV_UNKNOWN);
            l_err->setEventType(ERRORLOG::ERRL_ETYPE_CAPACITY_UPGRADE);
            l_err->setSubSys(ERRORLOG::EPUB_UNKNOWN);
            l_err->setSrcType(ERRORLOG::SRC_ERR_INFO);
            l_err->setTermState(ERRORLOG::TERM_STATE_NO_FLAGS);

            if (l_err->sev() != ERRORLOG::ERRL_SEV_UNKNOWN)
            {
                TS_FAIL("testErrl2: setSev() fails!");
            }
            else if (l_err->eventType() != ERRORLOG::ERRL_ETYPE_CAPACITY_UPGRADE)
            {
                TS_FAIL("testErrl2: setEventType() fails!");
            }
            else if (l_err->subSys() != ERRORLOG::EPUB_UNKNOWN)
            {
                TS_FAIL("testErrl2: setSubSys() fails!");
            }
            else if (l_err->srcType() != ERRORLOG::SRC_ERR_INFO)
            {
                TS_FAIL("testErrl2: setSrcType() fails!");
            }
            else if (l_err->termState() != ERRORLOG::TERM_STATE_NO_FLAGS)
            {
                 TS_FAIL("testErrl2: setTermState() fails!");
            }

            // Delete the log
            delete l_err;
            l_err = NULL;

        }
    }
};

#endif
