/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_tor.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#ifdef WIN32
    #include "endian.h"
#else
    #include <endian.h>
#endif

// IMPORTANT notice on usage of io_RingType and io_instanceId arguments
//
// io_RingTyp
// -------------
// While using tor_access_ring API, it is used as pass by reference
// While using tor_get_block_of_rings API, it is used as  pass by value
// io_instanceId
// --------------
// While using tor_access_ring API, it is used as pass by reference.
// While using tor_tor_get_block_of_rings and tor_get_single_ring API,
// it is used pass by value
//
#include "p9_tor.H"
namespace P9_RID
{
#include "p9_ringId.H"
}
namespace CEN_RID
{
#include "cen_ringId.H"
}
#include "p9_scan_compression.H"
#include "p9_infrastruct_help.H"


// These strings must adhere precisely to the enum of PpeType.
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


///////////////////////////////////////////////////////////////////////////////////
//
//                          GET RING FROM SBE IMAGE   FUNCTION
//
//////////////////////////////////////////////////////////////////////////////////
static
int get_ring_from_sbe_image( void*           i_ringSection,     // Ring section ptr
                             RingId_t        i_ringId,          // Ring ID
                             uint16_t        i_ddLevelOffset,   // DD level offset (wrt i_ringSection)
                             RingType_t&     io_RingType,       // Common, Instance
                             RingVariant_t   i_RingVariant,     // Base,CC, RL, Ovrd, Ovly
                             uint8_t&        io_instanceId,     // Instance ID
                             RingBlockType_t i_RingBlockType,   // Single ring, Block
                             void**          io_ringBlockPtr,   // Output ring buffer
                             uint32_t&       io_ringBlockSize,  // Size of ring data
                             char*           o_ringName,        // Name of ring
                             uint32_t        i_dbgl )           // Debug option
{
    int        rc = TOR_SUCCESS;
    uint32_t   torMagic = 0xffffffff;
    ChipType_t chipType = INVALID_CHIP_TYPE;
    uint32_t   tor_slot_no = 0; // TOR slot number (within a TOR chiplet section)
    uint16_t   dd_level_offset; // Local DD level offset, if any (wrt i_ringSection)
    uint32_t   acc_offset = 0;  // Accumulating offset to next TOR offset
    uint32_t   ppe_offset = 0;  // Local offset to where SBE PPE ring section starts
    uint32_t   ppe_cplt_offset = 0; // Local offset to where the pool of chiplets starts
    uint32_t   cplt_offset = 0; // Local offset to where a specific chiplet section starts
    uint16_t   ring_offset = 0; // Local offset to where SBE ring container/block starts
    uint32_t   ring_size = 0;   // Size of whole ring container/block.
    RingVariantOrder* ring_variant_order;
    GenRingIdList*    ring_id_list_common;
    GenRingIdList*    ring_id_list_instance;
    ChipletData_t*    l_cpltData;
    uint8_t           l_num_variant;
    ChipletType_t     numChiplets = 0;
    const RingProperties_t* ringProperties;

    torMagic = be32toh( ((TorHeader_t*)i_ringSection)->magic );
    chipType = ((TorHeader_t*)i_ringSection)->chipType;

    // Calculate the offset (wrt start of ringSection) to the SBE PPE
    //   ring section. This offset, ppe_offset, will point to the
    //   TORB header of the SBE PPE ring section.
    if (torMagic == TOR_MAGIC_HW)
    {
        dd_level_offset = i_ddLevelOffset;
        ppe_offset = *(uint32_t*)((uint8_t*)i_ringSection + dd_level_offset);
        ppe_offset = be32toh(ppe_offset);
        numChiplets = P9_RID::SBE_NOOF_CHIPLETS;
        ringProperties = &P9_RID::RING_PROPERTIES[0];
    }
    else if (torMagic == TOR_MAGIC_SBE  ||
             (torMagic == TOR_MAGIC_OVRD && (chipType == CT_P9N || chipType == CT_P9C)) ||
             torMagic == TOR_MAGIC_OVLY)
    {
        ppe_offset = 0;
        dd_level_offset = 0;
        numChiplets = P9_RID::SBE_NOOF_CHIPLETS;
        ringProperties = &P9_RID::RING_PROPERTIES[0];
    }
    else if (torMagic == TOR_MAGIC_CEN ||
             (torMagic == TOR_MAGIC_OVRD && chipType == CT_CEN))
    {
        ppe_offset = 0;
        dd_level_offset = 0;
        numChiplets = CEN_RID::CEN_NOOF_CHIPLETS;
        ringProperties = &CEN_RID::RING_PROPERTIES[0];
    }
    else
    {
        MY_ERR("torMagic=0x%08x is not valid for SBE\n", torMagic);
        return TOR_INVALID_MAGIC_NUMBER;
    }

    // Calculate the offset (wrt start of ringSection) to where the
    //   pool of chiplet offsets begins in the SBE PPE ring section,
    //   which is right after the TORB header.
    ppe_cplt_offset = ppe_offset + sizeof(TorHeader_t);

    // Looper for each SBE chiplet
    for (ChipletType_t iCplt = 0; iCplt < numChiplets; iCplt++)
    {
        if (torMagic == TOR_MAGIC_CEN ||
            (torMagic == TOR_MAGIC_OVRD && chipType == CT_CEN))
        {
            CEN_RID::ringid_get_chiplet_properties(
                iCplt,
                &l_cpltData,
                &ring_id_list_common,
                &ring_id_list_instance,
                &ring_variant_order,
                &l_num_variant);
        }
        else
        {
            P9_RID::ringid_get_chiplet_properties(
                iCplt,
                &l_cpltData,
                &ring_id_list_common,
                &ring_id_list_instance,
                &ring_variant_order,
                &l_num_variant);
        }

        if (!ring_id_list_common && !ring_id_list_instance)
        {
            MY_ERR("Chiplet=%d is not valid for SBE. \n", iCplt);
            return TOR_INVALID_CHIPLET;
        }

        l_num_variant = (torMagic == TOR_MAGIC_OVRD || torMagic == TOR_MAGIC_OVLY) ? 1 : l_num_variant;

        if (i_dbgl > 1)
        {
            MY_INF(" No of CommonRing %d, No of InstanceRing %d, No of Variants %d \n",
                   l_cpltData->iv_num_common_rings, l_cpltData->iv_num_instance_rings,
                   l_num_variant);
        }


        //
        // Sequentially walk the TOR slots within the chiplet's   COMMON   section
        //
        tor_slot_no = 0;

        for (uint8_t i = 0; i < l_cpltData->iv_num_common_rings ; i++)
        {
            for (uint8_t iVariant = 0; iVariant < l_num_variant ; iVariant++)
            {
                if (i_dbgl > 2)
                {
                    MY_INF(" Ring %s  Cplt common ring id %d  Variant id %d\n",
                           (ring_id_list_common + i)->ringName, i, iVariant);
                }

                if ( ( strcmp( (ring_id_list_common + i)->ringName,
                               ringProperties[i_ringId].iv_name) == 0 ) &&
                     ( i_RingVariant == ring_variant_order->variant[iVariant] ||
                       torMagic == TOR_MAGIC_OVRD ||
                       torMagic == TOR_MAGIC_OVLY ) )
                {
                    strcpy(o_ringName, ringProperties[i_ringId].iv_name);
                    acc_offset = dd_level_offset +
                                 ppe_cplt_offset +
                                 iCplt * sizeof(TorPpeBlock_t);
                    cplt_offset =  *(uint32_t*)( (uint8_t*)i_ringSection +
                                                 acc_offset );
                    cplt_offset = be32toh(cplt_offset);
                    acc_offset = dd_level_offset + ppe_cplt_offset + cplt_offset;
                    ring_offset = *(uint16_t*)( (uint8_t*)i_ringSection +
                                                acc_offset +
                                                tor_slot_no * sizeof(ring_offset) );
                    ring_offset = be16toh(ring_offset);

                    if (i_RingBlockType == GET_SINGLE_RING)
                    {
                        acc_offset = dd_level_offset +
                                     ppe_cplt_offset +
                                     cplt_offset +
                                     ring_offset;
                        ring_size = be16toh( ((CompressedScanData*)
                                              ((uint8_t*)i_ringSection + acc_offset))->iv_size );
                        io_RingType = COMMON_RING;

                        if (ring_offset)
                        {
                            if (io_ringBlockSize == 0)
                            {
                                if (i_dbgl > 0)
                                {
                                    MY_INF("\tio_ringBlockSize is zero. Returning required size.\n");
                                }

                                io_ringBlockSize =  ring_size;
                                return 0;
                            }

                            if (io_ringBlockSize < ring_size)
                            {
                                MY_ERR("\tio_ringBlockSize is less than required size.\n");
                                return TOR_BUFFER_TOO_SMALL;
                            }

                            if (i_dbgl > 0)
                            {
                                MY_INF(" Ring %s found in the SBE section \n", o_ringName);
                            }

                            memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSection + acc_offset,
                                    (size_t)ring_size);

                            io_ringBlockSize = ring_size;
                            io_instanceId = (ring_id_list_common + i)->instanceIdMin;

                            rc = TOR_RING_FOUND;
                        }
                        else
                        {
                            if (i_dbgl > 0)
                            {
                                MY_INF(" Ring %s not found in the SBE section \n", o_ringName);
                            }

                            rc = TOR_RING_NOT_FOUND;
                        }

                        if (i_dbgl > 0)
                        {
                            MY_INF(" Hex details (SBE) for Chiplet #%d: \n"
                                   "   DD number section's offset to DD level section = 0x%08x \n"
                                   "   DD level section's offset to PpeType = 0x%08x \n"
                                   "   PpeType section's offset to chiplet = 0x%08x \n"
                                   "   Chiplet section's offset to RS4 header = 0x%08x \n"
                                   "   Full offset to RS4 header = 0x%08x \n"
                                   "   Ring size = 0x%08x \n",
                                   i, dd_level_offset, ppe_cplt_offset, cplt_offset, ring_offset, acc_offset, ring_size);
                        }

                        return rc;

                    }
                    else if (i_RingBlockType == PUT_SINGLE_RING)
                    {
                        if (ring_offset)
                        {
                            MY_ERR("Ring container is already present in the SBE section \n");
                            return TOR_RING_AVAILABLE_IN_RINGSECTION;
                        }

                        // Special [mis]use of io_ringBlockPtr and io_ringBlockSize:
                        // Put location of chiplet's common section into ringBlockPtr
                        memcpy( (uint8_t*)(*io_ringBlockPtr), &acc_offset, sizeof(acc_offset));
                        // Put location of ring_offset slot into ringBlockSize
                        io_ringBlockSize = acc_offset + (tor_slot_no * sizeof(ring_offset));

                        return TOR_RING_FOUND;
                    }
                    else
                    {
                        MY_ERR("Ring block type (i_RingBlockType=%d) is not supported for SBE \n", i_RingBlockType);
                        return TOR_INVALID_RING_BLOCK_TYPE;
                    }
                }

                tor_slot_no++; // Next TOR slot
            }
        }


        //
        // Sequentially walk the TOR slots within the chiplet's   INSTANCE   section
        //
        if (ring_id_list_instance)
        {

            tor_slot_no = 0;

            for ( uint8_t i = (ring_id_list_instance + 0)->instanceIdMin;
                  i < (ring_id_list_instance + 0)->instanceIdMax + 1 ; i++ )
            {
                for (uint8_t j = 0; j < l_cpltData->iv_num_instance_rings; j++)
                {
                    for (uint8_t iVariant = 0; iVariant < l_num_variant ; iVariant++)
                    {
                        if (i_dbgl > 2)
                        {
                            MY_INF(" Ring name %s Cplt instance ring id %d Variant id %d Instance id %d\n",
                                   (ring_id_list_instance + j)->ringName, j, iVariant, i);
                        }

                        if (strcmp( (ring_id_list_instance + j)->ringName,
                                    ringProperties[i_ringId].iv_name) == 0)
                        {
                            if ( io_instanceId >=  (ring_id_list_instance + 0)->instanceIdMin
                                 &&  io_instanceId  <= (ring_id_list_instance + 0)->instanceIdMax )
                            {
                                if (i == io_instanceId && i_RingVariant == ring_variant_order->variant[iVariant])
                                {
                                    strcpy(o_ringName, ringProperties[i_ringId].iv_name);

                                    acc_offset = dd_level_offset +
                                                 ppe_cplt_offset +
                                                 iCplt * sizeof(TorPpeBlock_t) +
                                                 sizeof(cplt_offset); // Jump to instance offset
                                    cplt_offset =  *(uint32_t*)( (uint8_t*)i_ringSection +
                                                                 acc_offset );
                                    cplt_offset = be32toh(cplt_offset);

                                    acc_offset = cplt_offset +
                                                 dd_level_offset +
                                                 ppe_cplt_offset;
                                    ring_offset = *(uint16_t*)( (uint8_t*)i_ringSection +
                                                                acc_offset +
                                                                tor_slot_no * sizeof(ring_offset) );
                                    ring_offset = be16toh(ring_offset);

                                    if (i_RingBlockType == GET_SINGLE_RING)
                                    {
                                        acc_offset = dd_level_offset +
                                                     ppe_cplt_offset +
                                                     cplt_offset +
                                                     ring_offset;
                                        ring_size = be16toh( ((CompressedScanData*)
                                                              ((uint8_t*)i_ringSection +
                                                               acc_offset))->iv_size );
                                        io_RingType = INSTANCE_RING;

                                        if (ring_offset)
                                        {
                                            if (io_ringBlockSize == 0)
                                            {
                                                if (i_dbgl > 0)
                                                {
                                                    MY_INF("\tio_ringBlockSize is zero. Returning required size.\n");
                                                }

                                                io_ringBlockSize =  ring_size;
                                                return 0;
                                            }

                                            if (io_ringBlockSize < ring_size)
                                            {
                                                MY_ERR("\tio_ringBlockSize is less than required size.\n");
                                                return TOR_BUFFER_TOO_SMALL;
                                            }

                                            if (i_dbgl > 0)
                                            {
                                                MY_INF("   ring container of %s is found in the SBE image container \n",
                                                       o_ringName);
                                            }

                                            memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSection + acc_offset,
                                                    (size_t)ring_size);

                                            io_ringBlockSize = ring_size;

                                            if (i_dbgl > 0)
                                            {
                                                MY_INF(" After get_ring_from_sbe_image Size %d \n", io_ringBlockSize);
                                            }

                                            rc = TOR_RING_FOUND;
                                        }
                                        else
                                        {
                                            if (i_dbgl > 0)
                                            {
                                                MY_INF(" Ring %s not found in SBE section \n", o_ringName);
                                            }

                                            rc = TOR_RING_NOT_FOUND;
                                        }

                                        if (i_dbgl > 0)
                                        {
                                            MY_INF(" Hex details (SBE) for Chiplet #%d: \n"
                                                   "   DD number section's offset to DD level section = 0x%08x \n"
                                                   "   DD level section's offset to PpeType = 0x%08x \n"
                                                   "   PpeType section's offset to chiplet = 0x%08x \n"
                                                   "   Chiplet section's offset to RS4 header = 0x%08x \n"
                                                   "   Full offset to RS4 header = 0x%08x \n"
                                                   "   Ring size = 0x%08x \n",
                                                   i, dd_level_offset, ppe_cplt_offset, cplt_offset, ring_offset, acc_offset, ring_size);
                                        }

                                        return rc;
                                    }
                                    else if (i_RingBlockType == PUT_SINGLE_RING)
                                    {
                                        if (ring_offset)
                                        {
                                            MY_ERR("Ring container is already present in the SBE section \n");
                                            return TOR_RING_AVAILABLE_IN_RINGSECTION;
                                        }

                                        // Special [mis]use of io_ringBlockPtr and io_ringBlockSize:
                                        // Put location of chiplet's instance section into ringBlockPtr
                                        memcpy( (uint8_t*)(*io_ringBlockPtr), &acc_offset, sizeof(acc_offset));
                                        // Put location of ring_offset slot into ringBlockSize
                                        io_ringBlockSize = acc_offset + (tor_slot_no * sizeof(ring_offset));

                                        return TOR_RING_FOUND;
                                    }
                                    else
                                    {
                                        MY_ERR("Ring block type (i_RingBlockType=%d) is not supported for SBE \n", i_RingBlockType);
                                        return TOR_INVALID_RING_BLOCK_TYPE;
                                    }
                                }
                            }
                            else
                            {
                                if (i_dbgl > 0)
                                {
                                    MY_INF(" SBE ring instance ID %d is invalid, Valid ID is from %d  to %d  \n",
                                           io_instanceId, (ring_id_list_instance + 0)->instanceIdMin,
                                           (ring_id_list_instance + 0)->instanceIdMax);
                                }

                                return TOR_INVALID_INSTANCE_ID;
                            }
                        }

                        tor_slot_no++;
                    }
                }
            }
        } // if (ring_id_list_instance)
    }

    if (i_dbgl > 0)
    {
        MY_DBG("i_ringId=0x%x is an invalid ring ID for SBE\n", i_ringId);
    }

    return TOR_INVALID_RING_ID;

} // End of get_ring_from_sbe_image()



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                     GET RING FROM SGPE IMAGE   FUNCTION
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static
int get_ring_from_sgpe_image ( void*           i_ringSection,     // Ring section ptr
                               RingId_t        i_ringId,          // Ring ID
                               uint16_t        i_ddLevelOffset,   // DD level offset
                               RingType_t&     io_RingType,       // Common, Instance
                               RingVariant_t   i_RingVariant,     // Base,CC, RL, Ovrd, Ovly
                               uint8_t&        io_instanceId,     // Instance ID
                               RingBlockType_t i_RingBlockType,   // Single ring, Block
                               void**          io_ringBlockPtr,   // Output ring data buffer
                               uint32_t&       io_ringBlockSize,  // Size of ring data
                               char*           o_ringName,        // Name of ring
                               uint32_t        i_dbgl )           // Debug option
{
    uint32_t torMagic;
    uint32_t acc_offset = 0;   // Accumulating offset to next TOR offset slot
    uint32_t ring_offset = 0;
    uint16_t chiplet_offset = 0;
    uint32_t ringSize = 0;
    int temp = (i_ddLevelOffset >> 2) + 4;    // converting byte  to word counter
    uint32_t spge_offset = 0;
    uint32_t ppe_cplt_offset = 0; // Local offset to where the pool of chiplets starts

    torMagic = be32toh( ((TorHeader_t*)i_ringSection)->magic );

    // Calculate the offset (wrt start of ringSection) to the SGPE PPE
    //   ring section. This offset, inappropriately denoted "temp" here
    //   but which needs to be renamed to "ppe_offset" asap, will point
    //   to the TORG header of the SGPE PPE ring section.
    if (torMagic == TOR_MAGIC_HW)
    {
        spge_offset = *((uint32_t*)i_ringSection + temp);  //DD level offset index
        temp = be32toh(spge_offset);
    }
    else if (torMagic == TOR_MAGIC_SGPE)
    {
        spge_offset = 0;
        i_ddLevelOffset = 0;
        temp = be32toh(spge_offset);
    }
    else
    {
        MY_ERR("torMagic=0x%08x is not valid for SGPE\n", torMagic);
        return TOR_INVALID_MAGIC_NUMBER;
    }

    // Calculate the offset (wrt start of ringSection) to where the
    //   pool of chiplet offsets begins in the SGPE PPE ring section,
    //   which is right after the TORG header.
    ppe_cplt_offset = temp + sizeof(TorHeader_t);

    GenRingIdList* ring_id_list_common = NULL;
    GenRingIdList* ring_id_list_instance = NULL;
    uint8_t l_num_variant  = P9_RID::EQ::g_chipletData.iv_num_ring_variants;
    ring_id_list_common = (GenRingIdList*) P9_RID::EQ::RING_ID_LIST_COMMON;
    ring_id_list_instance = (GenRingIdList*) P9_RID::EQ::RING_ID_LIST_INSTANCE;

    uint32_t local = 0;

    for (uint8_t i = 0; i < P9_RID::EQ::g_chipletData.iv_num_common_rings ; i++)
    {
        for (uint8_t j = 0; j < l_num_variant ; j++)
        {
            if (i_dbgl > 2)
            {
                MY_INF(" Ring %s  Cplt common ring id %d  Variant id %d\n",
                       (ring_id_list_common + i)->ringName, i, j);
            }

            if ((strcmp( (ring_id_list_common + i)->ringName,
                         P9_RID::RING_PROPERTIES[i_ringId].iv_name) == 0) && ( i_RingVariant == j ))
            {
                strcpy(o_ringName, P9_RID::RING_PROPERTIES[i_ringId].iv_name);
                uint32_t var = 0 + i_ddLevelOffset + ppe_cplt_offset;
                int temp1 =  var / sizeof(uint32_t);
                ring_offset =  *((uint32_t*)i_ringSection + temp1);
                ring_offset = be32toh(ring_offset);
                var = ring_offset + i_ddLevelOffset + ppe_cplt_offset;
                temp1 = var / sizeof(uint16_t) + local;
                chiplet_offset  = *((uint16_t*)i_ringSection + temp1);
                chiplet_offset = be16toh(chiplet_offset);

                if (i_RingBlockType == GET_SINGLE_RING)
                {
                    var = ring_offset + chiplet_offset + i_ddLevelOffset + ppe_cplt_offset;
                    ringSize = be16toh( ((CompressedScanData*)
                                         ((uint8_t*)i_ringSection +
                                          var))->iv_size );
                    io_RingType = COMMON_RING;

                    if (chiplet_offset)
                    {
                        if (io_ringBlockSize == 0)
                        {
                            if (i_dbgl > 0)
                            {
                                MY_INF("\tio_ringBlockSize is zero. Returning required size.\n");
                            }

                            io_ringBlockSize =  ringSize;
                            return 0;
                        }

                        if (io_ringBlockSize < ringSize)
                        {
                            MY_ERR("\tio_ringBlockSize is less than required size.\n");
                            return TOR_BUFFER_TOO_SMALL;
                        }

                        if (i_dbgl > 0)
                        {
                            MY_INF(" Ring %s found in the SGPE section \n", o_ringName);
                        }

                        memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSection + var,
                                (size_t)ringSize);

                        io_ringBlockSize = ringSize;
                        io_instanceId = (ring_id_list_common + i)->instanceIdMin;

                        if (i_dbgl > 0)
                        {
                            MY_INF(" Hex details (SGPE):  Chiplet #%d offset 0x%08x  local offset 0x%08x  " \
                                   "ring offset 0x%08x  start adr 0x%08x  ringSize=0x%08x \n",
                                   i, var, ppe_cplt_offset, ring_offset, chiplet_offset, ringSize);
                        }

                        return TOR_RING_FOUND;
                    }
                    else
                    {
                        if (i_dbgl > 0)
                        {
                            MY_INF(" Ring %s not found in the SGPE section \n", o_ringName);
                        }

                        return TOR_RING_NOT_FOUND;
                    }
                }
                else if (i_RingBlockType == PUT_SINGLE_RING)
                {
                    if (chiplet_offset)
                    {
                        MY_ERR("Ring container is already present in the SGPE section \n");
                        return TOR_RING_AVAILABLE_IN_RINGSECTION;
                    }

                    acc_offset = var;
                    io_ringBlockSize =  acc_offset + (local * RING_OFFSET_SIZE);
                    memcpy( (uint8_t*)(*io_ringBlockPtr), &acc_offset, sizeof(acc_offset));

                    return TOR_RING_FOUND;
                }
                else
                {
                    MY_ERR("Ring block type (i_RingBlockType=%d) is not supported for SGPE \n", i_RingBlockType);
                    return TOR_INVALID_RING_BLOCK_TYPE;
                }
            }

            local++;
        }

    }

    // Instance specific single ring extract loop
    local = 0;

    for(uint8_t i = (ring_id_list_instance + 0)->instanceIdMin;
        i < (ring_id_list_instance + 0)->instanceIdMax + 1 ; i++)
    {
        for (uint8_t j = 0; j < P9_RID::EQ::g_chipletData.iv_num_instance_rings; j++)
        {
            for(uint8_t k = 0; k < l_num_variant ; k++)
            {
                if (i_dbgl > 2)
                {
                    MY_INF(" Ring name %s Cplt instance ring id %d Variant id %d",
                           (ring_id_list_instance + j)->ringName, j, k);
                }

                if  (strcmp( (ring_id_list_instance + j)->ringName,
                             P9_RID::RING_PROPERTIES[i_ringId].iv_name) == 0)
                {
                    if ( io_instanceId >=  (ring_id_list_instance + 0)->instanceIdMin
                         &&  io_instanceId  <= (ring_id_list_instance + 0)->instanceIdMax )
                    {
                        if ( i == io_instanceId && k == i_RingVariant )
                        {
                            strcpy(o_ringName, P9_RID::RING_PROPERTIES[i_ringId].iv_name);
                            uint32_t var = CPLT_OFFSET_SIZE + i_ddLevelOffset + ppe_cplt_offset;
                            int temp1 =  var / sizeof(uint32_t);
                            ring_offset =  *((uint32_t*)i_ringSection + temp1);
                            ring_offset = be32toh(ring_offset);
                            var = ring_offset + i_ddLevelOffset + ppe_cplt_offset;
                            temp1 = var / sizeof(uint16_t) + local;
                            chiplet_offset  = *((uint16_t*)i_ringSection + temp1);
                            chiplet_offset = be16toh(chiplet_offset);

                            if (i_RingBlockType == GET_SINGLE_RING)
                            {
                                var = ring_offset + chiplet_offset + i_ddLevelOffset + ppe_cplt_offset;
                                ringSize = be16toh( ((CompressedScanData*)
                                                     ((uint8_t*)i_ringSection +
                                                      var))->iv_size );
                                io_RingType = INSTANCE_RING;

                                if (chiplet_offset)
                                {
                                    if (io_ringBlockSize == 0)
                                    {
                                        if (i_dbgl > 0)
                                        {
                                            MY_INF("\tio_ringBlockSize is zero. Returning required size.\n");
                                        }

                                        io_ringBlockSize =  ringSize;
                                        return 0;
                                    }

                                    if (io_ringBlockSize < ringSize)
                                    {
                                        MY_ERR("\tio_ringBlockSize is less than required size.\n");
                                        return TOR_BUFFER_TOO_SMALL;
                                    }

                                    if (i_dbgl > 0)
                                    {
                                        MY_INF("   ring container of %s is found in the SGPE image container \n",
                                               o_ringName);
                                    }

                                    memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSection + var,
                                            (size_t)ringSize);

                                    io_ringBlockSize = ringSize;

                                    if (i_dbgl > 0)
                                    {
                                        MY_INF(" After get_ring_from_sgpe_image Size %d \n", io_ringBlockSize);
                                    }

                                    if (i_dbgl > 0)
                                    {
                                        MY_INF(" Hex details (SGPE):  Chiplet #%d offset 0x%08x  local offset 0x%08x  " \
                                               "ring offset 0x%08x  start adr 0x%08x  ringSize=0x%08x \n",
                                               i, var, ppe_cplt_offset, ring_offset, chiplet_offset, ringSize);
                                    }

                                    return TOR_RING_FOUND;
                                }
                                else
                                {
                                    if (i_dbgl > 0)
                                    {
                                        MY_INF("   ring container of %s is not found in the SGPE image container \n",
                                               o_ringName);
                                    }

                                    return TOR_RING_NOT_FOUND;
                                }
                            }
                            else if (i_RingBlockType == PUT_SINGLE_RING)
                            {
                                if (chiplet_offset)
                                {
                                    MY_ERR("Ring container is already present in the SGPE section \n");
                                    return TOR_RING_AVAILABLE_IN_RINGSECTION;
                                }

                                acc_offset = var;
                                io_ringBlockSize =  acc_offset + (local * RING_OFFSET_SIZE);
                                memcpy( (uint8_t*)(*io_ringBlockPtr), &acc_offset, sizeof(acc_offset));

                                return TOR_RING_FOUND;
                            }
                            else
                            {
                                MY_ERR("Ring block type (i_RingBlockType=%d) is not supported for SGPE \n", i_RingBlockType);
                                return TOR_INVALID_RING_BLOCK_TYPE;
                            }
                        }
                    }
                    else
                    {
                        if (i_dbgl > 0)
                        {
                            MY_INF("SGPE ring instance ID %d is invalid, Valid ID is from %d  to %d \n",
                                   io_instanceId, (ring_id_list_instance + 0)->instanceIdMin,
                                   (ring_id_list_instance + 0)->instanceIdMax);
                        }

                        return TOR_INVALID_INSTANCE_ID;
                    }
                }

                local++;
            }
        }
    }

    return TOR_INVALID_RING_ID;

} // End of get_ring_from_sgpe_image()



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                 GET RING FROM CME IMAGE   FUNCTION
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static
int get_ring_from_cme_image ( void*           i_ringSection,     // Ring section ptr
                              RingId_t        i_ringId,          // Ring ID
                              uint16_t        i_ddLevelOffset,   // DD level offset
                              RingType_t&     io_RingType,       // Common, Instance
                              RingVariant_t   i_RingVariant,     // Base,CC, RL, Ovrd, Ovly
                              uint8_t&        io_instanceId,     // instance ID
                              RingBlockType_t i_RingBlockType,   // Single ring, Block
                              void**          io_ringBlockPtr,   // Output ring data buffer
                              uint32_t&       io_ringBlockSize,  // Size of ring data
                              char*           o_ringName,        // Name of ring
                              uint32_t        i_dbgl )           // Debug option
{
    uint32_t torMagic;
    uint32_t acc_offset = 0;   // Accumulating offset to next TOR offset slot
    uint32_t ring_offset = 0;
    uint16_t chiplet_offset = 0;
    uint32_t ringSize = 0;
    int temp = (i_ddLevelOffset >> 2) + 2;  // converting byte  to word counter
    uint32_t cme_offset = 0;
    uint32_t ppe_cplt_offset = 0; // Local offset to where the pool of chiplets starts

    torMagic = be32toh( ((TorHeader_t*)i_ringSection)->magic );

    if (torMagic == TOR_MAGIC_HW)
    {
        cme_offset = *((uint32_t*)i_ringSection + temp);  //DD level offset index
        temp = be32toh(cme_offset);
    }
    else if (torMagic == TOR_MAGIC_CME)
    {
        cme_offset = 0;
        i_ddLevelOffset = 0;
        temp = be32toh(cme_offset);
    }
    else
    {
        MY_ERR("torMagic=0x%08x is not valid for CME\n", torMagic);
        return TOR_INVALID_MAGIC_NUMBER;
    }

    // Calculate the offset (wrt start of ringSection) to where the
    //   pool of chiplet offsets begins in the CME PPE ring section,
    //   which is right after the TORC header.
    ppe_cplt_offset = temp + sizeof(TorHeader_t);

    GenRingIdList* ring_id_list_common = NULL;
    GenRingIdList* ring_id_list_instance = NULL;
    uint8_t l_num_variant  = P9_RID::EC::g_chipletData.iv_num_ring_variants;
    ring_id_list_common = (GenRingIdList*) P9_RID::EC::RING_ID_LIST_COMMON;
    ring_id_list_instance = (GenRingIdList*) P9_RID::EC::RING_ID_LIST_INSTANCE;

    uint32_t local = 0;

    for (uint8_t i = 0; i < P9_RID::EC::g_chipletData.iv_num_common_rings ; i++)
    {
        for (uint8_t j = 0; j < l_num_variant ; j++)
        {
            if (i_dbgl > 2)
            {
                MY_INF(" Ring %s  Cplt common ring id %d  Variant id %d\n",
                       (ring_id_list_common + i)->ringName, i, j);
            }

            if ((strcmp( (ring_id_list_common + i)->ringName,
                         P9_RID::RING_PROPERTIES[i_ringId].iv_name) == 0) && ( i_RingVariant == j ))
            {
                strcpy(o_ringName, P9_RID::RING_PROPERTIES[i_ringId].iv_name);
                uint32_t var = 0 + i_ddLevelOffset + ppe_cplt_offset;
                int temp1 =  var / sizeof(uint32_t);
                ring_offset =  *((uint32_t*)i_ringSection + temp1);
                ring_offset = be32toh(ring_offset);
                var = ring_offset + i_ddLevelOffset + ppe_cplt_offset;
                temp1 = var / sizeof(uint16_t) + local;
                chiplet_offset  = *((uint16_t*)i_ringSection + temp1);
                chiplet_offset = be16toh(chiplet_offset);

                if (i_RingBlockType == GET_SINGLE_RING)
                {
                    var = ring_offset + chiplet_offset + i_ddLevelOffset + ppe_cplt_offset;
                    ringSize = be16toh( ((CompressedScanData*)
                                         ((uint8_t*)i_ringSection +
                                          var))->iv_size );
                    io_RingType = COMMON_RING;

                    if (chiplet_offset)
                    {
                        if (io_ringBlockSize == 0)
                        {
                            if (i_dbgl > 0)
                            {
                                MY_INF("\tio_ringBlockSize is zero. Returning required size.\n");
                            }

                            io_ringBlockSize =  ringSize;
                            return 0;
                        }

                        if (io_ringBlockSize < ringSize)
                        {
                            MY_ERR("\tio_ringBlockSize is less than required size.\n");
                            return TOR_BUFFER_TOO_SMALL;
                        }

                        if (i_dbgl > 0)
                        {
                            MY_INF(" Ring %s found in the CME section \n", o_ringName);
                        }

                        memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSection + var,
                                (size_t)ringSize);

                        io_ringBlockSize = ringSize;
                        io_instanceId = (ring_id_list_common + i)->instanceIdMin;

                        if (i_dbgl > 0)
                        {
                            MY_INF(" Hex details (CME):  Chiplet #%d offset 0x%08x  local offset 0x%08x  " \
                                   "ring offset 0x%08x  start adr 0x%08x  ringSize=0x%08x \n",
                                   i, var, ppe_cplt_offset, ring_offset, chiplet_offset, ringSize);
                        }

                        return TOR_RING_FOUND;
                    }
                    else
                    {
                        if (i_dbgl > 0)
                        {
                            MY_INF(" Ring %s not found in the CME section \n", o_ringName);
                        }

                        return TOR_RING_NOT_FOUND;
                    }
                }
                else if (i_RingBlockType == PUT_SINGLE_RING)
                {
                    if (chiplet_offset)
                    {
                        MY_ERR("Ring container is already present in the CME section \n");
                        return TOR_RING_AVAILABLE_IN_RINGSECTION;
                    }

                    acc_offset = var;
                    io_ringBlockSize =  acc_offset + (local * RING_OFFSET_SIZE);
                    memcpy( (uint8_t*)(*io_ringBlockPtr), &acc_offset, sizeof(acc_offset));

                    return TOR_RING_FOUND;
                }
                else
                {
                    MY_ERR("Ring block type (i_RingBlockType=%d) is not supported for CME \n", i_RingBlockType);
                    return TOR_INVALID_RING_BLOCK_TYPE;
                }
            }

            local++;
        }
    }

    // Instance specific single ring extract loop
    local = 0;

    for ( uint8_t i =  (ring_id_list_instance + 0)->instanceIdMin;
          i <= (ring_id_list_instance + 0)->instanceIdMax;
          i++ )
    {
        for (uint8_t j = 0; j < P9_RID::EC::g_chipletData.iv_num_instance_rings; j++)
        {
            for (uint8_t k = 0; k < l_num_variant ; k++)
            {
                if (i_dbgl > 2)
                {
                    MY_INF(" Ring name %s Cplt instance ring id %d Variant id %d",
                           (ring_id_list_instance + j)->ringName, j, k);
                }

                if (strcmp( (ring_id_list_instance + j)->ringName,
                            P9_RID::RING_PROPERTIES[i_ringId].iv_name) == 0)
                {
                    if ( io_instanceId >=  (ring_id_list_instance + 0)->instanceIdMin
                         &&  io_instanceId  <= (ring_id_list_instance + 0)->instanceIdMax )
                    {
                        if ( i == io_instanceId && k == i_RingVariant )
                        {
                            strcpy(o_ringName, P9_RID::RING_PROPERTIES[i_ringId].iv_name);
                            uint32_t var = i_ddLevelOffset + ppe_cplt_offset + CPLT_OFFSET_SIZE;
                            int temp1 =  var / CPLT_OFFSET_SIZE;
                            ring_offset =  *((uint32_t*)i_ringSection + temp1);
                            ring_offset = be32toh(ring_offset);
                            var = ring_offset + i_ddLevelOffset + ppe_cplt_offset;
                            temp1 = var / sizeof(uint16_t) + local;
                            chiplet_offset = *((uint16_t*)i_ringSection + temp1);
                            chiplet_offset = be16toh(chiplet_offset);

                            if (i_RingBlockType == GET_SINGLE_RING)
                            {
                                var = ring_offset + chiplet_offset + i_ddLevelOffset + ppe_cplt_offset;
                                ringSize = be16toh( ((CompressedScanData*)
                                                     ((uint8_t*)i_ringSection +
                                                      var))->iv_size );
                                io_RingType = INSTANCE_RING;

                                if (chiplet_offset)
                                {
                                    if (io_ringBlockSize == 0)
                                    {
                                        if (i_dbgl > 0)
                                        {
                                            MY_INF("\tio_ringBlockSize is zero. Returning required size.\n");
                                        }

                                        io_ringBlockSize =  ringSize;

                                        return TOR_SUCCESS;
                                    }

                                    if (io_ringBlockSize < ringSize)
                                    {
                                        MY_ERR("\tio_ringBlockSize is less than required size.\n");

                                        return TOR_BUFFER_TOO_SMALL;
                                    }

                                    if (i_dbgl > 0)
                                    {
                                        MY_INF(" Hex details (CME):  Chiplet #%d offset 0x%08x  local offset 0x%08x  " \
                                               "ring offset 0x%08x  start adr 0x%08x  ringSize=0x%08x \n",
                                               i, var, ppe_cplt_offset, ring_offset, chiplet_offset, ringSize);
                                    }

                                    memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSection + var,
                                            (size_t)ringSize);

                                    io_ringBlockSize = ringSize;

                                    if (i_dbgl > 0)
                                    {
                                        MY_INF(" After get_ring_from_cme_image Size %d \n", io_ringBlockSize);
                                    }

                                    return TOR_RING_FOUND;
                                }
                                else
                                {
                                    if (i_dbgl > 0)
                                    {
                                        MY_INF("   ring container of %s is not found in the CME image container \n",
                                               o_ringName);
                                    }

                                    return TOR_RING_NOT_FOUND;
                                }
                            }
                            else if (i_RingBlockType == PUT_SINGLE_RING)
                            {
                                if (chiplet_offset)
                                {
                                    MY_ERR("Ring container is already present in the CME section \n");

                                    return TOR_RING_AVAILABLE_IN_RINGSECTION;
                                }

                                acc_offset = var;
                                io_ringBlockSize =  acc_offset + (local * RING_OFFSET_SIZE);
                                memcpy( (uint8_t*)(*io_ringBlockPtr), &acc_offset, sizeof(acc_offset));

                                return TOR_RING_FOUND;
                            }
                            else
                            {
                                MY_ERR("Ring block type (i_RingBlockType=%d) is not supported for CME \n", i_RingBlockType);
                                return TOR_INVALID_RING_BLOCK_TYPE;
                            }
                        }
                    }
                    else
                    {
                        if (i_dbgl > 0)
                        {
                            MY_INF(" CME ring instance ID %d is invalid, Valid ID is from %d  to %d \n",
                                   io_instanceId, (ring_id_list_instance + 0)->instanceIdMin,
                                   (ring_id_list_instance + 0)->instanceIdMax);
                        }

                        return TOR_INVALID_INSTANCE_ID;
                    }
                }

                local++;
            }
        }
    }

    return TOR_INVALID_RING_ID;

} // End of get_ring_from_cme_image()



