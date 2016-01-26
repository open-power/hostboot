/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/customize/p9_xip_customize.H $        */
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
#ifndef _P9_XIP_CUSTOMIZE_
#define _P9_XIP_CUSTOMIZE_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_xip_customize_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_system_target,
    void* io_image);

extern "C"
{
    fapi2::ReturnCode p9_xip_customize (
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_system_target,
        void* io_image);

}
#endif
