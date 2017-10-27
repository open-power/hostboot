/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_npu_scom.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include "p9_npu_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0xF = 0xF;
constexpr uint64_t literal_0b001000 = 0b001000;
constexpr uint64_t literal_0b000001 = 0b000001;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0x66 = 0x66;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0x67 = 0x67;
constexpr uint64_t literal_0x4B = 0x4B;
constexpr uint64_t literal_0x04 = 0x04;
constexpr uint64_t literal_0x0C = 0x0C;
constexpr uint64_t literal_0x4 = 0x4;
constexpr uint64_t literal_0x100 = 0x100;
constexpr uint64_t literal_0x200 = 0x200;
constexpr uint64_t literal_0x300 = 0x300;
constexpr uint64_t literal_0x8 = 0x8;
constexpr uint64_t literal_0xFFF = 0xFFF;
constexpr uint64_t literal_0xE000000000000000 = 0xE000000000000000;
constexpr uint64_t literal_0x0000000000000000 = 0x0000000000000000;
constexpr uint64_t literal_0x0000740000000000 = 0x0000740000000000;
constexpr uint64_t literal_0x7F60B04500AC0000 = 0x7F60B04500AC0000;
constexpr uint64_t literal_0xAAA70A55F0000000 = 0xAAA70A55F0000000;
constexpr uint64_t literal_0x5550740000000000 = 0x5550740000000000;
constexpr uint64_t literal_0x009A48180F61FFFF = 0x009A48180F61FFFF;
constexpr uint64_t literal_0x009A48180F01FFFF = 0x009A48180F01FFFF;
constexpr uint64_t literal_0xFFFFFFFFFFFFFFFF = 0xFFFFFFFFFFFFFFFF;
constexpr uint64_t literal_0x7F60B04500AE0000 = 0x7F60B04500AE0000;
constexpr uint64_t literal_0x8005000200100000 = 0x8005000200100000;
constexpr uint64_t literal_0xFF65B04700FE0000 = 0xFF65B04700FE0000;
constexpr uint64_t literal_0x5550F40000000003 = 0x5550F40000000003;
constexpr uint64_t literal_0x0000F40000000003 = 0x0000F40000000003;
constexpr uint64_t literal_0xFFF70A5DF0000000 = 0xFFF70A5DF0000000;
constexpr uint64_t literal_0x000801A200000000 = 0x000801A200000000;
constexpr uint64_t literal_0xFFFF0BFFF0000000 = 0xFFFF0BFFF0000000;
constexpr uint64_t literal_0xF000003FF00C0FFF = 0xF000003FF00C0FFF;
constexpr uint64_t literal_0x0000100000024000 = 0x0000100000024000;

