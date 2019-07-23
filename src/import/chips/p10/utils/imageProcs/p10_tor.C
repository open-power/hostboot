/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_tor.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

#include "p10_tor.H"
#include "p10_scan_compression.H"
#include "p10_infrastruct_help.H"


///////////////////////////////////////////////////////////////////////////////////
//                       Get Ring From Ring Section function
//////////////////////////////////////////////////////////////////////////////////
static
int get_ring_from_ring_section( void*           i_ringSection,  // Ring section ptr
                                RingId_t        i_ringId,       // Ring ID
                                uint8_t&        io_instanceId,  // IO instance ID
                                RingRequest_t   i_ringRequest,  // {GET,PUT}_SINGLE_RING
                                void*           io_rs4Ring,     // IO RS4 ring buffer (caller mgd)
                                uint32_t&       io_ringBufSize, // Query, rs4Size, or max buf size
                                uint32_t        i_dbgl )
{
    int               rc = TOR_SUCCESS;
    TorHeader_t*      torHeader;
    uint32_t          torMagic;
    ChipId_t          chipId;
    TorCpltBlock_t*   cpltBlock;
    TorCpltOffset_t   cpltOffset; // Offset from ringSection to chiplet section
    TorRingOffset_t   ringOffset; // Offset to actual ring container
    uint32_t          torSlotNum; // TOR slot number (within a chiplet section)
    uint32_t          rs4Size;    // Size of RS4 ring container/block.
    RingId_t          numRings;
    ChipletType_t     chipletType = UNDEFINED_CHIPLET_TYPE;
    ChipletType_t     chipletIndex = UNDEFINED_CHIPLET_TYPE; // Effective chiplet index
    MyBool_t          bInstCase = UNDEFINED_BOOLEAN;
    ChipletData_t*    chipletData;
    uint8_t           numInstances;
    RingProperties_t* ringProps = NULL;
    uint8_t           idxRingEff;      // Effective chiplet ring index
    uint8_t           iInst, iRing; // Index counters for instance, chiplet rings

    torHeader = (TorHeader_t*)i_ringSection;
    torMagic  = be32toh(torHeader->magic);
    chipId    = torHeader->chipId;

    //
    // Get main ring properties list for the chip ID
    //
    rc = ringid_get_ringProps( chipId,
                               &ringProps );

    if (rc)
    {
        MY_ERR("ringid_get_ringProps() failed w/rc=0x%08x\n", rc);
        return rc;
    }

    chipletType = ringProps[i_ringId].chipletType;

    //
    // Get all other metadata for the chipletType
    //
    rc = ringid_get_chipletProps( chipId,
                                  torMagic,
                                  torHeader->version,
                                  chipletType,
                                  &chipletData );

    if (rc)
    {
        MY_ERR("ringid_get_chipletProps() failed w/rc=0x%08x\n", rc);
        return rc;
    }

    //
    // Check the scope of chipletType and Get the effective chipletType's index
    //
    rc = ringid_get_chipletIndex( chipId,
                                  torMagic,
                                  chipletType,
                                  &chipletIndex );

    if (rc)
    {
        if ( rc == TOR_INVALID_CHIPLET_TYPE )
        {
            // This is not necessarily a fatal or unacceptable error. For example,
            // xip_tool and ipl_customize's dynamic customization for QME will hit
            // this one a lot.  So we can't trace out here in confidence.  For
            // now, we're just returning TOR_INVALID_CHIPLET_TYPE and leaving it
            // up to the caller to investigate the rc.
            return rc;
        }
        else
        {
            MY_ERR("ringid_get_chipletIndex() failed w/rc=0x%08x\n", rc);
            return rc;
        }
    }

    //
    // Determine whether Common or Instance section based on the INSTANCE_RING_MARK
    //
    if ( ringProps[i_ringId].idxRing & INSTANCE_RING_MARK )
    {
        bInstCase = 1;
    }
    else
    {
        bInstCase = 0;
    }

    //
    // Calculate various loop upper limits
    //
    numInstances = bInstCase ?
                   chipletData->numChipletInstances :
                   1;

    numRings     = bInstCase ?
                   chipletData->numInstanceRings :
                   chipletData->numCommonRings;

    idxRingEff   = ringProps[i_ringId].idxRing & INSTANCE_RING_MASK; // Always safe

    // Unless we find a ring, then the following rc will be returned
    rc = TOR_RING_HAS_NO_TOR_SLOT;

    //
    // Now traverse the chiplet's Common or Instance ring section
    //
    if (numRings) // Only proceed if chiplet has [Common/Instance] rings.
    {
        // Calc offset to chiplet's CMN or INST section, cpltOffset (steps 1-3)
        //
        // 1. Calc offset to TOR slot pointing to chiplet's COM or INST section
        cpltOffset = sizeof(TorHeader_t) +
                     chipletIndex * sizeof(TorCpltBlock_t) +
                     bInstCase * sizeof(cpltBlock->cmnOffset);
        // 2. Retrive offset, endian convert and make it relative to ring section origin
        cpltOffset = *(uint32_t*)( (uint8_t*)i_ringSection + cpltOffset );
        cpltOffset = be32toh(cpltOffset);
        // 3. Make offset relative to ring section origin
        cpltOffset = sizeof(TorHeader_t) + cpltOffset;

        torSlotNum = 0;

        for ( iInst = 0; iInst < numInstances; iInst++ )
        {
            for ( iRing = 0; iRing < numRings; iRing++ )
            {
                // Remember in the following "busy" if that we're already in the correct
                // chiplet ring section and that we're merely trying to determine if we have
                // hit the proper combination of (iRing,iInst).
                if ( idxRingEff == iRing  &&
                     ( !bInstCase ||
                       ( bInstCase &&
                         ( iInst == (io_instanceId - chipletData->chipletBaseId) ) ) ) )
                {
                    // Calc offset to actual ring, ringOffset (steps 1-3)
                    //
                    // 1. Calc offset to TOR slot pointing to actual ring
                    ringOffset = cpltOffset + torSlotNum * sizeof(ringOffset);
                    // 2. Retrieve offset and endian convert
                    ringOffset = *(TorRingOffset_t*)( (uint8_t*)i_ringSection + ringOffset );
                    ringOffset = be16toh(ringOffset);

                    if (i_ringRequest == GET_SINGLE_RING)
                    {
                        rs4Size = 0;

                        if (ringOffset)
                        {
                            // 3. Make offset relative to ring section origin
                            ringOffset = cpltOffset + ringOffset;

                            rs4Size = be16toh( ((CompressedScanData*)
                                                ((uint8_t*)i_ringSection + ringOffset))->iv_size );

                            if (io_ringBufSize < rs4Size)
                            {
                                MY_ERR("io_ringBufSize(=%u) is less than rs4Size(=%u).\n",
                                       io_ringBufSize, rs4Size);
                                io_ringBufSize = rs4Size;
                                return TOR_BUFFER_TOO_SMALL;
                            }

                            // Produce return parms
                            memcpy( io_rs4Ring,
                                    (void*)((uint8_t*)i_ringSection + ringOffset),
                                    rs4Size );
                            io_ringBufSize = rs4Size;
                            io_instanceId = bInstCase ?
                                            io_instanceId :
                                            chipletData->chipletBaseId;

                            if (i_dbgl > 0)
                            {
                                MY_DBG("Found a ring:\n" \
                                       "  ringId: 0x%x\n" \
                                       "  rs4Size: %d\n",
                                       i_ringId, rs4Size);
                            }

                            rc = TOR_SUCCESS;
                        }
                        else
                        {
                            if (i_dbgl > 0)
                            {
                                MY_DBG("ringId=0x%x was found but is empty\n",
                                       i_ringId);
                            }

                            rc = TOR_RING_IS_EMPTY;
                        }

                        if (i_dbgl > 0)
                        {
                            MY_DBG("Details for chiplet ring index=%d: \n"
                                   "  Full offset to chiplet section = 0x%08x \n"
                                   "  Full offset to RS4 header = 0x%08x \n"
                                   "  RS4 ring size = 0x%08x \n",
                                   iRing, cpltOffset, ringOffset, rs4Size);
                        }

                        return rc;

                    }
                    else if (i_ringRequest == PUT_SINGLE_RING)
                    {
                        if (ringOffset)
                        {
                            MY_ERR("Ring container is already present in image\n");
                            MY_ERR("  Ring section addr: 0x%016lx  (First 8B: 0x%016lx)\n",
                                   (uintptr_t)i_ringSection,
                                   be64toh(*((uint64_t*)i_ringSection)));
                            MY_ERR("  cpltOffset=0x%08x, torSlotNum=0x%x, TOR offset=0x%04x\n",
                                   cpltOffset, torSlotNum, ringOffset);
                            return TOR_RING_IS_POPULATED;
                        }

                        // Special [mis]use of io_rs4Ring and io_ringBufSize:
                        // Put location of chiplet's CMN or INST section into rs4Ring
                        memcpy(io_rs4Ring, &cpltOffset, sizeof(cpltOffset));
                        // Put location of ringOffset slot into ringBufSize
                        io_ringBufSize = cpltOffset + (torSlotNum * sizeof(ringOffset));

                        return TOR_SUCCESS;
                    }
                    else
                    {
                        MY_ERR("Ring request (i_ringRequest=%d) is not supported\n", i_ringRequest);
                        return TOR_INVALID_RING_REQUEST;
                    }
                }

                torSlotNum++; // Next TOR ring slot
            }
        }
    }
    else
    {
        // Unusual to get here. Most likely due to caller error but not necessarily so. For
        // ex, xip_tool will cycle through here because it assumes nothing about whether a
        // chiplet has both common and instance rings.
        return TOR_RING_HAS_NO_TOR_SLOT;
    } // if (numRings)

    return rc;

} // End of get_ring_from_ring_section()



