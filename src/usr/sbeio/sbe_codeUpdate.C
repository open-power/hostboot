/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_codeUpdate.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
* @file  sbe_codeUpdate.C
* @brief This file holds all the Code Update chipops for the SBE FIFO
*
*/

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <targeting/odyutil.H>
#include "sbe_getCodeLevels.H"

//  FAPI support
#include <fapi2.H>
#include <plat_hwp_invoker.H>

// Odyssey HWPs
#include <ody_code_getlevels.H>
#include <ody_code_update.H>

using namespace TARGETING;

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"CodeUpdate: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"CodeUpdate: " printf_string,##args)

/** @brief Implementation for the chipop used by ody_code_getlevels.
 *
 *  @param[in] i_target         The OCMB target
 *  @param[out] o_sppeCLIPData  The code level information packages for the SPPE.
 */
extern "C"
fapi2::ReturnCode ody_chipop_getcodelevels(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                           std::vector<sppeCLIP_t>& o_sppeCLIPdata)
{
    using namespace SBEIO;

    fapi2::ReturnCode rc;

    o_sppeCLIPdata.clear();

    getCodeLevelsResponse_t l_response{};

    auto errl = getFifoSbeCodeLevels(i_target.get(), l_response);
    if (errl)
    {
        SBE_TRACF("ody_chipop_getcodelevels failed: " TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(errl));
        addErrlPtrToReturnCode(rc, errl);
    }
    else
    {
        for (const auto& sppe_clip : l_response.updatable_images)
        {
            SBE_TRACF("ody_chipop_getcodelevels(0x%08X): Image type: %d",
                      get_huid(i_target.get()),
                      sppe_clip.type);

            const auto hash_words = reinterpret_cast<const uint32_t*>(&sppe_clip.hash);

            SBE_TRACF("ody_chipop_getcodelevels: Image hash prefix: %08x %08x %08x %08x",
                      hash_words[0], hash_words[1],
                      hash_words[2], hash_words[3]);

            sppeCLIP_t clip = { };
            clip.type = (sppeImageType_t)sppe_clip.type;

            static_assert(sizeof(sppe_clip.hash) == sizeof(clip.hash),
                          "Size of image hashes must be the same!");
            memcpy(&clip.hash, &sppe_clip.hash, sizeof(clip.hash));

            o_sppeCLIPdata.push_back(clip);
        }
    }

    return rc;
}

/**
 * @brief Implementation for the chipop used by ody_code_update.
 *
 * @param[in] i_target         The OCMB target to update.
 * @param[in] i_imageType      The type of image to update on the OCMB.
 * @param[in] i_image          The image contents.
 * @param[in] i_imageSize      Length of image contents in bytes.
 *
 * @return                     fapi2 return code.
 */
extern "C"
fapi2::ReturnCode ody_chipop_codeupdate(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        const sppeImageType_t& i_imageType,
                                        const void* const i_image,
                                        const size_t i_imageSize)
{
    using namespace SBEIO;

    fapi2::ReturnCode rc;

    SbeFifo::fifoUpdateImageRequest request(i_imageType, i_imageSize);

    memory_stream header_stream(&request, sizeof(request));
    memory_stream body_stream(i_image, i_imageSize);

    SbeFifo::fifoStandardResponse response;
    auto errl = SbeFifo::getTheInstance().performFifoChipOp(i_target.get(),
                                                            cat_streams(&header_stream,
                                                                        &body_stream),
                                                            reinterpret_cast<uint32_t*>(&response),
                                                            sizeof(response));

    if (errl)
    {
        SBE_TRACF("ody_chipop_getcodelevels failed: " TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(errl));
        addErrlPtrToReturnCode(rc, errl);
    }

    return rc;
}

