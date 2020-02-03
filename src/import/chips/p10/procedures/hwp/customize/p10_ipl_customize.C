/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_ipl_customize.C $ */
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
//
//  @file p10_ipl_customize.C
//
//  @brief Customize IPL images to be used by various PPEs
//
//  *HWP HWP Owner: Mike Olsen <cmolsen@us.ibm.com>
//  *HWP HWP Backup Owner: Sumit Kumar <sumit_kumar@in.ibm.com>
//  *HWP Team: Infrastructure
//  *HWP Level: 1
//  *HWP Consumed by: HOSTBOOT, CRONUS
//

#ifdef WIN32
    #include "win32_stdint.h"
    #include "endian.h"
    #include "win_sim_fapi.h"
#else
    #include <p10_get_mvpd_ring.H>
#endif

#include <p10_ipl_customize.H>
#include <p10_ipl_image.H>
#include <p10_ring_id.H>
#include <p10_tor.H>
#include <p10_scan_compression.H>
#include <p10_infrastruct_help.H>
#include <map>

using namespace fapi2;

#ifdef CHIP_GEN_P9
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
    P9XipItem l_item;

    MBOX_ATTR_WRITE (ATTR_SPI_BUS_DIV_REF,          i_procTarget,   i_image);
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
    MBOX_ATTR_WRITE (ATTR_PROC_EFF_FABRIC_GROUP_ID, i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EFF_FABRIC_CHIP_ID,  i_procTarget,   i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EPS_READ_CYCLES_T0,  FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EPS_READ_CYCLES_T1,  FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EPS_READ_CYCLES_T2,  FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EPS_WRITE_CYCLES_T1, FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_PROC_EPS_WRITE_CYCLES_T2, FAPI_SYSTEM,    i_image);
    MBOX_ATTR_WRITE (ATTR_LPC_CONSOLE_CNFG,        i_procTarget,   i_image);

    // for backwards compatiblity with images that don't contain
    // the OB/MC PLL bucket attributes, ensure that the item exists
    // prior to attempting an update which would otherwise fail
    if (!p9_xip_find(i_image, "ATTR_OB0_PLL_BUCKET", &l_item))
    {
        MBOX_ATTR_WRITE(ATTR_OB0_PLL_BUCKET, i_procTarget, i_image);
    }

    if (!p9_xip_find(i_image, "ATTR_OB1_PLL_BUCKET", &l_item))
    {
        MBOX_ATTR_WRITE(ATTR_OB1_PLL_BUCKET, i_procTarget, i_image);
    }

    if (!p9_xip_find(i_image, "ATTR_OB2_PLL_BUCKET", &l_item))
    {
        MBOX_ATTR_WRITE(ATTR_OB2_PLL_BUCKET, i_procTarget, i_image);
    }

    if (!p9_xip_find(i_image, "ATTR_OB3_PLL_BUCKET", &l_item))
    {
        MBOX_ATTR_WRITE(ATTR_OB3_PLL_BUCKET, i_procTarget, i_image);
    }

    if (!p9_xip_find(i_image, "ATTR_MC_PLL_BUCKET", &l_item))
    {
        MBOX_ATTR_WRITE(ATTR_MC_PLL_BUCKET, FAPI_SYSTEM, i_image);
    }

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
                     set_PG_INDEX(l_pg_idx).
                     set_IMG_PG_ENTRIES(IMG_PG_ENTRIES),
                     "Code bug: Invalid translation from PERV chip unit position"
                     " to image PG index: l_pg_idx=%d, IMG_PG_ENTRIES=%d",
                     l_pg_idx, IMG_PG_ENTRIES );

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
#endif // #ifdef CHIP_GEN_P9


// Function: get_overlays_ring()
// @brief: This function is used to get Gptr overlay ring from overlays section
//
// Parameter list:
// const fapi2::Target &i_target:    Processor chip target.
// void*     i_overlaysSection:  Pointer to extracted DD section in hw image
// uint8_t   i_ddLevel:          DD level (to be used for TOR API level verif)
// RingId_t  i_ringId:           GPTR ring id
// void*     io_ringBuf2:        Work buffer which contains RS4 overlay ring on return.
// void*     io_ringBuf3:        Work buffer which contains data+care raw overlay ring on return.
// uint32_t* o_ovlyUncmpSize     Uncompressed overlay ring size
#ifdef WIN32
int get_overlays_ring(
    int i_procTarget,
#else
fapi2::ReturnCode get_overlays_ring(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#endif
    void*     i_overlaysSection,
    uint8_t   i_ddLevel,
    RingId_t  i_ringId,
    void**    io_ringBuf2,
    void**    io_ringBuf3,
    uint32_t* o_ovlyUncmpSize)
{
    ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    int l_rc = INFRASTRUCT_RC_SUCCESS;
    uint32_t maxRingBufSize = MAX_RING_BUF_SIZE;
    uint32_t l_ovlyUncmpSize = 0;

    // As we'll be using tor_get_single_ring() with P9_XIP_MAGIC_SEEPROM
    // to identify TOR layout for overlays/overrides sections we have to define
    // following variables (though unused in this context) to support the API.
    uint8_t  l_chipletId = 0; // Unused param
    uint32_t l_ringBlockSize = 0xFFFFFFFF;  // Unused param

    FAPI_DBG("Entering get_overlays_ring");

    // Get Gptr overlay ring from overlays section into ringBuf2
    l_rc = tor_get_single_ring(
               i_overlaysSection,
               i_ddLevel,
               i_ringId,
               l_chipletId,
               io_ringBuf2,  //Has RS4 Gptr overlay ring on return
               l_ringBlockSize );

    if (l_rc == INFRASTRUCT_RC_SUCCESS)
    {
        FAPI_DBG("Successfully found Gptr ringId=0x%x of iv_size=%d bytes", i_ringId,
                 be16toh(((CompressedScanData*)(*io_ringBuf2))->iv_size));

        // Decompress Gptr overlay ring
        l_rc = _rs4_decompress(
                   (uint8_t*)(*io_ringBuf3),
                   (uint8_t*)(*io_ringBuf3) + maxRingBufSize / 2,
                   maxRingBufSize / 2, // Max allowable raw ring size (in bytes)
                   &l_ovlyUncmpSize,      // Actual raw ring size (in bits) on return.
                   (CompressedScanData*)(*io_ringBuf2) );

        FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                     fapi2::XIPC_RS4_DECOMPRESS_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_MAX_RING_BYTE_SIZE(maxRingBufSize).
                     set_LOCAL_RC(l_rc).
                     set_OCCURRENCE(2),
                     "_rs4_decompress() failed w/rc=%i for "
                     "ringId=0x%x, maxRingBufSize=%d, occurrence=2",
                     l_rc, i_ringId, maxRingBufSize );

        FAPI_DBG("Overlay raw ring size=%d bits", l_ovlyUncmpSize);

        // Copy the overlay ring's raw size
        *o_ovlyUncmpSize = l_ovlyUncmpSize;
    }
    else
    {
        FAPI_ASSERT( l_rc == TOR_RING_IS_EMPTY,
                     fapi2::XIPC_GPTR_GET_SINGLE_RING_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_CHIPLET_ID(0xff).
                     set_DD_LEVEL(i_ddLevel).
                     set_LOCAL_RC(l_rc).
                     set_OCCURRENCE(1),
                     "tor_get_single_ring() for gptr: Failed w/rc=%i for "
                     "ringId=0x%x, chipletId=0xff and ddLevel=0x%x",
                     l_rc, i_ringId, i_ddLevel );

        *io_ringBuf2 = NULL;
        *io_ringBuf3 = NULL;

        // Return success here if gptr rings not found as its not an error.
        // Not finding gptr rings is expected in most cases.
        FAPI_DBG("GPTR ring %d not found in overlays section", i_ringId);
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

fapi_try_exit:
    FAPI_DBG("Exiting get_overlays_ring");
    return fapi2::current_err;
}


// Function: apply_overlay_ring()
// @brief: This function overlays a raw ring from either the .dynamic or the .overlays ring
//         section onto an RS4 ring obtained from either the .{sbe,qme}.rings ring section
//         or the Mvpd #G record (Gptr rings specifically).
//
// Parameter list:
// const fapi2::Target &i_target:    Processor chip target.
// void*    io_rs4Ring:      Contains Base RS4 ring on input and final overlaid RS4 ring on output
// void*    io_workBuf:      Work buffer (has final overlaid raw ring on output)
// void*    i_ovlyRawRing:   Raw data+care overlay ring
// uint32_t i_ovlyRawSize:   Overlay raw ring size
// CompressedScanData* i_rs4RefRing:  Reference ring to get header data from (assumed volatile)
// uint8_t  i_rs4TypeField:  iv_type to be used for final RS4 ring
// _
// Assumption:
// - RS4 header's iv_selector will be set to UNDEFINED_RS4_SELECTOR
//
#ifdef WIN32
int apply_overlay_ring(
    int i_procTarget,
#else
fapi2::ReturnCode apply_overlay_ring(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#endif
    void*    io_rs4Ring,
    void*    io_workBuf,
    void*    i_ovlyRawRing,
    uint32_t i_ovlyRawSize,
    CompressedScanData*  i_rs4RefHeader,
    uint8_t  i_rs4TypeField)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    int l_rc = INFRASTRUCT_RC_SUCCESS;
    uint32_t maxRingBufSize = MAX_RING_BUF_SIZE;
    // Pt to our overlay raw buffers
    uint8_t* dataOvly = (uint8_t*)i_ovlyRawRing;
    uint8_t* careOvly = (uint8_t*)i_ovlyRawRing + maxRingBufSize / 2;
    // Pt to our Base/Final raw work buffers
    uint8_t* dataBase = (uint8_t*)io_workBuf;
    uint8_t* careBase = (uint8_t*)io_workBuf + maxRingBufSize / 2;
    uint32_t baseRawSize = 0;
    MyBool_t bOvrd = UNDEFINED_BOOLEAN;
    uint8_t  ivTypeTmp = 0;

    FAPI_DBG("Entering apply_overlay_ring");

    // Copy the key RS4 ref header settings into local struct before we, possibly,
    // contaminate i_rs4RefHeader as this may be pointing to one of our work
    // buffers.
    CompressedScanData l_rs4RefHeader;
    l_rs4RefHeader.iv_ringId = be16toh(i_rs4RefHeader->iv_ringId);
    l_rs4RefHeader.iv_scanAddr = be32toh(i_rs4RefHeader->iv_scanAddr);
    l_rs4RefHeader.iv_type = i_rs4RefHeader->iv_type;

    // Decompress the ring to apply overlay onto, io_rs4Ring.
    l_rc = _rs4_decompress(
               dataBase,
               careBase,
               maxRingBufSize / 2, // Max allowable raw ring size (in bytes)
               &baseRawSize,         // Actual raw ring size (in bits) on return.
               (CompressedScanData*)io_rs4Ring );

    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                 fapi2::XIPC_RS4_DECOMPRESS_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_RING_ID(l_rs4RefHeader.iv_ringId).
                 set_MAX_RING_BYTE_SIZE(maxRingBufSize).
                 set_LOCAL_RC(l_rc).
                 set_OCCURRENCE(3),
                 "_rs4_decompress() of Base ring failed w/rc=%i for ringId=0x%x,"
                 "maxRingBufSize=%d, occurrence=3",
                 l_rc, l_rs4RefHeader.iv_ringId, maxRingBufSize );

    // Compare raw Base and Overlay ring sizes
    FAPI_ASSERT( i_ovlyRawSize == baseRawSize,
                 fapi2::XIPC_BASE_OVLY_RAW_RING_SIZE_MISMATCH_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_BASE_SIZE(baseRawSize).
                 set_OVLY_SIZE(i_ovlyRawSize),
                 "Base raw size (=%d) and overlay raw size (=%d) don't match.",
                 baseRawSize, i_ovlyRawSize);

    FAPI_DBG("Base raw ring size=%d bits)", baseRawSize);

    //
    // Check ring override/flush type and then perform Overlay operation:
    // If overlay data is '1' and care is '1', set base data to '1' and care to '1'.
    // If overlay data is '0' and care is '1', set base data to '0' and:
    //     set care to '1' if ring is an override ring
    //     set care to '0' if ring is an flush ring (to save RS4 data string space)
    //
    bOvrd = rs4_is_ovrd(&l_rs4RefHeader, ivTypeTmp);

    FAPI_ASSERT( bOvrd != UNDEFINED_BOOLEAN,
                 fapi2::XIPC_RS4_TYPE_FIELD_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_RING_ID(l_rs4RefHeader.iv_ringId).
                 set_SCAN_ADDR(l_rs4RefHeader.iv_scanAddr).
                 set_TYPE_FIELD(ivTypeTmp).
                 set_OCCURRENCE(1),
                 "RS4 header iv_type field error: OVRD setting must be either true or "
                 "false but iv_type=0x%2x for ringId=0x%x, scanAddr=0x%8x, occurrence=1",
                 ivTypeTmp, l_rs4RefHeader.iv_ringId, l_rs4RefHeader.iv_scanAddr );

    uint32_t i, j;

    for (i = 0; i < baseRawSize / 8; i++)
    {
        if (careOvly[i] > 0)
        {
            for (j = 0; j < 8; j++)
            {
                if (careOvly[i] & (0x80 >> j))
                {
                    if ( dataOvly[i] & (0x80 >> j) )
                    {
                        dataBase[i] |= (0x80 >> j);
                        careBase[i] |= (0x80 >> j);
                    }
                    else
                    {
                        dataBase[i] &= ~(0x80 >> j);

                        if (bOvrd)
                        {
                            careBase[i] |= (0x80 >> j);
                        }
                        else
                        {
                            careBase[i] &= ~(0x80 >> j);
                        }
                    }
                }
            }
        }
    }

    // Processing remainder of data & care bits (mod 8)
    if (baseRawSize % 8)
    {
        i = baseRawSize / 8;

        careOvly[i] &= ~(0xFF << (8 - (baseRawSize % 8)));

        if (careOvly[i] > 0)
        {
            for (j = 0; j < baseRawSize % 8; j++)
            {
                if (careOvly[i] & (0x80 >> j))
                {
                    if ( dataOvly[i] & (0x80 >> j) )
                    {
                        dataBase[i] |= (0x80 >> j);
                        careBase[i] |= (0x80 >> j);
                    }
                    else
                    {
                        dataBase[i] &= ~(0x80 >> j);

                        if (bOvrd)
                        {
                            careBase[i] |= (0x80 >> j);
                        }
                        else
                        {
                            careBase[i] &= ~(0x80 >> j);
                        }
                    }
                }
            }
        }
    }

    // Recompress overlay ring
    l_rc = _rs4_compress(
               (CompressedScanData*)io_rs4Ring,
               maxRingBufSize,
               dataBase,
               careBase,
               baseRawSize,
               l_rs4RefHeader.iv_scanAddr,
               l_rs4RefHeader.iv_ringId,
               UNDEFINED_RS4_SELECTOR,
               i_rs4TypeField);

    FAPI_ASSERT( l_rc == 0,
                 fapi2::XIPC_RS4_COMPRESS_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_RING_ID(l_rs4RefHeader.iv_ringId).
                 set_SCAN_ADDR(l_rs4RefHeader.iv_scanAddr).
                 set_LOCAL_RC(l_rc).
                 set_OCCURRENCE(2),
                 "_rs4_compress() : Failed w/rc=%i for "
                 "ringId=0x%x, scanAddr=0x%8x, occurrence=2",
                 l_rc, l_rs4RefHeader.iv_ringId, l_rs4RefHeader.iv_scanAddr );

fapi_try_exit:
    FAPI_DBG("Exiting apply_overlay_ring");
    return fapi2::current_err;
}


