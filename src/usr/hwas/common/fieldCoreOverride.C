/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/fieldCoreOverride.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
#include <algorithm>

#include <sys/misc.h>

#include <hwas/common/fieldCoreOverride.H>
#include <hwas/common/deconfigGard.H> // DECONFIGURED_BY_FIELD_CORE_OVERRIDE
#include <hwas/common/hwas.H>
#include <hwas/hwasPlatTrace.H>

#include <targeting/common/utilFilter.H> // getChildChiplets()
#include <targeting/common/util.H> // is_fused_mode()

namespace FCO
{

// The chip team requires Hostboot to deconfigure each CORE for FCO in a priority order. That order is represented in
// this array. There are 32 cores in a P10 chip and therefore there are 32 entries in this list. Each entry in the
// array represents a priority value given by the chip team which corresponds to a CORE's CHIP_UNIT value. The CHIP_UNIT
// value is used as an index into to the array to find its corresponding priority.
//
// For example, CORE with CHIP_UNIT 10 has a deconfigure priority set by the chip team as 19, whereas CHIP_UNIT 14 has a
// priority of 1. That means CORE 14 would be deconfigured before CORE 10 since it has a higher (numerically lower)
// priority for deconfiguring. One exception to this is the Boot Core. Hostboot cannot deconfigure that CORE so whatever
// CORE that ends up being will get the highest numerical value for its priority so that the FCO algorithm leaves it
// alone.
static_assert((P10_MAX_EC_PER_PROC == NUM_CORE_PER_CHIP) && (NUM_CORE_PER_CHIP == 32), "CORE_FCO_PRIORITY_DECONFIG_LIST only accounts for 32 cores. Must be updated with new priorities from the chip team.");
static constexpr std::array<coreDeconfigPriority_t, NUM_CORE_PER_CHIP> CORE_FCO_PRIORITY_DECONFIG_LIST
{
    31,
    32,
     5,
     6,
    13,
    14,
    21,
    22,
     9,
    10,
    19,
    20,
    25,
    26,
     1,
     2,
    27,
    28,
     3,
     4,
    11,
    12,
    17,
    18,
    15,
    16,
    23,
    24,
    29,
    30,
     7,
     8,
};

// The FCO value is context sensitive. Depending on the core type, the value changes. For Fused Core mode, the value
// represents the amount of Fused Cores that are to remain usable in the system. For Normal (or Small) Core mode, the
// value means how many cores are to remain usable in the system. Since the Chip Team provides priorities on a core
// level granularity the FCO algorithm translates a Fused Core FCO value into a Normal Core FCO value and then operates
// based on that.
size_t getFcoBasedOnCoreType(const size_t i_fcoValue)
{
    return  TARGETING::is_fused_mode()  ? (i_fcoValue + i_fcoValue) // fused mode, twice as many cores to remain.
                                        : i_fcoValue;
}

// Used to sort the child COREs of a PROC target.
coreDeconfigPriority_t getCoreFcoPriority(coreFcoMetadata_t const & i_core)
{
    coreDeconfigPriority_t priority = 0;
    if (i_core.isBootCore)
    {
        // Can't deconfigure the boot core so make sure it has the highest numerical priority value.
        priority = BOOT_CORE_PRIORITY;
    }
    else
    {
        assert(i_core.chipUnit < NUM_CORE_PER_CHIP, "CORE chip unit %d was not less than NUM_CORE_PER_CHIP %d",
                                             i_core.chipUnit,
                                             NUM_CORE_PER_CHIP);
        priority = CORE_FCO_PRIORITY_DECONFIG_LIST[i_core.chipUnit];
    }
    return priority;
}

void setHwasStateForFcoDeconfig(TARGETING::Target & i_target)
{
    TARGETING::HwasState hwasState = i_target.getAttr<TARGETING::ATTR_HWAS_STATE>();
    hwasState.poweredOn  = true;
    hwasState.present    = true;
    hwasState.functional = false;
    hwasState.deconfiguredByEid = HWAS::DeconfigGard::DECONFIGURED_BY_FIELD_CORE_OVERRIDE;
    // Set functionalOverride so that Hostboot and BMC will treat as functional during reconfig loops
    hwasState.functionalOverride = true;

    i_target.setAttr<TARGETING::ATTR_HWAS_STATE>(hwasState);

    HWAS::updateAttrPG(i_target, hwasState.functional);

    HWAS_INF("setHwasStateForFcoDeconfig(): TARGET[%08X] - marked present, NOT functional, functionalOverride SET; "
             "set functional on Service Processor reboot",
             get_huid(&i_target));
}

void deconfigCoreByFco(coreFcoMetadata_t & i_core)
{
    i_core.markedForFcoDeconfig = true;
}

// This function takes in a core metadata struct and marks it and its sibling for deconfig.
void deconfigFcByFco(coreFcoMetadata_t & i_core)
{
    // mark the given core for deconfig
    deconfigCoreByFco(i_core);
    // mark the sibling for deconfig too since FCs cannot be broken.
    deconfigCoreByFco(*i_core.fcSiblingCore);
}

// Helper functions. Consider reading over applyFieldCoreOverrides first before the implementations of these which
// follow that function.
size_t calculateIdealRemainingUnitsPerProc(const fcoRestrictMetadata_t & i_fcoData, size_t& o_extra);
size_t calculateMaxUnitsForProc(const size_t i_idealUnitsPerProc,
                                const size_t i_availableCores,
                                const bool   i_isLastProcInList,
                                size_t& io_extraUnits,
                                size_t& io_debtFromPriorProcs);

// There are a number of rules for Field Core Override that must be followed. They are:
//      1) The FCO number is relative to Fused Core mode. In Fused Core mode FCO number refers to FC, in Small Core mode
//         FCO number refers to CORE
//             1a) The FCO number applies to the entire system, e.g. FCO=1 in Fused Core mode means 1 FC total, in Small
//                 Core mode that means 1 CORE total.
//             1b) FCO=0 is a special value that indicates no Field Core Overrides.
//      2) COREs should be spread across all PROCs as evenly as possible.
//             2a) Must always keep the CORE/FC that the SBE booted Hostboot with. Implicitly, this also means FCO
//                 cannot deconfigure the boot PROC.
//             2b) FCO only considers functional cores
//             2c) FCO does not include ECO cores, only active execution cores.
//             2d) Cores must be deconfigured in the order that the chip team provides.
//      3) In Fused Core mode, algorithm cannot break apart an FC.
//      4) The FCO number is the maximum number of CORE/FCs to use in the system. So, if the number of available units
//         is less than that then that's acceptable but should get as close as possible.
//
// To follow these rules, the algorithm in this function is as follows:
//    * Scale the FCO number in terms of number of COREs to remain, based on system type. This algorithm operates on
//      CORE level granulaity to follow chip team deconfigure priorities.
//    * Determine the ideal remaining units per PROC to keep. Ideally, following Rule 2 would result in a simple
//      calculation of RemainingUnits = FCO / NumberOfProcs but that's not always going to be possible. The
//      implementation of that calculation will go into more detail but broadly speaking the ideal amount will be
//      as large as possible.
//    * Given the ideal remaining units per proc, iterate over each proc and deconfigure COREs by priority until the
//      remaining available cores for the proc is less than or equal to the maximum value that proc can leave
//      functional. That max value is decided on per proc and is influenced by the ideal value.
//    * The sum of the remaining available cores between all procs is now less than or equal to the given FCO number.
void applyFieldCoreOverrides(fcoRestrictMetadata_t& i_fcoData)
{
    HWAS_INF(ENTER_MRK"applyFieldCoreOverrides(): FCO=%d, is_fused_mode? %d, PROCs given=%d",
             i_fcoData.fcoValue,
             TARGETING::is_fused_mode(),
             i_fcoData.procFcoMetadataList.size());
    do {
        // Translate the FCO number in terms of COREs.
        const size_t fcoNumber = getFcoBasedOnCoreType(i_fcoData.fcoValue);
        if (fcoNumber == 0)
        {
            // Special value to indicate no FCO.
            break;
        }

        // Sort the list of PROCs by least number of available cores to most. This serves a couple purposes.
        // First, to calculate the ideal remaining units per proc they must be sorted in this order so that in cases
        // where one or more PROCs have dramatically more or less units than another the calculation can adjust for
        // that.
        // Secondly, later on when reducing the number of units available to meet the FCO value the PROCs with available
        // cores less than the ideal number are guaranteed to keep all their cores.
        std::sort(i_fcoData.procFcoMetadataList.begin(), i_fcoData.procFcoMetadataList.end(),
                  [](const auto & i_thisProc, const auto & i_thatProc)
                  {
                        return ((i_thisProc->availableCores < i_thatProc->availableCores)
                                || ((i_thisProc->availableCores == i_thatProc->availableCores) && (i_thisProc->procId < i_thatProc->procId)));
                  });

        // Given the FCO number, calculate the ideal number of remaining units per proc. Since the FCO number could be
        // anything, it's not guaranteed to be a value that evenly divides among the number of PROCs given. So, this
        // creates a need to keep track of the extra remaining units after we've determined the ideal number. With those
        // extra units, if a PROC has more than the ideal amount it will attempt to be greedy and keep an extra unit
        // under certain conditions.
        //
        // There is one more consideration with the ideal calculation. The FCO number could produce an ideal number that
        // would require violating Rule 3 to satisfy Rule 2. So, to not violate Rule 3, a PROC can "borrow" a CORE from
        // the next PROC in the list. Hence the need to keep track of the "debt" incurred from a prior PROC.
        // A simple example: FCO=28(14 FCs), Number of PROCs=4, so ideal number is 7. In Fused Core mode that value
        //                   would require breaking up FCs which is not allowed and enforced below. If nothing is done,
        //                   then each PROC will only keep 6 COREs == 3 FCs to avoid breaking FCs.
        //                   3 FCs * 4 PROCs = 12 which is less than the FCO. This would satisfy Rule 4 however we
        //                   could have gotten 14 if 2 PROCs "borrow" one core from the other 2. Meaning, 2 PROCs get
        //                   8 COREs (4 FCs) and the other two get 6 COREs (3 FCs) for a total of 14 FCs.
        size_t extraRemainingUnitsPerProc = 0,
               debtFromPriorProcs = 0;
        const size_t idealRemainingUnitsPerProc = calculateIdealRemainingUnitsPerProc(i_fcoData,
                                                                                      extraRemainingUnitsPerProc);

        // To satisfy Rule 2a, swap the boot proc with the first in the list to guarantee it has cores left. Despite the
        // earlier sorting, this doesn't effect anything if the boot proc has significantly more/less available cores
        // than the first proc in the list.
        {
            auto bootProcIt = std::find_if(i_fcoData.procFcoMetadataList.begin(),
                                           i_fcoData.procFcoMetadataList.end(),
                                           [](const auto & i_procData)
                                           {
                                              return i_procData->isBootProc;
                                           });
            // Caller didn't fill out the struct properly.
            assert(bootProcIt != i_fcoData.procFcoMetadataList.end(), "applyFieldCoreOverrides(): Boot Proc could not be found.");
            auto firstProc = i_fcoData.procFcoMetadataList.begin();
            std::swap(*firstProc, *bootProcIt);
        }

        // For each proc reduce the number of CORE/FC units down to the ideal remaining number but if there are extra
        // beyond that then be greedy and try to keep an extra unit. By being greedy this guarantees that the algorithm
        // gets as close to the requested FCO number as possible without going over.
        for (size_t procIndex = 0; procIndex < i_fcoData.procFcoMetadataList.size(); ++procIndex)
        {
            procFcoMetadata_t & proc = *i_fcoData.procFcoMetadataList[procIndex];

            // How many COREs this PROC may keep is decided here. To arrive at the maxUnitsForThisProc, a series of
            // prioritized rules are checked and the value is returned. See that function for details.
            bool isLastProc = (procIndex == i_fcoData.procFcoMetadataList.size()-1);
            const size_t maxUnitsForThisProc = calculateMaxUnitsForProc(idealRemainingUnitsPerProc,
                                                                        proc.availableCores,
                                                                        isLastProc,
                                                                        extraRemainingUnitsPerProc,
                                                                        debtFromPriorProcs);

            // If the available cores for this proc are less than or equal to the max allowed for this proc then move
            // onto the next proc in the list. calculateMaxUnitsForProc has already updated the values necessary for the
            // next proc in the list to use (if there is one).
            if (proc.availableCores <= maxUnitsForThisProc)
            {
                continue;
            }

            // Which units to deconfig is deterministic and decided by CORE_FCO_PRIORITY_DECONFIG_LIST where each
            // CORE's CHIP_UNIT is an index into that array and the value at that index determines its priority.
            // Sort the list of COREs for this PROC by priority. By sorting the cores here we guarantee Rule 2a and 2d
            // are followed.
            std::sort(proc.coreCandidateList.begin(), proc.coreCandidateList.end(),
                    [](auto & i_thisCore, auto & i_thatCore)
                    {
                        return getCoreFcoPriority(*i_thisCore) < getCoreFcoPriority(*i_thatCore);
                    });

            // For each core, if the available number of cores for this proc exceeds the maximum then deconfigure that
            // unit and, in Fused Core mode, its FC parent and CORE sibling.
            for (auto & pCore : proc.coreCandidateList)
            {
                coreFcoMetadata_t & core = *pCore;

                // Note: If this core is not functional then the sibling CORE was already processed ahead of this one.
                // This unit and its sibling are all already deconfigured by FCO. In small core mode the only time the
                // core should be marked for FCO deconfig is during the tests to simulate a system where some cores are
                // already deconfigured for any reason.
                if ((proc.availableCores > maxUnitsForThisProc) && ( ! core.markedForFcoDeconfig ))
                {
                    // Deconfig this unit, and in Fused Core Mode its parent FC and sibling CORE.
                    // The sorting performed prior to this loop guarantees the boot CORE/FC will not be
                    // deconfigured so no need to do anything here.
                    if (TARGETING::is_fused_mode())
                    {
                            // This will deconfig this core and its sibling.
                            deconfigFcByFco(core);
                            proc.availableCores -= 2;
                    }
                    else // not fused_mode
                    {
                        // Based on the assumptions this function makes, no core should ever have already been
                        // deconfigured before reaching this point. The caller has made a mistake if the core is
                        // already marked for deconfig.
                        deconfigCoreByFco(core);
                        --proc.availableCores;
                    }
                }
                if (proc.availableCores <= maxUnitsForThisProc)
                {
                    // This proc has reduced its number of units enough, no need to walk the rest of the core list.
                    break;
                }
            }
        }
    } while (0);
    HWAS_INF(EXIT_MRK"applyFieldCoreOverrides()");

}

// A helper function for applyFieldCoreOverrides(). It takes in the FCO metadata and gives back an ideal number of units
// per proc as well as how many extra units are left beyond that ideal number.
// NOTE: It is required that the procFcoMetadataList is sorted by least to most number of available cores.
size_t calculateIdealRemainingUnitsPerProc(const fcoRestrictMetadata_t & i_fcoData, size_t & o_extra)
{
    // To calculate the ideal units per proc Rule 2 says that we need to distribute the remaining units as evenly
    // as possible. Ideally all PROCs would get the same number of remaining units but that's not always going to
    // be the case. Instead, this fuction figures out the largest value that could be split among the procs and use
    // that as the ideal value. This way PROCs with cores less than the true ideal value get to keep all their units
    // and those with more don't lose units in a vain attempt at sharing units with PROCs that don't have any more to
    // use.
    const size_t totalNumProcs = i_fcoData.procFcoMetadataList.size();

    // These are used to determine the ideal and extra values that will be returned by this function.
    size_t remainProc = totalNumProcs,
           remainFco  = getFcoBasedOnCoreType(i_fcoData.fcoValue);

    // The true ideal value if the system were fully configured
    size_t ideal = remainFco / remainProc;
    // The extra units that should be divided among the PROCs to guarantee that the most amount of cores are used.
    size_t extra = remainFco % remainProc;

    // This loop will walk through the list of procs and recalculate the ideal and extra values whenever it encounters
    // a proc with available cores less than or equal to the current ideal value. Each time this recalculation happens
    // the number of remaining procs is reduced along with the FCO value. As a result, the ideal value will grow to its
    // maximum potential value which is then returned by this function for use in the FCO algorithm.
    for (const auto & pProc : i_fcoData.procFcoMetadataList)
     {
        procFcoMetadata_t & proc = *pProc;

        // If a PROC has less than or equal to the ideal amount of available units then recalculate the ideal amount
        // excluding the available cores of this PROC from the given FCO.
        if (proc.availableCores <= ideal)
         {
            --remainProc;
            if (remainProc == 0)
            {
                break;
            }
            remainFco = remainFco - proc.availableCores;

            // After "assigning" some of the FCO value to the available cores for this proc, determine what the ideal
            // shared cores are between the remaining procs.
            ideal = remainFco / remainProc;
            extra = remainFco % remainProc;
        }
    }
    HWAS_DBG("calculateIdealRemainingUnitsPerProc(): FINAL ideal=%d, extra=%d, remainProc=%d, remainFco=%d\n",
           ideal,
           extra,
           remainProc,
           remainFco);

    o_extra = extra;
    return ideal;
}

/* @brief Given some data about the proc and the state of the FCO logic, calculate the maximum number of cores
 *        this proc can keep. Also updates the extra remaining units and if this proc effected the "debt".
 *
 * @param[in]  i_idealUnitsPerProc  The best case amount of cores this proc could keep.
 * @param[in]  i_availableCores     How many cores the proc actually has available.
 * @param[in]  i_isLastProcInList   Whether or not this is the last proc being looked at. Determines if the proc can
 *                                  "borrow" from another
 * @param[in/out] io_extraUnits     IN: How many extra units are left to be taken by procs with available cores greater
 *                                      than the ideal amount.
 *                                  OUT: How many extra units are left after this proc has had its max determined.
 * @param[in/out] io_debtFromPriorProcs IN: A value signifying if a prior proc has borrowed a core.
 *                                          zero = No borrowing has occurred yet
 *                                          non-zero = A prior proc has borrowed
 *                                     OUT: A value signifying if this proc has borrowed a core or "repayed" the debt by
 *                                          reducing its max allowed units by the debt.
 *                                          zero = Debt paid or never incurred.
 *                                          non-zero = This proc has incurred debt for a subsequent proc to pay for.
 * @return  size_t                 The maximum number of cores this proc is allowed to leave configured to satisfy FCO.
 *
 */
size_t calculateMaxUnitsForProc(const size_t i_idealUnitsPerProc,
                                const size_t i_availableCores,
                                const bool   i_isLastProcInList,
                                size_t& io_extraUnits,
                                size_t& io_debtFromPriorProcs)
{
    size_t maxUnitsForThisProc = 0;

    // The following if logic is ordered in a way that forms a set of proirities to follow in order to calculate the
    //  correct max cores for the proc. Each proirity effectively builds on the previous. So a subsequent priority can
    //  safely assume all previous priorities aren't applicable to this proc.
    //
    // Priority 1: If the available cores for this proc is less than the ideal, then this proc may keep all of those
    //             cores. Reduction of cores for this proc doesn't make sense.
    if (i_availableCores <= i_idealUnitsPerProc)
    {
        maxUnitsForThisProc = i_availableCores;
    }
    // Priority 2: If there are extra units to borrow from, then this proc will be greedy and take some of the extra.
    //             This ensures that the sum of all procs remaining units is as close or equal to the given FCO value
    //             without falling below due to other rules of the FCO algorithm, e.g. Cannot break up FCs and Ideal is
    //             odd.
    else if (io_extraUnits > 0)
    {
        // Keep an extra for this proc
        maxUnitsForThisProc = i_idealUnitsPerProc + 1;
        // decrement the available extras
        io_extraUnits--;

        // Fused cores cannot be broken up so if the max units for this proc are odd then by definition that would
        // require breaking up a fused core. That leads to the extra being wasted. To correct this take another extra
        // unit if available. If not, the extra goes unused and other procs will either shore up the unused extra
        // through "borrowing" or the rule that FCs can't be broken will take precedent over getting as close to the FCO
        // value as possible.
        if (TARGETING::is_fused_mode()
            && ((maxUnitsForThisProc % 2) != 0) // max units is an odd number
            && (io_extraUnits != 0)) // don't take extra if there isn't any left
        {
            ++maxUnitsForThisProc;
            --io_extraUnits;
        }
    }
    // Priority 3: If there is debt incurred from another proc, then this proc should pay for it over any subsequent
    //             priorities. This ensures that there is no remaining debt at the end of the FCO algorithm causing
    //             total remaining units to exceed the given FCO value.
    else if (io_debtFromPriorProcs != 0) // Another proc borrowed a unit from this one
    {
        // Pay the debt
        --io_debtFromPriorProcs;
        maxUnitsForThisProc = i_idealUnitsPerProc - 1;
    }
    // Priority 4: If the ideal is odd, this is a fused core system, and this isn't the last proc to process then this
    //             proc should borrow a core from the next in the list to end up with an even max so that an FC isn't
    //             unnecessarily deconfigured in this proc and the next one for both having an odd max value.
    else if (((i_idealUnitsPerProc % 2) != 0) // The ideal is odd
             && TARGETING::is_fused_mode() // fused cores can't be broken up
             && ( ! i_isLastProcInList)) // There is another proc after this one
    {
        ++io_debtFromPriorProcs;
        maxUnitsForThisProc = i_idealUnitsPerProc + 1;
    }
    // Priority 5: If nothing else above applies then the max units for this proc should be the ideal number of units
    //             and the FCO algorithm will handle the rest.
    else
    {
        maxUnitsForThisProc = i_idealUnitsPerProc;
    }

    return maxUnitsForThisProc;

}

}
