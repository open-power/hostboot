/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/utils/p9_cpu_special_wakeup.H $                      */
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

/**
 * @file            :     p9_cpu_special_wakeup.C
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
#include <p9_cpu_special_wakeup.H>

fapi2::ReturnCode
p9_cpu_special_wakeup(  CONST_FAPI2_WAKEUP_CHIPLET& i_chipletTarget,
                        PROC_SPCWKUP_OPS i_operation,
                        PROC_SPCWKUP_ENTITY i_entity )
{
    FAPI_IMP("Entering... ");

    FAPI_IMP("Exit..." );
    return fapi2::FAPI2_RC_SUCCESS;
}

