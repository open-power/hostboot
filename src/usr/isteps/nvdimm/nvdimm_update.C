/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimm_update.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#include "nvdimm_update.H"
#include "nvdimm.H"
#include <isteps/nvdimm/nvdimm.H>
#include <isteps/nvdimm/nvdimmreasoncodes.H>
#include "bpm_update.H"

#include <initservice/istepdispatcherif.H> // sendProgressCode
#include <util/utilmclmgr.H> // secure LID manager
#include <errl/errlmanager.H>
#include <devicefw/userif.H>
#include <vpd/spdenums.H>
#include <sys/time.h>
#include <vector>

// Unique tracing for nvdimm update process
const char NVDIMM_UPD[] = "NVDIMM_UPD";
trace_desc_t* g_trac_nvdimm_upd = NULL;
TRAC_INIT(&g_trac_nvdimm_upd, NVDIMM_UPD, 2*KILOBYTE);


// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace NVDIMM
{
//////////////////////////////////////////////////////////////////////////////
// Helper Inline functions
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief Inline function to collect NVDIMM traces and
 *        make sure error is logged at least as PREDICTIVE
 */
inline void commitPredictiveNvdimmError(errlHndl_t & io_err)
{
    io_err->collectTrace(NVDIMM_UPD, 512);
    io_err->collectTrace(NVDIMM_COMP_NAME, 256);  // for helper function traces
    if ( io_err->sev() < ERRORLOG::ERRL_SEV_PREDICTIVE )
    {
        io_err->setSev( ERRORLOG::ERRL_SEV_PREDICTIVE );
    }
    ERRORLOG::errlCommit(io_err, NVDIMM_COMP_ID);
}

////////////////////////////////////////////////////////////////////////////////
// Helper structs/enums for code update
//
// Refer to JEDEC BAEBI spec for details
// https://www.jedec.org/standards-documents/docs/jesd245a
////////////////////////////////////////////////////////////////////////////////
// Definition of FIRMWARE_OPS_STATUS -- offset 0x71
typedef union {
    uint8_t whole;
    struct
    {
        // [7:6] : reserved
        uint8_t reserved : 2;
        // [5] : the abort of the last fw operation failed
        uint8_t fw_ops_abort_error : 1;
        // [4] : the last fw operation was aborted by the host
        uint8_t fw_ops_abort_success : 1;
        // [3] : the last block has been received successfully by the NVDIMM
        //       and the host may proceed with sending the next block
        uint8_t fw_ops_block_received : 1;
        // [2] : the module is in FW update mode where firmware on the module
        //       can be changed.
        //       If cleared, firmware on the module cannot be changed
        uint8_t fw_ops_update_mode : 1;
        // [1] : the last firmware operation failed
        uint8_t fw_ops_error : 1;
        // [0] : the last firmware operation completed without any errors
        uint8_t fw_ops_success : 1;
    } PACKED;
} fw_ops_status_t;

// Definition of FIRMWARE_OPS_CMD -- offset 0x4A
typedef union {
    uint8_t whole;
    struct
    {
        // [6-7] : Reserved for future use
        uint8_t reserved : 2;
        // [5] : Start a Validate Firmware Image operation
        uint8_t start_validate_fw_image_op : 1;
        // [4] : Start a Validate Firmware Header operation
        uint8_t start_validate_fw_header_op : 1;
        // [3] : Start a Commit Firmware operation
        uint8_t start_commit_fw_op : 1;
        // [2] : Start a Generate Firmware Checksum operation
        uint8_t start_generate_fw_checksum_op : 1;
        // [1] : Start a Clear Firmware operation
        uint8_t start_clear_fw_op : 1;
        // [0] : Enable / Disable firmware update mode.
        // 0b0: fw update mode is disabled.
        // 0b1: fw update mode is enabled.
        uint8_t firmware_update_mode : 1;
    } PACKED;
} fw_ops_cmd_t;

// Definition of NVDIMM_CMD_STATUS0 -- offset 0x61
typedef union {
    uint8_t whole;
    struct
    {
        // [7] : Firmware operations currently in progress
        uint8_t firmware_ops_in_progress : 1;
        // [6] : Arm operation in progress
        uint8_t arm_in_progress : 1;
        // [5] : Abort operation in progress
        uint8_t abort_in_progress : 1;
        // [4] : Erase operation in progress
        uint8_t erase_in_progress : 1;
        // [3] : Restore operation in progress
        uint8_t restore_in_progress : 1;
        // [2] : Catastrophic Save operation in progress
        uint8_t catastrophic_save_in_progress : 1;
        // [1] : Factory Default in progress
        uint8_t factory_default_in_progress : 1;
        // [0] : Operation in progress
        uint8_t operation_in_progress : 1;
    } PACKED;
} nvdimm_cmd_status0_t;

// A code update block is composed of this many bytes
constexpr uint8_t BYTES_PER_BLOCK = 32;

// Maximum allowed region write retries
constexpr uint8_t MAX_REGION_WRITE_RETRY_ATTEMPTS = 5;

///////////////////////////////////////////////////////////////////////////////
// NVDIMM LID Image
///////////////////////////////////////////////////////////////////////////////
NvdimmLidImage::NvdimmLidImage(const void * i_lidImageAddr, size_t i_size) :
    iv_lidImage(i_lidImageAddr), iv_lidImageSize(i_size)
{
}

uint32_t NvdimmLidImage::getType()
{
    uint32_t o_type = INVALID_TYPE;

    if (iv_lidImageSize >= sizeof(nvdimm_image_header_t))
    {
        const nvdimm_image_header_t * pLid =
            reinterpret_cast<const nvdimm_image_header_t*>(iv_lidImage);
        o_type = (uint32_t)pLid->module_mnfg_id_code << 16;
        o_type |= (uint32_t)pLid->module_product_id;
    }
    return o_type;
}

uint16_t NvdimmLidImage::getVersion()
{
    uint16_t o_version = INVALID_VERSION;

    if (iv_lidImageSize >= sizeof(nvdimm_image_header_t))
    {
        const nvdimm_image_header_t * pLid =
            reinterpret_cast<const nvdimm_image_header_t*>(iv_lidImage);
        o_version = pLid->controller_firmware_revision;
    }
    return o_version;
}


const uint8_t * NvdimmLidImage::getHeaderAndSmartSignature(uint16_t & o_size)
{
    o_size = 0;
    if (iv_lidImageSize > sizeof(nvdimm_image_header_t))
    {
        const nvdimm_image_header_t * pLid =
            reinterpret_cast<const nvdimm_image_header_t*>(iv_lidImage);
        o_size = le16toh(pLid->SMART_digital_signature_size);
        o_size += sizeof(nvdimm_image_header_t);
    }
    return reinterpret_cast<const uint8_t*>(iv_lidImage);
}


const void * NvdimmLidImage::getFlashImage()
{
    void * o_image_ptr = nullptr;
    if (iv_lidImageSize > sizeof(nvdimm_image_header_t))
    {
        const nvdimm_image_header_t * pLid =
            reinterpret_cast<const nvdimm_image_header_t*>(iv_lidImage);

        // make sure we don't point outside of lid memory
        // nvdimm flash image starts after the header and digital signature
        if ((sizeof(nvdimm_image_header_t) +
             le16toh(pLid->SMART_digital_signature_size)) < iv_lidImageSize)
        {
            TRACUCOMP(g_trac_nvdimm_upd,
                "NvdimmLidImage::getFlashImage() -> starts at offset 0x%X "
                "(digital signature size: %d, header size: %d)",
                sizeof(nvdimm_image_header_t) +
                le16toh(pLid->SMART_digital_signature_size),
                le16toh(pLid->SMART_digital_signature_size),
                sizeof(nvdimm_image_header_t));

            o_image_ptr = reinterpret_cast<void*>(const_cast<uint8_t *>(
                              reinterpret_cast<const uint8_t*>(iv_lidImage) +
                              sizeof(nvdimm_image_header_t) +
                              le16toh(pLid->SMART_digital_signature_size)));
        }
    }
    return o_image_ptr;
}


size_t NvdimmLidImage::getFlashImageSize()
{
    uint32_t o_flash_size = 0;
    if (iv_lidImageSize > sizeof(nvdimm_image_header_t))
    {
        const nvdimm_image_header_t * pLid =
            reinterpret_cast<const nvdimm_image_header_t*>(iv_lidImage);
        // Note: firmware_image_size does NOT include the Digital Signature
        //       (does include the 32-byte header though)
        o_flash_size = le32toh(pLid->firmware_image_size);
        o_flash_size -= sizeof(nvdimm_image_header_t);

        // safety check so we don't access past lid's memory size
        if ((o_flash_size + sizeof(nvdimm_image_header_t) +
             le16toh(pLid->SMART_digital_signature_size)) > iv_lidImageSize)
        {
            TRACFCOMP(g_trac_nvdimm_upd,
                ERR_MRK"getFlashImageSize(): %ld flash size + %ld header + "
                "%ld digital signature is greater than %ld overall lid size",
                o_flash_size, sizeof(nvdimm_image_header_t),
                le16toh(pLid->SMART_digital_signature_size),
                iv_lidImageSize);
            // flash image size is outside of lid memory bounds so don't return
            // a valid flash size
            o_flash_size = 0;
        }
    }
    return o_flash_size;
}

///////////////////////////////////////////////////////////////////////////////
// NVDIMM Installed Image
///////////////////////////////////////////////////////////////////////////////
NvdimmInstalledImage::NvdimmInstalledImage(TARGETING::Target * i_nvDimm) :
    iv_dimm(i_nvDimm), iv_version(INVALID_VERSION),
    iv_manufacturer_id(INVALID_ID), iv_product_id(INVALID_ID),
    iv_timeout(INVALID_TIMEOUT),
    iv_max_blocks_per_region(INVALID_REGION_BLOCK_SIZE),
    iv_fw_update_mode_enabled(false),
    iv_region_write_retries(0),
    iv_blockSizeSupported(INVALID_BLOCK_SIZE)
{
    // initialize to invalid values
}

errlHndl_t NvdimmInstalledImage::getType(uint32_t & o_type)
{
    errlHndl_t l_err = nullptr;
    do {
      size_t l_id_size = 0; // size of id
      if ( iv_manufacturer_id == INVALID_ID)
      {
          // grab values for the installed NVDIMM via SPD
          l_id_size = sizeof(iv_manufacturer_id);
          l_err = deviceRead(iv_dimm, &iv_manufacturer_id, l_id_size,
                           DEVICE_SPD_ADDRESS(SPD::RAW_MODULE_MANUFACTURER_ID));
          if (l_err)
          {
              TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"NvdimmInstalledImage::getType()"
                  " nvdimm[%X] failed to read manufacturer ID",
                  TARGETING::get_huid(iv_dimm));
              iv_manufacturer_id = INVALID_ID;
              break;
          }
      }

      if (iv_product_id == INVALID_ID)
      {
          // grab values for the installed NVDIMM via SPD
          l_id_size = sizeof(iv_product_id);
          l_err = deviceRead(iv_dimm, &iv_product_id, l_id_size,
                            DEVICE_SPD_ADDRESS(SPD::RAW_MODULE_PRODUCT_ID));
          if (l_err)
          {
              TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"NvdimmInstalledImage::getType()"
                  " nvdimm[%X] failed to read product ID",
                  TARGETING::get_huid(iv_dimm));
              iv_product_id = INVALID_ID;
              break;
          }
      }
    } while (0);

    // return the concatenated Type (this may include INVALID_IDs)
    o_type = ((uint32_t)iv_manufacturer_id << 16) | (uint32_t)iv_product_id;
    return l_err;
}

