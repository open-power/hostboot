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
    #include <p10_boot_mode.H>
#endif

#include <p10_ipl_customize.H>
#include <p10_ipl_image.H>
#include <p10_ringId.H>
#include <p10_tor.H>
#include <p10_scan_compression.H>
#include <p10_infrastruct_help.H>
#include <map>
#include <p10_ipl_section_append.H>
#ifndef WIN32
    #include <p10_dyninit_bitvec.H>
#endif
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

#define MBOX_ATTR_WRITE_VECTOR(ID,TARGET,IMAGE,SIZE) \
    { \
        fapi2::ID##_Type ID##_attrVal; \
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ID,TARGET,ID##_attrVal),\
                 "MBOX_ATTR_WRITE_VECTOR: Error getting %s", #ID); \
        for (auto idx = 0; idx < SIZE; idx++) \
        { \
            FAPI_TRY(p9_xip_set_element(IMAGE,#ID,idx,ID##_attrVal[idx]),    \
                     "MBOX_ATTR_WRITE_VECTOR: Error writing attr %s to seeprom image",\
                     #ID); \
        } \
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

#define MBOX_ATTR_CLEAR_VECTOR(ID,TARGET,IMAGE,SIZE)    \
    { \
        fapi2::ID##_Type ID##_attrVal; \
        for (auto idx = 0; idx < SIZE; idx++) \
        { \
            ID##_attrVal[idx] = 0; \
            FAPI_TRY(p9_xip_set_element(IMAGE,#ID,idx,ID##_attrVal[idx]),    \
                     "MBOX_ATTR_CLEAR_VECTOR: Error writing attr %s to seeprom image",\
                     #ID); \
        } \
    }

fapi2::ReturnCode writeMboxRegs (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
    void* i_image)
{
    FAPI_DBG ("writeMboxRegs Entering...");
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_CONTAINED_IPL_TYPE_Type l_attr_contained_ipl_type;
    P9XipItem l_item;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE,
                           FAPI_SYSTEM,
                           l_attr_contained_ipl_type));

    // customize only attributes
    MBOX_ATTR_WRITE(ATTR_SECURITY_MODE,                         FAPI_SYSTEM,  i_image);
    MBOX_ATTR_WRITE(ATTR_SECTOR_BUFFER_STRENGTH,                FAPI_SYSTEM,  i_image);
    MBOX_ATTR_WRITE(ATTR_LPC_CONSOLE_CNFG,                      i_procTarget, i_image);

    // mailbox 1,2
    // covered by writePG() function
    // mailbox 3
    // not customized: ATTR_BOOT_FLAGS, ATTR_IS_MPIPL, ATTR_IS_SP_MODE

    // mailbox 4
    MBOX_ATTR_WRITE(ATTR_SPI_BUS_DIV_REF,                       i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_FREQ_CORE_BOOT_MHZ,                    i_procTarget, i_image);

    // mailbox 5
    MBOX_ATTR_WRITE(ATTR_SYSTEM_IPL_PHASE,                      FAPI_SYSTEM,  i_image);
    MBOX_ATTR_WRITE(ATTR_CONTAINED_IPL_TYPE,                    FAPI_SYSTEM,  i_image);
    MBOX_ATTR_WRITE(ATTR_RUNN_MODE,                             FAPI_SYSTEM,  i_image);
    MBOX_ATTR_WRITE(ATTR_DISABLE_HBBL_VECTORS,                  FAPI_SYSTEM,  i_image);
    MBOX_ATTR_WRITE(ATTR_SBE_SELECT_EX_POLICY,                  FAPI_SYSTEM,  i_image);
    MBOX_ATTR_WRITE(ATTR_CP_REFCLOCK_SELECT,                    i_procTarget, i_image);
    MBOX_ATTR_WRITE_VECTOR(ATTR_CLOCK_MUX_IOHS_LCPLL_INPUT,     i_procTarget, i_image, 8);
    MBOX_ATTR_WRITE_VECTOR(ATTR_CLOCK_MUX_PCI_LCPLL_INPUT,      i_procTarget, i_image, 2);

    // mailbox 6
    // for backwards compatiblity with images that don't contain
    // the new filter/PCI PLL bucket attributes, ensure that the item exists
    // prior to attempting an update which would otherwise fail
    if (!p9_xip_find(i_image, "ATTR_FILTER_PLL_BUCKET", &l_item))
    {
        MBOX_ATTR_WRITE(ATTR_FILTER_PLL_BUCKET,                 i_procTarget, i_image);
    }

    if (!p9_xip_find(i_image, "ATTR_PCI_PLL_BUCKET", &l_item))
    {
        MBOX_ATTR_WRITE(ATTR_PCI_PLL_BUCKET,                    i_procTarget, i_image);
    }

    MBOX_ATTR_WRITE(ATTR_CP_PLLTODFLT_BYPASS,                   i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_CP_PLLNESTFLT_BYPASS,                  i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_CP_PLLIOFLT_BYPASS,                    i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_CP_PLLIOSSFLT_BYPASS,                  i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_NEST_DPLL_BYPASS,                      i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_PAU_DPLL_BYPASS,                       i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_BOOT_PAU_DPLL_BYPASS,                  i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_IO_TANK_PLL_BYPASS,                    i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_SKEWADJ_BYPASS,                        i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_DCADJ_BYPASS,                          i_procTarget, i_image);
    MBOX_ATTR_CLEAR(ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID,           i_procTarget, i_image);
    MBOX_ATTR_WRITE(ATTR_PROC_FABRIC_TOPOLOGY_MODE,             FAPI_SYSTEM,  i_image);
    MBOX_ATTR_WRITE(ATTR_PROC_FABRIC_BROADCAST_MODE,            FAPI_SYSTEM,  i_image);
    MBOX_ATTR_SET(ATTR_PROC_SBE_MASTER_CHIP,                    i_procTarget, i_image);
    MBOX_ATTR_CLEAR(ATTR_PROC_FABRIC_TOPOLOGY_ID,               i_procTarget, i_image);
    MBOX_ATTR_CLEAR_VECTOR(ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE,  i_procTarget, i_image, 32);

    // mailbox 7
    if (l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_CHIP)
    {
        MBOX_ATTR_WRITE(ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC,   i_procTarget, i_image);
    }
    else
    {
        MBOX_ATTR_CLEAR(ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC,   i_procTarget, i_image);
    }

    // mailbox 9
    MBOX_ATTR_WRITE(ATTR_FREQ_PAU_MHZ,                          FAPI_SYSTEM,  i_image);
    MBOX_ATTR_WRITE_VECTOR(ATTR_MC_PLL_BUCKET,                  i_procTarget, i_image, 4);

    // mailbox 10
    MBOX_ATTR_WRITE_VECTOR(ATTR_IOHS_PLL_BUCKET,                i_procTarget, i_image, 8);

    if (l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_CHIP)
    {
        MBOX_ATTR_WRITE(ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC, i_procTarget, i_image);
    }
    else
    {
        MBOX_ATTR_CLEAR(ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC, i_procTarget, i_image);
    }

fapi_try_exit:
    FAPI_DBG("writeMboxRegs Exiting...");
    return fapi2::current_err;
}
#endif
///////////////////////////////////////////////////////////////////////////////
// Table structure for the expanded raw scoms
///////////////////////////////////////////////////////////////////////////////
////////// 1B Command // 1B LAST ROW // 2B PAD // 4B ADDR // 8B DATA //////////
//////////////////////////////// N ROWS ///////////////////////////////////////
#ifdef WIN32
int p10_expand_ring_util(
#else
fapi2::ReturnCode p10_expand_ring_util(
#endif
    const uint8_t    i_chipletId,         // Chiplet to scan
    const uint64_t   i_scanRegionType,    // Scan region and type register value for ring
    uint8_t*         o_tbl_scom_data,     // Ptr to table of scoms per the struct
    uint32_t&        o_tbl_size_in_bytes, // Size of generated table in bytes
    uint32_t         i_size_in_bits,      // in: size of raw ring data in bits
    const uint8_t*   i_raw_data)          // in: raw ring data ptr
{
    typedef struct
    {
        uint32_t cmd: 8;      // Getscom = 0, Putscom = 1, other val for future scope
        uint32_t last_row: 8; // Set to 1, if last row
        uint32_t pad: 16;     // Pad bytes for future use
        uint32_t addr;        // Addr for the above cmd (getscom/putscom)
        uint64_t data;        // Data for the above cmd (getscom/putscom)
    } ringExpand_tbl_t;

    const uint32_t SCAN_REGION_TYPE   = (i_chipletId << 24) | 0x00030005; // scan region and type address
    const uint32_t SCAN_PUT_BASE_ADDR = (i_chipletId << 24) | 0x0003E000; // scan write base address
    const uint32_t SCAN_GET_BASE_ADDR = (i_chipletId << 24) | 0x00038000; // scan read base address

    const uint32_t EXPAND_RING_64BIT_LEN_MASK = 0x00000040;    // address mask for 64-bit shift
    const uint64_t EXPAND_RING_HEADER = 0xA5A5A5A5A5A5A5A5ull; // header check data pattern

    const uint8_t  ROW_LEN_IN_BYTES = 16;             // size of each table entry
    const uint8_t  EXPAND_RING_GETSCOM_CMD = 0x00;    // getscom command
    const uint8_t  EXPAND_RING_PUTSCOM_CMD = 0x01;    // putscom command
    const uint8_t  SCOM_DATA_LEN_IN_BITS = 64;        // number of bits per SCOM update
    const uint8_t  RING_HEADER_SKIP_LEN_IN_BITS = 64; // number of bits consumed by header
    const uint8_t  LAST_ROW = 1;                      // last row identifier

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint32_t rowIterCnt = 0;
    uint32_t numScoms = (i_size_in_bits / SCOM_DATA_LEN_IN_BITS);
    o_tbl_size_in_bytes = 0;

    FAPI_DBG(">>p10_expand_ring_util i_size_in_bits %d", i_size_in_bits);

    FAPI_ASSERT((o_tbl_scom_data != NULL) &&
                (i_size_in_bits > 0) &&
                (i_raw_data != NULL),
                fapi2::EXPAND_RING_UTIL_INVALID_PARAMETERS().
                set_OUT_IMAGE(o_tbl_scom_data).
                set_IN_IMAGE_SIZE(i_size_in_bits).
                set_IN_IMAGE((uint8_t*)i_raw_data),
                "at least one input parameter not valid");

    if(i_size_in_bits % SCOM_DATA_LEN_IN_BITS)
    {
        numScoms = numScoms + 1;
    }

    // Additional rows for ring implementation
    // 1 row for Setting Scan type and region
    // 1 row for Header
    // 1 row in footer for Header check
    // 1 row in footer to clear Scan type and region
    numScoms = numScoms + 4;

    ringExpand_tbl_t row;
    row.cmd = EXPAND_RING_PUTSCOM_CMD;
    row.last_row = 0;
    row.pad = 0;  // explictly set memory to 0 (WIN32 needs this)

    // Set up the scan type and region
    row.addr = SCAN_REGION_TYPE;
    row.addr = htobe32(row.addr);
    row.data = i_scanRegionType;
    row.data = htobe64(row.data);
    memcpy( (o_tbl_scom_data + (ROW_LEN_IN_BYTES * rowIterCnt++) ),
            (uint8_t*)&row,
            sizeof(ringExpand_tbl_t) );
    // Setup header
    row.addr = SCAN_PUT_BASE_ADDR | EXPAND_RING_64BIT_LEN_MASK;
    row.addr = htobe32(row.addr);
    row.data = EXPAND_RING_HEADER;
    row.data = htobe64(row.data);
    memcpy( (o_tbl_scom_data + (ROW_LEN_IN_BYTES * rowIterCnt++) ),
            (uint8_t*)&row,
            sizeof(ringExpand_tbl_t) );

    // Expand the ring into rows
    for( uint32_t numBits = RING_HEADER_SKIP_LEN_IN_BITS; numBits < i_size_in_bits;
         numBits = numBits + SCOM_DATA_LEN_IN_BITS )
    {
        if(numBits + SCOM_DATA_LEN_IN_BITS <= i_size_in_bits)
        {
            row.addr = SCAN_PUT_BASE_ADDR | EXPAND_RING_64BIT_LEN_MASK;
            row.addr = htobe32(row.addr);
        }
        else // 64bits are not available to copy
        {
            uint8_t remain = i_size_in_bits - numBits;
            row.addr = SCAN_PUT_BASE_ADDR | remain;
            row.addr = htobe32(row.addr);
        }

        memcpy((uint8_t*)&row.data, (i_raw_data + numBits / 8), 8); //8bytes copy
        memcpy( (o_tbl_scom_data + (ROW_LEN_IN_BYTES * rowIterCnt++)),
                (uint8_t*)&row,
                sizeof(ringExpand_tbl_t) );
    }

    // Setup footer, to verify the header bytes
    row.cmd  = EXPAND_RING_GETSCOM_CMD;
    row.addr = SCAN_GET_BASE_ADDR;
    row.addr = htobe32(row.addr);
    row.data = EXPAND_RING_HEADER;
    row.data = htobe64(row.data);
    memcpy( (o_tbl_scom_data + (ROW_LEN_IN_BYTES * rowIterCnt++) ),
            (uint8_t*)&row,
            sizeof(ringExpand_tbl_t) );

    // Clear Scan type and region and set last row byte
    row.cmd  = EXPAND_RING_PUTSCOM_CMD;
    row.addr = SCAN_REGION_TYPE;
    row.addr = htobe32(row.addr);
    row.data = 0x0;

    row.last_row = LAST_ROW;
    memcpy( (o_tbl_scom_data + (ROW_LEN_IN_BYTES * rowIterCnt++) ),
            (uint8_t*)&row,
            sizeof(ringExpand_tbl_t) );

    //Update the number of bytes in the table
    o_tbl_size_in_bytes = ROW_LEN_IN_BYTES * rowIterCnt;

fapi_try_exit:
    FAPI_DBG("<<p10_expand_ring_util");
    return fapi2::current_err;
}

#ifndef WIN32
fapi2::ReturnCode writePG(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
    void* i_image)
{
    const uint8_t  IMG_PG_ENTRIES = 64;
    const uint32_t DEFAULT_PG_VAL = 0xffffff;
    const uint32_t STANDBY_PG_VAL = 0xffe03fff;
    uint8_t l_pg_idx = 0;

    FAPI_DBG ("writePG Entering...");

    // fill in ATTR_PG from platform attribute state
    FAPI_DBG("Updating ATTR_PG...")
    {
        // Make all chiplets "not good", excepting standby/FSI (chiplet ID=0)
        FAPI_TRY( p9_xip_set_element(i_image, "ATTR_PG", l_pg_idx, STANDBY_PG_VAL),
                  "Error (1)) from p9_xip_set_element (ATTR_PG idx %d)", l_pg_idx );

        for (l_pg_idx = 1; l_pg_idx < IMG_PG_ENTRIES; l_pg_idx++)
        {
            FAPI_TRY( p9_xip_set_element(i_image, "ATTR_PG", l_pg_idx, DEFAULT_PG_VAL),
                      "Error from p9_xip_set_element (ATTR_PG idx %d)", l_pg_idx );
        }

        // update results of functional chiplets only
        for (auto l_perv_tgt : i_procTarget.getChildren<fapi2::TARGET_TYPE_PERV>())
        {
            uint8_t l_unit_id = 0;
            uint32_t l_pg_data = 0;

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
                         "CODE BUG: Invalid translation from PERV chip unit position"
                         " to image PG index: l_pg_idx=%d, IMG_PG_ENTRIES=%d",
                         l_pg_idx, IMG_PG_ENTRIES );

            // Update the image
            FAPI_TRY( p9_xip_set_element(i_image, "ATTR_PG", l_pg_idx, l_pg_data),
                      "Error (2) from p9_xip_set_element (ATTR_PG idx %d)", l_pg_idx );

            FAPI_DBG("Write data for chiplet %d, PG = %08X", l_pg_idx, l_pg_data);
        }
    }

    // fill in ATTR_PG_MVPD from MVPD query
    FAPI_DBG("Updating ATTR_PG_MVPD...")
    {
        uint32_t       sizeMvpdPGField = 0;
        uint8_t*       fullPGData = nullptr;
        const uint8_t  MVPD_PG_KWD_VER1 = 0x01;
        const uint8_t  MVPD_PG_KWD_VER1_SIZE = 193;

        // Get Mvpd MK level
        FAPI_TRY(getMvpdField(fapi2::MVPD_RECORD_CP00,
                              fapi2::MVPD_KEYWORD_PG,
                              i_procTarget,
                              NULL,
                              sizeMvpdPGField),
                 "getMvpdField failed for CP00/PG (1) w/rc=0x%08x",
                 (uint64_t)fapi2::current_err);

        fullPGData = new uint8_t[sizeMvpdPGField]();

        FAPI_TRY(getMvpdField(fapi2::MVPD_RECORD_CP00,
                              fapi2::MVPD_KEYWORD_PG,
                              i_procTarget,
                              fullPGData,
                              sizeMvpdPGField),
                 "getMvpdField failed for CP00/PG (2) w/rc=0x%08x and"
                 "PG size is of %u bytes",
                 (uint64_t)fapi2::current_err, sizeMvpdPGField);

        //Size of PG keyword is 193 bytes. 1st byte is keyword version,
        //Checking the keyword version
        FAPI_ASSERT((fullPGData[0] == MVPD_PG_KWD_VER1) &&
                    (sizeMvpdPGField == MVPD_PG_KWD_VER1_SIZE),
                    fapi2::XIPC_MVPD_PG_KEYWORD_VERSION_ERROR().
                    set_CHIP_TARGET(i_procTarget).
                    set_MVPD_PG_KWD_VERSION(fullPGData[0]).
                    set_MVPD_PGSIZE(sizeMvpdPGField),
                    "PG Keyword version from MVPD is 0x%0x, "
                    "size of PG keyword is %u",
                    fullPGData[0], sizeMvpdPGField);

        // copy results verbatim from MVPD
        for (l_pg_idx = 0; l_pg_idx < IMG_PG_ENTRIES; l_pg_idx++)
        {
            // 3B of keyword data, stored right aligned in 4B attribute value
            // initialize the first byte to all 1s per convention
            uint32_t l_pg_mvpd_data = DEFAULT_PG_VAL & 0xFF000000;
            uint8_t l_pg_byte = 1 + (3 * l_pg_idx);

            l_pg_mvpd_data = (fullPGData[l_pg_byte] << 16) |
                             (fullPGData[l_pg_byte + 1] << 8) |
                             (fullPGData[l_pg_byte + 2]);

            // Update the image
            FAPI_TRY( p9_xip_set_element(i_image, "ATTR_PG_MVPD", l_pg_idx, l_pg_mvpd_data),
                      "Error (2) from p9_xip_set_element (ATTR_PG_MVPD idx %d)", l_pg_idx );

            FAPI_DBG("Write data for chiplet %d, PG MVPD = %08X", l_pg_idx, l_pg_mvpd_data);
        }
    }


fapi_try_exit:
    FAPI_DBG ("writePG Exiting...");
    return fapi2::current_err;
}

#endif

// Function: get_overlays_ring()
// @brief: This function is used to get a [Gptr] ring from the overlays section
//
// Parameter list:
// const fapi2::Target &i_target:  Processor chip target.
// void*     i_overlaysSection:  Overlays ring section in HW image
// uint8_t   i_ddLevel:          DD level (to be used in TOR API verif)
// RingId_t  i_ringId:           Overlays [Gptr] ringId
// void*     io_ovlyRs4:         =ringBuf2: Contains RS4 overlays ring on return
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
    void*     io_ovlyRs4 )
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    int rc = INFRASTRUCT_RC_SUCCESS;

    FAPI_DBG("Entering get_overlays_ring");

    // Copy ring from overlays section into ovlyRs4
    uint8_t  chipletId = 0; // Unused parm
    uint32_t bufSize = RS4_RING_BUF_SIZE;
    rc = tor_get_single_ring(
             i_overlaysSection,
             i_ddLevel,
             i_ringId,
             chipletId,
             io_ovlyRs4,
             bufSize,
             UNDEFINED_BOOLEAN ); //The overlays section is never customized

    if (rc == TOR_SUCCESS)
    {
        uint32_t rawBitLength = 0;
        rc = rs4_get_raw_bit_length( rawBitLength,
                                     (CompressedScanData*)io_ovlyRs4 );

        FAPI_ASSERT( rc == SCAN_COMPRESSION_OK,
                     fapi2::XIPC_RS4_DECOMPRESS_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_MAX_RING_BUF_SIZE(RS4_RING_BUF_SIZE).
                     set_LOCAL_RC(rc).
                     set_OCCURRENCE(5),
                     "rs4_get_raw_bit_length() failed w/rc=0x%08x for ringId=0x%x, occurrence=5",
                     rc, i_ringId );

        FAPI_DBG("Ring found in origination section, Overlays: "
                 "ringId=0x%x, size=%u and raw length=%u",
                 i_ringId, be16toh(((CompressedScanData*)io_ovlyRs4)->iv_size), rawBitLength);

        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
    else if (rc == TOR_RING_IS_EMPTY)
    {
        // It's normal to not find an overlays ring w/content
        FAPI_DBG("Overlays ring w/ringId=0x%x is empty", i_ringId);

        // Inform caller that overlays ring is empty
        fapi2::current_err = RC_XIPC_OVERLAYS_RING_IS_EMPTY;
    }
    else
    {
        FAPI_ASSERT( false,
                     fapi2::XIPC_TOR_GET_SINGLE_RING_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_DD_LEVEL(i_ddLevel).
                     set_LOCAL_RC(rc).
                     set_OCCURRENCE(1),
                     "tor_get_single_ring() failed w/rc=0x%08x during extraction of overlays"
                     " ring w/ringId=0x%x and ddLevel=0x%x",
                     rc, i_ringId, i_ddLevel );
    }

fapi_try_exit:
    FAPI_DBG("Exiting get_overlays_ring");
    return fapi2::current_err;
}



// Function: process_gptr_rings()
// @brief: This function is used to check and process gptr rings found in the overlays
//         ring section and in the Mvpd.
//
// Parameter list:
// const fapi2::Target &i_target: Processor chip target.
// void*      i_overlaysSection:  Overlays ring section in HW image
// uint8_t    i_ddLevel:          DD level (to be used in TOR API verif)
// void*      io_gptrRs4Ring:     =ringBuf1: In: Mvpd Gptr ring, Out: Overlaid Gptr ring
// void*      io_ringBuf2:        =ringBuf2: Ring work buffer(used for Rs4 overlay ring)
// void*      io_ringBuf3:        =ringBuf3: Ring work buffer(used for Raw4 overlays operation)
#ifdef WIN32
int process_gptr_rings(
    int i_procTarget,
#else
fapi2::ReturnCode process_gptr_rings(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#endif
    void*   i_overlaysSection,
    uint8_t i_ddLevel,
    void*   io_gptrRs4Ring, // In: Mvpd Gptr Rs4 ring, Out: Overlaid Gptr Rs4 ring
    void*   io_ringBuf2, // Will locally hold ovlyRs4Ring
    void*   io_ringBuf3) // Work buffer to perform Raw4 overlays operation
{
    ReturnCode fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Used for getting Gptr ring from overlays section
    void* ovlyRs4Ring = io_ringBuf2;

    FAPI_DBG("process_gptr_rings(): Processing Mvpd Gptr ringId=0x%x",
             be16toh(((CompressedScanData*)io_gptrRs4Ring)->iv_ringId));

    fapiRc = get_overlays_ring(
                 i_procTarget,
                 i_overlaysSection,
                 i_ddLevel,
                 be16toh(((CompressedScanData*)io_gptrRs4Ring)->iv_ringId),
                 ovlyRs4Ring ); // Has overlays Rs4 ring on return

    if (fapiRc == fapi2::FAPI2_RC_SUCCESS) // An overlays ring with content was found
    {
        // Check that RS4 headers of the Mvpd and overlay rings match wrt:
        // - version
        // - ringId
        // - scanAddr
        FAPI_ASSERT( ( ((CompressedScanData*)io_gptrRs4Ring)->iv_ringId ==
                       ((CompressedScanData*)ovlyRs4Ring)->iv_ringId &&
                       ((CompressedScanData*)io_gptrRs4Ring)->iv_scanAddr ==
                       ((CompressedScanData*)ovlyRs4Ring)->iv_scanAddr ),
                     fapi2::XIPC_MVPD_OVLY_RING_HEADER_MISMATCH().
                     set_CHIP_TARGET(i_procTarget).
                     set_MVPD_RING_ID(  be16toh(((CompressedScanData*)io_gptrRs4Ring)->iv_ringId)).
                     set_OVLY_RING_ID(  be16toh(((CompressedScanData*)ovlyRs4Ring)->iv_ringId)).
                     set_MVPD_SCAN_ADDR(be32toh(((CompressedScanData*)io_gptrRs4Ring)->iv_scanAddr)).
                     set_OVLY_SCAN_ADDR(be32toh(((CompressedScanData*)ovlyRs4Ring)->iv_scanAddr)).
                     set_MVPD_TYPE(             ((CompressedScanData*)io_gptrRs4Ring)->iv_type).
                     set_OVLY_TYPE(             ((CompressedScanData*)ovlyRs4Ring)->iv_type),
                     "ERROR: process_gptr_rings: MVPD and Ovly RS4 headers don't match:\n"
                     " Mvpd ringId: 0x%x\n"
                     " Ovly ringId: 0x%x\n"
                     " Mvpd scanAddr: 0x%08x\n"
                     " Ovly scanAddr: 0x%08x\n"
                     " Mvpd type: 0x%02x\n"
                     " Ovly type: 0x%02x",
                     be16toh(((CompressedScanData*)io_gptrRs4Ring)->iv_ringId),
                     be16toh(((CompressedScanData*)ovlyRs4Ring)->iv_ringId),
                     be32toh(((CompressedScanData*)io_gptrRs4Ring)->iv_scanAddr),
                     be32toh(((CompressedScanData*)ovlyRs4Ring)->iv_scanAddr),
                     ((CompressedScanData*)io_gptrRs4Ring)->iv_type,
                     ((CompressedScanData*)ovlyRs4Ring)->iv_type );

        //
        // Overlay the overlays ring onto the Mvpd Gptr ring.
        // Note that the overlay operation needs to be done even if the Mvpd Gptr ring is
        // redundant so that any potential reset bits in the overlays ring get cleared in the
        // care portion which wouldn't happen if we just memcpy the overlays ring into the final
        // io_gptrRs4Ring.
        //

        // Check that iv_type's non-ORIG part is the same in both rings. If they differ,
        // that shows an error in either the programming of the Mvpd ring or the Overlays ring.
        // (The ORIG bits have already been checked as part of the ring retrieval APIs)
        uint8_t mvpdTypeField = ((CompressedScanData*)io_gptrRs4Ring)->iv_type;
        uint8_t ovlyTypeField = ((CompressedScanData*)ovlyRs4Ring)->iv_type;

        FAPI_ASSERT( !((mvpdTypeField ^ ovlyTypeField) & ~RS4_IV_TYPE_ORIG_MASK),
                     fapi2::XIPC_TYPE_FIELD_MISMATCH().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(be16toh(((CompressedScanData*)ovlyRs4Ring)->iv_ringId)).
                     set_RING1_TYPE_FIELD(mvpdTypeField).
                     set_RING2_TYPE_FIELD(ovlyTypeField).
                     set_OCCURRENCE(1),
                     "ERROR: process_gptr_rings: The RS4 iv_type field differs in the non-ORIG"
                     " bits between Mvpd Gptr(type=0x%02x) and Overlays(type=0x%02x) rings for"
                     " ringId=0x%x",
                     mvpdTypeField, ovlyTypeField,
                     be16toh(((CompressedScanData*)ovlyRs4Ring)->iv_ringId) );

        // We need to preserve (for debugging purpose) where the ring contributions came from,
        // ie the RS4_IV_TYPE_ORIG_* settings.  Since we know at this point that the non-ORIG
        // part of iv_type agree between the two rings, we can OR the iv_types here.
        uint8_t finalTypeField = mvpdTypeField | ovlyTypeField;

        FAPI_DBG("In process_gptr_rings(): gptrRs4Ring (Before):");

        for (uint16_t iRs4 = 0; iRs4 < (be16toh(((CompressedScanData*)io_gptrRs4Ring)->iv_size) + 4) / 8; iRs4++)
        {
            FAPI_DBG("0x%016lx", be64toh(*((uint64_t*)io_gptrRs4Ring + iRs4)));
        }

        int rc = rs4_overlay( (CompressedScanData*)io_ringBuf3,    // ringBuf3
                              OVLY_WORK_BUF_SIZE,
                              (CompressedScanData*)io_gptrRs4Ring, // ringBuf1 - Tgt
                              (CompressedScanData*)ovlyRs4Ring,    // ringBuf2 - Ovly
                              //(CompressedScanData*)io_gptrRs4Ring,    // ringBuf2 - Ovly
                              finalTypeField,
                              UNDEFINED_RS4_SELECTOR,
                              OVLY_MODE_BOSS );            // Ovly is boss

        FAPI_ASSERT( rc == SCAN_COMPRESSION_OK,
                     fapi2::XIPC_RS4_OVERLAY_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(be16toh(((CompressedScanData*)io_gptrRs4Ring)->iv_ringId)).
                     set_LOCAL_RC(rc).
                     set_OCCURRENCE(1),
                     "ERROR(1): rs4_overlay failed w/rc=0x%08x",
                     rc );

        memcpy( io_gptrRs4Ring, io_ringBuf3, be16toh(((CompressedScanData*)io_ringBuf3)->iv_size));

        FAPI_DBG("In process_gptr_rings(): gptrRs4Ring (After):");

        for (uint16_t iRs4 = 0; iRs4 < (be16toh(((CompressedScanData*)io_gptrRs4Ring)->iv_size) + 4) / 8; iRs4++)
        {
            FAPI_DBG("0x%016lx", be64toh(*((uint64_t*)io_gptrRs4Ring + iRs4)));
        }

    }
    else if ((uint32_t)fapiRc == RC_XIPC_OVERLAYS_RING_IS_EMPTY)
    {
        // Finding an empty overlays ring will be a common scenario. There is no overlay to do.
        // The content in io_gptrRs4Ring will be the final overlaid Gptr ring.
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
    else
    {
        // Failure: Return the fapiRc from get_overlays_ring()
        fapi2::current_err = fapiRc;
    }

fapi_try_exit:
    FAPI_DBG("Exiting process_gptr_rings");
    return fapi2::current_err;
}



//  Function: process_target_and_dynamic_rings()
//
//  Parameter list:
//  const fapi::Target &i_target:    Processor chip target.
//  bool            i_bBaseRing:  true: Base target ring, false: Gptr target ring
//  void*           i_targetRingSectionOrRing: Has the ring to be overlaid
//                                             **Overloaded** input arg as follows:
//                                             if (bBaseRing==true) => Base ringSection
//                                             if (bBaseRing==false)=> Gptr ring in mid-ringBuf1
//  void*           i_dynamicRingSection:      Dynamic overlay ringSection
//  void*           io_ringBuf1                On return, has the final overlaid ring
//  void*           i_ringBuf2
//  void*           i_ringBuf3
//  std::map<Rs4Selector_t, Rs4Selector_t>& i_idxFeatureMap
//  std::map<RingId_t, uint64_t>& io_ringIdFeatureVecMap
//  Rs4Selector_t   i_numberOfFeatures
//  RingId_t&       i_ringId
//  uint32_t        i_ddLevel
//
#ifdef WIN32
int process_target_and_dynamic_rings(
    int i_procTarget,
#else
fapi2::ReturnCode process_target_and_dynamic_rings(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
#endif
    bool            i_bBaseRing,
    void*           i_targetRingSectionOrRing,
    void*           i_dynamicRingSection,
    void*           io_ringBuf1,
    void*           i_ringBuf2,
    void*           i_ringBuf3,
    std::map<Rs4Selector_t, Rs4Selector_t>& i_idxFeatureMap,
    std::map<RingId_t, uint64_t>& io_ringIdFeatureVecMap,
    Rs4Selector_t   i_numberOfFeatures,
    RingId_t        i_ringId,
    uint32_t        i_ddLevel )
{
    int         l_rc = 0;
    uint32_t    bufSize = 0;
    bool        bDynRingFound = false;
    bool        bTargetRingFound = false;
    uint32_t    nextFeature = 0;
    uint64_t    featureVecAcc = 0;
    uint8_t     targetTypeField = 0;
    uint8_t     dynTypeField = 0;
    uint8_t     finalTypeField = 0;

    // io_ringBuf1 is used in the following three steps:
    //
    // 1st  In dynRs4, it is used temporarily to hold the extracted individual dynamic RS4 rings
    //      from the .dynamic ring section before they are accumulated in ringBuf2/3.
    // 2nd  In targetRs4,
    //      a) if bBaseRing==true, it is used for extracting the Base ring from the .<ppe>.rings
    //         ring section, or
    //      b) i bBaseRing==false, it will copy the Gptr RS4 ring which has been relocated to
    //         ringBuf1 + RS4_RING_BUF_SIZE / 2 to avoid dynRs4 usage overwriting it
    //      (Note that in both cases the RS4 ring is obtained from the targetRingSectionOrRing arg.)
    // 3rd  Here we again use targetRs4 as the target ring onto which we overlay, or produce, the
    //      final overlaid target ring.
    //
    void* dynRs4 = io_ringBuf1;
    void* targetRs4 = io_ringBuf1;
    void* dynRs4Acc = i_ringBuf3;
    memset(dynRs4Acc, 0, OVLY_WORK_BUF_SIZE);
    bool bDynAccEmpty = true;

    FAPI_DBG("Entering process_target_and_dynamic_rings() w/(ringId,numberOfFeatures)=(0x%x,%u)",
             i_ringId, i_numberOfFeatures);

    //
    // 1st: Get/accumulate the dynamic ring(s)
    //
    for (uint64_t idxFeat = 0; idxFeat < i_numberOfFeatures; idxFeat++)
    {
        nextFeature = i_idxFeatureMap[idxFeat];

        if (i_bBaseRing)
        {
            bufSize = RS4_RING_BUF_SIZE; // Use it all. targetRs4 will come from baseRingSection
        }
        else
        {
            bufSize = RS4_RING_BUF_SIZE / 2; // Don't exceed half Buf1 size where Gptr ring is
        }

        l_rc = dyn_get_ring( i_dynamicRingSection,
                             i_ringId,
                             nextFeature,
                             i_ddLevel,
                             dynRs4,
                             bufSize );

        if(l_rc == TOR_SUCCESS)
        {
            uint32_t rawBitLength = 0;
            l_rc = rs4_get_raw_bit_length( rawBitLength,
                                           (CompressedScanData*)dynRs4 );

            FAPI_ASSERT( l_rc == SCAN_COMPRESSION_OK,
                         fapi2::XIPC_RS4_DECOMPRESS_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_ID(i_ringId).
                         set_MAX_RING_BUF_SIZE(RS4_RING_BUF_SIZE).
                         set_LOCAL_RC(l_rc).
                         set_OCCURRENCE(2),
                         "rs4_get_raw_bit_length() failed w/rc=0x%08x for ringId=0x%x, occurrence=2",
                         l_rc, i_ringId );

            FAPI_DBG("Ring found in origination section, Dynamic (.dynamic): "
                     "ringId=0x%x, size=%u and raw length=%u",
                     i_ringId, be16toh(((CompressedScanData*)dynRs4)->iv_size), rawBitLength);

            bDynRingFound = true;
            featureVecAcc |= 0x8000000000000000 >> nextFeature;

            dynTypeField = ((CompressedScanData*)dynRs4)->iv_type;

            if (bDynAccEmpty)
            {
                // Copy the first found dynamic ring into the accumulated dynamic buffer, and
                // skip an otherwise dummy overlay.
                memcpy(dynRs4Acc, dynRs4, be16toh(((CompressedScanData*)dynRs4)->iv_size));
                bDynAccEmpty = false;
            }
            else
            {
                l_rc = rs4_overlay( (CompressedScanData*)dynRs4Acc,  // Must pt to ringBuf3
                                    OVLY_WORK_BUF_SIZE,
                                    (CompressedScanData*)dynRs4Acc,  // Tgt ring to be overlaid
                                    (CompressedScanData*)dynRs4,     // Overlay ring
                                    dynTypeField,
                                    UNDEFINED_RS4_SELECTOR,
                                    OVLY_MODE_ACC );            // Ovly is boss

                FAPI_ASSERT( l_rc == SCAN_COMPRESSION_OK,
                             fapi2::XIPC_RS4_OVERLAY_ERROR().
                             set_CHIP_TARGET(i_procTarget).
                             set_RING_ID(be16toh(((CompressedScanData*)dynRs4)->iv_ringId)).
                             set_LOCAL_RC(l_rc).
                             set_OCCURRENCE(2),
                             "ERROR(2): rs4_overlay failed w/rc=0x%08x during accumulation of"
                             " dynamic rings for ringId=0x%x at featureVecAcc=0x%016lx and"
                             " feature value=%u",
                             l_rc, be16toh(((CompressedScanData*)dynRs4)->iv_ringId),
                             featureVecAcc, nextFeature);
            }
        }
        else if( l_rc != TOR_DYN_RING_NOT_FOUND &&
                 l_rc != TOR_HOLE_RING_ID )
        {
            FAPI_ASSERT( false,
                         fapi2::XIPC_DYN_GET_RING_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_ID(i_ringId).
                         set_FEATURE(nextFeature).
                         set_MAX_RING_BUF_SIZE(RS4_RING_BUF_SIZE).
                         set_LOCAL_RC(l_rc),
                         "ERROR: dyn_get_ring() failed w/rc=0x%08x during fetch of ringId=0x%x and feature=%u",
                         l_rc, i_ringId, nextFeature );
        }
    }

    if(bDynRingFound)
    {
#ifdef WIN32
        io_ringIdFeatureVecMap.insert(std::make_pair(i_ringId, featureVecAcc));
#else
        io_ringIdFeatureVecMap.insert({i_ringId, featureVecAcc});
#endif
    }

    //
    // 2nd: Get the target ring
    //
    if(i_bBaseRing)  // Copy Target ring from **Base ringSection in i_targetRingSectionOrRing**
    {
        bufSize = RS4_RING_BUF_SIZE; // Safe to use full Buf1 here
        l_rc = tor_get_single_ring(
                   i_targetRingSectionOrRing,
                   i_ddLevel,
                   i_ringId,
                   UNDEFINED_CHIPLET_ID,
                   targetRs4,
                   bufSize,
                   false ); //We're retrieving from non-customized SBE and QME sections

        FAPI_ASSERT( l_rc == TOR_SUCCESS ||
                     l_rc == TOR_RING_IS_EMPTY ||
                     l_rc == TOR_INVALID_CHIPLET_TYPE,  // We will hit this in RT_QME phase
                     fapi2::XIPC_TOR_GET_SINGLE_RING_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_DD_LEVEL(i_ddLevel).
                     set_LOCAL_RC(l_rc).
                     set_OCCURRENCE(2),
                     "tor_get_single_ring() failed w/rc=0x%08x during extracting Base "
                     "ringId=0x%x and ddLevel=0x%x",
                     l_rc, i_ringId, i_ddLevel );

        if(l_rc == TOR_SUCCESS)
        {
            uint32_t rawBitLength = 0;
            l_rc = rs4_get_raw_bit_length( rawBitLength,
                                           (CompressedScanData*)targetRs4 );

            FAPI_ASSERT( l_rc == SCAN_COMPRESSION_OK,
                         fapi2::XIPC_RS4_DECOMPRESS_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_ID(i_ringId).
                         set_MAX_RING_BUF_SIZE(RS4_RING_BUF_SIZE).
                         set_LOCAL_RC(l_rc).
                         set_OCCURRENCE(3),
                         "rs4_get_raw_bit_length() failed w/rc=0x%08x for ringId=0x%x, occurrence=3",
                         l_rc, i_ringId );

            FAPI_DBG("Ring found in origination section, Base (.{sbe,qme}.rings}: "
                     "ringId=0x%x, size=%u and raw length=%u",
                     i_ringId, be16toh(((CompressedScanData*)targetRs4)->iv_size), rawBitLength);

            bTargetRingFound = true;

            targetTypeField = ((CompressedScanData*)targetRs4)->iv_type;
        }
    }
    else  // Copy Target ring from **Gptr RS4 ring in i_targetRingSectionOrRing**
    {
        // Gptr ring located halfway into Buf1. Size check assumed done by caller.
        memcpy( targetRs4,
                i_targetRingSectionOrRing,
                be16toh(((CompressedScanData*)i_targetRingSectionOrRing)->iv_size));

        targetTypeField = ((CompressedScanData*)targetRs4)->iv_type;

        bTargetRingFound = true;
    }

    //
    // 3rd: Produce the final [overlaid] target ring
    //
    if(bTargetRingFound && bDynRingFound)
    {
        //
        // In this case targetRs4 will be produced from overlaying the accummulated dynamic ring
        // onto the target ring from either the Base ring section or the supplied Gptr ring.
        //
        FAPI_DBG("ringId=0x%x: Target ring found. Dynamic ring found.", i_ringId);

        // Check that iv_type's non-ORIG part is the same in both rings. If they differ,
        // that shows an error in either the programming of the Target ring or the Dynamic ring.
        FAPI_ASSERT( !((targetTypeField ^ dynTypeField) & ~RS4_IV_TYPE_ORIG_MASK),
                     fapi2::XIPC_TYPE_FIELD_MISMATCH().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_RING1_TYPE_FIELD(targetTypeField).
                     set_RING2_TYPE_FIELD(dynTypeField).
                     set_OCCURRENCE(2),
                     "ERROR: process_target_and_dynamic_rings: The RS4 iv_type field differs in the"
                     " non-ORIG bits between target(type=0x%02x) and dynamic(type=0x%02x) rings"
                     " for ringId=0x%x",
                     targetTypeField, dynTypeField, i_ringId );

        // We need to preserve (for debugging purpose) where the ring contributions came from,
        // ie the RS4_IV_TYPE_ORIG_* settings.  Since we know at this point that the non-ORIG
        // part of iv_type agree between the two rings, we can OR the iv_types here.
        finalTypeField = targetTypeField | dynTypeField;

        FAPI_DBG("In process_target_and dynamic_rings(): targetRs4 (Before):");

        for (uint16_t iRs4 = 0; iRs4 < (be16toh(((CompressedScanData*)targetRs4)->iv_size) + 4) / 8; iRs4++)
        {
            FAPI_DBG("0x%016lx", be64toh(*((uint64_t*)targetRs4 + iRs4)));
        }

        FAPI_DBG("In process_target_and dynamic_rings(): dynRs4Acc (first 64B only):");

        for (uint16_t iRs4 = 0; iRs4 < 8; iRs4++)
        {
            FAPI_DBG("0x%016lx", be64toh(*((uint64_t*)dynRs4Acc + iRs4)));
        }

        l_rc = rs4_overlay( (CompressedScanData*)i_ringBuf3,     // ringBuf3
                            OVLY_WORK_BUF_SIZE,
                            (CompressedScanData*)targetRs4,      // ringBuf1 - Tgt
                            (CompressedScanData*)dynRs4Acc,      // Acc dyn ovly ring
                            finalTypeField,
                            UNDEFINED_RS4_SELECTOR,
                            OVLY_MODE_BOSS );            // Ovly is boss

        FAPI_ASSERT( l_rc == SCAN_COMPRESSION_OK,
                     fapi2::XIPC_RS4_OVERLAY_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(be16toh(((CompressedScanData*)targetRs4)->iv_ringId)).
                     set_LOCAL_RC(l_rc).
                     set_OCCURRENCE(3),
                     "ERROR(3): rs4_overlay: Overlay operation failed w/rc=0x%08x",
                     l_rc );

        memcpy( targetRs4, i_ringBuf3, be16toh(((CompressedScanData*)i_ringBuf3)->iv_size));

        FAPI_DBG("In process_target_and_dynamic_rings(): targetRs4 (After):");

        for (uint16_t iRs4 = 0; iRs4 < (be16toh(((CompressedScanData*)targetRs4)->iv_size) + 4) / 8; iRs4++)
        {
            FAPI_DBG("0x%016lx", be64toh(*((uint64_t*)targetRs4 + iRs4)));
        }

        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
    else if(!bTargetRingFound && bDynRingFound)
    {
        //
        // In this case targetRs4 will be produced from compressing the accummulated dynamic ring
        //
        FAPI_DBG("ringId=0x%x: No Target ring found. Dynamic ring found.", i_ringId);

        memcpy(targetRs4, dynRs4Acc, be16toh(((CompressedScanData*)dynRs4Acc)->iv_size));

        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
    else if(bTargetRingFound && !bDynRingFound)
    {
        //
        // In this case targetRs4 already has the final ring
        //
        FAPI_DBG("ringId=0x%x: Target ring found. No Dynamic ring found.", i_ringId);

        finalTypeField = targetTypeField;

        ((CompressedScanData*)targetRs4)->iv_type = finalTypeField;

        ((CompressedScanData*)targetRs4)->iv_selector = UNDEFINED_RS4_SELECTOR;

        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
    else
    {
        FAPI_DBG("ringId=0x%x: No Target ring found. No Dynamic ring found.", i_ringId);

        fapi2::current_err = RC_XIPC_DYNAMIC_NO_RINGS_FOUND;
    }

    // targetRs4=io_ringBuf1 has the final ring at this point.

fapi_try_exit:

    FAPI_DBG("Exiting process_target_and_dynamic_rings");

    return fapi2::current_err;
} //End of process_target_and_dynamic_rings



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
//  void*      i ringBuf1:           Ring buffer 1
//  uint32_t   i_ringBufSize1:       Size of ring buffer 1
//  void*      i_ringBuf2:           Ring buffer 2
//  uint32_t   i_ringBufSize2:       Size of ring buffer 2
//  void*      i_ringBuf3:           Ring buffer 3
//  uint32_t   i_ringBufSize3:       Size of ring buffer 3
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
    void*           i_ringBuf1,
    uint32_t        i_ringBufSize1,
    void*           i_ringBuf2,
    uint32_t        i_ringBufSize2,
    void*           i_ringBuf3,
    uint32_t        i_ringBufSize3,
    RingProperties_t* i_ringProps,
    RingId_t        i_ringId,
    uint32_t        i_chipletSel,
    uint8_t&        io_ringStatusInMvpd,
    bool&           i_bImgOutOfSpace,
    uint32_t&       io_bootCoreMask,
    std::map<Rs4Selector_t, Rs4Selector_t>& i_idxFeatureMap,
    std::map<RingId_t, uint64_t>& io_ringIdFeatureVecMap,
    Rs4Selector_t   i_numberOfFeatures,
    void*           i_dynamicRingSection )
{
    ReturnCode   l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err  = fapi2::FAPI2_RC_SUCCESS;
    int          l_rc = INFRASTRUCT_RC_SUCCESS;;
    RingId_t     rpIndex = UNDEFINED_RING_ID;
    RingClass_t  ringClass = UNDEFINED_RING_CLASS;
    TorHeader_t* torHeader = (TorHeader_t*)i_ringSection;

    MvpdKeyword  mvpdKeyword;
    void*        vpdRing = NULL;
    uint32_t     vpdRingSize = 0;
    void*        finalVpdRing = NULL;
    uint32_t     ringBufSize1Half = i_ringBufSize1 / 2;
    uint8_t      chipletId = (uint8_t)(i_chipletSel >> 24);

    FAPI_DBG("_fetch_and_insert_vpd_ring: (ringId,chipletSel) = (0x%x,0x%08x)",
             i_ringId, i_chipletSel);

    // Check the ringId validity, then get the ring properties (rp) index
    l_rc = ringid_check_ringId( torHeader->chipId, i_ringId);

    FAPI_ASSERT( l_rc == TOR_SUCCESS,
                 fapi2::XIPC_CODE_BUG().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(4),
                 "CODE BUG(4): ringid_check_ringId() failed w/rc=0x%08x. Calling code must make"
                 " sure it passes valid ringId(=0x%x) to _fetch(). Fix calling code.\n",
                 l_rc, i_ringId);

    rpIndex = ringid_convert_ringId_to_rpIndex( i_ringId);

    ringClass = i_ringProps[rpIndex].ringClass;

    switch (ringClass & RCLS_MVPD_MASK)
    {
        case RMRK_MVPD_PDG: // #G Time rings
            mvpdKeyword = fapi2::MVPD_KEYWORD_PDG;
            break;

        case RMRK_MVPD_PDP: // #P Pll rings
            mvpdKeyword = fapi2::MVPD_KEYWORD_PDP;
            break;

        case RMRK_MVPD_PDR: // #R Repair rings
            mvpdKeyword = fapi2::MVPD_KEYWORD_PDR;
            break;

        case RMRK_MVPD_PDS: // #S Repair rings
            mvpdKeyword = fapi2::MVPD_KEYWORD_PDS;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::XIPC_INVALID_MVPD_RINGCLASS().
                         set_CHIP_TARGET(i_procTarget).
                         set_RING_ID(i_ringId).
                         set_RING_CLASS(ringClass).
                         set_KWD_MASK(RCLS_MVPD_MASK),
                         "CODE BUG: Unsupported value of ringClass (=0x%04x) or keyword"
                         " mask (=0x%04x) for ringId=0x%x",
                         ringClass, RCLS_MVPD_MASK, i_ringId );
            break;
    }

    // Initialize data buffers to zeros
    memset(i_ringBuf1, 0, i_ringBufSize1);
    memset(i_ringBuf2, 0, i_ringBufSize2);
    memset(i_ringBuf3, 0, i_ringBufSize3);

    // Fetch ring from the MVPD:
    vpdRing = i_ringBuf1;
    vpdRingSize = ringBufSize1Half; // Half size of RS4_RING_BUF_SIZE due to later overload of Buf1

    l_fapiRc = getMvpdRing( i_procTarget,
                            MVPD_RECORD_CP00,
                            mvpdKeyword,
                            i_chipletSel,
                            i_ringId,
                            (uint8_t*)vpdRing,
                            vpdRingSize ); // In: Buf space, Out: Actual size of Mvpd ring


    if (l_fapiRc == fapi2::FAPI2_RC_SUCCESS)
    {
        uint32_t rawBitLength = 0;
        l_rc = rs4_get_raw_bit_length( rawBitLength,
                                       (CompressedScanData*)vpdRing );

        FAPI_ASSERT( l_rc == SCAN_COMPRESSION_OK,
                     fapi2::XIPC_RS4_DECOMPRESS_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_MAX_RING_BUF_SIZE(RS4_RING_BUF_SIZE).
                     set_LOCAL_RC(l_rc).
                     set_OCCURRENCE(4),
                     "rs4_get_raw_bit_length() failed w/rc=0x%08x for ringId=0x%x, occurrence=4",
                     l_rc, i_ringId );

        FAPI_DBG("Ring found in origination section, Mvpd: "
                 "ringId=0x%x, size=%u and raw length=%u",
                 i_ringId, be16toh(((CompressedScanData*)vpdRing)->iv_size), rawBitLength);

        // Update for ring found in mvpd
        io_ringStatusInMvpd = RING_FOUND;

        uint32_t l_scanAddr = be32toh(((CompressedScanData*)vpdRing)->iv_scanAddr);
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
                     "CODE BUG: _fetch_and_insert_vpd_ring: VPD ring's chipletSel"
                     " (=0x%08x) doesn't match the requested chipletSel (=0x%08x)",
                     vpdChipletSel, i_chipletSel );

        // Check for Gptr ring in the .overlays section and if found overlay it onto
        // the Mvpd-Gptr ring.  Further, check for Gptr rings in the .dynamic section
        // and if found overlay them onto the previously overlaid Gptr ring.
        if ( ringClass & RMRK_GPTR_OVLY )
        {
            FAPI_TRY( process_gptr_rings(
                          i_procTarget,
                          i_overlaysSection,
                          i_ddLevel,
                          vpdRing, //In:Mvpd Gptr ring, Out: Overlaid Gptr ring
                          i_ringBuf2,
                          i_ringBuf3),
                      "process_gptr_rings() failed w/rc=0x%08x",
                      (uint32_t)current_err );

            // Here we need to overload the use of i_ringBuf1 in the call to
            // process_target_and_dynamic_rings() because it uses i_ringBuf1 in two args. So
            // we move the overlaid input Gptr ring in arg2 to the middle of ringBuf1 to allow
            // continued use of ringBuf1 work buffer in arg4 as follows:
            void* vpdRingCopy = (void*)((uint8_t*)vpdRing + ringBufSize1Half);

            memcpy( vpdRingCopy,
                    vpdRing,
                    be16toh(((CompressedScanData*)vpdRing)->iv_size) );

            FAPI_TRY( process_target_and_dynamic_rings(
                          i_procTarget,
                          false,//false means next arg is the overlaid Mvpd Gptr RS4 ring
                          vpdRingCopy,//Overloaded (false:RS4 ring in mid-Buf1,true:Base ringSection)
                          i_dynamicRingSection,
                          i_ringBuf1,//On return, contains final Gptr ring overlaid with dynamic rings
                          i_ringBuf2,
                          i_ringBuf3,
                          i_idxFeatureMap,
                          io_ringIdFeatureVecMap,
                          i_numberOfFeatures,
                          i_ringId,
                          i_ddLevel ),
                      "process_target_and_dynamic_rings() failed w/rc=0x%08x",
                      (uint32_t)current_err );

            // Update finalVpdRing and vpdRingSize to new value if any
            finalVpdRing = i_ringBuf1;
            vpdRingSize = be16toh(((CompressedScanData*)finalVpdRing)->iv_size);
        }
        else
        {
            finalVpdRing = vpdRing; // This is also ringBuf1
        }

        // Check final Mvpd ring for redundancy
        MyBool_t redundant = UNDEFINED_BOOLEAN;

        l_rc = rs4_redundant((CompressedScanData*)finalVpdRing, redundant);

        FAPI_ASSERT( l_rc == 0 && redundant != UNDEFINED_BOOLEAN,
                     fapi2::XIPC_RS4_REDUNDANT_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_LOCAL_RC(l_rc).
                     set_RING_ID(i_ringId).
                     set_CHIPLET_ID(chipletId).
                     set_REDUNDANT(redundant).
                     set_OCCURRENCE(1),
                     "ERROR: rs4_redundant failed w/rc=0x%08x or redundant=%u for"
                     " ringId=0x%x, chipletId=0x%02x, occurrence=1 ",
                     l_rc, redundant, i_ringId, chipletId );

        if (redundant)
        {
            io_ringStatusInMvpd = RING_REDUNDANT;

            FAPI_DBG("Skipping redundant MVPD ring: ringId=0x%x, chipletId=0x%02x ",
                     i_ringId, chipletId);
            fapi2::current_err = RC_XIPC_RING_IS_REDUNDANT;
            goto fapi_try_exit;
        }

        // Check for image size already out-of-space. If yes just traverse mvpd file
        // looking for remaining instance rings available if any
        if (i_bImgOutOfSpace == true)
        {
            goto fapi_try_exit;
        }

        // Checking for potential image overflow BEFORE appending the ring.
        if ( (io_ringSectionSize + vpdRingSize) > i_maxRingSectionSize )
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
                         set_SIZE_OF_THIS_RING(vpdRingSize).
                         set_MAX_RING_SECTION_SIZE(i_maxRingSectionSize).
                         set_RING_ID(i_ringId).
                         set_CHIPLET_ID(chipletId).
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
                         chipletId,
                         vpdRingSize,
                         io_ringSectionSize,
                         i_maxRingSectionSize,
                         io_bootCoreMask );
        }

        // Now, append the ring to the ring section
        l_rc = tor_append_ring(
                   i_ringSection,
                   i_maxRingSectionSize,
                   i_ringId,
                   chipletId,
                   finalVpdRing,
                   true ); //Indicate producing customized SBE/QME sections

        FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                     fapi2::XIPC_TOR_APPEND_RING_FAILED().
                     set_CHIP_TARGET(i_procTarget).
                     set_TOR_RC(l_rc).
                     set_RING_ID(i_ringId).
                     set_OCCURRENCE(1),
                     "tor_append_ring() failed in sysPhase=%d w/rc=%d for ringId=0x%x",
                     i_sysPhase, l_rc, i_ringId );

        io_ringSectionSize = be32toh(torHeader->size);

        FAPI_IMP("Successfully appended Mvpd ring w/(ringId,chipletId)=(0x%x,0x%02x) and now"
                 " ringSectionSize=%u",
                 i_ringId, chipletId, io_ringSectionSize);
    }
    else if ((uint32_t)l_fapiRc == RC_MVPD_RING_NOT_FOUND)
    {
        // Update for ring not found in mvpd
        io_ringStatusInMvpd = RING_NOT_FOUND;

        // No match, do nothing. But since rare, trace out as warning since all
        // rings we're looking for in Mvpd really should be represented there.
        FAPI_DBG("INFO(NOT-A-BUG): _fetch_and_insert_vpd_rings(): The ring w/"
                 "(ringId,chipletId)=(0x%x,0x%02x) was not found.",
                 i_ringId, chipletId);

        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
    else
    {
        //--------------------------
        // Handle other error cases
        //--------------------------

        // getMvpdRing failed due to insufficient ring buffer space.
        // Assumption here is that getMvpdRing returns required buffer size
        //   in vpdRingSize (and which it does!).
        FAPI_ASSERT( (uint32_t)l_fapiRc != RC_MVPD_RING_BUFFER_TOO_SMALL,
                     fapi2::XIPC_MVPD_RING_SIZE_TOO_BIG().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(i_ringId).
                     set_CHIPLET_ID(chipletId).
                     set_RING_BUFFER_SIZE(ringBufSize1Half).
                     set_MVPD_RING_SIZE(vpdRingSize),
                     "_fetch_and_insert_vpd_ring(): VPD ring size (=0x%X) exceeds"
                     " allowed ring buffer size (=0x%X)",
                     vpdRingSize, ringBufSize1Half );

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



//  Function: fetch_and_insert_vpd_rings()
//
//  Parameter list:
//  const fapi::Target &i_target:    Processor chip target.
//  void*      i_ringSection:        The customized ring section.
//  uint32_t&  io_ringSectionSize:   Running ring section size
//  uint32_t   i_maxRingSectionSize: Max ring section size
//  void*      i_hwImage:            HW image (needed for .overlays)
//  uint8_t    i_sysPhase:           ={IPL, RT_QME}
//  void*      i_ringBuf1:           Ring buffer 1
//  uint32_t   i_ringBufSize1:       Size of ring buffer 1
//  void*      i_ringBuf2:           Ring buffer 2
//  uint32_t   i_ringBufSize2:       Size of ring buffer 2
//  void*      i_ringBuf3:           Ring buffer 3
//  uint32_t   i_ringBufSize3:       Size of ring buffer 3
//  uint32_t&  io_bootCoreMask:      Desired (in) and actual (out) boot cores.
//  map&       i_idxFeatureMap:      List of indexed features
//  map&       io_ringIdFeatureVecMap: List of the features applied onto each ringId
//  Rs4Selector_t i_numberOfFeature: Number of features in idxFeatureMap
//  void*      i_dynamicRingSection: The .dynamic ring section
//  uint8_t    i_ddLevel:            Platform DD level
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
    void*           i_ringBuf1,
    uint32_t        i_ringBufSize1,
    void*           i_ringBuf2,
    uint32_t        i_ringBufSize2,
    void*           i_ringBuf3,
    uint32_t        i_ringBufSize3,
    std::map<Rs4Selector_t, Rs4Selector_t>& i_idxFeatureMap,
    std::map<RingId_t, uint64_t>& io_ringIdFeatureVecMap,
    Rs4Selector_t   i_numberOfFeatures,
    void*           i_dynamicRingSection,
    uint8_t         i_ddLevel,
    RingProperties_t* i_ringProps,
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
    uint8_t ringInsertionStage = NON_EQ_INSTANCE_STAGE; // 0:NON_EQ_INSTANCE_STAGE, 1:EQ_INSTANCE_STAGE

    // Initialize activeCoreMask to be filled up with EC column filling as it progresses
    uint32_t l_activeCoreMask  = 0x0;
    uint32_t l_bootCoreMaskMin = 0x0;

    TorHeader_t* torHeader  = (TorHeader_t*)i_ringSection;
    uint32_t     torMagic = be32toh(torHeader->magic);
    uint8_t      torVersion = torHeader->version;

    FAPI_DBG("Entering fetch_and_insert_vpd_rings");


    // Let's get the .overlays ring section up front
    P9XipSection iplImgSection;
    void* l_overlaysSection = NULL;
    l_rc = p9_xip_get_section(i_hwImage, P9_XIP_SECTION_HW_OVERLAYS, &iplImgSection, i_ddLevel);

    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                 fapi2::XIPC_XIP_GET_SECTION_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_XIP_RC(l_rc).
                 set_SECTION_ID(P9_XIP_SECTION_HW_OVERLAYS).
                 set_DDLEVEL(i_ddLevel).
                 set_OCCURRENCE(6),
                 "p9_xip_get_section() failed (6) w/rc=0x%08x getting .overlays"
                 " section for ddLevel=0x%x",
                 (uint32_t)l_rc, i_ddLevel );

    l_overlaysSection = (void*)((uint8_t*)i_hwImage + iplImgSection.iv_offset);


    // Walk through all Vpd rings and add any that's there to the image.
    // Do this in two steps:
    // 1- Add all NEST rings
    // 2- Add QUAD rings in EC order

    RingId_t          rpIndex; // Ring properties (rp) index counter
    RingClass_t       ringClass;
    ChipletData_t*    l_chipletData;
    ChipletData_t*    l_chipletDataEQ, *l_chipletDataEC;
    uint8_t           iInstance;
    uint8_t           l_chipletId;  // Nibbles {0,1} of scanScomAddr
    uint32_t          l_regionSel;  // Nibbles {2,4,5,6} of scanScomAddr (region select target)
    uint32_t          l_chipletSel; // Combination of chipletId and regionSel


    // ---------------------------------------------------------------------------------
    // 1- Add Common rings and Perv Instance rings (ie, all non-EQ/core Instance rings)
    // ---------------------------------------------------------------------------------
    ringInsertionStage = NON_EQ_INSTANCE_STAGE;

    for ( rpIndex = 0; rpIndex < NUM_RING_IDS; rpIndex++ )
    {

        ringClass = i_ringProps[rpIndex].ringClass;

        if ( ( ringClass != UNDEFINED_RING_CLASS )  &&
             ( ringClass & RCLS_MVPD_MASK )  &&
             ( (ringClass & RCLS_MVPD_PDR_EQ) != RCLS_MVPD_PDR_EQ )  &&
             ( (ringClass & RCLS_MVPD_PDR_CORE) != RCLS_MVPD_PDR_CORE ) &&
             ( (ringClass & RCLS_MVPD_PDS_EQ) != RCLS_MVPD_PDS_EQ )  &&
             ( (ringClass & RCLS_MVPD_PDS_CORE) != RCLS_MVPD_PDS_CORE ) )
        {
            l_rc = ringid_get_chipletProps( CID_P10,
                                            torMagic,
                                            torVersion,
                                            i_ringProps[rpIndex].chipletType,
                                            &l_chipletData );

            FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                         fapi2::XIPC_RINGID_CHIPLETPROPS_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_LOCAL_RC(l_rc).
                         set_TOR_MAGIC(torMagic).
                         set_TOR_VER(torVersion).
                         set_CHIPLET_TYPE(i_ringProps[rpIndex].chipletType).
                         set_RING_ID(i_ringProps[rpIndex].ringId).
                         set_OCCURRENCE(1),
                         "ringid_get_chipletProps(): Failed w/rc=%i for"
                         " TOR magic = 0x%04x, TOR version = %d,"
                         " chipletType = %d, ringId = 0x%x,"
                         " occurrence=1",
                         l_rc, torMagic, torVersion,
                         i_ringProps[rpIndex].chipletType,
                         i_ringProps[rpIndex].ringId );

            for (iInstance = 0; iInstance < l_chipletData->numChipletInstances; iInstance++)
            {

                l_chipletId = l_chipletData->chipletBaseId + iInstance;
                l_chipletSel = ((uint32_t)l_chipletId) << 24;

                // Fetch Common and Perv Instance rings (i.e., non-Eq Instance rings)
                // - Fetch all Mvpd rings for SBE.
                // - Fetch QME scannable Mvpd rings for QME.

                if ( i_sysPhase == SYSPHASE_HB_SBE   ||
                     ( i_sysPhase == SYSPHASE_RT_QME && ( ringClass & RMRK_SCAN_BY_QME ) ) )
                {
                    l_fapiRc = _fetch_and_insert_vpd_rings (
                                   i_procTarget,
                                   i_ringSection,
                                   io_ringSectionSize,
                                   i_maxRingSectionSize,
                                   l_overlaysSection,
                                   i_ddLevel,
                                   i_sysPhase,
                                   i_ringBuf1,
                                   i_ringBufSize1,
                                   i_ringBuf2,
                                   i_ringBufSize2,
                                   i_ringBuf3,
                                   i_ringBufSize3,
                                   i_ringProps,
                                   i_ringProps[rpIndex].ringId,
                                   l_chipletSel,
                                   l_ringStatusInMvpd,
                                   l_bImgOutOfSpace,
                                   io_bootCoreMask,
                                   i_idxFeatureMap,
                                   io_ringIdFeatureVecMap,
                                   i_numberOfFeatures,
                                   i_dynamicRingSection );

                    if (   (uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW ||
                           ( (uint32_t)l_fapiRc != RC_XIPC_RING_IS_REDUNDANT &&
                             l_fapiRc != fapi2::FAPI2_RC_SUCCESS ) )
                    {
                        fapi2::current_err = l_fapiRc;
                        FAPI_ERR("_fetch_and_insert_vpd_rings() failed inserting NON_EQ_INSTANCE"
                                 " Mvpd rings w/rc=0x%.8x",
                                 (uint64_t)fapi2::current_err );
                        goto fapi_try_exit;
                    }

                    FAPI_DBG("(CMN+PERVINST) io_ringSectionSize = %d", io_ringSectionSize);
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                }
            } // End of for(iInstance)
        }
    } // End of for(rpIndex)

    // ------------------------------------------------------------
    // 2- Add EQ-level instance rings (ie, EQ/core Instance rings)
    // ------------------------------------------------------------
    ringInsertionStage =  EQ_INSTANCE_STAGE;

    // Add all instance [QUAD-level] rings in order - EQ->EC.
    // Looking at the bootCoreMask start adding EQ first followed
    // by EC VPD ring insertion in order.
    // For common rings already completed in above step #1.
    // The step #2 instance part is updated looping over chipletId
    // to fill up one core chipletId "column" at a time (RTC158106).

    // Loop for EQ/EC filling
    for (eq = 0; eq < NUM_OF_QMES; eq++)
    {

        // CMO-20200604:
        // In p10, unlike in p9, the quads/QMEs are expected to always be good
        // and active, and essentially part of the nest set of chiplets.  Therefore
        // all QMEs, even if one or more of them have no EC cores indicated in the
        // bootCoreMask, still need to come online and thus need instance rings
        // like the eq_repr and eq_gptr_ovly. So the check we used to have here in
        // p9 for whether any cores are indicated in the bootCoreMask for the
        // current quad, and if not then skip this quad, has been deleted.

        for ( rpIndex = 0; rpIndex < NUM_RING_IDS; rpIndex++ )
        {

            //
            // Determine if ringId belongs to relevant Mvpd #R EQ ringClass. If so,
            // then try fetch the ring from Mvpd and append it to ring section.
            // In principle, Since only the SBE can scan QME ring, e.g. eq_xyz_ring,
            // we could limit the ring search to just the HB_SBE phase. But to be
            // consistent, and in case for some reason suddenly the QME is able to
            // "scan itself", we consider the RT_QME phase here as well.
            //
            ringClass = i_ringProps[rpIndex].ringClass;

            if ( ( ringClass != UNDEFINED_RING_CLASS )  &&
                 ( ( (ringClass & RCLS_MVPD_PDR_EQ) == RCLS_MVPD_PDR_EQ )  ||
                   ( (ringClass & RCLS_MVPD_PDS_EQ) == RCLS_MVPD_PDS_EQ ) )  &&
                 ( i_sysPhase == SYSPHASE_HB_SBE  ||
                   ( i_sysPhase == SYSPHASE_RT_QME && (ringClass & RMRK_SCAN_BY_QME) ) ) )
            {
                l_rc = ringid_get_chipletProps(
                           CID_P10,
                           torMagic,
                           torVersion,
                           i_ringProps[rpIndex].chipletType,
                           &l_chipletDataEQ );

                FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                             fapi2::XIPC_RINGID_CHIPLETPROPS_ERROR().
                             set_CHIP_TARGET(i_procTarget).
                             set_LOCAL_RC(l_rc).
                             set_TOR_MAGIC(torMagic).
                             set_TOR_VER(torVersion).
                             set_CHIPLET_TYPE(i_ringProps[rpIndex].chipletType).
                             set_RING_ID(i_ringProps[rpIndex].ringId).
                             set_OCCURRENCE(2),
                             "ringid_get_chipletProps(): Failed w/rc=%i for"
                             " TOR magic = 0x%04x, TOR version = %d,"
                             " chipletType = %d, ringId = 0x%x,"
                             " occurrence=2",
                             l_rc, torMagic, torVersion,
                             i_ringProps[rpIndex].chipletType,
                             i_ringProps[rpIndex].ringId );

                l_chipletId = l_chipletDataEQ->chipletBaseId + eq;
                l_chipletSel = ((uint32_t)l_chipletId) << 24;

                FAPI_DBG("EQ=%d; chipletId=0x%02x, ringName:%s",
                         eq, l_chipletId, i_ringProps[rpIndex].ringName);

                // Update for ring in scan mode
                l_ringStatusInMvpd = RING_SCAN;

                l_fapiRc = _fetch_and_insert_vpd_rings (
                               i_procTarget,
                               i_ringSection,
                               io_ringSectionSize,
                               i_maxRingSectionSize,
                               l_overlaysSection,
                               i_ddLevel,
                               i_sysPhase,
                               i_ringBuf1,
                               i_ringBufSize1,
                               i_ringBuf2,
                               i_ringBufSize2,
                               i_ringBuf3,
                               i_ringBufSize3,
                               i_ringProps,
                               i_ringProps[rpIndex].ringId,
                               l_chipletSel,
                               l_ringStatusInMvpd,
                               l_bImgOutOfSpace,
                               io_bootCoreMask,
                               i_idxFeatureMap,
                               io_ringIdFeatureVecMap,
                               i_numberOfFeatures,
                               i_dynamicRingSection );

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
                else if ( (uint32_t)l_fapiRc != RC_XIPC_RING_IS_REDUNDANT &&
                          l_fapiRc != fapi2::FAPI2_RC_SUCCESS )
                {
                    fapi2::current_err = l_fapiRc;
                    FAPI_ERR("_fetch_and_insert_vpd_rings() failed inserting EQ_INSTANCE"
                             " Mvpd rings w/rc=0x%.8x",
                             (uint64_t)fapi2::current_err );
                    goto fapi_try_exit;
                }

                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

            } // Done w/fetch_and_insert() current EQ instance ring

        } // End of for(rpIndex) for the current eq

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

            for ( rpIndex = 0; rpIndex < NUM_RING_IDS; rpIndex++ )
            {

                //
                // Determine if ringId belongs to relevant Mvpd #R EC ringClass. If so,
                // then try fetch the ring from Mvpd and append it to ring section.
                //
                ringClass = i_ringProps[rpIndex].ringClass;

                if ( ( ringClass != UNDEFINED_RING_CLASS )  &&
                     ( ( (ringClass & RCLS_MVPD_PDR_CORE) == RCLS_MVPD_PDR_CORE )  ||
                       ( (ringClass & RCLS_MVPD_PDS_CORE) == RCLS_MVPD_PDS_CORE ) )  &&
                     ( i_sysPhase == SYSPHASE_HB_SBE  ||
                       ( i_sysPhase == SYSPHASE_RT_QME && (ringClass & RMRK_SCAN_BY_QME) ) ) )
                {
                    l_rc = ringid_get_chipletProps(
                               CID_P10,
                               torMagic,
                               torVersion,
                               i_ringProps[rpIndex].chipletType,
                               &l_chipletDataEC );

                    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                                 fapi2::XIPC_RINGID_CHIPLETPROPS_ERROR().
                                 set_CHIP_TARGET(i_procTarget).
                                 set_LOCAL_RC(l_rc).
                                 set_TOR_MAGIC(torMagic).
                                 set_TOR_VER(torVersion).
                                 set_CHIPLET_TYPE(i_ringProps[rpIndex].chipletType).
                                 set_RING_ID(i_ringProps[rpIndex].ringId).
                                 set_OCCURRENCE(3),
                                 "ringid_get_chipletProps(): Failed w/rc=%i for"
                                 " TOR magic = 0x%04x, TOR version = %d,"
                                 " chipletType = %d, ringId = 0x%x,"
                                 " occurrence=3",
                                 l_rc, torMagic, torVersion,
                                 i_ringProps[rpIndex].chipletType,
                                 i_ringProps[rpIndex].ringId );

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
                    l_regionSel = i_ringProps[rpIndex].scanScomAddr & l_regionSel;
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
                                 ec, l_chipletSel, i_ringProps[rpIndex].ringName, quadrant);
                        continue;
                    }

                    FAPI_DBG("EC=%d: chipletSel=0x%08x, ringName=%s",
                             ec, l_chipletSel, i_ringProps[rpIndex].ringName);

                    // Update for ring in scan mode
                    l_ringStatusInMvpd = RING_SCAN;

                    l_fapiRc = _fetch_and_insert_vpd_rings (
                                   i_procTarget,
                                   i_ringSection,
                                   io_ringSectionSize,
                                   i_maxRingSectionSize,
                                   l_overlaysSection,
                                   i_ddLevel,
                                   i_sysPhase,
                                   i_ringBuf1,
                                   i_ringBufSize1,
                                   i_ringBuf2,
                                   i_ringBufSize2,
                                   i_ringBuf3,
                                   i_ringBufSize3,
                                   i_ringProps,
                                   i_ringProps[rpIndex].ringId,
                                   l_chipletSel,
                                   l_ringStatusInMvpd,
                                   l_bImgOutOfSpace,
                                   io_bootCoreMask,
                                   i_idxFeatureMap,
                                   io_ringIdFeatureVecMap,
                                   i_numberOfFeatures,
                                   i_dynamicRingSection );

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
                    else if ( (uint32_t)l_fapiRc != RC_XIPC_RING_IS_REDUNDANT &&
                              l_fapiRc != fapi2::FAPI2_RC_SUCCESS )
                    {
                        fapi2::current_err = l_fapiRc;
                        FAPI_ERR("_fetch_and_insert_vpd_rings() failed inserting VPD EC Instance rings w/rc=0x%.8x",
                                 (uint64_t)fapi2::current_err );
                        goto fapi_try_exit;
                    }
                    else if ( ( l_fapiRc == fapi2::FAPI2_RC_SUCCESS     ||
                                (uint32_t)l_fapiRc == RC_XIPC_RING_IS_REDUNDANT ||
                                (uint32_t)l_fapiRc == RC_MVPD_RING_NOT_FOUND ) &&
                              l_bImgOutOfSpace == false )
                    {
                        FAPI_DBG("(EQINST) io_ringSectionSize = %d", io_ringSectionSize);
                        l_activeCoreMask |= (uint32_t)( 1 << ((NUM_OF_CORES - 1) - ec) );
                    }

                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

                } // Done inserting current ec core instance ring

            } //for(rpIndex) - Done inserting all core instance rings for current ec core

        } //for (quadrant=0; quadrant<CORES_PER_QME; quadrant++)

    } //for (eq=0; eq<NUM_OF_QMES; eq++)


