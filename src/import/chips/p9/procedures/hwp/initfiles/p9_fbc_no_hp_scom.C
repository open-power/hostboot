/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_fbc_no_hp_scom.C $       */
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
#include "p9_fbc_no_hp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0 = 0;
constexpr auto literal_3 = 3;
constexpr auto literal_2 = 2;
constexpr auto literal_1 = 1;
constexpr auto literal_6 = 6;
constexpr auto literal_5 = 5;
constexpr auto literal_4 = 4;
constexpr auto literal_0x0 = 0x0;
constexpr auto literal_0x1 = 0x1;
constexpr auto literal_0x2 = 0x2;
constexpr auto literal_0x3 = 0x3;
constexpr auto literal_0x4 = 0x4;
constexpr auto literal_0x6 = 0x6;
constexpr auto literal_0x5 = 0x5;
constexpr auto literal_0x9 = 0x9;
constexpr auto literal_0xB = 0xB;
constexpr auto literal_0x13 = 0x13;
constexpr auto literal_0x7 = 0x7;
constexpr auto literal_0xA = 0xA;
constexpr auto literal_0xF = 0xF;
constexpr auto literal_0x1F = 0x1F;
constexpr auto literal_0xD = 0xD;
constexpr auto literal_0x12 = 0x12;
constexpr auto literal_0x17 = 0x17;
constexpr auto literal_0x1B = 0x1B;
constexpr auto literal_0x27 = 0x27;
constexpr auto literal_0x2F = 0x2F;
constexpr auto literal_0x37 = 0x37;
constexpr auto literal_0x8 = 0x8;
constexpr auto literal_0x1E = 0x1E;
constexpr auto literal_0x1A = 0x1A;
constexpr auto literal_0x15 = 0x15;
constexpr auto literal_0x2B = 0x2B;
constexpr auto literal_0x4F = 0x4F;
constexpr auto literal_0xE = 0xE;
constexpr auto literal_0xC = 0xC;
constexpr auto literal_0x11 = 0x11;
constexpr auto literal_0x23 = 0x23;
constexpr auto literal_0x47 = 0x47;
constexpr auto literal_0x3F = 0x3F;
constexpr auto literal_0x19 = 0x19;
constexpr auto literal_0x1D = 0x1D;
constexpr auto literal_0x3A = 0x3A;
constexpr auto literal_0x57 = 0x57;
constexpr auto literal_0x5F = 0x5F;
constexpr auto literal_0xAF = 0xAF;

