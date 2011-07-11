/****************************************************************************
 * $IBMCopyrightBlock:
 * 
 *  IBM Confidential
 * 
 *  Licensed Internal Code Source Materials
 * 
 *  IBM HostBoot Licensed Internal Code
 * 
 *  (C) Copyright IBM Corp. 2011
 * 
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 * $
****************************************************************************/

#include <stdint.h>
/**
 * @brief global vars to keep track of unit tests,
 *
 * @see TestSuite.H and TestSuite.C
 *
 *  These are now also being used in the main code to record failed modules.
 *
 * @var g_TotalTests    -   initialized to 0, updated by reportTotalTests().
 *      Each test suite will call reporttotaltests after all tests have
 *      run with the total number of tests for that suite.
 *      Once all the testsuites have run, the global totaltests will hold
 *      the total of number of unit tests for that run.
 *
 *      Each unit test macro (TS_TRACE, TS_WARN, and TS_FAIL) will update
 *      the proper variable.  At the end the unit tester will print out
 *      the totals.
 *
 * @var g_TraceCalls    -   updated by TS_TRACE macro
 *
 * @var g_Warnings      -   updated by TS_WARN macro
 *
 * @var g_FailedTests   -   updated by TS_FAIL macro in the unit test image.
 *  This variable is also used to allow a code in a binary image
 *  not containing the testcase modules to query the number of failed tests
 *
 */

namespace CxxTest
{

uint64_t        g_TotalTests      =     0;
uint64_t        g_TraceCalls      =     0;
uint64_t        g_Warnings        =     0;
uint64_t        g_FailedTests     =     0;

}

