/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/attrPlatOverride.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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
 *  @file attrPlatOverride.H
 *
 *  @brief Defines platform level functions used to read and parse
 *         attribute override data.
 */

#ifndef __ATTR_PLAT_OVERRIDE_H
#define __ATTR_PLAT_OVERRIDE_H

#include <targeting/common/attributeTank.H>
#include <pnor/pnorif.H>
#include <utility>

namespace TARGETING
{

/**
 * @brief This function checks the format of Attribute Overrides in ATTR_TMP
 *
 * This function checks the ATTR_TMP section for the possible attribute tank
 * layer types and returns true if one is found. If one is not found, then
 * any ATTR_TMP data must be ascii attribute override data.
 *
 * @param[in] i_sectionInfo   PNOR::SectionInfo_t to look for overrides
 *
 * @return bool   true if attribute tank layer found, else false
 */
bool attrTankLayerFound(const PNOR::SectionInfo_t &i_sectionInfo);

/**
 * @struct AttrOverrideSection
 *
 * This structure defines the layout of the PNOR attribute override section
 *
 */
struct AttrOverrideSection
{
    AttributeTank::TankLayer iv_layer;
    size_t iv_size;
    uint8_t iv_chunk[0];
};

/**
 * @brief Array containing AttributeTank layers to Pnor Override Sections
 *
 *        The pair is used just to maintain order of AttributeTank::TankLayer
 *        enums and make it obvious which layers map to what PNOR section.
 *        Currrently the pair is only used in a test case to keep it in order
 */
extern const std::pair<AttributeTank::TankLayer, PNOR::SectionId>
    tankLayerToPnor[AttributeTank::TANK_LAYER_LAST];

/**
 * @brief This function gets any Attribute Overrides in PNOR
 *
 * This function reads attribute overrides in from PNOR and places them in
 * the appropriate attribute tank. It also calls writePermAttributes() to write
 * permanent attribute overrides. Currently there are 3 attribute tanks,
 * FAPI, Targeting, and Permanent.
 *
 * For runtime attribute updates, a PNOR::SectionInfo is set up to point to the
 * passed attribute update binary blob instead of being a 'real' pnor section.
 *
 * @param[in] i_sectionInfo   PNOR::SectionInfo_t to look for overrides
 * @param[in] io_tanks        Array of pointers to Attribute tanks, used for
 *                            test cases, default set to NULL
 *
 * @return errlHndl_t         Error log handle.
 */
errlHndl_t getAttrOverrides(PNOR::SectionInfo_t &i_sectionInfo,
              AttributeTank* io_tanks[AttributeTank::TANK_LAYER_LAST] = NULL);

} // end of namespace

#endif
