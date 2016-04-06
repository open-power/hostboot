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
#include <attribute_ids.H>
#include <target_types.H>
#include <fapi2_attribute_service.H>
using namespace fapi2;

#define LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4    0x41a4240c64318560
#define LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4_1    0x0
#define LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R    0xa446a446739cc9a6
#define LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_1    0xccc213a2946aa22b
#define LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_2    0x1cc301184

fapi2::ReturnCode p9_mca_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> MCP_PORT0_SRQ_STD_SIZE_scom0;
        l_rc = fapi2::getScom( TGT0, 0x701090cull, MCP_PORT0_SRQ_STD_SIZE_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x701090c)");
            break;
        }

        fapi2::buffer<uint64_t> MCP_PORT0_SRQ_STD_SIZE_scom01;
        l_rc = fapi2::getScom( TGT0, 0x7010932ull, MCP_PORT0_SRQ_STD_SIZE_scom01 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x7010932)");
            break;
        }

        fapi2::buffer<uint64_t> MCP_PORT0_SRQ_STD_SIZE_scom012;
        l_rc = fapi2::getScom( TGT0, 0x7010934ull, MCP_PORT0_SRQ_STD_SIZE_scom012 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x7010934)");
            break;
        }

        fapi2::buffer<uint64_t> MCP_PORT0_SRQ_STD_SIZE_scom0123;
        l_rc = fapi2::getScom( TGT0, 0x7010935ull, MCP_PORT0_SRQ_STD_SIZE_scom0123 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x7010935)");
            break;
        }

        MCP_PORT0_SRQ_STD_SIZE_scom0.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4, 10, 6, 0 );
        MCP_PORT0_SRQ_STD_SIZE_scom01.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4, 30, 20, 6 );
        MCP_PORT0_SRQ_STD_SIZE_scom012.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4, 16, 5, 26 );
        MCP_PORT0_SRQ_STD_SIZE_scom012.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4, 11, 5, 31 );
        MCP_PORT0_SRQ_STD_SIZE_scom012.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4, 6, 5, 36 );
        MCP_PORT0_SRQ_STD_SIZE_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4, 17, 10, 41 );
        MCP_PORT0_SRQ_STD_SIZE_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4, 12, 5, 51 );
        MCP_PORT0_SRQ_STD_SIZE_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4, 27, 8, 56 );
        MCP_PORT0_SRQ_STD_SIZE_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_SIZE_2400_8GB_X4_1, 35, 3, 61 );

        fapi2::buffer<uint64_t> MCP_PORT0_SRQ_STD_TIMING_scom0;
        l_rc = fapi2::getScom( TGT0, 0x701090bull, MCP_PORT0_SRQ_STD_TIMING_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x701090b)");
            break;
        }

        fapi2::buffer<uint64_t> MCP_PORT0_SRQ_STD_TIMING_scom012;
        l_rc = fapi2::getScom( TGT0, 0x7010913ull, MCP_PORT0_SRQ_STD_TIMING_scom012 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x7010913)");
            break;
        }

        fapi2::buffer<uint64_t> MCP_PORT0_SRQ_STD_TIMING_scom0123;
        l_rc = fapi2::getScom( TGT0, 0x701090aull, MCP_PORT0_SRQ_STD_TIMING_scom0123 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x701090a)");
            break;
        }

        MCP_PORT0_SRQ_STD_TIMING_scom0.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R, 0, 63, 0 );
        MCP_PORT0_SRQ_STD_SIZE_scom0.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R, 0, 1, 63 );
        MCP_PORT0_SRQ_STD_SIZE_scom0.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_1, 1, 9, 0 );
        MCP_PORT0_SRQ_STD_SIZE_scom0.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_1, 16, 16, 9 );
        MCP_PORT0_SRQ_STD_SIZE_scom0.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_1, 41, 23, 25 );
        MCP_PORT0_SRQ_STD_TIMING_scom012.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_1, 38, 1,
                48 );
        MCP_PORT0_SRQ_STD_TIMING_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_1, 36, 6,
                49 );
        MCP_PORT0_SRQ_STD_TIMING_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_1, 30, 6,
                55 );
        MCP_PORT0_SRQ_STD_TIMING_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_1, 24, 3,
                61 );
        MCP_PORT0_SRQ_STD_TIMING_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_2, 27, 3,
                25 );
        MCP_PORT0_SRQ_STD_TIMING_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_2, 0, 12,
                28 );
        MCP_PORT0_SRQ_STD_TIMING_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_2, 43, 6,
                40 );
        MCP_PORT0_SRQ_STD_TIMING_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_2, 12, 12,
                46 );
        MCP_PORT0_SRQ_STD_TIMING_scom0123.insert<uint64_t> (LITERAL_MCP_PORT0_SRQ_STD_TIMING_SC_DDR4_2400_16_16_16R_2, 49, 6,
                58 );


        l_rc = fapi2::putScom( TGT0, 0x701090aull, MCP_PORT0_SRQ_STD_TIMING_scom0123 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x701090a)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x701090bull, MCP_PORT0_SRQ_STD_TIMING_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x701090b)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x701090cull, MCP_PORT0_SRQ_STD_SIZE_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x701090c)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x7010913ull, MCP_PORT0_SRQ_STD_TIMING_scom012 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x7010913)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x7010932ull, MCP_PORT0_SRQ_STD_SIZE_scom01 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x7010932)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x7010934ull, MCP_PORT0_SRQ_STD_SIZE_scom012 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x7010934)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x7010935ull, MCP_PORT0_SRQ_STD_SIZE_scom0123 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x7010935)");
            break;
        }

    }
    while(0);

    return l_rc;
}

