/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/hwasGardTest.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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
#include <targeting/common/utilFilter.H>
#include <hwas/common/hwas.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas_reasoncodes.H>

//  $$  make sure these are disabled before checking in!!
#define DISABLE_UNIT_TESTS        1
#define DISABLE_MCS_UNIT_TESTS    1
#define DISABLE_MBA_UNIT_TESTS    1
#define DISABLE_MEM_UNIT_TESTS    1
#define DISABLE_FC_UNIT_TESTS     1
//$$#define DISABLE_UNIT_TESTS        0

#define DISABLE_OMI_UNIT_TESTS    1

#if DISABLE_OMI_UNIT_TESTS
#define ENABLE_OMI_UNIT_TEST_1    0
#define ENABLE_OMI_UNIT_TEST_2    0
#define ENABLE_OMI_UNIT_TEST_3    0
#define ENABLE_OMI_UNIT_TEST_4    0
#else
#define ENABLE_OMI_UNIT_TEST_1    1
#define ENABLE_OMI_UNIT_TEST_2    1
#define ENABLE_OMI_UNIT_TEST_3    1
#define ENABLE_OMI_UNIT_TEST_4    1
#endif

#define TEST_SAVE_RESTORE_SYSTEM_STATE    0

#include <algorithm>

using namespace HWAS;
using namespace TARGETING;

bool compareAffinityCXX(const TargetInfo t1, const TargetInfo t2)
{
        return t1.affinityPath < t2.affinityPath;
}

// This is used when we test every combination of configured and deconfigured
// PAUs to ensure that the NMMU power-gating rule applies correctly.
const size_t NUM_PAU_PER_PROC = 6;

// This value is used by getAnyTargetByType to indicate that we don't care what
// chiplet the target comes from.
const ATTR_CHIPLET_ID_type ANY_CHIPLET = 0xFF;

/* @brief getAnyTargetByType   Gets a pointer to a child target of a given type with a
 *                             given chiplet ID (or ANY_CHIPLET if it doesn't matter).
 *
 * @param[in] i_parent         The target whose children will be searched.
 * @param[in] i_targetType     The type of target the caller wants.
 * @param[in] i_chipletID      A chiplet ID or the special value ANY_CHIPLET.
 * @return    Target*          Pointer to a target. Never returns nullptr.
 */
Target* getAnyTargetByType(const Target& i_parent,
                           const ATTR_TYPE_type i_targetType,
                           const ATTR_CHIPLET_ID_type i_chipletID = ANY_CHIPLET)
{
    TargetHandleList l_targetList;
    getChildChiplets(l_targetList, &i_parent, i_targetType, false);

    Target* l_target = nullptr;

    for (const auto target : l_targetList)
    {
        if (i_chipletID == ANY_CHIPLET
            || target->getAttr<ATTR_CHIPLET_ID>() == i_chipletID)
        {
            l_target = target;
            break;
        }
    }

    if (!l_target)
    {
        TS_FAIL("getAnyTargetByType: Cannot find instance of target type %s "
                "(chiplet id 0x%02x)",
                attrToString<ATTR_TYPE>(i_targetType),
                i_chipletID);
    }

    return l_target;
}

const size_t NMMU_1_CHIPLET = 3;

const size_t PAU_0_INDEX = 0,
             PAU_4_INDEX = 2,
             PAU_5_INDEX = 3;

/* @brief getNMMU1       Retrieves a pointer to NMMU 1 from a given PROC.
 * @param[in] i_proc     The processor to search
 * @return    Target*    Pointer to NMMU1 on i_proc (never nullptr)
 */
Target* getNMMU1(const Target& i_proc)
{
    return getAnyTargetByType(i_proc, TYPE_NMMU, NMMU_1_CHIPLET);
}

/* @brief getSortedPAUList
 *
 *                  Retrieves a list of functional PAU children of the given PROC
 *                  sorted in ascending order by chip unit number.
 *
 * @param[in] i_proc              The processor to search
 * @return    TargetHandleList    Sorted list of PAUs in i_proc
 */
TargetHandleList getSortedPAUList(const Target& i_proc)
{
    TargetHandleList l_pauList;
    getChildChiplets(l_pauList, &i_proc, TYPE_PAU);

    if (l_pauList.size() != NUM_PAU_PER_PROC)
    {
        TS_FAIL("testDeconfigureNMMU1ByPAU: Unexpected number of "
                " functional PAUs (%d)",
                l_pauList.size());
    }
    else
    {
        std::sort(l_pauList.begin(), l_pauList.end(),
                  [](const Target* const a, const Target* const b)
                  {
                      return a->getAttr<ATTR_CHIP_UNIT>() < b->getAttr<ATTR_CHIP_UNIT>();
                  });

        if (l_pauList[PAU_0_INDEX]->getAttr<ATTR_CHIP_UNIT>() != 0)
        {
            TS_FAIL("testDeconfigureNMMU1ByPAU: Unexpected chip unit in sorted PAU list");
            l_pauList.clear();
        }
        else if (l_pauList[PAU_4_INDEX]->getAttr<ATTR_CHIP_UNIT>() != 4)
        {
            TS_FAIL("testDeconfigureNMMU1ByPAU: Unexpected chip unit in sorted PAU list");
            l_pauList.clear();
        }
        else if (l_pauList[PAU_5_INDEX]->getAttr<ATTR_CHIP_UNIT>() != 5)
        {
            TS_FAIL("testDeconfigureNMMU1ByPAU: Unexpected chip unit in sorted PAU list");
            l_pauList.clear();
        }
    }

    return l_pauList;
}

/* @brief Saves the state of every target's HWAS_STATE and PG attributes.
 */
void saveSystemState()
{
    TargetHandle_t pSys;
    targetService().getTopLevelTarget(pSys);

    TargetHandleList pChildList;
    getChildAffinityTargets(pChildList, pSys, CLASS_NA, TYPE_NA, false);

    for (const auto l_child : pChildList)
    {
        // Get the original state of the child
        const HwasState l_originalState = l_child->getAttr<ATTR_HWAS_STATE>();

        const ATTR_SAVED_STATE_UINT8_type l_savedState = l_originalState.functional;

        // Store it in a scratch attribute for later
        l_child->setAttr<ATTR_SAVED_STATE_UINT8>(l_savedState);

        // If this is a PERV target, store ATTR_PG
        if (l_child->getAttr<ATTR_TYPE>() == TYPE_PERV)
        {
            const ATTR_PG_SAVED_type l_savedAttrPg = l_child->getAttr<ATTR_PG>();
            l_child->setAttr<ATTR_PG_SAVED>(l_savedAttrPg);
        }
    }
}

/* @brief Restores the state of every target's HWAS_STATE and PG attributes.
 */
void restoreSystemState()
{
    TargetHandle_t pSys;
    targetService().getTopLevelTarget(pSys);

    TargetHandleList pChildList;
    getChildAffinityTargets(pChildList, pSys, CLASS_NA, TYPE_NA, false);

    for (const auto l_child : pChildList)
    {
        // Get original HwasState from scratch attribute
        const auto l_savedState = l_child->getAttr<ATTR_SAVED_STATE_UINT8>();

        // Update current HwasState
        HwasState l_state = l_child->getAttr<ATTR_HWAS_STATE>();

        l_state.functional = l_savedState != 0;

        l_child->setAttr<ATTR_HWAS_STATE>(l_state);

        // And if it's a PERV, restore ATTR_PG
        if (l_child->getAttr<ATTR_TYPE>() == TYPE_PERV)
        {
            l_child->setAttr<ATTR_PG>(l_child->getAttr<ATTR_PG_SAVED>());
        }
    }
}

class HwasGardTest: public CxxTest::TestSuite
{
public:
    /**
     *  @brief Test which verifies all targets have a valid deconfig rule
     */
    void testParentDeconfigRules()
    {
        // @TODO RTC 243399: Fix parent deconfig rules for new targets
        return;

        TS_TRACE(INFO_MRK "testParentDeconfigRules: Started");
        HWAS_INF("testParentDeconfigRules: Started");

        TARGETING::TargetIterator l_pTarget;
        for(    l_pTarget = TARGETING::targetService().begin();
                l_pTarget != TARGETING::targetService().end();
                ++l_pTarget
           )
        {
            TARGETING::ATTR_PARENT_DECONFIG_RULES_type l_rules =
                l_pTarget->getAttr<ATTR_PARENT_DECONFIG_RULES>();
            if (l_rules.valid == 0)
            {
                TS_FAIL("testParentDeconfigRules: 0x%.8X target has invalid ATTR_PARENT_DECONFIG_RULES",
                  TARGETING::get_huid(*l_pTarget));
            }
        }
        HWAS_INF("testParentDeconfigRules: Ended");
    }

    /*
     * @brief Checks if the OMI tests should be run for the current model
     */
    bool applicableModel()
    {
        bool result = false;
        TargetHandle_t masterProc = nullptr;
        targetService().masterProcChipTargetHandle(masterProc);

        HWAS_ASSERT(masterProc, "applicableModel: Couldn't get master proc");

        auto model = masterProc->getAttr<ATTR_MODEL>();

        if (model == MODEL_AXONE)
        {
            result = true;
        }

        return result;

    }

    void testSaveRestoreState()
    {
#if TEST_SAVE_RESTORE_SYSTEM_STATE
        // find an fc unit that we can play with
        Target * pSys;
        targetService().getTopLevelTarget(pSys);

        PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
        PredicateHwas predFunctional;
        predFunctional.poweredOn(true).present(true).functional(true);
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predFc).push(&predFunctional).And();
        TargetHandleList pFcList;
        targetService().getAssociated( pFcList, pSys,
            TargetService::CHILD, TargetService::ALL, &checkExpr );

        if (pFcList.empty())
        {
            TS_FAIL("testSaveRestoreState: empty pFcList");
        }
        TargetHandle_t l_pTarget = *pFcList.begin();
        saveSystemState();

        // Get current HwasState.
        HwasState l_state = l_pTarget->getAttr<ATTR_HWAS_STATE>();
        HwasState l_originalState = l_state;

        // Change it to something else
        l_state.functional = !l_state.functional;

        l_pTarget->setAttr<ATTR_HWAS_STATE>(l_state);

        restoreSystemState();

        HwasState l_restoState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

