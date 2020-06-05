/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_tor.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include "p10_ringId.H"
#include "p10_scan_compression.H"
#include "p10_infrastruct_help.H"


///////////////////////////////////////////////////////////////////////////////////
//                       [internal] TOR Access Ring function
//////////////////////////////////////////////////////////////////////////////////
static
int _tor_access_ring( void*          io_ringSection,   // Ring section ptr
                      uint32_t       i_maxRingSectionSize, // Max ringSection size
                      RingId_t       i_ringId,         // Ring ID to extract or append
                      uint8_t        i_chipletId,      // Chiplet ID (ignored for Common rings)
                      RingRequest_t  i_ringRequest,    // {GET,PUT}_SINGLE_RING
                      void*          io_rs4Ring,       // RS4 ring buffer (caller mgd)
                      uint32_t&      io_ringBufSize,   // Query, rs4Size, or max buf size
                      uint32_t       i_dbgl )
{
    int               rc = TOR_SUCCESS;
    TorHeader_t*      torHeader;
    uint32_t          torMagic;
    ChipId_t          chipId;
    TorCpltBlock_t*   cpltBlock;
    TorOffset_t       cpltOffsetSlot; // Offset to TOR chiplet offset slot
    TorOffset_t       cpltOffset; // Offset from ringSection to chiplet section
    TorOffset_t       ringOffsetSlot; // Offset to TOR ring offset slot
    TorOffset_t       ringOffset; // Offset to actual ring container (for GET operation)
    TorOffset_t       ringOffset16; // Offset to actual ring container (for PUT operation)
    uint32_t          torSlotNum; // TOR slot number (within a chiplet section)
    uint32_t          rs4Size;    // Size of RS4 ring container/block.
    RingId_t          rpIndex = UNDEFINED_RING_ID;
    RingId_t          numRings;
    ChipletType_t     chipletType = UNDEFINED_CHIPLET_TYPE;
    ChipletType_t     chipletIndex = UNDEFINED_CHIPLET_TYPE; // Effective chiplet index
    MyBool_t          bInstCase = UNDEFINED_BOOLEAN;
    RingProperties_t* ringProps = NULL;
    ChipletData_t*    chipletData = NULL;
    uint8_t           idxRingEff;      // Effective chiplet ring index
    uint32_t          ringSectionSize;

    torHeader = (TorHeader_t*)io_ringSection;
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

    // Get the ring properties (rp) index
    rpIndex = ringid_convert_ringId_to_rpIndex(i_ringId);

    // Note:  Prior to entering _tor_access_ring(), we must call _tor_header_check()
    //        which also verifies valid ringId.  So no need to check ringId again.

    chipletType = ringProps[rpIndex].chipletType;

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
        if (rc != TOR_INVALID_CHIPLET_TYPE)
        {
            MY_ERR("ringid_get_chipletProps() failed w/rc=0x%08x\n", rc);
        }

        return rc;
    }

    //
    // Check the scope of chipletType and get the effective chipletType's index
    //
    rc = ringid_get_chipletIndex( chipId,
                                  torMagic,
                                  chipletType,
                                  &chipletIndex );

    // TOR_INVALID_CHIPLET_TYPE:  This is not necessarily a fatal or unacceptable error. For
    // example, xip_tool and ipl_customize's dynamic customization for QME will hit
    // this one.  So we can't trace out here in confidence without being "annoying". It's
    // up to the calling TOR APIs to investigate the rc.
    if (rc)
    {
        if (rc != TOR_INVALID_CHIPLET_TYPE)
        {
            MY_ERR("ringid_get_chipletIndex() failed w/rc=0x%08x\n", rc);
        }

        return rc;
    }

    //
    // Determine whether Common or Instance section based on the INSTANCE_RING_MARK
    //
    if ( ringProps[rpIndex].idxRing & INSTANCE_RING_MARK )
    {
        bInstCase = 1;
    }
    else
    {
        bInstCase = 0;
    }

    numRings     = bInstCase ?
                   chipletData->numInstanceRings :
                   chipletData->numCommonRings;

    idxRingEff   = ringProps[rpIndex].idxRing & INSTANCE_RING_MASK; // Always safe

    //
    // Check that chipletId is within chiplet's range (Note that we care only about Instance
    // rings here so we can identify to proper slot. For Common rings, we can ignore the
    // chipletId since there's only one instance slot, namely the 0'th.)
    //
    if ( bInstCase &&
         ( i_chipletId < chipletData->chipletBaseId ||
           i_chipletId > (chipletData->chipletBaseId + chipletData->numChipletInstances - 1) ) )
    {
        // TOR_INVALID_CHIPLET_ID:  This is not necessarily an error. User codes may differ
        // in their knowledge what is an acceptable value for the chipletId. So we can't
        // trace out here in confidence. It's up to the caller to investigate the rc.
        return TOR_INVALID_CHIPLET_ID;
    }

    //
    // Unless we find a ring, then the following rc will be returned
    //
    rc = TOR_RING_HAS_NO_TOR_SLOT;

    //
    // Now traverse the chiplet's Common or Instance ring section
    //
    if (numRings) // Only proceed if chiplet has [Common/Instance] rings.
    {
        // Calc offset to chiplet's CMN or INST section, cpltOffset
        // - Note that the TOR cpltOffset is assumed to be wrt to ringSection origin
        //
        // 1. Calc offset to TOR chiplet offset slot pointing to chiplet's COM or INST section
        cpltOffsetSlot = sizeof(TorHeader_t) +
                         chipletIndex * sizeof(TorCpltBlock_t) +
                         bInstCase * sizeof(cpltBlock->cmnOffset);
        // 2. Retrive chiplet offset and endian convert
        cpltOffset = *(TorOffset_t*)( (uint8_t*)io_ringSection + cpltOffsetSlot );
        cpltOffset = be16toh(cpltOffset); // <- This is the final TOR chiplet offset

        //
        // Calc the effective TOR offset slot index number (within the chiplet's Common
        // or Instance ring section)
        //
        torSlotNum = bInstCase * (i_chipletId - chipletData->chipletBaseId) * numRings + idxRingEff;

        // Calc offset to actual ring, ringOffset
        // - Note that ringOffset is assumed to be wrt to ringSection origin
        //
        // 1. Calc offset to the TOR ring offset slot (which points to the actual ring)
        ringOffsetSlot = cpltOffset + torSlotNum * sizeof(ringOffset);
        // 2. Retrieve ring offset and endian convert
        ringOffset = *(TorOffset_t*)( (uint8_t*)io_ringSection + ringOffsetSlot );
        ringOffset = be16toh(ringOffset); // <- This is the final TOR ring offset

        if (i_ringRequest == GET_SINGLE_RING)
        {
            rs4Size = 0;

            if (ringOffset)
            {
                RingId_t ringIdRs4 = be16toh( ((CompressedScanData*)
                                               ((uint8_t*)io_ringSection + ringOffset))->iv_ringId );

                if (i_ringId != ringIdRs4)
                {
                    MY_ERR("ERROR: _tor_access_ring(): Requested ringId(=0x%03x) and RS4 header's"
                           " ringId(=0x%03x) don't match for rpIndex=0x%03x\n",
                           i_ringId, ringIdRs4, rpIndex);
                    return TOR_RING_ID_MISMATCH;
                }

                rs4Size = be16toh( ((CompressedScanData*)
                                    ((uint8_t*)io_ringSection + ringOffset))->iv_size );

                if (rs4Size <= io_ringBufSize)
                {
                    memcpy( io_rs4Ring,
                            (void*)((uint8_t*)io_ringSection + ringOffset),
                            rs4Size );

                    if (i_dbgl > 0)
                    {
                        MY_DBG("Found a ring:  ringId=0x%x and rs4Size=%u\n",
                               i_ringId, rs4Size);
                    }

                    rc = TOR_SUCCESS;
                }
                else
                {
                    if (i_dbgl > 0)
                    {
                        MY_DBG("io_ringBufSize(=%u) is less than rs4Size(=%u).\n",
                               io_ringBufSize, rs4Size);
                    }

                    io_ringBufSize = rs4Size;
                    return TOR_BUFFER_TOO_SMALL;
                }
            }
            else
            {
                rc = TOR_RING_IS_EMPTY;
            }

            return rc;

        }
        else if (i_ringRequest == PUT_SINGLE_RING)
        {
            // We can not overwrite an existing ring
            if (ringOffset)
            {
                MY_ERR("Ring container is already present in image\n");
                MY_ERR("  Ring section addr: 0x%016lx  (First 8B: 0x%016lx)\n",
                       (uintptr_t)io_ringSection,
                       be64toh(*((uint64_t*)io_ringSection)));
                MY_ERR("  cpltOffset=0x%08x, torSlotNum=0x%x, ringOffset=0x%04x\n",
                       cpltOffset, torSlotNum, ringOffset);
                return TOR_RING_IS_POPULATED;
            }

            // Check we can fit the ring
            ringSectionSize = be32toh(torHeader->size);
            rs4Size = be16toh( ((CompressedScanData*)io_rs4Ring)->iv_size );

            if ( (ringSectionSize + rs4Size) > i_maxRingSectionSize )
            {
                MY_ERR("ERROR: _tor_access_ring() : Appending the ring would overflow"
                       " the max ring section size:\n"
                       " Current ringSectionSize:  %d\n"
                       " Size of ring to be added: %d\n"
                       " Max ringSection Size:     %d\n",
                       ringSectionSize, rs4Size, i_maxRingSectionSize);
                return TOR_BUFFER_TOO_SMALL;
            }

            // Then calculate the TOR ring offset value and put it into the TOR ring
            // slot. But first, check that the offset value can be contained within
            // the 2B of the TOR ring slot.
            // - Note that TOR offset value to the ring is wrt to ringSection origin
            if ( ringSectionSize <= MAX_TOR_RING_OFFSET )
            {
                ringOffset16 = htobe16(ringSectionSize);
                memcpy( (uint8_t*)io_ringSection + ringOffsetSlot,
                        &ringOffset16,
                        sizeof(ringOffset16) );
            }
            else
            {
                MY_ERR("Code bug: Ring offset (=0x%x) exceeds MAX_TOR_RING_OFFSET (=0x%x)\n",
                       ringSectionSize, MAX_TOR_RING_OFFSET);
                return TOR_OFFSET_TOO_BIG;
            }

            // Finally, append the ring to the end of ringSection.
            memcpy( (uint8_t*)io_ringSection + ringSectionSize,
                    (uint8_t*)io_rs4Ring,
                    rs4Size );

            // Update the ring section size in the TOR header
            torHeader->size = htobe32(ringSectionSize + rs4Size);

            return TOR_SUCCESS;
        }
        else
        {
            MY_ERR("Ring request (i_ringRequest=%d) is not supported\n", i_ringRequest);
            return TOR_INVALID_RING_REQUEST;
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

} // End of _tor_access_ring()



//////////////////////////////////////////////////////////////////////////////////////////
///               [internal] TOR Header and RingId Check function
//////////////////////////////////////////////////////////////////////////////////////////
int _tor_header_and_ringId_check( void*           i_ringSection,  // Ring section ptr
                                  RingId_t        i_ringId,       // Ring ID
                                  uint8_t         i_ddLevel,      // DD level
                                  uint32_t        i_dbgl )
{
    int            rc = TOR_SUCCESS;
    uint32_t       torMagic;
    TorHeader_t*   torHeader;

    torHeader = (TorHeader_t*)i_ringSection;
    torMagic = be32toh(torHeader->magic);

    if (i_dbgl > 0)
    {
        MY_DBG("TOR header fields\n"
               "  magic:         0x%08x\n"
               "  version:       %d\n"
               "  chipId:        0x%x\n"
               "  ddLevel:       0x%x\n"
               "  rtVersion:     %u\n"
               "  size:          %d\n"
               "API parms\n"
               "  i_ddLevel:     0x%x\n",
               torMagic, torHeader->version, torHeader->chipId,
               torHeader->ddLevel, torHeader->rtVersion,
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

    // Check for valid ring ID and chip ID
    rc = ringid_check_ringId(torHeader->chipId, i_ringId);

    if ( rc != TOR_SUCCESS )
    {
        // Only trace out what we know could be an error. Return any rc!=success.
        if ( rc == TOR_INVALID_CHIP_ID )
        {
            MY_ERR("ERROR: TOR ringId check: ringid_check_ringId() failed w/rc=0x%08x"
                   " which is an invalid chipId(=0x%x)\n",
                   rc, torHeader->chipId);
        }

        return rc;
    }

    // Check TOR header
    const uint8_t RING_TABLE_VERSION_HWIMG = ringid_get_ring_table_version_hwimg();

    if ( torMagic >> 8 != TOR_MAGIC ||
         torHeader->version != TOR_VERSION ||
         torHeader->rtVersion > RING_TABLE_VERSION_HWIMG )
    {
        MY_ERR("ERROR: TOR header check:\n"
               "  magic:       0x%08x (TOR_MAGIC: 0x%08x)\n"
               "  version:     %u (TOR_VERSION: %u)\n"
               "  rtVersion:   %u (RING_TABLE_VERSION_HWIMG: %u)\n"
               "  size:        %d\n",
               torMagic, TOR_MAGIC,
               torHeader->version, TOR_VERSION,
               torHeader->rtVersion, RING_TABLE_VERSION_HWIMG,
               be32toh(torHeader->size));
        return TOR_HEADER_CHECK_FAILURE;
    }

    // Check ddLevel
    if ( i_ddLevel != torHeader->ddLevel &&
         i_ddLevel != UNDEFINED_DD_LEVEL )
    {
        MY_ERR("ERROR: TOR DD check: Requested DD level (=0x%x) doesn't match TOR header DD"
               " level (=0x%x) nor UNDEFINED_DD_LEVEL (=0x%x)\n",
               i_ddLevel, torHeader->ddLevel, UNDEFINED_DD_LEVEL);
        return TOR_DD_LEVEL_NOT_FOUND;
    }

    return rc;
} // End of _tor_header_and_ringId_check()


//////////////////////////////////////////////////////////////////////////////////////////
///                     [internal] TOR RS4 Header Check function
//////////////////////////////////////////////////////////////////////////////////////////
/// Notes:
/// - The checks in this function is not necessarily catastrophic. We merely make a note
///   of any inconsistencies and leave it up to caller to decide the action.
///
int _tor_rs4_header_check( void*                i_ringSection,
                           CompressedScanData*  i_rs4Ring,
                           MyBool_t             i_bCustom ) // Indicates custom SBE or QME section
{
    int      rc = TOR_SUCCESS;

    TorHeader_t* torHeader = (TorHeader_t*)i_ringSection;
    uint32_t     torMagic = be32toh(torHeader->magic);
    uint8_t      expectedOrigType = 0;

    switch (torMagic)
    {
        case TOR_MAGIC_SBE:
        case TOR_MAGIC_QME:
            if (i_bCustom)
            {
                expectedOrigType = RS4_IV_TYPE_ORIG_BASE |
                                   RS4_IV_TYPE_ORIG_MVPD |
                                   RS4_IV_TYPE_ORIG_OVLY |
                                   RS4_IV_TYPE_ORIG_DYN;
            }
            else
            {
                expectedOrigType = RS4_IV_TYPE_ORIG_BASE;
            }

            break;

        case TOR_MAGIC_OVLY:
            expectedOrigType = RS4_IV_TYPE_ORIG_OVLY;
            break;

        case TOR_MAGIC_DYN:
            expectedOrigType = RS4_IV_TYPE_ORIG_DYN;
            break;

        case TOR_MAGIC_OVRD:
            expectedOrigType = RS4_IV_TYPE_ORIG_OVRD;
            break;

        default:
            MY_ERR("ERROR: _tor_rs4_header_check: Invalid torMagic(=0x%08x)\n",
                   torMagic);
            return TOR_INVALID_MAGIC_NUMBER;
            break;
    }

    //
    // Check for RS4 header inconsistency (in order of decreasing severity)
    //
    // Since the error checking below is a little unusual, here's why:
    // - On first inconsistency check a) trace out partial info, b) make a  note of rc
    //   condition, and c) skip any further checks and break out.
    // - After break out, continue tracing out full details.
    //
    do
    {
        if ( be16toh(i_rs4Ring->iv_magic) != RS4_MAGIC )
        {
            MY_ERR("_tor_rs4_header_check: RS4->iv_magic is invalid for");
            rc = TOR_INVALID_RS4_MAGIC;
            break;
        }

        if ( i_rs4Ring->iv_version != RS4_VERSION )
        {
            MY_ERR("_tor_rs4_header_check: RS4->iv_version is invalid for");
            rc = TOR_INVALID_RS4_VERSION;
            break;
        }

        if ( ((i_rs4Ring->iv_type & RS4_IV_TYPE_ORIG_MASK) & expectedOrigType) == false )
        {
            MY_ERR("_tor_rs4_header_check: RS4->iv_type is invalid for");
            rc = TOR_INVALID_RS4_TYPE;
            break;
        }
    }
    while (0);

    // ..if rc==true from above check, continue tracing out full details.
    if (rc)
    {
        MY_ERR(" ringId=0x%04x, selector=0x%04x and bCustom=%i in ringSection w/TOR magic=0x%08x:\n"
               "  iv_magic: 0x%04x (RS4_MAGIC: 0x%04x)\n"
               "  iv_version: %u (RS4_VERSION: %u)\n"
               "  iv_type: 0x%02x (RS4_IV_TYPE_ORIG_MASK: 0x%02x, expectedOrigType: 0x%02x",
               be16toh(i_rs4Ring->iv_ringId), be16toh(i_rs4Ring->iv_selector), i_bCustom,
               torMagic,
               be16toh(i_rs4Ring->iv_magic), RS4_MAGIC,
               i_rs4Ring->iv_version, RS4_VERSION,
               i_rs4Ring->iv_type, RS4_IV_TYPE_ORIG_MASK, expectedOrigType);

        return rc;
    }
    else
    {
        return TOR_SUCCESS;
    }
} // End of _tor_rs4_header_check()


/////////////////////////////////////////////////////////////////////////////////////
//                             TOR Get Single Ring API
/////////////////////////////////////////////////////////////////////////////////////
int tor_get_single_ring ( void*         i_ringSection,  // Ring section ptr
                          uint8_t       i_ddLevel,      // DD level
                          RingId_t      i_ringId,       // Ring ID
                          uint8_t       i_chipletId,    // Chiplet ID (ignored for Common rings)
                          void*         io_rs4Ring,     // IO RS4 ring buffer (caller mgd)
                          uint32_t&     io_ringBufSize, // (See header)
                          MyBool_t      i_bCustom,      // Indicates whether custom ringSection
                          uint32_t      i_dbgl )
{
    int          rc = TOR_SUCCESS;

    rc = _tor_header_and_ringId_check( i_ringSection,
                                       i_ringId,
                                       i_ddLevel,
                                       i_dbgl );

    // Explanation to the "list" of RCs that we exclude from tracing out:
    // TOR_HOLE_RING_ID:    Can happen if a ring has been removed from the ring list
    // TOR_INVALID_RING_ID: Can happen if caller carelessly cycles through ringIds
    if ( rc )
    {
        if ( rc != TOR_HOLE_RING_ID &&
             rc != TOR_INVALID_RING_ID )
        {
            MY_ERR("ERROR: tor_get_single_ring: _tor_header_and_ringId_check() failed"
                   " w/rc=0x%08x\n",
                   rc);
        }

        return rc;
    }

    rc = _tor_access_ring( i_ringSection,
                           0, // Not used. Only used when appending a ring.
                           i_ringId,
                           i_chipletId,
                           GET_SINGLE_RING,
                           io_rs4Ring,
                           io_ringBufSize,
                           i_dbgl );

    // Explanation to the "list" of RCs that we exclude from tracing out:
    // TOR_RING_IS_EMPTY:  Normal scenario (will occur frequently).
    // TOR_RING_HAS_NO_TOR_SLOT:  Will be caused a lot by ipl_image_tool, but is an error if
    //                     called by any other user.
    // TOR_INVALID_CHIPLET_ID:  Not necessarily an error as a user may be sweeping through a
    //                     worst case range to "get all I can get".
    // TOR_INVALID_CHIPLET_TYPE:  Also somewhat normal scenario since the caller should,
    //                     in princple, be able to mindlessly request a ringId without
    //                     having to figure out first if that ringId belongs to a chiplet
    //                     that is valid for the context. But really this is a gray area.
    //                     For now, we omit to trace out as we will hit this rc condition
    //                     in both ipl_image_tool and ipl_customize (RT_QME phase).
    if ( rc &&
         rc != TOR_RING_IS_EMPTY &&
         rc != TOR_RING_HAS_NO_TOR_SLOT &&
         rc != TOR_INVALID_CHIPLET_ID &&
         rc != TOR_INVALID_CHIPLET_TYPE )
    {
        MY_ERR("ERROR: tor_get_single_ring: _tor_access_ring() failed w/rc=0x%08x\n",
               rc);
        return rc;
    }

    if ( rc == TOR_SUCCESS )
    {
        rc = _tor_rs4_header_check( i_ringSection,
                                    (CompressedScanData*)io_rs4Ring,
                                    i_bCustom );
        // Do not trace out. Let caller decide if acceptable error
        return rc;
    }

    return rc;
} // End of tor_get_single_ring()



////////////////////////////////////////////////////////////////////////////////////////
//                                 TOR Append Ring API
///////////////////////////////////////////////////////////////////////////////////////
int tor_append_ring( void*           io_ringSection,       // Ring section ptr
                     uint32_t        i_maxRingSectionSize, // Max ringSection size
                     RingId_t        i_ringId,             // Ring ID to append
                     uint8_t         i_chipletId,          // Chiplet ID (ignored for Common rings)
                     void*           i_rs4Ring,            // RS4 ring container
                     MyBool_t        i_bCustom,            // Indicates whether custom ringSection
                     uint32_t        i_dbgl )              // Debug option
{
    int          rc = TOR_SUCCESS;
    uint32_t     ringBufSize;

    rc = _tor_header_and_ringId_check( io_ringSection,
                                       i_ringId,
                                       UNDEFINED_DD_LEVEL,
                                       i_dbgl );

    if (rc)
    {
        MY_ERR("ERROR: tor_append_ring: _tor_header_and_ringId_check() failed w/rc=0x%08x\n",
               rc);
        return rc;
    }

    if ( ringid_has_derivs( ((TorHeader_t*)io_ringSection)->chipId, i_ringId) )
    {
        MY_DBG("INFO(NOT-AN-ERROR): Can't append ringId=0x%x since it has derivatives. Only the"
               " derivative rings, e.g. *_bucket, can be appended.\n",
               i_ringId);
        return TOR_RING_HAS_DERIVS;
    }

    rc = _tor_rs4_header_check( io_ringSection,
                                (CompressedScanData*)i_rs4Ring,
                                i_bCustom );

    if (rc)
    {
        MY_ERR("ERROR: tor_append_ring: _tor_rs4_header_check() failed w/rc=0x%08x",
               rc);
        return rc;
    }

    rc =  _tor_access_ring( io_ringSection,
                            i_maxRingSectionSize,
                            i_ringId,
                            i_chipletId,
                            PUT_SINGLE_RING,
                            i_rs4Ring,
                            ringBufSize, // Not used here
                            i_dbgl );

    // Explanation to the "list" of RCs that we exclude from tracing out:
    // TOR_INVALID_CHIPLET_TYPE:  Not really a normal scenario though it's possible a
    //                     caller will mindlessly request a ringId to be appended  without
    //                     knowing ahead of the call if the ringId belongs to the chiplet
    //                     indicated in ringSection's torMagic. But this is a gray area.
    //                     For now, we omit to trace out as we will hit this rc condition
    //                     in ipl_customize (RT_QME phase).
    if ( rc &&
         rc != TOR_INVALID_CHIPLET_TYPE )
    {
        MY_ERR("ERROR: tor_append_ring: _tor_access_ring() failed w/rc=0x%08x for"
               " ringId=0x%x\n",
               rc, i_ringId);
        return rc;
    }

    return rc;
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
    torHeader->rtVersion = ringid_get_ring_table_version_hwimg();
    //torHeader->size = Updated after creating TOR skeleton

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

            // Update the current chiplet block's offset to the Common or Instance ring section
            // - Note that the TOR chiplet offsets are assumed to be wrt to ringSection origin
            if (bInstCase)
            {
                torChipletBlock->instOffset = htobe16(ringSectionSize);
            }
            else
            {
                torChipletBlock->cmnOffset = htobe16(ringSectionSize);
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
            sizeRingSlots = myByteAlign(4, numRingSlots * sizeof(TorOffset_t));
            memset( (uint8_t*)io_ringSection + ringSectionSize,
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
// Return this code's TOR version.
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
    int rc = TOR_SUCCESS;

    uint32_t   rs4Size = 0;
    uint32_t   ringSectionSize = 0;

    TorHeader_t* torHeader = (TorHeader_t*)io_ringSection;

    rc = _tor_rs4_header_check( io_ringSection,
                                (CompressedScanData*)i_rs4Ring,
                                UNDEFINED_BOOLEAN ); // Only relevant for SBE and QME sections

    if (rc)
    {
        MY_ERR("ERROR: dyn_append_ring: _tor_rs4_header_check() failed w/rc=0x%08x",
               rc);
        return rc;
    }

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
        MY_ERR("ERROR in dyn_append_ring: ringSectionSize(=%u) + rs4Size(=%u)"
               " would exceed maxRingSectionSize(=%d)\n",
               ringSectionSize, rs4Size, i_maxRingSectionSize);
        return TOR_BUFFER_TOO_SMALL;
    }

    // Update the ring section size in the TOR header
    torHeader->size = htobe32(ringSectionSize + rs4Size);

    return TOR_SUCCESS;
}



////////////////////////////////////////////////////////////////////////////////////////
//                           Dynamic Inits Get Ring API
///////////////////////////////////////////////////////////////////////////////////////
int dyn_get_ring( void*          i_ringSection,
                  RingId_t       i_ringId,
                  Rs4Selector_t  i_selector,
                  uint8_t        i_ddLevel,
                  void*          io_rs4Ring,
                  uint32_t&      io_ringBufSize,
                  uint32_t       i_dbgl )
{
    int  rc = TOR_SUCCESS;
    TorHeader_t* torHeader = (TorHeader_t*)i_ringSection;
    uint32_t ringSectionLoc = 0; // Tracks the position inside the ringSection
    CompressedScanData* nextRs4 = NULL;
    uint32_t rs4Size = 0;
    MyBool_t bFound = UNDEFINED_BOOLEAN;

    // Check for valid ring ID and chip ID
    rc = ringid_check_ringId(torHeader->chipId, i_ringId);

    if ( rc != TOR_SUCCESS )
    {
        // Only trace out what we know could be an error. Return any rc!=success.
        if ( rc == TOR_INVALID_CHIP_ID )
        {
            MY_ERR("ERROR: dyn_get_ring: ringid_check_ringId() failed w/rc=0x%08x"
                   " which is an invalid chipId(=0x%x)\n",
                   rc, torHeader->chipId);
        }

        return rc;
    }

    // TOR header check
    const uint8_t RING_TABLE_VERSION_HWIMG = ringid_get_ring_table_version_hwimg();

    if ( be32toh(torHeader->magic) != TOR_MAGIC_DYN ||
         torHeader->version != TOR_VERSION ||
         torHeader->ddLevel != i_ddLevel ||
         torHeader->rtVersion != RING_TABLE_VERSION_HWIMG )
    {
        MY_ERR("ERROR: dyn_get_ring: TOR header check failed as follows:\n"
               " torHeader->magic(=0x%08x) != TOR_MAGIC_DYN(=0x%08x)\n"
               " torHeader->version(=%u) != TOR_VERSION(=%u)\n"
               " torHeader->ddLevel(=0x%02x) != i_ddLevel(=0x%02x)\n"
               " torHeader->rtVersion(=%u) != RING_TABLE_VERSION_HWIMG(=%u)\n",
               be32toh(torHeader->magic), TOR_MAGIC_DYN,
               torHeader->version, TOR_VERSION,
               torHeader->ddLevel, i_ddLevel,
               torHeader->rtVersion, RING_TABLE_VERSION_HWIMG);
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
        if ( be16toh(nextRs4->iv_ringId) == i_ringId &&
             be16toh(nextRs4->iv_selector) == i_selector )
        {
            if (rs4Size <= io_ringBufSize)
            {
                memcpy( io_rs4Ring, (void*)nextRs4, rs4Size );
                bFound = true;
                break;
            }
            else
            {
                MY_ERR("COND in dyn_get_ring: Size of ring(=%u) > size of buffer(=%u)."
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
        // Check for valid RS4 header
        rc = _tor_rs4_header_check( i_ringSection,
                                    (CompressedScanData*)io_rs4Ring,
                                    UNDEFINED_BOOLEAN ); //The dynamic section is never customized
        // Do not trace out. Let caller decide if acceptable error
        return rc;
    }
    else
    {
        return TOR_DYN_RING_NOT_FOUND;
    }
}
