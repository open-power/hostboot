/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_ipl_section_append.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#ifndef _P10_IPL_SECTION_APPEND_H_
#define _P10_IPL_SECTION_APPEND_H_

#ifndef WIN32
#include <fapi2.H>
//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_ipl_section_append_FP_t)(
    void*, uint32_t, uint32_t, void*, uint32_t&);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{
    fapi2::ReturnCode p10_ipl_section_append(
        void*     i_section,      // Ptr to buffer that gets appended
        uint32_t  i_section_size, // Size of buffer that gets appended
        uint32_t  i_section_id,   // XIP section to be populated
        void*     i_image,        // Ptr to XIP customize image (non-ecc)
        uint32_t& io_image_size); // in: space available for enlarged XIP image
    // out: size of enlarged XIP image
}
#else
//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef int (*p10_ipl_section_append_FP_t)(
    void*, uint32_t, uint32_t, void*, uint32_t&);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{
    int p10_ipl_section_append(
        void*     i_section,      // Ptr to buffer that gets appended
        uint32_t  i_section_size, // Size of buffer that gets appended
        uint32_t  i_section_id,   // XIP section to be populated
        void*     i_image,        // Ptr to XIP customize image (non-ecc)
        uint32_t& io_image_size); // in: space available for enlarged XIP image
    // out: size of enlarged XIP image
}
#endif
#endif //_P10_IPL_SECTION_APPEND_H_
