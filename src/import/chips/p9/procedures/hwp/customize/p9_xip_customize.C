/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/customize/p9_xip_customize.C $ */
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
    #include "win32_stdint.h"
    #include "endian.h"
    #include "win_sim_fapi.h"
#else
    #include <p9_get_mvpd_ring.H>
#endif

#include <p9_xip_customize.H>
#include <p9_xip_image.h>
#include <p9_ring_identification.H>
#include <p9_tor.H>
#include <p9_scan_compression.H>
#include <p9_infrastruct_help.H>
#include <p9_ringId.H>

enum MvpdRingStatus
{
    RING_NOT_FOUND,
    RING_FOUND,
    RING_REDUNDANT,
    RING_SCAN
};

enum ChipletIdentifier
{
    EQ_CHIPLET,
    EX_CHIPLET,
    EC_CHIPLET,
};

enum ChipPosIdentifier
{
    EX_EVEN_POS               = 0x00400000,
    ODD_CORES_IN_EX           = 0x00300000,
    HIGH_ORDER_ODD_CORE_IN_EX = 0x00100000,
    LOW_ORDER_ODD_CORE_IN_EX  = 0x00200000,
    EC_POSITION               = 0x00800000
};

typedef struct
{
    //Read as:0000 0000 000X 000X 000X 000X 000X 000X (binary;X=[0,1]) EQ:[0:05]
    uint32_t EQ;

    //Read as:0000 0000 0X0X 0X0X 0X0X 0X0X 0X0X 0X0X (binary;X=[0,1]) EX:[0:11]
    uint32_t EX[4];

    //Read as:0000 0000 XXXX XXXX XXXX XXXX XXXX XXXX (binary;X=[0,1]) EC:[0:23]
    uint32_t EC;

    // Following members used to capture current state of instance vpd ring to
    // be appended when image run out-of-space.
    // Refers to chiplet as in EQ/EX/EC
    uint8_t  chipletUnderProcess;

    // Refer to 4 EX repr rings:[ex_l3_refr_time,ex_l3_repr,ex_l2_repr,ex_l3_refr_repr]
    uint8_t  exReprRingNum;

    // Refer to EQ:[0:5]; EX:[0:11]; EC:[0:23]
    uint8_t  chipletNumUnderProcess;
} VpdInsInsertProg_t;

using namespace fapi2;

#ifndef WIN32

