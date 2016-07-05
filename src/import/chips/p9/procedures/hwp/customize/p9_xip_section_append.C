/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/customize/p9_xip_section_append.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <p9_xip_section_append.H>
#include <p9_xip_image.h>


fapi2::ReturnCode p9_xip_section_append(
    void*     i_section,      // Ptr to buffer that gets appended
    uint32_t  i_section_size, // Size of buffer that gets appended
    uint32_t  i_section_id,   // XIP section to be populated
    void*     i_image,        // Ptr to XIP customize image (non-ecc)
    uint32_t& io_image_size)  // in: space available for enlarged XIP image
// out: size of enlarged XIP image
{
    uint32_t unused_param = 0;
    int rc;

    FAPI_DBG(">>p9_xip_section_append");

    fapi2::current_err = fapi2::FAPI2_RC_INVALID_PARAMETER;

    FAPI_ASSERT((i_section != NULL),
                fapi2::XIP_SECTION_APPEND_SANITY_SECTION().
                set_SECTION(i_section),
                "Section pointer not valid (0x%x)", i_section);
    FAPI_ASSERT((i_section_size > 0),
                fapi2::XIP_SECTION_APPEND_SANITY_SECTION_SIZE().
                set_SECTION_SIZE(i_section_size),
                "Section size not valid (%d)", i_section_size);
    FAPI_ASSERT((i_section_id < P9_XIP_SECTIONS),
                fapi2::XIP_SECTION_APPEND_SANITY_SECTION_ID().
                set_SECTION_ID(i_section_id),
                "Section ID not valid (%d)", i_section_id);
    FAPI_ASSERT((i_image != NULL),
                fapi2::XIP_SECTION_APPEND_SANITY_IMAGE().
                set_IMAGE(i_image),
                "Image pointer not valid (0x%x)", i_image);
    FAPI_ASSERT((io_image_size > 0),
                fapi2::XIP_SECTION_APPEND_SANITY_IMAGE_SIZE().
                set_IMAGE_SIZE(io_image_size),
                "Size of available image space not valid (%d)", io_image_size);

    FAPI_DBG("i_section 0x%x", i_section);
    FAPI_DBG("i_section_size %d", i_section_size);
    FAPI_DBG("i_section_id %d", i_section_id);
    FAPI_DBG("i_image 0x%x", i_image);
    FAPI_DBG("io_image_size %d", io_image_size);

    fapi2::current_err = fapi2::FAPI2_RC_PLAT_ERR_SEE_DATA;

    rc = p9_xip_append(i_image, i_section_id, i_section, i_section_size,
                       io_image_size, &unused_param);
    FAPI_ASSERT((rc == 0),
                fapi2::XIP_SECTION_APPEND_APPEND_RC().
                set_APPEND_RC(rc).
                set_SECTION(i_section).
                set_SECTION_SIZE(i_section_size).
                set_SECTION_ID(i_section_id).
                set_IMAGE(i_image).
                set_IMAGE_SIZE(io_image_size),
                "Failed to append section (rc=%d)", rc);

    rc = p9_xip_image_size(i_image, &io_image_size);
    FAPI_ASSERT((rc == 0),
                fapi2::XIP_SECTION_APPEND_SIZE_RC().
                set_SIZE_RC(rc).
                set_SECTION(i_section).
                set_SECTION_SIZE(i_section_size).
                set_SECTION_ID(i_section_id).
                set_IMAGE(i_image).
                set_IMAGE_SIZE(io_image_size),
                "Failed to determine new image size (rc=%d)", rc);

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_DBG("<<p9_xip_section_append");
    return fapi2::current_err;
}