errlHndl_t NvdimmInstalledImage::getVersion(uint16_t & o_version,
                                            const bool i_force_recollect)
{
    errlHndl_t l_err = nullptr;

    do {
      if ((iv_version == INVALID_VERSION) || i_force_recollect)
      {
          // Return version in little-endian format
          uint8_t l_rev1 = 0xFF;
          uint8_t l_rev0 = 0xFF;

          l_err = nvdimmReadReg(iv_dimm, SLOT1_FWREV0, l_rev0 );
          if (l_err)
          {
              TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"NvdimmInstalledImage::"
                  "getVersion() nvdimm[%X] failed to read SLOT1_FWREV0",
                  TARGETING::get_huid(iv_dimm));
              iv_version = INVALID_VERSION;
              break;
          }
          iv_version = (uint16_t)l_rev0 << 8;
          l_err = nvdimmReadReg(iv_dimm, SLOT1_FWREV1, l_rev1 );
          if (l_err)
          {
              TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"NvdimmInstalledImage::"
                  "getVersion() nvdimm[%X] failed to read SLOT1_FWREV1",
                  TARGETING::get_huid(iv_dimm));
              iv_version = INVALID_VERSION;
              break;
          }
          iv_version |= (uint16_t)l_rev1;
      }
    } while (0);
    o_version = iv_version;
    return l_err;
}

errlHndl_t NvdimmInstalledImage::getBlockWriteSizeSupported(uint64_t & o_blockSize)
{
    errlHndl_t l_err = nullptr;

    do {
        if (iv_blockSizeSupported == INVALID_BLOCK_SIZE)
        {
            uint16_t version = INVALID_VERSION;
            l_err = getVersion(version, 0);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"getBlockWriteSizeSupported: "
                    "Failed to get version for 0x%.8X NVDIMM",
                    TARGETING::get_huid(iv_dimm));
                break;
            }

            // The block write is more prone to random system interrupt
            // which does something funny to the i2c bus.
            // v3.A has the timeout increased to mitigate that
            if (version >= 0x3A00)
            {
                // version supports 32-byte block size
                iv_blockSizeSupported = 32;
            }
            else
            {
                // default to word size max write
                iv_blockSizeSupported = sizeof(uint16_t);
            }
            TRACFCOMP( g_trac_nvdimm_upd, "getBlockWriteSizeSupported: "
                "block size %d supported for 0x%.8X NVDIMM (version 0x%04X)",
                iv_blockSizeSupported, TARGETING::get_huid(iv_dimm),
                version );

            // Get the sys target to check for attribute overrides
            TARGETING::Target* sys = nullptr;
            TARGETING::targetService().getTopLevelTarget(sys);
            auto l_blockSize = sys->getAttr<TARGETING::ATTR_NVDIMM_UPDATE_I2C_BLOCK_SIZE>();
            if (l_blockSize)
            {
                // only support 32 byte and word size
                if ((l_blockSize == 32) || (l_blockSize == sizeof(uint16_t)))
                {
                    TRACFCOMP( g_trac_nvdimm_upd, "getBlockWriteSizeSupported: "
                      "ATTR_NVDIMM_UPDATE_I2C_BLOCK_SIZE override block size: %d", l_blockSize );
                    iv_blockSizeSupported = l_blockSize;
                }
                else
                {
                    TRACFCOMP( g_trac_nvdimm_upd, "getBlockWriteSizeSupported: "
                      "ATTR_NVDIMM_UPDATE_I2C_BLOCK_SIZE has invalid size (%d)",
                      l_blockSize );
                }
            }
        }
    } while (0);
    o_blockSize = iv_blockSizeSupported;
    return l_err;
}

errlHndl_t NvdimmInstalledImage::updateImage(NvdimmLidImage * i_lidImage)
{
    errlHndl_t l_err = nullptr;

    do {
        INITSERVICE::sendProgressCode();
        ////////////////////////////////////////////////////////////////////////
        // Start of firmware update logic, section 9.7 in JESD245B
        ////////////////////////////////////////////////////////////////////////
        // 1. Validate module manufacturer ID and module product identifier
        //    Done before this was called, it is what selected i_lidImage

        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 2");
        // 2. Verify 'Operation In Progress' bit in the NVDIMM_CMD_STATUS0
        //    register is cleared (ie. NV controller is NOT busy)
        nvdimm_cmd_status0_t l_status;
        l_err = nvdimmReadReg(iv_dimm, NVDIMM_CMD_STATUS0, l_status.whole);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "Read of NVDIMM_CMD_STATUS0 register on 0x%.8X NVDIMM failed",
                TARGETING::get_huid(iv_dimm), l_status.whole);
            break;
        }
        if (l_status.operation_in_progress)
        {
            TRACFCOMP(g_trac_nvdimm_upd,ERR_MRK"updateImage: "
                "NV controller is busy (0x%08X) for NVDIMM 0x%.8X",
                l_status.whole, TARGETING::get_huid(iv_dimm));
            /*@
             *@errortype
             *@moduleid         UPDATE_IMAGE
             *@reasoncode       NVDIMM_OPERATION_IN_PROGRESS
             *@userdata1        NVDIMM Target Huid
             *@userdata2        NVDIMM_CMD_STATUS0
             *@devdesc          NV controller is busy so no update can run
             *@custdesc         NVDIMM not updated
             */
            l_err = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_PREDICTIVE,
                                   UPDATE_IMAGE,
                                   NVDIMM_OPERATION_IN_PROGRESS,
                                   TARGETING::get_huid(iv_dimm),
                                   l_status.whole,
                                   ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace( NVDIMM_COMP_NAME, 256 );
            nvdimmAddVendorLog(iv_dimm, l_err);
            l_err->addPartCallout( iv_dimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH );
            l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW );
            nvdimmAddPage4Regs(iv_dimm,l_err);
            nvdimmAddUpdateRegs(iv_dimm,l_err);
            break;
        }

        // 3. Make sure we start from a cleared state
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 3");
        l_err = clearFwOpsStatus();
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "Unable to clear firmware ops status for NVDIMM %.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // 4. Enable firmware update mode
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 4");
        l_err = changeFwUpdateMode(FW_UPDATE_MODE_ENABLED);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "Unable to enable firmware update mode for NVDIMM %.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // 5. Clear the Firmware Operation status
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 5");
        l_err = clearFwOpsStatus();
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "Unable to clear firmware ops status for NVDIMM %.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // 6. Clear the firmware data block to ensure there is no residual data.
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 6");
        l_err = clearFwDataBlock();
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "Step 6. clearFwDataBlock() failed for NVDIMM %.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // 7. Send the first part (header + SMART signature) of
        //    the Firmware Image Data

        // 7a. Write the TYPED_BLOCK_DATA register with 0x1 (Firmware Image Data)
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 7a");
        l_err = nvdimmWriteReg(iv_dimm, TYPED_BLOCK_DATA, 0x01);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "Write of 0x01 to TYPED_BLOCK_DATA failed for NVDIMM %.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // 7b. Write the BLOCK_ID, REGION_ID0 and REGION_ID1 registers with value 0.
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 7b");
        l_err = nvdimmWriteReg(iv_dimm, BLOCK_ID, 0x00);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "Write of 0x00 to BLOCK_ID failed for NVDIMM %.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }
        l_err = nvdimmWriteReg(iv_dimm, REGION_ID0, 0x00);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "Write of 0x00 to REGION_ID0 failed for NVDIMM %.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }
        l_err = nvdimmWriteReg(iv_dimm, REGION_ID1, 0x00);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "Write of 0x00 to REGION_ID1 failed for NVDIMM %.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // 7c. Send the header (first 32 bytes of the image) +
        //     SMART digital signature to multiple blocks of
        //     TYPED_BLOCK_DATA_BYTE0 - TYPED_BLOCK_DATA_BYTE31.
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 7c");
        uint16_t header_plus_signature_size = 0;
        const uint8_t * pHeaderAndDigitalSignature =
            i_lidImage->getHeaderAndSmartSignature(header_plus_signature_size);
        l_err = byteRegionBlockTransfer( pHeaderAndDigitalSignature,
                                         header_plus_signature_size, false );
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: Unable to send "
                "header and digital signature update for NVDIMM %.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // 7d. Validate the transfer by checksum

        // 7d.i. Host calculate checksum using the crc16 algo in JESD245B
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 7d.i.");
        uint16_t hostCksm = crc16(pHeaderAndDigitalSignature,
                                  header_plus_signature_size);

        // 7d.ii. Set bit 1 (Clear the FIRMWARE_OPS_STATUS register) in
        //        the NVDIMM_MGT_CMD1 register.
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 7d.ii.");
        l_err = clearFwOpsStatus();
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "Unable to clear Firmware Operations Status for NVDIMM %.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // 7d.iii - 7d.vii
        // Write the FIRMWARE_OPS_CMD register with value 0x04
        // to start a Generate Firmware Checksum operation.
        // Compare the module generated value with the host value.
        // Abort the workflow if they do not match.
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 7d.iii.");
        uint16_t nvCksm;
        l_err = calcAndGetCksm(nvCksm);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "updateImage: calcAndGetCksm() "
                "failed for 0x%.8X nvdimm", TARGETING::get_huid(iv_dimm));
            break;
        }
        if (hostCksm != nvCksm)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImage: "
                "NVDIMM 0x%.8X: data checksums mismatch (calc host: 0x%X "
                "and nv: 0x%X) for first part (header + SMART signature)",
                TARGETING::get_huid(iv_dimm), hostCksm, nvCksm);
            /*@
             *@errortype
             *@moduleid         UPDATE_IMAGE
             *@reasoncode       NVDIMM_CHECKSUM_ERROR
             *@userdata1        NVDIMM Target Huid
             *@userdata2[0:15]  Host checksum calculated
             *@userdata2[16:31] NV checksum returned
             *@userdata2[32:47] size of data for checksum
             *@devdesc          Checksum failure when transferring region
             *@custdesc         NVDIMM not updated
             */
            l_err = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_PREDICTIVE,
                                   UPDATE_IMAGE_DATA,
                                   NVDIMM_CHECKSUM_ERROR,
                                   TARGETING::get_huid(iv_dimm),
                                   FOUR_UINT16_TO_UINT64(
                                      hostCksm, nvCksm,
                                      header_plus_signature_size,
                                      0x0000),
                                   ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace( NVDIMM_COMP_NAME, 256 );

            // Do not add vendor log as it messes with fw update mode
            //nvdimmAddVendorLog(iv_dimm, l_err);

            // maybe some data was altered on the NV controller
            l_err->addPartCallout( iv_dimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH );
            // possible code issue
            l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW );
            nvdimmAddPage4Regs(iv_dimm,l_err);
            nvdimmAddUpdateRegs(iv_dimm,l_err);
            break;
        }

        // 8. Command the module to validate that the firmware image is valid
        //    for the module based on the header.
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 8");
        l_err = validateFwHeader();
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "updateImage: firmware header "
                "for 0x%.8X nvdimm cannot be validated",
                TARGETING::get_huid(iv_dimm));
            break;
        }
        else
        {
            TRACFCOMP(g_trac_nvdimm_upd, "updateImage: NVDIMM 0x%.8X "
                "updated with valid header + SMART signature",
                TARGETING::get_huid(iv_dimm));
        }

        // 9. Commit the first firmware data region
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 9");
        l_err = commitFwRegion();
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "updateImage: commitFwRegion() "
                "of first data region failed for 0x%.8X nvdimm",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // 10. Send and commit the remaining firmware data in
        //     REGION_BLOCK_SIZE regions
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 10");
        l_err = updateImageData(i_lidImage);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "updateImage:  "
                "updateImageData() failed sending full image for 0x%.8X nvdimm",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // 11. Validate the firmware data
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 11");
        l_err = validateFwImage();
        if ( l_err )
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "updateImage:  "
                "validateFwImage() failed for 0x%.8X nvdimm",
                TARGETING::get_huid(iv_dimm));
            break;
        }
        else
        {
            TRACFCOMP(g_trac_nvdimm_upd, "updateImage: NVDIMM 0x%.8X "
                "updated with valid image data", TARGETING::get_huid(iv_dimm));
        }

        // 12. Disable firmware update mode
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 12");
        l_err = changeFwUpdateMode(FW_UPDATE_MODE_DISABLED);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "updateImage:  "
                "Unable to disable FW update mode for 0x%.8X nvdimm",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // There are two slots for firmware.
        // Slot 0 is read-only hence this procedure only updates slot 1.
        // At the end of the update, we should explicitly select slot 1,
        // by writing 0x1 to FW_SLOT_INFO, to make sure the module is
        // running on the latest code.
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: Switch to slot 1");
        l_err = nvdimmWriteReg(iv_dimm, FW_SLOT_INFO, 0x01);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "updateImage:  "
                "Unable to switch to slot 1 for 0x%.8X nvdimm",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // Reset controller to activate new firmware
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: resetController");
        l_err = nvdimmResetController(iv_dimm);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "updateImage:  "
                "Unable to activate new firmware for 0x%.8X nvdimm",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // force a recollect of the version of code installed
        TRACUCOMP(g_trac_nvdimm_upd, "updateImage: verify new code version running");
        uint16_t new_version = INVALID_VERSION;
        l_err = getVersion(new_version, true);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "updateImage: "
                "Unable to verify NVDIMM 0x%.8X was successfully updated",
                TARGETING::get_huid(iv_dimm));
            break;
        }
        else
        {
            TRACFCOMP(g_trac_nvdimm_upd, "updateImage: NVDIMM 0x%.8X of type "
                "0x%04X%04X now running new code level 0x%04X",
                TARGETING::get_huid(iv_dimm),
                le16toh(iv_manufacturer_id), le16toh(iv_product_id),
                le16toh(new_version));

        }

    } while (0);

    // If update operation is aborted, we need to disable update mode
    if (iv_fw_update_mode_enabled)
    {
        TRACFCOMP(g_trac_nvdimm_upd, "updateImage: update was aborted, so disable FW_UPDATE_MODE");
        errlHndl_t l_err2 = changeFwUpdateMode(FW_UPDATE_MODE_DISABLED);
        if (l_err2)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "updateImage: "
                "Attempt to disable Firmware Update Mode of 0x%.8X failed,"
                " RC=0x%X", TARGETING::get_huid(iv_dimm),
                ERRL_GETRC_SAFE(l_err2));

            // Should always have an error here, so link the two errors together
            // Just a safety-check so we don't dereference a nullptr
            if (l_err)
            {
                l_err2->plid(l_err->plid());
                l_err2->collectTrace(NVDIMM_COMP_NAME, 256);
                l_err2->collectTrace(NVDIMM_UPD, 256);
                errlCommit(l_err2, NVDIMM_COMP_ID);
            }
            else
            {
                // this path shouldn't get run
                l_err = l_err2;
            }
        }
    }

    return l_err;
}