// Function: process_gptr_rings()
// @brief: This function is used to check and process gptr rings.
//
// Parameter list:
// const fapi2::Target &i_target: Processor chip target.
// void*      i_overlaysSection:  Pointer to extracted DD section in hw image
// uint8_t    i_ddLevel:          DD level (to be used by TOR API level verif)
// void*      io_vpdRing:         Has Mvpd RS4 ring on input and final Vpd RS4 ring on output
// void*      io_ringBuf2:        Ring work buffer(used for RS4 overlay ring)
// void*      io_ringBuf3:        Ring work buffer(used for raw data+care overlay ring)
#ifdef WIN32
int process_gptr_rings(
    int i_procTarget,
#else
fapi2::ReturnCode process_gptr_rings(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#endif
    void*   i_overlaysSection,
    uint8_t i_ddLevel,
    void*   io_vpdRing,
    void*   io_ringBuf2,
    void*   io_ringBuf3)
{
    ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint32_t l_ovlyUncmpSize = 0;
    RingId_t l_vpdRingId   = (RingId_t)be16toh(((CompressedScanData*)io_vpdRing)->iv_ringId);
    uint32_t l_vpdScanAddr = be32toh(((CompressedScanData*)io_vpdRing)->iv_scanAddr);

    FAPI_DBG("process_gptr_rings(): Processing ringId=0x%x", l_vpdRingId);

    // Used for getting Gptr ring from overlays section
    void* l_ovlyRs4Ring = io_ringBuf2; //This content will be destroyed later in this function!
    void* l_ovlyRawRing = io_ringBuf3;

    FAPI_TRY( get_overlays_ring(
                  i_procTarget,
                  i_overlaysSection,
                  i_ddLevel,
                  l_vpdRingId,
                  &l_ovlyRs4Ring, // Has RS4 ring on return
                  &l_ovlyRawRing, // Has raw data+care ring on return
                  &l_ovlyUncmpSize),
              "get_overlays_ring() failed w/rc=0x%08x",
              (uint32_t)current_err );

    // Check whether both ovlyRs4/RawRing ring pointers match the original input buffer
    // pointers which would verify that an Gptr overlay ring was found
    if (l_ovlyRs4Ring == io_ringBuf2 && l_ovlyRawRing == io_ringBuf3)
    {
        // Check that RS4 headers of the Mvpd and overlay rings match
        FAPI_ASSERT( ( ((CompressedScanData*)io_vpdRing)->iv_ringId ==
                       ((CompressedScanData*)l_ovlyRs4Ring)->iv_ringId &&
                       ((CompressedScanData*)io_vpdRing)->iv_scanAddr ==
                       ((CompressedScanData*)l_ovlyRs4Ring)->iv_scanAddr ),
                     fapi2::XIPC_MVPD_OVLY_RING_HEADER_MISMATCH_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_MVPD_RING_ID(l_vpdRingId).
                     set_OVLY_RING_ID(be16toh(((CompressedScanData*)l_ovlyRs4Ring)->iv_ringId)).
                     set_MVPD_SCAN_ADDR(l_vpdScanAddr).
                     set_OVLY_SCAN_ADDR(be32toh(((CompressedScanData*)l_ovlyRs4Ring)->iv_scanAddr)),
                     "MVPD and Ovly RS4 headers don't match:\n"
                     " Mvpd ringId: 0x%x\n"
                     " Ovly ringId: 0x%x\n"
                     " Mvpd scanAddr: 0x%08x\n"
                     " Ovly scanAddr: 0x%08x",
                     l_vpdRingId,
                     be16toh(((CompressedScanData*)l_ovlyRs4Ring)->iv_ringId),
                     l_vpdScanAddr,
                     be32toh(((CompressedScanData*)l_ovlyRs4Ring)->iv_scanAddr) );

        // Do overlay operation
        FAPI_TRY( apply_overlay_ring(
                      i_procTarget,
                      io_vpdRing,
                      io_ringBuf2, //We can now destroy ovlyRs4Ring
                      l_ovlyRawRing,
                      l_ovlyUncmpSize,
                      (CompressedScanData*)l_ovlyRs4Ring, //Ovly ring is more trustworthy for ref
                      ((CompressedScanData*)l_ovlyRs4Ring)->iv_type ),
                  "apply_overlay_ring() failed w/rc=0x%08x for ringId=0x%x",
                  (uint32_t)current_err, be16toh(((CompressedScanData*)l_ovlyRs4Ring)->iv_ringId));
    }
    else
    {
        // Next, we check that the overlay buffer pointers are NULL which verifies that
        // no overlay ring was found. This is normal and is NOT an error.  However, if
        // the overlay buffer pointers neither match the original input work buffers
        // (which they don't if we here in this spot)  AND if they are not NULL either,
        // then that is a code bug error case.
        FAPI_ASSERT( (l_ovlyRs4Ring == NULL && l_ovlyRawRing == NULL),
                     fapi2::XIPC_OVLY_RING_BUFFER_MISMATCH_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(l_vpdRingId).
                     set_RING_BUF2(io_ringBuf2).
                     set_RING_BUF2_LOCAL(l_ovlyRs4Ring).
                     set_RING_BUF3(io_ringBuf3).
                     set_RING_BUF3_LOCAL(l_ovlyRawRing),
                     "process_gptr_rings(): Code bug: Failed with ring buffer pointer mismatch");

        // Return success
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

fapi_try_exit:
    FAPI_DBG("Exiting process_gptr_rings");
    return fapi2::current_err;
}

//  Function: _fetch_and_insert_vpd_rings()
//  This function is used to fetch and insert a single ring(common/instance)
//
//  Parameter list:
//  const fapi::Target &i_target:    Processor chip target.
//  void*      i_ringSection:        Ptr to ring section.
//  uint32_t&  io_ringSectionSize:   Running ring section size
//  uint32_t   i_maxRingSectionSize: Max ring section size
//  void*      i_overlaysSection:    DD specific overlays ring section
//  uint8_t    i_ddLevel:            DD level (to be used for TOR API level verif)
//  uint8_t    i_sysPhase:           ={HB_SBE, RT_QME}
//  void*      i_vpdRing:            VPD ring buffer.
//  uint32_t   i_vpdRingSize:        Size of VPD ring buffer.
//  void*      i_ringBuf2:           Ring work buffer.
//  uint32_t   i_ringBufSize2:       Size of ring work buffer.
//  void*      i_ringBuf3:           Ring work buffer.
//  uint32_t   i_ringBufSize3:       Size of ring work buffer.
//  RingProperties_t* i_ringProps:   Ptr to main ring properties list
//  RingId_t   i_ringId:             Ring ID
//  uint32_t   i_chipletSel:         Chiplet Select (chipletId + quad region select)
//  uint8_t&   io_ringStatusInMvpd:  EQ/EC ring status - found/notfound/redundant in mvpd
//  bool       i_bImgOutOfSpace:     Flag to indicate image space overflow
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
    void*           i_overlaysSection,
    uint8_t         i_ddLevel,
    uint8_t         i_sysPhase,
    void*           i_vpdRing,
    uint32_t        i_vpdRingSize,
    void*           i_ringBuf2,
    uint32_t        i_ringBufSize2,
    void*           i_ringBuf3,
    uint32_t        i_ringBufSize3,
    RingProperties_t* i_ringProps,
    RingId_t        i_ringId,
    uint32_t        i_chipletSel,
    uint8_t&        io_ringStatusInMvpd,
    bool&           i_bImgOutOfSpace,
    uint32_t&       io_bootCoreMask )
{
    ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err  = fapi2::FAPI2_RC_SUCCESS;
    int        l_rc = INFRASTRUCT_RC_SUCCESS;;

    FAPI_DBG("_fetch_and_insert_vpd_ring: (ringId,chipletSel) = (0x%x,0x%08x)",
             i_ringId, i_chipletSel);

    uint32_t     l_vpdRingSize = i_vpdRingSize;
    MvpdKeyword  l_mvpdKeyword;
    uint8_t      l_chipletId = (uint8_t)(i_chipletSel >> 24);

    RingClass_t l_ringClass = i_ringProps[i_ringId].ringClass;

    switch (l_ringClass & RCLS_MVPD_MASK)
    {
        case RMRK_MVPD_PDG: // #G Time rings
            l_mvpdKeyword = fapi2::MVPD_KEYWORD_PDG;
            break;

        case RMRK_MVPD_PDP: // #P Pll rings
            l_mvpdKeyword = fapi2::MVPD_KEYWORD_PDP;
            break;

        case RMRK_MVPD_PDR: // #R Repair rings
            l_mvpdKeyword = fapi2::MVPD_KEYWORD_PDR;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::XIPC_INVALID_MVPD_RINGCLASS().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_ID(i_ringId).
                         set_RING_CLASS(l_ringClass).
                         set_KWD_MASK(RCLS_MVPD_MASK),
                         "Code bug: Unsupported value of ringClass (=0x%4x) or keyword"
                         " mask (=0x%4x) for ringId=0x%x",
                         l_ringClass, RCLS_MVPD_MASK, i_ringId );
            break;
    }

    // Initialize data buffers to zeros
    memset(i_vpdRing,  0, i_vpdRingSize);
    memset(i_ringBuf2, 0, i_ringBufSize2);
    memset(i_ringBuf3, 0, i_ringBufSize3);

    /////////////////////////////////////////////////////////////////////
    // Fetch ring from the MVPD:
    /////////////////////////////////////////////////////////////////////
    l_fapiRc = getMvpdRing( i_procTarget,
                            MVPD_RECORD_CP00,
                            l_mvpdKeyword,
                            i_chipletSel,
                            i_ringId,
                            (uint8_t*)i_vpdRing,
                            l_vpdRingSize );

    ///////////////////////////////////////////////////////////////////////
    // Append VPD ring to the ring section
    ///////////////////////////////////////////////////////////////////////

    if (l_fapiRc == fapi2::FAPI2_RC_SUCCESS)
    {
        // Update for ring found in mvpd
        io_ringStatusInMvpd = RING_FOUND;

        uint32_t l_scanAddr = be32toh(((CompressedScanData*)i_vpdRing)->iv_scanAddr);
        uint32_t vpdChipletSel;

        // Even though success, check chipletSel didn't somehow get messed up (code bug).
        if ( (i_chipletSel & EQ_QUADRANT_MASK) == 0 )
        {
            // Everything else except a core instance ring
            vpdChipletSel = l_scanAddr & CHIPLET_ID_MASK;
        }
        else
        {
            // A core instance ring
            vpdChipletSel = l_scanAddr & (CHIPLET_ID_MASK | EQ_QUADRANT_MASK);
        }

        FAPI_ASSERT( vpdChipletSel == i_chipletSel,
                     fapi2::XIPC_MVPD_CHIPLET_ID_MESS().
                     set_CHIP_TARGET(i_procTarget).
                     set_CHIPLET_SEL(i_chipletSel).
                     set_MVPD_CHIPLET_SEL(vpdChipletSel).
                     set_RING_ID(i_ringId),
                     "_fetch_and_insert_vpd_ring: Code bug: VPD ring's chipletSel"
                     " (=0x%08x) doesn't match the requested chipletSel (=0x%08x)",
                     vpdChipletSel, i_chipletSel );

        // Even though success, check for accidental buffer overflow (code bug).
        FAPI_ASSERT( l_vpdRingSize <= i_vpdRingSize,
                     fapi2::XIPC_MVPD_RING_SIZE_MESS().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_CHIPLET_ID(l_chipletId).
                     set_RING_BUFFER_SIZE(i_vpdRingSize).
                     set_MVPD_RING_SIZE(l_vpdRingSize),
                     "_fetch_and_insert_vpd_ring: Code bug: VPD ring size (=0x%X) exceeds"
                     " allowed ring buffer size (=0x%X)",
                     l_vpdRingSize, i_vpdRingSize );

        // Check for ovly-Gptr rings in overlays section and if found
        // process it over Mvpd-Gptr ring.
        if ( l_ringClass & RMRK_GPTR_OVLY )
        {
            FAPI_TRY( process_gptr_rings(
                          i_procTarget,
                          i_overlaysSection,
                          i_ddLevel,
                          i_vpdRing,
                          i_ringBuf2,
                          i_ringBuf3),
                      "process_gptr_rings() failed w/rc=0x%08x",
                      (uint32_t)current_err );

            // Update vpdRingSize to new value if any
            l_vpdRingSize = be16toh(((CompressedScanData*)i_vpdRing)->iv_size);
        }

        // Initialize variable to check for redundant ring.
        int redundant = 0;

        l_rc = rs4_redundant((CompressedScanData*)i_vpdRing, &redundant);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_RS4_REDUNDANT_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_CHIPLET_ID(l_chipletId).
                     set_LOCAL_RC(l_rc).
                     set_OCCURRENCE(1),
                     "rs4_redundant: Failed w/rc=%i for "
                     "ringId=0x%x, chipletId=0x%02x, occurrence=1 ",
                     l_rc, i_ringId, l_chipletId );

        // Regarding Gptr rings processing:
        // At this stage i_vpdRing (mvpd-gptr) has already been processed w/wo ovly-gptr,
        // so now newly modified(if any) i_vpdRing could be check for redundancy
        // like any other non-gptr rings.
        if (redundant)
        {
            // Update for ring found in mvpd contains redundant data
            io_ringStatusInMvpd = RING_REDUNDANT;

            FAPI_DBG("Skipping redundant VPD ring: ringId=0x%x, chipletId=0x%02x ",
                     i_ringId, l_chipletId);
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
                         set_RING_ID(i_ringId).
                         set_CHIPLET_ID(l_chipletId).
                         set_CURRENT_BOOT_CORE_MASK(io_bootCoreMask),
                         "Ran out of image buffer space trying to append a ring"
                         " to the .rings section\n"
                         "ringId: 0x%x\n"
                         "chipletId: 0x%x\n"
                         "vpdRingSize: %d\n"
                         "ringSectionSize: %d\n"
                         "maxRingSectionSize: %d\n"
                         "Current bootCoreMask: 0x%08x",
                         i_ringId,
                         l_chipletId,
                         l_vpdRingSize,
                         io_ringSectionSize,
                         i_maxRingSectionSize,
                         io_bootCoreMask );
        }

        //------------------------------------------
        // Now, append the ring to the ring section
        //------------------------------------------

        l_rc = tor_append_ring(
                   i_ringSection,
                   i_maxRingSectionSize,
                   i_ringId,
                   l_chipletId,
                   i_vpdRing );

        FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                     fapi2::XIPC_TOR_APPEND_RING_FAILED().
                     set_CHIP_TARGET(i_procTarget).
                     set_TOR_RC(l_rc).
                     set_RING_ID(i_ringId).
                     set_OCCURRENCE(1),
                     "tor_append_ring() failed in sysPhase=%d w/rc=%d for ringId=0x%x",
                     i_sysPhase, l_rc, i_ringId );

        io_ringSectionSize = be32toh(((TorHeader_t*)i_ringSection)->size);

        FAPI_IMP("Successfully appended VPD ring, (ringId,chipletId)=(0x%x,0x%02x), and"
                 " now ringSectionSize=%u",
                 i_ringId, l_chipletId, io_ringSectionSize);
    }
    else if ((uint32_t)l_fapiRc == RC_MVPD_RING_NOT_FOUND)
    {
        // Update for ring not found in mvpd
        io_ringStatusInMvpd = RING_NOT_FOUND;

        // No match, do nothing. But since rare, trace out as warning since all
        // rings we're looking for in Mvpd really should be represented there.
        FAPI_DBG("WARNING!: _fetch_and_insert_vpd_rings(): The ring w/"
                 "(ringId,chipletId)=(0x%x,0x%02x) was not found. (This is not a bug)",
                 i_ringId, l_chipletId);

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
                     set_RING_ID(i_ringId).
                     set_CHIPLET_ID(l_chipletId).
                     set_RING_BUFFER_SIZE(i_vpdRingSize).
                     set_MVPD_RING_SIZE(l_vpdRingSize),
                     "_fetch_and_insert_vpd_ring(): VPD ring size (=0x%X) exceeds"
                     " allowed ring buffer size (=0x%X)",
                     l_vpdRingSize, i_vpdRingSize );

        // getMvpdRing failed for some other reason aside from above handled cases.
        if (l_fapiRc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("_fetch_and_insert_vpd_ring(): getMvpdRing failed w/rc=0x%08X",
                     (uint64_t)l_fapiRc);
            fapi2::current_err = l_fapiRc;
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting _fetch_and_insert_vpd_ring");
    return fapi2::current_err;

} // End of  _fetch_and_insert_vpd_rings()


