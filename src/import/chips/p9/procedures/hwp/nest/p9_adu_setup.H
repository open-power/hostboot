/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_adu_setup.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
//------------------------------------------------------------------------------------
//
/// @file p9_adu_setup.H
/// @brief Setup the adu to do reads/writes
//
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by:
//-----------------------------------------------------------------------------------
// *! ADDITIONAL COMMENTS:
// *!
// *! The purpose of this procedure is to setup the ADU to do reads/writes
// *! and to return the number of granules (number of 8B reads/writes) that
// *! can be done before setup needs to be called again
// *!
// *! Successful operation assumes that:
// *!
// *! High-level procedure flow:
// *!
// *!
//------------------------------------------------------------------------------------

#ifndef _P9_ADU_SETUP_H_
#define _P9_ADU_SETUP_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_adu_constants.H>

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9_adu_setup_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
                      const uint64_t,
                      const bool,
                      const uint32_t,
                      uint32_t&);

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

extern "C" {

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

/// @brief setup for reads/writes from the ADU
/// @param[in] i_target       => P9 chip target
/// @param[in] i_address      => base real address for read/write operation (expected to be 8B aligned)
/// @param[in] i_rnw          => if the operation is read not write (1 for read, 0 for write)
/// @param[in] i_flags        => other information that is needed - the flags are:
///                               -bit 0-cache inhibited - use cache-inhibited ttype?
///                                     (true = ci, false = dma partial)
///                               -bit 1-autoinc - utilize ADU HW auto-increment function
///                               -bit 2-lock pick - pick ADU lock (if required)
///                               -bit 3-leave dirty - in the case of a fail with lock held,
///                                      do not reset ADU & do not release lock
///                               -bit 4-fastmode - check status only at the end of read/write stream
///                               -bit 5-itag - collect itag with each 8B read/write
///                               -bit 6:13-size - transaction size
///                               -bit 14:32-lock tries - number of ADU lock acquisitions to attempt
///                                      before giving up or attempting lock pick
/// @param[out] o_numGranules  => number of 8B granules that can be read/written before setup needs to be called again
//
/// @return FAPI_RC_SUCCESS if the setup completes successfully,
//
    fapi2::ReturnCode p9_adu_setup(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const bool i_rnw,
        const uint32_t i_flags,
        uint32_t& o_numGranules);
} //extern "C"

#endif //_P9_ADU_SETUP_H_
