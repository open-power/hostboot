/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_draminit_training.H $   */
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

/// @file p9_mss_draminit_training.H
/// @brief Train DRAM
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_DRAMINIT_TRAINING__
#define __P9_MSS_DRAMINIT_TRAINING__

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_mss_draminit_training_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>&,
        const uint16_t);

extern "C"
{

    ///
    /// @brief Train dram, assumes effective config has run
    /// @param[in] i_target, the McBIST of the ports of the dram you're training
    /// @param[in] i_special_training, optional CAL_STEP_ENABLE override. Used in sim, debug
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_draminit_training( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
            const uint16_t i_special_training = 0 );
}


#endif