//  Function: resolve_gptr_overlays()
//
//  Parameter list:
//  const fapi::Target &i_target:    Processor chip target.
//  void*      i_hwImage:            Ptr to ring section.
//  void**     o_overlaysSection:    Ptr to extracted overlay DD section in hwImage.
//  uint8_t&   o_ddLevel:            DD level extracted from host services.
#ifdef WIN32
int resolve_gptr_overlays(
    int i_procTarget,
#else
fapi2::ReturnCode resolve_gptr_overlays(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#endif
    void*    i_hwImage,
    void**   o_overlaysSection,
    uint8_t& o_ddLevel )
{

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    P9XipSection l_xipSection;
    int      l_rc = INFRASTRUCT_RC_SUCCESS;

    FAPI_DBG("Entering resolve_gptr_overlays");

    // Get the Overlays dd level
    FAPI_TRY( FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC,
                                       i_procTarget,
                                       o_ddLevel),
              "ERROR: Attribute ATTR_EC failed w/rc=0x%08x",
              (uint64_t)current_err );

    l_rc = p9_xip_get_section(i_hwImage, P9_XIP_SECTION_HW_OVERLAYS, &l_xipSection, o_ddLevel);

    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                 fapi2::XIPC_XIP_GET_SECTION_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_XIP_RC(l_rc).
                 set_SECTION_ID(P9_XIP_SECTION_HW_OVERLAYS).
                 set_DDLEVEL(o_ddLevel).
                 set_OCCURRENCE(5),
                 "p9_xip_get_section() failed (5) w/rc=0x%08X getting .overlays"
                 " section for ddLevel=0x%x",
                 (uint32_t)l_rc, o_ddLevel );

    *o_overlaysSection = (void*)((uint8_t*)i_hwImage + l_xipSection.iv_offset);
    FAPI_DBG("GPTR support available in overlays for ddLevel=0x%x "
             "located at addr=0x%08x (hwImage=0x%08x)",
             o_ddLevel, *(uint32_t*)o_overlaysSection, *(uint32_t*)i_hwImage);

fapi_try_exit:
    FAPI_DBG("Exiting resolve_gptr_overlays");
    return fapi2::current_err;
}


//  Function: fetch_and_insert_vpd_rings()
//
//  Parameter list:
//  const fapi::Target &i_target:    Processor chip target.
//  void*      i_ringSection:        Ptr to ring section.
//  uint32_t&  io_ringSectionSize:   Running size
//  uint32_t   i_maxRingSectionSize: Max size
//  void*      i_hwImage:            HW image
//  uint8_t    i_sysPhase:           ={IPL, RT_QME}
//  void*      i_vpdRing:            VPD ring buffer.
//  uint32_t   i_vpdRingSize:        Size of VPD ring buffer.
//  void*      i_ringBuf2:           Ring work buffer.
//  uint32_t   i_ringBufSize2:       Size of ring work buffer.
//  void*      i_ringBuf3:           Ring work buffer.
//  uint32_t   i_ringBufSize3:       Size of ring work buffer.
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
    void*           i_hwImage,
    uint8_t         i_sysPhase,
    void*           i_vpdRing,
    uint32_t        i_vpdRingSize,
    void*           i_ringBuf2,
    uint32_t        i_ringBufSize2,
    void*           i_ringBuf3,
    uint32_t        i_ringBufSize3,
    uint32_t&       io_bootCoreMask )
{

    ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err  = fapi2::FAPI2_RC_SUCCESS;
    int l_rc = INFRASTRUCT_RC_SUCCESS;

    // Variables needed to provide updated bootCoreMask
    uint8_t eq, ec, quadrant; // Index vars for counting EQ, core and EQ instances and regions
    VpdInsInsertProg_t l_instanceVpdRing  = {};
    uint8_t l_ringStatusInMvpd            = RING_SCAN;
    bool    l_bImgOutOfSpace              = false;
    uint8_t l_eqNumWhenOutOfSpace         = 0xF;   // Assign invalid value to check for correctness of value when used
    RingType_t l_ringType = 0xff; // 0:COMMON, 1:INSTANCE

    // Initialize activeCoreMask to be filled up with EC column filling as it progresses
    uint32_t l_activeCoreMask  = 0x0;
    uint32_t l_bootCoreMaskMin = 0x0;
    void*    l_overlaysSection;
    uint8_t  l_ddLevel = UNDEFINED_DD_LEVEL;

    TorHeader_t* torHeader  = (TorHeader_t*)i_ringSection;
    uint32_t     torMagic = be32toh(torHeader->magic);
    uint8_t      torVersion = torHeader->version;

    FAPI_DBG("Entering fetch_and_insert_vpd_rings");

    FAPI_TRY( resolve_gptr_overlays( i_procTarget,
                                     i_hwImage,
                                     &l_overlaysSection,
                                     l_ddLevel ),
              "resolve_gptr_overlays() failed w/rc=0x%08x",
              (uint32_t)current_err );


    // Walk through all Vpd rings and add any that's there to the image.
    // Do this in two steps:
    // 1- Add all NEST rings
    // 2- Add QUAD rings in EC order

    RingId_t          l_ringId;
    RingClass_t       l_ringClass;
    RingProperties_t* l_ringProps;
    ChipletData_t*    l_chipletData;
    ChipletData_t*    l_chipletDataEQ, *l_chipletDataEC;
    uint8_t           l_chipletId;  // Nibbles {0,1} of scanScomAddr
    uint32_t          l_regionSel;  // Nibbles {2,4,5,6} of scanScomAddr (region select target)
    uint32_t          l_chipletSel; // Combination of chipletId and regionSel

    l_rc = ringid_get_ringProps( CID_P10, &l_ringProps);

    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                 fapi2::XIPC_RINGID_RINGPROPS_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_LOCAL_RC(l_rc).
                 set_OCCURRENCE(1),
                 "ringid_get_ringProps(): Failed w/rc=%i for occurrence=1",
                 l_rc );


    // ----------------------------------------------------
    // 1- Add all common rings (ie, non-EQ/core repr rings)
    // ----------------------------------------------------
    l_ringType = COMMON_RING;

    for ( l_ringId = 0; l_ringId < NUM_RING_IDS; l_ringId++ )
    {

        l_ringClass = l_ringProps[l_ringId].ringClass;

        if ( ( l_ringClass != UNDEFINED_RING_CLASS )  &&
             ( l_ringClass & RCLS_MVPD_MASK )  &&
             ( (l_ringClass & RCLS_MVPD_PDR_EQ) != RCLS_MVPD_PDR_EQ )  &&
             ( (l_ringClass & RCLS_MVPD_PDR_CORE) != RCLS_MVPD_PDR_CORE ) )
        {
            l_rc = ringid_get_chipletProps( CID_P10,
                                            torMagic,
                                            torVersion,
                                            l_ringProps[l_ringId].chipletType,
                                            &l_chipletData );

            FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                         fapi2::XIPC_RINGID_CHIPLETPROPS_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_LOCAL_RC(l_rc).
                         set_TOR_MAGIC(torMagic).
                         set_TOR_VER(torVersion).
                         set_CHIPLET_TYPE(l_ringProps[l_ringId].chipletType).
                         set_RING_ID(l_ringId).
                         set_OCCURRENCE(1),
                         "ringid_get_chipletProps(): Failed w/rc=%i for"
                         " TOR magic = 0x%04x, TOR version = %d,"
                         " chipletType = %d, ringId = 0x%x,"
                         " occurrence=1",
                         l_rc, torMagic, torVersion,
                         l_ringProps[l_ringId].chipletType,
                         l_ringId );

            l_chipletId = l_chipletData->chipletBaseId;
            l_chipletSel = ((uint32_t)l_chipletId) << 24;

            // Fetch COMMON rings (i.e., non repair rings)
            // - Fetch all VPD rings for SBE.
            // - Fetch QME scannable VPD rings for QME.

            if ( i_sysPhase == SYSPHASE_HB_SBE   ||
                 ( i_sysPhase == SYSPHASE_RT_QME && ( l_ringClass & RMRK_SCAN_BY_QME ) ) )
            {
                l_fapiRc = _fetch_and_insert_vpd_rings (
                               i_procTarget,
                               i_ringSection,
                               io_ringSectionSize,
                               i_maxRingSectionSize,
                               l_overlaysSection,
                               l_ddLevel,
                               i_sysPhase,
                               i_vpdRing,
                               i_vpdRingSize,
                               i_ringBuf2,
                               i_ringBufSize2,
                               i_ringBuf3,
                               i_ringBufSize3,
                               l_ringProps,
                               l_ringId,
                               l_chipletSel,
                               l_ringStatusInMvpd,
                               l_bImgOutOfSpace,
                               io_bootCoreMask );

                if (   (uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW ||
                       ( (uint32_t)l_fapiRc != RC_MVPD_RING_REDUNDANT_DATA &&
                         l_fapiRc != fapi2::FAPI2_RC_SUCCESS ) )
                {
                    fapi2::current_err = l_fapiRc;
                    FAPI_ERR("_fetch_and_insert_vpd_rings() failed inserting VPD Common rings w/rc=0x%.8x",
                             (uint64_t)fapi2::current_err );
                    goto fapi_try_exit;
                }

                FAPI_DBG("(CMN) io_ringSectionSize = %d", io_ringSectionSize);
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }
    }

    // --------------------------------------------------
    // 2- Add all instance rings (ie, EQ/core repr rings)
    // --------------------------------------------------
    l_ringType = INSTANCE_RING;

    // Add all instance [QUAD-level] rings in order - EQ->EC.
    // Looking at the bootCoreMask start adding EQ first followed
    // by EC VPD ring insertion in order.
    // For common rings already completed in above step #1.
    // The step #2 instance part is updated looping over chipletId
    // to fill up one core chipletId "column" at a time (RTC158106).

    // Loop for EQ/EC filling
    for (eq = 0; eq < NUM_OF_QMES; eq++)
    {

        // Make sure one of the current eq's cores is included in the requested bootCoreMask
        if ( !( ( (QUAD0_CORES_MASK) >> (eq * CORES_PER_QME) ) & io_bootCoreMask ) )
        {
            // No cores from current eq are included in bootCoreMask. Skip to next eq.
            continue;
        }

        for ( l_ringId = 0; l_ringId < NUM_RING_IDS; l_ringId++ )
        {

            //
            // Determine if ringId belongs to relevant Mvpd #R EQ ringClass. If so,
            // then try fetch the ring from Mvpd and append it to ring section.
            // In principle, Since only the SBE can scan QME ring, e.g. eq_xyz_ring,
            // we could limit the ring search to just the HB_SBE phase. But to be
            // consistent, and in case for some reason suddenly the QME is able to
            // "scan itself", we consider the RT_QME phase here as well.
            //
            l_ringClass = l_ringProps[l_ringId].ringClass;

            if ( ( l_ringClass != UNDEFINED_RING_CLASS )  &&
                 ( (l_ringClass & RCLS_MVPD_PDR_EQ) == RCLS_MVPD_PDR_EQ )  &&
                 ( i_sysPhase == SYSPHASE_HB_SBE  ||
                   ( i_sysPhase == SYSPHASE_RT_QME && (l_ringClass & RMRK_SCAN_BY_QME) ) ) )
            {
                l_rc = ringid_get_chipletProps(
                           CID_P10,
                           torMagic,
                           torVersion,
                           l_ringProps[l_ringId].chipletType,
                           &l_chipletDataEQ );

                FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                             fapi2::XIPC_RINGID_CHIPLETPROPS_ERROR().
                             set_CHIP_TARGET(i_procTarget).
                             set_LOCAL_RC(l_rc).
                             set_TOR_MAGIC(torMagic).
                             set_TOR_VER(torVersion).
                             set_CHIPLET_TYPE(l_ringProps[l_ringId].chipletType).
                             set_RING_ID(l_ringId).
                             set_OCCURRENCE(2),
                             "ringid_get_chipletProps(): Failed w/rc=%i for"
                             " TOR magic = 0x%04x, TOR version = %d,"
                             " chipletType = %d, ringId = 0x%x,"
                             " occurrence=2",
                             l_rc, torMagic, torVersion,
                             l_ringProps[l_ringId].chipletType,
                             l_ringId );

                l_chipletId = l_chipletDataEQ->chipletBaseId + eq;
                l_chipletSel = ((uint32_t)l_chipletId) << 24;

                FAPI_DBG("EQ=%d; chipletId=0x%02x, ringName:%s",
                         eq, l_chipletId, l_ringProps[l_ringId].ringName);

                // Update for ring in scan mode
                l_ringStatusInMvpd = RING_SCAN;

                l_fapiRc = _fetch_and_insert_vpd_rings (
                               i_procTarget,
                               i_ringSection,
                               io_ringSectionSize,
                               i_maxRingSectionSize,
                               l_overlaysSection,
                               l_ddLevel,
                               i_sysPhase,
                               i_vpdRing,
                               i_vpdRingSize,
                               i_ringBuf2,
                               i_ringBufSize2,
                               i_ringBuf3,
                               i_ringBufSize3,
                               l_ringProps,
                               l_ringId,
                               l_chipletSel,
                               l_ringStatusInMvpd,
                               l_bImgOutOfSpace,
                               io_bootCoreMask );

                // Update EQ instance var for ring found in mvpd
                if (l_ringStatusInMvpd == RING_FOUND)
                {
                    l_instanceVpdRing.EQ |= ((QUAD0_CORES_MASK) >> (eq * CORES_PER_QME));
                }

                if ((uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW)
                {
                    // Capture EQ number when image ran out-of-space while appending ring
                    l_eqNumWhenOutOfSpace = eq;

                    // Capture current state of chiplet under process
                    l_instanceVpdRing.chipletUnderProcess    = EQ_CHIPLET;
                    l_instanceVpdRing.instanceNumUnderProcess = eq;
                }
                else if ( (uint32_t)l_fapiRc != RC_MVPD_RING_REDUNDANT_DATA &&
                          l_fapiRc != fapi2::FAPI2_RC_SUCCESS )
                {
                    fapi2::current_err = l_fapiRc;
                    FAPI_ERR("_fetch_and_insert_vpd_rings() failed inserting VPD EQ Instance rings w/rc=0x%.8x",
                             (uint64_t)fapi2::current_err );
                    goto fapi_try_exit;
                }

                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

            } // Done w/fetch_and_insert() current EQ instance ring

        } // End of for(l_ringId) for the current eq

        //
        // At this point, we're done appending all possible EQ Mvpd rings for current eq.
        // Next, we fill the [four] cores with EC Mvpd rings, filling one core/quadrant
        // at a time.
        //
        for (quadrant = 0; quadrant < CORES_PER_QME; quadrant++)
        {

            ec = eq * CORES_PER_QME + quadrant;

            // Make sure the current ec core is included in the requested bootCoreMask
            if ( !( ((CORE0_MASK) >> ec) & io_bootCoreMask ) )
            {
                continue;
            }

            for ( l_ringId = 0; l_ringId < NUM_RING_IDS; l_ringId++ )
            {

                //
                // Determine if ringId belongs to relevant Mvpd #R EC ringClass. If so,
                // then try fetch the ring from Mvpd and append it to ring section.
                //
                l_ringClass = l_ringProps[l_ringId].ringClass;

                if ( ( l_ringClass != UNDEFINED_RING_CLASS )  &&
                     ( (l_ringClass & RCLS_MVPD_PDR_CORE) == RCLS_MVPD_PDR_CORE )  &&
                     ( i_sysPhase == SYSPHASE_HB_SBE  ||
                       ( i_sysPhase == SYSPHASE_RT_QME && (l_ringClass & RMRK_SCAN_BY_QME) ) ) )
                {
                    l_rc = ringid_get_chipletProps(
                               CID_P10,
                               torMagic,
                               torVersion,
                               l_ringProps[l_ringId].chipletType,
                               &l_chipletDataEC );

                    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                                 fapi2::XIPC_RINGID_CHIPLETPROPS_ERROR().
                                 set_CHIP_TARGET(i_procTarget).
                                 set_LOCAL_RC(l_rc).
                                 set_TOR_MAGIC(torMagic).
                                 set_TOR_VER(torVersion).
                                 set_CHIPLET_TYPE(l_ringProps[l_ringId].chipletType).
                                 set_RING_ID(l_ringId).
                                 set_OCCURRENCE(3),
                                 "ringid_get_chipletProps(): Failed w/rc=%i for"
                                 " TOR magic = 0x%04x, TOR version = %d,"
                                 " chipletType = %d, ringId = 0x%x,"
                                 " occurrence=3",
                                 l_rc, torMagic, torVersion,
                                 l_ringProps[l_ringId].chipletType,
                                 l_ringId );

                    //
                    // Calculate chipletSel target "ID" for this particular (eq,quadrant) combo
                    // **NOTE** The assumption here is that the three repair rings being
                    // processed here do not have overlapping region/core bits. (See the *.H
                    // file for more info about the EQ_QUADRANT0_SEL and EQ_QUADRANT_MASK)
                    //
                    l_chipletId = l_chipletDataEC->chipletBaseId + eq;
                    // For the region/core select bits, first set the three repair rings' possible
                    // target bits based on the current quadrant we're processing
                    l_regionSel = EQ_QUADRANT0_SEL >> quadrant;
                    // ...then narrow in on the particular rings region/core bit, which is set
                    // in the scanScomAddr, and see if it matches the current quadrant we're in:
                    // - If there's a match, regionSel will have one bit set,
                    // - If there's no match, regionSel will be zero.
                    l_regionSel = l_ringProps[l_ringId].scanScomAddr & l_regionSel;
                    // Final chipletSel to look for in Mvpd
                    l_chipletSel = ( (uint32_t)l_chipletId << 24 ) | l_regionSel;

                    // Find out, before attempting Mvpd fetch, if regionSel target even selects
                    // the region core select bit of scanScomAddr of the current ringId
                    if ( !l_regionSel )
                    {
                        // Region select target does not select region select bit of current
                        // ringIds scanScomAddr.  Proceed to the next ringId.
                        FAPI_DBG("EC=%d: chipletSel=0x%08x, ringName=%s (Skipping this ring"
                                 " because we're in wrong quadrant(=%d))",
                                 ec, l_chipletSel, l_ringProps[l_ringId].ringName, quadrant);
                        continue;
                    }

                    FAPI_DBG("EC=%d: chipletSel=0x%08x, ringName=%s",
                             ec, l_chipletSel, l_ringProps[l_ringId].ringName);

                    // Update for ring in scan mode
                    l_ringStatusInMvpd = RING_SCAN;

                    l_fapiRc = _fetch_and_insert_vpd_rings (
                                   i_procTarget,
                                   i_ringSection,
                                   io_ringSectionSize,
                                   i_maxRingSectionSize,
                                   l_overlaysSection,
                                   l_ddLevel,
                                   i_sysPhase,
                                   i_vpdRing,
                                   i_vpdRingSize,
                                   i_ringBuf2,
                                   i_ringBufSize2,
                                   i_ringBuf3,
                                   i_ringBufSize3,
                                   l_ringProps,
                                   l_ringId,
                                   l_chipletSel,
                                   l_ringStatusInMvpd,
                                   l_bImgOutOfSpace,
                                   io_bootCoreMask );

                    // Update EC instance var for ring found in mvpd
                    if (l_ringStatusInMvpd == RING_FOUND)
                    {
                        l_instanceVpdRing.EC |= (CORE0_MASK) >> ec;
                    }

                    if ((uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW)
                    {
                        // Capture EQ number when image ran out-of-space while appending ring
                        l_eqNumWhenOutOfSpace = eq;

                        // Capture current state of chiplet under process
                        l_instanceVpdRing.chipletUnderProcess    = EC_CHIPLET;
                        l_instanceVpdRing.instanceNumUnderProcess = ec;
                    }
                    else if ( (uint32_t)l_fapiRc != RC_MVPD_RING_REDUNDANT_DATA &&
                              l_fapiRc != fapi2::FAPI2_RC_SUCCESS )
                    {
                        fapi2::current_err = l_fapiRc;
                        FAPI_ERR("_fetch_and_insert_vpd_rings() failed inserting VPD EC Instance rings w/rc=0x%.8x",
                                 (uint64_t)fapi2::current_err );
                        goto fapi_try_exit;
                    }
                    else if ( ( l_fapiRc == fapi2::FAPI2_RC_SUCCESS     ||
                                (uint32_t)l_fapiRc == RC_MVPD_RING_REDUNDANT_DATA ||
                                (uint32_t)l_fapiRc == RC_MVPD_RING_NOT_FOUND ) &&
                              l_bImgOutOfSpace == false )
                    {
                        FAPI_DBG("(INS) io_ringSectionSize = %d", io_ringSectionSize);
                        l_activeCoreMask |= (uint32_t)( 1 << ((NUM_OF_CORES - 1) - ec) );
                    }

                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

                } // Done inserting current ec core instance ring

            } //for(ringId) - Done inserting all core instance rings for current ec core

        } //for (quadrant=0; quadrant<CORES_PER_QME; quadrant++)

    } //for (eq=0; eq<NUM_OF_QMES; eq++)


fapi_try_exit:

    if( (l_ringType == COMMON_RING) &&
        (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS) )
    {
        //Error handling:
        //-when image would have run out-of-space if try to append common ring
        //-Any other 'unknown/unexpected' error reported
        io_bootCoreMask = 0;
        FAPI_IMP("bootCoreMask value: 0x%08x", io_bootCoreMask);
        FAPI_DBG("Exiting fetch_and_insert_vpd_rings w/rc=0x%08x", (uint32_t)fapi2::current_err);
        return fapi2::current_err;
    }
    else if( (l_ringType == INSTANCE_RING) &&
             (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS) )
    {
        //Error handling: Any other 'unknown/unexpected' error reported
        io_bootCoreMask = l_activeCoreMask;
        FAPI_IMP("bootCoreMask value: 0x%08x", io_bootCoreMask);
        FAPI_DBG("Exiting fetch_and_insert_vpd_rings w/rc=0x%08x", (uint32_t)fapi2::current_err);
        return fapi2::current_err;
    }

    // Display all EQ/EC instance rings found in mvpd for given bootCoreMask
    FAPI_DBG("List of instance rings available in mvpd (as per bootCoreMask):");
    FAPI_DBG("Domain | Domain rings in Mvpd");
    FAPI_DBG("-----------------------------");
    FAPI_DBG("EQ     | 0x%08x", l_instanceVpdRing.EQ);
    FAPI_DBG("EC     | 0x%08x", l_instanceVpdRing.EC);
    FAPI_DBG("-----------------------------");

    l_bootCoreMaskMin = ~(l_instanceVpdRing.EQ | l_instanceVpdRing.EC) & io_bootCoreMask;

    FAPI_DBG("bootCoreMaskMin: 0x%08x", l_bootCoreMaskMin);
    FAPI_DBG("ActiveCoreMask : 0x%08x", l_activeCoreMask);

    // Normal case when generated image didn't run out-of-space
    if (l_bImgOutOfSpace == false)
    {
        FAPI_DBG("SBE image or QME ring section created successfully");
        l_activeCoreMask |= io_bootCoreMask;
    }
    else    // Case where generated image ran out-of-space
    {
        // Useful debug info when image ran out-of-space
        FAPI_DBG("--------------------------------------------------------------");
        FAPI_DBG("SBE image or QME ring section ran out-of-space...");
        FAPI_DBG("EQ number at image overflow                     : %d", l_eqNumWhenOutOfSpace);
        FAPI_DBG("Chiplet name under process at image overflow    : %s",
                 ((l_instanceVpdRing.chipletUnderProcess == 0) ? "EQ" : "EC"));
        FAPI_DBG("Chiplet number under process at image overflow  : %d", l_instanceVpdRing.instanceNumUnderProcess);
        FAPI_DBG("--------------------------------------------------------------");

        // Make sure EQ chiplet is captured and valid when image ran out-of-space
        if ( l_eqNumWhenOutOfSpace < NUM_OF_QMES )
        {
            // Process EQ and other chiplets in current quad
            do
            {
                // Process EC when image ran out-of-space
                if (l_instanceVpdRing.chipletUnderProcess == EC_CHIPLET)
                {
                    // Get EC position [1:4] in quad
                    // l_ecPos = 1 : Refer fourth core in quad say EC-3 in EQ-0
                    // l_ecPos = 2 : Refer third  core in quad say EC-2 in EQ-0
                    // l_ecPos = 3 : Refer second core in quad say EC-1 in EQ-0
                    // l_ecPos = 4 : Refer first  core in quad say EC-0 in EQ-0
                    uint8_t l_ecPos = ( (l_eqNumWhenOutOfSpace + 1) * CORES_PER_QME) -
                                      l_instanceVpdRing.instanceNumUnderProcess;

                    // We have come to this point (EC chiplet) confirms that the
                    // EQ instance ring for this quad would have been appended.
                    // Now here we should check for the
                    // remaining EC chiplets (apart from one during processing
                    // of which image ran out-of-space) in quad for which instance
                    // rings available (or not) to be appended. If not available
                    // make sure to update the activecoremask as this chiplet can
                    // work with common ring and no instance ring available for
                    // this chiplet.
                    switch (l_ecPos)
                    {
                        case 4:
                        case 3:
                        case 2:
                            if (!(l_instanceVpdRing.EC &
                                  ((CORE0_MASK) >>
                                   (l_instanceVpdRing.instanceNumUnderProcess + 1))))
                            {
                                l_activeCoreMask |= ( ((CORE0_MASK) >>
                                                       (l_instanceVpdRing.instanceNumUnderProcess + 1)) &
                                                      io_bootCoreMask);
                            }

                        case 1:
                            break;

                        default:
                            FAPI_ASSERT( false,
                                         fapi2::XIPC_CODE_BUG().
                                         set_CHIP_TARGET(i_procTarget).
                                         set_OCCURRENCE(1),
                                         "Code bug(1): Incorrect EC mask. Should never get here. Fix code!" );
                            break;
                    }
                }
            }
            while(0);     // Process EQ and other chiplets in current quad

            // Get minimum set of EC cores or'ed that should be supported
            // should we hit the ceiling
            l_activeCoreMask |= l_bootCoreMaskMin;
        }
        else
        {
            FAPI_ERR("Image ran out-of-space. Value computed NOT correct");
        }

        fapi2::current_err = RC_XIPC_IMAGE_WOULD_OVERFLOW;
    } // Case where generated image ran out-of-space

    io_bootCoreMask = l_activeCoreMask;
    FAPI_IMP("bootCoreMask value: 0x%08x", io_bootCoreMask);
    FAPI_DBG("Exiting fetch_and_insert_vpd_rings w/rc=0x%08x", (uint32_t)fapi2::current_err);
    return fapi2::current_err;

} // End of   fetch_and_insert_vpd_rings()



