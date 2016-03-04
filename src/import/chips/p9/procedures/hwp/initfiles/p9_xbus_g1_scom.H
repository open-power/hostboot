/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_xbus_g1_scom.H $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef _INIT_P9_XBUS_G1_SCOM_PROCEDURE_H_
#define _INIT_P9_XBUS_G1_SCOM_PROCEDURE_H_


#include <stddef.h>
#include <stdint.h>
#include <fapi2_target.H>
#include <fapi2.H>


typedef fapi2::ReturnCode (*p9_xbus_g1_scom_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_XBUS>&,
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>&);

extern "C"
{

    fapi2::ReturnCode p9_xbus_g1_scom(const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& TGT0,
                                      const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1);

}

#endif