//////////////////////////////////////////////////////////////////////////////////////////
///
///                            TOR ACCESS RING   API
///
//////////////////////////////////////////////////////////////////////////////////////////
int tor_access_ring(  void*           i_ringSection,     // Ring section ptr
                      RingId_t        i_ringId,          // Ring ID
                      uint16_t        i_ddLevel,         // DD level
                      PpeType_t       i_PpeType,         // SBE, CME, SGPE
                      RingType_t&     io_RingType,       // Common, Instance
                      RingVariant_t   i_RingVariant,     // Base,CC, RL, Ovrd, Ovly
                      uint8_t&        io_instanceId,     // Instance ID
                      RingBlockType_t i_RingBlockType,   // Single ring, Block
                      void**          io_ringBlockPtr,   // Ring data buffer
                      uint32_t&       io_ringBlockSize,  // Size of ring data
                      char*           o_ringName,        // Ring name
                      uint32_t        i_dbgl )           // Debug option
{
    int rc = 0;
    uint32_t       torMagic;
    TorHeader_t*   torHeader;
    TorDdBlock_t*  torDdBlock;
    uint8_t  bDdCheck = 0;
    uint32_t ddLevelOffset = 0;
    uint32_t ddLevelCount = 0;
    uint32_t ddLevel = 0;
    uint32_t ddBlockSize = 0;
    uint32_t temp = 0;


    if (i_dbgl > 1)
    {
        MY_INF("Entering tor_access_ring()... \n");
    }

    torHeader = (TorHeader_t*)i_ringSection;
    torMagic = be32toh(torHeader->magic);

    if (torMagic == TOR_MAGIC_HW)
    {
        ddLevelCount = torHeader->numDdLevels;

        if (ddLevelCount > MAX_NOOF_DD_LEVELS_IN_IMAGE)
        {
            MY_ERR("Too many DD levels in image:\n"
                   "  ddLevelCount = %d\n"
                   "  Max no of DD levels = %d\n",
                   ddLevelCount, MAX_NOOF_DD_LEVELS_IN_IMAGE);

            return TOR_TOO_MANY_DD_LEVELS;
        }
        else if (i_dbgl > 1)
        {
            MY_INF("tor_access_ring(): No of DD levels: %d \n", ddLevelCount);
        }

        for (uint8_t i = 0; i < ddLevelCount; i++)
        {
            torDdBlock = (TorDdBlock_t*)( (uint8_t*)torHeader +
                                          sizeof(TorHeader_t) +
                                          i * sizeof(TorDdBlock_t) );
            ddLevel = torDdBlock->ddLevel;
            // Local ddLevelOffset
            ddLevelOffset = be32toh(torDdBlock->offset);

            if (i_dbgl > 1)
            {
                MY_INF( "tor_access_ring(): Local DD level offset: 0x%08x for DD level: 0x%x \n",
                        ddLevelOffset, ddLevel );
            }

            if ( ddLevel == i_ddLevel)
            {
                // Convert to global ddLevelOffset
                ddLevelOffset = ddLevelOffset +
                                sizeof(TorHeader_t);
                ddBlockSize = htobe32(torDdBlock->size);
                bDdCheck = 1;
                break;
            }
        }

        if (!bDdCheck)
        {
            MY_ERR("Input DD level not found and/or image indicates zero no of DD levels\n"
                   "  i_ddLevel = 0x%x\n"
                   "  ddLevelCount = %d\n",
                   i_ddLevel, ddLevelCount);

            return TOR_DD_LEVEL_NOT_FOUND;
        }
    }
    else if ( torMagic == TOR_MAGIC_SBE  ||
              torMagic == TOR_MAGIC_OVRD ||
              torMagic == TOR_MAGIC_OVLY ||
              torMagic == TOR_MAGIC_CEN )
    {
        if ( i_PpeType == PT_CME || i_PpeType == PT_SGPE
             || i_RingBlockType == GET_DD_LEVEL_RINGS
             || i_RingBlockType == GET_PPE_LEVEL_RINGS )
        {
            MY_ERR("Ambiguity on input PARMS for calling SEEPROM Ring copy API. \n");
            return TOR_AMBIGUOUS_API_PARMS;
        }
        else
        {
            ddLevelOffset = sizeof(TorHeader_t);
            ddBlockSize = 0;
        }
    }
    else if (torMagic == TOR_MAGIC_CME)
    {
        if ( i_PpeType == PT_SBE || i_PpeType == PT_SGPE
             || i_RingBlockType == GET_DD_LEVEL_RINGS
             || i_RingBlockType == GET_PPE_LEVEL_RINGS )
        {
            MY_ERR("Ambiguity on input PARMS for calling CME Ring copy API. \n");
            return TOR_AMBIGUOUS_API_PARMS;
        }
        else
        {
            ddLevelOffset = sizeof(TorHeader_t);
            ddBlockSize = 0;
        }
    }
    else if (torMagic == TOR_MAGIC_SGPE)
    {
        if ( i_PpeType == PT_SBE || i_PpeType == PT_CME
             || i_RingBlockType == GET_DD_LEVEL_RINGS
             || i_RingBlockType == GET_PPE_LEVEL_RINGS )
        {
            MY_ERR("Ambiguity on input PARMS for calling SGPE Ring copy API. \n");
            return TOR_AMBIGUOUS_API_PARMS;
        }
        else
        {
            ddLevelOffset = sizeof(TorHeader_t);
            ddBlockSize = 0;
        }
    }
    else
    {
        if (i_dbgl > 0)
        {
            MY_ERR("torMagic=0x%08x is not valid\n", torMagic);
        }

        return TOR_INVALID_MAGIC_NUMBER;
    }

    if (i_RingBlockType == GET_DD_LEVEL_RINGS)
    {
        if (io_ringBlockSize == 0)
        {
            if (i_dbgl > 0)
            {
                MY_INF("\tio_ringBlockSize is zero. Returning required size.\n");
            }

            io_ringBlockSize =  ddBlockSize;
            return 0;
        }

        if (io_ringBlockSize < ddBlockSize)
        {
            MY_ERR("\tio_ringBlockSize is less than required size.\n");
            return TOR_BUFFER_TOO_SMALL;
        }

        memcpy( (uint8_t*)(*io_ringBlockPtr),
                (uint8_t*)i_ringSection + ddLevelOffset, (size_t)ddBlockSize);

        if (i_dbgl > 1)
        {
            MY_INF( "TOR_ACCESS_RING(5): DD offset = %d  DD level = %d  DD block size = %d \n",
                    ddLevelOffset, ddLevel, ddBlockSize);
        }

        io_ringBlockSize =  ddBlockSize;

        return TOR_RING_FOUND;
    }
    else if (i_RingBlockType == GET_PPE_LEVEL_RINGS)
    {
        uint32_t l_ppe_offset = 0;
        uint32_t l_ppe_size   = 0;

        if (i_PpeType == PT_SBE)
        {
            temp = ddLevelOffset >> 2;

            if (i_dbgl > 1)
            {
                MY_INF( "TOR_ACCESS_RING(6): SBE PPE_LEVEL_RING COPY called ... \n");
            }

            l_ppe_offset = *((uint32_t*)i_ringSection + temp);
            l_ppe_offset = be32toh(l_ppe_offset);
            l_ppe_size = *((uint32_t*)i_ringSection + temp + 1 );
            l_ppe_size = be32toh(l_ppe_size);
        }
        else if (i_PpeType == PT_CME)
        {
            temp = (ddLevelOffset >> 2) + 2;

            if (i_dbgl > 1)
            {
                MY_INF( "TOR_ACCESS_RING(7): CME PPE_LEVEL_RING COPY called... \n");
            }

            l_ppe_offset = *((uint32_t*)i_ringSection + temp);
            l_ppe_offset = be32toh(l_ppe_offset);
            l_ppe_size = *((uint32_t*)i_ringSection + temp + 1 );
            l_ppe_size = be32toh(l_ppe_size);
        }
        else if (i_PpeType == PT_SGPE)
        {

            temp = (ddLevelOffset >> 2) + sizeof(uint32_t);

            if (i_dbgl > 1)
            {
                MY_INF( "TOR_ACCESS_RING(8): SPGE PPE_LEVEL_RING COPY called... \n");
            }

            l_ppe_offset = *((uint32_t*)i_ringSection + temp);
            l_ppe_offset = be32toh(l_ppe_offset);
            l_ppe_size = *((uint32_t*)i_ringSection + temp + 1 );
            l_ppe_size = be32toh(l_ppe_size);
        }

        if (io_ringBlockSize == 0)
        {
            if (i_dbgl > 0)
            {
                MY_INF("\tio_ringBlockSize is zero. Returning required size.\n");
            }

            io_ringBlockSize =  l_ppe_size;
            return 0;
        }

        if (io_ringBlockSize < l_ppe_size)
        {
            MY_ERR("\tio_ringBlockSize is less than required size.\n");
            return TOR_BUFFER_TOO_SMALL;
        }

        memcpy( (uint8_t*)(*io_ringBlockPtr),
                (uint8_t*)i_ringSection + l_ppe_offset + ddLevelOffset,
                (size_t)l_ppe_size);
        io_ringBlockSize = l_ppe_size;

        return TOR_RING_FOUND;
    }
    else if ( i_RingBlockType == GET_SINGLE_RING ||
              i_RingBlockType == PUT_SINGLE_RING )
    {
        if ( i_PpeType == PT_SBE &&
             ( torMagic == TOR_MAGIC_HW   ||
               torMagic == TOR_MAGIC_SBE  ||
               torMagic == TOR_MAGIC_OVRD ||
               torMagic == TOR_MAGIC_OVLY ||
               torMagic == TOR_MAGIC_CEN ) )
        {
            rc = get_ring_from_sbe_image( i_ringSection,
                                          i_ringId,
                                          ddLevelOffset,
                                          io_RingType,
                                          i_RingVariant,
                                          io_instanceId,
                                          i_RingBlockType,
                                          io_ringBlockPtr,
                                          io_ringBlockSize,
                                          o_ringName,
                                          i_dbgl );

            if (rc)
            {
                if (i_dbgl > 0)
                {
                    MY_ERR("get_ring_from_sbe_image failed w/rc=%d\n", rc);
                }

                return rc;
            }
            else
            {
                if (i_dbgl > 1)
                {
                    MY_INF(" TOR_ACCESS_RING(10): After get_ring_from_sbe_image Size %d \n",
                           io_ringBlockSize );
                }

                return TOR_RING_FOUND;
            }
        }
        else if ( i_PpeType == PT_CME &&
                  ( torMagic == TOR_MAGIC_HW ||
                    torMagic == TOR_MAGIC_CME ) )
        {
            rc =  get_ring_from_cme_image( i_ringSection,
                                           i_ringId,
                                           ddLevelOffset,
                                           io_RingType,
                                           i_RingVariant,
                                           io_instanceId,
                                           i_RingBlockType,
                                           io_ringBlockPtr,
                                           io_ringBlockSize,
                                           o_ringName,
                                           i_dbgl );

            if (rc == TOR_RING_NOT_FOUND)
            {
                if (i_dbgl > 0)
                {
                    MY_INF("\t After CME single ring call, %s ring container is not found \n",
                           P9_RID::RING_PROPERTIES[i_ringId].iv_name);
                }

                return rc;
            }
            else if (rc == TOR_INVALID_INSTANCE_ID)
            {
                if (i_dbgl > 0)
                {
                    MY_INF("\t After CME single ring call, Instance %d is invalid \n",
                           io_instanceId );
                }

                return rc;
            }
            else if (rc == TOR_RING_AVAILABLE_IN_RINGSECTION)
            {
                if (i_dbgl > 0)
                {
                    MY_INF("\t After CME single ring call, Ring container is available in the image \n");
                }

                return rc;
            }
            else if (rc == TOR_INVALID_RING_ID)
            {
                if (i_dbgl > 0)
                {
                    MY_INF("\t After CME single ring call, There is no TOR slot for %s %d\n",
                           P9_RID::RING_PROPERTIES[i_ringId].iv_name, i_ringId);
                }

                return rc;
            }
            else
            {
                if (i_dbgl > 1)
                {
                    MY_INF("TOR_ACCESS_RING(11): After get_ring_from_cme_image Size %d \n",
                           io_ringBlockSize );
                }

                return TOR_RING_FOUND;
            }
        }
        else if ( i_PpeType == PT_SGPE &&
                  ( torMagic == TOR_MAGIC_HW ||
                    torMagic == TOR_MAGIC_SGPE ) )
        {
            rc =  get_ring_from_sgpe_image( i_ringSection,
                                            i_ringId,
                                            ddLevelOffset,
                                            io_RingType,
                                            i_RingVariant,
                                            io_instanceId,
                                            i_RingBlockType,
                                            io_ringBlockPtr,
                                            io_ringBlockSize,
                                            o_ringName,
                                            i_dbgl );

            if (rc == TOR_RING_NOT_FOUND)
            {
                if (i_dbgl > 0)
                {
                    MY_INF("\t After SGPE single ring call, %s ring container is not found \n",
                           P9_RID::RING_PROPERTIES[i_ringId].iv_name);
                }

                return rc;
            }
            else if (rc == TOR_INVALID_INSTANCE_ID)
            {
                if (i_dbgl > 0)
                {
                    MY_INF("\t After SGPE single ring call, Instance %d is invalid \n",
                           io_instanceId );
                }

                return rc;
            }
            else if (rc == TOR_RING_AVAILABLE_IN_RINGSECTION)
            {
                if (i_dbgl > 0)
                {
                    MY_INF("\t After SGPE single ring call, Ring container is available in the image \n");
                }

                return rc;
            }
            else if (rc == TOR_INVALID_RING_ID)
            {
                if (i_dbgl > 0)
                {
                    MY_INF("\t After SGPE single ring call, There is no TOR slot for %s %d\n",
                           P9_RID::RING_PROPERTIES[i_ringId].iv_name, i_ringId);
                }

                return rc;
            }
            else
            {
                if (i_dbgl > 1)
                {
                    MY_INF("TOR_ACCESS_RING(12): After get_ring_from_sgpe_image Size %d \n",
                           io_ringBlockSize );
                }

                return TOR_RING_FOUND;
            }
        }
        else
        {
            if (i_dbgl > 0)
            {
                MY_ERR("\t Unsupported combination of i_PpeType=%d and torMagic=0x%08x\n",
                       i_PpeType, torMagic);
            }

            return TOR_AMBIGUOUS_API_PARMS;
        }

    }
    else
    {
        MY_ERR("\t RingBlockType=0x%x is not supported. Caller error.\n",
               i_RingBlockType);

        return TOR_INVALID_RING_BLOCK_TYPE;
    }

    return TOR_AMBIGUOUS_API_PARMS;

} // End of tor_access_ring()



