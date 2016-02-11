/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_block_wakeup_intr.H $           */
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

/// @file  p9_block_wakeup_intr.H
/// @brief Set/reset the BLOCK_REG_WKUP_SOURCES bit in the PPM
///         associated with an EX chiplet
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS
///
///-----------------------------------------------------------------------------

#ifndef _P9_BLKWKUP_H_
#define _P9_BLKWKUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <p9_pm.H>
#include <fapi2.H>
#include <p9_misc_scom_addresses.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

namespace p9pmblockwkup
{

static const uint8_t NUM_OPS = 2;

enum OP_TYPE
{
    SET,
    CLEAR
};

} // namespace p9pmblockwkup

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_block_wakeup_intr_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
    const p9pmblockwkup::OP_TYPE);

extern "C" {

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

/// @brief @brief Set/reset the BLOCK_REG_WKUP_SOURCES bit in the PPM
///         associated with an EX chiplet
///
/// @param[in] i_core_target    Core target
/// @param[in] i_operation      SET, CLEAR
///
/// @retval ECMD_SUCCESS
/// @retval ERROR only those from called functions or MACROs

    fapi2::ReturnCode
    p9_block_wakeup_intr(  const fapi2::Target<fapi2::TARGET_TYPE_CORE>&
                           i_core_target,
                           p9pmblockwkup::OP_TYPE i_operation);

} // extern "C"

#endif // _P9_BLKWKUP_H_
