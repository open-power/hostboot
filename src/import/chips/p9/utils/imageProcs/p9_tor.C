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
#include <endian.h>
#include "p9_ringId.H"
#include "p9_tor.H"
#include "p9_xip_image.h"
#include "p9_scan_compression.H"
#include "p9_infrastruct_help.H"

namespace P9_TOR
{

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
                             uint64_t        i_magic,           // Image Magic Number
                             RingID          i_ringId,          // Ring ID
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
    int      rc = TOR_SUCCESS;
    RingVariantOrder* ring_variant_order = NULL;
    uint32_t tor_slot_no = 0; // TOR slot number (within a TOR chiplet section)
    uint16_t dd_level_offset; // Local DD level offset, if any (wrt i_ringSection)
    uint32_t acc_offset = 0;  // Accumulating offset to next TOR offset
    uint32_t ppe_offset = 0;  // Local offset to where SBE PPE section starts
    uint32_t cplt_offset = 0; // Local offset to where SBE chiplet section starts
    uint16_t ring_offset = 0; // Local offset to where SBE ring container/block starts
    uint32_t ring_size = 0;   // Size of whole ring container/block.

    if (i_magic == P9_XIP_MAGIC_HW)
    {
        dd_level_offset = i_ddLevelOffset;
        ppe_offset = *(uint32_t*)((uint8_t*)i_ringSection + dd_level_offset);
        ppe_offset = htobe32(ppe_offset);
    }
    else if (i_magic == P9_XIP_MAGIC_SEEPROM)
    {
        ppe_offset = 0;
        dd_level_offset = 0;
        ppe_offset = htobe32(ppe_offset);
    }
    else
    {
        MY_ERR("Magic number i_magic=0x%016lX is not valid for SBE\n", (uintptr_t)i_magic);
        return TOR_INVALID_MAGIC_NUMBER;
    }

    // Looper for each SBE chiplet
    for(int iCplt = 0; iCplt < SBE_NOOF_CHIPLETS; iCplt++)
    {
        GenRingIdList* ring_id_list_common = NULL;
        GenRingIdList* ring_id_list_instance = NULL;
        CHIPLET_DATA  l_cpltData;
        uint8_t l_num_variant = 1;

        switch (iCplt)
        {
            case PERV_CPLT :
                l_cpltData  =  PERV::g_pervData;
                l_num_variant  = (uint8_t)sizeof(PERV::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) PERV::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) PERV::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) PERV::RING_VARIANT_ORDER;
                break;

