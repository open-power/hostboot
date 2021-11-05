/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbe/sbe_update.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
/**
 *  @file sbe_update.H
 *
 *  SBE common update header
 *
 */

#ifndef __SBE_SBE_UPDATE_H
#define __SBE_SBE_UPDATE_H

#include <sbe/sbe_common.H> // sbeSeepromVersionInfo_t

#include <stdint.h>                   // uint32_t, etc
#include <errl/errlentry.H>           // errlHndl_t
#include <errl/hberrltypes.H>         // ERRORLOG::errlSeverity_t
#include <targeting/common/target.H>  // Target
#include <eeprom/eepromif.H>          // EEPROM_ROLE
#include <pnor/ecc.H>                 // PNOR::ECC::eccStatus
#include <util/utilxipimage.H>        // Util::imageBuild_t
#include <vector>
#include <p10_infrastruct_help.H>     // XIPC_RING_BUF{1,2,3}_SIZE
#include <p10_ipl_image.H>            // p9_xip_section_sbe_t
#include <securerom/sha512.H>         // SHA512_t

namespace SBE
{
    // This line forces a compile fail if the two imageBuild_t deviate
    static_assert(sizeof(SBE::imageBuild_t) == sizeof(Util::imageBuild_t),
     "SBE::imageBuild_t and Util::imageBuild_t must be equivalent and in sync");

    // Situation constants -- bits numbered from left to right
#ifndef CONFIG_SBE_UPDATE_CONSECUTIVE
    const uint8_t SITUATION_ALL_BITS_MASK = 0xE0;
#else
    const uint8_t SITUATION_ALL_BITS_MASK = 0x0E;
#endif
    // Bit 0: current side is permanent (=0) or temp (=1)
    const uint8_t SITUATION_CUR_IS_PERM   = 0x00;
    const uint8_t SITUATION_CUR_IS_TEMP   = 0x80;

    // Bit 1:  current_side clean (=0) or dirty (=1)
    const uint8_t SITUATION_CUR_IS_CLEAN  = 0x00;
    const uint8_t SITUATION_CUR_IS_DIRTY  = 0x40;

    // Bit 2:  alt side clean (=0) or dirty (=1)
    const uint8_t SITUATION_ALT_IS_CLEAN  = 0x00;
    const uint8_t SITUATION_ALT_IS_DIRTY  = 0x20;

    // Bit 4:  side 0 clean (=0) or dirty (=1)
    const uint8_t SITUATION_SIDE_0_CLEAN  = 0x00;
    const uint8_t SITUATION_SIDE_0_DIRTY  = 0x08;

    // Bit 5:  side 1 clean (=0) or dirty (=1)
    const uint8_t SITUATION_SIDE_1_CLEAN  = 0x00;
    const uint8_t SITUATION_SIDE_1_DIRTY  = 0x04;

    // Bit 6:  boot side is side 0 (=0) or side 1 (=1)
    const uint8_t SITUATION_BOOT_SIDE_0   = 0x00;
    const uint8_t SITUATION_BOOT_SIDE_1   = 0x02;

    // For mbox messages to FSP
    const uint32_t MSG_IPL_DUE_TO_SBE_UPDATE         = 0x40000012;
    const uint32_t MSG_IPL_MASTER_CORE               = 0x40000005;
    const uint32_t MSG_KEY_TRANSITION_EVENT_OCCURRED = 0x40000017;

