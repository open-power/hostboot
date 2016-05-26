/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_fbc_ioe_tl_scom.C $      */
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
#include "p9_fbc_ioe_tl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0 = 0;
constexpr auto literal_2 = 2;
constexpr auto literal_1 = 1;
constexpr auto literal_0xFFFFFFFFFFFFFFFF = 0xFFFFFFFFFFFFFFFF;
constexpr auto literal_0x1 = 0x1;
constexpr auto literal_0x20 = 0x20;
constexpr auto literal_12 = 12;
constexpr auto literal_10 = 10;
constexpr auto literal_0b0010001 = 0b0010001;
constexpr auto literal_11 = 11;
constexpr auto literal_0b0010000 = 0b0010000;
constexpr auto literal_0b0001111 = 0b0001111;
constexpr auto literal_0b0001110 = 0b0001110;
constexpr auto literal_0b0001101 = 0b0001101;
constexpr auto literal_13 = 13;
constexpr auto literal_0b0001100 = 0b0001100;
constexpr auto literal_0x1F = 0x1F;
constexpr auto literal_0x40 = 0x40;
constexpr auto literal_0x3C = 0x3C;
constexpr auto literal_0b0101 = 0b0101;

fapi2::ReturnCode p9_fbc_ioe_tl_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
            break;
        }

        auto l_def_X2_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] != literal_0);
        auto l_def_X1_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] != literal_0);
        auto l_def_X0_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] != literal_0);
        {
            l_rc = fapi2::getScom( TGT0, 0x5013403ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5013403ull)");
                break;
            }

            {
                if (((l_def_X0_ENABLED || l_def_X1_ENABLED) || l_def_X2_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0xFFFFFFFFFFFFFFFF, 0, 64, 0 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5013403ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5013403ull)");
                break;
            }
        }
        fapi2::ATTR_FREQ_PB_MHZ_Type l_TGT1_ATTR_FREQ_PB_MHZ;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ, TGT1, l_TGT1_ATTR_FREQ_PB_MHZ);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_FREQ_PB_MHZ)");
            break;
        }

        fapi2::ATTR_FREQ_X_MHZ_Type l_TGT1_ATTR_FREQ_X_MHZ;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_FREQ_X_MHZ, TGT1, l_TGT1_ATTR_FREQ_X_MHZ);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_FREQ_X_MHZ)");
            break;
        }

        auto l_def_X_RATIO_12_10 = ((literal_10 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_12 * l_TGT1_ATTR_FREQ_PB_MHZ));
        auto l_def_X_RATIO_11_10 = ((literal_10 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_11 * l_TGT1_ATTR_FREQ_PB_MHZ));
        auto l_def_X_RATIO_10_10 = ((literal_10 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_10 * l_TGT1_ATTR_FREQ_PB_MHZ));
        auto l_def_X_RATIO_10_11 = ((literal_11 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_10 * l_TGT1_ATTR_FREQ_PB_MHZ));
        auto l_def_X_RATIO_10_12 = ((literal_12 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_10 * l_TGT1_ATTR_FREQ_PB_MHZ));
        auto l_def_X_RATIO_10_13 = ((literal_13 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_10 * l_TGT1_ATTR_FREQ_PB_MHZ));
        {
            l_rc = fapi2::getScom( TGT0, 0x501340aull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501340aull)");
                break;
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1, 22, 2, 62 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x20, 12, 8, 56 );
                }
            }

            {
                if ((l_def_X0_ENABLED && (l_def_X_RATIO_12_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010001, 4, 8, 56 );
                }
                else if ((l_def_X0_ENABLED && (l_def_X_RATIO_11_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010000, 4, 8, 56 );
                }
                else if ((l_def_X0_ENABLED && (l_def_X_RATIO_10_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001111, 4, 8, 56 );
                }
                else if ((l_def_X0_ENABLED && (l_def_X_RATIO_10_11 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001110, 4, 8, 56 );
                }
                else if ((l_def_X0_ENABLED && (l_def_X_RATIO_10_12 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001101, 4, 8, 56 );
                }
                else if ((l_def_X0_ENABLED && (l_def_X_RATIO_10_13 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001100, 4, 8, 56 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x20, 44, 8, 56 );
                }
            }

            {
                if ((l_def_X0_ENABLED && (l_def_X_RATIO_12_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010001, 36, 8, 56 );
                }
                else if ((l_def_X0_ENABLED && (l_def_X_RATIO_11_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010000, 36, 8, 56 );
                }
                else if ((l_def_X0_ENABLED && (l_def_X_RATIO_10_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001111, 36, 8, 56 );
                }
                else if ((l_def_X0_ENABLED && (l_def_X_RATIO_10_11 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001110, 36, 8, 56 );
                }
                else if ((l_def_X0_ENABLED && (l_def_X_RATIO_10_12 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001101, 36, 8, 56 );
                }
                else if ((l_def_X0_ENABLED && (l_def_X_RATIO_10_13 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001100, 36, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x501340aull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501340aull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x501340bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501340bull)");
                break;
            }

            {
                if (l_def_X1_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1, 22, 2, 62 );
                }
            }

            {
                if (l_def_X1_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x20, 12, 8, 56 );
                }
            }

            {
                if ((l_def_X1_ENABLED && (l_def_X_RATIO_12_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010001, 4, 8, 56 );
                }
                else if ((l_def_X1_ENABLED && (l_def_X_RATIO_11_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010000, 4, 8, 56 );
                }
                else if ((l_def_X1_ENABLED && (l_def_X_RATIO_10_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001111, 4, 8, 56 );
                }
                else if ((l_def_X1_ENABLED && (l_def_X_RATIO_10_11 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001110, 4, 8, 56 );
                }
                else if ((l_def_X1_ENABLED && (l_def_X_RATIO_10_12 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001101, 4, 8, 56 );
                }
                else if ((l_def_X1_ENABLED && (l_def_X_RATIO_10_13 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001100, 4, 8, 56 );
                }
            }

            {
                if (l_def_X1_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x20, 44, 8, 56 );
                }
            }

            {
                if ((l_def_X1_ENABLED && (l_def_X_RATIO_12_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010001, 36, 8, 56 );
                }
                else if ((l_def_X1_ENABLED && (l_def_X_RATIO_11_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010000, 36, 8, 56 );
                }
                else if ((l_def_X1_ENABLED && (l_def_X_RATIO_10_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001111, 36, 8, 56 );
                }
                else if ((l_def_X1_ENABLED && (l_def_X_RATIO_10_11 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001110, 36, 8, 56 );
                }
                else if ((l_def_X1_ENABLED && (l_def_X_RATIO_10_12 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001101, 36, 8, 56 );
                }
                else if ((l_def_X1_ENABLED && (l_def_X_RATIO_10_13 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001100, 36, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x501340bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501340bull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x501340cull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501340cull)");
                break;
            }

            {
                if (l_def_X2_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1, 22, 2, 62 );
                }
            }

            {
                if (l_def_X2_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x20, 12, 8, 56 );
                }
            }

            {
                if ((l_def_X2_ENABLED && (l_def_X_RATIO_12_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010001, 4, 8, 56 );
                }
                else if ((l_def_X2_ENABLED && (l_def_X_RATIO_11_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010000, 4, 8, 56 );
                }
                else if ((l_def_X2_ENABLED && (l_def_X_RATIO_10_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001111, 4, 8, 56 );
                }
                else if ((l_def_X2_ENABLED && (l_def_X_RATIO_10_11 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001110, 4, 8, 56 );
                }
                else if ((l_def_X2_ENABLED && (l_def_X_RATIO_10_12 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001101, 4, 8, 56 );
                }
                else if ((l_def_X2_ENABLED && (l_def_X_RATIO_10_13 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001100, 4, 8, 56 );
                }
            }

            {
                if (l_def_X2_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x20, 44, 8, 56 );
                }
            }

            {
                if ((l_def_X2_ENABLED && (l_def_X_RATIO_12_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010001, 36, 8, 56 );
                }
                else if ((l_def_X2_ENABLED && (l_def_X_RATIO_11_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0010000, 36, 8, 56 );
                }
                else if ((l_def_X2_ENABLED && (l_def_X_RATIO_10_10 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001111, 36, 8, 56 );
                }
                else if ((l_def_X2_ENABLED && (l_def_X_RATIO_10_11 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001110, 36, 8, 56 );
                }
                else if ((l_def_X2_ENABLED && (l_def_X_RATIO_10_12 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001101, 36, 8, 56 );
                }
                else if ((l_def_X2_ENABLED && (l_def_X_RATIO_10_13 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0001100, 36, 8, 56 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x501340cull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501340cull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5013410ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5013410ull)");
                break;
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1F, 24, 5, 59 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 1, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 33, 7, 57 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 1, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 33, 7, 57 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 9, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 41, 7, 57 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 9, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 41, 7, 57 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 17, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 49, 7, 57 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 17, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 49, 7, 57 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5013410ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5013410ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5013411ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5013411ull)");
                break;
            }

            {
                if (l_def_X1_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1F, 24, 5, 59 );
                }
            }

            {
                if (l_def_X1_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 1, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 33, 7, 57 );
                }
            }

            {
                if (l_def_X1_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 1, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 33, 7, 57 );
                }
            }

            {
                if (l_def_X1_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 9, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 41, 7, 57 );
                }
            }

            {
                if (l_def_X1_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 9, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 41, 7, 57 );
                }
            }

            {
                if (l_def_X1_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 17, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 49, 7, 57 );
                }
            }

            {
                if (l_def_X1_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 17, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 49, 7, 57 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5013411ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5013411ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5013412ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5013412ull)");
                break;
            }

            {
                if (l_def_X2_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x1F, 24, 5, 59 );
                }
            }

            {
                if (l_def_X2_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 1, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 33, 7, 57 );
                }
            }

            {
                if (l_def_X2_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 1, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x40, 33, 7, 57 );
                }
            }

            {
                if (l_def_X2_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 9, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 41, 7, 57 );
                }
            }

            {
                if (l_def_X2_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 9, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 41, 7, 57 );
                }
            }

            {
                if (l_def_X2_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 17, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 49, 7, 57 );
                }
            }

            {
                if (l_def_X2_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 17, 7, 57 );
                    l_scom_buffer.insert<uint64_t> (literal_0x3C, 49, 7, 57 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5013412ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5013412ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5013423ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5013423ull)");
                break;
            }

            {
                if (l_def_X0_ENABLED)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 63 );
                }
            }

            {
                if (l_def_X1_ENABLED)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 1, 1, 63 );
                }
            }

            {
                if (l_def_X2_ENABLED)
                {
                    constexpr auto l_scom_buffer_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 2, 1, 63 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5013423ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5013423ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5013424ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5013424ull)");
                break;
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 0, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 8, 4, 60 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 0, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 8, 4, 60 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 4, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 12, 4, 60 );
                }
            }

            {
                if (l_def_X0_ENABLED)
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 4, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 12, 4, 60 );
                }
            }

            {
                if ((( ! l_def_X0_ENABLED) && l_def_X1_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 16, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 24, 4, 60 );
                }
            }

            {
                if ((( ! l_def_X0_ENABLED) && l_def_X1_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 16, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 24, 4, 60 );
                }
            }

            {
                if ((( ! l_def_X0_ENABLED) && l_def_X1_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 20, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 28, 4, 60 );
                }
            }

            {
                if ((( ! l_def_X0_ENABLED) && l_def_X1_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 20, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 28, 4, 60 );
                }
            }

            {
                if (((( ! l_def_X0_ENABLED) && ( ! l_def_X1_ENABLED)) && l_def_X2_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 32, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 40, 4, 60 );
                }
            }

            {
                if (((( ! l_def_X0_ENABLED) && ( ! l_def_X1_ENABLED)) && l_def_X2_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 32, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 40, 4, 60 );
                }
            }

            {
                if (((( ! l_def_X0_ENABLED) && ( ! l_def_X1_ENABLED)) && l_def_X2_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 36, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 44, 4, 60 );
                }
            }

            {
                if (((( ! l_def_X0_ENABLED) && ( ! l_def_X1_ENABLED)) && l_def_X2_ENABLED))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 36, 4, 60 );
                    l_scom_buffer.insert<uint64_t> (literal_0b0101, 44, 4, 60 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5013424ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5013424ull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