fapi2::ReturnCode p9_npu_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG));
        uint64_t l_def_NUM_X_LINKS_CFG = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] +
                                           l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1]) + l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2]);
        fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE));
        uint64_t l_def_NVLINK_ACTIVE = ((((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] ==
                                           fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV)
                                          || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                                         || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                                        || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV));
        fapi2::ATTR_CHIP_EC_FEATURE_HW372457_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW372457, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457));
        fapi2::ATTR_CHIP_EC_FEATURE_HW423589_OPTION1_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW423589_OPTION1, TGT0,
                               l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1));
        fapi2::ATTR_CHIP_EC_FEATURE_HW410625_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW410625, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625));
        fapi2::ATTR_CHIP_EC_FEATURE_HW364887_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW364887, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T0_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T1_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T2_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2));
        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1_Type l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1, TGT1, l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1));
        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2_Type l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2, TGT1, l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2));
        fapi2::ATTR_CHIP_EC_FEATURE_HW426816_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW426816, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816));
        fapi2::ATTR_CHIP_EC_FEATURE_DISABLE_NPU_FREEZE_Type l_TGT0_ATTR_CHIP_EC_FEATURE_DISABLE_NPU_FREEZE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DISABLE_NPU_FREEZE, TGT0,
                               l_TGT0_ATTR_CHIP_EC_FEATURE_DISABLE_NPU_FREEZE));
        uint64_t l_def_ENABLE_NPU_FREEZE = (l_TGT0_ATTR_CHIP_EC_FEATURE_DISABLE_NPU_FREEZE == literal_0);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011000ull, l_scom_buffer ));

            if ((l_def_NUM_X_LINKS_CFG == literal_1))
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
            }

            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                 || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
            {
                l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
            {
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011000ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011001ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011001ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011002ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011002ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011003ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
            {
                l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
            {
                l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
            {
                l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011003ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011008ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011008ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011010ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
            {
                l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011010ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501101bull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x501101bull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011020ull, l_scom_buffer ));

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011020ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011021ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011021ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011022ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011022ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011023ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011023ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011028ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011028ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011030ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011030ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011031ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011031ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011032ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011032ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011033ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011033ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011038ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011038ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501103bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501103bull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011040ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011040ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011041ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011041ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011042ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011042ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011043ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011043ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011048ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011048ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501104bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501104bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011050ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011050ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501105bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501105bull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011060ull, l_scom_buffer ));

            if ((l_def_NUM_X_LINKS_CFG == literal_1))
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
            }

            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                 || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
            {
                l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
            {
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011060ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011061ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011061ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011062ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011062ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011063ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
            {
                l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
            {
                l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
            {
                l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011063ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011068ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011068ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011070ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
            {
                l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011070ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501107bull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x501107bull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011080ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011080ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011090ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011090ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011091ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011091ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011092ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011092ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011093ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011093ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011098ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011098ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50110a0ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50110a0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50110abull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x50110abull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50110c0ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50110c0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50110d0ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50110d0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011100ull, l_scom_buffer ));

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011100ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011101ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011101ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011102ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011102ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011103ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011103ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011108ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011108ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011110ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011110ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501111bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501111bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011120ull, l_scom_buffer ));

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011120ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011121ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011121ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011122ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011122ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011123ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011123ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011128ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011128ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011130ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011130ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501113bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501113bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011140ull, l_scom_buffer ));

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011140ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011141ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011141ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011142ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011142ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011143ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011143ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011148ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011148ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011150ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011150ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501115bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501115bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011160ull, l_scom_buffer ));

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011160ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011161ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011161ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011162ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011162ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011163ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011163ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011168ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011168ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011170ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011170ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501117bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501117bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011180ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011180ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011190ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011190ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011200ull, l_scom_buffer ));

            if ((l_def_NUM_X_LINKS_CFG == literal_1))
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
            }

            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011200ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011201ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011201ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011202ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011202ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011203ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011203ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011208ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011208ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011210ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011210ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501121bull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x501121bull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011220ull, l_scom_buffer ));

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011220ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011221ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011221ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011222ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011222ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011223ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011223ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011228ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011228ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011230ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011230ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011231ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011231ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011232ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011232ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011233ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011233ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011238ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011238ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501123bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501123bull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011240ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011240ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011241ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011241ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011242ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011242ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011243ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011243ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011248ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011248ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501124bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501124bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011250ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011250ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501125bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501125bull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011260ull, l_scom_buffer ));

            if ((l_def_NUM_X_LINKS_CFG == literal_1))
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
            }

            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011260ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011261ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011261ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011262ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011262ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011263ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011263ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011268ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011268ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011270ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011270ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501127bull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x501127bull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011280ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011280ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011290ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011290ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011291ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011291ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011292ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011292ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011293ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011293ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011298ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011298ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50112a0ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50112a0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50112abull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x50112abull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50112c0ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50112c0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50112d0ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50112d0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011345ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x8 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011345ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011382ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 12, 52, uint64_t>(literal_0xFFF );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x8 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011382ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011383ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 3, 0, uint64_t>(literal_0xE000000000000000 );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 3, 0, uint64_t>(literal_0x0000000000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011383ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011389ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000740000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011389ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501138aull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7F60B04500AC0000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501138aull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501138bull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xAAA70A55F0000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501138bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501138dull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5550740000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501138dull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011400ull, l_scom_buffer ));

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011400ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011401ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011401ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011402ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011402ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011403ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x009A48180F61FFFF );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x009A48180F01FFFF );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011403ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011406ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000000000000000 );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7F60B04500AE0000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011406ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011407ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x8005000200100000 );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFF65B04700FE0000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011407ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011408ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011408ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011410ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011410ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501141bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501141bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011430ull, l_scom_buffer ));

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011430ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011431ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011431ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011432ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011432ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011433ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011433ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011438ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011438ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011440ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011440ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011443ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5550F40000000003 );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000F40000000003 );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011443ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011446ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000000000000000 );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFF70A5DF0000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011446ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011447ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x000801A200000000 );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFF0BFFF0000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011447ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501144bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501144bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011460ull, l_scom_buffer ));

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011460ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011461ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011461ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011462ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011462ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011463ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011463ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011468ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011468ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011470ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011470ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501147bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501147bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011490ull, l_scom_buffer ));

                if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_1 );
                }

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_TGT0_ATTR_CHIP_EC_FEATURE_HW410625 != literal_0)
                     || (l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0)))
                {
                    l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW423589_OPTION1 != literal_0))
                {
                    l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011490ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011491ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW364887 != literal_0))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0xF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011491ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011492ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011492ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011493ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b001000 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<26, 6, 58, uint64_t>(literal_0b000001 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<32, 6, 58, uint64_t>(literal_0b000001 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011493ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011498ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011498ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50114a0ull, l_scom_buffer ));

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x66 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW372457 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x67 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW426816 != literal_0))
                {
                    l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4B );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50114a0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50114abull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x50114abull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50114c0ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50114c0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50114d0ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50114d0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011645ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x8 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011645ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011682ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 12, 52, uint64_t>(literal_0xFFF );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x8 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011682ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011683ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 7, 0, uint64_t>(literal_0xE000000000000000 );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 7, 0, uint64_t>(literal_0x0000000000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011683ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011689ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000740000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011689ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501168aull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7F60B04500AC0000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501168aull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501168bull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xAAA70A55F0000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501168bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501168dull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5550740000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501168dull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c03ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x009A48180F61FFFF );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x009A48180F01FFFF );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c03ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c06ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000000000000000 );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7F60B04500AE0000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c06ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c07ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x8005000200100000 );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFF65B04700FE0000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c07ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c43ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5550F40000000003 );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000F40000000003 );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c43ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c46ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000000000000000 );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFF70A5DF0000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c46ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c47ull, l_scom_buffer ));

                if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_0)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x000801A200000000 );
                }
                else if (((l_def_NVLINK_ACTIVE == literal_1) && (l_def_ENABLE_NPU_FREEZE == literal_1)))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFF0BFFF0000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c47ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c83ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xF000003FF00C0FFF );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c83ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c86ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000000000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c86ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c87ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000100000024000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c87ull, l_scom_buffer));
            }
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
