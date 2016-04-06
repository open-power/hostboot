/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_ddrphy_scom.C $          */
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
#include "p9_ddrphy_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>
#include <attribute_ids.H>
#include <target_types.H>
#include <fapi2_attribute_service.H>
using namespace fapi2;

#define LITERAL_IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR0_0xFFFF    0xFFFF
#define LITERAL_IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR1_0xFFFF    0xFFFF
#define LITERAL_IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR2_0xFFFF    0xFFFF
#define LITERAL_IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR3_0xFFFF    0xFFFF
#define LITERAL_IOMP_DDRPHY_ADR_DELAY1_P0_ADR1_0x4040    0x4040
#define LITERAL_IOMP_DDRPHY_ADR_DELAY3_P0_ADR1_0x4040    0x4040
#define LITERAL_IOMP_DDRPHY_ADR_DIFFPAIR_ENABLE_P0_ADR1_0x5000    0x5000
#define LITERAL_IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S0_0xE058    0xE058
#define LITERAL_IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S1_0xE058    0xE058
#define LITERAL_IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0_0x6000    0x6000
#define LITERAL_IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S1_0x6000    0x6000
#define LITERAL_IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_0x0120    0x0120
#define LITERAL_IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_1_0x0120    0x0120
#define LITERAL_IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_2_0x0120    0x0120
#define LITERAL_IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_3_0x0120    0x0120
#define LITERAL_IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_4_0x0120    0x0120
#define LITERAL_IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_0_0x4000    0x4000
#define LITERAL_IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_1_0x4000    0x4000
#define LITERAL_IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_2_0x4000    0x4000
#define LITERAL_IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_3_0x4000    0x4000
#define LITERAL_IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_4_0x4000    0x4000
#define LITERAL_IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0_0x7F7F    0x7F7F
#define LITERAL_IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_1_0x7F7F    0x7F7F
#define LITERAL_IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_2_0x7F7F    0x7F7F
#define LITERAL_IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_3_0x7F7F    0x7F7F
#define LITERAL_IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_4_0x7F7F    0x7F7F
#define LITERAL_IOMP_DDRPHY_DP16_WRCLK_PR_P0_0_0x6000    0x6000
#define LITERAL_IOMP_DDRPHY_DP16_WRCLK_PR_P0_1_0x6000    0x6000
#define LITERAL_IOMP_DDRPHY_DP16_WRCLK_PR_P0_2_0x6000    0x6000
#define LITERAL_IOMP_DDRPHY_DP16_WRCLK_PR_P0_3_0x6000    0x6000
#define LITERAL_IOMP_DDRPHY_DP16_WRCLK_PR_P0_4_0x6000    0x6000
#define LITERAL_IOMP_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_0x4770    0x4770

