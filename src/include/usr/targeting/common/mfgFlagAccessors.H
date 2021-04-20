/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/mfgFlagAccessors.H $         */
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

/**
 *  @file targeting/common/mfgFlagAccessors.H
 *
 *  @brief Provides an API for setting/getting and determining if a
 *         manufacturing flag is set.
 */

#ifndef __TARGETING_COMMON_MFG_FLAG_ACCESSORS_H
#define __TARGETING_COMMON_MFG_FLAG_ACCESSORS_H

// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L

//******************************************************************************
// Includes
//******************************************************************************
#include <stdint.h>                      // uint32_t
#include <targeting/common/attributes.H> // TARGETING::MFG_FLAGS, ATTR_MFG_FLAGS

namespace TARGETING
{

//##############################################################################
//##                   Manufacturing (MFG) Constants
//##############################################################################

// Masks that define a cell as being cell 0, 1, 2 or 3
// Each cell, a 32 bit integer, can self identify with these masks.
// A 32 bit integer can be identified as cell 0 when using the mask for cell 0,
// a 32 bit integer can be identified as cell 1 when using the mask for cell 1,
// etc.
constexpr uint32_t MFG_FLAG_CELL_0_MASK = 0x00000000;
constexpr uint32_t MFG_FLAG_CELL_1_MASK = 0x00020000;
constexpr uint32_t MFG_FLAG_CELL_2_MASK = 0x00040000;
constexpr uint32_t MFG_FLAG_CELL_3_MASK = 0x00080000;

// Indexes to the individual cells
constexpr uint32_t MFG_FLAG_CELL_0_INDEX = 0;
constexpr uint32_t MFG_FLAG_CELL_1_INDEX = 1;
constexpr uint32_t MFG_FLAG_CELL_2_INDEX = 2;
constexpr uint32_t MFG_FLAG_CELL_3_INDEX = 3;

// Constants that define the number of cells and cell sizes
constexpr uint32_t MFG_FLAG_NUM_CELLS = 4;
constexpr uint32_t MFG_FLAG_SIZE_OF_CELL_IN_BITS = 32;
constexpr uint32_t MFG_FLAG_SIZE_OF_A_CELL_IN_BYTES = sizeof(uint32_t);
constexpr uint32_t MFG_FLAG_SIZE_OF_ALL_CELLS_IN_BYTES =
                        MFG_FLAG_NUM_CELLS * MFG_FLAG_SIZE_OF_A_CELL_IN_BYTES;

// Constants that define the maximum value for each cell
constexpr uint32_t MFG_FLAG_CELL_0_MAX_VAL =
             ((MFG_FLAG_CELL_0_INDEX + 1) * MFG_FLAG_SIZE_OF_CELL_IN_BITS) -1;
constexpr uint32_t MFG_FLAG_CELL_1_MAX_VAL =
             ((MFG_FLAG_CELL_1_INDEX + 1) * MFG_FLAG_SIZE_OF_CELL_IN_BITS) -1;
constexpr uint32_t MFG_FLAG_CELL_2_MAX_VAL =
             ((MFG_FLAG_CELL_2_INDEX + 1) * MFG_FLAG_SIZE_OF_CELL_IN_BITS) -1;
constexpr uint32_t MFG_FLAG_CELL_3_MAX_VAL =
             ((MFG_FLAG_CELL_3_INDEX + 1) * MFG_FLAG_SIZE_OF_CELL_IN_BITS) -1;


//##############################################################################
//## Methods that directly call the manufacturing (MFG) Flag Canned Responses
//## are better suited here in this file, at least from a compile perspective.
//##############################################################################

/**
 * @brief   Checks if we are loading a PHYP payload
 *
 * @description  Looks at both ATTR_PAYLOAD_KIND and the manufacturing flags
 *               to determine if we are really loading and starting PHYP
 *
 * @param[out]   Current value of PAYLOAD_KIND
 * @return  True if PHYP will be loaded and started
 */
bool is_phyp_load( ATTR_PAYLOAD_KIND_type* o_type = NULL );

/**
 * @brief  Utility function to determine if Sapphire is the payload
 *
 * @description  If the payload kind is Sapphire returns true.  Does
 *    not matter if it is Sapphire with FSP or standalone
 *
 * @return bool  True when loading sapphire
 */
bool is_sapphire_load(void);


//##############################################################################
//##             Manufacturing (MFG) Flag Canned Responses
//##############################################################################

/**
 * @brief  Utility function to determine if an AVP is the payload
 *         Note the actual payload could be something else -- this
 *         is based solely on MFG flags
 *
 * @description  If MFG AVP mode flags are set then returns true
 *      Does not matter what the actual payload is
 *
 * @return bool  True when in AVP mode
 */
bool is_avp_load();

/**
 * @brief Check if a particular manufacturing flag is set
 *
 * @note The following functions abstract out the actual manufacturing
 *       flags for a conceptual API.
 *       Confining the API, for the manufacturing flags, into one source file,
 *       allows for any future maintenance of the flags (name change, new flag,
 *       etc) to be minimized to this single source file.
 *
 * @note If checking multiple flags in a single method then use the sister
 *       functions below, of the same name, to expedite in time.
 *
 * @note doxygen output will not be made for all these functions
 *
 * @return bool - returns true if the manufacturing flag is set for the
 *                associated API, false otherwise.
 */
bool isMfgSpareDramDeploy();
bool areAllSrcsTerminating();
bool isDramRepairsDisabled();
bool areMfgThresholdsActive();
bool isMfgAvpEnabled();
bool isMfgHdatAvpEnabled();
bool isEnableFastBackgroundScrub();
bool isMemoryRepairDisabled();
bool isFabricRepairDisabled();
bool isMfgCeCheckingEnabled();
bool isMinimumPatternTestEnabled();
bool isStandardPatternTestEnabled();
bool isExhaustivePatternTestEnabled();
bool isUpdateBothSidesOfSbe();
bool isUpdateSbeImage();
bool isSMPWrapConfig();
bool isNoGardSet();
bool isSeepromSecurityChecksSet();

/**
 * @brief Check if a particular manufacturing flag is set
 *
 * @note The following functions abstract out the actual manufacturing
 *       flags for a conceptual API.
 *       Confining the API, for the manufacturing flags, into one source file,
 *       allows for any future maintenance of the flags (name change, new flag,
 *       etc) to be minimized to this single source file.
 *
 * @note These functions are useful for when checking multiple flags within
 *       a single method by only checking against the flag list that is passed
 *       in, as a parameter, and not constantly retrieving the list from the
 *       system target.
 *
 * @note doxygen output will not be made for all these functions
 *
 * @param i_mfgFlags - A bit-field of all the manufacturing flags, presumably
 *                     retrieved by using method 'getAllMfgFlags' found below.
 *
 * @return bool - returns true if the manufacturing flag is set for the
 *                associated API, false otherwise.
 */
bool isMfgSpareDramDeploy(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool areAllSrcsTerminating(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isDramRepairsDisabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool areMfgThresholdsActive(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isMfgAvpEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isMfgHdatAvpEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isEnableFastBackgroundScrub(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isMemoryRepairDisabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isFabricRepairDisabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isMfgCeCheckingEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isMinimumPatternTestEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isStandardPatternTestEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isExhaustivePatternTestEnabled(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isUpdateBothSidesOfSbe(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isUpdateSbeImage(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isSMPWrapConfig(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isNoGardSet(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);
bool isSeepromSecurityChecksSet(ATTR_MFG_FLAGS_typeStdArr &i_mfgFlags);


//##############################################################################
//##                 Manufacturing (MFG) Flag Full API
//##############################################################################

/**
 * @brief Get all the manufacturing flags
 *
 * @details Get all the manufacturing flags from the System target from
 *          attribute ATTR_MFG_FLAGS.
 *
 * @note Will assert if unable to get a handle to the System target.
 *
 * @param[in] o_allMfgFlags - A bit-field of all the manufacturing flags.
 */
void getAllMfgFlags(ATTR_MFG_FLAGS_typeStdArr &o_allMfgFlags);

/**
 * @brief Set an individual manufacturing flag
 *
 * @details Set an individual manufacturing flag for the System target on
 *          attribute ATTR_MFG_FLAGS.
 *
 * @note Will assert if unable to get a handle to the System target.
 *
 * @param[in] i_mfgFlag - manufacturing flag to set
 */
void setMfgFlag(TARGETING::MFG_FLAGS i_mfgFlag);

/**
 * @brief Set an individual manufacturing flag
 *
 * @details Set an individual manufacturing flag on the given data
 *
 * @param[in] i_mfgFlag     - manufacturing flag to set
 * @param[in] i_allMfgFlags - data to set the flag against
 */
void setMfgFlag(TARGETING::MFG_FLAGS       i_mfgFlag,
                ATTR_MFG_FLAGS_typeStdArr &io_allMfgFlags);

/**
 * @brief Set all the manufacturing flags
 *
 * @details Set ATTR_MFG_FLAGS attribute on the Sytem target according to
 *          i_allMfgFlags.
 *
 * @note Will assert if unable to get a handle to the System target.
 *
 * @param[in] i_allMfgFlags - A bit-field of all the manufacturing flags.
 */
void setAllMfgFlags(const ATTR_MFG_FLAGS_typeStdArr &i_allMfgFlags);

/**
 * @brief Determine if a manufacturing flag is set
 *
 * @details Determine if a manufacturing flag is set for the given flag
 *          (i_mfgFlag) against the given bit-field (i_allMfgFlags).
 *
 * @param[in] i_mfgFlag     - The manufacturing flag to find in the
 *                            bit-field list.
 * @param[in] i_allMfgFlags - A bit-field that contains a list of set
 *                            manufacturing flags.
 *
 * @return true if the manufacturing flag is set, false otherwise
 */
bool isMfgFlagSet(      TARGETING::MFG_FLAGS       i_mfgFlag,
                  const ATTR_MFG_FLAGS_typeStdArr &i_allMfgFlags);

/**
 * @brief Determine if manufacturing flag is set
 *
 * @details Determine if manufacturing flag is set for the given flag
 *          (i_mfgFlag) against the bit-field list retrieved from the
 *          System target's attribute ATTR_MFG_FLAGS.
 *
 * @note Will assert if unable to get a handle to the System target.
 *
 * @param[in] i_mfgFlag - The manufacturing flag to find against the bit-field
 *                        list retrieved from the System target.
 *
 * @return true if the manufacturing flag is set, false otherwise
 */
bool isMfgFlagSet(TARGETING::MFG_FLAGS i_mfgFlag);

/**
 * @brief Get the cell index associated with manufacturing flag
 *
 * @note Will assert if manufacturing flag is out of bounds.
 *
 * @param[in] i_mfgFlag - The manufacturing flag to find the cell index of
 *
 * @return the cell index the manufacturing flag is associated with
 */
uint32_t getMfgFlagCellIndex(TARGETING::MFG_FLAGS i_mfgFlag);


//##############################################################################
//##             Manufacturing (MFG) Flag Canned Responses
//## These canned functions are at the bottom of the file after the
//## API it uses are declared.
//##############################################################################




} // namespace TARGETING

#endif // __cplusplus >= 201103L

#endif // __TARGETING_COMMON_MFG_FLAG_ACCESSORS_H