//////////////////////////////////////////////////////////////////////////////////////////
///                            TOR ACCESS RING   API
//////////////////////////////////////////////////////////////////////////////////////////
int tor_access_ring( void*           i_ringSection,  // Ring section ptr
                     RingId_t        i_ringId,       // Ring ID
                     uint8_t         i_ddLevel,      // DD level
                     uint8_t&        io_instanceId,  // Instance ID
                     RingRequest_t   i_ringRequest,  // {GET,PUT}_SINGLE_RING
                     void*           io_rs4Ring,     // IO RS4 ring buffer (caller mgd)
                     uint32_t&       io_ringBufSize, // Query, rs4Size, or max buf size
                     uint32_t        i_dbgl )
{
    int            rc = TOR_SUCCESS;
    uint32_t       torMagic;
    TorHeader_t*   torHeader;

    if (i_dbgl > 1)
    {
        MY_DBG("Entering tor_access_ring()...\n");
    }

    torHeader = (TorHeader_t*)i_ringSection;
    torMagic = be32toh(torHeader->magic);

    if (i_dbgl > 0)
    {
        MY_DBG("TOR header fields\n"
               "  magic:         0x%08x\n"
               "  version:       %d\n"
               "  chipId:        %d\n"
               "  ddLevel:       0x%x\n"
               "  size:          %d\n"
               "API parms\n"
               "  i_ddLevel:     0x%x\n",
               torMagic, torHeader->version, torHeader->chipId,
               torHeader->ddLevel,
               be32toh(torHeader->size),
               i_ddLevel);

        MY_DBG("Dump of first 12 quad-word lines in ring section\n");

        for (uint8_t iLine = 0; iLine < 12; iLine++)
        {
            MY_DBG("%04x: %04x %04x %04x %04x %04x %04x %04x %04x\n",
                   iLine * 16,
                   (uint16_t)( be64toh(*((uint64_t*)i_ringSection + 2 * iLine + 0)) >> 48),
                   (uint16_t)( be64toh(*((uint64_t*)i_ringSection + 2 * iLine + 0)) >> 32),
                   (uint16_t)( be64toh(*((uint64_t*)i_ringSection + 2 * iLine + 0)) >> 16),
                   (uint16_t)( be64toh(*((uint64_t*)i_ringSection + 2 * iLine + 0)) >>  0),
                   (uint16_t)( be64toh(*((uint64_t*)i_ringSection + 2 * iLine + 1)) >> 48),
                   (uint16_t)( be64toh(*((uint64_t*)i_ringSection + 2 * iLine + 1)) >> 32),
                   (uint16_t)( be64toh(*((uint64_t*)i_ringSection + 2 * iLine + 1)) >> 16),
                   (uint16_t)( be64toh(*((uint64_t*)i_ringSection + 2 * iLine + 1)) >>  0));
        }
    }

    if ( torMagic >> 8 != TOR_MAGIC ||
         // Check that we're not trying to be "forward" compatible to a newer image
         torHeader->version > TOR_VERSION ||
         // Make sure version is set
         torHeader->version == 0 ||
         // Check for valid chip ID and for valid ring ID
         ringid_check_ringId(torHeader->chipId, i_ringId) != INFRASTRUCT_RC_SUCCESS )
    {
        MY_ERR("Invalid TOR header or ringId:\n"
               "  magic:       0x%08x (TOR_MAGIC: 0x%08x)\n"
               "  version:     %d (TOR_VERSION: %d)\n"
               "  chipId:      %d\n"
               "  ringId:      0x%x\n"
               "  ddLevel:     0x%x  (requested ddLevel=0x%x)\n"
               "  size:        %d\n",
               torMagic, TOR_MAGIC, torHeader->version, TOR_VERSION,
               torHeader->chipId, i_ringId, torHeader->ddLevel,
               i_ddLevel, be32toh(torHeader->size));
        return TOR_HEADER_CHECK_FAILURE;
    }

    if ( i_ddLevel != torHeader->ddLevel &&
         i_ddLevel != UNDEFINED_DD_LEVEL )
    {
        MY_ERR("Requested DD level (=0x%x) doesn't match TOR header DD level (=0x%x) nor UNDEFINED_DD_LEVEL (=0x%x) \n",
               i_ddLevel, torHeader->ddLevel, UNDEFINED_DD_LEVEL);
        return TOR_DD_LEVEL_NOT_FOUND;
    }

    rc =  get_ring_from_ring_section( i_ringSection,
                                      i_ringId,
                                      io_instanceId,
                                      i_ringRequest,
                                      io_rs4Ring,
                                      io_ringBufSize,
                                      i_dbgl );

    if ( rc &&
         rc != TOR_RING_IS_EMPTY &&         // generally acceptable
         rc != TOR_RING_HAS_NO_TOR_SLOT &&  // ipl_image_tool will cause this a lot
         rc != TOR_INVALID_CHIPLET_TYPE )   // ipl_image_tool will cause this a lot
    {
        MY_ERR("ERROR: tor_access_ring(): get_ring_from_ring_section() failed w/rc="
               "0x%08x\n", rc);
        return rc;
    }

    return rc;
} // End of tor_access_ring()



