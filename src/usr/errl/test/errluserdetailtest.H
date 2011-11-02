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
 *  @brief Test user data plugins for errorlog.
 *
 */

#include    <cxxtest/TestSuite.H>
#include    <errl/errlentry.H>
#include    <errl/errluserdetails.H>
#include    <errl/errlreasoncodes.H>

using   namespace   ERRORLOG;


enum
{
    UTIL_COMP_ID                = 0x8A00,

};
// Subsection values, copied from FIPS.
enum
{
    UTIL_UDT_STREAM_PERC        = 0x0001,///< Perc Data for Streams
    UTIL_UDT_MEM_ALLOC          = 0x0002,///< Memory Allocation Failure
    UTIL_UDT_REG_KEYS           = 0x0003,///< Registry key name, with data
    UTIL_UDT_FILENAME           = 0x0004,///< A null terminated filename
    UTIL_UDT_FLOCK              = 0x0005,///< An flock struct
    UTIL_UDT_SEMAPHORE          = 0x0006,///< A semaphore object
    UTIL_UDT_LIBNAME            = 0x0007,///< Name of the library
    UTIL_UDT_REG_DATA           = 0x0008,///< Payload data for UtilReg::write
    UTIL_UDT_ERR_MSG            = 0x0009,///< An error message string
    UTIL_UDT_INOTIFY_PATH       = 0x000a,///< The path name in error
    UTIL_UDT_XML_TOKEN          = 0x000b,///< The XML token in error
    //
    //  dummy one for Stackdump
    TEST_STACKDUMP_SUBSECT  = 0x0055   // dummy subsection # for stackdump
};


/**
 * Declare a test UserDetails derived class to post a filename string to
 * the errorlog.
 * These are canned routines that are handled by the errl tool.
 *
 * This is just for test purposes, it will not show up in production code.
 * The values for version and subsection should match the actual filename
 * UD section parser routing in the errl tool - you should see it parse it
 * correctly.
 */
class TestFilename : public ErrlUserDetails
{
public:

    TestFilename(const char *i_filename)
    {

        iv_CompId       = UTIL_COMP_ID;
        iv_Version    = 1;
        iv_SubSection = UTIL_UDT_FILENAME;

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
 * Declare a test UserDetails derived class to post an error message
 * filename string to the errorlog
 * These are canned routines that are handled by the errl tool.
 *
 * This is just for test purposes, it will not show up in production code.
 * The values for version and subsection should match the actual filename
 * UD section parser routing in the errl tool - you should see it parse it
 * correctly.
 */
class TestErrorMsg : public ErrlUserDetails
{
public:

    TestErrorMsg(const char *i_filename)
    {

        iv_CompId       = UTIL_COMP_ID;
        iv_Version    = 1;
        iv_SubSection = UTIL_UDT_ERR_MSG;

        // Store the string in the internal buffer
        char * l_pString = (char *)allocUsrBuf( strlen(i_filename)+1 );
        strcpy(l_pString, i_filename );
    }

    /**
     *  @brief Destructor
     *
     */
    virtual ~TestErrorMsg() {}

private:

    // Disabled
    TestErrorMsg(const TestErrorMsg &);
    TestErrorMsg & operator=(const TestErrorMsg &);
};

/**
 * Declare a test UserDetails derived class to post an XML token in error
 * to the errorlog
 * These are canned routines that are handled by the errl tool.
 *
 * This is just for test purposes, it will not show up in production code.
 * The values for version and subsection should match the actual filename
 * UD section parser routing in the errl tool - you should see it parse it
 * correctly.
 */
class TestXMLToken : public ErrlUserDetails
{
public:

    TestXMLToken(const char *i_filename)
    {

        iv_CompId       = UTIL_COMP_ID;
        iv_Version    = 1;
        iv_SubSection = UTIL_UDT_XML_TOKEN;

        // Store the string in the internal buffer
        char * l_pString = (char *)allocUsrBuf( strlen(i_filename)+1 );
        strcpy(l_pString, i_filename );
    }

    /**
     *  @brief Destructor
     *
     */
    virtual ~TestXMLToken() {}

private:

    // Disabled
    TestXMLToken(const TestXMLToken &);
    TestXMLToken & operator=(const TestXMLToken &);
};


//  --------------------------------------------------------------------------
//  begin actual test code..
//  --------------------------------------------------------------------------
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
        /*@
        * @errortype
        * @severity ERRORLOG_SEV_INFORMATIONAL
        * @moduleid ERRL_USERDETAILS_MODULE_ID
        * @reasoncode ERRL_FILENAME_TEST
        * @userdata1 <UNUSED>
        * @userdata2 <UNUSED>
        * @devdesc  User Details unit test - post a filename user data section
        */
        l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                ERRL_USERDETAILS_MODULE_ID,
                ERRL_FILENAME_TEST,             //  compid/reasoncode
                0x1234567890,                   //  user1
                0x9876543210 );                 //  user2
        if( l_errl   ==   NULL )
        {
            TS_FAIL("Could not create errlog.\n");
            return;
        }

