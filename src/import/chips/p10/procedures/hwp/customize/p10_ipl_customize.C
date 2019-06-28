/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_ipl_customize.C $ */
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
#include <p10_ring_identification.H>
#include <p10_tor.H>
#include <p10_scan_compression.H>
#include <p10_infrastruct_help.H>

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
    uint32_t l_maxRingByteSize = MAX_RING_BUF_SIZE;
    uint32_t l_ovlyUncmpSize = 0;

    // As we'll be using tor_get_single_ring() with P9_XIP_MAGIC_SEEPROM
    // to identify TOR layout for overlays/overrides sections we have to define
    // following variables (though unused in this context) to support the API.
    uint8_t  l_instanceId = 0; // Unused param (instance id)
    uint32_t l_ringBlockSize = 0xFFFFFFFF;  // Unused param (ringBlockSize)

    FAPI_DBG("Entering get_overlays_ring");

    // Get Gptr overlay ring from overlays section into ringBuf2
    l_rc = tor_get_single_ring(
               i_overlaysSection,
               i_ddLevel,
               i_ringId,
               l_instanceId,
               io_ringBuf2,  //Has RS4 Gptr overlay ring on return
               l_ringBlockSize);

    if (l_rc == INFRASTRUCT_RC_SUCCESS)
    {
        FAPI_DBG("Successfully found Gptr ringId=0x%x of iv_size=%d bytes", i_ringId,
                 be16toh(((CompressedScanData*)(*io_ringBuf2))->iv_size));

        // Decompress Gptr overlay ring
        l_rc = _rs4_decompress(
                   (uint8_t*)(*io_ringBuf3),
                   (uint8_t*)(*io_ringBuf3) + l_maxRingByteSize / 2,
                   l_maxRingByteSize / 2, // Max allowable raw ring size (in bytes)
                   &l_ovlyUncmpSize,      // Actual raw ring size (in bits) on return.
                   (CompressedScanData*)(*io_ringBuf2) );

        FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                     fapi2::XIPC_RS4_DECOMPRESS_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_MAX_RING_BYTE_SIZE(l_maxRingByteSize).
                     set_LOCAL_RC(l_rc).
                     set_OCCURRENCE(1),
                     "rs4_decompress() failed w/rc=%i for "
                     "ringId=0x%x, maxRingByteSize=%d, occurrence=1",
                     l_rc, i_ringId, l_maxRingByteSize );

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


