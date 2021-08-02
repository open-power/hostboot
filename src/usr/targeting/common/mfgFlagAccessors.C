/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/mfgFlagAccessors.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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

// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L

//******************************************************************************
// Includes
//******************************************************************************
#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/common/targetservice.H> // TARGETING::UTIL::assertGetToplevelTarget

namespace TARGETING
{

//##############################################################################
//## Methods that directly call the manufacturing (MFG) Flag Canned Responses
//## are better suited here in this file, at least from a compile perspective.
//##############################################################################

// is_phyp_load
bool is_phyp_load( ATTR_PAYLOAD_KIND_type* o_type )
{
    // Get a handle to the System target
    TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();

    // get the current payload kind
    TARGETING::PAYLOAD_KIND payload_kind =
                     l_systemTarget->getAttr<ATTR_PAYLOAD_KIND>();

    if( o_type )
    {
        *o_type = payload_kind;
    }

    //If in AVP mode default to false
    bool is_phyp = false;
    if(!is_avp_load())
    {
        is_phyp = (PAYLOAD_KIND_PHYP == payload_kind);
    }
    return is_phyp;
 }

// is_sapphire_load
bool is_sapphire_load(void)
{
    // Get a handle to the System target
    TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();

    bool is_sapphire = false;

    //If in AVP mode default to false
    if(!is_avp_load())
    {
        is_sapphire = (PAYLOAD_KIND_SAPPHIRE ==
                     l_systemTarget->getAttr<TARGETING::ATTR_PAYLOAD_KIND>());
    }
    return is_sapphire;
}


//##############################################################################
//##             Manufacturing (MFG) Flag Canned Responses
//##############################################################################

bool is_avp_load()
{
    // Get the list of manufacturing flags to check against
    TARGETING::ATTR_MFG_FLAGS_typeStdArr i_mfgFlags;
    TARGETING::getAllMfgFlags(i_mfgFlags);

    return (isMfgAvpEnabled(i_mfgFlags) || isMfgHdatAvpEnabled(i_mfgFlags));
};

bool isMfgSpareDramDeploy()
{
    // RBS (redundant bit steering) is synonymous and equivalent with DRAM
    // repairs as seen in document /fips1020/src/mnfg/mfg/mnfgPolicyFlags.H
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_TEST_RBS);
};

bool areAllSrcsTerminating()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_SRC_TERM);
};

bool isDramRepairsDisabled()
{
    // RBS (redundant bit steering) is synonymous and equivalent with DRAM
    // repairs as seen in document /fips1020/src/mnfg/mfg/mnfgPolicyFlags.H
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_NO_RBS);
};

bool areMfgThresholdsActive()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_THRESHOLDS);
};

bool isMfgAvpEnabled()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_AVP_ENABLE);
};

bool isMfgHdatAvpEnabled()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_HDAT_AVP_ENABLE);
};

bool isEnableFastBackgroundScrub()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_FAST_BACKGROUND_SCRUB);
};

bool isMemoryRepairDisabled()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_DISABLE_MEMORY_eREPAIR);
};

bool isFabricRepairDisabled()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_DISABLE_FABRIC_eREPAIR);
};

bool isMfgCeCheckingEnabled()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_IPL_MEMORY_CE_CHECKING);
};

bool isMinimumPatternTestEnabled()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_ENABLE_MINIMUM_PATTERN_TEST);
};

bool isStandardPatternTestEnabled()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_ENABLE_STANDARD_PATTERN_TEST);
};

bool isExhaustivePatternTestEnabled()
{
    return isMfgFlagSet
                     (TARGETING::MFG_FLAGS_MNFG_ENABLE_EXHAUSTIVE_PATTERN_TEST);
};

bool isUpdateBothSidesOfSbe()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_UPDATE_BOTH_SIDES_OF_SBE);
};

bool isUpdateSbeImage()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_FSP_UPDATE_SBE_IMAGE);
};

bool isSMPWrapConfig()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_SMP_WRAP_CONFIG);
};

bool isNoGardSet()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_NO_GARD);
};

bool isSeepromSecurityChecksSet()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_SEEPROM_SECURITY_CHECKS);
};

bool isDimmSpiFlashScreenSet()
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_DIMM_SPI_FLASH_SCREEN);
};

// Canned responses with bit-field of all the manufacturing flags as a parameter
bool isMfgSpareDramDeploy(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_TEST_RBS,
                        i_mfgFlags);
};

bool areAllSrcsTerminating(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_SRC_TERM,
                        i_mfgFlags);
};

bool isDramRepairsDisabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_NO_RBS,
                        i_mfgFlags);
};

