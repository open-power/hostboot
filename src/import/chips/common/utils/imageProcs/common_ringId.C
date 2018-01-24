/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/common/utils/imageProcs/common_ringId.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
                                  "RL2",
                                };

#ifndef __HOSTBOOT_MODULE  // This is only used by ring_apply in EKB

static int get_ipl_base_param( char*& l_ringPath )
{
    l_ringPath = getenv("IPL_BASE");

    if (l_ringPath == NULL)
    {
        MY_ERR("p9_ring_apply.C: ring path: IPL_BASE environment parameter not set.\n");
        return INFRASTRUCT_RC_ENV_ERROR;
    }

    return INFRASTRUCT_RC_SUCCESS;
}

static int get_ipl_cache_contained_param( char*& l_ringPath)
{
    l_ringPath = getenv("IPL_CACHE_CONTAINED");

    if (l_ringPath == NULL)
    {
        MY_ERR("p9_ring_apply.C: ring path: IPL_CACHE_CONTAINED environment parameter not set.\n");
        return INFRASTRUCT_RC_ENV_ERROR;
    }

    return INFRASTRUCT_RC_SUCCESS;
}

static int get_ipl_risk_param( char*& l_ringPath)
{
    l_ringPath = getenv("IPL_RISK");

    if (l_ringPath == NULL)
    {
        MY_ERR("p9_ring_apply.C: ring path: IPL_RISK environment parameter not set.\n");
        return INFRASTRUCT_RC_ENV_ERROR;
    }

    return INFRASTRUCT_RC_SUCCESS;
}

static int get_runtime_base_param( char*& l_ringPath)
{
    l_ringPath = getenv("RUNTIME_BASE");

    if (l_ringPath == NULL)
    {
        MY_ERR("p9_ring_apply.C: ring path: RUNTIME_BASE environment parameter not set.\n");
        return INFRASTRUCT_RC_ENV_ERROR;
    }

    return INFRASTRUCT_RC_SUCCESS;
}
static int get_runtime_risk_param( char*& l_ringPath)
{
    l_ringPath = getenv("RUNTIME_RISK");

    if (l_ringPath == NULL)
    {
        MY_ERR("p9_ring_apply.C: ring path: RUNTIME_RISK environment parameter not set.\n");
        return INFRASTRUCT_RC_ENV_ERROR;
    }

    return INFRASTRUCT_RC_SUCCESS;
}

static int get_runtime_risk2_param( char*& l_ringPath)
{
    l_ringPath = getenv("RUNTIME_RISK2");

    if (l_ringPath == NULL)
    {
        MY_ERR("p9_ring_apply.C: ring path: RUNTIME_RISK2 environment parameter not set.\n");
        return INFRASTRUCT_RC_ENV_ERROR;
    }

    return INFRASTRUCT_RC_SUCCESS;
}

