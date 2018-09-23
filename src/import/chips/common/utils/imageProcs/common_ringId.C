/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/common/utils/imageProcs/common_ringId.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2019                        */
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
#include <p9_infrastruct_help.H>


// These strings must adhere precisely to the enum of RingVariant.
const char* ringVariantName[] = { "BASE",
                                  "CC",
                                  "RL",
                                  "RL2",
                                  "RL3",
                                  "RL4",
                                  "RL5"
                                };

#ifndef __HOSTBOOT_MODULE  // This is only used by ring_apply in EKB

static int get_ipl_ring_path_param( RingVariant_t i_ringVariant, char*& o_ringPath)
{
    switch (i_ringVariant)
    {
        case RV_BASE:
            o_ringPath = getenv("IPL_BASE");
            break;

        case RV_CC:
            o_ringPath = getenv("IPL_CACHE_CONTAINED");
            break;

        case RV_RL:
            o_ringPath = getenv("IPL_RISK");
            break;

        default:
            o_ringPath = NULL;
            break;
    }

    if (o_ringPath == NULL)
    {
        MY_ERR("get_ipl_ring_path_param(): IPL env parm for ringVariant=%d not set\n",
               i_ringVariant);
        return INFRASTRUCT_RC_ENV_ERROR;
    }

    return INFRASTRUCT_RC_SUCCESS;
}