// HELPER FUNCTIONS FOR UPDATE
errlHndl_t NvdimmInstalledImage::updateImageData(NvdimmLidImage * i_lidImage)
{
    errlHndl_t l_err = nullptr;
    do
    {
        uint8_t blocks_per_region;
        l_err = getBlocksPerRegion(blocks_per_region);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                "getBlocksPerRegion() failed on NVDIMM 0x%.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // calculate the region size which equals block size * blocks per region
        uint16_t region_size = BYTES_PER_BLOCK * blocks_per_region;
        const uint8_t * fw_img_data =
            reinterpret_cast<const uint8_t*>(i_lidImage->getFlashImage());
        size_t fw_img_data_len = i_lidImage->getFlashImageSize();

        // Get the number of regions required for the amount of data.
        // This sets the upper bound for the REGION_ID
        uint16_t fw_img_total_regions = fw_img_data_len/region_size;
        if (fw_img_data_len % region_size > 0)
        {
            // account for a partial region
            fw_img_total_regions++;
        }
        if (fw_img_total_regions == 0)
        {
            /*@
             *@errortype
             *@moduleid         UPDATE_IMAGE_DATA
             *@reasoncode       NVDIMM_ZERO_TOTAL_REGIONS
             *@userdata1        NVDIMM Target Huid
             *@userdata2[0:15]  Firmware image size
             *@userdata2[16:31] region_size
             *@devdesc          Firmware image size is not large enough
             *                  (needs to be at least region_size)
             *@custdesc         NVDIMM not updated
             */
            l_err = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_PREDICTIVE,
                                   UPDATE_IMAGE_DATA,
                                   NVDIMM_ZERO_TOTAL_REGIONS,
                                   TARGETING::get_huid(iv_dimm),
                                   TWO_UINT16_ONE_UINT32_TO_UINT64(
                                      fw_img_data_len,
                                      region_size,
                                      0x00000000),
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            l_err->collectTrace( NVDIMM_COMP_NAME, 256 );
            nvdimmAddPage4Regs(iv_dimm,l_err);
            nvdimmAddUpdateRegs(iv_dimm,l_err);
            break;
        }

        // 10.a Write the BLOCK_ID, REGION_ID0 and REGION_ID1 registers
        //      with the appropriate value starting at 0
        TRACUCOMP(g_trac_nvdimm_upd,
            "updateImage: Sending %d total regions of size %d bytes (total size: 0x%08X)",
            fw_img_total_regions, region_size, fw_img_data_len);
        l_err = nvdimmWriteReg(iv_dimm, REGION_ID0, 0x00);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                "Write of 0x00 to REGION_ID0 failed on NVDIMM 0x%.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }
        l_err = nvdimmWriteReg(iv_dimm, REGION_ID1, 0x00);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                "Write of 0x00 to REGION_ID1 failed on NVDIMM 0x%.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        uint8_t l_region_write_retries = 0; // local region write retry count
        uint16_t region = 0;
        while (region < fw_img_total_regions)
        {
            if ( l_err )
            {
                if ( l_region_write_retries++ < MAX_REGION_WRITE_RETRY_ATTEMPTS )
                {
                    TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                      "Region %d on NVDIMM 0x%.8X failed, retry %d",
                      region, TARGETING::get_huid(iv_dimm),l_region_write_retries);
                    l_err->collectTrace(NVDIMM_UPD, 512);

                    // Change PREDICTIVE to INFORMATIONAL as this might be recoverable
                    l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);

                    // Commit this log and retry region write
                    ERRORLOG::errlCommit(l_err, NVDIMM_COMP_ID);
                    l_err = nullptr;
                    iv_region_write_retries++;
                }
                else
                {
                    break;
                }
            }

            if (region % 100 == 0)
            {
                TRACFCOMP(g_trac_nvdimm_upd,
                    "updateImage: progress code for sending region %d",
                    region);
                INITSERVICE::sendProgressCode();
            }
            TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 10.a - region 0x%04X",
                region);
            // For each region, start with BLOCK_ID of 0. BLOCK_ID
            // is controlled in byteRegionBlockTransfer().
            l_err = nvdimmWriteReg(iv_dimm, BLOCK_ID, 0x00);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                    "Write of 0x00 to BLOCK_ID failed on NVDIMM 0x%.8X",
                    TARGETING::get_huid(iv_dimm));
                continue;
            }

            // Update REGION_ID0(lsb) and REGION_ID1(msb)
            uint8_t l_data = region & 0x00FF;
            l_err = nvdimmWriteReg(iv_dimm, REGION_ID0, l_data);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                    "Write of 0x%02X to REGION_ID0 failed on NVDIMM 0x%.8X",
                    l_data, TARGETING::get_huid(iv_dimm));
                continue;
            }
            l_data = (((region & 0xFF00) >> 8) & 0x00FF);
            l_err = nvdimmWriteReg(iv_dimm, REGION_ID1, l_data);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                    "Region %d write of 0x%02X to REGION_ID1 failed on NVDIMM "
                    "0x%.8X", region, l_data, TARGETING::get_huid(iv_dimm));
                continue;
            }

            // 10.b Clear the firmware data block to ensure there is no
            //      residual data.
            TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 10.b");
            l_err = clearFwDataBlock();
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                    "Region %d: clearFwDataBlock() failed on NVDIMM 0x%.8X",
                    region, TARGETING::get_huid(iv_dimm));
                continue;
            }

            // 10.c Send the data over to nvdimm region by region.
            // Check if the remaining data is in the multiple of the region size
            // If not, have the function to calculate the actual amount of data
            // to send over to the nvdimm
            const uint8_t * pImageData = &(fw_img_data[(region*region_size)]);
            uint16_t data_len = region_size;
            if ((fw_img_data_len-(region*region_size)) < region_size)
            {
                // send a final partial region
                data_len = fw_img_data_len-(region*region_size);
                TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 10.c - send partial region (%d length)", data_len);
                l_err = byteRegionBlockTransfer(pImageData, data_len, false);
            }
            else
            {
                // send a full region worth of data
                TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 10.c - send full region (%d length)", data_len);
                l_err = byteRegionBlockTransfer(pImageData, data_len, true);
            }
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                    "Region %d: byteRegionBlockTransfer() failed on NVDIMM 0x%.8X",
                    region, TARGETING::get_huid(iv_dimm));
                continue;
            }

            // 10.d-e After transferring each region, validate the transfer by checksum
            TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 10.d-e");
            uint16_t hostCksm = crc16(pImageData, data_len);
            l_err = clearFwOpsStatus();
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                    "Region %d: clearFwOpsStatus() failed on NVDIMM 0x%.8X",
                    region, TARGETING::get_huid(iv_dimm));
                continue;
            }
            uint16_t nvCksm;
            l_err = calcAndGetCksm(nvCksm);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                    "Region %d: calcAndGetCksm() failed on NVDIMM 0x%.8X",
                    region, TARGETING::get_huid(iv_dimm));
                continue;
            }
            if (hostCksm != nvCksm)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                    "Region %d out of %d on NVDIMM 0x%.8X: data checksums mismatch "
                    "(calc host: 0x%X and nv: 0x%X)",
                    region, fw_img_total_regions,
                    TARGETING::get_huid(iv_dimm), hostCksm, nvCksm);

                /*@
                 *@errortype
                 *@moduleid         UPDATE_IMAGE_DATA
                 *@reasoncode       NVDIMM_CHECKSUM_ERROR
                 *@userdata1[0:31]  NVDIMM Target Huid
                 *@userdata1[32:63] Retry count for this region
                 *@userdata2[0:15]  Host checksum calculated
                 *@userdata2[16:31] NV checksum returned
                 *@userdata2[32:47] size of data for checksum
                 *@userdata2[48:63] region
                 *@devdesc          Checksum failure when transferring region
                 *@custdesc         NVDIMM not updated
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                       ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       UPDATE_IMAGE_DATA,
                                       NVDIMM_CHECKSUM_ERROR,
                                       TWO_UINT32_TO_UINT64(
                                          TARGETING::get_huid(iv_dimm),
                                          l_region_write_retries),
                                       FOUR_UINT16_TO_UINT64(
                                          hostCksm, nvCksm,
                                          region, data_len),
                                       ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
                // Do not add vendor log as it messes with fw update mode
                // and will prevent retries from working
                l_err->addPartCallout( iv_dimm,
                                       HWAS::NV_CONTROLLER_PART_TYPE,
                                       HWAS::SRCI_PRIORITY_HIGH );
                l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                            HWAS::SRCI_PRIORITY_LOW );
                nvdimmAddPage4Regs(iv_dimm,l_err);
                nvdimmAddUpdateRegs(iv_dimm,l_err);

                continue;
            }

            // 10.f Commit the firmware data region transferred
            TRACUCOMP(g_trac_nvdimm_upd, "updateImage: step 10.f");
            l_err = commitFwRegion();
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"updateImageData: "
                    "Region %d: commitFwRegion() failed on NVDIMM 0x%.8X",
                    region, TARGETING::get_huid(iv_dimm));
                continue;
            }
            region++;
        } // End of FW image data transfer
    } while (0);

    return l_err;
}

errlHndl_t NvdimmInstalledImage::changeFwUpdateMode(fw_update_mode i_mode)
{
    errlHndl_t l_err = nullptr;

    l_err = nvdimmWriteReg(iv_dimm, FIRMWARE_OPS_CMD, i_mode);
    if (!l_err)
    {
        // Wait for ops to complete
        l_err = waitFwOpsComplete();
        if (!l_err)
        {
            // if ops completed successfully, check the status
            // to make sure that FW update mode has been enabled/disabled
            fw_ops_status_t opStatus;
            l_err = nvdimmReadReg(iv_dimm, FIRMWARE_OPS_STATUS, opStatus.whole);
            if (!l_err)
            {
                // Create an error if the mode was NOT set correctly
                if (!(((i_mode == FW_UPDATE_MODE_ENABLED) &&
                       (opStatus.fw_ops_update_mode == 1)) ||
                      ((i_mode == FW_UPDATE_MODE_DISABLED) &&
                       (opStatus.fw_ops_update_mode == 0))) )
                {
                    /*@
                     *@errortype
                     *@moduleid         CHANGE_FW_UPDATE_MODE
                     *@reasoncode       NVDIMM_UPDATE_MODE_UNCHANGED
                     *@userdata1        NVDIMM Target Huid
                     *@userdata2[0:7]   Mode setting
                     *@userdata2[8:15]  FIRMWARE_OPS_STATUS byte
                     *@devdesc          Firmware Update Mode not updated
                     *@custdesc         NVDIMM not updated
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           CHANGE_FW_UPDATE_MODE,
                                           NVDIMM_UPDATE_MODE_UNCHANGED,
                                           TARGETING::get_huid(iv_dimm),
                                           FOUR_UINT8_TO_UINT32(
                                              i_mode, opStatus.whole,
                                              0x00, 0x00),
                                           ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
                    l_err->collectTrace( NVDIMM_COMP_NAME, 256 );
                    nvdimmAddVendorLog(iv_dimm, l_err);
                    l_err->addPartCallout( iv_dimm,
                                           HWAS::NV_CONTROLLER_PART_TYPE,
                                           HWAS::SRCI_PRIORITY_HIGH );
                    l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                                HWAS::SRCI_PRIORITY_LOW );
                    nvdimmAddPage4Regs(iv_dimm,l_err);
                    nvdimmAddUpdateRegs(iv_dimm,l_err);
                }
                else
                {
                    if (opStatus.fw_ops_update_mode == 1)
                    {
                        iv_fw_update_mode_enabled = true;
                    }
                    else
                    {
                        iv_fw_update_mode_enabled = false;
                    }
                }
            }
        }
    }
    return l_err;
}

errlHndl_t NvdimmInstalledImage::waitFwOpsBlockReceived()
{
    errlHndl_t l_err = nullptr;

    // retry for a total of 500ms
    const uint32_t MAX_WAIT_FOR_OPS_BLOCK_RECEIVED = 500;
    uint32_t timeout_ms_val = MAX_WAIT_FOR_OPS_BLOCK_RECEIVED;

    bool blockReceived = false;
    fw_ops_status_t opStatus;
    while (1)
    {
        l_err = nvdimmReadReg(iv_dimm, FIRMWARE_OPS_STATUS,
                              opStatus.whole);
        if (l_err)
        {
            TRACFCOMP( g_trac_nvdimm_upd, ERR_MRK"waitFwOpsBlockReceived: "
                "FIRMWARE_OPS_STATUS read failed on NVDIMM 0x%.8X "
                "(timeout: %d ms out of %d ms)",
                TARGETING::get_huid(iv_dimm),
                timeout_ms_val, MAX_WAIT_FOR_OPS_BLOCK_RECEIVED );
            break;
        }

        if (!opStatus.fw_ops_block_received)
        {
            // wait 1 millisecond between checking status
            if (timeout_ms_val > 0)
            {
                timeout_ms_val -= 1;
                nanosleep(0, NS_PER_MSEC);
            }
            else
            {
                // timeout hit
                break;
            }
        }
        else
        {
            // block received
            blockReceived = true;
            break;
        }
    }

    if (!blockReceived && !l_err)
    {
        TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"waitFwOpsBlockReceived: "
            "NVDIMM 0x%.8X FIRMWARE_OPS_STATUS (timeout: %d ms) "
            "-- Last status: 0x%02X",
            TARGETING::get_huid(iv_dimm), MAX_WAIT_FOR_OPS_BLOCK_RECEIVED,
            opStatus.whole);

        /*@
         *@errortype
         *@moduleid         WAIT_FW_OPS_BLOCK_RECEIVED
         *@reasoncode       NVDIMM_BLOCK_NOT_RECEIVED
         *@userdata1        NVDIMM Target Huid
         *@userdata2[0:15]  Last FIRMWARE_OPS_STATUS read
         *@userdata2[16:31] Timeout (msecs)
         *@devdesc          Firmware Operation timed out waiting for
         *                  data block transfer confirmation
         *@custdesc         NVDIMM not updated
         */
        l_err = new ERRORLOG::ErrlEntry(
                               ERRORLOG::ERRL_SEV_PREDICTIVE,
                               WAIT_FW_OPS_BLOCK_RECEIVED,
                               NVDIMM_BLOCK_NOT_RECEIVED,
                               TARGETING::get_huid(iv_dimm),
                               TWO_UINT16_ONE_UINT32_TO_UINT64
                               (
                                  TWO_UINT8_TO_UINT16( 0x00,
                                                  opStatus.whole),
                                  MAX_WAIT_FOR_OPS_BLOCK_RECEIVED,
                                  timeout_ms_val
                               ),
                               ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
        l_err->collectTrace(NVDIMM_COMP_NAME, 512 );
        nvdimmAddVendorLog(iv_dimm, l_err);
        l_err->addPartCallout( iv_dimm,
                               HWAS::NV_CONTROLLER_PART_TYPE,
                               HWAS::SRCI_PRIORITY_HIGH );
        l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_LOW );
        nvdimmAddPage4Regs(iv_dimm,l_err);
        nvdimmAddUpdateRegs(iv_dimm,l_err);
    }

    return l_err;
}


