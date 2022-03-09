/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/hwas.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
/* [+] Google Inc.                                                        */
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
 *  @file hwas.C
 *
 *  HardWare Availability Service functions.
 *  See hwas.H for doxygen documentation tags.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/

#include <stdint.h>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h> // sprintf

#ifdef __HOSTBOOT_MODULE
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <initservice/initsvcreasoncodes.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <sbe/sbeif.H>
#include <kernel/bltohbdatamgr.H> // CacheSize
#include <util/misc.H>            // isSimicsRunning
#endif


#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/util.H>

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwasError.H>
#include <hwas/common/pgLogic.H>

#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas_reasoncodes.H>

#ifdef CONFIG_SUPPORT_EEPROM_CACHING
#include <eeprom/eepromif.H>
#endif

namespace HWAS
{

using namespace TARGETING;
using namespace HWAS::COMMON;

using PARTIAL_GOOD::pg_entry_t;
using PARTIAL_GOOD::pg_mask_t;

// trace setup; used by HWAS_DBG and HWAS_ERR macros
HWAS_TD_t g_trac_dbg_hwas   = NULL; // debug - fast
HWAS_TD_t g_trac_imp_hwas   = NULL; // important - slow

#ifdef __HOSTBOOT_MODULE
TRAC_INIT(&g_trac_dbg_hwas, "HWAS",     KILOBYTE );
TRAC_INIT(&g_trac_imp_hwas, "HWAS_I",   KILOBYTE );
#else
TRAC_INIT(&g_trac_dbg_hwas, "HWAS",     1024 );
TRAC_INIT(&g_trac_imp_hwas, "HWAS_I",   1024 );
#endif

Target* shouldPowerGateNMMU1(const Target& i_proc)
{
    HWAS_ASSERT(i_proc.getAttr<ATTR_TYPE>() == TYPE_PROC,
                "shouldPowerGateNMMU1: Expecting PROC");

    const CHIPLET_ID_ATTR NEST1_CHIPLET_ID = 3;

    TargetHandleList l_pauHandleList { };
    getChildChiplets(l_pauHandleList, &i_proc, TYPE_PAU);

    bool l_haveFunctionalPAU = false;

    // Check all the functional PAUs to see whether any of them in the set
    // { 0, 4, 5 } are functional
    for (Target* const l_pauTarget : l_pauHandleList)
    {
        const auto l_chipUnit = l_pauTarget->getAttr<ATTR_CHIP_UNIT>();

        if (   l_chipUnit == 0
            || l_chipUnit == 4
            || l_chipUnit == 5)
        {
            l_haveFunctionalPAU = true;
            break;
        }
    }

    Target* l_nmmu1 = nullptr;

    // If we have no functional PAUs in the set { 0, 4, 5 } then return a
    // reference to NMMU1 so the caller can deconfigure it.
    if (!l_haveFunctionalPAU)
    {
        TargetHandleList l_nmmuHandleList { };
        getChildChiplets(l_nmmuHandleList, &i_proc, TYPE_NMMU);

        for (Target* const l_nmmuTarget : l_nmmuHandleList)
        {
            if (l_nmmuTarget->getAttr<ATTR_CHIPLET_ID>()
                == NEST1_CHIPLET_ID)
            {
                l_nmmu1 = l_nmmuTarget;
                break;
            }
        }
    }

    return l_nmmu1;
} // shouldPowerGateNMMU1

/**
 * @brief       simple helper fn to get and set hwas state to poweredOn,
 *                  present, functional and then execute any secondary
 *                  behaviors that are required.
 *
 * @param[in]   i_target        pointer to target that we're looking at
 * @param[in]   i_present       boolean indicating present or not
 * @param[in]   i_functional    boolean indicating functional or not
 * @param[in]   i_errlEid       erreid that caused change to non-funcational;
 *                              0 if not associated with an error or if
 *                              functional is true
 *
 * @return      none
 *
 */
void enableHwasState(Target *i_target,
        bool i_present, bool i_functional,
        uint32_t i_errlEid)
{
    HwasState hwasState = i_target->getAttr<ATTR_HWAS_STATE>();

    // Only modify the reason/eid on the initial deconfig
    //  or if we're reverting what happened earlier
    if( (i_functional == false)
        || (DeconfigGard::CONFIGURED_BY_RESOURCE_RECOVERY == i_errlEid) )
    {   // record the EID as a reason that we're marking non-functional
        hwasState.deconfiguredByEid = i_errlEid;
    }

    // clear speculative deconfig if we're functional now
    if( i_functional )
    {
        hwasState.specdeconfig = 0;
    }

    hwasState.poweredOn     = true;
    hwasState.present       = i_present;
    hwasState.functional    = i_functional;

    i_target->setAttr<ATTR_HWAS_STATE>( hwasState );

    updateAttrPG(*i_target, hwasState.functional);
}

void applyCoreFunctionalOverride(TARGETING::TargetHandle_t i_target)
{
    HwasState hwasState = i_target->getAttr<ATTR_HWAS_STATE>();
    // if functionalOverride is set, then the target was deconfigured
    // due to Field Core Override (FCO). Set target 'functional' to
    // re-enable for use or for FCO selection again
    if (hwasState.functionalOverride && hwasState.present)
    {
        hwasState.functional = true;
    }
    // set to false so that the override is only applied
    // once per time being set
    hwasState.functionalOverride = false;
    i_target->setAttr<ATTR_HWAS_STATE>(hwasState);
}

TargetHandleList disableExtraOcapiIohsTargets(const Target* const i_pauc)
{
    TargetHandleList pauHandleList;
    getChildChiplets(pauHandleList, i_pauc, TYPE_PAU, true);

    TargetHandleList iohsHandleList;
    getChildChiplets(iohsHandleList, i_pauc, TYPE_IOHS, true);

    // Toss out all the non-OCAPI IOHSes
    for (auto iohs = iohsHandleList.begin(); iohs != iohsHandleList.end();)
    {
        if ((*iohs)->getAttr<ATTR_IOHS_CONFIG_MODE>() != IOHS_CONFIG_MODE_OCAPI)
        {
            iohs = iohsHandleList.erase(iohs);
        }
        else
        {
            ++iohs;
        }
    }

    TargetHandleList deconfigureIohsList;

    // Now if we have more OCAPI IOHSes than PAUs that could support them, add
    // the extra ones to the disable list. It doesn't matter which ones we
    // disable, since they will be mapped appropriately in the SCOM setup in
    // istep 10.
    for (size_t i = pauHandleList.size(); i < iohsHandleList.size(); ++i)
    {
        deconfigureIohsList.push_back(iohsHandleList[i]);
    }

    return deconfigureIohsList;
}

#ifndef __HOSTBOOT_RUNTIME

// SORT functions that we'll use for PR keyword processing
bool compareProcGroup(procRestrict_t t1, procRestrict_t t2)
{
    if (t1.group == t2.group)
    {
        return (t1.target->getAttr<ATTR_HUID>() <
                    t2.target->getAttr<ATTR_HUID>());
    }
    return (t1.group < t2.group);
}

bool compareAffinity(const TargetInfo t1, const TargetInfo t2)
{
        return t1.affinityPath < t2.affinityPath;
}

/*
 * @brief  This function returns the topology ID of the input proc target
 *
 * @param[in] i_proc: proc target
 * @return Processor's topology ID
 */
uint8_t getTopologyId (TargetHandle_t i_proc)
{
    return i_proc->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
}

/**
 * @brief Do presence detect on only MUX targets and enable HWAS state
 *
 * @param[in] i_sysTarget the top level target (CLASS_SYS)
 * @return    errlHndl_t  return nullptr if no error,
 *                        else return a handle to an error entry
 *
 */
errlHndl_t discoverMuxTargetsAndEnable(const Target &i_sysTarget)
{
    HWAS_DBG(ENTER_MRK"discoverMuxTargetsAndEnable");

    errlHndl_t l_err{nullptr};

    do
    {
        // Only get MUX targets
        const PredicateCTM l_muxPred(CLASS_CHIP, TYPE_I2C_MUX);
        TARGETING::PredicatePostfixExpr l_muxPredExpr;
        l_muxPredExpr.push(&l_muxPred);
        TargetHandleList l_pMuxCheckPres;
        targetService().getAssociated( l_pMuxCheckPres, (&i_sysTarget),
            TargetService::CHILD, TargetService::ALL, &l_muxPredExpr);

        // Do the presence detect on only MUX targets
        l_err = platPresenceDetect(l_pMuxCheckPres);

        // If an issue with platPresenceDetect, then exit, returning
        // error back to caller
        if (nullptr != l_err)
        {
            break;
        }

        // Enable the HWAS State for the MUXes
        const bool l_present(true);
        const bool l_functional(true);
        const uint32_t l_errlEid(0);
        for (TargetHandle_t pTarget : l_pMuxCheckPres)
        {
            // set HWAS state to show MUX is present and functional
            enableHwasState(pTarget, l_present, l_functional, l_errlEid);
        }
    } while (0);

    HWAS_DBG(EXIT_MRK"discoverMuxTargetsAndEnable exit with %s",
             (nullptr == l_err ? "no error" : "error"));

    return l_err;
}

// The Partial-good vector is stored in VPD as a series of 24-bit entries. To
// make them easier to work with and to provide room to grow them in the future,
// we work with them as 32-bit entries (pg_entry_t). This function converts from
// an array of bytes which represent 24-bit VPD data into a pgv object (array of
// 32-bit pg_entry_t).
// Because a 1-bit in a PG entry means that the part is not represented or not
// functional, we pad the most significant byte of each pg_entry_t with 0xFF and
// right-justify the actual data from the VPD.
// This function presumes that the PG entries are stored in big-endian byte
// order.
void HWASDiscovery::parsePgData(
        const std::array<uint8_t, VPD_CP00_PG_DATA_LENGTH>& i_pgData,
        partialGoodVector&                                  o_pgDataExpanded)
{
    for (size_t i = 0; i < VPD_CP00_PG_DATA_ENTRIES; ++i)
    {
        // We put all 1s in the high byte (this gets shifted over three times as
        // the three data bytes get read) to indicate that none of the bits are
        // "functional" because they don't represent hardware
        o_pgDataExpanded[i] = 0xFF;

        for (size_t j = 0; j < VPD_CP00_PG_ENTRY_SIZE; ++j)
        {
            o_pgDataExpanded[i] = (o_pgDataExpanded[i] << 8)
                                 | i_pgData[i * VPD_CP00_PG_ENTRY_SIZE + j];
        }
    }
}

/**
 * @brief Do presence detect on only PMIC targets and enable HWAS state
 *
 * @param[in] i_sysTarget the top level target (CLASS_SYS)
 * @return    errlHndl_t  return nullptr if no error,
 *                        else return a handle to an error entry
 *
 */
errlHndl_t discoverPmicTargetsAndEnable(const Target &i_sysTarget)
{
    HWAS_INF(ENTER_MRK"discoverPmicTargetsAndEnable");

    errlHndl_t l_err{nullptr};

    do
    {
        // Only get PMIC targets
        const PredicateCTM l_pmicPred(CLASS_NA, TYPE_PMIC);
        TARGETING::PredicatePostfixExpr l_asicPredExpr;
        l_asicPredExpr.push(&l_pmicPred);
        TargetHandleList l_pPmicCheckPres;
        targetService().getAssociated( l_pPmicCheckPres, (&i_sysTarget),
            TargetService::CHILD, TargetService::ALL, &l_asicPredExpr);

        // Do the presence detect on only PMIC targets
        // NOTE: this function will remove any non-present targets
        //       from pPmicCheckPres
        l_err = platPresenceDetect(l_pPmicCheckPres);

        // If an issue with platPresenceDetect, then exit, returning
        // error back to caller
        if (nullptr != l_err)
        {
            break;
        }

        // Enable the HWAS State for the PMICs
        const bool l_present(true);
        const bool l_functional(true);
        const uint32_t l_errlEid(0);
        for (TargetHandle_t pTarget : l_pPmicCheckPres)
        {
            // set HWAS state to show PMIC is present and functional
            enableHwasState(pTarget, l_present, l_functional, l_errlEid);
        }
    } while (0);

    HWAS_INF(EXIT_MRK"discoverPmicTargetsAndEnable exit with %s",
             (nullptr == l_err ? "no error" : "error"));

    return l_err;
}


/**
 * @brief Do presence detect on only MDS targets and enable HWAS state
 *
 * @param[in] i_sysTarget the top level target (CLASS_SYS)
 * @return    errlHndl_t  return nullptr if no error,
 *                        else return a handle to an error entry
 *
 */
errlHndl_t discoverMdsTargetsAndEnable(const Target &i_sysTarget)
{
    HWAS_INF(ENTER_MRK"discoverMdsTargetsAndEnable");

    errlHndl_t l_err{nullptr};

    do
    {
        // Only get MDS targets
        const PredicateCTM l_mdsPred(CLASS_NA, TYPE_MDS_CTLR);
        TARGETING::PredicatePostfixExpr l_asicPredExpr;
        l_asicPredExpr.push(&l_mdsPred);
        TargetHandleList l_pMdsCheckPresList;
        targetService().getAssociated( l_pMdsCheckPresList, (&i_sysTarget),
            TargetService::CHILD, TargetService::ALL, &l_asicPredExpr);

        // If no MDS targets found, then nothing to do but exit
        if (!l_pMdsCheckPresList.size())
        {
            break;
        }

        // Do the presence detect on only MDS targets
        // NOTE: this function will remove any non-present targets from l_pMdsCheckPresList
        l_err = platPresenceDetect(l_pMdsCheckPresList);

        // If an issue with platPresenceDetect, then exit, returning error back to caller
        if (l_err)
        {
            break;
        }

        // Enable the HWAS State for the MDSs
        const bool l_present(true);
        const bool l_functional(true);
        const uint32_t l_errlEid(0);
        for (TargetHandle_t pTarget : l_pMdsCheckPresList)
        {
            // set HWAS state to show MDS is present and functional
            enableHwasState(pTarget, l_present, l_functional, l_errlEid);
        }
    } while (0);

    HWAS_INF(EXIT_MRK"discoverMdsTargetsAndEnable exit with %s",
             (nullptr == l_err ? "no error" : "error"));

    return l_err;
} // discoverMdsTargetsAndEnable


/**
 * @brief Do presence detect on Generic I2C Device targets and enable HWAS state
 *
 * @param[in] i_sysTarget the top level target (CLASS_SYS)
 * @return    errlHndl_t  return nullptr if no error,
 *                        else return a handle to an error entry
 *
 */
errlHndl_t discoverGenericI2cDeviceTargetsAndEnable(const Target &i_sysTarget)
{
    HWAS_INF(ENTER_MRK"discoverGenericI2cDeviceTargetsAndEnable");

    errlHndl_t l_err{nullptr};

    do
    {
        // Only get Generic I2C Device targets
        const PredicateCTM l_gi2cPred(CLASS_NA, TYPE_GENERIC_I2C_DEVICE);
        TARGETING::PredicatePostfixExpr l_asicPredExpr;
        l_asicPredExpr.push(&l_gi2cPred);
        TargetHandleList l_pGi2cCheckPres;
        targetService().getAssociated( l_pGi2cCheckPres, (&i_sysTarget),
            TargetService::CHILD, TargetService::ALL, &l_asicPredExpr);

        // Do the presence detect on only Generic I2C Device targets
        // NOTE: this function will remove any non-present targets
        //       from l_pGi2cCheckPres
        l_err = platPresenceDetect(l_pGi2cCheckPres);

        // If an issue with platPresenceDetect, then exit, returning
        // error back to caller
        if (nullptr != l_err)
        {
            break;
        }

        // Enable the HWAS State for the Generic I2C Device targets
        const bool l_present(true);
        const bool l_functional(true);
        const uint32_t l_errlEid(0);
        for (TargetHandle_t pTarget : l_pGi2cCheckPres)
        {
            // set HWAS state to show each Generic I2C Device target
            // is present and functional
            enableHwasState(pTarget, l_present, l_functional, l_errlEid);
        }
    } while (0);

    HWAS_INF(EXIT_MRK"discoverGenericI2cDeviceTargetsAndEnable exit with %s",
             (nullptr == l_err ? "no error" : "error"));

    return l_err;
}

/* @brief Deconfigure all SMPGROUP targets that don't have a peer.
 * attribute. Some hardware procedures expect busses without peers to
 * be deconfigured.
 */
static void deconfigureBussesWithNullPeer()
{
    const auto sys = UTIL::assertGetToplevelTarget();

    TargetHandleList smpgroups;

    getChildAffinityTargets(smpgroups,
                            sys,
                            CLASS_NA,
                            TYPE_SMPGROUP);

    for (const auto smpgroup : smpgroups)
    {
        const auto peer_path = smpgroup->getAttr<ATTR_PEER_PATH>();

        if (peer_path.size() == 1 && peer_path[0].type == TARGETING::TYPE_NA)
        {
            theDeconfigGard().deconfigureTarget(*smpgroup,
                                                HWAS::DeconfigGard::DECONFIGURED_BY_NO_PEER_TARGET);
        }
    }
}

#if defined(__HOSTBOOT_MODULE) && !defined(CONFIG_FSP_BUILD)
template <typename Iterator, typename T>
static constexpr bool find(Iterator begin, const Iterator end, const T& value)
{
    while(begin != end)
    {
        if (*begin == value)
        {
            return true;
        }
        ++begin;
    }
    return false;
}
/*
 * @brief Checks all chips in the system against the MRW established Minimum Ship Level (MSL) EC levels for the given
 *        chip. If it finds a chip with an EC level not in the list in the MRW then an unrecoverable error will be
 *        created and committed.
 *
 * @param[in] i_mslArray    One of two possible arrays based on the template arg. Either an array of values for
 *                          ATTR_MSL_MFG_ALLOW or ATTR_MSL_FIELD_SUPPORTED.
 *
 * @return   errlHndl_t     An error if any EC mismatches occurred that points to all errors that occurred.
 *                          Otherwise, nullptr.
 */
template<const ATTRIBUTE_ID A>
errlHndl_t validateEcMslLevels(typename AttributeTraits<A>::TypeStdArr i_mslArray)
{
    HWAS_INF(ENTER_MRK"validateEcMslLevels");
    ///////////////////////////////////////////////////////////////////////////
    // Compile time assertions about the input data
    ///////////////////////////////////////////////////////////////////////////
    static constexpr std::array<ATTRIBUTE_ID, 2> VALID_ATTRIBUTE_IDS =
    {
        ATTR_MSL_MFG_ALLOW,
        ATTR_MSL_FIELD_SUPPORTED,
    };
    // The above list are the only acceptable attributes that can be passed into this function. So the following
    // assert verifies the template arg given is in that list.
    static_assert(find(VALID_ATTRIBUTE_IDS.begin(), VALID_ATTRIBUTE_IDS.end(), A),
                  "validateEcMslLevels cannot be called with given ATTRIBUTE_ID");
    // The reason the array must be even is because its expected that the data is of the form given by mslEntry_t below.
    // So if there were an array with an odd number of elements passed in then either the iv_chipId or iv_ecLevel member
    // would be missing when this logic lays the struct down overtop the i_mslArray.
    static_assert(std::size(i_mslArray) % 2 == 0,
                  "validateEcMslLevels requires input array to have an even size to "
                  "hold assumptions about data format.");
    ///////////////////////////////////////////////////////////////////////////

    typedef uint16_t chipId_t;
    typedef uint16_t ecLevel_t;
    struct mslEntry_t
    {
        chipId_t iv_chipId;
        ecLevel_t iv_ecLevel;
    };

    uint32_t commonPlid = 0;
    errlHndl_t error = nullptr;
    size_t numberOfInvalidChips = 0;

    do {

        // @TODO RTC 251152 Remove this if statement once all system MRWs are updated.
        if (i_mslArray.empty() || i_mslArray[0] == 0)
        {
            // The MRW didn't have any MSL EC levels to check against.
            HWAS_INF("validateEcMslLevels: MSL Array was found to be empty. Skipping MSL_CHECK verification.");
            break;
        }

        // Walk the MSL_CHECK array and add each entry to the map.
        std::map<chipId_t, std::vector<ecLevel_t>> ecLevel_map;
        auto it = i_mslArray.begin();
        while (it != i_mslArray.cend())
        {
            const mslEntry_t * const entry = reinterpret_cast<mslEntry_t *>(it);
            if (entry->iv_chipId == 0)
            {
                // No more entries to process
                break;
            }
            HWAS_DBG("validateEcMslLevels: Adding Chip Id 0x%04X with EC Level 0x%02X to MRW list.",
                     entry->iv_chipId,
                     entry->iv_ecLevel);
            ecLevel_map[entry->iv_chipId].push_back(entry->iv_ecLevel);
            // Move to the start of the next entry
            std::advance(it, 2);
        }

        // Get a list of all chips in the system. For each one, if it has a chip id in the EC level map then its EC
        // level must be one of the specified EC levels from the map.
        TargetHandleList chips;
        getAllChips(chips, TYPE_NA);
        for (const auto chip : chips)
        {
            // Get chip id
            ATTR_CHIP_ID_type chipId = 0;
            ATTR_EC_type ecLevel = 0;
            if ( !chip->tryGetAttr<ATTR_CHIP_ID>(chipId) ||
                 !chip->tryGetAttr<ATTR_EC>(ecLevel) )
            {
                HWAS_DBG("validateEcMslLevels: chip[%.08X] has CHIP_ID? %d, has EC? %d",
                         get_huid(chip),
                         chip->tryGetAttr<ATTR_CHIP_ID>(chipId),
                         chip->tryGetAttr<ATTR_EC>(ecLevel));
                // Chip doesn't have the necessary attributes, go to the next one.
                continue;
            }

            // See if this chip has a chip id in the map.
            if (ecLevel_map.find(chipId) != ecLevel_map.end())
            {
                // Compare EC level to each level in map.
                const std::vector<ecLevel_t> & validEcLevels = ecLevel_map[chipId];
                bool matchFound = false;
                for (const auto level : validEcLevels)
                {
                    if (ecLevel == level)
                    {
                        // A match was found in the MRW, break out.
                        matchFound = true;
                        break;
                    }
                }
                if ( !matchFound )
                {
                    HWAS_ERR("validateEcMslLevels: Couldn't find a valid EC level in the MSL_CHECK array for "
                             "HUID 0x%.08X with EC level of 0x%.02X", get_huid(chip), ecLevel);
                    /*@
                      * @errortype
                      * @severity           ERRL_SEV_UNRECOVERABLE
                      * @moduleid           MOD_VALIDATE_EC_MSL_LEVELS
                      * @reasoncode         RC_EC_MISMATCH
                      * @devdesc            Found a chip which has an EC level that is not in the MSL list from the MRW
                      * @custdesc           An incompatible chip level was found in the system.
                      * @userdata1[00:31]   HUID of the chip
                      * @userdata1[32:63]   EC level of the chip
                      * @userdata2          Unused
                      */
                    error = hwasError(ERRL_SEV_UNRECOVERABLE,
                                      MOD_VALIDATE_EC_MSL_LEVELS,
                                      RC_EC_MISMATCH,
                                      TWO_UINT32_TO_UINT64(get_huid(chip), ecLevel),
                                      0);
                    platHwasErrorAddHWCallout(error,
                                              chip,
                                              SRCI_PRIORITY_HIGH,
                                              DECONFIG,
                                              GARD_NULL);
                    // If an error occurred before then link this one to the earlier one.
                    hwasErrorUpdatePlid(error, commonPlid);
                    errlCommit(error, HWAS_COMP_ID);
                    numberOfInvalidChips++;
                    // Move onto the next chip.
                    continue;
                }
            }
            else
            {
                // Chip ID not present in MRW list. Move on to the next chip.
                HWAS_DBG("validateEcMslLevels: Chip 0x%08X, ID 0x%04X, was not in the MRW list",
                         get_huid(chip),
                         chipId);
                continue;
            }
        }
    } while(0);

    if (commonPlid != 0)
    {
        /*@
          * @errortype
          * @severity           ERRL_SEV_UNRECOVERABLE
          * @moduleid           MOD_VALIDATE_EC_MSL_LEVELS
          * @reasoncode         RC_FAILED_MSL_EC_VALIDATION
          * @devdesc            One or more chips had an unsupported EC level compared to the given MRW values.
          * @custdesc           One or more incompatible chip levels were found in the system.
          * @userdata1[00:63]   Number of failing chips
          * @userdata2[00:31]   MSL_CHECK MNFG flag state 1=set,0=unset
          * @userdata2[32:63]   Unused
          */
        error = hwasError(ERRL_SEV_UNRECOVERABLE,
                          MOD_VALIDATE_EC_MSL_LEVELS,
                          RC_FAILED_MSL_EC_VALIDATION,
                          numberOfInvalidChips,
                          TWO_UINT32_TO_UINT64(isMslChecksSet() ? 1 : 0, 0));
        hwasErrorUpdatePlid(error, commonPlid);
    }

    return error;

}

// Wrapper function to call the correct version of the templated validateEcMslLevels function based on the MSL_CHECKS
// manufacturing flag
errlHndl_t validateEcMslLevels()
{
    const Target* sys = UTIL::assertGetToplevelTarget();
    errlHndl_t error = nullptr;

    // Check MNFG flag
    if (TARGETING::isMslChecksSet())
    {
        error = validateEcMslLevels<ATTR_MSL_MFG_ALLOW>(sys->getAttrAsStdArr<ATTR_MSL_MFG_ALLOW>());
    }
    else
    {
        error = validateEcMslLevels<ATTR_MSL_FIELD_SUPPORTED>(sys->getAttrAsStdArr<ATTR_MSL_FIELD_SUPPORTED>());
    }
    return error;
}
#endif // defined __HOSTBOOT_MODULE not defined CONFIG_FSP_BUILD

errlHndl_t discoverTargets()
{
    HWAS::HWASDiscovery l_HWASDiscovery;
    return l_HWASDiscovery.discoverTargets();
}

errlHndl_t HWASDiscovery::discoverTargets()
{
    HWAS_DBG("discoverTargets entry");
    errlHndl_t errl = nullptr;

    //  loop through all the targets and set HWAS_STATE to a known default
    for (TargetIterator target = targetService().begin();
            target != targetService().end();
            ++target)
    {
        // TODO:RTC:151617 Need to find a better way
        // to initialize the target
        TARGETING::ATTR_INIT_TO_AVAILABLE_type initToAvailable = false;
        HwasState hwasState = target->getAttr<ATTR_HWAS_STATE>();
        if(   (target->tryGetAttr<TARGETING::ATTR_INIT_TO_AVAILABLE>(
                   initToAvailable))
           && (initToAvailable))
        {
            hwasState.poweredOn          = true;
            hwasState.present            = true;
            hwasState.functional         = true;
        }
        else
        {
            hwasState.poweredOn          = false;
            hwasState.present            = false;
            hwasState.functional         = false;
        }
        hwasState.deconfiguredByEid  = 0;
        hwasState.dumpfunctional     = false;
        hwasState.functionalOverride = false;
        target->setAttr<ATTR_HWAS_STATE>(hwasState);
    }

    // Assumptions and actions:
    // CLASS_SYS (exactly 1) - mark as present
    // CLASS_ENC, TYPE_PROC, TYPE_MEMBUF, TYPE_DIMM
    //     (ALL require hardware query) - call platPresenceDetect
    //  \->children: CLASS_* (NONE require hardware query) - mark as present
    do
    {
        // find CLASS_SYS (the top level target)
        Target* pSys;
        targetService().getTopLevelTarget(pSys);

        HWAS_ASSERT(pSys,
                "HWAS discoverTargets: no CLASS_SYS TopLevelTarget found");

        // mark this as present
        enableHwasState(pSys, true, true, 0);
        HWAS_DBG("pSys %.8X - marked present",
            pSys->getAttr<ATTR_HUID>());

        // Certain targets have dependencies on the MUX, so it is best to
        // presence detect and enable the MUX before moving on to these targets.
        // Please take this into consideration if code needs to be rearranged
        // in the future.
        errl = discoverMuxTargetsAndEnable(*pSys);

        if (errl != nullptr)
        {
            break; // break out of the do/while so that we can return
        }

        PredicateCTM predEnc(CLASS_ENC);
        PredicateCTM predChip(CLASS_CHIP);
        PredicateCTM predDimm(CLASS_LOGICAL_CARD, TYPE_DIMM);

        // We can ignore chips of TYPE_I2C_MUX because they
        // were already detected above in discoverMuxTargetsAndEnable
        // Also we can ignore chips of type PMIC because they will be processed
        // below.
        PredicateCTM predMux(CLASS_CHIP, TYPE_I2C_MUX);
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predChip).push(&predDimm).Or().push(&predEnc).Or().
                  push(&predMux).Not().And();

        TargetHandleList pCheckPres;
        targetService().getAssociated( pCheckPres, pSys,
            TargetService::CHILD, TargetService::ALL, &checkExpr );

        // pass this list to the hwas platform-specific api where
        // pCheckPres will be modified to only have present targets
        HWAS_DBG("pCheckPres size: %d", pCheckPres.size());
        errl = platPresenceDetect(pCheckPres);
        HWAS_DBG("pCheckPres size: %d", pCheckPres.size());

        if (errl != nullptr)
        {
            break; // break out of the do/while so that we can return
        }

        // for each, read their ID/EC level. if that works,
        //  mark them and their descendants as present
        //  read the partialGood vector to determine if any are not functional
        //  and read and store values from the PR keyword

        // list of procs and data that we'll need to look at when potentially
        //  reducing the list of valid ECs later
        procRestrict_t l_procEntry;
        std::vector <procRestrict_t> l_procRestrictList;

        // List to track targets marked as non-functional by their VPD data.
        // After all non-functional targets are collected, their corresponding
        // ATTR_PG attributes will be marked as non-functional.
        TargetHandleList l_deconfigTargets;

        // sort the list by ATTR_HUID to ensure that we
        //  start at the same place each time
        std::sort(pCheckPres.begin(), pCheckPres.end(),
                compareTargetHuid);

        for (TargetHandleList::const_iterator pTarget_it = pCheckPres.begin();
                pTarget_it != pCheckPres.end();
                ++pTarget_it
            )
        {
            TargetHandle_t pTarget = *pTarget_it;

            // if CLASS_ENC is still in this list, mark as present
            if (pTarget->getAttr<ATTR_CLASS>() == CLASS_ENC)
            {
                enableHwasState(pTarget, true, true, 0);
                HWAS_DBG("pTarget %.8X - CLASS_ENC marked present",
                    pTarget->getAttr<ATTR_HUID>());

                // on to the next target
                continue;
            }

            bool chipPresent = true;
            bool chipFunctional = true;
            bool createInfoLog = false;
            uint32_t errlEid = 0;

            // First we read the PGV into pgData as packed 3-byte integers,
            // then we zero-extend the entries into pg_entry_t elements
            std::array<uint8_t, VPD_CP00_PG_DATA_LENGTH> pgData = { };
            partialGoodVector pgData_expanded = { };

            // Cache the target type
            auto l_targetType = pTarget->getAttr<ATTR_TYPE>();

            // This error is created preemptively to capture any targets that
            // were deemed non-functional for partial good reasons. If there are
            // no issues, then this error log is deleted.
            /*@
             * @errortype
             * @severity        ERRL_SEV_INFORMATIONAL
             * @moduleid        MOD_DISCOVER_TARGETS
             * @reasoncode      RC_PARTIAL_GOOD_INFORMATION
             * @devdesc         Informational log that contains information
             *                  about which targets, procs, and entries in the
             *                  processor module vpd PG vector are marked as
             *                  nonfunctional.  This is NOT an indication of
             *                  a problem in this part.
             * @custdesc        An informational event
             * @userdata1       Processor HUID
             * @userdata2       None
             */
            errlHndl_t infoErrl = hwasError(ERRL_SEV_INFORMATIONAL,
                                            MOD_DISCOVER_TARGETS,
                                            RC_PARTIAL_GOOD_INFORMATION,
                                            get_huid(pTarget));

            if(   (pTarget->getAttr<ATTR_CLASS>() == CLASS_CHIP)
               && (l_targetType != TYPE_TPM)
               && (l_targetType != TYPE_SP)
               && (l_targetType != TYPE_BMC)
               && (l_targetType != TYPE_I2C_MUX))
            {
                // read Chip ID/EC data from these physical chips
                errl = platReadIDEC(pTarget);
                if (errl)
                {
                    // read of ID/EC failed even tho we THOUGHT we were present.
                    HWAS_INF("pTarget 0x%.8X - read IDEC failed "
                             "(eid 0x%X) - bad",
                             get_huid(pTarget), errl->eid());

                    // chip NOT present and NOT functional, so that FSP doesn't
                    // include this for HB to process
                    chipPresent = false;
                    chipFunctional = false;
                    errlEid = errl->eid();

                    // commit the error but keep going
                    errlCommit(errl, HWAS_COMP_ID);
                    // errl is now nullptr
                }
                else if (l_targetType == TYPE_PROC)
                {
                    // read partialGood vector from these as well.
                    errl = platReadPartialGood(pTarget, &pgData[0]);
                    if (errl)
                    {   // read of PG failed even tho we were present..
                        HWAS_INF("pTarget 0x%.8X - read PG failed "
                                 "(eid 0x%X) - bad",
                                 get_huid(pTarget), errl->eid());
                        chipFunctional = false;
                        errlEid = errl->eid();

                        // commit the error but keep going
                        errlCommit(errl, HWAS_COMP_ID);
                        // errl is now nullptr
                    }
                    else
                    {
                        parsePgData(pgData, pgData_expanded);

                        // look at the 'nest' logic to override the
                        //  functionality of this proc
                        chipFunctional =
                            isChipFunctional(pTarget, pgData_expanded);

                        if(!chipFunctional)
                        {
                            // Add this proc to the informational error log.
                            platHwasErrorAddHWCallout(infoErrl,
                                                      pTarget,
                                                      SRCI_PRIORITY_HIGH,
                                                      NO_DECONFIG,
                                                      GARD_NULL);

                            createInfoLog = true;
                        }


                        // Fill in a dummy restrict list
                        l_procEntry.target = pTarget;
                        // every proc is uniquely counted
                        l_procEntry.group = pTarget->getAttr<ATTR_HUID>();
                        // just 1 proc per group
                        l_procEntry.procs = 1;
                        // indicates we should use all available ECs
                        l_procEntry.maxECs = UINT32_MAX;
                        l_procRestrictList.push_back(l_procEntry);
                    }
                } // TYPE_PROC
            } // CLASS_CHIP

            HWAS_DBG("pTarget %.8X - detected present, %sfunctional",
                pTarget->getAttr<ATTR_HUID>(),
                chipFunctional ? "" : "NOT ");

            // Now determine if the descendants of this target are
            // present and/or functional
            checkPartialGoodForDescendants(pTarget,
                                           pgData_expanded,
                                           chipFunctional,
                                           errlEid,
                                           infoErrl,
                                           &createInfoLog,
                                           false, // is code running in testcase
                                           nullptr, // testcases result
                                           &l_deconfigTargets);

            // set HWAS state to show CHIP is present, functional per above
            enableHwasState(pTarget, chipPresent, chipFunctional, errlEid);

            // If there were partial good issues with the chip or its
            // descendents then create an info error log. Otherwise, delete
            // and move on.
            if (createInfoLog)
            {
                TargetHandle_t l_masterProc = nullptr;

                //Get master proc
                errl =
                    targetService()
                        .queryMasterProcChipTargetHandle(l_masterProc);
                if (errl)
                {
                    HWAS_ERR("discoverTargets: unable to get master proc");
                    errlCommit(errl, HWAS_COMP_ID);
                    errlCommit(infoErrl, HWAS_COMP_ID);
                    break;
                }

                auto l_model = l_masterProc->getAttr<ATTR_MODEL>();

                // Setup model-dependent all good data
                model_ag_entries l_modelPgData = { };

                // Insert model-depdendent entries here (there are none right
                // now for P10)
                (void)l_model;

                hwasErrorAddPartialGoodFFDC(infoErrl, l_modelPgData, pgData_expanded);
                errlCommit(infoErrl, HWAS_COMP_ID);
            }
            else
            {
                delete infoErrl;
                infoErrl = nullptr;
            }
        } // for pTarget_it

        // Deconfigure targets marked as not functional by their MVPD data (will
        // update ATTR_PG)
        for (auto& l_target : l_deconfigTargets)
        {

            HWAS_INF("discoverTargets: Updating PG mask (ATTR_PG) for %s with "
                "HUID %.8X because read as non-functional from VPD \n",
                l_target->getAttrAsString<ATTR_TYPE>(),
                l_target->getAttr<ATTR_HUID>());

            updateAttrPG(*l_target, false);
        }

        // After processing all other targets look at the pmics,
        // we must wait because we need the SPD cached from the OCMBs
        // which occurs when OCMBs go through presence detection above
        errl = discoverPmicTargetsAndEnable(*pSys);
        if (errl != NULL)
        {
            break; // break out of the do/while so that we can return
        }

        // After processing PMICs look at the Generic I2C Slaves
        errl = discoverGenericI2cDeviceTargetsAndEnable(*pSys);
        if (errl != NULL)
        {
            break; // break out of the do/while so that we can return
        }

        // After processing Generic I2C slaves, look at the MDS
        errl = discoverMdsTargetsAndEnable(*pSys);
        if (errl != NULL)
        {
            break; // break out of the do/while so that we can return
        }

        // Check for non-present Procs and if found, trigger
        // DeconfigGard::_invokeDeconfigureAssocProc() to run by setting
        // setXAOBusEndpointDeconfigured to true
        PredicateCTM predProc(CLASS_CHIP, TYPE_PROC);
        TargetHandleList l_procs;
        targetService().getAssociated(l_procs,
                                      pSys,
                                      TargetService::CHILD,
                                      TargetService::ALL,
                                      &predProc);

        for (const auto proc : l_procs)
        {
            if ( !proc->getAttr<ATTR_HWAS_STATE>().present )
            {
                HWAS_INF("discoverTargets: Proc %.8X not present",
                    proc->getAttr<ATTR_HUID>());
                HWAS::theDeconfigGard().setXAOBusEndpointDeconfigured(true);
            }
            else if (proc->getAttr<ATTR_HWAS_STATE>().functional)
            {
                // Determine if there are cores that can be used for Extended Cache-Only (ECO) mode.
                TargetHandleList l_coreList;
                getChildChiplets(l_coreList, proc, TYPE_CORE);
                errl = platDetermineEcoCores(l_coreList);
                if (errl)
                {
                    break;
                }
            }
        }
        if (errl)
        {
            break;
        }

#if defined(__HOSTBOOT_MODULE) && !defined(CONFIG_FSP_BUILD)
        // Check all CHIP targets in the system to ensure that they have an EC level that matches with one of
        // what the MRW provides. What levels are valid are given by the state of MFG_FLAGS_MNFG_MSL_CHECK.
        errl = validateEcMslLevels();
        if (errl)
        {
            HWAS_ERR("discoverTargets: validateEcMslLevels failed");
            break;
        }
#endif

        //Check all of the secondary processor's EC levels to ensure they match master
        //processor's EC level.
        //function will return error log pointing to all error logs created
        //by this function as this function could detect multiple procs w/
        //bad ECs and will make a log for each
        errl = validateProcessorEcLevels();

        if (errl)
        {
            HWAS_ERR("discoverTargets: validateProcessorEcLevels failed");
            break;
        }

        // Potentially reduce the number of ec/core units that are present
        // based on fused mode
        // deconfigReason = 0 because this is not a deconfigured event.
        // Units that get knocked out will be marked present=false
        // function = false.
        errl = restrictECunits(l_procRestrictList, 0);
        if (errl)
        {
            HWAS_ERR("discoverTargets: restrictECunits failed");
            break;
        }

        // call invokePresentByAssoc() to obtain functional memory hierarchy
        // info.invokePresentByAssoc calls algorithm function presentByAssoc()
        // to determine targets that need to be deconfigured
        invokePresentByAssoc();

        // NMMU1 is power-gated if PAU0, PAU4, and PAU5 are deconfigured, so we
        // handle that case here after all the PAUs have been deconfigured by PG
        // rules
        {
            TargetHandleList l_chips;
            getAllChips(l_chips, TYPE_PROC, true);

            for (const Target* const l_chip : l_chips)
            {
                if (Target* const l_nmmu1 = shouldPowerGateNMMU1(*l_chip))
                {
                    enableHwasState(l_nmmu1,
                                    true, // NMMU 1 will always be present
                                    false,
                                    DeconfigGard::DECONFIGURED_BY_INACTIVE_PAU);
                }
            }
        }

        // If PAUs got deconfigured, we need to ensure we don't try to use OCAPI
        // IOHSes that won't have a corresponding PAU when the IOHS/PAU pairs
        // get mapped.
        {
            TargetHandleList paucs;
            getAllChiplets(paucs, TYPE_PAUC, true);

            for (const auto pauc : paucs)
            {
                const auto iohsList = disableExtraOcapiIohsTargets(pauc);

                for (const auto iohs : iohsList)
                {
                    enableHwasState(iohs,
                                    true, // The IOHS started as functional, so must be present
                                    false, // non-functional
                                    DeconfigGard::DECONFIGURED_BY_INACTIVE_PAU);
                }
            }
        }

        deconfigureBussesWithNullPeer();

#if( defined(CONFIG_SUPPORT_EEPROM_CACHING)  )
        // call this after all targets have cached their eeprom vpd
        // This will cover the roles that cannot determine if eeprom has updated
        EEPROM::cacheEepromAncillaryRoles();
#endif
    } while (0);