bool areMfgThresholdsActive(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_THRESHOLDS,
                        i_mfgFlags);
};

bool isMfgAvpEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_AVP_ENABLE,
                        i_mfgFlags);
};

bool isMfgHdatAvpEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_HDAT_AVP_ENABLE,
                        i_mfgFlags);
};

bool isEnableFastBackgroundScrub(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_FAST_BACKGROUND_SCRUB,
                        i_mfgFlags);
};

bool isMemoryRepairDisabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_DISABLE_MEMORY_eREPAIR,
                        i_mfgFlags);
};

bool isFabricRepairDisabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_DISABLE_FABRIC_eREPAIR,
                        i_mfgFlags);
};

bool isMfgCeCheckingEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_IPL_MEMORY_CE_CHECKING,
                        i_mfgFlags);
};

bool isMinimumPatternTestEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_ENABLE_MINIMUM_PATTERN_TEST,
                        i_mfgFlags);
};

bool isStandardPatternTestEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_ENABLE_STANDARD_PATTERN_TEST,
                        i_mfgFlags);
};

bool isExhaustivePatternTestEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(
                      TARGETING::MFG_FLAGS_MNFG_ENABLE_EXHAUSTIVE_PATTERN_TEST,
                      i_mfgFlags);
};

bool isUpdateBothSidesOfSbe(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_UPDATE_BOTH_SIDES_OF_SBE,
                        i_mfgFlags);
};

bool isUpdateSbeImage(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_FSP_UPDATE_SBE_IMAGE,
                        i_mfgFlags);
};

bool isSMPWrapConfig(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_SMP_WRAP_CONFIG,
                        i_mfgFlags);
};

bool isNoGardSet(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_NO_GARD,
                        i_mfgFlags);
}

bool isSeepromSecurityChecksSet(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_SEEPROM_SECURITY_CHECKS,
                        i_mfgFlags);
}

bool isDimmSpiFlashScreenSet(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags)
{
    return isMfgFlagSet(TARGETING::MFG_FLAGS_MNFG_DIMM_SPI_FLASH_SCREEN,
                        i_mfgFlags);
}

//##############################################################################
//##                 Manufacturing (MFG) Flag full API
//##############################################################################

// convertFlagNumericValueToFlagMask
static uint32_t convertFlagNumericValueToFlagMask(MFG_FLAGS i_mfgFlag)
{
    // Constant for the most signification bit of a 32 bit integer
    constexpr uint32_t l_msb(0x80000000);

    // Get the shifting value
    uint32_t l_mfgFlagMaskShiftValue = i_mfgFlag %
                                       MFG_FLAG_SIZE_OF_CELL_IN_BITS;

    // Shift the most significant bit, 1, to the proper position to get
    // the mask value, then return that value.
    return (l_msb >> l_mfgFlagMaskShiftValue);
} // convertFlagNumericValueToFlagMask

// getAllMfgFlags
void getAllMfgFlags(ATTR_MFG_FLAGS_typeStdArr &o_allMfgFlags)
{
    // Get a handle to the System target
    TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();

    // Get the manufacturing flags from the System target
    o_allMfgFlags = l_systemTarget->getAttrAsStdArr<ATTR_MFG_FLAGS>();
}

// setMfgFlag
void setMfgFlag(const MFG_FLAGS i_mfgFlag)
{
    // Create local storage to hold all of the manufacturing flags
    ATTR_MFG_FLAGS_typeStdArr l_allMfgFlags = { 0 };

    // Get the manufacturing flags from the System target
    getAllMfgFlags(l_allMfgFlags);

    // Convert caller's manufacturing flag to a mask and then add
    // this mask (flag) to the correct cell
    l_allMfgFlags[getMfgFlagCellIndex(i_mfgFlag)] |=
                                  convertFlagNumericValueToFlagMask(i_mfgFlag);

    // Update the System target to contain the additional flag
    setAllMfgFlags(l_allMfgFlags);
}

// setMfgFlag
void setMfgFlag(const TARGETING::MFG_FLAGS       i_mfgFlag,
                      ATTR_MFG_FLAGS_typeStdArr &io_allMfgFlags)
{
    // Convert caller's manufacturing flag to a mask and then add
    // this mask (flag) to the correct cell
    io_allMfgFlags[getMfgFlagCellIndex(i_mfgFlag)] |=
                                  convertFlagNumericValueToFlagMask(i_mfgFlag);
} // setMfgFlag(const char32_t i_mfgFlag)

