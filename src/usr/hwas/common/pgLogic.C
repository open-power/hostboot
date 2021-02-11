/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/pgLogic.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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

#include <array>
#include <iterator>
#include <stdio.h>

using namespace HWAS::COMMON;

namespace PARTIAL_GOOD
{
    // Target Type Masks
    // PG Masks are created such that:
    //      pgData[ pgIndex ] & pgMask
    // produces the AG Mask defined for that rule. They are defined to cover the
    // set of bits that a target type covers. The AG masks were defined either
    // by directly using the provided AG mask listed in the MVPD PG Mapping
    // Table or were chosen to check the specific bits a target type covers.
    // Naming convention for masks is as follows:
    // TargetType_RuleNumber_MaskType_MASK
    //
    //  Mask Types: PG = Partial Good
    //              AG = All Good
    //              CU = Applicable Chip Units

    // Checks the perv, ioo, pdl/odl, and pllaxon bits of the IOHS PGV entry.
    // Note that this bitmask does NOT check the partial-good NDL bit of the
    // entry as NVLINK was dropped for P10.
    const pg_mask_t IOHS_R1_PG_MASK = 0x000C4200;

    // Checks the EC+L2, L3 and MMA units of the EC PGV entry for core A in an
    // EQ chiplet..
    const pg_mask_t EC_R1_PG_MASK = 0x00044100;

    // Each subsequent EC mask is shifted right by one because the bits are in
    // three interleaved regions (i.e. ...ABCD...ABCD...ABCD...) where the
    // groups are EC+L2, L3, and MMA, and the letters represent bits that are
    // part of the same CORE).
    const pg_mask_t EC_R2_PG_MASK = EC_R1_PG_MASK >> 1;
    const pg_mask_t EC_R3_PG_MASK = EC_R1_PG_MASK >> 2;
    const pg_mask_t EC_R4_PG_MASK = EC_R1_PG_MASK >> 3;

    // The All-Good mask for the EC units. The EC PG mask only checks bits
    // pertaining to the core itself, so all of them should be GOOD (0).
    const pg_mask_t EC_AG_MASK = 0;

    // There are four different EC PG masks, each applicable to every fourth
    // core starting from offsets 0, 1, 2 and 3. The documentation refers to
    // cores A, B, C and D for each EQ; core CU 0 is A, 1 is B, etc.
    const cu_mask_t EC_R1_CU_MASK = 0x1111111111111111ull; // core A mask

    // Shift core A's mask left to get masks for the other sets of cores
    const cu_mask_t EC_R2_CU_MASK = EC_R1_CU_MASK << 1; // core B mask
    const cu_mask_t EC_R3_CU_MASK = EC_R1_CU_MASK << 2; // core C
    const cu_mask_t EC_R4_CU_MASK = EC_R1_CU_MASK << 3; // core D

    // Checks the perv, mc_emo, dl01, dl23, ioo0, ioo1, and pllmc bits of the
    // MC.
    const pg_mask_t MC_PG_MASK = 0x000DE200;

    // Checks the perv, qme, and clkadj bits of the EQ chiplet PG rows. Does not
    // check EC data because those are in their own targets.
    const pg_mask_t EQ_PG_MASK = 0x00080600;

    // Checks the pau bit of a PAUC entry. This mask is applicable for PAU with
    // CU = 0, 3, 4, or 6.
    const pg_mask_t PAU_R1_PG_MASK = 0x00040000;

    // This mask is applicable for PAU with CU = 5 or 7.
    const pg_mask_t PAU_R2_PG_MASK = 0x00020000;

    // PAU rule 1 applies to CUs 0, 3, 4, 6
    const cu_mask_t PAU_R1_CU_MASK = (  cu_mask(0)
                                      | cu_mask(3)
                                      | cu_mask(4)
                                      | cu_mask(6));

    // PAU rule 2 applies to CUs 5, 7
    const cu_mask_t PAU_R2_CU_MASK = (  cu_mask(5)
                                      | cu_mask(7));

