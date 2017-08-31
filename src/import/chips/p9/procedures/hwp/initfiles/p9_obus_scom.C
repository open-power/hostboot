/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_obus_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include "p9_obus_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b0011 = 0b0011;
constexpr uint64_t literal_0b10000 = 0b10000;
constexpr uint64_t literal_0b1000 = 0b1000;
constexpr uint64_t literal_0b1011 = 0b1011;
constexpr uint64_t literal_0b1010 = 0b1010;
constexpr uint64_t literal_0b00011 = 0b00011;
constexpr uint64_t literal_0b100 = 0b100;
constexpr uint64_t literal_0b1100 = 0b1100;
constexpr uint64_t literal_0b000000 = 0b000000;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0b0010 = 0b0010;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b1000110 = 0b1000110;
constexpr uint64_t literal_0b0110 = 0b0110;
constexpr uint64_t literal_0b01111000 = 0b01111000;
constexpr uint64_t literal_0b01011010 = 0b01011010;
constexpr uint64_t literal_0b110 = 0b110;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0b01110 = 0b01110;
constexpr uint64_t literal_0b0010101 = 0b0010101;
constexpr uint64_t literal_0b0010110 = 0b0010110;

fapi2::ReturnCode p9_obus_scom(const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT2, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT2, l_chip_ec));
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_HW = (l_TGT1_ATTR_IS_SIMULATION == literal_0);
        uint64_t l_def_IS_SIM = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        fapi2::ATTR_CHIP_EC_FEATURE_OBUS_HW419305_Type l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OBUS_HW419305, TGT2, l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305));
        fapi2::ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES_Type l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES, TGT2,
                               l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES));
        fapi2::ATTR_CHIP_EC_FEATURE_SW387041_Type l_TGT2_ATTR_CHIP_EC_FEATURE_SW387041;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_SW387041, TGT2, l_TGT2_ATTR_CHIP_EC_FEATURE_SW387041));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000009010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000109010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000209010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000309010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000409010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000509010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000609010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000709010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000809010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000809010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000909010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000909010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000a09010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000a09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000b09010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000b09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000c09010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000c09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000d09010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000d09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000e09010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000e09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000f09010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000f09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000001009010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000001009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000001109010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000001109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000001209010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000001209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000001309010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000001309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000001409010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000001409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000001509010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000001509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000001609010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000001609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000001709010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF =
                0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF =
                0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF =
                    0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON =
                    0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x6)
                    && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000001709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280809010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280809010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280909010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280909010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280a09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280a09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280b09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280b09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280c09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280c09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280d09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280d09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280e09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280e09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280f09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280f09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000281009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000281009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000281109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000281109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000281209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000281209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000281309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000281309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000281409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000281409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000281509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000281509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000281609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000281609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000281709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000281709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300809010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300809010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300909010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300909010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300a09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300a09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300b09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300b09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300c09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300c09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300d09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300d09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300e09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300e09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300f09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300f09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000301009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000301009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000301109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000301109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000301209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000301209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000301309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000301309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000301409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000301409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000301509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000301509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000301609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000301609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000301709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000301709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980809010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980809010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980909010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980909010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980a09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980a09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980b09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980b09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980c09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980c09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980d09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980d09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980e09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980e09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980f09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980f09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000981009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000981009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000981109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000981109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000981209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000981209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000981309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000981309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000981409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000981409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000981509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000981509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000981609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000981609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000981709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000981709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00809010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00809010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00909010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00909010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00a09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00a09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00b09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00b09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00c09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00c09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00d09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00d09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00e09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00e09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00f09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00f09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a01009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a01009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a01109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a01109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a01209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a01209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a01309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a01309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a01409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a01409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a01509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a01509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a01609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a01609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a01709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a01709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00809010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00809010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00909010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00909010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00a09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00a09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00b09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00b09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00c09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00c09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00d09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00d09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00e09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00e09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00f09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00f09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c01009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c01009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c01109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c01109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c01209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c01209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c01309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c01309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c01409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c01409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c01509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c01509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c01609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c01609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c01709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c01709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80809010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80809010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80909010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80909010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80a09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80a09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80b09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80b09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80c09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80c09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80d09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80d09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80e09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80e09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80f09010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80f09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c81009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c81009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c81109010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c81109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c81209010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c81209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c81309010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c81309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c81409010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c81409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c81509010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c81509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c81609010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c81609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c81709010c3full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b00011 );
                }
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21))
                     || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_P9NDD1_SPY_NAMES)
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
                }
                else if (( true ))
                {
                    l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b00011 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c81709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280009010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280109010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280209010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280309010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280409010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280509010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280609010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280709010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280809010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280809010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280909010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280909010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280a09010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280a09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280b09010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280b09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280c09010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280c09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280d09010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280d09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280e09010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280e09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280f09010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280f09010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002281009010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002281009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002281109010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002281109010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002281209010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002281209010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002281309010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002281309010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002281409010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002281409010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002281509010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002281509010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002281609010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002281609010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002281709010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b100 );
            }

            if (l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8002281709010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008000009010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PG_SPARE_MODE_4_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 63, uint64_t>(l_IOO0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PG_SPARE_MODE_4_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8008000009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008080009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8008080009010c3full, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x8008180009010c3full, l_scom_buffer ));

                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x8008180009010c3full, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008580009010c3full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b010 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b010 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b001 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0001 );
            }

            l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b101 );
            l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b101 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8008580009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008600009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b010 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8008600009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008680009010c3full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b100 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b010 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008680009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008700009010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0b1000110 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008700009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008780009010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0110 );
            }

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0110 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008780009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008800009010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0110 );
            }

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0110 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008800009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8008d00009010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0b01111000 );
            }

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0b01011010 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8008d00009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009700009010c3full, l_scom_buffer ));

            constexpr auto l_IOO0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RC_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL_ON = 0x1;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_IOO0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RC_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8009700009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009780009010c3full, l_scom_buffer ));

            if (( ! l_TGT2_ATTR_CHIP_EC_FEATURE_OBUS_HW419305))
            {
                constexpr auto l_IOO0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DC_ENABLE_CM_COARSE_CAL_OFF = 0x0;
                l_scom_buffer.insert<48, 1, 63, uint64_t>
                (l_IOO0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_DC_ENABLE_CM_COARSE_CAL_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8009780009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8009880009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b110 );

            if ((l_TGT2_ATTR_CHIP_EC_FEATURE_SW387041 != literal_0))
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (( true ))
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8009880009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c0c0009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800c0c0009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800f1c0009010c3full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01110 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800f1c0009010c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800f2c0009010c3full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0010101 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0010110 );
            }

            l_scom_buffer.insert<55, 7, 57, uint64_t>(literal_0b1000110 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800f2c0009010c3full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