fapi_try_exit:

    if( (ringInsertionStage == NON_EQ_INSTANCE_STAGE) &&
        (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS) )
    {
        //Error handling:
        //- When image runs out-of-space during insertion of common rings and perv instance rings
        //- Any other 'unknown/unexpected' error reported
        io_bootCoreMask = 0;
        FAPI_IMP("bootCoreMask value: 0x%08x", io_bootCoreMask);
        FAPI_DBG("Exiting fetch_and_insert_vpd_rings w/rc=0x%08x", (uint32_t)fapi2::current_err);
        return fapi2::current_err;
    }
    else if( (ringInsertionStage == EQ_INSTANCE_STAGE) &&
             (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS) )
    {
        //Error handling:
        //- When image runs out-of-space during insertion of EQ/core instance rings
        //- Any other 'unknown/unexpected' error reported
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
                                         "CODE BUG(1): Incorrect EC mask. Should never get here. Fix code!" );
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
    uint8_t   i_sysPhase,               // {HB_SBE,RT_QME,HB_MEAS}
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
#define nullptr NULL
#endif
    int             l_rc = 0; // Non-fapi RC

    int mainSectionID = UNDEFINED_IPL_IMAGE_SID; // Represents the nested PPE image
    int subSectionID  = UNDEFINED_IPL_IMAGE_SID; // Represents .rings within nested image
    P9XipSection    iplImgSection;
    //Suggested replacement typedef name:
    //IplImgSection   iplImgSection; // Formerly: P9XipSection xipSection.
    uint32_t        l_inputImageSize;
    uint32_t        l_imageSizeWithoutRings;
    uint32_t        l_currentImageSize;
    uint32_t        l_maxImageSize = 0;   // Attrib adjusted local value of MAX_SEEPROM_IMAGE_SIZE
    uint32_t        l_maxRingSectionSize; // Max size of ringSection
    uint32_t        l_ringSectionBufSize; // Size of ringSection buffer passed by platform
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

    RingProperties_t* ringProps = nullptr; // Ring properties list
    RingId_t        ringId = UNDEFINED_RING_ID;
    RingId_t        rpIndex = UNDEFINED_RING_ID; // Ring properties (rp) index