    // The VITAL bit of each chiplet is checked by a separate PERV target
    // instance.
    const pg_mask_t PERV_BIT_PG_MASK = 0x00100000;

    // Check the perv, ph5, pcs0, pcs1, pcs2, pcs3, psm0, psm1, pllpci, pma0,
    // pma1, pma2, and pma3 bits of the PCI PGV entry.
    const pg_mask_t PEC_PG_MASK = 0x000FF3E0;

    /// Special Masks that are applicable to many rules

    // This mask is common to many rules because in most cases we are checking
    // specific bits and don't care about the rest. To detect a problem with
    // only those bits we provide an AG mask of all zeroes.
    const pg_mask_t ALL_OFF_AG_MASK               = 0x00000000;

    // Used in place of a chip unit mask to indicate that the rule is applicable
    // for all values a chip unit can take.
    const cu_mask_t APPLICABLE_TO_ALL_CU          = UINT64_MAX;

    // Used in place of a PG index to indicate that the target's associated
    // chiplet id is the correct way to index the PG vector.
    const uint8_t USE_CHIPLET_ID                  = 0xFF;

    // Used when a target type has no applicable partial good checking logic.
    // Instead of omitting that target type from the map of rules, it will have:
    //      agMask == ALL_OFF_AG_MASK
    //      pgIndex == PG_INDEX_NA
    // This lets us error out when there are no rules defined for a target.
    const pg_mask_t PG_MASK_NA                   = 0x00000000;
    const pg_idx_t PG_INDEX_NA                   = 0xFE;

    // This enumeration provides a mask for each processor model we want to
    // support to have their own special PG rules (models in p9 were nimbus,
    // cumulus, etc. and for p10 there's just the one). Each mask must have
    // exactly one bit set and the masks must not overlap each other (excepting
    // MODEL_MASK_ALL). To add support for a new processor model, two things
    // have to be updated:
    // 1. Add a member to this enumeration with the value being an unused bitmask
    // 2. Add an entry to model_lookup_table below
    enum model_mask_t : uint32_t
    {
        MODEL_MASK_NONE    = 0,
        MODEL_MASK_POWER10 = 1u << 0,
        MODEL_MASK_ALL     = ~0u
    };

    // This structure pairs model types with model masks for lookup.
    struct model_to_model_mask
    {
        TARGETING::ATTR_MODEL_type model;
        model_mask_t model_mask;
    };

    // This table contains the associations between model types and their model
    // masks. To add support for a new model, two things must be updated:
    // 1. Add a member to the model_mask_t enumeration above
    // 2. Add an entry to model_lookup_table below associating the new model
    //    mask with the new model type constant
    const std::array<model_to_model_mask, 1> model_lookup_table =
    {
        { TARGETING::MODEL_POWER10, MODEL_MASK_POWER10 }
    };

    // Given a model type, return the model mask associated with it or else
    // MODEL_MASK_NONE if there is no association.
    static const model_mask_t lookup_model_mask(const TARGETING::ATTR_MODEL_type model)
    {
        model_mask_t mask = MODEL_MASK_NONE;

        for (auto it = model_lookup_table.begin();
             it != model_lookup_table.end();
             it++)
        {
            if (it->model == model)
            {
                mask = it->model_mask;
                break;
            }
        }

        return mask;

    }

    constexpr PartialGoodRule::specialRuleFuncPtr_t NO_SPECIAL_RULE = nullptr;

    constexpr PartialGoodRule::PartialGoodRule(const TARGETING::TYPE i_type)
        : iv_type(i_type),
          iv_applicableModelMask(MODEL_MASK_ALL),
          iv_pgMask(PG_MASK_NA),
          iv_agMask(PG_MASK_NA),
          iv_pgIndex(PG_INDEX_NA),
          iv_applicableChipUnits(APPLICABLE_TO_ALL_CU),
          iv_specialRule(NO_SPECIAL_RULE)
    {
    }

