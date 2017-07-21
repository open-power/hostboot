/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_spr_name_map.C $   */
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
// *HWP Level            : 3
// *HWP Consumed by      : None (Cronus test only)
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_spr_name_map.H>

std::map<std::string, SPRMapEntry> SPR_MAP;
bool spr_map_initialized = false;

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------
bool p9_spr_name_map_init()
{
    if (spr_map_initialized)
    {
        return true;
    }

    if (!SPR_MAP.empty())
    {
        return false;
    }

    LIST_SPR_REG(DO_SPR_MAP)
    spr_map_initialized = true;

    return true;
}

//-----------------------------------------------------------------------------------
bool p9_spr_name_map_check_flag(unsigned char i_reg_flag, bool i_write)
{
    unsigned char op_flag = ((unsigned char)i_write) + 0x1;

    return (bool)(i_reg_flag & op_flag);
}

//-----------------------------------------------------------------------------------
bool p9_spr_name_map(const std::string i_name, const bool i_write, uint32_t& o_number)
{
    bool l_check_flag = false;

    if(SPR_MAP.find(i_name) != SPR_MAP.end())
    {
        l_check_flag = p9_spr_name_map_check_flag(SPR_MAP[i_name].flag, i_write);

        if(l_check_flag)
        {
            o_number = SPR_MAP[i_name].number;
        }
    }

    return l_check_flag;
}

//-----------------------------------------------------------------------------------
bool p9_get_share_type(const std::string i_name, Enum_ShareType& o_share_type)
{
    bool l_rc = false;

    if(SPR_MAP.find(i_name) != SPR_MAP.end())
    {
        o_share_type = SPR_MAP[i_name].share_type;
        l_rc = true;
    }

    return l_rc;
}

//-----------------------------------------------------------------------------------
bool p9_get_bit_length(const std::string i_name, uint8_t& o_bit_length)
{
    bool l_rc = false;

    if(SPR_MAP.find(i_name) != SPR_MAP.end())
    {
        o_bit_length = SPR_MAP[i_name].bit_length;
        l_rc = true;
    }

    return l_rc;
}

//-----------------------------------------------------------------------------------
bool p9_get_spr_entry(const std::string i_name, SPRMapEntry& o_spr_entry)
{
    bool l_rc = false;

    if(SPR_MAP.find(i_name) != SPR_MAP.end())
    {
        o_spr_entry = SPR_MAP[i_name];
        l_rc = true;
    }

    return l_rc;
}


