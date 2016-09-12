/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_setup.H $      */
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
/// @file p9_tod_setup.H
/// @brief Procedures to configure the TOD topology
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE
// ----------------------------------------------------------------------------------

#ifndef _P9_TOD_SETUP_H_
#define _P9_TOD_SETUP_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_tod_utils.H>

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9_tod_setup_FP_t) (tod_topology_node*,
                      const p9_tod_setup_tod_sel,
                      const p9_tod_setup_osc_sel);

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

extern "C" {

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

/// @brief Setup the tod
/// @param[in] i_tod_node  Reference to TOD topology (FAPI targets included within)
/// @param[in] i_tod_sel   Specifies the topology to configure
/// @param[in] i_osc_sel   Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if TOD topology is successfully configured else FAPI or ECMD error is sent through
    fapi2::ReturnCode p9_tod_setup(
        tod_topology_node* i_tod_node,
        const p9_tod_setup_tod_sel i_tod_sel,
        const p9_tod_setup_osc_sel i_osc_sel);

/// @brief Configure the tod topology set up the oscilator select and the primary or secondary tod
/// @param[in] i_tod_node => Reference to TOD topology (FAPI targets included within)
/// @param[in] i_tod_sel => Specifies the topology to configure
/// @param[in] i_osc_sel => Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if TOD topology is successfully configured
///          else FAPI or ECMD error is sent through
    fapi2::ReturnCode configure_tod_node(tod_topology_node*           i_tod_node,
                                         const p9_tod_setup_tod_sel i_tod_sel,
                                         const p9_tod_setup_osc_sel i_osc_sel);

/// @brief Clear any previous topology that may have been set
/// @param[in] i_tod_node => Reference to TOD topology (FAPI targets included within)
/// @param[in] i_tod_sel => Specifies the topology to clear
/// @param[in] i_is_mpipl => if this IPL is an MPIPL, additional setup is needed; determined via an attribute
/// @return FAPI_RC_SUCCESS if TOD topology is successfully cleared
///          else FAPI or ECMD error is sent through
    fapi2::ReturnCode clear_tod_node(tod_topology_node*             i_tod_node,
                                     const p9_tod_setup_tod_sel   i_tod_sel,
                                     const fapi2::ATTR_IS_MPIPL_Type i_is_mpipl);

/// @brief Configures the PSS_MSS_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node => Reference to TOD topology (FAPI targets included within)
/// @param[in] i_tod_sel => Specifies the topology to configure
/// @param[in] i_osc_sel => Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the PSS_MSS_CTRL_REG is successfully configured
///         else FAPI or ECMD error is sent through
    fapi2::ReturnCode configure_pss_mss_ctrl_reg(tod_topology_node*           i_tod_node,
            const p9_tod_setup_tod_sel i_tod_sel,
            const p9_tod_setup_osc_sel i_osc_sel);

/// @brief Configures the S_PATH_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node => Reference to TOD topology (FAPI targets included within)
/// @param[in] i_tod_sel => Specifies the topology to configure
/// @param[in] i_osc_sel => Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the S_PATH_CTRL_REG is successfully configured
///         else FAPI or ECMD error is sent through
    fapi2::ReturnCode configure_s_path_ctrl_reg(tod_topology_node*           i_tod_node,
            const p9_tod_setup_tod_sel i_tod_sel,
            const p9_tod_setup_osc_sel i_osc_sel);

/// @brief Configures the PORT_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node => Reference to TOD topology (FAPI targets included within)
/// @param[in] i_tod_sel => Specifies the topology to configure
/// @param[in] i_osc_sel => Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the PORT_CTRL_REG is successfully configured
///         else FAPI or ECMD error is sent through
    fapi2::ReturnCode configure_port_ctrl_regs(tod_topology_node*           i_tod_node,
            const p9_tod_setup_tod_sel i_tod_sel,
            const p9_tod_setup_osc_sel i_osc_sel);

/// @brief Configures the M_PATH_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node => Reference to TOD topology (FAPI targets included within)
/// @param[in] i_tod_sel => Specifies the topology to configure
/// @param[in] i_osc_sel => Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the M_PATH_CTRL_REG is successfully configured
///         else FAPI or ECMD error is sent through
    fapi2::ReturnCode configure_m_path_ctrl_reg(tod_topology_node*           i_tod_node,
            const p9_tod_setup_tod_sel i_tod_sel,
            const p9_tod_setup_osc_sel i_osc_sel);

/// @brief Configures the I_PATH_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node => Reference to TOD topology (FAPI targets included within)
/// @param[in] i_tod_sel => Specifies the topology to configure
/// @param[in] i_osc_sel => Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the I_PATH_CTRL_REG is successfully configured
///         else FAPI or ECMD error is sent through
    fapi2::ReturnCode configure_i_path_ctrl_reg(tod_topology_node*           i_tod_node,
            const p9_tod_setup_tod_sel i_tod_sel,
            const p9_tod_setup_osc_sel i_osc_sel);

/// @brief Configures the INIT_CHIP_CTRL_REG; will be called by configure_tod_node
/// @param[in]i_tod_node => Reference to TOD topology (FAPI targets included within)
/// @param[in] i_tod_sel => Specifies the topology to configure
/// @param[in] i_osc_sel => Specifies the oscillator to use for the master
/// @return FAPI_RC_SUCCESS if the INIT_CHIP_CTRL_REG is successfully configured
///         else FAPI or ECMD error is sent through
    fapi2::ReturnCode init_chip_ctrl_reg(tod_topology_node*           i_tod_node,
                                         const p9_tod_setup_tod_sel i_tod_sel,
                                         const p9_tod_setup_osc_sel i_osc_sel);

/// @brief Displays the TOD topology
/// @param[in] i_tod_node => Reference to TOD topology
/// @param[in] depth => depth of children into the tod node that we are in
/// @return void
    void display_tod_nodes(const tod_topology_node* i_tod_node, const uint32_t depth);

/// @brief Calculates and populates the topology delays
/// @param[in] i_tod_node => Reference to TOD topology
/// @return FAPI_RC_SUCCESS if TOD topology is successfully configured with delays else FAPI or ECMD error is sent through
    fapi2::ReturnCode calculate_node_delays(tod_topology_node* i_tod_node);

/// @brief Finds the longest delay in the topology (additionally sets each node delay)
/// @param[in]  i_tod_node      => Reference to TOD topology
/// @param[in]  i_freq_x        => XBUS frequency in MHz
/// @param[in]  i_freq_o        => OBUS frequency in MHz
/// @param[out] o_longest_delay => Longest delay in TOD-grid-cycles
/// @return FAPI_RC_SUCCESS if a longest TOD delay was found in topology else FAPI or ECMD error is sent through
    fapi2::ReturnCode calculate_longest_topolopy_delay(tod_topology_node* i_tod_node,
            const uint32_t     i_freq_x,
            const uint32_t     i_freq_o,
            uint32_t&          o_longest_delay);

/// @brief Calculates the delay for a node in TOD-grid-cycles
/// @param[in]  i_tod_node   => Reference to TOD topology
/// @param[in]  i_freq_x     => XBUS frequency in MHz
/// @param[in]  i_freq_o     => OBUS frequency in MHz
/// @param[out] o_node_delay => Delay of a single node in TOD-grid-cycles
/// @return FAPI_RC_SUCCESS if TOD node delay is successfully calculated else FAPI or ECMD error is sent through
    fapi2::ReturnCode calculate_node_link_delay(tod_topology_node* i_tod_node,
            const uint32_t     i_freq_x,
            const uint32_t     i_freq_o,
            uint32_t&          o_node_delay);

/// @brief Updates the topology struct with the final delay values
/// @param[in]  i_tod_node      => Reference to TOD topology
/// @param[in]  i_freq_x        => XBUS frequency in MHz
/// @param[in]  i_freq_o        => OBUS frequency in MHz
/// @param[in]  i_longest_delay => Longest delay in the topology
/// @return FAPI_RC_SUCCESS if o_int_path_delay was set for every node in the topology else FAPI or ECMD error is sent through
    fapi2::ReturnCode set_topology_delays(tod_topology_node* i_tod_node,
                                          const uint32_t     i_freq_x,
                                          const uint32_t     i_freq_o,
                                          const uint32_t     i_longest_delay);


} //extern "C"

#endif //_P9_TOD_SETUP_H_

