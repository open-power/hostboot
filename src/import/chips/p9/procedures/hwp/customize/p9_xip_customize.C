/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/customize/p9_xip_customize.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <p9_xip_customize.H>
#include <p9_xip_image.h>
#include <p9_ring_identification.H>
#include <p9_get_mvpd_ring.H>
#include <p9_tor.H>
#include <p9_scan_compression.H>
#include <p9_infrastruct_help.H>
#include <p9_ringId.H>

using namespace fapi2;

#define MBOX_ATTR_WRITE(ID,TARGET,IMAGE) \
    { \
        fapi2::ID##_Type ID##_attrVal; \
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ID,TARGET,ID##_attrVal),\
                 "MBOX_ATTR_WRITE: Error getting %s", #ID); \
        FAPI_TRY(p9_xip_set_scalar(IMAGE,#ID,ID##_attrVal),\
                 "MBOX_ATTR_WRITE: Error writing attr %s to seeprom image",\
                 #ID); \
    }

fapi2::ReturnCode writeMboxRegs (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void* i_image)
{
    FAPI_DBG ("writeMboxRegs Entering...");
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    MBOX_ATTR_WRITE (ATTR_I2C_BUS_DIV_REF,          i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_EQ_GARD,                  i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_EC_GARD,                  i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_NEST_PLL_BUCKET,          FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_BOOT_FREQ_MULT,           i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_CLOCK_PLL_MUX,            i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_DPLL_BYPASS,              i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_SS_FILTER_BYPASS,         i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_CP_FILTER_BYPASS,         i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_IO_FILTER_BYPASS,         i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_NEST_MEM_X_O_PCI_BYPASS,  i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_SYSTEM_IPL_PHASE,         FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_SYS_FORCE_ALL_CORES,      FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_RISK_LEVEL,               FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_DISABLE_HBBL_VECTORS,     FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_MC_SYNC_MODE,             i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_SBE_MASTER_CHIP,     i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_FABRIC_GROUP_ID,     i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_FABRIC_CHIP_ID,      i_proc_target,   i_image);

fapi_try_exit:
    FAPI_DBG("writeMboxRegs Exiting...");
    return fapi2::current_err;
}

fapi2::ReturnCode writePG(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void* i_image)
{
    FAPI_DBG ("writePG Entering...");
    const uint8_t IMG_PG_ENTRIES = 64;

    for (auto l_perv_tgt : i_proc_target.getChildren<fapi2::TARGET_TYPE_PERV>())
    {
        uint8_t l_unit_id = 0;
        uint16_t l_pg_data = 0;
        uint8_t l_pg_idx = 0;

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_perv_tgt, l_unit_id),
                  "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)" );
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PG, l_perv_tgt, l_pg_data),
                  "Error from FAPI_ATTR_GET (ATTR_PG)" );

        l_pg_idx = l_unit_id;

        FAPI_ASSERT( l_pg_idx < IMG_PG_ENTRIES,
                     fapi2::XIPC_BAD_PG_XLATE().
                     set_CHIP_TARGET(i_proc_target).
                     set_CHIP_UNIT_POS(l_unit_id).
                     set_PG_INDEX(l_pg_idx),
                     "Code bug: Invalid translation from PERV chip unit position to image PG index" );

        // Update the image
        FAPI_TRY( p9_xip_set_element(i_image, "ATTR_PG", l_pg_idx, l_pg_data),
                  "Error from p9_xip_set_element (idx %d)", l_pg_idx );

        FAPI_DBG("Write value of pg_data[%d] = %08X", l_pg_idx, l_pg_data);
    }

    for (auto l_pg_idx = 0; l_pg_idx < IMG_PG_ENTRIES; l_pg_idx++)
    {
        uint64_t l_val;
        FAPI_TRY( p9_xip_get_element(i_image, "ATTR_PG", l_pg_idx, &l_val),
                  "Error from p9_xip_get_element (idx %d)", l_pg_idx );
        FAPI_DBG("Read value of pg_data[%d] = %08X", l_pg_idx, l_val);
    }

fapi_try_exit:
    FAPI_DBG ("writePG Exiting...");
    return fapi2::current_err;
}


//  Function: _fetch_and_insert_vpd_rings()
//
//  Parameter list:
//  const fapi::Target &i_target:    Processor chip target.
//  void*      i_ringSection:        Ptr to ring section.
//  uint32_t&  io_ringSectionSize:   Running ring section size
//  uint32_t   i_maxRingSectionSize: Max ring section size
//  uint8_t    i_sysPhase:           ={HB_SBE, RT_CME, RT_SGPE}
//  void*      i_vpdRing:            VPD ring buffer.
//  uint32_t   i_vpdRingSize:        Size of VPD ring buffer.
//  void*      i_ringBuf2:           Ring work buffer.
//  uint32_t   i_ringBufSize2:       Size of ring work buffer.
//  const RingIdList i_ring:         The ring ID list (#G or #R list)
//  uint32_t&  io_bootCoreMask:      Desired (in) and actual (out) boot cores.
//

