/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_tod_save_config.C $ */
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
//------------------------------------------------------------------------------
//
// @file p10_tod_save_config.C
// @brief Saves TOD configuration registers to topology structure
//
// *HWP HW Maintainer    : Douglas Holtsinger <Douglas.Holtsinger@ibm.com>
// *HWP FW Maintainer    : Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by      : FSP
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_tod_save_config.H>
#include <p10_scom_perv.H>

//------------------------------------------------------------------------------
// Namespace declarations
//------------------------------------------------------------------------------

using namespace scomt;
using namespace scomt::perv;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// NOTE: description in header
fapi2::ReturnCode p10_tod_save_config(tod_topology_node* i_tod_node)
{
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(i_tod_node->i_target);

    FAPI_DBG("Start");

    FAPI_TRY(GET_TOD_M_PATH_CTRL_REG(l_target,
                                     i_tod_node->o_todRegs.tod_m_path_ctrl_reg),
             "Error from GET_TOD_M_PATH_CTRL_REG");

    FAPI_TRY(GET_TOD_PRI_PORT_0_CTRL_REG(l_target,
                                         i_tod_node->o_todRegs.tod_pri_port_0_ctrl_reg),
             "Error from GET_TOD_PRI_PORT_0_CTRL_REG");

    FAPI_TRY(GET_TOD_PRI_PORT_1_CTRL_REG(l_target,
                                         i_tod_node->o_todRegs.tod_pri_port_1_ctrl_reg),
             "Error from GET_TOD_PRI_PORT_1_CTRL_REG");

    FAPI_TRY(GET_TOD_SEC_PORT_0_CTRL_REG(l_target,
                                         i_tod_node->o_todRegs.tod_sec_port_0_ctrl_reg),
             "Error from GET_TOD_SEC_PORT_0_CTRL_REG");

    FAPI_TRY(GET_TOD_SEC_PORT_1_CTRL_REG(l_target,
                                         i_tod_node->o_todRegs.tod_sec_port_1_ctrl_reg),
             "Error from GET_TOD_SEC_PORT_1_CTRL_REG");

    FAPI_TRY(GET_TOD_S_PATH_CTRL_REG(l_target,
                                     i_tod_node->o_todRegs.tod_s_path_ctrl_reg),
             "Error from GET_TOD_S_PATH_CTRL_REG");

    FAPI_TRY(GET_TOD_I_PATH_CTRL_REG(l_target,
                                     i_tod_node->o_todRegs.tod_i_path_ctrl_reg),
             "Error from GET_TOD_I_PATH_CTRL_REG");

    FAPI_TRY(GET_TOD_PSS_MSS_CTRL_REG(l_target,
                                      i_tod_node->o_todRegs.tod_pss_mss_ctrl_reg),
             "Error from GET_TOD_PSS_MSS_CTRL_REG");

    FAPI_TRY(GET_TOD_CHIP_CTRL_REG(l_target,
                                   i_tod_node->o_todRegs.tod_chip_ctrl_reg),
             "Error from TOD_CHIP_CTRL_REG");

    // Recurse to save configuration of children
    for (auto l_child = (i_tod_node->i_children).begin();
         l_child != (i_tod_node->i_children).end();
         ++l_child)
    {
        FAPI_TRY(p10_tod_save_config(*l_child),
                 "Failure saving downstream configurations!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
