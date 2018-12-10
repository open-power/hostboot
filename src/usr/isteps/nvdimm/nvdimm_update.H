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
#include <util/utillidmgr.H>

namespace NVDIMM
{
// Some invalid constants
const uint16_t INVALID_ID       = 0xFFFF;
const uint16_t INVALID_VERSION  = 0xFFFF;
const uint32_t INVALID_TYPE     = 0xFFFFFFFF;

// Type is combination of manufacturer id and product id
const uint32_t JEDEC_NVDIMM_16GB_TYPE = 0x01945377;
const uint32_t JEDEC_NVDIMM_32GB_TYPE = 0x01945378;

class NvdimmLidImage
{
  public:
    /**
     * @brief Constructor that sets access to LID information
     * @param i_lidId - NVDIMM_16GB_LIDID or NVDIMM_32GB_LIDID
     * @param io_errHndl - error filled in if lid not loadable
     */
    explicit NvdimmLidImage(Util::LidId i_lidId, errlHndl_t& io_errHdl);

    /**
     *  @brief Cleanup any allocated memory holding the lid image
     */
    ~NvdimmLidImage();

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
    void * getFlashImage();

    /**
     * @brief  Get the size of the actual flash image
     * @return Image size
     */
    size_t getFlashImageSize();

    /**
     * @brief Check if the image was loaded into memory
     * @return true, if image was loaded into memory
     */
    bool isImageLoaded();


    //-----------------------------------------------------------//
    // Layout of NVDIMM lid image
    //
    // Keeping as struct so it can be overlayed on lid image
    // Note: the multiple byte variables will be in little-endian
    //-----------------------------------------------------------//
    // Header of NVDIMM lid image
    typedef struct nvdimm_image_header
    {
      // Byte 0-1
      uint16_t module_mnfg_id_code;
      // Byte 2-3
      uint16_t module_product_id;
      // Byte 4-5
      uint16_t nv_memory_subsys_cntrlr_mnfg_id_code;
      // Byte 6-7
      uint16_t nv_memory_subsys_cntrlr_product_id;
      // Byte 8
      uint8_t  module_revision_code;
      // Byte 9
      uint8_t  nv_memory_subsys_cntrlr_revision_code;
      // Byte 10-11
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
      uint8_t  SMART_digital_signature;
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

  private:
    /**
     *  @brief Load the lid image into memory
     */
    errlHndl_t loadImage();

    /**
     *  @brief Unload the lid image from memory
     */
    errlHndl_t unloadImage();

    // force user to supply lid_id
    NvdimmLidImage();

    // status of whether or not the image was loaded into memory
    bool iv_ImageLoaded;

    // pointer to lid image
    // note: memory allocated/deallocated by iv_lidMgr
    void * iv_lidImage;

    // size of lid image
    size_t iv_lidImageSize;

    // lid manager for nvdimm lid image
    UtilLidMgr* iv_lidMgr;
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
     * @param o_version - version of installed NVDIMM image
     * @return error if read operation fails
     */
    errlHndl_t getVersion(uint16_t & o_version);

    /**
     * @brief Accessor to grab the current NVDIMM target
     * @return NVDIMM target
     */
    const TARGETING::Target * getNvdimmTarget(void)
    {
        return iv_dimm;
    }

  private:
      // nvdimm target
      TARGETING::Target * iv_dimm;

      // little-endian version of installed nvdimm
      uint16_t iv_version;

      // Type contains these two concatentated little-endian IDs
      uint16_t iv_manufacturer_id;
      uint16_t iv_product_id;
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
     *  @param[out] o_update_needed - true if lid image is good to
     *                                update current image, else false
     *  @param[in] i_lid_image - lid image that is appropriate for nvdimm update
     *  @param[in] i_cur_image - current installed image on the nvdimm

     */
    errlHndl_t isUpdateNeeded(bool & o_update_needed,
                              NvdimmLidImage * i_lid_image,
                              NvdimmInstalledImage * i_cur_image);

  private:
    // Force user to supply NVDIMM list
    NvdimmsUpdate();

    // List of NVDIMMs installed in system
    TARGETING::TargetHandleList iv_nvdimmList;

};

} // Namespace NVDIMM
#endif
