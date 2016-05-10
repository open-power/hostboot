/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/utils/imageProcs/p9_tor.C $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// IMPORTANT notice on usage of io_RingType and io_instanceId arguments
//
// io_RingTyp
// -------------
// While using tor_get_ring API, it is used as pass by reference
// While using tor_get_block_of_rings API, it is used as  pass by value
// io_instanceId
// --------------
// While using tor_get_ring API, it is used as pass by reference.
// While using tor_tor_get_block_of_rings and tor_get_single_ring API,
// it is used pass by value
//
#include "p9_tor.H"

//
// PPE type names:
// These strings must adhere precisely to the enum of PpeType.
//
const char* ppeTypeName[] = { "SBE",
                              "CME",
                              "SGPE",
                              "DEADBEAF"
                            };

//
// Ring variant names:
// These strings must adhere precisely to the enum of RingVariant.
//
const char* ringVariantName[] = { "Base",
                                  "CacheContained",
                                  "RiskLevel",
                                  "Override",
                                  "Overlay",
                                  "DEADBEAF"
                                };



///////////////////////////////////////////////////////////////////////////////////
///
///          extract RS4 extract from HW image
///
//////////////////////////////////////////////////////////////////////////////////
int get_ring_from_sbe_image ( void*           i_ringSectionPtr, // Image pointer
                              uint64_t        i_magic,          // Image Magic Number
                              RingID          i_ringId,         // Unique ring I
                              uint16_t        i_ddLevel,        // DD level details
                              RingType_t&     io_RingType,      // 0: Common 1: Instance
                              RingVariant_t
                              i_RingVariant,    // Base, cache contained, Risk level, Override and Overlay
                              uint8_t&        io_instanceId,    // chiplet Instance id indo
                              RingBlockType_t i_RingBlockType,  // 0: single ring,  1: ddLevel block
                              void**          io_ringBlockPtr,  // RS4 Container data or block data
                              uint32_t&       io_ringBlockSize, // size of data copied into ring block pointer
                              char*           o_ringName,       // Name of ring
                              uint32_t        dbgl)             // Debug option
{

    uint32_t ring_offset = 0;
    uint16_t chiplet_offset = 0;
    uint32_t next_ring_offset = 0;
    uint32_t ringSize = 0;
    int temp = i_ddLevel >> 2;
    uint32_t* deltaRingRS4_4B;
    uint32_t sbe_offset = 0;

    if (i_magic == P9_XIP_MAGIC_HW)
    {
        sbe_offset = *((uint32_t*)i_ringSectionPtr + temp);
        temp = myRev32(sbe_offset);
    }
    else if (i_magic == P9_XIP_MAGIC_SEEPROM)
    {
        sbe_offset = 0;
        i_ddLevel = 0;
        temp = myRev32(sbe_offset);
    }

    // Looper for each SBE chiplet
    for(int l = 0; l < MAX_CPLT_SBE; l++)  //MAX_CPLT_SBE
    {
        GenRingIdList* ring_id_list_common = NULL;
        GenRingIdList* ring_id_list_instance = NULL;
        CHIPLET_DATA  l_cpltData;
        uint8_t iv_num_variant = 0;

        switch (l)
        {
            case 0 :
                l_cpltData  =  PERV::g_pervData;
                iv_num_variant  = (uint8_t)sizeof(PERV::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) PERV::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) PERV::RING_ID_LIST_INSTANCE;
                break;

            case 1 :
                l_cpltData  =     N0::g_n0Data;
                iv_num_variant  = (uint8_t)sizeof(N0::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) N0::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) N0::RING_ID_LIST_INSTANCE;
                break;

            case 2 :
                l_cpltData =   N1::g_n1Data;
                iv_num_variant  = (uint8_t)sizeof(N1::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) N1::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) N1::RING_ID_LIST_INSTANCE;
                break;

            case 3 :
                l_cpltData  =    N2::g_n2Data;
                iv_num_variant  = (uint8_t)sizeof(N2::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) N2::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) N2::RING_ID_LIST_INSTANCE;
                break;

            case 4 :
                l_cpltData =   N3::g_n3Data;
                iv_num_variant  = (uint8_t)sizeof(N3::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) N3::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) N3::RING_ID_LIST_INSTANCE;
                break;

            case 5 :
                l_cpltData = XB::g_xbData;
                iv_num_variant  = (uint8_t)sizeof(XB::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) XB::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) XB::RING_ID_LIST_INSTANCE;
                break;

            case 6 :
                l_cpltData = MC::g_mcData;
                iv_num_variant  = (uint8_t)sizeof(MC::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) MC::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) MC::RING_ID_LIST_INSTANCE;
                break;

            case 7 :
                l_cpltData  = OB::g_obData;
                iv_num_variant  = (uint8_t)sizeof(OB::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) OB::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) OB::RING_ID_LIST_INSTANCE;
                break;

            case 8 :
                l_cpltData  =  PCI0::g_pci0Data;
                iv_num_variant  = (uint8_t)sizeof(PCI0::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) PCI0::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) PCI0::RING_ID_LIST_INSTANCE;
                break;

            case 9 :
                l_cpltData =  PCI1::g_pci1Data;
                iv_num_variant  = (uint8_t)sizeof(PCI1::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) PCI1::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) PCI1::RING_ID_LIST_INSTANCE;
                break;

            case 10 :
                l_cpltData =  PCI2::g_pci2Data;
                iv_num_variant  = (uint8_t)sizeof(PCI2::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) PCI2::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) PCI2::RING_ID_LIST_INSTANCE;
                break;

            case 11 :
                l_cpltData  =  EQ::g_eqData;
                iv_num_variant  = (uint8_t)sizeof(EQ::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) EQ::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) EQ::RING_ID_LIST_INSTANCE;
                break;

            case 12 :
                l_cpltData =  EC::g_ecData;
                iv_num_variant  = (uint8_t)sizeof(EC::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) EC::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) EC::RING_ID_LIST_INSTANCE;
                break;

            default :
                printf("Not valid selection\n");
        }

        if(dbgl > 1)
        {
            printf(" No of CommonRing %d, No of InstanceRing %d, No of Variants %d \n",
                   l_cpltData.iv_num_common_rings, l_cpltData.iv_num_instance_rings,
                   iv_num_variant);
        }

        uint32_t local = 0;

        for (uint8_t i = 0; i < l_cpltData.iv_num_common_rings ; i++)
        {
            for (uint8_t j = 0; j < iv_num_variant ; j++)
            {
                if(dbgl > 2)
                {
                    printf(" Ring name %s Cplt Common ring id %d Variant id %d",
                           (ring_id_list_common + i)->ringNameImg, i, j);
                }

                if((strcmp( (ring_id_list_common + i)->ringName,
                            RING_PROPERTIES[i_ringId].iv_name) == 0)
                   && ( i_RingVariant == j ))
                {
                    strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);
                    int var = l * 8 + i_ddLevel + temp;
                    int temp1 =  var / 4;
                    ring_offset =  *((uint32_t*)i_ringSectionPtr + temp1);
                    ring_offset = myRev32(ring_offset);
                    var = ring_offset + i_ddLevel + temp;
                    temp1 = var / 2 + local;
                    chiplet_offset  = *((uint16_t*)i_ringSectionPtr + temp1);
                    chiplet_offset = myRev16(chiplet_offset);

                    if(i_RingBlockType == SINGLE_RING)
                    {
                        var = ring_offset + (chiplet_offset - 8) + i_ddLevel + temp;
                        temp1 = var / 4;
                        next_ring_offset = *((uint32_t*)i_ringSectionPtr + temp1);
                        next_ring_offset = myRev32(next_ring_offset);
                        ringSize = next_ring_offset;
                        io_RingType = COMMON;

                        if (chiplet_offset)
                        {
                            if (io_ringBlockSize < ringSize)
                            {
                                printf("\tio_ringBlockSize is less than required size ...\n");
                                io_ringBlockSize =  ringSize;
                                return 0;
                            }

                            if(dbgl > 1)
                            {
                                printf("   ring container of %s is found in the SBE image container \n",
                                       o_ringName);
                            }

                            // Copying single ring into ring block pointer
                            memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSectionPtr + var,
                                    (size_t)ringSize);
                            io_ringBlockSize = ringSize;
                            io_instanceId = (ring_id_list_common + i)->instanceIdMin;


                            if(dbgl > 0)
                            {
                                printf(" After get_ring_from_sbe_image Size %d \n", io_ringBlockSize);
                            }

                            // Debug details for each offset address in DD TOR, DD TOR, SBE TOP TOR, SBE common/instance TOR, ring size
                            if(dbgl > 1)
                            {
                                printf("Hexdetalis Chiplet offset 0x%08x local offset 0x%08x " \
                                       "ring offset 0x%08x start adr 0x%08x  size 0x%08x size 0x%08x \n",
                                       var, temp, ring_offset, chiplet_offset, next_ring_offset, ringSize);
                                printf("Chiplet %d   ChipletRing TOR offset  %d  %d   %d  Size %d %d \t\n",
                                       i,  ring_offset, chiplet_offset, next_ring_offset, ringSize, temp);
                            }

                            if(dbgl > 2)
                            {
                                deltaRingRS4_4B = (uint32_t*)(*io_ringBlockPtr);

                                for (uint32_t m = 0; m < ringSize / 4; m++)
                                {
                                    printf("compressed data %d  --- %08x   \t", m, myRev32(deltaRingRS4_4B[m]));
                                }

                                printf("\n");
                            }

                            return IMGBUILD_TGR_RING_FOUND;
                        }
                        else
                        {
                            printf("   ring container of %s is not found in the SBE image container \n",
                                   o_ringName);
                            return IMGBUILD_TGR_RING_NOT_FOUND;
                        }
                    }
                }

                local++;
            }
        }

        local = 0;

        for(uint8_t i = (ring_id_list_instance + 0)->instanceIdMin;
            i < (ring_id_list_instance + 0)->instanceIdMax + 1 ; i++)
        {
            for (uint8_t j = 0; j < l_cpltData.iv_num_instance_rings; j++)
            {
                for(uint8_t k = 0; k < iv_num_variant ; k++)
                {
                    if(dbgl > 2)
                    {
                        printf(" Ring name %s Cplt instance ring id %d Variant id %d Instance id %d\n",
                               (ring_id_list_instance + j)->ringNameImg, j, k, i);
                    }

                    if  (strcmp( (ring_id_list_instance + j)->ringName,
                                 RING_PROPERTIES[i_ringId].iv_name) == 0)
                    {
                        if(  io_instanceId >=  (ring_id_list_instance + 0)->instanceIdMin
                             &&  io_instanceId  <= (ring_id_list_instance + 0)->instanceIdMax)
                        {
                            if( i == io_instanceId && k == i_RingVariant )
                            {
                                strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);
                                uint32_t var = l * 8 + i_ddLevel + temp + 4;
                                int temp1 =  var / 4;
                                ring_offset =  *((uint32_t*)i_ringSectionPtr + temp1);
                                ring_offset = myRev32(ring_offset);
                                var = ring_offset + i_ddLevel + temp;
                                temp1 = var / 2 + local;
                                chiplet_offset  = *((uint16_t*)i_ringSectionPtr + temp1);
                                chiplet_offset = myRev16(chiplet_offset);

                                if(i_RingBlockType == SINGLE_RING)
                                {
                                    var = ring_offset + (chiplet_offset - 8) + i_ddLevel + temp;
                                    temp1 = var / 4;
                                    next_ring_offset = *((uint32_t*)i_ringSectionPtr + temp1);
                                    next_ring_offset = myRev32(next_ring_offset);
                                    ringSize = next_ring_offset;
                                    io_RingType = INSTANCE;

                                    if (chiplet_offset)
                                    {
                                        if (io_ringBlockSize < ringSize)
                                        {
                                            printf("\tio_ringBlockSize is less than required size ...\n");
                                            io_ringBlockSize =  ringSize;
                                            return 0;
                                        }

                                        if(dbgl > 0)
                                        {
                                            printf("   ring container of %s is found in the SBE image container \n",
                                                   o_ringName);
                                        }

                                        memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSectionPtr + var,
                                                (size_t)ringSize);
                                        io_ringBlockSize = ringSize;

                                        if(dbgl > 0)
                                        {
                                            printf(" After get_ring_from_sbe_image Size %d \n", io_ringBlockSize);
                                        }

                                        // Debug details for each offset address in DD TOR, DD TOR, SBE TOP TOR, SBE common/instance TOR, ring size
                                        if(dbgl > 1)
                                        {
                                            printf(" 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x \n",
                                                   var, temp, ring_offset, chiplet_offset, next_ring_offset, ringSize);
                                            printf("Chiplet %d   ChipletRing TOR offset  %d  %d   %d  Size %d %d \t\n",
                                                   i,  ring_offset, chiplet_offset, next_ring_offset, ringSize, temp);
                                        }

                                        if(dbgl > 2)
                                        {
                                            deltaRingRS4_4B = (uint32_t*)(*io_ringBlockPtr);

                                            for (uint32_t m = 0; m < ringSize / 4; m++)
                                            {
                                                printf("compressed data %d  --- %08x   \t",
                                                       m, myRev32(deltaRingRS4_4B[m]));
                                            }

                                            printf("\n");
                                        }

                                        return IMGBUILD_TGR_RING_FOUND;
                                    }
                                    else
                                    {
                                        printf("   ring container of %s is not found in the SBE image container \n",
                                               o_ringName);
                                        return IMGBUILD_TGR_RING_NOT_FOUND;
                                    }
                                }
                            }

                        }
                        else
                        {
                            printf(" SBE ring instance ID %d is invalid, Valid ID is from %d  to %d  \n",
                                   io_instanceId, (ring_id_list_instance + 0)->instanceIdMin,
                                   (ring_id_list_instance + 0)->instanceIdMax);
                            return IMGBUILD_INVALID_INSTANCEID;
                        }
                    }

                    local++;
                }

                //printf("\n");
            }

        }

    }

    return IMGBUILD_TGR_RING_NOT_FOUND;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_ring_from_sgpe_image ( void*
                               i_ringSectionPtr,  // Image pointer
                               RingID          i_ringId,          // Unique ring I
                               uint16_t        i_ddLevel,         // DD level details
                               RingType_t&     io_RingType,       // 0: Common 1: Instance
                               RingVariant_t
                               i_RingVariant,     // Variant -> Base, cache contained, Risk level,
                               // Override and Overlay
                               uint8_t&        io_instanceId,     // required Instance
                               RingBlockType_t i_RingBlockType,   // 0: single ring,  1: ddLevel block
                               void**          io_ringBlockPtr,   // RS4 Container data or block data
                               uint32_t&
                               io_ringBlockSize,  // size of data copied into ring block pointer
                               char*           o_ringName,        // Name of ring
                               uint32_t        dbgl)              // Debug option
{
    uint32_t ring_offset = 0;
    uint16_t chiplet_offset = 0;
    uint32_t next_ring_offset = 0;
    uint32_t ringSize = 0;
    int temp = (i_ddLevel >> 2) + 4;
    uint32_t* deltaRingRS4_4B;
    uint32_t spge_offset = *((uint32_t*)i_ringSectionPtr + temp);
    temp = myRev32(spge_offset);
    GenRingIdList* ring_id_list_common = NULL;
    GenRingIdList* ring_id_list_instance = NULL;
    uint8_t iv_num_variant  = (uint8_t)sizeof(EQ::RingVariants) / sizeof(uint16_t);
    ring_id_list_common = (GenRingIdList*) EQ::RING_ID_LIST_COMMON;
    ring_id_list_instance = (GenRingIdList*) EQ::RING_ID_LIST_INSTANCE;

    uint32_t local = 0;

    for (uint8_t i = 0; i < EQ::g_eqData.iv_num_common_rings ; i++)
    {
        for (uint8_t j = 0; j < iv_num_variant ; j++)
        {
            if(dbgl > 2)
            {
                printf(" Ring name %s Cplt Common ring id %d Variant id %d",
                       (ring_id_list_common + i)->ringNameImg, i, j);
            }

            if((strcmp( (ring_id_list_common + i)->ringName,
                        RING_PROPERTIES[i_ringId].iv_name) == 0) && ( i_RingVariant == j ))
            {
                strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);
                int var = 0 + i_ddLevel + temp;
                int temp1 =  var / 4;
                ring_offset =  *((uint32_t*)i_ringSectionPtr + temp1);
                ring_offset = myRev32(ring_offset);
                var = ring_offset + i_ddLevel + temp;
                temp1 = var / 2 + local;
                chiplet_offset  = *((uint16_t*)i_ringSectionPtr + temp1);
                chiplet_offset = myRev16(chiplet_offset);

                if (i_RingBlockType == SINGLE_RING)
                {
                    var = ring_offset + (chiplet_offset - 8) + i_ddLevel + temp;
                    temp1 = var / 4;
                    next_ring_offset = *((uint32_t*)i_ringSectionPtr + temp1);
                    next_ring_offset = myRev32(next_ring_offset);
                    ringSize = next_ring_offset;
                    io_RingType = COMMON;

                    if (chiplet_offset)
                    {
                        if (io_ringBlockSize < ringSize)
                        {
                            printf("\tio_ringBlockSize is less than required size ...\n");
                            io_ringBlockSize =  ringSize;
                            return 0;
                        }

                        if(dbgl > 0)
                        {
                            printf("   ring container of %s is found in the SGPE image container && ring offset %d \n",
                                   o_ringName, chiplet_offset);
                        }

                        // Copying ring data into io buffer
                        memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSectionPtr + var,
                                (size_t)ringSize);
                        io_ringBlockSize = ringSize;
                        io_instanceId = (ring_id_list_common + i)->instanceIdMin;

                        // Debug details for each offset address in DD TOR, DD TOR, SBE TOP TOR, SBE common/instance TOR, ring size
                        if(dbgl > 0)
                        {
                            printf(" After get_ring_from_sbe_image Size %d \n", io_ringBlockSize);
                        }

                        if(dbgl > 1)
                        {
                            printf("Hexdetalis Chiplet offset 0x%08x local offset 0x%08x " \
                                   "ring offset 0x%08x start adr 0x%08x  size 0x%08x size 0x%08x \n",
                                   var, temp, ring_offset, chiplet_offset, next_ring_offset, ringSize);
                            printf("Chiplet %d   ChipletRing TOR offset  %d  %d   %d  Size %d %d \t\n",
                                   i,  ring_offset, chiplet_offset, next_ring_offset, ringSize, temp);
                        }

                        if(dbgl > 2)
                        {
                            deltaRingRS4_4B = (uint32_t*)(*io_ringBlockPtr);

                            for (uint32_t m = 0; m < ringSize / 4; m++)
                            {
                                printf("compressed data %d  --- %08x   \t", m, myRev32(deltaRingRS4_4B[m]));
                            }

                            printf("\n");
                        }

                        return IMGBUILD_TGR_RING_FOUND;
                    }
                    else
                    {
                        printf("   ring container of %s is  not found in the SGPE image container \n",
                               o_ringName);
                        return IMGBUILD_TGR_RING_NOT_FOUND;
                    }
                }
            }

            local++;
        }

        //printf ("\n");
    }

    // Instance specific single ring extract loop
    local = 0;

    for(uint8_t i = (ring_id_list_instance + 0)->instanceIdMin;
        i < (ring_id_list_instance + 0)->instanceIdMax + 1 ; i++)
    {
        for (uint8_t j = 0; j < EQ::g_eqData.iv_num_instance_rings; j++)
        {
            for(uint8_t k = 0; k < iv_num_variant ; k++)
            {
                if(dbgl > 2)
                {
                    printf(" Ring name %s Cplt instance ring id %d Variant id %d",
                           (ring_id_list_instance + j)->ringNameImg, j, k);
                }

                if  (strcmp( (ring_id_list_instance + j)->ringName,
                             RING_PROPERTIES[i_ringId].iv_name) == 0)
                {
                    if(  io_instanceId >=  (ring_id_list_instance + 0)->instanceIdMin
                         &&  io_instanceId  <= (ring_id_list_instance + 0)->instanceIdMax)
                    {
                        if( i == io_instanceId && k == i_RingVariant )
                        {
                            strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);
                            uint32_t var = 4 + i_ddLevel + temp;
                            int temp1 =  var / 4;
                            ring_offset =  *((uint32_t*)i_ringSectionPtr + temp1);
                            ring_offset = myRev32(ring_offset);
                            var = ring_offset + i_ddLevel + temp;
                            temp1 = var / 2 + local;
                            chiplet_offset  = *((uint16_t*)i_ringSectionPtr + temp1);
                            chiplet_offset = myRev16(chiplet_offset);

                            if (i_RingBlockType == SINGLE_RING)
                            {
                                var = ring_offset + (chiplet_offset - 8) + i_ddLevel + temp;
                                temp1 = var / 4;
                                next_ring_offset = *((uint32_t*)i_ringSectionPtr + temp1);
                                next_ring_offset = myRev32(next_ring_offset);
                                ringSize = next_ring_offset;
                                io_RingType = INSTANCE;

                                if (chiplet_offset)
                                {
                                    if (io_ringBlockSize < ringSize)
                                    {
                                        printf("\tio_ringBlockSize is less than required size ...\n");
                                        io_ringBlockSize =  ringSize;
                                        return 0;
                                    }

                                    if(dbgl > 0)
                                    {
                                        printf("   ring container of %s is found in the SGPE image container \n",
                                               o_ringName);
                                    }

                                    // Copying ring data into io_buffer
                                    memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSectionPtr + var,
                                            (size_t)ringSize);
                                    io_ringBlockSize = ringSize;

                                    if(dbgl > 0)
                                    {
                                        printf(" After get_ring_from_sbe_image Size %d \n", io_ringBlockSize);
                                    }

                                    // Debug details for each offset address in DD TOR, DD TOR, SBE TOP TOR, SBE common/instance TOR, ring size
                                    if(dbgl > 1)
                                    {
                                        printf(" 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x \n",
                                               var, temp, ring_offset, chiplet_offset, next_ring_offset, ringSize);
                                        printf("Chiplet %d   ChipletRing TOR offset  %d  %d   %d  Size %d %d \t\n",
                                               i,  ring_offset, chiplet_offset, next_ring_offset, ringSize, temp);
                                    }

                                    if(dbgl > 2)
                                    {
                                        deltaRingRS4_4B = (uint32_t*)(*io_ringBlockPtr);

                                        for (uint32_t m = 0; m < ringSize / 4; m++)
                                        {
                                            printf("compressed data %d  --- %08x   \t", m, myRev32(deltaRingRS4_4B[m]));
                                        }

                                        printf("\n");
                                    }

                                    return IMGBUILD_TGR_RING_FOUND;
                                }
                                else
                                {
                                    printf("   ring container of %s is not found in the SGPE image container \n",
                                           o_ringName);
                                    return IMGBUILD_TGR_RING_NOT_FOUND;
                                }
                            }
                        }
                    }
                    else
                    {
                        printf(" SGPE ring instance ID %d is invalid, Valid ID is from %d  to %d \n",
                               io_instanceId, (ring_id_list_instance + 0)->instanceIdMin,
                               (ring_id_list_instance + 0)->instanceIdMax);
                        return IMGBUILD_INVALID_INSTANCEID;
                    }
                }

                local++;
            }
        }
    }

    return IMGBUILD_TGR_RING_NOT_FOUND;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                             Get ring container from CME ring section
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_ring_from_cme_image ( void*
                              i_ringSectionPtr,     // Image pointer
                              RingID          i_ringId,             // Unique ring I
                              uint16_t        i_ddLevel,            // DD level details
                              RingType_t&     io_RingType,          // 0: Common 1: Instance
                              RingVariant_t
                              i_RingVariant,        // Variant -> Base, cache contained, Risk level, Override and Overlay
                              uint8_t&        io_instanceId,        // required Instance
                              RingBlockType_t i_RingBlockType,      // 0: single ring,  1: ddLevel block
                              void**          io_ringBlockPtr,      // RS4 Container data or block data
                              uint32_t&
                              io_ringBlockSize,     // size of data copied into ring block pointer
                              char*           o_ringName,           // Name of ring
                              uint32_t        dbgl)                 // Debug option
{
    uint32_t ring_offset = 0;
    uint16_t chiplet_offset = 0;
    uint32_t next_ring_offset = 0;
    uint32_t ringSize = 0;
    int temp = (i_ddLevel >> 2) + 2;
    uint32_t* deltaRingRS4_4B;
    uint32_t spge_offset = *((uint32_t*)i_ringSectionPtr + temp);
    temp = myRev32(spge_offset);
    GenRingIdList* ring_id_list_common = NULL;
    GenRingIdList* ring_id_list_instance = NULL;
    uint8_t iv_num_variant  = (uint8_t)sizeof(EC::RingVariants) / sizeof(uint16_t);
    ring_id_list_common = (GenRingIdList*) EC::RING_ID_LIST_COMMON;
    ring_id_list_instance = (GenRingIdList*) EC::RING_ID_LIST_INSTANCE;
    //printf(" C %d I %d V %d \n",l_cpltData.iv_num_common_rings,l_cpltData.iv_num_instance_rings,iv_num_variant);
    uint32_t local = 0;

    for (uint8_t i = 0; i < EC::g_ecData.iv_num_common_rings ; i++)
    {
        for (uint8_t j = 0; j < iv_num_variant ; j++)
        {
            if(dbgl > 2)
            {
                printf(" Ring name %s Cplt Common ring id %d Variant id %d",
                       (ring_id_list_common + i)->ringNameImg, i, j);
            }

            if((strcmp( (ring_id_list_common + i)->ringName,
                        RING_PROPERTIES[i_ringId].iv_name) == 0) && ( i_RingVariant == j ))
            {
                strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);
                int var = 0 + i_ddLevel + temp;
                int temp1 =  var / 4;
                ring_offset =  *((uint32_t*)i_ringSectionPtr + temp1);
                ring_offset = myRev32(ring_offset);
                var = ring_offset + i_ddLevel + temp;
                temp1 = var / 2 + local;
                chiplet_offset  = *((uint16_t*)i_ringSectionPtr + temp1);
                chiplet_offset = myRev16(chiplet_offset);

                if (i_RingBlockType == SINGLE_RING)
                {
                    var = ring_offset + (chiplet_offset - 8) + i_ddLevel + temp;
                    temp1 = var / 4;
                    next_ring_offset = *((uint32_t*)i_ringSectionPtr + temp1);
                    next_ring_offset = myRev32(next_ring_offset);
                    ringSize = next_ring_offset;
                    io_RingType = COMMON;

                    if (chiplet_offset)
                    {
                        if (io_ringBlockSize < ringSize)
                        {
                            printf("\tio_ringBlockSize is less than required size ...\n");
                            io_ringBlockSize =  ringSize;
                            return 0;
                        }

                        if(dbgl > 0)
                        {
                            printf("   ring container of %s is found in the CME image container \n",
                                   o_ringName);
                        }

                        // Copying ring data into io_buffer
                        memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSectionPtr + var,
                                (size_t)ringSize);
                        io_ringBlockSize = ringSize;
                        io_instanceId = (ring_id_list_common + i)->instanceIdMin;

                        // Debug details for each offset address in DD TOR, DD TOR, SBE TOP TOR, SBE common/instance TOR, ring size
                        if(dbgl > 0)
                        {
                            printf(" After get_ring_from_sbe_image Size %d \n", io_ringBlockSize);
                        }

                        if(dbgl > 1)
                        {
                            printf("Hexdetalis Chiplet offset 0x%08x local offset 0x%08x " \
                                   "ring offset 0x%08x start adr 0x%08x  size 0x%08x size 0x%08x \n",
                                   var, temp, ring_offset, chiplet_offset, next_ring_offset, ringSize);
                            printf("Chiplet %d   ChipletRing TOR offset  %d  %d   %d  Size %d %d \t\n",
                                   i,  ring_offset, chiplet_offset, next_ring_offset, ringSize, temp);
                        }

                        if(dbgl > 2)
                        {
                            deltaRingRS4_4B = (uint32_t*)(*io_ringBlockPtr);

                            for (uint32_t m = 0; m < ringSize / 4; m++)
                            {
                                printf("compressed data %d  --- %08x   \t", m, myRev32(deltaRingRS4_4B[m]));
                            }

                            printf("\n");
                        }

                        return IMGBUILD_TGR_RING_FOUND;
                    }
                    else
                    {
                        printf("   ring container of %s is not found in the CME image container \n",
                               o_ringName);
                        return IMGBUILD_TGR_RING_NOT_FOUND;
                    }
                }
            }

            local++;
        }
    }

    // Instance specific single ring extract loop
    local = 0;

    for(uint8_t z = 0; z < 12; z++)
    {
        local = 0;

        for(uint8_t i = z * 2 + (ring_id_list_instance + 0)->instanceIdMin;
            i < z * 2 + 2 + (ring_id_list_instance + 0)->instanceIdMin ; i++)
        {
            for (uint8_t j = 0; j < EC::g_ecData.iv_num_instance_rings; j++)
            {
                for(uint8_t k = 0; k < iv_num_variant ; k++)
                {
                    if(dbgl > 2)
                    {
                        printf(" Ring name %s Cplt instance ring id %d Variant id %d",
                               (ring_id_list_instance + j)->ringNameImg, j, k);
                    }

                    if  (strcmp( (ring_id_list_instance + j)->ringName,
                                 RING_PROPERTIES[i_ringId].iv_name) == 0)
                    {
                        if(  io_instanceId >=  (ring_id_list_instance + 0)->instanceIdMin
                             &&  io_instanceId  <= (ring_id_list_instance + 0)->instanceIdMax)
                        {
                            if( i == io_instanceId && k == i_RingVariant )
                            {
                                strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);
                                uint32_t var = z * 4 + i_ddLevel + temp + 4;
                                int temp1 =  var / 4;
                                ring_offset =  *((uint32_t*)i_ringSectionPtr + temp1);
                                ring_offset = myRev32(ring_offset);
                                var = ring_offset + i_ddLevel + temp;
                                temp1 = var / 2 + local;
                                chiplet_offset  = *((uint16_t*)i_ringSectionPtr + temp1);
                                chiplet_offset = myRev16(chiplet_offset);

                                if (i_RingBlockType == SINGLE_RING)
                                {
                                    var = ring_offset + (chiplet_offset - 8) + i_ddLevel + temp;
                                    temp1 = var / 4;
                                    next_ring_offset = *((uint32_t*)i_ringSectionPtr + temp1);
                                    next_ring_offset = myRev32(next_ring_offset);
                                    ringSize = next_ring_offset;
                                    io_RingType = INSTANCE;

                                    if (chiplet_offset)
                                    {
                                        if (io_ringBlockSize < ringSize)
                                        {
                                            printf("\tio_ringBlockSize is less than required size ...\n");
                                            io_ringBlockSize =  ringSize;
                                            return 0;
                                        }

                                        if(dbgl > 0)
                                        {
                                            printf(" ring container of %s is found in the CME image container  %d %d \n",
                                                   o_ringName, chiplet_offset, ringSize);
                                            printf("  0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x \n",
                                                   var, temp, ring_offset, chiplet_offset, next_ring_offset, ringSize);
                                        }

                                        // Copying ring data into io_buffer
                                        memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSectionPtr + var,
                                                (size_t)ringSize);
                                        io_ringBlockSize = ringSize;

                                        // Debug details for each offset address in DD TOR, DD TOR, SBE TOP TOR, SBE common/instance TOR, ring size
                                        if(dbgl > 0)
                                        {
                                            printf(" After get_ring_from_sbe_image Size %d \n", io_ringBlockSize);
                                        }

                                        if(dbgl > 1)
                                        {
                                            printf("  0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x \n",
                                                   var, temp, ring_offset, chiplet_offset, next_ring_offset, ringSize);
                                            printf("Chiplet %d   ChipletRing TOR offset  %d  %d   %d  Size %d %d \t\n",
                                                   i,  ring_offset, chiplet_offset, next_ring_offset, ringSize, temp);
                                        }

                                        if(dbgl > 2)
                                        {
                                            deltaRingRS4_4B = (uint32_t*)(*io_ringBlockPtr);

                                            for (uint32_t m = 0; m < ringSize / 4; m++)
                                            {
                                                printf("compressed data %d  --- %08x   \t", m, myRev32(deltaRingRS4_4B[m]));
                                            }

                                            printf("\n");
                                        }

                                        return IMGBUILD_TGR_RING_FOUND;
                                    }
                                    else
                                    {
                                        printf("   ring container of %s is not found in the CME image container \n",
                                               o_ringName);
                                        return IMGBUILD_TGR_RING_NOT_FOUND;
                                    }
                                }
                            }
                        }
                        else
                        {
                            printf(" CME ring instance ID %d is invalid, Valid ID is from %d  to %d \n",
                                   io_instanceId, (ring_id_list_instance + 0)->instanceIdMin,
                                   (ring_id_list_instance + 0)->instanceIdMax);
                            return IMGBUILD_INVALID_INSTANCEID;
                        }
                    }

                    local++;
                }
            }
        }
    }

    return IMGBUILD_TGR_RING_NOT_FOUND;
}

