/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_unmask_errors.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9c_mss_unmask_errors.H
/// @brief Utility functions to set action regs and unmask FIR bits at the end of various mss IPL procedures.
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: Memtools
//
//


#ifndef _MSS_UNMASK_ERRORS_H
#define _MSS_UNMASK_ERRORS_H

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi2.H>


//------------------------------------------------------------------------------
// mss_unmask_pervasive_errors
//------------------------------------------------------------------------------

///
/// @brief Sets action regs and mask settings for pervasive errors to their runtime settings.
/// @param[in] i_target Centaur target
/// @return FAPI2_RC_SUCCESS iff okay
////
fapi2::ReturnCode mss_unmask_pervasive_errors( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);



//------------------------------------------------------------------------------
// mss_unmask_inband_errors
//------------------------------------------------------------------------------


///
/// @brief  Sets action regs and mask settings for inband errors to their runtime settings.
/// @param[in]  i_target Centaur target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of cen_mem_startclocks.C
///
fapi2::ReturnCode mss_unmask_inband_errors( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);


//------------------------------------------------------------------------------
// mss_unmask_ddrphy_errors
//------------------------------------------------------------------------------


///
/// @brief Sets action regs and mask settings for ddr phy errors to runtime settings.
/// @param[in]  i_target MBA target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of proc_cen_framelock.C
///
fapi2::ReturnCode mss_unmask_ddrphy_errors( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);


//------------------------------------------------------------------------------
// mss_unmask_draminit_errors
//------------------------------------------------------------------------------


///
/// @brief Sets MBACALFIR action regs to their runtime settings.
///        Unmasks errors that are valid for PRD to handle after mss_draminit procedure.
/// @param[in]  i_target MBA target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of mss_draminit.C.
///
fapi2::ReturnCode mss_unmask_draminit_errors( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);


//------------------------------------------------------------------------------
// mss_unmask_draminit_training_errors
//------------------------------------------------------------------------------


///
/// @brief Unmasks MBACALFIR errors that are valid for PRD to handle after mss_draminit_training
/// @param[in]  i_target MBA target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of mss_draminit_training.C.
fapi2::ReturnCode mss_unmask_draminit_training_errors(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);


//------------------------------------------------------------------------------
// mss_unmask_draminit_training_advanced_errors
//------------------------------------------------------------------------------


///
/// @brief Unmasks MBACALFIR errors that are valid for PRD to handle after mss_draminit_training_advanced
/// @param[in]  i_target MBA target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of mss_draminit_training_advanced.C.
///
fapi2::ReturnCode mss_unmask_draminit_training_advanced_errors(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);


//------------------------------------------------------------------------------
// mss_unmask_maint_errors
//------------------------------------------------------------------------------


///
/// @brief Sets action regs and unmasks maint errors prior to the maint logic
///         Being used in memdiags so that PRD will be able to handle them
///         if they happen during memdiags.
/// @param[in]  i_target MBA target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of mss_draminit_mc.C.
///
fapi2::ReturnCode mss_unmask_maint_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);


//------------------------------------------------------------------------------
// mss_unmask_fetch_errors
//------------------------------------------------------------------------------


///
/// @brief Sets action regs and unmasks fetch errors prior to the start of mainline traffic.
/// @param[in] i_target Centaur target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of mss_draminit_mc.C.
///
fapi2::ReturnCode mss_unmask_fetch_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);


#endif //// _MSS_UNMASK_ERRORS_H ////
