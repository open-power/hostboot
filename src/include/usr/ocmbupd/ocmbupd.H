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
#include <targeting/odyutil.H>
#include <istepHelperFuncs.H>

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
 */
void explorerUpdateAll(ISTEP_ERROR::IStepError& o_stepError);

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
 * @brief Update Odyssey OCMB firmware on the given target if necessary.
 *
 * @param[in] i_ocmb                   OCMB to update.
 * @param[in] i_force_update_all       Whether to update all of the code images
 *                                     on the chip regardless of whether they're
 *                                     out of date or not.
 * @return                             Error if any, otherwise nullptr.
 */
errlHndl_t odysseyUpdateImages(TARGETING::Target* i_ocmb,
                               bool i_force_update_all);

/**
 * @brief Check which Odyssey images need to be updated in the given chip, compared
 *        to what exists in PNOR.
 *
 * @param[in] i_ocmb               The Odyssey chip.
 * @param[out] o_updates_required  The images needing update.
 * @param[out] o_rt_hash_prefix    The 64-bit prefix of the hash of the runtime code
 *                                 level on running the Odyssey (optional).
 * @param[out] o_bldr_hash_prefix  The 64-bit prefix of the hash of the bootloader
 *                                 code level running on the Odyssey (optional).
 * @param[in]  i_force_update_all  If true, will consider all images in need of update.
 *                                 (Optional.)
 * @return                         Error if any, otherwise nullptr.
 */
errlHndl_t check_for_odyssey_codeupdate_needed(TARGETING::Target* i_ocmb,
                                               ody_cur_version_new_image_t& o_updates_required,
                                               uint64_t* const o_rt_hash_prefix = nullptr,
                                               uint64_t* const o_bldr_hash_prefix = nullptr,
                                               bool i_force_update_all = false);

/**
 * @brief Checks if update is needed and will perform i2c update if necessary
 * @param[in/out] o_stepError Error handle for logging istep failures
 */
void ocmbFwI2cUpdateStatusCheck( ISTEP_ERROR::IStepError & io_StepError);

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

/**
 *  @brief  Determines if the error is recoverable by I2C OCMB update
 *          If recoverable, commits error as recovered and triggers reconfig loop
 *          If not-recoverable, will act as normal captureError() call
 *
 *  @note   This function is not meant to be used in multithreaded contexts. If
 *          multiple errors need to be handled, call this function on each one
 *          sequentially.
 *
 *  @param[in/out] io_err
 *      An error log handle, that contains the error log info. Can be NULL.  If
 *      NULL then this function becomes a no-op.  BEWARE: Upon exit of
 *      this function, the handle will be NULL.
 *
 *  @param[out] io_stepError
 *      The details from the error handle, io_err, which will be added to this.
 *
 *  @param[in] i_componentId
 *      The component ID that will be associated with the error handler, io_err,
 *      when the error is committed.
 *
 *  @param[in] i_target
 *      The target that will be assimilated and have its knowledge
 *      added to the collective and when I say collective, I mean the error log
 *      handle, io_err ... resistance is futile. If not target is given, then
 *      target data will not be collected.
 */
inline void captureErrorOcmbUpdateCheck(errlHndl_t& io_err,
                                        ISTEP_ERROR::IStepError& io_stepError,
                                        const compId_t i_componentId,
                                        TARGETING::Target* const i_target)
{
    using namespace TARGETING;

    // Chip-specific handling functions.
    void explorerCaptureErrorOcmbUpdateCheck(errlHndl_t &io_err,
                                             ISTEP_ERROR::IStepError &io_stepError,
                                             compId_t i_componentId,
                                             const Target*  i_target);

    void odysseyCaptureErrorOcmbUpdateCheck(errlHndl_t &io_err,
                                            ISTEP_ERROR::IStepError &io_stepError,
                                            compId_t i_componentId,
                                            const Target* i_target);

    TRACISTEP(ENTER_MRK"captureErrorOcmbUpdateCheck: Handling error 0x%08X on target 0x%08X",
              ERRL_GETEID_SAFE(io_err),
              get_huid(i_target));

    if (!UTIL::isOdysseyChip(i_target))
    { // If this hwp was invoked on something other than an odyssey chip, but it's
      // *related* to an odyssey chip, then
        const auto parent_proc = (i_target->getAttr<ATTR_TYPE>() == TYPE_PROC
                                  ? i_target
                                  : getParent(i_target, TYPE_PROC));

        if (UTIL::hasOdysseyOcmbChildren(parent_proc))
        {
            odysseyCaptureErrorOcmbUpdateCheck(io_err, io_stepError, i_componentId, i_target);
        }
        else
        { // If the error isn't on an odyssey target or a target related to odyssey parts,
          // let the Explorer update handler take it. This will capture the error if there
          // is no update needed, or mark the part for an update otherwise.
            explorerCaptureErrorOcmbUpdateCheck(io_err, io_stepError, i_componentId, i_target);
        }
    }
    else
    {
        TRACISTEP(ENTER_MRK"captureErrorOcmbUpdateCheck: Comitting error on Odyssey chip");

        captureError(io_err, io_stepError, i_componentId);
    }

    TRACISTEP(EXIT_MRK"captureErrorOcmbUpdateCheck");
}

/**
 * @brief Whether Odyssey code update is supported. This boils down to
 * checking whether the Odyssey firmware is available in PNOR. We are
 * doing this for temporary backward compatibility with old OCMBFW
 * partitions until we drop support.
 *
 * @TODO JIRA: PFHB-522 Remove this function and all calls.
 */
bool odysseyCodeUpdateSupported();

}//namespace ocmbupd

#endif