// Function: apply_overlays_ring()
// @brief: This function applies the Gptr overlay ring from the overlays section to the Gptr
//         ring from the Mvpd.
//
// Parameter list:
// const fapi2::Target &i_target:    Processor chip target.
// void*    io_vpdRing:      Contains Mvpd RS4 ring on input and final Vpd RS4 ring on output
// void*    io_ringBuf2:     Work buffer (has raw Mvpd ring on output)
// void*    i_ovlyRawRing:   Raw data+care overlay ring
// uint32_t i_ovlyUncmpSize: Overlay/gptr uncompressed ring size
#ifdef WIN32
int apply_overlays_ring(
    int i_procTarget,
#else
fapi2::ReturnCode apply_overlays_ring(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#endif
    void*    io_vpdRing,
    void*    io_ringBuf2,
    void*    i_ovlyRawRing,
    uint32_t i_ovlyUncmpSize)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    int l_rc = INFRASTRUCT_RC_SUCCESS;
    uint32_t maxRingByteSize = MAX_RING_BUF_SIZE;
    uint8_t* dataVpd = (uint8_t*)io_ringBuf2;
    uint8_t* careVpd = (uint8_t*)io_ringBuf2 + maxRingByteSize / 2;
    uint8_t* dataOvly = NULL;
    uint8_t* careOvly = NULL;
    uint32_t vpdUncmpSize = 0;

    FAPI_DBG("Entering apply_overlays_ring");

    // Get the data+care raw Gptr overlay ring
    dataOvly = (uint8_t*)i_ovlyRawRing;
    careOvly = (uint8_t*)i_ovlyRawRing + maxRingByteSize / 2;

    // Decompress Gptr Mvpd ring
    l_rc = _rs4_decompress(
               dataVpd,
               careVpd,
               maxRingByteSize / 2, // Max allowable raw ring size (in bytes)
               &vpdUncmpSize,         // Actual raw ring size (in bits) on return.
               (CompressedScanData*)io_vpdRing );

    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                 fapi2::XIPC_RS4_DECOMPRESS_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_RING_ID(be16toh(((CompressedScanData*)io_vpdRing)->iv_ringId)).
                 set_MAX_RING_BYTE_SIZE(maxRingByteSize).
                 set_LOCAL_RC(l_rc).
                 set_OCCURRENCE(2),
                 "rs4_decompress() for gptr: Failed w/rc=%i for ringId=0x%x,"
                 "maxRingByteSize=%d, occurrence=2",
                 l_rc, be16toh(((CompressedScanData*)io_vpdRing)->iv_ringId), maxRingByteSize );

    FAPI_DBG("Mvpd raw ring size=%d bits)", vpdUncmpSize);

    // Compare uncompressed Mvpd ring and overlay ring sizes
    FAPI_ASSERT( i_ovlyUncmpSize == vpdUncmpSize,
                 fapi2::XIPC_MVPD_OVLY_RAW_RING_SIZE_MISMATCH_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_MVPD_SIZE(vpdUncmpSize).
                 set_OVLY_SIZE(i_ovlyUncmpSize),
                 "MVPD raw size (=%d) and overlay raw size (=%d) don't match.",
                 vpdUncmpSize, i_ovlyUncmpSize);

    // Perform Overlay operation:
    // if overlay data is '1' and care is '1', set vpd data to '1' and care to '1'
    // if overlay data is '0' and care is '1', set vpd data to '0' and care to '0'
    // Note that the latter can be done bcoz GPTR rings are scanned on flushed latches.
    // And since writing a 0 data to a flushed latch result in no change, hence we can
    // save RS4 ring space in image as well as improve scan time by clearing the
    // associated care bit so we instead rotate through the bit.
    int i;

    for (i = 0; i < (int)vpdUncmpSize / 8; i++)
    {
        if (careOvly[i] > 0)
        {
            for (int j = 0; j < 8; j++)
            {
                if (careOvly[i] & (0x80 >> j))
                {
                    uint8_t temp = (dataOvly[i] & (0x80 >> j));

                    if (temp)
                    {
                        dataVpd[i] |= (0x80 >> j);
                        careVpd[i] |= (0x80 >> j);
                    }
                    else
                    {
                        dataVpd[i] &= ~(0x80 >> j);
                        careVpd[i] &= ~(0x80 >> j);
                    }
                }
            }
        }
    }

    // Processing remainder of data & care bits (mod 8)
    if (vpdUncmpSize % 8)
    {
        i = (int)vpdUncmpSize / 8;

        careOvly[i] &= ~(0xFF << (8 - (vpdUncmpSize % 8)));

        if (careOvly[i] > 0)
        {
            for (int j = 0; j < (int)vpdUncmpSize % 8; j++)
            {
                if (careOvly[i] & (0x80 >> j))
                {
                    uint8_t temp = (dataOvly[i] & (0x80 >> j));

                    if (temp)
                    {
                        dataVpd[i] |= (0x80 >> j);
                        careVpd[i] |= (0x80 >> j);
                    }
                    else
                    {
                        dataVpd[i] &= ~(0x80 >> j);
                        careVpd[i] &= ~(0x80 >> j);
                    }
                }
            }
        }
    }

    // Recompress vpd ring
    l_rc = _rs4_compress(
               (CompressedScanData*)io_vpdRing,
               maxRingByteSize,
               dataVpd,
               careVpd,
               vpdUncmpSize,
               be32toh(((CompressedScanData*)io_vpdRing)->iv_scanAddr),
               be16toh(((CompressedScanData*)io_vpdRing)->iv_ringId),
               UNDEFINED_RS4_SELECTOR,
               RS4_IV_TYPE_CMSK_NON_CMSK |
               RS4_IV_TYPE_OVRD_FLUSH |
               RS4_IV_TYPE_SEL_BASE );

    FAPI_ASSERT( l_rc == 0,
                 fapi2::XIPC_RS4_COMPRESS_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_RING_ID(0xff).
                 set_CHIPLET_ID(0xff).
                 set_LOCAL_RC(l_rc).
                 set_OCCURRENCE(2),
                 "rs4_compress() for gptr: Failed w/rc=%i for "
                 "ringId=0xff, chipletId=0xff, occurrence=2 ", l_rc );

