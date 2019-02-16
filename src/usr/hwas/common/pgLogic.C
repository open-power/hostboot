/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/pgLogic.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <hwas/common/pgLogic.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/hwasPlatTrace.H>
#include <hwas/hwasPlatAssert.H>
#include <targeting/common/utilFilter.H>
#include <hwas/common/hwasError.H>

using namespace HWAS::COMMON;

namespace PARTIAL_GOOD
{

    // These constants are used for the applicableChipTypes in a PartialGoodRule
    // A combination of them can be pushed onto applicableChipTypes' expr stack.
    const TARGETING::PredicateCTM PREDICATE_NIMBUS(TARGETING::CLASS_NA,
                                                   TARGETING::TYPE_NA,
                                                   TARGETING::MODEL_NIMBUS);

    const TARGETING::PredicateCTM PREDICATE_CUMULUS(TARGETING::CLASS_NA,
                                                    TARGETING::TYPE_NA,
                                                    TARGETING::MODEL_CUMULUS);

    const TARGETING::PredicateCTM PREDICATE_AXONE(TARGETING::CLASS_NA,
                                                  TARGETING::TYPE_NA,
                                                  TARGETING::MODEL_AXONE);

    const TARGETING::PredicateCTM PREDICATE_NA(TARGETING::CLASS_NA,
                                               TARGETING::TYPE_NA,
                                               TARGETING::MODEL_NA);

    const predicates_t PREDICATE_P9 = {&PREDICATE_CUMULUS, &PREDICATE_NIMBUS,
                                 &PREDICATE_AXONE};

    // Partial Good Rule constants for Target Types
    // Naming convention for masks is as follows:
    // TargetType_RuleNumber_MaskType_MASK
    //
    //  Mask Types: PG = Partial Good
    //              AG = All Good
    //              CU = Applicable Chip Units

    // Special Masks that are applicable to many rules

    // This mask is common to many rules because in most cases we are checking
    // specific bits and don't care about the rest. To detect a problem with
    // only those bits we provide an AG mask of all zeroes.
    const uint16_t ALL_OFF_AG_MASK               = 0x0000;

    // This mask is common to many rules because there are target types that
    // cover a set of bits where all must checked at one time instead of just a
    // subset of bits to determine functionality.
    const uint16_t ALL_ON_PG_MASK                = 0xFFFF;

    // Used in place of a chip unit mask to indicate that the rule is applicable
    // for all values a chip unit can take.
    const size_t APPLICABLE_TO_ALL               = UINT64_MAX;

    // The following three masks are common among a few PG Rules and have been
    // defined as special masks. Each mask applies to the chip unit that the
    // name suggests. Zero bit for chip unit 0, etc.
    const size_t ZERO_BIT_CU_MASK                = 0x0001;
    const size_t ONE_BIT_CU_MASK                 = 0x0002;
    const size_t TWO_BIT_CU_MASK                 = 0x0004;


    // Used in place of a PG index to indicate that the target's associated
    // chiplet id is the correct way to index the PG vector.
    const uint8_t USE_CHIPLET_ID                 = 0xFF;

    // Used when a target type has no applicable partial good checking logic.
    // Instead of omitting that target type from the map of rules, it will have:
    //      pgMask == MASK_NA
    //      agMask == MASK_NA
    //      pgIndex == INDEX_NA
    // This will ensure that the algorithm in isDescFunctional() will execute
    // successfully and serve to enforce that all targets be defined in the
    // rules map.
    const uint16_t MASK_NA                       = 0x0000;
    const uint8_t INDEX_NA                       = 0x00;

    // Target Type Masks
    // PG Masks are created such that:
    //      pgData[ pgIndex ] & pgMask
    // produces the AG Mask defined for that rule. They are defined to cover the
    // set of bits that a target type covers. The AG masks were defined either
    // by directly using the provided AG mask listed in the MVPD PG Mapping
    // Table or were chosen to check the specific bits a target type covers.