    if (errl)
    {
        HWAS_INF("discoverTargets failed (plid 0x%X)", errl->plid());
    }
    else
    {
        HWAS_INF("discoverTargets completed successfully");
    }
    return errl;
} // discoverTargets


bool isChipFunctional(const TARGETING::TargetHandle_t &i_target,
                      const partialGoodVector& i_pgData)
{
    bool l_chipFunctional = true;

    for (size_t i = 0; i < ALWAYS_GOOD_INDEX_SIZE; ++i)
    {
        const auto l_index = VPD_CP00_PG_ALWAYS_GOOD_INDEX[i];
        const auto l_always_good_mask = VPD_CP00_PG_ALWAYS_GOOD_MASKS[i];

        if (i_pgData[l_index] & l_always_good_mask)
        {
            const char* const l_name = i_target->getAttrAsString<ATTR_TYPE>();

            HWAS_INF("pTarget %.8X - %s pgData[%d]: "
                     "actual 0x%08X, expected 0x%08X - bad",
                     i_target->getAttr<ATTR_HUID>(),
                     l_name, l_index, i_pgData[l_index], l_always_good_mask);
            l_chipFunctional = false;
            break;
        }
    }

    return l_chipFunctional;
} // isChipFunctional

bool isDescFunctional(const TARGETING::TargetHandle_t &i_desc,
                      const partialGoodVector& i_pgData,
                      pgState_map &io_targetStates,
                      TARGETING::TargetHandleList *io_deconfigTargets /* = nullptr */)
{
    bool l_functional = true, l_previouslySeen = false;

    do {

        // Look in the targetStates map to see if the target has been given a
        // state already. If it's not in the map, then continue with the
        // algorithm. Otherwise, only continue if the state was marked as
        // functional. Since the list input into isDescFunctional is sorted
        // where all of the children are first in the array, then if the current
        // target is found in io_targetStates and it's not functional that means
        // that it has no functional children and we shouldn't do any further
        // checking on it.
        auto selfState_it = io_targetStates.find(i_desc);
        if ((selfState_it != io_targetStates.end())
            && (selfState_it->second != true))
        {
            // This target has been seen, return.
            l_previouslySeen = true;
            l_functional = selfState_it->second;
            break;
        }

        // Only check PG rules if this target is descended from a PROC
        // target (because PG rules only apply to PROCs). Additionally, FSP
        // has targets that are descended from PROCs that should not be
        // checked either. This will all be handled below.
        {
            TargetHandleList procParent, pervParent;

            PredicateCTM predicate;
            predicate.setType(TYPE_PROC);

            // Get parent by containment
            targetService().getAssociated(procParent,
                                          i_desc,
                                          TargetService::PARENT,
                                          TargetService::ALL,
                                          &predicate);

            getParentPervasiveTargetsByState(pervParent,
                                             i_desc,
                                             CLASS_UNIT,
                                             TYPE_PERV,
                                             UTIL_FILTER_ALL);

            bool lacksProcParent = procParent.empty(),
                 lacksPervParent = pervParent.empty(),
                 isPervType = i_desc->getAttr<ATTR_TYPE>() == TYPE_PERV;

            // FSP only targets descended from PROC don't have a pervasive
            // parent. So, if this descendent doesn't have a pervasive
            // parent nor a proc parent then it's one of the FSP targets
            // that shouldn't be checked.
            if (lacksProcParent || (lacksPervParent && !isPervType))
            {
                break;
            }
        }

        // Since the target has at least one functional child (or no children),
        // next we must apply the correct partial good rules to determine
        // functionality.
        //
        // Lookup the correct partial good logic for the given target. To avoid
        // errors of omission, the lookup must return at least one pg logic
        // struct. If a target has no associated rules then an NA rule will be
        // returned that was created by the default constructor which will cause
        // the next for loop to function as a no-op.
        const PARTIAL_GOOD::PartialGoodRule* pgRule_it = nullptr;
        size_t numPgRules = 0;

        errlHndl_t l_returnErrl
            = PARTIAL_GOOD::findRulesForTarget(i_desc, pgRule_it, numPgRules);

        if (l_returnErrl != nullptr)
        {
            errlCommit(l_returnErrl, HWAS_COMP_ID);
            break;
        }

        TARGETING::ATTR_CHIP_UNIT_type l_targetCU = 0;

        if (!i_desc->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_targetCU))
        {
            break;
        }

        // Iterate through the list of partial good logic for this target. If
        // any of them fail then the target is non-functional.
        for(size_t i = 0; i < numPgRules; ++i, ++pgRule_it)
        {
            if (pgRule_it->isApplicableToChipUnit(l_targetCU)
                && pgRule_it->isApplicableToCurrentModel())
            {
                l_functional = pgRule_it->isFunctional(i_desc, i_pgData);

                if (!l_functional)
                {
                    // Record target who are not functional as marked by their
                    // VPD data
                    if (io_deconfigTargets != nullptr)
                    {
                        io_deconfigTargets->push_back(i_desc);
                    }

                    char msg[128] = { };
                    pgRule_it->formatDebugMessage(i_desc, i_pgData, msg, sizeof(msg));

                    HWAS_INF("pDesc 0x%.8X - %s - bad",
                             i_desc->getAttr<ATTR_HUID>(),
                             msg);

                    break;
                }
            }
        }
    } while(0);

    if (!l_previouslySeen)
    {
        // Record the result in the targetStates map for later use.
        io_targetStates[i_desc] = l_functional;
    }

    return l_functional;
}

