/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ioo_tl_scom.C $ */
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
#include "p9_fbc_ioo_tl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0 = 0;
constexpr auto literal_3 = 3;
constexpr auto literal_6 = 6;
constexpr auto literal_2 = 2;
constexpr auto literal_5 = 5;
constexpr auto literal_1 = 1;
constexpr auto literal_4 = 4;
constexpr auto literal_0xFFFFFFFFFFFFFFFF = 0xFFFFFFFFFFFFFFFF;
constexpr auto literal_0b0101 = 0b0101;

fapi2::ReturnCode p9_fbc_ioo_tl_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
            break;
        }

        auto l_def_OBUS3_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] != literal_0)
                                        || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] != literal_0));
        auto l_def_OBUS2_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] != literal_0)
                                        || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] != literal_0));
        auto l_def_OBUS1_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] != literal_0)
                                        || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] != literal_0));
        auto l_def_OBUS0_FBC_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] != literal_0)
                                        || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] != literal_0));
        {
            l_rc = fapi2::getScom( TGT0, 0x5013803ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5013803ull)");
                break;
            }

            {
                if ((((l_def_OBUS0_FBC_ENABLED || l_def_OBUS1_FBC_ENABLED) || l_def_OBUS2_FBC_ENABLED) || l_def_OBUS3_FBC_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xFFFFFFFFFFFFFFFF, 0, 64, 0 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5013803ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5013803ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5013823ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5013823ull)");
                break;
            }

            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_PB_IOO_SCOM_PB_CFG_IOO01_IS_LOGICAL_PAIR_ON, 0, 1, 63 );
                }
            }

            {
                if (l_def_OBUS1_FBC_ENABLED)
                {
                    constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO23_IS_LOGICAL_PAIR_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_PB_IOO_SCOM_PB_CFG_IOO23_IS_LOGICAL_PAIR_ON, 1, 1, 63 );
                }
            }

            {
                if (l_def_OBUS2_FBC_ENABLED)
                {
                    constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO45_IS_LOGICAL_PAIR_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_PB_IOO_SCOM_PB_CFG_IOO45_IS_LOGICAL_PAIR_ON, 2, 1, 63 );
                }
            }

            {
                if (l_def_OBUS3_FBC_ENABLED)
                {
                    constexpr auto l_PB_IOO_SCOM_PB_CFG_IOO67_IS_LOGICAL_PAIR_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_PB_IOO_SCOM_PB_CFG_IOO67_IS_LOGICAL_PAIR_ON, 3, 1, 63 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5013823ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5013823ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5013824ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5013824ull)");
                break;
            }

            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 0, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 8, 4, 60 );
                }
            }

            {
                if (l_def_OBUS0_FBC_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 4, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 12, 4, 60 );
                }
            }

            {
                if ((( ! l_def_OBUS0_FBC_ENABLED) && l_def_OBUS1_FBC_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 16, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 24, 4, 60 );
                }
            }

            {
                if ((( ! l_def_OBUS0_FBC_ENABLED) && l_def_OBUS1_FBC_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 20, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 28, 4, 60 );
                }
            }

            {
                if (((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && l_def_OBUS2_FBC_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 32, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 40, 4, 60 );
                }
            }

            {
                if (((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && l_def_OBUS2_FBC_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 36, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 44, 4, 60 );
                }
            }

            {
                if ((((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && ( ! l_def_OBUS2_FBC_ENABLED))
                     && l_def_OBUS3_FBC_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 48, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 56, 4, 60 );
                }
            }

            {
                if ((((( ! l_def_OBUS0_FBC_ENABLED) && ( ! l_def_OBUS1_FBC_ENABLED)) && ( ! l_def_OBUS2_FBC_ENABLED))
                     && l_def_OBUS3_FBC_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 52, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 60, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5013824ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5013824ull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