    // EQ
    // PG/AG Masks
    const uint16_t EQ_R1_PG_MASK                 = 0xFC33;
    const uint16_t EQ_R1_AG_MASK                 = 0xE001;

    // EX
    // PG/AG Masks
    const uint16_t EX_R1_PG_MASK                 = 0x0288;
    const uint16_t EX_R2_PG_MASK                 = 0x0144;

    // Applicable Chip Units
    // Rule 1 only applies to even chip unit values
    const size_t EX_R1_CU_MASK                   = 0x5555555555555555u;
    // Rule 2 only applies to odd chip unit values
    const size_t EX_R2_CU_MASK                   = 0xAAAAAAAAAAAAAAAAu;

    // EC
    // PG/AG Masks
    const uint16_t EC_R1_AG_MASK                 = 0xE1FF;

    // MC
    // PG/AG Masks
    const uint16_t MC_R1_AG_MASK                 = 0xE0FD;
    const uint16_t MC_R2_PG_MASK                 = 0x0040;
    const uint16_t MC_R3_PG_MASK                 = 0x0020;

    // MCA
    // PG/AG Masks
    const uint16_t MCA_R1_PG_MASK                = 0x0200;
    const uint16_t MCA_R2_PG_MASK                = 0x0100;

    // Applicable Chip Units
    const size_t MCA_R2_CU_MASK                  = 0x00CC;

    // MCBIST
    // PG/AG Masks
    // There is a special rule for MCBIST targets where the first MCA (MCA0 and
    // MCA4) on each MC is required to be functional for it to be functional. To
    // condense that rule into a single rule the bit that needs to be checked
    // has been included in the PG mask. The PG mask excluding that bit would
    // have been FCFF.
    const uint16_t MCBIST_R1_PG_MASK             = 0xFEFF;
    const uint16_t MCBIST_R1_AG_MASK             = 0xE0FD;

    // MCS
    // PG/AG Masks
    const uint16_t MCS_R1_PG_MASK                = 0x0020;
    const uint16_t MCS_R2_PG_MASK                = 0x0040;
    const uint16_t MCS_R3_PG_MASK                = 0xFEFF;
    const uint16_t MCS_R4_PG_MASK                = 0xFDFF;

    const uint16_t MCS_ALL_GOOD_MASK             = 0xE0FD;

    // Applicable Chip Units
    // Rule 1 only applies to chip units 0 & 1
    const size_t MCS_R1_CU_MASK                  = 0x0003;
    // Rule 2 only applies to chip units 2 & 3
    const size_t MCS_R2_CU_MASK                  = 0x000C;
    // Rule 3 only applies to chip units 0 & 2
    const size_t MCS_R3_CU_MASK                  = 0x0005;
    // Rule 4 only applies to chip units 1 & 3
    const size_t MCS_R4_CU_MASK                  = 0x000A;

    // NPU
    // PG/AG Masks
    const uint16_t NPU_R1_PG_MASK                = 0x0100;

    // OBUS
    // PG/AG Masks
    const uint16_t OBUS_R1_AG_MASK               = 0xE1FD;
    const uint16_t OBUS_R2_PG_MASK               = 0x0100;
    const uint16_t OBUS_R3_PG_MASK               = 0x0080;

    // Applicable Chip Units
    // Rule 3 only applies to Cumulus OBUS's 1 and 2
    const size_t OBUS_R3_CU_MASK                 = 0x0006;

    // PEC
    // PG/AG Masks
    const uint16_t PEC_R1_AG_MASK                = 0xE1FD;
    const uint16_t PEC_R2_AG_MASK                = 0xE0FD;
    const uint16_t PEC_R3_AG_MASK                = 0xE07D;

    // PERV
    // PG/AG Masks
    const uint16_t PERV_R1_PG_MASK               = 0x1000;

    // XBUS
    // PG/AG Masks
    const uint16_t XBUS_R1_PG_MASK               = 0x0040;
    const uint16_t XBUS_R2_PG_MASK               = 0x0020;
    const uint16_t XBUS_R3_PG_MASK               = 0x0010;


