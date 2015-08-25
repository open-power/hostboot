/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbe/sbe_resolve_sides.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef __SBE_SBE_RESOLVE_SIDES_H
#define __SBE_SBE_RESOLVE_SIDES_H


#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <pnor/pnorif.H>
#include <util/align.H>
#include <vmmconst.h>
#include <targeting/common/targetservice.H>
#include <i2c/eepromif.H>
#include "sbe_update.H"

namespace SBE
{
    /******************************************/
    /*  Constants                             */
    /******************************************/

    // This seeprom is a candidate to be READ_ONLY (ie, not updated)
    const sbeSeepromSide_t READ_ONLY_SEEPROM = SBE_SEEPROM1;

    // Used to keep SBE Seeproms in sync with EEPROM::eeprom_chip_types_t
    const EEPROM::eeprom_chip_types_t sbe_side_sync[2] =
                                      { EEPROM::SBE_PRIMARY,
                                        EEPROM::SBE_BACKUP };

    // @todo RTC 124679 - Remove Once BMC Monitors Shutdown Attention
    // Set Watchdog Timer To 15 seconds before calling doShutdown()
    const uint16_t SET_WD_TIMER_IN_SECS = 15;

    /******************************************/
    /*  Enums                                 */
    /******************************************/

    // Actions can be combined
    enum
    {
        NO_ACTIONS             = 0x00000000,
        REIPL                  = 0x00000001,

        // Use PNOR::ALTERNATE SideId for HBB Address info
        USE_PNOR_ALT_SIDE      = 0x00000002,

        // NOTE: These next 2 values are mutually exclusive
        CHECK_WORKING_HBB         = 0x00000010,
        COPY_READ_ONLY_TO_WORKING = 0x00000020,
    };

    /******************************************/
    /*  Structs                               */
    /******************************************/
    struct sbeResolveState_t
    {

        // Target Information
        TARGETING::Target*       tgt;

        sbeSeepromSide_t   cur_side;    // aka 'booted' side
        sbeSeepromSide_t   alt_side;    // non-booted/non-cur side
        sbeSeepromSide_t   update_side; // side to be updated

        // Info from PNOR
        PNOR::SideId pnor_sideId;
        char pnor_side;          /**< name of the side either A or B */
        bool pnor_isGolden;      /**< True if side is golden */
        bool pnor_hasOtherSide;  /**< True if a valid alternate side exists*/

        uint32_t actions;

        // Constructor to default certain values
        sbeResolveState_t() :
          tgt(NULL), cur_side(SBE_SEEPROM_INVALID),
          alt_side(SBE_SEEPROM_INVALID),
          update_side(SBE_SEEPROM_INVALID),
          pnor_sideId(PNOR::WORKING),
          pnor_side(NULL),
          pnor_isGolden(false), pnor_hasOtherSide(false),
          actions(NO_ACTIONS)
        {}

    };


    /******************************************/
    /*  Functions -- High Level Functions     */
    /******************************************/

    /**
     * @brief Collects SBE Side Information for a specifc target
     *
     * @param[io/out] io_sideState   Struct containing SBE State of the target
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t getSideState(sbeResolveState_t& io_sideState);

    /**
     * @brief Analyze and Determine Update Actions for a specific target
     *
     * @param[io/out] io_sideState   Struct containing SBE State of the target
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t getSideActions(sbeResolveState_t& io_sideState);

    /**
     * @brief Performs the Update Actions for a specific target
     *
     * @param[io/out] io_sideState   Struct containing SBE State of the target
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t performSideActions(sbeResolveState_t& io_sideState);



    /******************************************/
    /*  Functions -- System Access            */
    /******************************************/


    /**
     * @brief Read SBE Image from SBE Seeprom
     *
     * @param[in] i_target   Target processor
     *
     * @param[out] o_imgPtr    Pointer to SBE image in memory
     *                         Memory for this pointer is expected to be
     *                         pre-alloacted
     *                         NOTE:  ECC is handled internally in this
     *                         function. io_imgPtr points to non-ECC image
     *
     * @param[in] i_side          Seeprom Side to access
     *
     * @param[in] o_image_size    The size of the image (non-ECC)
     *                            NOTE: o_image_size will be 8 byte aligned.
     *
     * @param[in] o_version       SBE Version struct from seeprom (non-ECC)
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t readSbeImage(TARGETING::Target* i_target,
                              void* o_imgPtr,
                              sbeSeepromSide_t i_side,
                              size_t& o_image_size,
                              sbeSeepromVersionInfo_t& o_version);

    /**
     * @brief Write SBE Image from SBE Seeprom
     *
     * @param[in] i_target   Target processor
     *
     * @param[in] i_imgPtr    Pointer to SBE image in memory
     *                        Memory for this pointer is expected to be
     *                        pre-alloacted
     *                        NOTE:  ECC is handled internally in this function,
     *                        i_imgPtr points to non-ECC image
     *
     * @param[in] i_side        Seeprom Side to access
     *
     * @param[in] i_image_size  Size of image to write (non-ECC)
     *                          NOTE: must be 8 byte aligned
     *
     * @param[in] io_version    SBE Version struct to write (non-ECC)
     *                          NOTE: data_crc updated in this function
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t writeSbeImage(TARGETING::Target* i_target,
                             void* i_imgPtr,
                             sbeSeepromSide_t i_side,
                             size_t i_image_size,
                             sbeSeepromVersionInfo_t& io_version);

    /**
     * @brief Read SBE Image Header from SBE Seeprom and gets the
     *        Image size from the heaser
     *
     * @param[in] i_target   Target processor
     *
     * @param[out] i_imgPtr    Pointer to pre-allocated memory to be used
     *                         for different operations
     *
     * @param[in] i_side          Seeprom Side to access
     *
     * @param[in] o_image_size    The size of the image (non-ECC)
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t getSbeImageSize(TARGETING::Target* i_target,
                               void* i_imgPtr,
                               sbeSeepromSide_t i_side,
                               size_t& o_image_size);




    /******************************************/
    /*  Functions -- Helper Functions         */
    /******************************************/

    /**
     * @brief Check and Update (if necessary) the HBB Address MMIO offset
     *        in a customized SBE Image for the current Processor
     *
     * @param[in] i_target      Target processor to customize
     *
     * @param[in/out] io_imgPtr    Pointer to SBE image in memory
     *                          Memory for this pointer is expected to be
     *                          pre-alloacted
     *
     * @param[in] i_side          Seeprom Side to access
     *
     * @param[in] i_pnorSideId    PNOR side to get information for
     *
     * @param[out] o_imageWasUpdated  Set to true if Image was updated;
     *                                otherwise false
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t resolveImageHBBaddr(TARGETING::Target* i_target,
                                   void* io_imgPtr,
                                   sbeSeepromSide_t i_side,
                                   PNOR::SideId i_pnorSideId,
                                   bool& o_imageWasUpdated);

#ifdef CONFIG_BMC_IPMI
    /**
     * @brief Performs any necessary IPMI calls before shutting down the system
     *
     * @return void       Any generated Error Logs will be commited before the
     *                    function returns
     */
    void sbePreShutdownIpmiCalls( void );
#endif

} //end namespace SBE
#endif