    constexpr PartialGoodRule::PartialGoodRule
    (
        const TARGETING::TYPE i_type,
        const model_mask_t i_modelMask,
        const pg_mask_t i_pgMask,
        const pg_mask_t i_agMask,
        const pg_idx_t i_pgIndex,
        const cu_mask_t i_appChipUnits,
        const PartialGoodRule::specialRuleFuncPtr_t i_rule
    )
    : iv_type(i_type),
      iv_applicableModelMask(i_modelMask),
      iv_pgMask(i_pgMask),
      iv_agMask(i_agMask),
      iv_pgIndex(i_pgIndex),
      iv_applicableChipUnits(i_appChipUnits),
      iv_specialRule(i_rule)
    {
    }

    static TARGETING::TargetHandle_t getMasterProcChipTargetHandle()
    {
        TARGETING::TargetHandle_t l_handle = nullptr;

        TARGETING::targetService().masterProcChipTargetHandle(l_handle);

        HWAS_ASSERT(l_handle, "getMasterProcChipTargetHandle: couldn't get "
                              "master proc.");

        return l_handle;
    }

    bool PartialGoodRule::isApplicableToCurrentModel() const
    {
        bool l_isApplicable = false;

        if (iv_applicableModelMask == MODEL_MASK_ALL )
        {
            l_isApplicable = true;
        }
        else
        {
            // Querying the master proc chip target is expensive so we cache the
            // info we need from it (our current model)
            static const auto current_model =
                getMasterProcChipTargetHandle()->getAttr<TARGETING::ATTR_MODEL>();

            const auto current_model_mask = lookup_model_mask(current_model);

            l_isApplicable = current_model_mask & iv_applicableModelMask;
        }

        return l_isApplicable;
    }

    bool PartialGoodRule::isApplicableToChipUnit(const uint8_t i_chipUnit) const
    {
        // A PartialGoodRule is applicable for a chip unit if the result of the
        // bit-wise & is nonzero. This allows the special chip unit mask
        // APPLICABLE_TO_ALL_CU to function correctly.
        return iv_applicableChipUnits & cu_mask(i_chipUnit);
    }

    bool PartialGoodRule::useChipletIdAsIndex() const
    {
        return iv_pgIndex == USE_CHIPLET_ID;
    }

    pg_idx_t PartialGoodRule::getRealPgIndex(
        const TARGETING::TargetHandle_t& i_desc
    ) const
    {
        if (useChipletIdAsIndex())
        {
            return i_desc->getAttr<TARGETING::ATTR_CHIPLET_ID>();
        }

        return iv_pgIndex;
    }

    bool PartialGoodRule::isFunctional(
        const TARGETING::TargetHandle_t& i_desc,
        const HWAS::partialGoodVector& i_pgData
    ) const
    {
        bool l_functional = true;
        const pg_idx_t l_pgIndex = getRealPgIndex(i_desc);

        if (l_pgIndex != PG_INDEX_NA
            && (i_pgData[l_pgIndex] & iv_pgMask) != iv_agMask)
        {
            l_functional = false;
        }
        else if (iv_specialRule)
        {
            l_functional = iv_specialRule(i_desc, i_pgData);
        }

        return l_functional;
    }

    void PartialGoodRule::formatDebugMessage(
        const TARGETING::TargetHandle_t& i_desc,
        const HWAS::partialGoodVector& i_pgData,
        char* const buffer,
        const size_t bufsize
    ) const
    {
        if (getRealPgIndex(i_desc) == PG_INDEX_NA)
        {
            snprintf(buffer, bufsize,
                     "PG data not applicable; "
                     "special rule = ");
        }
        else
        {
            snprintf(buffer, bufsize,
                     "(pgData[%d] = 0x%08x) & 0x%08X: "
                     "actual 0x%08X, expected 0x%08X; "
                     "special rule = ",
                     getRealPgIndex(i_desc),
                     i_pgData[getRealPgIndex(i_desc)],
                     iv_pgMask,
                     i_pgData[getRealPgIndex(i_desc)] & iv_pgMask,
                     iv_agMask);
        }

        const size_t l_filled = bufsize ? strlen(buffer) : 0;

        if (iv_specialRule)
        {
            snprintf(buffer + l_filled,
                     bufsize - l_filled,
                     "%d",
                     iv_specialRule(i_desc, i_pgData));
        }
        else
        {
            strncat(buffer, "NA", bufsize - l_filled - 1);
        }

    }

