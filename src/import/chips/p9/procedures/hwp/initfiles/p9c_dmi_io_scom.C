/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9c_dmi_io_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include "p9c_dmi_io_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b0000 = 0b0000;
constexpr uint64_t literal_0b1111 = 0b1111;
constexpr uint64_t literal_0b00000 = 0b00000;
constexpr uint64_t literal_0b01111 = 0b01111;
constexpr uint64_t literal_0b01100 = 0b01100;
constexpr uint64_t literal_0b0111 = 0b0111;
constexpr uint64_t literal_0b1011 = 0b1011;
constexpr uint64_t literal_0b0000000 = 0b0000000;
constexpr uint64_t literal_0b0011001 = 0b0011001;
constexpr uint64_t literal_0b000000 = 0b000000;
constexpr uint64_t literal_0b100111 = 0b100111;
constexpr uint64_t literal_0b000001 = 0b000001;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0b000010 = 0b000010;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_0b000011 = 0b000011;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_0b000100 = 0b000100;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_0b000101 = 0b000101;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_0b000110 = 0b000110;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_0b000111 = 0b000111;
constexpr uint64_t literal_0b1010 = 0b1010;
constexpr uint64_t literal_0b11 = 0b11;
constexpr uint64_t literal_0b0010111 = 0b0010111;
constexpr uint64_t literal_0b00010 = 0b00010;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b0010 = 0b0010;
constexpr uint64_t literal_0b0010001 = 0b0010001;
constexpr uint64_t literal_0b0011000 = 0b0011000;
constexpr uint64_t literal_0b0001111 = 0b0001111;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b0111111 = 0b0111111;
constexpr uint64_t literal_0b0000000000000000 = 0b0000000000000000;
constexpr uint64_t literal_0b00000000 = 0b00000000;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_0b1100 = 0b1100;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0b0010000 = 0b0010000;

