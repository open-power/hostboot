/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/hwasGardTest.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#include <targeting/targplatutil.H> //assertGetToplevelTarget
#include <hwas/common/hwas.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/hwasPlat.H>
#include <initservice/mboxRegs.H>

// The defines below are here to modify mostly during
// code development and debug to easily turn off and on
// the various tests to isolate any problems that may
// complicate the debug process.

#define DISABLE_UNIT_TESTS        0
#define DISABLE_MCS_UNIT_TESTS    0 // standalone no TYPE_MCS
#define DISABLE_MBA_UNIT_TESTS    0 // standalone no TYPE_MBA
#define DISABLE_MEM_UNIT_TESTS    0 // standalone no TYPE_MEMBUF
#define DISABLE_FC_UNIT_TESTS     0
#define DISABLE_FC_CRASH_UNIT_TESTS  1 //keep disabled, core can crash
#define DISABLE_VERS_UNIT_TESTS   0

#define DISABLE_OMI_UNIT_TESTS    0

#if DISABLE_OMI_UNIT_TESTS
#define ENABLE_OMI_UNIT_TEST_1    0
#define ENABLE_OMI_UNIT_TEST_2    0
#define ENABLE_OMI_UNIT_TEST_3    0
#define ENABLE_OMI_UNIT_TEST_4    0
#define ENABLE_OMI_UNIT_TEST_5    0
#else
#define ENABLE_OMI_UNIT_TEST_1    1
#define ENABLE_OMI_UNIT_TEST_2    1
#define ENABLE_OMI_UNIT_TEST_3    1
#define ENABLE_OMI_UNIT_TEST_4    1
#define ENABLE_OMI_UNIT_TEST_5    1
#endif

#define DISABLE_PEC_UNIT_TESTS 0 // standalone no TYPE_PEC

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
 * @return    Target*          Pointer to a target.
 */
