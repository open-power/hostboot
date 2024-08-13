/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/fieldCoreOverrideTest.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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
#ifndef _FIELDCOREOVERRIDETEST_H
#define _FIELDCOREOVERRIDETEST_H
/**
 *  @file fieldCoreOverrideTest.H
 *
 *  @brief Unit tests to verify FCO functionality. Uses a chaos generator to create
 *         many random system configs to test FCO algorithm.
 */

//******************************************************************************
// Includes
//******************************************************************************

// CXXTEST
#include <cxxtest/TestSuite.H>
#include <targeting/targplatutil.H> //assertGetToplevelTarget
#include <hwas/common/fieldCoreOverride.H>
#include <util/random.H>
#include <targeting/namedtarget.H> // getBootCore

using namespace FCO;
using namespace HWAS;
using namespace TARGETING;

/////////////////////////////////////////////////
// Helper functions for testFieldCoreOverrides
////////////////////////////////////////////////

// Currently Everest is the largest single node system so set number of chips per system to that for testing FCO
constexpr size_t NUM_CHIP_PER_SYSTEM = 8;

typedef std::vector<std::pair<FCO::procFcoMetadata_t*, std::vector<FCO::coreFcoMetadata_t*>>> systemList_t;
typedef std::vector<uint32_t> systemBitStringList_t;

// Forward decl for spare algorithm
namespace HWAS
{
void selectSpareCores(FCO::fcoRestrictMetadata_t & io_fcoData);
};

// Finds CORE/FC units for a given chip parent which have ATTR_CORE_IS_SPARE set.
void findSpareCores(TargetHandleList & o_spares, Target * i_parent)
{
    o_spares.clear();
    for (const auto & fc : composable(getNonEcoFcs)(i_parent, false))
    {
        if (fc->getAttr<ATTR_CORE_IS_SPARE>())
        {
            o_spares.push_back(fc);
        }
        for (const auto & core : composable(getChildChiplets)(fc, TYPE_CORE, false))
        {
            if (core->getAttr<ATTR_CORE_IS_SPARE>())
            {
                o_spares.push_back(core);
            }
        }
    }
}

// Gets all spare-able units in the system. This is used to keep track of and restore system state before/after tests
void getSpareableUnits(std::map<TargetHandle_t, ATTR_CORE_IS_SPARE_type> & o_spareStates)
{
    o_spareStates.clear();

    PredicatePostfixExpr coreTypes;
    PredicateCTM isFc(CLASS_NA, TYPE_FC);
    PredicateCTM isCore(CLASS_NA, TYPE_CORE);
    coreTypes.push(&isFc)
        .push(&isCore).Or();

    TargetHandleList unitList;
    targetService().getAssociated(unitList, UTIL::assertGetToplevelTarget(),
            TargetService::CHILD_BY_AFFINITY,
            TargetService::ALL,
            &coreTypes);

    for (auto & coreUnit : unitList)
    {
        o_spareStates[coreUnit] = coreUnit->getAttr<ATTR_CORE_IS_SPARE>();
    }
}

void printSystem(const systemList_t & i_list, bool i_printSpares = false)
{
    for (const auto & pair : i_list)
    {
        auto & pProc = pair.first;
        std::vector<FCO::coreFcoMetadata_t*> coreList = pair.second;
        uint32_t bitString = 0x00000000ul;
        for (const auto & pCore : coreList)
        {
            if (!pCore->markedForFcoDeconfig)
            {
                bitString |= (0x80000000 >> (pCore->chipUnit));
            }
        }
        TS_INFO("%sProc[%X] FuncCores[%d]: 0x%08X",
                pProc->isBootProc ? "B " : "  ",
                pProc->procId,
                pProc->availableCores,
                bitString);
        for (const auto & spare : composable(findSpareCores)(pProc->target))
        {
            auto hwasState = spare->getAttr<ATTR_HWAS_STATE>();
            TS_INFO("SPARE %s CHIP_UNIT=%d, P=%d, F=%d",
                    spare->getAttr<ATTR_TYPE>() == TYPE_FC ? "FC" : "CORE",
                    spare->getAttr<ATTR_CHIP_UNIT>(),
                    hwasState.present,
                    hwasState.functional);
            if (spare->getAttr<ATTR_TYPE>() == TYPE_FC)
            {
                for (const auto & core : composable(getChildChiplets)(spare, TYPE_CORE, false))
                {
                    auto hwasState = core->getAttr<ATTR_HWAS_STATE>();
                    TS_INFO("    Core CU=%d, P=%d, F=%d, Spare=%d", core->getAttr<ATTR_CHIP_UNIT>(),
                            hwasState.present,
                            hwasState.functional,
                            core->getAttr<ATTR_CORE_IS_SPARE>());
                }
            }
        }
    }
}

void printSystem(const systemBitStringList_t & i_list)
{
    size_t procId = 0;
    for (const auto & bitString : i_list)
    {
        TS_INFO("Proc[%X] FuncCores[%d]: 0x%08X",
                procId++,
                __builtin_popcount(bitString),
                bitString);
    }
}

inline void clearBit(uint32_t & i_bitString, const size_t i_chipUnit)
{
    i_bitString &= ~(0x80000000UL >> i_chipUnit);
}

inline void setBit(uint32_t & i_bitString, const size_t i_chipUnit)
{
    i_bitString |= (0x80000000UL >> i_chipUnit);
}