errlHndl_t NvdimmInstalledImage::waitFwOpsComplete()
{
    errlHndl_t l_err = nullptr;

    uint16_t timeout_val = INVALID_TIMEOUT;
    l_err = getFwOpsTimeout(timeout_val);
    uint32_t timeout_ms_val = timeout_val * 1000;
    if (!l_err)
    {
        TRACUCOMP(g_trac_nvdimm_upd, "waitFwOpsComplete: timeout_val %d seconds", timeout_val);
        bool opsComplete = false;
        nvdimm_cmd_status0_t cmdStatus;
        while (1)
        {
            l_err = nvdimmReadReg(iv_dimm, NVDIMM_CMD_STATUS0, cmdStatus.whole);
            if (l_err)
            {
                break;
            }
            if (cmdStatus.firmware_ops_in_progress)
            {
                // wait 1 millisecond between checking status
                if (timeout_ms_val > 0)
                {
                    timeout_ms_val -= 1;
                    nanosleep(0, NS_PER_MSEC);
                }
                else
                {
                    // timeout hit
                    break;
                }
            }
            else
            {
                // ops completed
                opsComplete = true;
                break;
            }
        }

        if (!opsComplete && !l_err)
        {
            /*@
             *@errortype
             *@moduleid         WAIT_FW_OPS_COMPLETE
             *@reasoncode       NVDIMM_FW_OPS_IN_PROGRESS_TIMEOUT
             *@userdata1        NVDIMM Target Huid
             *@userdata2[0:15]  Last NVDIMM_CMD_STATUS0 read
             *@userdata2[16:31] Timeout (seconds)
             *@devdesc          Firmware Operation timed out
             *@custdesc         NVDIMM not updated
             */
            l_err = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_PREDICTIVE,
                                   WAIT_FW_OPS_COMPLETE,
                                   NVDIMM_FW_OPS_IN_PROGRESS_TIMEOUT,
                                   TARGETING::get_huid(iv_dimm),
                                   TWO_UINT16_ONE_UINT32_TO_UINT64
                                   (
                                      TWO_UINT8_TO_UINT16( 0x00,
                                                      cmdStatus.whole),
                                      iv_timeout,
                                      timeout_ms_val
                                   ),
                                   ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME, 256 );
            nvdimmAddVendorLog(iv_dimm, l_err);
            l_err->addPartCallout( iv_dimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH );
            l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW );
            nvdimmAddPage4Regs(iv_dimm,l_err);
            nvdimmAddUpdateRegs(iv_dimm,l_err);
        }
    }
    return l_err;
}

errlHndl_t NvdimmInstalledImage::getFwOpsTimeout(uint16_t & o_timeout)
{
    errlHndl_t l_err = nullptr;

    do {
        // Grab the timeout value once and reuse
        if (iv_timeout == INVALID_TIMEOUT)
        {
            uint8_t lsb;
            uint8_t msb;
            l_err = nvdimmReadReg(iv_dimm, FIRMWARE_OPS_TIMEOUT0, lsb);
            if (l_err)
            {
                break;
            }
            l_err = nvdimmReadReg(iv_dimm, FIRMWARE_OPS_TIMEOUT1, msb);
            if (l_err)
            {
                break;
            }

            // Look for whether this is in milliseconds or seconds
            if (msb < 0x80)
            {
                // convert time value for milliseconds to seconds
                iv_timeout = ((msb << 8) | lsb)/1000;
            }
            else
            {
                // timeout value is in seconds (remove the indicator bit)
                iv_timeout = (((msb - 0x80) << 8) | lsb);
            }
            TRACUCOMP(g_trac_nvdimm_upd,"getFwOpsTimeout: msb:0x%02X lsb:0x%02X -> 0x%04X",
                msb, lsb, iv_timeout);
        }
        o_timeout = iv_timeout;
    } while (0);

    return l_err;
}

