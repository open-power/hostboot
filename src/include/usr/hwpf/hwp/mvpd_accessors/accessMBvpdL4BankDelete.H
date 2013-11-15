/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/accessMBvpdL4BankDelete.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: accessMBvpdL4BankDelete.H,v 1.2 2013/11/21 17:17:30 whs Exp $
/**
 *  @file accessMBvpdL4BankDelete.H
 *
 *  @brief MBvpd accessor for the ATTR_L4_BANK_DELETE_VPD attribute
 */

#ifndef _HWP_ACCESSMBVPDL4BANKDELETE_
#define _HWP_ACCESSMBVPDL4BANKDELETE_

#include <fapi.H>

namespace fapi
{

// mode
    enum MBvpdL4BankDeleteMode
    {
        GET_L4_BANK_DELETE_MODE = 0,      // retrieve value from vpd
        SET_L4_BANK_DELETE_MODE = 1,      // update value in vpd
    };
}

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*accessMBvpdL4BankDelete_FP_t)
    (const fapi::Target &,
     uint32_t &,
     const fapi::MBvpdL4BankDeleteMode);

extern "C"
{
/**
 * @brief MBvpd accessor for the ATTR_L4_BANK_DELETE_VPD attribute
 *
 * Access L4 Bank Delete value in MBvpd record VSPD keyword MX.
 *
 * @param[in] i_mbTarget  - Reference to mb Target
 * @param[in,out] io_val  - retrived MX value or value to use to update MX vpd
 * @param[in] i_mode      - set or get mode
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode accessMBvpdL4BankDelete(
    const fapi::Target & i_mbTarget,
    uint32_t & io_val,
    const fapi::MBvpdL4BankDeleteMode i_mode );
}

#endif