// Setup a fully configured system as input for FCO algorithm testing
systemList_t buildSystem(FCO::fcoRestrictMetadata_t & o_fcoData,
        const size_t i_numProcs,
        const size_t i_bootProc,
        const size_t i_bootCore)
{
    systemList_t systemList;

    size_t coreChipUnit = 0;
    // Default to use all cores
    o_fcoData.fcoValue = 0;
    for (size_t i = 0; i < i_numProcs; i++)
    {
        std::unique_ptr<FCO::procFcoMetadata_t> proc = std::make_unique<FCO::procFcoMetadata_t>();
        // Add new proc to systemList
        systemList.push_back({proc.get(), {}});

        FCO::procFcoMetadata_t & thisProc = *proc;
        thisProc.isBootProc = (i == i_bootProc);
        thisProc.procId = i;
        thisProc.availableCores = NUM_CORE_PER_CHIP;

        for (size_t j = 0; j < NUM_FC_PER_CHIP; j++)
        {
            for (size_t k = 0; k < NUM_CORE_PER_FC; k++)
            {
                std::unique_ptr<FCO::coreFcoMetadata_t> pCore = std::make_unique<FCO::coreFcoMetadata_t>();
                FCO::coreFcoMetadata_t & core = *pCore;
                core.chipUnit = coreChipUnit;
                core.isBootCore = ((coreChipUnit == i_bootCore) && (i == i_bootProc));

                // For fused core mode, finish setting up the pairs only when k==1 so that both pairs have been created
                // already.
                if (is_fused_mode() && (k == 1))
                {
                    // The last core added was the sibling of this one.
                    FCO::coreFcoMetadata_t & siblingCore = *thisProc.coreCandidateList.back();

                    // If either core of the pair is the boot core, then both are considered boot cores since FCs
                    // cannot be broken up.
                    bool isBootPair = (siblingCore.isBootCore || core.isBootCore);
                    core.isBootCore = isBootPair;
                    siblingCore.isBootCore = isBootPair;

                    // Set the raw sibling pointers
                    core.fcSiblingCore = thisProc.coreCandidateList.back().get();
                    siblingCore.fcSiblingCore = pCore.get();
                }
                // Add the core to the list
                systemList[i].second.push_back(pCore.get());
                thisProc.coreCandidateList.push_back(std::move(pCore));
                coreChipUnit++;
            }
        }
        // Add the proc to the list
        o_fcoData.procFcoMetadataList.push_back(std::move(proc));
        // New proc, reset chip unit count.
        coreChipUnit = 0;
    }
    return systemList;
}

/*
 * @brief Takes in a system and uses the bit string list provided as a way to configure PROCs and CORES based on that
 *        list.  This is useful to recreate a chaos generated system for debug or to include in the
 *        testFieldCoreOverrides function as a baseline testcase.
 *
 * @param[in]   systemBitStringList_t  A list of bitstrings NUM_CHIP_PER_SYSTEM long where each bitstring represents a
 *                                     single proc's cores.
 *
 * @param[out]  systemList_t           A system list which was already built to be fully configured so that this
 *                                     function can knock out PROCs/COREs to replicate the system defined by the input
 *                                     systemBitStringList_t.
 */
void buildSystem(const systemBitStringList_t & i_bitStrings, systemList_t & o_sysList)
{
    size_t procIndex = 0;
    for (const auto & bitString : i_bitStrings)
    {
        FCO::procFcoMetadata_t & proc = *o_sysList[procIndex].first;

        // Reset the available cores
        proc.availableCores = __builtin_popcount(bitString);

        // Configure each core as given in the bit string
        for (auto & pCore : o_sysList[procIndex].second)
        {
            if (((0x80000000UL >> (pCore->chipUnit)) & bitString))
            {
                // The bit is set, meaning it is configured.
                pCore->markedForFcoDeconfig = false;
            }
            else
            {
                // The bit is unset meaning it's deconfigured. Simulate this by setting markedForFcoDeconfig.
                pCore->markedForFcoDeconfig = true;
            }
        }
        ++procIndex;
    }
}

/*
 * @brief Takes in a systemList_t and uses the actual present/functional chips/cores to configure the system list
 */
systemList_t buildSimicsSystem(FCO::fcoRestrictMetadata_t & o_fcoData, systemBitStringList_t & o_bitStrings)
{
    systemList_t sysList;
    do {
        TargetHandle_t bootChip = nullptr;
        if (targetService().queryMasterProcChipTargetHandle(bootChip))
        {
            TS_INFO("Error from queryMasterProcChipTargetHandle");
            break;
        }

        // Get only the functional procs in the system since a non-functional proc won't have spare cores.
        TargetHandleList procs;
        getAllChips(procs, TYPE_PROC);

        const Target * bootCore = getBootCore(false);
        // Builds a fully configured system with all the metadata pointers setup.
        sysList = buildSystem(o_fcoData,
                              procs.size(),
                              0,
                              bootCore->getAttr<ATTR_CHIP_UNIT>());

        systemBitStringList_t sysBitStrings(procs.size(), 0);

        // Fill in the real data
        for (size_t i = 0; i < procs.size(); ++i)
        {
            Target * proc = procs[i];
            auto & fcoProc = o_fcoData.procFcoMetadataList[i];
            fcoProc->target = proc;
            fcoProc->procId = get_huid(proc);

            TargetHandleList cores;
            getNonEcoCores(cores, proc, false);
            for (size_t j = 0; j < cores.size(); ++j)
            {
                Target * core = cores[j];
                auto & fcoCore = fcoProc->coreCandidateList[j];

                fcoCore->target = core;
                fcoCore->chipUnit = core->getAttr<ATTR_CHIP_UNIT>();

                setBit(sysBitStrings[i], fcoCore->chipUnit);
            }
            fcoProc->availableCores = __builtin_popcount(sysBitStrings[i]);

            // Remove unused cores from the lists. sysList holds raw pointers to the metadata objects so erase those
            // first then the objects themselves which fcoProc has ownership of.
            auto eraseIf = [](const auto & i_core)
                           { return i_core->target == nullptr; };
            sysList[i].second.erase(std::remove_if(begin(sysList[i].second),
                                                   end(sysList[i].second),
                                                   eraseIf),
                                    end(sysList[i].second));
            fcoProc->coreCandidateList.erase(std::remove_if(begin(fcoProc->coreCandidateList),
                                                            end(fcoProc->coreCandidateList),
                                                            eraseIf),
                                             end(fcoProc->coreCandidateList));
        }
        printSystem(sysBitStrings);
        o_bitStrings = sysBitStrings;

    } while(0);

    return sysList;

}

