/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_ram_getspr.C $     */
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
/// @file p9_ram_getspr.C
/// @brief Utility to implement Get SPR Register by ramming
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
#include <p9_ram_getspr.H>

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------
fapi2::ReturnCode p9_ram_getspr(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                                const uint8_t i_thread,
                                const std::string i_name,
                                fapi2::buffer<uint64_t>* o_buffer)
{
    FAPI_INF("Start");
    uint32_t spr_num = 0;

    // instantiate the basic RamCore class
    RamCore ram(i_target, i_thread);
    // map spr register name to number
    FAPI_TRY(p9_spr_name_map_init());
    FAPI_TRY(p9_spr_name_map(i_name, false, spr_num));
    // call RamCore get_reg method
    FAPI_TRY(ram.get_reg(REG_SPR, spr_num, o_buffer));

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
