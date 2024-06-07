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

using namespace HWAS;
using namespace TARGETING;

/////////////////////////////////////////////////
// Helper functions for testFieldCoreOverrides
////////////////////////////////////////////////

// Currently Everest is the largest single node system so set number of chips per system to that for testing FCO
constexpr size_t NUM_CHIP_PER_SYSTEM = 8;

typedef std::vector<std::pair<FCO::procFcoMetadata_t*, std::vector<FCO::coreFcoMetadata_t*>>> systemList_t;
typedef std::vector<uint32_t> systemBitStringList_t;

void printSystem(const systemList_t & i_list)
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
        TS_INFO("%sProc[%d] FuncCores[%d]: 0x%08X",
                pProc->isBootProc ? "B " : "  ",
                pProc->procId,
                pProc->availableCores,
                bitString);
    }
}

void printSystem(const systemBitStringList_t & i_list)
{
    size_t procId = 0;
    for (const auto & bitString : i_list)
    {
        TS_INFO("Proc[%d] FuncCores[%d]: 0x%08X",
                procId++,
                __builtin_popcount(bitString),
                bitString);
    }
}

inline void clearBit(uint32_t & i_bitString, const size_t i_chipUnit)
{
    i_bitString &= ~(0x80000000UL >> i_chipUnit);
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
                // The bit is unset meaning it's deconfigured. Simulate this by setting markedForFcoDeconfig and
                // decrementing the available core count.
                pCore->markedForFcoDeconfig = true;
            }
        }
        ++procIndex;
    }
}

// A wrapper for buildSystem to clearly state the intent of the call to the reader.
void resetSystem(const systemBitStringList_t & i_originalSystemBits, systemList_t & o_sysList)
{
    buildSystem(i_originalSystemBits, o_sysList);
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

};

#endif