void markChildrenNonFunctional(const TARGETING::TargetHandle_t &i_parent,
                               pgState_map &io_targetStates)
{

    // Get the state for the parent.
    auto parentState_it = io_targetStates.find(i_parent);

    if ((parentState_it != io_targetStates.end()) && !parentState_it->second)
    {
        // Parent is non-functional. So get the list of all children
        // and mark them non-functional as well.
        TargetHandleList pDescChildren;
        targetService().getAssociated(pDescChildren, i_parent,
                                      TargetService::CHILD,
                                      TargetService::IMMEDIATE);

        for(auto child : pDescChildren)
        {
            auto childState_it = io_targetStates.find(child);

            if (childState_it != io_targetStates.end())
            {
                // Ignore children that are already non-functional because the
                // first part of the partial good algorithm was done by starting
                // at the bottom of the target hierarchy and working up to the
                // top. Since this function is called while operating top-down,
                // that means if there is a child of this target that is
                // non-functional which has functional children we don't have to
                // deal with it now since it will eventually be passed into this
                // function as the parent target and its functional children
                // will be taken care of at that time.
                if (childState_it->second == true)
                {
                    // Child state is true so change it to false.
                    childState_it->second = false;

                    // Since this child's state is true it may have functional
                    // children that need to be marked non-functional. So, we
                    // should check this child's children.
                    TargetHandleList pGrandChildren;
                    targetService().getAssociated(pGrandChildren, child,
                                                 TargetService::CHILD,
                                                 TargetService::IMMEDIATE);

                    if (!pGrandChildren.empty())
                    {
                        markChildrenNonFunctional(child, io_targetStates);
                    }
                }
            }
            else
            {
                // Child is missing from the targetStates map. Insert it and
                // mark it non-functional.
                // NOTE: This won't happen during the actual PG algorithm but
                //       is left here to be used for testcases or other uses.
                io_targetStates[child] = false;

                // Since the child was missing and its state is unknown, check
                // if it has any children and make those non-functional as well.
                TargetHandleList pGrandChildren;
                targetService().getAssociated(pGrandChildren, child,
                                             TargetService::CHILD,
                                             TargetService::IMMEDIATE);

                if (!pGrandChildren.empty())
                {
                    markChildrenNonFunctional(child, io_targetStates);
                }
            }
        }
    }
}