/////////////////////////////////////////////////////////////////////////////////////
//
//                             TOR GET SINGLE RING   API
//
/////////////////////////////////////////////////////////////////////////////////////
int tor_get_single_ring ( void*         i_ringSection,     // Ring section ptr
                          uint16_t      i_ddLevel,         // DD level
                          RingId_t      i_ringId,          // Ring ID
                          PpeType_t     i_PpeType,         // SBE, CME, SGPE
                          RingVariant_t i_RingVariant,     // Base,CC, RL, Ovrd, Ovly
                          uint8_t       i_instanceId,      // Instance ID
                          void**        io_ringBlockPtr,   // Output ring buffer
                          uint32_t&     io_ringBlockSize,  // Size of ring data
                          uint32_t      i_dbgl )           // Debug option
{

    uint32_t rc;
    char i_ringName[25];
    //@FIXME: This should really be ALLRING. But it's not used as input.
    RingType_t l_ringType;
    l_ringType = COMMON_RING;

    if (i_dbgl > 1)
    {
        MY_INF(" TOR_GET_SINGLE_RING1: function call \n");
    }

    rc = tor_access_ring( i_ringSection,
                          i_ringId,
                          i_ddLevel,
                          i_PpeType,
                          l_ringType,
                          i_RingVariant,
                          i_instanceId,
                          GET_SINGLE_RING,
                          io_ringBlockPtr,
                          io_ringBlockSize,
                          i_ringName,
                          i_dbgl );

    if (i_dbgl > 1)
    {
        MY_INF(" TOR_GET_SINGLE_RING(2): after tor_access_ring function, Size %d \n",
               io_ringBlockSize );
    }

    return rc;
}



