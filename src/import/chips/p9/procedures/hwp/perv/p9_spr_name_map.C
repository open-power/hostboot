/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_spr_name_map.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
//-----------------------------------------------------------------------------------
///
/// @file p9_spr_name_map.C
/// @brief Utility to map SPR name to SPR number
///
//-----------------------------------------------------------------------------------
// *HWP HWP Owner        : Liu Yang Fan <shliuyf@cn.ibm.com>
// *HWP HWP Backup Owner : Gou Peng Fei <shgoupf@cn.ibm.com>
// *HWP FW Owner         : Thi Tran <thi@us.ibm.com>
// *HWP Team             : Perv
// *HWP Level            : 2
// *HWP Consumed by      : None (Cronus test only)
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_spr_name_map.H>

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------
std::map<std::string, SPRMapEntry> spr_map;

fapi2::ReturnCode p9_spr_name_map_init()
{
    FAPI_INF("Start SPR name map init");

    FAPI_ASSERT(spr_map.empty(),
                fapi2::P9_SPR_NAME_MAP_INIT_ERR(),
                "SPR name map is not empty when initialization");

    {
        LIST_SPR_REG(DO_SPR_MAP)
    }

fapi_try_exit:
    FAPI_INF("Exiting SPR name map init");
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------
bool p9_spr_name_map_check_flag(unsigned char i_reg_flag, bool i_write)
{
    unsigned char op_flag = ((unsigned char)i_write) + 0x1;

    return (bool)(i_reg_flag & op_flag);
}

//-----------------------------------------------------------------------------------
fapi2::ReturnCode p9_spr_name_map(const std::string i_name, const bool i_write, uint32_t& o_number)
{
    FAPI_INF("Start SPR name map");
    bool l_check_flag = false;

    if(spr_map.find(i_name) != spr_map.end())
    {
        l_check_flag = p9_spr_name_map_check_flag(spr_map[i_name].flag, i_write);

        FAPI_ASSERT(l_check_flag,
                    fapi2::P9_SPR_INVALID_RW_MODE_ACCESS_ERR()
                    .set_REGNAME(i_name)
                    .set_RWFLAG(spr_map[i_name].flag),
                    "SPR RW mode check failed");

        o_number = spr_map[i_name].number;
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::P9_SPR_INVALID_NAME_ACCESS_ERR()
                    .set_REGNAME(i_name),
                    "SPR name is invalid");
    }

fapi_try_exit:
    FAPI_INF("Exiting SPR name map");
    return fapi2::current_err;
}