#ifndef WIN32
    p10_dyninit_bitvec featureVec; // Dynamic inits feature vector
#endif
    std::map< Rs4Selector_t,  Rs4Selector_t> idxFeatureMap;
    std::map<RingId_t, uint64_t> ringIdFeatureVecMap;
    uint8_t*        ringIdFeatList = NULL;
    uint16_t        ringIdFeatListSize = 0;
    uint16_t        listPos = 0;
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
                     "p9_xip_image_size() failed (1) w/rc=0x%08x",
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
                 i_ringBufSize1 == RS4_RING_BUF_SIZE &&
                 i_ringBufSize2 == RS4_RING_BUF_SIZE &&
                 i_ringBufSize3 == OVLY_WORK_BUF_SIZE,
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

//#ifndef WIN32    this is where Joe had ifdef  mcs

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
    // CUSTOMIZE item:     Update PIBMEM repair section in Seeprom image
    // System phase:       HB_MEAS
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_MEAS)
    {
        uint8_t* bufMvpdField = (uint8_t*)i_ringBuf1;
        uint32_t vpdRingSize = i_ringBufSize1;
        uint32_t maxRingByteSize = RS4_RING_BUF_SIZE;
        uint8_t* dataVpd = (uint8_t*)i_ringBuf2;
        uint8_t* careVpd = (uint8_t*)i_ringBuf2 + maxRingByteSize / 2;
        uint8_t* scomTbl = (uint8_t*)i_ringBuf3;
        uint32_t uncmpSize = 0;
        uint32_t tblSize = 0;
        RingId_t perv_pib_repr = pib_repr;
        uint8_t  chipletId = 0x01; // TP chiplet
        uint64_t scanRegionType = 0x0200000000000200ull; // pib_repr
        l_rc = INFRASTRUCT_RC_SUCCESS;

        // Memset the data
        memset(bufMvpdField, 0, i_ringBufSize1);
        memset(dataVpd, 0, maxRingByteSize / 2);
        memset(careVpd, 0, maxRingByteSize / 2);

        // Fetch ring from the MVPD:
        FAPI_TRY( getMvpdRing( i_procTarget,
                               MVPD_RECORD_CP00,
                               fapi2::MVPD_KEYWORD_PDR,
                               (uint32_t) (chipletId << 24),
                               perv_pib_repr,
                               bufMvpdField,
                               vpdRingSize ),
                  "getMvpdRing() failed for PIBREPR Ring w/rc=0x%08X",
                  (uint64_t)fapi2::current_err );

        // Uncompress the RS4 to raw ring (perv_pib_repr is short at only ~1200bits,
        // so ok to use rs4_decompress() here)
        l_rc = _rs4_decompress( dataVpd,
                                careVpd,
                                (maxRingByteSize / 2),
                                &uncmpSize,
                                (CompressedScanData*)bufMvpdField );

        FAPI_ASSERT( l_rc == SCAN_COMPRESSION_OK,
                     fapi2::XIPC_RS4_DECOMPRESS_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(perv_pib_repr).
                     set_MAX_RING_BUF_SIZE(RS4_RING_BUF_SIZE).
                     set_LOCAL_RC(l_rc).
                     set_OCCURRENCE(1),
                     "rs4_decompress() for pibmem repair: Failed w/rc=%i "
                     "for perv_pib_repr=ringId=0x%03x, chipletId=0x%02x",
                     l_rc, perv_pib_repr, chipletId );

        FAPI_DBG("Ring found in origination section, Mvpd: "
                 "perv_pib_repr=ringId=0x%x, size=%u and raw length=%u",
                 perv_pib_repr, be16toh(((CompressedScanData*)bufMvpdField)->iv_size), uncmpSize);

        // Contruct repair table to encode raw bit stream into rows of scoms
        // for the SBE bootloader to parse and execute in raw scoms
        FAPI_TRY( p10_expand_ring_util( chipletId,
                                        scanRegionType,
                                        scomTbl,
                                        tblSize,
                                        uncmpSize,
                                        dataVpd ),
                  "Error in p10_expand_ring_util w/rc = 0x%08X",
                  (uint64_t)fapi2::current_err );

        FAPI_INF("p9_expand_ring_util returned a table of length %d from "
                 "perv_pib_repr ring of size %d", tblSize, uncmpSize);

        FAPI_TRY( p10_ipl_section_append( (void*)scomTbl,
                                          tblSize,
                                          P9_XIP_SECTION_SBE_PIBREPRDATA,
                                          io_image,
                                          io_imageSize),
                  "p10_ipl_section_append() failed w/rc=0x%08X",
                  (uint64_t)fapi2::current_err );
    }

    ///////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Write progdelay/duty cycle attributes
    // System phase:       HB_SBE
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {

        uint32_t       sizeMvpdMKField = 0;
        uint8_t*       fullMKData = nullptr;
        const uint8_t  MVPD_MK_KWD_VER1 = 0x01;
#ifndef WIN32
        fapi2::ATTR_SKEWADJ_CORE_PDLY_OVERRIDE_Type  l_attr_skewadj_core_pdly_override = 0;
        fapi2::ATTR_SKEWADJ_CACHE_PDLY_OVERRIDE_Type l_attr_skewadj_cache_pdly_override = 0;
        fapi2::ATTR_DCADJ_DCC_OVERRIDE_Type          l_attr_dcadj_dcc_override = 0;
        fapi2::ATTR_DCADJ_TARGET_OVERRIDE_Type       l_attr_dcadj_target_override = 0;
#else
        int l_attr_skewadj_core_pdly_override = 0;
        int l_attr_skewadj_cache_pdly_override = 0;
        int l_attr_dcadj_dcc_override = 0;
        int l_attr_dcadj_target_override = 0;
#endif
        // Get Mvpd MK level
        FAPI_TRY(getMvpdField(fapi2::MVPD_RECORD_CP00,
                              fapi2::MVPD_KEYWORD_MK,
                              i_procTarget,
                              NULL,
                              sizeMvpdMKField),
                 "getMvpdField failed for CP00/MK (1) w/rc=0x%08x",
                 (uint64_t)fapi2::current_err);

        fullMKData = new uint8_t[sizeMvpdMKField]();

        FAPI_TRY(getMvpdField(fapi2::MVPD_RECORD_CP00,
                              fapi2::MVPD_KEYWORD_MK,
                              i_procTarget,
                              fullMKData,
                              sizeMvpdMKField),
                 "getMvpdField failed for CP00/MK (2) w/rc=0x%08x and"
                 "MK size is of %u bytes",
                 (uint64_t)fapi2::current_err, sizeMvpdMKField);

        //Size of MK keyword is 7 bytes. 1st byte is keyword version,
        //Checking the keyword version
        FAPI_ASSERT((fullMKData[0] == MVPD_MK_KWD_VER1),
                    fapi2::XIPC_MVPD_MK_KEYWORD_VERSION_ERROR().
                    set_CHIP_TARGET(i_procTarget).
                    set_MVPD_MK_KWD_VERSION(fullMKData[0]).
                    set_MVPD_MKSIZE(sizeMvpdMKField),
                    "MK Keyword version from MVPD is 0x%0x, "
                    "size of MK keyword is %u",
                    fullMKData[0], sizeMvpdMKField);

        if (fullMKData[1] & 0x80)
        {
            l_attr_skewadj_core_pdly_override = 0x8000 |
                                                ((fullMKData[1] >> 0) & 0x0F);
        }

        if (fullMKData[1] & 0x40)
        {
            l_attr_skewadj_cache_pdly_override = 0x8000 |
                                                 ((fullMKData[2] >> 4) & 0x0F);
        }

        if (fullMKData[2] & 0x08)
        {
            l_attr_dcadj_dcc_override = 0x8000 |
                                        (fullMKData[3]);
        }

        if (fullMKData[2] & 0x04)
        {
            l_attr_dcadj_target_override = 0x8000 |
                                           (fullMKData[4]);
        }

#ifndef WIN32
        // populate platform attribute state
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SKEWADJ_CORE_PDLY_OVERRIDE,  i_procTarget, l_attr_skewadj_core_pdly_override));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SKEWADJ_CACHE_PDLY_OVERRIDE, i_procTarget, l_attr_skewadj_cache_pdly_override));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_DCADJ_DCC_OVERRIDE,          i_procTarget, l_attr_dcadj_dcc_override));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_DCADJ_TARGET_OVERRIDE,       i_procTarget, l_attr_dcadj_target_override));

        // customize image
        MBOX_ATTR_WRITE(ATTR_SKEWADJ_CORE_PDLY_OVERRIDE,  i_procTarget, io_image);
        MBOX_ATTR_WRITE(ATTR_SKEWADJ_CACHE_PDLY_OVERRIDE, i_procTarget, io_image);
        MBOX_ATTR_WRITE(ATTR_DCADJ_DCC_OVERRIDE,          i_procTarget, io_image);
        MBOX_ATTR_WRITE(ATTR_DCADJ_TARGET_OVERRIDE,       i_procTarget, io_image);