//////////////////////////////////////////////////////////////////////////////////////////
///
///                            TOR GET RING API
//////////////////////////////////////////////////////////////////////////////////////////

int tor_get_ring(  void*
                   i_ringSectionPtr,  // Ring address Ptr any of .rings, .overrides and .overlays.
                   uint64_t        i_magic,           // Image Magic Number
                   RingID          i_ringId,          // Unique ring ID
                   uint16_t        i_ddLevel,         // DD level info
                   PpeType_t       i_PpeType,         // PPE type : SBE, CME, etc
                   RingType_t&      io_RingType,       // 0: Common 1: Instance
                   RingVariant_t   i_RingVariant,     // Base, Cache etc
                   uint8_t&        io_instanceId,     // chiplet instance ID
                   RingBlockType_t i_RingBlockType,   // 0: single ring,  1: ring block
                   void**          io_ringBlockPtr,   // Addr of ring buffer
                   uint32_t&       io_ringBlockSize,  // size of ring data
                   char*           o_ringName         // Ring name
                )
{
    int rc = 0;
    uint32_t dbgl = 2;

    if(dbgl > 1)
    {
        printf( "TOR_GET_RING(1): function call \n");
    }

    uint32_t ddLevelOffset = 0;
    uint32_t ddLevelCount = 0;
    uint32_t temp = 0, temp1 = 0, local = 0;

    if(dbgl > 1)
    {
        printf( "TOR_GET_RING(2):DD Level info extracting from TOR \n");
    }

    if (i_magic == P9_XIP_MAGIC_HW)
    {
        ddLevelCount =  *((uint32_t*)i_ringSectionPtr + 0);
        ddLevelCount = myRev32(ddLevelCount);

        if(dbgl > 1)
        {
            printf("TOR_GET_RING(3): No of DD levels in the TOR is %d \n", ddLevelCount);
        }

        for (uint8_t i = 0; i < ddLevelCount; i++)
        {
            local = 2;
            ddLevelOffset  =  *((uint32_t*)i_ringSectionPtr + local);
            temp = myRev32(ddLevelOffset) >> 24 & 0x000000FF;
            ddLevelOffset = myRev32(ddLevelOffset) & 0x00FFFFFF;

            if(dbgl > 1)
            {
                printf( "TOR_GET_RING(4): DD level offset %d DD %d level Copy  \n",
                        ddLevelOffset, temp );
            }

            if ( temp == i_ddLevel)
            {
                ddLevelOffset  =  *((uint32_t*)i_ringSectionPtr + local);
                ddLevelOffset = ddLevelOffset & 0xFFFFFF00;
                ddLevelOffset = myRev32(ddLevelOffset);
                ddLevelOffset = ddLevelOffset + 8;
                local = local + 1;
                temp1 = *((uint32_t*)i_ringSectionPtr + local);
                temp1 = myRev32(temp1);
                break;
            }
        }
    }
    else if( i_magic ==  P9_XIP_MAGIC_SEEPROM)
    {
        if ( i_PpeType == CME)
        {
            printf("Ambiguity on input PARMS for calling SEEPROM Ring copy API. \n "\
                   " CME rings not populated on SEEPROM image       \n");
            return IMGBUILD_TGR_IMAGE_DOES_NOT_SUPPORT_CME;
        }
        else if (i_PpeType == SGPE)
        {
            printf("Ambiguity on input PARMS for calling SEEPROM Ring copy API. \n "\
                   "SGPE rings not populated on SEEPROM image       \n");
            return IMGBUILD_TGR_IMAGE_DOES_NOT_SUPPORT_SGPE;
        }
        else if (i_RingBlockType == DD_LEVEL_RINGS)
        {
            printf("Ambiguity on input PARMS for calling SEEPROM Ring copy API. \n "\
                   " DD level ring copy are not supported   \n");
            return IMGBUILD_TGR_IMAGE_DOES_NOT_SUPPORT_DD_LEVEL;
        }
        else if (i_RingBlockType == PPE_LEVEL_RINGS )
        {
            printf("Ambiguity on input PARMS for calling SEEPROM Ring copy API. \n "\
                   " PPE level ring copy are not supported   \n");
            return IMGBUILD_TGR_IMAGE_DOES_NOT_SUPPORT_PPE_LEVEL;
        }
        else
        {
            ddLevelOffset = 0;
            temp1 = 0;
        }
    }

    if(i_RingBlockType == DD_LEVEL_RINGS)  // DD_LEVEL_COPY
    {

        if (io_ringBlockSize < temp1)
        {
            printf("\tio_ringBlockSize is less than required size ...\n");
            io_ringBlockSize =  temp1;
            return 0;
        }

        memcpy( (uint8_t*)(*io_ringBlockPtr),
                (uint8_t*)i_ringSectionPtr + ddLevelOffset, (size_t)temp1);

        if(dbgl > 1)
        {
            printf( " TOR_GET_RING(5): DD level offset %d DD %d size 0x%08x %d \n",
                    ddLevelOffset, temp, temp1, temp1);
        }

        io_ringBlockSize =  temp1;
        return IMGBUILD_TGR_RING_BLOCKS_FOUND;

    }
    else if (i_RingBlockType == PPE_LEVEL_RINGS)
    {
        uint32_t l_ppe_offset = 0;
        uint32_t l_ppe_size   = 0;

        if(i_PpeType == SBE)
        {
            int temp = ddLevelOffset >> 2;

            if(dbgl > 1)
            {
                printf( "TOR_GET_RING(6): SBE PPE_LEVEL_RING COPY called ... \n");
            }

            l_ppe_offset = *((uint32_t*)i_ringSectionPtr + temp);
            l_ppe_offset = myRev32(l_ppe_offset);
            l_ppe_size = *((uint32_t*)i_ringSectionPtr + temp + 1 );
            l_ppe_size = myRev32(l_ppe_size);
        }
        else if (i_PpeType == CME)
        {
            int temp = (ddLevelOffset >> 2) + 2;

            if(dbgl > 1)
            {
                printf( "TOR_GET_RING(7): CME PPE_LEVEL_RING COPY called... \n");
            }

            l_ppe_offset = *((uint32_t*)i_ringSectionPtr + temp);
            l_ppe_offset = myRev32(l_ppe_offset);
            l_ppe_size = *((uint32_t*)i_ringSectionPtr + temp + 1 );
            l_ppe_size = myRev32(l_ppe_size);
        }
        else if (i_PpeType == SGPE)
        {

            int temp = (ddLevelOffset >> 2) + 4;

            if(dbgl > 1)
            {
                printf( "TOR_GET_RING(8): SPGE PPE_LEVEL_RING COPY called... \n");
            }

            l_ppe_offset = *((uint32_t*)i_ringSectionPtr + temp);
            l_ppe_offset = myRev32(l_ppe_offset);
            l_ppe_size = *((uint32_t*)i_ringSectionPtr + temp + 1 );
            l_ppe_size = myRev32(l_ppe_size);
        }

        if (io_ringBlockSize < l_ppe_size)
        {
            printf("\tio_ringBlockSize is less than required size ....\n");
            io_ringBlockSize =  l_ppe_size;
            return 0;
        }

        memcpy( (uint8_t*)(*io_ringBlockPtr),
                (uint8_t*)i_ringSectionPtr + l_ppe_offset + ddLevelOffset,
                (size_t)l_ppe_size);
        io_ringBlockSize = l_ppe_size;
        return IMGBUILD_TGR_RING_BLOCKS_FOUND;
    }
    else if (i_RingBlockType == CPLT_LEVEL_RINGS)
    {
        if(dbgl > 1)
        {
            printf( "TOR_GET_RING(9): CPLT_LEVEL_RING COPY called... \n");
        }

        if(io_RingType == ALLRING)
        {
            printf("Ambiguity on input PARMS. ALLRING RingType is invalid for CPLT level ring copy  \n");
            return IMGBUILD_TGR_AMBIGUOUS_API_PARMS;

        }

        uint32_t l_cplt_offset = 0;
        uint32_t l_ppe_offset  = 0;
        uint32_t l_cplt_size   = 0;

        if(i_PpeType == SBE)
        {
            SbeTorId_t l_sbeTorId = SBEALL;

            switch (io_instanceId)
            {
                case 1 :
                    l_sbeTorId = PERV_CPLT;
                    break;

                case 2 :
                    l_sbeTorId = N0_CPLT;
                    break;

                case 3 :
                    l_sbeTorId = N1_CPLT;
                    break;

                case 4 :
                    l_sbeTorId = N2_CPLT;
                    break;

                case 5 :
                    l_sbeTorId = N3_CPLT;
                    break;

                case 6 :
                    l_sbeTorId = XB_CPLT;
                    break;

                case 7 :
                    l_sbeTorId = MC_CPLT;
                    break;

                case 9 :
                    l_sbeTorId = OB_CPLT;
                    break;

                case 13 :
                    l_sbeTorId = PCI0_CPLT;
                    break;

                case 14 :
                    l_sbeTorId = PCI1_CPLT;
                    break;

                case 15 :
                    l_sbeTorId = PCI2_CPLT;
                    break;

                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                    l_sbeTorId = EQ_CPLT;
                    break;

                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                    l_sbeTorId = EC_CPLT;
                    break;

                default :
                    printf("Not valid chiplet ID\n");
            }

            temp = (ddLevelOffset >> 2);
            int l_word;

            if (i_magic == P9_XIP_MAGIC_HW)
            {
                l_cplt_offset = *((uint32_t*)i_ringSectionPtr + temp);
            }
            else
            {
                l_cplt_offset = 0;
            }

            if(dbgl > 1)
            {
                printf("SBE(1):Offset 0x%08x \n", l_cplt_offset);
            }

            l_cplt_offset = myRev32(l_cplt_offset);
            uint32_t l_ppe_cplt_offset  = l_cplt_offset;
            temp = temp + 2;
            l_ppe_offset  = *((uint32_t*)i_ringSectionPtr + temp);
            l_ppe_offset  = myRev32(l_ppe_offset);
            temp1 = l_cplt_offset;

            if(dbgl > 1)
            {
                printf("SBE(2):Offset 0x%08x  0x%08x 0x%08x 0x%08x\n", l_cplt_offset,
                       l_ppe_offset, temp, ddLevelOffset);
            }

            if (io_RingType == COMMON)
            {
                temp  = l_cplt_offset + ddLevelOffset + (l_sbeTorId * 8);
                l_word = temp >> 2;
                temp  = l_cplt_offset + ddLevelOffset;

                if(dbgl > 1)
                {
                    printf("SBE(3):COMMON Offset 0x%08x  0x%08x 0x%08x  \n", l_cplt_offset,
                           l_ppe_offset, temp);
                }
            }
            else
            {
                temp  = l_cplt_offset + ddLevelOffset + (l_sbeTorId * 8) + 4;
                l_word = temp >> 2;
                temp  = l_cplt_offset + ddLevelOffset;

                if(dbgl > 1)
                {
                    printf("SBE(4):INSTANCE Offset 0x%08x  0x%08x 0x%08x  \n", l_cplt_offset,
                           l_ppe_offset, temp);
                }
            }

            l_cplt_offset = *((uint32_t*)i_ringSectionPtr + l_word);
            l_cplt_offset = myRev32(l_cplt_offset);
            l_word++;

            if(dbgl > 1)
            {
                printf("SBE(5):Offset 0x%08x size 0x%08x \n", l_cplt_offset, l_ppe_offset);
            }

            l_cplt_size = *((uint32_t*)i_ringSectionPtr + l_word );
            l_cplt_size = myRev32(l_cplt_size);

            if(l_sbeTorId == EC_CPLT && io_RingType == INSTANCE)
            {
                if(i_magic == P9_XIP_MAGIC_SEEPROM)
                {
                    l_cplt_size =  io_ringBlockSize -  (l_cplt_offset + l_ppe_cplt_offset);
                }
                else
                {
                    l_cplt_size =  l_ppe_offset -  (l_cplt_offset + l_ppe_cplt_offset);
                }
            }
            else
            {
                l_cplt_size =  l_cplt_size -  l_cplt_offset;
            }

            l_cplt_offset = l_cplt_offset + ddLevelOffset;

            if(dbgl > 1)
            {
                printf("SBE(6): Ring pointer Offset 0x%08x size 0x%08x \n", l_cplt_offset,
                       l_cplt_size);
            }
        }
        else if (i_PpeType == CME)
        {
            CmeTorId_t l_cmeTorId = CMEALL;

            switch (io_instanceId)
            {
                case 32:
                case 33:
                    l_cmeTorId = CME0_CPLT;
                    break;

                case 34:
                case 35:
                    l_cmeTorId = CME1_CPLT;
                    break;

                case 36:
                case 37:
                    l_cmeTorId = CME2_CPLT;
                    break;

                case 38:
                case 39:
                    l_cmeTorId = CME3_CPLT;
                    break;

                case 40:
                case 41:
                    l_cmeTorId = CME4_CPLT;
                    break;

                case 42:
                case 43:
                    l_cmeTorId = CME5_CPLT;
                    break;

                case 44:
                case 45:
                    l_cmeTorId = CME6_CPLT;
                    break;

                case 46:
                case 47:
                    l_cmeTorId = CME7_CPLT;
                    break;

                case 48:
                case 49:
                    l_cmeTorId = CME8_CPLT;
                    break;

                case 50:
                case 51:
                    l_cmeTorId = CME9_CPLT;
                    break;

                case 52:
                case 53:
                    l_cmeTorId = CME10_CPLT;
                    break;

                case 54:
                case 55:
                    l_cmeTorId = CME11_CPLT;
                    break;

                default :
                    printf("Not valid chiplet ID\n");
            }

            temp = (ddLevelOffset >> 2) + 2;
            int l_word;
            l_cplt_offset = *((uint32_t*)i_ringSectionPtr + temp);

            if(dbgl > 1)
            {
                printf("CME(1):ppe type Offset 0x%08x \n", l_cplt_offset);
            }

            l_cplt_offset = myRev32(l_cplt_offset);
            uint32_t l_ppe_cplt_offset  = l_cplt_offset;
            temp = temp + 2;
            l_ppe_offset  = *((uint32_t*)i_ringSectionPtr + temp);
            l_ppe_offset  = myRev32(l_ppe_offset);
            temp1 = l_cplt_offset;

            if(dbgl > 1)
            {
                printf("CME(2): Offsets 0x%08x  0x%08x 0x%08x \n", l_cplt_offset, l_ppe_offset,
                       temp);
            }

            if (io_RingType == COMMON)
            {
                temp  = l_cplt_offset + ddLevelOffset;
                l_word = temp >> 2;
                temp  = l_cplt_offset + ddLevelOffset;

                if(dbgl > 1)
                {
                    printf("CME(3):COMMON Offsets 0x%08x  0x%08x 0x%08x  \n", l_cplt_offset,
                           l_ppe_offset, temp);
                }
            }
            else
            {
                temp  = l_cplt_offset + ddLevelOffset + (l_cmeTorId * 4) + 4;
                l_word = temp >> 2;
                temp  = l_cplt_offset + ddLevelOffset;

                if(dbgl > 1)
                {
                    printf("CME(4):INSTANCE Offset 0x%08x  0x%08x 0x%08x 0x%08x \n", l_cplt_offset,
                           l_ppe_offset, l_ppe_cplt_offset, temp);
                }
            }

            l_cplt_offset = *((uint32_t*)i_ringSectionPtr + l_word);
            l_cplt_offset = myRev32(l_cplt_offset);
            l_word++;

            if(dbgl > 1)
            {
                printf("CME(5):Offset 0x%08x size 0x%08x \n", l_cplt_offset, l_ppe_offset);
            }

            l_cplt_size = *((uint32_t*)i_ringSectionPtr + l_word );
            l_cplt_size = myRev32(l_cplt_size);

            if(l_cmeTorId == CME11_CPLT && io_RingType == INSTANCE)
            {
                l_cplt_size =  l_ppe_offset -  (l_cplt_offset + l_ppe_cplt_offset);
            }
            else
            {
                l_cplt_size =  l_cplt_size -  l_cplt_offset;
            }

            l_cplt_offset = l_cplt_offset + ddLevelOffset;

            if(dbgl > 1)
            {
                printf("CME(6): Ring pointer Offset 0x%08x size 0x%08x \n", l_cplt_offset,
                       l_cplt_size);
            }
        }
        else if (i_PpeType == SGPE)
        {

            temp = (ddLevelOffset >> 2) + 4;
            int l_word;
            l_cplt_offset = *((uint32_t*)i_ringSectionPtr + temp);

            if(dbgl > 1)
            {
                printf("SGPE(1):Offset 0x%08x \n", l_cplt_offset);
            }

            l_cplt_offset = myRev32(l_cplt_offset);

            temp = temp + 1;
            l_ppe_offset  = *((uint32_t*)i_ringSectionPtr + temp);
            l_ppe_offset  = myRev32(l_ppe_offset);
            temp1 = l_cplt_offset;

            if(dbgl > 1)
            {
                printf("SGPE(2):Offset 0x%08x  0x%08x 0x%08x \n", l_cplt_offset, l_ppe_offset,
                       temp);
            }

            if (io_RingType == COMMON)
            {
                temp  = l_cplt_offset + ddLevelOffset;
                l_word = temp >> 2;
                temp  = l_cplt_offset + ddLevelOffset;

                if(dbgl > 1)
                {
                    printf("SGPE(3):COMMON Offset 0x%08x  0x%08x 0x%08x  \n", l_cplt_offset,
                           l_ppe_offset, temp);
                }
            }
            else
            {
                temp  = l_cplt_offset + ddLevelOffset + 4;
                l_word = temp >> 2;
                temp  = l_cplt_offset + ddLevelOffset;

                if(dbgl > 1)
                {
                    printf("SGPE(4):INSTANCE Offset 0x%08x  0x%08x 0x%08x  \n", l_cplt_offset,
                           l_ppe_offset, temp);
                }
            }

            l_cplt_offset = *((uint32_t*)i_ringSectionPtr + l_word);
            l_cplt_offset = myRev32(l_cplt_offset);
            l_word++;
            l_cplt_size = *((uint32_t*)i_ringSectionPtr + l_word );
            l_cplt_size = myRev32(l_cplt_size);

            if( io_RingType == INSTANCE)
            {
                l_cplt_size =  l_ppe_offset -  l_cplt_offset;
            }
            else
            {
                l_cplt_size =  l_cplt_size -  l_cplt_offset;
            }

            l_cplt_offset = l_cplt_offset + ddLevelOffset;

            if(dbgl > 1)
            {
                printf("SGPE(5): Ring pointer Offset 0x%08x size 0x%08x \n", l_cplt_offset,
                       l_cplt_size);
            }
        }

        if (io_ringBlockSize < l_cplt_size)
        {
            printf("\tio_ringBlockSize is less than required size ...\n");
            io_ringBlockSize =  l_cplt_size;
            return 0;
        }


        memcpy( (uint8_t*)(*io_ringBlockPtr),
                (uint8_t*)i_ringSectionPtr + l_cplt_offset + temp1,
                (size_t)l_cplt_size);
        io_ringBlockSize = l_cplt_size;
        return IMGBUILD_TGR_RING_BLOCKS_FOUND;
    }
    else
    {
        if(i_PpeType == SBE)
        {
            rc = get_ring_from_sbe_image ( i_ringSectionPtr,
                                           i_magic,
                                           i_ringId,
                                           ddLevelOffset,
                                           io_RingType,
                                           i_RingVariant,
                                           io_instanceId,
                                           i_RingBlockType,
                                           io_ringBlockPtr,
                                           io_ringBlockSize,
                                           o_ringName,
                                           dbgl);

            if (rc == IMGBUILD_TGR_RING_NOT_FOUND)
            {
                printf("\t After SBE single ring call, %s ring container is not found \n",
                       RING_PROPERTIES[i_ringId].iv_name);
                return rc;
            }
            else if ( rc == IMGBUILD_INVALID_INSTANCEID)
            {
                printf("\t After SBE single ring call, Instance %d is invalid \n",
                       io_instanceId );
                return rc;
            }

            if(dbgl > 1)
            {
                printf(" TOR_GET_RING(10): After get_ring_from_sbe_image Size %d \n",
                       io_ringBlockSize );
            }
        }
        else if (i_PpeType == CME)
        {
            rc =  get_ring_from_cme_image ( i_ringSectionPtr,
                                            i_ringId,
                                            ddLevelOffset,
                                            io_RingType,
                                            i_RingVariant,
                                            io_instanceId,
                                            i_RingBlockType,
                                            io_ringBlockPtr,
                                            io_ringBlockSize,
                                            o_ringName,
                                            dbgl);

            if (rc == IMGBUILD_TGR_RING_NOT_FOUND)
            {
                printf("\t After CME single ring call, %s ring container is not found \n",
                       RING_PROPERTIES[i_ringId].iv_name);
                return rc;
            }
            else if ( rc == IMGBUILD_INVALID_INSTANCEID)
            {
                printf("\t After CME single ring call, Instance %d is invalid \n",
                       io_instanceId );
                return rc;
            }

            if(dbgl > 1)
            {
                printf(" TOR_GET_RING(11): After get_ring_from_sbe_image Size %d \n",
                       io_ringBlockSize );
            }
        }
        else if (i_PpeType == SGPE)
        {
            rc =  get_ring_from_sgpe_image ( i_ringSectionPtr,
                                             i_ringId,
                                             ddLevelOffset,
                                             io_RingType,
                                             i_RingVariant,
                                             io_instanceId,
                                             i_RingBlockType,
                                             io_ringBlockPtr,
                                             io_ringBlockSize,
                                             o_ringName,
                                             dbgl);

            if (rc == IMGBUILD_TGR_RING_NOT_FOUND)
            {
                printf("\t After SGPE single ring call, %s ring container is not found \n",
                       RING_PROPERTIES[i_ringId].iv_name);
                return rc;
            }
            else if ( rc == IMGBUILD_INVALID_INSTANCEID)
            {
                printf("\t After SGPE single ring call, Instance %d is invalid \n",
                       io_instanceId );
                return rc;
            }

            if(dbgl > 1)
            {
                printf("TOR_GET_RING(12): After get_ring_from_sbe_image Size %d \n",
                       io_ringBlockSize );
            }
        }

        return IMGBUILD_TGR_RING_BLOCKS_FOUND;
    }

    return IMGBUILD_TGR_AMBIGUOUS_API_PARMS;
}

