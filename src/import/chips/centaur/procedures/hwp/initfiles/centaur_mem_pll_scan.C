/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/initfiles/centaur_mem_pll_scan.C $ */
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
#include "centaur_mem_pll_scan.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x128000000A0060D3 = 0x128000000A0060D3;
constexpr uint64_t literal_1066 = 1066;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x128000000A0030D2 = 0x128000000A0030D2;
constexpr uint64_t literal_1333 = 1333;
constexpr uint64_t literal_0x128000000A0050D1 = 0x128000000A0050D1;
constexpr uint64_t literal_1600 = 1600;
constexpr uint64_t literal_0x128000000A0030D1 = 0x128000000A0030D1;
constexpr uint64_t literal_1866 = 1866;
constexpr uint64_t literal_0x128000000A0150D5 = 0x128000000A0150D5;
constexpr uint64_t literal_0x7000000200040000 = 0x7000000200040000;
constexpr uint64_t literal_0x5000000200040002 = 0x5000000200040002;
constexpr uint64_t literal_0x3000000200040002 = 0x3000000200040002;
constexpr uint64_t literal_0xB000000200040002 = 0xB000000200040002;
constexpr uint64_t literal_0x00 = 0x00;

fapi2::ReturnCode centaur_mem_pll_scan(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& TGT0,
                                       const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_SIM = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        fapi2::ATTR_CEN_MSS_FREQ_Type l_TGT0_ATTR_CEN_MSS_FREQ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, TGT0, l_TGT0_ATTR_CEN_MSS_FREQ));
        uint64_t l_def_MEMB_MEM_FREQ = l_TGT0_ATTR_CEN_MSS_FREQ;
        uint64_t l_def_IS_HW = (l_TGT1_ATTR_IS_SIMULATION == literal_0);
        bool l_PLLMEM_PLL_CNTRL0_update = false;
        fapi2::variable_buffer l_PLLMEM_PLL_CNTRL0(64);

        if (l_def_IS_SIM)
        {
            l_PLLMEM_PLL_CNTRL0.insertFromRight<uint64_t>(literal_0x128000000A0060D3, 0, 64);
            l_PLLMEM_PLL_CNTRL0_update = true;
        }
        else if ((l_def_IS_HW && (l_def_MEMB_MEM_FREQ == literal_1066)))
        {
            l_PLLMEM_PLL_CNTRL0.insertFromRight<uint64_t>(literal_0x128000000A0030D2, 0, 64);
            l_PLLMEM_PLL_CNTRL0_update = true;
        }
        else if ((l_def_IS_HW && (l_def_MEMB_MEM_FREQ == literal_1333)))
        {
            l_PLLMEM_PLL_CNTRL0.insertFromRight<uint64_t>(literal_0x128000000A0050D1, 0, 64);
            l_PLLMEM_PLL_CNTRL0_update = true;
        }
        else if ((l_def_IS_HW && (l_def_MEMB_MEM_FREQ == literal_1600)))
        {
            l_PLLMEM_PLL_CNTRL0.insertFromRight<uint64_t>(literal_0x128000000A0030D1, 0, 64);
            l_PLLMEM_PLL_CNTRL0_update = true;
        }
        else if ((l_def_IS_HW && (l_def_MEMB_MEM_FREQ == literal_1866)))
        {
            l_PLLMEM_PLL_CNTRL0.insertFromRight<uint64_t>(literal_0x128000000A0150D5, 0, 64);
            l_PLLMEM_PLL_CNTRL0_update = true;
        }

        if ( l_PLLMEM_PLL_CNTRL0_update)
        {
            FAPI_TRY(fapi2::putSpy(TGT0, "PLLMEM.PLL_CNTRL0", l_PLLMEM_PLL_CNTRL0));
        }

        bool l_PLLMEM_PLL_CNTRL1_update = false;
        fapi2::variable_buffer l_PLLMEM_PLL_CNTRL1(64);

        if (l_def_IS_SIM)
        {
            l_PLLMEM_PLL_CNTRL1.insertFromRight<uint64_t>(literal_0x7000000200040000, 0, 64);
            l_PLLMEM_PLL_CNTRL1_update = true;
        }
        else if ((l_def_IS_HW && (l_def_MEMB_MEM_FREQ == literal_1066)))
        {
            l_PLLMEM_PLL_CNTRL1.insertFromRight<uint64_t>(literal_0x5000000200040002, 0, 64);
            l_PLLMEM_PLL_CNTRL1_update = true;
        }
        else if ((l_def_IS_HW && (l_def_MEMB_MEM_FREQ == literal_1333)))
        {
            l_PLLMEM_PLL_CNTRL1.insertFromRight<uint64_t>(literal_0x3000000200040002, 0, 64);
            l_PLLMEM_PLL_CNTRL1_update = true;
        }
        else if ((l_def_IS_HW && (l_def_MEMB_MEM_FREQ == literal_1600)))
        {
            l_PLLMEM_PLL_CNTRL1.insertFromRight<uint64_t>(literal_0x3000000200040002, 0, 64);
            l_PLLMEM_PLL_CNTRL1_update = true;
        }
        else if ((l_def_IS_HW && (l_def_MEMB_MEM_FREQ == literal_1866)))
        {
            l_PLLMEM_PLL_CNTRL1.insertFromRight<uint64_t>(literal_0xB000000200040002, 0, 64);
            l_PLLMEM_PLL_CNTRL1_update = true;
        }

        if ( l_PLLMEM_PLL_CNTRL1_update)
        {
            FAPI_TRY(fapi2::putSpy(TGT0, "PLLMEM.PLL_CNTRL1", l_PLLMEM_PLL_CNTRL1));
        }

        bool l_PLLMEM_PLL_CNTRL2_update = false;
        fapi2::variable_buffer l_PLLMEM_PLL_CNTRL2(8);

        if (l_def_IS_SIM)
        {
            l_PLLMEM_PLL_CNTRL2.insertFromRight<uint64_t>(literal_0x00, 0, 8);
            l_PLLMEM_PLL_CNTRL2_update = true;
        }
        else if (l_def_IS_HW)
        {
            l_PLLMEM_PLL_CNTRL2.insertFromRight<uint64_t>(literal_0x00, 0, 8);
            l_PLLMEM_PLL_CNTRL2_update = true;
        }

        if ( l_PLLMEM_PLL_CNTRL2_update)
        {
            FAPI_TRY(fapi2::putSpy(TGT0, "PLLMEM.PLL_CNTRL2", l_PLLMEM_PLL_CNTRL2));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
