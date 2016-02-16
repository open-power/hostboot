/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_xbus_g0_scom.C $         */
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
#include "p9_xbus_g0_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>
#include <attribute_ids.H>
#include <target_types.H>
#include <fapi2_attribute_service.H>
using namespace fapi2;

#define ATTR_IS_SIMULATION_ATTRIBUTE_VALUE_0    0
#define ATTR_IS_SIMULATION_ATTRIBUTE_VALUE_1    1
#define LITERAL_0b00    0b00
#define LITERAL_0b0000    0b0000
#define LITERAL_0b00000    0b00000
#define LITERAL_0b000000    0b000000
#define LITERAL_0b0000000    0b0000000
#define LITERAL_0b0000000000000000    0b0000000000000000
#define LITERAL_0b0000011    0b0000011
#define LITERAL_0b00001    0b00001
#define LITERAL_0b0010000    0b0010000
#define LITERAL_0b0010001    0b0010001
#define LITERAL_0b01    0b01
#define LITERAL_0b0110    0b0110
#define LITERAL_0b01100    0b01100
#define LITERAL_0b01111    0b01111
#define LITERAL_0b01111111    0b01111111
#define LITERAL_0b100111    0b100111
#define LITERAL_0b1011    0b1011
#define LITERAL_0b11    0b11
#define LITERAL_DRV_0S    0x0
#define LITERAL_ENABLED    0x0
#define LITERAL_FENCED    0x80000000
#define LITERAL_OFF    0x0
#define LITERAL_ON    0x80000000
#define LITERAL_PATTERN_24_A_0_15    0x10000000
#define LITERAL_PATTERN_24_A_16_22    0x84000000
#define LITERAL_PATTERN_24_B_0_15    0xf03e0000
#define LITERAL_PATTERN_24_B_16_22    0x7c000000
#define LITERAL_PATTERN_24_C_0_15    0x7bc0000
#define LITERAL_PATTERN_24_C_12_ACGH_16_22    0x0
#define LITERAL_PATTERN_24_D_0_15    0x7c70000
#define LITERAL_PATTERN_24_D_16_22    0xc0000000
#define LITERAL_PATTERN_24_EF_16_22    0x80000000
#define LITERAL_PATTERN_24_E_0_15    0x3ef0000
#define LITERAL_PATTERN_24_F_0_15    0x1f0f0000
#define LITERAL_PATTERN_24_GH_16_22    0x6000000
#define LITERAL_PATTERN_24_G_0_15    0x18000000
#define LITERAL_PATTERN_24_H_0_15    0x9c000000
#define LITERAL_PATTERN_TX_AB_HALF_A_0_15    0x0
#define LITERAL_PATTERN_TX_A_16_22    0x2000000
#define LITERAL_PATTERN_TX_B_16_22    0xf8000000
#define LITERAL_PATTERN_TX_C_0_15    0x1e0000
#define LITERAL_PATTERN_TX_C_16_22    0xf6000000
#define LITERAL_PATTERN_TX_DG_16_22    0x18000000
#define LITERAL_PATTERN_TX_D_0_15    0x1f0000
#define LITERAL_PATTERN_TX_E_16_22    0xbc000000
#define LITERAL_PATTERN_TX_E_HALF_B_0_15    0xf0000
#define LITERAL_PATTERN_TX_F_0_15    0x7c0000
#define LITERAL_PATTERN_TX_F_HALF_A_16_22    0x20000000
#define LITERAL_PATTERN_TX_G_0_15    0xc630000
#define LITERAL_PATTERN_TX_H_0_15    0xe730000
#define LITERAL_PATTERN_TX_H_HALF_B_16_22    0x9c000000

