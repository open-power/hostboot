/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/pgLogic.H $                       */
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
#ifndef PG_LOGIC_H
#define PG_LOGIC_H

/* @file pgLogic.H
 *
 * Defines the necessary logic for checking the Partial Good data read from the
 * VPD. This logic is used in hwas.C  isDescFunctional
 */

#include <map>
#include <targeting/common/target.H>
#include <targeting/common/commontargeting.H>

namespace PARTIAL_GOOD
{
    // These constants are used for the applicableChipTypes in a PartialGoodRule
    // A combination of them can be pushed onto applicableChipTypes' expr stack.
    extern const TARGETING::PredicateCTM PREDICATE_NIMBUS;

    extern const TARGETING::PredicateCTM PREDICATE_CUMULUS;

    extern const TARGETING::PredicateCTM PREDICATE_AXONE;

    extern const TARGETING::PredicateCTM PREDICATE_NA;

    typedef std::vector<const TARGETING::PredicateCTM * > predicates_t;

    extern const predicates_t PREDICATE_P9;

    // Partial Good Rule extern constants for Target Types
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
    extern const uint16_t ALL_OFF_AG_MASK;

    // This mask is common to many rules because there are target types that
    // cover a set of bits where all must checked at one time instead of just a
    // subset of bits to determine functionality.
    extern const uint16_t ALL_ON_PG_MASK;

    // Used in place of a chip unit mask to indicate that the rule is applicable
    // for all values a chip unit can take.
    extern const size_t APPLICABLE_TO_ALL;

    // The following three masks are common among a few PG Rules and have been
    // defined as special masks. Each mask applies to the chip unit that the
    // name suggests. Zero bit for chip unit 0, etc.
    extern const size_t ZERO_BIT_CU_MASK;
    extern const size_t ONE_BIT_CU_MASK;
    extern const size_t TWO_BIT_CU_MASK;


    // Used in place of a PG index to indicate that the target's associated
    // chiplet id is the correct way to index the PG vector.
    extern const uint8_t USE_CHIPLET_ID;

    // Used when a target type has no applicable partial good checking logic.
    // Instead of omitting that target type from the map of rules, it will have:
    //      pgMask == MASK_NA
    //      agMask == MASK_NA
    //      pgIndex == INDEX_NA
    // This will ensure that the algorithm in isDescFunctional() will execute
    // successfully and serve to enforce that all targets be defined in the
    // rules map.
    extern const uint16_t MASK_NA;
    extern const uint8_t INDEX_NA;

    // Target Type Masks
    // PG Masks are created such that:
    //      pgData[ pgIndex ] & pgMask
    // produces the AG Mask defined for that rule. They are defined to cover the
    // set of bits that a target type covers. The AG masks were defined either
    // by directly using the provided AG mask listed in the MVPD PG Mapping
    // Table or were chosen to check the specific bits a target type covers.

    // EQ
    // PG/AG Masks
    extern const uint16_t EQ_R1_PG_MASK;
    extern const uint16_t EQ_R1_AG_MASK;

    // EX
    // PG/AG Masks
    extern const uint16_t EX_R1_PG_MASK;
    extern const uint16_t EX_R2_PG_MASK;

    // Applicable Chip Units
    // Rule 1 only applies to even chip unit values
    extern const size_t EX_R1_CU_MASK;
    // Rule 2 only applies to odd chip unit values
    extern const size_t EX_R2_CU_MASK;

    // EC
    // PG/AG Masks
    extern const uint16_t EC_R1_AG_MASK;

    // MC
    // PG/AG Masks
    extern const uint16_t MC_R1_AG_MASK;
    extern const uint16_t MC_R2_PG_MASK;
    extern const uint16_t MC_R3_PG_MASK;

    // MCA
    // PG/AG Masks
    extern const uint16_t MCA_R1_PG_MASK;
    extern const uint16_t MCA_R2_PG_MASK;

    // Applicable Chip Units
    extern const size_t MCA_R2_CU_MASK;