// A wrapper for buildSystem to clearly state the intent of the call to the reader.
void resetSystem(const systemBitStringList_t & i_originalSystemBits, systemList_t & o_sysList)
{
    buildSystem(i_originalSystemBits, o_sysList);
}

void setHwasFunctional(bool i_functional, Target * i_target)
{
    TARGETING::HwasState hwasState = i_target->getAttr<TARGETING::ATTR_HWAS_STATE>();
    hwasState.poweredOn  = true;
    hwasState.present    = true;
    hwasState.functional = i_functional;

    i_target->setAttr<TARGETING::ATTR_HWAS_STATE>(hwasState);

}

// Resets the systemList markedForFcoDeconfig flags and unsets any fcs/cores which may have been marked as spare.
// Does not touch HWAS state for targets.
void resetSimicsSystem(const systemBitStringList_t & i_originalSystemBits, systemList_t & o_sysList)
{
    // Call build system to reset all the markedForFcoDeconfig flags
    buildSystem(i_originalSystemBits, o_sysList);
    // Walk through all the cores under each proc to unset the spare core flag.
    for (auto & [pProc, pCores] : o_sysList)
    {
        // Get a list of the spares and reset to not spare. FCO doesn't deal directly with FC targets but this
        // will ensure regardless of fused_mode that the FC/CORE targets will have their attr set.
        for (auto & spare : composable(findSpareCores)(pProc->target))
        {
            // Clear spare
            spare->setAttr<ATTR_CORE_IS_SPARE>(0);
        }
    }
}

// A chaos generator which will deconfigure a random number of PROCs and CORE/FCs in the FCO data structure to simulate
// non-fully configured systems in the wild.
systemBitStringList_t injectChaosIntoSystem(systemList_t & i_sysList)
{
    // Create a vector of bit strings for this system and start all at all Fs. Later, we'll switch off the ones
    // we're not using.
    systemBitStringList_t sysBitStrings(NUM_CHIP_PER_SYSTEM, UINT32_MAX);

    // Decide how many PROCs are unavailable. The boot proc will always be ignored as a deconfig candidate since the IPL
    // wouldn't get to the FCO logic without at least a boot proc.
    //
    // Note because these are all random numbers its not possible to guarantee the max number of missing units is hit
    // without additional logic which has been omitted here.
    uint64_t maxNumProcsMissing = randint(1, NUM_CHIP_PER_SYSTEM);
    for (size_t i = 0; i < maxNumProcsMissing; ++i)
    {
        // Get a random index to select which proc is knocked out. Since this is a random number we cannot
        // guarantee the number isn't the boot proc. If it selects the boot proc then we'll not deconfig in that
        // case.
        const uint64_t procIndex = randint(0, NUM_CHIP_PER_SYSTEM-1);

        FCO::procFcoMetadata_t & proc = *i_sysList[procIndex].first;
        if ( !proc.isBootProc && (proc.availableCores != 0))
        {
            proc.availableCores = 0;
            sysBitStrings[procIndex] = 0;
            for (auto & pCore : proc.coreCandidateList)
            {
                deconfigCoreByFco(*pCore);
            }
        }
    }
    // For each PROC decide how many COREs to keep.
    for (size_t procIndex = 0; procIndex < i_sysList.size(); ++procIndex)
    {
        FCO::procFcoMetadata_t & proc = *i_sysList[procIndex].first;
        std::vector<FCO::coreFcoMetadata_t *> coreList = i_sysList[procIndex].second;

        if (proc.availableCores == 0)
        {
            continue;
        }

        if (is_fused_mode())
        {
            // For the same reason as the boot proc, ignore the boot FC
            // Leave at least one FC remaining since this PROC was left configured.
            uint64_t maxNumFcMissing = randint(1, NUM_FC_PER_CHIP-1);
            for (size_t i = 0; i < maxNumFcMissing; ++i)
            {
                // The FCO data structure doesn't track FCs so we can deconfigure them by grabbing a core and handing
                // it to the deconfigFcByFco function which will knock out its sibling.
                const uint64_t coreIndex = randint(0, NUM_CORE_PER_CHIP-1);
                FCO::coreFcoMetadata_t & core = *coreList[coreIndex];
                if ( !core.isBootCore && !core.markedForFcoDeconfig)
                {
                    deconfigFcByFco(core);
                    clearBit(sysBitStrings[procIndex], core.chipUnit);
                    clearBit(sysBitStrings[procIndex], core.fcSiblingCore->chipUnit);
                    proc.availableCores -= 2;
                }
            }
        }
        else
        {
            // For the same reason as the boot proc, ignore the boot CORE
            // Leave at least one CORE remaining since this PROC was left configured.
            uint64_t maxNumCoreMissing = randint(1, NUM_CORE_PER_CHIP-1);
            for (size_t i = 0; i < maxNumCoreMissing; ++i)
            {
                const uint64_t coreIndex = randint(0, NUM_CORE_PER_CHIP-1);
                FCO::coreFcoMetadata_t & core = *coreList[coreIndex];
                if ( !core.isBootCore && !core.markedForFcoDeconfig)
                {
                    deconfigCoreByFco(core);
                    clearBit(sysBitStrings[procIndex], core.chipUnit);
                    --proc.availableCores;
                }
            }
        }
    }
    return sysBitStrings;
}