namespace SBEIO
{
    errlHndl_t sendGetCodeLevelsRequest(Target * i_chipTarget)
    {
        SBE_TRACF(ENTER_MRK"sendGetCodeLevelsRequest(0x%08X)", get_huid(i_chipTarget));

        std::vector<sppeCLIP_t> clips;
        errlHndl_t              errl = nullptr;

        // Make sure the target is one of the supported types.
        errl = sbeioInterfaceChecks(i_chipTarget,
                                    SbeFifo::SBE_FIFO_CLASS_CODE_UPDATE_MESSAGES,
                                    SbeFifo::SBE_FIFO_CMD_GET_CODE_LEVELS);
        if (errl) {goto ERROR_EXIT;}

        if (!UTIL::isOdysseyChip(i_chipTarget))
        {
            SBE_TRACF("sendGetCodeLevelsRequest: Chip 0x%08X is not an Odyssey",
                      get_huid(i_chipTarget));
            goto ERROR_EXIT;
        }

        FAPI_INVOKE_HWP(errl, ody_code_getlevels, { i_chipTarget }, clips);

        if (errl)
        {
            SBE_TRACF("sendGetCodeLevelsRequest: ody_code_getlevels failed: " TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(errl));
            goto ERROR_EXIT;
        }

        // We only want the bootloader and runtime clips, and
        // then we save them as attributes

        clips.erase(std::remove_if(begin(clips), end(clips),
                                   [](const auto& clip)
                                   { return (clip.type != Bootloader
                                             && clip.type != Runtime); }),
                    end(clips));

        for (const auto& clip : clips)
        {
            switch (clip.type)
            {
              case Bootloader:
                i_chipTarget->setAttr<ATTR_SBE_BOOTLOADER_CODELEVEL>(clip.hash.x);
                break;
              case Runtime:
                i_chipTarget->setAttr<ATTR_SBE_RUNTIME_CODELEVEL>(clip.hash.x);
                break;
              default:
                assert(false); // this can't happen because the remove_if above
                               // filters out all but the two cases
            }
        }

        ERROR_EXIT:
        SBE_TRACF(EXIT_MRK"sendGetCodeLevelsRequest(0x%08X)", get_huid(i_chipTarget));
        return errl;
    }

    /**
     * @param[in] i_chipTarget The chip you would like to perform the chipop on
     *                       NOTE: HB should only be sending this to Odyssey chips
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t sendUpdateImageRequest(Target* const i_chipTarget,
                                      const codelevel_info_t& i_clip,
                                      const void* const i_img,
                                      const size_t i_img_size)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_CODE_UPDATE_MESSAGES,
                                        SbeFifo::SBE_FIFO_CMD_UPDATE_IMAGE);
            if(errl)
            {
                break;
            }

            if (!UTIL::isOdysseyChip(i_chipTarget))
            {
                SBE_TRACF(EXIT_MRK"sendUpdateImageRequest(0x%08X): Not an Odyssey chip",
                          get_huid(i_chipTarget));
                break;
            }

            sppeCLIP_t clip { };

            static_assert(sizeof(clip.hash) == sizeof(i_clip.hash));
            memcpy(&clip.hash, &i_clip.hash, sizeof(clip.hash));

            switch (i_clip.type)
            {
            case codelevel_info_t::bootloader:
                clip.type = Bootloader;
                break;
            case codelevel_info_t::runtime:
                clip.type = Runtime;
                break;
            }

            sppeImage_t sppe_image
            {
                .type = clip.type,
                .pakSize = i_img_size,
                .pak = (void*)i_img
            };

            static_assert(sizeof(sppe_image.hash) == sizeof(i_clip.hash));
            memcpy(&sppe_image.hash, &i_clip.hash, sizeof(sppe_image.hash));

            std::vector<sppeImageType_t> results;

            FAPI_INVOKE_HWP(errl,
                            ody_code_update,
                            { i_chipTarget },
                            { clip },
                            { sppe_image },
                            true /* force update */,
                            results);

            if (errl)
            {
                SBE_TRACF("sendUpdateImageRequest: ody_code_update failed: " TRACE_ERR_FMT,
                          TRACE_ERR_ARGS(errl));
                break;
            }
        }while(0);

        SBE_TRACD(EXIT_MRK "sendUpdateImageRequest");
        return errl;
    };

    /**
     * @brief Sync the backup code image with the running code image.
     */
    errlHndl_t sendSyncCodeLevelsRequest(Target* const i_chipTarget,
                                         const bool i_force_sync)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_CODE_UPDATE_MESSAGES,
                                        SbeFifo::SBE_FIFO_CMD_SYNC_CODE_LEVELS);
            if(errl)
            {
                break;
            }

            SbeFifo::fifoSyncCodeLevelsRequest request(i_force_sync);

            SbeFifo::fifoStandardResponse response;
            errl = SbeFifo::getTheInstance().performFifoChipOp(i_chipTarget,
                                                               reinterpret_cast<uint32_t*>(&request),
                                                               reinterpret_cast<uint32_t*>(&response),
                                                               sizeof(response));

            if (errl)
            {
                SBE_TRACF("sendSyncCodeLevels failed: " TRACE_ERR_FMT,
                          TRACE_ERR_ARGS(errl));
                break;
            }
        }while(0);

        SBE_TRACD(EXIT_MRK "sendSyncCodeLevelsRequest");
        return errl;
    };
} //end namespace SBEIO