////////////////////////////////////////////////////////////////////////////////////////
//
//                            TOR GET BLOCK OF RINGS   API
//
///////////////////////////////////////////////////////////////////////////////////////
int tor_get_block_of_rings ( void*           i_ringSection,     // Ring section ptr
                             uint16_t        i_ddLevel,         // DD level
                             PpeType_t       i_PpeType,         // SBE,CME,SGPE
                             RingType_t      i_ringType,        // Common, Instance
                             RingVariant_t   i_RingVariant,     // Base,CC, RL, Ovrd, Ovly
                             uint8_t         i_instanceId,      // Instance ID
                             void**          io_ringBlockPtr,   // Output ring buffer
                             uint32_t&       io_ringBlockSize,  // Size of ring data
                             uint32_t        i_dbgl )           // Debug option
{
    if (i_dbgl > 1)
    {
        MY_INF(" TOR_GET_BLOCK_OF_RINGS(1): function call \n");
    }

    uint32_t rc = 0;
    char i_ringName[25];

    if (i_ringType == ALLRING && i_PpeType != NUM_PPE_TYPES)
    {
        // Get block of rings specific to a PPE type
        rc = tor_access_ring( i_ringSection,
                              P9_RID::NUM_RING_IDS,
                              i_ddLevel,
                              i_PpeType,
                              i_ringType,
                              i_RingVariant,
                              i_instanceId,
                              GET_PPE_LEVEL_RINGS,
                              io_ringBlockPtr,
                              io_ringBlockSize,
                              i_ringName,
                              i_dbgl );

    }
    else if (i_ringType == ALLRING && i_PpeType == NUM_PPE_TYPES)
    {
        // Get DD level block of rings
        rc = tor_access_ring( i_ringSection,
                              P9_RID::NUM_RING_IDS,
                              i_ddLevel,
                              i_PpeType,
                              i_ringType,
                              i_RingVariant,
                              i_instanceId,
                              GET_DD_LEVEL_RINGS,
                              io_ringBlockPtr,
                              io_ringBlockSize,
                              i_ringName,
                              i_dbgl );
    }
    else
    {
        MY_ERR("TOR_GET_BLOCK_OF_RINGS(2): Wrong input params. Please check passing params\n");
        return TOR_AMBIGUOUS_API_PARMS;
    }

    if (i_dbgl > 1)
    {
        MY_INF(" TOR_GET_SINGLE_RING(2): after tor_access_ring function, Size %d \n",
               io_ringBlockSize );
    }

    return rc;
}



