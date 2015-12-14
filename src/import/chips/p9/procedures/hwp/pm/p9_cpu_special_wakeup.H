/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup.H $          */
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
#ifndef __API_SPECIAL_WAKEUP_
#define __API_SPECIAL_WAKEUP_

/**
 * @file            :     p9_cpu_special_wakeup.H
 * @brief           :     HWP to perform special wakeup of core, EQ or EX.
 * @HWP HW Owner    :     Greg Still <stillgs@us.ibm.com>
 * @HWP FW Owner    :     Prem S Jha <premjha2@in.ibm.com>
 * @HWP Team        :     PM
 * @HWP Level       :     L1
 * @HWP Consumed by :     OCC, FSP, HOST
 */

// ---------------------------------------------------------------------
// Includes
// ---------------------------------------------------------------------
#include <fapi2.H>

typedef  const fapi2::Target < fapi2::TARGET_TYPE_CORE |
fapi2::TARGET_TYPE_EX   |
fapi2::TARGET_TYPE_EQ > CONST_FAPI2_WAKEUP_CHIPLET;

#define NUM_SPCWKUP_ENTITIES 4

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

#define NUM_SPCWKUP_OPS 3

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

/**
 * @brief   Sets core, ex or eq chiplet into special wakeup state.
 * @param   i_chipletTarget fapi2 target associated with core, ex and eq.
 * @param   i_operation     special wakeup operations to be used.
 * @return  SUCCESS if requested operation is accomplished, errorcode
 *          otherwise.
 * @note    needs support of following attribute:
 *          ATTR_PM_SPWUP_FSP
 *          ATTR_PM_SPWUP_OCC
 *          ATTR_PM_SPWUP_HOST
 *          ATTR_PM_SPWUP_OTR
 *          ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG
 */
fapi2::ReturnCode
p9_cpu_special_wakeup(  CONST_FAPI2_WAKEUP_CHIPLET& i_chipletTarget,
                        PROC_SPCWKUP_OPS i_operation,
                        PROC_SPCWKUP_ENTITY i_entity );

#endif //__API_SPECIAL_WAKEUP_