#define MBOX_ATTR_WRITE(ID,TARGET,IMAGE) \
    { \
        fapi2::ID##_Type ID##_attrVal; \
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ID,TARGET,ID##_attrVal),\
                 "MBOX_ATTR_WRITE: Error getting %s", #ID); \
        FAPI_TRY(p9_xip_set_scalar(IMAGE,#ID,ID##_attrVal),\
                 "MBOX_ATTR_WRITE: Error writing attr %s to seeprom image",\
                 #ID); \
    }

#define MBOX_ATTR_SET(ID,TARGET,IMAGE) \
    { \
        fapi2::ID##_Type ID##_attrVal = 1; \
        FAPI_TRY(p9_xip_set_scalar(IMAGE,#ID,ID##_attrVal),\
                 "MBOX_ATTR_SET: Error writing attr %s to seeprom image",\
                 #ID); \
    }

#define MBOX_ATTR_CLEAR(ID,TARGET,IMAGE) \
    { \
        fapi2::ID##_Type ID##_attrVal = 0; \
        FAPI_TRY(p9_xip_set_scalar(IMAGE,#ID,ID##_attrVal),\
                 "MBOX_ATTR_CLEAR: Error writing attr %s to seeprom image",\
                 #ID); \
    }

fapi2::ReturnCode writeMboxRegs (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
    void* i_image)
{
    FAPI_DBG ("writeMboxRegs Entering...");
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    MBOX_ATTR_WRITE (ATTR_I2C_BUS_DIV_REF,          i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_EQ_GARD,                  i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_EC_GARD,                  i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_NEST_PLL_BUCKET,          FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_BOOT_FREQ_MULT,           i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_CLOCK_PLL_MUX,            i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_DPLL_BYPASS,              i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_SS_FILTER_BYPASS,         i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_CP_FILTER_BYPASS,         i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_IO_FILTER_BYPASS,         i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_NEST_MEM_X_O_PCI_BYPASS,  i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_SYSTEM_IPL_PHASE,         FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_SYS_FORCE_ALL_CORES,      FAPI_SYSTEM,    i_image);
    MBOX_ATTR_CLEAR (ATTR_RISK_LEVEL,               FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_DISABLE_HBBL_VECTORS,     FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_MC_SYNC_MODE,             i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_SECURITY_MODE,            FAPI_SYSTEM,    i_image);
    MBOX_ATTR_SET   (ATTR_PROC_SBE_MASTER_CHIP,     i_procTarget,   i_image);
    MBOX_ATTR_CLEAR (ATTR_PROC_FABRIC_GROUP_ID,     i_procTarget,   i_image);
    MBOX_ATTR_CLEAR (ATTR_PROC_FABRIC_CHIP_ID,      i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_DD1_SLOW_PCI_REF_CLOCK,   FAPI_SYSTEM,    i_image);
    MBOX_ATTR_CLEAR (ATTR_PROC_EFF_FABRIC_GROUP_ID, i_procTarget,   i_image);
    MBOX_ATTR_CLEAR (ATTR_PROC_EFF_FABRIC_CHIP_ID,  i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EPS_READ_CYCLES_T0,  FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EPS_READ_CYCLES_T1,  FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EPS_READ_CYCLES_T2,  FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EPS_WRITE_CYCLES_T1, FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EPS_WRITE_CYCLES_T2, FAPI_SYSTEM,    i_image);

fapi_try_exit:
    FAPI_DBG("writeMboxRegs Exiting...");
    return fapi2::current_err;
}

fapi2::ReturnCode writePG(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
    void* i_image)
{
    const uint8_t  IMG_PG_ENTRIES = 64;
    const uint16_t DEFAULT_PG_VAL = 0xffff;

    FAPI_DBG ("writePG Entering...");

    // Make all chiplets "not good".
    for (auto l_pg_idx = 0; l_pg_idx < IMG_PG_ENTRIES; l_pg_idx++)
    {
        FAPI_TRY( p9_xip_set_element(i_image, "ATTR_PG", l_pg_idx, DEFAULT_PG_VAL),
                  "Error (1) from p9_xip_set_element (idx %d)", l_pg_idx );
    }

    for (auto l_perv_tgt : i_procTarget.getChildren<fapi2::TARGET_TYPE_PERV>())
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
                     set_CHIP_TARGET(i_procTarget).
                     set_CHIP_UNIT_POS(l_unit_id).
                     set_PG_INDEX(l_pg_idx),
                     "Code bug: Invalid translation from PERV chip unit position to image PG index" );

        // Update the image
        FAPI_TRY( p9_xip_set_element(i_image, "ATTR_PG", l_pg_idx, l_pg_data),
                  "Error (2) from p9_xip_set_element (idx %d)", l_pg_idx );

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

#endif

//  Function: _fetch_and_insert_vpd_rings()
//  This function is used to fetch and insert a single ring(common/instance)
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
//  uint8_t    i_chipletId:          Chiplet Id
//  uint8_t    i_evenOdd:            Even/Odd for EX instances
//  const RingIdList i_ring:         The ring ID list (#G or #R list)
//  uint8_t&   io_ringStatusInMvpd:   EQ/EX/EC ring status - found/notfound/redundant in mvpd
//  bool       i_bImgOutOfSpace: flag to indicate image space overflow
//  uint32_t&  io_bootCoreMask:      Desired (in) and actual (out) boot cores.
//
#ifdef WIN32
ReturnCode _fetch_and_insert_vpd_rings(
    int& i_procTarget,
#else
fapi2::ReturnCode _fetch_and_insert_vpd_rings(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#endif
    void*           i_ringSection,
    uint32_t&       io_ringSectionSize,
    uint32_t        i_maxRingSectionSize,
    uint8_t         i_sysPhase,
    void*           i_vpdRing,
    uint32_t        i_vpdRingSize,
    void*           i_ringBuf2,
    uint32_t        i_ringBufSize2,
    uint8_t         i_chipletId,
    uint8_t         i_evenOdd,
    const RingIdList     i_ring,
    uint8_t&        io_ringStatusInMvpd,
    bool&           i_bImgOutOfSpace,
    uint32_t&       io_bootCoreMask )
{
    ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    int        l_rc = 0;

    FAPI_DBG("Entering _fetch_and_insert_vpd_ring");

    FAPI_INF("_fetch_and_insert_vpd_ring: (ringId,chipletId) = (0x%02X,0x%02x)",
             i_ring.ringId, i_chipletId);

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
                         set_CHIP_TARGET(i_procTarget).
                         set_VPD_KEYWORD(i_ring.vpdKeyword),
                         "Code bug: Unsupported value of vpdKeyword (=%d)",
                         i_ring.vpdKeyword );
            break;
    }

    /////////////////////////////////////////////////////////////////////
    // Fetch rings from the MVPD:
    /////////////////////////////////////////////////////////////////////
    l_fapiRc = getMvpdRing( MVPD_RECORD_CP00,
                            l_mvpdKeyword,
                            i_procTarget,
                            i_chipletId,
                            i_evenOdd,
                            i_ring.ringId,
                            (uint8_t*)i_vpdRing,
                            l_vpdRingSize );

    ///////////////////////////////////////////////////////////////////////
    //Append VPD ring to the ring section
    ///////////////////////////////////////////////////////////////////////

    if (l_fapiRc == fapi2::FAPI2_RC_SUCCESS)
    {
        // Update for ring found in mvpd
        io_ringStatusInMvpd = RING_FOUND;

        auto l_scanAddr =
            be32toh(((CompressedScanData*)i_vpdRing)->iv_scanAddr);
        auto l_vpdChipletId = (l_scanAddr & 0xFF000000UL) >> 24;

        // Even though success, checking that chipletId didn't somehow get
        //   messed up (code bug).
        FAPI_ASSERT( l_vpdChipletId == i_chipletId,
                     fapi2::XIPC_MVPD_CHIPLET_ID_MESS().
                     set_CHIP_TARGET(i_procTarget).
                     set_CHIPLET_ID(i_chipletId).
                     set_MVPD_CHIPLET_ID(l_vpdChipletId).
                     set_RING_ID(i_ring.ringId),
                     "_fetch_and_insert_vpd_ring: Code bug: VPD ring's chipletId"
                     " in scan container (=0x%X) doesn't match the requested"
                     " chipletId (=0x%X)",
                     l_vpdChipletId, i_chipletId );

        // Even though success, checking for accidental buffer overflow (code bug).
        FAPI_ASSERT( l_vpdRingSize <= i_vpdRingSize,
                     fapi2::XIPC_MVPD_RING_SIZE_MESS().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ring.ringId).
                     set_CHIPLET_ID(i_chipletId).
                     set_RING_BUFFER_SIZE(i_vpdRingSize).
                     set_MVPD_RING_SIZE(l_vpdRingSize),
                     "_fetch_and_insert_vpd_ring: Code bug: VPD ring size (=0x%X) exceeds"
                     " allowed ring buffer size (=0x%X)",
                     l_vpdRingSize, i_vpdRingSize );

        //@TODO: Remove following line asap. Temporary fix until Sgro starts using
        //       latest p9_scan_compression.H.
        //       Also fix p9_mvpd_ring_funcs.C to look for entire RS4_MAGIC string.
        //       Actually, do all the above in connection with RS4 header
        //       shrinkage (RTC158101 and RTC159801).
        ((CompressedScanData*)i_vpdRing)->iv_magic = htobe16(RS4_MAGIC);

        // Initialize variable to check for redundant ring.
        int redundant = 0;

        // Check if ring is a flush ring, i.e. if it is redundant, meaning that it will
        // result in no change.
        l_rc = rs4_redundant((CompressedScanData*)i_vpdRing, &redundant);
        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_RS4_REDUNDANT_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ring.ringId).
                     set_CHIPLET_ID(i_chipletId),
                     "rs4_redundant: Failed w/rc=%i for "
                     "ringId=0x%02X, chipletId=0x%02X ",
                     l_rc, i_ring.ringId, i_chipletId );

        if (redundant)
        {
            // Update for ring found in mvpd contains redundant data
            io_ringStatusInMvpd = RING_REDUNDANT;

            FAPI_DBG("Skipping redundant VPD ring: ringId=0x%02X, chipletId=0x%02X ", i_ring.ringId, i_chipletId);
            fapi2::current_err = RC_MVPD_RING_REDUNDANT_DATA;
            goto fapi_try_exit;
        }

        // Check for image size already out-of-space. If yes just traverse mvpd file
        // looking for remaining instance rings available if any
        if (i_bImgOutOfSpace == true)
        {
            goto fapi_try_exit;
        }

        // Checking for potential image overflow BEFORE appending the ring.
        if ( (io_ringSectionSize + l_vpdRingSize) > i_maxRingSectionSize )
        {
            // Update flag as image would run out-of-space if we try to append
            // this ring
            i_bImgOutOfSpace = true;

            // Update bootCoreMask is now supported (RTC158106) with insertion
            // of VPD rings in EC order. Thus, should there be an overflow
            // condition the updated io_bootCoreMask would be displayed with
            // ECs supported in the binary image file.
            FAPI_ASSERT( false,
                         fapi2::XIPC_IMAGE_WOULD_OVERFLOW().
                         set_CHIP_TARGET(i_procTarget).
                         set_CURRENT_RING_SECTION_SIZE(io_ringSectionSize).
                         set_SIZE_OF_THIS_RING(l_vpdRingSize).
                         set_MAX_RING_SECTION_SIZE(i_maxRingSectionSize).
                         set_RING_ID(i_ring.ringId).
                         set_CHIPLET_ID(i_chipletId).
                         set_CURRENT_BOOT_CORE_MASK(io_bootCoreMask),
                         "Ran out of image buffer space trying to append a ring"
                         " to the .rings section" );
        }

        //------------------------------------------
        // Now, append the ring to the ring section
        //------------------------------------------

        // Calculate the chiplet TOR index
        uint8_t l_chipletTorId = i_chipletId +
                                 (( i_chipletId - i_ring.instanceIdMin ) *
                                  (i_ring.vpdRingClass == VPD_RING_CLASS_EX_INS ? 1 : 0)) +
                                 i_evenOdd;

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

                if (l_rc == TOR_SUCCESS)
                {
                    FAPI_INF("Successfully added VPD ring: (ringId,evenOdd,chipletId)=(0x%02X,0x%X,0x%02X)",
                             i_ring.ringId, i_evenOdd, i_chipletId);
                }
                else
                {
                    FAPI_ASSERT( false,
                                 fapi2::XIPC_TOR_APPEND_RING_FAILED().
                                 set_CHIP_TARGET(i_procTarget).
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

                if (l_rc == TOR_SUCCESS)
                {
                    FAPI_INF("Successfully added VPD ring: (ringId,evenOdd,chipletId)=(0x%02X,0x%X,0x%02X)",
                             i_ring.ringId, i_evenOdd, i_chipletId);
                }
                else
                {
                    FAPI_ASSERT( false,
                                 fapi2::XIPC_TOR_APPEND_RING_FAILED().
                                 set_CHIP_TARGET(i_procTarget).
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

                if (l_rc == TOR_SUCCESS)
                {
                    FAPI_INF("Successfully added VPD ring: (ringId,evenOdd,chipletId)=(0x%02X,0x%X,0x%02X)",
                             i_ring.ringId, i_evenOdd, i_chipletId);
                }
                else
                {
                    FAPI_ASSERT( false,
                                 fapi2::XIPC_TOR_APPEND_RING_FAILED().
                                 set_CHIP_TARGET(i_procTarget).
                                 set_TOR_RC(l_rc),
                                 "tor_append_ring() failed w/l_rc=%d",
                                 l_rc );
                }

                FAPI_DBG("(After tor_append) io_ringSectionSize = %d", io_ringSectionSize);

                break;

            default:
                FAPI_ASSERT( false,
                             fapi2::XIPC_INVALID_SYSPHASE_PARM().
                             set_CHIP_TARGET(i_procTarget).
                             set_SYSPHASE(i_sysPhase).
                             set_OCCURRENCE(2),
                             "Code bug: Unsupported value of sysPhase (=%d)",
                             i_sysPhase );
                break;
        } // End switch(sysPhase)
    }
    else if ((uint32_t)l_fapiRc == RC_MVPD_RING_NOT_FOUND)
    {
        // Update for ring not found in mvpd
        io_ringStatusInMvpd = RING_NOT_FOUND;

        // No match, do nothing. Next chipletId.
        //@TODO: Uncomment the following after PowerOn. Also, need to come
        //       to agreement whether this should be fatal error or not.
        //       For now, for PO, it's considered benigh and noise and is
        //       being commented out.
        //FAPI_INF("_fetch_and_insert_vpd_rings():"
        //         "(ringId,chipletId)=(0x%X,0x%X) not found.",
        //         i_ring.ringId, i_chipletId);

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
        FAPI_ASSERT( (uint32_t)l_fapiRc != RC_MVPD_RING_BUFFER_TOO_SMALL,
                     fapi2::XIPC_MVPD_RING_SIZE_TOO_BIG().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ring.ringId).
                     set_CHIPLET_ID(i_chipletId).
                     set_RING_BUFFER_SIZE(i_vpdRingSize).
                     set_MVPD_RING_SIZE(l_vpdRingSize),
                     "_fetch_and_insert_vpd_ring(): VPD ring size (=0x%X) exceeds"
                     " allowed ring buffer size (=0x%X)",
                     l_vpdRingSize, i_vpdRingSize );

        // getMvpdRing failed due to invalid record data magic word.
        FAPI_ASSERT( (uint32_t)l_fapiRc != RC_MVPD_INVALID_RS4_HEADER,
                     fapi2::XIPC_MVPD_INVALID_RECORD_DATA().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ring.ringId).
                     set_CHIPLET_ID(i_chipletId),
                     "_fetch_and_insert_vpd_ring(): MVPD has invalid record data" );

        // getMvpdRing failed for some other reason aside from above handled cases.
        if (l_fapiRc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("_fetch_and_insert_vpd_ring(): getMvpdRing failed "
                     " w/rc=0x%08X", (uint64_t)l_fapiRc);
            fapi2::current_err = l_fapiRc;
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting _fetch_and_insert_vpd_ring");
    return fapi2::current_err;

} // End of  _fetch_and_insert_vpd_rings()



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
#ifdef WIN32
int fetch_and_insert_vpd_rings(
    int i_procTarget,
#else
fapi2::ReturnCode fetch_and_insert_vpd_rings(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#endif
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

    ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err  = fapi2::FAPI2_RC_SUCCESS;

    // Variables needed to provide updated bootCoreMask
    VpdInsInsertProg_t l_instanceVpdRing  = {};
    uint8_t l_ringStatusInMvpd            = RING_SCAN;
    bool    l_bImgOutOfSpace              = false;
    uint8_t l_eqNumWhenOutOfSpace         = 0xF;   // Assign invalid value to check for correctness of value when used
    uint8_t l_ringType;

    // Initialize activeCoreMask to be filled up with EC column filling as it progresses
    uint32_t l_activeCoreMask  = 0x0;
    uint32_t l_bootCoreMaskMin = 0x0;

    FAPI_DBG("Entering fetch_and_insert_vpd_rings");

    // Walk through all Vpd rings and add any that's there to the image.
    // Do this in two steps:
    // 1- Add all NEST rings
    // 2- Add QUAD rings in EC order

    // 1- Add all common rings
    // -----------------------
    l_ringType = RING_TYPES::COMMON_RING;

    for (auto vpdType = 0; vpdType < NUM_OF_VPD_TYPES; vpdType++)
    {
        const RingIdList* l_ringIdList = ALL_VPD_RINGS[vpdType].ringIdList;
        auto l_ringIdListSize         = ALL_VPD_RINGS[vpdType].ringIdListSize;
        uint8_t l_instanceIdMax;
        uint8_t l_chipletId;
        uint8_t l_evenOdd = 0;

        for (size_t iRing = 0; iRing < l_ringIdListSize; iRing++)
        {
            // Filter out GPTR requests. Not supported in DD1. Coming in through initfiles instead.
            if (l_ringIdList[iRing].vpdRingClass != VPD_RING_CLASS_EQ_INS &&
                l_ringIdList[iRing].vpdRingClass != VPD_RING_CLASS_EX_INS &&
                l_ringIdList[iRing].vpdRingClass != VPD_RING_CLASS_EC_INS &&
                l_ringIdList[iRing].vpdRingClass != VPD_RING_CLASS_GPTR)
            {
                // We use ring.instanceIdMax column to govern max value of instanceIdMax (i.e., the
                // max chipletId). But unlike in P8, in P9 we will not search for chipletId=0xff in P9
                // MVPD. It is no longer used in the MVPD. We merely keep the multicast Id, 0xff, in
                // the ring list for now, just in case it is needed later on.
                if (l_ringIdList[iRing].instanceIdMax == 0xff)
                {
                    l_instanceIdMax = l_ringIdList[iRing].instanceIdMin;
                }
                else
                {
                    l_instanceIdMax = l_ringIdList[iRing].instanceIdMax;
                }

                for (l_chipletId = l_ringIdList[iRing].instanceIdMin;
                     l_chipletId <= l_instanceIdMax; l_chipletId++)
                {
                    // Fetch common ring
                    // - Fetch all VPD rings for SBE.
                    // - Fetch only EC VPD rings for CME.
                    // - Fetch only EX+EQ VPD rings for SGPE.

                    if ( i_sysPhase == SYSPHASE_HB_SBE ||
                         (i_sysPhase == SYSPHASE_RT_CME  &&
                          l_ringIdList[iRing].vpdRingClass == VPD_RING_CLASS_EC) ||
                         (i_sysPhase == SYSPHASE_RT_SGPE &&
                          (l_ringIdList[iRing].vpdRingClass == VPD_RING_CLASS_EX ||
                           l_ringIdList[iRing].vpdRingClass == VPD_RING_CLASS_EQ)) )
                    {
                        l_fapiRc = _fetch_and_insert_vpd_rings ( i_procTarget,
                                   i_ringSection,
                                   io_ringSectionSize,
                                   i_maxRingSectionSize,
                                   i_sysPhase,
                                   i_vpdRing,
                                   i_vpdRingSize,
                                   i_ringBuf2,
                                   i_ringBufSize2,
                                   l_chipletId,
                                   l_evenOdd,
                                   l_ringIdList[iRing],
                                   l_ringStatusInMvpd,
                                   l_bImgOutOfSpace,
                                   io_bootCoreMask );

                        if (   (uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW ||
                               ( (uint32_t)l_fapiRc != RC_MVPD_RING_REDUNDANT_DATA &&
                                 l_fapiRc != fapi2::FAPI2_RC_SUCCESS ) )
                        {
                            fapi2::current_err = l_fapiRc;
                            FAPI_DBG("_fetch_and_insert_vpd_rings() for common rings w/rc:0x%.8x",
                                     (uint64_t)fapi2::current_err );
                            goto fapi_try_exit;
                        }

                        FAPI_DBG("(CMN) io_ringSectionSize = %d", io_ringSectionSize);
                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    }
                }
            }

        } //Loop on ringId

    } //Loop on VPD types

    // 2- Add all instance rings
    // -------------------------

    // Add all instance [QUAD-level] rings in order - EQ->EX->EC.
    // Looking at the bootCoreMask start adding EQ first followed by EX
    // and finally followed by EC vpd ring insertion in order.
    // For common rings already completed in above step #1.
    // The step #2 instance part is updated looping over chipletId
    // to fill up one core chipletId "column" at a time (RTC158106).

    l_ringType = RING_TYPES::INSTANCE_RING;

    {
        // Initialize ring id list from VPD_RINGS[1]
        const RingIdList* l_ringIdList = ALL_VPD_RINGS[1].ringIdList;
        auto l_ringIdListSize         = ALL_VPD_RINGS[1].ringIdListSize;

        // Initialize local ring eq, ec to first member of ring list
        RingIdList l_ringEQ = l_ringIdList[0];
        RingIdList l_ringEC = l_ringIdList[0];
        RingIdList l_ringEX[4];

        // Initialize flag for eq/ex/ec instances for entry found in ring list
        bool l_flagEQInstanceFound = false;
        bool l_flagEXInstanceFound = false;
        bool l_flagECInstanceFound = false;

        uint8_t l_chipletId;
        int     l_id = 0;

        // Loop for EQ/EX/EC filling
        for (auto eq = 0; eq < NUM_OF_QUADS; eq++)
        {
            uint8_t   l_evenOdd = 0;

            // For EQ instances
            if ( (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_SGPE) )
            {
                // Look for EQ instance in ring list
                if (l_flagEQInstanceFound == false)
                {
                    for (size_t iRing = 0; iRing < l_ringIdListSize; iRing++)
                    {
                        if (l_ringIdList[iRing].vpdRingClass == VPD_RING_CLASS_EQ_INS)
                        {
                            l_ringEQ = l_ringIdList[iRing];
                            l_flagEQInstanceFound = true;
                            break;
                        }
                    }
                }

                if (l_flagEQInstanceFound == true)
                {
                    l_chipletId = l_ringEQ.instanceIdMin + eq;

                    FAPI_DBG("EQ no. %02d; Even(0)/Odd(1):%d; InstanceId:0x%02x; RingName:%s ", eq, l_evenOdd, l_chipletId,
                             l_ringEQ.ringName);

                    if ( ((0x0000000F << ((NUM_OF_QUADS - 1)*CORES_PER_QUAD)) >>
                          ((l_chipletId - l_ringEQ.instanceIdMin)*CORES_PER_QUAD)) &
                         io_bootCoreMask )
                    {
                        // Update for ring in scan mode
                        l_ringStatusInMvpd = RING_SCAN;

                        l_fapiRc = _fetch_and_insert_vpd_rings (
                                       i_procTarget,
                                       i_ringSection,
                                       io_ringSectionSize,
                                       i_maxRingSectionSize,
                                       i_sysPhase,
                                       i_vpdRing,
                                       i_vpdRingSize,
                                       i_ringBuf2,
                                       i_ringBufSize2,
                                       l_chipletId,
                                       l_evenOdd,
                                       l_ringEQ,
                                       l_ringStatusInMvpd,
                                       l_bImgOutOfSpace,
                                       io_bootCoreMask );

                        // Update EQ instance var for ring found in mvpd
                        if (l_ringStatusInMvpd == RING_FOUND)
                        {
                            l_instanceVpdRing.EQ |=
                                (0x00F00000 >> (eq * CORES_PER_QUAD));
                        }

                        if ((uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW)
                        {
                            // Capture EQ number when image ran out-of-space while appending ring
                            l_eqNumWhenOutOfSpace = eq;

                            // Capture current state of chiplet under process
                            l_instanceVpdRing.chipletUnderProcess     = EQ_CHIPLET;
                            l_instanceVpdRing.chipletNumUnderProcess = eq;
                        }
                        else if ( (uint32_t)l_fapiRc != RC_MVPD_RING_REDUNDANT_DATA &&
                                  l_fapiRc != fapi2::FAPI2_RC_SUCCESS )
                        {
                            fapi2::current_err = l_fapiRc;
                            FAPI_DBG("_fetch_and_insert_vpd_rings() for EQ rings w/rc:0x%.8x", (uint64_t)fapi2::current_err );
                            goto fapi_try_exit;
                        }

                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    }
                    else
                    {
                        continue;
                    }
                }
            }

            // For EX instances
            // For EX rings, there's two rings listed in the Mvpd per [EQ] chipletId
            // listed in ring_identification.C: One for each of the two EX, even and odd.
            // Each of these two rings have the same [EQ] chipletId encoded in their
            // iv_chipletId (current RS4 header) or iv_scanAddress (next gen RS4 header).
            // They are distinguished by their even-odd bits in iv_scanAddress and so
            // for each EQ chipletId there's two EX rings to be accommodated.
            for (auto ex = (2 * eq); ex < (2 * (eq + 1)); ex++)
            {
                if ( (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_SGPE) )
                {
                    uint32_t   l_coreMask;

                    if (l_flagEXInstanceFound == false)
                    {
                        // Look for EX instances in ring list
                        for (size_t iRing = 0; iRing < l_ringIdListSize; iRing++)
                        {
                            if (l_ringIdList[iRing].vpdRingClass == VPD_RING_CLASS_EX_INS)
                            {
                                l_ringEX[l_id++] = l_ringIdList[iRing];
                                l_flagEXInstanceFound = true;
                            }
                        }
                    }

                    if (l_flagEXInstanceFound == true)
                    {
                        for (auto inst = 0; inst < l_id; inst++)
                        {
                            l_chipletId = l_ringEX[inst].instanceIdMin + eq;

                            if (ex % 2)
                            {
                                // For higher order ECs in EQ
                                l_coreMask = 0x00000003;
                                l_evenOdd = 1;
                            }
                            else
                            {
                                // For lower order ECs in EQ
                                l_coreMask = 0x0000000C;
                                l_evenOdd = 0;
                            }

                            FAPI_DBG("EX no. %02d; Even(0)/Odd(1):%d; InstanceId:0x%02x; RingName:%s ",
                                     ex, l_evenOdd, l_chipletId, l_ringEX[inst].ringName);

                            if ( ((l_coreMask << ((NUM_OF_QUADS - 1)*CORES_PER_QUAD)) >>
                                  ((l_chipletId - l_ringEX[inst].instanceIdMin)
                                   *CORES_PER_QUAD)) & io_bootCoreMask )
                            {
                                // Update for ring in scan mode
                                l_ringStatusInMvpd = RING_SCAN;

                                l_fapiRc = _fetch_and_insert_vpd_rings (
                                               i_procTarget,
                                               i_ringSection,
                                               io_ringSectionSize,
                                               i_maxRingSectionSize,
                                               i_sysPhase,
                                               i_vpdRing,
                                               i_vpdRingSize,
                                               i_ringBuf2,
                                               i_ringBufSize2,
                                               l_chipletId,
                                               l_evenOdd,
                                               l_ringEX[inst],
                                               l_ringStatusInMvpd,
                                               l_bImgOutOfSpace,
                                               io_bootCoreMask );

                                // Update EX instance var for ring found in mvpd
                                if (l_ringStatusInMvpd == RING_FOUND)
                                {
                                    l_instanceVpdRing.EX[inst] |=
                                        (0x00C00000 >> (ex * (CORES_PER_QUAD / 2)));
                                }

                                if ((uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW)
                                {
                                    // Capture EQ number when image ran out-of-space while appending ring
                                    l_eqNumWhenOutOfSpace = eq;

                                    // Capture current state of chiplet under process
                                    l_instanceVpdRing.chipletUnderProcess     = EX_CHIPLET;
                                    l_instanceVpdRing.exReprRingNum       = inst;
                                    l_instanceVpdRing.chipletNumUnderProcess = ex;
                                }
                                else if ( (uint32_t)l_fapiRc != RC_MVPD_RING_REDUNDANT_DATA &&
                                          l_fapiRc != fapi2::FAPI2_RC_SUCCESS )
                                {
                                    fapi2::current_err = l_fapiRc;
                                    FAPI_DBG("_fetch_and_insert_vpd_rings() for EX rings w/rc:0x%.8x", (uint64_t)fapi2::current_err );
                                    goto fapi_try_exit;
                                }

                                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                            }
                        }
                    } // if (l_flagEXInstanceFound == true)
                } // if ( (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_SGPE) )

                // For EC instances
                if ( (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_CME) )
                {
                    l_evenOdd = 0;

                    if (l_flagECInstanceFound == false)
                    {
                        // Look for EC instance in ring list
                        for (size_t iRing = 0; iRing < l_ringIdListSize; iRing++)
                        {
                            if (l_ringIdList[iRing].vpdRingClass == VPD_RING_CLASS_EC_INS)
                            {
                                l_ringEC = l_ringIdList[iRing];
                                l_flagECInstanceFound = true;
                                break;
                            }
                        }
                    }

                    if (l_flagECInstanceFound == true)
                    {
                        for (auto ec = (2 * ex); ec < (2 * (ex + 1)); ec++)
                        {
                            l_chipletId = l_ringEC.instanceIdMin + ec;
                            FAPI_DBG("EC no. %02d; Even(0)/Odd(1):%d; InstanceId:0x%02x; RingName:%s ", ec, l_evenOdd, l_chipletId,
                                     l_ringEC.ringName);

                            if ( ((0x00000001 << (NUM_OF_CORES - 1)) >>
                                  (l_chipletId - l_ringEC.instanceIdMin)) & io_bootCoreMask )
                            {
                                // Update for ring in scan mode
                                l_ringStatusInMvpd = RING_SCAN;

                                l_fapiRc = _fetch_and_insert_vpd_rings (
                                               i_procTarget,
                                               i_ringSection,
                                               io_ringSectionSize,
                                               i_maxRingSectionSize,
                                               i_sysPhase,
                                               i_vpdRing,
                                               i_vpdRingSize,
                                               i_ringBuf2,
                                               i_ringBufSize2,
                                               l_chipletId,
                                               l_evenOdd,
                                               l_ringEC,
                                               l_ringStatusInMvpd,
                                               l_bImgOutOfSpace,
                                               io_bootCoreMask );

                                // Update EC instance var for ring found in mvpd
                                if (l_ringStatusInMvpd == RING_FOUND)
                                {
                                    l_instanceVpdRing.EC |=
                                        (0x00800000 >> ec);
                                }

                                if ((uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW)
                                {
                                    // Capture EQ number when image ran out-of-space while appending ring
                                    l_eqNumWhenOutOfSpace = eq;

                                    // Capture current state of chiplet under process
                                    l_instanceVpdRing.chipletUnderProcess     = EC_CHIPLET;
                                    l_instanceVpdRing.chipletNumUnderProcess = ec;
                                }
                                else if ( (uint32_t)l_fapiRc != RC_MVPD_RING_REDUNDANT_DATA &&
                                          l_fapiRc != fapi2::FAPI2_RC_SUCCESS )
                                {
                                    fapi2::current_err = l_fapiRc;
                                    FAPI_DBG("_fetch_and_insert_vpd_rings() for EC rings w/rc:0x%.8x", (uint64_t)fapi2::current_err );
                                    goto fapi_try_exit;
                                }
                                else if ( (           l_fapiRc == fapi2::FAPI2_RC_SUCCESS     ||
                                                      (uint32_t)l_fapiRc == RC_MVPD_RING_REDUNDANT_DATA ||
                                                      (uint32_t)l_fapiRc == RC_MVPD_RING_NOT_FOUND ) &&
                                          l_bImgOutOfSpace == false )
                                {
                                    FAPI_DBG("(INS) io_ringSectionSize = %d", io_ringSectionSize);
                                    l_activeCoreMask |= (uint32_t)( 1 << ((NUM_OF_CORES - 1) - ec) );
                                }

                                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                            }

                            l_chipletId++;
                        }
                    } // if (l_flagECInstanceFound == true)
                } //if ( (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_CME) )
            } //for (auto ex = (2*eq); ex = (2*(eq+1)); ex++)
        }
    }

fapi_try_exit:

    if( (l_ringType == RING_TYPES::COMMON_RING) &&
        (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS) )
    {
        //Error handling:
        //-when image would have run out-of-space if try to append common ring
        //-Any other 'unknown/unexpected' error reported
        io_bootCoreMask = 0;
        FAPI_IMP("bootCoreMask value: 0x%08x", io_bootCoreMask);
        FAPI_DBG("Exiting fetch_and_insert_vpd_rings");
        return fapi2::current_err;
    }
    else if( (l_ringType == RING_TYPES::INSTANCE_RING) &&
             (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS) )
    {
        //Error handling: Any other 'unknown/unexpected' error reported
        io_bootCoreMask = l_activeCoreMask;
        FAPI_IMP("bootCoreMask value: 0x%08x", io_bootCoreMask);
        FAPI_DBG("Exiting fetch_and_insert_vpd_rings");
        return fapi2::current_err;
    }

    // Display all EQ/EX/EC instance rings found in mvpd for given bootCoreMask
    FAPI_DBG("List of instance rings available in mvpd (as per bootCoreMask):");
    FAPI_DBG("Domain | Domain rings in Mvpd");
    FAPI_DBG("-----------------------------");
    FAPI_DBG("EQ     | 0x%08x", l_instanceVpdRing.EQ);
    FAPI_DBG("EX     | 0x%08x", (l_instanceVpdRing.EX[0] |
                                 l_instanceVpdRing.EX[1] |
                                 l_instanceVpdRing.EX[2] |
                                 l_instanceVpdRing.EX[3]));
    FAPI_DBG("EC     | 0x%08x", l_instanceVpdRing.EC);
    FAPI_DBG("-----------------------------");

    l_bootCoreMaskMin = ~(l_instanceVpdRing.EQ |
                          l_instanceVpdRing.EX[0] |
                          l_instanceVpdRing.EX[1] |
                          l_instanceVpdRing.EX[2] |
                          l_instanceVpdRing.EX[3] |
                          l_instanceVpdRing.EC) &
                        io_bootCoreMask;
    FAPI_DBG("bootCoreMaskMin: 0x%08x", l_bootCoreMaskMin);
    FAPI_DBG("ActiveCoreMask : 0x%08x", l_activeCoreMask);

    // Normal case when generated image didn't ran out-of-space
    if (l_bImgOutOfSpace == false)
    {
        FAPI_DBG("Seeprom image created successfully");
        l_activeCoreMask |= io_bootCoreMask;
    }
    else    // Case where generated image ran out-of-space
    {
        // Useful debug info when image ran out-of-space
        FAPI_DBG("--------------------------------------------------------------");
        FAPI_DBG("Seeprom image creation ran out-of-space...");
        FAPI_DBG("EQ number at image overflow                     : %d", l_eqNumWhenOutOfSpace);
        FAPI_DBG("Chiplet name under process at image overflow    : %s",
                 ((l_instanceVpdRing.chipletUnderProcess == 0) ? "EQ" :
                  ((l_instanceVpdRing.chipletUnderProcess == 1) ? "EX" : "EC")));
        FAPI_DBG("EX repr instance number (valid when chiplet=EX) : %d", l_instanceVpdRing.exReprRingNum);
        FAPI_DBG("Chiplet number under process at image overflow  : %d", l_instanceVpdRing.chipletNumUnderProcess);
        FAPI_DBG("--------------------------------------------------------------");

        // Make sure EQ chiplet is captured and valid when image ran out-of-space
        if ( l_eqNumWhenOutOfSpace < NUM_OF_QUADS )
        {
            // Process EQ and other chiplets in current quad
            do
            {
                // Process EQ when image ran out-of-space
                //if (l_instanceVpdRing.chipletUnderProcess == EQ_CHIPLET)
                //{
                //    break;
                //}

                // Process EX when image ran out-of-space
                // ======================================
                // Check for EX: odd(1)/even(0)
                // Process even EX here as for odd EX no separate processing
                // needed in current quad when image ran out-of-space
                // processing odd EX.
                if ( (l_instanceVpdRing.chipletUnderProcess == EX_CHIPLET) &&
                     !(l_instanceVpdRing.chipletNumUnderProcess % 2) )
                {
                    // Process even EX: If image ran out-of-space when processing
                    // even EX then continue processing current quad to check
                    // for cores under odd EX
                    uint8_t l_exRingNum;

                    for (l_exRingNum = l_instanceVpdRing.exReprRingNum;
                         l_exRingNum < 4; l_exRingNum++)
                    {
                        if (l_instanceVpdRing.EX[l_exRingNum] &
                            (EX_EVEN_POS >>
                             ( (l_instanceVpdRing.chipletNumUnderProcess + 1) * 2)) )
                        {
                            break;
                        }
                    }

                    if (l_exRingNum >= 4)
                    {
                        uint32_t l_ecMask = l_instanceVpdRing.EC &
                                            (ODD_CORES_IN_EX >>
                                             (l_instanceVpdRing.chipletNumUnderProcess *
                                              (CORES_PER_QUAD / 2)));

                        if (l_ecMask == 0)
                        {
                            l_activeCoreMask |=
                                ( (ODD_CORES_IN_EX >>
                                   (l_instanceVpdRing.chipletNumUnderProcess *
                                    (CORES_PER_QUAD / 2))) & io_bootCoreMask );
                        }
                        else if (l_ecMask == (uint32_t)(ODD_CORES_IN_EX >>
                                                        (l_instanceVpdRing.chipletNumUnderProcess *
                                                         (CORES_PER_QUAD / 2))) )
                        {
                            break;
                        }
                        else if (l_ecMask == (uint32_t)(HIGH_ORDER_ODD_CORE_IN_EX >>
                                                        (l_instanceVpdRing.chipletNumUnderProcess *
                                                         (CORES_PER_QUAD / 2))) )
                        {
                            l_activeCoreMask |=
                                ( (LOW_ORDER_ODD_CORE_IN_EX >> (l_instanceVpdRing.chipletNumUnderProcess * 2)) &
                                  io_bootCoreMask );
                        }
                        else if (l_ecMask == (uint32_t)(LOW_ORDER_ODD_CORE_IN_EX >>
                                                        (l_instanceVpdRing.chipletNumUnderProcess *
                                                         (CORES_PER_QUAD / 2))) )
                        {
                            l_activeCoreMask |=
                                ( (HIGH_ORDER_ODD_CORE_IN_EX >> (l_instanceVpdRing.chipletNumUnderProcess *
                                                                 (CORES_PER_QUAD / 2))) & io_bootCoreMask );
                        }
                    }
                }

                // Process EC when image ran out-of-space
                else if (l_instanceVpdRing.chipletUnderProcess == EC_CHIPLET)
                {
                    // Get EC position [1:4] in quad
                    // l_ecPos = 1 : Refer fourth core in quad say EC-3 in EQ-0
                    // l_ecPos = 2 : Refer third  core in quad say EC-2 in EQ-0
                    // l_ecPos = 3 : Refer second core in quad say EC-1 in EQ-0
                    // l_ecPos = 4 : Refer first  core in quad say EC-0 in EQ-0
                    uint8_t l_ecPos = ( (l_eqNumWhenOutOfSpace + 1) * CORES_PER_QUAD) -
                                      l_instanceVpdRing.chipletNumUnderProcess;

                    // We have come to this point (EC chiplet) confirms that the
                    // EQ instance ring for this quad would have been appended and also
                    // the EX-odd/even (depending on EC chiplets) instance rings would
                    // have been appended as well. Now here we should check for the
                    // remaining EC chiplets (apart from one during processing
                    // of which image ran out-of-space) in quad for which instance
                    // rings available (or not) to be appended. If not available
                    // make sure to update the activecoremask as this chiplet can
                    // work with common ring and no instance ring available for
                    // this chiplet.
                    switch (l_ecPos)
                    {
                        case 4:
                        case 2:
                            if (!(l_instanceVpdRing.EC &
                                  (EC_POSITION >>
                                   (l_instanceVpdRing.chipletNumUnderProcess + 1))))
                            {
                                l_activeCoreMask |= ( (EC_POSITION >>
                                                       (l_instanceVpdRing.chipletNumUnderProcess + 1)) &
                                                      io_bootCoreMask);
                            }

                        case 3:
                            uint8_t l_exId;

                            for (l_exId = 0; l_exId < 4; l_exId++)
                            {
                                if (l_instanceVpdRing.EX[l_exId] &
                                    (EX_EVEN_POS >> (l_instanceVpdRing.chipletNumUnderProcess + 1)) )
                                {
                                    break;
                                }
                            }

                            if (l_exId >= 4)
                            {
                                uint32_t l_ecId = l_instanceVpdRing.EC &
                                                  (ODD_CORES_IN_EX >> (l_instanceVpdRing.chipletNumUnderProcess - 1));

                                if (l_ecId == 0)
                                {
                                    l_activeCoreMask |=
                                        ( (ODD_CORES_IN_EX >> (l_instanceVpdRing.chipletNumUnderProcess - 1)) &
                                          io_bootCoreMask );
                                }
                                //else if (l_ecId == (uint32_t)(ODD_CORES_IN_EX >>
                                //                              (l_instanceVpdRing.chipletNumUnderProcess - 1)) )
                                //{
                                //    break;
                                //}
                                else if (l_ecId == (uint32_t)(HIGH_ORDER_ODD_CORE_IN_EX >>
                                                              (l_instanceVpdRing.chipletNumUnderProcess - 1)) )
                                {
                                    l_activeCoreMask |=
                                        ( (LOW_ORDER_ODD_CORE_IN_EX >> (l_instanceVpdRing.chipletNumUnderProcess - 1)) &
                                          io_bootCoreMask );
                                }
                                else if (l_ecId == (uint32_t)(LOW_ORDER_ODD_CORE_IN_EX >>
                                                              (l_instanceVpdRing.chipletNumUnderProcess - 1)) )
                                {
                                    l_activeCoreMask |=
                                        ( (HIGH_ORDER_ODD_CORE_IN_EX >> (l_instanceVpdRing.chipletNumUnderProcess - 1)) &
                                          io_bootCoreMask );
                                }
                            }

                            break;

                        case 1:
                            break;

                        default:
                            FAPI_DBG("Incorrect EC mask. It should not come here");
                            break;
                    } // switch (l_ecPos)
                }   // else if (l_instanceVpdRing.chipletUnderProcess == EC_CHIPLET)
            }
            while(false); // Process EQ and other chiplets in current quad

            // Get minimum set of EC cores or'ed that should be supported
            // should we hit the ceiling
            l_activeCoreMask |= l_bootCoreMaskMin;
        }
        else
        {
            FAPI_DBG("Image ran out-of-space. Value computed NOT correct");
        }

        fapi2::current_err = RC_XIPC_IMAGE_WOULD_OVERFLOW;
    } // Case where generated image ran out-of-space

    io_bootCoreMask = l_activeCoreMask;
    FAPI_IMP("bootCoreMask value: 0x%08x", io_bootCoreMask);
    FAPI_DBG("Exiting fetch_and_insert_vpd_rings");
    return fapi2::current_err;

} // End of   fetch_and_insert_vpd_rings()



#ifndef WIN32
fapi2::ReturnCode p9_xip_customize (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#else
ReturnCode p9_xip_customize (
    int& i_procTarget,
#endif
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
#ifndef WIN32
    fapi2::ReturnCode   l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode   l_fapiRc2 = fapi2::FAPI2_RC_SUCCESS;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
#else
    ReturnCode   l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    ReturnCode   l_fapiRc2 = fapi2::FAPI2_RC_SUCCESS;
#endif
    int                 l_rc = 0; // Non-fapi RC

    P9XipSection    l_xipRingsSection;
    uint32_t        l_inputImageSize;
    uint32_t        l_imageSizeWithoutRings;
    uint32_t        l_currentImageSize;
    uint32_t        l_maxImageSize = 0; // Attrib adjusted local value of MAX_SEEPROM_IMAGE_SIZE
    uint32_t        l_maxRingSectionSize;
    uint32_t        l_sectionOffset = 1;
    uint8_t         attrDdLevel = 0;
    uint32_t        attrMaxSbeSeepromSize = 0;
    uint32_t        l_requestedBootCoreMask = (i_sysPhase == SYSPHASE_HB_SBE) ? io_bootCoreMask : 0x00FFFFFF;
    void*           l_hwRingsSection;


    FAPI_DBG ("Entering p9_xip_customize w/sysPhase=%d...", i_sysPhase);


    // Make copy of the requested bootCoreMask
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
                 set_CHIP_TARGET(i_procTarget).
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

    l_rc = p9_xip_image_size(io_image, &l_inputImageSize);

    FAPI_ASSERT( l_rc == 0,
                 fapi2::XIPC_XIP_API_MISC_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_XIP_RC(l_rc).
                 set_OCCURRENCE(1),
                 "p9_xip_image_size() failed (1) w/rc=0x%08X",
                 (uint32_t)l_rc );

    // Check that buffer sizes are > or == to some minimum sizes. More precise size checks
    //   later for each sysPhase. Neither io_imageSize nor io_ringSectionBufSize are
    //   subject to attrMaxSbeSeepromSize adjust yet, since this is sysPhase dependent.
    FAPI_ASSERT( (io_imageSize >= l_inputImageSize || io_imageSize >= MAX_SEEPROM_IMAGE_SIZE) &&
                 io_ringSectionBufSize >= MAX_SEEPROM_IMAGE_SIZE &&
                 i_ringBufSize1 == MAX_RING_BUF_SIZE &&
                 i_ringBufSize2 == MAX_RING_BUF_SIZE,
                 fapi2::XIPC_INVALID_INPUT_BUFFER_SIZE_PARM().
                 set_CHIP_TARGET(i_procTarget).
                 set_INPUT_IMAGE_SIZE(l_inputImageSize).
                 set_IMAGE_BUF_SIZE(io_imageSize).
                 set_RING_SECTION_BUF_SIZE(io_ringSectionBufSize).
                 set_RING_BUF_SIZE1(i_ringBufSize1).
                 set_RING_BUF_SIZE2(i_ringBufSize2).
                 set_OCCURRENCE(1),
                 "One or more invalid input buffer sizes:\n"
                 "  l_inputImageSize=0x%016llx\n"
                 "  io_imageSize=0x%016llx\n"
                 "  io_ringSectionBufSize=0x%016llx\n"
                 "  i_ringBufSize1=0x%016llx\n"
                 "  i_ringBufSize2=0x%016llx\n",
                 (uintptr_t)l_inputImageSize,
                 (uintptr_t)io_imageSize,
                 (uintptr_t)io_ringSectionBufSize,
                 (uintptr_t)i_ringBufSize1,
                 (uintptr_t)i_ringBufSize2 );

    FAPI_DBG("Input image size: %d", l_inputImageSize);


    ///////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Write mailbox attributes
    // System phase:       HB_SBE
    ///////////////////////////////////////////////////////////////////////////

#ifndef WIN32

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        FAPI_TRY(writeMboxRegs(i_procTarget, io_image),
                 "p9_xip_customize: error writing mbox regs in SBE image rc=0x%.8x",
                 (uint64_t)fapi2::current_err);
        FAPI_TRY(writePG(i_procTarget, io_image),
                 "p9_xip_customize: error writing PG data in SBE image rc=0x%.8x",
                 (uint64_t)fapi2::current_err);
    }



    ///////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Update PIBMEM repair attributes in Seeprom image
    // System phase:       HB_SBE
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        uint8_t    l_pibmemRepVersion = 0;
        uint64_t   l_pibmemRepData[4] = {0};
        uint32_t   l_sizeMvpdFieldExpected = sizeof(l_pibmemRepVersion) + sizeof(l_pibmemRepData);
        uint32_t   l_sizeMvpdField = 0;
        uint8_t*   l_bufMvpdField = (uint8_t*)io_ringBuf1;

        FAPI_TRY( getMvpdField(MVPD_RECORD_CP00,
                               MVPD_KEYWORD_PB,
                               i_procTarget,
                               NULL,
                               l_sizeMvpdField),
                  "getMvpdField(NULL buffer) failed w/rc=0x%08x",
                  (uint64_t)fapi2::current_err );

        FAPI_ASSERT( l_sizeMvpdField == l_sizeMvpdFieldExpected,
                     fapi2::XIPC_MVPD_FIELD_SIZE_MESS().
                     set_CHIP_TARGET(i_procTarget).
                     set_MVPD_FIELD_SIZE(l_sizeMvpdField).
                     set_EXPECTED_SIZE(l_sizeMvpdFieldExpected),
                     "MVPD field size bug:\n"
                     "  Returned MVPD field size of PB keyword = %d\n"
                     "  Anticipated MVPD field size = %d",
                     l_sizeMvpdField,
                     l_sizeMvpdFieldExpected );

        FAPI_TRY( getMvpdField(MVPD_RECORD_CP00,
                               MVPD_KEYWORD_PB,
                               i_procTarget,
                               l_bufMvpdField,
                               l_sizeMvpdField),
                  "getMvpdField(valid buffer) failed w/rc=0x%08x",
                  (uint64_t)fapi2::current_err );

        // Copy over the data into suitable 8Byte containers
        l_pibmemRepVersion = (uint8_t)(*l_bufMvpdField);
        l_pibmemRepData[0] = htobe64( *((uint64_t*)(l_bufMvpdField + 1)) );
        l_pibmemRepData[1] = htobe64( *((uint64_t*)(l_bufMvpdField + 1 + 8)) );
        l_pibmemRepData[2] = htobe64( *((uint64_t*)(l_bufMvpdField + 1 + 16)) );
        l_pibmemRepData[3] = htobe64( *((uint64_t*)(l_bufMvpdField + 1 + 24)) );

        FAPI_DBG("Retrieved Mvpd PB keyword field:\n");
        FAPI_DBG(" l_pibmemRepVersion = 0x%02x\n"
                 " l_pibmemRepData[1] = 0x%016llx\n"
                 " l_pibmemRepData[1] = 0x%016llx\n"
                 " l_pibmemRepData[2] = 0x%016llx\n"
                 " l_pibmemRepData[3] = 0x%016llx\n",
                 l_pibmemRepVersion,
                 l_pibmemRepData[0],
                 l_pibmemRepData[1],
                 l_pibmemRepData[2],
                 l_pibmemRepData[3]);

        FAPI_TRY( p9_xip_set_scalar(io_image, "ATTR_PIBMEM_REPAIR0", l_pibmemRepData[0]),
                  "p9_xip_set_scalar(ATTR_PIBMEM_REPAIR0) failed w/rc=0x%08x",
                  (uint64_t)fapi2::current_err );

        FAPI_TRY( p9_xip_set_scalar(io_image, "ATTR_PIBMEM_REPAIR1", l_pibmemRepData[1]),
                  "p9_xip_set_scalar(ATTR_PIBMEM_REPAIR1) failed w/rc=0x%08x",
                  (uint64_t)fapi2::current_err );

        FAPI_TRY( p9_xip_set_scalar(io_image, "ATTR_PIBMEM_REPAIR2", l_pibmemRepData[2]),
                  "p9_xip_set_scalar(ATTR_PIBMEM_REPAIR2) failed w/rc=0x%08x",
                  (uint64_t)fapi2::current_err );

    }

#endif



    ///////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:  Removal of .toc, .fixed_toc and .strings
    // System phase:    HB_SBE
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {

        // Get the image size.
        l_rc = p9_xip_image_size(io_image, &l_currentImageSize);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_XIP_API_MISC_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_RC(l_rc).
                     set_OCCURRENCE(9),
                     "p9_xip_image_size() failed (9) w/rc=0x%08X",
                     (uint32_t)l_rc );

        FAPI_DBG("Image size before XIP section removals: %d", l_currentImageSize);

        // Remove .toc:
        // This will remove external visibility to image's attributes and other global variables.
        l_rc = p9_xip_delete_section(io_image, io_ringSectionBuf, l_currentImageSize, P9_XIP_SECTION_TOC);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_SECTION_REMOVAL_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_SECTION(P9_XIP_SECTION_TOC),
                     "p9_xip_delete_section() failed to remove .toc section w/rc=0x%08X",
                     (uint32_t)l_rc );

        // Remove .fixedtoc:
        l_rc = p9_xip_delete_section(io_image, io_ringSectionBuf, l_currentImageSize, P9_XIP_SECTION_FIXED_TOC);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_SECTION_REMOVAL_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_SECTION(P9_XIP_SECTION_FIXED_TOC),
                     "p9_xip_delete_section() failed to remove .fixedtoc section w/rc=0x%08X",
                     (uint32_t)l_rc );

        // Remove .strings:
        // The .strings section must be removed after .toc and .fixed_toc.  Otherwise
        //   we get an P9_XIP_TOC_ERROR, probably because either of those two sections
        //   will "complain" on the next XIP API access that info they need in .strings
        //   is missing, i.e. as part of p9_xip_validate_image().
        l_rc = p9_xip_delete_section(io_image, io_ringSectionBuf, l_currentImageSize, P9_XIP_SECTION_STRINGS);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_SECTION_REMOVAL_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_SECTION(P9_XIP_SECTION_STRINGS),
                     "p9_xip_delete_section() failed to remove .fixedtoc section w/rc=0x%08X",
                     (uint32_t)l_rc );

        // Check the image size.
        l_rc = p9_xip_image_size(io_image, &l_currentImageSize);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_XIP_API_MISC_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_RC(l_rc).
                     set_OCCURRENCE(8),
                     "p9_xip_image_size() failed (7) w/rc=0x%08X",
                     (uint32_t)l_rc );

        FAPI_DBG("Image size after XIP section removals: %d", l_currentImageSize);

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

            FAPI_DBG("Image size before any VPD updates: %d", l_currentImageSize);

#ifndef WIN32
            // Adjust the local size of MAX_SEEPROM_IMAGE_SIZE to accommodate enlarged image for Cronus
            l_fapiRc2 = FAPI_ATTR_GET(fapi2::ATTR_MAX_SBE_SEEPROM_SIZE, FAPI_SYSTEM, attrMaxSbeSeepromSize);

            FAPI_ASSERT( l_fapiRc2 == fapi2::FAPI2_RC_SUCCESS,
                         fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                         set_CHIP_TARGET(i_procTarget).
                         set_OCCURRENCE(2),
                         "FAPI_ATTR_GET(ATTR_MAX_SBE_SEEPROM_SIZE) failed."
                         " Unable to determine ATTR_MAX_SBE_SEEPROM_SIZE,"
                         " so don't know what what max image size." );

            if (attrMaxSbeSeepromSize == MAX_SBE_SEEPROM_SIZE)
            {
                l_maxImageSize = MAX_SEEPROM_IMAGE_SIZE;
            }
            else if (attrMaxSbeSeepromSize > MAX_SBE_SEEPROM_SIZE)
            {
                l_maxImageSize = attrMaxSbeSeepromSize;
            }
            else
            {
                FAPI_ASSERT( false,
                             fapi2::XIPC_ATTR_MAX_SBE_SEEPROM_SIZE_TOO_SMALL().
                             set_CHIP_TARGET(i_procTarget).
                             set_ATTR_MAX_SBE_SEEPROM_SIZE(attrMaxSbeSeepromSize).
                             set_MAX_SBE_SEEPROM_SIZE(MAX_SBE_SEEPROM_SIZE),
                             "SBE Seeprom size reported in attribute (=0x%x) is smaller than"
                             " MAX_SBE_SEEPROM_SIZE (=0x%x)",
                             attrMaxSbeSeepromSize,
                             MAX_SBE_SEEPROM_SIZE );
            }

            FAPI_DBG("Platform adjusted MAX_SEEPROM_IMAGE_SIZE: %d", l_maxImageSize);
#else
            l_maxImageSize = MAX_SEEPROM_IMAGE_SIZE;
#endif

            // Make sure current image size isn't already too big for Seeprom
            FAPI_ASSERT( l_currentImageSize <= l_maxImageSize,
                         fapi2::XIPC_IMAGE_TOO_LARGE().
                         set_CHIP_TARGET(i_procTarget).
                         set_IMAGE_SIZE(l_currentImageSize).
                         set_MAX_IMAGE_SIZE(l_maxImageSize).
                         set_OCCURRENCE(1),
                         "Image size before VPD updates (=%d) already exceeds max image size (=%d)",
                         l_currentImageSize, l_maxImageSize );

            // Test supplied buffer spaces are big enough to hold max image size
            FAPI_ASSERT( io_imageSize >= l_maxImageSize,
                         fapi2::XIPC_INVALID_INPUT_BUFFER_SIZE_PARM().
                         set_CHIP_TARGET(i_procTarget).
                         set_INPUT_IMAGE_SIZE(l_inputImageSize).
                         set_IMAGE_BUF_SIZE(io_imageSize).
                         set_RING_SECTION_BUF_SIZE(io_ringSectionBufSize).
                         set_RING_BUF_SIZE1(i_ringBufSize1).
                         set_RING_BUF_SIZE2(i_ringBufSize2).
                         set_OCCURRENCE(2),
                         "One or more invalid input buffer sizes for HB_SBE phase:\n"
                         "  l_maxImageSize=0x%016llx\n"
                         "  io_imageSize=0x%016llx\n"
                         "  io_ringSectionBufSize=0x%016llx\n",
                         (uintptr_t)l_maxImageSize,
                         (uintptr_t)io_imageSize,
                         (uintptr_t)io_ringSectionBufSize );

            // Copy, save and delete the .rings section, wherever it is (even if
            //   not the last section), and re-arrange other sections located above
            //   the .rings section.
            // Keep a copy of the original input image, io_image, in io_ringSectionBuf.
            l_rc = p9_xip_delete_section(io_image, io_ringSectionBuf, l_currentImageSize, P9_XIP_SECTION_SBE_RINGS);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(2),
                         "p9_xip_delete_section() failed removing .rings w/rc=0x%08X",
                         (uint32_t)l_rc );

            // Make a note of the image size without .rings
            l_rc = p9_xip_image_size(io_image, &l_imageSizeWithoutRings);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(3),
                         "p9_xip_image_size() failed (3) w/rc=0x%08X",
                         (uint32_t)l_rc );

            FAPI_DBG("Size of image before VPD update (excl .rings): %d", l_imageSizeWithoutRings);

            // Get the size of our .rings section.
            l_rc = p9_xip_get_section(io_ringSectionBuf, P9_XIP_SECTION_SBE_RINGS, &l_xipRingsSection);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(4),
                         "p9_xip_get_section() failed (4) getting .rings section w/rc=0x%08X",
                         (uint32_t)l_rc );

            io_ringSectionBufSize = l_xipRingsSection.iv_size;

            FAPI_ASSERT( io_ringSectionBufSize > 0,
                         fapi2::XIPC_EMPTY_RING_SECTION().
                         set_CHIP_TARGET(i_procTarget),
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

            l_fapiRc = fetch_and_insert_vpd_rings( i_procTarget,
                                                   io_ringSectionBuf,
                                                   io_ringSectionBufSize, // Running section size
                                                   l_maxRingSectionSize,  // Max section size
                                                   i_sysPhase,
                                                   io_ringBuf1,
                                                   i_ringBufSize1,
                                                   io_ringBuf2,
                                                   i_ringBufSize2,
                                                   io_bootCoreMask );

            FAPI_DBG("-----------------------------------------------------------------------");
            FAPI_DBG("bootCoreMask:  Requested=0x%08X  Final=0x%08X",
                     l_requestedBootCoreMask, io_bootCoreMask);
            FAPI_DBG("-----------------------------------------------------------------------");

            if (l_fapiRc)
            {

                if ((uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW)
                {
                    FAPI_INF("p9_xip_customize(): Image is full. Ran out of space appending VPD rings"
                             " to the .rings section");

                    // Check the bootCoreMask to determine if enough cores have been configured.
                    uint8_t attrMinReqdEcs = 0;
                    uint8_t  l_actualEcCount = 0;

                    l_fapiRc2 = FAPI_ATTR_GET(fapi2::ATTR_SBE_IMAGE_MINIMUM_VALID_ECS, FAPI_SYSTEM, attrMinReqdEcs);

                    FAPI_ASSERT( l_fapiRc2 == fapi2::FAPI2_RC_SUCCESS,
                                 fapi2::XIPC_IMAGE_WOULD_OVERFLOW_ADDL_INFO().
                                 set_CHIP_TARGET(i_procTarget).
                                 set_REQUESTED_BOOT_CORE_MASK(l_requestedBootCoreMask).
                                 set_CURRENT_BOOT_CORE_MASK(io_bootCoreMask),
                                 "FAPI_ATTR_GET(ATTR_SBE_IMAGE_MINIMUM_VALID_ECS) failed."
                                 " Unable to determine ATTR_SBE_IMAGE_MINIMUM_VALID_ECS,"
                                 " so don't know if the minimum core set was met." );

                    FAPI_DBG("attrMinReqdEcs = 0x%x", attrMinReqdEcs);

                    // Count number of ECs set in bootCoreMask
                    l_actualEcCount = 0;

                    for (uint8_t iCore = 0; iCore < NUM_OF_CORES; iCore++)
                    {
                        if (io_bootCoreMask & ((0x00000001 << (NUM_OF_CORES - 1)) >> iCore))
                        {
                            l_actualEcCount++;
                        }
                    }

                    FAPI_ASSERT( l_actualEcCount >= attrMinReqdEcs,
                                 fapi2::XIPC_IMAGE_WOULD_OVERFLOW_BEFORE_REACHING_MIN_ECS().
                                 set_CHIP_TARGET(i_procTarget).
                                 set_REQUESTED_BOOT_CORE_MASK(l_requestedBootCoreMask).
                                 set_CURRENT_BOOT_CORE_MASK(io_bootCoreMask).
                                 set_MIN_REQD_ECS(attrMinReqdEcs).
                                 set_ACTUAL_EC_COUNT(l_actualEcCount),
                                 "Image buffer would overflow before reaching the minimum required"
                                 " number of EC boot cores" );

                }

                fapi2::current_err = l_fapiRc;
                goto fapi_try_exit;

            }

            // More size code sanity checks of section and image sizes.
            FAPI_ASSERT( io_ringSectionBufSize <= l_maxRingSectionSize,
                         fapi2::XIPC_SECTION_SIZING().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_SECTION_SIZE(io_ringSectionBufSize).
                         set_MAX_RING_SECTION_SIZE(l_maxRingSectionSize),
                         "Code bug: ringSectionBufSize>maxRingSectionSize" );

            FAPI_ASSERT( (l_imageSizeWithoutRings + io_ringSectionBufSize) <= l_maxImageSize,
                         fapi2::XIPC_IMAGE_SIZING().
                         set_CHIP_TARGET(i_procTarget).
                         set_IMAGE_SIZE_WITHOUT_RINGS(l_imageSizeWithoutRings).
                         set_RING_SECTION_SIZE(io_ringSectionBufSize).
                         set_MAX_IMAGE_SIZE(l_maxImageSize),
                         "Code bug: imageSize would exceed maxImageSize" );

            FAPI_DBG( "Image details: io_ringSectionBufSize=%d, l_imageSizeWithoutRings=%d,"
                      "  l_maxImageSize=%d",
                      io_ringSectionBufSize, l_imageSizeWithoutRings, l_maxImageSize );

            //--------------------------------------------------------
            // Append the updated .rings section to the Seeprom image
            //--------------------------------------------------------

            l_rc = p9_xip_append( io_image,
                                  P9_XIP_SECTION_SBE_RINGS,
                                  io_ringSectionBuf,
                                  (const uint32_t)io_ringSectionBufSize,
                                  (const uint32_t)l_maxImageSize,
                                  &l_sectionOffset,
                                  0 );

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(5),
                         "p9_xip_append() failed w/rc=0x%08x",
                         (uint32_t)l_rc );

            FAPI_DBG("sectionOffset=0x%08X", l_sectionOffset);

            l_rc = p9_xip_image_size(io_image, &l_currentImageSize);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(6),
                         "p9_xip_image_size() failed (6) w/rc=0x%08X",
                         (uint32_t)l_rc );

            FAPI_DBG( "Image size after VPD updates: %d", l_currentImageSize );

            FAPI_ASSERT( l_currentImageSize <= l_maxImageSize,
                         fapi2::XIPC_IMAGE_TOO_LARGE().
                         set_CHIP_TARGET(i_procTarget).
                         set_IMAGE_SIZE(l_currentImageSize).
                         set_MAX_IMAGE_SIZE(l_maxImageSize).
                         set_OCCURRENCE(2),
                         "Image size after VPD updates (=%d) exceeds max image size (=%d)",
                         l_currentImageSize, l_maxImageSize );

            break;

        case SYSPHASE_RT_CME:
        case SYSPHASE_RT_SGPE:

            FAPI_ASSERT( io_imageSize == l_inputImageSize &&
                         io_ringSectionBufSize >= MAX_SEEPROM_IMAGE_SIZE, //Not subject to attrMaxSbeSeepromSize adjust
                         fapi2::XIPC_INVALID_INPUT_BUFFER_SIZE_PARM().
                         set_CHIP_TARGET(i_procTarget).
                         set_INPUT_IMAGE_SIZE(l_inputImageSize).
                         set_IMAGE_BUF_SIZE(io_imageSize).
                         set_RING_SECTION_BUF_SIZE(io_ringSectionBufSize).
                         set_RING_BUF_SIZE1(i_ringBufSize1).
                         set_RING_BUF_SIZE2(i_ringBufSize2).
                         set_OCCURRENCE(3),
                         "One or more invalid input buffer sizes for RT_CME or RT_SGPE phase:\n"
                         "  l_inputImageSize=0x%016llx\n"
                         "  io_imageSize=0x%016llx\n"
                         "  io_ringSectionBufSize=0x%016llx\n",
                         (uintptr_t)l_inputImageSize,
                         (uintptr_t)io_imageSize,
                         (uintptr_t)io_ringSectionBufSize );

            l_maxRingSectionSize = io_ringSectionBufSize;

            // Calculate pointer to HW image's .rings section
            l_rc = p9_xip_get_section(io_image, P9_XIP_SECTION_HW_RINGS, &l_xipRingsSection);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(7),
                         "p9_xip_get_section() failed (7) getting .rings section w/rc=0x%08X",
                         (uint32_t)l_rc );

            FAPI_ASSERT( l_xipRingsSection.iv_size > 0,
                         fapi2::XIPC_EMPTY_RING_SECTION().
                         set_CHIP_TARGET(i_procTarget),
                         "CME or SGPE ring section size is zero (sysPhase=%d). No TOR. Can't append rings.",
                         i_sysPhase );

            l_hwRingsSection = (void*)((uintptr_t)io_image + l_xipRingsSection.iv_offset);

#ifndef WIN32
            // Extract the DD level to enable retrieval of correct CME/SGPE ring blocks
            l_fapiRc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, i_procTarget, attrDdLevel);

            FAPI_ASSERT( l_fapiRc == fapi2::FAPI2_RC_SUCCESS,
                         fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                         set_CHIP_TARGET(i_procTarget).
                         set_OCCURRENCE(1),
                         "FAPI_ATTR_GET(ATTR_EC) failed." );
#else
            attrDdLevel = g_ddLevel;
#endif

            FAPI_DBG("attrDdLevel = 0x%x", attrDdLevel);

            //------------------------------------------------------------
            // Get the CME or SGPE block of rings from .rings in HW image
            //------------------------------------------------------------
            if ( i_sysPhase == SYSPHASE_RT_CME )
            {
                FAPI_DBG("Getting the CME block of rings from HW image");

                l_rc = tor_get_block_of_rings( l_hwRingsSection,
                                               attrDdLevel,
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
                                               attrDdLevel,
                                               P9_TOR::SGPE,
                                               P9_TOR::ALLRING,
                                               BASE,
                                               0,
                                               &io_ringSectionBuf,
                                               io_ringSectionBufSize );
            }

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_TOR_GET_BLOCK_OF_RINGS_FAILED().
                         set_CHIP_TARGET(i_procTarget).
                         set_TOR_RC(l_rc).
                         set_SYSPHASE(i_sysPhase),
                         "tor_get_block_of_rings() failed w/rc=0x%08X",
                         (uint32_t)l_rc );

            FAPI_DBG("Size of .rings section before VPD update: %d", io_ringSectionBufSize);

            //----------------------------------------
            // Append VPD Rings to the .rings section
            //----------------------------------------

            l_fapiRc = fetch_and_insert_vpd_rings( i_procTarget,
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

            FAPI_DBG("-----------------------------------------------------------------------");
            FAPI_DBG("bootCoreMask: Requested=0x%08X Final=0x%08X",
                     l_requestedBootCoreMask, io_bootCoreMask);
            FAPI_DBG("-----------------------------------------------------------------------");

            if (l_fapiRc)
            {

                FAPI_ASSERT( (uint32_t)l_fapiRc != RC_XIPC_IMAGE_WOULD_OVERFLOW,
                             fapi2::XIPC_IMAGE_WOULD_OVERFLOW_BEFORE_REACHING_MIN_ECS().
                             set_CHIP_TARGET(i_procTarget).
                             set_REQUESTED_BOOT_CORE_MASK(l_requestedBootCoreMask).
                             set_CURRENT_BOOT_CORE_MASK(io_bootCoreMask),
                             "Ran out of space appending VPD rings to the .rings section" );

                fapi2::current_err = l_fapiRc;
                goto fapi_try_exit;

            }

            // More size code sanity checks of section and image sizes.
            FAPI_ASSERT( io_ringSectionBufSize <= l_maxRingSectionSize,
                         fapi2::XIPC_SECTION_SIZING().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_SECTION_SIZE(io_ringSectionBufSize).
                         set_MAX_RING_SECTION_SIZE(l_maxRingSectionSize),
                         "Code bug: ringSectionBufSize>maxRingSectionSize" );

            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::XIPC_INVALID_SYSPHASE_PARM().
                         set_CHIP_TARGET(i_procTarget).
                         set_SYSPHASE(i_sysPhase).
                         set_OCCURRENCE(1),
                         "Caller bug: Caller supplied unsupported value of sysPhase (=%d)",
                         i_sysPhase );

            break;
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
        io_imageSize = l_currentImageSize;
        FAPI_DBG("Final customized image size: %d", io_imageSize);
    }

    FAPI_DBG("Final customized .rings section size: %d", io_ringSectionBufSize);


fapi_try_exit:
    FAPI_DBG("Exiting p9_xip_customize");
    return fapi2::current_err;

}