    // The special rule for the PERV targets checks the "vital" bit (not the
    // "perv" bit) for its corresponding chip.
    bool PervSpecialRule(const TARGETING::TargetHandle_t &i_desc,
                         const HWAS::partialGoodVector& i_pgData)
    {
        HWAS_ASSERT((i_desc->getAttr<TARGETING::ATTR_TYPE>()
                     == TARGETING::TYPE_PERV),
                    "PervSpecialRule: i_desc type != TYPE_PERV");

        // The chip unit number of the perv target is the index into the PG data
        const auto indexPERV = i_desc->getAttr<TARGETING::ATTR_CHIP_UNIT>();

        const pg_entry_t l_pg = i_pgData[indexPERV];

        // Store the original PG VPD entry in the PERV's PG_MVPD attribute
        i_desc->setAttr<TARGETING::ATTR_PG_MVPD>(l_pg);

        return !(l_pg & PERV_BIT_PG_MASK);
    }

    // This is the table which associates target types to rules to determine
    // whether or not a given instance of the target type is functional in
    // itself (not taking into account the functionality of parents or children;
    // that information is propagated by a different part of the PG algorithm).
    //
    // The structure of this table is such that:
    // 1. It is in sorted order keyed by the target type
    // 2. Placing entries consecutively with the same target type has the effect
    //    of creating multiple rules for that target type which (for each rule
    //    that is applicable to the chip unit and model) must ALL succeed for
    //    the target to be considered functional (i.e. the rules form a logical
    //    conjunction for that target type).
    static constexpr std::array<PartialGoodRule, 29> pgRules_map
    {
        // SYS: This target doesn't have any PG checking logic. It is considered
        //      functional if its children (and parent, if a target has a
        //      parent) are functional. However, it must still be represented in
        //      the map. So we create a single empty PartialGoodRule using the
        //      PartialGoodRule(TARGETING::TYPE) constructor that will create a
        //      rule that is essentially a NOOP. When this target type is
        //      encountered in HWAS::isDescFunctional, a lookup will return this
        //      rule which will cause the function to execute successfully.
        PartialGoodRule          // The first element of pgRules_map must have
        { TARGETING::TYPE_SYS }, // an explicit type to dictate the type of this
                                 // initializer_list; the rest can be inferred.

        { TARGETING::TYPE_NODE },
        { TARGETING::TYPE_DIMM },
        { TARGETING::TYPE_PROC },

        /// TYPE_CORE rules

        // This is the form of a full PartialGoodRule definition in the map.
        { TARGETING::TYPE_CORE,
          MODEL_MASK_ALL,   // Applicable models mask (logical OR of one or more
                            // MODEL_MASK_XXX values)
          EC_R1_PG_MASK,    // Partial Good Mask
          ALL_OFF_AG_MASK,  // All Good Mask
          USE_CHIPLET_ID,   // Partial Good Index
          EC_R1_CU_MASK,    // Applicable Chip Units (this is the rule for
                            // "Core A" (refer to PG docs))
          NO_SPECIAL_RULE   // Special Rule Function Ptr
        },

        { TARGETING::TYPE_CORE,
          MODEL_MASK_ALL,
          EC_R2_PG_MASK,
          ALL_OFF_AG_MASK,
          USE_CHIPLET_ID,
          EC_R2_CU_MASK, // Core B rule
          NO_SPECIAL_RULE
        },

        { TARGETING::TYPE_CORE,
          MODEL_MASK_ALL,
          EC_R3_PG_MASK,
          ALL_OFF_AG_MASK,
          USE_CHIPLET_ID,
          EC_R3_CU_MASK, // Core C rule
          NO_SPECIAL_RULE
        },

        { TARGETING::TYPE_CORE,
          MODEL_MASK_ALL,
          EC_R4_PG_MASK,
          ALL_OFF_AG_MASK,
          USE_CHIPLET_ID,
          EC_R4_CU_MASK, // Core D rule
          NO_SPECIAL_RULE
        },

        /// end TYPE_CORE rules

        { TARGETING::TYPE_OCC },

        { TARGETING::TYPE_NX },

        // The EQs are always-good
        { TARGETING::TYPE_EQ },

        { TARGETING::TYPE_MI },
        { TARGETING::TYPE_DMI },

        // PERV is always-good
        { TARGETING::TYPE_PERV,
          MODEL_MASK_ALL,
          PERV_BIT_PG_MASK, // We still put this here because this data
                            // structure is also used to forcibly set ATTR_PG
                            // bits to "bad"
          ALL_OFF_AG_MASK,
          PG_INDEX_NA, // This is unused; the PERV targets use their chip unit
                       // to index into the PG data to check the "vital" (*not*
                       // the "perv") bit of their respective chiplet
          APPLICABLE_TO_ALL_CU,
          PervSpecialRule },

        // PEC chiplets are representative of the PCI chiplets.
        { TARGETING::TYPE_PEC,
          MODEL_MASK_ALL,
          PEC_PG_MASK,
          ALL_OFF_AG_MASK,
          USE_CHIPLET_ID,
          APPLICABLE_TO_ALL_CU,
          NO_SPECIAL_RULE },

        // PHB have no PG bits
        { TARGETING::TYPE_PHB },

        { TARGETING::TYPE_MC,
          MODEL_MASK_ALL,
          MC_PG_MASK,
          ALL_OFF_AG_MASK,
          USE_CHIPLET_ID,
          APPLICABLE_TO_ALL_CU,
          NO_SPECIAL_RULE
        },

        { TARGETING::TYPE_SMPGROUP },
        { TARGETING::TYPE_OMI },
        { TARGETING::TYPE_MCC },
        { TARGETING::TYPE_OMIC },
        { TARGETING::TYPE_OCMB_CHIP },
        { TARGETING::TYPE_MEM_PORT },

        // The NMMU is marked always-good in an always-good chiplet in
        // the PGV so we don't need to check anything.
        { TARGETING::TYPE_NMMU },

        /// PAU rules

        { TARGETING::TYPE_PAU,
          MODEL_MASK_ALL,
          PAU_R1_PG_MASK,
          ALL_OFF_AG_MASK,
          USE_CHIPLET_ID,
          PAU_R1_CU_MASK,
          NO_SPECIAL_RULE
        },

        { TARGETING::TYPE_PAU,
          MODEL_MASK_ALL,
          PAU_R2_PG_MASK,
          ALL_OFF_AG_MASK,
          USE_CHIPLET_ID,
          PAU_R2_CU_MASK,
          NO_SPECIAL_RULE
        },

        /// end PAU rules

        { TARGETING::TYPE_IOHS,
          MODEL_MASK_ALL,
          IOHS_R1_PG_MASK,
          ALL_OFF_AG_MASK,
          USE_CHIPLET_ID,
          APPLICABLE_TO_ALL_CU,
          NO_SPECIAL_RULE
        },

        // PAUC are always-good
        { TARGETING::TYPE_PAUC },

        // FC have no PG bits
        { TARGETING::TYPE_FC },
    }; // End of pgRules_map Rules

// @TODO RTC 249996 remove ifdef once fips compiler supports C++14 and beyond
#ifdef __HOSTBOOT_MODULE
    // A helper function to determine whether a sequence of rules is sorted with
    // respect to target type.
    template<typename It>
    static constexpr bool is_sorted(const It begin, const It end)
    {
        // Unfortunately pre-c++14 constexpr functions had to consist of exactly
        // one return statement, hence the nested ternary here.
        return (begin == end || begin + 1 == end
                ? true
                : (begin->type() > (begin+1)->type()
                   ? false
                   : is_sorted(begin + 1, end)));

    }

