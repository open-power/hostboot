/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup.C $          */
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
///  @file          :     p9_cpu_special_wakeup.C
///  @brief         :     HWP to perform special wakeup of core, EQ or EX.

// *HWP HW Owner    :    Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :    Prem S Jha <premjha2@in.ibm.com>
// *HWP Team        :    PM
// *HWP Level       :    1
// *HWP Consumed by :    OCC:FSP:HOST

// ---------------------------------------------------------------------
// Includes
// ---------------------------------------------------------------------
#include <p9_cpu_special_wakeup.H>

using namespace p9specialWakeup;
enum
{
    NUM_SPCWKUP_ENTITIES = 4,
    NUM_SPCWKUP_OPS = 3,
};

fapi2::ReturnCode
p9_cpu_special_wakeup(  const FAPI2_WAKEUP_CHIPLET& i_chipletTarget,
                        const PROC_SPCWKUP_OPS i_operation,
                        const PROC_SPCWKUP_ENTITY i_entity )
{
    FAPI_DBG("Entering p9_cpu_special_wakeup");

    FAPI_DBG("Exit p9_cpu_special_wakeup" );
    return fapi2::FAPI2_RC_SUCCESS;
}