/////////////////////////////////////////////////////////////////////////////////////
//                             TOR GET SINGLE RING   API
/////////////////////////////////////////////////////////////////////////////////////
int tor_get_single_ring ( void*         i_ringSection,  // Ring section ptr
                          uint8_t       i_ddLevel,      // DD level
                          RingId_t      i_ringId,       // Ring ID
                          uint8_t       i_instanceId,   // Instance ID
                          void*         io_rs4Ring,     // IO RS4 ring buffer (caller mgd)
                          uint32_t&     io_ringBufSize, // Query, rs4Size, or max buf size
                          uint32_t      i_dbgl )
{

    int    rc = TOR_SUCCESS;

    if (i_dbgl > 1)
    {
        MY_DBG("Entering tor_get_single_ring()...\n");
    }

    rc = tor_access_ring( i_ringSection,
                          i_ringId,
                          i_ddLevel,
                          i_instanceId,
                          GET_SINGLE_RING,
                          io_rs4Ring,
                          io_ringBufSize,
                          i_dbgl );

    // Explanation to the "list" of RCs that we exclude from tracing out:
    // TOR_RING_IS_EMPTY:  Normal scenario (will occur frequently)
    // TOR_INVALID_CHIPLET_TYPE:  Also somewhat normal scenario since the caller should,
    //                     in princple, be able to mindlessly request a ringId without
    //                     having to figure out first if that ringId belongs to a chiplet
    //                     that is valid for the context. But really this is a gray area.
    //                     For now, we omit to trace out as we will hit this rc condition
    //                     in both ipl_image_tool and ipl_customize (RT_QME phase).
    if ( rc &&
         rc != TOR_RING_IS_EMPTY &&
         rc != TOR_INVALID_CHIPLET_TYPE )
    {
        MY_ERR("ERROR: tor_get_single_ring(): tor_access_ring() failed w/rc="
               "0x%08x\n", rc);
        return rc;
    }

    return rc;
}



