/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_htm_setup.H $      */
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
/// ----------------------------------------------------------------------------
/// @file  p9_htm_setup.H
///
/// @brief Perform p9_htm_setup on a processor chip
///
/// The purpose of this procedure is to setup HTM on a processor
/// chip.
///
/// Some start/setup attributes are used as part of the setup process.
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 2
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

#ifndef _P9_HTM_SETUP_H_
#define _P9_HTM_SETUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_htm_setup_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const bool i_start);

//----------------------------------------------------------------------------
// Constant definitions
//----------------------------------------------------------------------------
// Size selected via HTM_MEM.MEM_SIZE_SMALL (bit 13)
enum htm_size_t
{
    HTM_512M_OR_16M = 0x0,
    HTM_1G_OR_32M   = 0x1,
    HTM_2G_OR_64M   = 0x3,
    HTM_4G_OR_128M  = 0x7,
    HTM_8G_OR_256M  = 0xF,
    HTM_16G_OR_512M = 0x1F,
    HTM_32G_OR_1G   = 0x3F,
    HTM_64G_OR_2G   = 0x7F,
    HTM_128G_OR_4G  = 0xFF,
    HTM_256G_OR_8G  = 0x1FF
};

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{

///
/// @brief p9_htm_setup procedure
///
/// The purpose of this procedure is to setup HTM on a processor
/// chip.
///
/// @param[in]    i_target   Reference to TARGET_TYPE_PROC_CHIP target.
/// @param[in]    i_start    Start HTM after setup.
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_htm_setup(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_start = true);

} // extern "C"

#endif  // _P9_HTM_SETUP_H_
