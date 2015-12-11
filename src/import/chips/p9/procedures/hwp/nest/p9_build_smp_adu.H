/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp_adu.H $             */
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
/// @file p9_build_smp_adu.H
/// @brief Interface for ADU operations required to support fabric
///        configuration actions (FAPI2)
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
/// *HWP Consumed by: HB,FSP
///

#ifndef _P9_BUILD_SMP_ADU_H_
#define _P9_BUILD_SMP_ADU_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_build_smp.H>

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief Perform fabric C/D configuration switch on a single chip
///
/// @param[in] i_smp_chip      Structure encapsulating single chip in SMP
/// @param[in] i_smp           Structure encapsulating SMP topology
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_switch_cd(p9_build_smp_chip& i_smp_chip,
            p9_build_smp_system& i_smp);

///
/// @brief Quiesce slave fabrics by issuing fabric quiesce operation on
///        specified chips
///        NOTE: ADU atomic lock will be obtained for all chips prior
///              to issuing quiesce operation on specified chips
///
/// @param[in] i_smp       Structure encapsulating SMP topology
/// @param[in] i_op        Enumerated type representing SMP build phase
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_quiesce_pb(p9_build_smp_system& i_smp,
            const p9_build_smp_operation i_op);


///
/// @brief Perform fabric A/B configuration switch on all chips present in SMP
///        NOTE: ADU atomic lock will be obtained for all chips prior to
///              issuing switch from master chip (defined by i_master_smp_chip)
///
/// @param[in] i_smp       Structure encapsulating SMP topology
/// @param[in] i_op        Enumerated type representing SMP build phase
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_switch_ab(p9_build_smp_system& i_smp,
            const p9_build_smp_operation i_op);


} // extern "C"

#endif // _P9_BUILD_SMP_ADU_H_
