/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/pgLogic.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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

#include <targeting/common/target.H>
#include <targeting/common/commontargeting.H>
#include <hwas/common/vpdConstants.H>

namespace PARTIAL_GOOD
{
    using HWAS::pg_entry_t;
    using HWAS::pg_idx_t;
    using HWAS::pg_mask_t;
    using HWAS::cu_mask_t;
    using HWAS::partialGoodVector;

    // This struct represents a "row" in the partial good rules map. It contains
    // all the information necessary to verify one or more rules for a target.
    struct PartialGoodRule
    {
        /**
         * @brief       This constructor should be used when adding a rule to
         *              the PG rules table that either doesn't have any
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
         * @param[in]   i_type        The target type this rule applies to
         *
         */
        constexpr PartialGoodRule(TARGETING::TYPE i_type);

        // This struct uses a function pointer to indicate that a special rule
        // for handling PG checking exists and that the function pointed to will
        // handle that rule.
        //
        // The special rule function should always return a boolean indicating
        // whether the given target is functional or not depending if the function
        // verified the rule successfully.
        typedef bool (*specialRuleFuncPtr_t)(
            const TARGETING::TargetHandle_t &i_desc,
            const partialGoodVector& i_pgData);

        // A model mask is a bitmask used to determine whether a rule applies to
        // a particular model of chip. See pgLogic.C for possible values.
        using model_mask_t = uint32_t;

        /**
         * @brief       This constructor should always be used when adding new
         *              rules to the partial good rules map whenever there is
         *              PG checking logic for a target.
         *
         * @param[in] i_type                The target type this rule applies to
         *
         * @param[in] i_modelMask           The mask for the chip models that
         *                                  this rule applies to (see pgLogic.C)
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
         * @param[in] i_rule                The special rule associated with
         *                                  this target that isn't represented
         *                                  in isDescFunctional. Since every
         *                                  PartialGoodRule is checked for a
         *                                  special rule it's only necessary to
         *                                  point to a unique special rule once.
         */
        constexpr PartialGoodRule(TARGETING::TYPE i_type,
                                  model_mask_t i_modelMask,
                                  pg_mask_t i_pgMask, pg_mask_t i_agMask,
                                  pg_idx_t i_pgIndex, cu_mask_t i_appChipUnits,
                                  specialRuleFuncPtr_t i_rule);
        /**
         * @brief     This function determines whether this rule is applicable to
         *            the given chip unit.
         *
         * @param[in] i_chipUnit the chip unit of a target to check
         *
         * @return bool Whether or not this PG rule applies to the given chip unit
         */
        bool isApplicableToChipUnit(uint8_t i_chipUnit) const;

        /**
         * @brief     This function determines whether this rule is applicable to
         *            the model of the current chip.
         *
         * @return bool Whether or not this PG rule applies to the model of the
         *              current chip.
         */
        bool isApplicableToCurrentModel() const;

        /**
         * @brief     This function determines whether the given target is functional
         *            according to the conditions described in this PG rule.
         *
         * @param[in] i_desc   The target to check
         *
         * @param[in] i_pgData The PG data to check against
         *
         * @return bool Whether or not the target is functional
         */
        bool isFunctional(
            const TARGETING::TargetHandle_t& i_desc,
            const partialGoodVector& i_pgData
        ) const;

        /**
         * @brief This is a helper function to determine if a target's chiplet
         *        id is the correct pg index for this rule.
         *
         * @return bool true if and only if the target's chiplet id is the
         *              correct pg index for this rule.
         */
        bool useChipletIdAsIndex() const;

        /**
         * @brief Writes diagnostic information to the given buffer, for use when
         *        the rule fails.
         *
         * @param[in] i_desc    The target to print info about
         *
         * @param[in] i_pgData  The PG data to reference
         *
         * @param[in] i_buffer  The buffer to store the debug string into
         *
         * @param[in] i_bufsize The size of the buffer in characters
         */
        void formatDebugMessage(
            const TARGETING::TargetHandle_t& i_desc,
            const partialGoodVector& i_pgData,
            char* i_buffer,
            size_t i_bufsize) const;


        /**
         * @brief Returns the target type to which this rule applies.
         *
         * @return TARGETING::TYPE The type of this rule's target.
         */
        constexpr TARGETING::TYPE type() const
        {
            return iv_type;
        }

    private:

        /**
         * @brief Returns the real index into the PGV (whether the stored index,
         *        or the chiplet ID, whichever is appropriate for this rule)
         *
         * @param[in] i_desc    The target to reference
         *
         * @return pg_idx_t The real PGV index
         */
        pg_idx_t getRealPgIndex(const TARGETING::TargetHandle_t& i_desc) const;

        // The type of the targets this rule applies to
        TARGETING::TYPE iv_type;

        // mask of all models that this rule applies to
        model_mask_t iv_applicableModelMask;

        // partial good mask
        // The mask to be applied to the partial good vector.
        pg_mask_t iv_pgMask;

        // all good mask
        // This mask is the expected result after the pgMask has been
        // bit-wise & with an entry in the partial good vector.
        pg_mask_t iv_agMask;

        // partial good index
        // Used to index into the partial good vector read from VPD.
        // For cases where the chiplet id should be used as an index into the
        // partial good vector it will be set to USE_CHIPLET_ID.
        pg_idx_t iv_pgIndex;

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
        cu_mask_t iv_applicableChipUnits;

        // A function pointer to a special case rule that cannot be covered by
        // the algorithm in HWAS::isDescFunctional(). This will almost always be
        // a nullptr. It should be used sparingly and only when absolutely
        // necessary.
        specialRuleFuncPtr_t iv_specialRule;
    };

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
    errlHndl_t findRulesForTarget(
        const TARGETING::TargetHandle_t &i_target,
        const PartialGoodRule*& o_pgRules,
        size_t& o_numPgRules
    );
}

#endif
