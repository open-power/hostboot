/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/initfiles/centaur_dmi_scom.C $ */
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
#include "centaur_dmi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_256 = 256;
constexpr uint64_t literal_0b000000 = 0b000000;
constexpr uint64_t literal_0b0000000 = 0b0000000;
constexpr uint64_t literal_0b0010000 = 0b0010000;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b0000000000000000 = 0b0000000000000000;
constexpr uint64_t literal_0b0111111111111111 = 0b0111111111111111;
constexpr uint64_t literal_0b00010 = 0b00010;
constexpr uint64_t literal_0b0011000 = 0b0011000;
constexpr uint64_t literal_0b0010001 = 0b0010001;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0b11 = 0b11;
constexpr uint64_t literal_0b1000000 = 0b1000000;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b0111 = 0b0111;
constexpr uint64_t literal_0b0011 = 0b0011;
constexpr uint64_t literal_0b0111111 = 0b0111111;
constexpr uint64_t literal_0b00000011 = 0b00000011;
constexpr uint64_t literal_0b00000000 = 0b00000000;
constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0b100 = 0b100;
constexpr uint64_t literal_0b100000 = 0b100000;
constexpr uint64_t literal_0b0010111 = 0b0010111;
constexpr uint64_t literal_0b0000000011111111 = 0b0000000011111111;
constexpr uint64_t literal_0b00100 = 0b00100;
constexpr uint64_t literal_0b0010101 = 0b0010101;
constexpr uint64_t literal_0b0010110 = 0b0010110;
constexpr uint64_t literal_0b1000110 = 0b1000110;