//  Function: process_base_and_dynamic_rings()
//
//  Parameter list:
//  const fapi::Target &i_target:    Processor chip target.
//  void*           i_baseRingSection
//  void*           i_dynamicRingSection
//  void*           io_ringBuf1
//  void*           i_ringBuf2
//  void*           i_ringBuf3
//  std::map<Rs4Selector_t, Rs4Selector_t> i_idxFeatureMap
//  std::map<RingId_t, uint64_t> io_ringIdFeatureVecMap
//  Rs4Selector_t   i_numberOfFeatures
//  RingId_t&       i_ringId
//  uint32_t        i_ddlevel
//
#ifdef WIN32
int process_base_and_dynamic_rings(
    int i_procTarget,
#else
fapi2::ReturnCode process_base_and_dynamic_rings(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#endif
    void*           i_baseRingSection,
    void*           i_dynamicRingSection,
    void*           io_ringBuf1,
    void*           i_ringBuf2,
    void*           i_ringBuf3,
    std::map<Rs4Selector_t, Rs4Selector_t> i_idxFeatureMap,
    std::map<RingId_t, uint64_t>& io_ringIdFeatureVecMap,
    Rs4Selector_t   i_numberOfFeatures,
    RingId_t        i_ringId,
    uint32_t        i_ddlevel )
{
    int         l_rc = 0;
    uint32_t    ringBlockSize = 0xFFFFFFFF;
    uint32_t    dynUncmpSize = 0;
    uint32_t    maxRingBufSize = MAX_RING_BUF_SIZE;
    bool        bDynRingFound = false;
    bool        bBaseRingFound = false;
    uint32_t    nextFeature = 0;
    uint64_t    featureVecAcc = 0;
    uint8_t     mask = 0;
    bool        bUpdateAcc = false;
    uint8_t     baseTypeField = 0;
    uint8_t     dynTypeField = 0;
    uint8_t     finalTypeField = 0;

    // io_ringBuf1 is used for multiple purposes:-
    // 1-> In dynRs4, it contains the individual Dynamic RS4 rings from the
    //     .dynamic ring section.
    // 2-> In baseRs4, it contains the Base ring from the .<ppe>.rings
    //     ring section.
    // 3-> In finalRs4, it contains the final [overlaid] RS4 ring that gets
    //     appended to the customized .rings section.
    void* dynRs4 = io_ringBuf1;
    void* baseRs4 = io_ringBuf1;
    void* finalRs4 = io_ringBuf1;

    uint8_t* dataDyn = (uint8_t*)i_ringBuf2;
    uint8_t* careDyn = (uint8_t*)i_ringBuf2 + maxRingBufSize / 2;

    uint8_t* dataDynAcc = (uint8_t*)i_ringBuf3;
    uint8_t* careDynAcc = (uint8_t*)i_ringBuf3 + maxRingBufSize / 2;

    memset(dataDyn, 0, maxRingBufSize);
    memset(dataDynAcc, 0, maxRingBufSize);

    FAPI_DBG("Entering process_base_and_dynamic_rings i_numberOfFeatures is %d and i_ringId"
             " is 0x%x",
             i_numberOfFeatures, i_ringId);

    //
    // 1st: Get/accumulate the Dynamic ring(s)
    //
    for (uint64_t idxFeat = 0; idxFeat < i_numberOfFeatures; idxFeat++)
    {
        nextFeature = i_idxFeatureMap[idxFeat];
        l_rc = dyn_get_ring( i_dynamicRingSection,
                             i_ringId,
                             nextFeature,
                             i_ddlevel,
                             dynRs4,
                             maxRingBufSize,
                             0 );

        if(l_rc == TOR_SUCCESS)
        {
            bDynRingFound = true;
            featureVecAcc |= 0x8000000000000000 >> nextFeature;

            dynTypeField = ((CompressedScanData*)dynRs4)->iv_type;

            l_rc = _rs4_decompress(
                       dataDyn,
                       careDyn,
                       maxRingBufSize / 2,
                       &dynUncmpSize,
                       (CompressedScanData*)(dynRs4) );

            FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                         fapi2::XIPC_RS4_DECOMPRESS_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_ID(i_ringId).
                         set_MAX_RING_BYTE_SIZE(maxRingBufSize).
                         set_LOCAL_RC(l_rc).
                         set_OCCURRENCE(1),
                         "_rs4_decompress() failed w/rc=%i for "
                         "ringId=0x%x, maxRingBufSize=%d, occurrence=1",
                         l_rc, i_ringId, maxRingBufSize );

            int i ;

            for (i = 0; i < (int)dynUncmpSize / 8; i++)
            {
                if (careDyn[i] > 0)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        mask = 0x80 >> j;

                        if (careDyn[i] & mask)
                        {
                            //Conflict checking
                            if ( ((careDynAcc[i] & mask) == mask) &&
                                 ((careDyn[i] & mask) == mask) )
                            {
                                if ( (dataDynAcc[i] & mask) != (dataDyn[i] & mask) )
                                {
                                    FAPI_ASSERT( false,
                                                 fapi2::XIPC_BITS_MISMATCH_DYNAMIC_RING().
                                                 set_CHIP_TARGET(i_procTarget).
                                                 set_RING_ID(i_ringId).
                                                 set_DYNBIT(8 * i + j).
                                                 set_FEATURE_VEC_ACC(featureVecAcc).
                                                 set_NEXT_FEATURE(nextFeature).
                                                 set_DATA_DYNACC(dataDynAcc[i]).
                                                 set_DATA_DYN(dataDyn[i]).
                                                 set_OCCURRENCE(1),
                                                 "Bit conflict at bit=%d found while processing "
                                                 "dynamic rings for ringId=0x%0x at feature=%d and "
                                                 "featureVecAcc=0x%0llx)",
                                                 8 * i + j, i_ringId, nextFeature, featureVecAcc);
                                }
                                else
                                {
                                    continue;
                                }
                            }
                            else
                            {
                                bUpdateAcc = true;
                            }

                            if(bUpdateAcc)
                            {
                                dataDynAcc[i] |= dataDyn[i] & mask;
                                careDynAcc[i] |= mask;
                            }
                        }
                    }
                }
            }

            if (dynUncmpSize % 8)
            {
                i = (int)dynUncmpSize / 8;

                careDyn[i] &= ~(0xFF << (8 - (dynUncmpSize % 8)));

                if (careDyn[i] > 0)
                {
                    for (int j = 0; j < (int)dynUncmpSize % 8; j++)
                    {
                        mask = 0x80 >> j;

                        if (careDyn[i] & mask)
                        {
                            //Conflict checking
                            if((careDynAcc[i] == 1) && (careDyn[i] == 1))
                            {
                                if(!(dataDynAcc[i] == dataDyn[i]))
                                {
                                    FAPI_ASSERT( false,
                                                 fapi2::XIPC_BITS_MISMATCH_DYNAMIC_RING().
                                                 set_CHIP_TARGET(i_procTarget).
                                                 set_RING_ID(i_ringId).
                                                 set_DYNBIT(8 * i + j).
                                                 set_FEATURE_VEC_ACC(featureVecAcc).
                                                 set_NEXT_FEATURE(nextFeature).
                                                 set_DATA_DYNACC(dataDynAcc[i]).
                                                 set_DATA_DYN(dataDyn[i]).
                                                 set_OCCURRENCE(2),
                                                 "Bit conflict at bit=0x%d found while processing "
                                                 "dynamic rings for ringId=0x%0x at feature=%d and "
                                                 "featureVecAcc=0x%0llx)",
                                                 8 * i + j, i_ringId, nextFeature, featureVecAcc);
                                }
                                else
                                {
                                    continue;
                                }
                            }
                            else
                            {
                                bUpdateAcc = true;
                            }

                            if(bUpdateAcc)
                            {
                                dataDynAcc[i] |= dataDyn[i] & mask;
                                careDynAcc[i] |= mask;
                            }
                        }
                    }
                }
            }
        }
        else if( l_rc != TOR_DYN_RING_NOT_FOUND &&
                 l_rc != TOR_HOLE_RING_ID )
        {
            FAPI_ASSERT( false,
                         fapi2::XIPC_DYNAMIC_RING_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_ID(i_ringId).
                         set_MAX_RING_BYTE_SIZE(maxRingBufSize).
                         set_LOCAL_RC(l_rc),
                         "Failed to fetch dynamic ring for ringID 0x%0x w/rc = %i",
                         i_ringId, l_rc);
        }
    }

    if(bDynRingFound)
    {
        io_ringIdFeatureVecMap.insert({i_ringId, featureVecAcc});
    }

    //
    // 2nd: Get the Base ring
    //
    l_rc = tor_get_single_ring(
               i_baseRingSection,
               i_ddlevel,
               i_ringId,
               0xff,
               baseRs4,
               ringBlockSize );

    FAPI_ASSERT( l_rc == TOR_SUCCESS ||
                 l_rc == TOR_RING_IS_EMPTY ||
                 l_rc == TOR_HOLE_RING_ID ||
                 l_rc == TOR_INVALID_CHIPLET_TYPE,  // We will hit this in RT_QME phase
                 fapi2::XIPC_BASE_GET_SINGLE_RING_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_RING_ID(i_ringId).
                 set_DD_LEVEL(i_ddlevel).
                 set_LOCAL_RC(l_rc),
                 "ERROR: tor_get_single_ring() for Base ring: Failed w/rc=%i for "
                 "ringId=0x%x, chipletId=0xff and ddLevel=0x%x",
                 l_rc, i_ringId, i_ddlevel );

    if(l_rc == TOR_SUCCESS)
    {
        FAPI_DBG("Successfully found Base ringId=0x%x of iv_size=%d bytes", i_ringId,
                 be16toh(((CompressedScanData*)(i_baseRingSection))->iv_size));

        bBaseRingFound = true;

        baseTypeField = ((CompressedScanData*)baseRs4)->iv_type;
    }

    if(bBaseRingFound && bDynRingFound)
    {
        FAPI_DBG("ringId=0x%x: Base ring found. Dynamic ring found.", i_ringId);

        // Use baseTypeField as ref input value for iv_type, but dynTypeField would be just as good
        finalTypeField = (baseTypeField & ~RS4_IV_TYPE_SEL_MASK) |
                         RS4_IV_TYPE_SEL_BASE | RS4_IV_TYPE_SEL_DYN | RS4_IV_TYPE_SEL_FINAL;

        // Note that apply_overlay_ring() will set iv_selector = UNDEFINED_RS4_SELECTOR.
        FAPI_TRY( apply_overlay_ring( i_procTarget,
                                      finalRs4, //finalRs4=baseRs4=io_ringBuf1 will have final ring
                                      i_ringBuf2,
                                      dataDynAcc, //dataDynAcc=i_ringBuf3 has raw Dynamic ring
                                      dynUncmpSize,
                                      (CompressedScanData*)finalRs4, //Base is a good ref
                                      finalTypeField ),
                  "apply_overlay_ring() for Dynamic overlay: Failed "
                  "w/rc=0x%08x for ringId=0x%x",
                  (uint32_t)current_err, i_ringId);

        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
    else if(!bBaseRingFound && bDynRingFound)
    {
        FAPI_DBG("ringId=0x%x: No Base ring found. Dynamic ring found.", i_ringId);

        // We'll need these temp vars below
        RingId_t ringIdTmp = be16toh(((CompressedScanData*)finalRs4)->iv_ringId);
        uint32_t scanAddrTmp = be32toh(((CompressedScanData*)finalRs4)->iv_scanAddr);

        finalTypeField = (dynTypeField & ~RS4_IV_TYPE_SEL_MASK) |
                         RS4_IV_TYPE_SEL_DYN | RS4_IV_TYPE_SEL_FINAL;

        l_rc = _rs4_compress(
                   (CompressedScanData*)finalRs4,//finalRs4 = io_ringBuf1 will have final ring
                   maxRingBufSize,
                   dataDynAcc,
                   careDynAcc,
                   dynUncmpSize,
                   scanAddrTmp,
                   ringIdTmp,
                   UNDEFINED_RS4_SELECTOR,
                   finalTypeField );

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_RS4_COMPRESS_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(ringIdTmp).
                     set_SCAN_ADDR(scanAddrTmp).
                     set_LOCAL_RC(l_rc).
                     set_OCCURRENCE(1),
                     "_rs4_compress() for dynamic ring: Failed w/rc=%i for "
                     "ringId=0x%x, scanAddr=0x%8x, occurrence=1 ",
                     l_rc, ringIdTmp, scanAddrTmp );

        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
    else if(bBaseRingFound && !bDynRingFound)
    {
        //In this case finalRs4 = baseRs4 = io_ringBuf1 already has the final ring
        FAPI_DBG("ringId=0x%x: Base ring found. No Dynamic ring found.", i_ringId);

        finalTypeField = (baseTypeField & ~RS4_IV_TYPE_SEL_MASK) |
                         RS4_IV_TYPE_SEL_BASE | RS4_IV_TYPE_SEL_FINAL;
        ((CompressedScanData*)finalRs4)->iv_type = finalTypeField;

        ((CompressedScanData*)finalRs4)->iv_selector = UNDEFINED_RS4_SELECTOR;

        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
    else
    {
        FAPI_DBG("ringId=0x%x: No Base ring found. No Dynamic ring found.", i_ringId);
        fapi2::current_err = RC_XIPC_NO_RING_FOUND;
    }

    // Note that the final ring is already in io_ringBuf1 at this point.

fapi_try_exit:
    FAPI_DBG("Exiting process_base_and_dynamic_rings");
    return fapi2::current_err;
}
//End of process_base_and_dynamic_rings


//  Function: apply_fbc_dyninits()
//  Determines the fabric settings to apply based on system
//  configuration and and sets the dynamic init vector.
//
//  Parameter list:
//  const fapi::Target &i_procTarget:   Processor chip target.
//  const fapi::Target &FAPI_SYSTEM:    System target.
//  uint64_t& io_featureVec:            Bit vector of dynamic init features.
//
#ifdef WIN32
int apply_fbc_dyninits(
    int i_procTarget,
    int FAPI_SYSTEM,
#else
fapi2::ReturnCode apply_fbc_dyninits(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& FAPI_SYSTEM,
#endif
    uint64_t& io_featureVec)
{
    FAPI_DBG("Entering apply_fbc_dyninits");

    fapi2::ATTR_FREQ_CORE_FLOOR_MHZ_Type l_core_fmin;
    fapi2::ATTR_FREQ_CORE_CEILING_MHZ_Type l_core_fmax;
    fapi2::ATTR_FREQ_PAU_MHZ_Type l_fpau;
    fapi2::ATTR_FREQ_MC_MHZ_Type l_fmc;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_mc_pos;
    bool l_rt2pa_nominal;
    bool l_rt2pa_safe;
    bool l_pa2rt_turbo;
    bool l_pa2rt_nominal;
    bool l_pa2rt_safe;
    bool l_rt2mc_ultraturbo[4]  = { false };
    bool l_rt2mc_turbo[4]       = { false };
    bool l_rt2mc_nominal[4]     = { false };
    bool l_rt2mc_safe[4]        = { false };
    bool l_mc2rt_ultraturbo[4]  = { false };
    bool l_mc2rt_turbo[4]       = { false };
    bool l_mc2rt_nominal[4]     = { false };
    bool l_mc2rt_safe[4]        = { false };

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PAU_MHZ, FAPI_SYSTEM, l_fpau),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_PAU_MHZ)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ, i_procTarget, l_core_fmin),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_CORE_FLOOR_MHZ)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_CEILING_MHZ, i_procTarget, l_core_fmax),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_CORE_CEILING_MHZ)");

    // MC Fast Settings
    for (auto& l_mc_target : i_procTarget.getChildren<fapi2::TARGET_TYPE_MC>())
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mc_target, l_mc_pos),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS_Type)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_MC_MHZ, l_mc_target, l_fmc),
                 "Error from FAPI_ATTR_GET (ATTR_FREQ_MC_MHZ)");

        if(l_fmc > 1610)
        {
            if(l_mc_pos == 0)
            {
                io_featureVec |= fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_MC0_FAST;
            }
            else if(l_mc_pos == 1)
            {
                io_featureVec |= fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_MC1_FAST;
            }
            else if(l_mc_pos == 2)
            {
                io_featureVec |= fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_MC2_FAST;
            }
            else
            {
                io_featureVec |= fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_MC3_FAST;
            }
        }
    }

    // PBI Async Settings
    // Frequency Ratio Definitions
    //
    // RT2PA
    // RT->PAU NOMINAL when Nest Fmin >= 1/2 * Fpau
    // RT->PAU SAFE    when Nest Fmin <  1/2 * Fpau
    //
    // PA2RT
    // PAU->RF TURBO   when Fpau >= 4/2 * Nest Fmax
    // PAU->RF NOMINAL when Fpau >= 3/2 * Nest Fmax and Fpau < 4/2 * Nest Fmax
    // PAU->RF SAFE    when                             Fpau < 3/2 * Nest Fmax
    //
    // RT2MC
    // RT->MC ULTRA_TURBO when Nest Fmin >= 3/2 * Fmc
    // RT->MC TURBO       when Nest Fmin >= 2/2 * Fmc and Nest Fmin < 3/2 * Fmc
    // RT->MC NOMINAL     when Nest Fmin >= 1/2 * Fmc and Nest Fmin < 2/2 * Fmc
    // RT->MC SAFE        when                            Nest Fmin < 1/2 * Fmc
    //
    // MC2RT
    // MC->RT ULTRA_TURBO when Fmc >= 4/2 * Nest Fmax
    // MC->RT TURBO when       Fmc >= 3/2 * Nest Fmax and Fmc < 4/2 * Nest Fmax
    // MC->RT NOMINAL when     Fmc >= 2/2 * Nest Fmax and Fmc < 3/2 * Nest Fmax
    // MC->RT SAFE when                                   Fmc < 2/2 * Nest Fmax

    l_rt2pa_nominal    = ((l_core_fmin) >= (l_fpau)) ? (true) : (false);
    l_rt2pa_safe       = ((l_core_fmin)  < (l_fpau)) ? (true) : (false);

    l_pa2rt_turbo      = ((     l_fpau) >= (    l_core_fmax))                                ? (true) : (false);
    l_pa2rt_nominal    = (((4 * l_fpau) >= (3 * l_core_fmax)) && ((l_fpau) < (l_core_fmax))) ? (true) : (false);
    l_pa2rt_safe       = (( 4 * l_fpau)  < (3 * l_core_fmax))                                ? (true) : (false);

    for (auto& l_mc_target : i_procTarget.getChildren<fapi2::TARGET_TYPE_MC>())
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mc_target, l_mc_pos),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS_Type)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_MC_MHZ, l_mc_target, l_fmc),
                 "Error from FAPI_ATTR_GET (ATTR_FREQ_MC_MHZ)");

        l_rt2mc_ultraturbo[l_mc_pos] = ( (l_core_fmin) >= (3 * l_fmc))                                   ? (true) : (false);
        l_rt2mc_turbo[l_mc_pos]      = (((l_core_fmin) >= (2 * l_fmc)) && ((l_core_fmin) < (3 * l_fmc))) ? (true) : (false);
        l_rt2mc_nominal[l_mc_pos]    = (((l_core_fmin) >= (    l_fmc)) && ((l_core_fmin) < (2 * l_fmc))) ? (true) : (false);
        l_rt2mc_safe[l_mc_pos]       = ( (l_core_fmin)  < (    l_fmc))                                   ? (true) : (false);

        l_mc2rt_ultraturbo[l_mc_pos] = ((     l_fmc) >= (    l_core_fmax))                               ? (true) : (false);
        l_mc2rt_turbo[l_mc_pos]      = (((4 * l_fmc) >= (3 * l_core_fmax))
                                        && ((    l_fmc) < (    l_core_fmax))) ? (true) : (false);
        l_mc2rt_nominal[l_mc_pos]    = (((2 * l_fmc) >= (    l_core_fmax))
                                        && ((4 * l_fmc) < (3 * l_core_fmax))) ? (true) : (false);
        l_mc2rt_safe[l_mc_pos]       = (( 2 * l_fmc)  < (    l_core_fmax))                               ? (true) : (false);
    }

    if(l_rt2pa_nominal)
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2PA_NOMINAL;
    }

    if(l_rt2pa_safe)
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2PA_SAFE;
    }

    if(l_pa2rt_turbo)
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_PA2RT_TURBO;
    }

    if(l_pa2rt_nominal)
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_PA2RT_NOMINAL;
    }

    if(l_pa2rt_safe)
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_PA2RT_SAFE;
    }

    if(l_rt2mc_ultraturbo[0])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC0_ULTRATURBO;
    }

    if(l_rt2mc_turbo[0])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC0_TURBO;
    }

    if(l_rt2mc_nominal[0])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC0_NOMINAL;
    }

    if(l_rt2mc_safe[0])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC0_SAFE;
    }

    if(l_rt2mc_ultraturbo[1])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC1_ULTRATURBO;
    }

    if(l_rt2mc_turbo[1])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC1_TURBO;
    }

    if(l_rt2mc_nominal[1])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC1_NOMINAL;
    }

    if(l_rt2mc_safe[1])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC1_SAFE;
    }

    if(l_rt2mc_ultraturbo[2])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC2_ULTRATURBO;
    }

    if(l_rt2mc_turbo[2])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC2_TURBO;
    }

    if(l_rt2mc_nominal[2])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC2_NOMINAL;
    }

    if(l_rt2mc_safe[2])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC2_SAFE;
    }

    if(l_rt2mc_ultraturbo[3])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC3_ULTRATURBO;
    }

    if(l_rt2mc_turbo[3])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC3_TURBO;
    }

    if(l_rt2mc_nominal[3])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC3_NOMINAL;
    }

    if(l_rt2mc_safe[3])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_RT2MC3_SAFE;
    }

    if(l_mc2rt_ultraturbo[0])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT0_ULTRATURBO;
    }

    if(l_mc2rt_turbo[0])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT0_TURBO;
    }

    if(l_mc2rt_nominal[0])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT0_NOMINAL;
    }

    if(l_mc2rt_safe[0])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT0_SAFE;
    }

    if(l_mc2rt_ultraturbo[1])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT1_ULTRATURBO;
    }

    if(l_mc2rt_turbo[1])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT1_TURBO;
    }

    if(l_mc2rt_nominal[1])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT1_NOMINAL;
    }

    if(l_mc2rt_safe[1])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT1_SAFE;
    }

    if(l_mc2rt_ultraturbo[2])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT2_ULTRATURBO;
    }

    if(l_mc2rt_turbo[2])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT2_TURBO;
    }

    if(l_mc2rt_nominal[2])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT2_NOMINAL;
    }

    if(l_mc2rt_safe[2])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT2_SAFE;
    }

    if(l_mc2rt_ultraturbo[3])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT3_ULTRATURBO;
    }

    if(l_mc2rt_turbo[3])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT3_TURBO;
    }

    if(l_mc2rt_nominal[3])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT3_NOMINAL;
    }

    if(l_mc2rt_safe[3])
    {
        io_featureVec |= ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_FBC_ASYNC_MC2RT3_SAFE;
    }

