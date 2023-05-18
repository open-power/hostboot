/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ocmbupd/ocmbupd.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
#ifndef __OCMBUPD_H
#define __OCMBUPD_H

#include <isteps/hwpisteperror.H>
#include <targeting/common/target.H>

#include <sbeio/sbeioif.H>
#include "ocmbFwImage_const.H"

namespace ocmbupd
{

/**
 * @brief Parameters pertaining to an unpackaged (raw) Explorer OCMB firmware image
 */
typedef struct rawImageInfo
{
    const uint8_t* imagePtr;
    size_t         imageSize;
    const uint8_t* imageSHA512HashPtr;
    const uint8_t* fwVersionStrPtr;  // pointer to explorer firmware version string
    size_t         fwVersionStrSize; // size of explorer firmware version string
}rawImageInfo_t;


/**
 * @brief Check flash image SHA512 hash value of each explorer chip
 *        and update the flash if it does not match the SHA512 hash
 *        of the image in PNOR.
 *
 * @param[out] o_stepError Error handle for logging istep failures
 *
 */
void explorerUpdateAll(ISTEP_ERROR::IStepError& o_stepError);


/**
 * @brief Checks if update is needed and will perform i2c update if necessary
 * @param[out] o_stepError Error handle for logging istep failures
 */
void ocmbFwI2cUpdateStatusCheck( ISTEP_ERROR::IStepError & io_StepError);

/**
 * @brief List of pairs of the image level currently flashed on the
 *        SBE, and a pointer to new image contents in the OCMBFW PNOR
 *        partition for that image type.
 */
using ody_cur_version_new_image_t
    = std::vector<std::pair<SBEIO::codelevel_info_t, const ocmbfw_ext_image_info*>>;

/** @brief Resource owner for the OCMBFW partition.
 */
using ocmbfw_owning_ptr_t = std::unique_ptr<const ocmbfw_ext_pnor_section_header,
                                            void(*)(const void*)>;

/**
 * @brief Check which Odyssey images need to be updated in the given chip, compared
 *        to what exists in PNOR.
 *
 * @param[in] i_ocmb               The Odyssey chip.
 * @param[in] i_fwhdr              The OCMBFW PNOR partition header pointer.
 * @param[out] o_updates_required  The images needing update.
 * @return                         Error if any, otherwise nullptr.
 */
errlHndl_t check_for_odyssey_codeupdate_needed(TARGETING::Target* i_ocmb,
                                               const ocmbfw_owning_ptr_t& i_fwhdr,
                                               ody_cur_version_new_image_t& o_updates_required);

/**
 * @brief Write a set of firmware images to the given Odyssey chip.
 *
 * @param[in] i_ocmb              The Odyssey chip.
 * @param[in] i_fwhdr             The OCMBFW PNOR partition header pointer.
 * @param[in] i_updates_required  The images to write.
 */
errlHndl_t odyssey_update_code(TARGETING::Target* i_ocmb,
                               const ocmbfw_owning_ptr_t& i_fwhdr,
                               const ody_cur_version_new_image_t& i_updates_required);

/**
 * @brief Load the OCMBFW PNOR partition and produce a pointer to the extended
 * section header within.
 *
 * @param[out] o_err  Error if any, otherwise nullptr.
 * @return            Pointer to the extended header within the PNOR partition.
 *                    When this is destroyed, the PNOR section will be unloaded
 *                    if it was loaded by this function.
 * @note The pointer returned by this function must not be used if o_err contains
 *       an error on exit. It may or may not be null in an error condition.
 */
ocmbfw_owning_ptr_t load_ocmbfw_pnor_section(errlHndl_t& o_err);

/**
 * @brief Find an image within the OCMBFW PNOR partition.
 *
 * @param[out] o_img             Pointer to the image in PNOR, or nullptr if not found.
 * @param[in] i_hdr              The extended OCMBFW section header.
 * @param[in] i_ocmb_type        The type of OCMB the image should apply to.
 * @param[in] i_image_type       The type of image to search for.
 * @param[in] i_dd_level_major   The major DD level to search for.
 * @param[in] i_dd_level_minor   The minor DD level to search for.
 * @return                       Error if any, otherwise nullptr.
 */
errlHndl_t find_ocmbfw_ext_image(const ocmbfw_ext_image_info*& o_img,
                                 const ocmbfw_ext_pnor_section_header* i_hdr,
                                 ocmb_type_t i_ocmb_type,
                                 image_type_t i_image_type,
                                 uint32_t i_dd_level_major = DD_LEVEL_ANY,
                                 uint32_t i_dd_level_minor = DD_LEVEL_ANY);

/**
 * @brief Get the pointer to the contents of the given image within
 * the OCMBFW PNOR partition.
 *
 * @param[in] i_hdr  The extended OCMBFW PNOR partition header.
 * @param[in] i_img  The image info structure for the desired image.
 * @return           The contents of the image.
 */
const void* get_ext_image_contents(const ocmbfw_ext_pnor_section_header* i_hdr,
                                   const ocmbfw_ext_image_info* i_img);

}//namespace ocmbupd

#endif
