/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrPlatOverride.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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
#include <fapi2/plat_attr_override_sync.H>
#include <targeting/common/trace.H>
#include <targeting/common/targreasoncodes.H>
#include <errl/errlmanager.H>
#include <secureboot/service.H>
#include <console/consoleif.H>

namespace TARGETING
{

const std::pair<AttributeTank::TankLayer, PNOR::SectionId>
    tankLayerToPnor[AttributeTank::TANK_LAYER_LAST] =
    {
        std::make_pair(AttributeTank::TANK_LAYER_FAPI, PNOR::ATTR_TMP),
        std::make_pair(AttributeTank::TANK_LAYER_TARG, PNOR::ATTR_TMP),
        std::make_pair(AttributeTank::TANK_LAYER_PERM, PNOR::ATTR_PERM)
    };

errlHndl_t getAttrOverrides(PNOR::SectionInfo_t &i_sectionInfo,
                      AttributeTank* io_tanks[AttributeTank::TANK_LAYER_LAST])
{
    TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides ENTER");

    errlHndl_t l_err = NULL;

    // Create local permanent override tank and array of tanks
    AttributeTank l_PermTank;
    AttributeTank* l_overTanks[AttributeTank::TANK_LAYER_LAST];

    // Local pointer to array containing each tank layer or io_tanks
    AttributeTank* *l_pOverTanks;

    // If no attribute tanks specified grab all TankLayers to create attribute
    // tanks with in enum order
    if (io_tanks == NULL)
    {
        // All indexes are -1 due to the first enum being TANK_LAYER_NONE,
        l_overTanks[AttributeTank::TANK_LAYER_FAPI-1] =
                    &fapi2::theAttrOverrideSync().iv_overrideTank;
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
        if (!SECUREBOOT::allowAttrOverrides())
        {
            TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides: "
                      "skipping since Attribute Overrides are not allowed");
            break;
        }

        TRACFCOMP( g_trac_targeting, "Section id=%d, size=%d", i_sectionInfo.id, i_sectionInfo.size );

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
                 *               chunk of pnor section
                 * @custdesc     Invalid configuration data in firmware Processor
                 *               NOR flash
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
                 * @custdesc     Invalid configuration data in firmware Processor
                 *               NOR flash
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
                 * @custdesc     Invalid configuration data in firmware Processor
                 *               NOR flash
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
                 * @custdesc     Invalid configuration data in firmware Processor
                 *               NOR flash
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
                l_ptank->deserializeAttributes(l_chunk, true);

                // The extraction of FAPI Tank Override Attributes is
                //   not supported. Note it here at ingestion so no
                //   silent fail later
                if ( l_pAttrOverSec->iv_layer ==
                        AttributeTank::TANK_LAYER_FAPI )
                {
                    TRACFCOMP(g_trac_targeting,
                              "getAttrOverrides: "
                              "FAPI Tank Layer Not Supported");
                    /*@
                     * @errortype
                     * @moduleid     TARG_GET_ATTR_OVER
                     * @reasoncode   TARG_RC_ATTR_OVER_FAPI_TANK_NOT_SUPPORTED
                     * @userdata1    Tank Layer of attribute
                     * @userdata2    PNOR Section specified
                     * @devdesc      Attribute override is in the FAPI Tank
                     *               which is not supported
                     * @custdesc     Unsupported override configuration data
                     */
                    l_err =
                        new ERRORLOG::ErrlEntry
                        (ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                         TARG_GET_ATTR_OVER,
                         TARG_RC_ATTR_OVER_FAPI_TANK_NOT_SUPPORTED,
                         l_pAttrOverSec->iv_layer,
                         i_sectionInfo.id);
                    l_err->collectTrace("TARG",256);
                    l_err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                               HWAS::SRCI_PRIORITY_HIGH);
                    ERRORLOG::errlCommit(l_err, TARG_COMP_ID);
                }



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