errlHndl_t checkPartialGoodForDescendants(
        const TARGETING::TargetHandle_t &i_pTarget,
        const partialGoodVector& i_pgData,
        const bool i_chipFunctional,
        const uint32_t i_errlEid,
        errlHndl_t io_infoErrl,
        bool* io_createInfoLog,
        bool i_isTestcase /* = false */,
        bool* o_testResult /* = nullptr */,
        TARGETING::TargetHandleList* io_deconfigTargets /* = nullptr */
        )
{

    errlHndl_t errl = nullptr;

    // A map that will keep track of what has already been checked to
    // eliminate re-checking targets. It also holds functional state.
    pgState_map targetStates;

    // by default, the descendant's functionality is 'inherited'
    bool descFunctional = i_chipFunctional;

    // Get a list of this target's physical descendants
    TargetHandleList pDescList;

    targetService().getAssociated( pDescList, i_pTarget,
        TargetService::CHILD, TargetService::ALL);

    if (i_isTestcase)
    {
        // If we are running a testcase then i_pTarget is the target to be
        // checked and the children of i_pTarget should be checked along with
        // it. So, add it to the list and the algorithm will check it too.
        pDescList.push_back(i_pTarget);
    }

    if (i_chipFunctional)
    {
        // Sort the list of descendants such that the largest affinity
        // paths are first in the list and targets are grouped by
        // parent.
        std::sort(pDescList.begin(), pDescList.end(),
                  // Define a lambda comparator function for sorting
                  // criteria.
                  [](const TargetHandle_t a, const TargetHandle_t b)
                  {
                        EntityPath aPath =
                            a->getAttr<ATTR_AFFINITY_PATH>();

                        TargetHandle_t aParent =
                            getImmediateParentByAffinity(a);

                        EntityPath bPath =
                            b->getAttr<ATTR_AFFINITY_PATH>();

                        TargetHandle_t bParent =
                            getImmediateParentByAffinity(b);


                        // a goes before b if its affinity path is
                        // greater than b's and its parent pointer
                        // is different from b's.
                        bool result = false;
                        if ((aPath.size() > bPath.size())
                            || ((aPath.size() == bPath.size())
                                && (aParent > bParent)))
                        {
                            result = true;
                        }

                        return result;
                  });

        // A pointer to a descendant's parent. This will be updated as
        // the first pass of PG checking occurs.
        TargetHandle_t parent = nullptr;

        // Assume the parent has no functional children and the
        // descendant's state is false.
        bool parentState = false, descState = false;

        // =========== Partial Good Checking First Pass ===========
        // Now that the list of descendants has been sorted, we can
        // proceed with the PG algorithm in two passes. In this pass,
        // the target hierarchy is navigated from the bottom up to the
        // top.
        //
        // This pass will check all children of a parent and when it
        // encounters a new parent, it will set the previous parent's
        // state as true or false.
        //      true: the parent has at least one functional child
        //      false: the parent has no functional children.
        // By setting a parent's state false ahead of time
        // isDescFunctional is able to skip over that target since,
        // regardless of PG results, that target will still be
        // non-functional due to not having functional children.
        for (auto pDesc : pDescList)
        {
            // Check if the parent has changed during iteration. If it
            // has then all of the children of that parent have been
            // checked and we now know if it has any functional
            // children. So, add the parent to targetStates with the
            // result.
            if (getImmediateParentByAffinity(pDesc) != parent)
            {
                if (parent != nullptr)
                {
                    // Add parent's state to the targetStates map.
                    // Note: If parentState has remained non-functional then
                    //       that means that it had no functional children
                    //       which is not allowed. So, PG checks will be
                    //       skipped for it when it is passed into
                    //       isDescFunctional.
                    targetStates[parent] = parentState;

                    if (parentState == false)
                    {
                        // No functional children of this target were found.
                        // Target is considered not functional.
                        HWAS_INF("pDesc parent 0x%.8X - marked bad because "
                                 "all of its children were bad.",
                                 parent->getAttr<ATTR_HUID>());
                    }
                }
                // Update parent pointer to the new parent.
                parent = getImmediateParentByAffinity(pDesc);

                // Reset parentState to false.
                parentState = false;
            }

            descState = isDescFunctional(pDesc,
                                         i_pgData,
                                         targetStates,
                                         io_deconfigTargets);

            // If one descendant of the current parent is functional,
            // then the parent is functional and should be checked by
            // isDescFunctional for partial good issues.
            if (descState == true)
            {
                parentState = true;
            }

            // Special case: don't mark PAUCs bad for lack of functional
            // children.
            if(parent->getAttr<ATTR_TYPE>() == TYPE_PAUC)
            {
                parentState = true;
            }
        }
    }

    // =========== Partial Good Checking Second Pass ===========
    // After the first pass completes, all targets have had PG checks
    // applied to them (if necessary) and all parents have been checked
    // to have at least one functional child. Now we iterate through the
    // list one final time in reverse and propagate all non-functional
    // parent states down to functional children, since functional
    // children must not have non-functional parents.
    //
    // As the algorithm works its way through the hierarchy in a
    // top-down fashion, the final hwasState of the current target is
    // known and can be set as it works through all of the targets this
    // time.
    //
    // NOTE: If the chip is not functional then the first pass will not execute
    //       and this iteration will serve only to mark all descendants
    //       non-functional.
    TargetHandleList::const_iterator pDescList_rbegin = pDescList.end() - 1;
    TargetHandleList::const_iterator pDescList_rend = pDescList.begin() - 1;

    for (TargetHandleList::const_iterator pDesc_it = pDescList_rbegin;
         pDesc_it != pDescList_rend; --pDesc_it)
    {
        TargetHandle_t pDesc = *pDesc_it;

        if (i_chipFunctional)
        {

            // If this descendant is non-functional then
            // propagate non-functional state down to its children.
            markChildrenNonFunctional(pDesc,
                                      targetStates);

            auto pDesc_mapIt = targetStates.find(pDesc);
            if (pDesc_mapIt != targetStates.end())
            {
                descFunctional = pDesc_mapIt->second;
            }
            else
            {
                /*@
                 * @errortype
                 * @severity        ERRL_SEV_UNRECOVERABLE
                 * @moduleid        MOD_CHECK_PG_FOR_DESC
                 * @reasoncode      RC_PARTIAL_GOOD_MISSING_TARGET
                 * @devdesc         A target was not found in the map of
                 *                  states kept by the PG checking
                 *                  algorithm. Therefore, it did not have
                 *                  PG checks run against it.
                 * @custdesc        An issue occurred during IPL of the
                 *                  system: Internal Firmware Error
                 * @userdata1       huid of the target
                 */
                 errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                                  MOD_CHECK_PG_FOR_DESC,
                                  RC_PARTIAL_GOOD_MISSING_TARGET,
                                  pDesc->getAttr<ATTR_HUID>());
                 break;
            }

            if(!descFunctional && !i_isTestcase)
            {
                // Add this descendant to the error log.
                hwasErrorAddTargetInfo(io_infoErrl, pDesc);
                *io_createInfoLog = true;
            }
        }

        // Don't mess with the state of the system if we are doing test cases.
        if (!i_isTestcase)
        {
            if (pDesc->getAttr<ATTR_TYPE>() == TYPE_PERV)
            {
                // for sub-parts of PERV, it's always present.
                enableHwasState(pDesc, i_chipFunctional, descFunctional,
                            i_errlEid);
                HWAS_DBG("pDesc %.8X - marked %spresent, %sfunctional",
                    pDesc->getAttr<ATTR_HUID>(),
                    i_chipFunctional ? "" : "NOT",
                    descFunctional ? "" : "NOT ");
            }
            else
            {
                // for other sub-parts, if it's not functional,
                // it's not present.
                enableHwasState(pDesc, descFunctional, descFunctional,
                            i_errlEid);
                HWAS_DBG("pDesc %.8X - marked %spresent, %sfunctional",
                    pDesc->getAttr<ATTR_HUID>(),
                    descFunctional ? "" : "NOT ",
                    descFunctional ? "" : "NOT ");
            }
        }
    }

    // Before we return, if this was run in a testcase then we should set the
    // o_testResult parameter so the testcase is aware of i_pTarget's state.
    if (i_isTestcase && (o_testResult != nullptr))
    {
        *o_testResult = targetStates[i_pTarget];
    }

    return errl;

}

void forceEcFcDeconfig(const TARGETING::TargetHandle_t i_core,
                       const bool i_present,
                       const uint32_t i_deconfigReason)
{
    TargetHandleList pFCList;
    HwasState hwasState = {};
    bool l_deconfig_by_fco = (i_deconfigReason ==
                              HWAS::theDeconfigGard().DECONFIGURED_BY_FIELD_CORE_OVERRIDE);
    //Deconfig the EC
    enableHwasState(i_core, i_present, false, i_deconfigReason);

    if (l_deconfig_by_fco)
    {
        // set functionalOverride so HB and BMC will treat as functional
        // during reconfig loops
        hwasState = i_core->getAttr<ATTR_HWAS_STATE>();
        hwasState.functionalOverride = 1;
        i_core->setAttr<ATTR_HWAS_STATE>(hwasState);
    }

    HWAS_INF("pEC HUID 0x%08X - marked %spresent, NOT functional, functionalOverride = %d "
             "%sset functional on BMC reboot",
             i_core->getAttr<ATTR_HUID>(),
             i_present ? "" : "NOT ",
             hwasState.functionalOverride,
             hwasState.functionalOverride ? "" : "NOT ");

    //Get parent FC and see if any other cores, if none, deconfig
    TARGETING::Target* l_fc = getParent(i_core, TARGETING::TYPE_FC);
    getChildChiplets(pFCList, l_fc, TYPE_CORE, true);
    if(pFCList.size() == 0)
    {
        enableHwasState(l_fc, i_present, false, i_deconfigReason);
        if (l_deconfig_by_fco)
        {
            // set functionalOverride so HB and BMC will treat as functional
            // during reconfig loops
            hwasState = l_fc->getAttr<ATTR_HWAS_STATE>();
            hwasState.functionalOverride = 1;
            l_fc->setAttr<ATTR_HWAS_STATE>(hwasState);
        }

        HWAS_INF("pFC HUID 0x%08X - marked %spresent, NOT functional, functionalOverride = %d "
                 "%sset functional on BMC reboot",
                 l_fc->getAttr<ATTR_HUID>(),
                 i_present ? "" : "NOT ",
                 hwasState.functionalOverride,
                 hwasState.functionalOverride ? "" : "NOT ");
    }

}