        // create the filename userdata object
        TestFilename l_FN_userdata( "/path/to/myfile.txt" );

        //  Add filename user data block to errorlog.  this should add
        //  the original constructor string, and the second string passed
        //  in here.
        const   char  testfnstr1[]   =   "addedfilename.txt";
        l_FN_userdata.addToLog( l_errl, testfnstr1, sizeof(testfnstr1) );

        //
        // Add another string.
        //
        const   char  testfnstr2[]   =   "thirdfilename.txt";
        l_FN_userdata.addToLog( l_errl, testfnstr2, sizeof(testfnstr2) );

        // commit the errorlog
        errlCommit(l_errl, ERRL_COMP_ID );

        //  Maybe do some stuff here to find the committed errorlog back and
        //  see if it is still correct?  Later.

    }

    /**
     * @test testErrorMsg - create a simple UD section in the errorlog
     * that stores an error message
     */
    void testErrorMsg(void)
    {
        errlHndl_t  l_errl      =   NULL;

        TS_TRACE( "testErrorMsg user data buffer for errorlog");
        /*@
        * @errortype
        * @severity ERRORLOG_SEV_INFORMATIONAL
        * @moduleid ERRL_USERDETAILS_MODULE_ID
        * @reasoncode ERRL_ERRORMSG_TEST
        * @userdata1 <UNUSED>
        * @userdata2 <UNUSED>
        * @devdesc  User Details unit test - post an error message in a
        * user data section
        */
        l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                ERRL_USERDETAILS_MODULE_ID,
                ERRL_ERRORMSG_TEST,             //  compid/reasoncode
                0x1212121212,                   //  user1
                0x3434343434 );                 //  user2
        if( l_errl   ==   NULL )
        {
            TS_FAIL("Could not create errlog.\n");
            return;
        }

        // create the filename userdata object
        TestErrorMsg l_userdata( "The UserData library has failed to fail." );

        // add it to the log
        l_userdata.addToLog( l_errl );

        // commit the errorlog
        errlCommit(l_errl, ERRL_COMP_ID );

    }

    /**
     * @test testXMLToken - create a simple UD section in the errorlog
     * that stores the name of an xml token in error.
     */
    void testXMLToken(void)
    {
        errlHndl_t  l_errl      =   NULL;

        TS_TRACE( "testXMLToken user data buffer for errorlog");
        /*@
        * @errortype
        * @severity ERRORLOG_SEV_INFORMATIONAL
        * @moduleid ERRL_USERDETAILS_MODULE_ID
        * @reasoncode ERRL_XMLTOKEN_TEST
        * @userdata1 <UNUSED>
        * @userdata2 <UNUSED>
        * @devdesc  User Details unit test - post an XML token in error as
        * a user data section
        */
        l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                ERRL_USERDETAILS_MODULE_ID,
                ERRL_XMLTOKEN_TEST,             //  compid/reasoncode
                0xa5a5a5a5a5,                   //  user1
                0xd2d2d2d2d2 );                 //  user2
        if( l_errl   ==   NULL )
        {
            TS_FAIL("Could not create errlog.\n");
            return;
        }

        // create the filename userdata object
        TestXMLToken l_userdata( "HWAS_STATE" );

        // add it to the log
         l_userdata.addToLog( l_errl );

        // commit the errorlog
        errlCommit( l_errl, ERRL_COMP_ID );

    }

};

#endif

