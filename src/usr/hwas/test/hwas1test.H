/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/hwas1test.H $                               */
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
#ifndef __TESTTARGETING_H
#define __TESTTARGETING_H

/**
 *  @file testtargeting.H
 *
 *  @brief Unit tests for HWAS
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <sys/time.h>

// CXXTEST
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

using PARTIAL_GOOD::pg_entry_t;
using PARTIAL_GOOD::pg_mask_t;
using PARTIAL_GOOD::cu_mask_t;
using PARTIAL_GOOD::cu_mask;

using namespace HWAS;
using namespace TARGETING;

// These constants are used in the arrays below to define testcases.
const pg_mask_t NO_ALWAYS_GOOD_BITS = 0;
const pg_idx_t USE_CHIP_UNIT = 0xFE;
const pg_idx_t USE_CHIPLET_ID = 0xFF;
const cu_mask_t ALL_CHIP_UNITS = 0;

// This structure is used to hold test cases for each target type that has PG
// bits.
struct pg_test_info
{
    ATTR_TYPE_type target_type; // Type of targets this test applies to
    pg_mask_t pg_idx;           // Use this number to index PGV (can be
                                // USE_CHIPLET_ID or USE_CHIP_UNIT)
    pg_mask_t bad_bits;         // Bits to set in the specified PG entry
};

// The list of test cases for targets that immediately go bad when PG bits are
// set (i.e. because of a PG rule, without upward or downward status
// propagation). (Not a std::array because we want size deduction)
const pg_test_info simple_pg_tests[] =
{
    { TYPE_CORE,           // This rule applies to all CORE targets
      USE_CHIPLET_ID,      // Use the chiplet's ID for indexing into PG data
      // Set the bits in the entry that correspond to the CORE PG info
      ~(VPD_CP00_PG_EQ_ALL_GOOD | VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK)
    },

    { TYPE_PEC,  USE_CHIPLET_ID, ~VPD_CP00_PG_PCI_ALL_GOOD },
    { TYPE_PERV, USE_CHIP_UNIT,  VPD_CP00_PG_PERV_BIT },
    { TYPE_MC,   USE_CHIPLET_ID, ~VPD_CP00_PG_MC_ALL_GOOD },
    { TYPE_PAU,  USE_CHIPLET_ID, ~VPD_CP00_PG_PAUC_SW_NW_ALL_GOOD },
    { TYPE_IOHS, USE_CHIPLET_ID, ~VPD_CP00_PG_IOHS_ALL_GOOD }

};

// This structure is used to hold test cases when the test suite checks that,
// from a parent's perspective, errors in itself propagate to at least one
// child.
struct parent_target_info
{
    ATTR_TYPE_type target_type; // Type of targets this test applies to
    pg_mask_t pg_idx;           // Use this number to index PGV (can be
                                // USE_CHIPLET_ID)
    pg_mask_t always_good_mask; // Avoid setting these bits because they're
                                // already checked in the test for
                                // isChipFunctional
    cu_mask_t all_bad_cu_mask;  // Disable/enable all-bad test for certain chip
                                // units (0 = enabled, 1 = disabled)
};

// The list of test cases for targets that have both PG bits and children which
// need to go bad when their parent PG bits go bad. (Not an std::array so that
// we get size deduction). Only targets with PG bits for PARTIAL-GOOD children
// should go in this array.
const parent_target_info targets_with_children[] =
{
    { TYPE_EQ,
      USE_CHIPLET_ID,
      VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK,
      ALL_CHIP_UNITS
    },
};

const pg_idx_t USE_PARENT_CHIPLET_ID = 0xFF;

// This structure is used to hold test cases when the test suite checks that,
// from the child's perspective, when their parent goes bad, the bad state
// propagates to themselves go bad.
struct child_target_info
{
    ATTR_TYPE_type target_type; // Type of target this rule applies to
    ATTR_TYPE_type parent_type; // Type of the target whose PGV has the PG bits
                                // for the target of this test
    pg_idx_t parent_pg_idx;     // Use this number to index PGV (can be
                                // USE_PARENT_CHIPLET_ID)
    pg_entry_t parent_pg_entry_bits_to_set; // Set these bits in the parent's PG
                                            // entry to cause it to go bad
};

// For targets that need to go bad when their parents go bad because of their
// parent's PG bits (this is not an std::array so that we get size
// deduction). No children of ALWAYS-GOOD parents should go in this array.
const child_target_info targets_with_parents[] =
{
    // PHB are children of PEC units (which represent PCI units)
    { TYPE_PHB,              // Rule applies to CORE targets
      TYPE_PEC,              // The PG ancestor of a PHB is a PEC
      USE_PARENT_CHIPLET_ID, // Use our parent EQ chiplet's ID to set bad bits in
                             // the PGV

      // Cause the parent to go bad by setting bits in the parent PEC's
      // PGV entry that will make it go bad
      ~VPD_CP00_PG_PCI_ALL_GOOD },

    { TYPE_DIMM,      TYPE_MC,   USE_PARENT_CHIPLET_ID, ~VPD_CP00_PG_MC_ALL_GOOD },
    { TYPE_MEM_PORT,  TYPE_MC,   USE_PARENT_CHIPLET_ID, ~VPD_CP00_PG_MC_ALL_GOOD },
    { TYPE_OCMB_CHIP, TYPE_MC,   USE_PARENT_CHIPLET_ID, ~VPD_CP00_PG_MC_ALL_GOOD },
    { TYPE_OMI,       TYPE_MC,   USE_PARENT_CHIPLET_ID, ~VPD_CP00_PG_MC_ALL_GOOD },
    { TYPE_MCC,       TYPE_MC,   USE_PARENT_CHIPLET_ID, ~VPD_CP00_PG_MC_ALL_GOOD },
};

// Look up an entry in one of the arrays above with the given target type.
template<typename T, size_t Size>
static const T* lookup_target_info(T(&array)[Size], const ATTR_TYPE_type type)
{
    const auto end = array + Size;
    const auto it = std::find_if(array, end,
                                 [type](const T& info) {
                                     return info.target_type == type;
                                 });

    if (it != end)
    {
        return it;
    }

    return nullptr;
}

class HWAS1test: public CxxTest::TestSuite
{
private:
    bool checkPartialGoodForDescendants(
            const TARGETING::TargetHandle_t &i_pTarget,
            const partialGoodVector& i_pgData)
    {
        bool result = true;

        // Call the partial good algorithm and pass in testcase appropriate
        // parameters.
        const bool CHIP_IS_FUNCTIONAL = true;
        const uint32_t NO_ERROR_ID = 0;
        errlHndl_t NO_INFO_ERRL = nullptr;
        bool DO_NOT_CREATE_INFO_LOG = false;
        const bool RUN_IN_TESTCASE_MODE = true;

        (void)HWAS::checkPartialGoodForDescendants(i_pTarget,
                                             i_pgData,
                                             CHIP_IS_FUNCTIONAL,
                                             NO_ERROR_ID,
                                             NO_INFO_ERRL,
                                             &DO_NOT_CREATE_INFO_LOG,
                                             RUN_IN_TESTCASE_MODE,
                                             &result);

        return result;
    }

    bool checkPropagationOfBadState(
            const char* const i_callerName,
            const TARGETING::TargetHandle_t &i_pParent,
            const TARGETING::TargetHandle_t &i_pChild,
            const partialGoodVector& i_pgData)

    {
        HWAS::pgState_map targetStates;

        // Since isDescFunctional propagates non-functional
        // parent state down to child state and it doesn't
        // consider parent state when checking a given
        // target, if we check this target directly it will
        // return true.
        if (!HWAS::isDescFunctional(i_pChild, i_pgData, targetStates))
        {
            TS_FAIL("checkPropagationOfBadState (%s)> "
                    "i_pChild HUID 0x %08x "
                    "should be true",
                    i_callerName,
                    get_huid(i_pChild));
        }

        // Now check the parent and mark it good or bad
        HWAS::isDescFunctional(i_pParent, i_pgData, targetStates);

        // Now we propagate the non-functional state of the parent to the child.
        // If this function is working correctly, then the child will now be
        // non-functional.
        HWAS::markChildrenNonFunctional(i_pParent, targetStates);

        // Return the child's functional state.
        return targetStates[i_pChild];
    }


public:


    /**
     * @brief   Write to all the attributes and then read them back.
     */
    void    testHWASReadWrite()
    {
        using namespace TARGETING;

        TARGETING::HwasState    l_orgHwasState, l_hwasState;
        TARGETING::TargetIterator l_pTarget;

        TS_INFO( "testHWASReadWrite entry" );

        //  write a pattern to all HWAS attributes and then read them back
        for(    l_pTarget = TARGETING::targetService().begin();
                l_pTarget != TARGETING::targetService().end();
                ++l_pTarget
                )
        {
            //  save original state
            l_orgHwasState  =   l_pTarget->getAttr<ATTR_HWAS_STATE>();

            //  modify state
            l_hwasState     =   l_pTarget->getAttr<ATTR_HWAS_STATE>();
            l_hwasState.deconfiguredByEid     =   0x12345678;
            l_hwasState.poweredOn             =   true;
            l_hwasState.present               =   true;
            l_hwasState.functional            =   true;

            //  Now write the modified value back to Targeting.
            l_pTarget->setAttr<ATTR_HWAS_STATE>( l_hwasState );

            // fetch and test new values
            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().deconfiguredByEid
                                != 0x12345678 )
            {
                TS_FAIL( " deconfiguredByEid = 0x%x, should be 0x12345678",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().
                                deconfiguredByEid );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn != true )
            {
                TS_FAIL( "poweredOn = 0x%x, should be true",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().present != true )
            {
                TS_FAIL( " present   = 0x%x should be true",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().present   );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().functional != true )
            {
                TS_FAIL( " functional = 0x%x, should be true",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().functional );
            }

            //
            //  Now write the original value back.
            //
            l_pTarget->setAttr<ATTR_HWAS_STATE>( l_orgHwasState );

            // check that it got written back correctly
            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn
                    != l_orgHwasState.poweredOn )
            {
                TS_FAIL( "poweredOn = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().present
                    != l_orgHwasState.present )
            {
                TS_FAIL( " present   = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().present   );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().functional
                    != l_orgHwasState.functional )
            {
                TS_FAIL( " functional = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().functional );
            }

        }

        TS_INFO( "testHWASReadWrite exit" );
    }

    /**
     * @brief   test platReadIDEC
     */
    void testHWASplatReadIDEC()
    {
        using namespace TARGETING;

        TS_INFO( "testHWASplatReadIDEC entry" );

        // call platReadIDEC with target that doesn't have an ID/EC
        errlHndl_t l_errl;

        Target* pSys;
        targetService().getTopLevelTarget(pSys);

        l_errl = HWAS::platReadIDEC(pSys);

        if (l_errl)
        {
            // error log is expected case, delete it
            delete l_errl;
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("testHWASplatReadIDEC>"
                    "No error from platReadIDEC(pSys).");
        }

        TS_INFO( "testHWASplatReadIDEC exit" );
    }

    /**
     * @brief   test platReadPartialGood
     */
    void testHWASplatReadPartialGood()
    {
        using namespace TARGETING;

        TS_INFO( "testHWASplatReadPartialGood entry" );

        // call platReadPartialGood with target that isn't in the VPD
        errlHndl_t l_errl;

        Target* pSys;
        targetService().getTopLevelTarget(pSys);
        uint8_t pgData[HWAS::VPD_CP00_PG_DATA_LENGTH];

        l_errl = HWAS::platReadPartialGood(pSys, pgData);

        if (l_errl)
        {
            // error log is expected case, delete it
            delete l_errl;
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("testHWASplatReadPartialGood>"
                    "No error from platReadPartialGood(pSys).");
        }

        TS_INFO( "testHWASplatReadPartialGood exit" );
    }

    /**
     * @brief   test isChipFunctional
     */
    void testHWASisChipFunctional()
    {
        /* This test ensures that if any bit in any of the targets REQUIRED for
         * a chip to be considered minimally functional goes bad, then the
         * entire chip is considered non-functional (i.e. isChipFunctional
         * evaluates to false). It also tests that if a partial-good bit is set
         * in one of these targets, then the chip is still considered
         * functional. */

        using namespace HWAS;
        using namespace TARGETING;

        TS_INFO( "testHWASisChipFunctional entry" );

        // Get list of all targets with type PROC
        TargetHandleList allProcs;
        getAllChips( allProcs, TYPE_PROC, false );

        for (TargetHandleList::const_iterator pTarget_it = allProcs.begin();
             pTarget_it != allProcs.end();
             ++pTarget_it
            )
        {
            const TargetHandle_t pTarget = *pTarget_it;

            TS_INFO( "testHWASisChipFunctional: chip is functional");
            if (!isChipFunctional(pTarget, pgDataAllGood))
            {
                TS_FAIL("testHWASisChipFunctional>functional = false, should be true.");
            }

            // This loop will iterate the bits of every chiplet that is
            // always-good (i.e. necessary for a chip to be considered even
            // minimally functional) and set it to BAD, to ensure that
            // isChipFunctional considers the entire chip to be bad.
            for (size_t i = 0; i < ALWAYS_GOOD_INDEX_SIZE; ++i)
            {
                const auto l_pgIndex = VPD_CP00_PG_ALWAYS_GOOD_INDEX[i];
                const auto l_alwaysGoodMask = VPD_CP00_PG_ALWAYS_GOOD_MASKS[i];

                const pg_entry_t original_entry = pgDataAllGood[l_pgIndex];

                TS_INFO("testHWASisChipFunctional [non-]functionality check");

                // The pgdata we will be modifying
                partialGoodVector bad_pgData = pgDataAllGood;

                // Iterate with a mask over every bit of the pg entry of this unit
                for (pg_mask_t l_mask = 1 << (sizeof(pg_mask_t) * 8 - 1);
                     l_mask != 0;
                     l_mask >>= 1)
                {
                    // If this bit is set in the always-good mask, then make
                    // sure the chip is non-functional when it's off. If it's
                    // NOT set (i.e. GOOD) in the original entry but not in the
                    // always-good mask, then we ensure that the chip is
                    // functional when it's off.
                    if (l_alwaysGoodMask & l_mask || !(original_entry & l_mask))
                    {
                        const bool l_shouldChipBeFunctional = !(l_alwaysGoodMask & l_mask);

                        const pg_entry_t l_newEntry = original_entry | l_mask;

                        bad_pgData[l_pgIndex] = l_newEntry;

                        if (isChipFunctional(pTarget, bad_pgData)
                            != l_shouldChipBeFunctional)
                        {
                            TS_FAIL("testHWASisChipFunctional>"
                                    "functional [%d] = %d, should be %d, "
                                    "testentry = 0x%08x, mask = 0x%08x, "
                                    "original = 0x%08x, "
                                    "HUID = 0x %08x",
                                    i,
                                    !l_shouldChipBeFunctional,
                                    l_shouldChipBeFunctional,
                                    l_newEntry, l_mask, original_entry,
                                    get_huid(pTarget));
                        }
                    }
                }
            }
        }

        TS_INFO( "testHWASisChipFunctional exit" );
    }

    /**
     * @brief Test getParentIohsTargetsByState/getChildPauTargetsByState
     */
    void testIohsPauRelationshipAccessors()
    {
        TS_INFO(">testIohsPauRelationshipAccessors");

        TargetHandleList paucs;
        getAllChiplets(paucs, TYPE_PAUC, false);

        for (const auto pauc : paucs)
        {
            TargetHandleList iohslist,
                             paulist;
            getChildAffinityTargetsByState(iohslist, pauc, CLASS_NA, TYPE_IOHS, UTIL_FILTER_ALL);

            if (iohslist.empty())
            {
                TS_INFO("testIohsPauRelationshipAccessors: PAUC 0x%08x has no child IOHS targets",
                        get_huid(pauc));
            }

            for (const auto iohs : iohslist)
            {
                if (iohs->getAttr<ATTR_IOHS_CONFIG_MODE>() == IOHS_CONFIG_MODE_OCAPI)
                {
                    TargetHandleList childpau;
                    getChildPauTargetsByState(childpau, iohs, CLASS_NA, TYPE_PAU, UTIL_FILTER_ALL);

                    if (childpau.size() > 1)
                    {
                        TS_FAIL("testIohsPauRelationshipAccessors: IOHS 0x%08x has multiple PAU children",
                                get_huid(iohs));
                    }
                    else if (childpau.size() == 1)
                    {
                        TargetHandleList pauParent;
                        getParentIohsTargetsByState(pauParent, childpau[0], CLASS_NA, TYPE_IOHS, UTIL_FILTER_ALL);

                        if (pauParent.size() > 1)
                        {
                            TS_FAIL("testIohsPauRelationshipAccessors: IOHS 0x%08x's child PAU has multiple IOHS parents",
                                    get_huid(iohs));
                        } else if (pauParent[0] != iohs)
                        {
                            TS_FAIL("testIohsPauRelationshipAccessors: IOHS 0x%08x with child PAU 0x%08x "
                                    "isn't that PAU's parent (is 0x%008x)",
                                    get_huid(iohs),
                                    get_huid(childpau[0]),
                                    get_huid(pauParent[0]));
                        }
                    }
                }
            }
        }

        TS_INFO("<testIohsPauRelationshipAccessors");
    }

    /**
     * @brief   Test whether targets with PG bits go bad when the PG bits go bad
     */
    void testHWAScheckBasicPGFunctionality()
    {
        TargetHandleList pCheckPres;
        getAllChips( pCheckPres, TYPE_PROC, true );

        TS_INFO( "%s() entry", __func__);

        for (TargetHandleList::const_iterator pTarget_it = pCheckPres.begin();
             pTarget_it != pCheckPres.end();
             ++pTarget_it
            )
        {
            TargetHandle_t pTarget = *pTarget_it;

            TargetHandleList pDescList;
            targetService().getAssociated( pDescList, pTarget,
                TargetService::CHILD, TargetService::ALL);

            for (TargetHandleList::const_iterator pDesc_it = pDescList.begin();
                    pDesc_it != pDescList.end();
                    ++pDesc_it)
            {
                const TargetHandle_t pDesc = *pDesc_it;
                const ATTR_TYPE_type l_type = pDesc->getAttr<ATTR_TYPE>();
                const ATTR_CHIPLET_ID_type l_chipletID
                    = pDesc->getAttr<ATTR_CHIPLET_ID>();
                const ATTR_CHIP_UNIT_type l_chipUnit
                    = pDesc->getAttr<ATTR_CHIP_UNIT>();

                const auto l_targetInfo
                    = lookup_target_info(simple_pg_tests, l_type);

                if (!l_targetInfo)
                {
                    continue;
                }

                const char* const l_type_str = attrToString<ATTR_TYPE>(l_type);

                TS_INFO("testHWAScheckBasicPGFunctionality: "
                        "Bad PG data (%s) - "
                        "attr type 0x%08X, chip unit %d, "
                        "HUID 0x %08X",
                        l_type_str, l_type, l_chipUnit, get_huid(pDesc));

                {
                    HWAS::pgState_map targetStates;

                    if (!isDescFunctional(pDesc, pgDataAllGood, targetStates))
                    {
                        TS_FAIL("testHWAScheckBasicPGFunctionality>"
                                "functional = false, should be true, "
                                "type = %s, chip unit = %d, chiplet ID = 0x%02x. "
                                "pDesc HUID 0x %08x",
                                l_type_str,
                                l_chipUnit,
                                l_chipletID,
                                get_huid(pDesc));
                    }
                }

                if (l_targetInfo)
                {
                    HWAS::pgState_map targetStates;
                    auto bad_pgData = pgDataAllGood;

                    pg_entry_t l_pgIdx = 0;

                    switch (l_targetInfo->pg_idx) {
                    case USE_CHIPLET_ID:
                        l_pgIdx = l_chipletID;
                        break;
                    case USE_CHIP_UNIT:
                        l_pgIdx = l_chipUnit;
                        break;
                    default:
                        l_pgIdx = l_targetInfo->pg_idx;
                        break;
                    }

                    bad_pgData[l_pgIdx] |= l_targetInfo->bad_bits;

                    if (isDescFunctional(pDesc, bad_pgData, targetStates))
                    {
                        TS_FAIL("testHWAScheckBasicPGFunctionality>"
                                "functional = true, should be false, "
                                "[0x%02x] = 0x %08x, pDesc HUID 0x %08x",
                                l_pgIdx,
                                bad_pgData[l_pgIdx],
                                get_huid(pDesc));
                    }
                }
            } // for pDesc_it
        }

        TS_INFO( "%s exit", __func__ );
    }

    /**
     * @brief   test isDescFunctional
     */
    void testHWAScheckPartialGoodForDescendants()
    {
        /* This test checks that whenever a bit in a target with children is
         * marked as BAD, then at least one child of the target is also marked
         * bad. */

        // Get list of present targets with type PROC
        TargetHandleList pCheckPres;
        getAllChips( pCheckPres, TYPE_PROC, true );

        TS_INFO( "testHWAScheckPartialGoodForDescendants() entry");

        for (TargetHandleList::const_iterator pTarget_it = pCheckPres.begin();
             pTarget_it != pCheckPres.end();
             ++pTarget_it
            )
        {
            TargetHandle_t pTarget = *pTarget_it;

            TargetHandleList pDescList;
            targetService().getAssociated( pDescList, pTarget,
                TargetService::CHILD, TargetService::ALL);

            for (TargetHandleList::const_iterator pDesc_it = pDescList.begin();
                    pDesc_it != pDescList.end();
                    ++pDesc_it)
            {
                const TargetHandle_t pDesc = *pDesc_it;
                const ATTR_TYPE_type l_type = pDesc->getAttr<ATTR_TYPE>();
                const ATTR_CHIPLET_ID_type l_chipletID = pDesc->getAttr<ATTR_CHIPLET_ID>();
                const ATTR_CHIP_UNIT_type l_chipUnit = pDesc->getAttr<ATTR_CHIP_UNIT>();

                const auto l_targetInfo
                    = lookup_target_info(targets_with_children, l_type);

                pg_entry_t l_pgIdx = 0;

                if (l_targetInfo)
                {
                    switch (l_targetInfo->pg_idx) {
                    case USE_CHIPLET_ID:
                        l_pgIdx = l_chipletID;
                        break;
                    case USE_CHIP_UNIT:
                        l_pgIdx = l_chipUnit;
                        break;
                    default:
                        l_pgIdx = l_targetInfo->pg_idx;
                        break;
                    }
                }

                const char* const l_type_str = attrToString<ATTR_TYPE>(l_type);

                TS_INFO("testHWAScheckPartialGoodForDescendants: "
                        "descendant functional (%s) - "
                        "attr type 0x%08X, chip unit %d, "
                        "HUID 0x %08X",
                        l_type_str, l_type, l_chipUnit, get_huid(pDesc));

                if (!checkPartialGoodForDescendants(pDesc, pgDataAllGood))
                {
                    char l_pgDataStr[32] = { };

                    if (l_targetInfo)
                    {
                        sprintf(l_pgDataStr, ", pgData = 0x%08x", pgDataAllGood[l_pgIdx]);
                    }

                    TS_FAIL("testHWAScheckPartialGoodForDescendants>"
                            "functional = false, should be true, "
                            "type = %s, chip unit = %d%s, chiplet ID = 0x%02x. "
                            "pDesc HUID 0x %08x",
                            l_type_str,
                            l_chipUnit,
                            l_pgDataStr,
                            l_chipletID,
                            get_huid(pDesc));
                }

                if (l_targetInfo)
                {
                    const size_t l_num_children = ({
                            TargetHandleList childList;
                            targetService().getAssociated( childList, pDesc,
                                                           TargetService::CHILD,
                                                           TargetService::IMMEDIATE);
                            childList.size();
                        });

                    /* Only one child at a time should go bad, so the parent
                       should be functional or not based on whether we have more
                       than one child. */
                    const bool l_shouldSucceed = l_num_children > 1;

                    TS_INFO( "testHWAScheckPartialGoodForDescendants: "
                             "%s (chiplet ID = 0x%02x) is not functional"
                             "(%d children, should %sbe functional)",
                             l_type_str,
                             l_chipletID,
                             static_cast<int>(l_num_children),
                             l_shouldSucceed ? "" : "not "
                        );

                    const pg_entry_t l_original_entry = pgDataAllGood[l_pgIdx];

                    // We don't want to flip the always-good bits of always-good
                    // targets because if they're not set then the whole chip is
                    // toast and we already test for that elsewhere. The
                    // always_good_mask is NO_ALWAYS_GOOD_BITS (0) if there
                    // aren't any.
                    const pg_entry_t l_original_entry_without_always_good_bits
                        = pgDataAllGood[l_pgIdx] | l_targetInfo->always_good_mask;

                    // The pgdata we will be modifying
                    partialGoodVector bad_pgData = pgDataAllGood;

                    // Iterate with a mask over every bit of the pg entry of
                    // this unit
                    for (pg_mask_t l_mask = 1u << (sizeof(pg_mask_t) * 8 - 1);
                         l_mask != 0;
                         l_mask >>= 1)
                    {
                        // if a bit is set to GOOD (not including the
                        // always-good bits of always-good targets, if any),
                        // then flip it and make sure that if we only have one
                        // child, our state turns bad; and if not, it doesn't.
                        if (!(l_mask & l_original_entry_without_always_good_bits))
                        {
                            // set the bit to BAD
                            bad_pgData[l_pgIdx] = l_original_entry | l_mask;

                            if (checkPartialGoodForDescendants(pDesc, bad_pgData)
                                != l_shouldSucceed)
                            {
                                TS_FAIL("testHWAScheckPartialGoodForDescendants>"
                                        "functional = %d, should be %d, "
                                        "[0x%02x] = 0x%08x, mask = 0x%08x. "
                                        "pDesc HUID 0x %08x",
                                        !l_shouldSucceed, l_shouldSucceed,
                                        l_pgIdx,
                                        bad_pgData[l_pgIdx],
                                        l_mask,
                                        get_huid(pDesc));
                            }
                        }
                    }

                    if (!(cu_mask(l_chipUnit) & l_targetInfo->all_bad_cu_mask))
                    {
                        // Now test that the parent goes bad when we set all the
                        // PG bits to BAD (i.e. all children go bad).
                        bad_pgData[l_pgIdx]
                            |= ~l_original_entry_without_always_good_bits;

                        if (checkPartialGoodForDescendants(pDesc, bad_pgData))
                        {
                            TS_FAIL("testHWAScheckPartialGoodForDescendants>"
                                    "setting all to bad: "
                                    "functional = true, should be false, "
                                    "[0x%02x] = 0x%08x, "
                                    "pDesc HUID 0x %08x",
                                    l_pgIdx,
                                    bad_pgData[l_pgIdx],
                                    get_huid(pDesc));
                        }
                    }
                }
            } // for pDesc_it
        } // for pTarget_it

        TS_INFO( "testHWAScheckPartialGoodForDescendants exit" );
    }

    /**
     * @brief   test markChildrenNonFunctional
     */
    void testHWASMarkChildrenNonFunctional()
    {
        // This test ensures that if the parent of a target is marked bad, then
        // it also is marked bad.

        // Get list of present targets with type PROC
        TargetHandleList pCheckPres;
        getAllChips( pCheckPres, TYPE_PROC, true );

        TS_INFO( "testHWAScheckMarkChildrenNonFunctional() entry");

        for (const TargetHandle_t pTarget : pCheckPres)
        {
            TargetHandleList pDescList;
            targetService().getAssociated( pDescList, pTarget,
                TargetService::CHILD, TargetService::ALL);

            for (const TargetHandle_t pDesc : pDescList)
            {
                const ATTR_TYPE_type l_type = pDesc->getAttr<ATTR_TYPE>();
                ATTR_CHIPLET_ID_type l_chipletID = 0;
                pDesc->tryGetAttr<ATTR_CHIPLET_ID>(l_chipletID);
                ATTR_CHIP_UNIT_type l_chipUnit = 0;
                pDesc->tryGetAttr<ATTR_CHIP_UNIT>(l_chipUnit);

                const char* const l_type_str = attrToString<ATTR_TYPE>(l_type);

                TargetHandle_t l_parentTarget = pDesc;

                ATTR_CHIPLET_ID_type l_parentChipletID = 0;

                const auto l_targetInfo
                    = lookup_target_info(targets_with_parents, l_type);

                // In this block we are traversing up the target hierarchy until
                // we have the ancestor of this target which owns the PG bits
                // that will cause this target to go bad
                if (l_targetInfo)
                {
                    do {
                        l_parentTarget
                            = getImmediateParentByAffinity(l_parentTarget);

                        if (!l_parentTarget)
                        {
                            TS_FAIL(
                                "testHWAScheckMarkChildrenNonFunctional>"
                                "Failed to find parent of type %s "
                                "for target %s "
                                "HUID = 0x %08x",
                                attrToString<ATTR_TYPE>(l_targetInfo->parent_type),
                                l_type_str, get_huid(pDesc)
                                );
                            break;
                        }
                    } while (l_parentTarget->getAttr<ATTR_TYPE>()
                             != l_targetInfo->parent_type);

                    if (!l_parentTarget)
                    {
                        continue;
                    }

                    l_parentChipletID = l_parentTarget->getAttr<ATTR_CHIPLET_ID>();
                }

                TS_INFO("testHWAScheckMarkChildrenNonFunctional: "
                        "descendant functional - "
                        "type %s, chip unit %d",
                        l_type_str, l_chipUnit);

                pg_entry_t l_pgIdx = 0;

                if (l_targetInfo)
                {
                    l_pgIdx = (l_targetInfo->parent_pg_idx == USE_PARENT_CHIPLET_ID
                               ? l_parentChipletID
                               : l_targetInfo->parent_pg_idx);
                }

                // Make sure we're starting out with good state at the beginning
                if (!checkPropagationOfBadState(__func__,
                                                l_parentTarget,
                                                pDesc,
                                                pgDataAllGood))
                {
                    char l_pgDataStr[32] = { };

                    if (l_targetInfo)
                    {
                        sprintf(l_pgDataStr, ", pgData = 0x%08x", pgDataAllGood[l_pgIdx]);
                    }

                    TS_FAIL("testHWAScheckMarkChildrenNonFunctional>"
                            "functional = false, should be true, "
                            "type = %s, chip unit = %d%s, chiplet ID = 0x%02x. "
                            "pDesc HUID 0x %08x",
                            l_type_str,
                            l_chipUnit,
                            l_pgDataStr,
                            l_chipletID,
                            get_huid(pDesc));
                }

                // If we can modify the bits of the parent, set its state to BAD
                // and make sure that the bad state propagates to this child
                if (l_targetInfo)
                {
                    TS_INFO( "testHWAScheckMarkChildrenNonFunctional: "
                             "%s (chiplet ID = 0x%02x) is not functional",
                             l_type_str,
                             l_chipletID);

                    // Make a copy we can modify to be bad
                    auto bad_pgData = pgDataAllGood;

                    // set the parent's entry to some BAD state, then check if
                    // we're also bad
                    bad_pgData[l_pgIdx] |= l_targetInfo->parent_pg_entry_bits_to_set;

                    if (checkPropagationOfBadState(__func__,
                                                   l_parentTarget,
                                                   pDesc,
                                                   bad_pgData))
                    {
                        TS_FAIL("testHWAScheckMarkChildrenNonFunctional>"
                                "functional = true, should be false, "
                                " = 0x%08x. "
                                "pDesc HUID 0x %08x, parent HUID 0x %08x, "
                                "pg idx = %d",
                                bad_pgData[l_pgIdx],
                                get_huid(pDesc),
                                get_huid(l_parentTarget),
                                l_pgIdx);
                    }
                }
            } // for pDesc_it
        } // for pTarget_it

        TS_INFO( "testHWASMarkChildrenNonFunctional exit" );
    }

    /**
     * @brief   test restrictECunits
     */
    void testHWASrestrictECunits()
    {
        using namespace HWAS;
        using namespace TARGETING;

#if 0 //Cannot actually run this because it might change state
        errlHndl_t errl = NULL;

        // list of procs and data
        procRestrict_t l_procEntry;
        std::vector <procRestrict_t> l_procRestrictList;

        // Get list of present targets with type PROC
        TargetHandleList pCheckPres;
        getAllChips( pCheckPres, TYPE_PROC, true );

        for (TargetHandleList::const_iterator pTarget_it = pCheckPres.begin();
             pTarget_it != pCheckPres.end();
             ++pTarget_it
            )
        {
            TargetHandle_t pTarget = *pTarget_it;

            // create data for each proc
            l_procEntry.target = pTarget;
            l_procEntry.group = 0;
            l_procEntry.procs = 1;
            l_procEntry.maxECs = UINT32_MAX;

            l_procPRList.push_back(l_procEntry);
        } // for pTarget_it

        // Call restrictECunits
        errl = restrictECunits(l_procRestrictList, false, 0);
        if (errl != NULL)
        {   // restrict EC units failed
            TS_FAIL("testHWASrestrictECunits> - restrict EC units failed");
        }
#endif

        // Instead verify that we ended up with exactly the right number
        //  enabled cores that we expect for our P10 standalone config
        TargetHandleList l_funcProcs;
        getAllChips( l_funcProcs, TYPE_PROC, true );
        for( const auto& l_proc : l_funcProcs )
        {
            TargetHandleList l_funcCores;
            getChildChiplets( l_funcCores, l_proc, TYPE_CORE, true );

            // Currently we have 4 ECs configured in the PG record
#ifdef PROFILE_CODE
            const size_t l_numCores = 8;
#else
            const size_t l_numCores = 4;
#endif

            if( l_funcCores.size() != l_numCores )
            {
                TS_FAIL("testHWASrestrictECunits> Expected %d cores, but saw %d",
                        l_numCores, l_funcCores.size() );
            }
        }

        TS_INFO( "testHWASrestrictECunits exit" );

    }

    /**
     * @brief   test pervStates
     */
    void testHWASpervStates()
    {
        using namespace HWAS;
        using namespace TARGETING;

        TS_INFO( "testHWASpervStates entry" );

        // find top level target
        Target * pSys;
        targetService().getTopLevelTarget(pSys);

        PredicateCTM predChip(CLASS_CHIP);
        PredicateCTM predPerv(CLASS_UNIT, TYPE_PERV);
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predChip).Or().push(&predPerv).Or();

        TargetHandleList pPervList;
        // get list of all PERV targets
        targetService().getAssociated( pPervList, pSys,
                TargetService::CHILD,
                TargetService::ALL,
                &predPerv );
        // sort the list by ATTR_HUID to ensure that we
        //  start at the same place each time
        std::sort(pPervList.begin(), pPervList.end(),
                compareTargetHuid);
        do
        {
            if (pPervList.empty())
            {
                TS_FAIL("testHWASpervStates: empty pPervList");
                break;
            }
            // Iterate through all PERV chiplets
            for (TargetHandleList::const_iterator
                 l_pervIter = pPervList.begin();
                 l_pervIter != pPervList.end();
                 ++l_pervIter)
            {
                Target * l_target = *l_pervIter;

                // The chip unit number of the perv target
                // is the index into the PG data
                ATTR_CHIP_UNIT_type chip_unit =
                  l_target->getAttr<ATTR_CHIP_UNIT>();

                // get the HW State of the target
                HwasState hwasState = l_target->getAttr<ATTR_HWAS_STATE>();

                // get parent target and the HW state
                const Target * l_ptarget;
                l_ptarget = getParentChip(l_target);
                HwasState phwasState = l_ptarget->getAttr<ATTR_HWAS_STATE>();

                if (phwasState.present == true)
                {
                    if (hwasState.present == false)
                    {
                        TS_FAIL("testHWASpervStates: PERV[%d] HUID: 0x %.8X - is NOT Present",
                             chip_unit,
                             get_huid(l_target));
                        break;
                    }
                    HWAS_DBG("PERV[%d]: HUID: 0x %.8X - %spresent, %sfunctional",
                        chip_unit,
                        get_huid(l_target),
                        hwasState.present ? "" : "NOT ",
                        hwasState.functional ? "" : "NOT ");
                }
                else
                {
                    if (hwasState.present == true)
                    {
                        TS_FAIL("testHWASpervStates: PERV[%d] HUID: 0x %.8X - is Present and Parent is NOT",
                             chip_unit,
                            l_target->getAttr<ATTR_HUID>());
                        break;
                    }
                    HWAS_DBG("PERV[%d]: HUID: 0x %.8X - %spresent, %sfunctional",
                        chip_unit,
                        get_huid(l_target),
                        hwasState.present ? "" : "NOT ",
                        hwasState.functional ? "" : "NOT ");
                }
            }
        } while(0);

        TS_INFO( "testHWASpervStates exit" );
    }

    /**
     * @brief   test platReadLx
     */
    void testHWASplatReadLx()
    {
        using namespace TARGETING;

        TS_INFO( "testHWASplatReadLx entry" );

        // call platReadLx with target that isn't in the VPD
        errlHndl_t l_errl = nullptr;

        // Get system target
        Target* pSys;
        targetService().getTopLevelTarget(pSys);

        // Get processor targets
        TARGETING::TargetHandleList l_procList;
        getAllChips(l_procList, TYPE_PROC);

        // Get children of first processor target
        TargetHandleList l_childList;
        getChildChiplets(l_childList, *(l_procList.begin()), TYPE_NA, false);

        uint8_t lxData[HWAS::VPD_CRP0_LX_HDR_DATA_LENGTH];

        // Try using system target which does not have a chip unit attribute
        l_errl = HWAS::platReadLx(pSys, lxData);

        // Check that an error log is returned
        if (l_errl)
        {
            // error log is expected case, delete it
            delete l_errl;
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("testHWASplatReadLx> No error from platReadLx(pSys).");
        }

        // Find a target that has a large chip unit and use that target
        for( const auto & l_child_target: l_childList )
        {
            uint8_t l_chip_unit;
            if (l_child_target->
                tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_chip_unit))
            {
                // Check if chip unit attribute is large enough
                if(l_chip_unit >= HWAS::VPD_CRP0_LX_MAX_X)
                {
                    // Try using target which has larger than expected chip unit
                    l_errl = HWAS::platReadLx(l_child_target, lxData);

                    // Check that an error log is returned
                    if (l_errl)
                    {
                        // error log is expected case, delete it
                        delete l_errl;
                        l_errl = nullptr;
                    }
                    else
                    {
                        TS_FAIL("testHWASplatReadLx> No error from "
                                "platReadLx(l_child_target 0x%8X).",
                                get_huid(l_child_target));
                    }

                    break;
                }
            }
        }

        TS_INFO( "testHWASplatReadLx exit" );
    }
};

#endif //