errlHndl_t NvdimmInstalledImage::clearFwOpsStatus()
{
    errlHndl_t l_err = nullptr;
    // NVDIMM_MGT_CMD1:
    // Bit 1 set, the module shall clear all the bits except Bit 2 in
    // the FIRMWARE_OPS_STATUS register
    uint8_t l_data = 0x02;
    l_err = nvdimmWriteReg(iv_dimm, NVDIMM_MGT_CMD1, l_data);
    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm_upd,ERR_MRK"clearFwOpsStatus: "
            "NVDIMM 0x%.8X clear FIRMWARE_OPS_STATUS register failed",
            TARGETING::get_huid(iv_dimm));
    }
    else
    {
        // Verify expected bits cleared

        // Setup expected cleared status byte
        fw_ops_status_t l_cleared_ops_status;
        l_cleared_ops_status.whole = 0x00;
        if (iv_fw_update_mode_enabled)
        {
            // set BIT 2 -- this should not be cleared by the command
            l_cleared_ops_status.fw_ops_update_mode = 1;
        }

        // Set some timeout so this doesn't cause endless loop
        uint16_t timeout_val = INVALID_TIMEOUT;
        l_err = getFwOpsTimeout(timeout_val);
        // Note: potential error will just exit the while loop and be returned

        // convert seconds to ms value
        // double the timeout to ensure enough time has elapsed for the clear
        // note: doubling here instead of just doubling timeout_val since that
        // variable is only a bit16 vs bit32
        uint32_t timeout_ms_val = timeout_val * 1000 * 2;

        fw_ops_status_t l_ops_status;

        while (!l_err)
        {
            l_err = nvdimmReadReg(iv_dimm, FIRMWARE_OPS_STATUS, l_ops_status.whole);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"clearFwOpsStatus: "
                    "NVDIMM 0x%.8X read FIRMWARE_OPS_STATUS register failed "
                    " (0x%02X)",
                    TARGETING::get_huid(iv_dimm), l_ops_status.whole);
                break;
            }

            // Exit if expected cleared status is found
            if (l_ops_status.whole == l_cleared_ops_status.whole)
            {
                break;
            }

            // wait 1 millisecond between checking status
            if (timeout_ms_val > 0)
            {
                timeout_ms_val -= 1;
                nanosleep(0, NS_PER_MSEC);
            }
            else
            {
                // timeout hit
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"clearFwOpsStatus: "
                    "NVDIMM 0x%.8X FIRMWARE_OPS_STATUS register reads 0x%02X "
                    "instead of cleared value of 0x%02X after %lld seconds",
                    TARGETING::get_huid(iv_dimm), l_ops_status.whole,
                    l_cleared_ops_status.whole, timeout_val*2);

                /*@
                 *@errortype
                 *@moduleid         CLEAR_FW_OPS_STATUS
                 *@reasoncode       NVDIMM_CLEAR_FW_OPS_STATUS_TIMEOUT
                 *@userdata1        NVDIMM Target Huid
                 *@userdata2[0:7]   Last FIRMWARE_OPS_STATUS read
                 *@userdata2[8:15]  Expected cleared status
                 *@userdata2[16:31] Reserved
                 *@userdata2[32:63] Timeout (seconds)
                 *@devdesc          FIRMWARE_OPS_STATUS not cleared
                 *@custdesc         NVDIMM not updated
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                       ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       CLEAR_FW_OPS_STATUS,
                                       NVDIMM_CLEAR_FW_OPS_STATUS_TIMEOUT,
                                       TARGETING::get_huid(iv_dimm),
                                       TWO_UINT16_ONE_UINT32_TO_UINT64
                                       (
                                          TWO_UINT8_TO_UINT16(
                                          l_ops_status.whole,
                                          l_cleared_ops_status.whole),
                                          0x0000,
                                          timeout_val * 2
                                       ),
                                       ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
                l_err->collectTrace(NVDIMM_COMP_NAME, 256);
                l_err->addPartCallout( iv_dimm,
                                       HWAS::NV_CONTROLLER_PART_TYPE,
                                       HWAS::SRCI_PRIORITY_HIGH );
                l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                            HWAS::SRCI_PRIORITY_LOW );

                break;
            }
        } // end of while (!l_err) loop
    }  // end of Verify expected bits cleared

    return l_err;
}

errlHndl_t NvdimmInstalledImage::isFwOpsSuccess(bool & o_success)
{
    errlHndl_t l_err = nullptr;
    o_success = false;

    fw_ops_status_t l_data;
    l_err = nvdimmReadReg(iv_dimm, FIRMWARE_OPS_STATUS, l_data.whole);
    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"isFwOpsSuccess: "
            "NVDIMM 0x%.8X read FIRMWARE_OPS_STATUS register failed (0x%02X)",
            TARGETING::get_huid(iv_dimm), l_data.whole);
    }
    else
    {
        if (l_data.fw_ops_success)
        {
            o_success = true;
        }
        else
        {
            // add this trace so we know what was returned from FIRMWARE_OP_STATUS read
            TRACFCOMP(g_trac_nvdimm_upd, "isFwOpsSuccess() returning false (0x%02X)",
                l_data.whole);
            o_success = false;
        }
    }
    return l_err;
}

errlHndl_t NvdimmInstalledImage::getBlocksPerRegion
                                    (uint8_t & io_blocks_per_region)
{
    errlHndl_t l_err = nullptr;

    io_blocks_per_region = iv_max_blocks_per_region;
    if (iv_max_blocks_per_region == INVALID_REGION_BLOCK_SIZE)
    {
        l_err = nvdimmReadReg(iv_dimm, REGION_BLOCK_SIZE, io_blocks_per_region);
        if (!l_err)
        {
            // If no error, update the class variable
            // as this gets called multiple times
            iv_max_blocks_per_region = io_blocks_per_region;
        }
    }
    return l_err;
}

errlHndl_t NvdimmInstalledImage::byteRegionBlockTransfer(const uint8_t * i_data,
                                                const uint16_t i_data_size,
                                                bool i_use_region_block_size)
{
    errlHndl_t l_err = nullptr;
    uint8_t blocks_per_region = 0x00;
    uint8_t max_blocks_per_region = 0x00;

    do {
        l_err = getBlocksPerRegion(max_blocks_per_region);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"byteRegionBlockTransfer: "
                "getBlocksPerRegion() failed on NVDIMM 0x%.8X",
                TARGETING::get_huid(iv_dimm));
            break;
        }

        // If the data passed in does not equal the region block size,
        // calculate the number of blocks required for the given data
        if (!i_use_region_block_size)
        {
            blocks_per_region = i_data_size/BYTES_PER_BLOCK;
            if (i_data_size % BYTES_PER_BLOCK)
            {
                // Add another block if data can't be evenly broken into
                // BYTES_PER_BLOCK blocks
                blocks_per_region++;
            }
            if (blocks_per_region > max_blocks_per_region)
            {
                /*@
                 *@errortype
                 *@moduleid         BYTE_REGION_BLOCK_TRANSFER
                 *@reasoncode       NVDIMM_DATA_SIZE_TOO_LARGE
                 *@userdata1        NVDIMM Target Huid
                 *@userdata2[0:15]  Data size trying to transfer
                 *@userdata2[16:31] Maximum data size allowed
                 *@userdata2[32:47] Calculated blocks_per_region
                 *@userdata2[48-63] Maximum blocks_per_region allowed
                 *@devdesc          Data size too big to transfer in one command
                 *@custdesc         NVDIMM not updated
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         BYTE_REGION_BLOCK_TRANSFER,
                                         NVDIMM_DATA_SIZE_TOO_LARGE,
                                         TARGETING::get_huid(iv_dimm),
                                         FOUR_UINT16_TO_UINT64(
                                          i_data_size,
                                          max_blocks_per_region*BYTES_PER_BLOCK,
                                          blocks_per_region,
                                          max_blocks_per_region),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
                break;
            }
        }
        else
        {
            blocks_per_region = max_blocks_per_region;
        }

        TRACUCOMP(g_trac_nvdimm_upd,"byteRegionBlockTransfer: blocks_per_region = 0x%02X", blocks_per_region);

        if (i_data_size > (BYTES_PER_BLOCK*blocks_per_region))
        {
            /*@
             *@errortype
             *@moduleid         BYTE_REGION_BLOCK_TRANSFER
             *@reasoncode       NVDIMM_DATA_SIZE_INVALID
             *@userdata1        NVDIMM Target Huid
             *@userdata2[0:15]  Data size trying to transfer
             *@userdata2[16:31] Calculated maximum data size transfer
             *@userdata2[32:47] Blocks per region
             *@userdata2[48-63] Bytes transferred per block
             *@devdesc          Data size too big to transfer
             *@custdesc         NVDIMM not updated
             */
            l_err = new ERRORLOG::ErrlEntry(
                                     ERRORLOG::ERRL_SEV_PREDICTIVE,
                                     BYTE_REGION_BLOCK_TRANSFER,
                                     NVDIMM_DATA_SIZE_INVALID,
                                     TARGETING::get_huid(iv_dimm),
                                     FOUR_UINT16_TO_UINT64(
                                        i_data_size,
                                        BYTES_PER_BLOCK*blocks_per_region,
                                        blocks_per_region,
                                        BYTES_PER_BLOCK),
                                     ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            break;
        }

        uint8_t blockNum = 0;
        uint8_t block[BYTES_PER_BLOCK]; // used for partial transfer
        uint8_t * pCurrentBlockData = nullptr;
        while (blockNum < blocks_per_region && (!l_err))
        {
            TRACUCOMP(g_trac_nvdimm_upd,"byteRegionBlockTransfer: block = 0x%02X", blockNum);
            l_err = nvdimmWriteReg(iv_dimm, BLOCK_ID, blockNum);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"byteRegionBlockTransfer: "
                    "Write 0x%02X to BLOCK_ID failed on NVDIMM 0x%.8X",
                    blockNum, TARGETING::get_huid(iv_dimm));
                break;
            }

            // Data must be transferred in multiple of BYTES_PER_BLOCK bytes.
            // If block_data is not BYTES_PER_BLOCK bytes, pad the end with 0s
            if ((i_data_size - BYTES_PER_BLOCK * blockNum) < BYTES_PER_BLOCK)
            {
                // clear entire block of bytes
                memset(block, 0x00, BYTES_PER_BLOCK);

                // add the last partial block of data bytes
                if (i_data_size > (blockNum * BYTES_PER_BLOCK))
                {
                    memcpy(block, &i_data[blockNum * BYTES_PER_BLOCK],
                        (i_data_size - (blockNum * BYTES_PER_BLOCK)));
                }
                pCurrentBlockData = block;
            }
            else
            {
                pCurrentBlockData = const_cast<uint8_t *>(&i_data[blockNum * BYTES_PER_BLOCK]);
            }

            // write out the 32-byte (BYTES_PER_BLOCK) data block
            TRACUCOMP(g_trac_nvdimm_upd,"byteRegionBlockTransfer: write out 32byte block 0x%02X", blockNum);
            l_err = nvdimmOpenPage(iv_dimm, PAGE(TYPED_BLOCK_DATA_BYTE0));
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"byteRegionBlockTransfer: "
                    "Unable to open page for BLOCK %d transfer of NVDIMM "
                    "0x%.8X", blockNum, TARGETING::get_huid(iv_dimm));
                break;
            }

            size_t l_numBytes = BYTES_PER_BLOCK;
            uint8_t l_reg_addr = ADDRESS(TYPED_BLOCK_DATA_BYTE0);

            // Grab whether word or 32-byte block write is supported
            uint64_t blockSizeSupported = INVALID_BLOCK_SIZE;
            l_err = getBlockWriteSizeSupported(blockSizeSupported);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"byteRegionBlockTransfer: "
                    "Unable to grab maximum block write size for NVDIMM 0x%.8X",
                    TARGETING::get_huid(iv_dimm));
                break;
            }

            l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                        iv_dimm,
                                        pCurrentBlockData,
                                        l_numBytes,
                                        DEVICE_NVDIMM_RAW_ADDRESS_WITH_BLOCKSIZE(l_reg_addr, blockSizeSupported)
                                       );
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"byteRegionBlockTransfer: "
                    "Block %d write to 0x%02X failed on NVDIMM 0x%.8X",
                    blockNum, l_reg_addr, TARGETING::get_huid(iv_dimm));
                break;
            }

            // After a block has been transferred, verify that the 32-byte block
            // was received by polling FIRMWARE_OPS_STATUS offset for
            // FIRMWARE_BLOCK_RECEIVED.
            l_err = waitFwOpsBlockReceived();
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"byteRegionBlockTransfer: "
                    "Block %d read of FIRMWARE_OPS_STATUS failed on NVDIMM "
                    " 0x%.8X", blockNum, TARGETING::get_huid(iv_dimm));

                size_t tmpNumBytes = l_numBytes;
                uint8_t tmpBuffer[tmpNumBytes];
                errlHndl_t l_err2 = DeviceFW::deviceOp( DeviceFW::READ,
                                           iv_dimm,
                                           tmpBuffer,
                                           tmpNumBytes,
                                           DEVICE_NVDIMM_ADDRESS(l_reg_addr) );
                if (l_err2)
                {
                    TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK"byteRegionBlockTransfer: "
                    "Block %d read from 0x%02X failed on NVDIMM 0x%.8X",
                    blockNum, l_reg_addr, TARGETING::get_huid(iv_dimm));
                    l_err2->plid(l_err->plid());
                    l_err2->collectTrace(NVDIMM_COMP_NAME);
                    l_err2->collectTrace(NVDIMM_UPD);
                    errlCommit(l_err2, NVDIMM_COMP_ID);
                    break;
                }
                else
                {
                    TRACFBIN(g_trac_nvdimm_upd, "byteRegionBlockTransfer: Wrote block", pCurrentBlockData, l_numBytes);
                    TRACFBIN(g_trac_nvdimm_upd, "byteRegionBlockTransfer: Read-back block", tmpBuffer, l_numBytes);
                }

                break;
            }

            // block of data successfully sent to NV controller
            TRACUCOMP(g_trac_nvdimm_upd,"byteRegionBlockTransfer: block 0x%02X successfully sent to NV controller", blockNum);

            // increment to next block
            pCurrentBlockData += BYTES_PER_BLOCK;
            blockNum++;
        }

    } while (0);

    return l_err;
} // end byteRegionBlockTransfer()

errlHndl_t NvdimmInstalledImage::calcAndGetCksm(uint16_t & o_nvCksm)
{
    errlHndl_t l_err = nullptr;

    // Command the module to calculate the checksum
    fw_ops_cmd_t opsCmd;
    opsCmd.whole = 0x00;
    opsCmd.start_generate_fw_checksum_op = 1;
    l_err = nvdimmWriteReg(iv_dimm, FIRMWARE_OPS_CMD, opsCmd.whole);
    if (!l_err)
    {
        l_err = waitFwOpsComplete();
        if (!l_err)
        {
            bool opSuccessful = false;
            l_err = isFwOpsSuccess(opSuccessful);
            if (!l_err && opSuccessful)
            {
                uint8_t lsb, msb;
                l_err = nvdimmReadReg(iv_dimm, FW_REGION_CRC0, lsb);
                if (!l_err)
                {
                    l_err = nvdimmReadReg(iv_dimm, FW_REGION_CRC1, msb);
                    if (!l_err)
                    {
                        o_nvCksm = (msb << 8) | lsb;
                    }
                }
            }
        }
    }
    return l_err;
}

