/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/zqcal.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file zqcal.H
/// @brief Subroutines to send ZQCL commands
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ZQCAL_H_
#define _MSS_ZQCAL_H_

#include <vector>
#include <fapi2.H>
#include <lib/ccs/ccs.H>

namespace mss
{

///
/// @brief Setup DRAM ZQCL
/// @tparam T the target type associated with this cal
/// @tparam TT the target type of the CCS instruction
/// @param[in] i_target the target associated with this cal
/// @param[in] i_rank the current rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T, fapi2::TargetType TT >
fapi2::ReturnCode setup_dram_zqcal( const fapi2::Target<T>& i_target,
                                    const uint64_t i_rank,
                                    std::vector< ccs::instruction_t<TT> >& io_inst);

///
/// @brief Setup LRDIMM data buffer ZQCL
/// @tparam T the target type associated with this cal
/// @tparam TT the target type of the CCS instruction
/// @param[in] i_target the target associated with this cal
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T, fapi2::TargetType TT >
fapi2::ReturnCode setup_data_buffer_zqcal( const fapi2::Target<T>& i_target,
        std::vector< ccs::instruction_t<TT> >& io_inst);

///
/// @brief Setup and execute DRAM ZQCL
/// @tparam T, the target type associated with this cal
/// @param[in] i_target the target associated with this cal
/// @param[in] i_cal_steps_enabled fapi2::buffer<uint16_t> representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode setup_and_execute_zqcal( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint32_t>& i_cal_steps_enabled);

}// mss

#endif