////////////////////////////////////////////////////////////////////////////////////////
//
//                             TOR APPEND RING   API
//
///////////////////////////////////////////////////////////////////////////////////////
int tor_append_ring(  void*           i_ringSection,      // Ring section ptr
                      uint32_t&       io_ringSectionSize, // In: Exact size of ring section.
                      // Out: Updated size of ring section.
                      void*           i_ringBuffer,       // Ring work buffer
                      const uint32_t  i_ringBufferSize,   // Max size of ring work buffer
                      RingId_t        i_ringId,           // Ring ID
                      PpeType_t       i_PpeType,          // SBE, CME, SGPE
                      RingType_t      i_RingType,         // Common, Instance
                      RingVariant_t   i_RingVariant,      // Base,CC, RL, Ovrd, Ovly
                      uint8_t         i_instanceId,       // Instance ID
                      void*           i_rs4Container,     // RS4 ring container
                      uint32_t        i_dbgl )            // Debug option
{
    uint32_t   rc = 0;
    char       i_ringName[25];
    uint32_t   l_buf = 0;
    uint32_t*  l_cpltSection = &l_buf;
    uint32_t   l_ringBlockSize;
    uint16_t   l_ringOffset16;
    uint32_t   l_torOffsetSlot;

    rc = tor_access_ring( i_ringSection,
                          i_ringId,
                          0x00,
                          i_PpeType,
                          i_RingType,
                          i_RingVariant,
                          i_instanceId,
                          PUT_SINGLE_RING,
                          (void**)&l_cpltSection, // On return, contains offset (wrt ringSection) of
                          // chiplet section's common or instance section
                          l_torOffsetSlot,        // On return, contains offset (wrt ringSection) of
                          // TOR offset slot
                          i_ringName,
                          i_dbgl);

    if (rc)
    {
        if (i_dbgl > 0)
        {
            MY_ERR("tor_append_ring() failed in call to tor_access_ring w/rc=0x%x \n", rc);
        }

        return rc;
    }

    if (i_dbgl > 1)
    {
        MY_INF(" TOR offset slot for ring address %d \n", l_torOffsetSlot );
    }

    // Explanation to the following:
    // tor_append_ring() appends a ring to the end of ringSection. The offset value to
    // that ring is wrt the beginning of the chiplet's TOR section. Below we calculate
    // the offset value and put it into the TOR slot. But first, check that the offset
    // value can be contained within the 2B of the TOR slot.
    if ( (io_ringSectionSize - *l_cpltSection) <= MAX_TOR_RING_OFFSET )
    {
        l_ringOffset16 = htobe16(io_ringSectionSize - *l_cpltSection);
        memcpy( (uint8_t*)i_ringSection + l_torOffsetSlot,
                &l_ringOffset16, sizeof(l_ringOffset16) );
    }
    else
    {
        MY_ERR("Code bug: TOR ring offset (=0x%x) exceeds MAX_TOR_RING_OFFSET (=0x%x)",
               io_ringSectionSize - *l_cpltSection, MAX_TOR_RING_OFFSET);
        return TOR_OFFSET_TOO_BIG;
    }

    // Now append the ring to the end of ringSection.
    l_ringBlockSize = be16toh( ((CompressedScanData*)i_rs4Container)->iv_size );
    memcpy( (uint8_t*)i_ringSection + io_ringSectionSize,
            (uint8_t*)i_rs4Container, (size_t)l_ringBlockSize);

    // Update the ringSectionSize
    io_ringSectionSize += l_ringBlockSize;

    // Update also the size in the TOR header
    TorHeader_t* torHeader = (TorHeader_t*)i_ringSection;
    torHeader->size = htobe32(be32toh(torHeader->size) + l_ringBlockSize);

    return TOR_SUCCESS;
}


//
// Inform caller of TOR version.
//
uint8_t tor_version( void)
{
    return (uint8_t)TOR_VERSION;
}