fapi2::ReturnCode _fetch_and_insert_vpd_rings(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void*           i_ringSection,
    uint32_t&       io_ringSectionSize,
    uint32_t        i_maxRingSectionSize,
    uint8_t         i_sysPhase,
    void*           i_vpdRing,
    uint32_t        i_vpdRingSize,
    void*           i_ringBuf2,
    uint32_t        i_ringBufSize2,
    const RingIdList     i_ring,
    uint32_t&       io_bootCoreMask )
{
    ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    int        l_rc = 0;

    uint8_t    l_chipletId;
    uint8_t    l_ringsPerChipletId = 0;
    uint8_t    l_instanceIdMax;
    uint8_t    l_evenOdd;
    uint64_t   l_evenOddMaskStart;
    uint64_t   l_evenOddMask;    // 0:even, 1:odd
    uint8_t    bSkipRing = 0;


    FAPI_DBG("Entering _fetch_and_insert_vpd_rings");

    // Filter out GPTR requests. Not supported in DD1. Coming in through initfiles instead.
    if (i_ring.vpdRingClass == VPD_RING_CLASS_GPTR)
    {
        FAPI_INF("Skipping extraction of GPTR ring...");
        fapi2::current_err = l_fapiRc;
        goto fapi_try_exit;
    }

    // For EX rings, there's two rings listed in the Mvpd per [EQ] chipletId
    //  listed in ring_identification.C: One for each of the two EX, even and odd.
    //  Each of these two rings have the same [EQ] chipletId encoded in their
    //  iv_chipletId (current RS4 header) or iv_scanAddress (next gen RS4 header).
    //  They are distinguished by their even-odd bits in iv_scanSelect as follows:
    if (i_ring.vpdRingClass == VPD_RING_CLASS_EX_INS)
    {
        l_ringsPerChipletId = 2;

        switch (i_ring.ringId)
        {
            case ex_l3_refr_time:
            case ex_l3_refr_repr:
                l_evenOddMaskStart = ((uint64_t)0x00080000) << 32;
                break;

            case ex_l2_repr:
                l_evenOddMaskStart = ((uint64_t)0x00800000) << 32;
                break;

            case ex_l3_repr:
                l_evenOddMaskStart = ((uint64_t)0x02000000) << 32;
                break;

            default:
                FAPI_ASSERT( false,
                             fapi2::XIPC_MVPD_RING_ID_MESS().
                             set_CHIP_TARGET(i_proc_target).
                             set_RING_ID(i_ring.ringId),
                             "Code bug: Wrong assumption about supported ringIds in this context. "
                             "ringId=%d(=0x%x)(=ringId.ringName) is not allowed here. ",
                             i_ring.ringId, i_ring.ringId, i_ring.ringName );
                break;
        }
    }
    else
    {
        l_ringsPerChipletId = 1;
        l_evenOddMaskStart = 0;
    }


    // We use ring.instanceIdMax column to govern max value of instanceIdMax (i.e., the
    //   max chipletId). But unlike in P8, in P9 we will not search for chipletId=0xff in P9
    //   MVPD. It is no longer used in the MVPD. We merely keep the multicast Id, 0xff, in
    //   the ring list for now, just in case it is needed later on.
    if (i_ring.instanceIdMax == 0xff)
    {
        l_instanceIdMax = i_ring.instanceIdMin;
    }
    else
    {
        l_instanceIdMax = i_ring.instanceIdMax;
    }

    for (l_chipletId = i_ring.instanceIdMin; l_chipletId <= l_instanceIdMax; l_chipletId++)
    {

        for (l_evenOdd = 0; l_evenOdd < l_ringsPerChipletId; l_evenOdd++)
        {

            l_evenOddMask = l_evenOddMaskStart >> l_evenOdd;

            FAPI_INF("_fetch_and_insert_vpd_rings: (ringId,chipletId) = (0x%02X,0x%02x)",
                     i_ring.ringId, l_chipletId);

            auto l_vpdRingSize = i_vpdRingSize;
            MvpdKeyword l_mvpdKeyword;

            switch (i_ring.vpdKeyword)
            {
                case VPD_KEYWORD_PDG:  // #G Time rings
                    l_mvpdKeyword = fapi2::MVPD_KEYWORD_PDG;
                    break;

                case VPD_KEYWORD_PDR:  // #R Repair rings
                    l_mvpdKeyword = fapi2::MVPD_KEYWORD_PDR;
                    break;

                default:
                    FAPI_ASSERT( false,
                                 fapi2::XIPC_INVALID_VPD_KEYWORD().
                                 set_CHIP_TARGET(i_proc_target).
                                 set_VPD_KEYWORD(i_ring.vpdKeyword),
                                 "Code bug: Unsupported value of vpdKeyword (=%d)",
                                 i_ring.vpdKeyword );
                    break;
            }


            /////////////////////////////////////////////////////////////////////
            // Fetch rings from the MVPD:
            /////////////////////////////////////////////////////////////////////

            // If an EC ring is an instance ring, then check if EC chipletId is represented in bootCoreMask,
            //   and only fetch if it is.
            // If an EX/EQ ring is an instance ring, then check if the associated EC chipletId range in
            //   in bootCoreMask is represented by at least one EC chipletId, and fetch it if it is.
            // Otherwise the ring is a common ring which we always must fetch.

            bSkipRing = 0;

            if ( i_ring.vpdRingClass == VPD_RING_CLASS_EQ_INS &&
                 (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_SGPE) )
            {
                // Fetch EQ instance ring
                // - Fetch for SBE and SGPE only.

                if ( ((0x0000000F << ((NUM_OF_QUADS - 1)*CORES_PER_QUAD)) >> ((l_chipletId - i_ring.instanceIdMin)*CORES_PER_QUAD)) &
                     io_bootCoreMask )
                {
                    l_fapiRc = getMvpdRing( MVPD_RECORD_CP00,
                                            l_mvpdKeyword,
                                            i_proc_target,
                                            l_chipletId,
                                            l_evenOddMask,
                                            i_ring.ringId,
                                            (uint8_t*)i_vpdRing,
                                            l_vpdRingSize );
                }
                else
                {
                    bSkipRing = 1;
                }

            }
            else if ( i_ring.vpdRingClass == VPD_RING_CLASS_EX_INS &&
                      (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_SGPE) )
            {
                // Fetch EX instance ring
                // - Fetch for SBE and SGPE only.

                if ( ((0x0000000F << ((NUM_OF_QUADS - 1)*CORES_PER_QUAD)) >> ((l_chipletId - i_ring.instanceIdMin)*CORES_PER_QUAD)) &
                     io_bootCoreMask )
                {
                    l_fapiRc = getMvpdRing( MVPD_RECORD_CP00,
                                            l_mvpdKeyword,
                                            i_proc_target,
                                            l_chipletId,
                                            l_evenOddMask,
                                            i_ring.ringId,
                                            (uint8_t*)i_vpdRing,
                                            l_vpdRingSize );
                }
                else
                {
                    bSkipRing = 1;
                }

            }
            else if ( i_ring.vpdRingClass == VPD_RING_CLASS_EC_INS &&
                      (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_CME) )
            {
                // Fetch EC instance ring
                // - Fetch for SBE and CME only.

                if ( ((0x00000001 << (NUM_OF_CORES - 1)) >> (l_chipletId - i_ring.instanceIdMin)) & io_bootCoreMask )
                {
                    l_fapiRc = getMvpdRing( MVPD_RECORD_CP00,
                                            l_mvpdKeyword,
                                            i_proc_target,
                                            l_chipletId,
                                            l_evenOddMask,
                                            i_ring.ringId,
                                            (uint8_t*)i_vpdRing,
                                            l_vpdRingSize );
                }
                else
                {
                    bSkipRing = 1;
                }

            }
            else if ( i_sysPhase == SYSPHASE_HB_SBE ||
                      (i_sysPhase == SYSPHASE_RT_CME  && i_ring.vpdRingClass == VPD_RING_CLASS_EC) ||
                      (i_sysPhase == SYSPHASE_RT_SGPE && (i_ring.vpdRingClass == VPD_RING_CLASS_EX ||
                              i_ring.vpdRingClass == VPD_RING_CLASS_EQ)) )
            {
                // Fetch common ring
                // - Fetch all VPD rings for SBE.
                // - Fetch only EC VPD rings for CME.
                // - Fetch only EX+EQ VPD rings for SGPE.

                l_fapiRc = getMvpdRing( MVPD_RECORD_CP00,
                                        l_mvpdKeyword,
                                        i_proc_target,
                                        l_chipletId,
                                        l_evenOddMask,
                                        i_ring.ringId,
                                        (uint8_t*)i_vpdRing,
                                        l_vpdRingSize );
            }
            else
            {
                bSkipRing = 1;
            }


            ///////////////////////////////////////////////////////////////////////
            //Append VPD ring to the ring section
            ///////////////////////////////////////////////////////////////////////

            if (bSkipRing)
            {
                continue;
            }
            else if (l_fapiRc == fapi2::FAPI2_RC_SUCCESS)
            {

                auto l_vpdChipletId = ((CompressedScanData*)i_vpdRing)->iv_chipletId;

                // Even though success, checking that chipletId didn't somehow get
                //   messed up (code bug).
                //@TODO: Modify this when chipletId becomes part of iv_scanAddress
                //       as part of RS4 shrinkage (RTC158101).
                FAPI_ASSERT( l_vpdChipletId == l_chipletId,
                             fapi2::XIPC_MVPD_CHIPLET_ID_MESS().
                             set_CHIP_TARGET(i_proc_target).
                             set_CHIPLET_ID(l_chipletId).
                             set_MVPD_CHIPLET_ID(l_vpdChipletId).
                             set_RING_ID(i_ring.ringId),
                             "_fetch_and_insert_vpd_rings: Code bug: VPD ring's chipletId"
                             " in scan container (=0x%X) doesn't match the requested"
                             " chipletId (=0x%X)",
                             l_vpdChipletId, l_chipletId );

                // Even though success, checking for accidental buffer overflow (code bug).
                FAPI_ASSERT( l_vpdRingSize <= i_vpdRingSize,
                             fapi2::XIPC_MVPD_RING_SIZE_MESS().
                             set_CHIP_TARGET(i_proc_target).
                             set_RING_ID(i_ring.ringId).
                             set_CHIPLET_ID(l_chipletId).
                             set_RING_BUFFER_SIZE(i_vpdRingSize).
                             set_MVPD_RING_SIZE(l_vpdRingSize),
                             "_fetch_and_insert_vpd_rings: Code bug: VPD ring size (=0x%X) exceeds"
                             " allowed ring buffer size (=0x%X)",
                             l_vpdRingSize, i_vpdRingSize );

                //@TODO: Remove following line asap. Temporary fix until Sgro starts using
                //       latest p9_scan_compression.H.
                //       Also fix p9_mvpd_ring_funcs.C to look for entire RS4_MAGIC string.
                //       Actually, do all the above in connection with RS4 header
                //       shrinkage (RTC158101 and RTC159801).
                ((CompressedScanData*)i_vpdRing)->iv_magic = htobe32(RS4_MAGIC);

                // Check if ring is a flush ring, i.e. if it is redundant, meaning that it will
                //   result in no change.
                int redundant = 0;
                l_rc = rs4_redundant((CompressedScanData*)i_vpdRing, &redundant);
                FAPI_ASSERT( l_rc == 0,
                             fapi2::XIPC_RS4_REDUNDANT_ERROR().
                             set_CHIP_TARGET(i_proc_target).
                             set_RING_ID(i_ring.ringId).
                             set_CHIPLET_ID(l_chipletId),
                             "rs4_redundant: Failed w/rc=%i for "
                             "ringId=0x%02X, chipletId=0x%02X ",
                             l_rc, i_ring.ringId, l_chipletId );

                if (redundant)
                {
                    FAPI_DBG("Skipping redundant VPD ring: ringId=0x%02X, chipletId=0x%02X ", i_ring.ringId, l_chipletId);
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    // Note that we do not want to exit here. There could be content in the next
                    //  instance. We're just not appending the current redundant one.
                }
                else
                {

                    //@TODO: Temporary fix to convert VPD RS4 container format to
                    //       to RingLayout format. Remove/replace in connection
                    //       with RS4 header shrinkage (RTC158101)
                    uint32_t i;

                    for (i = 0; i < l_vpdRingSize; i++)
                    {
                        *(((uint8_t*)i_vpdRing) + l_vpdRingSize - 1 + sizeof(P9_TOR::RingLayout_t) - i) =
                            *(((uint8_t*)i_vpdRing) + l_vpdRingSize - 1 - i);
                    }

                    uint32_t l_sizeOfThisRing = l_vpdRingSize + sizeof(P9_TOR::RingLayout_t);
                    ((P9_TOR::RingLayout_t*)i_vpdRing)->sizeOfThis = htobe32(l_sizeOfThisRing);
                    ((P9_TOR::RingLayout_t*)i_vpdRing)->sizeOfCmsk = 0;
                    ((P9_TOR::RingLayout_t*)i_vpdRing)->sizeOfMeta = 0;

                    // Checking for potential image overflow BEFORE appending the ring.
                    if ( (io_ringSectionSize + l_sizeOfThisRing) > i_maxRingSectionSize )
                    {
                        //@TODO: We can't update bootCoreMask until RTC158106. So for now
                        //       we're simply returning the requested bootCoreMask. Thus,
                        //       should there be an overflow condition before RTC158106
                        //       gets implemented (i.e., inserting VPD rings in EC order),
                        //       we would manually have to scale back on the requested
                        //       cores in the initialled supplied io_bootCoreMask arg to
                        //       xip_customize.
                        FAPI_ASSERT( false,
                                     fapi2::XIPC_IMAGE_WOULD_OVERFLOW().
                                     set_CHIP_TARGET(i_proc_target).
                                     set_CURRENT_RING_SECTION_SIZE(io_ringSectionSize).
                                     set_SIZE_OF_THIS_RING(l_sizeOfThisRing).
                                     set_MAX_RING_SECTION_SIZE(i_maxRingSectionSize).
                                     set_RING_ID(i_ring.ringId).
                                     set_CHIPLET_ID(l_chipletId).
                                     set_CURRENT_BOOT_CORE_MASK(io_bootCoreMask),
                                     "Ran out of image buffer space trying to append a ring"
                                     " to the .rings section" );
                    }

                    //------------------------------------------
                    // Now, append the ring to the ring section
                    //------------------------------------------

                    // Calculate the chiplet TOR index
                    uint8_t l_chipletTorId = l_chipletId +
                                             (l_chipletId - i_ring.instanceIdMin ) * (l_ringsPerChipletId - 1) +
                                             l_evenOdd;

                    switch (i_sysPhase)
                    {

                        case SYSPHASE_HB_SBE:
                            l_rc = tor_append_ring(
                                       i_ringSection,
                                       io_ringSectionSize, // In: Exact size. Out: Updated size.
                                       i_ringBuf2,
                                       i_ringBufSize2,  // Max size.
                                       (RingID)i_ring.ringId,
                                       P9_TOR::SBE,     // We're working on the SBE image
                                       P9_TOR::ALLRING, // No-care
                                       BASE,            // All VPD rings are Base ringVariant
                                       l_chipletTorId,  // Chiplet instance TOR Index
                                       i_vpdRing );     // The VPD RS4 ring container

                            if (l_rc == TOR_APPEND_RING_DONE)
                            {
                                FAPI_INF("Successfully added VPD ring: (ringId,evenOdd,chipletId)=(0x%02X,0x%X,0x%02X)",
                                         i_ring.ringId, l_evenOdd, l_chipletId);
                            }
                            else
                            {
                                FAPI_ASSERT( false,
                                             fapi2::XIPC_TOR_APPEND_RING_FAILED().
                                             set_CHIP_TARGET(i_proc_target).
                                             set_TOR_RC(l_rc),
                                             "tor_append_ring() failed w/l_rc=%d",
                                             l_rc );
                            }

                            break;

                        case SYSPHASE_RT_CME:
                            l_rc = tor_append_ring(
                                       i_ringSection,
                                       io_ringSectionSize, // In: Exact size. Out: Updated size.
                                       i_ringBuf2,
                                       i_ringBufSize2,  // Max size.
                                       (RingID)i_ring.ringId,
                                       P9_TOR::CME,     // We're working on the SBE image
                                       P9_TOR::ALLRING, // No-care
                                       BASE,            // All VPD rings are Base ringVariant
                                       l_chipletTorId,  // Chiplet instance ID
                                       i_vpdRing );     // The VPD RS4 ring container

                            if (l_rc == TOR_APPEND_RING_DONE)
                            {
                                FAPI_INF("Successfully added VPD ring: (ringId,evenOdd,chipletId)=(0x%02X,0x%X,0x%02X)",
                                         i_ring.ringId, l_evenOdd, l_chipletId);
                            }
                            else
                            {
                                FAPI_ASSERT( false,
                                             fapi2::XIPC_TOR_APPEND_RING_FAILED().
                                             set_CHIP_TARGET(i_proc_target).
                                             set_TOR_RC(l_rc),
                                             "tor_append_ring() failed w/l_rc=%d",
                                             l_rc );
                            }

                            FAPI_DBG("(After tor_append) io_ringSectionSize = %d", io_ringSectionSize);

                            break;

                        case SYSPHASE_RT_SGPE:
                            l_rc = tor_append_ring(
                                       i_ringSection,
                                       io_ringSectionSize, // In: Exact size. Out: Updated size.
                                       i_ringBuf2,
                                       i_ringBufSize2,  // Max size.
                                       (RingID)i_ring.ringId,
                                       P9_TOR::SGPE,    // We're working on the SGPE image
                                       P9_TOR::ALLRING, // No-care
                                       BASE,            // All VPD rings are Base ringVariant
                                       l_chipletTorId,  // Chiplet instance ID
                                       i_vpdRing );     // The VPD RS4 ring container

                            if (l_rc == TOR_APPEND_RING_DONE)
                            {
                                FAPI_INF("Successfully added VPD ring: (ringId,evenOdd,chipletId)=(0x%02X,0x%X,0x%02X)",
                                         i_ring.ringId, l_evenOdd, l_chipletId);
                            }
                            else
                            {
                                FAPI_ASSERT( false,
                                             fapi2::XIPC_TOR_APPEND_RING_FAILED().
                                             set_CHIP_TARGET(i_proc_target).
                                             set_TOR_RC(l_rc),
                                             "tor_append_ring() failed w/l_rc=%d",
                                             l_rc );
                            }

                            FAPI_DBG("(After tor_append) io_ringSectionSize = %d", io_ringSectionSize);

                            break;

                        default:
                            FAPI_ASSERT( false,
                                         fapi2::XIPC_INVALID_SYSPHASE_PARM().
                                         set_CHIP_TARGET(i_proc_target).
                                         set_SYSPHASE(i_sysPhase).
                                         set_OCCURRENCE(2),
                                         "Code bug: Unsupported value of sysPhase (=%d)",
                                         i_sysPhase );
                            break;
                    } // End switch(sysPhase)

                } // End if(redundant)

            }
            else if (l_fapiRc.isRC(RC_MVPD_RING_NOT_FOUND))
            {

                // No match, do nothing. Next chipletId.
                //@TODO: Uncomment the following after PowerOn. Also, need to come
                //       to agreement whether this should be fatal error or not.
                //       For now, for PO, it's considered benigh and noise and is
                //       being commented out.
                //FAPI_INF("_fetch_and_insert_vpd_rings():"
                //         "(ringId,chipletId)=(0x%X,0x%X) not found.",
                //         i_ring.ringId, l_chipletId);

                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

            }
            else
            {
                //--------------------------
                // Handle other error cases
                //--------------------------

                // getMvpdRing failed due to insufficient ring buffer space.
                // Assumption here is that getMvpdRing returns required buffer size
                //   in l_vpdRingSize (and which it does!).
                FAPI_ASSERT( !l_fapiRc.isRC(RC_MVPD_RING_BUFFER_TOO_SMALL),
                             fapi2::XIPC_MVPD_RING_SIZE_TOO_BIG().
                             set_CHIP_TARGET(i_proc_target).
                             set_RING_ID(i_ring.ringId).
                             set_CHIPLET_ID(l_chipletId).
                             set_RING_BUFFER_SIZE(i_vpdRingSize).
                             set_MVPD_RING_SIZE(l_vpdRingSize),
                             "_fetch_and_insert_vpd_rings(): VPD ring size (=0x%X) exceeds"
                             " allowed ring buffer size (=0x%X)",
                             l_vpdRingSize, i_vpdRingSize );

                // getMvpdRing failed due to invalid record data magic word.
                FAPI_ASSERT( !l_fapiRc.isRC(RC_MVPD_INVALID_RS4_HEADER),
                             fapi2::XIPC_MVPD_INVALID_RECORD_DATA().
                             set_CHIP_TARGET(i_proc_target).
                             set_RING_ID(i_ring.ringId).
                             set_CHIPLET_ID(l_chipletId),
                             "_fetch_and_insert_vpd_rings(): MVPD has invalid record data" );

                // getMvpdRing failed for some other reason aside from above handled cases.
                if (l_fapiRc != fapi2::FAPI2_RC_SUCCESS)
                {
                    FAPI_ERR("_fetch_and_insert_vpd_rings(): getMvpdRing failed "
                             " w/rc=0x%08X", (uint64_t)l_fapiRc);
                    fapi2::current_err = l_fapiRc;
                    goto fapi_try_exit;
                }

            } // End if(bSkipRing)

        } // Loop on evenOdd

    } //Loop on chipletId


fapi_try_exit:
    FAPI_DBG("Exiting _fetch_and_insert_vpd_rings");
    return fapi2::current_err;

}



