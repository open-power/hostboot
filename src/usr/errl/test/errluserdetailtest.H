//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/test/errluserdetailtest.H $
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
#ifndef __TEST_ERRLUSERDETAILSTEST_H
#define __TEST_USERUSERDETAILSTEST_H

/**
 *  @file errluserdetailstest.H
 *
 *  @brief Test user data plugin for errorlog.
 *
 */

#include    <cxxtest/TestSuite.H>
#include    <errl/errlentry.H>
#include    <errl/errluserdetails.H>

using   namespace   ERRORLOG;

// dummy version and subsection values.
const   errlver_t       TEST_FILENAME_VER           =   1;
const   errlsubsec_t    TEST_FILENAME_SUBSECT       =   4;
const   errlver_t       TEST_STACKDUMP_VER          =   2;
const   errlsubsec_t    TEST_STACKDUMP_SUBSECT      =   5;


/**
 * Declare a test UserDetails derived class to post a filename string to
 * the errorlog
 * This is just for test purposes, it will not show up in production code.
 */
class TestFilename : public ErrlUserDetails
{
public:

    TestFilename(const char *i_filename)
    {
        iv_CompId     = ERRL_COMP_ID;
        iv_Version    = TEST_FILENAME_VER;
        iv_SubSection = TEST_FILENAME_SUBSECT;

        // Store the string in the internal buffer
        char * l_pString = (char *)allocUsrBuf( strlen(i_filename)+1 );
        strcpy(l_pString, i_filename );
    }

    /**
     *  @brief Destructor
     *
     */
    virtual ~TestFilename() {}

private:

    // Disabled
    TestFilename(const TestFilename &);
    TestFilename & operator=(const TestFilename &);
};

/**
 * Declare a test User Details "StackDump" class to store an array of (32-bit)
 * Stack Addresses.  the first 32-bit number will be the number of following
 * Stack Addresses.
 *
 *  This is just a test program, it will not be used in production code.
 *  64-bit stack addrs will need other support
 */
class TestStackDump : public ErrlUserDetails
{
public:


    TestStackDump( const uint64_t i_numAddrs,  const uint64_t * i_paddrs )
    {

        iv_CompId     = ERRL_COMP_ID;
        iv_Version    = TEST_STACKDUMP_VER;
        iv_SubSection = TEST_STACKDUMP_SUBSECT;

        // allocUsrBuf returns a buffer of uint8_t
        uint64_t *l_pList   =
                reinterpret_cast<uint64_t *>( allocUsrBuf( (i_numAddrs+1)*sizeof(void*) ) );

        l_pList[0]  =   i_numAddrs;
        for (uint64_t i=0; i<i_numAddrs; i++ )
        {
            l_pList[i+1]    =   i_paddrs[i];
        }
    }

    /**
     *  @brief Destructor
     *
     */
    virtual ~TestStackDump() {}

private:

    // Disabled
    TestStackDump(const TestStackDump &);
    TestStackDump & operator=(const TestStackDump &);
};




//
//  begin actual test code..
//
class UtilErrlUsrDataTest: public CxxTest::TestSuite
{
public:

    /**
     * @test testFILENAME - create a simple UD section in the errorlog that
     *  stores a filename string
     */
    void testFILENAME(void)
    {
        errlHndl_t  l_errl      =   NULL;

        TS_TRACE( "testFILENAME user data buffer for errorlog");

        l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                TEST_MOD_ID,
                ERRL_COMP_ID | 0x55,        //  compid/reasoncode
                0x1234567890,               //  user1
                0x9876543210 );             //  user2
        if( l_errl   ==   NULL )
        {
            TS_FAIL("Could not create errlog.\n");
            return;
        }

        // create the filename userdata object
        //
        TestFilename l_FN_userdata( "foobar.txt" );

        //  Add filename user data block to errorlog.  this should add
        //  the original constructor string, and the second string passed
        //  in here.
        const   char  testfnstr1[]   =   "secondfilename.txt";
        l_FN_userdata.addToLog( l_errl, testfnstr1, sizeof(testfnstr1) );


        //
        // Add another string.
        //
        const   char  testfnstr2[]   =   "thirdfilename.txt";
        l_FN_userdata.addToLog( l_errl, testfnstr2, sizeof(testfnstr2) );

        // commit the errorlog
        errlCommit(l_errl );

        //  Maybe do some stuff here to find the committed errorlog back and
        //  see if it is still correct?  Later.

    }

    /**
     * @test    testStackDump - dump a User Data section of a stackdump.
     *
     * first 32-bit entry is the # of following 32-bit addresses, followed
     * by the list of addresses.
     *
     */
    void testStackDump(void)
    {
        errlHndl_t  l_errl      =   NULL;
        uint64_t    l_addrs[]   =
        {
                0x01234567,
                0xDEADBEEF,
                0x5555aaaa,
                0x69696969,
                0x34920781,
                0xaaaa5555,
                0x68392090,
                0x95720856,
                0xabcdef01,
                0x12345670
        };

        TS_TRACE( "testStackDump add Userdata Section ot errorlog");


        l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                TEST_MOD_ID,
                ERRL_COMP_ID | 0x56,        //  compid/reasoncode
                0x0101010101,               //  user1
                0x0202020202 );             //  user2
        if( l_errl   ==   NULL )
        {
            TS_FAIL("Could not create errlog.\n");
            return;
        }

        TS_TRACE("Create Stackdump object. ");
        TestStackDump   l_stackDump(
                            (sizeof(l_addrs)/sizeof(uint64_t)),
                            &(l_addrs[0]) );

        TS_TRACE("run addToLog");
        l_stackDump.addToLog( l_errl  );

        errlCommit( l_errl );

    }

};



#endif