errlHndl_t restrictECunits(
    std::vector <procRestrict_t> &i_procList,
    const uint32_t i_deconfigReason)
{
    HWAS_INF("restrictECunits entry, %d elements", i_procList.size());
    errlHndl_t errl = nullptr;
    TargetHandle_t l_primaryProcTarget = nullptr;

    do {

    errl = targetService().queryMasterProcChipTargetHandle(l_primaryProcTarget);
    if(errl)
    {
        HWAS_ERR( "restrictECunits:: Unable to find primary proc");
        break;
    }
    HWAS_DBG("primary proc huid: 0x%X", TARGETING::get_huid(l_primaryProcTarget));

    // sort by group so PROC# are in the right groupings.
    std::sort(i_procList.begin(), i_procList.end(),
                compareProcGroup);

    // loop thru procs to handle restrict
    const uint32_t l_ProcCount = i_procList.size();
    for (uint32_t procIdx = 0;
            procIdx < l_ProcCount;
            // the increment will happen in the loop to handle
            //  groups covering more than 1 proc target
        )
    {
        // determine the number of procs we should enable
        uint8_t procs = i_procList[procIdx].procs;
        int l_primaryProc = -1;
        uint32_t maxECs = i_procList[procIdx].maxECs;

        // this procs number, used to determine groupings
        uint32_t thisGroup = i_procList[procIdx].group;

        HWAS_INF("procRestrictList[%d] - maxECs 0x%X, procs %d, group %d",
                procIdx, maxECs, procs, thisGroup);

        // fcs, ecs, and iters for each proc in this vpd set
        TargetHandleList pFCList[procs];
        TargetHandleList::const_iterator pFC_it[procs];
        TargetHandleList pECList[procs][NUM_FC_PER_CHIP];
        TargetHandleList::const_iterator pEC_it[procs][NUM_FC_PER_CHIP];

        // find the proc's that we think are in this group
        uint32_t currentPairedECs = 0;
        uint32_t currentSingleECs = 0;
        for (uint32_t i = 0; i < procs; ) // increment in loop
        {
            TargetHandle_t pProc = i_procList[procIdx].target;

            // if this proc is past the last of the proc count
            //  OR is NOT in the same group
            if ((procIdx >= l_ProcCount) ||
                (thisGroup != i_procList[procIdx].group))
            {
                HWAS_DBG("procRestrictList[%d] - group %d not in group %d",
                        i, i_procList[procIdx].group, thisGroup);

                // change this to be how many we actually have here
                procs = i;

                // we're done - break so that we use procIdx as the
                //  start index next time
                break;
            }

            // is this proc the primary for this node?
            if (pProc == l_primaryProcTarget)
            {
                l_primaryProc = i;
            }

            // get this proc's (CHILD) FC units
            // Need to get all so we init the pEC_it array
            getChildChiplets(pFCList[i], pProc, TYPE_FC, false);

            if (!pFCList[i].empty())
            {
                // sort the list by ATTR_HUID to ensure that we
                //  start at the same place each time
                std::sort(pFCList[i].begin(), pFCList[i].end(),
                          compareTargetHuid);

                // keep a pointer into that list
                pFC_it[i] = pFCList[i].begin();

                for (uint32_t j = 0;
                     (j < NUM_FC_PER_CHIP) && (pFC_it[i] != pFCList[i].end());
                     j++)
                {
                    TargetHandle_t pFC = *(pFC_it[i]);

                    // Get this FC's (CHILD) functional EC/core units except the "Extended Cache-Only"
                    // cores since those are only used for their L3 cache.
                    getNonEcoCores(pECList[i][j], pFC);

                    // keep a pointer into that list
                    pEC_it[i][j] = pECList[i][j].begin();

                    if (!pECList[i][j].empty())
                    {
                        // sort the list by ATTR_HUID to ensure that we
                        //  start at the same place each time
                        std::sort(pECList[i][j].begin(), pECList[i][j].end(),
                                  compareTargetHuid);

                        // keep local count of current functional EC units
                        if (pECList[i][j].size() == 2)
                        {
                            // track ECs that can make a fused-core pair
                            currentPairedECs += pECList[i][j].size();
                        }
                        else
                        {
                            // track ECs without a pair for a fused-core
                            currentSingleECs += pECList[i][j].size();
                        }
                    }

                    // go to next FC
                    (pFC_it[i])++;
                } // for j < NUM_FC_PER_CHIP

                // go to next proc
                i++;
            }
            else
            {
                // this one is bad, stay on this i but lower the end count
                procs--;
            }

            // advance the outer loop as well since we're doing these
            //  procs together
            ++procIdx;
        } // for i < procs

        // adjust maxECs based on fused mode
        if( is_fused_mode() )
        {
            // only allow complete pairs
            maxECs = std::min( currentPairedECs, maxECs );
        }

        if ((currentPairedECs + currentSingleECs) <= maxECs)
        {
            // we don't need to restrict - we're done with this group.
            HWAS_INF("currentECs 0x%X <= maxECs 0x%X -- done",
                    (currentPairedECs + currentSingleECs), maxECs);
            continue;
        }

        HWAS_INF("primary proc idx: %d", l_primaryProc);

        HWAS_DBG("currentECs 0x%X > maxECs 0x%X -- restricting!",
                (currentPairedECs + currentSingleECs), maxECs);

        // now need to find EC units that stay functional, going
        // across the list of units for each proc and FC we have,
        // until we get to the max or run out of ECs, giving
        // preference to paired ECs and if we are in fused mode
        // excluding single, non-paired ECs.

        // Use as many paired ECs as we can up to maxECs
        uint32_t pairedECs_remaining =
            (maxECs < currentPairedECs) ? maxECs : currentPairedECs;
        // If not in fused mode, use single ECs as needed to get to maxECs
        uint32_t singleECs_remaining =
            ((maxECs > currentPairedECs) && !is_fused_mode())
            ? (maxECs - currentPairedECs) : 0;
        uint32_t goodECs = 0;
        HWAS_DBG("procs 0x%X maxECs 0x%X", procs, maxECs);

        // Keep track of when we allocate at least one core to the primary chip
        // in order to avoid the situation of primary not having any cores.
        bool l_allocatedToPrimary = false;

        // Each pECList has ECs for a given FC and proc. Check each EC list to
        // determine if it has an EC pair or a single EC and if the remaining
        // count indicates the given EC from that list is to stay functional.

        // Cycle through the first FC of each proc, then the second FC of each
        // proc and so on as we decrement remaining ECs. We put procs as the
        // inner loop and FCs as the outer to distribute the functional ECs
        // evenly between procs. After we run out of ECs, we deconfigure the
        // remaining ones.

        // Mark the ECs that have been accounted for
        uint8_t EC_checkedList[procs][NUM_FC_PER_CHIP];
        memset(EC_checkedList, 0, sizeof(EC_checkedList));

        for (uint32_t l_FC = 0; l_FC < NUM_FC_PER_CHIP; l_FC++)
        {
            for (int l_proc = 0; l_proc < procs; l_proc++)
            {
                // Save l_FC value to current FC, this is to be restored later
                uint32_t currrentFC = l_FC;

                // If core doesn't exist or already checked, find the
                // next available core on this proc in order to balance
                // the core distribution.
                uint8_t nextFCwithCore = 0;
                if ( (!pECList[l_proc][l_FC].size()) ||
                     (EC_checkedList[l_proc][l_FC]) )
                {
                    HWAS_INF("Current FC = %d, PROC %d: Need to find next "
                             "avail FC with cores.", l_FC, l_proc);
                    for (nextFCwithCore = l_FC+1;
                         nextFCwithCore < NUM_FC_PER_CHIP;
                         nextFCwithCore++)
                    {
                         if ( (pECList[l_proc][nextFCwithCore].size()) &&
                              (!(EC_checkedList[l_proc][nextFCwithCore]) ) )
                         {
                             l_FC = nextFCwithCore;
                             HWAS_INF("Next avail FC with cores = %d",
                                      nextFCwithCore);
                             break;
                         }
                    }
                    // No more core in this proc
                    if (nextFCwithCore == NUM_FC_PER_CHIP)
                    {
                        HWAS_INF("No more FC with cores in proc %d", l_proc);
                        l_FC = currrentFC;
                        continue;
                    }
                }

                // Mark this core has been checked.
                EC_checkedList[l_proc][l_FC] = 1;

                // Walk through the EC list from this FC
                while (pEC_it[l_proc][l_FC] != pECList[l_proc][l_FC].end())
                {
                    // Check if EC pair for this FC
                    if ((pECList[l_proc][l_FC].size() == 2) &&
                        (pairedECs_remaining != 0)  &&
                        // if we are doing field core override
                        // restriction we must ensure we are leaving
                        // enough allowed cores to give the primary processor
                        // at least 1 fused core
                        (i_deconfigReason != HWAS::DeconfigGard::DECONFIGURED_BY_FIELD_CORE_OVERRIDE ||
                         l_proc==l_primaryProc || // is primary or
                         l_allocatedToPrimary || // was allocated to primary
                         pairedECs_remaining > 2) // save 2 cores for primary
                       )
                    {
                        // got a functional EC that is part of a pair
                        goodECs++;
                        pairedECs_remaining--;
                        HWAS_DBG("pEC   0x%.8X - is good %d! (paired) pi:%d FCi:%d pairedECs_remaining %d",
                                 (*(pEC_it[l_proc][l_FC]))->getAttr<ATTR_HUID>(),
                                 goodECs, l_proc, l_FC, pairedECs_remaining);
                        if (l_proc == l_primaryProc)
                        {
                            HWAS_DBG("Allocated to primary");
                            l_allocatedToPrimary = true;
                        }
                    }
                    // Check if single EC for this FC
                    else if ((pECList[l_proc][l_FC].size() == 1) &&
                             (singleECs_remaining != 0) &&
                              // if we are doing field core override
                              // restriction we must ensure we are leaving
                              // enough allowed cores to give the primary processor
                              // at least 1 fused core
                              (i_deconfigReason != HWAS::DeconfigGard::DECONFIGURED_BY_FIELD_CORE_OVERRIDE ||
                              l_proc==l_primaryProc || // is primary or
                               l_allocatedToPrimary || // was allocated to primary
                               singleECs_remaining > 1)) // save core for primary

                    {
                        // got a functional EC without a pair
                        goodECs++;
                        singleECs_remaining--;
                        HWAS_DBG("pEC   0x%.8X - is good %d! (single) pi:%d FCi:%d singleECs_remaining %d",
                                 (*(pEC_it[l_proc][l_FC]))->getAttr<ATTR_HUID>(),
                                 goodECs, l_proc, l_FC, singleECs_remaining);
                        if (l_proc == l_primaryProc)
                        {
                            HWAS_DBG("Allocated to primary");
                            l_allocatedToPrimary = true;
                        }
                    }
                    // Otherwise paired or single EC, but not needed for maxECs
                    else
                    {
                        // got an EC to be restricted and marked not functional
                        TargetHandle_t l_pEC = *(pEC_it[l_proc][l_FC]);
                        bool l_markPresent =
                          (i_deconfigReason == HWAS::DeconfigGard::DECONFIGURED_BY_FIELD_CORE_OVERRIDE) ? true : false;
                        forceEcFcDeconfig(l_pEC, l_markPresent, i_deconfigReason);
                        HWAS_DBG("pEC   0x%.8X - deconfigured! (%s) pi:%d FCi:%d",
                            (*(pEC_it[l_proc][l_FC]))->getAttr<ATTR_HUID>(),
                            (pECList[l_proc][l_FC].size() == 1)? "single": "paired",
                            l_proc, l_FC);
                    }

                    (pEC_it[l_proc][l_FC])++; // next ec in this fc's list

                } // while pEC_it[l_proc][l_FC] != pECList[l_proc][l_FC].end()

                // Restore current FC
                l_FC = currrentFC;

            } // for l_proc < procs

        } // for l_FC < NUM_FC_PER_CHIP

    } // for procIdx < l_ProcCount

    } while(0); // do {

    if (errl)
    {
        HWAS_INF("restrictECunits failed (plid 0x%X)", errl->plid());
    }
    else
    {
        HWAS_INF("restrictECunits completed successfully");
    }
    return errl;
} // restrictECunits


/**
 * @brief checks if all critical resources are functional
 *  Verifies that the system has all of it's critical resources functional.
 *  If it does not, an error log will be created and committed indicating up
 *  to 3 critical targets that are not functional
 *
 * @param[in/out]  io_commonPlid  Reference to plid.
 * @param[in]      i_pTop         sys or node target to restrict hw check
 * @param[in]      i_pPredFunc    pointer to predicate to check for HWAS functional
 *                                and specdeconfig
 * @param[in/out]  io_bootable    whether the system is bootable after checking
 *                                for critical resources. If this param is
 *                                passed in this function, the error log for
 *                                missing critical parts won't be created
 *
 * @note If io_commonPlid is non-zero then any newly created Error Logs use io_commonPlid
 *       Else io_commonPlid is updated with the plid used in the newly created Error Logs
 */
void checkCriticalResources(uint32_t & io_commonPlid,
                            const Target * i_pTop,
                            const PredicateBase* const i_pPredFunc,
                            bool* io_bootable = nullptr)
{
    errlHndl_t l_errl = nullptr;
    PredicatePostfixExpr l_customPredicate;

    TargetHandleList l_plist;

    // filter for targets that are deemed critical by ATTR_RESOURCE_IS_CRITICAL
    uint8_t l_critical = 1;
    PredicateAttrVal<ATTR_RESOURCE_IS_CRITICAL> l_isCritical(l_critical);

    l_customPredicate.push(i_pPredFunc).Not().push(&l_isCritical).And();

    targetService().getAssociated( l_plist, i_pTop,
          TargetService::CHILD, TargetService::ALL, &l_customPredicate);

    do {
    //if this list has ANYTHING then something critical has been deconfigured
    if(l_plist.size())
    {
        HWAS_ERR("Insufficient HW to continue IPL: (critical resource not functional)");

        // the system is not bootable if a critical resource is missing
        if(io_bootable)
        {
            *io_bootable = false;
            // Due to the structure of minimum HW check calls, this function
            // can be called multiple times in the same path, generating error
            // logs every time it's called. We don't want to generate extra
            // error logs if we're just interested if the system is bootable
            // in current HW configuration.
            break;
        }

        /*@
         * @errortype
         * @severity          ERRL_SEV_UNRECOVERABLE
         * @moduleid          MOD_CHECK_MIN_HW
         * @reasoncode        RC_SYSAVAIL_MISSING_CRITICAL_RESOURCE
         * @devdesc           checkCriticalResources found a critical
         *                    resource to be deconfigured
         * @custdesc          A problem occurred during the IPL of the
         *                    system: A critical resource was found
         *                    to be deconfigured
         *
         * @userdata1[00:31]  Number of critical resources
         * @userdata1[32:63]  HUID of first critical resource found
         * @userdata2[00:31]  HUID of second critical resource found, if present
         * @userdata2[32:63]  HUID of third critical resource found, if present
         */

        uint64_t userdata1 = 0;
        uint64_t userdata2 = 0;
        switch(std::min(3,(int)l_plist.size()))
        {
            case 3:
                userdata2 = static_cast<uint64_t>(get_huid(l_plist[2]));

                /*fall through*/  // keep BEAM quiet
            case 2:
                userdata2 |=
                    static_cast<uint64_t>(get_huid(l_plist[1])) << 32;

                /*fall through*/  // keep BEAM quiet
            case 1:
                userdata1 =
                    (static_cast<uint64_t>(l_plist.size()) << 32) |
                     static_cast<uint64_t>(get_huid(l_plist[0]));
        }

        l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                           MOD_CHECK_MIN_HW,
                           RC_SYSAVAIL_MISSING_CRITICAL_RESOURCE,
                           userdata1,
                           userdata2 );

        // call out the procedure to find the deconfigured part.
        hwasErrorAddProcedureCallout(l_errl,
                                     EPUB_PRC_FIND_DECONFIGURED_PART,
                                     SRCI_PRIORITY_HIGH);

        // if we already have an error, link this one to the earlier;
        // if not, set the common plid
        hwasErrorUpdatePlid(l_errl, io_commonPlid);
        errlCommit(l_errl, HWAS_COMP_ID);
        // errl is now nullptr
    }
    }
    while(0);
}



