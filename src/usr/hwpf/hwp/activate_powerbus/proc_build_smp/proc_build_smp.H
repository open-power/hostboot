/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp.H $ */
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
// $Id: proc_build_smp.H,v 1.14 2014/02/23 21:41:06 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_build_smp.H
// *! DESCRIPTION : Perform fabric configuration (FAPI)
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS:
// *!
// *! Perform fabric SMP build/reconfiguration operations.
// *!
// *! Platform Notes:
// *!     This HWP has multiple IPL use cases.  In all all cases the HWP input
// *!     is expected to contain an entry for each chip within the scope of
// *!     the new SMP to be constructed (with valid information for all
// *!     active links that are fully contained within the new SMP).
// *!
// *!     The proc_build_smp_operation HWP input defines the desired
// *!     reconfiguration option to be performed:
// *!
// *!         SMP_ACTIVATE_PHASE1 (HBI):
// *!             o init epsilon registers,
// *!             o program FBC configuration dependent registers (switch C/D)
// *!             o join all single chip 'island' fabrics into drawer level
// *!               SMP (switch A/B)
// *!
// *!         SMP_ACTIVATE_PHASE2 (FSP):
// *!             o join collection of drawer level SMPs into full system SMP
// *!               (switch A/B)
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_BUILD_SMP_H_
#define _PROC_BUILD_SMP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <vector>
#include <map>
#include <fapi.H>
#include <proc_fab_smp.H>
#include <p8_scom_addresses.H>


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// HWP argument, define supported execution modes
enum proc_build_smp_operation
{
    // call from HBI (init epsilons, switch C/D + A/B)
    // used to initialize scope of HBI drawer
    SMP_ACTIVATE_PHASE1 = 1,
    // call from FSP (only switch A/B)
    // used to stitch drawers/CCM
    SMP_ACTIVATE_PHASE2 = 2
};

// HWP argument structure defining properties of this chip
// and links which should be considered
struct proc_build_smp_proc_chip
{
    // target for this chip
    fapi::Target this_chip;
    // set if this chip should be designated fabric
    // master post-reconfiguration
    // NOTE: this chip must currently be designated a
    //       master in its enclosing fabric
    //       PHASE1/HBI: any chip
    //       PHASE2/FSP: any current drawer master
    bool master_chip_sys_next;

    // chiplet targets connected to A links
    fapi::Target a0_chip;
    fapi::Target a1_chip;
    fapi::Target a2_chip;

    // chiplet targets connected to X links
    fapi::Target x0_chip;
    fapi::Target x1_chip;
    fapi::Target x2_chip;
    fapi::Target x3_chip;

    // parameters defining F link connected SMPs
    bool enable_f0;
    proc_fab_smp_node_id f0_node_id;
    bool enable_f1;
    proc_fab_smp_node_id f1_node_id;
};


// structure to represent fabric connectivty & properites for a single chip
// in the SMP topology
struct proc_build_smp_chip
{
    // associated HWP input structure
    proc_build_smp_proc_chip* chip;

    // chip properties/attributes:
    // fabric chip/node ID
    proc_fab_smp_chip_id chip_id;
    proc_fab_smp_node_id node_id;
    // partial good attributes
    bool nx_enabled;
    bool x_enabled;
    bool a_enabled;
    bool pcie_enabled;
    // node/system master designation (curr)
    bool master_chip_node_curr;
    bool master_chip_sys_curr;
    // node/system master designation (next)
    bool master_chip_node_next;
    bool issue_quiesce_next;
    bool quiesced_next;
    // select for PCIe/DSMP mux (one per link)
    bool pcie_not_f_link[PROC_FAB_SMP_NUM_F_LINKS];
};

// structure to represent properties for a single node in the SMP topology
struct proc_build_smp_node
{
    // chips which reside in this node
    std::map<proc_fab_smp_chip_id, proc_build_smp_chip> chips;

    // node properties/attributes:
    // fabric node ID
    proc_fab_smp_node_id node_id;
};

// structure to encapsulate system epsilon configuration
struct proc_build_smp_eps_cfg
{
    // epsilon configuration inputs
    bool gb_positive;
    uint8_t gb_percentage;
    proc_fab_smp_eps_table_type table_type;
    // target epsilon values
    uint32_t r_t0;    // read, tier0 (np)
    uint32_t r_t1;    // read, tier1 (gp)
    uint32_t r_t2;    // read, tier2 (sp)
    uint32_t r_f;     // read, foreign (f)
    uint32_t w_t2;    // write, tier2 (sp)
    uint32_t w_f;     // write, foreign (f)
    uint32_t p;       // pre
};

// core/nest frequency ratio cutpoints (epsilon)
enum proc_build_smp_core_ratio
{
    PROC_BUILD_SMP_CORE_RATIO_8_8 = 0,
    PROC_BUILD_SMP_CORE_RATIO_7_8 = 1,
    PROC_BUILD_SMP_CORE_RATIO_6_8 = 2,
    PROC_BUILD_SMP_CORE_RATIO_5_8 = 3,
    PROC_BUILD_SMP_CORE_RATIO_4_8 = 4,
    PROC_BUILD_SMP_CORE_RATIO_2_8 = 5
};

