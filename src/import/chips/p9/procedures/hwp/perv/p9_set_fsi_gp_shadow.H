/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_set_fsi_gp_shadow.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//------------------------------------------------------------------------------
/// @file  p9_set_fsi_gp_shadow.H
///
/// @brief --IPL step 0.8 proc_prep_ipl
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Brian Silver <bsilver@us.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


#ifndef _P9_SET_FSI_GP_SHADOW_H_
#define _P9_SET_FSI_GP_SHADOW_H_


#include <fapi2.H>


namespace p9SetFsiGpShadow
{
enum P9_SET_FSI_GP_SHADOW_Public_Constants
{
    PERV_CTRL0_FLUSHVALUE = 0x7C0E2000,
    PERV_CTRL1_FLUSHVALUE = 0x63C00000,
    ROOT_CTRL0_FLUSHVALUE = 0x80FF4003,
    ROOT_CTRL1_FLUSHVALUE = 0x00180000,
    ROOT_CTRL2_FLUSHVALUE = 0x0000E000,
    ROOT_CTRL5_FLUSHVALUE = 0x00000000,
    ROOT_CTRL3_FLUSHVALUE = 0x0080C000,
    ROOT_CTRL4_FLUSHVALUE = 0x00000000,
    ROOT_CTRL5_MASK       = 0xFFFF0000,
    ROOT_CTRL6_FLUSHVALUE = 0x00800000,
    ROOT_CTRL6_MASK       = 0xF0000000,
    ROOT_CTRL7_FLUSHVALUE = 0x00000000,
    ROOT_CTRL8_FLUSHVALUE = 0xEEECF300,
    ROOT_CTRL8_MASK       = 0x0000008F
};
}

typedef fapi2::ReturnCode (*p9_set_fsi_gp_shadow_FP_t)(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

/// @brief --update ROOT CTRL shadows if needed
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p9_set_fsi_gp_shadow(const
                                           fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip);
}

#endif
