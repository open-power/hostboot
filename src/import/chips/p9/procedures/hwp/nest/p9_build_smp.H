/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_build_smp.H
/// @brief Perform fabric configuration (FAPI2)
///
/// Perform fabric SMP build/reconfiguration operations.
///
/// Platform Notes:
///     This HWP has multiple IPL use cases.  In all all cases the HWP input
///     is expected to contain an entry for each chip within the scope of
///     the new SMP to be constructed (with valid attribute state repesenting all
///     active links that are fully contained within the new SMP).
///
///     The p9_build_smp_operation HWP input defines the desired
///     reconfiguration option to be performed:
///
///         SMP_ACTIVATE_PHASE1 (HBI):
///             o init epsilon registers,
///             o program FBC configuration dependent registers (switch C/D)
///             o join all single chip 'island' fabrics into drawer level
///               SMP (switch A/B)
///
///         SMP_ACTIVATE_PHASE2 (FSP):
///             o join collection of drawer level SMPs into full system SMP
///               (switch A/B)
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
/// *HWP Consumed by: HB,FSP
///

#ifndef _P9_BUILD_SMP_H_
#define _P9_BUILD_SMP_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <map>
#include <p9_fab_smp_utils.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
// PB shadow register constant definition
const uint8_t P9_BUILD_SMP_NUM_SHADOWS = 3;

// HWP argument, define supported execution modes
enum p9_build_smp_operation
{
    // Call from HB (init epsilons, switch C/D + A/B),
    // used to initialize scope of HBI drawer
    SMP_ACTIVATE_PHASE1 = 1,
    // Call from FSP (only switch A/B), used to stitch drawers/CCM
    SMP_ACTIVATE_PHASE2 = 2
};

// Core/nest frequency ratio cutpoints (epsilon)
enum p9_build_smp_core_ratio
{
    P9_BUILD_SMP_CORE_RATIO_8_8 = 0,
    P9_BUILD_SMP_CORE_RATIO_7_8 = 1,
    P9_BUILD_SMP_CORE_RATIO_6_8 = 2,
    P9_BUILD_SMP_CORE_RATIO_5_8 = 3,
    P9_BUILD_SMP_CORE_RATIO_4_8 = 4,
    P9_BUILD_SMP_CORE_RATIO_2_8 = 5
};

// Core floor/nest frequency ratio cutpoints (CPU delay)
enum p9_build_smp_cpu_delay
{
    P9_BUILD_SMP_CPU_DELAY_4800_2400 = 0,
    P9_BUILD_SMP_CPU_DELAY_4431_2400 = 1,
    P9_BUILD_SMP_CPU_DELAY_4114_2400 = 2,
    P9_BUILD_SMP_CPU_DELAY_3840_2400 = 3,
    P9_BUILD_SMP_CPU_DELAY_3600_2400 = 4,
    P9_BUILD_SMP_CPU_DELAY_3338_2400 = 5,
    P9_BUILD_SMP_CPU_DELAY_3200_2400 = 6,
    P9_BUILD_SMP_CPU_DELAY_3032_2400 = 7,
    P9_BUILD_SMP_CPU_DELAY_2880_2400 = 8,
    P9_BUILD_SMP_CPU_DELAY_2743_2400 = 9,
    P9_BUILD_SMP_CPU_DELAY_2618_2400 = 10,
    P9_BUILD_SMP_CPU_DELAY_2504_2400 = 11,
    P9_BUILD_SMP_CPU_DELAY_2400_2400 = 12
};

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// HWP argument structure defining properties of this chip
// and links which should be considered
struct p9_build_smp_proc_chip
{
    // Target for this chip
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> this_chip;

    // Set if this chip should be designated fabric
    // master post-reconfiguration
    // NOTE: this chip must currently be designated a
    //       master in its enclosing fabric
    //       PHASE1/HB: any chip
    //       PHASE2/FSP: any current drawer master
    bool master_chip_sys_next;

    // XBUS chiplet targets connected to X links
    fapi2::Target<fapi2::TARGET_TYPE_XBUS> x0_chip;
    fapi2::Target<fapi2::TARGET_TYPE_XBUS> x1_chip;
    fapi2::Target<fapi2::TARGET_TYPE_XBUS> x2_chip;