    // MCBIST
    // PG/AG Masks
    // There is a special rule for MCBIST targets where a specific MCA is
    // required to be functional for it to be functional. To condense that rule
    // into a single rule the bit that needs to be checked has been included in
    // the PG mask. The PG mask excluding that bit would have been FCFF.
    extern const uint16_t MCBIST_R1_PG_MASK;
    extern const uint16_t MCBIST_R1_AG_MASK;

    // MCS
    // PG/AG Masks
    extern const uint16_t MCS_R1_PG_MASK;
    extern const uint16_t MCS_R2_PG_MASK;
    extern const uint16_t MCS_R3_PG_MASK;
    extern const uint16_t MCS_R4_PG_MASK;

    extern const uint16_t MCS_ALL_GOOD_MASK;

    // Applicable Chip Units
    // Rule 1 only applies to chip units 0 & 1
    extern const size_t MCS_R1_CU_MASK;
    // Rule 2 only applies to chip units 2 & 3
    extern const size_t MCS_R2_CU_MASK;
    // Rule 3 only applies to chip units 0 & 2
    extern const size_t MCS_R3_CU_MASK;
    // Rule 4 only applies to chip units 1 & 3
    extern const size_t MCS_R4_CU_MASK;

    // NPU
    // PG/AG Masks
    extern const uint16_t NPU_R1_PG_MASK;

    // OBUS
    // PG/AG Masks
    extern const uint16_t OBUS_R1_AG_MASK;
    extern const uint16_t OBUS_R2_PG_MASK;
    extern const uint16_t OBUS_R3_PG_MASK;

    // Applicable Chip Units
    // Rule 3 only applies to Cumulus OBUS's 1 and 2
    extern const size_t OBUS_R3_CU_MASK;

    // PEC
    // PG/AG Masks
    extern const uint16_t PEC_R1_AG_MASK;
    extern const uint16_t PEC_R2_AG_MASK;
    extern const uint16_t PEC_R3_AG_MASK;

    // PERV
    // PG/AG Masks
    extern const uint16_t PERV_R1_PG_MASK;

    // XBUS
    // PG/AG Masks
    extern const uint16_t XBUS_R1_PG_MASK;
    extern const uint16_t XBUS_R2_PG_MASK;
    extern const uint16_t XBUS_R3_PG_MASK;


    // Partial Good Vector Indexes
    extern const uint16_t N1_PG_INDEX;
    extern const uint16_t N3_PG_INDEX;

    // The struct PartialGoodRule uses a function pointer to indicate that a
    // special rule for handling PG checking exists and that the function
    // pointed to will handle that rule.
    //
    // The special rule function should always return a boolean indicating
    // whether the given target is functional or not depending if the function
    // verified the rule successfully.
    typedef bool (*specialRuleFuncPtr_t)(
                                        const TARGETING::TargetHandle_t &i_desc,
                                        const uint16_t i_pgData[]);
    extern const specialRuleFuncPtr_t NO_SPECIAL_RULE;

    // This struct represents a "row" in the partial good rules map. It contains
    // all the information necessary to verify one or more rules for a target.
    struct PartialGoodRule
    {

        /**
         * @brief       This constructor should be used when adding a rule to
         *              the PartialGoodRulesTable that either doesn't have any
         *              PG checking logic or the only rule is that the target
         *              must have a functional parent. It's a requirement in the
         *              algorithm for isDescFunctional that a target have a
         *              functional parent to be considered functional. However,
         *              it is not necessary that a special rule be defined to
         *              enforce this requirement. The algorithm will mark any
         *              target with this rule as functional on a first pass but
         *              upon checking the target's parent will update the child
         *              with the correct status when the parent's status is
         *              determined.
         *
         */
        PartialGoodRule();