int ringid_get_raw_ring_file_path( uint32_t        i_magic,
                                   RingVariant_t   i_ringVariant,
                                   char*           io_ringPath )
{
    int   rc = INFRASTRUCT_RC_SUCCESS;
    char* l_ringDir = NULL;

    do
    {

        if ( i_magic == TOR_MAGIC_SBE )
        {
            if ( i_ringVariant == RV_BASE )
            {
                rc = get_ipl_base_param(l_ringDir);
            }
            else if ( i_ringVariant == RV_CC )
            {
                rc = get_ipl_cache_contained_param(l_ringDir);
            }
            else if ( i_ringVariant == RV_RL )
            {
                rc = get_ipl_risk_param(l_ringDir);
            }
            else if ( i_ringVariant == RV_RL2 )
            {
                // Valid RV for Quad chiplets but there's just no RL2 rings for SBE phase (by convention).
                rc = TOR_NO_RINGS_FOR_VARIANT;
                break;
            }
            else
            {
                MY_ERR("Invalid ringVariant(=%d) for TOR magic=0x%08x\n",
                       i_ringVariant, i_magic);
                rc = TOR_INVALID_VARIANT;
            }

            if (rc)
            {
                break;
            }

            strcat(io_ringPath, l_ringDir);
            strcat(io_ringPath, "/");
        }
        else if ( i_magic == TOR_MAGIC_CME ||
                  i_magic == TOR_MAGIC_SGPE )
        {
            if ( i_ringVariant == RV_BASE )
            {
                rc = get_runtime_base_param(l_ringDir);
            }
            else if ( i_ringVariant == RV_CC )
            {
                // Valid RV for Quad chiplets but there's just no CC rings for runtime phases (by convention).
                rc = TOR_NO_RINGS_FOR_VARIANT;
                break;
            }
            else if ( i_ringVariant == RV_RL )
            {
                rc = get_runtime_risk_param(l_ringDir);
            }
            else if ( i_ringVariant == RV_RL2 )
            {
                rc = get_runtime_risk2_param(l_ringDir);
            }
            else
            {
                MY_ERR("Invalid ringVariant(=%d) for TOR magic=0x%08x\n",
                       i_ringVariant, i_magic);
                rc = TOR_INVALID_VARIANT;
            }

            if (rc)
            {
                break;
            }

            strcat(io_ringPath, l_ringDir);
            strcat(io_ringPath, "/");
        }
        else if ( i_magic == TOR_MAGIC_CEN )
        {
            if ( i_ringVariant == RV_BASE )
            {
                rc = get_ipl_base_param(l_ringDir);
            }
            else if ( i_ringVariant == RV_RL )
            {
                rc = get_ipl_risk_param(l_ringDir);
            }
            else
            {
                MY_ERR("Invalid ringVariant(=%d) for TOR magic=0x%08x\n",
                       i_ringVariant, i_magic);
                rc = TOR_INVALID_VARIANT;
            }

            if (rc)
            {
                break;
            }

            strcat(io_ringPath, l_ringDir);
            strcat(io_ringPath, "/");
        }
        else if ( i_magic == TOR_MAGIC_OVRD ||
                  i_magic == TOR_MAGIC_OVLY )
        {
            // Path already fully qualified. Return io_ringPath as is.
        }
        else
        {
            MY_ERR("Unsupported value of TOR magic(=0x%X)\n", i_magic);
            rc = TOR_INVALID_MAGIC_NUMBER;
        }

    }
    while(0);

    return rc;
}

#endif // End of  ifndef __HOSTBOOT_MODULE

int ringid_get_noof_chiplets( ChipType_t  i_chipType,
                              uint32_t    i_torMagic,
                              uint8_t*    o_numChiplets )
{
    switch (i_chipType)
    {
        case CT_P9N:
        case CT_P9C:
        case CT_P9A:
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
                            uint8_t            i_torVersion,
                            ChipletType_t      i_chipletType,
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
        case CT_P9A:
            if ( i_torMagic == TOR_MAGIC_SBE  ||
                 i_torMagic == TOR_MAGIC_OVRD ||
                 i_torMagic == TOR_MAGIC_OVLY )
            {
                P9_RID::ringid_get_chiplet_properties(
                    i_chipletType,
                    o_chipletData,
                    o_ringIdListCommon,
                    o_ringIdListInstance,
                    o_ringVariantOrder,
                    o_numVariants );

                if ( i_torVersion < 6 &&
                     (i_chipletType == P9_RID::EQ_TYPE || i_chipletType == P9_RID::EC_TYPE) )
                {
                    *o_numVariants = *o_numVariants - 1;
                }

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

                if (i_torVersion < 6)
                {
                    *o_numVariants = *o_numVariants - 1;
                }
            }
            else if ( i_torMagic == TOR_MAGIC_SGPE )
            {
                *o_chipletData        = (ChipletData_t*)&P9_RID::EQ::g_chipletData;
                *o_ringIdListCommon   = (GenRingIdList*)P9_RID::EQ::RING_ID_LIST_COMMON;
                *o_ringIdListInstance = (GenRingIdList*)P9_RID::EQ::RING_ID_LIST_INSTANCE;
                *o_ringVariantOrder   = (RingVariantOrder*)P9_RID::EQ::RING_VARIANT_ORDER;
                *o_numVariants        = P9_RID::EQ::g_chipletData.iv_num_ring_variants;

                if (i_torVersion < 6)
                {
                    *o_numVariants = *o_numVariants - 1;
                }
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
                    i_chipletType,
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
