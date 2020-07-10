/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbe/sbeif.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#ifndef _SBEIF_H
#define _SBEIF_H

#include <sbe/sbe_common.H>
#include <errl/errlentry.H>
#include <pnor/pnorif.H>
#include <secureboot/service.H>
#include <i2c/eepromif.H>

namespace SBE
{
    typedef uint8_t sbe_image_version_t[SBE_IMAGE_VERSION_SIZE];

    /**
     *  @brief Enumeration indicating whether SBE SEEPROM update should
     *      allow key transitioning (if applicable)
     */
    enum KEY_TRANSITION_PERM : uint8_t
    {
        INHIBIT_KEY_TRANSITION = 0x00,
        ALLOW_KEY_TRANSITION   = 0x01,
    };

    /**
     * @brief Gets a pointer to the proper SBE image in PNOR
     *
     * @param[in] i_target     Target used to find right SBE Image in PNOR
     *
     * @param[out] o_imgPtr    Pointer to SBE Image mapped in PNOR
     *                         Note: Pointer moved past any header(s)
     *
     * @param[out] o_imgSize   Size of the SBE Image in PNOR
     *                         Note: Size does not include any header(s)
     *
     * @param[out] o_version   Pointer to SBE Image Version Struct
     *                         If Pointer is NULL, version not returned;
     *                         Else sbe_image_version_t is filled in
     *
     * @return errlHndl_t      Error log handle on failure.
     */
    errlHndl_t findSBEInPnor(TARGETING::Target* i_target,
                             void*& o_imgPtr,
                             size_t& o_imgSize,
                             sbe_image_version_t* o_version = NULL);

    /**
     * @brief Iterates through all the functional processors and updates
     *        the SBE Image in a SEEPROM, if necessary.
     *
     * @param[in] i_keyTransPerm Whether key transitions should be allowed
     *     or inhibited (if applicable).  By default, they are inhibited.
     *     Only istep 10.2 should allow key transitioning.
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t updateProcessorSbeSeeproms(
        KEY_TRANSITION_PERM i_keyTransPerm = INHIBIT_KEY_TRANSITION);

    /**
     * @brief Determines whether we are on the Golden side or not
     *
     * @param[out] o_isGolden boolean, True if we are on Golden side, False
     *                        otherwise.
     *
     * @return errlHndl_t Error log handle on failure.
     *
     * NOTE: -Golden Side means we booted from the Golden Seeprom pointing
     *        at the Golden side of PNOR.
     *       -Using master processor to make this determination.
     */
    errlHndl_t isGoldenSide( bool & o_isGolden );

   /**
    * @brief Determines if we booted in synchronous memory mode or not
    *
    * @param[out] o_mcSyncMode - The MC sync mode the system last booted with.
    *
    * @return errlHndl_t Error log handle on error.
    */
    errlHndl_t getBootMcSyncMode( uint8_t& o_mcSyncMode );

    /**
     * @brief Sets the target processor to boot SBE from the side that is
     *        indicated by the SBE MVPD
     *
     * @param[in] i_target      Target processor to update
     *
     * @return errlHndl_t       Error log handle on failure.
     */
    errlHndl_t updateSbeBootSeeprom(TARGETING::Target* i_target);

    /**
     * @brief Retrieves the HW Key Hash and the Secure Version from the
     *        Bootloader (HBBL) Section of the SBE Image. By default, the
     *        image is read from a SBE SEEPROM (where ECC is removed), but
     *        it also can be read from a SBE Image in System Memory
     *
     * @param[in] i_target    Target Processor of the SBE SEEPPROM.
     *                        Assert if nullptr.
     *                        NOTE: Ignored if i_image_ptr specifies an image
     *                        (ie, != nullptr).
     *
     * @param[in] i_seeprom   Specific SEEPROM on the processor to read the
     *                        HW Key Hash from.
     *                        Assert if neither SBE_PRIMARY nor SBE_BACKUP.
     *                        NOTE: Ignored if i_image_ptr specifies an image
     *                        (ie, != nullptr).
     *
     * @param[out] o_hash     HW Key Hash returned from the Processor SEEPROM
     *
     * @param[out] o_secure_Version Secure Version returned from the Processor SEEPROM
     *
     * @param[in] i_image_ptr  Defaults to nullptr.
     *                         If nullptr, then read SBE Image from i_target
     *                         and i_seeprom.
     *                         If not nullptr, read SBE Image from system
     *                         memory pointed to by this parameter.
     *
     * @return errlHndl_t     Error log handle on failure; otherwise nullptr
     */
    errlHndl_t getSecuritySettingsFromSbeImage(
                          TARGETING::Target* i_target,
                          EEPROM::eeprom_chip_types_t i_seeprom,
                          SHA512_t o_hash,
                          uint8_t & o_secure_version,
                          const void * i_image_ptr = nullptr);

    /**
     * @brief Loop through all active processor targets and compare both sides of
     *        the processor's SBE's seeprom versions. Mark down in the attribute
     *        ATTR_HB_SBE_SEEPROM_VERSION_MATCH whether or not the versions match.
     *        This value is used later on to determine if it is safe to switch
     *        seeprom sides in the event that we attempt to recover the SBE from
     *        a failed state.
     *
     * @return errlHndl_t     Error log handle on failure; otherwise nullptr
     */
    errlHndl_t querySbeSeepromVersions();

} //end namespace SBE

#endif /* _SBEIF_H */
