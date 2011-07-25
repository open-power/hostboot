#ifndef __PNORRPTEST_H
#define __PNORRPTEST_H

/**
 *  @file pnorrptest.H
 *
 *  @brief Test case for PNOR Resource Provider
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>
#include <pnor/pnorif.H>

extern trace_desc_t* g_trac_pnor;


class PnorRpTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief PNOR RP test #1
     *        Description
     */
    void testXX(void)
    {
    };

    //@todo - import config data from build and compare to section info
    //@todo - do read/modify/write/read to different virtual addresses
    //@todo - send messages to do read/write of individual pages

};     


#endif
