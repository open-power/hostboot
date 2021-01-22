/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbe/sbeif.H $                                 */
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
#ifndef _SBEIF_H
#define _SBEIF_H

#include <sbe/sbe_common.H>
#include <sbe/sbe_update.H>
#include <errl/errlentry.H>
#include <pnor/pnorif.H>
#include <secureboot/service.H>
#include <eeprom/eepromif.H>

namespace SBE
{
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
     *        "sb_settings" section of the SBE Image. By default, the
     *        image is read from a SBE SEEPROM (where ECC is removed), but
     *        it also can be read from a SBE Image in System Memory
     *
     * @param[in] i_target    Target Processor of the SBE SEEPPROM.
     *                        Assert if nullptr.
     *                        NOTE: Ignored if i_image_ptr specifies an image
     *                        (ie, != nullptr).
     *
     * @param[in] i_seeprom   Specific SEEPROM on the processor to read the
     *                        HW Key Hash and Secure Version from.
     *                        Assert if neither SBE_PRIMARY nor SBE_BACKUP.
     *                        NOTE: Ignored if i_image_ptr specifies an image
     *                        (ie, != nullptr).
     *
     * @param[in] i_bootSide  Designates which Seeprom the processor booted on.
     *                        If i_bootSide and i_seeprom match then ChipOps
     *                        will be used to read the Seeprom to avoid SPI
     *                        collisions.
     *
     * @param[out] o_hash     HW Key Hash returned from the SBE Image
     *
     * @param[out] o_secure_Version Secure Version returned from the SBE Image
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
                          EEPROM::EEPROM_ROLE i_seeprom,
                          sbeSeepromSide_t i_bootSide,
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