    /******************************************/
    /*  Enums                                 */
    /******************************************/
    // SBE VADDR Layout
    // 000K - 512K  = Dest for SEEPROM SBE image
    //
    //  512K - 1146K  = Ring buf1
    // 1146K - 1780K  = Ring buf2
    // 1780K - 2414K  = Ring buf3
    // 2414K - 3048K  = Ring Section buf
    // ---- Use 512K-3048K for SBE ECC image
    // 3048K - 3560K  = SBE + HBBL image
    enum {
        FIXED_SEEPROM_WORK_SPACE = 512 * 1024,
        SBE_IMG_VADDR = VMM_VADDR_SBE_UPDATE, // 3G address
        RING_BUF1_VADDR = FIXED_SEEPROM_WORK_SPACE + SBE_IMG_VADDR,
        RING_BUF2_VADDR = RING_BUF1_VADDR + XIPC_RING_BUF1_SIZE,
        RING_BUF3_VADDR = RING_BUF2_VADDR + XIPC_RING_BUF2_SIZE,
        RING_SEC_VADDR  = RING_BUF3_VADDR + XIPC_RING_BUF3_SIZE,
        //NOTE: recycling the same memory space for different
        //steps in the process.
        SBE_ECC_IMG_VADDR = RING_BUF1_VADDR,
        // for every 8 bytes of data use 1 byte for ECC = 9 bytes
        // then take that result of the space needed to store ECC data
        // and multiply by 8 bytes to know max data for ECC storage
        // a 256 byte area left at tail for comfort
        SBE_ECC_IMG_MAX_SIZE =
        (/*MAX_SEEPROM_IMAGE_SIZE*/ (PHYS_CHIPS_PER_LOGICAL_SEEPROM * (SBE_SEEPROM_SIZE / 9 * 8)) - 256) +
                               ((PHYS_CHIPS_PER_LOGICAL_SEEPROM-1) * SBE_SEEPROM_ECC_PAD),
        // to keep physical to logical algorithm above, put the unused ECC space
        // calculated for each physical chip back into the calculation to allow
        // logical jump of offsets from physical chip to physical chip
        SBE_HBBL_IMG_VADDR = RING_SEC_VADDR + FIXED_SEEPROM_WORK_SPACE,
    };

    // Used for MVPD function
    enum opType_t
    {
        MVPDOP_UNKNOWN,   // Invalid
        MVPDOP_READ,      // Read version data from MVPD
        MVPDOP_WRITE,     // Write version data to MVPD
    };

    // Used to keep track of Boot Seeprom perm/temp, and cur/alt
    enum sbeSeepromSide_t
    {
        SBE_SEEPROM0         = 0x00,   // corresponds to EEPROM::SBE_PRIMARY
        SBE_SEEPROM1         = 0x01,   // corresponds to EEPROM::SBE_BACKUP
        SBE_SEEPROM_INVALID  = 0xFF,
    };

    // Used to keep track of Measurement Seeprom side
    enum sbeMeasurementSeepromSide_t
    {
        SBE_MEASUREMENT_SEEPROM0         = 0x00,
        SBE_MEASUREMENT_SEEPROM1         = 0x01,
        SBE_MEASUREMENT_SEEPROM_INVALID  = 0xFF,
    };

    // Actions can be combined
    enum sbeUpdateActions_t
    {
        CLEAR_ACTIONS          = 0x00000000,
        DO_UPDATE              = 0x00000001,
        IPL_RESTART            = 0x00000002,
        UPDATE_MVPD            = 0x00000004,
        MVPD_UPDATE_COMPLETE   = 0x00000008,
        UPDATE_SBE             = 0x00000010,
        SBE_UPDATE_COMPLETE    = 0x00000020,
        UNSUPPORTED_SITUATION  = 0x80000000,
    };

    // Used for modifySbeSection() function
    enum modifyType_t : uint8_t
    {
        NO_MODIFY                  = 0x00,
        DELETE_SECTION             = 0x01,
        APPEND_SECTION             = 0x02,
        DELETE_AND_APPEND_SECTION  = DELETE_SECTION | APPEND_SECTION,
    };


    /**
     * @brief Contains the SBE state for a given target
     */
    struct sbeTargetState_t
    {

        // Target Information
        TARGETING::Target*       target;
        bool                     target_is_master;
        uint8_t                  ec;

        // Current Target SBE State Information
        sbe_image_version_t      pnorVersion;
        mvpdSbKeyword_t          mvpdSbKeyword;

        sbeSeepromVersionInfo_t  seeprom_0_ver;
        sbeSeepromVersionInfo_t  seeprom_1_ver;

        bool                     seeprom_0_ver_ECC_fail;
        bool                     seeprom_1_ver_ECC_fail;