        // Print out the contents of all attribute tanks
        for( size_t i=0; i<AttributeTank::TANK_LAYER_LAST; i++ )
        {
            if( l_pOverTanks[i]->attributesExist() )
            {
                /* Display output like this

                 **Found 3 attribute overrides in Tank TARG(2)
                 - type:n1:p2:c3
                   ATTR 12345678 = 0011223344
                   ATTR 10102020 = 223344
                 - type:nall:pall:call
                   ATTR 02395414 = 07
                 */

                CONSOLE::displayf(CONSOLE::DEFAULT, "TARG","**Found %d attribute overrides in Tank %s(%d)",
                                  l_pOverTanks[i]->size(),
                                  AttributeTank::layerToString(
                                     static_cast<AttributeTank::TankLayer>(i)),
                                  i);

                AttributeTank::AttributeHeader last_hdr;
                std::list<AttributeTank::Attribute*> l_attrList;
                l_pOverTanks[i]->getAllAttributes(l_attrList);
                for( auto l_attr : l_attrList )
                {
                    constexpr size_t MAX_DISPLAY = 100;
                    char outstr[MAX_DISPLAY];
                    outstr[0] = '\0';

                    // Only print out the target string once if possible
                    AttributeTank::AttributeHeader hdr = l_attr->getHeader();
                    if( (hdr.iv_targetType != last_hdr.iv_targetType)
                        || (hdr.iv_node != last_hdr.iv_node)
                        || (hdr.iv_pos != last_hdr.iv_pos)
                        || (hdr.iv_unitPos != last_hdr.iv_unitPos) )
                    {
                        EntityPath epath; //func should be static but isn't
                        sprintf( outstr, "- %s",
                               epath.pathElementTypeAsString(
                               static_cast<TARGETING::TYPE>(hdr.iv_targetType)) );
                        if( AttributeTank::ATTR_NODE_NA == hdr.iv_node )
                        {
                            strcat( outstr, ":nall" );
                        }
                        else
                        {
                            char tmpstr[10]={};
                            sprintf( tmpstr, ":n%d", hdr.iv_node );
                            strcat( outstr, tmpstr );
                        }
                        if( AttributeTank::ATTR_POS_NA == hdr.iv_pos )
                        {
                            strcat( outstr, ":pall" );
                        }
                        else
                        {
                            char tmpstr[10]={};
                            sprintf( tmpstr, ":p%d", hdr.iv_pos );
                            strcat( outstr, tmpstr );
                        }
                        if( AttributeTank::ATTR_UNIT_POS_NA == hdr.iv_unitPos )
                        {
                            strcat( outstr, ":call" );
                        }
                        else
                        {
                            char tmpstr[10]={};
                            sprintf( tmpstr, ":c%d", hdr.iv_unitPos );
                            strcat( outstr, tmpstr );
                        }
                        CONSOLE::displayf(CONSOLE::DEFAULT, "TARG",outstr);
                        last_hdr = hdr;
                    }

                    // Now print out the attribute values
                    sprintf( outstr, "  ATTR %.8X [%d] = ",
                             hdr.iv_attrId,
                             hdr.iv_valSize );
                    size_t max_data = (MAX_DISPLAY - strlen(outstr))/2 - 4;
                    const char* dataval =
                      reinterpret_cast<const char*>(l_attr->getValue());
                    for( size_t s=0; s<hdr.iv_valSize && s<max_data; s++ )
                    {
                        char datastr[4]={};
                        sprintf( datastr, "%.2X", dataval[s] );
                        strcat( outstr, datastr );
                    }
                    if( hdr.iv_valSize > max_data )
                    {
                        strcat( outstr, "..." );
                    }
                    CONSOLE::displayf(CONSOLE::DEFAULT, "TARG",outstr);
                }
                CONSOLE::flush();
            }
        }
    } while(0);

    TRACFCOMP(g_trac_targeting,"attrPlatOverride::getAttrOverrides EXIT");

    return l_err;
}

} // end of namespace


