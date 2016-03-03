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
#include <p9_build_smp.H>


extern "C" {

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

    enum p9_build_smp_adu_action
    {
        SWITCH_AB = 1,
        SWITCH_CD = 2,
        QUIESCE   = 4
    };


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief Perform fabric quiesce/switch operation via ADU
///
/// @param[in] i_smp       Fully specified structure encapsulating SMP
/// @param[in] i_op        Enumerated type representing SMP build phase (HB or FSP)
/// @param[in] i_action    Enumerated type representing fabric operation
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_sequence_adu(p9_build_smp_system& i_smp,
            const p9_build_smp_operation i_op,
            const p9_build_smp_adu_action i_action);


} // extern "C"

#endif // _P9_BUILD_SMP_ADU_H_