        if (l_restoState.functional != l_originalState.functional)
        {
            TS_FAIL("Original state not restored. original = %d, current = %d",
                    l_originalState.functional, l_restoState.functional);
        }
#endif
    }

    /**
     *  @brief Test creating and getting a Deconfigure Record for a
     *      FC Target
     */
    void testDeconfigure2()
    {
        TS_TRACE(INFO_MRK "testDeconfigure2: Started");
        HWAS_INF("testDeconfigure2: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::DeconfigureRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testDeconfigure2: empty pFcList");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();

            // create a deconfigure record
            theDeconfigGard().
                    registerDeferredDeconfigure(*l_pTarget, 0x12);

            // Get that Deconfigure Record for the target
            l_pErr = theDeconfigGard().
                    _getDeconfigureRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
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
                        _getDeconfigureRecords(l_pTarget, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testDeconfigure2: Error from _getDeconfigureRecords");
                break;
            }

            TS_TRACE(INFO_MRK "testDeconfigure2: Success");
        }
        while (0);
    }


    /**
     *  @brief Test Deconfiguring a Target - FC directly
     */

    void testDeconfigure3()
    {
        TS_TRACE(INFO_MRK "testDeconfigure3: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeconfigure3: Skipped");
#else
        HWAS_INF("testDeconfigure3: Started");

        errlHndl_t l_pErr = nullptr;
        saveSystemState();
        do
        {
            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testDeconfigure3: empty pFcList");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();

            // Get the original HWAS_STATE of the target
            HwasState l_origState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            // Deconfigure the target.
            bool l_targetDeconfigured = false;
            l_pErr = theDeconfigGard().deconfigureTarget(*l_pTarget,
                       DeconfigGard::DECONFIGURED_BY_FC_DECONFIG,
                       &l_targetDeconfigured);
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

            HWAS_INF(INFO_MRK "testDeconfigure3: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
#endif
    }

    /**
     *  @brief Test Deconfiguring a Target multiple times directly
     */
    void testDeconfigure4()
    {
        TS_TRACE(INFO_MRK "testDeconfigure4: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeconfigure4: Skipped");
#else
        HWAS_INF("testDeconfigure4: Started");

        errlHndl_t l_pErr = nullptr;

        saveSystemState();
        do
        {
            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testDeconfigure4: empty pFcList");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
#endif
    }

    /**
     *  @brief Test Deconfiguring a PEC Target directly
     */

    void testDeconfigurePECTarget()
    {
        TS_TRACE(INFO_MRK "testDeconfigurePECTarget: Started");

#if DISABLE_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeconfigurePECTarget: Skipped");
#else
        HWAS_INF("testDeconfigurePECTarget: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {
            //Find a functional PEC Target for the deconfigure test
            Target * pSys;
            targetService().getTopLevelTarget(pSys);
            PredicateCTM predPEC(CLASS_UNIT, TYPE_PEC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predPEC).push(&predFunctional).And();
            TargetHandleList l_pecList;
            targetService().getAssociated( l_pecList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            //Verify PEC list isn't empty
            if (l_pecList.empty())
            {
                TS_FAIL("testDeconfigurePECTarget: empty l_pecList");
                break;
            }

            //Iterate PEC targets doing the following
            // 1) Verify PEC is functional
            // 2) Verify Child PHB targets are functional
            // 3) Deconfigure PEC target
            // 4) Verify PEC target is non-functional
            // 5) Verify Child PHB targets are non-functional
            for (auto l_pec : l_pecList)
            {
                // Get the original HWAS_STATE of PEC
                HwasState l_state = l_pec->getAttr<ATTR_HWAS_STATE>();
                if (!l_state.functional)
                {
                    TS_FAIL("testDeconfigurePECTarget: PEC is non-functional"
                            " before deconfiguration");
                    break;
                }

                TargetHandleList l_phbList;
                // Get the list of PHB targets associated with the PEC target
                getChildAffinityTargets(l_phbList, l_pec,
                                        CLASS_NA, TYPE_PHB);

                if (l_phbList.empty())
                {
                    TS_FAIL("testDeconfigurePECTarget: empty l_phbList");
                    break;
                }

                //Iterate through the PHB's
                //   - Verify each is functional
                for (auto l_phb : l_phbList)
                {
                    l_state = l_phb->getAttr<ATTR_HWAS_STATE>();
                    //Verify the PHB is functional
                    if (!l_state.functional)
                    {
                        TS_FAIL("testDeconfigurePECTarget: PHB is non-functional before test");
                        break;
                    }
                }

                // Deconfigure the target PEC and check that works
                l_pErr = theDeconfigGard().
                        deconfigureTarget(*l_pec,
                            DeconfigGard::DECONFIGURED_BY_PEC_DECONFIG);
                if (l_pErr)
                {
                    TS_FAIL("testDeconfigurePECTarget: Error from deconfigureTarget");
                    break;
                }

                l_state = l_pec->getAttr<ATTR_HWAS_STATE>();
                if (l_state.functional)
                {
                    TS_FAIL("testDeconfigurePECTarget: PEC is functional after deconfiguration");
                    break;
                }
                // Reset the HWAS_STATE of PEC
                l_state.functional = 1;
                l_pec->setAttr<ATTR_HWAS_STATE>(l_state);

                // Iterate through child PHB targets and verify they were also
                //     deconfigured
                for (const auto l_phb : l_phbList)
                {
                    TS_TRACE("testDeconfigurePECTarget: PHB: %.8X",
                              get_huid(l_phb));
                    // Get the current HWAS_STATE of PHB
                    l_state = l_phb->getAttr<ATTR_HWAS_STATE>();
                    if (l_state.functional)
                    {
                        TS_FAIL("testDeconfigurePECTarget: PHB Functional after parent PEC deconfigured");
                        break;
                    }
                    //Reset HWAS State of the PHB
                    l_state.functional = 1;
                    l_phb->setAttr<ATTR_HWAS_STATE>(l_state);
                }
            }
        } while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }

#endif
    }

   /**
     *  @brief Verify PEC deconfigured when all PHB's deconfigured
     */
    void testDeconfigurePECwithAllBadPHBs()
    {
        TS_TRACE(INFO_MRK "testDeconfigurePECwithAllBadPHBs: Started");
#if DISABLE_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeconfigurePECwithAllBadPHBs: Skipped");
#else
        HWAS_INF("testDeconfigurePECwithAllBadPHBs: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {
            //Find a functional PEC Target for the deconfigure test
            Target * pSys;
            targetService().getTopLevelTarget(pSys);
            PredicateCTM predPEC(CLASS_UNIT, TYPE_PEC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predPEC).push(&predFunctional).And();
            TargetHandleList l_pecList;
            targetService().getAssociated( l_pecList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            //Verify PEC list isn't empty
            if (l_pecList.empty())
            {
                TS_FAIL("testDeconfigurePECwithAllBadPHBs: empty l_pecList");
                break;
            }

            //Iterate PEC targets doing the following
            // 1) Verify PEC is functional
            // 2) Verify Child PHB targets are functional
            // 3) Deconfigure all child PHB targets
            // 4) Verify PHB targets non-functional
            // 5) Verify PEC is non-functional after all child PHB targets are
            //    deconfigured
            for (auto l_pec : l_pecList)
            {
                HwasState l_state = l_pec->getAttr<ATTR_HWAS_STATE>();
                if (!l_state.functional)
                {
                    TS_FAIL("testDeconfigurePECwithAllBadPHBs: PEC is non-functional before test");
                    break;
                }

                TargetHandleList l_phbList;
                // Get the list of PHB targets associated with the PEC target
                getChildAffinityTargets(l_phbList, l_pec, CLASS_NA, TYPE_PHB);

                //Iterate through the PHB's
                //   - Verify each is functional
                //   - Deconfigure the PHB
                //   - Verify it is now-nonfunctional
                for (auto l_phb : l_phbList)
                {
                    l_state = l_phb->getAttr<ATTR_HWAS_STATE>();
                    //Verify the PHB is functional
                    if (!l_state.functional)
                    {
                        TS_FAIL("testDeconfigurePECwithAllBadPHBs: PHB is non-functional before test");
                        break;
                    }

                    //Deconfigure the PHB Target
                    l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_phb,
                        DeconfigGard::DECONFIGURED_BY_PHB_DECONFIG);
                    if (l_pErr)
                    {
                        TS_FAIL("testDeconfigurePECwithallBadPHBs: Error from deconfigureTarget");
                        break;
                    }

                    //Verify the PHB target is now non-functional
                    l_state = l_phb->getAttr<ATTR_HWAS_STATE>();
                    if (l_state.functional)
                    {
                        TS_FAIL("testDeconfigurePECwithAllBadPHBs: PHB is functional after deconfigure");
                        break;
                    }
                }

                //Verify PEC is now non-functional as all child PHB targets
                //  were deconfigured
                l_state = l_pec->getAttr<ATTR_HWAS_STATE>();
                if (l_state.functional)
                {
                    TS_FAIL("testDeconfigurePECwithAllBadPHBs: PEC is functional after deconfiguring all Child PHBs");
                    break;
                }

                //Reset HWAS State of the PEC
                l_state.functional = 1;
                l_pec->setAttr<ATTR_HWAS_STATE>(l_state);

                //Reset HWAS State of the Child PHB's
                for (auto l_phb : l_phbList)
                {
                    l_state.functional = 1;
                    l_phb->setAttr<ATTR_HWAS_STATE>(l_state);
                }

            }
        } while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }

#endif
    }

    /**
     *  @brief Test Deconfiguring a Target - EQ directly
     */
    void testDeconfigureEQTarget()
    {
        TS_TRACE(INFO_MRK "testDeconfigureEQTarget: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeconfigureEQTarget: Skipped");
#else
        HWAS_INF("testDeconfigureEQTarget: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {
            // find a eq unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEq(CLASS_UNIT, TYPE_EQ);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEq).push(&predFunctional).And();
            TargetHandleList pEqList;
            targetService().getAssociated( pEqList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pEqList.empty())
            {
                TS_FAIL("testDeconfigureEQTarget: empty pFcList");
                break;
            }
            TargetHandle_t l_pTargetEQ = *pEqList.begin();

            // Get the original HWAS_STATE of EQ

            HwasState l_state = l_pTargetEQ->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testDeconfigureEQTarget: EQ is non-functional before deconfiguration");
                break;
            }

            TargetHandleList pFcList, pCoreList[2];
            uint32_t cIndex = 0;
            // get the list of Fcs
            getChildAffinityTargets(pFcList, l_pTargetEQ, CLASS_NA ,TYPE_FC);

            if (pFcList.empty())
            {
                TS_FAIL("testDeconfigureEQTarget: empty pFcList");
                break;
            }

            // Pick up FC and cores and save them

            TargetHandle_t pFc, pCore;
            bool exitLoop = false;
            for (TargetHandleList::iterator pFc_it = pFcList.begin();
                   (pFc_it != pFcList.end()) || exitLoop; ++pFc_it)
            {
                pFc = *pFc_it;
                TS_TRACE("testDeconfigureEQTarget: FC: %.8X",
                         get_huid(pFc));
                // Get the original HWAS_STATE of FC
                l_state = pFc->getAttr<ATTR_HWAS_STATE>();
                if (!l_state.functional)
                {
                    TS_FAIL("testDeconfigureEQTarget: FC is non-functional before deconfiguration");
                    break;
                }
                getChildAffinityTargets(pCoreList[cIndex],
                                    pFc, CLASS_NA ,TYPE_NA);
                if(pCoreList[cIndex].empty())
                {
                    TS_FAIL("testDeconfigureEQTarget: empty pCoreList[%d]", cIndex);
                    exitLoop = true;
                    break;
                }

                for (TargetHandleList::iterator pChild_it =
                       pCoreList[cIndex].begin();
                       pChild_it != pCoreList[cIndex].end(); ++pChild_it)
                {
                    pCore = *pChild_it;
                    TS_TRACE("testDeconfigureEQTarget: Core: %.8X",
                         get_huid(pCore));
                    // Get the original HWAS_STATE of the core
                    l_state = pCore->getAttr<ATTR_HWAS_STATE>();
                    if (!l_state.functional)
                    {
                        TS_FAIL("testDeconfigureEQTarget: Core is non-functional before deconfiguration");
                        exitLoop = true;
                        break;
                    }
                } // for CHILD
                cIndex++;
            } // for pFc_it

            if (exitLoop)
            {
                break;
            }

            // Deconfigure the target EQ
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTargetEQ,
                        DeconfigGard::DECONFIGURED_BY_EQ_DECONFIG);
            if (!l_pErr)
            {
                TS_FAIL("testDeconfigureEQTarget: Did not get expected error from deconfigureTarget");
                break;
            }
            else
            {
                TS_INFO("testDeconfigureEQTarget: Got expected error from deconfigureTarget");
                errlCommit(l_pErr,CXXTEST_COMP_ID);
            }


            l_state = l_pTargetEQ->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testDeconfigureEQTarget: EQ is not functional after deconfiguration attempt!");
                // Reset the HWAS_STATE of EQ
                l_state.functional = 1;
                l_pTargetEQ->setAttr<ATTR_HWAS_STATE>(l_state);
                break;
            }
            else
            {
                TS_INFO("testDeconfigureEQTarget: EQ is functional after deconfiguration attempt (as expected).");
            }

            cIndex = 0;
            for (TargetHandleList::iterator pFc_it = pFcList.begin();
                   (pFc_it != pFcList.end()) || exitLoop; ++pFc_it)
            {
                pFc = *pFc_it;
                TS_TRACE("testDeconfigureEQTarget: FC: %.8X",
                         get_huid(pFc));
                // Get the HWAS_STATE of FC
                l_state = pFc->getAttr<ATTR_HWAS_STATE>();
                if (!l_state.functional)
                {
                    TS_FAIL("testDeconfigureEQTarget: FC is not functional after EQ deconfiguration");
                    break;
                }

                for (TargetHandleList::iterator pChild_it =
                       pCoreList[cIndex].begin();
                       pChild_it != pCoreList[cIndex].end(); ++pChild_it)
                {
                    pCore = *pChild_it;
                    TS_TRACE("testDeconfigureEQTarget: Core: %.8X",
                         get_huid(pCore));
                    // Get the HWAS_STATE of the core
                    l_state = pCore->getAttr<ATTR_HWAS_STATE>();
                    if (!l_state.functional)
                    {
                        TS_FAIL("testDeconfigureEQTarget: Core is not functional after EQ deconfiguration");
                        exitLoop = true;
                        break;
                    }
                    // Reset the HWAS_STATE of the core
                    l_state.functional = 1;
                    pCore->setAttr<ATTR_HWAS_STATE>(l_state);
                } // for CHILD
                cIndex++;
            }

            TS_TRACE(INFO_MRK "testDeconfigureEQTarget: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc1()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssoc1: Started");
#if DISABLE_MBA_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeconfigureAssoc1: Skipped");
#else
        HWAS_INF("testDeconfigureAssoc1: Started");

        errlHndl_t l_pErr = nullptr;

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc2()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssoc2: Started");
#if DISABLE_MEM_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeconfigureAssoc2: Skipped");
#else
        HWAS_INF("testDeconfigureAssoc2: Started");

        errlHndl_t l_pErr = nullptr;

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc3()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssoc3: Started");
#if DISABLE_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeconfigureAssoc3: Skipped");
#else
        HWAS_INF("testDeconfigureAssoc3: Started");

        errlHndl_t l_pErr = nullptr;

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }
    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc4()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssoc4: Started");
#if DISABLE_MCS_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeconfigureAssoc4: Skipped");
#else
        HWAS_INF("testDeconfigureAssoc4: Started");

        errlHndl_t l_pErr = nullptr;

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc5()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssoc5: Started");
#if DISABLE_MBA_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversely affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE(" - SKIPPING -- other tests could be adversely affected");
        HWAS_INF("testDeconfigureAssoc5: Skipped");
