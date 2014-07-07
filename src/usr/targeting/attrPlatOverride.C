/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrPlatOverride.C $                        */
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
#include <targeting/attrPlatOverride.H>
#include <hwpf/plat/fapiPlatAttrOverrideSync.H>
#include <targeting/common/trace.H>
#include <targeting/common/targreasoncodes.H>

namespace TARGETING
{

errlHndl_t getAttrOverrides(PNOR::SectionId i_section,
                      AttributeTank* io_tanks[AttributeTank::TANK_LAYER_LAST],
                      uint32_t pnorSecOffset)
{
    TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides ENTER");

    // Create local permanent override tank and array of tanks
    AttributeTank l_PermTank;
    AttributeTank* l_overTanks[AttributeTank::TANK_LAYER_LAST];
    errlHndl_t l_err = NULL;

    // Local pointer to array containing each tank layer or io_tanks
    AttributeTank* *l_pOverTanks;

    // If no attribute tanks specified grab all TankLayers to create attribute
    // tanks with in enum order
    if (io_tanks == NULL)
    {
        // All indexes are -1 due to the first enum being TANK_LAYER_NONE,
        l_overTanks[AttributeTank::TANK_LAYER_FAPI-1] =
                    &fapi::theAttrOverrideSync().iv_overrideTank;
        l_overTanks[AttributeTank::TANK_LAYER_TARG-1] =
                    &Target::theTargOverrideAttrTank();
        l_overTanks[AttributeTank::TANK_LAYER_PERM-1] = &l_PermTank;
        l_pOverTanks = l_overTanks;
    }
    else
    {
        l_pOverTanks = io_tanks;
    }

    do
    {
        // Read PNOR section
        PNOR::SectionInfo_t sectionInfo;
        l_err = PNOR::getSectionInfo( i_section, sectionInfo );
        // Attr override sections are optional so just delete error and break
        if (l_err)
        {
            delete l_err;
            l_err = NULL;
            break;
        }

        uint32_t l_index = pnorSecOffset;
        // Deserialize each section
        while (l_index < sectionInfo.size)
        {
            AttrOverrideSection * l_pAttrOverSec =
                reinterpret_cast<AttrOverrideSection *>
                    (sectionInfo.vaddr + l_index);

            // Reached termination chunck
            if (l_pAttrOverSec->iv_layer == AttributeTank::TANK_LAYER_NONE)
            {
                TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides Reached termination section at chunk (0x%x)",
                            (sectionInfo.size - l_index));
                break;
            }

            // Remaining chunk smaller than AttrOverrideSection, quit
            if (sizeof(AttrOverrideSection) > (sectionInfo.size - l_index))
            {
                TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides AttrOverrideSection too big for chunk (0x%x)",
                            (sectionInfo.size - l_index));
            /*@
             * @errortype
             * @moduleid     TARG_GET_ATTR_OVER
             * @reasoncode   TARG_RC_ATTR_OVER_PNOR_SEC_SPACE_FAIL
             * @userdata1    PNOR Section specified
             * @userdata2    Size of AttrOverrideSection
             * @devdesc      AttrOverrideSection too big to fit in remaining
             *               chunck of pnor section
             */
            l_err =
                new ERRORLOG::ErrlEntry
                (ERRORLOG::ERRL_SEV_PREDICTIVE,
                 TARG_GET_ATTR_OVER,
                 TARG_RC_ATTR_OVER_PNOR_SEC_SPACE_FAIL,
                 i_section,
                 sizeof(AttrOverrideSection),
                 true /*SW callout*/);
                break;
            }

            l_index += sizeof(AttrOverrideSection);

            // Remaining chunk smaller than serialized chunk size, quit
            if (l_pAttrOverSec->iv_size > (sectionInfo.size - l_index))
            {
                TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides serialized chunk too big for chunk (0x%x)",
                            (sectionInfo.size - l_index));
                /*@
                 * @errortype
                 * @moduleid     TARG_GET_ATTR_OVER
                 * @reasoncode   TARG_RC_ATTR_OVER_ATTR_DATA_SIZE_FAIL
                 * @userdata1    PNOR Section specified
                 * @userdata2    Size of Serialized attribute override
                 * @devdesc      Serialized attribute override chunk too big to
                 *               fit in remaining chunck of pnor section
                 */
                l_err =
                    new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_PREDICTIVE,
                     TARG_GET_ATTR_OVER,
                     TARG_RC_ATTR_OVER_ATTR_DATA_SIZE_FAIL,
                     i_section,
                     l_pAttrOverSec->iv_size,
                     true /*SW callout*/);
                break;
            }

            // Get the AttributeTank that corresponds to the TankLayer in the
            // AttrOverrideSection. Enum starts with TANK_LAYER_NONE so need to
            // substract 1
            AttributeTank* l_ptank = l_pOverTanks[l_pAttrOverSec->iv_layer - 1];

            // Create serialized chunck with AttrOverrideSection data
            AttributeTank::AttributeSerializedChunk l_chunk;
            l_chunk.iv_size = l_pAttrOverSec->iv_size;
            l_chunk.iv_pAttributes = &l_pAttrOverSec->iv_chunk[0];

            // Deserialize the data with the approriate AttributeTank
            l_ptank->deserializeAttributes(l_chunk);
            l_index += l_pAttrOverSec->iv_size;
        }

        // Write permanent attribute overrides
        l_err = l_PermTank.writePermAttributes();

    } while(0);

    TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides EXIT");
    return l_err;
}

} // end of namespace