fapi_try_exit:
    FAPI_DBG("Exiting apply_overlays_ring");
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

        // Apply overlays operations
        FAPI_TRY( apply_overlays_ring(
                      i_procTarget,
                      io_vpdRing,
                      io_ringBuf2, //We can now destroy ovlyRs4Ring
                      l_ovlyRawRing,
                      l_ovlyUncmpSize),
                  "apply_overlays_ring() failed w/rc=0x%08x for ringId=0x%x",
                  (uint32_t)current_err, l_vpdRingId);
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
//  uint8_t    i_sysPhase:           ={HB_SBE, RT_QME, RT_XGPE}
//  void*      i_vpdRing:            VPD ring buffer.
//  uint32_t   i_vpdRingSize:        Size of VPD ring buffer.
//  void*      i_ringBuf2:           Ring work buffer.
//  uint32_t   i_ringBufSize2:       Size of ring work buffer.
//  void*      i_ringBuf3:           Ring work buffer.
//  uint32_t   i_ringBufSize3:       Size of ring work buffer.
//  uint8_t    i_chipletId:          Chiplet Id
//  const RingIdList i_ring:         The ring ID list (#G or #R list)
//  uint8_t&   io_ringStatusInMvpd:   EQ/EC ring status - found/notfound/redundant in mvpd
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
    void*           i_overlaysSection,
    uint8_t         i_ddLevel,
    uint8_t         i_sysPhase,
    void*           i_vpdRing,
    uint32_t        i_vpdRingSize,
    void*           i_ringBuf2,
    uint32_t        i_ringBufSize2,
    void*           i_ringBuf3,
    uint32_t        i_ringBufSize3,
    uint8_t         i_chipletId,
    const RingIdList     i_ring,
    uint8_t&        io_ringStatusInMvpd,
    bool&           i_bImgOutOfSpace,
    uint32_t&       io_bootCoreMask )
{
    ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err  = fapi2::FAPI2_RC_SUCCESS;
    int        l_rc = 0;

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

    // Initialize data buffers to zeros
    memset(i_vpdRing,  0, i_vpdRingSize);
    memset(i_ringBuf2, 0, i_ringBufSize2);
    memset(i_ringBuf3, 0, i_ringBufSize3);

    /////////////////////////////////////////////////////////////////////
    // Fetch rings from the MVPD:
    /////////////////////////////////////////////////////////////////////
    l_fapiRc = getMvpdRing( i_procTarget,
                            MVPD_RECORD_CP00,
                            l_mvpdKeyword,
                            i_chipletId,
                            i_ring.ringId,
                            (uint8_t*)i_vpdRing,
                            l_vpdRingSize );

    ///////////////////////////////////////////////////////////////////////
    // Append VPD ring to the ring section
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

        // Check for Gptr rings (ovly-gptr) in overlays section and if found
        // process it over mvpd-gptr ring.
        if (i_ring.vpdRingClass == VPD_RING_CLASS_GPTR_NEST ||
            i_ring.vpdRingClass == VPD_RING_CLASS_GPTR_EQ ||
            i_ring.vpdRingClass == VPD_RING_CLASS_GPTR_EC)
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

        if ( ((CompressedScanData*)i_vpdRing)->iv_magic != htobe16(RS4_MAGIC) )
        {
            l_rc = INFRASTRUCT_RC_USER_ERROR;
        }
        else
        {
            // Check if ring is a flush ring, i.e. if it is redundant, meaning that it will
            // result in no change.
            l_rc = rs4_redundant((CompressedScanData*)i_vpdRing, &redundant);
        }

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_RS4_REDUNDANT_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ring.ringId).
                     set_CHIPLET_ID(i_chipletId).
                     set_LOCAL_RC(l_rc).
                     set_OCCURRENCE(1),
                     "rs4_redundant: Failed w/rc=%i for "
                     "ringId=0x%x, chipletId=0x%02X, occurrence=1 ",
                     l_rc, i_ring.ringId, i_chipletId );

        // Regarding Gptr rings processing:
        // At this stage i_vpdRing (mvpd-gptr) has already been processed w/wo ovly-gptr,
        // so now newly modified(if any) i_vpdRing could be check for redundancy
        // like any other non-gptr rings.
        if (redundant)
        {
            // Update for ring found in mvpd contains redundant data
            io_ringStatusInMvpd = RING_REDUNDANT;

            FAPI_DBG("Skipping redundant VPD ring: ringId=0x%x, chipletId=0x%02X ", i_ring.ringId, i_chipletId);
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
        uint8_t l_chipletTorId = i_chipletId - i_ring.instanceIdMin;

        l_rc = tor_append_ring(
                   i_ringSection,
                   io_ringSectionSize, // In: Exact size. Out: Updated size.
                   i_ring.ringId,
                   l_chipletTorId,  // Chiplet instance TOR Index
                   i_vpdRing );     // The VPD RS4 ring container

        FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                     fapi2::XIPC_TOR_APPEND_RING_FAILED().
                     set_CHIP_TARGET(i_procTarget).
                     set_TOR_RC(l_rc).
                     set_RING_ID(i_ring.ringId).
                     set_OCCURRENCE(1),
                     "tor_append_ring() failed in sysPhase=%d w/rc=%d for ringId=0x%x",
                     i_sysPhase, l_rc, i_ring.ringId );

        FAPI_INF("Successfully added VPD ring: (ringId,chipletId)=(0x%02X,0x%02X)",
                 i_ring.ringId, i_chipletId);

        FAPI_DBG("(After tor_append) io_ringSectionSize = %d", io_ringSectionSize);
    }
    else if ((uint32_t)l_fapiRc == RC_MVPD_RING_NOT_FOUND)
    {
        // Update for ring not found in mvpd
        io_ringStatusInMvpd = RING_NOT_FOUND;

        // No match, do nothing. But since rare, trace out.
        FAPI_DBG("_fetch_and_insert_vpd_rings():"
                 "(ringId,chipletId)=(0x%X,0x%X) not found.",
                 i_ring.ringId, i_chipletId);

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
              "Error: Attribute ATTR_EC failed w/rc=0x%08x",
              (uint64_t)current_err );

    l_rc = p9_xip_get_section(i_hwImage, P9_XIP_SECTION_HW_OVERLAYS, &l_xipSection, o_ddLevel);

    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                 fapi2::XIPC_XIP_GET_SECTION_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_XIP_RC(l_rc).
                 set_SECTION_ID(P9_XIP_SECTION_HW_OVERLAYS).
                 set_DDLEVEL(o_ddLevel).
                 set_OCCURRENCE(2),
                 "p9_xip_get_section() failed (2) w/rc=0x%08X getting .overlays"
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

    // Variables needed to provide updated bootCoreMask
    VpdInsInsertProg_t l_instanceVpdRing  = {};
    uint8_t l_ringStatusInMvpd            = RING_SCAN;
    bool    l_bImgOutOfSpace              = false;
    uint8_t l_eqNumWhenOutOfSpace         = 0xF;   // Assign invalid value to check for correctness of value when used
    RingType_t l_ringType = INVALID_RING_TYPE;

    // Initialize activeCoreMask to be filled up with EC column filling as it progresses
    uint32_t l_activeCoreMask  = 0x0;
    uint32_t l_bootCoreMaskMin = 0x0;
    void*    l_overlaysSection;
    uint8_t  l_ddLevel = UNDEFINED_DD_LEVEL;


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

    // 1- Add all common rings
    // -----------------------
    l_ringType = COMMON_RING;

    for (auto vpdType = 0; vpdType < NUM_OF_VPD_TYPES; vpdType++)
    {
        const RingIdList* l_ringIdList = ALL_VPD_RINGS[vpdType].ringIdList;
        auto l_ringIdListSize         = ALL_VPD_RINGS[vpdType].ringIdListSize;
        uint8_t l_instanceIdMax;
        uint8_t l_chipletId;

        for (size_t iRing = 0; iRing < l_ringIdListSize; iRing++)
        {
            if ( l_ringIdList[iRing].vpdRingClass != VPD_RING_CLASS_EQ_INS &&
                 l_ringIdList[iRing].vpdRingClass != VPD_RING_CLASS_EC_INS )
            {
                l_instanceIdMax = l_ringIdList[iRing].instanceIdMax;

                for (l_chipletId = l_ringIdList[iRing].instanceIdMin;
                     l_chipletId <= l_instanceIdMax; l_chipletId++)
                {
                    // Fetch common ring
                    // - Fetch all VPD rings for SBE.
                    // - Fetch only EC+EQ VPD rings for QME.

                    if ( i_sysPhase == SYSPHASE_HB_SBE   ||
                         ( i_sysPhase == SYSPHASE_RT_QME &&
                           ( l_ringIdList[iRing].vpdRingClass == VPD_RING_CLASS_EC ||
                             l_ringIdList[iRing].vpdRingClass == VPD_RING_CLASS_GPTR_EC ||
                             l_ringIdList[iRing].vpdRingClass == VPD_RING_CLASS_EQ ||
                             l_ringIdList[iRing].vpdRingClass == VPD_RING_CLASS_GPTR_EQ ) ) )
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
                                       l_chipletId,
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

    // Add all instance [QUAD-level] rings in order - EQ->EC.
    // Looking at the bootCoreMask start adding EQ first followed
    // by EC VPD ring insertion in order.
    // For common rings already completed in above step #1.
    // The step #2 instance part is updated looping over chipletId
    // to fill up one core chipletId "column" at a time (RTC158106).

    l_ringType = INSTANCE_RING;

    {
        // Initialize ring id list from VPD_RINGS[1]
        const RingIdList* l_ringIdList = ALL_VPD_RINGS[1].ringIdList;
        auto l_ringIdListSize         = ALL_VPD_RINGS[1].ringIdListSize;

        // Initialize local ring eq, ec to first member of ring list
        RingIdList l_ringEQ = l_ringIdList[0];
        RingIdList l_ringEC = l_ringIdList[0];

        // Initialize flag for eq/ex/ec instances for entry found in ring list
        bool l_flagEQInstanceFound = false;
        bool l_flagECInstanceFound = false;

        uint8_t l_chipletId;

        // Loop for EQ/EC filling
        for (auto eq = 0; eq < NUM_OF_QMES; eq++)
        {
            // For EQ instances
            if ( (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_QME) )
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

                    FAPI_DBG("EQ no. %02d; InstanceId:0x%02x; RingName:%s ", eq, l_chipletId,
                             l_ringEQ.ringName);

                    if ( ((0x0000000F << ((NUM_OF_QMES - 1)*CORES_PER_QME)) >>
                          ((l_chipletId - l_ringEQ.instanceIdMin)*CORES_PER_QME)) &
                         io_bootCoreMask )
                    {
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
                                       l_chipletId,
                                       l_ringEQ,
                                       l_ringStatusInMvpd,
                                       l_bImgOutOfSpace,
                                       io_bootCoreMask );

                        // Update EQ instance var for ring found in mvpd
                        if (l_ringStatusInMvpd == RING_FOUND)
                        {
                            l_instanceVpdRing.EQ |=
                                (0x00F00000 >> (eq * CORES_PER_QME));
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

            for (auto ec = (4 * eq); ec < (4 * (eq + 1)); ec++)
            {
                if ( (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_QME) )
                {
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
                        l_chipletId = l_ringEC.instanceIdMin + ec;
                        FAPI_DBG("EC no. %02d; InstanceId:0x%02x; RingName:%s ",
                                 ec, l_chipletId, l_ringEC.ringName);

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
                                           l_overlaysSection,
                                           l_ddLevel,
                                           i_sysPhase,
                                           i_vpdRing,
                                           i_vpdRingSize,
                                           i_ringBuf2,
                                           i_ringBufSize2,
                                           i_ringBuf3,
                                           i_ringBufSize3,
                                           l_chipletId,
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

                    } // if (l_flagECInstanceFound == true)

                } //if ( (i_sysPhase == SYSPHASE_HB_SBE || i_sysPhase == SYSPHASE_RT_QME) )

            } //for (ec=4*eq; ec=4*(eq+1); ec++)

        }

    }

fapi_try_exit:

    if( (l_ringType == COMMON_RING) &&
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
    else if( (l_ringType == INSTANCE_RING) &&
             (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS) )
    {
        //Error handling: Any other 'unknown/unexpected' error reported
        io_bootCoreMask = l_activeCoreMask;
        FAPI_IMP("bootCoreMask value: 0x%08x", io_bootCoreMask);
        FAPI_DBG("Exiting fetch_and_insert_vpd_rings");
        return fapi2::current_err;
    }

    // Display all EQ/EC instance rings found in mvpd for given bootCoreMask
    FAPI_DBG("List of instance rings available in mvpd (as per bootCoreMask):");
    FAPI_DBG("Domain | Domain rings in Mvpd");
    FAPI_DBG("-----------------------------");
    FAPI_DBG("EQ     | 0x%08x", l_instanceVpdRing.EQ);
    FAPI_DBG("EC     | 0x%08x", l_instanceVpdRing.EC);
    FAPI_DBG("-----------------------------");

    l_bootCoreMaskMin = ~(l_instanceVpdRing.EQ |
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
                 ((l_instanceVpdRing.chipletUnderProcess == 0) ? "EQ" : "EC"));
        FAPI_DBG("Chiplet number under process at image overflow  : %d", l_instanceVpdRing.chipletNumUnderProcess);
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
                                      l_instanceVpdRing.chipletNumUnderProcess;

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
                                  (EC_POSITION >>
                                   (l_instanceVpdRing.chipletNumUnderProcess + 1))))
                            {
                                l_activeCoreMask |= ( (EC_POSITION >>
                                                       (l_instanceVpdRing.chipletNumUnderProcess + 1)) &
                                                      io_bootCoreMask);
                            }

                        case 1:
                            break;

                        default:
                            FAPI_DBG("Incorrect EC mask. It should not come here");
                            break;
                    } // switch (l_ecPos)

                }   // else if (l_instanceVpdRing.chipletUnderProcess == EC_CHIPLET)

            }
            while(0);   // Process EQ and other chiplets in current quad

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
    uint8_t   i_sysPhase,
    uint8_t   i_modeBuild,
    void*     i_ringBuf1,
    uint32_t  i_ringBufSize1,
    void*     i_ringBuf2,
    uint32_t  i_ringBufSize2,
    void*     i_ringBuf3,
    uint32_t  i_ringBufSize3,
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
    int             l_rc = 0; // Non-fapi RC

    int mainSectionID = UNDEFINED_IPL_IMAGE_SID; // Represents the nested PPE image
    int subSectionID  = UNDEFINED_IPL_IMAGE_SID; // Represents .rings within nested image
    P9XipSection    iplImgSection;
    //Suggested replacement name:
    //IplImgSection   iplImgSection; // Formerly: P9XipSection xipSection.
    uint32_t        l_inputImageSize;
    uint32_t        l_imageSizeWithoutRings;
    uint32_t        l_currentImageSize;
    uint32_t        l_maxImageSize = 0; // Attrib adjusted local value of MAX_SEEPROM_IMAGE_SIZE
    uint32_t        l_maxRingSectionSize;
    uint32_t        l_sectionOffset = 1;
    uint32_t        attrMaxSbeSeepromSize = 0;
    uint32_t        l_requestedBootCoreMask = (i_sysPhase == SYSPHASE_HB_SBE) ? io_bootCoreMask : 0x00FFFFFF;
    uint8_t         attrDdLevel = UNDEFINED_DD_LEVEL; // Used for host services
    uint32_t        l_sizeMvpdDDField = 0;
    uint8_t*        l_decimalDDData = nullptr;
    uint8_t*        l_fullDDData = nullptr;
    uint8_t         l_mvpdDD = 0;
    uint8_t         l_chipName = 0;
    uint32_t        l_sizeMvpdCIField = 0;
    uint8_t*        l_fullCIData = nullptr;

    FAPI_IMP ("Entering p10_ipl_customize w/sysPhase=%d...", i_sysPhase);


    // Make copy of the requested bootCoreMask
    io_bootCoreMask = l_requestedBootCoreMask;


    //-------------------------------------------
    // Check some input buffer parameters:
    // - sysPhase is checked later
    // - log the initial image size
    // - more buffer size checks in big switch()
    //-------------------------------------------

    FAPI_ASSERT( i_hwImage != NULL &&
                 io_image != NULL &&
                 io_ringSectionBuf != NULL &&
                 i_ringBuf1 != NULL &&
                 i_ringBuf2 != NULL &&
                 i_ringBuf3 != NULL,
                 fapi2::XIPC_INVALID_INPUT_BUFFER_PARM().
                 set_CHIP_TARGET(i_procTarget).
                 set_HW_IMAGE(i_hwImage).
                 set_IMAGE_BUF(io_image).
                 set_RING_SECTION_BUF(io_ringSectionBuf).
                 set_RING_BUF1(i_ringBuf1).
                 set_RING_BUF2(i_ringBuf2).
                 set_RING_BUF3(i_ringBuf3),
                 "One or more invalid input buffer pointers:\n"
                 "  i_hwImage=0x%016llx\n"
                 "  io_image=0x%016llx\n"
                 "  io_ringSectionBuf=0x%016llx\n"
                 "  i_ringBuf1=0x%016llx\n"
                 "  i_ringBuf2=0x%016llx\n"
                 "  i_ringBuf3=0x%016llx\n",
                 (uintptr_t)i_hwImage,
                 (uintptr_t)io_image,
                 (uintptr_t)io_ringSectionBuf,
                 (uintptr_t)i_ringBuf1,
                 (uintptr_t)i_ringBuf2,
                 (uintptr_t)i_ringBuf3 );

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
                 i_ringBufSize2 == MAX_RING_BUF_SIZE &&
                 i_ringBufSize3 == MAX_RING_BUF_SIZE,
                 fapi2::XIPC_INVALID_INPUT_BUFFER_SIZE_PARM().
                 set_CHIP_TARGET(i_procTarget).
                 set_INPUT_IMAGE_SIZE(l_inputImageSize).
                 set_IMAGE_BUF_SIZE(io_imageSize).
                 set_RING_SECTION_BUF_SIZE(io_ringSectionBufSize).
                 set_RING_BUF_SIZE1(i_ringBufSize1).
                 set_RING_BUF_SIZE2(i_ringBufSize2).
                 set_RING_BUF_SIZE3(i_ringBufSize3).
                 set_OCCURRENCE(1),
                 "One or more invalid input buffer sizes:\n"
                 "  l_inputImageSize=0x%016llx\n"
                 "  io_imageSize=0x%016llx\n"
                 "  io_ringSectionBufSize=0x%016llx\n"
                 "  i_ringBufSize1=0x%016llx\n"
                 "  i_ringBufSize2=0x%016llx\n"
                 "  i_ringBufSize3=0x%016llx\n",
                 (uintptr_t)l_inputImageSize,
                 (uintptr_t)io_imageSize,
                 (uintptr_t)io_ringSectionBufSize,
                 (uintptr_t)i_ringBufSize1,
                 (uintptr_t)i_ringBufSize2,
                 (uintptr_t)i_ringBufSize3 );

    FAPI_DBG("Input image size: %d", l_inputImageSize);

    // First, determine the DD level
    l_fapiRc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, i_procTarget, attrDdLevel);

    FAPI_ASSERT( l_fapiRc == fapi2::FAPI2_RC_SUCCESS,
                 fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(1),
                 "FAPI_ATTR_GET(ATTR_EC) failed." );

    FAPI_DBG("attrDdLevel (for DD level .rings) = 0x%x", attrDdLevel);

    //Fetching the chip name
    l_fapiRc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_procTarget, l_chipName);

    FAPI_ASSERT( l_fapiRc == fapi2::FAPI2_RC_SUCCESS,
                 fapi2::XIPC_FAPI_ATTR_SVC_FAIL().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(1),
                 "FAPI_ATTR_GET(ATTR_NAME) failed." );

    FAPI_DBG("chipName (from HW image .rings) = 0x%x", l_chipName);

    //Fetching DD version from MVPD file
    FAPI_TRY(getMvpdField(fapi2::MVPD_RECORD_CRP0,
                          fapi2::MVPD_KEYWORD_DD,
                          i_procTarget,
                          NULL,
                          l_sizeMvpdDDField),
             "getMvpdField failed for CRP0/DD (1) w/rc=0x%08x",
             (uint64_t)fapi2::current_err);

    l_fullDDData = new uint8_t[l_sizeMvpdDDField]();
    l_decimalDDData = new uint8_t[l_sizeMvpdDDField]();

    FAPI_TRY(getMvpdField(fapi2::MVPD_RECORD_CRP0,
                          fapi2::MVPD_KEYWORD_DD,
                          i_procTarget,
                          l_fullDDData,
                          l_sizeMvpdDDField),
             "getMvpdField failed for CRP0/DD (2) w/rc=0x%08x and"
             "DD level size is of %u bytes",
             (uint64_t)fapi2::current_err, l_sizeMvpdDDField);

    //Size of DD keyword is of 5 bytes. 1st byte is keyword version,
    //Checking the keyword version
    FAPI_ASSERT((l_fullDDData[0] == MVPD_DD_KWD_VER1),
                fapi2::XIPC_MVPD_DD_KEYWORD_VERSION_ERROR().
                set_CHIP_TARGET(i_procTarget).
                set_MVPD_DD_KWD_VERSION(l_fullDDData[0]).
                set_MVPD_DDSIZE(l_sizeMvpdDDField),
                "DD Keyword version from MVPD is 0x%0x, "
                "size of DD keyword is %u",
                l_fullDDData[0], l_sizeMvpdDDField);

    //Converting ASCI to hex
    //2nd & 3rd byte contains RIT and 4th and 5th bytes has EC value.
    //DD level in MVPD is determined using RIT and EC values.
    //For example:- if DD level is x.y than the RIT = x & EC = y.
    //Therefore below we are considering RIT and EC values.
    //i value is initialized to 1 as the data field(RIT+EC) starts from there.
    for(uint32_t i = 1; i < l_sizeMvpdDDField; i++)
    {
        *(l_decimalDDData + i) = *(l_fullDDData + i) - '0';
    }

    //Storing the value of l_fullDDData in a uint8, value obtained from
    //MVPD is in 4 bytes i.e. the 1st two bytes contain the major DD number, x,
    //and the next two bytes contain the minor DD number, y, in DDx.y
    //Hence the below conversion is done where the 1st two bytes are
    //ORed and shifted by 4 bits.
    l_mvpdDD = (((*(l_decimalDDData + 1) * 10 + * (l_decimalDDData + 2)) << 4) |
                (*(l_decimalDDData + 3) * 10 + * (l_decimalDDData + 4)));
    FAPI_DBG("l_mvpdDD (DD level fetched from MVPD) is 0x%02x", l_mvpdDD);

    FAPI_ASSERT((l_mvpdDD == attrDdLevel),
                fapi2::XIPC_DD_LEVEL_MISMATCH_ERROR().
                set_CHIP_TARGET(i_procTarget).
                set_ATTR_DDLEVEL(attrDdLevel).
                set_MVPD_DDLEVEL(l_mvpdDD).
                set_MVPD_DDDATA1(*(l_fullDDData + 1)).
                set_MVPD_DDDATA2(*(l_fullDDData + 2)).
                set_MVPD_DDDATA3(*(l_fullDDData + 3)).
                set_MVPD_DDDATA4(*(l_fullDDData + 4)).
                set_MVPD_DDSIZE(l_sizeMvpdDDField),
                "DD level from Platform (i.e attrDdLevel: 0x%0x) and "
                "MVPD (i.e l_mvpdDD: 0x%0x)is not matching. "
                "Data fetched from MVPD, 1st Byte = 0x%0x, 2nd Byte = 0x%0x, "
                " 3rd Byte = 0x%0x, 4th Byte = 0x%0x. Size of MVPD is %u.",
                attrDdLevel, l_mvpdDD, *(l_fullDDData + 1), *(l_fullDDData + 2),
                *(l_fullDDData + 3), *(l_fullDDData + 4), l_sizeMvpdDDField);

    //Fetching chip name from MVPD
    FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CRP0,
                           fapi2::MVPD_KEYWORD_CI,
                           i_procTarget,
                           NULL,
                           l_sizeMvpdCIField),
              "getMvpdField failed for CRP0/CI (1) w/rc=0x%08x",
              (uint64_t)fapi2::current_err);

    l_fullCIData = new uint8_t[l_sizeMvpdCIField]();

    FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CRP0,
                           fapi2::MVPD_KEYWORD_CI,
                           i_procTarget,
                           l_fullCIData,
                           l_sizeMvpdCIField),
              "getMvpdField failed for CRP0/CI (2) w/rc=0x%08x and"
              "chipname data size is of %u bytes",
              (uint64_t)fapi2::current_err, l_sizeMvpdCIField);
    FAPI_DBG("Chip name fetched from MVPD is 0x%0x", *l_fullCIData);

    FAPI_ASSERT((*(l_fullCIData) == P10_MVPD_CHIP_NAME) && (l_chipName == CID_P10),
                fapi2::XIPC_CHIPNAME_MISMATCH_ERROR().
                set_CHIP_TARGET(i_procTarget).
                set_ATTR_NAME(l_chipName).
                set_MVPD_NAME(l_fullCIData),
                "Chip name from Platform (i.e. l_chipName: 0x%0x)"
                "and MVPD (i.e. l_fullCIData: 0x%0x)is different",
                l_chipName, *l_fullCIData );

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
    // CUSTOMIZE item:  Removal of .toc, .fixed_toc and .strings
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
    // - Determine if there GPTR support, and overlays support, through Mvpd
    //////////////////////////////////////////////////////////////////////////


    switch (i_sysPhase)
    {

        case SYSPHASE_HB_SBE:

            FAPI_DBG("Image size w/empty .rings section before any VPD updates: %d", l_currentImageSize);

            l_imageSizeWithoutRings = l_currentImageSize;

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
                         set_SECTION_ID(P9_XIP_SECTION_SBE_RINGS).
                         set_DDLEVEL(attrDdLevel).
                         set_OCCURRENCE(1),
                         "p9_xip_get_sub_section() failed (1) w/rc=0x%08X retrieving .sbe.rings"
                         " section and ddLevel=0x%x",
                         (uint32_t)l_rc, attrDdLevel );

            io_ringSectionBufSize = iplImgSection.iv_size;

            FAPI_ASSERT( io_ringSectionBufSize > 0,
                         fapi2::XIPC_EMPTY_IMAGE_SECTION().
                         set_CHIP_TARGET(i_procTarget).
                         set_SECTION_ID(P9_XIP_SECTION_SBE_RINGS).
                         set_DDLEVEL(UNDEFINED_DD_LEVEL).
                         set_OCCURRENCE(1),
                         "p9_xip_get_sub_section() returned .sbe.rings size of size zero."
                         "No TOR. Can't append rings.");

            FAPI_DBG("Size of .rings section before VPD update: %d", io_ringSectionBufSize);

            l_maxRingSectionSize = l_maxImageSize - l_imageSizeWithoutRings;

            FAPI_DBG("Max allowable size of .rings section: %d", l_maxRingSectionSize);

            // Move .rings to the top of ringSectionBuf (which currently holds a copy of the
            //   io_image but which can now be destroyed.)
            memcpy( io_ringSectionBuf,
                    (void*)((uint8_t*)i_hwImage + iplImgSection.iv_offset),
                    io_ringSectionBufSize );

            //----------------------------------------
            // Append VPD Rings to the .rings section
            //----------------------------------------