fapi2::ReturnCode p9_fbc_no_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
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

        auto l_def_NUM_A_LINKS_CFG = (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] +
                                        l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1]) + l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2]) +
                                      l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3]);
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
            break;
        }

        auto l_def_NUM_X_LINKS_CFG = ((((((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] +
                                           l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1]) + l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2]) +
                                         l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3]) + l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4]) +
                                       l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5]) + l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6]);
        {
            l_rc = fapi2::getScom( TGT0, 0x501180aull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501180aull)");
                break;
            }

            {
                if (((l_def_NUM_X_LINKS_CFG == literal_0) && (l_def_NUM_A_LINKS_CFG == literal_0)))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 4, 1, 61 );
                }
                else if (((l_def_NUM_X_LINKS_CFG != literal_0) || (l_def_NUM_A_LINKS_CFG != literal_0)))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 4, 1, 61 );
                }
            }

            {
                constexpr auto l_scom_buffer_CNT_64 = 0x102040;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_CNT_64, 16, 7, 43 );
            }

            {
                constexpr auto l_scom_buffer_CNT_64 = 0x102040;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_CNT_64, 23, 7, 43 );
            }

            {
                constexpr auto l_scom_buffer_CNT_42 = 0x2aaaa;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_CNT_42, 30, 6, 46 );
            }

            l_rc = fapi2::putScom(TGT0, 0x501180aull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501180aull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5011c0aull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c0aull)");
                break;
            }

            {
                if (((l_def_NUM_X_LINKS_CFG == literal_0) && (l_def_NUM_A_LINKS_CFG == literal_0)))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 4, 1, 62 );
                }
                else if (((l_def_NUM_X_LINKS_CFG != literal_0) || (l_def_NUM_A_LINKS_CFG != literal_0)))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 4, 1, 62 );
                }
            }

            {
                constexpr auto l_scom_buffer_CNT_64 = 0x102040;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_CNT_64, 16, 7, 50 );
            }

            {
                constexpr auto l_scom_buffer_CNT_64 = 0x102040;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_CNT_64, 23, 7, 50 );
            }

            {
                constexpr auto l_scom_buffer_CNT_42 = 0x2aaaa;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_CNT_42, 30, 6, 52 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c0aull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c0aull)");
                break;
            }
        }
        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_PUMP_MODE)");
            break;
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011c26ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c26ull)");
                break;
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 0, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 8, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 16, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 24, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4, 32, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 40, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 48, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x13, 56, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c26ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c26ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011c27ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c27ull)");
                break;
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 0, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4, 8, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 16, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 24, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 32, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xA, 40, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 48, 8, 56 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1F, 56, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c27ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c27ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011c28ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c28ull)");
                break;
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 0, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 8, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 16, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 24, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 32, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x12, 40, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x13, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x13, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x17, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1B, 48, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x17, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x27, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x27, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2F, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x37, 56, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c28ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c28ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011c29ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c29ull)");
                break;
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 0, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 8, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 16, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x8, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 24, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xA, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x13, 32, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xA, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1F, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1E, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x12, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1A, 40, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x17, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x15, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1B, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x27, 48, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x17, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1F, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2F, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2B, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x37, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4F, 56, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c29ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c29ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011c2aull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c2aull)");
                break;
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x8, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 0, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xA, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 8, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xA, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 16, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xE, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xC, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 24, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x11, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x13, 32, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x17, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x12, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x15, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1A, 40, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x13, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x23, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1B, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1F, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x27, 48, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x17, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x27, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x47, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x37, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3F, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4F, 56, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c2aull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c2aull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011c2bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c2bull)");
                break;
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 0, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 0, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x15, 0, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 8, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 8, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x19, 8, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 16, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 16, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1D, 16, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x6, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x9, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 24, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x13, 24, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x23, 24, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x7, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xB, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x13, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xD, 32, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x17, 32, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2B, 32, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xA, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1A, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x12, 40, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1F, 40, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3A, 40, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xF, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x17, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x27, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1B, 48, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2F, 48, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x57, 48, 8, 56 );
                }
            }

            {
                if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                     && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x0, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1F, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x2F, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x4F, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG == literal_0)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x37, 56, 8, 56 );
                }
                else if ((((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                           && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x5F, 56, 8, 56 );
                }
                else if (((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP)
                          && (l_def_NUM_X_LINKS_CFG > literal_2)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xAF, 56, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c2bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c2bull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x501200aull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501200aull)");
                break;
            }

            {
                if (((l_def_NUM_X_LINKS_CFG == literal_0) && (l_def_NUM_A_LINKS_CFG == literal_0)))
                {
                    constexpr auto l_scom_buffer_ON = 0x7;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 4, 1, 63 );
                }
                else if (((l_def_NUM_X_LINKS_CFG != literal_0) || (l_def_NUM_A_LINKS_CFG != literal_0)))
                {
                    constexpr auto l_scom_buffer_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 4, 1, 63 );
                }
            }

            {
                constexpr auto l_scom_buffer_CNT_64 = 0x102040;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_CNT_64, 16, 7, 57 );
            }

            {
                constexpr auto l_scom_buffer_CNT_64 = 0x102040;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_CNT_64, 23, 7, 57 );
            }

            {
                constexpr auto l_scom_buffer_CNT_42 = 0x2aaaa;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_CNT_42, 30, 6, 58 );
            }

            l_rc = fapi2::putScom(TGT0, 0x501200aull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501200aull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