fapi_try_exit:
    FAPI_DBG("Exiting apply_fbc_dyninits");
    return fapi2::current_err;
}
//End of apply_fbc_dyninits


#ifndef WIN32
fapi2::ReturnCode p10_ipl_customize (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#else
ReturnCode p10_ipl_customize (
    int& i_procTarget,
#endif
    void*     i_hwImage,
    void*     io_image,
    uint32_t& io_imageSize,             // In: Max, Out: Actual
    void*     io_ringSectionBuf,
    uint32_t& io_ringSectionBufSize,    // In: Max, Out: Actual
    uint8_t   i_sysPhase,               // {HB_SBE,RT_QME}
    void*     i_ringBuf1,
    uint32_t  i_ringBufSize1,
    void*     i_ringBuf2,
    uint32_t  i_ringBufSize2,
    void*     i_ringBuf3,
    uint32_t  i_ringBufSize3,
    uint32_t& io_bootCoreMask )         // Bits(0:31) = Core(0:31)
{
#ifndef WIN32
    fapi2::ReturnCode   l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode   l_fapiRc2 = fapi2::FAPI2_RC_SUCCESS;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
#else
    ReturnCode   l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    ReturnCode   l_fapiRc2 = fapi2::FAPI2_RC_SUCCESS;
#endif
    int             l_rc = 0; // Non-fapi RC

    int mainSectionID = UNDEFINED_IPL_IMAGE_SID; // Represents the nested PPE image
    int subSectionID  = UNDEFINED_IPL_IMAGE_SID; // Represents .rings within nested image
    P9XipSection    iplImgSection;
    //Suggested replacement name:
    //IplImgSection   iplImgSection; // Formerly: P9XipSection xipSection.
    uint32_t        l_inputImageSize;
    uint32_t        l_imageSizeWithoutRings;
    uint32_t        l_currentImageSize;
    uint32_t        l_maxImageSize = 0;   // Attrib adjusted local value of MAX_SEEPROM_IMAGE_SIZE
    uint32_t        l_maxRingSectionSize; // Max size of ringSection
    uint32_t        l_ringSectionBufSize; // Size of ringSection buffer
    uint32_t        l_sectionOffset = 1;
    uint32_t        attrMaxSbeSeepromSize = 0;
    uint32_t        l_requestedBootCoreMask = (i_sysPhase == SYSPHASE_HB_SBE) ? io_bootCoreMask : 0xFFFFFFFF;
    uint8_t         attrDdLevel = UNDEFINED_DD_LEVEL; // Platform DD level
    uint32_t        sizeMvpdDDField = 0;
    uint8_t*        decimalDDData = nullptr;
    uint8_t*        fullDDData = nullptr;
    uint8_t         mvpdDD = UNDEFINED_DD_LEVEL; // Mvpd DD level
    uint8_t         chipName = 0;
    uint32_t        sizeMvpdCIField = 0;
    uint8_t*        fullCIData = nullptr;

    uint64_t        featureVec = 0; // Dynamic inits feature vector from platform attribute
    fapi2::ATTR_SYSTEM_IPL_PHASE_Type l_attrSystemIplPhase;
    fapi2::ATTR_CONTAINED_IPL_TYPE_Type l_attrContainedIplType;
    RingId_t        ringId = UNDEFINED_RING_ID;
    std::map< Rs4Selector_t,  Rs4Selector_t> idxFeatureMap;
    std::map<RingId_t, uint64_t> ringIdFeatureVecMap;
    uint8_t*        ringIdFeatList = NULL;
    uint16_t        ringIdFeatListSize = 0;
    Rs4Selector_t   numberOfFeatures = 0;
    void*           baseRingSection = NULL;
    void*           dynamicRingSection = NULL;
    TorHeader_t*    torHeaderBase;
    uint8_t*        partialKwdData = NULL;
    uint32_t        sizeofPartialKwdData  = 0;
    uint8_t         mvpdRtvFromCode = 0xff;
    uint8_t         mvpdRtvFromMvpd = 0xff;
    MvpdKeyword     mvpdKeyword;

    FAPI_IMP("Entering p10_ipl_customize w/sysPhase=%d...", i_sysPhase);


    // Make copy of the requested bootCoreMask
    io_bootCoreMask = l_requestedBootCoreMask;

    //-------------------------------------------
    // Check some input buffer parameters:
    // - sysPhase is checked later
    // - log the initial image size
    // - more buffer size checks in big switch()
    //-------------------------------------------

    FAPI_ASSERT( i_hwImage != NULL &&
                 (io_image != NULL || i_sysPhase == SYSPHASE_RT_QME) && // RT_QME ignores io_image
                 io_ringSectionBuf != NULL &&
                 i_ringBuf1 != NULL &&
                 i_ringBuf2 != NULL &&
                 i_ringBuf3 != NULL,
                 fapi2::XIPC_INVALID_INPUT_BUFFER_PTR_PARM().
                 set_CHIP_TARGET(i_procTarget).
                 set_SYSPHASE(i_sysPhase).
                 set_HW_IMAGE(i_hwImage).
                 set_IMAGE_BUF(io_image).
                 set_RING_SECTION_BUF(io_ringSectionBuf).
                 set_RING_BUF1(i_ringBuf1).
                 set_RING_BUF2(i_ringBuf2).
                 set_RING_BUF3(i_ringBuf3),
                 "One or more invalid input buffer pointers:\n"
                 "  i_sysPhase=%d\n"
                 "  i_hwImage=0x%016llx\n"
                 "  io_image=0x%016llx\n"
                 "  io_ringSectionBuf=0x%016llx\n"
                 "  i_ringBuf1=0x%016llx\n"
                 "  i_ringBuf2=0x%016llx\n"
                 "  i_ringBuf3=0x%016llx\n",
                 i_sysPhase,
                 (uintptr_t)i_hwImage,
                 (uintptr_t)io_image,
                 (uintptr_t)io_ringSectionBuf,
                 (uintptr_t)i_ringBuf1,
                 (uintptr_t)i_ringBuf2,
                 (uintptr_t)i_ringBuf3 );

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        l_rc = p9_xip_image_size(io_image, &l_inputImageSize);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_XIP_API_MISC_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_RC(l_rc).
                     set_OCCURRENCE(1),
                     "p9_xip_image_size() failed w/rc=0x%08x at occurrence=1",
                     (uint32_t)l_rc );

        FAPI_DBG("Input image size: %d", l_inputImageSize);
    }
    else
    {
        l_inputImageSize = 0;    // For RT_QME there is no separate input PPE image
    }

    // Check that buffer sizes are > or == to some minimum sizes. More precise size checks
    //   later for each sysPhase. Neither io_imageSize nor io_ringSectionBufSize are
    //   subject to attrMaxSbeSeepromSize adjust yet, since this is sysPhase dependent.
    FAPI_ASSERT( ( io_imageSize >= MAX_SEEPROM_IMAGE_SIZE ||
                   i_sysPhase == SYSPHASE_RT_QME ) && // RT_QME ignores io_image
                 io_ringSectionBufSize >= MAX_SEEPROM_IMAGE_SIZE &&
                 i_ringBufSize1 == MAX_RING_BUF_SIZE &&
                 i_ringBufSize2 == MAX_RING_BUF_SIZE &&
                 i_ringBufSize3 == MAX_RING_BUF_SIZE,
                 fapi2::XIPC_INVALID_INPUT_BUFFER_SIZE_PARM().
                 set_CHIP_TARGET(i_procTarget).
                 set_SYSPHASE(i_sysPhase).
                 set_INPUT_IMAGE_SIZE(l_inputImageSize).
                 set_IMAGE_BUF_SIZE(io_imageSize).
                 set_RING_SECTION_BUF_SIZE(io_ringSectionBufSize).
                 set_RING_BUF_SIZE1(i_ringBufSize1).
                 set_RING_BUF_SIZE2(i_ringBufSize2).
                 set_RING_BUF_SIZE3(i_ringBufSize3).
                 set_OCCURRENCE(1),
                 "One or more invalid input buffer sizes:\n"
                 "  i_sysPhase=%d\n"
                 "  l_inputImageSize=0x%016llx\n"
                 "  io_imageSize=0x%016llx\n"
                 "  io_ringSectionBufSize=0x%016llx\n"
                 "  i_ringBufSize1=0x%016llx\n"
                 "  i_ringBufSize2=0x%016llx\n"
                 "  i_ringBufSize3=0x%016llx\n",
                 i_sysPhase,
                 (uintptr_t)l_inputImageSize,
                 (uintptr_t)io_imageSize,
                 (uintptr_t)io_ringSectionBufSize,
                 (uintptr_t)i_ringBufSize1,
                 (uintptr_t)i_ringBufSize2,
                 (uintptr_t)i_ringBufSize3 );

    // Make local copy of the [max] io_ringSectionBufSize before we start changing it
    l_ringSectionBufSize = io_ringSectionBufSize;


    //-------------------------------------------
    // Verify that platform and Mvpd agree on:
    // - DD level
    // - Chip name (e.g., p9 or p10)
    //-------------------------------------------

    // Get platform DD level
    l_fapiRc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, i_procTarget, attrDdLevel);

    FAPI_ASSERT( l_fapiRc == fapi2::FAPI2_RC_SUCCESS,
                 fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(1),
                 "FAPI_ATTR_GET(ATTR_EC) failed." );

    FAPI_DBG("Platform DD level = 0x%x", attrDdLevel);

    // Get platform chip name
    l_fapiRc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_procTarget, chipName);

    FAPI_ASSERT( l_fapiRc == fapi2::FAPI2_RC_SUCCESS,
                 fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(2),
                 "FAPI_ATTR_GET(ATTR_NAME) failed." );

    FAPI_DBG("Platform chip name = 0x%x", chipName);

    // Get Mvpd DD level
    FAPI_TRY(getMvpdField(fapi2::MVPD_RECORD_CRP0,
                          fapi2::MVPD_KEYWORD_DD,
                          i_procTarget,
                          NULL,
                          sizeMvpdDDField),
             "getMvpdField failed for CRP0/DD (1) w/rc=0x%08x",
             (uint64_t)fapi2::current_err);

    fullDDData = new uint8_t[sizeMvpdDDField]();
    decimalDDData = new uint8_t[sizeMvpdDDField]();

    FAPI_TRY(getMvpdField(fapi2::MVPD_RECORD_CRP0,
                          fapi2::MVPD_KEYWORD_DD,
                          i_procTarget,
                          fullDDData,
                          sizeMvpdDDField),
             "getMvpdField failed for CRP0/DD (2) w/rc=0x%08x and"
             "DD level size is of %u bytes",
             (uint64_t)fapi2::current_err, sizeMvpdDDField);

    //Size of DD keyword is of 5 bytes. 1st byte is keyword version,
    //Checking the keyword version
    FAPI_ASSERT((fullDDData[0] == MVPD_DD_KWD_VER1),
                fapi2::XIPC_MVPD_DD_KEYWORD_VERSION_ERROR().
                set_CHIP_TARGET(i_procTarget).
                set_MVPD_DD_KWD_VERSION(fullDDData[0]).
                set_MVPD_DDSIZE(sizeMvpdDDField),
                "DD Keyword version from MVPD is 0x%0x, "
                "size of DD keyword is %u",
                fullDDData[0], sizeMvpdDDField);

    //Converting ASCI to hex
    //2nd & 3rd byte contains RIT and 4th and 5th bytes has EC value.
    //DD level in MVPD is determined using RIT and EC values.
    //For example:- if DD level is x.y than the RIT = x & EC = y.
    //Therefore below we are considering RIT and EC values.
    //i value is initialized to 1 as the data field(RIT+EC) starts from there.
    for(uint32_t i = 1; i < sizeMvpdDDField; i++)
    {
        *(decimalDDData + i) = *(fullDDData + i) - '0';
    }

    //Storing the value of l_fullDDData in a uint8, value obtained from
    //MVPD is in 4 bytes i.e. the 1st two bytes contain the major DD number, x,
    //and the next two bytes contain the minor DD number, y, in DDx.y
    //Hence the below conversion is done where the 1st two bytes are
    //ORed and shifted by 4 bits.
    mvpdDD = (((*(decimalDDData + 1) * 10 + * (decimalDDData + 2)) << 4) |
              (*(decimalDDData + 3) * 10 + * (decimalDDData + 4)));

    FAPI_DBG("Mvpd DD level = 0x%x", mvpdDD);

    FAPI_ASSERT((mvpdDD == attrDdLevel),
                fapi2::XIPC_DD_LEVEL_MISMATCH_ERROR().
                set_CHIP_TARGET(i_procTarget).
                set_ATTR_DDLEVEL(attrDdLevel).
                set_MVPD_DDLEVEL(mvpdDD).
                set_MVPD_DDDATA1(*(fullDDData + 1)).
                set_MVPD_DDDATA2(*(fullDDData + 2)).
                set_MVPD_DDDATA3(*(fullDDData + 3)).
                set_MVPD_DDDATA4(*(fullDDData + 4)).
                set_MVPD_DDSIZE(sizeMvpdDDField),
                "DD level from Platform (i.e attrDdLevel: 0x%0x) and "
                "MVPD (i.e mvpdDD: 0x%0x)is not matching. "
                "Data fetched from MVPD, 1st Byte = 0x%0x, 2nd Byte = 0x%0x, "
                " 3rd Byte = 0x%0x, 4th Byte = 0x%0x. Size of MVPD is %u.",
                attrDdLevel, mvpdDD, *(fullDDData + 1), *(fullDDData + 2),
                *(fullDDData + 3), *(fullDDData + 4), sizeMvpdDDField);

    // Get Mvpd chip name
    FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CRP0,
                           fapi2::MVPD_KEYWORD_CI,
                           i_procTarget,
                           NULL,
                           sizeMvpdCIField),
              "getMvpdField failed for CRP0/CI (1) w/rc=0x%08x",
              (uint64_t)fapi2::current_err);

    fullCIData = new uint8_t[sizeMvpdCIField]();

    FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CRP0,
                           fapi2::MVPD_KEYWORD_CI,
                           i_procTarget,
                           fullCIData,
                           sizeMvpdCIField),
              "getMvpdField failed for CRP0/CI (2) w/rc=0x%08x and"
              "chipname data size is of %u bytes",
              (uint64_t)fapi2::current_err, sizeMvpdCIField);

    FAPI_DBG("Mvpd chip name = 0x%x", *fullCIData);

    FAPI_ASSERT((*(fullCIData) == MVPD_CHIP_NAME_P10) && (chipName == CID_P10),
                fapi2::XIPC_CHIPNAME_MISMATCH_ERROR().
                set_CHIP_TARGET(i_procTarget).
                set_ATTR_NAME(chipName).
                set_MVPD_NAME(fullCIData),
                "Chip name from Platform (i.e. chipName: 0x%0x)"
                "and MVPD (i.e. fullCIData: 0x%0x)is different",
                chipName, *fullCIData );

    delete fullDDData;
    fullDDData = NULL;
    delete decimalDDData;
    decimalDDData = NULL;
    delete fullCIData;
    fullCIData = NULL;