        /**
         * @brief       This constructor should always be used when adding new
         *              rules to the partial good rules map whenever there is
         *              PG checking logic for a target. Since copy and
         *              assignment are disabled for iv_applicableChipTypes, the
         *              only way to initialize its expr stack is to pass in a
         *              vector of PredicateCTMs and push them onto the stack.
         *
         * @param[in] i_preds               The vector of PredicateCTMs to be
         *                                  pushed onto iv_applicableChipTypes
         *                                  expr stack.
         *
         * @param[in] i_pgMask              The partial good mask for this rule.
         *
         * @param[in] i_agMask              The all good mask for this rule.
         *
         * @param[in] i_pgIndex             Where to index into the partial good
         *                                  vector.
         *
         * @param[in] i_appChipUnits        The chip unit values of a target
         *                                  that this rule applies to.
         *
         * @param[in] specialRuleFuncPtr_t  The special rule associated with
         *                                  this target that isn't represented
         *                                  in isDescFunctional. Since every
         *                                  PartialGoodRule is checked for a
         *                                  special rule it's only necessary to
         *                                  point to a unique special rule once.
         */
        PartialGoodRule(predicates_t i_preds, uint16_t i_pgMask,
                        uint16_t i_agMask, uint8_t i_pgIndex,
                        size_t i_appChipUnits,
                        specialRuleFuncPtr_t rule);

        // A predicate expression that indicates what processor chip types this
        // parital good rule applies to. Only logical Or() should be used for
        // multiple applicable chip types.
        //
        TARGETING::PredicatePostfixExpr iv_applicableChipTypes;

        // partial good mask
        // The mask to be applied to the partial good vector.
        uint16_t iv_pgMask;

        // all good mask
        // This mask is the expected result after the pgMask has been
        // bit-wise & with an entry in the partial good vector.
        uint16_t iv_agMask;

        // partial good index
        // Used to index into the partial good vector read from VPD.
        // For cases where the chiplet id should be used as an index into the
        // partial good vector it will be set to USE_CHIPLET_ID.
        uint8_t iv_pgIndex;

        // This represents the applicable chip unit for a target instance that
        // this rule applies to. It is encoded such that each bit starting from
        // the right-most position represents a chip unit value for a target
        // instance.
        //
        // Ex: 1010 => represents values for chip units c3, c2, c1, c0. A 1 in
        //             positions c3 and c1 signify that those are the applicable
        //             chip units for this PartialGoodRule.
        //
        // For cases where a rule applies to a target type & chip type
        // combination regardless of chip unit value it will be set to
        // APPLICABLE_TO_ALL
        size_t iv_applicableChipUnits;

        // A function pointer to a special case rule that cannot be covered by
        // the algorithm in HWAS::isDescFunctional(). This will almost always be
        // a nullptr. It should be used sparingly and only when absolutely
        // necessary.
        specialRuleFuncPtr_t iv_specialRule;

        /**
         * @brief This is a helper function to encode a chip unit value to match
         *        the encoding of the applicableChipUnits member and return
         *        whether the PartialGoodRule is applicable for the given chip
         *        unit value.
         *
         * @param[in] i_chipUnit the chip unit of a target to encode
         *
         * @return bool Whether or not the PG rule applies to this chip unit
         */
        bool isApplicableToChipUnit(uint8_t i_chipUnit) const;

        /**
         * @brief This is a helper function to determine if a target's chiplet
         *        id is the correct pg index for this rule.
         *
         * @return bool Evaluates to true when target's chiplet id is the
         *              correct pg index for this rule.
         */
        bool useChipletIdAsIndex() const;

    private:
        TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(PartialGoodRule);
    };

    // The subset of logic required to check the pg vector. Since copy and
    // assignment of PredicatePostfixExpr have been disabled, it is much simpler
    // to create and pass around this struct than it is a PartialGoodRule.
    struct PartialGoodLogic
    {
        PartialGoodLogic(): iv_pgMask(MASK_NA), iv_agMask(MASK_NA),
                            iv_pgIndex(INDEX_NA),
                            iv_specialRule(NO_SPECIAL_RULE)
        {};

        // partial good mask
        // The mask to be applied to the partial good vector.
        uint16_t iv_pgMask;

