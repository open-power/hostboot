/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrPlatOverride.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
//@TODO RTC:128106
//#include <hwpf/plat/fapiPlatAttrOverrideSync.H>
#include <targeting/common/trace.H>
#include <targeting/common/targreasoncodes.H>
#include <errl/errlmanager.H>

namespace TARGETING
{

errlHndl_t getAttrOverrides(PNOR::SectionInfo_t &i_sectionInfo,
                      AttributeTank* io_tanks[AttributeTank::TANK_LAYER_LAST])
{
    TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides ENTER");

    // Create local permanent override tank and array of tanks
    errlHndl_t l_err = NULL;
    AttributeTank l_PermTank;
    AttributeTank* l_overTanks[AttributeTank::TANK_LAYER_LAST];

    // Local pointer to array containing each tank layer or io_tanks
    AttributeTank* *l_pOverTanks;

    // If no attribute tanks specified grab all TankLayers to create attribute
    // tanks with in enum order
    if (io_tanks == NULL)
    {
        // All indexes are -1 due to the first enum being TANK_LAYER_NONE,
        //@TODO RTC:128106
        //l_overTanks[AttributeTank::TANK_LAYER_FAPI-1] =
        //            &fapi::theAttrOverrideSync().iv_overrideTank;
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

        uint32_t l_index = 0;
        // Deserialize each section
        while (l_index < i_sectionInfo.size)
        {
            AttrOverrideSection * l_pAttrOverSec =
                reinterpret_cast<AttrOverrideSection *>
                    (i_sectionInfo.vaddr + l_index);

            // Reached termination chunk
            if (l_pAttrOverSec->iv_layer == AttributeTank::TANK_LAYER_TERM)
            {
                TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides Reached termination section at chunk (0x%x)",
                            (i_sectionInfo.size - l_index));
                break;
            }

            // Remaining chunk smaller than AttrOverrideSection, quit
            if (sizeof(AttrOverrideSection) > (i_sectionInfo.size - l_index))
            {
                TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides AttrOverrideSection too big for chunk (0x%x)",
                            (i_sectionInfo.size - l_index));
                /*@
                 * @errortype
                 * @moduleid     TARG_GET_ATTR_OVER
                 * @reasoncode   TARG_RC_ATTR_OVER_PNOR_SEC_SPACE_FAIL
                 * @userdata1    PNOR Section specified
                 * @userdata2    Size of AttrOverrideSection
                 * @devdesc      AttrOverrideSection too big to fit in remaining
                 *               chunck of pnor section
                 * @custdesc     Invalid configuration data in firmware pnor
                 */
                l_err =
                    new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_PREDICTIVE,
                     TARG_GET_ATTR_OVER,
                     TARG_RC_ATTR_OVER_PNOR_SEC_SPACE_FAIL,
                     i_sectionInfo.id,
                     sizeof(AttrOverrideSection));
                l_err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                           HWAS::SRCI_PRIORITY_HIGH);
                    break;
            }

            l_index += sizeof(AttrOverrideSection);

            // Remaining chunk smaller than serialized chunk size, quit
            if (l_pAttrOverSec->iv_size > (i_sectionInfo.size - l_index))
            {
                TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides serialized chunk too big for chunk (0x%x)",
                            (i_sectionInfo.size - l_index));
                /*@
                 * @errortype
                 * @moduleid     TARG_GET_ATTR_OVER
                 * @reasoncode   TARG_RC_ATTR_OVER_ATTR_DATA_SIZE_FAIL
                 * @userdata1    PNOR Section specified
                 * @userdata2    Size of Serialized attribute override
                 * @devdesc      Serialized attribute override chunk too big to
                 *               fit in remaining chunck of pnor section
                 * @custdesc     Invalid configuration data in firmware pnor
                 */
                l_err =
                    new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_PREDICTIVE,
                     TARG_GET_ATTR_OVER,
                     TARG_RC_ATTR_OVER_ATTR_DATA_SIZE_FAIL,
                     i_sectionInfo.id,
                     l_pAttrOverSec->iv_size);
                l_err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                           HWAS::SRCI_PRIORITY_HIGH);
                break;
            }

            // Check if a tank layer is specified, if not we can't apply the
            // attribute override.
            if (l_pAttrOverSec->iv_layer == AttributeTank::TANK_LAYER_NONE)
            {
                TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides no tank layer specified at chunk (0x%x)",
                            (i_sectionInfo.size - l_index));
                /*@
                 * @errortype
                 * @moduleid     TARG_GET_ATTR_OVER
                 * @reasoncode   TARG_RC_WRITE_ATTR_OVER_NO_TANK_LAYER
                 * @userdata1    PNOR Section specified
                 * @userdata2    Chunk location with no tank layer
                 * @devdesc      No tank layer was specified for attribute
                 *               override.
                 * @custdesc     Invalid configuration data in firmware pnor
                 */
                l_err =
                    new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_PREDICTIVE,
                     TARG_GET_ATTR_OVER,
                     TARG_RC_WRITE_ATTR_OVER_NO_TANK_LAYER,
                     i_sectionInfo.id,
                     (i_sectionInfo.size - l_index));
                l_err->collectTrace("TARG",256);
                l_err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                           HWAS::SRCI_PRIORITY_HIGH);
                ERRORLOG::errlCommit(l_err, TARG_COMP_ID);
            }
            // Check if the AttrOverSec is in the correct PNOR section
            // It was decided that this should not cause a failed IPL, so the
            // override will not be applied, the errl will be committed, then
            // we move on.
            else if (tankLayerToPnor[l_pAttrOverSec->iv_layer - 1].second !=
                                                            i_sectionInfo.id)
            {
                TRACFCOMP(g_trac_targeting,"getAttrOverrides: Failed to apply override - override with TankLayer 0x%X should not be in PNOR::%s",
                            l_pAttrOverSec->iv_layer, i_sectionInfo.name);
                /*@
                 * @errortype
                 * @moduleid     TARG_GET_ATTR_OVER
                 * @reasoncode   TARG_RC_WRITE_ATTR_OVER_WRONG_PNOR_SEC
                 * @userdata1    Tank Layer of attribute
                 * @userdata2    PNOR Section specified
                 * @devdesc      Attribute override is in the wrong pnor section
                 *               needs to be moved to the section associated
                 *               with its attribute tank layer
                 * @custdesc     Invalid configuration data in firmware pnor
                 */
                l_err =
                    new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_PREDICTIVE,
                     TARG_GET_ATTR_OVER,
                     TARG_RC_WRITE_ATTR_OVER_WRONG_PNOR_SEC,
                     l_pAttrOverSec->iv_layer,
                     i_sectionInfo.id);
                l_err->collectTrace("TARG",256);
                l_err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                           HWAS::SRCI_PRIORITY_HIGH);
                ERRORLOG::errlCommit(l_err, TARG_COMP_ID);
            }
            // Only apply attribute override if in the correct PNOR section
            else
            {
                TRACFCOMP(g_trac_targeting,"getAttrOverrides:"
                            " override into TankLayer 0x%X",
                            l_pAttrOverSec->iv_layer);

                // Get the AttributeTank that corresponds to the TankLayer in
                // the AttrOverrideSection. Enum starts with TANK_LAYER_NONE
                // so need to subtract 1
                AttributeTank* l_ptank =
                                     l_pOverTanks[l_pAttrOverSec->iv_layer - 1];

                // Create serialized chunck with AttrOverrideSection data
                AttributeTank::AttributeSerializedChunk l_chunk;
                l_chunk.iv_size = l_pAttrOverSec->iv_size;
                l_chunk.iv_pAttributes = &l_pAttrOverSec->iv_chunk[0];

                // Deserialize the data with the approriate AttributeTank
                l_ptank->deserializeAttributes(l_chunk);
            }
            l_index += l_pAttrOverSec->iv_size;
        }

        if (l_err)
        {
            break;
        }

        // Write permanent attribute overrides
        if ((i_sectionInfo.id == PNOR::ATTR_PERM) &&
            (l_PermTank.size() > 0) )
        {
            // l_PermTank should be empty if the section is not ATTR_PERM
            // with the check above, but sanity check
            l_err = l_PermTank.writePermAttributes();
            break;
        }

    } while(0);

    TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides EXIT");
    return l_err;
}

} // end of namespace