////////////////////////////////////////////////////////////////////////////////////////
//                             TOR APPEND RING   API
///////////////////////////////////////////////////////////////////////////////////////
int tor_append_ring( void*           i_ringSection,      // Ring section ptr
                     uint32_t&       io_ringSectionSize, // In: Exact size of ring section.
                     // Out: Updated size of ring section.
                     RingId_t        i_ringId,           // Ring ID
                     uint8_t         i_instanceId,       // Instance ID
                     void*           i_rs4Ring,          // RS4 ring
                     uint32_t        i_dbgl )            // Debug option
{
    int    rc = TOR_SUCCESS;
    uint32_t   buf = 0;
    uint32_t*  cpltSection = &buf;
    uint32_t   rs4Size = 0;
    TorRingOffset_t   ringOffset16;
    uint32_t   torOffsetSlot;

    rc = tor_access_ring( i_ringSection,
                          i_ringId,
                          UNDEFINED_DD_LEVEL,
                          i_instanceId,
                          PUT_SINGLE_RING,
                          (void*)cpltSection, // On return, contains offset (wrt ringSection) of
                          // chiplet section's common or instance section
                          torOffsetSlot,        // On return, contains offset (wrt ringSection) of
                          // TOR offset slot
                          i_dbgl);

    if (rc)
    {
        MY_ERR("ERROR: tor_append_ring(): tor_access_ring() failed w/rc="
               "0x%08x\n", rc);
        return rc;
    }

    if (i_dbgl > 1)
    {
        MY_INF(" TOR offset slot for ring address %d \n", torOffsetSlot );
    }

    // Explanation to the following:
    // tor_append_ring() appends a ring to the end of the ringSection. The offset value to
    // that ring is wrt the beginning of the chiplet's Common/Instance TOR ring offset slot
    // section. Below we calculate the offset value and put it into the TOR slot. But first,
    // check that the offset value can be contained within the 2B of the TOR slot.
    if ( (io_ringSectionSize - *cpltSection) <= MAX_TOR_RING_OFFSET )
    {
        ringOffset16 = htobe16(io_ringSectionSize - *cpltSection);
        memcpy( (uint8_t*)i_ringSection + torOffsetSlot,
                &ringOffset16, sizeof(ringOffset16) );
    }
    else
    {
        MY_ERR("Code bug: TOR ring offset (=0x%x) exceeds MAX_TOR_RING_OFFSET (=0x%x)\n",
               io_ringSectionSize - *cpltSection, MAX_TOR_RING_OFFSET);
        return TOR_OFFSET_TOO_BIG;
    }

    // Now append the ring to the end of ringSection.
    rs4Size = be16toh( ((CompressedScanData*)i_rs4Ring)->iv_size );
    memcpy( (uint8_t*)i_ringSection + io_ringSectionSize,
            (uint8_t*)i_rs4Ring,
            rs4Size );

    // Update the ringSectionSize
    io_ringSectionSize += rs4Size;

    // Update the size in the TOR header
    TorHeader_t* torHeader = (TorHeader_t*)i_ringSection;
    torHeader->size = htobe32(be32toh(torHeader->size) + rs4Size);

    return TOR_SUCCESS;
}