        // all good mask
        // This mask is the expected result after the pgMask has been
        // bit-wise & with an entry in the partial good vector.
        uint16_t iv_agMask;

        // partial good index
        // Used to index into the partial good vector read from VPD.
        uint8_t iv_pgIndex;

        // special rule
        // A function pointer that will be used when there is PG logic that
        // can't work in the algorithm found in HWAS::isDescFunctional()
        specialRuleFuncPtr_t iv_specialRule;

    };

    typedef std::vector<PartialGoodRule*> pgRules_t;
    typedef std::vector<PartialGoodLogic> pgLogic_t;

    /*
     * @brief A special rule function for Perv targets. This doesn't have any
     *        additional special logic. It will just set the ATTR_PG for the
     *        Perv target to be the applicable row of partial good data.
     *
     * @param[in] i_desc          A pointer to the current target that this
     *                            function has been called for.
     *
     * @param[in] i_pgData        The partial good data
     *
     * @return bool               Always returns true since this isn't checking
     *                            logic it's just a required additional step.
     */
    bool PervSpecialRule(const TARGETING::TargetHandle_t &i_desc,
                         const uint16_t i_pgData[]);

    /*
     * @brief A special rule function for Obus Brick targets. This will check
     *        if the NPU is functional and whether or not the Obus is in SMP
     *        mode.
     *
     * @param[in] i_desc          A pointer to the current target that this
     *                            function has been called for.
     *
     * @param[in] i_pgData        The partial good data.
     *
     * @return bool               This returns false when in non-SMP mode and
     *                            the NPU is non-functional.
     */
    bool ObusBrickSpecialRule(const TARGETING::TargetHandle_t &i_desc,
                              const uint16_t i_pgData[]);

    /*
     * @brief A special rule function for EQ targets. This will check the
     *        L3/L2/REFR triplets in the PG EPx data.
     *
     * @param[in] i_desc          A pointer to the current target that this
     *                            function has been called for.
     *
     * @param[in] i_pgData        The partial good data.
     *
     * @return bool               The triplets are valid if they are all 0 or
     *                            all 1.
     */
    bool EQSpecialRule(const TARGETING::TargetHandle_t &i_desc,
                       const uint16_t i_pgData[]);

    struct PartialGoodRulesTable
    {

        ~PartialGoodRulesTable();

        /**
         * @brief This function will lookup the list of applicable rules for the
         *        given target and return them as a vector of PartialGoodLogic.
         *        This function should always return a vector of size >= 1. If
         *        that isn't the case then an error will be returned by this
         *        function.
         *
         * @param[in]  i_target        The target to find pg rules for.
         *
         * @param[out] o_pgLogic       A vector of PartialGoodLogic structs
         *                             representing the list of applicable rules
         *                             used to verify if a target is functional
         *                             or not.
         *
         * @return errlHndl_t          An error that occured while getting pg
         *                             logic or nullptr.
         */
        errlHndl_t
            findRulesForTarget(const TARGETING::TargetHandle_t &i_target,
                               pgLogic_t &o_pgLogic) const;

