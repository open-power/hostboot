//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/fsiscom/test/fsiscomtest.H $
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
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>
#include <limits.h>
#include <devicefw/driverif.H>


class FsiScomTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief test1
     */
    void test_fsiScom(void)
    {

        //FSISCOM testing driving by SCOM device driver.  This allows for testing FSISCOM <-> XSCOM
        //coherency.
    };
};
