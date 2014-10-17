/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/attrPlatOverride.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __ATTR_PLAT_OVERRIDE_H
#define __ATTR_PLAT_OVERRIDE_H

#include <targeting/common/attributeTank.H>
#include <pnor/pnorif.H>
#include <utility>

namespace TARGETING
{

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
const std::pair<AttributeTank::TankLayer, PNOR::SectionId>
    tankLayerToPnor[AttributeTank::TANK_LAYER_LAST] =
    {
        std::make_pair(AttributeTank::TANK_LAYER_FAPI, PNOR::ATTR_TMP),
        std::make_pair(AttributeTank::TANK_LAYER_TARG, PNOR::ATTR_TMP),
        std::make_pair(AttributeTank::TANK_LAYER_PERM, PNOR::ATTR_PERM)
    };

/**
 * @brief This function gets any Attribute Overrides in PNOR
 *
 * This function reads attribute overrides in from PNOR and places them in
 * the appropriate attribute tank. It also calls writePermAttributes() to write
 * permanent attribute overrides. Currently there are 3 attribute tanks,
 * FAPI, Targeting, and Permanent.
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