static int get_runtime_ring_path_param( RingVariant_t i_ringVariant, char*& o_ringPath)
{
    switch (i_ringVariant)
    {
        case RV_BASE:
            o_ringPath = getenv("RUNTIME_BASE");
            break;

        case RV_RL:
            o_ringPath = getenv("RUNTIME_RISK");
            break;

        case RV_RL2:
            o_ringPath = getenv("RUNTIME_RISK2");
            break;

        case RV_RL3:
            o_ringPath = getenv("RUNTIME_RISK3");
            break;

        case RV_RL4:
            o_ringPath = getenv("RUNTIME_RISK4");
            break;

        case RV_RL5:
            o_ringPath = getenv("RUNTIME_RISK5");
            break;

        default:
            o_ringPath = NULL;
            break;
    }

    if (o_ringPath == NULL)
    {
        MY_ERR("get_runtime_ring_path_param(): RUNTIME env parm for ringVariant(=%d) not set\n",
               i_ringVariant);
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
            if ( i_ringVariant == RV_BASE ||
                 i_ringVariant == RV_CC ||
                 i_ringVariant == RV_RL )
            {
                rc = get_ipl_ring_path_param(i_ringVariant, l_ringDir);
            }
            else if ( i_ringVariant == RV_RL2 ||
                      i_ringVariant == RV_RL3 ||
                      i_ringVariant == RV_RL4 ||
                      i_ringVariant == RV_RL5 )
            {
                // No IPL rings for these variants
                rc = TOR_NO_RINGS_FOR_VARIANT;
            }
            else
            {
                MY_ERR("Invalid ringVariant(=%d) for TOR magic=0x%08x\n", i_ringVariant, i_magic);
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
            if ( i_ringVariant == RV_BASE ||
                 i_ringVariant == RV_RL ||
                 i_ringVariant == RV_RL2 ||
                 i_ringVariant == RV_RL3 ||
                 i_ringVariant == RV_RL4 ||
                 i_ringVariant == RV_RL5 )
            {
                rc = get_runtime_ring_path_param(i_ringVariant, l_ringDir);
            }
            else if ( i_ringVariant == RV_CC )
            {
                // No Runtime rings for this variant
                rc = TOR_NO_RINGS_FOR_VARIANT;
            }
            else
            {
                MY_ERR("Invalid ringVariant(=%d) for TOR magic=0x%08x\n", i_ringVariant, i_magic);
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
            MY_ERR("Unsupported value of TOR magic(=0x%08x)\n", i_magic);
            rc = TOR_INVALID_MAGIC_NUMBER;
        }

    }
    while(0);

    return rc;
}

#endif // End of  ifndef __HOSTBOOT_MODULE


int ringid_get_num_ring_ids( ChipId_t   i_chipId,
                             RingId_t*  o_numRingIds )
{
    int rc = INFRASTRUCT_RC_SUCCESS;

    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            *o_numRingIds = P9_RID::NUM_RING_IDS;
            break;

        default:
            MY_ERR("ringid_get_num_ring_ids(): Unsupported chipId(=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    return rc;
}


int ringid_get_num_chiplets( ChipId_t  i_chipId,
                             uint32_t  i_torMagic,
                             uint8_t*  o_numChiplets )
{
    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            if ( i_torMagic == TOR_MAGIC_SBE  ||
                 i_torMagic == TOR_MAGIC_OVRD ||
                 i_torMagic == TOR_MAGIC_OVLY )
            {
                *o_numChiplets = P9_RID::SBE_NUM_CHIPLETS;
            }
            else if ( i_torMagic == TOR_MAGIC_CME )
            {
                *o_numChiplets = P9_RID::CME_NUM_CHIPLETS;
            }
            else if ( i_torMagic == TOR_MAGIC_SGPE )
            {
                *o_numChiplets = P9_RID::SGPE_NUM_CHIPLETS;
            }
            else
            {
                MY_ERR("ringid_get_num_chiplets(): Invalid torMagic(=0x%08x) for chipId(=CID_P9x=%d)\n", i_torMagic, i_chipId);
                return TOR_INVALID_MAGIC_NUMBER;
            }

            break;

        default:
            MY_ERR("Invalid chipId(=%d)\n", i_chipId);
            return TOR_INVALID_CHIP_ID;
    }

    return INFRASTRUCT_RC_SUCCESS;
}


int ringid_get_ringProps( ChipId_t           i_chipId,
                          RingProperties_t** o_ringProps )
{
    int rc = INFRASTRUCT_RC_SUCCESS;

    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            *o_ringProps = (RingProperties_t*)&P9_RID::RING_PROPERTIES;
            break;

        default:
            MY_ERR("ringid_get_ringProps(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    return rc;
}


int ringid_get_chipletProps( ChipId_t           i_chipId,
                             uint32_t           i_torMagic,
                             uint8_t            i_torVersion,
                             ChipletType_t      i_chipletType,
                             ChipletData_t**    o_chipletData,
                             uint8_t*           o_numVariants )
{
    int rc = INFRASTRUCT_RC_SUCCESS;

    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            if ( i_torMagic == TOR_MAGIC_SBE  ||
                 i_torMagic == TOR_MAGIC_OVRD ||
                 i_torMagic == TOR_MAGIC_OVLY )
            {
                rc = P9_RID::ringid_get_chiplet_properties(
                         i_chipletType,
                         o_chipletData);

                if (rc)
                {
                    return rc;
                }

                *o_numVariants = (*o_chipletData)->numCommonRingVariants;

                if ( i_torVersion < 7 &&
                     (i_chipletType == P9_RID::EQ_TYPE || i_chipletType == P9_RID::EC_TYPE) )
                {
                    *o_numVariants = *o_numVariants - 3;
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
                *o_numVariants        = (*o_chipletData)->numCommonRingVariants;

                if (i_torVersion < 7)
                {
                    *o_numVariants = *o_numVariants - 3;
                }
            }
            else if ( i_torMagic == TOR_MAGIC_SGPE )
            {
                *o_chipletData        = (ChipletData_t*)&P9_RID::EQ::g_chipletData;
                *o_numVariants        = (*o_chipletData)->numCommonRingVariants;

                if (i_torVersion < 7)
                {
                    *o_numVariants = *o_numVariants - 3;
                }
            }
            else
            {
                MY_ERR("Invalid torMagic(=0x%08x) for chipId=CID_P9x=%d\n", i_torMagic, i_chipId);
                return TOR_INVALID_MAGIC_NUMBER;
            }

            break;

        default:
            MY_ERR("Invalid chipId(=%d)\n", i_chipId);
            return TOR_INVALID_CHIP_ID;

    }

    return INFRASTRUCT_RC_SUCCESS;
}


int ringid_get_scanScomAddr( ChipId_t   i_chipId,
                             RingId_t   i_ringId,
                             uint32_t*  o_scanScomAddr )
{
    int rc = INFRASTRUCT_RC_SUCCESS;
    uint32_t l_scanScomAddr = UNDEFINED_SCOM_ADDR;

    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            if (i_ringId >= P9_RID::NUM_RING_IDS)
            {
                MY_ERR("ringid_get_scanScomAddr(): ringId(=0x%x) >= NUM_RING_IDS(=0x%x) not"
                       " allowed\n",
                       i_ringId, P9_RID::NUM_RING_IDS);
                rc = TOR_INVALID_RING_ID;
                break;
            }

            l_scanScomAddr = P9_RID::RING_PROPERTIES[i_ringId].scanScomAddr;
            break;

        default:
            MY_ERR("ringid_get_scanScomAddr(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    *o_scanScomAddr = l_scanScomAddr;

    return rc;
}


int ringid_get_ringClass( ChipId_t      i_chipId,
                          RingId_t      i_ringId,
                          RingClass_t*  o_ringClass )
{
    int rc = INFRASTRUCT_RC_SUCCESS;
    RingClass_t l_ringClass = UNDEFINED_RING_CLASS;

    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            if (i_ringId >= P9_RID::NUM_RING_IDS)
            {
                MY_ERR("ringid_get_ringClass(): ringId(=0x%x) >= NUM_RING_IDS(=0x%x) not allowed\n",
                       i_ringId, P9_RID::NUM_RING_IDS);
                rc = TOR_INVALID_RING_ID;
                break;
            }

            l_ringClass = P9_RID::RING_PROPERTIES[i_ringId].ringClass;
            break;

        default:
            MY_ERR("ringid_get_ringClass(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    *o_ringClass = l_ringClass;

    return rc;
}


int ringid_check_ringId( ChipId_t  i_chipId,
                         RingId_t  i_ringId )
{
    int rc = INFRASTRUCT_RC_SUCCESS;

    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            if ( i_ringId >= P9_RID::NUM_RING_IDS && i_ringId != UNDEFINED_RING_ID )
            {
                MY_ERR("ringid_check_ringId(): ringId(=0x%x) >= NUM_RING_IDS(=0x%x) not allowed\n",
                       i_ringId, P9_RID::NUM_RING_IDS);
                rc = TOR_INVALID_RING_ID;
                break;
            }

            break;

        default:
            MY_ERR("ringid_check_ringId(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    return rc;
}


int ringid_get_chipletIndex( ChipId_t        i_chipId,
                             uint32_t        i_torMagic,
                             ChipletType_t   i_chipletType,
                             ChipletType_t*  o_chipletIndex )
{
    int rc = INFRASTRUCT_RC_SUCCESS;

    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            if ( i_torMagic == TOR_MAGIC_SBE  ||
                 i_torMagic == TOR_MAGIC_OVRD ||
                 i_torMagic == TOR_MAGIC_OVLY )
            {
                if ( i_chipletType < P9_RID::SBE_NUM_CHIPLETS )
                {
                    *o_chipletIndex = i_chipletType;
                }
                else
                {
                    rc = TOR_INVALID_CHIPLET_TYPE;
                }
            }
            else if ( i_torMagic == TOR_MAGIC_CME )
            {
                if ( i_chipletType == P9_RID::EC_TYPE )
                {
                    *o_chipletIndex = 0;
                }
                else
                {
                    rc = TOR_INVALID_CHIPLET_TYPE;
                }
            }
            else if ( i_torMagic == TOR_MAGIC_SGPE )
            {
                if ( i_chipletType == P9_RID::EQ_TYPE )
                {
                    *o_chipletIndex = 0;
                }
                else
                {
                    rc = TOR_INVALID_CHIPLET_TYPE;
                }
            }
            else
            {
                MY_ERR("Invalid torMagic(=0x%08x) for chipId=CID_P9x=%d\n", i_torMagic, i_chipId);
                return TOR_INVALID_MAGIC_NUMBER;
            }

            break;

        default:
            MY_ERR("ringid_get_chipletIndex(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    return rc;
}


#if !defined(__PPE__) && !defined(NO_STD_LIB_IN_PPE) && !defined(__HOSTBOOT_MODULE) && !defined(FIPSODE)

// The following defines are needed by the initCompiler and so it's practical to use C++
// features.

// ** Important **
// If updates are made to the below three maps, corresponding updates to the two
// maps in ./tools/ifCompiler/initCompiler/initCompiler.y may also have to be made.

// Mapping from our [InfraStructure's} chipId to the chipType name
std::map <ChipId_t, std::string> chipIdIsMap
{
    { UNDEFINED_CHIP_ID, ""    },
    { (ChipId_t)CID_P9N, "p9n" },
    { (ChipId_t)CID_P9C, "p9c" },
    { (ChipId_t)CID_P9A, "p9a" }
};

// Mapping from chipType name to our [InfraStructure's} chipId (revers of above map)
std::map <std::string, ChipId_t> chipTypeIsMap
{
    { "",    UNDEFINED_CHIP_ID },
    { "p9n", (ChipId_t)CID_P9N },
    { "p9c", (ChipId_t)CID_P9C },
    { "p9a", (ChipId_t)CID_P9A }
};

// Mapping from InitCompiler's chipId to InfraStructure's chipId
std::map <uint8_t, ChipId_t> chipIdIcToIsMap
{
    { 0x0, UNDEFINED_CHIP_ID },
    { 0x5, (ChipId_t)CID_P9N },
    { 0x6, (ChipId_t)CID_P9C },
    { 0x7, (ChipId_t)CID_P9A }
};

int ringidGetRootRingId( ChipId_t    i_chipId,
                         uint32_t    i_scanScomAddr,
                         RingId_t&   o_ringId,
                         bool        i_bTest )
{
    int rc = INFRASTRUCT_RC_SUCCESS;
    RingProperties_t* ringProps = NULL;
    RingId_t          numRingIds = UNDEFINED_RING_ID;
    RingId_t          iRingId = UNDEFINED_RING_ID; // ringId loop counter
    RingId_t          l_ringId = UNDEFINED_RING_ID;
    bool              bFound = false;

    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            ringProps = (RingProperties_t*)&P9_RID::RING_PROPERTIES;
            numRingIds = P9_RID::NUM_RING_IDS;
            break;

        default:
            MY_ERR("ringidGetRootRingId(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    if (!rc)
    {
        for ( iRingId = 0; iRingId < numRingIds; iRingId++ )
        {
            if ( ringProps[iRingId].scanScomAddr == i_scanScomAddr )
            {
                if ( ringProps[iRingId].ringClass & RCLS_ROOT_RING )
                {
                    if (bFound)
                    {
                        MY_ERR("ringidGetRootRingId(): Two rings w/same addr cannot both be"
                               " ROOT_RING.  Fix RING_PROPERTIES list for chipId=%d at ringId=0x%x"
                               " and ringId=0x%x\n",
                               i_chipId, l_ringId, iRingId);
                        rc = INFRASTRUCT_RC_CODE_BUG;
                        l_ringId = UNDEFINED_RING_ID;
                        break;
                    }
                    else
                    {
                        l_ringId = iRingId;
                        bFound = true;

                        if (!i_bTest)
                        {
                            // Stop testing and break out of ringId loop
                            break;
                        }

                        // Continue testing to see if duplicate root rings found
                    }
                }
            }
        }
    }

    if (!rc && !bFound)
    {
        MY_DBG("ringidGetRootRingId(): Did not find match for scanScomAddr=0x%08x for chipId=%d."
               " (Note, l_ringId=0x%x better be equal to UNDEFINED_RING_ID=0x%x)\n",
               i_scanScomAddr, i_chipId, l_ringId, UNDEFINED_RING_ID);
        rc = TOR_SCOM_ADDR_NOT_FOUND;
    }

    o_ringId = l_ringId;

    return rc;
}


int ringidGetRingId1( ChipId_t     i_chipId,
                      std::string  i_ringName,
                      RingId_t&    o_ringId,
                      bool         i_bTest )
{
    int rc = INFRASTRUCT_RC_SUCCESS;
    RingProperties_t* ringProps = NULL;
    RingId_t          numRingIds = UNDEFINED_RING_ID;
    RingId_t          iRingId = UNDEFINED_RING_ID; // ringId loop counter
    RingId_t          l_ringId = UNDEFINED_RING_ID;
    bool              bFound = false;

    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            ringProps = (RingProperties_t*)&P9_RID::RING_PROPERTIES;
            numRingIds = P9_RID::NUM_RING_IDS;
            break;

        default:
            MY_ERR("ringidGetRingId1(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    if (!rc)
    {
        for ( iRingId = 0; iRingId < numRingIds; iRingId++ )
        {
            if ( !(i_ringName.compare(ringProps[iRingId].ringName)) )
            {
                if (bFound)
                {
                    MY_ERR("ringidGetRingId1(): Two rings cannot have the same ringName=%s.  Fix"
                           " RING_PROPERTIES list for chipId=%d at ringId=0x%x and ringId=0x%x\n",
                           i_ringName.c_str(), i_chipId, l_ringId, iRingId);
                    rc = INFRASTRUCT_RC_CODE_BUG;
                    l_ringId = UNDEFINED_RING_ID;
                    break;
                }
                else
                {
                    l_ringId = iRingId;
                    bFound = true;

                    if (!i_bTest)
                    {
                        // Stop testing and break our of ringId loop
                        break;
                    }

                    // Continue testing to see if duplicate ringNames found
                }
            }
        }
    }

    if (!rc && !bFound)
    {
        MY_DBG("ringidGetRingId1(): Did not find match to ringName=%s for chipId=%d."
               " (Note, l_ringId=0x%x better be equal to UNDEFINED_RING_ID=0x%x)\n",
               i_ringName.c_str(), i_chipId, l_ringId, UNDEFINED_RING_ID);
        rc = TOR_RING_NAME_NOT_FOUND;
    }

    o_ringId = l_ringId;

    return rc;
}


int ringidGetRingId2( ChipId_t       i_chipId,
                      uint32_t       i_torMagic,
                      ChipletType_t  i_chipletType, // Ignored if only one chiplet in torMagic
                      uint8_t        i_idxRing,     // The effective ring index within chiplet's
                      // common or instance ring section
                      MyBool_t       i_bInstCase,
                      RingId_t&      o_ringId,
                      bool           i_bTest )
{
    int rc = INFRASTRUCT_RC_SUCCESS;
    ChipletType_t     l_chipletType = UNDEFINED_CHIPLET_TYPE;
    RingProperties_t* ringProps = NULL;
    RingId_t          numRingIds = UNDEFINED_RING_ID;
    RingId_t          iRingId = UNDEFINED_RING_ID; // ringId loop counter
    RingId_t          l_ringId = UNDEFINED_RING_ID;
    uint8_t           l_idxRing = INVALID_RING_OFFSET;
    bool              bFound = false;
    bool              bOverlap = false;

    // First, select the main ring list we need. And while we're at it,
    // convert input chipletType, which can be ignored for ring sections (i.e. torMagic)
    // with only one chiplet, to a valid chipletType
    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            ringProps = (RingProperties_t*)&P9_RID::RING_PROPERTIES;
            numRingIds = P9_RID::NUM_RING_IDS;

            if ( i_torMagic == TOR_MAGIC_SBE  ||
                 i_torMagic == TOR_MAGIC_OVRD ||
                 i_torMagic == TOR_MAGIC_OVLY )
            {
                l_chipletType = i_chipletType;
            }
            else if ( i_torMagic == TOR_MAGIC_CME )
            {
                l_chipletType = P9_RID::EC_TYPE;
            }
            else if ( i_torMagic == TOR_MAGIC_SGPE )
            {
                l_chipletType = P9_RID::EQ_TYPE;
            }
            else
            {
                MY_ERR("Invalid torMagic(=0x%08x) for chipId=CID_P9x=%d\n", i_torMagic, i_chipId);
                return TOR_INVALID_MAGIC_NUMBER;
            }

            break;

        default:
            MY_ERR("ringidGetRingId2(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    // Second, convert effective input ring index (which has no instance marker) to the
    // common/instance specific index
    l_idxRing = i_bInstCase ?
                i_idxRing | INSTANCE_RING_MARK :
                i_idxRing;

    if (!rc)
    {
        for ( iRingId = 0; iRingId < numRingIds; iRingId++ )
        {
            if ( ringProps[iRingId].chipletType == l_chipletType &&
                 ringProps[iRingId].idxRing == l_idxRing )
            {
                if (bFound)
                {
                    // Allow ring index overlap between a root and a non-root ring
                    // and let the non-root (i.e., the bucket ring) "win"
                    if ( !bOverlap &&
                         ( (ringProps[iRingId].ringClass & RCLS_ROOT_RING) !=
                           (ringProps[l_ringId].ringClass & RCLS_ROOT_RING) ) )
                    {
                        if ( (ringProps[iRingId].ringClass & RCLS_ROOT_RING) != RCLS_ROOT_RING )
                        {
                            l_ringId = iRingId;
                        }
                        else
                        {
                            // Keep l_ringId as is since it must already be the non-root ring
                        }

                        bOverlap = true; // Indicate we found an overlap match

                        if (!i_bTest)
                        {
                            // Stop testing and break our of ringId loop
                            break;
                        }
                    }
                    else
                    {
                        MY_ERR("ringidGetRingId2(): Two root, or two non-root, rings within a"
                               " chiplet (chipletType=%d) cannot have the same ring index"
                               " (idxRing=%d, bInst=%d). Fix RING_PROPERTIES list for chipId=%d"
                               " at ringId=0x%x and ringId=0x%x\n",
                               l_chipletType, i_idxRing, i_bInstCase, i_chipId, l_ringId, iRingId);
                        rc = INFRASTRUCT_RC_CODE_BUG;
                        l_ringId = UNDEFINED_RING_ID;
                        break;
                    }
                }
                else
                {
                    l_ringId = iRingId;
                    bFound = true; // Indicate we found a first match

                    // Continue searching for ring index overlap due to bucket ring or code bug
                }
            }
        }
    }

    if (!rc && !bFound)
    {
        MY_ERR("ringidGetRingId2(): Could not find a match for (chipId,chipletType,idxRing,bInst) ="
               " (%d, %d, %d, %d).  Fix RING_PROPERTIES list for chipId=%d (Note, l_ringId=0x%x"
               " better be equal to UNDEFINED_RING_ID=0x%x)\n",
               i_chipId, l_chipletType, i_idxRing, i_bInstCase,
               i_chipId, l_ringId, UNDEFINED_RING_ID);
        rc = INFRASTRUCT_RC_CODE_BUG;
    }

    o_ringId = l_ringId;

    return rc;
}


int ringidGetRingName( ChipId_t     i_chipId,
                       RingId_t     i_ringId,
                       std::string& o_ringName )
{
    int rc = INFRASTRUCT_RC_SUCCESS;
    std::string l_ringName;

    switch (i_chipId)
    {
        case CID_P9N:
        case CID_P9C:
        case CID_P9A:
            if (i_ringId >= P9_RID::NUM_RING_IDS)
            {
                MY_ERR("ringidGetRingName(): ringId(=0x%x) >= NUM_RING_IDS(=0x%x) not allowed\n",
                       i_ringId, P9_RID::NUM_RING_IDS);
                rc = TOR_INVALID_RING_ID;
                break;
            }

            l_ringName = (std::string)P9_RID::RING_PROPERTIES[i_ringId].ringName;
            break;

        default:
            MY_ERR("ringidGetRingName(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    o_ringName = l_ringName;

    return rc;
}

int ringidGetRingClass( ChipId_t      i_chipId,
                        RingId_t      i_ringId,
                        RingClass_t&  o_ringClass )
{
    return (ringid_get_ringClass(i_chipId, i_ringId, &o_ringClass));
}

#endif // __PPE__ && NO_STD_LIB_IN_PPE