errlHndl_t checkMinimumHardware(const TARGETING::ConstTargetHandle_t i_nodeOrSys,
                                bool *io_bootable)
{
    errlHndl_t l_errl = nullptr;
    HWAS_INF("checkMinimumHardware entry");
    uint32_t l_commonPlid = 0;

    do
    {
        //*********************************************************************/
        //  Common present and functional hardware checks.
        //*********************************************************************/

        if(io_bootable)
        {
            *io_bootable = true;
        }
        PredicateHwas l_present;
        l_present.present(true);
        PredicateHwas l_functional;
        if(io_bootable)
        {
            // Speculative deconfig sets the specdeconfig to true for the target
            // in question, so we want to filter out the targets that have been
            // speculatively deconfigured. Setting specdeconfig to false in this
            // predicate will ensure that those targets are left out of the list
            // of functional targets.
            l_functional.specdeconfig(false);
        }
        l_functional.functional(true);

        // top 'starting' point - use first node if no i_node given (hostboot)
        Target *pTop;
        if (i_nodeOrSys == nullptr)
        {
            Target *pSys;
            targetService().getTopLevelTarget(pSys);
            PredicateCTM l_predEnc(CLASS_ENC);
            PredicatePostfixExpr l_nodeFilter;
            l_nodeFilter.push(&l_predEnc).push(&l_functional).And();
            TargetHandleList l_nodes;
            targetService().getAssociated( l_nodes, pSys,
                TargetService::CHILD, TargetService::IMMEDIATE, &l_nodeFilter );

            if (l_nodes.empty())
            {
                HWAS_ERR("Insufficient HW to continue IPL: (no func nodes)");

                if(io_bootable)
                {
                    *io_bootable = false;
                    break;
                }

                /*@
                 * @errortype
                 * @severity          ERRL_SEV_UNRECOVERABLE
                 * @moduleid          MOD_CHECK_MIN_HW
                 * @reasoncode        RC_SYSAVAIL_NO_NODES_FUNC
                 * @devdesc           checkMinimumHardware found no functional
                 *                    nodes on the system
                 * @custdesc          A problem occurred during the IPL of the
                 *                    system: No functional nodes were found on
                 *                    the system.
                 */
                l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                                    MOD_CHECK_MIN_HW,
                                    RC_SYSAVAIL_NO_NODES_FUNC);

                // call out the procedure to find the deconfigured part.
                hwasErrorAddProcedureCallout(l_errl,
                                            EPUB_PRC_FIND_DECONFIGURED_PART,
                                            SRCI_PRIORITY_HIGH);

                //  if we already have an error, link this one to the earlier;
                //  if not, set the common plid
                hwasErrorUpdatePlid(l_errl, l_commonPlid);
                errlCommit(l_errl, HWAS_COMP_ID);
                // errl is now nullptr
                break;
            }

            // top level has at least 1 node - and it's our node.
            pTop = l_nodes[0];

            HWAS_INF("checkMinimumHardware: i_nodeOrSys = nullptr, using 0x%08X",
                    get_huid(pTop));
        }
        else
        {
            pTop = const_cast<Target *>(i_nodeOrSys);
            HWAS_INF("checkMinimumHardware: i_nodeOrSys 0x%08X",
                    get_huid(pTop));
        }

        // check for functional Master Proc on this node
        Target* l_pMasterProc = nullptr;

        //Get master proc at system level or node level based on target type
        if(pTop->getAttr<ATTR_TYPE>() == TYPE_SYS)
        {
            targetService().queryMasterProcChipTargetHandle(l_pMasterProc);
        }
        else
        {
            targetService().queryMasterProcChipTargetHandle(l_pMasterProc,
                                                          pTop);
        }

        if ((l_pMasterProc == nullptr) || (!l_functional(l_pMasterProc)))
        {
            HWAS_ERR("Insufficient HW to continue IPL: (no master proc)");

            if(io_bootable)
            {
                *io_bootable = false;
                break;
            }
            // determine some numbers to help figure out what's up..
            PredicateCTM l_proc(CLASS_CHIP, TYPE_PROC);
            TargetHandleList l_plist;

            PredicatePostfixExpr l_checkExprPresent;
            l_checkExprPresent.push(&l_proc).push(&l_present).And();
            targetService().getAssociated(l_plist, pTop,
                    TargetService::CHILD, TargetService::ALL,
                    &l_checkExprPresent);
            uint32_t procs_present = l_plist.size();

            PredicatePostfixExpr l_checkExprFunctional;
            l_checkExprFunctional.push(&l_proc).push(&l_functional).And();
            targetService().getAssociated(l_plist, pTop,
                    TargetService::CHILD, TargetService::ALL,
                    &l_checkExprFunctional);
            uint32_t procs_functional = l_plist.size();

            /*@
             * @errortype
             * @severity          ERRL_SEV_UNRECOVERABLE
             * @moduleid          MOD_CHECK_MIN_HW
             * @reasoncode        RC_SYSAVAIL_NO_PROCS_FUNC
             * @devdesc           checkMinimumHardware found no functional
             *                    master processor on this node
             * @custdesc          A problem occurred during the IPL of the
             *                    system: No functional master processor
             *                    was found on this node.
             * @userdata1[00:31]  HUID of node
             * @userdata2[00:31]  number of present procs
             * @userdata2[32:63]  number of present functional non-master procs
             */
            const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(pTop)) << 32);
            const uint64_t userdata2 =
                (static_cast<uint64_t>(procs_present) << 32) | procs_functional;
            l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                                MOD_CHECK_MIN_HW,
                                RC_SYSAVAIL_NO_PROCS_FUNC,
                                userdata1, userdata2);

            // call out the procedure to find the deconfigured part.
            hwasErrorAddProcedureCallout(l_errl,
                                        EPUB_PRC_FIND_DECONFIGURED_PART,
                                        SRCI_PRIORITY_HIGH);

            //  if we already have an error, link this one to the earlier;
            //  if not, set the common plid
            hwasErrorUpdatePlid(l_errl, l_commonPlid);
            errlCommit(l_errl, HWAS_COMP_ID);
            // errl is now nullptr
        }
        else
        {
        // don't do core check in HWSV. Common HWAS code in HWSV is not aware of util/misc.H for isSimicsRunning()
        // which is needed to let FSP simics pass the core checks with the simics default core enabelment.
        // When HB runs checkMinimumHardware(), then core checks will be preformed and Resourse Recovery will be
        // triggered as necessary, setting BLOCK_SPEC_DECONFIG for HWSV to skip applying gard records
#ifdef __HOSTBOOT_MODULE
            // if simics is running, set cache FCs to the minimum provided by default
            // simics setup. Otherwise, we are running on HW so use the ATTR val from xml
            const uint8_t min_num_backing_FCs = Util::isSimicsRunning() ? 1 :
                                                UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_HB_MIN_BACKING_CACHE_FC>();
            bool enough_cores_to_boot = true;

            // get all functional FCs and FCs deconfigured due to FCO
            PredicateHwas l_deconfig_by_fco;
            l_deconfig_by_fco.functionalOverride(true);
            TargetHandleList l_all_fused_cores;
            PredicatePostfixExpr l_testPred;
            PredicateCTM l_isFC(CLASS_UNIT, TYPE_FC);
            // (is FC && functional) || (is FC && deconfigured by FCO)
            l_testPred.push(&l_functional);
            l_testPred.push(&l_isFC).And();
            l_testPred.push(&l_deconfig_by_fco);
            l_testPred.push(&l_isFC).And().Or();
            targetService().getAssociated(l_all_fused_cores, l_pMasterProc,
                                          TargetService::CHILD, TargetService::ALL,
                                          &l_testPred);

            // predicate to filter the above FCs furthur based on their core children
            PredicatePostfixExpr l_checkExprFunctionalNonECOCores;
            PredicateCTM l_isCore(CLASS_UNIT, TYPE_CORE);
            PredicateAttrVal<ATTR_ECO_MODE> l_isNotEcoMode(ECO_MODE_DISABLED);
            // (is core && functional && !ECO-mode) || (is core && deconfig by FCO)
            l_checkExprFunctionalNonECOCores.push(&l_functional);
            l_checkExprFunctionalNonECOCores.push(&l_isCore).And();
            l_checkExprFunctionalNonECOCores.push(&l_isNotEcoMode).And();
            l_checkExprFunctionalNonECOCores.push(&l_deconfig_by_fco);
            l_checkExprFunctionalNonECOCores.push(&l_isCore).And().Or();

            bool unpairedFCFound = false;
            // remove FCs that do not have 2 functional non-ECO core children
            l_all_fused_cores.erase(
                std::remove_if(l_all_fused_cores.begin(), l_all_fused_cores.end(), [&l_checkExprFunctionalNonECOCores, &unpairedFCFound](TargetHandle_t i_fc_target){
                    TargetHandleList l_child_cores;

                    targetService().getAssociated(l_child_cores, i_fc_target,
                                                  TargetService::CHILD, TargetService::ALL,
                                                  &l_checkExprFunctionalNonECOCores);
                    if (!unpairedFCFound && l_child_cores.size() == 1)
                    {
                        // found an FC with only one core
                        // if the core is functional (ie not l_deconfig_by_fco),
                        // then we can use it as the executable core for systems not in FC mode
                        unpairedFCFound = l_child_cores[0]->getAttr<ATTR_HWAS_STATE>().functional;
                    }
                    return l_child_cores.size() < 2;
                }),
                l_all_fused_cores.end());

            HWAS_INF("checkMinimumHardware: %d functional and functionalOverride non-ECO FCs found", l_all_fused_cores.size());

            uint8_t FCO_and_Func_FC_size = l_all_fused_cores.size();
            uint8_t l_valid_cache_FCs = 0;
            if (is_fused_mode())
            {
                // at this point, if l_all_fused_cores is non empty, then there is at least 1 functional FC for execution
                // this is because FCO will never deconfigure cores/FCs below 0.
                // this leaves the rest of the FCs as valid backing cache candidates
                // otherwise if the list is empty, then it was due to gard record application
                l_valid_cache_FCs = FCO_and_Func_FC_size > 0 ? (FCO_and_Func_FC_size - 1) : 0;

                // check that we have enough backing cache FCs after counting one for execution
                enough_cores_to_boot = l_valid_cache_FCs >= min_num_backing_FCs;
            }
            else
            {
                // if a FC with one functional core was found, then it can be used as the executable core
                // otherwise, one of the FCs still in the list must be used for execution
                // if a FC with one functional core was NOT found, there is at least 1 functional FC for
                // execution left in the list if it is non-empty. This is because FCO will never deconfigure
                // cores/FCs below 0.
                // otherwise if the list is empty, then it was due to gard record application
                l_valid_cache_FCs = (unpairedFCFound || FCO_and_Func_FC_size == 0) ? FCO_and_Func_FC_size : (FCO_and_Func_FC_size - 1);

                // verify there are enough FCs to satify backing cache requirement,
                // and at least 1 more FC to execute on
                enough_cores_to_boot = ( (unpairedFCFound) || (FCO_and_Func_FC_size > 0)) &&
                                       (l_valid_cache_FCs >= min_num_backing_FCs);
            }

            HWAS_INF("checkMinimumHardware: enough_cores_to_boot = %s", enough_cores_to_boot ? "TRUE" : "FALSE");
            HWAS_INF("checkMinimumHardware: %d valid cache FCs >= %d needed : %s",
                     l_valid_cache_FCs,
                     min_num_backing_FCs,
                     l_valid_cache_FCs >= min_num_backing_FCs ? "TRUE" : "FALSE");

        #ifdef __HOSTBOOT_MODULE
            uint8_t cur_hb_cache = g_BlToHbDataManager.getHbCacheSizeMb();
            uint8_t min_hb_cache = min_num_backing_FCs * NUM_MB_CACHE_PER_FC;

            // if HB found enough cores to satisfy our backing cache requirements
            // but SBE did not report enough cache was available
            //    Don't run during MPIPL
            if(!(UTIL::assertGetToplevelTarget()->getAttr<ATTR_IS_MPIPL_HB>()) && enough_cores_to_boot && (cur_hb_cache < min_hb_cache))
            {
                // then there is a mismatch between SBE and HB, attempt SBE update to get back in sync
                HWAS_ERR("checkMinimumHardware: SBE reported only %dMB of backing cache, HB found enough FCs (%d) for %dMB of cache",
                         cur_hb_cache,
                         l_valid_cache_FCs,
                         l_valid_cache_FCs * NUM_MB_CACHE_PER_FC);

                HWAS_ERR("checkMinimumHardware: trigger SBE update to sync valid cores with SBE");
                l_errl = SBE::updateProcessorSbeSeeproms();

                if (l_errl)
                {
                    // got an error performing SBE update
                    HWAS_ERR("checkMinimumHardware: Error calling updateProcessorSbeSeeproms"
                              TRACE_ERR_FMT,
                              TRACE_ERR_ARGS(l_errl));
                    hwasErrorUpdatePlid(l_errl, l_commonPlid);
                    errlCommit(l_errl, HWAS_COMP_ID);
                }
                else
                {
                    // no error but no mismatch found, create an informational log
                    HWAS_ERR("checkMinimumHardware: updateProcessorSbeSeeproms returned without an error on processor 0x%08X",
                             get_huid(l_pMasterProc));

                    /*@
                     * @moduleid          MOD_CHECK_MIN_HW
                     * @reasoncode        RC_SYSAVAIL_SBE_NOT_ENOUGH_BACKING_CACHE
                     * @userdata1[00:31]         HUID of master proc
                     * @userdata1[32:63]         minimum required backing cache in MB
                     * @userdata2[00:31]         available cache provided from SBE in MB
                     * @userdata2[32:63]         available cache found by HB in MB
                     * @devdesc           Failed to update the SBE after SBE did not report
                     *                    enough available backing cache but HB found enough
                     *                    cores to satisfy the requirment
                     * @custdesc          A problem occurred during the IPL of the
                     *                    system: Not enough cache enabled
                     */
                    l_errl = hwasError(ERRL_SEV_INFORMATIONAL,
                                       MOD_CHECK_MIN_HW,
                                       RC_SYSAVAIL_SBE_NOT_ENOUGH_BACKING_CACHE,
                                       (static_cast<uint64_t>(get_huid(l_pMasterProc)) << 32) | min_hb_cache,
                                       (static_cast<uint64_t>(cur_hb_cache) << 32) | (l_valid_cache_FCs * NUM_MB_CACHE_PER_FC)
                                      );

                    // if we already have an error, link this one to the earlier;
                    // if not, set the common plid
                    hwasErrorUpdatePlid(l_errl, l_commonPlid);
                    l_errl->collectTrace(SBE_COMP_NAME);
                    l_errl->collectTrace(SBEIO_COMP_NAME);
                    errlCommit(l_errl, HWAS_COMP_ID);

                    // Explicitly force a devtree sync because we don't currently
                    // go through a shutdown when we send a reboot request
                    TARGETING::AttrRP::syncAllAttributesToSP();

                    // Initiate a graceful power cycle
                    HWAS_INF("checkMinimumHardware(): reconfig loop for backing cache adjustment");
                    INITSERVICE::requestReboot("backing cache adjustment");
                }

            }
        #endif // inner __HOSTBOOT_MODULE

            if (!enough_cores_to_boot)
            {
                HWAS_ERR("Insufficient HW to continue IPL: (not enough func cores to satisfy backing cache requirment)");

                if(io_bootable)
                {
                    *io_bootable = false;
                    break;
                }
                // determine some numbers to help figure out what's up..

                // get present cores
                TargetHandleList l_pres_cores;
                PredicatePostfixExpr l_checkExprPresent;
                l_checkExprPresent.push(&l_isCore).push(&l_present).And();
                targetService().getAssociated(l_pres_cores, l_pMasterProc,
                        TargetService::CHILD, TargetService::ALL,
                        &l_checkExprPresent);

                // functional core predicate
                // Ignore ECO cores as those don't support instruction execution.
                PredicatePostfixExpr l_checkExprFunctionalcore;
                PredicateCTM l_isCore(CLASS_UNIT, TYPE_CORE);
                PredicateAttrVal<ATTR_ECO_MODE> l_isNotEcoMode(ECO_MODE_DISABLED);
                l_checkExprFunctionalcore.push(&l_functional);
                l_checkExprFunctionalcore.push(&l_isCore).And();
                l_checkExprFunctionalcore.push(&l_isNotEcoMode).And();

                // functional ECO core predicate
                PredicatePostfixExpr l_checkExprECOcore;
                PredicateAttrVal<ATTR_ECO_MODE> l_isEcoMode(ECO_MODE_ENABLED);
                l_checkExprECOcore.push(&l_functional);
                l_checkExprECOcore.push(&l_isCore).And();
                l_checkExprECOcore.push(&l_isEcoMode).And();

                // Field Core Override predicate
                PredicatePostfixExpr l_checkExprFCOcore;
                l_checkExprFCOcore.push(&l_isCore);
                l_checkExprFCOcore.push(&l_deconfig_by_fco).And();

                uint32_t bitStringPresCores = UTIL::targetListToBitString(l_pres_cores);
                uint32_t bitStringFuncCores = UTIL::targetListToBitString(l_pres_cores, &l_checkExprFunctionalcore);
                uint32_t bitStringECOCores  = UTIL::targetListToBitString(l_pres_cores, &l_checkExprECOcore);
                uint32_t bitStringFCOCores  = UTIL::targetListToBitString(l_pres_cores, &l_checkExprFCOcore);
                HWAS_ERR("checkMinimumHardware: present cores:    0x%08X", bitStringPresCores);
                HWAS_ERR("checkMinimumHardware: functional cores: 0x%08X", bitStringFuncCores);
                HWAS_ERR("checkMinimumHardware: ECO cores:        0x%08X", bitStringECOCores);
                HWAS_ERR("checkMinimumHardware: FCO cores:        0x%08X", bitStringFCOCores);

                /*@
                 * @errortype
                 * @severity          ERRL_SEV_UNRECOVERABLE
                 * @moduleid          MOD_CHECK_MIN_HW
                 * @reasoncode        RC_SYSAVAIL_NO_CORES_FUNC
                 * @devdesc           checkMinimumHardware did not find enough cores
                 *                    for execution and backing cache on the master proc
                 * @custdesc          A problem occurred during the IPL of the
                 *                    system: No functional processor cores
                 *                    were found on the master processor.
                 * @userdata1[00:31]  bitstring of present cores
                 * @userdata1[32:63]  bitstring of present, functional non-ECO cores
                 * @userdata2[00:31]  bitstring of present, functional ECO cores
                 * @userdata2[32:63]  bitstring of present, FCO cores

                 */
                l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                                   MOD_CHECK_MIN_HW,
                                   RC_SYSAVAIL_NO_CORES_FUNC,
                                   (static_cast<uint64_t>(bitStringPresCores) << 32) | bitStringFuncCores,
                                   (static_cast<uint64_t>(bitStringECOCores) << 32)  | bitStringFCOCores
                                  );

                platHwasErrorAddHWCallout(l_errl,
                                          l_pMasterProc,
                                          SRCI_PRIORITY_LOW,
                                          NO_DECONFIG,
                                          GARD_NULL);

                // call out the procedure to find the deconfigured part.
                hwasErrorAddProcedureCallout(l_errl,
                                             EPUB_PRC_FIND_DECONFIGURED_PART,
                                             SRCI_PRIORITY_HIGH);

                // if we already have an error, link this one to the earlier;
                // if not, set the common plid
                hwasErrorUpdatePlid( l_errl, l_commonPlid );
                errlCommit(l_errl, HWAS_COMP_ID);
                // errl is now nullptr
            } // if not enough backing cache cores
