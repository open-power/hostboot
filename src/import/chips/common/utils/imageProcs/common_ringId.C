/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/common/utils/imageProcs/common_ringId.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include <common_ringId.H>

namespace P9_RID
{
#include <p9_ringId.H>
};
namespace CEN_RID
{
#include <cen_ringId.H>
};
#include <p9_infrastruct_help.H>

// These strings must adhere precisely to the enum of ppeType.
const char* ppeTypeName[] = { "SBE",
                              "CME",
                              "SGPE"
                            };

// These strings must adhere precisely to the enum of RingVariant.
const char* ringVariantName[] = { "BASE",
                                  "CC",
                                  "RL",
                                  "OVRD",
                                  "OVLY"
                                };



int ringid_get_noof_chiplets( ChipType_t  i_chipType,
                              uint32_t    i_torMagic,
                              uint8_t*    o_numChiplets )
{
    switch (i_chipType)
    {
        case CT_P9N:
        case CT_P9C:
            if ( i_torMagic == TOR_MAGIC_SBE  ||
                 i_torMagic == TOR_MAGIC_OVRD ||
                 i_torMagic == TOR_MAGIC_OVLY )
            {
                *o_numChiplets = P9_RID::SBE_NOOF_CHIPLETS;
            }
            else if ( i_torMagic == TOR_MAGIC_CME )
            {
                *o_numChiplets = P9_RID::CME_NOOF_CHIPLETS;
            }
            else if ( i_torMagic == TOR_MAGIC_SGPE )
            {
                *o_numChiplets = P9_RID::SGPE_NOOF_CHIPLETS;
            }
            else
            {
                MY_ERR("Invalid torMagic (=0x%08x) for chipType (=CT_P9x=%d)\n", i_torMagic, i_chipType);
                return TOR_INVALID_MAGIC_NUMBER;
            }

            break;

        case CT_CEN:
            if ( i_torMagic == TOR_MAGIC_CEN ||
                 i_torMagic == TOR_MAGIC_OVRD )
            {
                *o_numChiplets = CEN_RID::CEN_NOOF_CHIPLETS;
            }
            else
            {
                MY_ERR("Invalid torMagic (=0x%08x) for chipType (=CT_CEN)\n", i_torMagic);
                return TOR_INVALID_MAGIC_NUMBER;
            }

            break;

        default:
            MY_ERR("Invalid chipType (=0x%02x)\n", i_chipType);
            return TOR_INVALID_CHIPTYPE;
    }

    return TOR_SUCCESS;
}


int  ringid_get_properties( ChipType_t         i_chipType,
                            uint32_t           i_torMagic,
                            ChipletType_t      i_chiplet,
                            ChipletData_t**    o_chipletData,
                            GenRingIdList**    o_ringIdListCommon,
                            GenRingIdList**    o_ringIdListInstance,
                            RingVariantOrder** o_ringVariantOrder,
                            RingProperties_t** o_ringProps,
                            uint8_t*           o_numVariants )
{
    switch (i_chipType)
    {
        case CT_P9N:
        case CT_P9C:
            if ( i_torMagic == TOR_MAGIC_SBE  ||
                 i_torMagic == TOR_MAGIC_OVRD ||
                 i_torMagic == TOR_MAGIC_OVLY )
            {
                P9_RID::ringid_get_chiplet_properties(
                    i_chiplet,
                    o_chipletData,
                    o_ringIdListCommon,
                    o_ringIdListInstance,
                    o_ringVariantOrder,
                    o_numVariants );

                if ( i_torMagic == TOR_MAGIC_OVRD ||
                     i_torMagic == TOR_MAGIC_OVLY )
                {
                    *o_numVariants = 1;
                }
            }
            else if ( i_torMagic == TOR_MAGIC_CME )
            {
                *o_chipletData        = (ChipletData_t*)&P9_RID::EC::g_chipletData;
                *o_ringIdListCommon   = (GenRingIdList*)P9_RID::EC::RING_ID_LIST_COMMON;
                *o_ringIdListInstance = (GenRingIdList*)P9_RID::EC::RING_ID_LIST_INSTANCE;
                *o_ringVariantOrder   = (RingVariantOrder*)P9_RID::EC::RING_VARIANT_ORDER;
                *o_numVariants        = P9_RID::EC::g_chipletData.iv_num_ring_variants;
            }
            else if ( i_torMagic == TOR_MAGIC_SGPE )
            {
                *o_chipletData        = (ChipletData_t*)&P9_RID::EQ::g_chipletData;
                *o_ringIdListCommon   = (GenRingIdList*)P9_RID::EQ::RING_ID_LIST_COMMON;
                *o_ringIdListInstance = (GenRingIdList*)P9_RID::EQ::RING_ID_LIST_INSTANCE;
                *o_ringVariantOrder   = (RingVariantOrder*)P9_RID::EQ::RING_VARIANT_ORDER;
                *o_numVariants        = P9_RID::EQ::g_chipletData.iv_num_ring_variants;
            }
            else
            {
                MY_ERR("Invalid torMagic (=0x%08x) for chipType=CT_P9x=%d\n", i_torMagic, i_chipType);
                return TOR_INVALID_MAGIC_NUMBER;
            }

            *o_ringProps = (RingProperties_t*)P9_RID::RING_PROPERTIES;

            break;

        case CT_CEN:
            if ( i_torMagic == TOR_MAGIC_CEN ||
                 i_torMagic == TOR_MAGIC_OVRD )
            {
                CEN_RID::ringid_get_chiplet_properties(
                    i_chiplet,
                    o_chipletData,
                    o_ringIdListCommon,
                    o_ringIdListInstance,
                    o_ringVariantOrder,
                    o_numVariants );

                if ( i_torMagic == TOR_MAGIC_OVRD)
                {
                    *o_numVariants = 1;
                }
            }
            else
            {
                MY_ERR("Invalid torMagic (=0x%08x) for chipType=CT_CEN\n", i_torMagic);
                return TOR_INVALID_MAGIC_NUMBER;
            }

            *o_ringProps = (RingProperties_t*)CEN_RID::RING_PROPERTIES;

            break;

        default:
            MY_ERR("Invalid chipType (=0x%02x)\n", i_chipType);
            return TOR_INVALID_CHIPTYPE;

    }

    return TOR_SUCCESS;
}