// core floor/nest frequency ratio cutpoints (CPU delay)
enum proc_build_smp_cpu_delay
{
    PROC_BUILD_SMP_CPU_DELAY_4800_2400 = 0,
    PROC_BUILD_SMP_CPU_DELAY_4431_2400 = 1,
    PROC_BUILD_SMP_CPU_DELAY_4114_2400 = 2,
    PROC_BUILD_SMP_CPU_DELAY_3840_2400 = 3,
    PROC_BUILD_SMP_CPU_DELAY_3600_2400 = 4,
    PROC_BUILD_SMP_CPU_DELAY_3338_2400 = 5,
    PROC_BUILD_SMP_CPU_DELAY_3200_2400 = 6,
    PROC_BUILD_SMP_CPU_DELAY_3032_2400 = 7,
    PROC_BUILD_SMP_CPU_DELAY_2880_2400 = 8,
    PROC_BUILD_SMP_CPU_DELAY_2743_2400 = 9,
    PROC_BUILD_SMP_CPU_DELAY_2618_2400 = 10,
    PROC_BUILD_SMP_CPU_DELAY_2504_2400 = 11,
    PROC_BUILD_SMP_CPU_DELAY_2400_2400 = 12
};

// structure to represent collection of nodes in SMP topology
struct proc_build_smp_system
{
    // nodes which reside in this SMP
    std::map<proc_fab_smp_node_id, proc_build_smp_node> nodes;
    // current system master for the purpose of launching
    // fabric reconfiguration operations
    bool master_chip_curr_set;
    proc_fab_smp_node_id master_chip_curr_node_id;
    proc_fab_smp_chip_id master_chip_curr_chip_id;

    // system properties/attributes:
    // system frequencies (MHz):
    uint32_t freq_pb;
    uint32_t freq_a;
    uint32_t freq_x;
    uint32_t freq_core_floor;
    uint32_t freq_core_nom;
    uint32_t freq_core_ceiling;
    uint32_t freq_pcie;
    // core/pb frequency ratios
    proc_build_smp_core_ratio core_floor_ratio;
    proc_build_smp_core_ratio core_ceiling_ratio;
    // CPU delay/RCMD highwater settings
    proc_build_smp_cpu_delay nom_cpu_delay;
    proc_build_smp_cpu_delay full_cpu_delay;

    // program async boundary crossings to safe mode
    bool async_safe_mode;
    // X bus width
    bool x_bus_8B;
    // fabric pump mode
    proc_fab_smp_pump_mode pump_mode;
    // AVP test modes
    bool avp_mode;
    // MCS interleaving configuration
    bool all_mcs_interleaved;
    // system epsilon configuration
    proc_build_smp_eps_cfg eps_cfg;
};

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_build_smp_FP_t)(std::vector<proc_build_smp_proc_chip>&,
                       const proc_build_smp_operation);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// PB shadow register constant definition
const uint8_t PROC_BUILD_SMP_NUM_SHADOWS = 3;

// core floor/nest frequency ratio cutpoints (CPU delay)
const uint8_t PROC_BUILD_SMP_CPU_DELAY_NUM_SETPOINTS = 13;


extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: perform fabric SMP reconfiguration operations
// parameters: i_proc_chips => vector of structures defining properties of each
//                             chip and its connected links
//             i_op  => enumerated type representing SMP build phase
//                      (SMP_ACTIVATE_PHASE1 = HBI,
//                       SMP_ACTIVATE_PHASE2 = FSP)
// returns: FAPI_RC_SUCCESS if SMP build operation is successful,
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
//          RC_PROC_FAB_SMP_X_BUS_WIDTH_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_PUMP_MODE_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_MCS_INTERLEAVED_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_EPSILON_TABLE_TYPE_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_EPSILON_GB_DIRECTION_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_BUILD_SMP_CORE_FLOOR_FREQ_RATIO_ERR if cache/nest frequency
//              ratio is unsupported,
//          RC_PROC_BUILD_SMP_CORE_FREQ_RANGE_ERR if invalid relationship exists
//              between ceiling/nominal/floor core frequency attributes,
//          RC_PROC_BUILD_SMP_CORE_CEILING_FREQ_RATIO_ERR if cache/nest frequency
//              ratio is unsupported,
//          RC_PROC_BUILD_SMP_CORE_FLOOR_RATIO_ERR if cache/nest frequency
//              ratio is unsupported,
//          RC_PROC_BUILD_SMP_CORE_CEILING_RATIO_ERR if cache/nest frequency
//              ratio is unsupported,
//          RC_PROC_FAB_SMP_ASYNC_SAFE_MODE_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_PCIE_NOT_F_LINK_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_FABRIC_NODE_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_FABRIC_CHIP_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_BUILD_SMP_NODE_ADD_INTERNAL_ERR if node map insert fails,
//          RC_PROC_BUILD_SMP_DUPLICATE_FABRIC_ID_ERR if chips with duplicate
//              fabric node/chip IDs are detected,
//          RC_PROC_BUILD_SMP_NO_MASTER_SPECIFIED_ERR if input parameters
//              do not specify a new fabric system master,
//          RC_PROC_BUILD_SMP_MASTER_DESIGNATION_ERR if node/system master
//              error is detected based on chip state and input paramters,
//          RC_PROC_BUILD_SMP_INVALID_OPERATION_ERR if an unsupported operation
//              is specified
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if HP shadow registers are not
//              equivalent,
//          RC_PROC_BUILD_SMP_EPSILON_INVALID_TABLE_ERR if invalid epsilon
//              table type/content is detected,
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if any target value is out of
//              range given underlying HW storage,
//          RC_PROC_BUILD_SMP_INVALID_GROUP_SIZE_ERR if group size is too
//              small/large,
//          RC_PROC_BUILD_SMP_PACING_RATE_TABLE_ERR if pacing rate table lookup
//              is unsuccessful,
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
fapi::ReturnCode proc_build_smp(
    std::vector<proc_build_smp_proc_chip> & i_proc_chips,
    const proc_build_smp_operation i_op);


} // extern "C"

#endif // _PROC_BUILD_SMP_H_