#endif // outer __HOSTBOOT_MODULE

        }
        //  check here for functional dimms
        TargetHandleList l_dimms;
        PredicateCTM l_dimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
        PredicatePostfixExpr l_checkExprFunctional;
        l_checkExprFunctional.push(&l_dimm).push(&l_functional).And();
        targetService().getAssociated(l_dimms, pTop,
                TargetService::CHILD, TargetService::ALL,
                &l_checkExprFunctional);
        HWAS_DBG( "checkMinimumHardware: %d functional dimms",
                  l_dimms.size());

        if (l_dimms.empty())
        {
            HWAS_ERR( "Insufficient hardware to continue IPL (func DIMM)");

            if(io_bootable)
            {
                *io_bootable = false;
                break;
            }
            // determine some numbers to help figure out what's up..
            TargetHandleList l_plist;
            PredicatePostfixExpr l_checkExprPresent;
            l_checkExprPresent.push(&l_dimm).push(&l_present).And();
            targetService().getAssociated(l_plist, pTop,
                    TargetService::CHILD, TargetService::ALL,
                    &l_checkExprPresent);
            uint32_t dimms_present = l_plist.size();

            /*@
             * @errortype
             * @severity          ERRL_SEV_UNRECOVERABLE
             * @moduleid          MOD_CHECK_MIN_HW
             * @reasoncode        RC_SYSAVAIL_NO_MEMORY_FUNC
             * @devdesc           checkMinimumHardware found no
             *                    functional dimm cards.
             * @custdesc          A problem occurred during the IPL of the
             *                    system: Found no functional dimm cards.
             * @userdata1[00:31]  HUID of node
             * @userdata2[00:31]  number of present, non-functional dimms
             */
            const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(pTop)) << 32);
            const uint64_t userdata2 =
                (static_cast<uint64_t>(dimms_present) << 32);
            l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                                MOD_CHECK_MIN_HW,
                                RC_SYSAVAIL_NO_MEMORY_FUNC,
                                userdata1, userdata2);

            //  call out the procedure to find the deconfigured part.
            hwasErrorAddProcedureCallout( l_errl,
                                          EPUB_PRC_FIND_DECONFIGURED_PART,
                                          SRCI_PRIORITY_HIGH );

            //  if we already have an error, link this one to the earlier;
            //  if not, set the common plid
            hwasErrorUpdatePlid( l_errl, l_commonPlid );
            errlCommit(l_errl, HWAS_COMP_ID);
            // errl is now nullptr
        } // if no dimms

        // check for functional NX chiplets
        // Take specdeconfig into account here
        TargetHandleList l_functionalNXChiplets;
        PredicateCTM l_nxChiplet(CLASS_UNIT, TYPE_NX);
        PredicatePostfixExpr l_checkExprFunctionalNxChiplets;
        l_checkExprFunctionalNxChiplets.push(&l_nxChiplet)
                                       .push(&l_functional)
                                       .And();
        targetService().getAssociated(l_functionalNXChiplets, pTop,
                        TargetService::CHILD, TargetService::ALL,
                        &l_checkExprFunctionalNxChiplets);
        HWAS_DBG( "checkMinimumHardware: %d NX chiplets",
                  l_functionalNXChiplets.size());

        if (l_functionalNXChiplets.empty())
        {
            HWAS_ERR( "Insufficient hardware to continue IPL (NX chiplets)");

            if(io_bootable)
            {
                *io_bootable = false;
                break;
            }
            TargetHandleList l_presentNXChiplets;
            getChildChiplets(l_presentNXChiplets, pTop, TYPE_NX, false);
            uint32_t nx_present = l_presentNXChiplets.size();

            /*@
             * @errortype
             * @severity           ERRL_SEV_UNRECOVERABLE
             * @moduleid           MOD_CHECK_MIN_HW
             * @reasoncode         RC_SYSAVAIL_NO_NX_FUNC
             * @devdesc            checkMinimumHardware found no
             *                     functional NX chiplets
             * @custdesc           Insufficient hardware to continue IPL
             * @userdata1[00:31]   HUID of node
             * @userdata2[00:31]   number of present nonfunctional NX chiplets
             */
            const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(pTop)) << 32);
            const uint64_t userdata2 =
                (static_cast<uint64_t>(nx_present) << 32);
            l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                         MOD_CHECK_MIN_HW,
                         RC_SYSAVAIL_NO_NX_FUNC,
                         userdata1, userdata2);

            //  call out the procedure to find the deconfigured part.
            hwasErrorAddProcedureCallout( l_errl,
                         EPUB_PRC_FIND_DECONFIGURED_PART,
                         SRCI_PRIORITY_HIGH );

            //  if we already have an error, link this one to the earlier;
            //  if not, set the common plid
            hwasErrorUpdatePlid( l_errl, l_commonPlid );
            errlCommit(l_errl, HWAS_COMP_ID);
        }

        //  ------------------------------------------------------------
        //  Check for Mirrored memory -
        //  If the user requests mirrored memory and we do not have it,
        //  post an errorlog but do not return a terminating error.
        //  ------------------------------------------------------------
        //  Need to read an attribute set by PHYP?


        //  check for minimum hardware that is specific to platform that we're
        //  running on (ie, hostboot or fsp in hwsv).
        //  if there is an issue, create and commit an error, and tie it to the
        //  the rest of them with the common plid.
        HWAS::checkCriticalResources(l_commonPlid, pTop, &l_functional, io_bootable);
        platCheckMinimumHardware(l_commonPlid, pTop, io_bootable);
    }
    while (0);

    //  ---------------------------------------------------------------
    // if the common plid got set anywhere above, we have an error.
    //  ---------------------------------------------------------------
    if ((l_commonPlid)&&(io_bootable == nullptr))
    {
        /*@
         * @errortype
         * @severity          ERRL_SEV_UNRECOVERABLE
         * @moduleid          MOD_CHECK_MIN_HW
         * @reasoncode        RC_SYSAVAIL_INSUFFICIENT_HW
         * @devdesc           Insufficient hardware to continue.
         * @custdesc          An issue occurred during IPL of the system:
         *                    Internal Firmware Error
         */
        l_errl  =   hwasError(  ERRL_SEV_UNRECOVERABLE,
                                MOD_CHECK_MIN_HW,
                                RC_SYSAVAIL_INSUFFICIENT_HW);
        //  call out the procedure to find the deconfigured part.
        hwasErrorAddProcedureCallout( l_errl,
                                      EPUB_PRC_FIND_DECONFIGURED_PART,
                                      SRCI_PRIORITY_HIGH );
        //  if we already have an error, link this one to the earlier;
        //  if not, set the common plid
        hwasErrorUpdatePlid( l_errl, l_commonPlid );
    }

    HWAS_INF("checkMinimumHardware exit - minimum hardware %s",
            ((l_errl != nullptr)||((io_bootable!=nullptr)&&(!*io_bootable))) ?
                    "NOT available" : "available");
    if((l_errl != nullptr)||((io_bootable!=nullptr)&&(!*io_bootable)))
    {
        // Get all node targets
        TargetHandleList l_nodelist;
        getEncResources(l_nodelist, TARGETING::TYPE_NODE,
                        TARGETING::UTIL_FILTER_FUNCTIONAL);
        for( auto l_node : l_nodelist )
        {
            // Minimum hardware not available, block speculative deconfigs
            l_node->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(1);
        }
    }

    return  l_errl ;
} // checkMinimumHardware



/**
 * @brief Checks if both targets have the same paths up to a certain number
 *        of path elements, determined by the smaller affinity path. For Axone,
 *        if an OMIC and OMI target are given as the parameters then it will use
 *        the OMI's special OMIC_PARENT relation and compare that to the OMIC
 *        target. Otherwise, affinity path comparison between OMI and OMIC
 *        targets will always fail erroneously.
 *
 * @param[in] i_t1 TargetInfo containing the first target's affinity path
 * @param[in] i_t2 TargetInfo containing the second target's affinity path
 */
bool isSameSubPath(TargetInfo i_t1, TargetInfo i_t2)
{

    PredicateCTM isOmic(CLASS_NA, TYPE_OMIC), isOmi(CLASS_NA, TYPE_OMI);

    EntityPath l_t1Path = i_t1.affinityPath,
               l_t2Path = i_t2.affinityPath;

    // Due to the special OMIC_PARENT relation between OMI and OMIC targets
    // this function will only work correctly if we use the OMIC_PARENT path
    // instead of the OMI affinity path when comparing OMI and OMIC targets.
    if (((i_t1.pThisTarget != nullptr) && (i_t2.pThisTarget != nullptr))
       && ((isOmi(i_t1.pThisTarget) && isOmic(i_t2.pThisTarget)) ||
           (isOmi(i_t2.pThisTarget) && isOmic(i_t1.pThisTarget))))
    {
        TargetHandleList l_pOmicParent;
        if (i_t1.type == TYPE_OMI)
        {
            targetService().getAssociated(l_pOmicParent, i_t1.pThisTarget,
                                          TargetService::OMIC_PARENT,
                                          TargetService::ALL);

            l_t1Path = l_pOmicParent[0]->getAttr<ATTR_AFFINITY_PATH>();
        }
        else
        {
            targetService().getAssociated(l_pOmicParent, i_t2.pThisTarget,
                                          TargetService::OMIC_PARENT,
                                          TargetService::ALL);

            l_t2Path = l_pOmicParent[0]->getAttr<ATTR_AFFINITY_PATH>();
        }
    }

    size_t l_size = std::min(l_t1Path.size(),
                             l_t2Path.size());

    return l_t1Path.equals(l_t2Path, l_size);
}

void deconfigPresentByAssoc(TargetInfo i_targInfo)
{
    TargetHandleList pChildList;

    // find all CHILD matches for this target and deconfigure them
    getChildChiplets(pChildList, i_targInfo.pThisTarget, TYPE_NA);

    for (TargetHandleList::const_iterator
            pChild_it = pChildList.begin();
            pChild_it != pChildList.end();
            ++pChild_it)
    {
        TargetHandle_t l_childTarget = *pChild_it;
        enableHwasState(l_childTarget, true, false, i_targInfo.reason);
        HWAS_INF("deconfigPresentByAssoc: Parent Target %.8X: Child Target %.8X"
                 " marked present, not functional: reason %.x",
                 get_huid(i_targInfo.pThisTarget),
                 get_huid(l_childTarget), i_targInfo.reason);
    }

    // find all CHILD_BY_AFFINITY matches for this target and deconfigure them
    getChildAffinityTargets(pChildList, i_targInfo.pThisTarget,
                            CLASS_NA ,TYPE_NA);

    for (TargetHandleList::const_iterator
            pChild_it = pChildList.begin();
            pChild_it != pChildList.end();
            ++pChild_it)
    {
        TargetHandle_t l_affinityTarget = *pChild_it;
        enableHwasState(l_affinityTarget, true, false, i_targInfo.reason);
        HWAS_INF("deconfigPresentByAssoc: Parent Target %.8X: Child Target by Affinity %.8X"
                 " marked present, not functional: reason %.x",
                 get_huid(i_targInfo.pThisTarget),
                 get_huid(l_affinityTarget), i_targInfo.reason);
    }

    // deconfigure the target itself
    enableHwasState(i_targInfo.pThisTarget, true, false, i_targInfo.reason);
    HWAS_INF("deconfigPresentByAssoc: Target itself %.8X"
             " marked present, not functional, reason %.x",
             get_huid(i_targInfo.pThisTarget), i_targInfo.reason);

    // find all Parent Pervasive matches for this target and deconfigure them,
    // iff all the targets associated with the Parent Pervasive are not functional
    getParentPervasiveTargetsByState(pChildList, i_targInfo.pThisTarget, CLASS_UNIT,
                                    TYPE_PERV, UTIL_FILTER_FUNCTIONAL);
    for (auto l_parentPervasive: pChildList)
    {
        // Retrieve all the functional targets associated with this Parent Pervasive target
        TargetHandleList l_associatesOfPervTargetsList;
        getPervasiveChildTargetsByState(l_associatesOfPervTargetsList, l_parentPervasive,
                                        CLASS_NA, TYPE_NA, UTIL_FILTER_FUNCTIONAL);

        // If there are no functional targets associated with this Parent Pervasive target,
        // then it is OK to deconfigure it
        if (!l_associatesOfPervTargetsList.size())
        {
            HWAS_INF("deconfigPresentByAssoc: Target itself %.8X: "
                     "Associated Parent Pervasive Target %0.8X"
                     " marked present, not functional, reason %.x",
                     get_huid(i_targInfo.pThisTarget), get_huid(l_parentPervasive), i_targInfo.reason);
            enableHwasState(l_parentPervasive, true, false, i_targInfo.reason);
        }
    } // for (auto l_parentPervasive: pChildList)
} // deconfigPresentByAssoc

void invokePresentByAssoc()
{
    HWAS_DBG("invokePresentByAssoc enter");

    // make one list
    TargetHandleList l_funcTargetList;

    // get the functional MCs
    TargetHandleList l_funcMCTargetList;
    getAllChiplets(l_funcMCTargetList, TYPE_MC, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                            l_funcMCTargetList.begin(),
                            l_funcMCTargetList.end());

// If VPO, dump targets (MC) for verification & debug purposes
#ifdef CONFIG_VPO_COMPILE
    HWAS_INF("invokePresentByAssoc(): MC targets:");
    for (auto l_MC : l_funcMCTargetList)
    {
        HWAS_INF("   MC: HUID %.8x", TARGETING::get_huid(l_MC));
    }
#endif

    // get the functional MIs
    TargetHandleList l_funcMITargetList;
    getAllChiplets(l_funcMITargetList, TYPE_MI, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                            l_funcMITargetList.begin(),
                            l_funcMITargetList.end());

// If VPO, dump targets (MI) for verification & debug purposes
#ifdef CONFIG_VPO_COMPILE
    HWAS_INF("invokePresentByAssoc(): MI targets:");
    for (auto l_MI : l_funcMITargetList)
    {
        HWAS_INF("   MI: HUID %.8x", TARGETING::get_huid(l_MI));
    }
#endif

    PredicateCTM mccPred(CLASS_NA, TYPE_MCC),
                 omiPred(CLASS_NA, TYPE_OMI),
                 omicPred(CLASS_NA, TYPE_OMIC),
                 ocmbPred(CLASS_CHIP, TYPE_OCMB_CHIP),
                 pmicPred(CLASS_NA, TYPE_PMIC),
                 memportPred(CLASS_NA, TYPE_MEM_PORT);
    PredicateHwas functionalPred;
    functionalPred.functional(true);

    Target *pSys;
    targetService().getTopLevelTarget(pSys);

    PredicatePostfixExpr l_funcAxoneMemoryUnits;
    l_funcAxoneMemoryUnits.push(&mccPred).push(&omiPred).Or()
        .push(&omicPred).Or().push(&ocmbPred).Or().push(&memportPred)
        .Or().push(&functionalPred).And();

    TargetHandleList l_funcAxoneTargetList;
    targetService().getAssociated(l_funcAxoneTargetList, pSys,
            TargetService::CHILD, TargetService::ALL, &l_funcAxoneMemoryUnits);
    l_funcTargetList.insert(l_funcTargetList.begin(),
                            l_funcAxoneTargetList.begin(),
                            l_funcAxoneTargetList.end());


    // get the functional dimms
    TargetHandleList l_funcDIMMTargetList;
    getAllLogicalCards(l_funcDIMMTargetList, TYPE_DIMM, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                               l_funcDIMMTargetList.begin(),
                               l_funcDIMMTargetList.end());


// If VPO, dump targets (DIMM) for verification & debug purposes
#ifdef CONFIG_VPO_COMPILE
    HWAS_INF("invokePresentByAssoc(): DIMM targets:");
    for (auto l_DIMM : l_funcDIMMTargetList)
    {
        HWAS_INF("   DIMM: HUID %.8x", TARGETING::get_huid(l_DIMM));
    }
#endif

    // Call presentByAssoc to take the functional targets in l_targInfo
    // and determine which ones need to be deconfigured
    presentByAssoc(l_funcTargetList);
} // invokePresentByAssoc

