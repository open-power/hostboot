/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/DCMUtils.C $                         */
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

/**
 * @file DCMUtils.C
 *
 * @brief Implements the DCM (Dual Chip Module) utilities
 *
 * Utilities to pair PROCs with IO SCM chips and returning the IO SCM chip which
 * is currently used to deconfigure.  Also utilities to print it the paired PROCs
 * of the system for debugging and testing purposes.
 */

#ifdef __HOSTBOOT_MODULE

#include <targeting/common/DCMUtils.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/target.H>
#include <targeting/common/trace.H>
#include <hwas/common/deconfigGard.H>

namespace TARGETING
{

/*****************************************************************************/
// Constructor
/*****************************************************************************/
DCMUtils::DCMUtils()
: iv_isInitialized(false),
  iv_isSystemDCM(false)
{ }

/*****************************************************************************/
// Is System DCM (Dual Chip Module)
/*****************************************************************************/
bool DCMUtils::isSystemDCM()
{
    TRACFCOMP(g_trac_targeting, ENTER_MRK"isSystemDCM()");

    if (!iv_isInitialized)
    {
        determineSystemIsDCM();
    }

    TRACFCOMP(g_trac_targeting, EXIT_MRK"isSystemDCM(): returning %d (0: no; 1: yes)",
                                iv_isSystemDCM);

    return iv_isSystemDCM;
}  // DCMUtils::isSystemDCM()

/*****************************************************************************/
// Get the IO SCM chip associated with PROC target
/*****************************************************************************/
TargetHandle_t DCMUtils::getAssociatedIoScmChip(TargetHandle_t i_procTarget)
{
    const auto l_procTargetHuid = get_huid(i_procTarget);

    TRACFCOMP(g_trac_targeting, ENTER_MRK"getAssociatedIoScmChip(): for PROC HUID 0x%.8x",
                                l_procTargetHuid);

    TargetHandle_t l_ioScmChip(nullptr); //Will populate with IO SCM chip if found for i_procTarget
    ATTR_HUID_type l_ioScmChipHuid(0);   //Used for tracing purposes

    // Grouping is done via the PROCs location code
    auto l_locationCodeProc = i_procTarget->getAttrAsStdArr<ATTR_STATIC_ABS_LOCATION_CODE>();

    // Get a list of all PROCs, functional or not
    TargetHandleList l_allProcs;
    bool l_functional = false;
    getAllChips(l_allProcs, TYPE_PROC, l_functional);


    // Iterate over the PROC list, grouping pairs
    for (auto & l_proc : l_allProcs)
    {
        // Grouping is done via the PROCs location code
        auto l_locationCodeIoScm = l_proc->getAttrAsStdArr<ATTR_STATIC_ABS_LOCATION_CODE>();
        if ((l_proc != i_procTarget) && (l_locationCodeProc == l_locationCodeIoScm))
        {
            // Find the number of present cores for the PROC
            TargetHandleList l_coreList;
            getCoreChiplets(l_coreList, UTIL_FILTER_CORE_ALL,
                            UTIL_FILTER_PRESENT, l_proc);
            if (!l_coreList.size())
            {
                l_ioScmChip = l_proc;
                l_ioScmChipHuid = l_proc->getAttr<ATTR_HUID>();

                TRACFCOMP(g_trac_targeting,
                          INFO_MRK"getAssociatedIoScmChip(): found associated IO SCM "
                                  "chip HUID 0x%.8x that is paired with PROC HUID 0x%.8x",
                                   l_ioScmChipHuid, l_procTargetHuid);
                break;
            }
        }
    } // for (const auto l_proc : l_allProcs)

    if (l_ioScmChipHuid)
    {
        TRACFCOMP(g_trac_targeting, EXIT_MRK"getAssociatedIoScmChip(): returning IO SCM "
                  "chip HUID 0x%.8x that is associated with PROC HUID 0x%.8x",
                   l_ioScmChipHuid, l_procTargetHuid);
    }
    else
    {
        TRACFCOMP(g_trac_targeting, EXIT_MRK"getAssociatedIoScmChip(): no IO SCM "
                  "chip associated with PROC HUID 0x%.8x, returning nullptr",
                   l_procTargetHuid);
    }

    return l_ioScmChip;
} // DCMUtils::deconfigureIoScmPair()

/*****************************************************************************/
// Determine if System Is DCM (Dual Chip Module)
/*****************************************************************************/
void DCMUtils::determineSystemIsDCM()
{
    TRACFCOMP(g_trac_targeting, ENTER_MRK"determineSystemIsDCM()");

    // Get a list of all PROCs, functional or not
    TargetHandleList l_allProcs;
    bool l_functional = false;
    getAllChips(l_allProcs, TYPE_PROC, l_functional);

    // Iterate over the PROC list, grouping pairs
    for (const auto & l_proc : l_allProcs)
    {
        // Grouping is done via the PROCs location code
        auto l_locationCode = l_proc->getAttrAsStdArr<ATTR_STATIC_ABS_LOCATION_CODE>();

        // Determine if this location code has been found before, if not
        // then create a mapping for the location code
        auto l_findLocationCode = iv_mapDcmPairs.find(l_locationCode);
        if (l_findLocationCode == iv_mapDcmPairs.end())
        {
            // First time encountering this location code therefore
            // create a struct to hold the DCM paired data
            dcmProcsPairs_t l_dcmProcPairs;
            iv_mapDcmPairs[l_locationCode] = l_dcmProcPairs;
        }
        // Get HUID of PROC target
        auto l_procHuid = l_proc->getAttr<ATTR_HUID>();

        // Find the number of present cores for the PROC
        TargetHandleList l_coreList;
        getCoreChiplets(l_coreList, UTIL_FILTER_CORE_ALL,
                        UTIL_FILTER_PRESENT, l_proc);

        // Add the PROC target to the DCM struct which will sort out if
        // the target is an IO SCM chip or not
        iv_mapDcmPairs[l_locationCode].addTarget(l_proc, l_coreList.size(), l_procHuid);

        TRACFCOMP(g_trac_targeting, INFO_MRK"determineSystemIsDCM(): Found "
                  "PROC 0x%.8X with location code %s which has %d cores",
                  l_procHuid, l_locationCode.data(), l_coreList.size());
    } // for (const auto l_proc : l_allProcs)

    // Iterate over map, if any item in the map is paired then the system is
    // a Dual Chip Module system.
    if (!iv_mapDcmPairs.empty())
    {
        for (const auto & pairedData: iv_mapDcmPairs)
        {
            iv_isSystemDCM = pairedData.second.iv_isPaired;
            if (iv_isSystemDCM)
            {
                break;
            }
        }
    }

    iv_isInitialized = true;

    TRACFCOMP(g_trac_targeting, INFO_MRK"determineSystemIsDCM(): "
              "Is system dual chip: %d (0: no; 1: yes)", iv_isSystemDCM);

    TRACFCOMP(g_trac_targeting, EXIT_MRK"determineSystemIsDCM()");
} // DCMUtils::determineSystemIsDCM()

/*****************************************************************************/
// Dump DCM Pairs
/*****************************************************************************/
void DCMUtils::dumpDcmPairs()
{
    TRACFCOMP(g_trac_targeting, ENTER_MRK"dumpDcmPairs()");

    TRACFCOMP(g_trac_targeting, INFO_MRK"Is system dual chip: %d (0: no; 1: yes)\n",
              isSystemDCM());

    if (!iv_mapDcmPairs.size())
    {
        TRACFCOMP(g_trac_targeting, INFO_MRK"  No dual chip pairs found on system");
    }

    for (const auto & l_pairData: iv_mapDcmPairs)
    {
        TRACFCOMP(g_trac_targeting, INFO_MRK"  Location Code %s is paired: %d (0: no; 1: yes)",
                          l_pairData.first.data(), l_pairData.second.iv_isPaired);

        if (l_pairData.second.iv_procTarget)
        {
            dumpProcTarget(l_pairData.second);
        }
        else
        {
            TRACFCOMP(g_trac_targeting, INFO_MRK"    PROC target is NULL");
        }

        if (l_pairData.second.iv_ioScmChip)
        {
            dumpIoScmChip(l_pairData.second);
        }
        else
        {
            TRACFCOMP(g_trac_targeting, INFO_MRK"    IO SCM chip is NULL");
        }
    }

    TRACFCOMP(g_trac_targeting, EXIT_MRK"dumpDcmPairs()");
} // DCMUtils::dumpDcmPairs()

/*****************************************************************************/
// Dump PROC target HWAS state data and number of cores
/*****************************************************************************/
void DCMUtils::dumpProcTarget(const dcmProcsPairs_t &i_dcmProcPair) const
{
    const auto l_state = i_dcmProcPair.iv_procTarget->getAttr<ATTR_HWAS_STATE>();

    TRACFCOMP(g_trac_targeting, INFO_MRK"    PROC target HUID 0x%0.8X", i_dcmProcPair.iv_procTargetHuid);
    TRACFCOMP(g_trac_targeting, INFO_MRK"       present cores: %d", i_dcmProcPair.iv_procTargetCores);
    TRACFCOMP(g_trac_targeting, INFO_MRK"       is functional: %d", l_state.functional);
    TRACFCOMP(g_trac_targeting, INFO_MRK"       is spec deconfig: %d", l_state.specdeconfig);
    TRACFCOMP(g_trac_targeting, INFO_MRK"       deconfig by EID: %d", l_state.deconfiguredByEid);
} // DCMUtils::dumpProcTarget

/*****************************************************************************/
// Dump IO SCM chip HWAS state data and number of cores
/*****************************************************************************/
void DCMUtils::dumpIoScmChip(const dcmProcsPairs_t &i_dcmProcPair) const
{
    const auto l_state = i_dcmProcPair.iv_ioScmChip->getAttr<ATTR_HWAS_STATE>();

    TRACFCOMP(g_trac_targeting, INFO_MRK"    IO SCM chip HUID 0x%0.8X", i_dcmProcPair.iv_ioScmChipHuid);
    TRACFCOMP(g_trac_targeting, INFO_MRK"       present cores: 0");
    TRACFCOMP(g_trac_targeting, INFO_MRK"       is functional: %d", l_state.functional);
    TRACFCOMP(g_trac_targeting, INFO_MRK"       is spec deconfig: %d", l_state.specdeconfig);
    TRACFCOMP(g_trac_targeting, INFO_MRK"       deconfig by EID: %d", l_state.deconfiguredByEid);
} // DCMUtils::dumpIoScmChip

} // namespace TARGETING

#endif // __HOSTBOOT_MODULE
