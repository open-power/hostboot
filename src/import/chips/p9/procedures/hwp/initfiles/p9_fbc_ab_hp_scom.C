/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_fbc_ab_hp_scom.C $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include "p9_fbc_ab_hp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0 = 0;
constexpr auto literal_1 = 1;
constexpr auto literal_2 = 2;
constexpr auto literal_3 = 3;
constexpr auto literal_0b0000000 = 0b0000000;
constexpr auto literal_4 = 4;
constexpr auto literal_5 = 5;
constexpr auto literal_6 = 6;
constexpr auto literal_7 = 7;
constexpr auto literal_8 = 8;
constexpr auto literal_9 = 9;
constexpr auto literal_10 = 10;
constexpr auto literal_11 = 11;
constexpr auto literal_12 = 12;
constexpr auto literal_13 = 13;
constexpr auto literal_14 = 14;
constexpr auto literal_15 = 15;
constexpr auto literal_1600 = 1600;
constexpr auto literal_2577 = 2577;

fapi2::ReturnCode p9_fbc_ab_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        fapi2::ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_Type l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP, TGT0, l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_Type l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_MASTER_CHIP, TGT0, l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_GROUP_MASTER_CHIP)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_CCSM_MODE_Type l_TGT1_ATTR_PROC_FABRIC_CCSM_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CCSM_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_CCSM_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_CCSM_MODE)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE_Type l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_SMP_OPTICS_MODE)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_CAPI_MODE_Type l_TGT1_ATTR_PROC_FABRIC_CAPI_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CAPI_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_CAPI_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_CAPI_MODE)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE_Type l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_ADDR_BAR_MODE)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_PUMP_MODE)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID_Type l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_A_AGGREGATE_Type l_TGT0_ATTR_PROC_FABRIC_A_AGGREGATE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_AGGREGATE, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_AGGREGATE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_AGGREGATE)");
            break;
        }

        auto l_def_LINK_A_AGGREGATE_EN = (l_TGT0_ATTR_PROC_FABRIC_A_AGGREGATE == ENUM_ATTR_PROC_FABRIC_A_AGGREGATE_ON);
        fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS_Type l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ADDR_DIS)");
            break;
        }

        fapi2::ATTR_FREQ_A_MHZ_Type l_TGT1_ATTR_FREQ_A_MHZ;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_FREQ_A_MHZ, TGT1, l_TGT1_ATTR_FREQ_A_MHZ);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_FREQ_A_MHZ)");
            break;
        }

        fapi2::ATTR_FREQ_PB_MHZ_Type l_TGT1_ATTR_FREQ_PB_MHZ;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ, TGT1, l_TGT1_ATTR_FREQ_PB_MHZ);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_FREQ_PB_MHZ)");
            break;
        }

        auto l_def_A_CMD_RATE_4B_R = (((literal_6 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_2577) % ((
                                          l_TGT1_ATTR_FREQ_A_MHZ * literal_1600) * literal_2));
        fapi2::ATTR_PROC_FABRIC_A_BUS_WIDTH_Type l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_BUS_WIDTH, TGT1, l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_BUS_WIDTH)");
            break;
        }

        auto l_def_A_CMD_RATE_D = ((l_TGT1_ATTR_FREQ_A_MHZ * literal_1600) * literal_2);
        auto l_def_A_CMD_RATE_4B_N = ((literal_6 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_2577);
        auto l_def_A_CMD_RATE_2B_R = (((literal_12 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_2577) % ((
                                          l_TGT1_ATTR_FREQ_A_MHZ * literal_1600) * literal_2));
        auto l_def_A_CMD_RATE_2B_N = ((literal_12 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_2577);
        {
            l_rc = fapi2::getScom( TGT0, 0x501180bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501180bull)");
                break;
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 1, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 2, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 3, 1, 61 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_CCSM_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CCSM_MODE_ON))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 29, 1, 61 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_A_BUS))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 30, 1, 61 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_CAPI_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CAPI_MODE_ON))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 31, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 32, 2, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 32, 2, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 32, 2, 58 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 34, 2, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 34, 2, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 34, 2, 58 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 36, 2, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 36, 2, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 36, 2, 58 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 38, 2, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 38, 2, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 38, 2, 58 );
                }
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b0000000, 40, 7, 57 );
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_CCSM_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CCSM_MODE_ON))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 52, 1, 61 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_SMALL_SYSTEM))
                {
                    constexpr auto l_scom_buffer_SMALL_SYSTEM_MODE = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMALL_SYSTEM_MODE, 53, 1, 61 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    constexpr auto l_scom_buffer_CHIP_IS_GROUP = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CHIP_IS_GROUP, 54, 1, 61 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 61 );
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 4, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 12, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 12, 4, 52 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 5, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 16, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 16, 4, 52 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 6, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 20, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 20, 4, 52 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 7, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 24, 4, 52 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 24, 4, 52 );
                }
            }

            {
                if (l_def_LINK_A_AGGREGATE_EN)
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 28, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 8, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 9, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 10, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 11, 1, 61 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                     && (l_def_A_CMD_RATE_4B_R != literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> ((l_def_A_CMD_RATE_4B_N / l_def_A_CMD_RATE_D), 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                          && (l_def_A_CMD_RATE_4B_R == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (((l_def_A_CMD_RATE_4B_N / l_def_A_CMD_RATE_D) - literal_1), 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                          && (l_def_A_CMD_RATE_2B_R != literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> ((l_def_A_CMD_RATE_2B_N / l_def_A_CMD_RATE_D), 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                          && (l_def_A_CMD_RATE_2B_R == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (((l_def_A_CMD_RATE_2B_N / l_def_A_CMD_RATE_D) - literal_1), 56, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x501180bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501180bull)");
                break;
            }
        }
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_X_AGGREGATE_Type l_TGT0_ATTR_PROC_FABRIC_X_AGGREGATE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_AGGREGATE, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_AGGREGATE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_AGGREGATE)");
            break;
        }

        auto l_def_LINK_X_AGGREGATE_EN = (l_TGT0_ATTR_PROC_FABRIC_X_AGGREGATE == ENUM_ATTR_PROC_FABRIC_X_AGGREGATE_ON);
        fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS_Type l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ADDR_DIS)");
            break;
        }

        fapi2::ATTR_FREQ_X_MHZ_Type l_TGT1_ATTR_FREQ_X_MHZ;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_FREQ_X_MHZ, TGT1, l_TGT1_ATTR_FREQ_X_MHZ);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_FREQ_X_MHZ)");
            break;
        }

        auto l_def_X_CMD_RATE_4B_R = ((literal_6 * l_TGT1_ATTR_FREQ_PB_MHZ) % l_TGT1_ATTR_FREQ_X_MHZ);
        fapi2::ATTR_PROC_FABRIC_X_BUS_WIDTH_Type l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_BUS_WIDTH, TGT1, l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_BUS_WIDTH)");
            break;
        }

        auto l_def_X_CMD_RATE_D = l_TGT1_ATTR_FREQ_X_MHZ;
        auto l_def_X_CMD_RATE_4B_N = (literal_6 * l_TGT1_ATTR_FREQ_PB_MHZ);
        auto l_def_X_CMD_RATE_2B_R = ((literal_12 * l_TGT1_ATTR_FREQ_PB_MHZ) % l_TGT1_ATTR_FREQ_X_MHZ);
        auto l_def_X_CMD_RATE_2B_N = (literal_12 * l_TGT1_ATTR_FREQ_PB_MHZ);
        {
            l_rc = fapi2::getScom( TGT0, 0x501180full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501180full)");
                break;
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 16, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 16, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 16, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 16, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 16, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 16, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 16, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 16, 3, 55 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 1, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 19, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 19, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 19, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 19, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 19, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 19, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 19, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 19, 3, 55 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 2, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 22, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 22, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 22, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 22, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 22, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 22, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 22, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 22, 3, 55 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 3, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 25, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 25, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 25, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 25, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 25, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 25, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 25, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 25, 3, 55 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 4, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 28, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 28, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 28, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 28, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 28, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 28, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 28, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 28, 3, 55 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 5, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 31, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 31, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 31, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 31, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 31, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 31, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 31, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 31, 3, 55 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 6, 1, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 34, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 34, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 34, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 34, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 34, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 34, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 34, 3, 55 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 34, 3, 55 );
                }
            }

            {
                if (l_def_LINK_X_AGGREGATE_EN)
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 37, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 8, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 9, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 10, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 11, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 12, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 13, 1, 61 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 14, 1, 61 );
                }
            }

            {
                constexpr auto l_scom_buffer_ON = 0x7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 49, 1, 61 );
            }

            {
                constexpr auto l_scom_buffer_ON = 0x7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 50, 1, 61 );
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                     && (l_def_X_CMD_RATE_4B_R != literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> ((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D), 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                          && (l_def_X_CMD_RATE_4B_R == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) - literal_1), 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                          && (l_def_X_CMD_RATE_2B_R != literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> ((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D), 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                          && (l_def_X_CMD_RATE_2B_R == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) - literal_1), 56, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x501180full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501180full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5011c0bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c0bull)");
                break;
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 1, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 2, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 3, 1, 62 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_CCSM_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CCSM_MODE_ON))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 29, 1, 62 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_A_BUS))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 30, 1, 62 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_CAPI_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CAPI_MODE_ON))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 31, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 32, 2, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 32, 2, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 32, 2, 60 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 34, 2, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 34, 2, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 34, 2, 60 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 36, 2, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 36, 2, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 36, 2, 60 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 38, 2, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 38, 2, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 38, 2, 60 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_CCSM_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CCSM_MODE_ON))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 52, 1, 62 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_SMALL_SYSTEM))
                {
                    constexpr auto l_scom_buffer_SMALL_SYSTEM_MODE = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMALL_SYSTEM_MODE, 53, 1, 62 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    constexpr auto l_scom_buffer_CHIP_IS_GROUP = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CHIP_IS_GROUP, 54, 1, 62 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 62 );
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 4, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 12, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 12, 4, 56 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 5, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 16, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 16, 4, 56 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 6, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 20, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 20, 4, 56 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 7, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 24, 4, 56 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 24, 4, 56 );
                }
            }

            {
                if (l_def_LINK_A_AGGREGATE_EN)
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 28, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 8, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 9, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 10, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 11, 1, 62 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c0bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c0bull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5011c0full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c0full)");
                break;
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 16, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 16, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 16, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 16, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 16, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 16, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 16, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 16, 3, 58 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 1, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 19, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 19, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 19, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 19, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 19, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 19, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 19, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 19, 3, 58 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 2, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 22, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 22, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 22, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 22, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 22, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 22, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 22, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 22, 3, 58 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 3, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 25, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 25, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 25, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 25, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 25, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 25, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 25, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 25, 3, 58 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 4, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 28, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 28, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 28, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 28, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 28, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 28, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 28, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 28, 3, 58 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 5, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 31, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 31, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 31, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 31, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 31, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 31, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 31, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 31, 3, 58 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 6, 1, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 34, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 34, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 34, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 34, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 34, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 34, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 34, 3, 58 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 34, 3, 58 );
                }
            }

            {
                if (l_def_LINK_X_AGGREGATE_EN)
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 37, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 8, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 9, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 10, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 11, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 12, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 13, 1, 62 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 14, 1, 62 );
                }
            }

            {
                constexpr auto l_scom_buffer_ON = 0x7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 49, 1, 62 );
            }

            {
                constexpr auto l_scom_buffer_ON = 0x7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 50, 1, 62 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c0full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c0full)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x501200bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501200bull)");
                break;
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 1, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 2, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 3, 1, 63 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_CCSM_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CCSM_MODE_ON))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 29, 1, 63 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_A_BUS))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 30, 1, 63 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_CAPI_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CAPI_MODE_ON))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 31, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 32, 2, 62 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 32, 2, 62 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 32, 2, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 34, 2, 62 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 34, 2, 62 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 34, 2, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 36, 2, 62 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 36, 2, 62 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 36, 2, 62 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
                {
                    constexpr auto l_scom_buffer_SMP = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMP, 38, 2, 62 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] ==
                          fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
                {
                    constexpr auto l_scom_buffer_CAPI = 0x15;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CAPI, 38, 2, 62 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                {
                    constexpr auto l_scom_buffer_NV = 0x2a;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_NV, 38, 2, 62 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_CCSM_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CCSM_MODE_ON))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 52, 1, 63 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_SMALL_SYSTEM))
                {
                    constexpr auto l_scom_buffer_SMALL_SYSTEM_MODE = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_SMALL_SYSTEM_MODE, 53, 1, 63 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    constexpr auto l_scom_buffer_CHIP_IS_GROUP = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_CHIP_IS_GROUP, 54, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 55, 1, 63 );
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 4, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 12, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 12, 4, 60 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 5, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 16, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 16, 4, 60 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 6, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 20, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 20, 4, 60 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 7, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x111;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x222;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0x333;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x444;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x555;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x666;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x777;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_8))
                {
                    constexpr auto l_scom_buffer_ID_8 = 0x888;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_8, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_9))
                {
                    constexpr auto l_scom_buffer_ID_9 = 0x999;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_9, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_10))
                {
                    constexpr auto l_scom_buffer_ID_10 = 0xaaa;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_10, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_11))
                {
                    constexpr auto l_scom_buffer_ID_11 = 0xbbb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_11, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_12))
                {
                    constexpr auto l_scom_buffer_ID_12 = 0xccc;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_12, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_13))
                {
                    constexpr auto l_scom_buffer_ID_13 = 0xddd;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_13, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_14))
                {
                    constexpr auto l_scom_buffer_ID_14 = 0xeee;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_14, 24, 4, 60 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_15))
                {
                    constexpr auto l_scom_buffer_ID_15 = 0xfff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_15, 24, 4, 60 );
                }
            }

            {
                if (l_def_LINK_A_AGGREGATE_EN)
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 28, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 8, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 9, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 10, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                     && l_def_LINK_A_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 11, 1, 63 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x501200bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501200bull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x501200full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501200full)");
                break;
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 16, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 16, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 16, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 16, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 16, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 16, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 16, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 16, 3, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 1, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 19, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 19, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 19, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 19, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 19, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 19, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 19, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 19, 3, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 2, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 22, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 22, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 22, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 22, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 22, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 22, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 22, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 22, 3, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 3, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 25, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 25, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 25, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 25, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 25, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 25, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 25, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 25, 3, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 4, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 28, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 28, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 28, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 28, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 28, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 28, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 28, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 28, 3, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 5, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 31, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 31, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 31, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 31, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 31, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 31, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 31, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 31, 3, 61 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 6, 1, 63 );
                }
            }

            {
                if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0))
                {
                    constexpr auto l_scom_buffer_ID_0 = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_0, 34, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1))
                {
                    constexpr auto l_scom_buffer_ID_1 = 0x49;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_1, 34, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2))
                {
                    constexpr auto l_scom_buffer_ID_2 = 0x92;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_2, 34, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3))
                {
                    constexpr auto l_scom_buffer_ID_3 = 0xdb;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_3, 34, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4))
                {
                    constexpr auto l_scom_buffer_ID_4 = 0x124;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_4, 34, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5))
                {
                    constexpr auto l_scom_buffer_ID_5 = 0x16d;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_5, 34, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6))
                {
                    constexpr auto l_scom_buffer_ID_6 = 0x1b6;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_6, 34, 3, 61 );
                }
                else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7))
                {
                    constexpr auto l_scom_buffer_ID_7 = 0x1ff;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ID_7, 34, 3, 61 );
                }
            }

            {
                if (l_def_LINK_X_AGGREGATE_EN)
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 37, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 8, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 9, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 10, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 11, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 12, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 13, 1, 63 );
                }
            }

            {
                if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                     && l_def_LINK_X_AGGREGATE_EN))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 14, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_ON = 0x7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 49, 1, 63 );
            }

            {
                constexpr auto l_scom_buffer_ON = 0x7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 50, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x501200full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501200full)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