    // Partial Good Vector Indexes
    const uint16_t N1_PG_INDEX                   = 0x03;
    const uint16_t N3_PG_INDEX                   = 0x05;

    const specialRuleFuncPtr_t NO_SPECIAL_RULE = nullptr;

    const PartialGoodRulesTable pgTable;

    PartialGoodRulesTable::~PartialGoodRulesTable()
    {
        for (auto const& type : pgRules_map)
        {
            for (pgRules_t::const_iterator it = type.second.begin();
                it != type.second.end(); ++it)
            {
                delete (*it);
            }
        }
    }

    errlHndl_t PartialGoodRulesTable::findRulesForTarget(
            const TARGETING::TargetHandle_t &i_target,
            pgLogic_t &o_targetPgLogic) const
    {
        errlHndl_t l_errl = nullptr;

        // Lookup the Target in the PG Rules Table
        auto rulesIterator =
            pgRules_map.find(i_target->getAttr<TARGETING::ATTR_TYPE>());

        do {

            if (rulesIterator == pgRules_map.end())
            {
                // Target is missing from the table. Return an empty vector.
                break;
            }

            pgRules_t l_allRules = rulesIterator->second;

            // Since many targets don't have ATTR_MODEL filled in, lookup
            // the master proc and use that to verify if this chip type is
            // applicable for the target.
            TARGETING::TargetService& ts = TARGETING::targetService();
            TARGETING::TargetHandle_t masterProc;
            ts.masterProcChipTargetHandle(masterProc);

            // Iterate through all of the pg rules and compose a list of
            // applicable rules based on chip unit and chip type.
            for (pgRules_t::const_iterator pgRule = l_allRules.begin();
                 pgRule != l_allRules.end(); ++pgRule)
            {
                TARGETING::ATTR_CHIP_UNIT_type targetCU =
                    i_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                // Compare the pgRule's chip type to the target. Encode the
                // target's chip unit and see if it is a match for this rule.
                if ((*pgRule)->iv_applicableChipTypes(masterProc)
                    && (*pgRule)->isApplicableToChipUnit(targetCU))
                {
                    // Current PG Rule is applicable to this target so create
                    // logic for it and add it to the list of logic for this
                    // target.
                    PartialGoodLogic pgLogic;
                    pgLogic.iv_pgMask = (*pgRule)->iv_pgMask;
                    pgLogic.iv_agMask = (*pgRule)->iv_agMask;
                    pgLogic.iv_pgIndex = (*pgRule)->iv_pgIndex;
                    pgLogic.iv_specialRule = (*pgRule)->iv_specialRule;

                    // Check if the chiplet id of the target is a valid index
                    // for this rule.
                    if ((*pgRule)->useChipletIdAsIndex())
                    {
                        auto l_targetChipletId =
                            i_target->getAttr<TARGETING::ATTR_CHIPLET_ID>();

                        // The index must be within range of the vector.
                        // Otherwise we'll go out-of-bounds.
                        if (l_targetChipletId < HWAS::VPD_CP00_PG_DATA_ENTRIES)
                        {
                            // The target's Chiplet Id is a valid index for this
                            // rule and is within range.
                            pgLogic.iv_pgIndex = l_targetChipletId;
                        }
                        else
                        {
                            /*@
                             * @errortype
                             * @severity        ERRL_SEV_UNRECOVERABLE
                             * @moduleid        HWAS::MOD_FIND_RULES_FOR_TARGET
                             * @reasoncode      HWAS::RC_PG_INDEX_INVALID
                             * @devdesc         A rule called for the use of the
                             *                  MRW's supplied CHIPLET_ID for an
                             *                  index into the PG vector. That
                             *                  value has gone unexpectedly
                             *                  out-of-range.
                             * @custdesc        A problem occured during IPL of
                             *                  the system:
                             *                  Internal Firmware Error
                             * @userdata1       PG Index value
                             * @userdata2       HUID of the target
                             */
                            l_errl = HWAS::hwasError(
                                              ERRL_SEV_UNRECOVERABLE,
                                              HWAS::MOD_FIND_RULES_FOR_TARGET,
                                              HWAS::RC_PG_INDEX_INVALID,
                                              l_targetChipletId,
                                              get_huid(i_target));

                            break;
                        }
                    }

                    // Add it to list of pg logic for this target.
                    o_targetPgLogic.push_back(pgLogic);
                }
            }

            // If o_targetPgLogic has no entries then that means that there
            // doesn't exist any PG rules for the given target or another error
            // was encountered. If no other error occurred then return the
            // the following error if applicable.
            if ((l_errl == nullptr) && (o_targetPgLogic.size() == 0))
            {
                /*@
                * @errortype
                * @severity        ERRL_SEV_UNRECOVERABLE
                * @moduleid        HWAS::MOD_IS_DESCENDANT_FUNCTIONAL
                * @reasoncode      HWAS::RC_NO_PG_LOGIC
                * @devdesc         To enforce all target types have partial good
                *                  rules and logic, all targets must be included
                *                  in the PartialGoodRulesTable. A combination
                *                  of target type, chip type, and chip unit
                *                  produced an empty set of logic for the
                *                  target.
                *
                * @custdesc        A problem occured during IPL of the system:
                *                  Internal Firmware Error
                * @userdata1       target type attribute
                * @userdata2       HUID of the target
                */
                l_errl = hwasError(
                                   ERRL_SEV_UNRECOVERABLE,
                                   HWAS::MOD_IS_DESCENDANT_FUNCTIONAL,
                                   HWAS::RC_NO_PG_LOGIC,
                                   i_target->getAttr<TARGETING::ATTR_TYPE>(),
                                   get_huid(i_target));

                break;
            }

        } while(0);

        return l_errl;
    }


