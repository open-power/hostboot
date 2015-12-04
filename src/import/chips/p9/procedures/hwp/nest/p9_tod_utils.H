/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_utils.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
//
/// @file p9_tod_utils.H
/// @brief Utilities and classes for the tod_init and tod_setup procedures
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by:
// ----------------------------------------------------------------------------------
//
// *! ADDITIONAL COMMENTS :
// *!
// *!
// *!
//-----------------------------------------------------------------------------------

#ifndef _P9_TOD_UTILS_H_
#define _P9_TOD_UTILS_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------

#include <fapi2.H>

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9_tod_utils_get_tfmr_reg_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
                                   ecmdDataBufferBase& );

typedef fapi2::ReturnCode
(*p9_tod_utils_set_tfmr_reg_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_CORE>*&,
                                   ecmdDataBufferBase& );
//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

extern "C" {

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------
    enum p9_tod_setup_tod_sel
    {
        TOD_PRIMARY,  // configure primary TOD
        TOD_SECONDARY // configure secondary TOD
    };

    enum p9_tod_setup_bus
    {
        NONE, //This is for MDMT
        XBUS0,
        XBUS1,
        XBUS2,
        XBUS3,
        ABUS0,
        ABUS1,
        ABUS2
    };

    enum tod_action
    {
        TOD_SETUP,
        TOD_INIT,
        TOD_STATUS,
        TOD_CLEANUP,
        TOD_CHECK_OSC
    };

    // Input which determines the master oscillator to use
    enum p9_tod_setup_osc_sel
    {
        TOD_OSC_0,             // oscillator connected to OSC0 and not OSC1
        TOD_OSC_1,             // oscillator connected to OSC1 and not OSC0
        TOD_OSC_0_AND_1,       // oscillators connected to both OSC0 and OSC1
        TOD_OSC_0_AND_1_SEL_0, // oscillators connected to both OSC0 and OSC1, but OSC0 will always be selected
        TOD_OSC_0_AND_1_SEL_1, // oscillators connected to both OSC0 and OSC1, but OSC1 will always be selected
        TOD_OSC_NONE           // No oscillators connected
    };

    struct p9_tod_setup_conf_regs
    {
        ecmdDataBufferBase tod_m_path_ctrl_reg;
        ecmdDataBufferBase tod_pri_port_0_ctrl_reg;
        ecmdDataBufferBase tod_pri_port_1_ctrl_reg;
        ecmdDataBufferBase tod_sec_port_0_ctrl_reg;
        ecmdDataBufferBase tod_sec_port_1_ctrl_reg;
        ecmdDataBufferBase tod_s_path_ctrl_reg;
        ecmdDataBufferBase tod_i_path_ctrl_reg;
        ecmdDataBufferBase tod_pss_mss_ctrl_reg;
        ecmdDataBufferBase tod_chip_ctrl_reg;
    };

    struct tod_topology_node
    {
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* i_target;
        bool i_tod_master;
        bool i_drawer_master;
        p9_tod_setup_bus i_bus_rx; // Current node's bus from which step/sync is received ("Receive Port" in eiinfo)
        p9_tod_setup_bus i_bus_tx; // Upstream node's bus from which step/sync is transmitted ("Drive Port" in eiinfo)
        std::list<tod_topology_node*> i_children;
        p9_tod_setup_conf_regs o_todRegs;
        uint32_t o_int_path_delay;
    };

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

/// @brief Gets the value in the TFMR register
/// @param[in] i_target       => P9 chip target
/// @param[out] o_tfmr_val    => Value that is in the TFMR register
/// @return FAPI_RC_SUCCESS if TFMR read is successful else FAPI or ECMD error is sent through
    fapi2::ReturnCode p9_tod_utils_get_tfmr_reg(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        ecmdDataBufferBase& o_tfmr_val);

/// @brief Sets the value in the TFMR register
/// @param[in] i_target => P9 chip target
/// @param[in] i_tfmr_val => Value that will be put in the TFMR register
/// @return FAPI_RC_SUCCESS if TFMR write is successful else FAPI or ECMD error is sent through
    fapi2::ReturnCode p9_tod_utils_set_tfmr_reg(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        ecmdDataBufferBase& i_tfmr_val);

} //extern "C"

#endif //_P9_TOD_UTILS_H_