        sbeSeepromSide_t         cur_seeprom_side; // aka 'booted' side
        sbeSeepromSide_t         alt_seeprom_side;
        sbeSeepromSide_t         permanent_seeprom_side;

        // Customized Image Information for this Target
        size_t                   customizedImage_size;
        uint32_t                 customizedImage_crc;

        // Update Fields and New Fields to be Written to the Target
        sbeUpdateActions_t            update_actions;
        EEPROM::EEPROM_ROLE   seeprom_side_to_update;

        sbeSeepromVersionInfo_t       new_seeprom_ver;
        bool                          new_readBack_check;
        Util::imageBuild_t            new_imageBuild;

        uint32_t                      err_plid;
        uint32_t                      err_eid;
        uint16_t                      err_rc;
        ERRORLOG::errlSeverity_t      err_sev;

        // Constructor to default certain values
        sbeTargetState_t() :
          target(NULL), target_is_master(false), ec(0x0),
          seeprom_0_ver_ECC_fail(false), seeprom_1_ver_ECC_fail(false),
          customizedImage_size(0x0), customizedImage_crc(0x0),
          new_readBack_check(false),
          err_plid(0x0), err_eid(0x0), err_rc(0x0),
          err_sev(ERRORLOG::ERRL_SEV_UNKNOWN)
        {};
    };

    /**
     * @brief Layout of P9_XIP_SECTION_SBE_SB_SETTINGS section in the SBE
     *
     * @note  This could eventually be replaced by a define in SBE code
     */
    struct sbeSectionSbSettings_t
    {
        SHA512_t hw_keys_hash = {0};            // 64 bytes
        uint8_t minimum_secure_version = 0;     // 1 byte
        uint8_t reserved[7] = {0,0,0,0,0,0,0};  // 7 bytes - used to keep 8-byte alignment
    } PACKED;

    // Catch if the struct is ever not 8-byte aligned
    static_assert(0 == (sizeof(sbeSectionSbSettings_t) % 8),
                  "sbeSectionSbSettings_t is not 8-byte-aligned");

    /******************************************/
    /*  Functions -- High Level Functions     */
    /******************************************/

    /**
     * @brief Collects SBE Information for a specifc target
     *
     * @param[io/out] io_sbeState   Struct containing SBE State of the target
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t getSbeInfoState(sbeTargetState_t& io_sbeState);

    /**
     * @brief Analyze and Determine Update Actions for a specific target
     *
     * @param[io/out] io_sbeState   Struct containing SBE State of the target
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t getTargetUpdateActions(sbeTargetState_t& io_sbeState);

    /**
     * @brief Performs the Update Actions for a specific target
     *
     * @param[io/out] io_sbeState   Struct containing SBE State of the target
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t performUpdateActions(sbeTargetState_t& io_sbeState);


    /******************************************/
    /*  Functions -- System Access            */
    /******************************************/