    // Obus chiplet targets, connected to either A or X links
    fapi2::Target<fapi2::TARGET_TYPE_OBUS> o0_chip;
    fapi2::Target<fapi2::TARGET_TYPE_OBUS> o1_chip;
    fapi2::Target<fapi2::TARGET_TYPE_OBUS> o2_chip;
    fapi2::Target<fapi2::TARGET_TYPE_OBUS> o3_chip;

};

// Structure to encapsulate system epsilon configuration

const uint8_t NUMBER_OF_EPSILON_READ_TIERS = 3;
const uint8_t NUMBER_OF_EPSILON_WRITE_TIERS = 3;

struct p9_build_smp_eps_cfg
{
    // Epsilon configuration inputs
    int8_t gb_percentage;
    p9_fab_smp_eps_table_type table_type;

    // Epsilon protection count
    // read, tier0 (LN)
    // read, tier1 (NN/G)
    // read, tier2 (RN/VG)
    // write, tier1 (LN/NN/G)
    // write, tier2 (RN/VG)
    uint32_t r_t[NUMBER_OF_EPSILON_READ_TIERS];  // Read, index is tier
    uint32_t w_t[NUMBER_OF_EPSILON_WRITE_TIERS]; // Write, index is tier
};

// Structure to represent fabric connectivty & properites for a single chip
// in the SMP topology
struct p9_build_smp_chip
{
    // associated HWP input structure
    p9_build_smp_proc_chip* chip;

    // Fabric chip/node ID
    p9_fab_smp_chip_id chip_id;
    p9_fab_smp_node_id node_id;

    // Optic mode (A or X)
    uint8_t smpOpticsMode;

    // TODO: RTC 147511 - Need to set enabled based on ATTR_PG attributes.
    // This is to prevent issuing SCOMs to a region that might be deconfigured,
    // and we can't use the state of a unit target (XBUS/OBUS) to make the
    // determination.
    bool nv_enabled = false;
    bool x_enabled = true;
    bool o_enabled = true;

    // Node/system master designation (curr)
    bool master_chip_node_curr;
    bool master_chip_sys_curr;

    // Node/system master designation (next)
    bool master_chip_node_next;
    bool issue_quiesce_next;
    bool quiesced_next;

};

// Structure to represent properties for a single node in the SMP topology
struct p9_build_smp_node
{
    // Chips which reside in this node
    std::map<p9_fab_smp_chip_id, p9_build_smp_chip> chips;

    // Node properties/attributes:
    // fabric node ID
    p9_fab_smp_node_id node_id;
};

// Structure to represent collection of nodes in SMP topology
struct p9_build_smp_system
{
    // nodes which reside in this SMP
    std::map<p9_fab_smp_node_id, p9_build_smp_node> nodes;

    // current system master for the purpose of launching
    // fabric reconfiguration operations
    bool master_chip_curr_set;
    p9_fab_smp_node_id master_chip_curr_node_id;
    p9_fab_smp_chip_id master_chip_curr_chip_id;

    // Indicate if optic is configured as A or X
    uint8_t smpOpticsMode;

    // System properties/attributes:
    // system frequencies (MHz):
    uint32_t freq_pb;
    uint32_t freq_a;
    uint32_t freq_x;
    uint32_t freq_core_floor;
    uint32_t freq_core_nom;
    uint32_t freq_core_ceiling;
    uint32_t freq_pcie;

    // Core/pb frequency ratios
    p9_build_smp_core_ratio core_floor_ratio;
    p9_build_smp_core_ratio core_ceiling_ratio;

    // CPU delay/RCMD highwater settings
    p9_build_smp_cpu_delay nom_cpu_delay;
    p9_build_smp_cpu_delay full_cpu_delay;

    // Fabric pump mode
    p9_fab_smp_pump_mode pump_mode;

    // System epsilon configuration
    p9_build_smp_eps_cfg eps_cfg;
};

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_build_smp_FP_t)
(std::vector<p9_build_smp_proc_chip>&,
 const p9_build_smp_operation);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Perform fabric SMP reconfiguration operation
///
/// @param[in] i_proc_chips Vector of structures defining properties of each chip
/// @param[op] i_op Enumerated type representing SMP build phase (HB or FSP)
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp(std::vector<p9_build_smp_proc_chip>& i_proc_chips,
                                   const p9_build_smp_operation i_op);

} // extern "C"

#endif // _P9_BUILD_SMP_H_
