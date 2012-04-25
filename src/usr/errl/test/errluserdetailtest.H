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

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errluserdetails.H>
#include <errl/errlreasoncodes.H>
#include <errl/errludstring.H>
#include <errl/errludbacktrace.H>
#include <errl/errludtarget.H>
#include <errludattribute.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/util.H>

using   namespace   ERRORLOG;

class UtilErrlUsrDataTest: public CxxTest::TestSuite
{
public:
    
    // Note that errlUserDetailsTarget is tested in the targeting unit test
    
    /**
     * @test testString - Capture a String in an error log
     */
    void testString(void)
    {
        errlHndl_t l_errl = NULL;

        TS_TRACE( "testString errorlog user detail data");
        /*@
        * @errortype
        * @severity ERRORLOG_SEV_INFORMATIONAL
        * @moduleid HBERRL_USERDATA_TEST_MOD_ID
        * @reasoncode HBERRL_TEST_STRING_UD
        * @userdata1 Test data 1
        * @userdata2 Test data 2
        * @devdesc  User Details unit test - create string user detail data
        */
        l_errl = new ErrlEntry(
                ERRL_SEV_INFORMATIONAL,
                HBERRL_USERDATA_TEST_MOD_ID,
                HBERRL_TEST_STRING_UD,
                0x1234567890,                   //  user1
                0x9876543210 );                 //  user2

        // Create a test string and add it to the error log as user detail data
        const char * l_pString = "This is a test string";
        ErrlUserDetailsString(l_pString).addToLog(l_errl);

        // commit the errorlog
        errlCommit(l_errl, CXXTEST_COMP_ID);
    }

    /**
     * @test testAttribute - Capture a String in an error log
     */
    void testAttribute(void)
    {
        errlHndl_t l_err = NULL;

        TS_TRACE( "testAttribute errorlog user detail data");
        /*@
        * @errortype
        * @severity ERRORLOG_SEV_INFORMATIONAL
        * @moduleid HBERRL_USERDATA_TEST_MOD_ID
        * @reasoncode HBERRL_TEST_ATTRIBUTE_UD
        * @userdata1 Test data 1
        * @userdata2 Test data 2
        * @devdesc  User Details unit test - create string user detail data
        */
        l_err = new ErrlEntry(
                ERRL_SEV_INFORMATIONAL,
                HBERRL_USERDATA_TEST_MOD_ID,
                HBERRL_TEST_ATTRIBUTE_UD,
                0x0001002300450067,
                0x008900AB00CD00EF);

        using namespace TARGETING;

        // find a proc target
        PredicateCTM procChipFilter(CLASS_CHIP,TYPE_PROC);
        TargetRangeFilter pProc(
            targetService().begin(), targetService().end(),
            &procChipFilter);

        // find a membuf target
        PredicateCTM membufChipFilter(CLASS_CHIP,TYPE_MEMBUF);
        TargetRangeFilter pMembuf(
            targetService().begin(), targetService().end(),
            &membufChipFilter);

        // find a dimm target
        PredicateCTM dimmChipFilter(CLASS_NA,TYPE_DIMM);
        TargetRangeFilter pDimm(
            targetService().begin(), targetService().end(),
            &dimmChipFilter);

        const Target* c_target;
        c_target = *pProc;
        TS_TRACE( "testAttribute pProc %p", c_target);
        ErrlUserDetailsString("Attribute test").addToLog(l_err);
        ErrlUserDetailsTarget(c_target).addToLog(l_err);
        ErrlUserDetailsBackTrace().addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_CLASS).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_TYPE).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_MODEL).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_PHYS_PATH).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_SCRATCH_UINT8_1).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_HUID).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_DUMMY_WO).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target).addToLog(l_err);

        c_target = *pMembuf;
        TS_TRACE( "testAttribute pMembuf %p", c_target);
        ErrlUserDetailsString("Attribute test").addToLog(l_err);
        ErrlUserDetailsTarget(c_target).addToLog(l_err);
        ErrlUserDetailsBackTrace().addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_CLASS).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_TYPE).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_MODEL).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_PHYS_PATH).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_SCRATCH_UINT8_1).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_HUID).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_DUMMY_WO).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target).addToLog(l_err);

        c_target = *pDimm;
        TS_TRACE( "testAttribute pDimm %p", c_target);
        ErrlUserDetailsString("Attribute test").addToLog(l_err);
        ErrlUserDetailsTarget(c_target).addToLog(l_err);
        ErrlUserDetailsBackTrace().addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_CLASS).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_TYPE).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_MODEL).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_PHYS_PATH).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_SCRATCH_UINT8_1).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_HUID).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target,ATTR_DUMMY_WO).addToLog(l_err);
        ErrlUserDetailsAttribute(c_target).addToLog(l_err);

#if 0
        // extended test 
        uint32_t i = 0;
        for (TargetIterator target = targetService().begin();
            (i < 10) && (target != targetService().end());
            ++i, ++target)
        {
            TS_TRACE( "testAttribute %p", *target);
            const Target* c_target = *target;
            ErrlUserDetailsTarget(c_target).addToLog(l_err);
            ErrlUserDetailsAttribute(c_target).addToLog(l_err);
        }
#endif

        // commit the errorlog
        errlCommit(l_err, CXXTEST_COMP_ID);
        TS_TRACE( "testAttribute done");
    }

};

#endif