////////////////////////////////////////////////////////////////////////////////////////
///                   TOR [ring section] skeleton generation
////////////////////////////////////////////////////////////////////////////////////////
int tor_skeleton_generation( void*         io_ringSection,
                             uint32_t      i_torMagic,
                             uint8_t       i_torVersion,
                             uint8_t       i_ddLevel,
                             ChipId_t      i_chipId,
                             uint32_t      dbgl )
{
    int       rc = TOR_SUCCESS;
    uint32_t  ringSectionSize = 0;
    ChipletData_t*    chipletData;
    TorCpltBlock_t*   torChipletBlock;
    ChipletType_t  chipletType = UNDEFINED_CHIPLET_TYPE;
    ChipletType_t  numChiplets = UNDEFINED_CHIPLET_TYPE;
    MyBool_t       bInstCase = UNDEFINED_BOOLEAN; // 0:COMMON, 1:INSTANCE rings
    uint32_t  chipletBlockStart;   // Offset from ringSection to start of chiplet offset block
    uint32_t  sizeChipletBlock;    // Size of the chiplet offset block
    uint32_t  sizeRingSlots;       // Size of ring offset block
    uint32_t  chipletRingsStart;   // Offset from ringSection to start of chiplet's ring slots
    RingId_t  numRings = UNDEFINED_RING_ID;  // Number of a chiplet common or instance rings
    uint8_t   numInstances = 0;    // Number of chiplet instances (=1 for COMMON case)
    uint32_t  numRingSlots = 0;    // Number of ring slots in chiplet's Cmn/Inst ring section

    TorHeader_t* torHeader = (TorHeader_t*)io_ringSection;

    // Note that we'll be 4B aligning all offset block sub-sections in this routine.

    // Calc start position of the chiplet blocks (relative to start of ringSection)
    chipletBlockStart = sizeof(TorHeader_t);

    //
    // Step 1:
    // Allocate and populate TOR header and chiplet offset block section
    //
    torHeader->magic   = htobe32(i_torMagic);
    torHeader->version = i_torVersion;
    torHeader->chipId  = i_chipId;
    torHeader->ddLevel = i_ddLevel;
    //torHeader->size = Updated after creating TOR skeleton
    torHeader->undefined = 0;

    // Init local running ring section size
    ringSectionSize = sizeof(TorHeader_t);

    // Get the number of chiplets and calc size of chiplet offset block
    rc = ringid_get_num_chiplets( i_chipId,
                                  i_torMagic,
                                  &numChiplets );

    if (rc)
    {
        MY_ERR("ERROR: ringid_get_num_chiplets() failed in tor_skeleton_generation() for"
               " torMagic=0x%08x and chipId=%d w/rc=0x%08x\n",
               i_torMagic, i_chipId, rc);
        return rc;
    }

    sizeChipletBlock = myByteAlign(4, numChiplets * sizeof(TorCpltBlock_t));

    // Allocate and init offset slots for the chiplet offset block, and align to 4B.
    memset( (uint8_t*)io_ringSection + chipletBlockStart,
            0,
            sizeChipletBlock );

    // Save start pos of first chiplet's ring offset block (rel to start of ringSection)
    ringSectionSize += sizeChipletBlock;

    //
    // Step 2:
    // Main TOR skeleton ring section create loop
    // (Note that we're *not* appending any rings here. Merely generating the complete, and
    //  empty!, set of TOR ring offset slots.)
    //
    for (chipletType = 0; chipletType < numChiplets; chipletType++)
    {
        // Calc location of this chiplet's offset block (which is composed of an cmnOffset
        // and an instOffset)
        torChipletBlock = (TorCpltBlock_t*)( (uint8_t*)io_ringSection +
                                             chipletBlockStart +
                                             chipletType * sizeof(TorCpltBlock_t) );

        // Get all the meta data for this chiplet and its rings
        rc = ringid_get_chipletProps( i_chipId,
                                      i_torMagic,
                                      i_torVersion,
                                      chipletType,
                                      &chipletData );

        if (rc)
        {
            MY_ERR("ringid_get_chipletProps() failed in tor_skeleton_generation()"
                   " w/rc=0x%08x\n",
                   rc);
            return rc;
        }

        for (bInstCase = 0; bInstCase <= 1; bInstCase++)
        {
            if ( ( bInstCase == false && chipletData->numCommonRings == 0 ) ||
                 ( bInstCase == true && chipletData->numInstanceRings == 0 ) )
            {
                continue;
            }

            // Save start position of current chiplet's Common or Instance ring section
            // (relative to start of ringSection)
            chipletRingsStart = ringSectionSize;

            // Update the current chiplet block's offset to the Common or Instance ring section
            if (bInstCase)
            {
                torChipletBlock->instOffset = htobe32(chipletRingsStart - chipletBlockStart);
            }
            else
            {
                torChipletBlock->cmnOffset = htobe32(chipletRingsStart - chipletBlockStart);
            }

            // Determine total number of Instance or Common rings (TOR slots) which involves:
            // - calc the number of instance rings in the Instance case,
            // - adjust the number of variants for the Instance case (i.e., no variants),
            numInstances = bInstCase ?
                           chipletData->numChipletInstances :
                           1;

            numRings = bInstCase ?
                       chipletData->numInstanceRings :
                       chipletData->numCommonRings;

            numRingSlots = numRings * numInstances; // Total number of ring slots

            // Allocate and init offset slots for chiplet Cmn/Inst rings
            // Use 4B alignment of the TOR ring slots for debugging visualization.
            sizeRingSlots = myByteAlign(4, numRingSlots * sizeof(TorRingOffset_t));
            memset( (uint8_t*)io_ringSection + chipletRingsStart,
                    0,
                    sizeRingSlots );

            ringSectionSize += sizeRingSlots;

            // Update the header's ring section size
            torHeader->size = htobe32(ringSectionSize);

        } // bInstCase

    } // chipletType

    return TOR_SUCCESS;
}



