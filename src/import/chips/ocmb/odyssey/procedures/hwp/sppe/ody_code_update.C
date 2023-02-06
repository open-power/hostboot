/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/sppe/ody_code_update.C $ */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_code_update.C
/// @brief Odyssey Code Update
///
// *HWP Owner: Hostboot Team
// *HWP Backup: SBE Team
// *HWP Level: 1
// *HWP Consumed by: HB:Cronus

#include <fapi2.H>
#include <fapi2_subroutine_executor.H>
#include <ody_code_update.H>
#include <ody_chipop_codeupdate.H>
#include <poz_perv_mod_misc_regs.H>

#define DC99

extern "C"
{

///
/// @brief Execute one or more chipops to perform a code update of the Odyssey
///       firmware images.
///
    fapi2::ReturnCode ody_code_update(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
        const std::vector<sppeCLIP_t>& i_curVersions,
        const std::vector<sppeImage_t>& i_newImages,
        bool i_forceUpdate,
        std::vector<sppeImageType_t>& o_results )
    {
        fapi2::ReturnCode l_rc;
        char l_targStr[fapi2::MAX_ECMD_STRING_LEN] = {0};
        fapi2::toString(i_ocmb, l_targStr, sizeof(l_targStr));
        bool l_bootloaderChanged = false;
        FAPI_INF("ENTER> ody_code_update: Ody=%s", l_targStr);

        // Map the current version to the new versions
        std::map<sppeImageType_t, sppeImageHash_t[2]> l_comparer;
        enum
        {
            CurrentImage = 0,
            NewImage = 1
        };

        // Read the active side
        fapi2::buffer<uint8_t> l_activeSide = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SPPE_BOOT_SIDE, i_ocmb, l_activeSide));

        FAPI_INF("Running on side %d", l_activeSide);

        // Print and save off the current versions to compare later
        for( auto l_cur : i_curVersions )
        {
            FAPI_INF("Current: type=%d, hash : %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X",
                     l_cur.type,
                     l_cur.hash.x[0], l_cur.hash.x[1], l_cur.hash.x[2], l_cur.hash.x[3],
                     l_cur.hash.x[4], l_cur.hash.x[5], l_cur.hash.x[6], l_cur.hash.x[7],
                     l_cur.hash.x[8], l_cur.hash.x[9], l_cur.hash.x[10], l_cur.hash.x[11],
                     l_cur.hash.x[12], l_cur.hash.x[13], l_cur.hash.x[14], l_cur.hash.x[15]);
            l_comparer[l_cur.type][CurrentImage] = l_cur.hash;
        }

        // Print and save off the new versions to compare later
        for( auto l_new : i_newImages )
        {
            l_comparer[l_new.type][NewImage] = l_new.hash;

            FAPI_INF("New: type=%d, hash : %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X",
                     l_new.type,
                     l_new.hash.x[0], l_new.hash.x[1], l_new.hash.x[2], l_new.hash.x[3],
                     l_new.hash.x[4], l_new.hash.x[5], l_new.hash.x[6], l_new.hash.x[7],
                     l_new.hash.x[8], l_new.hash.x[9], l_new.hash.x[10], l_new.hash.x[11],
                     l_new.hash.x[12], l_new.hash.x[13], l_new.hash.x[14], l_new.hash.x[15]);
        }

        // Loop around all input versions and send update chipop for any mismatch
        //  Note - This logic assumes that Bootloader will be processed before
        //  any other image types.

        for( auto l_type = Invalid;
             l_type < Num_Types;
             ++l_type )
        {
            // Skip the Invalid image enum
            if( Invalid == l_type )
            {
                continue;
            }
            // Skip this image type if no new image was passed in
            //   (using Invalid since it will always be set to zero above)
            else if( l_comparer[l_type][NewImage] == l_comparer[Invalid][0] )
            {
                FAPI_INF("No new image for type %d", l_type);
                continue;
            }
            // Continue on to the update if the force flag was set
            else if( i_forceUpdate )
            {
                FAPI_INF("Update is being forced");
            }
            // Update all images if we booted from Golden side
            else if( fapi2::ENUM_ATTR_SPPE_BOOT_SIDE_GOLDEN == l_activeSide )
            {
                FAPI_INF("Update of image %d is required since we are running on the Golden side",
                         l_type);
            }
            // Update all images if there was a bootloader change
            else if( l_bootloaderChanged )
            {
                FAPI_INF("Update of image %d is required due to bootloader change",
                         l_type);
            }
            // Skip if the image didn't change
            else if( l_comparer[l_type][CurrentImage]
                     == l_comparer[l_type][NewImage] )
            {
                FAPI_INF("Image type %d is unchanged", l_type);
                continue;
            }

            void* l_image = nullptr;
            size_t l_imageSize = 0;

            // find new image based on current type to load
            for( auto l_newImage : i_newImages )
            {
                if( l_newImage.type == l_type )
                {
                    l_image = l_newImage.pak;
                    l_imageSize = l_newImage.pakSize;
                    break;
                }
            }

            FAPI_TRY(l_image == nullptr,
                     "Error, image is a null ptr");
            FAPI_TRY(l_imageSize == 0,
                     "Error, image size is 0");

            // Actually call the chipop to update the image
            FAPI_INF("Updating image: type=%d, image=%p, size=%d",
                     l_type,
                     l_image,
                     l_imageSize);

            FAPI_CALL_SUBROUTINE(l_rc,
                                 ody_chipop_codeupdate,
                                 i_ocmb,
                                 l_type,
                                 l_image,
                                 l_imageSize);

            FAPI_TRY(l_rc,
                     "Error from ody_chipop_codeupdate on image type %d",
                     l_type);

            o_results.push_back(l_type);

            // Remember that we updated the bootloader to make sure we
            //  update all of the other images
            if( Bootloader == l_type )
            {
                l_bootloaderChanged = true;
            }

            //QUESTION-Should this HWP have the logic to hard fail vs continue?
            // Or is it up to the caller to decide what to do?

        }


    fapi_try_exit:
        FAPI_INF("EXIT> ody_code_update: Ody=%s", l_targStr);

        return fapi2::current_err;
    }

} //extern "C"