/////////////////////////////////////////////////////////////////////////////////////
//          Pulling single ring from ring section of HW image
/////////////////////////////////////////////////////////////////////////////////////

int tor_get_single_ring ( void*
                          i_ringSectionPt,  // ring section pointer
                          uint16_t      i_ddLevel,        // DD level info
                          RingID        i_ringId,         // Ring ID info
                          PpeType_t     i_PpeType,        // ppe Type info
                          RingVariant_t i_RingVariant,    // ring variant info -Base, CC, RL,OR,OL
                          uint8_t       i_instanceId,     // chiplet Instance Id
                          void**        io_ringBlockPtr,  // Output void pointer
                          uint32_t&     io_ringBlockSize  //  size of ring
                        )
{

    uint32_t rc;
    uint32_t dbgl = 1;
    char i_ringName[25];
    uint8_t l_instanceId = i_instanceId;
    RingType_t l_ringType;
    l_ringType = COMMON;


    if(dbgl > 1)
    {
        printf(" TOR_GET_SINGLE_RING1: function call \n");
    }

    rc = tor_get_ring(
             i_ringSectionPt,
             P9_XIP_MAGIC_HW,
             i_ringId,
             i_ddLevel,
             i_PpeType,
             l_ringType,
             i_RingVariant,
             l_instanceId,
             SINGLE_RING,
             io_ringBlockPtr,
             io_ringBlockSize,
             i_ringName );

    if(dbgl > 1)
    {
        printf(" TOR_GET_SINGLE_RING(2): after tor_get_ring function, Size %d \n",
               io_ringBlockSize );
    }

    return rc;
}
////////////////////////////////////////////////////////////////////////////////////////
//          Extract block of rings from ring section of HW image
///////////////////////////////////////////////////////////////////////////////////////