    /**
     * @brief Read or Write SB Keyword in MVPD
     *
     * @param[in] i_target   Target processor
     *
     * @param[in] i_op      Indicates read or write
     *
     * @param[io/out] io_sb_keyword  Pointer to MVPD SBE Keyword struct
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t getSetMVPDVersion(TARGETING::Target* i_target,
                                 opType_t i_op,
                                 mvpdSbKeyword_t& io_sb_keyword);


    /**
     * @brief Read SBE Version from PNOR
     *
     * @param[in] i_pnorImgHdrPtr Pointer to Image Header in PNOR
     *
     * @param[out] o_version      Pointer to SBE Version struct
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t readPNORVersion(void*& i_pnorImgHdrPtr,
                               sbe_image_version_t& o_version);

    /**
     * @brief Modify (Delete and/or Append) Section of SBE Image
     *
     * @param[ini] i_section             Enum defining which section to modify
     *
     * @param[in] i_modify_type          Enum defining the action(s) to take on the section
     *
     * @param[in] i_section_ptr          Pointer to SBE Section to append
     *                                   Fail if nullptr on append operation
     *
     * @param[in] i_section_size         Size of SBE Section
     *
     * @param[in] i_sbe_image            Pointer to SBE image in memory (non-ecc)
     *
     * @param[in/out] io_sbe_image_size  in: space available for enlarged XIP image
     *                                   out: size of enlarged XIP image
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t modifySbeSection(p9_xip_section_sbe_t i_section,
                                modifyType_t i_modify_type,
                                void*     i_section_ptr,
                                uint32_t  i_section_size,
                                void*     i_image,
                                uint32_t& io_image_size);

    /**
     * @brief Customize SBE Image for current Processor
     *
     * @param[in] i_target      Target processor to customize
     *
     * @param[in] i_sbeImgPtr   Pointer to SBE Image with HBBL appended
     *                          Expected that this pointer points to memory
     *                          where the SBE Image in PNOR was copied and
     *                          the HBBL Image in PNOR was appended
     *
     * @param[in] i_maxImgSize  Maximum size of customized image
     *
     * @param[out] io_imgPtr    Pointer to SBE image in memory
     *                          Memory from this pointer through
     *                          i_maxImgSize is expected to be pre-allocated
     *
     * @param[out] o_actImgSize  Actual size of the customized image
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t procCustomizeSbeImg(TARGETING::Target* i_target,
                                   void* i_hwImgPtr,
                                   void* i_sbeImgPtr,
                                   size_t i_maxImgSize,
                                   void* io_imgPtr,
                                   size_t& o_actImgSize);

    /**
     * @brief Determines which Seeprom was used to boot the SBE
     *
     * @param[in] i_target      Target processor to customize.
     *
     * @param[out] o_bootSide   The Boot Seeprom the SBE booted from
     *
     * @param[out] o_mSide         The Measurement Seeprom the SBE booted from
     *
     * @return errlHndl_t       Error log handle on failure.
     */
    errlHndl_t getSbeBootSeeprom(TARGETING::Target* i_target,
                                 sbeSeepromSide_t& o_bootSide,
                                 sbeMeasurementSeepromSide_t& o_mSide);

    /**
     * @brief Collects Version information from a specific SEEPROM using SPI
     *
     * @param[in] i_target      Target processor to customize
     *
     * @param[in] i_seepromSide The SEEPROM on the target that to collect
     *                          the information from
     *
     * @param[out] o_info       Struct containing the SBE Version Information
     *
     * @param[out] o_seeprom_ver_ECC_fail Reports if there was an ECC error on
     *                                    the collected information
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t getSeepromSideVersionViaSPI(TARGETING::Target* i_target,
                                     EEPROM::EEPROM_ROLE i_seepromSide,
                                     sbeSeepromVersionInfo_t& o_info,
                                     bool& o_seeprom_ver_ECC_fail);
    /**
     * @brief Collects Version information from a specific SEEPROM using PSU ChipOp
     *
     * @param[in] i_target        Target processor to customize
     *
     * @param[out] o_info         Struct containing the SBE Version Information
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t getSeepromSideVersionViaChipOp(TARGETING::Target* i_target,
                                     sbeSeepromVersionInfo_t& o_info);

    /**
     * @brief Updates a specific SEEPROM
     *
     * @param[io/out] io_sbeState   Struct containing SBE State of the target
     *                              and the information to be used for updating
     *                              the SBE State of the target
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t updateSeepromSide(sbeTargetState_t& io_sbeState);

    /**
     * @brief Check and Update all targets before Re-IPL Request
     *
     * @param[io/out] io_sbeStates_v   Vector of SBE State structs
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t preReIplCheck(std::vector<sbeTargetState_t>& io_sbeStates_v);


    /******************************************/
    /*  Functions -- Helper Functions         */
    /******************************************/

    /**
     * @brief Send Mailbox msg to FSP to query if this IPL came from
     *        SBE Update Re-Ipl Request
     *
     * @return  bool    If true, this IPL was from a Hostboot re-IPL request
     */
    bool isIplFromReIplRequest(void);

