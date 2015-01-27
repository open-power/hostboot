/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/hwasGardTest.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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

bool compareAffinity(const TargetInfo t1, const TargetInfo t2)
{
        return t1.affinityPath < t2.affinityPath;
}

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
            bool l_targetDeconfigured = false;
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0x12, &l_targetDeconfigured);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure3: Error from deconfigureTarget");
                break;
            }
            if (l_targetDeconfigured == false)
            {
                TS_FAIL("testDeconfigure3: deconfigureTarget didn't set targetDeconfigured correctly");
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

            // get the current status/counter
            uint32_t l_origStatus = theDeconfigGard().getDeconfigureStatus();

            // Deconfigure the target.
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0xA);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigure4: Error from deconfigureTarget");
                break;
            }

            // confirm the counter changed
            if (l_origStatus == theDeconfigGard().getDeconfigureStatus())
            {
                TS_FAIL("testDeconfigure4: unchanged deconfigureStatus");
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

            // get the current status/counter
            uint32_t l_origStatus = theDeconfigGard().getDeconfigureStatus();

            // create a deconfigure record
            theDeconfigGard().
                    registerDeferredDeconfigure(*l_pTarget, 0x12);

            // confirm the counter changed
            if (l_origStatus == theDeconfigGard().getDeconfigureStatus())
            {
                TS_FAIL("testDefDeconfig1: unchanged deconfigureStatus");
            }

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
                    platCreateGardRecord(l_pTarget, 0x12, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from platCreateGardRecord");
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
                    platCreateGardRecord(l_pTarget, 0x23, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from platCreateGardRecord");
                break;
            }

            // Create another GARD Record for the target
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_pTarget, 0x45, GARD_Fatal);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from platCreateGardRecord (2)");
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
                    platCreateGardRecord(l_pTarget, 0x23, GARD_User_Manual);

            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from platCreateGardRecord");
                break;
            }

            // Create another GARD Record for the target - should overwrite
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_pTarget, 0x46, GARD_Fatal);

            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from platCreateGardRecord (2)");
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

            if ((l_records[0].iv_errlogEid != 0x46) ||
                (l_records[0].iv_errorType != GARD_Fatal))
            {
                TS_FAIL("testGard6: unexpected data - errl 0x%X type %x",
                    l_records[0].iv_errlogEid, l_records[0].iv_errorType);
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
                    platCreateGardRecord(l_pTarget, 0x71, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from platCreateGardRecord");
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
                    platCreateGardRecord(l_target, 0x12, GARD_User_Manual);
            if (l_pErr)
            {
                TS_FAIL("testGard8: Error from platCreateGardRecord");
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
                    platCreateGardRecord(l_pTarget, 0x12, GARD_Fatal);

            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from platCreateGardRecord");
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
                    platCreateGardRecord(l_pTarget, 0x12, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from platCreateGardRecord");
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
                    platCreateGardRecord(l_target, 0x12, GARD_Predictive);
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from platCreateGardRecord");
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
                TS_FAIL("testGard10: Error from clearGardRecords(NULL)");
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
                    platCreateGardRecord(l_target, 0x12, GARD_Predictive);
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from platCreateGardRecord");
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

            // Clear all GARD Records
            l_pErr = theDeconfigGard().clearGardRecords(NULL);
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from clearGardRecords(NULL)");
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


    /**
     *  @brief Test Deconfigure Associated Proc1
     */
    void testDeconfigureAssocProc1()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc1: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 1: TULETA 4 System with Master proc's abus1
        // and proc2 abus1 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_tuletaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_tuletaProcs.insert(l_tuletaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_tuletaProcs[0].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[0].procHUID = 0;                 // HUID
        l_tuletaProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_tuletaProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[0].iv_masterCapable = true;      // Master proc
        l_tuletaProcs[0].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        // abus1 and 2 linked to proc2
        l_tuletaProcs[0].iv_pAProcs[0] = &l_tuletaProcs[2];
        l_tuletaProcs[0].iv_pAProcs[1] = &l_tuletaProcs[2];
        // abus1 endpoint deconfigured
        l_tuletaProcs[0].iv_ADeconfigured[0] = true;
        // XBus links and states
        l_tuletaProcs[0].iv_pXProcs[0] = &l_tuletaProcs[1];

        // Proc1:
        l_tuletaProcs[1].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[1].procHUID = 1;                 // HUID
        l_tuletaProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_tuletaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[1].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[1].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[1].iv_pAProcs[0] = &l_tuletaProcs[3];
        l_tuletaProcs[1].iv_pAProcs[1] = &l_tuletaProcs[3];
        // XBus links and states
        l_tuletaProcs[1].iv_pXProcs[0] = &l_tuletaProcs[0];

        // Proc2:
        l_tuletaProcs[2].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[2].procHUID = 2;                 // HUID
        l_tuletaProcs[2].procFabricNode = 1;           // FABRIC_NODE_ID
        l_tuletaProcs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[2].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[2].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[2].iv_pAProcs[0] = &l_tuletaProcs[0];
        l_tuletaProcs[2].iv_pAProcs[1] = &l_tuletaProcs[0];
        l_tuletaProcs[2].iv_ADeconfigured[0] = true;
        // XBus links and states
        l_tuletaProcs[2].iv_pXProcs[0] = &l_tuletaProcs[3];

        // Proc3:
        l_tuletaProcs[3].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[3].procHUID = 3;                 // HUID
        l_tuletaProcs[3].procFabricNode = 1;           // FABRIC_NODE_ID
        l_tuletaProcs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[3].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[3].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[3].iv_pAProcs[0] = &l_tuletaProcs[1];
        l_tuletaProcs[3].iv_pAProcs[1] = &l_tuletaProcs[2];
        // XBus links and states
        l_tuletaProcs[3].iv_pXProcs[0] = &l_tuletaProcs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_tuletaProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_tuletaProcs[0].iv_deconfigured == false &&
            l_tuletaProcs[1].iv_deconfigured == false &&
            l_tuletaProcs[2].iv_deconfigured == true &&
            l_tuletaProcs[3].iv_deconfigured == true)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc1: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc1: incorrect configuration returned");
        }
    }


    /**
     *  @brief Test Deconfigure Associated Proc2
     */
    void testDeconfigureAssocProc2()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc2: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 2: TULETA 4 System with Master proc's xbus1
        // and proc3's xbus1 deconfigured, where the Master is
        // proc2

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_tuletaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_tuletaProcs.insert(l_tuletaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_tuletaProcs[0].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[0].procHUID = 0;                 // HUID
        l_tuletaProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_tuletaProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[0].iv_masterCapable = false;     // Note master proc
        l_tuletaProcs[0].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[0].iv_pAProcs[0] = &l_tuletaProcs[2];
        l_tuletaProcs[0].iv_pAProcs[1] = &l_tuletaProcs[2];
        // XBus links and states
        l_tuletaProcs[0].iv_pXProcs[0] = &l_tuletaProcs[1];

        // Proc1:
        l_tuletaProcs[1].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[1].procHUID = 1;                 // HUID
        l_tuletaProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_tuletaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[1].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[1].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[1].iv_pAProcs[0] = &l_tuletaProcs[3];
        l_tuletaProcs[1].iv_pAProcs[1] = &l_tuletaProcs[3];
        // XBus links and states
        l_tuletaProcs[1].iv_pXProcs[0] = &l_tuletaProcs[0];

        // Proc2:
        l_tuletaProcs[2].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[2].procHUID = 2;                 // HUID
        l_tuletaProcs[2].procFabricNode = 1;           // FABRIC_NODE_ID
        l_tuletaProcs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[2].iv_masterCapable = true;      // Master proc
        l_tuletaProcs[2].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[2].iv_pAProcs[0] = &l_tuletaProcs[0];
        l_tuletaProcs[2].iv_pAProcs[1] = &l_tuletaProcs[0];
        // XBus links and states
        l_tuletaProcs[2].iv_pXProcs[0] = &l_tuletaProcs[3];
        l_tuletaProcs[2].iv_XDeconfigured[0] = true;

        // Proc3:
        l_tuletaProcs[3].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[3].procHUID = 3;                 // HUID
        l_tuletaProcs[3].procFabricNode = 1;           // FABRIC_NODE_ID
        l_tuletaProcs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[3].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[3].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[3].iv_pAProcs[0] = &l_tuletaProcs[1];
        l_tuletaProcs[3].iv_pAProcs[1] = &l_tuletaProcs[1];
        // XBus links and states
        l_tuletaProcs[3].iv_pXProcs[0] = &l_tuletaProcs[2];
        l_tuletaProcs[3].iv_XDeconfigured[0] = true;

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_tuletaProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_tuletaProcs[0].iv_deconfigured == false &&
            l_tuletaProcs[1].iv_deconfigured == true &&
            l_tuletaProcs[2].iv_deconfigured == false &&
            l_tuletaProcs[3].iv_deconfigured == true)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc2: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc2: incorrect configuration returned");
        }
    }

    /**
     *  @brief Test Deconfigure Associated Proc3
     */
    void testDeconfigureAssocProc3()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc3: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 3: ORLENA System with Master and proc1's
        // xbus1 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 8;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_orlenaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_orlenaProcs.insert(l_orlenaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_orlenaProcs[0].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[0].procHUID = 0;                 // HUID
        l_orlenaProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_orlenaProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[0].iv_masterCapable = true;      // Master proc
        l_orlenaProcs[0].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[0].iv_pAProcs[0] = &l_orlenaProcs[2];
        l_orlenaProcs[0].iv_pAProcs[1] = &l_orlenaProcs[4];
        l_orlenaProcs[0].iv_pAProcs[2] = &l_orlenaProcs[6];
        // XBus links and states
        l_orlenaProcs[0].iv_pXProcs[0] = &l_orlenaProcs[1];
        l_orlenaProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_orlenaProcs[1].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[1].procHUID = 1;                 // HUID
        l_orlenaProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_orlenaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[1].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[1].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[1].iv_pAProcs[0] = &l_orlenaProcs[5];
        l_orlenaProcs[1].iv_pAProcs[1] = &l_orlenaProcs[7];
        l_orlenaProcs[1].iv_pAProcs[2] = &l_orlenaProcs[3];
        // XBus links and states
        l_orlenaProcs[1].iv_pXProcs[0] = &l_orlenaProcs[0];
        l_orlenaProcs[1].iv_XDeconfigured[0] = true;

        // Proc2:
        l_orlenaProcs[2].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[2].procHUID = 2;                 // HUID
        l_orlenaProcs[2].procFabricNode = 1;           // FABRIC_NODE_ID
        l_orlenaProcs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[2].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[2].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[2].iv_pAProcs[0] = &l_orlenaProcs[0];
        l_orlenaProcs[2].iv_pAProcs[1] = &l_orlenaProcs[6];
        l_orlenaProcs[2].iv_pAProcs[2] = &l_orlenaProcs[4];
        // XBus links and states
        l_orlenaProcs[2].iv_pXProcs[0] = &l_orlenaProcs[3];

        // Proc3:
        l_orlenaProcs[3].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[3].procHUID = 3;                 // HUID
        l_orlenaProcs[3].procFabricNode = 1;           // FABRIC_NODE_ID
        l_orlenaProcs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[3].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[3].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[3].iv_pAProcs[0] = &l_orlenaProcs[7];
        l_orlenaProcs[3].iv_pAProcs[1] = &l_orlenaProcs[5];
        l_orlenaProcs[3].iv_pAProcs[2] = &l_orlenaProcs[1];
        // XBus links and states
        l_orlenaProcs[3].iv_pXProcs[0] = &l_orlenaProcs[2];

        // Proc4:
        l_orlenaProcs[4].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[4].procHUID = 4;                 // HUID
        l_orlenaProcs[4].procFabricNode = 2;           // FABRIC_NODE_ID
        l_orlenaProcs[4].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[4].iv_masterCapable = false;      // Master proc
        l_orlenaProcs[4].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[4].iv_pAProcs[0] = &l_orlenaProcs[6];
        l_orlenaProcs[4].iv_pAProcs[1] = &l_orlenaProcs[0];
        l_orlenaProcs[4].iv_pAProcs[2] = &l_orlenaProcs[2];
        // XBus links and states
        l_orlenaProcs[4].iv_pXProcs[0] = &l_orlenaProcs[5];

        // Proc5:
        l_orlenaProcs[5].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[5].procHUID = 5;                 // HUID
        l_orlenaProcs[5].procFabricNode = 2;           // FABRIC_NODE_ID
        l_orlenaProcs[5].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[5].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[5].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[5].iv_pAProcs[0] = &l_orlenaProcs[1];
        l_orlenaProcs[5].iv_pAProcs[1] = &l_orlenaProcs[3];
        l_orlenaProcs[5].iv_pAProcs[2] = &l_orlenaProcs[7];
        // XBus links and states
        l_orlenaProcs[5].iv_pXProcs[0] = &l_orlenaProcs[4];

        // Proc6:
        l_orlenaProcs[6].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[6].procHUID = 6;                 // HUID
        l_orlenaProcs[6].procFabricNode = 3;           // FABRIC_NODE_ID
        l_orlenaProcs[6].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[6].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[6].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[6].iv_pAProcs[0] = &l_orlenaProcs[4];
        l_orlenaProcs[6].iv_pAProcs[1] = &l_orlenaProcs[2];
        l_orlenaProcs[6].iv_pAProcs[2] = &l_orlenaProcs[0];
        // XBus links and states
        l_orlenaProcs[6].iv_pXProcs[0] = &l_orlenaProcs[7];

        // Proc7:
        l_orlenaProcs[7].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[7].procHUID = 7;                 // HUID
        l_orlenaProcs[7].procFabricNode = 3;           // FABRIC_NODE_ID
        l_orlenaProcs[7].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[7].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[7].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[7].iv_pAProcs[0] = &l_orlenaProcs[3];
        l_orlenaProcs[7].iv_pAProcs[1] = &l_orlenaProcs[1];
        l_orlenaProcs[7].iv_pAProcs[2] = &l_orlenaProcs[5];
        // XBus links and states
        l_orlenaProcs[7].iv_pXProcs[0] = &l_orlenaProcs[6];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_orlenaProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_orlenaProcs[0].iv_deconfigured == false &&
            l_orlenaProcs[1].iv_deconfigured == true &&
            l_orlenaProcs[2].iv_deconfigured == false &&
            l_orlenaProcs[3].iv_deconfigured == true &&
            l_orlenaProcs[4].iv_deconfigured == false &&
            l_orlenaProcs[5].iv_deconfigured == true &&
            l_orlenaProcs[6].iv_deconfigured == false &&
            l_orlenaProcs[7].iv_deconfigured == true)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc3: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc3: incorrect configuration returned");
        }
    }


    /**
     *  @brief Test Deconfigure Associated Proc4
     */
    void testDeconfigureAssocProc4()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc4: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 4: ORLENA System with proc6/7xbus1 and
        // proc2/4 abus2 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 8;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_orlenaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_orlenaProcs.insert(l_orlenaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_orlenaProcs[0].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[0].procHUID = 0;                 // HUID
        l_orlenaProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_orlenaProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[0].iv_masterCapable = true;      // Master proc
        l_orlenaProcs[0].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[0].iv_pAProcs[0] = &l_orlenaProcs[2];
        l_orlenaProcs[0].iv_pAProcs[1] = &l_orlenaProcs[4];
        l_orlenaProcs[0].iv_pAProcs[2] = &l_orlenaProcs[6];
        // XBus links and states
        l_orlenaProcs[0].iv_pXProcs[0] = &l_orlenaProcs[1];

        // Proc1:
        l_orlenaProcs[1].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[1].procHUID = 1;                 // HUID
        l_orlenaProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_orlenaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[1].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[1].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[1].iv_pAProcs[0] = &l_orlenaProcs[5];
        l_orlenaProcs[1].iv_pAProcs[1] = &l_orlenaProcs[7];
        l_orlenaProcs[1].iv_pAProcs[2] = &l_orlenaProcs[3];
        // XBus links and states
        l_orlenaProcs[1].iv_pXProcs[0] = &l_orlenaProcs[0];

        // Proc2:
        l_orlenaProcs[2].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[2].procHUID = 2;                 // HUID
        l_orlenaProcs[2].procFabricNode = 1;           // FABRIC_NODE_ID
        l_orlenaProcs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[2].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[2].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[2].iv_pAProcs[0] = &l_orlenaProcs[0];
        l_orlenaProcs[2].iv_pAProcs[1] = &l_orlenaProcs[6];
        l_orlenaProcs[2].iv_pAProcs[2] = &l_orlenaProcs[4];
        l_orlenaProcs[2].iv_ADeconfigured[2] = true;
        // XBus links and states
        l_orlenaProcs[2].iv_pXProcs[0] = &l_orlenaProcs[3];

        // Proc3:
        l_orlenaProcs[3].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[3].procHUID = 3;                 // HUID
        l_orlenaProcs[3].procFabricNode = 1;           // FABRIC_NODE_ID
        l_orlenaProcs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[3].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[3].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[3].iv_pAProcs[0] = &l_orlenaProcs[7];
        l_orlenaProcs[3].iv_pAProcs[1] = &l_orlenaProcs[5];
        l_orlenaProcs[3].iv_pAProcs[2] = &l_orlenaProcs[1];
        // XBus links and states
        l_orlenaProcs[3].iv_pXProcs[0] = &l_orlenaProcs[2];

        // Proc4:
        l_orlenaProcs[4].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[4].procHUID = 4;                 // HUID
        l_orlenaProcs[4].procFabricNode = 2;           // FABRIC_NODE_ID
        l_orlenaProcs[4].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[4].iv_masterCapable = false;      // Master proc
        l_orlenaProcs[4].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[4].iv_pAProcs[0] = &l_orlenaProcs[6];
        l_orlenaProcs[4].iv_pAProcs[1] = &l_orlenaProcs[0];
        l_orlenaProcs[4].iv_pAProcs[2] = &l_orlenaProcs[2];
        l_orlenaProcs[4].iv_ADeconfigured[2] = true;
        // XBus links and states
        l_orlenaProcs[4].iv_pXProcs[0] = &l_orlenaProcs[5];

        // Proc5:
        l_orlenaProcs[5].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[5].procHUID = 5;                 // HUID
        l_orlenaProcs[5].procFabricNode = 2;           // FABRIC_NODE_ID
        l_orlenaProcs[5].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[5].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[5].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[5].iv_pAProcs[0] = &l_orlenaProcs[1];
        l_orlenaProcs[5].iv_pAProcs[1] = &l_orlenaProcs[3];
        l_orlenaProcs[5].iv_pAProcs[2] = &l_orlenaProcs[7];
        // XBus links and states
        l_orlenaProcs[5].iv_pXProcs[0] = &l_orlenaProcs[4];

        // Proc6:
        l_orlenaProcs[6].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[6].procHUID = 6;                 // HUID
        l_orlenaProcs[6].procFabricNode = 3;           // FABRIC_NODE_ID
        l_orlenaProcs[6].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[6].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[6].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[6].iv_pAProcs[0] = &l_orlenaProcs[4];
        l_orlenaProcs[6].iv_pAProcs[1] = &l_orlenaProcs[2];
        l_orlenaProcs[6].iv_pAProcs[2] = &l_orlenaProcs[0];
        // XBus links and states
        l_orlenaProcs[6].iv_pXProcs[0] = &l_orlenaProcs[7];
        l_orlenaProcs[6].iv_XDeconfigured[0] = true;

        // Proc7:
        l_orlenaProcs[7].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[7].procHUID = 7;                 // HUID
        l_orlenaProcs[7].procFabricNode = 3;           // FABRIC_NODE_ID
        l_orlenaProcs[7].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[7].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[7].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[7].iv_pAProcs[0] = &l_orlenaProcs[3];
        l_orlenaProcs[7].iv_pAProcs[1] = &l_orlenaProcs[1];
        l_orlenaProcs[7].iv_pAProcs[2] = &l_orlenaProcs[5];
        // XBus links and states
        l_orlenaProcs[7].iv_pXProcs[0] = &l_orlenaProcs[6];
        l_orlenaProcs[7].iv_XDeconfigured[0] = true;

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_orlenaProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_orlenaProcs[0].iv_deconfigured == false &&
            l_orlenaProcs[1].iv_deconfigured == false &&
            l_orlenaProcs[2].iv_deconfigured == false &&
            l_orlenaProcs[3].iv_deconfigured == false &&
            l_orlenaProcs[4].iv_deconfigured == true &&
            l_orlenaProcs[5].iv_deconfigured == true &&
            l_orlenaProcs[6].iv_deconfigured == true &&
            l_orlenaProcs[7].iv_deconfigured == true)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc4: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc4: incorrect configuration returned");
        }
    }


    /**
     *  @brief Test Deconfigure Associated Proc5
     */
    void testDeconfigureAssocProc5()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc5: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 5: ORLENA System with proc4 deconfigured (and
        // proc4's chiplets and peers deconfigured by association),
        // and proc5-abus2 / proc7-abus2 deconfigured.

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 8;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_orlenaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_orlenaProcs.insert(l_orlenaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_orlenaProcs[0].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[0].procHUID = 0;                 // HUID
        l_orlenaProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_orlenaProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[0].iv_masterCapable = true;      // Master proc
        l_orlenaProcs[0].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[0].iv_pAProcs[0] = &l_orlenaProcs[2];
        l_orlenaProcs[0].iv_pAProcs[1] = &l_orlenaProcs[4];
        l_orlenaProcs[0].iv_pAProcs[2] = &l_orlenaProcs[6];
        l_orlenaProcs[4].iv_ADeconfigured[1] = true;
        // XBus links and states
        l_orlenaProcs[0].iv_pXProcs[0] = &l_orlenaProcs[1];

        // Proc1:
        l_orlenaProcs[1].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[1].procHUID = 1;                 // HUID
        l_orlenaProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_orlenaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[1].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[1].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[1].iv_pAProcs[0] = &l_orlenaProcs[5];
        l_orlenaProcs[1].iv_pAProcs[1] = &l_orlenaProcs[7];
        l_orlenaProcs[1].iv_pAProcs[2] = &l_orlenaProcs[3];
        // XBus links and states
        l_orlenaProcs[1].iv_pXProcs[0] = &l_orlenaProcs[0];

        // Proc2:
        l_orlenaProcs[2].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[2].procHUID = 2;                 // HUID
        l_orlenaProcs[2].procFabricNode = 1;           // FABRIC_NODE_ID
        l_orlenaProcs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[2].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[2].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[2].iv_pAProcs[0] = &l_orlenaProcs[0];
        l_orlenaProcs[2].iv_pAProcs[1] = &l_orlenaProcs[6];
        l_orlenaProcs[2].iv_pAProcs[2] = &l_orlenaProcs[4];
        l_orlenaProcs[2].iv_ADeconfigured[2] = true;
        // XBus links and states
        l_orlenaProcs[2].iv_pXProcs[0] = &l_orlenaProcs[3];

        // Proc3:
        l_orlenaProcs[3].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[3].procHUID = 3;                 // HUID
        l_orlenaProcs[3].procFabricNode = 1;           // FABRIC_NODE_ID
        l_orlenaProcs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[3].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[3].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[3].iv_pAProcs[0] = &l_orlenaProcs[7];
        l_orlenaProcs[3].iv_pAProcs[1] = &l_orlenaProcs[5];
        l_orlenaProcs[3].iv_pAProcs[2] = &l_orlenaProcs[1];
        // XBus links and states
        l_orlenaProcs[3].iv_pXProcs[0] = &l_orlenaProcs[2];

        // Proc4:
        l_orlenaProcs[4].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[4].procHUID = 4;                 // HUID
        l_orlenaProcs[4].procFabricNode = 2;           // FABRIC_NODE_ID
        l_orlenaProcs[4].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[4].iv_masterCapable = false;      // Master proc
        l_orlenaProcs[4].iv_deconfigured = true;      // HWAS state
        // ABus links and states
        l_orlenaProcs[4].iv_pAProcs[0] = &l_orlenaProcs[6];
        l_orlenaProcs[4].iv_pAProcs[1] = &l_orlenaProcs[0];
        l_orlenaProcs[4].iv_pAProcs[2] = &l_orlenaProcs[2];
        l_orlenaProcs[4].iv_ADeconfigured[0] = true;
        l_orlenaProcs[4].iv_ADeconfigured[1] = true;
        l_orlenaProcs[4].iv_ADeconfigured[2] = true;
        // XBus links and states
        l_orlenaProcs[4].iv_pXProcs[0] = &l_orlenaProcs[5];
        l_orlenaProcs[4].iv_XDeconfigured[0] = true;

        // Proc5:
        l_orlenaProcs[5].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[5].procHUID = 5;                 // HUID
        l_orlenaProcs[5].procFabricNode = 2;           // FABRIC_NODE_ID
        l_orlenaProcs[5].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[5].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[5].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[5].iv_pAProcs[0] = &l_orlenaProcs[1];
        l_orlenaProcs[5].iv_pAProcs[1] = &l_orlenaProcs[3];
        l_orlenaProcs[5].iv_pAProcs[2] = &l_orlenaProcs[7];
        l_orlenaProcs[5].iv_ADeconfigured[2] = true;
        // XBus links and states
        l_orlenaProcs[5].iv_pXProcs[0] = &l_orlenaProcs[4];
        l_orlenaProcs[5].iv_XDeconfigured[0] = true;

        // Proc6:
        l_orlenaProcs[6].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[6].procHUID = 6;                 // HUID
        l_orlenaProcs[6].procFabricNode = 3;           // FABRIC_NODE_ID
        l_orlenaProcs[6].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_orlenaProcs[6].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[6].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[6].iv_pAProcs[0] = &l_orlenaProcs[4];
        l_orlenaProcs[6].iv_pAProcs[1] = &l_orlenaProcs[2];
        l_orlenaProcs[6].iv_pAProcs[2] = &l_orlenaProcs[0];
        l_orlenaProcs[6].iv_ADeconfigured[0] = true;
        // XBus links and states
        l_orlenaProcs[6].iv_pXProcs[0] = &l_orlenaProcs[7];

        // Proc7:
        l_orlenaProcs[7].iv_pThisProc = NULL;          // Target *
        l_orlenaProcs[7].procHUID = 7;                 // HUID
        l_orlenaProcs[7].procFabricNode = 3;           // FABRIC_NODE_ID
        l_orlenaProcs[7].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_orlenaProcs[7].iv_masterCapable = false;     // Not master proc
        l_orlenaProcs[7].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_orlenaProcs[7].iv_pAProcs[0] = &l_orlenaProcs[3];
        l_orlenaProcs[7].iv_pAProcs[1] = &l_orlenaProcs[1];
        l_orlenaProcs[7].iv_pAProcs[2] = &l_orlenaProcs[5];
        l_orlenaProcs[7].iv_ADeconfigured[2] = true;
        // XBus links and states
        l_orlenaProcs[7].iv_pXProcs[0] = &l_orlenaProcs[6];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_orlenaProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_orlenaProcs[0].iv_deconfigured == false &&
            l_orlenaProcs[1].iv_deconfigured == false &&
            l_orlenaProcs[2].iv_deconfigured == false &&
            l_orlenaProcs[3].iv_deconfigured == false &&
            l_orlenaProcs[4].iv_deconfigured == true &&
            l_orlenaProcs[5].iv_deconfigured == true &&
            l_orlenaProcs[6].iv_deconfigured == false &&
            l_orlenaProcs[7].iv_deconfigured == false)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc5: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc5: incorrect configuration returned");
        }
    }


    /**
     *  @brief Test Deconfigure Associated Proc6
     */
    void testDeconfigureAssocProc6()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc6: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 6: BRAZOS System with proc0xbus0
        // and proc1xbus3 deconfigured
        // Note that procs in BRAZOS have xbus0,xbus1,
        // and xbus3 chiplets as defined by the mrw.xml file.

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_brazosProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_brazosProcs.insert(l_brazosProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_brazosProcs[0].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[0].procHUID = 0;                 // HUID
        l_brazosProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_brazosProcs[0].iv_masterCapable = true;      // Master proc
        l_brazosProcs[0].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[0].iv_pXProcs[0] = &l_brazosProcs[1];
        l_brazosProcs[0].iv_pXProcs[1] = &l_brazosProcs[2];
        l_brazosProcs[0].iv_pXProcs[3] = &l_brazosProcs[3];
        l_brazosProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_brazosProcs[1].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[1].procHUID = 1;                 // HUID
        l_brazosProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_brazosProcs[1].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[1].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        // XBus links and states
        l_brazosProcs[1].iv_pXProcs[0] = &l_brazosProcs[2];
        l_brazosProcs[1].iv_pXProcs[1] = &l_brazosProcs[3];
        l_brazosProcs[1].iv_pXProcs[3] = &l_brazosProcs[0];
        l_brazosProcs[1].iv_XDeconfigured[3] = true;

        // Proc2:
        l_brazosProcs[2].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[2].procHUID = 2;                 // HUID
        l_brazosProcs[2].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_brazosProcs[2].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[2].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[2].iv_pXProcs[0] = &l_brazosProcs[3];
        l_brazosProcs[2].iv_pXProcs[1] = &l_brazosProcs[0];
        l_brazosProcs[2].iv_pXProcs[3] = &l_brazosProcs[1];

        // Proc3:
        l_brazosProcs[3].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[3].procHUID = 3;                 // HUID
        l_brazosProcs[3].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[3].procFabricChip = 3;           // FABRIC_CHIP_ID
        l_brazosProcs[3].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[3].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[3].iv_pXProcs[0] = &l_brazosProcs[0];
        l_brazosProcs[3].iv_pXProcs[1] = &l_brazosProcs[1];
        l_brazosProcs[3].iv_pXProcs[3] = &l_brazosProcs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_brazosProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_brazosProcs[0].iv_deconfigured == false &&
            l_brazosProcs[1].iv_deconfigured == true &&
            l_brazosProcs[2].iv_deconfigured == false &&
            l_brazosProcs[3].iv_deconfigured == false)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc6: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc6: incorrect configuration returned");
        }
    }


    /**
     *  @brief Test Deconfigure Associated Proc7
     */
    void testDeconfigureAssocProc7()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc7: Started");