Target* getAnyTargetByType(const Target& i_parent,
                           const ATTR_TYPE_type i_targetType,
                           const ATTR_CHIPLET_ID_type i_chipletID = ANY_CHIPLET)
{
    TargetHandleList l_targetList;
    getChildChiplets(l_targetList, &i_parent, i_targetType, false);

    Target* l_target = nullptr;

    TS_INFO("getAnyTargetByType: l_targetList.size()=%d TYPE=0x%X",
        l_targetList.size(), i_targetType);
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
        TS_INFO("getAnyTargetByType: *WARNING* Cannot find "
                "instance of target type %s "
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
    Target* pSys = UTIL::assertGetToplevelTarget();

    TargetHandleList pChildList;
    getChildAffinityTargets(pChildList, pSys, CLASS_NA, TYPE_NA, false);

    for (const auto l_child : pChildList)
    {
        // Get the original state of the child
        const HwasState l_originalState = l_child->getAttr<ATTR_HWAS_STATE>();

        const ATTR_SAVED_STATE_UINT8_type l_savedState = l_originalState.functional;

        // Store it in a scratch attribute for later
        l_child->setAttr<ATTR_SAVED_STATE_UINT8>(l_savedState);
        TS_TRACE("saveSystemState: SAVED HWAS_STATE for "
            "HUID=0x%X l_savedState=0x%X",
            get_huid(l_child), l_savedState);

        // If this is a PERV target, store ATTR_PG
        if (l_child->getAttr<ATTR_TYPE>() == TYPE_PERV)
        {
            const ATTR_PG_SAVED_type l_savedAttrPg = l_child->getAttr<ATTR_PG>();
            l_child->setAttr<ATTR_PG_SAVED>(l_savedAttrPg);
            TS_TRACE("saveSystemState: SAVED ATTR_PG for "
                "HUID=0x%X l_savedAttrPg=0x%X",
                get_huid(l_child), l_savedAttrPg);
        }
        else
        {
            TS_TRACE("saveSystemState: NOT SAVING ATTR_PG for HUID=0x%X",
                get_huid(l_child));
        }
    }
}

/* @brief Restores the state of every target's HWAS_STATE and PG attributes.
 */
void restoreSystemState()
{
    Target* pSys = UTIL::assertGetToplevelTarget();

    TargetHandleList pChildList;
    getChildAffinityTargets(pChildList, pSys, CLASS_NA, TYPE_NA, false);

    for (const auto l_child : pChildList)
    {
        // Get original HwasState from scratch attribute
        const auto l_savedState = l_child->getAttr<ATTR_SAVED_STATE_UINT8>();

        // Update current HwasState
        HwasState l_state = l_child->getAttr<ATTR_HWAS_STATE>();
        TS_TRACE("restoreSystemState: Working with HUID=0x%X "
            "functional=0x%X savedState=0x%X",
            get_huid(l_child), l_state.functional, l_savedState);

        l_state.functional = l_savedState != 0;

        TS_TRACE("restoreSystemState: SETTING HUID=0x%X "
            "functional=0x%X savedState=0x%X",
            get_huid(l_child), l_state.functional, l_savedState);
        l_child->setAttr<ATTR_HWAS_STATE>(l_state);

        // And if it's a PERV, restore ATTR_PG
        if (l_child->getAttr<ATTR_TYPE>() == TYPE_PERV)
        {
            TS_TRACE("restoreSystemState: HUID=0x%X TYPE_PERV SETTING "
                "ATTR_PG to ATTR_PG_SAVED 0x%X",
                get_huid(l_child), l_child->getAttr<ATTR_PG_SAVED>());
            l_child->setAttr<ATTR_PG>(l_child->getAttr<ATTR_PG_SAVED>());
        }
        else
        {
            TS_TRACE("restoreSystemState: NO ATTR_PG RESTORE "
                "HUID=0x%X NOT TYPE_PERV, but TYPE=0x%X",
                get_huid(l_child), l_child->getAttr<ATTR_TYPE>());
        }
    }
}

/**
@brief Class to help test that deconfig done by HB and SBE match each other.
*/
class TestHbSbePGDeconfig :
    public HWAS::HWASDiscovery, public HWAS::HWASPlatVerification
{

private:

    // Will be used to store original copy (in func saveOrigSbeRegs) and then
    // set back (in func restoreSbeRegs) the value of ATTR_MASTER_MBOX_SCRATCH
    ATTR_MASTER_MBOX_SCRATCH_typeStdArr g_originalSbeReg;

    Target* g_topSysTarget;

    /**
    @brief From HWAS::HWASDiscovery, this function is being overridden to return
    a manipulated PG vector. The PGV being returned will pretend that all the
    PECs are not functional.
    */
    void parsePgData(
            const std::array<uint8_t, VPD_CP00_PG_DATA_LENGTH>& pgData,
            partialGoodVector& o_pgDataAllGood) override
    {

        // Copy of the P10 all good PG vector.
        memcpy(&o_pgDataAllGood, &pgDataAllGood, sizeof(pgDataAllGood));

        // Set all the PECs bad
        for (const int l_pecIdx : VPD_CP00_PG_PCI_INDEX)
        {
            o_pgDataAllGood[l_pecIdx] |= (~VPD_CP00_PG_PCI_ALL_GOOD);
        }

    }

    /*
    @brief From HWAS::HWASPlatVerification, this function overrides the logging
    of errors to instead check that what has been deconfig with test data was
    caught by verifyDeconfiguration()
    */
    errlHndl_t verificationMatchHandler(Target * i_target,
        const bool i_hbFunctional, const bool i_sbeFunctional) override
    {

        // PEC should be deconfig in both HB and SBE context (this was done in
        // parsePgData() and setFakeScratchRegAttr() respectively)
        if (i_target->getAttr<ATTR_TYPE>() == TYPE_PEC)
        {
            if (i_hbFunctional || i_sbeFunctional)
            {
                TS_FAIL("testHostbootSbeDeconfig: verifyDeconfiguration() For "
                    "PEC with HUID %.8X, expected to be marked not functional "
                    "by SBE and HB. Instead got SBE marked functional: %s  HB "
                    "marked functional: %s)",
                    i_target->getAttr<ATTR_HUID>(),
                    ((i_sbeFunctional) ? "True" : "False"),
                    ((i_hbFunctional) ? "True" : "False") );
            }
        }

        // All MCs should be deconfig by HB and marked as functional by SBE
        if (i_target->getAttr<ATTR_TYPE>() == TYPE_MC)
        {
            if (i_hbFunctional || !i_sbeFunctional)
            {
                TS_FAIL("testHostbootSbeDeconfig: verifyDeconfiguration() For "
                    "MC with HUID %.8X, expected to be marked functional by "
                    "SBE and not functional by HB. Instead got SBE marked "
                    "functional: %s  HB marked functional: %s)",
                    i_target->getAttr<ATTR_HUID>(),
                    ((i_sbeFunctional) ? "True" : "False"),
                    ((i_hbFunctional) ? "True" : "False") );
            }
        }

        return nullptr; // return value ignored
    }

public:

    // Constructor
    TestHbSbePGDeconfig()
    {
        g_topSysTarget = nullptr;
        targetService().getTopLevelTarget(g_topSysTarget);
        HWAS_ASSERT(g_topSysTarget, "testHostbootSbeDeconfig: Could not get top"
            " system target");
    }

    /**
    @brief Save original SBE scratch reg attr values
    */
    void saveOrigSbeRegs()
    {
        g_originalSbeReg = g_topSysTarget->getAttrAsStdArr
            <ATTR_MASTER_MBOX_SCRATCH>();
    }

    /**
    @brief Restore SBE scratch reg to original state (kept in g_originalSbeReg)
    */
    void restoreSbeRegs()
    {
        g_topSysTarget->setAttrFromStdArr<ATTR_MASTER_MBOX_SCRATCH>
            (g_originalSbeReg);
    }

   /**
    @brief Faking scratch register MboxScratch2_t (as if read from SBE) to:
    - deconfig all PECs
    - mark all MCs as functional
    */
    void setFakeScratchRegAttr()
    {

        // Setting PECs to non-functional in MboxScratch2_t
        // Note that 1 in a bit position means the part is NOT functional,
        // a 0 means the part is functional.
        auto l_sbeFakeRegs = g_originalSbeReg;
        TargetHandleList l_pecList;
        getChildAffinityTargetsByState(l_pecList, g_topSysTarget, CLASS_NA,
            TYPE_PEC, UTIL_FILTER_ALL);
        const uint64_t l_pecRegStartPosition = 0;
        for (const auto l_pec: l_pecList)
        {
            const uint64_t l_shiftToPec = l_pec->getAttr<ATTR_CHIP_UNIT>() +
                l_pecRegStartPosition;
            l_sbeFakeRegs[INITSERVICE::SPLESS::MboxScratch2_t::REG_IDX] |=
                (0x80000000ull >> l_shiftToPec);
        }

        // Setting MCs to functional in MboxScratch2_t
        TargetHandleList l_mcList;
        getChildAffinityTargetsByState(l_mcList, g_topSysTarget, CLASS_NA,
            TYPE_MC, UTIL_FILTER_ALL);
        const uint64_t l_mcRegStartPosition = 4;
        for (const auto l_mc: l_mcList)
        {
            const uint64_t l_shiftToMc = l_mc->getAttr<ATTR_CHIP_UNIT>() +
                l_mcRegStartPosition;
            l_sbeFakeRegs[INITSERVICE::SPLESS::MboxScratch2_t::REG_IDX] &=
                ~(0x80000000ull >> l_shiftToMc);
        }

        // Storing fake data in SBE scratch reg attr
        g_topSysTarget->setAttrFromStdArr<ATTR_MASTER_MBOX_SCRATCH>
            (l_sbeFakeRegs);
    }

    /**
    @brief Garding all MCs for test
    */
    void createFakeGardRecords()
    {
        // Get all MCs
        TargetHandleList l_mcList;
        getChildAffinityTargetsByState (l_mcList, g_topSysTarget, CLASS_UNIT,
            TYPE_MC, UTIL_FILTER_ALL);

        // Fake manual gard
        DeconfigGard::GardRecord l_fakeGardRecord =
            {0, EntityPath(EntityPath::PATH_NA), 0, GARD_User_Manual, 0, 0};
        strcpy(reinterpret_cast<char *>(l_fakeGardRecord.uniqueId.ibm11S.serialNum), "FAKE_SN12345");
        strcpy(reinterpret_cast<char *>(l_fakeGardRecord.uniqueId.ibm11S.partNum), "FAKE_PN");

        // Apply fake gard to all MCs
        TS_INFO("createFakeGardRecords l_mcList.size()=%d", l_mcList.size());
        for (auto const& l_mc: l_mcList)
        {
            errlHndl_t l_errHandler = nullptr;
            TS_INFO("createFakeGardRecords working HUID=0x%X", get_huid(l_mc));
            l_errHandler = HWAS::theDeconfigGard().applyGardRecord(l_mc,
                l_fakeGardRecord);

            if (l_errHandler)
            {
                TS_FAIL("testHostbootSbeDeconfig: createFakeGardRecords() was "
                "not able to apply test gard records");
            }
        }

    }

};

class HwasGardTest: public CxxTest::TestSuite
{
public:

    /**
    @brief This test will fake de-configuration of targets from the HB and SBE
    side independently.
    SBE deconfig will be faked by editing ATTR_MASTER_MBOX_SCRATCH:
        - All PECs marked as non-functional
        - All MCs marked as functional
    HB deconfig will be faked by:
        - Changing VPD PG read by HB to read all PECs as non-functional
        - Garding all MCs
    Following the succesful creation of faked data, verifyDeconfiguration()
    will be called to verify that in fact the de-configurations were caught and
    that verifyDeconfiguration() takes appropriate action based on that.
    The TestHbSbePGDeconfig class was created to assist in this testcase.
    */
    void testHostbootSbeDeconfig()
    {
        // Target attributes will be edited, save state to restore at the end
        // of testcase
        TS_INFO("testHostbootSbeDeconfig Started");
        saveSystemState();

        TestHbSbePGDeconfig testHbSbeDeconfig;

        testHbSbeDeconfig.saveOrigSbeRegs();

        // Set fake SBE reg data
        testHbSbeDeconfig.setFakeScratchRegAttr();

        // Create fake gard records
        testHbSbeDeconfig.createFakeGardRecords();

        do
        {

        errlHndl_t l_pErrHandler = testHbSbeDeconfig.discoverTargets();

        if (nullptr != l_pErrHandler) //discoverTargets worked
        {
            TS_FAIL("testHostbootSbeDeconfig: Error while calling"
                " discoverTargets()");
            errlCommit(l_pErrHandler, CXXTEST_COMP_ID);
            break;
        }

        // Create fake gard records
        testHbSbeDeconfig.createFakeGardRecords();

        // Verify
        Target* l_pMasterProcChip = nullptr;
        targetService().masterProcChipTargetHandle(l_pMasterProcChip);
        const auto scratchRegs = UTIL::assertGetToplevelTarget()->getAttrAsStdArr<ATTR_MASTER_MBOX_SCRATCH>();
        testHbSbeDeconfig.verifyDeconfiguration(l_pMasterProcChip, scratchRegs);

        } while (0);

        // Restore SBE reg data
        testHbSbeDeconfig.restoreSbeRegs();

        // Restore saved Target state
        restoreSystemState();
        TS_INFO("testHostbootSbeDeconfig Ended");

    }

    /**
     *  @brief Test which verifies all targets have a valid deconfig rule
     */
    void testParentDeconfigRules()
    {
        TS_INFO("testParentDeconfigRules: Started");

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
        TS_INFO("testParentDeconfigRules: Ended");
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
#if !DISABLE_UNIT_TESTS
        // find an fc unit that we can play with
        TS_INFO("testSaveRestoreState: Started");
        Target* pSys = UTIL::assertGetToplevelTarget();

        PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
        PredicateHwas predFunctional;
        predFunctional.poweredOn(true).present(true).functional(true);
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predFc).push(&predFunctional).And();
        TargetHandleList pFcList;
        targetService().getAssociated( pFcList, pSys,
            TargetService::CHILD, TargetService::ALL, &checkExpr );

        do
        {
            if (pFcList.empty())
            {
                TS_WARN("testSaveRestoreState: empty pFcList CLASS_UNIT, TYPE_FC");
                break;
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
        }
        while (0);
        TS_INFO("testSaveRestoreState: Ended");
#endif
    }

    /**
     *  @brief Test creating and getting a Deconfigure Record for a
     *      FC Target
     */
    void testDeconfigure2()
    {
        TS_INFO("testDeconfigure2: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::DeconfigureRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeconfigure2: pFcList.size()=%d", pFcList.size());
            if (pFcList.empty())
            {
                TS_FAIL("testDeconfigure2: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
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

            TS_INFO("testDeconfigure2: Success. %d record",
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

            TS_INFO("testDeconfigure2: Success");
        }
        while (0);
        TS_INFO("testDeconfigure2: Ended");
    }


    /**
     *  @brief Test Deconfiguring a Target - FC directly
     */

    void testDeconfigure3()
    {
        TS_INFO("testDeconfigure3: Started");
#if DISABLE_UNIT_TESTS
        TS_INFO( "testDeconfigure3 - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = nullptr;
        saveSystemState();
        do
        {
            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeconfigure3: pFcList.size()=%d", pFcList.size());
            if (pFcList.empty())
            {
                TS_FAIL("testDeconfigure3: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();
            TS_INFO("testDeconfigure3: Working with "
                "HUID=0x%X", get_huid(l_pTarget));

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

            TS_INFO("testDeconfigure3: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testDeconfigure3: Ended");
#endif
    }

    /**
     *  @brief Test Deconfiguring a Target multiple times directly
     */
    void testDeconfigure4()
    {
        TS_INFO("testDeconfigure4: Started");
#if DISABLE_UNIT_TESTS
        TS_INFO("testDeconfigure4 - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = nullptr;

        saveSystemState();
        do
        {
            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeconfigure4: pFcList.size()=%d", pFcList.size());
            if (pFcList.empty())
            {
                TS_FAIL("testDeconfigure4: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();
            TS_INFO("testDeconfigured4: Working with "
                "HUID=0x%X", get_huid(l_pTarget));

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

            TS_INFO("testDeconfigure4: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testDeconfigure4: Ended");
#endif
    }

    /**
     *  @brief Test Deconfiguring a PEC Target directly
     */

    void testDeconfigurePECTarget()
    {
        TS_INFO("testDeconfigurePECTarget: Started");

#if DISABLE_PEC_UNIT_TESTS
        TS_INFO("testDeconfigurePECTarget - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = nullptr;

        do
        {
            //Find a functional PEC Target for the deconfigure test
            Target* pSys = UTIL::assertGetToplevelTarget();
            PredicateCTM predPEC(CLASS_UNIT, TYPE_PEC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predPEC).push(&predFunctional).And();
            TargetHandleList l_pecList;
            targetService().getAssociated( l_pecList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            //Verify PEC list isn't empty
            TS_INFO("testDeconfigurePECTarget: l_pecList.size()=%d",
                l_pecList.size());
            if (l_pecList.empty())
            {
                TS_INFO("testDeconfigurePECTarget: SKIPPING empty l_pecList CLASS_UNIT, TYPE_PEC");
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
                l_pErr = theDeconfigGard().deconfigureTarget(*l_pec,
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
                    TS_INFO("testDeconfigurePECTarget: PHB: %.8X",
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

        TS_INFO("testDeconfigurePECTarget: Ended");

#endif
    }

   /**
     *  @brief Verify PEC deconfigured when all PHB's deconfigured
     */
    void testDeconfigurePECwithAllBadPHBs()
    {
        TS_INFO("testDeconfigurePECwithAllBadPHBs: Started");
#if DISABLE_PEC_UNIT_TESTS
        TS_INFO("testDeconfigurePECwithAllBadPHBs - SKIPPING -- other tests could be adversly affected");
#else
        errlHndl_t l_pErr = nullptr;

        do
        {
            //Find a functional PEC Target for the deconfigure test
            Target* pSys = UTIL::assertGetToplevelTarget();
            PredicateCTM predPEC(CLASS_UNIT, TYPE_PEC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predPEC).push(&predFunctional).And();
            TargetHandleList l_pecList;
            targetService().getAssociated( l_pecList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            //Verify PEC list isn't empty
            TS_INFO("testDeconfigurePECwithAllBadPHBs: l_pecList.size()=%d", l_pecList.size());
            if (l_pecList.empty())
            {
                TS_INFO("testDeconfigurePECwithAllBadPHBs: SKIPPING empty l_pecList CLASS_UNIT, TYPE_PEC");
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
        TS_INFO("testDeconfigurePECwithAllBadPHBs: Ended");

#endif
    }

    /**
     *  @brief Test Deconfiguring a Target - EQ directly
     */
    void testDeconfigureEQTarget()
    {
        TS_INFO("testDeconfigureEQTarget: Started");
#if DISABLE_UNIT_TESTS
        TS_INFO("testDeconfigureEQTarget - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = nullptr;
        saveSystemState();

        do
        {
            // find EQ unit that we can play with
            TS_INFO("testDeConfigEQTarget: is_fused_mode=0x%X", is_fused_mode());
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predEq(CLASS_UNIT, TYPE_EQ);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEq).push(&predFunctional).And();
            TargetHandleList pEqList;
            targetService().getAssociated( pEqList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeconfigureEQTarget: pEqList.size()=%d", pEqList.size());
            if (pEqList.empty())
            {
                TS_FAIL("testDeconfigureEQTarget: SKIPPING empty pEqList CLASS_UNIT, TYPE_EQ");
                break;
            }

            // Health Check pre-testing
            TargetHandle_t l_pTargetEQ1 = *pEqList.begin(); // prime first EQ
            TargetHandle_t l_pTargetEQ2;
            HwasState l_state_eq;
            for (TargetHandleList::iterator pEq_it = pEqList.begin();
                   (pEq_it != pEqList.end()); ++pEq_it)
            {
                l_pTargetEQ2 = *pEq_it; // last iteration will save last one of two as the END EQ
                // Get the original HWAS_STATE of EQ
                l_state_eq = l_pTargetEQ2->getAttr<ATTR_HWAS_STATE>();
                //  This information is saved to help validate and cleanup later
                TS_INFO("testDeconfigureEQTarget: INITIAL STATE EQ HUID=0x%X state=0x%X present=0x%X",
                    get_huid(l_pTargetEQ2), l_state_eq.functional, l_state_eq.present);
                if (!l_state_eq.functional)
                {
                    TS_FAIL("testDeconfigureEQTarget: EQ is not functional before deconfig EQ HUID=0x%X state=0x%X, unexpected",
                        get_huid(l_pTargetEQ2), l_state_eq);
                    break;
                }
            }

            TargetHandleList pFcList1, pCoreList1[2];
            TargetHandleList pFcList2, pCoreList2[2];
            uint32_t cIndex = 0;
            // get the list of FCs
            getChildAffinityTargets(pFcList1, l_pTargetEQ1, CLASS_NA ,TYPE_FC);
            getChildAffinityTargets(pFcList2, l_pTargetEQ2, CLASS_NA ,TYPE_FC);

            TS_INFO("testDeconfigureEQTarget: getChildAffinityTargets pFcList1.size()=%d",
                pFcList1.size());
            TS_INFO("testDeconfigureEQTarget: getChildAffinityTargets pFcList2.size()=%d",
                pFcList2.size());

            if (pFcList1.empty())
            {
                TS_FAIL("testDeconfigureEQTarget: empty pFcList1");
                break;
            }

            // Pick up FC and cores and save them

            TargetHandle_t pFc1, pCore1;
            HwasState l_state;
            bool exitLoop = false;
            for (TargetHandleList::iterator pFc_it1 = pFcList1.begin();
                   (pFc_it1 != pFcList1.end()) && !exitLoop; ++pFc_it1)
            {
                pFc1 = *pFc_it1;
                // Get the original HWAS_STATE of FC
                l_state = pFc1->getAttr<ATTR_HWAS_STATE>();
                TS_INFO("testDeconfigureEQTarget: Working with FC before deconfig FC HUID=0x%X state=0x%X",
                         get_huid(pFc1), l_state.functional);
                if (!l_state.functional)
                {
                    TS_FAIL("testDeconfigureEQTarget: FC is not functional before deconfig FC HUID=0x%X state=0x%X",
                        get_huid(pFc1), l_state.functional);
                    break;
                }
                getChildAffinityTargets(pCoreList1[cIndex],
                                    pFc1, CLASS_NA ,TYPE_NA);
                TS_INFO("testDeconfigureEQTarget: pCoreList1[%d] HUID=0x%X pCoreList1[%d].size()=%d",
                    cIndex, get_huid(pFc1), cIndex, pCoreList1[cIndex].size());
                if(pCoreList1[cIndex].empty())
                {
                    TS_FAIL("testDeconfigureEQTarget: empty pCoreList1[%d]", cIndex);
                    exitLoop = true;
                    break;
                }

                for (TargetHandleList::iterator pChild_it1 =
                       pCoreList1[cIndex].begin();
                       pChild_it1 != pCoreList1[cIndex].end(); ++pChild_it1)
                {
                    pCore1 = *pChild_it1;
                    // Get the original HWAS_STATE of the core
                    l_state = pCore1->getAttr<ATTR_HWAS_STATE>();
                    TS_INFO("testDeconfigureEQTarget before deconfig: Working with Core HUID=0x%X state=0x%X",
                         get_huid(pCore1), l_state.functional);
                    if (!l_state.functional)
                    {
                        TS_FAIL("testDeconfigureEQTarget: Core is not functional before deconfig Core HUID=0x%X state=0x%X",
                            get_huid(pCore1), l_state.functional);
                        exitLoop = true;
                        break;
                    }
                } // for CHILD
                cIndex++;
            } // for pFc_it1

            // FC2 needed in case debug needed
            TargetHandle_t pFc2, pCore2;
            for (TargetHandleList::iterator pFc_it2 = pFcList2.begin();
                   (pFc_it2 != pFcList2.end()) && !exitLoop; ++pFc_it2)
            {
                pFc2 = *pFc_it2;
                // Get the original HWAS_STATE of FC
                l_state = pFc2->getAttr<ATTR_HWAS_STATE>();
                TS_INFO("testDeconfigureEQTarget: Working with FC2 before deconfig FC2 HUID=0x%X  state=0x%X",
                    get_huid(pFc2), l_state.functional);
                if (!l_state.functional)
                {
                    TS_FAIL("testDeconfigureEQTarget: FC2 is not functional before deconfig FC2 HUID=0x%X state=0x%X",
                         get_huid(pFc2), l_state.functional);
                    break;
                }
                getChildAffinityTargets(pCoreList2[cIndex],
                                    pFc2, CLASS_NA ,TYPE_NA);
                TS_INFO("testDeconfigureEQTarget: pCoreList2[%d] HUID=0x%X pCoreList2[%d].size()=%d",
                    cIndex, get_huid(pFc2), cIndex, pCoreList2[cIndex].size());
                if(pCoreList2[cIndex].empty())
                {
                    TS_FAIL("testDeconfigureEQTarget: empty pCoreList2[%d]", cIndex);
                    exitLoop = true;
                    break;
                }

                for (TargetHandleList::iterator pChild_it2 =
                       pCoreList2[cIndex].begin();
                       pChild_it2 != pCoreList2[cIndex].end(); ++pChild_it2)
                {
                    pCore2 = *pChild_it2;
                    // Get the original HWAS_STATE of the core
                    l_state = pCore2->getAttr<ATTR_HWAS_STATE>();
                    TS_INFO("testDeconfigureEQTarget before deconfig: Working with Core HUID=0x%X state=0x%X",
                         get_huid(pCore2), l_state.functional);
                    if (!l_state.functional)
                    {
                        TS_FAIL("testDeconfigureEQTarget: Core is not functional before deconfig Core HUID=0x%X state=0x%X",
                            get_huid(pCore2), l_state.functional);
                        exitLoop = true;
                        break;
                    }
                } // for CHILD
                cIndex++;
            } // for pFc_it2

            if (exitLoop)
            {
                break;
            }

            // Deconfigure the target EQ
            TS_INFO("testDeconfigureEQTarget: calling deconfigureTarget EQ HUID=0x%X",
                get_huid(l_pTargetEQ1));
            l_pErr = theDeconfigGard().
                    deconfigureTarget(*l_pTargetEQ1,
                        DeconfigGard::DECONFIGURED_BY_EQ_DECONFIG);
            if (l_pErr)
            {
                TS_FAIL("testDeconfigureEQTarget: We were unable to deconfigureTarget, EQ HUID=0x%X should be gardable",
                    get_huid(l_pTargetEQ1));
                break;
            }
            else
            {
                TS_INFO("testDeconfigureEQTarget: We were able to deconfigureTarget, EQ HUID=0x%X is gardable",
                    get_huid(l_pTargetEQ1));
                errlCommit(l_pErr,CXXTEST_COMP_ID);
            }


            l_state = l_pTargetEQ1->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeconfigureEQTarget: Working with EQ after deconfig EQ HUID=0x%X state=0x%X present=0x%X",
                get_huid(l_pTargetEQ1), l_state.functional, l_state.present);
            if (!l_state.functional)
            {
                // Reset the HWAS_STATE of EQ back to functional
                TS_INFO("testDeconfigureEQTarget: GOING TO RESET HWAS_STATE for EQ to functional after deconfig EQ HUID=0x%X state=0x%X, expected",
                    get_huid(l_pTargetEQ1), l_state.functional);
                l_state.functional = 1;
                l_pTargetEQ1->setAttr<ATTR_HWAS_STATE>(l_state);
                l_state = l_pTargetEQ1->getAttr<ATTR_HWAS_STATE>();
                TS_INFO("testDeconfigureEQTarget: RESET CONFIRMATION HWAS_STATE for EQ to functional after deconfig EQ HUID=0x%X state=0x%X present=0x%X",
                    get_huid(l_pTargetEQ1), l_state.functional, l_state.present);
            }
            else
            {
                TS_FAIL("testDeconfigureEQTarget: EQ is functional after deconfig EQ HUID=0x%X state=0x%X, unexpected",
                    get_huid(l_pTargetEQ1), l_state.functional);
                break;
            }

            cIndex = 0;
            bool found_proc_disabled = false; // used to flag that we found the proc disabled at least first time
            for (TargetHandleList::iterator pFc_it1 = pFcList1.begin();
                   (pFc_it1 != pFcList1.end()); ++pFc_it1)
            {
                pFc1 = *pFc_it1;
                // Get the HWAS_STATE of FC
                l_state = pFc1->getAttr<ATTR_HWAS_STATE>();
                TS_INFO("testDeconfigureEQTarget: Working with FC HUID=0x%X state=0x%X",
                         get_huid(pFc1), l_state.functional);
                if (!l_state.functional)
                {
                    TS_INFO("testDeconfigureEQTarget: FC is not functional after EQ deconfig FC HUID=0x%X state=0x%X, expected",
                        get_huid(pFc1), l_state.functional);
                    l_state.functional = 1;
                    pFc1->setAttr<ATTR_HWAS_STATE>(l_state);
                    l_state = pFc1->getAttr<ATTR_HWAS_STATE>();
                    TS_INFO("testDeconfigureEQTarget: RESET CONFIRMATION HWAS_STATE to functional after deconfig FC HUID=0x%X state=0x%X",
                        get_huid(pFc1), l_state.functional);
                }
                else
                {
                    TS_FAIL("testDeconfigureEQTarget: FC is functional after EQ deconfig HUID=0x%X state=0x%X, unexpected",
                        get_huid(pFc1), l_state.functional);
                    break;
                }

                // Next block is to restore and confirm all is functional

                for (TargetHandleList::iterator pChild_it1 =
                       pCoreList1[cIndex].begin();
                       pChild_it1 != pCoreList1[cIndex].end(); ++pChild_it1)
                {
                    pCore1 = *pChild_it1;
                    // Get the HWAS_STATE of the core
                    l_state = pCore1->getAttr<ATTR_HWAS_STATE>();
                    TS_INFO("testDeconfigureEQTarget: Working with Core HUID=0x%X state=0x%X",
                         get_huid(pCore1), l_state.functional);
                    if (!l_state.functional)
                    {
                        TS_INFO("testDeconfigureEQTarget: Core is not functional after EQ deconfig Core HUID=0x%X state=0x%X, maybe expected",
                            get_huid(pCore1), l_state.functional);
                        l_state.functional = 1;
                        pCore1->setAttr<ATTR_HWAS_STATE>(l_state);
                        l_state = pCore1->getAttr<ATTR_HWAS_STATE>();
                        TS_INFO("testDeconfigureEQTarget: RESET CONFIRMATION HWAS_STATE to functional after deconfig Core HUID=0x%X state=0x%X",
                             get_huid(pCore1), l_state.functional);
                    }
                } // for CHILD
                l_state = pFc1->getAttr<ATTR_HWAS_STATE>();
                TS_INFO("testDeconfigureEQTarget: FC SHOULD BE FUNCTIONAL Working with FC HUID=0x%X state=0x%X",
                    get_huid(pFc1), l_state.functional);
                if (!l_state.functional)
                {
                    TS_FAIL("testDeconfigureEQTarget: NOT FUNCTIONAL Working with FC HUID=0x%X state=0x%X, unexpected",
                        get_huid(pFc1), l_state.functional);
                        break;
                }

                // Check out the PARENT PROC and cleanup
                Target* const l_proc = const_cast<Target*>(getParentChip(l_pTargetEQ1));
                HwasState l_proc_state;
                l_proc_state= l_proc->getAttr<ATTR_HWAS_STATE>();
                TS_INFO("testDeconfigureEQTarget: Parent PROC SHOULD NOT BE FUNCTIONAL on the first pass Parent PROC HUID=0x%X state=0x%X",
                         get_huid(l_proc), l_proc_state.functional);
                if (!l_proc_state.functional)
                {
                    found_proc_disabled = true;
                    l_proc_state.functional = 1;
                    l_proc->setAttr<ATTR_HWAS_STATE>(l_proc_state);
                    l_proc_state= l_proc->getAttr<ATTR_HWAS_STATE>();
                    TS_INFO("testDeconfigureEQTarget: RESET CONFIRMATION HWAS_STATE to functional after deconfig Parent PROC HUID=0x%X state=0x%X",
                             get_huid(l_proc), l_proc_state.functional);
                }
                if (!found_proc_disabled)
                {
                    TS_FAIL("testDeconfigureEQTarget: Parent PROC HWAS_STATE found functional after deconfig Parent PROC HUID=0x%X state=0x%X",
                        get_huid(l_proc), l_proc_state.functional);
                }
                else
                {
                    TS_INFO("testDeconfigureEQTarget: Parent PROC HWAS_STATE RESET after deconfig Parent PROC HUID=0x%X state=0x%X",
                        get_huid(l_proc), l_proc_state.functional);
                }
                cIndex++;
            }

            // Confirm EQ is functional after cleanup, health check only and logging
            l_state = l_pTargetEQ1->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeconfigureEQTarget: PRE CLEANUP Working with EQ after deconfig CLEANUP SHOULD BE FUNCTIONAL HUID=0x%X state=0x%X present=0x%X",
                get_huid(l_pTargetEQ1), l_state.functional, l_state.present);
            l_state = l_pTargetEQ2->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeconfigureEQTarget: PRE CLEANUP Working with EQ after deconfig CLEANUP SHOULD BE FUNCTIONAL HUID=0x%X state=0x%X present=0x%X",
                get_huid(l_pTargetEQ2), l_state.functional, l_state.present);
            restoreSystemState();
            l_state = l_pTargetEQ1->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeconfigureEQTarget: POST CLEANUP Working with EQ after deconfig CLEANUP SHOULD BE FUNCTIONAL HUID=0x%X state=0x%X present=0x%X",
                get_huid(l_pTargetEQ1), l_state.functional, l_state.present);
            l_state = l_pTargetEQ2->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeconfigureEQTarget: POST CLEANUP Working with EQ after deconfig CLEANUP SHOULD BE FUNCTIONAL HUID=0x%X state=0x%X present=0x%X",
                get_huid(l_pTargetEQ2), l_state.functional, l_state.present);

            TS_INFO("testDeconfigureEQTarget: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        TS_INFO("testDeconfigureEQTarget: Ended");
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc1()
    {
        TS_INFO("testDeconfigureAssoc1: Started");
#if DISABLE_MBA_UNIT_TESTS
        TS_INFO("testDeconfigureAssoc1 - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;

        do
        {
            // find an MBA
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predMba(CLASS_UNIT, TYPE_MBA);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predMba).push(&predFunctional).And();
            TargetHandleList pMba;
            targetService().getAssociated( pMba, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeconfigureAssoc1: pMba.size()=%d", pMba.size());
            if (pMba.empty())
            {
                TS_INFO("testDeconfigureAssoc1: SKIPPING empty pMba CLASS_UNIT, TYPE_MBA");
                break;
            }
            //TargetHandle_t l_pTarget = *pMba.begin();
            TargetHandle_t l_pTarget = pMba[pMba.size()-1];

            // Get the original HWAS_STATE of the target
            HwasState l_origState = l_pTarget->getAttr<ATTR_HWAS_STATE>();

            // Deconfigure the target.
            l_pErr = theDeconfigGard().deconfigureTarget(*l_pTarget, 0xA101);
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

            TS_INFO("testDeconfigureAssoc1: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testDeconfigureAssoc1: Ended");
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc2()
    {
        TS_INFO("testDeconfigureAssoc2: Started");
#if DISABLE_MEM_UNIT_TESTS
        TS_INFO("testDeconfigureAssoc2 - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;

        do
        {
            // find an MEMBUF
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predMembuf(CLASS_CHIP, TYPE_MEMBUF);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predMembuf).push(&predFunctional).And();
            TargetHandleList pMembuf;
            targetService().getAssociated( pMembuf, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeconfigureAssoc2: pMembuf.size()=%d", pMembuf.size());
            if (pMembuf.empty())
            {
                TS_INFO("testDeconfigureAssoc2: SKIPPING empty pMembuf CLASS_CHIP, TYPE_MEMBUF");
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

            TS_INFO("testDeconfigureAssoc2: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testDeconfigureAssoc2: Ended");
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc3()
    {
        TS_INFO("testDeconfigureAssoc3: Started");
#if DISABLE_UNIT_TESTS
        TS_INFO("testDeconfigureAssoc3 - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;

        do
        {
            // find an DIMM
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predDimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predDimm).push(&predFunctional).And();
            TargetHandleList pDimm;
            targetService().getAssociated( pDimm, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeconfigureAssoc3: pDimm.size()=%d", pDimm.size());
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
            targetService().getAssociated( pDimm, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );
            TS_INFO("testDeconfigureAssoc3: pDimm.size()=%d", pDimm.size());
            if (pDimm.empty())
            {
                TS_FAIL("testDeconfigureAssoc3: We should have some pDimm restored, but we are empty pDimm");
                break;
            }

            TS_INFO("testDeconfigureAssoc3: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testDeconfigureAssoc3: Ended");
#endif
    }
    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc4()
    {
        TS_INFO("testDeconfigureAssoc4: Started");
#if DISABLE_MCS_UNIT_TESTS
        TS_INFO("testDeconfigureAssoc4 - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;

        do
        {
            // find an MCS
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predMcs(CLASS_UNIT, TYPE_MCS);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predMcs).push(&predFunctional).And();
            TargetHandleList pMcs;
            targetService().getAssociated( pMcs, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeconfigureAssoc4: pMcs.size()=%d", pMcs.size());
            if (pMcs.empty())
            {
                TS_INFO("testDeconfigureAssoc4: SKIPPING empty pMcs CLASS_UNIT, TYPE_MCS");
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

            TS_INFO("testDeconfigureAssoc4: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testDeconfigureAssoc4: Ended");
#endif
    }

    /**
     *  @brief Test Deconfiguring by Association
     */
    void testDeconfigureAssoc5()
    {
        TS_INFO("testDeconfigureAssoc5: Started");
#if DISABLE_MBA_UNIT_TESTS
        TS_INFO("testDeconfigureAssoc5 - SKIPPING -- other tests could be adversely affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;

        do
        {
            // find a MBA, deconfigure the attached DIMMs
            Target* pSys = UTIL::assertGetToplevelTarget();

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
                TS_INFO("testDeconfigureAssoc5: SKIPPING empty pMbaList CLASS_UNIT, TYPE_MBA");
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

            TS_INFO("testDeconfigureAssoc5: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr, CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testDeconfigureAssoc5: Ended");
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
        TS_INFO("testDeconfigureAssoc6: Started");
#if DISABLE_MEM_UNIT_TESTS
        TS_INFO("testDeconfigureAssoc6 - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;

        do
        {
            // find an MEMBUF
            Target* pSys = UTIL::assertGetToplevelTarget();

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
                TS_INFO("testDeconfigureAssoc6: SKIPPING empty pMembuf CLASS_CHIP, TYPE_MEMBUF");
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

            TS_INFO("testDeconfigureAssoc6: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testDeconfigureAssoc6: Ended");
#endif
    }

    /**
     *  @brief Test FC with no good cores should be deconfigured
     */
    void testDeConfigFC2BadCores()
    {
        TS_INFO("testDeConfigFC2BadCores: Started");
#if DISABLE_FC_UNIT_TESTS
        TS_INFO("testDeConfigFC2BadCores - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;
        do
        {

            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);

            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();

            TargetHandleList pFcList, pCoreList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeConfigFC2BadCores: pFcList.size()=%d", pFcList.size());
            if (pFcList.empty())
            {
                TS_FAIL("testDeConfigFC2BadCores: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }

            // Pick up first FC
            TargetHandle_t pFc = *pFcList.begin();
            HwasState l_State, fc_State, ofc_State;
            fc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC2BadCores Working on first FC: %.8X state=0x%X",
                       get_huid(pFc), fc_State.functional);
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
                // Get the original HWAS_STATE of the target
                l_State = pCore->getAttr<ATTR_HWAS_STATE>();
                TS_INFO("testDeConfigFC2BadCores Core: %.8X orig state=0x%X",
                         get_huid(pCore), l_State.functional);
                l_State.functional  =   0 ;
                pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            } // for CHILD

            // Get the HWAS_STATE of FC
            ofc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeconfigFC2BadCores: FC: %.8X state=0x%X",
                get_huid(pFc), ofc_State.functional);
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
            TS_INFO("testDeconfigFC2BadCores: FC: %.8X new state=0x%X",
                get_huid(pFc), fc_State.functional);
            if (fc_State.functional)
            {
                TS_FAIL("testDeConfigFC2BadCores: Fc functional when cores non-functional");
                break;
            }

            // Reset the HWAS_STATE of FC
            pFc->setAttr<ATTR_HWAS_STATE>(ofc_State);
            TS_INFO("testDeconfigFC2BadCores: RESETTING FC: %.8X setAttr to functional state=0x%X",
                get_huid(pFc), ofc_State.functional);

            // reset all core states
            for (TargetHandleList::iterator pChild_it = pCoreList.begin();
                   pChild_it != pCoreList.end(); ++pChild_it)
            {
                TargetHandle_t pCore = *pChild_it;
                // Get the original HWAS_STATE of the target
                l_State = pCore->getAttr<ATTR_HWAS_STATE>();
                TS_INFO("testDeConfigFC2BadCores Core: %.8X resetting from bad state=0x%X",
                         get_huid(pCore), l_State.functional);
                l_State.functional  =   1 ;
                pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            } // for CHILD
            fc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeconfigFC2BadCores: RESTORED FC: %.8X restored should be functional state=0x%X",
                get_huid(pFc), fc_State.functional);
            if (!fc_State.functional)
            {
                TS_FAIL("testDeConfigFC2BadCores: CLEANUP FAILED to restore %.8X state=0x%X",
                    get_huid(pFc), fc_State);
                break;
            }

            TS_INFO("testDeConfigFC2BadCores: Success");

        }
        while (0);
        restoreSystemState();
        TS_INFO("testDeConfigFC2BadCores: Ended");

#endif
    }

    /**
     *  @brief Test FC with one good and one bad core should not be deconfigured
     */

    void testDeConfigFC1BadCore()
    {
        TS_INFO("testDeConfigFC1BadCore: Started");
#if DISABLE_FC_UNIT_TESTS
        TS_INFO("testDeConfigFC1BadCore - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;
        do
        {

            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);

            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();

            TargetHandleList pFcList, pCoreList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeConfigFC1BadCore: pFcList.size()=%d", pFcList.size());
            if (pFcList.empty())
            {
                TS_FAIL("testDeConfigFC1BadCore: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }

            // Pick up first FC
            TargetHandle_t pFc = *pFcList.begin();
            TS_INFO("testDeConfigFC1BadCore first FC pFc: %.8X",
                       get_huid(pFc));
            HwasState l_State, fc_State, ofc_State;
            TargetHandle_t pCore;
            fc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeconfigFC1BadCore: START with FC %.8X state=0x%X",
                get_huid(pFc), fc_State.functional);
            if (!fc_State.functional)
            {
                TS_FAIL("testDeConfigFC1BadCore: UNCLEAN start FC %.8X state=0x%X",
                    get_huid(pFc), fc_State.functional);
                break;
            }

            // find all CHILD_BY_AFFINITY matches for this FC i.e. cores
            // set state non-functional
            getChildAffinityTargets(pCoreList, pFc, CLASS_NA, TYPE_NA);
            TS_INFO("testDeconfigFC1BadCore pCoreList.size=%d", pCoreList.size());
            if(pCoreList.empty())
            {
                TS_FAIL("testDeconfigFC1BadCores: empty pCoreList");
                break;
            }

            // Set first core state non-functional
            TargetHandleList::iterator pChild_it = pCoreList.begin();
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore Core: %.8X 1st core orig state=0x%X",
                     get_huid(pCore), l_State.functional);
            l_State.functional  =   0 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            // Set second core state functional
            ++pChild_it;
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore Core: %.8X 2nd core orig state=0x%X",
                     get_huid(pCore), l_State.functional);
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            // Get the HWAS_STATE of FC
            ofc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore: should be functional - FC ofc_State.functional=0x%X", ofc_State.functional);
            if (!ofc_State.functional)
            {
                TS_FAIL("testDeConfigFC1BadCore: Fc non-functional, expected functional");
                break;
            }

            // Deconfigure the first core
            pCore = *pCoreList.begin();
            TS_INFO("testDeConfigFC1BadCore: calling deconfigureTarget for pCore HUID=%.8X",
                     get_huid(pCore));
            l_pErr = theDeconfigGard().deconfigureTarget(*pCore,
                          DeconfigGard::DECONFIGURED_BY_CORE_DECONFIG);
            if (l_pErr)
            {
                TS_FAIL("testDeConfigFC1BadCore: Error from deconfigureTarget");
                break;
            }

            // Get the new HWAS_STATE FC
            fc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore FC should be non-functional with one BAD core fc_State.functional=0x%X", fc_State.functional);

            if(is_fused_mode() && (!fc_State.functional))
            {
                TS_INFO("testDeConfigFC1BadCore: Case OK - FC non-functional with one BAD core is_fused_mode=0x%X fc_State.functional=0x%X",
                         is_fused_mode(), fc_State.functional);
            }
            else if (is_fused_mode() && (fc_State.functional))
            {
                TS_FAIL("testDeConfigFC1BadCore: Case FAIL - FC and functional with one BAD core is_fused_mode=0x%X fc_State.functional=0x%X",
                         is_fused_mode(), fc_State.functional);
                break;
            } else
            {
                TS_FAIL("testDeConfigFC1BadCore: Case FAIL - UNKNOWN Needs Investigation is_fused_mode=0x%X fc_State.functional=0x%X",
                         is_fused_mode(), fc_State.functional);
                break;
            }

            // Set both cores state functional
            pChild_it = pCoreList.begin();
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore Core: %.8X 1st core current non-functional state=0x%X",
                     get_huid(pCore), l_State.functional);
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            HwasState Core1_State = pCore->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore Core: %.8X 1st core reset should be functional state=0x%X",
                     get_huid(pCore), Core1_State.functional);

            fc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore CONFIRMING FC should be STILL -NOT- FUNCTIONAL 1st core reset to FUNCTIONAL fc_State.functional=0x%X", fc_State.functional);

            ++pChild_it;
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore Core: %.8X 2nd core current non-functional state=0x%X",
                     get_huid(pCore), l_State.functional);
            l_State.functional  =   1 ;
            HwasState Core2_State = pCore->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore Core: %.8X 2nd core reset should be functional state=0x%X",
                     get_huid(pCore), Core2_State.functional);
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            fc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore CONFIRMING FC should STILL be -NOT- FUNCTIONAL 2nd core reset to FUNCTIONAL fc_State.functional=0x%X", fc_State.functional);

            // Reset the HWAS_STATE of FC
            pFc->setAttr<ATTR_HWAS_STATE>(ofc_State);
            TS_INFO("testDeconfigFC1BadCore: RESETTING FC: %.8X setAttr to functional state=0x%X",
                get_huid(pFc), ofc_State.functional);

            // Get the HWAS_STATE of FC
            ofc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFC1BadCore: should NOW be functional - FC ofc_State.functional=0x%X", ofc_State.functional);
            if (!ofc_State.functional)
            {
                TS_FAIL("testDeConfigFC1BadCore: Fc non-functional, expected functional");
                break;
            }

            TS_INFO("testDeConfigFC1BadCore: Success");
        }
        while (0);
        restoreSystemState();
        TS_INFO("testDeConfigFC1BadCore: Ended");

#endif
    }

    /**
     *  @brief Test EQ with no good FCs should NOT be deconfigured
     */
    void testDeConfigEQ2BadFCs()
    {
        TS_INFO("testDeConfigEQ2BadFCs: Started");
#if DISABLE_FC_UNIT_TESTS
        TS_INFO("testDeConfigEQ2BadFCs - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;

        do
        {

            // find a eq unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predEq(CLASS_UNIT, TYPE_EQ);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);

            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEq).push(&predFunctional).And();

            TargetHandleList pEqList, pFcList;
            targetService().getAssociated( pEqList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeConfigEQ2BadFCs: pEqList.size()=%d",
                    pEqList.size());
            if (pEqList.empty())
            {
                TS_FAIL("testDeConfigEQ2BadFCs: empty pEqList");
                break;
            }

            // Pick up first EQ
            TargetHandle_t pEq = *pEqList.begin();
            TS_INFO("testDeConfigEQ2BadFCs EQ: %.8X",
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
                TS_INFO("testDeConfigEQ2BadFCs FC: %.8X",
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
                TS_INFO("testDeConfigEQ2BadFCs FC: %.8X",
                         get_huid(pFc));
                // Get the original HWAS_STATE of the target
                l_State = pFc->getAttr<ATTR_HWAS_STATE>();
                l_State.functional  =   1 ;
                pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            } // for CHILD
            TS_INFO("testDeConfigEQ2BadFCs: Success");
        }
        while (0);
        restoreSystemState();
        TS_INFO("testDeConfigEQ2BadFCs: Ended");

#endif
    }

    /**
     *  @brief Test EQ with one good and one bad FC should not be deconfigured
     */

    void testDeConfigEQ1BadFC()
    {
        TS_INFO("testDeConfigEQ1BadFC: Started");
#if DISABLE_UNIT_TESTS
        TS_INFO("testDeConfigEQ1BadFC - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;
        do
        {

            // find a eq unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predEq(CLASS_UNIT, TYPE_EQ);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);

            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predEq).push(&predFunctional).And();

            TargetHandleList pEqList;
            targetService().getAssociated( pEqList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeConfigEQ1BadFC: pEqList.size()=%d", pEqList.size());
            if (pEqList.empty())
            {
                TS_FAIL("testDeConfigEQ1BadFC: empty pEqList");
                break;
            }

            // Pick up first EQ
            TargetHandle_t pEq = *pEqList.begin();
            TS_INFO("testDeConfigEQ1BadFC EQ: %.8X", get_huid(pEq));
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
            TS_INFO("testDeConfigEQ1BadFC: PRE should be functional 1st Core %8.X state=0x%X",
                get_huid(pFc), l_State.functional);

            l_State.functional  =   0 ;
            pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);

            // Confirm that we setAttr properly
            l_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigEQ1BadFC: POST CONFIRMATION - SHOULD BE NON-FUNCTIONAL 1st Core %8.X state=0x%X",
                get_huid(pFc), l_State.functional);
            if (l_State.functional)
            {
                TS_FAIL("testDeConfigEQ1BadFC: FAILED to set 1st Core NON-FUNCTIONAL %8.X state=0x%X",
                    get_huid(pFc), l_State.functional);
            }

            // Set second core state functional explicitly for assurance test is properly setup
            ++pChild_it;
            pFc = *pChild_it;
            l_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigEQ1BadFC: PRE should be functional 2nd Core %8.X state=0x%X",
                get_huid(pFc), l_State.functional);
            if (!l_State.functional)
            {
                TS_WARN("testDeConfigEQ1BadFC: PRE should have been functional 2nd Core %8.X state=0x%X",
                    get_huid(pFc), l_State.functional);
            }
            l_State.functional  =   1 ;
            pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            l_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigEQ1BadFC: POST should be functional 2nd Core %8.X state=0x%X",
                get_huid(pFc), l_State.functional);
            if (!l_State.functional)
            {
                TS_FAIL("testDeConfigEQ1BadFC: FAILED to set 2nd Core FUNCTIONAL %8.X state=0x%X",
                    get_huid(pFc), l_State.functional);
            }

            // Get the HWAS_STATE of EQ
            oeq_State = pEq->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigEQ1BadFC: PRE should be functional EQ %8.X state=0x%X",
                get_huid(pEq), oeq_State.functional);
            if (!oeq_State.functional)
            {
                TS_FAIL("testDeConfigEQ1BadFC: EQ non-functional, expected functional");
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
            TS_INFO("testDeConfigEQ1BadFC: PRE should be functional EQ %8.X state=0x%X",
                get_huid(pEq), eq_State.functional);
            if (!eq_State.functional)
            {
                TS_FAIL("testDeConfigEQ1BadFC: EQ non-functional, one core functional");
                break;
            }

            // Set both FCs state functional
            pChild_it = pFcList.begin();
            pFc = *pChild_it;
            l_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigEQ1BadFC: PRE should be non-functional 1st Core %8.X state=0x%X",
                get_huid(pFc), l_State.functional);
            l_State.functional  =   1 ;
            pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            TS_INFO("testDeConfigEQ1BadFC: POST should be functional 1st Core %8.X state=0x%X",
                get_huid(pFc), l_State.functional);

            ++pChild_it;
            pFc = *pChild_it;
            l_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigEQ1BadFC: PRE should be functional 2nd Core %8.X state=0x%X",
                get_huid(pFc), l_State.functional);
            l_State.functional  =   1 ;
            pFc->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            TS_INFO("testDeConfigEQ1BadFC: POST should be functional 2nd Core %8.X state=0x%X",
                get_huid(pFc), l_State.functional);

            targetService().getAssociated( pEqList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testDeConfigEQ1BadFC: pEqList.size()=%d", pEqList.size());
            if (pEqList.empty())
            {
                TS_FAIL("testDeConfigEQ1BadFC: We should have some pEqList, but we are empty pEqList");
                break;
            }
            TS_INFO("testDeConfigEQ1BadFC: Success");
        }
        while (0);
        restoreSystemState();
        TS_INFO("testDeConfigEQ1BadFC: Ended");

#endif
    }

    /**
     *  @brief Test in fused core mode FC with one good and one bad core
     *  should be deconfigured
     */

    void testDeConfigFCInFusedCoreMode()
    {
        TS_INFO("testDeConfigFCInFusedCoreMode: Started");
#if DISABLE_FC_CRASH_UNIT_TESTS
        TS_INFO("testDeConfigFCInFusedCoreMode - SKIPPING -- other tests could be adversly affected");
#else

        // query original fuse mode
        Target* pSys = UTIL::assertGetToplevelTarget();
        auto l_oFusedMode = pSys->getAttr<ATTR_FUSED_CORE_OPTION>();
        TS_INFO("testDeConfigFCInFusedCoreMode l_oFusedMode=0x%X is_fused_mode=0x%X",
            l_oFusedMode, is_fused_mode());
        saveSystemState();
        errlHndl_t l_pErr = nullptr;
        do
        {

            // force fused core mode
            pSys->setAttr<ATTR_FUSED_CORE_OPTION>(FUSED_CORE_OPTION_USING_FUSED_CORES);
            TS_INFO("testDeConfigFCInFusedCoreMode FORCED FUSED CORE MODE");

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

            TS_INFO("testDeConfigFCInFusedCoreMode: pFcList.size()=%d", pFcList.size());
            if (pFcList.empty())
            {
                TS_WARN("testDeConfigFCInFusedCoreMode: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }

            // Pick up first FC
            TargetHandle_t pFc = *pFcList.begin();
            TS_INFO("testDeConfigFCInFusedCoreMode FC: %.8X",
                       get_huid(pFc));
            HwasState l_State, fc_State, ofc_State;
            TargetHandle_t pCore;

            // find all CHILD_BY_AFFINITY matches for this FC i.e. cores
            // set state non-functional
            TS_INFO("testDeConfigFCInFusedCoreMode: calling getChildAffinityTargets");
            getChildAffinityTargets(pCoreList, pFc, CLASS_NA ,TYPE_NA);
            TS_INFO("testDeConfigFCInFusedCoreMode: back calling getChildAffinityTargets");
            TS_INFO("testDeConfigFCInFusedCoreMode: pCoreList.size()=%d",
                    pCoreList.size());
            if (pCoreList.empty())
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: empty pCoreList");
                break;
            }

            // Set first core state non-functional
            TargetHandleList::iterator pChild_it = pCoreList.begin();
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFCInFusedCoreMode: PRE should be functional 1st Core %8.X state=0x%X",
                get_huid(pCore), l_State.functional);
            l_State.functional  =   0 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            TS_INFO("testDeConfigFCInFusedCoreMode: POST should be non-functional 1st Core %8.X state=0x%X",
                get_huid(pCore), l_State.functional);
            // Crashes HERE ^^ when the core is made non-functional and
            // we happen to be running on that core we stop

            // Set second core state functional
            ++pChild_it;
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFCInFusedCoreMode: PRE should be functional 2nd Core %8.X state=0x%X",
                get_huid(pCore), l_State.functional);
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            TS_INFO("testDeConfigFCInFusedCoreMode: POST should be functional 2nd Core %8.X state=0x%X",
                get_huid(pCore), l_State.functional);

            // Get the HWAS_STATE of FC
            ofc_State = pFc->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFCInFusedCoreMode: should be -NOT- functional FC %8.X state=0x%X",
                get_huid(pCore), ofc_State.functional);
            if (ofc_State.functional)
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: FC functional, expected non-functional");
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
            TS_INFO("testDeConfigFCInFusedCoreMode: should be -NOT- functional FC %8.X state=0x%X",
                get_huid(pFc), fc_State.functional);
            if (fc_State.functional)
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: FC functional after deconfigure");
                break;
            }

            // Reset FC state
            fc_State.functional = 1;
            pFc->setAttr<ATTR_HWAS_STATE>(fc_State);
            TS_INFO("testDeConfigFCInFusedCoreMode: should be functional FC %8.X state=0x%X",
                get_huid(pFc), fc_State.functional);

            // Set both cores state functional
            pChild_it = pCoreList.begin();
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFCInFusedCoreMode: PRE should be non-functional 1st Core %8.X state=0x%X",
                get_huid(pCore), l_State.functional);
            if (l_State.functional)
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: Core1 is functional in Fused Core Mode");
                break;
            }
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            TS_INFO("testDeConfigFCInFusedCoreMode: POST should be functional 1st Core %8.X state=0x%X",
                get_huid(pCore), l_State.functional);

            ++pChild_it;
            pCore = *pChild_it;
            l_State = pCore->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testDeConfigFCInFusedCoreMode: PRE should be non-functional 2nd Core %8.X state=0x%X",
                get_huid(pCore), l_State.functional);
            if (l_State.functional)
            {
                TS_FAIL("testDeConfigFCInFusedCoreMode: Core2 is functional after deconfigure");
                break;
            }
            l_State.functional  =   1 ;
            pCore->setAttr<TARGETING::ATTR_HWAS_STATE>(l_State);
            TS_INFO("testDeConfigFCInFusedCoreMode: POST should be functional 2nd Core %8.X state=0x%X",
                get_huid(pCore), l_State.functional);

            TS_INFO("testDeConfigFCInFusedCoreMode: Success");
        }
        while (0);

        //restore original fused mode
        TS_INFO("testDeConfigFCInFusedCoreMode PRE RESTORE ORIGINAL SAVED OFF OLD l_oFusedMode=0x%X is_fused_mode=0x%X",
            l_oFusedMode, is_fused_mode());
        pSys->setAttr<ATTR_FUSED_CORE_OPTION>(l_oFusedMode);
        TS_INFO("testDeConfigFCInFusedCoreMode POST RESTORE ORIGINAL SAVED OFF OLD l_oFusedMode=0x%X is_fused_mode=0x%X",
            l_oFusedMode, is_fused_mode());
        restoreSystemState();
        TS_INFO("testDeConfigFCInFusedCoreMode: Ended");

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
        TS_INFO("testDefDeconfig1: Started");
#if DISABLE_UNIT_TESTS
        TS_INFO("testDefDeconfig1: Skipped");
#else

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::DeconfigureRecords_t l_records;

        saveSystemState();
        do
        {
            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

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
                TS_FAIL("testDefDeconfig1: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
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
                TS_INFO("testDefDeconfig1: target has existing Deconfigure Record, SKIPPING test");
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

            TS_INFO("testDefDeconfig1: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testDefDeconfig1: Ended");
#endif
    }

    /**
     *  @brief Test getting all GARD Records
     */
    void testGard1()
    {
        TS_INFO("testGard1: Started");

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
            TS_FAIL("testGard1: Error from getGardRecords with a nullptr");
        }
        else
        {
            TS_INFO("testGard1: Success typically zero records - %d records",
                     l_records.size());
        }
    }

    /**
     *  @brief Test creating a GARD Record, getting the GARD Record and
     *         clearing the GARD Record
     */
    void testGard2()
    {
        TS_INFO("testGard2: Started");
#if DISABLE_UNIT_TESTS
        TS_INFO( "testGard2 - SKIPPING -- other tests could be adversly affected");
#else

        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();
            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testGard2: pFcList.size()=%d", pFcList.size());
            if (pFcList.empty())
            {
                TS_FAIL("testGard2: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();

            // Get any existing GARD Records for the target
            TS_INFO("testGard2: Working with HUID=0x%X TYPE_FC", get_huid(l_pTarget));
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);
            if (l_pErr)
            {
                TS_FAIL("testGard2: Error from getGardRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_INFO("testGard2: target has %d existing Gard Records, SKIPPING test",
                         l_records.size());
                break;
            }

            // Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_pTarget, 0x12, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard2: Error from platCreateGardRecord");
                break;
            }

            // Get the GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard2: Error from getGardRecords (2)");
                break;
            }

            if (l_records.size() != 1)
            {
                TS_FAIL("testGard2: %d records for target, expected 1",
                        l_records.size());
                break;
            }

            if (l_records[0].iv_errorType != GARD_Predictive)
            {
                TS_FAIL("testGard2: Record errorType %d, expected predictive",
                        l_records[0].iv_errorType);
                break;
            }

            // Clear the GARD Records for the target
            l_pErr = theDeconfigGard().clearGardRecords(l_pTarget);

            if (l_pErr)
            {
                TS_FAIL("testGard2: Error from clearGardRecords");
                break;
            }

            // Get the GARD Records for the target
            l_records.clear();

            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard2: Error from getGardRecords (3)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testGard2: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            TS_INFO("testGard2: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        TS_INFO("testGard2: Ended");
#endif
    }

    /**
     *  @brief Test creating a GARD Record for a Target multiple times
     */
    void testGard3()
    {
        TS_INFO("testGard3: Started");
#if DISABLE_UNIT_TESTS
        TS_INFO( "testGard3 - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

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
                TS_FAIL("testGard3: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();
            TS_INFO("testGard3: Working with HUID=0x%X TYPE_FC", get_huid(l_pTarget));

            // Get any existing GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard3: Error from getGardRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_INFO("testGard3: target has %d existing Gard Records, SKIPPING test",
                         l_records.size());
                break;
            }

            // Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_pTarget, 0x23, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard3: Error from platCreateGardRecord");
                break;
            }

            // Create another GARD Record for the target
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_pTarget, 0x45, GARD_Fatal);

            if (l_pErr)
            {
                TS_FAIL("testGard3: Error from platCreateGardRecord (2)");
                break;
            }

            // Get the GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard3: Error from getGardRecords (2)");
                break;
            }

            if (l_records.size() != 1)
            {
                TS_FAIL("testGard3: %d records for target, expected 1",
                        l_records.size());
                break;
            }

            // Clear the GARD Record for the target
            l_pErr = theDeconfigGard().clearGardRecords(l_pTarget);

            if (l_pErr)
            {
                TS_FAIL("testGard3: Error from clearGardRecords");
                break;
            }

            // Get the GARD Records for the target
            l_records.clear();

            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard3: Error from getGardRecords (3)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testGard3: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            TS_INFO("testGard3: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testGard3: Ended");
#endif
    }

    /**
     *  @brief Test creating a 2nd GARD Record overwrites manual gard
     */
    void testGard4()
    {
        TS_INFO("testGard4: Started");
#if DISABLE_FC_UNIT_TESTS
        TS_INFO("testGard4 - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

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
                TS_FAIL("testGard4: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();
            TS_INFO("testGard4: Working with HUID=0x%X TYPE_FC", get_huid(l_pTarget));

            // Get any existing GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from getGardRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_INFO("testGard4: target has %d existing Gard Records, SKIPPING test",
                         l_records.size());
                break;
            }

            // Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_pTarget, 0x23, GARD_User_Manual);

            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from platCreateGardRecord");
                break;
            }

            // Create another GARD Record for the target - should overwrite
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_pTarget, 0x46, GARD_Fatal);

            if (l_pErr)
            {
                TS_FAIL("testGard4: Error from platCreateGardRecord (2)");
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

            if ((l_records[0].iv_errlogEid != 0x46) ||
                (l_records[0].iv_errorType != GARD_Fatal))
            {
                TS_FAIL("testGard4: unexpected data - errl 0x%X type %x",
                    l_records[0].iv_errlogEid, l_records[0].iv_errorType);
                break;
            }

            // Clear the GARD Record for the target
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

            TS_INFO("testGard4: Success");
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
     *  @brief Test getting and clearing all GARD Records
     *
     *  Creates one gard record then clearGardRecords for all.
     */
    void testGard5()
    {
        TS_INFO("testGard5: Started");
#if DISABLE_FC_UNIT_TESTS
        TS_INFO("testGard5: - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

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
                TS_FAIL("testGard5: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();
            TS_INFO("testGard5: Working with HUID=0x%X TYPE_FC", get_huid(l_pTarget));

            // Get all existing GARD Records
            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from getGardRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_INFO("testGard5: %d existing Gard Records, SKIPPING test",
                         l_records.size());
                break;
            }

            // Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_pTarget, 0x71, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from platCreateGardRecord");
                break;
            }

            // Clear all GARD Records
            l_pErr = theDeconfigGard().clearGardRecords(nullptr);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from clearGardRecords(nullptr)");
                break;
            }

            // Get the GARD Records
            l_records.clear();

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard5: Error from getGardRecords (2)");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_FAIL("testGard5: %d records for target, expected 0",
                        l_records.size());
                break;
            }

            TS_INFO("testGard5: Success");
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
     *  @brief Test create GARD record, call collect GARD to confirm targets
     *      are deconfigured, set changed bit ala HCDB, reprocess GARD to
     *      confirm GARD record is deleted.
     */
    void testGard6()
    {
        TS_INFO("testGard6: Started");
#if DISABLE_FC_UNIT_TESTS
        TS_INFO("testGard6: - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testGard6: Error from getGardRecords");
                break;
            }

            if (l_records.size() > 0)
            {
                TS_FAIL("testGard6: already GARD records here. %d records",
                        l_records.size());
                break;
            }
            // find an fc unit that we can play with

            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();

            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testGard6: pFcList.size()=%d", pFcList.size());
            if (pFcList.empty())
            {
                TS_WARN("testGard6: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }

            TargetHandle_t l_target = *pFcList.begin();
            TS_INFO("testGard6: Working with HUID=0x%X TYPE_FC", get_huid(l_target));

            //This test assumes the target chosen is not deemed a replacement target,
            //   this distinction is important because gard records for targets that
            //   are then found to be replaced are ignore, and we do not want that for
            //   these tests. So set the HWAS_CHANGED_BIT_GARD to force this target
            //   to not be seen as a replacement target
            clear_hwas_changed_bit(l_target, HWAS_CHANGED_BIT_GARD);

            // create GARD record, call 'doGard' step and confirm target is
            //  deconfigured
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_target, 0x12, GARD_Void);
            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from platCreateGardRecord");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testGard6: Error from getGardRecords");
                break;
            }
            TS_INFO("testGard6: l_records.size()=%d should be 1 for doGard setup", l_records.size());
            if (l_records.size() != 1)
            {
                TS_FAIL("testGard6: should be 1 record; instead %d records",
                        l_records.size());
                break;
            }

            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard6: Error from collectGard");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testGard6: Error from getGardRecords 2");
                break;
            }
            TS_INFO("testGard6: POST collectGard l_records.size()=%d should be 1 for doGard setup", l_records.size());
            HwasState l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testGard6: l_state=0x%X", l_state);
            if (l_records.size() != 1)
            {
                TS_WARN("testGard6: should be 1 record; instead %d records, check logs for "
                        "Insufficient HW to continue IPL: (no func cores)",
                        l_records.size());
            }
            else
            {
                if (l_state.functional)
                {
                    TS_FAIL("testGard6: target still functional, should have been non-functional");
                    break;
                }
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
                TS_FAIL("testGard6: Error from collectGard2");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testGard6: Error from getGardRecords");
                break;
            }
            TS_INFO("testGard6: l_records.size()=%d should be 0 for doGard setup", l_records.size());
            if (l_records.size() != 0)
            {
                TS_FAIL("testGard6: should be 0 records; instead %d records",
                        l_records.size());
                break;
            }

            l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testGard6: l_state=0x%X", l_state);
            if (!l_state.functional)
            {
                TS_FAIL("testGard6: target NOT functional");
                break;
            }

            TS_INFO("testGard6: Success");
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
     *  @brief Test CDM modes to restrict creating GARD records
     */
    void testGard7()
    {
        TS_INFO("testGard7: Started");
#if DISABLE_FC_UNIT_TESTS
        TS_INFO( "testGard7: - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            // find an fc unit that we can play with
            Target* pSys = UTIL::assertGetToplevelTarget();

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
                TS_FAIL("testGard7: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }
            TargetHandle_t l_pTarget = *pFcList.begin();
            TS_INFO("testGard7: Working with HUID=0x%X TYPE_FC", get_huid(l_pTarget));

            // Get any existing GARD Records for the target
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from getGardRecords");
                break;
            }

            if (l_records.size() != 0)
            {
                TS_INFO("testGard7: target has %d existing Gard Records, SKIPPING test",
                         l_records.size());
                break;
            }

            // set Manufacturing policy to disabled,
            //  test that gard record is not created
            ATTR_CDM_POLICIES_type l_policies =
                pSys->getAttr<ATTR_CDM_POLICIES>();
            TS_INFO("testGard7: l_policies=0x%X", l_policies);
            l_policies = CDM_POLICIES_MANUFACTURING_DISABLED;
            TS_INFO("testGard7: DISABLED ? l_policies=0x%X", l_policies);
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            // (try to) Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_pTarget, 0x12, GARD_Fatal);

            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from platCreateGardRecord");
                break;
            }

            // Get the GARD Records for the target - shouldn't be any
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

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

            // set Predictive policy to disabled
            //  test that gard record isn't created
            l_policies = CDM_POLICIES_PREDICTIVE_DISABLED;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            // (try to) Create a GARD Record for the target.
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_pTarget, 0x12, GARD_Predictive);

            if (l_pErr)
            {
                TS_FAIL("testGard7: Error from platCreateGardRecord");
                break;
            }

            // Get the GARD Records for the target - shouldn't be any
            l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

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

            // restore
            l_policies = 0;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);
            TS_INFO("testGard7: Success");
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
     *  @brief Test CDM modes to restrict processing GARD records
     */
    void testGard8()
    {
        TS_INFO("testGard8: Started");
#if DISABLE_FC_UNIT_TESTS
        TS_INFO( "testGard8 - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
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
            Target* pSys = UTIL::assertGetToplevelTarget();

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
                TS_WARN("testGard8: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }

            TargetHandle_t l_target = *pFcList.begin();
            TS_INFO("testGard8: Working with HUID=0x%X TYPE_FC", get_huid(l_target));

            // create GARD record, set Policy, call 'doGard' step and confirm
            //  target is NOT deconfigured
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_target, 0x12, GARD_Predictive);
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

            // set Manufacturing policy to disabled,
            //  test that gard record is not created
            ATTR_CDM_POLICIES_type l_policies =
                pSys->getAttr<ATTR_CDM_POLICIES>();
            TS_INFO("testGard8: l_policies=0x%X", l_policies);
            l_policies = CDM_POLICIES_MANUFACTURING_DISABLED;
            TS_INFO("testGard8: DISABLED ? l_policies=0x%X", l_policies);
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard8: Error from collectGard");
                break;
            }

            HwasState l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testGard8: target NOT functional");
                break;
            }

            // set Predictive policy to disabled,
            //  test that gard record is not created
            l_policies = CDM_POLICIES_PREDICTIVE_DISABLED;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard8: Error from collectGard");
                break;
            }

            l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            if (!l_state.functional)
            {
                TS_FAIL("testGard8: target NOT functional");
                break;
            }

            // Clear all GARD Records
            l_pErr = theDeconfigGard().clearGardRecords(nullptr);
            if (l_pErr)
            {
                TS_FAIL("testGard8: Error from clearGardRecords(nullptr)");
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

            // create GARD record, set Policy, call 'doGard' step and confirm
            //  target is NOT deconfigured

            //  Clear out policy
            l_policies = 0;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);

            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_target, 0x12, GARD_Predictive);
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
                TS_FAIL("testGard8: should be 1 records; instead %d records",
                        l_records.size());
                break;
            }

            // Clear all GARD Records
            l_pErr = theDeconfigGard().clearGardRecords(nullptr);
            if (l_pErr)
            {
                TS_FAIL("testGard8: Error from clearGardRecords(nullptr)");
                break;
            }

            // restore
            l_policies = 0;
            pSys->setAttr<ATTR_CDM_POLICIES>(l_policies);
            TS_INFO("testGard8: Success");
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
     *  @brief Test create GARD record, call collect GARD to confirm targets
     *      are deconfigured, set changed bit ala HCDB, reprocess GARD to
     *      confirm GARD record is deleted.
     */
    void testGard9()
    {
        TS_INFO("testGard9: Started");
#if DISABLE_UNIT_TESTS
        TS_INFO( "testGard9 - SKIPPING -- other tests could be adversly affected");
#else

        saveSystemState();
        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testGard9: Error from getGardRecords");
                break;
            }

            if (l_records.size() > 0)
            {
                TS_FAIL("testGard9: already GARD records here. %d records",
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
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predFc(CLASS_UNIT, TYPE_FC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&predFunctional).And();

            TargetHandleList pFcList;
            targetService().getAssociated( pFcList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testGard9: pFcList.size=%d", pFcList.size());
            if (pFcList.empty())
            {
                TS_WARN("testGard9: SKIPPING empty pFcList CLASS_UNIT, TYPE_FC");
                break;
            }

            TargetHandle_t l_target = *pFcList.begin();
            TS_INFO("testGard9: Working with HUID=0x%X TYPE_FC", get_huid(l_target));

            // Save ATTR_BLOCK_SPEC_DECONFIG value
            TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_orig_block_spec_deconfig
                = pSys->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
            TS_INFO("testGard9: l_orig_block_spec_deconfig=0x%X", l_orig_block_spec_deconfig);

            // Allow speculative deconfigs (clear ATTR_BLOCK_SPEC_DECONFIG)
            TS_INFO("testGard9: Allow speculative deconfigs");
            pSys->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(0);

            // create GARD record, call 'doGard' step and confirm target is
            //  deconfigured
            l_pErr = theDeconfigGard().
                    platCreateGardRecord(l_target, 0x12, GARD_Predictive);
            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from platCreateGardRecord");
                break;
            }

            l_pErr = theDeconfigGard().getGardRecords(nullptr, l_records);
            if (l_pErr)
            {
                errlCommit(l_pErr,CXXTEST_COMP_ID);
                TS_FAIL("testGard9: Error from getGardRecords");
                break;
            }
            if (l_records.size() != 1)
            {
                TS_FAIL("testGard9: should be 1 record; instead %d records",
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
                TS_FAIL("testGard9: Error from collectGard");
                break;
            }

            HwasState l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testGard9: Stage 1 l_state.functional=0x%X", l_state.functional);
            if (l_state.functional)
            {
                TS_FAIL("testGard9: target still functional");
                break;
            }

            // Block speculative deconfigs(set ATTR_BLOCK_SPEC_DECONFIG)
            TS_INFO("testGard9: Block speculative deconfigs");
            pSys->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(1);

            // restore functional state
            l_state.functional = true;
            l_target->setAttr<ATTR_HWAS_STATE>(l_state);

            // call collectGard and confirm Block speculative deconfigs stays
            //  set and target stays functional
            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from collectGard call 2");
                break;
            }

            TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_block_spec_deconfig
                = pSys->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
            TS_INFO("testGard9: l_block_spec_deconfig=0x%X", l_block_spec_deconfig);
            if(l_block_spec_deconfig == 0)
            {
                TS_FAIL("testGard9: block spec deconfig cleared");
                break;
            }

            l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testGard9: Stage 2 l_state.functional=0x%X", l_state.functional);
            if (!l_state.functional)
            {
                TS_FAIL("testGard9: target NOT functional");
                break;
            }

            // emulate HCDB - target changed, call collectGard and confirm Block
            //  speculative deconfigs is cleared and target is deconfigured
            update_hwas_changed_mask(l_target);
            l_pErr = collectGard();
            if (l_pErr)
            {
                TS_FAIL("testGard9: Error from collectGard call 2");
                break;
            }

            l_block_spec_deconfig = pSys->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
            TS_INFO("testGard9: l_block_spec_deconfig=0x%X", l_block_spec_deconfig);
            if(l_block_spec_deconfig != 0)
            {
                TS_FAIL("testGard9: block spec deconfig NOT cleared, is %d",
                        l_block_spec_deconfig);
                break;
            }

            l_state = l_target->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("testGard9: l_state.functional=0x%X", l_state.functional);
            if (!l_state.functional)
            {
                TS_FAIL("testGard9: target NOT functional");
                break;
            }

            // Restore
            l_state.functional = true;
            l_target->setAttr<ATTR_HWAS_STATE>(l_state);
            pSys->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(l_orig_block_spec_deconfig);

            TS_INFO("testGard9: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        restoreSystemState();
        TS_INFO("testGard9: Ended");
#endif
    }


    /**
     *  @brief Test garding types
     *
     *
     */
    void testGardTypes()
    {
        TS_INFO("testGardTypes: Started");
#if DISABLE_VERS_UNIT_TESTS
        TS_INFO( "testGardTypes - SKIPPING -- other tests could be adversly affected");
#else
        const uint32_t DUMMY_EID = 0x12;
        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;
        ATTR_DECONFIG_GARDABLE_type l_gardable;
        uint8_t l_present;
        struct testcase_t
        {
            ATTR_TYPE_type targetType;
            ATTR_CHIPLET_ID_type chipletID;
        }
        static const testcases[] =
        {
            { TYPE_NMMU,      ANY_CHIPLET },
            { TYPE_PEC,       ANY_CHIPLET },
            { TYPE_MC,        ANY_CHIPLET },
            { TYPE_PAUC,      ANY_CHIPLET },
            { TYPE_PAU,       ANY_CHIPLET },
            { TYPE_IOHS,      ANY_CHIPLET },
            { TYPE_EQ,        ANY_CHIPLET },
            { TYPE_PERV,      ANY_CHIPLET },
            { TYPE_MCC,       ANY_CHIPLET },
            { TYPE_OMI,       ANY_CHIPLET },
            { TYPE_OMIC,      ANY_CHIPLET },
            { TYPE_CORE,      ANY_CHIPLET },
            { TYPE_IOHS,      ANY_CHIPLET },
            { TYPE_MI,        ANY_CHIPLET },
            { TYPE_FC,        ANY_CHIPLET },
            { TYPE_TPM,       ANY_CHIPLET },
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
                    TS_INFO("testGardTypes: NO l_target, CONTINUE");
                    continue;
                }
                const char* const l_targetType = l_target->getAttrAsString<ATTR_TYPE>();
                const auto l_huid = get_huid(l_target);
                TS_INFO("testGardTypes: Working with HUID=0x%X l_targetType=%s",
                    l_huid, l_targetType);

                l_gardable = l_target->getAttr<ATTR_DECONFIG_GARDABLE>();
                l_present = l_target->getAttr<ATTR_HWAS_STATE>().present;
                TS_INFO("testGardTypes: l_gardable=0x%X l_present=0x%X", l_gardable, l_present);
                if (l_target->getAttr<ATTR_HWAS_STATE>().functional)
                {
                    if (l_gardable && l_present)
                    {
                        TS_INFO("testGardTypes: GARDing HUID=0x%X TYPE=0x%X",
                            l_huid, l_testcase.targetType);
                        l_pErr = theDeconfigGard().platCreateGardRecord(l_target, DUMMY_EID, GARD_Predictive);
                        if (l_pErr)
                        {
                            TS_FAIL("testGardTypes: Error from platCreateGardRecord HUID=0x%X",
                                l_huid);
                            break;
                        }

                        l_pErr = theDeconfigGard().getGardRecords(l_target, l_records);

                        if (l_pErr)
                        {
                            TS_FAIL("testGardTypes: Error from getGardRecords HUID=0x%X",
                                l_huid);
                            break;
                        }

                        if (l_records.size() != 1)
                        {
                            TS_FAIL("testGardTypes: %d records for HUID=0x%X expected 1",
                                l_huid, l_records.size());
                            break;
                        }

                        // just a trace point
                        l_pErr = theDeconfigGard().dumpGardRecords(nullptr, l_records);

                        if (l_pErr)
                        {
                            TS_FAIL("testGardTypes: Error from dumpGardRecords");
                            break;
                        }

                        l_pErr = theDeconfigGard().clearGardRecords(nullptr);
                        if (l_pErr)
                        {
                            TS_FAIL("testGardTypes: Error from clearGardRecords");
                            break;
                        }

                        l_records.clear();

                        l_pErr = theDeconfigGard().getGardRecords(l_target, l_records);

                        if (l_pErr)
                        {
                            TS_FAIL("testGardTypes: Error from getGardRecords HUID=0x%X",
                                l_huid);
                            break;
                        }

                        if (l_records.size() != 0)
                        {
                            TS_FAIL("testGardTypes: %d records for HUID=0x%X, expected 0",
                                l_records.size(), l_huid);
                            break;
                        }
                    }
                    else
                    {
                        TS_INFO("testGardTypes: SKIPPING HUID=0x%X TYPE=0x%X -NOT- GARDABLE or Present",
                            l_huid, l_testcase.targetType);
                    }
                }
                else
                {
                    TS_INFO("testGardTypes: SKIPPING HUID=0x%X TYPE=0x%X NOT Functional, state.present=0x%X",
                        l_huid, l_testcase.targetType, l_present);
                }
            }
            if (l_pErr)
            {
                TS_FAIL("testGardTypes: Error processing");
                break;
            }
        }

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        TS_INFO("testGardTypes: Ended");
#endif
    }

    /**
     *  @brief Test gard versioning
     *
     *  This needs revisted - RTC 215332
     *  RTC 215332 will support ibm11s data in DDIMM
     *
     */
    void testGardVersion()
    {
        TS_INFO("testGardVersion: Started");
#if DISABLE_VERS_UNIT_TESTS
        TS_INFO( "testGardVersion - SKIPPING -- other tests could be adversly affected");
#else

        const uint32_t DUMMY_EID = 0x12;
        errlHndl_t l_pErr = nullptr;
        DeconfigGard::GardRecords_t l_records;

        do
        {
            Target* pSys = UTIL::assertGetToplevelTarget();
            TargetHandleList fullList;
            size_t number_processed = 0;

            TARGETING::PredicateCTM predFc(TARGETING::CLASS_UNIT,
                                                  TARGETING::TYPE_FC);
            TARGETING::PredicateCTM dimms(TARGETING::CLASS_LOGICAL_CARD,
                                   TARGETING::TYPE_DIMM,
                                   TARGETING::MODEL_NA);

            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predFc).push(&dimms).Or().push(&predFunctional).And();

            targetService().getAssociated(fullList, pSys,
                TargetService::CHILD, TargetService::ALL, &checkExpr );

            TS_INFO("testGardVersion: number to process is fullList.size=%d", fullList.size());
            if (fullList.empty())
            {
                TS_FAIL("testGardVersion: empty fullList");
                break;
            }

            for( auto j = fullList.begin(); j != fullList.end(); ++j )
            {
                TargetHandle_t l_pTarget = *j;

                l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

                if (l_pErr)
                {
                    TS_FAIL("testGardVersion: Error from getGardRecords");
                    break;
                }
                if (l_records.size() != 0)
                {
                    TS_INFO("testGardVersion: target has %d existing Gard Records, SKIPPING test",
                             number_processed, l_records.size());
                     break;
                }

                l_pErr = theDeconfigGard().
                        platCreateGardRecord(l_pTarget, DUMMY_EID, GARD_Predictive);

                if (l_pErr)
                {
                    TS_FAIL("testGardVersion: Error from platCreateGardRecord");
                    break;
                }

                l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

                if (l_pErr)
                {
                    TS_FAIL("testGardVersion: Error from getGardRecords (2)");
                    break;
                }

                if (l_records.size() != 1)
                {
                    TS_FAIL("testGardVersion: %d records for target, expected 1",
                            l_records.size());
                    break;
                }

                if (l_records[0].iv_errorType != GARD_Predictive)
                {
                    TS_FAIL("testGardVersion: Record errorType %d, expected predictive",
                            l_records[0].iv_errorType);
                    break;
                }

                l_pErr = theDeconfigGard().dumpGardRecords(l_pTarget, l_records);

                if (l_pErr)
                {
                    TS_FAIL("testGardVersion: Error from dumpGardRecords");
                    break;
                }
                // Specifically pass nullptr to perform clear ALL to test paths
                l_pErr = theDeconfigGard().clearGardRecords(nullptr);

                if (l_pErr)
                {
                    TS_FAIL("testGardVersion: Error from clearGardRecords");
                    break;
                }

                l_records.clear();

                l_pErr = theDeconfigGard().getGardRecords(l_pTarget, l_records);

                if (l_pErr)
                {
                    TS_FAIL("testGardVersion: Error from getGardRecords (3)");
                    break;
                }

                l_pErr = theDeconfigGard().dumpGardRecords(l_pTarget, l_records);

                if (l_pErr)
                {
                    TS_FAIL("testGardVersion: Error from dumpGardRecords - empty");
                    break;
                }

                if (l_records.size() != 0)
                {
                    TS_FAIL("testGardVersion: %d records for target, expected 0",
                            l_records.size());
                    break;
                }

                number_processed++;
                TS_INFO("testGardVersion: Success number_processed for item %d of %d total",
                    number_processed, fullList.size());
            } // end for

            if (number_processed != fullList.size())
            {
                TS_FAIL("testGardVersion: Error total number_processed %d does -NOT- match fullList.size=%d",
                    number_processed, fullList.size());
            }
            else
            {
                TS_INFO("testGardVersion: Success total number_processed %d matches fullList.size=%d",
                    number_processed, fullList.size());
            }
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr,CXXTEST_COMP_ID);
        }
        TS_INFO("testGardVersion: Ended");
#endif
    }

    /**
     *  @brief Test Deconfigure Associated Proc1
     */
    void testDeconfigureAssocProc1()
    {
        TS_INFO("testDeconfigureAssocProc1: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: System with Master proc (group 0) and proc2 (group 1) out-group bus1 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        // out-group bus1 and 2 linked to proc2
        l_procs[0].iv_pOutGroupProcInfos[0] = &l_procs[2];
        l_procs[0].iv_pOutGroupProcInfos[1] = &l_procs[2];
        // out-group bus1 endpoint deconfigured
        l_procs[0].iv_OutGroupLinkDeconfigured[0] = true;
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = false;     // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[1].iv_pOutGroupProcInfos[0] = &l_procs[3];
        l_procs[1].iv_pOutGroupProcInfos[1] = &l_procs[3];
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[0];

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[2].iv_pOutGroupProcInfos[0] = &l_procs[0];
        l_procs[2].iv_pOutGroupProcInfos[1] = &l_procs[0];
        l_procs[2].iv_OutGroupLinkDeconfigured[0] = true;
        // in-group bus links and states
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[3].iv_pOutGroupProcInfos[0] = &l_procs[1];
        l_procs[3].iv_pOutGroupProcInfos[1] = &l_procs[2];
        // in-group bus links and states
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[2];

        // Set the correct broadcast mode for a multi-group scenario, default broadcast mode is for single-group.
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE);

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_procs[0].iv_deconfigured == false &&
            l_procs[1].iv_deconfigured == false &&
            l_procs[2].iv_deconfigured == true &&
            l_procs[3].iv_deconfigured == true)
        {
            TS_INFO("testDeconfigureAssocProc1: Success");
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
        TS_INFO("testDeconfigureAssocProc2: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: System with Master proc's in-group bus1 and proc3's in-group bus1 deconfigured,
        //             where the Master is proc2

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = false;     // Note master proc
        l_procs[0].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[0].iv_pOutGroupProcInfos[0] = &l_procs[2];
        l_procs[0].iv_pOutGroupProcInfos[1] = &l_procs[2];
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = false;     // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[1].iv_pOutGroupProcInfos[0] = &l_procs[3];
        l_procs[1].iv_pOutGroupProcInfos[1] = &l_procs[3];
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[0];

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = true;      // Master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[2].iv_pOutGroupProcInfos[0] = &l_procs[0];
        l_procs[2].iv_pOutGroupProcInfos[1] = &l_procs[0];
        // in-group bus links and states
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];
        l_procs[2].iv_InGroupLinkDeconfigured[0] = true;

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[3].iv_pOutGroupProcInfos[0] = &l_procs[1];
        l_procs[3].iv_pOutGroupProcInfos[1] = &l_procs[1];
        // in-group bus links and states
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[2];
        l_procs[3].iv_InGroupLinkDeconfigured[0] = true;

        // Set the correct broadcast mode for a multi-group scenario, default broadcast mode is for single-group.
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE);
        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);

        // Check result
        if (l_procs[0].iv_deconfigured == false &&
            l_procs[1].iv_deconfigured == true &&
            l_procs[2].iv_deconfigured == false &&
            l_procs[3].iv_deconfigured == true)
        {
            TS_INFO("testDeconfigureAssocProc2: Success");
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
        TS_INFO("testDeconfigureAssocProc3: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: System with Master and proc1's
        // in-group bus1 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 8;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[0].iv_pOutGroupProcInfos[0] = &l_procs[2];
        l_procs[0].iv_pOutGroupProcInfos[1] = &l_procs[4];
        l_procs[0].iv_pOutGroupProcInfos[2] = &l_procs[6];
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];
        l_procs[0].iv_InGroupLinkDeconfigured[0] = true;

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = false;     // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[1].iv_pOutGroupProcInfos[0] = &l_procs[5];
        l_procs[1].iv_pOutGroupProcInfos[1] = &l_procs[7];
        l_procs[1].iv_pOutGroupProcInfos[2] = &l_procs[3];
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[0];
        l_procs[1].iv_InGroupLinkDeconfigured[0] = true;

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[2].iv_pOutGroupProcInfos[0] = &l_procs[0];
        l_procs[2].iv_pOutGroupProcInfos[1] = &l_procs[6];
        l_procs[2].iv_pOutGroupProcInfos[2] = &l_procs[4];
        // in-group bus links and states
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[3].iv_pOutGroupProcInfos[0] = &l_procs[7];
        l_procs[3].iv_pOutGroupProcInfos[1] = &l_procs[5];
        l_procs[3].iv_pOutGroupProcInfos[2] = &l_procs[1];
        // in-group bus links and states
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[2];

        // Proc4:
        l_procs[4].iv_pThisProc = nullptr;          // Target *
        l_procs[4].procHUID = 4;                 // HUID
        l_procs[4].procFabricGroup = 2;          // FABRIC_GROUP_ID
        l_procs[4].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[4].iv_masterCapable = false;      // Master proc
        l_procs[4].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[4].iv_pOutGroupProcInfos[0] = &l_procs[6];
        l_procs[4].iv_pOutGroupProcInfos[1] = &l_procs[0];
        l_procs[4].iv_pOutGroupProcInfos[2] = &l_procs[2];
        // in-group bus links and states
        l_procs[4].iv_pInGroupProcInfos[0] = &l_procs[5];

        // Proc5:
        l_procs[5].iv_pThisProc = nullptr;          // Target *
        l_procs[5].procHUID = 5;                 // HUID
        l_procs[5].procFabricGroup = 2;          // FABRIC_GROUP_ID
        l_procs[5].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[5].iv_masterCapable = false;     // Not master proc
        l_procs[5].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[5].iv_pOutGroupProcInfos[0] = &l_procs[1];
        l_procs[5].iv_pOutGroupProcInfos[1] = &l_procs[3];
        l_procs[5].iv_pOutGroupProcInfos[2] = &l_procs[7];
        // in-group bus links and states
        l_procs[5].iv_pInGroupProcInfos[0] = &l_procs[4];

        // Proc6:
        l_procs[6].iv_pThisProc = nullptr;          // Target *
        l_procs[6].procHUID = 6;                 // HUID
        l_procs[6].procFabricGroup = 3;          // FABRIC_GROUP_ID
        l_procs[6].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[6].iv_masterCapable = false;     // Not master proc
        l_procs[6].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[6].iv_pOutGroupProcInfos[0] = &l_procs[4];
        l_procs[6].iv_pOutGroupProcInfos[1] = &l_procs[2];
        l_procs[6].iv_pOutGroupProcInfos[2] = &l_procs[0];
        // in-group bus links and states
        l_procs[6].iv_pInGroupProcInfos[0] = &l_procs[7];

        // Proc7:
        l_procs[7].iv_pThisProc = nullptr;          // Target *
        l_procs[7].procHUID = 7;                 // HUID
        l_procs[7].procFabricGroup = 3;          // FABRIC_GROUP_ID
        l_procs[7].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[7].iv_masterCapable = false;     // Not master proc
        l_procs[7].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[7].iv_pOutGroupProcInfos[0] = &l_procs[3];
        l_procs[7].iv_pOutGroupProcInfos[1] = &l_procs[1];
        l_procs[7].iv_pOutGroupProcInfos[2] = &l_procs[5];
        // in-group bus links and states
        l_procs[7].iv_pInGroupProcInfos[0] = &l_procs[6];

        // Set the correct broadcast mode for a multi-group scenario, default broadcast mode is for single-group.
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE);
        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);

        // Check result
        if (l_procs[0].iv_deconfigured == false &&
            l_procs[1].iv_deconfigured == true &&
            l_procs[2].iv_deconfigured == false &&
            l_procs[3].iv_deconfigured == true &&
            l_procs[4].iv_deconfigured == false &&
            l_procs[5].iv_deconfigured == true &&
            l_procs[6].iv_deconfigured == false &&
            l_procs[7].iv_deconfigured == true)
        {
            TS_INFO("testDeconfigureAssocProc3: Success");
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
        TS_INFO("testDeconfigureAssocProc4: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: System with proc6/7 in-group bus1 and
        // proc2/4 out-group bus2 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 8;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[0].iv_pOutGroupProcInfos[0] = &l_procs[2];
        l_procs[0].iv_pOutGroupProcInfos[1] = &l_procs[4];
        l_procs[0].iv_pOutGroupProcInfos[2] = &l_procs[6];
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = false;     // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[1].iv_pOutGroupProcInfos[0] = &l_procs[5];
        l_procs[1].iv_pOutGroupProcInfos[1] = &l_procs[7];
        l_procs[1].iv_pOutGroupProcInfos[2] = &l_procs[3];
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[0];

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[2].iv_pOutGroupProcInfos[0] = &l_procs[0];
        l_procs[2].iv_pOutGroupProcInfos[1] = &l_procs[6];
        l_procs[2].iv_pOutGroupProcInfos[2] = &l_procs[4];
        l_procs[2].iv_OutGroupLinkDeconfigured[2] = true;
        // in-group bus links and states
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[3].iv_pOutGroupProcInfos[0] = &l_procs[7];
        l_procs[3].iv_pOutGroupProcInfos[1] = &l_procs[5];
        l_procs[3].iv_pOutGroupProcInfos[2] = &l_procs[1];
        // in-group bus links and states
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[2];

        // Proc4:
        l_procs[4].iv_pThisProc = nullptr;          // Target *
        l_procs[4].procHUID = 4;                 // HUID
        l_procs[4].procFabricGroup = 2;          // FABRIC_GROUP_ID
        l_procs[4].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[4].iv_masterCapable = false;      // Master proc
        l_procs[4].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[4].iv_pOutGroupProcInfos[0] = &l_procs[6];
        l_procs[4].iv_pOutGroupProcInfos[1] = &l_procs[0];
        l_procs[4].iv_pOutGroupProcInfos[2] = &l_procs[2];
        l_procs[4].iv_OutGroupLinkDeconfigured[2] = true;
        // in-group bus links and states
        l_procs[4].iv_pInGroupProcInfos[0] = &l_procs[5];

        // Proc5:
        l_procs[5].iv_pThisProc = nullptr;          // Target *
        l_procs[5].procHUID = 5;                 // HUID
        l_procs[5].procFabricGroup = 2;          // FABRIC_GROUP_ID
        l_procs[5].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[5].iv_masterCapable = false;     // Not master proc
        l_procs[5].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[5].iv_pOutGroupProcInfos[0] = &l_procs[1];
        l_procs[5].iv_pOutGroupProcInfos[1] = &l_procs[3];
        l_procs[5].iv_pOutGroupProcInfos[2] = &l_procs[7];
        // in-group bus links and states
        l_procs[5].iv_pInGroupProcInfos[0] = &l_procs[4];

        // Proc6:
        l_procs[6].iv_pThisProc = nullptr;          // Target *
        l_procs[6].procHUID = 6;                 // HUID
        l_procs[6].procFabricGroup = 3;          // FABRIC_GROUP_ID
        l_procs[6].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[6].iv_masterCapable = false;     // Not master proc
        l_procs[6].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[6].iv_pOutGroupProcInfos[0] = &l_procs[4];
        l_procs[6].iv_pOutGroupProcInfos[1] = &l_procs[2];
        l_procs[6].iv_pOutGroupProcInfos[2] = &l_procs[0];
        // in-group bus links and states
        l_procs[6].iv_pInGroupProcInfos[0] = &l_procs[7];
        l_procs[6].iv_InGroupLinkDeconfigured[0] = true;

        // Proc7:
        l_procs[7].iv_pThisProc = nullptr;          // Target *
        l_procs[7].procHUID = 7;                 // HUID
        l_procs[7].procFabricGroup = 3;          // FABRIC_GROUP_ID
        l_procs[7].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[7].iv_masterCapable = false;     // Not master proc
        l_procs[7].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[7].iv_pOutGroupProcInfos[0] = &l_procs[3];
        l_procs[7].iv_pOutGroupProcInfos[1] = &l_procs[1];
        l_procs[7].iv_pOutGroupProcInfos[2] = &l_procs[5];
        // in-group bus links and states
        l_procs[7].iv_pInGroupProcInfos[0] = &l_procs[6];
        l_procs[7].iv_InGroupLinkDeconfigured[0] = true;

        // Set the correct broadcast mode for a multi-group scenario, default broadcast mode is for single-group.
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE);
        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);

        // Check result
        if (l_procs[0].iv_deconfigured == false &&
            l_procs[1].iv_deconfigured == false &&
            l_procs[2].iv_deconfigured == false &&
            l_procs[3].iv_deconfigured == false &&
            l_procs[4].iv_deconfigured == true &&
            l_procs[5].iv_deconfigured == true &&
            l_procs[6].iv_deconfigured == true &&
            l_procs[7].iv_deconfigured == true)
        {
            TS_INFO("testDeconfigureAssocProc4: Success");
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
        TS_INFO("testDeconfigureAssocProc5: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: System with proc4 deconfigured (and
        // proc4's chiplets and peers deconfigured by association),
        // and proc5 out-group bus2 / proc7 out-group bus2 deconfigured.

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 8;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[0].iv_pOutGroupProcInfos[0] = &l_procs[2];
        l_procs[0].iv_pOutGroupProcInfos[1] = &l_procs[4];
        l_procs[0].iv_pOutGroupProcInfos[2] = &l_procs[6];
        l_procs[4].iv_OutGroupLinkDeconfigured[1] = true;
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = false;     // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[1].iv_pOutGroupProcInfos[0] = &l_procs[5];
        l_procs[1].iv_pOutGroupProcInfos[1] = &l_procs[7];
        l_procs[1].iv_pOutGroupProcInfos[2] = &l_procs[3];
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[0];

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[2].iv_pOutGroupProcInfos[0] = &l_procs[0];
        l_procs[2].iv_pOutGroupProcInfos[1] = &l_procs[6];
        l_procs[2].iv_pOutGroupProcInfos[2] = &l_procs[4];
        l_procs[2].iv_OutGroupLinkDeconfigured[2] = true;
        // in-group bus links and states
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[3].iv_pOutGroupProcInfos[0] = &l_procs[7];
        l_procs[3].iv_pOutGroupProcInfos[1] = &l_procs[5];
        l_procs[3].iv_pOutGroupProcInfos[2] = &l_procs[1];
        // in-group bus links and states
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[2];

        // Proc4:
        l_procs[4].iv_pThisProc = nullptr;          // Target *
        l_procs[4].procHUID = 4;                 // HUID
        l_procs[4].procFabricGroup = 2;          // FABRIC_GROUP_ID
        l_procs[4].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[4].iv_masterCapable = false;      // Master proc
        l_procs[4].iv_deconfigured = true;      // HWAS state
        // out-group bus links and states
        l_procs[4].iv_pOutGroupProcInfos[0] = &l_procs[6];
        l_procs[4].iv_pOutGroupProcInfos[1] = &l_procs[0];
        l_procs[4].iv_pOutGroupProcInfos[2] = &l_procs[2];
        l_procs[4].iv_OutGroupLinkDeconfigured[0] = true;
        l_procs[4].iv_OutGroupLinkDeconfigured[1] = true;
        l_procs[4].iv_OutGroupLinkDeconfigured[2] = true;
        // in-group bus links and states
        l_procs[4].iv_pInGroupProcInfos[0] = &l_procs[5];
        l_procs[4].iv_InGroupLinkDeconfigured[0] = true;

        // Proc5:
        l_procs[5].iv_pThisProc = nullptr;          // Target *
        l_procs[5].procHUID = 5;                 // HUID
        l_procs[5].procFabricGroup = 2;          // FABRIC_GROUP_ID
        l_procs[5].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[5].iv_masterCapable = false;     // Not master proc
        l_procs[5].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[5].iv_pOutGroupProcInfos[0] = &l_procs[1];
        l_procs[5].iv_pOutGroupProcInfos[1] = &l_procs[3];
        l_procs[5].iv_pOutGroupProcInfos[2] = &l_procs[7];
        l_procs[5].iv_OutGroupLinkDeconfigured[2] = true;
        // in-group bus links and states
        l_procs[5].iv_pInGroupProcInfos[0] = &l_procs[4];
        l_procs[5].iv_InGroupLinkDeconfigured[0] = true;

        // Proc6:
        l_procs[6].iv_pThisProc = nullptr;          // Target *
        l_procs[6].procHUID = 6;                 // HUID
        l_procs[6].procFabricGroup = 3;          // FABRIC_GROUP_ID
        l_procs[6].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[6].iv_masterCapable = false;     // Not master proc
        l_procs[6].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[6].iv_pOutGroupProcInfos[0] = &l_procs[4];
        l_procs[6].iv_pOutGroupProcInfos[1] = &l_procs[2];
        l_procs[6].iv_pOutGroupProcInfos[2] = &l_procs[0];
        l_procs[6].iv_OutGroupLinkDeconfigured[0] = true;
        // in-group bus links and states
        l_procs[6].iv_pInGroupProcInfos[0] = &l_procs[7];

        // Proc7:
        l_procs[7].iv_pThisProc = nullptr;          // Target *
        l_procs[7].procHUID = 7;                 // HUID
        l_procs[7].procFabricGroup = 3;          // FABRIC_GROUP_ID
        l_procs[7].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[7].iv_masterCapable = false;     // Not master proc
        l_procs[7].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[7].iv_pOutGroupProcInfos[0] = &l_procs[3];
        l_procs[7].iv_pOutGroupProcInfos[1] = &l_procs[1];
        l_procs[7].iv_pOutGroupProcInfos[2] = &l_procs[5];
        l_procs[7].iv_OutGroupLinkDeconfigured[2] = true;
        // in-group bus links and states
        l_procs[7].iv_pInGroupProcInfos[0] = &l_procs[6];

        // Set the correct broadcast mode for a multi-group scenario, default broadcast mode is for single-group.
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE);
        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);

        // Check result
        if (l_procs[0].iv_deconfigured == false &&
            l_procs[1].iv_deconfigured == false &&
            l_procs[2].iv_deconfigured == false &&
            l_procs[3].iv_deconfigured == false &&
            l_procs[4].iv_deconfigured == true &&
            l_procs[5].iv_deconfigured == true &&
            l_procs[6].iv_deconfigured == false &&
            l_procs[7].iv_deconfigured == false)
        {
            TS_INFO("testDeconfigureAssocProc5: Success");
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
        TS_INFO("testDeconfigureAssocProc6: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: System with proc0 in-group bus0
        // and proc1 in-group bus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];
        l_procs[0].iv_pInGroupProcInfos[1] = &l_procs[2];
        l_procs[0].iv_pInGroupProcInfos[3] = &l_procs[3];
        l_procs[0].iv_InGroupLinkDeconfigured[0] = true;

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = false;     // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[2];
        l_procs[1].iv_pInGroupProcInfos[1] = &l_procs[3];
        l_procs[1].iv_pInGroupProcInfos[3] = &l_procs[0];
        l_procs[1].iv_InGroupLinkDeconfigured[3] = true;

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];
        l_procs[2].iv_pInGroupProcInfos[1] = &l_procs[0];
        l_procs[2].iv_pInGroupProcInfos[3] = &l_procs[1];

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 3;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[0];
        l_procs[3].iv_pInGroupProcInfos[1] = &l_procs[1];
        l_procs[3].iv_pInGroupProcInfos[3] = &l_procs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_procs[0].iv_deconfigured == false &&
            l_procs[1].iv_deconfigured == true &&
            l_procs[2].iv_deconfigured == false &&
            l_procs[3].iv_deconfigured == false)
        {
            TS_INFO("testDeconfigureAssocProc6: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc6: incorrect configuration returned");
        }
    }

    /**
     *  @brief Test Deconfigure Associated Proc8
     */
    void testDeconfigureAssocProc7()
    {
        TS_INFO("testDeconfigureAssocProc7: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with master proc, proc0in-group bus0, proc1in-group bus3, proc1in-group bus0, and
        // proc2in-group bus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = true;      // HWAS state
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];
        l_procs[0].iv_pInGroupProcInfos[1] = &l_procs[2];
        l_procs[0].iv_pInGroupProcInfos[3] = &l_procs[3];
        l_procs[0].iv_InGroupLinkDeconfigured[0] = true;

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = true;      // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[2];
        l_procs[1].iv_pInGroupProcInfos[1] = &l_procs[3];
        l_procs[1].iv_pInGroupProcInfos[3] = &l_procs[0];
        l_procs[1].iv_InGroupLinkDeconfigured[0] = true;
        l_procs[1].iv_InGroupLinkDeconfigured[3] = true;

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];
        l_procs[2].iv_pInGroupProcInfos[1] = &l_procs[0];
        l_procs[2].iv_pInGroupProcInfos[3] = &l_procs[1];
        l_procs[2].iv_InGroupLinkDeconfigured[3] = true;

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 3;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[0];
        l_procs[3].iv_pInGroupProcInfos[1] = &l_procs[1];
        l_procs[3].iv_pInGroupProcInfos[3] = &l_procs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_procs[0].iv_deconfigured == true &&
            l_procs[1].iv_deconfigured == false &&
            l_procs[2].iv_deconfigured == true &&
            l_procs[3].iv_deconfigured == false)
        {
            TS_INFO("testDeconfigureAssocProc7: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc7: incorrect configuration returned");
        }

        TS_INFO("testDeconfigureAssocProc7: Ended");
    }

    /**
     *  @brief Test Deconfigure Associated Proc8
     */
    void testDeconfigureAssocProc8()
    {
        TS_INFO("testDeconfigureAssocProc8: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: System with proc2, proc3 and
        // all associated bus endpoints deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = false;      // HWAS state
        l_procs[0].iv_pOutGroupProcInfos[0] = &l_procs[2];
        l_procs[0].iv_pOutGroupProcInfos[1] = &l_procs[2];
        l_procs[0].iv_OutGroupLinkDeconfigured[0] = true;
        l_procs[0].iv_OutGroupLinkDeconfigured[1] = true;
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = false;     // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        l_procs[1].iv_pOutGroupProcInfos[0] = &l_procs[3];
        l_procs[1].iv_pOutGroupProcInfos[1] = &l_procs[3];
        l_procs[1].iv_OutGroupLinkDeconfigured[0] = true;
        l_procs[1].iv_OutGroupLinkDeconfigured[1] = true;
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[0];

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = true;      // HWAS state
        l_procs[2].iv_pOutGroupProcInfos[0] = &l_procs[0];
        l_procs[2].iv_pOutGroupProcInfos[1] = &l_procs[0];
        l_procs[2].iv_OutGroupLinkDeconfigured[0] = true;
        l_procs[2].iv_OutGroupLinkDeconfigured[1] = true;
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];
        l_procs[2].iv_InGroupLinkDeconfigured[0] = true;


        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = true;      // HWAS state
        l_procs[3].iv_pOutGroupProcInfos[0] = &l_procs[1];
        l_procs[3].iv_pOutGroupProcInfos[1] = &l_procs[2];
        l_procs[3].iv_OutGroupLinkDeconfigured[0] = true;
        l_procs[3].iv_OutGroupLinkDeconfigured[1] = true;
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[2];
        l_procs[3].iv_InGroupLinkDeconfigured[0] = true;

        // Set the correct broadcast mode for a multi-group scenario, default broadcast mode is for single-group.
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE);
        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);

        // Check result
        if (l_procs[0].iv_deconfigured == false &&
            l_procs[1].iv_deconfigured == false &&
            l_procs[2].iv_deconfigured == true &&
            l_procs[3].iv_deconfigured == true)
        {
            TS_INFO("testDeconfigureAssocProc8: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc8: incorrect configuration returned");
        }

        TS_INFO("testDeconfigureAssocProc8: Ended");
    }

    /**
     *  @brief Test Deconfigure Associated Proc9
     */
    void testDeconfigureAssocProc9()
    {
        TS_INFO("testDeconfigureAssocProc9: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: System with Proc 3 non-present which is indicated by
        // No out-group bus endpoints on Proc 1 and 3 and no in-group bus endpoint on Proc1

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[0].iv_pOutGroupProcInfos[0] = &l_procs[2];
        l_procs[0].iv_pOutGroupProcInfos[1] = &l_procs[2];
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = false;     // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[0];

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // out-group bus links and states
        l_procs[2].iv_pOutGroupProcInfos[0] = &l_procs[0];
        l_procs[2].iv_pOutGroupProcInfos[1] = &l_procs[0];
        // No in-group bus because proc3 is "not present"

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 1;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = true;      // HWAS state
        // in-group bus links still has in-group bus to proc 2 because proc 2 is functional
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[2];

        // Set the correct broadcast mode for a multi-group scenario, default broadcast mode is for single-group.
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE);
        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }
        UTIL::assertGetToplevelTarget()->setAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>(PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);

        // Check result
        if (l_procs[0].iv_deconfigured == false &&
            l_procs[1].iv_deconfigured == false &&
            l_procs[2].iv_deconfigured == true &&
            l_procs[3].iv_deconfigured == true)
        {
            TS_INFO("testDeconfigureAssocProc9: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc9: incorrect configuration returned");
        }

        TS_INFO("testDeconfigureAssocProc9: Ended");
    }

    /**
     *  @brief Test Deconfigure Associated Proc10
     */
    void testDeconfigureAssocProc10()
    {
        TS_INFO("testDeconfigureAssocProc10: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with proc0 in-group bus0 and proc1 in-group bus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];
        l_procs[0].iv_pInGroupProcInfos[1] = &l_procs[2];
        l_procs[0].iv_pInGroupProcInfos[3] = &l_procs[3];
        l_procs[0].iv_InGroupLinkDeconfigured[0] = true;

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = true;     // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[2];
        l_procs[1].iv_pInGroupProcInfos[1] = &l_procs[3];
        l_procs[1].iv_pInGroupProcInfos[3] = &l_procs[0];
        l_procs[1].iv_InGroupLinkDeconfigured[3] = true;

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];
        l_procs[2].iv_pInGroupProcInfos[1] = &l_procs[0];
        l_procs[2].iv_pInGroupProcInfos[3] = &l_procs[1];

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 3;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[0];
        l_procs[3].iv_pInGroupProcInfos[1] = &l_procs[1];
        l_procs[3].iv_pInGroupProcInfos[3] = &l_procs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_procs[0].iv_deconfigured == false &&
            l_procs[1].iv_deconfigured == true &&
            l_procs[2].iv_deconfigured == false &&
            l_procs[3].iv_deconfigured == false)
        {
            TS_INFO("testDeconfigureAssocProc10: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc10: incorrect configuration returned");
        }

        TS_INFO("testDeconfigureAssocProc10: Ended");
    }

    /**
     *  @brief Test Deconfigure Associated Proc11
     */
    void testDeconfigureAssocProc11()
    {
        TS_INFO("testDeconfigureAssocProc11: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with master proc, proc0 in-group bus0 and proc1 in-group bus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = true;      // HWAS state
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];
        l_procs[0].iv_pInGroupProcInfos[1] = &l_procs[2];
        l_procs[0].iv_pInGroupProcInfos[3] = &l_procs[3];
        l_procs[0].iv_InGroupLinkDeconfigured[0] = true;

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = true;     // Not master proc
        l_procs[1].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[2];
        l_procs[1].iv_pInGroupProcInfos[1] = &l_procs[3];
        l_procs[1].iv_pInGroupProcInfos[3] = &l_procs[0];
        l_procs[1].iv_InGroupLinkDeconfigured[3] = true;

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];
        l_procs[2].iv_pInGroupProcInfos[1] = &l_procs[0];
        l_procs[2].iv_pInGroupProcInfos[3] = &l_procs[1];

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 3;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[0];
        l_procs[3].iv_pInGroupProcInfos[1] = &l_procs[1];
        l_procs[3].iv_pInGroupProcInfos[3] = &l_procs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_procs[0].iv_deconfigured == true &&
            l_procs[1].iv_deconfigured == false &&
            l_procs[2].iv_deconfigured == false &&
            l_procs[3].iv_deconfigured == false)
        {
            TS_INFO("testDeconfigureAssocProc11: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc11: incorrect configuration returned");
        }

        TS_INFO("testDeconfigureAssocProc11: Ended");
    }

    /**
     *  @brief Test Deconfigure Associated Proc12
     */
    void testDeconfigureAssocProc12()
    {
        TS_INFO("testDeconfigureAssocProc12: Started");

        // This test populates structs which contain information
        // regarding a processor and its child chiplet's linkage
        // and states.  A vector of these structs, effectively
        // describing the system, is passed to the
        // _deconfigureAssocProc algorithm which marks procs to
        // be deconfigured based on existing bus deconfigurations.

        // SCENARIO: Single node, 2 master procs (one master, one alternate)
        // System with alt master proc, proc0 in-group bus0 and proc1 in-group bus3 deconfigured

        // Return error for _deconfigureAssocProc
        errlHndl_t l_pErr = nullptr;

        // User-defined number of procs
        size_t NUM_PROCS = 4;

        // Define and populate vector
        DeconfigGard::ProcInfoVector l_procs;
        DeconfigGard::ProcInfo l_ProcInfo = DeconfigGard::ProcInfo();
        l_procs.insert(l_procs.begin(), NUM_PROCS, l_ProcInfo);

        // Set proc options
        // Proc0:
        l_procs[0].iv_pThisProc = nullptr;          // Target *
        l_procs[0].procHUID = 0;                 // HUID
        l_procs[0].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[0].procFabricChip = 0;           // FABRIC_CHIP_ID
        l_procs[0].iv_masterCapable = true;      // Master proc
        l_procs[0].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[0].iv_pInGroupProcInfos[0] = &l_procs[1];
        l_procs[0].iv_pInGroupProcInfos[1] = &l_procs[2];
        l_procs[0].iv_pInGroupProcInfos[3] = &l_procs[3];
        l_procs[0].iv_InGroupLinkDeconfigured[0] = true;

        // Proc1:
        l_procs[1].iv_pThisProc = nullptr;          // Target *
        l_procs[1].procHUID = 1;                 // HUID
        l_procs[1].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[1].procFabricChip = 1;           // FABRIC_CHIP_ID
        l_procs[1].iv_masterCapable = true;     // Not master proc
        l_procs[1].iv_deconfigured = true;      // HWAS state
        // in-group bus links and states
        // in-group bus links and states
        l_procs[1].iv_pInGroupProcInfos[0] = &l_procs[2];
        l_procs[1].iv_pInGroupProcInfos[1] = &l_procs[3];
        l_procs[1].iv_pInGroupProcInfos[3] = &l_procs[0];
        l_procs[1].iv_InGroupLinkDeconfigured[3] = true;

        // Proc2:
        l_procs[2].iv_pThisProc = nullptr;          // Target *
        l_procs[2].procHUID = 2;                 // HUID
        l_procs[2].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[2].procFabricChip = 2;           // FABRIC_CHIP_ID
        l_procs[2].iv_masterCapable = false;     // Not master proc
        l_procs[2].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[2].iv_pInGroupProcInfos[0] = &l_procs[3];
        l_procs[2].iv_pInGroupProcInfos[1] = &l_procs[0];
        l_procs[2].iv_pInGroupProcInfos[3] = &l_procs[1];

        // Proc3:
        l_procs[3].iv_pThisProc = nullptr;          // Target *
        l_procs[3].procHUID = 3;                 // HUID
        l_procs[3].procFabricGroup = 0;          // FABRIC_GROUP_ID
        l_procs[3].procFabricChip = 3;           // FABRIC_CHIP_ID
        l_procs[3].iv_masterCapable = false;     // Not master proc
        l_procs[3].iv_deconfigured = false;      // HWAS state
        // in-group bus links and states
        l_procs[3].iv_pInGroupProcInfos[0] = &l_procs[0];
        l_procs[3].iv_pInGroupProcInfos[1] = &l_procs[1];
        l_procs[3].iv_pInGroupProcInfos[3] = &l_procs[2];

        // Call _deconfigureAssocProc to determine which procs
        // should be deconfigured based on state of system passed in
        l_pErr = DeconfigGard::_deconfigureAssocProc(l_procs);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
        }

        // Check result
        if (l_procs[0].iv_deconfigured == false &&
            l_procs[1].iv_deconfigured == true &&
            l_procs[2].iv_deconfigured == false &&
            l_procs[3].iv_deconfigured == false)
        {
            TS_INFO("testDeconfigureAssocProc12: Success");
        }
        else
        {
            TS_FAIL("testDeconfigureAssocProc12: incorrect configuration returned");
        }

        TS_INFO("testDeconfigureAssocProc12: Ended");
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

    // @brief This function is called at the beginning of the
    // runDeconfigPresentByAssocTest() test to deconfigure all PAUC chiplets and
    // their children if the test requires it.
    static void deconfigPauc()
    {
        TargetHandleList l_funcPAUCTargetList;
        getAllChiplets(l_funcPAUCTargetList, TYPE_PAUC, true);

        if (!l_funcPAUCTargetList.empty())
        {
            for (const auto l_pPauc : l_funcPAUCTargetList)
            {
                // Deconfigure the PAUC target
                TargetInfo l_paucinfo;
                l_paucinfo.pThisTarget = l_pPauc;
                l_paucinfo.affinityPath = l_pPauc->getAttr<ATTR_AFFINITY_PATH>();
                l_paucinfo.type = l_pPauc->getAttr<ATTR_TYPE>();
                l_paucinfo.reason = DeconfigGard::DECONFIGURED_BY_NO_PARENT_PAUC;
                deconfigPresentByAssoc(l_paucinfo);
            }
        }
        else
        {
            TS_FAIL("deconfigPauc: empty PAUC list");
        }
    }

    // @brief This function is called at the end of the test
    // runDeconfigPresentByAssocTest() to check that the present PAUC units
    //   are functional.
    static bool isPaucFunctional()
    {
        bool rc = true;
        TargetHandleList l_funcPAUCTargetList;
        getAllChiplets(l_funcPAUCTargetList, TYPE_PAUC, false);

        if (!l_funcPAUCTargetList.empty())
        {
            // Check whether the PAUC target is functional
            for (uint32_t l_index = 0; l_index < l_funcPAUCTargetList.size();
                l_index++)
            {
                TargetHandle_t l_pPauc = l_funcPAUCTargetList[l_index];
                if ( (!l_pPauc->getAttr<ATTR_HWAS_STATE>().functional)
                     && (l_pPauc->getAttr<ATTR_HWAS_STATE>().present) )
                {
                    TS_FAIL("isPaucFunctional: PAUC%d not functional", l_index);
                    rc = false;
                    break;
                }
            }
        }
        else
        {
            TS_FAIL("isPaucFunctional: empty PAUC list");
            rc = false;
        }
        return rc;
    }

    /* @brief Retrieve a target from affinity path.
     *
     * @param[in] i_path    Affinity path to entity from proc 0
     * @param[out] o_epath  Affinity path to entity from proc 0
     * @return Target*      Target if any at the given path, otherwise nullptr.
     */
    static Target* targetFromPath(const std::vector<entityPathComponent>& i_path,
                           EntityPath& o_epath)
    {
        o_epath = EntityPath(EntityPath::PATH_AFFINITY);
        o_epath.addLast(TYPE_SYS, 0).addLast(TYPE_NODE, 0).addLast(TYPE_PROC, 0);

        for (const auto l_component : i_path)
        {
            o_epath.addLast(l_component.targetType, l_component.instance);
        }

        return targetService().toTarget(o_epath);
    }

    /* @brief This function runs a test on presentByAssoc.
     *
     * It expects a list of entity paths and functionality expectations; it then
     * deconfigures everything in the memory hierarchy except the targets
     * mentioned in the list of paths, runs presentByAssoc, and then checks that
     * each target mentioned by the test has been deconfigured or not, as
     * specified by each element of the list.
     *
     * @param[in] i_testPaths List of entity paths to test.
     * @param[in] i_deconfigPauc Whether PAUC should be deconfigured, default is no.
     * @return bool Whether all paths were functional or not as expected.
     */
    static bool runDeconfigPresentByAssocTest(
        const std::vector<presentByAssocTestPath>& i_testPaths,
        const bool i_deconfigPauc = false
    )
    {
        bool l_success = true;

        TargetHandleList l_targets;

        // Save the HWAS state of all targets so that we can restore the system
        // state after running the test
        saveSystemState();

        // Deconfigure the PAUC if required
        if (i_deconfigPauc)
        {
            deconfigPauc();
        }

        deconfigAllMc();

        // Enable all targets listed in the test
        for (const auto& l_targetInfo : i_testPaths)
        {
            EntityPath l_entPath;
            Target* const l_targ = targetFromPath(l_targetInfo.entityPathComponents, l_entPath);

            if (!l_targ)
            {
                char* l_affinityPath = l_entPath.toString();

                TS_FAIL("runDeconfigPresentByAssocTest: "
                        "Invalid test case, target does not exist: bad entity path: %s",
                        l_affinityPath);

                free(l_affinityPath);
                l_affinityPath = nullptr;

                restoreSystemState();

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

        // Unless deconfigure PAUC has been specifically requested, PAUC should
        // be functional. This is true for all memory hierarchy deconfigs.
        if ((!i_deconfigPauc) && (!isPaucFunctional()))
        {
            l_success = false;
        }

        restoreSystemState();

        return l_success;
    }

    /**
     *  @brief Test Deconfig Present Association 1
     */
    void testdeconfigPresentByAssoc1()
    {
        TS_INFO("testdeconfigPresentByAssoc1: Started");

        // This tests the scenario where there is 1 mc, mi, omic, mcc, omi and
        // ocmb, pmic, generic_i2c_device, mem_port, and dimm

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
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
            },
            {
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
            },
            {
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
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

        TS_INFO("testdeconfigPresentByAssoc1: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 2
     */
    void testdeconfigPresentByAssoc2()
    {
        TS_INFO("testdeconfigPresentByAssoc2: Started");

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
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
        };

        if (!runDeconfigPresentByAssocTest(l_testCase))
        {
            TS_INFO("testdeconfigPresentByAssoc2: incorrect configuration returned");
        }

        TS_INFO("testdeconfigPresentByAssoc2: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 3
     */
    void testdeconfigPresentByAssoc3()
    {
        TS_INFO("testdeconfigPresentByAssoc3: Started");

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
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
            { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },

            // OMI group 1
            { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
            // No OCMB chip here
            { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
            { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
            { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
            { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
        };

        if (!runDeconfigPresentByAssocTest(l_testCase))
        {
            TS_INFO("testdeconfigPresentByAssoc3: incorrect configuration returned");
        }

        TS_INFO("testdeconfigPresentByAssoc3: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 4
     */
    void testdeconfigPresentByAssoc4()
    {
        TS_INFO("testdeconfigPresentByAssoc4: Started");

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
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // missing MEM_PORT causes deconfiguration
                { false, { TYPE_MC } },
                { false, { TYPE_MC, TYPE_MI } },
                { false, { TYPE_MC, TYPE_OMIC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                // No MEM_PORT here
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
            }
        };

        for (const auto& l_testCase : l_testCases)
        {
            if (!runDeconfigPresentByAssocTest(l_testCase))
            {
                TS_INFO("testdeconfigPresentByAssoc4: incorrect configuration returned");
            }
        }

        TS_INFO("testdeconfigPresentByAssoc4: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 5
     *  rollup testing for deconfigured pmics
     */
    void testdeconfigPresentByAssoc5()
    {
        TS_INFO("testdeconfigPresentByAssoc5: Started");

        // This tests the deconfig rule for the OCMB_CHIP parent and PMIC children.
        // If there is no OCMB_CHIP parent, we make sure everything, including the PMIC,
        // is deconfigured.
        // If there are no PMIC children, we make sure the OCMB_CHIP is deconfigured.

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
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // removing the pmic should knockout the ocmb chip, which should knockout everything else
                { false, { TYPE_MC } },
                { false, { TYPE_MC, TYPE_MI } },
                { false, { TYPE_MC, TYPE_OMIC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                // { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // remove the OCMB_CHIP and everything should go bad, including the PMIC
                { false, { TYPE_MC } },
                { false, { TYPE_MC, TYPE_MI } },
                { false, { TYPE_MC, TYPE_OMIC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                // { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
        };

        uint8_t l_caseCount = 0;
        for (const auto& l_testCase : l_testCases)
        {

            TS_INFO("testdeconfigPresentByAssoc5: Starting Test case %d", l_caseCount );
            if (!runDeconfigPresentByAssocTest(l_testCase))
            {
                TS_INFO("testdeconfigPresentByAssoc5: Incorrect configuration returned for Test case %d", l_caseCount );
            }
            else
            {
                TS_INFO("testdeconfigPresentByAssoc5: Correct configuration returned for Test case %d", l_caseCount );
            }
            l_caseCount++;
        }

        TS_INFO("testdeconfigPresentByAssoc5: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 6
     *  rollup testing for deconfigured generic i2c devices
     */
    void testdeconfigPresentByAssoc6()
    {
        TS_INFO("testdeconfigPresentByAssoc6: Started");
        // This tests the scenario where an OCMB_CHIP parent has no TYPE_GENERIC_I2C_DEVICE children,
        // the OCMB_CHIP should not be deconfigured since the presence of TYPE_GENERIC_I2C_DEVICE's
        // depends on if the system is 2U or 4U DDIMM
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
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
            { // removing the generic i2c devices shouldn't make anything bad since there is an async rule
              // for differneces between 2U and 4U DDIMMs
                { true, { TYPE_MC } },
                { true, { TYPE_MC, TYPE_MI } },
                { true, { TYPE_MC, TYPE_OMIC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                // { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
            },
        };

        uint8_t l_caseCount = 0;
        for (const auto& l_testCase : l_testCases)
        {
            TS_INFO("testdeconfigPresentByAssoc6: Starting Test case %d", l_caseCount );
            if (!runDeconfigPresentByAssocTest(l_testCase))
            {
                TS_INFO("testdeconfigPresentByAssoc6: incorrect configuration returned for Test case %d", l_caseCount );
            }
            else
            {
                TS_INFO("testdeconfigPresentByAssoc6: Correct configuration returned for Test case %d", l_caseCount );
            }
            l_caseCount++;
        }

        TS_INFO("testdeconfigPresentByAssoc6: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 7
     */
    void testdeconfigPresentByAssoc7()
    {
        TS_INFO("testdeconfigPresentByAssoc7: Started");

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
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },

                // OMI group 1
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
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
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                  // no DIMM here

                // OMI group 1
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
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

        TS_INFO("testdeconfigPresentByAssoc7: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 8
     */
    void testdeconfigPresentByAssoc8()
    {
        TS_INFO("testdeconfigPresentByAssoc8: Started");

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
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
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
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
            }
        };

        for (const auto& l_testCase : l_testCases)
        {
            if (!runDeconfigPresentByAssocTest(l_testCase))
            {
                TS_INFO("testdeconfigPresentByAssoc8: incorrect configuration returned");
            }
        }

        TS_INFO("testdeconfigPresentByAssoc8: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 9
     */
    void testdeconfigPresentByAssoc9()
    {
        TS_INFO("testdeconfigPresentByAssoc9: Started");

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
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
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
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
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
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
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
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
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
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { true, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      // missing OCMB chip here
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      // missing OCMB chip here
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
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
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { true, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
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

        TS_INFO("testdeconfigPresentByAssoc9: Exit");
    }

    /**
     *  @brief Test Deconfig Present Association 10: PAUC/OMIC rule
     */
    void testdeconfigPresentByAssoc10()
    {
        TS_INFO(INFO_MRK "testdeconfigPresentByAssoc10: Started");

        // This test creates the scenario where an OMIC has no PAUC parent.
        // It makes sure the OMIC is deconfigured.
        const std::vector<presentByAssocTestPath> l_testCase =
        {
            // A functional MC0 tree. Verify the whole tree will be
            // deconfigured because of the missing PAUC
            { false, { TYPE_MC } },
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
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC0/OMI1
                    { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC ,{TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, TYPE_MCC, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                  // MCC1
                  { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1} } },
                    // MCC1/OMI0
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, TYPE_OMI, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
                    // MCC1/OMI1
                    { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1} } },
                      { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_PMIC } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, {TYPE_PMIC, 1} } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE } },
                        { false, { TYPE_MC, TYPE_MI, {TYPE_MCC, 1}, {TYPE_OMI, 1}, TYPE_OCMB_CHIP, TYPE_MEM_PORT, TYPE_DIMM } },
        };

        // Run presentByAssoc test. deconfigPauc=true.
        if (!runDeconfigPresentByAssocTest(l_testCase, true))
        {
            TS_INFO("testdeconfigPresentByAssoc10: incorrect configuration returned");
        }

        TS_INFO(INFO_MRK "testdeconfigPresentByAssoc10: Exit");
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

        TS_INFO("testDeconfigureAssocOMI1: Started");

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
            Target* pSys = UTIL::assertGetToplevelTarget();

            PredicateCTM predMC(CLASS_UNIT, TYPE_MC);
            PredicateHwas predFunctional;
            predFunctional.poweredOn(true).present(true).functional(true);
            PredicatePostfixExpr checkExprMC;
            checkExprMC.push(&predMC).push(&predFunctional).And();

            TargetHandleList pMcList;
            targetService().getAssociated(pMcList, pSys,
                TargetService::CHILD, TargetService::ALL,
                &checkExprMC);
            TS_INFO("testDeconfigureAssocOMI1: pMcList.size()=%d", pMcList.size());
            if (pMcList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI1: empty MC list");
                break;
            }
            TargetHandle_t l_pMc = pMcList[0];
            TS_INFO("testDeconfigureAssocOMI1: Working with HUID l_pMc=0x%X", get_huid(l_pMc));

            // find all OMIC targets
            TargetHandleList l_pOmicList;
            getChildChiplets(l_pOmicList, l_pMc, TYPE_OMIC);

            TS_INFO("testDeconfigureAssocOMI1: l_pOmicList.size()=%d", l_pOmicList.size());
            if (l_pOmicList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI1: empty OMIC list");
                break;
            }

            // deconfigure all but one OMIC
            for (auto i = (l_pOmicList.size() - 1); i > 0; --i)
            {
                TargetHandle_t l_pOmic = l_pOmicList[i];
                TS_INFO("testDeconfigureAssocOMI1: Deconfiguring HUID l_pOmic=0x%X", get_huid(l_pOmic));

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
            TS_INFO("testDeconfigureAssocOMI1: Deconfiguring LAST HUID l_pLastOmic=0x%X", get_huid(l_pLastOmic));
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
        TS_INFO("testDeconfigureAssocOMI1: Ended");

#endif
    }


    /**
     *  @brief Find an MC target and deconfigure it. This should deconfig the
     *         child OMIC targets but not affect the PAUC targets.
     */
    void testDeconfigureAssocOMI2()
    {
#if ENABLE_OMI_UNIT_TEST_2
        // Save the state of the system before we make any changes.
        saveSystemState();

        TS_INFO("testDeconfigureAssocOMI2: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {
            // find an MC
            Target* pSys = UTIL::assertGetToplevelTarget();

            TargetHandleList pMcList;

            getChildAffinityTargets(pMcList, pSys, CLASS_NA ,TYPE_MC, true);

            TS_INFO("testDeconfigureAssocOMI2: pMcList.size()=%d", pMcList.size());
            if (pMcList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI2: empty MC list");
                break;
            }
            TargetHandle_t l_pMc = pMcList[0];
            TS_INFO("testDeconfigureAssocOMI2: Working with HUID l_pMc=0x%X", get_huid(l_pMc));

            // find all functional OMIC targets
            TargetHandleList l_pOmicList;
            getChildChiplets(l_pOmicList, l_pMc, TYPE_OMIC, true);

            TS_INFO("testDeconfigureAssocOMI2: l_pOmicList.size()=%d", l_pOmicList.size());
            if (l_pOmicList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI2: empty OMIC list");
                break;
            }

            // find the PAUC_PARENT for one of the OMICs
            TargetHandleList l_pPaucList;
            getParentPaucTargetsByState(
                l_pPaucList,
                l_pOmicList[0],
                TARGETING::CLASS_NA,
                TYPE_PAUC,
                TARGETING::UTIL_FILTER_ALL);
            TS_INFO("testDeconfigureAssocOMI2: l_pPaucList.size()=%d", l_pPaucList.size());
            if (l_pPaucList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI2: empty PAUC list");
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
                    TS_FAIL("testDeconfigureAssocOMI2: OMIC functional after "
                            "deconfiguring parent MC");
                    functionalOmic = true;
                    break;
                }
            }
            if (functionalOmic)
            {
                break;
            }

            // Verify the PAUC parent is not affected by OMICs becoming
            // non-functional
            uint32_t l_index = 0;
            uint32_t l_numPauc = l_pPaucList.size();
            for (; l_index < l_numPauc; l_index++)
            {
                HwasState l_state =
                    l_pPaucList[l_index]->getAttr<ATTR_HWAS_STATE>();
                if (!l_state.functional)
                {
                    TS_FAIL("testDeconfigureAssocOMI2: PAUC%d not functional "
                        "after deconfiguring all OMICS", l_index);
                    break;
                }
            }
            TS_INFO("testDeconfigureAssocOMI2: l_index=0x%X o_numPauc=0x%X", l_index, l_numPauc);
            if (l_index < l_numPauc)
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
        TS_INFO("testDeconfigureAssocOMI2: Ended");
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

        TS_INFO("testDeconfigureAssocOMI3: Started");

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

            Target* pSys = UTIL::assertGetToplevelTarget();

            // find an OMIC
            TargetHandleList l_pOmicList;
            getChildChiplets(l_pOmicList, pSys, TYPE_OMIC, true);

            TS_INFO("testDeconfigureAssocOMI3: l_pOmicList.size()=%d", l_pOmicList.size());
            if (l_pOmicList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI3: empty OMIC list");
                break;
            }

            TargetHandle_t l_pOmic = l_pOmicList[0];
            TS_INFO("testDeconfigureAssocOMI3: Working with HUID l_pOmic=0x%X", get_huid(l_pOmic));

            // find all OMI targets
            TargetHandleList l_pOmiList;

            getChildOmiTargetsByState(l_pOmiList, l_pOmic, CLASS_NA,
                                    TYPE_OMI, UTIL_FILTER_FUNCTIONAL);

            TS_INFO("testDeconfigureAssocOMI3: l_pOmiList.size()=%d", l_pOmiList.size());
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
        TS_INFO("testDeconfigureAssocOMI3: Ended");
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

        TS_INFO("testDeconfigureAssocOMI4: Started");

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

            Target* pSys = UTIL::assertGetToplevelTarget();

            // find an OMIC
            TargetHandleList l_pOmicList;
            getChildChiplets(l_pOmicList, pSys, TYPE_OMIC, true);

            TS_INFO("testDeconfigureAssocOMI4: l_pOmicList.size()=%d", l_pOmicList.size());
            if (l_pOmicList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI4: empty OMIC list");
                break;
            }

            TargetHandle_t l_pOmic = l_pOmicList[0];
            TS_INFO("testDeconfigureAssocOMI4: Working with HUID l_pOmic=0x%X", get_huid(l_pOmic));

            // find all OMI targets
            TargetHandleList l_pOmiList;
            getChildOmiTargetsByState(l_pOmiList, l_pOmic, CLASS_NA,
                                    TYPE_OMI, UTIL_FILTER_FUNCTIONAL);

            TS_INFO("testDeconfigureAssocOMI4: l_pOmiList.size()=%d", l_pOmiList.size());
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
            TS_INFO("testDeconfigureAssocOMI4: Deconfiguring LAST HUID l_pLastOmi=0x%X", get_huid(l_pLastOmi));
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
        TS_INFO("testDeconfigureAssocOMI4: Ended");

#endif
    }

    /**
     *  @brief Find a PAUC target and deconfigure it. This should deconfigure
     *         the child OMIC targets.
     */
    void testDeconfigureAssocOMI5()
    {
#if ENABLE_OMI_UNIT_TEST_5
        // Save the state of the system before we make any changes.
        saveSystemState();

        TS_INFO("testDeconfigureAssocOMI5: Started");

        errlHndl_t l_pErr = nullptr;

        do
        {
            // find a PAUC
            Target* pSys = UTIL::assertGetToplevelTarget();

            TargetHandleList pPaucList;

            getChildAffinityTargets(pPaucList, pSys, CLASS_NA ,TYPE_PAUC, true);

            TS_INFO("testDeconfigureAssocOMI5: pPaucList.size()=%d", pPaucList.size());

            if (pPaucList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI5: empty PAUC list");
                break;
            }
            TargetHandle_t l_pPauc = pPaucList[0];
            TS_INFO("testDeconfigureAssocOMI5: Working with HUID l_pPauc=0x%X", get_huid(l_pPauc));

            // find all functional PAUC_CHILD targets (OMICs)
            TargetHandleList l_pOmicList;
            getChildPaucTargetsByState(l_pOmicList, l_pPauc, CLASS_NA,
                                    TYPE_OMIC, UTIL_FILTER_FUNCTIONAL);

            TS_INFO("testDeconfigureAssocOMI5: l_pOmicList.size()=%d", l_pOmicList.size());
            if (l_pOmicList.empty())
            {
                TS_FAIL("testDeconfigureAssocOMI5: empty OMIC list");
                break;
            }

            // Deconfigure the PAUC target
            l_pErr = theDeconfigGard().deconfigureTarget(*l_pPauc, 0xA5);

            bool functionalOmic = false;
            // Check to see if the OMIC targets were deconfigured.
            for (auto l_pOmic : l_pOmicList)
            {
                HwasState l_state = l_pOmic->getAttr<ATTR_HWAS_STATE>();

                if (l_state.functional)
                {
                    TS_FAIL("testDeconfigureAssocOMI5: OMIC functional after "
                            "deconfiguring parent PAUC");
                    functionalOmic = true;
                    break;
                }
            }
            if (functionalOmic)
            {
                break;
            }
            TS_INFO(INFO_MRK "testDeconfigureAssocOMI5: Success");
        }
        while (0);

        if (l_pErr)
        {
            errlCommit(l_pErr, CXXTEST_COMP_ID);
        }

        // Restore the state of the system prior to the test
        restoreSystemState();
        TS_INFO("testDeconfigureAssocOMI5: Ended");
#endif
    }

    static void enableTarget(Target* const t)
    {
        auto hwasState = t->getAttr<ATTR_HWAS_STATE>();
        hwasState.functional = 1;
        t->setAttr<ATTR_HWAS_STATE>(hwasState);
    }

    static void disableTarget(Target* const t)
    {
        auto hwasState = t->getAttr<ATTR_HWAS_STATE>();
        hwasState.functional = 0;
        t->setAttr<ATTR_HWAS_STATE>(hwasState);
    }

    static bool isFunctional(Target* const t)
    {
        return t->getAttr<ATTR_HWAS_STATE>().functional;
    }

    /* @brief Test deconfiguring related IOHS and PAU targets
     */
    void testIohsPauDeconfigureRule()
    {
        TS_INFO(">testIohsPauDeconfigureRule");

        // Grab some entities to work with.

        EntityPath epath;
        Target
            * const pauc  = targetFromPath({ { TYPE_PAUC, 2}                   }, epath),
            * const iohs0 = targetFromPath({ { TYPE_PAUC, 2}, { TYPE_IOHS, 0 } }, epath),
            * const iohs1 = targetFromPath({ { TYPE_PAUC, 2}, { TYPE_IOHS, 1 } }, epath),
            * const pau0  = targetFromPath({ { TYPE_PAUC, 2}, { TYPE_PAU,  0 } }, epath),
            * const pau1  = targetFromPath({ { TYPE_PAUC, 2}, { TYPE_PAU,  1 } }, epath);

        // Save to restore later
        const auto oldMapping = iohs0->getAttr<ATTR_IOHS_PHY_TO_PAU_MAPPING>();

        saveSystemState();

        do
        {

        // Ensure that the targets we are using have the expected IOHS_CONFIG_MODE

        if (iohs0->getAttr<ATTR_IOHS_CONFIG_MODE>() != IOHS_CONFIG_MODE_OCAPI)
        {
            TS_FAIL("testIohsPauDeconfigureRule: Expected IOHS 0x%08x to be in OCAPI mode",
                    get_huid(iohs0));
            break;
        }

        if (iohs1->getAttr<ATTR_IOHS_CONFIG_MODE>() == IOHS_CONFIG_MODE_OCAPI)
        {
            TS_FAIL("testIohsPauDeconfigureRule: Expected IOHS 0x%08x NOT to be in OCAPI mode",
                    get_huid(iohs1));
            break;
        }

        // Enable the targets we're working with, don't care what their state
        // was before since we're not using them for anything other than deconfigure.
        for (auto target : { pauc, iohs0, iohs1, pau0, pau1 })
        {
            enableTarget(target);
        }

        // Structure for our testcases
        struct deconfiguration
        {
            bool pau0good, pau1good;
            bool iohs0good, iohs1good;
            ATTR_IOHS_PHY_TO_PAU_MAPPING_type iohs0mapping;
        };

        // constants for the testcases
        const bool BAD = false, GOOD = true;
        const ATTR_IOHS_PHY_TO_PAU_MAPPING_type INVALID = 0xFF;

        // We're going to map IOHS 0 to PAU 1
        const auto pau1unit = pau1->getAttr<ATTR_CHIP_UNIT>();

        const deconfiguration testcases[] =
        {
         // Legend:
         // { PAU0 , PAU1 , IOHS0 , IOHS1 , mapping }

         // Test without a PAU mapping (i.e. pre-istep10 deconfigure)
            { GOOD , GOOD , GOOD  , GOOD  , INVALID },
            { BAD  , GOOD , GOOD  , GOOD  , INVALID },
            { GOOD , BAD  , GOOD  , GOOD  , INVALID },
            { BAD  , BAD  , BAD   , GOOD  , INVALID },

         // Test with a PAU mapping (i.e. post-istep10 deconfigure)
            { GOOD , GOOD , GOOD  , GOOD  , pau1unit },
            { BAD  , GOOD , GOOD  , GOOD  , pau1unit },
            { GOOD , BAD  , BAD   , GOOD  , pau1unit },
            { BAD  , BAD  , BAD   , GOOD  , pau1unit },
        };

        // Iterate our list of testcases; deconfigure PAU0 and 1 as needed, and
        // then check that IOHS0 and 1 are deconfigured if/as appropriate.
        size_t test_index = 0;
        for (const auto& testcase : testcases)
        {
            TS_INFO("testIohsPauDeconfigureRule: Running test index %lu", test_index);

            iohs0->setAttr<ATTR_IOHS_PHY_TO_PAU_MAPPING>(testcase.iohs0mapping);

            if (!testcase.pau0good) theDeconfigGard().deconfigureTarget(*pau0, 0);
            if (!testcase.pau1good) theDeconfigGard().deconfigureTarget(*pau1, 0);

            if (isFunctional(iohs0) != testcase.iohs0good)
            {
                TS_FAIL("testIohsPauDeconfigureRule: IOHS0 (0x%08x) is%s functional "
                        "in testcase index %lu, expected the opposite",
                        get_huid(iohs0),
                        isFunctional(iohs0) ? "" : " not",
                        test_index);
            }

            if (isFunctional(iohs1) != testcase.iohs1good)
            {
                TS_FAIL("testIohsPauDeconfigureRule: IOHS1 (0x%08x) is%s functional "
                        "in testcase index %lu, expected the opposite",
                        get_huid(iohs1),
                        isFunctional(iohs1) ? "" : " not",
                        test_index);
            }

            // Reset all functional states for the next test
            restoreSystemState();

            ++test_index;
        }

        } while (0);

        // Restore the state that we modified

        restoreSystemState();

        iohs0->setAttr<ATTR_IOHS_PHY_TO_PAU_MAPPING>(oldMapping);

        TS_INFO("<testIohsPauDeconfigureRule");
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
        TS_INFO("testHWASNMMU1DeconfigByPAU: Started");

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

        TS_INFO("testHWASNMMU1DeconfigByPAU: Ended");
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
        TS_INFO("testDeconfigureNMMU1ByPAU: Started");

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

                TS_INFO("testDeconfigureNMMU1ByPAU: Disabling PAUs with mask 0x%02x "
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
        TS_INFO("testDeconfigureNMMU1ByPAU: Ended");
    }

    /**
     *  @brief Test that deconfiguration updates HWAS functional state and
     *  ATTR_PG separately
     */
    void testDeconfigureMask()
    {
        TS_INFO("testDeconfigureMask: Started");

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
                                       // updateAttrPG ourselves
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
                    TS_INFO("testDeconfigureMask: NO l_target, CONTINUE");
                    continue;
                }

                const char* const l_targetType = l_target->getAttrAsString<ATTR_TYPE>();
                const auto l_huid = get_huid(l_target);
                TS_INFO("testDeconfigureMask: Working with HUID=0x%X l_targetType=%s",
                    l_huid, l_targetType);

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
                        TS_INFO("testDeconfigureMask: calling deconfigureTarget HUID=0x%X GARDABLE TYPE=0x%X",
                            get_huid(l_target), l_testcase.targetType);
                        theDeconfigGard().deconfigureTarget(*l_target, 0);
                    }
                    else
                    {
                        // Setting HWAS state to non-functional
                        ATTR_HWAS_STATE_type l_hwasState
                            = l_target->getAttr<ATTR_HWAS_STATE>();
                        TS_INFO("testDeconfigureMask: setting l_hwasState non-functional for HUID=0x%X TYPE=0x%X",
                            get_huid(l_target), l_testcase.targetType);
                        l_hwasState.functional = false;
                        l_target->setAttr<ATTR_HWAS_STATE>(l_hwasState);
                        // Setting ATTR_PG to not-functional
                        updateAttrPG(*l_target, false);
                        TS_INFO("testDeconfigureMask: SET PG non-functional for HUID=0x%X",
                            get_huid(l_target));

                        // Check that ATTR_PG was deconfig
                        // by making sure that the deconfigured target has the
                        // right ATTR_PG bits set
                        TS_INFO("testDeconfigureMask: ATTR_PG 0x%08X expect 0x%08X",
                            l_perv->getAttr<ATTR_PG>(), l_testcase.attrPgBits);
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

                    }
                }
                else
                {
                    TS_INFO("ELSE testDeconfigureMask: NOT FUNC for HUID=0x%X TYPE=0x%X",
                        get_huid(l_target), l_testcase.targetType);

                }

                // Check that HWAS functional state was deconfig
                // (Only check if the part is functional if it is present)
                if (l_target->getAttr<ATTR_HWAS_STATE>().present &&
                    l_target->getAttr<ATTR_HWAS_STATE>().functional)
                {
                    TS_FAIL("testDeconfigureMask: Failed to deconfigure %s target 0x %08x",
                            l_target->getAttrAsString<ATTR_TYPE>(), l_huid);
                    restoreSystemState();
                    continue;
                }

                restoreSystemState();
            }
        }
        for (Target* const l_proc : l_procList)
        {
            for (const auto& l_testcase : testcases)
            {
                TS_INFO("testDeconfigureMask calling getAnyTargetByType loop");
                Target* const l_target = getAnyTargetByType(*l_proc,
                                                            l_testcase.targetType,
                                                            l_testcase.chipletID);
                TS_INFO("testDeconfigureMask back l_target=0x%X calling getAnyTargetByType loop", get_huid(l_target));
            }
        }
        TS_INFO("testDeconfigureMask: Ended");
    }

    /**
     *  @brief Test CDM_DOMAIN set
     */
    void testCdmDomainSet()
    {
        TS_INFO("testCdmDomainSet: Started");

        ATTR_DECONFIG_GARDABLE_type l_gardable = 0;
        ATTR_CDM_DOMAIN_type l_cdmDomain = CDM_DOMAIN_INVALID;
        ATTR_TYPE_type l_type = TYPE_NA;

        // Go through all targets to ensure CDM_DOMAIN is set correctly
        for (TargetIterator t_iter = targetService().begin();
             t_iter != targetService().end();
             ++t_iter)
        {
            Target* l_pTarget = *t_iter;

            if (l_pTarget->tryGetAttr<ATTR_DECONFIG_GARDABLE>(l_gardable))
            {
                // If DECONFIG_GARDABLE is set, then a valid CDM_DOMAIN is needed
                if (l_gardable)
                {
                    l_type = l_pTarget->getAttr<ATTR_TYPE>();
                    if (!l_pTarget->tryGetAttr<ATTR_CDM_DOMAIN>(l_cdmDomain))
                    {
                        TS_FAIL("testCdmDomainSet: Target 0x%08X of type %d needs CDM_DOMAIN",
                            get_huid(l_pTarget), l_type);
                    }
                    else if ((l_cdmDomain == CDM_DOMAIN_INVALID) ||
                             (l_cdmDomain == CDM_DOMAIN_NONE))
                    {
                        TS_FAIL("testCdmDomainSet: Invalid domain %d for target 0x%08X type %d",
                            l_cdmDomain, get_huid(l_pTarget), l_type);
                    }
                }
            }
        } // for
        TS_INFO("testCdmDomainSet: Ended");
    }
};

#undef DISABLE_UNIT_TESTS
#undef DISABLE_MBA_UNIT_TESTS
#undef DISABLE_MEM_UNIT_TESTS
#undef DISABLE_FC_UNIT_TESTS
#undef DISABLE_FC_CRASH_UNIT_TESTS
#undef DISABLE_OMI_UNIT_TESTS
#undef DISABLE_VERS_UNIT_TESTS

#undef ENABLE_OMI_UNIT_TEST_1
#undef ENABLE_OMI_UNIT_TEST_2
#undef ENABLE_OMI_UNIT_TEST_3
#undef ENABLE_OMI_UNIT_TEST_4

#endif
