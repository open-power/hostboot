/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/pore/test/poretest.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __PORETEST_H
#define __PORETEST_H

/**
 *  @file poretest.H
 *
 *  @brief Test case for POREVE code
*/

#include <vector>
#include <cxxtest/TestSuite.H>
#include <targeting/common/commontargeting.H>
#include <fapiPoreVeArg.H>
#include <fapiTarget.H>
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>
#include <vfs/vfs.H>
#include <errl/errlmanager.H>

#define CENTAUR_SBE_PNOR_MRR    0     // Memory Relocation Register for Centaur


using namespace TARGETING;
using namespace vsbe;
extern fapi::ReturnCode fapiPoreVe(const fapi::Target i_target,
                   std::vector<FapiPoreVeArg *> & io_sharedObjectArgs);

class PoreTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief PORE test #2
     *        Run a sample procedure on Proc
     */
    void testPore2(void)
    {
        // @todo - Add code to run sbe image from Proc when available

        return;
    }

};

#endif