    PartialGoodRule::PartialGoodRule() : iv_pgMask(MASK_NA),
                                    iv_agMask(MASK_NA),
                                    iv_pgIndex(INDEX_NA),
                                    iv_applicableChipUnits(APPLICABLE_TO_ALL),
                                    iv_specialRule(NO_SPECIAL_RULE)
    {
        iv_applicableChipTypes.push(&PREDICATE_NA);
    };

    PartialGoodRule::PartialGoodRule
    (
        predicates_t i_preds,
        uint16_t i_pgMask, uint16_t i_agMask,
        uint8_t  i_pgIndex, size_t i_appChipUnits,
        specialRuleFuncPtr_t rule
    )
    : iv_pgMask(i_pgMask), iv_agMask(i_agMask), iv_pgIndex(i_pgIndex),
      iv_applicableChipUnits(i_appChipUnits), iv_specialRule(rule)
    {

        // First push all predicates onto the expr stack.
        for (predicates_t::const_iterator it = i_preds.begin();
             it != i_preds.end(); ++it)
        {
            iv_applicableChipTypes.push(*it);
        }

        // If there were more than one predicate pushed on the expr stack then
        // add n - 1 Or() predicates to the expr stack
        if (i_preds.size() > 1)
        {
            for (size_t i = 0; i < (i_preds.size() - 1); ++i)
            {
                iv_applicableChipTypes.Or();
            }
        }
    }

    bool PartialGoodRule::isApplicableToChipUnit(uint8_t i_chipUnit) const
    {
        // The encoded chip unit has the value of zero represented as the
        // farthest right bit.
        size_t l_encodedChipUnit = 0x0001;

        // Left shift the encoded value a number of times equal to the value
        // of i_chipUnit. This puts the ON bit under the correct position to
        // be compared against the chip unit mask.
        l_encodedChipUnit <<= i_chipUnit;

        bool result = false;

        // A PartialGoodRule is applicable for a chip unit if the result of
        // the bit-wise & results in the encoded chip unit value. This
        // allows the special chip unit mask APPLICABLE_TO_ALL to function
        // correctly.
        if ((iv_applicableChipUnits & l_encodedChipUnit) ==
                l_encodedChipUnit)
        {
            result = true;
        }

        return result;
    }