#ifdef CHIP_GEN_P9
#ifndef WIN32

    ///////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Update Filter PLL attribute from MVPD AW keyword
    // System phase:       HB_SBE
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        fapi2::ATTR_MRW_FILTER_PLL_BUCKET_Type l_filterPllBucketMRW = 0;
        uint8_t l_filterPllBucket = 0;
        uint8_t l_keywordVersion = 0;
        P9XipItem l_item;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_FILTER_PLL_BUCKET,
                               FAPI_SYSTEM,
                               l_filterPllBucketMRW),
                 "Error from FAPI_ATTR_GET (ATTR_MRW_FILTER_PLL_BUCKET)");

        // set bucket based on MRW attribute if it is non zero
        if (l_filterPllBucketMRW != 0)
        {
            l_filterPllBucket = l_filterPllBucketMRW;
        }
        // otherwise, set bucket from AW VPD data
        else
        {
            uint32_t   l_sizeMvpdFieldExpected = 4;
            uint32_t   l_sizeMvpdField = 0;
            uint8_t*   l_bufMvpdField = (uint8_t*)i_ringBuf1;

            FAPI_TRY( getMvpdField(MVPD_RECORD_CP00,
                                   MVPD_KEYWORD_AW,
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
                         "  Returned MVPD field size of AW keyword = %d\n"
                         "  Anticipated MVPD field size = %d",
                         l_sizeMvpdField,
                         l_sizeMvpdFieldExpected );

            FAPI_TRY( getMvpdField(MVPD_RECORD_CP00,
                                   MVPD_KEYWORD_AW,
                                   i_procTarget,
                                   l_bufMvpdField,
                                   l_sizeMvpdField),
                      "getMvpdField(valid buffer) failed w/rc=0x%08x",
                      (uint64_t)fapi2::current_err );

            // extract first byte (keyword version)
            l_keywordVersion = (uint8_t)(*l_bufMvpdField);

            if (l_keywordVersion == 2)
            {
                // extract data
                l_filterPllBucket = (uint8_t)(*(l_bufMvpdField + 1));
            }
        }

        FAPI_ASSERT( l_filterPllBucket <= MAX_FILTER_PLL_BUCKETS,
                     fapi2::XIPC_MVPD_AW_FIELD_VALUE_ERR().
                     set_CHIP_TARGET(i_procTarget).
                     set_MVPD_VALUE(l_filterPllBucket),
                     "MVPD AW field bug:\n"
                     "  Value of filter PLL bucket select = %d\n"
                     "  Anticipated range = 0..%d\n",
                     l_filterPllBucket,
                     MAX_FILTER_PLL_BUCKETS );

        // set FAPI attribute
        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_FILTER_PLL_BUCKET,
                                i_procTarget,
                                l_filterPllBucket ),
                 "Error from FAPI_ATTR_SET (ATTR_FILTER_PLL_BUCKET)" );

        // customize attribute in SBE image, if field exists
        if (!p9_xip_find(io_image, "ATTR_FILTER_PLL_BUCKET", &l_item))
        {
            MBOX_ATTR_WRITE(ATTR_FILTER_PLL_BUCKET, i_procTarget, io_image);
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Write mailbox attributes
    // System phase:       HB_SBE
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        FAPI_TRY(writeMboxRegs(i_procTarget, io_image),
                 "p10_ipl_customize: error writing mbox regs in SBE image rc=0x%.8x",
                 (uint64_t)fapi2::current_err);
        FAPI_TRY(writePG(i_procTarget, io_image),
                 "p10_ipl_customize: error writing PG data in SBE image rc=0x%.8x",
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
        uint8_t*   l_bufMvpdField = (uint8_t*)i_ringBuf1;

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

#endif // ifdef CHIP_GEN_P9
#endif // ifndef WIN32



    ///////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:  Removal of .toc, .fixed_toc and .strings and adjustment
    //                  of max Seeprom image size.
    // System phase:    HB_SBE
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        // Test the size of the DD specific SBE image's .rings section (it better be ==0).
        l_rc = p9_xip_get_section(io_image, P9_XIP_SECTION_SBE_RINGS, &iplImgSection);

        FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                     fapi2::XIPC_XIP_GET_SECTION_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_RC(l_rc).
                     set_SECTION_ID(P9_XIP_SECTION_SBE_RINGS).
                     set_DDLEVEL(UNDEFINED_DD_LEVEL).
                     set_OCCURRENCE(1),
                     "p9_xip_get_section() failed (1) w/rc=0x%08x getting SBE .rings"
                     " section for ddLevel=0x%x",
                     (uint32_t)l_rc, UNDEFINED_DD_LEVEL );

        FAPI_ASSERT( iplImgSection.iv_size == 0,
                     fapi2::XIPC_INPUT_SBE_IMAGE_NONZERO_RINGS_SIZE().
                     set_CHIP_TARGET(i_procTarget).
                     set_INPUT_RINGS_SIZE(iplImgSection.iv_size),
                     "The DD specific input SBE image must have a zero sized .rings section."
                     "But the size of .rings is =%d\n", iplImgSection.iv_size );

        // Get the image size.
        l_rc = p9_xip_image_size(io_image, &l_currentImageSize);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_XIP_API_MISC_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_RC(l_rc).
                     set_OCCURRENCE(2),
                     "p9_xip_image_size() failed (2) w/rc=0x%08X",
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
                     set_OCCURRENCE(3),
                     "p9_xip_image_size() failed (3) w/rc=0x%08X",
                     (uint32_t)l_rc );

        FAPI_DBG("SBE image size w/empty .rings section after ipl image section removals: %d",
                 l_currentImageSize);

        l_imageSizeWithoutRings = l_currentImageSize;

        // Adjust the local size of MAX_SEEPROM_IMAGE_SIZE to accommodate enlarged image for Cronus
        l_fapiRc2 = FAPI_ATTR_GET(fapi2::ATTR_MAX_SBE_SEEPROM_SIZE, FAPI_SYSTEM, attrMaxSbeSeepromSize);

        FAPI_ASSERT( l_fapiRc2 == fapi2::FAPI2_RC_SUCCESS,
                     fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                     set_CHIP_TARGET(i_procTarget).
                     set_OCCURRENCE(3),
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

        // Make sure current image size isn't already too big for Seeprom
        FAPI_ASSERT( l_currentImageSize <= l_maxImageSize,
                     fapi2::XIPC_IMAGE_TOO_LARGE().
                     set_CHIP_TARGET(i_procTarget).
                     set_IMAGE_SIZE(l_currentImageSize).
                     set_MAX_IMAGE_SIZE(l_maxImageSize).
                     set_OCCURRENCE(1),
                     "Image size before VPD updates (=%d) already exceeds max image size (=%d)",
                     l_currentImageSize, l_maxImageSize );

        // Test that supplied buffer spaces are big enough to hold max image size
        FAPI_ASSERT( io_imageSize >= l_maxImageSize,
                     fapi2::XIPC_INVALID_INPUT_BUFFER_SIZE_PARM().
                     set_CHIP_TARGET(i_procTarget).
                     set_INPUT_IMAGE_SIZE(l_inputImageSize).
                     set_IMAGE_BUF_SIZE(io_imageSize).
                     set_RING_SECTION_BUF_SIZE(l_ringSectionBufSize).
                     set_RING_BUF_SIZE1(i_ringBufSize1).
                     set_RING_BUF_SIZE2(i_ringBufSize2).
                     set_OCCURRENCE(2),
                     "One or more invalid input buffer sizes for HB_SBE phase:\n"
                     "  l_maxImageSize=0x%016llx\n"
                     "  io_imageSize=0x%016llx\n"
                     "  l_ringSectionBufSize=0x%016llx\n",
                     (uintptr_t)l_maxImageSize,
                     (uintptr_t)io_imageSize,
                     (uintptr_t)l_ringSectionBufSize );

    }




    //////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Common for all subsequent customization steps
    // System phase:       All phases
    //////////////////////////////////////////////////////////////////////////

    l_fapiRc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, i_procTarget, attrDdLevel);

    FAPI_ASSERT( l_fapiRc == fapi2::FAPI2_RC_SUCCESS,
                 fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(4),
                 "FAPI_ATTR_GET(ATTR_EC) failed." );

    FAPI_DBG("attrDdLevel = 0x%x", attrDdLevel);




    //////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Extract the DD-specific .rings section from either
    //                     the SBE or QME embedded image in the HW image.
    // System phase:       All phases
    //////////////////////////////////////////////////////////////////////////

    switch (i_sysPhase)
    {

        case SYSPHASE_HB_SBE:

            // Setup up nested section ID combination for SBE PPE image
            mainSectionID = P9_XIP_SECTION_HW_SBE;
            subSectionID = P9_XIP_SECTION_SBE_RINGS;

            l_rc = p9_xip_get_sub_section( i_hwImage,
                                           mainSectionID,
                                           subSectionID,
                                           &iplImgSection,
                                           attrDdLevel );

            FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                         fapi2::XIPC_XIP_GET_SECTION_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_SECTION_ID(subSectionID).
                         set_DDLEVEL(attrDdLevel).
                         set_OCCURRENCE(2),
                         "p9_xip_get_sub_section() failed (2) w/rc=0x%08X retrieving .sbe.rings"
                         " section and ddLevel=0x%x",
                         (uint32_t)l_rc, attrDdLevel );

            break;

        case SYSPHASE_RT_QME:

            // Setup up nested section ID combination for QME PPE image
            mainSectionID = P9_XIP_SECTION_HW_QME;
            subSectionID = P9_XIP_SECTION_QME_RINGS;

            l_rc = p9_xip_get_sub_section( i_hwImage,
                                           mainSectionID,
                                           subSectionID,
                                           &iplImgSection,
                                           attrDdLevel );

            FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                         fapi2::XIPC_XIP_GET_SECTION_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_SECTION_ID(subSectionID).
                         set_DDLEVEL(attrDdLevel).
                         set_OCCURRENCE(3),
                         "p9_xip_get_sub_section() failed (3) w/rc=0x%08x retrieving .qme.rings"
                         " section and ddLevel=0x%x",
                         (uint32_t)l_rc, attrDdLevel );

            break;

        default:

            FAPI_ASSERT( false,
                         fapi2::XIPC_INVALID_SYSPHASE_PARM().
                         set_CHIP_TARGET(i_procTarget).
                         set_SYSPHASE(i_sysPhase).
                         set_OCCURRENCE(1),
                         "Caller bug: Caller supplied unsupported value of sysPhase=%u"
                         " (Occurrence 1)",
                         i_sysPhase );

            break;
    }

    // Sanity check that the .rings section exists
    FAPI_ASSERT( iplImgSection.iv_size > 0,
                 fapi2::XIPC_EMPTY_IMAGE_SECTION().
                 set_CHIP_TARGET(i_procTarget).
                 set_SECTION_ID(subSectionID).
                 set_DDLEVEL(attrDdLevel).
                 set_OCCURRENCE(3),
                 "p9_xip_get_sub_section() returned a .rings section of zero size for"
                 " sysPhase=%d, ddLevel=0x%x, mainSectionID=%d and subSectionID=%d."
                 " There's no TOR.",
                 i_sysPhase, attrDdLevel, mainSectionID, subSectionID );

    // Point baseRingSection to the DD specific ring section in either the SBE
    // or in the QME image.
    baseRingSection = (void*)((uint8_t*)i_hwImage + iplImgSection.iv_offset);




    //////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Build up a new ring section in io_ringSectionBuf
    //                     based on the TOR header info in baseRingSection.
    // System phase:       All phases
    //////////////////////////////////////////////////////////////////////////

    torHeaderBase  = (TorHeader_t*)baseRingSection;

    l_rc = tor_skeleton_generation( io_ringSectionBuf,
                                    be32toh(torHeaderBase->magic),
                                    torHeaderBase->version,
                                    attrDdLevel,
                                    torHeaderBase->chipId );

    FAPI_ASSERT( l_rc == 0,
                 fapi2::XIPC_SKELETON_GEN_FAILED().
                 set_CHIP_TARGET(i_procTarget),
                 "tor_skeleton_generation failed w/rc=0x%08X", (uint32_t)l_rc );

    // Now, start tracking the instantaneous actual custom ring section size.
    // (Note that we already took a copy of the [max] value of io_ringSectionBufSize
    // earlier on into l_ringSectionBufSize, so safe to update this now.)
    io_ringSectionBufSize = be32toh(((TorHeader_t*)io_ringSectionBuf)->size);




    //////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Determine the max allowed ringSection size
    // Systemp phase:      All phases
    //////////////////////////////////////////////////////////////////////////

    switch (i_sysPhase)
    {

        case SYSPHASE_HB_SBE:

            // Calc the max ring section size for SBE.
            l_maxRingSectionSize = l_maxImageSize - l_imageSizeWithoutRings;

            break;

        case SYSPHASE_RT_QME:

            // Max ring section size for QME.
            l_maxRingSectionSize = l_ringSectionBufSize; // l_ringSectionBufSize is actual max buf size

            break;

        default:

            FAPI_ASSERT( false,
                         fapi2::XIPC_INVALID_SYSPHASE_PARM().
                         set_CHIP_TARGET(i_procTarget).
                         set_SYSPHASE(i_sysPhase).
                         set_OCCURRENCE(2),
                         "Caller bug: Caller supplied unsupported value of sysPhase=%u"
                         " (Occurrence 2)",
                         i_sysPhase );

            break;
    }

    // maxRingSectionSize should never exceed ringSectionBufSize which should always be allocated
    // to be so large that we should be able to fill out the image to its maximum capacity.
    FAPI_ASSERT( l_maxRingSectionSize <= l_ringSectionBufSize,
                 fapi2::XIPC_RING_SECTION_SIZING().
                 set_CHIP_TARGET(i_procTarget).
                 set_RING_SECTION_SIZE(io_ringSectionBufSize).
                 set_RING_SECTION_BUF_SIZE(l_ringSectionBufSize).
                 set_MAX_RING_SECTION_SIZE(l_maxRingSectionSize).
                 set_OCCURRENCE(1),
                 "CODE BUG : maxRingSectionSize(=%u) > ringSectionBufSize(=%u) should"
                 " never happen. Fix your assumptions/settings about ringSection"
                 " buffer size or max image size (=%u) (Occurrence 1)",
                 l_maxRingSectionSize, l_ringSectionBufSize, l_maxImageSize );




    //////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Append Dynamic-on-Base rings to io_ringSectionBuf
    // System phase:       All phases
    //------------------------------------------------------------------------
    // Notes:
    // Here we copy, overlay or produce Base rings and append them to the
    // customized .rings section as follows:
    // - copy:    Is performed when a ring is only found in the .{sbe,qme}.rings
    //            ring section (ie, no Dynamic ring is found).
    // - overlay: Is performed when rings are found in both the .{sbe,qme}.rings
    //            and .dynamic ring sections.
    // - produce: Is performed when a ring is only found in the .dynamic ring
    //            ring section (ie, no Base ring is found) and in which case the Dynamic
    //            ring becomes the de facto Base ring.
    //////////////////////////////////////////////////////////////////////////

    // TODO / FIXME: The mapping from bit position in the vector to features
    //               should be encapsulated in an enum constructed at ekb build
    //               time.

    l_fapiRc2 = FAPI_ATTR_GET(fapi2::ATTR_DYNAMIC_INIT_FEATURE_VEC,
                              FAPI_SYSTEM,
                              featureVec);

    FAPI_ASSERT( l_fapiRc2 == fapi2::FAPI2_RC_SUCCESS,
                 fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(5),
                 "FAPI_ATTR_GET(ATTR_DYNAMIC_INIT_FEATURE_VEC) failed."
                 " Unable to determine featureVec." );

    FAPI_IMP("Dynamic inits featureVec = 0x%016llx (GET from plat attribute)", featureVec);

    l_fapiRc2 = FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_IPL_PHASE,
                              FAPI_SYSTEM,
                              l_attrSystemIplPhase);

    FAPI_ASSERT( l_fapiRc2 == fapi2::FAPI2_RC_SUCCESS,
                 fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(6),
                 "Failed to retrieve the system IPL phase attribute" );

    l_fapiRc2 = FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE,
                              FAPI_SYSTEM,
                              l_attrContainedIplType);

    FAPI_ASSERT( l_fapiRc2 == fapi2::FAPI2_RC_SUCCESS,
                 fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(7),
                 "Failed to retrieve the contained IPL type attribute" );

    // apply ipl dynamic inits
    if ((l_attrSystemIplPhase == fapi2::ENUM_ATTR_SYSTEM_IPL_PHASE_HB_IPL) &&
        (i_sysPhase == SYSPHASE_HB_SBE))
    {
        featureVec |= fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_HOSTBOOT;

        // apply fabric dynamic inits
        FAPI_TRY(apply_fbc_dyninits(i_procTarget, FAPI_SYSTEM, featureVec),
                 "Error applying fabric dynamic inits");
    }
    else if (l_attrSystemIplPhase == fapi2::ENUM_ATTR_SYSTEM_IPL_PHASE_CONTAINED_IPL)
    {
        featureVec |= fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_COMMON_CONTAINED;

        if (l_attrContainedIplType == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_CACHE)
        {
            featureVec |= fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_CACHE_CONTAINED;
        }
        else
        {
            featureVec |= fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_CHIP_CONTAINED;
        }
    }
    else // runtime
    {
        fapi2::ATTR_SMF_CONFIG_Type l_attrSmfConfig;

        l_fapiRc2 = FAPI_ATTR_GET(fapi2::ATTR_SMF_CONFIG, FAPI_SYSTEM, l_attrSmfConfig);

        if(l_attrSmfConfig == fapi2::ENUM_ATTR_SMF_CONFIG_DISABLED)
        {
            FAPI_DBG("Applying Dynamic Init Runtime Feature: HV_INITS");
            featureVec |= fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_HV_INITS;
        }

        // clear undesireable features
        featureVec &= ~fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_HOSTBOOT;
        featureVec &= ~fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_COMMON_CONTAINED;
        featureVec &= ~fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_CACHE_CONTAINED;
        featureVec &= ~fapi2::ENUM_ATTR_DYNAMIC_INIT_FEATURE_VEC_CHIP_CONTAINED;
    }

    l_fapiRc2 = FAPI_ATTR_SET(fapi2::ATTR_DYNAMIC_INIT_FEATURE_VEC,
                              FAPI_SYSTEM,
                              featureVec);

    FAPI_ASSERT( l_fapiRc2 == fapi2::FAPI2_RC_SUCCESS,
                 fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(8),
                 "Failed to set the dynamic init feature vector attribute" );

    FAPI_IMP("Dynamic inits featureVec = 0x%016llx (SET to plat attribute)", featureVec);

    l_rc = p9_xip_get_section(i_hwImage, P9_XIP_SECTION_HW_DYNAMIC, &iplImgSection, attrDdLevel);

    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                 fapi2::XIPC_XIP_GET_SECTION_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_XIP_RC(l_rc).
                 set_SECTION_ID(P9_XIP_SECTION_HW_DYNAMIC).
                 set_DDLEVEL(attrDdLevel).
                 set_OCCURRENCE(4),
                 "p9_xip_get_section() failed (4) w/rc=0x%08X getting .dynamic"
                 " section for ddLevel=0x%x",
                 (uint32_t)l_rc, attrDdLevel );

    dynamicRingSection = (void*)((uint8_t*)i_hwImage + iplImgSection.iv_offset);

    for(Rs4Selector_t feature = 0; feature < 64; feature++)
    {
        if( featureVec & (0x8000000000000000 >> feature) )
        {
            idxFeatureMap.insert({numberOfFeatures, feature});
            numberOfFeatures++;
        }
    }