    private:
        // A map that will hold all of the PG rules for all targets. If a target
        // doesn't have a pg checking logic or special rules it will still be
        // represented in this map because the generic algorithm will consider
        // an empty returned array to be an error. This will ensure that the
        // pgRules_map is kept up-to-date.
        // KEY: The target type for which the PG rules apply to.
        // VALUE: A vector of PartialGoodRule structs.
        //
        std::map<TARGETING::TYPE, pgRules_t> pgRules_map
        {
            // This is the form of a Partial Good Rule definition in the map.
            // Since PredicatePostfixExpr has assignment disabled, the
            // applicable chip types for a rule must be supplied as a vector of
            // pointers to constant defined PredicateCTMs. The constructor for
            // PartialGoodRule will handle adding them to the expr stack for its
            // iv_applicableChipTypes member.
            { TARGETING::TYPE_CORE,
                {// Start of pgRules_t vector
                    // EC Rule 1: Check all bits in the ECxx entry.
                    new PartialGoodRule
                    (
                        // The first parameter to the PartialGoodRule
                        // constructor is the vector of PredicateCTM references.
                        // In this case this rule applies to all power 9
                        // processors. So it's the vector of all P9 predicates.
                        PREDICATE_P9,            // Applicable Chip Types.
                        ALL_ON_PG_MASK,          // Partial Good Mask
                        EC_R1_AG_MASK,           // All Good Mask
                        USE_CHIPLET_ID,          // Partial Good Index
                        APPLICABLE_TO_ALL,       // Applicable Chip Units
                        NO_SPECIAL_RULE          // Special Rule Function Ptr
                    ),
                }// End of PG Rules for EC Target
            },
            // DMI: This target doesn't have any PG checking logic. It is
            //      considered functional if its parent is functional. However,
            //      it must still be represented in the map. So we create a
            //      pgRules_t with a single element using the PartialGoodRule()
            //      constructor that will create a rule that is essentially a
            //      NOOP. When this target type is encountered in
            //      HWAS::isDescFunctional, a lookup will return this rule which
            //      will cause the function to execute successfully.
            { TARGETING::TYPE_DMI, {new PartialGoodRule(),}},
            { TARGETING::TYPE_EQ,
                {
                    // EQ Rule 1: Check all bits in the EPx entry. This rule has
                    //            a special rule to validate the triplets in the
                    //            partial good region.
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        EQ_R1_PG_MASK,
                        EQ_R1_AG_MASK,
                        USE_CHIPLET_ID,
                        APPLICABLE_TO_ALL,
                        EQSpecialRule
                    ),
                }// End of PG Rules for EQ Target
            },
            { TARGETING::TYPE_EX,
                {
                    // EX Rule 1: Only applicable to even numbered chip units
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        EX_R1_PG_MASK,
                        ALL_OFF_AG_MASK,
                        USE_CHIPLET_ID,
                        EX_R1_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                    // EX Rule 2: Only applicable to odd numbered chip units
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        EX_R2_PG_MASK,
                        ALL_OFF_AG_MASK,
                        USE_CHIPLET_ID,
                        EX_R2_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                }// End of PG Rules for EX Target
            },
            { TARGETING::TYPE_MC,
                {
                    // MC Rule 1
                    new PartialGoodRule
                    (
                        {&PREDICATE_CUMULUS, &PREDICATE_AXONE},
                        ALL_ON_PG_MASK,
                        MC_R1_AG_MASK,
                        USE_CHIPLET_ID,
                        APPLICABLE_TO_ALL,
                        NO_SPECIAL_RULE
                    ),
                    // MC Rule 2: Chiplet N1 must be checked for chip unit 1
                    new PartialGoodRule
                    (
                        {&PREDICATE_CUMULUS, &PREDICATE_AXONE},
                        MC_R2_PG_MASK,
                        ALL_OFF_AG_MASK,
                        N1_PG_INDEX,
                        ONE_BIT_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                    // MC Rule 3: Chiplet N3 must be checked for chip unit 0
                    new PartialGoodRule
                    (
                        {&PREDICATE_CUMULUS, &PREDICATE_AXONE},
                        MC_R3_PG_MASK,
                        ALL_OFF_AG_MASK,
                        N3_PG_INDEX,
                        ZERO_BIT_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                }// End of PG Rules for MC Target
            },
            { TARGETING::TYPE_MCA,
                {
                    // MCA Rule 1: For chip units 0-3
                    //             However, since there is a special requirement
                    //             that the first MCA (mca0 or mca4) must be
                    //             functional it is applicable to all chip units
                    new PartialGoodRule
                    (
                        {&PREDICATE_NIMBUS},
                        MCA_R1_PG_MASK,
                        ALL_OFF_AG_MASK,
                        USE_CHIPLET_ID,
                        APPLICABLE_TO_ALL,
                        NO_SPECIAL_RULE
                    ),
                    // MCA Rule 2: For chip units 4-7
                    new PartialGoodRule
                    (
                        {&PREDICATE_NIMBUS},
                        MCA_R2_PG_MASK,
                        ALL_OFF_AG_MASK,
                        USE_CHIPLET_ID,
                        MCA_R2_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                }// End of PG Rules for MCA Target
            },
            { TARGETING::TYPE_MCBIST,
                {
                    // MCBIST Rule 1
                    new PartialGoodRule
                    (
                        {&PREDICATE_NIMBUS},
                        MCBIST_R1_PG_MASK,
                        MCBIST_R1_AG_MASK,
                        USE_CHIPLET_ID,
                        APPLICABLE_TO_ALL,
                        NO_SPECIAL_RULE
                    ),
                }// End of PG Rules for MCBIST Target
            },
            { TARGETING::TYPE_MCC, {new PartialGoodRule(),}},
            { TARGETING::TYPE_MCS,
                {
                    // MCS Rule 1: For chip units 0 and 1. Check MCS01
                    new PartialGoodRule
                    (
                        {&PREDICATE_NIMBUS},
                        MCS_R1_PG_MASK,
                        ALL_OFF_AG_MASK,
                        N3_PG_INDEX,
                        MCS_R1_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                    // MCS Rule 2: For chip units 2 and 3. Check MCS23
                    new PartialGoodRule
                    (
                        {&PREDICATE_NIMBUS},
                        MCS_R2_PG_MASK,
                        ALL_OFF_AG_MASK,
                        N1_PG_INDEX,
                        MCS_R2_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                    // MCS Rule 3: For chip units 0 and 2. Check bits in the
                    //             MCxx entry including specific IOM bit, but
                    //             not the other bits in the partial good
                    //             region.
                    new PartialGoodRule
                    (
                        {&PREDICATE_NIMBUS},
                        MCS_R3_PG_MASK,
                        MCS_ALL_GOOD_MASK,
                        USE_CHIPLET_ID,
                        MCS_R3_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                    // MCS Rule 4: For chip units 1 and 3. Check bits in the
                    //             MCxx entry including specific IOM bit, but
                    //             not the other bits in the partial good
                    //             region.
                    new PartialGoodRule
                    (
                        {&PREDICATE_NIMBUS},
                        MCS_R4_PG_MASK,
                        MCS_ALL_GOOD_MASK,
                        USE_CHIPLET_ID,
                        MCS_R4_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                }// End of PG Rules for MCS Target
            },
            { TARGETING::TYPE_MI, {new PartialGoodRule(),}},
            { TARGETING::TYPE_NPU,
                {
                    // NPU Rule 1: This logic is for Cumulus and Nimbus only.
                    new PartialGoodRule
                    (
                        {&PREDICATE_CUMULUS, &PREDICATE_NIMBUS},
                        NPU_R1_PG_MASK,
                        ALL_OFF_AG_MASK,
                        USE_CHIPLET_ID,
                        APPLICABLE_TO_ALL,
                        NO_SPECIAL_RULE
                    ),
                }// End of PG Rules for NPU Target
            },
            { TARGETING::TYPE_OBUS,
                {
                    // OBUS Rule 1
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        ALL_ON_PG_MASK,
                        OBUS_R1_AG_MASK,
                        USE_CHIPLET_ID,
                        APPLICABLE_TO_ALL,
                        NO_SPECIAL_RULE
                    ),
                    // OBUS Rule 2: pbioo0 unit on chiplet N1 must be
                    //              checked for all OBUSes
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        OBUS_R2_PG_MASK,
                        ALL_OFF_AG_MASK,
                        N1_PG_INDEX,
                        APPLICABLE_TO_ALL,
                        NO_SPECIAL_RULE
                    ),
                    // OBUS Rule 3: pbioo1 unit on chiplet N3 must be checked
                    //              for Cumulus OBUSes (chip unit 1 and 2).
                    new PartialGoodRule
                    (
                        {&PREDICATE_CUMULUS},
                        OBUS_R3_PG_MASK,
                        ALL_OFF_AG_MASK,
                        N3_PG_INDEX,
                        OBUS_R3_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                }// End of PG Rules for OBUS Target
            },
            { TARGETING::TYPE_OBUS_BRICK,
                {
                    // OBUS BRICK Rule 1: This applies only to Nimbus and
                    //                    Cumulus. OBUS BRICK is considered
                    //                    non-functional if the NPU is
                    //                    non-functional and if OBUS is
                    //                    in non-SMP mode.
                    //                    The Obus Brick also requires a
                    //                    functional parent Obus to be
                    //                    considered functional. However,
                    //                    HWAS::markChildrenNonFunctional() will
                    //                    take care of that requirement instead
                    //                    of that rule being explictly defined
                    //                    here.
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        MASK_NA,
                        MASK_NA,
                        INDEX_NA,
                        APPLICABLE_TO_ALL,
                        ObusBrickSpecialRule
                    ),
                }// End of PG Rules for OBUS BRICK Target
            },
            { TARGETING::TYPE_OMI, {new PartialGoodRule(),}},
            { TARGETING::TYPE_OMIC, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PEC,
                {
                    // PEC Rule 1: Applies to chip unit 0. Check PCI0
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        ALL_ON_PG_MASK,
                        PEC_R1_AG_MASK,
                        USE_CHIPLET_ID,
                        ZERO_BIT_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                    // PEC Rule 2: Applies to chip unit 1. Check PCI1
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        ALL_ON_PG_MASK,
                        PEC_R2_AG_MASK,
                        USE_CHIPLET_ID,
                        ONE_BIT_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                    // PEC Rule 3: Applies to chip unit 2. Check PCI2
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        ALL_ON_PG_MASK,
                        PEC_R3_AG_MASK,
                        USE_CHIPLET_ID,
                        TWO_BIT_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                }
            },
            { TARGETING::TYPE_PERV,
                {
                    // PERV Rule 1: Check Vital bit
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        PERV_R1_PG_MASK,
                        ALL_OFF_AG_MASK,
                        USE_CHIPLET_ID,
                        APPLICABLE_TO_ALL,
                        PervSpecialRule
                    ),
                }// End of PG Rules for PERV Target
            },
            { TARGETING::TYPE_PHB, {new PartialGoodRule(),}},
            { TARGETING::TYPE_XBUS,
                {
                    // XBUS Rule 1: Applies to chip unit 0 which is not
                    //              present on Nimbus.
                    new PartialGoodRule
                    (
                        {&PREDICATE_CUMULUS, &PREDICATE_AXONE},
                        XBUS_R1_PG_MASK,
                        ALL_OFF_AG_MASK,
                        USE_CHIPLET_ID,
                        ZERO_BIT_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                    // XBUS Rule 2: Applies to chip unit 1
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        XBUS_R2_PG_MASK,
                        ALL_OFF_AG_MASK,
                        USE_CHIPLET_ID,
                        ONE_BIT_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                    // XBUS Rule 3: Applies to chip unit 2
                    new PartialGoodRule
                    (
                        PREDICATE_P9,
                        XBUS_R3_PG_MASK,
                        ALL_OFF_AG_MASK,
                        USE_CHIPLET_ID,
                        TWO_BIT_CU_MASK,
                        NO_SPECIAL_RULE
                    ),
                }// End of PG Rules for XBUS Target
            },
            { TARGETING::TYPE_NA, {new PartialGoodRule(),}},
            { TARGETING::TYPE_SYS, {new PartialGoodRule(),}},
            { TARGETING::TYPE_NODE, {new PartialGoodRule(),}},
            { TARGETING::TYPE_DIMM, {new PartialGoodRule(),}},
            { TARGETING::TYPE_MEMBUF, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PROC, {new PartialGoodRule(),}},
            { TARGETING::TYPE_L2, {new PartialGoodRule(),}},
            { TARGETING::TYPE_L3, {new PartialGoodRule(),}},
            { TARGETING::TYPE_L4, {new PartialGoodRule(),}},
            { TARGETING::TYPE_MBA, {new PartialGoodRule(),}},
            { TARGETING::TYPE_ABUS, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PCI, {new PartialGoodRule(),}},
            { TARGETING::TYPE_DPSS, {new PartialGoodRule(),}},
            { TARGETING::TYPE_APSS, {new PartialGoodRule(),}},
            { TARGETING::TYPE_OCC, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PSI, {new PartialGoodRule(),}},
            { TARGETING::TYPE_FSP, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PNOR, {new PartialGoodRule(),}},
            { TARGETING::TYPE_OSC, {new PartialGoodRule(),}},
            { TARGETING::TYPE_TODCLK, {new PartialGoodRule(),}},
            { TARGETING::TYPE_CONTROL_NODE, {new PartialGoodRule(),}},
            { TARGETING::TYPE_OSCREFCLK, {new PartialGoodRule(),}},
            { TARGETING::TYPE_OSCPCICLK, {new PartialGoodRule(),}},
            { TARGETING::TYPE_REFCLKENDPT, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PCICLKENDPT, {new PartialGoodRule(),}},
            { TARGETING::TYPE_NX, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PORE, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PCIESWITCH, {new PartialGoodRule(),}},
            { TARGETING::TYPE_CAPP, {new PartialGoodRule(),}},
            { TARGETING::TYPE_FSI, {new PartialGoodRule(),}},
            { TARGETING::TYPE_SBE, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PPE, {new PartialGoodRule(),}},
            { TARGETING::TYPE_SYSREFCLKENDPT, {new PartialGoodRule(),}},
            { TARGETING::TYPE_MFREFCLKENDPT, {new PartialGoodRule(),}},
            { TARGETING::TYPE_TPM, {new PartialGoodRule(),}},
            { TARGETING::TYPE_SP, {new PartialGoodRule(),}},
            { TARGETING::TYPE_UART, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PS, {new PartialGoodRule(),}},
            { TARGETING::TYPE_FAN, {new PartialGoodRule(),}},
            { TARGETING::TYPE_VRM, {new PartialGoodRule(),}},
            { TARGETING::TYPE_USB, {new PartialGoodRule(),}},
            { TARGETING::TYPE_ETH, {new PartialGoodRule(),}},
            { TARGETING::TYPE_PANEL, {new PartialGoodRule(),}},
            { TARGETING::TYPE_BMC, {new PartialGoodRule(),}},
            { TARGETING::TYPE_FLASH, {new PartialGoodRule(),}},
            { TARGETING::TYPE_SEEPROM, {new PartialGoodRule(),}},
            { TARGETING::TYPE_TMP, {new PartialGoodRule(),}},
            { TARGETING::TYPE_GPIO_EXPANDER, {new PartialGoodRule(),}},
            { TARGETING::TYPE_POWER_SEQUENCER, {new PartialGoodRule(),}},
            { TARGETING::TYPE_RTC, {new PartialGoodRule(),}},
            { TARGETING::TYPE_FANCTLR, {new PartialGoodRule(),}},
            { TARGETING::TYPE_TEST_FAIL, {new PartialGoodRule(),}},
            { TARGETING::TYPE_MFREFCLK, {new PartialGoodRule(),}},
            { TARGETING::TYPE_SMPGROUP, {new PartialGoodRule(),}},
            { TARGETING::TYPE_OCMB_CHIP, {new PartialGoodRule(),}},
            { TARGETING::TYPE_MEM_PORT, {new PartialGoodRule(),}},
            { TARGETING::TYPE_I2C_MUX, {new PartialGoodRule(),}},
            { TARGETING::TYPE_LAST_IN_RANGE, {new PartialGoodRule(),}},
            // End of pgRules_map Rules
        };
    };

    // Due to the size of the PartialGoodRulesTable a static version is declared
    // to reduce overhead associated with creating one.
    extern const PartialGoodRulesTable pgTable;

}

#endif