//
// Inform caller of TOR version.
//
uint8_t tor_version( void)
{
    return (uint8_t)TOR_VERSION;
}



////////////////////////////////////////////////////////////////////////////////////////
//                         Dynamic Inits Append Ring API
///////////////////////////////////////////////////////////////////////////////////////
int dyn_append_ring( void*     io_ringSection,        // Ring section ptr
                     uint32_t  i_maxRingSectionSize,  // Max size of ring section
                     void*     i_rs4Ring,             // RS4 ring
                     uint32_t  i_dbgl )               // Debug option
{
    uint32_t   rs4Size = 0;
    uint32_t   ringSectionSize = 0;

    TorHeader_t* torHeader = (TorHeader_t*)io_ringSection;

    ringSectionSize = be32toh(torHeader->size);
    rs4Size         = be16toh(((CompressedScanData*)i_rs4Ring)->iv_size);

    if ( (ringSectionSize + rs4Size) < i_maxRingSectionSize )
    {
        memcpy( (void*)((uint8_t*)io_ringSection + ringSectionSize),
                i_rs4Ring,
                rs4Size );
    }
    else
    {
        MY_ERR("ERROR in dyn_append_ring: ringSectionSize(=%d) + rs4Size(=%d)"
               " would exceed maxRingSectionSize(=%d)\n",
               ringSectionSize, rs4Size, i_maxRingSectionSize);
        return TOR_BUFFER_TOO_SMALL;
    }

    // Update the ring section size in the TOR header
    torHeader->size = htobe32(ringSectionSize + rs4Size);

    return TOR_SUCCESS;
}



