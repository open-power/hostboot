/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/initfiles/p9_mc_scan.H $              */
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
#ifndef _INIT_P9_MC_SCAN_PROCEDURE_H_
#define _INIT_P9_MC_SCAN_PROCEDURE_H_


#include <stddef.h>
#include <stdint.h>
#include <fapi2.H>

#ifdef IFCOMPILER_PLAT
#define INITFILE_PROCEDURE \
    p9_mc_scan(TGT0);
#endif

typedef fapi2::ReturnCode (*p9_mc_scan_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>&);

extern "C"
{

    fapi2::ReturnCode p9_mc_scan(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& TGT0);

}

#endif
