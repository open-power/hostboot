/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_mi_omi_pretrain_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#include "p10_mi_omi_pretrain_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_1 = 1;

fapi2::ReturnCode p10_mi_omi_pretrain_scom(const fapi2::Target<fapi2::TARGET_TYPE_MI>& TGT0,
        const fapi2::Target<fapi2::TARGET_TYPE_OMI>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_MCC>& TGT2,
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT3)
{
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT1_ATTR_CHIP_UNIT_POS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT1, l_TGT1_ATTR_CHIP_UNIT_POS));
        uint64_t l_def_OMI_POSITION = (l_TGT1_ATTR_CHIP_UNIT_POS % literal_2);
        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT2_ATTR_CHIP_UNIT_POS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT2, l_TGT2_ATTR_CHIP_UNIT_POS));
        uint64_t l_def_MCC_POSITION = (l_TGT2_ATTR_CHIP_UNIT_POS % literal_2);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0xc010c13ull, l_scom_buffer ));

            if (((l_def_MCC_POSITION == literal_0) && (l_def_OMI_POSITION == literal_0)))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_def_MCC_POSITION == literal_0) && (l_def_OMI_POSITION == literal_1)))
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_def_MCC_POSITION == literal_1) && (l_def_OMI_POSITION == literal_0)))
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_def_MCC_POSITION == literal_1) && (l_def_OMI_POSITION == literal_1)))
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0xc010c13ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