int dyn_get_ring( void*          i_ringSection,
                  RingId_t       i_ringId,
                  Rs4Selector_t  i_selector,
                  uint8_t        i_ddLevel,
                  void*          io_rs4Ring,     // IO RS4 ring buffer (caller mgd)
                  uint32_t&      io_ringBufSize, // Query, ring size, or max buffer size
                  uint32_t       i_dbgl )
{
    TorHeader_t* torHeader = (TorHeader_t*)i_ringSection;
    uint32_t ringSectionLoc = 0; // Tracks the position inside the ringSection
    CompressedScanData* nextRs4 = NULL;
    uint32_t rs4Size = 0;
    MyBool_t bFound = UNDEFINED_BOOLEAN;

    // TOR header check
    if ( be32toh(torHeader->magic) != TOR_MAGIC_DYN ||
         torHeader->version != TOR_VERSION ||
         torHeader->ddLevel != i_ddLevel )
    {
        MY_ERR("ERROR in dyn_get_ring: TOR header check failed as follows:\n"
               " torHeader->magic(=0x%08x) != TOR_MAGIC_DYN(=0x%08x)\n"
               " torHeader->version(=%u) != TOR_VERSION(=%u)\n"
               " torHeader->ddLevel(=0x%02x) != i_ddLevel(=0x%02x)\n",
               be32toh(torHeader->magic), TOR_MAGIC_DYN,
               torHeader->version, TOR_VERSION,
               torHeader->ddLevel, i_ddLevel);
        return TOR_HEADER_CHECK_FAILURE;
    }

    ringSectionLoc += sizeof(TorHeader_t);
    nextRs4 = (CompressedScanData*)( (uint8_t*)i_ringSection + ringSectionLoc );
    bFound = false;

    // Traverse the .dynamic ringSection
    do
    {
        rs4Size = be16toh(nextRs4->iv_size);

        // Look for a match
        if ( be16toh(nextRs4->iv_magic) == RS4_MAGIC &&
             (nextRs4->iv_type & RS4_IV_TYPE_SEL_MASK) == RS4_IV_TYPE_SEL_DYN &&
             be16toh(nextRs4->iv_ringId) == i_ringId &&
             be16toh(nextRs4->iv_selector) == i_selector )
        {
            if (rs4Size < io_ringBufSize)
            {
                memcpy( io_rs4Ring, (void*)nextRs4, rs4Size );
                bFound = true;
                break;
            }
            else
            {
                MY_ERR("COND in dyn_get_ring: Size of ring(=%d) > size of buffer(=%d)."
                       " Returning required buffer size.",
                       rs4Size, io_ringBufSize);
                io_ringBufSize = rs4Size;
                return TOR_BUFFER_TOO_SMALL;
            }
        }
        else
        {
            // Move location to the next ring and check if we've reached the end
            ringSectionLoc += rs4Size;

            if ( ringSectionLoc < be32toh(torHeader->size) )
            {
                // Process the next ring
                nextRs4 = (CompressedScanData*)( (uint8_t*)nextRs4 + rs4Size );
            }
            else
            {
                // We have exhausted the ringSection. Nothing else to do.
                bFound = false;
                break;
            }
        }
    }
    while (bFound != true);

    if (bFound == true)
    {
        return TOR_SUCCESS;
    }
    else
    {
        return TOR_DYN_RING_NOT_FOUND;
    }
}