errlHndl_t NvdimmInstalledImage::validateFwHeader()
{
    errlHndl_t l_err = nullptr;

    l_err = clearFwOpsStatus();
    if (!l_err)
    {
        fw_ops_cmd_t opsCmd;
        opsCmd.whole = 0x00;
        opsCmd.start_validate_fw_header_op = 1;

        l_err = nvdimmWriteReg(iv_dimm, FIRMWARE_OPS_CMD, opsCmd.whole);
        if (!l_err)
        {
            l_err = waitFwOpsComplete();
            if (!l_err)
            {
                bool opsSuccessful = false;
                l_err = isFwOpsSuccess(opsSuccessful);
                if (!l_err && !opsSuccessful)
                {
                    /*@
                     *@errortype
                     *@moduleid         VALIDATE_FW_HEADER
                     *@reasoncode       NVDIMM_FW_OPS_NOT_SUCCESSFUL
                     *@userdata1        NVDIMM Target Huid
                     *@userdata2        Operation command being verified
                     *@devdesc          Firmware Operation not successful
                     *@custdesc         NVDIMM not updated
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           VALIDATE_FW_HEADER,
                                           NVDIMM_FW_OPS_NOT_SUCCESSFUL,
                                           TARGETING::get_huid(iv_dimm),
                                           opsCmd.whole,
                                           ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
                    l_err->collectTrace(NVDIMM_COMP_NAME, 256 );
                    nvdimmAddVendorLog(iv_dimm, l_err);
                    l_err->addPartCallout( iv_dimm,
                                           HWAS::NV_CONTROLLER_PART_TYPE,
                                           HWAS::SRCI_PRIORITY_HIGH );
                    l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                                HWAS::SRCI_PRIORITY_LOW );
                    nvdimmAddPage4Regs(iv_dimm,l_err);
                    nvdimmAddUpdateRegs(iv_dimm,l_err);
                }
            }
        }
    }
    return l_err;
}

errlHndl_t NvdimmInstalledImage::commitFwRegion()
{
    errlHndl_t l_err = nullptr;

    l_err = clearFwOpsStatus();
    if (!l_err)
    {
        fw_ops_cmd_t opsCmd;
        opsCmd.whole = 0x00;
        opsCmd.start_commit_fw_op = 1;
        l_err = nvdimmWriteReg(iv_dimm, FIRMWARE_OPS_CMD, opsCmd.whole);
        if (!l_err)
        {
            l_err = waitFwOpsComplete();
            if (!l_err)
            {
                bool opsSuccessful = false;
                l_err = isFwOpsSuccess(opsSuccessful);
                if (!l_err && !opsSuccessful)
                {
                    /*@
                     *@errortype
                     *@moduleid         COMMIT_FW_REGION
                     *@reasoncode       NVDIMM_FW_OPS_NOT_SUCCESSFUL
                     *@userdata1        NVDIMM Target Huid
                     *@userdata2        Operation command being verified
                     *@devdesc          Firmware Operation not successful
                     *@custdesc         NVDIMM not updated
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           COMMIT_FW_REGION,
                                           NVDIMM_FW_OPS_NOT_SUCCESSFUL,
                                           TARGETING::get_huid(iv_dimm),
                                           opsCmd.whole,
                                           ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
                    l_err->collectTrace(NVDIMM_COMP_NAME, 256 );
                    nvdimmAddVendorLog(iv_dimm, l_err);
                    l_err->addPartCallout( iv_dimm,
                                           HWAS::NV_CONTROLLER_PART_TYPE,
                                           HWAS::SRCI_PRIORITY_HIGH );
                    l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                                HWAS::SRCI_PRIORITY_LOW );
                    nvdimmAddPage4Regs(iv_dimm,l_err);
                    nvdimmAddUpdateRegs(iv_dimm,l_err);
                }
            }
        }
    }
    return l_err;
}

errlHndl_t NvdimmInstalledImage::clearFwDataBlock()
{
    errlHndl_t l_err = nullptr;

    // clearFwOps
    fw_ops_cmd_t opsCmd;
    opsCmd.whole = 0x00;
    opsCmd.start_clear_fw_op = 1;
    TRACUCOMP(g_trac_nvdimm_upd, "clearFwDataBlock: clearFwOps cmd 0x%02X", opsCmd.whole);
    l_err = nvdimmWriteReg(iv_dimm, FIRMWARE_OPS_CMD, opsCmd.whole);
    if (!l_err)
    {
        TRACUCOMP(g_trac_nvdimm_upd, "clearFwDataBlock: start waitFwOpsComplete");
        l_err = waitFwOpsComplete();
        if (!l_err)
        {
            bool ops_success = false;
            TRACUCOMP(g_trac_nvdimm_upd, "clearFwDataBlock: done waiting now check FwOpsStatus for success");
            l_err = isFwOpsSuccess(ops_success);
            if (!l_err && !ops_success)
            {
                /*@
                 *@errortype
                 *@moduleid         CLEAR_FW_DATA_BLOCK
                 *@reasoncode       NVDIMM_FW_OPS_NOT_SUCCESSFUL
                 *@userdata1        NVDIMM Target Huid
                 *@userdata2        Operation command being verified
                 *@devdesc          Firmware Operation not successful
                 *@custdesc         NVDIMM not updated
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                       ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       CLEAR_FW_DATA_BLOCK,
                                       NVDIMM_FW_OPS_NOT_SUCCESSFUL,
                                       TARGETING::get_huid(iv_dimm),
                                       opsCmd.whole,
                                       ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
                l_err->collectTrace(NVDIMM_COMP_NAME, 256 );
                nvdimmAddVendorLog(iv_dimm, l_err);
                l_err->addPartCallout( iv_dimm,
                                       HWAS::NV_CONTROLLER_PART_TYPE,
                                       HWAS::SRCI_PRIORITY_HIGH );
                l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                            HWAS::SRCI_PRIORITY_LOW );
                nvdimmAddPage4Regs(iv_dimm,l_err);
                nvdimmAddUpdateRegs(iv_dimm,l_err);
            }
        }
    }
    return l_err;
}

errlHndl_t NvdimmInstalledImage::validateFwImage()
{
    errlHndl_t l_err = nullptr;

    l_err = clearFwOpsStatus();
    if (!l_err)
    {
        fw_ops_cmd_t opsCmd;
        opsCmd.whole = 0x00;
        opsCmd.start_validate_fw_image_op = 1;
        l_err = nvdimmWriteReg(iv_dimm, FIRMWARE_OPS_CMD, opsCmd.whole);
        if (!l_err)
        {
            l_err = waitFwOpsComplete();
            if (!l_err)
            {
                bool opsSuccessful = false;
                l_err = isFwOpsSuccess(opsSuccessful);
                // create an error if operation not successful
                if (!l_err && !opsSuccessful)
                {
                    /*@
                     *@errortype
                     *@moduleid         VALIDATE_FW_IMAGE
                     *@reasoncode       NVDIMM_FW_OPS_NOT_SUCCESSFUL
                     *@userdata1        NVDIMM Target Huid
                     *@userdata2        Operation command being verified
                     *@devdesc          Firmware Operation not successful
                     *@custdesc         NVDIMM not updated
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           VALIDATE_FW_IMAGE,
                                           NVDIMM_FW_OPS_NOT_SUCCESSFUL,
                                           TARGETING::get_huid(iv_dimm),
                                           opsCmd.whole,
                                           ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
                    l_err->collectTrace(NVDIMM_COMP_NAME, 256 );
                    nvdimmAddVendorLog(iv_dimm, l_err);
                    l_err->addPartCallout( iv_dimm,
                                           HWAS::NV_CONTROLLER_PART_TYPE,
                                           HWAS::SRCI_PRIORITY_HIGH );
                    l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                                HWAS::SRCI_PRIORITY_LOW );
                    nvdimmAddPage4Regs(iv_dimm,l_err);
                    nvdimmAddUpdateRegs(iv_dimm,l_err);
                }
            }
        }
    }
    return l_err;
}

uint16_t NvdimmInstalledImage::crc16(const uint8_t * i_data, int i_data_size)
{
    // From JEDEC JESD245B.01 document
    // https://www.jedec.org/standards-documents/docs/jesd245a
    int i, crc;
    crc = 0;
    while (--i_data_size >= 0)
    {
        crc = crc ^ (int)*i_data++ << 8;
        for (i = 0; i < 8; ++i)
        {
           if (crc & 0x8000)
           {
               crc = crc << 1 ^ 0x1021;
           }
           else
           {
               crc = crc << 1;
           }
        }
    }
    return (crc & 0xFFFF);
}

///////////////////////////////////////////////////////////////////////////////
// NVDIMMS Update Functions
///////////////////////////////////////////////////////////////////////////////
NvdimmsUpdate::NvdimmsUpdate(TARGETING::TargetHandleList i_nvdimmList)
{
    iv_nvdimmList = i_nvdimmList;
}

bool NvdimmsUpdate::runUpdateUsingLid(NvdimmLidImage * i_lidImage,
                                std::vector<NvdimmInstalledImage *> &i_list)
{
    bool o_no_error_found = true;

   // Get the sys target to check for attribute overrides.
    TARGETING::Target* sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(sys);

    auto l_forceFwUpdate =
        sys->getAttr<TARGETING::ATTR_NVDIMM_FORCE_FW_UPDATE>();

    errlHndl_t l_err = nullptr;
    for (auto pInstalledImage : i_list)
    {
        TARGETING::Target * l_nvdimm = pInstalledImage->getNvdimmTarget();
        uint64_t l_nvdimm_huid = TARGETING::get_huid(l_nvdimm);

        INITSERVICE::sendProgressCode();
        bool updateNeeded = false;
        l_err = isUpdateNeeded(updateNeeded, i_lidImage, pInstalledImage);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "NvdimmsUpdate::runUpdateUsingLid()"
                " Unable to determine if nvdimm[%X] needs NV controller update."
                " RC=0x%X, PLID=0x%.8X",
                TARGETING::get_huid(pInstalledImage->getNvdimmTarget()),
                ERRL_GETRC_SAFE(l_err), ERRL_GETPLID_SAFE(l_err));
            commitPredictiveNvdimmError(l_err);
            o_no_error_found = false;
            continue;
        }

        if (updateNeeded || l_forceFwUpdate)
        {
            // shared trace variables
            uint32_t l_installed_type = INVALID_TYPE;
            l_err = pInstalledImage->getType(l_installed_type);
            if (l_err)
            {
                // Continue updating other dimms
                TRACFCOMP(g_trac_nvdimm_upd,
                    ERR_MRK"NvdimmsUpdate::runUpdateUsingLid() - "
                    "Unable to get nvdimm[0x%.8X] installed image type. "
                    "RC=0x%X, PLID=0x%.8X", l_nvdimm_huid,
                    ERRL_GETRC_SAFE(l_err), ERRL_GETPLID_SAFE(l_err));
                commitPredictiveNvdimmError(l_err);
                l_err = nullptr;
                continue;
            }

            uint16_t l_oldVersion = INVALID_VERSION;
            l_err = pInstalledImage->getVersion(l_oldVersion);
            if (l_err)
            {
                // This shouldn't happen as getVersion should return a
                // cached version
                TRACFCOMP(g_trac_nvdimm_upd,
                    ERR_MRK"NvdimmsUpdate::runUpdateUsingLid() - "
                    "Failed to find current NVDIMM level of %.8X. "
                    "RC=0x%X, PLID=0x%.8X", l_nvdimm_huid,
                    ERRL_GETRC_SAFE(l_err), ERRL_GETPLID_SAFE(l_err));
                commitPredictiveNvdimmError(l_err);
                l_err = nullptr;
                o_no_error_found = false;
                continue;
            }

            // perform update for this DIMM with the current LID image
            TRACFCOMP(g_trac_nvdimm_upd, "NvdimmsUpdate::runUpdateUsingLid() - "
                "now update nvdimm[0x%.8X] -- force: %d, updateNeeded: %d",
                l_nvdimm_huid, l_forceFwUpdate, updateNeeded);

            TRACFCOMP(g_trac_nvdimm_upd,"Updating with flash size: 0x%08X",
                i_lidImage->getFlashImageSize());

            /*@
             *@errortype        INFORMATIONAL
             *@reasoncode       NVDIMM_START_UPDATE
             *@moduleid         NVDIMM_RUN_UPDATE_USING_LID
             *@userdata1        NVDIMM Target Huid
             *@userdata2[0:15]  Old level (current)
             *@userdata2[16:31] Update image level (new)
             *@userdata2[32:63] Installed type (manufacturer and product)
             *@devdesc          Start of the NVDIMM update of this controller
             *@custdesc         NVDIMM update started
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                       NVDIMM_RUN_UPDATE_USING_LID,
                                       NVDIMM_START_UPDATE,
                                       l_nvdimm_huid,
                                       TWO_UINT16_ONE_UINT32_TO_UINT64(
                                       l_oldVersion, i_lidImage->getVersion(),
                                       l_installed_type),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_err->collectTrace(NVDIMM_UPD, 256);
            ERRORLOG::errlCommit(l_err, NVDIMM_COMP_ID);
            l_err = nullptr;

            // hold original error in case retry works
            errlHndl_t l_original_error = nullptr;
            do
            {
                // put controller into a known state
                // (helps recover from previous update failures)
                l_err = nvdimmResetController(l_nvdimm);
                if (l_err)
                {
                    TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK
                        "NvdimmsUpdate::runUpdateUsingLid() - :  "
                        "Unable to reset controller for 0x%.8X nvdimm "
                        "RC=0x%X, PLID=0x%.8X", l_nvdimm_huid,
                        ERRL_GETRC_SAFE(l_err), ERRL_GETPLID_SAFE(l_err));
                    commitPredictiveNvdimmError(l_err);
                    l_err = nullptr;
                    break;
                }

                l_err = pInstalledImage->updateImage(i_lidImage);
                if (l_err)
                {
                    // If update fails, the NV controller will run on its factory
                    // installed version in slot 0.
                    // We will call out the failed NVDIMM for replacement, but try
                    // to keep running with as much function as possible.
                    TRACFCOMP(g_trac_nvdimm_upd,
                        ERR_MRK"NvdimmsUpdate::runUpdateUsingLid() - "
                        "NVDIMM 0x%.8X NV controller update failed. "
                        "RC=0x%X, PLID=0x%.8X", l_nvdimm_huid,
                        ERRL_GETRC_SAFE(l_err), ERRL_GETPLID_SAFE(l_err));

                    if (l_original_error == nullptr)
                    {
                        l_original_error = l_err;
                        l_original_error->collectTrace(NVDIMM_UPD, 512);
                        l_err = nullptr;
                        continue;
                    }
                    else
                    {
                        // already retried, just break now
                        break;
                    }
                }
                else
                {
                    // successfully updated this NVDIMM

                    // Note: call for version should just return a saved value
                    uint16_t curVersion = INVALID_VERSION;
                    l_err = pInstalledImage->getVersion(curVersion);
                    if (l_err)
                    {
                        TRACFCOMP(g_trac_nvdimm_upd,
                            ERR_MRK"NvdimmsUpdate::runUpdateUsingLid() - "
                            "Failed to find current NVDIMM level of %.8X after "
                            "successful update. RC=0x%X, PLID=0x%.8X",
                            l_nvdimm_huid,
                            ERRL_GETRC_SAFE(l_err), ERRL_GETPLID_SAFE(l_err));
                        commitPredictiveNvdimmError(l_err);
                        l_err = nullptr;
                    }

                    /*@
                     *@errortype        INFORMATIONAL
                     *@reasoncode       NVDIMM_UPDATE_COMPLETE
                     *@moduleid         NVDIMM_RUN_UPDATE_USING_LID
                     *@userdata1[0:31]  NVDIMM Target Huid
                     *@userdata1[32:63] Total region write retries
                     *@userdata2[0:15]  Previous level
                     *@userdata2[16:31] Current updated level
                     *@userdata2[32:63] Installed type (manufacturer and product)
                     *@devdesc          Successful update of NVDIMM code
                     *@custdesc         NVDIMM was successfully updated
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                 NVDIMM_RUN_UPDATE_USING_LID,
                                 NVDIMM_UPDATE_COMPLETE,
                                 TWO_UINT32_TO_UINT64(
                                   l_nvdimm_huid,
                                   pInstalledImage->getRegionWriteRetries()),
                                 TWO_UINT16_ONE_UINT32_TO_UINT64(
                                   l_oldVersion, curVersion,
                                   l_installed_type),
                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
                    l_err->collectTrace(NVDIMM_UPD, 512);
                    ERRORLOG::errlCommit(l_err, NVDIMM_COMP_ID);
                    l_err = nullptr;
                    break;
                }
            } while (l_err == nullptr);

            if (l_err && l_original_error)
            {
                // link the new error to the original failure error
                l_err->plid(l_original_error->plid());
                // don't recollect trace data for original error
                ERRORLOG::errlCommit(l_original_error, NVDIMM_COMP_ID);

                // log this latest failure as predictive,
                // since dimm wasn't updated
                commitPredictiveNvdimmError(l_err);
                l_err = nullptr;
                l_original_error = nullptr;
                o_no_error_found = false;

                // go to next dimm in list as this one failed update
                continue;
            }
            else if (l_original_error)
            {
                // recovered from the first failure
                l_original_error->setSev( ERRORLOG::ERRL_SEV_RECOVERED );
                ERRORLOG::errlCommit(l_original_error, NVDIMM_COMP_ID);
                l_original_error = nullptr;
            }
            else if (l_err)
            {
                // should not hit this case, but cleanup error if necessary
                commitPredictiveNvdimmError(l_err);
                l_err = nullptr;
            }
            //else - no errors

        } // end of updateNeeded

        /////////////////////////////////////////////////////////////////
        // Should not exit the nvdimm update stage until each nvdimm
        // is running at the lid's code level
        // (or a predictive error was logged for that nvdimm)
        /////////////////////////////////////////////////////////////////

        // Check NVDIMM is at the latest level and it is running from slot 1
        uint16_t l_curVersion = INVALID_VERSION;
        l_err = pInstalledImage->getVersion(l_curVersion, true);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd,
                ERR_MRK"NvdimmsUpdate::runUpdateUsingLid() - "
                "Failed to find current level of NVDIMM %.8X. "
                "RC=0x%X, PLID=0x%.8X", l_nvdimm_huid,
                ERRL_GETRC_SAFE(l_err), ERRL_GETPLID_SAFE(l_err));
            commitPredictiveNvdimmError(l_err);
            l_err = nullptr;
            o_no_error_found = false;
            continue;
        }
        uint8_t l_slot_running = 0;
        l_err = nvdimmGetRunningSlot(l_nvdimm, l_slot_running);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd,
                ERR_MRK"NvdimmsUpdate::runUpdateUsingLid() - "
                "Failed to find running slot of NVDIMM %.8X. "
                "RC=0x%X, PLID=0x%.8X", l_nvdimm_huid,
                ERRL_GETRC_SAFE(l_err), ERRL_GETPLID_SAFE(l_err));
            commitPredictiveNvdimmError(l_err);
            l_err = nullptr;
            o_no_error_found = false;
            continue;
        }

        if ((l_slot_running == 0) || (l_curVersion != i_lidImage->getVersion()))
        {
            // Not running latest code on this NVDIMM
            TRACFCOMP(g_trac_nvdimm_upd,
                ERR_MRK"NvdimmsUpdate::runUpdateUsingLid() - "
                "NVDIMM %.8X running from slot %d with code level "
                "0x%04X (lid level: 0x%04X)",
                l_nvdimm_huid, l_slot_running, l_curVersion,
                i_lidImage->getVersion());
            /*@
             *@errortype
             *@reasoncode       NVDIMM_NOT_RUNNING_LATEST_LEVEL
             *@severity         ERRORLOG_SEV_PREDICTIVE
             *@moduleid         NVDIMM_RUN_UPDATE_USING_LID
             *@userdata1        NVDIMM Target Huid
             *@userdata2[0:15]  NVDIMM slot
             *@userdata2[16:31] slot1 version
             *@userdata2[32:47] latest version from lid
             *@devdesc          Encountered error after update while checking
             *                  if NVDIMM is running latest code level
             *@custdesc         NVDIMM not running latest firmware level
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                          NVDIMM_RUN_UPDATE_USING_LID,
                                          NVDIMM_NOT_RUNNING_LATEST_LEVEL,
                                          l_nvdimm_huid,
                                          FOUR_UINT16_TO_UINT64(
                                              l_slot_running,
                                              l_curVersion,
                                              i_lidImage->getVersion(),
                                              0x0000),
                                          ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace( NVDIMM_COMP_NAME );

            // Add callout of nvdimm with no deconfig/gard
            l_err->addHwCallout( l_nvdimm,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL);

            // Maybe vendor log will tell why it isn't running latest code level
            nvdimmAddVendorLog(l_nvdimm, l_err);
            commitPredictiveNvdimmError(l_err);
            l_err = nullptr;
            o_no_error_found = false;
        }
        else
        {
            TRACFCOMP(g_trac_nvdimm_upd,
                "NvdimmsUpdate::runUpdateUsingLid() - "
                "NVDIMM %.8X running from slot %d with latest level 0x%04X",
                l_nvdimm_huid, l_slot_running, l_curVersion);
        }
    }
    return o_no_error_found;
}

bool NvdimmsUpdate::runUpdate(void)
{
    bool o_no_error_found = true;  // true if no error was found during update

    errlHndl_t l_err = nullptr;

    uint32_t l_installed_type = INVALID_TYPE; // current LID type installed

    // List of each installed NVDIMM type
    std::vector<NvdimmInstalledImage*> v_NVDIMM_16GB_list;
    std::vector<NvdimmInstalledImage*> v_NVDIMM_32GB_list;
    BPM::bpmList_t NVDIMM_BPM_16GB_list;
    BPM::bpmList_t NVDIMM_BPM_32GB_list;

    // Build up installed NVDIMM image lists
    for (auto l_nvdimm : iv_nvdimmList)
    {
        NvdimmInstalledImage * l_installed_image =
            new NvdimmInstalledImage(l_nvdimm);

        l_err = l_installed_image->getType(l_installed_type);
        if (l_err)
        {
            // Continue updating other dimms
            TRACFCOMP(g_trac_nvdimm_upd, ERR_MRK "NvdimmsUpdate::runUpdate() - "
                "Unable to get nvdimm[0x%.8X] installed image type. "
                "RC=0x%X, PLID=0x%.8X",
                get_huid(l_nvdimm), ERRL_GETRC_SAFE(l_err),
                ERRL_GETPLID_SAFE(l_err));
            commitPredictiveNvdimmError(l_err);
            o_no_error_found = false;

            // Delete the unused NvdimmInstalledImage pointer
            delete l_installed_image;

            continue;
        }

        if (l_installed_type == SMART_NVDIMM_16GB_TYPE)
        {
            TRACFCOMP(g_trac_nvdimm_upd, "NvdimmsUpdate::runUpdate() - "
                "0x%.8X NVDIMM is SMART_NVDIMM_16GB_TYPE",
                get_huid(l_nvdimm));
            v_NVDIMM_16GB_list.push_back(l_installed_image);

            BPM::Bpm l_16gbBpm(l_nvdimm);
            NVDIMM_BPM_16GB_list.push_back(l_16gbBpm);

        }
        else if (l_installed_type == SMART_NVDIMM_32GB_TYPE)
        {
            TRACFCOMP(g_trac_nvdimm_upd, "NvdimmsUpdate::runUpdate() - "
                "0x%.8X NVDIMM is SMART_NVDIMM_32GB_TYPE",
                get_huid(l_nvdimm));
            v_NVDIMM_32GB_list.push_back(l_installed_image);

            BPM::Bpm l_32gbBpm(l_nvdimm);
            NVDIMM_BPM_32GB_list.push_back(l_32gbBpm);
        }
        else
        {
            // unknown/unsupported Type
            TRACFCOMP(g_trac_nvdimm_upd, "NvdimmsUpdate::runUpdate() - unknown "
                "nvdimm[%X] installed type 0x%04X, skipping update",
                TARGETING::get_huid(l_nvdimm), l_installed_type);
            /*@
             *@errortype
             *@reasoncode       NVDIMM_UNSUPPORTED_NVDIMM_TYPE
             *@moduleid         NVDIMM_RUN_UPDATE
             *@userdata1[0:31]  Unsupported Type
             *@userdata1[32:63] NVDIMM Target Huid
             *@userdata2[0:31]  Supported nvdimm type
             *@userdata2[32:63] Other supported nvdimm type
             *@devdesc          Unable to update an unsupported NVDIMM type
             *@custdesc         NVDIMM not updated
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                           NVDIMM_RUN_UPDATE,
                                           NVDIMM_UNSUPPORTED_NVDIMM_TYPE,
                                           TWO_UINT32_TO_UINT64(
                                              l_installed_type,
                                              TARGETING::get_huid(l_nvdimm)),
                                           TWO_UINT32_TO_UINT64(
                                              SMART_NVDIMM_16GB_TYPE,
                                              SMART_NVDIMM_32GB_TYPE),
                                           ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME, 256 );
            l_err->collectTrace(NVDIMM_UPD, 256);
            nvdimmAddVendorLog(l_nvdimm, l_err);
            l_err->addPartCallout( l_nvdimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH );
            l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW );
            nvdimmAddPage4Regs(l_nvdimm,l_err);
            nvdimmAddUpdateRegs(l_nvdimm,l_err);
            ERRORLOG::errlCommit(l_err, NVDIMM_COMP_ID);

            // Delete the unused NvdimmInstalledImage object
            delete l_installed_image;

            continue;
        }
    }

    do {
        // First check that updatable NVDIMMs or BPMs exist on the system
        if (   (v_NVDIMM_16GB_list.size() == 0)
            && (v_NVDIMM_32GB_list.size() == 0)
            && (NVDIMM_BPM_16GB_list.size() == 0)
            && (NVDIMM_BPM_32GB_list.size() == 0))
        {
            TRACFCOMP(g_trac_nvdimm_upd, "NvdimmsUpdate::runUpdate() - "
                "No updatable NVDIMMs or BPMs present on the system");
            break;
        }

        if (INITSERVICE::spBaseServicesEnabled())
        {
            // Load the NVDIMM flash binary via the MCL in load-only mode
            MCL::MasterContainerLidMgr mclManager(true);
            MCL::CompInfo info;
            l_err = mclManager.processSingleComponent(MCL::g_NvdimmCompId,info);
            if(l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK "NvdimmsUpdate::runUpdate() - "
                    "unable to obtain NVDIMM lid images - ");
                commitPredictiveNvdimmError(l_err);
                o_no_error_found = false;
                break;
            }

            // Both the config and firmware images are needed to perform an
            // update on a BPM. So, get pointers to each in the CompInfo
            // struct's vector of LID IDs.
            MCL::LidInfo * bpm_16gb_fw = nullptr;
            MCL::LidInfo * bpm_16gb_config = nullptr;
            MCL::LidInfo * bpm_32gb_fw = nullptr;
            MCL::LidInfo * bpm_32gb_config = nullptr;

            for(auto& lid : info.lidIds)
            {
                TRACFCOMP(g_trac_nvdimm,"LID ID=0x%08X, size=%d, vAddr=%p",
                    lid.id, lid.size, lid.vAddr);

                if (lid.id == NVDIMM_16GB_LIDID)
                {
                    if (v_NVDIMM_16GB_list.size() > 0)
                    {
                        // Grab the 16GB lid
                        TRACFCOMP(g_trac_nvdimm,
                            "Check/update %d 16GB_TYPE NVDIMMs",
                            v_NVDIMM_16GB_list.size());
                        NvdimmLidImage lidImage(lid.vAddr, lid.size);
                        o_no_error_found &= runUpdateUsingLid(&lidImage,
                                                            v_NVDIMM_16GB_list);
                    }
                }
                else if (lid.id == NVDIMM_32GB_LIDID)
                {
                    if (v_NVDIMM_32GB_list.size() > 0)
                    {
                        // Grab the 32GB lid
                        TRACFCOMP(g_trac_nvdimm,
                            "Check/update %d 32GB_TYPE NVDIMMs",
                            v_NVDIMM_32GB_list.size());
                        NvdimmLidImage lidImage(lid.vAddr, lid.size);
                        o_no_error_found &= runUpdateUsingLid(&lidImage,
                                                            v_NVDIMM_32GB_list);
                    }
                }
                else if (lid.id == NVDIMM_32GB_BPM_FW_LIDID)
                {
                    bpm_32gb_fw = &lid;
                }
                else if (lid.id == NVDIMM_32GB_BPM_CONFIG_LIDID)
                {
                    bpm_32gb_config = &lid;
                }
                else if (lid.id == NVDIMM_16GB_BPM_FW_LIDID)
                {
                    bpm_16gb_fw = &lid;
                }
                else if (lid.id == NVDIMM_16GB_BPM_CONFIG_LIDID)
                {
                    bpm_16gb_config = &lid;
                }
                else if (lid.id != NVDIMM_SIGNATURE_LIDID)
                {
                    TRACFCOMP(g_trac_nvdimm, "NvdimmsUpdate::runUpdate() - "
                        "Unknown NVDIMM LID: ID=0x%08X, size=%d",
                        lid.id, lid.size);
                    TRACFBIN(g_trac_nvdimm, "Unknown LID", lid.vAddr, 64);
                }
            }

            // Run BPM updates on NVDIMMs
            BPM::BpmFirmwareLidImage fwImage_16gb(bpm_16gb_fw->vAddr,
                                                  bpm_16gb_fw->size);

            BPM::BpmFirmwareLidImage fwImage_32gb(bpm_32gb_fw->vAddr,
                                                  bpm_32gb_fw->size);

            BPM::BpmConfigLidImage configImage_16gb(bpm_16gb_config->vAddr,
                                                    bpm_16gb_config->size);

            BPM::BpmConfigLidImage configImage_32gb(bpm_32gb_config->vAddr,
                                                    bpm_32gb_config->size);

            BPM::runBpmUpdates(&NVDIMM_BPM_16GB_list,
                               &NVDIMM_BPM_32GB_list,
                               &fwImage_16gb,
                               &fwImage_32gb,
                               &configImage_16gb,
                               &configImage_32gb);

            // Destructor automatically unloads the NVDIMM flash binary
        }
        else
        {
            TRACFCOMP(g_trac_nvdimm_upd, "NvdimmsUpdate::runUpdate() -  "
                "spBaseServices not running, therefore NVDIMM LID images "
                "cannot be accessed");
            // potential openpower support in future, so don't throw an error
            break;
        }
    } while (0); // end of flash update section

    // Clean up the pointers used in v_NVDIMM_16GB_list and v_NVDIMM_32GB_list
    for (const auto& pInstalledImage : v_NVDIMM_16GB_list)
    {
        delete pInstalledImage;
    }
    for (const auto& pInstalledImage : v_NVDIMM_32GB_list)
    {
        delete pInstalledImage;
    }

    return o_no_error_found;
}

errlHndl_t NvdimmsUpdate::isUpdateNeeded(bool & o_update_needed,
                                   NvdimmLidImage * i_lid_image,
                                   NvdimmInstalledImage * i_cur_image)
{
    o_update_needed = false;  // initialize to false

    errlHndl_t l_err = nullptr;
    uint32_t lidType = INVALID_TYPE;
    uint32_t curType = INVALID_TYPE;

    do {
        TARGETING::Target * l_dimm = i_cur_image->getNvdimmTarget();

        // check Types match (same manufacturer and product)
        lidType = i_lid_image->getType();
        l_err = i_cur_image->getType(curType);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm_upd,
                "isUpdateNeeded(): failed to find type of NVDIMM[%X]",
                TARGETING::get_huid(l_dimm));
            break;
        }

        if ((lidType == curType) && (lidType != INVALID_TYPE))
        {
            // check that versions do NOT match
            uint16_t curVersion = INVALID_VERSION;
            uint16_t lidVersion = i_lid_image->getVersion();
            l_err = i_cur_image->getVersion(curVersion);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm_upd,
                    "isUpdateNeeded(): failed to find version of NVDIMM[%X]",
                    TARGETING::get_huid(l_dimm));
                break;
            }

            // Put a check here for non-updateable SMART NVDIMMs.
            // Anything before 0x0030 should bypass the update, as update
            // would fail due to a bug in the backlevel firmware on the
            // nvdimm card (exception: 0x0000 = slot blank so allow update)
            if ((curVersion != 0x0000) && (le16toh(curVersion) < 0x0030))
            {
                TRACFCOMP(g_trac_nvdimm_upd,
                    "isUpdateNeeded(): non-updatable SMART NVDIMM 0x%.8X "
                    "(0x%04X)",
                    TARGETING::get_huid(l_dimm), le16toh(curVersion));
                /*@
                 *@errortype
                 *@reasoncode       NVDIMM_UPDATE_NOT_SUPPORTED
                 *@moduleid         NVDIMM_IS_UPDATE_NEEDED
                 *@userdata1[0:31]  NVDIMM version level
                 *@userdata1[32:63] NVDIMM Target Huid
                 *@userdata2        NVDIMM type (manufacturer and product)
                 *@devdesc          Unable to update an NVDIMM at this code level
                 *@custdesc         Unsupported level of NVDIMM hardware
                 */
                l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           NVDIMM_IS_UPDATE_NEEDED,
                                           NVDIMM_UPDATE_NOT_SUPPORTED,
                                           TWO_UINT32_TO_UINT64(
                                               curVersion,
                                               TARGETING::get_huid(l_dimm)),
                                           curType,
                                           ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
                l_err->collectTrace( NVDIMM_UPD, 256 );
                nvdimmAddVendorLog(const_cast<TARGETING::Target*>(l_dimm),
                                   l_err);
                l_err->addHwCallout( l_dimm,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::DECONFIG,
                                     HWAS::GARD_Fatal);
                l_err->addPartCallout( l_dimm,
                                       HWAS::NV_CONTROLLER_PART_TYPE,
                                       HWAS::SRCI_PRIORITY_MED );
                l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                            HWAS::SRCI_PRIORITY_LOW );
                break;
            }

            if (curVersion != lidVersion)
            {
                // verify we are updating with a good version
                if (lidVersion != INVALID_VERSION)
                {
                    // Found mismatched version and a valid lid update version
                    // so an update can proceed
                    o_update_needed = true;

                    TRACFCOMP(g_trac_nvdimm_upd,
                        "NVDIMM[%X] code level - current: 0x%04X, new: 0x%04X",
                        TARGETING::get_huid(l_dimm),
                        le16toh(curVersion), le16toh(lidVersion));
                }
                else
                {
                    TRACFCOMP(g_trac_nvdimm_upd, "NVDIMM[%X] has invalid version",
                        TARGETING::get_huid(l_dimm));
                }
            }
            else
            {
                TRACFCOMP(g_trac_nvdimm_upd,
                    "Keeping current NVDIMM[%X] level: 0x%04X",
                    TARGETING::get_huid(l_dimm), le16toh(curVersion));
            }
        }
    } while (0);

    return l_err;
}

////////////////////////////////////////////////////////////////////////////////
// External function to update the NVDIMMs
////////////////////////////////////////////////////////////////////////////////
bool nvdimm_update(TARGETING::TargetHandleList &i_nvdimmList)
{
    NvdimmsUpdate l_nvdimmsUpdate(i_nvdimmList);
    return l_nvdimmsUpdate.runUpdate();
}

}; // end namespace NVDIMM