    /**
     * @brief Determines the Update Actions for a specific target situation
     *
     * @param[io/out] io_sbeState   Struct containing SBE State of the target
     *                              and is updated based on the situation
     *
     * @param[in] i_system_situation SBE Situation of the target that requires
     *                               analysis to determine Update Actions
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t decisionTreeForUpdates(sbeTargetState_t& io_sbeState,
                                      uint8_t i_system_situation);



    /**
     * @brief Provides the decisionTreeForUpdates() functionality in the
     *        case that both sides of the SBE should be updated
     *        simultaneously.
     *
     * @param[io/out] io_actions   SBE Update actions required for the target
     *
     * @param[io/out] io_sbeState   Struct containing SBE State of the target
     *                              and is updated based on the situation
     *
     * @param[in] i_system_situation SBE Situation of the target that requires
     *                               analysis to determine Update Actions
     *
     */
    void decisionTreeForUpdatesSimultaneous(uint32_t& io_actions,
                                            sbeTargetState_t& io_sbeState,
                                            uint8_t& i_system_situation );

    /**
     * @brief Deconfigures any Targets whose version does not match the
     *        Master Target's Version
     *
     * @pre   All planned updates must have been completed
     *
     * @param[io/out] io_sbeStates_v   Vector of SBE State structs
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t masterVersionCompare(
                     std::vector<sbeTargetState_t>& io_sbeStates_v);

    /**
     * @brief Creates the memory space needed for SBE Image Customization
     *        by allocating and setting permissions on VMM_VADDR_SBE_UPDATE
     *        area defined in vmmconst.H
     *
     * @param[in]   void
     *
     * @return      void
     */
    errlHndl_t createSbeImageVmmSpace(void);

    /**
     * @brief Cleans up memory space needed for SBE Image Customization
     *
     * @param[in]   void
     *
     * @return      void
     */
    errlHndl_t cleanupSbeImageVmmSpace(void);


    /**
     * @brief Select best cores to include in SBE Image.
     *        The output is used to indicate to the image customization procedures
     *        which cores should be included in the SBE image.
     *
     * @param[in] i_target   Target processor to use for core selection
     *
     * @param[in] i_maxCores  Maximum number of cores to select for inclusion
     *                        in the SBE Image
     *
     * @param[out] o_coreMask  Core Mask for the target that does not exceed
     *                         the maximum number of cores
     *                         NOTE: bits 0:31 = EC00:EC31
     *                         This value is used as input into
     *                         the image customization procedures.
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t selectBestCores(TARGETING::Target* i_target,
                               size_t i_maxCores,
                               uint32_t& o_coreMask);


    /**
     * @brief Reduces bits set in a bit mask until there is a
     *        a maximum number of bits set.
     *        NOTE: bits removed left-to-right
     *
     * @param[in] i_mask      Starting mask to be reduced
     *
     * @param[in] i_maxBits   Maximum number of bits that the
     *                        returned Bit Mask can contain
     *
     * @return uint32_t       Bit Mask
     */
    uint32_t trimBitMask(uint32_t i_mask,
                         size_t i_maxBits);


    /**
     * @brief Calculates ECC size for a block of code or data allowing for
     *        padding at chip boundaries so 9-byte segment (8 bytes of code
     *        or data and 1 byte of ECC) does not straddle the boundary.
     *
     * @param[in]  i_srcSz    Size of source (code or data)
     *
     * @param[in]  i_offset   Offset into device for storing destination
     *
     * @param[in]  i_boundary Chip boundary
     *
     * @return Size of source (code or data) with ECC and padding
     */
    size_t setECCSize(size_t i_srcSz,
                      const uint64_t i_offset = SBE_IMAGE_SEEPROM_ADDRESS,
                      const uint64_t i_boundary = SBE_SEEPROM_SIZE);