#else
        HWAS_INF("testDeconfigureAssoc5: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {
            // find a MBA, deconfigure the attached DIMMs
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predMba(CLASS_UNIT, TYPE_MBA);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr funcMbas;
            funcMbas.push(&predMba).push(&predFunctional).And();

            TargetHandleList pMbaList;
            targetService().getAssociated(pMbaList, pSys,
                TargetService::CHILD, TargetService::ALL,
                &funcMbas);

            if (pMbaList.empty())
            {
                TS_FAIL("testDeconfigureAssoc5: empty MBA list");
                break;
            }
            TargetHandle_t l_pMba = pMbaList[0];

            // Get the original HWAS_STATE of the MBA
            HwasState l_origState = l_pMba->getAttr<ATTR_HWAS_STATE>();

            // find all DIMM targets
            PredicateCTM predDimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
            PredicatePostfixExpr funcDimms;
            funcDimms.push(&predDimm).push(&predFunctional).And();
            TargetHandleList pDimmList;
            targetService().getAssociated(pDimmList, l_pMba,
                    TargetService::CHILD_BY_AFFINITY, TargetService::ALL,
                    &funcDimms);
            if (pDimmList.empty())
            {
                TS_FAIL("testDeconfigureAssoc5: empty DIMM list");
                break;
            }

            // deconfigure all but one DIMM
            for (auto i = pDimmList.size() - 1;i > 0;--i)
            {
                TargetHandle_t l_pDimm = pDimmList[i];

                // Deconfigure the DIMM.
                l_pErr = theDeconfigGard().
                        deconfigureTarget(*l_pDimm, 0xA5);
                if (l_pErr)
                {
                    TS_FAIL("testDeconfigureAssoc5: Error from deconfigureTarget");
                    break;
                }
            }
            // Check the HWAS_STATE of the MBA
            HwasState l_state = l_pMba->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testDeconfigureAssoc5: MBA not functional after deconfiguring most DIMMS");
                break;
            }

            // deconfigure last functional DIMM
            TargetHandle_t l_pLastDimm = pDimmList[0];
            l_pErr = theDeconfigGard().deconfigureTarget(*l_pLastDimm, 0xA6);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigureAssoc5: Error from deconfigureTarget");
                break;
            }
            // Check the HWAS_STATE of the MBA
            l_state = l_pMba->getAttr<ATTR_HWAS_STATE>();
            if (l_state.functional)
            {
                TS_FAIL("testDeconfigureAssoc5: MBA functional after deconfiguring all DIMMS");
                break;
            }

            // Reset the HWAS_STATE of the DIMMs and MBA
            ATTR_HWAS_STATE_type functionalHwasState = {0};
            functionalHwasState.functional = true;
            for (auto l_pDimm: pDimmList)
                l_pDimm->setAttr<ATTR_HWAS_STATE>(functionalHwasState);
            l_pMba->setAttr<ATTR_HWAS_STATE>(l_origState);

            TS_TRACE(INFO_MRK "testDeconfigureAssoc5: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr, CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     *
     *  Ensure that if a parent of an MBA being deconfigured is not present
     *  (due to some other bug) that the deconfig by association code properly
     *  handles it.
     *
     */
    void testDeconfigureAssoc6()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssoc6: Started");
#if DISABLE_MEM_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeconfigureAssoc6: Skipped");
#else
        HWAS_INF("testDeconfigureAssoc6: Started");

        errlHndl_t l_pErr = nullptr;

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
                TS_FAIL("testDeconfigureAssoc6: empty pMembuf");
                break;
            }
            TargetHandle_t l_pTarget = *pMembuf.begin();

            // Get the original HWAS_STATE of the target
            HwasState l_origState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            // Get it's parent DMI target
            TargetHandleList pParentDmiList;
            getParentAffinityTargetsByState(pParentDmiList, l_pTarget,
                    CLASS_UNIT, TYPE_DMI, UTIL_FILTER_PRESENT);
            if (pParentDmiList.empty())
            {
                TS_FAIL("testDeconfigureAssoc6: empty pParentDmiList");
                break;
            }
            TargetHandle_t l_parentTgt = *pParentDmiList.begin();

            // Save off parent state and set to not present
            HwasState l_parOrigState = l_parentTgt->getAttr<ATTR_HWAS_STATE>();
            HwasState l_parTestState = l_parOrigState;
            l_parTestState.present = 0;
            l_parentTgt->setAttr<ATTR_HWAS_STATE>(l_parTestState);

            // Deconfigure the target.
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTarget, 0xA2);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigureAssoc6: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE of the target
            HwasState l_state = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            if (l_state.functional)
            {
                TS_FAIL("testDeconfigureAssoc6: target functional after deconfigure");
                break;
            }

            // Reset the HWAS_STATE of the target and it's parent
            l_pTarget->setAttr<ATTR_HWAS_STATE>(l_origState);
            l_parentTgt->setAttr<ATTR_HWAS_STATE>(l_parOrigState);

            TS_TRACE(INFO_MRK "testDeconfigureAssoc6: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test FC with no good cores should be deconfigured
     */
    void testDeConfigFC2BadCores()
    {
        TS_TRACE(INFO_MRK "testDeConfigFC2BadCores: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeConfigFC2BadCores: Skipped");
#else
        HWAS_INF("testDeConfigFC2BadCores: Started");

        errlHndl_t l_pErr = nullptr;
        do
        {

            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);

            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();

            TargetHandleList pFcList, pCoreList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testDeConfigFC2BadCores: empty pFcList");
                break;
            }

            // Pick up first FC
            TargetHandle_t pFc = *pFcList.begin();
            HWAS_INF("testDeConfigFC2BadCores FC: %.8X",
                       get_huid(pFc));
            HwasState l_State, fc_State, ofc_State;
            TargetHandle_t pCore;

            // find all CHILD_BY_AFFINITY matches for this FC i.e. cores
            // set state non-functional
            getChildAffinityTargets(pCoreList, pFc, CLASS_NA, TYPE_NA);
            if(pCoreList.empty())
            {
                TS_FAIL("testDeconfigFC2BadCores: empty pCoreList");
                break;
            }

            for (TargetHandleList::iterator pChild_it = pCoreList.begin();
                   pChild_it != pCoreList.end(); ++pChild_it)
            {
                pCore = *pChild_it;
                HWAS_INF("testDeConfigFC2BadCores Core: %.8X",
                         get_huid(pCore));
                // Get the original HWAS_STATE of the target
                l_State = pCore->getAttr<ATTR_HWAS_STATE>();
                l_State.functional  =   0 ;
                pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            } // for CHILD

            // Get the HWAS_STATE of FC
            ofc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            if (!ofc_State.functional)
            {
                TS_FAIL("testDeConfigFC2BadCores: Fc non-functional, expected functional");
                break;
            }

            // Deconfigure any of the core
            pCore = *pCoreList.begin();
            l_pErr = theDeconfigGard().deconfigureTarget(*pCore,
                          DeconfigGard::DECONFIGURED_BY_CORE_DECONFIG);
            if (l_pErr)
            {
                TS_FAIL("testDeConfigFC2BadCores: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE FC
            fc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            if (fc_State.functional)
            {
                TS_FAIL("testDeConfigFC2BadCores: Fc functional when cores non-functional");
                break;
            }

            // Reset the HWAS_STATE of FC
            pFc->setAttr<ATTR_HWAS_STATE>(ofc_State);

            // reset all core states
            for (TargetHandleList::iterator pChild_it = pCoreList.begin();
                   pChild_it != pCoreList.end(); ++pChild_it)
            {
                TargetHandle_t pCore = *pChild_it;
                HWAS_INF("testDeConfigFC2BadCores Core: %.8X",
                         get_huid(pCore));
                // Get the original HWAS_STATE of the target
                l_State = pCore->getAttr<ATTR_HWAS_STATE>();
                l_State.functional  =   1 ;
                pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            } // for CHILD
            HWAS_INF(INFO_MRK "testDeConfigFC2BadCores: Success");
        }
        while (0);

#endif
    }

    /**
     *  @brief Test FC with one good and one bad core should not be deconfigured
     */

    void testDeConfigFC1BadCore()
    {
        TS_TRACE(INFO_MRK "testDeConfigFC1BadCore: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeConfigFC1BadCore: Skipped");
#else
        HWAS_INF("testDeConfigFC1BadCore: Started");

        errlHndl_t l_pErr = nullptr;
        do
        {

            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);

            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();

            TargetHandleList pFcList, pCoreList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testDeConfigFC1BadCore: empty pFcList");
                break;
            }

            // Pick up first FC
            TargetHandle_t pFc = *pFcList.begin();
            TS_TRACE("testDeConfigFC1BadCore FC: %.8X",
                       get_huid(pFc));
            HwasState l_State, fc_State, ofc_State;
            TargetHandle_t pCore;

            // find all CHILD_BY_AFFINITY matches for this FC i.e. cores
            // set state non-functional
            getChildAffinityTargets(pCoreList, pFc, CLASS_NA, TYPE_NA);
            if(pCoreList.empty())
            {
                TS_FAIL("testDeconfigFC1BadCores: empty pCoreList");
                break;
            }

            // Set first core state non-functional
            TargetHandleList::iterator pChild_it = pCoreList.begin();
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            l_State.functional  =   0 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            // Set second core state functional
            ++pChild_it;
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            // Get the HWAS_STATE of FC
            ofc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            if (!ofc_State.functional)
            {
                TS_FAIL("testDeConfigFC1BadCore: Fc non-functional, expected functional");
                break;
            }

            // Deconfigure the first core
            pCore = *pCoreList.begin();
            l_pErr = theDeconfigGard().deconfigureTarget(*pCore,
                          DeconfigGard::DECONFIGURED_BY_CORE_DECONFIG);
            if (l_pErr)
            {
                TS_FAIL("testDeConfigFC1BadCore: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE FC
            fc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            if (!fc_State.functional)
            {
                TS_FAIL("testDeConfigFC1BadCore: Fc non-functional when one core is functional");
                break;
            }

            // Set both cores state functional
            pChild_it = pCoreList.begin();
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            ++pChild_it;
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            TS_TRACE(INFO_MRK "testDeConfigFC1BadCore: Success");
        }
        while (0);

#endif
    }

    /**
     *  @brief Test EQ with no good FCs should NOT be deconfigured
     */
    void testDeConfigEQ2BadFCs()
    {
        TS_TRACE(INFO_MRK "testDeConfigEQ2BadFCs: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeConfigEQ2BadFCs: Skipped");
#else
        HWAS_INF("testDeConfigEQ2BadFCs: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {

            // find a eq unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEq(CLASS_UNIT, TYPE_EQ);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);

            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEq).push(&predFunctional).And();

            TargetHandleList pEqList, pFcList;
            targetService().getAssociated( pEqList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pEqList.empty())
            {
                TS_FAIL("testDeConfigEQ2BadFCs: empty pEqList");
                break;
            }

            // Pick up first EQ
            TargetHandle_t pEq = *pEqList.begin();
            TS_TRACE("testDeConfigEQ2BadFCs EQ: %.8X",
                       get_huid(pEq));
            HwasState l_State, eq_State, oeq_State;
            TargetHandle_t pFc;

            // find all CHILD_BY_AFFINITY matches for this EQ i.e. FCs
            // set state non-functional
            getChildAffinityTargets(pFcList, pEq, CLASS_NA ,TYPE_NA);

            for (TargetHandleList::iterator pChild_it = pFcList.begin();
                   pChild_it != pFcList.end(); ++pChild_it)
            {
                pFc = *pChild_it;
                TS_TRACE("testDeConfigEQ2BadFCs FC: %.8X",
                         get_huid(pFc));
                // Get the original HWAS_STATE of the target
                l_State = pFc->getAttr<ATTR_HWAS_STATE>();
                l_State.functional  =   0 ;
                pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            } // for CHILD

            // Get the HWAS_STATE of EQ
            oeq_State = pEq->getAttr<ATTR_HWAS_STATE>();
            if (!oeq_State.functional)
            {
                TS_FAIL("testDeConfigEQ2BadFCs: Eq non-functional, expected functional");
                break;
            }

            // Deconfigure any of the FC
            pFc = *pFcList.begin();
            l_pErr = theDeconfigGard().deconfigureTarget(*pFc,
                       DeconfigGard::DECONFIGURED_BY_FC_DECONFIG);
            if (l_pErr)
            {
                TS_FAIL("testDeConfigEQ2BadFCs: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE EQ
            eq_State = pEq->getAttr<ATTR_HWAS_STATE>();
            if (!eq_State.functional)
            {
                TS_FAIL("testDeConfigEQ2BadFCs: Deconfig of all Fcs also deconfigured EQ!!");
                break;
            }

            // Reset the HWAS_STATE of FC
            pEq->setAttr<ATTR_HWAS_STATE>(oeq_State);

            // reset all core states
            for (TargetHandleList::iterator pChild_it = pFcList.begin();
                   pChild_it != pFcList.end(); ++pChild_it)
            {
                TargetHandle_t pFc = *pChild_it;
                TS_TRACE("testDeConfigEQ2BadFCs FC: %.8X",
                         get_huid(pFc));
                // Get the original HWAS_STATE of the target
                l_State = pFc->getAttr<ATTR_HWAS_STATE>();
                l_State.functional  =   1 ;
                pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            } // for CHILD
            TS_TRACE(INFO_MRK "testDeConfigEQ2BadFCs: Success");
        }
        while (0);

#endif
    }

    /**
     *  @brief Test EQ with one good and one bad FC should not be deconfigured
     */

    void testDeConfigEQ1BadFC()
    {
        TS_TRACE(INFO_MRK "testDeConfigEQ1BadFC: Started");
#if DISABLE_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeConfigEQ1BadFC: Skipped");
#else
        HWAS_INF("testDeConfigEQ1BadFC: Started");

        errlHndl_t l_pErr = nullptr;
        do
        {

            // find a eq unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predEq(CLASS_UNIT, TYPE_EQ);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);

            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEq).push(&predFunctional).And();

            TargetHandleList pEqList;
            targetService().getAssociated( pEqList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pEqList.empty())
            {
                TS_FAIL("testDeConfigEQ1BadFC: empty pEqList");
                break;
            }

            // Pick up first EQ
            TargetHandle_t pEq = *pEqList.begin();
            TS_TRACE("testDeConfigEQ1BadFC EQ: %.8X", get_huid(pEq));
            HwasState l_State, eq_State, oeq_State;

            // find all CHILD_BY_AFFINITY matches for this FC i.e. cores
            // set state non-functional
            TargetHandleList pFcList;
            TargetHandle_t pFc;
            getChildAffinityTargets(pFcList, pEq, CLASS_NA ,TYPE_NA);

            // Set first core state non-functional
            TargetHandleList::iterator pChild_it = pFcList.begin();
            pFc = *pChild_it;
            l_State = pFc->getAttr<ATTR_HWAS_STATE>();
            l_State.functional  =   0 ;
            pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            // Set second core state functional
            ++pChild_it;
            pFc = *pChild_it;
            l_State = pFc->getAttr<ATTR_HWAS_STATE>();
            l_State.functional  =   1 ;
            pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            // Get the HWAS_STATE of EQ
            oeq_State = pEq->getAttr<ATTR_HWAS_STATE>();
            if (!oeq_State.functional)
            {
                TS_FAIL("testDeConfigEQ1BadFC: Eq non-functional, expected functional");
                break;
            }

            // Deconfigure the first FC
            pFc = *pFcList.begin();
            l_pErr = theDeconfigGard().deconfigureTarget(*pFc,
                         DeconfigGard::DECONFIGURED_BY_FC_DECONFIG);
            if (l_pErr)
            {
                TS_FAIL("testDeConfigEQ1BadFC: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE FC
            eq_State = pEq->getAttr<ATTR_HWAS_STATE>();
            if (!eq_State.functional)
            {
                TS_FAIL("testDeConfigEQ1BadFC: Eq non-functional, one core functional");
                break;
            }

            // Set both FCs state functional
            pChild_it = pFcList.begin();
            pFc = *pChild_it;
            l_State = pFc->getAttr<ATTR_HWAS_STATE>();
            l_State.functional  =   1 ;
            pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            ++pChild_it;
            pFc = *pChild_it;
            l_State = pFc->getAttr<ATTR_HWAS_STATE>();
            l_State.functional  =   1 ;
            pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            TS_TRACE(INFO_MRK "testDeConfigEQ1BadFC: Success");
        }
        while (0);

#endif
    }

    /**
     *  @brief Test in fused core mode FC with one good and one bad core
     *  should be deconfigured
     */

    void testDeConfigFCInFusedCoreMode()
    {
        TS_TRACE(INFO_MRK "testDeConfigFCInFusedCoreMode: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testDeConfigFCInFusedCoreMode: Skipped");
#else
        HWAS_INF("testDeConfigFCInFusedCoreMode: Started");

        Target * pSys = nullptr;
        targetService().getTopLevelTarget(pSys);

        // query original fuse mode
        auto l_oFusedMode = pSys->getAttr<ATTR_FUSED_CORE_OPTION>();

        errlHndl_t l_pErr = nullptr;
        do
        {

            // force fused core mode
            pSys->setAttr<ATTR_FUSED_CORE_OPTION>(FUSED_CORE_OPTION_USING_FUSED_CORES);
            if(!is_fused_mode())
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: Unable to force fused core mode");
                break;
            }

            // find an fc unit that we can play with
            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);

            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();

            TargetHandleList pFcList, pCoreList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: empty pFcList");
                break;
            }

            // Pick up first FC
            TargetHandle_t pFc = *pFcList.begin();
            TS_TRACE("testDeConfigFCInFusedCoreMode FC: %.8X",
                       get_huid(pFc));
            HwasState l_State, fc_State, ofc_State;
            TargetHandle_t pCore;

            // find all CHILD_BY_AFFINITY matches for this FC i.e. cores
            // set state non-functional
            getChildAffinityTargets(pCoreList, pFc, CLASS_NA ,TYPE_NA);
            if (pCoreList.empty())
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: empty pCoreList");
                break;
            }

            // Set first core state non-functional
            TargetHandleList::iterator pChild_it = pCoreList.begin();
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            l_State.functional  =   0 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            // Set second core state functional
            ++pChild_it;
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            // Get the HWAS_STATE of FC
            ofc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            if (!ofc_State.functional)
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: Fc non-functional, expected functional");
                break;
            }

            // Deconfigure the first core
            pCore = *pCoreList.begin();
            l_pErr = theDeconfigGard().deconfigureTarget(*pCore,
                         DeconfigGard::DECONFIGURED_BY_CORE_DECONFIG);
            if (l_pErr)
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE FC
            fc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            if (fc_State.functional)
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: Fc functional in Fused Core Mode");
                break;
            }

            // Reset FC state
            fc_State.functional = 1;
            pFc->setAttr<ATTR_HWAS_STATE>(fc_State);

            // Set both cores state functional
            pChild_it = pCoreList.begin();
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            if (l_State.functional)
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: Core1 is functional in Fused Core Mode");
                break;
            }
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            ++pChild_it;
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            if (l_State.functional)
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: Core2 is functional in Fused Core Mode");
                break;
            }
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            TS_TRACE(INFO_MRK "testDeConfigFCInFusedCoreMode: Success");
        }
        while (0);

        //restore original fused mode
        pSys->setAttr<ATTR_FUSED_CORE_OPTION>(l_oFusedMode);