fapi2::ReturnCode p9_xbus_g0_scom(const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& TGT0,
                                  const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_BUS_ID_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800808000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_BUS_ID_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800808000601103f)");
            break;
        }

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_BUS_ID_scom0.insert<uint64_t> (LITERAL_0b000000, 48, 6, 58 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_BUS_ID_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800c0c000601103full, IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_BUS_ID_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800c0c000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_BUS_ID_scom0.insert<uint64_t> (LITERAL_0b000000, 48, 6, 58 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_START_LANE_ID_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800980000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_START_LANE_ID_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800980000601103f)");
            break;
        }

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_START_LANE_ID_scom0.insert<uint64_t> (LITERAL_0b0000000, 49, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_START_LANE_ID_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800c84000601103full,
                               IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_START_LANE_ID_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800c84000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_START_LANE_ID_scom0.insert<uint64_t> (LITERAL_0b0000000, 49, 7, 57 );

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_START_LANE_ID_scom0.insert<uint64_t> (LITERAL_0b0010000, 57, 7, 57 );

        IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_START_LANE_ID_scom0.insert<uint64_t> (LITERAL_0b0010000, 57, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_TX_BUS_WIDTH_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8009b8000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_TX_BUS_WIDTH_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8009b8000601103f)");
            break;
        }

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_TX_BUS_WIDTH_scom0.insert<uint64_t> (LITERAL_0b0010001, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_BUS_WIDTH_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800c1c000601103full, IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_BUS_WIDTH_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800c1c000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_BUS_WIDTH_scom0.insert<uint64_t> (LITERAL_0b0010001, 56, 7, 57 );

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_TX_BUS_WIDTH_scom0.insert<uint64_t> (LITERAL_0b0010001, 55, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_LANE_DISABLED_VEC_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8009e0000601103full,
                               IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_LANE_DISABLED_VEC_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8009e0000601103f)");
            break;
        }

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_LANE_DISABLED_VEC_0_15_scom0.insert<uint64_t> (LITERAL_0b0000000000000000, 48,
                16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_LANE_DISABLED_VEC_16_23_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8009e8000601103full,
                               IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_LANE_DISABLED_VEC_16_23_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8009e8000601103f)");
            break;
        }

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_LANE_DISABLED_VEC_16_23_scom0.insert<uint64_t> (LITERAL_0b01111111, 48, 8,
                56 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_LANE_DISABLED_VEC_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800cec000601103full,
                               IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_LANE_DISABLED_VEC_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800cec000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_LANE_DISABLED_VEC_0_15_scom0.insert<uint64_t>
        (LITERAL_0b0000000000000000, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_LANE_DISABLED_VEC_16_23_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800cf4000601103full,
                               IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_LANE_DISABLED_VEC_16_23_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800cf4000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_LANE_DISABLED_VEC_16_23_scom0.insert<uint64_t> (LITERAL_0b01111111, 48,
                8, 56 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220000601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220010601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220020601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220030601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220040601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220050601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220060601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220070601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220080601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220090601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002200a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002200a0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002200b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002200b0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002200c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002200c0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002200d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002200d0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002200e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002200e0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002200f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002200f0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220100601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800220110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800220110601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0.insert<uint64_t> (LITERAL_ON, 48, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008000601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008010601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008020601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008030601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008040601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008050601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008060601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008070601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008080601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008090601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000080a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000080a0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000080b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000080b0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000080c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000080c0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000080d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000080d0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000080e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000080e0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000080f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000080f0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008100601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_OFF,
                54, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800008110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800008110601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0.insert<uint64_t> (LITERAL_ON, 54,
                1, 63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404000601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404010601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404010601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404020601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404020601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404030601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404030601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404040601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404040601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404050601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404050601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404060601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404060601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404070601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404070601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404080601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404080601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404090601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404090601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004040a0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004040a0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004040b0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004040b0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004040c0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004040c0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004040d0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004040d0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004040e0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004040e0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004040f0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004040f0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800404100601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800404100601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0.insert<uint64_t> (LITERAL_ENABLED, 48, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_CLKDIST_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800810000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_CLKDIST_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800810000601103f)");
            break;
        }

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_CLKDIST_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_CLKDIST_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800c14000601103full, IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_CLKDIST_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800c14000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_CLKDIST_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 48, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PDWN_LITE_DISABLE_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800990000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PDWN_LITE_DISABLE_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800990000601103f)");
            break;
        }

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PDWN_LITE_DISABLE_scom0.insert<uint64_t> (LITERAL_ON, 58, 1, 63 );

        IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_CLKDIST_PDWN_scom0.insert<uint64_t> (LITERAL_ON, 59, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0000601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_A_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0010601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_B_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0020601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_C_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0030601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_D_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0040601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_E_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0050601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_F_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0060601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_G_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0070601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_H_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0080601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_A_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0090601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_H_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c00a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c00a0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_G_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c00b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c00b0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_F_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c00c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c00c0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_E_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c00d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c00d0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_D_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c00e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c00e0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_C_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c00f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c00f0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_B_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c0100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c0100601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_A_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8000601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_A_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8010601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_B_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8020601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_C_12_ACGH_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8030601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_D_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8040601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_EF_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8050601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_EF_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8060601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_GH_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8070601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_GH_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8080601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_A_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8090601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_GH_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c80a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c80a0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_GH_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c80b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c80b0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_EF_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c80c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c80c0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_EF_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c80d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c80d0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_D_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c80e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c80e0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_C_12_ACGH_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c80f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c80f0601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_B_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8002c8100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8002c8100601103f)");
            break;
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_24_A_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c000601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c010601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c010601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c020601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c020601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_C_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c030601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c030601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_D_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c040601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c040601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_E_HALF_B_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c050601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c050601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_F_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c060601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c060601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_G_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c070601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c070601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_H_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c080601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c080601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c090601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c090601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_H_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c0a0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c0a0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_G_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c0b0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c0b0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_F_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c0c0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c0c0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_E_HALF_B_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c0d0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c0d0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_D_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c0e0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c0e0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_C_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c0f0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c0f0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80043c100601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80043c100601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_AB_HALF_A_0_15, 48, 16, 48 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444000601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_A_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444010601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444010601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_B_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444020601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444020601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_C_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444030601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444030601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_DG_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444040601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444040601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_E_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444050601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444050601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_F_HALF_A_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444060601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444060601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_DG_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444070601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444070601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_H_HALF_B_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444080601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444080601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_A_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444090601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444090601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_H_HALF_B_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004440a0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004440a0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_DG_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004440b0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004440b0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_F_HALF_A_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004440c0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004440c0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_E_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004440d0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004440d0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_DG_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004440e0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004440e0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_C_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8004440f0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8004440f0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_B_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800444100601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800444100601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0.insert<uint64_t>
        (LITERAL_PATTERN_TX_A_16_22, 48, 7, 57 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_WTR_MAX_BAD_LANES_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800998000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_WTR_MAX_BAD_LANES_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800998000601103f)");
            break;
        }

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_WTR_MAX_BAD_LANES_scom0.insert<uint64_t> (LITERAL_0b00001, 48, 5, 59 );

        IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_CLKDIST_PDWN_scom0.insert<uint64_t> (LITERAL_0b00001, 53, 5, 59 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PEAK_TUNE_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8008c0000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PEAK_TUNE_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8008c0000601103f)");
            break;
        }

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PEAK_TUNE_scom0.insert<uint64_t> (LITERAL_OFF, 55, 1, 63 );

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PEAK_TUNE_scom0.insert<uint64_t> (LITERAL_OFF, 56, 1, 63 );

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PEAK_TUNE_scom0.insert<uint64_t> (LITERAL_0b11, 57, 2, 62 );

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PEAK_TUNE_scom0.insert<uint64_t> (LITERAL_ON, 59, 1, 63 );

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PEAK_TUNE_scom0.insert<uint64_t> (LITERAL_ON, 60, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXCTL_DATASM_DATASM_REGS_RX_CTL_DATASM_CLKDIST_PDWN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800b80000601103full,
                               IOF1_RX_RX0_RXCTL_DATASM_DATASM_REGS_RX_CTL_DATASM_CLKDIST_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800b80000601103f)");
            break;
        }

        IOF1_RX_RX0_RXCTL_DATASM_DATASM_REGS_RX_CTL_DATASM_CLKDIST_PDWN_scom0.insert<uint64_t> (LITERAL_OFF, 60, 1, 63 );

        ATTR_IS_SIMULATION_Type iv_TGT1_ATTR_IS_SIMULATION;
        l_rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, TGT1, iv_TGT1_ATTR_IS_SIMULATION);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (iv_TGT1_ATTR_IS_SIMULATION)");
            break;
        }

        auto iv_def_IS_HW = (iv_TGT1_ATTR_IS_SIMULATION == ATTR_IS_SIMULATION_ATTRIBUTE_VALUE_0);
        auto iv_def_IS_SIM = (iv_TGT1_ATTR_IS_SIMULATION == ATTR_IS_SIMULATION_ATTRIBUTE_VALUE_1);
        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_PG_SPARE_MODE_8_9_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800c04000601103full,
                               IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_PG_SPARE_MODE_8_9_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800c04000601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_PG_SPARE_MODE_8_9_scom0.insert<uint64_t> (LITERAL_0b00, 56, 2, 62 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_PG_SPARE_MODE_8_9_scom0.insert<uint64_t> (LITERAL_0b01, 56, 2, 62 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000000d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000000d0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000280d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000280d0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000300d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000300d0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c00d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c00d0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000000f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000000f0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000280f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000280f0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000300f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000300f0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c00f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c00f0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000000e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000000e0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000280e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000280e0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000300e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000300e0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c00e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c00e0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000100601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028100601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030100601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0100601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000000b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000000b0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000280b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000280b0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000300b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000300b0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c00b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c00b0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000090601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028090601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030090601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0090601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000000c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000000c0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000280c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000280c0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000300c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000300c0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c00c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c00c0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000000a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000000a0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000280a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000280a0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000300a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000300a0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c00a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c00a0601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000070601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028070601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030070601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0070601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000110601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028110601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030110601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0110601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000060601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028060601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030060601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0060601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000080601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028080601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030080601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0080601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000040601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028040601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030040601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0040601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000020601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028020601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030020601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0020601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000050601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028050601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030050601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0050601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000030601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028030601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030030601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0030601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000000601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028000601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030000601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0000601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        fapi2::buffer<uint64_t>
        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800000010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800000010601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_OFF, 53, 1, 63 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
            (LITERAL_ON, 53, 1, 63 );
        }

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 54, 1, 63 );

        IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0.insert<uint64_t>
        (LITERAL_OFF, 55, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800028010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800028010601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0000, 48, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b0110, 48, 4, 60 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 52, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 52, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b00000, 57, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0.insert<uint64_t>
            (LITERAL_0b01111, 57, 5, 59 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800030010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800030010601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b00000,
                    48, 5, 59 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b01100,
                    48, 5, 59 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b0000,
                    53, 4, 60 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0.insert<uint64_t> (LITERAL_0b1011,
                    53, 4, 60 );
        }

        fapi2::buffer<uint64_t> IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x8000c0010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x8000c0010601103f)");
            break;
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000000, 48, 7, 57 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b0000011, 48, 7, 57 );
        }

        if (iv_def_IS_HW)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b000000, 55, 6, 58 );
        }
        else if (iv_def_IS_SIM)
        {
            IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0.insert<uint64_t>
            (LITERAL_0b100111, 55, 6, 58 );
        }

        IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PDWN_LITE_DISABLE_scom0.insert<uint64_t> (LITERAL_FENCED, 57, 1, 63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DRV_CLK_PATTERN_GCRMSG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x800c24000601103full,
                               IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DRV_CLK_PATTERN_GCRMSG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x800c24000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DRV_CLK_PATTERN_GCRMSG_scom0.insert<uint64_t> (LITERAL_DRV_0S, 48, 2,
                62 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c000601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c000601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c010601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c010601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c020601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c020601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c030601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c030601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c040601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c040601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c050601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c050601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c060601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c060601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c070601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c070601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c080601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c080601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c090601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c090601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c0a0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c0a0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c0b0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c0b0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c0c0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c0c0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c0d0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c0d0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c0e0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c0e0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c0f0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c0f0601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );

        fapi2::buffer<uint64_t> IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0;
        l_rc = fapi2::getScom( TGT0, 0x80040c100601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x80040c100601103f)");
            break;
        }

        IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0.insert<uint64_t> (LITERAL_ON, 62, 1,
                63 );


        l_rc = fapi2::putScom( TGT0, 0x800000000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000000a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000000a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000000b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000000b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000000c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000000c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000000d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000000d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000000e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000000e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000000f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000000f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800000110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800000110601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000080a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000080a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000080b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000080b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000080c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000080c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000080d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000080d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000080e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000080e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000080f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000080f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800008110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800008110601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000280a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000280a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000280b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000280b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000280c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000280c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000280d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000280d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000280e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000280e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000280f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000280f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800028110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_INTEG_COARSE_GAIN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800028110601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000300a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000300a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000300b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000300b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000300c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000300c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000300d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000300d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000300e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000300e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000300f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000300f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800030110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_CTLE_PEAK_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800030110601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c00a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c00a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c00b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c00b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c00c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c00c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c00d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c00d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c00e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c00e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c00f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c00f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8000c0110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_A_H1ARATIO_VAL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8000c0110601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002200a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002200a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002200b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002200b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002200c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002200c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002200d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002200d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002200e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002200e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002200f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002200f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800220110601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800220110601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c00a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c00a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c00b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c00b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c00c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c00c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c00d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c00d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c00e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c00e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c00f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c00f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c0100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c0100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8000601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_4_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8010601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_5_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8020601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8030601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8040601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8050601103full,
                               IOF1_RX_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8060601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8070601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8080601103full,
                               IOF1_RX_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8090601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c80a0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c80a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c80b0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c80b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c80c0601103full,
                               IOF1_RX_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c80c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c80d0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c80d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c80e0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c80e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c80f0601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c80f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8002c8100601103full,
                               IOF1_RX_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8002c8100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404000601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404010601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404020601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404030601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404040601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404050601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404060601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404070601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404080601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404090601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004040a0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004040a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004040b0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004040b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004040c0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004040c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004040d0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004040d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004040e0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004040e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004040f0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004040f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800404100601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_LANE_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800404100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c000601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c010601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c020601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c030601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c040601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c050601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c060601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c070601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c080601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c090601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c0a0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c0a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c0b0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c0b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c0c0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c0c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c0d0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c0d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c0e0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c0e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c0f0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c0f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80040c100601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80040c100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c000601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c010601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c020601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c030601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c040601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c050601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c060601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c070601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c080601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c090601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c0a0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c0a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c0b0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c0b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c0c0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c0c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c0d0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c0d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c0e0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c0e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c0f0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c0f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x80043c100601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x80043c100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444000601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444010601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444010601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444020601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444020601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444030601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444030601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444040601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444040601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444050601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444050601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444060601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444060601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444070601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444070601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444080601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444080601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444090601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444090601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004440a0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004440a0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004440b0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004440b0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004440c0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004440c0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004440d0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004440d0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004440e0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004440e0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8004440f0601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8004440f0601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800444100601103full,
                               IOF1_TX_WRAP_TX0_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800444100601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800808000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_BUS_ID_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800808000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800810000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_CLKDIST_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800810000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8008c0000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PEAK_TUNE_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8008c0000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800980000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_START_LANE_ID_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800980000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800990000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PDWN_LITE_DISABLE_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800990000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800998000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_WTR_MAX_BAD_LANES_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800998000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8009b8000601103full, IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_TX_BUS_WIDTH_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8009b8000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8009e0000601103full,
                               IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_LANE_DISABLED_VEC_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8009e0000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x8009e8000601103full,
                               IOF1_RX_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_LANE_DISABLED_VEC_16_23_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x8009e8000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800b80000601103full,
                               IOF1_RX_RX0_RXCTL_DATASM_DATASM_REGS_RX_CTL_DATASM_CLKDIST_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800b80000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800c04000601103full,
                               IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_PG_SPARE_MODE_8_9_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800c04000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800c0c000601103full, IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_BUS_ID_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800c0c000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800c14000601103full, IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_CLKDIST_PDWN_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800c14000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800c1c000601103full, IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_BUS_WIDTH_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800c1c000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800c24000601103full,
                               IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DRV_CLK_PATTERN_GCRMSG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800c24000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800c84000601103full,
                               IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_START_LANE_ID_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800c84000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800cec000601103full,
                               IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_LANE_DISABLED_VEC_0_15_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800cec000601103f)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x800cf4000601103full,
                               IOF1_TX_WRAP_TX0_TXCTL_CTL_REGS_TX_CTL_REGS_TX_LANE_DISABLED_VEC_16_23_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x800cf4000601103f)");
            break;
        }

    }
    while(0);

    return l_rc;
}