#if 0
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
#endif
            FAPI_DBG("-----------------------------------------------------------------------");
            FAPI_DBG("bootCoreMask:  Requested=0x%08X  Final=0x%08X",
                     l_requestedBootCoreMask, io_bootCoreMask);
            FAPI_DBG("-----------------------------------------------------------------------");

            if (l_fapiRc)
            {

                if ((uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW)
                {
                    FAPI_INF("p10_ipl_customize(): Image is full. Ran out of space appending VPD rings"
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

        case SYSPHASE_RT_QME:

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
                         "One or more invalid input buffer sizes for RT_QME phase:\n"
                         "  l_inputImageSize=0x%016llx\n"
                         "  io_imageSize=0x%016llx\n"
                         "  io_ringSectionBufSize=0x%016llx\n",
                         (uintptr_t)l_inputImageSize,
                         (uintptr_t)io_imageSize,
                         (uintptr_t)io_ringSectionBufSize );

            l_maxRingSectionSize = io_ringSectionBufSize;


            //
            // Next, get the DD level specific set of QME rings from the HW image.
            //

            // Setup up nested section ID combination for current PPE image
            mainSectionID = P9_XIP_SECTION_HW_QME;
            subSectionID = P9_XIP_SECTION_QME_RINGS;

            l_rc = p9_xip_get_sub_section( io_image,
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
                         set_OCCURRENCE(4),
                         "p9_xip_get_sub_section() failed (4) w/rc=0x%08x in sysPhase=%d",
                         " getting nested PPE image's .rings subSectionID=%d for"
                         " ddLevel=0x%x",
                         (uint32_t)l_rc, i_sysPhase, subSectionID, attrDdLevel );

            FAPI_ASSERT( iplImgSection.iv_size > 0,
                         fapi2::XIPC_EMPTY_IMAGE_SECTION().
                         set_CHIP_TARGET(i_procTarget).
                         set_SECTION_ID(subSectionID).
                         set_DDLEVEL(attrDdLevel).
                         set_OCCURRENCE(3),
                         "p9_xip_get_sub_section() returned a ring section of zero size for"
                         " sysPhase=%d, ddLevel=0x%x, mainSectionID=%d and subSectionID=%d."
                         " There's no TOR. We cannot append rings.",
                         i_sysPhase, attrDdLevel, mainSectionID, subSectionID );

            io_ringSectionBufSize = iplImgSection.iv_size;

            memcpy( io_ringSectionBuf,
                    (void*)((uint8_t*)io_image + iplImgSection.iv_offset),
                    io_ringSectionBufSize );

            FAPI_DBG("Size of .rings section before VPD update: %d", io_ringSectionBufSize);

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
    FAPI_DBG("Exiting p10_ipl_customize");
    return fapi2::current_err;

}