//CMO-20190825: For the RT_QME phase we will get TOR_INVALID_CHIPLET_TYPE a lot
//              here because we cycle through all the chiplets, when we really only
//              should consider the EQ chiplet for RT_QME. For now, we will be
//              mindless, but this should probably be changed.
    for(ringId = 0; ringId < NUM_RING_IDS; ringId++)
    {
        // Only process non-Mvpd and GPTR rings (which are all assumed to be Common rings)
        if ( ringid_is_gptr_ring(torHeaderBase->chipId, ringId) == false &&
             ringid_is_mvpd_ring(torHeaderBase->chipId, ringId) == true )
        {
            continue;
        }

        l_fapiRc = process_base_and_dynamic_rings( i_procTarget,
                   baseRingSection,
                   dynamicRingSection,
                   i_ringBuf1,
                   i_ringBuf2,
                   i_ringBuf3,
                   idxFeatureMap,
                   ringIdFeatureVecMap,
                   numberOfFeatures,
                   ringId,
                   attrDdLevel );

        FAPI_ASSERT( ((l_fapiRc == FAPI2_RC_SUCCESS) ||
                      ((uint32_t) l_fapiRc == RC_XIPC_NO_RING_FOUND)),
                     fapi2::XIPC_DYNAMIC_INIT_FAILED().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(ringId),
                     "process_base_and_dynamic_rings failed for "
                     "ringId=0x%0x w/rc=0x%08x",
                     ringId, (uint32_t)l_fapiRc);

        if (l_fapiRc == FAPI2_RC_SUCCESS)
        {
            l_rc = tor_append_ring(
                       io_ringSectionBuf,
                       l_maxRingSectionSize,
                       ringId,
                       0xff,
                       i_ringBuf1 );

            FAPI_ASSERT( l_rc == TOR_SUCCESS ||
                         l_rc == TOR_INVALID_CHIPLET_TYPE ||
                         l_rc == TOR_RING_HAS_DERIVS,
                         fapi2::XIPC_TOR_APPEND_RING_FAILED().
                         set_CHIP_TARGET(i_procTarget).
                         set_TOR_RC(l_rc).
                         set_RING_ID(ringId).
                         set_OCCURRENCE(1),
                         "tor_append_ring() failed in "
                         "process_base_and_dynamic_rings w/rc=%d "
                         "for ringId=0x%x",
                         l_rc, ringId );

            io_ringSectionBufSize = be32toh(((TorHeader_t*)io_ringSectionBuf)->size);

            switch (l_rc)
            {
                case TOR_SUCCESS:
                    FAPI_IMP("A Base or Dynamic ring w/ringId=0x%x was appended"
                             " and now ringSection->size=%u",
                             ringId, io_ringSectionBufSize);
                    break;

                case TOR_INVALID_CHIPLET_TYPE:
                    FAPI_IMP("A Base or Dynamic ring w/ringId=0x%x was skipped"
                             " because its an invalid chiplet for this sysPhase=%u",
                             ringId, i_sysPhase);
                    break;

                case TOR_RING_HAS_DERIVS:
                    FAPI_IMP("A Base or Dynamic ring w/ringId=0x%x was skipped"
                             " because its a [root] ring w/derivatives",
                             ringId);
                    break;

                default:
                    FAPI_ASSERT( false,
                                 fapi2::XIPC_CODE_BUG().
                                 set_CHIP_TARGET(i_procTarget).
                                 set_OCCURRENCE(2),
                                 "Code bug(2): Messed up RC handling in assoc code. Fix code!" );
                    break;
            }

        }
    }

    //
    // Produce the "anticipatory" dynamic inits debug list and, so far, append it only to
    // the Seeprom image. (Later, maybe PM team special delivery?)
    //
    ringIdFeatListSize = ringIdFeatureVecMap.size() * (sizeof(ringIdFeatureVecMap));

    FAPI_DBG("ringIdFeatListSize = %u", ringIdFeatListSize);

    if (ringIdFeatListSize > RINGID_FEAT_LIST_MAX_SIZE)
    {
        FAPI_ASSERT( false,
                     fapi2::XIPC_FEATURE_LIST_SIZE_OVERFLOW().
                     set_CHIP_TARGET(i_procTarget).
                     set_FEAT_LIST_SIZE(ringIdFeatListSize).
                     set_FEAT_LIST_MAX_SIZE(RINGID_FEAT_LIST_MAX_SIZE),
                     "The ringId-feature list size(=%u) has exceeded the max allowed"
                     " size(=%u).",
                     ringIdFeatListSize, RINGID_FEAT_LIST_MAX_SIZE );
    }

    ringIdFeatList = new uint8_t[ringIdFeatListSize];

    for( std::map<RingId_t, uint64_t>::iterator it = ringIdFeatureVecMap.begin();
         it != ringIdFeatureVecMap.end();
         it++ )
    {
        FAPI_IMP("(ringId,featureVecAcc)=(0x%x,0x%0llx)\n", it->first, it->second);

        RingId_t* pKey = (RingId_t*)ringIdFeatList;
        *pKey = htobe16(it->first);
        ringIdFeatList += sizeof(it->first);

        uint64_t* pData = (uint64_t*)ringIdFeatList;
        *pData = htobe64(it->second);
        ringIdFeatList += sizeof(it->second);
    }

    // Append .ringidfeatlist section to the Seeprom image
    if (i_sysPhase ==  SYSPHASE_HB_SBE)
    {
        l_rc = p9_xip_append( io_image,
                              P9_XIP_SECTION_SBE_RINGIDFEATLIST,
                              ringIdFeatList,
                              ringIdFeatListSize,
                              l_maxImageSize,
                              &l_sectionOffset,
                              0 );

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_XIP_API_MISC_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_RC(l_rc).
                     set_OCCURRENCE(4),
                     "p9_xip_append() failed (4) w/rc=0x%08x",
                     (uint32_t)l_rc );
    }



    //////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Append VPD rings to io_ringSectionBuf
    // System phase:       All phases
    //------------------------------------------------------------------------
    // Notes:
    // Do some sysPhase specific initial operations:
    // - Determine if there GPTR support, and overlays support, through Mvpd
    //////////////////////////////////////////////////////////////////////////

    //
    // First, make sure the Mvpd rings RT version agrees with code header.
    //

    // Fetching ring table version from code header
    mvpdRtvFromCode = ringid_get_ring_table_version_mvpd();

    // Fetching ring table version from the MVPD
    for(uint8_t i = 0; i < MVPD_RING_TYPES; i++)
    {
        if(i == MVPD_RING_PDG)
        {
            mvpdKeyword = fapi2::MVPD_KEYWORD_PDG;
        }
        else if(i == MVPD_RING_PDP)
        {
            continue; // Reinstate next line when HB supports #P
            //mvpdKeyword = fapi2::MVPD_KEYWORD_PDP;
        }
        else if(i == MVPD_RING_PDR)
        {
            mvpdKeyword = fapi2::MVPD_KEYWORD_PDR;
        }
        else
        {
            mvpdKeyword = fapi2::MVPD_KEYWORD_UNDEFINED;
        }

        FAPI_TRY(getMvpdField(fapi2::MVPD_RECORD_CP00,
                              mvpdKeyword,
                              i_procTarget,
                              NULL,
                              sizeofPartialKwdData),
                 "getMvpdField failed for CP00(1) record with "
                 "keyword=0x%0x, w/rc=0x%08x",
                 mvpdKeyword, (uint64_t)fapi2::current_err);

        partialKwdData = new uint8_t[sizeofPartialKwdData]();

        FAPI_TRY(getMvpdField(fapi2::MVPD_RECORD_CP00,
                              mvpdKeyword,
                              i_procTarget,
                              partialKwdData,
                              sizeofPartialKwdData),
                 "getMvpdField failed for CP00(2) record with "
                 "keyword=0x%0x, w/rc=0x%08x",
                 mvpdKeyword, (uint64_t)fapi2::current_err);

        mvpdRtvFromMvpd = partialKwdData[0];

        FAPI_ASSERT( mvpdRtvFromMvpd <= mvpdRtvFromCode,
                     fapi2::XIPC_MVPD_RINGTABLE_VERSION_MISMATCH().
                     set_CHIP_TARGET(i_procTarget).
                     set_RINGTABLE_VERSION_MVPD(mvpdRtvFromMvpd).
                     set_RINGTABLE_VERSION_CODE(mvpdRtvFromCode).
                     set_MVPD_RING_TYPE(mvpdKeyword),
                     "p10_ipl_customize: MVPD ringtable version 0x%0x, "
                     "doesn't match with code header ring table version 0x%0x"
                     " for MVPD ringType 0x%0x",
                     mvpdRtvFromMvpd, mvpdRtvFromCode, mvpdKeyword );

        delete partialKwdData;
        partialKwdData = NULL;
    }

    //
    // Now, append the Mvpd rings into the customized ringSection
    //
    switch (i_sysPhase)
    {

        case SYSPHASE_HB_SBE:

            FAPI_DBG("Size of SBE .rings section before VPD update: %u (max size allowed: %u)",
                     io_ringSectionBufSize, l_maxRingSectionSize);

            //----------------------------------------
            // Append VPD Rings to the .rings section
            //----------------------------------------

            l_fapiRc = fetch_and_insert_vpd_rings( i_procTarget,
                                                   io_ringSectionBuf,
                                                   io_ringSectionBufSize, // Running section size
                                                   l_maxRingSectionSize,  // Max section size
                                                   i_hwImage,
                                                   i_sysPhase,
                                                   i_ringBuf1,
                                                   i_ringBufSize1,
                                                   i_ringBuf2,
                                                   i_ringBufSize2,
                                                   i_ringBuf3,
                                                   i_ringBufSize3,
                                                   io_bootCoreMask );

            FAPI_DBG("-----------------------------------------------------------------------");
            FAPI_DBG("bootCoreMask:  Requested=0x%08X  Final=0x%08X",
                     l_requestedBootCoreMask, io_bootCoreMask);
            FAPI_DBG("-----------------------------------------------------------------------");

            if (l_fapiRc)
            {

                if ((uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW)
                {
                    FAPI_DBG("p10_ipl_customize(): SBE image is full. Ran out of space appending VPD rings"
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
                        if (io_bootCoreMask & ((CORE0_MASK) >> iCore))
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
                                 "SBE image buffer would overflow before reaching the minimum required"
                                 " number of EC boot cores" );

                    fapi2::current_err = FAPI2_RC_SUCCESS;
                }
                else
                {
                    fapi2::current_err = l_fapiRc;
                }

                goto fapi_try_exit;
            }

            // More size code sanity checks of section and image sizes.
            FAPI_ASSERT( io_ringSectionBufSize <= l_maxRingSectionSize,
                         fapi2::XIPC_RING_SECTION_SIZING().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_SECTION_SIZE(io_ringSectionBufSize).
                         set_RING_SECTION_BUF_SIZE(l_ringSectionBufSize).
                         set_MAX_RING_SECTION_SIZE(l_maxRingSectionSize).
                         set_OCCURRENCE(2),
                         "Code bug: ringSectionBufSize(=%d) > maxRingSectionSize(=%d) in HB_SBE (Occurrence 2)",
                         io_ringSectionBufSize, l_maxRingSectionSize );

            FAPI_ASSERT( (l_imageSizeWithoutRings + io_ringSectionBufSize) <= l_maxImageSize,
                         fapi2::XIPC_IMAGE_SIZING().
                         set_CHIP_TARGET(i_procTarget).
                         set_IMAGE_SIZE_WITHOUT_RINGS(l_imageSizeWithoutRings).
                         set_RING_SECTION_SIZE(io_ringSectionBufSize).
                         set_MAX_IMAGE_SIZE(l_maxImageSize),
                         "Code bug: SBE imageSize would exceed maxImageSize" );

            FAPI_DBG( "SBE image details: io_ringSectionBufSize=%d, l_imageSizeWithoutRings=%d,"
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

            FAPI_DBG( "SBE image size after VPD updates: %d", l_currentImageSize );

            FAPI_ASSERT( l_currentImageSize <= l_maxImageSize,
                         fapi2::XIPC_IMAGE_TOO_LARGE().
                         set_CHIP_TARGET(i_procTarget).
                         set_IMAGE_SIZE(l_currentImageSize).
                         set_MAX_IMAGE_SIZE(l_maxImageSize).
                         set_OCCURRENCE(2),
                         "SBE image size after VPD updates (=%d) exceeds max image size (=%d)",
                         l_currentImageSize, l_maxImageSize );

            break;

        case SYSPHASE_RT_QME:

            FAPI_DBG("Size of QME .rings section before VPD update: %d", io_ringSectionBufSize);

            //----------------------------------------
            // Append VPD Rings to the .rings section
            //----------------------------------------

            l_fapiRc = fetch_and_insert_vpd_rings( i_procTarget,
                                                   io_ringSectionBuf,
                                                   io_ringSectionBufSize, // Running ring section size
                                                   l_maxRingSectionSize,  // Max allowed section size
                                                   i_hwImage,
                                                   i_sysPhase,
                                                   i_ringBuf1,
                                                   i_ringBufSize1,
                                                   i_ringBuf2,
                                                   i_ringBufSize2,
                                                   i_ringBuf3,
                                                   i_ringBufSize3,
                                                   io_bootCoreMask );

            FAPI_DBG("Size of QME .rings section after VPD update: %d", io_ringSectionBufSize );

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
                             "Ran out of space appending VPD rings to QME .rings section" );

                fapi2::current_err = l_fapiRc;
                goto fapi_try_exit;

            }

            // More size code sanity checks of section and image sizes.
            FAPI_ASSERT( io_ringSectionBufSize <= l_maxRingSectionSize,
                         fapi2::XIPC_RING_SECTION_SIZING().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_SECTION_SIZE(io_ringSectionBufSize).
                         set_RING_SECTION_BUF_SIZE(l_ringSectionBufSize).
                         set_MAX_RING_SECTION_SIZE(l_maxRingSectionSize).
                         set_OCCURRENCE(3),
                         "Code bug: QME ring section size(=%d) > maxRingSectionSize(=%d)"
                         " in RT_QME (Occurrence 3)",
                         io_ringSectionBufSize, l_maxRingSectionSize );

            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::XIPC_INVALID_SYSPHASE_PARM().
                         set_CHIP_TARGET(i_procTarget).
                         set_SYSPHASE(i_sysPhase).
                         set_OCCURRENCE(3),
                         "Caller bug: Caller supplied unsupported value of sysPhase=%u"
                         " (Occurrence 3)",
                         i_sysPhase );

            break;
    }



    ///////////////////////////////////////////////////////////////////////////
    // Done
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        io_imageSize = l_currentImageSize;
        FAPI_DBG("Final customized SBE image size: %d", io_imageSize);
    }

    FAPI_DBG("Final customized .rings section size: %d", io_ringSectionBufSize);

fapi_try_exit:
    FAPI_IMP("Exiting p10_ipl_customize w/rc=0x%08x", (uint32_t)fapi2::current_err);
    return fapi2::current_err;

}