int tor_get_block_of_rings ( void*           i_ringSectionPt,
                             uint16_t        i_ddLevel,
                             PpeType_t       i_PpeType,
                             RingType_t      i_RingType,
                             RingVariant_t   i_RingVariant,
                             uint8_t         i_instanceId,
                             void**          io_ringBlockPtr,
                             uint32_t&       io_ringBlockSize
                           )
{
    uint32_t dbgl = 1;

    if(dbgl > 1)
    {
        printf(" TOR_GET_BLOCK_OF_RINGS(1): function call \n");
    }

    uint32_t rc = 0;
    char i_ringName[25];
    uint8_t l_instanceId  = i_instanceId;
    RingType_t l_ringType = i_RingType;

    if(l_ringType == ALLRING && i_PpeType != NUM_PPE_TYPES)
    {
        //ppe level copy
        rc = tor_get_ring( i_ringSectionPt,
                           P9_XIP_MAGIC_HW,
                           P9_NUM_RINGS,
                           i_ddLevel,
                           i_PpeType,
                           l_ringType,
                           i_RingVariant,
                           l_instanceId,
                           PPE_LEVEL_RINGS,
                           io_ringBlockPtr,
                           io_ringBlockSize,
                           i_ringName );

    }
    else if (l_ringType == ALLRING && i_PpeType == NUM_PPE_TYPES)
    {
        //dd level Copy
        rc = tor_get_ring( i_ringSectionPt,
                           P9_XIP_MAGIC_HW,
                           P9_NUM_RINGS,
                           i_ddLevel,
                           i_PpeType,
                           l_ringType,
                           i_RingVariant,
                           l_instanceId,
                           DD_LEVEL_RINGS,
                           io_ringBlockPtr,
                           io_ringBlockSize,
                           i_ringName );
    }
    else if(l_ringType == COMMON || l_ringType == INSTANCE)
    {
        // Chiplet level copy
        rc = tor_get_ring( i_ringSectionPt,
                           P9_XIP_MAGIC_HW,
                           P9_NUM_RINGS,
                           i_ddLevel,
                           i_PpeType,
                           l_ringType,
                           i_RingVariant,
                           l_instanceId,
                           CPLT_LEVEL_RINGS,
                           io_ringBlockPtr,
                           io_ringBlockSize,
                           i_ringName );
    }
    else
    {
        printf("TOR_GET_BLOCK_OF_RINGS(2): Wrong input params. Please check passing params\n");
        return IMGBUILD_TGR_AMBIGUOUS_API_PARMS;
    }

    if(dbgl > 1)
    {
        printf(" TOR_GET_SINGLE_RING(2): after tor_get_ring function, Size %d \n",
               io_ringBlockSize );
    }

    return rc;
}