    bool PartialGoodRule::useChipletIdAsIndex() const
    {
        return iv_pgIndex == USE_CHIPLET_ID;
    }

    ////////////////////////////////////////////////////////////////////////////
    //                              Special Rules
    ////////////////////////////////////////////////////////////////////////////


    bool PervSpecialRule(const TARGETING::TargetHandle_t &i_desc,
                         const uint16_t i_pgData[])
    {
        HWAS_ASSERT((i_desc->getAttr<TARGETING::ATTR_TYPE>()
                          == TARGETING::TYPE_PERV),
                    "PervSpecialRule: i_desc type != TYPE_PERV");

        // The chip unit number of the perv target is the index into the PG data
        auto indexPERV = i_desc->getAttr<TARGETING::ATTR_CHIP_UNIT>();

        // Set the local attribute copy of this data
        TARGETING::ATTR_PG_type l_pg = i_pgData[indexPERV];
        i_desc->setAttr<TARGETING::ATTR_PG>(l_pg);

        return true;
    }

    bool ObusBrickSpecialRule(const TARGETING::TargetHandle_t &i_desc,
                              const uint16_t i_pgData[])
    {
        HWAS_ASSERT((i_desc->getAttr<TARGETING::ATTR_TYPE>()
                          == TARGETING::TYPE_OBUS_BRICK),
                    "ObusBrickSpecialRule: i_desc type != TYPE_OBUS_BRICK");

        bool l_descFunctional = true;
        auto obusType = TARGETING::TYPE_OBUS;
        TARGETING::Target* l_obus_ptr = getParent(i_desc, obusType);

        //If NPU is bad and OBUS is non-SMP, then mark them bad
        // Bit does not matter unless not in SMP mode
        if ((l_obus_ptr->getAttr<TARGETING::ATTR_OPTICS_CONFIG_MODE>()
                    != TARGETING::OPTICS_CONFIG_MODE_SMP)
           && ((i_pgData[N3_PG_INDEX] & NPU_R1_PG_MASK) != ALL_OFF_AG_MASK))
        {
            TRACFCOMP(HWAS::g_trac_imp_hwas,
                      "pDesc 0x%.8X - OBUS_BRICK pgData[%d]: "
                      "actual 0x%04X, expected 0x%04X - bad",
                      i_desc->getAttr<TARGETING::ATTR_HUID>(),
                      N3_PG_INDEX,
                      i_pgData[N3_PG_INDEX],
                      ALL_OFF_AG_MASK);

            l_descFunctional = false;
        }

        return l_descFunctional;
    }

    bool EQSpecialRule(const TARGETING::TargetHandle_t &i_desc,
                       const uint16_t i_pgData[])
    {

        HWAS_ASSERT((i_desc->getAttr<TARGETING::ATTR_TYPE>()
                    == TARGETING::TYPE_EQ),
                   "EQSpecialRule: i_desc target type != TYPE_EQ");

        bool l_valid = false;

        // This rule only looks at specific bits in the partial good vector.
        // These bits can be found by using  EQ chiplet id's value as an index
        // into the vector.
        auto EQChipletId = i_desc->getAttr<TARGETING::ATTR_CHIPLET_ID>();
        uint16_t l_pgData = i_pgData[EQChipletId];

        // For this rule, we check the triplets associated with EX targets.
        // Those are the L3, L2, and REFR units. In order for this rule to
        // be validated, only values of all 0 or all 1 are permitted in those
        // three bit positions.
        if ((((l_pgData & EX_R1_PG_MASK) == 0)
                || ((l_pgData & EX_R1_PG_MASK) == EX_R1_PG_MASK))
           && (((l_pgData & EX_R2_PG_MASK) == 0)
                || ((l_pgData & EX_R2_PG_MASK) == EX_R2_PG_MASK)))
        {
            l_valid = true;
        }

        return l_valid;

    }

}
