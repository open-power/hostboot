/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/common/utils/imageProcs/common_ringId.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2022                        */
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

namespace P10_RID
{
#include <p10_ringId.H>
};
#include <p10_infrastruct_help.H>


int ringid_get_num_ring_ids( ChipId_t   i_chipId,
                             RingId_t*  o_numRingIds )
{
    int rc = INFRASTRUCT_RC_SUCCESS;

    switch (i_chipId)
    {
        case CID_P10:
            *o_numRingIds = P10_RID::NUM_RING_IDS;
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
        case CID_P10:
            if ( i_torMagic == TOR_MAGIC_SBE  ||
                 i_torMagic == TOR_MAGIC_OVRD ||
                 i_torMagic == TOR_MAGIC_OVLY ||
                 i_torMagic == TOR_MAGIC_DYN )
            {
                *o_numChiplets = P10_RID::SBE_NUM_CHIPLETS;
            }
            else if ( i_torMagic == TOR_MAGIC_QME )
            {
                *o_numChiplets = P10_RID::QME_NUM_CHIPLETS;
            }
            else
            {
                MY_ERR("ringid_get_num_chiplets(): Invalid torMagic(=0x%08x) for chipId(=CID_P10x=%d)\n", i_torMagic, i_chipId);
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

    *o_ringProps = NULL;

    switch (i_chipId)
    {
        case CID_P10:
            *o_ringProps = (RingProperties_t*)&P10_RID::RING_PROPERTIES;
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
                             ChipletData_t**    o_chipletData )
{
    int rc = INFRASTRUCT_RC_SUCCESS;

    switch (i_chipId)
    {
        case CID_P10:
            if ( i_torMagic == TOR_MAGIC_SBE  ||
                 i_torMagic == TOR_MAGIC_OVRD ||
                 i_torMagic == TOR_MAGIC_OVLY ||
                 i_torMagic == TOR_MAGIC_DYN )
            {
                rc = P10_RID::ringid_get_chiplet_properties(
                         i_chipletType,
                         o_chipletData);

                if (rc)
                {
                    return rc;
                }
            }
            else if ( i_torMagic == TOR_MAGIC_QME )
            {
                *o_chipletData        = (ChipletData_t*)&P10_RID::EQ::g_chipletData;
            }
            else
            {
                MY_ERR("Invalid torMagic(=0x%08x) for chipId=CID_P10x=%d\n", i_torMagic, i_chipId);
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

    // Get the ring properties (rp) index
    RingId_t rpIndex = P10_RID::ringid_convert_ringId_to_rpIndex(i_ringId);

    switch (i_chipId)
    {
        case CID_P10:
            if (rpIndex >= P10_RID::NUM_RING_IDS)
            {
                MY_ERR("ringid_get_scanScomAddr(): rpIndex(=0x%x) >= NUM_RING_IDS(=0x%x) not"
                       " allowed and ringId=0x%x\n",
                       rpIndex, P10_RID::NUM_RING_IDS, i_ringId);
                rc = TOR_INVALID_RING_ID;
                break;
            }

            l_scanScomAddr = P10_RID::RING_PROPERTIES[rpIndex].scanScomAddr;
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

    // Get the ring properties (rp) index
    RingId_t rpIndex = P10_RID::ringid_convert_ringId_to_rpIndex(i_ringId);

    switch (i_chipId)
    {
        case CID_P10:
            if (rpIndex >= P10_RID::NUM_RING_IDS)
            {
                MY_ERR("ringid_get_ringClass(): rpIndex(=0x%x) >= NUM_RING_IDS(=0x%x) not"
                       " allowed and ringId=0x%x\n",
                       rpIndex, P10_RID::NUM_RING_IDS, i_ringId);
                rc = TOR_INVALID_RING_ID;
                break;
            }

            l_ringClass = P10_RID::RING_PROPERTIES[rpIndex].ringClass;
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
    if ( i_ringId == HOLE_RING_ID )
    {
        // A hole ring is usually benign. No tracing. Let caller decide.
        return TOR_HOLE_RING_ID;
    }

    // Get the ring properties (rp) index
    RingId_t rpIndex = P10_RID::ringid_convert_ringId_to_rpIndex(i_ringId);

    switch (i_chipId)
    {
        case CID_P10:
            if ( rpIndex >= P10_RID::NUM_RING_IDS )
            {
                // Not necessarily an error. No tracing. Let caller decide.
                return TOR_INVALID_RING_ID;
            }

            break;

        default:
            MY_ERR("ERROR: ringid_check_ringId: Unsupported chipId(=0x%x) supplied\n",
                   i_chipId);
            return TOR_INVALID_CHIP_ID;
    }

    return TOR_SUCCESS;
}


int ringid_get_chipletIndex( ChipId_t        i_chipId,
                             uint32_t        i_torMagic,
                             ChipletType_t   i_chipletType,
                             ChipletType_t*  o_chipletIndex )
{
    int rc = INFRASTRUCT_RC_SUCCESS;

    switch (i_chipId)
    {
        case CID_P10:
            if ( i_torMagic == TOR_MAGIC_SBE  ||
                 i_torMagic == TOR_MAGIC_OVRD ||
                 i_torMagic == TOR_MAGIC_OVLY ||
                 i_torMagic == TOR_MAGIC_DYN )
            {
                if ( i_chipletType < P10_RID::SBE_NUM_CHIPLETS )
                {
                    *o_chipletIndex = i_chipletType;
                }
                else
                {
                    rc = TOR_INVALID_CHIPLET_TYPE;
                }
            }
            else if ( i_torMagic == TOR_MAGIC_QME )
            {
                if ( i_chipletType == P10_RID::EQ_TYPE )
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
                MY_ERR("Invalid torMagic(=0x%08x) for chipId=CID_P10x=%d\n", i_torMagic, i_chipId);
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


MyBool_t ringid_is_mvpd_ring( ChipId_t  i_chipId,
                              RingId_t  i_ringId )
{
    RingId_t rpIndex = UNDEFINED_RING_ID;

    switch (i_chipId)
    {
        case CID_P10:

            // Catch hole rings
            if (i_ringId == HOLE_RING_ID)
            {
                return false;
            }

            // Get the ring properties (rp) index
            rpIndex = P10_RID::ringid_convert_ringId_to_rpIndex(i_ringId);

            if (rpIndex >= P10_RID::NUM_RING_IDS)
            {
                MY_ERR("ringid_is_mvpd_ring(): rpIndex(=0x%x) >= NUM_RING_IDS(=0x%x) not"
                       " allowed and ringId=0x%x\n",
                       rpIndex, P10_RID::NUM_RING_IDS, i_ringId);
                return UNDEFINED_BOOLEAN;
            }

            if ( P10_RID::RING_PROPERTIES[rpIndex].ringClass & RCLS_MVPD_MASK )
            {
                return true;
            }
            else
            {
                return false;
            }

            break;

        default:
            MY_ERR("ringid_is_mvpd_ring(): Unsupported chipId (=%d) supplied\n", i_chipId);
            return UNDEFINED_BOOLEAN;
    }

    return UNDEFINED_BOOLEAN;
}

/*
MyBool_t ringid_is_gptr_ring( ChipId_t  i_chipId,
                              RingId_t  i_ringId )
{
    RingId_t rpIndex = UNDEFINED_RING_ID;

    switch (i_chipId)
    {
        case CID_P10:
            // Catch hole rings
            if (i_ringId == HOLE_RING_ID)
            {
                return false;
            }

            // Get the ring properties (rp) index
            rpIndex = P10_RID::ringid_convert_ringId_to_rpIndex(i_ringId);

            if (rpIndex >= P10_RID::NUM_RING_IDS)
            {
                MY_ERR("ringid_is_gptr_ring(): rpIndex(=0x%x) >= NUM_RING_IDS(=0x%x) not"
                       " allowed and ringId=0x%x\n",
                       rpIndex, P10_RID::NUM_RING_IDS, i_ringId);
                return UNDEFINED_BOOLEAN;
            }

            if ( P10_RID::RING_PROPERTIES[rpIndex].ringClass & RMRK_GPTR_OVLY )
            {
                return true;
            }
            else
            {
                return false;
            }

            break;

        default:
            MY_ERR("ringid_is_gptr_ring(): Unsupported chipId (=%d) supplied\n", i_chipId);
            return UNDEFINED_BOOLEAN;
    }

    return UNDEFINED_BOOLEAN;
}
*/


MyBool_t ringid_is_instance_ring( RingId_t  i_rpIndex)
{
    if (i_rpIndex >= P10_RID::NUM_RING_IDS)
    {
        MY_ERR("ringid_is_instance_ring(): rpIndex(=0x%x) >= NUM_RING_IDS(=0x%x) not allowed\n",
               i_rpIndex, P10_RID::NUM_RING_IDS);
        return UNDEFINED_BOOLEAN;
    }

    if ( P10_RID::RING_PROPERTIES[i_rpIndex].idxRing == UNDEFINED_RING_INDEX )
    {
        return UNDEFINED_BOOLEAN;
    }

    if ( P10_RID::RING_PROPERTIES[i_rpIndex].idxRing & INSTANCE_RING_MARK )
    {
        return true;
    }
    else
    {
        return false;
    }

    return UNDEFINED_BOOLEAN;
}


MyBool_t ringid_has_derivs( ChipId_t  i_chipId,
                            RingId_t  i_ringId )
{
    // Get the ring properties (rp) index
    RingId_t rpIndex = P10_RID::ringid_convert_ringId_to_rpIndex(i_ringId);

    switch (i_chipId)
    {
        case CID_P10:
            if (rpIndex >= P10_RID::NUM_RING_IDS)
            {
                MY_ERR("ringid_has_derivs(): rpIndex(=0x%x) >= NUM_RING_IDS(=0x%x) not"
                       " allowed and ringId=0x%x\n",
                       rpIndex, P10_RID::NUM_RING_IDS, i_ringId);
                return UNDEFINED_BOOLEAN;
            }

            if ( P10_RID::RING_PROPERTIES[rpIndex].ringClass & RMRK_HAS_DERIVS )
            {
                return true;
            }
            else
            {
                return false;
            }

            break;

        default:
            MY_ERR("ringid_has_derivs(): Unsupported chipId (=%d) supplied\n", i_chipId);
            return UNDEFINED_BOOLEAN;
    }

    return UNDEFINED_BOOLEAN;
}


uint8_t ringid_get_ring_table_version_ekb( void)
{
    return P10_RID::RING_TABLE_VERSION_EKB;
}


uint8_t ringid_get_ring_table_version_mvpd( void)
{
    return P10_RID::RING_TABLE_VERSION_MVPD;
}


uint8_t ringid_get_ring_table_version_hwimg( void)
{
    return P10_RID::RING_TABLE_VERSION_EKB >= P10_RID::RING_TABLE_VERSION_MVPD ?
           P10_RID::RING_TABLE_VERSION_EKB :
           P10_RID::RING_TABLE_VERSION_MVPD;
}


#if !defined(__PPE__) && !defined(NO_STD_LIB_IN_PPE) && !defined(WIN32)

int ringidGetRootRingId( ChipId_t    i_chipId,
                         uint32_t    i_scanScomAddr,
                         RingId_t&   o_ringId,
                         bool        i_bTest )
{
    int rc = INFRASTRUCT_RC_SUCCESS;
    RingProperties_t* ringProps = NULL;
    RingId_t          numRingIds = UNDEFINED_RING_ID;
    RingId_t          iRpIndex = UNDEFINED_RING_ID; // Ring properties index counter
    RingId_t          rpIndexTmp = UNDEFINED_RING_ID; // Temporary RP index for bFound=true
    RingId_t          l_ringId = UNDEFINED_RING_ID; // Local ringId, eventual output ringId
    bool              bFound = false;

    switch (i_chipId)
    {
        case CID_P10:
            ringProps = (RingProperties_t*)&P10_RID::RING_PROPERTIES;
            numRingIds = P10_RID::NUM_RING_IDS;
            break;

        case CID_EXPLORER:
            // No ring support
            rc = TOR_NO_RINGS_FOR_CHIP;
            break;

        case CID_ODYSSEY:
            //FIXME?
            // No ring support
            rc = TOR_NO_RINGS_FOR_CHIP;
            break;

        default:
            MY_ERR("ringidGetRootRingId(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    if (!rc)
    {
        for ( iRpIndex = 0; iRpIndex < numRingIds; iRpIndex++ )
        {
            if ( ringProps[iRpIndex].scanScomAddr == i_scanScomAddr )
            {
                if ( ringProps[iRpIndex].ringClass & RMRK_ROOT &&
                     !( ringProps[iRpIndex].ringClass & RMRK_MVPD_PDS ) )
                {
                    if (bFound)
                    {
                        MY_ERR("ringidGetRootRingId(): Two rings w/same addr cannot both be"
                               " ROOT_RING.  Fix RING_PROPERTIES list for chipId=%d at"
                               " ringId=0x%x and ringId=0x%x\n",
                               i_chipId, rpIndexTmp, iRpIndex);
                        l_ringId = UNDEFINED_RING_ID;
                        rc = INFRASTRUCT_RC_CODE_BUG;
                        break;
                    }
                    else
                    {
                        rpIndexTmp = iRpIndex;
                        l_ringId = ringProps[iRpIndex].ringId;
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

    if ( !rc && !bFound )
    {
        // This is not a bug, but do tell caller that scanScomAddr wasn't found.
        rc = TOR_SCOM_ADDR_NOT_FOUND;
    }

    o_ringId = l_ringId;

    return rc;
}


int ringidGetRingClass( ChipId_t      i_chipId,
                        RingId_t      i_ringId,
                        RingClass_t&  o_ringClass )
{
    return (ringid_get_ringClass(i_chipId, i_ringId, &o_ringClass));
}

#if !defined(__HOSTBOOT_MODULE) && !defined(FIPSODE)

// Mapping from the shared [initCompiler] chipId to the chipType name
std::map <ChipId_t, std::string> chipIdToTypeMap
{
    { (ChipId_t)CID_P10, "p10" },
    { (ChipId_t)CID_EXPLORER, "explorer" },
    { (ChipId_t)CID_ODYSSEY, "odyssey" }
};

// Mapping from chipType name to the shared [initCompiler] chipId (reverse of above map)
std::map <std::string, ChipId_t> chipTypeToIdMap
{
    { "p10", (ChipId_t)CID_P10 },
    { "explorer", (ChipId_t)CID_EXPLORER },
    { "odyssey", (ChipId_t)CID_ODYSSEY }
};


//
// Get ringId from ringName
//
int ringidGetRingId1( ChipId_t     i_chipId,
                      std::string  i_ringName,
                      RingId_t&    o_ringId,
                      bool         i_bTest )
{
    int rc = TOR_SUCCESS;
    RingProperties_t* ringProps = NULL;
    RingId_t          numRingIds = UNDEFINED_RING_ID;
    RingId_t          iRpIndex = UNDEFINED_RING_ID; // Ring properties index counter
    RingId_t          rpIndex = UNDEFINED_RING_ID; // The matching RP index
    bool              bFound = false;

    switch (i_chipId)
    {
        case CID_P10:
            ringProps = (RingProperties_t*)&P10_RID::RING_PROPERTIES;
            numRingIds = P10_RID::NUM_RING_IDS;
            break;

        default:
            MY_ERR("ringidGetRingId1(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    if (rc)
    {
        return rc;
    }
    else
    {
        // Search through RING_PROPERTIES for ringName match
        for ( iRpIndex = 0; iRpIndex < numRingIds; iRpIndex++ )
        {
            if ( !(i_ringName.compare(ringProps[iRpIndex].ringName)) )
            {
                if (bFound)
                {
                    MY_ERR("ringidGetRingId1(): Two rings cannot have the same ringName=%s. Fix"
                           " RING_PROPERTIES list for chipId=%d at rpIndex=0x%x and"
                           " rpIndex=0x%x\n",
                           i_ringName.c_str(), i_chipId, rpIndex, iRpIndex);
                    rpIndex = UNDEFINED_RING_ID;
                    rc = TOR_CODE_BUG;
                    break;
                }
                else
                {
                    rpIndex = iRpIndex;
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

    if (rc)
    {
        return rc;
    }
    else if (bFound)
    {
        o_ringId = ringProps[rpIndex].ringId;
        rc = TOR_SUCCESS;
    }
    else
    {
        MY_DBG("ringidGetRingId1(): Did not find match to ringName=%s for chipId=%u"
               " (Note, rpIndex=0x%x better be equal to UNDEFINED_RING_ID=0x%x)\n",
               i_ringName.c_str(), i_chipId, rpIndex, UNDEFINED_RING_ID);
        o_ringId = UNDEFINED_RING_ID;
        rc = TOR_RING_NAME_NOT_FOUND;
    }

    return rc;
}


//
// Get ringName from ringId
//
int ringidGetRingName( ChipId_t     i_chipId,
                       RingId_t     i_ringId,
                       std::string& o_ringName )
{
    int rc = INFRASTRUCT_RC_SUCCESS;
    RingProperties_t* ringProps = (RingProperties_t*)&P10_RID::RING_PROPERTIES;
    std::string l_ringName;

    // Get the ring properties (rp) index
    RingId_t rpIndex = P10_RID::ringid_convert_ringId_to_rpIndex(i_ringId);

    switch (i_chipId)
    {
        case CID_P10:
            if (rpIndex >= P10_RID::NUM_RING_IDS)
            {
                MY_ERR("ringidGetRingName(): rpIndex(=0x%x) >= NUM_RING_IDS(=0x%x) not allowed"
                       " and ringId=0x%x\n",
                       rpIndex, P10_RID::NUM_RING_IDS, i_ringId);
                rc = TOR_INVALID_RING_ID;
                break;
            }

            l_ringName = (std::string)ringProps[rpIndex].ringName;

            if (ringProps[rpIndex].ringId == HOLE_RING_ID)
            {
                rc = TOR_HOLE_RING_ID;
                break;
            }

            break;

        default:
            MY_ERR("ringidGetRingName(): Unsupported chipId (=%d) supplied\n", i_chipId);
            rc = TOR_INVALID_CHIP_ID;
            break;
    }

    o_ringName = l_ringName;

    return rc;
}


#endif // __HOSTBOOT_MODULE && FIPSODE

#endif // __PPE__ && NO_STD_LIB_IN_PPE && WIN32