#else
        MBOX_ATTR_WRITE(ATTR_SKEWADJ_CORE_PDLY_OVERRIDE,  l_attr_skewadj_core_pdly_override , io_image);
        MBOX_ATTR_WRITE(ATTR_SKEWADJ_CACHE_PDLY_OVERRIDE, l_attr_skewadj_cache_pdly_override, io_image);
        MBOX_ATTR_WRITE(ATTR_DCADJ_DCC_OVERRIDE,          l_attr_dcadj_dcc_override,          io_image);
        MBOX_ATTR_WRITE(ATTR_DCADJ_TARGET_OVERRIDE,       l_attr_dcadj_target_override,       io_image);
#endif
        delete fullMKData;
        fullMKData = NULL;
    }

//#endif     comment end Joe #ifndef WIN32

    ///////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:  Removal of .toc, .fixed_toc and .strings and adjustment
    //                  of max Seeprom image size.
    // System phase:    HB_SBE/HB_MEAS
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE ||
        i_sysPhase == SYSPHASE_HB_MEAS)
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

        // confirm image size
        if (i_sysPhase == SYSPHASE_HB_SBE)
        {
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
        else
        {
            l_maxImageSize = MAX_MEAS_SEEPROM_IMAGE_SIZE;

            // Make sure current image size isn't already too big for Seeprom
            FAPI_ASSERT( l_currentImageSize <= l_maxImageSize,
                         fapi2::XIPC_IMAGE_TOO_LARGE().
                         set_CHIP_TARGET(i_procTarget).
                         set_IMAGE_SIZE(l_currentImageSize).
                         set_MAX_IMAGE_SIZE(l_maxImageSize).
                         set_OCCURRENCE(1),
                         "Image size before VPD updates (=%d) already exceeds max image size (=%d)",
                         l_currentImageSize, l_maxImageSize );

            // done, no further customization required for measurement seeprom image
            goto fapi_try_exit;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    // CUSTOMIZE item:     Copy DD-specific .fa_xyz fastarray binaries to
    //                     Seeprom image.
    // System phase:       HB_SBE
    //////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        // Setup up nested section ID combination for SBE PPE image
        mainSectionID = P9_XIP_SECTION_HW_SBE;

        for (uint8_t iSection = 0; iSection < FA_IPL_SECTIONS; iSection++)
        {
            switch (iSection)
            {
                case FA_EC_CL2_FAR:
                    subSectionID = P9_XIP_SECTION_SBE_FA_EC_CL2_FAR;
                    break;

                case FA_EC_MMA_FAR:
                    subSectionID = P9_XIP_SECTION_SBE_FA_EC_MMA_FAR;
                    break;

                case FA_RING_OVRD:
                    subSectionID = P9_XIP_SECTION_SBE_FA_RING_OVRD;
                    break;

                default:
                    subSectionID = UNDEFINED_IPL_IMAGE_SID;
                    break;
            }

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
                         "p9_xip_get_sub_section() failed (2) w/rc=0x%08X retrieving SBE IPL"
                         " section ID=%u and ddLevel=0x%x",
                         (uint32_t)l_rc, subSectionID, attrDdLevel );

            l_rc = p9_xip_append( io_image,       // *must* be an SBE image
                                  subSectionID,
                                  (void*)((uint8_t*)i_hwImage + iplImgSection.iv_offset),
                                  iplImgSection.iv_size,
                                  l_maxImageSize,
                                  &l_sectionOffset,
                                  0 );

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_APPEND_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_SECTION_ID(subSectionID).
                         set_MAX_IMAGE_SIZE(l_maxImageSize).
                         set_OCCURRENCE(1),
                         "ERROR(1,%u): p9_xip_append() failed w/rc=0x%08x",
                         iSection, (uint32_t)l_rc );
        }
    }




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
                         set_OCCURRENCE(3),
                         "p9_xip_get_sub_section() failed (3) w/rc=0x%08X retrieving .sbe.rings"
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
                         set_OCCURRENCE(4),
                         "p9_xip_get_sub_section() failed (4) w/rc=0x%08x retrieving .qme.rings"
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

    // Point baseRingSection to either the DD specific ring section in the SBE
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

    // We will be needing the ring properties (rp) list for both Dynamic and Mvpd rings
    l_rc = ringid_get_ringProps( CID_P10, &ringProps);

    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                 fapi2::XIPC_RINGID_RINGPROPS_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_LOCAL_RC(l_rc).
                 set_OCCURRENCE(1),
                 "ringid_get_ringProps(): Failed w/rc=%i for occurrence=1",
                 l_rc );

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
    // customized ring section as follows:
    // - copy:    Is performed when a ring is only found in the .{sbe,qme}.rings
    //            ring section (ie, no Dynamic ring is found).
    // - overlay: Is performed when rings are found in both the .{sbe,qme}.rings
    //            and .dynamic ring sections.
    // - produce: Is performed when a ring is only found in the .dynamic ring
    //            ring section (ie, no Base ring is found) and in which case the Dynamic
    //            ring becomes the de facto Base ring.
    //////////////////////////////////////////////////////////////////////////