fapi2::ReturnCode p9c_dmi_io_scom(const fapi2::Target<fapi2::TARGET_TYPE_DMI>& TGT0,
                                  const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_HW = (l_TGT1_ATTR_IS_SIMULATION == literal_0);
        uint64_t l_def_IS_SIM = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT0_ATTR_CHIP_UNIT_POS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT0, l_TGT0_ATTR_CHIP_UNIT_POS));
        uint64_t l_def_POSITION = l_TGT0_ATTR_CHIP_UNIT_POS;
        uint64_t l_def_is_master = literal_1;
        fapi2::ATTR_EI_BUS_TX_MSBSWAP_Type l_TGT0_ATTR_EI_BUS_TX_MSBSWAP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EI_BUS_TX_MSBSWAP, TGT0, l_TGT0_ATTR_EI_BUS_TX_MSBSWAP));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000600701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000610701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000620701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000630701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000640701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000650701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000660701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000670701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000680701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000690701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000006a0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000006a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000006b0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000006b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000006c0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000006c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000006d0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000006d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000006e0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000006e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000006f0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000006f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000700701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000710701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000710701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000720701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000720701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000730701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000730701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000740701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000750701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000760701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000760701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000770701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON = 0x1;
                l_scom_buffer.insert<53, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_ON );
            }

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000770701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008610701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008620701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008630701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008640701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008650701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008660701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008670701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008680701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008690701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000086a0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000086a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000086b0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000086b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000086c0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000086c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000086d0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000086d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000086e0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000086e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000086f0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000086f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008700701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008710701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008710701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008720701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008720701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008730701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008730701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008740701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008750701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008760701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008760701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008770701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_LANE_ANA_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800008770701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028600701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028610701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028620701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028630701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028640701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028650701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028660701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028670701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028680701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028690701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000286a0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000286a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000286b0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000286b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000286c0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000286c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000286d0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000286d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000286e0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000286e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000286f0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000286f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028700701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028710701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028710701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028720701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028720701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028730701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028730701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028740701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028750701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028760701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028760701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028770701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800028770701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030610701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030620701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030630701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030640701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030650701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030660701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030670701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030680701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030690701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000306a0701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000306a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000306b0701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000306b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000306c0701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000306c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000306d0701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000306d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000306e0701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000306e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000306f0701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000306f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030700701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030710701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030710701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030720701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030720701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030730701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030730701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030740701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030750701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030760701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030760701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030770701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01100 );

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800030770701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0600701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0610701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0620701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0630701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0640701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0650701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0660701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0670701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0680701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0690701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c06a0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c06a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c06b0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c06b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c06c0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c06c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c06d0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c06d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c06e0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c06e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c06f0701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c06f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0700701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0710701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0710701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0720701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0720701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0730701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0730701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0740701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0750701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0760701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0760701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0770701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0011001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0770701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220610701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220620701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220630701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220640701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220650701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220660701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220670701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220680701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220690701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002206a0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002206a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002206b0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002206b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002206c0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002206c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002206d0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002206d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002206e0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002206e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002206f0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002206f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220700701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220710701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220710701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220720701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220720701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220730701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220730701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220740701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220750701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220760701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220760701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800220770701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_LANE_DIG_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SYNC_MODE_ON );
            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800220770701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_A_0_15 = 0x8400;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_A_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0610701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_B_0_15 = 0x7c00;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_B_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0620701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_C_0_15 = 0xf;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_C_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0630701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_D_0_15 = 0xc00f;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_D_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0640701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_E_0_15 = 0x8007;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_E_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0650701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_F_0_15 = 0x803f;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_F_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0660701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_G_0_15 = 0x600;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_G_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0670701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_H_0_15 = 0x700;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_H_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0680701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_A_0_15 = 0x8400;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_A_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0690701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_B_0_15 = 0x7c00;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_B_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c06a0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_C_0_15 = 0xf;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_C_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c06a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c06b0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_D_0_15 = 0xc00f;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_D_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c06b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c06c0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_D_0_15 = 0xc00f;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_D_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c06c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c06d0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_C_0_15 = 0xf;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_C_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c06d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c06e0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_B_0_15 = 0x7c00;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_B_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c06e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c06f0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_A_0_15 = 0x8400;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_A_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c06f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0700701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_H_0_15 = 0x700;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_H_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0710701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_G_0_15 = 0x600;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_G_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0710701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0720701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_F_0_15 = 0x803f;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_F_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0720701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0730701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_E_0_15 = 0x8007;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_E_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0730701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0740701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_D_0_15 = 0xc00f;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_D_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0750701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_C_0_15 = 0xf;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_C_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0760701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_B_0_15 = 0x7c00;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_B_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0760701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c0770701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_A_0_15 = 0x8400;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_0_15_PATTERN_12_A_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c0770701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8610701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_B_16_22 = 0x3f;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_B_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8620701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8630701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_D_16_22 = 0x78;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_0_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_D_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8640701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_EF_16_22 =
                0x70;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_EF_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8650701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_EF_16_22 =
                0x70;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_EF_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8660701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8670701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_1_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8680701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8690701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_B_16_22 = 0x3f;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_B_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c86a0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c86a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c86b0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_D_16_22 = 0x78;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_2_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_D_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c86b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c86c0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_D_16_22 = 0x78;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_D_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c86c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c86d0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c86d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c86e0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_B_16_22 = 0x3f;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_B_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c86e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c86f0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_3_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c86f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8700701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8710701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8710701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8720701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_EF_16_22 =
                0x70;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_EF_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8720701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8730701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_EF_16_22 =
                0x70;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_4_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_EF_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8730701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8740701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_D_16_22 = 0x78;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_0_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_D_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8740701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8750701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_1_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8750701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8760701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_B_16_22 = 0x3f;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_2_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_12_B_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8760701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002c8770701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22
                = 0x0;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_RX3_RXPACKS_5_RXPACK_RD_SLICE_3_RD_RX_BIT_REGS_RX_PRBS_SEED_VALUE_16_22_PATTERN_24_C_12_ACGH_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002c8770701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404610701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404620701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404630701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404640701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404650701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404660701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404670701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404680701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404690701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004046a0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004046a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004046b0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004046b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004046c0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004046c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004046d0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004046d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004046e0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004046e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004046f0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004046f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800404700701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_LANE_PDWN_ENABLED );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800404700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c610701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c620701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c630701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c640701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c650701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c660701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c670701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c680701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c690701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c6a0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c6a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c6b0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c6b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c6c0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c6c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c6d0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c6d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c6e0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c6e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c6f0701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c6f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80040c700701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_CAL_LANE_SEL_ON );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_FIFO_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80040c700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c600701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_AB_HALF_A_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c610701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_E_HALF_B_0_15 = 0xf;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_E_HALF_B_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c620701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_C_0_15 = 0x1ef;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_C_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c630701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_D_0_15 = 0x1f1;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_D_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c640701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_E_0_15 = 0xfb;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_E_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c650701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_F_0_15 = 0x7c2;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_F_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c660701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_G_0_15 = 0xc631;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_G_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c670701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_H_0_15 = 0xe739;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_H_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c680701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_AB_HALF_A_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c690701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_H_0_15 = 0xe739;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_H_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c6a0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_G_0_15 = 0xc631;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_G_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c6a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c6b0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_F_0_15 = 0x7c2;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_F_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c6b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c6c0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_E_0_15 = 0xfb;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_E_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c6c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c6d0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_D_0_15 = 0x1f1;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_D_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c6d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c6e0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_C_0_15 = 0x1ef;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_HALF_C_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c6e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c6f0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_E_HALF_B_0_15 = 0xf;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_E_HALF_B_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c6f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80043c700701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_AB_HALF_A_0_15 = 0x0;
            l_scom_buffer.insert<48, 16, 48, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_0_15_PATTERN_TX_AB_HALF_A_0_15 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x80043c700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444600701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_F_HALF_A_16_22 = 0x10;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_F_HALF_A_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444610701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_H_HALF_B_16_22 = 0x4e;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_H_HALF_B_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444610701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444620701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_C_16_22 = 0x3d;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_C_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444620701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444630701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_DG_16_22 = 0x46;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_0_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_DG_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444630701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444640701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_E_16_22 = 0x6f;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_E_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444640701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444650701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_F_16_22 = 0x8;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_F_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444650701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444660701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_DG_16_22 = 0x46;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_DG_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444660701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444670701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_H_16_22 = 0x67;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_1_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_H_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444670701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444680701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_F_HALF_A_16_22 = 0x10;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_F_HALF_A_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444680701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444690701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_H_16_22 = 0x67;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_H_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444690701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004446a0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_DG_16_22 = 0x46;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_DG_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004446a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004446b0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_F_16_22 = 0x8;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_2_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_F_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004446b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004446c0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_E_16_22 = 0x6f;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_0_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_E_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004446c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004446d0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_DG_16_22 = 0x46;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_1_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_DG_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004446d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004446e0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_C_16_22 = 0x3d;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_2_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_HALF_C_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004446e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8004446f0701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_H_HALF_B_16_22 = 0x4e;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_3_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_H_HALF_B_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8004446f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800444700701103full, l_scom_buffer ));

            constexpr auto
            l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_F_HALF_A_16_22 = 0x10;
            l_scom_buffer.insert<48, 7, 57, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXPACKS_3_TXPACK_DD_SLICE_4_DD_TX_BIT_REGS_TX_PRBS_SEED_VALUE_16_22_PATTERN_TX_F_HALF_A_16_22 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800444700701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800800600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PG_SPARE_MODE_0_ON = 0x1;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PG_SPARE_MODE_0_ON );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PG_SPARE_MODE_1_OFF = 0x0;
            l_scom_buffer.insert<49, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PG_SPARE_MODE_1_OFF );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PG_SPARE_MODE_2_OFF = 0x0;
            l_scom_buffer.insert<50, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PG_SPARE_MODE_2_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800800600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800808600701103full, l_scom_buffer ));

            if ((l_def_POSITION == literal_0))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((l_def_POSITION == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000001 );
            }
            else if ((l_def_POSITION == literal_2))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000010 );
            }
            else if ((l_def_POSITION == literal_3))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000011 );
            }
            else if ((l_def_POSITION == literal_4))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000100 );
            }
            else if ((l_def_POSITION == literal_5))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000101 );
            }
            else if ((l_def_POSITION == literal_6))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if ((l_def_POSITION == literal_7))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800808600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800810600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_CLKDIST_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_CLKDIST_PDWN_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800810600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800830600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<51, 3, 61, uint64_t>
            (l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<54, 2, 62, uint64_t>
            (l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800830600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800840600701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1010 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800840600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008c0600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PEAK_TUNE_OFF = 0x0;
            l_scom_buffer.insert<55, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PEAK_TUNE_OFF );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_LTE_EN_OFF = 0x0;
            l_scom_buffer.insert<56, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_LTE_EN_OFF );
            l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b11 );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DFEHISPD_EN_ON = 0x1;
            l_scom_buffer.insert<59, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DFEHISPD_EN_ON );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DFE12_EN_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DFE12_EN_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8008c0600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800970600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RC_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL_ON = 0x1;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RC_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800970600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800980600701103full, l_scom_buffer ));

            l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0b0000000 );
            l_scom_buffer.insert<57, 7, 57, uint64_t>(literal_0b0010111 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800980600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800990600701103full, l_scom_buffer ));

            if (l_def_is_master)
            {
                constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_MASTER_MODE_MASTER = 0x1;
                l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_MASTER_MODE_MASTER );
            }

            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_FENCE_FENCED = 0x1;
            l_scom_buffer.insert<57, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_FENCE_FENCED );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PDWN_LITE_DISABLE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PDWN_LITE_DISABLE_ON );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RECAL_SUSPEND_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RECAL_SUSPEND_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800990600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800998600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00010 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800998600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009a0600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8009a0600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009b0600701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0010 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8009b0600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009b8600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0010001 );
            l_scom_buffer.insert<55, 7, 57, uint64_t>(literal_0b0011000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8009b8600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009c8600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0001111 );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RPR_ERR_CNTR1_DURATION_TAP5 = 0x5;
            l_scom_buffer.insert<55, 4, 60, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RPR_ERR_CNTR1_DURATION_TAP5 );
            l_scom_buffer.insert<61, 3, 61, uint64_t>(literal_0b101 );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RPR_DISABLE_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RPR_DISABLE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8009c8600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009d0600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0111111 );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RPR_ERR_CNTR2_DURATION_TAP5 = 0x5;
            l_scom_buffer.insert<55, 4, 60, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RPR_ERR_CNTR2_DURATION_TAP5 );
            constexpr auto l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RPR_DISABLE2_ON = 0x1;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DYN_RPR_DISABLE2_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8009d0600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009e0600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0b0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8009e0600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009e8600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0b00000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8009e8600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800a80600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXCTL_GLBSM_REGS_RX_DESKEW_BUMP_AFTER_AFTER = 0x1;
            l_scom_buffer.insert<56, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_GLBSM_REGS_RX_DESKEW_BUMP_AFTER_AFTER );
            constexpr auto l_IOMP_RX3_RXCTL_GLBSM_REGS_RX_SLS_RCVY_DISABLE_ON = 0x1;
            l_scom_buffer.insert<57, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_GLBSM_REGS_RX_SLS_RCVY_DISABLE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800a80600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800ae8600701103full, l_scom_buffer ));

            l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            constexpr auto l_IOMP_RX3_RXCTL_GLBSM_REGS_RX_HALF_RATE_MODE_GLBSM_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_GLBSM_REGS_RX_HALF_RATE_MODE_GLBSM_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800ae8600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800af8600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800af8600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800b80600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXCTL_DATASM_DATASM_REGS_RX_CTL_DATASM_CLKDIST_PDWN_OFF = 0x0;
            l_scom_buffer.insert<60, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_DATASM_DATASM_REGS_RX_CTL_DATASM_CLKDIST_PDWN_OFF );
            constexpr auto l_IOMP_RX3_RXCTL_DATASM_DATASM_REGS_RX_PG_DATASM_SPARE_MODE_0_ON = 0x1;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_DATASM_DATASM_REGS_RX_PG_DATASM_SPARE_MODE_0_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800b80600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800be8600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_RX3_RXCTL_DATASM_DATASM_REGS_RX_DESKEW_RATE_DIV1 = 0x1;
            l_scom_buffer.insert<51, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_DATASM_DATASM_REGS_RX_DESKEW_RATE_DIV1 );
            constexpr auto l_IOMP_RX3_RXCTL_DATASM_DATASM_REGS_RX_HALF_RATE_MODE_DATASM_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>(l_IOMP_RX3_RXCTL_DATASM_DATASM_REGS_RX_HALF_RATE_MODE_DATASM_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800be8600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c04600701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800c04600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c0c600701103full, l_scom_buffer ));

            if ((l_def_POSITION == literal_0))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((l_def_POSITION == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000001 );
            }
            else if ((l_def_POSITION == literal_2))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000010 );
            }
            else if ((l_def_POSITION == literal_3))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000011 );
            }
            else if ((l_def_POSITION == literal_4))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000100 );
            }
            else if ((l_def_POSITION == literal_5))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000101 );
            }
            else if ((l_def_POSITION == literal_6))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if ((l_def_POSITION == literal_7))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800c0c600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c14600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_CLKDIST_PDWN_OFF = 0x0;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_CLKDIST_PDWN_OFF );
            l_scom_buffer.insert<53, 5, 59, uint64_t>(literal_0b00010 );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DESKEW_RATE_DIV1 = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>(l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DESKEW_RATE_DIV1 );

            if ((l_TGT0_ATTR_EI_BUS_TX_MSBSWAP != fapi2::ENUM_ATTR_EI_BUS_TX_MSBSWAP_NO_SWAP))
            {
                constexpr auto l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_MSBSWAP_MSBSWAP = 0x1;
                l_scom_buffer.insert<58, 1, 63, uint64_t>(l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_MSBSWAP_MSBSWAP );
            }

            constexpr auto l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_PDWN_LITE_DISABLE_ON = 0x1;
            l_scom_buffer.insert<59, 1, 63, uint64_t>(l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_PDWN_LITE_DISABLE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800c14600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c1c600701103full, l_scom_buffer ));

            l_scom_buffer.insert<56, 7, 57, uint64_t>(literal_0b0010001 );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_CLK_HALF_WIDTH_MODE_ON = 0x1;
            l_scom_buffer.insert<55, 1, 63, uint64_t>(l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_CLK_HALF_WIDTH_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800c1c600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c24600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DRV_CLK_PATTERN_GCRMSG_DRV_0S = 0x0;
            l_scom_buffer.insert<48, 2, 62, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DRV_CLK_PATTERN_GCRMSG_DRV_0S );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800c24600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c84600701103full, l_scom_buffer ));

            l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0b0000000 );
            l_scom_buffer.insert<57, 7, 57, uint64_t>(literal_0b0010000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800c84600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c8c600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 = 0x5;
            l_scom_buffer.insert<55, 3, 61, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DYN_RECAL_INTERVAL_TIMEOUT_SEL_TAP5 );
            constexpr auto l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 = 0x1;
            l_scom_buffer.insert<58, 2, 62, uint64_t>
            (l_IOMP_TX_WRAP_TX3_TXCTL_CTL_REGS_TX_CTL_REGS_TX_DYN_RECAL_STATUS_RPT_TIMEOUT_SEL_TAP1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800c8c600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800cec600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0b0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800cec600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800cf4600701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0b00000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800cf4600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800d24600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXCTL_TX_CTL_SM_REGS_TX_PG_CTL_SM_SPARE_MODE_0_ON = 0x1;
            l_scom_buffer.insert<48, 1, 63, uint64_t>(l_IOMP_TX_WRAP_TX3_TXCTL_TX_CTL_SM_REGS_TX_PG_CTL_SM_SPARE_MODE_0_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800d24600701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800d2c600701103full, l_scom_buffer ));

            constexpr auto l_IOMP_TX_WRAP_TX3_TXCTL_TX_CTL_SM_REGS_TX_HALF_RATE_MODE_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>(l_IOMP_TX_WRAP_TX3_TXCTL_TX_CTL_SM_REGS_TX_HALF_RATE_MODE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800d2c600701103full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
