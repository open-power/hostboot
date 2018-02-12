/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_cd_hp2_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#include "p9_fbc_cd_hp2_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b1000 = 0b1000;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0b1111 = 0b1111;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0b11111110 = 0b11111110;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0b10 = 0b10;

fapi2::ReturnCode p9_fbc_cd_hp2_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE_Type l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE));
        uint64_t l_def_SMP_OPTICS_MODE = (l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE ==
                                          fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_A_BUS);
        fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG));
        uint64_t l_def_NUM_X_LINKS_CFG = l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG;
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11))
                || ((l_chip_id == 0x6) && (l_chip_ec == 0x12)) || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.flush<0> ();

                if (literal_1)
                {
                    l_scom_buffer.insert<38, 4, 60, uint64_t>(literal_0b1000 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<42, 4, 60, uint64_t>(literal_0b0100 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<46, 3, 61, uint64_t>(literal_0b001 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<46, 3, 61, uint64_t>(literal_0b000 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b000 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b001 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b000 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b001 );
                }

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1111 );
                }
                else if (literal_1)
                {
                    l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x90000daa05011c11ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11))
                || ((l_chip_id == 0x6) && (l_chip_ec == 0x12)) || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.flush<0> ();

                if (literal_1)
                {
                    l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b0100 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<17, 4, 60, uint64_t>(literal_0b0100 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<21, 4, 60, uint64_t>(literal_0b0100 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<25, 3, 61, uint64_t>(literal_0b011 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<25, 3, 61, uint64_t>(literal_0b001 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<28, 3, 61, uint64_t>(literal_0b001 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<31, 3, 61, uint64_t>(literal_0b010 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<31, 3, 61, uint64_t>(literal_0b001 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<34, 8, 56, uint64_t>(literal_0b11111110 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<42, 8, 56, uint64_t>(literal_0b11111110 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b010 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x90000f4d05011c11ull, l_scom_buffer));
            }
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
