/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_mca_scom.C $             */
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
#include "p9_mca_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;


fapi2::ReturnCode p9_mca_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            l_rc = fapi2::getScom( TGT0, 0x701090aull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x701090aull)");
                break;
            }

            constexpr auto l_scom_buffer_SC_DDR4_2400_16_16_16R = 0xa446a446739cc9a6;
            constexpr auto l_scom_buffer_SC_DDR4_2400_16_16_16R_1 = 0xccc213a2946aa22b;
            constexpr auto l_scom_buffer_SC_DDR4_2400_16_16_16R_2 = 0x1cc301184;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R, 0, 63, 0 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R, 0, 1, 63 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 1, 9, 0 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 16, 16, 9 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 41, 23, 25 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 38, 1, 48 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 36, 6, 49 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 30, 6, 55 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 24, 3, 61 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 27, 3, 25 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 0, 12, 28 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 43, 6, 40 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 12, 12, 46 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 49, 6, 58 );
            l_rc = fapi2::putScom(TGT0, 0x701090aull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x701090aull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x701090bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x701090bull)");
                break;
            }

            constexpr auto l_scom_buffer_SC_DDR4_2400_16_16_16R = 0xa446a446739cc9a6;
            constexpr auto l_scom_buffer_SC_DDR4_2400_16_16_16R_1 = 0xccc213a2946aa22b;
            constexpr auto l_scom_buffer_SC_DDR4_2400_16_16_16R_2 = 0x1cc301184;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R, 0, 63, 0 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R, 0, 1, 63 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 1, 9, 0 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 16, 16, 9 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 41, 23, 25 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 38, 1, 48 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 36, 6, 49 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 30, 6, 55 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 24, 3, 61 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 27, 3, 25 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 0, 12, 28 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 43, 6, 40 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 12, 12, 46 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 49, 6, 58 );
            l_rc = fapi2::putScom(TGT0, 0x701090bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x701090bull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x701090cull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x701090cull)");
                break;
            }

            constexpr auto l_scom_buffer_2400_8GB_X4 = 0x41a4240c64318560;
            constexpr auto l_scom_buffer_2400_8GB_X4_1 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 10, 6, 0 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 30, 20, 6 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 16, 5, 26 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 11, 5, 31 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 6, 5, 36 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 17, 10, 41 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 12, 5, 51 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 27, 8, 56 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4_1, 35, 3, 61 );
            l_rc = fapi2::putScom(TGT0, 0x701090cull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x701090cull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x7010913ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x7010913ull)");
                break;
            }

            constexpr auto l_scom_buffer_SC_DDR4_2400_16_16_16R = 0xa446a446739cc9a6;
            constexpr auto l_scom_buffer_SC_DDR4_2400_16_16_16R_1 = 0xccc213a2946aa22b;
            constexpr auto l_scom_buffer_SC_DDR4_2400_16_16_16R_2 = 0x1cc301184;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R, 0, 63, 0 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R, 0, 1, 63 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 1, 9, 0 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 16, 16, 9 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 41, 23, 25 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 38, 1, 48 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 36, 6, 49 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 30, 6, 55 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_1, 24, 3, 61 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 27, 3, 25 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 0, 12, 28 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 43, 6, 40 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 12, 12, 46 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_SC_DDR4_2400_16_16_16R_2, 49, 6, 58 );
            l_rc = fapi2::putScom(TGT0, 0x7010913ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x7010913ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x7010932ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x7010932ull)");
                break;
            }

            constexpr auto l_scom_buffer_2400_8GB_X4 = 0x41a4240c64318560;
            constexpr auto l_scom_buffer_2400_8GB_X4_1 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 10, 6, 0 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 30, 20, 6 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 16, 5, 26 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 11, 5, 31 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 6, 5, 36 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 17, 10, 41 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 12, 5, 51 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 27, 8, 56 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4_1, 35, 3, 61 );
            l_rc = fapi2::putScom(TGT0, 0x7010932ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x7010932ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x7010934ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x7010934ull)");
                break;
            }

            constexpr auto l_scom_buffer_2400_8GB_X4 = 0x41a4240c64318560;
            constexpr auto l_scom_buffer_2400_8GB_X4_1 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 10, 6, 0 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 30, 20, 6 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 16, 5, 26 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 11, 5, 31 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 6, 5, 36 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 17, 10, 41 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 12, 5, 51 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 27, 8, 56 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4_1, 35, 3, 61 );
            l_rc = fapi2::putScom(TGT0, 0x7010934ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x7010934ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x7010935ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x7010935ull)");
                break;
            }

            constexpr auto l_scom_buffer_2400_8GB_X4 = 0x41a4240c64318560;
            constexpr auto l_scom_buffer_2400_8GB_X4_1 = 0x0;
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 10, 6, 0 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 30, 20, 6 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 16, 5, 26 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 11, 5, 31 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 6, 5, 36 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 17, 10, 41 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 12, 5, 51 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4, 27, 8, 56 );
            l_scom_buffer.insert<uint64_t> (l_scom_buffer_2400_8GB_X4_1, 35, 3, 61 );
            l_rc = fapi2::putScom(TGT0, 0x7010935ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x7010935ull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