#endif
    }

    /**
     *  @brief Test EQ with no good FCs should NOT be deconfigured
     */
    /**
     *  @brief Test Deconfiguring a Target via deferred
     */
    void testDefDeconfig1()
    {
        TS_TRACE(INFO_MRK "testDefDeconfig1: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        HWAS_INF("testDefDeconfig1: Skipped");
#else
        HWAS_INF("testDefDeconfig1: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::DeconfigureRecords_t l_records;

        saveSystemState();
        do
        {
            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testDefDeconfig1: empty pFcList");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();

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
            theDeconfigGard().processDeferredDeconfig();

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
#endif
    }

    /**
     *  @brief Test getting all GARD Records
     */
    void testGard1()
    {
        TS_TRACE(INFO_MRK "testGard1: Started");
        HWAS_INF("testGard1: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
            TS_FAIL("testGard1: Error from getGardRecords(nullptr)");
        }
        else
        {
            TS_TRACE(INFO_MRK "testGard1: get(nullptr) Success. %d records",
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
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testGard4: Skipped");
#else
        HWAS_INF("testGard4: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testGard4: empty pFcList");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test creating a GARD Record for a Target multiple times
     */
    void testGard5()
    {
        TS_TRACE(INFO_MRK "testGard5: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testGard5: Skipped");
#else
        HWAS_INF("testGard5: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testGard5: empty pFcList");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test creating a 2nd GARD Record overwrites manual gard
     */
    void testGard6()
    {
        TS_TRACE(INFO_MRK "testGard6: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testGard6: Skipped");
#else
        HWAS_INF("testGard6: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testGard6: empty pFcList");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test getting and clearing all GARD Records
     */
    void testGard7()
    {
        TS_TRACE(INFO_MRK "testGard7: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testGard7: Skipped");
#else
        HWAS_INF("testGard7: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testGard7: empty pFcList");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();

            // Get all existing GARD Records
            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);

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
            l_pErr = theDeconfigGard().clearGardRecords(nullptr);

            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from clearGardRecords(nullptr)");
                break;
            }

            // Get the GARD Records
            l_records.clear();

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
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
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testGard8: Skipped");
#else
        HWAS_INF("testGard8: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testGard8: Error from getGardRecords");
                break;
            }

            if (l_records.size() > 0)
            {
                TS_FAIL("testGard8: already GARD records here. %d records",
                        l_records.size());
                break;
            }
            // find an fc unit that we can play with

            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();

            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testGard8: empty pFcList");
                break;
            }

            TargetHandle_t l_target = *pFcList.begin();

            // create GARD record, call 'doGard' step and confirm target is
            //  deconfigured
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_target, 0x12, GARD_Void);
            if (l_pErr)
            {
                TS_FAIL("testGard8: Error from platCreateGardRecord");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
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

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test CDM modes to restrict creating GARD records
     */
    void testGard9()
    {
        TS_TRACE(INFO_MRK "testGard9: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testGard9: Skipped");
#else
        HWAS_INF("testGard9: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testGard9: empty pFcList");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();

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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test CDM modes to restrict processing GARD records
     */
    void testGard10()
    {
        TS_TRACE(INFO_MRK "testGard10: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testGard10: Skipped");
#else
        HWAS_INF("testGard10: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testGard10: Error from getGardRecords");
                break;
            }

            if (l_records.size() > 0)
            {
                TS_FAIL("testGard10: already GARD records here. %d records",
                        l_records.size());
                break;
            }

            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();

            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testGard10: empty pFcList");
                break;
            }

            TargetHandle_t l_target = *pFcList.begin();

            // create GARD record, set Policy, call 'doGard' step and confirm
            //  target is NOT deconfigured
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_target, 0x12, GARD_Predictive);
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from platCreateGardRecord");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
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
            l_pErr = theDeconfigGard().clearGardRecords(nullptr);
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from clearGardRecords(nullptr)");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
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

            //  Clear out policy
            l_policies = 0;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_target, 0x12, GARD_Predictive);
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from platCreateGardRecord");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
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
            l_pErr = theDeconfigGard().clearGardRecords(nullptr);
            if (l_pErr)
            {
                TS_FAIL("testGard10: Error from clearGardRecords(nullptr)");
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
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }

    /**
     *  @brief Test create GARD record, call collect GARD to confirm targets
     *      are deconfigured, set changed bit ala HCDB, reprocess GARD to
     *      confirm GARD record is deleted.
     */
    void testGard11()
    {
        TS_TRACE(INFO_MRK "testGard11: Started");
#if DISABLE_FC_UNIT_TESTS
        // these tests deconfigure and gard targets. and even though they
        //  restore their state after the tests, since the cxxtests are
        //  all run in parallel, during the time that a target is non-
        //  functional due to this test, another test may be running that
        //  might be adversly affected.
        // tests are left in the code so that a developer can enable them
        //  to test these specific functions - just keep in mind that there
        //  could be side effects in other cxxtests.
        TS_TRACE( " - SKIPPING -- other tests could be adversly affected");
        HWAS_INF("testGard11: Skipped");
#else
        HWAS_INF("testGard11: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testGard11: Error from getGardRecords");
                break;
            }

            if (l_records.size() > 0)
            {
                TS_FAIL("testGard11: already GARD records here. %d records",
                        l_records.size());
                break;
            }

            // Go through all targets to ensure changed flags are cleared
            for (TargetIterator t_iter = targetService().begin();
                 t_iter != targetService().end();
                 ++t_iter)
            {
                Target* l_pTarget = *t_iter;

                // Clear bits in changed flags for the target
                ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK_type l_mask =
                    l_pTarget->
                        getAttr<ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK>();
                clear_hwas_changed_bit(l_pTarget,
                                       static_cast<HWAS_CHANGED_BIT>(l_mask));
            } // for

            // find an fc unit that we can play with
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();

            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            if (pFcList.empty())
            {
                TS_FAIL("testGard11: empty pFcList");
                break;
            }

            TargetHandle_t l_target = *pFcList.begin();

            // Save ATTR_BLOCK_SPEC_DECONFIG value
            TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_orig_block_spec_deconfig
                = pSys->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();

            // Allow speculative deconfigs (clear ATTR_BLOCK_SPEC_DECONFIG)
            HWAS_INF("testGard11: Allow speculative deconfigs");
            pSys->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(0);

            // create GARD record, call 'doGard' step and confirm target is
            //  deconfigured
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_target, 0x12, GARD_Predictive);
            if (l_pErr)
            {
                TS_FAIL("testGard11: Error from platCreateGardRecord");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testGard11: Error from getGardRecords");
                break;
            }
            if (l_records.size() != 1)
            {
                TS_FAIL("testGard11: should be 1 record; instead %d records",
                        l_records.size());
                break;
            }

            // Note that collectGard() makes various calls, including calls of
            // clearGardRecordsForReplacedTargets() and
            // deconfigureTargetsFromGardRecordsForIpl(i_pPredicate)
            // which in turn calls clearBlockSpecDeconfigForReplacedTargets().
            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard11: Error from collectGard");
                break;
            }

            HwasState l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            if (l_state.functional)
            {
                TS_FAIL("testGard11: target still functional");
                break;
            }

            // Block speculative deconfigs(set ATTR_BLOCK_SPEC_DECONFIG)
            HWAS_INF("testGard11: Block speculative deconfigs");
            pSys->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(1);

            // restore functional state
            l_state.functional = true;
            l_target->setAttr<ATTR_HWAS_STATE>(l_state);

            // call collectGard and confirm Block speculative deconfigs stays
            //  set and target stays functional
            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard11: Error from collectGard call 2");
                break;
            }

            TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_block_spec_deconfig
                = pSys->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
            if(l_block_spec_deconfig == 0)
            {
                TS_FAIL("testGard11: block spec deconfig cleared");
                break;
            }

            l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testGard11: target NOT functional");
                break;
            }

            // emulate HCDB - target changed, call collectGard and confirm Block
            //  speculative deconfigs is cleared and target is deconfigured
            update_hwas_changed_mask(l_target);
            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard11: Error from collectGard call 2");
                break;
            }

            l_block_spec_deconfig = pSys->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
            if(l_block_spec_deconfig != 0)
            {
                TS_FAIL("testGard11: block spec deconfig NOT cleared, is %d",
                        l_block_spec_deconfig);
                break;
            }

            l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testGard11: target NOT functional");
                break;
            }

            // Restore
            l_state.functional = true;
            l_target->setAttr<ATTR_HWAS_STATE>(l_state);
            pSys->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(l_orig_block_spec_deconfig);

            TS_TRACE(INFO_MRK "testGard11: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
#endif
    }


    /**
     *  @brief Test Deconfigure Associated Proc1
     */
    void testDeconfigureAssocProc1()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc1: Started");
        HWAS_INF("testDeconfigureAssocProc1: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 1: TULETA 4 System with Master proc's abus1
        // and proc2 abus1 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_tuletaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_tuletaProcs.insert(l_tuletaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_tuletaProcs[0].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[0].procHUID = 0;                 // HUID
        l_tuletaProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_tuletaProcs[1].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[1].procHUID = 1;                 // HUID
        l_tuletaProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_tuletaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[1].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[1].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[1].iv_pAProcs[0] = &l_tuletaProcs[3];
        l_tuletaProcs[1].iv_pAProcs[1] = &l_tuletaProcs[3];
        // XBus links and states
        l_tuletaProcs[1].iv_pXProcs[0] = &l_tuletaProcs[0];

        // Proc2:
        l_tuletaProcs[2].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[2].procHUID = 2;                 // HUID
        l_tuletaProcs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        l_tuletaProcs[3].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[3].procHUID = 3;                 // HUID
        l_tuletaProcs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        HWAS_INF("testDeconfigureAssocProc2: Started");

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
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_tuletaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_tuletaProcs.insert(l_tuletaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_tuletaProcs[0].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[0].procHUID = 0;                 // HUID
        l_tuletaProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_tuletaProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[0].iv_masterCapable = false;     // Note master proc
        l_tuletaProcs[0].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[0].iv_pAProcs[0] = &l_tuletaProcs[2];
        l_tuletaProcs[0].iv_pAProcs[1] = &l_tuletaProcs[2];
        // XBus links and states
        l_tuletaProcs[0].iv_pXProcs[0] = &l_tuletaProcs[1];

        // Proc1:
        l_tuletaProcs[1].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[1].procHUID = 1;                 // HUID
        l_tuletaProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_tuletaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[1].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[1].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[1].iv_pAProcs[0] = &l_tuletaProcs[3];
        l_tuletaProcs[1].iv_pAProcs[1] = &l_tuletaProcs[3];
        // XBus links and states
        l_tuletaProcs[1].iv_pXProcs[0] = &l_tuletaProcs[0];

        // Proc2:
        l_tuletaProcs[2].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[2].procHUID = 2;                 // HUID
        l_tuletaProcs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        l_tuletaProcs[3].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[3].procHUID = 3;                 // HUID
        l_tuletaProcs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        HWAS_INF("testDeconfigureAssocProc3: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 3: ORLENA System with Master and proc1's
        // xbus1 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 8;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_orlenaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_orlenaProcs.insert(l_orlenaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_orlenaProcs[0].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[0].procHUID = 0;                 // HUID
        l_orlenaProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[1].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[1].procHUID = 1;                 // HUID
        l_orlenaProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[2].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[2].procHUID = 2;                 // HUID
        l_orlenaProcs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[3].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[3].procHUID = 3;                 // HUID
        l_orlenaProcs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[4].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[4].procHUID = 4;                 // HUID
        l_orlenaProcs[4].procFabricGroup = 2;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[5].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[5].procHUID = 5;                 // HUID
        l_orlenaProcs[5].procFabricGroup = 2;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[6].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[6].procHUID = 6;                 // HUID
        l_orlenaProcs[6].procFabricGroup = 3;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[7].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[7].procHUID = 7;                 // HUID
        l_orlenaProcs[7].procFabricGroup = 3;          // FABRIC_GROUP_ID
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
        HWAS_INF("testDeconfigureAssocProc4: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 4: ORLENA System with proc6/7xbus1 and
        // proc2/4 abus2 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 8;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_orlenaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_orlenaProcs.insert(l_orlenaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_orlenaProcs[0].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[0].procHUID = 0;                 // HUID
        l_orlenaProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[1].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[1].procHUID = 1;                 // HUID
        l_orlenaProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[2].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[2].procHUID = 2;                 // HUID
        l_orlenaProcs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[3].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[3].procHUID = 3;                 // HUID
        l_orlenaProcs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[4].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[4].procHUID = 4;                 // HUID
        l_orlenaProcs[4].procFabricGroup = 2;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[5].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[5].procHUID = 5;                 // HUID
        l_orlenaProcs[5].procFabricGroup = 2;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[6].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[6].procHUID = 6;                 // HUID
        l_orlenaProcs[6].procFabricGroup = 3;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[7].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[7].procHUID = 7;                 // HUID
        l_orlenaProcs[7].procFabricGroup = 3;          // FABRIC_GROUP_ID
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
        HWAS_INF("testDeconfigureAssocProc5: Started");

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
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 8;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_orlenaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_orlenaProcs.insert(l_orlenaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_orlenaProcs[0].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[0].procHUID = 0;                 // HUID
        l_orlenaProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[1].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[1].procHUID = 1;                 // HUID
        l_orlenaProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[2].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[2].procHUID = 2;                 // HUID
        l_orlenaProcs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[3].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[3].procHUID = 3;                 // HUID
        l_orlenaProcs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[4].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[4].procHUID = 4;                 // HUID
        l_orlenaProcs[4].procFabricGroup = 2;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[5].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[5].procHUID = 5;                 // HUID
        l_orlenaProcs[5].procFabricGroup = 2;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[6].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[6].procHUID = 6;                 // HUID
        l_orlenaProcs[6].procFabricGroup = 3;          // FABRIC_GROUP_ID
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
        l_orlenaProcs[7].iv_pThisProc = nullptr;          // Target *
        l_orlenaProcs[7].procHUID = 7;                 // HUID
        l_orlenaProcs[7].procFabricGroup = 3;          // FABRIC_GROUP_ID
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
        HWAS_INF("testDeconfigureAssocProc6: Started");

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
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_brazosProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_brazosProcs.insert(l_brazosProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_brazosProcs[0].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[0].procHUID = 0;                 // HUID
        l_brazosProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_brazosProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_brazosProcs[0].iv_masterCapable = true;      // Master proc
        l_brazosProcs[0].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[0].iv_pXProcs[0] = &l_brazosProcs[1];
        l_brazosProcs[0].iv_pXProcs[1] = &l_brazosProcs[2];
        l_brazosProcs[0].iv_pXProcs[3] = &l_brazosProcs[3];
        l_brazosProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_brazosProcs[1].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[1].procHUID = 1;                 // HUID
        l_brazosProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_brazosProcs[2].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[2].procHUID = 2;                 // HUID
        l_brazosProcs[2].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_brazosProcs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_brazosProcs[2].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[2].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[2].iv_pXProcs[0] = &l_brazosProcs[3];
        l_brazosProcs[2].iv_pXProcs[1] = &l_brazosProcs[0];
        l_brazosProcs[2].iv_pXProcs[3] = &l_brazosProcs[1];

        // Proc3:
        l_brazosProcs[3].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[3].procHUID = 3;                 // HUID
        l_brazosProcs[3].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
#if 1 // This failing test seems a bit out-dated and may be system specific.
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
        HWAS_INF("testDeconfigureAssocProc7: Skipped");
#else
        HWAS_INF("testDeconfigureAssocProc7: Started");

        errlHndl_t l_pErr = nullptr;

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
        HWAS_INF("testDeconfigureAssocProc8: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 1: TULETA 4 System with proc2, proc3 and
        // all associated bus endpoints deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_tuletaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_tuletaProcs.insert(l_tuletaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_tuletaProcs[0].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[0].procHUID = 0;                 // HUID
        l_tuletaProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_tuletaProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[0].iv_masterCapable = true;      // Master proc
        l_tuletaProcs[0].iv_deconfigured = false;      // HWAS state
        l_tuletaProcs[0].iv_pAProcs[0] = &l_tuletaProcs[2];
        l_tuletaProcs[0].iv_pAProcs[1] = &l_tuletaProcs[2];
        l_tuletaProcs[0].iv_ADeconfigured[0] = true;
        l_tuletaProcs[0].iv_ADeconfigured[1] = true;
        l_tuletaProcs[0].iv_pXProcs[0] = &l_tuletaProcs[1];

        // Proc1:
        l_tuletaProcs[1].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[1].procHUID = 1;                 // HUID
        l_tuletaProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_tuletaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[1].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[1].iv_deconfigured = false;      // HWAS state
        l_tuletaProcs[1].iv_pAProcs[0] = &l_tuletaProcs[3];
        l_tuletaProcs[1].iv_pAProcs[1] = &l_tuletaProcs[3];
        l_tuletaProcs[1].iv_ADeconfigured[0] = true;
        l_tuletaProcs[1].iv_ADeconfigured[1] = true;
        l_tuletaProcs[1].iv_pXProcs[0] = &l_tuletaProcs[0];

        // Proc2:
        l_tuletaProcs[2].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[2].procHUID = 2;                 // HUID
        l_tuletaProcs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        l_tuletaProcs[3].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[3].procHUID = 3;                 // HUID
        l_tuletaProcs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        HWAS_INF("testDeconfigureAssocProc9: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO 1: TULETA 4 System with Proc 3 NP which is indicated by
        // No Abus endpoints on Proc 1 and 3 and no Xbus endpoint on Proc1

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_tuletaProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_tuletaProcs.insert(l_tuletaProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_tuletaProcs[0].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[0].procHUID = 0;                 // HUID
        l_tuletaProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_tuletaProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[0].iv_masterCapable = true;      // Master proc
        l_tuletaProcs[0].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[0].iv_pAProcs[0] = &l_tuletaProcs[2];
        l_tuletaProcs[0].iv_pAProcs[1] = &l_tuletaProcs[2];
        // XBus links and states
        l_tuletaProcs[0].iv_pXProcs[0] = &l_tuletaProcs[1];

        // Proc1:
        l_tuletaProcs[1].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[1].procHUID = 1;                 // HUID
        l_tuletaProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_tuletaProcs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_tuletaProcs[1].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[1].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_tuletaProcs[1].iv_pXProcs[0] = &l_tuletaProcs[0];

        // Proc2:
        l_tuletaProcs[2].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[2].procHUID = 2;                 // HUID
        l_tuletaProcs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_tuletaProcs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_tuletaProcs[2].iv_masterCapable = false;     // Not master proc
        l_tuletaProcs[2].iv_deconfigured = false;      // HWAS state
        // ABus links and states
        l_tuletaProcs[2].iv_pAProcs[0] = &l_tuletaProcs[0];
        l_tuletaProcs[2].iv_pAProcs[1] = &l_tuletaProcs[0];
        // No xbus because proc3 is "not present"

        // Proc3:
        l_tuletaProcs[3].iv_pThisProc = nullptr;          // Target *
        l_tuletaProcs[3].procHUID = 3;                 // HUID
        l_tuletaProcs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
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
        HWAS_INF("testDeconfigureAssocProc10: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with proc0xbus0 and proc1xbus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_brazosProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_brazosProcs.insert(l_brazosProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_brazosProcs[0].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[0].procHUID = 0;                 // HUID
        l_brazosProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_brazosProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_brazosProcs[0].iv_masterCapable = true;      // Master proc
        l_brazosProcs[0].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[0].iv_pXProcs[0] = &l_brazosProcs[1];
        l_brazosProcs[0].iv_pXProcs[1] = &l_brazosProcs[2];
        l_brazosProcs[0].iv_pXProcs[3] = &l_brazosProcs[3];
        l_brazosProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_brazosProcs[1].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[1].procHUID = 1;                 // HUID
        l_brazosProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_brazosProcs[2].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[2].procHUID = 2;                 // HUID
        l_brazosProcs[2].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_brazosProcs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_brazosProcs[2].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[2].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[2].iv_pXProcs[0] = &l_brazosProcs[3];
        l_brazosProcs[2].iv_pXProcs[1] = &l_brazosProcs[0];
        l_brazosProcs[2].iv_pXProcs[3] = &l_brazosProcs[1];

        // Proc3:
        l_brazosProcs[3].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[3].procHUID = 3;                 // HUID
        l_brazosProcs[3].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        HWAS_INF("testDeconfigureAssocProc11: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with master proc, proc0xbus0 and proc1xbus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_brazosProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_brazosProcs.insert(l_brazosProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_brazosProcs[0].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[0].procHUID = 0;                 // HUID
        l_brazosProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_brazosProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_brazosProcs[0].iv_masterCapable = true;      // Master proc
        l_brazosProcs[0].iv_deconfigured = true;      // HWAS state
        // XBus links and states
        l_brazosProcs[0].iv_pXProcs[0] = &l_brazosProcs[1];
        l_brazosProcs[0].iv_pXProcs[1] = &l_brazosProcs[2];
        l_brazosProcs[0].iv_pXProcs[3] = &l_brazosProcs[3];
        l_brazosProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_brazosProcs[1].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[1].procHUID = 1;                 // HUID
        l_brazosProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_brazosProcs[2].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[2].procHUID = 2;                 // HUID
        l_brazosProcs[2].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_brazosProcs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_brazosProcs[2].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[2].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[2].iv_pXProcs[0] = &l_brazosProcs[3];
        l_brazosProcs[2].iv_pXProcs[1] = &l_brazosProcs[0];
        l_brazosProcs[2].iv_pXProcs[3] = &l_brazosProcs[1];

        // Proc3:
        l_brazosProcs[3].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[3].procHUID = 3;                 // HUID
        l_brazosProcs[3].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        HWAS_INF("testDeconfigureAssocProc12: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with alt master proc, proc0xbus0 and proc1xbus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_brazosProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_brazosProcs.insert(l_brazosProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_brazosProcs[0].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[0].procHUID = 0;                 // HUID
        l_brazosProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_brazosProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_brazosProcs[0].iv_masterCapable = true;      // Master proc
        l_brazosProcs[0].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[0].iv_pXProcs[0] = &l_brazosProcs[1];
        l_brazosProcs[0].iv_pXProcs[1] = &l_brazosProcs[2];
        l_brazosProcs[0].iv_pXProcs[3] = &l_brazosProcs[3];
        l_brazosProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_brazosProcs[1].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[1].procHUID = 1;                 // HUID
        l_brazosProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_brazosProcs[2].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[2].procHUID = 2;                 // HUID
        l_brazosProcs[2].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_brazosProcs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_brazosProcs[2].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[2].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[2].iv_pXProcs[0] = &l_brazosProcs[3];
        l_brazosProcs[2].iv_pXProcs[1] = &l_brazosProcs[0];
        l_brazosProcs[2].iv_pXProcs[3] = &l_brazosProcs[1];

        // Proc3:
        l_brazosProcs[3].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[3].procHUID = 3;                 // HUID
        l_brazosProcs[3].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        HWAS_INF("testDeconfigureAssocProc13: Started");

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
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_brazosProcs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_brazosProcs.insert(l_brazosProcs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_brazosProcs[0].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[0].procHUID = 0;                 // HUID
        l_brazosProcs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_brazosProcs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_brazosProcs[0].iv_masterCapable = true;      // Master proc
        l_brazosProcs[0].iv_deconfigured = true;      // HWAS state
        // XBus links and states
        l_brazosProcs[0].iv_pXProcs[0] = &l_brazosProcs[1];
        l_brazosProcs[0].iv_pXProcs[1] = &l_brazosProcs[2];
        l_brazosProcs[0].iv_pXProcs[3] = &l_brazosProcs[3];
        l_brazosProcs[0].iv_XDeconfigured[0] = true;

        // Proc1:
        l_brazosProcs[1].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[1].procHUID = 1;                 // HUID
        l_brazosProcs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
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
        l_brazosProcs[2].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[2].procHUID = 2;                 // HUID
        l_brazosProcs[2].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_brazosProcs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_brazosProcs[2].iv_masterCapable = false;     // Not master proc
        l_brazosProcs[2].iv_deconfigured = false;      // HWAS state
        // XBus links and states
        l_brazosProcs[2].iv_pXProcs[0] = &l_brazosProcs[3];
        l_brazosProcs[2].iv_pXProcs[1] = &l_brazosProcs[0];
        l_brazosProcs[2].iv_pXProcs[3] = &l_brazosProcs[1];
        l_brazosProcs[2].iv_XDeconfigured[3] = true;

        // Proc3:
        l_brazosProcs[3].iv_pThisProc = nullptr;          // Target *
        l_brazosProcs[3].procHUID = 3;                 // HUID
        l_brazosProcs[3].procFabricGroup = 0;          // FABRIC_GROUP_ID
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

    // @brief Simple type/instance pair describing a component of an entity path
    // for used in presentByAssocTestPath. The instance number defaults to zero.
    struct entityPathComponent
    {
        TYPE targetType;
        int instance = 0;

        entityPathComponent(const TYPE i_type, const int i_instance = 0)
            : targetType(i_type), instance(i_instance)
        { }
    };

    // @brief A structure containing the path to an entity (rooted in
    // sys0node0proc0) and whether the entity should be functional after
    // presentByAssoc is run.
    struct presentByAssocTestPath
    {
        // If true, the target described by entityPathComponents should be
        // functional after presentByAssoc is run, otherwise it should be
        // nonfunctional.
        bool shouldBeFunctional;

        // The affinity path to an entity (rooted in sys0node0proc0) described by
        // instances of entityPathComponent. For example, if entityPathComponents is
        //   { {TYPE_MC, 1}, {TYPE_MI, 0} }
        // then the entity represented is at the path
        //   sys0/node0/proc0/mc1/mi0
        std::vector<entityPathComponent> entityPathComponents;
    };

    // @brief Called at the beginning of a presentByAssoc test to deconfigure
    // all MCs and their children. This is so that whatever targets the test
    // specifies as being initially functional are the only functional targets
    // in the memory targeting hierarchy.
    static void deconfigAllMc()
    {
        TargetHandleList l_funcMCTargetList;
        getAllChiplets(l_funcMCTargetList, TYPE_MC, true);

        for (const auto l_mc : l_funcMCTargetList)
        {
            TargetInfo l_mcinfo;
            l_mcinfo.pThisTarget = l_mc;
            l_mcinfo.affinityPath = l_mc->getAttr<ATTR_AFFINITY_PATH>();
            l_mcinfo.type = l_mc->getAttr<ATTR_TYPE>();

            // Recursively deconfigure children
            deconfigPresentByAssoc(l_mcinfo);
        }
    }

    /* @brief This function runs a test on presentByAssoc.
     *
     * It expects a list of entity paths and functionality expectations; it then
     * deconfigures everything in the memory hierarchy except the targets
     * mentioned in the list of paths, runs presentByAssoc, and then checks that
     * each target mentioned by the test has been deconfigured or not, as
     * specified by each element of the list.
     *
     * @brief i_testPaths List of entity paths to test.
     * @return bool Whether all paths were functional or not as expected.
     */
    static bool runDeconfigPresentByAssocTest(
        const std::vector<presentByAssocTestPath>& i_testPaths
    )
    {
        bool l_success = true;

        TargetHandleList l_targets;

        EntityPath l_root(EntityPath::PATH_AFFINITY);
        l_root.addLast(TYPE_SYS, 0).addLast(TYPE_NODE, 0).addLast(TYPE_PROC, 0);

        // Save the HWAS state of all targets so that we can restore the system
        // state after running the test
        saveSystemState();

        // Start off with everything deconfigured
        deconfigAllMc();

        // Enable all targets listed in the test
        for (const auto& l_targetInfo : i_testPaths)
        {
            auto l_entPath = l_root;

            for (const auto l_component : l_targetInfo.entityPathComponents)
            {
                l_entPath.addLast(l_component.targetType, l_component.instance);
            }

            Target* const l_targ = targetService().toTarget(l_entPath);

            if (!l_targ)
            {
                char* l_affinityPath = l_entPath.toString();

                TS_FAIL("runDeconfigPresentByAssocTest: "
                        "Invalid test case, target does not exist: bad entity path: %s",
                        l_affinityPath);

                free(l_affinityPath);
                l_affinityPath = nullptr;

                return false;
            }

            auto l_hwasState = l_targ->getAttr<ATTR_HWAS_STATE>();
            l_hwasState.functional = true;
            l_targ->setAttr<ATTR_HWAS_STATE>(l_hwasState);

            l_targets.push_back(l_targ);
        }

        // Run presentByAssoc, which should deconfigure targets
        {
            auto l_scratchTargets = l_targets;
            presentByAssoc(l_scratchTargets);
        }

        // Ensure that every target was deconfigured or not, as specified by
        // each test path
        for (size_t i = 0; i < l_targets.size(); ++i)
        {
            const auto& l_target = l_targets[i];
            const auto l_targetInfo = i_testPaths[i];

            if (l_target->getAttr<ATTR_HWAS_STATE>().functional
                != l_targetInfo.shouldBeFunctional)
            {
                char* l_affinityPath
                    = l_target->getAttr<ATTR_AFFINITY_PATH>().toString();

                TS_FAIL("runDeconfigPresentByAssocTest: Testcase failed: "
                        "%s -> functional is %d but should be %d",
                        l_affinityPath,
                        !l_targetInfo.shouldBeFunctional,
                        l_targetInfo.shouldBeFunctional);

                free(l_affinityPath);
                l_affinityPath = nullptr;

                l_success = false;
            }
        }

        restoreSystemState();

        return l_success;
    }

    /**
     *  @brief Test Deconfig Present Association 1
     */
    void testdeconfigPresentByAssoc1()
    {
        TS_TRACE(INFO_MRK "testDeconfigureAssocProc1: Started");
        HWAS_INF("testdeconfigPresentByAssoc1: Started");

        // This tests the scenario where there is 1 mc, mi, omic, mcc, omi and
        // ocmb, mem_port, and dimm

        // This is done to ensure that the algorithm works on each edge case

        const std::vector<presentByAssocTestPath> l_testCases[] =
        {
            // Each one of these is a separate test. Each test has only a single
            // functional target, which is expected to be deconfigured by
            // presentByAssoc.
            {
                { false,      // This target will not be functional after presentByAssoc
                  { TYPE_MC } // Path to the target (rooted in sys0node0proc0, i.e. sys0node0proc0mc0)
                },
            },
            {
                { false, { TYPE_MC, TYPE_MI } },
            },
            {
                { false, { TYPE_MC, TYPE_OMIC } },
            },
            {
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC } },
            },
            {
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
            },
            {
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
            },
            {
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
            },
            {
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
        };

        // Run each testcase
        for (const auto& l_testCase : l_testCases)
        {
            if (!runDeconfigPresentByAssocTest(l_testCase))
            {
                TS_INFO("testdeconfigPresentByAssoc1: incorrect configuration returned");
            }
        }

        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc1: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 2
     */
    void testdeconfigPresentByAssoc2()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc2: Started");
        HWAS_INF("testdeconfigPresentByAssoc2: Started");

        // This test the scenario where MC Group 1 does not have any children
        // MC Group 0 is fully populated

        const std::vector<presentByAssocTestPath> l_testCase = {
            // MC 1 (has nothing)
            { false, { {TYPE_MC, 1} } },

            // MC 0 (fully populated)
            { true, { TYPE_MC } },
            { true, { TYPE_MC, TYPE_MI } },
            { true, { TYPE_MC, TYPE_OMIC } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
        };

        if (!runDeconfigPresentByAssocTest(l_testCase))
        {
            TS_INFO("testdeconfigPresentByAssoc2: incorrect configuration returned");
        }

        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc2: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 3
     */
    void testdeconfigPresentByAssoc3()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc3: Started");
        HWAS_INF("testdeconfigPresentByAssoc3: Started");

        // This test the scenario where OMI group 1 is missing an OCMB chip so
        // it deconfigures the whole chain up to (but not including) the parent
        // MCC

        const std::vector<presentByAssocTestPath> l_testCase = {
            { true, { TYPE_MC } },
            { true, { TYPE_MC, TYPE_MI } },
            { true, { TYPE_MC, TYPE_OMIC } },
            { false, { TYPE_MC, {TYPE_OMIC, 1} } }, // deconfigured because MCC 1 has no functional OMIs
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },

            // OMI group 0
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },

            // OMI group 1
            { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
            // No OCMB chip here
            { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
            { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
        };

        if (!runDeconfigPresentByAssocTest(l_testCase))
        {
            TS_INFO("testdeconfigPresentByAssoc3: incorrect configuration returned");
        }

        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc3: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 4
     */
    void testdeconfigPresentByAssoc4()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc4: Started");
        HWAS_INF("testdeconfigPresentByAssoc4: Started");

        // This test the scenario where OCMB_CHIP Group 0 has no MEM_PORTs causing
        // MC Group 0 to also be deconfigured.

        const std::vector<presentByAssocTestPath> l_testCases[] =
        {
            { // baseline functional
                { true, { TYPE_MC } },
                { true, { TYPE_MC, TYPE_MI } },
                { true, { TYPE_MC, TYPE_OMIC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } }
            },
            { // missing MEM_PORT causes deconfiguration
                { false, { TYPE_MC } },
                { false, { TYPE_MC, TYPE_MI } },
                { false, { TYPE_MC, TYPE_OMIC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } }
            }
        };

        for (const auto& l_testCase : l_testCases)
        {
            if (!runDeconfigPresentByAssocTest(l_testCase))
            {
                TS_INFO("testdeconfigPresentByAssoc4: incorrect configuration returned");
            }
        }

        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc4: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 5
     */
    void testdeconfigPresentByAssoc5()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc5: Started");
        HWAS_INF("testdeconfigPresentByAssoc5: Started");

        // This test the scenario where a PMIC has no OCMB_CHIP parent, we make
        // sure the PMIC is deconfigured

        const std::vector<presentByAssocTestPath> l_testCases[] =
        {
            { // baseline should be functional
                { true, { TYPE_MC } },
                { true, { TYPE_MC, TYPE_MI } },
                { true, { TYPE_MC, TYPE_OMIC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // removing the PMIC shouldn't affect anything
                { true, { TYPE_MC } },
                { true, { TYPE_MC, TYPE_MI } },
                { true, { TYPE_MC, TYPE_OMIC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // remove the OCMB_CHIP and everything should go bad, including the PMIC
                { false, { TYPE_MC } },
                { false, { TYPE_MC, TYPE_MI } },
                { false, { TYPE_MC, TYPE_OMIC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
        };

        for (const auto& l_testCase : l_testCases)
        {
            if (!runDeconfigPresentByAssocTest(l_testCase))
            {
                TS_INFO("testdeconfigPresentByAssoc5: incorrect configuration returned");
            }
        }

        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc5: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 7
     */
    void testdeconfigPresentByAssoc7()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc7: Started");
        HWAS_INF("testdeconfigPresentByAssoc7: Started");

        // This test the scenario where OMI Group 0 has no DIMMS

        const std::vector<presentByAssocTestPath> l_testCases[] =
        {
            { // baseline should be all good except for childless OMIC1
                { true, { TYPE_MC } },
                { true, { TYPE_MC, TYPE_MI } },
                { true, { TYPE_MC, TYPE_OMIC } },
                { false, { TYPE_MC, {TYPE_OMIC, 1} } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },

                // OMI group 0
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },

                // OMI group 1
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } }
            },
            { // When we remove the DIMM for OMI 0 then it should be deconfigured
                { true, { TYPE_MC } },
                { true, { TYPE_MC, TYPE_MI } },
                { true, { TYPE_MC, TYPE_OMIC } }, // not deconfigured because OMI 1 is not deconfigured
                { false, { TYPE_MC, {TYPE_OMIC, 1} } }, // deconfigured because MCC1 has no functional OMI
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },

                // OMI group 0
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                  // no DIMM here

                // OMI group 1
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } }
            }
        };

        for (const auto& l_testCase : l_testCases)
        {
            if (!runDeconfigPresentByAssocTest(l_testCase))
            {
                TS_INFO("testdeconfigPresentByAssoc7: incorrect configuration returned");
            }
        }

        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc7: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 8
     */
    void testdeconfigPresentByAssoc8()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc8: Started");
        HWAS_INF("testdeconfigPresentByAssoc8: Started");

        // This test the scenario where each type is missing it's child
        //  and the cascade

        const std::vector<presentByAssocTestPath> l_testCases[] =
        {
            { // baseline should be all good
                { true, { TYPE_MC } },
                { true, { TYPE_MC, TYPE_OMIC } },
                { true, { TYPE_MC, {TYPE_OMIC, 1} } },

                { true, { TYPE_MC, TYPE_MI } },
                  // MCC0
                  { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                    // MCC0/OMI0
                    { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                      { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // Missing children should bubble up
                { true, { TYPE_MC } },
                { false, { TYPE_MC, TYPE_OMIC } },
                { true, { TYPE_MC, {TYPE_OMIC, 1} } },

                { true, { TYPE_MC, TYPE_MI } },
                  // MCC0
                  { false, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                    // MCC0/OMI0
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
            }
        };

        for (const auto& l_testCase : l_testCases)
        {
            if (!runDeconfigPresentByAssocTest(l_testCase))
            {
                TS_INFO("testdeconfigPresentByAssoc8: incorrect configuration returned");
            }
        }

        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc8: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 9
     */
    void testdeconfigPresentByAssoc9()
    {
        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc9: Started");
        HWAS_INF("testdeconfigPresentByAssoc9: Started");

        // This test the scenario where each type is missing it's parent
        //  and the cascade

        const std::vector<presentByAssocTestPath> l_testCases[] =
        {
            { // baseline should be all good
                { true, { TYPE_MC } },
                { true, { TYPE_MC, TYPE_OMIC } },
                { true, { TYPE_MC, {TYPE_OMIC, 1} } },

                { true, { TYPE_MC, TYPE_MI } },
                  // MCC0
                  { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                    // MCC0/OMI0
                    { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                      { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // Bad parent MC should make all children bad
                { false, { TYPE_MC, TYPE_OMIC } },
                { false, { TYPE_MC, {TYPE_OMIC, 1} } },

                { false, { TYPE_MC, TYPE_MI } },
                  // MCC0
                  { false, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                    // MCC0/OMI0
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // Bad MI should make all children bad
                { false, { TYPE_MC } },
                { false, { TYPE_MC, TYPE_OMIC } },
                { false, { TYPE_MC, {TYPE_OMIC, 1} } },

                  // MCC0
                  { false, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                    // MCC0/OMI0
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // Bad MCC, OMI makes children bad
                { true, { TYPE_MC } },
                { false, { TYPE_MC, TYPE_OMIC } },
                { true, { TYPE_MC, {TYPE_OMIC, 1} } },

                { true, { TYPE_MC, TYPE_MI } },
                  // MCC0
                    // MCC0/OMI0
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // Bad OCMB chip makes children bad
                { true, { TYPE_MC } },
                { true, { TYPE_MC, TYPE_OMIC } },
                { true, { TYPE_MC, {TYPE_OMIC, 1} } },

                { true, { TYPE_MC, TYPE_MI } },
                  // MCC0
                  { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                    // MCC0/OMI0
                    { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                      { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      // missing OCMB chip here
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      // missing OCMB chip here
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // Missing OMIC should make child OMIs bad
                { true, { TYPE_MC } },
                { true, { TYPE_MC, {TYPE_OMIC, 1} } },
                // No OMICs here

                { true, { TYPE_MC, TYPE_MI } },
                  // MCC0
                  { false, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                    // MCC0/OMI0
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            }
        };

        for (const auto& l_testCase : l_testCases)
        {
            if (!runDeconfigPresentByAssocTest(l_testCase))
            {
                TS_INFO("testdeconfigPresentByAssoc9: incorrect configuration returned");
            }
        }

        TS_TRACE(INFO_MRK "testdeconfigPresentByAssoc9: Exit");
    }

    /**
     *  @brief Find an MC target and deconfigure OMIC targets. This should
     *         deconfig the MC parent.
     */
    void testDeconfigureAssocOMI1()
    {
#if ENABLE_OMI_UNIT_TEST_1
        // Save the state of the system before we make any changes.
        saveSystemState();

        TS_INFO(INFO_MRK "testDeconfigureAssocOMI1: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {
            // This test is only relevant to Axone.
            if (!applicableModel())
            {
                TS_INFO(INFO_MRK"testDeconfigureAssocOMI1: Skipped due to N/A"
                        " model");
                break;
            }

            // find an MC
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            PredicateCTM predMC(CLASS_UNIT, TYPE_MC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExprMC;
            checkExprMC.push(&predMC).push(&predFunctional).And();

            TargetHandleList pMcList;
            targetService().getAssociated(pMcList, pSys,
                TargetService::CHILD, TargetService::ALL,
                &checkExprMC);

            if (pMcList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI1: empty MC list");
                break;
            }
            TargetHandle_t l_pMc = pMcList[0];

            // find all OMIC targets
            TargetHandleList l_pOmicList;
            getChildChiplets(l_pOmicList, l_pMc, TYPE_OMIC);

            if (l_pOmicList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI1: empty OMIC list");
                break;
            }

            // deconfigure all but one OMIC
            for (auto i = (l_pOmicList.size() - 1); i > 0; --i)
            {
                TargetHandle_t l_pOmic = l_pOmicList[i];

                // Deconfigure the OMIC.
                l_pErr = theDeconfigGard().
                        deconfigureTarget(*l_pOmic, 0xA5);
                if (l_pErr)
                {
                    TS_FAIL("testDeconfigureAssocOMI1: Error from "
                            "deconfigureTarget");
                    break;
                }
            }

            // Check the HWAS_STATE of the MC
            HwasState l_state = l_pMc->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testDeconfigureAssocOMI1: MC not functional after "
                        "deconfiguring all but one OMIC");
                break;
            }

            // deconfigure last functional OMIC
            TargetHandle_t l_pLastOmic = l_pOmicList[0];
            l_pErr = theDeconfigGard().deconfigureTarget(*l_pLastOmic, 0xA6);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigureAssocOMI1: Error from "
                        "deconfigureTarget");
                break;
            }

            // Check the HWAS_STATE of the MC
            l_state = l_pMc->getAttr<ATTR_HWAS_STATE>();
            if (l_state.functional)
            {
                TS_FAIL("testDeconfigureAssocOMI1: MC functional after "
                        "deconfiguring all OMICS");
                break;
            }

            TS_INFO(INFO_MRK "testDeconfigureAssocOMI1: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr, CXXTEST_COMP_ID);
        }

        // Restore the state of the system prior to the test
        restoreSystemState();

#endif
    }


    /**
     *  @brief Find an MC target and deconfigure it. This should deconfig the
     *         child OMIC targets.
     */
    void testDeconfigureAssocOMI2()
    {
#if ENABLE_OMI_UNIT_TEST_2
        // Save the state of the system before we make any changes.
        saveSystemState();

        TS_INFO(INFO_MRK "testDeconfigureAssocOMI2: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {
            // This test is only relevant to Axone.
            if (!applicableModel())
            {
                TS_INFO(INFO_MRK"testDeconfigureAssocOMI2: Skipped due to N/A"
                        " model");
                break;
            }

            // find an MC
            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            TargetHandleList pMcList;

            getChildAffinityTargets(pMcList, pSys, CLASS_NA ,TYPE_MC, true);

            if (pMcList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI2: empty MC list");
                break;
            }
            TargetHandle_t l_pMc = pMcList[0];

            // find all functional OMIC targets
            TargetHandleList l_pOmicList;
            getChildChiplets(l_pOmicList, l_pMc, TYPE_OMIC, true);

            if (l_pOmicList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI2: empty OMIC list");
                break;
            }

            // Deconfigure the MC target
            l_pErr = theDeconfigGard().deconfigureTarget(*l_pMc, 0xA5);

            bool functionalOmic = false;
            // Check to see if the OMIC targets were deconfigured.
            for (auto l_pOmic : l_pOmicList)
            {
                HwasState l_state = l_pOmic->getAttr<ATTR_HWAS_STATE>();

                if (l_state.functional)
                {
                    TS_FAIL("testDeconfigureAssocOMI1: OMIC functional after "
                            "deconfiguring parent MC");
                    functionalOmic = true;
                    break;
                }
            }
            if (functionalOmic)
            {
                break;
            }
            TS_INFO(INFO_MRK "testDeconfigureAssocOMI2: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr, CXXTEST_COMP_ID);
        }

        // Restore the state of the system prior to the test
        restoreSystemState();
#endif
    }


    /**
     *  @brief Find an OMIC target and deconfigure it. This should deconfig the
     *         child OMI targets.
     */
    void testDeconfigureAssocOMI3()
    {
#if ENABLE_OMI_UNIT_TEST_3
        // Save the state of the system before we make any changes.
        saveSystemState();

        TS_INFO(INFO_MRK "testDeconfigureAssocOMI3: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {
            // This test is only relevant to Axone.
            if (!applicableModel())
            {
                TS_INFO(INFO_MRK"testDeconfigureAssocOMI3: Skipped due to N/A"
                        " model");
                break;
            }

            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            // find an OMIC
            TargetHandleList l_pOmicList;
            getChildChiplets(l_pOmicList, pSys, TYPE_OMIC, true);

            if (l_pOmicList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI3: empty OMIC list");
                break;
            }

            TargetHandle_t l_pOmic = l_pOmicList[0];

            // find all OMI targets
            TargetHandleList l_pOmiList;

            getChildOmiTargetsByState(l_pOmiList, l_pOmic, CLASS_NA,
                                    TYPE_OMI, UTIL_FILTER_FUNCTIONAL);

            if (l_pOmiList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI3: empty OMI list");
                break;
            }

            // Deconfigure the OMIC target
            l_pErr = theDeconfigGard().deconfigureTarget(*l_pOmic, 0xA5);

            bool foundFunctionalOMI = false;
            // Check to see if the OMI targets were deconfigured.
            for (auto l_pOmi : l_pOmiList)
            {
                HwasState l_state = l_pOmi->getAttr<ATTR_HWAS_STATE>();

                if (l_state.functional)
                {
                    TS_FAIL("testDeconfigureAssocOMI3: OMI functional after "
                            "deconfiguring parent OMIC");
                    foundFunctionalOMI = true;
                    break;
                }
            }

            if (!foundFunctionalOMI)
            {
                TS_INFO(INFO_MRK "testDeconfigureAssocOMI3: Success");
            }
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr, CXXTEST_COMP_ID);
        }

        // Restore the state of the system prior to the test
        restoreSystemState();
#endif
    }


    /**
     *  @brief Find an OMIC target and deconfigure OMI targets. This should
     *         deconfig the OMIC parent.
     */
    void testDeconfigureAssocOMI4()
    {
#if ENABLE_OMI_UNIT_TEST_4
        // Save the state of the system before we make any changes.
        saveSystemState();

        TS_INFO(INFO_MRK "testDeconfigureAssocOMI4: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {
            // This test is only relevant to Axone.
            if (!applicableModel())
            {
                TS_INFO(INFO_MRK"testDeconfigureAssocOMI4: Skipped due to N/A"
                        " model");
                break;
            }

            Target * pSys;
            targetService().getTopLevelTarget(pSys);

            // find an OMIC
            TargetHandleList l_pOmicList;
            getChildChiplets(l_pOmicList, pSys, TYPE_OMIC, true);

            if (l_pOmicList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI4: empty OMIC list");
                break;
            }

            TargetHandle_t l_pOmic = l_pOmicList[0];

            // find all OMI targets
            TargetHandleList l_pOmiList;
            getChildOmiTargetsByState(l_pOmiList, l_pOmic, CLASS_NA,
                                    TYPE_OMI, UTIL_FILTER_FUNCTIONAL);

            if (l_pOmiList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI4: empty OMI list");
                break;
            }

            // deconfigure all but one OMI
            for (auto i = (l_pOmiList.size() - 1); i > 0; --i)
            {
                TargetHandle_t l_pOmi = l_pOmiList[i];

                // Deconfigure the OMI.
                l_pErr = theDeconfigGard().
                        deconfigureTarget(*l_pOmi, 0xA5);
                if (l_pErr)
                {
                    TS_FAIL("testDeconfigureAssocOMI4: Error from "
                            "deconfigureTarget");
                    break;
                }
            }

            // Check the HWAS_STATE of the OMIC
            HwasState l_state = l_pOmic->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testDeconfigureAssocOMI4: OMIC not functional after "
                        "deconfiguring all but one OMI");
                break;
            }

            // deconfigure last functional OMI
            TargetHandle_t l_pLastOmi = l_pOmiList[0];
            l_pErr = theDeconfigGard().deconfigureTarget(*l_pLastOmi, 0xA6);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigureAssocOMI4: Error from "
                        "deconfigureTarget");
                break;
            }
            // Check the HWAS_STATE of the OMIC
            l_state = l_pOmic->getAttr<ATTR_HWAS_STATE>();
            if (l_state.functional)
            {
                TS_FAIL("testDeconfigureAssocOMI4: OMIC functional after "
                        "deconfiguring all OMIs");
                break;
            }

            TS_INFO(INFO_MRK "testDeconfigureAssocOMI4: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr, CXXTEST_COMP_ID);
        }

        // Restore the state of the system prior to the test
        restoreSystemState();

#endif
    }

    /**
     * @brief Check the PG rules for PAUs 0, 4 and 5 to see whether NMMU 1 should
     *        be functional or power-gated based on PG information.
     * @param[in] i_sortedPauList   List of PAU targets sorted by chip unit
     * @param[in] i_pgv             The PGV to be used for the PAU targets
     * @param[in] i_stateMap        The state map to be used for the PAU targets
     * @return bool                 Whether NMMU1 should be deconfigured
     */
    static bool shouldNMMU1BeFunctional_pg(const TargetHandleList& i_sortedPauList,
                                           const partialGoodVector& i_pgv,
                                           pgState_map& i_stateMap)
    {
        return    isDescFunctional(i_sortedPauList[PAU_0_INDEX], i_pgv, i_stateMap)
               || isDescFunctional(i_sortedPauList[PAU_4_INDEX], i_pgv, i_stateMap)
               || isDescFunctional(i_sortedPauList[PAU_5_INDEX], i_pgv, i_stateMap);
    }

    /**
     * @brief Test the PG deconfiguration rule for Nest 1 NMMU
     */
    void testHWASNMMU1DeconfigByPAU()
    {
        TS_INFO( "testHWASNMMU1DeconfigByPAU entry" );

        static const pg_entry_t INVALID_PAU = 0xFFFFFFFF;
        static const pg_entry_t l_pauBadPgBit[] =
        {
            0x00040000,
            INVALID_PAU, // Logical PAUs 1 and 2 are not defined;
            INVALID_PAU, // there are only 6 physical PAUs.
            0x00040000,
            0x00040000,
            0x00020000,
            0x00040000,
            0x00020000,
        };

        TargetHandleList l_procList;
        getAllChips(l_procList, TYPE_PROC);

        for (const Target* const l_proc : l_procList)
        {
            const TargetHandleList l_sortedPauList = getSortedPAUList(*l_proc);

            /* This loop will iterate all possible combinations of enabled/disabled
             * PAUs using the least-significant NUM_PAU_PER_PROC bits of
             * l_pauDisableMask as a bitmask (1 = disabled, 0 = enabled), and
             * ensure that if PAUs 0, 4 and 5 are disabled, then NMMU1 gets
             * disabled as well. */

            unsigned int l_pauDisableMask = 0;

            do
            {
                partialGoodVector l_badPgData = pgDataAllGood;

                // Disable each bad PAU
                for (uint32_t i = 0; i < NUM_PAU_PER_PROC; ++i)
                {
                    const bool l_shouldPauBeDisabled = l_pauDisableMask & (1 << i);

                    if (l_shouldPauBeDisabled)
                    {
                        const auto l_chipUnit
                            = l_sortedPauList[i]->getAttr<ATTR_CHIP_UNIT>();

                        const pg_idx_t l_pgIdx
                            = l_sortedPauList[i]->getAttr<ATTR_CHIPLET_ID>();

                        if (l_pauBadPgBit[l_chipUnit] == INVALID_PAU)
                        {
                            TS_FAIL("Invalid PAU chip unit");
                            continue;
                        }

                        l_badPgData[l_pgIdx] |= l_pauBadPgBit[l_chipUnit];

                        pgState_map l_targetStates;

                        if (isDescFunctional(l_sortedPauList[i],
                                             l_badPgData,
                                             l_targetStates)
                            != !l_shouldPauBeDisabled)
                        {
                            TS_FAIL("testHWASNMMU1DeconfigByPAU: Failed to "
                                    "deconfigure PAU %d",
                                    l_chipUnit);
                            continue;
                        }
                    }
                }

                pgState_map l_targetStates;

                const bool l_nmmu1ShouldBeFunctional
                    = shouldNMMU1BeFunctional_pg(l_sortedPauList,
                                                 l_badPgData,
                                                 l_targetStates);

                saveSystemState();

                // Set the PAUs' HWAS_STATE appropriately
                for (Target* const l_pau : l_sortedPauList)
                {
                    auto l_hwasState = l_pau->getAttr<ATTR_HWAS_STATE>();
                    l_hwasState.functional
                        = isDescFunctional(l_pau, l_badPgData, l_targetStates);
                    l_pau->setAttr<ATTR_HWAS_STATE>(l_hwasState);
                }

                // Check NMMU state and compare it to what we expected
                const bool l_nmmu1IsDeconfigured = shouldPowerGateNMMU1(*l_proc);

                if (   ( l_nmmu1IsDeconfigured &&  l_nmmu1ShouldBeFunctional)
                    || (!l_nmmu1IsDeconfigured && !l_nmmu1ShouldBeFunctional))
                {
                    TS_FAIL("testHWASNMMU1DeconfigByPAU: NMMU 1 is not properly "
                            "functional (is %d, should be %d) when PAUs are:",
                            !l_nmmu1ShouldBeFunctional,
                            l_nmmu1ShouldBeFunctional);

                    for (size_t i = 0; i < NUM_PAU_PER_PROC; ++i)
                    {
                        TS_INFO("  PAU%d: %s",
                                l_sortedPauList[i]->getAttr<ATTR_CHIP_UNIT>(),
                                (isDescFunctional(l_sortedPauList[i],
                                                  l_badPgData,
                                                  l_targetStates)
                                 ? "functional"
                                 : "not functional"));
                    }
                }

                restoreSystemState();

                // Go to the next permutation of enabled/disabled PAUs.
                ++l_pauDisableMask;
            } while (l_pauDisableMask < (1 << NUM_PAU_PER_PROC));
        }

        TS_INFO( "testHWASNMMU1DeconfigByPAU exit" );
    }

    /**
     *  @brief Returns whether or not NMMU 1 should be functional based on which
     *         PAU units are disabled according to ATTR_HWAS_STATE
     *  @param[in] i_sortedPauList      List of PAU targets sorted by chip unit
     *  @return bool                    Whether NMMU 1 should be functional
     */
    static bool shouldNMMU1BeFunctional_hwas(const TargetHandleList& i_sortedPauList)
    {
        return    i_sortedPauList[PAU_0_INDEX]->getAttr<ATTR_HWAS_STATE>().functional
               || i_sortedPauList[PAU_4_INDEX]->getAttr<ATTR_HWAS_STATE>().functional
               || i_sortedPauList[PAU_5_INDEX]->getAttr<ATTR_HWAS_STATE>().functional;
    }

    /**
     *  @brief Test the deconfig gard rule for Nest 1 NMMU
     */
    void testDeconfigureNMMU1ByPAU()
    {
        TS_INFO(INFO_MRK "testDeconfigureNMMU1ByPAU: Started");

        TargetHandleList l_procList;
        getAllChips(l_procList, TYPE_PROC);

        for (Target* const l_proc : l_procList)
        {
            const TargetHandleList l_pauList = getSortedPAUList(*l_proc);

            Target* const l_nmmu1 = getNMMU1(*l_proc);

            if (!l_nmmu1)
            {
                continue;
            }

            uint32_t l_pauDisableMask = 0;

            // This loop will iterate over all possible combinations of
            // enabled/disabled PAUs using the lower NUM_PAU_PER_PROC bits of
            // l_pauDisableMask (1 = disabled, 0 = enabled) to ensure that NMMU 1 gets
            // deconfigured appropriately.
            do
            {
                saveSystemState();

                HWAS_INF("testDeconfigureNMMU1ByPAU: Disabling PAUs with mask 0x%02x "
                         " (1 means disable the corresponding PAU)",
                         l_pauDisableMask);

                // Disable masked PAUs
                for (uint32_t i = 0; i < NUM_PAU_PER_PROC; ++i)
                {
                    if (l_pauDisableMask & (1 << i))
                    {
                        theDeconfigGard().deconfigureTarget(*l_pauList[i], 0);

                        if (l_pauList[i]->getAttr<ATTR_HWAS_STATE>().functional)
                        {
                            TS_FAIL("Failed to deconfigure PAU %d",
                                    l_pauList[i]->getAttr<ATTR_CHIP_UNIT>());
                        }
                    }
                }

                // NMMU 1 should have been deconfigured if the right combination of
                // PAUs were deconfigured
                if (l_nmmu1->getAttr<ATTR_HWAS_STATE>().functional
                    != shouldNMMU1BeFunctional_hwas(l_pauList))
                {
                    TS_FAIL("NMMU 1 is not properly functional (is %d, should be %d) "
                            "when PAUs are:",
                            l_nmmu1->getAttr<ATTR_HWAS_STATE>().functional,
                            shouldNMMU1BeFunctional_hwas(l_pauList));

                    for (size_t i = 0; i < NUM_PAU_PER_PROC; ++i)
                    {
                        TS_INFO("  PAU%d: %s",
                                l_pauList[i]->getAttr<ATTR_CHIP_UNIT>(),
                                (l_pauList[i]->getAttr<ATTR_HWAS_STATE>().functional
                                 ? "functional"
                                 : "not functional"));
                    }
                }

                restoreSystemState();

                // Go to the next permutation of enabled/disabled PAUs.
                ++l_pauDisableMask;
            } while (l_pauDisableMask < (1 << NUM_PAU_PER_PROC));
        }
    }

    /**
     *  @brief Test that deconfiguration updates ATTR_PG appropriately
     */
    void testDeconfigureMask()
    {
        TS_INFO(INFO_MRK "testDeconfigureMask: Started");

        struct testcase_t
        {
            ATTR_TYPE_type targetType; // The target type to test
            pg_entry_t attrPgBits;     // The PG bits in the target's PERV to set
                                       // (i.e. the parts that should be disabled)
                                       // Reference: P10 Partial Good Keyword doc153
            ATTR_CHIPLET_ID_type chipletID; // Chiplet to look in for the target
            bool gardable = true;      // Whether this target can be deconfigured
                                       // by a GARD; if not then we just set
                                       // functional = false and call
                                       // updateDeconfigureMask ourselves
        }
        static const testcases[] =
        {
            { TYPE_NMMU, 0x00004000, NMMU_1_CHIPLET },
            { TYPE_PEC,  0x000FFE00, ANY_CHIPLET },
            { TYPE_MC,   0x000DE200, ANY_CHIPLET },
            { TYPE_PAUC, 0x000C6000, 16 }, // This PAUC has 1 PAU
            { TYPE_PAUC, 0x000E6000, 18 }, // This PAUC has 2 PAUs
            { TYPE_PAU,  0x00040000, 17 }, // PAU in PAUC 1
            { TYPE_IOHS, 0x000C4200, ANY_CHIPLET },
            { TYPE_EQ,   0x00080600, ANY_CHIPLET, false },
            { TYPE_PERV, 0x00100000, ANY_CHIPLET, false },
        };

        TargetHandleList l_procList;
        getAllChips(l_procList, TYPE_PROC);

        for (Target* const l_proc : l_procList)
        {
            for (const auto& l_testcase : testcases)
            {
                Target* const l_target = getAnyTargetByType(*l_proc,
                                                            l_testcase.targetType,
                                                            l_testcase.chipletID);

                if (!l_target)
                {
                    continue;
                }

                const char* const l_targetType = l_target->getAttrAsString<ATTR_TYPE>();
                const auto l_huid = get_huid(l_target);

                Target* const l_perv = getTargetWithPGAttr(*l_target);

                if (!l_perv)
                {
                    TS_FAIL("testDeconfigureMask: Cannot get parent PERV for "
                            "target %s (HUID 0x %x)",
                            l_targetType, l_huid);
                    continue;
                }

                saveSystemState();

                // Deconfigure the target if it's not already non-functional. If
                // the target is gardable then use that method of
                // deconfiguration, otherwise juse force ATTR_HWAS_STATE.
                if (l_target->getAttr<ATTR_HWAS_STATE>().functional)
                {
                    if (l_testcase.gardable)
                    {
                        theDeconfigGard().deconfigureTarget(*l_target, 0);
                    }
                    else
                    {
                        ATTR_HWAS_STATE_type l_hwasState
                            = l_target->getAttr<ATTR_HWAS_STATE>();
                        l_hwasState.functional = false;
                        l_target->setAttr<ATTR_HWAS_STATE>(l_hwasState);
                        updateDeconfigureMask(*l_target, l_hwasState);
                    }
                }

                if (l_target->getAttr<ATTR_HWAS_STATE>().functional)
                {
                    TS_FAIL("testDeconfigureMask: Failed to deconfigure target 0x %08x",
                            l_huid);
                    restoreSystemState();
                    continue;
                }

                // Make sure that the deconfigured target has the right ATTR_PG bits
                // set
                if ((l_perv->getAttr<ATTR_PG>() & l_testcase.attrPgBits)
                    != l_testcase.attrPgBits)
                {
                    TS_FAIL("testDeconfigureMask: incorrect ATTR_PG (was 0x%08x, "
                            "expected bits 0x%08x to be set)",
                            l_perv->getAttr<ATTR_PG>(),
                            l_testcase.attrPgBits);
                    restoreSystemState();
                    continue;
                }

                restoreSystemState();
            }
        }
        TS_INFO(INFO_MRK "testDeconfigureMask: Ended");
    }
};

#undef DISABLE_UNIT_TESTS
#undef DISABLE_MBA_UNIT_TESTS
#undef DISABLE_MEM_UNIT_TESTS
#undef DISABLE_FC_UNIT_TESTS
#undef DISABLE_OMI_UNIT_TESTS

#undef ENABLE_OMI_UNIT_TEST_1
#undef ENABLE_OMI_UNIT_TEST_2
#undef ENABLE_OMI_UNIT_TEST_3
#undef ENABLE_OMI_UNIT_TEST_4

#endif
