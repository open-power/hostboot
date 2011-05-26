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

#define TEST_USR_8BIT_1    0x80
#define TEST_USR_8BIT_2    0x93

#define TEST_USR_16BIT_1    0x8000
#define TEST_USR_16BIT_2    0x9003

#define TEST_USR_32BIT_1     0x80000001
#define TEST_USR_32BIT_2     0x90000003

#define TEST_USR_64BIT_1    0x8000000000000001
#define TEST_USR_64BIT_2    0x9000000000000003


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

        // An example that shows how to use macros to stuff data into
        // the two 64-bit user data parameters in the error log.
        // l_userData1 = 16bit(0):l_bit8_1:l_bit8_2:l_32bit_1
        uint8_t l_8bit_1 = TEST_USR_8BIT_1;
        uint8_t l_8bit_2 = TEST_USR_8BIT_2;
        uint32_t l_32bit_1 = TEST_USR_32BIT_1;
        uint64_t l_userData1 =
              TWO_UINT32_TO_UINT64(
                TO_UINT32(TWO_UINT8_TO_UINT16(l_8bit_1, l_8bit_2)), l_32bit_1);
        // l_userData2 = l_16bit_1:l_16bit_2:l_32bit_2
        uint16_t l_16bit_1 = TEST_USR_16BIT_1;
        uint16_t l_16bit_2 = TEST_USR_16BIT_2;
        uint32_t l_32bit_2 = TEST_USR_32BIT_2;
        uint64_t l_userData2 =
                TWO_UINT16_ONE_UINT32_TO_UINT64(l_16bit_1, l_16bit_2, l_32bit_2);

        // Create an error log
        errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                                TEST_SEVERITY,
                                TEST_MOD_ID,
                                TEST_REASON_CODE,
                                l_userData1,
                                l_userData2);

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
            errlCommit(l_err);
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
        // An example that shows how to use macros to stuff data into
        // the two 64-bit user data parameters in the error log.
        // l_userData1 = l_bit32_1:l_bit32_2
        uint32_t l_32bit_1 = TEST_USR_32BIT_1;
        uint32_t l_32bit_2 = TEST_USR_32BIT_2;
        uint64_t l_userData1 = TWO_UINT32_TO_UINT64(l_32bit_1, l_32bit_2);

        // l_userData2 = 24bit(0):l_8bit_1:16bit(0):l_16bit_1
        uint8_t l_8bit_1 = TEST_USR_8BIT_1;
        uint16_t l_16bit_1 = TEST_USR_16BIT_1;
        uint64_t l_userData2 =
                TWO_UINT32_TO_UINT64(TO_UINT32(l_8bit_1), TO_UINT32(l_16bit_1));

        // Create an error log
        errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                                TEST_SEVERITY,
                                TEST_MOD_ID,
                                TEST_REASON_CODE,
                                l_userData1,
                                l_userData2);

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
