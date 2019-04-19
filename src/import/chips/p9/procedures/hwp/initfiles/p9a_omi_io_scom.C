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

fapi2::ReturnCode p9a_omi_io_scom(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& TGT0,
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
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000000701183full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000000701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000010701183full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000010701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000020701183full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_2_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000020701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000030701183full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_3_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000030701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000040701183full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_4_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000040701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000050701183full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_0_RXPACK_RD_SLICE_5_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000050701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000060701183full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_0_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000060701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000070701183full, l_scom_buffer ));

            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_5_OFF );
            constexpr auto
            l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF = 0x0;
            l_scom_buffer.insert<54, 1, 63, uint64_t>
            (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_6_OFF );

            if (l_def_IS_HW)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF = 0x0;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_OFF );
            }
            else if (l_def_IS_SIM)
            {
                constexpr auto
                l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON = 0x1;
                l_scom_buffer.insert<55, 1, 63, uint64_t>
                (l_MCP_OMI2_IOO_CPLT_RX0_RXPACKS_1_RXPACK_RD_SLICE_1_RX_DAC_REGS_RX_DAC_REGS_RX_PL_DATA_DAC_SPARE_MODE_7_ON );
            }

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800000070701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028000701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028000701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028010701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028010701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028020701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028020701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028030701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028030701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028040701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028040701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028050701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028050701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028060701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028060701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800028070701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800028070701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030000701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030000701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030010701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030010701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030020701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030020701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030030701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030030701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030040701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030040701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030050701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030050701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030060701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030060701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800030070701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800030070701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098000701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098000701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098010701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098010701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098020701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098020701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098030701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098030701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098040701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098040701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098050701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098050701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098060701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098060701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800098070701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800098070701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0000701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0000701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0010701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0010701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0020701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0020701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0030701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0030701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0040701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0040701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0050701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0050701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0060701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0060701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000a0070701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000a0070701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0000701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0000701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0010701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0010701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0020701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0020701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0030701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0030701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0040701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0040701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0050701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0050701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0060701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0060701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0070701183full, l_scom_buffer ));

            l_scom_buffer.insert<52, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<57, 5, 59, uint64_t>(literal_0b10000 );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0070701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8000701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8000701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8010701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8010701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8020701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8020701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8030701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8030701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8040701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8040701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8050701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8050701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8060701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8060701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8070701183full, l_scom_buffer ));

            l_scom_buffer.insert<53, 4, 60, uint64_t>(literal_0b1010 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b0011 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8070701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228000701183full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228000701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228010701183full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228010701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228020701183full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228020701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228030701183full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228030701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228040701183full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228040701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228050701183full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228050701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228060701183full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228060701183full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800228070701183full, l_scom_buffer ));

            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x800228070701183full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
