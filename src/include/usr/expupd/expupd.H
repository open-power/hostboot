/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/expupd/expupd.H $                             */
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
#ifndef __EXPUPD_H
#define __EXPUPD_H

#include <isteps/hwpisteperror.H>
#include <targeting/common/target.H>

#include "ocmbFwImage_const.H"

namespace expupd
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
 * @brief Find out which explorer chips need an update.
 *        Check flash image SHA512 hash value of each explorer chip
 *        and add to list if the value does not match the SHA512 hash
 *        of the image in PNOR.
 *
 * @note  Cleanup call PNOR::unloadSecureSection(PNOR::OCMBFW)
 *        if o_imageLoaded returns true
 *
 * @param[out] o_stepError Error handle for logging istep failures
 * @param[out] o_flashUpdateList List of Explorer OCMB's that mismatch
 * @param[out] o_versionUpdateList List of Explorer OCMB's that need version
 *                data rewritten
 * @param[out] o_imageInfo PNOR image information for update
 * @param[out] o_imageLoaded true if PNOR::OCMBFW secure section loaded
 * @param[out] o_rebootRequired true if any OCMB FW upate is triggered by a FW
 *                  mismatch or forced by attribute, but not the mfg flag
 * @param[in]  i_checkMfgFlag Use the mfg flag in update decision
 */
void explorerUpdateCheck(ISTEP_ERROR::IStepError& o_stepError,
                         TARGETING::TargetHandleList& o_flashUpdateList,
                         TARGETING::TargetHandleList& o_versionUpdateList,
                         rawImageInfo_t & o_imageInfo,
                         bool & o_imageLoaded,
                         bool & o_rebootRequired,
                         bool i_checkMfgFlag  );

/**
 * @brief Call the HWP to perform update on list of Ocmb chips.
 *        This will try to update multiple OCMBs at a time via threads.
 *
 * @param[out] o_stepError Error handle for logging istep failures
 * @param[in]  i_explorerList List of Explorer OCMB's that need to update
 * @param[in]  i_imageInfo PNOR OCMBFW image information for update
 * @param[in]  i_rebootRequired true if any OCMB FW upate is triggered by a FW
 *                  mismatch or forced by attribute, but not the mfg flag
 */
void performUpdate(ISTEP_ERROR::IStepError& o_stepError,
                   TARGETING::TargetHandleList& i_explorerList,
                   rawImageInfo_t& i_imageInfo,
                   bool i_rebootRequired );


/**
 * @brief Check flash image SHA512 hash value of each explorer chip
 *        and update the flash if it does not match the SHA512 hash
 *        of the image in PNOR.
 *
 * @param[out] o_stepError Error handle for logging istep failures
 *
 */
void updateAll(ISTEP_ERROR::IStepError& o_stepError);


/**
 * @brief Checks if update is needed and will perform i2c update if necessary
 * @param[out] o_stepError Error handle for logging istep failures
 */
void ocmbFwI2cUpdateStatusCheck( ISTEP_ERROR::IStepError & io_StepError);

/** @brief Resource owner for the OCMBFW partition.
 */
using ocmbfw_owning_ptr_t = std::unique_ptr<const ocmbfw_ext_pnor_section_header,
                                            void(*)(const void*)>;

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

}//namespace expupd

#endif