    /**
     * @brief Injects ECC into a block of code or data.  Pads output at chip
     *        boundaries so 9-byte segment (8 bytes of code or data and 1 byte
     *        of ECC) does not straddle the boundary.
     *
     * @param[in]  i_src      Location of source (code or data) without ECC
     *
     * @param[in]  i_srcSz    Size of source (code or data)
     *
     * @param[in]  i_offset   Offset into device for storing destination
     *
     * @param[in]  i_boundary Chip boundary within the device
     *
     * @param[out] o_dst      Location of destination (code or data) with ECC
     *
     * @return void
     */
    void injectECC(const uint8_t* i_src,
                   size_t i_srcSz,
                   const uint64_t i_offset,
                   const uint64_t i_boundary,
                   uint8_t* o_dst);

    /**
    * @brief Read the version of code found on each of the SBE's seeproms
    *        and store values in sbeTargetState_t type
    *
    * @param[in]  io_sbeState Struct holding SBE related information
    * @pre        it is expected that the member 'target' in the
    *             sbeTargetState_t struct is set prior to calling this function
    * @note       members 'seeprom_0_ver' and 'seeprom_1_ver' in sbeTargetState_t
    *             are defaulted to all zero at start of the function
    *
    * @return errlHndl_t if error, nullptr if no error
    */
    errlHndl_t getSeepromVersions(sbeTargetState_t& io_sbeState);


    /**
     * @brief Removes ECC from a block of code or data.  Removes padding at
     *        chip boundaries where 9-byte segment (8 bytes of code or data
     *        and 1 byte of ECC) was moved to next chip so as to not straddle
     *        the boundary.
     *
     * @param[in/out] io_src  Location of source (code or data) with ECC
     *
     * @param[out] o_dst      Location of destination (code or data) without ECC
     *
     * @param[in]  i_dstSz    Size of destination (code or data)
     *
     * @param[in]  i_offset   Offset into device where source was stored
     *
     * @param[in]  i_boundary Chip boundary
     *
     * @return     eccStatus  ECC status from removing ECC.
     */
    PNOR::ECC::eccStatus removeECC(uint8_t* io_src,
                                   uint8_t* o_dst,
                                   size_t i_dstSz,
                                   const uint64_t i_offset,
                                   const uint64_t i_boundary);

    /**
     * @brief Add ring overrides to SBE image if present in PNOR partition
     *
     * @param[out] io_imgPtr      Pointer to current SBE image in memory
     *                            Memory from this pointer through io_actImgSize
     *                            is expected to be pre-allocated
     *
     * @param[out] io_actImgSize   Max size as input, actual size of the
     *                            customized image as output
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t ringOvd(void *io_imgPtr,
                       uint32_t & io_ovdImgSize);

    /**
     * @brief Performs any necessary actions and then reboot the system
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t sbeDoReboot( void );

    /**
     * @brief Checks if a secure key transition is needed and if so verifies
     *        the key transition container is valid. Then gets the new hw keys'
     *        hash and sets the global hash transition data variables.
     *
     * @return errlHndl_t    Error log handle on failure. NULL on success
     */
    errlHndl_t secureKeyTransition();

    /**
     * @brief locate the hbbl ID string buffer
     *
     * @param[in] i_pSourceBfr         Ptr to buffer to search
     *
     * @param[in] i_SourceBfrSize      length (in bytes) of source buffer
     *
     * @param[out] o_pHbblIdStringBfr  Ptr to Hbbl ID String
     *                                   NULL if not found
     *
     * @return errlHndl_t              Error log handle on failure.
     */
    errlHndl_t locateHbblIdStringBfr( void * i_pSourceBfr,
                                      uint32_t i_SourceBfrLen,
                                      void * & o_pHbblIdStringBfr );

    /**
     *  @brief Updates the key transition state for the node
     *
     *  @par Detailed Description:
     *      Updates the specified key transition state for the node and sends a
     *      synchronous key transition state change alert to FSP (if
     *      applicable).
     *
     *  @param[in] i_keyTransitionState Key transition state to update
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr Successfully updated node key transition state and
     *      sent the new key transition state to FSP
     *  @retval !nullptr Failed to send new key transition state to FSP
     */
    errlHndl_t updateKeyTransitionState(
        TARGETING::KEY_TRANSITION_STATE i_keyTransitionState);

} //end namespace SBE
#endif
