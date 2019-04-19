/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9a_omic_io_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include "p9a_omic_io_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b000000 = 0b000000;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0 = 0;
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

fapi2::ReturnCode p9a_omic_io_scom(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT2, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT2, l_chip_ec));
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_SIM = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        uint64_t l_def_IS_HW = (l_TGT1_ATTR_IS_SIMULATION == literal_0);
        fapi2::buffer<uint64_t> l_scom_buffer;
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