#ifdef WIN32
    //// statically select only Hostboot dynamic init
    //featureVec.iv_bits.push_back(0x1000000000000000ULL);
    //featureVec.iv_bit_count = 3;
    //featureVec.iv_source = MERGED;
    //featureVec.iv_type = FEATURE;

    uint64_t featureVec = 0x1000000000000000ULL;

    // Index the features in a map
    for(Rs4Selector_t feature = 0; feature < 64; feature++)
    {
        if( featureVec & (0x8000000000000000 >> feature) )
        {
            idxFeatureMap.insert(std::make_pair(numberOfFeatures, feature));
            numberOfFeatures++;
        }
    }

#else
    // call p10_boot_mode HWP to calculate dynamic init vector
    FAPI_EXEC_HWP(l_rc,
                  p10_boot_mode,
                  i_procTarget,
                  i_hwImage,
                  i_sysPhase,
                  featureVec);

    if (l_rc)
    {
        FAPI_ERR("Error from p10_boot_mode");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    // Index the features in a map
    for (Rs4Selector_t feature = 0; feature < featureVec.iv_bit_count; feature++)
    {
        if ( featureVec.iv_bits[feature / 64] & ( 0x8000000000000000 >> (feature % 64) ) )
        {
            idxFeatureMap.insert({numberOfFeatures, feature});
            numberOfFeatures++;
        }
    }

#endif

    //
    // Extract the .dynamic ring section from the HW image and process all Base
    // and Dynamic rings. (Note that the Base ring section was extracted earlier.)
    //
    l_rc = p9_xip_get_section(i_hwImage, P9_XIP_SECTION_HW_DYNAMIC, &iplImgSection, attrDdLevel);

    FAPI_ASSERT( l_rc == INFRASTRUCT_RC_SUCCESS,
                 fapi2::XIPC_XIP_GET_SECTION_ERROR().
                 set_CHIP_TARGET(i_procTarget).
                 set_XIP_RC(l_rc).
                 set_SECTION_ID(P9_XIP_SECTION_HW_DYNAMIC).
                 set_DDLEVEL(attrDdLevel).
                 set_OCCURRENCE(5),
                 "p9_xip_get_section() failed (5) w/rc=0x%08X getting .dynamic"
                 " section for ddLevel=0x%x",
                 (uint32_t)l_rc, attrDdLevel );

    dynamicRingSection = (void*)((uint8_t*)i_hwImage + iplImgSection.iv_offset);

    for (rpIndex = 0; rpIndex < NUM_RING_IDS; rpIndex++)
    {
        // Get the ringId from the RP list
        ringId = ringProps[rpIndex].ringId;

        // Only process non-Mvpd (which are all Common rings)
        if ( ringid_is_mvpd_ring(torHeaderBase->chipId, ringId) == true ||
             ringId == HOLE_RING_ID )
        {
            continue;
        }

        l_fapiRc = process_target_and_dynamic_rings(
                       i_procTarget,
                       true,//true means next arg is Base ringSection ptr
                       baseRingSection,//Overloaded (false:RS4 ring in mid-Buf1,true:Base section)
                       dynamicRingSection,
                       i_ringBuf1,//On return, contains Base ring overlaid with dynamic rings
                       i_ringBuf2,
                       i_ringBuf3,
                       idxFeatureMap,
                       ringIdFeatureVecMap,
                       numberOfFeatures,
                       ringId,
                       attrDdLevel );

        FAPI_ASSERT( ((l_fapiRc == FAPI2_RC_SUCCESS) ||
                      ((uint32_t) l_fapiRc == RC_XIPC_DYNAMIC_NO_RINGS_FOUND)),
                     fapi2::XIPC_DYNAMIC_INIT_FAILED().
                     set_CHIP_TARGET(i_procTarget).
                     set_RING_ID(ringId),
                     "process_base_and_dynamic_rings failed for "
                     "ringId=0x%x w/rc=0x%08x",
                     ringId, (uint32_t)l_fapiRc);

        if (l_fapiRc == FAPI2_RC_SUCCESS)
        {
            l_rc = tor_append_ring(
                       io_ringSectionBuf,
                       l_maxRingSectionSize,
                       ringId,
                       UNDEFINED_CHIPLET_ID,
                       i_ringBuf1,
                       true ); //We're customizing the SBE/QME sections now

            FAPI_ASSERT( l_rc == TOR_SUCCESS ||
                         l_rc == TOR_INVALID_CHIPLET_TYPE || // Will get this for RT_QME phase
                         l_rc == TOR_RING_HAS_DERIVS,
                         fapi2::XIPC_TOR_APPEND_RING_FAILED().
                         set_CHIP_TARGET(i_procTarget).
                         set_TOR_RC(l_rc).
                         set_RING_ID(ringId).
                         set_OCCURRENCE(1),
                         "tor_append_ring() failed in process_base_and_dynamic_rings w/rc=0x%08x"
                         " for ringId=0x%x",
                         l_rc, ringId );

            io_ringSectionBufSize = be32toh(((TorHeader_t*)io_ringSectionBuf)->size);

            switch (l_rc)
            {
                case TOR_SUCCESS:
                    FAPI_IMP("Successfully appended Base or Dynamic ring w/ringId=0x%x"
                             " and now ringSectionSize=%u",
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
                                 "CODE BUG(2): Messed up RC handling in assoc code. Fix code!" );
                    break;
            }
        }
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
    for (uint8_t iType = 0; iType < MVPD_RING_TYPES; iType++)
    {
        switch (iType)
        {
            case MVPD_RING_PDG:
                mvpdKeyword = fapi2::MVPD_KEYWORD_PDG;
                break;

            case MVPD_RING_PDP:
                // Reinstate next line when/if #P needs support
                //mvpdKeyword = fapi2::MVPD_KEYWORD_PDP;
                continue;

            case MVPD_RING_PDR:
                mvpdKeyword = fapi2::MVPD_KEYWORD_PDR;
                break;

            case MVPD_RING_PDS:
                mvpdKeyword = fapi2::MVPD_KEYWORD_PDS;
                break;

            default:
                mvpdKeyword = fapi2::MVPD_KEYWORD_UNDEFINED;
                break;
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
                                                   idxFeatureMap,
                                                   ringIdFeatureVecMap,
                                                   numberOfFeatures,
                                                   dynamicRingSection,
                                                   attrDdLevel,
                                                   ringProps,
                                                   io_bootCoreMask );

            FAPI_DBG("-----------------------------------------------------------------------");
            FAPI_DBG("bootCoreMask:  Requested=0x%08X  Final=0x%08X",
                     l_requestedBootCoreMask, io_bootCoreMask);
            FAPI_DBG("-----------------------------------------------------------------------");

            if (l_fapiRc)
            {

                if ((uint32_t)l_fapiRc == RC_XIPC_IMAGE_WOULD_OVERFLOW)
                {
                    FAPI_DBG("p10_ipl_customize(): SBE image is full. Ran out of space appending"
                             " VPD rings to the .rings section");

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
                         "CODE BUG: ringSectionBufSize(=%d) > maxRingSectionSize(=%d) in HB_SBE"
                         " (Occurrence 2)",
                         io_ringSectionBufSize, l_maxRingSectionSize );

            FAPI_ASSERT( (l_imageSizeWithoutRings + io_ringSectionBufSize) <= l_maxImageSize,
                         fapi2::XIPC_IMAGE_SIZING().
                         set_CHIP_TARGET(i_procTarget).
                         set_IMAGE_SIZE_WITHOUT_RINGS(l_imageSizeWithoutRings).
                         set_RING_SECTION_SIZE(io_ringSectionBufSize).
                         set_MAX_IMAGE_SIZE(l_maxImageSize),
                         "CODE BUG: SBE imageSize would exceed maxImageSize" );

            FAPI_DBG( "SBE image details: io_ringSectionBufSize=%d, l_imageSizeWithoutRings=%d,"
                      "  l_maxImageSize=%d",
                      io_ringSectionBufSize, l_imageSizeWithoutRings, l_maxImageSize );


            //--------------------------------------------------------
            // Append the updated .rings section to the Seeprom image
            //--------------------------------------------------------

            l_rc = p9_xip_append( io_image,
                                  P9_XIP_SECTION_SBE_RINGS,
                                  io_ringSectionBuf,
                                  io_ringSectionBufSize,
                                  l_maxImageSize,
                                  &l_sectionOffset,
                                  0 );

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_APPEND_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_SECTION_ID(P9_XIP_SECTION_SBE_RINGS).
                         set_MAX_IMAGE_SIZE(l_maxImageSize).
                         set_OCCURRENCE(2),
                         "ERROR(2): p9_xip_append() failed w/rc=0x%08x",
                         (uint32_t)l_rc );

            l_rc = p9_xip_image_size(io_image, &l_currentImageSize);

            FAPI_ASSERT( l_rc == 0,
                         fapi2::XIPC_XIP_API_MISC_ERROR().
                         set_CHIP_TARGET(i_procTarget).
                         set_XIP_RC(l_rc).
                         set_OCCURRENCE(4),
                         "p9_xip_image_size() failed (4) w/rc=0x%08X",
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
                                                   idxFeatureMap,
                                                   ringIdFeatureVecMap,
                                                   numberOfFeatures,
                                                   dynamicRingSection,
                                                   attrDdLevel,
                                                   ringProps,
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
                         "CODE BUG: QME ring section size(=%d) > maxRingSectionSize(=%d)"
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

    //
    // Produce the "anticipatory" dynamic inits debug list and, so far, append it only to
    // the Seeprom image. (Later, maybe PM team special delivery?)
    //
    ringIdFeatListSize = ringIdFeatureVecMap.size() * (sizeof(RingId_t) + sizeof(uint64_t));

    FAPI_DBG("ringIdFeatListSize =%u", ringIdFeatListSize);

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
    listPos = 0;

    for( std::map<RingId_t, uint64_t>::iterator it = ringIdFeatureVecMap.begin();
         it != ringIdFeatureVecMap.end();
         it++ )
    {
        FAPI_IMP("(ringId,featureVecAcc)=(0x%04x,0x%016llx)", it->first, it->second);

        *(RingId_t*)(ringIdFeatList + listPos) = htobe16(it->first);
        listPos += sizeof(it->first);

        *(uint64_t*)(ringIdFeatList + listPos) = htobe64(it->second);
        listPos += sizeof(it->second);
    }

    FAPI_ASSERT( listPos == ringIdFeatListSize,
                 fapi2::XIPC_CODE_BUG().
                 set_CHIP_TARGET(i_procTarget).
                 set_OCCURRENCE(5),
                 "CODE BUG(5): Accummulated feature list size(=%u) does not match"
                 " allocated list size(=%u)",
                 listPos, ringIdFeatListSize );


    // Append .ringidfeatlist section to the Seeprom image
    if (i_sysPhase ==  SYSPHASE_HB_SBE)
    {
        l_rc = p9_xip_append( io_image,
                              P9_XIP_SECTION_SBE_RINGIDFEATLIST,
                              (void*)ringIdFeatList,
                              ringIdFeatListSize,
                              l_maxImageSize,
                              &l_sectionOffset,
                              0 );

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_XIP_APPEND_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_RC(l_rc).
                     set_SECTION_ID(P9_XIP_SECTION_SBE_RINGIDFEATLIST).
                     set_MAX_IMAGE_SIZE(l_maxImageSize).
                     set_OCCURRENCE(3),
                     "ERROR(3): p9_xip_append() failed w/rc=0x%08x",
                     (uint32_t)l_rc );
    }

    delete ringIdFeatList;
    ringIdFeatList = NULL;      // added mcsgro 07152020



    ///////////////////////////////////////////////////////////////////////////
    // Done
    ///////////////////////////////////////////////////////////////////////////

    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        l_rc = p9_xip_image_size(io_image, &l_currentImageSize);

        FAPI_ASSERT( l_rc == 0,
                     fapi2::XIPC_XIP_API_MISC_ERROR().
                     set_CHIP_TARGET(i_procTarget).
                     set_XIP_RC(l_rc).
                     set_OCCURRENCE(5),
                     "p9_xip_image_size() failed (5) w/rc=0x%08X",
                     (uint32_t)l_rc );


        io_imageSize = l_currentImageSize;

        FAPI_DBG("Final customized SBE image size: %d", io_imageSize);
    }

    FAPI_DBG("Final customized .rings section size: %d", io_ringSectionBufSize);

fapi_try_exit:
    FAPI_IMP("Exiting p10_ipl_customize w/rc=0x%08x", (uint32_t)fapi2::current_err);
    return fapi2::current_err;

}