// Called by testFieldCoreOverrides to check the work of applyFieldCoreOverrides
bool verifyFieldCoreOverrides(const size_t i_fcoNumber,
        const FCO::fcoRestrictMetadata_t& i_fcoList,
        const size_t & i_originalNumCores,
        const bool     i_isChaosTest)
{
    const size_t expectedUnitsRemaining = is_fused_mode() ? (i_fcoNumber + i_fcoNumber) : i_fcoNumber;
    bool testPassed = true;

    enum failStates_t
    {
        ALL_GOOD             =  0,
        BOOT_PROC_DECONFIG   = -1,
        BOOT_CORE_DECONFIG   = -2,
        FUSED_CORE_BROKEN    = -3,
        UNNECESSARY_DECONFIG = -4,
    };

    size_t totalRemainingCores = 0;
    failStates_t failState = ALL_GOOD;
    for (const auto & pProc : i_fcoList.procFcoMetadataList)
    {
        FCO::procFcoMetadata_t & proc = *pProc;
        totalRemainingCores += proc.availableCores;
        if (proc.isBootProc)
        {
            // Needs to stay configured
            if (proc.availableCores == 0)
            {
                failState = BOOT_PROC_DECONFIG;
                break;
            }

            // Needs to keep boot CORE/FC around too.
            for (const auto & pCore : proc.coreCandidateList)
            {
                FCO::coreFcoMetadata_t & core = *pCore;
                if (core.isBootCore)
                {
                    if (core.markedForFcoDeconfig)
                    {
                        failState = BOOT_CORE_DECONFIG;
                    }
                    if (is_fused_mode() && core.fcSiblingCore->markedForFcoDeconfig)
                    {
                        // This would also mean the fused core got broken somehow.
                        failState = BOOT_CORE_DECONFIG;
                    }
                    // We checked the boot CORE/FC is still around. Leave this inner loop.
                    break;
                }
            }
            if (failState != ALL_GOOD)
            {
                break;
            }
        }
        if (is_fused_mode())
        {
            // Cannot break apart fused cores. Despite sorting in the algorithm the priority list provided by the chip
            // team should have the pairs adjacent to each other in the list.
            for (auto pCore_it = proc.coreCandidateList.begin();
                    pCore_it != proc.coreCandidateList.end();
                    std::advance(pCore_it, 2))
            {
                FCO::coreFcoMetadata_t & core = **pCore_it;
                // Check for broken FCs
                if (core.markedForFcoDeconfig != core.fcSiblingCore->markedForFcoDeconfig)
                {
                    failState = FUSED_CORE_BROKEN;
                    break;
                }
            }
        }
        if (failState != ALL_GOOD)
        {
            break;
        }
    }

    // If the system started with less than the expected units after FCO was applied and the total remaining units
    // are not the same as what the system started with then that means the algorithm deconfigured units unnecessarily.
    // The system should try to keep as many units as possible.
    if ((i_originalNumCores < expectedUnitsRemaining) && (totalRemainingCores != i_originalNumCores)
        && (failState == ALL_GOOD)) // Don't overwrite other fails
    {
        failState = UNNECESSARY_DECONFIG;
    }

    if (i_fcoNumber == 0)
    {
        if ((failState == ALL_GOOD) && (totalRemainingCores == i_originalNumCores))
        {
            TS_TRACE("testFieldCoreOverrides(): FCO=%d Pass. expected=%d, actual=%d",
                     i_fcoNumber,
                     i_originalNumCores,
                     totalRemainingCores);
        }
        else
        {
            TS_FAIL("testFieldCoreOverrides(): FCO=%d Failed. expected=%d, actual=%d, reason=%d",
                    i_fcoNumber,
                    i_originalNumCores,
                    totalRemainingCores,
                    failState);
            testPassed = false;
        }
    }
    else if ((i_isChaosTest
                && (totalRemainingCores > expectedUnitsRemaining)) // Can't guarantee total==expected with chaos
            || (failState != ALL_GOOD))
    {
        TS_FAIL("testFieldCoreOverrides(): A chaos generated test failed with reason %d. FCO=%d, expected=%d actual=%d",
                failState,
                i_fcoNumber,
                expectedUnitsRemaining,
                totalRemainingCores);
        testPassed = false;
    }
    else if (((totalRemainingCores != expectedUnitsRemaining) && ! i_isChaosTest) // Only works if there is not chaos
            || failState != ALL_GOOD)
    {
        TS_FAIL("testFieldCoreOverrides(): A fully configured system test failed with reason %d. FCO=%d, expected=%d actual=%d",
                failState,
                i_fcoNumber,
                expectedUnitsRemaining,
                totalRemainingCores);
        testPassed = false;
    }
    else
    {
        TS_TRACE("testFieldCoreOverrides(): FCO %d Pass. expected=%d, actual=%d",
                 i_fcoNumber,
                 expectedUnitsRemaining,
                 totalRemainingCores);
    }
    return testPassed;
}

/////////////////////////////////////////////////
// End of helper functions for testFieldCoreOverrides
////////////////////////////////////////////////

