/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimm_update.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef NVDIMM_UPDATE_H
#define NVDIMM_UPDATE_H

/**
 *  @file nvdimm/nvdimm_update.H
 *
 *  @brief  Interface to support updating NVDIMM controller code
 */

#include <cstdint>
#include <errl/errlentry.H>


namespace NVDIMM
{
// Some invalid constants
const uint16_t INVALID_ID       = 0xFFFF;
const uint16_t INVALID_VERSION  = 0xFFFF;
const uint16_t INVALID_TIMEOUT  = 0xFFFF;
const uint32_t INVALID_TYPE     = 0xFFFFFFFF;

// Type is combination of manufacturer id and product id
const uint32_t SMART_NVDIMM_16GB_TYPE = 0x01945377;
const uint32_t SMART_NVDIMM_32GB_TYPE = 0x01945378;

// LID IDs for each NV controller type
const uint32_t NVDIMM_SIGNATURE_LIDID = 0x80D00025; // ignore this one

// These LIDs are created from these two binaries supplied by SMART
// 16GB image -> src/extucode/NVDIDMM_SRN7A2G4IBM26MP1SC.bin --> 81e00640.lid
// 32GB image -> src/extucode/NVDIDMM_SRN7A4G4IBM24KP2SB.bin --> 81e00641.lid
const uint32_t NVDIMM_16GB_LIDID = 0x81e00640;
const uint32_t NVDIMM_32GB_LIDID = 0x81e00641;


// Firmware Update Mode settings for FIRMWARE_OPS_CMD
enum fw_update_mode : uint8_t
{
    FW_UPDATE_MODE_DISABLED = 0x00,
    FW_UPDATE_MODE_ENABLED = 0x01,
};

class NvdimmLidImage
{
  public:
    /**
     * @brief Constructor that sets access to LID information
     * @param i_lidImageAddr - virtual address where LID was loaded
     * @param i_size - size of the loaded LID
     */
    explicit NvdimmLidImage(const void * i_lidImageAddr, size_t i_size);

    /**
     * @brief Grab the type of the image
     *        (The type will be in raw little-endian format)
     * @return concated manufacturer id and product id
     *         module_mnfg_id_code (0-1) and module_product_id (2-3)
     */
    uint32_t getType();

    /**
     * @brief Get the firmware version of image
     * @return o_version - version of the image in raw little-endian format
     */
    uint16_t getVersion();

    /**
     *  @brief Get the actual NVDIMM flash image to load on the NVDIMM
     *  @return Pointer to the start of the flash image
     */
    const void * getFlashImage();

    /**
     * @brief  Get the size of the actual flash image
     * @return Image size
     */
    size_t getFlashImageSize();


    //-----------------------------------------------------------//
    // Layout of NVDIMM lid image
    //
    // Keeping as struct so it can be overlayed on lid image
    // Note: the multiple byte variables will be in little-endian
    //-----------------------------------------------------------//
    // Header of NVDIMM lid image
    typedef struct nvdimm_image_header
    {
      // Byte 0-1 - 1st part of type
      uint16_t module_mnfg_id_code;
      // Byte 2-3 - 2nd part of type
      uint16_t module_product_id;
      // Byte 4-5
      uint16_t nv_memory_subsys_cntrlr_mnfg_id_code;
      // Byte 6-7
      uint16_t nv_memory_subsys_cntrlr_product_id;
      // Byte 8
      uint8_t  module_revision_code;
      // Byte 9
      uint8_t  nv_memory_subsys_cntrlr_revision_code;
      // Byte 10-11 - this version of code for update
      uint16_t controller_firmware_revision;
      // Byte 12-13
      uint16_t energy_source_firmware_revision;
      // Byte 14
      uint8_t  subcomponent_firmware_revision;
      // Byte 15
      uint8_t  rsvd_0;
      // Byte 16-17
      uint16_t SMART_digital_signature_size;
      // Byte 18
      uint8_t  SMART_digital_signature_type;
      // Byte 19
      union
      {
        uint8_t _valid;
        struct
        {
          uint8_t _subcomponent_firmware_revision:1;          // bit7 in spec
          uint8_t _energy_source_firmware_revision:1;         // bit6
          uint8_t _nv_memory_subsys_cntrlr_revision_code:1;   // bit5
          uint8_t _module_revision_code:1;                    // bit4
          uint8_t _nv_memory_subsys_cntrlr_product_id:1;      // bit3
          uint8_t _nv_memory_subsys_cntrlr_mnfg_id_code:1;    // bit2
          uint8_t _module_mnfg_product_id:1;                  // bit1
          uint8_t _module_mnfg_id:1;                          // bit0 in spec
        } PACKED;
      };

      // Byte 20-23
      uint32_t firmware_image_size; // Includes 32-byte header + actual fw image
                                    // Byte 20 LSB, Byte 23 MSB
      // Byte 24-25
      uint16_t firmware_image_checksum;
      // Byte 26-30
      uint8_t  rsvd_1[5];
      // Byte 31
      uint8_t  firmware_image_format;
    } nvdimm_image_header_t;
    // After header, these two follow:
    // Digital signature (size: SMART_digital_signature_size bytes)
    // Actual flash firmware image
    // (size: firmware_image_size bytes - 32-byte header)
    //-----------------------------------------------------------//