/* @brief Constructor function for TargetInfo
 *
 * @param[in] i_targ             The target to create the TargetInfo from
 * @param[in] i_deconfigReason   Deconfiguration reason for TargetInfo
 *
 * @return TargetInfo TargetInfo describing the input parameters
 */
static TargetInfo makeTargetInfo(
    Target* const i_targ,
    const DeconfigGard::DeconfiguredByReason i_deconfigReason
)
{
    TargetInfo l_targetInfo;
    l_targetInfo.pThisTarget    = i_targ;
    l_targetInfo.affinityPath   = i_targ->getAttr<ATTR_AFFINITY_PATH>();
    l_targetInfo.type           = i_targ->getAttr<ATTR_TYPE>();
    l_targetInfo.reason         = i_deconfigReason;

    return l_targetInfo;
}

void presentByAssoc(TargetHandleList& i_targets)
{
    /* This function ensures that each child has at least one functional parent
     * of each type (i.e. OMI have a parent OMIC and a parent MCC), and that
     * each parent has at least one functional child of each type (i.e. an MC
     * must have at least one functional OMIC and MI). */

    /* @brief Enumeration for values of presentRule::checkParent
     */
    enum parentCheck_t
    {
        NO_CHECK_PARENT, // Do NOT check whether the parent has children of the
                         // given type
        CHECK_PARENT     // DO check whether the parent has children of the
                         // given type
    };

    // This structure contains a single rule for a parent/child
    // relationship. The rule is symmetrical (i.e. the child type must have (at
    // least) one parent of the parent type, and vice versa) unless checkParent
    // is NO_CHECK_PARENT, in which case it only applies to the child type (as
    // in the case of TYPE_PMIC).
    struct presentRule
    {
        // This type represents a function that retrieves either a list of
        // parents or children. It's stored in the rule because not all
        // parent/child relationships are by affinity path (i.e. OMI/OMIC
        // relationship has its own function).
        using getRelatives_t = void(*)(TARGETING::TargetHandleList& o_vector,
                                       const Target * i_target,
                                       CLASS i_class,
                                       TYPE i_type,
                                       ResourceState);

        // The types of targets this rule applies to
        TARGETING::TYPE parentType, childType;

        // The reason to provide to the TargetInfo structure when a target is
        // deconfigured by this rule
        DeconfigGard::DeconfiguredByReason parentDeconfigReason,
                                           childDeconfigReason;

        // If this is CHECK_PARENT, then the parent must have at least one
        // functional child of the given type and vice versa (i.e. the rule is
        // symmetrical). If NO_CHECK_PARENT, the former condition is not checked
        // (but the latter still is).
        parentCheck_t checkParent = CHECK_PARENT;

        // Functions to retrieve a list of parents and children from instances
        // of the given target types.
        getRelatives_t getParent = getParentAffinityTargetsByState,
                       getChildren = getChildAffinityTargetsByState;

        // @TODO RTC 249996 This constructor is not necessary for later C++
        //                  versions. Investigate possible removal.
        presentRule(
              TARGETING::TYPE parent,
              TARGETING::TYPE child,
              DeconfigGard::DeconfiguredByReason parentReason,
              DeconfigGard::DeconfiguredByReason childReason,
              parentCheck_t check = CHECK_PARENT,
              getRelatives_t relativeParent = getParentAffinityTargetsByState,
              getRelatives_t relativeChildren = getChildAffinityTargetsByState)
                : parentType(parent), childType(child),
                  parentDeconfigReason(parentReason),
                  childDeconfigReason(childReason),
                  checkParent(check),
                  getParent(relativeParent),
                  getChildren(relativeChildren)
                {}
    }
    static const l_rules[] =
    {
        { TYPE_MC, TYPE_MI,
          DeconfigGard::DECONFIGURED_BY_NO_CHILD_MI,
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_MC },

        { TYPE_MC, TYPE_OMIC,
          DeconfigGard::DECONFIGURED_BY_NO_CHILD_OMIC,
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_MC },

        { TYPE_MI, TYPE_MCC,
          DeconfigGard::DECONFIGURED_BY_NO_CHILD_MCC,
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_MI },

        // Symmetrical rule with special accessors for parent and children.
        { TYPE_OMIC, TYPE_OMI,
          DeconfigGard::DECONFIGURED_BY_NO_CHILD_OMI,
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_OMIC,
          CHECK_PARENT, // symmetrical rule
          getParentOmicTargetsByState, getChildOmiTargetsByState },

        // Asymmetrical rule with special accessors for parent and children.
        // Every OMIC has to have a PAUC parent, but a PAUC parent does not
        // have to have any OMIC children
        { TYPE_PAUC, TYPE_OMIC,
          DeconfigGard::INVALID_DECONFIGURED_BY_REASON, // Asymmetrical rule
                                                        // Can't deconfig parent
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_PAUC,
          NO_CHECK_PARENT, // Asymmetrical rule
          getParentPaucTargetsByState, getChildPaucTargetsByState },

        { TYPE_MCC, TYPE_OMI,
          DeconfigGard::DECONFIGURED_BY_NO_CHILD_OMI,
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_MCC },

        { TYPE_OMI, TYPE_OCMB_CHIP,
          DeconfigGard::DECONFIGURED_BY_NO_CHILD_OCMB_CHIP,
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_OMI },

        { TYPE_OCMB_CHIP, TYPE_MEM_PORT,
          DeconfigGard::DECONFIGURED_BY_NO_CHILD_MEM_PORT,
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_OCMB_CHIP },

        // TODO RTC 261354: remove compile flag and use the symetric rule for PMICs once
        // HWSV implements the logic to set PMICs as present
#ifdef __HOSTBOOT_MODULE
        { TYPE_OCMB_CHIP, TYPE_PMIC,
          DeconfigGard::DECONFIGURED_BY_NO_CHILD_PMIC,
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_OCMB_CHIP },
#else
        // Asymmetrical rule; every PMIC has to have an OCMB_CHIP parent,
        // but not every OCMB_CHIP has a PMIC child
        { TYPE_OCMB_CHIP, TYPE_PMIC,
          DeconfigGard::INVALID_DECONFIGURED_BY_REASON, // Asymmetrical rules can't
                                                        // deconfigure the parent
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_OCMB_CHIP,
          NO_CHECK_PARENT }, // asymmetrical
#endif


        // Asymmetrical rule; every GENERIC_I2C_DEVICE has to have an OCMB_CHIP parent,
        // but not every OCMB_CHIP has a GENERIC_I2C_DEVICE child, ie on 2U DDIMMs
        { TYPE_OCMB_CHIP, TYPE_GENERIC_I2C_DEVICE,
          DeconfigGard::INVALID_DECONFIGURED_BY_REASON, // Asymmetrical rules can't
                                                        // deconfigure the parent
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_OCMB_CHIP,
          NO_CHECK_PARENT }, // asymmetrical

        { TYPE_MEM_PORT, TYPE_DIMM,
          DeconfigGard::DECONFIGURED_BY_NO_CHILD_DIMM,
          DeconfigGard::DECONFIGURED_BY_NO_PARENT_MEM_PORT },
    };

    // Keeps a record of targets we have already examined
    std::map<Target*, bool> deconfigured;

    // i_targets is used as a work list. When we deconfigure a target, we push
    // its parents and children (if they exist) into the list to be re-examined,
    // so that deconfiguration propagates up and down the target hierarchy. The
    // algorithm halts when there are no more targets to be checked in the list.
    while (!i_targets.empty())
    {
        const auto l_funcTarget = i_targets.back();
        i_targets.pop_back();

        // Don't process the same target twice. This condition is possible when,
        // for example, two children of the same target are deconfigured; their
        // parent will be added to the list twice as part of the propagation
        // effect.
        if (deconfigured[l_funcTarget])
        {
            continue;
        }

        const TYPE l_targetType = l_funcTarget->getAttr<ATTR_TYPE>();

        // We keep a list of all of children of any type for this target, so
        // that if at any point this target gets deconfigured, all of its
        // parents and children are rechecked for propagation (as opposed to
        // only children/parents of a the single type from the rule that caused
        // it to be deconfigured).
        TargetHandleList l_allChildrenList;
        TargetHandleList l_allParentsList;

        // Check each rule in the ruleset
        for (const auto l_rule : l_rules)
        {
            TargetHandleList l_childList;
            TargetHandleList l_parentList;
            TargetHandleList* l_relativeList = nullptr;
            DeconfigGard::DeconfiguredByReason l_deconfigReason;

            if ((l_rule.parentType == l_targetType)
                && (l_rule.checkParent == CHECK_PARENT))
            {
                l_relativeList = &l_childList;
                l_deconfigReason = l_rule.parentDeconfigReason;
            }
            else if (l_rule.childType == l_targetType)
            {
                l_relativeList = &l_parentList;
                l_deconfigReason = l_rule.childDeconfigReason;
            }
            else // skip to the next rule
            {
                continue;
            }

            l_rule.getChildren(l_childList, l_funcTarget, CLASS_NA,
                               l_rule.childType, UTIL_FILTER_FUNCTIONAL);

            l_rule.getParent(l_parentList, l_funcTarget, CLASS_NA,
                             l_rule.parentType, UTIL_FILTER_FUNCTIONAL);

            l_allChildrenList.insert(l_allChildrenList.end(),
                                     l_childList.cbegin(), l_childList.cend());

            l_allParentsList.insert(l_allParentsList.end(),
                                    l_parentList.cbegin(), l_parentList.cend());

            if (l_relativeList)
            {
                // If the rule applied to this target and the appropriate list
                // of relatives is empty, then deconfigure this target
                if (l_relativeList->empty())
                {
                    HWAS_DBG("PresentByAssoc, deconfig %.8X by rule 0x%x-%x",
                             l_funcTarget->getAttr<ATTR_HUID>(),
                             l_rule.parentType, l_rule.childType);

                    deconfigPresentByAssoc(makeTargetInfo(l_funcTarget,
                                                          l_deconfigReason));
                    deconfigured[l_funcTarget] = true;
                }
            }
        }

        // If we deconfigured this target, then add its parents and children to
        // the worklist so that the deconfiguration can propagate if needed
        if (deconfigured[l_funcTarget])
        {
            i_targets.insert(i_targets.end(),
                             l_allParentsList.cbegin(),
                             l_allParentsList.cend());

            i_targets.insert(i_targets.end(),
                             l_allChildrenList.cbegin(),
                             l_allChildrenList.cend());
        }
    }
}

void setChipletGardsOnProc(TARGETING::Target * i_procTarget)
{
    //@TODO-RTC:257499-Remove after HWSV removes references to it
    HWAS_ERR("HWAS::setChipletGardsOnProc is deprecated");
}//setChipletGardsOnProc

bool mixedECsAllowed(TARGETING::ATTR_MODEL_type i_model,
                     TARGETING::ATTR_EC_type i_baseEC,
                     TARGETING::ATTR_EC_type i_compareEC)
{
    bool l_mixOk = false;

    return l_mixOk;
}

errlHndl_t validateProcessorEcLevels()
{
    HWAS_INF("validateProcessorEcLevels entry");
    errlHndl_t l_err = nullptr;
    uint32_t l_commonPlid = 0;
    TARGETING::ATTR_EC_type l_masterEc     = 0;
    TARGETING::ATTR_EC_type l_ecToCompare  = 0;
    TARGETING::ATTR_HUID_type l_masterHuid = 0;
    TARGETING::TargetHandleList l_procChips;
    Target* l_pMasterProc = nullptr;
    TARGETING::ATTR_MODEL_type l_model;

    do
    {
        //Get all functional chips
        getAllChips(l_procChips, TYPE_PROC);

        // check for functional Master Proc on this node
        l_err = targetService().queryMasterProcChipTargetHandle(l_pMasterProc,
                                                                nullptr, true);

        //queryMasterProcChipTargetHandle will check for null, make sure
        //there was no problem finding the master proc
        if(l_err)
        {
            HWAS_ERR( "validateProcessorEcLevels:: Unable to find master proc");
            //Don't commit the error just let it get returned from function
            break;
        }

        //Get master info and store it for comparing later
        l_masterEc = l_pMasterProc->getAttr<TARGETING::ATTR_EC>();
        l_masterHuid = get_huid(l_pMasterProc);
        l_model = l_pMasterProc->getAttr<TARGETING::ATTR_MODEL>();

        //Loop through all functional procs and create error logs
        //for any processors whose EC does not match the master
        for(const auto & l_chip : l_procChips)
        {
            l_ecToCompare = l_chip->getAttr<TARGETING::ATTR_EC>();
            bool l_mixOk = mixedECsAllowed(l_model,l_masterEc, l_ecToCompare);
            if((l_ecToCompare != l_masterEc) && !l_mixOk)
            {
                HWAS_ERR("validateProcessorEcLevels:: Slave Proc EC level not does not match master, "
                        "this is an unrecoverable error.. system will shut down");

                /*@
                * @errortype
                * @severity           ERRL_SEV_UNRECOVERABLE
                * @moduleid           MOD_VALIDATE_EC_LEVELS
                * @reasoncode         RC_EC_MISMATCH
                * @devdesc            Found a slave processor whose EC level
                *                     did not match the master
                * @custdesc           Incompatible Processor Chip Levels
                * @userdata1[00:31]   HUID of slave chip
                * @userdata1[32:63]   EC level of slave chip
                * @userdata2[00:31]   HUID of master chip
                * @userdata2[32:63]   EC level of master chip
                */
                const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(l_chip)) << 32) | static_cast<uint64_t>(l_ecToCompare);
                const uint64_t userdata2 =
                (static_cast<uint64_t>(l_masterHuid) << 32) | static_cast<uint64_t>(l_masterEc);

                l_err = hwasError(ERRL_SEV_UNRECOVERABLE,
                                  MOD_VALIDATE_EC_LEVELS,
                                  RC_EC_MISMATCH,
                                  userdata1,
                                  userdata2);

                //  call out the procedure to find the deconfigured part.
                platHwasErrorAddHWCallout( l_err,
                                       l_chip,
                                       SRCI_PRIORITY_HIGH,
                                       NO_DECONFIG,
                                       GARD_NULL);
                //  if we already have an error, link this one to the earlier;
                //  if not, set the common plid
                hwasErrorUpdatePlid(l_err, l_commonPlid);
                errlCommit(l_err, HWAS_COMP_ID);
                //Do not break, we want to find all mismatches
            }
        }
    }while(0);

    if(l_commonPlid)
    {
        HWAS_ERR("validateProcessorEcLevels:: One or more slave processor's EC level did not match master, check error logs");

        /*@
        * @errortype
        * @severity           ERRL_SEV_UNRECOVERABLE
        * @moduleid           MOD_VALIDATE_EC_LEVELS
        * @reasoncode         RC_FAILED_EC_VALIDATION
        * @devdesc            Found one or more slave processor whose EC level
        *                     did not match the master
        * @custdesc           Incompatible Processor Chip Levels
        * @userdata1[00:64]   Number of Procs
        */
        const uint64_t userdata1 =
        static_cast<uint64_t>(l_procChips.size());
        const uint64_t userdata2 =
        (static_cast<uint64_t>(l_masterHuid) << 32) | static_cast<uint64_t>(l_masterEc);

        l_err = hwasError(ERRL_SEV_UNRECOVERABLE,
                            MOD_VALIDATE_EC_LEVELS,
                            RC_FAILED_EC_VALIDATION,
                            userdata1,
                            userdata2);

        //  link this error to the earlier errors;
        hwasErrorUpdatePlid(l_err, l_commonPlid);
    }

    HWAS_INF("validateProcessorEcLevels exit");
    return l_err;

} //validateProccesorEcLevels
#endif // end #ifndef __HOSTBOOT_RUNTIME

};   // end namespace