class fieldCoreOverrideTest: public CxxTest::TestSuite
{
private:
    // Used to HWAS deconfigure a core for testing
    void deconfigCores(systemList_t     & i_sysList,
                       const size_t       i_coresToDeconfig)
    {
        for (auto & [pProc, pCores] : i_sysList)
        {
            size_t coresToDeconfig = i_coresToDeconfig;
            for (auto & core : pCores)
            {
                if ((! core->isBootCore) &&
                    (core->target != nullptr))
                {
                    if (coresToDeconfig && core->target->getAttr<ATTR_HWAS_STATE>().functional)
                    {
                        // FCO algorithm doesn't check actual HWAS state, so setting markedForFcoDeconfig is a way to
                        // tell FCO to ignore this core like it wasn't HWAS functional.
                        core->markedForFcoDeconfig = true;
                        setHwasFunctional(false, core->target);

                        --coresToDeconfig;
                        --pProc->availableCores;
                        if (is_fused_mode())
                        {
                            auto & sibling = core->fcSiblingCore;
                            // FCO algorithm doesn't check actual HWAS state, so setting markedForFcoDeconfig is a way
                            // to tell FCO to ignore this core like it wasn't HWAS functional.
                            sibling->markedForFcoDeconfig = true;
                            setHwasFunctional(false, sibling->target);

                            --coresToDeconfig;
                            --pProc->availableCores;
                        }

                    }
                }
                if (coresToDeconfig == 0)
                {
                    // No more cores to knock out for this chip. Move to the next.
                    break;
                }
            }
        }
    }

public:

    void testFieldCoreOverrides()
    {
        // Save original fused core mode attrs
        Target* pSys = UTIL::assertGetToplevelTarget();
        auto originalFusedMode = pSys->getAttr<ATTR_FUSED_CORE_MODE_HB>();
        auto originalFusedOption = pSys->getAttr<ATTR_FUSED_CORE_OPTION>();

        do {
        // Need to ensure fused mode is set before the test system is built so that the sibling pointers are valid.
        pSys->setAttr<ATTR_FUSED_CORE_OPTION>(FUSED_CORE_OPTION_USING_FUSED_CORES);
        pSys->setAttr<ATTR_FUSED_CORE_MODE_HB>(FUSED_CORE_MODE_HB_SMT8_ONLY);
        if (!is_fused_mode())
        {
            TS_FAIL("testFieldCoreOverrides(): Could not force fused core mode");
            break;
        }

        // Build up the FCO metadata structure as if it were an Everest system.
        FCO::fcoRestrictMetadata_t fcoList;
        // Choose the secondary boot proc as the proc to test against. This checks two things:
        //  1. That the algorithm is aware of which proc is the boot proc
        //  2. That the algorithm doesn't remove the boot core regardless of what the boot proc is.
        constexpr size_t bootProc = 1;

        // Select a few different boot core options to ensure FCO doesn't try to knock out the boot core regardless of
        // which it is. These three were chosen based on their deconfig prorities.
        // 0 is the last to be considered for deconfig
        // 14 is the first
        // 24 is in the middle
        std::vector<ATTR_CHIP_UNIT_type> bootCoreOptions = {0, 14, 24};
        // The sysList will hold all pointers to all the PROCs and COREs for easy access since FCO sorts the fcoList.
        // This way the system can be built once and then modified over each run as necessary to produce a different
        // system configuration.
        systemList_t sysList = buildSystem(fcoList, NUM_CHIP_PER_SYSTEM, bootProc, bootCoreOptions[0]);

        // These are the various system configurations to run this test suite against. If additional system configs
        // are desired they should always be added prior to the last fully configured system because the test suite
        // assumes the final system config is for the chaos generator which requires a fully configured system.
        const std::vector<systemBitStringList_t> systemConfigOptions =
        {
            // First system to test is a fully configured one.
            systemBitStringList_t(NUM_CHIP_PER_SYSTEM, UINT32_MAX),

            // The last system in the test should always be fully configured because this system
            // is used as the basis for the chaos generator to work off of.
            systemBitStringList_t(NUM_CHIP_PER_SYSTEM, UINT32_MAX)
        };

        // Test Fused and Normal Core modes
        for (size_t testFusedMode = 0; testFusedMode < 2; ++testFusedMode)
        {
            if (testFusedMode)
            {
                TS_TRACE("Switching to FUSED MODE");
                // Force fused core mode. Note, none of these functions touch targeting directly so the real simulated
                // hardware configuration doesn't matter.
                pSys->setAttr<ATTR_FUSED_CORE_OPTION>(FUSED_CORE_OPTION_USING_FUSED_CORES);
                pSys->setAttr<ATTR_FUSED_CORE_MODE_HB>(FUSED_CORE_MODE_HB_SMT8_ONLY);
                if (!is_fused_mode())
                {
                    TS_FAIL("testFieldCoreOverrides(): Could not force fused core mode");
                    break;
                }
                // The first test in fused core mode needs its sibling set
                sysList[bootProc].second[bootCoreOptions[0]]->fcSiblingCore->isBootCore = true;
            }
            else
            {
                TS_TRACE("Switching to NORMAL MODE");
                // Force non-fused core mode.
                pSys->setAttr<ATTR_FUSED_CORE_OPTION>(FUSED_CORE_OPTION_USING_NORMAL_CORES);
                pSys->setAttr<ATTR_FUSED_CORE_MODE_HB>(FUSED_CORE_MODE_HB_SMT4_ONLY);
                if (is_fused_mode())
                {
                    TS_FAIL("testFieldCoreOverrides(): Could not force normal core mode");
                    break;
                }
                // The first test in small core mode needs to ensure its sibling is unset
                sysList[bootProc].second[bootCoreOptions[0]]->fcSiblingCore->isBootCore = false;
            }

            // Anything above this calculated max will produce the same results. That is because FCO is a core
            // reduction algorithm and if the system already begins with fewer or equal cores to max then there is no
            // change to the system necessary if FCO is greater than or equal to the max.
            const size_t maxFcoValue = is_fused_mode()
                                     ? (NUM_FC_PER_CHIP * NUM_CHIP_PER_SYSTEM)
                                     : (NUM_CORE_PER_CHIP * NUM_CHIP_PER_SYSTEM);

            // For Normal and Fused modes we want to test fully configured systems and chaotic systems.
            for (size_t systemConfigIndex = 0; systemConfigIndex < systemConfigOptions.size(); ++systemConfigIndex)
            {
                // The last test are the chaos generated configs.
                bool isChaosTest = (systemConfigIndex == (systemConfigOptions.size() - 1));
                // The original system config before FCO was applied.
                systemBitStringList_t sysBitStrings = systemConfigOptions[systemConfigIndex];
                // How many cores the system began with.
                size_t originalNumCores = 0;
                for (const auto & bits : sysBitStrings)
                {
                    originalNumCores += __builtin_popcount(bits);
                }

                buildSystem(sysBitStrings, sysList);

                // Check a handful of boot core options to verify FCO doesn't deconfig the boot core/fc.
                for (size_t bootCoreIndex = 0; bootCoreIndex < bootCoreOptions.size(); ++bootCoreIndex)
                {
                    // Helpful variables to make things easier to read.
                    auto currentBootCore = bootCoreOptions[bootCoreIndex];
                    auto nextBootCore = ((bootCoreIndex + 1) < bootCoreOptions.size())
                                      ? bootCoreOptions[bootCoreIndex+1]
                                      : 0;

                    TS_INFO("testFieldCoreOverrides(): FCO CHAOS=%d BOOT P=%d C=%d",
                            isChaosTest,
                            bootProc,
                            currentBootCore);

                    for (size_t fcoValue = 0; fcoValue <= maxFcoValue; ++fcoValue)
                    {
                        fcoList.fcoValue = fcoValue;
                        if (isChaosTest)
                        {
                            sysBitStrings = injectChaosIntoSystem(sysList);
                            // Recount the cores since we don't know how many are left.
                            originalNumCores = 0;
                            for (const auto & bits : sysBitStrings)
                            {
                                originalNumCores += __builtin_popcount(bits);
                            }
                        }

                        applyFieldCoreOverrides(fcoList);

                        bool testPassed = verifyFieldCoreOverrides(fcoValue,
                                                                   fcoList,
                                                                   originalNumCores,
                                                                   isChaosTest);
                        if (!testPassed)
                        {
                            // Print out the system before applying FCO
                            TS_INFO("Starting system config before FCO");
                            printSystem(sysBitStrings);
                            // Print after applying FCO
                            TS_INFO("Resulting config after FCO");
                            printSystem(sysList);
                            // Don't break, allow all tests to run. Just because one failed doesn't mean they'll all
                            // fail or will fail in the same way.
                        }
                        // reset the system using the original system config since chaos tests can mess with
                        // sysBitStrings.
                        resetSystem(systemConfigOptions[systemConfigIndex], sysList);
                    } // end for each FCO val

                    // Setup next boot core(s)
                    // Switch off the current boot core(s)
                    sysList[bootProc].second[currentBootCore]->isBootCore = false;
                    if (is_fused_mode())
                    {
                        sysList[bootProc].second[currentBootCore]->fcSiblingCore->isBootCore = false;
                    }
                    // Switch on the next boot core(s)
                    sysList[bootProc].second[nextBootCore]->isBootCore = true;
                    if (is_fused_mode())
                    {
                        sysList[bootProc].second[nextBootCore]->fcSiblingCore->isBootCore = true;
                    }

                } // end for each boot core(fc)
            } // end for full config & chaos gen
        } // end testing fused and normal core modes

        // Put the fused core attrs back to original values.
        pSys->setAttr<ATTR_FUSED_CORE_MODE_HB>(originalFusedMode);
        pSys->setAttr<ATTR_FUSED_CORE_OPTION>(originalFusedOption);
        } while(0);
    }