    /**
     * @brief Get a pointer to the header and smart digital signature
     * @param o_size Byte size of the data being returned
     * @return Pointer to 32-byte header + digital signature
     */
    const uint8_t * getHeaderAndSmartSignature(uint16_t & o_size);

  private:
    // force user to supply loaded image addr/size
    NvdimmLidImage();

    // pointer to lid image
    // note: memory is allocated outside of this class,
    // should be left alone
    const void * iv_lidImage;

    // size of lid image
    size_t iv_lidImageSize;
};


class NvdimmInstalledImage
{
  public:
    /**
     * @brief Constructor to associate a target DIMM to grab info from
     * @param i_nvDimm - NVDIMM target
     */
    explicit NvdimmInstalledImage(TARGETING::Target * i_nvDimm);

    /**
     * @brief Grab the type of the installed nvdimm
     *        (The type will be in raw little-endian format)
     * @param o_type - concated manufacturer id and product id
     * @return error if read operation fails
     */
    errlHndl_t getType(uint32_t & o_type);

    /**
     * @brief Grab the installed NVDIMM's version
     * @param o_version - version of installed NVDIMM image (little-endian format)
     * @param i_force_recollect - force hw calls to recollect version
     * @return error if read operation fails
     */
    errlHndl_t getVersion(uint16_t & o_version,
                          const bool i_force_recollect = false);

    /**
     * @brief Accessor to grab the current NVDIMM target
     * @return NVDIMM target
     */
    const TARGETING::Target * getNvdimmTarget(void)
    {
        return iv_dimm;
    }

    /**
     * @brief Update the current NV Controller
     * @param Update using this image
     * @return error pointer if failure to update, else nullptr
     */
    errlHndl_t updateImage(NvdimmLidImage * i_lidImage);

  private:
      // nvdimm target
      TARGETING::Target * iv_dimm;

      // little-endian version of installed nvdimm
      uint16_t iv_version;

      // Type contains these two concatentated little-endian IDs
      uint16_t iv_manufacturer_id;
      uint16_t iv_product_id;

      // timeout value (in seconds) for FIRMWARE_OPS_TIMEOUT0/1
      uint16_t iv_timeout;

      // constant for invalid setting
      const uint8_t INVALID_REGION_BLOCK_SIZE = 0x00;

      // maximum blocks allowed per region (REGION_BLOCK_SIZE)
      uint8_t iv_max_blocks_per_region;

      // Helper functions for updating the installed lid
      /**
       * @brief Transfer a region of bytes in multiple 32-byte blocks
       * @param i_data - data to transfer
       * @param i_data_size - size of the data to transfer
       * @param i_use_region_block_size - use the register REGION_BLOCK_SIZE
       *                                  as number of blocks to send
       * @return error if transfer fails, else nullptr
       */
      errlHndl_t byteRegionBlockTransfer(const uint8_t * i_data,
                                         const uint16_t i_data_size,
                                         bool i_use_region_block_size = true);

      /**
       * @brief NV controller calculate checksum of region of data bytes
       * @param o_nvCksm - NV calculated checksum
       * @return error if unable to get checksum, else nullptr
       */
      errlHndl_t calcAndGetCksm(uint16_t & o_nvCksm);

      /**
       * @brief Change the Firmware Update Mode
       * @param i_mode - enable or disable mode
       * @return error if unable to change mode, else nullptr
       */
      errlHndl_t changeFwUpdateMode(fw_update_mode i_mode);

      /**
       * @brief Clear the Firmware Data Block
       * @return error if unable to clear data block, else nullptr
       */
      errlHndl_t clearFwDataBlock();