fapi2::ReturnCode centaur_dmi_scom(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_HW = (l_TGT1_ATTR_IS_SIMULATION == literal_0);
        uint64_t l_def_IS_SIM = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        fapi2::ATTR_EI_BUS_TX_MSBSWAP_Type l_TGT0_ATTR_EI_BUS_TX_MSBSWAP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EI_BUS_TX_MSBSWAP, TGT0, l_TGT0_ATTR_EI_BUS_TX_MSBSWAP));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0000201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_A = 0x0;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0010201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_B = 0x1;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_B );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0010201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0020201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_C = 0x2;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_C );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0020201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0030201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_D = 0x3;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_D );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0030201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0040201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_E = 0x4;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_E );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0040201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0050201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_F = 0x5;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_F );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0050201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0060201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_G = 0x6;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_G );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0060201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0070201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_H = 0x7;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_H );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0070201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0080201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_A = 0x0;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0080201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0090201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_H = 0x7;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_H );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0090201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b00a0201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_G = 0x6;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_G );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b00a0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b00b0201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_F = 0x5;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_F );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b00b0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b00c0201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_E = 0x4;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_E );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b00c0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b00d0201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_D = 0x3;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_D );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b00d0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b00e0201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_C = 0x2;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_C );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b00e0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b00f0201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_B = 0x1;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_B );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b00f0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0100201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_A = 0x0;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0100201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000b0110201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_A = 0x0;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_TAP_ID_PATTERN_A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000b0110201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434000201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_A = 0x0;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434010201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_B = 0x1;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_B );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434010201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434020201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_C = 0x2;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_C );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434020201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434030201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_D = 0x3;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_D );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434030201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434040201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_E = 0x4;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_E );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434040201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434050201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_F = 0x5;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_F );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434050201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434060201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_G = 0x6;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_G );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434060201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434070201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_H = 0x7;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_H );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434070201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434080201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_A = 0x0;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434080201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434090201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_SLICE_3_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_B = 0x1;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_SLICE_3_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_B );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434090201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004340a0201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_C = 0x2;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_C );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004340a0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004340b0201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_D = 0x3;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_D );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004340b0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004340c0201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_D = 0x3;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_D );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004340c0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004340d0201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_SLICE_3_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_C = 0x2;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_SLICE_3_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_C );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004340d0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004340e0201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_B = 0x1;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_B );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004340e0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004340f0201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_A = 0x0;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004340f0201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434100201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_H = 0x7;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_H );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434100201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434110201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_SLICE_3_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_G = 0x6;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_SLICE_3_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_G );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434110201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434120201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_SLICE_4_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_F = 0x5;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_SLICE_4_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_F );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434120201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434130201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_E = 0x4;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_SLICE_0_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_E );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434130201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434140201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_D = 0x3;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_SLICE_1_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_D );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434140201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434150201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_C = 0x2;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_SLICE_2_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_C );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434150201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434160201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_SLICE_3_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_B = 0x1;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_SLICE_3_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_B );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434160201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800434170201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_SLICE_4_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_A = 0x0;
            l_scom_buffer.insert<48, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_SLICE_4_TD_TX_BIT_REGS_TX_PRBS_TAP_ID_PATTERN_A );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800434170201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800850000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800850000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800858000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800858000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800860000201043full, l_scom_buffer ));

            l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0b0000000 );
            l_scom_buffer.insert<57, 7, 57, uint64_t>(literal_0b0010000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800860000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800898000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DS_BL_TIMEOUT_SEL_TAP5 = 0x5;
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DS_BL_TIMEOUT_SEL_TAP5 );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DS_BL_TIMEOUT_SEL_TAP1 = 0x1;
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DS_BL_TIMEOUT_SEL_TAP1 );
            }

            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DS_TIMEOUT_SEL_TAP7 = 0x7;
            l_scom_buffer.insert<61, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DS_TIMEOUT_SEL_TAP7 );

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_TIMEOUT_SEL_TAP7 = 0x7;
                l_scom_buffer.insert<58, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_TIMEOUT_SEL_TAP7 );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_TIMEOUT_SEL_TAP3 = 0x3;
                l_scom_buffer.insert<58, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_TIMEOUT_SEL_TAP3 );
            }

            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SLS_TIMEOUT_SEL_TAP10 = 0xa;
            l_scom_buffer.insert<48, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SLS_TIMEOUT_SEL_TAP10 );
            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_CL_TIMEOUT_SEL_TAP7 = 0x7;
            l_scom_buffer.insert<55, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_CL_TIMEOUT_SEL_TAP7 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800898000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800910000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_AMP_TIMEOUT_SEL_TAP7 = 0x7;
                l_scom_buffer.insert<51, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_AMP_TIMEOUT_SEL_TAP7 );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_AMP_TIMEOUT_SEL_TAP6 = 0x6;
                l_scom_buffer.insert<51, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_AMP_TIMEOUT_SEL_TAP6 );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_CTLE_TIMEOUT_SEL_TAP7 = 0x7;
                l_scom_buffer.insert<54, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_CTLE_TIMEOUT_SEL_TAP7 );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_CTLE_TIMEOUT_SEL_TAP6 = 0x6;
                l_scom_buffer.insert<54, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_CTLE_TIMEOUT_SEL_TAP6 );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_DDC_TIMEOUT_SEL_TAP6 = 0x6;
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_DDC_TIMEOUT_SEL_TAP6 );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_DDC_TIMEOUT_SEL_TAP5 = 0x5;
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_DDC_TIMEOUT_SEL_TAP5 );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_H1AP_TIMEOUT_SEL_TAP7 = 0x7;
                l_scom_buffer.insert<57, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_H1AP_TIMEOUT_SEL_TAP7 );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_H1AP_TIMEOUT_SEL_TAP6 = 0x6;
                l_scom_buffer.insert<57, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_H1AP_TIMEOUT_SEL_TAP6 );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_OFFSET_TIMEOUT_SEL_TAP7 = 0x7;
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_OFFSET_TIMEOUT_SEL_TAP7 );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_OFFSET_TIMEOUT_SEL_TAP6 = 0x6;
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_OFFSET_TIMEOUT_SEL_TAP6 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800910000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800928000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0b0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800928000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800930000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0b0111111111111111 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800930000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800958000201043full, l_scom_buffer ));

            l_scom_buffer.insert<53, 5, 59, uint64_t>(literal_0b00010 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800958000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800998000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011000 );
            l_scom_buffer.insert<55, 7, 57, uint64_t>(literal_0b0010001 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800998000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009a8000201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_FENCE_FENCED = 0x1;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_FENCE_FENCED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8009a8000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009c0000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_PROT_SPEED_SLCT_ON = 0x1;
                l_scom_buffer.insert<51, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_PROT_SPEED_SLCT_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_PROT_SPEED_SLCT_OFF = 0x0;
                l_scom_buffer.insert<51, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_PROT_SPEED_SLCT_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8009c0000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009d8000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b1000000 );
            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DYN_RPR_ERR_CNTR1_DURATION_TAP2 = 0x2;
            l_scom_buffer.insert<55, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DYN_RPR_ERR_CNTR1_DURATION_TAP2 );
            l_scom_buffer.insert<61, 3, 61, uint64_t>(literal_0b101 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8009d8000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800a18000201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DYN_RECAL_OVERALL_TIMEOUT_SEL_TAP4 = 0x4;
            l_scom_buffer.insert<48, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DYN_RECAL_OVERALL_TIMEOUT_SEL_TAP4 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800a18000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800a30000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_CU_PLL_RESET_NOT_ENABLE = 0x0;
                l_scom_buffer.insert<49, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_CU_PLL_RESET_NOT_ENABLE );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_CU_PLL_RESET_ENABLE = 0x1;
                l_scom_buffer.insert<49, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_CU_PLL_RESET_ENABLE );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_CU_PLL_PGOODDLY_MAX = 0x6;
                l_scom_buffer.insert<50, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_CU_PLL_PGOODDLY_MAX );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_CU_PLL_PGOODDLY_16UI = 0x0;
                l_scom_buffer.insert<50, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_CU_PLL_PGOODDLY_16UI );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800a30000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800a38000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_LATCH_OFFSET_CAL_ON = 0x1;
                l_scom_buffer.insert<48, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_LATCH_OFFSET_CAL_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_LATCH_OFFSET_CAL_OFF = 0x0;
                l_scom_buffer.insert<48, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_LATCH_OFFSET_CAL_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_CTLE_CAL_ON = 0x1;
                l_scom_buffer.insert<49, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_CTLE_CAL_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_CTLE_CAL_OFF = 0x0;
                l_scom_buffer.insert<49, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_CTLE_CAL_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_VGA_CAL_ON = 0x1;
                l_scom_buffer.insert<50, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_VGA_CAL_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_VGA_CAL_OFF = 0x0;
                l_scom_buffer.insert<50, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_VGA_CAL_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_DFE_H1_CAL_ON = 0x1;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_DFE_H1_CAL_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_DFE_H1_CAL_OFF = 0x0;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_DFE_H1_CAL_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_H1AP_TWEAK_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_H1AP_TWEAK_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_H1AP_TWEAK_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_H1AP_TWEAK_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_DDC_ON = 0x1;
                l_scom_buffer.insert<54, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_DDC_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_DDC_OFF = 0x0;
                l_scom_buffer.insert<54, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_DDC_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_BER_TEST_ON = 0x1;
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_BER_TEST_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_BER_TEST_OFF = 0x0;
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_BER_TEST_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_RESULT_CHECK_ON = 0x1;
                l_scom_buffer.insert<58, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_RESULT_CHECK_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_RESULT_CHECK_OFF = 0x0;
                l_scom_buffer.insert<58, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_RESULT_CHECK_OFF );
            }

            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_FINAL_L2U_ADJ_ON = 0x1;
            l_scom_buffer.insert<56, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_EO_ENABLE_FINAL_L2U_ADJ_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800a38000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800a80000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800a80000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800aa8000201043full, l_scom_buffer ));

            l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800aa8000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800ab8000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_LATCH_OFFSET_CAL_ON = 0x1;
                l_scom_buffer.insert<48, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_LATCH_OFFSET_CAL_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_LATCH_OFFSET_CAL_OFF = 0x0;
                l_scom_buffer.insert<48, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_LATCH_OFFSET_CAL_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_CTLE_CAL_ON = 0x1;
                l_scom_buffer.insert<49, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_CTLE_CAL_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_CTLE_CAL_OFF = 0x0;
                l_scom_buffer.insert<49, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_CTLE_CAL_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_VGA_CAL_ON = 0x1;
                l_scom_buffer.insert<50, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_VGA_CAL_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_VGA_CAL_OFF = 0x0;
                l_scom_buffer.insert<50, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_VGA_CAL_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_DFE_H1_CAL_ON = 0x1;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_DFE_H1_CAL_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_DFE_H1_CAL_OFF = 0x0;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_DFE_H1_CAL_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_H1AP_TWEAK_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_H1AP_TWEAK_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_H1AP_TWEAK_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_H1AP_TWEAK_OFF );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_DDC_ON = 0x1;
                l_scom_buffer.insert<54, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_DDC_ON );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_DDC_OFF = 0x0;
                l_scom_buffer.insert<54, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_DDC_OFF );
            }

            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_BER_TEST_ON = 0x1;
            l_scom_buffer.insert<56, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_BER_TEST_ON );
            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_RESULT_CHECK_ON = 0x1;
            l_scom_buffer.insert<57, 1, 63, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RC_ENABLE_RESULT_CHECK_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800ab8000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800ae0000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0111111 );
            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DYN_RPR_ERR_CNTR2_DURATION_TAP7 = 0x7;
            l_scom_buffer.insert<55, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DYN_RPR_ERR_CNTR2_DURATION_TAP7 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800ae0000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800af0000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0b00000011 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0b00000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800af0000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800b08000201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800b08000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800b40000201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800b40000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800b60000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI = 0xa;
                l_scom_buffer.insert<52, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI = 0xa;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI = 0xa;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI = 0xa;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI = 0xa;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI = 0xa;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI = 0xa;
                l_scom_buffer.insert<60, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI = 0xa;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI = 0xa;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI = 0xa;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI = 0xa;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI = 0xa;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_256KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_D_64KUI );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800b60000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800b68000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_H_64KUI );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800b68000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800b70000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI = 0xd;
                l_scom_buffer.insert<52, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI = 0xd;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI = 0xd;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI = 0xd;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI = 0xd;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI = 0xd;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI = 0xd;
                l_scom_buffer.insert<56, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI = 0xd;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI = 0xd;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI = 0xd;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI = 0xd;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI = 0xd;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_2MUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_SERVO_TIMEOUT_SEL_K_64KUI );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800b70000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800b78000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800b78000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800b80000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b011 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b011 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b011 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b011 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b011 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b011 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b100 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b100 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b100 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b100 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b100 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b100 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b101 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b101 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b101 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b101 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b101 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b101 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<61, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800b80000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800b90000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI = 0x6;
                l_scom_buffer.insert<52, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI = 0x6;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI = 0x6;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI = 0x6;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI = 0x6;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI = 0x6;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_16KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_B_64KUI );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800b90000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800b98000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI = 0x7;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_32KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI = 0x4;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_G_4KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI = 0xb;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI = 0x8;
                l_scom_buffer.insert<60, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_H_64KUI );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800b98000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800ba0000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI = 0xb;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI = 0x8;
                l_scom_buffer.insert<48, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_I_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI = 0xb;
                l_scom_buffer.insert<52, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI = 0xb;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI = 0xb;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI = 0xb;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI = 0xb;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI = 0xb;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI = 0x8;
                l_scom_buffer.insert<52, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_J_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI = 0xb;
                l_scom_buffer.insert<56, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI = 0xb;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI = 0xb;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI = 0xb;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI = 0xb;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI );
            }

            if (l_def_IS_HW)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI = 0xb;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_512KUI );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI = 0x8;
                l_scom_buffer.insert<56, 4, 60, uint64_t>
                (l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_RECAL_TIMEOUT_SEL_K_64KUI );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800ba0000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800bb0000201043full, l_scom_buffer ));

            constexpr auto l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<62, 2, 62, uint64_t>(l_DMI_RX_RXCTL_RX_CTL_REGS_RX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<62, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_0_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<62, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_1_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<62, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_2_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<62, 2, 62, uint64_t>
            (l_DMI_RX_RXPACKS_3_RXPACK_DEFAULT_RXPACK_RD_RX_DATA_REGS_RX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<62, 2, 62, uint64_t>(l_DMI_RX_RXPACKS_4_RXPACK_4_RXPACK_RD_RX_DATA_REGS_RX_WT_PATTERN_LENGTH_256 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800bb0000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c1c000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00010 );

            if ((l_TGT0_ATTR_EI_BUS_TX_MSBSWAP != fapi2::ENUM_ATTR_EI_BUS_TX_MSBSWAP_NO_SWAP))
            {
                constexpr auto l_DMI_TX_TXCTL_TX_CTL_REGS_TX_MSBSWAP_MSBSWAP = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>(l_DMI_TX_TXCTL_TX_CTL_REGS_TX_MSBSWAP_MSBSWAP );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800c1c000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c94000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800c94000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c9c000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b100000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800c9c000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800ca4000201043full, l_scom_buffer ));

            l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0b0000000 );
            l_scom_buffer.insert<57, 7, 57, uint64_t>(literal_0b0010111 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800ca4000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800cc4000201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXCTL_TX_CTL_REGS_TX_DRV_CLK_PATTERN_GCRMSG_DRV_0S = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>(l_DMI_TX_TXCTL_TX_CTL_REGS_TX_DRV_CLK_PATTERN_GCRMSG_DRV_0S );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800cc4000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800d1c000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0b0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800d1c000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800d24000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0b0000000011111111 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800d24000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800e84000201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXCTL_TX_CTL_REGS_TX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<48, 2, 62, uint64_t>(l_DMI_TX_TXCTL_TX_CTL_REGS_TX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<48, 2, 62, uint64_t>(l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<48, 2, 62, uint64_t>(l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<48, 2, 62, uint64_t>(l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 );
            constexpr auto l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 = 0x1;
            l_scom_buffer.insert<48, 2, 62, uint64_t>(l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_TX_DATA_REGS_TX_WT_PATTERN_LENGTH_256 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800e84000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800e8c000201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXCTL_TX_CTL_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>(l_DMI_TX_TXCTL_TX_CTL_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            constexpr auto l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_TX_DATA_REGS_TX_REDUCED_SCRAMBLE_MODE_DISABLE_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800e8c000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800eac000201043full, l_scom_buffer ));

            constexpr auto l_DMI_TX_TXCTL_TX_CTL_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>(l_DMI_TX_TXCTL_TX_CTL_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<49, 3, 61, uint64_t>
            (l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_DMI_TX_TXCTL_TX_CTL_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>(l_DMI_TX_TXCTL_TX_CTL_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_0_TXPACK_0_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_1_TXPACK_1_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_2_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_3_TXPACK_DEFAULT_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_4_TXPACK_4_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            constexpr auto l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<52, 2, 62, uint64_t>
            (l_DMI_TX_TXPACKS_5_TXPACK_5_TXPACK_DD_TX_DATA_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800eac000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800f1c000201043full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800f1c000201043full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800f2c000201043full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0010101 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0010110 );
            }

            l_scom_buffer.insert<55, 7, 57, uint64_t>(literal_0b1000110 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800f2c000201043full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
