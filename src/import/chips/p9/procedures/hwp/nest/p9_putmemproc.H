/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_putmemproc.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
///
/// @file p9_putmemproc.H
/// @brief Invoke ADU putmem chipop
///
/// *HWP HWP Owner: Joseph McGill jmcgill@us.ibm.com
/// *HWP FW Owner: Thi Tran thi@us.ibm.com
/// *HWP Team: Nest
/// *HWP Level: 3
/// *HWP Consumed by: HB
///

#ifndef _P9_PUTMEMPROC_H_
#define _P9_PUTMEMPROC_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

namespace fapi2
{

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------
enum sbeMemoryAccessFlags
{
    SBE_MEM_ACCESS_FLAGS_TARGET_PROC          = 0x00000001,
    SBE_MEM_ACCESS_FLAGS_TARGET_PBA           = 0x00000002,
    SBE_MEM_ACCESS_FLAGS_AUTO_INCR_ON         = 0x00000004,
    SBE_MEM_ACCESS_FLAGS_ECC_OVERRIDE         = 0x00000008,
    SBE_MEM_ACCESS_FLAGS_TAG                  = 0x00000010,
    SBE_MEM_ACCESS_FLAGS_FAST_MODE_ON         = 0x00000020,
    SBE_MEM_ACCESS_FLAGS_LCO_MODE             = 0x00000040,
    SBE_MEM_ACCESS_FLAGS_CACHE_INHIBITED_MODE = 0x00000080,
    SBE_MEM_ACCESS_FLAGS_HOST_PASS_THROUGH    = 0x00000100,
    SBE_MEM_ACCESS_FLAGS_CACHE_INJECT_MODE    = 0x00000200,
    SBE_MEM_ACCESS_FLAGS_PB_DIS_MODE          = 0x00000400,
    SBE_MEM_ACCESS_FLAGS_SWITCH_MODE          = 0x00000800,
    SBE_MEM_ACCESS_FLAGS_PB_INIT_MODE         = 0x00001000,
    SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_CD_MODE   = 0x00002000,
    SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_AB_MODE   = 0x00004000,
    SBE_MEM_ACCESS_FLAGS_POST_SWITCH_MODE     = 0x00008000,
};

} // End namespace

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode(*p9_putmemproc_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const uint64_t,
    const uint32_t,
    uint8_t*,
    const uint32_t);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
//

extern "C" {

///
/// @brief Invoke ADU putmem chipop
///
/// @param[in] i_target Reference to processor chip target
/// @param[in] i_address Base address for write operation
/// @param[in] i_bytes Size of write data, in B
/// @param[in] i_data Pointer to write data
/// @param[in] i_mem_flags Flags to pass to chipop
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode p9_putmemproc(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const uint32_t i_bytes,
        uint8_t* i_data,
        const uint32_t i_mem_flags);

} //extern "C"

#endif //_P9_PUTMEMPROC_H_
