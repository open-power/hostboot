/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/hwasGardTest.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef _HWASGARDTEST_H
#define _HWASGARDTEST_H

/**
 *  @file hwasGardTest.H
 *
 *  @brief Unit tests for HWAS Deconfigure and GARD functionality
 */

//******************************************************************************
// Includes
//******************************************************************************

// CXXTEST
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas_reasoncodes.H>

using namespace HWAS;
using namespace TARGETING;

class HwasGardTest: public CxxTest::TestSuite
{
public:

    /**
     *  @brief Test creating and getting a Deconfigure Record for a
     *      specific Target
     */
    void testDeconfigure2()
    {
        TS_TRACE(INFO_MRK "testDeconfigure2: Started");

        errlHndl_t l_pErr = NULL;
        DeconfigGard::DeconfigureRecords_t l_records;

        do
        {
            // confirm that there aren't any deconfigure records - if so exit
            l_pErr = theDeconfigGard().
                        _getDeconfigureRecords(NULL, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,HWAS_COMP_ID);
                TS_FAIL("testDeconfigure2: Error from _getDeconfigureRecords");
                break;
            }
            if (l_records.size() > 0)
            {
                TS_TRACE("testDeconfigure2: Existing records (%d); exiting",
                        l_records.size());
                 break;
            }

            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testDeconfigure3a: empty pExList");
                break;
            }
            TargetHandle_t l_pTarget = *pExList.begin();

            // create a deconfigure record
            theDeconfigGard().
                    registerDeferredDeconfigure(*l_pTarget, 0x12);

