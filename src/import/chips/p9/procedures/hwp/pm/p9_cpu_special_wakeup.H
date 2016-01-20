/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup.H $          */
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
///  @file          :     p9_cpu_special_wakeup.H
///  @brief         :     HWP to perform special wakeup of core, EQ or EX.

// *HWP HW Owner    :    Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :    Prem S Jha <premjha2@in.ibm.com>
// *HWP Team        :    PM
// *HWP Level       :    1
// *HWP Consumed by :    OCC:FSP:HOST

#ifndef __P9_CPU_SPECIAL_WAKEUP_H_
#define __P9_CPU_SPECIAL_WAKEUP_H_


// ---------------------------------------------------------------------
// Includes
// ---------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

namespace p9specialWakeup
{

typedef  fapi2::Target < fapi2::TARGET_TYPE_CORE |
fapi2::TARGET_TYPE_EX   |
fapi2::TARGET_TYPE_EQ > FAPI2_WAKEUP_CHIPLET;

/**
 * @brief enumerates all platforms which request special wakeup.
 */
enum PROC_SPCWKUP_ENTITY
{
    HOST,
    FSP,
    OCC,
    PHYP = HOST,
    SPW_ALL
};

/**
 * @brief enumerates all operations associated with special wakeup.
 */
enum PROC_SPCWKUP_OPS
{
    SPCWKUP_DISABLE,
    SPCWKUP_ENABLE,
    SPCWKUP_INIT,
    SPCWKUP_FORCE_DEASSERT
};

} //p9specialWakeup ends

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_cpu_special_wakeup_FP_t)
( const p9specialWakeup::FAPI2_WAKEUP_CHIPLET& i_chipletTarget,
  const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
  const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity );

extern "C"
{
/// @brief       Sets core, ex or eq chiplet into special wakeup state.
/// @param[in]   i_chipletTarget fapi2 target associated with core, ex and eq.
/// @param[in]   i_operation     special wakeup operations to be used.
/// @param[in]   i_entity        entity requesting special wakeup.
/// @return      FAPI2_RC_SUCCESS on success, errorcode otherwise.
/// @note    needs support of following attribute:
///          ATTR_PM_SPWUP_FSP
///          ATTR_PM_SPWUP_OCC
///          ATTR_PM_SPWUP_HOST
///          ATTR_PM_SPWUP_OTR
///          ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG
    fapi2::ReturnCode
    p9_cpu_special_wakeup(  const p9specialWakeup::FAPI2_WAKEUP_CHIPLET& i_chipletTarget,
                            const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
                            const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity );
}// extern "C" ends

#endif //__P9_CPU_SPECIAL_WAKEUP_H_
