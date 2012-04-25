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
        errlHndl_t errl = NULL;

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
        errl = new ErrlEntry(
                ERRL_SEV_INFORMATIONAL,
                HBERRL_USERDATA_TEST_MOD_ID,
                HBERRL_TEST_STRING_UD,
                0x1234567890,                   //  user1
                0x9876543210 );                 //  user2

        // Create a test string and add it to the error log as user detail data
        const char * l_pString = "This is a test string";
        ErrlUserDetailsString(l_pString).addToLog(errl);

        // create more and make sure that they get merged into 1 sub-section
        ErrlUserDetailsString("String test - string 2").addToLog(errl);

        ErrlUserDetailsString stringUD("String test - string 3");
        stringUD.addToLog(errl);

        // commit the errorlog
        errlCommit(errl, CXXTEST_COMP_ID);
    }

    /**
     * @test testAttribute - Capture a String in an error log
     */
    void testAttribute(void)
    {
        errlHndl_t errl = NULL;

        TS_TRACE( "testAttribute errorlog user detail data and merge");
        /*@
        * @errortype
        * @severity ERRORLOG_SEV_INFORMATIONAL
        * @moduleid HBERRL_USERDATA_TEST_MOD_ID
        * @reasoncode HBERRL_TEST_ATTRIBUTE_UD
        * @userdata1 Test data 1
        * @userdata2 Test data 2
        * @devdesc  User Details unit test - create string user detail data
        */
        errl = new ErrlEntry(
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
        ErrlUserDetailsTarget(c_target).addToLog(errl);
        ErrlUserDetailsTarget(
            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL).addToLog(errl);

        // all attributes
        ErrlUserDetailsAttribute(c_target).addToLog(errl);

        // HUID repeated for each addToLog()
        ErrlUserDetailsAttribute(c_target,ATTR_EC).addToLog(errl);
        ErrlUserDetailsAttribute(c_target,ATTR_CHIP_ID).addToLog(errl);

        // 1 HUID only
        ErrlUserDetailsAttribute(c_target,ATTR_HUID).addToLog(errl);

        // HUID only - not there
        ErrlUserDetailsAttribute(c_target,ATTR_SCRATCH_UINT8_1).addToLog(errl);

        // HUID only - write only
        ErrlUserDetailsAttribute(c_target,ATTR_DUMMY_WO).addToLog(errl);

        // HUID only - read only
        ErrlUserDetailsAttribute(c_target,ATTR_CLASS).addToLog(errl);

        //
        // one HUID then each attribute
        ErrlUserDetailsAttribute pProcEUDA(c_target,ATTR_CHIP_ID);
        pProcEUDA.addData(ATTR_EC);
        pProcEUDA.addData(ATTR_CHIP_ID);

        // skipped - not there
        pProcEUDA.addData(ATTR_SCRATCH_UINT8_1);

        // skipped - write only
        pProcEUDA.addData(ATTR_DUMMY_WO);

        // skipped - read only
        pProcEUDA.addData(ATTR_CLASS);

        // done - write it out
        pProcEUDA.addToLog(errl);

        c_target = *pMembuf;
        TS_TRACE( "testAttribute pMembuf %p", c_target);
        ErrlUserDetailsTarget(c_target).addToLog(errl);

        // all attributes
        ErrlUserDetailsAttribute(c_target).addToLog(errl);

        // one HUID then each attribute
        ErrlUserDetailsAttribute pMembufEUDA(c_target,ATTR_CHIP_ID);
        pMembufEUDA.addData(ATTR_EC);
        pMembufEUDA.addData(ATTR_CHIP_ID);
        pMembufEUDA.addData(ATTR_MSS_VOLT);
        pMembufEUDA.addData(ATTR_MSS_FREQ);

        // skipped - not there
        pMembufEUDA.addData(ATTR_SCRATCH_UINT8_1);

        // skipped - write only
        pMembufEUDA.addData(ATTR_DUMMY_WO);

        // skipped - read only
        pMembufEUDA.addData(ATTR_CLASS);

        // done - write it out
        pMembufEUDA.addToLog(errl);

        c_target = *pDimm;
        TS_TRACE( "testAttribute pDimm %p", c_target);
        ErrlUserDetailsTarget(c_target).addToLog(errl);

        // all attributes
        ErrlUserDetailsAttribute(c_target).addToLog(errl);

        // one HUID then each attribute
        ErrlUserDetailsAttribute pDimmEUDA(c_target,ATTR_CHIP_ID);
        pDimmEUDA.addData(ATTR_EC);
        pDimmEUDA.addData(ATTR_CHIP_ID);
        pDimmEUDA.addData(ATTR_MSS_VOLT);
        pDimmEUDA.addData(ATTR_MSS_FREQ);

        // skipped - not there
        pDimmEUDA.addData(ATTR_SCRATCH_UINT8_1);

        // skipped - write only
        pDimmEUDA.addData(ATTR_DUMMY_WO);

        // skipped - read only
        pDimmEUDA.addData(ATTR_CLASS);

        // done - write it out
        pDimmEUDA.addToLog(errl);

#if 1
        // extended test
        uint32_t i = 0;
        for (TargetIterator target = targetService().begin();
            (i < 10) && (target != targetService().end());
            ++i, ++target)
        {
            TS_TRACE( "testAttribute %p", *target);
            const Target* c_target = *target;
            ErrlUserDetailsTarget(c_target).addToLog(errl);
            ErrlUserDetailsAttribute(c_target).addToLog(errl);
        }
#endif

        // commit the errorlog
        errlCommit(errl, CXXTEST_COMP_ID);
        TS_TRACE( "testAttribute done");
    }

};

#endif