    void testSpareCoreSelection()
    {
        TS_INFO("testSpareCoreSelection: Start");
        // Save original fused core mode attrs
        Target* pSys = UTIL::assertGetToplevelTarget();
        auto originalFusedMode = pSys->getAttr<ATTR_FUSED_CORE_MODE_HB>();
        auto originalFusedOption = pSys->getAttr<ATTR_FUSED_CORE_OPTION>();
        // Save original spare settings
        std::map<TargetHandle_t, ATTR_CORE_IS_SPARE_type> originalSpares;
        getSpareableUnits(originalSpares);

        do {
        // Need to ensure fused mode is set before the test system is built so that the sibling pointers are valid.
        pSys->setAttr<ATTR_FUSED_CORE_OPTION>(FUSED_CORE_OPTION_USING_FUSED_CORES);
        pSys->setAttr<ATTR_FUSED_CORE_MODE_HB>(FUSED_CORE_MODE_HB_SMT8_ONLY);
        if (!is_fused_mode())
        {
            TS_FAIL("testFieldCoreOverrides(): Could not force fused core mode");
            break;
        }

        // Build up the FCO metadata structure. To test spare selection, we want to include FCO settings to fully
        // exercise the various cases. The twist here is that usually FCO doesn't actually touch the real targets
        // but spare core selection has to so it can pick between present/functional/FCO cores.
        FCO::fcoRestrictMetadata_t fcoList;

        // This holds the original state of the system to reset with later.
        systemBitStringList_t originalSystemConfig;
        // The sysList will hold all pointers to all the PROCs and COREs for easy access since FCO sorts the fcoList.
        // This way the system can be built once and then modified over each run as necessary to produce a different
        // system configuration.
        systemList_t sysList = buildSimicsSystem(fcoList, originalSystemConfig);

        // Clear all the spare settings from the targets before the test. This isn't touching the saved value.
        for (auto & [coreUnit, originalSpareSetting]  : originalSpares )
        {
            coreUnit->setAttr<ATTR_CORE_IS_SPARE>(0);
        }

        // Get the total functional cores available to test with. These will be used to select FCO values for testing a
        // few scenarios below.
        size_t coreCount = 0;
        for (auto & [pProc, pCores] : sysList)
        {
            coreCount += pProc->availableCores;
        }
        const size_t totalCoresAvailable = coreCount;

        // These values are used to create test systems to run FCO and spare core algorithm against. The values are not
        // cumulative. So an FCO reduction of 1 and a deconfig of 1 does not mean a core/fc will be marked for FCO
        // deconfig and one will be marked non-functional.
        //
        // The values are also scaled according to fused mode. So if you want to add a test you can just write in terms
        // of CORE for small core mode and FC for fused core mode.
        struct spareCoreTest_t {
            size_t fcoReductionPerProc; // number of core/fcs to take from each proc
            size_t numSparesPerProc;    // number of core/fcs to mark spare per proc
            size_t numDeconfigsPerProc; // number of core/fcs to deconfig per proc
            bool fusedMode;      // small core or fused core test

        };

        std::vector<spareCoreTest_t> tests = {
                                               // Test normal and fused modes choose a spare from full config
                                               {0, 1, 0, true},
                                               {0, 1, 0, false},
                                               // Test normal and fused modes choose the spare as the deconfiged CORE/FC
                                               {0, 1, 1, true},
                                               {0, 1, 1, false},
                                               // Test normal and fused modes reclaim spare from FCO
                                               {1, 1, 0, true},
                                               {1, 1, 0, false},
                                               // Test normal and fused modes choose deconfig and don't reclaim from FCO
                                               {1, 1, 1, true},
                                               {1, 1, 1, false},
                                               // Test normal and fused modes choose deconfig and reclaim from FCO
                                               {3, 2, 1, true},
                                               {3, 2, 1, false},
                                             };

        constexpr bool PRINT_SPARES = true;
        size_t testNum = 0;
        for (const auto & test : tests)
        {
            TS_TRACE("testSpareCoreSelection: Test %d/%d: FCO Reduction=%d, Spare Per Proc=%d, Deconfigs Per Proc=%d, Fused=%d",
                     ++testNum,
                     tests.size(),
                     test.fcoReductionPerProc,
                     test.numSparesPerProc,
                     test.numDeconfigsPerProc,
                     test.fusedMode ? 1 : 0);
            size_t numCoresToDeconfig = test.numDeconfigsPerProc;
            size_t numCoresToSpare = test.numSparesPerProc;
            size_t fcoReductionPerProc = (test.fcoReductionPerProc * sysList.size()); /* multiply by number of procs to
                                                                                         reduce each proc by requested
                                                                                         amount */
            if (test.fusedMode)
            {
                // This test is fused mode, recontextualize test numbers in terms of small cores
                numCoresToDeconfig *= 2;
                numCoresToSpare *= 2;
                fcoReductionPerProc *= 2;

                // Set fused mode attrs.
                TS_TRACE("Switching to FUSED MODE");
                // Force fused core mode. Note, none of these functions touch targeting directly so the real simulated
                // hardware configuration doesn't matter.
                pSys->setAttr<ATTR_FUSED_CORE_OPTION>(FUSED_CORE_OPTION_USING_FUSED_CORES);
                pSys->setAttr<ATTR_FUSED_CORE_MODE_HB>(FUSED_CORE_MODE_HB_SMT8_ONLY);
                if (!is_fused_mode())
                {
                    TS_FAIL("testFieldCoreOverrides(): Could not force fused core mode");
                    break;
                }

            }
            else
            {
                // This is a small core test, set the attrs.
                TS_TRACE("Switching to NORMAL MODE");
                // Force non-fused core mode.
                pSys->setAttr<ATTR_FUSED_CORE_OPTION>(FUSED_CORE_OPTION_USING_NORMAL_CORES);
                pSys->setAttr<ATTR_FUSED_CORE_MODE_HB>(FUSED_CORE_MODE_HB_SMT4_ONLY);
                if (is_fused_mode())
                {
                    TS_FAIL("testFieldCoreOverrides(): Could not force normal core mode");
                    break;
                }
            }
            // Set the FCO value for this test.
            assert(totalCoresAvailable >= fcoReductionPerProc,
                    "Testcase bug, totalCoresAvailable < fcoReductionPerProc");
            // If the test is in fused mode then we need to divide FCO value by 2 since the value needs to be in
            // terms of FCs, not COREs.
            const size_t fusedModeDivisor = is_fused_mode() ? 2 : 1;
            fcoList.fcoValue = fcoReductionPerProc ? ((totalCoresAvailable - fcoReductionPerProc) / fusedModeDivisor)
                                                   : 0; // No reduction means no FCO mode, 0 signifies that.

            // Set the number of spare cores for each proc in this test.
            for (auto & [pProc, pCores] : sysList)
            {
                // Based on PG data:
                // The number of normal core spares identified can be 0, 2, 4, 6, or 8.
                // Which would translate into fused-core spares of 0, 1, 2, 3 or 4.
                // The algorithm was written to support an arbitrary number of spares though.
                pProc->target->setAttr<ATTR_SPARE_CORES>(numCoresToSpare);
            }

            // Knock out the requested number of cores/fcs per proc for this test.
            deconfigCores(sysList,
                          numCoresToDeconfig);

            // Call FCO
            applyFieldCoreOverrides(fcoList);

            // Call selectSpareCores with same fcoList. Spare selection gathers it's own data but uses FCO as a
            // cross-reference
            selectSpareCores(fcoList);

            bool procFailedTest = false;
            bool bootCoreSpared = false;
            // For each proc, walk through it's list of cores and count the spares
            for (auto & [pProc, pCores] : sysList)
            {
                // Count the number of cores spared, how many of those spares were deconfigured cores, and how many
                // cores were marked for FCO deconfig. With these values, we can compare to the test's values to
                // determine if spares were selected properly.
                size_t coresSpared = 0,
                       deconfigedSpares = 0,
                       numFcoDeconfigs = 0;
                for (auto & core : pCores)
                {
                    if (core->markedForFcoDeconfig)
                    {
                        // When the test deconfigs a core it also will set markedForFcoDeconfig to tell FCO this core
                        // was deconfigured since FCO doesn't inspect targets directly.
                        ++numFcoDeconfigs;
                    }
                    if (core->target->getAttr<ATTR_CORE_IS_SPARE>())
                    {
                        ++coresSpared;
                        if (not core->target->getAttr<ATTR_HWAS_STATE>().functional)
                        {
                            ++deconfigedSpares;
                            // Reset HWAS state for future tests
                            setHwasFunctional(true, core->target);
                        }
                        if (core->isBootCore)
                        {
                            TS_FAIL("testSpareCoreSelection: FAIL Boot CORE[chip_unit=%d] was chosen as spare!",
                                    core->chipUnit);
                            bootCoreSpared = true;
                            // Finish counting the results to check other fail conditions.
                        }
                    }
                }

                // Number of cores spared on this proc should match what was asked for.
                if (coresSpared != numCoresToSpare)
                {
                    TS_FAIL("testSpareCoreSelection: Test (%d/%d) for PROC[%X] w/ "
                             "coresSpared=%d, deconfigedSpares=%d, numFcoDeconfigs=%d "
                             "Failed to pick enough spares",
                             testNum,
                             tests.size(),
                             pProc->procId,
                             coresSpared,
                             deconfigedSpares,
                             numFcoDeconfigs);
                    procFailedTest = true;
                    // Check the other proc
                    continue;
                }
                // Spare algorithm priorizes selecting deconfigured (non-functional) cores before choosing to reclaim
                // from FCO or using available functional cores. If there were deconfigured cores for this test
                // then ensure this expectation was met.
                if (numCoresToDeconfig &&
                        // Number of spares are more than number of deconfiged cores but spare algorithm didn't
                        // assign spares to all available deconfigured cores first.
                        (((numCoresToSpare > numCoresToDeconfig) && (deconfigedSpares != numCoresToDeconfig)) ||
                        // Number of spares are less than or equal to number of deconfiged cores but spare algorithm
                        // didn't assign all spares to deconfigured cores.
                        ((numCoresToSpare <= numCoresToDeconfig) && (deconfigedSpares != coresSpared))))
                {
                    TS_FAIL("testSpareCoreSelection: Test (%d/%d) for PROC[%X] w/ "
                             "coresSpared=%d, deconfigedSpares=%d, numFcoDeconfigs=%d "
                             "failed to spare enough deconfigured cores",
                             testNum,
                             tests.size(),
                             pProc->procId,
                             coresSpared,
                             deconfigedSpares,
                             numFcoDeconfigs);
                    procFailedTest = true;
                    // Check the other proc
                    continue;

                }
                // When FCO mode is enabled, the spare algorithm should always try to reclaim a core from FCO if there
                // are no deconfigured (non-functional) cores to choose from. Check if we're testing that scenario
                if ((test.numSparesPerProc > test.numDeconfigsPerProc)
                    && (test.fcoReductionPerProc > test.numDeconfigsPerProc))
                {
                    // The number of spares is greater than the deconfigs per proc and
                    // FCO value was high enough to mark some cores for FCO deconfig. So,
                    // check that the spare core algorithm reclaimed from FCO
                    if (numFcoDeconfigs == test.fcoReductionPerProc)
                    {
                        // if the number of FCO deconfigs matches what the test requested
                        // then that means that the spare core algorithm didn't reclaim any
                        // units from FCO to mark as spare.
                        TS_TRACE("testSpareCoreSelection: Test (%d/%d) for PROC[%X] w/ "
                                 "coresSpared=%d, deconfigedSpares=%d, numFcoDeconfigs=%d",
                                 testNum,
                                 tests.size(),
                                 pProc->procId,
                                 coresSpared,
                                 deconfigedSpares,
                                 numFcoDeconfigs);
                        TS_FAIL("testSpareCoreSelection: Failed to reclaim spare from FCO when spares=%d, fco=%d,"
                                " deconfigs=%d", numCoresToSpare,
                                                 fcoList.fcoValue,
                                                 numCoresToDeconfig);
                        procFailedTest = true;
                        // Check the other proc
                        continue;
                    }
                }
                // Emit a pass for this chip if the boot core wasn't spared or this isn't the boot proc and the test got
                // this far indicating no other fails occurred above.
                if ( ! bootCoreSpared || ! pProc->isBootProc)
                {
                    TS_TRACE("testSpareCoreSelection: Test (%d/%d) for PROC[%X] PASS w/ "
                             "coresSpared=%d, deconfigedSpares=%d, numFcoDeconfigs=%d",
                             testNum,
                             tests.size(),
                             pProc->procId,
                             coresSpared,
                             deconfigedSpares,
                             numFcoDeconfigs);
                }
            }
            if (bootCoreSpared || procFailedTest)
            {
                // The test failed. Print out the system state for inspection
                printSystem(sysList, PRINT_SPARES);
            }

            // Reset the spare and deconfigByFco flags
            resetSimicsSystem(originalSystemConfig, sysList);
        }

        } while(0);

        // Restore the original spare core settings
        for (auto & [coreUnit, originalSpareSetting]  : originalSpares )
        {
            coreUnit->setAttr<ATTR_CORE_IS_SPARE>(originalSpareSetting);
        }

        // Put the fused core attrs back to original values.
        pSys->setAttr<ATTR_FUSED_CORE_MODE_HB>(originalFusedMode);
        pSys->setAttr<ATTR_FUSED_CORE_OPTION>(originalFusedOption);
        TS_INFO("testSpareCoreSelection: Done");
    }

};

#endif