            // Get that Deconfigure Record for the target
            l_pErr = theDeconfigGard().
                    _getDeconfigureRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                errlCommit(l_pErr,HWAS_COMP_ID);
                TS_FAIL("testDeconfigure2: Error from _getDeconfigureRecords");
                break;
            }
            if (l_records.size() > 1)
            {
                TS_FAIL("testDeconfigure2: %d records for target",
                        l_records.size());
                break;
            }

            TS_TRACE(INFO_MRK "testDeconfigure2: Success. %d record",
                         l_records.size());

            // now delete it.
            theDeconfigGard().clearDeconfigureRecords(l_pTarget);

            // confirm that there aren't any deconfigure records - if so exit
            l_pErr = theDeconfigGard().
                        _getDeconfigureRecords(NULL, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,HWAS_COMP_ID);
                TS_FAIL("testDeconfigure2: Error from _getDeconfigureRecords");
                break;
            }

            if (l_records.size() > 0)
            {
                TS_TRACE("testDeconfigure2: Existing records (%d); exiting",
                        l_records.size());
                 break;
            }
        }
        while (0);
    }

    /**
     *  @brief Test Deconfiguring a Target directly
     */
    void testDeconfigure3()
    {
        TS_TRACE(INFO_MRK "testDeconfigure3: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;

        do
        {
            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testDeconfigure3: empty pExList");
                break;
            }
            TargetHandle_t l_pTarget = *pExList.begin();

            // Get the original HWAS_STATE of the target
            HwasState l_origState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            // Deconfigure the target.
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0x12);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure3: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE of the target
            HwasState l_state = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            if (l_state.functional)
            {
                TS_FAIL("testDeconfigure3: target functional after deconfigure");
                break;
            }

            // Reset the HWAS_STATE of the target
            l_pTarget->setAttr<ATTR_HWAS_STATE>(l_origState);

            TS_TRACE(INFO_MRK "testDeconfigure3: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test Deconfiguring a Target multiple times directly
     */
    void testDeconfigure4()
    {
        TS_TRACE(INFO_MRK "testDeconfigure4: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;

        do
        {
            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testDeconfigure4: empty pExList");
                break;
            }
            TargetHandle_t l_pTarget = *pExList.begin();

            // Get the current HWAS_STATE of the target
            HwasState l_origState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            // Deconfigure the target.
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0xA);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure4: Error from deconfigureTarget");
                break;
            }

            // Deconfigure the target again
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0xB);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure4: Error from 2nd deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE of the target
            HwasState l_state = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            if (l_state.functional)
            {
                TS_FAIL("testDeconfigure4: target functional after deconfigure");
                break;
            }

            // Reset the HWAS_STATE of the target
            l_pTarget->setAttr<ATTR_HWAS_STATE>(l_origState);

            TS_TRACE(INFO_MRK "testDeconfigure4: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc1()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssoc1: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;

        do
        {
            // find an MBA
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predMba(CLASS_UNIT, TYPE_MBA);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predMba).push(&predFunctional).And();
            TargetHandleList pMba;
            targetService().getAssociated( pMba, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pMba.empty())
            {
                TS_FAIL("testDeconfigureAssoc1: empty pMba");
                break;
            }
            //TargetHandle_t l_pTarget = *pMba.begin();
            TargetHandle_t l_pTarget = pMba[pMba.size()-1];

            // Get the original HWAS_STATE of the target
            HwasState l_origState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            // Deconfigure the target.
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0xA101);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigureAssoc1: Error from deconfigureTarget");
                break;
            }

            l_pTarget = pMba[1];

            // Deconfigure the target.
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0xA102);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigureAssoc1: Error from deconfigureTarget");
                break;
            }
            // Get the new HWAS_STATE of the target
            HwasState l_state = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            if (l_state.functional)
            {
                TS_FAIL("testDeconfigureAssoc1: target functional after deconfigure");
                break;
            }

            // Reset the HWAS_STATE of the target
            l_pTarget->setAttr<ATTR_HWAS_STATE>(l_origState);

            TS_TRACE(INFO_MRK "testDeconfigureAssoc1: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc2()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssoc2: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;

        do
        {
            // find an MEMBUF
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predMembuf(CLASS_CHIP, TYPE_MEMBUF);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predMembuf).push(&predFunctional).And();
            TargetHandleList pMembuf;
            targetService().getAssociated( pMembuf, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pMembuf.empty())
            {
                TS_FAIL("testDeconfigureAssoc2: empty pMembuf");
                break;
            }
            TargetHandle_t l_pTarget = *pMembuf.begin();

            // Get the original HWAS_STATE of the target
            HwasState l_origState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            // Deconfigure the target.
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0xA2);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigureAssoc2: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE of the target
            HwasState l_state = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            if (l_state.functional)
            {
                TS_FAIL("testDeconfigureAssoc2: target functional after deconfigure");
                break;
            }

            // Reset the HWAS_STATE of the target
            l_pTarget->setAttr<ATTR_HWAS_STATE>(l_origState);

            TS_TRACE(INFO_MRK "testDeconfigureAssoc2: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc3()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssoc3: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;

        do
        {
            // find an DIMM
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predDimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predDimm).push(&predFunctional).And();
            TargetHandleList pDimm;
            targetService().getAssociated( pDimm, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pDimm.empty())
            {
                TS_FAIL("testDeconfigureAssoc3: empty pDimm");
                break;
            }
            TargetHandle_t l_pTarget = *pDimm.begin();

            // Get the original HWAS_STATE of the target
            HwasState l_origState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            // Deconfigure the target.
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0xA3);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigureAssoc3: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE of the target
            HwasState l_state = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            if (l_state.functional)
            {
                TS_FAIL("testDeconfigureAssoc3: target functional after deconfigure");
                break;
            }

            // Reset the HWAS_STATE of the target
            l_pTarget->setAttr<ATTR_HWAS_STATE>(l_origState);

            TS_TRACE(INFO_MRK "testDeconfigureAssoc3: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }
    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc4()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssoc4: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;

        do
        {
            // find an MCS
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predMcs(CLASS_UNIT, TYPE_MCS);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predMcs).push(&predFunctional).And();
            TargetHandleList pMcs;
            targetService().getAssociated( pMcs, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pMcs.empty())
            {
                TS_FAIL("testDeconfigureAssoc4: empty pMcs");
                break;
            }
            TargetHandle_t l_pTarget = *pMcs.begin();

            // Get the original HWAS_STATE of the target
            HwasState l_origState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            // Deconfigure the target.
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0xA4);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigureAssoc4: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE of the target
            HwasState l_state = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            if (l_state.functional)
            {
                TS_FAIL("testDeconfigureAssoc4: target functional after deconfigure");
                break;
            }

            // Reset the HWAS_STATE of the target
            l_pTarget->setAttr<ATTR_HWAS_STATE>(l_origState);

            TS_TRACE(INFO_MRK "testDeconfigureAssoc4: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test Deconfiguring a Target via deferred
     */
    void testDefDeconfig1()
    {
        TS_TRACE(INFO_MRK "testDefDeconfig1: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;
        DeconfigGard::DeconfigureRecords_t l_records;

        do
        {
            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testDefDeconfig1: empty pExList");
                break;
            }
            TargetHandle_t l_pTarget = *pExList.begin();

            // Get any existing Deconfigure Record for the target
            l_pErr = theDeconfigGard().
                    _getDeconfigureRecords(l_pTarget, l_records);
            if (l_pErr)
            {
                TS_FAIL("testDefDeconfig1: Error from _getDeconfigureRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testDefDeconfig1: target has existing Deconfigure Record, skipping test");
                break;
            }

            // Get the original HWAS_STATE of the target
            HwasState l_origState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            // create a deconfigure record
            theDeconfigGard().
                    registerDeferredDeconfigure(*l_pTarget, 0x12);

            // call function to process deferred deconfigure records
            bool l_processed = processDeferredDeconfig();

            if (!l_processed)
            {
                TS_FAIL("testDefDeconfig1: processDeferredDeconfig found no work");
                break;
            }

            // Get the new HWAS_STATE of the target
            HwasState l_state = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            if (l_state.functional)
            {
                TS_FAIL("testDefDeconfig1: target functional after deconfigure");
                // intentionally continue
            }

            // Try to get the Deconfigure Record for the target
            l_pErr = theDeconfigGard().
                    _getDeconfigureRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testDefDeconfig1: Error from _getDeconfigureRecords (2)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testDefDeconfig1: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            // Reset the HWAS_STATE of the target
            l_pTarget->setAttr<ATTR_HWAS_STATE>(l_origState);

            TS_TRACE(INFO_MRK "testDefDeconfig1: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test getting all GARD Records
     */
    void testGard1()
    {
        TS_TRACE(INFO_MRK "testGard1: Started");

        errlHndl_t l_pErr = NULL;
        DeconfigGard::GardRecords_t l_records;

        l_pErr = theDeconfigGard().getGardRecords(NULL, l_records);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
            TS_FAIL("testGard1: Error from getGardRecords(NULL)");
        }
        else
        {
            TS_TRACE(INFO_MRK "testGard1: get(NULL) Success. %d records",
                     l_records.size());
        }
    }

    /**
     *  @brief Test creating a GARD Record, getting the GARD Record and
     *         clearing the GARD Record
     */
    void testGard4()
    {
        TS_TRACE(INFO_MRK "testGard4: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testGard4: empty pExList");
                break;
            }
            TargetHandle_t l_pTarget = *pExList.begin();

            // Get any existing GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);
            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from getGardRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testGard4: target has %d existing Gard Records, skipping test",
                         l_records.size());
                break;
            }

            // Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    createGardRecord(l_pTarget, 0x12, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from createGardRecord");
                break;
            }

            // Get the GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from getGardRecords (2)");
                break;
            }

            if (l_records.size() != 1)
            {
                TS_FAIL("testGard4: %d records for target, expected 1",
                        l_records.size());
                break;
            }

            if (l_records[0].iv_errorType != GARD_Predictive)
            {
                TS_FAIL("testGard4: Record errorType %d, expected predictive",
                        l_records[0].iv_errorType);
                break;
            }

            // Clear the GARD Records for the target
            l_pErr = theDeconfigGard().clearGardRecords(l_pTarget);

            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from clearGardRecords");
                break;
            }

            // Get the GARD Records for the target
            l_records.clear();

            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from getGardRecords (3)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testGard4: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            TS_TRACE(INFO_MRK "testGard4: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test creating a GARD Record for a Target multiple times
     */
    void testGard5()
    {
        TS_TRACE(INFO_MRK "testGard5: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testGard5: empty pExList");
                break;
            }
            TargetHandle_t l_pTarget = *pExList.begin();

            // Get any existing GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from getGardRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testGard5: target has %d existing Gard Records, skipping test",
                         l_records.size());
                break;
            }

            // Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    createGardRecord(l_pTarget, 0x23, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from createGardRecord");
                break;
            }

            // Create another GARD Record for the target
            l_pErr = theDeconfigGard().
                    createGardRecord(l_pTarget, 0x45, GARD_Fatal);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from createGardRecord (2)");
                break;
            }

            // Get the GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from getGardRecords (2)");
                break;
            }

            if (l_records.size() != 1)
            {
                TS_FAIL("testGard5: %d records for target, expected 1",
                        l_records.size());
                break;
            }

            // Clear the GARD Record for the target
            l_pErr = theDeconfigGard().clearGardRecords(l_pTarget);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from clearGardRecords");
                break;
            }

            // Get the GARD Records for the target
            l_records.clear();

            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from getGardRecords (3)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testGard5: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            TS_TRACE(INFO_MRK "testGard5: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test creating a 2nd GARD Record overwrites manual gard
     */
    void testGard6()
    {
        TS_TRACE(INFO_MRK "testGard6: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testGard6: empty pExList");
                break;
            }
            TargetHandle_t l_pTarget = *pExList.begin();

            // Get any existing GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from getGardRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testGard6: target has %d existing Gard Records, skipping test",
                         l_records.size());
                break;
            }

            // Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    createGardRecord(l_pTarget, 0x23, GARD_User_Manual);

            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from createGardRecord");
                break;
            }

            // Create another GARD Record for the target - should overwrite
            l_pErr = theDeconfigGard().
                    createGardRecord(l_pTarget, 0x46, GARD_Fatal);

            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from createGardRecord (2)");
                break;
            }

            // Get the GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from getGardRecords (2)");
                break;
            }

            if (l_records.size() != 1)
            {
                TS_FAIL("testGard6: %d records for target, expected 1",
                        l_records.size());
                break;
            }

            if ((l_records[0].iv_errlogPlid != 0x46) ||
                (l_records[0].iv_errorType != GARD_Fatal))
            {
                TS_FAIL("testGard6: unexpected data - errl 0x%X type %x",
                    l_records[0].iv_errlogPlid, l_records[0].iv_errorType);
                break;
            }

            // Clear the GARD Record for the target
            l_pErr = theDeconfigGard().clearGardRecords(l_pTarget);

            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from clearGardRecords");
                break;
            }

            // Get the GARD Records for the target
            l_records.clear();

            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from getGardRecords (3)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testGard6: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            TS_TRACE(INFO_MRK "testGard6: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test getting and clearing all GARD Records
     */
    void testGard7()
    {
        TS_TRACE(INFO_MRK "testGard7: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testGard7: empty pExList");
                break;
            }
            TargetHandle_t l_pTarget = *pExList.begin();

            // Get all existing GARD Records
            l_pErr = theDeconfigGard().getGardRecords(NULL, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from getGardRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testGard7: %d existing Gard Records, skipping test",
                         l_records.size());
                break;
            }

            // Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    createGardRecord(l_pTarget, 0x71, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from createGardRecord");
                break;
            }

            // Clear all GARD Records
            l_pErr = theDeconfigGard().clearGardRecords(NULL);

            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from clearGardRecords(NULL)");
                break;
            }

            // Get the GARD Records
            l_records.clear();

            l_pErr = theDeconfigGard().getGardRecords(NULL, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from getGardRecords (2)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testGard7: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            TS_TRACE(INFO_MRK "testGard7: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test create GARD record, call collect GARD to confirm targets
     *      are deconfigured, set changed bit ala HCDB, reprocess GARD to
     *      confirm GARD record is deleted.
     */
    void testGard8()
    {
        TS_TRACE(INFO_MRK "testGard8: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else
        errlHndl_t l_pErr = NULL;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            l_pErr = theDeconfigGard().getGardRecords(NULL, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,HWAS_COMP_ID);
                TS_FAIL("testGard8: Error from getGardRecords");
                break;
            }

            if (l_records.size() > 0)
            {
                TS_FAIL("testGard8: already GARD records here. %d records",
                        l_records.size());
                break;
            }

            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();

            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testGard8: empty pExList");
                break;
            }

            TargetHandle_t l_target = *pExList.begin();

            // create GARD record, call 'doGard' step and confirm target is
            //  deconfigured
            l_pErr = theDeconfigGard().
                    createGardRecord(l_target, 0x12, GARD_User_Manual);
            if (l_pErr)
            {
                TS_FAIL("testGard8: Error from createGardRecord");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(NULL, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,HWAS_COMP_ID);
                TS_FAIL("testGard8: Error from getGardRecords");
                break;
            }
            if (l_records.size() != 1)
            {
                TS_FAIL("testGard8: should be 1 record; instead %d records",
                        l_records.size());
                break;
            }

            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard8: Error from collectGard");
                break;
            }

            HwasState l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            if (l_state.functional)
            {
                TS_FAIL("testGard8: target still functional");
                break;
            }

            // reset functional state
            l_state.functional = true;
            l_target->setAttr<ATTR_HWAS_STATE>(l_state);

            // emulate HCDB - target changed, call collectGard and confirm
            //  GARD record is gone and target is functional
            update_hwas_changed_mask(l_target);
            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard8: Error from collectGard2");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(NULL, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,HWAS_COMP_ID);
                TS_FAIL("testGard8: Error from getGardRecords");
                break;
            }
            if (l_records.size() != 0)
            {
                TS_FAIL("testGard8: should be 0 records; instead %d records",
                        l_records.size());
                break;
            }

            l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testGard8: target NOT functional");
                break;
            }

            TS_TRACE(INFO_MRK "testGard8: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test CDM modes to restrict createing GARD records
     */
    void testGard9()
    {
        TS_TRACE(INFO_MRK "testGard9: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();
            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testGard9: empty pExList");
                break;
            }
            TargetHandle_t l_pTarget = *pExList.begin();

            // Get any existing GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from getGardRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_TRACE(INFO_MRK "testGard9: target has %d existing Gard Records, skipping test",
                         l_records.size());
                break;
            }

            // set Manufacturing policy to disabled,
            //  test that gard record is not created
            ATTR_CDM_POLICIES_type l_policies =
                pSys->getAttr<ATTR_CDM_POLICIES>();
            l_policies = CDM_POLICIES_MANUFACTURING_DISABLED;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            // (try to) Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    createGardRecord(l_pTarget, 0x12, GARD_Fatal);

            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from createGardRecord");
                break;
            }

            // Get the GARD Records for the target - shouldn't be any
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from getGardRecords (2)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testGard9: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            // set Predictive policy to disabled
            //  test that gard record isn't created
            l_policies = CDM_POLICIES_PREDICTIVE_DISABLED;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            // (try to) Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    createGardRecord(l_pTarget, 0x12, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from createGardRecord");
                break;
            }

            // Get the GARD Records for the target - shouldn't be any
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from getGardRecords (2)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testGard9: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            // set Functional policy to disabled
            //  test that gard record isn't created
            l_policies = CDM_POLICIES_FUNCTIONAL_DISABLED;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            // (try to) Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    createGardRecord(l_pTarget, 0x12, GARD_Func);

            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from createGardRecord");
                break;
            }

            // Get the GARD Records for the target - shouldn't be any
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from getGardRecords (2)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testGard9: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            // restore
            l_policies = 0;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);
            TS_TRACE(INFO_MRK "testGard9: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test CDM modes to restrict processing GARD records
     */
    void testGard10()
    {
        TS_TRACE(INFO_MRK "testGard10: Started");
#if 1
        // these tests deconfigure and gard targets. and even tho they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else
        errlHndl_t l_pErr = NULL;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            l_pErr = theDeconfigGard().getGardRecords(NULL, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,HWAS_COMP_ID);
                TS_FAIL("testGard10: Error from getGardRecords");
                break;
            }

            if (l_records.size() > 0)
            {
                TS_FAIL("testGard10: already GARD records here. %d records",
                        l_records.size());
                break;
            }

            // find a ex unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEx(CLASS_UNIT, TYPE_EX);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEx).push(&predFunctional).And();

            TargetHandleList pExList;
            targetService().getAssociated( pExList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pExList.empty())
            {
                TS_FAIL("testGard10: empty pExList");
                break;
            }

            TargetHandle_t l_target = *pExList.begin();

            // create GARD record, set Policy, call 'doGard' step and confirm
            //  target is NOT deconfigured
            l_pErr = theDeconfigGard().
                    createGardRecord(l_target, 0x12, GARD_Predictive);
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from createGardRecord");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(NULL, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,HWAS_COMP_ID);
                TS_FAIL("testGard10: Error from getGardRecords");
                break;
            }
            if (l_records.size() != 1)
            {
                TS_FAIL("testGard10: should be 1 record; instead %d records",
                        l_records.size());
                break;
            }

            // set Manufacturing policy to disabled,
            //  test that gard record is not created
            ATTR_CDM_POLICIES_type l_policies =
                pSys->getAttr<ATTR_CDM_POLICIES>();
            l_policies = CDM_POLICIES_MANUFACTURING_DISABLED;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from collectGard");
                break;
            }

            HwasState l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testGard10: target NOT functional");
                break;
            }

            // set Predictive policy to disabled,
            //  test that gard record is not created
            l_policies = CDM_POLICIES_PREDICTIVE_DISABLED;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from collectGard");
                break;
            }

            l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testGard10: target NOT functional");
                break;
            }

            // Clear all GARD Records
            l_pErr = theDeconfigGard().clearGardRecords(NULL);
            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from clearGardRecords(NULL)");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(NULL, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,HWAS_COMP_ID);
                TS_FAIL("testGard10: Error from getGardRecords");
                break;
            }
            if (l_records.size() != 0)
            {
                TS_FAIL("testGard10: should be 0 records; instead %d records",
                        l_records.size());
                break;
            }

            // create GARD record, set Policy, call 'doGard' step and confirm
            //  target is NOT deconfigured
            l_pErr = theDeconfigGard().
                    createGardRecord(l_target, 0x12, GARD_Func);
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from createGardRecord");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(NULL, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,HWAS_COMP_ID);
                TS_FAIL("testGard10: Error from getGardRecords");
                break;
            }
            if (l_records.size() != 1)
            {
                TS_FAIL("testGard10: should be 1 records; instead %d records",
                        l_records.size());
                break;
            }

            // set Functional policy to disabled,
            //  test that gard record is not created
            l_policies = CDM_POLICIES_FUNCTIONAL_DISABLED;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from collectGard");
                break;
            }

            l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testGard10: target NOT functional");
                break;
            }

            // Clear all GARD Records
            l_pErr = theDeconfigGard().clearGardRecords(NULL);
            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from clearGardRecords(NULL)");
                break;
            }

            // restore
            l_policies = 0;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);
            TS_TRACE(INFO_MRK "testGard10: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,HWAS_COMP_ID);
        }
#endif
    }

};

#endif
