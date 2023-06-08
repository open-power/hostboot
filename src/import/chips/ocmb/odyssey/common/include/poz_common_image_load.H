/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/poz_common_image_load.H $ */
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
#pragma once

#include <type_traits>
#include <fapi2.H>

enum poz_image_type
{
    IOPPE_BASE_IMAGE,
    IOPPE_MEMREGS_IMAGE,
    DDR_IMEM_IMAGE,
    DDR_DMEM_IMAGE,
};

typedef fapi2::ReturnCode(*poz_common_image_load_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    const uint8_t*,
    const uint32_t,
    const uint32_t,
    poz_image_type);

#define ASSERT_COMMON_IMAGE_LOAD(hwp) \
    static_assert(std::is_same<decltype(&hwp), poz_common_image_load_FP_t>::value, \
                  "HWP is not conforming to common Odyssey image load semantics")
