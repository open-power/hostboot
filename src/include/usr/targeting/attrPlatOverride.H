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
 * @brief This function gets any Attribute Overrides in PNOR
 *
 * This function reads attribute overrides in from PNOR and places them in
 * the appropriate attribute tank. It also calls writePermAttributes() to write
 * permanent attribute overrides. Currently there are 3 attribute tanks,
 * FAPI, Targeting, and Permanent.
 *
 * @param[in] i_section       PNOR::SectionId to look for overrides default
 *                            ATTR_OVER
 * @param[in] io_tanks        Array of pointers to Attribute tanks, used for
 *                            test cases, default set to NULL
 * @param[in] i_pnorSecOffset Offset within section to read, used for test cases
 *                            default set to 0
 *
 * @return errlHndl_t         Error log handle.
 */
errlHndl_t getAttrOverrides(PNOR::SectionId i_section = PNOR::ATTR_OVER,
              AttributeTank* io_tanks[AttributeTank::TANK_LAYER_LAST] = NULL,
              uint32_t i_pnorSecOffset = 0);
//errlCommit( err, TARG_COMP_ID);

} // end of namespace

#endif