// setAllMfgFlags
void setAllMfgFlags(const ATTR_MFG_FLAGS_typeStdArr &i_allMfgFlags)
{
    // Get a handle to the System target
    TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();

    // Now set the System target manufacturing flags with the caller's flags
    l_systemTarget->setAttrFromStdArr<ATTR_MFG_FLAGS>(i_allMfgFlags);
}

// clearMfgFlag
void clearMfgFlag(const TARGETING::MFG_FLAGS i_mfgFlag)
{
    // Create local storage to hold all of the manufacturing flags
    ATTR_MFG_FLAGS_typeStdArr l_allMfgFlags = { 0 };

    // Get the manufacturing flags from the System target
    getAllMfgFlags(l_allMfgFlags);

    // Convert caller's manufacturing flag to a mask and then clear
    // this mask (flag) at the correct cell location.
    l_allMfgFlags[getMfgFlagCellIndex(i_mfgFlag)] &= ~convertFlagNumericValueToFlagMask(i_mfgFlag);

    // Update the System target to contain the additional flag
    setAllMfgFlags(l_allMfgFlags);
}

// clearMfgFlag
void clearMfgFlag(const TARGETING::MFG_FLAGS       i_mfgFlag,
                  ATTR_MFG_FLAGS_typeStdArr       &io_allMfgFlags)
{
    // Convert caller's manufacturing flag to a mask and then clear
    // this mask (flag) at the correct cell location
    io_allMfgFlags[getMfgFlagCellIndex(i_mfgFlag)] &= ~convertFlagNumericValueToFlagMask(i_mfgFlag);
}

// isMfgFlagSet
bool isMfgFlagSet(const TARGETING::MFG_FLAGS       i_mfgFlag,
                  const ATTR_MFG_FLAGS_typeStdArr &i_allMfgFlags)
{
    // Default the return value to false, switch to true if flag found
    bool l_retVal(false);

    // If the flag is found in list of all manufacturing flags then return true
    if (convertFlagNumericValueToFlagMask(i_mfgFlag) &
                           i_allMfgFlags[getMfgFlagCellIndex(i_mfgFlag)])
    {
        l_retVal = true;
    }

    return l_retVal;
} //isMfgFlagSet

// isMfgFlagSet
bool isMfgFlagSet(const TARGETING::MFG_FLAGS i_mfgFlag)
{
    // Create local storage to hold all of the manufacturing flags
    ATTR_MFG_FLAGS_typeStdArr l_allMfgFlags = {0};

    // Get all of the manufacturing flags from the System target
    getAllMfgFlags(l_allMfgFlags);

    // Determine if flag is in the list of all manufacturing flags and return
    // answer
    return (isMfgFlagSet(i_mfgFlag, l_allMfgFlags));
} // isMfgFlagSet

// getMfgFlagCellIndex
uint32_t getMfgFlagCellIndex(const MFG_FLAGS i_mfgFlag)
{
    // If the manufacturing flag value is greater than cell 3's max value, then
    // there is a s/w coding error.  It could be the flags got upgraded
    // and this method did not get adjusted.
    TARG_ASSERT(i_mfgFlag <= MFG_FLAG_CELL_3_MAX_VAL,
           "mfgFlagAccessors.C::getMfgFlagCellIndex: "
           "Manufacturing flag %d is greater than the maximum value of %d",
           i_mfgFlag, MFG_FLAG_CELL_3_MAX_VAL);

    // Default the return value to cell 0's index value
    uint32_t l_retVal(MFG_FLAG_CELL_0_INDEX);

    if (i_mfgFlag > MFG_FLAG_CELL_2_MAX_VAL)
    {
        // If the manufacturing flag value is greater than the max value for
        // cell 2, then it must be in cell 3.
        l_retVal = MFG_FLAG_CELL_3_INDEX;
    }
    else if (i_mfgFlag > MFG_FLAG_CELL_1_MAX_VAL)
    {
        // If the manufacturing flag value is greater than the max value for
        // cell 1, but less than the max value for cell 2 (see previous if),
        // then it must be in cell 2.
        l_retVal = MFG_FLAG_CELL_2_INDEX;

    }
    else if (i_mfgFlag > MFG_FLAG_CELL_0_MAX_VAL)
    {
        // If the manufacturing flag value is greater than the max value for
        // cell 0, but less than the max value for cell 1 (see previous if),
        // then it must be in cell 1
        l_retVal = MFG_FLAG_CELL_1_INDEX;
    }
    // else defaults to cell 0, which is what the return value is defaulted to

    return l_retVal;
} // getMfgFlagCellIndex

} // namespace TARGETING

#endif // __cplusplus >= 201103L
