/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
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
/// @author Joe McGill <jmcgill@us.ibm.com>
/// @author Christy Graves <clgraves@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: HB,FSP
//

#ifndef _P9_BUILD_SMP_H_
#define _P9_BUILD_SMP_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// HWP argument, define supported execution modes
enum p9_build_smp_operation
{
    // call from HB (init epsilons, switch C/D + A/B)
    // used to initialize scope of HBI drawer
    SMP_ACTIVATE_PHASE1 = 1,
    // call from FSP (only switch A/B)
    // used to stitch drawers/CCM
    SMP_ACTIVATE_PHASE2 = 2
};

// HWP argument structure defining properties of this chip
struct p9_build_smp_proc_chip
{
    // target for this chip
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> this_chip;
    // set if this chip should be designated fabric
    // master post-reconfiguration
    // NOTE: this chip must currently be designated a
    //       master in its enclosing fabric
    //       PHASE1/HB: any chip
    //       PHASE2/FSP: any current drawer master
    bool is_master_chip_sys_next;
};

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_build_smp_FP_t) (std::vector<p9_build_smp_proc_chip>&,
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
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp(std::vector<p9_build_smp_proc_chip>& i_proc_chips,
                                   const p9_build_smp_operation i_op);

} // extern "C"

#endif // _P9_BUILD_SMP_H_
