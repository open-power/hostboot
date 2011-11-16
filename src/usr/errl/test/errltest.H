//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/test/errltest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
#include <trace/trace.H>
#include <hbotcompid.H>

#define TEST_REASON_CODE    (ERRL_COMP_ID | 0x0F)
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
        bool fOK;
        ERRORLOG::ErrlUD * pffdc;

        // An example that shows how to use macros to stuff data into
        // the two 64-bit user data parameters in the error log.
        // l_userData1 = 16bit(0):l_bit8_1:l_bit8_2:l_32bit_1
        uint8_t l_8bit_1 = TEST_USR_8BIT_1;      // 0x80
        uint8_t l_8bit_2 = TEST_USR_8BIT_2;      // 0x93
        uint32_t l_32bit_1 = TEST_USR_32BIT_1;   // 0x80000001
        uint64_t l_userData1 =
          TWO_UINT32_TO_UINT64( TO_UINT32(TWO_UINT8_TO_UINT16(l_8bit_1, l_8bit_2)), l_32bit_1);
            // yields 0x0000809380000001


        // l_userData2 = l_16bit_1:l_16bit_2:l_32bit_2
        uint16_t l_16bit_1 = TEST_USR_16BIT_1;  // 0x8000
        uint16_t l_16bit_2 = TEST_USR_16BIT_2;  // 0x9003
        uint32_t l_32bit_2 = TEST_USR_32BIT_2;  // 0x90000003
        uint64_t l_userData2 = TWO_UINT16_ONE_UINT32_TO_UINT64(l_16bit_1, l_16bit_2, l_32bit_2);
            // yields 0x8000900390000003



        do
        {

            // Create an error log
            errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    TEST_MOD_ID,
                                    TEST_REASON_CODE,
                                    l_userData1,
                                    l_userData2);


            // Make sure log is created
            if (l_err == NULL)
            {
                TS_FAIL("testErrl1: createErrlLog() outputs NULL pointer!");
                break;
            }


            // These addFFDC() calls return a pointer to class ERRORLOG::ErrlFFDC
            // but errlffdc.H is not publicly includable to give me the definition
            // for it.  addFFDC() should return a Boolean indication of success.

            const char * pch = "martha washington";
            pffdc = l_err->addFFDC( ERRL_COMP_ID, pch, strlen( pch ), 1, 2 );
            if ( NULL == pffdc )
            {
                TS_FAIL("testErrl1: addFFDC() output NULL pointer");
                break;
            }

            // really short user data
            pch = "A";
            pffdc = l_err->addFFDC( DEVFW_COMP_ID, pch, strlen( pch ), 3, 4 );
            if ( NULL == pffdc )
            {
                TS_FAIL("testErrl1: addFFDC() output NULL pointer");
                break;
            }

            pch = "george washington";
            pffdc = l_err->addFFDC( DEVFW_COMP_ID, pch, strlen( pch ), 3, 4 );
            if ( NULL == pffdc )
            {
                TS_FAIL("testErrl1: addFFDC() output NULL pointer");
                break;
            }

            pch = "dwight eisenhour";
            pffdc = l_err->addFFDC( SCOM_COMP_ID, pch, strlen( pch ), 5, 6 );
            if ( NULL == pffdc )
            {
                TS_FAIL("testErrl1: addFFDC() output NULL pointer");
                break;
            }

            pch = "ronald ";
            pffdc = l_err->addFFDC( ERRL_COMP_ID, pch, strlen( pch ), 7, 8 );
            if ( NULL == pffdc )
            {
                TS_FAIL("testErrl1: addFFDC() output NULL pointer");
                break;
            }

            // Append data to something already added.
            pch = "reagan";
            l_err->appendToFFDC( pffdc, pch, strlen(pch) );

            // Collect trace
            fOK = l_err->collectTrace(  "INITSVC" );
            if( !fOK )
            {
                TS_FAIL( "collectTrace(INITSVC) rets false." );
                break;
            }

            // Assuming trace buffers are 0x800 in size, and you're going
            // after a trace buffer that has wrapped, then a size almost as
            // big as the buffer will exercise the wrapping code in
            // trace::getBuffer()
            fOK = l_err->collectTrace(  "XSCOM" , 0x7D0 );
            if( !fOK )
            {
                TS_FAIL( "collectTrace(XSCOM) rets false." );
                break;
            }

            fOK = l_err->collectTrace(  "UNKNOWN"  );
            if( fOK )
            {
                TS_FAIL( "collectTrace(UNKNOWN) rets true" );
                break;
            }

            fOK = l_err->collectTrace( "TARG", sizeof(trace_buf_head_t)-2);
            if( fOK )
            {
                // expect an error, buffer not big enough
                TS_FAIL( "collectTrace(TARG,38) rets true" );
                break;
            }

            fOK = l_err->collectTrace(  "TARG", sizeof( trace_buf_head_t ));
            if( !fOK )
            {
                // Buffer is big enough for the header only. It is
                // supposed to work, although not terribly useful.
                TS_FAIL( "collectTrace(TARG,40) rets false" );
                break;
            }

            // sizeof( trace_buf_head_t ) + n bytes such that a single trace
            // entry cannot fit into.
            uint64_t l_cb = sizeof(trace_buf_head_t) + (sizeof(trace_bin_entry_t)/2);
            fOK = l_err->collectTrace( "TARG", l_cb );
            if( !fOK )
            {
                // cb is big enough for the header only, but no
                // room for any entries. 
                TS_FAIL( "collectTrace(TARG,l_cb) rets false", l_cb );
                break;
            }

            // Normal buffer sizes are 0x800 (2048), so passing
            // something bigger is not expected to be an error.
            // TODO: maybe after story "user selectable trace buffer sizes"
            // TRAC_DEFAULT_BUFFER_SIZE (0x800) will be publicly available.
            fOK = l_err->collectTrace(  "TARG" , 4003 );
            if( !fOK )
            {
                TS_FAIL( "collectTrace(TARG,4003) rets false" );
                break;
            }


            // Add null data.
            pffdc = l_err->addFFDC( ERRL_COMP_ID, NULL, 0,  9, 10 );
            if ( NULL != pffdc )
            {
                TS_FAIL("testErrl1: addFFDC() returned non null");
                break;
            }

            // Verify log data
            if (l_err->sev() != ERRORLOG::ERRL_SEV_INFORMATIONAL)
            {
                TS_FAIL("testErrl1: createErrlLog() returns incorrect severity!");
                break;
            }

            if (l_err->reasonCode() != TEST_REASON_CODE)
            {
                TS_FAIL("testErrl1: createErrlLog() returns incorrect reason code!");
                break;
            }

            if (l_err->eventType() != ERRORLOG::ERRL_ETYPE_NOT_APPLICABLE)
            {
                TS_FAIL("testErrl1: createErrlLog() returns incorrect event type!");
                break;
            }

            if (l_err->subSys() != ERRORLOG::EPUB_FIRMWARE_SUBSYS )
            {
                TS_FAIL("testErrl1: createErrlLog() returns incorrect sub system!");
                break;
            }

            if (l_err->srcType() != ERRORLOG::SRC_ERR_INFO)
            {
                TS_FAIL("testErrl1: createErrlLog() returns incorrect SRC type!");
                break;
            }

            if (l_err->termState() != ERRORLOG::TERM_STATE_UNKNOWN)
            {
                TS_FAIL("testErrl1: termState() returns incorrect term state!");
                break;
            }



            // Commit error log with different component ID.
            errlCommit(l_err, FSI_COMP_ID);

            // Make sure error log has been deleted by manager
            if (l_err != NULL)
            {
                TS_FAIL("testErrl1: commitErrLog() did not delete error!");
                break;
            }

        }
        while(0);
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
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
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