//  Function: fetch_and_insert_vpd_rings()
//
//  Parameter list:
//  const fapi::Target &i_target:    Processor chip target.
//  void*      i_ringSection:        Ptr to ring section.
//  uint32_t&  io_ringSectionSize:   Running size
//  uint32_t   i_maxRingSectionSize: Max size
//  uint8_t    i_sysPhase:           ={IPL, RT_CME, RT_SGPE}
//  void*      i_vpdRing:            VPD ring buffer.
//  uint32_t   i_vpdRingSize:        Size of VPD ring buffer.
//  void*      i_ringBuf2:           Ring work buffer.
//  uint32_t   i_ringBufSize2:       Size of ring work buffer.
//  uint32_t&  io_bootCoreMask:      Desired (in) and actual (out) boot cores.
//
fapi2::ReturnCode fetch_and_insert_vpd_rings(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void*           i_ringSection,
    uint32_t&       io_ringSectionSize,     // Running size
    uint32_t        i_maxRingSectionSize,   // Max size
    uint8_t         i_sysPhase,
    void*           i_vpdRing,
    uint32_t        i_vpdRingSize,
    void*           i_ringBuf2,
    uint32_t        i_ringBufSize2,
    uint32_t&       io_bootCoreMask )
{

    FAPI_DBG("Entering fetch_and_insert_vpd_rings");

    // Walk through all Vpd rings and add any that's there to the image.
    // Do this in two steps:
    // 1- Add all NEST rings
    // 2- Add QUAD rings in EC order

    // 1- Add all common rings
    for (auto vpdType = 0; vpdType < NUM_OF_VPD_TYPES; vpdType++)
    {

        const RingIdList* l_ring_id_list = ALL_VPD_RINGS[vpdType].ringIdList;
        auto l_ring_id_list_size   = ALL_VPD_RINGS[vpdType].ringIdListSize;

        for (size_t iRing = 0; iRing < l_ring_id_list_size; iRing++)
        {

            if (l_ring_id_list[iRing].vpdRingClass != VPD_RING_CLASS_EQ_INS &&
                l_ring_id_list[iRing].vpdRingClass != VPD_RING_CLASS_EX_INS &&
                l_ring_id_list[iRing].vpdRingClass != VPD_RING_CLASS_EC_INS)
            {

                FAPI_TRY( _fetch_and_insert_vpd_rings( i_proc_target,
                                                       i_ringSection,
                                                       io_ringSectionSize,
                                                       i_maxRingSectionSize,
                                                       i_sysPhase,
                                                       i_vpdRing,
                                                       i_vpdRingSize,
                                                       i_ringBuf2,
                                                       i_ringBufSize2,
                                                       l_ring_id_list[iRing],
                                                       io_bootCoreMask ),
                          "fetch_and_insert_vpd_rings(): Failed to execute "
                          "_fetch_and_insert_vpd_rings() w/rc:0x%.8x",
                          (uint64_t)fapi2::current_err );

                FAPI_DBG("(CMN) io_ringSectionSize = %d", io_ringSectionSize);

            }

        } //Loop on ringId

    } //Loop on VPD types

    // 2- Add all instance [QUAD-level] rings in EC order - TBD
    //@TODO: For now, just add everything though honoring bootCoreMask with
    //       which we can control any potential overfilling of the image
    //       by manually ditching cores in bootCoreMask until it fits. For
    //       the actual VPD ring insertion order effort in RTC158106, we need
    //       a dual fetch_and_insert_{common,instance}_vpd_rings where the
    //       common part pretty much is already completed in the above step
    //       #1. The step #2 instance part needs updating to ditch looping
    //       over vpdType and instead loop over chipletId to fill up one
    //       core chipletId "column" at a time (RTC158106).
    for (auto vpdType = 0; vpdType < NUM_OF_VPD_TYPES; vpdType++)
    {

        const RingIdList* l_ring_id_list = ALL_VPD_RINGS[vpdType].ringIdList;
        auto l_ring_id_list_size   = ALL_VPD_RINGS[vpdType].ringIdListSize;

        for (size_t iRing = 0; iRing < l_ring_id_list_size; iRing++)
        {

            if (l_ring_id_list[iRing].vpdRingClass == VPD_RING_CLASS_EQ_INS ||
                l_ring_id_list[iRing].vpdRingClass == VPD_RING_CLASS_EX_INS ||
                l_ring_id_list[iRing].vpdRingClass == VPD_RING_CLASS_EC_INS)
            {

                FAPI_TRY( _fetch_and_insert_vpd_rings( i_proc_target,
                                                       i_ringSection,
                                                       io_ringSectionSize,
                                                       i_maxRingSectionSize,
                                                       i_sysPhase,
                                                       i_vpdRing,
                                                       i_vpdRingSize,
                                                       i_ringBuf2,
                                                       i_ringBufSize2,
                                                       l_ring_id_list[iRing],
                                                       io_bootCoreMask ),
                          "fetch_and_insert_vpd_rings(): Failed to execute "
                          "_fetch_and_insert_vpd_rings() w/rc:0x%.8x",
                          (uint64_t)fapi2::current_err );

                FAPI_DBG("(INS) io_ringSectionSize = %d", io_ringSectionSize);

            } // if (Quad instance ring)

        } // Loop on ringId

    } //Loop on VPD types

fapi_try_exit:
    FAPI_DBG("Exiting fetch_and_insert_vpd_rings");
    return fapi2::current_err;

}



