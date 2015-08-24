/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbe/sbeif.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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

#include <errl/errlentry.H>
#include <pnor/pnorif.H>

namespace SBE
{
    // Each SBE Image stored in PNOR has a 64-byte version associated with it
    // (like a SHA hash of the image)
    const size_t   SBE_IMAGE_VERSION_SIZE = 64; // 64 bytes

    typedef uint8_t sbe_image_version_t[SBE_IMAGE_VERSION_SIZE];


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
                             void*& o_imgPt,
                             size_t& o_imgSize,
                             sbe_image_version_t* o_version = NULL);

    /**
     * @enum sbeUpdateCheckType
     *
     * @brief Determines what types of checks are performed on the SBE Seeproms
     *        to determine if an update is necessary.
     *
     */
    enum sbeUpdateCheckType
    {
        SBE_UPDATE_CHECK_ALL                   = 0x00,
        SBE_UPDATE_ONLY_CHECK_NEST_FREQ        = 0x01
    };

    /**
     * @brief Iterates through all the functional processors and updates
     *        the SBE Image in a SEEPROM, if necessary.
     *
     * @param[in] i_check_type    Indicates what types of checks are performed
     *                            on the SBE Seeproms to determine if an update
     *                            is necessary.
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t updateProcessorSbeSeeproms(
                   sbeUpdateCheckType i_check_type = SBE_UPDATE_CHECK_ALL);

    /**
     * @brief Iterates through all the functional processors and resolves
     *        the Hostboot Base Addresses (HBB) in each SBE Image and performs
     *        any necessary operations related to GOLDEN side support.
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t resolveProcessorSbeSeeproms();

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



} //end namespace SBE

#endif /* _SBEIF_H */