#if 1
        // This test deconfigures proc2-xbus1 and proc3-xbus1 in a
        // TULETA-2S4U system. Even though this test
        // restores their states after the test, since the cxxtests are
        // all run in parallel, during the time that a target is non-
        // functional due to this test, another test may be running that
        // might be adversly affected.
        // tests are left in the code so that a developer can enable them
        // to test these specific functions - just keep in mind that there
        // could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = NULL;

        do
        {
            // Define and populate vector of present procs
            // Get top level target
            TARGETING::Target * l_pSys;
            TARGETING::targetService().getTopLevelTarget(l_pSys);
            // Define predicate
            TARGETING::PredicateCTM predProc(TARGETING::CLASS_CHIP,
                                             TARGETING::TYPE_PROC);
            TARGETING::PredicateHwas predPres;
            predPres.present(true);
            TARGETING::PredicatePostfixExpr presProc;
            presProc.push(&predProc).push(&predPres).And();
            // Populate vector
            TARGETING::TargetHandleList l_presProcs;
            TARGETING::targetService().getAssociated(l_presProcs,
                                                     l_pSys,
                                            TARGETING::TargetService::CHILD,
                                            TARGETING::TargetService::ALL,
                                            &presProc);
            // Define HUIDs of targets to deconfigure based on
            // 4-proc configuration in simics_MURANO.system.xml
            ATTR_HUID_type l_proc2Xbus1HUID = 0x000E0009;
            ATTR_HUID_type l_proc3Xbus1HUID = 0x000E000D;
            // Define targeting*'s corresponding to HUIDs above
            TARGETING::Target * l_pProc2Xbus1;
            TARGETING::Target * l_pProc3Xbus1;
            // Define targets' original states corresponding to HUIDs above
            HwasState l_proc2Xbus1OrigState;
            HwasState l_proc3Xbus1OrigState;
            // Define vector of present bus endpoint chiplets
            TARGETING::PredicateCTM predXbus(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_XBUS);
            TARGETING::PredicateCTM predAbus(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_ABUS);
            TARGETING::PredicatePostfixExpr busPres;
            busPres.push(&predXbus).push(&predAbus).Or().push(&predPres).And();
            // Counter to keep track of deconfigureTarget calls
            uint8_t deconfigureTargetCallCounter = 0;
            // Iterate through present procs
            for (TARGETING::TargetHandleList::const_iterator
                 l_procsIter = l_presProcs.begin();
                 l_procsIter != l_presProcs.end();
                 ++l_procsIter)
            {
                // Populate vector of bus endpoints associated with this proc
                TARGETING::TargetHandleList l_presentBusChiplets;
                TARGETING::targetService().getAssociated(l_presentBusChiplets,
                                             (*l_procsIter),
                                             TARGETING::TargetService::CHILD,
                                             TARGETING::TargetService::ALL,
                                             &busPres);

                // Iterate through present bus endpoint chiplets
                for (TARGETING::TargetHandleList::iterator
                     l_busIter = l_presentBusChiplets.begin();
                     l_busIter != l_presentBusChiplets.end();
                     ++l_busIter)
                {
                    if (l_proc2Xbus1HUID == get_huid(*l_busIter))
                    {
                        // Save target
                        l_pProc2Xbus1 = (*l_busIter);
                        // Get the original HWAS_STATE of the target
                        l_proc2Xbus1OrigState = l_pProc2Xbus1->
                                    getAttr<ATTR_HWAS_STATE>();
                        // Deconfigure the target.
                        l_pErr = theDeconfigGard().
                                deconfigureTarget(*l_pProc2Xbus1,
                                    DeconfigGard::DECONFIGURED_BY_BUS_DECONFIG);
                        if (l_pErr)
                        {
                            TS_FAIL("testDeconfigureAssocProc7: "
                            "Could not deconfigure proc2xbus1");
                            break;
                        }
                        deconfigureTargetCallCounter++;
                    }
                    if (l_proc3Xbus1HUID == get_huid(*l_busIter))
                    {
                        // Save target
                        l_pProc3Xbus1 = (*l_busIter);
                        // Get the original HWAS_STATE of the target
                        l_proc3Xbus1OrigState = l_pProc3Xbus1->
                                    getAttr<ATTR_HWAS_STATE>();
                        // Deconfigure the target.
                        l_pErr = theDeconfigGard().
                                deconfigureTarget(*l_pProc3Xbus1,
                                    DeconfigGard::DECONFIGURED_BY_BUS_DECONFIG);
                        if (l_pErr)
                        {
                            TS_FAIL("testDeconfigureAssocProc7: "
                            "Could not deconfigure proc3xbus1");
                            break;
                        }
                        deconfigureTargetCallCounter++;
                    }
                }
            }
            // If both targets were deconfigured
            if (2 == deconfigureTargetCallCounter)
            {
                // Call deconfigureAssocProc()
                l_pErr = theDeconfigGard().deconfigureAssocProc();
                if (l_pErr)
                {
                    TS_FAIL("testDeconfigureAssocProc7: "
                            "Error from deconfigureAssocProc");
                            break;
                }
                TS_TRACE(INFO_MRK "testDeconfigureAssocProc7: Success");
                // Reset the HWAS_STATE of the targets
                l_pProc2Xbus1->setAttr<ATTR_HWAS_STATE>(l_proc2Xbus1OrigState);
                l_pProc3Xbus1->setAttr<ATTR_HWAS_STATE>(l_proc3Xbus1OrigState);
            }
            else
            {
                TS_FAIL("testDeconfigureAssocProc7: "
                "Not all xbuses were deconfigured");
            }
        }while (0);
