/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_fbc_ab.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_build_smp_fbc_ab.H,v 1.3 2014/02/23 21:41:07 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_fbc_ab.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_build_smp_fbc_ab.H
// *! DESCRIPTION : Fabric configuration (hotplug, AB) functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_BUILD_SMP_FBC_AB_H_
#define _PROC_BUILD_SMP_FBC_AB_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_build_smp.H>
#include <p8_scom_addresses.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// PB Hotplug Mode register field/bit definitions
const uint32_t PB_HP_MODE_MASTER_CHIP_BIT = 0;
const uint32_t PB_HP_MODE_CHG_RATE_GP_MASTER_BIT = 18;

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: determine paramters of link/destination chip
// parameters: i_smp_chip            => structure encapsulating SMP chip
//             i_source_link_id      => link identifier for FFDC
//             i_dest_target         => pointer to destination link endpoint target
//             o_link_is_enabled     => true=link enabled, false=link disabled
//             o_dest_target_node_id => node ID of destination chip
//             o_dest_target_chip_id => chip ID of destination chip
// returns: FAPI_RC_SUCCESS if output values are valid,
//          RC_PROC_FAB_SMP_FABRIC_CHIP_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_FABRIC_NODE_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_BUILD_SMP_AX_PARTIAL_GOOD_ERR if partial good attribute
//              state does not allow for action on target,
//          RC_PROC_BUILD_SMP_LINK_TARGET_TYPE_ERR if link target type is
//              unsupported,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_query_link_state(
    const proc_build_smp_chip& i_smp_chip,
    const uint8_t i_source_link_id,
    fapi::Target* i_dest_target,
    bool& o_link_is_enabled,
    proc_fab_smp_node_id& o_dest_target_node_id,
    proc_fab_smp_chip_id& o_dest_target_chip_id);


//------------------------------------------------------------------------------
// function: utility function to read set of PB CURR hotplug registers
// parameters: i_smp_chip   => structure encapsulating SMP chip
//             i_hp_not_hpx => choose HP/HPX register set (true=HP,
//                             false=HPX)
//             o_data       => data buffer containing read data
// returns: FAPI_RC_SUCCESS if register reads are successful and all shadow
//               registers are equivalent,
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_get_hotplug_curr_reg(
    const proc_build_smp_chip& i_smp_chip,
    const bool i_hp_not_hpx,
    ecmdDataBufferBase& o_data);


//------------------------------------------------------------------------------
// function: program fabric configuration register (hotplug, A/B set)
// parameters: i_smp => structure encapsulating SMP topology
//             i_op  => enumerated type representing SMP build phase
// returns: FAPI_RC_SUCCESS if register reads are successful and all shadow
//               registers are equivalent,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_OPERATION if an unsupported operation
//              is specified,
//          RC_PROC_ADU_UTILS_INVALID_LOCK_ATTEMPTS if invalid number of attempts
//              is specified,
//          RC_PROC_ADU_UTILS_INVALID_FBC_OP if invalid fabric operation
//              parameters are specified,
//          RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH if ADU status mismatches
//              for switch operation,
//          RC_PROC_FAB_SMP_FABRIC_CHIP_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_FABRIC_NODE_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          RC_PROC_BUILD_SMP_INVALID_AGGREGATE_CONFIG_ERR if configuration
//              specifies invalid aggregate link setup,
//          RC_PROC_BUILD_SMP_A_CMD_RATE_ERR if calculated A link command rate
//              is invalid,
//          RC_PROC_BUILD_SMP_F_CMD_RATE_ERR if calculated F link command rate
//              is invalid,
//          RC_PROC_BUILD_SMP_X_CMD_RATE_ERR if calculated X link command rate
//              is invalid,
//          RC_PROC_BUILD_SMP_AX_PARTIAL_GOOD_ERR if partial good attribute
//              state does not allow for action on target,
//          RC_PROC_BUILD_SMP_PCIE_PARTIAL_GOOD_ERR if partial good attribute
//              state does not allow for action on target,
//          RC_PROC_BUILD_SMP_LINK_TARGET_TYPE_ERR if link target type is
//              unsupported,
//          RC_PROC_BUILD_SMP_INVALID_TOPOLOGY if specified fabric topology
//              is illegal,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_fbc_ab(
    proc_build_smp_system& i_smp,
    const proc_build_smp_operation i_op);

} // extern "C"

#endif // _PROC_BUILD_SMP_FBC_AB_H_