fapi2::ReturnCode p9_ddrphy_scom(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800040000701103full, IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800040000701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR0_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR0_0xFFFF, 48, 16,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800044000701103full, IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800044000701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR1_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR1_0xFFFF, 48, 16,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR2_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800048000701103full, IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR2_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800048000701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR2_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR2_0xFFFF, 48, 16,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR3_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80004c000701103full, IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR3_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80004c000701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR3_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR3_0xFFFF, 48, 16,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_DELAY1_P0_ADR1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800044050701103full, IOMP_DDRPHY_ADR_DELAY1_P0_ADR1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800044050701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_DELAY1_P0_ADR1_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_ADR_DELAY1_P0_ADR1_0x4040, 48, 16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_DELAY3_P0_ADR1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800044070701103full, IOMP_DDRPHY_ADR_DELAY3_P0_ADR1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800044070701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_DELAY3_P0_ADR1_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_ADR_DELAY3_P0_ADR1_0x4040, 48, 16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_DIFFPAIR_ENABLE_P0_ADR1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800044010701103full, IOMP_DDRPHY_ADR_DIFFPAIR_ENABLE_P0_ADR1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800044010701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_DIFFPAIR_ENABLE_P0_ADR1_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_ADR_DIFFPAIR_ENABLE_P0_ADR1_0x5000,
                    48, 16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800080310701103full, IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800080310701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S0_scom0.insert<uint64_t>
            (LITERAL_IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S0_0xE058, 48, 16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800084310701103full, IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800084310701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S1_scom0.insert<uint64_t>
            (LITERAL_IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S1_0xE058, 48, 16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800080330701103full, IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800080330701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0_scom0.insert<uint64_t>
            (LITERAL_IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0_0x6000, 48, 16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800084330701103full, IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800084330701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S1_scom0.insert<uint64_t>
            (LITERAL_IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S1_0x6000, 48, 16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000030701103full, IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000030701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_0x0120, 48, 16,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800004030701103full, IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800004030701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_1_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_1_0x0120, 48, 16,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_2_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008030701103full, IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_2_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008030701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_2_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_2_0x0120, 48, 16,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_3_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80000c030701103full, IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_3_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80000c030701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_3_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_3_0x0120, 48, 16,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_4_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800010030701103full, IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_4_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800010030701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_4_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_4_0x0120, 48, 16,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000750701103full, IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000750701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_0_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_0_0x4000, 48, 12,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800004750701103full, IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800004750701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_1_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_1_0x4000, 48, 12,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_2_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008750701103full, IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_2_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008750701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_2_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_2_0x4000, 48, 12,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_3_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80000c750701103full, IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_3_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80000c750701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_3_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_3_0x4000, 48, 12,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_4_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800010750701103full, IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_4_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800010750701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_4_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_4_0x4000, 48, 12,
                    48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000780701103full, IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000780701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0_0x7F7F, 48,
                    16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800004780701103full, IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800004780701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_1_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_1_0x7F7F, 48,
                    16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_2_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008780701103full, IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_2_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008780701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_2_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_2_0x7F7F, 48,
                    16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_3_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80000c780701103full, IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_3_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80000c780701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_3_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_3_0x7F7F, 48,
                    16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_4_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800010780701103full, IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_4_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800010780701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_4_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_4_0x7F7F, 48,
                    16, 48 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_WRCLK_PR_P0_0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000740701103full, IOMP_DDRPHY_DP16_WRCLK_PR_P0_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000740701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_WRCLK_PR_P0_0_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_WRCLK_PR_P0_0_0x6000, 49, 7, 49 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_WRCLK_PR_P0_1_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800004740701103full, IOMP_DDRPHY_DP16_WRCLK_PR_P0_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800004740701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_WRCLK_PR_P0_1_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_WRCLK_PR_P0_1_0x6000, 49, 7, 49 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_WRCLK_PR_P0_2_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008740701103full, IOMP_DDRPHY_DP16_WRCLK_PR_P0_2_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008740701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_WRCLK_PR_P0_2_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_WRCLK_PR_P0_2_0x6000, 49, 7, 49 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_WRCLK_PR_P0_3_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80000c740701103full, IOMP_DDRPHY_DP16_WRCLK_PR_P0_3_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80000c740701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_WRCLK_PR_P0_3_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_WRCLK_PR_P0_3_0x6000, 49, 7, 49 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_DP16_WRCLK_PR_P0_4_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800010740701103full, IOMP_DDRPHY_DP16_WRCLK_PR_P0_4_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800010740701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_DP16_WRCLK_PR_P0_4_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_DP16_WRCLK_PR_P0_4_0x6000, 49, 7, 49 );
        }

        fapi2::buffer<uint64_t> IOMP_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c4140701103full, IOMP_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c4140701103f)");
            break;
        }

        if (( true ))
        {
            IOMP_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_scom0.insert<uint64_t> (LITERAL_IOMP_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_0x4770, 48,
                    16, 48 );
        }


        l_rc = fapi2::putScom( TGT0, 0x800000030701103full, IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000030701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000740701103full, IOMP_DDRPHY_DP16_WRCLK_PR_P0_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000740701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000750701103full, IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000750701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000780701103full, IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000780701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800004030701103full, IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800004030701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800004740701103full, IOMP_DDRPHY_DP16_WRCLK_PR_P0_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800004740701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800004750701103full, IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800004750701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800004780701103full, IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800004780701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008030701103full, IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_2_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008030701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008740701103full, IOMP_DDRPHY_DP16_WRCLK_PR_P0_2_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008740701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008750701103full, IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_2_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008750701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008780701103full, IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_2_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008780701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80000c030701103full, IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_3_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80000c030701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80000c740701103full, IOMP_DDRPHY_DP16_WRCLK_PR_P0_3_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80000c740701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80000c750701103full, IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_3_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80000c750701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80000c780701103full, IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_3_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80000c780701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800010030701103full, IOMP_DDRPHY_DP16_DATA_BIT_DIR1_P0_4_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800010030701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800010740701103full, IOMP_DDRPHY_DP16_WRCLK_PR_P0_4_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800010740701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800010750701103full, IOMP_DDRPHY_DP16_IO_TX_CONFIG0_P0_4_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800010750701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800010780701103full, IOMP_DDRPHY_DP16_IO_TX_FET_SLICE_P0_4_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800010780701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800040000701103full, IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800040000701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800044000701103full, IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800044000701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800044010701103full, IOMP_DDRPHY_ADR_DIFFPAIR_ENABLE_P0_ADR1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800044010701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800044050701103full, IOMP_DDRPHY_ADR_DELAY1_P0_ADR1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800044050701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800044070701103full, IOMP_DDRPHY_ADR_DELAY3_P0_ADR1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800044070701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800048000701103full, IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR2_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800048000701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80004c000701103full, IOMP_DDRPHY_ADR_BIT_ENABLE_P0_ADR3_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80004c000701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800080310701103full, IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800080310701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800080330701103full, IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800080330701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800084310701103full, IOMP_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800084310701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800084330701103full, IOMP_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S1_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800084330701103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c4140701103full, IOMP_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c4140701103f)");
            break;
        }

    }
    while(0);

    return l_rc;
}

