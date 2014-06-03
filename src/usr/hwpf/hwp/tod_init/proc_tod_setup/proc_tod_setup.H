/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_setup/proc_tod_setup.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: proc_tod_setup.H,v 1.8 2014/05/27 16:31:03 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *!
// *! TITLE : proc_tod_setup.H
// *!
// *! DESCRIPTION : Header for proc_tod_setup.C
// *!
// *! OWNER NAME  : Nick Klazynski  Email: jklazyns@us.ibm.com
// *! BACKUP NAME :                 Email:
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef PROC_TOD_SETUP_H_
#define PROC_TOD_SETUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "proc_tod_utils.H"

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_tod_setup_FP_t) (tod_topology_node*,
                        const proc_tod_setup_tod_sel,
                        const proc_tod_setup_osc_sel);

// function pointer which allows HWSV to calculate TOD_CHIP_CTRL_REG_00040010's value
// (Does not set the register)
typedef fapi::ReturnCode
(*init_chip_ctrl_reg_FP_t) (ecmdDataBufferBase&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/**
 * @brief Configures the TOD topology
 *
 * @param[in] i_tod_node  Reference to TOD topology (FAPI targets included within)
 *            i_tod_sel   Specifies the topology to configure
 *            i_osc_sel   Specifies the oscillator to use for the master
 *
 * @return FAPI_RC_SUCCESS if TOD topology is successfully configured
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode proc_tod_setup(tod_topology_node*           i_tod_node,
                                const proc_tod_setup_tod_sel i_tod_sel,
                                const proc_tod_setup_osc_sel i_osc_sel);

/**
 * @brief Helper function for proc_tod_setup
 *
 * @param[in] i_tod_node  Reference to TOD topology (FAPI targets included within)
 *            i_tod_sel   Specifies the topology to configure
 *            i_osc_sel   Specifies the oscillator to use for the master
 *
 * @return FAPI_RC_SUCCESS if TOD topology is successfully configured
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode configure_tod_node(tod_topology_node*           i_tod_node,
                                    const proc_tod_setup_tod_sel i_tod_sel,
                                    const proc_tod_setup_osc_sel i_osc_sel);

/**
 * @brief Helper function for proc_tod_setup
 *
 * @param[in] i_tod_node  Reference to TOD topology (FAPI targets included within)
 *            i_tod_sel   Specifies the topology to clear
 *
 * @return FAPI_RC_SUCCESS if TOD topology is successfully cleared
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode clear_tod_node(tod_topology_node*           i_tod_node,
                                const proc_tod_setup_tod_sel i_tod_sel);

/**
 * @brief Calculates TOD_CHIP_CTRL_REG_00040010 value; will be called
 * while configuring the TOD node
 * 
 * @param[out] o_chic_ctrlReg_val => ecmdDataBuffer containing the 
 * Chip Control Status Register configuration
 *        
 * @return FAPI_RC_SUCCESS if TOD_CHIP_CTRL_REG_00040010's value was successfully
 *         calculated else ECMD error is sent back
 */
fapi::ReturnCode init_chip_ctrl_reg(ecmdDataBufferBase& o_chic_ctrlReg_val); 

/**
 * @brief Displays the TOD topology
 *
 * @param[in] i_tod_node  Reference to TOD topology
 *
 * @return void
 */
void display_tod_nodes(const tod_topology_node* i_tod_node, const uint32_t depth);

/**
 * @brief Calculates and populates the topology delays
 *
 * @param[in] i_tod_node  Reference to TOD topology
 *
 * @return FAPI_RC_SUCCESS if TOD topology is successfully configured with delays
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode calculate_node_delays(tod_topology_node* i_tod_node);

/**
 * @brief Finds the longest delay in the topology (additionally sets each node delay)
 *
 * @param[in]  i_tod_node      Reference to TOD topology
 * @param[in]  i_freq_x        XBUS frequency in MHz
 * @param[in]  i_freq_a        ABUS frequency in MHz
 *
 * @param[out] o_longest_delay Longest delay in TOD-grid-cycles
 *
 * @return FAPI_RC_SUCCESS if a longest TOD delay was found in topology
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode calculate_longest_topolopy_delay(tod_topology_node* i_tod_node,
                                                  const uint32_t     i_freq_x,
                                                  const uint32_t     i_freq_a,
                                                  uint32_t*          o_longest_delay);

/**
 * @brief Calculates the delay for a node in TOD-grid-cycles
 *
 * @param[in]  i_tod_node      Reference to TOD topology
 * @param[in]  i_freq_x        XBUS frequency in MHz
 * @param[in]  i_freq_a        ABUS frequency in MHz
 *
 * @param[out] o_node_delay    Delay of a single node in TOD-grid-cycles
 *
 * @return FAPI_RC_SUCCESS if TOD node delay is successfully calculated
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode calculate_node_link_delay(tod_topology_node* i_tod_node,
                                           const uint32_t     i_freq_x,
                                           const uint32_t     i_freq_a,
                                           uint32_t*          o_node_delay);

/**
 * @brief Updates the topology struct with the final delay values
 *
 * @param[in]  i_tod_node      Reference to TOD topology
 * @param[in]  i_freq_x        XBUS frequency in MHz
 * @param[in]  i_freq_a        ABUS frequency in MHz
 * @param[in]  i_longest_delay Longest delay in the topology
 *
 * @return FAPI_RC_SUCCESS if o_int_path_delay was set for every node in the topology
 *         else FAPI or ECMD error is sent through
 */
fapi::ReturnCode set_topology_delays(tod_topology_node* i_tod_node,
                                     const uint32_t     i_freq_x,
                                     const uint32_t     i_freq_a,
                                     const uint32_t     i_longest_delay);
} // extern "C"

#endif // PROC_TOD_SETUP_H_