fapi2::ReturnCode p9_xip_customize (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void*     io_image,
    uint32_t& io_imageSize,             // In: Max, Out: Actual
    void*     io_ringSectionBuf,
    uint32_t& io_ringSectionBufSize,    // In: Max, Out: Actual
    uint8_t   i_sysPhase,
    uint8_t   i_modeBuild,
    void*     io_ringBuf1,
    uint32_t  i_ringBufSize1,
    void*     io_ringBuf2,
    uint32_t  i_ringBufSize2,
    uint32_t& io_bootCoreMask )         // Bits(8:31) = EC00:EC23
{
    fapi2::ReturnCode   l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode   l_fapiRc2 = fapi2::FAPI2_RC_SUCCESS;
    int                 l_rc = 0; // Non-fapi RC

    P9XipSection    l_xipRingsSection;
    uint32_t        l_initialImageSize;
    uint32_t        l_imageSizeWithoutRings;
    uint32_t        l_maxImageSize, l_imageSize;
    uint32_t        l_maxRingSectionSize;
    uint32_t        l_sectionOffset = 1;
    uint16_t        l_ddLevel;
    uint32_t        l_requestedBootCoreMask = (i_sysPhase == SYSPHASE_HB_SBE) ? io_bootCoreMask : 0x00FFFFFF;
    void*           l_hwRingsSection;


    FAPI_DBG ("Entering p9_xip_customize w/sysPhase=%d...", i_sysPhase);

    io_bootCoreMask = l_requestedBootCoreMask;

    //-------------------------------------------
    // Check some input buffer parameters:
    // - sysPhase, modeBuild are checked later
    // - log the initial image size
    // - more buffer size checks in big switch()
    //-------------------------------------------

    FAPI_ASSERT( io_image != NULL &&
                 io_ringSectionBuf != NULL &&
                 io_ringBuf1 != NULL &&
                 io_ringBuf2 != NULL,
                 fapi2::XIPC_INVALID_INPUT_BUFFER_PARM().
                 set_CHIP_TARGET(i_proc_target).
                 set_IMAGE_BUF(io_image).
                 set_RING_SECTION_BUF(io_ringSectionBuf).
                 set_RING_BUF1(io_ringBuf1).
                 set_RING_BUF2(io_ringBuf2),
                 "One or more invalid input buffer pointers:\n"
                 "  io_image=0x%016llx\n"
                 "  io_ringSectionBuf=0x%016llx\n"
                 "  io_ringBuf1=0x%016llx\n"
                 "  io_ringBuf2=0x%016llx\n",
                 (uintptr_t)io_image,
                 (uintptr_t)io_ringSectionBuf,
                 (uintptr_t)io_ringBuf1,
                 (uintptr_t)io_ringBuf2 );

    l_rc = p9_xip_image_size(io_image, &l_initialImageSize);

    FAPI_ASSERT( l_rc == 0,
                 fapi2::XIPC_XIP_API_MISC_ERROR().
                 set_CHIP_TARGET(i_proc_target).
                 set_XIP_RC(l_rc).
                 set_OCCURRENCE(1),
                 "p9_xip_image_size() failed (1) w/rc=0x%08X",
                 (uint32_t)l_rc );

    FAPI_ASSERT( io_imageSize >= l_initialImageSize &&
                 io_ringSectionBufSize == MAX_SEEPROM_IMAGE_SIZE &&
                 i_ringBufSize1 == MAX_RING_BUF_SIZE &&
                 i_ringBufSize2 == MAX_RING_BUF_SIZE,
                 fapi2::XIPC_INVALID_INPUT_BUFFER_SIZE_PARM().
                 set_CHIP_TARGET(i_proc_target).
                 set_INPUT_IMAGE_SIZE(l_initialImageSize).
                 set_IMAGE_BUF_SIZE(io_imageSize).
                 set_RING_SECTION_BUF_SIZE(io_ringSectionBufSize).
                 set_RING_BUF_SIZE1(i_ringBufSize1).
                 set_RING_BUF_SIZE2(i_ringBufSize2).
                 set_OCCURRENCE(1),
                 "One or more invalid input buffer sizes:\n"
                 "  l_initialImageSize=0x%016llx\n"
                 "  io_imageSize=0x%016llx\n"
                 "  io_ringSectionBufSize=0x%016llx\n"
                 "  i_ringBufSize1=0x%016llx\n"
                 "  i_ringBufSize2=0x%016llx\n",
                 (uintptr_t)l_initialImageSize,
                 (uintptr_t)io_imageSize,
                 (uintptr_t)io_ringSectionBufSize,
                 (uintptr_t)i_ringBufSize1,
                 (uintptr_t)i_ringBufSize2 );


    FAPI_DBG("Input image size: %d", l_initialImageSize);


    ///////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Write mailbox attributes
    // System phase:       HB_SBE
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        FAPI_TRY(writeMboxRegs(i_proc_target, io_image),
                 "p9_xip_customize: error writing mbox regs in SBE image rc=0x%.8x",
                 (uint64_t)fapi2::current_err);
        FAPI_TRY(writePG(i_proc_target, io_image),
                 "p9_xip_customize: error writing PG data in SBE image rc=0x%.8x",
                 (uint64_t)fapi2::current_err);
    }


    //////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Append VPD rings to ring section
    // System phase:       All phases
    //------------------------------------------------------------------------
    // Notes:
    // Do some sysPhase specific initial operations:
    // - Set max image size
    // - Copy image's sysPhase specific [sub-]section into separate ring
    //   section buffer
    // - Delete (IPL sysPhase only) .rings, since we need to append later
    //////////////////////////////////////////////////////////////////////////

    switch (i_sysPhase)
    {

        case SYSPHASE_HB_SBE:

            FAPI_DBG("Image size before any updates: %d", l_initialImageSize);

            FAPI_ASSERT( io_imageSize >= MAX_SEEPROM_IMAGE_SIZE &&
                         io_ringSectionBufSize == MAX_SEEPROM_IMAGE_SIZE,
                         fapi2::XIPC_INVALID_INPUT_BUFFER_SIZE_PARM().
                         set_CHIP_TARGET(i_proc_target).
                         set_INPUT_IMAGE_SIZE(l_initialImageSize).
                         set_IMAGE_BUF_SIZE(io_imageSize).
                         set_RING_SECTION_BUF_SIZE(io_ringSectionBufSize).
                         set_RING_BUF_SIZE1(i_ringBufSize1).
                         set_RING_BUF_SIZE2(i_ringBufSize2).
                         set_OCCURRENCE(2),
                         "One or more invalid input buffer sizes for SBE:\n"
                         "  MAX_SEEPROM_IMAGE_SIZE=0x%016llx\n"
                         "  io_imageSize=0x%016llx\n"
                         "  io_ringSectionBufSize=0x%016llx\n",
                         (uintptr_t)MAX_SEEPROM_IMAGE_SIZE,
                         (uintptr_t)io_imageSize,
                         (uintptr_t)io_ringSectionBufSize );

            l_maxImageSize = MAX_SEEPROM_IMAGE_SIZE;

            // Copy, save and delete the .rings section, wherever it is (even if
            //   not the last section), and re-arrange other sections located above
            //   the .rings section.
            // Keep a copy of the original input image, io_image, in io_ringSectionBuf.
            l_rc = p9_xip_delete_section(io_image, io_ringSectionBuf, l_initialImageSize, P9_XIP_SECTION_SBE_RINGS);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_proc_target).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(2),
                         "p9_xip_delete_section() failed removing .rings w/rc=0x%08X",
                         (uint32_t)l_rc );

            // Make a note of the image size without .rings
            l_rc = p9_xip_image_size(io_image, &l_imageSizeWithoutRings);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_proc_target).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(3),
                         "p9_xip_image_size() failed (3) w/rc=0x%08X",
                         (uint32_t)l_rc );

            FAPI_DBG("Size of image before VPD update (excl .rings): %d", l_imageSizeWithoutRings);

            // Get the size of our .rings section.
            l_rc = p9_xip_get_section(io_ringSectionBuf, P9_XIP_SECTION_SBE_RINGS, &l_xipRingsSection);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_proc_target).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(4),
                         "p9_xip_get_section() failed (4) getting .rings section w/rc=0x%08X",
                         (uint32_t)l_rc );

            io_ringSectionBufSize = l_xipRingsSection.iv_size;

            FAPI_ASSERT( io_ringSectionBufSize > 0,
                         fapi2::XIPC_EMPTY_RING_SECTION().
                         set_CHIP_TARGET(i_proc_target),
                         "Ring section size in SBE image is zero. No TOR. Can't append rings.");

            FAPI_DBG("Size of .rings section before VPD update: %d", io_ringSectionBufSize);

            l_maxRingSectionSize = l_maxImageSize - l_imageSizeWithoutRings;

            FAPI_DBG("Max allowable size of .rings section: %d", l_maxRingSectionSize);

            // Move .rings to the top of ringSectionBuf (which currently holds a copy of the
            //   io_image but which can now be destroyed.)
            memcpy( io_ringSectionBuf,
                    (void*)(((uint8_t*)io_ringSectionBuf) + l_xipRingsSection.iv_offset),
                    io_ringSectionBufSize );

            //----------------------------------------
            // Append VPD Rings to the .rings section
            //----------------------------------------

            l_fapiRc = fetch_and_insert_vpd_rings( i_proc_target,
                                                   io_ringSectionBuf,
                                                   io_ringSectionBufSize, // Running section size
                                                   l_maxRingSectionSize,  // Max section size
                                                   i_sysPhase,
                                                   io_ringBuf1,
                                                   i_ringBufSize1,
                                                   io_ringBuf2,
                                                   i_ringBufSize2,
                                                   io_bootCoreMask );

            FAPI_DBG("bootCoreMask:  Requested=0x%08X  Final=0x%08X",
                     l_requestedBootCoreMask, io_bootCoreMask);

            if (l_fapiRc)
            {

                if (l_fapiRc.isRC(RC_XIPC_IMAGE_WOULD_OVERFLOW))
                {
                    FAPI_INF("p9_xip_customize(): Image is full. Ran out of space appending VPD rings"
                             " to the .rings section");

                    // Check the bootCoreMask to determine if enough cores have been configured.
                    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
                    uint8_t MIN_REQD_ECS = 0;
                    uint8_t  l_actualEcCount = 0;

                    FAPI_DBG("MIN_REQD_ECS = 0x%x", MIN_REQD_ECS);

                    l_fapiRc2 = FAPI_ATTR_GET(fapi2::ATTR_SBE_IMAGE_MINIMUM_VALID_ECS, FAPI_SYSTEM, MIN_REQD_ECS);

                    FAPI_DBG("MIN_REQD_ECS = 0x%x", MIN_REQD_ECS);

                    FAPI_ASSERT( l_fapiRc2.isRC(fapi2::FAPI2_RC_SUCCESS),
                                 fapi2::XIPC_IMAGE_WOULD_OVERFLOW_ADDL_INFO().
                                 set_CHIP_TARGET(i_proc_target).
                                 set_REQUESTED_BOOT_CORE_MASK(l_requestedBootCoreMask).
                                 set_CURRENT_BOOT_CORE_MASK(io_bootCoreMask),
                                 "Unable to determine ATTR_SBE_IMAGE_MINIMUM_VALID_ECS, so don't"
                                 " know if the minimum core set was met");

                    // Count number of ECs set in bootCoreMask
                    l_actualEcCount = 0;

                    for (uint8_t iCore = 0; iCore < NUM_OF_CORES; iCore++)
                    {
                        if (io_bootCoreMask & ((0x00000001 << (NUM_OF_CORES - 1)) >> iCore))
                        {
                            l_actualEcCount++;
                        }
                    }

                    FAPI_ASSERT( l_actualEcCount >= MIN_REQD_ECS,
                                 fapi2::XIPC_IMAGE_WOULD_OVERFLOW_BEFORE_REACHING_MIN_ECS().
                                 set_CHIP_TARGET(i_proc_target).
                                 set_REQUESTED_BOOT_CORE_MASK(l_requestedBootCoreMask).
                                 set_CURRENT_BOOT_CORE_MASK(io_bootCoreMask).
                                 set_MIN_REQD_ECS(MIN_REQD_ECS).
                                 set_ACTUAL_EC_COUNT(l_actualEcCount),
                                 "Image buffer would overflow before reaching the minimum required"
                                 " number of EC boot cores" );

                    FAPI_INF( "Image is full and with sufficient boot cores:\n"
                              "  Final bootCoreMask: 0x%08X\n"
                              "  Number of boot cores: %d\n"
                              "  Min req'd boot cores: %d",
                              io_bootCoreMask, l_actualEcCount, MIN_REQD_ECS );

                    l_fapiRc = fapi2::FAPI2_RC_SUCCESS;

                }

                fapi2::current_err = l_fapiRc;
                goto fapi_try_exit;

            }

            // More size code sanity checks of section and image sizes.
            FAPI_ASSERT( io_ringSectionBufSize <= l_maxRingSectionSize,
                         fapi2::XIPC_SECTION_SIZING().
                         set_CHIP_TARGET(i_proc_target).
                         set_RING_SECTION_SIZE(io_ringSectionBufSize).
                         set_MAX_RING_SECTION_SIZE(l_maxRingSectionSize),
                         "Code bug: ringSectionBufSize>maxRingSectionSize" );

            FAPI_ASSERT( (l_imageSizeWithoutRings + io_ringSectionBufSize) <= l_maxImageSize,
                         fapi2::XIPC_IMAGE_SIZING().
                         set_CHIP_TARGET(i_proc_target).
                         set_IMAGE_SIZE_WITHOUT_RINGS(l_imageSizeWithoutRings).
                         set_RING_SECTION_SIZE(io_ringSectionBufSize).
                         set_MAX_IMAGE_SIZE(l_maxImageSize),
                         "Code bug: imageSize would exceed maxImageSize" );

            FAPI_DBG( "Image details: io_ringSectionBufSize=%d l_imageSizeWithoutRings=%d l_maxImageSize=%d",
                      io_ringSectionBufSize, l_imageSizeWithoutRings, l_maxImageSize );

            //--------------------------------------------------------
            // Append the updated .rings section to the Seeprom image
            //--------------------------------------------------------

            l_rc = p9_xip_append( io_image,
                                  P9_XIP_SECTION_SBE_RINGS,
                                  io_ringSectionBuf,
                                  (const uint32_t)io_ringSectionBufSize,
                                  (const uint32_t)l_maxImageSize,
                                  &l_sectionOffset );

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_proc_target).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(5),
                         "p9_xip_append() failed w/rc=0x%08x",
                         (uint32_t)l_rc );

            FAPI_DBG("sectionOffset=0x%08X", l_sectionOffset);

            l_rc = p9_xip_image_size(io_image, &l_imageSize);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_proc_target).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(6),
                         "p9_xip_image_size() failed (6) w/rc=0x%08X",
                         (uint32_t)l_rc );

            FAPI_DBG( "Seeprom image size after VPD updates: %d", l_imageSize );

            FAPI_ASSERT( l_imageSize <= l_maxImageSize,
                         fapi2::XIPC_IMAGE_TOO_LARGE().
                         set_CHIP_TARGET(i_proc_target).
                         set_IMAGE_SIZE(l_imageSize).
                         set_MAX_IMAGE_SIZE(l_maxImageSize).
                         set_OCCURRENCE(1),
                         "Seeprom image size after VPD updates (=%d) exceeds max image size (=%d)",
                         l_imageSize, l_maxImageSize );

            break;

        case SYSPHASE_RT_CME:
        case SYSPHASE_RT_SGPE:

            FAPI_ASSERT( io_imageSize == l_initialImageSize &&
                         io_ringSectionBufSize == MAX_SEEPROM_IMAGE_SIZE,
                         fapi2::XIPC_INVALID_INPUT_BUFFER_SIZE_PARM().
                         set_CHIP_TARGET(i_proc_target).
                         set_INPUT_IMAGE_SIZE(l_initialImageSize).
                         set_IMAGE_BUF_SIZE(io_imageSize).
                         set_RING_SECTION_BUF_SIZE(io_ringSectionBufSize).
                         set_RING_BUF_SIZE1(i_ringBufSize1).
                         set_RING_BUF_SIZE2(i_ringBufSize2).
                         set_OCCURRENCE(3),
                         "One or more invalid input buffer sizes for CME or SGPE:\n"
                         "  l_initialImageSize=0x%016llx\n"
                         "  io_imageSize=0x%016llx\n"
                         "  io_ringSectionBufSize=0x%016llx\n",
                         (uintptr_t)l_initialImageSize,
                         (uintptr_t)io_imageSize,
                         (uintptr_t)io_ringSectionBufSize );

            l_maxRingSectionSize = io_ringSectionBufSize;

            // Calculate pointer to HW image's .rings section
            l_rc = p9_xip_get_section(io_image, P9_XIP_SECTION_HW_RINGS, &l_xipRingsSection);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_proc_target).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(7),
                         "p9_xip_get_section() failed (7) getting .rings section w/rc=0x%08X",
                         (uint32_t)l_rc );

            FAPI_ASSERT( l_xipRingsSection.iv_size > 0,
                         fapi2::XIPC_EMPTY_RING_SECTION().
                         set_CHIP_TARGET(i_proc_target),
                         "CME or SGPE ring section size is zero (sysPhase=%d). No TOR. Can't append rings.",
                         i_sysPhase );

            l_hwRingsSection = (void*)((uintptr_t)io_image + l_xipRingsSection.iv_offset);

            // Extract the DD level
            //@FIXME: CMO: Use attribute service for this. For now, hardcode.
            l_ddLevel = 0x10;

            //------------------------------------------------------------
            // Get the CME or SGPE block of rings from .rings in HW image
            //------------------------------------------------------------
            if ( i_sysPhase == SYSPHASE_RT_CME )
            {
                FAPI_DBG("Getting the CME block of rings from HW image");

                l_rc = tor_get_block_of_rings( l_hwRingsSection,
                                               l_ddLevel,
                                               P9_TOR::CME,
                                               P9_TOR::ALLRING,
                                               BASE,
                                               0,
                                               &io_ringSectionBuf,
                                               io_ringSectionBufSize );
            }
            else
            {
                FAPI_DBG("Getting the SGPE block of rings from HW image");

                l_rc = tor_get_block_of_rings( l_hwRingsSection,
                                               l_ddLevel,
                                               P9_TOR::SGPE,
                                               P9_TOR::ALLRING,
                                               BASE,
                                               0,
                                               &io_ringSectionBuf,
                                               io_ringSectionBufSize );
            }

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_TOR_GET_BLOCK_OF_RINGS_FAILED().
                         set_CHIP_TARGET(i_proc_target).
                         set_TOR_RC(l_rc).
                         set_SYSPHASE(i_sysPhase),
                         "tor_get_block_of_rings() failed w/rc=0x%08X",
                         (uint32_t)l_rc );

            FAPI_DBG("Size of .rings section before VPD update: %d", io_ringSectionBufSize);

            //----------------------------------------
            // Append VPD Rings to the .rings section
            //----------------------------------------

            l_fapiRc = fetch_and_insert_vpd_rings( i_proc_target,
                                                   io_ringSectionBuf,
                                                   io_ringSectionBufSize, // Running section size
                                                   l_maxRingSectionSize,  // Max section size
                                                   i_sysPhase,
                                                   io_ringBuf1,
                                                   i_ringBufSize1,
                                                   io_ringBuf2,
                                                   i_ringBufSize2,
                                                   io_bootCoreMask );

            FAPI_DBG("Size of .rings section after VPD update: %d", io_ringSectionBufSize );

            FAPI_DBG("bootCoreMask: Requested=0x%08X Final=0x%08X",
                     l_requestedBootCoreMask, io_bootCoreMask);

            if (l_fapiRc)
            {

                FAPI_ASSERT( !l_fapiRc.isRC(RC_XIPC_IMAGE_WOULD_OVERFLOW),
                             fapi2::XIPC_IMAGE_WOULD_OVERFLOW_BEFORE_REACHING_MIN_ECS().
                             set_CHIP_TARGET(i_proc_target).
                             set_REQUESTED_BOOT_CORE_MASK(l_requestedBootCoreMask).
                             set_CURRENT_BOOT_CORE_MASK(io_bootCoreMask),
                             "Ran out of space appending VPD rings to the .rings section" );

                fapi2::current_err = l_fapiRc;
                goto fapi_try_exit;

            }

            // More size code sanity checks of section and image sizes.
            FAPI_ASSERT( io_ringSectionBufSize <= l_maxRingSectionSize,
                         fapi2::XIPC_SECTION_SIZING().
                         set_CHIP_TARGET(i_proc_target).
                         set_RING_SECTION_SIZE(io_ringSectionBufSize).
                         set_MAX_RING_SECTION_SIZE(l_maxRingSectionSize),
                         "Code bug: ringSectionBufSize>maxRingSectionSize" );

            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::XIPC_INVALID_SYSPHASE_PARM().
                         set_CHIP_TARGET(i_proc_target).
                         set_SYSPHASE(i_sysPhase).
                         set_OCCURRENCE(1),
                         "Caller bug: Caller supplied unsupported value of sysPhase (=%d)",
                         i_sysPhase );
            break;
    }



    ///////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:  Removal of .toc, .fixed_toc and .strings
    // System phase:    HB_SBE
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {

        // Remove .toc:
        // This will remove external visibility to image's attributes and other global variables.
        l_rc = p9_xip_delete_section(io_image, io_ringSectionBuf, l_imageSize, P9_XIP_SECTION_TOC);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_SECTION_REMOVAL_ERROR().
                     set_CHIP_TARGET(i_proc_target).
                     set_XIP_SECTION(P9_XIP_SECTION_TOC),
                     "p9_xip_delete_section() failed to remove .toc section w/rc=0x%08X",
                     (uint32_t)l_rc );

        // Remove .fixedtoc:
        l_rc = p9_xip_delete_section(io_image, io_ringSectionBuf, l_imageSize, P9_XIP_SECTION_FIXED_TOC);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_SECTION_REMOVAL_ERROR().
                     set_CHIP_TARGET(i_proc_target).
                     set_XIP_SECTION(P9_XIP_SECTION_FIXED_TOC),
                     "p9_xip_delete_section() failed to remove .fixedtoc section w/rc=0x%08X",
                     (uint32_t)l_rc );

        // Remove .strings:
        // The .strings section must be removed after .toc and .fixed_toc.  Otherwise
        //   we get an P9_XIP_TOC_ERROR, probably because either of those two sections
        //   will "complain" on the next XIP API access that info they need in .strings
        //   is missing, i.e. as part of p9_xip_validate_image().
        l_rc = p9_xip_delete_section(io_image, io_ringSectionBuf, l_imageSize, P9_XIP_SECTION_STRINGS);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_SECTION_REMOVAL_ERROR().
                     set_CHIP_TARGET(i_proc_target).
                     set_XIP_SECTION(P9_XIP_SECTION_STRINGS),
                     "p9_xip_delete_section() failed to remove .fixedtoc section w/rc=0x%08X",
                     (uint32_t)l_rc );

        // Check the image size.
        l_rc = p9_xip_image_size(io_image, &l_imageSize);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_XIP_API_MISC_ERROR().
                     set_CHIP_TARGET(i_proc_target).
                     set_XIP_RC(l_rc).
                     set_OCCURRENCE(8),
                     "p9_xip_image_size() failed (7) w/rc=0x%08X",
                     (uint32_t)l_rc );

        FAPI_DBG("Image size after section removals: %d", l_imageSize);

        FAPI_ASSERT( l_imageSize <= l_maxImageSize,
                     fapi2::XIPC_IMAGE_TOO_LARGE().
                     set_CHIP_TARGET(i_proc_target).
                     set_IMAGE_SIZE(l_imageSize).
                     set_MAX_IMAGE_SIZE(l_maxImageSize).
                     set_OCCURRENCE(2),
                     "Final Seeprom image size (=%d) exceeds max image size (=%d)",
                     l_imageSize, l_maxImageSize );

    }



    ///////////////////////////////////////////////////////////////////////////
    // Other customizations
    ///////////////////////////////////////////////////////////////////////////

    // TBD



    ///////////////////////////////////////////////////////////////////////////
    // Done
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        io_imageSize = l_imageSize;
        FAPI_DBG("Final customized Seeprom image size: %d", io_imageSize);
    }

    FAPI_DBG("Final customized .rings section size: %d", io_ringSectionBufSize);


fapi_try_exit:
    FAPI_DBG("Exiting p9_xip_customize");
    return fapi2::current_err;

}


