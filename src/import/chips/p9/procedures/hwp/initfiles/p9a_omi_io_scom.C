/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9a_omi_io_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include "p9a_omi_io_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b0011 = 0b0011;
constexpr uint64_t literal_0b10000 = 0b10000;
constexpr uint64_t literal_0b1011 = 0b1011;
constexpr uint64_t literal_0b1010 = 0b1010;
constexpr uint64_t literal_0b1100 = 0b1100;
constexpr uint64_t literal_0b000000 = 0b000000;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0b0010 = 0b0010;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b100 = 0b100;
constexpr uint64_t literal_0b0000 = 0b0000;
constexpr uint64_t literal_0b110 = 0b110;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0b01110 = 0b01110;
constexpr uint64_t literal_0b0010101 = 0b0010101;
constexpr uint64_t literal_0b0010110 = 0b0010110;
constexpr uint64_t literal_0b1000110 = 0b1000110;

fapi2::ReturnCode p9a_omi_io_scom(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& TGT0,
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
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000000701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000010701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000010701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000020701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000020701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000030701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000030701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000040701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000040701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000050701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000050701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000060701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000060701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000070701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000070701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000080701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000080701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000090701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000090701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000a0701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000b0701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_2_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000c0701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000d0701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000e0701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000000f0701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_3_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000000f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000100701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000100701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000110701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000110701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000120701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000120701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000130701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_4_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000130701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000140701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000140701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000150701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000150701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000160701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000160701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000170701103full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI0_IOO_CPLT_RX0_RXPACKS_5_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000170701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028000701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028010701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028010701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028020701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028020701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028030701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028030701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028040701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028040701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028050701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028050701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028060701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028060701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028070701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028070701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028080701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028080701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028090701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028090701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280a0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280b0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280c0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280d0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280e0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000280f0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000280f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028100701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028100701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028110701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028110701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028120701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028120701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028130701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028130701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028140701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028140701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028150701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028150701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028160701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028160701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028170701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028170701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030000701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030010701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030010701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030020701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030020701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030030701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030030701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030040701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030040701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030050701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030050701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030060701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030060701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030070701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030070701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030080701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030080701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030090701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030090701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300a0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300b0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300c0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300d0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300e0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000300f0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000300f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030100701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030100701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030110701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030110701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030120701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030120701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030130701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030130701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030140701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030140701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030150701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030150701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030160701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030160701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030170701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030170701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098000701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098010701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098010701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098020701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098020701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098030701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098030701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098040701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098040701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098050701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098050701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098060701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098060701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098070701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098070701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098080701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098080701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098090701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098090701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980a0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980b0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980c0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980d0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980e0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000980f0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000980f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098100701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098100701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098110701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098110701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098120701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098120701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098130701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098130701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098140701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098140701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098150701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098150701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098160701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098160701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098170701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098170701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0000701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0010701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0010701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0020701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0020701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0030701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0030701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0040701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0040701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0050701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0050701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0060701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0060701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0070701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0070701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0080701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0080701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0090701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0090701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00a0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00b0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00c0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00d0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00e0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a00f0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a00f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0100701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0100701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0110701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0110701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0120701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0120701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0130701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0130701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0140701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0140701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0150701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0150701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0160701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0160701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0170701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0170701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0000701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0010701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0010701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0020701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0020701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0030701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0030701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0040701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0040701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0050701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0050701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0060701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0060701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0070701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0070701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0080701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0080701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0090701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0090701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00a0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00b0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00c0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00d0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00e0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00f0701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0100701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0100701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0110701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0110701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0120701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0120701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0130701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0130701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0140701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0140701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0150701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0150701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0160701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0160701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0170701103full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0170701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8000701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8010701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8010701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8020701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8020701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8030701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8030701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8040701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8040701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8050701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8050701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8060701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8060701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8070701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8070701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8080701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8080701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8090701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8090701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80a0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80b0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80c0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80d0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80e0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c80f0701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c80f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8100701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8100701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8110701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8110701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8120701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8120701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8130701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8130701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8140701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8140701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8150701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8150701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8160701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8160701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8170701103full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8170701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228000701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228010701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228010701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228020701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228020701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228030701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228030701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228040701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228040701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228050701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228050701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228060701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228060701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228070701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228070701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228080701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228080701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228090701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228090701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280a0701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280a0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280b0701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280b0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280c0701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280c0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280d0701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280d0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280e0701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280e0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8002280f0701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8002280f0701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228100701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228100701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228110701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228110701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228120701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228120701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228130701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228130701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228140701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228140701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228150701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228150701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228160701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228160701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228170701103full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228170701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800800000701103full, l_scom_buffer ));

            constexpr auto l_MCP_OMI0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PG_SPARE_MODE_4_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 63, uint64_t>(l_MCP_OMI0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_PG_SPARE_MODE_4_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800800000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800808000701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800808000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800818000701103full, l_scom_buffer ));

            constexpr auto l_MCP_OMI0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RECAL_REQ_DL_MASK_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>(l_MCP_OMI0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RECAL_REQ_DL_MASK_OFF );
            constexpr auto l_MCP_OMI0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RECAL_ABORT_DL_MASK_OFF = 0x0;
            l_scom_buffer.insert<57, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RECAL_ABORT_DL_MASK_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800818000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800830000701103full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800830000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800840000701103full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x0 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800840000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800858000701103full, l_scom_buffer ));

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
            FAPI_TRY(fapi2::putScom(TGT0, 0x800858000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800860000701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b010 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800860000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800868000701103full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x0 );
            }

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b100 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b010 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800868000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800878000701103full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800878000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800880000701103full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800880000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800888000701103full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x0 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800888000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800970000701103full, l_scom_buffer ));

            constexpr auto l_MCP_OMI0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RC_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL_ON = 0x1;
            l_scom_buffer.insert<48, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RC_ENABLE_CTLE_1ST_LATCH_OFFSET_CAL_ON );
            constexpr auto l_MCP_OMI0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RC_ENABLE_AUTO_RECAL_OFF = 0x0;
            l_scom_buffer.insert<51, 1, 63, uint64_t>
            (l_MCP_OMI0_IOO_CPLT_RX0_RXCTL_CTL_REGS_RX_CTL_REGS_RX_RC_ENABLE_AUTO_RECAL_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800970000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800988000701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b110 );
            l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800988000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800c0c000701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800c0c000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800f1c000701103full, l_scom_buffer ));

            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01110 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800f1c000701103full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800f2c000701103full, l_scom_buffer ));

            if (l_def_IS_HW)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0010101 );
            }
            else if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<48, 7, 57, uint64_t>(literal_0b0010110 );
            }

            l_scom_buffer.insert<55, 7, 57, uint64_t>(literal_0b1000110 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800f2c000701103full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