    // Statically enforce the requirement that the PG rules map is in sorted
    // order, because we binary search it.
    static_assert(is_sorted(pgRules_map.cbegin(), pgRules_map.cend()),
                  "PG rules map must be in sorted order");
#endif // @TODO RTC 249996


    // @TODO RTC 249996 Drop this overloaded operator
    bool PartialGoodRule::operator<(const TARGETING::TYPE rhs) const
    {
        return iv_type < rhs;
    }

    errlHndl_t findRulesForTarget(
            const TARGETING::ConstTargetHandle_t i_target,
            const PartialGoodRule*& o_pgRules,
            size_t& o_numPgRules
    )
    {
        using namespace TARGETING;

        errlHndl_t l_errl = nullptr;

        // We have no rules initially, then we will increment this below for
        // each rule that matches.
        o_numPgRules = 0;

        const auto l_targetType = i_target->getAttr<ATTR_TYPE>();

        // Lookup the target in the PG Rules Table
        auto l_rulesIterator
            = std::lower_bound(pgRules_map.cbegin(), pgRules_map.cend(),
                               l_targetType/*, @TODO RTC 249996 Uncomment
                               [](const PartialGoodRule& r, const TYPE t)
                               {
                                   return r.type() < t;
                               }*/);

        o_pgRules = &*l_rulesIterator;

        // Iterate through all of the pg rules and compose a list of
        // applicable rules based on chip unit and chip type.
        while (l_rulesIterator != pgRules_map.cend())
        {
            // There will be one or more rules that match the given target
            // type; once we reach a rule for a different target type, we
            // stop searching.
            if (l_rulesIterator->type() != l_targetType)
            {
                break;
            }

            if (l_rulesIterator->useChipletIdAsIndex())
            {
                const auto l_targetChipletId
                    = i_target->getAttr<ATTR_CHIPLET_ID>();

                if (l_targetChipletId >= HWAS::VPD_CP00_PG_DATA_ENTRIES)
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
                     * @custdesc        A problem occurred during IPL of
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

            ++o_numPgRules;
            ++l_rulesIterator;
        }

        // If o_pgRules has no entries then that means that there doesn't exist
        // any PG rules for the given target or another error was
        // encountered. If no other error occurred then return the the following
        // error if applicable.
        if ((l_errl == nullptr) && (o_numPgRules == 0))
        {
            /*@
            * @errortype
            * @severity        ERRL_SEV_UNRECOVERABLE
            * @moduleid        HWAS::MOD_FIND_RULES_FOR_TARGET
            * @reasoncode      HWAS::RC_NO_PG_LOGIC
            * @devdesc         To enforce all target types have partial good
            *                  rules and logic, all targets must be included
            *                  in the rules table. A combination
            *                  of target type, chip type, and chip unit
            *                  produced an empty set of logic for the
            *                  target.
            *
            * @custdesc        A problem occurred during IPL of the system:
            *                  Internal Firmware Error
            * @userdata1       target type attribute
            * @userdata2       HUID of the target
            */
            l_errl = hwasError(
                               ERRL_SEV_UNRECOVERABLE,
                               HWAS::MOD_FIND_RULES_FOR_TARGET,
                               HWAS::RC_NO_PG_LOGIC,
                               i_target->getAttr<TARGETING::ATTR_TYPE>(),
                               get_huid(i_target));
        }

        // If an error occurred, reset the output variables to error states.
        if (l_errl)
        {
            o_numPgRules = 0;
            o_pgRules = nullptr;
        }

        return l_errl;
    }
}