      /**
       * @brief Clear the Firmware Operations Status
       * @return error if unable to clear status, else nullptr
       */
      errlHndl_t clearFwOpsStatus();

      /**
       * @brief Commit the Firmware Region Operation
       * @return error if unable commit, else nullptr
       */
      errlHndl_t commitFwRegion();

      /**
       * @brief Get the number of blocks per region
       * @param io_blocks_per_region - value of REGION_BLOCK_SIZE register
       * @return error if unable to get value, else nullptr
       */
      errlHndl_t getBlocksPerRegion(uint8_t & io_blocks_per_region);

      /**
       * @brief Get the Firmware Operations Timeout
       * @param o_timeout - timeout in seconds for a Firmware Operation
       *                    to complete
       * @return error if unable to get timeout value, else nullptr
       */
      errlHndl_t getFwOpsTimeout(uint16_t & o_timeout);

      /**
       * @brief Is the Firmware Operation successful?
       * @param o_success - true if FIRMWARE_OPS_STATUS reporting success
       * @return error if unable to read register, else nullptr
       */
      errlHndl_t isFwOpsSuccess(bool & o_success);

      /**
       * @brief Reset NV controller. Resets controller and waits for it to
       *        come back online
       * @return error if reset failed, else nullptr
       */
      errlHndl_t resetController();

      /**
       * @brief Updates the NV controller with the lid's image data
       *        (minus header and signature)
       * @param i_lidImage - lid object with image data
       * @return error if unable to update, else nullptr
       */
      errlHndl_t updateImageData(NvdimmLidImage * i_lidImage);

      /**
       * @brief Run FW operation to validate the header and verify
       *        it was a successful operation
       * @return error if unable to validate, else nullptr
       */
      errlHndl_t validateFwHeader();

      /**
       * @brief Run FW operation to validate the firmware image and verify
       *        it was a successful operation
       * @return error if unable to validate, else nullptr
       */
      errlHndl_t validateFwImage();

      /**
       * @brief Wait until FW operation is no longer in progress
       * @return error if failed i2c operation getting status or if
       *         timeout happened before status indicated operation completion,
       *         else nullptr
       */
      errlHndl_t waitFwOpsComplete();

      /**
       * @brief Wait until FW operation reports data block was received
       *        Polls FIRMWARE_OPS_STATUS offset for FIRMWARE_BLOCK_RECEIVED
       * @return error if failed i2c operation getting status or if
       *         timeout happened before status indicated operation completion,
       *         else nullptr
       */
      errlHndl_t waitFwOpsBlockReceived();

      /**
       * @brief Checksum calculation
       *        See JESD245B for documentation of this checksum
       * @param i_data - pointer to data
       * @param i_data_size - size of data being pointed too
       * @return checksum
       */
      uint16_t crc16(const uint8_t * i_data, int i_data_size);
};


class NvdimmsUpdate
{
  public:
    /**
     *  @brief Constructor that uses passed in nvdimm list
     *  @parm[in] i_nvdimmList List of NVDIMMs to update
     */
    explicit NvdimmsUpdate(TARGETING::TargetHandleList i_nvdimmList);

    /**
     *  @brief Main function that tries to update all NVDIMMs (if needed)
     *         This function runs SPD and lid loading/unloading, so should
     *         not be called multiple times
     *  @return true if no errors reported, else false
     */
    bool runUpdate(void);

  protected:
    /**
     *  @brief Checks if an update is needed for an individual nvdimm
     *  @param[out] o_update_needed -
     *      true -  lid image is good to update current image
     *      false - update not needed
     *  @param[in] i_lid_image - lid image that is appropriate for nvdimm update
     *  @param[in] i_cur_image - current installed image on the nvdimm
     *  @return error if failure during check, else false
     */
    errlHndl_t isUpdateNeeded(bool & o_update_needed,
                              NvdimmLidImage * i_lid_image,
                              NvdimmInstalledImage * i_cur_image);

    /**
     * @brief Update the list of NVDIMMs with the supplied LID image
     * @param[in] i_lidImage - LID image for update
     * @param[in] i_list - List of installed NVDIMMs to update
     * @return true if no errors reported, else false
     */
    bool runUpdateUsingLid(NvdimmLidImage * i_lidImage,
                           std::vector<NvdimmInstalledImage *> &i_list);

  private:
    // Force user to supply NVDIMM list
    NvdimmsUpdate();

    // List of NVDIMMs installed in system
    TARGETING::TargetHandleList iv_nvdimmList;

};

} // Namespace NVDIMM
#endif