#endif
    }



    /**
     *  @brief Test Deconfigure Associated Proc8
     */
    void testDeconfigureAssocProc8()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc8: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 1: TULETA 4 System with proc2, proc3 and
        // all associated bus endpoints deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_tuletaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_tuletaProcs.insert(l_tuletaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_tuletaProcs[0].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[0].procHUID = 0;                 // HUID
        l_tuletaProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_tuletaProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[0].iv_masterCapable = true;      // Master proc
        l_tuletaProcs[0].iv_deconfigured = false;      // HWAS state
        l_tuletaProcs[0].iv_pAProcs[0] = &l_tuletaProcs[2];
        l_tuletaProcs[0].iv_pAProcs[1] = &l_tuletaProcs[2];
        l_tuletaProcs[0].iv_ADeconfigured[0] = true;
        l_tuletaProcs[0].iv_ADeconfigured[1] = true;
        l_tuletaProcs[0].iv_pXProcs[0] = &l_tuletaProcs[1];

        // Proc1:
        l_tuletaProcs[1].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[1].procHUID = 1;                 // HUID
        l_tuletaProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_tuletaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[1].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[1].iv_deconfigured = false;      // HWAS state
        l_tuletaProcs[1].iv_pAProcs[0] = &l_tuletaProcs[3];
        l_tuletaProcs[1].iv_pAProcs[1] = &l_tuletaProcs[3];
        l_tuletaProcs[1].iv_ADeconfigured[0] = true;
        l_tuletaProcs[1].iv_ADeconfigured[1] = true;
        l_tuletaProcs[1].iv_pXProcs[0] = &l_tuletaProcs[0];

        // Proc2:
        l_tuletaProcs[2].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[2].procHUID = 2;                 // HUID
        l_tuletaProcs[2].procFabricNode = 1;           // FABRIC_NODE_ID
        l_tuletaProcs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[2].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[2].iv_deconfigured = true;      // HWAS state
        l_tuletaProcs[2].iv_pAProcs[0] = &l_tuletaProcs[0];
        l_tuletaProcs[2].iv_pAProcs[1] = &l_tuletaProcs[0];
        l_tuletaProcs[2].iv_ADeconfigured[0] = true;
        l_tuletaProcs[2].iv_ADeconfigured[1] = true;
        l_tuletaProcs[2].iv_pXProcs[0] = &l_tuletaProcs[3];
        l_tuletaProcs[2].iv_XDeconfigured[0] = true;


        // Proc3:
        l_tuletaProcs[3].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[3].procHUID = 3;                 // HUID
        l_tuletaProcs[3].procFabricNode = 1;           // FABRIC_NODE_ID
        l_tuletaProcs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[3].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[3].iv_deconfigured = true;      // HWAS state
        l_tuletaProcs[3].iv_pAProcs[0] = &l_tuletaProcs[1];
        l_tuletaProcs[3].iv_pAProcs[1] = &l_tuletaProcs[2];
        l_tuletaProcs[3].iv_ADeconfigured[0] = true;
        l_tuletaProcs[3].iv_ADeconfigured[1] = true;
        l_tuletaProcs[3].iv_pXProcs[0] = &l_tuletaProcs[2];
        l_tuletaProcs[3].iv_XDeconfigured[0] = true;


        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_tuletaProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_tuletaProcs[0].iv_deconfigured == false &&
            l_tuletaProcs[1].iv_deconfigured == false &&
            l_tuletaProcs[2].iv_deconfigured == true &&
            l_tuletaProcs[3].iv_deconfigured == true)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc8: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc8: incorrect configuration returned");
        }
    }

    /**
     *  @brief Test Deconfigure Associated Proc9
     */
    void testDeconfigureAssocProc9()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc9: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 1: TULETA 4 System with Proc 3 NP which is indicated by
        // No Abus endpoints on Proc 1 and 3 and no Xbus endpoint on Proc1

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_tuletaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_tuletaProcs.insert(l_tuletaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_tuletaProcs[0].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[0].procHUID = 0;                 // HUID
        l_tuletaProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_tuletaProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[0].iv_masterCapable = true;      // Master proc
        l_tuletaProcs[0].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[0].iv_pAProcs[0] = &l_tuletaProcs[2];
        l_tuletaProcs[0].iv_pAProcs[1] = &l_tuletaProcs[2];
        // XBus links and states
        l_tuletaProcs[0].iv_pXProcs[0] = &l_tuletaProcs[1];

        // Proc1:
        l_tuletaProcs[1].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[1].procHUID = 1;                 // HUID
        l_tuletaProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_tuletaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[1].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[1].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_tuletaProcs[1].iv_pXProcs[0] = &l_tuletaProcs[0];

        // Proc2:
        l_tuletaProcs[2].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[2].procHUID = 2;                 // HUID
        l_tuletaProcs[2].procFabricNode = 1;           // FABRIC_NODE_ID
        l_tuletaProcs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[2].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[2].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[2].iv_pAProcs[0] = &l_tuletaProcs[0];
        l_tuletaProcs[2].iv_pAProcs[1] = &l_tuletaProcs[0];
        // No xbus because proc3 is "not present"

        // Proc3:
        l_tuletaProcs[3].iv_pThisProc = NULL;          // Target *
        l_tuletaProcs[3].procHUID = 3;                 // HUID
        l_tuletaProcs[3].procFabricNode = 1;           // FABRIC_NODE_ID
        l_tuletaProcs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[3].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[3].iv_deconfigured = true;      // HWAS state
        // Xbus links still has xbus to proc 2 because proc 2 is functional
        l_tuletaProcs[3].iv_pXProcs[0] = &l_tuletaProcs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_tuletaProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_tuletaProcs[0].iv_deconfigured == false &&
            l_tuletaProcs[1].iv_deconfigured == false &&
            l_tuletaProcs[2].iv_deconfigured == true &&
            l_tuletaProcs[3].iv_deconfigured == true)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc9: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc9: incorrect configuration returned");
        }
    }

    /**
     *  @brief Test Deconfigure Associated Proc10
     */
    void testDeconfigureAssocProc10()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc10: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with proc0xbus0 and proc1xbus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_brazosProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_brazosProcs.insert(l_brazosProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_brazosProcs[0].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[0].procHUID = 0;                 // HUID
        l_brazosProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_brazosProcs[0].iv_masterCapable = true;      // Master proc
        l_brazosProcs[0].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[0].iv_pXProcs[0] = &l_brazosProcs[1];
        l_brazosProcs[0].iv_pXProcs[1] = &l_brazosProcs[2];
        l_brazosProcs[0].iv_pXProcs[3] = &l_brazosProcs[3];
        l_brazosProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_brazosProcs[1].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[1].procHUID = 1;                 // HUID
        l_brazosProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_brazosProcs[1].iv_masterCapable = true;     // Not master proc
        l_brazosProcs[1].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        // XBus links and states
        l_brazosProcs[1].iv_pXProcs[0] = &l_brazosProcs[2];
        l_brazosProcs[1].iv_pXProcs[1] = &l_brazosProcs[3];
        l_brazosProcs[1].iv_pXProcs[3] = &l_brazosProcs[0];
        l_brazosProcs[1].iv_XDeconfigured[3] = true;

        // Proc2:
        l_brazosProcs[2].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[2].procHUID = 2;                 // HUID
        l_brazosProcs[2].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_brazosProcs[2].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[2].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[2].iv_pXProcs[0] = &l_brazosProcs[3];
        l_brazosProcs[2].iv_pXProcs[1] = &l_brazosProcs[0];
        l_brazosProcs[2].iv_pXProcs[3] = &l_brazosProcs[1];

        // Proc3:
        l_brazosProcs[3].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[3].procHUID = 3;                 // HUID
        l_brazosProcs[3].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[3].procFabricChip = 3;           // FABRIC_CHIP_ID
        l_brazosProcs[3].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[3].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[3].iv_pXProcs[0] = &l_brazosProcs[0];
        l_brazosProcs[3].iv_pXProcs[1] = &l_brazosProcs[1];
        l_brazosProcs[3].iv_pXProcs[3] = &l_brazosProcs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_brazosProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_brazosProcs[0].iv_deconfigured == false &&
            l_brazosProcs[1].iv_deconfigured == true &&
            l_brazosProcs[2].iv_deconfigured == false &&
            l_brazosProcs[3].iv_deconfigured == false)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc10: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc10: incorrect configuration returned");
        }
    }

    /**
     *  @brief Test Deconfigure Associated Proc11
     */
    void testDeconfigureAssocProc11()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc11: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with master proc, proc0xbus0 and proc1xbus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_brazosProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_brazosProcs.insert(l_brazosProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_brazosProcs[0].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[0].procHUID = 0;                 // HUID
        l_brazosProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_brazosProcs[0].iv_masterCapable = true;      // Master proc
        l_brazosProcs[0].iv_deconfigured = true;      // HWAS state
        // XBus links and states
        l_brazosProcs[0].iv_pXProcs[0] = &l_brazosProcs[1];
        l_brazosProcs[0].iv_pXProcs[1] = &l_brazosProcs[2];
        l_brazosProcs[0].iv_pXProcs[3] = &l_brazosProcs[3];
        l_brazosProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_brazosProcs[1].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[1].procHUID = 1;                 // HUID
        l_brazosProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_brazosProcs[1].iv_masterCapable = true;     // Not master proc
        l_brazosProcs[1].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        // XBus links and states
        l_brazosProcs[1].iv_pXProcs[0] = &l_brazosProcs[2];
        l_brazosProcs[1].iv_pXProcs[1] = &l_brazosProcs[3];
        l_brazosProcs[1].iv_pXProcs[3] = &l_brazosProcs[0];
        l_brazosProcs[1].iv_XDeconfigured[3] = true;

        // Proc2:
        l_brazosProcs[2].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[2].procHUID = 2;                 // HUID
        l_brazosProcs[2].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_brazosProcs[2].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[2].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[2].iv_pXProcs[0] = &l_brazosProcs[3];
        l_brazosProcs[2].iv_pXProcs[1] = &l_brazosProcs[0];
        l_brazosProcs[2].iv_pXProcs[3] = &l_brazosProcs[1];

        // Proc3:
        l_brazosProcs[3].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[3].procHUID = 3;                 // HUID
        l_brazosProcs[3].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[3].procFabricChip = 3;           // FABRIC_CHIP_ID
        l_brazosProcs[3].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[3].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[3].iv_pXProcs[0] = &l_brazosProcs[0];
        l_brazosProcs[3].iv_pXProcs[1] = &l_brazosProcs[1];
        l_brazosProcs[3].iv_pXProcs[3] = &l_brazosProcs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_brazosProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_brazosProcs[0].iv_deconfigured == true &&
            l_brazosProcs[1].iv_deconfigured == false &&
            l_brazosProcs[2].iv_deconfigured == false &&
            l_brazosProcs[3].iv_deconfigured == false)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc11: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc11: incorrect configuration returned");
        }
    }

    /**
     *  @brief Test Deconfigure Associated Proc12
     */
    void testDeconfigureAssocProc12()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc12: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with alt master proc, proc0xbus0 and proc1xbus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_brazosProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_brazosProcs.insert(l_brazosProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_brazosProcs[0].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[0].procHUID = 0;                 // HUID
        l_brazosProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_brazosProcs[0].iv_masterCapable = true;      // Master proc
        l_brazosProcs[0].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[0].iv_pXProcs[0] = &l_brazosProcs[1];
        l_brazosProcs[0].iv_pXProcs[1] = &l_brazosProcs[2];
        l_brazosProcs[0].iv_pXProcs[3] = &l_brazosProcs[3];
        l_brazosProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_brazosProcs[1].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[1].procHUID = 1;                 // HUID
        l_brazosProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_brazosProcs[1].iv_masterCapable = true;     // Not master proc
        l_brazosProcs[1].iv_deconfigured = true;      // HWAS state
        // XBus links and states
        // XBus links and states
        l_brazosProcs[1].iv_pXProcs[0] = &l_brazosProcs[2];
        l_brazosProcs[1].iv_pXProcs[1] = &l_brazosProcs[3];
        l_brazosProcs[1].iv_pXProcs[3] = &l_brazosProcs[0];
        l_brazosProcs[1].iv_XDeconfigured[3] = true;

        // Proc2:
        l_brazosProcs[2].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[2].procHUID = 2;                 // HUID
        l_brazosProcs[2].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_brazosProcs[2].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[2].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[2].iv_pXProcs[0] = &l_brazosProcs[3];
        l_brazosProcs[2].iv_pXProcs[1] = &l_brazosProcs[0];
        l_brazosProcs[2].iv_pXProcs[3] = &l_brazosProcs[1];

        // Proc3:
        l_brazosProcs[3].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[3].procHUID = 3;                 // HUID
        l_brazosProcs[3].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[3].procFabricChip = 3;           // FABRIC_CHIP_ID
        l_brazosProcs[3].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[3].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[3].iv_pXProcs[0] = &l_brazosProcs[0];
        l_brazosProcs[3].iv_pXProcs[1] = &l_brazosProcs[1];
        l_brazosProcs[3].iv_pXProcs[3] = &l_brazosProcs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_brazosProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_brazosProcs[0].iv_deconfigured == false &&
            l_brazosProcs[1].iv_deconfigured == true &&
            l_brazosProcs[2].iv_deconfigured == false &&
            l_brazosProcs[3].iv_deconfigured == false)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc12: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc12: incorrect configuration returned");
        }
    }

    /**
     *  @brief Test Deconfigure Associated Proc13
     */
    void testDeconfigureAssocProc13()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc13: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with master proc, proc0xbus0, proc1xbus3, proc1xbus0, and
        // proc2xbus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = NULL;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_brazosProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_brazosProcs.insert(l_brazosProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_brazosProcs[0].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[0].procHUID = 0;                 // HUID
        l_brazosProcs[0].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_brazosProcs[0].iv_masterCapable = true;      // Master proc
        l_brazosProcs[0].iv_deconfigured = true;      // HWAS state
        // XBus links and states
        l_brazosProcs[0].iv_pXProcs[0] = &l_brazosProcs[1];
        l_brazosProcs[0].iv_pXProcs[1] = &l_brazosProcs[2];
        l_brazosProcs[0].iv_pXProcs[3] = &l_brazosProcs[3];
        l_brazosProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_brazosProcs[1].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[1].procHUID = 1;                 // HUID
        l_brazosProcs[1].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_brazosProcs[1].iv_masterCapable = true;      // Not master proc
        l_brazosProcs[1].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        // XBus links and states
        l_brazosProcs[1].iv_pXProcs[0] = &l_brazosProcs[2];
        l_brazosProcs[1].iv_pXProcs[1] = &l_brazosProcs[3];
        l_brazosProcs[1].iv_pXProcs[3] = &l_brazosProcs[0];
        l_brazosProcs[1].iv_XDeconfigured[0] = true;
        l_brazosProcs[1].iv_XDeconfigured[3] = true;

        // Proc2:
        l_brazosProcs[2].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[2].procHUID = 2;                 // HUID
        l_brazosProcs[2].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_brazosProcs[2].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[2].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[2].iv_pXProcs[0] = &l_brazosProcs[3];
        l_brazosProcs[2].iv_pXProcs[1] = &l_brazosProcs[0];
        l_brazosProcs[2].iv_pXProcs[3] = &l_brazosProcs[1];
        l_brazosProcs[2].iv_XDeconfigured[3] = true;

        // Proc3:
        l_brazosProcs[3].iv_pThisProc = NULL;          // Target *
        l_brazosProcs[3].procHUID = 3;                 // HUID
        l_brazosProcs[3].procFabricNode = 0;           // FABRIC_NODE_ID
        l_brazosProcs[3].procFabricChip = 3;           // FABRIC_CHIP_ID
        l_brazosProcs[3].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[3].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[3].iv_pXProcs[0] = &l_brazosProcs[0];
        l_brazosProcs[3].iv_pXProcs[1] = &l_brazosProcs[1];
        l_brazosProcs[3].iv_pXProcs[3] = &l_brazosProcs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_brazosProcs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_brazosProcs[0].iv_deconfigured == true &&
            l_brazosProcs[1].iv_deconfigured == false &&
            l_brazosProcs[2].iv_deconfigured == true &&
            l_brazosProcs[3].iv_deconfigured == false)
        {
            TS_TRACE(INFO_MRK "testDeconfigureAssocProc13: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc13: incorrect configuration returned");
        }
    }

    /**
     *  @brief Test Deconfig Present Association 1
     */
    void testdeconfigPresentByAssoc1()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc1: Started");
        // This tests the scenario where there is 1 mcs, membuff, mba and dimm
        // This is done to ensure that the algorithm works on each edge case

        TargetInfoVector l_targets;
        TargetInfoVector l_targToDeconfig;
        TargetInfo l_TargetInfo;

        l_TargetInfo.pThisTarget = NULL;
        EntityPath l_ep[4];

        // MCS only
        l_ep[0].addLast(TYPE_MCS, 0);
        l_TargetInfo.affinityPath = l_ep[0]; // SHOULD GET DECONFIGURED
        l_TargetInfo.type = TYPE_MCS;

        l_targets.push_back(l_TargetInfo);

        presentByAssoc(l_targets, l_targToDeconfig);

        // MEMBUF only
        l_ep[1].addLast(TYPE_MCS, 0);
        l_ep[1].addLast(TYPE_MEMBUF, 0);
        l_TargetInfo.affinityPath = l_ep[1]; // SHOULD GET DECONFIGURED
        l_TargetInfo.type = TYPE_MEMBUF;
        l_targets.push_back(l_TargetInfo);

        presentByAssoc(l_targets, l_targToDeconfig);

        // MBA only
        l_ep[2].addLast(TYPE_MCS, 0);
        l_ep[2].addLast(TYPE_MEMBUF, 0);
        l_ep[2].addLast(TYPE_MBA, 0);
        l_TargetInfo.affinityPath = l_ep[2]; // SHOULD GET DECONFIGURED
        l_TargetInfo.type = TYPE_MBA;
        l_targets.push_back(l_TargetInfo);

        presentByAssoc(l_targets, l_targToDeconfig);

        // DIMM only
        l_ep[3].addLast(TYPE_MCS, 0);
        l_ep[3].addLast(TYPE_MEMBUF, 0);
        l_ep[3].addLast(TYPE_MBA, 0);
        l_ep[3].addLast(TYPE_DIMM, 0);
        l_TargetInfo.affinityPath = l_ep[3]; // SHOULD GET DECONFIGURED
        l_TargetInfo.type = TYPE_DIMM;
        l_targets.push_back(l_TargetInfo);

        presentByAssoc(l_targets, l_targToDeconfig);

        // Check result
        std::sort(l_targToDeconfig.begin(), l_targToDeconfig.end(),
              compareAffinity);
        if ((l_targToDeconfig.size() == 4) &&
            (l_targToDeconfig[0].affinityPath == l_ep[0]) &&
            (l_targToDeconfig[1].affinityPath == l_ep[1]) &&
            (l_targToDeconfig[2].affinityPath == l_ep[2]) &&
            (l_targToDeconfig[3].affinityPath == l_ep[3]) )
        {
            TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc1: Success");
        }
        else
        {
            TS_FAIL("testdeconfigPresentByAssoc1: incorrect configuration returned");
            for (uint8_t i=0;i<l_targToDeconfig.size();i++)
            {
                char *s = l_targToDeconfig[i].affinityPath.toString();
                TS_WARN("deconfig %s reason %x",s, l_targToDeconfig[i].reason);
                free(s);
            }
        }
    }

    /**
     *  @brief Test Deconfig Present Association 2
     */
    void testdeconfigPresentByAssoc2()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc2: Started");
        // This test the scenario where MCS Group 0 does not have a membuf
        // MCS Group 1 is fully populated

        // User-defined number of targets
        size_t NUM_TARGS = 5;

        // Input target vector
        TargetInfoVector l_targets;
        TargetInfo l_TargInfo;
        EntityPath l_ep[NUM_TARGS];
        l_TargInfo.pThisTarget = NULL;
        l_TargInfo.affinityPath = l_ep[0];
        l_targets.insert(l_targets.begin(), NUM_TARGS, l_TargInfo);
        // Output target vector
        TargetInfoVector l_targToDeconfig;

        // Add MCS Group 0
        //l_targets[0].pThisTarget = NULL;
        l_targets[0].affinityPath.addLast(TYPE_MCS, 0);
        l_ep[0] = l_targets[0].affinityPath; // SHOULD GET DECONFIGURED
        l_targets[0].type = TYPE_MCS;

        // Add MEMBUF Group 1
        //l_targets[1].pThisTarget = NULL;
        l_targets[1].affinityPath.addLast(TYPE_MCS, 1);
        l_targets[1].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_ep[1] = l_targets[1].affinityPath;
        l_targets[1].type = TYPE_MEMBUF;

        // Add MBA Group 1
        //l_targets[2].pThisTarget = NULL;
        l_targets[2].affinityPath.addLast(TYPE_MCS, 1);
        l_targets[2].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[2].affinityPath.addLast(TYPE_MBA, 0);
        l_ep[2] = l_targets[2].affinityPath;
        l_targets[2].type = TYPE_MBA;

        // Add DIMM Group 1
        //l_targets[3].pThisTarget = NULL;
        l_targets[3].affinityPath.addLast(TYPE_MCS, 1);
        l_targets[3].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[3].affinityPath.addLast(TYPE_MBA, 0);
        l_targets[3].affinityPath.addLast(TYPE_DIMM, 0);
        l_ep[3] = l_targets[3].affinityPath;
        l_targets[3].type = TYPE_DIMM;

        // Add MCS Group 1
        //l_targets[4].pThisTarget = NULL;
        l_targets[4].affinityPath.addLast(TYPE_MCS, 1);
        l_ep[4] = l_targets[4].affinityPath;
        l_targets[4].type = TYPE_MCS;

        presentByAssoc(l_targets, l_targToDeconfig);

        // Check result
        std::sort(l_targToDeconfig.begin(), l_targToDeconfig.end(),
              compareAffinity);
        if ((l_targToDeconfig.size() == 1) &&
            (l_targToDeconfig[0].affinityPath == l_ep[0]) )
        {
            TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc2: Success");
        }
        else
        {
            TS_FAIL("testdeconfigPresentByAssoc2: incorrect configuration returned");
            for (uint8_t i=0;i<l_targToDeconfig.size();i++)
            {
                char *s = l_targToDeconfig[i].affinityPath.toString();
                TS_WARN("deconfig %s reason %x",s, l_targToDeconfig[i].reason);
                free(s);
            }
        }
    }

    /**
     *  @brief Test Deconfig Present Association 3
     */
    void testdeconfigPresentByAssoc3()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc3: Started");
        // This test the scenario where MEMBUF Group 1 has no MCS and then
        // DIMM Group 1 has no MEMBUF because MEMBUF 1 will be marked for
        // deconfigure

        // User-defined number of targets
        size_t NUM_TARGS = 7;

        // Input target vector
        TargetInfoVector l_targets;
        TargetInfo l_TargInfo;
        EntityPath l_ep[NUM_TARGS];
        l_TargInfo.affinityPath = l_ep[0];
        l_targets.insert(l_targets.begin(), NUM_TARGS, l_TargInfo);
        // Output target vector
        TargetInfoVector l_targToDeconfig;

        // Add MCS Group 0
        l_targets[0].pThisTarget = NULL;
        l_targets[0].affinityPath.addLast(TYPE_MCS, 0);
        l_ep[0] = l_targets[0].affinityPath;
        l_targets[0].type = TYPE_MCS;

        // Add MEMBUF Group 0
        l_targets[1].pThisTarget = NULL;
        l_targets[1].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[1].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_ep[1] = l_targets[1].affinityPath;
        l_targets[1].type = TYPE_MEMBUF;

        // Add MBA Group 0
        l_targets[2].pThisTarget = NULL;
        l_targets[2].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[2].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[2].affinityPath.addLast(TYPE_MBA, 0);
        l_ep[2] = l_targets[2].affinityPath;
        l_targets[2].type = TYPE_MBA;

        // Add MBA Group 1
        l_targets[3].pThisTarget = NULL;
        l_targets[3].affinityPath.addLast(TYPE_MCS, 1);
        l_targets[3].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[3].affinityPath.addLast(TYPE_MBA, 0);
        l_ep[3] = l_targets[3].affinityPath; // SHOULD GET DECONFIGURED
        l_targets[3].type = TYPE_MBA;

        // Add MEMBUF Group 1
        l_targets[4].pThisTarget = NULL;
        l_targets[4].affinityPath.addLast(TYPE_MCS, 1);
        l_targets[4].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_ep[4] = l_targets[4].affinityPath; // SHOULD GET DECONFIGURED
        l_targets[4].type = TYPE_MEMBUF;

        // Add DIMM Group 0
        l_targets[5].pThisTarget = NULL;
        l_targets[5].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[5].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[5].affinityPath.addLast(TYPE_MBA, 0);
        l_targets[5].affinityPath.addLast(TYPE_DIMM, 0);
        l_ep[5] = l_targets[5].affinityPath;
        l_targets[5].type = TYPE_DIMM;

        // Add DIMM Group 1
        l_targets[6].pThisTarget = NULL;
        l_targets[6].affinityPath.addLast(TYPE_MCS, 1);
        l_targets[6].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[6].affinityPath.addLast(TYPE_MBA, 0);
        l_targets[6].affinityPath.addLast(TYPE_DIMM, 0);
        l_ep[6] = l_targets[6].affinityPath; // SHOULD GET DECONFIGURED
        l_targets[6].type = TYPE_DIMM;

        presentByAssoc(l_targets, l_targToDeconfig);

        // Check result
        std::sort(l_targToDeconfig.begin(), l_targToDeconfig.end(),
              compareAffinity);
        if ((l_targToDeconfig.size() == 3) &&
            (l_targToDeconfig[0].affinityPath == l_ep[4]) && // 10 MEMBUF
            (l_targToDeconfig[1].affinityPath == l_ep[3]) && // 100 MBA
            (l_targToDeconfig[2].affinityPath == l_ep[6]) )  // 1000 DIMM
        {
            TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc3: Success");
        }
        else
        {
            TS_FAIL("testdeconfigPresentByAssoc3: incorrect configuration returned");
            for (uint8_t i=0;i<l_targToDeconfig.size();i++)
            {
                char *s = l_targToDeconfig[i].affinityPath.toString();
                TS_WARN("deconfig %s reason %x",s, l_targToDeconfig[i].reason);
                free(s);
            }
        }
    }

    /**
     *  @brief Test Deconfig Present Association 4
     */
    void testdeconfigPresentByAssoc4()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc4: Started");
        // This test the scenario where MEMBUF Group 0 has no MBAs causing
        // MCS Group 0 to also be deconfigured.

        // User-defined number of targets
        size_t NUM_TARGS = 2;

        // Input target vector
        TargetInfoVector l_targets;
        TargetInfo l_TargInfo;
        EntityPath l_ep[NUM_TARGS];
        l_TargInfo.affinityPath = l_ep[0];
        l_targets.insert(l_targets.begin(), NUM_TARGS, l_TargInfo);
        // Output target vector
        TargetInfoVector l_targToDeconfig;

        // Add MCS Group 0
        l_targets[0].pThisTarget = NULL;
        l_targets[0].affinityPath.addLast(TYPE_MCS, 0);
        l_ep[0] = l_targets[0].affinityPath; // SHOULD BE DECONFIGURED
        l_targets[0].type = TYPE_MCS;

        // Add MEMBUF Group 0
        l_targets[1].pThisTarget = NULL;
        l_targets[1].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[1].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_ep[1] = l_targets[1].affinityPath; // SHOULD BE DECONFIGURED
        l_targets[1].type = TYPE_MEMBUF;

        presentByAssoc(l_targets, l_targToDeconfig);

        // Check result
        std::sort(l_targToDeconfig.begin(), l_targToDeconfig.end(),
              compareAffinity);
        if ((l_targToDeconfig.size() == 2) &&
            (l_targToDeconfig[0].affinityPath == l_ep[0]) && // 0 MCS
            (l_targToDeconfig[1].affinityPath == l_ep[1]) )  // 00 MEMBUF
        {
            TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc4: Success");
        }
        else
        {
            TS_FAIL("testdeconfigPresentByAssoc4: incorrect configuration returned");
            for (uint8_t i=0;i<l_targToDeconfig.size();i++)
            {
                char *s = l_targToDeconfig[i].affinityPath.toString();
                TS_WARN("deconfig %s reason %x",s, l_targToDeconfig[i].reason);
                free(s);
            }
        }
    }

    /**
     *  @brief Test Deconfig Present Association 5
     */
    void testdeconfigPresentByAssoc5()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc5: Started");
        // This test the scenario where MEMBUF Group 0 and MBA Group 0 having
        // no MCS. This tests the MCSINDEX edge case because one never existed

        // User-defined number of targets
        size_t NUM_TARGS = 2;

        // Input target vector
        TargetInfoVector l_targets;
        TargetInfo l_TargInfo;
        EntityPath l_ep[NUM_TARGS];
        l_TargInfo.affinityPath = l_ep[0];
        l_targets.insert(l_targets.begin(), NUM_TARGS, l_TargInfo);
        // Output target vector
        TargetInfoVector l_targToDeconfig;

        // Add MEMBUF Group 0
        l_targets[0].pThisTarget = NULL;
        l_targets[0].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[0].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_ep[0] = l_targets[0].affinityPath; // SHOULD BE DECONFIGURED
        l_targets[0].type = TYPE_MEMBUF;

        // Add MBA Group 0
        l_targets[1].pThisTarget = NULL;
        l_targets[1].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[1].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[1].affinityPath.addLast(TYPE_MBA, 0);
        l_ep[1] = l_targets[1].affinityPath; // SHOULD BE DECONFIGURED
        l_targets[1].type = TYPE_MBA;

        presentByAssoc(l_targets, l_targToDeconfig);

        // Check result
        std::sort(l_targToDeconfig.begin(), l_targToDeconfig.end(),
              compareAffinity);
        if ((l_targToDeconfig.size() == 2) &&
            (l_targToDeconfig[0].affinityPath == l_ep[0]) && // 00 MEMBUF
            (l_targToDeconfig[1].affinityPath == l_ep[1]) )  // 000 MBA
        {
            TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc5: Success");
        }
        else
        {
            TS_FAIL("testdeconfigPresentByAssoc5: incorrect configuration returned");
            for (uint8_t i=0;i<l_targToDeconfig.size();i++)
            {
                char *s = l_targToDeconfig[i].affinityPath.toString();
                TS_WARN("deconfig %s reason %x",s, l_targToDeconfig[i].reason);
                free(s);
            }
        }
    }

    /**
     *  @brief Test Deconfig Present Association 6
     */
    void testdeconfigPresentByAssoc6()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc6: Started");
        // This test the scenario where MBA Group 0 and DIMM Group 0 having
        // no MEMBUF. This tests the MEMBUFIndex edge case because one never existed

        // User-defined number of targets
        size_t NUM_TARGS = 2;

        // Input target vector
        TargetInfoVector l_targets;
        TargetInfo l_TargInfo;
        EntityPath l_ep[NUM_TARGS];
        l_TargInfo.affinityPath = l_ep[0];
        l_targets.insert(l_targets.begin(), NUM_TARGS, l_TargInfo);
        // Output target vector
        TargetInfoVector l_targToDeconfig;

        // Add MBA Group 0
        l_targets[0].pThisTarget = NULL;
        l_targets[0].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[0].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[0].affinityPath.addLast(TYPE_MBA, 0);
        l_ep[0] = l_targets[0].affinityPath; // SHOULD BE DECONFIGURED
        l_targets[0].type = TYPE_MBA;

        // Add DIMM Group 0
        l_targets[1].pThisTarget = NULL;
        l_targets[1].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[1].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[1].affinityPath.addLast(TYPE_MBA, 0);
        l_targets[1].affinityPath.addLast(TYPE_DIMM, 0);
        l_ep[1] = l_targets[1].affinityPath; // SHOULD BE DECONFIGURED
        l_targets[1].type = TYPE_DIMM;

        presentByAssoc(l_targets, l_targToDeconfig);

        // Check result
        std::sort(l_targToDeconfig.begin(), l_targToDeconfig.end(),
              compareAffinity);
        if ((l_targToDeconfig.size() == 2) &&
            (l_targToDeconfig[0].affinityPath == l_ep[0]) && // 000 MBA
            (l_targToDeconfig[1].affinityPath == l_ep[1]) )  // 0000 DIMM
        {
            TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc6: Success");
        }
        else
        {
            TS_FAIL("testdeconfigPresentByAssoc6: incorrect configuration returned");
            for (uint8_t i=0;i<l_targToDeconfig.size();i++)
            {
                char *s = l_targToDeconfig[i].affinityPath.toString();
                TS_WARN("deconfig %s reason %x",s, l_targToDeconfig[i].reason);
                free(s);
            }
        }
    }

    /**
     *  @brief Test Deconfig Present Association 7
     */
    void testdeconfigPresentByAssoc7()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc7: Started");
        // This test the scenario where MBA Group 1 has no DIMMS

        // User-defined number of targets
        size_t NUM_TARGS = 5;

        // Input target vector
        TargetInfoVector l_targets;
        TargetInfo l_TargInfo;
        EntityPath l_ep[NUM_TARGS];
        l_TargInfo.affinityPath = l_ep[0];
        l_targets.insert(l_targets.begin(), NUM_TARGS, l_TargInfo);
        // Output target vector
        TargetInfoVector l_targToDeconfig;

        // Add MCS Group 0
        l_targets[0].pThisTarget = NULL;
        l_targets[0].affinityPath.addLast(TYPE_MCS, 0);
        l_ep[0] = l_targets[0].affinityPath;
        l_targets[0].type = TYPE_MCS;

        // Add MEMBUF Group 0
        l_targets[1].pThisTarget = NULL;
        l_targets[1].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[1].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_ep[1] = l_targets[1].affinityPath;
        l_targets[1].type = TYPE_MEMBUF;

        // Add MBA Group 0
        l_targets[2].pThisTarget = NULL;
        l_targets[2].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[2].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[2].affinityPath.addLast(TYPE_MBA, 0);
        l_ep[2] = l_targets[2].affinityPath;
        l_targets[2].type = TYPE_MBA;

        // Add DIMM Group 0
        l_targets[3].pThisTarget = NULL;
        l_targets[3].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[3].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[3].affinityPath.addLast(TYPE_MBA, 0);
        l_targets[3].affinityPath.addLast(TYPE_DIMM, 0);
        l_ep[3] = l_targets[3].affinityPath;
        l_targets[3].type = TYPE_DIMM;

        // Add MBA Group 1
        l_targets[4].pThisTarget = NULL;
        l_targets[4].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[4].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[4].affinityPath.addLast(TYPE_MBA, 1);
        l_ep[4] = l_targets[4].affinityPath; // SHOULD BE DECONFIGURED
        l_targets[4].type = TYPE_MBA;

        presentByAssoc(l_targets, l_targToDeconfig);

        // Check result
        std::sort(l_targToDeconfig.begin(), l_targToDeconfig.end(),
              compareAffinity);
        if ((l_targToDeconfig.size() == 1) &&
            (l_targToDeconfig[0].affinityPath == l_ep[4]) ) // 001 MBA
        {
            TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc7: Success");
        }
        else
        {
            TS_FAIL("testdeconfigPresentByAssoc7: incorrect configuration returned");
            for (uint8_t i=0;i<l_targToDeconfig.size();i++)
            {
                char *s = l_targToDeconfig[i].affinityPath.toString();
                TS_WARN("deconfig %s reason %x",s, l_targToDeconfig[i].reason);
                free(s);
            }
        }
    }

    /**
     *  @brief Test Deconfig Present Association 8
     */
    void testdeconfigPresentByAssoc8()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc8: Started");
        // This test the scenario where each type is missing it's child
        //  and the cascade

        // User-defined number of targets
        size_t NUM_TARGS = 10;

        // Input target vector
        TargetInfoVector l_targets;
        TargetInfo l_TargInfo;
        EntityPath l_ep[NUM_TARGS];
        l_TargInfo.affinityPath = l_ep[0];
        l_targets.insert(l_targets.begin(), NUM_TARGS, l_TargInfo);
        // Output target vector
        TargetInfoVector l_targToDeconfig;

        // Add MCS Group 0
        l_targets[0].pThisTarget = NULL;
        l_targets[0].affinityPath.addLast(TYPE_MCS, 0);
        l_ep[0] = l_targets[0].affinityPath;
        l_targets[0].type = TYPE_MCS; // SHOULD BE DECONFIGURED

        // Add MEMBUF Group 0
        l_targets[1].pThisTarget = NULL;
        l_targets[1].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[1].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_ep[1] = l_targets[1].affinityPath;
        l_targets[1].type = TYPE_MEMBUF; // SHOULD BE DECONFIGURED

        // Add MBA Group 0
        l_targets[2].pThisTarget = NULL;
        l_targets[2].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[2].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[2].affinityPath.addLast(TYPE_MBA, 0);
        l_ep[2] = l_targets[2].affinityPath;
        l_targets[2].type = TYPE_MBA; // SHOULD BE DECONFIGURED


        // Add MCS Group 1
        l_targets[3].pThisTarget = NULL;
        l_targets[3].affinityPath.addLast(TYPE_MCS, 1);
        l_ep[3] = l_targets[3].affinityPath;
        l_targets[3].type = TYPE_MCS; // SHOULD BE DECONFIGURED


        // Add MCS Group 2
        l_targets[4].pThisTarget = NULL;
        l_targets[4].affinityPath.addLast(TYPE_MCS, 2);
        l_ep[4] = l_targets[4].affinityPath;
        l_targets[4].type = TYPE_MCS;

        // Add MEMBUF Group 0
        l_targets[5].pThisTarget = NULL;
        l_targets[5].affinityPath.addLast(TYPE_MCS, 2);
        l_targets[5].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_ep[5] = l_targets[5].affinityPath;
        l_targets[5].type = TYPE_MEMBUF; // SHOULD BE DECONFIGURED

        // Add MEMBUF Group 1
        l_targets[6].pThisTarget = NULL;
        l_targets[6].affinityPath.addLast(TYPE_MCS, 2);
        l_targets[6].affinityPath.addLast(TYPE_MEMBUF, 1);
        l_ep[6] = l_targets[6].affinityPath;
        l_targets[6].type = TYPE_MEMBUF;

        // Add MBA Group 0
        l_targets[7].pThisTarget = NULL;
        l_targets[7].affinityPath.addLast(TYPE_MCS, 2);
        l_targets[7].affinityPath.addLast(TYPE_MEMBUF, 1);
        l_targets[7].affinityPath.addLast(TYPE_MBA, 0);
        l_ep[7] = l_targets[7].affinityPath;
        l_targets[7].type = TYPE_MBA; // SHOULD BE DECONFIGURED

        // Add MBA Group 1
        l_targets[8].pThisTarget = NULL;
        l_targets[8].affinityPath.addLast(TYPE_MCS, 2);
        l_targets[8].affinityPath.addLast(TYPE_MEMBUF, 1);
        l_targets[8].affinityPath.addLast(TYPE_MBA, 1);
        l_ep[8] = l_targets[8].affinityPath;
        l_targets[8].type = TYPE_MBA;

        // Add DIMM Group 1
        l_targets[9].pThisTarget = NULL;
        l_targets[9].affinityPath.addLast(TYPE_MCS, 2);
        l_targets[9].affinityPath.addLast(TYPE_MEMBUF, 1);
        l_targets[9].affinityPath.addLast(TYPE_MBA, 1);
        l_targets[9].affinityPath.addLast(TYPE_DIMM, 0);
        l_ep[9] = l_targets[9].affinityPath;
        l_targets[9].type = TYPE_DIMM;

        presentByAssoc(l_targets, l_targToDeconfig);

        // Check result
        std::sort(l_targToDeconfig.begin(), l_targToDeconfig.end(),
              compareAffinity);
        if ((l_targToDeconfig.size() == 6) &&
            (l_targToDeconfig[0].affinityPath == l_ep[0]) && // 0 MCS
            (l_targToDeconfig[1].affinityPath == l_ep[1]) && // 00 MEMBUF
            (l_targToDeconfig[2].affinityPath == l_ep[2]) && // 000 MBA
            (l_targToDeconfig[3].affinityPath == l_ep[3]) && // 1 MCS
            (l_targToDeconfig[4].affinityPath == l_ep[5]) && // 20 MEMBUF
            (l_targToDeconfig[5].affinityPath == l_ep[7]) )  // 210 MBA
        {
            TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc8: Success");
        }
        else
        {
            TS_FAIL("testdeconfigPresentByAssoc8: incorrect configuration returned");
            for (uint8_t i=0;i<l_targToDeconfig.size();i++)
            {
                char *s = l_targToDeconfig[i].affinityPath.toString();
                TS_WARN("deconfig %s reason %x",s, l_targToDeconfig[i].reason);
                free(s);
            }
        }
    }

    /**
     *  @brief Test Deconfig Present Association 9
     */
    void testdeconfigPresentByAssoc9()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc9: Started");
        // This test the scenario where each type is missing it's parent
        //  and the cascade

        // User-defined number of targets
        size_t NUM_TARGS = 6;

        // Input target vector
        TargetInfoVector l_targets;
        TargetInfo l_TargInfo;
        EntityPath l_ep[NUM_TARGS];
        l_TargInfo.affinityPath = l_ep[0];
        l_targets.insert(l_targets.begin(), NUM_TARGS, l_TargInfo);
        // Output target vector
        TargetInfoVector l_targToDeconfig;

        // Add MEMBUF Group 0
        l_targets[0].pThisTarget = NULL;
        l_targets[0].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[0].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_ep[0] = l_targets[0].affinityPath;
        l_targets[0].type = TYPE_MEMBUF; // SHOULD BE DECONFIGURED

        // Add MBA Group 0
        l_targets[1].pThisTarget = NULL;
        l_targets[1].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[1].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[1].affinityPath.addLast(TYPE_MBA, 0);
        l_ep[1] = l_targets[1].affinityPath;
        l_targets[1].type = TYPE_MBA; // SHOULD BE DECONFIGURED

        // Add DIMM Group 0
        l_targets[2].pThisTarget = NULL;
        l_targets[2].affinityPath.addLast(TYPE_MCS, 0);
        l_targets[2].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[2].affinityPath.addLast(TYPE_MBA, 0);
        l_targets[2].affinityPath.addLast(TYPE_DIMM, 0);
        l_ep[2] = l_targets[2].affinityPath;
        l_targets[2].type = TYPE_DIMM; // SHOULD BE DECONFIGURED

        // Add MBA Group 1
        l_targets[3].pThisTarget = NULL;
        l_targets[3].affinityPath.addLast(TYPE_MCS, 1);
        l_targets[3].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[3].affinityPath.addLast(TYPE_MBA, 0);
        l_ep[3] = l_targets[3].affinityPath;
        l_targets[3].type = TYPE_MBA; // SHOULD BE DECONFIGURED

        // Add DIMM Group 1
        l_targets[4].pThisTarget = NULL;
        l_targets[4].affinityPath.addLast(TYPE_MCS, 1);
        l_targets[4].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[4].affinityPath.addLast(TYPE_MBA, 0);
        l_targets[4].affinityPath.addLast(TYPE_DIMM, 0);
        l_ep[4] = l_targets[4].affinityPath;
        l_targets[4].type = TYPE_DIMM; // SHOULD BE DECONFIGURED

        // Add DIMM Group 2
        l_targets[5].pThisTarget = NULL;
        l_targets[5].affinityPath.addLast(TYPE_MCS, 2);
        l_targets[5].affinityPath.addLast(TYPE_MEMBUF, 0);
        l_targets[5].affinityPath.addLast(TYPE_MBA, 0);
        l_targets[5].affinityPath.addLast(TYPE_DIMM, 0);
        l_ep[5] = l_targets[5].affinityPath;
        l_targets[5].type = TYPE_DIMM; // SHOULD BE DECONFIGURED

        presentByAssoc(l_targets, l_targToDeconfig);

        // Check result
        std::sort(l_targToDeconfig.begin(), l_targToDeconfig.end(),
              compareAffinity);
        if ((l_targToDeconfig.size() == 6) &&
            (l_targToDeconfig[0].affinityPath == l_ep[0]) &&
            (l_targToDeconfig[1].affinityPath == l_ep[1]) &&
            (l_targToDeconfig[2].affinityPath == l_ep[2]) &&
            (l_targToDeconfig[3].affinityPath == l_ep[3]) &&
            (l_targToDeconfig[4].affinityPath == l_ep[4]) &&
            (l_targToDeconfig[5].affinityPath == l_ep[5]) )
        {
            TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc9: Success");
        }
        else
        {
            TS_FAIL("testdeconfigPresentByAssoc9: incorrect configuration returned");
            for (uint8_t i=0;i<l_targToDeconfig.size();i++)
            {
                char *s = l_targToDeconfig[i].affinityPath.toString();
                TS_WARN("deconfig %s reason %x",s, l_targToDeconfig[i].reason);
                free(s);
            }
        }
    }

};

#endif