            case N0_CPLT :
                l_cpltData  =     N0::g_n0Data;
                l_num_variant  = (uint8_t)sizeof(N0::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) N0::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) N0::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) N0::RING_VARIANT_ORDER;
                break;

            case N1_CPLT :
                l_cpltData =   N1::g_n1Data;
                l_num_variant  = (uint8_t)sizeof(N1::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) N1::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) N1::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) N1::RING_VARIANT_ORDER;
                break;

            case N2_CPLT :
                l_cpltData  =    N2::g_n2Data;
                l_num_variant  = (uint8_t)sizeof(N2::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) N2::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) N2::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) N2::RING_VARIANT_ORDER;
                break;

            case N3_CPLT :
                l_cpltData =   N3::g_n3Data;
                l_num_variant  = (uint8_t)sizeof(N3::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) N3::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) N3::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) N3::RING_VARIANT_ORDER;
                break;

            case XB_CPLT :
                l_cpltData = XB::g_xbData;
                l_num_variant  = (uint8_t)sizeof(XB::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) XB::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) XB::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) XB::RING_VARIANT_ORDER;
                break;

            case MC_CPLT :
                l_cpltData = MC::g_mcData;
                l_num_variant  = (uint8_t)sizeof(MC::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) MC::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) MC::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) MC::RING_VARIANT_ORDER;
                break;

            case OB0_CPLT :
                l_cpltData  = OB0::g_ob0Data;
                l_num_variant  = (uint8_t)sizeof(OB0::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) OB0::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) OB0::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) OB0::RING_VARIANT_ORDER;
                break;

            case OB1_CPLT :
                l_cpltData  = OB1::g_ob1Data;
                l_num_variant  = (uint8_t)sizeof(OB1::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) OB1::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) OB1::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) OB1::RING_VARIANT_ORDER;
                break;

            case OB2_CPLT :
                l_cpltData  = OB2::g_ob2Data;
                l_num_variant  = (uint8_t)sizeof(OB2::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) OB2::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) OB2::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) OB2::RING_VARIANT_ORDER;
                break;

            case OB3_CPLT :
                l_cpltData  = OB3::g_ob3Data;
                l_num_variant  = (uint8_t)sizeof(OB3::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) OB3::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) OB3::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) OB3::RING_VARIANT_ORDER;
                break;

            case PCI0_CPLT :
                l_cpltData  =  PCI0::g_pci0Data;
                l_num_variant  = (uint8_t)sizeof(PCI0::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) PCI0::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) PCI0::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) PCI0::RING_VARIANT_ORDER;
                break;

            case PCI1_CPLT :
                l_cpltData =  PCI1::g_pci1Data;
                l_num_variant  = (uint8_t)sizeof(PCI1::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) PCI1::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) PCI1::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) PCI1::RING_VARIANT_ORDER;
                break;

            case PCI2_CPLT :
                l_cpltData =  PCI2::g_pci2Data;
                l_num_variant  = (uint8_t)sizeof(PCI2::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) PCI2::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) PCI2::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) PCI2::RING_VARIANT_ORDER;
                break;

            case EQ_CPLT :
                l_cpltData  =  EQ::g_eqData;
                l_num_variant  = (uint8_t)sizeof(EQ::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) EQ::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) EQ::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) EQ::RING_VARIANT_ORDER;
                break;

            case EC_CPLT :
                l_cpltData =  EC::g_ecData;
                l_num_variant  = (uint8_t)sizeof(EC::RingVariants) / sizeof(uint16_t);
                ring_id_list_common = (GenRingIdList*) EC::RING_ID_LIST_COMMON;
                ring_id_list_instance = (GenRingIdList*) EC::RING_ID_LIST_INSTANCE;
                ring_variant_order    = (RingVariantOrder*) EC::RING_VARIANT_ORDER;
                break;

            default :
                MY_ERR("Chiplet=%d is not valid for SBE. \n", iCplt);
                return TOR_INVALID_CHIPLET;
        }

        l_num_variant = (i_RingVariant == OVERRIDE) ? 1 : l_num_variant;

        if (i_dbgl > 1)
        {
            MY_INF(" No of CommonRing %d, No of InstanceRing %d, No of Variants %d \n",
                   l_cpltData.iv_num_common_rings, l_cpltData.iv_num_instance_rings,
                   l_num_variant);
        }


        //
        // Sequentially walk the TOR slots within the chiplet's   COMMON   section
        //
        tor_slot_no = 0;

        for (uint8_t i = 0; i < l_cpltData.iv_num_common_rings ; i++)
        {
            for (uint8_t iVariant = 0; iVariant < l_num_variant ; iVariant++)
            {
                if (i_dbgl > 2)
                {
                    MY_INF(" Ring %s  Cplt common ring id %d  Variant id %d\n",
                           (ring_id_list_common + i)->ringName, i, iVariant);
                }

                if ((strcmp( (ring_id_list_common + i)->ringName,
                             RING_PROPERTIES[i_ringId].iv_name) == 0)
                    && ( i_RingVariant == ring_variant_order->variant[iVariant]
                         || (i_RingVariant == OVERRIDE && i_magic == P9_XIP_MAGIC_SEEPROM)))
                {
                    strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);

                    acc_offset = dd_level_offset + ppe_offset + iCplt * sizeof(TorPpeBlock_t);
                    cplt_offset =  *(uint32_t*)( (uint8_t*)i_ringSection +
                                                 acc_offset );
                    cplt_offset = htobe32(cplt_offset);

                    acc_offset = dd_level_offset + ppe_offset + cplt_offset;
                    ring_offset = *(uint16_t*)( (uint8_t*)i_ringSection +
                                                acc_offset +
                                                tor_slot_no * sizeof(ring_offset) );
                    ring_offset = htobe16(ring_offset);

                    if (i_RingBlockType == GET_SINGLE_RING)
                    {
                        acc_offset = dd_level_offset +
                                     ppe_offset +
                                     cplt_offset +
                                     ring_offset;
                        ring_size = htobe16( ((CompressedScanData*)
                                              ((uint8_t*)i_ringSection + acc_offset))->iv_size );
                        io_RingType = COMMON;

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
                                   i, dd_level_offset, ppe_offset, cplt_offset, ring_offset, acc_offset, ring_size);
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
        tor_slot_no = 0;

        for ( uint8_t i = (ring_id_list_instance + 0)->instanceIdMin;
              i < (ring_id_list_instance + 0)->instanceIdMax + 1 ; i++ )
        {
            for (uint8_t j = 0; j < l_cpltData.iv_num_instance_rings; j++)
            {
                for (uint8_t iVariant = 0; iVariant < l_num_variant ; iVariant++)
                {
                    if (i_dbgl > 2)
                    {
                        MY_INF(" Ring name %s Cplt instance ring id %d Variant id %d Instance id %d\n",
                               (ring_id_list_instance + j)->ringName, j, iVariant, i);
                    }

                    if (strcmp( (ring_id_list_instance + j)->ringName,
                                RING_PROPERTIES[i_ringId].iv_name) == 0)
                    {
                        if ( io_instanceId >=  (ring_id_list_instance + 0)->instanceIdMin
                             &&  io_instanceId  <= (ring_id_list_instance + 0)->instanceIdMax )
                        {
                            if (i == io_instanceId && i_RingVariant == ring_variant_order->variant[iVariant])
                            {
                                strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);

                                acc_offset = dd_level_offset +
                                             ppe_offset +
                                             iCplt * sizeof(TorPpeBlock_t) +
                                             sizeof(cplt_offset); // Jump to instance offset
                                cplt_offset =  *(uint32_t*)( (uint8_t*)i_ringSection +
                                                             acc_offset );
                                cplt_offset = htobe32(cplt_offset);

                                acc_offset = cplt_offset + dd_level_offset + ppe_offset;
                                ring_offset = *(uint16_t*)( (uint8_t*)i_ringSection +
                                                            acc_offset +
                                                            tor_slot_no * sizeof(ring_offset) );
                                ring_offset = htobe16(ring_offset);

                                if (i_RingBlockType == GET_SINGLE_RING)
                                {
                                    acc_offset = dd_level_offset +
                                                 ppe_offset +
                                                 cplt_offset +
                                                 ring_offset;
                                    ring_size = htobe16( ((CompressedScanData*)
                                                          ((uint8_t*)i_ringSection +
                                                           acc_offset))->iv_size );
                                    io_RingType = INSTANCE;

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
                                               i, dd_level_offset, ppe_offset, cplt_offset, ring_offset, acc_offset, ring_size);
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
                            MY_ERR(" SBE ring instance ID %d is invalid, Valid ID is from %d  to %d  \n",
                                   io_instanceId, (ring_id_list_instance + 0)->instanceIdMin,
                                   (ring_id_list_instance + 0)->instanceIdMax);

                            return TOR_INVALID_INSTANCE_ID;
                        }
                    }

                    tor_slot_no++;
                }
            }
        }
    }

    MY_ERR("i_ringId=0x%x is an invalid ring ID for SBE", i_ringId);

    return TOR_INVALID_RING_ID;

} // End of get_ring_from_sbe_image()



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                     GET RING FROM SGPE IMAGE   FUNCTION
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static
int get_ring_from_sgpe_image ( void*           i_ringSection,     // Ring section ptr
                               uint64_t        i_magic,           // Image Magic Number
                               RingID          i_ringId,          // Ring ID
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
    uint32_t acc_offset = 0;   // Accumulating offset to next TOR offset slot
    uint32_t ring_offset = 0;
    uint16_t chiplet_offset = 0;
    uint32_t ringSize = 0;
    int temp = (i_ddLevelOffset >> 2) + 4;    // converting byte  to word counter
    uint32_t spge_offset = 0;

    if (i_magic == P9_XIP_MAGIC_HW)
    {
        spge_offset = *((uint32_t*)i_ringSection + temp);  //DD level offset index
        temp = htobe32(spge_offset);
    }
    else if (i_magic == P9_XIP_MAGIC_SGPE)
    {
        spge_offset = 0;
        i_ddLevelOffset = 0;
        temp = htobe32(spge_offset);
    }

    GenRingIdList* ring_id_list_common = NULL;
    GenRingIdList* ring_id_list_instance = NULL;
    uint8_t l_num_variant  = (uint8_t)sizeof(EQ::RingVariants) / sizeof(uint16_t);
    ring_id_list_common = (GenRingIdList*) EQ::RING_ID_LIST_COMMON;
    ring_id_list_instance = (GenRingIdList*) EQ::RING_ID_LIST_INSTANCE;

    uint32_t local = 0;

    for (uint8_t i = 0; i < EQ::g_eqData.iv_num_common_rings ; i++)
    {
        for (uint8_t j = 0; j < l_num_variant ; j++)
        {
            if (i_dbgl > 2)
            {
                MY_INF(" Ring %s  Cplt common ring id %d  Variant id %d\n",
                       (ring_id_list_common + i)->ringName, i, j);
            }

            if ((strcmp( (ring_id_list_common + i)->ringName,
                         RING_PROPERTIES[i_ringId].iv_name) == 0) && ( i_RingVariant == j ))
            {
                strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);
                uint32_t var = 0 + i_ddLevelOffset + temp;
                int temp1 =  var / sizeof(uint32_t);
                ring_offset =  *((uint32_t*)i_ringSection + temp1);
                ring_offset = htobe32(ring_offset);
                var = ring_offset + i_ddLevelOffset + temp;
                temp1 = var / sizeof(uint16_t) + local;
                chiplet_offset  = *((uint16_t*)i_ringSection + temp1);
                chiplet_offset = htobe16(chiplet_offset);

                if (i_RingBlockType == GET_SINGLE_RING)
                {
                    var = ring_offset + chiplet_offset + i_ddLevelOffset + temp;
                    ringSize = htobe16( ((CompressedScanData*)
                                         ((uint8_t*)i_ringSection +
                                          var))->iv_size );
                    io_RingType = COMMON;

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
                                   i, var, temp, ring_offset, chiplet_offset, ringSize);
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
        for (uint8_t j = 0; j < EQ::g_eqData.iv_num_instance_rings; j++)
        {
            for(uint8_t k = 0; k < l_num_variant ; k++)
            {
                if (i_dbgl > 2)
                {
                    MY_INF(" Ring name %s Cplt instance ring id %d Variant id %d",
                           (ring_id_list_instance + j)->ringName, j, k);
                }

                if  (strcmp( (ring_id_list_instance + j)->ringName,
                             RING_PROPERTIES[i_ringId].iv_name) == 0)
                {
                    if ( io_instanceId >=  (ring_id_list_instance + 0)->instanceIdMin
                         &&  io_instanceId  <= (ring_id_list_instance + 0)->instanceIdMax )
                    {
                        if ( i == io_instanceId && k == i_RingVariant )
                        {
                            strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);
                            uint32_t var = CPLT_OFFSET_SIZE + i_ddLevelOffset + temp;
                            int temp1 =  var / sizeof(uint32_t);
                            ring_offset =  *((uint32_t*)i_ringSection + temp1);
                            ring_offset = htobe32(ring_offset);
                            var = ring_offset + i_ddLevelOffset + temp;
                            temp1 = var / sizeof(uint16_t) + local;
                            chiplet_offset  = *((uint16_t*)i_ringSection + temp1);
                            chiplet_offset = htobe16(chiplet_offset);

                            if (i_RingBlockType == GET_SINGLE_RING)
                            {
                                var = ring_offset + chiplet_offset + i_ddLevelOffset + temp;
                                ringSize = htobe16( ((CompressedScanData*)
                                                     ((uint8_t*)i_ringSection +
                                                      var))->iv_size );
                                io_RingType = INSTANCE;

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
                                               i, var, temp, ring_offset, chiplet_offset, ringSize);
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
                        MY_INF("SGPE ring instance ID %d is invalid, Valid ID is from %d  to %d \n",
                               io_instanceId, (ring_id_list_instance + 0)->instanceIdMin,
                               (ring_id_list_instance + 0)->instanceIdMax);
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
                              uint64_t        i_magic,           // Image Magic Number
                              RingID          i_ringId,          // Ring ID
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
    uint32_t acc_offset = 0;   // Accumulating offset to next TOR offset slot
    uint32_t ring_offset = 0;
    uint16_t chiplet_offset = 0;
    uint32_t ringSize = 0;
    int temp = (i_ddLevelOffset >> 2) + 2;  // converting byte  to word counter
    uint32_t cme_offset = 0;

    if (i_magic == P9_XIP_MAGIC_HW)
    {
        cme_offset = *((uint32_t*)i_ringSection + temp);  //DD level offset index
        temp = htobe32(cme_offset);
    }
    else if (i_magic == P9_XIP_MAGIC_CME)
    {
        cme_offset = 0;
        i_ddLevelOffset = 0;
        temp = htobe32(cme_offset);
    }

    GenRingIdList* ring_id_list_common = NULL;
    GenRingIdList* ring_id_list_instance = NULL;
    uint8_t l_num_variant  = (uint8_t)sizeof(EC::RingVariants) / sizeof(uint16_t);
    ring_id_list_common = (GenRingIdList*) EC::RING_ID_LIST_COMMON;
    ring_id_list_instance = (GenRingIdList*) EC::RING_ID_LIST_INSTANCE;

    uint32_t local = 0;

    for (uint8_t i = 0; i < EC::g_ecData.iv_num_common_rings ; i++)
    {
        for (uint8_t j = 0; j < l_num_variant ; j++)
        {
            if (i_dbgl > 2)
            {
                MY_INF(" Ring %s  Cplt common ring id %d  Variant id %d\n",
                       (ring_id_list_common + i)->ringName, i, j);
            }

            if ((strcmp( (ring_id_list_common + i)->ringName,
                         RING_PROPERTIES[i_ringId].iv_name) == 0) && ( i_RingVariant == j ))
            {
                strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);
                uint32_t var = 0 + i_ddLevelOffset + temp;
                int temp1 =  var / sizeof(uint32_t);
                ring_offset =  *((uint32_t*)i_ringSection + temp1);
                ring_offset = htobe32(ring_offset);
                var = ring_offset + i_ddLevelOffset + temp;
                temp1 = var / sizeof(uint16_t) + local;
                chiplet_offset  = *((uint16_t*)i_ringSection + temp1);
                chiplet_offset = htobe16(chiplet_offset);

                if (i_RingBlockType == GET_SINGLE_RING)
                {
                    var = ring_offset + chiplet_offset + i_ddLevelOffset + temp;
                    ringSize = htobe16( ((CompressedScanData*)
                                         ((uint8_t*)i_ringSection +
                                          var))->iv_size );
                    io_RingType = COMMON;

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
                                   i, var, temp, ring_offset, chiplet_offset, ringSize);
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

    for (uint8_t z = 0; z < 12; z++)
    {
        local = 0;

        for (uint8_t i = z * 2 + (ring_id_list_instance + 0)->instanceIdMin;
             i < z * 2 + 2 + (ring_id_list_instance + 0)->instanceIdMin ; i++)
        {
            for (uint8_t j = 0; j < EC::g_ecData.iv_num_instance_rings; j++)
            {
                for (uint8_t k = 0; k < l_num_variant ; k++)
                {
                    if (i_dbgl > 2)
                    {
                        MY_INF(" Ring name %s Cplt instance ring id %d Variant id %d",
                               (ring_id_list_instance + j)->ringName, j, k);
                    }

                    if (strcmp( (ring_id_list_instance + j)->ringName,
                                RING_PROPERTIES[i_ringId].iv_name) == 0)
                    {
                        if ( io_instanceId >=  (ring_id_list_instance + 0)->instanceIdMin
                             &&  io_instanceId  <= (ring_id_list_instance + 0)->instanceIdMax )
                        {
                            if ( i == io_instanceId && k == i_RingVariant )
                            {
                                strcpy(o_ringName, RING_PROPERTIES[i_ringId].iv_name);
                                uint32_t var = z * CPLT_OFFSET_SIZE + i_ddLevelOffset + temp + CPLT_OFFSET_SIZE;
                                int temp1 =  var / CPLT_OFFSET_SIZE;
                                ring_offset =  *((uint32_t*)i_ringSection + temp1);
                                ring_offset = htobe32(ring_offset);
                                var = ring_offset + i_ddLevelOffset + temp;
                                temp1 = var / sizeof(uint16_t) + local;
                                chiplet_offset = *((uint16_t*)i_ringSection + temp1);
                                chiplet_offset = htobe16(chiplet_offset);

                                if (i_RingBlockType == GET_SINGLE_RING)
                                {
                                    var = ring_offset + chiplet_offset + i_ddLevelOffset + temp;
                                    ringSize = htobe16( ((CompressedScanData*)
                                                         ((uint8_t*)i_ringSection +
                                                          var))->iv_size );
                                    io_RingType = INSTANCE;

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
                                            MY_INF(" Hex details (CME):  Chiplet #%d offset 0x%08x  local offset 0x%08x  " \
                                                   "ring offset 0x%08x  start adr 0x%08x  ringSize=0x%08x \n",
                                                   i, var, temp, ring_offset, chiplet_offset, ringSize);
                                        }

                                        memcpy( (uint8_t*)(*io_ringBlockPtr), (uint8_t*)i_ringSection + var,
                                                (size_t)ringSize);

                                        io_ringBlockSize = ringSize;

                                        if (i_dbgl > 0)
                                        {
                                            MY_INF(" After get_ring_from_cme_image Size %d \n", io_ringBlockSize);
                                        }

                                        if (i_dbgl > 1)
                                        {
                                            MY_INF("  0x%08x 0x%08x 0x%08x 0x%08x 0x%08x \n",
                                                   var, temp, ring_offset, chiplet_offset, ringSize);
                                            MY_INF("Chiplet %d   ChipletRing TOR offset  %d   %d  Size %d %d \t\n",
                                                   i,  ring_offset, chiplet_offset, ringSize, temp);
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
                            MY_INF(" CME ring instance ID %d is invalid, Valid ID is from %d  to %d \n",
                                   io_instanceId, (ring_id_list_instance + 0)->instanceIdMin,
                                   (ring_id_list_instance + 0)->instanceIdMax);
                            return TOR_INVALID_INSTANCE_ID;
                        }
                    }

                    local++;
                }
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
                      uint64_t        i_magic,           // Image Magic Number
                      RingID          i_ringId,          // Ring ID
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
    TorPpeBlock_t l_TorPpeBlock;
    uint8_t  bDdCheck = 0;
    uint32_t ddLevelOffset = 0;
    uint32_t ddLevelCount = 0;
    uint32_t ddLevel = 0;
    uint32_t ddBlockSize = 0;
    uint32_t temp = 0, temp1 = 0, local = 0;


    if (i_dbgl > 1)
    {
        MY_INF("Entering tor_access_ring()... \n");
    }

    if (i_magic == P9_XIP_MAGIC_HW)
    {
        ddLevelCount =  *((uint32_t*)i_ringSection + 0);
        ddLevelCount = htobe32(ddLevelCount);

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
            local = 2;
            ddLevelOffset  =  *((uint32_t*)i_ringSection + local);
            ddLevel = htobe32(ddLevelOffset) >> 24 & 0x000000FF;
            ddLevelOffset = htobe32(ddLevelOffset) & 0x00FFFFFF;

            if (i_dbgl > 1)
            {
                MY_INF( "tor_access_ring(): Local DD level offset: 0x%08x for DD level: 0x%x \n",
                        ddLevelOffset, ddLevel );
            }

            if ( ddLevel == i_ddLevel)
            {
                ddLevelOffset  =  *((uint32_t*)i_ringSection + local);
                ddLevelOffset = htobe32(ddLevelOffset) & 0x00FFFFFF;
                ddLevelOffset = ddLevelOffset + sizeof(TorNumDdLevels_t);
                local = local + 1;
                ddBlockSize = *((uint32_t*)i_ringSection + local);
                ddBlockSize = htobe32(ddBlockSize);
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
    else if ( i_magic ==  P9_XIP_MAGIC_SEEPROM)
    {
        if ( i_PpeType == CME || i_PpeType == SGPE
             || i_RingBlockType == GET_DD_LEVEL_RINGS
             || i_RingBlockType == GET_PPE_LEVEL_RINGS )
        {
            MY_ERR("Ambiguity on input PARMS for calling SEEPROM Ring copy API. \n");
            return TOR_AMBIGUOUS_API_PARMS;
        }
        else
        {
            ddLevelOffset = 0;
            ddBlockSize = 0;
        }
    }
    else if ( i_magic ==  P9_XIP_MAGIC_CME)
    {
        if ( i_PpeType == SBE || i_PpeType == SGPE
             || i_RingBlockType == GET_DD_LEVEL_RINGS
             || i_RingBlockType == GET_PPE_LEVEL_RINGS )
        {
            MY_ERR("Ambiguity on input PARMS for calling CME Ring copy API. \n");
            return TOR_AMBIGUOUS_API_PARMS;
        }
        else
        {
            ddLevelOffset = 0;
            ddBlockSize = 0;
        }
    }
    else if ( i_magic ==  P9_XIP_MAGIC_SGPE)
    {
        if ( i_PpeType == SBE || i_PpeType == CME
             || i_RingBlockType == GET_DD_LEVEL_RINGS
             || i_RingBlockType == GET_PPE_LEVEL_RINGS )
        {
            MY_ERR("Ambiguity on input PARMS for calling SGPE Ring copy API. \n");
            return TOR_AMBIGUOUS_API_PARMS;
        }
        else
        {
            ddLevelOffset = 0;
            ddBlockSize = 0;
        }
    }
    else
    {
        MY_ERR("Magic number i_magic=0x%016lX\n is not valid.\n", (uintptr_t)i_magic);

        return TOR_AMBIGUOUS_API_PARMS;
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

        return TOR_RING_BLOCKS_FOUND;
    }
    else if (i_RingBlockType == GET_PPE_LEVEL_RINGS)
    {
        uint32_t l_ppe_offset = 0;
        uint32_t l_ppe_size   = 0;

        if (i_PpeType == SBE)
        {
            temp = ddLevelOffset >> 2;

            if (i_dbgl > 1)
            {
                MY_INF( "TOR_ACCESS_RING(6): SBE PPE_LEVEL_RING COPY called ... \n");
            }

            l_ppe_offset = *((uint32_t*)i_ringSection + temp);
            l_ppe_offset = htobe32(l_ppe_offset);
            l_ppe_size = *((uint32_t*)i_ringSection + temp + 1 );
            l_ppe_size = htobe32(l_ppe_size);
        }
        else if (i_PpeType == CME)
        {
            temp = (ddLevelOffset >> 2) + 2;

            if (i_dbgl > 1)
            {
                MY_INF( "TOR_ACCESS_RING(7): CME PPE_LEVEL_RING COPY called... \n");
            }

            l_ppe_offset = *((uint32_t*)i_ringSection + temp);
            l_ppe_offset = htobe32(l_ppe_offset);
            l_ppe_size = *((uint32_t*)i_ringSection + temp + 1 );
            l_ppe_size = htobe32(l_ppe_size);
        }
        else if (i_PpeType == SGPE)
        {

            temp = (ddLevelOffset >> 2) + sizeof(uint32_t);

            if (i_dbgl > 1)
            {
                MY_INF( "TOR_ACCESS_RING(8): SPGE PPE_LEVEL_RING COPY called... \n");
            }

            l_ppe_offset = *((uint32_t*)i_ringSection + temp);
            l_ppe_offset = htobe32(l_ppe_offset);
            l_ppe_size = *((uint32_t*)i_ringSection + temp + 1 );
            l_ppe_size = htobe32(l_ppe_size);
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

        return TOR_RING_BLOCKS_FOUND;
    }
    else if (i_RingBlockType == GET_CPLT_LEVEL_RINGS)
    {
        if (i_dbgl > 1)
        {
            MY_INF( "TOR_ACCESS_RING(9): CPLT_LEVEL_RING COPY called... \n");
        }

        if (io_RingType == ALLRING)
        {
            MY_INF("Ambiguity on input PARMS. ALLRING RingType is invalid for CPLT level ring copy  \n");
            return TOR_AMBIGUOUS_API_PARMS;

        }

        uint32_t l_cplt_offset = 0;
        uint32_t l_ppe_offset  = 0;
        uint32_t l_cplt_size   = 0;

        if (i_PpeType == SBE)
        {
            SbeTorId_t l_sbeTorId = SBE_NOOF_CHIPLETS;

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
                    l_sbeTorId = OB0_CPLT;
                    break;

                case 10 :
                    l_sbeTorId = OB1_CPLT;
                    break;

                case 11 :
                    l_sbeTorId = OB2_CPLT;
                    break;

                case 12 :
                    l_sbeTorId = OB3_CPLT;
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
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
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
                    MY_ERR("io_instanceId=0x%x is not a valid chiplet ID (for SBE)\n", io_instanceId);
                    return TOR_INVALID_INSTANCE_ID;
            }

            temp = (ddLevelOffset >> 2);
            int l_word;

            if (i_magic == P9_XIP_MAGIC_HW)
            {
                l_cplt_offset = *((uint32_t*)i_ringSection + temp);
            }
            else
            {
                l_cplt_offset = 0;
            }

            if (i_dbgl > 1)
            {
                MY_INF("SBE(1):Offset 0x%08x \n", l_cplt_offset);
            }

            l_cplt_offset = htobe32(l_cplt_offset);
            uint32_t l_ppe_cplt_offset  = l_cplt_offset;
            temp = temp + 2;
            l_ppe_offset  = *((uint32_t*)i_ringSection + temp);
            l_ppe_offset  = htobe32(l_ppe_offset);
            temp1 = l_cplt_offset;

            if (i_dbgl > 1)
            {
                MY_INF("SBE(2):Offset 0x%08x  0x%08x 0x%08x 0x%08x\n", l_cplt_offset,
                       l_ppe_offset, temp, ddLevelOffset);
            }

            if (io_RingType == COMMON)
            {
                temp  = l_cplt_offset + ddLevelOffset + (l_sbeTorId * sizeof(TorPpeBlock_t));
                l_word = temp >> 2;
                temp  = l_cplt_offset + ddLevelOffset;

                if (i_dbgl > 1)
                {
                    MY_INF("SBE(3):COMMON Offset 0x%08x  0x%08x 0x%08x  \n", l_cplt_offset,
                           l_ppe_offset, temp);
                }
            }
            else
            {
                temp  = l_cplt_offset + ddLevelOffset
                        + (l_sbeTorId * sizeof(TorPpeBlock_t))
                        + sizeof(l_TorPpeBlock.TorPpeTypeOffset);
                l_word = temp >> 2;
                temp  = l_cplt_offset + ddLevelOffset;

                if (i_dbgl > 1)
                {
                    MY_INF("SBE(4):INSTANCE Offset 0x%08x  0x%08x 0x%08x  \n", l_cplt_offset,
                           l_ppe_offset, temp);
                }
            }

            l_cplt_offset = *((uint32_t*)i_ringSection + l_word);
            l_cplt_offset = htobe32(l_cplt_offset);
            l_word++;

            if (i_dbgl > 1)
            {
                MY_INF("SBE(5):Offset 0x%08x size 0x%08x \n", l_cplt_offset, l_ppe_offset);
            }

            l_cplt_size = *((uint32_t*)i_ringSection + l_word );
            l_cplt_size = htobe32(l_cplt_size);

            if (l_sbeTorId == EC_CPLT && io_RingType == INSTANCE)
            {
                if (i_magic == P9_XIP_MAGIC_SEEPROM)
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

            if (i_dbgl > 1)
            {
                MY_INF("SBE(6): Ring pointer Offset 0x%08x size 0x%08x \n", l_cplt_offset,
                       l_cplt_size);
            }
        }
        else if (i_PpeType == CME)
        {
            CmeTorId_t l_cmeTorId = CME_NOOF_CHIPLETS;

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
                    MY_ERR("io_instanceId=0x%x is not a valid chiplet ID (for CME)\n", io_instanceId);
                    return TOR_INVALID_INSTANCE_ID;
            }

            temp = (ddLevelOffset >> 2) + (sizeof(TorPpeBlock_t) >> 2);
            int l_word;
            l_cplt_offset = *((uint32_t*)i_ringSection + temp);

            if (i_dbgl > 1)
            {
                MY_INF("CME(1):ppe type Offset 0x%08x \n", l_cplt_offset);
            }

            l_cplt_offset = htobe32(l_cplt_offset);
            uint32_t l_ppe_cplt_offset  = l_cplt_offset;
            temp = temp + 2;
            l_ppe_offset  = *((uint32_t*)i_ringSection + temp);
            l_ppe_offset  = htobe32(l_ppe_offset);
            temp1 = l_cplt_offset;

            if (i_dbgl > 1)
            {
                MY_INF("CME(2): Offsets 0x%08x  0x%08x 0x%08x \n", l_cplt_offset, l_ppe_offset,
                       temp);
            }

            if (io_RingType == COMMON)
            {
                temp  = l_cplt_offset + ddLevelOffset;
                l_word = temp >> 2;

                if (i_dbgl > 1)
                {
                    MY_INF("CME(3):COMMON Offsets 0x%08x  0x%08x 0x%08x  \n", l_cplt_offset,
                           l_ppe_offset, temp);
                }
            }
            else
            {
                temp  = l_cplt_offset + ddLevelOffset
                        + (l_cmeTorId * sizeof(l_TorPpeBlock.TorPpeTypeOffset))
                        + sizeof(l_TorPpeBlock.TorPpeTypeOffset);
                l_word = temp >> 2;
                temp  = l_cplt_offset + ddLevelOffset;

                if (i_dbgl > 1)
                {
                    MY_INF("CME(4):INSTANCE Offset 0x%08x  0x%08x 0x%08x 0x%08x \n", l_cplt_offset,
                           l_ppe_offset, l_ppe_cplt_offset, temp);
                }
            }

            l_cplt_offset = *((uint32_t*)i_ringSection + l_word);
            l_cplt_offset = htobe32(l_cplt_offset);
            l_word++;

            if (i_dbgl > 1)
            {
                MY_INF("CME(5):Offset 0x%08x size 0x%08x \n", l_cplt_offset, l_ppe_offset);
            }

            l_cplt_size = *((uint32_t*)i_ringSection + l_word );
            l_cplt_size = htobe32(l_cplt_size);

            if (l_cmeTorId == CME11_CPLT && io_RingType == INSTANCE)
            {
                l_cplt_size =  l_ppe_offset -  (l_cplt_offset + l_ppe_cplt_offset);
            }
            else
            {
                l_cplt_size =  l_cplt_size -  l_cplt_offset;
            }

            l_cplt_offset = l_cplt_offset + ddLevelOffset;

            if (i_dbgl > 1)
            {
                MY_INF("CME(6): Ring pointer Offset 0x%08x size 0x%08x \n", l_cplt_offset,
                       l_cplt_size);
            }
        }
        else if (i_PpeType == SGPE)
        {

            temp = (ddLevelOffset >> 2) + (2 * (sizeof(TorPpeBlock_t) >> 2));
            int l_word;
            l_cplt_offset = *((uint32_t*)i_ringSection + temp);

            if (i_dbgl > 1)
            {
                MY_INF("SGPE(1):Offset 0x%08x \n", l_cplt_offset);
            }

            l_cplt_offset = htobe32(l_cplt_offset);

            temp = temp + 1;
            l_ppe_offset  = *((uint32_t*)i_ringSection + temp);
            l_ppe_offset  = htobe32(l_ppe_offset);
            temp1 = l_cplt_offset;

            if (i_dbgl > 1)
            {
                MY_INF("SGPE(2):Offset 0x%08x  0x%08x 0x%08x \n", l_cplt_offset, l_ppe_offset,
                       temp);
            }

            if (io_RingType == COMMON)
            {
                temp  = l_cplt_offset + ddLevelOffset;
                l_word = temp >> 2;

                if (i_dbgl > 1)
                {
                    MY_INF("SGPE(3):COMMON Offset 0x%08x  0x%08x 0x%08x  \n", l_cplt_offset,
                           l_ppe_offset, temp);
                }
            }
            else
            {
                temp  = l_cplt_offset + ddLevelOffset
                        + sizeof(l_TorPpeBlock.TorPpeBlockSize);
                l_word = temp >> 2;
                temp  = l_cplt_offset + ddLevelOffset;

                if (i_dbgl > 1)
                {
                    MY_INF("SGPE(4):INSTANCE Offset 0x%08x  0x%08x 0x%08x  \n", l_cplt_offset,
                           l_ppe_offset, temp);
                }
            }

            l_cplt_offset = *((uint32_t*)i_ringSection + l_word);
            l_cplt_offset = htobe32(l_cplt_offset);
            l_word++;
            l_cplt_size = *((uint32_t*)i_ringSection + l_word );
            l_cplt_size = htobe32(l_cplt_size);

            if ( io_RingType == INSTANCE)
            {
                l_cplt_size =  l_ppe_offset -  l_cplt_offset;
            }
            else
            {
                l_cplt_size =  l_cplt_size -  l_cplt_offset;
            }

            l_cplt_offset = l_cplt_offset + ddLevelOffset;

            if (i_dbgl > 1)
            {
                MY_INF("SGPE(5): Ring pointer Offset 0x%08x size 0x%08x \n", l_cplt_offset,
                       l_cplt_size);
            }
        }
        else
        {
            MY_ERR("\t i_PpeType=%d is not supported\n", i_PpeType);

            return TOR_AMBIGUOUS_API_PARMS;
        }

        if (io_ringBlockSize >= l_cplt_size)
        {
            memcpy( (uint8_t*)(*io_ringBlockPtr),
                    (uint8_t*)i_ringSection + l_cplt_offset + temp1,
                    (size_t)l_cplt_size);

            io_ringBlockSize = l_cplt_size;

            return TOR_RING_BLOCKS_FOUND;
        }
        else if (io_ringBlockSize == 0)
        {
            if (i_dbgl > 0)
            {
                MY_INF("\tio_ringBlockSize is zero. Returning required size.\n");
            }

            io_ringBlockSize =  l_cplt_size;

            return 0;
        }
        else
        {
            MY_ERR("\tio_ringBlockSize is less than required size, but not zero.\n");

            return TOR_BUFFER_TOO_SMALL;
        }
    }
    else
    {
        if (i_PpeType == SBE &&
            ( i_magic == P9_XIP_MAGIC_HW ||
              i_magic == P9_XIP_MAGIC_SEEPROM))
        {
            rc = get_ring_from_sbe_image ( i_ringSection,
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
                                           i_dbgl);

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

                return TOR_RING_BLOCKS_FOUND;
            }
        }
        else if (i_PpeType == CME &&
                 ( i_magic == P9_XIP_MAGIC_HW ||
                   i_magic == P9_XIP_MAGIC_CME))
        {
            rc =  get_ring_from_cme_image ( i_ringSection,
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
                                            i_dbgl);

            if (rc == TOR_RING_NOT_FOUND)
            {
                if (i_dbgl > 0)
                {
                    MY_INF("\t After CME single ring call, %s ring container is not found \n",
                           RING_PROPERTIES[i_ringId].iv_name);
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
                           RING_PROPERTIES[i_ringId].iv_name, i_ringId);
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

                return TOR_RING_BLOCKS_FOUND;
            }
        }
        else if (i_PpeType == SGPE &&
                 ( i_magic == P9_XIP_MAGIC_HW ||
                   i_magic == P9_XIP_MAGIC_SGPE))
        {
            rc =  get_ring_from_sgpe_image ( i_ringSection,
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
                                             i_dbgl);

            if (rc == TOR_RING_NOT_FOUND)
            {
                if (i_dbgl > 0)
                {
                    MY_INF("\t After SGPE single ring call, %s ring container is not found \n",
                           RING_PROPERTIES[i_ringId].iv_name);
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
                           RING_PROPERTIES[i_ringId].iv_name, i_ringId);
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

                return TOR_RING_BLOCKS_FOUND;
            }
        }
        else
        {
            MY_ERR("\t Code bug: We are unpreparred for this input parm combination: \n"
                   "\t i_PpeType=%d\n"
                   "\t i_magic=0x%016lX\n",
                   i_PpeType, (uintptr_t)i_magic);

            return TOR_AMBIGUOUS_API_PARMS;
        }

    }

    return TOR_AMBIGUOUS_API_PARMS;
}



/////////////////////////////////////////////////////////////////////////////////////
//
//                             TOR GET SINGLE RING   API
//
/////////////////////////////////////////////////////////////////////////////////////
int tor_get_single_ring ( void*         i_ringSection,     // Ring section ptr
                          uint64_t      i_magic,           // Image Magic Number
                          uint16_t      i_ddLevel,         // DD level
                          RingID        i_ringId,          // Ring ID
                          PpeType_t     i_PpeType,         // SBE, CME, SGPE
                          RingVariant_t i_RingVariant,     // Base,CC, RL, Ovrd, Ovly
                          uint8_t       i_instanceId,      // Instance ID
                          void**        io_ringBlockPtr,   // Output ring buffer
                          uint32_t&     io_ringBlockSize,  // Size of ring data
                          uint32_t      i_dbgl )           // Debug option
{

    uint32_t rc;
    char i_ringName[25];
    uint8_t l_instanceId = i_instanceId;
    RingType_t l_ringType;
    l_ringType = COMMON;

    if (i_dbgl > 1)
    {
        MY_INF(" TOR_GET_SINGLE_RING1: function call \n");
    }

    rc = tor_access_ring( i_ringSection,
                          i_magic,
                          i_ringId,
                          i_ddLevel,
                          i_PpeType,
                          l_ringType,
                          i_RingVariant,
                          l_instanceId,
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
                             RingType_t      i_RingType,        // Common, Instance
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
    uint8_t l_instanceId  = i_instanceId;
    RingType_t l_ringType = i_RingType;

    if (l_ringType == ALLRING && i_PpeType != NUM_PPE_TYPES)
    {
        // Get block of rings specific to a PPE type
        rc = tor_access_ring( i_ringSection,
                              P9_XIP_MAGIC_HW,
                              NUM_RING_IDS,
                              i_ddLevel,
                              i_PpeType,
                              l_ringType,
                              i_RingVariant,
                              l_instanceId,
                              GET_PPE_LEVEL_RINGS,
                              io_ringBlockPtr,
                              io_ringBlockSize,
                              i_ringName,
                              i_dbgl );

    }
    else if (l_ringType == ALLRING && i_PpeType == NUM_PPE_TYPES)
    {
        // Get DD level block of rings
        rc = tor_access_ring( i_ringSection,
                              P9_XIP_MAGIC_HW,
                              NUM_RING_IDS,
                              i_ddLevel,
                              i_PpeType,
                              l_ringType,
                              i_RingVariant,
                              l_instanceId,
                              GET_DD_LEVEL_RINGS,
                              io_ringBlockPtr,
                              io_ringBlockSize,
                              i_ringName,
                              i_dbgl );
    }
    else if (l_ringType == COMMON || l_ringType == INSTANCE)
    {
        // Get Chiplet level block of ringscopy
        // CMO-20161004: This won't work w/VPD rings since they are appended to the end
        //               of the section, i.e. not immediately after the TOR offset section.
        rc = tor_access_ring( i_ringSection,
                              P9_XIP_MAGIC_HW,
                              NUM_RING_IDS,
                              i_ddLevel,
                              i_PpeType,
                              l_ringType,
                              i_RingVariant,
                              l_instanceId,
                              GET_CPLT_LEVEL_RINGS,
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
                      RingID          i_ringId,           // Ring ID
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
    uint8_t    l_instanceId  = i_instanceId;
    RingType_t l_RingType = i_RingType;
    uint32_t   l_ringBlockSize;
    uint16_t   l_ringOffset16;
    uint64_t   l_magic;
    uint32_t   l_torOffsetSlot;

    if (i_PpeType  == SBE)  // Assign i_magic variant as SBE image
    {
        l_magic = P9_XIP_MAGIC_SEEPROM;
    }
    else if (i_PpeType == CME)  // Assign i_magic variant as CME image
    {
        l_magic = P9_XIP_MAGIC_CME;
    }
    else if (i_PpeType == SGPE) // Assign i_magic variant as SGPE image
    {
        l_magic = P9_XIP_MAGIC_SGPE;
    }
    else
    {
        MY_ERR("PPE type (i_PpeType=%d) is not supported \n", i_PpeType);
        return TOR_AMBIGUOUS_API_PARMS;
    }

    rc = tor_access_ring( i_ringSection,
                          l_magic,
                          i_ringId,
                          0x00,
                          i_PpeType,
                          l_RingType,
                          i_RingVariant,
                          l_instanceId,
                          PUT_SINGLE_RING,
                          (void**)&l_cpltSection, // On return, contains offset (wrt ringSection) of
                          // chiplet section's common or instance section
                          l_torOffsetSlot,        // On return, contains offset (wrt ringSection) of
                          // TOR offset slot
                          i_ringName,
                          i_dbgl);

    if (rc)
    {
        MY_ERR("tor_access_ring() failed w/rc=0x%x \n", rc);
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
    l_ringBlockSize = htobe16( ((CompressedScanData*)i_rs4Container)->iv_size );
    memcpy( (uint8_t*)i_ringSection + io_ringSectionSize,
            (uint8_t*)i_rs4Container, (size_t)l_ringBlockSize);

    // Update the ringSectionSize
    io_ringSectionSize += l_ringBlockSize;

    return TOR_SUCCESS;
}


//
// Inform caller of TOR version.
//
uint8_t tor_version( void)
{
    return (uint8_t)TOR_VERSION;
}

};
